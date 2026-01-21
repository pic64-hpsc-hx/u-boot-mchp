/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ddr_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_DDR_TYPE_H
#define P64H_SYSC_DDR_TYPE_H

#include <generated/p64h_sysc_ddr_defs.h>
#include "p64h_sysc_common_types.h"

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_DDR_INSTANCE_NUM  2u   ///< /// Number of DDR instances
#define P64H_SYSC_DDR_EDAC_IF       2u   ///< define the number of DDR EDAC interfaces
#define P64H_SYSC_DDR_INST_NUM      2u   ///< number of DDR instances
#define P64H_SYSC_DDR_HSIO_INST_NUM 5u   ///< number of HSIO bank instances
#define P64H_SYSC_DDR_CTRL_REGS     412u ///< Number of DDR controller registers
#define P64H_SYSC_DDR_PHY_DQ_PINS   80u  ///< DDR PHY number of DQ pins
#define P64H_SYSC_DDR_PHY_LANE_NUM  10u  ///< DDR PHY number of lanes

/* Public Structs and Enums --------------------------------------- */

/// DDR type
typedef enum {
    P64H_SYSC_DDR_TYPE_DDR3 = 0u, ///< DDR3 memory type
    P64H_SYSC_DDR_TYPE_DDR4,      ///< DDR4 memory type
    P64H_SYSC_DDR_TYPE_LAST,      ///< invalid, used for error checking
} p64h_sysc_ddr_type_t;

/// DQ width
typedef enum {
    P64H_SYSC_DQ_WIDTH_64B_DATA_16B_PARITY = 0u, ///< 64-bit data + 16-bit parity
    P64H_SYSC_DQ_WIDTH_64B_DATA_8B_ECC,          ///< 64-bit data + 8-bit ECC
    P64H_SYSC_DQ_WIDTH_64B_DATA,                 ///< 64-bit data
    P64H_SYSC_DQ_WIDTH_LAST                      ///< invalid, user for error checking
} p64h_sysc_dq_width_t;

/**
 * @brief
 *  Enumeration of RS data alignment
 */
typedef enum {
    P64H_SYSC_RS_DATA_ALIGNMENT_HORIZONTAL, ///< See doc
    P64H_SYSC_RS_DATA_ALIGNMENT_VERTICAL,   ///< See doc
    P64H_SYSC_RS_DATA_ALIGNMENT_LAST
} p64h_sysc_rs_data_alignment_t;

/// DDR PHY lane configuration
typedef struct {
    uint8_t wrlvl_iog_sr_dly_txs;      ///< Tap write DQS delay
    uint8_t wrdbus_phywrap_pipe_delay; ///< Write calibration delay
    uint8_t rdgt_phywrap_steps_180;    ///< Read gate 180 degree step offset
    uint8_t rdgt_lanectl_sr_rdgt_dly;  ///< Initial read gate delay setting
    uint8_t rdbus_lanectl_sr_rx0_dly;  ///< Initial read data bus RX delay
    uint8_t wrdbus_iog_dm_dly_txs;     ///< Tap write DM delay
} p64h_sysc_ddr_phy_lane_cfg_t;

/// DQ Pin configuration for DDR PHY
typedef struct {
    uint8_t tap_tx_delay; ///< TAP Tx delay
    uint8_t tap_rx_delay; ///< TAP Rx delay
} p64h_sysc_ddr_phy_dq_pin_cfg_t;

/// Debug info on DLL
typedef struct {
    uint8_t reg0_lock_int_ri;    ///< reg0 lock status
    uint8_t reg0_unlock_irq_ri;  ///< reg0 unlock status
    uint8_t reg1_lock_int_ri;    ///< reg1 unlock status
    uint8_t reg1_unlock_int_ri;  ///< reg1 unlock status
    uint8_t reg0_lock_int_irq;   ///< reg0 lcok interrupt bit
    uint8_t reg0_unlock_int_irq; ///< reg0 unlock interrupt bit
    uint8_t reg1_lock_int_irq;   ///< reg1 lock interrupt bit
    uint8_t reg1_unlock_int_irq; ///< reg1 unlock interrupt bit
} p64h_sysc_ddr_phy_debug_dll_t;

