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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "GlobalResDef.h"
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_icon_bar.h"
#endif
#include "UCMGProt.h"
#include "UcmSrvGprot.h"

//#include "MessagesResourceData.h"
//#include "MessagesMiscell.h"
#ifdef __MMI_PHOTOEDITOR__
#include "PhotoEditorGProt.h"
#endif 
#include "CommonScreens.h"
#include "Custom_events_notify.h"
#include "wapadp.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif

#ifdef __MMI_MMS_POSTCARD__
#include "UcPcrdProt.h"
#endif /* #ifdef __MMI_MMS_POSTCARD__ */
#include "UcResDef.h"
#include "UcAppGprot.h"
#include "FileMgr.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcScrUIProt.h"
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
    //#include "kal_general_types.h"
    #include "mmi_frm_mem_gprot.h"
    //#include "kal_public_api.h"
    #include "string.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_rp_app_sms_def.h"
    #include "UcSrvGprot.h"
    #include "ImeGprot.h"
    #include "mmi_frm_history_gprot.h"
    #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "mma_api.h"
    #include "mmi_frm_timer_gprot.h"
    //#include "TimerEvents.h"
    #include "gdi_include.h"
    #include "wgui_categories_util.h"
    #include "customer_email_num.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_include.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/****************************************************************************
* Constants
*****************************************************************************/
/****************************************************************************
 * Type definitions
 ****************************************************************************/
