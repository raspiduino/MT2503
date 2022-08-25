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
 * UcScrUICb.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements all screen data feeder apis. It incorporate all application data provider for UI in Unified Composer.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"
#endif 

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_icon_bar.h"
#endif
//#include "PhoneBookResDef.h"
#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "SimCtrlSrvGprot.h"

//#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"

#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif 

#if defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    #include "CameraGprot.h"
#endif
#if defined(__MMI_CAMCORDER__)    
    #include "mmi_features_camcorder.h"
    #include "CamcorderGprot.h"
#else /* __MMI_CAMCORDER__ */ 
#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
    #include "VdoRecGprot.h"
#endif /* defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE) */ 
#endif /* __MMI_CAMCORDER__ */

/* yingchun modify for framework2.0 */
/* include cui vdorec and camra part */
#include "VdoRecCuiGprot.h"
#include "CameraCuiGprot.h"

#include "imeGprot.h"
#include "wgui_inline_edit.h"
#include "Commonscreens.h"
#include "wapadp.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif

#ifndef WAP_SUPPORT
#ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 
#else /* WAP_SUPPORT */ 
#include "WAPProfileSrvGProt.h"
#endif /* WAP_SUPPORT */ 
#include "inlineCuiGprot.h"
#ifdef __MMI_MMS_POSTCARD__
#include "UcPcrdProt.h"
#endif 
#include "UcResDef.h"
#include "Custom_events_notify.h"
#include "UcAppGprot.h"
#include "FileMgr.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcScrUIProt.h"
//#include "UcPcrdProt.h"
//#include "MessagesResourceData.h"
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
#include "MenuCuiGprot.h"
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
//suggested add
#include "MMI_features.h"
    #include "gui_data_types.h"
    #include "MMIDataType.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_frm_history_gprot.h"
    #include "GlobalResDef.h"
   // #include "kal_general_types.h"
    #include "CustMenuRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "Unicodexdcl.h"
    #include "UcSrvGprot.h"
    #include "CustDataRes.h"
    #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "mma_struct.h"
    //#include "kal_public_api.h"
    #include "customer_email_num.h"
    #include "mmi_frm_mem_gprot.h"
    #include "UmSrvDefs.h"
    #include "UmSrvGprot.h"
    #include "string.h"
    #include "wgui_categories_inputs.h"
    #include "GlobalConstants.h"
    #include "SmsSrvGprot.h"
    #include "stdio.h"
    #include "DebugInitDef_Int.h"
    #include "mma_api.h"
    #include "wgui_categories_util.h"
    #include "custom_phb_config.h"
    #include "mmi_frm_input_gprot.h"
    #include "mms_api.h"
    #include "mmi_frm_timer_gprot.h"
    //#include "TimerEvents.h"
    #include "kal_trace.h"
   // #include "MMI_common_app_trc.h"
    #include "mmi_common_app_trc.h"
    #include "app_mem.h"
    #include "gui_typedef.h"
#ifdef __MMI_OP02_LEMEI__
#include "mmi_rp_menu_misc_def.h"
#endif
	#include "MenuCuiGprot.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetsetAppGprot.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
/****************************************************************************
* Constants
*****************************************************************************/
mmi_imm_input_mode_enum g_uc_required_input_modes[] = 
{
    IMM_INPUT_MODE_PHONE_NUMBER,
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,
    IMM_INPUT_MODE_NONE
};

/****************************************************************************
 * Type definitions
 ****************************************************************************/
/***************************************************************************** 
* Extern Function
*****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
/* To sync with phb design */
extern const UI_character_type mmi_phb_e_mail_allowed[];
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

