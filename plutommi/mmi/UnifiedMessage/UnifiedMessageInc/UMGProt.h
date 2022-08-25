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
 * UMGprot.h
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
#ifndef UM_GPROT_H
#define UM_GPROT_H
#include "MMI_features.h"

#ifdef __UM_SUPPORT__
#include "MsgViewerCuiGProt.h"
#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "IdleNotificationManagerGprot.h"
#if !defined(__IOT__)
#include "mmi_rp_app_unifiedmessage_def.h"
#endif
#include "NotificationGprot.h"

extern MMI_ID g_um_general_folder_scrn_id;
extern MMI_ID g_um_loading_scrn_id;

typedef void (*mmi_um_iterator_viewer_cb) (void *user_data);
typedef struct
{
    U32 msg_id;                                     /* query message id */
    srv_um_msg_enum msg_type;                       /* query message type */
    mmi_um_iterator_viewer_cb func_cb;              /* message callback for fail case */
    void *user_data;                                /* message's user data */
} mmi_um_iter_viewer_info_struct;

typedef struct
{
    U16 index_number;                               /* The indexing number */
    U16 total_number;                               /* The total number */
    U32 prev_msg_id;                                /* Previous message id */
    U32 next_msg_id;                                /* Next message id */
    srv_um_msg_enum prev_msg_type;                  /* Previous message type */
    srv_um_msg_enum next_msg_type;                  /* Next message type */
    cui_msg_viewer_launch_ptr prev_launch_func_ptr; /* Prevous launch function of message viewer */
    cui_msg_viewer_launch_ptr next_launch_func_ptr; /* Next launch function of message viewer */
} mmi_um_iter_viewer_result_struct;

typedef struct
{
    U16 key_code;           /* MMI_UM_UI_ENTRY_KEY_CSK, MMI_UM_UI_ENTRY_INTUITIVE_CMD */
    MMI_ID parent_grp_id;   /* UM's group */
    U32 msg_id;             /* Selected message id */
    void *user_data;        /* UM's user_data for iterator viewer */
} mmi_um_entry_msg_struct;

typedef struct
{
    U32 msg_id;             /* Selected message id */
    MMI_ID parent_grp_id;   /* UM's group */
    MMI_BOOL display_flag;  /* Display flag of application */
    void *user_data;        /* UM's user data */
} mmi_um_opt_para_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_um_msg_enum msg_type;       /* Refresh message type */
    srv_um_msg_box_enum msg_box;    /* Refresh message box */
} mmi_um_refresh_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL is_entry;              /* MMI_TRUE: entry, MMI_FALSE: exit */
    void *um_user_data;             /* UM's user data */
} mmi_um_entry_main_msg_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL is_entry;              /* MMI_TRUE: entry, MMI_FALSE: exit */
    srv_um_msg_box_enum msg_box;    /* Entry box type */
    void *um_user_data;             /* UM's user data */
} mmi_um_entry_folder_evt_struct;

typedef enum
{
    MMI_UM_TAB_PAGE_BT,
    MMI_UM_TAB_PAGE_BT2,
    MMI_UM_TAB_PAGE_LOCAL
}mmi_um_tab_page;

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_new_msg
 * DESCRIPTION
 *  check if new msg arrives
 * PARAMETERS
 *  void
 * RETURNS
 *  The bitwise of new message
 * RETURN VALUES
 *	SMS:    0x01
 *	MMS:    0x02
 *	Push:   0x04
 *****************************************************************************/