/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void mmi_frm_highlight_input_method_generic(void);
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
static void mmi_uc_dummy_api(void);
#endif

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*------------------------------------Pre Functions ----------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_ui_generic_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_ui_generic_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_progress_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_progress_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_progress_screen_struct *prgs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prgs = (mmi_uc_frm_progress_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    if (prgs == NULL)
    {
        prgs = (mmi_uc_frm_progress_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_progress_screen_struct));
		ASSERT(prgs);
		memset(prgs, 0, sizeof(mmi_uc_frm_progress_screen_struct));
        prgs->uc_gid = g_uc_p->main.uc_cui_gid;
        prgs->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        prgs->scrn_id = prgs->scrDB->scrn_id;
        prgs->get_message_cb = mmi_uc_frm_app_get_progress_screen_data;
        prgs->animation_image_id = g_uc_p->processing.animation_image_id;
        prgs->body_str_id = g_uc_p->processing.body_str_id;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)prgs);
        return MMI_TRUE;
    }
    return MMI_FALSE;   /* from history   */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_confirmation_screen_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_confirmation_screen_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_confirmation_screen_struct *cnfrm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnfrm = (mmi_uc_frm_confirmation_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    if (cnfrm == NULL)
    {
        cnfrm = (mmi_uc_frm_confirmation_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_confirmation_screen_struct));
		ASSERT(cnfrm);
		memset(cnfrm, 0, sizeof(mmi_uc_frm_confirmation_screen_struct));
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        cnfrm->uc_gid = g_uc_p->main.uc_cui_gid;
        cnfrm->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        cnfrm->scrn_id = cnfrm->scrDB->scrn_id;
        cnfrm->get_message_cb = mmi_uc_frm_app_get_confirmation_screen_data;
        cnfrm->get_image_id_cb = mmi_uc_frm_app_get_confirmation_screen_image_id;
        cnfrm->confirm_lsk_func = g_uc_p->main.confirm_lsk_func;
        cnfrm->confirm_rsk_func = g_uc_p->main.confirm_rsk_func;
        cnfrm->confirm_tone_id = g_uc_p->main.confirm_tone_id;
        cnfrm->body_str_id = g_uc_p->main.confirm_str_id;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)cnfrm);
        return MMI_TRUE;
    }
    return MMI_FALSE;   /* from history   */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_sig_confirmation_screen_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_sig_confirmation_screen_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_confirmation_screen_struct *cnfrm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnfrm = (mmi_uc_frm_confirmation_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    if (cnfrm == NULL)
    {
        cnfrm = (mmi_uc_frm_confirmation_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_confirmation_screen_struct));
		ASSERT(cnfrm);
		memset(cnfrm, 0, sizeof(mmi_uc_frm_confirmation_screen_struct));
		if (g_uc_p->main.uc_cui_gid != GRP_ID_UNIFIED_COMPOSER)
		{
			cnfrm->uc_gid = g_uc_p->main.parent_grp_id;
		}
		else
		{
			cnfrm->uc_gid = g_uc_p->main.uc_cui_gid;
		}

        cnfrm->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        cnfrm->scrn_id = cnfrm->scrDB->scrn_id;
        cnfrm->get_message_cb = mmi_uc_frm_app_get_sig_confirmation_screen_data;
        cnfrm->get_image_id_cb = mmi_uc_frm_app_get_sig_confirmation_screen_image_id;
        cnfrm->confirm_lsk_func = g_uc_p->main.sig_confirm_lsk_func;
        cnfrm->confirm_rsk_func = g_uc_p->main.sig_confirm_rsk_func;
        cnfrm->confirm_tone_id = g_uc_p->main.sig_confirm_tone_id;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)cnfrm);
        return MMI_TRUE;
    }
    return MMI_FALSE;   /* from history   */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_attachment_option_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_attachment_option_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
		ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = mmi_uc_frm_app_static_menu_list_of_descriptions;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#if !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_progress_screen_for_send_cancellation_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_progress_screen_for_send_cancellation_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_progress_screen_for_send_cancellation_struct *prgs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prgs = (mmi_uc_frm_progress_screen_for_send_cancellation_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);
    if (prgs == NULL)
    {
        prgs =
            (mmi_uc_frm_progress_screen_for_send_cancellation_struct*)
            OslMalloc(sizeof(mmi_uc_frm_progress_screen_for_send_cancellation_struct));
		ASSERT(prgs);
		memset(prgs, 0, sizeof(mmi_uc_frm_progress_screen_for_send_cancellation_struct));
        prgs->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        prgs->scrn_id = prgs->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        prgs->uc_gid = g_uc_p->main.uc_cui_gid;
        prgs->body_str_id = STR_GLOBAL_SENDING;
        prgs->animation_image_id = IMG_NEW_SMS_SEND;
        prgs->end_key_func = mmi_uc_abort_send_sms_by_end_key;
        prgs->rsk_func = mmi_uc_abort_send_sms;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)prgs);
        return MMI_TRUE;
    }
    return MMI_FALSE;   /* from history   */
}
#endif /* !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_msg_detail_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_msg_detail_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_full_text_screen_struct *detail_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    detail_screen = (mmi_uc_frm_full_text_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    if (detail_screen == NULL)
    {
        detail_screen = (mmi_uc_frm_full_text_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_full_text_screen_struct));
		ASSERT(detail_screen);
		memset(detail_screen, 0, sizeof(mmi_uc_frm_full_text_screen_struct));
        detail_screen->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        detail_screen->uc_gid = g_uc_p->main.uc_cui_gid;
        detail_screen->scrn_id = detail_screen->scrDB->scrn_id;
        detail_screen->get_string_buffer = mmi_uc_frm_sh_msg_detail_get_data;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)detail_screen);

        return MMI_TRUE;
    }
    return MMI_FALSE;   /* From history  */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_attachment_list_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_attachment_list_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_single_buffer_list_screen_struct *list_scr =
        (mmi_uc_frm_single_buffer_list_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_scr == NULL)
    {
        list_scr =
            (mmi_uc_frm_single_buffer_list_screen_struct*)
            OslMalloc(sizeof(mmi_uc_frm_single_buffer_list_screen_struct));
		ASSERT(list_scr);
		memset(list_scr, 0, sizeof(mmi_uc_frm_single_buffer_list_screen_struct));
        list_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        list_scr->scrn_id = list_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        list_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        list_scr->number_of_items = mmi_uc_frm_app_get_number_of_items;
        list_scr->list_of_items = mmi_uc_frm_app_get_attachment_item_list_for_menu;
        list_scr->list_of_icons = mmi_uc_frm_app_get_general_icon_list;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)list_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_sending_mms_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_sending_mms_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_progress_meter_screen_struct *progress_meter_scr =
        (mmi_uc_frm_progress_meter_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (progress_meter_scr == NULL)
    {
        progress_meter_scr =
            (mmi_uc_frm_progress_meter_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_progress_meter_screen_struct));
		ASSERT(progress_meter_scr);
		memset(progress_meter_scr, 0, sizeof(mmi_uc_frm_progress_meter_screen_struct));
        progress_meter_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        progress_meter_scr->scrn_id = progress_meter_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        progress_meter_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        progress_meter_scr->get_string_buffer = mmi_uc_get_string_buffer_for_sending_progress;
        progress_meter_scr->get_progress_percent = mmi_uc_get_progress_for_sending_progress;
        progress_meter_scr->get_message_buffer = mmi_uc_get_message_buffer_for_sending_progress;
        progress_meter_scr->free_message_buffer = mmi_uc_free_message_buffer_for_sending_progress;
        progress_meter_scr->end_key_func = mmi_uc_abort_send_mms_by_end_key;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)progress_meter_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_content_editor_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_content_editor_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_content_editor_screen_struct *editor_scr =
        (mmi_uc_frm_content_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_uc_is_no_recepient())
    {
        g_uc_p->done.current_addr_index = 0;
    }
    else
    {
        g_uc_p->done.current_addr_index = MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted();
    }
    g_uc_p->send_info.curr_folder =
        (U16) mmi_uc_get_current_msg_box_type(g_uc_p->srv_send_info->existed_msg_id);
    if (editor_scr == NULL)
    {
        editor_scr =
            (mmi_uc_frm_content_editor_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_content_editor_screen_struct));
		ASSERT(editor_scr);
		memset(editor_scr, 0, sizeof(mmi_uc_frm_content_editor_screen_struct));
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        editor_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        editor_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        editor_scr->scrn_id = editor_scr->scrDB->scrn_id;
        editor_scr->editor_msg_type = mmi_uc_app_get_editor_msg_type_type;
		#ifdef __MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT__
			editor_scr->input_type = (S32) (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH);
		#else
			editor_scr->input_type = (S32) IMM_INPUT_TYPE_SENTENCE;
		#endif
        editor_scr->get_subject_strings = mmi_uc_get_subject_for_editor_screen;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		editor_scr->get_title_id = mmi_uc_get_title_for_editor_screen;
