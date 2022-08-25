/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2005
 *
 *  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 *  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 *  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 *  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
 *  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
 *  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
 *  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 *  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
 *  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
 *
 *  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
 *  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
 *  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
 *  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
 *  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
 *
 *****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 * BtcmSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use BT CM related apis
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_CM_ADP_H
#define BT_CM_ADP_H

// RHR: add
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
// RHR: add

#include "app_ltlcom.h"
#include "bluetooth_bm_struct.h"
#include "nvram_interface.h"
#include "custom_mmi_default_value.h"
#include "kal_trace.h"

#define U32 kal_uint32
#define S32 kal_int32
#define U8 kal_uint8
//#define S8 (signed char)
#define U16 kal_uint16
#define S16 kal_int16
#define MMI_BOOL kal_bool
#define MMI_FALSE KAL_FALSE
#define MMI_TRUE KAL_TRUE
typedef signed char                *PS8;    /* signed 8 bit integer pointer */
typedef unsigned short int  *PU16;   /* unsigned 16 bit integer pointer */
typedef unsigned char       *PU8;    /* unsigned 8 bit integer pointer */
typedef PU8                 UI_buffer_type;
typedef U16                 UI_character_type;

typedef unsigned short      MMI_ID_TYPE;
typedef U16                 MMI_ID;         /* app id, group id, screen id */
typedef U16                 MMI_IMG_ID;     /* image or icon */
typedef U16                 MMI_STR_ID;     /* string */
typedef U16                 MMI_MENU_ID;    /* menu item id, hilite id, hint id */
typedef U16                 MMI_TIMER_ID;   /* timer */
typedef U16                 MMI_EVENT_ID;

typedef unsigned int mmi_scenario_id;


#ifndef ENCODING_LENGTH
#define ENCODING_LENGTH       2
#endif
#define MMI_TRACE  kal_brief_trace
#define MMI_CONN_TRC_G7_B TRACE_GROUP_7 
#define MMI_CONN_TRC_G7_BT TRACE_GROUP_7
#define MMI_COMMON_TRC_G5_CALL TRACE_GROUP_7
#define MMI_MEDIA_TRC_G2_APP TRACE_GROUP_7
#define MMI_MEDIA_TRC_G4_MDI TRACE_GROUP_7
#define MMI_MEDIA_TRC_G10_MMI_PRINT TRACE_GROUP_7
#define MMI_MEDIA_TRC_G3_APP_DETAIL TRACE_GROUP_7
#if !defined(__BLE_GATT__)
#define MOD_MMI_CONN_APP MOD_BCM
#define MOD_MMI MOD_BCM
#endif
#define MMI_ASSERT(expr)      ASSERT(expr)

#define mmi_ret kal_uint32
#define StartTimer(timerid, delay, funcPtr)  bcm_restart_timer(timerid,delay,funcPtr##_bcm_adp)
#define StartTimerEx(timerid, delay, funcPtr, arg)  bcm_restart_timerEx(timerid,delay,funcPtr##_bcm_adp,arg)
#define StopTimer(timerid) bcm_stop_timer(timerid)
extern void srv_bt_cm_set_temp_visibility_timeout_bcm_adp(void *data);
extern void srv_bt_cm_release_all_conn_timeout_hdlr_bcm_adp(void *data);
extern void srv_bt_cm_switch_off_timeout_hdlr_bcm_adp(void *data);
extern void srv_bt_cm_set_limit_visibility_timeout_hdlr_bcm_adp(void *data);
extern void mmi_a2dp_delay_open_callback_hdlr_bcm_adp(void *data);
extern void srv_a2dp_pause_stream_hdlr_bcm_adp(void *data);
extern void srv_avrcp_auto_release_cmd_bcm_adp(void *data,void *arg);



#define CHAR char  
typedef void (*FuncPtr) (void);
typedef void (*FuncPtr_void) (void* data);

#define OslMalloc(nob)  get_ctrl_buffer(nob)
#define OslMfree(frp)   free_ctrl_buffer(frp)

#define MMI_RET_OK          (0)         /* the return value of mmi_ret */
#define MMI_RET_DONT_CARE   (-499)      /* the return value of mmi_ret */
#define MMI_RET_ERR         (-500)      /* the return value of mmi_ret */
#define ReadRecordSlim(nLID, nRecordId,pBuffer,nBufferSize) \
    ASSERT(nvram_external_read_data(nLID, nRecordId, (kal_uint8*)pBuffer, nBufferSize))
#define WriteRecordSlim(nLID, nRecordId,pBuffer,nBufferSize) \
    ASSERT(nvram_external_write_data(nLID, nRecordId, (kal_uint8*)pBuffer, nBufferSize))

#define ReadRecord(nLID, nRecordId,pBuffer,nBufferSize, pErr) ReadRecordSlim(nLID, nRecordId,pBuffer,nBufferSize)
#define WriteRecord(nLID, nRecordId,pBuffer,nBufferSize, pErr) WriteRecordSlim(nLID, nRecordId,pBuffer,nBufferSize)
#define ReadValueSlim(_arg0, _arg1, _arg2) MMI_FALSE
#define WriteValueSlim(_arg0, _arg1, _arg2) MMI_FALSE
#define mmi_frm_reset_record(_arg0, _arg1, _arg2, _arg3, _arg4) 0
#define mmi_frm_write_async_record WriteRecordSlim
//typedef S32 				MMI_RET;
#define MMI_RET S32


#define MMI_EVT_PARAM_HEADER	\
        kal_uint16 evt_id;             \
        kal_uint16 size;               \
        void *user_data;


/* Post event mechanism */
typedef struct// _mmi_event_struct
{
	/* Event id */
    U16 evt_id; 
    /* Event structure size */
    U16 size; 
    /* User data pointer */
    void *user_data;
}mmi_event_struct;



/* mmi proc function type */
typedef mmi_ret (*mmi_proc_func) (mmi_event_struct *param); 
//typedef unsigned char	BOOL;
//typedef char				S8; 	 /* signed 8 bit integer */
typedef U8(*PsIntFuncPtr) (void *);
typedef unsigned short		MMI_ID_TYPE;

#ifndef __UCS2_ENCODING
#define __UCS2_ENCODING
#endif

#ifdef __UCS2_ENCODING
typedef	U16					UI_character_type;
#else
typedef U8					UI_character_type;
#endif

typedef UI_character_type*	UI_string_type;

/* Define local parameter type. */
#define oslParaType     local_para_struct

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

/* This enum is used to indicate the three framework NVRAM cache type and their values stand for  the small data item size. */
typedef enum
{
    /* Corresponding to NVRAM_EF_CACHE_BYTE_LID. */
    DS_BYTE = 1,
    /* Corresponding to NVRAM_EF_CACHE_SHORT_LID. */
    DS_SHORT = 2,
    /* Corresponding to NVRAM_EF_CACHE_DOUBLE_LID. */
    DS_DOUBLE = 8
} DATASIZE;

/* This enum is used to indicate the NVRAM operation error code. */
typedef enum
{   
    /* Read NVRAM fail. */
    NVRAM_READ_FAIL,
    /* Read NVRAM success. */
    NVRAM_READ_SUCCESS,
    /* Read NVRAM actual size is greater than requested size. */
    NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ,
    /* Read NVRAM actual size is less than requested size. */
    NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ,
    /* Write NVRAM success. */
    NVRAM_WRITE_SUCCESS,
    /* Write NVRAM fail. */
    NVRAM_WRITE_FAIL
} MMINVRAMERRORSENUM;



//#define MMI_TRACE(...)
#define kal_buffer_trace(...)


/*
 * This is deprecated API: OslConstructDataPtr; 
 * Please use mmi_construct_msg_local_para to construct the local parameter of the message. 
 */
#define OslConstructDataPtr(size)     construct_local_para((kal_uint16)(size), (TD_CTRL | TD_RESET))
#define OslIntConstructDataPtr(size)  construct_local_para((kal_uint16)(size), (TD_CTRL | TD_RESET))

#define mmi_frm_send_ilm(_arg0, _arg1, _arg2, _arg3)

#define MMI_FRM_CB_EMIT_EVENT(_evt) 0
#define MMI_FRM_CB_EMIT_POST_EVENT(_evt)
#define mmi_frm_cb_emit_post_event(_evt)

