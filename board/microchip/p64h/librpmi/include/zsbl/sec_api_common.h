/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines sec API available from JTAG and system mailbox
 */
#ifndef SEC_API_COMMON_H
#define SEC_API_COMMON_H

#include "sec_mbox_types.h"

/**
 * @brief
 *  Construct the command request message structure for mbox data transfer
 * @param[out] pCmd_req_msg_st - ptr to cmd request msg structure to fill the attributes
 * @param[in]  cmd             - command opcode
 * @param[in]  cmd_args        - command arguments
 * @param[in]  cmd_data_size   - size of payload for the command
 * @param[in]  offset          - offset used when transferring multi-blocks of data
 */
static inline void sec_build_mbox_req_msg(sec_mbox_cmd_req_msg_t *pCmd_req_msg_st, uint16_t cmd,
                                          uint16_t cmd_args, uint32_t cmd_data_size, uint32_t offset)
{
    // Fill the mailbox command message structure with the required attributes for mbox data transfer
    pCmd_req_msg_st->cmd_opcode = cmd;
    pCmd_req_msg_st->cmd_args   = cmd_args;
    pCmd_req_msg_st->cmd_data_size = cmd_data_size;
    pCmd_req_msg_st->offset = offset;
    // dma src/dest fields are not used for JTAG mbox path
    pCmd_req_msg_st->dma_src_addr = 0;
    pCmd_req_msg_st->dma_dest_addr = 0;
    // Data transfer path over JTAG is always over mbox
    pCmd_req_msg_st->data_xfer_path = SEC_MBOX_PATH;
} // sec_build_mbox_req_msg


#endif /* SEC_API_COMMON_H */
