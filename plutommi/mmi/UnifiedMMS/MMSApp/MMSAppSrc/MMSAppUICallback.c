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
 * MMSAppUICallback.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

// #include "MainMenuDef.h"
#include "CommonScreens.h"
// #include "mmsadp.h"
#include "MMSAppUICommon.h"
#include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "mmi_rp_srv_mms_def.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSAppInterfaceGProt.h"
#include "MMSAppInterfaceProt.h"
#include "MMSAppScrHdlr.h"
#include "MMSAppSrvHdlr.h"
#include "MMSAppUIPlugin.h"
// #include "MMSAppUIdrawEx.h"
#include "MMSAppScrHdlrEx.h"
#include "MMSAppResourceDB.h"
#include "inlineCuiGprot.h"
#include "MMSAppDataManager.h"
#include "MMSAppUICallback.h"
#include "MMSAppOp.h"
#include "MmsSrvGprot.h"
#include "MMSAppResdef.h"
// #include "CallManagementGprot.h"
#include "ProfilesSrvGprot.h"
#include "MMSAppUIdraw.h"
#include "App_usedetails.h"

// #include "ProfileMgrGProt.h"
#include "EmailAppGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __MMI_USB_SUPPORT__ */ 

#include "WAPProfileSrvGProt.h"
#include "WapProfileSrvType.h"

#ifdef __MMI_MMS_POSTCARD__
#include "app_oppostcard.h"
#include "UcSrvGprot.h"
#endif /* __MMI_MMS_POSTCARD__ */ 
// #include "UcmGprot.h"
#include "UMGProt.h"
// #include "UcAppGProt.h"
#include "custom_wap_config.h"
#include "DateTimeGprot.h"
#include "FileMgrCUIGProt.h"
#include "MenuCuiGprot.h"
#include "BootupSrvGprot.h"
// #include "SimDetectionGprot.h"
#include "FileMgrSrvGProt.h"
// #include "MMSAppUIController.h"
#include "MMSAppUIdraw.h"
#include "Imageviewcuigprot.h"
#include "MediaAppGProt.h"
#include "MMIDataType.h"
#include "CustMenuRes.h"
#include "kal_general_types.h"
#include "mma_api.h"
#include "mma_struct.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
// #include "SimDetectionStruct.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "wgui_categories_MMS_viewer.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_mms_def.h"
#include "custom_srv_prof_defs.h"
#include "UcmSrvGprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stdio.h"
#include "MmsXMLDefSrv.h"
#include "custom_mmi_default_value.h"
#include "gui_data_types.h"
#include "gui.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "AlertScreen.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "mmi_frm_mem_gprot.h"
// #include "app_buff_alloc.h"
#include "fs_errcode.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_gprot.h"
#include "CommonScreensResDef.h"
#include "mms_api.h"
#include "MsgViewerCuiGProt.h"
#include "mmi_frm_gestures_gprot.h"
#include "wgui_touch_screen.h"
#include "IdleGprot.h"
#include "mma_struct.h"
#include "gdi_include.h"
#include "med_mem.h"
#include "med_api.h"
#include "Conversions.h"
#include "SimCtrlSrvGprot.h"
#include "NetSetAppGprot.h"
#if(MMI_MAX_SIM_NUM >= 3)
#include "SimSelCuiGProt.h"
#endif 
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern kal_uint16 mmi_um_prepare_sort_selection_list(kal_uint16 *menu_item_str_id, kal_uint16 max_menu_item);
#endif 

extern kal_uint32 applib_get_file_size(kal_wchar *filename);
static MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_view_lebel_decide(U16 viewerOption, U16 msgType);

/* extern mmi_umms_app_dtmgr_inline_settings_struct *g_umms_context ; */

extern void mmi_umms_signature_objects_remove_confirmation(void);

extern kal_uint64 mma_get_mms_avaliable_file_space(kal_uint32 *usedBytes, U8 storage);

extern void mmi_umms_settings_hdlr(mmi_event_struct *param);

extern U32 srv_mms_get_attachment_no(void);

extern mmi_ret mmi_umms_uc_event_handler_proc(mmi_event_struct *evt);

static mmi_ret mmi_umms_select_file_group_proc(mmi_event_struct *evt);

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
static void mmi_umms_app_ui_callback_image_rights_expired(void *data);
static void mmi_umms_app_ui_callback_audio_rights_expired(void *data);
static void mmi_umms_app_ui_callback_video_rights_expired(void *data);
#endif

S8 *media_path = NULL;


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_options_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_mms_options_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;

}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sort_by_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_sort_by_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_prepare_sort_selection_list(str_item_list, MAX_SUB_MENUS);
    return str_item_list;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_options_menu_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_sim_options_menu_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_options_menu_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_mms_options_menu_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}

/* remove this function  */
extern MMI_BOOL mmi_umms_is_creation_mode_restricted(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_creation_mode_restricted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_is_creation_mode_restricted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_umms_app_ui_callback_sim_options_decide(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    U8 i;
    U8 sim_count;
    U16 menuId[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
                      MENU_ID_UMMS_FROM_SIM1
                     ,MENU_ID_UMMS_FROM_SIM2
    #endif
    #if(MMI_MAX_SIM_NUM >= 3)
                     ,MENU_ID_UMMS_FROM_SIM3
    #endif
    #if(MMI_MAX_SIM_NUM >= 4)
                     ,MENU_ID_UMMS_FROM_SIM4
    #endif
                    };

    WCHAR sim_name[MAX_SUB_MENU_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   

    for (i = (U8) MMI_SIM1, sim_count = 0; sim_count < MMI_SIM_TOTAL; i = i << 1, sim_count++)
    {
        if(srv_mms_is_sim_valid((mmi_sim_enum)i))
        {
            if (mmi_netset_get_sim_name((mmi_sim_enum)i) != NULL)
            {
                kal_wsprintf(sim_name, 
                    "%w%w%w%w",
                    GetString(GetStringIdOfItem(menuId[sim_count])),
                    (S8*) L"(",
                    mmi_netset_get_sim_name((mmi_sim_enum)i),
                    (S8*) L")");
                cui_menu_set_item_string(menu_evt->sender_id, menuId[sim_count], sim_name);
            }
        }
    }
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_options_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_sim_options_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sort_by_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sort_by_num(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS] = {0};
    S32 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == SCR_ID_UMMS_SORT_OPTION)
    {
        num = mmi_um_prepare_sort_selection_list(nStrItemList, MAX_SUB_MENUS);
    }
    return num;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_slim_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_slim_options_decide(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_header_struct *header = srv_mms_container_get_header();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
#if(MMI_MAX_SIM_NUM == 2)

    if (srv_mms_is_sim_valid(MMI_SIM1))
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    else
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    if (srv_mms_is_sim_valid(MMI_SIM2))
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM2);
    else
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
   if (1 == GetNumOfChild_Ext(MENU_ID_UMMS_OPTIONS_SLIM_SEND))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    }

#endif /* (MMI_MAX_SIM_NUM == 2) */ 
    if (srv_mms_num_valid_sim() == 0)
	{
		#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if(srv_sim_ctrl_get_num_of_inserted() == 0)
		{
			 mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
             mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
            cui_menu_set_item_disabled(mmi_umms_app_dtmgr_get_menu_cui_id(), MENU_ID_UMMS_OPTIONS_SLIM_SEND, MMI_TRUE);
		}
		else
        #endif
		{
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
		}
        
	}
#if(MMI_MAX_SIM_NUM == 2)
    if (header->to_num == 0 && header->cc_num == 0 && header->bcc_num == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);

    }
#endif /* (MMI_MAX_SIM_NUM == 2) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_recipient_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_recipient_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_addr_list_struct *current = NULL;
    mma_mms_header_struct *header;
    mmi_umms_app_ui_draw_dynamic_screen_struct *slide_list_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide_list_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_ADD_RECIPIENT);
    header = srv_mms_container_get_header();

    switch (slide_list_scr->highlighted_menu)
    {
        case MENU_ID_UMMS_ADD_RECIPIENT_TO:
            current = header->to;
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_ADD_RECIPIENT_CC:
            current = header->cc;
            break;
        case MENU_ID_UMMS_ADD_RECIPIENT_BCC:
            current = header->bcc;
            break;
#endif
        default:
            ASSERT(0);
    }
    if (current)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_REMOVE_ADDRESS);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_EDIT_ADDRESS);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_REMOVE_ADDRESS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_EDIT_ADDRESS);
    }
    return scr_id;

    /* to decide whether to dim any option menu */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_option_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 *  str_item_list       [?](?)
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_ui_callback_compose_option_decide(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTINGS_COMPOSE);
#endif
    return menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_composer_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 *  str_item_list       [?](?)
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_ui_callback_composer_options_decide(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_frm_unhide_menu_item(MENU_ID_UMMS_EDIT_TEXT);
     * mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT);
     * mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE);
     * return GetNumOfChild_Ext(menu_id);
     */
    mma_mms_description_struct *mms_msg_data = srv_mms_container_get_content();
    mma_mms_slide_struct *curr_slide = mms_msg_data->body->curr_slide;

    mmi_frm_unhide_menu_item(MENU_ID_UMMS_EDIT_TEXT);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE_SLIDE);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE_IMAGE);
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE_SOUND);
#endif
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE_VIDEO);
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_DELETE_ATTACHMENT);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_ATTACHMENT);
    if (!(mms_msg_data->body->attachment))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE_ATTACHMENT);
    }
#endif
    if (curr_slide->vid.id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE_VIDEO);
    }

    if ((curr_slide->img.id) == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE_IMAGE);
    }
    if ((curr_slide->aud.id) == 0)
    {
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE_SOUND);
#endif
    }
   
    
	mmi_umms_app_ui_callback_insert_options_decide(MENU_ID_UMMS_INSERT);
    if (mms_msg_data->body->slide_no == 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE_SLIDE);
    }
    if (0 == GetNumOfChild_Ext(MENU_ID_UMMS_DELETE))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE);
    }
#ifdef __MMI_MMS_NO_SMIL_SUPPORT__
		if(curr_slide->img.id || curr_slide->vid.id || curr_slide->aud.id)
		{
			mmi_frm_hide_menu_item(MENU_ID_UMMS_EDIT_TEXT);
		}
#endif
    return menu_id;
}
 U16 mmi_umms_app_ui_callback_insert_options_decide(U16 menu_id)
	{
		mma_mms_description_struct *mms_msg_data = srv_mms_container_get_content();
        mma_mms_slide_struct *curr_slide = mms_msg_data->body->curr_slide;

		mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_SLIDE);
		mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_IMAGE);
		mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_VIDEO);
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
		mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_SOUND);
#endif
		mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT);
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
		 mmi_frm_unhide_menu_item(MENU_ID_UMMS_INSERT_ATTACHMENT);
    if (srv_mms_get_attachment_no() >= 3)
    {

        mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_ATTACHMENT);

    }
#endif
		/*SMIl*/
#ifdef __MMI_MMS_NO_SMIL_SUPPORT__
	if (curr_slide->img.id || curr_slide->vid.id || curr_slide->aud.id || curr_slide->txt.id)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_IMAGE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_VIDEO);
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_SOUND);
#endif
		}
#endif

    if (mms_msg_data->body->slide_no == 20)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_SLIDE);
        if (curr_slide->img.id)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_IMAGE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_VIDEO);
#ifdef __MMI_MMS_NO_SMIL_SUPPORT__
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_SOUND);
#endif
#endif
        }
        if (curr_slide->vid.id)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_IMAGE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_VIDEO);
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_SOUND);
#endif
        }
        if (curr_slide->aud.id)
        {
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_SOUND);
#endif
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_VIDEO);
#ifdef __MMI_MMS_NO_SMIL_SUPPORT__
			mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT_IMAGE);
#endif
        }
        if (0 == GetNumOfChild_Ext(MENU_ID_UMMS_INSERT))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT);
        }
    }

	   return menu_id;
   }
#ifdef __MMI_FTE_SUPPORT__

MMI_BOOL  mmi_umms_app_ui_callback_decide_enable_disable_insert_tool()
{

    mma_mms_description_struct *mms_msg_data = srv_mms_container_get_content();
    mma_mms_slide_struct *curr_slide = mms_msg_data->body->curr_slide;

      if ((srv_mms_get_attachment_no() >= 3) &&
		  (mms_msg_data->body->slide_no == 20) &&
		  ((curr_slide->vid.id) || ((curr_slide->img.id) && (curr_slide->aud.id))))
    {
          return MMI_TRUE ;
    }
	  else
    {
		  return MMI_FALSE;
    }
       
}
#endif
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_draft_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_draft_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    if (scr_info == NULL)
    {
        return MMI_UMMS_FALSE;
    }

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_EDIT_TEXT);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_INSERT);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_DELETE);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_umms_app_ui_callback_prop_view_lebel_decide(scr_info->is_already_viewed, scr_info->msg_info->media_type);
    if (scr_info->is_already_viewed)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }

    /* mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY); */

    if ((scr_info->msg_info->is_forward_lock) ||
        ((scr_info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SEND);
    }

#ifdef __MMI_MMS_POSTCARD__
    if (scr_info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SEND);
    }
#endif /* __MMI_MMS_POSTCARD__ */ 

    if (scr_info->msg_info->is_forward_lock == KAL_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);
    }

    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    }

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
    }
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 

    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    }

    if ((!scr_info->is_already_viewed) || (scr_info->msg_info->is_forward_lock == KAL_TRUE)
#ifdef __MMI_MMS_POSTCARD__
        || (scr_info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
#endif 
        )
    {
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
    }

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
		
    }

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (scr_info->folder_id == MMA_FOLDER_ARCHIVE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 

    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    }
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    mmi_umms_app_ui_callback_move_copy_options_hide_unhide();
#endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_DRAFT_OPTIONS);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return num_item;
}

#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_report_box_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_report_box_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    mma_msg_addr_info_struct addr;
    S32 num_item = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);
    result = mma_mms_get_report_address(scr_info->msg_id, &addr);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_CALL,
        scr_info->msg_id,
        result,
        addr.addr_len,
        addr.addr_group,
        addr.addr_type);
    if (result == MMA_RESULT_OK)
    {
        if (addr.addr_type != MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL);
        }
    }

    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_REPORT_BOX_OPTIONS);

    return num_item;

}
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_inbox_mms_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_inbox_mms_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 to_address_buffer[ /* MMA_MAX_ADDR_LEN */ 100] = {0x00, };
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    if (scr_info == NULL)
    {
        return MMI_UMMS_FALSE;
    }
    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

    mmi_umms_app_ui_callback_prop_view_lebel_decide(
        scr_info->is_already_viewed,
        0 /* scr_info->msg_info->media_type */ );
    if (scr_info->is_already_viewed)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }

    if (!mmi_ucs2ncmp((S8*) scr_info->msg_info->from_address, (S8*) to_address_buffer, /* MMA_MAX_ADDR_LEN */ 100))
    {
    #if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__))
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY);
    #endif 
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
    }

    if ((scr_info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER) &&
        (scr_info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL))
    {
    #if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__) ||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY);
    #endif 
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
    }

    if (scr_info->header_info)
    {
        if ((scr_info->header_info->to_num + scr_info->header_info->cc_num) < 2)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
        }
    }
    if (srv_mms_num_valid_sim() == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL_SENDER);
    }
    if (scr_info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
    {
    #if (defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__)||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTION_REPLY_SMS);
    #endif 

        mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL_SENDER);
        if (scr_info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
        }
    }
#ifndef __MMI_PHB_OPTIONAL_FIELD__
    if (scr_info->msg_info->from_address_type == MMA_ADDR_TYPE_EMAIL)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
    }
#endif /* (!defined(__MMI_PHB_OPTIONAL_FIELD__)) */ 

    if(srv_phb_check_number_exist((U16*) scr_info->msg_info->from_address))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
    }

    if (scr_info->msg_info->is_forward_lock ||
        (MMI_UMMS_LOCK_MODE_ON == scr_info->msg_info->is_lock_mode) ||
        ((scr_info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_FORWARD);
    }

    if (!scr_info->is_already_viewed)
    {
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
    }
    else if (scr_info->msg_info->is_forward_lock == KAL_TRUE)
    {
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
    }

    if (scr_info->msg_info->is_forward_lock == KAL_TRUE)
    {
    #ifndef __MMI_SLIM_MMS_2__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_UNLOCK);
    #endif /* __MMI_SLIM_MMS_2__ */ 
    }
    else
    {
    #ifndef __MMI_SLIM_MMS_2__
        if (MMI_UMMS_LOCK_MODE_ON == scr_info->msg_info->is_lock_mode)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_UNLOCK);
        }
    #endif /* __MMI_SLIM_MMS_2__ */ 

    }

    if (scr_info->is_already_viewed)
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif
    }


    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    }

#ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__

    if (!scr_info->is_already_viewed)

    {
        if (scr_info->msg_info->isRead == KAL_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
    }

#endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 
    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    }

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
    	mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    }

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    {
        mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

        if ((srv_mms_get_hs_event() == MMI_FALSE) || scr_info->is_already_viewed)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_ALL_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_GO_TO);
        }

        if (srv_mms_get_hs_active() == MMI_TRUE || srv_mms_get_hs_event() == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
     		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }

#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (scr_info->folder_id == MMA_FOLDER_ARCHIVE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    if ((srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND) ||
        (srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_SENDING) ||
        (srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND))
    {
        mmi_umms_app_ui_callback_move_copy_options_hide_all();
    }
    else
    {
        mmi_umms_app_ui_callback_move_copy_options_hide_unhide();
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    if (scr_info->is_already_viewed)
    {
        if (scr_info->msg_info->need_read_report)
        {
            mmi_umms_app_ui_callback_move_copy_options_hide_all();
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#ifdef __MMI_OP12_TOOLBAR__
    {
        mmi_umms_op_op12_struct *op_struct = mmi_umms_op_get_op12_data();

        if (op_struct->tb_active)
        {

            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
    		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* __MMI_OP12_TOOLBAR__ */ 

    if (srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);

    #ifdef __MMI_MMS_VOICE_MESSAGE_HANDLING__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
    #endif 

    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif 
    #ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
    #endif 
    #ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
    #endif 

    #ifdef __MMI_MMS2_MV_MANUAL_PLAY__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
    #endif /* __MMI_MMS2_MV_MANUAL_PLAY__ */ 

    #if (defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__) ||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTION_REPLY_SMS);
    #endif 
    #if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__) ||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY);
    #endif 
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL_SENDER);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_FORWARD);
    #ifndef __MMI_SLIM_MMS_2__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_UNLOCK);
    #endif /* __MMI_SLIM_MMS_2__ */ 
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
    #endif 
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
    #endif 
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
  		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    #endif 
    #ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
    #endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
        #endif
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
#endif
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */ 
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
    }
    else
    {
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
    }

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
        mmi_umms_op_op11_hs32_struct *op_data = mmi_umms_op_get_op11_hs32_data();

        if (op_data->hs_active == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

    return num_item;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_outbox_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_umms_app_ui_callback_download_options_decide(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__

    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt; 

#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);

#if (MMI_MAX_SIM_NUM >= 3) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM2);

    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM3);
#endif
#if (MMI_MAX_SIM_NUM >= 4) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM4);
#endif

    if (srv_mms_num_valid_sim() == 0)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if(srv_sim_ctrl_get_num_of_inserted() == 0)
        {
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD, MMI_TRUE);
        }
        else
#endif
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
        }

    #ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
    #endif

    }
    else
    {
        #if (MMI_MAX_SIM_NUM >= 3) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        if (!srv_mms_is_sim_valid(MMI_SIM1))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
        }
        if (!srv_mms_is_sim_valid(MMI_SIM2))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
        }
        
        if (!srv_mms_is_sim_valid(MMI_SIM3))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM3);
        }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        if (!srv_mms_is_sim_valid(MMI_SIM4))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM4);
        }
        #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_inbox_notification_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_inbox_notification_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    if (scr_info == NULL)
    {
        return MMI_UMMS_FALSE;
    }

    if (srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_NONE)
    {
    #ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
    #endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
    }


    switch (srv_mms_bgsr_get_msg_status(scr_info->msg_id))
    {
        case SRV_MMS_BGSR_STATUS_DOWNLOADING:
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
            break;
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
            break;
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
    #ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
    #endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
            break;
        default:
    #ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
    #endif 
            break;

    }

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    {
        mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

        if (srv_mms_get_hs_event() == MMI_FALSE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_ALL_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_GO_TO);
        }
        if (srv_mms_get_hs_active() == MMI_TRUE || srv_mms_get_hs_event() == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
    #endif 
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    #endif 
    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

#ifdef __MMI_OP12_TOOLBAR__
    {
        mmi_umms_op_op12_struct *op_struct = mmi_umms_op_get_op12_data();

        if (op_struct->tb_active)
        {

            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
     		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* __MMI_OP12_TOOLBAR__ */ 
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
        mmi_umms_op_op11_hs32_struct *op_data = mmi_umms_op_get_op11_hs32_data();

        if (op_data->hs_active == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else 
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION);
#endif 
    return num_item;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_inbox_java_mms_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_inbox_java_mms_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    {
        mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

        if (srv_mms_get_hs_event() == MMI_FALSE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_ALL_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_GO_TO);
        }
        if (srv_mms_get_hs_active() == MMI_TRUE || srv_mms_get_hs_event() == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
           mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
	 		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
    #endif 
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    #endif 
    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
#ifdef __MMI_OP12_TOOLBAR__
    {
        mmi_umms_op_op12_struct *op_struct = mmi_umms_op_get_op12_data();

        if (op_struct->tb_active)
        {

            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* __MMI_OP12_TOOLBAR__ */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
        mmi_umms_op_op11_hs32_struct *op_data = mmi_umms_op_get_op11_hs32_data();

        if (op_data->hs_active == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
           mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
	 		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else 
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS);
#endif 
    return num_item;
    /* Show All MMS Option */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_inbox_read_delivery_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_inbox_read_delivery_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 num_item = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

	//mmi_frm_get_active_scrn_id(&grp_id, &scrn_id);

	
		if(mmi_frm_scrn_is_present
             (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
             MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
		{
			if (scr_info->msg_info->is_read == KAL_TRUE)
			{
				mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
			}
		}
	
#ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__

    if (!mmi_frm_scrn_is_present
        (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
         MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        if (scr_info->msg_info->is_read == KAL_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
    }

#endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 

    if (mmi_frm_scrn_is_present
        (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
         MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    }


    if (mmi_frm_scrn_is_present
        (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
         MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif
    }
 

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

    if (mmi_frm_scrn_is_present
        (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
         MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
    	mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    }

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    {
        mmi_umms_op_op11_struct *op_data = mmi_umms_op_get_op11_data();

        if ((srv_mms_get_hs_event() == MMI_FALSE) ||
            (mmi_frm_scrn_is_present
             (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
              MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_CLEAR_ALL_EVENT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_HS_INBOX_GO_TO);
        }
        if (srv_mms_get_hs_active() == MMI_TRUE || srv_mms_get_hs_event() == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP12_TOOLBAR__
    {
        mmi_umms_op_op12_struct *op_struct = mmi_umms_op_get_op12_data();

        if (op_struct->tb_active)
        {

            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
            mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }
#endif /* __MMI_OP12_TOOLBAR__ */ 
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
        mmi_umms_op_op11_hs32_struct *op_data = mmi_umms_op_get_op11_hs32_data();

        if (op_data->hs_active == MMI_TRUE)
        {
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);

        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
           mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif

        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
			mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
        #endif 
        }
    }

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else 
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT);
#endif 

    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sent_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sent_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 num_item = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

    mmi_umms_app_ui_callback_prop_view_lebel_decide(scr_info->is_already_viewed, scr_info->msg_info->media_type);
    if (scr_info->is_already_viewed)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }

    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    }


    if (scr_info->is_already_viewed)
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif
    }


    if ((!scr_info->is_already_viewed) || (scr_info->msg_info->is_forward_lock == KAL_TRUE)
#ifdef __MMI_MMS_POSTCARD__
        || (scr_info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
#endif 
        )
    {
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
    }

    if (scr_info->msg_info->is_forward_lock == KAL_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);

    }

    if ((scr_info->msg_info->is_forward_lock)
#ifdef __MMI_MMS_POSTCARD__
        || (scr_info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
#endif 
        || ((scr_info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)
            && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_FORWARD);
    }

    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    }

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

    if (scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    }

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


    if (scr_info->is_already_viewed)
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
        #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
        #endif
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (scr_info->folder_id == MMA_FOLDER_ARCHIVE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    mmi_umms_app_ui_callback_move_copy_options_hide_unhide();
#endif 
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    if (!(scr_info->msg_info->need_delivery_report))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELIVERY_STATUS);
    }
    if (!(scr_info->msg_info->need_read_report))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_READ_STATUS);
    }
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_SENT_OPTIONS);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

    return num_item;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_outbox_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_umms_app_ui_callback_resend_options_decide(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__

    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt; 

#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(SCR_ID_UMMS_OUTBOX_OPTION);


#if((MMI_MAX_SIM_NUM == 2) || ((MMI_MAX_SIM_NUM >= 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)))
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM3);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM4);
#endif

    if (srv_mms_num_valid_sim() == 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM3);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM4);
#endif
    }
    else
    {
        if (!srv_mms_is_sim_valid(MMI_SIM1))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
        }
        if (!srv_mms_is_sim_valid(MMI_SIM2))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
        }
        #if (MMI_MAX_SIM_NUM >= 3)
        if (!srv_mms_is_sim_valid(MMI_SIM3))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM3);
        }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
        if (!srv_mms_is_sim_valid(MMI_SIM4))
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM4);
        }
        #endif

    }
