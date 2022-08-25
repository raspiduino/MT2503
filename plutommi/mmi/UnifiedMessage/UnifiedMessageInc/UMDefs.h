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

/*******************************************************************************
 * Filename:
 * ---------
 * UMDefs.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#ifndef UM_DEFS_H
#define UM_DEFS_H

#ifdef __UM_SUPPORT__
/* This file is used by MMI task and other task,Please do not use MMI type. */

#include "UmSrvDefs.h"

/* UI define value */
#define MMI_UM_UI_MAX_SCRN_CNTX_NUM (6)
#define MMI_UM_UI_MAX_GRP_CNTX_NUM (1)
#ifdef __MMI_SMS_SLIM__
#define MMI_UM_UI_MAX_MSG_INFO_NUM (11)
#else
#define MMI_UM_UI_MAX_MSG_INFO_NUM (10)
#endif
#define MMI_UM_UI_BIT_MARK_STATUS_SIZE (sizeof(U32)*8)
#define MMI_UM_UI_MAX_BIT_MARK_STATUS_NUM (SRV_UM_MAX_MSG_NUM/MMI_UM_UI_BIT_MARK_STATUS_SIZE + 1)
#define MMI_UM_UI_MAX_LEN_TIME_STR  (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/
#define MMI_UM_UI_MAX_GET_STRING_LEN (16)
#define MMI_UM_UI_MAX_MSG_NUM_DIGIT    (6)          /* Display the maximum length of message number string*/
#define MMI_UM_UI_MAX_CONFIRM_STR_LEN (256)         /* Display the maximum confirm string */
#define MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN (48)   /* the maximum length of unread message string */
#define MMI_UM_UI_FSM_MAX_NUM_OF_INVALID_PID (8)    /* refer to UMS_MAX_PROCESS */
#define MMI_UM_UI_MAX_TB_ICON (3)
#define MMI_UM_UI_PROGRESS_INTERVAL (100)

#define MMI_MSG_MAIN_SCREEN_TAB_COUNT                  (3)

/* max support link */
#define MMI_UM_UI_MAX_DEV_LIST_NUM                  (2)


/* UI enum */
typedef enum
{
    MMI_UM_UI_APRC_263,
    MMI_UM_UI_APRC_267,
    MMI_UM_UI_APRC_268,
    MMI_UM_UI_APRC_53,
    MMI_UM_UI_APRC_52,
    MMI_UM_UI_APRC_8,
    MMI_UM_UI_APRC_165,
    MMI_UM_UI_APRC_1002,
    MMI_UM_UI_APRC_36, 
    MMI_UM_UI_APRC_6003, 
    MMI_UM_UI_APRC_THREAD_ENHANCE,    
    MMI_UM_UI_APRC_THREAD_ENHANCE_MS,
    MMI_UM_UI_APRC_TOTAL
} mmi_um_ui_aprc_type_enum;

typedef enum
{
    MMI_UM_UI_SCRN_TYPE_MAIN_MENU, 
    MMI_UM_UI_SCRN_TYPE_FOLDER, 
    MMI_UM_UI_SCRN_TYPE_MS, 
    MMI_UM_UI_SCRN_TYPE_LIST, 
    MMI_UM_UI_SCRN_TYPE_LOADING, 
    MMI_UM_UI_SCRN_TYPE_LOADING_PGRS, 
    MMI_UM_UI_SCRN_TYPE_CONVERSATION_BOX, 
    MMI_UM_UI_SCRN_TYPE_THRD_MSG, 
    MMI_UM_UI_SCRN_TYPE_MS_CONVERSATION_BOX, 
    MMI_UM_UI_SCRN_TYPE_MS_THRD_MSG, 
    MMI_UM_UI_SCRN_TYPE_CONVERSATION_SETTING, 
    MMI_UM_UI_SCRN_TYPE_PREFER_SIM_SETTING,
    MMI_UM_UI_SCRN_TYPE_TOTAL
} mmi_um_ui_aprc_st_enum;

