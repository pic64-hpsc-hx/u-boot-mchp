/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines Clock ACSU (A Clock Synthises Unit) driver header
 */

#ifndef ACSU_H
#define ACSU_H

#include <env/p64h_sysc_os_specific.h>

/**
 * @brief
 *   Proportional Path loop bandwidth control. FPFD = F_ref / REFDIV.
*/
typedef enum acsu_pplbwp_t
{
    ACSU_INT_FPFD31_6_FRAC_FPFD29_1 = 0U, ///< Integer 31.6, Fractional 29.1
    ACSU_INT_FPFD24_0_FRAC_FPFD24_0, ///< Integer 24.0, Fractional 24.0
    ACSU_INT_FPFD18_5_FRAC_FPFD19_5, ///< Integer 18.5, Fractional 19.5
    ACSU_INT_FPFD14_7_FRAC_FPFD16_1  ///< Integer 14.7, Fractional 16.1    
}acsu_pplbwp_t;

/**
 * @brief
 *   Integral Path loop bandwidth control.
*/
typedef enum acsu_pplbwi_t
{
    ACSU_PPLBWI_1X = 0U, ///< 1X integral path (recommended for FPFD<10MHz)
    ACSU_PPLBWI_2X, ///< 2X integral path
    ACSU_PPLBWI_3X, ///< 3X integral path
    ACSU_PPLBWI_4X, ///< 4X integral path (recommended for FPFD>100MHz)
    LAST_ACSU_PPLBWI ///< invalid, used for error checking
}acsu_pplbwi_t;

/**
 * @brief
 *   Type define for post dividers configuration
 *   Each ACSU has up to 8 clock outputs
*/
typedef struct acsu_post_div_cfg_type_t
{
    uint8_t     clk_bypass_en;   ///< 8b clock bypass enable. 1=Reference clock, 0=ACSU divided clock. bit0=clk[0]/bit7=clk[7]
    uint8_t     post_div_by[8];  ///< Array for the post divider for all 8 clocks + 1. 0=div by 1, 1=div by 2, etc   
    uint8_t     struct_padding1[3]; ///< 32b alignment
} acsu_post_div_cfg_type_t;

/**
 * @brief
 *   Type define for PLL configuration
*/
typedef struct acsu_pll_cfg_type_t
{
    acsu_pplbwi_t pllbwi;   ///< Integral Path loop bandwidth control
    acsu_pplbwp_t pllbwp;   ///< Proportional Path loop bandwidth control
    uint32_t    frac;            ///< 24b denominator - not used in integer mode
    uint16_t    fbdiv;           ///< 12b feedback divider
    uint8_t     dsmen;           ///< PLL fractional (1) vs integer (0)
    uint8_t     prediv;          ///< 6b 
    uint8_t     refdiv;          ///< 6b reference divider (always enabled, set to 1 to disable)
    uint8_t     struct_padding1[3]; ///< 32b alignment
} acsu_pll_cfg_type_t;

/**
 * @brief
 *   Type define for Clock configuration
*/
typedef struct acsu_cfg_t
{    
    acsu_pll_cfg_type_t pll_cfg;           ///< PLL Configuration
    acsu_post_div_cfg_type_t post_div_cfg; ///< Post Clock divider configs 
    bool offset_cal;                        ///< TRUE: perform offset calibration 
    bool ss_en;                             ///< TRUE: Spread Spectrum is enabled 
    bool pll_en;                            ///< TRUE: PLL is enabled, FALSE: PLL disabled (low power)
    bool pll_bypass_en;                     ///< TRUE: PLL is bypassed (ref clock output into post divider), FALSE: PLL 
} acsu_cfg_t;

/// CLOCK_ADJUST MBOX command paramaters: reduced set of acsu_cfg_t
typedef struct secc_cmd_clock_adjust_t
{
    uint16_t fbdiv;             ///< Register FBDIV
    uint8_t acsu_post_div_by;   ///< Register ACSU_POST_DIV_BY    
    uint8_t prediv;             ///< Register ACSU PREDIV
    uint8_t pllbwi;             ///< Register PLLBWI 
    uint8_t pll_en;             ///< Register PLL_EN
    uint8_t pll_bypass_en;      ///< Register PLL_BYPASS_EN
    uint8_t clk_bypass_en;      ///< Register bitfield[8] CLK_BYPASS_EN
} secc_cmd_clock_adjust_t;

#endif // ACSU_H
