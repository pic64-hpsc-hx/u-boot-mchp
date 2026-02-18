/*
 * P64H NAND Controller (NFC) U-Boot driver
 * Based on Cadence HPNFC driver
 *
 * SPDX-License-Identifier: GPL-2.0+
 * Copyright (C) 2025 Microchip Technology Ltd.
 *
 */

#ifndef _P64H_NFC_REGS_H_
#define _P64H_NFC_REGS_H_

#include <linux/bitops.h>
#include <linux/bitfield.h>
#include <linux/types.h>

/* General constants */
// #define MAX_ADDRESS_CYC         6
// #define MAX_ERASE_ADDRESS_CYC   3
// #define MAX_DATA_SIZE           0xFFFC
#define DMA_DATA_SIZE_ALIGN     8

/* Register Offsets */
#define CMD_REG0                0x0000
// #define CMD_REG1                0x0004
#define CMD_REG2                0x0008
#define CMD_REG3                0x000C
// #define CMD_STATUS_PTR          0x0010
// #define CMD_STATUS              0x0014

#define INTR_STATUS             0x0110
#define INTR_ENABLE             0x0114
#define CTRL_STATUS             0x0118
#define TRD_STATUS              0x0120
// #define TRD_ERR_INT_STATUS      0x0128
// #define TRD_ERR_INT_STATUS_EN   0x0130
// #define TRD_COMP_INT_STATUS     0x0138

#define TRAN_CFG_0              0x0400
#define TRAN_CFG_1              0x0404
#define ECC_CONFIG_0            0x0428
#define ECC_CONFIG_1            0x042C
#define MULTIPLANE_CFG          0x0434
#define CACHE_CFG               0x0438
// #define DMA_SETINGS             0x043C
#define SDMA_SIZE               0x0440
#define SDMA_TRD_NUM            0x0444
#define CONTROL_DATA_CTRL       0x0494

#define CTRL_VERSION            0x0800
#define CTRL_FEATURES           0x0804

#define BCH_CFG_0               0x0838
#define BCH_CFG_1               0x083C
#define BCH_CFG_2               0x0840
#define BCH_CFG_3               0x0844

#define RBN_SETTINGS            0x1004
#define COMMON_SET              0x1008
#define SKIP_BYTES_CONF         0x100C
#define SKIP_BYTES_OFFSET       0x1010
#define ASYNC_TOGGLE_TIMINGS    0x101C
#define TIMINGS0                0x1024
#define TIMINGS1                0x1028
#define TIMINGS2                0x102C
#define DLL_PHY_CTRL            0x1034

#define PHY_DQ_TIMING           0x2000
#define PHY_DQS_TIMING          0x2004
#define PHY_GATE_LPBK_CTRL      0x2008
#define PHY_DLL_MASTER_CTRL     0x200C
#define PHY_DLL_SLAVE_CTRL      0x2010
#define PHY_CTRL                0x2080
#define PHY_TSEL                0x2084

/* Bitfields and Masks */
#define CMD_REG0_CT             GENMASK(31, 30)
#define CMD_REG0_CT_CDMA        0uL
#define CMD_REG0_CT_GEN         3uL
#define CMD_REG0_TN             GENMASK(26, 24)

// #define INTR_STATUS_SDMA_ERR    BIT(22)
#define INTR_STATUS_SDMA_TRIGG  BIT(21)
// #define INTR_STATUS_UNSUPP_CMD  BIT(19)
// #define INTR_STATUS_DDMA_TERR   BIT(18)
// #define INTR_STATUS_CDMA_TERR   BIT(17)
// #define INTR_STATUS_CDMA_IDL    BIT(16)

// #define INTR_ENABLE_INTR_EN         BIT(31)
// #define INTR_ENABLE_SDMA_ERR_EN     BIT(22)
// #define INTR_ENABLE_SDMA_TRIGG_EN   BIT(21)
// #define INTR_ENABLE_UNSUPP_CMD_EN   BIT(19)
// #define INTR_ENABLE_DDMA_TERR_EN    BIT(18)
// #define INTR_ENABLE_CDMA_TERR_EN    BIT(17)
// #define INTR_ENABLE_CDMA_IDLE_EN    BIT(16)

#define CTRL_STATUS_INIT_COMP   BIT(9)
#define CTRL_STATUS_CTRL_BUSY   BIT(8)

