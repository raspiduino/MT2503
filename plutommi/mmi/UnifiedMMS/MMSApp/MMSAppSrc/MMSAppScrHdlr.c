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
 * MMSAppScrHdlr.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

// #include "CallManagementGprot.h"
#include "MMSAppUICommon.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSAppInterfaceGProt.h"
#include "MMSAppInterfaceProt.h"
#include "MMSAppScrHdlr.h"
#include "MMSAppUIPlugin.h"
#include "MMSAppUICallback.h"
#include "MMSAppComposerUILE.h"
#include "MmsContextSrvLE.h"
// #include "MMSAppUIdrawEx.h"
#include "MMSAppScrHdlrEx.h"
#include "MMSAppResourceDB.h"
#include "inlineCuiGprot.h"
#include "MMSAppUIdraw.h"
#include "MMSAppDataManager.h"
#include "MmsSrvGprot.h"
//#include "UnifiedMessageResDef.h"
//#include "CommonScreens.h"
#include "MMSAppUtil.h"
#include "MMSAppSrvHdlr.h"
#include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
//#include "MessagesResourceData.h"
//#include "UCMGProt.h"
//#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "MmsSrvProt.h"
// #include "MenuCuiGprot.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mma_api.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "mmi_frm_gestures_gprot.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "UmSrvGprot.h"
#include "mmi_rp_app_sms_def.h"
#include "UmSrvDefs.h"
#include "string.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "gui_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "tcm_common.h"
#include "wgui_categories_MMS_viewer.h"
#include "app_usedetails.h"
// #include "SimDetectionStruct.h"
#include "WAPProfileSrvGProt.h"
#include "WAPProfileSrvType.h"
#include "gui_data_types.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
// #include "app_buff_alloc.h"
#include "UMGProt.h"
#include "mmi_rp_srv_mms_def.h"
#include "mmi_frm_timer_gprot.h"
#include "mma_struct.h"


extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_template_grp_proc_func(mmi_event_struct *evt);
extern void srv_mms_set_attachment_list_hilighted_item(S32 index);

/* extern mmi_umms_app_dtmgr_inline_settings_struct *g_umms_context; */

mmi_umms_app_sh_context g_sh_cntx[MMI_UMMS_APP_SH_MAX_CNTX];

/* U8 g_signature_current_highlighted = 0; */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_init_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_init_function(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_screenDB_struct *ScrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    MMI_UMMS_ERROR ret = MMI_UMMS_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == 0)
    {
        return MMI_UMMS_FALSE;
    }

    if (ScrDB == NULL)
    {
        return MMI_UMMS_FALSE;
    }

    if (ScrDB->create_func)
    {
        ScrDB->create_func(scr_id);
    }

    if (ScrDB->pre_func)
    {
        if (ScrDB->pre_func(scr_id) == MMI_UMMS_FAIL)
        {
            return MMI_UMMS_FALSE;
        }
    }

    if (ScrDB->draw_func)
    {
        ret = ScrDB->draw_func(scr_id);
    }

    if (ret == MMI_UMMS_TRUE && ScrDB->post_func)
    {
        ScrDB->post_func(scr_id);
    }

    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_option_screen(U8 folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 activeScr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activeScr = mmi_frm_scrn_get_active_id();

    switch ( /* mmi_umms_convert_umbox_type_to_mma_folder */ (folder_id))
    {
        case MMA_FOLDER_INBOX:
            if (activeScr == SCR_ID_UMMS_INBOX_MMS_OPTION || activeScr == SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION
                || activeScr == SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION || activeScr == SCR_ID_UMMS_JAVA_OPTIONS)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_JAVA_OPTIONS);
            break;
        case MMA_FOLDER_OUTBOX:
            if (activeScr == SCR_ID_UMMS_OUTBOX_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OUTBOX_OPTION);
            break;
        case MMA_FOLDER_SENT:
            if (activeScr == SCR_ID_UMMS_SENT_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
            break;
        case MMA_FOLDER_DRAFT:
            if (activeScr == SCR_ID_UMMS_DRAFT_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            if (activeScr == SCR_ID_UMMS_ARCHIVE_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_ARCHIVE_OPTION);

            if (activeScr == SCR_ID_UMMS_INBOX_MMS_OPTION || activeScr == SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION
                || activeScr == SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION || activeScr == SCR_ID_UMMS_JAVA_OPTIONS)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);

            if (activeScr == SCR_ID_UMMS_SENT_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
            if (activeScr == SCR_ID_UMMS_DRAFT_OPTION)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);

            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_TEMPLATE:
            if (activeScr == SCR_ID_UMMS_TEMPLATES_OPTIONS)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_OPTIONS);
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            if (activeScr == SCR_ID_UMMS_TEMPLATES_OPTIONS)
            {
                mmi_umms_app_ui_draw_dummy_screen();
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_OPTIONS);
            break;
        #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_create_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_create_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If we delete last screen of the group than the group will automatically deleted, 
       so at that time we reset the group_flag .
       That's why in this case if the flag is not set 
       (i.e group is already deleted) than we create group again */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

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
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_template_create_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_template_create_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If we delete last screen of the group than the group will automatically deleted, 
       so at that time we reset the group_flag .
       That's why in this case if the flag is not set 
       (i.e group is already deleted) than we create group again */
    mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
    if (mmi_umms_dtmgr_check_tenplate_group_flag() == MMI_FALSE)
    {
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
        if (GRP_ID_INVALID == mmi_umms_app_dtmgr_get_parent_grp_id())
        {
            mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
        }
        mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
        mmi_umms_dtmgr_set_tenplate_group_flag(MMI_TRUE);
        mmi_frm_group_create_ex(
            mmi_umms_app_dtmgr_get_parent_grp_id(),
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_template_grp_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    }
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_create_popup_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_create_popup_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_dummy_history_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_dummy_history_func(void *arg)
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
 *  mmi_umms_app_sh_mms_option_mms_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 *  sender_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_mms_handler(U16 hilite_menu, U16 sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_mms_option_handling(hilite_menu, sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_static_list_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_static_list_rsk_handler(void)
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
 *  mmi_umms_app_sh_dynamic_list_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_dynamic_list_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_sh_delete_screen_context(scrDB->scrn_id);
    }
    return MMI_RET_OK;
}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_recipient_list_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_show_recipient_list_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;
    U16 scrn_id = scrDB->scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_ui_draw_dynamic_screen_struct *dynamic_scr =
            (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
        if (dynamic_scr->scrDB->RObj)
        {
            srv_mms_mem_mgr_app_adm_free(dynamic_scr->scrDB->RObj);
            dynamic_scr->scrDB->RObj = NULL;
        }
        if (dynamic_scr->scrDB)
        {
            srv_mms_mem_mgr_app_adm_free(dynamic_scr->scrDB);
            dynamic_scr->scrDB = NULL;
        }
        mmi_umms_app_sh_delete_screen_context(scrn_id);
    }
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_details_list_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_use_details_list_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_ui_plug_in_reset_use_details_list_data(scrDB->scrn_id);
        mmi_umms_app_sh_delete_screen_context(scrDB->scrn_id);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_sim_option_mms_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sim_option_mms_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
#endif /* __MMI_FTE_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if (info && info->msg_info )
#endif 
    {
        mmi_umms_app_ui_plug_in_sim_option_handling(hilite_menu, 0);
    }
#ifdef __MMI_FTE_SUPPORT__
    else
    {
    
        switch (hilite_menu)
        {
            #if( (MMI_MAX_SIM_NUM == 2) || ((MMI_MAX_SIM_NUM >= 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)))
            case MENU_ID_UMMS_FROM_SIM1:
            {
                srv_mms_set_selected_sim_id((U8) MMI_SIM1);
            }
                break;
            case MENU_ID_UMMS_FROM_SIM2:
            {
                srv_mms_set_selected_sim_id((U8) MMI_SIM2);
            }
                break;
            #endif /* (MMI_MAX_SIM_NUM == 2) */ /* __MMI_MMS_DUAL_SIM__ */
            default:
                break;
        }
    
        mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list();
    }
#endif /* __MMI_FTE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_read_delivery_report_view_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_read_delivery_report_view_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_if_show_inbox_read_delivery_option();
}

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_abnormal_view_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_abnormal_view_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_abnormal_screen_option();
}
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_read_delivery_report_view_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_read_delivery_report_view_rsk_handler(void)
{
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_add_to_phb_list_and_deinit_umms();
#else /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
    mmi_umms_app_core_deinit_viewer_and_globals_and_go_to_box_list();
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_dynamic_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_dynamic_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_dynamic_screen_struct *dynamic_scr;
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_scr = (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    ASSERT(dynamic_scr);
    dynamic_scr->hilighted_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_progress_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_progress_screen_exit_func(void)
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
 *  mmi_umms_app_sh_progress_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_progress_delete_screen(mmi_event_struct *data)
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
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_sh_delete_screen_context(scr_id);
    }
    return MMI_RET_OK;
}

