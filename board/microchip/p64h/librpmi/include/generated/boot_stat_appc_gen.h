/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * APPC BOOT_STAT defines
 */

 /*--------------------.
 | auto-generated file |
 +--------------------*/

#ifdef __ASSEMBLER__
// #defines are for when included by assembler .S files.
#define BOOT_STAGE_APPC_CORE_0_PARTITION_BOOT     0U ///< Core 0 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED8                 1U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_0_ZSBL_STARTED       2U ///< Core 0 - zsbl started  
#define BOOT_STAGE_APPC_CORE_0_PARTITION_AUTO_RESET  3U ///< Core 0 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_0_UP_DOWN            4U ///< Core 0 - status up/down  
#define BOOT_STAGE_APPC_CORE_0_RNMI_EXCEPTION     5U ///< Core 0 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED0                 6U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED1                 7U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED2                 8U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED3                 9U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED4                10U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED5                11U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED6                12U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED7                13U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_0_HEARTBEAT         14U ///< Core 0 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_0_GUARD_BIT         15U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_1_PARTITION_BOOT    16U ///< Core 1 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED18               17U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_1_ZSBL_STARTED      18U ///< Core 1 - zsbl started  
#define BOOT_STAGE_APPC_CORE_1_PARTITION_AUTO_RESET 19U ///< Core 1 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_1_UP_DOWN           20U ///< Core 1 - status up/down  
#define BOOT_STAGE_APPC_CORE_1_RNMI_EXCEPTION    21U ///< Core 1 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED10               22U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED11               23U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED12               24U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED13               25U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED14               26U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED15               27U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED16               28U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED17               29U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_1_HEARTBEAT         30U ///< Core 1 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_1_GUARD_BIT         31U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_2_PARTITION_BOOT    32U ///< Core 2 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED28               33U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_2_ZSBL_STARTED      34U ///< Core 2 - zsbl started  
#define BOOT_STAGE_APPC_CORE_2_PARTITION_AUTO_RESET 35U ///< Core 2 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_2_UP_DOWN           36U ///< Core 2 - status up/down  
#define BOOT_STAGE_APPC_CORE_2_RNMI_EXCEPTION    37U ///< Core 2 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED20               38U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED21               39U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED22               40U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED23               41U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED24               42U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED25               43U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED26               44U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED27               45U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_2_HEARTBEAT         46U ///< Core 2 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_2_GUARD_BIT         47U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_3_PARTITION_BOOT    48U ///< Core 3 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED38               49U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_3_ZSBL_STARTED      50U ///< Core 3 - zsbl started  
#define BOOT_STAGE_APPC_CORE_3_PARTITION_AUTO_RESET 51U ///< Core 3 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_3_UP_DOWN           52U ///< Core 3 - status up/down  
#define BOOT_STAGE_APPC_CORE_3_RNMI_EXCEPTION    53U ///< Core 3 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED30               54U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED31               55U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED32               56U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED33               57U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED34               58U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED35               59U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED36               60U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED37               61U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_3_HEARTBEAT         62U ///< Core 3 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_3_GUARD_BIT         63U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_4_PARTITION_BOOT    64U ///< Core 4 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED48               65U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_4_ZSBL_STARTED      66U ///< Core 4 - zsbl started  
#define BOOT_STAGE_APPC_CORE_4_PARTITION_AUTO_RESET 67U ///< Core 4 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_4_UP_DOWN           68U ///< Core 4 - status up/down  
#define BOOT_STAGE_APPC_CORE_4_RNMI_EXCEPTION    69U ///< Core 4 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED40               70U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED41               71U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED42               72U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED43               73U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED44               74U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED45               75U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED46               76U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED47               77U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_4_HEARTBEAT         78U ///< Core 4 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_4_GUARD_BIT         79U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_5_PARTITION_BOOT    80U ///< Core 5 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED58               81U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_5_ZSBL_STARTED      82U ///< Core 5 - zsbl started  
#define BOOT_STAGE_APPC_CORE_5_PARTITION_AUTO_RESET 83U ///< Core 5 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_5_UP_DOWN           84U ///< Core 5 - status up/down  
#define BOOT_STAGE_APPC_CORE_5_RNMI_EXCEPTION    85U ///< Core 5 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED50               86U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED51               87U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED52               88U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED53               89U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED54               90U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED55               91U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED56               92U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED57               93U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_5_HEARTBEAT         94U ///< Core 5 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_5_GUARD_BIT         95U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_6_PARTITION_BOOT    96U ///< Core 6 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED68               97U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_6_ZSBL_STARTED      98U ///< Core 6 - zsbl started  
#define BOOT_STAGE_APPC_CORE_6_PARTITION_AUTO_RESET 99U ///< Core 6 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_6_UP_DOWN           100U ///< Core 6 - status up/down  
#define BOOT_STAGE_APPC_CORE_6_RNMI_EXCEPTION    101U ///< Core 6 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED60               102U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED61               103U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED62               104U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED63               105U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED64               106U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED65               107U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED66               108U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED67               109U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_6_HEARTBEAT         110U ///< Core 6 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_6_GUARD_BIT         111U ///< STAT_DRV workaround (always 1)  
#define BOOT_STAGE_APPC_CORE_7_PARTITION_BOOT    112U ///< Core 7 - Partition boot stage  
#define BOOT_STAGE_APPC_RESERVED78               113U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_7_ZSBL_STARTED      114U ///< Core 7 - zsbl started  
#define BOOT_STAGE_APPC_CORE_7_PARTITION_AUTO_RESET 115U ///< Core 7 - Partition auto reset  
#define BOOT_STAGE_APPC_CORE_7_UP_DOWN           116U ///< Core 7 - status up/down  
#define BOOT_STAGE_APPC_CORE_7_RNMI_EXCEPTION    117U ///< Core 7 - exception while RNMI in progress  
#define BOOT_STAGE_APPC_RESERVED70               118U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED71               119U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED72               120U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED73               121U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED74               122U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED75               123U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED76               124U ///< Not used for appc  
#define BOOT_STAGE_APPC_RESERVED77               125U ///< Not used for appc  
#define BOOT_STAGE_APPC_CORE_7_HEARTBEAT         126U ///< Core 7 - AppC Heart beat event  
#define BOOT_STAGE_APPC_CORE_7_GUARD_BIT         127U ///< STAT_DRV workaround (always 1)  
#else // __ASSEMBLER__

