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
 * UcMsgHdlrApp.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements all msg handler apis for Unified Composer.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MMI_UNIFIED_COMPOSER_APP_MSG_HDLR_C
#define _MMI_UNIFIED_COMPOSER_APP_MSG_HDLR_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "Conversions.h"
//#include "Commonscreens.h"
#include "MessagesExdcl.h"
//#include "app_str.h"
#include "wapadp.h"
//#include "wap_ps_struct.h"
#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "UcResDef.h"
#include "Custom_events_notify.h"
#include "UcSrvGprot.h"
#include "UcSrvIprot.h"
#include "UcAppGprot.h"
#include "FileMgrGProt.h"
#include "BootupSrvGprot.h"
#include "kal_public_api.h"
#include "UcAppProt.h"
#include "UcPcrdProt.h"
#ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
#ifndef WAP_SUPPORT
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#else /* WAP_SUPPORT */ 
#include "WAPProfileSrvGProt.h"
#endif /* WAP_SUPPORT */ 
#endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 
//#if (MMI_MAX_SIM_NUM ==2)
//#include "SimDetectionGprot.h"
//#endif 
#include "MMSAppCommonGprot.h"
#include "mmi_rp_app_sms_def.h"
#include "bookmarkcuigprot.h"
//#if(MMI_MAX_SIM_NUM >=2)kuldeep_nosim
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoSrvGprot.h"
//#if(MMI_MAX_SIM_NUM == 2)
//#include "MTPNP_AD_master_header.h"
//#endif
//#endif
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__*/
//suggested add
    #include "MMI_features.h"
    #include "mmi_frm_events_gprot.h"
    #include "kal_public_defs.h"
    #include "MMIDataType.h"
    //#include "kal_general_types.h"
    #include "mma_api.h"
    #include "mdi_audio.h"
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)
    #include "mdi_video.h"
    #endif
    #include "mma_struct.h"
    //#include "kal_public_api.h"
    #include "string.h"
    #include "custom_wap_config.h"
    #include "Unicodexdcl.h"
    #include "DebugInitDef_Int.h"
    //#include "op_custom_ps_inc.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "FileMgrGProt.h"
    #include "FileMgrType.h"
   // #include "MMI_common_app_trc.h"
    #include "kal_trace.h"
    #include "mmi_common_app_trc.h"
    #include "WAPProfileSrvType.h"
    #include "mms_api.h"
    #include "UcmSrvGprot.h"
    #include "UmSrvDefs.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "FileMgrSrvGProt.h"
    #include "AlertScreen.h"
    #include "CommonScreensResDef.h"
    #include "wgui_categories_util.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_timer_gprot.h"
    //#include "TimerEvents.h"
    #include "fs_errcode.h"
    #include "mms_sap_struct.h"
    #include "CustDataRes.h"
    #include "gui_data_types.h"
    #include "mmi_frm_mem_gprot.h"
    #include "app_mem.h"
    //#include "SimDetectionStruct.h"
    #include "gui_config.h"
    #include "wgui_categories_UCE.h"

extern kal_uint32 applib_get_file_size(kal_wchar *filename);
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_protocol_event_handler
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #if (MMI_MAX_SIM_NUM ==2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
	#endif
/* under construction !*/
/* under construction !*/
	#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_start_req
 * DESCRIPTION
 *  Handler for start UC request
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_start_req(void *inMsg)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
    #ifdef __MMI_MMS_STANDALONE_COMPOSER__
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_start_rsp
 * DESCRIPTION
 *  Handler for start UC response
 * PARAMETERS
 *  result          [IN]        
 *  msg_id          [IN]        
 *  app_mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_start_rsp(U16 result, U32 msg_id, U16 app_mode)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_setting
 * DESCRIPTION
 *  Get MMS setting response
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_insert_sig_result_enum pass_sig_check = MMI_UC_INSERT_SIG_RESULT_PASS;
    mma_insert_info_struct insert_info;
    mma_signature_struct *signature = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_msg->display_no_resize = MMI_FALSE;
    signature = kal_adm_alloc(g_uc_p->main.mem_pool_id, sizeof(mma_signature_struct));
    if (signature != NULL)
    {
        memset(signature, 0, sizeof(mma_signature_struct));
    }
#ifdef __MMI_OP02_LEMEI__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
    {
        g_uc_p->srv_mms_info->creation_mode = MMA_CREATION_MODE_FREE;
    }
    else
#endif /*__MMI_OP02_LEMEI__*/
    {
        g_uc_p->srv_mms_info->creation_mode = srv_mms_compose_settings_creation_mode();
    }

    g_uc_p->srv_mms_info->priority = srv_mms_sending_settings_priority();
    g_uc_p->srv_mms_info->validity_period = srv_mms_sending_settings_validity_period();
    g_uc_p->srv_mms_info->delivery_time = srv_mms_sending_settings_delivery_time();
    g_uc_p->srv_mms_info->delivery_report = srv_mms_sending_settings_delivery_report();
    g_uc_p->srv_mms_info->read_report = srv_mms_sending_settings_read_report();
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
  #ifdef __MMI_OP02_LEMEI__
	/*in lemei mms ,size will be 300kb*/
	if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
     { 
     g_uc_p->srv_mms_info->max_mms_size = (U32)MMA_SETTING_SIZE_LIMIT_300;
	}
	else
#endif/*__MMI_OP02_LEMEI__*/
	{
	g_uc_p->srv_mms_info->max_mms_size = (U32)srv_mms_sending_mms_size_limit();
	}
#else
    g_uc_p->srv_mms_info->max_mms_size = wap_custom_get_max_mms_msg_size();
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
    g_uc_p->srv_mms_info->best_page_duration = srv_mms_compose_settings_best_page_duration(); /* E_OFF=0/E_ON=1 */
    srv_mms_compose_setting_image_resize_info(&g_uc_p->srv_mms_info->image_resize);
    srv_mms_compose_settings_default_slide_time(&g_uc_p->srv_mms_info->sliding_time);
    g_uc_p->srv_mms_info->hide_sender = srv_mms_sending_settings_hide_sender();     /* __MMI_MMS_HIDE_SENDER_SUPPORT__   */
    srv_uc_reset_mms_signature(g_uc_p->main.instance);
    if (signature != NULL)
    {
        U32 file_path_len;
        srv_mms_compose_settings_sign_info(signature);
        g_uc_p->srv_mms_info->signature.enable = signature->enable;

    //if ((g_uc_p->srv_mms_info->signature.enable = signature->enable) == TRUE)

        if ((file_path_len = mmi_ucs2strlen((S8*) signature->text_file)) > 0)
        {
            g_uc_p->srv_mms_info->signature.text_file = kal_adm_alloc(
                                                            g_uc_p->main.mem_pool_id,
                                                            (file_path_len + 1) * ENCODING_LENGTH);
            MMI_ASSERT(g_uc_p->srv_mms_info->signature.text_file);
			if(!(g_uc_p->srv_mms_info->signature.text_file))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}
            mmi_ucs2ncpy(
                (S8*) g_uc_p->srv_mms_info->signature.text_file,
                (S8*) signature->text_file,
                file_path_len);
        }
        if ((file_path_len = mmi_ucs2strlen((S8*) signature->img_file)) > 0)
        {
            g_uc_p->srv_mms_info->signature.img_file = kal_adm_alloc(
                                                        g_uc_p->main.mem_pool_id,
                                                        (file_path_len + 1) * ENCODING_LENGTH);
            MMI_ASSERT(g_uc_p->srv_mms_info->signature.img_file);
	    	if(!(g_uc_p->srv_mms_info->signature.img_file))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}
            mmi_ucs2ncpy(
                (S8*) g_uc_p->srv_mms_info->signature.img_file,
                (S8*) signature->img_file,
                file_path_len);
        }
        if ((file_path_len = mmi_ucs2strlen((S8*) signature->audio_file)) > 0)
        {
            g_uc_p->srv_mms_info->signature.audio_file = kal_adm_alloc(
                                                            g_uc_p->main.mem_pool_id,
                                                            (file_path_len + 1) * ENCODING_LENGTH);
            MMI_ASSERT(g_uc_p->srv_mms_info->signature.audio_file);
            if(!(g_uc_p->srv_mms_info->signature.audio_file))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}			
            mmi_ucs2ncpy(
                (S8*) g_uc_p->srv_mms_info->signature.audio_file,
                (S8*) signature->audio_file,
                file_path_len);
        }
        if ((file_path_len = mmi_ucs2strlen((S8*) signature->video_file)) > 0)
        {
            g_uc_p->srv_mms_info->signature.video_file = kal_adm_alloc(
                                                            g_uc_p->main.mem_pool_id,
                                                            (file_path_len + 1) * ENCODING_LENGTH);

            MMI_ASSERT(g_uc_p->srv_mms_info->signature.video_file);
			if(!(g_uc_p->srv_mms_info->signature.video_file))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}
            mmi_ucs2ncpy(
                (S8*) g_uc_p->srv_mms_info->signature.video_file,
                (S8*) signature->video_file,
                file_path_len);
        }
    }

    g_uc_p->srv_msg->read_report = g_uc_p->srv_mms_info->read_report;
    g_uc_p->srv_msg->delivery_report = g_uc_p->srv_mms_info->delivery_report;
    g_uc_p->srv_msg->priority = g_uc_p->srv_mms_info->priority;
    g_uc_p->srv_msg->expiry_time = srv_uc_convert_mms_expiry_time_to_uc(g_uc_p->srv_mms_info->validity_period);
    g_uc_p->srv_msg->delivery_time = srv_uc_convert_mms_delivery_time_to_uc(g_uc_p->srv_mms_info->delivery_time);
    g_uc_p->srv_msg->slide_timing = g_uc_p->srv_mms_info->sliding_time.value;
    g_uc_p->srv_msg->hide_sender = g_uc_p->srv_mms_info->hide_sender;
	g_uc_p->srv_msg->best_page_duration = g_uc_p->srv_mms_info->best_page_duration;
    g_uc_p->srv_msg->msg_body.bgColor= SRV_UC_DEFAULT_BG_COLOR;
    g_uc_p->srv_msg->msg_body.fgColor= SRV_UC_DEFAULT_FG_COLOR;
	
	g_uc_p->srv_msg->msg_header.read_reply = srv_uc_convert_mms_rr_to_mma_rr(g_uc_p->srv_mms_info->read_report);
	g_uc_p->srv_msg->msg_header.delivery_report = srv_uc_convert_mms_dr_to_mma_dr(g_uc_p->srv_mms_info->delivery_report);
	//g_uc_p->srv_msg->msg_header.priority = srv_uc_convert_mms_prio_to_mma_prio(g_uc_p->srv_mms_info->priority);
	g_uc_p->srv_msg->msg_header.priority = g_uc_p->srv_mms_info->priority;
	g_uc_p->srv_msg->msg_header.expiry_time = (mma_mms_time_sec)g_uc_p->srv_mms_info->validity_period ;
	g_uc_p->srv_msg->msg_header.delivery_time = (mma_mms_time_sec)g_uc_p->srv_mms_info->delivery_time ;
	g_uc_p->srv_msg->msg_header.visibility = srv_uc_convert_mms_vis_to_mma_vis(g_uc_p->srv_mms_info->hide_sender);
    #ifdef __MMI_OP02_LEMEI__
    g_uc_p->srv_msg->msg_header.msg_class.class_identifier = MMA_MSG_CLASS_INFORMATIONAL ;
    #endif