/* MMI_UMMS_ERROR mmi_umms_app_sh_prop_mms_options_handling(U16 hilite_menu, U16 scr_id) */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_options_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_options_exit_func(void)
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
 *  mmi_umms_app_sh_read_delivery_report_view_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_read_delivery_report_view_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_confirm_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_confirm_screen_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_sort_by_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sort_by_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_static_screen_struct *static_scr;

    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static_scr = (mmi_umms_app_ui_draw_static_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_SORT_BY_OPTION_TO_UM, static_scr->hilighted_item);
    mmi_um_set_message_list_sort_type((U16) static_scr->hilighted_item);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_JAVA_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OUTBOX_OPTION);
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED);
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    mmi_umms_app_sh_delete_umms_screens();
    mmi_frm_scrn_close_active_id();
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_popup_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_popup_screen_exit_func(void)
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
 *  mmi_umms_app_sh_get_scr_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_sh_get_scr_context(U16 scrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_UMMS_APP_SH_MAX_CNTX; index++)
    {
        if (g_sh_cntx[index].scr_id == scrId)
        {
            return g_sh_cntx[index].sh_data;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_set_screen_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrId       [IN]        
 *  data        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_set_screen_context(U16 scrId, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_UMMS_APP_SH_MAX_CNTX; index++)
    {
        if (g_sh_cntx[index].scr_id == 0)
        {
            break;
        }
    }
    ASSERT(g_sh_cntx[index].scr_id == 0);
    g_sh_cntx[index].scr_id = scrId;
    g_sh_cntx[index].sh_data = data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_delete_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_delete_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* srv_mms_delete_req_struct req; */
    srv_mms_bgsr_msg_box_enum bgsr_folder_id = SRV_MMS_BGSR_FOLDER_NONE;
    mmi_umms_app_dtmgr_option_scr_data_struct *info;
    U8 error = 0;
    U8 srv_result = 0;

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
    mmi_um_iter_viewer_result_struct other_msg_data;
    U8 folder_id;
    void *um_data = NULL;
    mmi_id parent_id;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(
       MMI_INET_TRC_G6_MMS,
       MMI_UMMS_DONT_SEND_READ_REPORT,
       g_current_mms_info_list->current_msg_id,
       g_current_mms_info_list->folder_id); */

    info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    bgsr_folder_id = mmi_umms_app_util_mma_folder_to_bgsr_folder(info->folder_id);
    switch (info->folder_id)
    {
        case MMA_FOLDER_OUTBOX:
        case MMA_FOLDER_INBOX:
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SEND_BGSR_CHANGE_NOTIFY, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                info->msg_id,
                SRV_MMS_BGSR_OP_DELETE,
                bgsr_folder_id,
                mmi_umms_app_core_delete_msg_notify_callback,
                info->msg_info->msg_storage);
            break;
    #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
        case MMA_FOLDER_REPORT_BOX:
        {
            srv_result = srv_mms_delete_report_msg(info->msg_id, &error);
            if (srv_result != SRV_MMS_RESULT_OK)
            {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                mmi_umms_app_sh_delete_umms_screens();
                return;
            }
            else
            {
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
                mmi_umms_app_sh_delete_umms_screens();
            }
            break;
        }
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
        case MMA_FOLDER_ARCHIVE:
            if (info->msg_info->prev_folder == MMA_FOLDER_INBOX)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SEND_BGSR_CHANGE_NOTIFY, bgsr_folder_id);
                srv_mms_bgsr_change_msg_notify(
                    info->msg_id,
                    SRV_MMS_BGSR_OP_DELETE,
                    bgsr_folder_id,
                    mmi_umms_app_core_delete_msg_notify_callback,
                    info->msg_info->msg_storage);
                break;
            }

        #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_USRDEF_TEMPLATE:
        case MMA_FOLDER_TEMPLATE:
            mmi_umms_app_dtmgr_reset_template_list_data();
        #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        default:
            srv_result = srv_mms_delete_msg(info->msg_id, &error);

            if (srv_result != SRV_MMS_RESULT_OK)
            {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                mmi_umms_app_sh_delete_umms_screens();
                return;
            }
            if (error == MMA_RESULT_OK)
            {
            #ifndef __MMI_BACKGROUND_CALL__
                // if (!mmi_umms_is_in_call())
                // {
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
                /* } */
            #else /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
            #endif /* __MMI_BACKGROUND_CALL__ */ 
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
                parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
                mmi_umms_app_sh_delete_umms_screens();
                srv_mms_show_status_icon();
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                if (ret_val == MMI_UMMS_TRUE)
                {
                    mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data, parent_id);
                }
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(error);
                mmi_umms_app_sh_delete_umms_screens();
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_delete_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_delete_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_reset_data();
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_warning_object_signature_confirm_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_warning_object_signature_confirm_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_reset_buffer_for_signature();
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_screen_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_screen_context(U16 scrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    MMI_BOOL scr_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < 10; index++)
    {
        if (g_sh_cntx[index].scr_id == scrId)
        {
            scr_found = MMI_TRUE;
            break;
        }
    }
    if (scr_found == MMI_FALSE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SH_SCREEN_NOT_FOUND);
        return;
    }
    g_sh_cntx[index].scr_id = 0;
    if (g_sh_cntx[index].sh_data != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_sh_cntx[index].sh_data);
        g_sh_cntx[index].sh_data = NULL;
    }
}