#ifndef BOOT_STAT_GEN_APPC_H
#define BOOT_STAT_GEN_APPC_H

/// Definitions of APPC boot stages
typedef enum boot_stage_appc_t
{
    BOOT_STAGE_APPC_CORE_0_PARTITION_BOOT    =  0U, ///< Core 0 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED8                =  1U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_0_ZSBL_STARTED      =  2U, ///< Core 0 - zsbl started  
    BOOT_STAGE_APPC_CORE_0_PARTITION_AUTO_RESET =  3U, ///< Core 0 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_0_UP_DOWN           =  4U, ///< Core 0 - status up/down  
    BOOT_STAGE_APPC_CORE_0_RNMI_EXCEPTION    =  5U, ///< Core 0 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED0                =  6U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED1                =  7U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED2                =  8U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED3                =  9U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED4                = 10U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED5                = 11U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED6                = 12U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED7                = 13U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_0_HEARTBEAT         = 14U, ///< Core 0 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_0_GUARD_BIT         = 15U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_1_PARTITION_BOOT    = 16U, ///< Core 1 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED18               = 17U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_1_ZSBL_STARTED      = 18U, ///< Core 1 - zsbl started  
    BOOT_STAGE_APPC_CORE_1_PARTITION_AUTO_RESET = 19U, ///< Core 1 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_1_UP_DOWN           = 20U, ///< Core 1 - status up/down  
    BOOT_STAGE_APPC_CORE_1_RNMI_EXCEPTION    = 21U, ///< Core 1 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED10               = 22U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED11               = 23U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED12               = 24U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED13               = 25U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED14               = 26U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED15               = 27U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED16               = 28U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED17               = 29U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_1_HEARTBEAT         = 30U, ///< Core 1 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_1_GUARD_BIT         = 31U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_2_PARTITION_BOOT    = 32U, ///< Core 2 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED28               = 33U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_2_ZSBL_STARTED      = 34U, ///< Core 2 - zsbl started  
    BOOT_STAGE_APPC_CORE_2_PARTITION_AUTO_RESET = 35U, ///< Core 2 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_2_UP_DOWN           = 36U, ///< Core 2 - status up/down  
    BOOT_STAGE_APPC_CORE_2_RNMI_EXCEPTION    = 37U, ///< Core 2 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED20               = 38U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED21               = 39U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED22               = 40U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED23               = 41U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED24               = 42U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED25               = 43U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED26               = 44U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED27               = 45U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_2_HEARTBEAT         = 46U, ///< Core 2 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_2_GUARD_BIT         = 47U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_3_PARTITION_BOOT    = 48U, ///< Core 3 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED38               = 49U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_3_ZSBL_STARTED      = 50U, ///< Core 3 - zsbl started  
    BOOT_STAGE_APPC_CORE_3_PARTITION_AUTO_RESET = 51U, ///< Core 3 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_3_UP_DOWN           = 52U, ///< Core 3 - status up/down  
    BOOT_STAGE_APPC_CORE_3_RNMI_EXCEPTION    = 53U, ///< Core 3 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED30               = 54U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED31               = 55U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED32               = 56U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED33               = 57U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED34               = 58U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED35               = 59U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED36               = 60U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED37               = 61U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_3_HEARTBEAT         = 62U, ///< Core 3 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_3_GUARD_BIT         = 63U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_4_PARTITION_BOOT    = 64U, ///< Core 4 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED48               = 65U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_4_ZSBL_STARTED      = 66U, ///< Core 4 - zsbl started  
    BOOT_STAGE_APPC_CORE_4_PARTITION_AUTO_RESET = 67U, ///< Core 4 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_4_UP_DOWN           = 68U, ///< Core 4 - status up/down  
    BOOT_STAGE_APPC_CORE_4_RNMI_EXCEPTION    = 69U, ///< Core 4 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED40               = 70U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED41               = 71U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED42               = 72U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED43               = 73U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED44               = 74U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED45               = 75U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED46               = 76U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED47               = 77U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_4_HEARTBEAT         = 78U, ///< Core 4 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_4_GUARD_BIT         = 79U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_5_PARTITION_BOOT    = 80U, ///< Core 5 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED58               = 81U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_5_ZSBL_STARTED      = 82U, ///< Core 5 - zsbl started  
    BOOT_STAGE_APPC_CORE_5_PARTITION_AUTO_RESET = 83U, ///< Core 5 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_5_UP_DOWN           = 84U, ///< Core 5 - status up/down  
    BOOT_STAGE_APPC_CORE_5_RNMI_EXCEPTION    = 85U, ///< Core 5 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED50               = 86U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED51               = 87U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED52               = 88U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED53               = 89U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED54               = 90U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED55               = 91U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED56               = 92U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED57               = 93U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_5_HEARTBEAT         = 94U, ///< Core 5 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_5_GUARD_BIT         = 95U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_6_PARTITION_BOOT    = 96U, ///< Core 6 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED68               = 97U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_6_ZSBL_STARTED      = 98U, ///< Core 6 - zsbl started  
    BOOT_STAGE_APPC_CORE_6_PARTITION_AUTO_RESET = 99U, ///< Core 6 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_6_UP_DOWN           = 100U, ///< Core 6 - status up/down  
    BOOT_STAGE_APPC_CORE_6_RNMI_EXCEPTION    = 101U, ///< Core 6 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED60               = 102U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED61               = 103U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED62               = 104U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED63               = 105U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED64               = 106U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED65               = 107U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED66               = 108U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED67               = 109U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_6_HEARTBEAT         = 110U, ///< Core 6 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_6_GUARD_BIT         = 111U, ///< STAT_DRV workaround (always 1)  
    BOOT_STAGE_APPC_CORE_7_PARTITION_BOOT    = 112U, ///< Core 7 - Partition boot stage  
    BOOT_STAGE_APPC_RESERVED78               = 113U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_7_ZSBL_STARTED      = 114U, ///< Core 7 - zsbl started  
    BOOT_STAGE_APPC_CORE_7_PARTITION_AUTO_RESET = 115U, ///< Core 7 - Partition auto reset  
    BOOT_STAGE_APPC_CORE_7_UP_DOWN           = 116U, ///< Core 7 - status up/down  
    BOOT_STAGE_APPC_CORE_7_RNMI_EXCEPTION    = 117U, ///< Core 7 - exception while RNMI in progress  
    BOOT_STAGE_APPC_RESERVED70               = 118U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED71               = 119U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED72               = 120U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED73               = 121U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED74               = 122U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED75               = 123U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED76               = 124U, ///< Not used for appc  
    BOOT_STAGE_APPC_RESERVED77               = 125U, ///< Not used for appc  
    BOOT_STAGE_APPC_CORE_7_HEARTBEAT         = 126U, ///< Core 7 - AppC Heart beat event  
    BOOT_STAGE_APPC_CORE_7_GUARD_BIT         = 127U, ///< STAT_DRV workaround (always 1)  
} boot_stage_appc_t;