#endif /* (MMI_MAX_SIM_NUM == 2) */ /* For hiding the arrow in the cascaded menu */

    if (srv_mms_num_valid_sim() == 0)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if(srv_sim_ctrl_get_num_of_inserted() == 0)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
    #if (MMI_MAX_SIM_NUM >= 3)
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
            mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM4);
    #endif
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_OPTIONS_RESEND, MMI_TRUE);
        }
        else
#endif
        {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_outbox_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_outbox_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 num_item = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

    mmi_umms_app_ui_callback_prop_view_lebel_decide(scr_info->is_already_viewed, scr_info->msg_info->media_type);
    if (scr_info->is_already_viewed && srv_mms_bgsr_get_sending_msg_id() != scr_info->msg_id)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }

#if(MMI_MAX_SIM_NUM == 2)
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM1);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_FROM_SIM2);

    if (srv_mms_num_valid_sim() == 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM1);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FROM_SIM2);
    }
#endif /* (MMI_MAX_SIM_NUM == 2) */ /* THINK THIS IS USELESS */

    if (srv_mms_num_valid_sim() == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
    }

    switch (srv_mms_bgsr_get_msg_status(scr_info->msg_id))
    {
        case SRV_MMS_BGSR_STATUS_SENDING:
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
            mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);

            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
            break;
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
            /* mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES); */
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
            break;
        default:
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
    #endif 
            break;
    }

    if ((scr_info->msg_info->is_forward_lock) ||
        ((scr_info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
    }
    /*
     * if (((scr_info->msg_info->msg_status == MMA_MSG_STATUS_WAITING_SENDING) ||
     * (scr_info->msg_info->msg_status == MMA_MSG_STATUS_SENDING)) &&
     * (srv_mms_bgsr_get_msg_status(scr_info->msg_id) != SRV_MMS_BGSR_STATUS_SENDING))
     * {
     * mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
     * }
     */
    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
    #endif 
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
   		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    #endif 
        if (srv_mms_bgsr_get_sending_msg_id() == scr_info->msg_id)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
        }
    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    if (scr_info->is_already_viewed)
    {
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
		mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);
    #endif 
        mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
    }


    if (scr_info->is_already_viewed)
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
        #endif /*__UNIFIED_MESSAGE_SORT_MESSAGE_LIST__*/
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
    }

    if (srv_mms_bgsr_get_msg_status(scr_info->msg_id) == SRV_MMS_BGSR_STATUS_NONE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
    }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_OUTBOX_OPTIONS);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return num_item;

}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_default_template_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_default_template_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 num_item = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

    mmi_umms_app_ui_callback_prop_view_lebel_decide(scr_info->is_already_viewed, scr_info->msg_info->media_type);

    if (scr_info->is_already_viewed)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);

    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
    }
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
    return num_item;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_user_defined_template_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_user_defined_template_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 num_item = 0;
    U8 template_type = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mmi_umms_app_ui_callback_prop_unhide_all_menu_options(scr_id);

    mmi_umms_app_ui_callback_prop_view_lebel_decide(scr_info->is_already_viewed, scr_info->msg_info->media_type);
    if (scr_info->is_already_viewed)
    {
        mmi_umms_app_ui_callback_save_objects_items_hide_unhide();
    }

    template_type = mmi_umms_app_dtmgr_get_current_template_type();
    if (template_type == MMI_UMMS_DEFAULT_TYPE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
    }
    else if (template_type == MMI_UMMS_USER_DEFINED_TYPE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE);
    }
    if (!scr_info->is_already_viewed)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
    }
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
    return num_item;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_prop_view_lebel_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  viewerOption        [IN]        
 *  msgType             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_view_lebel_decide(U16 viewerOption, U16 msgType)
{
#ifdef __MMI_MMS2_MV_MANUAL_PLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *desc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!viewerOption)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
        desc = srv_mms_get_desc_pointer();
        if (desc->body->curr_slide->slide_num == 1)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
        }
    }
#endif /* __MMI_MMS2_MV_MANUAL_PLAY__ */ 

#ifdef __MMI_MMS_VOICE_MESSAGE_HANDLING__
    if (!viewerOption)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
    }
    else
    {
        if (msgType == MMA_MEDIA_MSG_AUDIO)
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
        }
    }
#endif /* __MMI_MMS_VOICE_MESSAGE_HANDLING__ */ 

#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
    #endif 
    #ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
    #endif 
/* under construction !*/
#endif /* __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__ */ 

#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif 
    #ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
    #endif 
/* under construction !*/
#endif /* __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__ */ 
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif 
    #ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
    #endif 
/* under construction !*/
#endif /* __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__ */ 

#if (defined(__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__) || defined(__MMI_OP11_MMS_SUPPORT_PHOTO_MSG__) || defined(__MMI_OP11_MMS_SUPPORT_VIDEO_MSG__))
/* under construction !*/
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
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
/* under construction !*/
#endif /* (defined(__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__) || defined(__MMI_OP11_MMS_SUPPORT_PHOTO_MSG__) || defined(__MMI_OP11_MMS_SUPPORT_VIDEO_MSG__)) */ 
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_prop_hide_all_menu_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_hide_all_menu_options(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UNHIDE_ALL_MENU_OPTION);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
#ifdef __MMI_MMS_VOICE_MESSAGE_HANDLING__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
#endif 

#ifdef __MMI_MMS2_MV_MANUAL_PLAY__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
#endif /* __MMI_MMS2_MV_MANUAL_PLAY__ */ 
#ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
#endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 
#if (defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__) ||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTION_REPLY_SMS);
#endif 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__) ||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY);
#endif 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
#ifndef __MMI_SLIM_MMS_2__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_UNLOCK);
#endif /* __MMI_SLIM_MMS_2__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_FORWARD);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
    mmi_frm_hide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
#endif 

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UM_MS_OPT);
    mmi_frm_hide_menu_item(MENU_ID_UM_MS_DELETE_OPT);

#endif 
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
#endif 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
    mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
#endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_SEND);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE);
#endif
    mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL_SENDER);
    mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    mmi_frm_hide_menu_item(MENU_ID_UM_SORT_BY_OPT);
#endif 
    #ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_hide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_CALL);
#endif 
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_DELIVERY_STATUS);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_READ_STATUS);
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE);
    #endif
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE);
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
    #endif
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
    #endif
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
#endif
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_prop_unhide_all_menu_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_unhide_all_menu_options(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UNHIDE_ALL_MENU_OPTION);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_VIEW);
#ifdef __MMI_MMS_VOICE_MESSAGE_HANDLING__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
#endif 
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
#endif 

#ifdef __MMI_MMS2_MV_MANUAL_PLAY__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MANUAL_PLAY_VIEW_FROM_START);
#endif /* __MMI_MMS2_MV_MANUAL_PLAY__ */ 
#ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_READ);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTION_MARK_AS_UNREAD);
#endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 
#if (defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__)||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTION_REPLY_SMS);
#endif 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMS_STANDALONE_COMPOSER_SUPPORT__) || defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__)||  defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY);
#endif 
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_REPLY_ALL);
#ifndef __MMI_SLIM_MMS_2__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_LOCK);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_UNLOCK);
#endif /* __MMI_SLIM_MMS_2__ */ 
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_FORWARD);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_DELETE);
    mmi_frm_unhide_menu_item(MENU_ID_UM_DEL_ALL_OPT);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_ARCHIVE);
#endif 

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UM_MS_OPT);
    mmi_frm_unhide_menu_item(MENU_ID_UM_MS_DELETE_OPT);