/* ----------------------------Niraj---------------------------------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_message_settings_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_message_settings_menu_exit_func(void)
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
 *  mmi_umms_app_sh_mms_message_settings_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_message_settings_menu_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_user_template_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_user_template_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_reset_template_list_data();
    mmi_frm_scrn_close_active_id();
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_get_dynamic_list_hilighted_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_sh_get_dynamic_list_hilighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_static_screen_struct *static_scr;
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static_scr = (mmi_umms_app_ui_draw_static_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    ASSERT(static_scr);
    return static_scr->hilighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_delete_all_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_delete_all_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_all_ind_struct req;
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    srv_um_box_identity_struct data;
#endif
    srv_mms_bgsr_msg_box_enum bgsr_folder_id = SRV_MMS_BGSR_FOLDER_NONE;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DELTE_ALL, info->folder_id);

    bgsr_folder_id = mmi_umms_app_util_mma_folder_to_bgsr_folder(info->folder_id);
    /* if (mmi_frm_scrn_get_active_id() != SCR_ID_UMMS_PROGRESS)
       {
       mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_DELETING);
       mmi_umms_app_if_show_progress_screen();
       } */
    switch (info->folder_id)
    {
        case MMA_FOLDER_OUTBOX:
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_BGSR_MSG_NOTIFY_FOR_DELTE_ALL_OUTBOX, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                info->msg_id,
                SRV_MMS_BGSR_OP_DELETE_ALL_OUTBOX,
                bgsr_folder_id,
                mmi_umms_app_core_delete_all_msg_notify_callback,
                info->msg_info->msg_storage);
            break;
        case MMA_FOLDER_INBOX:
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_BGSR_MSG_NOTIFY_FOR_DELTE_ALL_INBOX, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                info->msg_id,
                SRV_MMS_BGSR_OP_DELETE_ALL_INBOX,
                bgsr_folder_id,
                mmi_umms_app_core_delete_all_msg_notify_callback,
                info->msg_info->msg_storage);
            break;
        case MMA_FOLDER_ARCHIVE:
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_BGSR_MSG_NOTIFY_FOR_DELTE_ALL_ARCHIVE, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                info->msg_id,
                SRV_MMS_BGSR_OP_DELETE_ALL_ARCHIVE,
                bgsr_folder_id,
                mmi_umms_app_core_delete_all_msg_notify_callback,
                info->msg_info->msg_storage);
            break;
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_USRDEF_TEMPLATE:
            mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_DELETING);
            mmi_umms_app_if_show_progress_screen();
            mmi_umms_app_sh_delete_umms_screens();
            mmi_umms_app_dtmgr_reset_template_list_data();

            data.msg_type = SRV_UM_MSG_MMS; /* the message type in box */
            data.msg_box_type = SRV_UM_MSG_BOX_USRDEF_TEMPLATES;        /* the type of box */
            data.sim_id = SRV_UM_SIM_GSM_SIM1;
            srv_um_delete_folder(data, mmi_umms_app_core_um_delete_folder_callback, 0);
            break;
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        default:

            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DUMMY_SCR);

            memset(&req, 0, sizeof(srv_mms_delete_all_ind_struct));
            req.user_data = 0;
            req.call_back = mmi_umms_app_core_delete_all_msg_callback;
            req.msg_type = SRV_UM_MSG_MMS;
            req.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(info->folder_id);

            srv_mms_delete_all(&req);
            /* if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
               {
               mmi_umms_app_ui_draw_dummy_screen();
               }
               mmi_umms_app_sh_delete_progress_screen(); */
            mmi_umms_app_sh_go_to_box_list_screen();

            break;
    }

}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_option_slim_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_option_slim_menu_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_template_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_template_menu_exit_func(void)
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
 *  mmi_umms_app_sh_mms_template_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_template_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_handle_mms_template_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_user_template_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_user_template_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_default_template_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_default_template_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 icon_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_current_message_index(index);
    icon_id = mmi_umms_app_dtmgr_get_template_list_csk_icon_id();
    
    ChangeCenterSoftkey(0, icon_id)
    if (icon_id)
    {
        SetCenterSoftkeyFunction(mmi_umms_app_ui_plug_in_template_view_by_csk, KEY_EVENT_UP);
        /* SetKeyHandler(mmi_umms_app_ui_plug_in_template_view_by_csk, KEY_CSK, KEY_EVENT_UP); */
    }
    else
    {
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        /* SetKeyHandler(NULL, KEY_CSK, KEY_EVENT_UP); */
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_userdef_template_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_userdef_template_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 icon_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_current_message_index(index);
    
    icon_id = mmi_umms_app_dtmgr_get_template_list_csk_icon_id();
    ChangeCenterSoftkey(0, icon_id);
    if (icon_id)
    {
        SetCenterSoftkeyFunction(mmi_umms_app_ui_plug_in_template_view_by_csk, KEY_EVENT_UP);
        /* SetKeyHandler(mmi_umms_app_ui_plug_in_template_view_by_csk, KEY_CSK, KEY_EVENT_UP); */
    }
    else
    {
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        /* SetKeyHandler(NULL, KEY_CSK, KEY_EVENT_UP); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_userdef_template_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_userdef_template_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_dtmgr_reset_template_list_data();
        mmi_umms_app_sh_delete_screen_context(scrDB->scrn_id);
    }
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_compose_settings_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_settings_rsk_handler(void)
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
 *  mmi_umms_app_sh_compose_settings_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_settings_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 change_in_signature = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_in_signature = mmi_umms_app_ui_plug_in_get_change_in_compose_signature();

    if (index == E_COMPOSE_DEFAULT_SLIDE_TIME)
    {
        cui_inline_set_softkey_icon(mmi_umms_dtmgr_get_inline_gid(), index, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    }
#ifdef __MMI_MMS_SIGNATURE__
    if (index == E_COMPOSE_AUTO_SIGNATURE_CONTENT)
    {
        /*ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_umms_compose_settings_signature_selection_lsk_handler, KEY_EVENT_UP);*/

        cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);

        wgui_inline_set_lsk_function(mmi_umms_compose_settings_signature_selection_lsk_handler);
        cui_inline_set_softkey_icon(mmi_umms_dtmgr_get_inline_gid(), index, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    }
#endif /* __MMI_MMS_SIGNATURE__ */ 
    if (change_in_signature == E_ON)
    {
        cui_inline_set_screen_attributes(
            mmi_umms_dtmgr_get_inline_gid(),
            CUI_INLINE_SET_ATTRIBUTE,
            CUI_INLINE_SCREEN_CHANGED);
        //ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        //SetRightSoftkeyFunction(mmi_umms_app_ui_plug_in_confirm_save_compose_settings, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_compose_settings_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_settings_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_inline_selection_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_inline_selection_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id = *((U16*) (data->user_data));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_read_nvarm_compose_settings();
    mmi_umms_app_reset_buffer_for_signature();
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (mmi_umms_app_dtmgr_get_signature_audio_disp_path() != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(mmi_umms_app_dtmgr_get_signature_audio_disp_path());
        mmi_umms_app_dtmgr_set_signature_audio_disp_path(NULL);
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
    mmi_umms_app_sh_delete_screen_context(scrn_id);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_new_notification_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_new_notification_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_infinite_popup_screen_struct *data =
        (mmi_umms_app_dtmgr_infinite_popup_screen_struct*) mmi_umms_app_dtmgr_get_infinite_popup_screen_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->tone_id)

    {
        srv_prof_stop_tone((srv_prof_tone_enum) data->tone_id);
        data->tone_id = 0;
        if (mmi_umms_app_core_get_backgroundaudioresume())
        {
            mdi_audio_resume_background_play();
            mmi_umms_app_core_set_backgroundaudioresume(MMI_FALSE);
        }
    }
    /* active goback subLCD history to return the previous screen */
    GoBackSubLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_full_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_full_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_infinite_popup_screen_struct *data =
        (mmi_umms_app_dtmgr_infinite_popup_screen_struct*) mmi_umms_app_dtmgr_get_infinite_popup_screen_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->tone_id)
    {
        srv_prof_stop_tone((srv_prof_tone_enum) data->tone_id);
        data->tone_id = 0;
    }
}

/* ---------------------retrieval settings------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_retrieval_settings_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_retrieval_settings_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_retrieval_settings_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_retrieval_settings_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_app_dtmgr_get_recieve_filters_done() == E_ON)
    {
        mmi_umms_app_ui_plug_in_confirm_save_retrieval_settings();
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}

#if(MMI_MAX_SIM_NUM == 2)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_sim_options_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sim_options_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* (MMI_MAX_SIM_NUM == 2) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_retrieval_settings_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_retrieval_settings_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == (E_RETRIEVAL_FILTERS_CAPTION))
    {
        /*ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_umms_retrieval_settings_filter_selection_lsk_handler, KEY_EVENT_UP);*/

        cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);

        wgui_inline_set_lsk_function(mmi_umms_retrieval_settings_filter_selection_lsk_handler);
        cui_inline_set_softkey_icon(mmi_umms_dtmgr_get_inline_gid(), index, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    }
    if (mmi_umms_get_app_ui_plug_in_change_in_filters() == MMI_TRUE)
    {
        cui_inline_set_screen_attributes(
            mmi_umms_dtmgr_get_inline_gid(),
            CUI_INLINE_SET_ATTRIBUTE,
            CUI_INLINE_SCREEN_CHANGED);
        //ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        //SetRightSoftkeyFunction(mmi_umms_app_ui_plug_in_confirm_save_retrieval_settings, KEY_EVENT_UP);
    }

    /* mmi_umms_set_key_handler_according_to_scrn_id(scrDB->scrn_id,MMI_UMMS_APRNC_TYPE_INLINE_SELECTION_LIST); */
}

