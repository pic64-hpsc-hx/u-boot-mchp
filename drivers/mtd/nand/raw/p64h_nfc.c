/*
 * SPDX-License-Identifier: GPL-2.0+
 * Copyright (C) 2025 Microchip Technology Ltd.
 *
 * P64H_NFC NAND controller U-Boot driver
 * Based on Cadence HPNFC driver (bare metal and Linux)
 *
 * Not Supported:
 *  - thread management
 *  - PIO Mode
 *  - interrupts support
 *  - DDR mode
 * 
 *  TODO: 
 * - implement support for 16 bit NAND devices
 * - implement or remove all functions "not implemented" in the driver
 */

#include <common.h>
#include <nand.h>
#include <dm.h>
#include <clk.h>
#include <malloc.h>
#include <asm/io.h>

#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/mtd/rawnand.h>
#include <linux/dma-mapping.h>
#include <linux/sizes.h>
#include <linux/io.h>

#include <dm/device_compat.h>

#include "p64h_nfc.h"

#define CADENCE_NAND_CALC_ECC_BYTES(max_step_size)                         \
    static int p64h_nfc_nand_calc_ecc_bytes_##max_step_size(int step_size, \
                                                            int strength)  \
    {                                                                      \
        return p64h_nfc_nand_calc_ecc_bytes(max_step_size, strength);      \
    }

/* command DMA descriptor. */
struct __attribute__((packed)) p64h_nfc_cdma_desc {
    /* next descriptor address. */
    u64 next_pointer;
    /* flash address is a 32-bit address comprising of BANK and ROW ADDR. */
    u32 flash_pointer;
    /* field appears in HPNFC version 13*/
    u16 bank;
    /* reserved field */
    u16 rsvd0;
    /* operation the controller needs to perform. */
    u16 command_type;
    /* reserved field */
    u16 rsvd1;
    /* flags for operation of this command. */
    u16 command_flags;
    /* reserved field */
    u16 rsvd2;
    /* system/host memory address required for data DMA commands. */
    u64 memory_pointer;
    /* status of operation. */
    u32 status;
    /* reserved field */
    u32 rsvd3;
    /* address pointer to sync buffer location. */
    u64 sync_flag_pointer;
    /* controls the buffer sync mechanism. */
    u32 sync_arguments;
    /* reserved field */
    u32 rsvd4;
    /* control data pointer. */
    u64 ctrl_data_ptr;
};

struct p64h_nfc_nand_timings {
    u32 async_toggle_timings;
    u32 timings0;
    u32 timings1;
    u32 timings2;
    u32 dll_phy_ctrl;
    u32 phy_ctrl;
    u32 phy_dqs_timing;
    u32 phy_gate_lpbk_ctrl;
};

struct p64h_nfc_caps {
    /* maximum number of banks supported by hardware. */
    u8 max_banks;
    /* slave and Master DMA data width in bytes (4 or 8). */
    u8 data_dma_width;
    /* control Data feature supported. */
    bool data_control_supp;
    /* is PHY type DLL. */
    bool is_phy_type_dll;
    /* skew value of the output signals of the NAND Flash interface. */
    u32 if_skew;
};

struct p64h_nfc_nand_chip {
    struct list_head node;
    struct nand_chip chip;
    struct p64h_nfc_nand_timings timings;
    int selected;
    u32 cur_cmd;
    u32 avail_oob_size;
    u32 sector_size;
    u32 sector_count;
    u8 corr_str_idx;
    u8 bbm_len;
    u8 bbm_offs;
    u8 nthread;
    u8 thread[];
};

struct p64h_nfc_ctrl {
    void __iomem *regs;
    void __iomem *sdma;
    struct udevice *dev;
    struct p64h_nfc_cdma_desc *cdma_desc;
    unsigned long dma_cdma_desc;
    struct list_head chips;
    struct p64h_nfc_caps caps;
    struct nand_ecc_caps ecc_caps;
    struct nand_ecc_step_info ecc_stepinfos[BCH_MAX_NUM_SECTOR_SIZES];
    int curr_trans_type;
    u8 bch_metadata_size;
    u8 curr_corr_str_idx;
    u8 assigned_cs;
    u8 *buffer;
    u32 buffer_size;
    u32 version;
    u32 nf_clk_rate;
    u32 board_delay;

    int ecc_strengths[BCH_MAX_NUM_CORR_CAPS];
};

static u64 p64h_nfc_pack_addr(u64 address, u8 no_of_bytes)
{
    /* mask no_of_bytes to 3 bits */
    no_of_bytes &= 0x7;

    /* pack address bytes into [63:16] */
    u64 result = (address & 0xFFFFFFFFFFFFULL) << 16;

    /* pack No_of_BYTES into [13:11] */
    result |= ((u64)no_of_bytes) << 11;

    return result;
}

static struct p64h_nfc_nand_chip *to_nfc_nand(struct nand_chip *chip)
{
    return container_of(chip, struct p64h_nfc_nand_chip, chip);
}

static u32 p64h_nfc_read(void *base, u32 reg)
{
    u32 val;
    volatile void __iomem *addr = base + reg;
    val = readl(addr);
    return val;
}

static void p64h_nfc_write(void *base, u32 reg, u32 val)
{
    volatile void __iomem *addr = base + reg;
    writel(val, addr);
}

static bool p64h_nfc_nand_dma_buf_ok(struct p64h_nfc_ctrl *ctrl,
                                     const void *buf,
                                     u32 buf_len)
{
    u8 data_dma_width = ctrl->caps.data_dma_width;

    return buf && likely(IS_ALIGNED((uintptr_t)buf, data_dma_width)) &&
           likely(IS_ALIGNED(buf_len, DMA_DATA_SIZE_ALIGN));
}

static u32 p64h_nfc_timeout_wait(struct p64h_nfc_ctrl *ctrl,
                                 u32 reg,
                                 u32 mask,
                                 u32 value,
                                 u32 match,
                                 u32 timeout)
{
    u32 val;

    if (!timeout)
        return 0;

    do {
        udelay(1);
        val = p64h_nfc_read(ctrl->regs, reg) & mask;
        timeout--;
    } while (((val != value && match) || (val == value && !match)) && timeout);

    if (((val == value) && match) || ((val != value) && !match)) {
        /* value matches */
        return 0;
    }
    return -ETIMEDOUT;
}

static int p64h_nfc_nand_calc_ecc_bytes(int max_step_size, int strength)
{
    int nbytes_addr = DIV_ROUND_UP(fls(8 * max_step_size) * strength, 8);

    return ALIGN(nbytes_addr, 2);
}

CADENCE_NAND_CALC_ECC_BYTES(256)
CADENCE_NAND_CALC_ECC_BYTES(512)
CADENCE_NAND_CALC_ECC_BYTES(1024)
CADENCE_NAND_CALC_ECC_BYTES(2048)
CADENCE_NAND_CALC_ECC_BYTES(4096)

static int p64h_nfc_nand_read_bch_caps(struct p64h_nfc_ctrl *ctrl)
{
    struct nand_ecc_caps *ecc_caps = &ctrl->ecc_caps;
    int max_step_size = 0, nstrengths, i;
    u32 reg;

    reg = p64h_nfc_read(ctrl->regs, BCH_CFG_3);
    ctrl->bch_metadata_size = FIELD_GET(BCH_CFG_3_METADATA_SIZE, reg);
    if (ctrl->bch_metadata_size < 4) {
        dev_err(ctrl->dev, "Driver needs at least 4 bytes of BCH meta data\n");
        return -EIO;
    }

    reg = p64h_nfc_read(ctrl->regs, BCH_CFG_0);
    ctrl->ecc_strengths[0] = FIELD_GET(BCH_CFG_0_CORR_CAP_0, reg);
    ctrl->ecc_strengths[1] = FIELD_GET(BCH_CFG_0_CORR_CAP_1, reg);
    ctrl->ecc_strengths[2] = FIELD_GET(BCH_CFG_0_CORR_CAP_2, reg);
    ctrl->ecc_strengths[3] = FIELD_GET(BCH_CFG_0_CORR_CAP_3, reg);

    reg = p64h_nfc_read(ctrl->regs, BCH_CFG_1);
    ctrl->ecc_strengths[4] = FIELD_GET(BCH_CFG_1_CORR_CAP_4, reg);
    ctrl->ecc_strengths[5] = FIELD_GET(BCH_CFG_1_CORR_CAP_5, reg);
    ctrl->ecc_strengths[6] = FIELD_GET(BCH_CFG_1_CORR_CAP_6, reg);
    ctrl->ecc_strengths[7] = FIELD_GET(BCH_CFG_1_CORR_CAP_7, reg);

    reg = p64h_nfc_read(ctrl->regs, BCH_CFG_2);
    ctrl->ecc_stepinfos[0].stepsize = FIELD_GET(BCH_CFG_2_SECT_0, reg);
    ctrl->ecc_stepinfos[1].stepsize = FIELD_GET(BCH_CFG_2_SECT_1, reg);

    nstrengths = 0;
    for (i = 0; i < BCH_MAX_NUM_CORR_CAPS; i++) {
        if (ctrl->ecc_strengths[i] != 0)
            nstrengths++;
    }

    ecc_caps->nstepinfos = 0;
    for (i = 0; i < BCH_MAX_NUM_SECTOR_SIZES; i++) {
        /* ECC strengths are common for all step infos. */
        ctrl->ecc_stepinfos[i].nstrengths = nstrengths;
        ctrl->ecc_stepinfos[i].strengths = ctrl->ecc_strengths;

        if (ctrl->ecc_stepinfos[i].stepsize != 0)
            ecc_caps->nstepinfos++;

        if (ctrl->ecc_stepinfos[i].stepsize > max_step_size)
            max_step_size = ctrl->ecc_stepinfos[i].stepsize;
    }
    ecc_caps->stepinfos = &ctrl->ecc_stepinfos[0];

    switch (max_step_size) {
        case 256:
            ecc_caps->calc_ecc_bytes = &p64h_nfc_nand_calc_ecc_bytes_256;
            break;
        case 512:
            ecc_caps->calc_ecc_bytes = &p64h_nfc_nand_calc_ecc_bytes_512;
            break;
        case 1024:
            ecc_caps->calc_ecc_bytes = &p64h_nfc_nand_calc_ecc_bytes_1024;
            break;
        case 2048:
            ecc_caps->calc_ecc_bytes = &p64h_nfc_nand_calc_ecc_bytes_2048;
            break;
        case 4096:
            ecc_caps->calc_ecc_bytes = &p64h_nfc_nand_calc_ecc_bytes_4096;
            break;
        default:
            dev_err(ctrl->dev,
                    "Unsupported sector size(ecc step size) %d\n",
                    max_step_size);
            return -EIO;
    }

    return 0;
}

