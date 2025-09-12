/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_errinj_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_ERRINJ_TYPE_H
#define P64H_SYSC_RAS_ERRINJ_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>

/* Public Defines ------------------------------------------------- */

/* Public Structs and Enums --------------------------------------- */

/// Description of attributes for a specific error injection
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for an error injection
} p64h_sysc_ras_errinj_attr_desc_t;

/// Attributes for the description of a specific error injection. Used to trigger an error injection
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for an error injection
} p64h_sysc_ras_errinj_attr_t;

#endif // P64H_SYSC_RAS_ERRINJ_TYPE_H
/// @}
