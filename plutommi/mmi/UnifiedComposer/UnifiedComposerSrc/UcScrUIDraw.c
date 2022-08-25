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
 * UcScrUIHldr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements screen UI handling common code for Unified Composer.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
//#include "Custom_events_notify.h"
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_icon_bar.h"
#endif
#include "ReminderSrvGprot.h"
#include "CommonScreens.h"
//#include "SettingProfile.h"
#include "wapadp.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "inlineCuiGprot.h"
#include "UcResDef.h"
#include "UcAppGprot.h"
#include "FileMgr.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcScrUIProt.h"
//#include "Wgui_touch_screen.h" 
#include "wgui_categories.h"
#include "MenuCuiGprot.h"
#include "PhoneBookResDef.h"
#include "FSEditorCuiGprot.h"
#include "ProfilesSrvGprot.h"
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
    //#include "kal_general_types.h"
    #include "UcSrvGprot.h"
    //#include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_categories_popup.h"
    #include "mmi_frm_input_gprot.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_timer_gprot.h"
    //#include "TimerEvents.h"
    #include "mma_api.h"
    #include "wgui_categories_util.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_history_gprot.h"
    #include "CustDataRes.h"
    #include "gui_data_types.h"
    #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "ImeGprot.h"
    #include "wgui_categories_inputs.h"
    #include "gui_typedef.h"
   // #include "mmi_rp_app_phonebook_def.h"
    #include "custom_phb_config.h"
    #include "CustMenuRes.h"
    #include "wgui_categories_list.h"
   // #include "MMI_common_app_trc.h"
    #include "kal_trace.h"
    //#include "mmi_common_app_trc.h"
    #include "wgui_categories_UCE.h"
    #include "wgui_categories_text_viewer.h"
   #ifdef __MMI_OP02_LEMEI__
     #include "mmi_rp_app_lemei_def.h"
   #endif
/***************************************************************************** 
* Define
*****************************************************************************/
/****************************************************************************
* Constants
*****************************************************************************/
/****************************************************************************
 * Type definitions
 ****************************************************************************/

extern void GetCurrEndKeyDownHandler(void);

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_subject_editor_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_subject_editor_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__)
    mmi_uc_frm_ui_editor_cat215_screen_draw(instance_hash_id);
#elif defined(__MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__)
    mmi_uc_frm_ui_editor_cat215ext_screen_draw(instance_hash_id);
#else /* must define===> Normal UC */
    mmi_uc_frm_ui_editor_cat5ext_screen_draw(instance_hash_id);
#endif 
	return MMI_TRUE;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_recipient_editor_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_recipient_editor_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_uc_frm_ui_editor_cat5_screen_draw(instance_hash_id);
    }
    else
    {
        mmi_uc_frm_ui_editor_cat5ext_screen_draw(instance_hash_id);
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_slide_time_editor_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_slide_time_editor_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_ui_editor_cat5_screen_draw(instance_hash_id);
	return MMI_TRUE;
}

