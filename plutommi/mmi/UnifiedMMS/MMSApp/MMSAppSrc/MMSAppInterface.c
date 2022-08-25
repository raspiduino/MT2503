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
 * MMSAppInterface.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "mma_api.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
// #include "CallManagementGprot.h"
#include "MMSAppUICommon.h"
#include "MMSAppInterfaceprot.h"
#include "MMSAppInterfaceGprot.h"
#include "MMSAppUIController.h"
#include "MMSAppResDef.h"
// #include "inlineCuiGprot.h"
#include "MMSAppDataManager.h"
// #include "mmsadp.h"
#include "UMGProt.h"
#include "UcAppGProt.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSAppDataManager.h"
//#include "UnifiedMessageResDef.h"
//#include "SimDetectionGprot.h"
/* Amit added for profiles */

#include "WAPProfileSrvGProt.h"
#include "WAPProfileSrvType.h"
// #include "WAPprovisioningType.h"


#include "MmsSrvGprot.h"
#include "MMSAppSrvHdlr.h"
#include "MMSAppScrHdlrEx.h"
// #include "MessagesResourceData.h"
#include "IdleHomescreenGProt.h"
//#include "UcmGprot.h"
//#include "MMSAppOp.h"
#include "MmsSrvProt.h"
#include "MMSAppUIPlugin.h"

#include "MenuCuiGprot.h"
#include "MMSAppUICallback.h"
#include "med_api.h"
#include "med_mem.h"
#include "MsgViewerCuiGProt.h"
#include "mma_struct.h"
#include "UMDefs.h"
#include "UmSrvDefs.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "UcmSrvGprot.h"
#include "custom_wap_config.h"
#include "gdi_features.h"
#include "mms_sap_struct.h"
// #include "SimDetectionStruct.h"
#if(MMI_MAX_SIM_NUM >= 3)
#include "SimSelCuiGProt.h"
#endif 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#include "mms_api.h"
#include "MMSAppComposerUILE.h"
#include "MMSAppResourceDB.h"
#include "SimCtrlSrvGprot.h"
#include "USBsrvGprot.h"
#include "USBDeviceGprot.h"
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
extern void mmi_umms_app_ui_draw_dummy_screen(void);
extern void mmi_umms_app_sh_delete_umms_screens(void);
extern void mmi_umms_app_sh_delete_umms_use_details_screens(void);
extern void mmi_umms_app_sh_delete_umms_save_objects_screens(void);
extern void mmi_umms_app_ui_callback_check_compose_signature_settings_file_info(void);
extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_template_grp_proc_func(mmi_event_struct *evt);
extern kal_uint8 mma_get_mms_msg_type(kal_uint32 msg_id);
extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);

/* External Interface   */
extern void mmi_umms_settings_show_func(void);
extern void mmi_umms_app_ui_plug_in_reply_for_folder_list(void);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_option_screen_slim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_option_screen_slim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_OPTION_SLIM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_recipient_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_recipient_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_ADD_RECIPIENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_recipient_addresses_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_recipient_addresses_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_ADD_RECIPIENT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_composer_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_composer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_COMPOSER_OPTION);
}
/*
void mmi_umms_app_if_show_slim_reply_option(void)

{

   mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SLIM_REPLY_OPTION);
}*/
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_template_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_template_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    mmi_umms_app_show_template_menu();
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

}


/*****************************************************************************
 *  
 * FUNCTION
 *  mmi_umms_app_show_template_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_show_template_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_option_screen(void *data)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

     mmi_umms_app_start_struct *msg = (mmi_umms_app_start_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        //MMI_ID grp_id = mmi_umms_dtmgr_get_group_id() != GRP_ID_INVALID ? mmi_umms_dtmgr_get_group_id() : GRP_ID_ROOT;

        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            msg->parent_grp_id,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    mmi_umms_app_interface_prop_mms_only_options(data);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_view_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_view_screen(void *data)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_app_start_struct *msg_data = (mmi_umms_app_start_struct*) data;

        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_VIEW);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            msg_data->parent_grp_id,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PERFORMANCE_VIEWER_START);
    mmi_umms_app_interface_prop_show_viewer_screen(data, 0);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_preview_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_preview_screen(void *data)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_PREVIEW);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    mmi_umms_app_interface_prop_show_viewer_screen(data, 0);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_screen(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_start_struct *msg = (mmi_umms_app_start_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
    mmi_umms_app_dtmgr_reset_data();
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_umms_app_dtmgr_set_iterator_status(MMI_FALSE);
#endif 
    switch (msg->action)
    {
        case MMI_UMMS_OPEN_MMS_OPTION:
            mmi_umms_app_if_show_mms_option_screen(data);
            break;
        case MMI_UMMS_OPEN_MMS_VIEWER:
            mmi_umms_app_if_show_mms_view_screen(data);
            break;
    #ifdef __MMI_MMS_POSTCARD__
        case MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD:
    #endif 
        case MMI_UMMS_OPEN_MMS_PREVIEWER_MMS:
            mmi_umms_app_if_show_mms_preview_screen(data);
            break;
        default:
            break;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_screen_no_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_screen_no_reset(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_start_struct *msg = (mmi_umms_app_start_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->action)
    {
        case MMI_UMMS_OPEN_MMS_OPTION:
            mmi_umms_app_if_show_mms_option_screen(data);
            break;
        case MMI_UMMS_OPEN_MMS_VIEWER:
            mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
            mmi_umms_app_if_show_mms_view_screen(data);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_properties_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_properties_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
}

/* Internal Interface    */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_viewer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_VIEWER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_start_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_grp_id       [IN]        
 *  msg_id              [IN]        
 *  um_data             [?]         
 *  view_type           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_start_viewer(U16 parent_grp_id, U32 msg_id, void *um_data, cui_msg_viewer_type_enum view_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_start_struct msg;
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	mmi_um_entry_msg_struct user_data ;
     mmi_umms_entry_event_struct evt = {0, };
     mmi_um_opt_para_struct para = {0, };
   #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));
    /* ASSERT(parent_grp_id); */
    msg.um_data = um_data;
    msg.parent_grp_id = parent_grp_id;
    msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
    msg.msg_id = msg_id;
    msg.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(mma_get_box(msg_id));
    switch (view_type)
    {
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
        case CUI_MSG_VIEWER_TYPE_NORMAL:
            break;
        case CUI_MSG_VIEWER_TYPE_ITERATOR:
            msg.is_iterting = MMI_TRUE;
            break;
			
    #else /* __MMI_MMS_ITERATOR_VIEWER__ */ 
        case CUI_MSG_VIEWER_TYPE_ITERATOR:
            ASSERT(0);
			break;
			case CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD:
			#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		 	user_data.key_code = MMI_UM_UI_ENTRY_INTUITIVE_CMD ;
            #endif
			break;
		case CUI_MSG_VIEWER_TYPE_CSK_KEY :
			  if(mma_get_mms_msg_type(msg_id) == MMA_MSG_TYPE_JAVA)
				{
					 mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_FAILED_TO_DISPLAY_JSR_MMS),
                MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();
            return;
			  }
			  #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
				user_data.key_code =	MMI_UM_UI_ENTRY_KEY_CSK;
             #endif
				
				break;
    #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    }
	#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_if_show_mms_screen((void*)&msg);
    #else

	 user_data.parent_grp_id = msg.parent_grp_id;
 	 user_data.msg_id =  msg.msg_id;
     user_data.user_data = NULL ;
     evt.evt_id = EVT_ID_ON_KEY;
     evt.msg_data = &user_data;
     para.msg_id = msg.msg_id;
     para.parent_grp_id = msg.parent_grp_id;
     umms_cb_hdlr((mmi_event_struct*) & evt, &para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_draft_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_draft_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_DRAFT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_inbox_mms_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_inbox_mms_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_INBOX_MMS_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_inbox_notification_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_inbox_notification_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_inbox_read_delivery_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_inbox_read_delivery_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_inbox_java_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_inbox_java_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sent_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sent_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SENT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_outbox_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_outbox_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_OUTBOX_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_archive_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_archive_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_ARCHIVE_OPTION);
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_user_template_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_user_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_progress_scrn_data(STR_ID_UMMS_TEMPLATE_USER_DEFINED, STR_GLOBAL_PLEASE_WAIT);
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_TEMPLATES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_default_template_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_default_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_progress_scrn_data(STR_GLOBAL_DEFAULT, STR_GLOBAL_PLEASE_WAIT);
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_FWD_EDIT_CLUBBED);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_display_popup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_display_popup_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_DISPLAY_POPUP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_display_callback_popup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_display_callback_popup_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_CALLBACK_DISPLAY_POPUP);
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_template_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_template_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_TEMPLATES_OPTIONS);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id =
        (mmi_umms_dtmgr_get_group_id() ==
         GRP_ID_UMMS_LIST_TEMPLATES) ? SCR_ID_UMMS_PROGRESS_TMPLT : SCR_ID_UMMS_PROGRESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (mmi_umms_app_dtmgr_state_asm_waiting() == MMI_TRUE)
    {
        mmi_event_struct evt;

        memset(&evt, 0, sizeof(mmi_event_struct));
        evt.evt_id = EVT_ID_UMMS_DEINIT_FROM_HISTORY;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UMMS_DEINIT_FROM_HISTORY);
        MMI_FRM_POST_EVENT(&evt, mmi_umms_proc_func, NULL);
        return;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_umms_app_cntrlr_screen_render_start(scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_display_confirm_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_display_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_CONFIRM);
}

