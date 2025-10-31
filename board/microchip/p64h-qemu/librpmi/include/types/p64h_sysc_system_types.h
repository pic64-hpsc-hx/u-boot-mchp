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

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_CFM_CH_NUM        8u ///< define the maximum number of channels in the CFM
#define SYS_TRACE_NUM_CROSS_TRIGGER 78 ///< Number of cross trigger matrix instances

/* Public Structs and Enums --------------------------------------- */

/// Enum for firmware dump component selection
typedef enum {
    P64H_SYSC_DUMP_COMP_OTP_BOOT_CFG      = ONE_HOT(0), ///< OTP boot configuration component
    P64H_SYSC_DUMP_COMP_SYSC_IMG          = ONE_HOT(1), ///< System controller image component
    P64H_SYSC_DUMP_COMP_SYSC_FS_SYSC      = ONE_HOT(2), ///< System controller file system (SYSC) component
    P64H_SYSC_DUMP_COMP_SYSC_FS_BOOTCFG   = ONE_HOT(3), ///< System controller file system (boot configuration) component
    P64H_SYSC_DUMP_COMP_SYSC_FS_APPC      = ONE_HOT(4), ///< System controller file system (APPC) component
    P64H_SYSC_DUMP_COMP_SYSC_FS_SYSC_DATA = ONE_HOT(5)  ///< System controller file system (SYSC data) component
} p64h_sysc_fw_dump_comp_t;

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
} p64h_sysc_boot_cfg_id_t;

/* ---------------------------------------------------------------*/
//  ### Stuct and Enums for Device Level Trace configuration such as Trace Sok Funnel Destination ###
/* ---------------------------------------------------------------*/

/**
 * Enum for defining trace data source
 */

typedef enum {
    P64H_SYSC_TRACE_SRC_SYSC      = ONE_HOT(0), ///< Trace data is coming from System Controller ATB funnel
    P64H_SYSC_TRACE_SRC_APPC_0    = ONE_HOT(1), ///< Trace data is coming from app cluster 0 ATB funnel
    P64H_SYSC_TRACE_SRC_APPC_1    = ONE_HOT(2), ///< Trace data is coming from app cluster 1 ATB funnel
    P64H_SYSC_TRACE_SRC_SYS_NOC   = ONE_HOT(3), ///< Trace data is coming from SYS_NOC
    P64H_SYSC_TRACE_SRC_APP_NOC   = ONE_HOT(4), ///< Trace data is coming from APP_NOC
    P64H_SYSC_TRACE_SRC_DDR_NOC   = ONE_HOT(5), ///< Trace data is coming from DDR_NOC
    P64H_SYSC_TRACE_SRC_ALL_NOCS  = 0b111000,   ///< Trace data is coming from all NOC
    P64H_SYSC_TRACE_SRC_APPC_SYSC = 0b000111,   ///< Trace data is coming from both appc and sysc
    P64H_SYSC_TRACE_SRC_ALL       = 0b111111    ///< Trace data is coming from all available sources

} p64h_sysc_trace_src_t;

/**
 * Enum for selecting the trace system timestamp source
 */
typedef enum {
    P64H_SYSC_TRACE_TIMESTAMP_SRC_INTERNAL = 0, ///< use internal timestamper
    P64H_SYSC_TRACE_TIMESTAMP_SRC_SYSC_TS       ///< use sysc elapsed timer
} p64h_sysc_trace_timestamp_src_t;

