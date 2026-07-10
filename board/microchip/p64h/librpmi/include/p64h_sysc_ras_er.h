/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_ras_er.h
 * @brief RAS Error Reporting API
 * @addtogroup RAS_ER_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_ER_H
#define P64H_SYSC_RAS_ER_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_ras_er_types.h>

p64h_err_t p64h_sysc_ras_er_evt_enable(p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_er_evt_id_t em_evt, const p64h_sysc_psm_id_t pid,
                                       const p64h_sysc_ras_er_evt_fct_t* er_evt_fct_ptr);
p64h_err_t p64h_sysc_ras_er_evt_disable(p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_er_evt_id_t em_evt, const p64h_sysc_psm_id_t pid);
p64h_err_t p64h_sysc_ras_er_evt_state_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_er_evt_id_t em_evt, const p64h_sysc_psm_id_t pid,
                                          p64h_sysc_evt_notification_state_t* evt_state_ptr);
p64h_err_t p64h_sysc_ras_er_num_err_resp_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_err_resp_ptr);
p64h_err_t p64h_sysc_ras_er_id_list_get(const p64h_sysc_handle_t* handle_ptr, uint32_t list_num, uint32_t* id_list_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_ras_er_attr_get(const p64h_sysc_handle_t* handle_ptr, uint32_t err_resp_id, p64h_sysc_ras_er_attr_desc_t* attr_desc_ptr);
p64h_err_t p64h_sysc_ras_er_trigger(const p64h_sysc_handle_t* handle_ptr, uint32_t err_resp_id, const p64h_sysc_ras_er_attr_t attr);
p64h_err_t p64h_sysc_ras_er_table_info_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_psm_id_t pid, uint64_t* table_addr_ptr);
p64h_err_t p64h_sysc_ras_er_num_prof_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_prof_ptr);
p64h_err_t p64h_sysc_ras_er_prof_assign(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_psm_id_t pid, const uint32_t prof_idx);
p64h_err_t p64h_sysc_ras_er_prof_set(const p64h_sysc_handle_t* handle_ptr, uint32_t prof_idx, const p64h_sysc_ras_er_prof_t prof);
p64h_err_t p64h_sysc_ras_er_prof_get(const p64h_sysc_handle_t* handle_ptr, uint32_t prof_idx, p64h_sysc_ras_er_prof_t* prof_ptr);
p64h_err_t p64h_sysc_ras_er_set(const p64h_sysc_handle_t* handle_ptr, uint32_t prof_idx, const uint32_t err_src_id, const uint32_t err_id,
                                const uint32_t err_resp_id);
p64h_err_t p64h_sysc_ras_er_get(const p64h_sysc_handle_t* handle_ptr, uint32_t prof_idx, const uint32_t err_src_id, const uint32_t err_id,
                                uint32_t* err_resp_id_ptr);

#endif // P64H_SYSC_RAS_ER_H
/// @}
