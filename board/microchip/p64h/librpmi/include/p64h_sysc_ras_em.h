/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_ras_em.h
 * @brief RAS Error Monitoring API
 * @addtogroup RAS_EM_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_EM_H
#define P64H_SYSC_RAS_EM_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_ras_em_types.h>

p64h_err_t p64h_sysc_ras_em_evt_enable(p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_em_evt_id_t em_evt, const p64h_sysc_psm_id_t pid,
                                       const p64h_sysc_ras_em_evt_fct_t* em_evt_fct_ptr);
p64h_err_t p64h_sysc_ras_em_evt_disable(p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_em_evt_id_t em_evt, const p64h_sysc_psm_id_t pid);
p64h_err_t p64h_sysc_ras_em_evt_state_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_em_evt_id_t em_evt, const p64h_sysc_psm_id_t pid,
                                          p64h_sysc_evt_notification_state_t* evt_state_ptr);
p64h_err_t p64h_sysc_ras_em_num_err_srcs_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* const num_err_src_ptr);
p64h_err_t p64h_sysc_ras_em_err_src_id_list_get(const p64h_sysc_handle_t* handle_ptr, uint32_t list_num, p64h_ghes_id_t* const id_list_ptr,
                                                bool shmem_xfer);
p64h_err_t p64h_sysc_ras_em_num_struc_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id, uint32_t* const num_struc_ptr);
p64h_err_t p64h_sysc_ras_em_struc_id_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id, uint32_t list_num,
                                              p64h_ras_generic_struc_id_t* const id_list_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_ras_em_num_struc_inst_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id,
                                               const p64h_ras_generic_struc_id_t struc_id, uint32_t* const num_struc_inst_ptr);
p64h_err_t p64h_sysc_ras_em_ert_log_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id, p64h_sysc_ras_erte_t* const log_ptr,
                                        uint32_t num_entries, uint64_t req_start_off, uint64_t* const resp_start_off, uint32_t* const num_returned);
p64h_err_t p64h_sysc_ras_em_ert_log_clear(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id);
p64h_err_t p64h_sysc_ras_em_table_info_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_acpi_pid_t pid,
                                           p64h_sysc_ras_em_table_t* const table_ptr);
p64h_err_t p64h_sysc_ras_em_num_serial_log_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_serial_logs);
p64h_err_t p64h_sysc_ras_em_serial_log_list_get(const p64h_sysc_handle_t* handle_ptr, uint32_t list_num,
                                                p64h_sysc_ras_em_serial_log_id_t* const log_id_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_ras_em_serial_log_get(const p64h_sysc_handle_t* handle_ptr, uint32_t log_id, p64h_sysc_ras_erte_t* const log_ptr,
                                           uint32_t num_entries, uint64_t req_start_off, uint64_t* const resp_start_off,
                                           uint32_t* const num_returned);
p64h_err_t p64h_sysc_ras_em_serial_log_clear(const p64h_sysc_handle_t* handle_ptr, uint32_t log_id);
p64h_err_t p64h_sysc_ras_em_err_id_num_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id, uint32_t* const num_err_ptr);
p64h_err_t p64h_sysc_ras_em_err_id_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_ghes_id_t err_src_id, uint32_t list_num,
                                            p64h_ras_err_id_t* const err_id_list_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_ras_em_num_err_mon_prof_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* const num_prof_ptr);
p64h_err_t p64h_sysc_ras_em_err_mon_prof_assign(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const uint32_t prof_idx);
p64h_err_t p64h_sysc_ras_em_err_mon_prof_set(const p64h_sysc_handle_t* handle_ptr, const uint32_t prof_idx,
                                             const p64h_sysc_ras_em_prof_t* const prof_ptr);
p64h_err_t p64h_sysc_ras_em_err_mon_prof_get(const p64h_sysc_handle_t* handle_ptr, const uint32_t prof_idx, p64h_sysc_ras_em_prof_t* const prof_ptr);
p64h_err_t p64h_sysc_ras_em_err_filter_set(const p64h_sysc_handle_t* handle_ptr, const uint32_t prof_idx, const p64h_ras_err_id_t err_id,
                                           const bool filter_en);
p64h_err_t p64h_sysc_ras_em_err_filter_get(const p64h_sysc_handle_t* handle_ptr, const uint32_t prof_idx, const p64h_ras_err_id_t err_id,
                                           bool* const filter_en_ptr);

#endif // P64H_SYSC_RAS_EM_H
/// @}
