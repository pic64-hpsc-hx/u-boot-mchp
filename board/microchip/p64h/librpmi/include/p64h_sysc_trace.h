/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_trace.h
 * @brief Trace API
 * @addtogroup TRACE_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_TRACE_H
#define P64H_SYSC_TRACE_H

#include <types/p64h_sysc_trace_types.h>
#include <rpmi/librpmi_sysc.h>

// system event notification interface
p64h_err_t p64h_sysc_trace_evt_enable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_trace_evt_id_t eid,
                                      const p64h_sysc_trace_evt_fct_t trace_evt_fct);
p64h_err_t p64h_sysc_trace_evt_disable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_trace_evt_id_t eid);
p64h_err_t p64h_sysc_trace_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_trace_evt_id_t eid,
                                         p64h_sysc_evt_notification_state_t* evt_state_ptr);

p64h_err_t p64h_sysc_trace_sink_num_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t* num_trace_sink_ptr);
p64h_err_t p64h_sysc_trace_sink_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t list_num,
                                         p64h_sysc_trace_sink_id_t* sid_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_trace_sink_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_sink_id_t sid,
                                         p64h_sysc_trace_sink_attr_t* attr_ptr);
p64h_err_t p64h_sysc_trace_sink_config_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_sink_id_t sid,
                                           p64h_sysc_trace_sink_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_sink_config_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_sink_id_t sid,
                                           const p64h_sysc_trace_sink_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_sys_num_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t* num_sys_trace);
p64h_err_t p64h_sysc_trace_sys_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t list_num,
                                        p64h_sysc_sys_trace_id_t* tid, bool shmem_xfer);
p64h_err_t p64h_sysc_trace_sys_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sys_trace_id_t tid,
                                        p64h_sysc_sys_trace_attr_t* attr_ptr);
p64h_err_t p64h_sysc_trace_sys_config_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sys_trace_id_t tid,
                                          p64h_sysc_sys_trace_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_sys_config_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sys_trace_id_t tid,
                                          const p64h_sysc_sys_trace_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_sys_config_execute(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sys_trace_id_t nid,
                                              const p64h_sysc_sys_trace_cfg_t* cfg_ptr);

p64h_err_t p64h_sysc_trace_sw_num_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t* num_sw_trace);
p64h_err_t p64h_sysc_trace_sw_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t list_num,
                                       p64h_sysc_sw_trace_id_t* tid, bool shmem_xfer);
p64h_err_t p64h_sysc_trace_sw_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sw_trace_id_t tid,
                                       p64h_sysc_sw_trace_attr_t* attr_ptr);
p64h_err_t p64h_sysc_trace_sw_config_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sw_trace_id_t tid,
                                         p64h_sysc_sw_trace_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_sw_config_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sw_trace_id_t tid,
                                         const p64h_sysc_sw_trace_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_te_num_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t* num_te_trace);
p64h_err_t p64h_sysc_trace_te_list_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, uint32_t list_num,
                                       p64h_sysc_trace_te_id_t* tid, bool shmem_xfer);
p64h_err_t p64h_sysc_trace_te_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_te_id_t tid,
                                       p64h_sysc_trace_te_attr_t* attr_ptr);
p64h_err_t p64h_sysc_trace_te_config_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_te_id_t tid,
                                         p64h_sysc_trace_te_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_te_config_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_te_id_t tid,
                                         const p64h_sysc_trace_te_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_trace_te_trace_start(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_te_id_t tid);
p64h_err_t p64h_sysc_trace_te_trace_stop(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_te_id_t tid);
p64h_err_t p64h_sysc_trace_data_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_trace_data_type_t type,
                                    uint8_t* trace_buf_ptr, size_t trace_buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_trace_noc_data_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_psm_id_t pid, const p64h_sysc_sys_trace_cfg_t* cfg_ptr,
                                        uint32_t* noc_data_ptr);

#endif // P64H_SYSC_TRACE_H
/// @}
