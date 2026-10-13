/* (c) 2022 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */
#ifndef P64H_SYSC_MATH_H
#define P64H_SYSC_MATH_H
/**
 * @file p64h_sysc_math.h
 * @brief
 * Common math macros and functions
 */
#ifndef DIV_ROUND_UP
#define DIV_ROUND_UP(n, d) (((n) + (d)-1) / (d)) ///< divide round up
#endif

#ifndef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y)) ///< max
#endif

#ifndef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y)) ///< min
#endif

#ifndef ALIGN
#define ALIGN(addr, size) (((uint64_t)addr) + (((uint64_t)size) - 1) & ~(((uint64_t)size) - 1))
#endif

#define INGR_TO_EGR_OFFSET(ingr_beats, egr_beats, ingr_offset) (((uint64_t)(ingr_offset) * egr_beats) / (uint64_t)ingr_beats)

#define EGR_TO_INGR_OFFSET(ingr_beats, egr_beats, egr_offset)  (((uint64_t)(egr_offset) * ingr_beats) / (uint64_t)egr_beats)

#define FIXED_WR_INGR_BYTE_OFFSET_FIND(ingr_beats, egr_beats, desired_egr_byte_offset)                                                               \
    (((uint64_t)((desired_egr_byte_offset) | 0x800) * (uint64_t)ingr_beats) / (uint64_t)egr_beats)

#define FIXED_RD_INGR_BYTE_OFFSET_FIND(ingr_beats, egr_beats, desired_egr_byte_offset)                                                               \
    (((uint64_t)((desired_egr_byte_offset) & ~0x800) * (uint64_t)ingr_beats) / (uint64_t)egr_beats)

#define IS_OVERLAPPING_4K(start_addr, end_addr) ((0x1000 & (uint64_t)start_addr) != (0x1000 & (uint64_t)end_addr))

#endif /* P64H_SYSC_MATH_H */