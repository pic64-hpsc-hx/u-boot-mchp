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

/// info options
typedef struct {
    bool no_stdout;                         ///< no stdout
    bool file_output;                       ///< output to file
    char output_path[P64H_SYSC_STRING_MAX]; ///< filepath to output
    bool verbose;                           ///< verbose mode
} p64h_sysc_info_options_t;

p64h_err_t p64h_sysc_ddr_info(const p64h_sysc_ddr_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_lsio_info(const p64h_sysc_lsio_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_nvm_cfg_info(const p64h_sysc_nvm_cpair_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_nvm_device_info(const p64h_sysc_nvm_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_serdes_info(const p64h_sysc_serdes_grp_attr_t* attr_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_serdes_diag(const p64h_sysc_serdes_grp_diag_t* diag_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_sys_info(const p64h_sysc_sys_info_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_sys_attr(const p64h_sysc_sys_attr_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_pgmrclk_cfg_info(const p64h_pgmrclk_cfg_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_acot_entry_info(const p64h_sysc_acot_entry_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);
p64h_err_t p64h_sysc_appc_boot_cfg_info(const p64h_sysc_acot_t* cfg_ptr, const p64h_sysc_info_options_t* options_ptr);

#endif // P64H_SYSC_RAS_LIB_H
/// @}
