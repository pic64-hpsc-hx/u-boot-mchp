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
#define DIV_ROUND_UP(n, d) (((n) + (d)-1) / (d))   ///< divide round up
#endif

#ifndef MAX
#define MAX(x, y)          ((x) > (y) ? (x) : (y)) ///< max
#endif

#ifndef MIN
#define MIN(x, y)          ((x) < (y) ? (x) : (y)) ///< min
#endif

#ifndef ALIGN
#define ALIGN(addr, size)  (((uint64_t)addr) + (((uint64_t)size) - 1) & ~(((uint64_t)size) - 1))
#endif

#endif /* P64H_SYSC_MATH_H */