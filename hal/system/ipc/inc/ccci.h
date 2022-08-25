/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of CCCI.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCCI_H__
#define __CCCI_H__

#if defined(__SMART_PHONE_MODEM__)


#include "kal_general_types.h"
#include "kal_public_defs.h"

//#define ARM9
//#define TK6516

#if (defined(TK6516) || defined(MT6516) || defined(MT6573)) && defined(__APPLICATION_PROCESSOR__)
#define CCCI_FOR_AP_SIDE
#else /* (TK6516 || MT6516) && __APPLICATION_PROCESSOR__ */
#define CCCI_FOR_MD_SIDE
#endif /* (TK6516 || MT6516 ) && __APPLICATION_PROCESSOR__ */

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/

/* CCCI API return value */
typedef enum
{
    CCCI_SUCCESS = 0,
    CCCI_FAIL = -1001,
    CCCI_IN_USE = -1002,
    CCCI_NOT_OWNER = -1003,
    CCCI_INVALID_PARAM = -1004,
    CCCI_NO_PHY_CHANNEL = -1005,
    CCCI_IN_LISR = -1006
}CCCI_RETURNVAL_T;

/* CCCI status */
typedef enum
{
    CCCI_IDLE = 0x00,
    CCCI_ACTIVE_READ = 0x01,
    CCCI_ACTIVE_WRITE = 0x02,
    CCCI_ACTIVE_ISR = 0x04
} CCCI_STATE_T;

/* CCCI logical channel */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    CCCI_CONTROL_CHANNEL = 0,
    CCCI_CONTROL_CHANNEL_ACK =1,
    CCCI_SYSTEM_CHANNEL = 2,
    CCCI_SYSTEM_CHANNEL_ACK = 3,
    CCCI_PCM_CHANNEL = 4,
    CCCI_PCM_CHANNEL_ACK = 5,
    CCCI_TST_CHANNEL = 6,
    CCCI_TST_ACK_CHANNEL = 7,
    CCCI_TR_CHANNEL = 8,
    CCCI_TR_ACK_CHANNEL = 9,
    CCCI_AT_CHANNEL_TX = 10,
    CCCI_AT_ACK_CHANNEL_TX = 11,
    CCCI_AT_CHANNEL_RX = 12,
    CCCI_AT_ACK_CHANNEL_RX = 13,
    CCCI_FS_CHANNEL = 14,
    CCCI_FS_ACK_CHANNEL = 15,
    CCCI_PMIC_CHANNEL = 16,
    CCCI_PMIC_ACK_CHANNEL = 17,
    CCCI_UEM_CHANNEL = 18,
    CCCI_UEM_ACK_CHANNEL = 19,
    CCCI_CCMNI1_RX = 20,
    CCCI_CCMNI1_RX_ACK = 21,
    CCCI_CCMNI1_TX = 22,
    CCCI_CCMNI1_TX_ACK = 23,
	CCCI_CCMNI2_RX = 24,
	CCCI_CCMNI2_RX_ACK = 25,
	CCCI_CCMNI2_TX = 26,
	CCCI_CCMNI2_TX_ACK = 27,
	CCCI_CCMNI3_RX = 28,
	CCCI_CCMNI3_RX_ACK = 29,
	CCCI_CCMNI3_TX = 30,
	CCCI_CCMNI3_TX_ACK = 31,
	CCCI_IPC_RPC_CHANNEL = 32,
    CCCI_IPC_RPC_ACK_CHANNEL = 33,
    CCCI_MSGSVC_SEND_CHANNEL = 34,
    CCCI_MSGSVC_SEND_ACK_CHANNEL = 35,
    CCCI_MSGSVC_RCV_CHANNEL = 36,
    CCCI_MSGSVC_RCV_ACK_CHANNEL = 37,
	CCCI_GPS_CHANNEL_TX = 38,
    CCCI_GPS_ACK_CHANNEL_TX = 39,
    CCCI_GPS_CHANNEL_RX = 40,
    CCCI_GPS_ACK_CHANNEL_RX = 41,
    CCCI_MD_LOG_RX = 42,
    CCCI_MD_LOG_TX = 43,
    CCCI_MAX_CHANNEL = 44,
    CCCI_FORCE_RESET_MODEM_CHANNEL = 20090215
} CCCI_CHANNEL_T;