extern U8 wgui_inline_list_menu_changed;

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*----------------------------------Interface-Code----------------------------*/

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_text_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_show_text_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_cntrlr_screen_render_start(MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_image_timing_inline_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_image_timing_inline_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.inline_cui_id = mmi_frm_group_create(
            g_uc_p->main.uc_cui_gid, GRP_ID_UNIFIED_COMPOSER_INLINE_CUI, mmi_uc_object_timing_inline_cui_group_proc, (void*)NULL);
    mmi_frm_group_enter(g_uc_p->main.inline_cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_uc_show_image_timing(); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_image_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_show_image_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_cntrlr_screen_render_start(MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_IMAGE_TIMING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_audio_timing_inline_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_audio_timing_inline_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.inline_cui_id = mmi_frm_group_create(
            g_uc_p->main.uc_cui_gid, GRP_ID_UNIFIED_COMPOSER_INLINE_CUI, mmi_uc_object_timing_inline_cui_group_proc, (void*)NULL);
    mmi_frm_group_enter(g_uc_p->main.inline_cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_uc_show_audio_timing(); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_audio_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_show_audio_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_cntrlr_screen_render_start(MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_AUDIO_TIMING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_video_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_video_timing_inline_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->main.inline_cui_id = mmi_frm_group_create(
            g_uc_p->main.uc_cui_gid, GRP_ID_UNIFIED_COMPOSER_INLINE_CUI, mmi_uc_object_timing_inline_cui_group_proc, (void*)NULL);
    mmi_frm_group_enter(g_uc_p->main.inline_cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_uc_show_video_timing(); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_video_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_show_video_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_cntrlr_screen_render_start(MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_VIDEO_TIMING);
}
#endif /* _MMI_SLIM_MMS_2__ */

/*------------------------------------Lsk Rsk callbacks functions ----------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_static_list_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_static_list_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_sh_add_recipient_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_sh_add_recipient_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}

/*------------------------------------other callbacks functions ----------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_progress_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_progress_screen_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_recipient_list_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_uc_app_recipient_list_delete_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:

        break;
    case EVT_ID_SCRN_GOBACK:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:

        break;
    case EVT_ID_SCRN_DEINIT:
        //mmi_uc_reset_msg();
        mmi_uc_done_delete_history_hdlr(evt->user_data);

        break;
    default:
        return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;
}

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_write_msg_selection_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_uc_app_write_msg_selection_delete_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:

        break;
    case EVT_ID_SCRN_GOBACK:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:

        break;
    case EVT_ID_SCRN_DEINIT:
        //mmi_uc_reset_msg();
        mmi_uc_write_msg_selection_del_history_hdlr(evt->user_data);

        break;
    default:
        return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;

    return MMI_FALSE;
}
#endif /* __MMI_MMS_POSTCARD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_content_editor_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_uc_frm_sh_content_editor_delete_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_EDITOR);

        break;
    case EVT_ID_SCRN_GOBACK:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_EDITOR);

        break;
    case EVT_ID_SCRN_DEINIT:
        //mmi_uc_reset_msg();
        mmi_uc_write_msg_delete_history_hdlr(evt->user_data);

        break;
    default:
        return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_generic_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_uc_frm_sh_generic_delete_screen(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = (mmi_uc_frm_screenDB_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(scrDB->instance_hash_id);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_static_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 *  str_item_list           [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_frm_app_static_menu_item_list(U16 instance_hash_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scr_db = mmi_uc_frm_get_screenDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(scr_db->parent_menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_static_menu_icon_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_frm_app_static_menu_icon_list(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*) gIndexIconsImageList;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_static_menu_list_of_descriptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 *  popUpList               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 **mmi_uc_frm_app_static_menu_list_of_descriptions(U16 instance_hash_id, U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_uc_frm_screenDB_struct *scrDB = mmi_uc_frm_get_screenDB(instance_hash_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ConstructHintsList(scrDB->parent_menu_id, popUpList);
    return popUpList;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_general_icon_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_frm_app_get_general_icon_list(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*) gIndexIconsImageList;
}

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_text_timing_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_text_timing_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_image_timing_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_image_timing_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_audio_timing_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_audio_timing_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_video_timing_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_video_timing_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* _MMI_SLIM_MMS_2__ */
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_add_recipient_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_sh_add_recipient_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_uc_preview_delete_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_preview_delete_history_hdlr();

    return MMI_FALSE;
}

/*------------------------------- Data filler corresponding app part --------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_subject_for_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subjcet_firstline       [?]     
 *  subject_secondline      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_subject_for_editor_screen(UI_string_type *subjcet_firstline, UI_string_type *subject_secondline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->subject) > 0 &&
        g_uc_p->srv_msg_type->curr_msg_type != MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        *subjcet_firstline = (UI_string_type) GetString(STR_UC_WRITE_MSG_SUBJECT_ID);
        *subject_secondline = g_uc_p->srv_msg->subject;
    }
}

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_title_for_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subjcet_firstline       [?]     
 *  subject_secondline      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_uc_get_title_for_editor_screen(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    title_id = STR_UC_WRITE_MSG_ID;
#else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        title_id = STR_UC_WRITE_SMS_ID;
    }
    else if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        title_id = STR_UC_WRITE_MMS_ID;
    }
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 

#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        title_id = STR_UC_WRITE_MSG_ID;
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
    return title_id;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_editor_msg_type_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_app_get_editor_msg_type_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_uc_convert_to_editor_msg_type(g_uc_p->srv_msg_type->curr_msg_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_slide_time_input_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_app_get_slide_time_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IMM_INPUT_TYPE_NUMERIC;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_slide_time_set_first_entry_editor_environment_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_set_slide_time_set_first_entry_editor_environment_for_work(void)
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
 *  mmi_uc_get_slide_time_editor_buffer_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_get_slide_time_editor_buffer_for_work(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*) g_uc_p->main.slide_timing;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_slide_time_editor_max_buffer_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_get_slide_time_editor_max_buffer_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 timing_digit_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_mms_info->sliding_time.max < 100)
    {
        timing_digit_len = 2;
    }
    else if (g_uc_p->srv_mms_info->sliding_time.max < 1000)
    {
        timing_digit_len = 3;
    }
    else
    {
        timing_digit_len = 3;
    }
#ifdef __MMI_MMS_2__
    if (g_uc_p->srv_msg->best_page_duration)
    {
        S32 obj_duration_digit = mmi_ucs2strlen((S8*) g_uc_p->main.slide_timing);

        if (timing_digit_len < obj_duration_digit)
        {
            timing_digit_len = obj_duration_digit;
        }
        /* error handling for digit exceed slide_timing mem limitation */
        if (MMI_UC_MAX_SLIDE_TIMING_DIGIT < obj_duration_digit)
        {
            S8 j;
            U32 maxValue = 1;

            timing_digit_len = MMI_UC_MAX_SLIDE_TIMING_DIGIT;
            /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
            for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
            {
                maxValue = 10 * maxValue;
            }
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_timing, "%d", maxValue - 1);
            /* if digit =3, here timing will be 999 */
        }
    }
#endif /* __MMI_MMS_2__ */ 

    return (timing_digit_len + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_slide_time_editor_filters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_uc_app_get_slide_time_editor_filters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_recipiet_input_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_app_get_recipiet_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        return IMM_INPUT_TYPE_PHONE_NUMBER;
    }
    else
    {
        return IMM_INPUT_TYPE_USER_SPECIFIC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_recipient_set_first_entry_editor_environment_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_set_recipient_set_first_entry_editor_environment_for_work(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_PHONE_NUMBER);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_recipient_editor_buffer_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_get_recipient_editor_buffer_for_work(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*) g_uc_p->done.to;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_recipient_editor_max_buffer_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_get_recipient_editor_max_buffer_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_UC_MAX_RECIPIENT_LEN + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_recipient_editor_filters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_uc_app_get_recipient_editor_filters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_recipient_editor_filters_for_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 *mmi_uc_app_get_recipient_editor_filters_for_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        const UI_string_type allowed_characters = mmi_imm_get_allowed_email_address_characters();

        mmi_imm_set_characters(MMI_TRUE, allowed_characters);
    }
    return (S32*) g_uc_required_input_modes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_subject_input_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_app_get_subject_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IMM_INPUT_TYPE_SENTENCE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_first_entry_editor_environment_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_uc_set_first_entry_editor_environment_for_work(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_uc_p->srv_msg->temp_subject)
    {
        g_uc_p->srv_msg->temp_subject = OslMalloc(sizeof(U16) * (MMI_UC_MAX_SUBJECT_LEN + 1));
    }
    memcpy(g_uc_p->srv_msg->temp_subject, g_uc_p->srv_msg->subject, sizeof(U16) * (MMI_UC_MAX_SUBJECT_LEN + 1));
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_editor_buffer_for_work
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_uc_get_editor_buffer_for_work(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uc_p->srv_msg->temp_subject;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_subject_editor_max_buffer_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_get_subject_editor_max_buffer_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_UC_MAX_SUBJECT_LEN + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_subject_editor_filters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_uc_app_get_subject_editor_filters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_app_get_subject_editor_filters_for_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 *mmi_uc_app_get_subject_editor_filters_for_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_sh_msg_detail_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 *  length                  [?]         
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_uc_frm_sh_msg_detail_get_data(U16 instance_hash_id, S32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *info = (PU8) subMenuData;
    U32 temp_string_len = 30;
    U8 temp_string[30];
    U8 temp_ucs2_string[30 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *length = MAX_SUB_MENUS * MAX_SUB_MENU_SIZE;
    memset(info, 0, MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);
    if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        U32 page;
        U32 total_msg;
        U32 recipient;

        page = srv_sms_get_sms_segment_number(
                g_uc_p->srv_msg->msg_body.curr_slide->txt.UCS2_count,
                g_uc_p->srv_msg->msg_body.curr_slide->txt.char_count,
                g_uc_p->srv_msg->msg_body.curr_slide->txt.extension_char_count);
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        recipient = mmi_uc_get_buffer_recipient_count();
#else
        recipient = g_uc_p->srv_msg->to_num;
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        total_msg = page * recipient;

        /* Msg type caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_MESSAGE_TYPE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Msg type */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_TEXT_MESSAGE));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Msg page caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_PAGES_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Msg page */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);
        sprintf((char*)temp_string, "%d", page);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Recipient caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MSG_DETAIL_RECIPIENTS_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Recipient */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);
        sprintf((char*)temp_string, "%d", recipient);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Total msg caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_TOTAL_MESSAGES_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Total msg */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);
        sprintf((char*)temp_string, "%d", total_msg);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
    #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    }
    else if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        FLOAT size = 0;
        U32 recipient;
        mma_mms_attachment_info_struct *attach = g_uc_p->srv_msg->msg_body.attachment;
        mma_mms_slide_struct *slide = g_uc_p->srv_msg->msg_body.slides;

    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            recipient = (U32) srv_postcard_get_total_recipient_count(g_uc_p->main.instance);
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            recipient = mmi_uc_get_buffer_recipient_count();
#else
            recipient = g_uc_p->srv_msg->to_num;
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        }
        size = (FLOAT) g_uc_p->srv_msg->msg_size / (FLOAT) 1024.0;

        /* Msg type caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_MESSAGE_TYPE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Msg type */
    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            mmi_ucs2cat((PS8) info, (PS8) GetString(STR_ID_UC_MMS_POSTCARD));
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
            mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_MULTIMEDIA_MESSAGE));
        }
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode != MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    #endif 
        {
            /* Msg Sub Caption */
            mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_WRITE_MSG_SUBJECT_ID));
            mmi_ucs2cat((PS8) info, (PS8) L"\n");

            /* Msg Sub */
            if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->subject) > 0)
            {
                mmi_ucs2cat((PS8) info, (PS8) g_uc_p->srv_msg->subject);
            }
            else
            {
                mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
        }
        /* Msg size caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_SIZE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Msg size */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);
        sprintf((char*)temp_string, "%.1f ", size);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_KB_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Recipient caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MSG_DETAIL_RECIPIENTS_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        /* Recipient */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);
        sprintf((char*)temp_string, "%d", recipient);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            /* Just skip do nothing. */
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
            /* Attachment caption */
            mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_DETAIL_ATTACHMENT_LIST_ID));
            mmi_ucs2cat((PS8) info, (PS8) L"\n");

            /* Attachments  */
            if (g_uc_p->srv_msg->msg_body.total_attach_no == 0)
            {
                mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_EMPTY_LIST));
                mmi_ucs2cat((PS8) info, (PS8) L"\n");
            }
            else
            {
                U32 i;
                U32 handled_num = 0;

                /* total_attachment_num = ref + attachment */
                /* 1. ref */
                for (i = 0; i < g_uc_p->srv_msg->msg_body.slide_no; i++)
                {
                    if (slide->ref_items != NULL)
                    {
                        mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

                        while (curr_ref != NULL)
                        {
                            mmi_uc_get_file_detail_info(curr_ref->object, info);
                            handled_num++;
                            MMI_ASSERT(handled_num <= g_uc_p->srv_msg->msg_body.total_attach_no);
                            MMI_ASSERT(handled_num <= SRV_UC_MAX_ATTACHMENT_NUM);
                            curr_ref = curr_ref->next;
                        }
                    }
                    slide = slide->next;
                }

                /* attach */
                while (attach != NULL)
                {
                    mmi_uc_get_file_detail_info(attach->object, info);
                    handled_num++;
                    MMI_ASSERT(handled_num <= g_uc_p->srv_msg->msg_body.total_attach_no);
                    MMI_ASSERT(handled_num <= SRV_UC_MAX_ATTACHMENT_NUM);
                    attach = attach->next;
                }
            }
        }   /* attach */
    }
    return info;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_attachment_item_list_for_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 **mmi_uc_frm_app_get_attachment_item_list_for_menu(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 submenu_index = 0;  /* subMenuDataPtrs[] -- start from 0 */
    mma_mms_slide_struct *slide = g_uc_p->srv_msg->msg_body.slides;

    mma_mms_attachment_info_struct *attachment = g_uc_p->srv_msg->msg_body.attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* total_attachment_num = ref + attach obj */

    /* 1. Ref */
    for (i = 0; i < g_uc_p->srv_msg->msg_body.slide_no; i++)
    {
        if (slide->ref_items!= NULL)
        {
            mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

            while (curr_ref != NULL)
            {
                mmi_ucs2cpy((S8*) subMenuDataPtrs[submenu_index], (S8*) curr_ref->object->file_name_ucs);
                submenu_index++;
                MMI_ASSERT(submenu_index <= g_uc_p->srv_msg->msg_body.total_attach_no);
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }
    g_uc_p->srv_msg->msg_body.total_ref_no = submenu_index;

    /* 2. attachment */
    while (attachment != NULL)
    {
        mmi_ucs2cpy((S8*) subMenuDataPtrs[submenu_index], (S8*) attachment->object->file_name_ucs);
        submenu_index++;
        MMI_ASSERT(submenu_index <= g_uc_p->srv_msg->msg_body.total_attach_no);
        attachment = attachment->next;
    }
    return (U8 **) subMenuDataPtrs;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_number_of_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_frm_app_get_number_of_items(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uc_p->srv_msg->msg_body.total_attach_no;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_message_buffer_for_sending_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_uc_get_message_buffer_for_sending_progress(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->send_info.retry > 0)
    {

        const S8 *pstr1;
        U32 temp_string_len = 6;    /* temp_string_len - for percentage wording --ex" 100%" */
        U8 temp_string[6];
        U8 temp_ucs2_string[6 * ENCODING_LENGTH];
        int msg_size = 0;

        pstr1 = GetString(STR_UC_RESEND_ID);
        msg_size = (mmi_ucs2strlen(pstr1) + temp_string_len) * ENCODING_LENGTH;

        message = (S8*) OslMalloc(msg_size);
        memset(message, 0, msg_size);

        sprintf((char*)temp_string, " %d%%", g_uc_p->send_info.percent);
        mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, temp_string_len);
        mmi_ucs2cpy((PS8) message, (PS8) pstr1);
        mmi_ucs2cat(message, (S8*) temp_ucs2_string);
    }

    return message;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_string_buffer_for_sending_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_uc_get_string_buffer_for_sending_progress(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) GetString(STR_GLOBAL_PLEASE_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_progress_for_sending_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_uc_get_progress_for_sending_progress(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uc_p->send_info.percent;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_free_message_buffer_for_sending_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_free_message_buffer_for_sending_progress(S8 *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(message);
    message = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_callback_slide_timing_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_callback_slide_timing_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[0] = IMG_GLOBAL_L1;
    image_list[1] = 0;
    image_list[2] = IMG_GLOBAL_L2;
    image_list[3] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_callback_slide_timing_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
wgui_inline_item *mmi_uc_frm_app_callback_slide_timing_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 timing_digit_len = 0;
    //S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_mms_info->sliding_time.max < 100)
    {
        timing_digit_len = 2;
    }
    else if (g_uc_p->srv_mms_info->sliding_time.max < 1000)
    {
        timing_digit_len = 3;
    }
    else
    {
        timing_digit_len = 3;
    }

    if (g_uc_p->srv_msg->best_page_duration)
    {
        S32 obj_duration_digit = mmi_ucs2strlen((S8*) g_uc_p->main.slide_number);      /* END TIME */

        if (timing_digit_len < obj_duration_digit)
        {
            timing_digit_len = obj_duration_digit;
        }
        /* error handling for digit exceed slide_timing mem limitation */
        if (MMI_UC_MAX_SLIDE_TIMING_DIGIT < obj_duration_digit)
        {
            S8 j;
            U32 maxValue = 1;

            timing_digit_len = MMI_UC_MAX_SLIDE_TIMING_DIGIT;
            /* to get max vaule of digit MMI_UC_MAX_SLIDE_TIMING_DIGIT */
            for (j = 0; j < MMI_UC_MAX_SLIDE_TIMING_DIGIT; j++)
            {
                maxValue = 10 * maxValue;
            }
            kal_wsprintf((kal_uint16*) g_uc_p->main.slide_number, "%d", maxValue - 1);
            /* if digit =3, here timing will be 999 */
        }
    }

    /* Start time caption */
    //cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT1, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_BOUNDARY);
    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT1, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_text_len(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT1, timing_digit_len + 1);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT1, g_uc_p->main.slide_timing);

    /* End time caption */
    //cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_BOUNDARY);
    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_text_len(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT2, timing_digit_len + 1);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, APP_TEXTEDIT2, g_uc_p->main.slide_number);

    return wgui_inline_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_callback_send_opt_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_callback_send_opt_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
    image_list[MMI_UC_SEND_OPT_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_VALIDITY_PERIOD] = 0;
#endif /* __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__ */ 
    image_list[MMI_UC_SEND_OPT_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_DELIVERY_REPORT] = 0;
    image_list[MMI_UC_SEND_OPT_READ_REPORT_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_READ_REPORT] = 0;
    image_list[MMI_UC_SEND_OPT_PRIORITY_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_PRIORITY] = 0;
    image_list[MMI_UC_SEND_OPT_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_DELIVERY_TIME] = 0;
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
    image_list[MMI_UC_SEND_OPT_HIDE_SENDER_CAPTION] = gIndexIconsImageList[count++];
    image_list[MMI_UC_SEND_OPT_HIDE_SENDER] = 0;
#endif /* __MMI_MMS_HIDE_SENDER_SUPPORT__ */ 
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
    image_list[MMI_UC_SEND_OPT_CLASS_CAPTION] = IMG_UC_DELIVERY_TIME_ID;
    image_list[MMI_UC_SEND_OPT_MSG_CLASS] = 0;
#endif /* OMA13_CON_739_SUPPORT_TEMP_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_callback_send_opt_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
wgui_inline_item *mmi_uc_frm_app_callback_send_opt_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
		g_uc_p->send_opt.validity_period = g_uc_p->srv_msg->expiry_time - 1;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, VALIDITY_PERIOD_SELECT, (void *) (g_uc_p->send_opt.validity_period));
#endif
		g_uc_p->send_opt.delivery_report = g_uc_p->srv_msg->delivery_report;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, DELIVERY_REPORT_SELECT, (void *) (g_uc_p->send_opt.delivery_report));
		
		g_uc_p->send_opt.read_report = g_uc_p->srv_msg->read_report;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, READ_REPORT_SELECT, (void *) (g_uc_p->send_opt.read_report));
		
		g_uc_p->send_opt.priority = g_uc_p->srv_msg->priority - 1;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, PRIORITY_SELECT, (void *) (g_uc_p->send_opt.priority));
		
		g_uc_p->send_opt.delivery_time = g_uc_p->srv_msg->delivery_time - 1;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, DELIVERY_TIME_SELECT, (void *) (g_uc_p->send_opt.delivery_time));
		
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
		g_uc_p->send_opt.hide_sender = g_uc_p->srv_msg->hide_sender;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, SENDER_VISIBILITY_SELECT, (void *)&(g_uc_p->send_opt.hide_sender));