#endif 
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_TO_TEMPLATE);
#endif 
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_PROPERTIES);
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_CANCEL_DOWNLOAD);
#endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS);
#endif
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_SEND);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_RESEND);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND);
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE);
#endif
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_CALL_SENDER);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_CONTACT);
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    mmi_frm_unhide_menu_item(MENU_ID_UM_SORT_BY_OPT);
#endif 
#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__ 
        mmi_frm_unhide_menu_item(MENU_ID_UM_FILTER_BY_OPT); 
    #endif
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_CALL);
#endif 
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_DELIVERY_STATUS);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_READ_STATUS);
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_progress_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_umms_app_ui_callback_get_progress_screen_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString(STR_GLOBAL_PLEASE_WAIT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_exit_viewer_application
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_exit_viewer_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OK, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_handle_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_handle_stop(void)
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
 *  mmi_umms_app_ui_plug_in_disable_icon_if_any
 * DESCRIPTION
 *  disable toolbar icon if any
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_app_common_action(wgui_mv_action_type action_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
	mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_MMS_VIEWER);
	mma_mms_object_struct *obj;
    mma_mms_slide_struct *current_slide;
    mma_mms_description_struct *desc;
	applib_mime_type_struct *type;
	S8 ext_gif[4] = { 'g', 'i', 'f', '\0' };
		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (action_type)
	{
		case WGUI_MV_DISABLE_ENABLE_ACTION :
		#ifdef __MMI_FTE_SUPPORT__
            #ifdef __MMI_ICON_BAR_SUPPORT__ 
    if (info->is_preview)
    {

    #ifndef __MMI_UMMS_PREVIEW_SEND__
        #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		if(info->open_mode == MMA_MODE_VIEW && viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW )
		{
         #endif
		if(viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
		{
        wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
		}

		#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		}
       #endif
	#else
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	if (srv_mms_num_valid_sim() == 0 &&  info->open_mode == MMA_MODE_VIEW && viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
				 {
					wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
					
				 }
	#else
		if(viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
		{
			if(srv_mms_is_resend_on(info->msg_id) == MMI_FALSE )
			 {
			   wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
		}
		}
	#endif
	#endif
       #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		if(info->open_mode == MMA_MODE_EDIT )
		{   
	    	 if(srv_mms_num_valid_sim() == 0)
			    {
                  wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
		        }
			 if(mmi_umms_app_ui_callback_decide_enable_disable_insert_tool())
			 {
                 wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
			 }
			 else
			 {
                  wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
			 }
			
		}
    #endif
		return MMI_FALSE;
	}
	 // on preview screen need to show tool which shall be enabled all time so no need to disable items in case of PLAY mode
	if(viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
	{
    switch (info->folder_id)
    {
        case MMA_FOLDER_INBOX:
            if (info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL
                && info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
				
            break;
        case MMA_FOLDER_DRAFT:
            if (info->msg_info->is_forward_lock == KAL_TRUE)
            {
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            break;
        case MMA_FOLDER_OUTBOX: 
              if(srv_mms_is_resend_on(info->msg_id) == MMI_FALSE )
			 {
			     wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
			 } 
			break ;
        case MMA_FOLDER_TEMPLATE:
        case MMA_FOLDER_USRDEF_TEMPLATE:
            if (info->msg_info->is_forward_lock == KAL_TRUE)
            {
                wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            }
            break;
        case MMA_FOLDER_SENT:
            if ((info->msg_info->is_forward_lock) || ((info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)))
            {
                mma_creation_mode_enum creation_mode;

                creation_mode = srv_mms_compose_settings_creation_mode();
                if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
                {
                    wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                }
            }

        #ifdef __MMI_MMS_POSTCARD__
            if (info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
            }
        #endif /* __MMI_MMS_POSTCARD__ */ 
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            switch (info->msg_info->prev_folder)
            {
                case MMA_FOLDER_INBOX:
                    if (info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL
                        && info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
                    {
                        wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                    }
                    break;
				case MMA_FOLDER_OUTBOX: 
				  if(srv_mms_is_resend_on(info->msg_id) == MMI_FALSE )
					 {
			    		 wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
					 } 
			       break ;
                case MMA_FOLDER_DRAFT:
                    if (info->msg_info->is_forward_lock == KAL_TRUE)
                    {
                        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
                    }
                    break;
                case MMA_FOLDER_TEMPLATE:
                case MMA_FOLDER_USRDEF_TEMPLATE:
                    if (info->msg_info->is_forward_lock == KAL_TRUE)
                    {
                        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
                    }
                    break;
                case MMA_FOLDER_SENT:
                    if ((info->msg_info->is_forward_lock) || ((info->msg_info->is_follow_phone_mms_content_class == KAL_FALSE)))
                    {
                        mma_creation_mode_enum creation_mode;

                        creation_mode = srv_mms_compose_settings_creation_mode();
                        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
                        {
                            wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                        }
                    }

                #ifdef __MMI_MMS_POSTCARD__
                    if (info->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
                    {
                        wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
                    }
                #endif /* __MMI_MMS_POSTCARD__ */ 
                    break;
            }
            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 

    }
}	        
#endif
#endif
  break ;
  case WGUI_MV_IMAGE_TYPE_ACTION :
            
		desc = srv_mms_get_desc_pointer();
		current_slide = desc->body->curr_slide; 
		if (current_slide->img.id)
		{
			obj = current_slide->img.object;
			type = applib_mime_get_file_type(obj->file_name_ucs);
			if (strncmp(ext_gif, type->file_ext, 4) == 0)
					{
						return MMI_FALSE ;
					}
			else
			{
				return MMI_TRUE ;
			}
		}
		return MMI_FALSE ;
  case WGUI_MV_STOP_IMAGE_DECODE_ACTION :
	  #ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
	     mmi_umms_app_dtmgr_stop_image_decode();
      #endif
	  break ;
            
}

return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_viewer_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_viewer_stop_callback(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL); */
#ifdef __MMI_MMS_AUTO_SWITCH_TO_FIRST_SLIDE__
    mma_mms_description_struct *desc = NULL;
#endif
    mmi_frm_scrn_enter(
        mmi_umms_dtmgr_get_group_id(),
        SCR_ID_UMMS_DUMMY,
        NULL,
        mmi_umms_app_dummy_entry_function,
        MMI_FRM_FG_ONLY_SCRN);
#ifdef __MMI_MMS_AUTO_SWITCH_TO_FIRST_SLIDE__
    desc = srv_mms_get_desc_pointer();
    if (desc->body->slide_no == desc->body->curr_slide->slide_num)
    {
        desc->body->curr_slide = desc->body->slides;
    }
#endif /* __MMI_MMS_AUTO_SWITCH_TO_FIRST_SLIDE__ */ 

    mmi_frm_scrn_close_active_id();
}

#ifdef __MMI_MSG_FTE_ENHANCE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_app_ui_callback_get_filename_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  set_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_app_app_ui_callback_get_filename_filepath(U16 **set_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    mma_mms_object_struct *med_obj = NULL;
    U16 *file_ext = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_get_med_object_from_current_slide(&med_obj);
    len = mmi_ucs2strlen((PS8) med_obj->file_name_ucs);
    if (len > SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        *set_name = (U16*) srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        ASSERT(*set_name);
        memset(*set_name, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (PS8) * set_name,
            (PS8) med_obj->file_name_ucs,
            SRV_FMGR_PATH_MAX_FILE_NAME_LEN - (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1));
        file_ext = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) med_obj->file_name_ucs);
        if (file_ext != NULL)
        {
            mmi_ucs2cat((S8*) * set_name, (S8*) L".");
            mmi_ucs2ncat((S8*) * set_name, (S8*) file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
    else
    {
        *set_name =
            (U16*) srv_mms_mem_mgr_app_adm_alloc(ENCODING_LENGTH +
                                                  (ENCODING_LENGTH * mmi_ucs2strlen((PS8) med_obj->file_name_ucs)));
        ASSERT(*set_name);
        mmi_ucs2cpy((PS8) * set_name, (PS8) med_obj->file_name_ucs);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_viewer_fte2_common_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_area      [IN]        
 *  touch area type : [IN]which element of viewer has been tapped(?)
 *  i.e.attachment icon, full scrn button(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_viewer_fte2_common_cb(U16 touch_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id imageviewer_id = GRP_ID_INVALID;
    PU16 file_name, file_path;
    U16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
    mma_mms_slide_struct *current_slide = NULL;
    mma_mms_description_struct *desc;

    desc = srv_mms_get_desc_pointer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (touch_area)
    {
        case WGUI_MV_TOUCH_AREA_ATTACHMENT:
            mmi_umms_app_if_show_save_objects_attchement_list();
            break;
        case WGUI_MV_TOUCH_AREA_TOGGLE_SCRN:
        {
            /* mmi_umms_app_ui_draw_viewer_toggle_screen(); */
        }
            return MMI_TRUE;
            break;
    #if defined(__MMI_IMAGE_VIEWER__)
        case WGUI_MV_TOUCH_AREA_IMG_HLITE:
        {
            S32 *parent_fh = mmi_umms_app_dtmgr_get_parent_file_hdl();

            imageviewer_id = cui_imgview_create(mmi_umms_dtmgr_get_group_id());
            current_slide = desc->body->curr_slide; /* srv_mms_viewer_get_current_slide(); */
            mmi_umms_app_app_ui_callback_get_filename_filepath(&file_name);
            srv_mms_get_filename_by_id(&(current_slide->img), vfname, &file_path, parent_fh);
            cui_imgview_set_mode_filename(imageviewer_id, (PS8) file_path);
            cui_imgview_set_title(imageviewer_id, file_name, IMG_ID_SRV_MMS_VIEWER_APP);
            cui_imgview_set_ui_direction(imageviewer_id, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
            cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_ALL, MMI_FALSE);
            cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_ZOOM, MMI_TRUE);
            cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_IMG_ROTATE, MMI_TRUE);
            cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_UI_ROTATE, MMI_TRUE);
            cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_TITLE, MMI_TRUE);

            cui_imgview_run(imageviewer_id);
            srv_mms_mem_mgr_app_adm_free(file_name);
        }
            break;
    #endif /* defined(__MMI_IMAGE_VIEWER__) */ 
    #if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)
        case WGUI_MV_TOUCH_AREA_VDO_HLITE:
        {
            S32 fmgr_type = 0;
            S32 *parent_fh = mmi_umms_app_dtmgr_get_parent_file_hdl();

            current_slide = desc->body->curr_slide;
            srv_mms_get_filename_by_id(&(current_slide->vid), vfname, &file_path, parent_fh);
            mmi_umms_app_app_ui_callback_get_filename_filepath(&file_name);
        #ifdef __MMI_VIDEO_STREAM__
            fmgr_type = srv_fmgr_types_find_type_by_filename_str((WCHAR*) file_path);
            if (fmgr_type == FMGR_TYPE_SDP)
            {
                mmi_media_app_play_stream_from_sdp_file_ext(file_path, FALSE, (PS8) file_name);
            }
            else if (fmgr_type == FMGR_TYPE_RAM)
            {
                mmi_media_app_play_stream_from_ram_file(file_path, FALSE);
            }
            else    /* other video type */
            {
                mmi_media_app_play_video_ext(file_path, FALSE, (PS8) file_name);
            }
        #else /* __MMI_VIDEO_STREAM__ */ 
            mmi_media_app_play_video_ext(file_path, FALSE, (PS8) file_name);
        #endif /* __MMI_VIDEO_STREAM__ */ 
            break;
        }
    #endif /* defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__) */ 
        case WGUI_MV_TOUCH_AREA_TXT_HLITE:
            break;
        case WGUI_MV_TOUCH_AREA_AUD_HLITE:
            break;
        default:
            break;
    }
}
#endif /* __MMI_MSG_FTE_ENHANCE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_viewer_mid_slides_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_viewer_mid_slides_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr = NULL;
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    viewer_scr = (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    ASSERT(viewer_scr);
    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
    {
        ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);

        if (option_scr_data->msg_info->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            SetKeyHandler(mmi_umms_app_ui_plug_in_call_sender_viewer, KEY_SEND, KEY_EVENT_DOWN);
        }
    }
    if (mmi_umms_app_dtmgr_check_use_details_for_viewer(scrDB->scrn_id))
    {
        StartTimer(
            MMS_VIEWER_TIMER,
            SRV_MMS_VIEWER_UNBLOCK_TIME,
            mmi_umms_app_ui_plug_in_viewer_handover_to_category);
    }
    else
    {
        mmi_umms_app_dtmgr_get_use_details_for_viewer(scrDB->scrn_id);
        viewer_scr->current_hilited = NULL;
        viewer_scr->list_head = NULL;
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, mmi_umms_app_ui_plug_in_viewer_handover_to_category);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_viewer_get_use_details_on_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_head       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_viewer_get_use_details_on_slide(srv_mms_viewer_use_details_list **list_head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    if (viewer_scr->current_hilited)
    {
        *list_head = viewer_scr->current_hilited;
    }
    else if (viewer_scr->list_head)
    {
        *list_head = viewer_scr->list_head;
    }
    else
    {
        *list_head = viewer_scr->list_head = mmi_umms_app_dtmgr_get_use_details_for_viewer(scrDB->scrn_id);
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    *list_head = NULL;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_filename_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media                       [?]         
 *  vf                          [IN]        
 *  file_path                   [?]         [?]
 *  vf_parent_file_handle       [IN]        
 *  id(?)                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_get_filename_by_id(
            mma_mms_slide_object_struct *media,
            PU16 vf,
            PU16 *file_path,
            PS32 vf_parent_file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_get_filename_by_id(media, vf, file_path, vf_parent_file_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_load_ucs2_txt_to_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_buffer             [IN]        
 *  dest_buffer_size        [IN]        
 *  media                   [?]         
 *  object_id(?)            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_load_ucs2_txt_to_buffer(
            PU8 dest_buffer,
            U32 dest_buffer_size,
            mma_mms_slide_text_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_viewer_load_ucs2_txt_to_buffer(dest_buffer, dest_buffer_size, media);
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_check_rights_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media       [?]         
 *  id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_check_rights_by_id(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_check_rights_by_id(media);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_start_consume_rights
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media               [?]         
 *  file_path           [IN]        
 *  object_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_start_consume_rights(mma_mms_slide_object_struct *media, PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = media->object;  /* srv_mms_viewer_get_objects_from_id(object_id) */
    srv_mms_rights_expiry_notify_cb func = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object != NULL)
    {
        switch (object->type)
        {
            case MMA_MMS_OBJECT_TYPE_IMAGE:
                func = mmi_umms_app_ui_callback_image_rights_expired;
                break;
            case MMA_MMS_OBJECT_TYPE_AUDIO:
                func = mmi_umms_app_ui_callback_audio_rights_expired;
                break;
            case MMA_MMS_OBJECT_TYPE_VIDEO:
                func = mmi_umms_app_ui_callback_video_rights_expired;
                break;
        }
    }
    return srv_mms_start_consume_rights(media, file_path, func, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_image_rights_expired
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_image_rights_expired(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category630ImageRightExpiredNotify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_audio_rights_expired
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_audio_rights_expired(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category630AudioRightExpiredNotify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_video_rights_expired
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_video_rights_expired(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category630VideoRightExpiredNotify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_stop_consume_rights
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media               [?]         
 *  object_id(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_stop_consume_rights(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_stop_consume_rights(media);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_update_rights_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media               [?]         
 *  rights_expired      [IN]        
 *  id(?)               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_update_rights_by_id(mma_mms_slide_object_struct *media, MMI_BOOL rights_expired)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_update_rights_by_id(media, rights_expired);
}
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_move_to_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_move_to_attachment(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    if (srv_mms_move_to_attachment(media))
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_UMMS_MOVE_TO_ATTACHMENT_ID), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
    }
    else
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_FAILED), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_allow_audio_playing
 * DESCRIPTION
 *  Callback to category
 * PARAMETERS
 *  void
 * RETURNS
 *  Allow or Disallow
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_allow_audio_playing(void)
{
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MMI_ALERT_TYPE alertType = GetMtCallAlertTypeEnum(); */
    srv_prof_alert_type_enum alertType;

    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, (void*)(&alertType));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((alertType != SRV_PROF_ALERT_TYPE_VIB_AND_RING && alertType != SRV_PROF_ALERT_TYPE_VIB_THEN_RING &&
         alertType != SRV_PROF_ALERT_TYPE_RING) ||
        !((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) ||
          (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
           srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0)) ||
        ((srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_SUCCESS) &&
         alertType == SRV_PROF_ALERT_TYPE_VIB_ONLY) ||
        (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_SUCCESS))
    {
        /* If the profile setting is meeting or silent  */
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CALLBACK_BLOCK_AUDIO);
        return MMI_FALSE;
    }

    return MMI_TRUE;
#else
	return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_best_page_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  playing_time        [IN]        
 *  slide_duration      [IN]        
 *  obj_start_time      [IN]        
 *  obj_end_time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_best_page_duration(
        U64 playing_time,
        kal_uint32 *slide_duration,
        kal_uint32 *obj_start_time,
        kal_uint32 *obj_end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_best_page_duration(playing_time, slide_duration, obj_start_time, obj_end_time);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_set_send_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_hilited     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_set_send_key(srv_mms_viewer_use_details_list *current_hilited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_frm_scrn_get_user_data(mmi_umms_dtmgr_get_group_id(), mmi_frm_scrn_get_active_id());
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scrDB->scrn_id);
    applib_address_node_struct *current_node = (applib_address_node_struct*) current_hilited->item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
    switch (current_node->dataType)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            if (srv_mms_num_valid_sim())
            {
                SetKeyHandler(viewer_scr->call_number, KEY_SEND, KEY_EVENT_DOWN);
            }
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            SetKeyHandler(viewer_scr->launch_email, KEY_SEND, KEY_EVENT_DOWN);
            break;
        case APPLIB_ADDR_TYPE_URL:
            SetKeyHandler(viewer_scr->launch_url, KEY_SEND, KEY_EVENT_DOWN);
            break;
        default:
            ASSERT(0);
    }
}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_recipient_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_recipient_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_header_struct *header;
    mmi_umms_app_ui_draw_dynamic_screen_struct *use_detail_scr;
    S16 count = 0;
    S32 len = 0;
    mma_mms_addr_list_struct *current = NULL;
    U16 temp_addr[MAX_SUB_MENU_SIZE] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = srv_mms_container_get_header();
    use_detail_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_ADD_RECIPIENT);
    /* This is important */
    /* Address will always be in UTF-8 */
    switch (use_detail_scr->highlighted_menu)
    {
        case MENU_ID_UMMS_ADD_RECIPIENT_TO:
            current = header->to;
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_ADD_RECIPIENT_CC:
            current = header->cc;
            break;
        case MENU_ID_UMMS_ADD_RECIPIENT_BCC:
            current = header->bcc;
            break;
#endif

    }
    while (current && count != item_index)
    {
        current = current->next;
        count++;
    }
    ASSERT(current);
    while (current && count < (num_item + item_index))
    {
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) temp_addr,
                MAX_SUB_MENU_SIZE,
                (kal_uint8*) current->address);
        if (!srv_phb_get_name_by_number
            ((U16*) temp_addr, (U16*) menuData[count - item_index].item_list[0], MAX_SUB_MENU_SIZE) ||
            !mmi_ucs2strlen((S8*) menuData[count - item_index].item_list[0]))
        {
            mmi_ucs2cpy((S8*) menuData[count - item_index].item_list[0], (S8*) temp_addr);
            if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
            {
                /* No Need */
            }
            else
            {
                mmi_ucs2cat((S8*) menuData[count - item_index].item_list[0], (S8*) L"...");
            }
        }

        menuData[count - item_index].image_list[0] = wgui_get_list_menu_icon(count,0);

		//menuData[index].image_list[0] = wgui_get_list_menu_icon(cur_index,0);

        current = current->next;
        count++;
    }
    return num_item;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_address_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  menuData        [?]         [?]
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_address_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    return mmi_umms_app_dtmgr_get_use_details_aysnc(item_index, menuData, num_item);
#else 
    return NULL;
#endif 
}

#ifdef __MMI_MMS_PREVIEW_GOTO__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_slide_list
 * DESCRIPTION
 *  get item callback for category262
 * PARAMETERS
 *  item_index      [IN]        
 *  menuData        [OUT]       
 *  num_item        [IN]        
 * RETURNS
 *  num item
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_slide_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_UMMS_INDEX_STR_LEN 5
    U16 temp[MMI_UMMS_INDEX_STR_LEN];
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i)
    {
        menuData[i].image_list[0] = get_image(IMG_ID_UMMS_SLIDE_LIST);
        memset(temp, 0, MMI_UMMS_INDEX_STR_LEN);
        kal_wsprintf(temp, " %d", i + 1 + item_index);
        mmi_ucs2ncpy((PS8) menuData[i].item_list[0], (PS8) GetString(STR_GLOBAL_PREVIEW), MAX_SUB_MENU_SIZE);
        mmi_ucs2ncat((PS8) menuData[i].item_list[0], (PS8) temp, MMI_UMMS_INDEX_STR_LEN);
    }
    return num_item;
}
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
/*****************************Niraj Added*****************************************/

/*********common settings**********/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_no_of_items_general
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_no_of_items_general(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nNumofItem;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scrn_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nNumofItem = GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
    return nNumofItem;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_message_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_message_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //U16 str_item_list[MAX_SUB_MENUS]; /* Stores the strings id of submenus returned */
    //mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    GetSequenceStringIds(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_message_menu_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_message_menu_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}

/**************************mms common settings*******************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_message_settings_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_mms_message_settings_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_message_settings_menu_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_mms_message_settings_menu_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}

/*****************************compose settings***********************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_settings_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_id      [IN]        
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_settings_item_list(mmi_id grp_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*)
        mmi_umms_app_dtmgr_get_compose_settings_inline_item_list(mmi_umms_app_ui_plug_in_get_change_in_compose_signature
                                                                 ());

    if (!mmi_frm_is_in_backward_scenario())
    {
        mmi_umms_app_ui_plug_in_check_and_update_signature_file_info_first();
    }
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_DEFAULT_SLIDE_TIME,
        (void*)(compose_settings_inline_items->defualt_slide_time_buffer));
#ifdef __LAYOUT_SUPPORT__
    cui_inline_set_value(grp_id, E_COMPOSE_LAYOUT, (void*)(compose_settings_inline_items->layout));
#endif 
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    cui_inline_set_value(grp_id, E_COMPOSE_ADD_DRM, (void*)(compose_settings_inline_items->add_drm));
#endif 
#endif /* __DRM_SUPPORT__ */ 
    cui_inline_set_value(grp_id, E_COMPOSE_CREATION_MODES, (void*)(compose_settings_inline_items->creation_mode));
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_IMAGE_RESIZING,
        (void*)(compose_settings_inline_items->image_resize_option));
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
#ifdef __MAX_PAGE_SUPPORTED__
    cui_inline_set_value(grp_id, E_COMPOSE_MAX_NO_PAGES, (void*)(compose_settings_inline_items->max_num_pages_buffer));
#endif 
#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_BEST_PAGE_DURATION,
        (void*)(compose_settings_inline_items->best_page_duration));
#endif /* __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__ */ 
#ifdef __MMI_MMS_SIGNATURE__
    cui_inline_set_value(grp_id, E_COMPOSE_AUTO_SIGNATURE, (void*)(compose_settings_inline_items->auto_signature));
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_settings_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_settings_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count];
#ifdef __LAYOUT_SUPPORT__
    image_list[E_COMPOSE_LAYOUT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    image_list[E_COMPOSE_ADD_DRM_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
#endif /* __DRM_SUPPORT__ */ 
    image_list[E_COMPOSE_CREATION_MODES_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    image_list[E_COMPOSE_IMAGE_RESIZE_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
#ifdef __MAX_PAGE_SUPPORTED__
    image_list[E_COMPOSE_MAX_NO_PAGES_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    image_list[E_COMPOSE_BEST_PAGE_DURATION_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
#ifdef __MMI_MMS_SIGNATURE__
    image_list[E_COMPOSE_AUTO_SIGNATURE_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_AUTO_SIGNATURE_CONTENT - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];;
#endif /* __MMI_MMS_SIGNATURE__ */ 

}

/******************retrieval settings***********************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_retrieval_settings_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_retrieval_settings_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
    if (srv_nw_info_is_roaming(MMI_SIM1) == TRUE)
    {
        image_list[E_RETRIEVAL_HOME_NETWORK_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_ROAMING_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_FILTERS_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_READ_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
    }
    else
    {
        /* *number_of_items = (*number_of_items) - 2; */
        image_list[E_RETRIEVAL_HOME_NETWORK_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_FILTERS_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_READ_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
        image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];

    }
#else /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
    image_list[E_RETRIEVAL_HOME_NETWORK_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_ROAMING_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_FILTERS_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_READ_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[index++];

#endif /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 

}

/********************retrieval filter settings******************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_retrieval_filters_settings_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_id      [IN]        
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_retrieval_filters_settings_item_list(U16 grp_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    umms_inline_retrieval_items_struct *retrieval_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retrieval_settings_inline_items =
        (umms_inline_retrieval_items_struct*)
        mmi_umms_app_dtmgr_get_retrieval_settings_inline_item_list(mmi_umms_get_app_ui_plug_in_change_in_filters());

    cui_inline_set_value(
        grp_id,
        E_RETRIEVAL_FILTERS_ANONYMOUS,
        (void*)(retrieval_settings_inline_items->anonymous_filter));
    cui_inline_set_value(
        grp_id,
        E_RETRIEVAL_FILTERS_ADVERTISEMENT,
        (void*)(retrieval_settings_inline_items->advertisement_filter));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_retrieval_filters_settings_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_retrieval_filters_settings_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#ifndef __MMI_MMS_OMA_CONF_273__
    image_list[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#else /* __MMI_MMS_OMA_CONF_273__ */ 
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#endif /* __MMI_MMS_OMA_CONF_273__ */ 

    /* return image_list; */

}

/*************************sendingsettings***********************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sending_settings_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_sending_settings_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
    image_list[E_SENDING_VALIDITY_PERIOD_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#endif 
    image_list[E_SENDING_DELIVERY_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count];
    image_list[E_SENDING_READ_REPORT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
    image_list[E_SENDING_PRIORITY_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
    image_list[E_SENDING_DELIVERY_TIME_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
    image_list[E_SENDING_HIDE_SENDER_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 
    image_list[E_SENDING_SEND_AND_SAVE_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    image_list[E_SENDING_SIZE_LIMIT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[++count];
#endif 

    /* return image_list; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sending_settings_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_id      [IN]        
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_sending_settings_item_list(U16 grp_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_sending_items_struct *sending_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sending_settings_inline_items =
        (umms_inline_sending_items_struct*) mmi_umms_app_dtmgr_get_sending_settings_inline_item_list(0);

#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
    cui_inline_set_value(grp_id, E_SENDING_VALIDITY_PERIOD, (void*)(sending_settings_inline_items->validity_period));
#endif 

    cui_inline_set_value(grp_id, E_SENDING_DELIVERY_REPORT, (void*)(sending_settings_inline_items->delivery_report));

    cui_inline_set_value(grp_id, E_SENDING_READ_REPORT, (void*)(sending_settings_inline_items->read_report));

    cui_inline_set_value(grp_id, E_SENDING_PRIORITY, (void*)(sending_settings_inline_items->priority));

    cui_inline_set_value(grp_id, E_SENDING_DELIVERY_TIME, (void*)(sending_settings_inline_items->delivery_time));
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
    cui_inline_set_value(grp_id, E_SENDING_HIDE_SENDER, (void*)(sending_settings_inline_items->hide_sender));
#endif 
    /* send and save start */
    cui_inline_set_value(grp_id, E_SENDING_SEND_AND_SAVE, (void*)(sending_settings_inline_items->send_and_save));

    /* send and save ends */
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    cui_inline_set_value(grp_id, E_SENDING_SIZE_LIMIT, (void*)(sending_settings_inline_items->size));
#endif 
}

/*****************compose signature settings************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_signature_settings_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_id      [IN]        
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_signature_settings_item_list(U16 grp_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    umms_inline_compose_items_struct *compose_settings_inline_items_sig;

#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    S8 tmp_str[UMMS_CONVERT_INDEX] = {0, };
#endif 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    /* S8 *image_path; */
#endif 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    S8 *audio_path = NULL;
#endif 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    /* S8 *video_path; */
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items_sig =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    /* image_path = mmi_umms_app_dtmgr_get_signature_image_disp_path(); */
#endif 

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    audio_path = mmi_umms_app_dtmgr_get_signature_audio_disp_path();
#endif 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    /* video_path = mmi_umms_app_dtmgr_get_signature_video_disp_path(); */
#endif 
    /* text */
    /* mmi_umms_update_file_information(); */

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_image_file))
    {
		FS_HANDLE fh = 0;

        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_image_file, FS_READ_ONLY);
            if (fh < 0)
            {
                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;

            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
    }
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_video_file))
    {
		FS_HANDLE fh = 0;
        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_video_file, FS_READ_ONLY);
            if (fh < 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_VIDEO_NOT);

                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;

    }
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_audio_file))
    {
		FS_HANDLE fh = 0;
        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_audio_file, FS_READ_ONLY);
            if (fh < 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_AUDIO_NOT);

                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED;

            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#ifdef __MMI_MMS_SIGNATURE__
    if ((compose_settings_inline_items_sig->auto_signature == E_ON)
        &&
        (mmi_ucs2ncmp
         ((S8*) compose_settings_inline_items_sig->auto_signature_content, "\0",
          UMMS_MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0)
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        )
    {

        // g_compose_signature_done = E_ON; 
        //g_umms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
        compose_settings_inline_items_sig->auto_signature = (U8) E_OFF;

    }
#endif /* __MMI_MMS_SIGNATURE__ */ 
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_SIGNATURE_TEXT,
        (void*)(compose_settings_inline_items_sig->auto_signature_content));
    cui_inline_set_fullscreen_edit_title_icon(
        grp_id,
        E_COMPOSE_SIGNATURE_TEXT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    /*  if (image_path != NULL)
       {
       srv_mms_mem_mgr_app_adm_free(image_path);
       mmi_umms_app_dtmgr_set_signature_image_disp_path(NULL);
       }
       
       image_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
       MMI_ASSERT(image_path != NULL);
       mmi_umms_app_dtmgr_set_signature_image_disp_path(image_path); */
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
           image_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) compose_settings_inline_items_sig->auto_signature_image_file);
        }
    #endif /* (!defined(__MMI_SHOW_FILE_EXT__)) */ 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */

    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_SIGNATURE_IMAGE,
        (void*)(compose_settings_inline_items_sig->auto_signature_image_file));
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    /* Video */
    /* if (video_path != NULL)
       {
       srv_mms_mem_mgr_app_adm_free(video_path);
       mmi_umms_app_dtmgr_set_signature_video_disp_path(NULL);
       }
       video_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
       MMI_ASSERT(video_path != NULL);
       mmi_umms_app_dtmgr_set_signature_video_disp_path(video_path); */
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
           video_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) compose_settings_inline_items_sig->auto_signature_video_file);
        }
    #endif /* (!defined(__MMI_SHOW_FILE_EXT__)) */ 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    cui_inline_set_value(
        grp_id,
        E_COMPOSE_SIGNATURE_VIDEO,
        (void*)(compose_settings_inline_items_sig->auto_signature_video_file));
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ /* _MMI_MMS_VIDEO_FEATURE__ */

    /* Audio */
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (audio_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(audio_path);
        mmi_umms_app_dtmgr_set_signature_audio_disp_path(NULL);
    }
    audio_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
    MMI_ASSERT(audio_path != NULL);
    memset(audio_path, 0, MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
    mmi_umms_app_dtmgr_set_signature_audio_disp_path(audio_path);
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
           audio_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
        mmi_ucs2cpy((S8*) audio_path, (S8*) compose_settings_inline_items_sig->auto_signature_audio_file);
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) audio_path);
        }

    #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
        {
            PS8 ext_name;
            S8 mp3_ext[] = { 'm', 0, 'p', 0, '3', 0, 0, 0};
            S8 mp2_ext[] = { 'm', 0, 'p', 0, '2', 0, 0, 0};
            ext_name = (S8*) srv_fmgr_path_get_extension_ptr((WCHAR*) audio_path);
            if (ext_name == NULL)
                EXT_ASSERT(0, 0, 0, 0);

            if ((mmi_ucs2cmp(ext_name, mp3_ext) == 0) || (mmi_ucs2cmp(ext_name, mp2_ext) == 0))
            {
                srv_fmgr_path_hide_extension((WCHAR*) audio_path);

            }
        }
    #endif 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */

    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        mmi_ucs2cpy((S8*) audio_path, (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    cui_inline_set_value(grp_id, E_COMPOSE_SIGNATURE_AUDIO, (void*)(audio_path));
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_signature_settings_set_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_signature_settings_set_flag(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    S8 tmp_str[UMMS_CONVERT_INDEX] = {0, };
#endif 

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    S8 *audio_path = NULL;
#endif 

#ifdef __MMI_MMS_SIGNATURE__
    umms_inline_compose_items_struct *compose_settings_inline_items_sig;

	compose_settings_inline_items_sig =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    audio_path = mmi_umms_app_dtmgr_get_signature_audio_disp_path();
#endif 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_image_file))
    {
		FS_HANDLE fh = 0;
        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_image_file, FS_READ_ONLY);
            if (fh < 0)
            {
                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;

            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
    }
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_video_file))
    {
		FS_HANDLE fh = 0;
        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_video_file, FS_READ_ONLY);
            if (fh < 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_VIDEO_NOT);

                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;

    }
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (mmi_ucs2strlen((S8*) compose_settings_inline_items_sig->auto_signature_audio_file))
    {
		FS_HANDLE fh = 0;
        if (mmi_ucs2cmp(
                (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
            fh = FS_Open((U16*) compose_settings_inline_items_sig->auto_signature_audio_file, FS_READ_ONLY);
            if (fh < 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_AUDIO_NOT);

                mmi_ucs2cpy(
                    (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
                compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED;

            }
            else
            {
                compose_settings_inline_items_sig->signature_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
            }
            FS_Close(fh);
        }
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        compose_settings_inline_items_sig->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#ifdef __MMI_MMS_SIGNATURE__
    if ((compose_settings_inline_items_sig->auto_signature == E_ON)
        &&
        (mmi_ucs2ncmp
         ((S8*) compose_settings_inline_items_sig->auto_signature_content, "\0",
          UMMS_MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0)
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_image_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items_sig->auto_signature_video_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        )
    {

        // g_compose_signature_done = E_ON; 
        //g_umms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
        compose_settings_inline_items_sig->auto_signature = (U8) E_OFF;

    }
#endif /* __MMI_MMS_SIGNATURE__ */ 
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
           image_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) compose_settings_inline_items_sig->auto_signature_image_file);
        }
    #endif /* (!defined(__MMI_SHOW_FILE_EXT__)) */ 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */

    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    /* cui_inline_set_value(grp_id, E_COMPOSE_SIGNATURE_IMAGE, (void *)(compose_settings_inline_items_sig->auto_signature_image_file)); */
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    /* Video */
    /* if (video_path != NULL)
       {
       srv_mms_mem_mgr_app_adm_free(video_path);
       mmi_umms_app_dtmgr_set_signature_video_disp_path(NULL);
       }
       video_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
       MMI_ASSERT(video_path != NULL);
       mmi_umms_app_dtmgr_set_signature_video_disp_path(video_path); */
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
           video_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) compose_settings_inline_items_sig->auto_signature_video_file);
        }
    #endif /* (!defined(__MMI_SHOW_FILE_EXT__)) */ 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    /* cui_inline_set_value(grp_id, E_COMPOSE_SIGNATURE_VIDEO, (void *)(compose_settings_inline_items_sig->auto_signature_video_file)); */
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ /* _MMI_MMS_VIDEO_FEATURE__ */

    /* Audio */
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (audio_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(audio_path);
        mmi_umms_app_dtmgr_set_signature_audio_disp_path(NULL);
    }
    audio_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
    MMI_ASSERT(audio_path != NULL);
    memset(audio_path, 0, MMA_MAX_EXTERNAL_FILE_PATH_LEN * ENCODING_LENGTH);
    mmi_umms_app_dtmgr_set_signature_audio_disp_path(audio_path);
    if (mmi_ucs2cmp(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        /* fs_ret = mmi_fmgr_util_get_filepath_display_name(
           (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
           audio_path,
           MMA_MAX_EXTERNAL_FILE_PATH_LEN);
           if (fs_ret >= 0)
           { */
        mmi_ucs2cpy((S8*) audio_path, (S8*) compose_settings_inline_items_sig->auto_signature_audio_file);
    #if (!defined(__MMI_SHOW_FILE_EXT__))
        {
            srv_fmgr_path_hide_extension((WCHAR*) audio_path);
        }

    #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
        {
            PS8 ext_name;
            S8 mp3_ext[] = { 'm', 0, 'p', 0, '3', 0, 0, 0};
            S8 mp2_ext[] = { 'm', 0, 'p', 0, '2', 0, 0, 0};
            ext_name = (S8*) srv_fmgr_path_get_extension_ptr((WCHAR*) audio_path);
            ASSERT(ext_name);
            if ((mmi_ucs2cmp(ext_name, mp3_ext) == 0) || (mmi_ucs2cmp(ext_name, mp2_ext) == 0))
            {
                srv_fmgr_path_hide_extension((WCHAR*) audio_path);

            }
        }
    #endif 

        /* }
           else
           {
           MMI_ASSERT(fs_ret);
           } */

    }
    else
    {
        mmi_ucs2cpy(
            (S8*) compose_settings_inline_items_sig->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        mmi_ucs2cpy((S8*) audio_path, (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
    }
    /* cui_inline_set_value(grp_id, E_COMPOSE_SIGNATURE_AUDIO, (void *)(audio_path)); */
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_signature_objects_remove_confirmation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_signature_objects_remove_confirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_MMS_2__
    U32 selected_mms_size = 0;
#endif
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_MMS_2__
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    selected_mms_size = srv_mms_sending_mms_size_limit();
#else 
    selected_mms_size = wap_custom_get_max_mms_msg_size();
#endif 

    if (MMA_SETTING_SIZE_LIMIT_100 == selected_mms_size)
    {
        str_id = STR_ID_UMMS_SIGNATURE_SIZE_EXCEEDS_LIMIT_100K;
    }
    if (MMA_SETTING_SIZE_LIMIT_300 == selected_mms_size)
    {
        str_id = STR_ID_UMMS_SIGNATURE_SIZE_EXCEEDS_LIMIT_300K;
    }
    if (MMA_SETTING_SIZE_LIMIT_600 == selected_mms_size)
    {
        str_id = STR_ID_UMMS_SIGNATURE_SIZE_EXCEEDS_LIMIT_600K;
    }
#endif /* __MMI_SLIM_MMS_2__ */ 

    mmi_umms_app_dtmgr_set_confirm_screen_para(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U16*) GetString(str_id),
        MMI_EVENT_QUERY,
        MMI_FALSE,
        MMI_FALSE,
        mmi_umms_app_ui_plug_in_lsk_funct_pre_signature_restricted,
        mmi_umms_app_if_show_compose_signature_settings_menu,
        NULL,
        NULL);
    mmi_umms_app_if_show_display_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_signature_objects_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_signature_objects_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__)
    srv_mms_nvram_compose_settings_struct *nvram_compose_items_list;
    umms_inline_compose_items_struct *compose_settings_inline_settings;

	compose_settings_inline_settings =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

	nvram_compose_items_list = (srv_mms_nvram_compose_settings_struct*) srv_mms_get_nvram_compose_settings();
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    if (compose_settings_inline_settings->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_VIDEO_NOT);

        mmi_ucs2cpy(
            (S8*) compose_settings_inline_settings->auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        memset(
            nvram_compose_items_list->auto_signature_video_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects(E_ON);

        compose_settings_inline_settings->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
    }
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (compose_settings_inline_settings->signature_flag & UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_IMAGE_NOT);

        mmi_ucs2cpy(
            (S8*) compose_settings_inline_settings->auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        memset(
            nvram_compose_items_list->auto_signature_image_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects(E_ON);

        compose_settings_inline_settings->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
    }
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__

    if (compose_settings_inline_settings->
        signature_flag & (UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED | UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED))
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_AUDIO_NOT);

        mmi_ucs2cpy(
            (S8*) compose_settings_inline_settings->auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
        memset(
            nvram_compose_items_list->auto_signature_audio_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects(E_ON);

        compose_settings_inline_settings->signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

    if (mmi_umms_app_dtmgr_get_flag_for_signature_remove_objects())
    {
        mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_signature_settings_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_signature_settings_list_of_icon(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[E_COMPOSE_SIGNATURE_TEXT_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    image_list[E_COMPOSE_SIGNATURE_IMAGE_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#endif 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    image_list[E_COMPOSE_SIGNATURE_VIDEO_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#endif 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    image_list[E_COMPOSE_SIGNATURE_AUDIO_CAPTION - CUI_INLINE_ITEM_ID_BASE] = gIndexIconsImageList[count++];
#endif 

    /* return image_list; */

}

/*********************signature options**********************/

#ifdef __MMI_MMS_SIGNATURE__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_signature_options_get_no_of_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_signature_options_get_no_of_items(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    BOOL file_exist = FALSE;
    U16 signature_hilighter = 0;
    umms_inline_compose_items_struct *compose_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_reset_buffer_for_signature();
    signature_hilighter = mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature();
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    switch (signature_hilighter)
    {
    #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        case E_COMPOSE_SIGNATURE_IMAGE:
            if (mmi_ucs2cmp(
                    (S8*) compose_settings_inline_items->auto_signature_image_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
            {
                file_exist = TRUE;
            }
            break;
    #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        case E_COMPOSE_SIGNATURE_AUDIO:
            if (mmi_ucs2cmp(
                    (S8*) compose_settings_inline_items->auto_signature_audio_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
            {
                file_exist = TRUE;
            }

            break;
        #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        case E_COMPOSE_SIGNATURE_VIDEO:
            if (mmi_ucs2cmp(
                    (S8*) compose_settings_inline_items->auto_signature_video_file,
                    (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
            {
                file_exist = TRUE;
            }

            break;
        #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        default:
            break;
    }
    mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW);

    if (file_exist == FALSE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_DELETE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_DELETE);
    }

    return GetNumOfChild_Ext(MENU_ID_UMMS_SIGNATURE_OPTION);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_signature_options_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_signature_options_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_signature_options_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_signature_options_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}
#endif
/****************************Amit added*******************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_memory_status_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_memory_status_get_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 tempBuf[100];        /* UMMS_MEMORY_STATUS_TEMP_BUF]; */
    S8 tempBufUnicode[200]; /* UMMS_MEMORY_STATUS_TEMP_BUF * ENCODING_LENGTH]; */
    S8 spaceBuf[100];       /* UMMS_MEMORY_STATUS_TEMP_BUF]; */

    U64 size_available = 0;
    U32 used_bytes = 0;
    U64 size_kb_free = 0;
    U64 size_bytes_free = 0;
    U32 size_kb_used = 0;
    U32 size_bytes_used = 0;

    U32 total_msg = 0;

#ifdef __OP01_0203__
    U32 total_mem_kb = 0;
    U32 total_mem_bytes = 0;
#endif /* __OP01_0203__ */ 
    /* S8 memoryStatus[UMMS_MEMORY_STATUS_MAX_LENGTH * ENCODING_LENGTH]; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));

    mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_MESSAGE_STATUS_TOTAL));
    memset(spaceBuf, 0, 100);
    mmi_asc_to_ucs2(spaceBuf, " ");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    if (scr_id == SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD)
    {
        total_msg = srv_mms_get_mem_card_total_msg();
        sprintf(tempBuf, "%d/%d", total_msg, wap_custom_get_max_mms_num_on_card());
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_asc_to_ucs2(spaceBuf, "\n");
        mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        total_msg = srv_mms_get_phone_mem_total_msg();
        sprintf(tempBuf, "%d/%d", total_msg, wap_custom_get_max_mms_num() - 1);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_asc_to_ucs2(spaceBuf, "\n");
        mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    }

    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_MESSAGE_STATUS_USAGE));
    memset(spaceBuf, 0, 100);
    mmi_asc_to_ucs2(spaceBuf, " ");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

    /* Added a New line after "Used Space:" */
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);

    memset(spaceBuf, 0, 100);

    memset(tempBuf, 0, 100);
    memset(tempBufUnicode, 0, 100 * ENCODING_LENGTH);

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    if (scr_id == SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD)
    {
        size_available = mma_get_mms_avaliable_file_space(&used_bytes, MMA_MSG_STORAGE_CARD1);
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        size_available = mma_get_mms_avaliable_file_space(&used_bytes, MMA_MSG_STORAGE_PHONE);
    }
    size_kb_used = used_bytes / 1024;
    size_bytes_used = used_bytes % 1024;

    if (size_kb_used >= 1)
    {
        if (size_bytes_used > 512)
        {
            size_kb_used++;
        }
        sprintf(tempBuf, "%d ", size_kb_used);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

    }
    else
    {
        sprintf(tempBuf, "%d ", size_bytes_used);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));

    }

    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_FREE_SPACE));
    memset(spaceBuf, 0, 100);
    mmi_asc_to_ucs2(spaceBuf, " ");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

    /* Added a New line after "Free Space:" */
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

    memset(tempBuf, 0, 100);
    memset(tempBufUnicode, 0, 100 * ENCODING_LENGTH);
    size_kb_free = size_available / 1024;
    size_bytes_free = size_available % 1024;
    if (size_kb_free >= 1)
    {
        if (size_bytes_free > 512)
        {
            size_kb_free++;
        }
        sprintf(tempBuf, "%llu ", size_kb_free);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

    }
    else
    {
        sprintf(tempBuf, "%llu ", size_bytes_free);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));

    }

#ifdef __OP01_0203__
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_TOTAL_SPACE));
    memset(spaceBuf, 0, 100);
    mmi_asc_to_ucs2(spaceBuf, " ");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

    /* Added a New line after "Total Space:" */
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat((S8*) subMenuData, spaceBuf);
    memset(spaceBuf, 0, 100);

    memset(tempBuf, 0, 100);
    memset(tempBufUnicode, 0, 100 * ENCODING_LENGTH);

    if ((size_kb_free >= 1) && (size_kb_used >= 1))
    {
        total_mem_kb = size_kb_free + size_kb_used;
    }
    else if ((size_kb_free >= 1) && (size_kb_used == 0))
    {
        total_mem_kb = size_kb_free;
        if (size_bytes_used > 512)
        {
            total_mem_kb++;
        }
    }
    else if ((size_kb_free == 0) && (size_kb_used >= 1))
    {
        total_mem_kb = size_kb_used;
        if (size_bytes_free > 512)
        {
            total_mem_kb++;
        }
    }
    else if ((size_kb_free == 0) && (size_kb_used == 0))
    {
        total_mem_bytes = size_bytes_free + size_bytes_used;
        if (total_mem_bytes > (512 + 1024))
        {
            total_mem_kb += 2;
        }
        else if (total_mem_bytes > 512)
        {
            total_mem_kb++;
        }
    }

    if (total_mem_kb >= 1)
    {
        sprintf(tempBuf, "%d ", total_mem_kb);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));
    }
    else
    {
        sprintf(tempBuf, "%d ", total_mem_bytes);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((S8*) subMenuData, tempBufUnicode);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));
    }
