/*************************************************************************
 *  (c) 2024 Microchip Technology Inc.
 *  SPDX-License-Identifier: MIT
 * 
 *   DESCRIPTION:
 *     Contains all register offset and register bit definitions for the
 *     mbox_req block
 ************************************************************************/
#ifndef HPSC_MBOX_REQ_REGS_H
#define HPSC_MBOX_REQ_REGS_H


/*-----------------.
 | block structure |
 +----------------*/

/**
 * MBOX_REQ_t
 */
typedef struct {
    volatile uint32_t       r_RAM[512];   ///< 0x00000000 + 0x4*N(N=0:511) MBOX_REQ_reg_RAM_t
    volatile uint32_t       r_CTRL;       ///< 0x00000800                  MBOX_REQ_reg_CTRL_t
    volatile uint32_t const r_STAT;       ///< 0x00000804                  MBOX_REQ_reg_STAT_t
    uint32_t                fill_808[2];  ///< padding
    volatile uint32_t       r_INT_EN;     ///< 0x00000810                  MBOX_REQ_reg_INT_EN_t
    volatile uint32_t       r_INT_VAL;    ///< 0x00000814                  MBOX_REQ_reg_INT_VAL_t
    volatile uint32_t       r_INT_STAT;   ///< 0x00000818                  MBOX_REQ_reg_INT_STAT_t
    uint32_t                fill_81c[25]; ///< padding
    volatile uint32_t       r_CONTROL;    ///< 0x00000880                  MBOX_REQ_reg_CONTROL_t
} MBOX_REQ_t;

/*---------------.
 | offset checks |
 +--------------*/

#ifdef __cplusplus
static_assert(offsetof(MBOX_REQ_t,r_RAM[511])  == 0x000007fc,"offset wrong for RAM");
static_assert(offsetof(MBOX_REQ_t,r_CTRL)      == 0x00000800,"offset wrong for CTRL");
static_assert(offsetof(MBOX_REQ_t,r_STAT)      == 0x00000804,"offset wrong for STAT");
static_assert(offsetof(MBOX_REQ_t,r_INT_EN)    == 0x00000810,"offset wrong for INT_EN");
static_assert(offsetof(MBOX_REQ_t,r_INT_VAL)   == 0x00000814,"offset wrong for INT_VAL");
static_assert(offsetof(MBOX_REQ_t,r_INT_STAT)  == 0x00000818,"offset wrong for INT_STAT");
static_assert(offsetof(MBOX_REQ_t,r_CONTROL)   == 0x00000880,"offset wrong for CONTROL");
#endif // __cplusplus

/*---------------------.
 | register structures |
 +--------------------*/


