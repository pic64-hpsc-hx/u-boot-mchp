/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_system_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_SYSTEM_TYPES_H
#define P64H_SYSC_SYSTEM_TYPES_H

#include "p64h_sysc_common_types.h"
#include <ba/p64h_sysc_shared_ba.h>
#include <ba/p64h_sysc_sysc_ba.h>
#include <generated/p64h_sysc_pgmrclk_defs.h>
#include <zsbl/sec_api_types.h>
#include <zsbl/sec_smb_types.h>
#include <zsbl/scratchreg.h>
#include <zsbl/boot_cfg_helper.h>
#include <p64h_sysc_math.h>

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_CFM_CH_NUM 8u         ///< define the maximum number of channels in the CFM
#define P64H_SYSC_LOG_MAGIC  0xDEADBEEF ///< magic number to identify a stringless entry in the log buffer
///< Number of mask SYSC Log ID
#define P64H_SYSC_LOG_ID_MASK_NUM DIV_ROUND_UP(P64H_SYSC_LOG_ID_LAST, 8 * sizeof(uint64_t))

/* Public Structs and Enums --------------------------------------- */

// TODO: this is not specific to a boot cfg right? there's just one?

// P64H_SYSC_DUMP_COMP_OTP_BOOT_CFG      = ONE_HOT(0), ///< OTP boot configuration component

/// Enum for sysc cfg dump component selection
typedef enum {
    P64H_SYSC_SYSC_CFG_DUMP_COMP_FLASH_HDR = 0U,    ///< Dump whole sysc config - will ignore individual selection of artifacts below
    P64H_SYSC_SYSC_CFG_DUMP_COMP_FSBL,              ///< SysC FSBL
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG0,              ///< SysC cfg0
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_SYSC_SOC_CFG, ///< System-on-Chip configuration
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_DDR_CFG,      ///< DDR configuration
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_SW_SVC_CFG,   ///< Software service configuration
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_ACOT,         ///< AppC Images Offset Table
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_ENET_SW_CFG,  ///< Ethernet switch configuration
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_KEYS_CFG,     ///< Keys config
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_PQ_FW,        ///< PQ firmware
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_APPC_ZSBL,    ///< AppC ZSBL
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG1_APPC_RNMI,    ///< AppC RNMI
    P64H_SYSC_SYSC_CFG_DUMP_COMP_CFG2,              ///< SysC cfg2
    P64H_SYSC_SYSC_CFG_DUMP_COMP_SECC_FW,           ///< SecC fw
    P64H_SYSC_SYSC_CFG_DUMP_COMP_LAST
} p64h_sysc_sysc_cfg_dump_comp_t;

/// Enum for appc cfg dump component selection
typedef enum {
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_CFG = 0U,        ///< Dump whole appc config - will ignore individual selection of artifacts below
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_APPC_BOOTSCRIPT, ///< Appc bootscript
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_APPC_STATIC_CFG, ///< Appc static config
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_SW_SV_CFG,       ///< Appc bootcfg software service configuration
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P0_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P0_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P1_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P1_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P2_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P2_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P3_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P3_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P4_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P4_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P5_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P5_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P6_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P6_APPC_CFG,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P7_APPC_DTB,
    P64H_SYSC_APPC_CFG_DUMP_COMP_BOOTCFG_P7_APPC_CFG,
} p64h_sysc_appc_cfg_dump_comp_t;

/// system event identifier
typedef enum {
    P64H_SYSC_SYS_EVT_ID_LOG = 1,              ///< log availability event
    P64H_SYSC_SYS_EVT_ID_APPC_BOOT_CFG_UPDATE, ///< appc boot configuration update completed
    P64H_SYSC_SYS_EVT_ID_POWER_UPDATE,         ///< power update events
    P64H_SYSC_SYS_EVT_ID_FW_UPDATE             ///< firmware update events
} p64h_sysc_sys_evt_id_t;