/***************compose signature settings**********/
#ifdef __MMI_MMS_SIGNATURE__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_compose_signature_settings_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_signature_settings_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    if ((compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
            {
             #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_IMAGE, CUI_INLINE_SET_ATTRIBUTE,  CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
             #endif
             #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_AUDIO, CUI_INLINE_SET_ATTRIBUTE,  CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
             #endif
            }
    else if ((compose_settings_inline_items->signature_flag &
                 UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED)
                || (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED))
            {
             #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_VIDEO, CUI_INLINE_SET_ATTRIBUTE,  CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
             #endif
            }
    else
            {
             #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_IMAGE, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW );
             #endif
             #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_AUDIO, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW );
             #endif
             #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
                cui_inline_set_item_attributes(mmi_umms_dtmgr_get_inline_gid_ext(), E_COMPOSE_SIGNATURE_VIDEO, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW );
             #endif
            }
    switch (index)
    {
        case E_COMPOSE_SIGNATURE_TEXT:
            /*EnableLeftSoftkey(STR_GLOBAL_EDIT, 0);
            ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);*/

            //cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_EDIT);
            
            break;
    #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        case E_COMPOSE_SIGNATURE_IMAGE:
            if ((compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
            {
                /*DisableLeftSoftkey(STR_GLOBAL_OK, 0);
                ResetCenterSoftkey();
                cui_inline_set_softkey_icon(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_CENTER_SOFTKEY, 0);*/
                cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, CUI_INLINE_SOFTKEY_DEFAULT_VALUE);
                return;
            }
            /*EnableLeftSoftkey(STR_GLOBAL_OK, 0);
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);*/
            cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
            cui_inline_set_softkey_icon(
                mmi_umms_dtmgr_get_inline_gid_ext(),
                index,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature(E_COMPOSE_SIGNATURE_IMAGE);

            
            break;
    #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        case E_COMPOSE_SIGNATURE_AUDIO:
            if ((compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
            {
                cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, CUI_INLINE_SOFTKEY_DEFAULT_VALUE);
                return;
            }
            /*EnableLeftSoftkey(STR_GLOBAL_OK, 0);
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);*/
            cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
            cui_inline_set_softkey_icon(
                mmi_umms_dtmgr_get_inline_gid_ext(),
                index,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature(E_COMPOSE_SIGNATURE_AUDIO);

            
            break;
        #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        case E_COMPOSE_SIGNATURE_VIDEO:
            if ((compose_settings_inline_items->signature_flag &
                 UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED)
                || (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED))
            {
                cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, CUI_INLINE_SOFTKEY_DEFAULT_VALUE);
                return;
            }
            /*EnableLeftSoftkey(STR_GLOBAL_OK, 0);
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);*/

            cui_inline_set_softkey_text(mmi_umms_dtmgr_get_inline_gid_ext(), index, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
            cui_inline_set_softkey_icon(
                mmi_umms_dtmgr_get_inline_gid_ext(),
                index,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature(E_COMPOSE_SIGNATURE_VIDEO);

            

            break;
        #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
    }


    wgui_inline_set_lsk_function(mmi_umms_app_sh_compose_signature_settings_lsk_handler);

    /* mmi_umms_set_key_handler_according_to_scrn_id(scrDB->scrn_id,MMI_UMMS_APRNC_TYPE_INLINE_SELECTION_LIST); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_compose_signature_settings_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_signature_settings_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(SCR_ID_UMMS_COMPOSE_IMAGE_OPTION);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_umms_compose_signature_pre_option_menu();
    //return;
    if (scrDB != NULL)
    {
        scrDB->EntryFunction();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_compose_signature_settings_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_signature_settings_rsk_handler(void)
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
 *  mmi_umms_app_sh_compose_signature_settings_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_compose_signature_settings_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);

}
#endif/*ifdef __MMI_MMS_SIGNATURE__*/

/********retrieval filter settings*********/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_retrieval_filters_settings_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_retrieval_filters_settings_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);

}

/**************sending settings***********/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_sending_settings_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sending_settings_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
}

/************************signature options*******************/
#ifdef __MMI_MMS_SIGNATURE__
extern void mmi_umms_compose_select_from_file_manager(void);
extern void mmi_umms_pre_entry_compose_reference_delete(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_signature_options_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_signature_options_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_SIGNATURE_OPTION_SELECT:
            mmi_umms_compose_select_from_file_manager();
            break;
        case MENU_ID_UMMS_SIGNATURE_OPTION_DELETE:
            mmi_umms_pre_entry_compose_reference_delete();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_signature_options_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_signature_options_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif/*ifdef __MMI_MMS_SIGNATURE__*/

/* void mmi_umms_app_sh_signature_options_hilite_handler(S32 index)
   {
   mmi_umms_app_ui_draw_static_screen_struct* static_scr;
   mmi_umms_app_screenDB_struct* scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
   static_scr = (mmi_umms_app_ui_draw_static_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
   static_scr->hilighted_item = index;
   } */

/*****************************************Amit added*****************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_memory_status_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_memory_status_exit_func(void)
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
 *  mmi_umms_app_sh_property_status_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_property_status_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info && info->is_already_viewed == MMI_FALSE)
    {
        mmi_umms_app_dtmgr_reset_data();
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_property_status_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_property_status_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U16 scrn_id = scrDB->scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        if (scrDB)
        {
            if (scrDB->RObj)
            {
                srv_mms_mem_mgr_app_adm_free(scrDB->RObj);
                scrDB->RObj = NULL;
            }
            srv_mms_mem_mgr_app_adm_free(scrDB);
            scrDB = NULL;
        }
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        mmi_umms_app_sh_delete_screen_context(scrn_id);
        switch (scrn_id)
        {
            case SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES:
            case SCR_ID_UMMS_MESSAGE_STATUS:
                if (info && info->is_already_viewed == MMI_FALSE &&
                    !mmi_frm_scrn_is_present(
                        mmi_umms_dtmgr_get_group_id(),
                        SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
                        MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    mmi_umms_app_dtmgr_reset_data();
                }
                break;

            #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
            case SCR_ID_UMMS_MMS_DELIVERY_STATUS:
            case SCR_ID_UMMS_MMS_READ_STATUS:
                if (info && info->is_already_viewed == MMI_FALSE)
                {
                    mmi_umms_app_dtmgr_reset_data();
                }
                break;
            #endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
            case SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN:
            case SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN:
            {
				//noneed to free data here, data can be freed at lot of places
				//MAUI_03088767
            }
                break;
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
        }

    }
    return MMI_RET_OK;
}

/* mem status ***** */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_save_objects_attachment_list_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_attachment_list_exit_func(void)
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
 *  mmi_umms_app_sh_save_objects_attachment_list_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_attachment_list_rsk_handler(void)
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
 *  mmi_umms_app_sh_save_objects_list_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_list_exit_func(void)
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
 *  mmi_umms_app_sh_save_objects_list_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_list_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS:
        case MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS:
        case MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS:
        case MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS:

            mmi_umms_app_ui_plug_in_save_viewer_objects(hilite_menu);
            break;
        case MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS:
            mmi_umms_app_if_show_save_objects_attchement_list();

            break;

        default:
            MMI_ASSERT(0);
            break;

    }
}

/* mms property */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_properties_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_properties_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_sort_by_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sort_by_exit_func(void)
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
 *  mmi_umms_app_sh_sort_by_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sort_by_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_details_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_use_details_menu_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_recipient_list_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_recipient_list_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dummy_entry_function();
    mmi_umms_app_ui_draw_set_current_opt_menu_id(MENU_ID_UMMS_RECIPIENT_SLIM);
    mmi_umms_app_if_show_recipient_addresses_options();
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_number_list_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_use_number_list_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_if_show_use_details_addresses_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_java_options_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_java_options_exit_func(void)
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
 *  mmi_umms_app_sh_mms_java_options_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_java_options_rsk_handler(void)
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
 *  mmi_umms_app_sh_sim_selection_profile_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sim_selection_profile_exit_func(void)
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
 *  mmi_umms_app_sh_sim_selection_profile_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_sim_selection_profile_rsk_handler(void)
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
 *  mmi_umms_app_sh_settings_sim_selection_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_settings_sim_selection_exit_func(void)
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
 *  mmi_umms_app_sh_settings_sim_selection_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_settings_sim_selection_rsk_handler(void)
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
 *  mmi_umms_app_sh_settings_sim_selection_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM >= 2)