#else
        editor_scr->csk_func = mmi_uc_pre_entry_add_recipient;
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        editor_scr->end_key_func = mmi_uc_write_msg_end_key_hdlr;

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#ifdef __MMI_OP02_LEMEI__
		/*do not support FTE in lemei mms*/
	if(g_uc_p->srv_msg_type->MMS_edit_mode != MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
#endif
		{       
		memset(&editor_scr->editor_tool_bar, 0 , sizeof(mmi_uc_frm_toolbar_struct));

        editor_scr->editor_tool_bar.item_count = UC_EDITOR_FTE_TOOLBAR_OPERATION_TOTAL_NUM;

		editor_scr->editor_tool_bar.content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_SEND] = (PU8)get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
		editor_scr->editor_tool_bar.content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_RECIPIENT] = (PU8)GetImage(IMG_GLOBAL_TOOLBAR_ADD_CONTACT);
        editor_scr->editor_tool_bar.content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_OBJECT] = (PU8)GetImage(IMG_UC_FTE_ADD_OBJECT_ID);

		editor_scr->editor_tool_bar.disabled_content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_SEND] = (PU8)get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
		editor_scr->editor_tool_bar.disabled_content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_RECIPIENT] = (PU8)get_image(IMG_GLOBAL_TOOLBAR_ADD_CONTACT_DISABLED);
        editor_scr->editor_tool_bar.disabled_content_icon[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_OBJECT] = (PU8)get_image(IMG_UC_FTE_DISABLED_ADD_OBJECT_ID);;

        editor_scr->editor_tool_bar.string[UC_EDITOR_FTE_TOOLBAR_OPERATION_SEND] = (PU8)GetString(STR_GLOBAL_SEND);
		editor_scr->editor_tool_bar.string[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_RECIPIENT] = (PU8)GetString(STR_UC_ADD_RECIPIENT_ID);
        editor_scr->editor_tool_bar.string[UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_OBJECT] = (PU8)GetString(STR_UC_ADD_OBJECT_ID);

        editor_scr->editor_tool_bar.callback = mmi_uc_write_msg_toolbar_callback;
	}