/*--------------------------- Generic Draw UI ( Use showcategory ) ------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_progress_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_progress_screen_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_progress_screen_struct *prgs =
        (mmi_uc_frm_progress_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource_obj_p = mmi_uc_frm_get_resourceDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || prgs == NULL || resource_obj_p == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            prgs->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {

		mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
        ShowCategory66Screen(
            resource_obj_p->title_str_id,
            resource_obj_p->title_icon_id,
            0,
            0,
            0,
            0,
            (U8*) prgs->get_message_cb(prgs->body_str_id),
            prgs->animation_image_id,
            NULL);

        
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
        StartTimer(UC_INPROGRESS_TIMER_ID, MMI_UC_INPROGRESS_TIME_OUT, mmi_uc_time_out_processing_generic);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_confirmation_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_confirmation_screen_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_confirmation_screen_struct *cnfrm =
        (mmi_uc_frm_confirmation_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || cnfrm == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            cnfrm->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {

		if (g_uc_p->main.confirm_flag_onoff != MMI_FALSE)
		{
			EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		}
        ShowCategory66Screen(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            (U8*) cnfrm->get_message_cb(cnfrm->body_str_id),
            (U16) cnfrm->get_image_id_cb(cnfrm->event_id),
            NULL);

        
        if (cnfrm->confirm_lsk_func != NULL)
        {
            SetLeftSoftkeyFunction(cnfrm->confirm_lsk_func, KEY_EVENT_UP);
			if (g_uc_p->main.confirm_flag_onoff != MMI_FALSE)
			{
				SetCenterSoftkeyFunction(cnfrm->confirm_lsk_func, KEY_EVENT_UP);
			}
        }

		if (cnfrm->confirm_rsk_func != NULL){
			ClearKeyHandler(KEY_END, KEY_EVENT_UP);
			ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
			ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
			ClearKeyHandler(KEY_END, KEY_REPEAT);

			SetKeyHandler(cnfrm->confirm_rsk_func, KEY_END, KEY_EVENT_DOWN);
		}

        if (cnfrm->confirm_rsk_func != NULL)
        {
            SetRightSoftkeyFunction(cnfrm->confirm_rsk_func, KEY_EVENT_UP);
        }

        if (cnfrm->confirm_tone_id && (!mmi_frm_is_in_backward_scenario()))
        {
            srv_prof_play_tone((srv_prof_tone_enum)cnfrm->confirm_tone_id, NULL);
        }
    }
    return MMI_TRUE;

}

#if !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_progress_screen_for_send_cancellation_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_progress_screen_for_send_cancellation_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_progress_screen_for_send_cancellation_struct *prgs =
        (mmi_uc_frm_progress_screen_for_send_cancellation_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || prgs == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    
    if( mmi_frm_scrn_enter(
            prgs->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            prgs->body_str_id,
            prgs->animation_image_id,
            NULL);

        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        

        SetKeyHandler(prgs->end_key_func, KEY_END, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(prgs->rsk_func, KEY_EVENT_UP);
    }

    return MMI_TRUE;
}
#endif /* !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_static_list_cui_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_static_list_cui_draw_func(U16 instance_hash_id)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id child_menu_gid;
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    child_menu_gid = cui_menu_create(g_uc_p->main.uc_cui_gid ,
                                                		    CUI_MENU_SRC_TYPE_RESOURCE,
                                                		    CUI_MENU_TYPE_FROM_RESOURCE,	/* Option menu */
                                                		    scrDB->parent_menu_id,	
                                                		    MMI_FALSE, NULL);
    cui_menu_set_default_title(child_menu_gid,  (UI_string_type) GetString(resource->title_str_id), (UI_image_type) GetImage(resource->title_icon_id));
     cui_menu_run(child_menu_gid);

     return MMI_TRUE;
}


static const cui_inline_item_caption_struct caption1 = {STR_UC_START_TIME_ID};
static const cui_inline_item_caption_struct caption2 = {STR_UC_END_TIME_ID};
static const cui_inline_item_text_edit_struct textedit_test1 = {0, STR_GLOBAL_EDIT, 0, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};
static const cui_inline_item_text_edit_struct textedit_test2 = {0, STR_GLOBAL_EDIT, 0, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};
static const cui_inline_set_item_struct app_inline_1[] = 
{
    {APP_CAPTION1, CUI_INLINE_ITEM_TYPE_CAPTION  , IMG_GLOBAL_L1, (void *)&caption1},
        
    {APP_TEXTEDIT1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_test1},

    {APP_CAPTION2, CUI_INLINE_ITEM_TYPE_CAPTION  , IMG_GLOBAL_L2, (void *)&caption2},
        
    {APP_TEXTEDIT2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_test2}
};
//static const cui_inline_item_softkey_struct app_softkey = {{{STR_GLOBAL_OK, 0}, {0, 0}, {0, 0XFFFF}}};
static const cui_inline_struct g_initial_data = 
{
    4,
    STR_GLOBAL_EDIT,
    0, 
    CUI_INLINE_SCREEN_LOOP, 
    NULL,
    app_inline_1
};

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func(U16 instance_hash_id)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_inline_selection_screen_struct *inline_selection_scr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_selection_scr =
        (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    g_uc_p->main.inline_child_cui_id = cui_inline_create(inline_selection_scr->uc_gid, &g_initial_data);

    cui_inline_set_title(g_uc_p->main.inline_child_cui_id, resource->title_str_id, resource->title_icon_id); 
    inline_selection_scr->inline_items();
	cui_inline_set_softkey_icon(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT1, MMI_CENTER_SOFTKEY,  IMG_GLOBAL_COMMON_CSK);
    cui_inline_set_softkey_icon(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT2, MMI_CENTER_SOFTKEY,  IMG_GLOBAL_COMMON_CSK);
    cui_inline_run (g_uc_p->main.inline_child_cui_id);
	return MMI_TRUE;
}