static void p64h_nfc_nand_get_caps(struct p64h_nfc_ctrl *ctrl)
{
    u32 val;

    val = p64h_nfc_read(ctrl->regs, CTRL_FEATURES);
    ctrl->caps.max_banks = 1 << FIELD_GET(CTRL_FEATURES_N_BANKS, val);

    if (FIELD_GET(CTRL_FEATURES_DMA_DWITH64, val))
        ctrl->caps.data_dma_width = 8;
    else
        ctrl->caps.data_dma_width = 4;

    if (val & CTRL_FEATURES_CONTROL_DATA)
        ctrl->caps.data_control_supp = true;

    if (val & (CTRL_FEATURES_NVDDR_2_3 | CTRL_FEATURES_NVDDR))
        ctrl->caps.is_phy_type_dll = true;
}

static int p64h_nfc_nand_set_access_width16(struct p64h_nfc_ctrl *ctrl,
                                            bool bit_bus16)
{
    u32 reg_val, ret;

    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_CTRL_BUSY,
                                CTRL_STATUS_CTRL_BUSY,
                                0,
                                TIMEOUT_100MS);
    if (ret)
        return ret;

    reg_val = p64h_nfc_read(ctrl->regs, COMMON_SET);

    if (!bit_bus16)
        reg_val &= ~COMMON_SET_DEVICE_16BIT;
    else
        reg_val |= COMMON_SET_DEVICE_16BIT;

    p64h_nfc_write(ctrl->regs, COMMON_SET, reg_val);

    return 0;
}

static int p64h_nfc_generic_cmd_send(struct p64h_nfc_ctrl *ctrl,
                                     u8 chip_nr,
                                     u64 mini_ctrl_cmd)
{
    int ret;
    u32 mini_ctrl_cmd_l, mini_ctrl_cmd_h, val;

    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAY_CS, chip_nr);
    mini_ctrl_cmd_l = mini_ctrl_cmd & 0xFFFFFFFF;
    mini_ctrl_cmd_h = mini_ctrl_cmd >> 32;

    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_CTRL_BUSY,
                                CTRL_STATUS_CTRL_BUSY,
                                0,
                                TIMEOUT_100MS);

    if (ret)
        return ret;

    /* set mini controller command */
    p64h_nfc_write(ctrl->regs, CMD_REG2, mini_ctrl_cmd_l);
    p64h_nfc_write(ctrl->regs, CMD_REG3, mini_ctrl_cmd_h);

    /* select generic command */
    val = FIELD_PREP(CMD_REG0_CT, CMD_REG0_CT_GEN);
    /* thread number */
    val |= FIELD_PREP(CMD_REG0_TN, 0);

    /* issue command */
    p64h_nfc_write(ctrl->regs, CMD_REG0, val);

    return 0;
}

static void p64h_nfc_nand_set_timings(struct p64h_nfc_ctrl *ctrl,
                                      struct p64h_nfc_nand_timings *t)
{
    p64h_nfc_write(ctrl->regs, ASYNC_TOGGLE_TIMINGS, t->async_toggle_timings);
    p64h_nfc_write(ctrl->regs, TIMINGS0, t->timings0);
    p64h_nfc_write(ctrl->regs, TIMINGS1, t->timings1);
    p64h_nfc_write(ctrl->regs, TIMINGS2, t->timings2);

    if (ctrl->caps.is_phy_type_dll)
        p64h_nfc_write(ctrl->regs, DLL_PHY_CTRL, t->dll_phy_ctrl);

    p64h_nfc_write(ctrl->regs, PHY_CTRL, t->phy_ctrl);

    if (ctrl->caps.is_phy_type_dll) {
        p64h_nfc_write(ctrl->regs, PHY_TSEL, 0);
        p64h_nfc_write(ctrl->regs, PHY_DQ_TIMING, 2);
        p64h_nfc_write(ctrl->regs, PHY_DQS_TIMING, t->phy_dqs_timing);
        p64h_nfc_write(ctrl->regs, PHY_GATE_LPBK_CTRL, t->phy_gate_lpbk_ctrl);
        p64h_nfc_write(
            ctrl->regs, PHY_DLL_MASTER_CTRL, PHY_DLL_MASTER_CTRL_BYPASS_MODE);
        p64h_nfc_write(ctrl->regs, PHY_DLL_SLAVE_CTRL, 0);
    }
}

static void p64h_nfc_nand_set_ecc_strength(struct p64h_nfc_ctrl *ctrl,
                                           u8 corr_str_idx)
{
    u32 reg;

    if (ctrl->curr_corr_str_idx == corr_str_idx)
        return;

    reg = p64h_nfc_read(ctrl->regs, ECC_CONFIG_0);
    reg &= ~ECC_CONFIG_0_CORR_STR;
    reg |= FIELD_PREP(ECC_CONFIG_0_CORR_STR, corr_str_idx);
    p64h_nfc_write(ctrl->regs, ECC_CONFIG_0, reg);
    ctrl->curr_corr_str_idx = corr_str_idx;
}

static int p64h_nfc_nand_get_ecc_strength(struct p64h_nfc_ctrl *ctrl,
                                          u8 strength)
{
    int i, corr_str_idx = -1;

    for (i = 0; i < BCH_MAX_NUM_CORR_CAPS; i++) {
        if (ctrl->ecc_strengths[i] == strength) {
            corr_str_idx = i;
            break;
        }
    }

    return corr_str_idx;
}

static void p64h_nfc_nand_set_erase_detection(struct p64h_nfc_ctrl *ctrl,
                                              bool enable,
                                              u8 bitflips_threshold)
{
    u32 reg;

    reg = p64h_nfc_read(ctrl->regs, ECC_CONFIG_0);

    if (enable)
        reg |= ECC_CONFIG_0_ERASE_DET_EN;
    else
        reg &= ~ECC_CONFIG_0_ERASE_DET_EN;

    p64h_nfc_write(ctrl->regs, ECC_CONFIG_0, reg);
    p64h_nfc_write(ctrl->regs, ECC_CONFIG_1, bitflips_threshold);
}

static int p64h_nfc_nand_set_skip_bytes_conf(struct p64h_nfc_ctrl *ctrl,
                                             u8 num_of_bytes,
                                             u32 offset_value,
                                             int enable)
{
    int ret;
    u32 reg, skip_bytes_offset;

    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_CTRL_BUSY,
                                CTRL_STATUS_CTRL_BUSY,
                                0,
                                TIMEOUT_100MS);
    if (ret)
        return ret;

    if (!enable) {
        num_of_bytes = 0;
        offset_value = 0;
    }

    reg = p64h_nfc_read(ctrl->regs, SKIP_BYTES_CONF);
    reg &= ~SKIP_BYTES_NUM_OF_BYTES;
    reg |= FIELD_PREP(SKIP_BYTES_NUM_OF_BYTES, num_of_bytes);
    skip_bytes_offset = FIELD_PREP(SKIP_BYTES_OFFSET_VALUE, offset_value);

    p64h_nfc_write(ctrl->regs, SKIP_BYTES_CONF, reg);
    p64h_nfc_write(ctrl->regs, SKIP_BYTES_OFFSET, skip_bytes_offset);

    return 0;
}

