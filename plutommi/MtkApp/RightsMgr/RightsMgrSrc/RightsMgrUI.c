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
 *  RightsMgrUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifdef __DRM_SUPPORT__
#ifdef __DRM_V02__

#include "MMI_include.h"
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "drm_def.h"
#include "drm_gprot.h"
#include "drm_msg.h"
#include "drm_ui.h"
#include "wgui_categories_inputs.h"/* INPUT_TYPE_USE_ONLY_ENGLISH_MODES */
#include "Conversions.h"
#include "wapadp.h"
#include "app_str.h"
#include "FileManagerGProt.h"
#include "CallManagementGprot.h"
#include "BrowserGprots.h"
#include "drm_trace.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
enum
{
    DRMT_INFO_NONE,
    DRMT_INFO_TEXT,
    DRMT_INFO_POPUP
};

typedef struct
{
    kal_uint16  session;
    kal_uint16  type;
    mmi_event_notify_enum event;
    kal_uint16  title;
    kal_uint16  category;
    kal_uint16  percentage;
    kal_int8    *msg;   /* coding in UCS2 */
} drmt_ui_context_struct;

static drmt_ui_context_struct drmt_ui_cntx;

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
/*****************************************************************************
 * Local Function
 *****************************************************************************/
void mmi_drm_entry_auth(void);
void mmi_drm_entry_pecentage_bar(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_ilm
 * DESCRIPTION
 *  send message
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *
 *****************************************************************************/
static void mmi_drm_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_WPS:
            sap_id = MMI_WAP_SAP;
            break;
        case MOD_DRMT:
            sap_id = DRMT_MMI_SAP;
            break;
        default:
            sap_id = INVALID_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = sap_id;

    msg_send_ext_queue(ilm_ptr);
}

