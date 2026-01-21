/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_version.h
 * @brief Header for system controller version
 * @addtogroup rpmi
 * @{
 */

#ifndef P64H_SYSC_VERSION_H
#define P64H_SYSC_VERSION_H

// API major version
#ifndef P64H_SYSC_FW_VERSION_MAJOR
#define P64H_SYSC_FW_VERSION_MAJOR 2
#endif
// API minor version
#ifndef P64H_SYSC_FW_VERSION_MINOR
#define P64H_SYSC_FW_VERSION_MINOR 0
#endif
// API patch version 
#ifndef P64H_SYSC_FW_VERSION_PATCH
#define P64H_SYSC_FW_VERSION_PATCH 0
#endif

// Bit offset for the major from version values
#define P64H_SYSC_MAJOR_OFFSET (20u)
// Mask to extract the major from version values
#define P64H_SYSC_MAJOR_MASK (0x0fffu << P64H_SYSC_MAJOR_OFFSET)
// Extract the major from version values
#define P64H_SYSC_GET_MAJOR(vers)   (((vers) & P64H_SYSC_MAJOR_MASK) >> P64H_SYSC_MAJOR_OFFSET)
// Bit offset for the minor from version values
#define P64H_SYSC_MINOR_OFFSET (10U)
// Mask to extract the minor from version values
#define P64H_SYSC_MINOR_MASK (0x03ffu << P64H_SYSC_MINOR_OFFSET)
// Extract the minor from version values
#define P64H_SYSC_GET_MINOR(vers)   (((vers) & P64H_SYSC_MINOR_MASK) >> P64H_SYSC_MINOR_OFFSET)
// Mask to extract the patch from version values
#define P64H_SYSC_PATCH_MASK (0x03ffu)
// Extract the patch from version values
#define P64H_SYSC_GET_PATCH(vers)   ((vers) & P64H_SYSC_PATCH_MASK)

// macro that returns build an API version word
#define P64H_SYSC_FW_VERSION(major,minor,patch) ((major << P64H_SYSC_MAJOR_OFFSET) | (minor << P64H_SYSC_MINOR_OFFSET) | (patch))
// macro that returns compiled API version word
#define P64H_SYSC_FW_CURRENT_VERSION P64H_SYSC_FW_VERSION(P64H_SYSC_FW_VERSION_MAJOR, P64H_SYSC_FW_VERSION_MINOR, P64H_SYSC_FW_VERSION_PATCH)
// generic macro to enable an API
#define P64H_SYSC_FW_ENABLE(major,minor,patch) P64H_SYSC_FW_CURRENT_VERSION >= P64H_SYSC_FW_VERSION(major,minor,patch)
// generic macro to disable an API
#define P64H_SYSC_FW_DISABLE(major,minor,patch) P64H_SYSC_FW_CURRENT_VERSION < P64H_SYSC_FW_VERSION(major,minor,patch)

#endif // P64H_SYSC_VERSION_H
/// @}