typedef enum
{
    MMI_UM_UI_APRC_REDRAW_TITLE     = 0x01,
    MMI_UM_UI_APRC_REDRAW_BODY      = 0x02,
    MMI_UM_UI_APRC_REDRAW_KEY       = 0x04, 
    MMI_UM_UI_APRC_REDRAW_TB_ICON   = 0x08, 
    MMI_UM_UI_APRC_REDRAW_TB_STATUS = 0x10, 
    MMI_UM_UI_APRC_REDRAW_TOTAL
} mmi_um_ui_aprc_redraw_type_enum;

typedef enum
{
    MMI_UM_UI_FSM_NONE,
    MMI_UM_UI_FSM_ENTRY_LIST,
    MMI_UM_UI_FSM_ENTRY_FOLDER,
    MMI_UM_UI_FSM_OPERATION,
    MMI_UM_UI_FSM_TOTAL
} mmi_um_ui_fsm_type_enum;

typedef enum
{
    MMI_UM_UI_EVENT_INIT,                   /* 0, Initial event for finite state machine */
    MMI_UM_UI_EVENT_REFRESH,                /* 1, refresh the data in the finite state machine */
    MMI_UM_UI_EVENT_ABORT,                  /* 2, abort the finite state machine action */
    MMI_UM_UI_EVENT_DELETE,                 /* 3, delete the related screen */
    MMI_UM_UI_EVENT_DELETED,                /* 4, inform the parent screen that child is deleted */
    MMI_UM_UI_EVENT_CHECK,                  /* 5, check the data in the finite state machine */
    MMI_UM_UI_EVENT_READY,                  /* 6, the service is ready */
    MMI_UM_UI_EVENT_UNREADY,                /* 7, the service is un-ready */
    MMI_UM_UI_EVENT_REL_DATA_LIST,          /* 8, release the data list from finite state machine */
    MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE,       /* 9, highlight is modified by other app, msg_id & msg_type */
    MMI_UM_UI_EVENT_HIGHLIGHT_IDX_CHANGE,   /* 10, highlight index is modified by central controller */
    MMI_UM_UI_EVENT_SET_MS_LIST,            /* 11, Set the mark information list to child screen */
    MMI_UM_UI_EVENT_REL_MS_LIST,            /* 12, Release the mark information list */
    MMI_UM_UI_EVENT_NOTIFY_PARENT_FOLDER,   /* 13, Notify parent folder information to child screen */
    MMI_UM_UI_EVENT_CLEAN_RSK_HDLR,         /* 14, Clean the rsk handler */
    MMI_UM_UI_EVENT_SET_SPT_MSG_TYPE,       /* 15, Set the support message type */
    MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE,     /* 16, Set number of message inside the folder, used to support "empty folder screen" */
    MMI_UM_UI_EVENT_SET_FILTER_TYPE,        /* 17, Set the sorting type of beginning, thread id also */
    MMI_UM_UI_EVENT_SET_OP_TYPE,            /* 18, Set the operation type. Refer to mmi_um_ui_req_srv_action_enum */
    MMI_UM_UI_EVENT_SET_FOLDER_MODE,        /* 19, Set the folder mode of entry folder. Refer to mmi_um_ui_folder_mode_enum */
    MMI_UM_UI_EVENT_SET_THREAD_ID,          /* 20, Set the thread id for operation */
    MMI_UM_UI_EVENT_QUERY_INDEXING,         /* 21, Query the indexing information from external app. */
    MMI_UM_UI_EVENT_SET_MS_OP_TYPE,         /* 22, Set the ms operation type */
    MMI_UM_UI_EVENT_TOTAL
} mmi_um_ui_event_enum;