/// bitset of formatting and locking flags per destination
typedef enum {
    P64H_SYSC_LOG_NO_FLAGS             = 0,  ///< no special flags
    P64H_SYSC_LOG_FORMAT_WITH_MODULE   = 1,  ///< prefix printf messages with module name
    P64H_SYSC_LOG_FORMAT_WITH_SEVERITY = 2,  ///< prefix printf messages with severity
    P64H_SYSC_LOG_FORMAT_WITH_HART     = 4,  ///< prefix printf messages with hartid
    P64H_SYSC_LOG_FORMAT_WITH_MTIME    = 8,  ///< prefix printf messages with mtime
    P64H_SYSC_LOG_FORMAT_WITH_TOD      = 16, ///< prefix printf messages with time of day
    P64H_SYSC_LOG_USE_SPINLOCK         = 32, ///< use a multi-core spin for all messages
    P64H_SYSC_LOG_USE_MUTEX            = 64, ///< use an operating system mutex for all messages
} p64h_sysc_log_flags_t;

/**
 * @brief
 *   log levels - note: we could change these to bit sets,
 *       and use log levels as another way of filtering.
 */
typedef enum {
    P64H_SYSC_LOG_LEVEL_DISABLED = 0u, //!< used to disable logging to a destination.
    P64H_SYSC_LOG_LEVEL_CRITICAL = 1u, //!< used for assert messages.
    P64H_SYSC_LOG_LEVEL_ERROR    = 2u, //!< error messages.
    P64H_SYSC_LOG_LEVEL_WARN     = 3u, //!< warning messages.
    P64H_SYSC_LOG_LEVEL_INFO     = 4u, //!< informational messages.
    P64H_SYSC_LOG_LEVEL_DEBUG    = 5u, //!< debug messages.
} p64h_sysc_log_level_t;

/// logger destination
typedef enum {
    P64H_SYSC_LOG_TO_STDOUT = 0u, ///< log to stdout
    P64H_SYSC_LOG_TO_TRACE  = 1u, ///< log to trace encoder
    P64H_SYSC_LOG_RSRV0     = 2u, ///< reserved
    P64H_SYSC_LOG_TO_UART   = 3u, ///< log to uart
    P64H_SYSC_LOG_TO_BUFFER = 4u, ///< log to local buffer
} p64h_sysc_log_destination_t;

/// enumerate appc boot configuration
typedef enum {
    P64H_SYSC_APPC_BOOT_CFG_0 = 0u, ///< appc boot configuration 0
    P64H_SYSC_APPC_BOOT_CFG_1,      ///< appc boot configuration 1
    P64H_SYSC_APPC_BOOT_CFG_2,      ///< appc boot configuration 2
    P64H_SYSC_APPC_BOOT_CFG_3,      ///< appc boot configuration 3
    P64H_SYSC_APPC_BOOT_CFG_4,      ///< appc boot configuration 4
    P64H_SYSC_APPC_BOOT_CFG_5,      ///< appc boot configuration 5
    P64H_SYSC_APPC_BOOT_CFG_6,      ///< appc boot configuration 6
    P64H_SYSC_APPC_BOOT_CFG_7,      ///< appc boot configuration 7
    P64H_SYSC_APPC_BOOT_CFG_8,      ///< appc boot configuration 8
    P64H_SYSC_APPC_BOOT_CFG_9,      ///< appc boot configuration 9
    P64H_SYSC_APPC_BOOT_CFG_10,     ///< appc boot configuration 10
    P64H_SYSC_APPC_BOOT_CFG_11,     ///< appc boot configuration 11
    P64H_SYSC_APPC_BOOT_CFG_12,     ///< appc boot configuration 12
    P64H_SYSC_APPC_BOOT_CFG_13,     ///< appc boot configuration 13
    P64H_SYSC_APPC_BOOT_CFG_14,     ///< appc boot configuration 14
    P64H_SYSC_APPC_BOOT_CFG_15,     ///< appc boot configuration 15
    P64H_SYSC_APPC_BOOT_CFG_LAST
} p64h_sysc_boot_cfg_id_t;

/// system event
typedef struct {
    p64h_sysc_sys_evt_id_t eid; ///< event identifier
} p64h_sysc_sys_evt_t;

/// This struct defines system version
typedef struct {
    uint32_t major; ///< sysc major version
    uint32_t minor; ///< sysc minor version
    uint32_t patch; ///< sysc patch version
} p64h_sysc_sys_version_t;

/// Data related to the OS error
typedef struct {
    uint32_t src;  ///< OS error source ID
    uint32_t code; ///< OS error code
    uint64_t addr; ///< Address reported with OS error (optional)
} p64h_sysc_os_err_t;

