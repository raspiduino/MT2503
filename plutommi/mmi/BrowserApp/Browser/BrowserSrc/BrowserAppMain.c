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
 * BrowserUIPlugIn.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPMAIN_C
#define MMI_BROWSERAPPMAIN_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppMain.h"
#include "BrowserAppScrDB.h"
#include "BrowserAppUICallback.h"
#include "BrowserAppCntrlDB.h"
#include "BrowserAppDMgr.h"
#include "BrowserAppInterface.h"
#include "BrowserAppSrvHdlr.h"
#include "BrowserAppScrHdlr.h"
#include "PhoneBookGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "EmailAppGprot.h"      /* for the email API mmi_email_is_email_can_forward */
#ifdef __MMI_UCM__
#include "UCMGProt.h"           /* for UCM enums and macros */
#endif 
#include "Menucuigprot.h"


#include "kal_general_types.h"
#include "BrowserAppTypes.h"
#include "MMIDataType.h"
#include "wap_adp.h"
#include "BrowserSrvProts.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "gui_typedef.h"
#include "mmi_rp_app_browser_def.h"
#include "BrowserSrvConfig.h"
#include "kal_public_api.h"
#include "BrowserSrvInterface.h"
#include "ImeGprot.h"
#include "common_nvram_editor_data_item.h"
#include "BrowserSrvBookmarks.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "custom_events_notify.h"
#include "GlobalMenuItems.h"
#include "BrowserResDef.h"
#include "InlineCuiGprot.h"
#include "DebugInitDef_Int.h"
#include "DLAgentSrvDef.h"
#include "CustDataRes.h"
#include "BrowserAppUIDraw.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "string.h"
#include "Conversions.h"
#include "wgui_categories.h"
#include "gui_switch.h"
#include "wgui.h"
#include "stack_msgs.h"
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvGprot.h"
#include "wps_struct.h"
#include "CustMenuRes.h"
//#include "SimDetectionGprot.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "wgui_categories_util.h"
#include "BrowserSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "wgui_title.h"
#include "DtcntSrvGprot.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "stdio.h"
#include "mmi_rp_srv_browser_def.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_data_types.h"
#include "mms_api.h"
#include "mmi_res_range_def.h"
#include "BrowserAppUIPlugin.h"
#include "ModeSwitchSrvGprot.h"
#include "BTMMIScrGprots.h"
#include "BrowserSrvMsgHdlr.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "BrowserSrvMain.h"
#include "CbmSrvGprot.h"

#ifdef __MMI_OP12_BRW_SEARCH_MENU__
extern kal_uint8 const WAP_CUSTOM_CFG_SEARCH_WEB_URL[];
#endif 
#ifdef __MMI_CBM_CONNECTION_MANAGER__
#include "ConnectManageGprot.h"
#endif


brw_app_context_struct g_brw_app_cntx;
U8 *g_brw_display_info_str;
U8 g_brw_current_url[(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH];
U8 g_brw_current_title[(SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH];
void *g_brw_app_memory_pool = NULL; /* for storing the memory pointer sent by ASM */

U16 g_brw_busy_scr_title_str_id = 0;
U16 g_brw_busy_scr_msg_str_id = 0;
U16 g_brw_bkm_scr_id;
brw_file_detail_struct g_brw_open_file_cntx;
brw_ext_bkm_context_struct *g_brw_ext_bkm_cntx_p;

#ifdef OBIGO_Q05A
U8 g_brw_auth_dlg_save_option = BRW_APP_AUTH_DLG_SAVE_NONE_INDEX;
S8 *gBrwAuthDlgSaveOptionStringArray[BRW_APP_AUTH_DLG_SAVE_OPTION_TOTAL];
#endif /* OBIGO_Q05A */

#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
brw_bkm_sel_bkm_cntx_struct g_brw_bkm_sel_bkm_cntx;
MMI_BOOL g_brw_bkm_sel_bkm_pool = MMI_FALSE;
#endif
brw_bkm_add_bookmark_enum g_brw_bkm_add_type;
brw_bkm_context_struct g_brw_bkm_cntx;
brw_bkm_browse_path_enum g_brw_bkm_browse_path_event;
#endif /* __MMI_VBOOKMARK__ */
void *g_brw_memory_pool = NULL;


#ifdef OBIGO_Q03C_BROWSER
extern void widget_MMI_delete_symbol_picker_screen_if_present(void);
#endif /* OBIGO_Q03C_BROWSER */

U8 g_brw_auth_username[(WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH];
U8 g_brw_auth_password[(WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH];

/*************************************SCREEN DATA FUNC******************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_dynamic_list_callback_func
 * DESCRIPTION
 *  This function is to return the callback function to be passed to the 
 * dynamic list screen depending on the screen being displayed.
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the callback function
 *****************************************************************************/
GetItemFuncPtr mmi_brw_app_get_dynamic_list_callback_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BOOKMARKS:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_bookmarks_list_item;

    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case SCR_ID_BRW_SELECT_BOOKMARK:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_insert_bookmarks_list_item;
    #endif

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_folder_list_item;
    #endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_recent_page_list_item;
#endif
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES_HOST:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_recent_page_host_list_item;
#endif

        case SCR_ID_BRW_PAGE_OBJECT_TYPES:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_page_object_types_get_item;

		case SCR_ID_BRW_PAGE_OBJECTS:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_page_objects_get_item;
#endif /* #ifdef OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
        case SCR_ID_BRW_PAGE_ACTIONS:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_page_actions_list_get_item;
#endif
#ifdef WAP_SEC_SUPPORT
        case SCR_ID_BRW_TRUSTED_CERTIFICATES:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_trusted_certificates_list_item;
#endif /* WAP_SEC_SUPPORT */
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGES:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_stored_page_list_item;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE:
            return (GetItemFuncPtr)mmi_brw_app_ui_callback_get_shortcuts_list_item;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
        default:
            ASSERT(0);
    }
}


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_tap_callback_func
 * DESCRIPTION
 *  This function is to return the callback function to be registered on the 
 * tap callback for a screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the tap callback function
 *****************************************************************************/
tap_cllback_func mmi_brw_app_get_tap_callback_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BOOKMARKS:
            return (tap_cllback_func)mmi_brw_app_ui_callback_bookmarks_list_tap;

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH:
            return (tap_cllback_func)mmi_brw_app_ui_callback_browse_path_tap;
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES:
            return (tap_cllback_func)mmi_brw_app_ui_callback_recent_page_list_tap;
#endif
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES_HOST:
            return (tap_cllback_func)mmi_brw_app_ui_callback_recent_page_host_list_tap;
#endif

        case SCR_ID_BRW_PAGE_OBJECTS:
            return (tap_cllback_func)mmi_brw_app_ui_callback_page_obj_list_tap;
#endif /* OBIGO_Q05A */

#ifdef WAP_SEC_SUPPORT
        case SCR_ID_BRW_TRUSTED_CERTIFICATES:
            return (tap_cllback_func)mmi_brw_app_ui_callback_trusted_certificate_tap;
#endif /* WAP_SEC_SUPPORT */
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGES:
            return (tap_cllback_func)mmi_brw_app_ui_callback_stored_page_list_tap;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE:
            return (tap_cllback_func)mmi_brw_app_ui_callback_shortcuts_list_tap;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
        default:
            return NULL;
    }
}


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_show_toolbar_func
 * DESCRIPTION
 *  This function is to return the callback function to be called to show the 
 * FTE toolbar
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the show toolbar function
 *****************************************************************************/
show_toolbar_func_ptr mmi_brw_app_get_show_toolbar_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BOOKMARKS:
            return (show_toolbar_func_ptr)mmi_brw_app_ui_callback_show_bookmarks_toolbar;

        case SCR_ID_BRW_BROWSER_MAIN:
            return (show_toolbar_func_ptr)mmi_brw_app_ui_callback_show_rendered_page_toolbar;

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES:
            return (show_toolbar_func_ptr)mmi_brw_app_ui_callback_show_recent_page_toolbar;
#endif

    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGES:
            return (show_toolbar_func_ptr)mmi_brw_app_ui_callback_show_stored_page_toolbar;
    #endif /* #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__ */

        default:
            return (show_toolbar_func_ptr)NULL;
    }
}
#endif /* #ifdef __MMI_ICON_BAR_SUPPORT__*/

#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_dynamic_list_number_of_items
 * DESCRIPTION
 *  This function is to return the number of items to be displayed in a 
 * dynamic screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a dynamic list screen
 *****************************************************************************/
U16 mmi_brw_app_get_dynamic_list_number_of_items(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BOOKMARKS:
            return (mmi_brw_dmgr_get_number_of_bookmark_list_items());

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH:
            return mmi_brw_dmgr_get_number_of_browse_path_list_items();
    #endif

    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case SCR_ID_BRW_SELECT_BOOKMARK:
            return (mmi_brw_dmgr_get_number_of_select_bookmark_list_items());
    #endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES:
            return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count;
#endif

#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES_HOST:
            return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_count;
#endif
#endif

#ifndef SLIM_WAP_MMS
        case SCR_ID_BRW_PAGE_ACTIONS:
            return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count;
#endif
#ifdef OBIGO_Q05A 
        case SCR_ID_BRW_PAGE_OBJECT_TYPES:
        {
            U8 list_count;
            srv_brw_get_page_object_types_count(&list_count);
            return (U16)list_count;
        }

        case SCR_ID_BRW_PAGE_OBJECTS:
        {
            U16 list_count;
            list_count = srv_brw_get_page_objects_count(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->selected_page_object_type);
            return list_count;
        }
#endif /* #ifdef OBIGO_Q05A */
#ifdef WAP_SEC_SUPPORT
        case SCR_ID_BRW_TRUSTED_CERTIFICATES:
            return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
#endif /* WAP_SEC_SUPPORT */

    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGES:
            return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count;
    #endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE:
            return SRV_BRW_MAX_SHORTCUTS_COUNT;
#endif /* __MMI_Q05A_LAUNCH_SCREEN__ */
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_dynamic_list_highlighted_item
 * DESCRIPTION
 *  This function is to set the highlighted item to be displayed in the dynamic
 * list screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a dynamic list screen
 *****************************************************************************/
S32 mmi_brw_app_set_dynamic_list_highlighted_item(U16 scr_id, U8** gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlighted_item;
    list_menu_category_history *gui_buff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BOOKMARKS:
        {
            highlighted_item = g_brw_bkm_cntx.sel_file_index;
            break;
        }
    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case SCR_ID_BRW_SELECT_BOOKMARK:
        {
            highlighted_item = g_brw_bkm_sel_bkm_cntx.sel_file_index;
            break;
        }
    #endif
        default:
            return 0;
    }
    if(*gui_buffer != NULL)
    {
        gui_buff = (list_menu_category_history*)(*gui_buffer);
        gui_buff->highlighted_item = highlighted_item;
    }
    return highlighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_hide_handler_for_parent_menu_id
 * DESCRIPTION
 *  This function is to return the hide handler function to be called for a
 * particular parent menu id that is being displayed
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the callback function
 *****************************************************************************/
hide_hdlr_func_ptr mmi_brw_get_hide_handler_for_parent_menu_id(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_id)
    {
#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case MENU_ID_BRW_BKM_OPTIONS_FOR_FOLDER:
    #endif
        case MENU_ID_BRW_BKM_OPTIONS_FOR_EMPTY_FOLDER:
        case MENU_ID_BRW_BKM_OPTIONS_FOR_DEFAULT_FILE:
        case MENU_ID_BRW_BKM_OPTIONS_FOR_USER_FILE:
        case MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_bookmark_options_hide_handler;
#endif

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_browser_path_options_hide_handler;
    #endif

    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        case MENU_ID_BRW_SEND_ADDRESS_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_send_address_hide_handler;
    #endif
        
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case MENU_ID_BRW_RECENT_PAGE_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_recent_pages_options_hide_handler;
#endif

#ifdef OBIGO_Q05A
        case MENU_ID_BRW_PAGE_OBJECTS_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_page_object_options_hide_handler;

#endif /* #ifdef OBIGO_Q05A */
        case MENU_ID_BRW_SELECT_MODE_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_select_mode_options_hide_handler;
        case MENU_ID_BRW_RENDERED_PAGE_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_ren_page_options_hide_handler;

        case MENU_ID_BRW_SETTINGS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_settings_hide_handler;

        case MENU_ID_BRW_BROWSER_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_browser_options_hide_handler;

#ifdef WAP_SEC_SUPPORT
#ifdef OBIGO_Q05A
        case MENU_ID_BRW_SECURITY_SETTINGS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_security_settings_hide_handler;

#endif /* OBIGO_Q05A */
#endif /* WAP_SEC_SUPPORT */
        case MENU_ID_BRW_REN_PAGE_ADVANCED_OPTIONS:
            return (hide_hdlr_func_ptr)mmi_brw_app_ui_callback_advanced_options_hide_handler;

        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_highlighted_menu_for_parent_menu_id
 * DESCRIPTION
 *  This function is to return the highlighted menu id correspongind to the menu id
 * passed to the function
 * PARAMETERS
 *  Menu id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the callback function
 *****************************************************************************/
U16 mmi_brw_app_get_highlighted_menu_for_parent_menu_id(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_id)
    {
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case MENU_ID_BRW_RECENT_HOST_SORT:
        case MENU_ID_BRW_RECENT_PAGE_SORT:
            return mmi_brw_app_ui_plugin_get_highlighted_sort_option();
#endif
        case MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES:
            return mmi_brw_app_ui_plugin_get_highlighted_rendering_mode();

        case MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES:
            return mmi_brw_app_ui_plugin_get_highlighted_navigation_mode();
#ifdef __MMI_VECTOR_FONT_SUPPORT__
        case MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE:
            return mmi_brw_app_ui_plugin_get_highlighted_font_size();
#endif
#endif /* OBIGO_Q05A */
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case MENU_ID_BRW_SETTINGS_HOMEPAGE:
            return mmi_brw_app_ui_plugin_get_highlighted_homepage_setting();
#endif
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_construct_view_data
 * DESCRIPTION
 *  This function is to populated the view buffer with the required data and
 * then return the pointer to be displayed in the category screen.
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a inline edit screen
 *****************************************************************************/
PU8 mmi_brw_app_construct_view_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_MEMORY_STATUS:
        {
            if(g_brw_display_info_str)
            {
                mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
            }
            g_brw_display_info_str = (U8*)srv_brw_malloc(BRW_MEMORY_STATUS_MSG_LEN + 1);
            mmi_brw_app_dmgr_get_bookmark_memory_status(g_brw_display_info_str);
            return g_brw_display_info_str;
        }

        case SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE:
        {
            return g_brw_display_info_str;
        }
#ifdef __MMI_BRW_POST_SESSION_INFO__
        case SCR_ID_BRW_POST_SESSION_INFO:
        {
            mmi_brw_app_dmgr_get_post_session_info_str(subMenuData[0]);
            return subMenuData[0];
        }
#endif /* OBIGO_Q05A */
#ifdef __OP01__
        case SCR_ID_BRW_VIEW_URL:
        {
            if(g_brw_display_info_str)
            {
                mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
            }
            g_brw_display_info_str = (U8*)srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string(
            (U8*) g_brw_display_info_str,
            (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
            return g_brw_display_info_str;
        }
#endif /* __OP01__ */
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_VIEW_BOOKMARK:
        {
            if(mmi_brw_is_browser_active())
            {
                mmi_brw_app_dmgr_get_view_bookmark_str(subMenuData[0], 
                    g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title,
                    g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
            }
            else
            {
                if(g_brw_ext_bkm_cntx_p)
                {
                    mmi_chset_ucs2_to_utf8_string((U8*) g_brw_current_title, 
                        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_ext_bkm_cntx_p->bookmark_name) + 1), 
                        (U8*) g_brw_ext_bkm_cntx_p->bookmark_name);
                    mmi_chset_ucs2_to_utf8_string((U8*) g_brw_current_url, 
                        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_ext_bkm_cntx_p->bookmark_url) + 1), 
                        (U8*) g_brw_ext_bkm_cntx_p->bookmark_url);
                    mmi_brw_app_dmgr_get_view_bookmark_str(subMenuData[0], g_brw_current_title, g_brw_current_url);
                }
                else
                {
                    U8* title = OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_title) + 1));
                    U8* url = OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_url) + 1));
                    memset(title, 0, BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_title) + 1));
                    memset(url, 0, BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_url) + 1));
                    mmi_chset_ucs2_to_utf8_string((U8*) title, 
                        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_title) + 1), 
                        (U8*) g_brw_current_title);
                    mmi_chset_ucs2_to_utf8_string((U8*) url, 
                        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) g_brw_current_url) + 1), 
                        (U8*) g_brw_current_url);
                    mmi_brw_app_dmgr_get_view_bookmark_str(subMenuData[0], title, url);
                    OslMfree(title);
                    OslMfree(url);
                }
            }
            return subMenuData[0];
        }
#endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_construct_view_data
 * DESCRIPTION
 *  This function is to get the buffer to be passed to the editor screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  pointer of the buffer to be used in editor screen
 *****************************************************************************/
