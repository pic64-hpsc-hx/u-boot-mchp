/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Ventana Micro Systems Inc.
 */

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
enum rpmi_error rpmi_io_read(struct rpmi_io* io, void* in, rpmi_uint32_t len)
{
    if (!io || !in) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }

    return io->ops->read(io->ops_priv, in, len);
}

enum rpmi_error rpmi_io_write(struct rpmi_io* io, const void* out, rpmi_uint32_t len)
{
    if (!io || !out) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    return io->ops->write(io->ops_priv, out, len);
}

enum rpmi_error rpmi_io_flush_rx(struct rpmi_io* io)
{
    if (!io) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    return io->ops->flush_rx(io->ops_priv);
}

rpmi_bool_t rpmi_io_is_empty(struct rpmi_io* io)
{
    if (!io) {
        DPRINTF("%s: invalid parameters\n", __func__);
        return RPMI_ERR_INVALID_PARAM;
    }
    return io->ops->is_empty(io->ops_priv);
}