#define get_audio(_arg0, _arg1, _arg2) NULL


#define BT_SCO_CONNECT_TIMER 1000 
#define BT_SCO_ENABLE_CONNECT_DELAY_TIMER 1001 

#define APP_BT_DIALER 10000

#define SRV_SHUTDOWN_BASE 1000

/*
 * DESCRIPTION
 *  Event IDs of shutdown events.
 */
typedef enum
{
    /*
     * [INTERNAL]
     * Internal event to launch normal shutdown flow. Shutdown application core
     * will take over the control flow as received this event.
     *
     * SEE ALSO
     *  srv_shutdown_normal_start_evt_struct
     */

    EVT_ID_SRV_SHUTDOWN_NORMAL_START = SRV_SHUTDOWN_BASE, 
    
    /*
     * The first event of normal shutdown to applications. 
     * This event will be emitted if shutdown is triggered and starting to run.
     * Applications can listen to this event to de-initialize their module.
     * However, it will NOT be emitted for abnormal shutdown, e.g., low-power,
     * USB power-on mode, etc.
     *
     * SEE ALSO
     *  srv_shutdown_deinit_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_DEINIT,
    
    /*
     * The protocol event handlers of framework was all cleared.
     * If application needs to listen protocol events even in shutdown period,
     * this event should be subscribed to re-register handlers.
     *
     * SEE ALSO
     *  srv_shutdown_handler_reset_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_HANDLER_RESET,
    
    /*
     * The final event of shutdown. System is going to power off very soon.
     *
     * SEE ALSO
     *  srv_shutdown_final_deinit_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT,

    EVT_ID_SRV_SHUTDOWN_END_OF_ENUM
} srv_shutdown_event_enum;

#define EVT_ID_SRV_BTSCO_CLOSE_IND EVT_ID_SRV_SHUTDOWN_END_OF_ENUM+1


#define GLOBAL_BASE                     (1)


typedef enum 
{

    /* ----------------------- Common (start) ---------------------------- */
    /* Global string listed here are shared by Pluto and Cosmos */
	
                                    /* [English], [Description] */
    STR_GLOBAL_0 = GLOBAL_BASE,     /* "0", "Global String- 0" */
    STR_GLOBAL_1,                   /* "1", "Global String- 1" */
    STR_GLOBAL_2,                   /* "2", "Global String- 2" */
    STR_GLOBAL_3,                   /* "3", "Global String- 3" */
    STR_GLOBAL_4,                   /* "4", "Global String- 4" */
    STR_GLOBAL_5,                   /* "5", "Global String- 5" */
    STR_GLOBAL_6,                   /* "6", "Global String- 6" */
    STR_GLOBAL_7,                   /* "7", "Global String- 7" */
    STR_GLOBAL_8,                   /* "8", "Global String- 8" */
    STR_GLOBAL_9,                   /* "9", "Global String- 9" */
    STR_GLOBAL_10,                  /* "10", "Global String- 10" */
    STR_GLOBAL_ABORT,               /* "Abort", "Global String- Abort" */
    STR_GLOBAL_ABORTING,            /* "Aborting", "Global String- Aborting" */
    STR_GLOBAL_ACCEPT,              /* "Accept", "Global String- Accept" */
    STR_GLOBAL_ACCOUNTS,            /* "Accounts",	"Accounts- configuration folder" */
    STR_GLOBAL_ACTIVATE,            /* "Activate", "Global String- Activate" */
    STR_GLOBAL_ACTIVATED,           /* "Activated", "Global String- Activated" */  
    STR_GLOBAL_ADD,                 /* "Add", "Global String- Add" */
    STR_GLOBAL_ADDRESS,             /* "Address", "Global String- Address" */
    STR_GLOBAL_ADVANCED,            /* "Advanced", "Global String- Advanced" */
    STR_GLOBAL_ALARM,               /* "Alarm", "Global String- Alarm" */
    STR_GLOBAL_ALWAYS_ASK,          /* "Always ask", "Global String- Always ask" */
    STR_GLOBAL_AS_EMAIL,            /* "As Email", "Global String- As Email- sub option of sending command" */
    STR_GLOBAL_AS_MULTIMEDIA_MSG,   /* "As multimedia message", "Global String- As multimedia message- sub option of sending command" */
    STR_GLOBAL_AS_TEXT_MESSAGE,     /* "As text message", "Global String- As text message- sub option of sending command" */
    STR_GLOBAL_ATTACHMENT,          /* "Attachment", "Global String- Attachment" */
    STR_GLOBAL_AUTHENTICATION,      /* "Authentication","Global String- Authentication" */
    STR_GLOBAL_AUTOMATIC,           /* "Automatic","Global String- Automatic" */
    STR_GLOBAL_BACK,                /* "Back", "Global String- Back" */
    STR_GLOBAL_BLUETOOTH,           /* "Bluetooth", "Global String- Bluetooth" */
    STR_GLOBAL_BUSY_TRY_LATER,      /* "Busy", "STR_GLOBAL_BUSY_TRY_LATER" */
    STR_GLOBAL_CANCEL,              /* "Cancel", "Global String- Cancel" */
    STR_GLOBAL_CANCELLING,          /* "Cancelling", "Global String- Cancelling" */
    STR_GLOBAL_CLEAR,               /* "Clear", "Global String- Clear" */
    STR_GLOBAL_CLOSE,               /* "Close", "Global String- Close" */
    STR_GLOBAL_CONFIRM,             /* "Confirm", "Global String- Confirm" */
    STR_GLOBAL_CONNECT,             /* "Connect", "Global String- Connect" */
    STR_GLOBAL_CONNECTING,          /* "Connecting", "Global String- Connecting" */
    STR_GLOBAL_CONTENT,             /* "Content", "Global String- Content" */
    STR_GLOBAL_CONTINUE,            /* "Cont.", "Global String- Cont.- use as LSK for length limit" */
    STR_GLOBAL_COPY,                /* "Copy", "Global String- Copy" */
    STR_GLOBAL_COPYING,             /* "Copying", "Global String- Copying" */
    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                                    /* "Currently not available", "Global String- the services/operations aren't workable in some situations" */
    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
                                    /* "Not available during the call", "Global String- the services/operations aren't workable during the call" */
    STR_GLOBAL_CUSTOM,              /* "Custom", "Global String- Custom- user defined" */
    STR_GLOBAL_DATA_ACCOUNT,        /* "Data account", "Global String- Data account" */
    STR_GLOBAL_DATA_ACCOUNTS,       /* "Data accounts", "Global String- Data accounts" */
    STR_GLOBAL_DATA_CONN_SETTING,   /* "Data connection settings", "Global String- Data connection settings" */
    STR_GLOBAL_DATE,                /* "Date", "Global String- Date" */
    STR_GLOBAL_DEACTIVATE,          /* "Deactivate", "Global String- Deactivate" */
    STR_GLOBAL_DEFAULT,             /* "Default", "Global String- Default" */
    STR_GLOBAL_DELETE,              /* "Delete", "Global String- Delete" */
    STR_GLOBAL_DELETE_ALL,          /* "Delete All", "Global String- Delete All" */
    STR_GLOBAL_DELETED,             /* "Deleted", "Global String- Deleted" */
    STR_GLOBAL_DELETING,            /* "Deleting", "Global String- Deleting" */
    STR_GLOBAL_DETAILS,             /* "Details", "Global String- Details" */
    STR_GLOBAL_DIAL,                /* "Call", "Global String- Call" */
    STR_GLOBAL_DIALLED_CALLS,       /* "Dialled call", "Global string- Dialled calls" */
    STR_GLOBAL_DISCARD,             /* "Discard","Global String- Discard" */
    STR_GLOBAL_DISCONNECT,          /* "Disconnect", "Global String- Disconnect" */
    STR_GLOBAL_DISCONNECTING,       /* "Disconnecting", "Global String- Disconnecting" */
    STR_GLOBAL_DONE,                /* "Done", "Global String- Done" */
    STR_GLOBAL_DOWNLOAD,            /* "Download", "STR_GLOBAL_DOWNLOAD" */
    STR_GLOBAL_DOWNLOAD_ASK,        /* "Download?", "STR_GLOBAL_DOWNLOAD_ASK" */
    STR_GLOBAL_DOWNLOADING,         /* "Downloading", "STR_GLOBAL_DOWNLOADING" */
    STR_GLOBAL_DRAFTS,              /* "Drafts", "Global String- Drafts" */
    STR_GLOBAL_DRM_FILE_EXISTS,     /* "File Exists", "Global String- File Exists" */
    STR_GLOBAL_DRM_FS_ERROR,        /* "File Access Error", "Global String- File Access Error" */
    STR_GLOBAL_DRM_INVALID_FORMAT,  /* "Format Error", "Global String- Format Error" */
    STR_GLOBAL_DRM_NON_DRM,         /* "Not DRM File", "Global String- Not DRM File" */
    STR_GLOBAL_DRM_PROCESSING,      /* "DRM Processing", "Global String- DRM Processing" */
    STR_GLOBAL_DRM_PROHIBITED,      /* "DRM Prohibited", "Global String- DRM Prohibited" */
    STR_GLOBAL_DRM_RO_RECEIVED,     /* "DRM Rights Received", "Global String- DRM Rights Received" */
    STR_GLOBAL_DRM_SIZE_TOO_BIG,    /* "Size Too Big", "Global String- Size Too Big" */
    STR_GLOBAL_EARPHONE_IN,         /* "Earphone plugged in!", "Global String- String Associated with Ear Phone Plug In Popup." */
    STR_GLOBAL_EARPHONE_OUT,        /* "Earphone plugged Out", "Global String- Earphone plugged Out" */
    STR_GLOBAL_EDIT,                /* "Edit", "Global String- Edit" */
    STR_GLOBAL_EDIT_BEFORE_CALL,    /* "Edit before call", "Global String- Edit before call" */
    STR_GLOBAL_EMAIL,               /* "Email", "Global String- Email" */
    STR_GLOBAL_EMPTY,               /* "Empty", "Global String- Empty" */
    STR_GLOBAL_EMPTY_LIST,          /* "<Empty>", "Global String- <Empty>" */
    STR_GLOBAL_ERROR,               /* "Error", "Global String- Error" */
    STR_GLOBAL_EXIT,                /* "Exit", "Global String- Exit" */
    STR_GLOBAL_FAILED,              /* "Failed", "Global String- Failed" */
    STR_GLOBAL_FAILED_TO_SAVE,      /* "Failed to save", "Global String- Failed to save" */
    STR_GLOBAL_FAILED_TO_SEND,      /* "Failed to send", "Global String- Failed to send" */
    STR_GLOBAL_FAST,                /* "Fast", "Global String- Fast" */
    STR_GLOBAL_FILE_ALREADY_EXISTS, /* "File already exists", "Global String- File already exists" */
    STR_GLOBAL_FILE_NOT_FOUND,      /* "File not found", "Global string- File not found" */
    STR_GLOBAL_FILENAME,            /* "Filename", "Global String- Filename" */
    STR_GLOBAL_FORMAT,              /* "Format", "Global String- Format- the type of file" */
    STR_GLOBAL_FORWARD,             /* "Forward", "Global String- Forward- send message to other recipients" */
    STR_GLOBAL_GO_TO,               /* "Go to", "Global String- Go to- connect the URL" */
    STR_GLOBAL_GPRS,                /* "GPRS", "Global String- GPRS" */
    STR_GLOBAL_GSM,                 /* "GSM", "Global String- GSM" */
    STR_GLOBAL_HELP,                /* "Help", "Global String- Help- show the usage tips or notes" */
    STR_GLOBAL_HIGH,                /* "High", "Global String- High" */
    STR_GLOBAL_HTTP,                /* "HTTP", "Global String- HTTP" */
    STR_GLOBAL_INBOX,               /* "Inbox", "Global String- Inbox" */
    STR_GLOBAL_INCOMING_CALL,       /* "Incoming call", "Global String- Incoming call" */
    STR_GLOBAL_INPUT_METHOD,        /* "Input Method", "Global String- Input Method" */
    STR_GLOBAL_INPUT_METHOD_OPTIONS,        /* "Input Method", "Global String- Input Method" */
    STR_GLOBAL_INSERT_SIM_CARD,     /* "Please insert a SIM card", "Gloabl String - Please insert a SIM card" */
    STR_GLOBAL_INSTALL,             /* "Install", "Global String- Install" */
    STR_GLOBAL_INSUFFICIENT_MEMORY, /* "Insufficient memory", "Global String- Insufficient memory- not enough RAM to operate" */
    STR_GLOBAL_INVALID,             /* "Invalid", "Global String- Invalid" */
    STR_GLOBAL_INVALID_DATA_ACCOUNT,    /* "Invalid data account. Configure?", "Global String- Invalid data account. Configure?" */
    STR_GLOBAL_INVALID_EMAIL_ADDRESS,   /* "Invalid Email address", "Global String- Invalid Email address" */
    STR_GLOBAL_INVALID_EMAIL_ADDRESSES, /* "Invalid Email addresses", "Global String- Invalid Email addresses" */
    STR_GLOBAL_INVALID_FILENAME,    /* "Invalid filename", "Global String- Invalid filename" */
    STR_GLOBAL_INVALID_FORMAT,      /* "Invalid format", "Global String- Invalid format" */
    STR_GLOBAL_INVALID_INPUT,       /* "Invalid input", "Global String- Invalid input" */
    STR_GLOBAL_INVALID_NUMBER,      /* "Invalid number", "Global String- Invalid number" */
    STR_GLOBAL_INVALID_NUMBERS,     /* "Invalid numbers", "Global String- Invalid numbers" */
    STR_GLOBAL_INVALID_RECIPIENTS,  /* "Invalid recipients", "Global String- Invalid recipients" */
    STR_GLOBAL_INVALID_URL,         /* "Invalid URL", "Global String- Invalid URL" */
    STR_GLOBAL_LIST,                /* "List", "Global String- List" */
    STR_GLOBAL_LOADING,             /* "Loading", "Global String- Loading" */
    STR_GLOBAL_LOGIN,               /* "Login", "Global String- Login" */
    STR_GLOBAL_LOGO,                /* "Logo", "Global String- Logo" */
    STR_GLOBAL_LOGOUT,              /* "Logout", "Global String- Logout" */
    STR_GLOBAL_LOW,                 /* "Low", "Global String- Low" */
    STR_GLOBAL_MANUAL,              /* "Manual", "Global String- Manual" */
    STR_GLOBAL_MARK,                /* "Mark", "Global String- Mark" */
    STR_GLOBAL_MARK_ALL,            /* "Mark all", "Global String- Mark all" */
    STR_GLOBAL_MAXIMUM,             /* "Maximum", "Global String- Maximum" */
    STR_GLOBAL_MEDIUM,              /* "Medium", "Global String- Medium" */
    STR_GLOBAL_MEMORY_CARD,         /* "Memory card", "Global String- Memory card" */
    STR_GLOBAL_MEMORY_FULL,         /* "Memory full", "Global String- Memory full- indicate user not save again" */
    STR_GLOBAL_MEMORY_STATUS,       /* "Memory status", "Global String- Memory status" */
    STR_GLOBAL_MESSAGE,             /* "Message", "Global String- Message" */
    STR_GLOBAL_MISSED_CALLS,        /* "Missed calls", "Global String- Missed calls" */
    STR_GLOBAL_MMS,                 /* "MMS", "Global String- MMS" */
    STR_GLOBAL_MODE,                /* "Mode", "Global String- Mode" */
    STR_GLOBAL_MOVE,                /* "Move", "Global String- Move" */
    STR_GLOBAL_MOVING,              /* "Moving", "Global String- Moving" */
    STR_GLOBAL_MULTIMEDIA_MESSAGE,  /* "Multimedia message ", "Global String- Multimedia message " */
    STR_GLOBAL_MUTE,                /* "Mute", "Global String- Mute" */
    STR_GLOBAL_NETWORK_SETTINGS,    /* "Network settings", "Global String- Network settings" */
    STR_GLOBAL_NO,                  /* "No", "Global String- No" */
    STR_GLOBAL_NO_MEMORY_CARD,      /* "No Memory Card", "[Notify-No Memory Card]" */
    STR_GLOBAL_NONE,                /* "None", "Global String- None" */
    STR_GLOBAL_NORMAL,              /* "Normal", "Global String- Normal" */
    STR_GLOBAL_NOT_AVAILABLE,       /* "Not Available", "Global String- Not Available" */
    STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL,
                                    /* "Not available during video call", "Global String- Not available during video call" */
    STR_GLOBAL_NOT_ENOUGH_MEMORY,   /* "Not enough memory", "Global String- Not enough memory- memory is too small to save" */
    STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR, 
                                    /* "Not Support at PC Simulator", "Global String- Not Support at PC Simulator" */
    STR_GLOBAL_NOT_SUPPORTED,       /* "Not supported", "Global String- Not supported" */
    STR_GLOBAL_OFF,                 /* "Off", "Global String- Off" */
    STR_GLOBAL_OK,                  /* "Ok", "Global String- OK" */
    STR_GLOBAL_ON,                  /* "On", "Global String- On"*/
    STR_GLOBAL_OPEN,                /* "Open", "Global String- Open" */
    STR_GLOBAL_OPTIONS,             /* "Option", "Global String- Options" */
    STR_GLOBAL_OUTBOX,              /* "Outbox", "Global String- Outbox" */
    STR_GLOBAL_OVERWRITE_EXISTING_FILE, 
                                    /* "Overwrite existing file?", "Global String- Overwrite existing file?" */
    STR_GLOBAL_PASSWORD,            /* "Password","Global String- Password menu" */
    STR_GLOBAL_PAUSE,               /* "Pause","Global String- Pause" */
    STR_GLOBAL_PHONE,               /* "Phone", "Global String- Phone" */
    STR_GLOBAL_PICTURE,             /* "Picture","Global String- Picture" */
    STR_GLOBAL_PLAY,                /* "Play","Global String- Play" */
    STR_GLOBAL_PLEASE_INPUT_THE_FILENAME,
                                    /* "Please input the filename", "Global String- Prompt user the filename is empty" */
    STR_GLOBAL_PLEASE_WAIT,         /* "Please Wait", "Global String- Please Wait" */
    STR_GLOBAL_PREFERRED_STORAGE,   /* "Preferred storage", "Global String- Preferred storage" */
    STR_GLOBAL_PREV,                /* "Prev.", "Global String- Prev." */
    STR_GLOBAL_PREVIEW,             /* "Preview", "Global String- Preview" */
    STR_GLOBAL_PRINT,               /* "Print", "Global String- Print" */
    STR_GLOBAL_PRIORITY,            /* "Priority", "Global String- Priority" */
    STR_GLOBAL_PROXY,               /* "Proxy", "Global String- Proxy" */
    STR_GLOBAL_QUIT,                /* "Quit", "Global String- Quit" */
    STR_GLOBAL_READ,                /* "Read", "Global String- Read" */
    STR_GLOBAL_RECEIVED,            /* "Received", "Global String- Received" */
    STR_GLOBAL_RECEIVED_CALLS,      /* "Received calls", "Global string- Received calls" */
    STR_GLOBAL_RECEIVING,           /* "Receiving", "Global String- Receiving" */
    STR_GLOBAL_RECIPIENTS,          /* "Recipients", "Global String- Recipients- recipient list name" */
    STR_GLOBAL_REFRESH,             /* "Refresh", "Global String- Refresh" */
    STR_GLOBAL_REMOVE,              /* "Remove", "Global String- Remove- delete the reference link or remove accessory from phone" */
    STR_GLOBAL_REMOVED,             /* "Removed", "Global String- Removed- remove successfully" */
    STR_GLOBAL_RENAME,              /* "Rename", "Global String- Rename" */
    STR_GLOBAL_REPLACE,             /* "Replace", "Global String- Replace" */
    STR_GLOBAL_REPLY,               /* "Reply", "Global String- Reply" */
    STR_GLOBAL_RESEND,              /* "Resend", "Global String- Resend" */
    STR_GLOBAL_RESET,               /* "Reset", "Global String- Reset" */
    STR_GLOBAL_RESUME,              /* "Resume", "Global String- Resume" */
    STR_GLOBAL_RINGTONE,            /* "Ringtone", "Global String- Ringtone" */
    STR_GLOBAL_SAVE,                /* "Save", "Global String- Save" */
    STR_GLOBAL_SAVE_ASK,            /* "Save?", "Global String- Save?" */
    STR_GLOBAL_SAVE_TO_PHONEBOOK,   /* "Save to Phonebook", "Global String- Save to Phonebook" */
    STR_GLOBAL_SAVED,               /* "Saved", "Global String- Saved"); */
    STR_GLOBAL_SAVING,              /* "Saving", "Global String- Saving" */
    STR_GLOBAL_SEARCH,              /* "Search", "Global String- Search" */
    STR_GLOBAL_SEARCHING,           /* "Searching", "Global String- Searching" */
    STR_GLOBAL_SELECT,              /* "Select", "Global String- Select" */
    STR_GLOBAL_SEND,                /* "Send", "Global String- Send" */
    STR_GLOBAL_SEND_MESSAGE,        /* "Send message", "Global String- Send message" */
    STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE,
                                    /* "Send multimedia message", "The option of send multimedia message" */
    STR_GLOBAL_SEND_TEXT_MESSAGE,   /* "Send text message", "The option of send text message" */
    STR_GLOBAL_SENDING,             /* "Sending", "Global String- Sending"*/
    STR_GLOBAL_SENT,                /* "Sent", "Global String- Sent- send successfully" */
    STR_GLOBAL_SETTINGS,            /* "Settings", "Global String- Settings" */
    STR_GLOBAL_SILENT,              /* "Silent", "Global String- Silent" */
    STR_GLOBAL_SIM,                 /* "SIM", "Global String- SIM" */
    STR_GLOBAL_SIM_1,               /* "SIM 1", "Global String- SIM 1" */
    STR_GLOBAL_SIM_2,               /* "SIM 2", "Global String- SIM 2" */
    STR_GLOBAL_SLOW,                /* "Slow", "Global String- Slow" */
    STR_GLOBAL_SORT_BY,             /* "Sort by", "Global String- Sort by- include sub options" */
    STR_GLOBAL_START,               /* "Start", "Global String- Start" */
    STR_GLOBAL_STOP,                /* "Stop", "Global String- Stop" */
    STR_GLOBAL_STORAGE,             /* "Storage", "Global String- Storage" */
    STR_GLOBAL_SUBJECT,             /* "Subject", "Global String- Subject" */
    STR_GLOBAL_TEXT,                /* "Text", "Global String- Text" */
    STR_GLOBAL_TEXT_MESSAGE,        /* "Text message", "Global String- Text message- SMS" */
    STR_GLOBAL_TIME,                /* Time", "Global String- Time" */
    STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE,
                                    /* "Unavailable in flight mode", "Global String- Unavailable in flight mode" */
    STR_GLOBAL_UNAVAILABLE_SIM,     /* "Unavailable SIM", "Global String- Unavailable SIM" */
    STR_GLOBAL_UNFINISHED,          /* "Unfinished", "Global String- Unfinished" */
    STR_GLOBAL_UNMARK,              /* "Unmark", "Global String- Unmark" */
    STR_GLOBAL_UNMARK_ALL,          /* "Unmark all", "Global String- Unmark all" */
    STR_GLOBAL_UNSUPPORTED_FORMAT,  /* "Unsupported Format", "Global String- Unsupported Format" */
    STR_GLOBAL_URL,                 /* "URL", "Global String- URL" */
    STR_GLOBAL_UPDATE,              /* "Update", "Global String- Update" */
    STR_GLOBAL_USE,                 /* "Use", "Global String- Use" */
    STR_GLOBAL_USE_TEMPLATE,        /* "Use Template", "Global String- Use Template" */
    STR_GLOBAL_USERNAME,            /* "User Name", "Global String- User name menu" */
    STR_GLOBAL_VIA_BLUETOOTH,       /* "Via Bluetooth", "Global String- Via Bluetooth- sub option of sending command" */
    STR_GLOBAL_VIA_INFRARED,        /* "Via infrared", "Global String- Via infrared- sub option of sending command" */
    STR_GLOBAL_VIDEO,               /* "Video", "Global String- Video" */
    STR_GLOBAL_VIEW,                /* "View", "Global String- View" */
    STR_GLOBAL_VOLUME,              /* "Volume", "Global String- Volume" */
    STR_GLOBAL_WALLPAPER,           /* "Wallpaper", "Global String- Wallpaper" */
    STR_GLOBAL_WAP,                 /* "WAP", "Global String- WAP" */
    STR_GLOBAL_WIFI,                /* "Wi-Fi", "Global String- Wi-Fi" */
    STR_GLOBAL_YEAR,                /* "Year", "Global String- Year" */
    STR_GLOBAL_YES,	                /* "Yes", "Global String- Yes" */

    STR_GLOBAL_INSERT_MEMORY_CARD,  /* "Please insert memory card", "Global String- Please insert memory card" */
    STR_GLOBAL_MC_REMOVED_USE_PHONE,    /* "Memory card removed. Use phone?", "Global String- Memory card removed. Use phone?" */
    STR_GLOBAL_MC_REMOVED,              /* "Memory card removed", "Global String- Memory card removed" */
    STR_GLOBAL_MC_INSERTED,             /* "Memory card inserted", "Global String- Memory card inserted" */
    STR_GLOBAL_OTG_REMOVED_USE_PHONE,   /* "OTG device removed. Phone will be used.", "Global String- OTG device removed. Phone will be used." */
    STR_GLOBAL_OTG_REMOVED_USE_PHONE_QUERY,   /* "OTG device removed. Use phone?", "Global String- OTG device removed. Use phone?" */    
    STR_GLOBAL_OTG_REMOVED,             /* "OTG device removed", "Global String- OTG device removed" */
    STR_GLOBAL_OTG_CONNECTED,           /* "OTG device connected", "Global String- OTG device connected" */
    STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE,  /* "Not available in mass storage mode", "Global String- Not available in mass storage mode" */
    STR_GLOBAL_NO_NUMBER,           /* "No number", "Global String- No number" */

    STR_GLOBAL_SUNDAY,              /* "Sunday", "Global String- Sunday" */
    STR_GLOBAL_MONDAY,              /* "Monday", "Global String- Monday" */
    STR_GLOBAL_TUESDAY,             /* "Tuesday", "Global String- Tuesday" */
    STR_GLOBAL_WEDNESDAY,           /* "Wednesday", "Global String- Wednesday" */
    STR_GLOBAL_THURSDAY,            /* "Thursday", "Global String- Thursday" */
    STR_GLOBAL_FRIDAY,              /* "Friday", "Global String- Friday" */
    STR_GLOBAL_SATURDAY,            /* "Saturday", "Global String- Saturday" */

    STR_GLOBAL_SUNDAY_SHORT,        /* "Sun", "Global String- Sun" */
    STR_GLOBAL_MONDAY_SHORT,        /* "Mon", "Global String- Mon" */
    STR_GLOBAL_TUESDAY_SHORT,       /* "Tue", "Global String- Tue" */
    STR_GLOBAL_WEDNESDAY_SHORT,     /* "Wed", "Global String- Wed" */
    STR_GLOBAL_THURSDAY_SHORT,      /* "Thu", "Global String- Thu" */
    STR_GLOBAL_FRIDAY_SHORT,        /* "Fri", "Global String- Fri" */
    STR_GLOBAL_SATURDAY_SHORT,      /* "Sat", "Global String- Sat" */

    STR_GLOBAL_JANUARY_SHORT,		    /* "Jan", "Global String- Jan" */
    STR_GLOBAL_FEBRUARY_SHORT,      /* "Feb", "Global String- Feb" */
    STR_GLOBAL_MARCH_SHORT,         /* "Mar", "Global String- Mar" */
    STR_GLOBAL_APRIL_SHORT,         /* "Apr", "Global String- Apr" */
    STR_GLOBAL_MAY_SHORT,           /* "May", "Global String- May" */
    STR_GLOBAL_JUNE_SHORT,          /* "Jun", "Global String- Jun" */
    STR_GLOBAL_JULY_SHORT,          /* "Jul", "Global String- Jul" */
    STR_GLOBAL_AUGEST_SHORT,        /* "Aug", "Global String- Aug" */
    STR_GLOBAL_SEPTEMBER_SHORT,     /* "Sep", "Global String- Sep" */
    STR_GLOBAL_OCTOBER_SHORT,       /* "Oct", "Global String- Oct" */
    STR_GLOBAL_NOVEMBER_SHORT,      /* "Nov", "Global String- Nov" */
    STR_GLOBAL_DECEMBER_SHORT,      /* "Dec", "Global String- Dec" */		

    STR_GLOBAL_DIAL_VIDEO_CALL,

    STR_GLOBAL_SIM_3,
    STR_GLOBAL_SIM_4,
    
    STR_GLOBAL_DELETE_ASK,           /* "Delete?", "Global String- Delete?" */
    STR_GLOBAL_DELETE_ALL_ASK,       /* "Delete all?", "Global String- Delete all?" */
    STR_GLOBAL_USE_AS,               /* "Use as", "Global String- Use as" */
    STR_GLOBAL_STATUS,               /* "Status", "Global String- Status" */
    /* ----------------------- Common (end) ------------------------------- */

#if defined(__COSMOS_MMI__) || defined(__VENUS_UI_ENGINE__)

    /* ----------------------- Cosmos and FTE only (Start)----------------- */
    /* Global string listed here are used by Cosmos and FTE only */
    STR_GLOBAL_SUBMIT,              /* "Submit","Accept" */
    STR_GLOBAL_UDP_PORT,            /* "UDP port", "Global String- UDP port" */
    STR_GLOBAL_CLIPBOARD,           /* "Clipboard", "Global String- Clipboard" */

    STR_GLOBAL_ADD_TO_EXISTING_CONTACT,
                                    /* "Add to existing contact", "Global String- Add to existing contact" */
    STR_GLOBAL_AM,                  /* "AM", "Global String- AM" */
    STR_GLOBAL_AUDIO,               /* "Audio", "Global String- Audio" */
    STR_GLOBAL_BOOKMARKS,           /* "Bookmarks", "Global String- Bookmarks" */
    STR_GLOBAL_CHOOSE_STORAGE,      /* "Choose storage", "Global String- Choose storage" */
    STR_GLOBAL_CREATE_NEW_CONTACT,  /* "Create new contact", "Global String- Create new contact" */
    STR_GLOBAL_DAY,                 /* "Day", "Global String- Day" */
    STR_GLOBAL_EARPHONE,            /* "Earphone", "Global String- Earphone" */
    STR_GLOBAL_EXPORT,              /* "Export", "Global String- Export" */
    STR_GLOBAL_FILENAME_ALREADY_EXISTS,
                                    /* "Filename already exists", "Global String- Filename already exists" */
    STR_GLOBAL_FOLD,                /* "Fold", "Global String- Fold" */
    STR_GLOBAL_GO_TO_URL,           /* "Go to URL", "Global String- Go to URL" */
    STR_GLOBAL_HOME,                /* "Home", "Global String- Home" */
    STR_GLOBAL_HOUR,                /* "Hour", "Global String- Hour" */
    STR_GLOBAL_IMPORT,              /* "Import", "Global String- Import" */
    STR_GLOBAL_INSTALLING,          /* "Installing", "Global String- Installing" */
    STR_GLOBAL_LANDSCAPE,           /* "Landscape", "Global String- Landscape" */
    STR_GLOBAL_MIN,                 /* "Min", "Global String- Min" */
    STR_GLOBAL_MORE,                /* "More", "Global String- More" */
    STR_GLOBAL_MULTIMEDIA,          /* "Multimedia", "Global String- Multimedia" */    
    STR_GLOBAL_NEXT,                /* "Next", "Global String- Next" */
    STR_GLOBAL_PM,                  /* "PM", "Global String- PM" */
    STR_GLOBAL_PORTRAIT,            /* "Portrait", "Global String- Portrait" */
    STR_GLOBAL_PRIMARY_SIM,         /* "Primary SIM", "Global String- Primary SIM" */
    STR_GLOBAL_REFRESHING,          /* "Refreshing", "Global String- Refreshing" */
    STR_GLOBAL_REMINDER,            /* "Reminder", "Global String- Reminder" */
    STR_GLOBAL_RESTORE,             /* "Restore", "Global String- Restore" */
    STR_GLOBAL_SEC,                 /* "Sec", "Global String- Sec" */
    STR_GLOBAL_SECONDARY_SIM,       /* "Secondary SIM", "Global String- Secondary SIM" */
    STR_GLOBAL_SECURITY,            /* "Security", "Global String- Security" */
    STR_GLOBAL_SELECT_ALL,          /* "Select all", "Global String- Select all" */
    STR_GLOBAL_SET_AS,              /* "Set as", "Global String- Set as" */
    STR_GLOBAL_SHARE,               /* "Share", "Global String- Share" */
    STR_GLOBAL_SMS,                 /* "SMS", "Global String- SMS" */
    STR_GLOBAL_SORT,                /* "Sort", "Global String- Sort" */
    STR_GLOBAL_TEMPLATE,            /* "Template", "Global String- Template" */
    STR_GLOBAL_UNNAMED,             /* "Unnamed", "Global String- Unnamed" */    
    STR_GLOBAL_UNSELECT_ALL,        /* "Unselect all", "Global String- Unselect all" */
    STR_GLOBAL_UPLOAD,              /* "Upload", "Global String- Upload" */
    STR_GLOBAL_VIBRATION,           /* "Vibration", "Global String- Vibration" */
    STR_GLOBAL_WEEK,                /* "WEEK", "Global String- Week" */
    STR_GLOBAL_WIFI_ONLY,		        /* "Wi-Fi only", "Global String- Wi-Fi only" */
    /* -------------------------- Cosmos and FTE only (end) ------------------ */
#endif /* __COSMOS_MMI__) || __VENUS_UI_ENGINE__ */
									
    /* add new resource before here */
	STR_GLOBAL_END

}STR_GLOBAL_LIST_ENUM;