#define TRAN_CFG_0_OFFSET       GENMASK(31, 16)
#define TRAN_CFG_0_SEC_CNT      GENMASK(7, 0)
#define TRAN_CFG_1_LAST_SEC_SIZE    GENMASK(31, 16)
#define TRAN_CFG_1_SECTOR_SIZE      GENMASK(15, 0)

#define ECC_CONFIG_0_CORR_STR       GENMASK(10, 8)
#define ECC_CONFIG_0_ERASE_DET_EN   BIT(1)
#define ECC_CONFIG_0_ECC_EN         BIT(0)

#define SDMA_TRD_NUM_SDMA_TRD       GENMASK(2, 0)
#define CONTROL_DATA_CTRL_SIZE      GENMASK(15, 0)

#define CTRL_VERSION_REV            GENMASK(7, 0)
#define CTRL_FEATURES_NVDDR_2_3     BIT(28)
#define CTRL_FEATURES_NVDDR         BIT(27)
// #define CTRL_FEATURES_ASYNC         BIT(26)
#define CTRL_FEATURES_N_BANKS       GENMASK(25, 24)
#define CTRL_FEATURES_DMA_DWITH64   BIT(21)
#define CTRL_FEATURES_CONTROL_DATA  BIT(10)

#define BCH_MAX_NUM_CORR_CAPS       8
#define BCH_MAX_NUM_SECTOR_SIZES    2
#define BCH_CFG_0_CORR_CAP_0        GENMASK(7, 0)
#define BCH_CFG_0_CORR_CAP_1        GENMASK(15, 8)
#define BCH_CFG_0_CORR_CAP_2        GENMASK(23, 16)
#define BCH_CFG_0_CORR_CAP_3        GENMASK(31, 24)
#define BCH_CFG_1_CORR_CAP_4        GENMASK(7, 0)
#define BCH_CFG_1_CORR_CAP_5        GENMASK(15, 8)
#define BCH_CFG_1_CORR_CAP_6        GENMASK(23, 16)
#define BCH_CFG_1_CORR_CAP_7        GENMASK(31, 24)
#define BCH_CFG_2_SECT_0            GENMASK(15, 0)
#define BCH_CFG_2_SECT_1            GENMASK(31, 16)
#define BCH_CFG_3_METADATA_SIZE     GENMASK(23, 16)

#define COMMON_SET_DEVICE_16BIT     BIT(8)
#define SKIP_BYTES_MARKER_VALUE     GENMASK(31, 16)
#define SKIP_BYTES_NUM_OF_BYTES     GENMASK(7, 0)
#define SKIP_BYTES_OFFSET_VALUE     GENMASK(23, 0)

#define ASYNC_TOGGLE_TIMINGS_TRH    GENMASK(28, 24)
#define ASYNC_TOGGLE_TIMINGS_TRP    GENMASK(20, 16)
#define ASYNC_TOGGLE_TIMINGS_TWH    GENMASK(12, 8)
#define ASYNC_TOGGLE_TIMINGS_TWP    GENMASK(4, 0)

#define TIMINGS0_TADL               GENMASK(31, 24)
#define TIMINGS0_TCCS               GENMASK(23, 16)
#define TIMINGS0_TWHR               GENMASK(15, 8)
#define TIMINGS0_TRHW               GENMASK(7, 0)
#define TIMINGS1_TRHZ               GENMASK(31, 24)
#define TIMINGS1_TWB                GENMASK(23, 16)
#define TIMINGS1_TVDLY              GENMASK(7, 0)
#define TIMINGS2_TFEAT              GENMASK(25, 16)
#define TIMINGS2_CS_HOLD_TIME       GENMASK(13, 8)
#define TIMINGS2_CS_SETUP_TIME      GENMASK(5, 0)

#define DLL_PHY_CTRL_DLL_RST_N      BIT(24)
#define DLL_PHY_CTRL_EXTENDED_WR_MODE   BIT(17)
#define DLL_PHY_CTRL_EXTENDED_RD_MODE   BIT(16)
#define DLL_PHY_CTRL_RS_HIGH_WAIT_CNT   GENMASK(11, 8)
#define DLL_PHY_CTRL_RS_IDLE_CNT        GENMASK(7, 0)

#define PHY_DQS_TIMING_DQS_SEL_OE_END   GENMASK(3, 0)
#define PHY_DQS_TIMING_PHONY_DQS_SEL    BIT(16)
#define PHY_DQS_TIMING_USE_PHONY_DQS    BIT(20)
#define PHY_GATE_LPBK_CTRL_RDS          GENMASK(24, 19)
#define PHY_DLL_MASTER_CTRL_BYPASS_MODE BIT(23)
#define PHY_CTRL_SDR_DQS                BIT(14)
#define PHY_CTRL_PHONY_DQS              GENMASK(9, 4)