PU8 mmi_brw_app_get_editor_buffer(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
        case SCR_ID_BRW_ENTER_URL:
        case SCR_ID_BRW_EDIT_URL:
        {
            return g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url;
        }
#endif

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BKM_CREATE_FOLDER:
#endif
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
#endif /* #ifdef OBIGO_Q05A */
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
        {
            return g_brw_display_info_str;
        }
        case SCR_ID_BRW_EDIT_BOOKMARK_NAMING_RULE:
        {
            return g_brw_current_title;
        }
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
        {
            return g_brw_current_url;
        }
#endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_editor_input_type
 * DESCRIPTION
 *  This function is to get the input type to be passed to the editor screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  pointer of the buffer to be used in editor screen
 *****************************************************************************/
U32 mmi_brw_app_get_editor_input_type(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
        case SCR_ID_BRW_ENTER_URL:
        case SCR_ID_BRW_EDIT_URL:
        {
            return IMM_INPUT_TYPE_SENTENCE;
        }
#endif
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
        {
            return IMM_INPUT_TYPE_URL;
        }
#endif
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
#endif /* #ifdef OBIGO_Q05A */
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
        {
            return IMM_INPUT_TYPE_SENTENCE;
        }
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_editor_buffer_length
 * DESCRIPTION
 *  This function is to get the buffer length to be passed to the editor screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  pointer of the buffer to be used in editor screen
 *****************************************************************************/
U32 mmi_brw_app_get_editor_buffer_length(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
        case SCR_ID_BRW_ENTER_URL:
        case SCR_ID_BRW_EDIT_URL:
            return (SRV_BRW_ADDRESS_LIST_URL_LENGTH * ENCODING_LENGTH);
#endif

    #ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
    #endif /* #ifdef OBIGO_Q05A */
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
            return ((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);

#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
            return ((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
#endif
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_editor_buffer_char_count
 * DESCRIPTION
 *  This function is to get the character count of buffer to be passed 
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  character count of buffer corresponding to the screen passed
 *****************************************************************************/
U32 mmi_brw_app_get_editor_buffer_char_count(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
        case SCR_ID_BRW_ENTER_URL:
        case SCR_ID_BRW_EDIT_URL:
            return (SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1);
#endif

    #ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
    #endif /* #ifdef OBIGO_Q05A */
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
            return (SRV_BRW_MAX_TITLE_LENGTH);

#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
            return SRV_BRW_MAX_URL_LEN;
#endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_editor_title_string
 * DESCRIPTION
 *  This function is to get the character count of buffer to be passed 
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  character count of buffer corresponding to the screen passed
 *****************************************************************************/
U16 mmi_brw_app_get_editor_title_string(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_ENTER_URL:
            return (STR_ID_BRW_SEARCH_OR_INPUT_URL);

        case SCR_ID_BRW_EDIT_URL:
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BKM_CREATE_FOLDER:
    #endif
#if (defined(OBIGO_Q05A) || !defined(__MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__))
    #ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
    #endif /* #ifdef OBIGO_Q05A */
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
    #endif
            return (STR_GLOBAL_EDIT);
#endif

    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
            return (STR_ID_BRW_ENTER_NAME);
    #endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_naming_rule_operation
 * DESCRIPTION
 *  This function is to get the opeartion type for which the naming rule CUI is
 * being created
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_brw_app_get_naming_rule_operation(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BKM_CREATE_FOLDER:
            return g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type;
#endif

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_naming_rule_selected_folder_path
 * DESCRIPTION
 *  This function is to get the selected folder path under which the desired
 * operation is being performed
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
U8* mmi_brw_app_get_naming_rule_selected_folder_path(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        default:
            return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_proc_func_for_fseditor
 * DESCRIPTION
 *  This function is to get the selected folder path under which the desired
 * operation is being performed
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
mmi_proc_func mmi_brw_app_get_proc_func_for_fseditor(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
        case SCR_ID_BRW_EDIT_URL:
        case SCR_ID_BRW_ENTER_URL:
        {
            return (mmi_proc_func)mmi_brw_app_enter_url_fseditor_cui_proc;
        }
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_STORED_PAGE_RENAME:
        {
            return (mmi_proc_func)mmi_brw_app_stored_page_rename_fseditor_cui_proc;
        }
#endif
        case SCR_ID_BRW_EDIT_STORE_OFFLINE:
        {
            return (mmi_proc_func)mmi_brw_app_store_offline_fseditor_cui_proc;
        }
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        case SCR_ID_BRW_EDIT_HOMEPAGE:
        {
            return (mmi_proc_func)mmi_brw_app_edit_homepage_fseditor_cui_proc;
        }
#endif
        default:
            return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_viewer_buffer_length
 * DESCRIPTION
 *  This function is to get the length of the data to be displayed in viewer 
 * screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a inline edit screen
 *****************************************************************************/
U16 mmi_brw_app_get_viewer_buffer_length(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_MEMORY_STATUS:
        case SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE:
        {
            return (mmi_ucs2strlen((S8*) g_brw_display_info_str) + 1);
        }

#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_VIEW_BOOKMARK:
        {
            return mmi_ucs2strlen((S8*) subMenuData[0]) + 1;            
        }
#endif
#ifdef __MMI_BRW_POST_SESSION_INFO__
        case SCR_ID_BRW_POST_SESSION_INFO:
        {
            return mmi_ucs2strlen((S8*) subMenuData[0]) + 1;            
        }
#endif
#ifdef __OP01__
        case SCR_ID_BRW_VIEW_URL:
        {
            return (mmi_ucs2strlen((S8*) g_brw_display_info_str) + 1);
        }
#endif /* __OP01__ */
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_small_screen_data
 * DESCRIPTION
 *  This function is to get the data to be displayed in the small screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a inline edit screen
 *****************************************************************************/
void mmi_brw_app_get_small_screen_data(U16 scr_id, U16 *msg_str, U16 *str_id, U16 *img_id, srv_prof_tone_enum *tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
        case SCR_ID_BRW_BUSY_SCREEN:
        case SCR_ID_BRW_TEMP_BUSY_SCREEN:
        {
            *msg_str = g_brw_busy_scr_msg_str_id;
            *str_id = g_brw_busy_scr_title_str_id;
            *img_id = (U16)mmi_get_event_based_image(MMI_EVENT_PROGRESS);
            break;
        }
#ifdef __MMI_URI_AGENT__
        case SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN:
        {
            *msg_str = STR_ID_BRW_UHA_CONNECT_TO_BROWSER;
            *img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
            *tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
            break;
        }
#endif /* __MMI_URI_AGENT__ */
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ 
        case SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN:
        {
            *msg_str = STR_ID_BRW_CANCEL_UPLOADING;
            *img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
            *tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
            break;
        }
#endif /* #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
        case SCR_ID_BRW_OUT_OF_MEM_CONFIRMATION_SCREEN:
        {
            *msg_str = STR_GLOBAL_INSUFFICIENT_MEMORY;
            *img_id = mmi_get_event_based_image(MMI_EVENT_FAILURE);
            *tone_id = mmi_get_event_based_sound(MMI_EVENT_FAILURE);
            break;
        }

#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
        case SCR_ID_BRW_LOADING_TIME_CHECK:
        {
            *msg_str = STR_ID_BRW_LOADING_TIME_CHECKING;
            *img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
            *tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
            break;
        }
#endif
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
        case SCR_ID_BRW_PAGE_SIZE_CHECK:
        {
            *msg_str = STR_ID_BRW_PAGE_SIZE_CHECKING;
            *img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
            *tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
            break;
        }
#endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_menu_cui_src_type
 * DESCRIPTION
 *  This function is to get the menu CUI src type for a particular screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  cui_menu_src_type_enum
 *****************************************************************************/
cui_menu_src_type_enum mmi_brw_app_get_menu_cui_src_type(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
        case SCR_ID_BRW_INTERNET_SERVICES:
        {
            return CUI_MENU_SRC_TYPE_APPCREATE;
            break;
        }
#endif
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_ENCODING_METHODS:
        {
            return CUI_MENU_SRC_TYPE_APPCREATE;
            break;
        }
#endif
        default:
        {
            return CUI_MENU_SRC_TYPE_RESOURCE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_cui_menu_type
 * DESCRIPTION
 *  This function is to get the CUI menu type for a particular screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  cui_menu_type_enum
 *****************************************************************************/
cui_menu_type_enum mmi_brw_app_get_cui_menu_type(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
        case SCR_ID_BRW_INTERNET_SERVICES:
        {
            return CUI_MENU_TYPE_APPMAIN;
            break;
        }
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_ENCODING_METHODS:
        {
            return CUI_MENU_TYPE_APPSUB;
            break;
        }
#endif
        default:
        {
            return CUI_MENU_TYPE_FROM_RESOURCE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_parent_menu_id
 * DESCRIPTION
 *  This function is to get the parent menu id
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
U16 mmi_brw_app_get_parent_menu_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 parent_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
        case SCR_ID_BRW_BOOKMARK_OPTIONS:
        {
            parent_id = mmi_brw_app_dmgr_get_bookmark_options_parent_menu();
            return parent_id;
            break;
        }
        case SCR_ID_BRW_RENDERED_PAGE_OPTIONS:
        {
            parent_id = mmi_brw_app_dmgr_get_ren_page_options_parent_menu();
            return parent_id;
            break;
        }
        case SCR_ID_BRW_INTERNET_SERVICES:
        {
            return SERVICES_WAP_MENU_ID;
            break;
        }
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGE_OPTIONS:
        {
            return MENU_ID_BRW_RECENT_PAGE_OPTIONS;
            break;
        }
#endif
        case SCR_ID_BRW_SETTINGS:
        {
            return MENU_ID_BRW_SETTINGS;
            break;
        }
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGE_OPTIONS:
        {
            return MENU_ID_BRW_STORED_PAGE_OPTIONS;
            break;
        }
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */      
#ifdef WAP_SEC_SUPPORT
        case SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS:
        {
            return MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS;
            break;
        }
#endif /* WAP_SEC_SUPPORT */
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_PAGE_OBJECTS_OPTIONS:
        {
            return MENU_ID_BRW_PAGE_OBJECTS_OPTIONS;
            break;
        }
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS:
        {
            return MENU_ID_BRW_RECENT_PAGE_OPTIONS_1;
            break;
        }
#endif
        case SCR_ID_BRW_ENCODING_METHODS:
        {
            return 0;
            break;
        }
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS:
        {
            return MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS;
            break;
        }
#endif
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        case SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR:
        {
            return MENU_ID_BRW_BKM_OPTIONS_OPEN_FROM_FMGR;
            break;
        }
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
        case SCR_ID_BRW_EDITOR_OPTION:
        {
            return MENU_ID_BRW_EDITOR_OPTION;
            break;
        }
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE_OPTIONS:
        {
            return MENU_ID_BRW_LAUNCH_PAGE_OPTIONS;
            break;
        }
#endif /* __MMI_Q05A_LAUNCH_SCREEN__ */
        default:
        {
            ASSERT(0);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_menu_cui_proc_func
 * DESCRIPTION
 *  This function is to get the proc function that will handle the framework 
 * events for a corresponding screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
browser_cui_proc mmi_brw_app_get_menu_cui_proc_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
        case SCR_ID_BRW_INTERNET_SERVICES:
        {
            return (browser_cui_proc)mmi_brw_app_internet_service_menu_cui_proc;
            break;
        }
        case SCR_ID_BRW_BOOKMARK_OPTIONS:
        {
            return (browser_cui_proc)mmi_brw_app_bookmarks_options_menu_cui_proc;
            break;
        }
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS:
#endif /* OBIGO_Q05A */
        case SCR_ID_BRW_RECENT_PAGE_OPTIONS:
        {
            return (browser_cui_proc)mmi_brw_app_recent_page_menu_cui_proc;
            break;
        }
#endif
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGE_OPTIONS:
        {
            return (browser_cui_proc)mmi_brw_app_stored_page_menu_cui_proc;
            break;
        }
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
        case SCR_ID_BRW_RENDERED_PAGE_OPTIONS:
        {
            return (browser_cui_proc)mmi_brw_app_render_page_menu_cui_proc;
            break;
        }
        case SCR_ID_BRW_SETTINGS:
         {
            return (browser_cui_proc)mmi_brw_app_settings_menu_cui_proc;
            break;
        }
        case SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS:
        {
            return mmi_brw_app_settings_trusted_certificate_options_menu_cui_proc;
            break;
        }
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS:
        {
            return mmi_brw_app_browse_path_menu_cui_proc;
            break;
        }
    #endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
        case SCR_ID_BRW_EDITOR_OPTION:
        {
            return mmi_brw_app_enter_url_editor_options_menu_cui_proc;
            break;
        }
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        case SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR:
		{
            return (browser_cui_proc)mmi_brw_app_bookmark_in_fmgr_menu_cui_proc;
			break;
		}
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_PAGE_OBJECTS_OPTIONS:
		{
            return (browser_cui_proc)mmi_brw_app_objects_options_menu_cui_proc;
			break;
		}
        case SCR_ID_BRW_ENCODING_METHODS:
		{
            return (browser_cui_proc)mmi_brw_app_encoding_methods_cui_proc;
			break;
		}
#endif /* OBIGO_Q05A */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE_OPTIONS:
		{
            return (browser_cui_proc)mmi_brw_app_shortcut_options_menu_cui_proc;
			break;
		}
#endif /* OBIGO_Q05A */
        default:
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_menu_cui_group_id
 * DESCRIPTION
 *  This function is to get the proc function that will handle the framework 
 * events for a corresponding screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
MMI_ID mmi_brw_app_get_menu_cui_group_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
        case SCR_ID_BRW_INTERNET_SERVICES:
        {
            return BRW_INTERNET_SERVICE_MENU_GRP;
            break;
        }
        case SCR_ID_BRW_BOOKMARK_OPTIONS:
        {
            return BRW_MENU_CUI_BOOKMARK_OPT;
            break;
        }
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS:
#endif /* OBIGO_Q05A */
        case SCR_ID_BRW_RECENT_PAGE_OPTIONS:
        {
            return BRW_MENU_CUI_RECENT_PAGE_OPT;
            break;
        }
#endif
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGE_OPTIONS:
        {
            return BRW_MENU_CUI_STORED_PAGE_OPT;
            break;
        }
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
        case SCR_ID_BRW_RENDERED_PAGE_OPTIONS:
        {
            return BRW_MENU_CUI_RENDERED_PAGE_OPT;
            break;
        }
        case SCR_ID_BRW_SETTINGS:
         {
            return BRW_MENU_CUI_SETTINGS;
            break;
        }
        case SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS:
        {
            return BRW_MENU_CUI_SECURITY_SETTINGS;
            break;
        }
        case SCR_ID_BRW_RENDERING_MODES:
        {
            return BRW_MENU_CUI_SETTINGS_RENDERING_MODES;
            break;
        }
        case SCR_ID_BRW_NAVIGATION_MODES:
        {
            return BRW_MENU_CUI_SETTINGS_NAVIGATION_MODES;
            break;
        }
        case SCR_ID_BRW_FONT_SIZE:
        {
            return BRW_MENU_CUI_SETTINGS_FONT_SIZE;
            break;
        }
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS:
        {
            return BRW_MENU_CUI_BKM_BROWSE_PATH;
            break;
        }
    #endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
        case SCR_ID_BRW_EDITOR_OPTION:
        {
            return BRW_MENU_CUI_EDITOR_OPTIONS;
            break;
        }
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        case SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR:
        {
            return BRW_MENU_CUI_BOOKMARKS_IN_FMGR;
            break;
        }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_PAGE_OBJECTS_OPTIONS:
		{
            return BRW_MENU_CUI_PAGE_OBJECTS_OPTION;
			break;
		}
        case SCR_ID_BRW_ENCODING_METHODS:
		{
            return BRW_MENU_CUI_ENCODING_METHODS;
			break;
		}
#endif /* OBIGO_Q05A */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE_OPTIONS:
		{
            return BRW_MENU_CUI_SHORTCUT_OPTIONS;
			break;
		}
#endif /* OBIGO_Q05A */
        default:
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_grp_id_by_scrn_id
 * DESCRIPTION
 *  This function is to return the number of items to be displayed in an 
 * inline screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  number of items for a inline edit screen
 *****************************************************************************/
MMI_ID mmi_brw_app_get_grp_id_by_scrn_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_ADD_TO_BOOKMARK:
            return g_brw_app_cntx.add_bkm_cid;
    #endif
    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case SCR_ID_BRW_SELECT_BOOKMARK:
            return g_brw_app_cntx.sel_bkm_cid;
    #endif

        default:
            return g_brw_app_cntx.brw_scr_group_id;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_inline_cui_proc_func
 * DESCRIPTION
 *  This function is to get the proc function that will handle the framework 
 * events for a inline screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
browser_cui_proc mmi_brw_app_get_inline_cui_proc_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_EDIT_BOOKMARK:
        case SCR_ID_BRW_ADD_BOOKMARK:
        case SCR_ID_BRW_ADD_TO_BOOKMARK:
        {
            return (browser_cui_proc)mmi_brw_bkm_add_bookmark_inline_cui_proc;
            break;
        }
    #endif
        case SCR_ID_BRW_BROWSER_PREFERENCES:
        {
            return (browser_cui_proc)mmi_brw_settings_pref_inline_cui_proc ;
            break;
        }
        case SCR_ID_BRW_SAVE_TO_BOOKMARK:
        {
            return (browser_cui_proc)mmi_brw_bkm_save_bookmark_proc ;
            break;
        }
        case SCR_ID_BRW_SHOW_AUTH_DIALOG:
        {
            return (browser_cui_proc)mmi_brw_authentication_inline_cui_proc ;
            break;
        }
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_OBJECT_PROPERTIES:
        {
            return (browser_cui_proc)mmi_brw_app_properties_proc;
            break;
        }
#endif /* OBIGO_Q05A */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_EDIT_SHORTCUT:
        {
            return (browser_cui_proc)mmi_brw_edit_shortcut_inline_cui_proc;
            break;
        }
#endif /* OBIGO_Q05A */
        default:
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_inline_cui_proc_func
 * DESCRIPTION
 *  This function is to get group id to be created for displaying the
 * inline CUI
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id mmi_brw_app_get_inline_group_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_EDIT_BOOKMARK:
        case SCR_ID_BRW_ADD_BOOKMARK:
        case SCR_ID_BRW_ADD_TO_BOOKMARK:
        {
            return BRW_ADD_BOOKMARK_GRP_ID;
            break;
        }
    #endif
        default:
        {
            return BRW_INLINE_GRP_ID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_inline_cui_global_data
 * DESCRIPTION
 *  This function is to get the proc function that will handle the framework 
 * events for a inline screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
const cui_inline_struct mmi_brw_app_get_inline_cui_global_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_ADD_BOOKMARK:
        case SCR_ID_BRW_ADD_TO_BOOKMARK:
        {
            return g_brw_bkm_initial_data_add_bookmark;
            break;
        }
        case SCR_ID_BRW_EDIT_BOOKMARK:
        {
            return g_brw_bkm_initial_data_edit_bookmark;
            break;
        }
    #endif
        case SCR_ID_BRW_BROWSER_PREFERENCES:
        {
            return g_brw_settings_pref;
            break;
        }
        case SCR_ID_BRW_SAVE_TO_BOOKMARK:
        {
            return g_brw_bkm_initial_data_view_bookmark;
            break;
        }
        case SCR_ID_BRW_SHOW_AUTH_DIALOG:
        {
            return g_brw_ren_initial_data_auth;
            break;
        }
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_OBJECT_PROPERTIES:
        {
            return g_brw_initial_data_obj_properties;
            break;
        }
#endif /* OBIGO_Q05A */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_EDIT_SHORTCUT:
        {
            return g_brw_initial_data_edit_shortcut;
            break;
        }
#endif
        default:
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_inline_cui_fill_func
 * DESCRIPTION
 *  This function is to get the proc function that will handle the framework 
 * events for a inline screen
 * screen
 * PARAMETERS
 *  Screen Id       [IN]       The Screen ID
 * RETURNS
 *  Menu Id
 *****************************************************************************/
FuncPtr mmi_brw_app_get_inline_cui_fill_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_EDIT_BOOKMARK:
        case SCR_ID_BRW_ADD_BOOKMARK:
        case SCR_ID_BRW_ADD_TO_BOOKMARK:
        {
            return (FuncPtr)mmi_brw_add_bookmark_inline_cui_fill_data ;
            break;
        }
    #endif
        case SCR_ID_BRW_BROWSER_PREFERENCES:
        {
            return (FuncPtr)mmi_brw_settings_pref_inline_cui_fill_data ;
            break;
        }
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case SCR_ID_BRW_SAVE_TO_BOOKMARK:
        {
            return (FuncPtr)mmi_brw_view_bookmark_inline_cui_fill_data ;
            break;
        }
    #endif
        case SCR_ID_BRW_SHOW_AUTH_DIALOG:
        {
            return (FuncPtr)mmi_brw_authentication_inline_cui_fill_data;
            break;
        }
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_OBJECT_PROPERTIES:
        {
            return (FuncPtr)mmi_brw_properties_inline_cui_fill_data;
            break;
        }
#endif /* OBIGO_Q05A */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_EDIT_SHORTCUT:
        {
            return (FuncPtr)mmi_brw_edit_shortcut_inline_cui_fill_data;
            break;
        }
#endif /* OBIGO_Q05A */
        default:
        {
            ASSERT(0);
        }
    }
}
/*************************************SCREEN DATA FUNC******************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_all_db_index
 * DESCRIPTION
 *  This function is to set the global index which points toits database to a
 * particular screen id
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_app_set_all_db_index(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_ctrlr_db_index(scr_id);
    mmi_brw_app_set_res_db_index(scr_id);
    mmi_brw_app_set_scrhdlr_db_index(scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_title_icon
 * DESCRIPTION
 *  This function is to get the title icon to be displayed on a screen
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_brw_app_get_title_icon(U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
    return (mmi_brw_get_wap_icon());
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_free_browser_memory
 * DESCRIPTION
 *  This func is used to free the Browser memory if allocated by the pointer
 * passed as argument to it and then set the pointer to NULL
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_free_browser_memory(void **ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (ptr);

    if (*ptr != NULL)
    {
        srv_brw_free(*ptr);
        *ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_cancel_browser_preferences
 * DESCRIPTION
 *  This function is to cancel the browser preferences save process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_cancel_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_group_close(g_brw_app_cntx.brw_inline_cui_gid);                
	
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_encoding_methods_initialize_list
 * DESCRIPTION
 *  Entry function for encoding methods
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_encoding_methods_initialize_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_of_charsets;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_charsets = bam_get_total_charset_num();
    MMI_ASSERT(num_of_charsets);

    g_brw_app_cntx.charset_list_p = OslMalloc(num_of_charsets * sizeof(bam_charset_name_id_t));

    bam_get_all_charsets(g_brw_app_cntx.charset_list_p);

    /* replacing the framework provided Ascii charset with Auto-select option
       so that it will be in sync with core */
    g_brw_app_cntx.charset_list_p[0].id = WAP_BAM_UNKNOWN_CHARSET;
    g_brw_app_cntx.charset_list_p[0].name_id = STR_ID_BRW_CHARSET_AUTO_SELECT;
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_context_init
 * DESCRIPTION
 *  This function is to initialize the application global context variables to
 * some default value on bootup
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_app_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.common_gateway_flag = MMI_FALSE;
    g_brw_app_cntx.editor_scr_id = 0;
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    g_brw_app_cntx.send_msg_cui_id = GRP_ID_INVALID ;
#endif
#if defined(__MMI_OP11_HOMESCREEN__)  || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    g_brw_app_cntx.isBookmarkLaunched = MMI_FALSE;
#endif 
#ifdef __MMI_URI_AGENT__
    g_brw_app_cntx.uha_info_p = NULL;
#endif 
    g_brw_app_cntx.top_scr_id = SCR_ID_BRW_FIRST_SCREEN_ID;
    g_brw_app_cntx.brw_launching_pad = BRW_LPD_NONE;
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)	
    g_brw_app_cntx.brw_launching_pad_for_OHS = 	BRW_LPD_NONE ;
#endif	
    g_brw_app_cntx.brw_dynamic_cntx_p = NULL;
#ifdef __MMI_FTE_SUPPORT__
    g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
#endif
#ifdef __MMI_VBOOKMARK__
    mmi_brw_app_bookmarks_context_init();
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
    g_brw_bkm_sel_bkm_cntx.sel_folder_name = NULL;
#endif
#endif /* __MMI_VBOOKMARK__ */ 
    g_brw_app_cntx.sat_profile_update = MMI_FALSE;
#ifdef OBIGO_Q05A
    g_brw_app_cntx.charset_list_p = NULL;
    /* initializing the encoding methods list */
    mmi_brw_app_encoding_methods_initialize_list(); //srv init
#endif /* OBIGO_Q05A */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_GoBackServicesMenu
 * DESCRIPTION
 *  This function is to return from the WAP menu by deinitializing the browser
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the callback function
 *****************************************************************************/
void mmi_brw_app_GoBackServicesMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_exit();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_exit
 * DESCRIPTION
 *  This function is being called to deinitialize the browser and get back to the
 *  previous screen if user wants to exit from it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_deinit();
    //mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_progress_screen_params
 * DESCRIPTION
 *  This func is used for setting the progress screen title and message string
 * PARAMETERS
 *  title_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_progress_screen_params(U16 title_id, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_busy_scr_title_str_id = title_id;
    g_brw_busy_scr_msg_str_id = msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_progress_screen
 * DESCRIPTION
 *  This func is used for setting the progress screen title and msg id and then 
 * diplaying the progress screen
 * PARAMETERS
 *  title_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_progress_screen(U16 title_id, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_progress_screen_params(title_id, msg_id);
    mmi_brw_app_if_show_progressing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_load_url
 * DESCRIPTION
 *  This function is the external interface for fetching a given url
 * PARAMETERS
 *  url_p       [IN]        Url in UTF-8
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_load_url(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);

    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_LOAD_URL);

    MMI_PRINT(MOD_MMI_INET_APP, MMI_INET_TRC_G4_BRW, "[BrowserMain][mmi_brw_load_url] url=%s", url_p);

    if (strlen((S8*) url_p) > WAP_MAX_SEARCH_URL_LENGTH)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
    #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
        mmi_rmgr_unlock_session_callback();
    #endif 
        return;
    }

    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url, (WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*) url_p);

    if (srv_brw_validate_url(g_brw_current_url, WAP_MAX_SEARCH_URL_LENGTH) < 0)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
    #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
        mmi_rmgr_unlock_session_callback();
    #endif 
        return;
    }

    /* if a live browser instance is already there then simply fetch the url */
    if (mmi_brw_is_browser_active())
    {
        mmi_brw_app_pre_entry_goto_url();
    }
    else
    {
        g_brw_app_cntx.brw_launching_pad = BRW_LPD_EXTERNAL_LOAD_URL_REQ;
        mmi_brw_app_common_gateway();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_service_instance
 * DESCRIPTION
 *  This func is used for creating a instance of Browser WAP service for 
 * launching Browser.
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_create_service_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_screen_info_struct screen_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if this flag is TRUE then there is no need of showing busy screen */
    /* again because in this case it should have displayed from common */
    /* gateway interface */
    if (g_brw_app_cntx.common_gateway_flag)
    {
        g_brw_app_cntx.common_gateway_flag = MMI_FALSE;
        if(!mmi_frm_group_is_present(BRW_SCREEN_GROUP))
        {
            mmi_frm_group_create_ex(GRP_ID_ROOT, BRW_CLOSE_GROUP_ID, mmi_brw_close_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            mmi_frm_group_create_ex(GRP_ID_ROOT, BRW_SCREEN_GROUP, mmi_brw_internet_service_screen_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_brw_app_cntx.brw_scr_group_id = BRW_SCREEN_GROUP;
            /* showing the busy screen */
            mmi_brw_app_set_progress_screen_params(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
            mmi_brw_app_if_show_progressing_screen();
         }

    }
    else
    {
        if(!mmi_frm_group_is_present(BRW_SCREEN_GROUP))
        {
    		mmi_frm_group_create_ex(GRP_ID_ROOT, BRW_CLOSE_GROUP_ID, mmi_brw_close_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			mmi_frm_group_create_ex(GRP_ID_ROOT, BRW_SCREEN_GROUP, mmi_brw_internet_service_screen_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			g_brw_app_cntx.brw_scr_group_id = BRW_SCREEN_GROUP;
		}

        /* showing the busy screen */
        mmi_brw_app_set_progress_screen_params(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
        mmi_brw_app_if_show_progressing_screen();
    }

    Cat431GetScreenInfo((MMI_BOOL)g_srv_brw_cntx.screen_size_status, &screen_info.x, &screen_info.y, &screen_info.w, &screen_info.h, &screen_info.title_layer, &screen_info.bottom_layer);
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
    screen_info.h = screen_info.h - MMI_ICON_BAR_HEIGHT;
#endif
#endif
    obj.rsp_callback = mmi_brw_srv_hdlr_create_instance;
    obj.req_data = (void*)&screen_info;
    srv_brw_create_instance_req(&obj, g_brw_app_memory_pool);
    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_session_init
 * DESCRIPTION
 *  This func is used for initializing the Browser Application variables for
 * a particular session
 * PARAMETERS
 *  title_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_session_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.top_scr_id = SCR_ID_BRW_FIRST_SCREEN_ID;
    g_brw_app_cntx.editor_scr_id = 0;
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    g_brw_app_cntx.send_msg_cui_id = GRP_ID_INVALID; 
#endif

#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    mmi_brw_bookmarks_dynamic_context_init();
#endif
#endif
#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
    g_brw_app_cntx.nine_way_mode = MMI_TRUE;
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */

    mmi_brw_app_dynamic_context_init();
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    srv_cbm_register_bearer_event(
            SRV_CBM_BEARER_EVENT_DISCONNECT | SRV_CBM_BEARER_EVENT_SWITCH,
            (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id)),
            mmi_brw_app_if_bearer_switch_hdlr,
            NULL);
#endif
}




/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dynamic_context_init
 * DESCRIPTION
 *  Initialize the browser app dynamic context whenever user launches WAP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dynamic_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p = (brw_app_dynamic_context_struct*)srv_brw_malloc(sizeof(brw_app_dynamic_context_struct));
    memset(g_brw_app_cntx.brw_dynamic_cntx_p, 0, sizeof(brw_app_dynamic_context_struct));

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
    g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting = MMI_FALSE;
    g_brw_app_cntx.brw_dynamic_cntx_p->mainMenuEntryFlag = MMI_FALSE;
    g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag = MMI_FALSE;
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    g_brw_app_cntx.brw_dynamic_cntx_p->brw_first_page_flag = MMI_TRUE;
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
    g_brw_app_cntx.brw_dynamic_cntx_p->list_refresh_flag = MMI_FALSE;
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    g_brw_app_cntx.brw_dynamic_cntx_p->address_list_flag = MMI_FALSE;
#endif /* #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
    g_brw_app_cntx.brw_dynamic_cntx_p->reset_hiliter_flag = MMI_FALSE;
    g_brw_app_cntx.brw_dynamic_cntx_p->view_cert_flag = MMI_FALSE;
#ifdef OBIGO_Q05A
    g_brw_app_cntx.brw_dynamic_cntx_p->encoding_type_new_flag = MMI_FALSE;
#endif /* OBIGO_Q05A */
    g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_FALSE;
#ifdef __MMI_FTE_SUPPORT__
    g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send = MMI_FALSE;
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef OBIGO_Q03C_BROWSER
    g_brw_app_cntx.brw_dynamic_cntx_p->reload_req_processing = MMI_FALSE;
    g_brw_app_cntx.brw_dynamic_cntx_p->load_req_processing = MMI_FALSE;
#endif
    g_brw_app_cntx.brw_dynamic_cntx_p->requested_url_p = NULL;
    g_brw_app_cntx.brw_dynamic_cntx_p->is_bearer_active = MMI_FALSE;
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)	
    g_brw_app_cntx.brw_launching_pad_for_OHS = 	BRW_LPD_NONE ;
#endif 
    /* initializing the global string arrays */
    g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray[BRW_PREF_NEVER_INDEX] = GetString(STR_ID_BRW_NEVER);
    g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray[BRW_PREF_ALWAYS_INDEX] = GetString(STR_ID_BRW_ALWAYS);

    g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray[BRW_PREF_DISABLE_INDEX] = GetString(STR_ID_BRW_DISABLE);
    g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray[BRW_PREF_ENABLE_INDEX] = GetString(STR_ID_BRW_ENABLE);
}    


#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_dynamic_context_init
 * DESCRIPTION
 *  it initializes the global bookmark context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_dynamic_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_cntx.bkm_dynamic_cntx = (brw_bkm_dynamic_context_struct*)srv_brw_malloc(sizeof(brw_bkm_dynamic_context_struct));
 
    g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index = -1;
    g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type = BRW_BKM_FOLDER_NONE;
    g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count = 0;
    mmi_ucs2cpy((S8*) g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_name, (S8*) L"");
}
#endif
#endif /* __MMI_VBOOKMARK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_launch_if_or_insert_in_history
 * DESCRIPTION
 *  Common function to launch the if function if Progress screen is active else
 *  replace the Progress screen with the new screen in history.
 * PARAMETERS
 *  new_scr_id      [IN]
 *  new_scr_if_func [IN]
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_brw_app_launch_if_or_insert_in_history(U16 new_scr_id, FuncPtr new_scr_if_func, mmi_id parent_group_id, mmi_proc_func proc_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id prev_group_id;
    mmi_frm_node_struct new_node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(parent_group_id) || mmi_frm_group_is_in_active_serial(g_brw_app_cntx.brw_scr_group_id))
    {
        prev_group_id = g_brw_app_cntx.brw_scr_group_id;
        (*new_scr_if_func)();
        mmi_frm_scrn_close(prev_group_id, SCR_ID_BRW_BUSY_SCREEN);
    }
    else
    {
        MMI_ASSERT(g_brw_app_cntx.brw_scr_group_id != GRP_ID_INVALID);
        MMI_ASSERT(parent_group_id == BRW_RENDERED_PAGE_GRP_ID);
        /* insert usage: no mmi_frm_group_enter */
        mmi_frm_group_create(GRP_ID_ROOT, parent_group_id, proc_func, NULL); 
        
        new_node_info.id = parent_group_id;
        new_node_info.entry_proc = proc_func;

        mmi_frm_group_insert(GRP_ID_ROOT, g_brw_app_cntx.brw_scr_group_id, &new_node_info, MMI_FRM_NODE_AFTER_FLAG);
        mmi_frm_group_set_attribute(parent_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        prev_group_id = g_brw_app_cntx.brw_scr_group_id;
        g_brw_app_cntx.brw_scr_group_id = parent_group_id;
        (*new_scr_if_func)();
        mmi_frm_scrn_close(prev_group_id, SCR_ID_BRW_BUSY_SCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_browser_screen
 * DESCRIPTION
 *  This function is a utility function to check if the screen id passed to 
 * the function is Browser screen
 * PARAMETERS
 *  screen_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_browser_screen(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (screen_id > SCR_ID_BRW_FIRST_SCREEN_ID && screen_id < SCR_ID_BRW_LAST_SCREEN_ID)
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
 *  mmi_brw_app_check_bam_error_code
 * DESCRIPTION
 *  This func is fo checking the error code returned by the BAM
 * PARAMETERS
 *  title_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_check_bam_error_code(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_code > 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_bam_error_handler(error_code);
        }
        mmi_brw_app_delete_busy_screen();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_check_wps_error_code
 * DESCRIPTION
 *  This func is fo checking the error code returned by the WPS module
 * PARAMETERS
 *  title_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_check_wps_error_code(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_code > 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_wps_error_handler(error_code);
        }
        mmi_brw_app_delete_busy_screen();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_busy_screen
 * DESCRIPTION
 *  This function is to remove the Browser busy screen if present and adjust
 * the Browser top screen id properly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_busy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_app_cntx.top_scr_id == SCR_ID_BRW_BUSY_SCREEN)
    {
        //prev_scr_found = GetPreviousScrnIdOf(SCR_ID_BRW_BUSY_SCREEN, &prev_scr_id);
        prev_scr_id = mmi_frm_scrn_get_neighbor_id(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN, MMI_FRM_NODE_AFTER_FLAG);
        if(prev_scr_id && mmi_brw_app_is_browser_screen(prev_scr_id))
        {
            g_brw_app_cntx.top_scr_id = prev_scr_id;
        }
    }
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_active
 * DESCRIPTION
 *  This function is to check if the Browser is currently active or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_brw_is_browser_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.brw_instance_id > 0 && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_all_browser_screens
 * DESCRIPTION
 *  This function is to delete all the open Browser Application screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_all_browser_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SHOW_AUTH_DIALOG);
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN);

    /* Delete the all the screens that can be opened from a received bookmark */
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SAVE_TO_BOOKMARK);
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_VIEW_BOOKMARK);
#endif
    
    /* re-setting browser top screen id to default */
    g_brw_app_cntx.top_scr_id = SCR_ID_BRW_FIRST_SCREEN_ID;

    /* remove the CBM modules connection manager screen */
#ifdef __MMI_CBM_CONNECTION_MANAGER__
	mmi_cnmgr_delete_bearer_detail_screen();
#endif
/* Delete the Widget editor screen if it is open */
#ifdef OBIGO_Q03C_BROWSER
    widget_MMI_delete_symbol_picker_screen_if_present();
#endif /* OBIGO_Q03C_BROWSER */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_bam_error_handler
 * DESCRIPTION
 *  This func is used for displaying the error popup in relation to the error
 * code returned by the BAM
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_bam_error_handler(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BAM_ERROR_HNDLR, error_code);
    if (!mmi_brw_is_browser_active())
    {
        return;
    }

    switch (error_code)
    {
        case WAP_BAM_ERROR_INVALID_INPUT:   /* 14 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVALID_PARAM,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_INVALID_URL: /* 15 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_INVALID_URL,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_INVALID_SCHEME:  /* 16 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_UNSUPPORTED_SCHEME,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_UNKNOWN_CHARSET: /* 21 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_UNSUPPORTED_ENCODING,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_SYNTAX:  /* 22 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_SYNTAX_ERROR,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_UNKNOWN_DOCTYPE: /* 23 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_UNKNOWN_DOC_TYPE,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_UNSUPPORTED_WBXML:   /* 24 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_UNSUPPORTED_WBXML,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_VALIDATION:  /* 25 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_DOC_VALIDATION_ERROR,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_ABORTED: /* 26 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_PARSER_NOT_INITIALIZED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WML: /* 40 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERR_WML_ACCESS_VIOLATION,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WMLS:    /* 41 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERR_WML_SCRIPT_ACCESS_VIOLATION,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_COMMUNICATION:   /* 50 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_COMMUNICATION,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_HOST_NOT_FOUND:  /* 51 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_HOST_NOT_FOUND,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_REQUEST_TIMED_OUT:   /* 52 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_REQUEST_TIMEOUT,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_CONNECTION_FAILED:   /* 53 */
        case WAP_BAM_ERROR_CSD_REACTIVATE:  /* 115 */
	case WAP_BAM_ERROR_CSD_PPP_NEGOTIATED_FAILED:  /* 116 */
	case WAP_BAM_ERROR_CSD_ACT_FAILED:  /* 117 */
	case WAP_BAM_ERROR_CSD_CALL_SETUP_FAILED:  /* 118 */
	case WAP_BAM_ERROR_ABM_REJECTED:    /* 119 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_CONNECTION_FAILED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_SECURE_CONNECTION_FAILED:    /* 54 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_SECURE_CONNECTION_FAILED,
                MMI_EVENT_PROPLEM);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_AUTHENTICATION:  /* 55 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_AUTHENTICATION,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_SECURE_CONNECTION_CANCELLED: /* 56 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_SECURE_CONNECTION_CANCELLED,
                MMI_EVENT_PROPLEM);
            break;
        }
    #endif /*#ifdef OBIGO_Q05A */
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        case WAP_BAM_ERROR_FILE_SIZE_TOO_LARGE: /* 59 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_FILE_SIZE_TOO_LARGE,
                MMI_EVENT_PROPLEM);
            break;
        }
    #endif /*#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
        case WAP_BAM_ERROR_INTERNAL:    /* 70 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INTERNAL_ERROR,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_RESEND_POST_WARNING: /* 71 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_RESEND_POST_WARNING,
                MMI_EVENT_PROPLEM);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_LOW_MEMORY:  /* 72 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_LOW_MEMORY,
                MMI_EVENT_FAILURE);
            break;
        }
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_CONTENT_TOO_LARGE:   /* 73 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_CONTENT_TOO_LARGE,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_OUT_OF_MEMORY:   /* 75 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_INSUFFICIENT_MEMORY,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_LONG_IDLE_TIMEOUT:   /* 76 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_LONG_IDLE_TIMEOUT,
                MMI_EVENT_WARNING);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_EXISTS:  /* 81 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_PAGE_ALREADY_EXISTS,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_FAILED:  /* 82 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_REQUEST_FAILED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_PARTIAL: /* 83 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_PAGE_SAVED_PARTIALLY,
                MMI_EVENT_FAILURE);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED:  /* 84 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_PAGE_LIMIT_EXCEEDED,
                MMI_EVENT_PROPLEM);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_PAGE_NOT_FOUND: /* 57 */ /* Only Q05A */
        case WAP_BAM_ERROR_RECENT_PAGES_NOT_FOUND:   /* 80 */ /* Only Q05A */
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND:  /* 90 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_PAGE_NOT_FOUND,
                MMI_EVENT_PROPLEM);
            break;
        }

        case WAP_BAM_ERROR_RECENT_PAGES_FAILED: /* 91 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_REQUEST_FAILED,
                MMI_EVENT_PROPLEM);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_EXCEED_MAX_NUM_OF_INLINE_VDO:    /* 101 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_VIDEO_OBJS_EXCEED_MAX_LIMIT,
                MMI_EVENT_INFO);
            break;
        }
        case WAP_BAM_ERROR_CANNOT_PLAY_INLINE_VDO_IN_CALL:  /* 102 */ /* Only Q05A */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
                MMI_EVENT_FAILURE);
            break;
        }
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_GPRS_UNKNOWN_APN:    /* 110 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_GPRS_UNKNOWN_APN,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_GPRS_AUTHENTICATION_FAILURE: /* 111 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_GPRS_AUTHENTICATION_FAILURE,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_GPRS_UNSUPPORTED:    /* 112 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_GPRS_UNSUPPORTED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_GPRS_NOT_SUBSCRIBED: /* 113 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_GPRS_NOT_SUBSCRIBED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WAP_BAM_ERROR_CSD_AUTHENTICATION_FAILURE:  /* 114 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ERROR_CSD_AUTHENTICATION_FAILURE,
                MMI_EVENT_PROPLEM);
            break;
        }
    #ifdef OBIGO_Q03C_BROWSER
        case WAP_BAM_ERROR_UNSUPPORTED_SCRIPT_WARNING:  /* 114 */
        {
        #ifdef __GOOGLE_SEARCH_SUPPORT__
            if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_scripts_warning_disabled)
        #endif
            {
                mmi_brw_app_ui_draw_display_popup_ext(
                    STR_ID_BRW_UNSUPPORTED_SCRIPTS,
                    MMI_EVENT_FAILURE);
            #ifdef __GOOGLE_SEARCH_SUPPORT__
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_scripts_warning_disabled = MMI_TRUE;
            #endif
            }
            break;
        }
        case WAP_BAM_ERROR_REQUIRE_FRAMES:  /* 27 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_REQUIRES_FRAME_SUPPORT,
                MMI_EVENT_FAILURE);
            break;
        }
        case WAP_BAM_ERROR_NO_DISPLAY_CONTENT:  /* 134 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_NO_DISPLAY_CONTENT,
                MMI_EVENT_PROPLEM);
            break;
        }

    #endif /* OBIGO_Q03C_BROWSER */
        default:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_ERROR,
                MMI_EVENT_PROPLEM);
            break;
        }
    }
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_wps_error_handler
 * DESCRIPTION
 *  This func is used for displaying the error popup in relation to the error
 * code returned by the WPS
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_wps_error_handler(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_WPS_ERROR_HNDLR, error_code);

    switch (error_code)
    {
        case WPS_ERROR_INVALID_PARAM:   /* 3 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVALID_PARAM,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_INVALID_CHANNEL_ID:  /* 5 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVAL_CHANNEL_ID,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_INVALID_REQUEST_ID:  /* 6 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVAL_REQUEST_ID,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_INVALID_SEQUENCE_NUM:    /* 7 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVAL_SEQUENCE_NUM,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_ACCESS_DENY: /* 12 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_ACCESS_DENIED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_REQ_ABORT:   /* 15 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_REQUEST_ABORTED,
                MMI_EVENT_PROPLEM);
            break;
        }
        case WPS_ERROR_NOT_FOUND:   /* 16 */
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_NOT_FOUND,
                MMI_EVENT_PROPLEM);
            break;
        }
        default:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_ERROR,
                MMI_EVENT_PROPLEM);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_temp_busy_screen_active
 * DESCRIPTION
 *  This function is to check if the Browser temp busy screen is currently 
  * active or not(for WIDGET)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_temp_busy_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_TEMP_BUSY_SCREEN)
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
 *  mmi_brw_app_adjust_hide_highlight_menu_item
 * DESCRIPTION
 *  adjust the highlight and menu item.
 * PARAMETERS
 *  show_flag        [IN] : hide or unhide menu item
 *  child_item_id    [IN] : the child menu item
 *  parent_item_id   [IN] : the parent menu item
 *  gui_buffer       [IN] : the current gui buffer
 *  screen_id        [IN] :
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_adjust_hide_highlight_menu_item(MMI_BOOL show_flag, U16 child_item_id, U16 parent_item_id, U8* gui_buffer, U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    list_menu_category_history *h = (list_menu_category_history*)gui_buffer;
    U16 highlight_item_id = 0;
    S16 gui_hiliteitem = 0;
    S16 new_highlight_index;
    MMI_BOOL is_dynamic_data = MMI_FALSE;
    U16 total_number_of_child = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First entry main message menu */
    if (mmi_brw_app_is_screen_present(screen_id) == MMI_FALSE)
    {
        if (show_flag == MMI_TRUE)
        {
            mmi_frm_unhide_menu_item(child_item_id);
        }
        else
        {
            mmi_frm_hide_menu_item(child_item_id);
        }
        return;
    }

    /* Goback history to adjust the highlight and menu item */
    /* get the current highlight menu item id */
    if (gui_buffer != NULL)
    {
        gui_hiliteitem = h->highlighted_item;
        if (screen_id == SCR_ID_BRW_INTERNET_SERVICES)
        {
            total_number_of_child = GetNumOfChild_Ext(parent_item_id);
            if (gui_hiliteitem >= total_number_of_child)
            {
                is_dynamic_data = MMI_TRUE;
            }
            else
            {
                highlight_item_id = GetSeqItemId_Ext(parent_item_id, gui_hiliteitem);
            }
        }
        else
        {
            highlight_item_id = GetSeqItemId_Ext(parent_item_id, gui_hiliteitem);
        }
    }

    /* hide/unhide the menu item */
    if (show_flag == MMI_TRUE)
    {
        mmi_frm_unhide_menu_item(child_item_id);
    }
    else
    {
        mmi_frm_hide_menu_item(child_item_id);
    }

    /* reset the highlight index by current highlight menu item */
    if (gui_buffer != NULL)
    {
        if (is_dynamic_data)
        {
            if (total_number_of_child > GetNumOfChild_Ext(parent_item_id))
            {
                h->highlighted_item--;
            }
            else if (total_number_of_child < GetNumOfChild_Ext(parent_item_id))
            {
                h->highlighted_item++;
            }
        }
        else
        {
            new_highlight_index = GetIndexOfStringId_Ext(parent_item_id, highlight_item_id);

            if (new_highlight_index != gui_hiliteitem)
            {
                h->highlighted_item = new_highlight_index;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_hide_menu_item
 * DESCRIPTION
 *  This func is used for Hiding or unhiding the menu item passed as argument 
 * to it depending on the hide condition passed
 * PARAMETERS
 *  hide_cond        [IN]        
 *  menu_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_hide_menu_item(MMI_BOOL hide_cond, U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hide_cond == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(menu_id);
    }
    else
    {
        mmi_frm_unhide_menu_item(menu_id);
    }
}


#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_transferring_media_available
 * DESCRIPTION
 *  Function to make the string from a value
 * PARAMETERS
 *  void
 *  value(?)            [IN]        
 *  StringVal(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_is_transferring_media_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MMS_SUPPORT)
    if (mmi_brw_app_check_mms_is_ready())
    {
        return MMI_TRUE;
    }
#endif /* defined(MMS_SUPPORT) */ 

    if(!srv_sms_is_hide_send_sms_menu_item())
    {
        return MMI_TRUE;
    }


#if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_VBOOKMARK__)
    if (mmi_bt_is_to_display_bt_menu())
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_OPP_SUPPORT__) && defined(__MMI_VBOOKMARK__) */ 

#if defined (__MMI_EMAIL__)
    if (mmi_email_is_email_can_forward() == TRUE)
    {
        return MMI_TRUE;
    }
#endif

    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_close_download_and_exit
 * DESCRIPTION
 *  This function is called to suspend/close the downloading if going on and
 * then deinitialize the Browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_close_download_and_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if (g_srv_brw_cntx.download_info_p && g_srv_brw_cntx.download_info_p->active_job_count)
    {
        srv_brw_background_downloads_req(MMI_DA_WAP_NOTIFY_BROWSER_CLOSED);
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
    mmi_brw_app_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_rendered_page_present
 * DESCRIPTION
 *  This function is to check if the Browser rendered page screen has been 
 * displayed or not (means either active or in history)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_rendered_page_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BROWSER_MAIN || mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN) ||
		mmi_frm_scrn_get_active_id() == mmi_brw_app_get_splash_scr_id() || mmi_brw_app_is_screen_present(mmi_brw_app_get_splash_scr_id()))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_draw_ren_page_title
 * DESCRIPTION
 *  This function is called to check and draw wither the title or the page 
 * fetching status progress bar if the page fetching feature is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_draw_ren_page_title(void)
{
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 progress_str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
    {
        if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_FETCHING_STATUS_CONNECTING)
        {
            progress_str_id = STR_ID_BRW_CONNECTING;
        }
        else if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_FETCHING_STATUS_PROCESSING)
        {
            progress_str_id = STR_ID_BRW_PROCESSING;
        }
        else
        {
            progress_str_id = STR_ID_BRW_LOADING;
        }
        mmi_brw_app_ui_draw_ren_page_progressive_bar(
                        g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress,
                        (S8*) GetString(progress_str_id));
    }
    else
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */
    {
        if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
        {
            return;
        }
        draw_title();
    }
}
#endif /* OBIGO_Q03C_BROWSER */


#ifdef __MMI_URI_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_wap_uri_scheme_launch
 * DESCRIPTION
 *  This function is to launcht the URI scheme passed to the Browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_wap_uri_scheme_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN);
    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url, (WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*) g_brw_app_cntx.uha_info_p->url);
    mmi_brw_app_if_launch_url(g_brw_current_url);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_uri_agent_get_pb_result
 * DESCRIPTION
 *  Convert the Phone Book error into WAP error.
 * PARAMETERS
 *  res          [IN]
 * RETURNS
 *  Error code in WAP error.
 *****************************************************************************/
U16 mmi_brw_app_uri_agent_get_pb_result(S32 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res)
    {
        case MMI_PHB_URIAGENT_ERR_OK:
        {
            return WAP_BAM_WTAI_RESULT_OK;
        }
        case MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG:
        {
            return WAP_BAM_WTAI_RESULT_INVALID;
        }
        case MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG:
        {
            return WAP_BAM_WTAI_RESULT_PB_IN_NAME;
        }
        case MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG:
        {
            return WAP_BAM_WTAI_RESULT_PB_NUMBER_TO_LONG;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR:
        {
            return WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_ENTRY;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_IS_FULL:
        {
            return WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_IS_FULL;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_NOT_READY:
        case MMI_PHB_URIAGENT_ERR_PHB_PROCESS_USIM:
        case MMI_PHB_URIAGENT_ERR_PHB_IN_SYNC:
        case MMI_PHB_URIAGENT_ERR_FDN_ON_ERROR:
        default:
        {
            return WAP_BAM_WTAI_RESULT_UNSPECIFIED;
        }
    }
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_uri_agent_get_tel_result
 * DESCRIPTION
 *  Convert the UCM error into WAP error.
 * PARAMETERS
 *  res          [IN]
 * RETURNS
 *  Error code in WAP error.
 *****************************************************************************/
U16 mmi_brw_app_uri_agent_get_tel_result(S32 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res)
    {
        case MMI_UCM_RESULT_OK:
        {
            return WAP_BAM_WTAI_RESULT_OK;
        }
        case MMI_UCM_RESULT_INVALID_NUMBER:
        case MMI_UCM_RESULT_EMPTY_NUMBER:
        {
            return WAP_BAM_WTAI_RESULT_INVALID;
        }
        case MMI_UCM_RESULT_CALLED_PARTY_BUSY:
        {
            return WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_IS_BUSY;
        }
        case MMI_UCM_RESULT_NETWORK_NOT_AVAILABLE:
        {
            return WAP_BAM_WTAI_RESULT_TEL_NETWORK_NOT_AVAILABLE;
        }
        case MMI_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED:
        {
            return WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_NO_ANSWER;
        }
        case MMI_UCM_RESULT_NO_ACTIVE_VOICE_CALL:
        {
            return WAP_BAM_WTAI_RESULT_TEL_NO_ACTIVE_CONNECTION;
        }
        case MMI_UCM_RESULT_USER_ABORT:
        case MMI_UCM_RESULT_UCM_BUSY:
        case MMI_UCM_RESULT_CANCEL:
        case MMI_UCM_RESULT_FLIGHT_MODE_PROHIBIT:
        case MMI_UCM_RESULT_PREFERRED_MODE_PROHIBIT:
        case MMI_UCM_RESULT_SOS_CALL_EXISTS:
        case MMI_UCM_RESULT_SOS_NUMBER_ONLY:
        case MMI_UCM_RESULT_UNSPECIFIED_ERROR:
        default:
        {
            return WAP_BAM_WTAI_RESULT_UNSPECIFIED;
        }
    }
}
#endif /* __MMI_UCM__ */
#endif /* __MMI_URI_AGENT__ */

#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_browser_first_accessed_page
 * DESCRIPTION
 *  This function is to check if the opened renderd page is the first accessed
 * page.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_browser_first_accessed_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_brw_app_cntx.brw_dynamic_cntx_p->brw_first_page_flag;
}
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_sec_popup
 * DESCRIPTION
 *  Entry function for confirm callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_sec_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_popup(
            (U8*) GetString((U16) g_brw_app_cntx.sec_confirm_dlg_info_p->text_id),
            mmi_brw_app_convert_wps_dialog_type_to_mmi_event());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_convert_wps_dialog_type_to_mmi_event
 * DESCRIPTION
 *  This function is to map the dialog type sent by the WPS with the MMI events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_event_notify_enum mmi_brw_app_convert_wps_dialog_type_to_mmi_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_brw_app_cntx.sec_confirm_dlg_info_p->dialog_type)
    {
        case WPS_DLG_INFO:
        {
            event_id = MMI_EVENT_SUCCESS;
            break;
        }
        case WPS_DLG_ERROR:
        {
            event_id = MMI_EVENT_FAILURE;
            break;
        }
        default:
        {
            event_id = MMI_EVENT_ERROR;
            break;
        }
    }
    return event_id;
}

#endif /* WAP_SEC_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_pre_entry_goto_url
 * DESCRIPTION
 *  Pre Entry function for fetching url i.e when the user wants to fetch a page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_pre_entry_goto_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_brw_app_open_bearer();
    if(ret == CBM_WOULDBLOCK)
    {
        mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
        g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_URL;
        return;
    }
    else if (ret == CBM_OK)
    {
        mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
        mmi_brw_app_pre_entry_render_page();
    }
}


#ifdef OBIGO_Q05A 
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_pre_entry_open_file
 * DESCRIPTION
 *  This function is the pre Entry function for opening a selected wap file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_pre_entry_open_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_brw_app_open_bearer();
    if(ret == CBM_WOULDBLOCK)
    {
        mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
        g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_OPEN_FILE;
        return;
    }
    else if (ret == CBM_OK)
    {
        mmi_brw_srv_hdlr_load_data_req();
        mmi_brw_app_pre_entry_render_page();
    }
}
#endif /* OBIGO_Q05A */


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_url_as_homepage
 * DESCRIPTION
 *  This function is to store the URL to be set as homepage before displaying
 * the confirmation screen in a buffer
 * PARAMETERS
 *  url_p       [IN]        It is an ascii string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_url_as_homepage(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);
    memset(g_brw_current_url, 0, sizeof(g_brw_current_url));

    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) url_p);

    mmi_brw_app_set_url_as_homepage_ok();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_url_as_homepage_ok
 * DESCRIPTION
 *  This function is to call the service API to set a given url as homepage and
 * then display the error popup depending on the result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_url_as_homepage_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_error_enum error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = srv_brw_set_as_homepage(g_brw_current_url);
    if(error_code == SRV_BRW_ERROR_OK)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_brw_app_ui_draw_display_popup_ext(mmi_brw_app_get_error_string_id(error_code), MMI_EVENT_PROPLEM);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_error_string_id
 * DESCRIPTION
 *  This function is to get the error message string ID depending on the Browser
 * Service error code passed to it to be displayed in a popup message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_error_string_id(srv_brw_error_enum error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(error_code)
    {
        case SRV_BRW_ERROR_INVALID_URL:
        {
            return STR_GLOBAL_INVALID_URL;
            break;
        }
        default:
        {
            return STR_GLOBAL_ERROR;
            break;
        }
    }
}