#endif		
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
		g_uc_p->send_opt.msg_class = g_uc_p->srv_msg->msg_class;
		cui_inline_set_value(g_uc_p->main.inline_child_cui_id, MSG_CLASS_SELECT, (void *)&(g_uc_p->send_opt.msg_class));
#endif
    return wgui_inline_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_get_num_of_items_for_inline_screen_based_on_instance_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_frm_get_num_of_items_for_inline_screen_based_on_instance_id(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (instance_hash_id)
    {
#ifndef __MMI_SLIM_MMS_2__
        case MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING:
        case MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_IMAGE_TIMING:
        case MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_AUDIO_TIMING:
        case MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_VIDEO_TIMING:
            num_of_items = 4;
            break;
#endif
        case MMI_UC_FLOW_INSTANCE_ID_OPT_SEND_OPT:
            num_of_items = MMI_UC_SEND_OPT_TOTAL_NUM;
            break;

    #ifdef __MMI_MMS_POSTCARD__
        case MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS:
            num_of_items = 14;
            break;
    #endif /* __MMI_MMS_POSTCARD__ */ 

        default:
            MMI_ASSERT(0);
            break;
    }
    return num_of_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_num_of_items_for_add_recipient_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_get_num_of_items_for_add_recipient_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        numItems += srv_postcard_get_total_recipient_count(g_uc_p->main.instance);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        numItems += g_uc_p->srv_msg->to_num;
    }
    numItems += MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted();
    if (mmi_uc_is_no_recepient())
    {
        numItems++;
    }

    return numItems;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_hilited_item_for_add_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]         
 *  numItems        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_get_hilited_item_for_add_recipient(U8 *guiBuffer, U16 numItems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hiliteitem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_uc_is_no_recepient())
    {
        numItems--;
    }
    if (guiBuffer != NULL)
    {
        if (g_uc_p->done.current_addr_index < numItems)
        {
            hiliteitem = g_uc_p->done.current_addr_index;
        }
        else if (g_uc_p->done.current_addr_index == numItems)
        {
            if (!mmi_uc_is_no_recepient())
            {
                hiliteitem = g_uc_p->done.current_addr_index;
            }
            else
            {
                hiliteitem = MMI_UC_ADD_FROM_CONTACTS;
            }
        }
        else if (g_uc_p->done.current_addr_index > numItems)
        {
            if (mmi_uc_is_no_recepient())
            {
                hiliteitem = MMI_UC_ADD_FROM_CONTACTS;
            }
        }
        /* change gui buffer content */
        //change_cat184_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
		change_cat1032_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
    }
    else if (g_uc_p->done.current_addr_index > 0)
    {
        if (!mmi_uc_is_no_recepient())
        {
            hiliteitem = (g_uc_p->done.current_addr_index <= numItems) ? g_uc_p->done.current_addr_index : 0;
        }
    }
    else
    {
        hiliteitem = MMI_UC_ADD_FROM_CONTACTS;
    }

    if (g_uc_p->srv_msg->to_num > 0)
    {
        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        }
        else
        {
            EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        }
    } 

    return hiliteitem;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_callback_set_data_for_recipient_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_callback_set_data_for_recipient_list(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    title_id = STR_UC_ADD_RECIPIENT_ID;
#else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        title_id = STR_UC_SEND_SMS_ID;
    }
    else if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        title_id = STR_UC_SEND_MMS_ID;
    }
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 

#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        title_id = STR_UC_ADD_RECIPIENT_ID;
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
    return title_id;
}


#ifdef __UC_ASYNC_DYNAMIC_LIST__

S32 mmi_uc_async_addr_list_get_item_ext(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{

	//MMI_ASSERT(start_indx >=0 && num_item >=0 && menuData != NULL);

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    #ifdef __MMI_MMS_POSTCARD__
    S8 *name = NULL;
    #endif
	S8 count = 0;
	S8 end_index = start_indx + num_item;
	S8 curr =0;
    mmi_uc_addr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(temp, 0, sizeof(temp));

	switch(start_indx)
	{
		case MMI_UC_ENTER_RECIPIENT:
			curr = MMI_UC_ENTER_RECIPIENT;
			if(curr >= start_indx && curr < end_index)
			{
				mmi_ucs2ncpy((S8*) menuData[count].item_list[0], (S8*) GetString((U16)(STR_UC_ENTER_RECIPIENT_ID)), MAX_SUBMENU_CHARACTERS);
	    	    menuData[count].image_list[0] = NULL;
				count++;
			}
		case MMI_UC_ADD_FROM_CONTACTS:
			curr = MMI_UC_ADD_FROM_CONTACTS;
			if(curr >= start_indx && curr < end_index)
			{
				//if(!(start_indx == 1 && num_item == 1))
				{
					mmi_ucs2ncpy((S8*) menuData[count].item_list[0], (S8*) GetString((U16)(STR_UC_ADD_FROM_CONTACTS_ID)), MAX_SUBMENU_CHARACTERS);
		    	    menuData[count].image_list[0] = NULL;
					count++;
				}
			}
		default:
			#ifdef __MMI_MMS_POSTCARD__
			if((g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS && !(srv_postcard_get_total_recipient_count(g_uc_p->main.instance) ) ) || !(g_uc_p->srv_msg->to_num) )
			#else
			if(!(g_uc_p->srv_msg->to_num) )
			#endif
	        {
	        	curr = MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted();
				if(curr >= start_indx && curr < end_index)
				{
		            mmi_ucs2ncpy((S8*) menuData[count].item_list[0], (S8*) GetString(STR_UC_NO_RECIPIENT_ID), MAX_SUBMENU_CHARACTERS);
		            menuData[count].image_list[0] = NULL;
					count++;
				}
	        }
			else
			{
				curr = MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted();
			#ifdef __MMI_MMS_POSTCARD__
				if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
				{
					U8 i = 0;
					for(i ; i < g_uc_p->srv_msg->postcard_recipient_info.recipient_total; i++)
					{
						if(curr >= start_indx && curr < end_index)
						{
							name = (S8*) srv_postcard_get_recipient_name_by_index(g_uc_p->main.instance, i);
							if (name != NULL && mmi_ucs2strlen(name) > 0)
							{
								mmi_ucs2ncpy((S8*) menuData[count].item_list[0], name, MAX_SUBMENU_CHARACTERS);
								menuData[count].image_list[0] = (PU8) GetImage(IMG_UC_POSTCARD_RECIPIENT_ID);
								count++;
							}
						}
						curr++;
					}		
				}
				else
			#endif /* __MMI_MMS_POSTCARD__ */ 
				{
					for(addr = g_uc_p->srv_msg->to_head ; addr ; addr = addr->next)
					{
						if(curr >= start_indx && curr < end_index)
						{
							if (addr->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
							{
							    //S32 result = 0;
								memset(temp, 0, sizeof(temp));
							    mmi_asc_to_ucs2(temp, (S8*) addr->addr);

							    if (strlen((S8*)addr->addr) <= (MMI_UC_MAX_PHONE_NUMBER_LEN + 1))
							    {
							        //result = srv_phb_get_name_by_number((U16*)temp, (U16*)str_buff, MAX_SUBMENU_CHARACTERS);
									//menuData[i].item_list[0]
									srv_phb_get_name_by_number((U16*)temp, (U16*)menuData[count].item_list[0], MAX_SUBMENU_CHARACTERS);	
							        if(mmi_ucs2strlen((S8*) menuData[count].item_list[0]))
							        {
							            /* Alraedy copied */
							        }
							        else
							        {
							            mmi_ucs2ncpy((S8*) menuData[count].item_list[0], (S8*) temp, MAX_SUBMENU_CHARACTERS);            
							        }

									
									if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_TO)
									{
										menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_TO_NUMBER_ID);
									}
									else if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_CC)
									{
										menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_CC_NUMBER_ID);
									}
									else
									{
										menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_BCC_NUMBER_ID);
									}
							    }	    
							}
							else
							{
							    mmi_ucs2ncpy((S8*) menuData[count].item_list[0], (S8*) addr->addr, MAX_SUBMENU_CHARACTERS);

								if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_TO)
					            {
					                menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_TO_EMAIL_ID);
					            }
					            else if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_CC)
					            {
					                menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_CC_EMAIL_ID);
					            }
					            else
					            {
					                menuData[count].image_list[0] = (U8*) GetImage(IMG_UC_BCC_EMAIL_ID);
					            }
							}

							count++;
						}
						curr++;
						
					
					}

				}
				
			}
			
	}

	MMI_ASSERT(count == num_item);
	return count;

}