/* CCCI mailbox channel structure */
typedef struct
{
    kal_uint32 magic;   /* 0xFFFFFFFF */
    kal_uint32 id;
} CCCI_MAILBOX_T;

/* CCCI stream channel structure */
typedef struct
{
    kal_uint32 addr;
    kal_uint32 len;
} CCCI_STREAM_T;

/* CCCI channel buffer structure */
typedef struct
{
    kal_uint32 data[2];
    kal_uint32 channel;
    kal_uint32 reserved;
} CCCI_BUFF_T;

/* CCCI callback function prototype */
typedef void (*CCCI_CALLBACK)(CCCI_BUFF_T *buff);

/* CCCI control structure */
typedef struct
{
    CCCI_STATE_T state;
    kal_uint32 owner;
    CCCI_BUFF_T buff;
    CCCI_CALLBACK funp;
    kal_eventgrpid event;
} CCCI_CTRL_T;



/* CCCI RunTime Data structure */
/*      NOTICE: Negotiations With AP Side Owner Before Modification */

/* DriverVersion */
#define CCCI_CURRENT_VERSION      0x20110118

/* BootingStartID */
#define NORMAL_BOOT_ID            0
#define META_BOOT_ID              1

/* BootAttributes */
#define BOOT_ATTR_IS_CLEAN_BOOT   0x00000001


#define UART_MAX_PORT_NUM 8


typedef struct MODEM_RUNTIME_DATA_T
{
    kal_uint8    Prefix[4];            // "CCIF"
    kal_uint8    Platform[8];          // Hardware Platform String ex: "MT6516E1"
    kal_uint32   DriverVersion;        // 0x00000929 since W09.29
    kal_uint32   BootChannel;          // Channel to ACK AP with boot ready
    kal_uint32   BootingStartID;       // MD is booting. NORMAL_BOOT_ID or META_BOOT_ID 
    kal_uint32   BootAttributes;       // Attributes passing from AP to MD Booting
    kal_uint32   BootReadyID;          // MD response ID if boot successful and ready ,
                                       // Cannot equal to CCMSG_ID_DRV_VERSION_ERR
    kal_uint32   MdlogShareMemBase;
    kal_uint32   MdlogShareMemSize;
    kal_uint32   PcmShareMemBase;
    kal_uint32   PcmShareMemSize;
    kal_uint32   UartPortNum;
    kal_uint32   UartShareMemBase[UART_MAX_PORT_NUM];
    kal_uint32   UartShareMemSize[UART_MAX_PORT_NUM];    
    kal_uint32   FileShareMemBase;
    kal_uint32   FileShareMemSize;
	kal_uint32   RpcShareMemBase;
	kal_uint32   RpcShareMemSize;
    kal_uint32   PmicShareMemBase;
    kal_uint32   PmicShareMemSize;
    kal_uint32   ExceShareMemBase;
    kal_uint32   ExceShareMemSize;     // 512 Bytes Required 
    kal_uint32   SysShareMemBase;
    kal_uint32   SysShareMemSize;      // AP MD run-time share data
    kal_uint32   IPCShareMemBase;
    kal_uint32   IPCShareMemSize;      // AP MD run-time share data
    kal_uint32   CheckSum;
    kal_uint8    Postfix[4];       //"CCIF"
}MODEM_RUNTIME_DATA;