#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_file_system_error_handler
 * DESCRIPTION
 *  This function is used to display error popup depending on the File System
 * error code received
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_file_system_error_handler(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_popup_ext(
        srv_fmgr_fs_error_get_string(error_code),
        MMI_EVENT_PROPLEM);
}
#endif /* __MMI_VBOOKMARK__ */


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_update_recent_page_sorting_method
 * DESCRIPTION
 *  This func is used for storing the sorting method if the previously selected
 *  and the newly selected sorting method are different
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_update_recent_page_sorting_method(U8 sorting_method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.sorting_method = sorting_method;

    srv_brw_update_settings_data(SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);                
    /* here it is used for highlighting the default menu item */
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_RECENT_PAGES);
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_RECENT_PAGES_HOST);
    mmi_brw_app_pre_entry_recent_page_list();
}
#endif /* OBIGO_Q05A */
#endif

#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_cache
 * DESCRIPTION
 *  This function is used for clearing the cache by notifying the service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_srv_hdlr_clear_data_req(WPS_CLEAR_CACHE_ALL);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_cookie
 * DESCRIPTION
 *  This function is used for clearing the cookie by notifying the service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_cookie(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_srv_hdlr_clear_data_req(WPS_CLEAR_COOKIES_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_auth
 * DESCRIPTION
 *  This function is used for clearing the authentication by notifying the 
 * service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_srv_hdlr_clear_data_req(WPS_CLEAR_AUTH_ALL);
}


#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_search_history
 * DESCRIPTION
 *  This function is used for clearing the authentication by notifying the 
 * service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_search_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_search_list_delete_all_items();
    mmi_brw_app_ui_draw_display_popup_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS);
}
#endif