#ifdef __MMI_MMS_POSTCARD__
    /* fill server info */
    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {

        memset(g_uc_p->done.to, 0, sizeof(g_uc_p->done.to));
    #ifdef __MMI_UC_POSTCARD_INTERNAL_TESTING__
        /* internal project, will use mmi_postcard_get_mms_postcard_server_addr, for testing */
        if (strlen((PS8) mmi_postcard_get_mms_postcard_server_addr()) > MMI_UC_MAX_EMAIL_LEN)
        {
            mmi_asc_n_to_ucs2(
                (PS8) g_uc_p->done.to,
                (PS8) mmi_postcard_get_mms_postcard_server_addr(),
                MMI_UC_MAX_EMAIL_LEN);

        }
        else
        {
            mmi_asc_to_ucs2((PS8) g_uc_p->done.to, (PS8) mmi_postcard_get_mms_postcard_server_addr());
        }
    #else /* __MMI_UC_POSTCARD_INTERNAL_TESTING__ */ 
        if (strlen((S8*) wap_custom_get_mms_postcard_server_addr()) > MMI_UC_MAX_EMAIL_LEN)
        {
            mmi_asc_n_to_ucs2(
                (PS8) g_uc_p->done.to,
                (PS8) wap_custom_get_mms_postcard_server_addr(),
                MMI_UC_MAX_EMAIL_LEN);
        }
        else
        {
            /* Should replace tmp API for test before MP */
            mmi_asc_to_ucs2((PS8) g_uc_p->done.to, (PS8) wap_custom_get_mms_postcard_server_addr());
        }
    #endif /* __MMI_UC_POSTCARD_INTERNAL_TESTING__ */ 

        srv_uc_add_address(
            g_uc_p->main.instance,
            g_uc_p->done.to,
            MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
            MMI_UC_ADDRESS_GROUP_TYPE_TO);

    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        /* resizing of signature image. */
        if (signature != NULL)
        {
            if (mmi_ucs2strlen((S8*)signature->img_file) > 0
                && g_uc_p->srv_mms_info->image_resize.enable
				&& mmi_uc_is_valid_image(g_uc_p->srv_mms_info->signature.img_file))
            {
                U8 mmi_uc_image_path[SRV_UC_MAX_TEMP_FILE_LEN] ={0,};
                GDI_RESULT resize_result = 0, file_path_len = 0;
    
                srv_uc_make_signature_image_file_path(mmi_uc_image_path, g_uc_p->main.instance);
        #ifdef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__
                g_uc_p->srv_mms_info->image_resize.width = 160;
                g_uc_p->srv_mms_info->image_resize.height = 120;
        #endif
                resize_result = mmi_uc_resize_image(
                                        (U8*) signature->img_file, 
                                        mmi_uc_image_path, 
                                        g_uc_p->srv_mms_info->image_resize.width,
                                        g_uc_p->srv_mms_info->image_resize.height);
            
                /* Error ! */
                if (resize_result < 0 || resize_result == SRV_UC_RESIZING_SUCCEED_WITH_UNCHANGED)
                {                                
                  /*  MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_SETTING_RSP_RESIZE_ERR_P2,g_uc_p->mms_info.image_resize.width,g_uc_p->mms_info.image_resize.height); */
                    /*resize may fail due to size.*/
                }
                else
                {
                    file_path_len = mmi_ucs2strlen((S8*)mmi_uc_image_path);
                    if (g_uc_p->srv_mms_info->signature.img_file)
                    {
                        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_mms_info->signature.img_file);
                        g_uc_p->srv_mms_info->signature.img_file = NULL;
                    }
                    g_uc_p->srv_mms_info->signature.img_file = kal_adm_alloc(g_uc_p->main.mem_pool_id, 
                                                                         (file_path_len + 1) * ENCODING_LENGTH);
            
                    mmi_ucs2ncpy((S8*)g_uc_p->srv_mms_info->signature.img_file, 
                                      (S8*)mmi_uc_image_path,
                                      file_path_len);        
                }        
            }	
        }
    }
    if (signature != NULL)
    {
        kal_adm_free(g_uc_p->main.mem_pool_id, signature);
        signature = NULL;
    }

    switch (g_uc_p->srv_main->state)
    {
        case MMI_UC_STATE_WRITE_NEW_MSG:
        {
            MMI_BOOL img_resolution_need_resize = MMI_FALSE;

            /* If enter from mmi_uc_entry_write_msg_with_content, the first slide is ready. */
            if (g_uc_p->srv_msg->msg_body.slide_no == 0)
            {
                g_uc_p->srv_msg->msg_body.curr_slide = srv_uc_insert_slide(g_uc_p->main.instance, NULL);
                g_uc_p->srv_msg->current_slide_num = g_uc_p->srv_msg->msg_body.curr_slide->slide_num;

                /* Set duration of current slide as the value of MMS slide setting */
                g_uc_p->srv_msg->msg_body.curr_slide->duration = g_uc_p->srv_msg->slide_timing;
            }
            else
            {
                /* Set duration of current slide as the value of MMS slide setting */
                /* srv_uc_insert_object_to_slide below will use g_uc_p->srv_msg->msg_body.curr_slide->duration, and also maybe change this value */
                g_uc_p->srv_msg->msg_body.curr_slide->duration = g_uc_p->srv_msg->slide_timing;

                if (g_uc_p->srv_main->file_path)
                {
                    mma_insert_check_struct check_result;
                    S32 result;

                    memset(&check_result, 0, sizeof(check_result));

                    insert_info.creation_mode = g_uc_p->srv_mms_info->creation_mode;
                    insert_info.current_msg_size = g_uc_p->srv_msg->msg_size;
                    insert_info.max_msg_size =
                        g_uc_p->srv_mms_info->max_mms_size - srv_uc_reserved_size(g_uc_p->main.instance);
                    insert_info.insert_type = MMA_INSERT_UNKNOWN;
                    insert_info.filepath = (kal_wchar*) g_uc_p->srv_main->file_path;
                    insert_info.mms_type = srv_uc_get_mms_type(g_uc_p->main.instance);

                    mma_uc_insert_object_check(&insert_info, &check_result);

                #ifdef __MMI_MMS_POSTCARD__
                    if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                    {
                        /* can not insert drm file in postcard */
                        if (check_result.drm_type != MMA_DRM_NONE)
                        {
                            mmi_uc_display_popup((U16) SRV_UC_PROHIBIT_BY_DRM);
                            kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_main->file_path);
                            g_uc_p->srv_main->file_path = NULL;
                            mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                            mmi_uc_reset_msg();
                            return;
                        }
                    }
                #endif /* __MMI_MMS_POSTCARD__ */ 
                    /* the file maybe be deleted before UC is triggered */
                    /* might be corrupted */
                    /* might be high resolution */
                    if (!(check_result.result) &&
                        ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_NOT_FOUND == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_EMPTY == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_IMAGE_TOO_LARGE == check_result.detail_result)))
                    {
                        result = srv_uc_convert_mms_check_result(&check_result);
                        mmi_uc_display_popup((srv_uc_result)result);
                        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_main->file_path);
                        g_uc_p->srv_main->file_path = NULL;
                        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                        mmi_uc_reset_msg();
                    #ifdef __MMI_OP02_LEMEI__
						if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
						{
							g_uc_p->srv_msg_type->MMS_edit_mode = MMI_UC_MMS_EDIT_MODE_NORMAL_MMS;
						}
                    #endif
                        return;
                    }
                #ifdef __MMI_MMS_POSTCARD__
                    if ((g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS) &&
                        (check_result.result))
                    {
                        MMI_ASSERT(check_result.insert_type == MMA_INSERT_IMAGE);
                    }
                #endif /* __MMI_MMS_POSTCARD__ */ 
                    if (check_result.insert_type == MMA_INSERT_IMAGE && check_result.drm_type == MMA_DRM_NONE)
                    {
                        if (g_uc_p->srv_mms_info->image_resize.enable)
                        {
                            img_resolution_need_resize = MMI_TRUE;

                            #ifdef __MMI_OP02_LEMEI__
                            if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
                            {
                                FMGR_FILE_INFO_STRUCT   file_info;
                                mmi_fmgr_get_file_info_by_path((S8 *)g_uc_p->srv_main->file_path, &file_info);
                                if (file_info.file_size <= 100 * 1024)
                                {
                                    img_resolution_need_resize = MMI_FALSE;
                                }
                            }
                            #endif
                        }
                        
                    #ifdef __MMI_OP02_LEMEI__
                        else if(g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_LEMEI_MMS)
                        {
                            FMGR_FILE_INFO_STRUCT   file_info;
                            mmi_fmgr_get_file_info_by_path((S8 *)g_uc_p->srv_main->file_path, &file_info);
                            if (file_info.file_size > 100 * 1024)
                            {
                                img_resolution_need_resize = MMI_TRUE;
                            }
                            else
                            {
                                img_resolution_need_resize = MMI_FALSE;
                            }
                        }
                    #endif
                    
                    #ifdef __MMI_UC_MMS_IMG_RESOLUTION__
                        else if (g_uc_p->srv_mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
                        {
                            img_resolution_need_resize = srv_uc_img_resolution_exceed_limitation((PU16) g_uc_p->srv_main->file_path);
                        }
                    #endif /* __MMI_UC_MMS_IMG_RESOLUTION__ */ 
                    }

                    if (!img_resolution_need_resize &&
                        check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
                    {
                        mmi_uc_setSoftkeyFunction(
                            mmi_uc_process_state_write_new_msg_in_mms_setting_rsp,
                            mmi_uc_process_no_in_mms_setting_rsp,
                            (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
                            (U16) STR_UC_WARNING_MODE_CONFIRM);
                        mmi_uc_entry_displayConfirm_generic();
                        return;
                    }
                    else if (img_resolution_need_resize)
                    {
                        S32 fmgr_ret = -1;
                        srv_uc_result result_fm_check;
#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
                        S32 img_width = 0, img_height = 0;
                        S32 resize_w = (S32) g_uc_p->srv_mms_info->image_resize.width;
                        S32 resize_h = (S32) g_uc_p->srv_mms_info->image_resize.height;
#endif
                        if (!check_result.result)
                        {
                            mmi_fmgr_util_file_limit_check2(
                                FMGR_LIMIT_MMS_CATEGORY,
                                (PS8) g_uc_p->srv_main->file_path,
                                &fmgr_ret);

                            if (fmgr_ret < 0)
                            {
                                if (fmgr_ret == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                                {
                                    result_fm_check = SRV_UC_FAIL_IMAGE_TOO_LARGE;
                                }
                                else
                                {
                                    result_fm_check = SRV_UC_FILE_CORRUPT;
                                }
                                mmi_uc_display_popup(result_fm_check);
                                kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_main->file_path);
                                g_uc_p->srv_main->file_path = NULL;
                                mmi_frm_scrn_close (g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                                mmi_uc_reset_msg();
                                return;
                            }
                        }

#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__

                        gdi_image_get_dimension_file((PS8)g_uc_p->srv_main->file_path, &img_width, &img_height);
                        if(((S32) img_width > (S32) resize_w) || ((S32) img_height > (S32) resize_h))
                        {
                            g_uc_p->main.decode_fp = mmi_uc_handle_image_object_resize_process_before_resolution_verification;
                            mmi_uc_decode_image(img_width, img_height);
                        }
                        else
#endif
                        {
                        mmi_uc_handle_image_object_resize_process_before_resolution_verification(
                            (PU16) g_uc_p->srv_main->file_path,
                            g_uc_p->main.is_short);
                        }
                        return;
                    }
                    if (!mmi_uc_handle_object_insert_if_file_path_exist())
                    {
                        return;
                    }
                    /* moved to mmi_uc_process_state_write_new_msg_in_mms_setting_rsp */
                }
                mmi_uc_change_msg_type_if_needed();
            }
            pass_sig_check = mmi_uc_insert_signature_check();
            mmi_uc_switch_slide(g_uc_p->srv_msg->msg_body.curr_slide);
            srv_uc_update_msg_size(g_uc_p->main.instance);
            if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_CONTENT_RSP_INTERRUPT);
                mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
            }
            else    /*if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)*/
            {
                mmi_uc_entry_write_msg();
                mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
            }


            if (MMI_UC_INSERT_SIG_RESULT_WARNING == pass_sig_check)
            {
                mmi_uc_sig_setSoftkeyFunction(
                    mmi_uc_process_warning_mode_insert_signature,
                    mmi_frm_scrn_close_active_id,
                    (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY));
                mmi_uc_entry_sig_displayConfirm_generic();
            }
        }
            break;

        case MMI_UC_STATE_EDIT_EXISTED_MSG:
        case MMI_UC_STATE_FORWARD:
        case MMI_UC_STATE_SEND:
        case MMI_UC_STATE_REPLY:
        case MMI_UC_STATE_REPLY_ALL:
        {
            if (g_uc_p->srv_send_info->existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
            {
            #ifndef __MMI_MMS_STANDALONE_COMPOSER__
            #ifdef __MMI_MMS_POSTCARD__
                MMI_ASSERT(g_uc_p->srv_msg_type->MMS_edit_mode != MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS);
				if(!(g_uc_p->srv_msg_type->MMS_edit_mode != MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS))
				{
				MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
				}
            #endif 

                if (g_uc_p->srv_msg->msg_body.slide_no > 0)
                {
                    g_uc_p->srv_msg->msg_body.curr_slide->duration = g_uc_p->srv_msg->slide_timing;
                }
                mmi_uc_change_msg_type_if_needed();

                if (g_uc_p->srv_main->state == MMI_UC_STATE_EDIT_EXISTED_MSG)
                {
                    /* tricky! disallow to insert signature for edit case */
                   // g_uc_p->srv_msg->auto_signature_inserted = MMI_TRUE; 
                    
                    
                    mmi_uc_switch_slide(g_uc_p->srv_msg->msg_body.curr_slide);
                    /*handle interrupt issue*/
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                    {
                        mmi_uc_entry_write_msg();
                        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                    else
                    {
                        if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                        {
                            mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
                        }
                    }           
                }
                else if (g_uc_p->srv_main->state == MMI_UC_STATE_EDIT_EXISTED_MSG ||
                    g_uc_p->srv_main->state == MMI_UC_STATE_REPLY || g_uc_p->srv_main->state == MMI_UC_STATE_REPLY_ALL)
                {
                    pass_sig_check = mmi_uc_insert_signature_check();

                    mmi_uc_switch_slide(g_uc_p->srv_msg->msg_body.curr_slide);
                    /* handle interrupt issue */
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                    {
                        mmi_uc_entry_write_msg();
                        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                    else
                    {
                        if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                        {
                            mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
                        }
                    }
                    if (MMI_UC_INSERT_SIG_RESULT_WARNING == pass_sig_check)
                    {
                        mmi_uc_sig_setSoftkeyFunction(
                            mmi_uc_process_warning_mode_insert_signature,
                            mmi_frm_scrn_close_active_id,
                            (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY));
                        mmi_uc_entry_sig_displayConfirm_generic();
                    }

                }
                else
                {
                    g_uc_p->done.pre_msg_type = g_uc_p->srv_msg_type->curr_msg_type;

                    /* tricky! disallow to insert signature for forward and send case */
                    g_uc_p->srv_msg->auto_signature_inserted = MMI_TRUE;

                    mmi_uc_pre_process_send_to();
                    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                }
            #else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
                MMI_ASSERT(0);
            #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
            }
            else if (g_uc_p->srv_send_info->existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                mmi_uc_get_mms_content_req();
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_content_req
 * DESCRIPTION
 *  Get MMS content request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_content_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_START_MMI_UC_GET_MMS_CONTENT_REQ);
	kal_get_time(&(g_uc_p->main.g_tick_count_at_start));

    g_uc_p->send_info.request_id = MMI_UC_GET_CONTENT_REQ;
    memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
    msg_req.msg_id = g_uc_p->srv_send_info->existed_msg_id;

    /* For Forward and Re-send MMS cases, the MMS msg may become SMS message before send */
    /* so the msg content should be gotten besides addresses */
    /* msg_req.mode = srv_uc_convert_uc_state_to_mms_app_mode(g_uc_p->main.state); */
    if (g_uc_p->srv_main->state == MMI_UC_STATE_REPLY)
    {
        msg_req.mode = MMA_MODE_REPLY;
    }
    else if (g_uc_p->srv_main->state == MMI_UC_STATE_REPLY_ALL)
    {
        msg_req.mode = MMA_MODE_REPLY_ALL;
    }
    else if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD)
    {
        msg_req.mode = MMA_MODE_FORWARD;
    }
    else if (g_uc_p->srv_main->state == MMI_UC_STATE_SEND)
    {
        msg_req.mode = MMA_MODE_SEND;
    }
    else
    {
        msg_req.mode = MMA_MODE_EDIT;
    }

    msg_req.user_data = NULL;
    msg_req.call_back = (srv_mms_funcptr_type) mmi_uc_get_mms_content_rsp;
    srv_mms_get_content(&msg_req);
    return;
}

void mmi_uc_free_addr_mem_alloc_for_mma(mma_mms_addr_list_struct *mma_addr)
{
	mma_mms_addr_list_struct *temp_addr = NULL ;
	while(mma_addr)
	{
		temp_addr = mma_addr ;
		mma_addr = mma_addr->next ;
		mmi_uc_mms_free_mem_cbk(temp_addr->address);
		mmi_uc_mms_free_mem_cbk(temp_addr);
		temp_addr = NULL ;
	}

}
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_content_rsp
 * DESCRIPTION
 *  Get MMS content response
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_content_rsp(srv_mms_result_enum mms_result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_content_rsp_struct *msg_rsp = (srv_mms_get_content_rsp_struct*) rsp_data;
    srv_uc_result result = SRV_UC_OK;
	kal_uint32 current_tick_count ;
	kal_uint32 time_gap ;
	mma_app_mode_enum app_mode ;

	//get the new header and body info from response data instead of XML

	mma_mms_description_struct *get_msg_info = (mma_mms_description_struct *)msg_rsp->content_info ;
    mma_mms_description_header_struct *get_mms_header = (mma_mms_description_header_struct *)get_msg_info->header ;
	mma_mms_description_body_struct *get_mms_body = (mma_mms_description_body_struct *)get_msg_info->body ;
	g_uc_p->srv_msg->g_msg_header.header = &(g_uc_p->srv_msg->msg_header);
	#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
		g_uc_p->srv_msg->g_msg_header.owner = NULL;												/* getting owner number from sim */
    #endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(msg_rsp->msg_id == g_uc_p->srv_send_info->existed_msg_id);
    //MMI_ASSERT(msg_rsp->buffer_index == g_uc_p->srv_send_info->buffer_index);

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        mmi_uc_display_mma_result_popup((mma_result_enum)msg_rsp->result);
        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);

    }
    else
    {
        MMI_ASSERT(msg_rsp->msg_id == g_uc_p->srv_send_info->existed_msg_id);
		if(!(msg_rsp->msg_id == g_uc_p->srv_send_info->existed_msg_id))
		{
		MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
		}
		g_uc_p->srv_msg->msg_body_size = msg_rsp->mms_body_size;
        g_uc_p->srv_msg->msg_size = msg_rsp->mms_header_size + msg_rsp->mms_body_size;

        {
            MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

        #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
            /* Check require only to disallow large MMS to send or FW only */
            U32 max_size = g_uc_p->srv_mms_info->max_mms_size;

            result = SRV_UC_SIZE_EXCEEDS;
        #ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
            if (MMA_MAX_WAP_CONN_MSG_SIZE < max_size &&
        #ifdef WAP_SUPPORT
                (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
                 SRV_WAP_PROF_CONN_TYPE_HTTP))
        #else /* WAP_SUPPORT */ 
                (mmi_brw_prof_get_activated_profile_connection_type(BRW_PROF_MMS_PROFILE) > BRW_PROF_CONN_TYPE_HTTP))
        #endif /* WAP_SUPPORT */ 
            {
                max_size = MMA_MAX_WAP_CONN_MSG_SIZE;
                result = SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED;
            }
        #endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 
            if (((g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD) || (g_uc_p->srv_main->state == MMI_UC_STATE_SEND)) &&
                (max_size < msg_rsp->mms_header_size + msg_rsp->mms_body_size))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_CONTENT_RSP_CHECK_SIZE_ERR);
                if (g_uc_p->srv_mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED &&
                    mms_get_max_msg_size_in_restricted_mode() < msg_rsp->mms_header_size + msg_rsp->mms_body_size)
                {
                    mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS);
                }
                else
                {
                    mmi_uc_display_popup(result);
                }
                mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                return;
            }
        #else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
            if ((g_uc_p->srv_main->state != MMI_UC_STATE_REPLY) && (g_uc_p->srv_main->state != MMI_UC_STATE_REPLY_ALL)
                && srv_uc_check_if_exceed_MMS_size_limitation(
                    g_uc_p->main.instance,
                    msg_rsp->mms_header_size + msg_rsp->mms_body_size,
                    &fail_in_restricted_size_check))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_CONTENT_RSP_CHECK_SIZE_ERR);
                (fail_in_restricted_size_check) ? mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS) :
                    mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS);
                mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                return;
            }
        #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
            //g_uc_p->srv_send_info->xml_file_size = msg_rsp->xml_size;

            if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL,SRV_UCM_VIDEO_CALL_TYPE_ALL,NULL)>0)
            {
                mma_mms_description_body_struct *mms_body = get_mms_body;
                if(mms_body != NULL)
                {
                mma_mms_slide_struct *slides = mms_body->slides;
                while(slides != NULL)
                {
                    if(slides->vid.object)
                    {
                         mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY)), MMI_EVENT_ERROR, NULL);
                         mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);	
				         return;
                    }
                    slides = slides->next;
                }
            }
            }

            mmi_uc_editor_initialize();
            /* parse the XML file */
			if (g_uc_p->srv_main->state == MMI_UC_STATE_REPLY)
			{
				app_mode = MMA_MODE_REPLY;
			}
			else if (g_uc_p->srv_main->state == MMI_UC_STATE_REPLY_ALL)
			{
				app_mode = MMA_MODE_REPLY_ALL;
			}
			else if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD)
			{
				app_mode= MMA_MODE_FORWARD;
			}
			else if (g_uc_p->srv_main->state == MMI_UC_STATE_SEND)
			{
				app_mode = MMA_MODE_SEND;
			}
			else
			{
				app_mode = MMA_MODE_EDIT;
			}
			MMI_ASSERT(get_mms_header);
			srv_mms_container_copy_header(get_mms_header,
					&(g_uc_p->srv_msg->g_msg_header),
					mmi_uc_srv_alloc_mem_cbk,
					(srv_mms_func_mem_free_user_data)mmi_uc_mms_free_mem_cbk,
					(mma_mms_state_enum)g_uc_p->srv_main->state,
					g_uc_p->srv_main->mode,
				    app_mode,
					NULL);

			
			if(!(app_mode == MMA_MODE_REPLY || 
			   app_mode == MMA_MODE_REPLY_ALL ||
			   app_mode == MMA_MODE_HEADER))
			{
				MMI_ASSERT(get_mms_body);
				srv_mms_container_copy_body(get_mms_body,
				&(g_uc_p->srv_msg->msg_body),
				mmi_uc_srv_alloc_mem_cbk,
				(srv_mms_func_mem_free_user_data)mmi_uc_mms_free_mem_cbk,
				NULL);
			}
			/*use the mma to_header pointer to UC to_head [to/cc/bcc all in to_head]*/
			if(g_uc_p->srv_msg->g_msg_header.header->to)
			{
				g_uc_p->srv_msg->to_head = srv_uc_cpy_address(g_uc_p->srv_msg->g_msg_header.header->to, g_uc_p->main.instance) ;
				g_uc_p->srv_msg->to_num = g_uc_p->srv_msg->g_msg_header.header->to_num ;
				mmi_uc_free_addr_mem_alloc_for_mma(g_uc_p->srv_msg->g_msg_header.header->to);
				g_uc_p->srv_msg->g_msg_header.header->to = NULL ;
			}

			if( g_uc_p->srv_msg->msg_body.attachment)
			{
				mma_mms_attachment_info_struct *attach = g_uc_p->srv_msg->msg_body.attachment ;
				while(attach)
				{
					attach->object->reference_count = 1 ;
					attach = attach->next ;
				}
			}
			if(g_uc_p->srv_msg->msg_header.subject.text)
			{
				mmi_chset_utf8_to_ucs2_string((kal_uint8 *)g_uc_p->srv_msg->subject,(sizeof(U16)*SRV_UC_MAX_SUBJECT_ARRAY_LEN + 1),(kal_uint8 *)g_uc_p->srv_msg->msg_header.subject.text);
			}

            result = (srv_uc_result)mmi_uc_parse_mms_xml_description_file();

        #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            mmi_uc_recipient_initialize();
        #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

            if (result != SRV_UC_OK)
            {
                mmi_uc_display_popup((srv_uc_result)result);
                mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                mmi_uc_reset_msg();
            }
            else
            {
                srv_uc_handle_extra_information_from_mma(g_uc_p->main.instance, msg_rsp->content_truncate_info);
                mmi_uc_success_case_process_after_get_content_rsp();
            }

        }
    }

	kal_get_time(&current_tick_count);
	time_gap = (current_tick_count)-(g_uc_p->main.g_tick_count_at_start);
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_EXIT_MMI_UC_GET_MMS_CONTENT_RSP,time_gap);

}

