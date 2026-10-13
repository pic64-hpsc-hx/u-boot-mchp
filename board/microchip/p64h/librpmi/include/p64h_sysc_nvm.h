/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_nvm.h
 * @brief NVM API
 * @addtogroup NVM_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_NVM_H
#define P64H_SYSC_NVM_H

#include <types/p64h_sysc_nvm_types.h>
#include <ba/p64h_sysc_board_ba.h>
#include <rpmi/librpmi_sysc.h>

p64h_err_t p64h_sysc_nvm_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_nvm_if_id_t nid, p64h_sysc_nvm_cpair_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_nvm_device_get(const p64h_sysc_handle_t* handle_ptr, const uint32_t nid, p64h_sysc_nvm_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_nvm_diag_test(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_nvm_if_id_t nid, const uint32_t test_mask,
                                   p64h_sysc_nvm_diag_test_t* diag_test_ptr);

#endif // P64H_SYSC_NVM_H
/// @}