/* -------------------------------------------------------------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_message_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_message_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_SETTINGS);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    mmi_umms_app_show_message_settings_menu();
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_show_message_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_show_message_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* vaibhav changes */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (mmi_umms_app_ui_plug_in_message_settings_menu_pre_func(SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS) ==
        MMI_UMMS_FAIL)
        return;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_message_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_message_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MESSAGE_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_compose_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_compose_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_ui_callback_check_compose_signature_settings_file_info(); */
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_COMPOSE_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_retrieval_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_retrieval_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_RETRIEVAL_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sending_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sending_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SENDING_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_retrieval_filters_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_retrieval_filters_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_compose_signature_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_compose_signature_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_signature_options_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_signature_options_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_COMPOSE_IMAGE_OPTION);
}

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_pref_storage_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_pref_storage_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_PREFER_STORAGE);
}
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_pref_storage_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_msg_filter_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_MSG_FILTER);
}
#endif
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* amit added */

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_memory_status_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_memory_status_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_MESSAGE_STATUS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_phone_memory_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_phone_memory_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_card_memory_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_card_memory_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD);
}
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_memory_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_memory_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_MESSAGE_STATUS);
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_save_objects_attchement_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_save_objects_attchement_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_save_objects_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_save_objects_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SAVE_OBJECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sort_by_selection_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sort_by_selection_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SORT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_details_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_details_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_preview_mms_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_preview_mms_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_PREVIEW_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_java_mms_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_java_mms_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_JAVA_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sim_selection_profile_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sim_selection_profile_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_notification_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_notification_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_NOTIFICATION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_report_options_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_report_options_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
}

#if (MMI_MAX_SIM_NUM == 2)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sim_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sim_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SIM_OPTION);
}
#endif /* (MMI_MAX_SIM_NUM == 2) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_details_addresses_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_details_addresses_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_message_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_message_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MESSAGE_STATUS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_new_message_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_new_message_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MESSAGE_STATUS);        /* SCR_POPUP_SCREEN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_edit_profile_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_edit_profile_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check_sim_context */
    /* otherwise call profile api to shwo the profile list */

    if (srv_sim_ctrl_get_num_of_inserted())
    {
       

                srv_wap_prof_display_profile_list(
                SRV_WAP_PROF_SIMID_DEFAULT,/*SRV_WAP_PROF_SIMID_DEFAULT,*/
                    SRV_WAP_PROF_APPID_MMS,
                    GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
                    mmi_umms_dtmgr_get_group_id());
                return;

   

            }
    else
            {
        mmi_umms_app_dtmgr_set_popup_screen_para(
					(U16*) GetString(STR_GLOBAL_NOT_AVAILABLE),
					MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_java_mms_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_java_mms_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_NOTIFICATION_NEW_MMS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_NOTIFICATION_NEW_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_mms_full_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_mms_full_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
        mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
    }

    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_DISPLAY_INFINITE_POPUP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_if_show_default_template_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_if_show_default_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(22);
}

/* Proprietary Interface API   */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_interface_prop_show_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         [?]
 *  new_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_interface_prop_show_viewer_screen(void *data, U8 new_state)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SHARE_MED_EXT_MEM)
    PU8 buf_ptr_p = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_app_dtmgr_get_parent_grp_id() == GRP_ID_INVALID)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER)
        {
            mmi_umms_app_ui_draw_dummy_screen();
        }
        mmi_umms_app_if_deinit_viewer();
    }

    mmi_umms_dtmgr_update_for_viewer(data, SCR_ID_UMMS_MMS_VIEWER, new_state);
#if defined(J2ME_SHARE_MED_EXT_MEM)
    media_get_ext_buffer(MOD_MMI, (void **)&buf_ptr_p, MED_1_SCENARIO_VID_DECODE);

    if (buf_ptr_p == NULL)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        return;
    }
    media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr_p);
