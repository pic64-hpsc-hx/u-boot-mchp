/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

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
#include <rpmi/librpmi_sysc.h>

p64h_err_t p64h_sysc_nvm_if_num_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_nvm_ifs);
p64h_err_t p64h_sysc_nvm_if_list_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_nvm_if_id_t* nids, bool shmem_xfer);
p64h_err_t p64h_sysc_nvm_if_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_nvm_if_id_t nid, p64h_sysc_nvm_if_attr_t* attr_ptr);
p64h_err_t p64h_sysc_nvm_if_cfg_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_nvm_if_id_t nid, p64h_sysc_nvm_if_cfg_t* cfg_ptr);

#endif // P64H_SYSC_NVM_H
/// @}
