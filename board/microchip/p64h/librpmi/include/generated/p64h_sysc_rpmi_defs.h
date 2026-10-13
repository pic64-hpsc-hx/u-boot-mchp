/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_rpmi_defs.h
 * @brief Generated RPMI service-group, service-ID and notification-event ID enums.
 *
 * Source of truth: tools/etc/gen_data/remote.yaml (reference_enums block),
 * itself derived from remote/include/rpmi/librpmi_p64h_types.h.
 *
 * @addtogroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RPMI_DEFS_H
#define P64H_SYSC_RPMI_DEFS_H

#include <stdint.h>

/**
 * @def P64H_RPMI_SRVGRP_ID_BASE
 * @brief Base value applied to every implementation-specific RPMI service-group ID.
 */
#define P64H_RPMI_SRVGRP_ID_BASE (0xA000)

/**
 * @enum p64h_rpmi_service_group_id_t
 * @brief P64H Implementation Specific RPMI Service Group IDs
 */
typedef enum {
    P64H_RPMI_SRVGRP_SYSTEM = P64H_RPMI_SRVGRP_ID_BASE + 1u, ///< System Group
    P64H_RPMI_SRVGRP_PSM = P64H_RPMI_SRVGRP_ID_BASE + 2u, ///< Partition State Management Group
    P64H_RPMI_SRVGRP_TRACE = P64H_RPMI_SRVGRP_ID_BASE + 3u, ///< Trace Group
    P64H_RPMI_SRVGRP_DDR = P64H_RPMI_SRVGRP_ID_BASE + 4u, ///< DDR Group
    P64H_RPMI_SRVGRP_SERDES = P64H_RPMI_SRVGRP_ID_BASE + 5u, ///< SERDES Group
    P64H_RPMI_SRVGRP_LSIO = P64H_RPMI_SRVGRP_ID_BASE + 6u, ///< Low Speed IO Group
    P64H_RPMI_SRVGRP_SWITCH = P64H_RPMI_SRVGRP_ID_BASE + 7u, ///< Ethernet Switch Group
    P64H_RPMI_SRVGRP_TEST = P64H_RPMI_SRVGRP_ID_BASE + 8u, ///< Test Group
    P64H_RPMI_SRVGRP_RAS_EM = P64H_RPMI_SRVGRP_ID_BASE + 9u, ///< RAS Error Monitoring Group
    P64H_RPMI_SRVGRP_RAS_ER = P64H_RPMI_SRVGRP_ID_BASE + 10u, ///< RAS Error Response Group
    P64H_RPMI_SRVGRP_RAS_HEALTH = P64H_RPMI_SRVGRP_ID_BASE + 11u, ///< RAS Error Health Group
    P64H_RPMI_SRVGRP_RAS_ERRINJ = P64H_RPMI_SRVGRP_ID_BASE + 12u, ///< RAS Error Injection Group
    P64H_RPMI_SRVGRP_CRYPTO = P64H_RPMI_SRVGRP_ID_BASE + 13u, ///< Crypto Group
    P64H_RPMI_SRVGRP_DEBUG = P64H_RPMI_SRVGRP_ID_BASE + 14u, ///< Debug Group
    P64H_RPMI_SRVGRP_NVM = P64H_RPMI_SRVGRP_ID_BASE + 15u, ///< NVM Group
    P64H_RPMI_SRVGRP_NMRA = P64H_RPMI_SRVGRP_ID_BASE + 16u, ///< NMRA Group
    P64H_RPMI_SRVGRP_MAX = P64H_RPMI_SRVGRP_ID_BASE + 17u, ///< The last Service Group Defined
} p64h_rpmi_service_group_id_t;

/**
 * @enum p64h_rpmi_system_service_id_t
 * @brief Service IDs for the System Service
 */