static int p64h_nand_set_skip_marker_val(struct p64h_nfc_ctrl *ctrl,
                                         u16 marker_value)
{
    u32 reg;

    int ret = p64h_nfc_timeout_wait(ctrl,
                                    CTRL_STATUS,
                                    CTRL_STATUS_CTRL_BUSY,
                                    CTRL_STATUS_CTRL_BUSY,
                                    0,
                                    TIMEOUT_100MS);
    if (ret)
        return ret;

    reg = p64h_nfc_read(ctrl->regs, SKIP_BYTES_CONF);
    reg &= ~SKIP_BYTES_MARKER_VALUE;
    reg |= FIELD_PREP(SKIP_BYTES_MARKER_VALUE, marker_value);

    p64h_nfc_write(ctrl->regs, SKIP_BYTES_CONF, reg);

    return 0;
}

static void p64h_nfc_nand_prepare_data_size(struct nand_chip *chip,
                                            int transfer_type)
{
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);
    struct mtd_info *mtd = nand_to_mtd(chip);
    u32 sec_size = 0, offset = 0, sec_cnt = 1;
    u32 last_sec_size = nand->sector_size;
    u32 data_ctrl_size = 0;
    u32 reg = 0;

    if (ctrl->curr_trans_type == transfer_type)
        return;

    switch (transfer_type) {
        case TT_MAIN_OOB_AREA_EXT:
            sec_cnt = nand->sector_count;
            sec_size = nand->sector_size;
            data_ctrl_size = nand->avail_oob_size;
            break;
        case TT_MAIN_OOB_AREAS:
            sec_cnt = nand->sector_count;
            last_sec_size = nand->sector_size + nand->avail_oob_size;
            sec_size = nand->sector_size;
            break;
        case TT_RAW_PAGE:
            last_sec_size = mtd->writesize + mtd->oobsize;
            break;
        case TT_BBM:
            offset = mtd->writesize + nand->bbm_offs;
            last_sec_size = 8;
            break;
    }

    reg = FIELD_PREP(TRAN_CFG_0_OFFSET, offset);
    reg |= FIELD_PREP(TRAN_CFG_0_SEC_CNT, sec_cnt);
    p64h_nfc_write(ctrl->regs, TRAN_CFG_0, reg);

    reg = FIELD_PREP(TRAN_CFG_1_LAST_SEC_SIZE, last_sec_size);
    reg |= FIELD_PREP(TRAN_CFG_1_SECTOR_SIZE, sec_size);
    p64h_nfc_write(ctrl->regs, TRAN_CFG_1, reg);

    if (ctrl->caps.data_control_supp) {
        reg = p64h_nfc_read(ctrl->regs, CONTROL_DATA_CTRL);
        reg &= ~CONTROL_DATA_CTRL_SIZE;
        reg |= FIELD_PREP(CONTROL_DATA_CTRL_SIZE, data_ctrl_size);
        p64h_nfc_write(ctrl->regs, CONTROL_DATA_CTRL, reg);
    }

    ctrl->curr_trans_type = transfer_type;
}

static int p64h_nfc_nand_set_ecc_enable(struct p64h_nfc_ctrl *ctrl, bool enable)
{
    int ret;
    u32 reg;

    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_CTRL_BUSY,
                                CTRL_STATUS_CTRL_BUSY,
                                0,
                                TIMEOUT_100MS);

    reg = p64h_nfc_read(ctrl->regs, ECC_CONFIG_0);

    if (enable)
        reg |= ECC_CONFIG_0_ECC_EN;
    else
        reg &= ~ECC_CONFIG_0_ECC_EN;

    p64h_nfc_write(ctrl->regs, ECC_CONFIG_0, reg);

    return 0;
}

static void p64h_nfc_nand_cdma_desc_prepare(struct p64h_nfc_ctrl *ctrl,
                                            u8 bank_num,
                                            u32 flash_ptr,
                                            dma_addr_t mem_ptr,
                                            dma_addr_t ctrl_data_ptr,
                                            u16 ctype)
{
    struct p64h_nfc_cdma_desc *cdma_desc = ctrl->cdma_desc;

    memset(cdma_desc, 0, sizeof(struct p64h_nfc_cdma_desc));

    /* set fields for one descriptor. */
    cdma_desc->flash_pointer = flash_ptr;
    cdma_desc->bank = bank_num;
    cdma_desc->command_flags |= CDMA_CF_DMA_MASTER;

    cdma_desc->memory_pointer = mem_ptr;
    cdma_desc->status = 0;
    cdma_desc->sync_flag_pointer = 0;
    cdma_desc->sync_arguments = 0;

    cdma_desc->command_type = ctype;
    cdma_desc->ctrl_data_ptr = ctrl_data_ptr;
}

static int p64h_nfc_nand_cdma_send(struct p64h_nfc_ctrl *ctrl, u8 thread)
{
    u32 reg;
    int ret;

    ret = p64h_nfc_timeout_wait(
        ctrl, TRD_STATUS, BIT(thread), BIT(thread), 0, TIMEOUT_100MS);
    if (ret)
        return ret;

    p64h_nfc_write(ctrl->regs, CMD_REG2, (u32)ctrl->dma_cdma_desc);
    p64h_nfc_write(ctrl->regs, CMD_REG3, (u32)(ctrl->dma_cdma_desc >> 32));

    /* select CDMA mode. */
    reg = FIELD_PREP(CMD_REG0_CT, CMD_REG0_CT_CDMA);
    /* thread number */
    reg |= FIELD_PREP(CMD_REG0_TN, thread);
    /* issue command */
    p64h_nfc_write(ctrl->regs, CMD_REG0, reg);

    return 0;
}

static u8 p64h_nfc_nand_check_desc_error(struct p64h_nfc_ctrl *ctrl,
                                         u32 desc_status)
{
    if (desc_status & CDMA_CS_ERP)
        return STAT_ERASED;

    if (desc_status & CDMA_CS_UNCE)
        return STAT_ECC_UNCORR;

    if (desc_status & CDMA_CS_ERR) {
        dev_err(ctrl->dev, "CDMA desc error flag detected.\n");
        return STAT_FAIL;
    }

    if (FIELD_GET(CDMA_CS_MAXERR, desc_status))
        return STAT_ECC_CORR;

    return STAT_FAIL;
}

static u32 p64h_nfc_nand_cdma_send_and_wait(struct p64h_nfc_ctrl *ctrl,
                                            u8 thread)
{
    u32 val, timeout = TIMEOUT_100MS;

    int ret = p64h_nfc_nand_cdma_send(ctrl, thread);
    if (ret)
        return ret;

    /* wait for operation completed, poll on descriptor status */
    do {
        udelay(1);
        val = ctrl->cdma_desc->status & CDMA_CS_COMP;
        timeout--;
    } while ((val != CDMA_CS_COMP) && timeout);

    if (timeout == 0)
        return -ETIMEDOUT;

    /* check for success or error */
    if (ctrl->cdma_desc->status & CDMA_CS_FAIL) {
        ret = p64h_nfc_nand_check_desc_error(ctrl, ctrl->cdma_desc->status);
    } else {
        /* descriptor finished with no errors. */
        if (ctrl->cdma_desc->command_flags & CDMA_CF_CONT) {
            ret = STAT_UNKNOWN;
        } else {
            /* last descriptor.  */
            ret = STAT_OK;
        }
    }
    return ret;
}

static int p64h_nfc_nand_cdma_transfer(struct p64h_nfc_ctrl *ctrl,
                                       u8 chip_nr,
                                       int page,
                                       void *buf,
                                       void *ctrl_dat,
                                       u32 buf_size,
                                       u32 ctrl_dat_size,
                                       enum dma_data_direction dir,
                                       bool with_ecc)
{
    int ret;
    u8 thread_nr = chip_nr;
    u16 ctype;
    dma_addr_t dma_buf, dma_ctrl_dat = 0;

    if (dir == DMA_FROM_DEVICE)
        ctype = CDMA_CT_RD;
    else
        ctype = CDMA_CT_WR;

    p64h_nfc_nand_set_ecc_enable(ctrl, with_ecc);

    dma_buf = dma_map_single(buf, buf_size, dir);
    if (dma_mapping_error(ctrl->dev, dma_buf)) {
        return -EIO;
    }

    if (ctrl_dat && ctrl_dat_size) {
        dma_ctrl_dat = dma_map_single(ctrl_dat, ctrl_dat_size, dir);
        if (dma_mapping_error(ctrl->dev, dma_ctrl_dat)) {
            dma_unmap_single(dma_buf, buf_size, dir);
            return -EIO;
        }
    }

    p64h_nfc_nand_cdma_desc_prepare(
        ctrl, chip_nr, page, dma_buf, dma_ctrl_dat, ctype);

    ret = p64h_nfc_nand_cdma_send_and_wait(ctrl, thread_nr);

    dma_unmap_single(dma_buf, buf_size, dir);

    if (ctrl_dat && ctrl_dat_size)
        dma_unmap_single(dma_ctrl_dat, ctrl_dat_size, dir);

    return ret;
}

