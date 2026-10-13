/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_bitops.h
 * @brief
 * Common bit operation macros and functions
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE (8) ///< Number of bits per byte
#endif
#define BITS_PER_LONG      (BITS_PER_BYTE * sizeof(long))      ///< Number of bits per long
#define BITS_PER_LONG_LONG (BITS_PER_BYTE * sizeof(long long)) ///< Number of bits per long long

#define BIT(n)             (1UL << (n))            ///< unsigned long with bit n  to '1' and the rest set to '0'
#define BIT_ULL(n)         (1ULL << (n))           ///< unsigned long long with bit n set to '1' and the rest set to '0'
#define BIT_SET(x, n)      ((x) |= (1ULL << (n)))  ///< Set bit n of x to '1'
#define BIT_UNSET(x, n)    ((x) &= ~(1ULL << (n))) ///< Set bit n of x to '0'
#define BIT_CHECK(x, n)    ((x) & (1ULL << (n)))   ///< Check if bit n of x is set to '1'

#define BIT32(n)           ((uint32_t)BIT(n)) ///< unsigned with bit n  to '1' and the rest set to '0'
#define BIT32_SET(x, n)    ((x) |= BIT32(n))  ///< Set bit n of x(uint32_t) to '1'
#define BIT32_UNSET(x, n)  ((x) &= ~BIT32(n)) ///< Set bit n of x(uint32_t) to '0'
#define BIT32_CHECK(x, n)  ((x) & BIT32(n))   ///< Check if bit n of x(uint32_t) is set to '1'

#define BIT16(n)           ((uint16_t)BIT(n)) ///< unsigned with bit n  to '1' and the rest set to '0'
#define BIT16_SET(x, n)    ((x) |= BIT16(n))  ///< Set bit n of x(uint16_t) to '1'
#define BIT16_UNSET(x, n)  ((x) &= ~BIT16(n)) ///< Set bit n of x(uint16_t) to '0'
#define BIT16_CHECK(x, n)  ((x) & BIT16(n))   ///< Check if bit n of x(uint16_t) is set to '1'

#define BIT8(n)            ((uint8_t)BIT(n))                 ///< unsigned with bit n  to '1' and the rest set to '0'
#define BIT8_SET(x, n)     ((x) = (uint8_t)((x) | BIT8(n)))  ///< Set bit n of x(uint8_t) to '1'
#define BIT8_UNSET(x, n)   ((x) = (uint8_t)((x) & ~BIT8(n))) ///< Set bit n of x(uint8_t) to '0'
#define BIT8_CHECK(x, n)   ((x) & BIT8(n))                   ///< Check if bit n of x(uint8_t) is set to '1'

#ifndef CONTAINER_OF
#define CONTAINER_OF(_ptr_, _type_, _field_) ((_type_*)(((uint64_t)(_ptr_)) - offsetof(_type_, _field_)))
#endif

#define LONG_LO_MASK  (0x00000000FFFFFFFFULL)
#define LONG_HI_MASK  (0xFFFFFFFF00000000ULL)
#define LONG_HI_SHIFT (32UL)

#define GENMASK(h, l)                                                                                                                                \
    (((~0UL) - (1UL << (l)) + 1) & (~0UL >> (BITS_PER_LONG - 1 - (h)))) /**<                                                                         \
  Create a contiguous bitmask starting at bit position l and ending at                                                                               \
  position h. For example                                                                                                                            \
  GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000ffffe00000.*/

#define GENMASK_ULL(h, l)                                                                                                                            \
    (((~0ULL) - (1ULL << (l)) + 1) & (~0ULL >> (BITS_PER_LONG_LONG - 1 - (h))))\\ /**<                                                               \
                                Create a contiguous bitmask starting at bit position l and ending at                                                 \
                                position h. For example                                                                                              \
                                GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000ffffe00000.*/

#define ALIGN_UP_TO_UINT64(value) (((value) + (sizeof(uint64_t)) - 1) & ~(sizeof(uint64_t) - 1))

