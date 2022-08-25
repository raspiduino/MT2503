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
 * MMSAppUIdraw.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
//#include "MainMenuDef.h"
//#include "CommonScreens.h"
#include "MessagesMiscell.h"
//#include "app_str.h"
//#include "App_mine.h"
#include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "MMSAppUICommon.h"
// #include "MMSAppInterfaceGProt.h"
#include "MMSAppInterfaceProt.h"
#include "MMSAppUICallback.h"
#include "MMSAppScrHdlr.h"
#include "MMSMemoryManagerSrv.h"
#ifdef __MMI_FTE_SUPPORT__
#include "wgui_categories_util.h"
#endif 
#include "MenuCuiGprot.h"
#include "inlineCuiGprot.h"
#include "MMSAppUIPlugin.h"
// #include "MMSAppUIdrawEx.h"
#include "MMSAppDataManager.h"
#include "MMSAppScrHdlrEx.h"
#include "MMSAppResourceDB.h"
#include "MMSAppUIdraw.h"
// #include "MessagesResourceData.h"
#include "ProfilesSrvGprot.h"
//#include "UCMGProt.h"
//#include "BootupSrvGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
 #include "DmSrvGprot.h"
#endif 
// #include "SimDetectionGprot.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "NotificationGprot.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "custom_events_notify.h"
#include "gui_data_types.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_MMS_viewer.h"
#include "gui_typedef.h"
#include "wgui_categories_email.h"
#include "AlertScreen.h"
#include "UcmSrvGprot.h"
#include "string.h"
#include "mmi_frm_gestures_gprot.h"

