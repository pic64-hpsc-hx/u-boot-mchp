/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines common enumeration, structures and functions that
 * are used to access bootcfg from otp
 */
#ifndef BOOT_CFG_HELPER_H
#define BOOT_CFG_HELPER_H

#include "acsu.h"

#define CS_ARRAY_SIZE 8 ///< Define the constant for the size of the pflash CS signal address mapping array

/// Max Boot Config vector select bit position allowed
#define SEC_OTP_BOOTCFG_VECT_SEL_MAX   4

/// max number of configuration table
#define NUM_SCFG_TABLE 3U
/// max number of images in image tbale
#define NUM_IMAGE_TABLE 8U
/// max number of nvm interface configurations
#define NUM_NVM_INTF_CFG 4U
/// max number of intf configuration word 
#define NUM_NVM_CFG_WORD    28U
/// max number of iob buf configuration 
#define NUM_NVM_IOB_BUF_CFG 4U

/**
 * @brief - Enum defining the process of FSBL requesting ZSBL to boot from a specific image_id and the ZSBL's progress in
 *          attempting to start this image
 */
typedef enum
{
  SYSC_FSBL_BOOT_REQ_NONE = 0U,       ///< No FSBL Forced image_id 
  SYSC_FSBL_BOOT_REQ_REQUEST,    ///< FSBL requests ZSBL boot with a forced image_id
  SYSC_FSBL_BOOT_REQ_PROCESSING, ///< ZSBL has identified that FSBL has requested forced image_id and is attempting this image
  SYSC_FSBL_BOOT_REQ_FAILED,     ///< ZSBL has terminated all retry attempts for the forced image id
  LAST_SYSC_FSBL_BOOT_REQ,
} sysc_fsbl_boot_req_t;
#ifndef SWIG
static_assert((uint32_t)LAST_SYSC_FSBL_BOOT_REQ <= (1u << 2), "sysc_fsbl_boot_req_t has more than 4 states, bit field too large for storage in 2-bit bit field see scratchpad_boot_mode_t");
#endif

/// boot configuration global data 0
typedef struct boot_cfg_global_data_0_t{
  uint32_t sysc_boot_medium   : 1;        ///< Boot image interface, 0 for SPI, 1 for PFLASH
  uint32_t nvm0_acsu_update: 1;           ///< bit to indicate to update NVM0 ACSU frequency. 1 = update, 0 = do not update
  uint32_t secc_zsbl_wdog_update: 1;      ///< bit to indicate to update SecC watchdog timeout
  uint32_t sysc_zsbl_wdog_update: 1;      ///< bit to indicate to update SysC watchdog timeout
  uint32_t nvm0_acsu_prediv: 6;           ///< selects the values 1-63 for a divided reference clock source to the PLL 
  uint32_t nvm0_acsu_fbdiv: 12;           ///< selects the values for the integer part of the feedback divide value 
  uint32_t nvm0_acsu_pllbwi: 2;      ///< Integral Path loop bandwidth control 
  uint32_t nvm0_acsu_pllbwp: 2;      ///< Proportional Path loop bandwidth control 
  uint32_t padding_gbl0: 6;               ///< padding to align to 32b
} boot_cfg_global_data_0_t;

/// boot configuration global data 1
typedef struct boot_cfg_global_data_1_t{
  uint32_t nvm0_acsu_post_div_by_clk0:7;  ///< ACSU post output divider for the CLK_OUT0
  uint32_t nvm0_acsu_post_div_by_clk1:7;  ///< ACSU post output divider for the CLK_OUT1
  uint32_t nvm0_acsu_post_div_by_clk2:7;  ///< ACSU post output divider for the CLK_OUT2
  uint32_t nvm0_acsu_post_div_by_clk3:7;  ///< ACSU post output divider for the CLK_OUT3
  uint32_t padding_gbl1: 4;               ///< padding to align to 32b
} boot_cfg_global_data_1_t;