#define SRV_GPIO_BASE 200

/* GPIO Event Type */
typedef enum
{

    EVT_ID_MMI_GPIO_BEGIN = SRV_GPIO_BASE,   
    EVT_ID_GPIO_EARPHONE_PLUG_IN,           /* event for earphone plug in */
    EVT_ID_GPIO_EARPHONE_PLUG_OUT,          /* event for earphone plug out */
    EVT_ID_GPIO_EARPHONE_QUERY_CTRL,        /* event for query whether earphone controlled by other app, such as CTM */
    EVT_ID_GPIO_EXT_DEV_KEY_1,              /* event for send key of earphone */
    EVT_ID_GPIO_CLAM_OPEN,                  /* event for clam open */
    EVT_ID_GPIO_CLAM_CLOSE,                 /* event for clam close */
    EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE, /* event for query whether tone can be play when clam open or close */     
    
    EVT_ID_GPIO_LCD_SLEEP_OUT,              /* event for LCD will leave sleep in mode */
    EVT_ID_GPIO_BACKLIGHT_ON,               /* notify special app (screenlock) to do thing */
    EVT_ID_GPIO_BACKLIGHT_DIMMING,          /* event for LCD backlight come to dimming status */
    EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN,        /* event for query all APP whether GPIO can turn off backlight */
    EVT_ID_GPIO_BACKLIGHT_OFF,              /* all APP agree to turn off backlight, then notify special app to do thing */
    EVT_ID_GPIO_LCD_SLEEP_IN,               /* event for LCD will come into sleep in mode, */
    EVT_ID_GPIO_AFTER_LCD_SLEEP_IN,         /* event for LCD already come into sleep in mode, whether can suspend system align timer */
    
    EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE,     /* event for backlight level have been set or changed */
    
    EVT_ID_GPIO_ENABLE_HAND_FREE,           /* event for enable hand free */
    EVT_ID_GPIO_DISABLE_HAND_FREE,          /* event for disable hand free */

    EVT_ID_GPIO_MUTE_PHONE,                 /* event for mute phone */
    EVT_ID_GPIO_UNMUTE_PHONE,               /* event for unmute phone */

    EVT_ID_GPIO_PENDING_TRUN_ON_BLT,        /* only use by myself, post to turn on backlihgt if some AP turn on in sleeping */

#ifdef __LINE_IN_SUPPORT__
    EVT_ID_GPIO_LINEIN_PLUG_IN,           /* event for linein plug in */
    EVT_ID_GPIO_LINEIN_PLUG_OUT,          /* event for line plug out */
#endif  //__LINE_IN_SUPPORT__
#ifdef __OP01_FWPBW__
    EVT_ID_GPIO_TRANSMITTER_HOLD_ON,        /* hold on transmitter of fixed phone in hand */
    EVT_ID_GPIO_TRANSMITTER_PUT_DOWN,       /* put down transmitter of fixed phone in phone */
#endif
    
    EVT_ID_SRV_GPIO_END_OF_ENUM
} srv_gpio_event_enum;

