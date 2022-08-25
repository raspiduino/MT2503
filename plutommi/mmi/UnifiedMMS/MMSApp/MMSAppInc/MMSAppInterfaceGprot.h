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
 * MMSAppInterfaceGProt.h
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
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_INTERFACE_GPROT_H
#define MMS_APP_INTERFACE_GPROT_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MsgViewerCuiGProt.h"
#include "UMGProt.h"
#ifdef __MMI_MMS_POSTCARD__
#include "FileManagerGprot.h"
#endif 
#include "MMIDataType.h"
#include "FileMgrType.h"
#include "kal_general_types.h"

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#define mmi_umms_app_cntrlr_screen_render_start(U16) mmi_umms_app_if_dummy_controller(U16)
#define mmi_umms_app_resource_get_screenDB(U16) mmi_umms_app_if_dummy_screen_db()
extern void mmi_umms_app_if_dummy_controller(U16 scr_id);
extern void mmi_umms_app_if_dummy_reset_data(void);
extern void mmi_umms_app_if_start_composer_from_cui(mmi_id parent_id);
extern void cui_uc_write_msg_launch(mmi_id parent_grp_id);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

/* This enum is used to identify which kind of operation is being performed on MMS i.e. Open option or open View or Preview etc */
typedef enum
{
    MMI_UMMS_OPEN_MMS_OPTION,               /* Open mms option */
    MMI_UMMS_OPEN_MMS_VIEWER,               /* Open mms Viewer */
#ifdef __MMI_MMS_POSTCARD__
    MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD,   /* Open preview postcard */
#endif 
    MMI_UMMS_OPEN_MMS_PREVIEWER_MMS         /* Open preview mms */
} mmi_umms_app_if_action_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER void *msg_data;
} mmi_umms_entry_event_struct;

/* This enum is used to identify key operation performed combined with mms compile options MMS */
typedef enum
{
    CSK_LIST_OPTION_ON,     /* List Option On CSK Press */
    CSK_LIST_OPTION_OFF,    /* List Option On LSK press */
    CSK_OK_OPTION_ON,
    CSK_OK_OPTION_OFF,
    CSK_OPTION_ALL
} mmi_umms_list_csk_option;

#ifdef __MMI_OP12_TOOLBAR__

/* This enum is used in mms toolbar feature from idle screen to identify current toolbar state */
typedef enum
{
    UMMS_TB_STATE_NONE,     /* invalid state */
    UMMS_TB_STATE_VIEW,     /* view mms from toolbar */
    UMMS_TB_STATE_DELETE,   /* delete mms from toolbar */
    UMMS_TB_STATE_CALL,     /* call sender from toolbar */
    UMMS_TB_STATE_TOTAL
} mmi_umms_tb_state;
#endif /* __MMI_OP12_TOOLBAR__ */ 

#if (MMI_MAX_SIM_NUM >= 3)
/* This enum is used in SIM selector CUI */
typedef enum
{
    UMMS_ACTION_NONE,
    UMMS_ACTION_DOWNLOAD,
    UMMS_ACTION_RESEND,
    UMMS_ACTION_TOTAL
} mmi_umms_action_type;
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 

/* This structure is used to laucnh mms from anywhere in the mmi, with these basic fileds mms can be started */
typedef struct
{
    mmi_umms_app_if_action_enum action; /* type of action on mms */
    MMI_BOOL is_iterting;               /* wheather in iterator mode */
    U16 msg_box_type;                   /* msg_box of selected mms */
    U32 msg_id;                         /* msg_id of selected mms */
    void *um_data;                      /* UM screen data used in iterator view */
    mmi_id parent_grp_id;               /* caller app grp id */
} mmi_umms_app_start_struct;