/**
 * (0x00000000 + (N) * 0x4) RAM
 *
 * bits 31:0 default XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX DATA
 *     Mailbox RAM space used to transfer data between requestor and responder
 *         as part of service requests and responses.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_DATA; ///< bit  0..31 R/W
  } b; ///< access bit fields
} MBOX_REQ_reg_RAM_t;

/**
 * 0x00000800 CTRL
 *
 * bits        0     default 0   REQ
 *     Mailbox service request bit.  When set to 1 requests a system service
 *         specified by the COMMAND field by triggering the REQ_I event on the
 *         responder side of the mailbox.
 *     This bit self-clears to 0 when the responder side of the Mailbox signals
 *         DONE.
 * bits        8     default 0   ABORT
 *     Mailbox service abort bit.  When set to 1 it indicates that any
 *         outstanding service request may be aborted (result not needed)
 *         triggering the ABORT_I event on the responder side of the mailbox.
 *     This bit self-clears to 0 when the responder side of the Mailbox signals
 *         ABORT_ACK.
 * bits        31:16 default 0x0 COMMAND
 * field_bits  15:0
 *     The 16-bit service request command value.
 *     The COMMAND field may be written in the same write transaction used to
 *         set the REQ bit to 1.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_REQ:1;     ///< bit  0      R/W
    uint32_t fill_1_7:7;  ///< padding
    uint32_t f_ABORT:1;   ///< bit  8      R/W
    uint32_t fill_9_15:7; ///< padding
    uint16_t f_COMMAND;   ///< bit  16..31 R/W
  } b; ///< access bit fields
} MBOX_REQ_reg_CTRL_t;

/**
 * 0x00000804 STAT
 *
 * bits        0     default X                BUSY
 *     Indicates if Mailbox has a pending service request.  The BUSY bit is a
 *         read-only mirror of the REQ bit state.
 *     When set to logic:
 *     1: Mailbox is busy, no request should be sent to the Mailbox.  The BUSY
 *         bit is set to 1 when the REQ bit is set to 1 to request a service
 *         action.
 *     0: Mailbox is not busy.  The BUSY bit is cleared to 0 when the responder
 *         side of the Mailbox signals DONE.
 * bits        8     default X                ABORT_PENDING
 *     Indicates if Mailbox has a pending abort request.  The ABORT_PENDING bit
 *         is a read-only mirror of the ABORT bit state.
 *     When set to logic:
 *     1: An abort request was made but not yet acknowledged, no request should
 *         be sent to the Mailbox.  The ABORT_PENDING bit is set to 1 when the
 *         ABORT bit is set to 1 to signal an abort request.
 *     0: No pending abort request.  The ABORT_PENDING bit is cleared to 0 when
 *         the responder side of the Mailbox signals ABORT_ACK.
 * bits        31:16 default XXXXXXXXXXXXXXXX STATUS
 * field_bits  15:0
 *     The 16-bit service response value.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_BUSY:1;          ///< bit  0      R
    uint32_t fill_1_7:7;        ///< padding
    uint32_t f_ABORT_PENDING:1; ///< bit  8      R
    uint32_t fill_9_15:7;       ///< padding
    uint16_t f_STATUS;          ///< bit  16..31 R
  } b; ///< access bit fields
} MBOX_REQ_reg_STAT_t;

/**
 * 0x00000810 INT_EN
 *
 * bits 0 default 0 DONE_E
 *     Interrupt enable for the associated interrupt.
 *     When set to logic:
 *     1: The associated interrupt bit will be propagated to the interrupt pin
 *         to allow interrupt processing.
 *     0: The associated interrupt bit can only be processed through polling.
 * bits 4 default 0 ABORT_ACK_E
 *     Interrupt enable for the associated interrupt.
 *     When set to logic:
 *     1: The associated interrupt bit will be propagated to the interrupt pin
 *         to allow interrupt processing.
 *     0: The associated interrupt bit can only be processed through polling.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_DONE_E:1;      ///< bit  0 R/W
    uint32_t fill_1_3:3;      ///< padding
    uint32_t f_ABORT_ACK_E:1; ///< bit  4 R/W
    uint32_t fill_5_31:27;    ///< padding
  } b; ///< access bit fields
} MBOX_REQ_reg_INT_EN_t;

/**
 * 0x00000814 INT_VAL
 *
 * bits 0 default 0 DUMMY_INT_VAL
 *     Placeholder for interrupt status register
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_DUMMY_INT_VAL:1; ///< bit  0 -
    uint32_t fill_1_31:31;      ///< padding
  } b; ///< access bit fields
} MBOX_REQ_reg_INT_VAL_t;

/**
 * 0x00000818 INT_STAT
 *
 * bits 0 default 0 DONE_I
 * attribute: int_edge=rising
 * attribute: clk=same
 *     Service request done interrupt.
 *     When read as logic:
 *     1: The responder side of the Mailbox signalled DONE.  The service
 *         request response is available in the STATUS field.
 *     0: No event has occurred.
 * bits 4 default 0 ABORT_ACK_I
 * attribute: int_edge=rising
 * attribute: clk=same
 *     Service request aborted interrupt.
 *     When read as logic:
 *     1: The responder side of the Mailbox signalled ABORT_ACK.
 *     0: No event has occurred.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t f_DONE_I:1;      ///< bit  0 R/W
    uint32_t fill_1_3:3;      ///< padding
    uint32_t f_ABORT_ACK_I:1; ///< bit  4 R/W
    uint32_t fill_5_31:27;    ///< padding
  } b; ///< access bit fields
} MBOX_REQ_reg_INT_STAT_t;

/**
 * 0x00000880 CONTROL
 *
 * bits 2 default 0 SW_INT_BYP_CTRL
 *     Software interrupt bypss control.  Set to 1 to allow software/firmware
 *         to set any interrupt status bit to 1 by writing 1 to that interrupt
 *         bit.  This is of value to SW/FW development, as well as software
 *         test.
 * bits 4 default 1 DECERR_EN
 *     This is simply a RW bit that defaults to 1 and ANDs the DECERR
 *         indication output by the PCBI NREGs block. DECERR is asserted if a
 *         read or write access is attempted at an unused address space, for
 *         example an address that has no register bits defined). This can be
 *         problematic when AXI burst read/write transactions such as cache
 *         line reads/writes are used.
 *     When set to 0, DECERR_EN bit provides a low-effort means to adjust the
 *         NREGS behaviour per XCBI/PCBI NREGS block so it will not produce
 *         decerr in such a situation where a designer has put an address space
 *         hole within a cache-line, and thereby allow the burst transaction
 *         (such a cache-line access) to complete with OKAY response, by
 *         setting DECERR_EN=0.
 */
typedef union {
  uint32_t w; ///< access 32 bit register
  struct {
    uint32_t fill_0_1:2;          ///< padding
    uint32_t f_SW_INT_BYP_CTRL:1; ///< bit  2 R/W
    uint32_t fill_3:1;            ///< padding
    uint32_t f_DECERR_EN:1;       ///< bit  4 R/W
    uint32_t fill_5_31:27;        ///< padding
  } b; ///< access bit fields
} MBOX_REQ_reg_CONTROL_t;

