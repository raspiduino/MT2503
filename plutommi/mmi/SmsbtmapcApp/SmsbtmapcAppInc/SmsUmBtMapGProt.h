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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_MAP_CLIENT__

#ifndef SMS_UM_BT_MAP_GPROT_H
#define SMS_UM_BT_MAP_GPROT_H
#include "MsgViewerCuiGProt.h"
#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "IdleNotificationManagerGprot.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "NotificationGprot.h"
#include "SmsBtMapCSrvGProt.h"
//#include "UmSrvDef.h"
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
}sms_um_bt_get_msg_num_result;


//extern srv_um_check_msg_num(srv_um_sim_enum sim_id, srv_um_msg_enum msg_type, srv_um_get_msg_num_result *data);
extern void mmi_sms_um_bt_entry_main_message_menu(void);


typedef struct
{
    U16 key_code;           /* MMI_UM_UI_ENTRY_KEY_CSK, MMI_UM_UI_ENTRY_INTUITIVE_CMD */
    MMI_ID parent_grp_id;   /* UM's group */
    U32 msg_id;             /* Selected message id */
    void *user_data;        /* UM's user_data for iterator viewer */
} mmi_sms_um_entry_msg_struct;

typedef struct
{
    U32 msg_id;             /* Selected message id */
    MMI_ID parent_grp_id;   /* UM's group */
    MMI_BOOL display_flag;  /* Display flag of application */
    void *user_data;        /* UM's user data */
} mmi_sms_um_opt_para_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_um_msg_enum msg_type;       /* Refresh message type */
    srv_um_msg_box_enum msg_box;    /* Refresh message box */
} mmi_sms_um_refresh_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL is_entry;              /* MMI_TRUE: entry, MMI_FALSE: exit */
    void *um_user_data;             /* UM's user data */
} mmi_sms_um_entry_main_msg_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL is_entry;              /* MMI_TRUE: entry, MMI_FALSE: exit */
    srv_um_msg_box_enum msg_box;    /* Entry box type */
    void *um_user_data;             /* UM's user data */
} mmi_sms_um_entry_folder_evt_struct;

typedef enum
{
    SRV_UM_MSG_BTMAPC_BOX_NONE         = 0x00,    /* None */
    SRV_UM_MSG_BTMAPC_BOX_INBOX        = 0x01,    /* Inbox, listed all SMS received from network */
    SRV_UM_MSG_BTMAPC_BOX_OUTBOX       = 0x02,    /* Outbox, listed all SMS sent to network, (or to be sent to network if don't support Unsent list) */
    SRV_UM_MSG_BTMAPC_BOX_DRAFTS       = 0x04,    /* Drafts, listed all draft SMS */
    SRV_UM_MSG_BTMAPC_BOX_UNSENT       = 0x08,    /* Unsent, listed all SMS to be sent to network, and they have been sent failed once */
    SRV_UM_MSG_BTMAPC_BOX_DELETED      = 0x10,
    SRV_UM_MSG_BTMAPC_BOX_ALL = SRV_UM_MSG_BTMAPC_BOX_INBOX
                         | SRV_UM_MSG_BTMAPC_BOX_OUTBOX
                         | SRV_UM_MSG_BTMAPC_BOX_DRAFTS
                         | SRV_UM_MSG_BTMAPC_BOX_UNSENT,
   SRV_UM_MSG_BTMAPC_BOX_END = 0x0800
} srv_um_msg_btmapc_box_enum;

typedef enum
{
    MMI_SMS_BT_BOX_NONE = 0,
    MMI_SMS_BT_BOX_INBOX,
    MMI_SMS_BT_BOX_OUTBOX,
    MMI_SMS_BT_BOX_DRAFTS,
    MMI_SMS_BT_BOX_UNSENT,
    MMI_SMS_BT_BOX_DELETED,
    MMI_SMS_BT_BOX_ALL,
    MMI_SMS_BT_BOX_END
}mmi_sms_bt_box_enum;

typedef enum
{
    MMI_SMS_BT_ENTRY_WRITE_PORT = 0x0001,
    MMI_SMS_BT_ENTRY_WRITE_CLASS = 0x0002,
    MMI_SMS_BT_ENTRY_WRITE_REPLY = 0x0004,
#if defined ( __MMI_DUAL_SIM_MASTER__) && defined (__MMI_UNIFIED_COMPOSER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined ( __MMI_DUAL_SIM_MASTER__) && defined (__MMI_UNIFIED_COMPOSER__) */
    MMI_SMS_BT_ENTRY_WRITE_END
} mmi_sms_bt_write_msg_enum;

typedef enum
{
    MMI_SMS_BT_DEV0 = 0x01,
    MMI_SMS_BT_DEV1 = 0x02,
    MMI_SMS_BT_DEV_END_OF_ENUM
}mmi_sms_bt_dev_enum;


