/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_switch.h
 * @brief ENET switch API
 * @addtogroup SWITCH_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_SWITCH_H
#define P64H_SYSC_SWITCH_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_switch_types.h>

p64h_err_t p64h_sysc_switch_coap_msg_send(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_switch_coap_msg_t* req,
                                          p64h_sysc_switch_coap_msg_t* resp);
p64h_err_t p64h_sysc_switch_dump_msg_send(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_switch_dump_msg_t* req);

#endif // P64H_SYSC_SWITCH_H
/// @}