/*send option*/
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
static const cui_inline_item_caption_struct caption_validity_period = {STR_UC_VALIDITY_PERIOD_ID};
#endif
static const cui_inline_item_caption_struct caption_delivery_report = {STR_UC_DELIVERY_REPORT_ID};
static const cui_inline_item_caption_struct caption_read_report = {STR_UC_READ_REPORT_ID};
static const cui_inline_item_caption_struct caption_priority = {STR_GLOBAL_PRIORITY};
static const cui_inline_item_caption_struct caption_delivery_time = {STR_UC_DELIVERY_TIME_ID};
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__	
static const cui_inline_item_caption_struct caption_sender_visibility = {STR_UC_HIDE_SENDER_ID};
#endif
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
static const cui_inline_item_caption_struct caption_msg_class = {STR_UC_MSG_CLASS_ID};
#endif

#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
static const U16 validity_period_select_string[6] = {STR_UC_VALIDITY_PERIOD_1_HOUR_ID,
                                                    STR_UC_VALIDITY_PERIOD_6_HOUR_ID,
                                                    STR_UC_VALIDITY_PERIOD_12_HOUR_ID,
                                                    STR_UC_VALIDITY_PERIOD_1_DAY_ID,
                                                    STR_UC_VALIDITY_PERIOD_1_WEEK_ID,
                                                    STR_GLOBAL_MAXIMUM};
#endif
static const U16 delivery_report_select_string[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const U16 read_report_select_string[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const U16 priority_select_string[3] = {STR_GLOBAL_LOW, STR_GLOBAL_MEDIUM, STR_GLOBAL_HIGH};
static const U16 delivery_time_select_string[4] = {STR_UC_DELIVERY_TIME_IMMEDIATE_ID,
                                                    STR_UC_DELIVERY_TIME_1_HOUR_ID,
                                                    STR_UC_DELIVERY_TIME_12_HOUR_ID,
                                                    STR_UC_DELIVERY_TIME_24_HOUR_ID};
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__	
static const U16 sender_visibility_select_string[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
#endif
 #ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
static const U16 msg_class_select_string[] = {STR_ID_UC_PERSONAL, 
												STR_ID_UC_ADVERTISEMENT,
												STR_ID_UC_INFORMATIONAL,
												STR_ID_UC_AUTO};
#endif 
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
static const cui_inline_item_select_struct select_validity_period ={6, 0, (U16 *)validity_period_select_string};
#endif
static const cui_inline_item_select_struct select_delivery_report = {2, 0, (U16 *)delivery_report_select_string};
static const cui_inline_item_select_struct select_read_report = {2, 0, (U16 *)read_report_select_string};
static const cui_inline_item_select_struct select_priority = {3, 0, (U16 *)priority_select_string};
static const cui_inline_item_select_struct select_delivery_time = {4,0, (U16 *)delivery_time_select_string};
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
static const cui_inline_item_select_struct select_sender_visibility = {2, 0, (U16 *)sender_visibility_select_string};
#endif
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
	static const cui_inline_item_select_struct select_msg_class = {4, 0, (U16 *)msg_class_select_string};
#endif
static const cui_inline_set_item_struct sending_opt[] = 
{     
    #ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
    {VALIDITY_PERIOD_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void *)&caption_validity_period},
    {VALIDITY_PERIOD_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_validity_period},
    #endif

    {DELIVERY_REPORT_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void *)&caption_delivery_report},
    {DELIVERY_REPORT_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_delivery_report},

    {READ_REPORT_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void *)&caption_read_report},
    {READ_REPORT_SELECT,        CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_read_report},

    {PRIORITY_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void *)&caption_priority},
    {PRIORITY_SELECT,           CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_priority},

    {DELIVERY_TIME_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void *)&caption_delivery_time},
    {DELIVERY_TIME_SELECT,      CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_delivery_time},

    #ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
    {SENDER_VISIBILITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void *)&caption_sender_visibility},
    {SENDER_VISIBILITY_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_sender_visibility},
    #endif

	#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
	{MSG_CLASS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L7, (void *)&caption_msg_class},
    {MSG_CLASS_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void *)&select_msg_class},
	#endif
};
static const cui_inline_struct g_initial_data2 = 
{
    MMI_UC_SEND_OPT_TOTAL_NUM,
    STR_UC_SEND_OPTION_ID,
    IMG_UC_ENTRY_SCRN_CAPTION_ID, 
    CUI_INLINE_SCREEN_LOOP ,
    NULL,
    sending_opt
};

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_draw_send_opt_inline_cui_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_draw_send_opt_inline_cui_draw_func(U16 instance_hash_id)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_inline_selection_screen_struct *inline_selection_scr = NULL;

    /*----------------------------------------------------------------*/
    /* code bady                                                      */
    /*----------------------------------------------------------------*/
    inline_selection_scr =
        (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    g_uc_p->main.inline_child_cui_id = cui_inline_create(inline_selection_scr->uc_gid, &g_initial_data2);

    cui_inline_set_title(g_uc_p->main.inline_child_cui_id, resource->title_str_id, resource->title_icon_id); 
    inline_selection_scr->inline_items();
    cui_inline_run (g_uc_p->main.inline_child_cui_id);
	return MMI_TRUE ;
}

