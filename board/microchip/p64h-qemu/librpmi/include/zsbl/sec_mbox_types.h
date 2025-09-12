/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines mailbox types & protocol structures used for sending cmd/data between sysc/secc
 */
#ifndef SEC_MBOX_TYPES_H
#define SEC_MBOX_TYPES_H

#include "sec_api_types.h"

/**
 * @def DOWNLOAD_COMPONENT_IMAGE_VERIFY_IN_PLACE
 * @brief Special value to indicate in-place verification.
 *
 * This macro defines a special value to be used as the destination address
 * when performing in-place verification of a component image. When this value
 * is used, the destination address is ignored, and the image verification
 * is performed without transferring the data to a new location.
 *
 * Usage example:
 * @code
 * uint64_t dest_addr = DOWNLOAD_COMPONENT_IMAGE_VERIFY_IN_PLACE;
 * secc_config_validate_impl(src_addr, dest_addr);
 * @endcode
 */
#define DOWNLOAD_COMPONENT_IMAGE_VERIFY_IN_PLACE UINT64_MAX

/**
 * @brief There are 2 mailbox instances.
 *  1) System mbox for communication between SysC & SecC
 *  2) JTAG mbox between JTAG host software & SecC
 */
typedef enum sec_mbox_inst_t
{
    SEC_MBOX_INST_SYSTEM = 0, ///< System MailBox
    SEC_MBOX_INST_JTAG,       ///< Jtag MailBox
    SEC_MBOX_INST_NUM,        ///< Total MailBox instances
} sec_mbox_inst_t;

/**
 * @brief Data Transfer path to be used for the command
 */
typedef enum sec_data_xfer_path_e
{
    SEC_DMA_PATH = 0, ///< Data is transferred using DMA
    SEC_MBOX_PATH,    ///< Mbox RAM memory is used for data transfer
}sec_data_xfer_path_e;

/**
 * @brief Service command request header
 * 
 */
typedef struct sec_mbox_cmd_req_msg_t
{
    uint16_t cmd_opcode;    ///< Crypto Service command
    uint16_t cmd_args;      ///< command arguments
    uint32_t cmd_data_size; ///< Total length of the input buffer passed for the command. 
                            ///< This can be 0 if the command doesn't have to pass input data buffer
    uint64_t dma_src_addr;  ///< source address for DMA data xfer mode
    uint64_t dma_dest_addr; ///< Destination address for DMA data xfer mode
    uint32_t offset;        ///< offset to rd/wr during multi data transfers
    sec_data_xfer_path_e data_xfer_path; ///< specifies the mode of the data xfer(DMA or MBOX)
} sec_mbox_cmd_req_msg_t;

/**
 * @brief Service Response header for command executed
 * 
 */
typedef struct sec_mbox_cmd_resp_msg_t
{
    uint16_t cmd_opcode; ///< Crypto Service command for which the response is being sent
    uint16_t pad;        ///< pad to retain 32b alignment
    uint32_t cmd_exec_status;///< success/fail or the specific error occurred for the executed command
    uint32_t cmd_resp_attr;///< Response attributes containing extended status of the executed command
    uint32_t resp_data_size; ///< Total length of the data received for the command
} sec_mbox_cmd_resp_msg_t;

/// Total JTAG mbox size
#define JTAG_MBOX_SIZE 2048U
/// Total System mbox size
#define SYSTEM_MBOX_SIZE 2048U

/// Total data buffer size in bytes possible to be transferred each time
// cppcheck-suppress-macro [misra-config] - suppress error that type just above can't be found
#define MBOX_MAX_BUFF_SIZE  (JTAG_MBOX_SIZE - (sizeof(sec_mbox_cmd_req_msg_t) + sizeof(sec_mbox_cmd_resp_msg_t)))


/**
 * @brief 2KB Mailbox ram for saving command, response, user & reply buffers
 */
typedef struct sec_mbox_ram_t
{
    sec_mbox_cmd_req_msg_t  cmd_req_buffer_st;  ///< message from APB1 to APB2 mbox RAM space
    sec_mbox_cmd_resp_msg_t cmd_resp_buffer_st;///< message from APB2 to APB1 mbox RAM space
    uint8_t buffer_data[MBOX_MAX_BUFF_SIZE];///< Data to be passed with request/response buffer
}sec_mbox_ram_t;

#endif /* SEC_MBOX_TYPES_H */