#else
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_addr_list_get_item_ext
 * DESCRIPTION
 *  Get address list item
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 *  a(?)                [IN]            Item index(?)
 *  d(?)                [IN/OUT]        String image mask(?)
 *  c(?)                [IN/OUT]        Image buffer(?)
 *  b(?)                [IN/OUT]        String buffer(?)
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_uc_addr_list_get_item_ext(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
	#ifdef __MMI_MMS_POSTCARD__
		S8 *name = NULL;
	#endif
    U8 i = 0;
    mmi_uc_addr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp, 0, sizeof(temp));

    if (item_index < (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()))
    {
        if (item_index == MMI_UC_ENTER_RECIPIENT)
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(STR_UC_ENTER_RECIPIENT_ID), MAX_SUBMENU_CHARACTERS);
        }
        else if (item_index == MMI_UC_ADD_FROM_CONTACTS)
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(STR_UC_ADD_FROM_CONTACTS_ID), MAX_SUBMENU_CHARACTERS);
        }
        *img_buff_p = NULL;
        return TRUE;
    }

#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        if (item_index == (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted())
            && !(srv_postcard_get_total_recipient_count(g_uc_p->main.instance)))
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(STR_UC_NO_RECIPIENT_ID), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
            return TRUE;
        }
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        if (item_index == (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()) &&
            !(g_uc_p->srv_msg->to_num))
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(STR_UC_NO_RECIPIENT_ID), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
            return TRUE;
        }
    }

    item_index -= (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted());

#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        name = (S8*) srv_postcard_get_recipient_name_by_index(g_uc_p->main.instance, (U8) item_index);
        if (name != NULL && mmi_ucs2strlen(name) > 0)
        {
            mmi_ucs2ncpy((S8*) str_buff, name, MAX_SUBMENU_CHARACTERS);
        }
        *img_buff_p = (PU8) GetImage(IMG_UC_POSTCARD_RECIPIENT_ID);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        if (item_index < g_uc_p->srv_msg->to_num)
        {
            addr = g_uc_p->srv_msg->to_head;
        }
        else
        {
            ASSERT(0);
        }

        for (i = 0; i < item_index; i++)
        {
            addr = addr->next;
            MMI_ASSERT(addr);
        }

        if (addr->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
        {
            S32 result = 0;
            mmi_asc_to_ucs2(temp, (S8*) addr->addr);

            if (strlen((S8*)addr->addr) <= (MMI_UC_MAX_PHONE_NUMBER_LEN + 1))
            {
                result = srv_phb_get_name_by_number((U16*)temp, (U16*)str_buff, MAX_SUBMENU_CHARACTERS);
                if(mmi_ucs2strlen((S8*) str_buff))
                {
                    /* Alraedy copied */
                }
                else
                {
                    mmi_ucs2ncpy((S8*) str_buff, (S8*) temp, MAX_SUBMENU_CHARACTERS);            
                }
            }

            if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_TO_NUMBER_ID);
            }
            else if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_CC_NUMBER_ID);
            }
            else
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_BCC_NUMBER_ID);
            }
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) addr->addr, MAX_SUBMENU_CHARACTERS);
            if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_TO_EMAIL_ID);
            }
            else if (addr->group == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_CC_EMAIL_ID);
            }
            else
            {
                *img_buff_p = (PU8) GetImage(IMG_UC_BCC_EMAIL_ID);
            }
        }
    }
    return TRUE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_enter_recipient_option_set_data_for_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_enter_recipient_option_set_data_for_editor_option(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_imm_create_input_method_list(IMM_INPUT_TYPE_PHONE_NUMBER, NULL);
    }
    else
    {
        mmi_imm_create_input_method_list(IMM_INPUT_TYPE_USER_SPECIFIC, g_uc_required_input_modes);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_set_data_for_write_msg_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_set_data_for_write_msg_selection(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_preview_is_back_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_back     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_preview_is_back_handling(MMI_BOOL is_back)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_back)
    {
        g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;

        if (g_uc_p->srv_send_info->new_msg_id)
        {
            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
        }
    }
    else
    {
        g_uc_p->srv_send_info->action = SRV_UC_ACTION_PREVIEW;
        MMI_ASSERT(g_uc_p->srv_send_info->new_msg_id == 0);
		if(!(g_uc_p->srv_send_info->new_msg_id == 0))
		{
		MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
		}
        mmi_uc_create_mms();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_confirmation_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  body_str_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_uc_frm_app_get_confirmation_screen_data(S16 body_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) GetString(body_str_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_confirmation_screen_image_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_frm_app_get_confirmation_screen_image_id(mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_get_event_based_image(MMI_EVENT_QUERY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_sig_confirmation_screen_image_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_frm_app_get_sig_confirmation_screen_image_id(mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_sig_confirmation_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  body_str_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_uc_frm_app_get_sig_confirmation_screen_data(S16 body_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) GetString(STR_UC_WARNING_MODE_SIG_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_get_progress_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_uc_frm_app_get_progress_screen_data(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len = mmi_ucs2strlen((S8*) GetString(g_uc_p->processing.body_str_id));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = (str_len > MMI_UC_MAX_PROCESS_STRING_LEN) ? MMI_UC_MAX_PROCESS_STRING_LEN : str_len;
    memset(g_uc_p->processing.body_str, 0, (MMI_UC_MAX_PROCESS_STRING_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) g_uc_p->processing.body_str, (S8*) GetString(g_uc_p->processing.body_str_id), str_len);

    return g_uc_p->processing.body_str;
}

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_callback_recipient_address_editor_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
wgui_inline_item *mmi_uc_frm_app_callback_recipient_address_editor_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT1, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT1, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT2, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_additional);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT3, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT3, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT4, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT4, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT5, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT5, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_state);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT6, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT6, g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode);

    cui_inline_set_item_attributes(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT7, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DEFAULT_TEXT);
    cui_inline_set_value(g_uc_p->main.inline_child_cui_id, POSTCARD_FULLSCREEN_EDIT7, g_uc_p->srv_msg->msg_body..recipient_editor->postcard_country);
    if ((g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation == SRV_POSTCARD_ADDRESS_INIT ||
         g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation == SRV_POSTCARD_ADDRESS_ADD) &&
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->phonebook_index != 0xFF)
    {
        /* Add from phonebook */
        cui_inline_set_screen_attributes(g_uc_p->main.inline_child_cui_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
    }

    return wgui_inline_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_set_data_for_multiple_recipient_option_in_postcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_set_data_for_multiple_recipient_option_in_postcard(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MMS_POSTCARD__ */ 

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_enter_multimedia_is_back_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_back     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_frm_app_enter_multimedia_is_back_handling(MMI_BOOL is_back)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    U32 max_file_size = 0;
    U32 smil_size = 0;

    /* max "file name" size, not path size. not include file extension, the max file name that user can edit is 35 */
    U16 temp_file_path[43] = L"D:\\temp1234567890123456789012345678901.tmp";
    U16 file_name_size = (35 + 4) * 3 + 50; /* (max+file extension) *3 + constant for mms calculation */
    U32 max_mms_size_available = 0;
    MMI_BOOL flag_for_restricted_popup = (g_uc_p->srv_mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED &&
                                          mms_get_max_msg_size_in_restricted_mode() <=
                                          g_uc_p->srv_mms_info->max_mms_size) ? MMI_TRUE : MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_mms_size_available =
        (flag_for_restricted_popup) ? mms_get_max_msg_size_in_restricted_mode() : g_uc_p->srv_mms_info->max_mms_size;
    if (is_back && g_uc_p->main.is_warning)
    {
        StartTimer(
            UC_MSG_TYPE_CHECK_TIMER_ID,
            MMI_UC_MSG_TYPE_CHECK_TIME,
            mmi_uc_enter_multimedia_app_add_object_warning_mode_check);
    }
    else if (is_back)
    {
        StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_enter_multimedia_app_add_object);
    }
    else
    {
        switch (g_uc_p->main.highlighted_object_type)
        {
        #ifdef __MMI_CAMERA__
            case SRV_UC_OBJECT_TYPE_IMAGE:
            {
                if (g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {

                    new_slide_size = mma_uc_calc_slide_smil_size(g_uc_p->srv_msg->slide_timing);
                }

                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_IMAGE, (kal_wchar*) temp_file_path);
                if (srv_uc_get_mms_type(g_uc_p->main.instance) == MMA_MMS_TYPE_MIXED_MMS)
                {
                    new_slide_size = 0;
                    smil_size = 0;
                }

                if (max_mms_size_available < (g_uc_p->srv_msg->msg_size + new_slide_size + smil_size + file_name_size))
                {
                    MMI_TRACE(
                        MMI_COMMON_TRC_G6_MSG,
                        TRC_MMI_UC_ENTER_MULTIMEDIA_APP_SIZE_EXCEED_P5,
                        max_file_size,
                        max_mms_size_available,
                        g_uc_p->srv_msg->msg_size,
                        new_slide_size,
                        smil_size);
                    max_file_size = 0;
                }
                else    /* avoid overflow */
                {
                    max_file_size =
                        (max_mms_size_available - g_uc_p->srv_msg->msg_size - new_slide_size - smil_size -
                         file_name_size) / 1024;
                }

                MMI_TRACE(
                    MMI_COMMON_TRC_G6_MSG,
                    TRC_MMI_UC_ENTER_MULTIMEDIA_APP_P5,
                    max_file_size,
                    max_mms_size_available,
                    g_uc_p->srv_msg->msg_size,
                    new_slide_size,
                    smil_size);

                if (max_file_size > 0)
                {
                    /* yingchun modify for framework2.0 */
                    /* it will use vdorec cui to record */
                    if(cui_camera_check_and_display_popup())
                    {
                        cui_camera_run_struct camera_struct;

                        cui_camera_struct_init(&camera_struct);

                    #ifdef __MMI_MMS_POSTCARD__
                        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                        {
                            camera_struct.req_mode = MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION;
                            /* mmi_camera_external_request_by_mode(MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION, mmi_uc_enter_multimedia_app_callback); */
                        }
                        else
                    #endif /* __MMI_MMS_POSTCARD__ */ 
                        {
                            camera_struct.req_mode = MMI_CAMERA_EXTERNAL_MODE_NORMAL;
                            /* mmi_camera_external_request_by_mode(MMI_CAMERA_EXTERNAL_MODE_NORMAL, mmi_uc_enter_multimedia_app_callback); */
                        }

                        g_uc_p->main.camera_cui_gid = cui_camera_ex_create(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, mmi_uc_cui_event_handler_group_proc);
                        cui_camera_ex_run(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, g_uc_p->main.camera_cui_gid, &camera_struct);
                    }
                }
                else
                {
                #if (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__))
                #ifdef WAP_SUPPORT
                    if (srv_wap_prof_get_active_profile_connection_type
                        ((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) > SRV_WAP_PROF_CONN_TYPE_HTTP)
                #else /* WAP_SUPPORT */ 
                    if (mmi_brw_prof_get_activated_profile_connection_type(BRW_PROF_MMS_PROFILE) >
                        BRW_PROF_CONN_TYPE_HTTP)
                #endif /* WAP_SUPPORT */ 
                    {
                        mmi_uc_display_popup(SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED);
                    }
                    else
                #endif /* (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__)) */ 
                    {
                        if (flag_for_restricted_popup)
                        {
                            mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS);
                        }
                        else
                        {
                            mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS);
                        }
                    }
                    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }
            }
                break;
        #endif /* __MMI_CAMERA__ */ 

        #ifdef __MMI_SOUND_RECORDER__
            case SRV_UC_OBJECT_TYPE_AUDIO:
            {
                if (g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {

                    new_slide_size = mma_uc_calc_slide_smil_size(g_uc_p->srv_msg->slide_timing);
                }

                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_AUDIO, (kal_wchar*) temp_file_path);
                if (srv_uc_get_mms_type(g_uc_p->main.instance) == MMA_MMS_TYPE_MIXED_MMS)
                {
                    new_slide_size = 0;
                    smil_size = 0;
                }

                if (max_mms_size_available < (g_uc_p->srv_msg->msg_size + new_slide_size + smil_size + file_name_size))
                {
                    MMI_TRACE(
                        MMI_COMMON_TRC_G6_MSG,
                        TRC_MMI_UC_ENTER_MULTIMEDIA_APP_SIZE_EXCEED_P5,
                        max_file_size,
                        max_mms_size_available,
                        g_uc_p->srv_msg->msg_size,
                        new_slide_size,
                        smil_size);
                    max_file_size = 0;
                }
                else    /* avoid overflow */
                {
                    max_file_size =
                        (max_mms_size_available - g_uc_p->srv_msg->msg_size - new_slide_size - smil_size -
                         file_name_size) / 1024;
                }

                MMI_TRACE(
                    MMI_COMMON_TRC_G6_MSG,
                    TRC_MMI_UC_ENTER_MULTIMEDIA_APP_P5,
                    max_file_size,
                    max_mms_size_available,
                    g_uc_p->srv_msg->msg_size,
                    new_slide_size,
                    smil_size);

                if (max_file_size > 0)
                {
                     g_uc_p->main.sndrec_cui_gid = 1;
                    /* audio use byptes */
                #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else /* __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__ */ 

                    mmi_sndrec_entry_record_from_other_app(
                        NULL,
                        max_mms_size_available - g_uc_p->srv_msg->msg_size - new_slide_size - smil_size - file_name_size,
                        0,
                        (void (*)(BOOL, U16*))mmi_uc_enter_multimedia_app_callback);
                #endif /* __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__ */ 
                }
                else
                {
                #if (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__))
                #ifdef WAP_SUPPORT
                    if (srv_wap_prof_get_active_profile_connection_type
                        ((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) > SRV_WAP_PROF_CONN_TYPE_HTTP)
                #else /* WAP_SUPPORT */ 
                    if (mmi_brw_prof_get_activated_profile_connection_type(BRW_PROF_MMS_PROFILE) >
                        BRW_PROF_CONN_TYPE_HTTP)
                #endif /* WAP_SUPPORT */ 
                    {
                        mmi_uc_display_popup(SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED);
                    }
                    else
                #endif /* (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__)) */ 
                    {
                        if (flag_for_restricted_popup)
                        {
                            mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS);
                        }
                        else
                        {
                            mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS);
                        }
                    }
                    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }
            }
                break;
        #endif /* __MMI_SOUND_RECORDER__ */ 

        #if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)

            case SRV_UC_OBJECT_TYPE_VIDEO:
            {
                if (g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL)
                {

                    new_slide_size = mma_uc_calc_slide_smil_size(g_uc_p->srv_msg->slide_timing);
                }

                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_VIDEO, (kal_wchar*) temp_file_path);
                if (srv_uc_get_mms_type(g_uc_p->main.instance) == MMA_MMS_TYPE_MIXED_MMS)
                {
                    new_slide_size = 0;
                    smil_size = 0;
                }

                if (max_mms_size_available < (g_uc_p->srv_msg->msg_size + new_slide_size + smil_size + file_name_size))
                {
                    MMI_TRACE(
                        MMI_COMMON_TRC_G6_MSG,
                        TRC_MMI_UC_ENTER_MULTIMEDIA_APP_SIZE_EXCEED_P5,
                        max_file_size,
                        max_mms_size_available,
                        g_uc_p->srv_msg->msg_size,
                        new_slide_size,
                        smil_size);
                    max_file_size = 0;

                }
                else
                {
                    max_file_size =
                        (max_mms_size_available - g_uc_p->srv_msg->msg_size - new_slide_size - smil_size -
                         file_name_size) / 1024;
                }

                MMI_TRACE(
                    MMI_COMMON_TRC_G6_MSG,
                    TRC_MMI_UC_ENTER_MULTIMEDIA_APP_P5,
                    max_file_size,
                    max_mms_size_available,
                    g_uc_p->srv_msg->msg_size,
                    new_slide_size,
                    smil_size);

                if (max_file_size >= mmi_vdorec_get_min_external_request_size())        /* because video recorder can not record with accurate size, walk around */
                {
                    /* yingchun modify for framework2.0 */
                    /* it will use vdorec cui to record */
                    if(cui_vdorec_check_and_display_popup())    
                    {
                        cui_vdorec_run_struct vdorec_struct;

                        cui_vdorec_struct_init(&vdorec_struct);
                    #ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
                        #if defined(__MMI_CAMCORDER__)
/* under construction !*/
                        #endif
/* under construction !*/
                    #else /* __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__ */ 
                        /* mmi_vdorec_entry_for_external_request(NULL,  max_file_size, 0, mmi_uc_enter_multimedia_app_callback); */
                        vdorec_struct.max_file_size = max_file_size;
                        vdorec_struct.max_record_time = 0;
                        #if defined(__MMI_CAMCORDER__)
                        vdorec_struct.is_partial = 0;
                        #endif
                        g_uc_p->main.vdorec_cui_gid = cui_vdorec_ex_create(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, mmi_uc_cui_event_handler_group_proc);
                    #endif /* __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__ */ 

                        cui_vdorec_ex_run(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, g_uc_p->main.vdorec_cui_gid, &vdorec_struct);
                    }
                }
                else if (max_file_size > 0)
                {
                    mmi_uc_display_popup(SRV_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO);
                    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }
                else
                {
                #if (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__))
                #ifdef WAP_SUPPORT
                    if (srv_wap_prof_get_active_profile_connection_type
                        ((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) > SRV_WAP_PROF_CONN_TYPE_HTTP)
                #else /* WAP_SUPPORT */ 
                    if (mmi_brw_prof_get_activated_profile_connection_type(BRW_PROF_MMS_PROFILE) >
                        BRW_PROF_CONN_TYPE_HTTP)
                #endif /* WAP_SUPPORT */ 
                    {
                        mmi_uc_display_popup(SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED);
                    }
                    else
                #endif /* (defined (__MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__) && !defined (__MMI_OP12_MMS_MAX_SIZE_SUPPORT__)) */ 
                    {
                        if (flag_for_restricted_popup)
                        {
                            mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS);
                        }
                        else
                        {
                            mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS);
                        }
                    }
                    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }
            }
                break;
        #endif /* defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE) */ 
            default:
            {
                MMI_ASSERT(0);
            }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_timing
 * DESCRIPTION
 *  Exit function of done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING);
}
#endif /* _MMI_SLIM_MMS_2__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_send_opt
 * DESCRIPTION
 *  Exit function of send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  in_param        [?](?)
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_uc_preview_delete_history_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG,
        TRC_MMI_UC_PREVIEW_DELETE_HISTORY_HDLR_P2,
        g_uc_p->srv_send_info->action,
        g_uc_p->srv_send_info->new_msg_id);
    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_PREVIEW && g_uc_p->srv_send_info->new_msg_id)
    {
#ifdef __MMI_UC_USE_ASM__
        g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;
        mmi_uc_delete_mms_req(g_uc_p->srv_send_info->new_msg_id, g_uc_p->send_info.new_msg_storage);
        g_uc_p->srv_send_info->new_msg_id = 0;
#else
        g_uc_p->srv_send_info->action = SRV_UC_ACTION_SAVE_IN_BACKGROUND;
        mmi_uc_save_mms_req(g_uc_p->srv_send_info->new_msg_id, MMA_FOLDER_DRAFT);
#endif /* __MMI_UC_USE_ASM__ */
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_dynamic_list_separator_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  flag        [?]         
 *  flag_ex     [?]         
 *  S32(?)
 *  U32*(?)
 *  U32*(?)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_set_dynamic_list_separator_line(S32 index, U32 *flag, U32 *flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()))
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
    }
    if (index == (S32) (MMI_UC_ADD_FROM_CONTACTS - mmi_uc_get_number_of_options_omitted()))
    {
        *flag_ex |=UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE ;
    }