typedef enum {
    P64H_SYS_ENABLE_NOTIFICATION = 1u, ///< Enable Notification from a System Service
    P64H_SYS_GET_INFO = 2u, ///< Service Discovery
    P64H_SYS_GET_LOG_INFO = 4u, ///< Log Discovery
    P64H_SYS_SET_LOG_CONFIG = 5u, ///< Log Config Mutator
    P64H_SYS_GET_LOG_CONFIG = 6u, ///< Log Config Accessor
    P64H_SYS_GET_LOG_DATA = 7u, ///< Log Data Accessor
    P64H_SYS_GET_APPC_BOOT_CFG = 8u, ///< Boot Config Accessor
    P64H_SYS_SET_APPC_BOOT_CFG = 9u, ///< Boot Config Mutator
    P64H_SYS_GET_APPC_BOOT_STATUS = 10u, ///< Boot Status Accessor
    P64H_SYS_SET_PWR_CONFIG = 11u, ///< Power Config Mutator
    P64H_SYS_GET_PWR_CONFIG = 12u, ///< Power Config Accessor
    P64H_SYS_GET_PWR_WAKEUP_TRIGGER = 13u, ///< Power Wakeup Trigger
    P64H_SYS_GET_DEV_TRACE_ATTRIBUTE = 14u, ///< Device Trace Attribute Accessor
    P64H_SYS_GET_DEV_TRACE_CONFIG = 15u, ///< Device Trace Config Accessor
    P64H_SYS_SET_DEV_TRACE_CONFIG = 16u, ///< Device Trace Config Mutator
    P64H_SYS_FW_PKG_UPGRADE_UPLOAD = 17u, ///< Send a new file to the device from remote/appc
    P64H_SYS_FW_PKG_UPGRADE_APPLY = 18u, ///< Apply the sent file to the device from remote/appc
    P64H_SYS_FW_DUMP = 19u, ///< Dump an existing file(s) from the device for remote/appc
    P64H_SYS_FW_DOWNLOAD = 20u, ///< Download a dumped file(s) from the device to remote/appc
    P64H_SYS_FW_DUMP_STATUS = 21u, ///< Get firmware dump status
    P64H_SYS_SET_TIME = 22u, ///< Set up system time
    P64H_SYS_GET_TIME = 23u, ///< Get system time
    P64H_SYS_SET_PGMRCLK_CFG = 24u, ///< PGMRCLK Config Mutator
    P64H_SYS_GET_PGMRCLK_CFG = 25u, ///< PGMRCLK Config Accessor
    P64H_SYS_SET_CFM_MEAS_CFG = 26u, ///< CFM Measurement Config Mutator
    P64H_SYS_GET_CFM_MEAS_CNT = 27u, ///< CFM Measurement Config Accessor
    P64H_SYS_GET_FW_PLL_MEASURE = 28u, ///< FW PLL Support Block Accessor
    P64H_SYS_APPC_DTB_FIXUP = 29u, ///< Fix up AppC DTB
    P64H_SYS_TRACE_SYNCREQ_SEND = 30u, ///< Trigger a manual SYNCREQ pulse on the device trace funnel
    P64H_SYS_PTP_TOD_SET = 31u, ///< Set PTP ToD to be latched on next 1PPS
    P64H_SYS_PTP_TOD_GET = 32u, ///< Get PTP ToD captured at last 1PPS event
    P64H_SYS_SYSC_REBOOT = 33u, ///< Force reboot SysC to a specific cfg image
    P64H_SYS_SET_TMON_THRESHOLD = 34u, ///< TMON threshold Config Mutator
    P64H_SYS_GET_TMON = 35u, ///< TMON Block Accessor
    P64H_SYS_SRV_MAX = 36u, ///< Max System Service Group Service
} p64h_rpmi_system_service_id_t;

/**
 * @enum p64h_rpmi_psm_service_id_t
 * @brief Partition State Management Service Group Service IDs
 */
