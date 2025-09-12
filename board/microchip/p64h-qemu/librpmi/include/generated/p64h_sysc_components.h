/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef P64H_SYSC_DEF_COMPONENTS_H
#define P64H_SYSC_DEF_COMPONENTS_H

#include <env/p64h_sysc_os_specific.h>

/* Public Defines --------------------------------------- */
#define P64H_SYSC_COMP_ENCODE(id) (((id+1u) << 12u)) ///< Retrieve the system code for a specific component ID
#define P64H_SYSC_COMP_DECODE(code) ((((uint32_t)(code) & 0xFFFFFU) >> 12u)-1u) ///< Retrieve the component ID from a system code
#define P64H_SYSC_NUM_SVC_COMP 11

/* Public Structs and Enums ----------------------------- */

/**
 * @brief P64H SYSC Components
 *
 */
typedef enum p64h_comp_t {
    P64H_COMP_SVC_SYSTEM            = 0,   ///< component id for system service
    P64H_COMP_SVC_APPC,                    ///< component id for appc service
    P64H_COMP_SVC_COM,                     ///< component id for com service
    P64H_COMP_SVC_TEST,                    ///< component id for test service
    P64H_COMP_SVC_TRACE,                   ///< component id for trace service
    P64H_COMP_SVC_CRYPTO,                  ///< component id for crypto service
    P64H_COMP_SVC_SECC_MBOX,               ///< component id for secc_mbox service
    P64H_COMP_SVC_HW,                      ///< component id for hardware manager service (hw)
    P64H_COMP_SVC_SWITCH,                  ///< component id for switch service (sw)
    P64H_COMP_SVC_EM,                      ///< component id for error monitor service
    P64H_COMP_SVC_HEALTH,                  ///< component id for health service
    P64H_COMP_CORE,                        ///< component id for core component
    P64H_COMP_CORE_OSAL,                   ///< component id for Operating System Abstraction Layer
    P64H_COMP_CORE_INTR_HANDLER,           ///< component id for intr_handler component
    P64H_COMP_CORE_SHARED,                 ///< component id for shared component
    P64H_COMP_LIB_BAAL,                    ///< component id for boot artifact abstraction layer component
    P64H_COMP_LIB_POWER,                   ///< component id for power library
    P64H_COMP_LIB_USR_CRYPTO,              ///< component id for usr crypto library
    P64H_COMP_LIB_BIST,                    ///< component id for BIST library
    P64H_COMP_LIB_APPC_SOC_CFG,            ///< component id for appc_soc_cfg library
    P64H_COMP_LIB_API,                     ///< component id for remote api library
    P64H_COMP_LIB_SYSC_SOC_CFG,            ///< component id for sysc_soc_cfg library
    P64H_COMP_LIB_RASLIB,                  ///< component id for cperlib library
    P64H_COMP_LIB_ANLT_SM,                 ///< component id for ANLT state machine library
    P64H_COMP_LIB_TAR_ZIP_HELPER,          ///< component id for microtar miniz component
    P64H_COMP_LIB_RING_BUF,                ///< component id for Ring buffer implementation
    P64H_COMP_LIB_BIAL,                    ///< component id for bial_helper component
    P64H_COMP_LIB_SEC,                     ///< component id for sec library
    P64H_COMP_LIB_SPW_TEST,                ///< component id for spw_test library
    P64H_COMP_LIB_UTEST,                   ///< component id for utest library
    P64H_COMP_LIB_EINJLIB,                 ///< component id for error injection library
    P64H_COMP_LIB_RPMI,                    ///< component id for rpmi library
    P64H_COMP_LIB_FW_UPGRADE,              ///< component id for fw_upgrade library
    P64H_COMP_LIB_IPC,                     ///< component id for ipc library
    P64H_COMP_DRV_APP_WRAP,                ///< component id for app_wrap driver
    P64H_COMP_DRV_APP_PERIPH,              ///< component id for app_periph driver
    P64H_COMP_DRV_DDR,                     ///< component id for ddr driver
    P64H_COMP_DRV_TOP,                     ///< component id for top-level driver
    P64H_COMP_DRV_NOC_CORE,                ///< component id for noc_core driver
    P64H_COMP_DRV_IOBRIDGE,                ///< component id for iobridge driver
    P64H_COMP_DRV_WGUARD,                  ///< component id for wguard driver
    P64H_COMP_DRV_ACSU,                    ///< component id for acsu driver
    P64H_COMP_DRV_PGMRCLK,                 ///< component id for PGMRCLK clock driver
    P64H_COMP_DRV_CFM,                     ///< component id for CFM driver
    P64H_COMP_DRV_APP_IPC,                 ///< component id for ipc driver
    P64H_COMP_DRV_DDR_CTRL,                ///< component id for ddr_ctrl driver
    P64H_COMP_DRV_DDR_EDAC,                ///< component id for ddr_edac driver
    P64H_COMP_DRV_DMA,                     ///< component id for dma driver
    P64H_COMP_DRV_OCR,                     ///< component id for ocr driver
    P64H_COMP_DRV_SERDES_IF,               ///< component id for SerDes High-level interface driver
    P64H_COMP_DRV_ANLT,                    ///< component id for ANLT driver
    P64H_COMP_DRV_M1_CORE,                 ///< component id for m1_core driver
    P64H_COMP_DRV_SYS_TOP,                 ///< component id for sys_top driver
    P64H_COMP_DRV_SYS_HPT,                 ///< component id for sys_hpt driver
    P64H_COMP_DRV_NVM,                     ///< component id for nvm driver
    P64H_COMP_DRV_EDAC,                    ///< component id for EDAC component
    P64H_COMP_DRV_X288_RAS,                ///< component id for x288 RAS driver
    P64H_COMP_DRV_ARM_N_FIRE,              ///< component id for arm and fire driver
    P64H_COMP_DRV_DEBUG,                   ///< component id for debug driver
    P64H_COMP_DRV_APP_SPW,                 ///< component id for spw driver
    P64H_COMP_DRV_DDR_NOC,                 ///< component id for ddr_noc driver
    P64H_COMP_DRV_PIER,                    ///< component id for pier driver
    P64H_COMP_DRV_PCIE_CXL,                ///< component id for pcie_cxl driver
    P64H_COMP_DRV_ZSBL,                    ///< component id for zsbl driver
    P64H_COMP_DRV_TRACE,                   ///< component id for trace driver
    P64H_COMP_DRV_WDOG,                    ///< component id for wdog driver
    P64H_COMP_DRV_LSIO,                    ///< component id for Low-speed IO driver
    P64H_COMP_DRV_APP_DMA,                 ///< component id for APP DMA driver
    P64H_COMP_DRV_SPI_FLASH,               ///< component id for spi flash driver
    P64H_COMP_LAST
} p64h_comp_t;