#endif /* defined(J2ME_SHARE_MED_EXT_MEM) */ 
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        return;
    }
    mmi_umms_app_if_show_viewer_screen();
    return;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_interface_prop_mms_only_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_interface_prop_mms_only_options(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    U16 folder_id;
    mmi_umms_app_start_struct *msg = (mmi_umms_app_start_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_id = mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder(msg->msg_box_type);

    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_INBOX_MMS_OPTION, 0);
            mmi_umms_app_if_show_inbox_mms_option();
            break;
        case MMA_FOLDER_OUTBOX:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_OUTBOX_OPTION, 0);
            mmi_umms_app_if_show_outbox_option();
            break;
        case MMA_FOLDER_SENT:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_SENT_OPTION, 0);
            mmi_umms_app_if_show_sent_option();
            break;
        case MMA_FOLDER_DRAFT:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_DRAFT_OPTION, 0);
            mmi_umms_app_if_show_draft_option();
            break;
        case MMA_FOLDER_ARCHIVE:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_ARCHIVE_OPTION, 0);
            mmi_umms_app_if_show_archive_option();
            break;
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_TEMPLATE:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_TEMPLATES_OPTIONS, 0);
            mmi_umms_app_if_show_mms_template_option();
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            mmi_umms_dtmgr_update_for_option((void*)msg, SCR_ID_UMMS_TEMPLATES_OPTIONS, 0);
            mmi_umms_app_if_show_mms_template_option();
            break;
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_interface_entry_from_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key                 [IN]        
 *  msg_id              [IN]        
 *  user_data           [?]         
 *  parent_grp_id       [IN]        
 *  data        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_interface_entry_from_um(U16 key, U32 msg_id, void *user_data, mmi_id parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_start_struct msg;
    U16 msg_type;
    mma_sync_msg_attribute_struct msg_info;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));
    msg.msg_id = msg_id;
    msg.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(mma_get_box(msg_id));
    msg.um_data = user_data;
    /* ASSERT(parent_grp_id); */
    msg.parent_grp_id = parent_grp_id;
    switch (key)
    {
        case MMI_UM_UI_ENTRY_KEY_CSK:
            if (msg.msg_box_type == SRV_UM_MSG_BOX_UNSENT)
            {
                msg.action = MMI_UMMS_OPEN_MMS_OPTION;
            }
            else
            {
                msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
            }
            break;
        case MMI_UM_UI_ENTRY_KEY_LSK:

            msg.action = MMI_UMMS_OPEN_MMS_OPTION;

            break;
        case MMI_UM_UI_ENTRY_INTUITIVE_CMD:
            if (msg.msg_box_type == SRV_UM_MSG_BOX_INBOX)
            {
                result = (U8) mma_mms_get_msg_attribute(msg_id, &msg_info);
                if (result == MMA_RESULT_OK)
                {
                    msg_type = msg_info.msg_type;

                    switch (msg_type)
                    {
                        case MMA_MSG_TYPE_NOTIFICATION:
                        case MMA_MSG_TYPE_JAVA:
                        case MMA_MSG_TYPE_READ_REPORT:
                        case MMA_MSG_TYPE_DELIVERY_REPORT:
                            return MMI_FALSE;
                    }
                }
            }
            if (msg.msg_box_type == SRV_UM_MSG_BOX_UNSENT)
            {
                return MMI_FALSE;
            }
            msg.action = MMI_UMMS_OPEN_MMS_VIEWER;
            break;
        default:
            break;
    }

    mmi_umms_app_if_show_mms_screen((void*)&msg);

    return ((MMI_BOOL)mmi_umms_dtmgr_get_group_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_stop_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_stop_viewer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_stop_app_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_stop_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_USE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_USE_EMAIL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_USE_URL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_sender
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_USE_SENDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_use_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_use_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_property_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_property_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
}

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_abnormal_view_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_abnormal_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN);
}
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_rr_dr_view_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_rr_dr_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_sort_by_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_sort_by_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_SORT_OPTION);
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_error_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_error_pop_up(const U8 error_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((mma_result_enum) error_result)
    {
        case MMA_RESULT_OK:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_DONE), MAX_PROGRESS_STRING_LENGTH);
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) string, MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        case MMA_RESULT_FAIL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL), MAX_PROGRESS_STRING_LENGTH);
            break;
            /* case MMA_RESULT_FAIL_IN_CALL:
               mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INCALL), MAX_PROGRESS_STRING_LENGTH);
               break; */
        case MMA_RESULT_FAIL_NOT_READY:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_NOT_AVAILABLE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_BUSY:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_BUSY_TRY_LATER), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED:
        case MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_NOT_FOUND:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_FILE_NOT_FOUND), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_CORRUPTED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_CORRUPTED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_IN_USE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_IN_USE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_IO:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_IO), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_UNSUPPORT_CONTENT),
                MAX_PROGRESS_STRING_LENGTH);
            break;
            /* case MMA_RESULT_FAIL_COMM_CONNECT_ERROR:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_CONNECT_ERROR),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_SERVER_TIMEOUT),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_USER_CANCEL:
               mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_USER_CANCEL), MAX_PROGRESS_STRING_LENGTH);
               break; */
        case MMA_RESULT_FAIL_INVALID_PARAMETER:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_PARAMETER),
                MAX_PROGRESS_STRING_LENGTH);
            break;
            /* case MMA_RESULT_FAIL_QUEUE_FULL:
               mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_QUEUE_FULL), MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_DELAYED:
               mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_DELAYED), MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_CONTINUE:
               mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_CONTINUE), MAX_PROGRESS_STRING_LENGTH);
               break; */
        case MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
            /* case MMA_RESULT_FAIL_FOLDER_NOT_FOUND:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FOLDER_NOT_FOUND),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_CONFIG_ERROR:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_CONFIG_ERROR),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_SERVER_ERROR:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_SERVER_ERROR),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_SERVICE_DENIED:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_SERVICE_DENIED),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_UNKNOWN_APN:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNKNOWN_APN),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
            /* case MMA_RESULT_FAIL_COMM_UNAUTHORIZED:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNAUTHORIZED),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
        case MMA_RESULT_FAIL_INVALID_MSGID:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_MSGID),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INVALID_FOLDER:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_FOLDER),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_PARSE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_PARSE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MSGID_IS_USING:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MSGID_IS_USING),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
            /* case MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM:
               mmi_ucs2ncpy(
               (PS8) string,
               (PS8) GetString(STR_ID_MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM),
               MAX_PROGRESS_STRING_LENGTH);
               break; */
        case MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_IN_VIDEO_CALL:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_IMAGE_TOO_LARGE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_LARGE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_ROOT_DIR_FULL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_ROOT_DIR_FULL), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_INSERT_CARD:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MAX_PROGRESS_STRING_LENGTH);
            break;
        default:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL), MAX_PROGRESS_STRING_LENGTH);
            break;

    }

    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) string, MMI_EVENT_PROPLEM);
    mmi_umms_app_if_show_display_popup_screen();
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_mms_in_open_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_if_is_mms_in_open_state(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_base_event_struct* base_evt = (srv_mms_base_event_struct*)evt;
    U32* msg_id = base_evt->sender_data;

    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data && (*msg_id == data->msg_id))
    {
        srv_mms_set_is_mms_in_use_flag(MMI_TRUE);
    }
    srv_mms_set_is_mms_in_use_flag(MMI_FALSE);

	return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_deinit_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_deinit_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* keep in sync with mmi_mv_delete_screen_cb */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_INTERFACE_VIEWER_DEINIT);
    /* StopTimer(MMS_VIEWER_TIMER); */

    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_RR_CONFIRM_SCREEN);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER);
    mmi_umms_app_dtmgr_deinit_viewer_service_through_dtmgr();
    mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_INVALID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_viewer_in_history
 * DESCRIPTION
 *  is viewer running
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_app_if_is_viewer_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_umms_app_if_is_viewer_init();
    /*
     * Incase DR/RR scr is present but viewer not in history then 
     * mmi_umms_is_option_screen_present is/should be checked
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_viewer_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_app_if_is_viewer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_INTERFACE_IS_VIEWER_INIT);
    if (cntx)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return srv_mms_container_get_is_viewed();
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_msg_in_view
 * DESCRIPTION
 *  Checks whether msg is currently viewed or not
 * PARAMETERS
 *  msg_id      [IN]        [In]
 * RETURNS
 *  TRUE: If msg_id is same as viewer contaxt's msg_id
 *  FALSE:Otherwise
 *****************************************************************************/
mmi_ret mmi_umms_app_if_msg_in_view(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx)
    {
        srv_mms_set_is_mms_in_use_flag(MMI_TRUE);
    }
    else
    {
        srv_mms_set_is_mms_in_use_flag(MMI_FALSE);
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    srv_mms_set_is_mms_in_use_flag( srv_mms_container_get_is_viewed());
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

	return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_uc_request_to_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_uc_request_to_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PREVIEW_OPTIONS ||
        mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PREVIEW_SLIDE_LIST
#if ((MMI_MAX_SIM_NUM >= 2) && defined(__MMI_UMMS_PREVIEW_SEND__))
        || mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_SIM_OPTION
#endif 
        )
    {
        mmi_umms_app_ui_draw_dummy_screen();
    }
#if ((MMI_MAX_SIM_NUM >= 2) && defined(__MMI_UMMS_PREVIEW_SEND__))
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SIM_OPTION);
#endif 
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PREVIEW_SLIDE_LIST);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PREVIEW_OPTIONS);
    mmi_umms_app_dtmgr_reset_data();    /* to fix mms option->edit issue */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_uc_preview_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_type        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_uc_preview_msg(U32 msg_id, U8 msg_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_start_struct msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg, 0, sizeof(mmi_umms_app_start_struct));
    msg.msg_id = msg_id;    /* function to get current msg_id ke index pe jo hilight hai */
    msg.msg_box_type = 0;
#ifdef __MMI_MMS_POSTCARD__
    if (msg_type == MMA_MSG_TYPE_POSTCARD)
    {
        msg.action = MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD;
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        msg.action = MMI_UMMS_OPEN_MMS_PREVIEWER_MMS;
    }

    mmi_umms_app_if_show_mms_screen((void*)&msg);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  cui_umms_app_set_uc_preview_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_type        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *cui_umms_app_set_uc_preview_msg(U32 msg_id, U8 msg_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_start_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_umms_app_start_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_start_struct));
    memset(msg, 0, sizeof(mmi_umms_app_start_struct));
    msg->msg_id = msg_id;   /* function to get current msg_id ke index pe jo hilight hai */
    msg->msg_box_type = 0;