// /* Generic command layout */
#define GCMD_LAY_CS             GENMASK_ULL(10, 8)
#define GCMD_LAY_TWB            BIT_ULL(6)
#define GCMD_LAY_INSTR          GENMASK_ULL(5, 0)
#define GCMD_LAY_INSTR_CMD      0
#define GCMD_LAY_INSTR_ADDR     1
#define GCMD_LAY_INSTR_DATA     2
#define GCMD_LAY_INPUT_CMD      GENMASK_ULL(23, 16)
#define GCMD_LAY_INPUT_ADDR     GENMASK_ULL(63, 16)
#define GCMD_LAY_INPUT_ADDR_SIZE    GENMASK_ULL(13, 11)
#define GCMD_DIR                BIT_ULL(11)
#define GCMD_DIR_READ           0
#define GCMD_DIR_WRITE          1
#define GCMD_ECC_EN             BIT_ULL(12)
#define GCMD_SECT_SIZE          GENMASK_ULL(31, 16)
#define GCMD_SECT_CNT           GENMASK_ULL(39, 32)
#define GCMD_LAST_SIZE          GENMASK_ULL(55, 40)

/* CDMA descriptor fields */
#define CDMA_CT_ERASE           0x1000
#define CDMA_CT_WR              0x2100
#define CDMA_CT_RD              0x2200
#define CDMA_CFPTR_MEM_SHIFT    24
#define CDMA_CFPTR_MEM          GENMASK(26, 24)
#define CDMA_CF_INT             BIT(8)
#define CDMA_CF_CONT            BIT(9)
#define CDMA_CF_DMA_MASTER      BIT(10)
#define CDMA_CS_COMP            BIT(15)
#define CDMA_CS_FAIL            BIT(14)
#define CDMA_CS_ERP             BIT(11)
#define CDMA_CS_TOUT            BIT(10)
#define CDMA_CS_MAXERR          GENMASK(9, 2)
#define CDMA_CS_UNCE            BIT(1)
#define CDMA_CS_ERR             BIT(0)

/* Status of operation */
#define STAT_OK                 0
#define STAT_FAIL               2
#define STAT_ECC_UNCORR         3
#define STAT_ERASED             5
#define STAT_ECC_CORR           6
#define STAT_UNKNOWN            7
#define STAT_BUSY               0xFF

#define TT_MAIN_OOB_AREAS     2
#define TT_RAW_PAGE           3
#define TT_BBM                4
#define TT_MAIN_OOB_AREA_EXT  5

/* Timeout values */
#define TIMEOUT_1S              1000000
#define TIMEOUT_100MS           100000
#define TIMEOUT_10S             10000000

/* Address mask */
#define ADDR0_MASK      GENMASK(23, 16)
#define ADDR1_MASK      GENMASK(31, 24)
#define ADDR2_MASK      GENMASK(39, 32)
#define ADDR3_MASK      GENMASK(47, 40)
#define ADDR4_MASK      GENMASK(55, 48)
#define ADDR5_MASK      GENMASK(63, 56)
#define NBYTES_MASK     GENMASK(13, 11)

// Combined address masks
#define ADDR0_1_MASK    GENMASK(31, 16)
#define ADDR0_2_MASK    GENMASK(39, 16)
#define ADDR0_3_MASK    GENMASK(47, 16)
#define ADDR0_4_MASK    GENMASK(55, 16)
#define ADDR0_5_MASK    GENMASK(63, 16)

#define ADDR1_2_MASK    GENMASK(39, 24)
#define ADDR1_3_MASK    GENMASK(47, 24)
#define ADDR1_4_MASK    GENMASK(55, 24)
#define ADDR1_5_MASK    GENMASK(63, 24)

#define ADDR2_3_MASK    GENMASK(47, 32)
#define ADDR2_4_MASK    GENMASK(55, 32)
#define ADDR2_5_MASK    GENMASK(63, 32)

#define ADDR3_4_MASK    GENMASK(55, 40)
#define ADDR3_5_MASK    GENMASK(63, 40)
#define ADDR4_5_MASK    GENMASK(63, 48)

#endif /* _P64H_NFC_REGS_H_ */
