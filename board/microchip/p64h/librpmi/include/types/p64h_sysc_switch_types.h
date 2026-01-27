/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines test types used by API, dev_cfg tool and sysc firmware
 */

#ifndef P64H_SYSC_SWITCH_TYPES_H
#define P64H_SYSC_SWITCH_TYPES_H

#include <env/p64h_sysc_os_specific.h>

// Numbers from RFC-7252
#define RPMI_COAP_PAYLOAD_MIN_SIZE (4U)    // Minimum CoAP header.
#define RPMI_COAP_PAYLOAD_MAX_SIZE (1152U) // Maximum CoAP payload + header

/// coap message
typedef struct {
    uint64_t coap_ctx;                            ///< coap context
    uint16_t length;                              ///< lenght of the payload
    uint8_t  payload[RPMI_COAP_PAYLOAD_MAX_SIZE]; ///< coap payload
} p64h_sysc_switch_coap_msg_t;

/**
 * @brief
 *  Enumeration of Switch dump layer
 */
typedef enum {
    P64H_SYSC_SWITCH_DUMP_LAYER_ALL, // All layers
    P64H_SYSC_SWITCH_DUMP_LAYER_AIL, // Application Interface Layer
    P64H_SYSC_SWITCH_DUMP_LAYER_CIL  // Chip Interface Layer
} p64h_sysc_switch_dump_layer_t;

/**
 * @brief
 *  Enumeration of Switch dump group
 */
typedef enum {
    P64H_SYSC_SWITCH_DUMP_GROUP_ALL,
    P64H_SYSC_SWITCH_DUMP_GROUP_INIT,
    P64H_SYSC_SWITCH_DUMP_GROUP_MISC,
    P64H_SYSC_SWITCH_DUMP_GROUP_PORT,
    P64H_SYSC_SWITCH_DUMP_GROUP_CNT,
    P64H_SYSC_SWITCH_DUMP_GROUP_PHY,
    P64H_SYSC_SWITCH_DUMP_GROUP_MAC_TABLE,
    P64H_SYSC_SWITCH_DUMP_GROUP_VLAN,
    P64H_SYSC_SWITCH_DUMP_GROUP_VX,
    P64H_SYSC_SWITCH_DUMP_GROUP_AGGR,
    P64H_SYSC_SWITCH_DUMP_GROUP_STP,
    P64H_SYSC_SWITCH_DUMP_GROUP_MIRROR,
    P64H_SYSC_SWITCH_DUMP_GROUP_PVLAN,
    P64H_SYSC_SWITCH_DUMP_GROUP_QOS,
    P64H_SYSC_SWITCH_DUMP_GROUP_PACKET,
    P64H_SYSC_SWITCH_DUMP_GROUP_WM,
    P64H_SYSC_SWITCH_DUMP_GROUP_L3,
    P64H_SYSC_SWITCH_DUMP_GROUP_ACL,
} p64h_sysc_switch_dump_group_t;

/**
 * @brief
 *  TBD
 */
typedef struct {
    p64h_sysc_switch_dump_layer_t layer;        // Lyer
    p64h_sysc_switch_dump_group_t group;        // Group
    uint32_t                      port_mask;    // Ports
    bool                          action_valid; // Action valid flag
    uint8_t                       action;       // Action number
    bool                          full;         // Detailed dump
    bool                          clear;        // Clear
} p64h_sysc_switch_dump_msg_t;

#endif // P64H_SYSC_SWITCH_TYPES_H