/// boot configuration global data 1
typedef struct boot_cfg_global_data_2_t{
  uint32_t nvm0_acsu_post_div_by_clk4:7;  ///< ACSU post output divider for the CLK_OUT4
  uint32_t nvm0_acsu_post_div_by_clk5:7;  ///< ACSU post output divider for the CLK_OUT5
  uint32_t nvm0_acsu_post_div_by_clk6:7;  ///< ACSU post output divider for the CLK_OUT6
  uint32_t nvm0_acsu_post_div_by_clk7:7;  ///< ACSU post output divider for the CLK_OUT7
  uint32_t padding_gbl2: 4;               ///< padding to align to 32b
} boot_cfg_global_data_2_t;

/// boot configuration PSC
typedef struct boot_cfg_global_psc_t{
  uint32_t psc0_cfg_auto_sequence:1;      ///< auto_sequence configuration
  uint32_t psc0_cfg_vsense_en:1;          ///< vsense_en configuration
  uint32_t psc0_cfg_vsense_level:2;       ///< vsense_level configuration
  uint32_t psc0_cfg_powerup_setting:2;    ///< powerup_setting configuration
  uint32_t psc0_cfg_powerdn_setting:2;    ///< powerdn_setting configuration
  uint32_t psc1_cfg_auto_sequence:1;      ///< auto_sequence configuration
  uint32_t psc1_cfg_vsense_en:1;          ///< vsense_en configuration
  uint32_t psc1_cfg_vsense_level:2;       ///< vsense_level configuration
  uint32_t psc1_cfg_powerup_setting:2;    ///< powerup_setting configuration
  uint32_t psc1_cfg_powerdn_setting:2;    ///< powerdn_setting configuration
  uint32_t psc_timeout_ns:16;             ///< psc timeout in nanoseconds
} boot_cfg_global_psc_t;

/** 
 * @brief
 *  Defines global data
 */
typedef struct otp_global_data_t { 
  uint32_t secc_wdog_fwe_timeout_in_us;   ///< secc First Watchdog Expiry (FWE) timeout in uSeconds from last kick
  uint32_t secc_wdog_swe_timeout_in_us;   ///< secc Second Watchdog Expiry (SWE) timeout in uSeconds from last kick (must be > FWE)
  uint32_t secc_wdog_rpe_timeout_in_us;   ///< secc Reset Pending Watchdog Expiry (RPE) timeout in uSeconds from last kick (must be > SWE)
  uint32_t sysc_wdog_fwe_timeout_in_us;   ///< sysc First Watchdog Expiry (FWE) timeout in uSeconds from last kick
  uint32_t sysc_wdog_swe_timeout_in_us;   ///< sysc Second Watchdog Expiry (SWE) timeout in uSeconds from last kick (must be > FWE)   
  uint32_t sysc_wdog_rpe_timeout_in_us;   ///< sysc Reset Pending Watchdog Expiry (RPE) timeout in uSeconds from last kick (must be > SWE)
  boot_cfg_global_data_0_t global_data_0; ///< boot configuration global data 0
  boot_cfg_global_data_1_t global_data_1; ///< boot configuration global data 1
  boot_cfg_global_data_2_t global_data_2; ///< boot configuration global data 2
  boot_cfg_global_psc_t    psc;           ///< boot configuration power switch controller
} otp_global_data_t; 

/**
 * @brief
 *  Defines an entry for the SRAM EDAC configuration table for the interface
 *
 */
typedef struct sram_edac_timeout_t {
   //sram_edac_timeout_config;                          ///< edac controller is selected based on boot_select. spi0/pflash0 is connected to edac0, spi1/pflash1 is connected to edac1
  uint32_t rcmd_timeout_cfg  : 6; ///< time out timer for read request channel
  uint32_t rdcap_timeout_cfg : 6; ///< time out timer for data read channel
  //sram_edac_timeout_ctrl;
  uint32_t rcmd_en_timeout   : 1; ///< Enables read command timeout when asserted.
  uint32_t rdcap_en_timeout  : 1; ///< Enables read data timeout when asserted.
  uint32_t padding : 18;
} sram_edac_timeout_t;