#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_search_history
 * DESCRIPTION
 *  This function is used for clearing the authentication by notifying the 
 * service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_url_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_address_list_delete_all_items();
    mmi_brw_app_ui_draw_display_popup_ext(
        STR_GLOBAL_DONE, 
        MMI_EVENT_SUCCESS);
}
#endif

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_rendering_mode
 * DESCRIPTION
 *  This function is used for setting the rendering mode and sending the change
 * setting indication to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_rendering_mode(U8 rendering_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.rendering_mode != rendering_mode)
    {
        g_srv_brw_cntx.rendering_mode = rendering_mode;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_RENDER_MODE);
        srv_brw_change_setting_value_req(
            wap_bam_setting_value_type_int,
            wap_bam_setting_id_rendering,
            g_srv_brw_cntx.rendering_mode,
            NULL);
    }
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_navigation_mode
 * DESCRIPTION
 *  This function is used for setting the navigation mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_navigation_mode(U8 navigation_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.navigation_mode != navigation_mode)
    {
        g_srv_brw_cntx.navigation_mode = navigation_mode;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_NAVIGATE_MODE);
        srv_brw_change_setting_value_req(
            wap_bam_setting_value_type_int,
            wap_bam_setting_id_navigation,
            g_srv_brw_cntx.navigation_mode,
        NULL);
    }
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}