#endif /* __OP01_0203__ */ 

    memset(spaceBuf, 0, 100);
    memset(tempBuf, 0, 100);
    memset(tempBufUnicode, 0, 100 * ENCODING_LENGTH);

    return (U8*) subMenuData;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_selection_profile_menu_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sim_selection_profile_menu_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_selection_profile_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_sim_selection_profile_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_save_objects_attachment_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_save_objects_attachment_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_attachment_info_struct *attachment_list = NULL;
    U32 num_attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_get_attachment_list(&attachment_list, &num_attachment);
    return num_attachment;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_attachment_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  menuData            [?]         [?]
 *  num_attachment      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_get_attachment_data(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_attachment)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_attach = 0;
    S32 count = 0;
    S32 len = 0;
    mma_mms_attachment_info_struct *attach_list = NULL;
    mma_mms_attachment_info_struct *temp_list = NULL;
    BOOL extRemoved = FALSE;
    S8 mp3_ext[] = { 'm', 0, 'p', 0, '3', 0, 0, 0};
    S8 mp2_ext[] = { 'm', 0, 'p', 0, '2', 0, 0, 0};
    U16 *str;
    U32 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }

    srv_mms_viewer_get_attachment_list(&temp_list, &num_attach);
    for (item_count = 0; item_count < num_attachment; item_count++)
    {
        menuData[item_count].image_list[0] = get_image(IMG_ID_UMMS_ATTACHMENT_LIST);
        count = -1;
        attach_list = temp_list;
        while (attach_list != NULL && count != (item_index + item_count - 1))
        {
            attach_list = attach_list->next;
            if (attach_list == NULL)
            {
                count++;
            }
            else if (attach_list->object->type == MMA_MMS_OBJECT_TYPE_ATTACHMENT)
            {
                count++;
            }
        }

        if (attach_list == NULL)
        {
            return FALSE;
        }

        len = (mmi_ucs2strlen((S8*) attach_list->object->file_name_ucs)) * ENCODING_LENGTH;
        str = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) attach_list->object->file_name_ucs);
        if (str != NULL)
        {
        #if((!defined(__MMI_SHOW_FILE_EXT__)))

            /* PmgRemoveFileExt((S8*) attach_list->object->file_name);
               len -= (mmi_ucs2strlen((S8*) str) * ENCODING_LENGTH); */
            extRemoved = TRUE;
            srv_fmgr_path_hide_extension((WCHAR*) attach_list->object->file_name_ucs);

        #elif(!defined(__MMI_SHOW_DAF_FILE_EXT__))
            if ((mmi_ucs2icmp((S8*) str, (S8*) mp3_ext) == 0) || (mmi_ucs2icmp((S8*) str, (S8*) mp2_ext) == 0))
            {
                /* PmgRemoveFileExt((S8*) attach_list->object->file_name);
                   len -= (mmi_ucs2strlen((S8*) str) * ENCODING_LENGTH); */
                extRemoved = TRUE;
                srv_fmgr_path_hide_extension((WCHAR*) attach_list->object->file_name_ucs);
            }
        #endif 
        }
        if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
        {
            mmi_ucs2cpy((S8*) menuData[item_count].item_list[0], (S8*) attach_list->object->file_name_ucs);
        }
        else
        {
            mmi_ucs2ncpy(
                (S8*) menuData[item_count].item_list[0],
                (S8*) attach_list->object->file_name_ucs,
                (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
            mmi_ucs2cat((S8*) menuData[item_count].item_list[0], (S8*) L"...");
        }
        if (extRemoved == TRUE)
        {
            srv_mms_make_file_name((S8*) attach_list->object->file_name_ucs, (S8*) str);
        }
        extRemoved = FALSE;
    }
    return num_attachment;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_save_objects_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_save_objects_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Stores the strings id of submenus returned */
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
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
#ifdef __MMI_MMS_POSTCARD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_POSTCARD__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_POSTCARD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_POSTCARD__ */ 
/* under construction !*/
#ifdef __MMI_MV_SUPPORT_REF_ID__
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
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_save_objects_items_hide_unhide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  scr_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_save_objects_items_hide_unhide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *image_info = NULL;
    mma_mms_object_struct *video_info = NULL;
    mma_mms_object_struct *audio_info = NULL;
    mma_mms_object_struct *text_info = NULL;
    mma_mms_attachment_info_struct *attachment_list = NULL;
    U32 attachment_count = 0;

    /* get objects info from viewer */
#ifdef __MMI_MMS_POSTCARD__
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
#endif /* __MMI_MMS_POSTCARD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_get_objects_from_current_slide(&image_info, &video_info, &audio_info, &text_info);
    srv_mms_viewer_get_attachment_list(&attachment_list, &attachment_count);

    /* image_info */
    if (NULL == image_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS);
    }

    /* audio_info */
    if (NULL == audio_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS);
    }
    /* video info */

    if (NULL == video_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS);
    }
    /* text info */
    if (NULL == text_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    }

#ifdef __MMI_MMS_POSTCARD__
    if (MMA_MSG_TYPE_POSTCARD == info->msg_info->msg_type)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    }
#endif /* __MMI_MMS_POSTCARD__ */ 

#ifdef __MMI_MV_SUPPORT_REF_ID__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_CURRENT_ATTACHMENT_AS);
#endif 

    if ((NULL == attachment_list) || (0 == attachment_count))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_save_objects_items_check_for_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  scr_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_save_objects_items_check_for_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */

    mma_mms_object_struct *image_info = NULL;
    mma_mms_object_struct *video_info = NULL;
    mma_mms_object_struct *audio_info = NULL;
    mma_mms_object_struct *text_info = NULL;
    mma_mms_attachment_info_struct *attachment_list = NULL;
    U32 attachment_count = 0;

    /* get objects info from viewer */
#ifdef __MMI_MMS_POSTCARD__
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
#endif /* __MMI_MMS_POSTCARD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_get_objects_from_current_slide(&image_info, &video_info, &audio_info, &text_info);
    srv_mms_viewer_get_attachment_list(&attachment_list, &attachment_count);

#ifdef __MMI_MMS_POSTCARD__
    if (MMA_MSG_TYPE_POSTCARD == info->msg_info->msg_type)
    {
        if (NULL == image_info)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 

    {
        if ((NULL == attachment_list) && (NULL == image_info) && (NULL == audio_info) && (NULL == video_info) &&
            (NULL == text_info))
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_save_objects_list_of_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_get_save_objects_list_of_icons(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_get_error_print_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_mms_get_error_print_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_NO_CONTENT_DISPLAY));
}
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_property_screen_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_mms_property_screen_get_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 temp[TEMP_BUFFER_SIZE] = {0, };
    S8 str_cmp_temp[SRV_MMS_MAX_ADDR_LEN] = {0x00, };
    S8 str_cmp_temp_1[SRV_MMS_MAX_ADDR_LEN] = {0x00, };
    S8 str_sub_cmp_temp[MMA_MAX_SUBJECT_LEN] = {0x00, };
    S8 str_sub_cmp_rpt_msg[SRV_MMS_XML_MAX_SUBJECT_LEN + 1] = {0x00, };
    S8 str_app_cmp_temp[MAX_PROGRESS_STRING_LENGTH] = {0x00, };
    MYTIME time, time1;
    U16 status_str_id = 0;
    U32 len = 0;
    U32 address_counter = 0;

#ifdef __MMI_MMS_POSTCARD__
    U16 *file_path = NULL;
    S32 offset = 0;
    S32 size_obj = 0;
    U16 *file_path_obj = NULL;
    srv_postcard_recipient_struct *recipient_head = NULL;
    srv_postcard_recipient_struct *temp_addr_recepient_head = NULL;
    kal_char *greeting = NULL;
    U32 recepient_count = 0;
    S32 parent_file_handle = 0;
    S32 result = 0;
#endif /* __MMI_MMS_POSTCARD__ */ 

    U32 size = 0, size_kb = 0, size_bytes = 0;

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mma_mms_addr_list_struct *temp_addr = NULL;
#else 
    srv_mms_addr_struct *temp_addr = NULL;
#endif 
    U8 dttemp[TEMP_BUFFER_SIZE];
    FLOAT timezone;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_PROPERTIES, info->msg_id, info->msg_info->msg_type);

    mmi_umms_app_sh_delete_progress_screen();

    memset(subMenuData, 0, sizeof(subMenuData));

    /* Status */
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
    if ((info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            switch (info->header_info->status)
            {
                case MMA_DR_STATUS_EXPIRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_EXPIRED;
                    break;
                case MMA_DR_STATUS_RETRIEVED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_RETRIEVED;
                    break;
                case MMA_DR_STATUS_REJECTED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_REJECTED;
                    break;
                case MMA_DR_STATUS_DEFERRED:
                    status_str_id = STR_ID_UMMS_DEFFERED;
                    break;
                case MMA_DR_STATUS_UNRECOGNISED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNRECOGNISED;
                    break;
                case MMA_DR_STATUS_INDETERMINATE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_INDETERMINATE;
                    break;
                case MMA_DR_STATUS_FORWARDED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_FORWARDED;
                    break;
                case MMA_DR_STATUS_UNREACHABLE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNREACHABLE;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT)
        {
            switch (info->header_info->status)
            {
                case MMA_RR_STATUS_READ:
                    status_str_id = STR_GLOBAL_READ;
                    break;
                case MMA_RR_STATUS_DELETED_NO_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_NO_READ;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (status_str_id != 0)
        {
            memset(subMenuData, 0, sizeof(subMenuData));
            mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_STATUS));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");

            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_ucs2cpy((S8*) temp, (S8*) GetString(status_str_id));
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        }

    }
#endif
    /* From Field */
    if (((info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_MMS) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_TEMPLATE) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_JAVA))
        && ((info->folder_id == MMA_FOLDER_INBOX)
            || ((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX))))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FROM));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if (!mmi_ucs2ncmp((S8*) info->msg_info->from_address, (S8*) str_cmp_temp, SRV_MMS_MAX_ADDR_LEN) ||
            ((info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER) &&
             (info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL)))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) info->msg_info->from_address);
            address_counter++;
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* To field */
    /* Call API for Postcard to get the Recepient List from Applib */