mma_mms_description_struct g_uc_content_info;

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms_req
 * DESCRIPTION
 *  Create MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_uc_replace_duplicate_object_file_name(U32 instance);

void mmi_uc_create_mms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_req_struct msg_req;
    //U32 read_size;
    //S32 remaining_size;
    //U16 peer_buff_len = 0;
    //srv_uc_service_req_struct *srv_req;
    //mma_mms_header_struct header ;
	//mma_mms_description_body_struct body;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_START_MMI_UC_CREATE_MMS);
	kal_get_time(&(g_uc_p->main.g_tick_count_at_start));

    g_uc_p->send_info.request_id = MMI_UC_CREATE_REQ;
    /* reset */
    memset(&msg_req, 0, sizeof(srv_mms_create_req_struct));
    msg_req.mode = MMA_MODE_EDIT;
    msg_req.msg_id = 0;

    if (g_uc_p->srv_send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
        if (g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD
            || g_uc_p->srv_main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            msg_req.msg_id = g_uc_p->srv_send_info->existed_msg_id;
            msg_req.mode = MMA_MODE_FORWARD;
        }
        else if (g_uc_p->srv_main->state == MMI_UC_STATE_SEND
            #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                || g_uc_p->srv_main->mode == SRV_UC_SEND_WITHOUT_EDIT_MODE
            #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
            )
        {
            msg_req.msg_id = g_uc_p->srv_send_info->existed_msg_id;
            msg_req.mode = MMA_MODE_SEND;
        }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        else if (g_uc_p->srv_main->state == MMI_UC_STATE_EDIT_EXISTED_MSG &&
                    g_uc_p->srv_main->mode != SRV_UC_FORWARD_WITH_EDIT_MODE
            #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
                && g_uc_p->srv_main->mode != SRV_UC_SEND_WITH_EDIT_MODE
            #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                )
        {
            if(mmi_uc_get_current_msg_box_type(g_uc_p->srv_send_info->existed_msg_id) == SRV_UM_MSG_BOX_DRAFT)
            {
                msg_req.msg_id = g_uc_p->srv_send_info->existed_msg_id;
            }
        }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    }
#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        msg_req.mode = MMA_MODE_POSTCARD;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SEND_IN_BACKGROUND)
        {
            if(srv_postcard_get_total_recipient_count(g_uc_p->main.instance) > 1)
            {
                msg_req.msg_id = 0;
            }
        }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
#if (defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SAVE_AS_TEMPLATE)
    {
        msg_req.mode = MMA_MODE_TEMPLATE;
        if (!(g_uc_p->srv_main->state == MMI_UC_STATE_FORWARD
            || g_uc_p->srv_main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE))
        {
            msg_req.msg_id = 0;
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

    srv_uc_set_media_duration(g_uc_p->srv_msg->msg_body.slides);
    msg_req.user_data = NULL;
    msg_req.call_back = (srv_mms_funcptr_type)mmi_uc_create_mms_rsp;
	g_uc_p->srv_msg->msg_header.to = NULL;
	g_uc_p->srv_msg->msg_header.cc = NULL;
	g_uc_p->srv_msg->msg_header.bcc = NULL;
	g_uc_p->srv_msg->msg_header.to = srv_uc_convert_uc_addr_to_mms_addr(g_uc_p->srv_msg->to_head, g_uc_p->main.instance);//convert here
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        if(g_uc_p->srv_msg->msg_header.subject.text)
        {
            kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->srv_msg->msg_header.subject.text);
        }
        g_uc_p->srv_msg->msg_header.subject.text  = (char *)kal_adm_alloc(g_uc_p->main.mem_pool_id, sizeof(U16) * (SRV_UC_MAX_SUBJECT_ARRAY_LEN + 1));
        memset(g_uc_p->srv_msg->msg_header.subject.text , 0 , sizeof(U16) * (SRV_UC_MAX_SUBJECT_ARRAY_LEN + 1));
        mmi_chset_ucs2_to_utf8_string((U8 *)g_uc_p->srv_msg->msg_header.subject.text,(sizeof(U16) * (SRV_UC_MAX_SUBJECT_ARRAY_LEN + 1)),(U8 *)g_uc_p->srv_msg->subject);
#endif
	g_uc_p->srv_msg->g_msg_header.header = &(g_uc_p->srv_msg->msg_header) ;
	g_uc_p->srv_msg->g_msg_header.header->to_num = g_uc_p->srv_msg->to_num ; 
	g_uc_p->srv_msg->msg_body.layout = srv_uc_convert_to_mms_layout_type((mma_slide_layout_enum)g_uc_p->srv_msg->msg_body.layout);
	srv_uc_copy_filename_filepath(g_uc_p->main.instance);
	g_uc_content_info.header = &(g_uc_p->srv_msg->g_msg_header);
	g_uc_content_info.body = &(g_uc_p->srv_msg->msg_body);
	msg_req.content_info = &g_uc_content_info;
	srv_uc_replace_duplicate_object_file_name(g_uc_p->main.instance);
    srv_mms_create(&msg_req);
    return;
}
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
mmi_ret mmi_uc_set_storage(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_YES:
            mmi_uc_set_prefer_storage();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_uc_reset_state();
            break;
        }
    }
    return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *mmi_uc_check_drm_after_preview
 * DESCRIPTION
 *  Create MMS msg response
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_check_drm_after_preview(mma_mms_object_struct *object, srv_uc_object_type object_type)
{
	if(object && (object->is_virtual_file == KAL_FALSE) && (object->drm_type != MMA_DRM_NONE))
	{
 #ifdef __DRM_SUPPORT__
		switch (object->drm_type)
    {
        case MMA_DRM_SD_NO_RIGHT:
        case MMA_DRM_SD:
        case MMA_DRM_PDCF_V2:
        case MMA_DRM_PDCF_V2_NO_RIGHT:
			{
		FS_HANDLE drm_fh = DRM_open_file((PU16)object->file_path_ucs, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
	   if (drm_fh >= FS_NO_ERROR)
		{
			if (MMI_FALSE == DRM_validate_permission(drm_fh, NULL, DRM_PERMISSION_DISPLAY))
			{
	           
				object->drm_type=MMA_DRM_SD_NO_RIGHT;
			}
			else
			{
				object->drm_type=MMA_DRM_SD;
			}

			DRM_close_file(drm_fh);
		}
			}
            break;
        }
 #endif
		

		 mmi_uc_editor_add_object(object, object_type);
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms_rsp
 * DESCRIPTION
 *  Create MMS msg response
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_create_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;
	kal_uint32 current_tick_count ;
	kal_uint32 time_gap ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_uc_p->srv_msg->msg_header.to)
	{
		srv_uc_free_mem_alloc_for_mma_addr(g_uc_p->srv_msg->msg_header.to, g_uc_p->main.instance);
		g_uc_p->srv_msg->msg_header.to = NULL ;
	}
    if(g_uc_p->send_info.request_id != MMI_UC_CREATE_REQ)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CREATE_MMS_RSP_P2, g_uc_p->send_info.request_id, g_uc_p->send_info.request_id);
        if(g_uc_p->srv_send_info->fs)
        {
            FS_Close(g_uc_p->srv_send_info->fs);
            g_uc_p->srv_send_info->fs = 0;
        }
    }
    else
    {
        if (msg_rsp->result != MMA_RESULT_OK)
        {
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            U16 str_id = 0;
        #endif 
            if(g_uc_p->srv_send_info->fs)
            {
                FS_Close(g_uc_p->srv_send_info->fs);
                g_uc_p->srv_send_info->fs = 0;
            }

            if (g_uc_p->srv_send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND)
            {
                /* pop up working space string to indicate user */
                if ((msg_rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) && (msg_rsp->min_fs_space_required != 0))
                {
                    mmi_uc_display_working_space_popup(msg_rsp->min_fs_space_required);
					mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_MSG_PREVIEW);
                }
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                else if (msg_rsp->result == MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE)
                {
                    str_id = STR_UC_CARD_NOT_PRESENT_CONFIRM;
                }
                else if (msg_rsp->result == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD)
                {
                    str_id = STR_UC_MAX_MSG_CARD_CONFIRM;
                }
                else if (msg_rsp->result == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY)
                {
                    str_id = STR_UC_MAX_MSG_PHONE_CONFIRM;
                }
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                else
                {
                    mmi_uc_display_mma_result_popup((mma_result_enum)msg_rsp->result);
					mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_MSG_PREVIEW);
                }
            }
            else
            {
                mmi_uc_reset_msg();
            }
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (str_id)
            {
				mmi_confirm_property_struct arg;
                mmi_uc_setSoftkeyFunction(
                    mmi_uc_set_prefer_storage,
                    mmi_uc_reset_state,
                    (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
                    str_id);
                /*mmi_uc_entry_displayConfirm_generic();*/

				mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
				arg.callback = (mmi_proc_func)mmi_uc_set_storage;
				arg.parent_id = g_uc_p->main.uc_cui_gid;
				mmi_confirm_display((WCHAR *)(get_string(str_id)), MMI_EVENT_QUERY, &arg);
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                /* reset state */
                g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;
            }
            mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
        }
        else
        {
            /* sending XML content completes */
            {
                if(g_uc_p->srv_send_info->fs)
                {
                    FS_Close(g_uc_p->srv_send_info->fs);
                    g_uc_p->srv_send_info->fs = 0;
                }
                g_uc_p->srv_send_info->new_msg_id = msg_rsp->msg_id;
                g_uc_p->send_info.new_msg_storage = (mma_msg_storage_type_enum) msg_rsp->storage;
                if ((g_uc_p->srv_send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND) &&
                    (g_uc_p->srv_send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND_WHEN_BATTERY_LOW))
                {
                    if (mmi_frm_scrn_get_active_id() != SCR_ID_UC_PROCESSING)
                    {
                        if(!mmi_uc_is_uc_screen_in_history())
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CREATE_MMS_RSP_INTERRUPT);
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_WRITE_MSG_DELETE_HISTORY_HDLR_RESET_MSG);
                            mmi_uc_reset_msg();
                            g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;
                            return;
                        }
                        /* Save the create rsp info -- rsp_data */
                        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CREATE_MMS_RSP_INTERRUPT);
                        mmi_uc_set_processing_screen(
                            0,
                            STR_GLOBAL_PLEASE_WAIT,
                            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                            0);
                        /* if the create_rsp is triggered by mmi_uc_create_mms_rsp_retry_timeout_callback, then GetExitScrnID must be SCR_ID_UC_PROCESSING, 
                           so it's impossible to run this path. */
                        g_uc_p->main.create_msg_rsp = kal_adm_alloc(
                                                        g_uc_p->main.mem_pool_id,
                                                        sizeof(srv_mms_create_rsp_struct));
                        if(g_uc_p->main.create_msg_rsp != NULL)
                        {
                            memset(g_uc_p->main.create_msg_rsp, 0, sizeof(srv_mms_create_rsp_struct));
                            memcpy(g_uc_p->main.create_msg_rsp, msg_rsp, sizeof(srv_mms_create_rsp_struct));

                            StartTimer(
                                UC_CREATE_RSP_RETRY_TIMER_ID,
                                MMI_UC_CREATE_RSP_RETRY_TIME,
                                mmi_uc_create_mms_rsp_retry_timeout_callback);
                        }
                        else
                        {
                            /* Fail in memory allocation. */
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CREATE_MMS_RSP_INTERRUPT);
                        }
                        return;
                    }
                }

                if(g_uc_p->main.create_msg_rsp != NULL)
                {
                    kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.create_msg_rsp);
                    g_uc_p->main.create_msg_rsp = NULL;
                    msg_rsp = NULL;
                }

                switch (g_uc_p->srv_send_info->action)
                {
                    case SRV_UC_ACTION_SEND:
                    {
                    #ifdef __MMI_MMS_BGSR_SUPPORT__
                        /* This case should not happened is BGSR is enabled */
                        MMI_ASSERT(0);
						MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
                    #else /* __MMI_MMS_BGSR_SUPPORT__ */ 
                        mmi_uc_send_mms();
                    #endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
                        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                        break;

                    case SRV_UC_ACTION_SEND_AND_SAVE:
                    {
                    #ifdef __MMI_MMS_BGSR_SUPPORT__
                        /* This case should not happened if BGSR is enabled */
                        MMI_ASSERT(0);
						MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
                    #else /* __MMI_MMS_BGSR_SUPPORT__ */ 
                        mmi_uc_send_and_save_mms();
                        mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    #endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
                    }
                        break;

                    case SRV_UC_ACTION_SAVE:
                    {
                        srv_um_msg_box_enum msg_box = mmi_uc_get_current_msg_box_type(g_uc_p->srv_send_info->existed_msg_id);

                        if (g_uc_p->srv_main->state == MMI_UC_STATE_EDIT_EXISTED_MSG && msg_box == SRV_UM_MSG_BOX_DRAFT)
                        {
                            mmi_uc_set_processing_screen(
                                0,
                                STR_GLOBAL_SAVING,
                                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                                0);

                            mmi_uc_entry_processing_generic();

                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                            if (g_uc_p->srv_send_info->existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                g_uc_p->send_info.need_highlight_ind_to_um = TRUE;
                                mmi_uc_save_mms_req(g_uc_p->srv_send_info->new_msg_id, MMA_FOLDER_DRAFT);
                            }
                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                            else if (g_uc_p->srv_send_info->existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                mmi_uc_delete_existed_mms();
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        else
                        {
                            mmi_uc_save_mms();
                        }
                        //mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                        break;

                #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
                    case SRV_UC_ACTION_SAVE_AS_TEMPLATE:
                    {
                        /* Handle save as template case as save new mms msg */
                        g_uc_p->srv_send_info->action = SRV_UC_ACTION_SAVE;
                        g_uc_p->srv_main->state = MMI_UC_STATE_WRITE_NEW_MSG;

                        mmi_uc_save_mms_to_folder(MMA_FOLDER_USRDEF_TEMPLATE);
                        //mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                        break;
                #endif /* defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__) */ 

                    case SRV_UC_ACTION_SAVE_IN_BACKGROUND:
                    case SRV_UC_ACTION_SAVE_IN_BACKGROUND_WHEN_BATTERY_LOW:
                    {
                        mmi_uc_save_mms_req(g_uc_p->srv_send_info->new_msg_id, MMA_FOLDER_DRAFT);
                    }
                        break;

                    case SRV_UC_ACTION_PREVIEW:
                    {
                        mmi_uc_preview_mms();
                        //mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                    #ifdef __MMI_MMS_POSTCARD__
                        /* should recover the original text object */
                        /* 1. if there is greeting, recover it */
                        if (g_uc_p->srv_msg->msg_body.greeting_exist_flag)
                        {
                            S32 result;

                            result = srv_uc_save_buffer_to_file(
                                        g_uc_p->main.instance,
                                        (U8*) g_uc_p->srv_msg->msg_body.curr_slide->text.object->file_path_ucs,
                                        g_uc_p->srv_main->text_buffer,
                                        g_uc_p->srv_msg->msg_body.curr_slide->text.char_count);

                            if (result == FS_NO_ERROR)
                            {
                                g_uc_p->srv_msg->msg_body.curr_slide->text.object->size = applib_get_file_size((kal_wchar*) g_uc_p->srv_msg->msg_body.curr_slide->txt.object->file_path_ucs);
                                                         
                            }
                            else
                            {
                                /* Error handling: when user press option (mmi_uc_pre_entry_option) , will try to save again, 
                                   if still error, will popup error msg and disallow user to enter next step */
                            }
                        }

                    #endif /* __MMI_MMS_POSTCARD__ */ 
                    }
                        break;
                #if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
                    case SRV_UC_ACTION_SEND_IN_BACKGROUND:
                    {
                        U16 result;
                        result = mms_send_msg(
                                    srv_uc_convert_uc_sim_id_to_mma (srv_uc_convert_sim_id(g_uc_p->srv_send_info->send_sim_id)),
                                    g_uc_p->srv_send_info->new_msg_id,
                                    (kal_uint16) g_uc_p->send_info.new_msg_storage,
                                    (kal_uint16) MMA_APP_ID_UC);

                        if ( result == SRV_MMS_BGSR_RESULT_OK)
                        {
                                mmi_popup_property_struct arg;
	                            mmi_popup_property_init(&arg);
#ifndef __MMI_BASIC_UI_STYLE__
	                            arg.msg_icon = IMG_NEW_SMS_SEND;
#endif
	                            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENDING)), MMI_EVENT_PROGRESS, &arg);                                       
                        }
                        else
                        {
                            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
                        }

                    #ifdef __MMI_MMS_POSTCARD__
                        if (g_uc_p->srv_msg_type->MMS_edit_mode == MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                        {
                            g_uc_p->srv_send_info->curr_send_number++;
                            /* g_uc_p->srv_send_info->curr_send_number : means the number that already be handled */
                            if (g_uc_p->srv_send_info->curr_send_number <
                                srv_postcard_get_total_recipient_count(g_uc_p->main.instance))
                            {
                                if (mmi_frm_scrn_get_active_id() != SCR_ID_UC_PROCESSING)       /* bgsr sending screen will interupt uc_processing, so draw again here */
                                {
								    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                                    mmi_uc_set_processing_screen(
                                        0,
                                        STR_GLOBAL_PLEASE_WAIT,
                                        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                                        0);
                                    mmi_uc_entry_processing_generic();

//								    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
                                }
                                mmi_uc_create_mms_handler();
                                return;
                            }

                        }
                    #endif /* __MMI_MMS_POSTCARD__ */ 
                        mmi_uc_action_fsm(SRV_UC_ACTION_SEND, MMA_RESULT_OK);
                    }
                        break;
                #endif /* (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__)) */ 

                    default:
                    {
                        MMI_ASSERT(0);
						MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
                    }
                }
            }
        }
    }

	kal_get_time(&current_tick_count);
	time_gap = (current_tick_count)-(g_uc_p->main.g_tick_count_at_start);
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_EXIT_MMI_UC_CREATE_MMS,time_gap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_req
 * DESCRIPTION
 *  Send MMS msg request
 * PARAMETERS
 *  send_and_save       [IN]        
 *  msg_box_to_save     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_req(BOOL send_and_save, U16 msg_box_to_save)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_rsp
 * DESCRIPTION
 *  Send MMS msg response
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_rsp(void *inMsg)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_mms_req
 * DESCRIPTION
 *  Delete MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        
 *  storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_delete_mms_req(U32 msg_id, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = MMI_UC_DELETE_REQ;
    memset(&msg_req, 0, sizeof(srv_mms_delete_req_struct));

#ifdef __MMI_MMS_BGSR_SUPPORT__
    srv_mms_bgsr_change_msg_notify(
        msg_id,
        SRV_MMS_BGSR_OP_DELETE,
        (srv_mms_bgsr_msg_box_enum) srv_uc_convert_mma_folder_to_bgsr_folder((S32) mma_get_box (msg_id)),
        NULL,
        storage);
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

    MMI_ASSERT(msg_id);
	if(!(msg_id))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    msg_req.msg_id[0] = msg_id;
    msg_req.no_of_msg = 1;
    msg_req.user_data = NULL;
    msg_req.call_back =(srv_mms_funcptr_type) mmi_uc_delete_mms_rsp;
    srv_mms_delete(&msg_req);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_mms_rsp
 * DESCRIPTION
 *  Delete MMS msg response
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_delete_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_rsp_struct *msg_rsp = (srv_mms_delete_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_uc_p->send_info.request_id == MMI_UC_DELETE_REQ)
    {
        mmi_uc_action_fsm(SRV_UC_ACTION_DELETE, msg_rsp->result[0]);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_DEL_MMS_RSP_IGNORE_P1, g_uc_p->send_info.request_id);
    }
    srv_uc_send_um_msg_refresh_ind(
        g_uc_p->main.instance,
        SRV_UM_MSG_BOX_DRAFT,
        SRV_UM_MSG_MMS);
    srv_uc_send_um_msg_refresh_ind(
        g_uc_p->main.instance,
        SRV_UM_MSG_BOX_UNSENT,
        SRV_UM_MSG_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms_req
 * DESCRIPTION
 *  Save MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg_box     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms_req(U32 msg_id, U16 msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = MMI_UC_SAVE_REQ;
    memset(&msg_req, 0, sizeof(srv_mms_save_req_struct));

    msg_req.msg_id[0] = msg_id;
    msg_req.no_of_msg = 1;
    msg_req.box = msg_box;
    msg_req.user_data = NULL;
    msg_req.call_back = (srv_mms_funcptr_type)mmi_uc_save_mms_rsp;
    srv_mms_save(&msg_req);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms_rsp
 * DESCRIPTION
 *  Save MMS msg response
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_rsp_struct *msg_rsp = (srv_mms_save_rsp_struct*) rsp_data;
    BOOL need_highlight_ind_to_um = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    need_highlight_ind_to_um = g_uc_p->send_info.need_highlight_ind_to_um;
    mmi_uc_action_fsm(SRV_UC_ACTION_SAVE, msg_rsp->result[0]);
    if (msg_rsp->result[0] == MMA_RESULT_OK)
    {
        if (need_highlight_ind_to_um == TRUE)
        {
            mmi_um_highlight_msg_ind(
                SRV_UM_MSG_MMS,
                srv_uc_convert_mma_folder_to_um_folder(mma_get_box(msg_rsp->msg_id[0])),
                msg_rsp->msg_id[0]);
            g_uc_p->send_info.need_highlight_ind_to_um = FALSE;
        }
        srv_uc_send_um_msg_refresh_ind(
            g_uc_p->main.instance,
            srv_uc_convert_mma_folder_to_um_folder(mma_get_box(msg_rsp->msg_id[0])),
            SRV_UM_MSG_MMS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms_req(U32 msg_id)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms_rsp(void *in_msg)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
#endif
}

#ifdef __MMI_SLIM_MMS_2__
void mmi_uc_reset_media_timing_after_preview(void)
{
    mma_mms_slide_struct *new_slide = g_uc_p->srv_msg->msg_body.slides;
    while(new_slide != NULL)
    {
        if(new_slide->aud.object) 
        {
            U32 file_duration = 0;
            if (mdi_audio_get_duration(new_slide->aud.object->file_path_ucs, &(file_duration)) == MDI_AUDIO_SUCCESS)
            {
                 new_slide->aud.end = file_duration/1000;
            }          

        }

        if(new_slide->vid.object) 
        {
            #ifdef __MMI_VIDEO_PLAY_SUPPORT__
                mdi_video_info_struct vdo_info;
                MDI_RESULT result;
            #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
                U32 file_duration = 0;

                #ifdef __MMI_VIDEO_PLAY_SUPPORT__
                mdi_video_ply_enable_aud_only_video_clip();
            
                result = mdi_video_ply_open_clip_file(0, (PS8) new_slide->vid.object->file_path_ucs, &vdo_info);
            
                if(result>=0)
                {
                    mdi_video_ply_close_clip_file();
                    
                    file_duration = (S32) (vdo_info.total_time_duration / 1000);
                    new_slide->vid.end = file_duration;
                }
                #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
        }
        new_slide = new_slide->next;
    }
}

#endif
static mmi_ret mmi_uc_cui_event_handler_for_preview_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_MEM_FREE_ASM:
        if (g_uc_p->main.mms_cui_gid != GRP_ID_INVALID)
        {
            cui_umms_preview_mms_close(g_uc_p->main.mms_cui_gid);
            mmi_frm_group_close(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER);
			mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
			mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_MSG_PREVIEW);
            mmi_uc_set_group_id();
            mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
        }
    case EVT_ID_GROUP_DEINIT:
        {
            cui_umms_preview_mms_close(g_uc_p->main.mms_cui_gid);
            mmi_frm_group_close(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER);
			mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
			mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_MSG_PREVIEW);
            mmi_uc_set_group_id();
			g_uc_p->srv_send_info->action = SRV_UC_ACTION_IDLE;

			if (g_uc_p->srv_send_info->new_msg_id)
			{
				mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
				if((g_uc_p->srv_msg->msg_body.curr_slide)->img.object)
				{
				mmi_uc_check_drm_after_preview( (g_uc_p->srv_msg->msg_body.curr_slide)->img.object,SRV_UC_OBJECT_TYPE_IMAGE);
			}
#ifdef __MMI_SLIM_MMS_2__
                mmi_uc_reset_media_timing_after_preview();
#endif
        }
        }
        break;
    default:
        break;
    }

    if (evt->evt_id == EVT_ID_MEM_FREE_ASM)
    {
        return MMI_MEM_FREED;
    }
    else
    {
    return MMI_RET_OK;
}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_mms_req
 * DESCRIPTION
 *  Preview MMS msg request
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_preview_mms_req(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, mmi_uc_cui_event_handler_for_preview_proc, NULL);
	mmi_frm_group_enter(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	g_uc_p->main.mms_cui_gid = cui_umms_preview_mms_create(APPLIB_MEM_AP_ID_UNIFIED_COMPOSER);
#ifdef __MMI_MMS_2__
#ifdef __MMI_MMS_POSTCARD__
    if (g_uc_p->srv_msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        msg = cui_umms_app_set_uc_preview_msg(
                g_uc_p->srv_send_info->new_msg_id,
                MMA_MSG_TYPE_POSTCARD,
                srv_uc_convert_sim_id(g_uc_p->send_info.highlight_sim_id));
			cui_umms_preview_mms_run(g_uc_p->main.mms_cui_gid, msg);
            mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        if(g_uc_p->main.mms_cui_gid != GRP_ID_INVALID)
        {
            msg = cui_umms_app_set_uc_preview_msg(
                g_uc_p->srv_send_info->new_msg_id,
                MMA_MSG_TYPE_MMS,
                srv_uc_convert_sim_id(g_uc_p->send_info.highlight_sim_id));
			cui_umms_preview_mms_run(g_uc_p->main.mms_cui_gid, msg);
            mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);

        }
    }