/* recipient address editor for post card*/
#ifdef __MMI_MMS_POSTCARD__
static const cui_inline_item_caption_struct name_caption           = {STR_ID_PHB_NAME};
static const cui_inline_item_caption_struct adr_ext_caption        = {STR_ID_PHB_ADR_EXTENSION};
static const cui_inline_item_caption_struct adr_street_caption     = {STR_ID_PHB_ADR_STREET};
static const cui_inline_item_caption_struct adr_city_caption       = {STR_ID_PHB_ADR_CITY};
static const cui_inline_item_caption_struct adr_state_caption      = {STR_ID_PHB_ADR_STATE};
static const cui_inline_item_caption_struct adr_postalcode_caption = {STR_ID_PHB_ADR_POSTALCODE};
static const cui_inline_item_caption_struct adr_country_caption    = {STR_ID_PHB_ADR_COUNTRY};

static const cui_inline_item_fullscreen_edit_struct full_screen_name           = {0, STR_GLOBAL_EDIT, STR_ID_PHB_NAME,          IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_NAME_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_ext        = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_EXTENSION, IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_street     = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_STREET,    IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_city       = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_CITY,      IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_state      = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_STATE,     IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_postalcode = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_POSTALCODE, IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};
static const cui_inline_item_fullscreen_edit_struct full_screen_adr_country    = {0, STR_GLOBAL_EDIT, STR_ID_PHB_ADR_COUNTRY,   IMG_UC_ENTRY_SCRN_CAPTION_ID, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, IMM_INPUT_TYPE_SENTENCE, MMI_PHB_ADDRESS_LENGTH + 1, NULL};

static const cui_inline_set_item_struct postcard_add_inline[] = 
{
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {POSTCARD_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION  ,                 IMG_NAME, (void *)&name_caption},
#else
	{POSTCARD_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION  ,                 0, (void *)&name_caption},
#endif
    {POSTCARD_FULLSCREEN_EDIT1,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,        (void *)&full_screen_name},

    {POSTCARD_ADR_EXTENSION_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_EXTENSION, (void *)&adr_ext_caption},
    {POSTCARD_FULLSCREEN_EDIT2,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_ext}, 

    {POSTCARD_ADR_STREET_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_STREET,    (void *)&adr_street_caption},
    {POSTCARD_FULLSCREEN_EDIT3,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_street},

    {POSTCARD_ADR_CITY_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_CITY,      (void *)&adr_city_caption},
    {POSTCARD_FULLSCREEN_EDIT4,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_city},

    {POSTCARD_ADR_STATE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_STATE,     (void *)&adr_state_caption},
    {POSTCARD_FULLSCREEN_EDIT5,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_state},

    {POSTCARD_ADR_POSTALCODE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_POSTALCODE, (void *)&adr_postalcode_caption},
    {POSTCARD_FULLSCREEN_EDIT6,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_postalcode},

    {POSTCARD_ADR_COUNTRY_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION  ,       IMG_ID_PHB_ADR_COUNTRY,   (void *)&adr_country_caption},
    {POSTCARD_FULLSCREEN_EDIT7,       CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0,                        (void *)&full_screen_adr_country},
};
cui_inline_item_softkey_struct postcard_softkey = {{{STR_GLOBAL_EDIT, 0}, {0, 0}, {0, 0XFFFF}}};