/**
 * @brief
 *  Defines an entry for scfg_table
 *
 */
typedef struct otp_scfg_table_entry_t {
  uint32_t img_id_0 : 3; ///< pointer to SImgID 0
  uint32_t img_id_1 : 3; ///< pointer to SImgID 1
  uint32_t img_id_2 : 3; ///< pointer to SImgID 2
  uint32_t padding : 23; ///< padding to align for 32b
} otp_scfg_table_entry_t;

typedef struct config_word_0_t { ///< SPI packed configuration word
  uint32_t boot_spi_ctrl    : 1;  ///< Boot SPI controller, 0: QSPI0, 1: QSPI1
  uint32_t spi_work_mode    : 2;  ///< SPI work mode, 00: DIRECT, 01: STIG, 10: ACMD (Reserved), 11: RESERVED
  uint32_t discovery_mode   : 2;  ///< 00: disable discovery mode, 01: Automatic discovery mode, 10: Pre-configured SFDP mode 11: Pre-configured non-SFDP mode
  uint32_t enable_xip       : 1;  ///< Enable XIP mode
  uint32_t ref_clk_div_cfg  : 2;  ///< Reference clock divider configuration REFDIV_CLK_CTRL:CFG_CLK_DIV
  uint32_t qspi_phy_clk_div : 4;  ///< QSPI PHY clock divider. Must be <=5
  uint32_t fill_1           : 20; ///< Reserved
} config_word_0_t;                ///< Configuration Set 0

typedef struct phy_timing_t {
  //dq_timing_reg
    uint32_t dq_select_oe_end     : 3; ///< Adjusts the ending point of the DQ pad output enable window
    uint32_t dq_select_oe_start   : 3; ///< Adjusts the starting point of the DQ pad output enable window
    uint32_t dq_select_tsel_end   : 4; ///< Defines the DQ pad dynamic termination select disable time.
    uint32_t dq_select_tsel_start : 4; ///< Defines the DQ pad dynamic termination select enable time.
    uint32_t dq_clkperiod_delay   : 1; ///< Defines additional latency on the write datapath
  //phy_dqs_timing_reg
    uint32_t dqs_select_tsel_end   : 4; ///< Defines the DQ pad dynamic termination select disable time.
    uint32_t dqs_select_tsel_start : 4; ///< Defines the DQ pad dynamic termination select enable time.
    uint32_t phony_dqs_sel         : 1; ///< If this bit is cleared the phony_dqs is synchronous with rising edge of the clk_phy before sending to the entry flops.
    uint32_t use_phony_dqs         : 1; ///< control how read data is sampled by the PHY.
    uint32_t use_lpbk_dqs          : 1; ///< control how read data is sampled by the PHY
    uint32_t use_ext_lpbk_dqs      : 1; ///< control how read data is sampled by the PHY
    uint32_t padding               : 5; ///< padding to align to 32b
} phy_timing_t;

typedef struct phy_dll_ctrl_t { ///< combined values of 2 registers to pack into 32b
    //phy_dll_master_ctrl_reg
    uint32_t param_dll_start_point  : 8; ///< initial DLL delay
    uint32_t param_dll_lock_num     : 3; ///< Holds the number of consecutive increment or decrement indications that will trigger an unlock condition
    uint32_t param_phase_detect_sel : 3; ///< Selects the number of delay elements to be inserted between the phase detect flip-flops
    uint32_t param_dll_bypass_mode  : 1; ///< DLL bypass mode control
    //phy_dll_slave_ctrl_reg
    uint32_t read_dqs_delay : 8; ///< Read DQS delay
    uint32_t clk_wr_delay   : 8; ///< Clock write delay
    uint32_t fill_0                 : 1; ///< Reserved
} phy_dll_ctrl_t;