extern void *mmi_umms_app_dtmgr_get_popup_screen_data(void);
extern void *mmi_umms_app_dtmgr_get_infinite_popup_screen_data(void);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
static mmi_menu_id g_umms_curr_menu_id;


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_set_current_opt_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_draw_set_current_opt_menu_id(mmi_menu_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_curr_menu_id = id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_get_current_opt_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_menu_id mmi_umms_app_ui_draw_get_current_opt_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_curr_menu_id;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_cui_static_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_cui_static_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_resourceDB_struct *resource = NULL;
#endif
    cui_menu_type_enum menu_type = CUI_MENU_TYPE_OPTION;
    mmi_id child_menu_gid;
    mmi_id menu_id = 0, title_icon_id = 0, title_str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Below code is replacement of ResourceDB removal */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    menu_id = mmi_umms_app_ui_draw_get_current_opt_menu_id();
    switch (scr_id)
    {
        case SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS:
        {
            menu_id = MENU_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_ID_UMMS_MMS_SETTINGS;
        }
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case SCR_ID_UMMS_MESSAGE_SETTINGS:
        {
            menu_id = MENU_ID_UMMS_MMS_SETTINGS;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_ID_UMMS_MESSAGE_SETTINGS_COMMON_SETTINGS;
        }
            break;
#endif
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
        case SCR_ID_UMMS_MMS_MESSAGE_STATUS:
        {
            menu_id = MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_GLOBAL_MEMORY_STATUS;
        }
            break;
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    #if(MMI_MAX_SIM_NUM >= 2)
        case SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION:
        {
            menu_id = MENU_ID_UMMS_MMS_SETTING_SIM_SELECTION;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_GLOBAL_DATA_ACCOUNT;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
#ifdef __MMI_MMS_SIGNATURE__
        case SCR_ID_UMMS_COMPOSE_IMAGE_OPTION:
        {
            menu_id = MENU_ID_UMMS_SIGNATURE_OPTION;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_ID_UMMS_SETTINGS_SIGNATURE;
        }
            break;
#endif
        case SCR_ID_UMMS_MMS_OPTION_SLIM:
        {
            menu_id = MENU_ID_UMMS_OPTIONS_SLIM;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_GLOBAL_OPTIONS;
        }
            break;
        case SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION:
        {
            menu_id = MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_GLOBAL_OPTIONS;
        }
            break;
		case SCR_ID_UMMS_SIM_OPTION:
		{
            menu_id = MENU_ID_UMMS_OPTIONS_RESEND;
			title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID); ;
			title_str_id = STR_GLOBAL_SEND;
		}
		break ;
			/*case SCR_ID_UMMS_SLIM_REPLY_OPTION:
        {
            menu_id = MENU_ID_UMMS_SLIM_OPTIONS_REPLY;
            title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            title_str_id = STR_GLOBAL_OPTIONS;
        }
            break;*/
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    if (scrDB == NULL)
    {
        MMI_ASSERT(0);
    }
    resource = scrDB->RObj;
    ASSERT(resource);
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    menu_id = resource->menu_item_id;
    title_icon_id = GetRootTitleIcon(resource->title_icon_id);
    title_str_id = resource->title_str_id;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    if (scr_id == SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS ||
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        scr_id == SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED ||
#endif 
        scr_id == SCR_ID_UMMS_MESSAGE_SETTINGS ||
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
        scr_id == SCR_ID_UMMS_MMS_MESSAGE_STATUS ||
#endif 
#if(MMI_MAX_SIM_NUM >= 2)
        scr_id == SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION ||
#endif 
        scr_id == SCR_ID_UMMS_COMPOSE_IMAGE_OPTION
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        || scr_id == SCR_ID_UMMS_MMS_OPTION_SLIM
#endif 
        )
    {
        menu_type = CUI_MENU_TYPE_APPMAIN;
    }
    child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        menu_type,  /* Option menu */
                        menu_id,    /* parent menu */
                        MMI_TRUE,
                        NULL);
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (scr_id != SCR_ID_UMMS_MMS_OPTION_SLIM)
#endif 
        cui_menu_set_default_title_image_by_id(child_menu_gid, title_icon_id);
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    else

        cui_menu_set_default_title_string_by_id(child_menu_gid, title_str_id);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (scr_id == SCR_ID_UMMS_COMPOSE_IMAGE_OPTION || scr_id == SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS)
    {
        mmi_umms_dtmgr_set_compose_image_gid(child_menu_gid);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    /* Run CUI */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (scr_id == SCR_ID_UMMS_MMS_OPTION_SLIM)
    {
        mmi_umms_app_dtmgr_set_menu_cui_id(child_menu_gid);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    cui_menu_run(child_menu_gid);   /* start to run this cui */

    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_infinite_time_list_draw_func_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scene_id        [IN]        
 *  arg             [?]         
 *  scr_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ui_infinite_time_list_draw_func_hdlr(mmi_scenario_id scene_id, void *arg) /* ShowCategory65Screen */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(*(U16*) arg);
    mmi_umms_app_ui_draw_infinite_popup_screen_struct *pop_up_scr =
        (mmi_umms_app_ui_draw_infinite_popup_screen_struct*) mmi_umms_app_dtmgr_get_infinite_popup_screen_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        srv_mms_mem_mgr_app_adm_free(arg);
        return MMI_FALSE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    mmi_frm_start_scenario(MMI_SCENARIO_ID_MMS_INFO);
    if (scrDB == NULL)
    {
        MMI_ASSERT(0);
    }
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_FALSE;
    }

    /* GetCurrEndKeyDownHandler(); */

    ShowCategory65Screen((PU8) pop_up_scr->string_id, pop_up_scr->image_id, NULL);

    /* SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
       SetGroupKeyHandler(mmi_frm_scrn_close_active_id, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
       ClearKeyHandler(KEY_END, KEY_EVENT_UP);
       SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_DOWN);
       if (srv_bootup_is_completed())
       {
       SetKeyHandler(DisplayIdleScreen, KEY_END, KEY_EVENT_DOWN);
       } */
    mmi_frm_scrn_set_key_proc(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id, mmi_umms_proc_func);
    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);
    }
    /* mmi_umms_set_key_handler_according_to_scrn_id(scrDB->scrn_id, MMI_UMMS_APRNC_TYPE_INFINITE_POPUP_LIST); */
    srv_mms_mem_mgr_app_adm_free(arg);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_infinite_time_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_infinite_time_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *type_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_NEW_MSG_POPUP, type, pp_flag, alertType); */
    type_p = srv_mms_mem_mgr_app_adm_alloc(sizeof(U16));
    *type_p = scr_id;
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_DEFAULT,
        mmi_umms_app_ui_infinite_time_list_draw_func_hdlr,
        (void*)type_p);
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_progress_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_progress_screen_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_resourceDB_struct *resource = scrDB->RObj;
    mmi_proc_func del_proc = scrDB->delete_screen_handler;
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_proc_func del_proc = mmi_umms_app_sh_progress_delete_screen;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_umms_app_ui_draw_progress_screen_struct *prgs =
        (mmi_umms_app_ui_draw_progress_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
    mmi_umms_app_ui_draw_progress_scrn_struct *curr_data =
        (mmi_umms_app_ui_draw_progress_scrn_struct*) mmi_umms_app_ui_plug_in_progress_scrn_data();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scr_id,
            mmi_umms_app_sh_progress_screen_exit_func,
            mmi_umms_app_if_show_progress_screen,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    if (del_proc != NULL)
    {
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), scr_id, (mmi_proc_func) del_proc);
    }
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory66Screen(
        curr_data->title_str_id,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(curr_data->display_id),
        IMG_GLOBAL_PROGRESS,
        NULL);

    GetCurrEndKeyDownHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    /* mmi_umms_set_key_handler_according_to_scrn_id(scrDB->scrn_id, MMI_UMMS_PROGRESS_SCREEN_LIST); */
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_display_confirm_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_confirm_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_display_confrim_screen_struct *confirm_data;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    U8 *guiBuffer = NULL;
    U16 img_id = 0;
    MMI_ID grp_id;
    srv_prof_tone_enum tone_id;
    void (*entry_func) (void);
    mmi_proc_func delete_screen_handler = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    confirm_data = (mmi_umms_app_ui_draw_display_confrim_screen_struct*) mmi_umms_app_ui_plug_in_get_confirm_func();
    if (!scrDB || scrDB->EntryFunction == NULL)
    {
        entry_func = mmi_umms_app_if_show_display_confirm_screen;
    }
    else
    {
        entry_func = scrDB->EntryFunction;
        delete_screen_handler = scrDB->delete_screen_handler;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scr_id);
    if (confirm_data->need_history)
    {
        if (!mmi_frm_scrn_enter(
                mmi_umms_dtmgr_get_group_id(),
                scr_id,
                confirm_data->exit_screen,
                entry_func,
                MMI_FRM_FULL_SCRN))
        {
            return MMI_UMMS_FALSE;
        }

    }
    else
    {
        grp_id = mmi_frm_group_get_active_id();
        if (!mmi_frm_scrn_enter(
                (grp_id == mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id())? mmi_frm_group_get_active_id() : mmi_umms_dtmgr_get_group_id(),
                scr_id,
                confirm_data->exit_screen,
                mmi_umms_app_dummy_entry_function,
                MMI_FRM_FG_ONLY_SCRN))
        {
            return MMI_UMMS_FALSE;
        }

    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scr_id, (void*)scrDB);

    if (confirm_data->del_scr_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), scr_id, (mmi_proc_func) delete_screen_handler);
    }
    img_id = mmi_get_event_based_image((mmi_event_notify_enum)confirm_data->mmi_event);
    tone_id = mmi_get_event_based_sound((mmi_event_notify_enum)confirm_data->mmi_event);
    ShowCategory165Screen(
        confirm_data->lsk_str_id,
        confirm_data->lsk_icon_id,
        confirm_data->rsk_str_id,
        confirm_data->rsk_icon_id,
        (UI_string_type) confirm_data->message,
        img_id,
        guiBuffer);
    if (!guiBuffer)
    {
        // if (!mmi_profiles_check_tone_playing(tone_id))   /*As due profile app/srv*/
        {
            srv_prof_play_tone((srv_prof_tone_enum) tone_id, NULL);
        }
    }
    /*
     */

    SetLeftSoftkeyFunction(confirm_data->lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(confirm_data->rsk_handler, KEY_EVENT_UP);
    
    /* changes done for implementing new CSK handling design */
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(confirm_data->lsk_handler, KEY_EVENT_UP);
    

    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_dummy_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_draw_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DUMMY_SCR);
    mmi_frm_display_dummy_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_inline_cui_selection_screen_struct *inline_selection_scr = NULL;
    U16 image_list[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_selection_scr =
        (mmi_umms_app_ui_draw_inline_cui_selection_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
    if (scr_id != SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS && scr_id != SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS)
    {
        mmi_frm_group_create_ex(
            mmi_umms_dtmgr_get_group_id(),
            GRP_ID_UMMS_LIST_INLINE_CUI,
            mmi_umms_inline_proc_func,
            (void*)inline_selection_scr,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        if (inline_selection_scr == NULL)
        {
            MMI_ASSERT(0);
        }
        mmi_umms_dtmgr_set_inline_gid(cui_inline_create
                                      (GRP_ID_UMMS_LIST_INLINE_CUI,
                                       (const cui_inline_struct*)&(inline_selection_scr->inline_initial_data)));
        cui_inline_set_title_icon(mmi_umms_dtmgr_get_inline_gid(), GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
        if (inline_selection_scr->image_list_icons != NULL)
        {
            inline_selection_scr->image_list_icons(image_list);
            cui_inline_set_icon_list(mmi_umms_dtmgr_get_inline_gid(), image_list);
        }
        inline_selection_scr->set_item_list(mmi_umms_dtmgr_get_inline_gid());
        cui_inline_run(mmi_umms_dtmgr_get_inline_gid());
    }
    else
    {
        mmi_frm_group_create_ex(
            GRP_ID_UMMS_LIST_INLINE_CUI,
            GRP_ID_UMMS_LIST_INLINE_CUI_EXT,
            mmi_umms_inline_proc_func,
            (void*)inline_selection_scr,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        if (inline_selection_scr == NULL)
        {
            MMI_ASSERT(0);
        }
        mmi_umms_dtmgr_set_inline_gid_ext(cui_inline_create
                                          (GRP_ID_UMMS_LIST_INLINE_CUI_EXT,
                                           (const cui_inline_struct*)&(inline_selection_scr->inline_initial_data)));
        cui_inline_set_title_icon(mmi_umms_dtmgr_get_inline_gid_ext(), GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
        if (inline_selection_scr->image_list_icons != NULL)
        {
            inline_selection_scr->image_list_icons(image_list);
            cui_inline_set_icon_list(mmi_umms_dtmgr_get_inline_gid_ext(), image_list);
        }
        inline_selection_scr->set_item_list(mmi_umms_dtmgr_get_inline_gid_ext());
        cui_inline_run(mmi_umms_dtmgr_get_inline_gid_ext());

    }
    return MMI_UMMS_TRUE;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_property_status_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_property_status_screen_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 submenudatalength = 0;
    U16 lsk_str = 0, lsk_icon = 0;
    U8 *string_buffer = NULL;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    mmi_umms_app_resourceDB_struct *resource = scrDB->RObj;
    mmi_umms_app_ui_draw_property_screen_struct *property_screen = NULL;

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    U16 index_num = 0, total_num = 0;
    void (*rnk_func) (void) = NULL;
    void (*lnk_func) (void) = NULL;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    property_screen = (mmi_umms_app_ui_draw_property_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
    ASSERT(property_screen);
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scrDB->scrn_id, (void*)scrDB);

    if (property_screen->get_string_buffer != NULL)
    {
        string_buffer = property_screen->get_string_buffer(scrDB->scrn_id);
    }
    submenudatalength = mmi_ucs2strlen((S8*) string_buffer);
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (property_screen->lsk_delete == MMI_TRUE)
    {
        lsk_str = STR_GLOBAL_DELETE;
    }
    else
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    {
        lsk_str = resource->lsk_str_id;
    }

#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (property_screen->lnk_func != NULL && mmi_umms_app_dtmgr_get_refresh_flag() == MMI_FALSE)
    {
        mmi_umms_app_ui_callback_get_index_data(&index_num, &total_num);
        if (index_num != 0 && total_num != 0)
        {
            rnk_func = property_screen->rnk_func;
            lnk_func = property_screen->lnk_func;
            memset(property_screen->middle_str, 0, MMI_MMS_MAX_ITER_VIEWER_MIDDLE_STR_LEN);
            kal_wsprintf((WCHAR*) property_screen->middle_str, "%d/%d", index_num, total_num);
            if (index_num == 1)
            {
                lnk_func = NULL;
            }
            if (index_num == total_num)
            {
                rnk_func = NULL;
            }
            wgui_cat_text_viewer_setup_slide_buttons(
                NULL,
                NULL,   /* Need artist create */
                NULL,
                lnk_func,
                NULL,
                NULL,
                NULL,
                rnk_func,
                property_screen->middle_str,
                0);
        }
    #if (defined( __MMI_FTE_SUPPORT__) && defined(__MMI_ICON_BAR_SUPPORT__))
        wgui_icon_bar_setup
            (property_screen->fte_data.item_count,
             property_screen->fte_data.content_icon,
             property_screen->fte_data.disabled_content_icon,
             property_screen->fte_data.string, property_screen->fte_data.callback);
    #endif /* __MMI_FTE_SUPPORT__ */ 

    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    ShowCategory74Screen(
        resource->title_str_id,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        lsk_str,
        lsk_icon,
        resource->rsk_str_id,
        resource->rsk_icon_id,
        (U8*) string_buffer,
        (S32) submenudatalength,
        guiBuffer);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);

    }

    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        /* SetKeyHandler(scrDB->lsk_func, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    }
    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
        /* SetKeyHandler(scrDB->rsk_func, KEY_LEFT_ARROW, KEY_EVENT_DOWN); */
    }
    if (property_screen->csk_func)
    {
        ChangeCenterSoftkey(0, property_screen->csk_icon);
        SetCenterSoftkeyFunction(property_screen->csk_func, KEY_EVENT_UP);
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (lnk_func)
    {
        SetKeyHandler(property_screen->lnk_func, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(wgui_cat_text_viewer_show_left_slide_button_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_listen_event(
            MMI_FRM_GESTURE_RIGHT,
            mmi_umms_app_ui_callback_display_previous_mms_through_swipe);
    #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */ 
    }
    if (rnk_func)
    {
        SetKeyHandler(property_screen->rnk_func, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(wgui_cat_text_viewer_show_right_slide_button_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_umms_app_ui_callback_display_next_mms_through_swipe);
    #endif 
    }
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    return MMI_UMMS_TRUE;
}
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_property_status_screen_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_property_status_screen_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 submenudatalength = 0;
    U16 lsk_str = 0;
    U8 *string_buffer = NULL;
    mmi_umms_app_screenDB_struct *scrDB = NULL;
    mmi_umms_app_resourceDB_struct *resource = NULL;
    mmi_umms_app_ui_draw_property_screen_struct *property_screen = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    property_screen = (mmi_umms_app_ui_draw_property_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
    ASSERT(property_screen);
    scrDB = property_screen->scrDB;
    resource = scrDB->RObj;
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scrDB->scrn_id, (void*)scrDB);

    if (property_screen->get_string_buffer != NULL)
    {
        string_buffer = property_screen->get_string_buffer(scrDB->scrn_id);
    }
    submenudatalength = mmi_ucs2strlen((S8*) string_buffer);
    lsk_str = resource->lsk_str_id;
    ShowCategory74Screen(
        resource->title_str_id,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        lsk_str,
        0,
        resource->rsk_str_id,
        resource->rsk_icon_id,
        (U8*) string_buffer,
        (S32) submenudatalength,
        guiBuffer);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);

    }
    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
        /* SetKeyHandler(scrDB->lsk_func, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    }
    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
        /* SetKeyHandler(scrDB->rsk_func, KEY_LEFT_ARROW, KEY_EVENT_DOWN); */
    }
    if (property_screen->csk_func)
    {
        ChangeCenterSoftkey(0, property_screen->csk_icon);
        SetCenterSoftkeyFunction(property_screen->csk_func, KEY_EVENT_UP);
    }
    return MMI_UMMS_TRUE;
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ /* __MMI_MMS_SLIM_IT */


#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_ui_radio_selection_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_ui_chkbox_selection_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U16 num_item = 0;
    U16 str_item_list[MAX_SUB_MENUS];
    mmi_menu_id hilighted_item = 0;

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    mmi_umms_app_resourceDB_struct *resource = NULL;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_id child_menu_gid;
    mmi_id menu_item_id, title_icon_id, title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (scrDB == NULL)
    {
        MMI_ASSERT(0);
    }
    resource = scrDB->RObj;
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    ASSERT(resource);
    menu_item_id = resource->menu_item_id;
    title_str_id = resource->title_str_id;
    title_icon_id = resource->title_icon_id;
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    menu_item_id = MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE;
    title_icon_id = MAIN_MENU_MESSAGES_MENUID;
    title_str_id = STR_ID_UMMS_MMS_PREFER_STORAGE;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

    child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,   /* Option menu */
                        menu_item_id,           /* parent menu */
                        MMI_TRUE,
                        NULL);

 
    cui_menu_set_default_title(
        child_menu_gid,
        (UI_string_type) GetString(title_str_id),
        (UI_image_type) GetImage(GetRootTitleIcon(title_icon_id)));
    /* cui_menu_enable_cascading_option_menu(child_menu_gid); */

    /* Run CUI */
    cui_menu_run(child_menu_gid);   /* start to run this cui */
    return MMI_UMMS_TRUE;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_ui_radio_selection_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_ui_radio_selection_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id hilighted_item = 0;

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    mmi_umms_app_resourceDB_struct *resource = NULL;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    mmi_id child_menu_gid;
    mmi_id menu_item_id, title_icon_id, title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (scrDB == NULL)
    {
        MMI_ASSERT(0);
    }
    resource = scrDB->RObj;
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }

    ASSERT(resource);
    menu_item_id = resource->menu_item_id;
    title_str_id = resource->title_str_id;
    title_icon_id = resource->title_icon_id;
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    menu_item_id = MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE;
    title_icon_id = MAIN_MENU_MESSAGES_MENUID;
    title_str_id = STR_ID_UMMS_MMS_PREFER_STORAGE;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

    child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,   /* Option menu */
                        menu_item_id,           /* parent menu */
                        MMI_TRUE,
                        NULL);

#if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    hilighted_item = (U8) mmi_umms_app_ui_plug_in_get_prefer_storage_hilighted_index();
    hilighted_item =
        hilighted_item ? MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_CARD : MENU_ID_UMMS_MMS_SETTINGS_PREFER_STORAGE_PHONE;
    cui_menu_set_radio_list_item(child_menu_gid, hilighted_item);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    cui_menu_set_default_title(
        child_menu_gid,
        (UI_string_type) GetString(title_str_id),
        (UI_image_type) GetImage(GetRootTitleIcon(title_icon_id)));
    /* cui_menu_enable_cascading_option_menu(child_menu_gid); */

    /* Run CUI */
    cui_menu_run(child_menu_gid);   /* start to run this cui */
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_msg_entry_new_msg_popup_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scene_id        [IN]        
 *  arg             [?]         
 *  scr_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_msg_entry_new_msg_popup_entry_hdlr(mmi_scenario_id scene_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    U16 image_id = 0;
    U16 scr_id = *(U16*) arg;
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    mmi_umms_app_resourceDB_struct *resource = NULL;
    mmi_umms_app_ui_draw_infinite_time_screen_struct *infinite_scr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        srv_mms_mem_mgr_app_adm_free(arg);
        return MMI_FALSE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        srv_mms_mem_mgr_app_adm_free(arg);
        return MMI_FALSE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 

    mmi_frm_start_scenario(MMI_SCENARIO_ID_NEW_MMS);
    infinite_scr = (mmi_umms_app_ui_draw_infinite_time_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);

    if (scrDB == NULL || infinite_scr == NULL)
    {
        MMI_ASSERT(0);
    }
    resource = scrDB->RObj;
    ASSERT(resource);
    if (scrDB->EntryFunction == NULL)
    {
        MMI_ASSERT(0);
    }
    else
    {
        if (!mmi_frm_scrn_enter(
                mmi_umms_dtmgr_get_group_id(),
                scrDB->scrn_id,
                scrDB->exit_screen,
                scrDB->EntryFunction,
                MMI_FRM_FULL_SCRN))
        {
            return MMI_FALSE;
        }
    }

    if (scrDB->parent_menu_id != 0)
    {
        SetParentHandler(scrDB->parent_menu_id);
    }
    if (scrDB->hilite_handler != NULL)
    {
        RegisterHighlightHandler(scrDB->hilite_handler);
    }

    if (infinite_scr->image_id != NULL)
    {
        /* image_id = infinite_scr->image_id(scr_id);[Amit-correct] */
    }
    if (infinite_scr->str_id != NULL)
    {
        /* str_id = infinite_scr->str_id(scr_id);[Amit-correct] */
    }

    ShowCategory65Screen((PU8) GetString(str_id), image_id, NULL);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);
    }
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_frm_scrn_close_active_id, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_DOWN);

    srv_mms_mem_mgr_app_adm_free(arg);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_ui_show_new_message_popup_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_ui_show_new_message_popup_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *type_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_NEW_MSG_POPUP, type, pp_flag, alertType); */
    type_p = (U16*) srv_mms_mem_mgr_app_adm_alloc(sizeof(U16));
    *type_p = scr_id;
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_NEW_MMS,
        MMI_EVENT_DEFAULT,
        mmi_umms_msg_entry_new_msg_popup_entry_hdlr,
        (void*)type_p);
    return MMI_UMMS_TRUE;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_viewer_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    if (mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id, NULL);
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scrDB->scrn_id, (void*)scrDB);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);
    }

    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_PLAY)
    {
        /* As category keys will be overridden in case group keys are set after showcategory so doing it before show category */
        /* GetCurrEndKeyDownHandler();
           SetGroupKeyHandler(
           mmi_umms_app_ui_callback_viewer_stop_callback,
           (PU16) PresentAllKeys,
           (U8) TOTAL_KEYS,
           KEY_EVENT_DOWN);
           SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_DOWN); */
        mmi_frm_scrn_set_key_proc(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id, mmi_umms_proc_func);
    }