/**
 * Enum to define cross trigger matrix source 0
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_0               = ONE_HOT(0),  ///< Cluster 0 Core 0
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_1               = ONE_HOT(1),  ///< Cluster 0 Core 1
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_2               = ONE_HOT(2),  ///< Cluster 0 Core 2
    P64H_SYSC_TRACE_XTRG_CLUSTER_0_HART_3               = ONE_HOT(3),  ///< Cluster 0 Core 3
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_0               = ONE_HOT(4),  ///< Cluster 1 Core 0
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_1               = ONE_HOT(5),  ///< Cluster 1 Core 1
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_2               = ONE_HOT(6),  ///< Cluster 1 Core 2
    P64H_SYSC_TRACE_XTRG_CLUSTER_1_HART_3               = ONE_HOT(7),  ///< Cluster 1 Core 3
    P64H_SYSC_TRACE_XTRG_S7_SYS_CTRL_TRIG_0             = ONE_HOT(8),  ///< S7 Sys Ctrl
    P64H_SYSC_TRACE_XTRG_S7_SYS_CTRL_TRIG_1             = ONE_HOT(9),  ///< S7 Sys Ctrl
    P64H_SYSC_TRACE_XTRG_DDR_NOC_LATENCY_TRIG_0         = ONE_HOT(10), ///< DDR NOC Latency
    P64H_SYSC_TRACE_XTRG_DDR_NOC_LATENCY_TRIG_1         = ONE_HOT(11), ///< DDR NOC Latency
    P64H_SYSC_TRACE_XTRG_DDR_NOC_PACKET_0_TRIG_0        = ONE_HOT(12), ///< DDR NOC Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_PACKET_0_TRIG_1        = ONE_HOT(13), ///< DDR NOC Packet 0
    P64H_SYSC_TRACE_XTRG_DDR_NOC_PACKET_1_TRIG_0        = ONE_HOT(14), ///< DDR NOC Packet 1
    P64H_SYSC_TRACE_XTRG_DDR_NOC_PACKET_1_TRIG_1        = ONE_HOT(15), ///< DDR NOC Packet 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_1_TRIG_0         = ONE_HOT(16), ///< SYS NOC Probe 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_1_TRIG_1         = ONE_HOT(17), ///< SYS NOC Probe 1
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_2_TRIG_0         = ONE_HOT(18), ///< SYS NOC Probe 2
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_2_TRIG_1         = ONE_HOT(19), ///< SYS NOC Probe 2
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_3_TRIG_0         = ONE_HOT(20), ///< SYS NOC Probe 3
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_3_TRIG_1         = ONE_HOT(21), ///< SYS NOC Probe 3
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_4_TRIG_0         = ONE_HOT(22), ///< SYS NOC Probe 4
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_4_TRIG_1         = ONE_HOT(23), ///< SYS NOC Probe 4
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_5_TRIG_0         = ONE_HOT(24), ///< SYS NOC Probe 5
    P64H_SYSC_TRACE_XTRG_SYS_NOC_PROBE_5_TRIG_1         = ONE_HOT(25), ///< SYS NOC Probe 5
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_0_TRIG_0       = ONE_HOT(26), ///< APP NOC Pkt CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_0_TRIG_1       = ONE_HOT(27), ///< APP NOC Pkt CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_1_TRIG_0       = ONE_HOT(28), ///< APP NOC Pkt CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_CPU_1_TRIG_1       = ONE_HOT(29), ///< APP NOC Pkt CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_DDR_ENCRYPT_TRIG_0 = ONE_HOT(30), ///< APP NOC Pkt DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_DDR_ENCRYPT_TRIG_1 = ONE_HOT(31)  ///< APP NOC Pkt DDR ENCRYPT
} p64h_sysc_trace_cross_trigger_out_select_0_t;

/**
 * Enum to define cross trigger matrix source 1
 *
 *
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_EP_TRIG_0       = ONE_HOT(0),  ///< APP NOC Pkt ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_EP_TRIG_1       = ONE_HOT(1),  ///< APP NOC Pkt ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_SWR_TRIG_0      = ONE_HOT(2),  ///< APP NOC Pkt ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_ENET_SWR_TRIG_1      = ONE_HOT(3),  ///< APP NOC Pkt ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_IOMMU_TRIG_0         = ONE_HOT(4),  ///< APP NOC Pkt IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_IOMMU_TRIG_1         = ONE_HOT(5),  ///< APP NOC Pkt IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M2_TRIG_0            = ONE_HOT(6),  ///< APP NOC Pkt M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M2_TRIG_1            = ONE_HOT(7),  ///< APP NOC Pkt M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M3_TRIG_0            = ONE_HOT(8),  ///< APP NOC Pkt M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_M3_TRIG_1            = ONE_HOT(9),  ///< APP NOC Pkt M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_NVM_TRIG_0           = ONE_HOT(10), ///< APP NOC Pkt NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_NVM_TRIG_1           = ONE_HOT(11), ///< APP NOC Pkt NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_0_TRIG_0        = ONE_HOT(12), ///< APP NOC Pkt PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_0_TRIG_1        = ONE_HOT(13), ///< APP NOC Pkt PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_1_TRIG_0        = ONE_HOT(14), ///< APP NOC Pkt PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_PCIE_1_TRIG_1        = ONE_HOT(15), ///< APP NOC Pkt PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_SYS_NOC_TRIG_0       = ONE_HOT(16), ///< APP NOC Pkt SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_SYS_NOC_TRIG_1       = ONE_HOT(17), ///< APP NOC Pkt SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_USER_CRYPTO_TRIG_0   = ONE_HOT(18), ///< APP NOC Pkt USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_PKT_USER_CRYPTO_TRIG_1   = ONE_HOT(19), ///< APP NOC Pkt USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_0_TRIG_0       = ONE_HOT(20), ///< APP NOC Trans CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_0_TRIG_1       = ONE_HOT(21), ///< APP NOC Trans CPU 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_1_TRIG_0       = ONE_HOT(22), ///< APP NOC Trans CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_CPU_1_TRIG_1       = ONE_HOT(23), ///< APP NOC Trans CPU 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_DDR_ENCRYPT_TRIG_0 = ONE_HOT(24), ///< APP NOC Trans DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_DDR_ENCRYPT_TRIG_1 = ONE_HOT(25), ///< APP NOC Trans DDR ENCRYPT
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_EP_TRIG_0     = ONE_HOT(26), ///< APP NOC Trans ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_EP_TRIG_1     = ONE_HOT(27), ///< APP NOC Trans ENET EP
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_SWR_TRIG_0    = ONE_HOT(28), ///< APP NOC Trans ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_ENET_SWR_TRIG_1    = ONE_HOT(29), ///< APP NOC Trans ENET SWR
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_IOMMU_TRIG_0       = ONE_HOT(30), ///< APP NOC Trans IOMMU
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_IOMMU_TRIG_1       = ONE_HOT(31)  ///< APP NOC Trans IOMMU
} p64h_sysc_trace_cross_trigger_out_select_1_t;

/**
 * Enum to define cross trigger matrix source 2
 */