#define DRMT_CLEAN_SCREEN
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_clean_screen
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_clean_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for ( i = SCR_ID_DRM_PROCESSING_START+1; i< SCR_ID_DRM_PROCESSING_END; i++)
    {
	    ClearDelScrnIDCallbackHandler(i, NULL);
        DeleteScreenIfPresent(i);
    }

    ClearDelScrnIDCallbackHandler(SCR_ID_DRM_GET_CONFIRM, NULL);
    DeleteScreenIfPresent(SCR_ID_DRM_GET_CONFIRM);

    i = mmi_frm_scrn_get_active_id();

    if (i > SCR_ID_DRM_PROCESSING_START && i < SCR_ID_DRM_PROCESSING_END )
    {
        mmi_frm_scrn_close_active_id();
    }
    else if (i == SCR_ID_DRM_GET_CONFIRM)
    {
        mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_clean_screen_ind
 * DESCRIPTION
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_recv_clean_screen_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_clean_screen_ind", (TRACE_GROUP_2, DRM_UI_5393CDEA59C3901674ED763A3B00D2F6));

    mmi_drm_clean_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_mids_abort_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 *  IN permission(?)
 *  IN execute(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* execute mmi_drm_progressing_del_cb when gobackhistory */
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_progressing_del_cb
 * DESCRIPTION
 *  try abort processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_drm_progressing_del_cb(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_async_cancel_current_process();

    return MMI_HIST_ALLOW_DELETING;
}

#define DRMT_AUTH

typedef enum
{
    DRMT_INLINE_USERNAME_CAPTION,
    DRMT_INLINE_USERNAME,
    DRMT_INLINE_PASSWORD_CAPTION,
    DRMT_INLINE_PASSWORD
} DRMT_auth_inline_item_enum;


static U8 DRMT_auth_username[ WPS_MAX_AUTH_USERNAME_LENGTH * ENCODING_LENGTH];
static U8 DRMT_auth_password[ WPS_MAX_AUTH_PASSWORD_LENGTH * ENCODING_LENGTH];

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_get_auth_cnf
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_send_get_auth_cnf(U8* username, U8* password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_auth_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_send_get_auth_cnf", (TRACE_GROUP_2, DRM_UI_133BA84F47C7DEF44ABB1752D567001E));

    msg = (drmt_get_auth_cnf_struct*) construct_local_para(sizeof(drmt_get_auth_cnf_struct), TD_RESET);

    if( username )
    {
        mmi_chset_ucs2_to_utf8_string( (kal_uint8*)msg->username, WPS_MAX_AUTH_USERNAME_LENGTH-1, username);
        msg->user_len = mmi_chset_utf8_strlen((kal_uint8*)msg->username);
    }

    if( password )
    {
        mmi_chset_ucs2_to_utf8_string( (kal_uint8*)msg->password, WPS_MAX_AUTH_PASSWORD_LENGTH-1, password);
        msg->pass_len = mmi_chset_utf8_strlen((kal_uint8*)msg->password);
    }

    mmi_drm_send_ilm(msg, NULL, MSG_ID_DRMT_GET_AUTH_CNF, MOD_DRMT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_yes_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO
    mmi_drm_send_get_auth_cnf(DRMT_auth_username, DRMT_auth_password);

    if( mmi_frm_scrn_get_active_id() == SCR_ID_DRM_AUTH )
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        GoBacknHistory(1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_endkey_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_drm_send_get_auth_cnf(NULL, NULL);
   // DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_cancel_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO
    mmi_drm_send_get_auth_cnf(NULL, NULL);

    if( mmi_frm_scrn_get_active_id() == SCR_ID_DRM_AUTH )
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        GoBacknHistory(1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_ucs2strlen((S8*)DRMT_auth_username) == 0)
    {
        mmi_popup_display((WCHAR*)L"Empty Username", MMI_EVENT_FAILURE, NULL);
        return;
    }
    else
    {

      {
		mmi_confirm_property_struct arg;
		mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
		arg.softkey[0].str = (WCHAR *)GetString(STR_GLOBAL_YES);
		arg.softkey[2].str = (WCHAR *)GetString(STR_GLOBAL_NO);
		arg.callback = (mmi_proc_func)mmi_rmgr_auth_conf_callback;
		mmi_confirm_display((WCHAR *)GetString(STR_GLOBAL_SEND), MMI_EVENT_QUERY, &arg);
      }
        /*mmi_display_popup_confirm(
                (UI_string_type)GetString(STR_GLOBAL_YES),
                (PU8)GetImage(IMG_GLOBAL_YES),
                (UI_string_type)GetString(STR_GLOBAL_NO),
                (PU8)GetImage(IMG_GLOBAL_NO),
                (UI_string_type)GetString(STR_GLOBAL_SEND),
                MMI_EVENT_QUERY);

        SetKeyHandler(mmi_drm_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_drm_auth_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_drm_auth_no_hdlr, KEY_EVENT_UP);*/
    }

}

mmi_ret mmi_rmgr_auth_conf_callback(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;
	
    if (alertEvt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alertEvt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_drm_auth_yes_hdlr();
        case MMI_ALERT_CNFM_NO:
            mmi_drm_auth_no_hdlr();
            break;
			/*END key case???*/
	  default:
	  	break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_open_full_screen_editor
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_open_full_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_auth_full_screen_editor_options
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_auth_full_screen_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
//    SetInputMethodAndDoneCaptionIcon(MAIN_MENU_TITLE_FUNANDGAMES_ICON);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_softkey_label_highlight_hdlr
 * DESCRIPTION
 *  Custom Highlight handler to change the label of LSK in case of inline edit screen.
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_softkey_label_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NumericKeys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(mmi_drm_auth_open_full_screen_editor, NumericKeys, 11, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    SetKeyHandler(mmi_drm_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_drm_auth_open_full_screen_editor, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_exit_auth
 * DESCRIPTION
 *  Exit function for authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_drm_exit_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_DRM_AUTH, mmi_drm_entry_auth);
}

/*************************************************************************
* FUNCTION
 *  mmi_drm_entry_auth
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
void mmi_drm_entry_auth(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    InlineItem authenticate_list[4];
    U16 IconsImageList[4];
     /*INLINE SCREEN*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_ID_DRM_AUTH, mmi_drm_exit_auth, NULL, NULL); */
    if (mmi_frm_scrn_enter(GRP_ID_RMGR_MAIN, SCR_ID_DRM_AUTH, mmi_drm_exit_auth, mmi_drm_entry_auth, MMI_FRM_FG_ONLY_SCRN))
    	{

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DRM_AUTH);

    InitializeCategory57Screen();
    memset(authenticate_list, 0, sizeof(authenticate_list));

    memset(DRMT_auth_username, 0, sizeof(DRMT_auth_username));
    memset(DRMT_auth_password, 0, sizeof(DRMT_auth_password));

    /* For username caption */
    SetInlineItemActivation(
        &authenticate_list[DRMT_INLINE_USERNAME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&authenticate_list[DRMT_INLINE_USERNAME_CAPTION], (U8*) GetString(STR_GLOBAL_USERNAME));

    /* For username string */
    SetInlineItemActivation(&authenticate_list[DRMT_INLINE_USERNAME], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &authenticate_list[DRMT_INLINE_USERNAME],
        STR_GLOBAL_USERNAME,
        mmi_rmgr_get_root_icon(),
        (U8*) DRMT_auth_username,
        WPS_MAX_AUTH_PASSWORD_LENGTH,
        IMM_INPUT_TYPE_ENGLISH_SENTENCE);
    SetInlineFullScreenEditCustomFunction(
        &authenticate_list[DRMT_INLINE_USERNAME],
        mmi_drm_auth_full_screen_editor_options);

    /* For password caption */
    SetInlineItemActivation(
        &authenticate_list[DRMT_INLINE_PASSWORD_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&authenticate_list[DRMT_INLINE_PASSWORD_CAPTION], (U8*) GetString(STR_GLOBAL_PASSWORD));

    /* For password string */
    SetInlineItemActivation(&authenticate_list[DRMT_INLINE_PASSWORD], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &authenticate_list[DRMT_INLINE_PASSWORD],
        STR_GLOBAL_PASSWORD,
        mmi_rmgr_get_root_icon(),
        (U8*) DRMT_auth_password,
        WPS_MAX_AUTH_PASSWORD_LENGTH,
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    SetInlineFullScreenEditCustomFunction(
        &authenticate_list[DRMT_INLINE_PASSWORD],
        mmi_drm_auth_full_screen_editor_options);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_DRM_AUTH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(authenticate_list, 4, inputBuffer);
    }

    SetParentHandler(0);

    /* Set the softkey label to be displayed in  Category57 screen */
    RegisterHighlightHandler(mmi_drm_softkey_label_highlight_hdlr);

    IconsImageList[0] = gIndexIconsImageList[0];
    IconsImageList[1] = 0;
    IconsImageList[2] = gIndexIconsImageList[1];
    IconsImageList[3] = 0;

    ShowCategory57Screen(
        STR_GLOBAL_AUTHENTICATION,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        4,
        (U16*) IconsImageList,
        authenticate_list,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions( mmi_drm_auth_confirm_hdlr, mmi_drm_auth_no_hdlr);
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_get_auth_req
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_recv_get_auth_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_auth_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_recv_get_auth_req", (TRACE_GROUP_2, DRM_UI_CE94B029B5756B814B4232BC9719ED38));

    msg = (drmt_get_auth_req_struct*) MsgStruct;
    mmi_drm_entry_auth();
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

void mmi_drm_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 screen_id = 0;
    U16 title = 0;
    U16 msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch( drmt_ui_cntx.session )
    {
    case DRMT_SESSION_REGISTER_AGENT:
        screen_id = SCR_ID_DRM_START_REGISTER_AGENT;
        title = STR_ID_DRM_REGISTER;
        msg = STR_ID_DRM_START_REGISTER_AGENT;
        break;

    case DRMT_SESSION_ACQUIRE_RO:
        screen_id = SCR_ID_DRM_START_ACQUIRE_RO;
        title = STR_ID_DRM_ACQUIRE;
        msg = STR_ID_DRM_START_ACQUIRE_RO;
        break;

    case DRMT_SESSION_DOMAIN_JOIN:
        screen_id = SCR_ID_DRM_START_DOMAIN_JOIN;
        title = STR_ID_DRM_JOIN;
        msg = STR_ID_DRM_START_DOMAIN_JOIN;
        break;

    case DRMT_SESSION_DOMAIN_LEAVE:
        screen_id = SCR_ID_DRM_START_DOMAIN_LEAVE;
        title = STR_ID_DRM_LEAVE;
        msg = STR_ID_DRM_START_DOMAIN_LEAVE;
        break;

    case DRMT_SESSION_PREVIEW_DOWNLOAD:
        screen_id = SCR_ID_DRM_START_PREVIEW_DOWNLOAD;
        title = STR_GLOBAL_DOWNLOAD;
        msg = STR_ID_DRM_START_PREVIEW_DOWNLOAD;
        break;

    case DRMT_SESSION_SILENT_DOWNLOAD:
        screen_id = SCR_ID_DRM_START_SILENT_DOWNLOAD;
        title = STR_GLOBAL_DOWNLOAD;
        msg = STR_ID_DRM_START_SILENT_DOWNLOAD;
        break;

    case DRMT_SESSION_TIME_SYNC:
        screen_id = SCR_ID_DRM_START_TIME_SYNC;
        title = msg = STR_ID_DRM_START_TIME_SYNC;
        break;
    default:
        ASSERT(0);
        break;
    }

    /* EntryNewScreen(screen_id, NULL, mmi_drm_entry_progressing, NULL); */
    if (mmi_frm_scrn_enter(GRP_ID_RMGR_MAIN, screen_id, NULL, mmi_drm_entry_progressing, MMI_FRM_FULL_SCRN))
    	{
    ShowCategory66Screen(
        title,
        mmi_rmgr_get_root_icon(),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (PU8) GetString(msg),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    SetRightSoftkeyFunction(mmi_drm_abort_hdlr, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(screen_id, mmi_drm_progressing_del_cb);
}
}

#define DRMT_GET_USER_CONFIRM
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_get_user_confirm_cnf
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_send_get_user_confirm_cnf(BOOL confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_user_confirm_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_send_get_user_confirm_cnf", (TRACE_GROUP_2, DRM_UI_F1FD1800D19CEBDA0801E88457290DC4));

    msg = (drmt_get_user_confirm_cnf_struct*) construct_local_para(sizeof(drmt_get_user_confirm_cnf_struct), TD_RESET);

    msg->result = confirm;

    mmi_drm_send_ilm(msg, NULL, MSG_ID_DRMT_GET_USER_CONFIRM_CNF, MOD_DRMT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_mids_get_confirm_yes_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "Yes" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_get_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearDelScrnIDCallbackHandler(SCR_ID_DRM_GET_CONFIRM, NULL);
    mmi_drm_send_get_user_confirm_cnf(DRMT_CONFIRM_YES);

    if( drmt_ui_cntx.session != DRMT_SESSION_NONE )
    {
        switch( drmt_ui_cntx.session )
        {
        case DRMT_SESSION_REGISTER_AGENT:
        case DRMT_SESSION_ACQUIRE_RO:
        case DRMT_SESSION_DOMAIN_JOIN:
        case DRMT_SESSION_DOMAIN_LEAVE:
        //case DRMT_SESSION_PREVIEW_DOWNLOAD:
        //case DRMT_SESSION_SILENT_DOWNLOAD:
            mmi_drm_entry_progressing();
            DeleteScreenIfPresent(SCR_ID_DRM_GET_CONFIRM);
            break;
        default:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_mids_get_confirm_no_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "No" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_get_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_DRM_GET_CONFIRM, NULL);
    mmi_drm_send_get_user_confirm_cnf(DRMT_CONFIRM_NO);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_mids_get_confirm_cancel_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "End key" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_drm_get_confirm_del_cb(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_drm_send_get_user_confirm_cnf(DRMT_CONFIRM_CANCEL);

    return MMI_HIST_ALLOW_DELETING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_entry_mids_get_confirm
 * DESCRIPTION
 *  The entry function to get any confirm from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_entry_get_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *str;
    U16 title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(mmi_frm_scrn_enter(
       GRP_ID_RMGR_MAIN, 
       SCR_ID_DRM_GET_CONFIRM, 
       NULL, 
       mmi_drm_entry_get_confirm, 
       MMI_FRM_FULL_SCRN))
    	{
    str = (S8*)drmt_ui_cntx.msg;
    if (drmt_ui_cntx.title)
        title = drmt_ui_cntx.title;
    else
        title = STR_ID_RMGR;

    //EntryNewScreen(SCR_ID_DRM_GET_CONFIRM, NULL, mmi_drm_entry_get_confirm, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DRM_GET_CONFIRM);

    if (drmt_ui_cntx.category == DRMT_CONFIRM_NOTIFICATION_CATEGORY)
    {
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) str,
            mmi_get_event_based_image(MMI_EVENT_CONFIRM),
            guiBuffer);
    }
    else if (drmt_ui_cntx.category == DRMT_CONFIRM_TEXT_VIEW_CATEGORY)
    {

        ShowCategory74Screen(
            (U16) title,
            mmi_rmgr_get_root_icon(),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*) str,
            app_ucs2_strlen((const kal_int8*) str),
            NULL);
    }
    else
    {
        ASSERT(0);
    }

//    SetKeyHandler(mmi_drm_get_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_drm_get_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_drm_get_confirm_no_hdlr, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_DRM_GET_CONFIRM, mmi_drm_get_confirm_del_cb);
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_get_user_confirm_req
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_recv_get_user_confirm_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_user_confirm_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_recv_get_user_confirm_req", (TRACE_GROUP_2, DRM_UI_17D20C96FAF91BFEA39E8F747F887E37));

    msg = (drmt_get_user_confirm_req_struct*) MsgStruct;
    if( drmt_ui_cntx.msg )
    {
        free_ctrl_buffer(drmt_ui_cntx.msg);
    }
    drmt_ui_cntx.session = msg->session_id;
    drmt_ui_cntx.category = msg->category;
    drmt_ui_cntx.title = msg->title;
    drmt_ui_cntx.msg = get_ctrl_buffer( app_ucs2_strlen(msg->msg) * 2 + 2 );
    app_ucs2_strcpy(drmt_ui_cntx.msg, msg->msg);

    switch( drmt_ui_cntx.session )
    {
        case DRMT_SESSION_REGISTER_AGENT:
            drmt_ui_cntx.title = STR_ID_DRM_REGISTER;
            break;
        case DRMT_SESSION_ACQUIRE_RO:
            drmt_ui_cntx.title = STR_ID_DRM_ACQUIRE;
            break;
        case DRMT_SESSION_DOMAIN_JOIN:
            drmt_ui_cntx.title = STR_ID_DRM_JOIN;
            break;
        case DRMT_SESSION_DOMAIN_LEAVE:
            drmt_ui_cntx.title = STR_ID_DRM_LEAVE;
            break;
        case DRMT_SESSION_PREVIEW_DOWNLOAD:
            drmt_ui_cntx.title = STR_GLOBAL_DOWNLOAD;
            break;
        case DRMT_SESSION_SILENT_DOWNLOAD:
            drmt_ui_cntx.title = STR_GLOBAL_DOWNLOAD;
            break;
        case DRMT_SESSION_TIME_SYNC:
            drmt_ui_cntx.title = STR_GLOBAL_DOWNLOAD;
            break;
    }

    if ( drmt_ui_cntx.session == DRMT_SESSION_ACQUIRE_RO )
    {
        mmi_drm_get_confirm_yes_hdlr();
    }
    else
    {
		U16 i;
        mmi_drm_entry_get_confirm();
        /* clean previous processing screen if exist */
        for ( i = SCR_ID_DRM_PROCESSING_START+1; i< SCR_ID_DRM_PROCESSING_END; i++)
        {
            DeleteScreenIfPresent(i);
        }
    }
}



#define DRMT_ALERT_USER
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_alert_user_rsp
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_send_alert_user_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_alert_user_rsp_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_send_alert_user_rsp",
            (TRACE_GROUP_2, DRM_UI_797AEA2EED5663D4006AE425A425A6A6));

    msg = (drmt_alert_user_rsp_struct*) construct_local_para(sizeof(drmt_alert_user_rsp_struct), TD_RESET);

    mmi_drm_send_ilm(msg, NULL, MSG_ID_DRMT_ALERT_USER_RSP, MOD_DRMT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_alert_user_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_recv_alert_user_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_alert_user_ind_struct *msg;
    mmi_event_notify_enum event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_recv_alert_user_ind",
            (TRACE_GROUP_2, DRM_UI_D29FECA278D3080AC8A72760BE12C606));

    msg = (drmt_alert_user_ind_struct*) MsgStruct;

    switch(msg->type)
    {
        case DRMT_ALERT_OK:
            event = MMI_EVENT_SUCCESS;
            break;
        case DRMT_ALERT_ERROR:
            event = MMI_EVENT_FAILURE;
            break;
        case DRMT_ALERT_WARNING:
            event = MMI_EVENT_WARNING;
            break;
        case DRMT_ALERT_DONE:
            event = MMI_EVENT_SUCCESS;
            break;
        default:
            event = MMI_EVENT_SUCCESS;
            break;
    }

    if( drmt_ui_cntx.msg )
    {
        free_ctrl_buffer(drmt_ui_cntx.msg);
    }

    drmt_ui_cntx.type = DRMT_INFO_POPUP;
    drmt_ui_cntx.event = event;
    drmt_ui_cntx.msg = get_ctrl_buffer( app_ucs2_strlen(msg->msg) * 2 + 2 );
    app_ucs2_strcpy(drmt_ui_cntx.msg, msg->msg);

#ifndef __SHOW_BY_APP__
    mmi_popup_display((WCHAR*)msg->msg, drmt_ui_cntx.event, NULL);
#endif
    mmi_drm_send_alert_user_rsp();
}
#define DRMT_NOTIFY_INFO
/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_notify_info_rsp
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_send_notify_info_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_notify_info_rsp_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_send_notify_info_rsp",
            (TRACE_GROUP_2, DRM_UI_4ACAB9E6A26B1DBC49FD6C60AE7BB217));

    msg = (drmt_notify_info_rsp_struct*) construct_local_para(sizeof(drmt_notify_info_rsp_struct), TD_RESET);

    mmi_drm_send_ilm(msg, NULL, MSG_ID_DRMT_NOTIFY_INFO_RSP, MOD_DRMT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_entry_notify_info
 * DESCRIPTION
 *  The entry function to get any confirm from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_entry_notify_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *str;
    U16 title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(mmi_frm_scrn_enter(
       GRP_ID_RMGR_MAIN, 
       SCR_ID_DRM_NOTIFY_INFO, 
       NULL, 
       mmi_drm_entry_notify_info, 
       MMI_FRM_FG_ONLY_SCRN))
    	{
    str = (S8*)drmt_ui_cntx.msg;
    if (drmt_ui_cntx.title)
        title = drmt_ui_cntx.title;
    else
        title = STR_ID_RMGR;

    /* no add to history */
    //EntryNewScreen(SCR_ID_DRM_NOTIFY_INFO, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DRM_NOTIFY_INFO);

    ShowCategory74Screen(
        (U16) title,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*) str,
        (S32) app_ucs2_strlen((const kal_int8*) str),
        NULL);

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_notify_info_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_recv_notify_info_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_notify_info_ind_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_notify_info_ind_struct*) MsgStruct;

    if( drmt_ui_cntx.msg )
    {
        free_ctrl_buffer(drmt_ui_cntx.msg);
    }
    drmt_ui_cntx.type = DRMT_INFO_TEXT;
    drmt_ui_cntx.title = msg->title;
    drmt_ui_cntx.msg = get_ctrl_buffer( app_ucs2_strlen(msg->msg) * 2 + 2 );
    app_ucs2_strcpy(drmt_ui_cntx.msg, msg->msg);

#ifndef __SHOW_BY_APP__
    mmi_drm_entry_notify_info();
#endif

    mmi_drm_send_notify_info_rsp();
}
#define DRMT_OPEN_URL

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_open_url_cnf
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_send_open_url_cnf(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_open_url_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_send_open_url_cnf",
            (TRACE_GROUP_2, DRM_UI_142FD2E5271AC508EC9475EC6849825D));

    msg = (drmt_open_url_cnf_struct*) construct_local_para(sizeof(drmt_open_url_cnf_struct), TD_RESET);

    msg->result = result;

    mmi_drm_send_ilm(msg, NULL, MSG_ID_DRMT_OPEN_URL_CNF, MOD_DRMT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_open_url_req
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_drm_recv_open_url_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 result;
    drmt_open_url_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_UI_DEBUG("[DRM] mmi_drm_recv_open_url_req",
            (TRACE_GROUP_2, DRM_UI_22F28A2359C392559C8711B17F956C03));

    msg = (drmt_open_url_req_struct*) MsgStruct;

#ifdef BROWSER_SUPPORT
    result = wap_start_browser(WAP_BROWSER_GOTO_URL,(kal_uint8 *) msg->url);
#endif

    if( result == 0 )
    {
        mmi_drm_clean_screen();
        mmi_drm_send_open_url_cnf(DRMT_BROWSER_NO_ERROR);
    }
    else
    {
        mmi_drm_send_open_url_cnf(DRMT_BROWSER_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_drm_show_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_drm_show_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(drmt_ui_cntx.type == DRMT_INFO_TEXT)
    {
        mmi_drm_entry_notify_info();
    }
    else if(drmt_ui_cntx.type == DRMT_INFO_POPUP)
    {
        mmi_popup_display((WCHAR*) drmt_ui_cntx.msg, drmt_ui_cntx.event, NULL);
    }
    drmt_ui_cntx.type = DRMT_INFO_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_need_show_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_drm_need_show_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (drmt_ui_cntx.type != DRMT_INFO_NONE)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_ui_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_drm_ui_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_get_auth_req, MSG_ID_DRMT_GET_AUTH_REQ);
    /* SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_dl_progress_ind, MSG_ID_DRMT_DL_PROGRESS_IND); */
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_get_user_confirm_req, MSG_ID_DRMT_GET_USER_CONFIRM_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_alert_user_ind, MSG_ID_DRMT_ALERT_USER_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_notify_info_ind, MSG_ID_DRMT_NOTIFY_INFO_IND);
    //SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_get_folder_req, MSG_ID_DRMT_GET_FOLDER_REQ);
    //SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_get_filename_req, MSG_ID_DRMT_GET_FILENAME_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_open_url_req, MSG_ID_DRMT_OPEN_URL_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_drm_recv_clean_screen_ind, MSG_ID_DRMT_CLEAN_SCREEN_IND);
    drmt_ui_cntx.type = DRMT_INFO_NONE;
}
#endif /* __DRM_V02__ */ 

#endif /*__DRM_SUPPORT__ */