typedef enum {
    P64H_PSM_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a PSM group Service
    P64H_PSM_GET_PARTITION_LIST = 2u, ///< Partition List Accessor
    P64H_PSM_GET_PARTITION_STATUS = 3u, ///< Partition Status Accessor
    P64H_PSM_GET_PARTITION_ATTRIBUTES = 4u, ///< Partition Attribute Accessor
    P64H_PSM_PARTITION_START = 5u, ///< Start a partition
    P64H_PSM_PARTITION_STOP = 6u, ///< Stop a partition
    P64H_PSM_PARTITION_SUSPEND = 7u, ///< Suspend a partition
    P64H_PSM_SET_PERMS = 8u, ///< Set a partition's RPMI access level at runtime to any p64h_sysc_rpmi_access_control_t value (passphrase-gated)
    P64H_PSM_SRV_MAX = 9u, ///< Max PSM Group Service ID
} p64h_rpmi_psm_service_id_t;

/**
 * @enum p64h_rpmi_trace_service_id_t
 * @brief Trace Service Group Service IDs
 */
typedef enum {
    P64H_TRACE_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a Trace Group Service
    P64H_TRACE_GET_SINK_NUM = 2u, ///< Sink Number Accessor
    P64H_TRACE_GET_SINK_LIST = 3u, ///< Sink List Accessor
    P64H_TRACE_GET_SINK_ATTRIBUTE = 4u, ///< Sink Attribute Accessor
    P64H_TRACE_GET_SINK_CONFIG = 5u, ///< Sink Config Accessor
    P64H_TRACE_SET_SINK_CONFIG = 6u, ///< Sink Config Mutator
    P64H_TRACE_GET_SYS_NUM = 7u, ///< Trace System Num Accessor
    P64H_TRACE_GET_SYS_LIST = 8u, ///< Trace System List Accessor
    P64H_TRACE_GET_SYS_ATTRIBUTE = 9u, ///< Trace System Attribute Accessor
    P64H_TRACE_GET_SYS_CONFIG = 10u, ///< Trace System Config Accessor
    P64H_TRACE_SET_SYS_CONFIG = 11u, ///< Trace System Config Mutator
    P64H_TRACE_EXEC_SYS_CONFIG = 12u, ///< Trace System Config Execution
    P64H_TRACE_GET_SW_NUM = 13u, ///< Software Trace Number Accessor
    P64H_TRACE_GET_SW_LIST = 14u, ///< Software Trace List Accessor
    P64H_TRACE_GET_SW_ATTRIBUTE = 15u, ///< Software Trace Attribute Accessor
    P64H_TRACE_GET_SW_CONFIG = 16u, ///< Software Trace Config Accessor
    P64H_TRACE_SET_SW_CONFIG = 17u, ///< Software Trace Config Mutator
    P64H_TRACE_GET_TE_NUM = 18u, ///< Trace Encoder Number Accessor
    P64H_TRACE_GET_TE_LIST = 19u, ///< Trace Encoder List Accessor
    P64H_TRACE_GET_TE_ATTRIBUTE = 20u, ///< Trace Encoder Attribute Accessor
    P64H_TRACE_GET_TE_CONFIG = 21u, ///< Trace Encoder Config Accessor
    P64H_TRACE_SET_TE_CONFIG = 22u, ///< Trace Encoder Config Mutator
    P64H_TRACE_TE_TRACE_START = 23u, ///< Start tracing on a Trace Encoder
    P64H_TRACE_TE_TRACE_STOP = 24u, ///< Stop tracing on a Trace Encoder
    P64H_TRACE_GET_TRACE_DATA = 25u, ///< Trace Data Accessor
    P64H_TRACE_GET_NOC_DATA = 26u, ///< Trace Noc Data Accessor
    P64H_TRACE_SRV_MAX = 27u, ///< Max Trace Service ID
} p64h_rpmi_trace_service_id_t;

/**
 * @enum p64h_rpmi_ddr_service_id_t
 * @brief DDR Service Group Service IDs
 */