#if (defined( __MMI_FTE_SUPPORT__) && defined(__MMI_ICON_BAR_SUPPORT__))
    wgui_icon_bar_setup
        (viewer_scr->fte_data.item_count,
         viewer_scr->fte_data.content_icon,
         viewer_scr->fte_data.disabled_content_icon, viewer_scr->fte_data.string, viewer_scr->fte_data.callback);
#endif /* __MMI_FTE_SUPPORT__ */ 
    ShowCategory630Screen(
        MMI_FALSE,
        viewer_scr->mode,
        /* scrDB->lsk_func */ viewer_scr->lsk_func,
        viewer_scr->lsk_str_id,
        scrDB->rsk_func,
        (kal_bool)viewer_scr->full_scrn,
        guiBuffer,
        1);

    return MMI_UMMS_TRUE;
}

#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_viewer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_viewer_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
    WGUI_MV_USED_BY_ENUM used_mode;
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(viewer_scr);
    if (mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), scr_id, NULL);
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scr_id);
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scr_id,
            mmi_umms_app_sh_viewer_exit_func,
            mmi_umms_app_if_show_viewer_screen,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scr_id, (void*)&scr_id);
    mmi_frm_scrn_set_leave_proc(
        mmi_umms_dtmgr_get_group_id(),
        scr_id,
        (mmi_proc_func) mmi_umms_app_sh_viewer_delete_scr_handler);
    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_PLAY)
    {
        mmi_frm_scrn_set_key_proc(mmi_umms_dtmgr_get_group_id(), scr_id, mmi_umms_proc_func);
    }
    if (data->open_mode == MMA_MODE_VIEW)
    {
        used_mode = WGUI_MV_USED_BY_VIEWER;
    }
    else
    {
        used_mode = WGUI_MV_USED_BY_UC;
    }
	#if (defined( __MMI_FTE_SUPPORT__) && defined(__MMI_ICON_BAR_SUPPORT__))
    wgui_icon_bar_setup
        (viewer_scr->fte_data.item_count,
         viewer_scr->fte_data.content_icon,
         viewer_scr->fte_data.disabled_content_icon, viewer_scr->fte_data.string, viewer_scr->fte_data.callback);
