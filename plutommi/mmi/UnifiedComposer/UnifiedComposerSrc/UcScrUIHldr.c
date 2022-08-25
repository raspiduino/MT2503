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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

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
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_icon_bar.h"
#endif

#ifdef __MMI_MMS_POSTCARD__
#include "UcPcrdProt.h"
#endif /* #ifdef __MMI_MMS_POSTCARD__ */
#include "UcResDef.h"
#include "UcAppGprot.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcScrUIProt.h"

#include "MenuCuiGprot.h"
#include "MMIDataType.h"
#include "smscuigprot.h"
//suggested add
    #include "MMI_features.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "UcSrvGprot.h"
    #include "mma_struct.h"
    //#include "kal_general_types.h"
    //#include "kal_public_api.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "mmi_frm_history_gprot.h"
    #include "GlobalResDef.h"
    #include "customer_email_num.h"
    #include "string.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_scenario_gprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_UCM__)
#define __MMI_UC_SUPPORT_SOUNDRECORDER_IN_UCM__ 1
#endif 
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

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*---------------------------------Highlight Handlers----------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_write_msg_selection
 * DESCRIPTION
 *  Funtion is called when write mms msg menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_write_msg_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_write_msg_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_exit_opt_exit
 * DESCRIPTION
 *  Funtion is called when exit item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_exit_opt_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_discard_msg_before_exit_write_msg, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_send
 * DESCRIPTION
 *  Funtion is called when send menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (MMI_MAX_SIM_NUM ==2) 
    g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SEND;
#endif 

#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
     #if (MMI_MAX_SIM_NUM >=2)
/* under construction !*/
    #else  /* #if (MMI_MAX_SIM_NUM ==2) */ 
/* under construction !*/
    #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
/* under construction !*/
#else /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */ 
 #if (MMI_MAX_SIM_NUM >=2)
    SetLeftSoftkeyFunction(mmi_uc_pre_entry_sim_option, KEY_EVENT_UP);
#else  /* #if (MMI_MAX_SIM_NUM ==2) */ 
    SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
#endif /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */ 
    return;
}

#if defined(__MMI_MMS_TEMPLATE_SUPPORT__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_save_as_template
 * DESCRIPTION
 *  Funtion is called when save as template menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_process_save_as_template, KEY_EVENT_UP);
    return;
}
#endif /* defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_send_opt
 * DESCRIPTION
 *  Funtion is called when send option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_send_opt, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_write_sel_message
 * DESCRIPTION
 *  Funtion is called when write message item of write option is selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_write_sel_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_NORMAL_MMS;

    SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_write_sel_mms_postcard
 * DESCRIPTION
 *  Funtion is called when write postcard item of write option is selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_write_sel_mms_postcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_uc_p->srv_msg_type->caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY; */
    g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS;

    SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);

}
#endif /* __MMI_MMS_POSTCARD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_image
 * DESCRIPTION
 *  Funtion is called when insert image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_audio
 * DESCRIPTION
 *  Funtion is called when insert audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_video
 * DESCRIPTION
 *  Funtion is called when insert video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_attachment
 * DESCRIPTION
 *  Funtion is called when insert attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_bookmark
 * DESCRIPTION
 *  Funtion is called when insert bookmark menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

    SetLeftSoftkeyFunction(mmi_uc_entry_insert_bookmark, KEY_EVENT_UP);
    return;
}
#endif