#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        if (index == (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted())
            && !(srv_postcard_get_total_recipient_count(g_uc_p->main.instance)))
        {
            *flag |= UI_MENUITEM_STATE_DISABLED;
            *flag |= UI_MENUITEM_DISABLE_ICON;
        }
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        if (index == (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()) &&
            !(g_uc_p->srv_msg->to_num))
        {
            *flag |= UI_MENUITEM_STATE_DISABLED;
            *flag |= UI_MENUITEM_DISABLE_ICON;
        }
    }
    return MMI_TRUE;
}


 #if(MMI_MAX_SIM_NUM >=2)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_set_data_for_sim_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_frm_app_set_data_for_sim_option(U16 instance_hash_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_sim_info->action == SRV_UC_ACTION_SAVE)
    {
        return STR_GLOBAL_SAVE;
    }
    else
    {
        return STR_GLOBAL_SEND;
    }
}

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__

U16 mmi_uc_get_menu_id_from_sim_id(mmi_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
            uc_menu_id = MENU_ID_UC_OPT_SEND_SIM1;
            break;

        case SRV_UC_SIM_ID_GSM_SIM2:
            uc_menu_id = MENU_ID_UC_OPT_SEND_SIM2;
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UC_SIM_ID_GSM_SIM3:
            uc_menu_id = MENU_ID_UC_OPT_SEND_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_UC_SIM_ID_GSM_SIM4:
            uc_menu_id = MENU_ID_UC_OPT_SEND_SIM4;
            break;
    #endif

        default:
            uc_menu_id = NULL;
            break;
    }

    return uc_menu_id;

}