typedef enum
{
    MMI_UM_UI_FSM_EVENT_INIT,               /* 0, Initialize */
    MMI_UM_UI_FSM_EVENT_REFRESH,            /* 1, Refresh indication */
    MMI_UM_UI_FSM_EVENT_ABORT,              /* 2, Abort the action */
    MMI_UM_UI_FSM_EVENT_DELETE,             /* 3, Delete the finite state machine */
    MMI_UM_UI_FSM_EVENT_CHECK,              /* 4, Check the current data */
    MMI_UM_UI_FSM_EVENT_READY,              /* 5, Ready indication */
    MMI_UM_UI_FSM_EVENT_UNREADY,            /* 6, Unready indication */
    MMI_UM_UI_FSM_EVENT_REL_DATA_LIST,      /* 7, Release data list */
    MMI_UM_UI_FSM_EVENT_UPDATE_DATA_LIST,   /* 8, Turn on the flag of update data list */
    MMI_UM_UI_FSM_EVENT_KEEP_DATA_LIST,     /* 9, Turn off the flag of update data list */
    MMI_UM_UI_FSM_EVENT_SET_FSM_DATA,       /* 10, Set the FSM needed data. ex: operation FSM */
    MMI_UM_UI_FSM_EVENT_TOTAL
} mmi_um_ui_fsm_event_enum;

typedef enum
{
    MMI_UM_UI_REQ_SRV_NONE,                 /* 0, Non request service action */
    MMI_UM_UI_REQ_SRV_WAIT_READY,           /* 1, Wait service ready */
    MMI_UM_UI_REQ_SRV_FINISH,               /* 2, Service response finish */
    MMI_UM_UI_REQ_SRV_PROGRESS,             /* 3, Progress with service */
    MMI_UM_UI_REQ_SRV_FAIL,                 /* 4, Service response fail */
    MMI_UM_UI_REQ_SRV_CANCELLING,           /* 5, Service is during cancelling */
    MMI_UM_UI_REQ_SRV_CANCELLED,            /* 6, Service is cancelled */
    MMI_UM_UI_REQ_SRV_CANCEL_FAIL,          /* 7, Service cancelled fail */
    MMI_UM_UI_REQ_SRV_TOTAL
} mmi_um_ui_req_srv_status_enum;

typedef enum
{
    MMI_UM_UI_ACTION_NONE,
    MMI_UM_UI_ACTION_GET_MSG_NUM,
    MMI_UM_UI_ACTION_GET_MSG_LIST,
    MMI_UM_UI_ACTION_GET_MSG_INFO,
    MMI_UM_UI_ACTION_GET_MSG_CONTENT,
    MMI_UM_UI_ACTION_GET_THRD_INFO, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM, 
    MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE, 
    MMI_UM_UI_ACTION_DELETE_FOLDER, 
    MMI_UM_UI_ACTION_DELETE_THRD_MSG, 
    MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG, 
    MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG, 
    MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG, 
    MMI_UM_UI_ACTION_TOTAL
} mmi_um_ui_req_srv_action_enum;

typedef enum
{
    MMI_UM_UI_FSM_EL_REQ_NONE,
    MMI_UM_UI_FSM_EL_REQ_MSG_NUM,
    MMI_UM_UI_FSM_EL_REQ_TOTAL
} mmi_um_ui_fsm_el_req_enum;

typedef enum
{
    MMI_UM_UI_FSM_EL_INIT,
    MMI_UM_UI_FSM_EL_INSIDE,
    MMI_UM_UI_FSM_EL_UPDATE,
    MMI_UM_UI_FSM_EL_TOTAL
} mmi_um_ui_fsm_entry_list_enum;

typedef enum
{
    MMI_UM_UI_FSM_EF_INIT,
    MMI_UM_UI_FSM_EF_CHECK_READY,
    MMI_UM_UI_FSM_EF_CHECK_DATA,
    MMI_UM_UI_FSM_EF_UPDATE_DATA,
    MMI_UM_UI_FSM_EF_DEINIT,
    MMI_UM_UI_FSM_EF_TOTAL
} mmi_um_ui_fsm_entry_folder_enum;

typedef enum
{
    MMI_UM_UI_FSM_OP_INIT,
    MMI_UM_UI_FSM_OP_OPERATION,
    MMI_UM_UI_FSM_OP_DEINIT,
    MMI_UM_UI_FSM_OP_TOTAL
} mmi_um_ui_fsm_operation_enum;

