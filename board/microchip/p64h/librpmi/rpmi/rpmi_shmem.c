/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

#include <env/p64h_sysc_os_specific.h>
#include <rpmi/librpmi.h>

/* Private Defines ------------------------------------------------ */
#undef DEBUG

#ifdef DEBUG
#define DPRINTF(msg...) rpmi_env_printf(msg)
#else
#define DPRINTF(msg...)
#endif

/* Private Structs and Enums -------------------------------------- */
/* Private Variables ---------------------------------------------- */
/* Prototypes ----------------------------------------------------- */
/* Private Function Definitions ----------------------------------- */
/* Public Function Definitions ------------------------------------ */
rpmi_uint64_t rpmi_shmem_base(const struct rpmi_shmem* shmem)
{
    return (shmem) ? shmem->base : 0;
}

rpmi_uint32_t rpmi_shmem_size(const struct rpmi_shmem* shmem)
{
    return (shmem) ? shmem->size : 0;
}

enum rpmi_error rpmi_shmem_read(struct rpmi_shmem* shmem, rpmi_uint64_t offset, void* in, rpmi_uint32_t len)
{
    if (!shmem || !in) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    if ((offset + len) > shmem->size) {
        DPRINTF("%s: %s: invalid offset 0x%lx or len 0x%x\n", __func__, shmem->name, offset, len);
        return RPMI_ERR_BAD_RANGE;
    }
    return shmem->ops->read(shmem->ops_priv, shmem->base + offset, in, len);
}

enum rpmi_error rpmi_shmem_write(struct rpmi_shmem* shmem, rpmi_uint64_t offset, const void* out, rpmi_uint32_t len)
{
    if (!shmem || !out) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    if ((offset + len) > shmem->size) {
        DPRINTF("%s: %s: invalid offset 0x%lx or len 0x%x\n", __func__, shmem->name, offset, len);
        return RPMI_ERR_BAD_RANGE;
    }
    return shmem->ops->write(shmem->ops_priv, shmem->base + offset, out, len);
}

enum rpmi_error rpmi_shmem_fill(struct rpmi_shmem* shmem, rpmi_uint64_t offset, char ch, rpmi_uint32_t len)
{
    if (!shmem) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    if ((offset + len) > shmem->size) {
        DPRINTF("%s: %s: invalid offset 0x%lx or len 0x%x\n", __func__, shmem->name, offset, len);
        return RPMI_ERR_BAD_RANGE;
    }
    return shmem->ops->fill(shmem->ops_priv, shmem->base + offset, ch, len);
}
