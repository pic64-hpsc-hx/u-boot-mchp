/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_test.h
 * @brief Test API
 * @addtogroup TEST_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_TEST_H
#define P64H_SYSC_TEST_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_test_types.h>

p64h_err_t p64h_sysc_test_num_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_tids);
p64h_err_t p64h_sysc_test_list_get(const p64h_sysc_handle_t* handle_ptr, uint32_t list_num, p64h_sysc_test_utest_type_e* tids, bool shmem_xfer);
p64h_err_t p64h_sysc_test_attr_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_test_utest_type_e tid, p64h_sysc_test_attr_t* attr_ptr);
p64h_err_t p64h_sysc_test_launch(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_test_launch_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_etest_launch(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_etest_launch_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_test_status_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_test_status_t* status_ptr);
p64h_err_t p64h_sysc_test_stop(const p64h_sysc_handle_t* handle_ptr);
p64h_err_t p64h_sysc_test_report_get(const p64h_sysc_handle_t* handle_ptr, const p64h_sysc_test_report_t* report_ptr);
p64h_err_t p64h_sysc_test_reg_op(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_test_reg_op_req_t* reg_op_req_ptr,
                                 p64h_sysc_test_reg_op_resp_t* reg_op_resp_ptr);
p64h_err_t p64h_sysc_test_mem_dump(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_test_mem_dump_req_t* req_ptr,
                                   p64h_sysc_test_mem_dump_resp_t* resp_ptr, bool shmem_xfer);

#endif // P64H_SYSC_TEST_H
/// @}
