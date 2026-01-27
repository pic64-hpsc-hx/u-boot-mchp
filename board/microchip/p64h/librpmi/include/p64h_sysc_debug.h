/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_debug.h
 * @brief Debug API
 * @addtogroup DEBUG_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_DEBUG_H
#define P64H_SYSC_DEBUG_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_debug_types.h>

p64h_err_t p64h_sysc_debug_mem_read(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_dm_id_t did, const uint64_t addr, uint8_t* data_ptr,
                                    const uint32_t data_size);
p64h_err_t p64h_sysc_debug_mem_write(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_dm_id_t did, const uint64_t addr, const uint8_t* data_ptr,
                                     const uint32_t data_size);
p64h_err_t p64h_sysc_debug_csr_read(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_dm_id_t did, const uint32_t csr_id, uint64_t* data_ptr);
p64h_err_t p64h_sysc_debug_csr_write(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_dm_id_t did, const uint32_t csr_id, const uint64_t data);

#endif // P64H_SYSC_DEBUG_H
/// @}