void mmi_umms_app_sh_settings_sim_selection_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_MMS_SETTING_SIM1:
            mmi_umms_app_ui_plug_in_show_sim_profile(MMI_SIM1);
            break;
        case MENU_ID_UMMS_MMS_SETTING_SIM2:
            mmi_umms_app_ui_plug_in_show_sim_profile(MMI_SIM2);
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_UMMS_MMS_SETTING_SIM3:
            mmi_umms_app_ui_plug_in_show_sim_profile(MMI_SIM3);
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_UMMS_MMS_SETTING_SIM4:
            mmi_umms_app_ui_plug_in_show_sim_profile(MMI_SIM4);
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
        default:
            MMI_ASSERT(0);
    }
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_notification_option_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_notification_option_screen_exit_func(void)
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
 *  mmi_umms_app_sh_notification_option_screen_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_notification_option_screen_rsk_handler(void)
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
 *  mmi_umms_app_sh_show_report_options_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_report_options_screen_exit_func(void)
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
 *  mmi_umms_app_sh_show_report_options_screen_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_report_options_screen_rsk_handler(void)
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
 *  mmi_umms_app_sh_show_sim_options_resend_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_sim_options_resend_screen_exit_func(void)
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
 *  mmi_umms_app_sh_show_use_details_addresses_options_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_use_details_addresses_options_screen_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/* */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_message_status_screen_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_message_status_screen_exit_func(void)
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
 *  mmi_umms_app_sh_show_new_message_popup_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_new_message_popup_exit_func(void)
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
 *  mmi_umms_app_sh_save_objects_attachment_list_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_attachment_list_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (option_scr_data->open_mode == MMA_MODE_EDIT)
    {
        mmi_umms_app_ui_plug_in_delete_attachmant_data();
        return;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_umms_app_ui_plug_in_save_attachmant_data_in_mms();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_save_objects_attachment_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_save_objects_attachment_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_dynamic_screen_struct *dynamic_src;
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    dynamic_src =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*)
        mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    dynamic_src = (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    ASSERT(dynamic_src);
    dynamic_src->hilighted_item = index;
    // #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    srv_mms_set_attachment_list_hilighted_item(dynamic_src->hilighted_item);
    // #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_preview_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_preview_menu_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __MMI_MMS_PREVIEW_GOTO__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_preview_menu_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_preview_menu_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}

#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_message_settings_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_message_settings_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
        case MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE:
            mmi_umms_app_if_show_pref_storage_option();
            break;
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
        case MENU_ID_UMMS_MMS_SETTINGS_STORAGE_FILTER:
            mmi_umms_app_if_show_msg_filter_option();
            break;
#endif
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_MMS_SETTINGS_COMPOSE:
            mmi_umms_app_if_show_compose_settings_menu();
            break;

        case MENU_ID_UMMS_MMS_SETTINGS_SENDING:
            mmi_umms_app_if_show_sending_settings_menu();
            break;

        case MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL:
            mmi_umms_app_if_show_retrieval_settings_menu();
            break;
        case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS:
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
			#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
            mmi_umms_app_if_show_memory_status_menu();
    #else 
			mmi_umms_app_if_show_card_memory_status_screen();
			#endif
    #else 
            mmi_umms_app_if_show_memory_status_screen();
    #endif 
            break;
        default:
            MMI_ASSERT(0);
            break;
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    }
}

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_memory_status_menu_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_memory_status_menu_exit_func(void)
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
 *  mmi_umms_app_sh_mms_memory_status_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_memory_status_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_PHONE:
            mmi_umms_app_if_show_phone_memory_status_screen();
            break;
        case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS_CARD:
            mmi_umms_app_if_show_card_memory_status_screen();
            break;
#ifdef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
		case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS:
			mmi_umms_app_if_show_card_memory_status_screen();
            break;
#endif
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
        default:
            MMI_ASSERT(0);
            break;
#endif
    }
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_option_slim_menu_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_option_slim_menu_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_confirm_screen_para(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U16*) GetString(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY,
        MMI_FALSE,
        MMI_FALSE,
        mmi_umms_app_sh_mms_option_save_lsk_handler,    /* mmi_umms_entry_cancel_dwnld, */
        mmi_umms_app_sh_mms_option_save_rsk_handler,
        mmi_umms_app_sh_mms_option_save_exit_handler,
        NULL);
    mmi_umms_app_if_show_display_confirm_screen();
	mmi_frm_scrn_set_key_proc(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM, mmi_umms_proc_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_option_slim_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_option_slim_delete_scr_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_delete_viewer_data(SCR_ID_UMMS_MMS_VIEWER);
    mmi_umms_app_sh_delete_screen_context(SCR_ID_UMMS_MMS_VIEWER);
    mmi_umms_app_sh_delete_umms_screens();
    mmi_umms_app_sh_delete_umms_use_details_screens();
    mmi_umms_app_sh_delete_umms_save_objects_screens();
}

static MMI_BOOL g_is_lsk_pressed = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_save_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_save_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_is_lsk_pressed = MMI_TRUE;
    mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_SAVE_TO_DRAFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_save_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_save_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_umms_app_dtmgr_set_menu_cui_id(GRP_ID_INVALID);
    mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_option_save_exit_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_option_save_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_umms_app_dtmgr_get_menu_cui_id() != GRP_ID_INVALID && g_is_lsk_pressed == MMI_FALSE)
	{
    cui_menu_close(mmi_umms_app_dtmgr_get_menu_cui_id());
	mmi_umms_app_if_show_option_screen_slim();
}
	g_is_lsk_pressed = MMI_FALSE;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_template_menu_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_template_menu_rsk_handler(void)
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
 *  mmi_umms_app_sh_template_menu_list_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_template_menu_list_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_app_dtmgr_get_parent_grp_id() != GRP_ID_INVALID)
    {
        mmi_umms_app_dtmgr_set_um_back_up_id(mmi_umms_app_dtmgr_get_parent_grp_id());
    }
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_TEMPLATES_USER_DEFINED:
            mmi_umms_app_if_show_user_template_list();
            break;
        case MENU_ID_UMMS_TEMPLATES_DEFAULT:
            mmi_umms_app_if_show_default_template_list();
            break;
        default:
            MMI_ASSERT(0);
    }

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_send_read_report_yes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_send_read_report_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SH_VIEWER_RR_YES);
    mmi_umms_app_ui_plug_in_rr_yes_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_send_read_report_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_send_read_report_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SH_VIEWER_RR_NO);
    mmi_umms_app_ui_plug_in_rr_no_hdlr();
}