extern MODEM_RUNTIME_DATA ap_md_share_data;
/* CCCI Message ID Passing Through CONTROL_CHANNEL and SYSTEM_CHANNEL */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    CCMSG_ID_START_BOOT        = 0x00000000,
    CCMSG_ID_NORMAL_BOOT_READY = 0x00000001,
    CCMSG_ID_META_BOOT_READY   = 0x00000002,
    CCMSG_ID_RESET             = 0x00000003,
    CCMSG_ID_EXCEPTION_CHECK   = 0x00000004,
    CCMSG_ID_DRV_VERSION_ERR   = 0x00000005,
    CCMSG_ID_EXCEPTION_REC_OK  = 0x00000006,
    /* System Channel */
    CCMSG_ID_MD_EINT_POLARITY  = 0x00000007,
    CCMSG_ID_MD_EINT_ON_OFF    = 0x00000008,
    CCMSG_ID_MD_EINT_ACK       = 0x0000000B,
    CCMSG_ID_MD_OS_TICK_UPDATE = 0x00000009,
    CCMSG_ID_MD_OS_TICK_QUERY  = 0x0000000A,
    CCMSG_ID_MD_PERIODIC_COM   = 0x0000000C,
    CCMSG_ID_MD_PERIODIC_ACK   = 0x0000000D,
    CCMSG_ID_MD_L4_MOD         = 0x0000000E,//add for RIL (AP task) and L4C (MD task) communication message
}CONTROL_CHANNEL_MSG;




/* Structure usage for L1SM */
#define CCCI_EXCHANGE_SLEEP_STATE_AWAKEN   (0)
#define CCCI_EXCHANGE_SLEEP_STATE_SLEEP    (1)
#define CCCI_EXCHANGE_SLEEP_STATE_SLUMBER  (2)

typedef struct
{
   kal_uint8    AP_Sleep;             // flag for AP to inform MD sleeping state
                                      // 0 awaken, 1 sleep with alarm , 2 slumber... until event
   kal_uint8    paddingA1;            // un-used , explict and manually alignment to prevent mistake
   kal_uint8    paddingA2;            // un-used , explict and manually alignment to prevent mistake
   kal_uint8    paddingA3;            // un-used , explict and manually alignment to prevent mistake
   kal_uint32   RTC_AP_WakeUp;        // The time AP will wake up
   kal_uint32   AP_SettleTime;        // The time for 26M clock to settle
   kal_uint8    MD_Sleep;             // flag for MD to inform AP sleep state
                                      // 0 awaken, 1 sleep with alarm 
   kal_uint8    paddingM1;            // un-used , explict and manually alignment to prevent mistake
   kal_uint8    paddingM2;            // un-used , explict and manually alignment to prevent mistake
   kal_uint8    paddingM3;            // un-used , explict and manually alignment to prevent mistake
   kal_uint32   RTC_MD_WakeUp;        // The time MD will wake up
   kal_uint32   RTC_MD_Settle_OK;     // The time MD will finish 26M clock settle
}EXCHANGE_SLEEP_TICKS;

typedef struct
{
   kal_uint8    eint_no;              // eint no.
   kal_bool     Sensitivity;          // config level or edge sensitivity
                                      // follow spec. level = 1 and edge = 0
   kal_bool     ACT_Polarity;         // if edge sensitivity, positive or negative
   kal_bool     Dbounce_En;           // enable the debounce
   kal_uint32   Dbounce_ms;           // debounce time in mini-second
}PROPAGATE_EINT_CFG;

typedef struct
{
   EXCHANGE_SLEEP_TICKS   sleep_mode_data;      // exchange sleep mode data
   kal_uint32             cfg_report_os_tick;   // Report OS Tick Periodic in second unit 
                                                // ( 0 = disable )
   kal_uint32             eint_array_numbers;   // PROPAGATE_EINT_CFG array valid elements
   kal_uint32             eint_array_offset;    // PROPAGATE_EINT_CFG array location in offset form
                                                // (bytes from SysShareMemBase)
}SYSTEM_EXCHANGE_DATA;

/*******************************************************************************
 * Define marco.
 *******************************************************************************/