static int p64h_nfc_nand_read_bbm(struct nand_chip *chip, int page, u8 *buf)
{
    int ret;
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct mtd_info *mtd = nand_to_mtd(chip);

    if (nand->selected < 0) {
        return -EINVAL;
    }

    p64h_nfc_nand_prepare_data_size(chip, TT_BBM);

    p64h_nfc_nand_set_skip_bytes_conf(ctrl, 0, 0, 0);

    /*
     * read only bad block marker from offset
     * defined by a memory manufacturer.
     */
    ret = p64h_nfc_nand_cdma_transfer(ctrl,
                                      nand->thread[nand->selected],
                                      page,
                                      ctrl->buffer,
                                      NULL,
                                      mtd->oobsize,
                                      0,
                                      DMA_FROM_DEVICE,
                                      false);
    if (ret) {
        dev_err(ctrl->dev, "read BBM failed\n");
        return -EIO;
    }

    memcpy(buf + nand->bbm_offs, ctrl->buffer, nand->bbm_len);

    return 0;
}

static int p64h_nfc_hw_init(struct p64h_nfc_ctrl *ctrl)
{
    int ret;
    u32 val;

    /* wait until the controller initialization is complete */
    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_INIT_COMP,
                                CTRL_STATUS_INIT_COMP,
                                1,
                                TIMEOUT_100MS);
    if (ret)
        return ret;

    /* get controller version */
    val = p64h_nfc_read(ctrl->regs, CTRL_VERSION);
    ctrl->version = FIELD_GET(CTRL_VERSION_REV, val);

    /* disable cache and multiplane */
    p64h_nfc_write(ctrl->regs, CACHE_CFG, 0);
    p64h_nfc_write(ctrl->regs, MULTIPLANE_CFG, 0);

    /* disable and clear all interrupts */
    p64h_nfc_write(ctrl->regs, INTR_ENABLE, 0);
    p64h_nfc_write(ctrl->regs, INTR_STATUS, -1);

    p64h_nfc_nand_get_caps(ctrl);
    if (p64h_nfc_nand_read_bch_caps(ctrl))
        return -EIO;

    return p64h_nfc_nand_set_access_width16(ctrl, false);
}

static void p64h_nfc_nand_addr_process(struct nand_chip *chip, uint32_t addr)
{
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    if (nand->selected < 0) {
        /* don't process if chip is not selected */
        return;
    }

    bool write = false;
    u64 mini_ctrl_cmd = 0;
    u32 data_size = 0;
    u32 nbytes_addr;

    switch (nand->cur_cmd) {
        case NAND_CMD_READID:
            nbytes_addr = 1;
            if (addr == 0x20)
                data_size = 4;
            else
                data_size = 8;
            break;

        case NAND_CMD_PARAM:
            nbytes_addr = 1;
            data_size = 256;
            break;

        case NAND_CMD_SET_FEATURES:
            nbytes_addr = 1;
            data_size = 4;
            write = true;
            break;

        case NAND_CMD_STATUS:
            nbytes_addr = 1;
            data_size = 1;
            break;

        case NAND_CMD_ERASE1:
            nbytes_addr = 3;
            break;
    }

    /* set instruction type to 1 (ADDR Sequence) */
    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAY_INSTR, GCMD_LAY_INSTR_ADDR);
    mini_ctrl_cmd |= p64h_nfc_pack_addr(addr, nbytes_addr);

    /* send address command */
    if (p64h_nfc_generic_cmd_send(
            ctrl, nand->thread[nand->selected], mini_ctrl_cmd)) {
        dev_err(ctrl->dev,
                "send generic address (0x%x) failed on chip %u\n",
                addr,
                nand->selected);
    }

    if (nand->cur_cmd == NAND_CMD_ERASE1) {
        /* no data phase for erase command, return here. */
        return;
    }

    /* send data command */
    mini_ctrl_cmd = 0;
    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAY_INSTR, GCMD_LAY_INSTR_DATA);

    if (write)
        mini_ctrl_cmd |= FIELD_PREP(GCMD_DIR, GCMD_DIR_WRITE);

    mini_ctrl_cmd |= FIELD_PREP(GCMD_SECT_CNT, 1);
    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAST_SIZE, data_size);

    if (p64h_nfc_generic_cmd_send(
            ctrl, nand->thread[nand->selected], mini_ctrl_cmd)) {
        dev_err(
            ctrl->dev, "send generic data failed on chip %u\n", nand->selected);
    }
}

static void p64h_nfc_nand_cmd_process(struct nand_chip *chip, uint32_t cmd)
{
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);
    u64 mini_ctrl_cmd = 0;

    if (nand->selected < 0) {
        /* don't process if chip is not selected */
        return;
    }
    nand->cur_cmd = cmd;

    /* reset controller status even if U-Boot doesn't use interrupt */
    p64h_nfc_write(ctrl->regs, INTR_STATUS, -1);

    /* set instruction type to 0 (CMD Sequence) */
    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAY_INSTR, GCMD_LAY_INSTR_CMD);
    /* set command to execute */
    mini_ctrl_cmd |= FIELD_PREP(GCMD_LAY_INPUT_CMD, cmd);

    if (p64h_nfc_generic_cmd_send(
            ctrl, nand->thread[nand->selected], mini_ctrl_cmd)) {
        dev_err(ctrl->dev,
                "send generic cmd 0x%x failed on chip %u\n",
                cmd,
                nand->selected);
    }

    if (cmd == NAND_CMD_STATUS) {
        /* special case, no address, data command generated after.
           U-Boot will get immediately data. Status is one byte */
        p64h_nfc_nand_addr_process(chip, 0);
    }
}

static void p64h_nfc_cmd_ctrl(struct mtd_info *mtd, int dat, unsigned int ctrl)
{
    struct nand_chip *chip = mtd_to_nand(mtd);

    switch (ctrl) {

        case NAND_CTRL_CLE | NAND_CTRL_CHANGE:
            p64h_nfc_nand_cmd_process(chip, dat);
            break;

        case NAND_CTRL_ALE | NAND_CTRL_CHANGE:
            p64h_nfc_nand_addr_process(chip, dat);
            break;

        case NAND_NCE | NAND_CTRL_CHANGE:
        case NAND_ALE | NAND_NCE:
            /* do nothing */
            break;

        default:
            BUG();
    }
}

static u16 p64h_nfc_read_word(struct mtd_info *mtd)
{
    printf("@@@ %s not implemented\n", __func__);
    return -1;
}

static u8 p64h_nfc_read_byte(struct mtd_info *mtd)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    return *(const volatile u8 __force *)ctrl->sdma;
}

static void p64h_nfc_write_byte(struct mtd_info *mtd, u8 byte)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    *(volatile u8 __force *)ctrl->sdma = byte;
}

static void p64h_nfc_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
    printf("@@@ %s not implemented\n", __func__);
}

static void p64h_nfc_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
    printf("@@@ %s not implemented\n", __func__);
}

static void p64h_nfc_nand_select_chip(struct mtd_info *mtd, int chip_select)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    /* chip is deselected */
    if (chip_select < 0) {
        nand->selected = chip_select;
        return;
    }

    /* check if it was the previous chip */
    if (nand->selected == chip_select) {
        return;
    }

    nand->selected = chip_select;
    if (p64h_nfc_timeout_wait(ctrl,
                              CTRL_STATUS,
                              CTRL_STATUS_CTRL_BUSY,
                              CTRL_STATUS_CTRL_BUSY,
                              0,
                              TIMEOUT_100MS)) {
        nand->selected = -1;
    }

    p64h_nfc_nand_set_timings(ctrl, &nand->timings);
    p64h_nfc_nand_set_ecc_strength(ctrl, nand->corr_str_idx);
    ctrl->curr_trans_type = -1;
}

static int p64h_nfc_block_bad(struct mtd_info *mtd, loff_t ofs)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_wait_func(struct mtd_info *mtd, struct nand_chip *chip)
{
    int ret;
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    if (nand->selected < 0) {
        return -EINVAL;
    }

    ret = p64h_nfc_timeout_wait(ctrl,
                                RBN_SETTINGS,
                                BIT(nand->thread[nand->selected]),
                                BIT(nand->thread[nand->selected]),
                                1,
                                TIMEOUT_1S);
    return ret;
}

static int p64h_nfc_erase(struct mtd_info *mtd, int page)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    
	/* Send commands to erase a block */
    p64h_nfc_nand_cmd_process(chip, NAND_CMD_ERASE1);
    p64h_nfc_nand_addr_process(chip, page);
    p64h_nfc_nand_cmd_process(chip, NAND_CMD_ERASE2);

	return p64h_nfc_wait_func(mtd, chip);
}

static int p64h_nfc_dev_ready(struct mtd_info *mtd)
{
    /*
     * NFC handles R/B internally. Therefore, this function
     * always returns status as ready.
     */
    return 1;
}

static int p64h_nfc_setup_read_retry(struct mtd_info *mtd, int retry_mode)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static void p64h_nfc_nand_ecc_hwctl(struct mtd_info *mtd, int mode)
{
    printf("@@@ %s: not implemented\n", __func__);
}