#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_toolbar_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_toolbar_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    #else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
            (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_MMS_VIEWER);
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (viewer_scr && viewer_scr->mode == WGUI_MV_DISPLAY_MODE_PLAY)
    {
        mmi_umms_app_ui_callback_viewer_stop_callback();
        return;
    }
    mmi_umms_app_ui_plugin_viewer_toolbar_hdlr(index);
}
#endif /* __MMI_FTE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plugin_viewer_lsk_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SH_VIEWER_EXIT_FN);
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    StopTimer(MMS_VIEWER_TIMER);
#endif 
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    srv_mms_close_use_detail_file_hdl();
#endif 
	#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
    mmi_umms_app_dtmgr_stop_image_decode();
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    mmi_umms_app_dtmgr_set_data_for_phb_notify();
#endif 

    mmi_frm_scrn_close_active_id();
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    mmi_umms_app_ui_plug_in_viewer_back_key_pressed();
#endif 
	#if defined  __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ &&  defined(__MMI_FTE_SUPPORT__)
	if (info->open_mode == MMA_MODE_VIEW && !(srv_mms_get_is_preview_from_cui()))
	{ 
            srv_mms_set_open_mode(MMA_MODE_EDIT);
            mmi_umms_app_core_handle_view();
	}
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_hilitte_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_node        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_hilitte_hdlr(srv_mms_viewer_use_details_list *current_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    viewer_scr->current_hilited = current_node;
    /* set send key operation */
    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
    {
        viewer_scr->set_send_key_cb(viewer_scr->current_hilited);
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_hilitte_click_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_node        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_viewer_hilitte_click_hdlr(srv_mms_viewer_use_details_list *current_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    applib_address_node_struct *node = NULL;
	#ifdef __OP01__
				mmi_umms_app_dtmgr_use_details_struct *data = NULL;
#endif
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    viewer_scr->current_hilited = current_node;
    node = (applib_address_node_struct*) viewer_scr->current_hilited->item;
    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
    {
        switch (node->dataType)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
				#ifdef __OP01__
					data = (mmi_umms_app_dtmgr_use_details_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_use_details_struct));
					ASSERT(data);
                    memset(data, 0, sizeof(mmi_umms_app_dtmgr_use_details_struct));
	                data->get_use_details_rsp.total_count = 1;
				    data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_NUMBER;
					data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_PHONENUMBER;
					data->get_use_details_rsp.num_list = node;
					mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
				    mmi_umms_app_sh_use_number_list_lsk_handler();
                 #else
                mmi_umms_app_ui_plug_in_use_number_as_make_call_viewer((U8*) node->data2);
                #endif
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                 #ifdef __OP01__
				 data = (mmi_umms_app_dtmgr_use_details_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_use_details_struct));
					ASSERT(data);
                    memset(data, 0, sizeof(mmi_umms_app_dtmgr_use_details_struct));
	                data->get_use_details_rsp.total_count = 1;
				    data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_EMAIL;
					data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_EMAIL;
					data->get_use_details_rsp.email_list = node;
					mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
				    mmi_umms_app_sh_use_number_list_lsk_handler();
				    #else
        #ifdef __MMI_EMAIL__
                mmi_umms_app_ui_plug_in_use_email_as_send_email_viewer((U8*) node->data);
        #endif 
                   #endif
                break;
            case APPLIB_ADDR_TYPE_URL:
				#if defined(__OP01__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
				    data = (mmi_umms_app_dtmgr_use_details_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_use_details_struct));
					ASSERT(data);
                    memset(data, 0, sizeof(mmi_umms_app_dtmgr_use_details_struct));
	                data->get_use_details_rsp.total_count = 1;
				    data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_URL;
					data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_URL;
					data->get_use_details_rsp.url_list = node;
					mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
				    mmi_umms_app_sh_use_number_list_lsk_handler();
                #else
                mmi_umms_app_ui_plug_in_use_url_as_browser_launch_viewer((U8*) node->data);
                #endif
                break;
            default:
                ASSERT(0);
        }
    }
}
#if defined(__OP01__) && defined(__MMI_TOUCH_SCREEN__)
void mmi_umms_app_sh_use_detail_delete_options_hdlr(void)
{
	mmi_umms_app_dtmgr_use_details_struct *data =
        (mmi_umms_app_dtmgr_use_details_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
	if(data != NULL &&
		!(mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_NUMBER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)
			|| mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_EMAIL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)
			|| mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_URL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)
			|| mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_SENDER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)))
	{
		srv_mms_mem_mgr_app_adm_free(data);
		data = NULL;
		mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
	}
}
#endif
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_highlighted_number_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_highlighted_number_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    applib_address_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    node = (applib_address_node_struct*) viewer_scr->current_hilited->item;
    mmi_umms_app_ui_plug_in_use_number_as_make_call_viewer((U8*) node->data2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_entry_use_url_go_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_entry_use_url_go_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    applib_address_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    node = (applib_address_node_struct*) viewer_scr->current_hilited->item;
    mmi_umms_app_ui_plug_in_use_url_as_browser_launch_viewer((U8*) node->data);
}

#ifdef __MMI_EMAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_email_send_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_use_email_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    applib_address_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    node = (applib_address_node_struct*) viewer_scr->current_hilited->item;
    mmi_umms_app_ui_plug_in_use_email_as_send_email_viewer((U8*) node->data);
}
#endif /* __MMI_EMAIL__ */ 

#ifdef __MMI_MMS_PREVIEW_GOTO__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_preview_slide_list_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_preview_slide_list_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_preview_slide_list_hdlr(scrDB->scrn_id);
}

#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_common_settings_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_common_settings_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hilite_menu)
    {
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_MMS_SETTINGS:
            /* mmi_umms_app_if_show_mms_message_settings_menu(); */
            break;
#endif
        case MENU_ID_UMMS_MMS_SETTINGS_EDIT_PROFILE:
            mmi_umms_app_if_show_edit_profile_screen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_viewer_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_viewer_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = (mmi_umms_app_screenDB_struct*) data->user_data;
#endif
    U16 scr_id = SCR_ID_UMMS_MMS_VIEWER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (mmi_frm_group_get_state(mmi_umms_app_dtmgr_get_menu_cui_id()) != MMI_SCENARIO_STATE_NONE)
    {
        if (data->evt_id == EVT_ID_SCRN_DEINIT)
        {
            mmi_umms_app_sh_delete_screen_context(scr_id);
        }
        return MMI_RET_OK;
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    scr_id = scrDB->scrn_id;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SH_VIEWER_DELETE_CB);
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_umms_app_dtmgr_delete_viewer_data(scr_id);
        mmi_umms_app_sh_delete_screen_context(scr_id);
        mmi_umms_app_sh_delete_umms_screens();
        mmi_umms_app_sh_delete_umms_use_details_screens();
        mmi_umms_app_sh_delete_umms_save_objects_screens();
		#if defined(__OP01__)  && defined(__MMI_TOUCH_SCREEN__)
        mmi_umms_app_sh_use_detail_delete_options_hdlr();
        #endif
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_infinite_pop_up_delete_scr_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_sh_infinite_pop_up_delete_scr_handler(mmi_event_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->evt_id == EVT_ID_SCRN_DEINIT)
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_MMS_INFO);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_detail_options_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_use_detail_options_hdlr(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_use_details_struct *data =
        (mmi_umms_app_dtmgr_use_details_struct*)
        srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_use_details_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data);
    memset(data, 0, sizeof(mmi_umms_app_dtmgr_use_details_struct));
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    data->curr_index = 0;
    data->is_more = MMI_FALSE;
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    switch (hilite_menu)
    {
        case MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER:
            data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_NUMBER;
            data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_PHONENUMBER;
            mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
            mmi_umms_app_if_show_use_number();
            break;
        case MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL:
            data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_EMAIL;
            data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_EMAIL;
            mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
            mmi_umms_app_if_show_use_email();
            break;
        case MENU_ID_UMMS_OPTION_USE_DETAILS_URL:
            data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_URL;
            data->applib_addr_type = (U8) APPLIB_ADDR_TYPE_URL;
            mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
            mmi_umms_app_if_show_use_url();
            break;
        case MENU_ID_UMMS_OPTIONS_USE_DETAILS_SENDER:
            data->mms_umms_app_slide = SRV_MMS_GET_USE_DETAILS_SENDER;
            mmi_umms_app_dtmgr_update_data_for_use_details((void*)data);
            mmi_umms_app_if_show_use_sender();
            break;
        case MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_NUMBER:
        case MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_EMAIL:
            mmi_umms_app_ui_plug_in_recipient_screen_hdlr(hilite_menu, 0);
            break;

    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_recipient_screen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_recipient_screen_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_recipient_screen_hdlr(hilite_menu, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_update_data_for_use_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_update_data_for_use_details(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_update_state((void*)data, MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST, 0);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_static_list_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_static_list_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_move_to_archive_confirm_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_move_to_archive_confirm_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U8 error = 0;
    U8 srv_result = 0;

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
    mmi_um_iter_viewer_result_struct other_msg_data;
    U8 folder_id;
    void *um_data = NULL;
    mmi_id parent_id;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_BGSR_SUPPORT__
    if (info->folder_id == MMA_FOLDER_INBOX)
    {
        srv_mms_bgsr_change_msg_notify(
            info->msg_id,
            SRV_MMS_BGSR_OP_MOVE_TO_FOLDER,
            SRV_MMS_BGSR_FOLDER_INBOX,
            mmi_umms_app_core_move_to_archive_msg_notify_callback,
            info->msg_info->msg_storage);
    }
    else
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
    {
        srv_result = srv_mms_save_msg(info->msg_id, MMA_FOLDER_ARCHIVE, &error);
        if (srv_result != SRV_MMS_RESULT_OK)
        {
            mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
            mmi_umms_app_sh_go_to_box_list_screen();
            return;
        }
        if (error == MMA_RESULT_OK)
        {
            srv_mms_show_status_icon();
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MOVED), MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();
        #ifdef __MMI_MMS_ITERATOR_VIEWER__
            ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
            parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
        #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
            mmi_umms_app_sh_go_to_box_list_screen();
        #ifdef __MMI_MMS_ITERATOR_VIEWER__
            if (ret_val == MMI_UMMS_TRUE)
            {
                mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data, parent_id);
            }
        #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
        }
        else
        {   /* Save Failed */
            mmi_umms_app_if_show_error_pop_up(error);
            mmi_umms_app_sh_go_to_box_list_screen();
        }
    }
}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_go_to_box_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_go_to_box_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Get the Total Number of Message present in the box selected
    // If total number in the box is 0 then go to the Message Centre Screen
    // Else got to the file List Screen.
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_GO_TO_BOX_LIST_SCR);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_app_ui_draw_dummy_screen();
    }
    mmi_umms_app_if_deinit_viewer();
    mmi_umms_app_sh_delete_umms_screens();
    mmi_umms_app_sh_delete_umms_use_details_screens();
    mmi_umms_app_sh_delete_umms_save_objects_screens();
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_umms_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_umms_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELET_ALL_SCREEN);
    /* mmi_frm_group_close(mmi_umms_dtmgr_get_group_id()); */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (mmi_umms_dtmgr_get_group_id() != GRP_ID_UMMS_LIST_SETTINGS)