#if 0   /* ndef __MMI_MMS_POSTCARD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* __MMI_MMS_POSTCARD__ */
    {
        if ((info->msg_info->msg_type != MMA_MSG_TYPE_NOTIFICATION) &&
            (info->msg_info->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
            (info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT))
        {

            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_TO));

            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            if (info->header_info->to == NULL)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            else
            {
                temp_addr = info->header_info->to;
                while (temp_addr != NULL && address_counter <= MMI_UMMS_MAX_ADDRESSES)
                {
                    memset(str_cmp_temp_1, 0, SRV_MMS_MAX_ADDR_LEN);
                #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                    if (temp_addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                    {   /* Convert To number from ASCII to UCS2. */
                        len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                        if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                        }
                        else
                        {
                            memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                            mmi_asc_n_to_ucs2(
                                (S8*) str_cmp_temp_1,
                                (S8*) temp_addr->addr,
                                (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    else
                    {
                        len = mmi_ucs2strlen((S8*) temp_addr->addr);
                        if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                        }
                        else
                        {
                            mmi_ucs2ncpy(
                                (S8*) str_cmp_temp_1,
                                (S8*) temp_addr->addr,
                                (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                #else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                    if (temp_addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                    {   /* Convert To number from ASCII to UCS2. */
                        len = (strlen((S8*) temp_addr->address)) * ENCODING_LENGTH;
                        if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                        }
                        else
                        {
                            memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                            mmi_asc_n_to_ucs2(
                                (S8*) str_cmp_temp_1,
                                (S8*) temp_addr->address,
                                (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                    else
                    {
                        len = mmi_ucs2strlen((S8*) temp_addr->address);
                        if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                        {
                            mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                        }
                        else
                        {
                            mmi_ucs2ncpy(
                                (S8*) str_cmp_temp_1,
                                (S8*) temp_addr->address,
                                (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                            mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                        }
                        mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                    }
                #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                    temp_addr = temp_addr->next;
                    if (temp_addr != NULL)
                    {
                        memset(temp, 0x00, TEMP_BUFFER_SIZE);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                    }
                    address_counter++;
                }
            }
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        }

        if (info->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD)
        {
            /* CC field */

            if ((info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
                (info->msg_info->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
                (info->msg_info->msg_type != MMA_MSG_TYPE_NOTIFICATION))
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CC));

                memset(temp, 0x00, TEMP_BUFFER_SIZE);
                mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
                mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

                if (info->header_info->cc == NULL)
                {
                    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
                }
                else
                {
                    temp_addr = info->header_info->cc;
                    while (temp_addr != NULL && address_counter <= MMI_UMMS_MAX_ADDRESSES)
                    {
                        memset(str_cmp_temp_1, 0, SRV_MMS_MAX_ADDR_LEN);
                    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                        if (temp_addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                        {   /* Convert To number from ASCII to UCS2. */
                            len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                            if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                            {
                                mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                            }
                            else
                            {
                                memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                                mmi_asc_n_to_ucs2(
                                    (S8*) str_cmp_temp_1,
                                    (S8*) temp_addr->addr,
                                    (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                            }
                            /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                            mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                        }
                        else
                        {
                            len = mmi_ucs2strlen((S8*) temp_addr->addr);
                            if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                            {
                                mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                            }
                            else
                            {
                                mmi_ucs2ncpy(
                                    (S8*) str_cmp_temp_1,
                                    (S8*) temp_addr->addr,
                                    (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                            }
                            mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                        }
                    #else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                        if (temp_addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                        {   /* Convert To number from ASCII to UCS2. */
                            len = (strlen((S8*) temp_addr->address)) * ENCODING_LENGTH;
                            if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                            {
                                mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                            }
                            else
                            {
                                memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                                mmi_asc_n_to_ucs2(
                                    (S8*) str_cmp_temp_1,
                                    (S8*) temp_addr->address,
                                    (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                            }
                            /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                            mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                        }
                        else
                        {
                            len = mmi_ucs2strlen((S8*) temp_addr->address);
                            if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                            {
                                mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                            }
                            else
                            {
                                mmi_ucs2ncpy(
                                    (S8*) str_cmp_temp_1,
                                    (S8*) temp_addr->address,
                                    (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                            }
                            mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                        }
                    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                        temp_addr = temp_addr->next;
                        if (temp_addr != NULL)
                        {
                            memset(temp, 0x00, TEMP_BUFFER_SIZE);
                            mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        }
                        address_counter++;
                    }
                }
                memset(temp, 0x00, TEMP_BUFFER_SIZE);
                mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
                mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

                /* /BCC */
                if ((info->folder_id != MMA_FOLDER_INBOX)
                    && !((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX)))
                {
                    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BCC));
                    memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

                    if (info->header_info->bcc == NULL)
                    {
                        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
                    }
                    else
                    {
                        temp_addr = info->header_info->bcc;
                        while (temp_addr != NULL && address_counter <= MMI_UMMS_MAX_ADDRESSES)
                        {
                            memset(str_cmp_temp_1, 0, SRV_MMS_MAX_ADDR_LEN);
                        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                            if (temp_addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                            {   /* Convert To number from ASCII to UCS2. */
                                len = (strlen((S8*) temp_addr->addr)) * ENCODING_LENGTH;
                                if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                                {
                                    mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                                }
                                else
                                {
                                    memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                                    mmi_asc_n_to_ucs2(
                                        (S8*) str_cmp_temp_1,
                                        (S8*) temp_addr->addr,
                                        (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                    mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                                }
                                /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                                mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                            }
                            else
                            {
                                len = mmi_ucs2strlen((S8*) temp_addr->addr);
                                if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                                {
                                    mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->addr);
                                }
                                else
                                {
                                    mmi_ucs2ncpy(
                                        (S8*) str_cmp_temp_1,
                                        (S8*) temp_addr->addr,
                                        (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                    mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                                }
                                mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                            }
                        #else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                            if (temp_addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                            {   /* Convert To number from ASCII to UCS2. */
                                len = (strlen((S8*) temp_addr->address)) * ENCODING_LENGTH;
                                if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                                {
                                    mmi_asc_to_ucs2((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                                }
                                else
                                {
                                    memset(str_cmp_temp_1, 0, (SRV_MMS_MAX_ADDR_LEN - (3 * ENCODING_LENGTH)));
                                    mmi_asc_n_to_ucs2(
                                        (S8*) str_cmp_temp_1,
                                        (S8*) temp_addr->address,
                                        (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                    mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                                }
                                /* mmi_asc_to_ucs2((PS8) str_cmp_temp, (PS8) temp_addr->addr); */
                                mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                            }
                            else
                            {
                                len = mmi_ucs2strlen((S8*) temp_addr->address);
                                if (len <= (SRV_MMS_MAX_ADDR_LEN - ENCODING_LENGTH - ENCODING_LENGTH))
                                {
                                    mmi_ucs2cpy((S8*) str_cmp_temp_1, (S8*) temp_addr->address);
                                }
                                else
                                {
                                    mmi_ucs2ncpy(
                                        (S8*) str_cmp_temp_1,
                                        (S8*) temp_addr->address,
                                        (SRV_MMS_MAX_ADDR_LEN - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                                    mmi_ucs2cat((S8*) str_cmp_temp_1, (S8*) L"...");
                                }
                                mmi_ucs2cat((S8*) subMenuData, (S8*) str_cmp_temp_1);
                            }

                        #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                            temp_addr = temp_addr->next;
                            if (temp_addr != NULL)
                            {
                                memset(temp, 0x00, TEMP_BUFFER_SIZE);
                                mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                                mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                            }
                            address_counter++;
                        }
                    }
                    memset(temp, 0x00, TEMP_BUFFER_SIZE);
                    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
                    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

                }
            }

            /* number of Recepients */
            if (info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT)
            {
                address_counter = 0;
                temp_addr = info->header_info->to;
                while (temp_addr != NULL)
                {
                    address_counter++;
                    temp_addr = temp_addr->next;
                }
                temp_addr = info->header_info->cc;
                while (temp_addr != NULL)
                {
                    address_counter++;
                    temp_addr = temp_addr->next;
                }
                temp_addr = info->header_info->bcc;
                while (temp_addr != NULL)
                {
                    address_counter++;
                    temp_addr = temp_addr->next;
                }
            }
        }
    }
#if 0   /* __MMI_MMS_POSTCARD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* __MMI_MMS_POSTCARD__ */

    if (info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT)
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_NUM_OF_RECEPIENT));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }
#if 0   /* __MMI_MMS_POSTCARD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* __MMI_MMS_POSTCARD__ */
    {
        if (info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            gui_itoa((S32) address_counter, (UI_string_type) temp, UMMS_CONVERT_INDEX);
        }
    }

    if (info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }
    /* Message Id for Read and Delivery Report */
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
#endif /* 0 */ 
    /* /Subject */
    if (info->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SUBJECT));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if ((info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
            (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT))
        {
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            if (!mmi_ucs2ncmp
                ((S8*) info->header_info->reported_subject, (S8*) str_sub_cmp_rpt_msg, SRV_MMS_XML_MAX_SUBJECT_LEN))
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            else
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) info->header_info->reported_subject);
            }
#else /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
			if (!mmi_ucs2ncmp
                ((S8*) info->msg_info->reported_subject, (S8*) str_sub_cmp_rpt_msg, SRV_MMS_XML_MAX_SUBJECT_LEN))
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
			else
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) info->msg_info->reported_subject);
            }
#endif /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
           
        }
        else
        {
            if (!mmi_ucs2ncmp((S8*) info->msg_info->subject, (S8*) str_sub_cmp_temp, SRV_MMS_MAX_ADDR_LEN))
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            }
            else
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) info->msg_info->subject);
            }
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* Expiration Time only For Notification */
    if (info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_EXPIRE_TIME));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (info->msg_info->expiry_date == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            timezone = mmi_dt_get_tz();
            mmi_dt_utc_sec_2_mytime((U32) info->msg_info->expiry_date, &time1, MMI_TRUE);
            mmi_dt_utc_to_rtc(timezone, time1, time);

            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

            memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            /* Time */
            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /* /Priority */
    /* CR ID MAUI_00404706 */
    if ((info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (info->msg_info->msg_type != MMA_MSG_TYPE_READ_REPORT) &&
        (info->msg_info->msg_type != MMA_MSG_TYPE_NOTIFICATION))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_OPTIONS_PROPERTIES_PRIORITY));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        switch (info->msg_info->priority)
        {
            case MMA_PRIORITY_LOW:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_LOW));
                break;
            case MMA_PRIORITY_MEDIUM:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_MEDIUM));
                break;
            case MMA_PRIORITY_HIGH:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_HIGH));
                break;
            default:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
                break;
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }
    /* CR ID MAUI_00404706 */

    /* Application Id and Reply by Application Id for Java MMS */

    if (info->msg_info->msg_type == MMA_MSG_TYPE_JAVA)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if (!mmi_ucs2ncmp((S8*) info->msg_info->app_id, (S8*) str_app_cmp_temp, MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) app_id, (PS8) info->msg_info->app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (app_id));

        }

        /* Reply by Application ID */
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_REPLY_TO_APPLICATION_ID));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if (!mmi_ucs2ncmp((S8*) info->msg_info->reply_app_id, (S8*) str_app_cmp_temp, MAX_PROGRESS_STRING_LENGTH))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            S8 reply_app_id[(MAX_PROGRESS_STRING_LENGTH + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2((PS8) reply_app_id, (PS8) info->msg_info->reply_app_id);

            mmi_ucs2cat((S8*) subMenuData, (S8*) (reply_app_id));

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* //message class */
    if ((info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) &&
        (info->msg_info->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MSG_CLASS));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        switch (info->msg_info->msg_class)
        {
            case MMA_MSG_CLASS_PERSONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_PERSONEL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_ADVERTISEMENT:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SETTINGS_ADVERTISMENT));
                break;
            case MMA_MSG_CLASS_INFORMATIONAL:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_INFORMATIONAL_MSG_CLASS));
                break;
            case MMA_MSG_CLASS_AUTO:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_AUTO_MSG_CLASS));
                break;
            default:
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_UNKNOWN));
                break;
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    /* /Creation Date */
    /* CR ID MAUI_00404735 */
    if ((info->folder_id != MMA_FOLDER_INBOX)
        && !((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX)))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CREATION_DATE));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        timezone = mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) info->msg_info->date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }
    /* CR ID MAUI_00404735 */

    /* Receive Date */
    if ((info->folder_id == MMA_FOLDER_INBOX)
        || ((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX)))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_RECEIVE_DATE));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        timezone = mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) info->msg_info->date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }

    /* /MMS Size */
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
    if ((info->msg_info->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (info->msg_info->msg_type != MMA_MSG_TYPE_READ_REPORT))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SIZE));
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* if(info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION )
           {
           size = info->header_info->download_size;
           }
           else
           { */
    #ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        size = info->msg_info->user_element_size;
    #else 
        size = info->msg_info->msg_size;
    #endif 
        /* } */
        size_kb = size / 1024;
        size_bytes = size % 1024;

        if (size_kb >= 1)
        {
            if (size_bytes > 512)
            {
                size_kb++;
            }
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_kb, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));

        }
        else
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            gui_itoa((S32) size_bytes, (UI_string_type) temp, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, UMMS_MEMSET_BUFFER_2);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            if (size_bytes == 1)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTE));
            }
            else
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_BYTES));
            }
        }
    }
#endif

    /* added for storage_type: */
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_CURR_STORAGE));
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    if (info->msg_info->msg_storage == MMA_MSG_STORAGE_PHONE)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_PREFER_STORAGE_PHONE));

    }
    else if (info->msg_info->msg_storage == MMA_MSG_STORAGE_CARD1)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_PREFER_STORAGE_CARD));

    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#if 0   /* def __MMI_MMS_POSTCARD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* __MMI_MMS_POSTCARD__ */

    return (U8*) subMenuData;

}

#else /*ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_property_screen_get_data_slim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_mms_property_screen_get_data_slim(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 temp[TEMP_BUFFER_SIZE] = {0, };
    S8 str_cmp_temp[MMA_MAX_ADDR_LEN] = {0x00, };
    MYTIME time, time1;
    U16 status_str_id = 0;
    U32 address_counter = 0;

    U8 dttemp[TEMP_BUFFER_SIZE];
    FLOAT timezone;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_PROPERTIES, info->msg_id, info->msg_info->msg_type);

    mmi_umms_app_sh_delete_progress_screen();

    memset(subMenuData, 0, sizeof(subMenuData));

    /* Status */
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__	
    if ((info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
        (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT))
    {
        if (info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            switch (info->msg_info->msg_report_status)
            {
                case MMA_DR_STATUS_EXPIRED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_EXPIRED;
                    break;
                case MMA_DR_STATUS_RETRIEVED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_RETRIEVED;
                    break;
                case MMA_DR_STATUS_REJECTED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_REJECTED;
                    break;
                case MMA_DR_STATUS_DEFERRED:
                    status_str_id = STR_ID_UMMS_DEFFERED;
                    break;
                case MMA_DR_STATUS_UNRECOGNISED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNRECOGNISED;
                    break;
                case MMA_DR_STATUS_INDETERMINATE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_INDETERMINATE;
                    break;
                case MMA_DR_STATUS_FORWARDED:
                    status_str_id = STR_ID_UMMS_DR_STATUS_FORWARDED;
                    break;
                case MMA_DR_STATUS_UNREACHABLE:
                    status_str_id = STR_ID_UMMS_DR_STATUS_UNREACHABLE;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT)
        {
            switch (info->msg_info->msg_report_status)
            {
                case MMA_RR_STATUS_READ:
                    status_str_id = STR_GLOBAL_READ;
                    break;
                case MMA_RR_STATUS_DELETED_NO_READ:
                    status_str_id = STR_ID_UMMS_DR_STATUS_NO_READ;
                    break;
                default:
                    status_str_id = 0;
                    break;
            }
        }

        if (status_str_id != 0)
        {
            memset(subMenuData, 0, sizeof(subMenuData));
            mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_STATUS));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");

            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_ucs2cpy((S8*) temp, (S8*) GetString(status_str_id));
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        }

    }
#endif
    /* From Field */
    if (((info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_MMS) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_TEMPLATE) ||
         (info->msg_info->msg_type == MMA_MSG_TYPE_JAVA))
        && ((info->folder_id == MMA_FOLDER_INBOX)
            || ((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX))))
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FROM));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        if (!mmi_ucs2ncmp((S8*) info->msg_info->from_address, (S8*) str_cmp_temp, MMA_MAX_ADDR_LEN) ||
            ((info->msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER) &&
             (info->msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL)))
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) info->msg_info->from_address);
            address_counter++;
        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    }



    /* Expiration Time only For Notification */
    if (info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {

        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_EXPIRE_TIME));

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        if (info->msg_info->expiry_date == 0)
        {
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            timezone = mmi_dt_get_tz();
            mmi_dt_utc_sec_2_mytime((U32) info->msg_info->expiry_date, &time1, MMI_TRUE);
            mmi_dt_utc_to_rtc(timezone, time1, time);

            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

            memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            /* Time */
            memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
            time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
            mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        }
        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    }

    /* CR ID MAUI_00404735 */
    if ((info->folder_id != MMA_FOLDER_INBOX)
        && !((info->folder_id == MMA_FOLDER_ARCHIVE) && (info->msg_info->prev_folder == MMA_FOLDER_INBOX)))
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_CREATION_DATE));
    }
    else
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_RECEIVE_DATE));
    }

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

        timezone = mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) info->msg_info->date, &time1, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time1, time);

        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        date_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, UMMS_MEMSET_BUFFER_1);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        /* Time */
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        time_string(&time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) subMenuData, (S8*) dttemp);

        memset(temp, 0x00, TEMP_BUFFER_SIZE);
        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);


    return (U8*) subMenuData;

}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_use_recipients_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_use_recipients_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stores the strings id of submenus returned */
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_use_recipients_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_use_recipients_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = GetNumOfChild(scrDB->RObj->menu_item_id);
    return count;
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sort_by_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sort_by_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = mmi_um_prepare_sort_selection_list(str_item_list, MAX_SUB_MENUS);
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sort_by_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_sort_by_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stores the strings id of submenus returned */
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    mmi_um_prepare_sort_selection_list(str_item_list, MAX_SUB_MENUS);
    return str_item_list;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_use_details_menu_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_use_details_menu_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 nNumofItem = 0;

    /* mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
        (data->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTION_USE_DETAILS_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTION_USE_DETAILS_URL);
    }
#ifdef __MMI_MMS_POSTCARD__
    if (MMA_MSG_TYPE_POSTCARD == data->msg_info->msg_type)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_SENDER);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_NUMBER);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_EMAIL);
    }

    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTION_USE_DETAILS_URL);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_SENDER);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_NUMBER);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_USE_DETAILS_REC_EMAIL);
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
#ifndef BROWSER_SUPPORT
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTION_USE_DETAILS_URL);
#endif 
    /* nNumofItem = GetNumOfChild_Ext(scrDB->RObj->menu_item_id); */
    return nNumofItem;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_use_details_menu_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_use_details_menu_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}

#ifdef __MMI_MMS_PREVIEW_GOTO__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_preview_menu_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_mms_preview_menu_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_mms_preview_menu_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_mms_preview_menu_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_java_options_menu_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_java_options_menu_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_java_options_menu_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_java_options_menu_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_list_of_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *mmi_umms_app_ui_callback_get_list_of_icon(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIndexIconsImageList;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_notification_option_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_notification_option_screen_item(U16 menu_id)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
	#endif 
/* under construction !*/
/* under construction !*/
	#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
	#endif 
/* under construction !*/
	#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
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
		#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
		#endif 
/* under construction !*/
/* under construction !*/
	#endif /* __MMI_OP11_HOMESCREEN__ */ 
	#ifdef __MMI_OP12_TOOLBAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif /* __MMI_OP12_TOOLBAR__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
		#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
		#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
		#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
		#endif /* __MMI_MMS_BGSR_CANCEL_PROHIBIT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_notification_option_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_notification_option_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_report_options_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_show_report_options_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
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
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
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
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
#ifdef __MMI_OP12_TOOLBAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP12_TOOLBAR__ */ 
#ifdef __MMI_MMS_SWITCH_MSG_READ_STATUS__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_SWITCH_MSG_READ_STATUS__ */ 
/* under construction !*/
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_report_options_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_show_report_options_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_sim_options_resend_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_show_sim_options_resend_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_sim_options_resend_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_show_sim_options_resend_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_num_valid_sim() == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_CALL);
    }
#ifdef __MMI_EMAIL__
    if (!mmi_email_is_email_can_forward())
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_USE_DETAILS_SEND_EMAIL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_USE_DETAILS_SEND_EMAIL);
    }
#endif /* __MMI_EMAIL__ */ 
    return GetNumOfChild_Ext(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_umms_app_screenDB_struct* scrDB = mmi_umms_app_resource_get_screenDB(scr_id); */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_message_status_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_message_status_get_data(U16 scr_id)
{
#ifndef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 temp[TEMP_BUFFER_SIZE] = {0, };
    S8 tmp_str[10] = {0, };
    U8 ntt = 0;
    U8 quota = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(
       MMI_INET_TRC_G6_MMS,
       MMI_UMMS_SHOW_MSG_STATUS_SCREEN,
       info->msg_id,
       g_current_mms_info_list->msg_status); */

    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    /* mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n"); */
    memset(subMenuData, 0, sizeof(subMenuData));
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_MMS_STATUS));
    memset(temp, 0x00, TEMP_BUFFER_SIZE);
    mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (info->bgsr_msg_info == NULL)
    {
        srv_mms_container_set_bgsr_info();
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    info->bgsr_msg_info->status = srv_mms_bgsr_update_msg_status_info(info->msg_id, &ntt, &quota);
    switch (info->bgsr_msg_info->status)
    {

        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_WAITING_SENDING));
            break;
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_WAITING_DWNLING));
            break;
        case SRV_MMS_BGSR_STATUS_SENDING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_SENDING));
            break;
        case SRV_MMS_BGSR_STATUS_SEND_FAIL:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FAILED));
            break;
        case SRV_MMS_BGSR_STATUS_DOWNLOADING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_DOWNLOADING));
            break;
        case SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_FAILED));
            break;
        case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DEFFERED));
            break;
        case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DEFFERED));
            break;
        case SRV_MMS_BGSR_STATUS_SAVING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_SAVING));
            break;
        case SRV_MMS_BGSR_STATUS_DELETING:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_DELETING));
            break;
        case SRV_MMS_BGSR_STATUS_SEND_SIM_UNAVAILABLE:
            if (info->msg_info->msg_sim_id == MMI_SIM1)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SEND_SIM1_UNAVAILABLE));
                break;
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            if (info->msg_info->msg_sim_id == MMI_SIM2)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SEND_SIM2_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */

        #if (MMI_MAX_SIM_NUM >= 3)
            if (info->msg_info->msg_sim_id == MMI_SIM3)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SEND_SIM3_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */

        #if (MMI_MAX_SIM_NUM >= 4)
            if (info->msg_info->msg_sim_id == MMI_SIM4)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SEND_SIM4_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */
        case SRV_MMS_BGSR_STATUS_DOWNLOAD_SIM_UNAVAILABLE:
            if (info->msg_info->msg_sim_id == MMI_SIM1)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DOWNLOAD_SIM1_UNAVAILABLE));
                break;
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            if (info->msg_info->msg_sim_id == MMI_SIM2)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DOWNLOAD_SIM2_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */

        #if (MMI_MAX_SIM_NUM >= 3)
            if (info->msg_info->msg_sim_id == MMI_SIM3)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DOWNLOAD_SIM3_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */

        #if (MMI_MAX_SIM_NUM >= 4)
            if (info->msg_info->msg_sim_id == MMI_SIM4)
            {
                mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DOWNLOAD_SIM4_UNAVAILABLE));
                break;
            }
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS == 2)) */

    
        case SRV_MMS_BGSR_STATUS_SEND_FAILED_INVALID_DATA_ACCOUNT:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_SEND_FAILED_BY_INVALID_DATA_ACCOUNT));
            break;
        case SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_DOWNLOAD_FAILED_BY_INVALID_DATA_ACCOUNT));
            break;
     
        #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
        case SRV_MMS_BGSR_STATUS_DOWNLOAD_MEM_CARD_UNAVAILABLE:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_IS_UMMS_DOWNLOAD_FAILED_CARD_NOT_PRESENT));
            break;
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        default:
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY));
            /* MMI_ASSERT(0); */
            break;
    }

    /* For Next Transimision Time */
    if ((info->bgsr_msg_info->status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND) ||
        (info->bgsr_msg_info->status == SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD))
    {
        info->bgsr_msg_info->ntt = ntt;
        info->bgsr_msg_info->quota = quota;
        if (info->bgsr_msg_info->ntt != 0)
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_NEXT_TRMN_TIME));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            memset(tmp_str, 0, 10);
            gui_itoa(info->bgsr_msg_info->ntt, (UI_string_type) tmp_str, 10);
            mmi_asc_to_ucs2((PS8) temp, (PS8) tmp_str);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) (S8*) GetString(STR_ID_UMMS_MINS));

        }
        /* For Quota */
        if (info->bgsr_msg_info->quota != 0)
        {
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_QUOTA));
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
            memset(temp, 0x00, TEMP_BUFFER_SIZE);
            memset(tmp_str, 0, 10);
            gui_itoa(info->bgsr_msg_info->quota, (UI_string_type) tmp_str, 10);
            mmi_asc_to_ucs2((PS8) temp, (PS8) tmp_str);
            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        }
    }
    return (U8*) subMenuData;