typedef enum
{
   MMI_EVENT_DEFAULT,
#ifdef MMI_NOTI_MGR_UT
   MMI_EVENT_UT_INFO,
   MMI_EVENT_UT_QUERY,
   MMI_EVENT_UT_WARNING,
   MMI_EVENT_UT_ALARM,
#endif /* MMI_NOTI_MGR_UT */
   MMI_EVENT_FAILURE,   /* Basic popup failure type */
   MMI_EVENT_INFO,      /* Basic popup infomation type */
   MMI_EVENT_WARNING,   /* Basic popup warning type */
   MMI_EVENT_SUCCESS,   /* Basic popup success type */
   MMI_EVENT_PROGRESS,  /* Basic popup progress type */
   MMI_EVENT_QUERY,     /* Basic popup query type */
   MMI_EVENT_MESSAGE_SENT,          /* __OP11__ */
   MMI_EVENT_PROPLEM,               /* __OP11__ */
   MMI_EVENT_EXPLICITLY_SAVED,      /* __OP11__ */
   MMI_EVENT_EXPLICITLY_DELETED,    /* __OP11__ */
   MMI_EVENT_CONFIRM,               /* __OP11__ */
   MMI_EVENT_BATTERY_WARNING,       /* __OP11__ */
   MMI_EVENT_NOT_AVAILABLE,         /* __OP11__ */
   MMI_EVENT_ANSPHONE,              /* __OP11__ */
   MMI_EVENT_REMIND,                /* __OP11__ */
   MMI_EVENT_BATTERY_NOTIFY,        /* __OP11__ */
   MMI_EVENT_TOTAL_NUM,		/* used for original popup event */
   /* App should define event id for scenario to configure notification information in mmi_events_notify_tbl */
   MMI_EVENT_NON_TONE,
   MMI_EVENT_INCOMING_CALL,
   MMI_EVENT_ALARM_EXPIRES,
   MMI_EVENT_VOBJECT,
   MMI_EVENT_MESSAGE_WAITING_OTHERS,
   MMI_EVENT_MESSAGE_WAITING_SLAVE,
   MMI_EVENT_MESSAGE_SIM1_WAITING = MMI_EVENT_MESSAGE_WAITING_OTHERS,
   MMI_EVENT_MESSAGE_SIM2_WAITING = MMI_EVENT_MESSAGE_WAITING_SLAVE,
   MMI_EVENT_MESSAGE_SIM3_WAITING,
   MMI_EVENT_MESSAGE_SIM4_WAITING,
   MMI_EVENT_MESSAGE_WAITING_VOICE_MAIL,
   MMI_EVENT_SMS,
   MMI_EVENT_SLAVE_SMS,
   MMI_EVENT_SIM1_SMS = MMI_EVENT_SMS,
   MMI_EVENT_SIM2_SMS = MMI_EVENT_SLAVE_SMS,
   MMI_EVENT_SIM3_SMS,
   MMI_EVENT_SIM4_SMS,
   MMI_EVENT_MMS,
   MMI_EVENT_SLAVE_MMS,
   MMI_EVENT_SIM1_MMS = MMI_EVENT_MMS,
   MMI_EVENT_SIM2_MMS = MMI_EVENT_SLAVE_MMS,
   MMI_EVENT_SIM3_MMS,
   MMI_EVENT_SIM4_MMS,
   MMI_EVENT_EMAIL,
   MMI_EVENT_EMAIL_NEW_EMAIL = MMI_EVENT_EMAIL,
   MMI_EVENT_EMAIL_SEND_FAIL,
   MMI_EVENT_EMAIL_REFRESH_FAIL,
   MMI_EVENT_REMINDER_ALARM,
   MMI_EVENT_REMINDER_OTHER,
   MMI_EVENT_REMINDER_CAL,
   MMI_EVENT_SCHEDULE_POWER_OFF,
   MMI_EVENT_INFO_BALLOON,


   MMI_EVENT_SEND_FAIL_MSG,
   MMI_EVENT_SENDING_MSG,
   MMI_EVENT_UNREAD_MSG,
   MMI_EVENT_JAVA_PUSH,
   MMI_EVENT_INVALID_CERT,
   MMI_EVENT_SELECT_CERT,

   MMI_EVENT_SIM1_NEW_CLASS0_SMS,
   MMI_EVENT_SIM2_NEW_CLASS0_SMS,
   MMI_EVENT_SIM3_NEW_CLASS0_SMS,
   MMI_EVENT_SIM4_NEW_CLASS0_SMS,
   MMI_EVENT_SIM1_NEW_SMS_REPORT,
   MMI_EVENT_SIM2_NEW_SMS_REPORT,
   MMI_EVENT_SIM3_NEW_SMS_REPORT,
   MMI_EVENT_SIM4_NEW_SMS_REPORT,
   MMI_EVENT_SIM1_NEW_MSG_WAITING_VOICEMAIL,
   MMI_EVENT_SIM2_NEW_MSG_WAITING_VOICEMAIL,
   MMI_EVENT_SIM3_NEW_MSG_WAITING_VOICEMAIL,
   MMI_EVENT_SIM4_NEW_MSG_WAITING_VOICEMAIL,
   MMI_EVENT_SIM1_NEW_MSG_WAITING_FAX,
   MMI_EVENT_SIM2_NEW_MSG_WAITING_FAX,
   MMI_EVENT_SIM3_NEW_MSG_WAITING_FAX,
   MMI_EVENT_SIM4_NEW_MSG_WAITING_FAX,
   MMI_EVENT_SIM1_NEW_MSG_WAITING_EMAIL,
   MMI_EVENT_SIM2_NEW_MSG_WAITING_EMAIL,
   MMI_EVENT_SIM3_NEW_MSG_WAITING_EMAIL,
   MMI_EVENT_SIM4_NEW_MSG_WAITING_EMAIL,
   MMI_EVENT_SIM1_NEW_MSG_WAITING_NET_MSG,
   MMI_EVENT_SIM2_NEW_MSG_WAITING_NET_MSG,
   MMI_EVENT_SIM3_NEW_MSG_WAITING_NET_MSG,
   MMI_EVENT_SIM4_NEW_MSG_WAITING_NET_MSG,
   MMI_EVENT_SIM1_NEW_MSG_WAITING_VEDIO,
   MMI_EVENT_SIM2_NEW_MSG_WAITING_VEDIO,
   MMI_EVENT_SIM3_NEW_MSG_WAITING_VEDIO,
   MMI_EVENT_SIM4_NEW_MSG_WAITING_VEDIO,

   MMI_EVENT_SIM1_NEW_CB_MSG,
   MMI_EVENT_SIM2_NEW_CB_MSG,
   MMI_EVENT_SIM3_NEW_CB_MSG,
   MMI_EVENT_SIM4_NEW_CB_MSG,

   MMI_EVENT_SIM_FAILURE,
   MMI_EVENT_SIM_VERIFICATION,
   MMI_EVENT_NW_REGISTER_FAIL,

   MMI_EVENT_BLUETOOTH,
   
   MMI_EVENT_SYNC_FINISH,

   MMI_EVENT_DA_DOWNLOAD_COMPLETED,
   MMI_EVENT_DA_DOWNLOAD_FAILED,
   MMI_EVENT_DA_MEMORY_FULL,

   MMI_EVENT_CONTACT_BACKUP_ERROR,
   MMI_EVENT_CONTACT_RESTORE_ERROR,
   MMI_EVENT_CONTACT_IMPORT_ERROR,

   MMI_EVENT_MMS_REPORTS,

   MMI_EVENT_SAT_IDLE_TEXT,

   MMI_EVENT_GENERAL_PREVIEW,
   
   MMI_EVENT_FULL_MSG,
   
   MMI_EVENT_EARPHONE_PLUG_INOUT,

   MMI_EVENT_LAUNCH_APP,
   
   MMI_EVENT_SNS_SENT_FAIL,
   
   MMI_EVENT_SNS_NEW_INFO,

   MMI_EVENT_UNKNOWN_WAP_PUSH,

   MMI_EVENT_MRE_PUSH,

   MMI_EVENT_BT_NOTIFY,
   MMI_EVENT_BT_MISSED_CALL,
   
   MMI_EVENT_TOTAL_COUNT		/* total event*/
} mmi_event_notify_enum;