#if defined(__MMI_MESSAGES_TEMPLATE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_text_template
 * DESCRIPTION
 *  Funtion is called when insert attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_text_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

    SetLeftSoftkeyFunction(mmi_sms_entry_template_list, KEY_EVENT_UP);
    return;
}
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_phb_number
 * DESCRIPTION
 *  Funtion is called when insert phb number menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

    SetLeftSoftkeyFunction(mmi_uc_entry_insert_phb_number, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_phb_name
 * DESCRIPTION
 *  Funtion is called when insert phb name menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_phb_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

    SetLeftSoftkeyFunction(mmi_uc_entry_insert_phb_name, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_CAMERA__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_image
 * DESCRIPTION
 *  Funtion is called when insert new image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;
#ifdef __MMI_UCM__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        SetLeftSoftkeyFunction(mmi_ucm_app_entry_error_message, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_UCM__ */ 
    {
        SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    }
    return;
}
#endif /* __MMI_CAMERA__ */ 

#ifdef __MMI_SOUND_RECORDER__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_audio
 * DESCRIPTION
 *  Funtion is called when insert new audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;
#if defined(__MMI_UCM__) && !defined (__MMI_UC_SUPPORT_SOUNDRECORDER_IN_UCM__)
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {

        SetLeftSoftkeyFunction(mmi_ucm_app_entry_error_message, KEY_EVENT_UP);
    }
    else
#endif /* defined(__MMI_UCM__) && !defined (__MMI_UC_SUPPORT_SOUNDRECORDER_IN_UCM__) */ 
    {

        SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    }
    return;
}
#endif /* __MMI_SOUND_RECORDER__ */ 

#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_video
 * DESCRIPTION
 *  Funtion is called when insert new video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;