typedef enum {
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M2_TRIG_0          = ONE_HOT(0),  ///< APP NOC Trans M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M2_TRIG_1          = ONE_HOT(1),  ///< APP NOC Trans M2
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M3_TRIG_0          = ONE_HOT(2),  ///< APP NOC Trans M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_M3_TRIG_1          = ONE_HOT(3),  ///< APP NOC Trans M3
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_NVM_TRIG_0         = ONE_HOT(4),  ///< APP NOC Trans NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_NVM_TRIG_1         = ONE_HOT(5),  ///< APP NOC Trans NVM
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_0_TRIG_0      = ONE_HOT(6),  ///< APP NOC Trans PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_0_TRIG_1      = ONE_HOT(7),  ///< APP NOC Trans PCIE 0
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_1_TRIG_0      = ONE_HOT(8),  ///< APP NOC Trans PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_PCIE_1_TRIG_1      = ONE_HOT(9),  ///< APP NOC Trans PCIE 1
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_SYS_NOC_TRIG_0     = ONE_HOT(10), ///< APP NOC Trans SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_SYS_NOC_TRIG_1     = ONE_HOT(11), ///< APP NOC Trans SYS NOC
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_USER_CRYPTO_TRIG_0 = ONE_HOT(12), ///< APP NOC Trans USER CRYPTO
    P64H_SYSC_TRACE_XTRG_APP_NOC_TRANS_USER_CRYPTO_TRIG_1 = ONE_HOT(13)  ///< APP NOC Trans USER CRYPTO
} p64h_sysc_trace_cross_trigger_out_select_2_t;

/**
 * Enum for selecting the trace data path at system level
 */
typedef enum {
    P64H_SYSC_TRACE_DEST_SERDES     = 0, ///< Trace data is directed to external trace debugger via SERDES
    P64H_SYSC_TRACE_DEST_SYSTEM_MEM = 1  ///< Trace data is directed to the AXI4 initiator Interface
} p64h_sysc_trace_dest_t;

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