static int
p64h_nfc_nand_ecc_calculate(struct mtd_info *mtd, const u8 *dat, u8 *ecc_code)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_nand_ecc_correct(struct mtd_info *mtd,
                                     u8 *dat,
                                     u8 *read_ecc,
                                     u8 *calc_ecc)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_nand_ecc_read_page_raw(struct mtd_info *mtd,
                                           struct nand_chip *chip,
                                           u8 *buf,
                                           int oob_required,
                                           int page)
{
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    int oob_skip = nand->bbm_len;
    int writesize = mtd->writesize;
    int ecc_steps = chip->ecc.steps;
    int ecc_size = chip->ecc.size;
    int ecc_bytes = chip->ecc.bytes;
    void *tmp_buf = ctrl->buffer;
    int ret, i, pos, len;

    if (nand->selected < 0) {
        return -EINVAL;
    }

    ret = p64h_nfc_nand_set_skip_bytes_conf(ctrl, 0, 0, 0);
    if (ret)
        return ret;

    p64h_nfc_nand_prepare_data_size(chip, TT_RAW_PAGE);
    ret = p64h_nfc_nand_cdma_transfer(ctrl,
                                      nand->thread[nand->selected],
                                      page,
                                      ctrl->buffer,
                                      NULL,
                                      mtd->writesize + mtd->oobsize,
                                      0,
                                      DMA_FROM_DEVICE,
                                      false);

    switch (ret) {
        case STAT_ERASED:
        case STAT_OK:
            break;

        default:
            dev_err(ctrl->dev, "read raw page failed\n");
            return -EIO;
    }

    /* Arrange the buffer for syndrome payload/ecc layout. */
    if (buf) {
        for (i = 0; i < ecc_steps; i++) {
            pos = i * (ecc_size + ecc_bytes);
            len = ecc_size;

            if (pos >= writesize)
                pos += oob_skip;
            else if (pos + len > writesize)
                len = writesize - pos;

            memcpy(buf, tmp_buf + pos, len);
            buf += len;
            if (len < ecc_size) {
                len = ecc_size - len;
                memcpy(buf, tmp_buf + writesize + oob_skip, len);
                buf += len;
            }
        }
    }

    if (oob_required) {
        u8 *oob = chip->oob_poi;
        u32 oob_data_offset =
            (nand->sector_count - 1) * (nand->sector_size + chip->ecc.bytes) +
            nand->sector_size + oob_skip;

        /* OOB free. */
        memcpy(oob, tmp_buf + oob_data_offset, nand->avail_oob_size);

        /* BBM at the beginning of the OOB area. */
        memcpy(oob, tmp_buf + writesize, oob_skip);

        oob += nand->avail_oob_size;

        /* OOB ECC */
        for (i = 0; i < ecc_steps; i++) {
            pos = ecc_size + i * (ecc_size + ecc_bytes);
            len = ecc_bytes;

            if (i == (ecc_steps - 1))
                pos += nand->avail_oob_size;

            if (pos >= writesize)
                pos += oob_skip;
            else if (pos + len > writesize)
                len = writesize - pos;

            memcpy(oob, tmp_buf + pos, len);
            oob += len;
            if (len < ecc_bytes) {
                len = ecc_bytes - len;
                memcpy(oob, tmp_buf + writesize + oob_skip, len);
                oob += len;
            }
        }
    }

    return 0;
}

static int p64h_nfc_ecc_write_page_raw(struct mtd_info *mtd,
                                       struct nand_chip *chip,
                                       const u8 *buf,
                                       int oob_required,
                                       int page)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_ecc_read_page(struct mtd_info *mtd,
                                  struct nand_chip *chip,
                                  u8 *buf,
                                  int oob_required,
                                  int page)
{
    int ret, ecc_err_count = 0;
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    if (nand->selected < 0) {
        return -EINVAL;
    }

    ret = p64h_nfc_nand_set_skip_bytes_conf(
        ctrl, nand->bbm_len, mtd->writesize + nand->bbm_offs, 1);
    if (ret)
        return ret;

    if (p64h_nfc_nand_dma_buf_ok(ctrl, buf, mtd->writesize) &&
        ctrl->caps.data_control_supp) {
        u8 *oob;

        if (oob_required)
            oob = chip->oob_poi;
        else
            oob = ctrl->buffer + mtd->writesize;

        p64h_nfc_nand_prepare_data_size(chip, TT_MAIN_OOB_AREA_EXT);
        ret = p64h_nfc_nand_cdma_transfer(ctrl,
                                          nand->thread[nand->selected],
                                          page,
                                          buf,
                                          oob,
                                          mtd->writesize,
                                          nand->avail_oob_size,
                                          DMA_FROM_DEVICE,
                                          true);
    } else {
        p64h_nfc_nand_prepare_data_size(chip, TT_MAIN_OOB_AREAS);
        ret = p64h_nfc_nand_cdma_transfer(ctrl,
                                          nand->thread[nand->selected],
                                          page,
                                          ctrl->buffer,
                                          NULL,
                                          mtd->writesize + nand->avail_oob_size,
                                          0,
                                          DMA_FROM_DEVICE,
                                          true);

        memcpy(buf, ctrl->buffer, mtd->writesize);
        if (oob_required)
            memcpy(chip->oob_poi, ctrl->buffer + mtd->writesize, mtd->oobsize);
    }

    switch (ret) {
        case STAT_ECC_UNCORR:
            mtd->ecc_stats.failed++;
            ecc_err_count++;
            break;

        case STAT_ECC_CORR:
            ecc_err_count = FIELD_GET(CDMA_CS_MAXERR, ctrl->cdma_desc->status);
            mtd->ecc_stats.corrected += ecc_err_count;
            break;

        case STAT_ERASED:
        case STAT_OK:
            break;

        default:
            dev_err(ctrl->dev, "read page failed\n");
            return -EIO;
    }

    if (oob_required)
        if (p64h_nfc_nand_read_bbm(chip, page, chip->oob_poi))
            return -EIO;

    return ecc_err_count;
}

static int p64h_nfc_ecc_write_page(struct mtd_info *mtd,
                                   struct nand_chip *chip,
                                   const u8 *buf,
                                   int oob_required,
                                   int page)
{
    int ret;
    u16 marker_val = 0xFFFF;
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);

    if (nand->selected < 0) {
        return -EINVAL;
    }

    ret = p64h_nfc_nand_set_skip_bytes_conf(
        ctrl, nand->bbm_len, mtd->writesize + nand->bbm_offs, 1);
    if (ret)
        return ret;

    if (oob_required) {
        marker_val = *(u16 *)(chip->oob_poi + nand->bbm_offs);
    } else {
        /* set oob data to 0xFF. */
        memset(ctrl->buffer + mtd->writesize, 0xFF, nand->avail_oob_size);
    }

    p64h_nand_set_skip_marker_val(ctrl, marker_val);
    p64h_nfc_nand_prepare_data_size(chip, TT_MAIN_OOB_AREA_EXT);

    if (p64h_nfc_nand_dma_buf_ok(ctrl, buf, mtd->writesize) &&
        ctrl->caps.data_control_supp) {
        u8 *oob;

        if (oob_required)
            oob = chip->oob_poi;
        else
            oob = ctrl->buffer + mtd->writesize;

        p64h_nfc_nand_prepare_data_size(chip, TT_MAIN_OOB_AREA_EXT);
        ret = p64h_nfc_nand_cdma_transfer(ctrl,
                                          nand->thread[nand->selected],
                                          page,
                                          (void *)buf,
                                          oob,
                                          mtd->writesize,
                                          nand->avail_oob_size,
                                          DMA_TO_DEVICE,
                                          true);

        if (ret) {
            return -EIO;
        }
    } else {
        /* TODO: check what needs to be done */
        BUG();
    }
    return 0;
}

static int p64h_nfc_ecc_write_oob_raw(struct mtd_info *mtd,
                                      struct nand_chip *chip,
                                      int page)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_ecc_read_oob_raw(struct mtd_info *mtd,
                                     struct nand_chip *chip,
                                     int page)
{
    return p64h_nfc_nand_ecc_read_page_raw(mtd, chip, NULL, true, page);
}

static int
p64h_nfc_ecc_read_oob(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);
    return p64h_nfc_ecc_read_page(mtd, chip, ctrl->buffer, 1, page);
}

static int
p64h_nfc_ecc_write_oob(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
    printf("@@@ %s: not implemented\n", __func__);
    return -1;
}

static int p64h_nfc_calc_cylc(u32 timing, u32 clock)
{
    if (timing == 0 || clock == 0)
        return 0;

    if ((timing % clock) > 0)
        return timing / clock;
    else
        return timing / clock - 1;
}

static inline u32 p64h_nfc_calc_tdvw_max(u32 trp_cnt,
                                         u32 clk_period,
                                         u32 trhoh_min,
                                         u32 board_delay_skew_min,
                                         u32 ext_mode)
{
    /* calculate max data valid window. */
    if (ext_mode == 0)
        clk_period /= 2;

    return (trp_cnt + 1) * clk_period + trhoh_min + board_delay_skew_min;
}