#define  PRT_MSG_ID_MMI_EQ_VOLUME_CHANGE_IND 1700
#define PRT_MMI_EQ_QUERY_SILENT_MODE_REQ_IND        1731
#define PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND   1310
#define PRT_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND      1732
#define PRT_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND 1315


#define EVT_ID_SRV_FMGR_ASYNC_END 2000
/* <GROUP Notification service event>
 * Event of FMGR notification.
 * For static registration, please refer to mmi_cb_mgr_cfg.h.
 * For dynamic registration, please refer to mmi_frm_cb_reg_event / mmi_frm_cb_dereg_event.
 * To broadcast the notification, please use srv_fmgr_fs_copy, srv_fmgr_fs_move, etc... API. */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_NOTIFICATION_BASE = EVT_ID_SRV_FMGR_ASYNC_END,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,     /* When removable devices are plugged in, 
                                                     see also srv_fmgr_notification_dev_plug_event_struct */
    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,    /* When removeable devices are plugged out,
                                                     see also srv_fmgr_notification_dev_plug_event_struct */

    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY,       /* When all devices are ready after bootup,
                                                     see also srv_fmgr_notification_dev_ready_event_struct*/

    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT,  /* When a removable device is removed, 
                                                     see also srv_fmgr_notification_dev_soft_mount_event_struct */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,          /* When a storage is being formatted and after formatted,
                                                     see also srv_fmgr_notification_format_event_struct */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, /* When set default storage,
                                                     see also srv_fmgr_notification_set_def_storage_event_struct */

    EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION,      /* When advanced action happen, including copy, move, rename, delete,
                                                     see also srv_fmgr_notification_adv_action_event_struct */


    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_NOTIFICATION_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_notification_event_enum;

