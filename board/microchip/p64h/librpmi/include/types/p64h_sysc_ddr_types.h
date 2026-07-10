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
/// Training policy types for cold, warm and skip
typedef enum p64h_ddr_training_action_t {
    P64H_DDR_TRAINING_COLD = 0, ///< Perform training on this phase
    P64H_DDR_TRAINING_WARM,     ///< Use flashed config for this training phase
    P64H_DDR_TRAINING_SKIP      ///< Don't modify the PHY values associated with this training phase
} p64h_ddr_training_action_t;

/// DDR PHY pin types
typedef enum ddr_pin_type_t {
    DDRC_SHIM_UNMAPPED = 0, ///< Unused
    DDRC_SHIM_CA,           ///< CA
    DDRC_SHIM_CAMSR,        ///< CAMSR
    DDRC_SHIM_ALERT,        ///< Alert
    DDRC_SHIM_CK_N,         ///< Clock Complement
    DDRC_SHIM_CK,           ///< Clock True
    DDRC_SHIM_CS,           ///< Chip Select
    DDRC_SHIM_DM,           ///< DM
    DDRC_SHIM_DQ,           ///< DQ
    DDRC_SHIM_DQS,          ///< DQ Strobe
    DDRC_SHIM_DQS_N,        ///< DQ Complement
    DDRC_SHIM_NUM_PIN_TYPES ///< Max Pin Type Enum
} ddr_pin_type_t;

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

/// HSIO time 0 delay configs
typedef struct {
    uint8_t clk; ///< CLK TXS_DLY value at time0
    uint8_t ca;  ///< CA TXS_DLY value at time0
    uint8_t cs;  ///< CS TXS_DLY value at time0
} p64h_sysc_ddr_phy_initial_dly_cfg_t;

/// Training policy per interface
typedef struct {
    p64h_ddr_training_action_t ca;      ///< Action to be taken for control/address training
    p64h_ddr_training_action_t rdgt;    ///< Action to be taken for read gate training
    p64h_ddr_training_action_t rddbus;  ///< Action to be taken for read databus training
    p64h_ddr_training_action_t wrlvl;   ///< Action to be taken for write leveling training
    p64h_ddr_training_action_t wrdbus;  ///< Action to be taken for write databus training
    p64h_ddr_training_action_t rddbus2; ///< Action to be taken for the second phase of read databus training
} p64h_sysc_ddr_training_policy_t;

/// HSIO configs DDR PHY
typedef struct {
    uint8_t vrgen0;                             ///< HSIO banks vref value for all banks
    uint8_t odtstatic[DDRC_SHIM_NUM_PIN_TYPES]; ///< HSIO IOA termination odt config per pin type
    uint8_t odtsrc[DDRC_SHIM_NUM_PIN_TYPES];    ///< HSIO IOA termination odt source strength per pin type
    uint8_t drvsrc[DDRC_SHIM_NUM_PIN_TYPES];    ///< HSIO IOA termination drive source strength per pin type
    uint8_t drvsnk[DDRC_SHIM_NUM_PIN_TYPES];    ///< HSIO IOA termination drive sink strength per pin type
} p64h_sysc_ddr_phy_hsio_cfg_t;

/// Banks reference voltage and DRAM RTT configs
typedef struct {
    uint8_t vrefdq;   ///< dram vref
    uint8_t rtt_park; ///< dram rtt_part odt config
    uint8_t rtt_nom;  ///< dram rtt_nom odt config
    uint8_t rtt_rw;   ///< dram rtt_rw odt config
} p64h_sysc_ddr_phy_dram_cfg_t;

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
    p64h_sysc_ddr_training_policy_t     training_policy; ///< Dictates if we skip, cold / warm configure the PHY during each training phases
    p64h_sysc_ddr_phy_initial_dly_cfg_t initial_dly;     ///< HSIO initial tap delay (CLK, CA and CS)
    p64h_sysc_ddr_phy_hsio_cfg_t        hsio_cfg;        ///< HSIO config (Banks VRGEN and pins ODT/DRV)
    p64h_sysc_ddr_phy_dram_cfg_t        dram_cfg;        ///< DRAM parameters (RTT and VREFDQ)
    uint32_t                            tdfi_rddata_en;  ///< DDR controller TDFI_RDDATA_EN trained value
    uint32_t                            ca_sr_dly_txs;   ///< Common CA delay for control signals
    p64h_sysc_ddr_phy_dq_pin_cfg_t      dq_pin_cfg[P64H_SYSC_DDR_PHY_DQ_PINS]; ///< DQ pin configuration
    p64h_sysc_ddr_phy_lane_cfg_t        lane_cfg[P64H_SYSC_DDR_PHY_LANE_NUM];  ///< Lane configuration
    p64h_sysc_ddr_phy_debug_t           debug;
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