#ifdef __MMI_MMS_POSTCARD__
    if (msg_type == MMA_MSG_TYPE_POSTCARD)
    {
        msg->action = MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD;
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        msg->action = MMI_UMMS_OPEN_MMS_PREVIEWER_MMS;
    }
    return (void*)msg;
}

#ifdef __MMI_UMMS_PREVIEW_SEND__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_preview_uc_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_preview_uc_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Remove Preview and Option Screen */
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PREVIEW_OPTIONS)
    {
        mmi_umms_app_ui_draw_dummy_screen();
    }
    mmi_umms_app_if_show_uc_add_address_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_uc_add_address_screen
 * DESCRIPTION
 *  Handler for Send After Preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_uc_add_address_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_edit_mms_content_from_previewer();
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PREVIEW_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER);

}
#endif /* __MMI_UMMS_PREVIEW_SEND__ */ 

#ifdef __MMI_MMS_PREVIEW_GOTO__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_preview_option
 * DESCRIPTION
 *  Handler for option After Preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_preview_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_PREVIEW_OPTIONS);
}
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_preview_slide_list
 * DESCRIPTION
 *  display slide list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_preview_slide_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_PREVIEW_SLIDE_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_option_screen_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_is_option_screen_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BACKGROUND_CALL__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* mmi_frm_group_close(mmi_umms_dtmgr_get_group_id()); */
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_end_call_is_download_in_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_end_call_is_download_in_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_msg_screen_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_is_msg_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_NOTIFICATION_NEW_MMS)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_check_mms_insert_postcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_type       [IN]        
 *  file_path       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_check_mms_insert_postcard(mmi_fmgr_filetype_enum file_type, char *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_check_struct check_result;
    mma_insert_info_struct insert_info;
    mma_creation_mode_enum creation_mode;
    kal_bool is_restricted = KAL_FALSE;
    MMI_BOOL flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CHECK_MMS_INSERT_POSTCARD);
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    memset(&insert_info, 0, sizeof(mma_insert_info_struct));
    insert_info.insert_type = MMA_INSERT_UNKNOWN;
    insert_info.current_msg_size = 0;
    insert_info.max_msg_size = wap_custom_get_max_mms_msg_size();
    insert_info.mms_type = MMA_MMS_TYPE_SMIL_MMS;
    insert_info.filepath = (U16*) srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
    memset(insert_info.filepath, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);

    creation_mode = srv_mms_compose_settings_creation_mode();
    insert_info.creation_mode = creation_mode;

    mmi_ucs2cpy((S8*) insert_info.filepath, (S8*) file_path);

    /* mma_uc_insert_object_check(&insert_info, &check_result); */

    if (mma_check_drm_type((kal_wchar*) file_path) == MMA_DRM_NONE)
    {
        //if (check_result.insert_type == MMA_INSERT_IMAGE)
        //{
        flag = MMI_TRUE;
        /* } */
    }

    is_restricted = (kal_bool)(srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED);
    if (!is_restricted)
    {
        switch (file_type)
        {
            case FMGR_TYPE_BMP:
            case FMGR_TYPE_WBMP:
            case FMGR_TYPE_WBM:
        #ifdef JPG_DECODE
            case FMGR_TYPE_JPG:
            case FMGR_TYPE_JPEG:
        #endif /* JPG_DECODE */ 
        #ifdef GDI_USING_PNG
            case FMGR_TYPE_PNG:
        #endif 
        #ifdef SVG_SUPPORT
            case FMGR_TYPE_SVG:
        #endif 
                srv_mms_mem_mgr_app_adm_free(insert_info.filepath);
                insert_info.filepath = NULL;
                return ((MMI_BOOL)(flag && MMI_TRUE));
        }
    }
    else
    {
        switch (file_type)
        {
            case FMGR_TYPE_WBMP:
            case FMGR_TYPE_WBM:
        #ifdef JPG_DECODE
            case FMGR_TYPE_JPG:
            case FMGR_TYPE_JPEG:
        #endif /* JPG_DECODE */ 
                srv_mms_mem_mgr_app_adm_free(insert_info.filepath);
                insert_info.filepath = NULL;
                return ((MMI_BOOL)(flag && MMI_TRUE));
        }
    }
    srv_mms_mem_mgr_app_adm_free(insert_info.filepath);
    insert_info.filepath = NULL;
    return MMI_FALSE;
}

#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */ 

#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_reply_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_reply_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 status;
    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_mms_bgsr_get_msg_status(msg_id);
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
    if (status == SRV_MMS_BGSR_STATUS_SENDING)
    {
        if (sync_info->msg_info.folder == MMA_FOLDER_INBOX)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_READ_REPORT_IS_IN_SEND),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            srv_mms_reset_sync_data();
            return;

        }

    }
#endif
	#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#if defined (__MMS_STANDALONE_COMPOSER_SUPPORT__)
    if (sync_info->msg_info.from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
    {
        mmi_umms_app_ui_plug_in_reply_as_sms_for_msg_list();
    }
    else
    {
        mmi_umms_app_ui_plug_in_reply_for_folder_list();
    }
#elif defined(__UNIFIED_COMPOSER_SUPPORT__)
    mmi_umms_app_ui_plug_in_reply_for_folder_list();
#endif 
  #else
	
if (sync_info->msg_info.from_address_type == MMA_ADDR_TYPE_EMAIL)
    {
        mmi_umms_app_ui_plug_in_reply_for_folder_list();
    }
else
    {
       mmi_umms_app_ui_plug_in_reply_as_sms_for_msg_list();
    }
  
  #endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_forward_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_forward_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 status;

#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    U32 max_msg_size = 0;
    S8 tmp_str[10] = {0, };
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_mms_bgsr_get_msg_status(msg_id);
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);

#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
    if (status == SRV_MMS_BGSR_STATUS_SENDING)
    {
        if (sync_info->msg_info.folder == MMA_FOLDER_INBOX)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_READ_REPORT_IS_IN_SEND),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            srv_mms_reset_sync_data();
            return;

        }

    }
#endif

    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_FWD, g_current_mms_info_list->current_msg_id); */
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)
 
    {
        max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
        if (sync_info->msg_info.user_elements_size > max_msg_size)
        {

            mmi_umms_app_plug_in_wap_connection_error_popup(
                sync_info->msg_info.user_elements_size,
                max_msg_size,
                STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS);
            srv_mms_reset_sync_data();
            return;
        }
    }
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    if (sync_info->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;

        creation_mode = srv_mms_compose_settings_creation_mode();
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {

            /* mmi_umms_show_content_mode_confrm_pop_up(); */

            mmi_umms_app_dtmgr_set_confirm_screen_para(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U16*) GetString(STR_ID_UMMS_RESTRICTED_MODE),
                MMI_EVENT_QUERY,
                MMI_FALSE,
                MMI_TRUE,
                mmi_umms_app_ui_plug_in_edit_fwd_mode_for_msg_list_toolbar,
                mmi_frm_scrn_close_active_id,
                NULL,
                NULL);
            mmi_umms_app_if_show_display_confirm_screen();

        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {

            /* mmi_umms_show_content_mode_confrm_pop_up(); */
            mmi_umms_app_dtmgr_set_confirm_screen_para(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U16*) GetString(STR_ID_UMMS_MODE_WARNING_CONFIRM),
                MMI_EVENT_QUERY,
                MMI_FALSE,
                MMI_TRUE,
                mmi_umms_app_ui_plug_in_edit_fwd_mode_for_msg_list_toolbar,
                mmi_frm_scrn_close_active_id,
                NULL,
                NULL);
            mmi_umms_app_if_show_display_confirm_screen();

        }
        else
        {
            mmi_umms_app_ui_plug_in_edit_fwd_mode_for_msg_list_toolbar();
        }
    }
    else
    {
        mmi_umms_app_ui_plug_in_edit_fwd_mode_for_msg_list_toolbar();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_edit_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_edit_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    U32 max_msg_size = 0;
#elif defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    U32 max_msg_size = 0;
#endif 
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_EDIT, g_current_mms_info_list->current_msg_id); */
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);

    if ((srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING) &&
        (sync_info->msg_info.folder == MMA_FOLDER_OUTBOX))
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MESSAGE_IS_IN_SEND), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        srv_mms_reset_sync_data();
        return;
    }