U16 mmi_uc_get_string_sim_id(mmi_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
            uc_str_id = STR_UC_SEND_FRM_SIM1;
            break;

        case SRV_UC_SIM_ID_GSM_SIM2:
            uc_str_id = STR_UC_SEND_FRM_SIM2;
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UC_SIM_ID_GSM_SIM3:
            uc_str_id = STR_UC_SEND_FRM_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_UC_SIM_ID_GSM_SIM4:
            uc_str_id = STR_UC_SEND_FRM_SIM4;
            break;
    #endif

        default:
            uc_str_id = NULL;
            break;
    }

    return uc_str_id;

}

//WCHAR * mmi_netset_get_sim_name(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  cui_uc_set_string_sim_name
 * DESCRIPTION
 *  
 * PARAMETERS
 * id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/

void cui_uc_set_string_sim_name(mmi_id sender_id, mmi_uc_sim_id sim_id)
{

    WCHAR sim_name[MAX_SUB_MENU_SIZE];

    if(mmi_netset_get_sim_name((mmi_sim_enum)sim_id) != NULL)
    {
       

                 kal_wsprintf(sim_name, 
                    "%w%w%w%w",
                    GetString(mmi_uc_get_string_sim_id(sim_id)),
                    (S8*) L"(",
                    mmi_netset_get_sim_name((mmi_sim_enum)sim_id),
                    (S8*) L")");
                cui_menu_set_item_string(sender_id, mmi_uc_get_menu_id_from_sim_id(sim_id),sim_name);

    }

}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_frm_app_set_data_for_sim_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 * id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/

void cui_uc_frm_app_set_data_for_sim_opt(mmi_id sender_id)
{
   /* U32 current_mode1 = srv_mode_switch_get_network_mode(SRV_UC_SIM_ID_GSM_SIM1);
    U32 current_mode2 = srv_mode_switch_get_network_mode(SRV_UC_SIM_ID_GSM_SIM2);
    #if (MMI_MAX_SIM_NUM >= 3)
        U32 current_mode3 = srv_mode_switch_get_network_mode(SRV_UC_SIM_ID_GSM_SIM3);
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
       U32 current_mode4 = srv_mode_switch_get_network_mode(SRV_UC_SIM_ID_GSM_SIM4);
    #endif */


    if(srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM1))
    {
        //g_uc_p->srv_sim_info->valid_sim_id_info |= SRV_UC_SIM_ID_GSM_SIM1;
        cui_uc_set_string_sim_name(sender_id,SRV_UC_SIM_ID_GSM_SIM1);
    }

    if(srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM2))
    {
       // g_uc_p->srv_sim_info->valid_sim_id_info |= SRV_UC_SIM_ID_GSM_SIM2;
        cui_uc_set_string_sim_name(sender_id,SRV_UC_SIM_ID_GSM_SIM2);
    }

    #if (MMI_MAX_SIM_NUM >= 3)
    if(srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM3))
    {
       // g_uc_p->srv_sim_info->valid_sim_id_info |= SRV_UC_SIM_ID_GSM_SIM3;
        cui_uc_set_string_sim_name(sender_id,SRV_UC_SIM_ID_GSM_SIM3);
    }

    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
    if(srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM4))
    {
        //g_uc_p->srv_sim_info->valid_sim_id_info |= SRV_UC_SIM_ID_GSM_SIM4;
        cui_uc_set_string_sim_name(sender_id,SRV_UC_SIM_ID_GSM_SIM4);
    }
    #endif

   /* if(srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM1) && current_mode1==0)
        cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND_SIM1, MMI_TRUE);

    if(srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM2) && current_mode2==0)
        cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND_SIM2, MMI_TRUE);

    #if (MMI_MAX_SIM_NUM >= 3)
     if(srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM3) && current_mode3==0)
        cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND_SIM3, MMI_TRUE);

    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
    if(srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM3) && current_mode4==0)
        cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND_SIM4, MMI_TRUE);
    #endif */

}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_frm_app_send_hilighted_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_uc_frm_app_send_hilighted_sim_id(void)
{
	return mmi_uc_convert_sim_id_to_hilite_index(g_uc_p->send_info.highlight_sim_id);
}


#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 


/* More to add */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_write_msg_toolbar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_write_msg_toolbar_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(index)
    {
    case UC_EDITOR_FTE_TOOLBAR_OPERATION_SEND:
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        mmi_uc_remove_empty_recipients();
        if(mmi_uc_get_buffer_recipient_count() ==0)
        {
            g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            mmi_uc_search_phb_recipient();
        }
    #else
        if (g_uc_p->srv_msg->to_num == 0)
        {
            mmi_uc_pre_entry_add_recipient();
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        else
        {
            #if (defined(__OP01__) && defined(__MMI_DUAL_SIM_MASTER__))
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
                           #if (MMI_MAX_SIM_NUM >=2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                           #else 
/* under construction !*/
/* under construction !*/
                           #endif
/* under construction !*/
              #else
                #if (MMI_MAX_SIM_NUM >=2)
                 g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SEND;
                 g_uc_p->main.parent_grp_id = g_uc_p->main.uc_cui_gid;
                 g_uc_p->main.uc_cui_gid = mmi_frm_group_create(
                 g_uc_p->main.parent_grp_id, GRP_ID_UNIFIED_COMPOSER_MENU_CUI, mmi_uc_add_media_proc, (void*)NULL); 
                 mmi_frm_group_enter(g_uc_p->main.uc_cui_gid , MMI_FRM_NODE_SMART_CLOSE_FLAG);
                 mmi_uc_pre_entry_sim_option_csk();
               #else 
		         mmi_uc_exit_write_msg();
                 mmi_uc_process_send();
               #endif 
#endif
        }
        break;
    case UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_RECIPIENT :
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        if(g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_BCC_RECIPIENT)
        {
            g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_BCC;
        }
        else if(g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_CC_RECIPIENT)
        {
            g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_CC;
        }
        else
        {
            g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        }
        mmi_uc_search_phb_recipient();
#else
        mmi_uc_pre_entry_add_recipient();
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        break;
    case UC_EDITOR_FTE_TOOLBAR_OPERATION_ADD_OBJECT:
        mmi_uc_entry_add_object_selection();
        break;
    }
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_fte_tap_handling_on_add_recipient_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_tap_type_enum tap_type, S32 index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_fte_tap_handling_on_add_recipient_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	    if (index < (S32) (MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted()))
	    {
	             /* execute the handler of LSK for tap on highlighted item and tap on nonhighlighted item */
         	     
            if (index == MMI_UC_ENTER_RECIPIENT)
            {
                /* use g_uc_p->done.to buffer to store phone number */
                /* here use MMI_UC_MAX_EMAIL_LEN, because to declare as MMI_UC_MAX_EMAIL_LEN */
        
                ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
       
                memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
                g_uc_p->done.current_addr_index = index;
            #ifdef __MMI_MMS_POSTCARD__
                if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                {
                    mmi_postcard_entry_import_manual();
                }
                else
            #endif /* __MMI_MMS_POSTCARD__ */ 
                {
                    mmi_uc_entry_enter_recipient();
                }
            }
            else if (index == MMI_UC_ADD_FROM_CONTACTS)
            {
                /* use g_uc_p->done.to buffer to store email */
                ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
                memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
                g_uc_p->done.current_addr_index = index;
            #ifdef __MMI_MMS_POSTCARD__
                if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                {
                #ifdef __MMI_PHB_INFO_FIELD__
                    mmi_postcard_entry_import_phonebook(); 
                #endif /* __MMI_PHB_INFO_FIELD__ */ 
                }
                else
            #endif /* __MMI_MMS_POSTCARD__ */ 
                {
                    mmi_uc_search_phb_recipient();
                }
                return;
            }
	    }
        else
        {
        if( tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
        {
        #ifdef __MMI_MMS_POSTCARD__
            if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
            {
                mmi_postcard_entry_to_option_edit();
            }
            else
        #endif /* __MMI_MMS_POSTCARD__ */ 
            {
                memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
                mmi_uc_pre_entry_edit_addr();
            }
            return;
        }
    }
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  cui_uc_frm_app_set_data_for_add_object_option_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance_hash_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_frm_app_set_data_for_add_object_option_list(mmi_id sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_AUDIO, MMI_TRUE);
        #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_TRUE);
        #endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_HEADER_OPTIONS, MMI_TRUE);
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#ifndef __MMI_SLIM_MMS_2__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
        #ifdef __MMI_CAMERA__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_TRUE);
        #endif
         #ifdef __MMI_SOUND_RECORDER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_AUDIO, MMI_TRUE);
        #endif
        #if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_TRUE);
        #endif /* defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)*/
#endif
    #else 
        MMI_ASSERT(0);
    #endif 
    }
    else
    {
    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            /* postcard disallow to add other media */
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
#endif
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_AUDIO, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
         #ifdef __MMI_SOUND_RECORDER__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_AUDIO, MMI_TRUE);
         #endif /*__MMI_SOUND_RECORDER__*/
#endif
         #ifdef __MMI_MMS_VIDEO_FEATURE__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
		#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_TRUE);
		#endif /* __MMI_VIDEO_RECORDER__ && !MJPG_SUPPORT*/
#endif
		    #endif
            

            /* Only allow insert one image */
            if ((g_uc_p->srv_msg->msg_body.slide_no == 1) && (g_uc_p->srv_msg->msg_body.curr_slide->image.object != NULL))
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
            #ifdef __MMI_CAMERA__   
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_TRUE);
            #endif /* __MMI_CAMERA__ */
#endif
            }
			else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_FALSE);
#ifndef __MMI_SLIM_MMS_2__
            #ifdef __MMI_CAMERA__
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_FALSE);
            #endif /* __MMI_CAMERA__ */
#endif
            }
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
            if (g_uc_p->srv_msg->msg_body.total_attach_no == SRV_UC_MAX_ATTACHMENT_NUM)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_FALSE);
            }
#ifndef __MMI_SLIM_MMS_2__
            if (g_uc_p->srv_msg->msg_body.slide_no < SRV_UC_MAX_MMS_SLIDE_NUM &&
                (g_uc_p->srv_mms_info->signature.text_file ||
                g_uc_p->srv_mms_info->signature.img_file ||
                g_uc_p->srv_mms_info->signature.audio_file ||
                g_uc_p->srv_mms_info->signature.video_file))
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
            }
#endif
            if ((g_uc_p->srv_msg->msg_body.slide_no == SRV_UC_MAX_MMS_SLIDE_NUM) ||
                /* disallow user to add any slide after signature, ex. insert img if there is already an img in last slide */
                ((g_uc_p->srv_msg->msg_body.slide_no == g_uc_p->srv_msg->current_slide_num) &&
                 g_uc_p->srv_msg->signature_in_last_slide))
            {
                if (g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
                    #ifdef __MMI_CAMERA__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_TRUE);
                    #endif /* __MMI_CAMERA__ */
#endif
                }
		        else
		        {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_FALSE);
        #ifndef __MMI_SLIM_MMS_2__
		        #ifdef __MMI_CAMERA__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_FALSE);
		        #endif /* __MMI_CAMERA__ */
        #endif
		        }

                if (g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_AUDIO, MMI_TRUE);
            #ifndef __MMI_SLIM_MMS_2__
		    #ifdef __MMI_SOUND_RECORDER__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_AUDIO, MMI_TRUE);
            #endif
            #endif
                }
		        else
		        {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_AUDIO, MMI_FALSE);
