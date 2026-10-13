/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_psm_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_PSM_TYPE_T
#define P64H_SYSC_PSM_TYPE_T

#include "p64h_sysc_common_types.h"
#include <ba/p64h_sysc_sysc_ba.h>
#include <ba/p64h_sysc_appc_ba.h>

/* Public Structs and Enums --------------------------------------- */

/// partition event identifier
typedef enum {
    P64H_SYSC_PSM_EVT_ID_CHANGE = 1 ///< partition change notification
} p64h_sysc_psm_evt_id_t;

/// partition status
typedef struct {
    p64h_sysc_appc_cfg_state_t boot; ///< boot status
    p64h_sysc_appc_status_t    core; ///< core status
} p64h_sysc_psm_status_t;

/// partition attributes
typedef struct {
    p64h_sysc_appc_cfg_t appc; ///< appc partition configuration
} p64h_sysc_psm_attr_t;

/// partition event
typedef struct {
    p64h_sysc_psm_evt_id_t eid;    ///< event identifier
    p64h_sysc_psm_id_t     pid;    ///< partition identifier
    p64h_sysc_psm_status_t status; ///< parition status
} p64h_sysc_psm_evt_t;

/// function pointer type for PSM event notification
typedef void (*p64h_sysc_psm_evt_fct_t)(const p64h_sysc_psm_evt_t* psm_evt_ptr);

#endif // P64H_SYSC_PSM_TYPE_T
/// @}