#ifndef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)

    {
        max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
        if (sync_info->msg_info.user_elements_size > max_msg_size)
        {
            mmi_umms_app_plug_in_wap_connection_error_popup(
                sync_info->msg_info.user_elements_size,
                max_msg_size,
                STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS);
            srv_mms_reset_sync_data();
            return;
        }
    }
#elif defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)

    {
        max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
        if (sync_info->msg_info.msg_size > max_msg_size)
        {
            mmi_umms_app_plug_in_wap_connection_error_popup(
                sync_info->msg_info.msg_size,
                max_msg_size,
                STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS);
            srv_mms_reset_sync_data();
            return;
        }
    }
#endif 
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

    if (sync_info->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;

        creation_mode = srv_mms_compose_settings_creation_mode();
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            mmi_umms_app_dtmgr_set_confirm_screen_para(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U16*) GetString(STR_ID_UMMS_RESTRICTED_MODE),
                MMI_EVENT_QUERY,
                MMI_FALSE,
                MMI_FALSE,
                mmi_umms_app_ui_plug_in_edit_for_msg_list_toolbar,
                mmi_frm_scrn_close_active_id,
                NULL,
                NULL);
            mmi_umms_app_if_show_display_confirm_screen();

        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {
            mmi_umms_app_dtmgr_set_confirm_screen_para(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U16*) GetString(STR_ID_UMMS_MODE_WARNING_CONFIRM),
                MMI_EVENT_QUERY,
                MMI_FALSE,
                MMI_TRUE,
                mmi_umms_app_ui_plug_in_edit_for_msg_list_toolbar,
                mmi_frm_scrn_close_active_id,
                NULL,
                NULL);
            mmi_umms_app_if_show_display_confirm_screen();

        }
        else
        {
            mmi_umms_app_ui_plug_in_edit_for_msg_list_toolbar();
        }
    }
    else
    {
        mmi_umms_app_ui_plug_in_edit_for_msg_list_toolbar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_send_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__) ||defined(__MMI_OP12_MMS_MAX_SIZE_SUPPORT__)
    U32 max_msg_size = 0;
#endif

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    S8 tmp_str[10] = {0, };
#endif 

    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);

    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRE_ENTRY_SEND_REQ, g_current_mms_info_list->current_msg_id); */
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)


    {
        max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
        if (sync_info->msg_info.user_elements_size > max_msg_size)
        {

            mmi_umms_app_plug_in_wap_connection_error_popup(
                sync_info->msg_info.user_elements_size,
                max_msg_size,
                STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS);
            srv_mms_reset_sync_data();
            return;
        }
    }
#elif defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)

    {
        max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
        if (sync_info->msg_info.msg_size > max_msg_size)
        {
            mmi_umms_app_plug_in_wap_connection_error_popup(
                sync_info->msg_info.msg_size,
                max_msg_size,
                STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS);
            srv_mms_reset_sync_data();
            return;
        }
    }
#endif 
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    if (sync_info->msg_info.user_elements_size > (U32) srv_mms_sending_mms_size_limit())
    {
        max_msg_size = (U32) srv_mms_sending_mms_size_limit() / 1024;
        memset(subMenuData, 0, sizeof(subMenuData));
        /* MMS exceeds send limit XX KB  */
        mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_SEND_EXCEED_SIZE_LIMIT));
        mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
        gui_itoa(max_msg_size, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
        mmi_ucs2cat((S8*) subMenuData, (S8*) tmp_str);
        mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) subMenuData, MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        srv_mms_reset_sync_data();
        return;
    }
#else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    if (sync_info->msg_info.msg_size > (U32) srv_mms_sending_mms_size_limit())
    {
        max_msg_size = (U32) srv_mms_sending_mms_size_limit() / 1024;
        memset(subMenuData, 0, sizeof(subMenuData));
        /* MMS exceeds send limit XX KB  */
        mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_SEND_EXCEED_SIZE_LIMIT));
        mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
        gui_itoa(max_msg_size, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
        mmi_ucs2cat((S8*) subMenuData, (S8*) tmp_str);
        mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) subMenuData, MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        srv_mms_reset_sync_data();
        return;
    }

#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

    if (sync_info->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;

        creation_mode = srv_mms_compose_settings_creation_mode();
        if (creation_mode == MMA_CREATION_MODE_WARNING)
        {

            mmi_umms_app_dtmgr_set_confirm_screen_para(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (U16*) GetString(STR_ID_UMMS_MODE_WARNING_CONFIRM),
                MMI_EVENT_QUERY,
                MMI_FALSE,
                MMI_TRUE,
                mmi_umms_app_ui_plug_in_send_msg_from_msg_list,
                mmi_frm_scrn_close_active_id,
                NULL,
                NULL);
            mmi_umms_app_if_show_display_confirm_screen();

        }
        else
        {
            mmi_umms_app_ui_plug_in_send_msg_from_msg_list();
        }
    }
    else
    {
        mmi_umms_app_ui_plug_in_send_msg_from_msg_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_resend_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_resend_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3)
	MMI_ID sim_sel_parent_id;
	MMI_ID sim_sel_cui_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
    if (srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MESSAGE_IS_IN_SEND), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        srv_mms_reset_sync_data();
        return;
    }
#if (MMI_MAX_SIM_NUM >= 3)
	srv_mms_set_selected_sim_id(0);
	if(srv_mms_num_valid_sim() > 1)
    {
        sim_sel_parent_id = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_umms_app_ui_callback_sim_sel_post_action_decide, NULL);
        mmi_frm_group_enter(sim_sel_parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        sim_sel_cui_id = cui_sim_sel_create(sim_sel_parent_id, srv_mms_get_sim_valid_flag(), NULL);
        if(sim_sel_cui_id != GRP_ID_INVALID)
        {
             mmi_umms_app_dtmgr_set_sim_sel_cui_id(sim_sel_cui_id);
			 cui_sim_sel_set_highlight_sim(MMI_SIM1);
             cui_sim_sel_run(sim_sel_cui_id);
        }
            
	}
	else
	{
		 mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list();
	}
#elif(MMI_MAX_SIM_NUM == 2)
    srv_mms_set_selected_sim_id((U8) MMI_SIM1);
    if (srv_mms_num_valid_sim() > 1)
    {
		#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

      mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM1);
      mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM2);
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
        if (GRP_ID_INVALID == mmi_umms_app_dtmgr_get_parent_grp_id())
        {
            mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
        }
        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            mmi_umms_app_dtmgr_get_parent_grp_id(),
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        mmi_umms_app_if_show_sim_option();
    }
    else
    {
        mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list();
    }
#else /* (MMI_MAX_SIM_NUM >= 2) */ 
    mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list();
#endif /*MMI_MAX_SIM_NUM >= 3*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_delete_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_delete_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 status;
    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_mms_bgsr_get_msg_status(msg_id);
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);

    if (status == SRV_MMS_BGSR_STATUS_SENDING)
    {
        if (sync_info->msg_info.folder == MMA_FOLDER_INBOX)
        {
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_READ_REPORT_IS_IN_SEND),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
#endif

        }
        else if (sync_info->msg_info.folder == MMA_FOLDER_OUTBOX)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_MESSAGE_IS_IN_SEND),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
        }
        srv_mms_reset_sync_data();
        return;
    }

    if (status == SRV_MMS_BGSR_STATUS_DOWNLOADING)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_DOWNLOAD_IN_PROGRESS), MMI_EVENT_INFO);
        mmi_umms_app_if_show_display_popup_screen();
        srv_mms_reset_sync_data();
        return;
    }

    mmi_umms_app_ui_plug_in_delete_confirm_func_for_folder_list();
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	 if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
        if (GRP_ID_INVALID == mmi_umms_app_dtmgr_get_parent_grp_id())
        {
            mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
        }
        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            mmi_umms_app_dtmgr_get_parent_grp_id(),
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
#endif
    mmi_umms_app_if_show_display_confirm_screen();

}