#ifdef __MMI_UCM__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {

        SetLeftSoftkeyFunction(mmi_ucm_app_entry_error_message, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_UCM__ */ 
    {
        SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    }
    return;
}
#endif /* defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE) */ 
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_image
 * DESCRIPTION
 *  Funtion is called when remove image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;

    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_audio
 * DESCRIPTION
 *  Funtion is called when remove audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;

    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_video
 * DESCRIPTION
 *  Funtion is called when remove video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;

    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_attachment
 * DESCRIPTION
 *  Funtion is called when remove attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;

    SetLeftSoftkeyFunction(mmi_uc_opt_attachment_option_remove, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_image
 * DESCRIPTION
 *  Funtion is called when replace image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_audio
 * DESCRIPTION
 *  Funtion is called when replace audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_video
 * DESCRIPTION
 *  Funtion is called when replace video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;

    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_attachment
 * DESCRIPTION
 *  Funtion is called when replace attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;

    SetLeftSoftkeyFunction(mmi_uc_opt_attachment_option_replace, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_UC_REPLACE_MEDIA_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_insert
 * DESCRIPTION
 *  Funtion is called when insert slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_slide, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_insert_before
 * DESCRIPTION
 *  Funtion is called when insert slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_insert_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_slide_before, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_delete
 * DESCRIPTION
 *  Funtion is called when delete slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_delete_slide, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_previous
 * DESCRIPTION
 *  Funtion is called when previous slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_previous_slide, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_next
 * DESCRIPTION
 *  Funtion is called when next slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_next_slide, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_timing
 * DESCRIPTION
 *  Funtion is called when slide timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2__
    if ((!g_uc_p->srv_msg->best_page_duration) &&
        (g_uc_p->srv_msg->msg_body.curr_slide->duration > g_uc_p->srv_mms_info->sliding_time.max))
    {
        kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_mms_info->sliding_time.max);
    }
    else
    {
#endif /* __MMI_MMS_2__ */ 
        S8 j;
        U32 maxValue = 1;

        /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
        for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
        {
            maxValue = 10 * maxValue;
        }
        maxValue = maxValue - 1;
        if (g_uc_p->srv_msg->msg_body.curr_slide->duration > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_msg->msg_body.curr_slide->duration);
        }
    #ifdef __MMI_MMS_2__
    }
    #endif 
    SetLeftSoftkeyFunction(mmi_uc_entry_slide_timing, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_MMS_2__

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_text_timing
 * DESCRIPTION
 *  Funtion is called when text timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_text_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S8 j;
    U32 maxValue = 1;

    /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
    for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
    {
        maxValue = 10 * maxValue;
    }
    maxValue = maxValue - 1;
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

    if (g_uc_p->srv_msg->msg_body.curr_slide->txt.begin != SRV_UC_INVALID_VALUE &&
        g_uc_p->srv_msg->msg_body.curr_slide->txt.end != SRV_UC_INVALID_VALUE)
    {
        if (g_uc_p->srv_msg->msg_body.curr_slide->txt.begin > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_msg->msg_body.curr_slide->txt.begin);
        }
        if (g_uc_p->srv_msg->msg_body.curr_slide->txt.end > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);     /* reuse slide_number buffer! */
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->txt.end);     /* reuse slide_number buffer! */
        }
    }
    else
    {
        kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", 0);
        if (g_uc_p->srv_msg->msg_body.curr_slide->duration > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->duration);     /* reuse slide_number buffer! */
        }
    }

    SetLeftSoftkeyFunction(mmi_uc_show_text_timing, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_image_timing
 * DESCRIPTION
 *  Funtion is called when image timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_image_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S8 j;
    U32 maxValue = 1;

    /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
    for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
    {
        maxValue = 10 * maxValue;
    }
    maxValue = maxValue - 1;
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;

    if (g_uc_p->srv_msg->msg_body.curr_slide->img.begin != SRV_UC_INVALID_VALUE &&
        g_uc_p->srv_msg->msg_body.curr_slide->img.end != SRV_UC_INVALID_VALUE)
    {
        if (g_uc_p->srv_msg->msg_body.curr_slide->img.begin > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_msg->msg_body.curr_slide->img.begin);
        }
        if (g_uc_p->srv_msg->msg_body.curr_slide->img.end > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->img.end);    /* reuse slide_number buffer! */
        }
    }
    else
    {
        kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", 0);
        if (g_uc_p->srv_msg->msg_body.curr_slide->duration > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->duration);     /* reuse slide_number buffer! */
        }
    }

    SetLeftSoftkeyFunction(mmi_uc_show_image_timing, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_video_timing
 * DESCRIPTION
 *  Funtion is called when video timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_video_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S8 j;
    U32 maxValue = 1;

    /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
    for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
    {
        maxValue = 10 * maxValue;
    }
    maxValue = maxValue - 1;
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;

    if (g_uc_p->srv_msg->msg_body.curr_slide->vid.begin != SRV_UC_INVALID_VALUE &&
        g_uc_p->srv_msg->msg_body.curr_slide->vid.end != SRV_UC_INVALID_VALUE)
    {
        if (g_uc_p->srv_msg->msg_body.curr_slide->vid.begin > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_msg->msg_body.curr_slide->vid.begin);
        }
        if (g_uc_p->srv_msg->msg_body.curr_slide->vid.end > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->vid.end);    /* reuse slide_number buffer! */
        }
    }
    else
    {
        kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", 0);
        if (g_uc_p->srv_msg->msg_body.curr_slide->duration > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->duration);     /* reuse slide_number buffer! */
        }
    }

    SetLeftSoftkeyFunction(mmi_uc_show_video_timing, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_audio_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_audio_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S8 j;
    U32 maxValue = 1;

    /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
    for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
    {
        maxValue = 10 * maxValue;
    }
    maxValue = maxValue - 1;
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;

    if (g_uc_p->srv_msg->msg_body.curr_slide->aud.begin != SRV_UC_INVALID_VALUE &&
        g_uc_p->srv_msg->msg_body.curr_slide->aud.end != SRV_UC_INVALID_VALUE)
    {
        if (g_uc_p->srv_msg->msg_body.curr_slide->aud.begin > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", g_uc_p->srv_msg->msg_body.curr_slide->aud.begin);
        }
        if (g_uc_p->srv_msg->msg_body.curr_slide->aud.end > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->aud.end);    /* reuse slide_number buffer! */
        }
    }
    else
    {
        kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", 0);
        if (g_uc_p->srv_msg->msg_body.curr_slide->duration > maxValue)
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue);
        }
        else
        {
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", g_uc_p->srv_msg->msg_body.curr_slide->duration);     /* reuse slide_number buffer! */
        }
    }

    SetLeftSoftkeyFunction(mmi_uc_show_audio_timing, KEY_EVENT_UP);
    return;
}
#endif
#endif /* __MMI_MMS_2__ */ 

