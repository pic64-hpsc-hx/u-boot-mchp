/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_system.h
 * @brief System API
 * @addtogroup SYSTEM_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_SYSTEM_H
#define P64H_SYSC_SYSTEM_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_system_types.h>

// sytem event notification interface
p64h_err_t p64h_sysc_sys_evt_enable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid, const p64h_sysc_sys_evt_fct_t sys_evt_fct);
p64h_err_t p64h_sysc_sys_evt_disable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid);
p64h_err_t p64h_sysc_sys_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_sys_evt_id_t eid, bool* enabled_ptr);

p64h_err_t p64h_sysc_sys_info_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_info_t* sys_info_ptr);
p64h_err_t p64h_sysc_sys_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_attr_t* sys_attr_ptr);

p64h_err_t p64h_sysc_sys_log_info_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_sys_log_info_t* log_info_ptr);
p64h_err_t p64h_sysc_sys_log_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_log_id_t lid, const p64h_sysc_sys_log_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_log_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_log_id_t lid, const p64h_sysc_log_destination_t did,
                                     p64h_sysc_sys_log_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_log_data_get(const p64h_sysc_handle_t* handle_ptr, uint64_t requested_read_offset, void* data_buffer,
                                      uint64_t data_buffer_size, uint64_t* resp_offset_ptr, uint32_t* bytes_read_ptr,
                                      uint64_t* current_write_offset_ptr);

p64h_err_t p64h_sysc_sys_appc_boot_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_acot_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_appc_boot_status_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_boot_cfg_id_t bid,
                                              p64h_sysc_appc_boot_cfg_status_t* status_ptr);
p64h_err_t p64h_sysc_sys_appc_boot_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_boot_cfg_id_t bid);

p64h_err_t p64h_sysc_sys_pwr_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pwr_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_pwr_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_pwr_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_pwr_wakeup_trigger(const p64h_sysc_handle_t* handle_ptr);

p64h_err_t p64h_sysc_sys_trace_dev_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_attr_t* attr_ptr);
p64h_err_t p64h_sysc_sys_trace_dev_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_trace_dev_cfg_set(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_trace_dev_cfg_t* cfg_ptr);

p64h_err_t p64h_sysc_sys_fw_pkg_upgrade_upload(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pkg_cfg_t* cfg_ptr, const void* data_ptr,
                                               size_t size, bool shmem_xfer);
p64h_err_t p64h_sysc_sys_fw_pkg_upgrade_apply(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pkg_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_fw_dump(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_dump_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_fw_download(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_dump_cfg_t* cfg_ptr, void* data_ptr, size_t size,
                                     bool shmem_xfer);
p64h_err_t p64h_sysc_sys_fw_dump_status_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_dump_status_t* status_ptr);

p64h_err_t p64h_sysc_sys_time_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_time_t* time_ptr);
p64h_err_t p64h_sysc_sys_time_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_time_t* time_ptr);

p64h_err_t p64h_sysc_sys_pgmrclk_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pgmrclk_id_t clk_id,
                                         const p64h_pgmrclk_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_pgmrclk_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_pgmrclk_id_t clk_id, p64h_pgmrclk_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_cfm_meas_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_cfm_inst_t cfm_inst,
                                          const p64h_sysc_cfm_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_sys_cfm_meas_count_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_cfm_inst_t cfm_inst,
                                            p64h_sysc_cfm_meas_count_t* count_ptr);
p64h_err_t p64h_sysc_sys_fw_pll_cfg_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_fw_pll_cfg_t* fw_pll_cfg_ptr);
p64h_err_t p64h_sysc_sys_fw_pll_timestamp_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_fw_pll_timestamp_t* timestamp_ptr);
p64h_err_t p64h_sysc_sys_dtb_fixup(const p64h_sysc_handle_t* handle_ptr, const uint64_t dtb_addr);
p64h_err_t p64h_sysc_m1_dump(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_m1_dump_t* m1_dump_ptr);
#endif // P64H_SYSC_SYSTEM_H
/// @}