typedef enum {
    P64H_DDR_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a DDR Service Group Service
    P64H_DDR_GET_CONFIG = 2u, ///< DDR Config Accessor
    P64H_DDR_PHY_GET_CONFIG = 3u, ///< DDR PHY Config Accessor
    P64H_DDR_MARGIN_TEST = 4u, ///< DDR Margin Test
    P64H_DDR_MARGIN_REPORT = 5u, ///< DDR Margin Report
    P64H_DDR_WR_LVL_DEBUG_SWEEP = 6u, ///< DDR Write Leveling Debug Sweep
    P64H_DDR_RDGT_FIND_TDFI_RDDATA_EN_VALUE = 7u, ///< DDR Read Gate Training Find TDFI_RDDATA_EN Value
    P64H_DDR_DO_CDNS_BIST = 8u, ///< DDR BIST operation
    P64H_DDR_DO_STRESS_TEST = 9u, ///< DDR Stress Test operation
    P64H_DDR_DO_DQ_TX_SWEEP = 10u, ///< DDR DQ TX SWEEP operation
    P64H_DDR_DO_DQ_RX_SWEEP = 11u, ///< DDR DQ RX SWEEP operation
    P64H_DDR_TRAINING_DATA_GET = 12u, ///< DDR Training Data Accessor
    P64H_DDR_SRV_MAX = 13u, ///< Max DDR Service ID
} p64h_rpmi_ddr_service_id_t;

/**
 * @enum p64h_rpmi_serdes_service_id_t
 * @brief SERDES Service Group Service IDs
 */
typedef enum {
    P64H_SYSC_SERDES_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a SERDES Service Group Service
    P64H_SYSC_SERDES_GET_GRP_LIST = 2u, ///< SERDES Group List Accessor
    P64H_SYSC_SERDES_GET_GRP_NUM = 3u, ///< SERDES Group Num Accessor
    P64H_SYSC_SERDES_GET_ATTRIBUTES = 4u, ///< SERDES Attributes Accessor
    P64H_SYSC_SERDES_GET_CONFIG = 5u, ///< SERDES Config Accessor
    P64H_SYSC_SERDES_SET_CONFIG = 6u, ///< SERDES Config Mutator
    P64H_SYSC_SERDES_PROVISION = 7u, ///< SERDES Provision a given SerDes Group
    P64H_SYSC_SERDES_DEPROVISION = 8u, ///< SERDES Bring down a given SerDes Group
    P64H_SYSC_SERDES_GET_DIAG = 9u, ///< SERDES Diagnostic Accessor
    P64H_SYSC_SERDES_ANLT_SET_CONFIG = 10u, ///< SERDES Auto-Negotiation and Link Training Config Mutator
    P64H_SYSC_SERDES_ANLT_GET_CONFIG = 11u, ///< SERDES Auto-Negotiation and Link Training Config Accessor
    P64H_SYSC_SERDES_ANLT_GET_DIAG = 12u, ///< SERDES Auto-Negotiation and Link Training Diagnostic Accessor
    P64H_SYSC_SERDES_SRV_MAX = 13u, ///< Max SERDES Service ID
} p64h_rpmi_serdes_service_id_t;

/**
 * @enum p64h_rpmi_lsio_service_id_t
 * @brief Low-Speed I/O Service Group Service IDs
 */
typedef enum {
    P64H_LSIO_GET_CONFIG = 1u, ///< LSIO Config Accessor
    P64H_LSIO_SRV_MAX = 2u, ///< Max LSIO Service ID
} p64h_rpmi_lsio_service_id_t;

/**
 * @enum p64h_rpmi_switch_service_id_t
 * @brief Ethernet Switch Service Group Service IDs
 */
typedef enum {
    P64H_SWITCH_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a Switch Service Group Service
    P64H_SWITCH_COAP_MESSAGE = 2u, ///< Send a COAP message to the Ethernet Switch
    P64H_SWITCH_DUMP_MESSAGE = 3u, ///< Send a switch dump message to the Ethernet Switch
    P64H_SWITCH_SRV_MAX = 4u, ///< Max Switch Service ID
} p64h_rpmi_switch_service_id_t;

/**
 * @enum p64h_rpmi_test_service_id_t
 * @brief Test Service Group Service IDs
 */