#ifdef __MMI_VECTOR_FONT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_font_size
 * DESCRIPTION
 *  This function is used for setting the font size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_font_size(U8 font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.font_size != font_size)
    {
        g_srv_brw_cntx.font_size = font_size;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_FONT_SIZE);
        srv_brw_change_setting_value_req(
            wap_bam_setting_value_type_int,
            wap_bam_setting_id_font_size,
            g_srv_brw_cntx.font_size,
            NULL);
    }
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
#endif /* OBIGO_Q05A */


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_check_available_bookmark_memory
 * DESCRIPTION
 *  This func is for checking the Available memory in Bookmarks
 *  memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_check_available_bookmark_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.bookmark_count == SRV_BRW_BKM_MAX_COUNT)
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_ID_BRW_NOT_ENOUGH_MEMORY,
            MMI_EVENT_PROPLEM);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_add_bookmark_confirm_GoBackHistory
 * DESCRIPTION
 *  This function is to delete the ADD bookmark screen when the user selects
 * No on the ADD Bookmark confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_add_bookmark_confirm_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_scrn_close_active_id(); 

}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_edit_bookmark_confirm_GoBackHistory
 * DESCRIPTION
 *  This function is to delete the EDIT bookmark screen when the user selects
 * No on the Edit Bookmark confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_edit_bookmark_confirm_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_scrn_close_active_id();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_handle_bookmark_error_code
 * DESCRIPTION
 *  This function is to delete the EDIT bookmark screen when the user selects
 * No on the Edit Bookmark confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_handle_bookmark_error_code(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(error_code)
    {
        case SRV_BRW_BKM_ERROR_OK:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_SAVED,
                MMI_EVENT_EXPLICITLY_SAVED);
            break;
        }

        case SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_NOT_ENOUGH_MEMORY,
                MMI_EVENT_PROPLEM);
            break;
        }

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SRV_BRW_BKM_ERROR_EMPTY_FOLDER_NAME:
    #endif
        case SRV_BRW_BKM_ERROR_EMPTY_FILE_NAME:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_PLEASE_INPUT_THE_FILENAME,
                MMI_EVENT_PROPLEM);
            break;
        }

        case SRV_BRW_BKM_ERROR_INVALID_TITLE:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_INVALID_TITLE,
                MMI_EVENT_PROPLEM);
            break;
        }

        case SRV_BRW_BKM_ERROR_INVALID_URL:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_INVALID_URL,
                MMI_EVENT_PROPLEM);
            break;
        }

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SRV_BRW_BKM_ERROR_FILE_PATH_LEN_EXCEEDED:
        case SRV_BRW_BKM_ERROR_DIR_PATH_TOO_DEEP:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_ID_BRW_DIR_PATH_TOO_DEEP,
                MMI_EVENT_PROPLEM);
            break;
        }
    #endif
        
        case SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS:
        {
        #ifdef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_FILE_ALREADY_EXISTS,
                MMI_EVENT_PROPLEM);
        #endif
            break;
        }

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SRV_BRW_BKM_ERROR_FOLDER_CREATED:
        {
            mmi_brw_app_ui_draw_display_popup_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS);
            break;
        }
    #endif

        default:
        {
            mmi_brw_app_file_system_error_handler(error_code);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_bookmarks_context_init
 * DESCRIPTION
 *  it initializes the global bookmark context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_bookmarks_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_cntx.sel_file_index = -1;
    g_brw_bkm_cntx.total_file_count = 0;
    memset(g_brw_bkm_cntx.sel_folder_name, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
    /*NOT NEEDED */
    mmi_ucs2cpy((S8*) g_brw_bkm_cntx.sel_file_name, (S8*) L"");
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_bookmark_items
 * DESCRIPTION
 *  This function is to get all the bookmark items index in the 
 * bookmark list passed to it corresponding to the currently
 * selected folder which is also passed to this function. 
 * The items stored in the bookmark list will not be in sorted order. 
 * PARAMETERS
 *  sel_folder_name [IN]    the name of the folder whose children
 *    bookmark items are to be stored in the bookmark list
 * bkm_list  [IN|OUT]      The bookmark list in which the indexes of 
 *   the selected items will be stored.
 * RETURNS
 *  the count of the no. of item found
 *****************************************************************************/
U8 mmi_brw_app_get_bookmark_items(U8* sel_folder_name, srv_brw_bkm_bookmark_list_struct* bkm_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 array_index = 0, index = 0, temp_array_count = 0;
    MMI_BOOL is_root_folder_list;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 selected_folder_index;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    selected_folder_index = srv_brw_bkm_get_parent_folder_index(sel_folder_name);
#endif
    for(index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
    {
        if(bkm_cntx_ptr[index].type != SRV_BRW_BKM_TYPE_EMPTY)
        {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[index].parent_index == selected_folder_index)
        #endif
            {
            #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                if(g_brw_app_cntx.brw_launching_pad_for_OHS == BRW_LPD_HOME_SCR_USER_DEFINED_BKM)
                {
                    if(bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
                    {
                        bkm_list[array_index].actual_index = index;
                        array_index++;
                        temp_array_count++;
                    }
                }
                else
            #endif
                {
                    bkm_list[array_index].actual_index = index;
                    array_index++;
                    temp_array_count++;
                }
            }
        }
    }
    return temp_array_count;
}
#endif

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_select_bookmark_list
 * DESCRIPTION
 *  This function is to create a list of the bookmark items that are
 * to be displayed in the Select Bookmark screen in sorted order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_create_select_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_count = 0;
    MMI_BOOL is_root_folder_list = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_root_folder_list = (g_brw_bkm_sel_bkm_cntx.sel_folder_name[0] == 0);
    total_count = mmi_brw_app_get_bookmark_items(g_brw_bkm_sel_bkm_cntx.sel_folder_name, g_brw_bkm_sel_bkm_cntx.bookmark_list);
    if(total_count > 0)
    {
        if(is_root_folder_list)
        {
            srv_brw_bkm_arrange_bookmark_list_in_order(g_brw_bkm_sel_bkm_cntx.bookmark_list, total_count);
        }
        else
        {
            srv_brw_bookmark_sort_bookmark_list(g_brw_bkm_sel_bkm_cntx.bookmark_list, 0, total_count - 1);
        }
    }
    g_brw_bkm_sel_bkm_cntx.total_file_count = total_count;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_bookmark_list
 * DESCRIPTION
 *  This function is to create a list of the bookmark items that are
 * to be displayed in the Bookmark list screen in sorting order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_create_bookmark_list(void)
{
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_count = 0;
    MMI_BOOL is_root_folder_list = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_root_folder_list = (g_brw_bkm_cntx.sel_folder_name[0] == 0);
    total_count = mmi_brw_app_get_bookmark_items(g_brw_bkm_cntx.sel_folder_name, g_brw_bkm_cntx.bookmark_list);
    if(total_count > 0)
    {
        if(is_root_folder_list)
        {
            srv_brw_bkm_arrange_bookmark_list_in_order(g_brw_bkm_cntx.bookmark_list, total_count);
        }
        else
        {
            srv_brw_bookmark_sort_bookmark_list(g_brw_bkm_cntx.bookmark_list, 0, total_count - 1);
        }
    }
    g_brw_bkm_cntx.total_file_count = total_count;
#else
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 index;
    g_brw_bkm_cntx.total_file_count = 0;
    for(index = 0; index< SRV_BRW_BKM_MAX_COUNT;index++)
    {
        if(bkm_cntx_ptr[index].type != SRV_BRW_BKM_TYPE_EMPTY)
        {
            g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.total_file_count++].actual_index = index;
        }
    }
#endif
}

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_bookmark_folder_items
 * DESCRIPTION
 *  This function is to get the bookmark folders index in the 
 * bookmark list passed to it that are present in the root folder
 * The items stored in the bookmark list will not be in sorted order. 
 * PARAMETERS
 * bkm_list  [IN|OUT]      The bookmark list in which the indexes of 
 *   the selected bookmark folder items will be stored.
 * RETURNS
 *  the count of the no. of item found
 *****************************************************************************/
U8 mmi_brw_app_get_bookmark_folder_items(srv_brw_bkm_bookmark_list_struct* bkm_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 array_index = 0, index = 0, temp_array_count = 0;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);
    for(index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
    {
        if(bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_FOLDER)
        {
                bkm_list[array_index].actual_index = index;
                array_index++;
                temp_array_count++;
        }
    }
    return temp_array_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_bookmark_folders_list
 * DESCRIPTION
 *  This function is to create a list of the bookmark folders that are
 * to be displayed in the Browse path list screen in sorting order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_create_bookmark_folders_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_count = mmi_brw_app_get_bookmark_folder_items(g_brw_bkm_cntx.bkm_dynamic_cntx->bookmark_list);
    if(total_count > 0)
    {
        srv_brw_bookmark_sort_bookmark_list(g_brw_bkm_cntx.bookmark_list, 0, total_count - 1);
    }
    g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count = total_count;
}
#endif


#endif /* __MMI_VBOOKMARK__ */


/****************************************RENDERED PAGE START**************************/
#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_status_icon
 * DESCRIPTION
 *  This func is used for showing or hiding the given status icon
 * PARAMETERS
 *  show_icon       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_status_icon(MMI_BOOL show_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }

    if (show_icon)
    {
        wgui_title_change(0, IMG_ID_BRW_SECURE_ICON, NULL, WGUI_TITLE_CHANGE_ICON2);
    }
    else
    {
        wgui_title_change(0, 0, NULL, WGUI_TITLE_CHANGE_ICON2);
    }
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_TOTAL_FETCHING_STATUS)
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */
    {
        draw_title();
    }
}
#endif /* WAP_SEC_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_ren_page_title_string
 * DESCRIPTION
 *  This function is used for setting the title string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_ren_page_title_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }

    wgui_title_change(0, 0, mmi_brw_app_get_ren_page_title_string(), WGUI_TITLE_CHANGE_TEXT);
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_ren_page_title_string
 * DESCRIPTION
 *  This function is used for getting the title string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_brw_app_get_ren_page_title_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        if (strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title) > 0)
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*) g_brw_current_title,
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
                (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
        }
        else
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*) g_brw_current_title,
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
                (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) g_brw_current_title, GetString(STR_ID_BRW_INTERNET_SERVICES));
    }
    return (U8*) g_brw_current_title;
}

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_ren_page_title_icon
 * DESCRIPTION
 *  This function is used for setting the title icon of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_ren_page_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
    if (!g_brw_app_cntx.brw_dynamic_cntx_p->is_bearer_active)
    {
        mmi_brw_app_show_root_title_icon();
    }
    /* check page fetching status */
    else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
    {
        mmi_brw_app_show_animated_title_icon();
    }
    else    /* page already fetched or browser in waiting state*/
    {
        mmi_brw_app_show_non_animated_title_icon();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_ren_page_title_icon
 * DESCRIPTION
 *  This function is used for getting the title icon ID of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_ren_page_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Image_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check page fetching status */
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
    {
        Image_id = mmi_brw_app_get_animated_title_icon();
    }
    else    /* page already fetched */
    {
        Image_id = mmi_brw_app_get_non_animated_title_icon();
    }
    return Image_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_root_title_icon
 * DESCRIPTION
 *  Function to display the root title icon in case the bearer is not active 
 *  or it has been released due to some reason
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_root_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(mmi_brw_get_wap_icon(), 0, NULL, WGUI_TITLE_CHANGE_ICON);
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_animated_title_icon
 * DESCRIPTION
 *  This function is used for displaying the animated title icon on rendered
 * page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(mmi_brw_app_get_animated_title_icon(), 0, NULL, WGUI_TITLE_CHANGE_ICON);
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_non_animated_title_icon
 * DESCRIPTION
 *  This function is used for displaying the non-animated title icon on the
 * rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_non_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(mmi_brw_app_get_non_animated_title_icon(), 0, NULL, WGUI_TITLE_CHANGE_ICON);
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_animated_title_icon
 * DESCRIPTION
 *  This function returns the animated title icon to be used depending on the
 *  current bearer type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 bearer_type;
    U16 title_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_brw_get_bearer_type(&bearer_type);
    if (!g_brw_app_cntx.brw_dynamic_cntx_p->is_bearer_active)
    {
        title_icon = mmi_brw_get_wap_icon();
    }
#ifdef __TCPIP_OVER_CSD__
    else if (bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        title_icon = mmi_brw_app_get_animated_bearer_icon();
    }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __PS_SERVICE__
    else if (bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        title_icon = mmi_brw_app_get_animated_bearer_icon();
    }
#endif /* __PS_SERVICE__ */
#ifdef __MMI_WLAN_FEATURES__
    else if (bearer_type == SRV_DTCNT_BEARER_WIFI)
    {
        title_icon = mmi_brw_app_get_animated_wifi_icon();
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else
    {
        title_icon = mmi_brw_get_wap_icon();
    }
    return (title_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_non_animated_title_icon
 * DESCRIPTION
 *  This function returns the non animated title icon to be used depending on the
 *  current bearer type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_non_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 bearer_type;
    U16 title_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_get_bearer_type(&bearer_type);
    if (!g_brw_app_cntx.brw_dynamic_cntx_p->is_bearer_active)
    {
        title_icon = mmi_brw_get_wap_icon();
    }
#ifdef __TCPIP_OVER_CSD__
    else if (bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        title_icon = mmi_brw_app_get_non_animated_bearer_icon();
    }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __PS_SERVICE__
    else if (bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        title_icon = mmi_brw_app_get_non_animated_bearer_icon();
    }
#endif /* __PS_SERVICE__ */
#ifdef __MMI_WLAN_FEATURES__
    else if (bearer_type == SRV_DTCNT_BEARER_WIFI)
    {
        title_icon = mmi_brw_app_get_non_animated_wifi_icon();
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else
    {
        title_icon = mmi_brw_get_wap_icon();
    }

    return (title_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_animated_bearer_icon
 * DESCRIPTION
 *  This function is get the animated bearer icon for both the 
 * GPRS and CSD case.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_animated_bearer_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef SLIM_WAP_MMS
    return IMG_ID_BRW_WAP_CONNECTING;
#else /* SLIM_WAP_MMS */
    switch (g_srv_brw_cntx.session_sim_id)
    {
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM1:
        {
            return IMG_ID_BRW_WAP_SIM1_CONNECTING;
        }

        case SRV_BRW_ACTIVE_SIM_SETTING_SIM2:
        {
            return IMG_ID_BRW_WAP_SIM2_CONNECTING;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM3:
        {
            return IMG_ID_BRW_WAP_SIM3_CONNECTING;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM4:
        {
            return IMG_ID_BRW_WAP_SIM4_CONNECTING;
        }
    #endif
        default:
        {
            return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
        }
    }
#endif /* SLIM_WAP_MMS */
#else
    return IMG_ID_BRW_WAP_CONNECTING;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_non_animated_bearer_icon
 * DESCRIPTION
 *  This function is get the non animated bearer icon for both the 
 * GPRS and CSD case.
 * setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_non_animated_bearer_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef SLIM_WAP_MMS
    return IMG_ID_BRW_WAP_CONNECTED;
#else /* SLIM_WAP_MMS */
    switch (g_srv_brw_cntx.session_sim_id)
    {
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM1:
        {
            return IMG_ID_BRW_WAP_SIM1_CONNECTED;
        }

        case SRV_BRW_ACTIVE_SIM_SETTING_SIM2:
        {
            return IMG_ID_BRW_WAP_SIM2_CONNECTED;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM3:
        {
            return IMG_ID_BRW_WAP_SIM3_CONNECTED;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM4:
        {
            return IMG_ID_BRW_WAP_SIM4_CONNECTED;
        }
    #endif
        default:
        {
            return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
        }
    }
#endif /* SLIM_WAP_MMS */
#else
    return IMG_ID_BRW_WAP_CONNECTED;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_animated_wifi_icon
 * DESCRIPTION
 *  This function is get the animated WIFI icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_animated_wifi_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SLIM_WAP_MMS
#ifdef __MMI_SLIM_IMG_RES__
    return IMG_ID_BRW_WAP_CONNECTING;
#else /* __MMI_SLIM_IMG_RES__ */
    return IMG_ID_BRW_CONNECTION_STATUS_WIFI;
#endif /* __MMI_SLIM_IMG_RES__ */
#else /* SLIM_WAP_MMS */
    return IMG_ID_BRW_CONNECTION_STATUS_WIFI;
#endif /* SLIM_WAP_MMS */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_non_animated_wifi_icon
 * DESCRIPTION
 *  This function is get the animated WIFI icon 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_non_animated_wifi_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SLIM_WAP_MMS
#ifdef __MMI_SLIM_IMG_RES__
    return IMG_ID_BRW_WAP_CONNECTED;
#else /* __MMI_SLIM_IMG_RES__ */
    return IMG_ID_BRW_CONNECTION_STATUS_WIFI_STATIC;
#endif /* __MMI_SLIM_IMG_RES__ */
#else /* SLIM_WAP_MMS */
    return IMG_ID_BRW_CONNECTION_STATUS_WIFI_STATIC;
#endif /* SLIM_WAP_MMS */
}
#endif /* __MMI_WLAN_FEATURES__ */

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_wap_icon
 * DESCRIPTION
 *  This function is get the WAP icon depending on the selected SIM setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_get_wap_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef SLIM_WAP_MMS
    return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
#else /* SLIM_WAP_MMS */
    switch (g_srv_brw_cntx.session_sim_id)
    {
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM1:
        {
            return IMG_ID_BRW_WAP_SIM1;
        }

        case SRV_BRW_ACTIVE_SIM_SETTING_SIM2:
        {
            return IMG_ID_BRW_WAP_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM3:
        {
            return IMG_ID_BRW_WAP_SIM3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM4:
        {
            return IMG_ID_BRW_WAP_SIM4;
        }
    #endif

        default:
        {
            return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
        }
    }
#endif /* SLIM_WAP_MMS */
#else
    return GetRootTitleIcon(SERVICES_WAP_MENU_ID);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#else /* __MMI_TITLE_BAR_NO_ICON_SHCT__ */
    return 0;
#endif /* __MMI_TITLE_BAR_NO_ICON_SHCT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ren_page_set_LSK
 * DESCRIPTION
 *  This function is used for setting the LSK string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ren_page_set_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN) && (mmi_frm_scrn_get_active_id() != mmi_brw_app_get_splash_scr_id()))
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_SET_LSK,
        mmi_frm_scrn_get_active_id(),
        g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting,
        g_srv_brw_cntx.screen_size_status,
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        mmi_brw_app_is_browser_first_accessed_page(),
    #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        2,
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p);


    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching || g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting)
    {
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
    #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        if (g_srv_brw_cntx.screen_size_status)
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        {
            set_left_softkey_label(L"");
            SetKeyUpHandler(NULL, KEY_LSK);
        }
        else    /* if screen is normal, we will redraw the softkey */
        {
			ChangeLeftSoftkey(0, 0);
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);

        }
    }
    else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
    #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        if (g_srv_brw_cntx.screen_size_status)
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        {
            set_left_softkey_label(L"");
            SetKeyUpHandler(mmi_brw_app_if_show_rendered_page_options_menu, KEY_LSK);
        }
        else    /* if screen is normal, we will redraw the softkey */
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetLeftSoftkeyFunction(mmi_brw_app_if_show_rendered_page_options_menu, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ren_page_set_RSK
 * DESCRIPTION
 *  This function is used for setting the RSK string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ren_page_set_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN) && (mmi_frm_scrn_get_active_id() != mmi_brw_app_get_splash_scr_id()))
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_SET_RSK,
        mmi_frm_scrn_get_active_id(),
        g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag,
        g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting,
        g_srv_brw_cntx.screen_size_status,
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        mmi_brw_app_is_browser_first_accessed_page(),
    #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        2,
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p,
        srv_brw_is_backward_navigation());

    if (g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag)
    {
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
    #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        if (g_srv_brw_cntx.screen_size_status)
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        {
            set_right_softkey_label(L"");
            SetKeyUpHandler(mmi_brw_app_ren_page_select_mode_rsk_exit, KEY_RSK);
        }
        else    /* if screen is normal, we will redraw the softkey */
        {
            ChangeRightSoftkey(STR_GLOBAL_EXIT, 0);
            SetRightSoftkeyFunction(mmi_brw_app_ren_page_select_mode_rsk_exit, KEY_EVENT_UP);
        }
    }
    else
    {
        if (g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting)
        {
        #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
            if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
        #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            if (g_srv_brw_cntx.screen_size_status)
        #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            {
                set_right_softkey_label(L"");
                SetKeyUpHandler(mmi_brw_app_pre_exit_ren_page, KEY_RSK);
            }
            else    /* if screen is normal, we will redraw the softkey */
            {
                ChangeRightSoftkey(STR_GLOBAL_EXIT, 0);
                SetRightSoftkeyFunction(mmi_brw_app_pre_exit_ren_page, KEY_EVENT_UP);
            }
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching || !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
        {
            if (g_srv_brw_cntx.screen_size_status)     /* if screen is full, we won't redraw the softkey */
            {
                set_right_softkey_label(L"");
                SetKeyUpHandler(mmi_brw_app_stop_ren_page_fetching, KEY_RSK);
            }
            else    /* if screen is normal, we will redraw the softkey */
            {
                ChangeRightSoftkey(STR_GLOBAL_CANCEL, 0);
                SetRightSoftkeyFunction(mmi_brw_app_stop_ren_page_fetching, KEY_EVENT_UP);
            }
        }
        else if (srv_brw_is_backward_navigation())
        {
        #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
            if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
        #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            if (g_srv_brw_cntx.screen_size_status)
        #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            {
                set_right_softkey_label(L"");
                SetKeyUpHandler(mmi_brw_app_backward_navigation, KEY_RSK);
            }
            else    /* if screen is normal, we will redraw the softkey */
            {
                ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
                SetRightSoftkeyFunction(mmi_brw_app_backward_navigation, KEY_EVENT_UP);
            }
        }
        else
        {
        #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
            if (g_srv_brw_cntx.screen_size_status && !mmi_brw_app_is_browser_first_accessed_page())/* if screen is full, we won't redraw the softkey */
        #else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            if (g_srv_brw_cntx.screen_size_status)
        #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            {
                set_right_softkey_label(L"");
                SetKeyUpHandler(mmi_brw_app_pre_exit_ren_page, KEY_RSK);
            }
            else    /* if screen is normal, we will redraw the softkey */
            {
                ChangeRightSoftkey(STR_GLOBAL_EXIT, 0);
                SetRightSoftkeyFunction(mmi_brw_app_pre_exit_ren_page, KEY_EVENT_UP);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ren_page_select_mode_rsk_exit
 * DESCRIPTION
 *  This function to used for sending the request to exit from the select mode
 *  if RSK is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ren_page_select_mode_rsk_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag = FALSE;
#ifdef OBIGO_Q03C_BROWSER
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p)
    {
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p, 0, sizeof(srv_brw_element_focused_ind_struct));
    }
#endif /* OBIGO_Q03C_BROWSER */
    srv_brw_navigation_change_req((U16)WAP_BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE);
    mmi_brw_app_ren_page_set_RSK();
#ifdef __MMI_FTE_SUPPORT__
    mmi_brw_app_change_ren_page_FTE_toolbar_state();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_stop_ren_page_fetching
 * DESCRIPTION
 *  This function is used for stopping the page fetching process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_stop_ren_page_fetching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN);
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SHOW_AUTH_DIALOG);
    srv_brw_stop_page_fetching_req();