#endif
    {
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_OPTIONS);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER_PROGRESS_SCREEN);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_NOTIFICATION);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MESSAGE_STATUS);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_JAVA_OPTIONS);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SIM_OPTION);
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SORT_OPTION);
    #endif 
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);

        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OUTBOX_OPTION);
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_OPTIONS);
    #endif 
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);

        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM);
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN);
    #endif 
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
    #endif 
        mmi_umms_app_dtmgr_reset_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_umms_use_details_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_umms_use_details_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELET_ALL_SCREEN);
    /* mmi_frm_group_close(mmi_umms_dtmgr_get_group_id()); */
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER_PROGRESS_SCREEN);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_NOTIFICATION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MESSAGE_STATUS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_JAVA_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_NUMBER);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_EMAIL);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_URL);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_USE_SENDER);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OUTBOX_OPTION);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_ADDRESS_LIST);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_SENDER_RECIPIENT);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM);     /* amit added */
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_umms_save_objects_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_umms_save_objects_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SAVE_OBJECT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_progress_screen(void)
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
    /* if(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
       {
       mmi_umms_app_ui_draw_dummy_screen();
       } */

    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), scr_id);

}

#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_cancel_dwnld_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_cancel_dwnld_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    srv_mms_cancel_download_req_struct req;

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
    mmi_um_iter_viewer_result_struct other_msg_data;
    U8 folder_id;
    void *um_data = NULL;
    mmi_id parent_id;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_cancel_download_req_struct));
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_CANCEL_DWNLD, info->msg_id);

    req.msg_id = info->msg_id;
    srv_mms_cancel_download(&req);
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
    parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    mmi_umms_app_sh_delete_umms_screens();
    mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (ret_val == MMI_UMMS_TRUE)
    {
        mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data, parent_id);
    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
}
#endif /* __MMI_MMS_BGSR_CANCEL_PROHIBIT__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_default_template_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_default_template_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_get_msg_info_from_bgsr_callback_for_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_get_msg_info_from_bgsr_callback_for_update(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info)
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
 *  mmi_umms_app_sh_show_screen_based_on_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_screen_based_on_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_SCREEN_BASED_ON_MSG_STATUS, msg_id);
    /* if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
       { */
    if (info->msg_info->msg_type == MMA_MSG_TYPE_JAVA)
    {
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_umms_app_sh_delete_progress_screen();
        mmi_umms_app_sh_enter_java_mms_screen();
    }
    else
    {
        if ((info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
            ((info->folder_id == MMA_FOLDER_OUTBOX) &&
             (info->action == MMI_UMMS_OPEN_MMS_OPTION) ||
             ((srv_mms_bgsr_get_msg_status(info->msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
              && (info->action == MMI_UMMS_OPEN_MMS_VIEWER))))
        {
            mmi_umms_app_ui_draw_dummy_screen();
            mmi_umms_app_sh_delete_progress_screen();
            mmi_umms_app_sh_show_notification_or_outbox_option(msg_id);
        }
        else
        {
            switch (info->action)
            {
                case MMI_UMMS_OPEN_MMS_VIEWER:
                    mmi_umms_app_sh_show_other_mms_option_list_option_off(msg_id);
                    break;
                case MMI_UMMS_OPEN_MMS_OPTION:
                    mmi_umms_app_ui_draw_dummy_screen();
                    mmi_umms_app_sh_delete_progress_screen();
                    mmi_umms_app_sh_show_other_mms_option_list_option_on(msg_id);
                    break;
                default:
                    MMI_ASSERT(0);
            }
        }
    }
    /* }
       else
       {
       mmi_umms_app_sh_delete_screen_reset_globals();
       } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_other_mms_option_list_option_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_other_mms_option_list_option_off(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_OTHER_MMS_OPTION_OFF, msg_id);
    if (info->msg_id == msg_id)
    {
    #ifdef __MMI_MMS_BGSR_SUPPORT__
        if (info->folder_id == MMA_FOLDER_OUTBOX &&
			info->bgsr_msg_info == NULL)
        {
            info->bgsr_msg_info =
                (srv_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
            ASSERT(info->bgsr_msg_info);
            memset(info->bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
            srv_mms_bgsr_get_msg_info(
                info->msg_id,
                info->bgsr_msg_info,
                mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view,
                info->msg_info->msg_storage,
                (mma_msg_type_enum)info->msg_info->msg_type);
        }
        else
    #endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
        {
            mmi_umms_app_core_handle_view();
        }

    }
    else
    {
        mmi_umms_app_sh_delete_screen_reset_globals();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_other_mms_option_list_option_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_other_mms_option_list_option_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_OTHER_MMS_OPTION_ON, msg_id);
    if (info->msg_id == msg_id)
    {
        mmi_umms_app_core_show_option();
    }
    else
    {
        mmi_umms_app_sh_delete_screen_reset_globals();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_delete_screen_reset_globals
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_delete_screen_reset_globals(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
    mmi_umms_app_sh_delete_umms_screens();
    mmi_umms_app_dtmgr_reset_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_notification_or_outbox_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_notification_or_outbox_option(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_NOTIFI_OR_OUTBOX_OPTION, msg_id);
        if (info->msg_id == msg_id)
    {
        if(info->bgsr_msg_info == NULL)
    {
        info->bgsr_msg_info =
            (srv_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
        ASSERT(info->bgsr_msg_info);
        memset(info->bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
        srv_mms_bgsr_get_msg_info(
            info->msg_id,
            info->bgsr_msg_info,
            mmi_umms_app_core_get_msg_info_from_bgsr_callback,
            info->msg_info->msg_storage,
            (mma_msg_type_enum)info->msg_info->msg_type);
    }
    else
    {
            mmi_umms_app_core_get_msg_info_from_bgsr_callback(info->msg_id, info->bgsr_msg_info);
        }
    }
    else
    {
        mmi_umms_app_sh_delete_screen_reset_globals();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_enter_java_mms_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_enter_java_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_callback_popup_screen_para(
        (UI_string_type) GetString(STR_ID_UMMS_FAILED_TO_DISPLAY_JSR_MMS),
        MMI_EVENT_PROPLEM,
        mmi_umms_app_if_show_java_mms_options,
        mmi_umms_app_sh_delete_umms_screens);

    mmi_umms_app_if_show_display_callback_popup_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_return_to_um_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_return_to_um_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_dtmgr_option_scr_data_struct *info = (mmi_umms_app_dtmgr_option_scr_data_struct *)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_umms_app_sh_delete_progress_screen();
        mmi_umms_app_sh_delete_umms_screens();
    }
    else
    {
        mmi_umms_app_sh_delete_umms_screens();
    }
    /* Added in MAUI_02144883 */
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_corrupt_and_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_corrupt_and_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_confirm_screen_para(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U16*) GetString(STR_ID_UMMS_CORRUPT_AND_DELETE),
        MMI_EVENT_QUERY,
        MMI_FALSE,
        MMI_FALSE,
        mmi_umms_app_sh_mms_option_delete_lsk_handler,  /* mmi_umms_entry_cancel_dwnld, */
        mmi_umms_app_sh_mms_option_delete_rsk_handler,
        NULL,
        NULL);

    mmi_umms_app_if_show_display_confirm_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_unsupported_and_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_unsupported_and_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_confirm_screen_para(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U16*) GetString(STR_ID_UMMS_UNSUPPORTED_MMS_AND_DELETE),
        MMI_EVENT_QUERY,
        MMI_FALSE,
        MMI_FALSE,
        mmi_umms_app_sh_mms_option_delete_lsk_handler,  /* mmi_umms_entry_cancel_dwnld, */
        mmi_umms_app_sh_mms_option_delete_rsk_handler,
        NULL,
        NULL);

    mmi_umms_app_if_show_display_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_network_changed_from_immd_to_deffered_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_network_changed_from_immd_to_deffered_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    srv_mms_bgsr_change_msg_notify(0, SRV_MMS_BGSR_OP_CANCEL_ALL_INBOX, SRV_MMS_BGSR_FOLDER_INBOX, NULL, MMA_MSG_STORAGE_TOTAL);        /* need no cb this is to just infirm BGSR for current downloading msg */
    /* if settings are opend only how will we pass the current location there should be enum for both memory */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_display_working_space_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  min_fs_space_required       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_display_working_space_popup(kal_uint32 min_fs_space_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const S8 *pstr1, *pstr2;
    int msg_size;
    S8 *message = NULL;
    U8 temp_string[12];
    U8 temp_ucs2_string[12 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_string, 0, 12);
    memset(temp_ucs2_string, 0, 12 * ENCODING_LENGTH);

    pstr1 = GetString(STR_UMMS_NO_ENOUGH_WORKING_SPACE_ID);
    pstr2 = GetString(STR_ID_UMMS_KB);

    sprintf((char*)temp_string, "%d ", min_fs_space_required);
    mmi_asc_n_to_ucs2((S8*) temp_ucs2_string, (S8*) temp_string, 10);

    msg_size =
        (mmi_ucs2strlen((PS8) pstr1) + mmi_ucs2strlen((PS8) pstr2) + mmi_ucs2strlen((PS8) temp_ucs2_string) +
         1 /* null terminate */ ) * ENCODING_LENGTH;
    message = (S8*) OslMalloc(msg_size);
    if (NULL == message)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();

        return;
    }

    mmi_ucs2cpy(message, pstr1);

    mmi_ucs2cat(message, (S8*) temp_ucs2_string);

    mmi_ucs2cat(message, pstr2);

    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) message, MMI_EVENT_FAILURE);
    mmi_umms_app_if_show_display_popup_screen();

    OslMfree(message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_signature_selection_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_settings_signature_selection_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_compose_settings_signature_selection_lsk_handler();
}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_show_recipient_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_show_recipient_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_dynamic_screen_struct *use_detail_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_ADD_RECIPIENT);
    use_detail_scr->hilighted_item = index;
    /* mmi_umms_app_dtmgr_set_hilite_item(index); */
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_use_details_list_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_use_details_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_use_details_list_addresses_list_hilite_handler(index);
}

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_pref_storage_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_msg_filter_exit_func(void)
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
 *  mmi_umms_app_sh_mms_pref_storage_exit_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_pref_storage_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_msg_filter_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_mms_msg_filter_handler(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_umms_app_ui_plug_in_msg_filter_menu_handling(evt);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_pref_storage_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hilite_menu     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_sh_mms_pref_storage_handler(U16 hilite_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_umms_app_ui_plug_in_pref_storage_menu_handling(hilite_menu, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_radio_button_list_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_radio_button_list_rsk_handler(void)
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
 *  mmi_umms_app_sh_radio_button_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_radio_button_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_radio_selection_screen_struct *radio_scr;
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    radio_scr = (mmi_umms_radio_selection_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    ASSERT(radio_scr);
    radio_scr->hilighted_item = index;
}

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_sh_mms_delete_lsk_handler_for_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_sh_mms_delete_lsk_handler_for_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* srv_mms_delete_req_struct req; */
    srv_mms_bgsr_msg_box_enum bgsr_folder_id = SRV_MMS_BGSR_FOLDER_NONE;
    
    U8 error = 0;
    U8 srv_result = 0;
    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(
       MMI_INET_TRC_G6_MMS,
       MMI_UMMS_DONT_SEND_READ_REPORT,
       g_current_mms_info_list->current_msg_id,
       g_current_mms_info_list->folder_id); */

    bgsr_folder_id = mmi_umms_app_util_mma_folder_to_bgsr_folder((mma_folder_enum)sync_info->msg_info.folder);
    switch (sync_info->msg_info.folder)
    {
        case MMA_FOLDER_OUTBOX:
        case MMA_FOLDER_INBOX:
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SEND_BGSR_CHANGE_NOTIFY, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                sync_info->msg_id,
                SRV_MMS_BGSR_OP_DELETE,
                bgsr_folder_id,
                mmi_umms_app_core_delete_msg_notify_for_msg_list_callback,
                sync_info->msg_info.msg_storage);
            break;
        case MMA_FOLDER_ARCHIVE:
            // if (sync_info->msg_info.from_folder == MMA_FOLDER_INBOX)/*rec*/
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SEND_BGSR_CHANGE_NOTIFY, bgsr_folder_id);
            srv_mms_bgsr_change_msg_notify(
                sync_info->msg_id,
                SRV_MMS_BGSR_OP_DELETE,
                bgsr_folder_id,
                mmi_umms_app_core_delete_msg_notify_for_msg_list_callback,
                sync_info->msg_info.msg_storage);
            break;
        }
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_FOLDER_USRDEF_TEMPLATE:
            mmi_umms_app_dtmgr_reset_template_list_data();
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        default:

            srv_result = srv_mms_delete_msg(sync_info->msg_id, &error);

            if (srv_result != SRV_MMS_RESULT_OK)
            {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                mmi_umms_app_sh_delete_umms_screens();
                return;
            }
            if (error == MMA_RESULT_OK)
            {
            #ifndef __MMI_BACKGROUND_CALL__
                // if (!mmi_umms_is_in_call())
                //{
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
                /* } */
            #else /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
            #endif /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_sh_delete_umms_screens();
                srv_mms_show_status_icon();
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(error);
                mmi_umms_app_sh_delete_umms_screens();
            }
            break;
    }
    srv_mms_reset_sync_data();

}
#endif /* __MMI_FTE_SUPPORT__ */ 

#endif /* __MMI_MMS_2__ */ 