/* <GROUP Notification service macro>
 * State of notification event. Receiver may receive the same notification event 
 * with different state. For example, when user try to format memory card,
 * format notification with "query" state is broadcasted to all receiver to make 
 * sure all receiver accept the formation, if anyone disagree, the formation is fail.
 * If all receiver agree, format with "before" state is broadcasted so that receiver
 * can reset status. Memory card is then formatted. After formation (success or not),
 * format with "after" state is broadcasted. */
typedef enum 
{
    SRV_FMGR_NOTIFICATION_STATE_QUERY,  /* Query state, all receiver have chance to stop 
                                         * what going to happen (format, delete, etc) by 
                                         * returning MMI_RET_ERR */
    SRV_FMGR_NOTIFICATION_STATE_BEFORE, /* Before state, after the query succeed, receiver
                                         * can do some pre-processing */
    SRV_FMGR_NOTIFICATION_STATE_AFTER,  /* After state, after operation is done, receiver
                                         * can do some post-processing */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_NOTIFICATION_STATE_END
    /* DOM-NOT_FOR_SDK-END */    
} srv_fmgr_notification_state_enum;

/* <GROUP Notification service macro>
 * EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION contains Copy, Move, Rename, Delete, Delete all.
 * This enum is used to indicate the real action */
typedef enum 
{
    SRV_FMGR_NOTIFICATION_ACTION_COPY,  /* Copy a single file or folder 
                                         * src:  a file or folder 
                                         * dest: a folder
                                         * Ex. Copy("D:\\A\\C.jpg", "D:\\B\\") = "D:\\B\\C.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_MOVE,  /* Move a single file or folder
                                         * src:  a file or folder 
                                         * dest: a folder
                                         * Ex. Move("D:\\A\\C.jpg", "D:\\B\\") = "D:\\B\\C.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_RENAME,/* Rename a single file or folder 
                                         * src:  a file or folder
                                         * dest: a file or folder
                                         * Ex. Move("D:\\A\\C.jpg", "D:\\A\\D.jpg") = "D:\\A\\D.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_DELETE,/* Delete a single file or folder 
                                         * src:  a file or folder */
    SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL, /* Delete all files in a folder 
                                         * src:  a folder
                                         * filter: only matched files will be deleted */
    SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER, /* A folder is being created 
                                         * src:  a folder */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_NOTIFICATION_ACTION_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_notification_action_enum;

/* <GROUP Fileinfo service>
 * detail infos of file info object, this structure contain type, attribute, size, 
 * datetime, also see srv_fmgr_fileinfo_get_info */
typedef struct
{
    U16     type;       /* type, see filetypes_file_type_enum */
    U16     attribute;  /* attribute, refer to FS_ATTR_XXX */
    U32     size;       /* size */
    MYTIME  datetime;   /* last modified date */
    MYTIME  created_datetime;   /* creation date */
} srv_fmgr_fileinfo_struct;


typedef enum 
{
    FMGR_TYPE_ALL,      /* this type represent all files (included not supported types, like *.doc */
    FMGR_TYPE_UNKNOWN,
    /* ================== App type begin ================== */
    FMGR_TYPE_FOLDER,
    FMGR_TYPE_HYPER_LINK,
    FMGR_TYPE_BMP,
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,
    FMGR_TYPE_GIF,
    FMGR_TYPE_EMS,
    FMGR_TYPE_ANM,
    FMGR_TYPE_IMY,
    FMGR_TYPE_MID,
    FMGR_TYPE_MIDI,
    FMGR_TYPE_WAV,
    FMGR_TYPE_AMR,
    FMGR_TYPE_AAC,
    FMGR_TYPE_DAF,
    FMGR_TYPE_FLAC,
    FMGR_TYPE_MRE_TXT,
    FMGR_TYPE_VCF,
    FMGR_TYPE_LRC,
    FMGR_TYPE_DCF,
    FMGR_TYPE_DM,
    /* ================== App type end ================== */
    FMGR_TYPE_COUNT
} filetypes_file_type_enum;


typedef struct { 
    unsigned int mask[(FMGR_TYPE_COUNT+32)/32];
} FMGR_FILTER;


/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    srv_fmgr_notification_state_enum    state;          /* query, before, after */
    srv_fmgr_notification_action_enum   action;         /* copy, move, rename, delete */

    const WCHAR*                        src_filepath;   /* fullpath of source */
    srv_fmgr_fileinfo_struct            src_fileinfo;
    const WCHAR*                        dest_filepath;  /* fullpath of destination */
    srv_fmgr_fileinfo_struct            dest_fileinfo;
    const FMGR_FILTER*                  filter;
    S32                                 result;         /* action result, valid when state = AFTER */
    
} srv_fmgr_notification_adv_action_event_struct;