// Contains the control parameters for a DDR BIST operation
typedef struct {
    uint32_t ddr_intf;
    uint64_t start_addr;
    uint32_t addr_exp;
    uint32_t err_stop;
    uint32_t include_lanes;
} ddr_ss_bist_ctrl_info_t;

// Contains the control parameters for a DDR BIST operation for a single DQ bit
typedef struct {
    uint32_t ddr_intf;
    uint64_t start_addr;
    uint32_t addr_exp;
    uint32_t err_stop;
    uint32_t target_dq;
    bool     use_sso_pattern;
} ddr_ss_bist_dq_ctrl_info_t;

// Contains the result information for DDR CDNS BIST operation
typedef struct {
    bool     bist_result;
    uint64_t num_reads_completed;
    uint32_t num_errors;
    uint64_t bist_fail_addr;
    uint32_t bist_fail_expect_data[16];
    uint32_t bist_fail_actual_data[16];
} ddr_ss_bist_result_info_t;

// Contains the control parameters for a DDR Stress Test operation
typedef struct {
    uint32_t ddr_inst;
    uint64_t rank;
    uint32_t nxfer;
    uint32_t test_i;
    uint32_t read_only;
} ddr_ss_test_ctrl_info_t;

// Contains the result information for DDR Stress Test operation
typedef struct {
    bool     test_result;
    uint32_t num_errors;
    // TODO: count errors for each DQ?  each lane?
} ddr_ss_test_result_info_t;

// Contains the control parameters for a DDR Margining DQ Tx/Rx Sweep
typedef struct {
    uint32_t ddr_inst;
    uint32_t target_dq;
} ddr_dq_sweep_ctrl_t;

// Contains the result information for DDR Margining DQ Tx/Rx Sweep
typedef struct {
    uint32_t left_edge;
    uint32_t original;
    uint32_t right_edge;
} ddr_dq_sweep_result_t;

// DDR training test results - find optimal tdfi_rddata_en_f0
typedef struct {
    uint32_t tdfi_rddata_en; //< optimal tdfi_rddata_en_f0 value
} ddr_ss_phy_training_result_tdfi_rddata_en_t;

// DDR training test results - read gate sweep point
typedef struct {
    uint32_t steps180;    //< steps180 register value
    uint32_t sr_rdgt_dly; //< sr_rdgt_dly register value
} ddr_ss_phy_training_result_rdgt_sweep_point_t;

// DDR training test results - read gate sweep eye
typedef struct {
    ddr_ss_phy_training_result_rdgt_sweep_point_t start; //< first point of success for read gate
    ddr_ss_phy_training_result_rdgt_sweep_point_t end;   //< last point of success for read gate
} ddr_ss_phy_training_result_rdgt_sweep_eye_t;

// DDR training test results - read gate sweep results
typedef struct {
    ddr_ss_phy_training_result_rdgt_sweep_eye_t   eye[P64H_SYSC_DDR_PHY_LANE_NUM];    //< valid eye for read gate sweep
    ddr_ss_phy_training_result_rdgt_sweep_point_t center[P64H_SYSC_DDR_PHY_LANE_NUM]; //< calculated center for read gate sweep
} ddr_ss_phy_training_result_rdgt_sweep_t;

// DDR training test results - read data bus dq eye
typedef struct {
    uint32_t start; //< First sr_dly_rxs match
    uint32_t end;   //< First sr_dly_rxs no match - Chosen value before sweeping dqs
} ddr_ss_phy_training_result_rddbus_dq_eye_t;

// DDR training test results - read data bus dqs eye
typedef struct {
    uint32_t start; //< first sr_rx0_dly match
    uint32_t end;   //< //< first sr_rx0_dly no match
} ddr_ss_phy_training_result_rddbus_dqs_eye_t;