static inline u32 p64h_nfc_calc_tdvw(
    u32 trp_cnt, u32 clk_period, u32 trhoh_min, u32 trea_max, u32 ext_mode)
{
    /* calculate data valid window. */
    if (ext_mode == 0)
        clk_period /= 2;

    return (trp_cnt + 1) * clk_period + trhoh_min - trea_max;
}

static int p64h_nfc_setup_data_interface(struct mtd_info *mtd,
                                         int chipnr,
                                         const struct nand_data_interface *cfg)
{
    const struct nand_sdr_timings *sdr;
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);
    struct p64h_nfc_ctrl *ctrl = nand_get_controller_data(chip);
    struct p64h_nfc_nand_timings *t = &nand->timings;

    u32 reg;
    u32 board_delay = ctrl->board_delay;
    u32 clk_period = DIV_ROUND_DOWN_ULL(1000000000000ULL, ctrl->nf_clk_rate);
    u32 tceh_cnt, tcs_cnt, tadl_cnt, tccs_cnt;
    u32 tfeat_cnt, trhz_cnt, tvdly_cnt;
    u32 trhw_cnt, twb_cnt, twh_cnt = 0, twhr_cnt;
    u32 twp_cnt = 0, trp_cnt = 0, trh_cnt = 0;
    u32 if_skew = ctrl->caps.if_skew;
    u32 board_delay_skew_min = board_delay - if_skew;
    u32 board_delay_skew_max = board_delay + if_skew;
    u32 dqs_sampl_res, phony_dqs_mod;
    u32 tdvw, tdvw_min, tdvw_max;
    u32 ext_rd_mode, ext_wr_mode;
    u32 dll_phy_dqs_timing = 0, phony_dqs_timing = 0, rd_del_sel = 0;
    u32 sampling_point;

    sdr = nand_get_sdr_timings(cfg);
    if (IS_ERR(sdr))
        return PTR_ERR(sdr);

    memset(t, 0, sizeof(*t));

    if (ctrl->caps.is_phy_type_dll)
        phony_dqs_mod = 2;
    else
        phony_dqs_mod = 1;

    dqs_sampl_res = clk_period / phony_dqs_mod;

    tdvw_min = sdr->tREA_max + board_delay_skew_max;
    /*
     * the idea of those calculation is to get the optimum value
     * for tRP and tRH timings. If it is NOT possible to sample data
     * with optimal tRP/tRH settings, the parameters will be extended.
     * If clk_period is 50ns (the lowest value) this condition is met
     * for SDR timing modes 1, 2, 3, 4 and 5.
     * If clk_period is 20ns the condition is met only for SDR timing
     * mode 5.
     */
    if (sdr->tRC_min <= clk_period && sdr->tRP_min <= (clk_period / 2) &&
        sdr->tREH_min <= (clk_period / 2)) {
        /* performance mode. */
        ext_rd_mode = 0;
        tdvw = p64h_nfc_calc_tdvw(
            trp_cnt, clk_period, sdr->tRHOH_min, sdr->tREA_max, ext_rd_mode);
        tdvw_max = p64h_nfc_calc_tdvw_max(trp_cnt,
                                          clk_period,
                                          sdr->tRHOH_min,
                                          board_delay_skew_min,
                                          ext_rd_mode);
        /*
         * check if data valid window and sampling point can be found
         * and is not on the edge (ie. we have hold margin).
         * If not extend the tRP timings.
         */
        if (tdvw > 0) {
            if (tdvw_max <= tdvw_min || (tdvw_max % dqs_sampl_res) == 0) {
                /*
                 * no valid sampling point so the RE pulse need
                 * to be widen widening by half clock cycle.
                 */
                ext_rd_mode = 1;
            }
        } else {
            /*
             * there is no valid window
             * to be able to sample data the tRP need to be widen.
             * Very safe calculations are performed here.
             */
            trp_cnt = (sdr->tREA_max + board_delay_skew_max + dqs_sampl_res) /
                      clk_period;
            ext_rd_mode = 1;
        }
    } else {
        /* extended read mode. */
        u32 trh;

        ext_rd_mode = 1;
        trp_cnt = p64h_nfc_calc_cylc(sdr->tRP_min, clk_period);
        trh = sdr->tRC_min - ((trp_cnt + 1) * clk_period);
        if (sdr->tREH_min >= trh)
            trh_cnt = p64h_nfc_calc_cylc(sdr->tREH_min, clk_period);
        else
            trh_cnt = p64h_nfc_calc_cylc(trh, clk_period);

        tdvw = p64h_nfc_calc_tdvw(
            trp_cnt, clk_period, sdr->tRHOH_min, sdr->tREA_max, ext_rd_mode);
        /*
         * check if data valid window and sampling point can be found
         * or if it is at the edge check if previous is valid
         * - if not extend the tRP timings.
         */
        if (tdvw > 0) {
            tdvw_max = p64h_nfc_calc_tdvw_max(trp_cnt,
                                              clk_period,
                                              sdr->tRHOH_min,
                                              board_delay_skew_min,
                                              ext_rd_mode);

            if ((((tdvw_max / dqs_sampl_res) * dqs_sampl_res) <= tdvw_min) ||
                (((tdvw_max % dqs_sampl_res) == 0) &&
                 (((tdvw_max / dqs_sampl_res - 1) * dqs_sampl_res) <=
                  tdvw_min))) {
                /*
                 * data valid window width is lower than
                 * sampling resolution and do not hit any
                 * sampling point to be sure the sampling point
                 * will be found the RE low pulse width will be
                 *  extended by one clock cycle.
                 */
                trp_cnt = trp_cnt + 1;
            }
        } else {
            /*
             * there is no valid window to be able to sample data.
             * The tRP need to be widen.
             * Very safe calculations are performed here.
             */
            trp_cnt = (sdr->tREA_max + board_delay_skew_max + dqs_sampl_res) /
                      clk_period;
        }
    }

    tdvw_max = p64h_nfc_calc_tdvw_max(
        trp_cnt, clk_period, sdr->tRHOH_min, board_delay_skew_min, ext_rd_mode);

    if (sdr->tWC_min <= clk_period &&
        (sdr->tWP_min + if_skew) <= (clk_period / 2) &&
        (sdr->tWH_min + if_skew) <= (clk_period / 2)) {
        ext_wr_mode = 0;
    } else {
        u32 twh;

        ext_wr_mode = 1;
        twp_cnt = p64h_nfc_calc_cylc(sdr->tWP_min + if_skew, clk_period);
        if ((twp_cnt + 1) * clk_period < (sdr->tALS_min + if_skew))
            twp_cnt = p64h_nfc_calc_cylc(sdr->tALS_min + if_skew, clk_period);

        twh = (sdr->tWC_min - (twp_cnt + 1) * clk_period);
        if (sdr->tWH_min >= twh)
            twh = sdr->tWH_min;

        twh_cnt = p64h_nfc_calc_cylc(twh + if_skew, clk_period);
    }

    reg = FIELD_PREP(ASYNC_TOGGLE_TIMINGS_TRH, trh_cnt);
    reg |= FIELD_PREP(ASYNC_TOGGLE_TIMINGS_TRP, trp_cnt);
    reg |= FIELD_PREP(ASYNC_TOGGLE_TIMINGS_TWH, twh_cnt);
    reg |= FIELD_PREP(ASYNC_TOGGLE_TIMINGS_TWP, twp_cnt);
    t->async_toggle_timings = reg;

    tadl_cnt = p64h_nfc_calc_cylc((sdr->tADL_min + if_skew), clk_period);
    tccs_cnt = p64h_nfc_calc_cylc((sdr->tCCS_min + if_skew), clk_period);
    twhr_cnt = p64h_nfc_calc_cylc((sdr->tWHR_min + if_skew), clk_period);
    trhw_cnt = p64h_nfc_calc_cylc((sdr->tRHW_min + if_skew), clk_period);
    reg = FIELD_PREP(TIMINGS0_TADL, tadl_cnt);

    /*
     * if timing exceeds delay field in timing register
     * then use maximum value.
     */
    if (FIELD_FIT(TIMINGS0_TCCS, tccs_cnt))
        reg |= FIELD_PREP(TIMINGS0_TCCS, tccs_cnt);
    else
        reg |= TIMINGS0_TCCS;

    reg |= FIELD_PREP(TIMINGS0_TWHR, twhr_cnt);
    reg |= FIELD_PREP(TIMINGS0_TRHW, trhw_cnt);
    t->timings0 = reg;

    /* the following is related to single signal so skew is not needed. */
    trhz_cnt = p64h_nfc_calc_cylc(sdr->tRHZ_max, clk_period);
    trhz_cnt = trhz_cnt + 1;
    twb_cnt = p64h_nfc_calc_cylc((sdr->tWB_max + board_delay), clk_period);
    /*
     * because of the two stage syncflop the value must be increased by 3
     * first value is related with sync, second value is related
     * with output if delay.
     */
    twb_cnt = twb_cnt + 3 + 5;
    /*
     * the following is related to the we edge of the random data input
     * sequence so skew is not needed.
     */
    tvdly_cnt = p64h_nfc_calc_cylc(500000 + if_skew, clk_period);
    reg = FIELD_PREP(TIMINGS1_TRHZ, trhz_cnt);
    reg |= FIELD_PREP(TIMINGS1_TWB, twb_cnt);
    reg |= FIELD_PREP(TIMINGS1_TVDLY, tvdly_cnt);
    t->timings1 = reg;

    tfeat_cnt = p64h_nfc_calc_cylc(sdr->tFEAT_max, clk_period);
    if (tfeat_cnt < twb_cnt)
        tfeat_cnt = twb_cnt;

    tceh_cnt = p64h_nfc_calc_cylc(sdr->tCEH_min, clk_period);
    tcs_cnt = p64h_nfc_calc_cylc((sdr->tCS_min + if_skew), clk_period);

    reg = FIELD_PREP(TIMINGS2_TFEAT, tfeat_cnt);
    reg |= FIELD_PREP(TIMINGS2_CS_HOLD_TIME, tceh_cnt);
    reg |= FIELD_PREP(TIMINGS2_CS_SETUP_TIME, tcs_cnt);
    t->timings2 = reg;

    if (ctrl->caps.is_phy_type_dll) {
        reg = DLL_PHY_CTRL_DLL_RST_N;
        if (ext_wr_mode)
            reg |= DLL_PHY_CTRL_EXTENDED_WR_MODE;
        if (ext_rd_mode)
            reg |= DLL_PHY_CTRL_EXTENDED_RD_MODE;

        reg |= FIELD_PREP(DLL_PHY_CTRL_RS_HIGH_WAIT_CNT, 7);
        reg |= FIELD_PREP(DLL_PHY_CTRL_RS_IDLE_CNT, 7);
        t->dll_phy_ctrl = reg;
    }

    /* sampling point calculation. */
    if ((tdvw_max % dqs_sampl_res) > 0)
        sampling_point = tdvw_max / dqs_sampl_res;
    else
        sampling_point = (tdvw_max / dqs_sampl_res - 1);

    if (sampling_point * dqs_sampl_res > tdvw_min) {
        dll_phy_dqs_timing = FIELD_PREP(PHY_DQS_TIMING_DQS_SEL_OE_END, 4);
        dll_phy_dqs_timing |= PHY_DQS_TIMING_USE_PHONY_DQS;
        phony_dqs_timing = sampling_point / phony_dqs_mod;

        if ((sampling_point % 2) > 0) {
            dll_phy_dqs_timing |= PHY_DQS_TIMING_PHONY_DQS_SEL;
            if ((tdvw_max % dqs_sampl_res) == 0)
                /*
                 * calculation for sampling point at the edge
                 * of data and being odd number.
                 */
                phony_dqs_timing =
                    (tdvw_max / dqs_sampl_res) / phony_dqs_mod - 1;

            if (!ctrl->caps.is_phy_type_dll)
                phony_dqs_timing--;
        } else {
            phony_dqs_timing--;
        }
        rd_del_sel = phony_dqs_timing + 3;
    } else {
        dev_warn(ctrl->dev, "ERROR : cannot find valid sampling point\n");
    }

    reg = FIELD_PREP(PHY_CTRL_PHONY_DQS, phony_dqs_timing);
    if (ctrl->caps.is_phy_type_dll)
        reg |= PHY_CTRL_SDR_DQS;
    t->phy_ctrl = reg;

    if (ctrl->caps.is_phy_type_dll) {
        t->phy_dqs_timing = dll_phy_dqs_timing;

        reg = FIELD_PREP(PHY_GATE_LPBK_CTRL_RDS, rd_del_sel);
        t->phy_gate_lpbk_ctrl = reg;
    }

    return 0;
}