#endif
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_slide_time_editor_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_slide_time_editor_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_scr == NULL)
    {
        editor_scr =
            (mmi_uc_frm_normal_editor_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_normal_editor_screen_struct));
		ASSERT(editor_scr);
		memset(editor_scr, 0, sizeof(mmi_uc_frm_normal_editor_screen_struct));
        editor_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.editor_cui_id)
        {
            editor_scr->uc_gid = g_uc_p->main.editor_cui_id;
        }
        editor_scr->uc_gid = g_uc_p->main.editor_cui_id;
        editor_scr->scrn_id = editor_scr->scrDB->scrn_id;
        editor_scr->get_input_type = mmi_uc_app_get_slide_time_input_type;
        editor_scr->get_editor_filters = mmi_uc_app_get_slide_time_editor_filters;
        editor_scr->get_max_buffer_length = mmi_uc_get_slide_time_editor_max_buffer_length;
        editor_scr->get_editor_buffer = mmi_uc_get_slide_time_editor_buffer_for_work;
        editor_scr->set_first_entry_editor_environment =
            mmi_uc_set_slide_time_set_first_entry_editor_environment_for_work;
        editor_scr->csk_func = mmi_uc_entry_slide_timing_done;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_recipient_editor_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_recipient_editor_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_scr == NULL)
    {
        editor_scr =
            (mmi_uc_frm_normal_editor_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_normal_editor_screen_struct));
        ASSERT(editor_scr);
		memset(editor_scr, 0, sizeof(mmi_uc_frm_normal_editor_screen_struct));
        editor_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        editor_scr->scrn_id = editor_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.editor_cui_id)
        {
            editor_scr->uc_gid = g_uc_p->main.editor_cui_id;
        }
        editor_scr->get_input_type = mmi_uc_app_get_recipiet_input_type;
        editor_scr->get_editor_filters = mmi_uc_app_get_recipient_editor_filters;
        editor_scr->get_editor_filter_for_input_mode = mmi_uc_app_get_recipient_editor_filters_for_input_mode;
        editor_scr->get_max_buffer_length = mmi_uc_get_recipient_editor_max_buffer_length;
        editor_scr->get_editor_buffer = mmi_uc_get_recipient_editor_buffer_for_work;
        editor_scr->set_first_entry_editor_environment =
            mmi_uc_set_recipient_set_first_entry_editor_environment_for_work;
        editor_scr->csk_func = mmi_uc_enter_recipient_done;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_subject_editor_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_subject_editor_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_normal_editor_screen_struct *editor_scr =
        (mmi_uc_frm_normal_editor_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_scr == NULL)
    {
        editor_scr =
            (mmi_uc_frm_normal_editor_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_normal_editor_screen_struct));
        ASSERT(editor_scr);
		memset(editor_scr, 0, sizeof(mmi_uc_frm_normal_editor_screen_struct));
        editor_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        editor_scr->scrn_id = editor_scr->scrDB->scrn_id;
        if (g_uc_p->main.editor_cui_id == GRP_ID_UNIFIED_COMPOSER_EDITOR_CUI)
        {
            editor_scr->uc_gid = g_uc_p->main.editor_cui_id;
        }
        else
        {
            editor_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        }
        
        editor_scr->get_input_type = mmi_uc_app_get_subject_input_type;
        editor_scr->get_editor_filters = mmi_uc_app_get_subject_editor_filters;
        editor_scr->get_editor_filter_for_input_mode = mmi_uc_app_get_subject_editor_filters_for_input_mode;
        editor_scr->get_max_buffer_length = mmi_uc_get_subject_editor_max_buffer_length;
        editor_scr->get_editor_buffer = mmi_uc_get_editor_buffer_for_work;
        editor_scr->set_first_entry_editor_environment = mmi_uc_set_first_entry_editor_environment_for_work;
        editor_scr->csk_func = mmi_uc_input_method_and_done_go_back_to_option;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_object_timing_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_object_timing_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_inline_selection_screen_struct *setting_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_scr = (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    if (setting_scr == NULL)
    {
        setting_scr =
            (mmi_uc_frm_inline_selection_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_inline_selection_screen_struct));
        ASSERT(setting_scr);
		memset(setting_scr, 0, sizeof(mmi_uc_frm_inline_selection_screen_struct));
        setting_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        setting_scr->scrn_id = setting_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.inline_cui_id)
        {
            setting_scr->uc_gid = g_uc_p->main.inline_cui_id;
        }
        setting_scr->num_of_items = mmi_uc_frm_get_num_of_items_for_inline_screen_based_on_instance_id(instance_hash_id);
        setting_scr->image_list_icons = mmi_uc_frm_app_callback_slide_timing_list_of_icon;
        setting_scr->inline_items = mmi_uc_frm_app_callback_slide_timing_item_list;
        if (g_uc_p->srv_msg->best_page_duration)
        {
            setting_scr->lsk_done_func = mmi_uc_entry_timing_check_before_done;
            setting_scr->rsk_done_func = mmi_uc_entry_timing_check_before_done;
        }
        else
        {
            setting_scr->lsk_done_func = mmi_uc_entry_timing_done;
            setting_scr->rsk_done_func = mmi_uc_entry_timing_done;
        }
        setting_scr->rsk_back_func = mmi_frm_scrn_close_active_id;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)setting_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_send_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_send_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_inline_selection_screen_struct *setting_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_scr = (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    if (setting_scr == NULL)
    {
        setting_scr =
            (mmi_uc_frm_inline_selection_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_inline_selection_screen_struct));
        ASSERT(setting_scr);
		memset(setting_scr, 0, sizeof(mmi_uc_frm_inline_selection_screen_struct));
        setting_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        setting_scr->scrn_id = setting_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.inline_cui_id)
        {
            setting_scr->uc_gid = g_uc_p->main.inline_cui_id;
        }
        setting_scr->num_of_items = mmi_uc_frm_get_num_of_items_for_inline_screen_based_on_instance_id(instance_hash_id);
        setting_scr->image_list_icons = mmi_uc_frm_app_callback_send_opt_list_of_icon;
        setting_scr->inline_items = mmi_uc_frm_app_callback_send_opt_item_list;
        setting_scr->lsk_done_func = NULL;
        setting_scr->rsk_done_func = mmi_uc_send_opt_done_hdlr;
        setting_scr->rsk_back_func = mmi_uc_frm_sh_static_list_rsk_handler;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)setting_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_recipient_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_recipient_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_dynamic_screen_struct *dynamic_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_scr = (mmi_uc_frm_dynamic_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    if (dynamic_scr == NULL)
    {
        dynamic_scr = (mmi_uc_frm_dynamic_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_dynamic_screen_struct));
        ASSERT(dynamic_scr);
		memset(dynamic_scr, 0, sizeof(mmi_uc_frm_dynamic_screen_struct));
        dynamic_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        dynamic_scr->scrn_id = dynamic_scr->scrDB->scrn_id;
        if (g_uc_p->main.parent_grp_id == GRP_ID_UNIFIED_COMPOSER)
        {
            dynamic_scr->uc_gid = g_uc_p->main.parent_grp_id;
        }
        else
        {
            dynamic_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        }
        dynamic_scr->set_data_for_recipient_list = mmi_uc_callback_set_data_for_recipient_list;
        dynamic_scr->fixed_list_register_get_flags = mmi_uc_set_dynamic_list_separator_line;
        dynamic_scr->number_of_item = mmi_uc_get_num_of_items_for_add_recipient_menu;
		#ifdef __UC_ASYNC_DYNAMIC_LIST__
		dynamic_scr->get_item_cb = mmi_uc_async_addr_list_get_item_ext;
		#else
        dynamic_scr->get_item_cb = mmi_uc_addr_list_get_item_ext;
		#endif
        dynamic_scr->get_hilighted_item = mmi_uc_get_hilited_item_for_add_recipient;
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        dynamic_scr->tap_func = mmi_uc_fte_tap_handling_on_add_recipient_callback;
    #endif /* __MMI_FTE_SUPPORT__*/
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)dynamic_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_uc_editor_option_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_uc_editor_option_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_editor_option_screen_struct *editor_opt_scr =
        (mmi_uc_frm_editor_option_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_opt_scr == NULL)
    {
        editor_opt_scr =
            (mmi_uc_frm_editor_option_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_editor_option_screen_struct));
        ASSERT(editor_opt_scr);
		memset(editor_opt_scr, 0, sizeof(mmi_uc_frm_editor_option_screen_struct));
        editor_opt_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        editor_opt_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        editor_opt_scr->scrn_id = editor_opt_scr->scrDB->scrn_id;
        editor_opt_scr->set_data_for_editor_option = NULL;
        editor_opt_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        editor_opt_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        editor_opt_scr->list_of_descriptions = NULL;    /* mmi_uc_frm_app_static_menu_list_of_descriptions; */
        editor_opt_scr->f_close = mmi_uc_entry_input_method_done;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_opt_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