#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sh_new_message_popup_get_image_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_ui_callback_sh_new_message_popup_get_image_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return IMG_NEW_MESSAGE_NOTIFICATION_MSG; */
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sh_new_message_popup_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_ui_callback_sh_new_message_popup_get_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return STR_ID_UMMS_NEW_MMS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_compose_settings_signature_selection_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_compose_settings_signature_selection_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;
    U8 temp_file[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH];
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__)
    mma_insert_check_struct check_result;
	U8 sig_temp_file[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH];
#endif
    mma_insert_info_struct insert_info;
#ifdef __MMI_MMS_SIGNATURE__
    BOOL out_of_class_object = FALSE;
#endif
    /* for signature size */
    

#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    S8 tmp_str[UMMS_CONVERT_INDEX] = {0, };
#endif 
    U32 current_msg_size = (UMMS_MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH;   /* space reserved for text */
#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    U32 max_msg_size = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    /* validate the file present */
    mmi_umms_app_ui_plug_in_check_and_update_signature_file_info();
    /* signature_size */
    insert_info.insert_type = MMA_INSERT_UNKNOWN;
    insert_info.current_msg_size = 0;
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    insert_info.max_msg_size = srv_mms_sending_mms_size_limit();
#else 
    insert_info.max_msg_size = wap_custom_get_max_mms_msg_size();
#endif 
    insert_info.mms_type = MMA_MMS_TYPE_SMIL_MMS;
    insert_info.filepath = (kal_wchar*) temp_file;

    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__

    if (compose_settings_inline_items->signature_flag &
        (UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED | UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED))
    {
        mmi_ucs2cpy((S8*) sig_temp_file, (S8*) compose_settings_inline_items->auto_signature_audio_file);
        current_msg_size += applib_get_file_size((U16*) sig_temp_file);
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED)
    {
        mmi_ucs2cpy((S8*) sig_temp_file, (S8*) compose_settings_inline_items->auto_signature_image_file);
        current_msg_size += applib_get_file_size((U16*) sig_temp_file);
    }
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__

    if (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED)
    {
        mmi_ucs2cpy((S8*) sig_temp_file, (S8*) compose_settings_inline_items->auto_signature_video_file);
        current_msg_size += applib_get_file_size((U16*) sig_temp_file);
    }
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)

    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP)

    {
        if (current_msg_size > MMA_MAX_WAP_CONN_MSG_SIZE)
        {
            max_msg_size = MMA_MAX_WAP_CONN_MSG_SIZE;
            max_msg_size = max_msg_size / 1024;
            memset(subMenuData, 0, sizeof(subMenuData));
            gui_itoa(max_msg_size, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
            mmi_ucs2cpy((S8*) subMenuData, (S8*) tmp_str);
            mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_WAP_MAX_SIZE_EXCEEDS));

            {
                mmi_popup_property_struct arg;

                mmi_popup_property_init(&arg);
                arg.parent_id = mmi_umms_dtmgr_get_group_id();
                arg.user_tag = (void*)(mmi_umms_signature_objects_remove_confirmation);
                mmi_popup_display((WCHAR*) ((UI_string_type) subMenuData), MMI_EVENT_INFO, &arg);
            }
            return;

        }
    }
#endif /* defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__) */ 
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    if (current_msg_size > srv_mms_sending_mms_size_limit())
    {
        mmi_umms_signature_objects_remove_confirmation();
        return;
    }
#else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    if (current_msg_size > wap_custom_get_max_mms_msg_size())
    {
        mmi_umms_signature_objects_remove_confirmation();
        return;
    }
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    /* put the size check here */

    if (compose_settings_inline_items->creation_mode == E_SET_CREAT_MODE_RESTRICTED)
    {
        insert_info.creation_mode = MMA_CREATION_MODE_RESTRICTED;
    }
#ifdef __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__
    else if (compose_settings_inline_items->creation_mode == E_SET_CREAT_MODE_WARNING)
    {
        insert_info.creation_mode = MMA_CREATION_MODE_WARNING;
    }
#endif /* __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__ */ 
    else
    {
        insert_info.creation_mode = MMA_CREATION_MODE_FREE;
    }
    if (insert_info.creation_mode != MMA_CREATION_MODE_FREE)
    {
    #ifdef __MMI_MMS_SIGNATURE__
        compose_settings_inline_items->signature_out_class_flag = 0;
        if (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED)
        {
        #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
            mmi_ucs2cpy((S8*) temp_file, (S8*) compose_settings_inline_items->auto_signature_image_file);

            insert_info.insert_type = MMA_INSERT_IMAGE;
            mma_uc_insert_object_check(&insert_info, &check_result);
            if ((!check_result.result && check_result.creation_mode_violate == TRUE)
                || (check_result.detail_result == MMA_RESULT_OK_WITH_WARNING_CONTENT))
            {
                out_of_class_object = TRUE;
                compose_settings_inline_items->signature_out_class_flag |= UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
            }
        #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
        }

        if (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED)
        {
        #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
            mmi_ucs2cpy((S8*) temp_file, (S8*) compose_settings_inline_items->auto_signature_audio_file);

            insert_info.insert_type = MMA_INSERT_AUDIO;
            mma_uc_insert_object_check(&insert_info, &check_result);
            if ((!check_result.result && check_result.creation_mode_violate == TRUE)
                || (check_result.detail_result == MMA_RESULT_OK_WITH_WARNING_CONTENT))
            {
                out_of_class_object = TRUE;
                compose_settings_inline_items->signature_out_class_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
            }
        #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
        }
    #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__

        if (compose_settings_inline_items->signature_flag & UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED)
        {
            mmi_ucs2cpy((S8*) temp_file, (S8*) compose_settings_inline_items->auto_signature_video_file);

            insert_info.insert_type = MMA_INSERT_VIDEO;
            mma_uc_insert_object_check(&insert_info, &check_result);
            if ((!check_result.result && check_result.creation_mode_violate == TRUE)
                || (check_result.detail_result == MMA_RESULT_OK_WITH_WARNING_CONTENT))
            {
                out_of_class_object = TRUE;
                compose_settings_inline_items->signature_out_class_flag |= UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
            }
        }
    #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        if (out_of_class_object == TRUE)
        {
            if (insert_info.creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                /* mmi_umms_setting_show_content_mode_confrm_pop_up(
                   STR_ID_UMMS_MODE_RESTRICTED_REMOVE_CONFIRM,
                   mmi_umms_lsk_funct_pre_signature_restricted,
                   mmi_umms_rsk_funct_pre_signature_restricted); */
                /* mmi_umms_entry_signature_confirmation((U16) STR_ID_UMMS_MODE_RESTRICTED_REMOVE_CONFIRM ); */
                mmi_umms_app_dtmgr_set_confirm_screen_para(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    (U16*) GetString(STR_ID_UMMS_MODE_RESTRICTED_REMOVE_CONFIRM),
                    MMI_EVENT_QUERY,
                    MMI_FALSE,
                    MMI_TRUE,
                    mmi_umms_app_ui_plug_in_lsk_funct_pre_signature_restricted,
                    mmi_umms_app_ui_plug_in_rsk_funct_pre_signature_restricted,
                    NULL,
                    NULL);
                mmi_umms_app_if_show_display_confirm_screen();

            }
            else
            {
                /* mmi_umms_setting_show_content_mode_confrm_pop_up(
                   STR_ID_UMMS_MODE_WARNING_REMOVE_CONFIRM,
                   mmi_umms_lsk_funct_pre_signature_warning,
                   NULL); */
                /* mmi_umms_entry_signature_confirmation((U16) STR_ID_UMMS_MODE_WARNING_REMOVE_CONFIRM ); */
                mmi_umms_app_dtmgr_set_confirm_screen_para(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    (U16*) GetString(STR_ID_UMMS_MODE_WARNING_REMOVE_CONFIRM),
                    MMI_EVENT_QUERY,
                    MMI_FALSE,
                    MMI_TRUE,
                    mmi_umms_app_ui_plug_in_lsk_funct_pre_signature_warning,
                    mmi_frm_scrn_close_active_id,
                    NULL,
                    NULL);
                mmi_umms_app_if_show_display_confirm_screen();
            }

            return;
        }
    #endif /* __MMI_MMS_SIGNATURE__ */ 
    }

    mmi_umms_app_if_show_compose_signature_settings_menu();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_filter_selection_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_retrieval_settings_filter_selection_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_if_show_retrieval_filters_settings_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PsExtFuncPtr callback = NULL; */
    FMGR_FILTER filter;
    U16 signature_hilighter = 0;
    U16 umms_parent_fmgr_cui_id = 0;
    U16 umms_fmgr_cui_id = 0;
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__)
    umms_inline_compose_items_struct *compose_settings_inline_items_value;

	compose_settings_inline_items_value =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    signature_hilighter = mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature();
    

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    switch (signature_hilighter)
    {
    #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        case E_COMPOSE_SIGNATURE_IMAGE:
            FMGR_FILTER_INIT(&filter);
            if (compose_settings_inline_items_value->creation_mode == E_SET_CREAT_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE);
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
            }
            /* callback = mmi_umms_compose_image_select_path_from_file_manager; */
            break;
    #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        case E_COMPOSE_SIGNATURE_VIDEO:
            FMGR_FILTER_INIT(&filter);
            if (compose_settings_inline_items_value->creation_mode == E_SET_CREAT_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE);
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
            }
            /* callback = mmi_umms_compose_video_select_path_from_file_manager; */
            break;
        #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        case E_COMPOSE_SIGNATURE_AUDIO:
            FMGR_FILTER_INIT(&filter);
            if (compose_settings_inline_items_value->creation_mode == E_SET_CREAT_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE);
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE);
            }
            /* callback = mmi_umms_compose_audio_select_path_from_file_manager; */
            break;
        #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
        default:
            ASSERT(0);
            break;
    }

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    umms_parent_fmgr_cui_id = mmi_frm_group_create_ex(
                                GRP_ID_ROOT,
                                GRP_ID_AUTO_GEN,
                                mmi_umms_select_file_group_proc,
                                NULL,
                                MMI_FRM_NODE_SMART_CLOSE_FLAG);
    /* mmi_umms_app_dtmgr_set_fmgr_file_select_cui_id(umms_fmgr_cui_id); */

    umms_fmgr_cui_id = cui_file_selector_create(
                        umms_parent_fmgr_cui_id,
                        (WCHAR*) L"root",
                        &filter,
                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON);
    if (umms_fmgr_cui_id != GRP_ID_INVALID)
    {
        mmi_umms_app_dtmgr_set_fmgr_file_select_cui_id(umms_fmgr_cui_id);
        cui_file_selector_set_title(umms_fmgr_cui_id, 0, GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
        cui_file_selector_run(umms_fmgr_cui_id);

    }

    /* FMGR_Revise 
       fmgr_grp_id = mmi_fmgr_select_path_and_enter(
       APP_MESSAGES,
       FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_FLAG_CHECK_SENDABLE,
       filter,
       (S8*) L"root",
       (PsExtFuncPtr) callback); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_select_file_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_select_file_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 umms_fmgr_cui_id = mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *fmgr_evt = (cui_file_selector_result_event_struct*) evt;
            srv_fmgr_fileinfo_struct info;
            WCHAR *path_buffer = NULL;

            if (fmgr_evt->result > 0)
            {
                U16 signature_hilighter = 0;

                path_buffer = srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
                cui_file_selector_get_selected_filepath(
                    umms_fmgr_cui_id,
                    &info,
                    path_buffer,
                    ((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR)));
                signature_hilighter = mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature();
                switch (signature_hilighter)
                {
                #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
                    case E_COMPOSE_SIGNATURE_IMAGE:
                        mmi_umms_compose_image_select_path_from_file_manager((S8*) path_buffer);
                        break;
                #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 

                #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
                    case E_COMPOSE_SIGNATURE_VIDEO:
                        mmi_umms_compose_video_select_path_from_file_manager((S8*) path_buffer);
                        break;
                #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 

                #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
                    case E_COMPOSE_SIGNATURE_AUDIO:
                        mmi_umms_compose_audio_select_path_from_file_manager((S8*) path_buffer);
                        break;
                #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

                    default:
                        break;
                }
                srv_mms_mem_mgr_app_adm_free(path_buffer);
            }
            else
            {
                cui_file_selector_close(umms_fmgr_cui_id);
            }
        }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_compose_reference_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_compose_reference_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__)
	umms_inline_compose_items_struct *compose_settings_sign_inline_items;
#endif
    U16 signature_hilighter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    signature_hilighter = 0;
    signature_hilighter = mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature();
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__)
    compose_settings_sign_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();
#endif
    switch (signature_hilighter)
    {
    #ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        case E_COMPOSE_SIGNATURE_IMAGE:
            memset(
                compose_settings_sign_inline_items->auto_signature_image_file,
                0,
                (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
            break;

    #endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
    #ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        case E_COMPOSE_SIGNATURE_VIDEO:
            memset(
                compose_settings_sign_inline_items->auto_signature_video_file,
                0,
                (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
            break;

    #endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
    #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        case E_COMPOSE_SIGNATURE_AUDIO:
            memset(
                compose_settings_sign_inline_items->auto_signature_audio_file,
                0,
                (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);

            break;
    #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
        default:
            break;
    }

    mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
    //mmi_frm_scrn_close_active_id();
    //mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_COMPOSE_IMAGE_OPTION);
    cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());

}

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_audio_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]         [?]
 *  is_short(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_audio_select_path_from_file_manager(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        mmi_umms_app_dtmgr_set_change_in_compose_signature(E_OFF);
        cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
        return;
    }
    media_path = (S8*) srv_mms_mem_mgr_app_adm_alloc((MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    MMI_ASSERT(media_path != NULL);
    memset(media_path, 0, (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) media_path, (S8*) path);

    /* mma_insert object check here */
    if (mmi_umms_composer_signature_check_object((S8*) path, UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED))
    {
        mmi_umms_app_callback_lsk_funct_add_audio();

    }

}
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_video_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]         [?]
 *  is_short(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_video_select_path_from_file_manager(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        mmi_umms_app_dtmgr_set_change_in_compose_signature(E_OFF);
        cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
        return;
    }

    media_path = (S8*) srv_mms_mem_mgr_app_adm_alloc((MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    MMI_ASSERT(media_path != NULL);
    memset(media_path, 0, (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) media_path, (S8*) path);
    /* mma insert object cehck here */

    if (mmi_umms_composer_signature_check_object((S8*) path, UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
    {
        mmi_umms_app_callback_lsk_funct_add_video();

    }

}
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_image_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]         [?]
 *  is_short(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_image_select_path_from_file_manager(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        mmi_umms_app_dtmgr_set_change_in_compose_signature(E_OFF);
        cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
        return;
    }
    media_path = (S8*) srv_mms_mem_mgr_app_adm_alloc((MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    MMI_ASSERT(media_path != NULL);
    memset(media_path, 0, (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) media_path, (S8*) path);

    if (mmi_umms_composer_signature_check_object((S8*) path, UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED))
    {
        mmi_umms_app_callback_lsk_funct_add_image();
    }
}
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_signature_done_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_signature_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);
    mmi_frm_group_close(GRP_ID_UMMS_LIST_INLINE_CUI_EXT);
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_multimedia_template_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_multimedia_template_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetNumOfChild(scrDB->RObj->menu_item_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_template_menu_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_template_menu_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    return str_item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_template_menu_list_of_descriptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id              [IN]        
 *  popUpList(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
WCHAR *mmi_umms_app_ui_callback_template_menu_list_of_descriptions(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 *popUpList[MAX_SUB_MENUS]; */
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[0], 0, sizeof(hintData[0]));
    sprintf((S8*) value, "%d ", srv_mms_get_userdef_template_num());
    if (srv_mms_get_userdef_template_num() > 1)
    {
        mmi_asc_to_ucs2((PS8) hintData[0], (PS8) value);
        mmi_ucs2cat((PS8) hintData[0], (S8*) GetString(STR_ID_UMMS_HINT_MESSAGES));
    }
    else
    {
        mmi_asc_to_ucs2((PS8) hintData[0], (PS8) value);
        mmi_ucs2cat((PS8) hintData[0], (S8*) GetString(STR_ID_UMMS_HINT_MESSAGE));
    }
    return (WCHAR*) (hintData[0]);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_callback_lsk_funct_add_audio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_callback_lsk_funct_add_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;
    U16 umms_fmgr_cui_id = mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);
    mmi_ucs2cpy((S8*) compose_settings_inline_items->auto_signature_audio_file, (S8*) media_path);
    mmi_umms_app_reset_buffer_for_signature();
    cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
    cui_file_selector_close(umms_fmgr_cui_id);
    /* mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_COMPOSE_IMAGE_OPTION); */
}
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_callback_lsk_funct_add_video
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_callback_lsk_funct_add_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;
    U16 umms_fmgr_cui_id = mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);
    mmi_ucs2cpy((S8*) compose_settings_inline_items->auto_signature_video_file, (S8*) media_path);
    mmi_umms_app_reset_buffer_for_signature();
    cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
    cui_file_selector_close(umms_fmgr_cui_id);
    /* mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_COMPOSE_IMAGE_OPTION); */
}
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_callback_lsk_funct_add_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_callback_lsk_funct_add_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    umms_inline_compose_items_struct *compose_settings_inline_items;
    U16 umms_fmgr_cui_id = mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    mmi_umms_app_dtmgr_set_change_in_compose_signature(E_ON);

    mmi_ucs2cpy((S8*) compose_settings_inline_items->auto_signature_image_file, (S8*) media_path);

    mmi_umms_app_reset_buffer_for_signature();
    cui_menu_close(mmi_umms_dtmgr_use_compose_image_gid());
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
    cui_file_selector_close(umms_fmgr_cui_id);

}

#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_check_compose_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_callback_check_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MAX_PAGE_SUPPORTED__
    U32 temp = 0;
#endif
    U16 temp_slide_time_value = 0;

    umms_inline_compose_items_struct *compose_settings_inline_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_settings_inline_items =
        (umms_inline_compose_items_struct*) mmi_umms_app_dtmgr_get_current_compose_settings_list();

    
#ifdef __MAX_PAGE_SUPPORTED__
	temp = gui_atoi((UI_string_type) compose_settings_inline_items->max_num_pages_buffer);

    if (mmi_ucs2ncmp((S8*) compose_settings_inline_items->max_num_pages_buffer, "\0", 1 * ENCODING_LENGTH) == 0)
    {
        /* mmi_umms_display_popup(
           (U8*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT),
           MMI_EVENT_PROPLEM); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }

    if (temp > UMMS_MAX_POSSIBLE_SLIDES || temp < 1)
    {
        /* mmi_umms_display_popup(
           (U8*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT),
           MMI_EVENT_PROPLEM); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }
#endif /* __MAX_PAGE_SUPPORTED__ */ 

    temp_slide_time_value = gui_atoi((UI_string_type) compose_settings_inline_items->defualt_slide_time_buffer);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (temp_slide_time_value == 0)
    {
        /* mmi_umms_display_popup(
           (U8*) GetString(STR_ID_UMMS_SLIDE_TIME_ZERO_ERROR),
           MMI_EVENT_ERROR); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_SLIDE_TIME_ZERO_ERROR), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }
#endif
#ifdef __MMI_MMS_SIGNATURE__
    if ((compose_settings_inline_items->auto_signature == E_ON)
        &&
        (mmi_ucs2ncmp
         ((S8*) compose_settings_inline_items->auto_signature_content, "\0",
          UMMS_MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0)
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items->auto_signature_image_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items->auto_signature_audio_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
        &&
        (mmi_ucs2cmp((S8*) compose_settings_inline_items->auto_signature_video_file,
                     (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
        )
    {
        /* mmi_umms_display_popup(
           (U8*) GetString(STR_ID_UMMS_AUTO_SIGN_ERROR),
           MMI_EVENT_ERROR); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_AUTO_SIGN_ERROR), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }
#endif /* __MMI_MMS_SIGNATURE__ */ 
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_reset_buffer_for_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_reset_buffer_for_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (media_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(media_path);
        media_path = NULL;
    }
}

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_display_next_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_display_next_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_um_iter_viewer_result_struct *other_msg_data;
    void *user_data = NULL;
    mmi_id parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();  /* (U16 *)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_GRP_ID); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_right_slide_button_up();
    other_msg_data =
        (mmi_um_iter_viewer_result_struct*) mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
    user_data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA);
    if (other_msg_data->next_launch_func_ptr)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER ||
            mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN ||
            mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN)
        {
            mmi_umms_app_ui_draw_dummy_screen();
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN);
        }
        mmi_umms_app_if_deinit_viewer();
        other_msg_data->index_number += 1;
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_umms_app_dtmgr_set_current_message_index(other_msg_data->index_number - 1);
    #endif 
        other_msg_data->next_launch_func_ptr(
                            parent_id,
                            other_msg_data->next_msg_id,
                            user_data,
                            CUI_MSG_VIEWER_TYPE_ITERATOR);

    }
}

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_display_next_mms_through_swipe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gesture_event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_display_next_mms_through_swipe(mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_callback_display_next_mms();
}
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_display_previous_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_display_previous_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *other_msg_data;
    void *user_data = NULL;
    mmi_id parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();  /* (U16 *)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_GRP_ID); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_left_slide_button_up();
    other_msg_data =
        (mmi_um_iter_viewer_result_struct*) mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
    user_data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA);
    if (other_msg_data->prev_launch_func_ptr)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER ||
            mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN ||
            mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN)
        {
            mmi_umms_app_ui_draw_dummy_screen();
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN);
        }
        mmi_umms_app_if_deinit_viewer();
        other_msg_data->index_number -= 1;
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        mmi_umms_app_dtmgr_set_current_message_index(other_msg_data->index_number - 1);
    #endif 
        other_msg_data->prev_launch_func_ptr(
                            parent_id,
                            other_msg_data->prev_msg_id,
                            user_data,
                            CUI_MSG_VIEWER_TYPE_ITERATOR);
    }

}

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_display_previous_mms_through_swipe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gesture_event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_display_previous_mms_through_swipe(mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_callback_display_previous_mms();
}
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_get_index_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  curr_msg_num        [?]     
 *  total_msg_num       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_get_index_data(U16 *curr_msg_num, U16 *total_msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_update_indexing_data_from_um(NULL);
    data = (mmi_um_iter_viewer_result_struct*) mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
    *total_msg_num = data->total_number;
    *curr_msg_num = data->index_number;

}

#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_tb_rr_dr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_tb_rr_dr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        mmi_umms_app_ui_plug_in_redraw_dr();
    }
    else
    {
        mmi_umms_app_ui_plug_in_delete_mms_from_toolbar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_tb_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_tb_notification(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        mmi_umms_app_ui_plug_in_download();
    }
    else
    {
        mmi_umms_app_ui_plug_in_delete_mms_from_toolbar();
    }
}

#endif /* __MMI_FTE_SUPPORT__ */ 
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_prefer_storage_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_prefer_storage_options_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_NO_CARD); */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id /* MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE */ );
#endif 
    return num_item;
}