typedef enum {
    P64H_TEST_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a Test Service Group Service
    P64H_TEST_GET_TEST_ID_NUM = 2u, ///< Number of Test Id Accessor
    P64H_TEST_GET_TEST_LIST = 3u, ///< Test List Id Accessor
    P64H_TEST_GET_ATTRIBUTES = 4u, ///< Test Attribute Accessor
    P64H_TEST_GET_STATUS = 5u, ///< Test Status Accessor
    P64H_TEST_LAUNCH = 6u, ///< Start a Test
    P64H_TEST_STOP = 7u, ///< Stop a Test
    P64H_TEST_GET_REPORT = 8u, ///< Test Report Accessor
    P64H_TEST_REG_OP = 9u, ///< Perform Register Operations
    P64H_TEST_MEM_DUMP = 10u, ///< Perform memory dump
    P64H_TEST_ETEST_LAUNCH = 11u, ///< Start an Embedded Test
    P64H_TEST_SRV_MAX = 12u, ///< Max Test Service ID
} p64h_rpmi_test_service_id_t;

/**
 * @enum p64h_rpmi_rasem_service_id_t
 * @brief RAS Error Monitoring Service Group Service IDs
 */
typedef enum {
    P64H_RASEM_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a RASEM Service Group Service
    P64H_RASEM_GET_NUM_ERR_SRCS = 2u, ///< Error Source Count Accessor
    P64H_RASEM_GET_ERR_SRC_ID_LIST = 3u, ///< Error Source ID List Accessor
    P64H_RASEM_GET_NUM_STRUC = 4u, ///< Get number of structures for GHES
    P64H_RASEM_GET_STRUC_ID_LIST = 5u, ///< Get list of structure IDs for GHES
    P64H_RASEM_GET_NUM_STRUC_INST = 6u, ///< Get number of structure instances
    P64H_RASEM_GET_ERR_MON_TABLE_INFO = 7u, ///< Error Monitor Table Info Accessor
    P64H_RASEM_GET_ERT_LOG = 8u, ///< Get local error log
    P64H_RASEM_CLEAR_ERT_LOG = 9u, ///< Clear local error log
    P64H_RASEM_GET_NUM_SERIAL_LOG = 10u, ///< Get the number of serial error log
    P64H_RASEM_GET_SERIAL_LOG_LIST = 11u, ///< Get list of serial error log identifier
    P64H_RASEM_GET_SERIAL_LOG = 12u, ///< Fetch serial error log
    P64H_RASEM_CLEAR_SERIAL_LOG = 13u, ///< Clear serial error log
    P64H_RASEM_GET_ERR_SRC_ERR_ID_NUM = 14u, ///< Get number of error IDs for a specified error source
    P64H_RASEM_GET_ERR_SRC_ERR_ID_LIST = 15u, ///< Get list of error IDs for a specified error source
    P64H_RASEM_GET_NUM_ERR_MON_PROFILE = 16u, ///< Get number of error profiles
    P64H_RASEM_ASSIGN_ERR_MON_PROFILE = 17u, ///< Assign an error profile ID to a partition
    P64H_RASEM_SET_ERR_MON_PROFILE = 18u, ///< Reconfigure a profile
    P64H_RASEM_GET_ERR_MON_PROFILE = 19u, ///< Retrieve the configuration of a profile
    P64H_RASEM_SET_ERROR_FILTER = 20u, ///< Set filter on specified error
    P64H_RASEM_GET_ERROR_FILTER = 21u, ///< Get filter on specified error
    P64H_RASEM_SRV_MAX = 22u, ///< Last EM service
} p64h_rpmi_rasem_service_id_t;

/**
 * @enum p64h_rpmi_raser_service_id_t
 * @brief raser service IDs
 */