#ifndef __MMI_SLIM_MMS_2__
		        #ifdef __MMI_SOUND_RECORDER__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_AUDIO, MMI_FALSE);
		        #endif /* __MMI_SOUND_RECORDER__ */
#endif
		        }

                if (g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL)
                {
            #ifdef __MMI_MMS_VIDEO_FEATURE__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_TRUE);
            #ifndef __MMI_SLIM_MMS_2__
		    #if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_TRUE);
		    #endif /* __MMI_VIDEO_RECORDER__ && !MJPG_SUPPORT*/
            #endif
		    #endif
                }
		        else
		        {
		        #ifdef __MMI_MMS_VIDEO_FEATURE__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_FALSE);
                #ifndef __MMI_SLIM_MMS_2__
		        #if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_FALSE);
		        #endif /* __MMI_VIDEO_RECORDER__ */
                #endif
		        #endif
                }
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_IMAGE, MMI_FALSE);
#ifndef __MMI_SLIM_MMS_2__
			#ifdef __MMI_CAMERA__
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_IMAGE, MMI_FALSE);
			#endif /* __MMI_CAMERA__ */
#endif
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_AUDIO, MMI_FALSE);
#ifndef __MMI_SLIM_MMS_2__
			#ifdef __MMI_SOUND_RECORDER__
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_AUDIO, MMI_FALSE);
			#endif /* __MMI_SOUND_RECORDER__ */
#endif
            #ifdef __MMI_MMS_VIDEO_FEATURE__
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_FALSE);
#ifndef __MMI_SLIM_MMS_2__
			#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_FALSE);
			#endif /* __MMI_VIDEO_RECORDER__ && !MJPG_SUPPORT */
#endif
            #endif /* __MMI_MMS_VIDEO_FEATURE__ */ 
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_FALSE);
            }
        }
    }
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL,SRV_UCM_VIDEO_CALL_TYPE_ALL,NULL)>0)
    {
        #ifdef __MMI_MMS_VIDEO_FEATURE__
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_VIDEO, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
			#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_NEW_VIDEO, MMI_TRUE);
			#endif /* __MMI_VIDEO_RECORDER__ && !MJPG_SUPPORT */
#endif
            #endif /* __MMI_MMS_VIDEO_FEATURE__ */ 
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
mmi_ret mmi_uc_header_field_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_of_states[3] = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_get_checkbox_state(menu_evt->sender_id, list_of_states);
    g_uc_p->main.cc_region_flag = list_of_states[0];
    g_uc_p->main.bcc_region_flag = list_of_states[1];
    g_uc_p->main.subject_region_flag = list_of_states[2];
    mmi_uc_handle_user_selection_for_screen();
    mmi_frm_group_close(menu_evt->sender_id);
    return MMI_RET_OK;

}
void cui_uc_app_set_menu_for_opt_header_options(mmi_id sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = sender_id;
    U8 list_of_states[3] = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_of_states[0] = g_uc_p->main.cc_region_flag;
    list_of_states[1] = g_uc_p->main.bcc_region_flag;
    list_of_states[2] = g_uc_p->main.subject_region_flag;

    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_CHECK_BOX_LIST);

    cui_menu_set_checkbox_state(cui_menu_gid, list_of_states);

    return;

}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#ifndef __MMI_FTE_SUPPORT__
void cui_uc_frm_app_set_data_for_exit_opt(mmi_id sender_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	   if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD || g_uc_p->srv_main->state == MMI_UC_STATE_SEND)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_EXIT_OPT_SAVE, MMI_TRUE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
    }
    else
    {
        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_EXIT_OPT_SAVE, MMI_TRUE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_EXIT_OPT_SAVE, MMI_FALSE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
        }
    }
	if (
	   (g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_UNCLASSIFIED)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM1)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM2)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM3)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM4)/*kuldeep_nosim*/
	   )
	{
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
	}
	else
	{
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
	}

}
#endif
void cui_uc_app_set_menu_data_for_uc_editor_option(mmi_id sender_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
 #if (MMI_MAX_SIM_NUM >=2)
	if (!(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM1) || !(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM2))
	{
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_FALSE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
	}
#endif
#endif
#ifdef __MMI_OP02_LEMEI__
	/*advanced option not shown in lemei mms */
   if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
    {
        cui_menu_set_group_hidden(sender_id, MENU_GROUP_EDITOR, MMI_TRUE);
    }
   if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
    {
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADVANCED, MMI_TRUE);
    }
   else
#endif
	{
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADVANCED, MMI_FALSE);
	}
#ifndef __MMI_SLIM_MMS_2__
#ifdef __MMI_OP02_LEMEI__
   /*msg detail not shown in lemei mms*/
    if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_DETAIL, MMI_TRUE);
	}
	else
#endif
	{
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_DETAIL, MMI_FALSE);
	}
	
#endif
    if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_TEXT_OPTIONS, MMI_TRUE);
#endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_TRUE);
    //#ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_TRUE);
    //#endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PREVIEW, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_TRUE);
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_HEADER_OPTIONS, MMI_FALSE);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_AS_TEMPLATE, MMI_TRUE);
#endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_FALSE);
    #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_FALSE);
    #endif
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
    }
    else if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
		if (g_uc_p->srv_msg->msg_body.curr_slide->img.object 
           #if 0
/* under construction !*/
           #endif
           )
            {
#ifdef __MMI_OP02_LEMEI__
				/*while highlight image picture edit option not shown in lemei mms*/
              if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
			  {
			   cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPTIONS, MMI_TRUE);
			  }
			  else
#endif
			  {
			  cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPTIONS, MMI_FALSE);
			  }
					 
         }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPTIONS, MMI_TRUE);
        }
        if (g_uc_p->srv_msg->msg_body.curr_slide->aud.object
#if 0
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/* under construction !*/
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#endif
            )
          {
            #ifdef __MMI_OP02_LEMEI__
			  /*highlight sound , sound option not shown in lemei mms */
                if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
				{
                 cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_TRUE);
				}
	            else
           #endif
				{
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_FALSE);
               }
		}
		 else
        {
          cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_TRUE);
        }
//#ifdef __MMI_MMS_VIDEO_FEATURE__
	   if (g_uc_p->srv_msg->msg_body.curr_slide->vid.object
          #if 0
/* under construction !*/
          #endif
          )
           {
#ifdef __MMI_OP02_LEMEI__
			   /*in lemei mms video option hide*/
            if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
				{
				cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_TRUE);
            	}
			else
#endif
				{
				cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_FALSE);
				}
			
				
            }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_TRUE);
        }
//#endif
        if (g_uc_p->srv_msg->msg_body.total_attach_no)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, MMI_TRUE);
        }
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        if (g_uc_p->srv_msg->msg_body.curr_slide->txt.object && g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_EDITOR)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_TEXT_OPTIONS, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_TEXT_OPTIONS, MMI_TRUE);
        }
#endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PREVIEW, MMI_FALSE);
	 #ifdef __MMI_OP02_LEMEI__
		/*only one media allowed in lemei*/
       if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	    {
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_TRUE);
    #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
    #endif 
		}
	  else
     #endif /*__MMI_OP02_LEMEI__*/
	    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_FALSE);
    #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_FALSE);
    #endif 
	    }
#ifdef __MMI_OP02_LEMEI__
		/* hide save mms option in lemei*/
        if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_TRUE);
        }
	else
#endif
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_FALSE);
	}
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
 #ifdef __MMI_OP02_LEMEI__
		/*hide send option in lemei mms*/
      if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
       cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_TRUE);
        }
      else
#endif
	{
	  cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_TRUE);
	}
#ifdef __MMI_OP02_LEMEI__
      /*hide header option in lemei mms*/
	  if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_HEADER_OPTIONS, MMI_TRUE);
        }
	else
#endif
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_HEADER_OPTIONS, MMI_FALSE);
	}
			
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#ifdef __MMI_OP02_LEMEI__
	  /*do not save mms as template in lemei mms*/
        if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_AS_TEMPLATE, MMI_TRUE);
        }
	else
#endif
	{
	cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_AS_TEMPLATE, MMI_FALSE);
	}
#endif
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
    }
    else
    {
        MMI_ASSERT(0);
    }
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY ||
        g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_MMS_ONLY ||
        mmi_uc_determine_msg_type_by_content() == MMI_UC_MSG_TYPE_MMS_PREFER
        /* postcard disallow to replace or set slide option or change msg type */
#ifdef __MMI_MMS_POSTCARD__
        || (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
#endif 
        )
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_SMS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_MMS, MMI_TRUE);
    }
    else
    {
        if (MMI_UC_MSG_TYPE_MMS_PREFER == g_uc_p->srv_msg_type->curr_msg_type)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_SMS, MMI_FALSE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_MMS, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_MMS, MMI_FALSE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_SMS, MMI_TRUE);
        }
    }
#endif

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SUBJECT, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_EDIT_SUBJECT, MMI_TRUE);
    }
    else if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->subject) > 0)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SUBJECT, MMI_TRUE);
        if (g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_SUBJECT)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_EDIT_SUBJECT, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_EDIT_SUBJECT, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_EDIT_SUBJECT, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SUBJECT, MMI_FALSE);
    }
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_TRUE);
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_TEXT_OPTIONS, MMI_TRUE);
#endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_TRUE);
        #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
        #endif
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PREVIEW, MMI_TRUE);
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_HEADER_OPTIONS, MMI_TRUE);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    }
    else
    {
    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            /* postcard disallow to replace or set slide option, change msg type and add other media */
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_TRUE);
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_TEXT_OPTIONS, MMI_TRUE);
#endif
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SOUND_OPTIONS, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_VIDEO_OPTIONS, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_TRUE);
        #ifdef __MMI_MMS_VIDEO_FEATURE__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
        #endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SUBJECT, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_EDIT_SUBJECT, MMI_TRUE);
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_AS_TEMPLATE, MMI_TRUE);
#endif

            /* Only allow insert one image */
            if ((g_uc_p->srv_msg->msg_body.slide_no == 1) && (g_uc_p->srv_msg->msg_body.curr_slide->image.object != NULL))
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_TRUE);
            }
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
                if ((g_uc_p->srv_msg->msg_body.slide_no == SRV_UC_MAX_MMS_SLIDE_NUM) ||
                    /* disallow user to add any slide after signature, ex. insert img if there is already an img in last slide */
                    ((g_uc_p->srv_msg->msg_body.slide_no == g_uc_p->srv_msg->current_slide_num) &&
                     g_uc_p->srv_msg->signature_in_last_slide))
            {
                if (g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_TRUE);
                }
    
                if (g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_TRUE);
                }
    
                if (g_uc_p->srv_msg->msg_body.curr_slide->vid.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->img.object != NULL ||
                    g_uc_p->srv_msg->msg_body.curr_slide->aud.object != NULL)
                {
                	#ifdef __MMI_MMS_VIDEO_FEATURE__
                    cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
                  #endif 
                }
            }
            else
            {
         #ifdef __MMI_OP02_LEMEI__
				/*only one media allowed in lemei*/
             if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	         { 
			  cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_TRUE);
              cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_TRUE);
            #ifdef __MMI_MMS_VIDEO_FEATURE__
              cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
            #endif 
			  }
			 else
         #endif /*__MMI_OP02_LEMEI__*/
			 {
			 cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_PICTURE, MMI_FALSE);
             cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_SOUND, MMI_FALSE);
            #ifdef __MMI_MMS_VIDEO_FEATURE__
             cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_FALSE);
            #endif 
			 }
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_FALSE);
            }
	 #ifdef __MMI_OP02_LEMEI__
       if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
	    {
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_TRUE);
	    }
	   else
     #endif
	   {
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT, MMI_FALSE);
	   }
		}
    }
	if (
		(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_UNCLASSIFIED)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM1)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM2)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM3)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM4)/*kuldeep_nosim*/
	   )
	{
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_FALSE);
#endif
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
	}
	else
	{
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
#endif
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
#if (defined(__OP01__) && defined(__MMI_DUAL_SIM_MASTER__))
/* under construction !*/
/* under construction !*/
#endif
#endif

	}
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
	if(mmi_uc_get_buffer_recipient_count() ==0)
	{
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_FALSE);
	}
	if(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_UNCLASSIFIED)
	{
      #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		if(!srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM1) && !srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM2)
            #if (MMI_MAX_SIM_NUM >= 3)
            && !srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM3) 
            #if (MMI_MAX_SIM_NUM == 4)
            && !srv_sim_ctrl_is_available(SRV_UC_SIM_ID_GSM_SIM4)
            #endif
            #endif
          )
        {
            cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
	}
        else
      #endif
        {
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
	}
        }
