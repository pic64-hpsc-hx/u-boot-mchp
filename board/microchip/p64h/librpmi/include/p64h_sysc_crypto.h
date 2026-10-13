/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_crypto.h
 * @brief CRYPTO API
 * @addtogroup CRYPTO_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_CRYPTO_H
#define P64H_SYSC_CRYPTO_H

#include <rpmi/librpmi_sysc.h>
#include <generated/p64h_sysc_errors.h>
#include <types/p64h_sysc_crypto_types.h>

p64h_err_t p64h_sysc_crypto_evt_enable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_evt_id_t eid,
                                       const p64h_sysc_crypto_evt_fct_t sys_evt_fct);
p64h_err_t p64h_sysc_crypto_evt_disable(p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_evt_id_t eid);
p64h_err_t p64h_sysc_crypto_evt_state_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_evt_id_t eid,
                                          p64h_sysc_evt_notification_state_t* evt_state_ptr);

// key management
p64h_err_t p64h_sysc_crypto_key_num_get(const p64h_sysc_handle_t* handle_ptr, const bool get_configured, uint32_t* num_key_ptr);
p64h_err_t p64h_sysc_crypto_key_list_get(const p64h_sysc_handle_t* handle_ptr, const bool get_configured, uint32_t list_num,
                                         p64h_sysc_crypto_key_id_t* kids_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_crypto_key_set(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_key_id_t key_id,
                                    const p64h_sysc_crypto_key_cfg_t* cfg_ptr);

// operation
p64h_err_t p64h_sysc_crypto_sha(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_sha_op_t* op_ptr, p64h_sysc_crypto_hash_t* sha_ptr);
p64h_err_t p64h_sysc_crypto_aes(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_aes_op_t* op_ptr);
p64h_err_t p64h_sysc_crypto_sign(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_crypto_sign_op_t* op_ptr);

#endif // P64H_SYSC_CRYPTO_H
/// @}