#ifdef __MMI_PHOTOEDITOR__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_edit_image
 * DESCRIPTION
 *  Funtion is called when edit image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_edit_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;
    SetLeftSoftkeyFunction(mmi_uc_enter_edit_image, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_PHOTOEDITOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_remove
 * DESCRIPTION
 *  Funtion is called when remove menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_remove, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_replace
 * DESCRIPTION
 *  Funtion is called when replace menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_replace, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_replace, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_UC_REPLACE_MEDIA_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_slide_opt
 * DESCRIPTION
 *  Funtion is called when slide option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_slide_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_slide_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_slide_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_send_opt
 * DESCRIPTION
 *  Funtion is called when send option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_send_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_send_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_msg_detail
 * DESCRIPTION
 *  Funtion is called when msg detail menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_msg_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_msg_detail, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_msg_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_input_method
 * DESCRIPTION
 *  Funtion is called when input method menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_UC_ENTRY_SCRN_CAPTION_ID);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_uc_entry_input_method_done);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_preview
 * DESCRIPTION
 *  Funtion is called when preview menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_preview, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_preview, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_add_subject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_add_subject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_edit_subject_editor_cui, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_edit_subject_editor_cui, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_send_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_send_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_add_recipient, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_add_recipient, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_save_as_template
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_process_save_as_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_save_as_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (MMI_MAX_SIM_NUM ==2)
    g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SEND;
#endif 

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
    #else  /* #if (MMI_MAX_SIM_NUM ==2) */ 
/* under construction !*/
/* under construction !*/
    #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
/* under construction !*/
#else /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */ 
 #if (MMI_MAX_SIM_NUM >=2)
    SetLeftSoftkeyFunction(mmi_uc_pre_entry_sim_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_pre_entry_sim_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else  /* #if (MMI_MAX_SIM_NUM ==2) */ 
    SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
#endif /* __MMS_SIZE_CONFIRM_BEFORE_SEND__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_change_msg_type_to_mms
 * DESCRIPTION
 *  highlight handler to change msg type to MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_change_msg_type_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_change_msg_type_to_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_change_msg_type_to_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_change_msg_type_to_sms
 * DESCRIPTION
 *  highlight handler to change to msg type to SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_change_msg_type_to_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_change_msg_type_to_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_change_msg_type_to_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_text_options
 * DESCRIPTION
 *  highlight handler to show text options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_text_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_text_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_text_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif  /*__MMI_SLIM_MMS_2__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_picture_options
 * DESCRIPTION
 *  highlight handler for picture options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_picture_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_picture_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_picture_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_sound_options
 * DESCRIPTION
 *  highlight handler for sound options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_sound_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_sound_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_sound_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_video_options
 * DESCRIPTION
 *  highlight handler for video options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_video_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_video_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_video_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_attachment_options
 * DESCRIPTION
 *  highlight handler for attachment options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_attachment_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_opt_attachment_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_opt_attachment_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_advance_options
 * DESCRIPTION
 *  highlight handler for advance options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_advance_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_advanced_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_advanced_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_add_picture
 * DESCRIPTION
 *  highlight handler for add picture options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_add_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_add_picture_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_add_picture_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_add_sound
 * DESCRIPTION
 *  hight handler for add sound option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_add_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_add_sound_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_add_sound_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#ifdef __MMI_MMS_VIDEO_FEATURE__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_add_video
 * DESCRIPTION
 *  highlight handler for add video options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_add_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_add_video_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_add_video_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_enter_recipient_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_enter_recipient_done(S32 index)
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
        SetLeftSoftkeyFunction(mmi_uc_enter_recipient_done, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_enter_recipient_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_frm_highlight_input_method_generic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_edit_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_edit_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_edit, KEY_EVENT_UP);
        SetKeyHandler(mmi_postcard_entry_to_option_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        /* use g_uc_p->done.to buffer to store edited address */
        memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

        SetLeftSoftkeyFunction(mmi_uc_pre_entry_edit_addr, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_pre_entry_edit_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_delete_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_delete_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_all_recipients
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_all_recipients(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_delete_all_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_delete_all_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_change_to_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_change_to_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_recipient_options_change_to_to, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_recipient_options_change_to_to, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_change_to_cc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_change_to_cc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_recipient_options_change_to_cc, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_recipient_options_change_to_cc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_change_to_bcc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_change_to_bcc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_recipient_options_change_to_bcc, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_recipient_options_change_to_bcc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_save_to_draft
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_save_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_pre_process_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_pre_process_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

 #if (MMI_MAX_SIM_NUM ==2)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_send_frm_sim1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_send_frm_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_send_info->send_sim_id = UC_SIM_ID_GSM_SIM1;
    if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SEND_AND_SAVE)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send_and_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SAVE)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SEND)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_send_frm_sim2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_send_frm_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_send_info->send_sim_id = UC_SIM_ID_GSM_SIM2;
    if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SEND_AND_SAVE)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send_and_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SAVE)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SEND)
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}