typedef enum {
    P64H_RASER_ENABLE_NOTIFICATION = 1u, ///< P64H_RASER_ENABLE_NOTIFICATION
    P64H_RASER_GET_NUM_ERR_RESP = 2u, ///< P64H_RASER_GET_NUM_ERR_RESP
    P64H_RASER_GET_ERR_RESP_ID_LIST = 3u, ///< P64H_RASER_GET_ERR_RESP_ID_LIST
    P64H_RASER_GET_ERR_RESP_ATTRIBUTES = 4u, ///< P64H_RASER_GET_ERR_RESP_ATTRIBUTES
    P64H_RASER_ERR_RESP_TRIGGER = 5u, ///< P64H_RASER_ERR_RESP_TRIGGER
    P64H_RASER_GET_ERR_RESP_TABLE_INFO = 6u, ///< P64H_RASER_GET_ERR_RESP_TABLE_INFO
    P64H_RASER_GET_NUM_ERR_RESP_PROFILE = 7u, ///< P64H_RASER_GET_NUM_ERR_RESP_PROFILE
    P64H_RASER_ASSIGN_ERR_RESP_PROFILE = 8u, ///< P64H_RASER_ASSIGN_ERR_RESP_PROFILE
    P64H_RASER_SET_ERR_RESP_PROFILE = 9u, ///< P64H_RASER_SET_ERR_RESP_PROFILE
    P64H_RASER_GET_ERR_RESP_PROFILE = 10u, ///< P64H_RASER_GET_ERR_RESP_PROFILE
    P64H_RASER_SET_ERROR_RESP = 11u, ///< P64H_RASER_SET_ERROR_RESP
    P64H_RASER_GET_ERROR_RESP = 12u, ///< P64H_RASER_GET_ERROR_RESP
    P64H_RASER_SRV_MAX = 13u, ///< P64H_RASER_SRV_MAX
} p64h_rpmi_raser_service_id_t;

/**
 * @enum p64h_rpmi_rashealth_service_id_t
 * @brief rashealth service IDs
 */
typedef enum {
    P64H_RASHEALTH_ENABLE_NOTIFICATION = 1u, ///< P64H_RASHEALTH_ENABLE_NOTIFICATION
    P64H_RASHEALTH_GET_MEM_SCRUBBER_ATTRIBUTES = 2u, ///< P64H_RASHEALTH_GET_MEM_SCRUBBER_ATTRIBUTES
    P64H_RASHEALTH_GET_NUM_SCRUB_PROFILE = 3u, ///< P64H_RASHEALTH_GET_NUM_SCRUB_PROFILE
    P64H_RASHEALTH_ASSIGN_SCRUB_PROFILE = 4u, ///< P64H_RASHEALTH_ASSIGN_SCRUB_PROFILE
    P64H_RASHEALTH_SET_SCRUB_PROFILE = 5u, ///< P64H_RASHEALTH_SET_SCRUB_PROFILE
    P64H_RASHEALTH_GET_SCRUB_PROFILE = 6u, ///< P64H_RASHEALTH_GET_SCRUB_PROFILE
    P64H_RASHEALTH_SET_MEM_SCRUBBER_CFG = 7u, ///< P64H_RASHEALTH_SET_MEM_SCRUBBER_CFG
    P64H_RASHEALTH_GET_MEM_SCRUBBER_CFG = 9u, ///< P64H_RASHEALTH_GET_MEM_SCRUBBER_CFG
    P64H_RASHEALTH_GET_SW_HEALTH_REPORT = 10u, ///< P64H_RASHEALTH_GET_SW_HEALTH_REPORT
    P64H_RASHEALTH_EXEC_HW_HEALTH_CHECK = 11u, ///< P64H_RASHEALTH_EXEC_HW_HEALTH_CHECK
    P64H_RASHEALTH_GET_HW_HEALTH_REPORT = 12u, ///< P64H_RASHEALTH_GET_HW_HEALTH_REPORT
    P64H_RASHEALTH_CRITICAL_SECTION_SET = 13u, ///< P64H_RASHEALTH_CRITICAL_SECTION_SET
    P64H_RASHEALTH_CRITICAL_SECTION_GET = 14u, ///< P64H_RASHEALTH_CRITICAL_SECTION_GET
    P64H_RASHEALTH_SRV_MAX = 15u, ///< P64H_RASHEALTH_SRV_MAX
} p64h_rpmi_rashealth_service_id_t;

/**
 * @enum p64h_rpmi_raserrinj_service_id_t
 * @brief raserrinj service IDs
 */
