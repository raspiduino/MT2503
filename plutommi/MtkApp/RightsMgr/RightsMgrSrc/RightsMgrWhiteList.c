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
 *  RightsMgrWhiteList.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  White list screen of Rights Manager  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include 
 */
#include "MMI_include.h"

#ifdef __DRM_V02__

#include "custom_mmi_default_value.h"
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"

#include "CommonScreens.h"
#include "SettingProfile.h"
#include "app_str.h"
#include "AlertScreen.h"

#include "FileManagerGProt.h"
/*
 * Local Functions
 */
static void mmi_rmgr_whitelist_select(S32 menu_idx);
static void mmi_rmgr_whitelist_set_execute_key_hdlr(FuncPtr key_hdlr);
static void mmi_rmgr_whitelist_entry_option(void);
static void mmi_rmgr_whitelist_go_back_to_main(void);
static void mmi_rmgr_whitelist_edit_option_done(void);
static void mmi_rmgr_whitelist_edit_option_entry_cancel(void);
static void mmi_rmgr_whitelist_edit_option_input_method_go_back_2(void);
static void mmi_rmgr_whitelist_edit_option_highlight_hdlr(S32 menu_idx);
static void mmi_rmgr_whitelist_entry_edit(void);
static void mmi_rmgr_whitelist_clean_done(void);
static void mmi_rmgr_whitelist_entry_clean(void);
static void mmi_rmgr_whitelist_option_highlight_hdlr(S32 menu_idx);

