/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_health_types.h
 * @brief RAS Health API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_HEALTH_TYPE_H
#define P64H_SYSC_RAS_HEALTH_TYPE_H

#include "p64h_sysc_common_types.h"
#include <ba/p64h_sysc_svc_cfg_ba.h>
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>
#include <generated/bist_generated.h>

/* Public Defines ------------------------------------------------- */

/* Public Structs and Enums --------------------------------------- */

/// Description of the configuration fields for a specified memory scrubber
typedef struct {
    /// secure controller scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_ocr;    ///< secure controller OCR scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_pq_ocr; ///< secure controller OCR scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_pq_ram; ///< secure controller PQ OCR scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_itim;   ///< secure controller ITIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t secc_l1i;    ///< secure controller L1 instruction cache scrubber
    /// system controller
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_itim; ///< system controller ITIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_dtim; ///< system controller DTIM scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_ocr;  ///< system controller OCR scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t sysc_l1i;  ///< system controller L1 instruction cache scrubber
    /// application complex
    p64h_sysc_mem_scrubber_inst_cfg_t appc_itim; ///< application complex ITIM scrubber type default configuration
    p64h_sysc_mem_scrubber_inst_cfg_t appc_dls;  ///< application complex DLS scrubber type default configuration
    p64h_sysc_mem_scrubber_inst_cfg_t appc_l1i;  ///< application complex L1 instruction cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_l1d;  ///< application complex L1 data cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_pl2;  ///< application complex L2 cache scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_ec3;  ///< application complex L3 cache scrubber
    /// SOC memories (OCR)
    p64h_sysc_mem_scrubber_inst_cfg_t appc_ocr_0; ///< AppC OCR 0 scrubber
    p64h_sysc_mem_scrubber_inst_cfg_t appc_ocr_1; ///< AppC OCR 1 scrubber
    /// External memories (DDR/NVM)
    p64h_sysc_mem_scrubber_edac_inst_cfg_t ddr_0;        ///< DDR controller 0 scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t ddr_1;        ///< DDR controller 1 scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_0_0; ///< SRAM scrubber 0 (EDAC instance 0) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_0_1; ///< SRAM scrubber 0 (EDAC instance 1) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_1_0; ///< SRAM scrubber 1 (EDAC instance 0) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_1_1; ///< SRAM scrubber 1 (EDAC instance 1) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_2_0; ///< SRAM scrubber 2 (EDAC instance 0) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_sram_2_1; ///< SRAM scrubber 2 (EDAC instance 1) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_nvm_0_0;  ///< NVM scrubber 0 (EDAC instance 0) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_nvm_0_1;  ///< NVM scrubber 0 (EDAC instance 1) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_nvm_1_0;  ///< NVM scrubber 1 (EDAC instance 0) scrubber
    p64h_sysc_mem_scrubber_edac_inst_cfg_t nvm_nvm_1_1;  ///< NVM scrubber 1 (EDAC instance 1) scrubber
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

/// Test execution status
typedef enum {
    TEST_STATUS_PASS    = 0, ///< Test passed
    TEST_STATUS_FAIL    = 1, ///< Test failed
    TEST_STATUS_NOT_RUN = 2, ///< Test not run
    TEST_STATUS_ID_LAST      ///< Last value for ID type test_status
} p64h_sysc_hw_test_status_t;

typedef struct {
    p64h_sysc_bist_test_t      bist_test_id;   ///< Identifier for the BIST test
    p64h_sysc_hw_test_status_t bist_test_stat; ///< bist test status
} p64h_sysc_bist_test_result_t;

/// HW health report
typedef struct {
    p64h_sysc_bist_test_result_t bist_test_result[P64H_SYSC_BIST_TEST_LAST]; ///< Array of BIST test reports for all hardware tests
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