typedef enum {
    P64H_RASERRINJ_ENABLE_NOTIFICATION = 1u, ///< P64H_RASERRINJ_ENABLE_NOTIFICATION
    P64H_RASERRINJ_GET_NUM_ERR_INJ = 2u, ///< P64H_RASERRINJ_GET_NUM_ERR_INJ
    P64H_RASERRINJ_GET_ERR_INJ_ID_LIST = 3u, ///< P64H_RASERRINJ_GET_ERR_INJ_ID_LIST
    P64H_RASERRINJ_GET_ERR_INJ_ATTRIBUTES = 4u, ///< P64H_RASERRINJ_GET_ERR_INJ_ATTRIBUTES
    P64H_RASERRINJ_ERR_INJ_TRIGGER = 5u, ///< P64H_RASERRINJ_ERR_INJ_TRIGGER
    P64H_RASERRINJ_SRV_MAX = 6u, ///< P64H_RASERRINJ_SRV_MAX
} p64h_rpmi_raserrinj_service_id_t;

/**
 * @enum p64h_rpmi_crypto_service_id_t
 * @brief crypto service IDs
 */
typedef enum {
    P64H_CRYPTO_ENABLE_NOTIFICATION = 1u, ///< P64H_CRYPTO_ENABLE_NOTIFICATION
    P64H_CRYPTO_GET_KEY_NUM = 2u, ///< P64H_CRYPTO_GET_KEY_NUM
    P64H_CRYPTO_GET_KEY_LIST = 3u, ///< P64H_CRYPTO_GET_KEY_LIST
    P64H_CRYPTO_SET_KEY = 4u, ///< P64H_CRYPTO_SET_KEY
    P64H_CRYPTO_SHA = 5u, ///< P64H_CRYPTO_SHA
    P64H_CRYPTO_AES = 6u, ///< P64H_CRYPTO_AES
    P64H_CRYPTO_SIGN = 7u, ///< P64H_CRYPTO_SIGN
    P64H_CRYPTO_SRV_MAX = 8u, ///< P64H_CRYPTO_SRV_MAX
} p64h_rpmi_crypto_service_id_t;

/**
 * @enum p64h_rpmi_nvm_service_id_t
 * @brief NVM Service Group Service IDs
 */
typedef enum {
    P64H_NVM_ENABLE_NOTIFICATION = 1u, ///< Enable Notification for a Service Group Service
    P64H_NVM_GET_CONFIG = 2u, ///< Config Accessor
    P64H_NVM_GET_DEVICE = 3u, ///< Device Information Accessor
    P64H_NVM_DIAG_TEST = 4u, ///< Run Diagnostic Test
    P64H_NVM_SRV_MAX = 5u, ///< Max Service ID
} p64h_rpmi_nvm_service_id_t;

/**
 * @enum p64h_rpmi_debug_service_id_t
 * @brief debug service IDs
 */
typedef enum {
    P64H_DEBUG_ENABLE_NOTIFICATION = 1u, ///< P64H_DEBUG_ENABLE_NOTIFICATION
    P64H_DEBUG_READ_MEM = 2u, ///< P64H_DEBUG_READ_MEM
    P64H_DEBUG_WRITE_MEM = 3u, ///< P64H_DEBUG_WRITE_MEM
    P64H_DEBUG_READ_CSR = 4u, ///< P64H_DEBUG_READ_CSR
    P64H_DEBUG_WRITE_CSR = 5u, ///< P64H_DEBUG_WRITE_CSR
    P64H_DEBUG_SRV_MAX = 6u, ///< Max Service ID
} p64h_rpmi_debug_service_id_t;

/**
 * @enum p64h_rpmi_system_service_notification_event_t
 * @brief System Service Notification Events
 */
typedef enum {
    P64H_SYS_LOG_AVAILABLE = 1u, ///< Log Available Event
    P64H_SYS_APPC_BOOT_CFG_UPDATE_COMPLETE = 2u, ///< Boot Config Update Complete Event
    P64H_SYS_POWER_UPDATE_COMPLETE = 3u, ///< Power Update Complete Event
    P64H_SYS_FW_UPDATE_COMPLETE = 4u, ///< Firmware Update Complete Event
} p64h_rpmi_system_service_notification_event_t;

#endif /* P64H_SYSC_RPMI_DEFS_H */
/** @} */
