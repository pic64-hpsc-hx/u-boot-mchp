/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

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
p64h_err_t p64h_sysc_ddr_do_cdns_bist(const p64h_sysc_handle_t* handle_ptr, const ddr_ss_bist_ctrl_info_t* bist_ctrl_info_ptr,
                                      const ddr_ss_bist_result_info_t* bist_results_ptr);
p64h_err_t p64h_sysc_ddr_do_stress_test(const p64h_sysc_handle_t* handle_ptr, const ddr_ss_test_ctrl_info_t* test_ctrl_info_ptr,
                                        const ddr_ss_test_result_info_t* test_results_ptr);
p64h_err_t p64h_sysc_ddr_do_dq_tx_sweep(const p64h_sysc_handle_t* handle_ptr, const ddr_dq_sweep_ctrl_t* ddr_dq_sweep_ctrl_ptr,
                                        ddr_dq_sweep_result_t* ddr_dq_sweep_result_ptr);
p64h_err_t p64h_sysc_ddr_do_dq_rx_sweep(const p64h_sysc_handle_t* handle_ptr, const ddr_dq_sweep_ctrl_t* ddr_dq_sweep_ctrl_ptr,
                                        ddr_dq_sweep_result_t* ddr_dq_sweep_result_ptr);
p64h_err_t p64h_sysc_ddr_training_data_get(const p64h_sysc_handle_t* handle_ptr, const uint32_t ddr_phy_id,
                                           ddr_ss_phy_training_result_per_intf_t* cfg_ptr);

#endif // P64H_SYSC_DDR_H
/// @}
