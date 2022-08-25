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
 *  SmsUmBtMapProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT Header File
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
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_BT_MAP_CLIENT__
#ifndef SMS_UM_BT_MAP_PROT_H
#define SMS_UM_BT_MAP_PROT_H
#include "UmSrvDefs.h"
#include "mmi_msg_context.h"
#include "custom_wap_config.h"
#include "customer_ps_inc.h"
#include "AlertScreen.h"

#include "UMGProt.h"
#include "MsgViewerCuiGProt.h" /* for cui_msg_viewer_launch_ptr */
#include "MMI_features.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "UMDefs.h"
#include "gui_typedef.h"
#include "wgui_touch_screen.h"
#include "gui_data_types.h"
#include "UmSrvGprot.h"
#include "Custom_ProvBox.h"
#include "UmSrvDefs.h"
#include "smssrvgprot.h"
#include "smsappgprot.h"
#include "Wgui_categories_list.h"
#include "SmsUmBtMapGProt.h"
#include "SmsBtMapCSrvGprot.h"
/* UI define value */
#define SRV_UM_BT_MAX_MSG_NUM SRV_SMS_BTMAPC_MAX_SMS_ENTRY
#define MMI_SMS_UM_BT_UI_MAX_SCRN_CNTX_NUM (6)
#define MMI_SMS_UM_BT_UI_MAX_GRP_CNTX_NUM (1)
#define MMI_SMS_UM_BT_UI_MAX_MSG_INFO_NUM (10)
#define MMI_SMS_UM_BT_UI_BIT_MARK_STATUS_SIZE (sizeof(U32)*8)
#define MMI_SMS_UM_BT_UI_MAX_BIT_MARK_STATUS_NUM (SRV_UM_BT_MAX_MSG_NUM/MMI_SMS_UM_BT_UI_BIT_MARK_STATUS_SIZE + 1)
#define MMI_SMS_UM_BT_UI_MAX_LEN_TIME_STR  (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/
#define MMI_SMS_UM_BT_UI_MAX_GET_STRING_LEN (16)
#define MMI_SMS_UM_BT_UI_MAX_MSG_NUM_DIGIT    (6)          /* Display the maximum length of message number string*/
#define MMI_SMS_UM_BT_UI_MAX_CONFIRM_STR_LEN (256)         /* Display the maximum confirm string */
#define MMI_SMS_UM_BT_UI_MAX_IDLE_UNREAD_STRING_LEN (48)   /* the maximum length of unread message string */
#define MMI_SMS_UM_BT_UI_FSM_MAX_NUM_OF_INVALID_PID (8)    /* refer to UMS_MAX_PROCESS */
#define MMI_SMS_UM_BT_UI_MAX_TB_ICON (3)
#define MMI_SMS_UM_BT_UI_PROGRESS_INTERVAL (100)
//#define MMI_SMS_UM_BT_PROGRESS_TIME_OUT (20 * 1000)

#if (SRV_UM_BT_MAX_MSG_NUM < 50)
    #define MMI_SMS_UM_BT_PROGRESS_TIME_OUT (20 * 1000)
#elif (SRV_UM_BT_MAX_MSG_NUM >= 50 && SRV_UM_BT_MAX_MSG_NUM <= 100)
    #define MMI_SMS_UM_BT_PROGRESS_TIME_OUT ((10 + SRV_SMS_BTMAPC_MAX_SMS_ENTRY * 0.2) * 1000)
#else
    #define MMI_SMS_UM_BT_PROGRESS_TIME_OUT (35 * 1000)
#endif



