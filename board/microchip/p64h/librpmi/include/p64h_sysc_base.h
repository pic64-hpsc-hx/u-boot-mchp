/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_base.h
 * @brief Base API
 * @addtogroup BASE_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_BASE_H
#define P64H_SYSC_BASE_H

#include <rpmi/librpmi_sysc.h>

p64h_err_t p64h_sysc_sys_service_probe(const p64h_sysc_handle_t* handle_ptr, const uint32_t group_id, const uint32_t service_id);
#endif // P64H_SYSC_BASE_H
/// @}
