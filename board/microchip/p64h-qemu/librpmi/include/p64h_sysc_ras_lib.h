/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_lib.h
 * @brief RAS Error Decoding API (parse/decode cperlite)
 * @addtogroup RAS_LIB_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_LIB_H
#define P64H_SYSC_RAS_LIB_H

#include "ras/p64h_acpi_tables.h"
#include "generated/p64h_sysc_ras_data_defs.h"

uint32_t p64h_sysc_ras_err_decode_cper_to_buf(const p64h_acpi_hest_generic_data_v300_t* rec, uint8_t* buf, size_t bufsize);
void     p64h_sysc_ras_err_decode_erte_to_buf(const p64h_sysc_ras_erte_t* rec, size_t num_entries);

#endif // P64H_SYSC_RAS_LIB_H
/// @}