/* UI enum */
typedef enum
{
    MMI_SMS_UM_BT_UI_APRC_263,
    MMI_SMS_UM_BT_UI_APRC_267,
    MMI_SMS_UM_BT_UI_APRC_268,
    MMI_SMS_UM_BT_UI_APRC_53,
    MMI_SMS_UM_BT_UI_APRC_52,
    MMI_SMS_UM_BT_UI_APRC_8,
    MMI_SMS_UM_BT_UI_APRC_165,
    MMI_SMS_UM_BT_UI_APRC_1002,
    MMI_SMS_UM_BT_UI_APRC_36, 
    MMI_SMS_UM_BT_UI_APRC_6003, 
    MMI_SMS_UM_BT_UI_APRC_THREAD_ENHANCE,    
    MMI_SMS_UM_BT_UI_APRC_THREAD_ENHANCE_MS,
    MMI_SMS_UM_BT_UI_APRC_TOTAL
} mmi_sms_um_bt_ui_aprc_type_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_SCRN_TYPE_MAIN_MENU, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_FOLDER, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_MS, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_LIST, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING_PGRS, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_CONVERSATION_BOX, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_THRD_MSG, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_MS_CONVERSATION_BOX, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_MS_THRD_MSG, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_CONVERSATION_SETTING, 
    MMI_SMS_UM_BT_UI_SCRN_TYPE_PREFER_SIM_SETTING,
    MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER,
    MMI_SMS_UM_BT_UI_SCRN_TYPE_TOTAL
} mmi_sms_um_bt_ui_aprc_st_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_APRC_REDRAW_TITLE     = 0x01,
    MMI_SMS_UM_BT_UI_APRC_REDRAW_BODY      = 0x02,
    MMI_SMS_UM_BT_UI_APRC_REDRAW_KEY       = 0x04, 
    MMI_SMS_UM_BT_UI_APRC_REDRAW_TB_ICON   = 0x08, 
    MMI_SMS_UM_BT_UI_APRC_REDRAW_TB_STATUS = 0x10, 
    MMI_SMS_UM_BT_UI_APRC_REDRAW_TOTAL
} mmi_sms_um_bt_ui_aprc_redraw_type_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_NONE,
    MMI_SMS_UM_BT_UI_FSM_ENTRY_LIST,
    MMI_SMS_UM_BT_UI_FSM_ENTRY_FOLDER,
    MMI_SMS_UM_BT_UI_FSM_OPERATION,
    MMI_SMS_UM_BT_UI_FSM_TOTAL
} mmi_sms_um_bt_ui_fsm_type_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_EVENT_INIT,                   /* 0, Initial event for finite state machine */
    MMI_SMS_UM_BT_UI_EVENT_REFRESH,                /* 1, refresh the data in the finite state machine */
    MMI_SMS_UM_BT_UI_EVENT_ABORT,                  /* 2, abort the finite state machine action */
    MMI_SMS_UM_BT_UI_EVENT_DELETE,                 /* 3, delete the related screen */
    MMI_SMS_UM_BT_UI_EVENT_DELETED,                /* 4, inform the parent screen that child is deleted */
    MMI_SMS_UM_BT_UI_EVENT_CHECK,                  /* 5, check the data in the finite state machine */
    MMI_SMS_UM_BT_UI_EVENT_READY,                  /* 6, the service is ready */
    MMI_SMS_UM_BT_UI_EVENT_UNREADY,                /* 7, the service is un-ready */
    MMI_SMS_UM_BT_UI_EVENT_REL_DATA_LIST,          /* 8, release the data list from finite state machine */
    MMI_SMS_UM_BT_UI_EVENT_HIGHLIGHT_CHANGE,       /* 9, highlight is modified by other app, msg_id & msg_type */
    MMI_SMS_UM_BT_UI_EVENT_HIGHLIGHT_IDX_CHANGE,   /* 10, highlight index is modified by central controller */
    MMI_SMS_UM_BT_UI_EVENT_SET_MS_LIST,            /* 11, Set the mark information list to child screen */
    MMI_SMS_UM_BT_UI_EVENT_REL_MS_LIST,            /* 12, Release the mark information list */
    MMI_SMS_UM_BT_UI_EVENT_NOTIFY_PARENT_FOLDER,   /* 13, Notify parent folder information to child screen */
    MMI_SMS_UM_BT_UI_EVENT_CLEAN_RSK_HDLR,         /* 14, Clean the rsk handler */
    MMI_SMS_UM_BT_UI_EVENT_SET_SPT_MSG_TYPE,       /* 15, Set the support message type */
    MMI_SMS_UM_BT_UI_EVENT_SET_NUM_MSG_INSIDE,     /* 16, Set number of message inside the folder, used to support "empty folder screen" */
    MMI_SMS_UM_BT_UI_EVENT_SET_FILTER_TYPE,        /* 17, Set the sorting type of beginning, thread id also */
    MMI_SMS_UM_BT_UI_EVENT_SET_OP_TYPE,            /* 18, Set the operation type. Refer to mmi_sms_um_bt_ui_req_srv_action_enum */
    MMI_SMS_UM_BT_UI_EVENT_SET_FOLDER_MODE,        /* 19, Set the folder mode of entry folder. Refer to mmi_sms_um_bt_ui_folder_mode_enum */
    MMI_SMS_UM_BT_UI_EVENT_SET_THREAD_ID,          /* 20, Set the thread id for operation */
    MMI_SMS_UM_BT_UI_EVENT_QUERY_INDEXING,         /* 21, Query the indexing information from external app. */
    MMI_SMS_UM_BT_UI_EVENT_SET_MS_OP_TYPE,         /* 22, Set the ms operation type */
    MMI_SMS_UM_BT_UI_EVENT_TOTAL
} mmi_sms_um_bt_ui_event_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_EVENT_INIT,               /* 0, Initialize */
    MMI_SMS_UM_BT_UI_FSM_EVENT_REFRESH,            /* 1, Refresh indication */
    MMI_SMS_UM_BT_UI_FSM_EVENT_ABORT,              /* 2, Abort the action */
    MMI_SMS_UM_BT_UI_FSM_EVENT_DELETE,             /* 3, Delete the finite state machine */
    MMI_SMS_UM_BT_UI_FSM_EVENT_CHECK,              /* 4, Check the current data */
    MMI_SMS_UM_BT_UI_FSM_EVENT_READY,              /* 5, Ready indication */
    MMI_SMS_UM_BT_UI_FSM_EVENT_UNREADY,            /* 6, Unready indication */
    MMI_SMS_UM_BT_UI_FSM_EVENT_REL_DATA_LIST,      /* 7, Release data list */
    MMI_SMS_UM_BT_UI_FSM_EVENT_UPDATE_DATA_LIST,   /* 8, Turn on the flag of update data list */
    MMI_SMS_UM_BT_UI_FSM_EVENT_KEEP_DATA_LIST,     /* 9, Turn off the flag of update data list */
    MMI_SMS_UM_BT_UI_FSM_EVENT_SET_FSM_DATA,       /* 10, Set the FSM needed data. ex: operation FSM */
    MMI_SMS_UM_BT_UI_FSM_EVENT_TOTAL
} mmi_sms_um_bt_ui_fsm_event_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_REQ_SRV_NONE,                 /* 0, Non request service action */
    MMI_SMS_UM_BT_UI_REQ_SRV_WAIT_READY,           /* 1, Wait service ready */
    MMI_SMS_UM_BT_UI_REQ_SRV_FINISH,               /* 2, Service response finish */
    MMI_SMS_UM_BT_UI_REQ_SRV_PROGRESS,             /* 3, Progress with service */
    MMI_SMS_UM_BT_UI_REQ_SRV_FAIL,                 /* 4, Service response fail */
    MMI_SMS_UM_BT_UI_REQ_SRV_CANCELLING,           /* 5, Service is during cancelling */
    MMI_SMS_UM_BT_UI_REQ_SRV_CANCELLED,            /* 6, Service is cancelled */
    MMI_SMS_UM_BT_UI_REQ_SRV_CANCEL_FAIL,          /* 7, Service cancelled fail */
    MMI_SMS_UM_BT_UI_REQ_SRV_TOTAL
} mmi_sms_um_bt_ui_req_srv_status_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_ACTION_NONE,
    MMI_SMS_UM_BT_UI_ACTION_GET_MSG_NUM,
    MMI_SMS_UM_BT_UI_ACTION_GET_MSG_LIST,
    MMI_SMS_UM_BT_UI_ACTION_GET_MSG_INFO,
    MMI_SMS_UM_BT_UI_ACTION_GET_MSG_CONTENT,
    MMI_SMS_UM_BT_UI_ACTION_GET_THRD_INFO, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_DELETE, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM, 
    MMI_SMS_UM_BT_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE, 
    MMI_SMS_UM_BT_UI_ACTION_DELETE_FOLDER, 
    MMI_SMS_UM_BT_UI_ACTION_DELETE_THRD_MSG, 
    MMI_SMS_UM_BT_UI_ACTION_MOV2ARC_THRD_MSG, 
    MMI_SMS_UM_BT_UI_ACTION_MS_DELETE_THRD_MSG, 
    MMI_SMS_UM_BT_UI_ACTION_MS_MOV2ARC_THRD_MSG, 
    MMI_SMS_UM_BT_UI_ACTION_TOTAL
} mmi_sms_um_bt_ui_req_srv_action_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_EL_REQ_NONE,
    MMI_SMS_UM_BT_UI_FSM_EL_REQ_MSG_NUM,
    MMI_SMS_UM_BT_UI_FSM_EL_REQ_TOTAL
} mmi_sms_um_bt_ui_fsm_el_req_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_EL_INIT,
    MMI_SMS_UM_BT_UI_FSM_EL_INSIDE,
    MMI_SMS_UM_BT_UI_FSM_EL_UPDATE,
    MMI_SMS_UM_BT_UI_FSM_EL_TOTAL
} mmi_sms_um_bt_ui_fsm_entry_list_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_EF_INIT,
    MMI_SMS_UM_BT_UI_FSM_EF_CHECK_READY,
    MMI_SMS_UM_BT_UI_FSM_EF_CHECK_DATA,
    MMI_SMS_UM_BT_UI_FSM_EF_UPDATE_DATA,
    MMI_SMS_UM_BT_UI_FSM_EF_DEINIT,
    MMI_SMS_UM_BT_UI_FSM_EF_TOTAL
} mmi_sms_um_bt_ui_fsm_entry_folder_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_FSM_OP_INIT,
    MMI_SMS_UM_BT_UI_FSM_OP_OPERATION,
    MMI_SMS_UM_BT_UI_FSM_OP_DEINIT,
    MMI_SMS_UM_BT_UI_FSM_OP_TOTAL
} mmi_sms_um_bt_ui_fsm_operation_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_ENTRY_NONE,
    MMI_SMS_UM_BT_UI_ENTRY_KEY_CSK, 
    MMI_SMS_UM_BT_UI_ENTRY_KEY_LSK, 
    MMI_SMS_UM_BT_UI_ENTRY_INTUITIVE_CMD, 
    MMI_SMS_UM_BT_UI_ENTRY_TOTAL
} mmi_sms_um_bt_ui_entry_msg_action_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_BLOCK_SLIDE_SHOW = 0x01    /* close slide show */
} mmi_sms_um_bt_ui_scrn_effect_enum;

typedef enum
{
    MMI_SMS_UM_BT_FOLDER_MODE_DEFAULT = 0, 
    MMI_SMS_UM_BT_FOLDER_MODE_CONVERSATION_BOX, 
    MMI_SMS_UM_BT_FOLDER_MODE_THREAD_MSG, 
    MMI_SMS_UM_BT_FOLDER_MODE_TOTAL
} mmi_sms_um_bt_ui_folder_mode_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_TB_FOLDER_INBOX = 0, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_DRAFT, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_UNSENT, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_SENT, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_ARCHIVE, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_SIM, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_CONVERSATION, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_THREAD_MSG, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_REPORT, 
    MMI_SMS_UM_BT_UI_TB_FOLDER_TOTAL
} mmi_sms_um_bt_ui_tb_action_folder_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_TB_ACTION_NONE = 0,
    MMI_SMS_UM_BT_UI_TB_ACTION_REPLY,
    MMI_SMS_UM_BT_UI_TB_ACTION_FORWARD,
    MMI_SMS_UM_BT_UI_TB_ACTION_SEND,
    MMI_SMS_UM_BT_UI_TB_ACTION_RESEND,
    MMI_SMS_UM_BT_UI_TB_ACTION_EDIT,
    MMI_SMS_UM_BT_UI_TB_ACTION_DELETE,
    MMI_SMS_UM_BT_UI_TB_ACTION_COPY,
    MMI_SMS_UM_BT_UI_TB_ACTION_MOVE,
    MMI_SMS_UM_BT_UI_TB_ACTION_TOTAL
} mmi_sms_um_bt_ui_tb_action_enum;