/*
 * Global Variable
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_select
 * DESCRIPTION
 *  Highlight handler of the white list main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_select(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->wl_sel_idx = menu_idx;

    if (mmi_rmgr_p->wl_sel_idx < mmi_rmgr_p->wl_count)
    {
        SetKeyHandler(mmi_rmgr_whitelist_entry_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_rmgr_whitelist_entry_option, KEY_EVENT_UP);
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    }
    else
    {
		app_ucs2_strcpy((kal_int8 *)mmi_rmgr_p->input_buffer, (kal_int8 *)L"http://");
        SetLeftSoftkeyFunction(mmi_rmgr_whitelist_entry_edit, KEY_EVENT_UP);
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_set_execute_key_hdlr
 * DESCRIPTION
 *  Set the execution key handler
 * PARAMETERS
 *  key_hdlr        [IN]        Key handler function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_set_execute_key_hdlr(FuncPtr key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(key_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_done
 * DESCRIPTION
 *  Entry function of the white list edit option done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 err_old, err_new, i;
    kal_int8 tmp_url[(MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1) *ENCODING_LENGTH];
    kal_int32 input_len = app_ucs2_strlen((kal_int8 *)mmi_rmgr_p->input_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; input_len && i < MMI_RMGR_WHITE_LIST_NUM; i++)
    {   
        err_new = DRM_get_whitelist((kal_char *)tmp_url, i);
        if (app_ucs2_stricmp((kal_int8 *)tmp_url, (kal_int8 *)mmi_rmgr_p->input_buffer) == 0)
        {
            mmi_popup_display((WCHAR*) GetString(STR_ID_RMGR_WHITE_LIST_DUPLICATE), MMI_EVENT_FAILURE, NULL);

            DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
            return;
        }

    }
    
    err_old = DRM_get_whitelist((kal_char *)tmp_url, mmi_rmgr_p->wl_sel_idx);
    
    if (err_old && app_ucs2_strcmp((kal_int8 *)mmi_rmgr_p->input_buffer, (kal_int8 *)tmp_url) != 0)
    {
        err_old = DRM_del_whitelist((kal_char *)tmp_url);
    }
    /* fail to get whitelist means it doesn't exist */
    err_new = DRM_add_whitelist((kal_char *)mmi_rmgr_p->input_buffer);

    if (err_new == DRM_RESULT_OK)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT);
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
    else
    {
        if (err_old)
        {
            DRM_add_whitelist((kal_char *)tmp_url);
        }

        if (err_new == DRM_RESULT_INVALID_FORMAT)
        {
            mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_INVALID_URL), MMI_EVENT_FAILURE, NULL);
        }
        else
        {
            mmi_popup_display((WCHAR*)GetString(srv_fmgr_fs_error_get_string(err_new)), MMI_EVENT_FAILURE, NULL);
        }
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_entry_cancel
 * DESCRIPTION
 *  Entry function of the white list edit option cancel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_entry_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_RMGR_WHITE_LIST_OPTION))
    {
        GoBackToHistory(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
	else
	{
		GoBackToHistory(SCR_ID_RMGR_WHITE_LIST_MAIN);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the white list edit option
 * PARAMETERS
 *  menu_idx        [IN]        Highlight menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    if (menu_idx == 0)  /* done */
    {
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_edit_option_done);
    }
    else if (menu_idx == 1) /* cancel */
    {
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_edit_option_entry_cancel);
    }
    else    /* input method */
    {
        SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        mmi_rmgr_whitelist_set_execute_key_hdlr(EntryInputMethodScreen);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option
 * DESCRIPTION
 *  Entry function of the white list edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_whitelist_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    const U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, STR_GLOBAL_INPUT_METHOD};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION, NULL, mmi_rmgr_whitelist_edit_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
    ShowCategory529Screen(
        STR_GLOBAL_OPTIONS,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        3,
        (U16*) item_texts,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer,
        mmi_rmgr_whitelist_edit_option_highlight_hdlr,
        mmi_rmgr_whitelist_edit_option_input_method_go_back_2);

    if (wgui_inputs_menu_index_in_editor_range() == MMI_FALSE)
    {
        SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_input_method_go_back_2
 * DESCRIPTION
 *  go back history twice
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_input_method_go_back_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_edit
 * DESCRIPTION
 *  Entry function of the white list edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
 
    const U8 disable_symbols2[] = "\x2c\0\xa3\0\x24\0\xa5\0\xa7\0\xac\x20\xa4\0\0";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_EDIT, NULL, mmi_rmgr_whitelist_entry_edit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_EDIT);

    mmi_imm_set_characters(KAL_FALSE, (const UI_character_type *)disable_symbols2);

    /* full screen edit */
    ShowCategory5Screen(
        STR_ID_RMGR_WHITE_LIST_EDIT_ENTER_ADDRESS,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMM_INPUT_TYPE_URL,
        (U8 *)mmi_rmgr_p->input_buffer,
        MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_rmgr_whitelist_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_go_back_to_main
 * DESCRIPTION
 *  Go back to the white list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_go_back_to_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_RMGR_WHITE_LIST_MAIN))
    {
        GoBackToHistory(SCR_ID_RMGR_WHITE_LIST_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_clean_done
 * DESCRIPTION
 *  Entry function of the white list clean done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_clean_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_del_whitelist((kal_char *)mmi_rmgr_p->input_buffer))
    {
        {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_rmgr_whitelist_go_back_to_main);
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, &arg);
	}

        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
    else
    {
        {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_rmgr_whitelist_go_back_to_main);
	mmi_popup_display((WCHAR*)(GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, &arg);
	}
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_clean
 * DESCRIPTION
 *  Entry function of the white list clean screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_clean(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     {
		mmi_confirm_property_struct arg;
		mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
		arg.softkey[0].str = (WCHAR *)GetString(STR_GLOBAL_YES);
		arg.softkey[2].str = (WCHAR *)GetString(STR_GLOBAL_NO);
		arg.callback = (mmi_proc_func)mmi_rmgr_whitelist_conf_callback;
		mmi_confirm_display((WCHAR *)GetString(STR_ID_RMGR_DELETE_QUERY), MMI_EVENT_QUERY, &arg);
      }
    /*mmi_display_popup_confirm(
        (UI_string_type)GetString(STR_GLOBAL_YES),
        (PU8)GetImage(IMG_GLOBAL_YES),
        (UI_string_type)GetString(STR_GLOBAL_NO),
        (PU8)GetImage(IMG_GLOBAL_NO),
        (UI_string_type)GetString(STR_ID_RMGR_DELETE_QUERY),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_rmgr_whitelist_clean_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);*/
}

mmi_ret mmi_rmgr_whitelist_conf_callback(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;
	
    if (alertEvt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alertEvt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_rmgr_whitelist_clean_done();
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
		
	  default:
	  	break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the white list option screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_option_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_idx == 0)
    {
        /* edit */
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_edit);
    }
    else
    {
        /* clear */
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_clean);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_option
 * DESCRIPTION
 *  Entry function of the white list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    kal_uint16 item_text[] = {STR_GLOBAL_EDIT, STR_GLOBAL_DELETE};
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_get_whitelist((kal_char *)mmi_rmgr_p->input_buffer, mmi_rmgr_p->wl_sel_idx))
    {
    }
    else
    {
        app_ucs2_strcpy((kal_int8 *)mmi_rmgr_p->input_buffer, (kal_int8 *)L"http://");
    }

    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_OPTION, NULL, mmi_rmgr_whitelist_entry_option, NULL);

    RegisterHighlightHandler(mmi_rmgr_whitelist_option_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        (U16*) item_text,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_wl_del_callback
 * DESCRIPTION
 *  delete callback of the white list main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_rmgr_wl_del_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_free_whitelist();

    return MMI_HIST_ALLOW_DELETING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_main
 * DESCRIPTION
 *  Entry function of the white list main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_whitelist_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer = NULL;
    kal_uint8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_MAIN);

    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_MAIN, NULL, mmi_rmgr_whitelist_entry_main, NULL);

    mmi_rmgr_p->wl_count = DRM_init_whitelist();
    mmi_rmgr_p->wl_sel_idx = 0;


    for (i = 0; i < MMI_RMGR_WHITE_LIST_NUM; i++)
    {
        if (i < mmi_rmgr_p->wl_count)
        {
            DRM_get_whitelist((kal_char *)subMenuDataPtrs[i], i);
            if (guiBuffer &&
                app_ucs2_stricmp((kal_int8*) subMenuDataPtrs[i], (kal_int8*) mmi_rmgr_p->input_buffer) == 0)
            {
                ((list_menu_category_history *)guiBuffer)->highlighted_item = mmi_rmgr_p->wl_sel_idx = i;
            }

        }
        else
        {
            app_ucs2_strcpy((kal_int8 *)subMenuDataPtrs[i], (kal_int8 *)L"<");
            app_ucs2_strcat((kal_int8 *)subMenuDataPtrs[i], (kal_int8 *)GetString(STR_GLOBAL_EMPTY));
            app_ucs2_strcat((kal_int8 *)subMenuDataPtrs[i], (kal_int8 *)L">");
        }
    }

    RegisterHighlightHandler(mmi_rmgr_whitelist_select);

    
    ShowCategory353Screen(
        (U8*) GetString(STR_ID_RMGR_WHITE_LIST),
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        1,
        mmi_rmgr_p->wl_sel_idx,
        guiBuffer);

    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    SetDelScrnIDCallbackHandler(SCR_ID_RMGR_WHITE_LIST_MAIN, (HistoryDelCBPtr) mmi_rmgr_wl_del_callback);
}

#endif /* __DRM_V02__ */ 

