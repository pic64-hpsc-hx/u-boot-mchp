/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines test types used by API, dev_cfg tool and sysc firmware
 */

#ifndef P64H_SYSC_TEST_TYPES_H
#define P64H_SYSC_TEST_TYPES_H

#include <ba/p64h_sysc_shared_ba.h>
#include <ba/p64h_sysc_shared_svc_ba.h>
#include "p64h_sysc_evt_param_types.h"

#define MAX_HART_COUNT            8U // The maximum number of cores
#define P64H_SYSC_DESC_STRING_MAX 256UL

///< Maximum size of 32-bit memory to read
// TODO: reduce the size from 0x1000(16K) to 0x400(4K)
#define P64H_SYSC_MEM_READ_MAX 0x1000

/**
 * @brief
 *  Unit test return codes
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_RET_OK = 0,
    P64H_SYSC_TEST_UTEST_RET_PTR_ERROR,
    P64H_SYSC_TEST_UTEST_RET_CB_REG_ERROR,
    P64H_SYSC_TEST_UTEST_RET_STATE_ERROR,
    P64H_SYSC_TEST_UTEST_RET_TEST_TYPE_ERROR,
    P64H_SYSC_TEST_UTEST_RET_TEST_TASK_ERROR,
    P64H_SYSC_TEST_UTEST_RET_BUSY,
    P64H_SYSC_TEST_UTEST_RET_UNSUPPORTED,
    P64H_SYSC_TEST_UTEST_RET_TEST_ERROR,
    P64H_SYSC_TEST_UTEST_RET_LAST
} p64h_sysc_test_utest_ret_code_e;

/**
 * @brief
 *  Unit test states
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_STATE_IDLE,      ///< No test running
    P64H_SYSC_TEST_UTEST_STATE_RUNNING,   ///< Test is running
    P64H_SYSC_TEST_UTEST_STATE_COMPLETED, ///< Test is completed
    P64H_SYSC_TEST_UTEST_STATE_LAST
} p64h_sysc_test_utest_state_e;

/**
 * @brief
 *  Unit test types
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_TYPE_SCRATCHPAD = 0,         ///< scratchpad used for debug purpose
    P64H_SYSC_TEST_UTEST_TYPE_SYSC_API,               ///< test sysc API
    P64H_SYSC_TEST_UTEST_TYPE_SMB,                    ///< smb
    P64H_SYSC_TEST_UTEST_TYPE_GPIO,                   ///< gpio
    P64H_SYSC_TEST_UTEST_TYPE_NOC_PM,                 ///< NOC performance
    P64H_SYSC_TEST_UTEST_TYPE_IPC,                    ///< IPC (raw message) testing
    P64H_SYSC_TEST_UTEST_TYPE_RPMSG_LITE,             ///< RPMSG-lite testing
    P64H_SYSC_TEST_UTEST_TYPE_RAS,                    ///< RAS testing
    P64H_SYSC_TEST_UTEST_TYPE_ENET_PIE,               ///< ENET packet insert/extract
    P64H_SYSC_TEST_UTEST_TYPE_APPC_REPROV,            ///< appc reprov testing
    P64H_SYSC_TEST_UTEST_TYPE_APPC_REPROV_GET_STATUS, ///< appc reprov status testing
    P64H_SYSC_TEST_UTEST_TYPE_TRACE,                  ///< trace features testing
    P64H_SYSC_TEST_UTEST_TYPE_DEBUG,                  ///< debug reprov testing
    P64H_SYSC_TEST_UTEST_TYPE_BOOT_STAT,              ///< Boot stat
    P64H_SYSC_TEST_UTEST_TYPE_DRIVERS,                ///< Drivers
    P64H_SYSC_TEST_UTEST_TYPE_LIBS,                   ///< Libs
    P64H_SYSC_TEST_UTEST_TYPE_SERVICES,               ///< Services
    P64H_SYSC_TEST_UTEST_TYPE_DRIVER,                 ///< Specific Driver
    P64H_SYSC_TEST_UTEST_TYPE_LIB,                    ///< Specific Library
    P64H_SYSC_TEST_UTEST_TYPE_SERVICE,                ///< Specific Service
    P64H_SYSC_TEST_UTEST_HPT_SYNC_MTIME,
    P64H_SYSC_TEST_UTEST_TYPE_RNMI_HANDLER, ///< RNMI handler testing
    P64H_SYSC_TEST_UTEST_TYPE_IMSIC,        ///< imsic testing
    P64H_SYSC_TEST_UTEST_TYPE_LAST
} p64h_sysc_test_utest_type_e;

/**
 * @brief
 *  NoC Types
 */