/* initialize a CCCI mailbox buffer */
#define CCCI_INIT_MAILBOX(buff, mailbox_id) \
        do {    \
            ((CCCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF; \
            ((CCCI_MAILBOX_T *)(buff))->id = (mailbox_id);  \
            (buff)->channel = CCCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* initialize a CCCI stream buffer */
#define CCCI_INIT_STREAM(buff, stream_addr, stream_len) \
        do {    \
            ((CCCI_STREAM_T *)(buff))->addr = (stream_addr); \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);  \
            (buff)->channel = CCCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* check the CCCI buffer type */
#define CCCI_IS_MAILBOX(buff)   ((((CCCI_MAILBOX_T *)(buff))->magic == 0xFFFFFFFF)? 1: 0)

/* get the id of the CCCI mailbox buffer */
#define CCCI_MAILBOX_ID(buff)   (((CCCI_MAILBOX_T *)(buff))->id)

/* get the addr of the CCCI stream buffer */
#define CCCI_STREAM_ADDR(buff)   (((CCCI_STREAM_T *)(buff))->addr)

/* get the len of the CCCI stream buffer */
#define CCCI_STREAM_LEN(buff)   (((CCCI_STREAM_T *)(buff))->len)


/*******************************************************************************
 * define global variable
 *******************************************************************************/
#define BOOT_CHECK_ID       0x5555FFFF /* magic id : Placed on reserved field */
#define EXCEPTION_CHECK_ID  0x45584350 /* EXCP     : Placed on reserved field */
#define EXCEPTION_REC_READY 0x45524543 /* EREC     : Placed on reserved field */
#define CCCI_WAIT_MAX_TIME  4615


/*******************************************************************************
 * Declare function prototype.
 * User APIs
 *******************************************************************************/

extern kal_int32 ccci_init(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp);
extern kal_int32 ccci_deinit(CCCI_CHANNEL_T channel);
extern kal_int32 ccci_stream_write(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len);
extern kal_int32 ccci_stream_read(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len);
extern kal_int32 ccci_stream_read_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved);
extern kal_int32 ccci_stream_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved);
extern kal_int32 ccci_mailbox_write(CCCI_CHANNEL_T channel, kal_uint32 id);
extern kal_int32 ccci_mailbox_read(CCCI_CHANNEL_T channel);
extern kal_int32 ccci_mailbox_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 id,kal_uint32 reserved);
extern kal_int32 ccci_mailbox_read_with_reserved(CCCI_CHANNEL_T channel,kal_uint32 *reserved);
extern void ccci_GetShareMemInfo( kal_uint32 **info, kal_uint16* count );
extern void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size);
extern kal_bool ccci_queryBootAttributes(kal_uint32 mask);
extern EXCHANGE_SLEEP_TICKS* ccci_query_ptr_of_exchange_sleeptick(void);
extern PROPAGATE_EINT_CFG* ccci_query_ptr_of_exchange_eint(kal_uint32 *number);
extern kal_bool ccci_chk_sententry_not_receive(kal_uint32 query_log, kal_uint32 data);

/*******************************************************************************
 * Declare function prototype.
 * Kernel/System Use APIs
 *******************************************************************************/

extern kal_int32 ccci_read(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff);
extern kal_int32 ccci_write_internal(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff,kal_bool check_lisr);
#define ccci_write(a,b) ccci_write_internal(a,b,1)
extern kal_int32 ccci_owner_init(CCCI_CHANNEL_T channel, kal_taskid task, CCCI_CALLBACK funp);
extern kal_uint32 ccci_query_sharemem_addr(CCCI_CHANNEL_T channel,kal_uint32 *size);
extern void ccci_change_owner_only(CCCI_CHANNEL_T channel,kal_uint8 owner);

extern void ccif_init(kal_uint32 arb, kal_uint32 md_offset);
extern kal_bool ccci_chk_recentry_in_queue(kal_uint32 query_log, kal_bool Is_Ack_All_if_found);
extern void ccci_init_handshake_phase1(void);
extern void ccci_init_handshake_phase2(kal_uint16 _boot_mode);
extern void ccci_exception_handshake(void) ;
extern void ccci_exception_info_passed(void) ;
extern void ccci_except_ack(CCCI_BUFF_T *bufp);
extern kal_bool ccci_send_sharemem_to_ap(kal_uint32* data_to_ap, kal_uint32 data_size, kal_uint32 reserved);

#endif /* __SMART_PHONE_MODEM__ */

#endif  /* !__CCCI_H__ */