extern kal_uint8 mmi_um_check_new_msg(void);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_main_message_menu
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
extern void mmi_um_entry_main_message_menu(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_main_message_menu_with_check
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
extern void mmi_um_entry_main_message_menu_with_check(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_main_message_menu_update_by_app
 * DESCRIPTION
 *  Message ap could call this funciton to update the main menu screen by 
 *  menu item id and the updated string.
 * PARAMETERS
 *  user_data:          [IN]    The UM's user data, get from event's user data
 *  menu_item_id:       [IN]    Menu item id
 *  update_string:      [IN]    Updated string
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_main_message_menu_update_by_app(void *user_data, U16 menu_item_id, U8 *update_string);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  pre-entry simbox list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_pre_entry_simbox(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
/* DOM-NOT_FOR_SDK-BEGIN */
struct mmi_nmgr_answer_struct_s;

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_query_data
 * DESCRIPTION
 *  For Notification management used.
 *      When Notification manager wants the data from UM, it will call this 
 *      function to gather information.
 *
 * PARAMETERS
 *  answer:             [OUT]   The information for notification manager
 *
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_nmgr_query_data(struct mmi_nmgr_answer_struct_s *answer);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_new_msg_cancel
 * DESCRIPTION
 *  If user see some message type, it should inform UM to cancel this message
 *  type
 * PARAMETERS
 *  msg_type:           [IN]    UM message type
 *
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_nmgr_new_msg_cancel(srv_um_msg_enum msg_type);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_lsk_handler
 * DESCRIPTION
 *  For Notification management used.
 *      To register LSK function for notification manager in IDLE screen.
 * PARAMETERS
 *  data:               [IN]    for extension used
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_nmgr_lsk_handler(void *data);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_new_msg_notify_cancel_sms
 * DESCRIPTION
 *  Cancel new MMS message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_new_msg_notify_cancel_sms(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_new_msg_notify_cancel_mms
 * DESCRIPTION
 *  Cancel new MMS message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_new_msg_notify_cancel_mms(void);
#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_query_report_message
 * DESCRIPTION
 *  For Notification management used.
 *      When Notification manager wants the data from UM, it will call this 
 *      function to gather information. Thie funciton is used to query report
 *      message
 *
 * PARAMETERS
 *  answer:             [OUT]   The information for notification manager
 *
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_nmgr_query_report_message(struct mmi_nmgr_answer_struct_s *answer);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_nmgr_report_lsk_handler
 * DESCRIPTION
 *  For Notification management used.
 *      To register LSK function for notification manager in IDLE screen.
 * PARAMETERS
 *  data:               [IN]    for extension used
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_nmgr_report_lsk_handler(void *data);
#endif /* __MMI_UM_REPORT_BOX__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_current_msg_box_type
 * DESCRIPTION
 *  Get the type of current msg box
 * PARAMETERS
 *  void
 * RETURNS
 *  The current UM message box type
 * RETURN VALUES
 *  Inbox:      0x01
 *  Draft:      0x02
 *  Outbox:     0x04
 *  Sent:       0x08
 *  Archive:    0x10
 *  Simbox:     0x80
 *****************************************************************************/
extern srv_um_msg_box_enum mmi_um_get_current_msg_box_type(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_hide_main_message_all_folder_menu_id
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
extern void mmi_um_hide_main_message_all_folder_menu_id(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_unhide_main_message_all_folder_menu_id
 * DESCRIPTION
 *      unhide all folder menu id.
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
extern void mmi_um_unhide_main_message_all_folder_menu_id(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_not_available_string_id
 * DESCRIPTION
 *  Get string ID for not available case
 * PARAMETERS
 *  void
 * RETURNS
 *  UM not available string ID
 * RETURN VALUES
 *  String ID of unavaliable
 *****************************************************************************/
extern kal_uint16 mmi_um_get_not_available_string_id(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_is_available
 * DESCRIPTION
 *  Check if unified message is available. It will check SMS/MMS/Push if
 *  avaliable.
 * PARAMETERS
 *  void
 * RETURNS
 *  The UM available status
 * RETURN VALUES
 *	MMI_TRUE:   UM is available to entry
 *  MMI_FALSE:  UM isnot avaliable to entry due to some reasons
 *****************************************************************************/
extern kal_bool mmi_um_is_available(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_init
 * DESCRIPTION
 *  Initialize Unified Message application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_init(void);


extern void mmi_um_ui_sh_main_msg_entry_inbox(void);
extern void mmi_um_ui_sh_main_msg_entry_draft(void);
extern void mmi_um_ui_sh_main_msg_entry_outbox(void);
extern void mmi_um_ui_sh_main_msg_entry_sent(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_msg_ind
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
extern void mmi_um_highlight_msg_ind(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type, kal_uint32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_write_msg
 * DESCRIPTION
 *  Entry write message selection screen for sms/mms editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_write_msg(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_write_msg_ext
 * DESCRIPTION
 *  Entry write message selection screen including sms/mms/uc/postcard editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_write_msg_ext(void);
#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_conversation
 * DESCRIPTION
 *  Entry conversation box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_conversation(void);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_inbox
 * DESCRIPTION
 *  Entry inbox folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_inbox(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_inbox_with_check
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
extern void mmi_um_entry_inbox_with_check(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_draft
 * DESCRIPTION
 *  Entry draft folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_draft(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_outbox
 * DESCRIPTION
 *  Entry outbox folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_outbox(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_sent
 * DESCRIPTION
 *  Entry sent box folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_sent(void);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_archive
 * DESCRIPTION
 *  Entry archive folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_archive(void);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_simbox
 * DESCRIPTION
 *  Entry simbox folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_simbox(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_simbox_with_check
 * DESCRIPTION
 *  Entry simbox folder and destroy UM instance if it exists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_simbox_with_check(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_report
 * DESCRIPTION
 *  Entry report folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_report(void);
#endif /* __MMI_UM_REPORT_BOX__ */

#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_delete_folder
 * DESCRIPTION
 *  Entry delete messages screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_delete_folder(void);
#endif

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_template
 * DESCRIPTION
 *  Entry template selection screen for sms/mms templates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_template(void);
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_setting
 * DESCRIPTION
 *  Entry setting selection screen for sms/mms settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_setting(void);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_inbox
 * DESCRIPTION
 *  Entry mark several inbox folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_inbox(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_draft
 * DESCRIPTION
 *  Entry mark several draft folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_draft(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_outbox
 * DESCRIPTION
 *  Entry mark several outbox folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_outbox(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_sent
 * DESCRIPTION
 *  Entry mark several sent box folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_sent(void);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_archive
 * DESCRIPTION
 *  Entry mark several archive box folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_archive(void);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_ms_simbox
 * DESCRIPTION
 *  Entry mark several sim box folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_entry_ms_simbox(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  Entry inbox folder. (old API)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_pre_entry_inbox(void);
#if defined(__MMI_OP12_TOOLBAR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_sms_inbox
 * DESCRIPTION
 *  Entry inbox folder with SMS only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_pre_entry_sms_inbox(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_mms_inbox
 * DESCRIPTION
 *  Entry inbox folder with MMS only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_pre_entry_mms_inbox(void);
#endif /*__MMI_OP12_TOOLBAR__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_um_launch_inbox_with_sms_only
 * DESCRIPTION
 *  Launch inbox with SMS only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_launch_inbox_with_sms_only(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_launch_inbox_with_mms_only
 * DESCRIPTION
 *  Launch inbox with MMS only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_launch_inbox_with_mms_only(void);
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_message_list_sort_type
 * DESCRIPTION
 *  Set the message list sorting type.
 * PARAMETERS
 *  index           [IN]: Selected index
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_um_set_message_list_sort_type(kal_uint16 index);
/*****************************************************************************
 * FUNCTION
 *  mmi_um_prepare_sort_selection_list
 * DESCRIPTION
 *  Prepare the string id of the sorting screen
 * PARAMETERS
 *  menu_item_str_id            [IN]: Selected index
 *  max_menu_item               [IN]: The maximum items of above buffer.
 * RETURNS
 *  The number of menu items.
 * RETURN VALUES
 *  The number of menu items.
 *****************************************************************************/
extern kal_uint16 mmi_um_prepare_sort_selection_list(kal_uint16 *menu_item_str_id, kal_uint16 max_menu_item);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_query_indexing
 * DESCRIPTION
 *  Query the current indexing information for specified message id.
 *  If UM could return the result immediately, UM will fill up the result
 *  variable and return MMI_TRUE.
 *  If UM could not return the result immediately, UM will return MMI_FALSE
 *  and call your callback while the result finished. Once your callback is
 *  executed, you should call mmi_um_query_indexing again to get the data.
 *  Note. You should only display a loading screen while launch your viewer.
 *
 * PARAMETERS
 *  info                [IN]: The query information including message id, 
 *                            callback function and your user data
 *  result              [OUT]: The output file of the query result
 *  user_data           [IN]: UM's user data. You should keep the user data
 *                            while UM call launch your screen like option
 *                            screen or viewer screen.
 *
 * RETURNS
 *  UM could return the data immediately or not.
 *
 * RETURN VALUES
 *  MMI_TRUE: UM fill the result variable.
 *  MMI_FALSE: UM has no data and feedback you to display a loading or other
 *             waiting screen.
 *****************************************************************************/
extern MMI_BOOL mmi_um_query_indexing(mmi_um_iter_viewer_info_struct *info, 
                                      mmi_um_iter_viewer_result_struct *result, 
                                      void *user_data);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_conversation_box_setting
 * DESCRIPTION
 *  Checking the conversation box setting. If it turns on the conversation
 *  box, it will return MMI_TRUE. Else, it will return MMI_FALSE
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  The conversation box setting status
 *
 * RETURN VALUES
 *  MMI_TRUE: Conversation box turns on.
 *  MMI_FALSE: Conversation box turns off.
 *****************************************************************************/
MMI_BOOL mmi_um_check_conversation_box_setting(void);
#endif /* __MMI_UM_CONVERSATION_BOX__ */

#ifdef __MMI_APP_MANAGER_SUPPORT__
mmi_ret mmi_um_package_proc(mmi_event_struct *evt);
#endif /* mmi_um_package_proc */

extern void mmi_um_alert_um_inbox_alert(mmi_frm_nmgr_alert_struct *alert);
extern void mmi_um_alert_um_outbox_alert(mmi_frm_nmgr_alert_struct *alert);

#ifndef __MMI_SUPPORT_ASMV2__
extern void mmi_um_ui_app_mem_stop_callback(void);
#endif

#endif /* __UM_SUPPORT__ */
#endif /* UM_GPROT_H */