// DDR training test results - read data bus
typedef struct {
    ddr_ss_phy_training_result_rddbus_dq_eye_t  dq_eye[P64H_SYSC_DDR_PHY_DQ_PINS];      //< Range of valid dq sr_rxs_dly
    ddr_ss_phy_training_result_rddbus_dqs_eye_t dqs_eye[P64H_SYSC_DDR_PHY_LANE_NUM];    //< Range of valid dqs sr_rx0_dly
    uint32_t                                    dqs_center[P64H_SYSC_DDR_PHY_LANE_NUM]; //< Calculated center for dqs sr_rx0_dly value
} ddr_ss_phy_training_result_rddbus_t;

// DDR training test results - read data bus 2
typedef struct {
    ddr_ss_phy_training_result_rddbus_dq_eye_t  dq_eye[P64H_SYSC_DDR_PHY_DQ_PINS];      //< Range of valid dq sr_rxs_dly
    uint32_t                                    dq_center[P64H_SYSC_DDR_PHY_DQ_PINS];   //< Calculated center for dq sr_rxs_dly value
    ddr_ss_phy_training_result_rddbus_dqs_eye_t dqs_eye[P64H_SYSC_DDR_PHY_LANE_NUM];    //< Range of valid dqs sr_rx0_dly
    uint32_t                                    dqs_center[P64H_SYSC_DDR_PHY_LANE_NUM]; //< Calculated center for dqs sr_rx0_dly value
} ddr_ss_phy_training_result_rddbus2_t;

// DDR training test results - write leveling eye
typedef struct {
    uint32_t start; //< sr_dly_txs found while hunting for 0s
    uint32_t end;   //< sr_dly_txs found while hunting for 1s
} ddr_ss_phy_training_result_wrlvl_eye_t;

// DDR training test results - write leveling
typedef struct {
    ddr_ss_phy_training_result_wrlvl_eye_t eye[P64H_SYSC_DDR_PHY_LANE_NUM]; //< Range of valid delays for sr_dly_txs on dqs
} ddr_ss_phy_training_result_wrlvl_t;

// DDR training test results - write data bus sweep point
typedef struct {
    uint32_t pipedly;    //< pipedelay register value
    uint32_t sr_dly_txs; //< sr_dly_txs register value
} ddr_ss_phy_training_result_wrdbus_point_t;

// DDR training test results - write data bus eye
typedef struct {
    ddr_ss_phy_training_result_wrdbus_point_t start; //< first valid delay point
    ddr_ss_phy_training_result_wrdbus_point_t end;   //< last valid delay point
} ddr_ss_phy_training_result_wrdbus_eye_t;

// DDR training test results - write data bus
typedef struct {
    ddr_ss_phy_training_result_wrdbus_eye_t   eye[P64H_SYSC_DDR_PHY_LANE_NUM];    //< window of valid delays
    ddr_ss_phy_training_result_wrdbus_point_t center[P64H_SYSC_DDR_PHY_LANE_NUM]; //< Calculated center for write databus delays
} ddr_ss_phy_training_result_wrdbus_t;

// DDR training test results - full training report per interface
typedef struct {
    ddr_ss_phy_training_result_tdfi_rddata_en_t find_tdfi_rddata_en; //< find optimal TDFI_RDDATA_EN_F0 result
    ddr_ss_phy_training_result_rdgt_sweep_t     rdgt_sweep;          //< read gate sweep result
    ddr_ss_phy_training_result_rddbus_t         rddbus;              //< read data bus result
    ddr_ss_phy_training_result_wrlvl_t          wrlvl;               //< write leveling result
    ddr_ss_phy_training_result_wrdbus_t         wrdbus;              //< write data bus result
    ddr_ss_phy_training_result_rddbus2_t        rddbus2;             //< read data bus 2 (phase5) result
} ddr_ss_phy_training_result_per_intf_t;

// DDR training test results - full report
typedef struct {
    ddr_ss_phy_training_result_per_intf_t intf[P64H_SYSC_DDR_INSTANCE_NUM]; //< full training report per interface
} ddr_ss_phy_training_result_t;

#endif // P64H_SYSC_DDR_TYPE_H
/// @}