typedef enum
{
    MMI_UM_UI_ENTRY_NONE,
    MMI_UM_UI_ENTRY_KEY_CSK, 
    MMI_UM_UI_ENTRY_KEY_LSK, 
    MMI_UM_UI_ENTRY_INTUITIVE_CMD, 
    MMI_UM_UI_ENTRY_TOTAL
} mmi_um_ui_entry_msg_action_enum;

typedef enum
{
    MMI_UM_UI_BLOCK_SLIDE_SHOW = 0x01    /* close slide show */
} mmi_um_ui_scrn_effect_enum;

typedef enum
{
    MMI_UM_FOLDER_MODE_DEFAULT = 0, 
    MMI_UM_FOLDER_MODE_CONVERSATION_BOX, 
    MMI_UM_FOLDER_MODE_THREAD_MSG, 
    MMI_UM_FOLDER_MODE_TOTAL
} mmi_um_ui_folder_mode_enum;

typedef enum
{
    MMI_UM_UI_TB_FOLDER_INBOX = 0, 
    MMI_UM_UI_TB_FOLDER_DRAFT, 
    MMI_UM_UI_TB_FOLDER_UNSENT, 
    MMI_UM_UI_TB_FOLDER_SENT, 
    MMI_UM_UI_TB_FOLDER_ARCHIVE, 
    MMI_UM_UI_TB_FOLDER_SIM, 
    MMI_UM_UI_TB_FOLDER_CONVERSATION, 
    MMI_UM_UI_TB_FOLDER_THREAD_MSG, 
    MMI_UM_UI_TB_FOLDER_REPORT, 
    MMI_UM_UI_TB_FOLDER_TOTAL
} mmi_um_ui_tb_action_folder_enum;

typedef enum
{
    MMI_UM_UI_TB_ACTION_NONE = 0,
    MMI_UM_UI_TB_ACTION_REPLY,
    MMI_UM_UI_TB_ACTION_FORWARD,
    MMI_UM_UI_TB_ACTION_SEND,
    MMI_UM_UI_TB_ACTION_RESEND,
    MMI_UM_UI_TB_ACTION_EDIT,
    MMI_UM_UI_TB_ACTION_DELETE,
    MMI_UM_UI_TB_ACTION_COPY,
    MMI_UM_UI_TB_ACTION_MOVE,
    MMI_UM_UI_TB_ACTION_TOTAL
} mmi_um_ui_tb_action_enum;

typedef enum
{
    MMI_UM_UI_SH_CF_NONE, 
    MMI_UM_UI_SH_CF_FOLDER_SEND_KEY, 
    MMI_UM_UI_SH_CF_FOLDER_OPT_DEL_ALL, 
    MMI_UM_UI_SH_CF_MS_DELETE, 
    MMI_UM_UI_SH_CF_MS_MOV2ARC, 
    MMI_UM_UI_SH_CF_MS_MOV2SIM, 
    MMI_UM_UI_SH_CF_MS_MOV2PHONE, 
    MMI_UM_UI_SH_CF_MS_CPY2SIM, 
    MMI_UM_UI_SH_CF_MS_CPY2PHONE, 
    MMI_UM_UI_SH_CF_DELETE_FOLDER, 
    MMI_UM_UI_SH_CF_CS_SEND_KEY, 
    MMI_UM_UI_SH_CF_CS_TB_DELETE, 
    MMI_UM_UI_SH_CF_CS_OPT_DELETE, 
    MMI_UM_UI_SH_CF_CS_OPT_DEL_ALL, 
    MMI_UM_UI_SH_CF_CS_OPT_MOV2ARC, 
    MMI_UM_UI_SH_CF_MS_CS_OPT_DELETE, 
    MMI_UM_UI_SH_CF_MS_CS_OPT_MOV2ARC, 
    MMI_UM_UI_SH_CF_TOTAL
} mmi_um_ui_sh_confirm_action_enum;
#endif /* __UM_SUPPORT__ */
#endif /* __UMDEFS_H__ */
