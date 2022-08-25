
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
 * MMSAppOp.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "custom_mmi_default_value.h"
#include "CustDataRes.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "GlobalResDef.h"
#include "USBDeviceGprot.h"
#include "kal_trace.h"
#include "MMI_inet_app_trc.h"
#include "mmi_rp_app_sms_def.h"
#include "mma_api.h"
#include "mma_struct.h"
#include "MMSAppOp.h"
#include "MMSAppDataManager.h"
#include "MMSMemoryManagerSrv.h"
#include "MmsSrvGprot.h"
//#include "CommonScreens.h"
//#include "MMSAppUICommon.h"
#include "MMSAppInterfaceGprot.h"
#include "MMSAppInterfaceProt.h"
// #include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
// #include "inlineCuiGprot.h"
#include "MMSAppSrvHdlr.h"
//#include "MMSAppUIPlugin.h"
//#include "MMSAppScrHdlrEx.h"
#include "UcAppGprot.h"
// #include "MessagesResourceData.h"
#include "ProfilesSrvGprot.h"
//#include "UCMGProt.h"
//#include "Custom_events_notify.h"
#include "phbsrvGprot.h"
#include "DateTimeGprot.h"
//#include "MMSAppUtil.h"
//#include "IdleAppGprot.h"
#include "UcSrvGprot.h"
#include "IdleHomescreenGProt.h"
#include "DebugInitDef_Int.h"
#include "UMGProt.h"
#include "mms_sap_struct.h"
#include "GlobalConstants.h"
//#include "SimDetectionStruct.h"    
//#include "SimDetectionGprot.h"  
#include "mmi_frm_events_gprot.h"
#include "IdleRecentEventGprot.h"
#include "gui_data_types.h"
#include "gui.h"
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#include "HomeScreenOp11V32Def.h"
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 
// #include "smssrvgprot.h"
#include "IdleNotificationManagerGprot.h"

extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
mmi_umms_op_hs_cntx_struct current_hs_struct;
static mmi_umms_op_hs_cntx_struct *g_current_hs_context = &current_hs_struct;
static mmi_umms_op_op11_struct g_umms_op11_data;
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
mmi_umms_op_hs32_cntx_struct current_hs32_struct;
static mmi_umms_op_hs32_cntx_struct *g_current_hs32_context = &current_hs32_struct;
static mmi_umms_op_op11_hs32_struct g_umms_op11_hs32_data;
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */

#ifdef __MMI_OP12_TOOLBAR__
mmi_umms_op_tb_struct umms_tb_struct;
static mmi_umms_op_tb_struct *g_umms_tb_cntx = &umms_tb_struct;
static mmi_umms_op_op12_struct g_umms_op12_data;
#endif /* __MMI_OP12_TOOLBAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_wap_ready_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_wap_ready_hdlr(void)
{
#ifdef __MMI_OP11_HOMESCREEN__
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
#endif /* __MMI_OP11_HOMESCREEN__ */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    if (g_current_hs_context->wap_is_not_ready_for_recent_events == MMI_TRUE)
    {
        mmi_umms_op_hs_get_recent_mms(g_current_hs_context->num_of_msg_req_by_hs_for_recent_event);
    }
    g_current_hs_context->wap_ready_ind_received = MMI_TRUE;
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP12_TOOLBAR__
    if (g_umms_tb_cntx->is_tb_active_from_idle == MMI_TRUE)
    {
        mmi_umms_op_tb_evnt_query_mms(g_umms_tb_cntx->num_of_msg_req_by_tb);
    }
    g_umms_tb_cntx->wap_is_ready_for_tb = MMI_TRUE;
#endif /* __MMI_OP12_TOOLBAR__ */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (g_current_hs32_context->wap_is_not_ready_for_indicator == MMI_TRUE)
    {
        mmi_mms_query_sidebar_info_for_ready();
    }

    if (g_current_hs32_context->wap_is_not_ready_for_data == MMI_TRUE)
    {
        mmi_op11_hs32_get_mms_shct_data_on_ready();
    }
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 
}

#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
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
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
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
    #ifdef __MMS_STANDALONE_COMPOSER_SUPPORT__
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__ */ 

/* For Home Screen */