/// Debug info on PLL
typedef struct {
    uint8_t lock_irq_ri;    ///< PLL lock status
    uint8_t unlock_irq_ri;  ///< PLL unlock status
    uint8_t lock_irq_irq;   ///< PLL lock interrupt bit
    uint8_t unlock_irq_irq; ///< PLL unlock interrupt bit
} p64h_sysc_ddr_phy_debug_pll_t;

/// Debug info on hsio
typedef struct {
    uint16_t ro_bnk_pcode;  ///< Calib pcode
    uint16_t ro_bnk_ncode;  ///< Calib ncode
    uint8_t  ro_ioen;       ///< IO enable probe
    uint8_t  ro_io_en_dly;  ///< IO enable delay probe
    uint8_t  ro_down_vdd18; ///< Voltage probe
} p64h_sysc_ddr_phy_debug_hsio_bank_t;

/// Debug info on calib/pll/dll
typedef struct {
    p64h_sysc_ddr_phy_debug_hsio_bank_t hsio_bank[P64H_SYSC_DDR_HSIO_INST_NUM];
    p64h_sysc_ddr_phy_debug_pll_t       hsio1_pll0;
    p64h_sysc_ddr_phy_debug_pll_t       hsio3_pll0;
    p64h_sysc_ddr_phy_debug_dll_t       hsio1_dll0;
    p64h_sysc_ddr_phy_debug_dll_t       hsio3_dll0;
} p64h_sysc_ddr_phy_debug_t;

/// DDR PHY configuration
typedef struct {
    uint32_t                       ca_sr_dly_txs;                         ///< Common CA delay for control signals
    p64h_sysc_ddr_phy_dq_pin_cfg_t dq_pin_cfg[P64H_SYSC_DDR_PHY_DQ_PINS]; ///< DQ pin configuration
    p64h_sysc_ddr_phy_lane_cfg_t   lane_cfg[P64H_SYSC_DDR_PHY_LANE_NUM];  ///< Lane configuration
    p64h_sysc_ddr_phy_debug_t      debug;
} p64h_sysc_ddr_phy_cfg_t;

/// DDR topology
typedef struct {
    p64h_sysc_ddr_type_t ddr_type;    ///< DDR memory type
    p64h_sysc_dq_width_t dq_width;    ///< DQ width
    p64h_sysc_ddr_part_t part;        ///< DDR part
    uint32_t             mdps;        ///< mega transfer per second
    uint8_t              burst_len;   ///< burst len
    uint8_t              cas_latency; ///< cas latency
    uint64_t             size;        ///< size
    uint32_t             chip_select; ///< chip select
} p64h_sysc_ddr_topo_cfg_t;

/// DDR CTRL configuration
typedef struct {
    uint32_t ddr_ctrl[P64H_SYSC_DDR_CTRL_REGS]; ///< DDR Controller register configuration (auto-generated from config)
    // additional paramters can be added here
    //  - CA parity
    //  - Bank Group Rotation
} p64h_sysc_ddr_ctrl_cfg_t;

/// DDR initialization configuration
typedef struct {
    bool     init_en;   ///< enable memory initialization
    uint64_t init_data; ///< 64-bit word to be encoded and written to memory.
    bool     cold_boot; ///< cold boot when true, otherwise warm boot
} p64h_sysc_ddr_init_cfg_t;

/// Defines DDR subsystem configuration
typedef struct {
    bool                     active[P64H_SYSC_DDR_INST_NUM]; ///< TRUE - DDR instance is active, FALSE - DDR instance is not active
    p64h_sysc_ddr_topo_cfg_t topo_cfg;
    p64h_sysc_ddr_ctrl_cfg_t ctrl_cfg;
    p64h_sysc_ddr_init_cfg_t init_cfg;
} p64h_sysc_ddr_ss_cfg_t;

/// Timeout mechanism configuration for DDR_EDAC
typedef struct {
    bool    wdresp_en;  ///< Enables write response timeout mechanism when asserted
    bool    wdgen_en;   ///< Enables write data timeout when asserted
    bool    wcmd_en;    ///< Enabled write request timeout when asserted
    bool    rdcap_en;   ///< Enables read data timeout when asserted
    bool    rcmd_en;    ///< Enables read request timeout when asserted
    uint8_t wdresp_val; ///< write response timeout mechanism
    uint8_t wdgen_val;  ///< Enables write data timeout
                        ///< Timer expires = clock period * 2^(wdgen_val+1) + clock period
    uint8_t wcmd_val;   ///< Enabled write request timeout
                        ///< Timer expires = clock period * 2^(wcmd_val+1) + clock period
    uint8_t rdcap_val;  ///< Enables read data timeout
                        ///< Timer expires = clock period * 2^(rdcap_val+1) + clock period
    uint8_t rcmd_val;   ///< Enables read request timeout
                        ///< Timer expires = clock period * 2^(rcmd_val+1) + clock period
} p64h_sysc_ddr_timeout_cfg_t;

