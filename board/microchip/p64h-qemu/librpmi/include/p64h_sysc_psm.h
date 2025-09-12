/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_psm.h
 * @brief Partition State Management API
 * @addtogroup PSM_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_PSM_H
#define P64H_SYSC_PSM_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_psm_types.h>

// PSM event notification interface
p64h_err_t p64h_sysc_psm_evt_enable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_evt_id_t eid, const p64h_sysc_psm_evt_fct_t psm_evt_fct);
p64h_err_t p64h_sysc_psm_evt_disable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_evt_id_t eid);
p64h_err_t p64h_sysc_psm_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_evt_id_t eid, bool* enabled_ptr);
// PSM APIs
p64h_err_t p64h_sysc_psm_list_num_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_partition);
p64h_err_t p64h_sysc_psm_list_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_psm_id_t* pids, bool shmem_xfer);
p64h_err_t p64h_sysc_psm_status_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, p64h_sysc_psm_status_t* status_ptr);
p64h_err_t p64h_sysc_psm_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, p64h_sysc_psm_attr_t* attr_ptr);
p64h_err_t p64h_sysc_psm_start(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid);
p64h_err_t p64h_sysc_psm_stop(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid);
p64h_err_t p64h_sysc_psm_suspend(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid);

#endif // P64H_SYSC_PSM_H
/// @}
