/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_lsio.h
 * @brief LSIO API
 * @addtogroup LSIO_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_LSIO_H
#define P64H_SYSC_LSIO_H

#include <generated/p64h_sysc_lsio_defs.h>
#include <rpmi/librpmi_sysc.h>

p64h_err_t p64h_sysc_lsio_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_lsio_cfg_t* cfg_ptr);

#endif // P64H_SYSC_LSIO_H
/// @}