MMI_BOOL mmi_uc_frm_app_ui_plug_in_header_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
		ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = mmi_uc_frm_app_static_menu_list_of_descriptions;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_enter_recipient_option_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_enter_recipient_option_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_editor_option_screen_struct *editor_opt_scr =
        (mmi_uc_frm_editor_option_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_opt_scr == NULL)
    {
        editor_opt_scr =
            (mmi_uc_frm_editor_option_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_editor_option_screen_struct));
        ASSERT(editor_opt_scr);
		memset(editor_opt_scr, 0, sizeof(mmi_uc_frm_editor_option_screen_struct));
        editor_opt_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        editor_opt_scr->scrn_id = editor_opt_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        editor_opt_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        editor_opt_scr->set_data_for_editor_option = mmi_uc_frm_app_enter_recipient_option_set_data_for_editor_option;
        editor_opt_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        editor_opt_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        editor_opt_scr->list_of_descriptions = NULL;    /* mmi_uc_frm_app_static_menu_list_of_descriptions; */
        editor_opt_scr->f_close = mmi_frm_go_back_2_history;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_opt_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_exit_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_exit_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_write_msg_selection_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_write_msg_selection_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        /*if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }*/
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = mmi_uc_frm_app_set_data_for_write_msg_selection;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = mmi_uc_frm_app_static_menu_list_of_descriptions;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_remove_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_remove_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_replace_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_replace_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_opt_slide_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_opt_slide_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_text_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_text_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_opt_picture_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_opt_picture_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_opt_sound_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_opt_sound_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_opt_video_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_opt_video_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_advanced_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_advanced_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_picture_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_picture_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_sound_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_sound_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_video_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_video_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_recipient_options_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_recipient_options_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

 #if(MMI_MAX_SIM_NUM >=2)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_sim_opt_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_sim_opt_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = mmi_uc_frm_app_set_data_for_sim_option;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;
		static_scr->hilighted_item = mmi_uc_frm_app_send_hilighted_sim_id();

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_preview_screen_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_preview_screen_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_is_back_empty_body_screen_struct *static_scr =
        (mmi_uc_frm_is_back_empty_body_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr =
            (mmi_uc_frm_is_back_empty_body_screen_struct*)
            OslMalloc(sizeof(mmi_uc_frm_is_back_empty_body_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_is_back_empty_body_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->is_back_process_handle = mmi_uc_frm_app_preview_is_back_handling;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_input_method_and_done_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_input_method_and_done_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_editor_option_screen_struct *editor_opt_scr =
        (mmi_uc_frm_editor_option_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_opt_scr == NULL)
    {
        editor_opt_scr =
            (mmi_uc_frm_editor_option_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_editor_option_screen_struct));
        ASSERT(editor_opt_scr);
		memset(editor_opt_scr, 0, sizeof(mmi_uc_frm_editor_option_screen_struct));
        editor_opt_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        editor_opt_scr->scrn_id = editor_opt_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        editor_opt_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        editor_opt_scr->set_data_for_editor_option = NULL;
        editor_opt_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        editor_opt_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        editor_opt_scr->list_of_descriptions = NULL;    /* mmi_uc_frm_app_static_menu_list_of_descriptions; */
        editor_opt_scr->f_close = mmi_frm_go_back_2_history;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)editor_opt_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_recipient_address_editor_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_recipient_address_editor_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_inline_selection_screen_struct *setting_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_scr = (mmi_uc_frm_inline_selection_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    if (setting_scr == NULL)
    {
        setting_scr =
            (mmi_uc_frm_inline_selection_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_inline_selection_screen_struct));
        ASSERT(setting_scr);
		memset(setting_scr, 0, sizeof(mmi_uc_frm_inline_selection_screen_struct));
        setting_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        setting_scr->scrn_id = setting_scr->scrDB->scrn_id;
        if (mmi_frm_group_get_active_id() == g_uc_p->main.inline_cui_id)
        {
            setting_scr->uc_gid = g_uc_p->main.inline_cui_id;
        }
        setting_scr->num_of_items = mmi_uc_frm_get_num_of_items_for_inline_screen_based_on_instance_id(instance_hash_id);
        setting_scr->image_list_icons = NULL;
        setting_scr->inline_items = mmi_uc_frm_app_callback_recipient_address_editor_item_list;
        setting_scr->lsk_done_func = NULL;
        setting_scr->rsk_done_func = mmi_postcard_validate_recipient_address_data;
        setting_scr->rsk_back_func = mmi_frm_scrn_close_active_id;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)setting_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_entry_multiple_recipient_option_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_entry_multiple_recipient_option_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = mmi_uc_frm_app_set_data_for_multiple_recipient_option_in_postcard;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_MMS_POSTCARD__ */ 

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_enter_multimedia_screen_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_enter_multimedia_screen_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_is_back_empty_body_screen_struct *static_scr =
        (mmi_uc_frm_is_back_empty_body_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr =
            (mmi_uc_frm_is_back_empty_body_screen_struct*)
            OslMalloc(sizeof(mmi_uc_frm_is_back_empty_body_screen_struct));
        ASSERT(static_scr);
		memset(static_scr, 0, sizeof(mmi_uc_frm_is_back_empty_body_screen_struct));
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->is_back_process_handle = mmi_uc_frm_app_enter_multimedia_is_back_handling;
        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_entry_add_object_option_pre_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_entry_add_object_option_pre_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_static_screen_struct *static_scr =
        (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (static_scr == NULL)
    {
        static_scr = (mmi_uc_frm_static_screen_struct*) OslMalloc(sizeof(mmi_uc_frm_static_screen_struct));
        ASSERT(static_scr);
        memset(static_scr, 0, sizeof(mmi_uc_frm_static_screen_struct));
        static_scr->scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);
        if (mmi_frm_group_get_active_id() == g_uc_p->main.parent_grp_id)
        {
            g_uc_p->main.uc_cui_gid = g_uc_p->main.parent_grp_id;
            g_uc_p->main.parent_grp_id = GRP_ID_INVALID;
        }
        static_scr->uc_gid = g_uc_p->main.uc_cui_gid;
        static_scr->scrn_id = static_scr->scrDB->scrn_id;
        static_scr->set_data_for_menu_list = NULL;
        static_scr->set_title = NULL;
        static_scr->list_of_items = mmi_uc_frm_app_static_menu_item_list;
        static_scr->list_of_icons = mmi_uc_frm_app_static_menu_icon_list;
        static_scr->list_of_descriptions = NULL;

        mmi_uc_frm_sh_set_screen_context(instance_hash_id, (void*)static_scr);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_FTE_SUPPORT__ */
/*------------------------------------Post Functions ----------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_progress_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_progress_post_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(instance_hash_id);
    return MMI_TRUE;
}

/* Special to content editor */


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_content_editor_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_content_editor_post_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_CONFIRM);
    /* In order to simplify popup string and let user can get important info, will ignore insignificant notification */
    if (g_uc_p->srv_send_info->content_truncated_type &&
        g_uc_p->srv_send_info->existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && !g_uc_p->send_info.need_to_skip_popup)
    {
        S32 msg_folder = (S32) mma_get_box(g_uc_p->srv_send_info->existed_msg_id);

        if (g_uc_p->srv_main->state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            (g_uc_p->srv_main->state == SRV_UC_STATE_WRITE_NEW_MSG &&
             (msg_folder == MMA_FOLDER_ARCHIVE || msg_folder == MMA_FOLDER_TEMPLATE ||
              msg_folder == MMA_FOLDER_USRDEF_TEMPLATE)))
        {
            mmi_uc_display_truncated_information_popup();
        }
        else
        {
            g_uc_p->srv_send_info->content_truncated_type = (srv_uc_msg_truncation_type_enum)0;
        }
    }
    else if (SRV_UC_INSERT_RESULT_FAIL == g_uc_p->srv_msg->fail_to_insert_signature)
    {
        StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_signature_insertion_fail);
    }
    else if (SRV_UC_INSERT_RESULT_FILE_NOT_EXIST == g_uc_p->srv_msg->fail_to_insert_signature)
    {
        StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_signature_object_missed);
    }
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    else if(g_uc_p->main.max_recipient_fields == 1)
    {
        StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_display_max_fields);
        g_uc_p->main.max_recipient_fields = 0;
    }
    else if(g_uc_p->main.max_recipient_fields == 2)
    {
        g_uc_p->main.max_recipient_fields--;
    }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    g_uc_p->done.pre_msg_type = g_uc_p->srv_msg_type->curr_msg_type;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_generic_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_generic_post_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(instance_hash_id);
    return MMI_TRUE;
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_add_recipient_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_add_recipient_post_func(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(instance_hash_id);
    mmi_uc_set_group_id();
    StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_handle_msg_type_check);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_ui_plug_in_subject_editor_post_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_frm_app_ui_plug_in_subject_editor_post_func(U16 instance_hash_id)
{
#if defined(__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_input_ext_type |= mmi_uc_app_get_subject_editor_filters();
#elif defined(__MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__)
    MMI_current_input_ext_type |= mmi_uc_app_get_subject_editor_filters();
#endif 
    mmi_uc_frm_sh_delete_screen_context(instance_hash_id);
    return MMI_TRUE;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
/*------------------------------- Highlight Handlers ------------------------------------------------*/

/* void mmi_uc_frm_sh_static_list_hilite_handler(S32 index)
   {
   mmi_uc_frm_static_screen_struct* static_scr;
   mmi_uc_frm_screenDB_struct* scrDB = mmi_frm_get_current_screen_argument();
   static_scr = (mmi_uc_frm_static_screen_struct*) mmi_uc_frm_sh_get_scr_context(scrDB->instance_hash_id);
   static_scr->hilighted_item = index;
   
   
   } */


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_attachment_option_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_attachment_option_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_sh_add_recipient_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_uc_dummy_api(void)
{

}
void mmi_uc_frm_app_sh_add_recipient_hilite_handler(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //const mmi_uc_frm_screenDB_struct *scrDB = mmi_frm_get_current_screen_argument();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex < (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()))
    {
        if (nIndex == MMI_UC_ENTER_RECIPIENT)
        {
            /* use g_uc_p->done.to buffer to store phone number */
            /* here use MMI_UC_MAX_EMAIL_LEN, because to declare as MMI_UC_MAX_EMAIL_LEN */
            gdi_layer_lock_frame_buffer();
            ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
            gdi_layer_unlock_frame_buffer();
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            
            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            g_uc_p->done.current_addr_index = nIndex;
			SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
        #ifdef __MMI_MMS_POSTCARD__
            if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
            {
                SetLeftSoftkeyFunction(mmi_postcard_entry_import_manual, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_ENTER, KEY_LONG_PRESS);
                SetCenterSoftkeyFunction(mmi_postcard_entry_import_manual, KEY_EVENT_UP);
            }
            else
        #endif /* __MMI_MMS_POSTCARD__ */ 
            {
                SetLeftSoftkeyFunction(mmi_uc_entry_enter_recipient, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_ENTER, KEY_LONG_PRESS);
                SetCenterSoftkeyFunction(mmi_uc_entry_enter_recipient, KEY_EVENT_UP);
            }

            return;
        }
        else if (nIndex == MMI_UC_ADD_FROM_CONTACTS)
        {
            /* use g_uc_p->done.to buffer to store email */
            gdi_layer_lock_frame_buffer();
            ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
            gdi_layer_unlock_frame_buffer();
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            g_uc_p->done.current_addr_index = nIndex;
			SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
        #ifdef __MMI_MMS_POSTCARD__
            if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
            {
            #ifdef __MMI_PHB_INFO_FIELD__
                SetLeftSoftkeyFunction(mmi_postcard_entry_import_phonebook, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_ENTER, KEY_LONG_PRESS);
                SetCenterSoftkeyFunction(mmi_postcard_entry_import_phonebook, KEY_EVENT_UP);
            #endif /* __MMI_PHB_INFO_FIELD__ */ 
            }
            else
        #endif /* __MMI_MMS_POSTCARD__ */ 
            {
                SetLeftSoftkeyFunction(mmi_uc_search_phb_recipient, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);
                ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_ENTER, KEY_LONG_PRESS);
                SetCenterSoftkeyFunction(mmi_uc_search_phb_recipient, KEY_EVENT_UP);
            }
            return;
        }
    }
    else
    {
        g_uc_p->done.current_addr_index = nIndex;
    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            srv_postcard_set_recipient_index(
                g_uc_p->main.instance,
                (S32) g_uc_p->done.current_addr_index - (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()));
        }
    #endif /* __MMI_MMS_POSTCARD__ */ 
        gdi_layer_lock_frame_buffer();
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        gdi_layer_unlock_frame_buffer();
        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        }
        else
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        }
        SetLeftSoftkeyFunction(mmi_uc_entry_add_recipients_options, KEY_EVENT_UP);

    #ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #if (MMI_MAX_SIM_NUM >=2)
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
                #if (defined(__OP01__) && defined(__MMI_DUAL_SIM_MASTER__))