#endif
    if(g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_THUMBNAIL)
    {
        wgui_inputs_options_menu_hide_items(sender_id,MMI_TRUE);
    }
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    if(g_uc_p->main.highlight_state == MMI_UC_HIGHLIGHT_AUDIO)
    {
        wgui_inputs_options_menu_hide_items(sender_id,MMI_TRUE);
    }
#endif
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL,SRV_UCM_VIDEO_CALL_TYPE_ALL,NULL)>0)
    {
        #ifdef __MMI_MMS_VIDEO_FEATURE__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_ADD_VIDEO, MMI_TRUE);
        #endif               
    }
    mmi_imm_create_input_method_list(IMM_INPUT_TYPE_SENTENCE, NULL);
}
/*****************************************************************************
 * FUNCTION
 *  cui_uc_app_set_menu_for_opt_advance_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_app_set_menu_for_opt_advance_options(mmi_id sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
#endif

    #else 
        MMI_ASSERT(0);
    #endif 
    }
    else
    {
    #ifdef __MMI_MMS_POSTCARD__
        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
#ifndef __MMI_SLIM_MMS_2__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
#endif
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
            if (g_uc_p->srv_msg->msg_body.total_attach_no == SRV_UC_MAX_ATTACHMENT_NUM)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_ATTACHMENT, MMI_FALSE);
            }
#ifndef __MMI_SLIM_MMS_2__
            if (g_uc_p->srv_msg->msg_body.slide_no < SRV_UC_MAX_MMS_SLIDE_NUM &&
                (g_uc_p->srv_mms_info->signature.text_file ||
                g_uc_p->srv_mms_info->signature.img_file ||
                g_uc_p->srv_mms_info->signature.audio_file ||
                g_uc_p->srv_mms_info->signature.video_file))
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_INSERT_SIGNATURE, MMI_TRUE);
            }
#endif
        }
    }   

}

/*****************************************************************************
 * FUNCTION
 *  cui_uc_app_set_menu_for_opt_picture_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_app_set_menu_for_opt_picture_opt(mmi_id sender_id)
{
#ifdef __MMI_MMS_POSTCARD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
    #if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING, MMI_TRUE);
    #endif 
    #ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REPLACE, MMI_TRUE);
    #endif 

    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
    #if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING, MMI_FALSE);
    #endif 
    #ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REPLACE, MMI_FALSE);
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_app_set_menu_for_opt_slide_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_app_set_menu_for_opt_slide_opt(mmi_id sender_id)
{
#ifdef __MMI_MMS_POSTCARD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
    #if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING, MMI_TRUE);
    #endif 
    #ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REPLACE, MMI_TRUE);
    #endif 

    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
    #if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING, MMI_FALSE);
    #endif 
    #ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REPLACE, MMI_FALSE);
    #endif 
    }
    if (g_uc_p->srv_msg->msg_body.slide_no < SRV_UC_MAX_MMS_SLIDE_NUM)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_INSERT, MMI_FALSE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_INSERT, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE, MMI_TRUE);
    }

    /* disallow user to insert slide after signature */
    if (g_uc_p->srv_msg->signature_in_last_slide &&
        (g_uc_p->srv_msg->msg_body.slide_no == g_uc_p->srv_msg->current_slide_num))
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_INSERT, MMI_TRUE);
    }

    if (g_uc_p->srv_msg->msg_body.slide_no > 1)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_DELETE, MMI_FALSE);
        /* mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_GO_TO); */
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_DELETE, MMI_TRUE);
        /* mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_GO_TO); */
    }

    if (g_uc_p->srv_msg->msg_body.curr_slide->prev)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS, MMI_TRUE);
    }

    if (g_uc_p->srv_msg->msg_body.curr_slide->next)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_NEXT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_NEXT, MMI_TRUE);
    }
#ifdef __MMI_MMS_2__
    if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_TIMING, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SLIDE_OPT_TIMING, MMI_TRUE);
    }
#endif
}

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  cui_uc_app_set_menu_for_opt_add_recipient_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_app_set_menu_for_opt_add_recipient_opt(mmi_id sender_id)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_TO, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_CC, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_BCC, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_FALSE);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_TO, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_CC, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_BCC, MMI_TRUE);
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND_OPT, MMI_FALSE);
        }

        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            addr = mmi_uc_get_highlighted_addr();
            g_uc_p->done.current_addr_type = addr->group;
            if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_TO, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_CC, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_BCC, MMI_FALSE);
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_TO, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_CC, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_BCC, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_TO, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_CC, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_CHANGE_TO_BCC, MMI_TRUE);
            }
        }
    }
    if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD || g_uc_p->srv_main->state == MMI_UC_STATE_SEND)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_TRUE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
    }
    else
    {
        if (g_uc_p->srv_msg_type->curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_TRUE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
        }
        else
        {
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_TO_DRAFT, MMI_FALSE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
            cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
        }
    }
	if (
	   (g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_UNCLASSIFIED)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM1)
	   ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM2)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM3)
       ||(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_GSM_SIM4)/*kuldeep_nosim*/
	   )
	{
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_FALSE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_FALSE);
#endif
	}
	else
	{
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
		cui_menu_set_non_leaf_item(sender_id, MENU_ID_UC_OPT_SAVE_SMS, MMI_TRUE);
#endif
#if (defined(__OP01__) && defined(__MMI_DUAL_SIM_MASTER__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	}/*kuldeep_nosim*/
	if(g_uc_p->srv_sim_info->valid_sim_id_info == SRV_UC_SIM_ID_UNCLASSIFIED)
	{
      #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if(!srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM1) && !srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM2)
            #if (MMI_MAX_SIM_NUM >= 3)
            && !srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM3) 
            #if (MMI_MAX_SIM_NUM == 4)
            && !srv_sim_ctrl_is_available((mmi_sim_enum)SRV_UC_SIM_ID_GSM_SIM4)
            #endif
            #endif
          )
        {
            cui_menu_set_item_disabled(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
        }
        else
      #endif
		{
		cui_menu_set_item_hidden(sender_id, MENU_ID_UC_OPT_SEND, MMI_TRUE);
	}
}
}
#endif /* #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  cui_uc_highlight_slide_opt_image_timing
 * DESCRIPTION
 *  Funtion is called when image timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_highlight_slide_opt_image_timing(void)
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
    return;
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_highlight_slide_opt_audio_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_highlight_slide_opt_audio_timing(void)
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

    return;
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_highlight_slide_opt_video_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_highlight_slide_opt_video_timing(void)
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


    return;
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_highlight_slide_opt_text_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_highlight_slide_opt_text_timing(void)
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

    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_uc_highlight_slide_opt_slide_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_highlight_slide_opt_slide_timing(void)
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

    return;
}
#if (MMI_MAX_SIM_NUM >= 3)

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_menu_for_sim_option
 * DESCRIPTION
 *  Funtion is called for set menu
 * PARAMETERS
 *  sender_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_menu_for_sim_option(mmi_id sender_id)
{

if( !(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM1))
{
cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM1, MMI_TRUE);
}
    else
      {
	  cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM1, MMI_FALSE);
      }
if(!(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM2))
{
cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM2, MMI_TRUE);
}
   else
     {
	 cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM2, MMI_FALSE);
     }
if(!(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM3))
{
cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM3, MMI_TRUE);
}
   else
   {
   cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM3, MMI_FALSE);
   }
 #if (MMI_MAX_SIM_NUM >= 4)
if(!(g_uc_p->srv_sim_info->valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM4))
{
cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM4, MMI_TRUE);
}
 else
   {
   cui_menu_set_item_hidden(sender_id,MENU_ID_UC_OPT_SEND_SIM4, MMI_FALSE);
}
#endif/*(GEMINI_PLUS == 4)*/
}
#endif/*(GEMINI_PLUS >= 3)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_write_msg_send_key_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index        [IN]        
 * RETURNS	
 *  void
 *****************************************************************************/
void mmi_uc_write_msg_send_key_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        mmi_uc_remove_empty_recipients();
        if(mmi_uc_get_buffer_recipient_count() ==0)
        {
            g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            mmi_uc_search_phb_recipient();
        }
    #else
        if (g_uc_p->srv_msg->to_num == 0)
        {
            mmi_uc_pre_entry_add_recipient();
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        else
        {
			#if (MMI_MAX_SIM_NUM >=2)
		        g_uc_p->srv_sim_info->action = SRV_UC_ACTION_SEND;
		        g_uc_p->main.parent_grp_id = g_uc_p->main.uc_cui_gid;
		        g_uc_p->main.uc_cui_gid = mmi_frm_group_create(
	            g_uc_p->main.parent_grp_id, GRP_ID_UNIFIED_COMPOSER_MENU_CUI, mmi_uc_add_media_proc, (void*)NULL); 
		        mmi_frm_group_enter(g_uc_p->main.uc_cui_gid , MMI_FRM_NODE_SMART_CLOSE_FLAG);
		        mmi_uc_pre_entry_sim_option_csk();
			#else 
				mmi_uc_exit_write_msg();
		        mmi_uc_process_send();
			#endif 
        }
}


#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */

#endif /* __MMI_TELEPHONY_SUPPORT__ */