int p64h_nfc_nand_ecc_choose_conf(struct nand_chip *chip,
                                  const struct nand_ecc_caps *caps,
                                  int oobavail)
{
    int ret;

    /*
     * if .size and .strength are already set (usually by DT),
     * check if they are supported by this controller.
     */
    if (chip->ecc.size && chip->ecc.strength)
        return nand_check_ecc_caps(chip, caps, oobavail);

    /*
     * we want .size and .strength closest to the chip's requirement
     * unless NAND_ECC_MAXIMIZE is requested.
     */
    if (!(chip->ecc.options & NAND_ECC_MAXIMIZE)) {
        ret = nand_match_ecc_req(chip, caps, oobavail);
        if (!ret) {
            return 0;
        }
    }

    /* max ECC strength is the last thing we can do */
    return nand_maximize_ecc(chip, caps, oobavail);
}

static int p64h_nfc_nand_ooblayout_free(struct mtd_info *mtd,
                                        int section,
                                        struct mtd_oob_region *oobregion)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);

    if (section)
        return -ERANGE;

    oobregion->offset = nand->bbm_len;
    oobregion->length = nand->avail_oob_size - nand->bbm_len;

    return 0;
}

static int p64h_nfc_nand_ooblayout_ecc(struct mtd_info *mtd,
                                       int section,
                                       struct mtd_oob_region *oobregion)
{
    struct nand_chip *chip = mtd_to_nand(mtd);
    struct p64h_nfc_nand_chip *nand = to_nfc_nand(chip);

    if (section)
        return -ERANGE;

    oobregion->offset = nand->avail_oob_size;
    oobregion->length = chip->ecc.total;

    return 0;
}

static const struct mtd_ooblayout_ops nand_ooblayout_ops = {
    .ecc = p64h_nfc_nand_ooblayout_ecc,
    .rfree = p64h_nfc_nand_ooblayout_free,
};

static int p64h_nfc_nand_attach_chip(struct p64h_nfc_ctrl *ctrl,
                                     struct p64h_nfc_nand_chip *nand,
                                     struct nand_chip *chip)
{
    int ret;
    u32 ecc_size;
    struct mtd_info *mtd = nand_to_mtd(chip);

    if (chip->options & NAND_BUSWIDTH_16) {
        ret = p64h_nfc_nand_set_access_width16(ctrl, true);
        if (ret)
            return ret;
    }

    chip->options |= NAND_NO_SUBPAGE_WRITE;

    chip->ecc.mode = NAND_ECC_HW;
    chip->ecc.options |= NAND_ECC_CUSTOM_PAGE_ACCESS;

    chip->bbt_options |= NAND_BBT_USE_FLASH;
    chip->bbt_options |= NAND_BBT_NO_OOB;

    nand->bbm_offs = chip->badblockpos;
    nand->bbm_offs &= ~0x01;
    nand->bbm_len = 2;

    ret = p64h_nfc_nand_ecc_choose_conf(
        chip, &ctrl->ecc_caps, mtd->oobsize - nand->bbm_len);
    if (ret) {
        dev_err(ctrl->dev, "ECC configuration failed\n");
        return ret;
    }

    /* error correction configuration. */
    nand->sector_size = chip->ecc.size;
    nand->sector_count = mtd->writesize / nand->sector_size;
    ecc_size = nand->sector_count * chip->ecc.bytes;

    nand->avail_oob_size = mtd->oobsize - ecc_size;

    if (nand->avail_oob_size > ctrl->bch_metadata_size)
        nand->avail_oob_size = ctrl->bch_metadata_size;

    if ((nand->avail_oob_size + nand->bbm_len + ecc_size) > mtd->oobsize)
        nand->avail_oob_size -= 4;

    ret = p64h_nfc_nand_get_ecc_strength(ctrl, chip->ecc.strength);
    if (ret < 0)
        return -EINVAL;

    nand->corr_str_idx = (u8)ret;
    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_CTRL_BUSY,
                                CTRL_STATUS_CTRL_BUSY,
                                0,
                                TIMEOUT_100MS);

    p64h_nfc_nand_set_erase_detection(ctrl, true, chip->ecc.strength);

    p64h_nfc_nand_set_ecc_strength(ctrl, nand->corr_str_idx);

    if ((mtd->writesize + mtd->oobsize) > ctrl->buffer_size)
        ctrl->buffer_size = mtd->writesize + mtd->oobsize;

    mtd_set_ooblayout(mtd, &nand_ooblayout_ops);

    return 0;
}

/*
 * OOB layout is handled by the MTD core and the ONFI
 * parameter page, not by a static layout structure.
 */
static struct nand_ecclayout ecc_layout_empty = { .eccbytes = 0,
                                                  .eccpos = {},
                                                  .oobfree = {} };