/// register offsets
///@{
#define MBOX_REQ_REG_RAM( N ) (0x00000000 + (N) * 0x4)
#define MBOX_REQ_REG_CTRL     0x00000800
#define MBOX_REQ_REG_STAT     0x00000804
#define MBOX_REQ_REG_INT_EN   0x00000810
#define MBOX_REQ_REG_INT_VAL  0x00000814
#define MBOX_REQ_REG_INT_STAT 0x00000818
#define MBOX_REQ_REG_CONTROL  0x00000880
///@}

/// field defines
///@{

#define MBOX_REQ_REG_RAM_INDEX_N_Min    0
#define MBOX_REQ_REG_RAM_INDEX_N_Max    511
#define MBOX_REQ_REG_RAM_INDEX_N_Size   512
#define MBOX_REQ_REG_RAM_INDEX_N_Offset 0x4

#define MBOX_REQ_REG_RAM_UnusedMsk      0x00000000
#define MBOX_REQ_REG_RAM_Default        0x00000000
#define MBOX_REQ_REG_RAM_BIT_DATA_Msk   0xffffffff
#define MBOX_REQ_REG_RAM_BIT_DATA_Pos   0


#define MBOX_REQ_REG_CTRL_UnusedMsk       0x0000fefe
#define MBOX_REQ_REG_CTRL_Default         0x00000000
#define MBOX_REQ_REG_CTRL_BIT_REQ_Msk     0x00000001
#define MBOX_REQ_REG_CTRL_BIT_REQ_Pos     0
#define MBOX_REQ_REG_CTRL_BIT_ABORT_Msk   0x00000100
#define MBOX_REQ_REG_CTRL_BIT_ABORT_Pos   8
#define MBOX_REQ_REG_CTRL_BIT_COMMAND_Msk 0xffff0000
#define MBOX_REQ_REG_CTRL_BIT_COMMAND_Pos 16


#define MBOX_REQ_REG_STAT_UnusedMsk             0x0000fefe
#define MBOX_REQ_REG_STAT_Default               0x00000000
#define MBOX_REQ_REG_STAT_BIT_BUSY_Msk          0x00000001
#define MBOX_REQ_REG_STAT_BIT_BUSY_Pos          0
#define MBOX_REQ_REG_STAT_BIT_ABORT_PENDING_Msk 0x00000100
#define MBOX_REQ_REG_STAT_BIT_ABORT_PENDING_Pos 8
#define MBOX_REQ_REG_STAT_BIT_STATUS_Msk        0xffff0000
#define MBOX_REQ_REG_STAT_BIT_STATUS_Pos        16


#define MBOX_REQ_REG_INT_EN_UnusedMsk           0xffffffee
#define MBOX_REQ_REG_INT_EN_Default             0x00000000
#define MBOX_REQ_REG_INT_EN_BIT_DONE_E_Msk      0x00000001
#define MBOX_REQ_REG_INT_EN_BIT_DONE_E_Pos      0
#define MBOX_REQ_REG_INT_EN_BIT_ABORT_ACK_E_Msk 0x00000010
#define MBOX_REQ_REG_INT_EN_BIT_ABORT_ACK_E_Pos 4


#define MBOX_REQ_REG_INT_VAL_UnusedMsk             0xfffffffe
#define MBOX_REQ_REG_INT_VAL_Default               0x00000000
#define MBOX_REQ_REG_INT_VAL_BIT_DUMMY_INT_VAL_Msk 0x00000001
#define MBOX_REQ_REG_INT_VAL_BIT_DUMMY_INT_VAL_Pos 0


#define MBOX_REQ_REG_INT_STAT_UnusedMsk           0xffffffee
#define MBOX_REQ_REG_INT_STAT_Default             0x00000000
#define MBOX_REQ_REG_INT_STAT_BIT_DONE_I_Msk      0x00000001
#define MBOX_REQ_REG_INT_STAT_BIT_DONE_I_Pos      0
#define MBOX_REQ_REG_INT_STAT_BIT_ABORT_ACK_I_Msk 0x00000010
#define MBOX_REQ_REG_INT_STAT_BIT_ABORT_ACK_I_Pos 4


#define MBOX_REQ_REG_CONTROL_UnusedMsk               0xffffffeb
#define MBOX_REQ_REG_CONTROL_Default                 0x00000010
#define MBOX_REQ_REG_CONTROL_BIT_SW_INT_BYP_CTRL_Msk 0x00000004
#define MBOX_REQ_REG_CONTROL_BIT_SW_INT_BYP_CTRL_Pos 2
#define MBOX_REQ_REG_CONTROL_BIT_DECERR_EN_Msk       0x00000010
#define MBOX_REQ_REG_CONTROL_BIT_DECERR_EN_Pos       4
///@}

#endif /* HPSC_MBOX_REQ_REGS_H */