typedef struct
{
    U16 srcport;
    U16 desport;

    U16 stringlength;
    U8 dcs; //srv_sms_dcs_enum
    U8 dcs_class; //srv_sms_class_enum

    S8 *string;
    S8 *filename;
    U8 *ascii_addr; /* max number of digit is (MAX_DIGITS_SMS - 1). Must contain NULL terminator. */

    mmi_sms_bt_write_msg_enum flag;
} mmi_sms_bt_write_msg_para_struct;

typedef struct
{
    MMI_BOOL need_refresh[MMI_SMS_BT_BOX_END];
    MMI_BOOL mmi_need_update_list;
    MMI_BOOL mmi_need_keep_list;
    MMI_BOOL is_bt_connected;
    MMI_BOOL remote_not_support;
    MMI_BOOL need_show_connect;
    srv_sms_btmapc_box_enum last_entered;
    
    srv_sms_btmapc_box_enum curr_entered;
    SMS_HANDLE sms_handle;
    MMI_BOOL is_on_request;
    srv_sms_btmapc_bt_enum  bt_active_index;       /* Bt index ID */
}mmi_sms_bt_cntx_struct;

typedef struct
{
    kal_uint32 msg_id;                              /* message index */
    kal_uint32 timestamp;                           /* message timestamp array */
    srv_um_addr_enum address_type;
    kal_uint8 address_length;                       /* Number of characters in address string */
    kal_uint8 subject_length;                       /* Number of characters in subject string */
#ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    kal_uint8 address_number;
    kal_bool address_more;
#endif
    kal_wchar address[SRV_UM_MAX_ADDR_LEN + 1];     /* sender address for MT msg; receiver address for MO msg */
#ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    kal_wchar address_ext[SRV_UM_EXTEND_ADDRESS_NUM][SRV_UM_MAX_ADDR_LEN + 1];
#endif
    kal_wchar sender_name[SRV_BT_MAP_MAX_SENDER_NAME_LEN + 1];  /* subject for MMS, WAP Push and E-mai; part of content for SMS */

    kal_uint16 icon_id;
    kal_uint16 csk_icon_id;
    kal_uint32 msg_status;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_id_struct thread_id;              /* thread id */
#endif
} srv_um_bt_msg_info_struct;

/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_main_message_menu
 * DESCRIPTION
 *      Entry function for IDLE main message menu.
 *      If UM opens, UM needs to take charge of the main message menu.
 *      Else SMS will take care it.(EntryScrMessagesMenuList)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_sms_um_bt_entry_main_message_menu(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_main_message_menu_with_check
 * DESCRIPTION
 *      Entry function for re-entry case. It need to check each message app
 *      could be re-entry or not. If it could not re-entry, it will display 
 *      a error popup to end user.
 *      UM will also close the group if exist in history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_sms_um_entry_main_message_menu_with_check(void);


extern srv_um_msg_box_enum mmi_sms_um_get_current_msg_box_type(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_hide_main_message_all_folder_menu_id
 * DESCRIPTION
 *      hide all folder menu id.
 *      MENU_ID_UM_WRITE_MSG, MENU_ID_UM_INBOX, MENU_ID_UM_UNSENT,
 *      MENU_ID_UM_SENT, MENU_ID_UM_DRAFT, MENU_ID_UM_ARCHIVE,
 *      MENU_ID_UM_SIM, MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_TEMPLATE,
 *      MENU_ID_UM_SETTING
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_sms_um_hide_main_message_all_folder_menu_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_not_available_string_id
 * DESCRIPTION
 *  Get string ID for not available case
 * PARAMETERS
 *  void
 * RETURNS
 *  UM not available string ID
 * RETURN VALUES
 *  String ID of unavaliable
 *****************************************************************************/
extern kal_uint16 mmi_sms_um_get_not_available_string_id(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_highlight_msg_ind
 * DESCRIPTION
 *  set msg to be highlighted
 * PARAMETERS
 *  msg_type:           [IN]    Message type
 *  msg_box_type:       [IN]    Message box type
 *  msg_id:             [IN]    Message unique identify
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_sms_um_highlight_msg_ind(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type, kal_uint32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_write_msg
 * DESCRIPTION
 *  Entry write message selection screen for sms/mms editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_sms_um_entry_write_msg(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_write_msg
 * DESCRIPTION
 *  Entry write message selection screen for sms/mms editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern MMI_ID g_sms_um_ui_main_menu_scrn_id;

extern void mmi_sms_bt_app_init();
extern void mmi_sms_bt_app_set_cntx(void* cntx);
extern void mmi_sms_bt_write_msg_lanch(mmi_id parent_gid, mmi_sms_bt_write_msg_para_struct *para);
extern void mmi_sms_um_bt_ui_cc_deinit_grp_cntx(void);
extern MMI_BOOL mmi_sms_bt_map_is_connected(void);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_inbox(void);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_draft(void);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_outbox(void);
extern void mmi_sms_um_bt_ui_sh_main_msg_entry_sent(void);
#ifdef __MMI_APP_MANAGER_SUPPORT__
mmi_ret mmi_sms_um_package_proc(mmi_event_struct *evt);
#endif /* mmi_sms_um_package_proc */

//void mmi_sms_um_bt_entry_main_message_menu(void);
#endif
#endif