#ifdef __MMI_OP11_HOMESCREEN__
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
#endif /* __MMI_OP11_HOMESCREEN__ */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_key_hndlr_for_mms_view_from_data_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_type        [IN]        
 *  user_data       [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_key_hndlr_for_mms_view_from_data_ext(U16 key_code, U16 key_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_hs_event(MMI_TRUE);
    mmi_umms_op_set_key_hndlr_for_mms_view_from_data(key_code, key_type, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_key_hndlr_for_mms_view_from_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_type        [IN]        
 *  user_data       [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_key_hndlr_for_mms_view_from_data(U16 key_code, U16 key_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
    switch (key_code)
    {
        case KEY_LSK:
        case KEY_ENTER:
        case KEY_RIGHT_ARROW:
            if (srv_mms_is_usb_mode())
            {
            #ifdef __USB_IN_NORMAL_MODE__
                mmi_usb_app_unavailable_popup(0);
            #endif 
                return;
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            if (srv_mms_get_sim_valid_flag() == 0)
        #else /* defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS > 2) */
            if (!(srv_sim_ctrl_is_available(MMI_SIM1)) || (!srv_mode_switch_is_network_service_available()))
        #endif /* __MMI_MMS_DUAL_SIM__ */
            {
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                    MMI_EVENT_FAILURE);
                mmi_umms_app_if_show_display_popup_screen();
                return;
            }
            // srv_mms_set_progress_screen();*/
            g_current_hs_context->msg_id = *(U32*) user_data;
            /* MMI_TRACE(
               MMI_INET_TRC_G6_MMS,
               MMI_UMMS_HS_SET_KEY_HNDLR_FOR_VIEW_DATA,
               g_current_hs_context->msg_id); */

            mmi_umms_op_hs_get_header(g_current_hs_context->msg_id, key_code, srv_mms_get_hs_event());
            break;
        default:
            break;
    }

}
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP11_HOMESCREEN__
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
            #ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
            #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 

/* Recent Event */
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_recent_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs_get_recent_mms(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_recent_evt_list_req_struct msg_req;
    mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_dtmgr_reset_data(); */
    g_current_hs_context->num_of_msg_req_by_hs_for_recent_event = (U32) num;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_GET_RECENT_EVENT, num);
    g_current_hs_context->hs_start_index_for_recent_event = 0;
    srv_mms_set_hs_event(MMI_TRUE);
    if (srv_mms_is_wap_ready())
    {

        msg_req.user_data = 0;
        msg_req.call_back = mmi_umms_op_hs_get_recent_mms_rsp_callback;
        msg_req.start_index = 0;
        msg_req.num_of_evt_requested = num;
        msg_req.app_id = MMA_APP_ID_HOME_SCREEN_RECENT_EVENT;
        srv_mms_get_recent_evt_list(&msg_req);
        g_current_hs_context->current_hs_event = E_HS_STATE_GET_RECENT_EVENT;
        op_data->hs_new_mms_arrived = MMI_FALSE;
    }
    else
    {
        g_current_hs_context->wap_is_not_ready_for_recent_events = MMI_TRUE;
        mmi_hs_recent_event_answer(MMI_HS_RECENT_EVENT_MMS, MMI_HS_RESULT_NOT_READY, (S32) 0, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_recent_mms_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs_get_recent_mms_rsp_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_recent_evt_list_rsp_struct *msg_rsp = (srv_mms_recent_evt_list_rsp_struct*) rsp_data;
    srv_mms_recent_evt_list_req_struct msg_req;
    mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_rsp->result == MMA_RESULT_OK)
    {
        if ((g_current_hs_context->current_hs_event == E_HS_STATE_INERUPT_PHONE_SUIT_EVENT) ||
            op_data->hs_new_mms_arrived)
        {

            msg_req.user_data = 0;
            msg_req.call_back = mmi_umms_op_hs_get_recent_mms_rsp_callback;
            msg_req.start_index = mmi_umms_op_get_start_index_for_recent_event();
            msg_req.num_of_evt_requested = mmi_umms_op_get_recent_event_msg_list_count();
            msg_req.app_id = MMA_APP_ID_HOME_SCREEN_RECENT_EVENT;
            srv_mms_get_recent_evt_list(&msg_req);
            op_data->hs_new_mms_arrived = MMI_FALSE;

            return;
        }
        if (msg_rsp->more == TRUE)
        {
            /* Means more data is needed from MMA */
            if (mmi_umms_op_get_recent_event_msg_list_count() - msg_rsp->num_of_evt > 0)
            {
                mmi_umms_op_set_data_for_recent_event(msg_rsp);

                msg_req.user_data = 0;
                msg_req.call_back = mmi_umms_op_hs_get_recent_mms_rsp_callback;
                msg_req.start_index = mmi_umms_op_get_start_index_for_recent_event();
                msg_req.num_of_evt_requested = mmi_umms_op_get_recent_event_msg_list_count() - msg_rsp->num_of_evt;
                msg_req.app_id = MMA_APP_ID_HOME_SCREEN_RECENT_EVENT;
                srv_mms_get_recent_evt_list(&msg_req);

                g_current_hs_context->hs_start_index_for_recent_event = msg_rsp->num_of_evt;
                return;
            }
            else
            {

                g_current_hs_context->current_hs_event = E_HS_STATE_NONE;
                mmi_umms_op_set_data_for_recent_event(msg_rsp);
            }
        }
        else
        {
            g_current_hs_context->current_hs_event = E_HS_STATE_NONE;
            mmi_umms_op_set_data_for_recent_event(msg_rsp);
        }
    }
    else
    {
        /* Send the Error Message to Home Screen */
        g_current_hs_context->current_hs_event = E_HS_STATE_NONE;
        mmi_umms_op_set_data_for_recent_event(msg_rsp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_data_for_recent_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_data_for_recent_event(srv_mms_recent_evt_list_rsp_struct *msg_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 loop_count = 0;
    MYTIME time, time1;
    FLOAT timezone = 0;
    mmi_hs_result_enum hs_result = MMI_HS_RESULT_NOT_READY;

    /* static mmi_hs_menu_data_struct srv_mms_hs_data_struct[MMA_MAX_EVT_NUM]; */
    mmi_hs_recent_event_struct *umms_hs_recent_event_data_struct = NULL;
    S8 str_sub_cmp_temp[MMA_MAX_SUBJECT_LEN] = {0x00, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    umms_hs_recent_event_data_struct = srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_hs_recent_event_struct) *
                                                                     g_current_hs_context->
                                                                     num_of_msg_req_by_hs_for_recent_event);
    memset(
        umms_hs_recent_event_data_struct,
        0,
        g_current_hs_context->num_of_msg_req_by_hs_for_recent_event * sizeof(mmi_hs_recent_event_struct));

    if (msg_rsp->result == MMA_RESULT_OK)
    {
        if (g_current_hs_context->num_of_msg_req_by_hs_for_recent_event <= msg_rsp->total_num_of_evt)
        {
            loop_count = g_current_hs_context->num_of_msg_req_by_hs_for_recent_event;
        }
        else
        {
            loop_count = msg_rsp->total_num_of_evt;
        }
        for (i = mmi_umms_op_get_start_index_for_recent_event(); i < loop_count; i++)
        {
            umms_hs_recent_event_data_struct[i].subject = srv_mms_mem_mgr_app_adm_alloc((MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            memset(umms_hs_recent_event_data_struct[i].subject, 0, (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            if (mmi_ucs2ncmp((S8*) msg_rsp->event_list[i].subject, (S8*) str_sub_cmp_temp, MMA_MAX_ADDR_LEN))
            {
                mmi_ucs2ncpy(
                    (S8*) umms_hs_recent_event_data_struct[i].subject,
                    (S8*) msg_rsp->event_list[i].subject,
                    (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) umms_hs_recent_event_data_struct[i].subject,
                    (S8*) GetString(STR_ID_UMMS_NO_SUBJECT),
                    (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            }

            if (msg_rsp->event_list[i].received_date > 0)
            {
                timezone = mmi_dt_get_tz();

                mmi_dt_utc_sec_2_mytime(msg_rsp->event_list[i].received_date, &time1, MMI_TRUE);
                mmi_dt_utc_to_rtc(timezone, time1, time);
                umms_hs_recent_event_data_struct[i].time.nYear = time.nYear;
                umms_hs_recent_event_data_struct[i].time.nMonth = time.nMonth;
                umms_hs_recent_event_data_struct[i].time.nDay = time.nDay;
                umms_hs_recent_event_data_struct[i].time.nHour = time.nHour;
                umms_hs_recent_event_data_struct[i].time.nMin = time.nMin;
                umms_hs_recent_event_data_struct[i].time.nSec = time.nSec;
                umms_hs_recent_event_data_struct[i].time.DayIndex = time.DayIndex;
            }
            g_current_hs_context->user_data_recent_events[i] = msg_rsp->event_list[i].msg_id;
            umms_hs_recent_event_data_struct[i].user_data = (void*)&g_current_hs_context->user_data_recent_events[i];
            umms_hs_recent_event_data_struct[i].is_read = (MMI_BOOL) msg_rsp->event_list[i].is_read;
            umms_hs_recent_event_data_struct[i].icon = msg_rsp->event_list[i].icon_id;
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_UMMS_HS_SET_DATA_FOR_RECENT_EVENTS,
                umms_hs_recent_event_data_struct[i].subject,
                msg_rsp->event_list[i].received_date,
                umms_hs_recent_event_data_struct[i].user_data);
        }

        if (g_current_hs_context->wap_is_not_ready_for_recent_events == MMI_TRUE)
        {
            hs_result = MMI_HS_RESULT_UPDATE;
            g_current_hs_context->wap_is_not_ready_for_recent_events = MMI_FALSE;
        }
        else
        {
            hs_result = MMI_HS_RESULT_OK;
        }
        if (g_current_hs_context->num_of_msg_req_by_hs_for_recent_event >= msg_rsp->total_num_of_evt)
        {
            mmi_hs_recent_event_answer(
                MMI_HS_RECENT_EVENT_MMS,
                hs_result,
                (S32) msg_rsp->total_num_of_evt,
                umms_hs_recent_event_data_struct,
                mmi_umms_op_set_key_hndlr_for_mms_view_from_data_ext);
        }
        else
        {
            mmi_hs_recent_event_answer(
                MMI_HS_RECENT_EVENT_MMS,
                hs_result,
                (S32) g_current_hs_context->num_of_msg_req_by_hs_for_recent_event,
                umms_hs_recent_event_data_struct,
                mmi_umms_op_set_key_hndlr_for_mms_view_from_data_ext);
        }
    }
    else
    {
        mmi_hs_recent_event_answer(
            MMI_HS_RECENT_EVENT_MMS,
            MMI_HS_RESULT_NOT_READY,
            (S32) g_current_hs_context->num_of_msg_req_by_hs_for_recent_event,
            NULL,
            NULL);
    }
    if (umms_hs_recent_event_data_struct != NULL)
    {
        for (i = 0; i < msg_rsp->num_of_evt; i++)
        {
            if (umms_hs_recent_event_data_struct[i].subject != NULL)
            {
                srv_mms_mem_mgr_app_adm_free(umms_hs_recent_event_data_struct[i].subject);
            }

            if (umms_hs_recent_event_data_struct[i].user_data != NULL)
            {
                /* srv_mms_mem_mgr_app_adm_free(srv_mms_hs_data_struct[i].user_data); */
            }
        }

        srv_mms_mem_mgr_app_adm_free(umms_hs_recent_event_data_struct);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_recent_event_msg_list_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_op_get_recent_event_msg_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_HS_GET_RECENT_EVENT_MSG_LIST_COUNT,
        g_current_hs_context->num_of_msg_req_by_hs_for_recent_event);
    return g_current_hs_context->num_of_msg_req_by_hs_for_recent_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_start_index_for_recent_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_op_get_start_index_for_recent_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_HS_GET_START_INDEX_RECENT_EVENT,
        g_current_hs_context->hs_start_index_for_recent_event);
    return g_current_hs_context->hs_start_index_for_recent_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_init_hs_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_init_hs_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_INIT_CONTEXT);
    g_current_hs_context->num_of_msg_req_by_hs = 0;
    g_current_hs_context->num_of_msg_req_by_hs_for_recent_event = 0;
    g_current_hs_context->hs_start_index = 0;
    g_current_hs_context->hs_start_index_for_recent_event = 0;
    g_current_hs_context->wap_is_not_ready_for_indicator = MMI_FALSE;
    g_current_hs_context->wap_is_not_ready_for_soft_notes = MMI_FALSE;
    g_current_hs_context->wap_is_not_ready_for_data = MMI_FALSE;
    g_current_hs_context->g_hs_new_mms_arrived = MMI_FALSE;
    g_current_hs_context->g_hs1_new_mms_arrived = MMI_FALSE;
    g_current_hs_context->wap_is_not_ready_for_recent_events = MMI_FALSE;
    g_current_hs_context->wap_ready_ind_received = MMI_FALSE;
    memset(g_current_hs_context->user_data, 0, MMI_HS_MAX_MENU_DATA_NEW_MMS_NUM);
    memset(g_current_hs_context->user_data_recent_events, 0, MMI_HS_MAX_RECENT_EVENT_NUM);

}
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP11_HOMESCREEN__
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
#endif /* __MMI_OP11_HOMESCREEN__ */ /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */

#ifdef __MMI_OP12_TOOLBAR__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_toolbar_option_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_op_toolbar_option_hdlr(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_is_usb_mode())
    {
    #ifdef __USB_IN_NORMAL_MODE__
        mmi_usb_app_unavailable_popup(0);
        return MMI_FALSE;
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        return MMI_FALSE;
    }
    switch (menu_id)
    {
        case MENU_ID_UMMS_TB_VIEW:
            mmi_umms_op_view_from_tb(KEY_LSK, g_umms_tb_cntx->msg_id);
            return MMI_TRUE;
        case MENU_ID_UMMS_TB_CALL:
            mmi_umms_op_tb_call(KEY_LSK, g_umms_tb_cntx->msg_id);
            return MMI_TRUE;
        case MENU_ID_UMMS_TB_DELETE:
            mmi_umms_op_tb_delete(KEY_LSK, g_umms_tb_cntx->msg_id);
            return MMI_TRUE;

        case MENU_ID_UMMS_OP12_TOOL_BAR_SETTING:
            mmi_tb_entry_toolbar_setting();
            return MMI_TRUE;

        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_evnt_query_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_evnt_query_mms(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_tb_evnt_struct tb_event_struct;
    srv_mms_get_unread_msg_list_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_tb_cntx->num_of_msg_req_by_tb = (U32) num;
    g_umms_tb_cntx->is_tb_active_from_idle = MMI_TRUE;
    g_umms_tb_cntx->umms_tb_start_index = 0;
    if (srv_mms_is_wap_ready())
    {
        g_umms_tb_cntx->wap_is_ready_for_tb = MMI_TRUE;
        req.user_data = 0;
        req.call_back = mmi_umms_op_tb_evnt_query_mms_rsp_callback;
        req.start_index = 0;
        req.num_of_msg_requested = num;
        req.app_id = MMA_APP_ID_TOOL_BAR;

        srv_mms_get_unread_msg_list(&req);
    }
    else
    {
        g_umms_tb_cntx->wap_is_ready_for_tb = MMI_FALSE;
        mmi_tb_evnt_answer(MMI_TB_EVNT_NEW_MMS, MMI_TB_RESULT_NOT_READY, 0, 0, &tb_event_struct, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_evnt_query_mms_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_evnt_query_mms_rsp_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_unread_msg_list_req_struct req;
    srv_mms_get_unread_msg_list_rsp_struct *msg_rsp = (srv_mms_get_unread_msg_list_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_rsp->result == MMA_RESULT_OK)
    {
        if (msg_rsp->more == TRUE)
        {
            /* Means more data is needed from MMA */
            if (g_umms_tb_cntx->num_of_msg_req_by_tb - msg_rsp->num_of_unread_msg > 0)
            {
                memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));
                mmi_umms_op_set_data_for_tb(msg_rsp);
                req.user_data = 0;
                req.call_back = mmi_umms_op_tb_evnt_query_mms_rsp_callback;
                req.start_index = msg_rsp->num_of_unread_msg;
                req.num_of_msg_requested = g_umms_tb_cntx->num_of_msg_req_by_tb - msg_rsp->num_of_unread_msg;
                req.app_id = MMA_APP_ID_TOOL_BAR;

                srv_mms_get_unread_msg_list(&req);
                mmi_umms_op_update_start_index_for_tb(msg_rsp->num_of_unread_msg);
                return;
            }
            else
            {
                mmi_umms_op_set_data_for_tb(msg_rsp);
            }
        }
        else
        {
            mmi_umms_op_set_data_for_tb(msg_rsp);
        }
    }
    else
    {
        /* Send the Error Message to Home Screen */
        mmi_umms_op_set_data_for_tb(msg_rsp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_data_for_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_data_for_tb(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 loop_count = 0;
    MYTIME time, time1;
    mmi_tb_result_enum tb_result = MMI_TB_RESULT_NOT_READY;

    /* static mmi_hs_menu_data_struct srv_mms_hs_data_struct[MMA_MAX_EVT_NUM]; */
    mmi_tb_evnt_struct *umms_mms_tb_data_struct = NULL;
    S8 str_sub_cmp_temp[MMA_MAX_SUBJECT_LEN] = {0x00, };
    FLOAT timezone = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    umms_mms_tb_data_struct = srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_tb_evnt_struct) * g_umms_tb_cntx->num_of_msg_req_by_tb);
    memset(umms_mms_tb_data_struct, 0, g_umms_tb_cntx->num_of_msg_req_by_tb * sizeof(mmi_tb_evnt_struct));

    if (msg_rsp->result == MMA_RESULT_OK)
    {
        if (g_umms_tb_cntx->num_of_msg_req_by_tb <= msg_rsp->total_num_of_unread_msg)
        {
            loop_count = g_umms_tb_cntx->num_of_msg_req_by_tb;
        }
        else
        {
            loop_count = msg_rsp->total_num_of_unread_msg;
        }
        for (i = g_umms_tb_cntx->umms_tb_start_index; i < loop_count; i++)
        {
            U32 msg_type;
            U32 temp_number;
            U32 user_data;

            umms_mms_tb_data_struct[i].subject = srv_mms_mem_mgr_app_adm_alloc((MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            memset(umms_mms_tb_data_struct[i].subject, 0, (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            if (mmi_ucs2ncmp((S8*) msg_rsp->unread_msg_list[i].subject, (S8*) str_sub_cmp_temp, MMA_MAX_ADDR_LEN))
            {
                mmi_ucs2ncpy(
                    (S8*) umms_mms_tb_data_struct[i].subject,
                    (S8*) msg_rsp->unread_msg_list[i].subject,
                    (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) umms_mms_tb_data_struct[i].subject,
                    (S8*) GetString(STR_ID_UMMS_NO_SUBJECT),
                    (MMA_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
            }

            umms_mms_tb_data_struct[i].is_time_present = MMI_TRUE;
            timezone = mmi_dt_get_tz();
            mmi_dt_utc_sec_2_mytime(msg_rsp->unread_msg_list[i].received_date, &time1, MMI_TRUE);
            mmi_dt_utc_to_rtc(timezone, time1, time);
            umms_mms_tb_data_struct[i].time.nYear = time.nYear;
            umms_mms_tb_data_struct[i].time.nMonth = time.nMonth;
            umms_mms_tb_data_struct[i].time.nDay = time.nDay;
            umms_mms_tb_data_struct[i].time.nHour = time.nHour;
            umms_mms_tb_data_struct[i].time.nMin = time.nMin;
            umms_mms_tb_data_struct[i].time.nSec = time.nSec;
            umms_mms_tb_data_struct[i].icon = msg_rsp->unread_msg_list[i].icon_id;
            umms_mms_tb_data_struct[i].time.DayIndex = time.DayIndex;

            g_umms_tb_cntx->user_data[i] = msg_rsp->unread_msg_list[i].msg_id;

            /* temp_number = (U32)msg_rsp->unread_msg_list[i].msg_type;
               temp_number = temp_number<<16;
               user_data = (U32) msg_rsp->unread_msg_list[i].msg_id;
               
               temp_number = temp_number | user_data; */

            g_umms_tb_cntx->user_data[i] = msg_rsp->unread_msg_list[i].msg_id;

            umms_mms_tb_data_struct[i].user_data = (void*)&g_umms_tb_cntx->user_data[i];
        }

        if (srv_mms_is_wap_ready() == MMI_FALSE)
        {
            tb_result = MMI_TB_RESULT_NOT_READY;
        }
        else
        {
            tb_result = MMI_TB_RESULT_UPDATE;
        }
        if (g_umms_tb_cntx->num_of_msg_req_by_tb >= msg_rsp->total_num_of_unread_msg)
        {
            mmi_tb_evnt_answer(
                MMI_TB_EVNT_NEW_MMS,
                tb_result,
                (S32) msg_rsp->total_num_of_unread_msg,
                (S32) msg_rsp->total_num_of_unread_msg,
                umms_mms_tb_data_struct,
                mmi_umms_op_set_key_hndlr_for_mms_view_from_tb,
                mmi_umms_op_set_key_hndlr_for_multi_hndlr_for_tb);
        }
        else
        {
            mmi_tb_evnt_answer(
                MMI_TB_EVNT_NEW_MMS,
                tb_result,
                (S32) msg_rsp->total_num_of_unread_msg,
                (S32) g_umms_tb_cntx->num_of_msg_req_by_tb,
                umms_mms_tb_data_struct,
                mmi_umms_op_set_key_hndlr_for_mms_view_from_tb,
                mmi_umms_op_set_key_hndlr_for_multi_hndlr_for_tb);
        }
    }
    else
    {
        mmi_tb_evnt_answer(
            MMI_TB_EVNT_NEW_MMS,
            MMI_TB_RESULT_NOT_READY,
            (S32) msg_rsp->total_num_of_unread_msg,
            (S32) g_umms_tb_cntx->num_of_msg_req_by_tb,
            NULL,
            NULL,
            NULL);
    }
    if (umms_mms_tb_data_struct != NULL)
    {
        for (i = 0; i < msg_rsp->num_of_unread_msg; i++)
        {
            if (umms_mms_tb_data_struct[i].subject != NULL)
            {
                srv_mms_mem_mgr_app_adm_free(umms_mms_tb_data_struct[i].subject);
            }

            if (umms_mms_tb_data_struct[i].user_data != NULL)
            {
                /* srv_mms_mem_mgr_app_adm_free(srv_mms_hs_data_struct[i].user_data); */
            }
        }

        srv_mms_mem_mgr_app_adm_free(umms_mms_tb_data_struct);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_key_hndlr_for_mms_view_from_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_type        [IN]        
 *  user_data       [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_key_hndlr_for_mms_view_from_tb(U16 key_code, U16 key_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
        case KEY_LSK:
        case KEY_RIGHT_ARROW:
            if (srv_mms_is_usb_mode())
            {
            #ifdef __USB_IN_NORMAL_MODE__
                mmi_usb_app_unavailable_popup(0);
            #endif 
                return;
            }
            /* srv_mms_set_progress_screen(); */
            g_umms_tb_cntx->is_tb_active = MMI_TRUE;
            g_umms_tb_cntx->msg_id = *(U32*) user_data;
            mmi_umms_op_tb_entry_option_live();
            break;
        case KEY_ENTER:
            if (srv_mms_is_usb_mode())
            {
            #ifdef __USB_IN_NORMAL_MODE__
                mmi_usb_app_unavailable_popup(0);
            #endif 
                return;
            }
            g_umms_tb_cntx->is_tb_active = MMI_TRUE;
            g_umms_tb_cntx->msg_id = *(U32*) user_data;
            /* srv_mms_entry_tb_view(); */
            mmi_umms_op_view_from_tb(key_code, g_umms_tb_cntx->msg_id);
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_key_hndlr_for_multi_hndlr_for_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_key_hndlr_for_multi_hndlr_for_tb(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tb_proc_message_um(key_code, key_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_update_start_index_for_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_update_start_index_for_tb(U32 new_start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_GET_UPDATE_INDEX_RECENT_EVENT, new_start_index);
    g_umms_tb_cntx->umms_tb_start_index = new_start_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_init_tb_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_init_tb_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_tb_cntx->num_of_msg_req_by_tb = 0;
    g_umms_tb_cntx->umms_tb_start_index = 0;
    g_umms_tb_cntx->umms_tb_new_mms_arrived = MMI_FALSE;
    g_umms_tb_cntx->wap_is_ready_for_tb = MMI_FALSE;
    g_umms_tb_cntx->umms_view_from_tb = MMI_FALSE;
    memset(g_umms_tb_cntx->user_data, 0, MMI_TB_MAX_NEW_MESSAGE_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_entry_option_live
 * DESCRIPTION
 *  This function shows the option menu of the OP12 live! module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_entry_option_live(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayCascadingMenu(MENU_ID_UMMS_TB_LIVE_OPTION, mmi_umms_op_toolbar_option_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_view_from_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  user_data       [IN]        
 *  msg_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_view_from_tb(U16 key_code, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_start_struct msg;
    U16 msg_type;
    U32 message_id;
    mma_sync_msg_attribute_struct msg_info;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* msg_type = (user_data>>16) & 0x0000ffff; */
    message_id = user_data;

    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));

    result = (U8) mma_mms_get_msg_attribute(message_id, &msg_info);
    if (result == MMA_RESULT_OK)
    {
        msg_type = msg_info.msg_type;

        switch (msg_type)
        {
            case MMA_MSG_TYPE_NOTIFICATION:
            case MMA_MSG_TYPE_JAVA:
                msg.action = MMI_UMMS_OPEN_MMS_OPTION;
                break;
            default:
                msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
                break;
        }
    }
    else
    {
        msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
    }

    msg.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(MMA_FOLDER_INBOX);

    msg.msg_id = (U32) message_id;
    mmi_umms_op_reset_op12_data();

    mmi_umms_app_dtmgr_reset_data();
    mmi_umms_op_set_op12_data(MMI_TRUE, UMMS_TB_STATE_VIEW);
    mmi_umms_app_if_show_mms_screen_no_reset((void*)&msg);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  user_data       [IN]        
 *  msg_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_call(U16 key_code, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_get_msg_info_req_struct msg_req;

    /* U16 msg_type; */
    U32 message_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* msg_type = (user_data>>16) & 0x0000ffff; */
    message_id = user_data; /* & 0x0000ffff; */

    mmi_umms_op_reset_op12_data();
    mmi_umms_op_set_op12_data(MMI_TRUE, UMMS_TB_STATE_CALL);

    mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
    mmi_umms_app_if_show_progress_screen();
    /* prepare service data */
    memset(&msg_req, 0, sizeof(srv_mms_mma_get_msg_info_req_struct));
    msg_req.msg_id = message_id;
    msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_op_tb_call_cb;
    msg_req.app_id = MMA_APP_ID_TOOL_BAR;
    srv_mms_mma_get_msg_info(&msg_req);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_call_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_call_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info;
    mmi_ucm_make_call_para_struct make_call_para;
    srv_mms_mma_get_msg_info_rsp_struct *rsp_msg_info = (srv_mms_mma_get_msg_info_rsp_struct*) msgrsp;
    mmi_umms_op_op12_struct *op_struct = mmi_umms_op_get_op12_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_msg_info->result != MMA_RESULT_OK)
    {
        mmi_umms_app_if_show_error_pop_up((U8) rsp_msg_info->result);
        mmi_umms_app_sh_delete_progress_screen();
    }

    mmi_umms_app_dtmgr_save_msg_info(msgrsp);

    info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_umms_app_sh_delete_progress_screen();
    }
    else
    {
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
        mmi_umms_app_dtmgr_reset_data();
    }

    switch (op_struct->current_tb_state)
    {
        case UMMS_TB_STATE_CALL:
            if (info->msg_info->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER && srv_mms_num_valid_sim())
            {
                /* MakeCall((S8*) (info->msg_info->from_address)); */
                mmi_ucm_init_call_para(&make_call_para);
                make_call_para.dial_type = SRV_UCM_CALL_TYPE_ALL;
                make_call_para.adv_para.after_make_call_callback = NULL;
                make_call_para.ucs2_num_uri = (U16*) info->msg_info->from_address;
                mmi_ucm_call_launch(0, &make_call_para);

            }
            else
            {
                /* Change the API here to display customize popup. */
                /* MAUI_01216984 */
                if (info->msg_info->from_address[0] == '\0')
                {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_USE_DETAILS_NO_NUMBER),
                        MMI_EVENT_FAILURE);
                    mmi_umms_app_if_show_display_popup_screen();

                }
                else
                {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_GLOBAL_INVALID_NUMBER),
                        MMI_EVENT_FAILURE);
                    mmi_umms_app_if_show_display_popup_screen();
                }
            }
            break;
        case UMMS_TB_STATE_DELETE:
            mmi_umms_app_ui_plug_in_delete_confirm_func();
            mmi_umms_app_if_show_display_confirm_screen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_tb_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  user_data       [IN]        
 *  msg_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_tb_delete(U16 key_code, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_get_msg_info_req_struct msg_req;

    /* U16 msg_type; */
    U32 message_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* msg_type = (user_data>>16) & 0x0000ffff; */
    message_id = user_data; /* & 0x0000ffff; */

    mmi_umms_op_reset_op12_data();
    mmi_umms_op_set_op12_data(MMI_TRUE, UMMS_TB_STATE_DELETE);

    mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
    mmi_umms_app_if_show_progress_screen();
    /* prepare service data */
    memset(&msg_req, 0, sizeof(srv_mms_mma_get_msg_info_req_struct));
    msg_req.msg_id = message_id;
    msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_op_tb_call_cb;
    msg_req.app_id = MMA_APP_ID_TOOL_BAR;
    srv_mms_mma_get_msg_info(&msg_req);
}

#endif /* __MMI_OP12_TOOLBAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_update_recent_event_list_from_phone_suit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)

    srv_mms_get_unread_msg_list_req_struct req;
    srv_mms_recent_evt_list_req_struct msg_req;
    S32 result;
    mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_UPDATE_RECENT_FRM_PHONE_SUIT, g_current_hs_context->current_hs_event);
    if (g_current_hs_context->current_hs_event == E_HS_STATE_GET_RECENT_EVENT)
    {
        /* After the Response is received again get the recent event list */
        g_current_hs_context->current_hs_event = E_HS_STATE_INERUPT_PHONE_SUIT_EVENT;
    }
    else
    {
        if (srv_mms_get_hs_event())
        {
            /* mmi_umms_app_dtmgr_reset_data(); */
            srv_mms_set_hs_event(MMI_TRUE);
            msg_req.user_data = 0;
            msg_req.call_back = mmi_umms_op_hs_get_recent_mms_rsp_callback;
            msg_req.start_index = mmi_umms_op_get_start_index_for_recent_event();
            msg_req.num_of_evt_requested = mmi_umms_op_get_recent_event_msg_list_count();
            msg_req.app_id = MMA_APP_ID_HOME_SCREEN_RECENT_EVENT;
            srv_mms_get_recent_evt_list(&msg_req);
            g_current_hs_context->current_hs_event = E_HS_STATE_GET_RECENT_EVENT;
            op_data->hs_new_mms_arrived = MMI_FALSE;

        }
    #ifdef __MMI_OP11_HOMESCREEN__
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
    #endif /* __MMI_OP11_HOMESCREEN__ */ 
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 
#ifdef __MMI_OP12_TOOLBAR__
    mmi_tb_evnt_struct tb_event_struct;
    srv_mms_get_unread_msg_list_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_UPDATE_RECENT_FRM_PHONE_SUIT, g_umms_tb_cntx->num_of_msg_req_by_tb);

    if (srv_mms_is_wap_ready())
    {
        g_umms_tb_cntx->wap_is_ready_for_tb = MMI_TRUE;
        req.user_data = 0;
        req.call_back = mmi_umms_op_tb_evnt_query_mms_rsp_callback;
        req.start_index = 0;
        req.num_of_msg_requested = g_umms_tb_cntx->num_of_msg_req_by_tb;
        req.app_id = MMA_APP_ID_TOOL_BAR;

        srv_mms_get_unread_msg_list(&req);
    }

#endif /* __MMI_OP12_TOOLBAR__ */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_idle_is_active())
    {
        U8 result;
        srv_mms_get_unread_msg_list_req_struct req;

        memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

        req.call_back = mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr;
        req.start_index = g_current_hs32_context->hs_start_index;
        req.num_of_msg_requested = g_current_hs32_context->num_of_msg_req_by_hs;
        req.app_id = MMA_APP_ID_HOME_SCREEN;
        result = srv_mms_get_unread_msg_list(&req);
        if (result != SRV_MMS_RESULT_OK)
        {
            ASSERT(0);
        }

    }
    if (mmi_idle_is_active())
    {
        mmi_mms_query_sidebar_info_for_ready();
    }
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    mmi_nmgr_refresh(MMI_NMGR_APP_MMS, MMI_NMGR_OPTION_USE_DEFAULT);
#endif
    return MMI_RET_OK;
}

#if defined(__MMI_OP12_TOOLBAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_op12_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tb_active               [IN]        
 *  current_tb_state        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_op12_data(BOOL tb_active, mmi_umms_tb_state current_tb_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_op12_data.tb_active = tb_active;
    g_umms_op12_data.current_tb_state = current_tb_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_op12_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_op_op12_struct *mmi_umms_op_get_op12_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_op12_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_reset_op12_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_reset_op12_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_umms_op12_data, 0, sizeof(mmi_umms_op_op12_struct));
}
#endif /* defined(__MMI_OP12_TOOLBAR__) */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_op11_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hs_active           [IN]        
 *  is_recent_event     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_op11_data(BOOL hs_active, BOOL is_recent_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_hs_active(hs_active);
    srv_mms_set_hs_event(is_recent_event);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_new_mms_arrived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_new_mms_arrived      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_new_mms_arrived(MMI_BOOL is_new_mms_arrived)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_op11_data.hs_new_mms_arrived = is_new_mms_arrived;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_op11_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_op_op11_struct *mmi_umms_op_get_op11_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_op11_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_reset_op11_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_reset_op11_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_umms_op11_data, 0, sizeof(mmi_umms_op_op11_struct));
    srv_mms_set_hs_active(MMI_FALSE);
    srv_mms_set_hs_event(MMI_FALSE);
}
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data           [IN]        
 *  key_code            [IN]        
 *  is_recent_event     [IN]        
 *  msg_id(?)           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs_get_header(U32 user_data, U16 key_code, BOOL is_recent_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_start_struct msg;

    U16 msg_type;
    U32 message_id;
    mma_sync_msg_attribute_struct msg_info;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));

    /* msg_type = (user_data>>16) & 0x0000ffff; */
    message_id = user_data;

    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));

    if (is_recent_event == MMI_TRUE)
    {
        msg.action = MMI_UMMS_OPEN_MMS_OPTION;
    }
    else
    {
        result = (U8) mma_mms_get_msg_attribute(message_id, &msg_info);

        if (result == MMA_RESULT_OK)
        {
            msg_type = msg_info.msg_type;

            switch (msg_type)
            {
                case MMA_MSG_TYPE_NOTIFICATION:
                case MMA_MSG_TYPE_JAVA:
                    msg.action = MMI_UMMS_OPEN_MMS_OPTION;
                    break;
                default:
                    msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
                    break;
            }
        }
        else
        {
            msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
        }
    }

    msg.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(MMA_FOLDER_INBOX);
    msg.msg_id = message_id;
    mmi_umms_op_reset_op11_data();

    mmi_umms_app_dtmgr_reset_data();
    mmi_umms_op_set_op11_data(MMI_TRUE, is_recent_event);
    mmi_umms_app_if_show_mms_screen_no_reset((void*)&msg);

}

#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_query_sidebar_info_for_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_query_sidebar_info_for_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    srv_mms_get_msg_count_struct msg_count_req;
    mmi_op11_hs32_sidebar_query_info_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));

    msg_count_req.count = 1;
    msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
    result = srv_mms_get_msg_count(&msg_count_req);

    if (result == SRV_MMS_RESULT_OK)
    {
        data.indicator_value = msg_count_req.rsp_tb[0];
        data.result_flag = MMI_OP11_HS32_RESULT_UPDATE;
    }
    else
    {
        data.result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
    }

    mmi_op11_hs32_answer_sidebar(g_current_hs32_context->sidebar_id, g_current_hs32_context->indctr_id, &data);

    g_current_hs32_context->wap_is_not_ready_for_indicator = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_query_sidebar_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sidebar_id      [IN]        
 *  indctr_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_query_sidebar_info(S32 sidebar_id, S32 indctr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    srv_mms_get_msg_count_struct msg_count_req;
    mmi_op11_hs32_sidebar_query_info_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_is_wap_ready())
    {
        memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));
        msg_count_req.count = 1;
        msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
        result = srv_mms_get_msg_count(&msg_count_req);

        if (result == SRV_MMS_RESULT_OK)
        {
            data.indicator_value = msg_count_req.rsp_tb[0];
            data.result_flag = MMI_OP11_HS32_RESULT_OK;
        }
        else
        {
            data.result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
        }

        mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, &data);

        g_current_hs32_context->wap_is_not_ready_for_indicator = MMI_FALSE;

    }
    else
    {
        g_current_hs32_context->wap_is_not_ready_for_indicator = MMI_TRUE;
        g_current_hs32_context->sidebar_id = sidebar_id;
        g_current_hs32_context->indctr_id = indctr_id;
        data.result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
        mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, &data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs32_get_mms_unread_rsp_hdlr
 * DESCRIPTION
 *  Returns the unread MMS count to Home Screen
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 *  process   [IN]Process struct(?)(?)
 *  msg       [IN]Response from MMA(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs32_get_mms_unread_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_sidebar_query_info_struct data;
    srv_mms_get_msg_num_rsp_struct *rsp = (srv_mms_get_msg_num_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(
       MMI_INET_TRC_G6_MMS,
       MMI_UMMS_HS_INDICATOR_ANSWER,
       result,
       unread_msg_number,
       g_current_hs_context->wap_is_not_ready_for_indicator); */
    if ((rsp->result == MMI_TRUE) && (result == SRV_MMS_RESULT_OK))
    {
        data.indicator_value = rsp->rsp_tb[0];
        data.result_flag = MMI_OP11_HS32_RESULT_UPDATE;
    }
    else
    {
        data.result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
    }

    mmi_op11_hs32_answer_sidebar(g_current_hs32_context->sidebar_id, g_current_hs32_context->indctr_id, &data);

    g_current_hs32_context->wap_is_not_ready_for_indicator = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_get_mms_shct_data_on_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_get_mms_shct_data_on_ready(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_unread_msg_list_req_struct req;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

    req.call_back = mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr;
    req.start_index = g_current_hs32_context->hs_start_index;
    req.num_of_msg_requested = g_current_hs32_context->num_of_msg_req_by_hs;
    req.app_id = MMA_APP_ID_HOME_SCREEN;
    result = srv_mms_get_unread_msg_list(&req);
    if (result != SRV_MMS_RESULT_OK)
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs32_get_mms_shct_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sidebar_id      [IN]        
 *  shct_id         [IN]        
 *  shct_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_op11_hs32_get_mms_shct_data(S32 sidebar_id, S32 shct_id, void *shct_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_shct_data_struct *shct_data_p = (mmi_op11_hs32_shct_data_struct*) shct_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_hs32_context->sidebar_id = sidebar_id;
    g_current_hs32_context->shct_id = shct_id;
    g_current_hs32_context->shct_data_p = shct_data_p;
    g_current_hs32_context->num_of_msg_req_by_hs = MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX;
    g_current_hs32_context->hs_start_index = 0;

    if (srv_mms_is_wap_ready())
    {
        srv_mms_get_unread_msg_list_req_struct req;
        S32 result;

        memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

        req.call_back = mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr;
        req.start_index = g_current_hs32_context->hs_start_index;
        req.num_of_msg_requested = g_current_hs32_context->num_of_msg_req_by_hs;
        req.app_id = MMA_APP_ID_HOME_SCREEN;
        result = srv_mms_get_unread_msg_list(&req);
        if (result != SRV_MMS_RESULT_OK)
        {
            ASSERT(0);
        }
    }
    g_current_hs32_context->wap_is_not_ready_for_data = MMI_TRUE;
    shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
    mmi_op11_hs32_answer_shct_data(sidebar_id, shct_id, shct_data_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_unread_msg_list_rsp_struct *rsp = (srv_mms_get_unread_msg_list_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((rsp->result == MMA_RESULT_OK) && (result == SRV_MMS_RESULT_OK))
    {
        if (rsp->more == TRUE)
        {
            /* Means more data is needed from MMA */
            if (g_current_hs32_context->num_of_msg_req_by_hs - rsp->num_of_unread_msg > 0)
            {
                srv_mms_get_unread_msg_list_req_struct req;
                S32 result;

                memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

                mmi_umms_op_set_data_for_hs32(rsp_data);

                g_current_hs32_context->hs_start_index =
                    g_current_hs32_context->hs_start_index + rsp->num_of_unread_msg;

                req.call_back = mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr;
                req.start_index = g_current_hs32_context->hs_start_index;
                req.num_of_msg_requested = g_current_hs32_context->num_of_msg_req_by_hs - rsp->num_of_unread_msg;
                req.app_id = MMA_APP_ID_HOME_SCREEN;
                result = srv_mms_get_unread_msg_list(&req);
                if (result != SRV_MMS_RESULT_OK)
                {
                    ASSERT(0);
                }

                return;
            }
            else
            {
                mmi_umms_op_set_data_for_hs32(rsp_data);
            }
        }
        else
        {
            mmi_umms_op_set_data_for_hs32(rsp_data);
        }
    }
    else if ((rsp->result != MMA_RESULT_OK) && (result == SRV_MMS_RESULT_OK))
    {
        /* Send the Error Message to Home Screen */
        mmi_umms_op_set_data_for_hs32(rsp_data);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_data_for_hs32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_data_for_hs32(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FLOAT timezone = 0;

    mmi_op11_hs32_shct_data_struct *shct_data_p;
    S32 i;
    U8 n = 0;
    MYTIME time, time1;

    /* S8 temp[SRV_SMS_MAX_ADDR_LEN * ENCODING_LENGTH]; */
    U16 name[MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX + 1];
    S8 tmp_str[UMMS_CONVERT_INDEX];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    shct_data_p = mmi_op11_hs32_get_shct_data_pointer(MMI_OP11_HS32_AP_MES, MMI_OP11_HS32_SHCT_MES_NEW_MMS);

    if (msg_rsp->result == MMA_RESULT_OK)
    {

        if (shct_data_p != NULL)
        {
            shct_data_p->item_count = msg_rsp->total_num_of_unread_msg;

            if (shct_data_p->item_count > MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX)
            {
                n = MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX;
            }
            else
            {
                n = shct_data_p->item_count;
            }

            for (i = 0; i < n; i++)
            {
                shct_data_p->item_uid[i] = (U32) msg_rsp->unread_msg_list[i].msg_id;

                /* shct_data_p->item_icon[i] = msg_rsp->unread_msg_list[i].icon_id; */

                /* memset(temp, 0, SRV_SMS_MAX_ADDR_LEN * ENCODING_LENGTH); */
                memset(name, 0, (MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX + 1) * ENCODING_LENGTH);

                /* mmi_ucs2cpy(temp, (S8*) msg_rsp->unread_msg_list[i].from_address); */
                srv_phb_get_name_by_number(
                    (U16*) msg_rsp->unread_msg_list[i].from_address,
                    (U16*) name,
                    MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX);
                if (name[0] != 0)
                {
                    mmi_ucs2ncpy((S8*) shct_data_p->item_name[i], (S8*) name, MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX);
                }
                else if (msg_rsp->unread_msg_list[i].from_address[0] != '\0')
                {
                    mmi_ucs2ncpy(
                        (S8*) shct_data_p->item_name[i],
                        (S8*) msg_rsp->unread_msg_list[i].from_address /* sender number  */ ,
                        MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX);
                }
                else
                {
                    /* mmi_ucs2ncpy((S8*)shct_data_p->item_name[i], GetString(STR_ID_UMMS_USE_DETAILS_NO_NUMBER), MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX); */
                }

                if (msg_rsp->unread_msg_list[i].is_subject || msg_rsp->unread_msg_list[i].is_text)
                {
                    mmi_ucs2ncpy(
                        (S8*) shct_data_p->item_content[i],
                        (S8*) msg_rsp->unread_msg_list[i].subject /* mms content */ ,
                        MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX);
                }
                else if (msg_rsp->unread_msg_list[i].num_attach)
                {
                    memset(tmp_str, 0, UMMS_CONVERT_INDEX);
                    gui_itoa(msg_rsp->unread_msg_list[i].num_attach, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
                    mmi_ucs2cpy((S8*) shct_data_p->item_content[i], (S8*) tmp_str);
                    mmi_ucs2cat((S8*) shct_data_p->item_content[i], (S8*) L" ");
                    mmi_ucs2cat((S8*) shct_data_p->item_content[i], (S8*) GetString(STR_ID_UMMS_ATTACHMENTS));
                }
                else
                {
                    mmi_ucs2cpy((S8*) shct_data_p->item_content[i], (S8*) GetString(STR_GLOBAL_EMPTY));
                    mmi_ucs2cat((S8*) shct_data_p->item_content[i], (S8*) L" ");
                    mmi_ucs2cat((S8*) shct_data_p->item_content[i], (S8*) GetString(STR_ID_UMMS_HINT_MESSAGE));
                }

                timezone = mmi_dt_get_tz();
                mmi_dt_utc_sec_2_mytime(msg_rsp->unread_msg_list[i].received_date, &time1, MMI_TRUE);
                mmi_dt_utc_to_rtc(timezone, time1, time);
                shct_data_p->item_time[i].nYear = time.nYear;
                shct_data_p->item_time[i].nMonth = time.nMonth;
                shct_data_p->item_time[i].nDay = time.nDay;
                shct_data_p->item_time[i].nHour = time.nHour;
                shct_data_p->item_time[i].nMin = time.nMin;
                shct_data_p->item_time[i].nSec = time.nSec;
                shct_data_p->item_time[i].DayIndex = time.DayIndex;
            }

            if (g_current_hs32_context->wap_is_not_ready_for_data == MMI_TRUE)
            {
                g_current_hs32_context->wap_is_not_ready_for_data = MMI_FALSE;
            }
            shct_data_p->result_flag = MMI_OP11_HS32_RESULT_UPDATE;
            mmi_op11_hs32_answer_shct_data(MMI_OP11_HS32_AP_MES, MMI_OP11_HS32_SHCT_MES_NEW_MMS, shct_data_p);
        }
    }
    else
    {
        if (shct_data_p != NULL)
        {
            shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
            mmi_op11_hs32_answer_shct_data(MMI_OP11_HS32_AP_MES, MMI_OP11_HS32_SHCT_MES_NEW_MMS, shct_data_p);
        }
    }

}

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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_op11_hs32_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hs_active       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_op11_hs32_data(MMI_BOOL hs_active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_op11_hs32_data.hs_active = hs_active;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_set_hs32_new_mms_arrived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_new_mms_arrived      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_set_hs32_new_mms_arrived(MMI_BOOL is_new_mms_arrived)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_op11_hs32_data.hs_new_mms_arrived = is_new_mms_arrived;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_get_op11_hs32_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_op_op11_hs32_struct *mmi_umms_op_get_op11_hs32_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_op11_hs32_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_reset_op11_hs32_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_reset_op11_hs32_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_umms_op11_hs32_data, 0, sizeof(g_umms_op11_hs32_data));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs32_shct_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  msg_id(?)       [IN]        
 *  key_code(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs32_shct_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_start_struct msg;

    U16 msg_type;
    U32 message_id;
    mma_sync_msg_attribute_struct msg_info;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_DUAL_SIM__
    if ((MMI_FALSE == srv_mms_get_sim_status((U8) MMI_SIM_ID_SIM1)) &&
        (MMI_FALSE == srv_mms_get_sim_status((U8) MMI_SIM_ID_SIM2)))
#else /* __MMI_MMS_DUAL_SIM__ */ 
    if (!(srv_sim_ctrl_is_available(MMI_SIM1)) || (!srv_mode_switch_is_network_service_available()))
#endif /* __MMI_MMS_DUAL_SIM__ */ 
    {
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        return;
    }
    mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);

    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));

    message_id = (U32) index;

    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));

    result = (U8) mma_mms_get_msg_attribute(message_id, &msg_info);

    if (result == MMA_RESULT_OK)
    {
        msg_type = msg_info.msg_type;

        switch (msg_type)
        {
            case MMA_MSG_TYPE_NOTIFICATION:
            case MMA_MSG_TYPE_JAVA:
                msg.action = MMI_UMMS_OPEN_MMS_OPTION;
                break;
            default:
                msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
                break;
        }
    }
    else
    {
        msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
    }

    msg.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(MMA_FOLDER_INBOX);
    msg.msg_id = message_id;
	msg.parent_grp_id = GRP_ID_ROOT ;
    mmi_umms_op_reset_op11_hs32_data();

    mmi_umms_app_dtmgr_reset_data();
    mmi_umms_op_set_op11_hs32_data(MMI_TRUE);
    mmi_umms_app_if_show_mms_screen_no_reset((void*)&msg);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_init_hs32_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_init_hs32_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HS_INIT_CONTEXT);
    g_current_hs32_context->num_of_msg_req_by_hs = 0;
    g_current_hs32_context->num_of_msg_req_by_hs_for_recent_event = 0;
    g_current_hs32_context->hs_start_index = 0;
    g_current_hs32_context->hs_start_index_for_recent_event = 0;
    g_current_hs32_context->wap_is_not_ready_for_indicator = MMI_FALSE;
    g_current_hs32_context->wap_is_not_ready_for_soft_notes = MMI_FALSE;
    g_current_hs32_context->wap_is_not_ready_for_data = MMI_FALSE;
    g_current_hs32_context->g_hs_new_mms_arrived = MMI_FALSE;
    g_current_hs32_context->g_hs1_new_mms_arrived = MMI_FALSE;
    g_current_hs32_context->wap_is_not_ready_for_recent_events = MMI_FALSE;
    g_current_hs32_context->wap_ready_ind_received = MMI_FALSE;

}

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#endif /* __MMI_MMS_2__ */ 

