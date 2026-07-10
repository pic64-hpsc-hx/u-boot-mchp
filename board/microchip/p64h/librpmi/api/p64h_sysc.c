/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc.c
 * @brief SysC API implementation
 * @addtogroup SYSC_API
 * @ingroup p64h_sysc
 * @{
 */

#include <env/p64h_sysc_os_specific.h>
#include "p64h_sysc.h"
#include <rpmi/librpmi.h>

/* Private Defines ------------------------------------------------ */

/* Private Variables ---------------------------------------------- */
/**
 * @brief Pointer to RPMI context for handling RPMI messages
 */
static p64h_sysc_handle_t* rpmi_handle_ptr = NULL;

/* Private Function Definitions ----------------------------------- */

/* Public Function Definitions ------------------------------------ */

/**
 * @brief Retrieve a handle to the P64H system controller.
 *
 * This function returns a pointer to a p64h_sysc_handle_t structure,
 * which can be used to interact with the P64H system controller.
 *
 * @param[out] handle_pptr  Address of a pointer to a p64h_sysc_handle_t instance.
 * @return p64h_err_t Status code indicating the result of the operation
 */
p64h_err_t p64h_sysc_handle_get(p64h_sysc_handle_t** handle_pptr)
{
    P64H_SYSC_ASSERT(NULL != handle_pptr, P64H_ERR_LIB_API_NULL_POINTER);

    p64h_err_t rc = P64H_ERR_OK;
    if (NULL == rpmi_handle_ptr) {
        rpmi_handle_ptr = (p64h_sysc_handle_t*)rpmi_ctxt_malloc();
    }

    if (rpmi_handle_ptr) {
        *handle_pptr = rpmi_handle_ptr;
    } else {
        rc = P64H_ERR_LIB_API_NULL_POINTER;
    }

    return rc;
}

/**
 * @brief Compare current version with system's.
 *
 * @param[in] sysc_ver  - Pointer to version got from RPMI.
 * @param[in] exp_vers  - Version stored while compiling this module.
 * @return p64h_err_t Error code indicating the result of the version check.
 */
p64h_err_t p64h_sysc_version_check(p64h_sysc_sys_version_t* sysc_ver, uint32_t exp_vers)
{
    P64H_SYSC_ASSERT(NULL != sysc_ver, P64H_ERR_LIB_API_NULL_POINTER);

    // Extracting version values
    uint32_t sysc_version = P64H_SYSC_FW_VERSION(sysc_ver->major, sysc_ver->minor, sysc_ver->patch);

    if (sysc_version == exp_vers) {
        return P64H_ERR_OK;
    } else {
        if ((sysc_version != 0) && (exp_vers == 0)) {
            return P64H_ERR_OK;
        } else if ((sysc_version == 0) && (exp_vers != 0)) {
            return P64H_ERR_OK;
        }
    }
    return P64H_ERR_LIB_API_VERSION_MISMATCH;
} // p64h_sysc_version_check

/**
 * @brief Initializes the shared memory system configuration.
 *
 * This function sets up the shared memory system based on the provided configuration.
 *
 * @param[in] cfg_ptr Pointer to the shared memory configuration structure.
 * @param[out] handle_pptr  Address of a pointer that will receive the handle to the initialized interface.
 * @return p64h_err_t Error code indicating the result of the initialization.
 */
p64h_err_t p64h_sysc_rpmi_shmem_init(const p64h_sysc_rpmi_shmem_cfg_t* cfg_ptr, p64h_sysc_handle_t** handle_pptr)
{
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(NULL != handle_pptr, P64H_ERR_LIB_API_NULL_POINTER);

    p64h_err_t           rc       = P64H_ERR_OK;
    p64h_sysc_rpmi_cfg_t rpmi_cfg = { 0 };

    rc                            = p64h_sysc_handle_get(handle_pptr);
    if (P64H_ERR_OK == rc) {
        rpmi_cfg.type = RPMI_TRANS_SHMEM;
        rpmi_cfg.role = RPMI_ROLE_A;
        rpmi_env_memcpy((void*)&rpmi_cfg.mem, &cfg_ptr->mem, sizeof(cfg_ptr->mem));

        if (!p64h_sysc_rpmi_handle_init(*handle_pptr, &rpmi_cfg)) {
            rc = P64H_ERR_LIB_API_SHMEM_INIT_FAIL;
        }
    }

    if (P64H_ERR_OK == rc) {
        // IPC message callback function
        if (!p64h_sysc_rpmi_ipc_init(*handle_pptr, &cfg_ptr->ops)) {
            rc = P64H_ERR_LIB_API_IPC_INIT_FAIL;
        }
    }

    /* disable version check for 2.0.1 release*/
    /*
    if (P64H_ERR_OK == rc) {
        p64h_sysc_sys_info_t sys_info;
        rc = p64h_sysc_sys_info_get(*handle_pptr, &sys_info);
        if (P64H_ERR_OK == rc) {
            rc = p64h_sysc_version_check(&sys_info.fw_version, P64H_SYSC_FW_CURRENT_VERSION);
        }
    }
    */

    return rc;
}

/**
 * @brief Initializes the remote system controller with the given configuration.
 *
 * This function sets up the remote system controller using the provided configuration
 * parameters. It is essential to call this function before any other remote system
 * controller operations are performed.
 *
 * @param[in] cfg_ptr Pointer to the configuration structure for the remote system controller.
 * @param[out] handle_pptr Address of a pointer that will receive the handle to the initialized interface.
 *
 * @return p64h_err_t Error code indicating the success or failure of the initialization.
 */
p64h_err_t __attribute__((weak)) p64h_sysc_rpmi_remote_init(const p64h_sysc_rpmi_remote_cfg_t* cfg_ptr, p64h_sysc_handle_t** handle_pptr)
{
    P64H_SYSC_ASSERT(NULL != cfg_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    P64H_SYSC_ASSERT(NULL != handle_pptr, P64H_ERR_LIB_API_NULL_POINTER);

    p64h_err_t           rc = P64H_ERR_OK;
    p64h_sysc_sys_info_t sys_info;
    rc = p64h_sysc_handle_get(handle_pptr);
    if (P64H_ERR_OK == rc) {
        rc = p64h_sysc_sys_info_get(*handle_pptr, &sys_info);
    }
    if (P64H_ERR_OK == rc) {
        rc = p64h_sysc_version_check(&sys_info.fw_version, P64H_SYSC_FW_CURRENT_VERSION);
    }

    return rc;
}

/**
 * @brief Uninitialize the remote system controller with the given handle
 *
 * @param[in] handle_ptr Pointer to the system controller handle.
 *
 * @return p64h_err_t Error code indicating the success or failure of the uninitialization.
 */
p64h_err_t __attribute__((weak)) p64h_sysc_rpmi_remote_uninit(p64h_sysc_handle_t* handle_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);
    p64h_sysc_rpmi_handle_uninit(handle_ptr);
    return P64H_ERR_OK;
}

/**
 * @brief Polls for notifications from system controller.
 *
 * This function checks for any pending notifications from the system controller
 * and processes them accordingly. It should be called periodically to ensure timely
 * handling of events and messages from the system controller.
 *
 * @param[in] handle_ptr Pointer to the system controller handle.
 *
 * @return p64h_err_t Error code indicating the success or failure of the polling operation.
 */
p64h_err_t p64h_sysc_rpmi_notification_poll(p64h_sysc_handle_t* handle_ptr)
{
    P64H_SYSC_ASSERT(NULL != handle_ptr, P64H_ERR_LIB_API_NULL_POINTER);

    if (p64h_sysc_rpmi_notification_check(handle_ptr)) {
        return P64H_ERR_OK;
    } else {
        return P64H_ERR_RPMSG_FAIL;
    }
}

/// @}