typedef struct spi_ctrl_cfg_t {
  // global_seq_cfg_t
  uint32_t seq_page_size_rd      : 4; ///< Determines page size of device being used for READ operations.
  uint32_t seq_crc_en            : 1; ///< Good to have: enables dynamic CRC calculation based on all previous bytes in the current sequence and puts this value on xSPI Flash Interface.
  uint32_t seq_crc_variant       : 1; ///< Good to have: Selecting of CRC variant
  uint32_t seq_crc_oe            : 1; ///< Good to have: This field determines if the controller expects the xSPI device to toggle CRC data on both SPI clock edges in CRC->CRCsequence
  uint32_t seq_crc_chunk_size    : 3; ///< Good to have: This field indicates the number of bytes after which CRC occurs
  uint32_t seq_crc_ual_chunk_en  : 1; ///< Good to have: enables taking into consideration the command address to determine after how many bytes CRC data slice is expected to be returned by the Flash  device.
  uint32_t seq_crc_ual_chunk_chk : 1; ///< Good to have: Setting this bit enables the checking of CRC unaligned chunk from the Flash Device
  uint32_t seq_tcms_en           : 1; ///< Good to have: Setting this bit enables tCMS timing in PROFILE 1.
  uint32_t seq_type              : 2; ///< Good to have: Sequence type (common for all sequences): PROFILE1/PROFILE2 etc.
  uint32_t seq_data_per_addr     : 1; ///< Selects data organization of the xSPI memory. Please note that xSPI address/pointer specified during sending CDMA/PIO and DIRECT

  // global_seq_cfg_1_t
  uint32_t seq_plane_cnt      : 2; ///< Good to have: Number of planes in SPI NAND device (encoded as 2^N):
  uint32_t seq_page_per_block : 3; ///< Good to have: Number of pages per blocks for SPI NAND device (encoded as 2^N):
  uint32_t seq_page_ca_size   : 1; ///< Good to have: Width of the Column Address for SPI NAND devices. Value of this field is used to calculate the next page address in case when data size specified in sequence exceed the current page capacity.

  // read_seq_cfg_0_t;
  uint32_t read_seq_p1_dummy_cnt : 6; ///< Number of dummy cycles. If 0 - dummy cycles disabled.
  uint32_t read_seq_p1_data_ios  : 2; ///< Number of data lines used to send data phase.
  uint32_t read_seq_p1_addr_ios  : 2; ///< Number of data lines used to send address phase.
  uint32_t read_seq_p1_addr_cnt  : 3; ///< Number of address bytes.
  uint32_t read_seq_p1_cmd_ios   : 2; ///< Number of data lines used to send command phase.
  uint32_t read_seq_p1_cmd_val   : 8; ///< Command mnemonic value.

  // stat_seq_cfg_0_t;
  uint32_t stat_seq_p1_data_ios   : 2; ///< Number of data lines used to send data phase.
  uint32_t stat_seq_p1_addr_ios   : 2; ///< Number of data lines used to send address phase.
  uint32_t stat_seq_p1_cmd_ext_en : 1; ///< Command extension enable.
  uint32_t stat_seq_p1_addr_cnt   : 2; ///< Number of address bytes for all status sequences.
  uint32_t stat_seq_p1_cmd_ios    : 2; ///< Number of data lines used to send command.

  // read_seq_cfg_1_t;
  uint32_t read_seq_p1_mb_dummy_cnt : 6; ///< Number of dummy cycles. If 0 - dummy cycles are disabled.
  uint32_t read_seq_p1_mb_en        : 1; ///< Set to 1'b1 to ensure the mode bits as defined in the xip_dis_mb_val field are sent following the address bytes.
  uint32_t read_seq_p1_cmd_ext_en   : 1; ///< Command extension enable.
  uint32_t padding_0                : 2; ///< padding to align to 32b
  uint32_t read_seq_p1_cmd_ext_val  : 8; ///< Command extension value.

  // stat_seq_cfg_1_t;
  uint32_t stat_seq_p1_dev_rdy_addr_en   : 1; ///< Enables address phase for checking ready/busy status after PROGRAM/ERASE and SOFT RESET/READ (only for SPI NAND) operation.
  uint32_t stat_seq_p1_dev_rdy_dummy_cnt : 6; ///< This register defines the number of dummy clock cycles needed to check ready/busy status after PROGRAM/ERASE or SOFT RESET/READ (only for SPI NAND) operation.

  // stat_seq_cfg_5_t;
  uint32_t stat_seq_dev_rdy_idx  : 4; ///< Yes:
  uint32_t stat_seq_dev_rdy_size : 1; ///< Yes:
  uint32_t stat_seq_dev_rdy_val  : 1; ///< Yes:

  // rst_seq_cfg_1_t;
  uint32_t rst_seq_p1_cmd1_ext_en  : 1; ///< Command extension enable for CMD1 phase.
  uint32_t rst_seq_p1_cmd0_ext_en  : 1; ///< Command extension enable for CMD0 phase.
  uint32_t rst_seq_p1_data_val     : 8; ///< Value of Confirmation Byte In (if enabled) following CMD1 phase.
  uint32_t padding_1               : 1; ///< padding to align to 32b
  uint32_t rst_seq_p1_cmd1_ext_val : 8; ///< Command extension value of CMD1 phase (if enabled).
  uint32_t rst_seq_p1_cmd0_ext_val : 8; ///< Command extension value of CMD0 phase (if enabled).

  // dll_phy_ctrl_t;
  uint32_t resync_high_wait_cnt : 4; ///< This field defines the number of xspi_clk cycles for which the DLL update request (dfi_ctrlupd_req) has to be asserted to resynchronize the DLLs and read and write FIFO pointers.
  uint32_t resync_idle_cnt      : 8; ///< This field defines the wait time (in terms of xspi_clk cycles) between the de-assertion of the DLL update request (dfi_ctrlupd_req) and resuming traffic to the PHY.
  uint32_t sdr_edge_active      : 1; ///< The PHY samples data on both edges of sampling clock.
  uint32_t padding_2            : 3; ///< padding to align to 32b

  // stat_seq_cfg_2_t;
  uint32_t stat_seq_p1_dev_rdy_cmd_val : 8; ///< Yes:

  // stat_seq_cfg_3_t;
  uint32_t stat_seq_p1_dev_rdy_cmd_ext_val : 8; ///< Yes:

  // rst_seq_cfg_0_t;
  uint32_t rst_seq_p1_cmd1_val : 8; ///< Command mnemonic value for CMD1 phase.
  uint32_t rst_seq_p1_cmd0_val : 8; ///< Command mnemonic value for CMD0 phase.
  uint32_t rst_seq_p1_cmd0_en  : 1; ///< Enable bit for CMD0 phase.

  // stat_seq_cfg_4_t;
  uint32_t stat_seq_p2_latency_cnt  : 6; ///< Good to have: Number of latency cycles between CA and STATUS reading.
  uint32_t stat_seq_p2_mask_cmd_mod : 1; ///< Good to have: Determines PROFILE 2 Command extension variant.

  // jedec_rst_timing_reg_t;
  uint32_t tCSL_delay : 8; ///< Defines how many xspi_clk cycles constitute tCSL timing of JEDEC Reset Instruction.
  uint32_t tCSH_delay : 8; ///< Defines how many xspi_clk cycles constitute tCSH timing of JEDEC Reset Instruction.

  // dev_delay_reg_t;
  uint32_t csda_min_delay : 8; ///< CSDA_MIN -Minimum Chip Select de-assertion timing.
  uint32_t cseot_delay    : 8; ///< CSEOT - Chip Select End Of Transfer. It allows to improve last active clock edge to CS de-assertion device timing.
  uint32_t cssot_delay    : 8; ///< CSSOT - Chip Select Start Of Transfer. It allows to improve CS de-assertion device timing to first active clock edge.

  // clock_mode_settings_t;
  uint32_t spi_clock_mode : 1; ///< Defines SPI Clock Mode.

  // direct_access_cfg_t
  uint32_t dac_addr_mask : 13; ///< Good to have: This mask is used for masking bits [44:32] of the system address for read/write transfers for PROFILE 2.

  uint32_t padding_3 : 2; ///< padding to align to 32b

  // rst_recovery_reg_t;
  uint32_t rst_recovery : 32; ///< This field defines additional delay for CS de-assertion to accommodate Device Reset Recovery timing.

  // stat_seq_cfg_7_t;
  uint32_t stat_seq_dev_rdy_addr : 32; ///< Yes:

  // dll_phy_update_cnt_t;
  uint32_t resync_cnt : 32; ///< This field defines the time interval (in terms of xspi_clk cycles) to send an update (assert dfi_ctrlupd_req high) to the PHY to re-synchronize the slave DLL values

  // read_seq_cfg_2_t;
  uint32_t read_seq_p2_latency_cnt  : 6; ///< Good to have: Number of latency cycles. Setting this bit to 0 disables latency clock cycles.
  uint32_t read_seq_p2_hf_bound_en  : 1; ///< Good to have: This field is used by the controller to calculate read transaction crossing page boundary.
  uint32_t read_seq_p2_mask_cmd_mod : 1; ///< Good to have: Determines PROFILE 2 Command extension variant.
  uint32_t read_seq_p2_target       : 1; ///< Good to have: Target space - corresponds to 46th Command/Address (CA) bit assignment.

  // hf_offset_reg_t;
  uint32_t hf_offset_size  : 6; ///< Good to have: Offset size of reserved area in command format.
  uint32_t hf_offset_index : 6; ///< Good to have: Starting index of reserved area in command format.

  // SDR_DDR_mode_t;
  uint32_t data_rate_mode : 1; ///< 0 - SDR, 1- DDR

  uint32_t padding_4 : 10; ///< padding to align to 32b
} spi_ctrl_cfg_t;

