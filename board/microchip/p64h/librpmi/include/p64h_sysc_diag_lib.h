/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_lib.h
 * @brief RAS Error Decoding API (parse/decode cperlite)
 * @addtogroup RAS_LIB_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_DIAG_LIB_H
#define P64H_SYSC_DIAG_LIB_H

#include <generated/p64h_sysc_errors.h>
#include <types/p64h_sysc_ddr_types.h>
#include <types/p64h_sysc_nvm_types.h>
#include <generated/p64h_sysc_lsio_defs.h>
#include <types/p64h_sysc_serdes_types.h>
#include <types/p64h_sysc_system_types.h>
#include <types/p64h_sysc_ras_health_types.h>
#include "ras/p64h_acpi_tables.h"
#include "generated/p64h_sysc_ras_data_defs.h"
#include <types/p64h_sysc_psm_types.h>
#include "p64h_sysc.h"

/// info options
typedef struct {
    bool  no_stdout;                         ///< no stdout
    bool  file_output;                       ///< output to file
    char  output_path[P64H_SYSC_STRING_MAX]; ///< filepath to output
    char* mode;                              ///< file access mode
    bool  verbose;                           ///< verbose mode
} p64h_sysc_info_options_t;

/// print config
typedef struct {
    bool     verbose;
    bool     no_stdout;
    FILE*    file;
    uint32_t indent_depth;
    char*    indent_string;
    bool     indent;
} p64h_sysc_env_print_t;

void       p64h_sysc_env_print(const p64h_sysc_env_print_t* env_print_ptr, const char* format, ...);

p64h_err_t p64h_sysc_ddr_info(const p64h_sysc_ddr_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_ddr_phy_info(const uint32_t ddr_phy_id, const p64h_sysc_ddr_phy_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_lsio_info(const p64h_sysc_lsio_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_nvm_cfg_info(const p64h_sysc_nvm_cpair_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_nvm_device_info(const p64h_sysc_nvm_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_nvm_diag(const p64h_sysc_nvm_diag_test_t* diag_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_serdes_info(const p64h_sysc_serdes_grp_attr_t* attr_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_serdes_diag(const p64h_sysc_serdes_grp_diag_t* diag_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_sys_info(const p64h_sysc_sys_info_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_pgmrclk_cfg_info(const p64h_pgmrclk_cfg_t* cfg_ptr, const uint32_t clk_id, const bool bypass,
                                      const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_acot_entry_info(const p64h_sysc_acot_entry_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_appc_boot_cfg_info(const p64h_sysc_acot_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_ras_err_decode_cper_to_buf(const p64h_acpi_hest_generic_data_v300_t* rec, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_ras_err_decode_erte_to_buf(const p64h_sysc_ras_erte_t* log_ptr, uint32_t num_entries,
                                                const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_ras_mem_scrubber_info(const p64h_sysc_mem_scrubber_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_fw_pll_sup_info(const p64h_sysc_fw_pll_timestamp_t* timestamp_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_cfm_count_info(const p64h_sysc_cfm_meas_count_t* count_ptr, const p64h_sysc_cfm_inst_t cfm_inst,
                                    const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_log_cfg_info(const p64h_sysc_sys_log_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_m1_dump_info(const p64h_sysc_m1_dump_t* m1_info_ptr, const p64h_sysc_info_options_t* options_ptr);

p64h_err_t p64h_sysc_psm_status_info(const p64h_sysc_psm_id_t pid, const p64h_sysc_psm_status_t* status_ptr,
                                     const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_psm_attr_info(const p64h_sysc_psm_id_t pid, const p64h_sysc_psm_attr_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_sys_log_info(const p64h_sysc_sys_log_info_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_pwr_info(const p64h_sysc_pwr_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);

p64h_err_t p64h_sysc_ras_bert_print(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_acpi_pid_t pid,
                                    const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_ras_hest_print(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_acpi_pid_t pid,
                                    const p64h_sysc_info_options_t* options_ptr);

p64h_err_t p64h_sysc_appc_boot_cfg_status_info(const p64h_sysc_appc_boot_cfg_status_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
#endif // P64H_SYSC_RAS_LIB_H
/// @}