#else /* __MMI_MMS_2__ */ 
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_MMS_2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_mms_rsp
 * DESCRIPTION
 *  Preview MMS msg response
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_preview_mms_rsp(void *in_msg)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
#endif
}

#if !defined(__MMI_MMS_BGSR_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_ind_hdlr
 * DESCRIPTION
 *  Send MMS message indication handler
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_ind_hdlr(void *inMsg)
{
    /* Shouldn't be called. Code will be deleted after discussion */
#if 0
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
#endif
}
#endif /* !defined(__MMI_MMS_BGSR_SUPPORT__) */ 

 //#if (MMI_MAX_SIM_NUM >=2)kuldeep_nosim
srv_uc_sim_id mmi_uc_convert_mmisim_to_ucsim(mmi_sim_enum sim)
            {
    if(sim ==MMI_SIM1)  
            {
      return SRV_UC_SIM_ID_GSM_SIM1;
            }
     if(sim ==MMI_SIM2)
            {
      return SRV_UC_SIM_ID_GSM_SIM2;
            }
   #if (MMI_MAX_SIM_NUM >=3)
     if(sim ==MMI_SIM3)
            {
      return SRV_UC_SIM_ID_GSM_SIM3;
            }
     #if (MMI_MAX_SIM_NUM ==4)
     if(sim ==MMI_SIM4)
                    {
      return SRV_UC_SIM_ID_GSM_SIM4;
                    }
#endif
#endif
                    else
                    {
      return SRV_UC_SIM_ID_UNCLASSIFIED;
                    }
                    }