/**
 * @brief
 *  Defines iob buf configuration
 *
 */
typedef struct otp_iob_buf_cfg_t { 
    uint32_t sr_drvsrc:4;            ///< bit  0..3   r/w
    uint32_t sr_drvsnk:5;            ///< bit  4..8   r/w
    uint32_t sr_odtsrc:4;            ///< bit  9..12  r/w
    uint32_t sr_odtsnk:4;            ///< bit  13..16 r/w
    uint32_t sr_odt_static:3;        ///< bit  17..19 r/w
    uint32_t sr_odt_ibufmd:3;        ///< bit  20..22 r/w
    uint32_t sr_odt_ibufmx:2;        ///< bit  23..24 r/w
    uint32_t sr_odt_hyst:1;          ///< bit  25     r/w
    uint32_t sr_odt_wpu:1;           ///< bit  26     r/w
    uint32_t sr_odt_wpd:1;           ///< bit  27     r/w
    uint32_t sr_lp_persist:1;        ///< bit  28     r/w
    uint32_t sr_lp_bypass:1;         ///< bit  29     r/w
    uint32_t sr_obuf_en:1;           ///< bit  30     r/w
    uint32_t padding:1;                ///< bit  31     r/w  
} otp_iob_buf_cfg_t; 

/**
 * @brief
 *  Defines iob bank ctrl 
 *
 */