/// Information on the reset request reason
typedef struct {
    uint32_t fw_err_valid : 1;  ///< fw_err + comp are valid
    uint32_t hw_err_valid : 1;  ///< hw_err is valid
    uint32_t os_err_valid : 1;  ///< os_err is valid
    uint32_t fill         : 29; ///< padding bits
} p64h_sysc_fsbl_rst_req_ctxt_t;

/// Content of a reset request containing information on the reason for reset
typedef struct {
    p64h_sysc_fsbl_rst_req_ctxt_t rst_req_ctxt; ///< Context of reset request
    p64h_err_t                    fw_err;       ///< FW error reported
    p64h_comp_t                   comp;         ///< Component reporting FW error
    p64h_sysc_ras_error_code_t    hw_err;       ///< HW error reported
    p64h_sysc_os_err_t            os_err;       ///< OS error reported
} p64h_sysc_fsbl_rst_req_t;

/// FSBL boot context bit description
typedef struct {
    uint32_t clk_rampup           : 1;  ///< Clock ramp-up was acheived
    uint32_t blob_fetch           : 1;  ///< CFG1 BLOB was fetched from SysC image
    uint32_t sys_health_chk       : 1;  ///< SysC health check executed
    uint32_t com_active           : 1;  ///< External communication is brought up
    uint32_t full_nvm_intf_active : 1;  ///< Opened full NVM interface
    uint32_t phase_1              : 1;  ///< Phase 1 successfully passed
    uint32_t svc_start            : 1;  ///< Started all required services
    uint32_t app_health_chk       : 1;  ///< AppC health check executed
    uint32_t safe_mode            : 1;  ///< Safe mode engaged
    uint32_t fill                 : 21; ///< Padding bits
} p64h_sysc_fsbl_boot_ctxt_bits_t;

/// FSBL boot context for the current boot
typedef union {
    uint32_t                        w; ///< Word accessor
    p64h_sysc_fsbl_boot_ctxt_bits_t b; ///< Bitfield accessor
} p64h_sysc_fsbl_boot_ctxt_t;

/**
 * @brief M1 dump data contents
 */
typedef struct {
    scratchpad_boot_mode_t       boot_mode;      ///< Sticky register for boot control
    scratchpad_boot_ctxt_t       boot_ctxt;      ///< Sticky register capturing the history of boot sequences across multiple boots/reboots
    uint32_t                     boot_cnt;       ///< boot counter (16 bits counter)
    sysc_scratchreg_exc_sticky_t exc_handler;    ///< exception handler context
    p64h_sysc_fsbl_rst_req_t     fsbl_rst_req;   ///< FSBL reset request sticky data
    p64h_sysc_fsbl_boot_ctxt_t   fsbl_boot_info; ///< FSBL boot info including reset request and boot context
} p64h_sysc_m1_dump_t;

/// This struct defines system information
typedef struct {
    p64h_sysc_dev_cfg_node_t dev_cfg;            ///< dev_cfg dtb node used to boot sysc firmware
    p64h_sysc_sys_version_t  fw_version;         ///< sysc firmware version
    tvs_mon_stat_t           tvs_mon_data;       ///< Temperature and Voltage Sensor readout
    uint64_t                 dsn[DSN_DWORD_LEN]; ///< Device Serial number
    uint32_t                 mac_oui;            ///< MAC addr Organizationally Unique Identifier
    uint32_t                 mac_base;           ///< Starting MAC addr
    uint32_t                 num_mac;            ///< Total MAC addresses
    uint16_t                 pcie_device_id;     ///< PCIe Device ID
    uint16_t                 pcie_vendor_id;     ///< PCIe Vendor ID
    uint32_t                 core_frequency;     ///< core frequency
    uint32_t                 time_frequency;     ///< time frequency
    uint32_t                 img_id;             ///< image id
    otp_image_table_entry_t  img_entry;          ///< image entry
    p64h_sysc_m1_dump_t      m1_dump;            ///< M1 scratchpad register dump
} p64h_sysc_sys_info_t;

/// logger information
typedef struct {
    uint64_t id_mask[P64H_SYSC_LOG_ID_MASK_NUM]; ///< logger id mask
    uint64_t dest_mask;                          ///< logger destination mask
} p64h_sysc_sys_log_info_t;