U32 mmi_uc_convert_modeswitch_to_ucsim(U32 swith_mode)
                    {
    switch((srv_mode_switch_type_enum)swith_mode)
                    {
        case SRV_MODE_SWITCH_SIM1:
            return SRV_UC_SIM_ID_GSM_SIM1;
                    
        case SRV_MODE_SWITCH_SIM2:
            return SRV_UC_SIM_ID_GSM_SIM2;
                    
#if (MMI_MAX_SIM_NUM >=3)
		case SRV_MODE_SWITCH_SIM3:
            return SRV_UC_SIM_ID_GSM_SIM3;
                    
#if (MMI_MAX_SIM_NUM ==4)
		case SRV_MODE_SWITCH_SIM4:
            return SRV_UC_SIM_ID_GSM_SIM4;
            
#endif
#endif
			#if (MMI_MAX_SIM_NUM >=2)/*kuldeep_nosim*/
              case SRV_MODE_SWITCH_SIM_ALL:
#if (MMI_MAX_SIM_NUM ==2)
			return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2;
#endif
#if (MMI_MAX_SIM_NUM ==3)
			return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2 | SRV_UC_SIM_ID_GSM_SIM3;
#endif
#if (MMI_MAX_SIM_NUM ==4)
			return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2 | SRV_UC_SIM_ID_GSM_SIM3 |SRV_UC_SIM_ID_GSM_SIM4;
#endif
			#endif

        default:
            return SRV_UC_SIM_ID_UNCLASSIFIED;
            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sim_status_info_hdlr
 * DESCRIPTION
 *  Handler for start UC request
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_uc_sim_status_info_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
            {
			/*verify event on bootup or hot swap*/
		      if(srv_bootup_is_booting())
			  {
              srv_uc_sim_id sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
              srv_sim_ctrl_availability_changed_evt_struct *sim_status = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
              mmi_sim_enum sim = sim_status->sim;
              sim_id = mmi_uc_convert_mmisim_to_ucsim(sim);
              if(sim_id != SRV_UC_SIM_ID_UNCLASSIFIED)
               {
                  g_uc_p->srv_sim_info->valid_sim_id_info &= ~sim_id;
                   if(sim & srv_mode_switch_get_current_mode())
				   {
                     if(srv_sim_ctrl_is_available(sim))
					 {
                     g_uc_p->srv_sim_info->valid_sim_id_info |= sim_id;
					 }

				   }

                if(mmi_uc_convert_modeswitch_to_ucsim(srv_mode_switch_get_current_mode()) == sim_id)
				{
                   g_uc_p->srv_sim_info->valid_sim_id_info &= sim_id;
                }
			  }
			}
		
		 /*else hot swap event*/
		#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
		 else 
		 {
	       srv_sim_ctrl_availability_changed_evt_struct *sim_status = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
           mmi_sim_enum sim = sim_status->sim;
           srv_uc_sim_id sim_id = mmi_uc_convert_mmisim_to_ucsim(sim);
           if(srv_sim_ctrl_is_available(sim))
		   {
		    g_uc_p->srv_sim_info->valid_sim_id_info |= sim_id;
		   }
		   else
		   {
            g_uc_p->srv_sim_info->valid_sim_id_info &= ~sim_id;
		   }
           /*if no sim then discard msg and close UC*/
          #if (MMI_MAX_SIM_NUM >= 3)
		   if(g_uc_p->main.uc_sim_cui_id)
		   {
		    cui_sim_sel_close(g_uc_p->main.uc_sim_cui_id);
			g_uc_p->main.uc_sim_cui_id = GRP_ID_INVALID;
		   }
          #endif
		   if(mmi_uc_is_uc_screen_in_history())
		   {
			   mmi_uc_force_close(evt);
			   mmi_uc_reset_msg();
		   }
		 }
  #endif /*__SIM_HOT_WAP_SUPPORT__*/
            break;
            }

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            {
            srv_uc_sim_id sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
            U32 i = 1;
            srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;
            U32 mode = (U32)mode_status->gsm_select_mode;
            g_uc_p->srv_sim_info->valid_sim_id_info = SRV_UC_SIM_ID_UNCLASSIFIED;
            while(mode)
            {
                U32 sim = mode & i;
                if(sim)
                    {
                    if(srv_sim_ctrl_is_available((mmi_sim_enum)sim))
                    {
                        sim_id = mmi_uc_convert_mmisim_to_ucsim((mmi_sim_enum)sim);
                        g_uc_p->srv_sim_info->valid_sim_id_info |= sim_id;
                    }
                    }
                    else
                    {
                    sim_id = mmi_uc_convert_mmisim_to_ucsim((mmi_sim_enum)i);
                    g_uc_p->srv_sim_info->valid_sim_id_info &= ~sim_id;
                    }
                mode = mode & ~i;
                i = i << 1;
                    }
                    break;
            }

        default:
            break;
    }
    return MMI_RET_OK;
}