typedef struct  { 
    uint32_t sr_vs:6;                   ///< bit  0..5   r/w
    uint32_t sr_pg_bias:1;              ///< bit  6      r/w
    uint32_t sr_pg_opamp:1;             ///< bit  7      r/w
    uint32_t sr_pg_switch_n:1;          ///< bit  8      r/w
    uint32_t sr_vs_core:2;              ///< bit  9..10  r/w
    uint32_t sr_dly_s:5;                ///< bit  11..15 r/w
    uint32_t sr_calib_trim:1;           ///< bit  16     r/w
    uint32_t sr_calib_ptrim:1;          ///< bit  17     r/w
    uint32_t padding_0:14;              ///< bit  18..31 r/w
    uint32_t sr_trim_pcode:9;           ///< bit  0..8   r/w
    uint32_t sr_trim_ncode:9;           ///< bit  9..17  r/w
    uint32_t sr_calib_clkdiv:2;         ///< bit  18..19 r/w
    uint32_t sr_calib_gen10u:2;         ///< bit  20..21 r/w
    uint32_t padding_1:10;              ///< bit  22..31 r/w  
} otp_iob_bnk_ctrl_cfg_t;

typedef struct otp_spi_drv_cfg_t {
  config_word_0_t            config_word_0;
  uint32_t                   init_uTimeout; ///< Initialization timeout
  uint32_t                   discovery_control; ///< See SPI_CTRL_reg_DISCOVERY_CONTROL_t for definitions
  phy_timing_t               phy_timing;
  phy_dll_ctrl_t             phy_dll_ctrl;
  uint32_t                   phy_gate_lpbk_ctrl_reg; // TBD if this is required. To be vonfirmed by PD. Split to smaller packing if required.
  spi_ctrl_cfg_t             spi_ctrl_cfg; // controller configuration registers
  sram_edac_timeout_t        sram_edac_timeout;
  otp_iob_buf_cfg_t          iob_buf_cfg[NUM_NVM_IOB_BUF_CFG];
  otp_iob_bnk_ctrl_cfg_t     iob_bnk_ctrl_cfg;
} otp_spi_drv_cfg_t;