/// logger configuration
typedef struct {
    p64h_sysc_log_level_t       level; ///< logger level
    p64h_sysc_log_destination_t dest;  ///< logger destination
    p64h_sysc_log_flags_t       flags; ///< logger flags
} p64h_sysc_sys_log_cfg_t;

/*
 * log data fetch request for the system command: P64H_SYS_GET_LOG_DATA
 */
typedef struct {
    uint64_t requested_read_offset; ///< fetch log from specified offset (or first available offset)
    uint32_t data_buffer_size;      ///< size of data buffer (maximum response size)
} p64h_sysc_sys_log_data_req_t;

/**
 * log data fetch response for the system command: P64H_SYS_GET_LOG_DATA
 *
 * data in response reflects offset from [resp_offset..resp_offset+bytes_read-1]
 * if current_write_offset > resp_offset+bytes_read then there is more data available to be read.
 */
typedef struct {
    uint64_t resp_offset;          ///< response offset (offset of data[0])
    uint64_t current_write_offset; ///< currnet write offset (possible more than resp_offset+bytes_read)
    uint32_t bytes_read;           ///< number of bytes returned in 'data'
    /* note: data follows the response header */
} p64h_sysc_sys_log_data_resp_header_t;

/** currently no api to retrieve a header structure plus variable response buffer,
so temporarily creating a contiguous response buffer and doing an extra copy. */
typedef struct {
    p64h_sysc_sys_log_data_resp_header_t header;
    uint8_t*                             data;
} p64h_sysc_sys_log_data_resp_t;

// payload data in a stringless log entry
typedef struct {
    uint64_t code;      ///< error code defined in enum p64h_err_t
    uint64_t timestamp; ///< A 64-bit timestamp
    uint64_t arg0;      ///< 64-bit log word 0
    uint64_t arg1;      ///< 64-bit log word 1
    uint64_t arg2;      ///< 64-bit log word 2
    uint64_t arg3;      ///< 64-bit log word 3
} p64h_sysc_log_payload_t;

// header for a stringless log entry
typedef struct {
    uint64_t magic; ///< 64-bit magic number to marker a stringless log entry
} p64h_sysc_log_hdr_t;

// stringless log entry
typedef struct {
    p64h_sysc_log_hdr_t     hdr;     ///< header
    p64h_sysc_log_payload_t payload; ///< payload
} p64h_sysc_log_entry_t;

/// appc boot configuration status
typedef struct {
    p64h_sysc_boot_cfg_id_t    boot_cfg_id;                                 ///< Active AppC boot configuration ID
    p64h_sysc_appc_cfg_state_t static_cfg;                                  ///< state of appc static cfg
    p64h_sysc_appc_cfg_state_t partition[P64H_SYSC_APPC_CFG_PARTITION_MAX]; ///< state of appc cfg partition
} p64h_sysc_appc_boot_cfg_status_t;

/// device trace attributes
typedef struct {
    bool                   dev_trace_mem_sink_available; ///< True if trace can be sent to system memory
    bool                   dev_trace_hti_sink_available; ///< True if trace can be sent to serdes
    p64h_sysc_trace_dest_t sink_selected;                ///< Currently selected sink
} p64h_sysc_trace_dev_attr_t;

/// Package data configuration
typedef struct {
    bool is_compressed; ///< Indicates if package compression is enabled (true: compressed, false: not compressed)
    bool is_encrypted;  ///< Indicates if package encryption is enabled (true: encrypted, false: not encrypted)
} p64h_sysc_fw_pkg_data_cfg_t;

/// Package configuration
typedef struct {
    p64h_sysc_fw_pkg_data_cfg_t pkg_data_cfg; ///< Package data config
    uint64_t                    pkg_size;     ///< The length of the pkg sent over rpmi.
    uint64_t uncompressed_pkg_size; ///< The length of the decompressed fw upgrade package. (equal to pkg_size if fw_pkg_cfg.compress == false)
} p64h_sysc_fw_pkg_cfg_t;