/* <GROUP Fileinfo service>
 * handle of file info object, see srv_fmgr_fileinfo_create for more detail */
typedef int SRV_FMGR_FILEINFO_HANDLE;



#ifndef __MMI_BT_AUDIO_SUPPORT__
#define __MMI_BT_AUDIO_SUPPORT__
#endif

#ifndef __MMI_BT_SUPPORT__
#define __MMI_BT_SUPPORT__
#endif

#define __MMI_BT_TEMP_VISIBILITY__
#define __MMI_BT_SIMPLE_PAIR__
#define __MMI_BT_AUTHORIZE__
#define __BT_BOND_CANCEL__
#define __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
#define __SRV_BT_CM_DEBUG_INTENAL__
#define __MMI_BT_SLIM__
#define __MMI_BT_SUPPORT__

#ifdef __BT_SPP_PROFILE__
#define __MMI_SPP_SUPPORT__
#endif

#if defined(__BT_GATTC_PROFILE__) || defined(__BT_GATTS_PROFILE__) 
#ifndef __MMI_BLE_LOW_POWER__
#define __MMI_BLE_LOW_POWER__
#endif
#endif

#if (defined(__BT_GATTS_PROFILE__))
	#ifndef MMI_SRV_BT_FMPT_PROFILE
	#define MMI_SRV_BT_FMPT_PROFILE
	#endif