/**
 * @brief Log identifier
 *
 */
typedef enum p64h_sysc_log_id_t {
    P64H_SYSC_LOG_ID_SVC_SYSTEM            = 0,   ///< log identifier for system service
    P64H_SYSC_LOG_ID_SVC_APPC,                    ///< log identifier for appc service
    P64H_SYSC_LOG_ID_SVC_COM,                     ///< log identifier for com service
    P64H_SYSC_LOG_ID_SVC_TEST,                    ///< log identifier for test service
    P64H_SYSC_LOG_ID_SVC_TRACE,                   ///< log identifier for trace service
    P64H_SYSC_LOG_ID_SVC_CRYPTO,                  ///< log identifier for crypto service
    P64H_SYSC_LOG_ID_SVC_SECC_MBOX,               ///< log identifier for secc_mbox service
    P64H_SYSC_LOG_ID_SVC_HW,                      ///< log identifier for hardware manager service (hw)
    P64H_SYSC_LOG_ID_SVC_SWITCH,                  ///< log identifier for switch service (sw)
    P64H_SYSC_LOG_ID_SVC_EM,                      ///< log identifier for error monitor service
    P64H_SYSC_LOG_ID_SVC_HEALTH,                  ///< log identifier for health service
    P64H_SYSC_LOG_ID_CORE,                        ///< log identifier for core component
    P64H_SYSC_LOG_ID_CORE_OSAL,                   ///< log identifier for Operating System Abstraction Layer
    P64H_SYSC_LOG_ID_CORE_INTR_HANDLER,           ///< log identifier for intr_handler component
    P64H_SYSC_LOG_ID_CORE_SHARED,                 ///< log identifier for shared component
    P64H_SYSC_LOG_ID_LIB_BAAL,                    ///< log identifier for boot artifact abstraction layer component
    P64H_SYSC_LOG_ID_LIB_POWER,                   ///< log identifier for power library
    P64H_SYSC_LOG_ID_LIB_USR_CRYPTO,              ///< log identifier for usr crypto library
    P64H_SYSC_LOG_ID_LIB_BIST,                    ///< log identifier for BIST library
    P64H_SYSC_LOG_ID_LIB_APPC_SOC_CFG,            ///< log identifier for appc_soc_cfg library
    P64H_SYSC_LOG_ID_LIB_API,                     ///< log identifier for remote api library
    P64H_SYSC_LOG_ID_LIB_SYSC_SOC_CFG,            ///< log identifier for sysc_soc_cfg library
    P64H_SYSC_LOG_ID_LIB_RASLIB,                  ///< log identifier for cperlib library
    P64H_SYSC_LOG_ID_LIB_ANLT_SM,                 ///< log identifier for ANLT state machine library
    P64H_SYSC_LOG_ID_LIB_TAR_ZIP_HELPER,          ///< log identifier for microtar miniz component
    P64H_SYSC_LOG_ID_LIB_RING_BUF,                ///< log identifier for Ring buffer implementation
    P64H_SYSC_LOG_ID_LIB_BIAL,                    ///< log identifier for bial_helper component
    P64H_SYSC_LOG_ID_LIB_SEC,                     ///< log identifier for sec library
    P64H_SYSC_LOG_ID_LIB_SPW_TEST,                ///< log identifier for spw_test library
    P64H_SYSC_LOG_ID_LIB_UTEST,                   ///< log identifier for utest library
    P64H_SYSC_LOG_ID_LIB_EINJLIB,                 ///< log identifier for error injection library
    P64H_SYSC_LOG_ID_LIB_RPMI,                    ///< log identifier for rpmi library
    P64H_SYSC_LOG_ID_LIB_FW_UPGRADE,              ///< log identifier for fw_upgrade library
    P64H_SYSC_LOG_ID_LIB_IPC,                     ///< log identifier for ipc library
    P64H_SYSC_LOG_ID_DRV_APP_WRAP,                ///< log identifier for app_wrap driver
    P64H_SYSC_LOG_ID_DRV_APP_PERIPH,              ///< log identifier for app_periph driver
    P64H_SYSC_LOG_ID_DRV_DDR,                     ///< log identifier for ddr driver
    P64H_SYSC_LOG_ID_DRV_TOP,                     ///< log identifier for top-level driver
    P64H_SYSC_LOG_ID_DRV_NOC_CORE,                ///< log identifier for noc_core driver
    P64H_SYSC_LOG_ID_DRV_IOBRIDGE,                ///< log identifier for iobridge driver
    P64H_SYSC_LOG_ID_DRV_WGUARD,                  ///< log identifier for wguard driver
    P64H_SYSC_LOG_ID_DRV_ACSU,                    ///< log identifier for acsu driver
    P64H_SYSC_LOG_ID_DRV_PGMRCLK,                 ///< log identifier for PGMRCLK clock driver
    P64H_SYSC_LOG_ID_DRV_CFM,                     ///< log identifier for CFM driver
    P64H_SYSC_LOG_ID_DRV_APP_IPC,                 ///< log identifier for ipc driver
    P64H_SYSC_LOG_ID_DRV_DDR_CTRL,                ///< log identifier for ddr_ctrl driver
    P64H_SYSC_LOG_ID_DRV_DDR_EDAC,                ///< log identifier for ddr_edac driver
    P64H_SYSC_LOG_ID_DRV_DMA,                     ///< log identifier for dma driver
    P64H_SYSC_LOG_ID_DRV_OCR,                     ///< log identifier for ocr driver
    P64H_SYSC_LOG_ID_DRV_SERDES_IF,               ///< log identifier for SerDes High-level interface driver
    P64H_SYSC_LOG_ID_DRV_ANLT,                    ///< log identifier for ANLT driver
    P64H_SYSC_LOG_ID_DRV_M1_CORE,                 ///< log identifier for m1_core driver
    P64H_SYSC_LOG_ID_DRV_SYS_TOP,                 ///< log identifier for sys_top driver
    P64H_SYSC_LOG_ID_DRV_SYS_HPT,                 ///< log identifier for sys_hpt driver
    P64H_SYSC_LOG_ID_DRV_NVM,                     ///< log identifier for nvm driver
    P64H_SYSC_LOG_ID_DRV_EDAC,                    ///< log identifier for EDAC component
    P64H_SYSC_LOG_ID_DRV_X288_RAS,                ///< log identifier for x288 RAS driver
    P64H_SYSC_LOG_ID_DRV_ARM_N_FIRE,              ///< log identifier for arm and fire driver
    P64H_SYSC_LOG_ID_DRV_DEBUG,                   ///< log identifier for debug driver
    P64H_SYSC_LOG_ID_DRV_APP_SPW,                 ///< log identifier for spw driver
    P64H_SYSC_LOG_ID_DRV_DDR_NOC,                 ///< log identifier for ddr_noc driver
    P64H_SYSC_LOG_ID_DRV_PIER,                    ///< log identifier for pier driver
    P64H_SYSC_LOG_ID_DRV_PCIE_CXL,                ///< log identifier for pcie_cxl driver
    P64H_SYSC_LOG_ID_DRV_ZSBL,                    ///< log identifier for zsbl driver
    P64H_SYSC_LOG_ID_DRV_TRACE,                   ///< log identifier for trace driver
    P64H_SYSC_LOG_ID_DRV_WDOG,                    ///< log identifier for wdog driver
    P64H_SYSC_LOG_ID_DRV_LSIO,                    ///< log identifier for Low-speed IO driver
    P64H_SYSC_LOG_ID_DRV_APP_DMA,                 ///< log identifier for APP DMA driver
    P64H_SYSC_LOG_ID_DRV_SPI_FLASH,               ///< log identifier for spi flash driver
    P64H_SYSC_LOG_ID_LAST
} p64h_sysc_log_id_t;

#endif /* P64H_SYSC_DEF_COMPONENTS_H */