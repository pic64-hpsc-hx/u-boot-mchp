/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_ras_health.h
 * @brief RAS Health API
 * @addtogroup RAS_HEALTH_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_HEALTH_H
#define P64H_SYSC_RAS_HEALTH_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_ras_health_types.h>

p64h_err_t p64h_sysc_num_scrub_prof_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_scrub_prof_ptr);
p64h_err_t p64h_sysc_scrub_prof_assign(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_psm_id_t partition_id, const uint32_t* scrub_prof_id_ptr);
p64h_err_t p64h_sysc_scrub_prof_set(const p64h_sysc_handle_t* handle_ptr, uint32_t scrub_prof_id, const p64h_sysc_scrub_prof_t* scrub_prof_ptr);
p64h_err_t p64h_sysc_scrub_prof_get(const p64h_sysc_handle_t* handle_ptr, uint32_t scrub_prof_id, p64h_sysc_scrub_prof_t* scrub_prof_ptr);
p64h_err_t p64h_sysc_mem_scrubber_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_mem_scrubber_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_mem_scrubber_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_mem_scrubber_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sw_health_report_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sw_health_report_t* report_ptr);
p64h_err_t p64h_sysc_hw_health_check_exec(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_hw_health_check_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_hw_health_report_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_hw_health_report_t* report_ptr);
p64h_err_t p64h_sysc_critical_section_set(const p64h_sysc_handle_t* handle_ptr, bool active);
p64h_err_t p64h_sysc_critical_section_get(const p64h_sysc_handle_t* handle_ptr, bool* active_ptr);

#endif // P64H_SYSC_RAS_HEALTH_H
/// @}