/// firmware dump config (user request)
typedef struct {
    uint16_t sysc_cfg_artifact_msk[P64H_SYSC_SYSC_BOOT_CFG_MAX]; ///< mask (p64h_sysc_sysc_cfg_dump_comp_t) specifying what to dump from each sysc cfg
    uint32_t appc_cfg_artifact_msk[P64H_SYSC_NUM_APPC_HW_PROF];  ///< mask (p64h_sysc_appc_cfg_dump_comp_t) specifying what to dump from each appc cfg
    uint32_t appc_cfg_binaries_msk[P64H_SYSC_NUM_APPC_HW_PROF];  ///< mask specifying what appc binaries to dump from each appc cfg. appc binary 0 as
                                                                 ///< the least significant bit, etc.
    uint64_t                    nth_request;
    p64h_sysc_fw_pkg_data_cfg_t fw_pkg_data_cfg; ///< Package data configuration options (unused, TODO: used for compressed or encrypted response)
} p64h_sysc_fw_dump_cfg_t;

/// firmware dump package (response with data)
typedef struct {
    uint16_t sysc_cfg_artifact_msk[P64H_SYSC_SYSC_BOOT_CFG_MAX]; ///< mask (p64h_sysc_sysc_cfg_dump_comp_t) specifying what to dump from each sysc cfg
    uint32_t appc_cfg_artifact_msk[P64H_SYSC_NUM_APPC_HW_PROF];  ///< mask (p64h_sysc_appc_cfg_dump_comp_t) specifying what to dump from each appc cfg
    uint32_t appc_cfg_binaries_msk[P64H_SYSC_NUM_APPC_HW_PROF];  ///< mask specifying what appc binaries to dump from each appc cfg. appc binary 0 as
    uint64_t nth_download;
    bool     last_download;
    uint64_t download_size;
    uint8_t  dump_data[0] __attribute__((aligned(8))); ///< single or partial instance of p64h_sysc_fw_dump_comp_info_t, corresponding to the bit set
                                                       ///< to one in the masks. followed by the contents of the dump components
} p64h_sysc_fw_dump_pkg_t;

// Firmware dump status
typedef struct {
    uint64_t size;      ///< size of firmware dump to receive
    bool     completed; ///< completion flag of firmware dump
} p64h_sysc_fw_dump_status_t;

// Firmware time
typedef struct {
    uint32_t year;   ///< year A.D
    uint32_t month;  ///< month of the year with values from 1 to 12
    uint32_t day;    ///< day of the month with values from 1 to 31
    uint32_t hour;   ///< hour of the day with values from 0 to 23
    uint32_t minute; ///< minute of the hour with values from 0 to 59
    uint32_t second; ///< second of the minute with values from 0 to 59
    uint32_t ticks;  ///< clock tick of the second starts from 0
} p64h_sysc_time_t;

/**
 * @brief
 *  Structure contains information for PGMRCLK configuration
 */
typedef struct p64h_pgmrclk_cfg_t {
    p64h_sysc_pgmrclk_sel_t clk_sel;         ///< clock select
    float                   input_clk_freq;  ///< source clock frequency
    float                   output_clk_freq; ///< output clock desired frequency
} p64h_pgmrclk_cfg_t;

/**
 * @brief
 *   Structure defining CFM divider configurations.
 */
typedef struct {
    p64h_sysc_cfm_meas_mode_t meas_mode[P64H_SYSC_CFM_CH_NUM]; ///< Measurement modes, per channel
    p64h_sysc_cfm_ref_sel_t   ref_sel;                         ///< CFM Clock Measurement Reference
    bool auto_mode[P64H_SYSC_CFM_CH_NUM]; ///< Frequency Measurement mode - Auto-Range Detection: Monitors measurements are within expected range, per
                                          ///< channel
    bool     continuous_mode;             ///< Frequency Measurement mode - Continuous Mode: Ongoing, repeated measurements
    bool     time_en;                     ///< Time enable, only applicable for Time Measurement mode. No impact on other channel modes.
    uint32_t ref_count;                   ///< Reference count for frequency and time measurement modes
    uint32_t threshold_low[P64H_SYSC_CFM_CH_NUM];  ///< The low limit value for auto mode, per channel
    uint32_t threshold_high[P64H_SYSC_CFM_CH_NUM]; ///< The high limit value for auto mode, per channel
    bool     start;                                ///< Start or stop measurement
} p64h_sysc_cfm_cfg_t;

/**
 * @brief
 *   Structure defining CFM divider measurement count.
 */