/// This struct defines system information
typedef struct {
    p64h_sysc_dev_cfg_node_t dev_cfg;    ///< dev_cfg dtb node used to boot sysc firmware
    p64h_sysc_sys_version_t  fw_version; ///< sysc firmware version
} p64h_sysc_sys_info_t;

/// System attributes
typedef struct {
    tvs_mon_stat_t tvs_mon_data;       ///< Temparture and Voltage Sensor readout
    uint64_t       dsn[DSN_DWORD_LEN]; ///< Device Serial number
} p64h_sysc_sys_attr_t;

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
    uint8_t data[4000]; ///< this field currently is smaller than the 4K buffer used in the rpmi buffer, but hopefully this structure is temporary.
} p64h_sysc_sys_log_data_resp_t;

/**
 * trace serdes configurations (example, not complete)
 */
typedef struct {
    uint32_t frame_size; ///< Aurora Frame Size. TWP Sync packets must be disabled. 0: 2 TWP Frames 1: 4 TWP Frames 2: 8 TWP Frames 3: 16 TWP Frames
    uint32_t crc_en;     ///< Enable to include CRC in Aurora Frames
    uint32_t endframe;   ///< Ends any ongoing frame and adds CRC as required
    uint8_t  twp_cnt;    ///< Number of Aurora frames sent before inserting 4 bytes of TWP sync
} p64h_sysc_trace_serdes_cfg_t;

/**
 * trace destination configurations
 */
typedef struct {
    p64h_sysc_trace_dest_t       trace_dest_select; ///< select trace data path
    p64h_sysc_trace_mem_cfg_t    mem_cfg;           ///< if trace_dest_select == SYSTEM_MEM, set up trace buffer
    p64h_sysc_trace_serdes_cfg_t serdes_cfg;        ///< if trace_dest_select == SERDES, set up serdes
} p64h_sysc_trace_dest_cfg_t;

/**
 * system level trace timestamp configuration
 */
typedef struct {
    uint32_t sync_count;   ///< 12-bit counter value to send periodic synchronization requests to the ATB initiator using syncreq.
                           // It also indicates the number of complete frames between TWP synchronization packets.
                           // If this field is programmed as 0x0, the synchronization counter is disabled.
                           // If this field is programmed with 0x1-0x7 the programmed value is 0x8.
    uint32_t flush_normal; ///< This bit, when clear, allows target ports that are already flushed to
                           // receive further data even if there are other ports that have not
                           // completed flush. If set, a port that has completed flush is not be
                           // allowed to receive further data until all ports have completed
                           // flush.
    uint32_t hold_time;    ///< Hold time. Value sets the minimum hold time before switching trace
                           // sources (funnel inputs) based on the ID. Value used is programmed
                           // value + 1. 0x0 - 1 transaction hold time. 0x1 - 2 transactions hold
                           // time. 0x2 - 3 transactions hold time. 0x3 - Reserved.

} p64h_sysc_trace_twp_fmt_cfg_t;

/**
 * system level trace timestamp configuration
 */
typedef struct {
    p64h_sysc_trace_timestamp_src_t timestamp_src; ///< source of timestamp
} p64h_sysc_trace_timestamp_cfg_t;

/**
 * CORE_N_ETR_groupA_t
 */
typedef struct {
    uint32_t xtrig_out_select_0; ///< mask for selecting out trig, each bit represents which of the 32  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
    uint32_t xtrig_out_select_1; ///< mask for selecting out trig, each bit represents which of the 32  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
    uint32_t xtrig_out_select_2; ///< mask for selecting out trig, each bit represents which of the 14  bits of TRIGGER_IN gets 'or'ed together for
                                 ///< TRIGGER_OUT
} p64h_sysc_cross_matrix_single_entry_t;

/**
 *  cross trigger matrix configuration
 *  There are 78 trig in -> trig out.
 *  Each trig out can be configured to activate to each trig in by setting that bit to one
 */
typedef struct {
    p64h_sysc_cross_matrix_single_entry_t xtrig_out[SYS_TRACE_NUM_CROSS_TRIGGER]; ///< CROSS_TRIGGER_OUT_SELECT_0
                                                                                  ///< CROSS_TRIGGER_OUT_SELECT_1
                                                                                  ///< CROSS_TRIGGER_OUT_SELECT_2
} p64h_sysc_trace_xtrig_matrix_cfg_t;