typedef enum {
    P64H_SYSC_TEST_APP_NOC_TYPE,  ///< APP NoC type
    P64H_SYSC_TEST_SYSC_NOC_TYPE, ///< SYS NoC type
    P64H_SYSC_TEST_DDR_NOC_TYPE,  ///< DDR NoC
    P64H_SYSC_TEST_NOC_TYPE_LAST
} p64h_sysc_test_noc_type_e;

/**
 * @brief
 *  Unit test types
 */
typedef enum {
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SYS_PORT_CLUSTER0_APP_NOC_REQ_AND_RESP, ///< System Port Cluster 0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_MEM_PORT_CLUSTER0_APP_NOC_REQ_AND_RESP, ///< Memory Port Cluster 0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SYS_PORT_CLUSTER1_APP_NOC_REQ_AND_RESP, ///< System Port Cluster 1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_MEM_PORT_CLUSTER1_APP_NOC_REQ_AND_RESP, ///< Memory Port Cluster 1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_DDR_ENCRYPT_REQ_AND_RESP,               ///< DDR Encryption request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_EP0_APP_NOC_REQ_AND_RESP,               ///< EP0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_EP1_APP_NOC_REQ_AND_RESP,               ///< EP1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_EP2_APP_NOC_REQ_AND_RESP,               ///< EP2 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_EP3_APP_NOC_REQ_AND_RESP,               ///< EP3 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA1_PIE_HIGH_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA1 PIE high bandwith request and response APP
                                                                                     ///< NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA1_ROCE_HIGH_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA1 ROCE high bandwith request and response
                                                                                      ///< APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA1_ROCE_LOW_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA1 ROCE low bandwith request and response APP
                                                                                     ///< NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA2_PIE_HIGH_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA2 PIE high bandwith request and response APP
                                                                                     ///< NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA2_ROCE_HIGH_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA2 ROCE high bandwith request and response
                                                                                      ///< APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_ENET_SWR_RDMA2_ROCE_LOW_BW_APP_NOC_REQ_AND_RESP, ///< ENET Switch RDMA2 ROCE low bandwith request and response APP
                                                                                     ///< NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_IOMMU0_APP_NOC_REQ_AND_RESP,                     ///< IOMMU0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_IOMMU1_APP_NOC_REQ_AND_RESP,                     ///< IOMMU1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SPW0_APP_NOC_REQ_AND_RESP,                       ///< SPW0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SPW1_APP_NOC_REQ_AND_RESP,                       ///< SPW1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_USB0_APP_NOC_REQ_AND_RESP,                       ///< USB0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_USB1_APP_NOC_REQ_AND_RESP,                       ///< USB1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_APPDMA0_APP_NOC_REQ_AND_RESP,                    ///< APPDMA0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_APPDMA1_APP_NOC_REQ_AND_RESP,                    ///< APPDMA1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_TRACE_SOK_APP_NOC_REQ_AND_RESP,                  ///< TRACE SOK request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_NVM_DMA0_APP_NOC_REQ_AND_RESP,                   ///< NVM DMA0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_NVM_DMA1_APP_NOC_REQ_AND_RESP,                   ///< NVM DMA1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_NVM_SD_DMA0_APP_NOC_REQ_AND_RESP,                ///< NVM SD DMA0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_NVM_SD_DMA1_APP_NOC_REQ_AND_RESP,                ///< NVM SD DMA1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_PCIEO_CTRL0_APP_NOC_REQ_AND_RESP,                ///< PCIe0 CTRL0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_PCIEO_CTRL1_APP_NOC_REQ_AND_RESP,                ///< PCIe0 CTRL1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_PCIE1_CTRL0_APP_NOC_REQ_AND_RESP,                ///< PCIe1 CTRL0 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_PCIE1_CTRL1_APP_NOC_REQ_AND_RESP,                ///< PCIe1 CTRL1 request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SVC_NOC_APP_NOC_REQ_AND_RESP,                    ///< Service NoC request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_SYS_NOC_APP_NOC_REQ_AND_RESP,                    ///< SYS NoC request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_USER_CRYPTO_APP_NOC_REQ_AND_RESP,                ///< User Crypto request and response APP NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_A0_DDR_NOC_REQ_AND_RESP,                         ///< A0 request and response DDR NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_A1_DDR_NOC_REQ_AND_RESP,                         ///< A1 request and response DDR NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_B0_DDR_NOC_REQ_AND_RESP,                         ///< B0 request and response DDR NoC stats collection
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_B1_DDR_NOC_REQ_AND_RESP,                         ///< B1 request and response DDR NoC stats collection
    // SYSC NoC tests .....
    P64H_SYSC_TEST_NOC_PM_TEST_TYPE_LAST
} p64h_sysc_test_noc_pm_test_type_e;

