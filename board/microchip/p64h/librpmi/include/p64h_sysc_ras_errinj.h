/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_ras_errinj.h
 * @brief RAS Error Injection API
 * @addtogroup RAS_ERRINJ_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_ERRINJ_H
#define P64H_SYSC_RAS_ERRINJ_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_ras_errinj_types.h>

p64h_err_t p64h_sysc_ras_errinj_num_get(const p64h_sysc_handle_t* handle_ptr, p64h_ghes_id_t err_src_id, uint32_t* const num_inj_err_ptr);
p64h_err_t p64h_sysc_ras_errinj_id_list_get(const p64h_sysc_handle_t* handle_ptr, p64h_ghes_id_t err_src_id, uint32_t list_num,
                                            p64h_ras_err_id_t* const id_list_ptr, bool shmem_xfer);
p64h_err_t p64h_sysc_ras_errinj_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_ras_err_id_t errinj_id,
                                         p64h_sysc_ras_einj_attrs_t* const attr_desc_ptr);
p64h_err_t p64h_sysc_ras_errinj_trigger(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_ras_einj_code_t errinj_id,
                                        const p64h_sysc_ras_einj_params_t* const attr_ptr);

#endif // P64H_SYSC_RAS_ERRINJ_H
/// @}