#endif /* __MMI_FTE_SUPPORT__ */ 
    ShowCategory630Screen(
        MMI_FALSE,
        viewer_scr->mode,
        viewer_scr->lsk_func,
        viewer_scr->lsk_str_id,
        mmi_umms_app_sh_viewer_rsk_handler,
        (kal_bool)viewer_scr->full_scrn,
        guiBuffer,
        used_mode);

    if (viewer_scr->mode == WGUI_MV_DISPLAY_MODE_SHOW)
    {
        ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);

        if (data->msg_info && data->msg_info->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            SetKeyHandler(mmi_umms_app_ui_plug_in_call_sender_viewer, KEY_SEND, KEY_EVENT_DOWN);
        }
    }
    
    return MMI_UMMS_TRUE;
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_viewer_toggle_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  scr_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_viewer_toggle_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(SCR_ID_UMMS_MMS_VIEWER);
    mmi_umms_app_ui_draw_viewer_screen_struct *viewer_scr =
        (mmi_umms_app_ui_draw_viewer_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_MMS_VIEWER);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER, (mmi_proc_func) NULL);
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_VIEWER);
    if (viewer_scr->full_scrn == MMI_UMMS_TRUE)
    {
        viewer_scr->full_scrn = FALSE;
    }
    else
    {
        viewer_scr->full_scrn = TRUE;
    }
    viewer_scr->mode = WGUI_MV_DISPLAY_MODE_PLAY;
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scrDB->scrn_id, (void*)scrDB);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);
    }
    ShowCategory630Screen(
        MMI_TRUE,
        viewer_scr->mode,
        /* scrDB->lsk_func */ viewer_scr->lsk_func,
        viewer_scr->lsk_str_id,
        scrDB->rsk_func,
        (kal_bool)viewer_scr->full_scrn,
        guiBuffer,
        WGUI_MV_USED_BY_VIEWER);

    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_dyncmic_list_draw_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_dyncmic_list_draw_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 list_not_ready = 0;
    U16 list_icon = 0;
    U16 title_icon = 0;
    list_menu_category_history *list_gui_buffer = NULL;
    mmi_umms_app_ui_draw_dynamic_screen_struct *dynamic_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(scr_id);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_screenDB_struct *scrDB = mmi_umms_app_resource_get_screenDB(scr_id);