#ifdef OBIGO_Q03C_BROWSER
    SetRightSoftkeyFunction(NULL,KEY_EVENT_UP);
#endif /* #ifdef OBIGO_Q03C_BROWSER */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_pre_exit_ren_page
 * DESCRIPTION
 *  This function is used for checking pre-conditions before exiting from
 *  browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_pre_exit_ren_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
    mmi_rmgr_unlock_session_callback();
#endif /* __MMI_RMGR_SEAMLESS_UNLOCK__ */

#ifdef __MMI_BRW_POST_SESSION_INFO__
    if (g_srv_brw_cntx.post_session_info_status && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time)
    {
        mmi_brw_app_dmgr_pre_entry_post_session_info();
        mmi_brw_app_deinit();
    }
    else
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
    {
        mmi_brw_app_exit();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_backward_navigation
 * DESCRIPTION
 *  This function sends the request for opening the previous page if user press
 *  RSK back from rendered page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_backward_navigation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_navigate_req(WAP_BAM_MOVE_BACKWARD);
#ifdef OBIGO_Q03C_BROWSER
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
#endif /* #ifdef OBIGO_Q03C_BROWSER */
}


#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_display_bkgrd_downloads_list
 * DESCRIPTION
 *  This function is used to notify the Browser service to send ind to DLAgent
 * to display the background downloads list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_display_bkgrd_downloads_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_background_downloads_req(MMI_DA_WAP_NOTIFY_DISPLAY_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_suspend_bkgrd_downloads
 * DESCRIPTION
 *  This function is used to suspend the background downloads and then exit from
 *  the browser application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_suspend_bkgrd_downloads(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_background_downloads_req(MMI_DA_WAP_NOTIFY_BROWSER_CLOSED);

#ifdef __MMI_BRW_POST_SESSION_INFO__
    if (g_srv_brw_cntx.post_session_info_status && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time)
    {
        mmi_brw_app_dmgr_pre_entry_post_session_info();
        mmi_brw_app_deinit();
    }
    else
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
    {
        mmi_brw_app_exit();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_continue_bkgrd_downloads
 * DESCRIPTION
 *  This function is used to display the background downloads list and postpone
 *  the browser termination
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_continue_bkgrd_downloads(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_background_downloads_req(MMI_DA_WAP_NOTIFY_DISPLAY_LIST);
    mmi_frm_scrn_close_active_id();
}
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */


#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_update_fetching_progress
 * DESCRIPTION
 *  This function is used to update the status of the page fetching progress
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_update_fetching_progress(void)
{
    if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_FETCHING_STATUS_CONNECTING)
    {
        if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress < BRW_PAGE_CONNECTING_LIMIT)
        {
            if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress + BRW_PAGE_INCREMENTATION < BRW_PAGE_CONNECTING_LIMIT)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress += BRW_PAGE_INCREMENTATION;
            }
            else
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status = BRW_FETCHING_STATUS_PROCESSING;
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress = BRW_PAGE_CONNECTING_LIMIT;
            }
            mmi_brw_app_ui_draw_ren_page_progressive_bar(
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress,
                (S8*) GetString(STR_ID_BRW_CONNECTING));
        }
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_FETCHING_STATUS_PROCESSING)
    {
        if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress < BRW_PAGE_PROCESSING_LIMIT)
        {
            if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress + BRW_PAGE_INCREMENTATION < BRW_PAGE_PROCESSING_LIMIT)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress += BRW_PAGE_INCREMENTATION;
            }
            else
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress = BRW_PAGE_PROCESSING_LIMIT;
            }
            mmi_brw_app_ui_draw_ren_page_progressive_bar(
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress,
                (S8*) GetString(STR_ID_BRW_PROCESSING));
        }
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status == BRW_FETCHING_STATUS_LOADING)
    {
        if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress < BRW_PAGE_LOADING_LIMIT)
        {
            if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress < BRW_PAGE_PROCESSING_LIMIT)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress = BRW_PAGE_PROCESSING_LIMIT;
            }
            else if (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress + BRW_PAGE_INCREMENTATION < BRW_PAGE_LOADING_LIMIT)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress += BRW_PAGE_INCREMENTATION;
            }
            mmi_brw_app_ui_draw_ren_page_progressive_bar(
                g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress,
                (S8*) GetString(STR_ID_BRW_LOADING));
        }
    }
}
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_show_upload_progress
 * DESCRIPTION
 *  Pre-entry function for showing the Upload progress screen if not already present
 *  or update the Upload status if progress screen is present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_show_upload_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id;
    MMI_BOOL is_upload_scr_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_UPLOAD_PROGRESS,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total);

    active_scr_id = mmi_frm_scrn_get_active_id();
    is_upload_scr_present = mmi_brw_app_is_screen_present(SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN);
    /* If the Upload progress screen has not been displayed to the user i.e. 
       the upload progress screen is being displayed for the first time */
    if (active_scr_id != SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN && !is_upload_scr_present)
    {
        /* Stop the server connection and the loding time check timer */
        mmi_brw_app_stop_server_connection_timer();
    #ifdef __MMI_BRW_LOADING_TIME_CHECKING__
        StopTimer(BRW_LOADING_TIME_CHECK_TIMER);
    #endif 
    #ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
        g_brw_app_cntx.brw_dynamic_cntx_p->is_page_size_checked = MMI_TRUE;
    #endif 
    #if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
        mmi_brw_app_remove_loading_size_time_screens();
    #endif 
    }
    /* If browser Upload progress screen is active and the bytes
       sent are less than bytes total then call the update status function */
    if (active_scr_id == SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN &&
        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total))
    {
        mmi_brw_app_ui_draw_update_upload_status();
    }
    /* If browser screen is active and the upload progress screen is 
       not present in the history then display the upload progress screen */
    else if (!is_upload_scr_present)
    {
        mmi_brw_app_if_show_upload_progress_screen();
        if(active_scr_id == SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN)
        {
            mmi_brw_app_if_show_browser_dummy_screen();
            mmi_frm_scrn_close_active_id();
        }
    }
    /* if the uploading has completed and the upload progress screen was in
       history so upload complete flag could not be set so check if the 
       upload cancel confirmation screen is active then remove it and set
       the upload complete flag */
    if ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent >=
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total) && g_brw_app_cntx.brw_dynamic_cntx_p->upload_status == BRW_UPLOAD_STATUS_UPLOADING)
    {
        if (active_scr_id == SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN)
        {
            mmi_frm_scrn_close_active_id();
        }
        g_brw_app_cntx.brw_dynamic_cntx_p->upload_status = BRW_UPLOAD_STATUS_COMPLETE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_format_size_total
 * DESCRIPTION
 *  Function for formatting and combining the bytes_sent and bytes_total string
 * PARAMETERS
 *  bytes_sent      [IN]        
 *  bytes_total     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_format_size_total(U32 bytes_sent, U32 bytes_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_util_format_size(bytes_sent, (S8*) subMenuData[0]);
    strcpy((S8*) subMenuData[1], (S8*) subMenuData[0]);
    if (bytes_total)
    {
        ptr = (S8*) subMenuData[1] + strlen((S8*) subMenuData[1]);
        ptr[0] = (S8) '/';
        ptr++;
        mmi_brw_app_util_format_size(bytes_total, (S8*) subMenuData[0]);
        strcpy((S8*) ptr, (S8*) subMenuData[0]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_remove_upload_screens
 * DESCRIPTION
 *  Function to remove the uploading screens if they are present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_remove_upload_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the Upload cancel confirmation screen is on top */
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN)
    {
        mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN);
        mmi_frm_scrn_close_active_id();
    }
    /* if upload progress screen is active then Go back to render page screen */
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN)
    {
        mmi_frm_scrn_close_active_id();
    }
    /* Otherwise remove upload progress screen from history if it is present */
    else
    {
        mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN);
    }
}
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_util_format_size
 * DESCRIPTION
 *  Function for formatting the bytes_sent and bytes_total string
 * PARAMETERS
 *  size        [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_util_format_size(U64 size, S8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MAIN_LCD_DEVICE_WIDTH > 128)
#define BRW_DISPLAY_UNIT 1024
#else 
#define BRW_DISPLAY_UNIT 1000
#endif 
    S8 unit;
    U16 remain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size >= BRW_DISPLAY_UNIT * 1024 * 1024)
    {
        size = size / (1024 * 1024);
        unit = 'G';
    }
    else if (size >= BRW_DISPLAY_UNIT * 1024)
    {
        size = size / 1024;
        unit = 'M';
    }
    else if (size >= BRW_DISPLAY_UNIT)
    {
        unit = 'K';
    }
    else
        unit = 'B';

    if (size >= BRW_DISPLAY_UNIT)
    {
        remain = (U16) ((size % 1024) / 103);
        size = size / 1024;
    }
    else
        remain = 0;

#if (MAIN_LCD_DEVICE_WIDTH > 128)
    if (remain)
#else 
    if (remain && size < 100)   /* 128 width, size is limited to 3 or 2.1digits */