#endif /* __MMI_FTE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_id cui_umms_preview_mms_create(mmi_id parent_id)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID != mmi_umms_dtmgr_get_group_id())
    {
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        mmi_umms_dtmgr_set_group_flag(MMI_FALSE);
    }
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_PREVIEW);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
        mmi_frm_group_create(parent_id, mmi_umms_dtmgr_get_group_id(), mmi_umms_proc_func, NULL);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return mmi_umms_dtmgr_get_group_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  msg             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cui_umms_preview_mms_run(mmi_id parent_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_start_struct *msg_data = (mmi_umms_app_start_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data->parent_grp_id = mmi_umms_app_dtmgr_get_parent_grp_id();
    mmi_frm_group_enter(parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_umms_app_if_show_mms_screen((void*)msg_data);
    srv_mms_mem_mgr_app_adm_free(msg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_umms_preview_mms_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_umms_preview_mms_close(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(parent_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_umms_mms_templates_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_id cui_umms_mms_templates_launch(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_tenplate_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
        mmi_umms_dtmgr_set_tenplate_group_flag(MMI_TRUE);
        mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
        mmi_frm_group_create_ex(
            parent_id,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_template_grp_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_umms_app_show_template_menu();
    }
    return mmi_umms_dtmgr_get_group_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_umms_mms_settings_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_id cui_umms_mms_settings_launch(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_SETTINGS);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
        mmi_frm_group_create_ex(
            parent_id,
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_umms_app_show_message_settings_menu();
    }
    return mmi_umms_dtmgr_get_group_id();
}



/*****************************************************************************
 * FUNCTION
 *  umms_menu_query_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_menu_id umms_menu_query_function(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_type;
    U16 folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_id = mma_get_box(msg_id);
    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
        {
            msg_type = mma_get_mms_msg_type(msg_id);
            switch (msg_type)
            {
                case MMA_MSG_TYPE_NOTIFICATION:
                    return MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION;
                case MMA_MSG_TYPE_DELIVERY_REPORT:
                case MMA_MSG_TYPE_READ_REPORT:
                    return MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT;

                case MMA_MSG_TYPE_MMS:
                    return MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS;
                case MMA_MSG_TYPE_JAVA:
                    return MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS;
                default:
                    return MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS;
            }
        }
        case MMA_FOLDER_OUTBOX:
            return MENU_ID_UMMS_OUTBOX_OPTIONS;
        case MMA_FOLDER_SENT:
            return MENU_ID_UMMS_SENT_OPTIONS;
        case MMA_FOLDER_DRAFT:
            return MENU_ID_UMMS_DRAFT_OPTIONS;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
        {
            mma_sync_msg_attribute_struct msg_info;

            mma_mms_get_msg_attribute(msg_id, &msg_info);
            switch (msg_info.prev_folder)
            {
                case MMA_FOLDER_INBOX:
                    return MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS;
                case MMA_FOLDER_OUTBOX:
                    return MENU_ID_UMMS_OUTBOX_OPTIONS;
                case MMA_FOLDER_SENT:
                    return MENU_ID_UMMS_SENT_OPTIONS;
                case MMA_FOLDER_DRAFT:
                    return MENU_ID_UMMS_DRAFT_OPTIONS;
				default: 
					return MENU_ID_UMMS_DRAFT_OPTIONS;
            }
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
	#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_TEMPLATE:
        case MMA_FOLDER_USRDEF_TEMPLATE:
            return MENU_ID_UMMS_TEMPLATES_OPTIONS;
    #endif
    #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
        case MMA_FOLDER_REPORT_BOX:
            return MENU_ID_UMMS_REPORT_BOX_OPTIONS;
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  umms_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [?]     
 *  para        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret umms_cb_hdlr(mmi_event_struct *evt, mmi_um_opt_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    mma_result_enum result_mma = MMA_RESULT_OK;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	MMI_UMMS_ERROR result = MMI_UMMS_FALSE;
    mmi_umms_app_dtmgr_option_scr_data_struct *data_new;
#endif
    cui_menu_event_struct *menu_evt;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_ON_KEY:
        {
        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            mmi_umms_dtmgr_set_proc_flag(KAL_FALSE);
            mmi_umms_app_dtmgr_reset_data();
            data_new =
                (mmi_umms_app_dtmgr_option_scr_data_struct*)
                srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
            ASSERT(data_new);
            memset(data_new, 0, sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
            mmi_umms_app_dtmgr_set_parent_grp_id(para->parent_grp_id);
            data_new->msg_id = para->msg_id;
            data_new->action = MMI_UMMS_OPEN_MMS_OPTION;
            data_new->folder_id = mma_get_box(para->msg_id);
        #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
            if (MMA_FOLDER_REPORT_BOX == data_new->folder_id)
            {

                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_UMMS_INTERFACE_UPDATE_DTMGR_FOR_OPTION,
                    data_new->msg_id,
                    data_new->folder_id);
                mmi_umms_app_dtmgr_update_state((void*)data_new, MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO, 0);
            }
            else
        #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
            {

            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                mmi_umms_app_dtmgr_update_state((void*)para->user_data, MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA, 0);
                mmi_umms_app_dtmgr_set_iterator_status(MMI_FALSE);
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_UMMS_INTERFACE_UPDATE_DTMGR_FOR_OPTION,
                    data_new->msg_id,
                    data_new->folder_id);
                mmi_umms_app_dtmgr_update_state((void*)data_new, MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO, 0);

                result = mmi_umms_app_dtmgr_get_option_scr_sync_data(
                            data_new,
                            MMI_TRUE,
                            (void*)mmi_umms_app_core_mms_app_asm_success_callback);

                   #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
				if(data_new->folder_id == MMA_FOLDER_ARCHIVE && (data_new->msg_info->prev_folder != MMA_FOLDER_INBOX  || data_new->msg_info->prev_folder != MMA_FOLDER_SENT || data_new->msg_info->prev_folder != MMA_FOLDER_DRAFT))
					{
						data_new->msg_info->prev_folder = MMA_FOLDER_DRAFT ;
					}
                   #endif

                if (result != MMI_UMMS_TRUE)
                {
                    return MMI_RET_ERR;
                }
            }
        #else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
            mmi_umms_entry_event_struct *evt_q = NULL;
            mmi_um_entry_msg_struct *msg_data = NULL;
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

            if (evt->evt_id == EVT_ID_ON_KEY)
            {
                evt_q = (mmi_umms_entry_event_struct*) evt;
                msg_data = (mmi_um_entry_msg_struct*) evt_q->msg_data;
            
			if(msg_data->key_code == MMI_UM_UI_ENTRY_INTUITIVE_CMD)
			{
				mma_sync_msg_attribute_struct msg_info;
				mma_result_enum result = mma_mms_get_msg_attribute(msg_data->msg_id, &msg_info);
				if (srv_mms_convert_mma_folder_to_umbox_type((mma_folder_enum)msg_info.folder) == SRV_UM_MSG_BOX_INBOX)
				{
					U16 msg_type;
					
					if (result == MMA_RESULT_OK)
					{
						msg_type = msg_info.msg_type;

						switch (msg_type)
						{
							case MMA_MSG_TYPE_NOTIFICATION:
							case MMA_MSG_TYPE_JAVA:
							case MMA_MSG_TYPE_READ_REPORT:
							case MMA_MSG_TYPE_DELIVERY_REPORT:
								return MMI_RET_ERR;
						}
					}
				}
				if (srv_mms_convert_mma_folder_to_umbox_type((mma_folder_enum)msg_info.folder) == SRV_UM_MSG_BOX_UNSENT)
				{
					return MMI_RET_ERR;
				}
				msg_data->key_code = MMI_UM_UI_ENTRY_KEY_CSK;
			}
			}
            if ((evt->evt_id == EVT_ID_ON_KEY && MMI_UM_UI_ENTRY_KEY_CSK == msg_data->key_code) ||
                evt->evt_id == EVT_ID_CUI_MENU_LIST_ENTRY)
            {
                srv_mms_container_reset_context();  /* First Entry Reset */
		if (mmi_umms_dtmgr_check_group_flag() == MMI_TRUE)
		{
			mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
			mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
			mmi_umms_dtmgr_set_group_flag(MMI_FALSE);
		}
                mmi_umms_app_dtmgr_set_parent_grp_id(para->parent_grp_id);
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
                result_mma = srv_mms_container_set_message_id(para->msg_id);    /* First Entry set Message ID and Fill Option Screen Data */
                if (result_mma == MMA_RESULT_OK)
                {
                    /* No Work Found yet */
                    /* if any thing need to do please write here */
                    /* This case is specially handled for notification, read report and delivery report */
                    /* No other case */
                    mmi_umms_app_dtmgr_option_scr_data_struct *data =
                        (mmi_umms_app_dtmgr_option_scr_data_struct*)
                        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
                    MMI_UMMS_ERROR asm_error = MMI_UMMS_FALSE;

                    if (data->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
                    {
                        mmi_umms_init_pools();
                        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
                        asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
                        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
                        {
                            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                            /* Close Group is a far better */
                            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
                            return MMI_RET_OK;
                        }
                        mmi_umms_dtmgr_set_proc_flag(KAL_FALSE);
                        srv_mms_initialize_header_for_special_mms();
                    }
                }
                else
                {
                    if (result_mma == MMA_RESULT_FAIL_FILE_CORRUPTED ||
                        result_mma == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
                    {
                        if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
                        {
                            mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
                            mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
                            mmi_frm_group_create_ex(
                                para->parent_grp_id,
                                mmi_umms_dtmgr_get_group_id(),
                                mmi_umms_proc_func,
                                NULL,
                                MMI_FRM_NODE_SMART_CLOSE_FLAG);
                        }
                    }
                    if (result_mma == MMA_RESULT_FAIL_FILE_CORRUPTED)
                    {
                        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
                        mmi_umms_app_sh_show_corrupt_and_delete();
                        /* This is error case */
                    }
                    else if (result_mma == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
                    {
                        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
                        mmi_umms_app_sh_show_unsupported_and_delete();
                        /* This is error case */
                    }
                    else
                    {
                        mmi_umms_dtmgr_set_group_id(menu_evt->sender_id);
                        mmi_umms_app_if_show_error_pop_up(result_mma);
                        /* This is error case */
                    }
                    /* srv_mms_container_reset_context(); */
                    return MMI_RET_ERR;
                }
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_MMS_OPTIONS);
            }
            if (evt->evt_id == EVT_ID_ON_KEY && MMI_UM_UI_ENTRY_KEY_CSK == msg_data->key_code)
            {
                mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
                srv_mms_set_open_mode(MMA_MODE_VIEW);   /* As Data Fetching Operates on MODE */
                mmi_umms_app_if_show_viewer_screen();   /* to start display viewer */
                return MMI_RET_OK;
            }
            if (EVT_ID_CUI_MENU_LIST_ENTRY == evt->evt_id)
            {
                mmi_umms_dtmgr_set_proc_flag(KAL_FALSE);
                mmi_umms_dtmgr_set_group_id(menu_evt->sender_id);
            }
        #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        }
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            menu_evt = (cui_menu_event_struct*) evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_DELETE
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_PROPERTIES
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
                #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD
                #endif
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_COPY_TO_CARD
#endif
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD
                //|| menu_evt->highlighted_menu_id == MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS
    #ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD
    #endif 
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                || menu_evt->highlighted_menu_id == MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE
    #endif 
                )
            {
                if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
                {
                    mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_GENERAL_OPERATION_SLIM);
                    mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
                    /* framework enhancement  changes */
                    mmi_frm_group_create_ex(
                        mmi_umms_app_dtmgr_get_parent_grp_id(),
                        mmi_umms_dtmgr_get_group_id(),
                        mmi_umms_proc_func,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
                    mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
                }
            }
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_umms_app_ui_callback_prop_unhide_all_menu_options(0);
            if (FALSE == mmi_umms_dtmgr_get_proc_flag())
            {
                mmi_umms_app_dtmgr_reset_data();
            }
        }
    #if((MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
        case EVT_ID_CUI_SIM_SEL_RESULT:
            /* Handler for SIM selector CUI */
            mmi_umms_app_ui_callback_sim_sel_post_action_decide(evt);
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
            return MMI_RET_OK;
    }

    return mmi_umms_proc_func(evt);
}

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_delivery_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_delivery_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_DELIVERY_STATUS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_read_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_read_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_cntrlr_screen_render_start(SCR_ID_UMMS_MMS_READ_STATUS);
}
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_get_um_box_type_from_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  Um box type
 *****************************************************************************/
U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_box_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(mma_get_box(msg_id));
    return msg_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dummy_entry_function
 * DESCRIPTION
 *  Use This for replacing NULL entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dummy_entry_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_show_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_show_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowStatusIcon(icon_id);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_hide_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_hide_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HideStatusIcon(icon_id);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_blink_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_blink_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BlinkStatusIcon(icon_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_start_uc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_start_uc(mmi_umms_start_uc_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_uc_start_struct *req;
    mma_result_enum uc_error;
    MMI_ID parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_uc_start_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_uc_start_struct));
    ASSERT(req);
    memset(req, 0, sizeof(mmi_uc_start_struct));
    req->app_id = MMA_APP_ID_MMS_APP;
    req->mode = para->uc_mode;
#ifdef __MMI_MMS_DUAL_SIM__
    req->sim_id = srv_mms_convert_to_uc_sim_id(para->sim_id);
#else 
    req->sim_id = 0;
#endif 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    req->curr_storage = para->storage_type;
#else 
    req->curr_storage = 0;
#endif 

    req->edit_mode = para->edit_mode;
    req->msg_id = para->msg_id;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DUMMY_SCR);

    /* uc_error = (mma_result_enum) mmi_uc_launch(req); */
    parent_id = mmi_umms_dtmgr_check_tenplate_group_flag() ==
        MMI_TRUE ? mmi_umms_app_dtmgr_get_um_back_up_id() : mmi_umms_app_dtmgr_get_parent_grp_id();
    if (parent_id == GRP_ID_INVALID)
    {
        parent_id = GRP_ID_ROOT;
    }

    // mmi_frm_group_create(parent_id, APP_UMMS_MMS, mmi_umms_cui_event_handler_edit_mms_group_proc, NULL);
    //mmi_frm_group_enter(APP_UMMS_MMS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    uc_error = (mma_result_enum) cui_uc_write_msg_from_mms_launch(parent_id, req);

    if (uc_error != MMA_RESULT_OK)
    {
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&uc_error);
    }
    srv_mms_mem_mgr_app_adm_free(req);

    return;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr
 * DESCRIPTION
 *  Start UC in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  content_source      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr(char *content_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        data.file_path = (kal_uint8*) content_source;
        data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &data);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) content_source;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr_with_callback
 * DESCRIPTION
 *  Start MMS editor with the specified content. A callback function is provided so that MMS editor
 *  can evoke the function when work is done.
 * CALLS
 *  
 * PARAMETERS
 *  entry_data      [?]         
 *  data(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr_with_callback(mms_content_entry_struct *entry_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        data.file_path = (kal_uint8*) entry_data->file_path;
        data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        data.callback = entry_data->callback;
        data.callback_para = entry_data->callback_param;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) entry_data->file_path;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.callback = entry_data->callback;
        data.callback_para = entry_data->callback_param;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_text_insert_hdlr
 * DESCRIPTION
 *  Start UC in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  subject                 [?]         
 *  subject_len             [IN]        
 *  text                    [?]         
 *  text_len                [IN]        
 *  content_source(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_text_insert_hdlr(char *subject, unsigned int subject_len, char *text, unsigned int text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        data.subject = (kal_uint8*) subject;
        data.text_buffer = (kal_uint8*) text;
        data.text_num = text_len;
        data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.subject = (kal_uint8*) subject;
        data.text_buffer = (kal_uint8*) text;
        data.text_num = text_len;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr
 * DESCRIPTION
 *  Start MEA in editor with a address inserted
 * CALLS
 *  
 * PARAMETERS
 *  address                 [?]         
 *  content_source(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_address_insert_hdlr(char *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct data;
        mma_mms_addr_list_struct addr;

        memset(&data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mma_mms_addr_list_struct));
        data.addr_num = 1;
        addr.address = (kal_char*) address;
        if ((mmi_ucs2chr(address, L'@')) == NULL)
        {
            addr.addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.addr_type = MMA_ADDR_TYPE_EMAIL;
        }
        addr.group = MMA_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &data);
    }

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct data;
        mmi_uc_addr_struct addr;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
        data.addr_num = 1;
        addr.addr = (kal_char*) address;
        if ((mmi_ucs2chr(address, L'@')) == NULL)
        {
            addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }
        addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr_with_callback
 * DESCRIPTION
 *  This function is used by MMI application, ex: Phonebook, to start MMS composer for more than one To addresses.  Caller should provide the callback functon to get the addresses one by one.
 * PARAMETERS
 *  addr_count                  [IN]        
 *  get_address_callback        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_address_insert_hdlr_with_callback(kal_uint8 addr_count, void *get_address_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        data.addr_num = (U8) addr_count;
        data.addr = NULL;
        data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        data.get_address_callback = (uc_func_ptr_general_insert_get_addr_fn) get_address_callback;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &data);
        return;
    }

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));

        data.addr_num = (U8) addr_count;
        data.addr = NULL;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.get_address_callback = (uc_func_ptr_general_insert_get_addr_fn) get_address_callback;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_general_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  data        [IN]        The mms_content_entry_struct data
 * RETURNS
 *  void
 *****************************************************************************/