/**
 * @brief
 * rol64 - rotate a 64-bit value left
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint64_t rol64(uint64_t word, unsigned int shift)
{
    return (word << shift) | (word >> (64 - shift));
}

/**
 * @brief
 * ror64 - rotate a 64-bit value right
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint64_t ror64(uint64_t word, unsigned int shift)
{
    return (word >> shift) | (word << (64 - shift));
}

/**
 * @brief
 * rol32 - rotate a 32-bit value left
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint32_t rol32(uint32_t word, unsigned int shift)
{
    return (word << shift) | (word >> ((-shift) & 31));
}

/**
 * @brief
 * ror32 - rotate a 32-bit value right
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint32_t ror32(uint32_t word, unsigned int shift)
{
    return (word >> shift) | (word << (32 - shift));
}

/**
 * @brief
 * rol16 - rotate a 16-bit value left
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint16_t rol16(uint16_t word, unsigned int shift)
{
    return (word << shift) | (word >> (16 - shift));
}

/**
 * @brief
 * ror16 - rotate a 16-bit value right
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint16_t ror16(uint16_t word, unsigned int shift)
{
    return (word >> shift) | (word << (16 - shift));
}

/**
 * @brief
 * rol8 - rotate an 8-bit value left
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint8_t rol8(uint8_t word, unsigned int shift)
{
    return (word << shift) | (word >> (8 - shift));
}

/**
 * @brief
 * ror8 - rotate an 8-bit value right
 * @param word value to rotate
 * @param shift bits to roll
 * @return rotated value
 */
static inline uint8_t ror8(uint8_t word, unsigned int shift)
{
    return (word >> shift) | (word << (8 - shift));
}

/**
 * @brief
 * sign_extend32 - sign extend a 32-bit value using specified bit as sign-bit
 * @param value value to sign extend
 * @param index 0 based bit index (0<=index<32) to sign bit
 *
 * @return sign extended value
 * This is safe to use for 16- and 8-bit types as well.
 */
static inline int32_t sign_extend32(uint32_t value, int index)
{
    uint8_t shift = 31 - index;
    return (int32_t)(value << shift) >> shift;
}

/**
 * @brief
 * sign_extend64 - sign extend a 64-bit value using specified bit as sign-bit
 * @param value value to sign extend
 * @param index 0 based bit index (0<=index<64) to sign bit
 *
 * @return sign extended value
 */
static inline int64_t sign_extend64(uint64_t value, int index)
{
    uint8_t shift = 63 - index;
    return (int64_t)(value << shift) >> shift;
}

/**
 * @brief
 * Find first bit in word
 * taken from https://github.com/torvalds/linux/blob/master/tools/include/asm-generic/bitops/__ffs.h
 *
 * @param[in] word the word to search
 *
 * @return index of first bit found
 */
inline uint64_t __ffs(uint64_t word)
{
    uint64_t num = 0;
    if ((word & 0xffffffff) == 0) {
        num   += 32;
        word >>= 32;
    }
    if ((word & 0xffff) == 0) {
        num   += 16;
        word >>= 16;
    }
    if ((word & 0xff) == 0) {
        num   += 8;
        word >>= 8;
    }
    if ((word & 0xf) == 0) {
        num   += 4;
        word >>= 4;
    }
    if ((word & 0x3) == 0) {
        num   += 2;
        word >>= 2;
    }
    if ((word & 0x1) == 0) {
        num += 1;
    }
    return num;
}

/**
 * __ffs64 - find first set bit in a 64 bit word
 * On 64 bit arches this is a synomyn for __ffs
 * The result is not defined if no bits are set, so check that word
 * is non-zero before calling this.
 * @param[in] word The 64 bit word
 *
 * @return index of first bit found
 */
static inline unsigned long __ffs64(uint64_t word)
{
    return __ffs((unsigned long)word);
}

/**
 * Retrieve lower 32 bits of 64 bit long value
 * @param[in] value The 64 bit word
 *
 * @return Lower 32 bits of input value
 */
static inline uint32_t __long_lo(uint64_t value)
{
    return (uint32_t)(value & LONG_LO_MASK);
}

/**
 * Retrieve higher 32 bits of 64 bit long value
 * @param[in] value The 64 bit word
 *
 * @return higher 32 bits of input value
 */
static inline uint32_t __long_hi(uint64_t value)
{
    return (uint32_t)((value >> LONG_HI_SHIFT) & LONG_LO_MASK);
}

/**
 * Reconstruct 64bit long from MSB and LSB
 * @param[in] msb MSB of value
 * @param[in] lsb LSB of value
 *
 * @return Reconstructed 64 bit long value
 */
static inline uint64_t __long_construct(uint32_t msb, uint32_t lsb)
{
    return (uint64_t)((((uint64_t)msb << LONG_HI_SHIFT) & LONG_HI_MASK) | (((uint64_t)lsb) & LONG_LO_MASK));
}

/**
 * Check if a given value fits within a specified register bit field
 * @param[in] value The value to check
 * @param[in] mask The bitmask representing the field
 * @param[in] pos The position (shift) of the field within the register
 *
 * @return true if the value fits in the field, false otherwise
 */
static inline bool value_fits_in_field(uint32_t value, uint32_t mask, uint32_t pos)
{
    return ((value << pos) & mask) == (value << pos);
}