/**
 * @brief
 *  Defines pflash cfg that can occupy otp_nvm_intf_cfg_t
 *
 */
typedef struct otp_pflash_cfg_t { 
  uint32_t cfgw:2; ///< 8-bit or 16-bit flash device bus width
  uint32_t ignore_ready:1; ///< 8-bit or 16-bit flash device bus width
  uint32_t polarity_rdyf:1; ///< polarity of pflash_ready
  uint32_t polarity_wef:1; ///< polarity of pflash_wen
  uint32_t polarity_oef:1; ///< polarity of pflash_oen
  uint32_t polarity_cef:8; ///< Sets polarity of pflash_cen[7:0]. Each bit is set individually
  uint32_t travel:8; ///< travel 8-bit register value (expressed in NVM_SS_PHY clk_cycle)
  uint32_t trelgl:8; ///< trelgl 8-bit register value (expressed in NVM_SS_PHY clk_cycle)
  uint32_t padding1:2; ///< Padding to align page to 32b  
  uint32_t page:30; ///< Page read optimization, 0 - disabled, otherwise flash memory page size in increments of 32b 
  uint32_t padding2:2; ///< Padding to align trglqv to 32b  
  uint32_t trglqv:8; ///< trglqv 8-bit register value (expressed in NVM_SS_PHY clk_cycle)
  uint32_t trqvqv:8; ///< trqvqv 8-bit register value (expressed in NVM_SS_PHY clk_cycle)
  uint32_t trqvpqv:8; ///< trqvpqv 8-bit register value (expressed in NVM_SS_PHY clk_cycle)
  uint32_t padding3:8;       ///< padding bits to start of next 32bit word
  uint32_t clock_period_ps;  ///< PFLASH Controller Clock Period in picoseconds, 6400 for 156.25 MHz reference
  /// Per media configuration section:
  /// cs_mask and cs_map_start[x] and cs_map_end[x] are used to specify
  /// which CS signals are used and where each of the devices connected
  /// to the CS signal map to the internal 4GByte SRAM_EDAC memory side address map
  /// Every set cs_mask bit must have the equivalent cs_map_start/end[x] fields
  /// specified.  cs_map_end_x address is the end address + 1.
  uint32_t cs_mask:8; ///< 8-bit mask specifying which CS signals are in use
  uint32_t pad1:24;   ///< padding bits up to start of next 32bit word
  uint32_t cs_map_start[CS_ARRAY_SIZE]; ///< CSx base address to SRAM_EDAC 4GByte memory side address range
  uint32_t cs_map_end[CS_ARRAY_SIZE]; ///< CSx 'end address + 1' to SRAM_EDAC 4GByte memory side address range
  sram_edac_timeout_t sram_edac_timeout;
  otp_iob_buf_cfg_t          iob_buf_cfg[NUM_NVM_IOB_BUF_CFG];
  otp_iob_bnk_ctrl_cfg_t     iob_bnk_ctrl_cfg;
} otp_pflash_cfg_t; 