//#endif /* __MMI_DUAL_SIM_MASTER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms_rsp_retry_timeout_callback
 * DESCRIPTION
 *  the timeout handler for interrupt cases while handling create_mms_rsp
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_create_mms_rsp_retry_timeout_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the interrupt screen exit or not, if not, still start timer to wait for next check */
    if (mmi_frm_scrn_get_active_id() != SCR_ID_UC_PROCESSING)
    {
        if (!mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            StopTimer(UC_CREATE_RSP_RETRY_TIMER_ID);
            if (g_uc_p->main.create_msg_rsp)
            {
                kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.create_msg_rsp);
                g_uc_p->main.create_msg_rsp = NULL;
            }
            return;
        }
        /* restart processing timer */
        StartTimer(UC_INPROGRESS_TIMER_ID, MMI_UC_INPROGRESS_TIME_OUT, mmi_uc_time_out_processing_generic);
        StartTimer(
            UC_CREATE_RSP_RETRY_TIMER_ID,
            MMI_UC_CREATE_RSP_RETRY_TIME,
            mmi_uc_create_mms_rsp_retry_timeout_callback);
    }
    else
    {
        /* if the create_rsp is triggered by mmi_uc_create_mms_rsp_retry_timeout_callback, then the retry check flow won't be triggered in create_mms_rsp, 
           so we can free create_msg_rsp here. */
        if (g_uc_p->main.create_msg_rsp)
        {
            mmi_uc_create_mms_rsp((srv_mms_result_enum)0, (void*)g_uc_p->main.create_msg_rsp, NULL);
        }
    }
    return;
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_handle_select_bookmark_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_handle_select_bookmark_rsp(U8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_HANDLE_SELECT_BOOKMARK_RSP_P1, 1);

    mmi_uc_set_group_id();

    {
        mmi_scrn_node_struct node_info;
        U16 chars_num = mmi_chset_utf8_strlen((const kal_uint8*)((S8*) url));
        U8 result = 0, tone = 0;
		U32 buffer_count = (CUI_BKM_MAX_URL_LEN < SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)? CUI_BKM_MAX_URL_LEN: SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;

		if (chars_num < buffer_count)
		{
			buffer_count = chars_num;
		}

        if (chars_num > 0)
        {
            //U8 *ucs2_buffer = OslMalloc((chars_num << 1 + 1) * ENCODING_LENGTH);
			U8 *ucs2_buffer = kal_adm_alloc(g_uc_p->main.mem_pool_id, (buffer_count << 1 + 1) * ENCODING_LENGTH);

            memset(ucs2_buffer, 0x00, (buffer_count << 1 + 1) * ENCODING_LENGTH);
            if ((strlen((const char*)url) != chars_num))
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) ucs2_buffer,
                    (kal_int32) (buffer_count << 1 + 1),
                    (kal_uint8*) url);
            }
            else
            {
                mmi_asc_n_to_ucs2((S8*) ucs2_buffer, (S8*) url, buffer_count);
            }
            chars_num = mmi_ucs2strlen((S8*) ucs2_buffer);
            if (mmi_uc_check_insert_text((U8*) ucs2_buffer))
            {
                if (mmi_frm_scrn_get_info(g_uc_p->main.uc_cui_gid, SCR_ID_UC_EDITOR, &node_info)  == MMI_RET_OK)
                {
                    result = wgui_uce_insert_text_template((U8*) ucs2_buffer, chars_num, node_info.gui_buf);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                tone = (U8) SRV_UC_NO_SPACE_TONE;
            }

            //OslMfree(ucs2_buffer);
			kal_adm_free(g_uc_p->main.mem_pool_id, ucs2_buffer);

            if (MMI_TRUE == mmi_msg_check_interrupt())
            {
                if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    mmi_uc_set_group_id();
                }
                else
                {
                    MMI_ASSERT(0);
					MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
				}
                
            }
            else
            {
                if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))//IsScreenPresent(SCR_ID_UC_EDITOR))
                {
                    mmi_uc_set_group_id();
                }
                else
                {
                    MMI_ASSERT(0);
                }

                if (tone == (U8) SRV_UC_NO_SPACE_TONE)
                {
                    mmi_uc_display_popup(SRV_UC_NO_SPACE_TONE);
                }
                else if (result == 0 || (result != chars_num))
                {
                    mmi_uc_display_popup(SRV_UC_NO_SPACE);
                }
            }
        }
        else
        {
            if (MMI_TRUE == mmi_msg_check_interrupt())
            {
                if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    mmi_uc_set_group_id();
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    mmi_uc_set_group_id();
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
    }

}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_terminate_editor
 * DESCRIPTION
 *  To terminate UC when MMA send termination
    indication
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_uc_terminate_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_uc_p->srv_send_info->fs)
    {
        FS_Close(g_uc_p->srv_send_info->fs);
        g_uc_p->srv_send_info->fs = 0;
    }
    
    mmi_uc_reset_msg();
	return MMI_RET_OK ;
}

#if /*((MMI_MAX_SIM_NUM == 1) && defined(__SIM_HOT_SWAP_SUPPORT__))*/ 0
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
/* under construction !*/
/* under construction !*/
#endif /*(defined(MMI_MAX_SIM_NUM == 1) && defined(__SIM_HOT_SWAP_SUPPORT__))*/

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _MMI_UNIFIED_COMPOSER_APP_MSG_HDLR_C */ 

#endif /* __MMI_TELEPHONY_SUPPORT__ */