#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_add_signature, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_add_signature, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif

#ifndef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_exit_opt_save
 * DESCRIPTION
 *  Funtion is called when save item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_exit_opt_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (MMI_MAX_SIM_NUM ==2)
    g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SAVE;
#endif 
    SetLeftSoftkeyFunction(mmi_uc_save_msg_before_exit_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_save_msg_before_exit_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif

/*------------------------------Highlight handler for postcard--------------*/
#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_to_option_reset
 * DESCRIPTION
 *  Entry function of delete all query popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_to_option_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_setSoftkeyFunction(
        mmi_postcard_reset_all_recipients,
        mmi_frm_scrn_close_active_id,
        (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
        STR_UC_DELETE_ALL_ASK_ID);
    mmi_uc_entry_displayConfirm_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_to_option_delete
 * DESCRIPTION
 *  Entry function of delete query popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_to_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_setSoftkeyFunction(
        mmi_postcard_delete_one_recipient,
        mmi_frm_scrn_close_active_id,
        (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
        STR_UC_DELETE_ASK_ID);
    mmi_uc_entry_displayConfirm_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_to_option_done
 * DESCRIPTION
 *  Completion of all recipients
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_to_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* go back to send option screen */
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_POSTCARD_RECIPIENT_OPTION);
    //mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_POSTCARD_RECIPIENT_LIST);
      /* mmi_uc_pre_entry_done_option(); */
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_reset
 * DESCRIPTION
 *  Highlight handler of address editor option: delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_reset, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_delete
 * DESCRIPTION
 *  Highlight handler of address editor option: delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_delete, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_edit
 * DESCRIPTION
 *  Highlight handler of address editor option: edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_add
 * DESCRIPTION
 *  Highlight handler of address editor option: add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to be removed */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_done
 * DESCRIPTION
 *  Highlight handler of address editor option: done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_done, KEY_EVENT_UP);
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_import_manual
 * DESCRIPTION
 *  Highlight handler of import address manually
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_import_manual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_import_manual, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_import_phonebook
 * DESCRIPTION
 *  Highlight handler of import address from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_import_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_import_phonebook, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_highlight_to_option_save
 * DESCRIPTION
 *  Highlight handler of address editor option: save to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_highlight_to_option_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_postcard_entry_to_option_save, KEY_EVENT_UP);
}
#endif /* __MMI_PHB_INFO_FIELD__ */ 

#endif /* __MMI_MMS_POSTCARD__ */ 

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