void mms_general_insert_hdlr(mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        mmi_umms_uc_entry_write_struct uc_data;
        mma_mms_addr_list_struct addr;

        memset(&uc_data, 0x00, sizeof(mmi_umms_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mma_mms_addr_list_struct));

        uc_data.callback = data->callback;
        uc_data.callback_para = data->callback_param;
        uc_data.subject = (kal_uint8*) data->subject;
        uc_data.text_buffer = (kal_uint8*) data->text_buffer;
        uc_data.text_num = mmi_ucs2strlen(data->text_buffer);
        uc_data.file_path = (kal_uint8*) data->file_path;
        uc_data.get_address_callback = NULL;
        if (data->addr != NULL)
        {
            uc_data.addr_num = 1;
            addr.address = (kal_char*) data->addr;
            if (mmi_ucs2chr(data->addr, L'@') == NULL)
            {
                addr.addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
            }
            else
            {
                addr.addr_type = MMA_ADDR_TYPE_EMAIL;
            }
            addr.group = MMA_ADDRESS_GROUP_TYPE_TO;
            uc_data.addr = &addr;
        }
        uc_data.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
        uc_data.info_type = SRV_MMS_UC_INFO_TYPE_MMS;
        mmi_umms_uc_entry_write_msg_with_content(SRV_MMS_STATE_WRITE_NEW_MSG, &uc_data);
        return;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {
        mmi_uc_entry_write_struct uc_data;
        mmi_uc_addr_struct addr;

        memset(&uc_data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));

        uc_data.callback = data->callback;
        uc_data.callback_para = data->callback_param;
        uc_data.subject = (kal_uint8*) data->subject;
        uc_data.text_buffer = (kal_uint8*) data->text_buffer;
        uc_data.text_num = mmi_ucs2strlen(data->text_buffer);
        uc_data.file_path = (kal_uint8*) data->file_path;
        uc_data.get_address_callback = NULL;
        if (data->addr != NULL)
        {
            uc_data.addr_num = 1;
            addr.addr = (kal_char*) data->addr;
            if (mmi_ucs2chr(data->addr, L'@') == NULL)
            {
                addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else
            {
                addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
            }
            addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            uc_data.addr = &addr;
        }
        uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;

        if (data->msg_type == MMS_MSG_TYPE_POSTCARD)
        {
            uc_data.info_type = MMI_UC_INFO_TYPE_POSTCARD_MMS;
        }
        else
        {
            uc_data.info_type = MMI_UC_INFO_TYPE_MMS;
        }
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_data);
        return;
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
}