/**
 * @brief
 *  define ipc utest parameter
 */
typedef struct {
    uint32_t appc_channel_id; ///< appc channel id
    uint32_t sysc_channel_id; ///< sysc channel id
    uint32_t ipc_msg_length;  ///< length of IPC message used in tests
} p64h_sysc_test_utest_param_sysc_ipc_t;

/**
 * @brief
 *  define hpt utest parameter
 */
typedef struct {
    uint32_t cluster_mask; ///< which CLINT MTIMER(s) to be synched up
} p64h_sysc_test_utest_param_sysc_hpt_t;

/**
 * @brief
 *  define scratchpad utest parameter
 */
typedef struct {
    uint32_t value; ///< a parameter value
} p64h_sysc_test_utest_param_scratchpad_t;

/**
 * @brief
 *  define scratchpad utest parameter
 */
typedef struct {
    uint32_t                          stat_alarm_read_num; ///< Number of times the stat alarm is triggered
    p64h_sysc_test_noc_type_e         noc_type;            ///< NoC Type
    p64h_sysc_test_noc_pm_test_type_e noc_pm_test_type;    ///< NoC PM test type
    bool                              trace_sok_enabled;   ///< TRUE - configure Trace Sok , FALSE - no Trace Sok
} p64h_sysc_test_utest_param_noc_pm_t;

/**
 * @brief
 *  define type of debug utest
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_TRACE_TYPE_APPC0_DEBUG_FROM_SYSC, ///< test appc 0 debug from sysc
    P64H_SYSC_TEST_UTEST_TRACE_TYPE_APPC1_DEBUG_FROM_SYSC, ///< test appc 1 debug from sysc
    P64H_SYSC_TEST_UTEST_TRACE_TYPE_CROSS_TRIGGER_TEST0,   ///< cross-trigger test 0
    P64H_SYSC_TEST_UTEST_TRACE_TYPE_CROSS_TRIGGER_TEST1,   ///< cross-trigger test 1
    P64H_SYSC_TEST_UTEST_TRACE_TYPE_LAST
} p64h_sysc_test_utest_debug_type_e;

/**
 * @brief
 *  define type of debug utest
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_DEBUG_TYPE_NOC_STAT,            ///< noc stat testing
    P64H_SYSC_TEST_UTEST_DEBUG_TYPE_CROSS_TRIGGER_TEST0, ///< cross-trigger test 0
    P64H_SYSC_TEST_UTEST_DEBUG_TYPE_CROSS_TRIGGER_TEST1, ///< cross-trigger test 1
    P64H_SYSC_TEST_UTEST_DEBUG_TYPE_LAST
} p64h_sysc_test_utest_trace_type_e;

/**
 * @brief
 *  define type of SMB utest
 */
