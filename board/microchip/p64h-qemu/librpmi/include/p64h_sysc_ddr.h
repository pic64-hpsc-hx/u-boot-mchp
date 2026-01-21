/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ddr.h
 * @brief DDR API
 * @addtogroup DDR_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_DDR_H
#define P64H_SYSC_DDR_H

#include <rpmi/librpmi_sysc.h>
#include <generated/p64h_sysc_errors.h>
#include <types/p64h_sysc_ddr_types.h>

p64h_err_t p64h_sysc_ddr_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_ddr_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_ddr_phy_cfg_get(const p64h_sysc_handle_t* handle_ptr, const uint32_t ddr_phy_id, p64h_sysc_ddr_phy_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_ddr_margin_test(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_ddr_margin_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_ddr_margin_report(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_ddr_margin_report_t* report_ptr);
p64h_err_t p64h_sysc_ddr_wr_lvl_debug_sweep(const p64h_sysc_handle_t* handle_ptr, const ddr_ss_phy_training_loc_t* training_loc_ptr, bool* success);
p64h_err_t p64h_sysc_ddr_rdgt_find_tdfi_rddata_en_value(const p64h_sysc_handle_t* handle_ptr, const ddr_ss_phy_training_loc_t* training_loc_ptr,
                                                        bool* success);

#endif // P64H_SYSC_DDR_H
/// @}