/// DDR EDAC configuration
typedef struct {
    p64h_sysc_mem_fec_mode_t fec_mode; ///< BYPASS, SECDED or DEECE

    bool                     wdgen_uncor_wstrb_zero_en; ///< when enabled, the write strobes are cleared when an uncorrectable error is detected.
                                    ///< Otherwise, the write is allowed to proceed with the potentially corrupted strobes or wlast.
    bool wstrb_sparse_det_en;   ///< when enabled, wstrb sparse detection for RMW operations.
                                ///< If the AXI wstrb is not set to all ones on incoming data, with this enabled, a RMW operation will occur.
    bool     bus_secded_bypass; ///< bypass AXI Bus secded checking
    bool     addr_chk_en;       ///< Enables address checking on Reed Solomon (DEECE) decoding.
    bool     init_en;           ///< Enables initializing the memory
    uint32_t init_val;          ///< Value to use for initializing the memory.
    bool     bypass_pl_rd_en;   ///< In bypass mode, partial reads create 64B reads within the EDAC block
    bool     bypass_rmw_en;     ///< In bypass mode, partial writes create 64B read/modify/write operations within the EDAC block.
    bool multi_rmw_en; ///< up to 8 outstanding read-modify write transactions can be held in the EDAC block. And up to 8 overlapping RMW transactions
                       ///< can be merged to one.
    bool                          drop_unkn_wr_en;   ///<  Write transaction responses with no matching context will be dropped if enabled
    bool                          drop_unkn_rd_en;   ///<  Read transaction responses with no matching context will be dropped if enabled
    p64h_sysc_rs_data_alignment_t rs_data_alignment; ///< RS encoder/decoder data alignment.  DEECE mode only.
    bool rs_dec_two_rank_en; ///< if TRUE, two ranks are connected to the RS decoder, if FALSE, only one rank is connected to the RS decoder.  DEECE
                             ///< mode only.
    uint8_t rs_dec_rank_addr_bits; ///< Declares which of the up to 40 bits in address_in is used to determine the rank where the current block is
                                   ///< from. It is expected to have one bit to be used to determine the DDR rank for each block.  DEECE mode only.
    p64h_sysc_ddr_timeout_cfg_t  timeout_cfg;      ///< see p64h_sysc_ddr_timeout_cfg_t
    p64h_sysc_demand_scrub_cfg_t demand_scrub_cfg; ///< see p64h_sysc_demand_scrub_cfg_t
    p64h_sysc_patrol_scrub_cfg_t patrol_scrub_cfg; ///< see p64h_sysc_patrol_scrub_cfg_t
} p64h_sysc_ddr_edac_cfg_t;

/// DDR configuration
typedef struct {
    p64h_sysc_ddr_edac_cfg_t ddr_edac_cfg[P64H_SYSC_DDR_EDAC_IF];     ///< EDAC configuration
    p64h_sysc_ddr_ss_cfg_t   ddr_ss_cfg;                              ///< DDR CTRL
    p64h_sysc_ddr_phy_cfg_t  ddr_phy_cfg[P64H_SYSC_DDR_INSTANCE_NUM]; ///< DDR PHY data config
} p64h_sysc_ddr_cfg_t;

/// DDR margining test configuration
typedef struct {
    uint32_t placeholder; ///< placeholder for DDR margining test configuration
} p64h_sysc_ddr_margin_cfg_t;

/// DDR margining test report
typedef struct {
    uint32_t placeholder; ///< placeholder for DDR margining test report
} p64h_sysc_ddr_margin_report_t;

// Identifies the ddr_intf, rank, lanes, and DQ bits that a training operation shall work on
typedef struct {
    uint32_t ddr_intf;
    uint32_t rank;
    bool     include_lanes[P64H_SYSC_DDR_PHY_LANE_NUM];
} ddr_ss_phy_training_loc_t;

#endif // P64H_SYSC_DDR_TYPE_H
/// @}