typedef enum {
    P64H_SYSC_TEST_UTEST_TYPE_SMB_DSN_GET = 0,          ///< get serial number cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_GET_LOG,              ///< get log cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_GET_BOOTCFG,          ///< get boot config cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_TEST_BOOTCFG,         ///< test boot config cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_COMMIT_BOOTCFG,       ///< commit boot config cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_DOWNLOAD_COMPONENT,   ///< download component cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_ALIVE_MSG,            ///< sysc/secc health check
    P64H_SYSC_TEST_UTEST_TYPE_SMB_ENTER_CRITICAL_PHASE, ///< Do not issue system reset when failures are detected in sysc/secc
    P64H_SYSC_TEST_UTEST_TYPE_SMB_EXIT_CRITICAL_PHASE,  ///< Reset critical phase state
    P64H_SYSC_TEST_UTEST_TYPE_SMB_MEMORY_SCRUB,
    P64H_SYSC_TEST_UTEST_TYPE_SMB_CLOCK_ADJUST,        ///< Adjust acsu clock parameters
    P64H_SYSC_TEST_UTEST_TYPE_SMB_SIGNATURE_VERIFY,    ///< signature verify cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_CRYPTO_READY,        ///< crypto ready cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_PERIPH_STAT,         ///< peripherals status cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_M1_MISC_FEATURE_SET, ///< set m1 misc feature
    P64H_SYSC_TEST_UTEST_TYPE_SMB_READ_SCAC_CERT,      ///< read SCAC cert cmd test
    P64H_SYSC_TEST_UTEST_TYPE_SMB_GET_OTP_PE_DATA,     ///< get otp pe data
    P64H_SYSC_TEST_UTEST_TYPE_SMB_LAST
} p64h_sysc_test_utest_smb_type_e;

/**
 * @brief
 *  define smb utest parameter
 */
typedef struct {
    p64h_sysc_test_utest_smb_type_e smb_test_type;
    p64h_sysc_sec_cmd_req_params_t  smb_test_params;
} p64h_sysc_test_utest_param_smb_t;

/**
 * @brief
 *  define scratchpad utest parameter
 */
typedef struct {
    p64h_sysc_test_utest_trace_type_e type;
} p64h_sysc_test_utest_param_trace_t;

/**
 * @brief
 *  define scratchpad utest parameter
 */
typedef struct {
    p64h_sysc_test_utest_debug_type_e type;
} p64h_sysc_test_utest_param_debug_t;

/**
 * @brief
 *  define unit test parameter
 */
typedef union {
    uint32_t appc_partition_mask; ///< Number of times the stat alarm is triggered
} p64h_sysc_test_utest_param_sysc_reprov_t;

/**
 * @brief
 *  define RNMI handler utest parameter
 */
typedef struct {
    uint8_t core_mask; ///< Which core to trigger
} p64h_sysc_test_utest_param_rnmi_handler_t;

/**
 * @brief
 *  define msi unit test parameter
 */
typedef struct {
    uint32_t* msi_addr[MAX_HART_COUNT];
    uint32_t  core_mask;
    uint32_t  interrupt_idx_start;
    uint32_t  interrupt_idx_end;
} p64h_sysc_test_utest_param_imsic_t;

/**
 * @brief
 *  define unit test parameter
 */