#endif 
    {
        sprintf((S8*) buffer, "%d.%d%c", (U16) size, (U16) remain, unit);
    }
    else
    {
        sprintf((S8*) buffer, "%d%c", (U16) size, unit);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_stop_server_connection_timer
 * DESCRIPTION
 *  This function is to stop the server connection timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_stop_server_connection_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_STOP_SERVER_CONN_TIMER, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching);

        StopTimer(BRW_SERVER_CONNECTION_TIMER);
    }
}


#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_stop_splash_screen_timer
 * DESCRIPTION
 *  This function is to stop the splash screen timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_stop_splash_screen_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_SPLASH_SCR_STOP_TIMER, g_brw_app_cntx.brw_dynamic_cntx_p->brw_first_page_flag);
        if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_first_page_flag)
        {
            g_brw_app_cntx.brw_dynamic_cntx_p->brw_first_page_flag = MMI_FALSE;
            StopTimer(BRW_SPLASH_SCREEN_TIMER);
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_SPLASH_SCREEN)
            {
                mmi_brw_app_pre_entry_render_page();
                mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SPLASH_SCREEN);        
            }
            else
            {
                mmi_frm_node_struct new_node;
                new_node.id = SCR_ID_BRW_BROWSER_MAIN;
                new_node.entry_proc = (mmi_proc_func)mmi_brw_app_if_show_rendered_page_screen;
                new_node.user_data = NULL;
                mmi_frm_scrn_replace(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_SPLASH_SCREEN, &new_node);
                scrDB = (mmi_brw_app_screenDB_struct*)mmi_brw_app_scrhdlr_get_screenDB(SCR_ID_BRW_SPLASH_SCREEN);
                if(scrDB->screen)
                {
                    srv_brw_free(scrDB->screen);
                    scrDB->screen = NULL;
                }
            }
        }
    }
}
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */


#if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_remove_loading_size_time_screens
 * DESCRIPTION
 *  Function to remove the loading time and size check screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_remove_loading_size_time_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_LOADING_TIME_CHECK);
    mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_PAGE_SIZE_CHECK);
}
#endif /* defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__) */ 


#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_page_size_checking
 * DESCRIPTION
 *  Pre-entry function for page size checking
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_page_size_checking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_if_show_page_size_check_screen();
}
#endif /* __MMI_BRW_PAGE_SIZE_CHECKING__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_send_auth_dlg_ok_rsp
 * DESCRIPTION
 *  This function is to send the authentication information provided by the 
 * user to the service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_send_auth_dlg_ok_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    switch (g_brw_auth_dlg_save_option)
    {
        case BRW_APP_AUTH_DLG_SAVE_BOTH_INDEX:
        {
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD, g_brw_auth_username, g_brw_auth_password);
            break;
        }
        case BRW_APP_AUTH_DLG_SAVE_USERNAME_INDEX:
        {
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME, g_brw_auth_username, g_brw_auth_password);
            break;
        }
        case BRW_APP_AUTH_DLG_SAVE_NONE_INDEX:
        default:
        {
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_NOTHING, g_brw_auth_username, g_brw_auth_password);
            break;
        }
    }
#else /* OBIGO_Q05A */
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD, g_brw_auth_username, g_brw_auth_password);
#endif /* OBIGO_Q05A */
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_group_close(g_brw_app_cntx.brw_inline_cui_gid);
#ifdef OBIGO_Q03C
    //mmi_frm_scrn_close_active_id();
#endif /* OBIGO_Q03C */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_send_auth_dlg_cancel_rsp
 * DESCRIPTION
 *  This function sends the 'cancel' user response for the auth dialog to the
 * service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_send_auth_dlg_cancel_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_CANCEL, g_brw_auth_username, g_brw_auth_password);
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_group_close(g_brw_app_cntx.brw_inline_cui_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_send_auth_dlg_cancel_rsp
 * DESCRIPTION
 *  This function sends the 'cancel' user response for the auth dialog to the
 * service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_send_auth_dlg_confirm_cancel_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_send_auth_dlg_cancel_rsp();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_handler
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  enable_positive_sk      [IN]        
 *  positive_label          [IN]        
 *  positive_label_len      [IN]        
 *  enable_negative_sk      [IN]        
 *  negative_label          [IN]        
 *  negative_label_len      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_handler(
        int enable_positive_sk,
        const char *positive_label,
        int positive_label_len,
        int enable_negative_sk,
        const char *negative_label,
        int negative_label_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
    mmi_rmgr_unlock_session_callback();
#endif 

    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }

    /* stop server connection response timer */
    mmi_brw_app_stop_server_connection_timer();
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    if (mmi_brw_app_is_browser_first_accessed_page())
    {
        mmi_brw_app_stop_splash_screen_timer();
        mmi_brw_app_pre_entry_render_page();
    }
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

    if (enable_positive_sk)
    {
        if (!g_srv_brw_cntx.screen_size_status)
        {
            MMI_ASSERT(positive_label);
            mmi_chset_utf8_to_ucs2_string(
                (U8*) subMenuDataPtrs[0],
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
                (U8*) positive_label);
            ChangeLeftSoftkeyByString((UI_string_type) subMenuDataPtrs[0], 0);
            SetLeftSoftkeyFunction(mmi_brw_wait_user_action_positive_key_hdlr, KEY_EVENT_UP);
        }
        else
        {
            SetKeyUpHandler(mmi_brw_wait_user_action_positive_key_hdlr, KEY_LSK);
        }
    }
    else
    {
        if (g_srv_brw_cntx.screen_size_status)
        {
            set_left_softkey_label(L"");
            SetKeyUpHandler(NULL, KEY_LSK);
        }
        else
        {
            ChangeLeftSoftkey(0, 0);
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        }
    }

    if (enable_negative_sk)
    {
        if (!g_srv_brw_cntx.screen_size_status)
        {
            MMI_ASSERT(negative_label);
            mmi_chset_utf8_to_ucs2_string(
                (U8*) subMenuDataPtrs[1],
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
                (U8*) negative_label);
            ChangeRightSoftkeyByString((UI_string_type) subMenuDataPtrs[1], 0);
            SetRightSoftkeyFunction(mmi_brw_wait_user_action_negative_key_hdlr, KEY_EVENT_UP);
        }
        else
        {
            SetKeyUpHandler(mmi_brw_wait_user_action_negative_key_hdlr, KEY_RSK);
        }
    }
    else
    {
        if (g_srv_brw_cntx.screen_size_status)
        {
            set_right_softkey_label(L"");
            SetKeyUpHandler(NULL, KEY_RSK);
        }
        else
        {
            ChangeRightSoftkey(0, 0);
            SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        }
    }

    if ((!enable_positive_sk) && (!enable_negative_sk))
    {
        mmi_brw_app_ren_page_set_LSK();
        mmi_brw_app_ren_page_set_RSK();
        g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_FALSE;
    #ifdef __MMI_FTE_SUPPORT__
        mmi_brw_app_change_ren_page_FTE_toolbar_state();
    #endif
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_TRUE;
    #ifdef __MMI_FTE_SUPPORT__
        mmi_brw_app_change_ren_page_FTE_toolbar_state();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_positive_key_hdlr
 * DESCRIPTION
 *  This is the temporary dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_positive_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-setting softkeys to their original state */
    mmi_brw_app_ren_page_set_LSK();
    mmi_brw_app_ren_page_set_RSK();
#ifdef __MMI_FTE_SUPPORT__
    mmi_brw_app_change_ren_page_FTE_toolbar_state();
#endif
    mmi_brw_app_srv_hdlr_wait_user_action_rsp(MMI_TRUE);
    g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_negative_key_hdlr
 * DESCRIPTION
 *  This is the temporary dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_negative_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-setting softkeys to their original state */
    mmi_brw_app_ren_page_set_LSK();
    mmi_brw_app_ren_page_set_RSK();
#ifdef __MMI_FTE_SUPPORT__
    mmi_brw_app_change_ren_page_FTE_toolbar_state();
#endif
    mmi_brw_app_srv_hdlr_wait_user_action_rsp(MMI_FALSE);
}


#ifdef __MMI_FTE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_change_ren_page_FTE_toolbar_state
 * DESCRIPTION
 *  Enable the FTE toolbar on browser main screen after Transaction ended
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_change_ren_page_FTE_toolbar_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_SET_LSK,
        mmi_frm_scrn_get_active_id(),
        g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting,
        g_srv_brw_cntx.screen_size_status,
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        mmi_brw_app_is_browser_first_accessed_page(),
    #else
        2,
    #endif /* SLIM_WAP_MMS */
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p);


    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
#ifdef __MMI_ICON_BAR_SUPPORT__
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    if(!mmi_brw_app_is_browser_first_accessed_page())
#endif
    {
        wgui_icon_bar_reset_pen_state();
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching 
                || g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting
                || g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action
                || g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag)
        {
            wgui_icon_bar_set_item_enable_state(0,MMI_FALSE);
            wgui_icon_bar_set_item_enable_state(1,MMI_FALSE);
            wgui_icon_bar_set_item_enable_state(2,MMI_FALSE);
            wgui_icon_bar_set_item_enable_state(3,MMI_FALSE);
            g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send = MMI_FALSE;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
        {
                wgui_icon_bar_set_item_enable_state(0,MMI_TRUE);
                wgui_icon_bar_set_item_enable_state(1,srv_brw_is_backward_navigation());
                wgui_icon_bar_set_item_enable_state(2,srv_brw_is_forward_navigation());
                wgui_icon_bar_set_item_enable_state(3,MMI_TRUE);
        }
        wgui_icon_bar_update();
    }
#endif
}
#endif /*__MMI_FTE_SUPPORT__*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_do_element_string
 * DESCRIPTION
 *  This function return the string ID to be displayed for a do element
 *  after comparing the string passed to it (label/type) with some of the
 *  standard do element types. If no match is found then it returns 0
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_brw_app_get_do_element_string(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp (string, "accept") == 0)
    {
        return STR_GLOBAL_OK;
    }
    else if (strcmp (string, "delete") == 0)
    {
        return STR_GLOBAL_DELETE;
    }
    else if (strcmp (string, "help") == 0)
    {
        return STR_GLOBAL_HELP;
    }
    else if (strcmp (string, "options") == 0)
    {
        return STR_GLOBAL_OPTIONS;
    }
    else if (strcmp (string, "prev") == 0)
    {
        return STR_GLOBAL_BACK;
    }
    else if (strcmp (string, "reset") == 0)
    {
        return STR_GLOBAL_RESET;
    }
    else
    {
        return 0;
    }
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_do_element_string
 * DESCRIPTION
 *  This function return the string ID to be displayed for a do element
 *  after comparing the string passed to it (label/type) with some of the
 *  standard do element types. If no match is found then it returns 0
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void mmi_brw_app_sec_confirm_dialog_res(S8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_ren_page_sec_confirm_dialog_res(g_brw_app_cntx.sec_confirm_dlg_info_p->request_id, result);
    srv_brw_free_OSL_memory((void**)&(g_brw_app_cntx.sec_confirm_dlg_info_p));

}
#endif /* WAP_SEC_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_do_element_string
 * DESCRIPTION
 *  This function return the string ID to be displayed for a do element
 *  after comparing the string passed to it (label/type) with some of the
 *  standard do element types. If no match is found then it returns 0
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
MMI_BOOL mmi_brw_app_pre_entry_auth_dialog_screen(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_app_cntx.brw_scr_group_id == GRP_ID_INVALID)
    {
        g_brw_app_cntx.brw_scr_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, 
                                                               BRW_AUTH_SEC_FROM_OUTSIDE_GRP_ID,
                                                               mmi_brw_app_auth_sec_group_proc,
                                                               (void*)NULL,
                                                               MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    }
    mmi_brw_app_if_show_auth_dlg();
}


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_do_element_string
 * DESCRIPTION
 *  This function return the string ID to be displayed for a do element
 *  after comparing the string passed to it (label/type) with some of the
 *  standard do element types. If no match is found then it returns 0
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
MMI_BOOL mmi_brw_app_pre_entry_sec_confirm_screen(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.sec_confirm_dlg_info_p->buttons == WPS_DLG_POPUP)
    {
        mmi_brw_app_show_sec_popup();
    }
    else
    {
        if(g_brw_app_cntx.brw_scr_group_id == GRP_ID_INVALID || !mmi_frm_group_is_in_active_serial(g_brw_app_cntx.brw_scr_group_id))
        {
            g_brw_app_cntx.brw_scr_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, 
                                                                   BRW_AUTH_SEC_FROM_OUTSIDE_GRP_ID,
                                                                   mmi_brw_app_auth_sec_group_proc,
                                                                   (void*)NULL,
                                                                   MMI_FRM_NODE_SMART_CLOSE_FLAG); 
        }
        mmi_brw_app_if_show_sec_confirm_screen();
    }
}
#endif /* WAP_SEC_SUPPORT */


#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_splash_screen_title_icon
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_splash_screen_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_icon = (PU8) get_image(mmi_brw_app_get_animated_title_icon());
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }
    draw_title();
}
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

/************************************RENDERED PAGE END******************************/

/************************************MISCELLANEOUS**********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_browser_launched_from_main_menu
 * DESCRIPTION
 *  This func is used for checking id the browser was launched from the WAP menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_browser_launched_from_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p)
    {
#if defined(__MMI_OP11_HOMESCREEN__)  || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        return (g_brw_app_cntx.brw_dynamic_cntx_p->mainMenuEntryFlag || g_brw_app_cntx.isBookmarkLaunched);
    #else 
        return g_brw_app_cntx.brw_dynamic_cntx_p->mainMenuEntryFlag;
    #endif 
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_top_screen_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_get_top_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_brw_app_cntx.top_scr_id;
}

#ifdef MMS_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_check_mms_is_ready
 * DESCRIPTION
 *  This function is called to check if the mms module is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_check_mms_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return(mms_is_ready());
}
#endif /* MMS_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_play_tone
 * DESCRIPTION
 *  This func is used for playing the tone id passed to it if it is allowed to
 * play that tone
 * PARAMETERS
 *  tone_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_play_tone(srv_prof_tone_enum tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_prof_is_tone_playing(tone_id))
    {
        srv_prof_play_tone(tone_id, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_return_to_editor
 * DESCRIPTION
 *  This function is the callback function passed to the editor option draw
 * screen to return to the editor screen whenever required
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GoBackHistory(1);
    cui_menu_close(BRW_MENU_CUI_EDITOR_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_screen_present
 * DESCRIPTION
 *  To perform mmi_brw_app_is_screen_present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_screen_present(mmi_id scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_id = BROWSER_BASE; group_id < BRW_SCREEN_GROUP_TOTAL; group_id++)
    {
        if (mmi_frm_group_is_present (group_id))
        {
            result = mmi_frm_scrn_is_present (group_id, scr_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG);
            if (result)
            {
                break;
            }
        }
    }
    return result;
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_resize_screen_req
 * DESCRIPTION
 *  To perform 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_resize_screen_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_screen_info_struct screen_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat431GetScreenInfo(g_srv_brw_cntx.screen_size_status, &screen_info.x, &screen_info.y, &screen_info.w, &screen_info.h, &screen_info.title_layer, &screen_info.bottom_layer);
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
    screen_info.h = screen_info.h - MMI_ICON_BAR_HEIGHT;
#endif
#endif
    srv_brw_resize_screen_req(&screen_info);
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_reset_object_properties
 * DESCRIPTION
 *  This function is to reset the content of the object properties structure 
 * before storing the new properties to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_reset_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < BRW_OBJECT_PROP_MAX_COUNT; index++)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[index] = MMI_FALSE;
    }
    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name, (S8*) L"");
    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_address, (S8*) L"");
    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size, (S8*) L"");
    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_date, (S8*) L"");
}

#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_free_dynamic_list_memory
 * DESCRIPTION
 *  This function is to free the memory taken for the dynamic list data when
 * the dynamic screen is getting deleted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_free_dynamic_list_memory(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES:
        {
    #ifdef OBIGO_Q05A
            if(g_srv_brw_cntx.sorting_method != WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
    #endif /* OBIGO_Q05A */
            {
                srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
                srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);                
            }
            break;
        }
#endif
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SCR_ID_BRW_STORED_PAGES:
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);
            break;
        }
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
#ifdef OBIGO_Q05A
    #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SCR_ID_BRW_RECENT_PAGES_HOST:
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST);
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);                
            break;
        }
    #endif
        case SCR_ID_BRW_PAGE_OBJECT_TYPES:
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_PAGE_OBJECTS_LIST);
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
            srv_brw_get_resource_list_end_req();
            break;
        }
#endif /* OBIGO_Q05A */
#ifdef WAP_SEC_SUPPORT
        case SCR_ID_BRW_TRUSTED_CERTIFICATES:
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
            break;
        }
#endif /* WAP_SEC_SUPPORT */
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH:
        {
            g_brw_bkm_browse_path_event = BRW_BKM_BROWSE_PATH_NONE;
            break;
        }
#endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SCR_ID_BRW_LAUNCH_PAGE:
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SHORTCUT_LIST);
            break;
        }
