/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_er_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_ER_TYPE_H
#define P64H_SYSC_RAS_ER_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>

/* Public Defines ------------------------------------------------- */

/* Public Structs and Enums --------------------------------------- */

/// Enum listing all possible notifications supported by the ER RAS service
typedef enum {
    P64H_SYSC_RAS_ER_NOTIF_EVT_ERROR_RESPONSE = 0, ///< Error response notification ID
    P64H_SYSC_RAS_ER_NOTIF_EVT_LAST                ///< Last ID
} p64h_sysc_ras_er_evt_id_t;

/// RAS ER notification state
typedef enum {
    RAS_EE_EVT_ACTIVE   = 0, ///< Notification event ID
    RAS_EE_EVT_INACTIVE = 1, ///< Notification event ID
} p64h_sysc_ras_er_evt_state_t;

/// RAS ER notification event received
typedef struct {
    p64h_sysc_ras_er_evt_id_t evt_id;       ///< Notification event ID
    p64h_sysc_psm_id_t        partition_id; ///< Partition ID for which notification events should be enabled
    /// cperlite #
    /// error response
} p64h_sysc_ras_er_evt_t;

/// Description of the attributes available for a specific error response
typedef struct {
    uint32_t placeholder; ///< Placeholder for error response attributes
} p64h_sysc_ras_er_attr_desc_t;

/// Data specific to an error response. Used to trigger an error response
typedef struct {
    uint32_t placeholder; ///< Placeholder for error response attributes
} p64h_sysc_ras_er_attr_t;

/// Error response profile
typedef struct {
    uint32_t placeholder; ///< Placeholder for error response profile
} p64h_sysc_ras_er_prof_t;
/// function pointer type for RAS ER event notification
typedef void (*p64h_sysc_ras_er_evt_fct_t)(const p64h_sysc_ras_er_evt_t* ras_er_evt_ptr);

#endif // P64H_SYSC_RAS_ER_TYPE_H
/// @}