#else 
    mmi_umms_app_screenDB_struct *scrDB = dynamic_scr->scrDB;
#endif 
    mmi_umms_app_resourceDB_struct *resource = scrDB->RObj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dynamic_scr);
    guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_umms_dtmgr_get_group_id(), scrDB->scrn_id);
    if (guiBuffer != NULL)
    {
        list_gui_buffer = (list_menu_category_history*) guiBuffer;
        list_gui_buffer->highlighted_item = dynamic_scr->hilighted_item;
    }
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            scrDB->exit_screen,
            scrDB->EntryFunction,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_UMMS_FALSE;
    }
    mmi_frm_scrn_set_user_data(mmi_umms_dtmgr_get_group_id(), (MMI_ID) scrDB->scrn_id, (void*)scrDB);

    if (scrDB->delete_screen_handler != NULL)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_umms_dtmgr_get_group_id(),
            scrDB->scrn_id,
            (mmi_proc_func) scrDB->delete_screen_handler);
    }

    RegisterHighlightHandler(scrDB->hilite_handler);
    if (dynamic_scr->change_title)
    {
        title_icon = dynamic_scr->change_title();
    }
    else
    {
        title_icon = GetRootTitleIcon(resource->title_icon_id);
    }
    //list_icon = mmi_umms_get_dynamic_icon_list(scrDB->scrn_id);
    //list_icon = (U16) g_msg_info_tpl_struct[dynamic_scr->hilighted_item].icon_id;
    /* ShowCategory184Screen(
       resource->title_str_id,
       GetRootTitleIcon(resource->menu_item_id),
       resource->lsk_str_id,
       resource->lsk_icon_id,
       resource->rsk_str_id,
       resource->rsk_icon_id,
       dynamic_scr->number_of_item,
       dynamic_scr->get_item_cb,
       NULL,
       dynamic_scr->hilighted_item,
       guiBuffer); */
    ShowCategory262Screen(
        (U8*) GetString(resource->title_str_id),
        title_icon,
        resource->lsk_str_id,
        resource->lsk_icon_id,
        resource->rsk_str_id,
        resource->rsk_icon_id,
        (S32) dynamic_scr->number_of_item,
        (GetAsyncItemFuncPtr) dynamic_scr->get_item_cb,
        NULL,
        (S32) dynamic_scr->hilighted_item,
        list_icon,
        guiBuffer,
        &list_not_ready);

    if (dynamic_scr->hndl_list_not_ready != NULL)
    {
        dynamic_scr->hndl_list_not_ready(list_not_ready);
    }
    SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);

    /* mmi_umms_set_key_handler_according_to_scrn_id(scr_id,MMI_UMMS_APRNC_TYPE_DYNAMIC_LIST); */
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_display_popup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_popup_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_display_popup_screen_struct *popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    popup_data = (mmi_umms_app_ui_draw_display_popup_screen_struct*) mmi_umms_app_dtmgr_get_popup_screen_data();

    mmi_popup_display_simple(
        (WCHAR*) ((UI_string_type) popup_data->string_id),
        (mmi_event_notify_enum) popup_data->event_type,
        GRP_ID_ROOT,
        NULL);

    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_display_progress_screen_with_no_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_progress_screen_with_no_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            mmi_umms_dtmgr_get_group_id(),
            SCR_ID_UMMS_PROGRESS_WITHOUT_HISTORY,
            NULL,
            mmi_umms_app_dummy_entry_function,
            MMI_FRM_FG_ONLY_SCRN))
    {
        return MMI_UMMS_FALSE;
    }

    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);    /* delete any previous progressing screen */
    image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory66Screen(
        STR_GLOBAL_SAVING,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        image_id,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        SetKeyHandler(mmi_umms_app_ui_plug_in_hangup_calls, KEY_END, KEY_EVENT_DOWN);
    }

	return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_draw_display_callback_popup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_callback_popup_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_display_callback_popup_screen_struct *callback_popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    callback_popup_data =
        (mmi_umms_app_ui_draw_display_callback_popup_screen_struct*)
        mmi_umms_app_dtmgr_get_callback_popup_screen_data();

    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
        arg.parent_id = mmi_umms_dtmgr_get_group_id();
        arg.callback = (mmi_proc_func) mmi_umms_popupcallback_ext_proc_fun;
        arg.user_tag = (void*)(NULL);   /* not for parent proc */
        mmi_popup_display(
            (WCHAR*) ((UI_string_type) callback_popup_data->string),
            (mmi_event_notify_enum) callback_popup_data->event_type,
            &arg);
    }

    return MMI_UMMS_TRUE;
}

#endif /* __MMI_MMS_2__ */ 

