/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_sysc_anlt_types.h
 * @brief
 *   Defines types required for anlt configuration and operation
 * @addtogroup p64h_sysc_types
 * @{
 */
#ifndef P64H_SYSC_ANLT_TYPES_H
#define P64H_SYSC_ANLT_TYPES_H

#include <env/p64h_sysc_os_specific.h>

/// Enum dictating whether we are in AutoNegotiation or Link Training Mode
typedef enum {
    P64H_SYSC_ANLT_MODE_LT = 0u, ///< ANLT is in LT mode
    P64H_SYSC_ANLT_MODE_AN,      ///< ANLT is in AN mode
    P64H_SYSC_ANLT_MODE_LAST     ///< invalid, used for error checking
} p64h_sysc_anlt_mode_t;

/// AutoNegotiation Base Page (IEEE 802.3 73.6) Definition
typedef union __attribute__((packed)) {
    uint64_t w; ///< whole 64 bits
    struct __attribute__((packed)) {
        uint64_t bot : 32; ///< bottom 32 bits
        uint64_t top : 32; ///< top 32 bits
    } h;                   ///< top or bottom half (32 bits), useful for register accesses
    struct __attribute__((packed)) {
        uint64_t selector         : 5;  ///< Selector Field (must be 0b00001)    bit [ 4: 0]
        uint64_t e_nonce          : 5;  ///< Echoed Nonce                        bit [ 9: 5]
        uint64_t pause_capability : 3;  ///< Pause Capability                    bit [12:10]
        uint64_t remote_fault     : 1;  ///< Remote Fault                        bit [13]
        uint64_t ack              : 1;  ///< Acknowledge                         bit [14]
        uint64_t next_page        : 1;  ///< Next Page                           bit [15]
        uint64_t t_nonce          : 1;  ///< Transmitted Nonce                   bit [20:16]
        uint64_t ab_1gkx          : 1;  ///< 1000BASEK-X   ability (  supported) bit [21]
        uint64_t ab_10gkx         : 1;  ///< 10GBASEK-X    ability (unsupported) bit [22]
        uint64_t ab_10gkr         : 1;  ///< 10GBASEK-R    ability (  supported) bit [23]
        uint64_t ab_40gkr4        : 1;  ///< 40GBASEK-R    ability (unsupported) bit [24]
        uint64_t ab_40gcr4        : 1;  ///< 40GBASEC-R    ability (unsupported) bit [25]
        uint64_t ab_100gcr10      : 1;  ///< 100GBASEC-R10 ability (unsupported) bit [26]
        uint64_t ab_100gkp4       : 1;  ///< 100GBASEK-P4  ability (unsupported) bit [27]
        uint64_t ab_100gkr4       : 1;  ///< 100GBASEK-R4  ability (unsupported) bit [28]
        uint64_t ab_100gcr4       : 1;  ///< 100GBASEC-R4  ability (unsupported) bit [29]
        uint64_t ab_25gkrs        : 1;  ///< 25GBASEK-RS   ability (unsupported) bit [30]
        uint64_t ab_25gkr         : 1;  ///< 25GBASEK-R    ability (unsupported) bit [31]
        uint64_t ab_2_5gkx        : 1;  ///< 2.5GBASEK-X   ability (  supported) bit [32]
        uint64_t ab_5gkr          : 1;  ///< 5GBASEK-R     ability (  supported) bit [33]
        uint64_t ab_50gkr         : 1;  ///< 50GBASEK-R    ability (unsupported) bit [34]
        uint64_t ab_100gkr2       : 1;  ///< 100GBASEK-R2  ability (unsupported) bit [35]
        uint64_t ab_200gkr4       : 1;  ///< 100GBASEK-R4  ability (unsupported) bit [36]
        uint64_t ab_reserved      : 7;  ///< Bits reserved by standard           bit [37:43]
        uint64_t fec_ability25g   : 2;  ///< Ability to send/receive FEC at 25G  bit [45:44]
        uint64_t fec_ability      : 2;  ///< Ability to send/receive FEC at 10G  bit [47:46]
        uint64_t pad_48_63        : 15; ///< padding out to 64 bits total        bit [63:48]
    } b;                                ///< individual bit fields
} p64h_sysc_an_base_page_t;

/// AN Arbitration State Machine (IEEE 802.3 Figure 73-11) State Definitions
typedef enum {
    P64H_SYSC_AN_ARB_AN_TRANSMIT_DISABLE = 0u, ///< AN Arbitration Transmit Disable
    P64H_SYSC_AN_ARB_AN_ABILITY_DETECT,        ///< AN Arbitration Ability Detect
    P64H_SYSC_AN_ARB_AN_ACKNOWLEDGE_DETECT,    ///< AN Arbitration Acknowledge Detect
    P64H_SYSC_AN_ARB_AN_COMPLETE_ACKNOWLEDGE,  ///< AN Arbitration Complete Acknowledge
    P64H_SYSC_AN_ARB_AN_NEXT_PAGE_WAIT,        ///< AN Arbitration Next Page Wait
    P64H_SYSC_AN_ARB_AN_GOOD_CHECK,            ///< AN Arbitration AutoNegotiation Good Check
    P64H_SYSC_AN_ARB_LAST                      ///< invalid, used for error checking
} p64h_sysc_an_arb_state_t;

/// LT Coefficient Update Request (IEEE 802.3 72.6.10.2.3.3) Definition
typedef enum {
    P64H_SYSC_LT_COEFF_REQ_HOLD = 0u, ///< LT Hold Coefficient at Current Value
    P64H_SYSC_LT_COEFF_REQ_INCR,      ///< LT Increment Coefficient by one step
    P64H_SYSC_LT_COEFF_REQ_DECR,      ///< LT Decrement Coefficient by one step
    P64H_SYSC_LT_COEFF_REQ_LAST       ///< invalid, used for error checking
} p64h_sysc_lt_coeff_req_t;

/// LT Coefficient Update Status (IEEE 802.3 72.6.10.2.4.5) Definition
typedef enum {
    P64H_SYSC_LT_COEFF_STAT_NOT_UPD = 0u, ///< LT Coefficient Not Updated
    P64H_SYSC_LT_COEFF_STAT_UPD,          ///< LT Coefficient Updated
    P64H_SYSC_LT_COEFF_STAT_MIN,          ///< LT Coefficient at Minimum
    P64H_SYSC_LT_COEFF_STAT_MAX,          ///< LT Coefficient at Maximum
    P64H_SYSC_LT_COEFF_STAT_LAST          ///< invalid, used for error checking
} p64h_sysc_lt_coeff_stat_t;

/// LT Frame Status Report Field (IEEE 802.3 72.6.10.2.4) Definition
typedef union __attribute__((packed)) {
    uint32_t cm1            : 2;  ///< Coefficient Status for Pre  Cursor (CM1)
    uint32_t c0             : 2;  ///< Coefficient Status for Main Cursor (C0 )
    uint32_t cp1            : 2;  ///< Coefficient Status for Post Cursor (CP1)
    uint32_t pad_14_6       : 9;  ///< Reserved bits in status field
    uint32_t receiver_ready : 1;  ///< Receiver Ready (Training Complete)
    uint32_t pad_ctrl       : 16; ///< Pad upper 16 bits as they contain the Control fields
} p64h_sysc_lt_stat_t;

/// LT Frame Coefficient Update (Control) Field (IEEE 802.3 72.6.10.2.3) Definition
typedef union __attribute__((packed)) {
    uint32_t pad_stat  : 16; ///< Pad upper 16 bits as they contain the Control fields
    uint32_t cm1       : 2;  ///< Coefficient Request for Pre  Cursor (CM1)
    uint32_t c0        : 2;  ///< Coefficient Request for Main Cursor (C0 )
    uint32_t cp1       : 2;  ///< Coefficient Request for Post Cursor (CP1)
    uint32_t pad_11_6  : 6;  ///< Reserved bits within control field
    uint32_t init      : 1;  ///< INIT Request
    uint32_t preset    : 1;  ///< PRESET Request
    uint32_t pad_15_14 : 2;  ///< Reserved bits within control field
} p64h_sysc_lt_ctrl_t;

/// LT Frame Control Channel Encoding (IEEE 802.3 72.6.10.2.2) Definition
typedef union __attribute__((packed)) {
    uint32_t            w;    ///< Whole 32 bits of frame
    p64h_sysc_lt_ctrl_t ctrl; ///< Coefficient Update (Control) Field
    p64h_sysc_lt_stat_t stat; ///< Status Report Field
} p64h_sysc_lt_frame_t;

/// The current state of the ANLT state machine
typedef enum {
    P64H_SYSC_ANLT_SM_STATE_RESET = 0u,       ///< Software State Machine in Reset
    P64H_SYSC_ANLT_SM_STATE_AN_WAIT,          ///< The beginning of AN operation
    P64H_SYSC_ANLT_SM_STATE_LT_INIT,          ///< Determined that we are running LT, perform any required tap PRESETS
    P64H_SYSC_ANLT_SM_STATE_LT_SEND_TRAINING, ///< Training our link partner, see LT_SEND_TRAINING state
    P64H_SYSC_ANLT_SM_STATE_LT_TRAIN_REMOTE,  ///< Done training our RX, waiting for remote parter to complete their training
    P64H_SYSC_ANLT_SM_STATE_LT_LINK_READY,    ///< Link partner done training, waiting for Link Ready timer to expire
    P64H_SYSC_ANLT_SM_STATE_LT_SEND_DATA,     ///< Link Training process complete, communicate to system software that we are ready to send data
    P64H_SYSC_ANLT_SM_STATE_LAST              ///< invalid, only used for error checking
} p64h_sysc_anlt_sm_state_t;

/// The current substate within the LT_SEND_TRAINING state
typedef enum {
    P64H_SYSC_LT_TRAIN_STATE_RESET = 0u,       ///< Not yet in LT_SEND_TRAINING, Sub State Machine inactive
    P64H_SYSC_LT_TRAIN_STATE_FIND_MIN_C0,      ///< Decreasing main cursor tap to MIN
    P64H_SYSC_LT_TRAIN_STATE_FIND_MAX_AREA_C0, ///< Increasing main cursor tap to MAX and checking the area at each step
    P64H_SYSC_LT_TRAIN_STATE_SET_C0_MAX_AREA,  ///< Moving the C0 to the Max Area
    P64H_SYSC_LT_TRAIN_STATE_AREA_C0_P1,       ///< Increasing main cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_AREA_C0_M1,       ///< Decreasing main cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_AREA_CP1_P1,      ///< Increasing post cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_AREA_CP1_M1,      ///< Decreasing post cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_AREA_CM1_P1,      ///< Increasing pre  cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_AREA_CM1_M1,      ///< Decreasing pre  cursor and checking new FOM
    P64H_SYSC_LT_TRAIN_STATE_MOVE_TO_MAX_AREA, ///< Moving to the largest Area in the neighborhood
    P64H_SYSC_LT_TRAIN_STATE_COMPLETE,         ///< Link Training Complete (determined we are at local maximum)
    P64H_SYSC_LT_TRAIN_STATE_LAST              ///< invalid, only used for error checking
} p64h_sysc_lt_train_state_t;

/// Substate while performing a Far End Coefficient Update
typedef enum {
    P64H_SYSC_LT_UPD_STATE_RESET = 0u,  ///< No Far End Coefficient Update has been issued, Sub State Machine inactive
    P64H_SYSC_LT_UPD_STATE_WAIT,        ///< Currently waiting for the Far End SerDes to update it's tap settings
    P64H_SYSC_LT_UPD_STATE_FOM_MEASURE, ///< Measuring the Figure of Merit
    P64H_SYSC_LT_UPD_STATE_LAST,        ///< invalid, only used for error checking
} p64h_sysc_lt_upd_state_t;

///
typedef union __attribute__((packed)) {
    uint32_t w;
    struct __attribute__((packed)) {
        uint32_t c0          : 6;
        uint32_t cm1         : 6;
        uint32_t cp1         : 6;
        uint32_t area        : 12;
        uint32_t fill_30     : 1;
        uint32_t entry_valid : 1;
    } b;
} p64h_sysc_lt_fom_t;

#define P64H_SYSC_LT_NUM_C0_SETTINGS          64u
#define P64H_SYSC_LT_NUM_CP1_SETTINGS         64u
#define P64H_SYSC_LT_NUM_CM1_SETTINGS         64u

#define P64H_SYSC_LT_MAX_NUM_FOM_MEASUREMENTS 512u
#define P64H_SYSC_LT_FOM_WINDOW_SIZE          5u

/// A struct containing the full state including any relevant substates, and the array of TAP settings tried and FOM
typedef struct __attribute__((packed)) {
    p64h_sysc_anlt_sm_state_t  anlt_state;     ///< Current overall ANLT state
    p64h_sysc_lt_train_state_t lt_train_state; ///< Current substate within the SEND_TRAINING state of the overall statemachine
    uint8_t                    c0_max;
    uint8_t                    cm1_max;
    uint8_t                    cp1_max;
    p64h_sysc_lt_upd_state_t   lt_upd_state; ///< Current substate when attempting to update the Far End SerDes tap settings
    uint8_t                    num_fom;
    uint32_t                   fom_curr;
    p64h_sysc_lt_fom_t         fom[P64H_SYSC_LT_MAX_NUM_FOM_MEASUREMENTS]; ///< A list of all Figure of Merit Measurements we have taken so far
} p64h_sysc_anlt_sm_ds_t;

#endif