/**
 * @brief
 *  Defines an nvm interface configuration
 *
 */
typedef union otp_nvm_intf_cfg_t {
  otp_spi_drv_cfg_t spi_cfg;
  otp_pflash_cfg_t  pflash_cfg;
  uint32_t          boot_cfg_nvm[NUM_NVM_CFG_WORD];  
} otp_nvm_intf_cfg_t;

/**
 * @brief
 *  Defines an entry for image_table
 *
 */
typedef struct otp_image_table_entry_t {
  uint32_t nvm_header_offset_40_8;       ///< Image memory offset NVM FLASH0_SYSC_MEM offset, in units of 64-bit addresses, ie << 3 to get 8-bit address offset
  uint32_t intf                    : 1;  ///< physical interface instance 0 and 1 (FLASH0_SYSC_MEM A=0:1 memory contents access aperture selection)
  uint32_t spi_chip_select         : 2;  ///< SPI interface chip selection to access image, bit 0 CS0, bit 1 CS1
  uint32_t nvm_intf_cfg_inst       : 2;  ///< array index to interface configuration for an arbitrary intance, instance to be configured specified with 'intf'  
  uint32_t boot_image_format       : 1;  ///< 0 for raw (no ecc), 1 for SECDED
  // FALLBACK policy  
  uint32_t retry                   : 2;  ///< retry policy
  uint32_t policy                  : 1;  ///< 0 for EMERGENCY, 1 for NEXT_IMAGE
  uint32_t policy_simg_id          : 3;  ///< next simg ID, if 1 == policy
  uint32_t padding1                : 20; ///< Paddiing to align struct to 32b
} otp_image_table_entry_t; 
 
/**
 * @brief bits configuration
 */
typedef struct otp_bist_cfg_t {
    uint32_t sysc_bist:1;   ///< bit  0     R/W
    uint32_t secc_bist:1;   ///< bit  1     R/W
    uint32_t padding:30;    ///< bit  2..31 R/W  
} otp_bist_cfg_t;

/**
 * @brief
 *  Define structure of boot_cfg
 *
 */
typedef struct boot_cfg_t {  
  otp_scfg_table_entry_t  scfg_table;                    ///< scfg table, index processed is value retrieved BOOT_CFG[4:3] bit settings when BOOT_CFG[5] == 0
  otp_image_table_entry_t image_table[NUM_IMAGE_TABLE]; ///< image table, index 0 interface 0, index 1 interface 1
  otp_nvm_intf_cfg_t      nvm_intf_cfg[NUM_NVM_INTF_CFG];    ///< nvm interface configurations, unitless indexing, all index specified in scfg_table and policy_simg_id must contain valid data.  
}  boot_cfg_t;

/**
 * @brief
 *  Define structure of bootcfg_otp binary
 *
 */
typedef struct bootcfg_otp_t {
  otp_global_data_t global_data;    ///< global data 
  boot_cfg_t        boot_cfg;       ///< boot cfg
  otp_bist_cfg_t    bist_cfg;       ///< bits configuration
  uint32_t          mac_oui;        ///< MAC addr Organizationally Unique Identifier
  uint32_t          mac_base;       ///< Starting MAC addr
  uint32_t          num_mac;        ///< Total MAC addresses
  uint16_t          pcie_device_id; ///< PCIE Device ID
  uint16_t          pcie_vendor_id; ///< PCIE Vendor ID
  uint32_t          dev_cfg_version;///< Device Configurator Tool version
  uint32_t          user_version;   ///< User-Defined version
  uint32_t          spare_ecc[46];  ///< padding
} bootcfg_otp_t;

#endif /* BOOT_CFG_HELPER_H */