/* under construction !*/
                #else
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
        #else  /* #if (MMI_MAX_SIM_NUM ==2) */ 
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
        #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
/* under construction !*/
    #else /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */ 
     #if (MMI_MAX_SIM_NUM >=2)
		if(g_uc_p->srv_sim_info->valid_sim_id_info ==SRV_UC_SIM_ID_UNCLASSIFIED)
		{
				if(g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
				{
					memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
					SetCenterSoftkeyFunction(mmi_uc_pre_entry_edit_addr, KEY_EVENT_UP);
					SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
				}
				else
				{
					SetCenterSoftkeyFunction(mmi_uc_entry_send_opt_inline_cui, KEY_EVENT_UP);
					SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
				}
		}
		else
		{
			SetCenterSoftkeyFunction(mmi_uc_pre_entry_sim_option_csk, KEY_EVENT_UP);
			g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SEND;
			SetKeyHandler(mmi_uc_pre_entry_sim_option_csk, KEY_SEND, KEY_EVENT_UP);
		}
    #else  /* #if (MMI_MAX_SIM_NUM ==2) */
		if(g_uc_p->srv_sim_info->valid_sim_id_info ==SRV_UC_SIM_ID_UNCLASSIFIED)
		{
				if(g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
				{
					memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
					SetCenterSoftkeyFunction(mmi_uc_pre_entry_edit_addr, KEY_EVENT_UP);
					SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
				}
				else
				{
					SetCenterSoftkeyFunction(mmi_uc_entry_send_opt_inline_cui, KEY_EVENT_UP);
					SetKeyHandler(mmi_uc_dummy_api, KEY_SEND, KEY_EVENT_UP);
				}
		}
		else
		{
			SetCenterSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
			SetKeyHandler(mmi_uc_process_send, KEY_SEND, KEY_EVENT_UP);
		}
    #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
    #endif /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */
    #ifdef __MMI_TOUCH_SCREEN__
        register_center_softkey_to_enter_key();
    #endif 
        return;
    }
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_sh_editor_option_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_sh_editor_option_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_uc_frm_editor_option_screen_struct *editor_opt_scr;
    //const mmi_uc_frm_screenDB_struct *scrDB = mmi_frm_get_current_screen_argument();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //editor_opt_scr = (mmi_uc_frm_editor_option_screen_struct*) mmi_uc_frm_sh_get_scr_context(scrDB->instance_hash_id);
    //editor_opt_scr->hilighted_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_sh_input_method_and_done_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_sh_input_method_and_done_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_uc_input_method_and_done_go_back_to_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_input_method_and_done_go_back_to_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_frm_highlight_input_method_generic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_input_method_and_done_hilite_handler
 * DESCRIPTION
 *  Highlighter to options on subject editor
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_input_method_and_done_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {

        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_uc_input_method_and_done_go_back_to_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_input_method_and_done_go_back_to_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    }
    else
    {
        mmi_frm_highlight_input_method_generic();
    }
}

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
