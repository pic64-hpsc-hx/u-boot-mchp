/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_log_print.h
 * @brief Log Data Printing and Decoding API
 * @addtogroup LOG_PRINT_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_LOG_PRINT_H
#define P64H_SYSC_LOG_PRINT_H

#include <generated/p64h_sysc_errors.h>
#include <generated/p64h_sysc_logs.h>
#include <types/p64h_sysc_system_types.h>
#include "p64h_sysc_diag_lib.h"

/**
 * @brief Response log data printer
 *
 * @param[in] log_ptr Pointer to the log data response structure.
 * @param[in] options_ptr Pointer to option for info
 * @return p64h_err_t Returns P64H_ERR_OK on success.
 */
p64h_err_t p64h_sysc_trans_log(const p64h_sysc_sys_log_data_resp_t* log_ptr, const p64h_sysc_info_options_t* options_ptr);

#endif // P64H_SYSC_LOG_PRINT_H
/// @}