#endif /* __MMI_Q05A_LAUNCH_SCREEN__ */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_is_in_usb_mode
 * DESCRIPTION
 *      This function is to check if we are currently in USB mass storage mode
 * and display popup if in USB mass storage mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_brw_app_is_in_usb_mode(void)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return MMI_TRUE;
    }
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif /* __USB_IN_NORMAL_MODE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_splash_scr_id
 * DESCRIPTION
 *      This function is to get the splash screen screen id 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U16 mmi_brw_app_get_splash_scr_id(void)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
	return SCR_ID_BRW_SPLASH_SCREEN;
#else
	return 0;
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
}

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_pre_entry_recent_page_list
 * DESCRIPTION
 *      This function is to check which interface function to be invoked for
 * displaying the recent page list depending on the sorting method
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_brw_app_pre_entry_recent_page_list(void)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    if(g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
    {
	    mmi_brw_app_if_show_recent_pages_host_screen();
    }
    else
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
    {
        mmi_brw_app_if_show_recent_pages_list();
    }
}
#endif


#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_fill_wap_menu_ids
 * DESCRIPTION
 *      
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_brw_app_fill_wap_menu_ids(mmi_menu_id *menu_ids)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_of_items = mmi_brw_app_ui_callback_get_wap_scr_num_of_items(SERVICES_WAP_MENU_ID);
    U16 index;
    U16 num_of_items;
    U16 menu_list[MAX_SUB_MENUS];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds_Ext(SERVICES_WAP_MENU_ID, menu_list);
    num_of_items = GetNumOfChild_Ext(SERVICES_WAP_MENU_ID);

    for(index = 0; index < number_of_items; index++)
    {
        if(index < num_of_items)
        {
            menu_ids[index] = menu_list[index];
        }
        else
        {
            menu_ids[index] = BRW_EMBEDDED_LINK_START + (index - num_of_items) + 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_wap_menu_string_and_icon
 * DESCRIPTION
 *      
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_brw_app_set_wap_menu_string_and_icon(mmi_id group_id, mmi_menu_id *menu_ids)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_of_items = mmi_brw_app_ui_callback_get_wap_scr_num_of_items(SERVICES_WAP_MENU_ID);
    U16 index;
    U16 num_of_items;
    U16 menu_string_ids[MAX_SUB_MENUS];
    U16 menu_image_ids[MAX_SUB_MENUS];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_items = GetNumOfChild_Ext(SERVICES_WAP_MENU_ID);
    GetSequenceStringIds_Ext(SERVICES_WAP_MENU_ID, menu_string_ids);
    GetSequenceImageIds_Ext(SERVICES_WAP_MENU_ID, menu_image_ids);
    for(index = 0; index < number_of_items; index++)
    {
        if(index < num_of_items)
        {
            cui_menu_set_item_string_by_id(group_id, menu_ids[index], menu_string_ids[index]);
            cui_menu_set_item_image(group_id, menu_ids[index], menu_image_ids[index]);
        }
        else
        {
            cui_menu_set_item_string_by_id(group_id, menu_ids[index], STR_ID_BRW_EMBEDDED_LINK_1 + index - num_of_items);
            cui_menu_set_item_image(group_id, menu_ids[index], IMG_ID_BRW_BOOKMARKS);
        }
    }
}

#endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_fill_encoding_menu_ids
 * DESCRIPTION
 *      
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_brw_app_fill_encoding_menu_ids(mmi_menu_id *menu_ids)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_of_items = (U16)bam_get_total_charset_num();
    U16 index;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < number_of_items; index++)
    {
        menu_ids[index] = BRW_ENCODING_START + index + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_wap_menu_string_and_icon
 * DESCRIPTION
 *      
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_brw_app_set_emcoding_menu_string_and_icon(mmi_id group_id, mmi_menu_id *menu_ids)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_of_items = bam_get_total_charset_num();
    U16 index;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < number_of_items; index++)
    {
        cui_menu_set_item_string_by_id(group_id, menu_ids[index], g_brw_app_cntx.charset_list_p[index].name_id);
    }
}

#endif /* OBIGO_Q05A */

/************************************MISCELLANEOUS END*******************************/



/************************************CONFIRM SCREENS***************************/
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_as_homepage_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for setting a url as
 * homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_set_as_homepage_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_SET_AS_HOMEPAGE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr,mmi_brw_app_set_url_as_homepage_ok, mmi_frm_scrn_close_active_id, MMI_FALSE );

}
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_recent_page_item_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently 
 * selected recent page item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_recent_page_item_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr,mmi_brw_app_dmgr_delete_recent_page, mmi_frm_scrn_close_active_id, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_all_recent_pages_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of all the 
 * whole recent page list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_all_recent_pages_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_all_recent_pages, mmi_frm_scrn_close_active_id, MMI_FALSE);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_recent_page_host_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently 
 * selected recent page host.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_recent_page_host_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_recent_host, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif /* OBIGO_Q05A */
#endif

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_suspend_bkgrd_downloads_confirm
 * DESCRIPTION
 *  Confirmation screen for suspending the background downloads
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_suspend_bkgrd_downloads_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DA_RESUME__
    mmi_brw_app_ui_draw_display_confirm(get_string(STR_ID_BRW_BKGRD_DOWNLOAD_SUSPEND), mmi_brw_app_suspend_bkgrd_downloads, mmi_brw_app_continue_bkgrd_downloads, MMI_FALSE);
#else
    mmi_brw_app_ui_draw_display_confirm(get_string(STR_ID_BRW_BKGRD_DOWNLOAD_CANCEL), mmi_brw_app_suspend_bkgrd_downloads, mmi_brw_app_continue_bkgrd_downloads, MMI_FALSE);
#endif /* __MMI_DA_RESUME__ */
   // SetLeftSoftkeyFunction(mmi_brw_app_suspend_bkgrd_downloads, KEY_EVENT_UP);
   // SetRightSoftkeyFunction(mmi_brw_app_continue_bkgrd_downloads, KEY_EVENT_UP);
}
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_select_mode_confirm
 * DESCRIPTION
 *  Confirmation screen for picture select mode activation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_select_mode_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_ACTIVATE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_activate_select_mode , mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_activate_select_mode, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_trusted_certificates_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  trusted certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_trusted_certificates_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_trusted_certificate, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_delete_trusted_certificate, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* WAP_SEC_SUPPORT */ 


#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_restore_browser_settings_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for restoring of Browser
 * settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_restore_browser_settings_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_RESTORE_BROWSER_SETTINGS));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_if_restore_browser_settings, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_if_restore_browser_settings, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */

#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_cache_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_cache_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_CLEAR_CACHE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_clear_cache, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_cache_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_cookie_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_CLEAR_COOKIE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_clear_cookie, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_clear_cookie, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_cache_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_auth_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_CLEAR_AUTH_INFO));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_clear_auth, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_clear_auth, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_search_history_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  search items list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_search_history_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_CLEAR_SEARCH_HISTORY));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_clear_search_history, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif

#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_clear_url_history_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  URL history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_clear_url_history_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_CLEAR_URL_HISTORY));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_clear_url_history, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif

#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_folder_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 *  directory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_folder_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_bookmark_folder, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_bookmark_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of a bookmark
 * file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_bookmark_file_confirm(void)
{
#ifdef SLIM_WAP_MMS
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));
    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_bookmark_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
#else
    mmi_brw_app_ui_draw_display_confirm(get_string(STR_ID_BRW_DELETE_BOOKMARK),mmi_brw_app_dmgr_delete_bookmark_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
#endif /* SLIM_WAP_MMS */

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_delete_bookmark_file, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_all_user_files_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of all the user
 * created bookmark files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_all_user_files_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SLIM_WAP_MMS
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE_ALL));
#else
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_DELETE_ALL_FILES));
#endif /* SLIM_WAP_MMS */
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_all_user_files, mmi_frm_scrn_close_active_id, MMI_FALSE);

}
#endif

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_browse_path_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing
 *  bookmark file while performing Copy/Move operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_browse_path_replace_file_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_confirm(
        get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE),mmi_brw_app_if_browse_path_replace_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_add_bookmark_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for adding a new bookmark
 * file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_add_bookmark_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SLIM_WAP_MMS
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SAVE));
#else
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_SAVE_BOOKMARK));
#endif /* SLIM_WAP_MMS */
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));
    if(g_brw_app_cntx.add_bkm_cid != GRP_ID_INVALID)
    {
        mmi_brw_app_ui_draw_display_confirm_with_sg((UI_string_type) msgStr, mmi_brw_app_dmgr_add_bookmark, mmi_brw_app_add_bookmark_confirm_GoBackHistory, MMI_FALSE, g_brw_app_cntx.add_bkm_cid);
    }
    else
    {
        mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_add_bookmark, mmi_brw_app_add_bookmark_confirm_GoBackHistory, MMI_FALSE);
    }

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_add_bookmark, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_brw_app_add_bookmark_confirm_GoBackHistory, KEY_EVENT_UP);
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_edit_bookmark_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for editing a bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_edit_bookmark_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SLIM_WAP_MMS
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SAVE));
#else
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_SAVE_BOOKMARK));
#endif /* SLIM_WAP_MMS */
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_edit_bookmark, mmi_brw_app_edit_bookmark_confirm_GoBackHistory, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_edit_bookmark, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_brw_app_edit_bookmark_confirm_GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_add_bookmark_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing
 *  bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_add_bookmark_replace_file_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_app_cntx.add_bkm_cid != GRP_ID_INVALID)
    {
        mmi_brw_app_ui_draw_display_confirm_with_sg(get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE),mmi_brw_app_dmgr_add_bookmark_replace_file, mmi_frm_scrn_close_active_id, MMI_FALSE, g_brw_app_cntx.add_bkm_cid);
    }
    else
    {
        mmi_brw_app_ui_draw_display_confirm(get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE),mmi_brw_app_dmgr_add_bookmark_replace_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_edit_bookmark_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing
 *  bookmark file while editing an existing bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_edit_bookmark_replace_file_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_confirm(get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE), mmi_brw_app_dmgr_edit_bookmark_replace_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif

#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_edit_bookmark_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing
 *  bookmark file while editing an existing bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_copy_move_replace_file_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_confirm(get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE), mmi_brw_app_if_copy_move_replace_file, mmi_frm_scrn_close_active_id, MMI_FALSE);
}
#endif
#endif /* __MMI_VBOOKMARK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_title_string_id
 * DESCRIPTION
 *  This function returns title string ID based on screen ID for dynamic list 
	screen
 * PARAMETERS
 *  void
 * RETURNS
 *  Title string ID
 *****************************************************************************/
U16 mmi_brw_app_get_title_string_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        case SCR_ID_BRW_BOOKMARK_BROWSE_PATH:
        {
            if (g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO)
            {
                title_ID = STR_ID_BRW_COPY_TO;
            }
            else
            {
                title_ID = STR_ID_BRW_MOVE_TO;
            }
            break;
        }
    #endif
#ifdef OBIGO_Q05A
        case SCR_ID_BRW_PAGE_OBJECTS:
        {			
            switch (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->selected_page_object_type)
            {
                case BRW_PAGE_OBJECT_TYPE_IMAGE:
                    title_ID = STR_ID_BRW_IMAGES;
                    break;

                case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
                    title_ID = STR_ID_BRW_BG_IMAGES;
                    break;

                case BRW_PAGE_OBJECT_TYPE_SOUNDS:
                    title_ID = STR_ID_BRW_SOUNDS;
                    break;

                case BRW_PAGE_OBJECT_TYPE_OTHERS:
                    title_ID = STR_ID_BRW_OTHERS;
                    break;
                default:
                    title_ID = 0;
                    break;
            }
            break;
        }
#endif /* OBIGO_Q05A */
        case SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE:
            {
                if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_TRUSTED_CERTIFICATE)
                {
                    title_ID = STR_ID_BRW_CERTIFICATE_DETAILS;
                }
            #ifdef OBIGO_Q05A
            #ifdef WAP_SEC_SUPPORT
                else if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_CERTIFICATE)
                {
                    title_ID = STR_ID_BRW_CURRENT_CERTIFICATE;
                }
                else if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_SESSION_INFO)
                {
                    title_ID = STR_ID_BRW_SESSION_INFO;
                }
            #endif
            #endif
                else
                {
                    title_ID = 0;
                }
            }
            break;

        default:
            return 0;
    }
    return title_ID;
}


#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_send_auth_info_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for sending the authentication
 * information provided by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_send_auth_info_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SEND));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_send_auth_dlg_ok_rsp, mmi_brw_app_send_auth_dlg_confirm_cancel_rsp, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_send_auth_dlg_ok_rsp, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_brw_app_send_auth_dlg_confirm_cancel_rsp, KEY_EVENT_UP);
}
#endif /* OBIGO_Q03C_BROWSER */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_preferences_save_confirm
 * DESCRIPTION
 *  This function is to display the confirmation screen for saving the changes
 * made in the preferences
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_preferences_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SAVE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_save_browser_preferences, mmi_brw_app_cancel_browser_preferences, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_save_browser_preferences, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_brw_app_cancel_browser_preferences, KEY_EVENT_UP);
}


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_stored_page_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently 
 * selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_stored_page_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_stored_page, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_delete_stored_page, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_all_stored_page_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire 
 * stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_all_stored_page_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_delete_all_stored_pages, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_delete_all_stored_pages, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_save_stored_page_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for saving of a new page in 
 * stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_save_stored_page_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SAVE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_save_stored_page, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_save_stored_page, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_rename_stored_page_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for renaming of a page in 
 * stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_rename_stored_page_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_GLOBAL_SAVE));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

    mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_rename_stored_page, mmi_frm_scrn_close_active_id, MMI_FALSE);

    //SetLeftSoftkeyFunction(mmi_brw_app_dmgr_rename_stored_page, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* OBIGO_Q05A */

#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_register_for_bearer_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_register_for_bearer_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 val;
    U8 app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer = SRV_CBM_BEARER_PS | 
         #ifdef __TCPIP_OVER_CSD__
             SRV_CBM_BEARER_CSD | 
         #endif /* #ifdef __TCPIP_OVER_CSD__ */
             SRV_CBM_BEARER_WIFI;

    val = SRV_CBM_ACTIVATED|
    #ifdef __MMI_WAP_GPRS_LINGER_TIMEOUT__
    SRV_CBM_GPRS_AUTO_DISC_TIMEOUT|
    #endif
#ifdef __TCPIP_OVER_CSD__
    SRV_CBM_CSD_AUTO_DISC_TIMEOUT|
#endif /* #ifdef __TCPIP_OVER_CSD__ */
    SRV_CBM_DEACTIVATED;
    app_id = (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, SRV_WAP_PROF_SIMID_SIM1);
    cbm_register_bearer_info_by_app_id(app_id, MOD_MMI, bearer, val);
    srv_cbm_register_bearer_info(app_id, val, bearer, mmi_brw_app_if_wifi_bearer_status_proc, NULL);

#if (MMI_MAX_SIM_NUM >= 2)
    app_id = (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, SRV_WAP_PROF_SIMID_SIM2);
    cbm_register_bearer_info_by_app_id(app_id, MOD_MMI, bearer, val);
    srv_cbm_register_bearer_info(app_id, val, bearer, mmi_brw_app_if_wifi_bearer_status_proc, NULL);
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    app_id = (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, SRV_WAP_PROF_SIMID_SIM3);
    cbm_register_bearer_info_by_app_id(app_id, MOD_MMI, bearer, val);
    srv_cbm_register_bearer_info(app_id, val, bearer, mmi_brw_app_if_wifi_bearer_status_proc, NULL);
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    app_id = (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, SRV_WAP_PROF_SIMID_SIM4);
    cbm_register_bearer_info_by_app_id(app_id, MOD_MMI, bearer, val);
    srv_cbm_register_bearer_info(app_id, val, bearer, mmi_brw_app_if_wifi_bearer_status_proc, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_open_bearer_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int8 mmi_brw_app_open_bearer_ext(void)
{
#ifdef __MMI_WLAN_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret = 0;
    srv_wap_prof_profile_content_struct *profile_content_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_get_profile_content((void **)&profile_content_p);
    ret = cbm_open_bearer(profile_content_p->data_account_primary_id);
    OslMfree(profile_content_p);
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 0, 0, 0, ret);
    if(ret == CBM_WOULDBLOCK)
    {
        srv_brw_set_bearer(MMI_TRUE);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi = MMI_TRUE;
    }
    else if (ret != CBM_OK)
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_ID_BRW_CONNECTION_FAILED,
            MMI_EVENT_PROPLEM);
    }
    return ret;
#else
    return CBM_OK;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_open_bearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int8 mmi_brw_app_open_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    return mmi_brw_app_open_bearer_ext();
#else
    return CBM_OK;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_continue_launch_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_continue_launch_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_brw_app_cntx.brw_dynamic_cntx_p->launch_type)
    {
        case BRW_LAUNCH_TYPE_OUTSIDE_URL:
        case BRW_LAUNCH_TYPE_URL:
        {
            mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
            break;
        }

    #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case BRW_LAUNCH_TYPE_RECENT_PAGE:
        {
            mmi_brw_app_srv_hdlr_open_recent_page();
            break;
        }
    #endif

    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case BRW_LAUNCH_TYPE_STORED_PAGE:
        {
            mmi_brw_app_srv_hdlr_open_stored_page();
            break;
        }
    #endif

    #ifdef OBIGO_Q05A 
        case BRW_LAUNCH_TYPE_OPEN_FILE:
        case BRW_LAUNCH_TYPE_OUTSIDE_FILE:
        {
            mmi_brw_srv_hdlr_load_data_req();
            break;
        }
    #endif

        default:
        {
            MMI_ASSERT(0);
        }
    }
    g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_END;
}


#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_continue_relaunch_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_continue_relaunch_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_error_enum ret = srv_brw_relaunch_last_browser_req();
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 22, 0, 0, ret);
    if(ret == SRV_BRW_ERROR)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_ID_BRW_BEARER_SWITCH_RETRY),
                MMI_EVENT_FAILURE);
        }
        mmi_brw_app_delete_busy_screen();
        return;
    }
    if(!mmi_brw_is_rendered_page_present())
    {
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                   mmi_brw_app_pre_entry_render_page,
                                                   BRW_RENDERED_PAGE_GRP_ID,
                                                   mmi_brw_rendered_page_group_proc);
    }
    else
    {
        mmi_brw_app_delete_busy_screen();
    }
}
#endif

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_save_shortcut_confirm_GoBackHistory
 * DESCRIPTION
 *  This function is to delete the ADD bookmark screen when the user selects
 * No on the ADD Bookmark confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_save_shortcut_confirm_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_scrn_close_active_id(); 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_save_shortcut_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for saving a shortcut item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_save_shortcut_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_SAVE_SHORTCUT));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));
    mmi_brw_app_ui_draw_display_confirm((UI_string_type)msgStr, mmi_brw_app_dmgr_save_shortcut, mmi_brw_app_save_shortcut_confirm_GoBackHistory, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_save_shortcut_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for saving a shortcut item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_shortcut_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_DELETE_SHORTCUT));
    mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));
    mmi_brw_app_ui_draw_display_confirm((UI_string_type)msgStr, mmi_brw_app_dmgr_delete_shortcut, mmi_frm_scrn_close_active_id, MMI_FALSE);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_close_all_bookmark_screens
 * DESCRIPTION
 *  This function is to close all the bookmark related screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_close_all_bookmark_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(BRW_OPEN_BOOKMARKS_FROM_FMGR_GRP_ID);
    mmi_frm_group_close(BRW_RECV_BOOKMARKS_GRP_ID); 
    mmi_frm_group_close(BRW_ADD_BOOKMARK_GRP_ID);
    mmi_frm_group_close(BRW_COPY_MOVE_BOOKMARK_GRP_ID);
    mmi_frm_group_close(g_brw_app_cntx.add_bkm_cid);
    mmi_frm_group_close(g_brw_app_cntx.file_naming_rule_cid);
    if(g_brw_app_cntx.brw_scr_group_id != GRP_ID_INVALID)
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BOOKMARKS);
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BOOKMARK_BROWSE_PATH);
    #endif
    }
}



#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPMAIN_C */
