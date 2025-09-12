/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_HEALTH_TYPE_H
#define P64H_SYSC_RAS_HEALTH_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>

/* Public Defines ------------------------------------------------- */

/* Public Structs and Enums --------------------------------------- */

typedef enum {
    NVM_SRAM = 0,
    DDR,
    APPC_OCR,
    SYSC_OCR,
    SECC_OCR,
    SECC_PQCRYPTO,
    APP_DMA_FIFO,
    ETHERNET_TCAM_VCAP,
    SECC_PQ_CRYPTO,
    SECC_MBOX,
    APPC_CORE_0_ITIM,
    APPC_CORE_0_DLS,
    APPC_CORE_1_ITIM,
    APPC_CORE_1_DLS,
    APPC_CORE_2_ITIM,
    APPC_CORE_2_DLS,
    APPC_CORE_3_ITIM,
    APPC_CORE_3_DLS,
    APPC_CORE_4_ITIM,
    APPC_CORE_4_DLS,
    APPC_CORE_5_ITIM,
    APPC_CORE_5_DLS,
    APPC_CORE_6_ITIM,
    APPC_CORE_6_DLS,
    APPC_CORE_7_ITIM,
    APPC_CORE_7_DLS,
    SYSC_ITIM,
    SYSC_DLS,
    SECC_ITIM,
    SECC_DLS,
    APPC_CORE_0_L1I,
    APPC_CORE_0_L1D,
    APPC_CORE_0_PL2,
    APPC_CORE_1_L1I,
    APPC_CORE_1_L1D,
    APPC_CORE_1_PL2,
    APPC_CORE_2_L1I,
    APPC_CORE_2_L1D,
    APPC_CORE_2_PL2,
    APPC_CORE_3_L1I,
    APPC_CORE_3_L1D,
    APPC_CORE_3_PL2,
    APPC_CORE_4_L1I,
    APPC_CORE_4_L1D,
    APPC_CORE_4_PL2,
    APPC_CORE_5_L1I,
    APPC_CORE_5_L1D,
    APPC_CORE_5_PL2,
    APPC_CORE_6_L1I,
    APPC_CORE_6_L1D,
    APPC_CORE_6_PL2,
    APPC_CORE_7_L1I,
    APPC_CORE_7_L1D,
    APPC_CORE_7_PL2,
    APPC_EC3,
    SYSC_L1I,
    SYSC_L1D,
    IOMMU_0_TLB,
    IOMMU_1_TLB,
    P64H_MEMSCRUBBER_ID_MAX,
} p64h_sysc_mem_scrubber_id_t;

/// Description of the configuration fields for a specified memory scrubber
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for the memory scrubber configuration
} p64h_sysc_mem_scrubber_cfg_t;

/// Memory scrubbing profile
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for the memory scrubbing profile
} p64h_sysc_scrub_prof_t;

/// SW health report
typedef struct {
    uint64_t sysc_appc_svc      : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_com_svc       : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_em_svc        : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_er_svc        : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_health_svc    : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_hw_svc        : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_nmra_svc      : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_secc_mbox_svc : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_switch_svc    : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_system_svc    : 1; ///< Placeholder variable for the SW health report
    uint64_t sysc_test_svc      : 1; ///< Placeholder variable for the SW health report
    uint64_t appc_partition;         ///< Placeholder variable for the SW health report
    uint64_t secc_application : 1;   ///< Placeholder variable for the SW health report
} p64h_sysc_sw_health_report_t;

/// HW health report
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for the HW health report
} p64h_sysc_hw_health_report_t;

/// HW health check configuration
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for the HW health check configuration
} p64h_sysc_hw_health_check_cfg_t;

/// WDOG configuration
typedef struct {
    uint64_t first_win_exp;  ///< WDOG first window expiracy threshold
    uint64_t second_win_exp; ///< WDOG second window expiracy threshold
} p64h_sysc_wdog_cfg_t;

/// WDOG state
typedef enum {
    WDOG_PAUSED = 0, ///< WDOG paused
    WDOG_COUNTING,   ///< WDOG counting
    WDOG_LAST_STATE, ///< WDOG last state
} p64h_sysc_wdog_state_t;

#endif // P64H_SYSC_RAS_HEALTH_TYPE_H
/// @}