static const cui_inline_struct g_postcard_adr_initial_data = 
{
    14,
    STR_GLOBAL_ADDRESS,
    IMG_UC_ENTRY_SCRN_CAPTION_ID, 
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    postcard_add_inline
};

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_draw_postcard_addr_inline_cui_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_draw_postcard_addr_inline_cui_draw_func(U16 instance_hash_id)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_inline_selection_screen_struct *inline_selection_scr = NULL;

    /*----------------------------------------------------------------*/
    /* code bady                                                      */
    /*----------------------------------------------------------------*/
    inline_selection_scr =
        (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    g_uc_p->main.inline_child_cui_id = cui_inline_create(inline_selection_scr->uc_gid, &g_postcard_adr_initial_data);

    cui_inline_set_title(g_uc_p->main.inline_child_cui_id, resource->title_str_id, resource->title_icon_id); 
    inline_selection_scr->inline_items();
    cui_inline_run (g_uc_p->main.inline_child_cui_id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_editor_option_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_editor_option_list_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;  /* Buffer holding history data */

    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 *items_list = NULL;             /* (*list_of_items)(U16); */
    U16 *icons_list = NULL;             /* (*list_of_icons)(U16); */
    U8 **descriptions_list = NULL;      /* (*list_of_descriptions)(U16,U8**); */
    U16 num_item = 0;                   /* Stores no of children in the submenu */
    U8 *popUpList[MAX_SUB_MENUS];
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_editor_option_screen_struct *editor_opt_scr =
        (mmi_uc_frm_editor_option_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || editor_opt_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if( mmi_frm_scrn_enter(
            editor_opt_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {

        gui_buffer = mmi_frm_scrn_get_active_gui_buf ();

        if (editor_opt_scr->set_data_for_editor_option != NULL)
        {
            editor_opt_scr->set_data_for_editor_option(instance_hash_id);
        }

        num_item = GetNumOfChild_Ext(scrDB->parent_menu_id);

        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

        if (editor_opt_scr->list_of_items != NULL)
        {
            items_list = editor_opt_scr->list_of_items(instance_hash_id, str_item_list);
        }

        if (editor_opt_scr->list_of_icons != NULL)
        {
            icons_list = editor_opt_scr->list_of_icons(instance_hash_id);
        }

        if (editor_opt_scr->list_of_descriptions != NULL)
        {
            descriptions_list = editor_opt_scr->list_of_descriptions(instance_hash_id, popUpList);
        }

        ShowCategory529Screen(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            num_item,
            items_list,
            icons_list,
            descriptions_list,
            0,
            0,
            gui_buffer,
            scrDB->hilite_handler,
            editor_opt_scr->f_close);


        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    return MMI_TRUE;
}

mmi_ret mmi_uc_editor_end_key_handler(mmi_event_struct *evt)
{
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
        {
            mmi_uc_write_msg_end_key_hdlr();
            return MMI_RET_OK;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_content_editor_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_content_editor_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;
    //S32 list_not_ready = 0;
    //U8 *edit_buffer = NULL;
    UI_string_type subjcet_firstline = NULL;
    UI_string_type subject_secondline = NULL;
	/*SLIM change*/
	U32 show_title_id = 0;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_content_editor_screen_struct *editor_scr =
        (mmi_uc_frm_content_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_ENTRY_WRITE_MSG);

    if (scrDB == NULL || editor_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if( mmi_frm_scrn_enter(
            editor_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer_p = mmi_frm_scrn_get_active_gui_buf ();
        srv_reminder_enable(SRV_REMINDER_TYPE_SPOF,  MMI_FALSE);
        GetCurrEndKeyDownHandler();
#ifdef __MMI_OP02_LEMEI__
		/*hide subject filed on editor screen in lemei mms*/
       if(g_uc_p->srv_msg_type->MMS_edit_mode != MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
#endif	  
           {
		   editor_scr->get_subject_strings(&subjcet_firstline, &subject_secondline);
	       }

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#else
        EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
       //mmi_imc_disable_csk();
    #ifdef __MMI_ICON_BAR_SUPPORT__

        wgui_icon_bar_setup(
                editor_scr->editor_tool_bar.item_count, 
                editor_scr->editor_tool_bar.content_icon, 
                editor_scr->editor_tool_bar.disabled_content_icon, 
                editor_scr->editor_tool_bar.string, 
                editor_scr->editor_tool_bar.callback
                );
		/*kuldeep_nosim*/
		if(g_uc_p->srv_sim_info->valid_sim_id_info ==SRV_UC_SIM_ID_UNCLASSIFIED)
		{
			wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);/* "0" index here for disable the send fte icon*/
			if(g_uc_p->srv_msg->to_num != 0)
			{
				//wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
			}
		}
    #endif

#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
        if(g_uc_p->srv_msg->msg_body.total_attach_no)
        {
            wgui_cat280_register_attach_button_callback(mmi_uc_opt_attachment_list);
        }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        wgui_cat280_register_recipient_change_callback(mmi_uc_recipient_change_callback);
        wgui_cat280_register_object_callback(mmi_uc_play_highlighted_object);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

	/*set here title_str_id*/
	#ifdef __MMI_OP02_LEMEI__
	if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
			show_title_id = STR_ID_LEMEI_MENUITEM ;
	}
	else
	#endif
	{
	#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
			 show_title_id = editor_scr->get_title_id(instance_hash_id) ;
	#else
			 show_title_id = resource->title_str_id ;
	#endif
	}
        mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

        ShowCategory280Screen(
			show_title_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            (wgui_uce_msg_type_enum)editor_scr->editor_msg_type(),
            editor_scr->input_type,
            subjcet_firstline,
            subject_secondline,
            gui_buffer_p);

        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);

		if(g_uc_p->srv_sim_info->valid_sim_id_info !=SRV_UC_SIM_ID_UNCLASSIFIED)
        {
            SetKeyHandler(mmi_uc_write_msg_send_key_callback, KEY_SEND, KEY_EVENT_UP);
        }
        else
        {
             SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
        }

        SetCategory280RightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
        mmi_frm_scrn_set_key_proc(editor_scr->uc_gid, scrDB->scrn_id, mmi_uc_editor_end_key_handler);
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        SetCenterSoftkeyFunction(editor_scr->csk_func, KEY_EVENT_UP);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        if (scrDB->delete_screen_handler != NULL)
        {
            mmi_frm_scrn_set_leave_proc(editor_scr->uc_gid, scrDB->scrn_id, scrDB->delete_screen_handler);
        }
    }
	return MMI_TRUE ;
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_full_text_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_full_text_screen_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 submenudatalength = 0;
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_full_text_screen_struct *detail_screen =
        (mmi_uc_frm_full_text_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf ();
    if (scrDB == NULL || detail_screen == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            detail_screen->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {

        ShowCategory74Screen(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            detail_screen->get_string_buffer(instance_hash_id, &submenudatalength),
            (S32) submenudatalength,
            guiBuffer);

        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    return MMI_TRUE;
}
#endif
#if !defined(__MMI_MMS_BGSR_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_progress_meter_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_progress_meter_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S8 *message;
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_progress_meter_screen_struct *progress_meter_screen =
        (mmi_uc_frm_progress_meter_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || progress_meter_screen == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            progress_meter_screen->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf ();

        message = progress_meter_screen->get_message_buffer(instance_hash_id);
        ShowCategory402Screen(
            (U8*) GetString(resource->title_str_id),
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            progress_meter_screen->get_string_buffer(instance_hash_id),
            progress_meter_screen->get_progress_percent(instance_hash_id),
            (U8*) message);
        progress_meter_screen->free_message_buffer(message);
        message = NULL;

        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        SetKeyHandler(progress_meter_screen->end_key_func, KEY_END, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    return MMI_TRUE;
}
#endif /* !defined(__MMI_MMS_BGSR_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_dynamic_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_dynamic_list_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    //S32 list_not_ready = 0;
    U16 hilighted_item = 0;
    U16 numItems = 0;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_dynamic_screen_struct *dynamic_scr =
        (mmi_uc_frm_dynamic_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || dynamic_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if( mmi_frm_scrn_enter(
            dynamic_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {

        if (dynamic_scr->fixed_list_register_get_flags)
        {
            wgui_fixed_list_register_get_flags_handler(dynamic_scr->fixed_list_register_get_flags);
        }

        if (dynamic_scr->number_of_item != NULL)
        {
            numItems = dynamic_scr->number_of_item();
        }

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        if (dynamic_scr->get_hilighted_item != NULL)
        {
            hilighted_item = dynamic_scr->get_hilighted_item(guiBuffer, numItems);
        }

        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

        if (scrDB->hilite_handler != NULL)
        {
            RegisterHighlightHandler(scrDB->hilite_handler);
        }

		#ifdef __UC_ASYNC_DYNAMIC_LIST__
		wgui_cat1032_show(
        (WCHAR*)GetString(dynamic_scr->set_data_for_recipient_list(instance_hash_id)),     //WCHAR* title,
		(PU8) GetImage(resource->title_icon_id),                                           //PU8 title_icon,
        (WCHAR*) GetString(resource->lsk_str_id),										    //WCHAR* left_softkey,
        (PU8) GetImage(resource->lsk_icon_id), 										        //PU8 left_softkey_icon,
        (WCHAR*) GetString(resource->rsk_str_id),											//WCHAR* right_softkey,
        (PU8) GetImage(resource->lsk_icon_id),												//PU8 right_softkey_icon,
		numItems,
        dynamic_scr->get_item_cb,															//GetAsyncItemFuncPtr get_item_func,
        NULL,																				//GetAsyncHintFuncPtr get_hint_func,
        hilighted_item,																		//S32 highlighted_item,
		1,																					//S8 highlighted_tab,    																
		IMG_UC_TO_NUMBER_ID,																	//U16 list_icon1,,
		IMG_GLOBAL_L1,	  																//U16 list_icon2,
        guiBuffer, 																			//U8 *history_buffer,
        NULL																				//S32 *category_error_flag
        );
        
		#else
        ShowCategory184Screen(
            dynamic_scr->set_data_for_recipient_list(instance_hash_id),
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            numItems,
            dynamic_scr->get_item_cb,
            NULL,
            hilighted_item,
            guiBuffer);
		#endif

     #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(dynamic_scr->tap_func);
     #endif /* __MMI_FTE_SUPPORT__ */

        if (scrDB->delete_screen_handler != NULL)
        {
            mmi_frm_scrn_set_leave_proc(dynamic_scr->uc_gid, scrDB->scrn_id, scrDB->delete_screen_handler);
        }
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_editor_cat5_screen_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_editor_cat5_screen_draw(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 list_not_ready = 0;
    U8 *edit_buffer = NULL;
    //mmi_id fseditor_gid;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || editor_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

    if (scrDB->hilite_handler != NULL)
    {
        RegisterHighlightHandler(scrDB->hilite_handler);
    }

            editor_scr->set_first_entry_editor_environment();

        edit_buffer = (PU8) editor_scr->get_editor_buffer(instance_hash_id);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        if ((g_uc_p->main.editor_child_cui_id = cui_fseditor_create(editor_scr->uc_gid)) != NULL)
        {
            cui_fseditor_set_title(g_uc_p->main.editor_child_cui_id, resource->title_str_id, resource->title_icon_id);
            cui_fseditor_set_buffer(g_uc_p->main.editor_child_cui_id, (PU8) edit_buffer, editor_scr->get_max_buffer_length() * ENCODING_LENGTH, editor_scr->get_max_buffer_length() - 1);
            cui_fseditor_set_input_method(g_uc_p->main.editor_child_cui_id, editor_scr->get_input_type(), NULL, 0);
            cui_fseditor_run(g_uc_p->main.editor_child_cui_id);
        }
        return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_editor_cat5ext_screen_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_editor_cat5ext_screen_draw(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 list_not_ready = 0;
    U8 *edit_buffer = NULL;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || editor_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if (scrDB->parent_menu_id != 0)
    {
        SetParentHandler(scrDB->parent_menu_id);
    }

    if (scrDB->hilite_handler != NULL)
    {
        RegisterHighlightHandler(scrDB->hilite_handler);
    }
        editor_scr->set_first_entry_editor_environment();

    edit_buffer = (PU8) editor_scr->get_editor_buffer(instance_hash_id);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    if ((g_uc_p->main.editor_child_cui_id = cui_fseditor_create(editor_scr->uc_gid)) != NULL)
    {
        cui_fseditor_set_title(g_uc_p->main.editor_child_cui_id, resource->title_str_id, resource->title_icon_id);
        cui_fseditor_set_buffer(g_uc_p->main.editor_child_cui_id, (PU8) edit_buffer, editor_scr->get_max_buffer_length() * ENCODING_LENGTH, editor_scr->get_max_buffer_length() - 1);
        cui_fseditor_set_input_method(g_uc_p->main.editor_child_cui_id, editor_scr->get_input_type(), (mmi_imm_input_mode_enum*) editor_scr->get_editor_filter_for_input_mode(), editor_scr->get_editor_filters());
		if (g_uc_p->srv_msg_type->caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY)
		{
			if (editor_scr->get_editor_filter_for_input_mode() != NULL)
			{
				cui_fseditor_set_characters_filter(g_uc_p->main.editor_child_cui_id, MMI_TRUE, (const UI_character_type *)mmi_imm_get_allowed_email_address_characters());
			}
		}
        cui_fseditor_run(g_uc_p->main.editor_child_cui_id);
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_editor_cat215ext_screen_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_editor_cat215ext_screen_draw(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;
    //S32 list_not_ready = 0;
    U8 *edit_buffer = NULL;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || editor_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if ( mmi_frm_scrn_enter(
            editor_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer_p = mmi_frm_scrn_get_active_gui_buf();
        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

        if (scrDB->hilite_handler != NULL)
        {
            RegisterHighlightHandler(scrDB->hilite_handler);
        }
        if (gui_buffer_p == NULL)
        {
            editor_scr->set_first_entry_editor_environment();
        }
        edit_buffer = (PU8) editor_scr->get_editor_buffer(instance_hash_id);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ShowCategory215Screen_ext(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            editor_scr->get_input_type(),
            edit_buffer,
            editor_scr->get_max_buffer_length(),
            gui_buffer_p);

        SetCenterSoftkeyFunction(editor_scr->csk_func, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        SetCategory5RightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_editor_cat215_screen_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_editor_cat215_screen_draw(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;
    //S32 list_not_ready = 0;
    U8 *edit_buffer = NULL;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || editor_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if (mmi_frm_scrn_enter(
            editor_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer_p = mmi_frm_scrn_get_active_gui_buf();
        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

        if (scrDB->hilite_handler != NULL)
        {
            RegisterHighlightHandler(scrDB->hilite_handler);
        }
        if (gui_buffer_p == NULL)
        {
            editor_scr->set_first_entry_editor_environment();
        }
        edit_buffer = (PU8) editor_scr->get_editor_buffer(instance_hash_id);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ShowCategory215Screen(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            editor_scr->get_input_type(),
            edit_buffer,
            editor_scr->get_max_buffer_length(),
            gui_buffer_p);

        SetCenterSoftkeyFunction(editor_scr->csk_func, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        SetCategory5RightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_single_buffer_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_single_buffer_list_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    //S32 list_not_ready = 0;

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    const mmi_uc_frm_resourceDB_struct *resource = mmi_uc_frm_get_resourceDB(instance_hash_id);
    mmi_uc_frm_single_buffer_list_screen_struct *list_scr =
        (mmi_uc_frm_single_buffer_list_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || list_scr == NULL || resource == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    if (mmi_frm_scrn_enter(
            list_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        if (scrDB->parent_menu_id != 0)
        {
            SetParentHandler(scrDB->parent_menu_id);
        }

        if (scrDB->hilite_handler != NULL)
        {
            RegisterHighlightHandler(scrDB->hilite_handler);
        }

	#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
	#else
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	#endif
        ShowCategory84Screen(
            resource->title_str_id,
            resource->title_icon_id,
            resource->lsk_str_id,
            resource->lsk_icon_id,
            resource->rsk_str_id,
            resource->rsk_icon_id,
            list_scr->number_of_items(instance_hash_id),
            (U8 **) list_scr->list_of_items(instance_hash_id),
            list_scr->list_of_icons(instance_hash_id),
            0,
            0,
            guiBuffer);

        SetCenterSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_is_back_empty_body_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_is_back_empty_body_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_back = mmi_frm_is_in_backward_scenario();

    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
    mmi_uc_frm_is_back_empty_body_screen_struct *is_back_empty_body_scr =
        (mmi_uc_frm_is_back_empty_body_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL || is_back_empty_body_scr == NULL)
    {
        MMI_ASSERT(0);
    }
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            is_back_empty_body_scr->uc_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        //set_small_screen();
        //mmi_frm_scrn_set_attribute (g_uc_p->main.uc_cui_gid, scrDB->scrn_id, MMI_SCRN_ATTRIB_SMALL_SCRN);
        if (scrDB->delete_screen_handler != NULL)
        {
            mmi_frm_scrn_set_leave_proc(is_back_empty_body_scr->uc_gid, scrDB->scrn_id, scrDB->delete_screen_handler);
        }
        is_back_empty_body_scr->is_back_process_handle(is_back);
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_dummy_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_dummy_screen_draw_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrDB == NULL)
    {
        MMI_ASSERT(0);
    }
	if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    if( mmi_frm_scrn_enter(
            g_uc_p->main.uc_cui_gid,
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FG_ONLY_SCRN))
    {
        mmi_frm_scrn_set_attribute (g_uc_p->main.uc_cui_gid, scrDB->scrn_id, MMI_SCRN_ATTRIB_SMALL_SCRN);
    }
	return MMI_TRUE ;
}

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