typedef union {
    p64h_sysc_test_utest_param_scratchpad_t   scratchpad; ///< scratchpad parameter
    p64h_sysc_test_utest_param_noc_pm_t       noc_pm;     ///< noc performance monitor parameter
    p64h_sysc_test_utest_param_sysc_ipc_t     ipc;        ///< ipc parameter
    p64h_sysc_test_utest_param_trace_t        trace;      ///< trace parameter
    p64h_sysc_test_utest_param_debug_t        debug;      ///< debug parameter
    p64h_sysc_test_utest_param_smb_t          smb;        ///< smb parameter
    p64h_sysc_test_utest_param_sysc_reprov_t  reprov;
    p64h_sysc_test_utest_param_sysc_hpt_t     hpt;          ///< hpt parameter
    p64h_sysc_test_utest_param_rnmi_handler_t rnmi_handler; ///< rnmi handler parameter
    p64h_sysc_test_utest_param_imsic_t        imsic;        ///< imsic parameter
    uint32_t                                  single_param;
} p64h_sysc_test_utest_param_t;

/**
 * @brief
 *  Unit test configuration
 */
typedef struct {
    p64h_sysc_test_utest_type_e  type;  ///< unit test type
    p64h_sysc_test_utest_param_t param; ///< test parameters
} p64h_sysc_test_utest_cfg_t;

/**
 * @brief
 *  Unit test status
 */
typedef struct {
    p64h_sysc_test_utest_type_e     type;     ///< current test type
    p64h_sysc_test_utest_state_e    state;    ///< current test state
    p64h_sysc_test_utest_ret_code_e ret_val;  ///< return value (only valid when state is COMPLETED)
    uint32_t                        response; ///< specific return value of the system under test (only valid when state is COMPLETED)
    char                            ret_desc[P64H_SYSC_DESC_STRING_MAX]; ///< return description (only valid when state is COMPLETED)
} p64h_sysc_test_utest_status_t;

/// test attributes
typedef struct {
    uint32_t placeholder; ///< placeholder for test attributes
} p64h_sysc_test_attr_t;

/// test status
typedef struct {
    p64h_sysc_test_utest_type_e     type;     ///< current test type
    p64h_sysc_test_utest_state_e    state;    ///< current test state
    p64h_sysc_test_utest_ret_code_e ret_val;  ///< return value (only valid when state is COMPLETED)
    uint32_t                        response; ///< specific return value of the system under test (only valid when state is COMPLETED)
    char                            ret_desc[P64H_SYSC_DESC_STRING_MAX]; ///< return description (only valid when state is COMPLETED)
} p64h_sysc_test_status_t;

/// test launch configuration
typedef struct {
    p64h_sysc_test_utest_type_e  type;  ///< unit test type
    p64h_sysc_test_utest_param_t param; ///< test parameters
} p64h_sysc_test_launch_cfg_t;

/// etest execution configuration
typedef struct {
    p64h_sysc_test_utest_type_e type;  ///< unit test type
    uint32_t                    param; ///< test parameters
} p64h_sysc_etest_launch_cfg_t;

/// test report
typedef struct {
    uint32_t placeholder; ///< placeholder for test report
} p64h_sysc_test_report_t;

typedef enum {
    P64H_SYSC_TEST_REG_READ32              = 0u,
    P64H_SYSC_TEST_REG_READ_MODIFY_WRITE32 = 1u,
    P64H_SYSC_TEST_REG_WRITE32             = 2u
} p64h_sysc_test_reg_op_t;

/// test register operation
typedef struct {
    uint64_t                addr;   ///< Address to read/write to
    uint32_t                mask;   ///< Bits to write value to
    uint32_t                value;  ///< Pointer to value to test
    p64h_sysc_test_reg_op_t reg_op; ///< Operation to test in register
} p64h_sysc_test_reg_op_req_t;

/// test register operation
typedef struct {
    uint32_t value; ///< Pointer to value to test
} p64h_sysc_test_reg_op_resp_t;

/// memory dump operation request
typedef struct {
    uint64_t addr; ///< Address to read to
    uint32_t size; ///< size to read value to
} p64h_sysc_test_mem_dump_req_t;

/// memory dump operation response
typedef struct {
    uint32_t value[P64H_SYSC_MEM_READ_MAX]; ///<  Array of memory values read
} p64h_sysc_test_mem_dump_resp_t;

#endif // P64H_SYSC_TEST_TYPES_H