typedef enum
{
    MMI_SMS_UM_BT_UI_SH_CF_NONE, 
    MMI_SMS_UM_BT_UI_SH_CF_FOLDER_SEND_KEY, 
    MMI_SMS_UM_BT_UI_SH_CF_FOLDER_OPT_DEL_ALL, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_DELETE, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_MOV2ARC, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_MOV2SIM, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_MOV2PHONE, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_CPY2SIM, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_CPY2PHONE, 
    MMI_SMS_UM_BT_UI_SH_CF_DELETE_FOLDER, 
    MMI_SMS_UM_BT_UI_SH_CF_CS_SEND_KEY, 
    MMI_SMS_UM_BT_UI_SH_CF_CS_TB_DELETE, 
    MMI_SMS_UM_BT_UI_SH_CF_CS_OPT_DELETE, 
    MMI_SMS_UM_BT_UI_SH_CF_CS_OPT_DEL_ALL, 
    MMI_SMS_UM_BT_UI_SH_CF_CS_OPT_MOV2ARC, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_CS_OPT_DELETE, 
    MMI_SMS_UM_BT_UI_SH_CF_MS_CS_OPT_MOV2ARC, 
    MMI_SMS_UM_BT_UI_SH_CF_TOTAL
} mmi_sms_um_bt_ui_sh_confirm_action_enum;

/**********UMprot Neccessary Function***********/
/************************************************************************/
/* Utility Macro                                                        */
/************************************************************************/
#if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
#define SET_GENERAL_FOLDER_APRC_TYPE(type)  \
{                                           \
    type = MMI_SMS_UM_BT_UI_APRC_268;              \
}
#define SET_MS_APRC_TYPE(type)              \
{                                           \
    type = MMI_SMS_UM_BT_UI_APRC_1002;             \
}
#elif __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_NORMAL__
#define SET_GENERAL_FOLDER_APRC_TYPE(type)  \
{                                           \
    type = MMI_SMS_UM_BT_UI_APRC_263;              \
}
#define SET_MS_APRC_TYPE(type)              \
{                                           \
    type = MMI_SMS_UM_BT_UI_APRC_267;              \
}
#endif /* __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ */
#define CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx) \
{                                             \
    MMI_ASSERT(NULL != scrn_cntx);            \
    MMI_ASSERT(0 != scrn_cntx->scrn_id);      \
}
#define CHECK_GRP_CNTX_PARA_VALID(grp_cntx)         \
{                                                   \
    MMI_ASSERT(NULL != grp_cntx);                   \
    MMI_ASSERT(GRP_ID_INVALID != grp_cntx->grp_id); \
}
typedef void (*mmi_sms_um_entry_func_ptr) (mmi_scrn_essential_struct *arg);


/* UI level internal structure */

typedef struct
{
    S32 error;                              /* error code */
    srv_um_msg_enum msg_type;               /* message type */
    srv_um_sim_enum sim_id;                 /* sim id */
    U16 inbox_msg_number;                   /* inbox message number */
    U16 inbox_unread_msg_number;            /* inbox unread message number */
    U16 unsent_msg_number;                  /* message number in unsent box */
    U16 sent_msg_number;                    /* message number in sent box */
    U16 draft_msg_number;                   /* message number if draft box */
}srv_sms_um_get_msg_num_rsp_struct;


typedef struct
{
    void (*lsk_hdlr)(void);     /* Left soft key handler */
    void (*rsk_hdlr)(void);     /* Right soft key handler */
    void (*csk_hdlr)(void);     /* Center soft key handler */
    void (*key_hdlr)(void);     /* The special key handler corresponding to key code */
    U16 special_key_code;       /* The special key codes */
    MMI_BOOL clear_end_key;     /* Clear end key flag */
} mmi_sms_um_bt_ui_key_handler_struct;

#ifdef __MMI_ICON_BAR_SUPPORT__
typedef struct
{
    U8 num_of_toolbar;                        /* Number of items in the toolbar */
    PU8 body[MMI_SMS_UM_BT_UI_MAX_TB_ICON];          /* The body of each toolbar icon */
    PU8 hint[MMI_SMS_UM_BT_UI_MAX_TB_ICON];          /* The hint of each toolbar icon */
    PU8 body_disable[MMI_SMS_UM_BT_UI_MAX_TB_ICON];  /* The disabled body of each icon */
    MMI_BOOL status[MMI_SMS_UM_BT_UI_MAX_TB_ICON];   /* The status of each icon, on/off */
    GUIIconbarItemCallback callback;          /* The callback function of each toolbar icon */
} mmi_sms_um_bt_ui_tb_handler_struct;
#endif /* __MMI_ICON_BAR_SUPPORT__ */

typedef struct
{
    MMI_ID grp_id;                                      /* Group id */
    MMI_ID scrn_id;                                     /* Screen id */
    U16 menu_item_id;                                   /* menu id */
    U16 title_str_id;                                   /* String id of title */
    U16 title_icon_id;                                  /* Icon id of title */
    U16 lsk_str_id;                                     /* String id of LSK */
    U16 lsk_icon_id;                                    /* Icon id of LSK */
    U16 rsk_str_id;                                     /* String id of RSK */
    U16 rsk_icon_id;                                    /* Icon id of RSK */
    U16 csk_str_id;                                     /* String id of CSK */
    U16 csk_icon_id;                                    /* Icon id of CSK */
    void (*hilite_hdlr)(S32) ;                          /* Highlight handler */
    S32 hilite_idx;                                     /* Highlight index */
    S32 num_of_item;                                    /* Number of items in this apperance */
    void (*entry_func)(mmi_scrn_essential_struct *);    /* Entry function */
    void (*exit_func)(mmi_scrn_essential_struct *);     /* Exit function */
    U8 *gui_buffer;                                     /* Gui buffer of appearance */
    mmi_sms_um_bt_ui_key_handler_struct key_hdlr;              /* Key handler */
    mmi_proc_func leave_proc;                           /* Screen leave proc handler */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    void (*intuitive_cmd_cb_func)(
            mmi_tap_type_enum tap_type, 
            S32 index);                                 /* The intuitive command callback handler */
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
} mmi_sms_um_bt_ui_aprc_general_cntx_struct;

typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U8 **list_of_items;                                         /* The string list of items */
    U16 *list_of_item_icons;                                    /* The icon id list of items */
    U8 **list_of_item_hints;                                    /* The string hint list of items */
} mmi_sms_um_bt_ui_aprc_st_main_menu_struct;

typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U8 *special_title;                                          /* The pointer of title */
    S32 folder_style;                                           /* The folder tyle flag, refer to MMI_CAT263_DISPLAY_STYLE */
    GetAsyncItemFuncPtr get_item_cb;                            /* Callback function to get the item data */
    GetAsyncHintFuncPtr get_item_hint_cb;                       /* Callback function to get the item hint data */
    AsyncUpdateCallback hilite_notify_cb;                       /* Callback function to get the current highlight */
} mmi_sms_um_bt_ui_aprc_st_folder_struct;


typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U16 msg_str_id;                                             /* Message string id */
    U16 msg_icon_id;                                            /* Message icon id */
    mmi_sms_um_bt_ui_scrn_effect_enum scrn_effect;                     /* Screen effect */
} mmi_sms_um_bt_ui_aprc_st_loading_struct;

typedef union
{
    mmi_sms_um_bt_ui_aprc_st_main_menu_struct main_menu;
    mmi_sms_um_bt_ui_aprc_st_folder_struct folder;
    mmi_sms_um_bt_ui_aprc_st_loading_struct loading;
} mmi_sms_um_bt_ui_aprc_st_union;

typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U8 *special_title;                                          /* The pointer of title */
    S32 folder_style;                                           /* The folder tyle flag, refer to MMI_CAT263_DISPLAY_STYLE */
    GetAsyncItemFuncPtr get_item_cb;                            /* Callback function to get the item data */
    GetAsyncHintFuncPtr get_item_hint_cb;                       /* Callback function to get the item hint data */
    AsyncUpdateCallback hilite_notify_cb;                       /* Callback function to get the current highlight */
} mmi_sms_um_bt_ui_aprc_263_struct;


typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U8 **list_of_items;                                         /* The string list of items */
    U16 *list_of_item_icons;                                    /* The icon id list of items */
    U8 **list_of_item_hints;                                    /* The string hint list of items */
} mmi_sms_um_bt_ui_aprc_53_struct;

typedef struct
{
    mmi_sms_um_bt_ui_aprc_general_cntx_struct general_aprc_cntx;       /* General context of apperance */
    U16 msg_str_id;                                             /* Message string id */
    U16 msg_icon_id;                                            /* Message icon id */
    mmi_sms_um_bt_ui_scrn_effect_enum scrn_effect;                     /* Screen effect */
} mmi_sms_um_bt_ui_aprc_165_struct;


typedef union
{
    mmi_sms_um_bt_ui_aprc_263_struct aprc_263;     /* The appearance 263 struct */
    mmi_sms_um_bt_ui_aprc_53_struct aprc_53;       /* The appearance 53 struct */
    mmi_sms_um_bt_ui_aprc_165_struct aprc_165;     /* The appearance 165 struct */
} mmi_sms_um_bt_ui_aprc_struct_union;

typedef struct
{
    mmi_sms_um_bt_ui_aprc_st_enum st_type;                             /* Screen type */
    mmi_sms_um_bt_ui_aprc_type_enum type;                              /* appearance type */
    MMI_BOOL (*draw_func)(mmi_sms_um_bt_ui_aprc_st_union *,
                          mmi_sms_um_bt_ui_aprc_st_enum);              /* Drawing function */
    MMI_BOOL (*redraw_func)(mmi_sms_um_bt_ui_aprc_st_union *, 
                            mmi_sms_um_bt_ui_aprc_st_enum, 
                            mmi_sms_um_bt_ui_aprc_redraw_type_enum);   /* Redrawing function */
    void *user_data;                                            /* For record some specified data */
} mmi_sms_um_bt_ui_aprc_node_struct;

typedef struct
{
    U16 owner_scrn_id;                                                  /* Onwer screen id */
    U16 num_of_node;                                                    /* Number of nodes */
    srv_um_list_filter_struct sort_type;                                /* Sorting type */
    srv_um_msg_node_struct data_list_table[SRV_UM_BT_MAX_MSG_NUM];         /* Data list */
} mmi_sms_um_bt_ui_data_list_cntx_struct;

typedef void (*mmi_sms_um_bt_ui_fsm_get_msg_num_cb) (U16 scrn_id, sms_um_bt_get_msg_num_result **msg_num);
typedef U16 (*mmi_sms_um_bt_ui_fsm_get_folder_num_cb) (U16 scrn_id);
typedef MMI_BOOL (*mmi_sms_um_bt_ui_fsm_get_msg_info_cb) (U16 srcn_id, 
                                                   U16 start_idx, 
                                                   U16 num_of_items, 
                                                   srv_um_bt_msg_info_struct ***msg_info, 
                                                   srv_um_thread_info_struct ***thread_info);
typedef MMI_BOOL (*mmi_sms_um_bt_ui_fsm_get_msg_content_cb) (U16 srcn_id, 
                                                   U16 start_idx, 
                                                   U16 num_of_items, 
                                                   CHAR **contents);

typedef S32 (*srv_sms_um_get_msg_num_cb) (S32 pid, srv_sms_um_get_msg_num_rsp_struct* rsp, S32 user_data);

typedef struct
{
    srv_um_msg_enum msg_type;                   /* the message type in box */
    srv_um_msg_btmapc_box_enum msg_box_type;           /* the type of box */
    srv_um_sim_enum sim_id;                     /* the sim id of messages */
} srv_sms_um_box_identity_struct;


typedef struct
{
    S32 pid;                                                /* Process id of service */    
    mmi_sms_um_bt_ui_fsm_entry_list_enum state;                    /* State of finite state machine */
    MMI_BOOL req_data;                                      /* Request data checking value */
    U16 scrn_id;                                            /* Screen id */
    mmi_sms_um_bt_ui_fsm_get_msg_num_cb get_msg_num;               /* To get the message number information */
    mmi_sms_um_bt_ui_req_srv_status_enum req_srv_status;           /* Request data status */
    mmi_sms_um_bt_ui_fsm_el_req_enum req_data_type;                /* Request data type */
    srv_sms_um_box_identity_struct req_folder_type;             /* Message type/ SIM type */
    sms_um_bt_get_msg_num_result req_msg_num_result;           /* Message number result */
} mmi_sms_um_bt_ui_fsm_entry_list_struct;

typedef struct
{
    U16 scrn_id;                                            /* Screen id */
    MMI_BOOL req_data;                                      /* Request data flag */
    MMI_BOOL (*scrn_callback_hdlr)(U16, U16, U16);          /* Callback handler for screen handler */
    srv_sms_um_box_identity_struct req_folder_type;             /* Message type/ SIM type */
    mmi_sms_um_bt_ui_fsm_el_req_enum req_data_type;
} mmi_sms_um_bt_ui_fsm_el_setting_struct;

typedef struct
{
    U16 start_msg_idx;                                              /* Start message index */
    U16 num_of_req_item;                                            /* End message index */
    MMI_BOOL data_list_updated;                                     /* Identity the data list is modified */
    srv_um_list_filter_struct filter_type;                          /* The sorting type of this message list */
    S32 list_id;                                                    /* List context id from service */
    srv_um_list_cntx_struct *data_list;                             /* Data list information */
} mmi_sms_um_bt_ui_folder_info_struct;

typedef struct
{
    U16 scrn_id;                                                    /* Screen id */
    srv_sms_um_box_identity_struct folder_type;                         /* Folder type */
    S32 pid;                                                        /* Process id of service */
    mmi_sms_um_bt_ui_fsm_get_folder_num_cb get_msg_num;                    /* Get the number of items in the list */
    mmi_sms_um_bt_ui_fsm_get_msg_info_cb get_msg_info;                     /* Get the message detail information */
    

    mmi_sms_um_bt_ui_folder_info_struct folder_info;                       /* Folder information */
    mmi_sms_um_bt_ui_folder_mode_enum folder_mode;                         /* Folder mode */
    mmi_sms_um_bt_ui_req_srv_status_enum req_srv_status;                   /* Request data status */
    mmi_sms_um_bt_ui_req_srv_action_enum action;                           /* Interactive action with service */
    mmi_sms_um_bt_ui_fsm_entry_folder_enum state;                          /* State of finite state machine */
} mmi_sms_um_bt_ui_fsm_entry_folder_struct;

typedef struct
{
    U16 scrn_id;                                        /* Screen id */
    mmi_sms_um_bt_ui_folder_mode_enum folder_mode;             /* Folder mode */
    srv_sms_um_box_identity_struct folder_type;             /* Folder type */
    MMI_BOOL (*scrn_callback_hdlr)(U16, U16, U16);      /* Callback handler for screen handler */
} mmi_sms_um_bt_ui_fsm_ef_setting_struct;

typedef union
{
    mmi_sms_um_bt_ui_fsm_entry_list_struct fsm_entry_list;         /* Entry list finite state machine */
    mmi_sms_um_bt_ui_fsm_entry_folder_struct fsm_entry_folder;     /* Entry folder finite state machine */
} mmi_sms_um_bt_ui_fsm_struct_union;

typedef struct
{
    mmi_sms_um_bt_ui_fsm_type_enum type;                                   /* Finite state machine type */
    mmi_sms_um_bt_ui_fsm_struct_union cntx;                                /* Finite state mahhine context */
    MMI_BOOL (*event_hdlr)(U16 scrn_id, U16 event, void *arg);      /* Event handler */
    MMI_BOOL (*callback_hdlr)(U16 scrn_id, U16 state, U16 status);  /* Callback function provided by Screen handler */
} mmi_sms_um_bt_ui_fsm_node_struct;