#endif

#if (defined(__BT_GATTS_PROFILE__))
	#ifndef MMI_SRV_BT_PRXR_PROFILE
	#define MMI_SRV_BT_PRXR_PROFILE
	#endif
#endif

#if (defined(__BT_GATTS_PROFILE__))
	#ifndef MMI_SRV_CHECK_SERVICE_UUID
	#define MMI_SRV_CHECK_SERVICE_UUID
	#endif
#endif

#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_HFG_PROFILE__))
	#ifndef __MMI_HFP_SUPPORT__
	#define __MMI_HFP_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__) && defined(__BT_HF_PROFILE__))
    #ifndef __MMI_HF_SUPPORT__
    #define __MMI_HF_SUPPORT__
    #endif
#endif

// BCM didn't support dual SIM
#if (defined(__GEMINI__) && !defined(__EMPTY_MMI__))
	#ifndef MMI_MAX_SIM_NUM
	#define MMI_MAX_SIM_NUM	GEMINI_PLUS
	#endif
#else
	#ifndef MMI_MAX_SIM_NUM
	#define MMI_MAX_SIM_NUM	1
	#endif
#endif
#ifdef __BT_PBAP_PROFILE__
#define __MMI_PBAP_SUPPORT__
#endif

#ifdef __BT_PBAP_CLIENT__
#define __MMI_BT_PBAP_CLIENT__
#endif

#ifdef __BT_OPP_PROFILE__
#define __MMI_OPP_SUPPORT__
#endif

#ifdef __BT_A2DP_PROFILE__
#define __MMI_A2DP_SUPPORT__
#endif

#ifdef __BT_AVRCP_PROFILE__
#define __MMI_AVRCP_SUPPORT__
#endif

typedef enum
{
    BT_TEMP_VISIBLE_TIMER,
    BT_RELEASE_ALL_CON_GUARD_TIMER,
    BT_POWER_OFF_GUARD_TIMER,
    BT_CMD_GUARD_TIMER,
    BT_INQ_TIMER,
    BT_BOND_TIMER,
#ifdef __BT_OPP_PROFILE__
    BT_OPP_PUSH_IND_TIMER,
#endif

#if defined(__BT_HF_PROFILE__) || defined(__BT_HFG_PROFILE__)
	SRV_PROF_STORE_CUR_TIMER,
	SRV_PROF_STORE_BUF_TIMER,
#endif/*defined(__BT_HF_PROFILE__) || defined(__BT_HFG_PROFILE__)*/
#ifdef __BT_A2DP_PROFILE__
	AV_BT_START_TIMER,
	AV_BT_DELAY_PAUSE_TIMER,
#endif
#ifdef __BT_AVRCP_PROFILE__
	BT_AVRCP_AUTO_RELEASE_TIMER,
	
#endif
#if defined(__BT_GATTC_PROFILE__) || defined(__BT_GATTS_PROFILE__) 
#ifdef __MMI_BLE_LOW_POWER__
	GATTS_SET_CONN_INTERVAL_TIMER_ID,
	GATTC_SET_CONN_INTERVAL_TIMER_ID,
	GATTC_CONN_UPDATE_TIMER_OUT_ID,
#endif /* __MMI_BLE_LOW_POWER__ */	
#endif /* (__BT_GATTC_PROFILE__) || defined(__BT_GATTS_PROFILE__)  */

    BCM_MAX_TIMER_NUM
}bcm_timer_id;

#define OslConstructDataPtr(size)  construct_local_para((kal_uint16)(size), (TD_CTRL | TD_RESET))
#endif /* BT_CM_SRV_GPROT_H */