#if (MMI_MAX_SIM_NUM >= 3)
typedef struct
{
    mmi_umms_action_type msg_action;
} mmi_umms_action_type_struct;
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_message_settings_menu
 * DESCRIPTION
 *  This interface is used to launch MMS Settings UI
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_message_settings_menu(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_template_menu
 * DESCRIPTION
 *  This interface is used to launch MMS templates UI from Unified Message
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_template_menu(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_screen
 * DESCRIPTION
 *  This interface is used to show mms screen either option or viewer.Currently 
 *   being used internally
 * PARAMETERS
 *  void *data [input]
 *   This data contains msg_id , msg_box, parent_group_id and some flags 
 *   required to start mms
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_screen(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_screen_no_reset
 * DESCRIPTION
 *  This interface is used to show mms screen either mms option or mms viewer 
 *   from home screen UI.Currently being used internally
 * PARAMETERS
 *  data : [IN] 
 *  This data contains msg_id , msg_box, parent_group_id and some flags 
 *   required to start mms    
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_screen_no_reset(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_option_screen
 * DESCRIPTION
 *  This interface is used to show mms option screen 
 *   Currently being used internally.
 * PARAMETERS
 *  data : [IN] 
 *   This data contains msg_id , msg_box, parent_group_id and some flags 
 *   required to draw mms option screen   
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_option_screen(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_view_screen
 * DESCRIPTION
 *  This interface is used to show mms viewer screen 
 *   Currently being used internally.
 * PARAMETERS
 *  data : [IN] 
 *   This data contains msg_id , msg_box, parent_group_id and some flags 
 *   required to view a highlighted MMS   
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_view_screen(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_preview_screen
 * DESCRIPTION
 *  This interface is used to show mms preview screen from MMS Composer 
 *   Currently being used internally.
 * PARAMETERS
 *  data : [IN] 
 *   This data contains msg_id , msg_box, parent_group_id and some flags 
 *   required to view a highlighted MMS     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_preview_screen(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_notification(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_java_mms_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_java_mms_notification(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_full_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_full_popup(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_stop_app_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_stop_app_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_stop_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_stop_viewer_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_properties_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_mms_properties_screen(void);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_pref_storage_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_pref_storage_option(void);

#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_msg_filter_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_msg_filter_option(void);

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_memory_status_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_memory_status_menu(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_phone_memory_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_phone_memory_status_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_card_memory_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_card_memory_status_screen(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  srv_mms_de_init_uri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mms_de_init_uri(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mms_sd_card_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mms_sd_card_plug_in_hdlr(U8);

/*****************************************************************************
 * FUNCTION
 *  srv_mms_sd_card_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mms_sd_card_plug_out_hdlr(U8);

/*****************************************************************************
 * FUNCTION
 *  srv_mms_drv_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mms_drv_format_hdlr(void);

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_delivery_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_delivery_status(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_read_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_show_read_status(void);
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_option_screen_present
 * DESCRIPTION
 *  Used to make sure option screen is not present to avoid re-entry
 * PARAMETERS
 *  void    
 * RETURNS
 *  TRUE[if option screen ie: inbox, draft etc. option screen is present]
 *  FALSE[o/w]
 *****************************************************************************/
extern MMI_BOOL mmi_umms_app_if_is_option_screen_present(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_mms_in_open_state
 * DESCRIPTION
 *  Used to make sure option screen for msg_id passed as parameter
 *   is not present to avoid any operation(ie: send etc.). 
 * PARAMETERS
 *  msg_id : [IN]  msg_id of the queried mms    
 * RETURNS
 *  TRUE[if option of same mms is openned]
 *  FALSE[O/W]
 *****************************************************************************/
extern mmi_ret mmi_umms_app_if_is_mms_in_open_state(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_viewer_in_history
 * DESCRIPTION
 *  Used to make sure any mms is not being currently viewer to avoid re-entry 
 * PARAMETERS
 *  void  
 * RETURNS
 *  TRUE[if currently viewer is openned]
 *  FALSE[O/W]
 *****************************************************************************/
extern BOOL mmi_umms_app_if_is_viewer_in_history(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_msg_in_view
 * DESCRIPTION
 *  Used to make sure mms of msg_id passed as parameter
 *   is not being currently viewer to avoid re-entry 
 * PARAMETERS
 *  msg_id : [IN]  msg_id of the queried mms     
 * RETURNS
 *  TRUE[if msg_id is same as current viewer context msg_id]
 *  FALSE[O/W]
 *****************************************************************************/
extern mmi_ret mmi_umms_app_if_msg_in_view(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_uc_request_to_deinit
 * DESCRIPTION
 *  Special interface to Unified Composer 
 *   for closing mms viewer from UC preview
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_uc_request_to_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_uc_preview_msg
 * DESCRIPTION
 *  This interface is used to preview mms from Unified Composer
 * PARAMETERS
 *  msg_id : [IN]  
 *  msg_type : [IN] msg_type of mms(i.e. MMS Postcard or normal MMS)
 *  sim_id : [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_uc_preview_msg(U32, U8, U8);

/*****************************************************************************
 * FUNCTION
 *  cui_umms_app_set_uc_preview_msg
 * DESCRIPTION
 *  This interface is new cui interface to set preview mms data 
 *   from Unified Composer before launching mms preview cui
 * PARAMETERS
 *  msg_id : [IN]  
 *  msg_type : [IN] msg_type of mms(i.e. MMS Postcard or normal MMS)
 *  sim_id : [IN]   
 * RETURNS
 *  void *data will be used by UC later to launch mms preview
 *****************************************************************************/
extern void *cui_umms_app_set_uc_preview_msg(U32, U8, U8);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_interface_entry_from_um
 * DESCRIPTION
 *  This interface is used to start mms application from anywhere in MMI,
 *  thourgh mmsadp
 * PARAMETERS
 *  msg_id : [IN]  
 *  msg_type : [IN] msg_type of mms(i.e. MMS Postcard or normal MMS)
 *  sim_id : [IN] 
 *  mmi_id parent_grp_id[input] grp id of calling app
 * RETURNS
 *  [TRUE]
 *****************************************************************************/
extern MMI_BOOL mmi_umms_app_interface_entry_from_um(U16, U32, void *, mmi_id);

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_clear_recent_event
 * DESCRIPTION
 *  This interface is used to delete whole recent event list, maintained 
 *   by MMS Core
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_hs_clear_recent_event(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_recent_mms
 * DESCRIPTION
 *  This interface is used to get recent mms 
 *   upto count mentioned in parameter num
 * PARAMETERS
 *  num : [IN] number of recent mms required  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_hs_get_recent_mms(S32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_mms_unread_count
 * DESCRIPTION
 *  This interface is used to get total number of unread mms for home screen
 *  this api updates data and calls home screen API with updated info
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_hs_get_mms_unread_count(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_new_mms_data
 * DESCRIPTION
 *  This interface is used to get unread mms list mentioned in parameted num
 *   for home screen. API calls home screen API with updated info.
 * PARAMETERS
 *  num : [IN]  number of unread msg     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_hs_get_new_mms_data(S32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_mms_softnote
 * DESCRIPTION
 *  This interface is used to get new mms count and update home screen
 *   calling home screen API with updated info,also provide home screen new 
 *   mms tone and callback for key handling on new msg popup
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_hs_get_mms_softnote(void);
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP12_TOOLBAR__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_evnt_query_mms
 * DESCRIPTION
 *  This interface is used to get toolbar mms 
 *   upto count mentioned in parameter num
 * PARAMETERS
 *  num : [IN]  number of mms required by toolbar  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_op_tb_evnt_query_mms(S32);

#endif /* __MMI_OP12_TOOLBAR__ */ 

#ifdef __MMI_MMS_POSTCARD__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_check_mms_insert_postcard
 * DESCRIPTION
 *  check wheather any image can be added in a postcard or not
 * PARAMETERS
 *  file_type : [IN] 
 *  file_path : [IN] 
 * RETURNS
 *  [TRUE] if picture can be inserted
 *  [FALSE]O/W
 *****************************************************************************/
extern MMI_BOOL mmi_umms_app_if_check_mms_insert_postcard(mmi_fmgr_filetype_enum, char *);
#endif /* __MMI_MMS_POSTCARD__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_update_recent_event_list_from_phone_suit
 * DESCRIPTION
 *  Interface is used to update recent event list when background upload or 
 *   delete any mmsfrom phonesuit
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sd_card_plug_out_hdlr_cb
 * DESCRIPTION
 *  To handle sd card plug out event on UMMS
 * PARAMETERS
 *  param : [IN]   
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_sd_card_plug_out_hdlr_cb(mmi_event_struct *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sd_card_plug_in_hdlr_cb
 * DESCRIPTION
 *  To handle sd card plug in event on UMMS
 * PARAMETERS
 *  param : [IN]       
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_sd_card_plug_in_hdlr_cb(mmi_event_struct *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_drv_format_hdlr_cb
 * DESCRIPTION
 *  To handle drive format event on UMMS
 * PARAMETERS
 *  param : [IN]     
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_drv_format_hdlr_cb(mmi_event_struct *);

#ifdef __MMI_FTE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_reply_mms
 * DESCRIPTION
 *  To reply mms sender through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_reply_mms(mmi_id, U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_forward_mms
 * DESCRIPTION
 *  To forward mms through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_forward_mms(mmi_id, U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_edit_mms
 * DESCRIPTION
 *  To edit mms through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_edit_mms(mmi_id, U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_send_mms
 * DESCRIPTION
 *  To send mms through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]          
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_send_mms(mmi_id, U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_resend_mms
 * DESCRIPTION
 *  To resend mms through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_resend_mms(mmi_id, U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_delete_mms
 * DESCRIPTION
 *  To delete mms through toolbar given on UM list
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 *  msg_id : [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_delete_mms(mmi_id, U32);
#endif /* __MMI_FTE_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_create
 * DESCRIPTION
 *  Interface to create mms preview cui
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app
 * RETURNS
 *  mmi_id group if of created CUi group
 *****************************************************************************/
extern mmi_id cui_umms_preview_mms_create(mmi_id);

/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_run
 * DESCRIPTION
 *  Interface to start mms preview cui
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app
 *  msg  : [IN] mms data   
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_umms_preview_mms_run(mmi_id, void *);

/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_close
 * DESCRIPTION
 *  Interface to close mms preview cui
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app   
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_umms_preview_mms_close(mmi_id);

/*****************************************************************************
 * FUNCTION
 *  cui_umms_mms_templates_launch
 * DESCRIPTION
 *  Interface cui to launch mms templates
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app        
 * RETURNS
 *  mmi_id group if of created CUi group
 *****************************************************************************/
extern mmi_id cui_umms_mms_templates_launch(mmi_id);

/*****************************************************************************
 * FUNCTION
 *  cui_umms_mms_settings_launch
 * DESCRIPTION
 *  Interface cui to launch mms settings
 * PARAMETERS
 *  parent_id : [IN] grp id of caller app 
 * RETURNS
 *  mmi_id group if of created CUi group
 *****************************************************************************/
extern mmi_id cui_umms_mms_settings_launch(mmi_id);

/*****************************************************************************
 * FUNCTION
 *  umms_cb_hdlr
 * DESCRIPTION
 *  this is a callback functions given to UM for sending cui events to UMMS
 * PARAMETERS
 *  evt : [IN] event data
 *  para : [IN] UM data(parent id, msg_id etc.)   
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret umms_cb_hdlr(mmi_event_struct *, mmi_um_opt_para_struct *);

/*****************************************************************************
 * FUNCTION
 *  umms_menu_query_function
 * DESCRIPTION
 *  Interface to get parent menu id of umms option screen
 * PARAMETERS
 *  msg_id : [IN] 
 * RETURNS
 *  menu_id of umms  
 *****************************************************************************/
extern mmi_menu_id umms_menu_query_function(U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_start_viewer
 * DESCRIPTION
 *  Interface to start mms viewer in iterator mode or normal mode from Shellapp
 * PARAMETERS
 *  parent_grp_id : [IN] grp id of caller app   
 *  msg_id : [IN] 
 *  user_data : [IN] um screen data 
 *  type : [IN] type of view(iterator or normal) 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_start_viewer(U16, U32, void *, cui_msg_viewer_type_enum);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mma_insuf_mem
 * DESCRIPTION
 *  to handle insufficient memory situation
 * PARAMETERS
 *  param : [IN]  
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_app_core_mma_insuf_mem(mmi_event_struct *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_get_um_box_type_from_msg_id
 * DESCRIPTION
 *  to get msg_box for msg_id 
 * PARAMETERS
 *  msg_id : [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mms_deinit
 * DESCRIPTION
 *  to handle deinit mms application
 * PARAMETERS
 *  param : [IN]  
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_app_core_mms_deinit(mmi_event_struct *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_idle_hdlr
 * DESCRIPTION
 * to handle mms application variables on idle screen
 * PARAMETERS
 *  param : [IN] 
 * RETURNS
 *  [MMI_RET_OK] if successful handling
 *  [MMI_RET_ERROR] O/W
 *****************************************************************************/
extern mmi_ret mmi_umms_app_core_idle_hdlr(mmi_event_struct *);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_deinit_viewer
 * DESCRIPTION
 * to deinit mms viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_if_deinit_viewer(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_show_status_icon_by_id
 * DESCRIPTION
 *  To show a icon in the status bar
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_show_status_icon_by_id(S32 icon_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_hide_status_icon_by_id
 * DESCRIPTION
 *  To hide a icon in the status bar
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_hide_status_icon_by_id(S32 icon_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_blink_status_icon_by_id
 * DESCRIPTION
 *  To blink a icon in the status bar
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_umms_app_blink_status_icon_by_id(S32 icon_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_if_cui_launch_from_widjet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_umms_if_cui_launch_from_widjet(U32 msg_id ,cui_msg_viewer_type_enum view_type);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern void mmi_umms_app_if_show_option_screen_slim(void);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_INTERFACE_GPROT_H */ 