#ifdef __MMI_MMS_IN_UM__


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_setting
 * DESCRIPTION
 *  This function is to enter MMS setting screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_2__)
    mmi_umms_app_if_show_message_settings_menu();
#endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_template
 * DESCRIPTION
 *  This function is to enter MMS template list screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_TEMPLATE_SUPPORT__)
    mmi_umms_app_if_show_template_menu();
#endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_write_msg
 * DESCRIPTION
 *  This function is to enter MMS editor screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_msg
 * DESCRIPTION
 *  This function is to enter MMS reading (player) screen by specifying MMS folder and index in that folder
 * CALLS
 *  
 * PARAMETERS
 *  um_req              [?]         
 *  msg_index(?)        [IN]        
 *  msg_box_type(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 mms_um_entry_msg(void *um_req)
{
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_entry_event_struct evt = {0, };
    mmi_um_opt_para_struct para = {0, };
    mmi_um_entry_msg_struct *msg_data = (mmi_um_entry_msg_struct*) um_req;
	#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_um_entry_msg_struct *entry_msg_param = (mmi_um_entry_msg_struct*) um_req;
#endif
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.evt_id = EVT_ID_ON_KEY;
    evt.msg_data = um_req;
    para.msg_id = msg_data->msg_id;
    para.parent_grp_id = msg_data->parent_grp_id;
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && mma_is_storage_exported_to_pc())   /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        return KAL_TRUE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    result = umms_cb_hdlr((mmi_event_struct*) & evt, &para);
    if (result == MMI_RET_OK)
    {
        return mmi_umms_dtmgr_get_group_id();
    }
	else
	{
		return KAL_FALSE;
	}
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return mmi_umms_app_interface_entry_from_um(
            entry_msg_param->key_code,
            entry_msg_param->msg_id,
            entry_msg_param->user_data,
            entry_msg_param->parent_grp_id);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#endif /* __COSMOS_MMI_PACKAGE__ */ 
}
#endif /* __MMI_MMS_IN_UM__ */ 

/* This Proc Function will handle all Events */
/* Any Event which has to be consumed by MMS must be handled here only */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_common_proc
 * DESCRIPTION
 *  This Proc Function will handle all Events
 *  Any Event which has to be consumed by MMS must be handled here only
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_umms_common_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_if_cui_launch_from_widjet
 * DESCRIPTION
 *  This function is to find if msg viewer cui will be launched 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE: 
 *  MMI_FALSE : 
 *****************************************************************************/
MMI_BOOL mmi_umms_if_cui_launch_from_widjet(U32 msg_id ,cui_msg_viewer_type_enum view_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      U8 msg_type = mma_get_mms_msg_type(msg_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	  if(view_type == CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD)
	  {
	  switch(msg_type)
	  {
	  case MMA_MSG_TYPE_NOTIFICATION :
	  case MMA_MSG_TYPE_DELIVERY_REPORT :
	  case MMA_MSG_TYPE_JAVA :
		  return MMI_FALSE ;
	  default :return MMI_TRUE;

      }
	  }
	  else if(view_type == CUI_MSG_VIEWER_TYPE_CSK_KEY)
	  {
         return MMI_TRUE;
	  }
	  else
	  {
         MMI_ASSERT(0);
		 return MMI_FALSE;
	  }
}
#endif /* __MMI_MMS_2__ */ 