/**
 * @brief
 *   Specifies any information required to configure the tracing system of the device
 */
typedef struct {
    uint32_t                           trace_srcs_msk;    ///< bitmask for sources to activate, p64h_sysc_trace_src_t
    p64h_sysc_trace_twp_fmt_cfg_t      trace_twp_fmt_cfg; ///< twp formatter configurations
    p64h_sysc_trace_dest_cfg_t         trace_dest_cfg;    ///< trace data-path configuration
    p64h_sysc_trace_timestamp_cfg_t    timestamp_cfg;     ///< system level timestamp configurations
    p64h_sysc_trace_xtrig_matrix_cfg_t xtrig_cfg;         ///< cross trigger matrix configurations

} p64h_sysc_trace_dev_cfg_t;

/**Trace Memory Controller Status register** */
typedef struct {
    uint32_t trace_buffer_full;     ///< Trace buffer is full
    uint32_t trace_mem_ctrl_ready;  ///< Trace capture has stopped and flushed &
                                    // The TMC is not tracing because of the DrainBuffer bit of the FFCR being set & he AXI interface is not busy &
                                    // the AXI interface is not busy
    uint32_t trace_pipelines_empty; ///< This bit is set when trace capture has stopped, and all internal pipelines and buffers have drained.
    uint32_t trace_buffer_empty;    ///< If set, this bit indicates that the TMC does not contain any valid trace data
    uint32_t trace_mem_err;         ///<   This bit indicates that an error has occurred on the AXI master interface.
} p64h_sysc_trace_mem_ctrl_status_t;

/// appc boot configuration status
typedef struct {
    uint32_t placeholder; ///< placeholder for appc boot configuration status
} p64h_sysc_appc_boot_cfg_status_t;

/// device trace attributes
typedef struct {
    bool                   dev_trace_mem_sink_available; ///< True if trace can be sent to system memory
    bool                   dev_trace_hti_sink_available; ///< True if trace can be sent to serdes
    p64h_sysc_trace_dest_t sink_selected;                ///< Currently selected sink
} p64h_sysc_trace_dev_attr_t;

/// Package configuration
typedef struct {
    bool compress;   ///< Indicates if package compression is enabled (true: compressed, false: not compressed)
    bool encryp_opt; ///< Indicates if package encryption is enabled (true: encrypted, false: not encrypted)
} p64h_sysc_fw_pkg_cfg_t;

/// firmware upgrade configuration
typedef struct {
    p64h_sysc_fw_pkg_cfg_t fw_pkg_cfg; ///< Package configuration options
} p64h_sysc_fw_upgrade_cfg_t;

/// firmware dump configuration
typedef struct {
    p64h_sysc_fw_dump_comp_t comp;          ///< Firmware dump component selection
    p64h_sysc_fw_pkg_cfg_t   fw_pkt_cfg;    ///< Package configuration options
    uint32_t                 sysc_img_msk;  ///< System controller image mask (bitmask, valid range: 0x00 to 0xFF for images 0..7)
    uint32_t                 bootcfg_msk;   ///< Boot configuration mask (bitmask, valid range: 0x00 to 0xFFFFFF for boot configs 0..23)
    uint32_t                 sysc_data_msk; ///< System controller data mask (partition_id: 0..7, sysc partition: 8)
} p64h_sysc_fw_dump_cfg_t;

// Firmware dump status configuration
typedef struct {
    uint32_t size;      ///< size of firmware dump to receive
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
} p64h_sysc_fw_pll_timestamp_t;

typedef struct {
    p64h_sysc_fw_pll_c_clock_t master_clk; ///< Set the Master (compared) Clock for the measurement
    p64h_sysc_fw_pll_r_clock_t test_clk;   ///< Set the Test (test) Clock for the measurement
    uint64_t                   master_val; ///< 40-bit value, sets the amount of cycles for the measurement
    uint64_t                   test_val;   ///< 40-bit value, sets the starting value for the reference counter
    uint64_t                   wdog_val;   ///< 40-bit value, sets the watchdog timeout value for the compared clock
} p64h_sysc_fw_pll_cfg_t;
#endif // P64H_SYSC_SYSTEM_TYPES_H
/// @}
