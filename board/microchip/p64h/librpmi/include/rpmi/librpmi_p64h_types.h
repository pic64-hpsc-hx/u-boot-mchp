/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  librpmi_p64h_types.h
 * @brief RPMI type extensions and custom types related to p64h specific service groups/services
 * @addtogroup RPMI
 * @{
 */

#ifndef LIB_RPMI_P64H_TYPES_H
#define LIB_RPMI_P64H_TYPES_H

#include <env/p64h_sysc_os_specific.h>
#include <rpmi/librpmi_types.h>
#include <generated/p64h_sysc_errors.h>

/// Maximum size of an RPMI slot buffer
// reserving 4 bytes for checksum to ensure data integrity(e.g., CRC32).
#define RPMI_MAX_SLOT_SIZE       ((32U * 1024U) - 4U)
#define P64H_RPMI_SRVGRP_ID_BASE (0xA000)
#define P64H_RPMI_SRVGRP_COUNT   ((uint32_t)((uint32_t)(P64H_RPMI_SRVGRP_MAX)-P64H_RPMI_SRVGRP_ID_BASE) - 1u)

/// Enum encapsulating the possible RPMI roles
typedef enum {
    RPMI_ROLE_P = 0, ///< this is the Platform microcontroller role. (system_controller)
    RPMI_ROLE_A,     ///< this is the Application role. (AppC or Remote)
    RPMI_NUM_ROLES   ///< the number of Roles in the enum
} rpmi_role_t;

typedef enum rpmi_error                   rpmi_error_t;
typedef enum rpmi_periph                  rpmi_periph_t;
typedef struct rpmi_service_group         rpmi_service_group_t;
typedef struct rpmi_service               rpmi_service_t;
typedef struct rpmi_transport             rpmi_transport_t;
typedef struct rpmi_message               rpmi_message_t;
typedef struct rpmi_message_header        rpmi_message_header_t;
typedef struct rpmi_shmem                 rpmi_shmem_t;
typedef struct rpmi_io                    rpmi_io_t;
typedef struct rpmi_io_port               rpmi_io_port_t;
typedef struct rpmi_transport_shmem       rpmi_transport_shmem_t;
typedef struct rpmi_transport_io          rpmi_transport_io_t;
typedef struct rpmi_transport_shmem_queue rpmi_transport_shmem_queue_t;
typedef struct rpmi_event_callback        rpmi_event_callback_t;

/// RPMI Generic Response Header
typedef struct {
    int32_t rpmi_rc;    ///< This is an rpmi_error_t but is made an int32_t to ensure it always consumes 4 bytes. sizeof enum depends on the values in
                        ///< the enum
    p64h_err_t p64h_rc; ///< p64h error code
} rpmi_resp_metadata_t;

/// RPMI Generic Request Header
typedef struct {
    uint32_t id0; ///< generic identifier 0
    uint32_t id1; ///< generic identifier 1
    uint32_t id2; ///< generic identifier 2
} rpmi_req_metadata_t;

/// RPMI Generic Response type
typedef struct {
    rpmi_message_header_t header; ///< Header
    rpmi_resp_metadata_t  resp_metadata;
    uint8_t               data[0] __attribute__((aligned(8))); ///< The payload of the response.
} rpmi_resp_message_t;

/// RPMI Generic request type
typedef struct {
    rpmi_message_header_t header;                              ///< header message
    rpmi_req_metadata_t   req_metadata;                        ///< header message
    uint8_t               data[0] __attribute__((aligned(8))); ///< The payload of the request.
} rpmi_req_message_t;

/// RPMI Response With Data request metadata type
typedef struct {
    rpmi_req_metadata_t req_metadata; ///< rpmi request metadata
    uint32_t            offset;       ///< Offset for next fragment data
    uint32_t            remaining;    ///< Remaining size the requestor expects to receive, 0 if requestor doesn't specify size to receive
    bool                shmem_xfer;   ///< false: the buffer will transfer thru RPMI channel
                                      ///< true: the data_ptr shall be available to the system controller
} rpmi_data_pull_req_metadata_t;

/// RPMI Response With Data response metadata type
typedef struct {
    rpmi_resp_metadata_t resp_metadata; ///< rpmi response metadata
    uint32_t             remaining;     ///< Number of buffer elements remaining to transfer
    uint32_t             returned;      ///< Number of buffer elements returned
} rpmi_data_pull_resp_metadata_t;

/// RPMI Response With Data response type
typedef struct {
    rpmi_message_header_t          header;                              ///< header
    rpmi_data_pull_resp_metadata_t metadata;                            ///< metadata
    uint8_t                        data[0] __attribute__((aligned(8))); ///< The payload of the response.
} rpmi_data_pull_resp_message_t;

/// RPMI Response With Data request type
typedef struct {
    rpmi_message_header_t         header;                              ///< header message
    rpmi_data_pull_req_metadata_t metadata;                            ///< metadata
    uint8_t                       data[0] __attribute__((aligned(8))); ///< The payload of the request.
} rpmi_data_pull_req_message_t;

/// RPMI log response metadata type
typedef struct __attribute__((aligned(8))) {
    rpmi_resp_metadata_t resp_metadata;     ///< rpmi response metadata
    uint32_t             resp_start_off_lo; ///< Actual log offset from which data was returned (LSB)
    uint32_t             resp_start_off_hi; ///< Actual log offset from which data was returned (MSB)
    uint32_t             entries_left_lo;   ///< Number of entries left to pull (LSB)
    uint32_t             entries_left_hi;   ///< Number of entries left to pull (MSB)
    uint32_t             returned;          ///< Number of log entries returned
} rpmi_log_resp_metadata_t;

/// RPMI log request metadata type
typedef struct {
    rpmi_req_metadata_t req_metadata;     ///< rpmi request metadata
    uint32_t            req_start_off_lo; ///< Desired log offset at which to start fetching data entries
    uint32_t            req_start_off_hi; ///< Desired log offset at which to start fetching data entries
    uint32_t            max_num_entries;  ///< Maximum number of entries to return
} rpmi_log_req_metadata_t;

/// RPMI log response message type
typedef struct {
    rpmi_message_header_t    header;                              ///< header
    rpmi_log_resp_metadata_t log_metadata;                        ///< log metadata
    uint8_t                  data[0] __attribute__((aligned(8))); ///< The payload of the response.
} rpmi_log_resp_message_t;

/// RPMI log request message type
typedef struct {
    rpmi_message_header_t   header;                              ///< header message
    rpmi_log_req_metadata_t log_metadata;                        ///< log metadata
    uint8_t                 data[0] __attribute__((aligned(8))); ///< The payload of the request.
} rpmi_log_req_message_t;

typedef struct {
    rpmi_req_metadata_t req_metadata; ///< rpmi request header
    uint32_t            remaining;    ///< Number of buffer elements remaining to send
    uint32_t            offset;       ///< Offset of data being sent
    uint32_t            sent;         ///< Number of buffer elements sent in this transaction
    bool                shmem_xfer;   ///< false: the buffer will transfer thru RPMI channel
                                      ///< true: the data_ptr shall be available to the system controller
} rpmi_data_push_req_metadata_t;

typedef struct {
    rpmi_message_header_t         header;                              ///< header
    rpmi_data_push_req_metadata_t metadata;                            ///< metadata
    uint8_t                       data[0] __attribute__((aligned(8))); ///< The payload of the response.
} rpmi_data_push_req_message_t;

/// RPMI generic event request
typedef struct {
    uint32_t eid;       ///< event identifier
    uint32_t req_state; ///< 0: Disable, 1: Enable, 2: Return current state
} rpmi_enable_notification_t;

/// RPMI Service Access Controls
typedef enum {
    P64H_RPMI_SVC_UNSUPPORTED = 0u, ///< Service is unsupported
    P64H_RPMI_SVC_SUPPORTED   = 1u, ///< Service is supported
    P64H_RPMI_SVC_RESTRICTED  = 2u, ///< Service is supported but is restricted
    P64H_RPMI_SVC_CHALLENGE   = 3u  ///< Service is supported but need key
} p64h_rpmi_service_access_control_t;

/// P64H Implementation Specific RPMI Service Group IDs
typedef enum {
    P64H_RPMI_SRVGRP_SYSTEM     = P64H_RPMI_SRVGRP_ID_BASE + 1u,  ///< System Group
    P64H_RPMI_SRVGRP_PSM        = P64H_RPMI_SRVGRP_ID_BASE + 2u,  ///< Partition State Management Group
    P64H_RPMI_SRVGRP_TRACE      = P64H_RPMI_SRVGRP_ID_BASE + 3u,  ///< Trace Group
    P64H_RPMI_SRVGRP_DDR        = P64H_RPMI_SRVGRP_ID_BASE + 4u,  ///< DDR Group
    P64H_RPMI_SRVGRP_SERDES     = P64H_RPMI_SRVGRP_ID_BASE + 5u,  ///< SERDES Group
    P64H_RPMI_SRVGRP_LSIO       = P64H_RPMI_SRVGRP_ID_BASE + 6u,  ///< Low Speed IO Group
    P64H_RPMI_SRVGRP_SWITCH     = P64H_RPMI_SRVGRP_ID_BASE + 7u,  ///< Ethernet Switch Group
    P64H_RPMI_SRVGRP_TEST       = P64H_RPMI_SRVGRP_ID_BASE + 8u,  ///< Test Group
    P64H_RPMI_SRVGRP_RAS_EM     = P64H_RPMI_SRVGRP_ID_BASE + 9u,  ///< RAS Error Monitoring Group
    P64H_RPMI_SRVGRP_RAS_ER     = P64H_RPMI_SRVGRP_ID_BASE + 10u, ///< RAS Error Response Group
    P64H_RPMI_SRVGRP_RAS_HEALTH = P64H_RPMI_SRVGRP_ID_BASE + 11u, ///< RAS Error Health Group
    P64H_RPMI_SRVGRP_RAS_ERRINJ = P64H_RPMI_SRVGRP_ID_BASE + 12u, ///< RAS Error Injection Group
    P64H_RPMI_SRVGRP_CRYPTO     = P64H_RPMI_SRVGRP_ID_BASE + 13u, ///< Crypto Group
    P64H_RPMI_SRVGRP_DEBUG      = P64H_RPMI_SRVGRP_ID_BASE + 14u, ///< Debug Group
    P64H_RPMI_SRVGRP_NVM        = P64H_RPMI_SRVGRP_ID_BASE + 15u, ///< NVM Group
    P64H_RPMI_SRVGRP_NMRA       = P64H_RPMI_SRVGRP_ID_BASE + 16u, ///< NMRA Group
    P64H_RPMI_SRVGRP_MAX        = P64H_RPMI_SRVGRP_ID_BASE + 17u  ///< The last Service Group Defined,
                                                                  ///  Used to mark the count of the the
                                                                  ///  Implementation Specific Groups
} p64h_rpmi_service_group_id_t;

// p64h system service group related

/// Service IDs for the System Service
typedef enum {
    P64H_SYS_ENABLE_NOTIFICATION     = 1u,  ///< Enable Notification from a System Service
    P64H_SYS_GET_INFO                = 2u,  ///< Service Discovery
    P64H_SYS_GET_ATTRIBUTES          = 3u,  ///< Feature and list data
    P64H_SYS_GET_LOG_INFO            = 4u,  ///< Log Discovery
    P64H_SYS_SET_LOG_CONFIG          = 5u,  ///< Log Config Mutator
    P64H_SYS_GET_LOG_CONFIG          = 6u,  ///< Log Config Accessor
    P64H_SYS_GET_LOG_DATA            = 7u,  ///< Log Data Accessor
    P64H_SYS_GET_APPC_BOOT_CFG       = 8u,  ///< Boot Config Accessor
    P64H_SYS_SET_APPC_BOOT_CFG       = 9u,  ///< Boot Config Mutator
    P64H_SYS_GET_APPC_BOOT_STATUS    = 10u, ///< Boot Status Accessor
    P64H_SYS_SET_PWR_CONFIG          = 11u, ///< Power Config Mutator
    P64H_SYS_GET_PWR_CONFIG          = 12u, ///< Power Config Accessor
    P64H_SYS_GET_PWR_WAKEUP_TRIGGER  = 13u, ///< Power Wakeup Trigger
    P64H_SYS_GET_DEV_TRACE_ATTRIBUTE = 14u, ///< Device Trace Attribute Accessor
    P64H_SYS_GET_DEV_TRACE_CONFIG    = 15u, ///< Device Trace Config Accessor
    P64H_SYS_SET_DEV_TRACE_CONFIG    = 16u, ///< Device Trace Config Mutator
    P64H_SYS_FW_PKG_UPGRADE_UPLOAD   = 17u, ///< Send a new file to the device from remote/appc
    P64H_SYS_FW_PKG_UPGRADE_APPLY    = 18u, ///< Apply the sent file to the device from remote/appc
    P64H_SYS_FW_DUMP                 = 19u, ///< Dump an existing file(s) from the device for remote/appc
    P64H_SYS_FW_DOWNLOAD             = 20u, ///< Download a dumped file(s) from the device to remote/appc
    P64H_SYS_FW_DUMP_STATUS          = 21u, ///< Get firmware dump status
    P64H_SYS_SET_TIME                = 22u, ///< Set up system time
    P64H_SYS_GET_TIME                = 23u, ///< Get system time
    P64H_SYS_SET_PGMRCLK_CFG         = 24u, ///< PGMRCLK Config Mutator
    P64H_SYS_GET_PGMRCLK_CFG         = 25u, ///< PGMRCLK Config Accessor
    P64H_SYS_SET_CFM_MEAS_CFG        = 26u, ///< CFM Measurement Config Mutator
    P64H_SYS_GET_CFM_MEAS_CNT        = 27u, ///< CFM Measurement Config Accessor
    P64H_SYS_SET_FW_PLL_CFG          = 28u, ///< FW PLL Support Block Mutator
    P64H_SYS_GET_FW_PLL_TIMESTAMP    = 29u, ///< FW PLL Support Block Accessor
    P64H_SYS_APPC_DTB_FIXUP          = 30u, ///< Fix up AppC DTB
    P64H_SYS_M1_DUMP                 = 31u, ///< M1 boot context dump
    P64H_SYS_SRV_MAX                 = 32u  ///< Max System Service Group Service
} p64h_rpmi_system_service_id_t;

/// System Service Notification Events
typedef enum {
    P64H_SYS_LOG_AVAILABLE                 = 1u, ///< Log Available Event
    P64H_SYS_APPC_BOOT_CFG_UPDATE_COMPLETE = 2u, ///< Boot Config Update Complete Event
    P64H_SYS_POWER_UPDATE_COMPLETE         = 3u, ///< Power Update Complete Event
    P64H_SYS_FW_UPDATE_COMPLETE            = 4u  ///< Firmware Update Complete Event
} p64h_rpmi_system_service_notification_event_t;

/// System Service Notification States
typedef enum {
    P64H_SYS_NOTIFY_STATE_DISABLE = 0u, ///< Notifications are Disabled
    P64H_SYS_NOTIFY_STATE_ENABLE  = 1u, ///< Notifications are Enabled
    P64H_SYS_NOTIFY_STATE_GET     = 2u, ///< Access Notification State
    P64H_SYS_NOTIFY_STATE_MAX     = 3u  ///< Max States
} p64h_rpmi_system_service_notification_state_t;

// p64h partition state management service group related

/// Partition State Management Service Group Service IDs
typedef enum {
    P64H_PSM_ENABLE_NOTIFICATION      = 1u, ///< Enable Notification for a PSM group Service
    P64H_PSM_GET_PARTITION_LIST       = 2u, ///< Partition List Accessor
    P64H_PSM_GET_NUM_PARTITIONS       = 3u, ///< Number of PSM Partitions Accessor
    P64H_PSM_GET_PARTITION_STATUS     = 4u, ///< Partition Status Accessor
    P64H_PSM_GET_PARTITION_ATTRIBUTES = 5u, ///< Partition Attribute Accessor
    P64H_PSM_PARTITION_START          = 6u, ///< Start a partition
    P64H_PSM_PARTITION_STOP           = 7u, ///< Stop a partition
    P64H_PSM_PARTITION_SUSPEND        = 8u, ///< Suspend a partition
    P64H_PSM_SRV_MAX                  = 9u  ///< Max PSM Group Service ID
} p64h_rpmi_psm_service_id_t;

// p64h trace service group related

/// Trace Service Group Service IDs
typedef enum {
    P64H_TRACE_ENABLE_NOTIFICATION = 1u,  ///< Enable Notification for a Trace Group Service
    P64H_TRACE_GET_SINK_NUM        = 2u,  ///< Sinl Number Accessor
    P64H_TRACE_GET_SINK_LIST       = 3u,  ///< Sink List Accessor
    P64H_TRACE_GET_SINK_ATTRIBUTE  = 4u,  ///< Sink Attribute Accessor
    P64H_TRACE_GET_SINK_CONFIG     = 5u,  ///< Sink Config Accessor
    P64H_TRACE_SET_SINK_CONFIG     = 6u,  ///< Sink Config Mutator
    P64H_TRACE_GET_SYS_NUM         = 7u,  ///< Trace System Num Accessor
    P64H_TRACE_GET_SYS_LIST        = 8u,  ///< Trace System List Accessor
    P64H_TRACE_GET_SYS_ATTRIBUTE   = 9u,  ///< Trace System Attribute Accessor
    P64H_TRACE_GET_SYS_CONFIG      = 10u, ///< Trace System Config Accessor
    P64H_TRACE_SET_SYS_CONFIG      = 11u, ///< Trace System Config Mutator
    P64H_TRACE_EXEC_SYS_CONFIG     = 12u, ///< Trace System Config Execution
    P64H_TRACE_GET_SW_NUM          = 13u, ///< Software Trace Number Accessor
    P64H_TRACE_GET_SW_LIST         = 14u, ///< Software Trace List Accessor
    P64H_TRACE_GET_SW_ATTRIBUTE    = 15u, ///< Software Trace Attribute Accessor
    P64H_TRACE_GET_SW_CONFIG       = 16u, ///< Software Trace Config Accessor
    P64H_TRACE_SET_SW_CONFIG       = 17u, ///< Software Trace Config Mutator
    P64H_TRACE_GET_TE_NUM          = 18u, ///< Trace Encoder Number Accessor
    P64H_TRACE_GET_TE_LIST         = 19u, ///< Trace Encoder List Accessor
    P64H_TRACE_GET_TE_ATTRIBUTE    = 20u, ///< Trace Encoder Attribute Accessor
    P64H_TRACE_GET_TE_CONFIG       = 21u, ///< Trace Encoder Config Accessor
    P64H_TRACE_SET_TE_CONFIG       = 22u, ///< Trace Encoder Config Mutator
    P64H_TRACE_GET_TRACE_DATA      = 23u, ///< Trace Data Accessor
    P64H_TRACE_GET_NOC_DATA        = 24u, ///< Trace Noc Data Accessor
    P64H_TRACE_SRV_MAX             = 25u  ///< Max Trace Service ID
} p64h_rpmi_trace_service_id_t;

// p64h ddr service group related

/// DDR Service Group Service IDs
typedef enum {
    P64H_DDR_ENABLE_NOTIFICATION            = 1u, ///< Enable Notification for a DDR Service Group Service
    P64H_DDR_GET_CONFIG                     = 2u, ///< DDR Config Accessor
    P64H_DDR_PHY_GET_CONFIG                 = 3u, ///< DDR PHY Config Accessor
    P64H_DDR_MARGIN_TEST                    = 4u, ///< DDR Margin Test
    P64H_DDR_MARGIN_REPORT                  = 5u, ///< DDR Margin Report
    P64H_DDR_WR_LVL_DEBUG_SWEEP             = 6u, ///< DDR Write Leveling Debug Sweep
    P64H_DDR_RDGT_FIND_TDFI_RDDATA_EN_VALUE = 7u, ///< DDR Read Gate Training Find TDFI_RDDATA_EN Value
    P64H_DDR_SRV_MAX                        = 8u  ///< Max DDR Service ID
} p64h_rpmi_ddr_service_id_t;

// p64h serdes service group related

/// SERDES Service Group Service IDs
typedef enum {
    P64H_SYSC_SERDES_ENABLE_NOTIFICATION = 1u,  ///< Enable Notification for a SERDES Service Group Service
    P64H_SYSC_SERDES_GET_GRP_LIST        = 2u,  ///< SERDES Group List Accessor
    P64H_SYSC_SERDES_GET_GRP_NUM         = 3u,  ///< SERDES Group Num Accessor
    P64H_SYSC_SERDES_GET_ATTRIBUTES      = 4u,  ///< SERDES Attributes Accessor
    P64H_SYSC_SERDES_GET_CONFIG          = 5u,  ///< SERDES Config Accessor
    P64H_SYSC_SERDES_SET_CONFIG          = 6u,  ///< SERDES Config Mutator
    P64H_SYSC_SERDES_PROVISION           = 7u,  ///< SERDES Provision a given SerDes Group
    P64H_SYSC_SERDES_DEPROVISION         = 8u,  ///< SERDES Bring down a given SerDes Group
    P64H_SYSC_SERDES_GET_DIAG            = 9u,  ///< SERDES Diagnostic Accessor
    P64H_SYSC_SERDES_ANLT_SET_CONFIG     = 10u, ///< SERDES Auto-Negoitiaion and Link Training Config Accessor
    P64H_SYSC_SERDES_ANLT_GET_CONFIG     = 11u, ///< SERDES Auto-Negoitiaion and Link Training Config Mutator
    P64H_SYSC_SERDES_ANLT_GET_DIAG       = 12u, ///< SERDES Auto-Negoitiaion and Link Training Diagnostic Acessor
    P64H_SYSC_SERDES_SRV_MAX             = 13u  ///< Max SERDES Service ID
} p64h_rpmi_serdes_service_id_t;

// p64h low speed I/O service group related

/// Low-Speed I/O Service Group Service IDs
typedef enum {
    P64H_LSIO_GET_CONFIG = 1u, ///< LSIO Config Accessor
    P64H_LSIO_SRV_MAX    = 2u  ///< Max LSIO Service ID
} p64h_rpmi_lsio_service_id_t;

// p64h ethernet switch service group related

/// Ethernet Switch Service Group Service IDs
typedef enum {
    P64H_SWITCH_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a Switch Service Group Service
    P64H_SWITCH_COAP_MESSAGE        = 2u, ///< Send a COAP message to the Ethernet Switch
    P64H_SWITCH_DUMP_MESSAGE        = 3u, ///< Send a switch dump message to the Ethernet Switch
    P64H_SWITCH_SRV_MAX             = 4u  ///< Max Switch Service ID
} p64h_rpmi_switch_service_id_t;

// p64h test service group related

/// Test Service Group Service IDs
typedef enum {
    P64H_TEST_ENABLE_NOTIFICATION = 1u,  ///< Enable Notification for a Test Service Group Service
    P64H_TEST_GET_TEST_ID_NUM     = 2u,  ///< Number of Test Id Accessor
    P64H_TEST_GET_TEST_LIST       = 3u,  ///< Test List Id Accessor
    P64H_TEST_GET_ATTRIBUTES      = 4u,  ///< Test Attribute Accessor
    P64H_TEST_GET_STATUS          = 5u,  ///< Test Status Accessor
    P64H_TEST_LAUNCH              = 6u,  ///< Start a Test
    P64H_TEST_STOP                = 7u,  ///< Stop a Test
    P64H_TEST_GET_REPORT          = 8u,  ///< Test Report Accessor
    P64H_TEST_REG_OP              = 9u,  ///< Perform Register Operations
    P64H_TEST_MEM_DUMP            = 10u, ///< Perform memory dump
    P64H_TEST_ETEST_LAUNCH        = 11u, ///< Start an Embedded Test
    P64H_TEST_SRV_MAX             = 12u  ///< Max Test Service ID
} p64h_rpmi_test_service_id_t;

// p64h RAS error monitoring service group related

/// RAS Error Monitoring Service Group Service IDs
typedef enum {
    P64H_RASEM_ENABLE_NOTIFICATION     = 1u,  ///< Enable Notification for a RASEM Service Group Service
    P64H_RASEM_GET_NUM_ERR_SRCS        = 2u,  ///< Error Source Count Accessor
    P64H_RASEM_GET_ERR_SRC_ID_LIST     = 3u,  ///< Error Source ID List Accessor
    P64H_RASEM_GET_ERR_SRC_DESC        = 4u,  ///< Error Source Description Accessor
    P64H_RASEM_GET_NUM_STRUC           = 5u,  ///< Get number of structures for GHES
    P64H_RASEM_GET_STRUC_ID_LIST       = 6u,  ///< Get list of structure IDs for GHES
    P64H_RASEM_GET_NUM_STRUC_INST      = 7u,  ///< Get number of struture instances
    P64H_RASEM_GET_STRUC_INST_DESC     = 8u,  ///< Get structure instance description
    P64H_RASEM_GET_ERR_MON_TABLE_INFO  = 9u,  ///< Error Monitor Table Info Accessor
    P64H_RASEM_GET_ERT_LOG             = 10u, ///< Get local error log
    P64H_RASEM_GET_NUM_SERIAL_LOG      = 11u, ///< Get the number of serial error log
    P64H_RASEM_GET_SERIAL_LOG_LIST     = 12u, ///< Get list of serial error log identifier
    P64H_RASEM_GET_SERIAL_LOG          = 13u, ///< Fetch serial error log
    P64H_RASEM_CLEAR_SERIAL_LOG        = 14u, ///< Clear serial error log
    P64H_RASEM_GET_ERR_SRC_ERR_ID_NUM  = 15u, ///< Get number of error IDs for a specified error source
    P64H_RASEM_GET_ERR_SRC_ERR_ID_LIST = 16u, ///< Get list of error IDs for a specified error source
    P64H_RASEM_GET_ERR_SRC_ERR_DESC    = 17u, ///< Get description of error IDs
    P64H_RASEM_GET_NUM_ERR_MON_PROFILE = 18u, ///< Get number of error profiles
    P64H_RASEM_ASSIGN_ERR_MON_PROFILE  = 19u, ///< Assign an error profile ID to a partition
    P64H_RASEM_SET_ERR_MON_PROFILE     = 20u, ///< Reconfigure a profile
    P64H_RASEM_GET_ERR_MON_PROFILE     = 21u, ///< Retrieve the configuration of a profile
    P64H_RASEM_SET_ERROR_FILTER        = 22u, ///< Set filter on specified error
    P64H_RASEM_GET_ERROR_FILTER        = 23u, ///< Get filter on specified error
    P64H_RASEM_SRV_MAX                 = 24u  ///< Last EM service
} p64h_rpmi_rasem_service_id_t;

// p64h RAS error response service group related

typedef enum {
    P64H_RASER_ENABLE_NOTIFICATION      = 1u,
    P64H_RASER_GET_NUM_ERR_RESP         = 2u,
    P64H_RASER_GET_ERR_RESP_ID_LIST     = 3u,
    P64H_RASER_GET_ERR_RESP_DESC        = 4u,
    P64H_RASER_GET_ERR_RESP_ATTRIBUTES  = 5u,
    P64H_RASER_ERR_RESP_TRIGGER         = 6u,
    P64H_RASER_GET_ERR_RESP_TABLE_INFO  = 7u,
    P64H_RASER_GET_NUM_ERR_RESP_PROFILE = 8u,
    P64H_RASER_ASSIGN_ERR_RESP_PROFILE  = 9u,
    P64H_RASER_SET_ERR_RESP_PROFILE     = 10u,
    P64H_RASER_GET_ERR_RESP_PROFILE     = 11u,
    P64H_RASER_SET_ERROR_RESP           = 12u,
    P64H_RASER_GET_ERROR_RESP           = 13u,
    P64H_RASER_SRV_MAX                  = 14u
} p64h_rpmi_raser_service_id_t;

// p64h RAS error health service group related

typedef enum {
    P64H_RASHEALTH_ENABLE_NOTIFICATION         = 1u,
    P64H_RASHEALTH_GET_NUM_MEM_SCRUBBER        = 2u,
    P64H_RASHEALTH_GET_MEM_SCRUBBER_ID_LIST    = 3u,
    P64H_RASHEALTH_GET_MEM_SCRUBBER_DESC       = 4u,
    P64H_RASHEALTH_GET_MEM_SCRUBBER_ATTRIBUTES = 5u,
    P64H_RASHEALTH_GET_NUM_SCRUB_PROFILE       = 6u,
    P64H_RASHEALTH_ASSIGN_SCRUB_PROFILE        = 7u,
    P64H_RASHEALTH_SET_SCRUB_PROFILE           = 8u,
    P64H_RASHEALTH_GET_SCRUB_PROFILE           = 9u,
    P64H_RASHEALTH_SET_MEM_SCRUBBER_CFG        = 10u,
    P64H_RASHEALTH_GET_MEM_SCRUBBER_CFG        = 11u,
    P64H_RASHEALTH_GET_SW_HEALTH_REPORT        = 12u,
    P64H_RASHEALTH_EXEC_HW_HEALTH_CHECK        = 13u,
    P64H_RASHEALTH_GET_HW_HEALTH_REPORT        = 14u,
    P64H_RASHEALTH_SET_WDOG_CFG                = 15u,
    P64H_RASHEALTH_GET_WDOG_CFG                = 16u,
    P64H_RASHEALTH_WDOG_PAUSE                  = 17u,
    P64H_RASHEALTH_WDOG_RESUME                 = 18u,
    P64H_RASHEALTH_GET_WDOG_STATE              = 19u,
    P64H_RASHEALTH_SRV_MAX                     = 20u
} p64h_rpmi_rashealth_service_id_t;

// p64h RAS error injection service group related
typedef enum {
    P64H_RASERRINJ_ENABLE_NOTIFICATION    = 1u,
    P64H_RASERRINJ_GET_NUM_ERR_INJ        = 2u,
    P64H_RASERRINJ_GET_ERR_INJ_ID_LIST    = 3u,
    P64H_RASERRINJ_GET_ERR_INJ_DESC       = 4u,
    P64H_RASERRINJ_GET_ERR_INJ_ATTRIBUTES = 5u,
    P64H_RASERRINJ_ERR_INJ_TRIGGER        = 6u,
    P64H_RASERRINJ_SRV_MAX                = 7u
} p64h_rpmi_raserrinj_service_id_t;

// p64h Cryptoservice group related
typedef enum {
    P64H_CRYPTO_ENABLE_NOTIFICATION = 1u,
    P64H_CRYPTO_GET_KEY_NUM         = 2u,
    P64H_CRYPTO_GET_KEY_LIST        = 3u,
    P64H_CRYPTO_SET_KEY             = 4u,
    P64H_CRYPTO_SHA                 = 5u,
    P64H_CRYPTO_AES                 = 6u,
    P64H_CRYPTO_SIGN                = 7u,
    P64H_CRYPTO_SRV_MAX             = 8u
} p64h_rpmi_crypto_service_id_t;

/// NVM Service Group Service IDs
typedef enum {
    P64H_NVM_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a  Service Group Service
    P64H_NVM_GET_CONFIG          = 2u, ///< Config Accessor
    P64H_NVM_GET_DEVICE          = 3u, ///< Device Information Accessor
    P64H_NVM_DIAG_TEST           = 4u, ///< Run Diagnostic Test
    P64H_NVM_SRV_MAX             = 5u  ///< Max Service ID
} p64h_rpmi_nvm_service_id_t;

// p64h debug group related
typedef enum {
    P64H_DEBUG_ENABLE_NOTIFICATION = 1u,
    P64H_DEBUG_READ_MEM            = 2u,
    P64H_DEBUG_WRITE_MEM           = 3u,
    P64H_DEBUG_READ_CSR            = 4u,
    P64H_DEBUG_WRITE_CSR           = 5u,
    P64H_DEBUG_SRV_MAX             = 6u ///< Max Service ID
} p64h_rpmi_debug_service_id_t;

/**@} */

#endif // LIB_RPMI_P64H_TYPES_H