#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_msg_filter_options_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_umms_app_ui_callback_msg_filter_options_decide(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_filter;
    U8 prefer_storage;
    U8 flag[2] = {0,0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_CARD, MMI_FALSE);
    cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_PHONE, MMI_FALSE);
    msg_filter = srv_mms_get_msg_filter();
	if(msg_filter & E_MSG_FILTER_PHONE)
		{
		    flag[0] = 1;
		}
	if((msg_filter & E_MSG_FILTER_CARD) && srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
		{
		    flag[1] = 1;
		}
    prefer_storage = srv_mms_get_mms_prefer_storage();
    if (prefer_storage == MMA_MSG_STORAGE_PHONE)
    {
        cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_PHONE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_CARD, MMI_TRUE);
    }

    if(!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_CARD, MMI_TRUE);
    }
    cui_menu_set_checkbox_state(menu_evt->sender_id, flag);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_prefer_storage_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id             [IN]        
 *  str_item_list       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_umms_app_ui_callback_prefer_storage_item_list(U16 menu_id, U16 *str_item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_item = 0, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_item = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, str_item_list);

    for (count = 0; count < num_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(str_item_list[count]), MAX_SUBMENU_CHARACTERS);
    }
    return (U16*) subMenuDataPtrs;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_move_copy_options_hide_unhide
 * DESCRIPTION
 *  mmi_umms_app_ui_callback_move_copy_options_hide_unhide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_move_copy_options_hide_unhide(void)
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
    if (info->msg_info->msg_storage == MMA_MSG_STORAGE_PHONE)
    {
        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE);
        #endif
		#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE);
		#endif
        if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
            #endif
			#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
            mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
			#endif
        }
        else
        {
            #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
            #endif
			#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
            mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
			#endif
        }
    }
    if (info->msg_info->msg_storage == MMA_MSG_STORAGE_CARD1)
    {
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
        #endif
        mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
        #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE);
        #endif
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE);
#endif

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_move_copy_options_hide_all
 * DESCRIPTION
 *  mmi_umms_app_ui_callback_move_copy_options_hide_all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_move_copy_options_hide_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_CARD);
    #endif
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_CARD);
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_MOVE_TO_PHONE);
    #endif
    mmi_frm_hide_menu_item(MENU_ID_UMMS_OPTIONS_COPY_TO_PHONE);
#endif
}

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_use_details_list_fte_tap_callback
 * DESCRIPTION
 *  mmi_umms_app_ui_use_details_list_fte_tap_callback
 *  action for intuitive command intiutive command is same as CSK functionlity
 *  for number ->call, email -->save to phb , URL -->launch the browser
 * PARAMETERS
 *  tap_type        [IN]        And hilighted_index
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_use_details_list_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_use_details_struct *data =
        (mmi_umms_app_dtmgr_use_details_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return; /* No action change hilighter by category */
    }
    else if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (APPLIB_ADDR_TYPE_PHONENUMBER == data->applib_addr_type)
        {
            mmi_umms_app_ui_plug_in_use_number_as_make_call();
        }
        /* #if (defined(__MMI_PHB_OPTIONAL_FIELD__))
           else if (APPLIB_ADDR_TYPE_EMAIL == data->applib_addr_type)
           {
           mmi_umms_app_ui_plug_in_use_email_as_save_to_phb();
           }
           #endif */

        else if (APPLIB_ADDR_TYPE_EMAIL == data->applib_addr_type)
        {
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            mmi_umms_app_ui_plug_in_use_email_as_save_to_phb();
        #else 
            mmi_umms_app_if_show_use_details_addresses_options();
        #endif 

        }
        else if (APPLIB_ADDR_TYPE_URL == data->applib_addr_type)
        {
            mmi_umms_app_ui_plug_in_use_url_as_browser_launch();
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_template_list_fte_tap_callback
 * DESCRIPTION
 *  mmi_umms_app_ui_use_details_list_fte_tap_callback
 * PARAMETERS
 *  tap_type        [IN]        And hilighted_index
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_template_list_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return; /* No action change hilighter by category */
    }
    else if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_umms_app_ui_plug_in_template_view_by_csk();
    }
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#endif /* __MMI_FTE_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sd_card_plug_in_hdlr_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_sd_card_plug_in_hdlr_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 drive_counter = 0;
    srv_fmgr_notification_dev_plug_event_struct *plug_in_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:

            plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*) param;

            for (i = 0; i < plug_in_info->count; i++)
            {
                if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
                {
                    drive_counter++;
                }
            }
            if (drive_counter)
            {
                srv_mms_sd_card_plug_in_hdlr(drive_counter);
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sd_card_plug_out_hdlr_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_sd_card_plug_out_hdlr_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 drive_counter = 0;
    srv_fmgr_notification_dev_plug_event_struct *plug_in_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:

            plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*) param;

            for (i = 0; i < plug_in_info->count; i++)
            {
                if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
                {
                    drive_counter++;
                }
            }
            if (drive_counter)
            {
                mmi_umms_app_core_handle_sd_card_plug_out(NULL);
                srv_mms_sd_card_plug_out_hdlr(drive_counter);
            }

            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_drv_format_hdlr_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_drv_format_hdlr_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            format_evt = (srv_fmgr_notification_format_event_struct*) param;
            if (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                srv_mms_drv_format_hdlr();
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_dr_rr_status_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_umms_app_ui_callback_dr_rr_status_get_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 priority_array[9];
    U8 priority_count = 0;
    U8 priority_flag = 0;
    U8 loop_flag = 0;
    U8 count = 0;
    U8 temp[TEMP_BUFFER_SIZE];
    S8 name[MMA_MAX_ADDR_LEN + 40];

    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    mma_result_enum result = 0;

    wap_mma_mms_msg_report_status_struct *temp_list, *list = info->status_list;
    U16 str_id = 0;
    MMI_BOOL is_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));
    if (list == NULL)
    {
        list =
            (wap_mma_mms_msg_report_status_struct*)
            srv_mms_mem_mgr_app_asm_alloc(sizeof(wap_mma_mms_msg_report_status_struct));
        MMI_ASSERT(list);
        result = mma_mms_get_msg_report_status_info(
                    info->msg_id,
                    list,
                    srv_mms_mem_mgr_app_asm_alloc,
                    srv_mms_mem_mgr_app_asm_free);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_RR_DR_GET_DATA_1, info->msg_id, scr_id, result);
        if (result != MMA_RESULT_OK)
        {
            srv_mms_mem_mgr_app_asm_free(list);
            list = NULL;
            return (U8*) subMenuData;
        }
        info->status_list = list;
    }

    MMI_ASSERT(list);
    memset(priority_array, 0, (sizeof(U8) * 9));
    if (scr_id == SCR_ID_UMMS_MMS_DELIVERY_STATUS)
    {
        priority_array[priority_count] = MMA_DR_STATUS_RETRIEVED;
        priority_array[++priority_count] = MMA_DR_STATUS_FORWARDED;
        priority_array[++priority_count] = MMA_DR_STATUS_DEFERRED;
        priority_array[++priority_count] = MMA_DR_STATUS_PENDING;
        priority_array[++priority_count] = MMA_DR_STATUS_EXPIRED;
        priority_array[++priority_count] = MMA_DR_STATUS_REJECTED;
        priority_array[++priority_count] = MMA_DR_STATUS_UNRECOGNISED;
        priority_array[++priority_count] = MMA_DR_STATUS_UNREACHABLE;
        priority_array[++priority_count] = MMA_DR_STATUS_INDETERMINATE;

        for (count = 0; count <= priority_count; ++count)
        {
            temp_list = list;
            priority_flag = 0;
            while (temp_list != NULL)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_RR_DR_GET_DATA_2,
                    count,
                    priority_flag,
                    temp_list->dr_status,
                    temp_list->rr_status,
                    temp_list->addr_type,
                    temp_list->addr_group,
                    temp_list->addr_len);
                if (priority_array[count] == temp_list->dr_status)
                {
                    if (priority_flag == 0)
                    {
                        priority_flag = 1;

                        if (loop_flag)
                        {
                            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
                            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        }
                        else
                        {
                            loop_flag = 1;
                        }

                        str_id = mmi_umms_app_util_get_string_for_msg_dr_status((U8) priority_array[count]);

                        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(str_id));
                        memset(temp, 0x00, TEMP_BUFFER_SIZE);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) ";");

                        if (temp_list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                        {
                            memset(name, 0, MMA_MAX_ADDR_LEN + 40);
                            is_found = srv_phb_get_name_by_number(
                                        temp_list->address,
                                        (U16*) name,
                                        (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            if (is_found == MMI_FALSE)
                            {
                                mmi_ucs2ncat(
                                    (S8*) subMenuData,
                                    (S8*) temp_list->address,
                                    (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                            else
                            {
                                mmi_ucs2ncat((S8*) subMenuData, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                        }
                        else
                        {
                            mmi_ucs2ncat(
                                (S8*) subMenuData,
                                (S8*) temp_list->address,
                                (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                        }

                    }
                    else
                    {
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        if (temp_list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                        {
                            memset(name, 0, MMA_MAX_ADDR_LEN + 40);
                            is_found = srv_phb_get_name_by_number(
                                        temp_list->address,
                                        (U16*) name,
                                        (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            if (is_found == MMI_FALSE)
                            {
                                mmi_ucs2ncat(
                                    (S8*) subMenuData,
                                    (S8*) temp_list->address,
                                    (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                            else
                            {
                                mmi_ucs2ncat((S8*) subMenuData, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                        }
                        else
                        {
                            mmi_ucs2ncat(
                                (S8*) subMenuData,
                                (S8*) temp_list->address,
                                (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                        }
                    }
                }
                temp_list = temp_list->next;
            }
        }

    }
    else if (scr_id == SCR_ID_UMMS_MMS_READ_STATUS)
    {
        priority_array[priority_count] = MMA_RR_STATUS_READ;
        priority_array[++priority_count] = MMA_RR_STATUS_DELETED_NO_READ;
        priority_array[++priority_count] = MMA_RR_STATUS_PENDING;

        for (count = 0; count <= priority_count; ++count)
        {
            temp_list = list;
            priority_flag = 0;
            while (temp_list != NULL)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_RR_DR_GET_DATA_2,
                    count,
                    priority_flag,
                    temp_list->dr_status,
                    temp_list->rr_status,
                    temp_list->addr_type,
                    temp_list->addr_group,
                    temp_list->addr_len);
                if (priority_array[count] == temp_list->rr_status)
                {
                    if (priority_flag == 0)
                    {
                        priority_flag = 1;

                        if (loop_flag)
                        {
                            mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
                            mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        }
                        else
                        {
                            loop_flag = 1;
                        }

                        str_id = mmi_umms_app_util_get_string_for_msg_rr_status((U8) priority_array[count]);

                        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(str_id));
                        memset(temp, 0x00, TEMP_BUFFER_SIZE);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) "\n");
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        mmi_asc_to_ucs2((PS8) temp, (PS8) ";");
                        if (temp_list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                        {
                            memset(name, 0, MMA_MAX_ADDR_LEN + 40);
                            is_found = srv_phb_get_name_by_number(
                                        temp_list->address,
                                        (U16*) name,
                                        (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            if (is_found == MMI_FALSE)
                            {
                                mmi_ucs2ncat(
                                    (S8*) subMenuData,
                                    (S8*) temp_list->address,
                                    (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                            else
                            {
                                mmi_ucs2ncat((S8*) subMenuData, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                        }
                        else
                        {
                            mmi_ucs2ncat(
                                (S8*) subMenuData,
                                (S8*) temp_list->address,
                                (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                        }
                    }
                    else
                    {
                        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
                        if (temp_list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
                        {
                            memset(name, 0, MMA_MAX_ADDR_LEN + 40);
                            is_found = srv_phb_get_name_by_number(
                                        temp_list->address,
                                        (U16*) name,
                                        (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            if (is_found == MMI_FALSE)
                            {
                                mmi_ucs2ncat(
                                    (S8*) subMenuData,
                                    (S8*) temp_list->address,
                                    (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                            else
                            {
                                mmi_ucs2ncat((S8*) subMenuData, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                            }
                        }
                        else
                        {
                            mmi_ucs2ncat(
                                (S8*) subMenuData,
                                (S8*) temp_list->address,
                                (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
                        }
                    }
                }
                temp_list = temp_list->next;
            }
        }
    }

    return (U8*) subMenuData;
}

#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 

/* Proc functions */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
#if defined (__MMI_MSG_FTE_ENHANCE__) && defined (__MMI_IMAGE_VIEWER__)
    mmi_group_event_struct *p_event = (mmi_group_event_struct*) evt;
#endif
    mmi_event_popoupcallback_result_struct *popup_evt = (mmi_event_popoupcallback_result_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct*) evt;

            if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER)
            {
                if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
                {
                    return MMI_RET_OK;
                }
                else if (key_evt->key_type == KEY_EVENT_DOWN)
                {
                    mmi_umms_app_ui_callback_viewer_stop_callback();
                    return MMI_RET_KEY_HANDLED;
                }
            }
            else if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_DISPLAY_INFINITE_POPUP)
            {
                if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
                {
                    if (srv_bootup_is_completed())
                    {
                        mmi_idle_display();
                    }
                    return MMI_RET_OK;
                }
                if (key_evt->key_type == KEY_EVENT_UP)
                {
                    mmi_frm_scrn_close_active_id();
                    return MMI_RET_KEY_HANDLED;
                }
            }
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	    else if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_CONFIRM)
            {
                if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
                {
                    mmi_umms_app_dtmgr_set_menu_cui_id(GRP_ID_INVALID);
                    return MMI_RET_OK;
                }
                if (key_evt->key_type == KEY_EVENT_UP)
                {
                    mmi_umms_app_dtmgr_set_menu_cui_id(GRP_ID_INVALID);
                    return MMI_RET_OK;
                }
            }
#endif
            break;
        }
        case EVT_ID_GROUP_ENTER:
            break;
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_INACTIVE:
            break;
        case EVT_ID_GROUP_FOCUSED:
            break;
        case EVT_ID_GROUP_DEFOCUSED:
            break;
        case EVT_ID_GROUP_GOBACK:
            break;
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_GROUP_DELETE_REQ:
            break;
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            break;
    #if defined (__MMI_MSG_FTE_ENHANCE__) && defined (__MMI_IMAGE_VIEWER__)
        case EVT_ID_IMGVIEW_CLOSE_GID:
        {
            S32 *parent_fh = mmi_umms_app_dtmgr_get_parent_file_hdl();

            cui_imgview_close(p_event->sender_id);
            if (*parent_fh)
            {
                FS_Close(*parent_fh);
            }
            *parent_fh = 0;
            break;
        }
    #endif /* defined (__MMI_MSG_FTE_ENHANCE__) && defined (__MMI_IMAGE_VIEWER__) */ 
        case EVT_ID_GROUP_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_umms_dtmgr_set_group_flag(MMI_FALSE);
            if (mmi_umms_dtmgr_get_group_id() == GRP_ID_UMMS_COMM_SLIM_OPTIONS)
            {
                mmi_umms_app_dtmgr_reset_data();
                mmi_umms_app_dtmgr_set_menu_cui_id(GRP_ID_INVALID);
            }
            break;
        case EVT_ID_GOBACK_HISTORY:
            break;
        case EVT_ID_CUI_MENU_LIST_ENTRY:

            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_UMMS_DRAFT_OPTIONS:
                    mmi_umms_app_ui_callback_draft_options_decide(SCR_ID_UMMS_DRAFT_OPTION);
                    break;
                case MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS:
                    mmi_umms_app_ui_callback_inbox_mms_options_decide(SCR_ID_UMMS_INBOX_MMS_OPTION);
                    break;
                case MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION:
                    mmi_umms_app_ui_callback_download_options_decide(evt);
                    mmi_umms_app_ui_callback_inbox_notification_options_decide(SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
                    break;
                case MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT:
                    mmi_umms_app_ui_callback_inbox_read_delivery_options_decide(SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
                    break;
                case MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS:
                    mmi_umms_app_ui_callback_inbox_java_mms_options_decide(SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION);
                    break;
                case MENU_ID_UMMS_SENT_OPTIONS:
                    mmi_umms_app_ui_callback_sent_options_decide(SCR_ID_UMMS_SENT_OPTION);
                    break;
                case MENU_ID_UMMS_OUTBOX_OPTIONS:
                    mmi_umms_app_ui_callback_resend_options_decide(evt);
                    mmi_umms_app_ui_callback_outbox_options_decide(SCR_ID_UMMS_OUTBOX_OPTION);
                    break;
            #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
                case MENU_ID_UMMS_REPORT_BOX_OPTIONS:
                    mmi_umms_app_ui_callback_report_box_options_decide(0);
                    break;
            #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
                case MENU_ID_UMMS_OPTIONS_RESEND:
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_umms_app_ui_callback_sim_options_decide(evt);
#endif
                    break;
#if((MMI_MAX_SIM_NUM >= 3) && defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
                    case MENU_ID_UMMS_SIM_SEL_DOWNLOAD:
                    mmi_umms_app_ui_callback_sim_options_decide(evt);
                    break;
#endif                 
            #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MENU_ID_UMMS_TEMPLATES_OPTIONS:
                {
                    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;

                    scr_info =
                        (mmi_umms_app_dtmgr_option_scr_data_struct*)
                        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
                    if (scr_info == NULL)
                    {
                        return MMI_UMMS_FALSE;
                    }
                    if (!scr_info->is_already_viewed)
                    {
                        mmi_umms_dtmgr_set_proc_flag(FALSE);
                    }
                    mmi_umms_app_ui_callback_user_defined_template_options_decide(SCR_ID_UMMS_TEMPLATES_OPTIONS);
                }
                    break;
            #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
                case MENU_ID_UMMS_OPTIONS_USE_DETAILS:
                    mmi_umms_app_ui_callback_use_details_menu_screen_item(0);
                    break;
                case MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS:
                    /* mmi_umms_app_ui_callback_save_objects_items_count(0); */
                    break;
#ifdef __MMI_MMS_SIGNATURE__
                case MENU_ID_UMMS_SIGNATURE_OPTION:
                    mmi_umms_app_ui_callback_signature_options_get_no_of_items(SCR_ID_UMMS_COMPOSE_IMAGE_OPTION);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
#endif
            #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
                case MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE:
                    mmi_umms_app_ui_callback_prefer_storage_options_decide(SCR_ID_UMMS_MMS_PREFER_STORAGE);
                    break;
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
				case MENU_ID_UMMS_MMS_SETTINGS_STORAGE_FILTER:
					    mmi_umms_app_ui_callback_msg_filter_options_decide(menu_evt);
						break;
#endif
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_MMS_SETTINGS_SENDING:
                case MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL:
#endif
                case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS:
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_NUMBER:
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_EMAIL:
            #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_URL:
            #endif
                    mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_item
                        (SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS);
                    break;
            #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MENU_ID_UMMS_TEMPLATE_MMS:
                {
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_ID_UMMS_TEMPLATES_USER_DEFINED,
                        mmi_umms_app_ui_callback_template_menu_list_of_descriptions(0));
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                }
                    break;
            #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
                case MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS:
                    mmi_umms_app_ui_callback_common_settings_decide();
            #if(MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION:
                    mmi_umms_app_ui_callback_sim_decide(SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION);    /* hide and show leaf node item */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
            #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                    mmi_umms_app_ui_callback_compose_option_decide(SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION);
            #endif 
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
			#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_MMS_SETTINGS:
                    mmi_umms_app_ui_plug_in_mms_message_settings_menu_post_func(0);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
			#endif
                case MENU_ID_UMMS_PREVIEW_OPTION:
                    break;
            #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_COMPOSER_OPTIONS:
                    mmi_umms_app_ui_callback_composer_options_decide(MENU_ID_UMMS_COMPOSER_OPTIONS);
					 cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
                case MENU_ID_UMMS_RECIPIENT_SLIM:
                    mmi_umms_app_ui_callback_recipient_options_decide(SCR_ID_UMMS_ADD_RECIPIENT_OPTION);
					 cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
                case MENU_ID_UMMS_OPTIONS_SLIM:
                    mmi_umms_app_ui_callback_slim_options_decide(MENU_ID_UMMS_OPTIONS_SLIM);
					 cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
                case MENU_ID_UMMS_OPTIONS_SLIM_SEND :
					#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                      mmi_umms_app_ui_callback_sim_options_decide(evt);
                    #endif
                      cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
				case MENU_ID_UMMS_INSERT :
					 mmi_umms_app_ui_callback_insert_options_decide(MENU_ID_UMMS_INSERT);
                     cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
					 break;

            #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
            }
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_UMMS_DRAFT_OPTIONS:
                case MENU_ID_UMMS_INBOX_OPTIONS_NEW_MMS:
                case MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION:
                case MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT:
                case MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS:
                case MENU_ID_UMMS_SENT_OPTIONS:
                case MENU_ID_UMMS_OUTBOX_OPTIONS:
            #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
                case MENU_ID_UMMS_REPORT_BOX_OPTIONS:
            #endif 
            #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MENU_ID_UMMS_TEMPLATES_OPTIONS:
            #endif 
            #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_OPTIONS_SLIM:
                case MENU_ID_UMMS_RECIPIENT_SLIM:
                case MENU_ID_UMMS_OPTIONS_SLIM_SEND:
                //case MENU_ID_UMMS_SLIM_OPTIONS_REPLY:
            #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
                    mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);

                    mmi_umms_app_sh_mms_option_mms_handler(menu_evt->highlighted_menu_id, menu_evt->sender_id);
                    break;
#ifdef __MMI_MMS_SIGNATURE__
                case MENU_ID_UMMS_SIGNATURE_OPTION:
                    mmi_umms_app_sh_signature_options_handler(menu_evt->highlighted_menu_id);   /* handle leaf node item */
                    break;
#endif
            #if(MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION:
                    mmi_umms_app_sh_settings_sim_selection_handler(menu_evt->highlighted_menu_id);      /* handle leaf node item */
                    break;
            #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
                case MENU_ID_UMMS_PREVIEW_OPTION:
                    mmi_umms_dtmgr_set_proc_flag(KAL_TRUE);
                    mmi_umms_app_ui_plug_in_preview_option_handling(menu_evt->highlighted_menu_id, 0);
                    break;
#if((MMI_MAX_SIM_NUM >= 3) && defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
                case MENU_ID_UMMS_SIM_SEL_DOWNLOAD:
                    mmi_umms_app_ui_callback_sim_sel_post_action_decide(evt);      /* handle leaf node item */
                    break;
#endif
                case MENU_ID_UMMS_OPTIONS_RESEND:
                    mmi_umms_app_sh_sim_option_mms_handler(menu_evt->highlighted_menu_id);      /* handle leaf node item */
                    break;
                case MENU_ID_UMMS_OPTIONS_USE_DETAILS:
                    mmi_umms_app_sh_use_detail_options_hdlr(menu_evt->highlighted_menu_id);
                    break;
                case MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS:
                    mmi_umms_app_sh_save_objects_list_handler(menu_evt->highlighted_menu_id);
                    break;
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_NUMBER:
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_EMAIL:
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
                case MENU_ID_UMMS_USE_DETAILS_ADDRESSES_USE_URL:
#endif
                    mmi_umms_app_ui_plug_in_use_details_list_addresses_options_lsk_handler(menu_evt->
                                                                                           highlighted_menu_id);
                    break;
            #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
                case MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS:
                    mmi_umms_app_sh_mms_memory_status_handler(menu_evt->highlighted_menu_id);
                    break;
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
                case MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE:
                    if (mmi_umms_app_sh_mms_pref_storage_handler(menu_evt->highlighted_menu_id) == MMI_UMMS_TRUE)
                    {
                        cui_menu_close(menu_evt->sender_id);
                    }
                    break;
#endif
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
                case MENU_ID_UMMS_MMS_SETTINGS_STORAGE_FILTER:
                    if (mmi_umms_app_sh_mms_msg_filter_handler(evt) == MMI_UMMS_TRUE)
                    {
                        cui_menu_close(menu_evt->sender_id);
                    }
                    break;
#endif
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MENU_ID_UMMS_TEMPLATE_MMS:
                    mmi_umms_app_sh_template_menu_list_handler(menu_evt->highlighted_menu_id);
                    break;
                #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
                case MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS:
                    mmi_umms_app_sh_mms_common_settings_handler(menu_evt->highlighted_menu_id);
                    break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_MMS_SETTINGS:
                    mmi_umms_app_sh_mms_message_settings_handler(menu_evt->highlighted_menu_id);
                    break;
#endif
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            if (mmi_umms_app_dtmgr_get_menu_cui_id() == menu_evt->sender_id)
            {
                mmi_umms_app_dtmgr_set_menu_cui_id(menu_evt->sender_id);
                mmi_umms_app_sh_option_slim_menu_rsk_handler();
                return MMI_RET_ERR;
            }
        #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
            mmi_umms_app_ui_callback_prop_unhide_all_menu_options(0);
            if (FALSE == mmi_umms_dtmgr_get_proc_flag())
            {
                mmi_umms_app_dtmgr_reset_data();
            }
            cui_menu_close(menu_evt->sender_id);
            break;
        case EVT_ID_POPUP_QUIT:
        {
            if (popup_evt->result == MMI_POPUP_NORMAL_EXIT && popup_evt->user_tag)
            {
                typedef void (*myfunc) (void);

                ((myfunc) popup_evt->user_tag) ();
            }
        }
            break;
			
    }
    if (evt->evt_id == EVT_ID_UMMS_DEINIT_FROM_HISTORY)
    {
        /* mmi_umms_app_if_deinit_viewer -> delete progressscreen */
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_umms_app_if_deinit_viewer();
        mmi_frm_scrn_close_active_id();
    }
    /* Call here UC Proc function to broadcast events to UC */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_uc_event_handler_proc(evt);

    mmi_umms_settings_hdlr(evt);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_template_grp_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_template_grp_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            break;
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_INACTIVE:
            break;
        case EVT_ID_GROUP_FOCUSED:
            if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
            {
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
            }
            break;
        case EVT_ID_GROUP_DEFOCUSED:
            break;
        case EVT_ID_GROUP_GOBACK:
            break;
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_GROUP_DELETE_REQ:
            break;
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            break;
        case EVT_ID_GROUP_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_umms_dtmgr_set_tenplate_group_flag(MMI_FALSE);
            mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
            /* if(mmi_umms_app_dtmgr_state_asm_waiting() == MMI_FALSE && mmi_umms_app_dtmgr_get_parent_grp_id() != GRP_ID_ROOT)
               {
               mmi_event_struct evt;
               memset(&evt, 0, sizeof(mmi_event_struct));
               MMI_FRM_INIT_EVENT(&evt, EVT_ID_GROUP_DEINIT);
               mmi_frm_scrn_send_to_parent(mmi_umms_app_dtmgr_get_parent_grp_id(), &evt);
               } */
            break;
        case EVT_ID_GOBACK_HISTORY:
            break;
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_TEMPLATES);
        #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MENU_ID_UMMS_TEMPLATE_MMS:
        {
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_ID_UMMS_TEMPLATES_USER_DEFINED,
                mmi_umms_app_ui_callback_template_menu_list_of_descriptions(0));
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        }
            break;
        #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->parent_menu_id)
            {
            #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MENU_ID_UMMS_TEMPLATE_MMS:
                    mmi_umms_app_sh_template_menu_list_handler(menu_evt->highlighted_menu_id);
                    break;
            #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
            }
        case MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS:
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_MMS_SETTINGS:
#endif
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (FALSE == mmi_umms_dtmgr_get_proc_flag())
            {
                mmi_umms_app_dtmgr_reset_data();
            }
            cui_menu_close(menu_evt->sender_id);
        case EVT_ID_POPUP_QUIT:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_popupcallback_ext_proc_fun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_popupcallback_ext_proc_fun(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct *pop_event;
    mmi_umms_app_ui_draw_display_callback_popup_screen_struct *callback_popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pop_event = (mmi_event_popoupcallback_result_struct*) evt;
    callback_popup_data =
        (mmi_umms_app_ui_draw_display_callback_popup_screen_struct*)
        mmi_umms_app_dtmgr_get_callback_popup_screen_data();
    if (pop_event->evt_id == EVT_ID_POPUP_QUIT)
    {
        switch (pop_event->result)
        {
            case MMI_POPUP_NORMAL_EXIT:
            case MMI_ALERT_NO_SHOW:
                callback_popup_data->success_callback();
                break;
            case MMI_POPUP_INTERRUPT_EXIT:
                callback_popup_data->failure_callback();
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_inline_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_inline_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct*) evt;
    mmi_umms_app_ui_draw_inline_cui_selection_screen_struct *screen_data =
        (mmi_umms_app_ui_draw_inline_cui_selection_screen_struct*) (inline_evt->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            mmi_umms_app_sh_inline_selection_delete_scr_handler(evt);
            break;
        case EVT_ID_CUI_INLINE_ABORT:
        {
            if (inline_evt->sender_id == mmi_umms_dtmgr_get_inline_gid())
            {
                cui_inline_close(mmi_umms_dtmgr_get_inline_gid());
            }
            else if (inline_evt->sender_id == mmi_umms_dtmgr_get_inline_gid_ext())
            {
            #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
                if (mmi_umms_app_dtmgr_get_signature_audio_disp_path() != NULL)
                {
                    srv_mms_mem_mgr_app_adm_free(mmi_umms_app_dtmgr_get_signature_audio_disp_path());
                    mmi_umms_app_dtmgr_set_signature_audio_disp_path(NULL);
                }
            #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
                cui_inline_close(mmi_umms_dtmgr_get_inline_gid_ext());
            }
        }
            break;
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS)
            {
                umms_inline_compose_items_struct *compose_settings_inline_items;

                compose_settings_inline_items = mmi_umms_app_dtmgr_get_current_compose_settings_list();
                cui_inline_get_value(
                    mmi_umms_dtmgr_get_inline_gid(),
                    E_COMPOSE_CREATION_MODES,
                    (void*)&(compose_settings_inline_items->creation_mode));
                if (mmi_umms_app_ui_plug_in_get_change_in_compose_signature() == MMI_TRUE)
                {
                    cui_inline_set_screen_attributes(
                        mmi_umms_dtmgr_get_inline_gid_ext(),
                        CUI_INLINE_SET_ATTRIBUTE,
                        CUI_INLINE_SCREEN_CHANGED);
                }
                mmi_umms_app_ui_callback_compose_signature_settings_set_flag();
            }
            if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SETTINGS)
            {
                if (mmi_umms_app_ui_plug_in_get_change_in_compose_signature() == MMI_TRUE)
                {
                    cui_inline_set_screen_attributes(
                        mmi_umms_dtmgr_get_inline_gid(),
                        CUI_INLINE_SET_ATTRIBUTE,
                        CUI_INLINE_SCREEN_CHANGED);
                }
            }
            break;
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            switch (screen_data->scrn_id)
            {
                case SCR_ID_UMMS_COMPOSE_SETTINGS:
                {
                    umms_inline_compose_items_struct *compose_settings_inline_items;

                    compose_settings_inline_items = mmi_umms_app_dtmgr_get_current_compose_settings_list();
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_DEFAULT_SLIDE_TIME,
                        (void*)&(compose_settings_inline_items->defualt_slide_time_buffer));
                #ifdef __LAYOUT_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_LAYOUT,
                        (void*)&(compose_settings_inline_items->layout));
                #endif /* __LAYOUT_SUPPORT__ */ 
                #ifdef __DRM_SUPPORT__
                #ifdef __UMMS_DRM_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_ADD_DRM,
                        (void*)&(compose_settings_inline_items->add_drm));
                #endif /* __UMMS_DRM_SUPPORT__ */ 
                #endif /* __DRM_SUPPORT__ */ 
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_CREATION_MODES,
                        (void*)&(compose_settings_inline_items->creation_mode));
                #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_IMAGE_RESIZING,
                        (void*)&(compose_settings_inline_items->image_resize_option));
                #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
                #ifdef __MAX_PAGE_SUPPORTED__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_MAX_NO_PAGES,
                        (void*)&(compose_settings_inline_items->max_num_pages_buffer));
                #endif /* __MAX_PAGE_SUPPORTED__ */ 
                #ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_BEST_PAGE_DURATION,
                        (void*)&(compose_settings_inline_items->best_page_duration));
                #endif /* __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__ */ 
                #ifdef __MMI_MMS_SIGNATURE__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_COMPOSE_AUTO_SIGNATURE,
                        (void*)&(compose_settings_inline_items->auto_signature));
                #endif /* __MMI_MMS_SIGNATURE__ */ 
                    /* cui_inline_close(mmi_umms_dtmgr_get_inline_gid()); */
                    mmi_umms_app_ui_plug_in_confirm_save_compose_settings();
                    break;
                }
                case SCR_ID_UMMS_SENDING_SETTINGS:
                {
                    umms_inline_sending_items_struct *sending_settings_inline_items;

                    sending_settings_inline_items = mmi_umms_app_dtmgr_get_current_sending_settings_list();

                #ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_VALIDITY_PERIOD,
                        (void*)&(sending_settings_inline_items->validity_period));
                #endif /* __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__ */ 

                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_DELIVERY_REPORT,
                        (void*)&(sending_settings_inline_items->delivery_report));

                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_READ_REPORT,
                        (void*)&(sending_settings_inline_items->read_report));

                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_PRIORITY,
                        (void*)&(sending_settings_inline_items->priority));

                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_DELIVERY_TIME,
                        (void*)&(sending_settings_inline_items->delivery_time));
                #ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_HIDE_SENDER,
                        (void*)&(sending_settings_inline_items->hide_sender));
                #endif /* __MMI_MMS_HIDE_SENDER_SUPPORT__ */ 
                    /* send and save start */
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_SEND_AND_SAVE,
                        (void*)&(sending_settings_inline_items->send_and_save));

                    /* send and save ends */
                #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_SENDING_SIZE_LIMIT,
                        (void*)&(sending_settings_inline_items->size));
                #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

                    /* cui_inline_close(mmi_umms_dtmgr_get_inline_gid()); */
                    mmi_umms_app_ui_plug_in_confirm_save_sending_settings();
                    break;
                }
                case SCR_ID_UMMS_RETRIEVAL_SETTINGS:
                {
                    umms_inline_retrieval_items_struct *retrieval_settings_inline_items;

                    retrieval_settings_inline_items = mmi_umms_app_dtmgr_get_current_retrieval_settings_list();
                #ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__

                    if (srv_nw_info_is_roaming(MMI_SIM1) == TRUE)
                    {
                        cui_inline_get_value(
                            mmi_umms_dtmgr_get_inline_gid(),
                            E_RETRIEVAL_HOME_NETWORK,
                            (void*)&(retrieval_settings_inline_items->home_network));
                        cui_inline_get_value(
                            mmi_umms_dtmgr_get_inline_gid(),
                            E_RETRIEVAL_ROAMING,
                            (void*)&(retrieval_settings_inline_items->roaming));
                    }
                    else
                    {
                        cui_inline_get_value(
                            mmi_umms_dtmgr_get_inline_gid(),
                            E_RETRIEVAL_HOME_NETWORK,
                            (void*)&(retrieval_settings_inline_items->home_network));
                    }
                #elif defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_HOME_NETWORK,
                        (void*)&(retrieval_settings_inline_items->home_network));
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_ROAMING,
                        (void*)&(retrieval_settings_inline_items->roaming));
                #else 
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_HOME_NETWORK,
                        (void*)&(retrieval_settings_inline_items->home_network));
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_ROAMING,
                        (void*)&(retrieval_settings_inline_items->roaming));
                #endif 

                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_READ_REPORT,
                        (void*)&(retrieval_settings_inline_items->read_report));
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid(),
                        E_RETRIEVAL_DELIVERY_REPORT,
                        (void*)&(retrieval_settings_inline_items->delivery_report));
                    mmi_umms_app_ui_plug_in_confirm_save_retrieval_settings();
                    break;
                }
                case SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS:
                {
                    umms_inline_retrieval_items_struct *retrieval_settings_inline_items;

                    retrieval_settings_inline_items = mmi_umms_app_dtmgr_get_current_retrieval_settings_list();
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid_ext(),
                        E_RETRIEVAL_FILTERS_ANONYMOUS,
                        (void*)&(retrieval_settings_inline_items->anonymous_filter));
                    cui_inline_get_value(
                        mmi_umms_dtmgr_get_inline_gid_ext(),
                        E_RETRIEVAL_FILTERS_ADVERTISEMENT,
                        (void*)&(retrieval_settings_inline_items->advertisement_filter));
                    mmi_umms_app_dtmgr_set_recieve_filters_done(MMI_TRUE);
                    cui_inline_close(mmi_umms_dtmgr_get_inline_gid_ext());
                    break;
                }