typedef struct
{
    U16 index;
    srv_um_msg_enum msg_type;
    U32 msg_id;
} mmi_sms_um_bt_ui_sh_hilite_info_struct;

typedef struct
{
    mmi_sms_um_bt_ui_sh_hilite_info_struct hilite_info;
    srv_sms_um_box_identity_struct folder_info;
} mmi_sms_um_bt_ui_sh_hilite_folder_info_struct;

typedef struct
{
    MMI_ID disp_scrn_id;                                /* display screen id */
    MMI_ID cf_grp_id;                                   /* Confirm group id */
    mmi_sms_um_bt_ui_sh_confirm_action_enum cf_action;         /* The confirm action type for proc handler */
    U16 num_of_item;                                    /* Number of items in this screen */    
    mmi_sms_um_bt_ui_sh_hilite_info_struct hilite_info;        /* Highlight information */
    MMI_BOOL is_scrn_displayed;                         /* Screen is displayed or not */
    srv_sms_um_box_identity_struct folder_type;             /* Folder type */
    void *scrn_data;                                    /* Screen specified data */
} mmi_sms_um_bt_ui_sh_node_struct;

typedef struct
{
    U16 scrn_id;                                                    /* Screen id */
    U16 parent_scrn_id;                                             /* Parent screen id */
    U16 child_scrn_id;                                              /* Child screen id */
    MMI_ID group_id;                                                /* Screen group id. Framework-based */
    MMI_ID child_group_id;                                          /* Childe screen group id. E.g. menu cui, phb cui */
    mmi_sms_um_bt_ui_aprc_node_struct aprc;                                /* Appearance context */
    mmi_sms_um_bt_ui_fsm_node_struct fsm;                                  /* Finite state machine context */
    mmi_sms_um_bt_ui_sh_node_struct screen_hdlr;                           /* Screen handler context */
    MMI_BOOL (*event_hdlr)(U16 screen_id, U16 event, void *arg);    /* Event handler */
} mmi_sms_um_bt_ui_cc_scrn_cntx_struct;

typedef struct
{
    MMI_BOOL new_grp;                                                       /* Create a new group flag */
    mmi_sms_um_bt_ui_aprc_st_enum aprc_type;                                       /* Appearance */
    MMI_ID parent_group_id;                                                 /* Screen groupd id. Framework-based */
    U16 scrn_id;                                                            /* Screen id */
    U16 parent_scrn_id;                                                     /* Parent screen id */
    U16 disp_scrn_id;                                                       /* display screen id. Framework-based */
    srv_sms_um_box_identity_struct folder;                                      /* folder type */
    MMI_BOOL (*event_hdlr)(U16 screen_id, U16 event, void *arg);            /* Event handler, usually use screen handler */
    void *scrn_data;
} mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct;

typedef MMI_BOOL (*scrn_init_func) (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx,
                                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting);    /* Screen handler init function */
typedef mmi_ret (*mmi_sms_um_confirm_hdlr_ptr) (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);

typedef struct
{
    srv_um_msg_enum msg_type;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
} mmi_sms_um_bt_ui_new_msg_struct;

typedef struct
{
    U16 scrn_id_counter;                                                        /* Unique screen id */
    srv_um_msg_enum support_msg_type;                                           /* supporting message type */
} mmi_sms_um_bt_ui_setting_struct;

typedef struct
{
    MMI_ID root_grp_id;             /* Message root group id */
    MMI_ID grp_id;                  /* UM internal group id */
} mmi_sms_um_bt_ui_cc_grp_cntx_struct;

typedef struct
{
    U16 num_of_scrn;                                                        /* Number of screen contexts in the global screen context table */
    U16 active_scrn;                                                        /* The active screen context */
    U16 num_of_grp;                                                         /* Number of screen group context in the global context */    
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct scrn_table[MMI_SMS_UM_BT_UI_MAX_SCRN_CNTX_NUM];  /* The global screen context table */
    mmi_sms_um_bt_ui_cc_grp_cntx_struct grp_table[MMI_SMS_UM_BT_UI_MAX_GRP_CNTX_NUM];     /* The global group context table */
} mmi_sms_um_bt_ui_cc_cntx_struct;

typedef enum
{
    MMI_SMS_UM_BT_UI_TAB0,     
    MMI_SMS_UM_BT_UI_TAB1,      
    MMI_SMS_UM_BT_UI_TAB2,          
          
    MMI_SMS_UM_BT_UI_TOTAL = 0xff                
} mmi_sms_um_entry_tab_enum;

typedef struct
{
    U16 scrn_id;
    MMI_BOOL is_back_folder;
    srv_sms_btmapc_bt_enum bt_index;
}mmi_sms_bt_entry_folder_userdata;

typedef struct
{
    mmi_sms_um_bt_ui_setting_struct setting;           /* Record the current UI setting */
    mmi_sms_um_bt_ui_cc_cntx_struct cc_cntx;           /* Central control table */
} mmi_sms_um_bt_ui_cntx_struct;

typedef enum
{
    MMI_SMS_UM_BT_ENTRY_SCREEN_MAIN_MENU,
    MMI_SMS_UM_BT_ENTRY_SCREEN_WRITE_MESSAGE,
    MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER,
    MMI_SMS_UM_BT_ENTRY_SCREEN_ENHANCE_CONVERSATION,
    MMI_SMS_UM_BT_ENTRY_SCREEN_TEMPLATE,
    MMI_SMS_UM_BT_ENTRY_SCREEN_DELETE_FOLDER,
    MMI_SMS_UM_BT_ENTRY_SCREEN_SETTING,
    MMI_SMS_UM_BT_ENTRY_SCREEN_LOADING,
    MMI_SMS_UM_BT_ENTRY_SCREEN_DELETE_FOLDER_PROCESSING,
    MMI_SMS_UM_BT_ENTRY_SCREEN_PROGRESS,
    MMI_SMS_UM_BT_ENTRY_SCREEN_TOTAL    
} mmi_sms_um_entry_screen_type;




typedef MMI_BOOL (* mmi_sms_um_bt_ui_fsm_event_hdlr_node) (mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);

extern void mmi_sms_bt_main_msg_entry_box(srv_um_msg_btmapc_box_enum );
extern const mmi_sms_um_bt_ui_fsm_event_hdlr_node fsm_el_tb[10];
extern const mmi_sms_um_bt_ui_fsm_event_hdlr_node sms_um_bt_fsm_ef_tb[20];
extern const mmi_sms_um_bt_ui_fsm_event_hdlr_node fsm_op_tb[7];
extern const U8 g_sms_um_bt_ui_fsm_ef_event_table[MMI_SMS_UM_BT_UI_FSM_EVENT_TOTAL][MMI_SMS_UM_BT_UI_FSM_EF_TOTAL];
extern mmi_sms_um_bt_ui_cntx_struct *g_sms_um_ui_p;
extern srv_um_bt_msg_info_struct *g_sms_um_ui_msg_info_buf_p[MMI_UM_UI_MAX_MSG_INFO_NUM];
extern const U16 g_sms_um_bt_ui_show_hide_menu[];

extern MMI_BOOL g_sms_bt_aprc_enter_tab;
extern MMI_BOOL g_bt_category_error_flag;
extern mmi_sms_um_bt_ui_cc_scrn_cntx_struct *g_sms_bt_sh_get_item_scrn_cntx;
extern mmi_sms_um_bt_ui_aprc_263_struct g_sms_bt_aprc_int_cntx;
extern srv_um_msg_btmapc_box_enum g_sms_bt_mmi_box_type;

/********************************************
 * UM app global functions                  *
 *******************************************/
/* UI initial function */
extern void mmi_sms_um_bt_ui_init(void);
extern MMI_BOOL mmi_sms_um_bt_ui_int_is_available(void);

/********************************************
 * Appearance internal functions            *
 *******************************************/
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_set_cntx(mmi_sms_um_bt_ui_aprc_node_struct *aprc_node, mmi_sms_um_bt_ui_aprc_st_enum aprc_type);
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_263_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                        mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type);
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_263_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                          mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                          mmi_sms_um_bt_ui_aprc_redraw_type_enum type);