typedef struct {
    uint32_t cfm_busy;
    uint32_t refcount;
    uint32_t count[P64H_SYSC_CFM_MEAS_SEL_GENERIC_LAST]; ///< measurement count for all channels
} p64h_sysc_cfm_meas_count_t;

/// function pointer type for SYSTEM event notification
typedef void (*p64h_sysc_sys_evt_fct_t)(const p64h_sysc_sys_evt_t* sys_evt_ptr);

typedef enum {
    P64H_FW_PLL_C_REFCLK   = 0x0, ///< FW PLL Support Clocks, Master (Complementary), Refclk
    P64H_FW_PLL_C_PGMRCLK  = 0x1, ///< FW PLL Support Clocks, Master (Complementary), Pgmrclk[3]
    P64H_FW_PLL_C_WDOG_CLK = 0x2, ///< FW PLL Support Clocks, Master (Complementary), WDOG clock
    P64H_FW_PLL_C_PCIE_CLK = 0x3, ///< FW PLL Support Clocks, Master (Complementary), PCIE clock
    P64H_FW_PLL_C_LAST            ///< Invalid, Used for error checking
} p64h_sysc_fw_pll_c_clock_t;

typedef enum {
    P64H_FW_PLL_R_WDOG_CLK = 0x0, ///< FW PLL Support Clocks, Test (Reference), WDOG clock
    P64H_FW_PLL_R_PCIE_CLK = 0x1, ///< FW PLL Support Clocks, Test (Reference), PCIE clock
    P64H_FW_PLL_R_REFCLK   = 0x2, ///< FW PLL Support Clocks, Test (Reference), Refclk
    P64H_FW_PLL_R_PGMRCLK  = 0x3, ///< FW PLL Support Clocks, Test (Reference), Pgmrclk[3]
    P64H_FW_PLL_R_LAST            ///< Invalid, Used for error checking
} p64h_sysc_fw_pll_r_clock_t;

typedef struct {
    uint64_t test_timestamp;
    uint64_t master_timestamp;
    uint64_t master_timestamp2;
    uint64_t measurement_count;
} p64h_sysc_fw_pll_timestamp_t;

typedef struct {
    p64h_sysc_fw_pll_c_clock_t master_clk; ///< Set the Master (compared) Clock for the measurement
    p64h_sysc_fw_pll_r_clock_t test_clk;   ///< Set the Test (test) Clock for the measurement
    uint64_t                   master_val; ///< 40-bit value, sets the amount of cycles for the measurement
    uint64_t                   test_val;   ///< 40-bit value, sets the starting value for the reference counter
    uint64_t                   wdog_val;   ///< 40-bit value, sets the watchdog timeout value for the compared clock
} p64h_sysc_fw_pll_cfg_t;

/// PTP Time-of-Day value, IEEE-1588 timecode layout
typedef struct {
    uint32_t sec_hi;    ///< integer seconds, upper 16 bits (48-bit seconds total)
    uint32_t sec_lo;    ///< integer seconds, lower 32 bits
    uint32_t nsec;      ///< integer nanoseconds (0..999,999,999)
    uint32_t frac_nsec; ///< fractional nanoseconds in 1/16 ns units (valid range 0..15)
} p64h_sysc_tod_t;

typedef enum {
    P64H_SYSC_TMON_INST_R = 0x0, ///< Temperature monitor instance (right)
    P64H_SYSC_TMON_INST_L = 0x1, ///< Temperature monitor instance (left)
    P64H_SYSC_TMON_INST_LAST
} p64h_sysc_tmon_inst_t;

typedef struct {
    uint16_t threshold_low;
    uint16_t threshold_high;
} p64h_sysc_tmon_threshold_t;

typedef struct {
    uint16_t tvs_val_vdd;   ///< Converted value for channel 0 VDD.
    uint16_t tvs_val_vdd18; ///< Converted value for channel 1 VDD18.
    uint16_t tvs_val_adc;   ///< Converted value for channel 2 ADC.
    uint16_t tvs_val_temp;  ///< Converted value for channel 3 Temperature.
    uint8_t  chvalid;       ///< Indicates which measured value is valid
} top_tvs_mon_stat_t;

#endif // P64H_SYSC_SYSTEM_TYPES_H
/// @}