#ifdef __MMI_MMS_SIGNATURE__
                case SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS:
                {
                    mmi_umms_signature_done_handler();
                    cui_inline_close(mmi_umms_dtmgr_get_inline_gid_ext());
                #ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
                    if (mmi_umms_app_dtmgr_get_signature_audio_disp_path() != NULL)
                    {
                        srv_mms_mem_mgr_app_adm_free(mmi_umms_app_dtmgr_get_signature_audio_disp_path());
                        mmi_umms_app_dtmgr_set_signature_audio_disp_path(NULL);
                    }
                #endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
                    break;
                }
#endif
            }
        }
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*) evt;

            switch (notify_evt->event_type)
            {
                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                {
                    if (screen_data->scrn_id == SCR_ID_UMMS_RETRIEVAL_SETTINGS)
                    {
                        mmi_umms_app_sh_retrieval_settings_hilite_handler(notify_evt->item_id);
                    }
                    else if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SETTINGS)
                    {
                        mmi_umms_app_sh_compose_settings_hilite_handler(notify_evt->item_id);
                    }
#ifdef __MMI_MMS_SIGNATURE__
                    else if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS)
                    {
                        mmi_umms_app_sh_compose_signature_settings_hilite_handler(notify_evt->item_id);

                    }
#endif
                    break;
                }
                case CUI_INLINE_NOTIFY_ITEM_CHANGED:
                    if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SETTINGS)
                    {
                        umms_inline_compose_items_struct *compose_settings_inline_items;

                        compose_settings_inline_items = mmi_umms_app_dtmgr_get_current_compose_settings_list();
                        cui_inline_get_value(
                            mmi_umms_dtmgr_get_inline_gid(),
                            E_COMPOSE_CREATION_MODES,
                            (void*)&(compose_settings_inline_items->creation_mode));
                    }
                    if (screen_data->scrn_id == SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS)
                    {
                        /* set the flag here */
                        mmi_umms_app_dtmgr_set_recieve_filters_done(MMI_TRUE);
                        mmi_umms_app_sh_retrieval_settings_hilite_handler(notify_evt->item_id);

                    }
#ifdef __MMI_MMS_SIGNATURE__
                    if (screen_data->scrn_id == SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS)
                    {
                        /* set the flag here */
                        mmi_umms_app_dtmgr_set_change_in_compose_signature(MMI_TRUE);
                        mmi_umms_app_sh_compose_settings_hilite_handler(notify_evt->item_id);

                    }
#endif

            }
        }
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_fmgr_forward_mms_enabler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_fmgr_forward_mms_enabler(
        mmi_menu_id item_id,
        const WCHAR *filepath,
        const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S8* filepath; */

#ifdef __MMI_MMS_2__
#ifdef __MMI_MMS_POSTCARD__
    MMI_BOOL can_insert = MMI_FALSE;
    mmi_fmgr_filetype_enum type;
#endif /* __MMI_MMS_POSTCARD__ */ 
#endif /* __MMI_MMS_2__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //filepath = mmi_fmgr_get_current_fileinfo(NULL, &app_id);
    //filepath = mmi_fmgr_util_extract_filename(filepath);
    if (fileinfo->type == FMGR_TYPE_FOLDER)
    {
    #ifdef __MMI_MMS_2__
    #ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
    #endif 
    #ifdef __MMI_MMS_POSTCARD__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD);
    #endif 
    #endif /* __MMI_MMS_2__ */ 
        mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_MMS);
        return;
    }

    if (mms_is_content_forward((char*)filepath) == MMI_FALSE)
    {
    #ifdef __MMI_MMS_2__
    #ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
    #endif 
    #ifdef __MMI_MMS_POSTCARD__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD);
    #endif 
    #endif /* __MMI_MMS_2__ */ 
        mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_MMS);
        return;
    }

#ifdef __MMI_MMS_2__
#ifdef __MMI_MMS_POSTCARD__

    type = srv_fmgr_types_find_type_by_filename_str((WCHAR*) filepath);
    can_insert = mmi_umms_app_if_check_mms_insert_postcard(type, (char*)filepath);
    if (!can_insert)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD);
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
#endif /* __MMI_MMS_2__ */ 
}

#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__  
wgui_mv_image_decode_status_enum mmi_umms_app_ui_callback_decode_image(U16 *src_path, U32 width_orig, U32 height_orig, U32 width_final, U32 height_final, U16 slide_id)
{
	return mmi_umms_app_dtmgr_start_image_decoder(src_path, width_orig, height_orig, width_final, height_final, slide_id);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_common_settings_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  menu_id(?)      [IN]        
 *  str_item_list     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_callback_common_settings_decide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_MMS_SETTINGS_EDIT_PROFILE);

    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >=2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif 
#if (MMI_MAX_SIM_NUM >=3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif 
#if (MMI_MAX_SIM_NUM >=4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif 
        )
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTINGS_EDIT_PROFILE);
    }

}

#if(MMI_MAX_SIM_NUM >= 2)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id          [IN]        
 *  menu_id(?)      [IN]        
 *  str_item_list       [?](?)
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_sim_decide(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_item = 0;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM1);
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM2);
#if(MMI_MAX_SIM_NUM >= 3)
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM3);
#endif 
#if(MMI_MAX_SIM_NUM >= 4)
    mmi_frm_unhide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM4);
#endif 
    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM1);
    }
#if (MMI_MAX_SIM_NUM >=2)
    if (!srv_sim_ctrl_is_available(MMI_SIM2))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM2);
    }
#endif /* (MMI_MAX_SIM_NUM >=2) */ 
#if (MMI_MAX_SIM_NUM >=3)
    if (!srv_sim_ctrl_is_available(MMI_SIM3))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM3);
    }
#endif /* (MMI_MAX_SIM_NUM >=3) */ 
#if (MMI_MAX_SIM_NUM >=4)
    if (!srv_sim_ctrl_is_available(MMI_SIM4))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_MMS_SETTING_SIM4);
    }
#endif /* (MMI_MAX_SIM_NUM >=4) */ 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__       /* vaibhav changes */
    num_item = GetNumOfChild_Ext(scrDB->RObj->menu_item_id /* MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION */ );
#endif 
    return num_item;

}
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 

#if(MMI_MAX_SIM_NUM >= 3)

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_slim_sim_sel_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_ui_callback_slim_sim_sel_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_sim_sel_result_event_struct *sim_sel_evt = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {

        }
            break;

            /* SIM selector event */
        case EVT_ID_CUI_SIM_SEL_RESULT:
        {

            sim_sel_evt = (cui_sim_sel_result_event_struct*) evt;
            cui_sim_sel_close(mmi_umms_app_dtmgr_get_sim_sel_cui_id());
            if (sim_sel_evt->result == CUI_SIM_SEL_OK)
            {
                srv_mms_set_selected_sim_id(sim_sel_evt->sim_id);
                if (sim_sel_evt->sim_id)
                {
                    mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
                }
                else
                {
                    mmi_popup_display(
                        (WCHAR*) ((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)),
                        MMI_EVENT_FAILURE,
                        NULL);
                }
            }
            if (sim_sel_evt->result == CUI_SIM_SEL_ABORT)
            {

                cui_sim_sel_close(mmi_umms_app_dtmgr_get_sim_sel_cui_id());

            }

            /* cui_sim_sel_close(g_uc_p->main.uc_sim_cui_id); */
        }
            break;

            /* GRP related events */
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_sim_sel_post_action_decide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_ui_callback_sim_sel_post_action_decide(mmi_event_struct *evt)
{
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    switch (menu_evt->highlighted_menu_id)
    {
        #if(MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_UMMS_FROM_SIM1:
        {
            mmi_umms_app_ui_plug_in_download_with_sim_id(MMI_SIM1);
        }
            break;
        case MENU_ID_UMMS_FROM_SIM2:
        {
            mmi_umms_app_ui_plug_in_download_with_sim_id(MMI_SIM2);
        }
            break;

        
        case MENU_ID_UMMS_FROM_SIM3:
        {
            mmi_umms_app_ui_plug_in_download_with_sim_id(MMI_SIM3);
        }
            break;
        #endif
        #if(MMI_MAX_SIM_NUM >= 4) 
        case MENU_ID_UMMS_FROM_SIM4:
        {
            mmi_umms_app_ui_plug_in_download_with_sim_id(MMI_SIM4);
        }
            break;
        #endif
        default:
            break;
       
    }

    cui_menu_close(mmi_umms_app_dtmgr_get_sim_sel_cui_id());
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sim_sel_result_event_struct *sim_sel_result = (cui_sim_sel_result_event_struct*) evt;
    mmi_umms_action_type_struct *data = (mmi_umms_action_type_struct*) sim_sel_result->parent_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_SIM_SEL_RESULT:
            if (sim_sel_result->result == CUI_SIM_SEL_OK)
            {
                cui_sim_sel_close(mmi_umms_app_dtmgr_get_sim_sel_cui_id());
                if (srv_mms_is_sim_valid(sim_sel_result->sim_id))
                {
                    srv_mms_set_selected_sim_id(sim_sel_result->sim_id);
                    switch (data->msg_action)
                    {
                        case UMMS_ACTION_RESEND:
                            /* Send */
                    #ifdef __MMI_FTE_SUPPORT__
                            mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list();
                    #else 
                            mmi_umms_app_plug_in_pre_entry_send_msg();
                    #endif 
                            break;
                        case UMMS_ACTION_DOWNLOAD:
                            /* Download */
                            mmi_umms_app_ui_plug_in_download_with_sim_id(sim_sel_result->sim_id);
                            break;
                    }
                    srv_mms_mem_mgr_app_adm_free(data);
                }
            }

            if (sim_sel_result->result == CUI_SIM_SEL_ABORT)
            {

                cui_sim_sel_close(mmi_umms_app_dtmgr_get_sim_sel_cui_id());
                if (data)
                {
                    srv_mms_mem_mgr_app_adm_free(data);
                }
            }

    }

    return MMI_RET_OK;
#endif
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 

#endif /* __MMI_MMS_2__ */ 