/**
 * @brief return string associated with boot stat code
 * note: we could generate a c file for this.
 *  for now, if we just call this from one .c file it should be fine.
 *  we don't really need the performance or space improvement of an array lookup.
 * 
 * @param[in] code - boot stat enum
 * @return string
 */
static inline const char *boot_stage_appc_str( boot_stage_appc_t code )
{
    const char *res;
    switch (code)
    {
          // Core 0 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_0_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_0_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED8:
              res = "BOOT_STAGE_APPC_RESERVED8";
              break;
          // Core 0 - zsbl started
          case BOOT_STAGE_APPC_CORE_0_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_0_ZSBL_STARTED";
              break;
          // Core 0 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_0_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_0_PARTITION_AUTO_RESET";
              break;
          // Core 0 - status up/down
          case BOOT_STAGE_APPC_CORE_0_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_0_UP_DOWN";
              break;
          // Core 0 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_0_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_0_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED0:
              res = "BOOT_STAGE_APPC_RESERVED0";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED1:
              res = "BOOT_STAGE_APPC_RESERVED1";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED2:
              res = "BOOT_STAGE_APPC_RESERVED2";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED3:
              res = "BOOT_STAGE_APPC_RESERVED3";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED4:
              res = "BOOT_STAGE_APPC_RESERVED4";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED5:
              res = "BOOT_STAGE_APPC_RESERVED5";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED6:
              res = "BOOT_STAGE_APPC_RESERVED6";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED7:
              res = "BOOT_STAGE_APPC_RESERVED7";
              break;
          // Core 0 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_0_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_0_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_0_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_0_GUARD_BIT";
              break;
          // Core 1 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_1_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_1_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED18:
              res = "BOOT_STAGE_APPC_RESERVED18";
              break;
          // Core 1 - zsbl started
          case BOOT_STAGE_APPC_CORE_1_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_1_ZSBL_STARTED";
              break;
          // Core 1 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_1_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_1_PARTITION_AUTO_RESET";
              break;
          // Core 1 - status up/down
          case BOOT_STAGE_APPC_CORE_1_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_1_UP_DOWN";
              break;
          // Core 1 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_1_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_1_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED10:
              res = "BOOT_STAGE_APPC_RESERVED10";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED11:
              res = "BOOT_STAGE_APPC_RESERVED11";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED12:
              res = "BOOT_STAGE_APPC_RESERVED12";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED13:
              res = "BOOT_STAGE_APPC_RESERVED13";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED14:
              res = "BOOT_STAGE_APPC_RESERVED14";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED15:
              res = "BOOT_STAGE_APPC_RESERVED15";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED16:
              res = "BOOT_STAGE_APPC_RESERVED16";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED17:
              res = "BOOT_STAGE_APPC_RESERVED17";
              break;
          // Core 1 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_1_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_1_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_1_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_1_GUARD_BIT";
              break;
          // Core 2 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_2_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_2_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED28:
              res = "BOOT_STAGE_APPC_RESERVED28";
              break;
          // Core 2 - zsbl started
          case BOOT_STAGE_APPC_CORE_2_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_2_ZSBL_STARTED";
              break;
          // Core 2 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_2_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_2_PARTITION_AUTO_RESET";
              break;
          // Core 2 - status up/down
          case BOOT_STAGE_APPC_CORE_2_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_2_UP_DOWN";
              break;
          // Core 2 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_2_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_2_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED20:
              res = "BOOT_STAGE_APPC_RESERVED20";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED21:
              res = "BOOT_STAGE_APPC_RESERVED21";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED22:
              res = "BOOT_STAGE_APPC_RESERVED22";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED23:
              res = "BOOT_STAGE_APPC_RESERVED23";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED24:
              res = "BOOT_STAGE_APPC_RESERVED24";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED25:
              res = "BOOT_STAGE_APPC_RESERVED25";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED26:
              res = "BOOT_STAGE_APPC_RESERVED26";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED27:
              res = "BOOT_STAGE_APPC_RESERVED27";
              break;
          // Core 2 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_2_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_2_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_2_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_2_GUARD_BIT";
              break;
          // Core 3 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_3_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_3_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED38:
              res = "BOOT_STAGE_APPC_RESERVED38";
              break;
          // Core 3 - zsbl started
          case BOOT_STAGE_APPC_CORE_3_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_3_ZSBL_STARTED";
              break;
          // Core 3 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_3_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_3_PARTITION_AUTO_RESET";
              break;
          // Core 3 - status up/down
          case BOOT_STAGE_APPC_CORE_3_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_3_UP_DOWN";
              break;
          // Core 3 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_3_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_3_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED30:
              res = "BOOT_STAGE_APPC_RESERVED30";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED31:
              res = "BOOT_STAGE_APPC_RESERVED31";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED32:
              res = "BOOT_STAGE_APPC_RESERVED32";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED33:
              res = "BOOT_STAGE_APPC_RESERVED33";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED34:
              res = "BOOT_STAGE_APPC_RESERVED34";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED35:
              res = "BOOT_STAGE_APPC_RESERVED35";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED36:
              res = "BOOT_STAGE_APPC_RESERVED36";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED37:
              res = "BOOT_STAGE_APPC_RESERVED37";
              break;
          // Core 3 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_3_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_3_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_3_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_3_GUARD_BIT";
              break;
          // Core 4 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_4_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_4_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED48:
              res = "BOOT_STAGE_APPC_RESERVED48";
              break;
          // Core 4 - zsbl started
          case BOOT_STAGE_APPC_CORE_4_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_4_ZSBL_STARTED";
              break;
          // Core 4 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_4_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_4_PARTITION_AUTO_RESET";
              break;
          // Core 4 - status up/down
          case BOOT_STAGE_APPC_CORE_4_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_4_UP_DOWN";
              break;
          // Core 4 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_4_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_4_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED40:
              res = "BOOT_STAGE_APPC_RESERVED40";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED41:
              res = "BOOT_STAGE_APPC_RESERVED41";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED42:
              res = "BOOT_STAGE_APPC_RESERVED42";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED43:
              res = "BOOT_STAGE_APPC_RESERVED43";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED44:
              res = "BOOT_STAGE_APPC_RESERVED44";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED45:
              res = "BOOT_STAGE_APPC_RESERVED45";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED46:
              res = "BOOT_STAGE_APPC_RESERVED46";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED47:
              res = "BOOT_STAGE_APPC_RESERVED47";
              break;
          // Core 4 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_4_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_4_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_4_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_4_GUARD_BIT";
              break;
          // Core 5 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_5_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_5_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED58:
              res = "BOOT_STAGE_APPC_RESERVED58";
              break;
          // Core 5 - zsbl started
          case BOOT_STAGE_APPC_CORE_5_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_5_ZSBL_STARTED";
              break;
          // Core 5 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_5_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_5_PARTITION_AUTO_RESET";
              break;
          // Core 5 - status up/down
          case BOOT_STAGE_APPC_CORE_5_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_5_UP_DOWN";
              break;
          // Core 5 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_5_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_5_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED50:
              res = "BOOT_STAGE_APPC_RESERVED50";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED51:
              res = "BOOT_STAGE_APPC_RESERVED51";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED52:
              res = "BOOT_STAGE_APPC_RESERVED52";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED53:
              res = "BOOT_STAGE_APPC_RESERVED53";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED54:
              res = "BOOT_STAGE_APPC_RESERVED54";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED55:
              res = "BOOT_STAGE_APPC_RESERVED55";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED56:
              res = "BOOT_STAGE_APPC_RESERVED56";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED57:
              res = "BOOT_STAGE_APPC_RESERVED57";
              break;
          // Core 5 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_5_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_5_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_5_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_5_GUARD_BIT";
              break;
          // Core 6 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_6_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_6_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED68:
              res = "BOOT_STAGE_APPC_RESERVED68";
              break;
          // Core 6 - zsbl started
          case BOOT_STAGE_APPC_CORE_6_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_6_ZSBL_STARTED";
              break;
          // Core 6 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_6_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_6_PARTITION_AUTO_RESET";
              break;
          // Core 6 - status up/down
          case BOOT_STAGE_APPC_CORE_6_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_6_UP_DOWN";
              break;
          // Core 6 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_6_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_6_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED60:
              res = "BOOT_STAGE_APPC_RESERVED60";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED61:
              res = "BOOT_STAGE_APPC_RESERVED61";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED62:
              res = "BOOT_STAGE_APPC_RESERVED62";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED63:
              res = "BOOT_STAGE_APPC_RESERVED63";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED64:
              res = "BOOT_STAGE_APPC_RESERVED64";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED65:
              res = "BOOT_STAGE_APPC_RESERVED65";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED66:
              res = "BOOT_STAGE_APPC_RESERVED66";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED67:
              res = "BOOT_STAGE_APPC_RESERVED67";
              break;
          // Core 6 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_6_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_6_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_6_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_6_GUARD_BIT";
              break;
          // Core 7 - Partition boot stage
          case BOOT_STAGE_APPC_CORE_7_PARTITION_BOOT:
              res = "BOOT_STAGE_APPC_CORE_7_PARTITION_BOOT";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED78:
              res = "BOOT_STAGE_APPC_RESERVED78";
              break;
          // Core 7 - zsbl started
          case BOOT_STAGE_APPC_CORE_7_ZSBL_STARTED:
              res = "BOOT_STAGE_APPC_CORE_7_ZSBL_STARTED";
              break;
          // Core 7 - Partition auto reset
          case BOOT_STAGE_APPC_CORE_7_PARTITION_AUTO_RESET:
              res = "BOOT_STAGE_APPC_CORE_7_PARTITION_AUTO_RESET";
              break;
          // Core 7 - status up/down
          case BOOT_STAGE_APPC_CORE_7_UP_DOWN:
              res = "BOOT_STAGE_APPC_CORE_7_UP_DOWN";
              break;
          // Core 7 - exception while RNMI in progress
          case BOOT_STAGE_APPC_CORE_7_RNMI_EXCEPTION:
              res = "BOOT_STAGE_APPC_CORE_7_RNMI_EXCEPTION";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED70:
              res = "BOOT_STAGE_APPC_RESERVED70";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED71:
              res = "BOOT_STAGE_APPC_RESERVED71";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED72:
              res = "BOOT_STAGE_APPC_RESERVED72";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED73:
              res = "BOOT_STAGE_APPC_RESERVED73";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED74:
              res = "BOOT_STAGE_APPC_RESERVED74";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED75:
              res = "BOOT_STAGE_APPC_RESERVED75";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED76:
              res = "BOOT_STAGE_APPC_RESERVED76";
              break;
          // Not used for appc
          case BOOT_STAGE_APPC_RESERVED77:
              res = "BOOT_STAGE_APPC_RESERVED77";
              break;
          // Core 7 - AppC Heart beat event
          case BOOT_STAGE_APPC_CORE_7_HEARTBEAT:
              res = "BOOT_STAGE_APPC_CORE_7_HEARTBEAT";
              break;
          // STAT_DRV workaround (always 1)
          case BOOT_STAGE_APPC_CORE_7_GUARD_BIT:
              res = "BOOT_STAGE_APPC_CORE_7_GUARD_BIT";
              break;
          default:
              res = "unknown boot_stage_appc_t";
              break;

    }
    return res;
}
#endif
#endif // __ASSEMBLER__