static int
p64h_nfc_nand_chip_init(struct p64h_nfc_ctrl *ctrl, ofnode node, int devnum)
{
    int ret;
    u32 nthread;
    struct nand_chip *chip;
    struct mtd_info *mtd;
    struct p64h_nfc_nand_chip *nand;

    if (!ofnode_get_property(node, "reg", &nthread)) {
        dev_err(ctrl->dev, "'reg' property is not found\n");
        return -ENODEV;
    }

    nthread /= sizeof(u32);
    if (!nthread || nthread > ctrl->caps.max_banks) {
        dev_err(ctrl->dev, "invalid reg property size\n");
        return -EINVAL;
    }

    nand = calloc(1, sizeof(*nand) + (nthread * sizeof(u8)));
    if (!nand) {
        dev_err(ctrl->dev, "could not allocate chip structure\n");
        ret = -ENOMEM;
        goto p64h_nfc_nand_chip_init_err;
    }
    chip = &nand->chip;
    nand->nthread = nthread;
    nand->selected = -1;

    for (int i = 0; i < nthread; i++) {
        u32 cs;

        ret = ofnode_read_u32_index(node, "reg", i, &cs);
        if (ret) {
            dev_err(ctrl->dev, "failed to read \"reg\" property\n");
            goto p64h_nfc_nand_chip_init_err;
        }

        if (cs >= ctrl->caps.max_banks) {
            dev_err(ctrl->dev,
                    "invalid reg value: %u (max CS = %d)\n",
                    cs,
                    ctrl->caps.max_banks);
            ret = -EINVAL;
            goto p64h_nfc_nand_chip_init_err;
        }

        if (test_and_set_bit(cs, &ctrl->assigned_cs)) {
            dev_err(ctrl->dev, "CS %d already assigned\n", cs);
            ret = -EINVAL;
            goto p64h_nfc_nand_chip_init_err;
        }
        nand->thread[i] = (u8)cs;
    }

    /* assign controller-specific operations */

    /* set the driver entry points for MTD */
    chip->cmd_ctrl = p64h_nfc_cmd_ctrl;
    chip->select_chip = p64h_nfc_nand_select_chip;
    chip->read_byte = p64h_nfc_read_byte;
    chip->write_byte = p64h_nfc_write_byte;
    chip->dev_ready = p64h_nfc_dev_ready;
    chip->setup_data_interface = p64h_nfc_setup_data_interface;

    /* buffer read/write routines */
    chip->read_buf = p64h_nfc_read_buf;
    chip->write_buf = p64h_nfc_write_buf;

    /* other callbacks, TODO: check if needed */
    chip->read_word = p64h_nfc_read_word;
    chip->block_bad = p64h_nfc_block_bad;
    chip->block_markbad = p64h_nfc_block_markbad;
    chip->waitfunc = p64h_nfc_wait_func;
    chip->setup_read_retry = p64h_nfc_setup_read_retry;

    /* override the default ECC operations. */
    chip->ecc.read_page = p64h_nfc_ecc_read_page;
    chip->ecc.read_page_raw = p64h_nfc_nand_ecc_read_page_raw;
    chip->ecc.write_page = p64h_nfc_ecc_write_page;
    chip->ecc.write_page_raw = p64h_nfc_ecc_write_page_raw;
    chip->ecc.read_oob = p64h_nfc_ecc_read_oob;
    chip->ecc.write_oob = p64h_nfc_ecc_write_oob;
    chip->ecc.read_oob_raw = p64h_nfc_ecc_read_oob_raw;
    chip->ecc.write_oob_raw = p64h_nfc_ecc_write_oob_raw;

    chip->ecc.hwctl = p64h_nfc_nand_ecc_hwctl;
    chip->ecc.calculate = p64h_nfc_nand_ecc_calculate;
    chip->ecc.correct = p64h_nfc_nand_ecc_correct;

    /* set the ECC empty layout */
    chip->ecc.layout = &ecc_layout_empty;

    /* link the chip to the device and controller data */
    nand_set_controller_data(chip, ctrl);

    /* attach the device tree node to nand chip */
    nand_set_flash_node(chip, node);

    mtd = nand_to_mtd(chip);

    ret = nand_scan_ident(mtd, nthread, NULL);
    if (ret) {
        dev_err(ctrl->dev, "'nand_scan_ident()' failed: %d\n", ret);
        goto p64h_nfc_nand_chip_init_err;
    }

    chip->erase = p64h_nfc_erase;
    p64h_nfc_nand_attach_chip(ctrl, nand, chip);

    ret = nand_scan_tail(mtd);
    if (ret) {
        dev_err(ctrl->dev, "nand_scan_tail failed: %d\n", ret);
        return ret;
    }

    ret = nand_register(devnum, mtd);
    if (ret) {
        dev_err(ctrl->dev, "failed to register mtd device: %d\n", ret);
        return ret;
    }

    return 0;

p64h_nfc_nand_chip_init_err:
    free(nand);
    return ret;
}

static int p64h_nfc_ctrl_init(struct p64h_nfc_ctrl *ctrl)
{
    int ret, i;
    ofnode node;

    ctrl->cdma_desc =
        dma_alloc_coherent(sizeof(*ctrl->cdma_desc), &ctrl->dma_cdma_desc);
    if (!ctrl->cdma_desc) {
        dev_err(ctrl->dev, "could not allocate NFC buffer\n");
        return -ENOMEM;
    }

    ctrl->buffer = malloc(SZ_16K);
    if (!ctrl->buffer) {
        dma_free_coherent(ctrl->cdma_desc);
        dev_err(ctrl->dev, "could not allocate NFC buffer\n");
        return -ENOMEM;
    }

    /* loop over child nodes to detect NAND chips */
    dev_for_each_subnode(node, ctrl->dev)
    {
        ret = p64h_nfc_nand_chip_init(ctrl, node, i++);
        if (ret) {
            dma_free_coherent(ctrl->cdma_desc);
            free(ctrl->buffer);
            return ret;
        }
    }

    return 0;
}

static int p64h_nfc_probe(struct udevice *dev)
{
    int ret;
    struct p64h_nfc_ctrl *ctrl = dev_get_priv(dev);

    ctrl->dev = dev;

    /* wait until the controller initialization is complete */
    ret = p64h_nfc_timeout_wait(ctrl,
                                CTRL_STATUS,
                                CTRL_STATUS_INIT_COMP,
                                CTRL_STATUS_INIT_COMP,
                                1,
                                TIMEOUT_100MS);
    if (ret)
        return -ENODEV;

    ret = p64h_nfc_hw_init(ctrl);
    if (ret) {
        dev_err(dev, "failed to init hardware: %d\n", ret);
        return ret;
    }

    ret = p64h_nfc_ctrl_init(ctrl);
    if (ret) {
        dev_err(dev, "failed to init controller: %d\n", ret);
        return ret;
    }

    return 0;
}

static int p64h_nfc_of_to_plat(struct udevice *dev)
{
    int ret;
    u32 val;
    struct clk *clk;
    struct p64h_nfc_ctrl *ctrl = dev_get_priv(dev);
    fdt_addr_t base;
    fdt_size_t size;

    ctrl->dev = dev;

    /* register interface */
    base = devfdt_get_addr_size_index(dev, 0, &size);
    if (base == FDT_ADDR_T_NONE) {
        dev_err(dev, "failed to get NFC address\n");
        return -EINVAL;
    }
    ctrl->regs = devm_ioremap(dev, base, size);
    if (!ctrl->regs)
        return -ENOMEM;

    /* SDMA interface */
    base = devfdt_get_addr_size_index(dev, 1, &size);
    if (base == FDT_ADDR_T_NONE) {
        dev_err(dev, "failed to get SDMA address\n");
        return -EINVAL;
    }
    ctrl->sdma = devm_ioremap(dev, base, size);
    if (!ctrl->sdma)
        return -ENOMEM;

    /* external clock */
    clk = devm_clk_get(dev, "nf_clk");
    if (IS_ERR(clk))
        return PTR_ERR(clk);
    ctrl->nf_clk_rate = clk_get_rate(clk);

    /* cdns,board-delay-ps : Estimated Board delay. The value includes the total
       round trip delay for the signals and is used for deciding on values
       associated with data read capture. The example formula for SDR mode is
       the following:
       board delay = RE#PAD delay + PCB trace to device + PCB trace from device
       + DQ PAD delay */
    ret = ofnode_read_u32(dev_ofnode(dev), "cdns,board-delay-ps", &val);
    if (ret)
        val = 4830;
    ctrl->board_delay = val;

    return 0;
}

static const struct udevice_id p64h_nfc_ids[] = {
    { .compatible = "microchip,p64h-nfc" }, {}
};

U_BOOT_DRIVER(p64h_nfc) = {
    .name = "p64h_nfc",
    .id = UCLASS_MTD,
    .of_match = p64h_nfc_ids,
    .probe = p64h_nfc_probe,
    .of_to_plat = p64h_nfc_of_to_plat,
    .priv_auto = sizeof(struct p64h_nfc_ctrl),
};

void board_nand_init(void)
{
    struct udevice *dev;
    int ret;

    ret =
        uclass_get_device_by_driver(UCLASS_MTD, DM_DRIVER_GET(p64h_nfc), &dev);
    if (ret && ret != -ENODEV)
        pr_err("Failed to initialize %s: %d\n", dev->name, ret);
}

MODULE_LICENSE("GPL-2.0+");
MODULE_AUTHOR("romain.caritey@microchip.com");
MODULE_DESCRIPTION("P64H NAND Flash Controller driver");