extern MMI_BOOL mmi_sms_um_bt_ui_aprc_53_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                        mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type);
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_53_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx,  
                                         mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                         mmi_sms_um_bt_ui_aprc_redraw_type_enum type);
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_53_redraw_body(mmi_sms_um_bt_ui_aprc_struct_union *aprc_cntx);

extern MMI_BOOL mmi_sms_um_bt_ui_aprc_165_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                        mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type);
extern MMI_BOOL mmi_sms_um_bt_ui_aprc_165_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx,  
                                          mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                          mmi_sms_um_bt_ui_aprc_redraw_type_enum type);

extern void mmi_sms_um_bt_ui_aprc_set_key_hdlr(mmi_sms_um_bt_ui_key_handler_struct *key_hdlr);
extern void mmi_sms_um_bt_ui_aprc_enable_softkey(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx);
extern void mmi_sms_um_bt_ui_aprc_change_key_hdlr(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx);
extern void mmi_sms_um_bt_ui_aprc_reg_leave_proc(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
extern void mmi_sms_um_bt_ui_aprc_reg_intuitive_cmd_cb_hdlr(void(* intuitive_cb_hdlr)(mmi_tap_type_enum tap_type, S32 index));
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
extern void mmi_sms_um_bt_ui_aprc_set_int_cntx(mmi_sms_um_bt_ui_aprc_struct_union *aprc_cntx, 
                                        mmi_sms_um_bt_ui_aprc_type_enum aprc_type, 
                                        mmi_sms_um_bt_ui_aprc_st_union *aprc_st_cntx, 
                                        mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type);

extern void mmi_sms_um_bt_ui_fsm_el_get_msg_num(U16 scrn_id, sms_um_bt_get_msg_num_result **msg_num);
/* Entry folder FSM */
extern void mmi_sms_um_bt_ui_fsm_ef_init(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, mmi_sms_um_bt_ui_fsm_ef_setting_struct setting);
extern void mmi_sms_um_bt_ui_fsm_ef_check_ready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_check_data(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_update_data(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_deinit(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_msg_list_status_cb(S32 event, S32 list_id, S32 para);
extern S32 mmi_sms_um_bt_ui_fsm_ef_req_msg_list_cb(S32 pid, srv_um_get_msg_list_result *rsp, S32 para);
extern S32 mmi_sms_um_bt_ui_fsm_ef_req_msg_info_cb(S32 pid, srv_um_get_msg_info_result *rsp, S32 para);
extern U16 mmi_sms_um_bt_ui_fsm_ef_get_msg_num(U16 scrn_id);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_get_msg_info(
                U16 scrn_id, 
                U16 start_idx, 
                U16 end_idx, 
                srv_um_bt_msg_info_struct ***msg_info, 
                srv_um_thread_info_struct ***thread_info);
extern U16 mmi_sms_um_bt_ui_fsm_ef_get_action(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_set_box_identity(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, srv_sms_um_box_identity_struct *box_identity);
extern void mmi_sms_um_bt_ui_fsm_ef_set_list_filter_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, srv_um_list_filter_struct filter);
extern srv_um_list_filter_struct *mmi_sms_um_bt_ui_fsm_ef_get_list_filter_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern srv_um_sim_enum mmi_sms_um_bt_ui_fsm_ef_get_sim_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_ef_set_sim_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, srv_um_sim_enum sim_type);
extern S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_list(
                srv_sms_um_box_identity_struct msg_box,
                srv_um_list_filter_struct *filter,
                srv_um_notify_list_handler cb_func,
                S32 user_data,
                srv_um_list_cntx_struct **list_cntx, 
                mmi_sms_um_bt_ui_folder_mode_enum mode);
extern S32 mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_list(
                srv_sms_um_box_identity_struct msg_box,
                srv_um_list_filter_struct *filter,
                srv_um_get_list_cb cb_func,
                S32 user_data, 
                mmi_sms_um_bt_ui_folder_mode_enum mode);
extern S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info(
                srv_sms_um_box_identity_struct msg_box,
                void *msg_list,
                U16 list_info_size,
                U16 start_entry,
                U16 msg_number,
                srv_um_bt_msg_info_struct msg_info[], 
                mmi_sms_um_bt_ui_folder_mode_enum mode);
extern S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info_by_ref(
                srv_sms_um_box_identity_struct msg_box,
                void *msg_list,
                U16 list_info_size,
                U16 start_entry,
                U16 msg_number,
                srv_um_bt_msg_info_struct *msg_info[], 
                srv_um_thread_info_struct *thread_info[], 
                mmi_sms_um_bt_ui_folder_mode_enum mode);
extern S32 mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_info(
                srv_sms_um_box_identity_struct msg_box,
                void *msg_list,
                U16 msg_number,
                void *cb_func,
                S32 user_data, 
                mmi_sms_um_bt_ui_folder_mode_enum mode);
extern mmi_sms_um_bt_ui_folder_mode_enum mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void  mmi_sms_um_bt_ui_fsm_ef_set_folder_mode(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, mmi_sms_um_bt_ui_folder_mode_enum folder_mode);

/* Utility for finite state machine */
extern srv_um_list_cntx_struct *mmi_sms_um_bt_ui_fsm_get_data_list_ptr(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern void mmi_sms_um_bt_ui_fsm_set_data_list_ptr(
                            mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx,
                            srv_um_list_cntx_struct *data_list);
extern U16 mmi_sms_um_bt_ui_fsm_get_fsm_state(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
extern U16 mmi_sms_um_bt_ui_fsm_get_fsm_req_srv_status(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);
//extern U8 mmi_sms_um_bt_ui_fsm_query_status(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx);

/********************************************
 * FSM event handler    internal functions  *
 *******************************************/
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_eh_dummy(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);

/* common popup */
extern void mmi_sms_um_current_not_avaiable_popup(void);

/* Entry folder FSM event handler */
/****************************************************************************************************
 *  Cross table for entry folder FSM event handler                                                  *
 *                                                                                                  *
 *  ----------      init            check_ready         check_data          update_data     deinit  *
 *  ----------------------------------------------------------------------------------------------- *
 *  INIT            init_init       dummy               dummy               dummy           dummy   *
 *  REFRESH         dummy           dummy               cd_refresh          ud_refresh      dummy   *
 *  ABORT           dummy           dummy               dummy               dummy           dummy   *
 *  DELETE          init_delete     cr_delete           cd_delete           ud_delete       dummy   *
 *  CHECK           dummy           cr_check            cd_check            ud_check        dummy   *
 *  READY           dummy           cr_ready            dummy               dummy           dummy   *
 *  UNREADY         dummy           dummy               cd_unready          ud_unready      dummy   *
 *  REL_DATA_LIST   dummy           dummy               cd_rel_list         ud_rel_list     dummy   *
 *  UPDATE_DATA_LISTdummy           dummy               cd_up_list          ud_up_list      dummy   *
 *  KEEP_DATA_LIST  init_kp_list    dummy               dummy               dummy           dummy   *
 *  SET_FSM_DATA    dummy           dummy               dummy               dummy           dummy   *
 *  ----------------------------------------------------------------------------------------------- *
 ***************************************************************************************************/
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_init(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_kp_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_ready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_refresh(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_unready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_rel_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_up_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_refresh(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_unready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_rel_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_up_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg);

 
/********************************************
 * Central controller internal functions    *
 *******************************************/
extern MMI_BOOL mmi_sms_um_bt_ui_cc_create_scrn_cntx(mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting, scrn_init_func init);
extern void mmi_sms_um_bt_ui_cc_event_hdlr(U16 event);
extern MMI_BOOL mmi_sms_um_bt_ui_cc_send_event(U16 scrn_id, mmi_sms_um_bt_ui_event_enum event, void *arg);
extern mmi_sms_um_bt_ui_cc_scrn_cntx_struct* mmi_sms_um_bt_ui_cc_get_scrn_cntx(U16 scrn_id);
extern U16 mmi_sms_um_bt_ui_cc_get_parent_scrn_id(U16 scrn_id);
extern U16 mmi_sms_um_bt_ui_cc_get_child_scrn_id(U16 scrn_id);
extern MMI_BOOL mmi_sms_um_bt_ui_cc_check_scrn_alive(U16 scrn_id);
extern void mmi_sms_um_bt_ui_cc_delete_scrn_cntx(U16 scrn_id);
extern mmi_sms_um_bt_ui_cc_scrn_cntx_struct* mmi_sms_um_bt_ui_cc_get_free_scrn_cntx(void);
extern void mmi_sms_um_bt_ui_cc_delete_all_scrn(void);
//extern srv_um_msg_enum mmi_sms_um_bt_ui_cc_get_support_msg_type_by_scrn_id(U16 scrn_id);
//extern U16 mmi_sms_um_bt_ui_cc_get_disp_scrn_id(U16 scrn_id);
//extern U16 mmi_sms_um_bt_ui_cc_get_grp_id(U16 scrn_id);
//extern U16 mmi_sms_um_bt_ui_cc_get_scrn_id_by_box_type(srv_um_msg_box_enum box_type);
extern mmi_sms_um_bt_ui_cc_grp_cntx_struct *mmi_sms_um_bt_ui_cc_get_free_grp_cntx(void);
extern void mmi_sms_um_bt_ui_cc_del_grp_cntx(mmi_sms_um_bt_ui_cc_grp_cntx_struct *grp_cntx);
extern mmi_ret mmi_sms_um_bt_ui_cc_grp_proc(mmi_event_struct *evt);
extern U16 mmi_sms_um_bt_ui_cc_get_grp_num(void);
extern mmi_ret mmi_sms_um_bt_ui_cc_destroy_all_grp(void);
extern MMI_ID mmi_sms_um_bt_ui_cc_get_root_grp_id(MMI_ID group_id);
extern srv_um_msg_btmapc_box_enum mmi_sms_um_bt_ui_cc_get_active_scrn_msg_box(void);
//extern mmi_ret mmi_sms_um_bt_ui_cc_sim_ctrl_unavailable_hdlr(mmi_event_struct *evt);
//extern mmi_ret mmi_sms_um_bt_ui_cc_sim_ctrl_available_hdlr(mmi_event_struct *evt);
//extern mmi_ret mmi_sms_um_bt_ui_cc_sim_status_hdlr(mmi_event_struct *evt);
//extern mmi_ret mmi_sms_um_bt_ui_cc_mode_switch_status_hdlr(mmi_event_struct *evt);

/********************************************
 * Screen handler internal functions        *
 *******************************************/
/* Main message screen */
extern MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_init(
                            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                            mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_event_hdlr(U16 scrn_id, U16 event, void *arg);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry(mmi_scrn_essential_struct *arg);
extern void mmi_sms_um_bt_ui_sh_main_msg_exit(mmi_scrn_essential_struct *arg);
extern void mmi_sms_um_bt_ui_sh_main_msg_hilite_hdlr(S32 index);
extern void mmi_sms_um_bt_ui_sh_main_msg_update(void *arg);
extern void mmi_sms_um_bt_ui_sh_main_msg_update_item(U8 **item_string, srv_um_get_msg_num_result * msg_num_info);
//extern void mmi_sms_um_bt_ui_sh_main_msg_update_item_hint(U8 **item_hint, srv_um_get_msg_num_result *msg_num_info);
extern void mmi_sms_um_bt_ui_sh_main_msg_reset(void *arg);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_folder(srv_um_msg_btmapc_box_enum msg_box, U16 scrn_id);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_write_msg(void);
extern void mmi_sms_um_bt_ui_sh_main_msg_arrange_menu_item(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);
//extern void mmi_sms_um_bt_ui_sh_main_msg_adjust_menu_item(
                                    //MMI_BOOL is_shown, 
                                    //U16 child_item_id, 
                                    //U16 parent_item_id, 
                                    //mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);
extern void mmi_sms_um_bt_ui_sh_main_message_update_by_app(U16 menu_item_id, U8 *update_string, void *user_data);
/* Folder screen */
extern MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_init(
                            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                            mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_event_hdlr(U16 scrn_id, U16 event, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_fsm_cb(U16 scrn_id, U16 state, U16 status);
extern void mmi_sms_um_bt_ui_sh_general_folder_entry(mmi_scrn_essential_struct *arg);
extern void mmi_sms_um_bt_ui_sh_general_folder_tab_entry(mmi_scrn_essential_struct* scr_ess);
extern void mmi_sms_um_bt_ui_sh_general_folder_exit(mmi_scrn_essential_struct *arg);
extern U8 mmi_sms_um_bt_ui_sh_general_folder_destroy(void *arg);
extern mmi_ret mmi_sms_um_bt_ui_sh_general_folder_leave_proc(mmi_event_struct *evt);
extern void mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr(void);
extern void mmi_sms_um_bt_ui_sh_general_folder_rsk_hdlr(void);
extern void mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr(void);
extern U16 mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);
extern void mmi_sms_um_bt_ui_sh_general_folder_hilite_hdlr(S32 index);
extern void mmi_sms_um_bt_ui_sh_general_folder_notify_highlight(S32 index);
extern mmi_ret mmi_sms_um_bt_ui_sh_general_folder_opt_proc(mmi_event_struct *evt);
extern mmi_ret mmi_sms_um_bt_ui_sh_general_folder_opt_list_entry_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_sms_um_bt_ui_sh_general_folder_opt_item_select_hdlr(mmi_event_struct *evt);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
//extern void mmi_sms_um_bt_ui_sh_general_folder_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
extern mmi_sms_um_entry_func_ptr mmi_sms_um_bt_ui_sh_general_folder_get_entry_func(mmi_sms_um_bt_ui_folder_mode_enum mode);
/* Message write */
extern MMI_BOOL mmi_sms_um_bt_ui_sh_write_msg_init(
                            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                            mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_write_msg_event_hdlr(U16 scrn_id, U16 event, void *arg);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_write_msg_fsm_cb(U16 scrn_id, U16 state, U16 status);
extern void mmi_sms_um_bt_ui_sh_write_msg_entry(mmi_scrn_essential_struct *arg);
extern void mmi_sms_um_bt_ui_sh_write_msg_hilite_hdlr(S32 index);
extern void mmi_sms_um_bt_ui_sh_write_msg_lsk_hdlr(void);


/* Processing */
extern MMI_BOOL mmi_sms_um_bt_ui_sh_process_init(
                            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                            mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting);
extern MMI_BOOL mmi_sms_um_bt_ui_sh_process_event_hdlr(U16 scrn_id, U16 event, void *arg);
extern void mmi_sms_um_bt_ui_sh_process_entry(mmi_scrn_essential_struct *arg);
extern void mmi_sms_um_bt_ui_sh_process_rsk_hdlr(void);
extern void mmi_sms_um_bt_ui_sh_process_clean_rsk_hdlr(void *arg);




/* General function handler */
extern void mmi_sms_um_bt_ui_sh_create(mmi_sms_um_entry_func_ptr entry_func_ptr, mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);
extern void mmi_sms_um_bt_ui_sh_rsk_hdlr(void);
extern U8 mmi_sms_um_bt_ui_sh_destroy(void *arg);
extern mmi_ret mmi_sms_um_bt_ui_sh_leave_proc(mmi_event_struct *evt);
extern S32 mmi_sms_um_bt_ui_sh_get_async_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_of_item);
extern void mmi_sms_um_bt_ui_sh_evt_hdlr_delete(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, void *arg);
extern mmi_sms_um_bt_ui_cc_scrn_cntx_struct *mmi_sms_um_bt_ui_sh_get_active_user_data(void);



/********************************************
 * Adaptor of message application functions *
 *******************************************/
extern MMI_ID mmi_sms_um_bt_ui_adp_entry_msg(srv_um_msg_enum msg_type, mmi_sms_um_entry_msg_struct *para);
extern MMI_BOOL mmi_sms_um_bt_ui_adp_check_reentry(srv_um_msg_enum msg_type);
extern MMI_BOOL mmi_sms_um_bt_ui_adp_check_pending_action(srv_um_msg_enum msg_type);
extern mmi_ret mmi_sms_um_bt_ui_adp_receive_event(mmi_event_struct *evt);

extern MMI_MENU_ID mmi_sms_um_bt_ui_adp_get_opt_menu_id(srv_um_msg_enum msg_type, U32 msg_id);
extern mmi_ret mmi_sms_um_bt_ui_adp_opt_cb(mmi_event_struct *evt, srv_um_msg_enum msg_type, mmi_sms_um_opt_para_struct *para);
extern MMI_ID mmi_sms_um_bt_ui_adp_cui_launch_by_menu_id(MMI_ID parent_grp_id, MMI_MENU_ID menu_id);
extern srv_um_msg_btmapc_box_enum mmi_sms_um_bt_ui_adp_get_msg_box(srv_um_msg_btmapc_box_enum msg_type, U32 msg_id);


/********************************************
 * Utility internal functions               *
 *******************************************/
extern U16 mmi_sms_um_bt_ui_ut_get_str_id_by_folder(srv_sms_um_box_identity_struct folder_type);
extern U16 mmi_sms_um_bt_ui_ut_get_fsm_event_by_ui_event(U16 ui_event);
extern U16 mmi_sms_um_bt_ui_ut_get_msg_num_by_msg_box(srv_um_msg_btmapc_box_enum msg_box, sms_um_bt_get_msg_num_result *msg_num_info);

//extern srv_um_msg_box_enum mmi_sms_um_bt_ui_ut_get_box_type_by_delete_menu_id(U16 menu_id);
//extern MMI_BOOL mmi_sms_um_bt_ui_ut_check_all_msg_pending_action(void);
//extern U16 mmi_sms_um_bt_ui_ut_get_pending_action_error_str_id(srv_um_msg_enum msg_type);

extern U16 mmi_sms_um_bt_ui_ut_create_scrn_id(void);
extern srv_um_bt_msg_info_struct **mmi_sms_um_bt_ui_ut_get_msg_info_buf(void);

//extern void mmi_sms_um_bt_ui_ut_concate_str_with_msg(S8 *input_str_asc, S8 *output_str_ucs2);
//extern void mmi_sms_um_bt_ui_ut_concate_str_with_msgs(S8 *input_str_asc, S8 *output_str_ucs2);
//extern void mmi_sms_um_bt_ui_ut_concate_str_with_num(S8 *input_str_asc, S8 *output_str_ucs2);
extern void mmi_sms_um_bt_ui_ut_del_relative_scrn(U16 *scrn_id);
extern void mmi_sms_um_bt_ui_ut_notify_scrn_deleted(U16 scrn_id);
extern void mmi_sms_um_bt_ui_ut_send_init_event(U16 scrn_id);
extern U16 mmi_sms_um_bt_ui_ut_get_disp_scrn_id_by_scrn_id(U16 scrn_id);
srv_um_msg_enum mmi_sms_um_bt_ui_cc_get_support_msg_type_by_scrn_id(U16 scrn_id);


extern void mmi_sms_um_bt_ui_ut_update_item_by_menu_id(U16 parent_menu_id, U16 menu_id, U8 **item_string, U16 number);
//extern void mmi_sms_um_bt_ui_ut_update_item_hint_by_menu_id(U16 parent_menu_id, U16 menu_id, U8 **item_hint, U16 number);
//extern MMI_BOOL mmi_sms_um_bt_ui_ut_check_all_msg_reentry(void);


/********************************************
 * Interface internal functions             *
 *******************************************/
 
extern U16 mmi_sms_um_bt_ui_if_entry_general(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp, U16 type, void *extend_data);
extern U16 mmi_sms_um_bt_ui_if_entry_write_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp);
extern U16 mmi_sms_um_bt_ui_if_entry_main_msg(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp);
extern U16 mmi_sms_um_bt_ui_if_entry_processing(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp);
extern void mmi_sms_bt_um_set_sms_context(U32 msg_id);
extern S32 srv_sms_um_bt_get_msg_num(
        srv_um_msg_enum msg_type,
        srv_um_sim_enum sim_id,
        srv_sms_um_get_msg_num_cb cb_func,
        S32 user_data);
extern void mmi_sms_um_bt_close_list_screen();

extern mmi_ret mmi_sms_um_bt_deinit_grp_cntx_on_shift(mmi_event_struct *evt);

/***************************************************
* SMS viewer methods declarations *
****************************************************/
extern void mmi_sms_bt_box_list_opt_pre_view(void);
extern void mmi_sms_bt_entry_menu_cui_options_generic(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id);
extern MMI_MENU_ID mmi_sms_bt_get_viewer_opt_menu_id(U16 msg_id);
extern MMI_ID mmi_sms_bt_um_entry_msg(mmi_um_entry_msg_struct *entry_msg_param);
extern MMI_BOOL mmi_sms_um_bt_ui_fsm_event_hdlr(U16 scrn_id, U16 event, void *arg);
extern void mmi_sms_bt_um_ui_aprc_263_tab_local(mmi_scrn_essential_struct* et_data);
extern void mmi_sms_bt_um_ui_aprc_263_tab_BT(mmi_scrn_essential_struct* et_data);
extern SrvSmsCallbackFunc mmi_sms_bt_get_callback_hdlr(srv_um_msg_btmapc_box_enum box_enum);



typedef enum
{
  MMI_SMS_BT_LIST_NONE,
  MMI_SMS_BT_LIST_INBOX,
  MMI_SMS_BT_LIST_OUTBOX,
  MMI_SMS_BT_LIST_DRAFTS,
  MMI_SMS_BT_LIST_UNSENT,
  MMI_SMS_BT_LIST_ARCHIVE,
  MMI_SMS_BT_LIST_SIMBOX,
  MMI_SMS_BT_LIST_REPORT,
  MMI_SMS_BT_LIST_MESSAGING_DATA,
  MMI_SMS_BT_LIST_RECENT_EVENT,
  MMI_SMS_BT_LIST_TOOLBAR,
  MMI_SMS_BT_LIST_TOTAL
}mmi_sms_bt_list_enum;

typedef enum
{
    SMS_BT_MSG_TYPE_TEXT,
    SMS_BT_MSG_TYPE_EMAIL,
    SMS_BT_MSG_TYPE_UNLIMITED,
    SMS_BT_MSG_TYPE_TOTAL
}mmi_sms_bt_msg_type_enum;

typedef enum
{
    SMS_BT_STATUS_UNREAD,
    SMS_BT_STATUS_INBOX,
    SMS_BT_STATUS_SENT,
    SMS_BT_STATUS_UNSENT,
    SMS_BT_STATUS_DRAFTS,
    SMS_BT_STATUS_DELIVERY_REPORT,
    SMS_BT_STATUS_PENDING_REPORT,
    SMS_BT_STATUS_UNSUPPORT,
    SMS_BT_STATUS_TOTAL
}mmi_sms_bt_msg_status_enum;

typedef enum
{
	SMS_BT_SEND_CASE_NONE,
	SMS_BT_SEND_CASE_WRITE_NEW_MSG,
    SMS_BT_SEND_CASE_REPLY,
	SMS_BT_SEND_CASE_EDIT_DRAFT,
	SMS_BT_SEND_CASE_EDIT_UNSENT,
	SMS_BT_SEND_CASE_FORWARD,
	SMS_BT_SEND_CASE_RESEND,
	SMS_BT_SEND_CASE_SEND_DRAFT,

    SMS_BT_SEND_CASE_TOTAL
}mmi_sms_bt_send_case_enum;

typedef struct
{
    S32 currHiliteIndex;
    U16 curr_msg_index;
    U16 curr_msg_type;

    U16 curr_msg_id;

    U16 ind_msg_index;

    EMSData *edit_ems_data;
    EMSData *view_ems_data;

    void *user_data;

    mmi_sms_bt_list_enum curr_list_type;
    srv_sms_box_enum curr_box_type;
    mmi_sms_bt_msg_status_enum curr_msg_status;

    MMI_BOOL msg_ind_in_idle;

    MMI_BOOL is_from_hs;

    U8 report_count;

#ifdef __MMI_UM_REPORT_BOX__
    U16 curr_report_id;
#else /* __MMI_UM_REPORT_BOX__ */
    srv_sms_status_report_struct *report_data[1];
#endif /* __MMI_UM_REPORT_BOX__ */

} mmi_sms_bt_context_struct;



#endif
#endif
