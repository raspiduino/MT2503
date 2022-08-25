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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef MMI_BROWSERAPPDMGR_C
#define MMI_BROWSERAPPDMGR_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "BrowserAppSrvHdlr.h"
#include "BrowserAppInterface.h"
#include "BrowserAppMain.h"
#include "BrowserAppScrDB.h"
#include "PhoneSetupGprots.h"
#include "BrowserAppDmgr.h"

#include "MMIDataType.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvProts.h"
#include "Unicodexdcl.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_browser_def.h"
#include "BrowserSrvInterface.h"
#include "BrowserSrvConfig.h"
#include "kal_public_api.h"
#include "app_datetime.h"
#include "CustDataRes.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "Conversions.h"
#include "string.h"
#include "stdio.h"
#include "wps_struct.h"
#include "mmi_frm_scenario_gprot.h"
#include "BrowserResDef.h"
#include "common_nvram_editor_data_item.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "FileMgrSrvGProt.h"
#include "BrowserAppUIDraw.h"
#include "mmi_frm_events_gprot.h"
#include "BrowserSrvGprot.h"
#include "gui_data_types.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "InlineCuiGprot.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "vBookmark.h"
#include "wap_adp.h"
#include "wgui_categories_util.h"
#include "BookmarkCuiGprot.h"
#include "custom_wap_config.h"
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvGprot.h"
#include "nvram_common_defs.h"
#include "bam_api.h"
#include "GlobalConstants.h"
#include "stdlib.h"

#ifdef __MMI_OP12_BRW_SEARCH_MENU__
extern kal_uint8 const WAP_CUSTOM_CFG_SEARCH_WEB_URL[];
#endif 

#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
extern const custom_wap_embed_link_struct wap_embed_link_default;
#endif 

#ifdef __MMI_BRW_POST_SESSION_INFO__
static applib_time_struct start_session_data_time;
static applib_time_struct end_session_data_time;
static U64 total_bytes_downloaded;
static U64 total_bytes_uploaded;
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dmgr_get_number_of_bookmark_list_items
 * DESCRIPTION
 *  This function is to get the number of items to be displayed in the 
 * bookmark screen.
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
U16 mmi_brw_dmgr_get_number_of_bookmark_list_items (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_brw_bkm_cntx.total_file_count;
}


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dmgr_get_number_of_browse_path_list_items
 * DESCRIPTION
 *  This function is to get the number of items to be displayed in the 
 * browser path list screen.
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
U16 mmi_brw_dmgr_get_number_of_browse_path_list_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count = BRW_BKM_TRANSFER_BOOKMARKS_TOTAL_MENU_ITEMS;
    }
    return g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count;
}
#endif


#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dmgr_get_number_of_select_bookmark_list_items
 * DESCRIPTION
 *  This function is to get the number of items to be displayed in the 
 * insert bookmark list screen.
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
U16 mmi_brw_dmgr_get_number_of_select_bookmark_list_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_brw_bkm_sel_bkm_cntx.total_file_count;
}
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_recent_page_list_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the recent page list screen
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_recent_page_list_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    if(g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
    {
        return MMI_TRUE;
    }
    else
#endif /* OBIGO_Q05A */
    {
        if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list)
            return MMI_TRUE;
        else
            return MMI_FALSE;
    }
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_recent_page_host_list_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the recent page list screen
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_recent_page_host_list_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_recent_page_list_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the recent pages list 
 * screen if the check data function returns false
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_recent_page_list_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_progress_screen_params(STR_ID_BRW_RECENT_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_recent_page_list;
    srv_brw_get_recent_pages_list_start_req(&obj);
    return MMI_TRUE;
}
#endif


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_stored_page_list_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the Stored Pages list screen
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_stored_page_list_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_stored_page_list_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the Stored Pages list 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_stored_page_list_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_progress_screen_params(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_save_page_list;
    srv_brw_get_stored_pages_list_start_req(&obj);
    return MMI_TRUE;
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_trusted_cert_list_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the Trusted certificate list screen
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_trusted_cert_list_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_trusted_cert_list_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the trusted cert list 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_trusted_cert_list_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_progress_screen_params(STR_ID_BRW_TRUSTED_CERTIFICATES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_trusted_cert_list;
    srv_brw_get_trusted_certificate_ids_req(&obj);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_trusted_cert_view_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the Trusted certificate View screen
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_trusted_cert_view_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Ensure that previous index data is cleared up on reaching list */
    if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_TRUSTED_CERTIFICATE && g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p)
    {
        return MMI_TRUE;
    }
#ifdef OBIGO_Q05A
    else if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_CERTIFICATE && g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p)
    {
        return MMI_TRUE;
    }
    else if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_SESSION_INFO && g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p)
    {
        return MMI_TRUE;
    }
#endif
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_trusted_cert_view_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the trusted cert view 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_trusted_cert_view_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_TRUSTED_CERTIFICATE)
    {
        mmi_brw_app_dmgr_get_trusted_certificate();
        mmi_brw_app_set_progress_screen_params(STR_GLOBAL_VIEW, STR_GLOBAL_PLEASE_WAIT);
    }
#ifdef OBIGO_Q05A
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_CERTIFICATE)
    {
        mmi_brw_app_dmgr_get_current_certificate();
        mmi_brw_app_set_progress_screen_params(STR_ID_BRW_CURRENT_CERTIFICATE, STR_GLOBAL_PLEASE_WAIT);
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_SESSION_INFO)
    {
        mmi_brw_app_dmgr_get_current_session_info();
        mmi_brw_app_set_progress_screen_params(STR_ID_BRW_SESSION_INFO, STR_GLOBAL_PLEASE_WAIT);
    }
#endif /* OBIGO_Q05A */
    else
    {
        ASSERT(0);
    }
    return MMI_TRUE;
}
#endif /* WAP_SEC_SUPPORT */

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_page_objects_type_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the Page Objects Types screen
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_page_objects_type_screen_check_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_page_objects_type_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the Page objects types 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_page_objects_type_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_progress_screen_params(STR_ID_BRW_PAGE_OBJECTS, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_page_objects_list;
    srv_brw_get_resource_list_start_req(&obj);
    return MMI_TRUE;
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_static_screen_check_data_func
 * DESCRIPTION
 *  This function is to check if the data is available to be displayed on a 
 * the static menu screen
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_static_screen_check_data_func(U16 scr_id)
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
 *  mmi_brw_app_dmgr_static_screen_get_data_func
 * DESCRIPTION
 *  This function is to get the data to be displayed on the static menu 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
MMI_BOOL mmi_brw_app_dmgr_static_screen_get_data_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_certificate_str
 * DESCRIPTION
 *  This func is used for getting the string from the data sent by the service
 * to be displayed in the view certificate screen
 * PARAMETERS
 *  msg_str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_get_certificate_str(U8 *msg_str, mmi_brw_certificate_content_struct *certificate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_str[BRW_CURRENT_CERT_STR_LEN + 1];
    U8 valid_not_before[20];
    U8 valid_not_after[20];
    S32 local_time_in_sec;
    applib_time_struct time_obj;
    U8 *serial_num_hex_p;
    U16 pos;
    U16 serial_num_len;
    U8 *issuer_str;
    U8 *valid_not_bfr_str;
    U8 *valid_not_aft_str;
    U8 *serial_num_str;
    U8 *sig_alg_name_str;
    U8 *subject_str;
    U8 *type_str;
    U8 *version_str;
    U8 *str_p;
    U8 date_format;
    U8 seperator_format;
    U8 seperator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = (U8*) GetString(STR_ID_BRW_ISSUER);
    issuer_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) issuer_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_VAL_NOT_BEF);
    valid_not_bfr_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) valid_not_bfr_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_VAL_NOT_AFT);
    valid_not_aft_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) valid_not_aft_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_SERIAL_NUM);
    serial_num_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) serial_num_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_SIG_ALG);
    sig_alg_name_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) sig_alg_name_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_SUBJECT);
    subject_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) subject_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_TYPE);
    type_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) type_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_VERSION);
    version_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) version_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    memset(temp_str, 0, BRW_CURRENT_CERT_STR_LEN + 1);

	date_format = PhnsetGetDateFormat();
    seperator_format = PhnsetGetDateSeperatorFormat();

	switch(seperator_format)
    {
	case 0:
		seperator = '.';
		break;
	case 1:
		seperator = ':';
		break;
	case 2:
		seperator = '/';
		break;
	default :
		seperator = '-';
		break;
    }
	
    local_time_in_sec = applib_dt_sec_utc_to_local(certificate->not_before);
    applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	switch(date_format)
    {
        case 0:
				sprintf((S8*) valid_not_before, "%02d%c%02d%c%d", time_obj.nDay, seperator, time_obj.nMonth, seperator, time_obj.nYear);		
                break;
        case 1:
                sprintf((S8*) valid_not_before, "%02d%c%02d%c%d", time_obj.nMonth, seperator, time_obj.nDay, seperator, time_obj.nYear);
                break;
        default:
				sprintf((S8*) valid_not_before, "%d%c%02d%c%02d", time_obj.nYear, seperator, time_obj.nMonth, seperator, time_obj.nDay);          
                break;
    }

    //local_time_in_sec = applib_dt_sec_utc_to_local(certificate->not_before);
    //applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
    //sprintf((S8*) valid_not_before, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

    local_time_in_sec = applib_dt_sec_utc_to_local(certificate->not_after);
    applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	switch(date_format)
    {
        case 0:
				sprintf((S8*) valid_not_after, "%02d%c%02d%c%d", time_obj.nDay, seperator, time_obj.nMonth, seperator, time_obj.nYear);		
                break;
        case 1:
                sprintf((S8*) valid_not_after, "%02d%c%02d%c%d", time_obj.nMonth, seperator, time_obj.nDay, seperator, time_obj.nYear);
                break;
        default:
				sprintf((S8*) valid_not_after, "%d%c%02d%c%02d", time_obj.nYear, seperator, time_obj.nMonth, seperator, time_obj.nDay);          
                break;
    }
    //sprintf((S8*) valid_not_after, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

    /* hexadecimal representation of a string takes thrice the number of bytes as the actual string */
    serial_num_len = certificate->serial_num_len;

    if (serial_num_len)
    {
        serial_num_hex_p = OslMalloc((serial_num_len * 3) + 1);
        for (pos = 0; pos < serial_num_len; pos++)
        {
            sprintf((S8*) temp_str, "%x ", certificate->serial_num[pos]);
            if (strlen((S8*) temp_str) < 3)
            {
                sprintf((S8*) temp_str, "0%x ", certificate->serial_num[pos]);
            }
            if (pos == 0)
            {
                strcpy((S8*) serial_num_hex_p, (S8*) temp_str);
            }
            else
            {
                strcat((S8*) serial_num_hex_p, (S8*) temp_str);
            }
        }

        sprintf(
            (S8*) temp_str,
            "%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%d\n\n%s\n%d",
            issuer_str,
            certificate->issuer,
            valid_not_bfr_str,
            valid_not_before,
            valid_not_aft_str,
            valid_not_after,
            serial_num_str,
            serial_num_hex_p,
            sig_alg_name_str,
            certificate->sig_alg_name,
            subject_str,
            certificate->subject,
            type_str,
            certificate->type,
            version_str,
            certificate->version);

        OslMfree(serial_num_hex_p);
    }
    else
    {
        sprintf(
            (S8*) temp_str,
            "%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%d\n\n%s\n%d",
            issuer_str,
            certificate->issuer,
            valid_not_bfr_str,
            valid_not_before,
            valid_not_aft_str,
            valid_not_after,
            sig_alg_name_str,
            certificate->sig_alg_name,
            subject_str,
            certificate->subject,
            type_str,
            certificate->type,
            version_str,
            certificate->version);
    }

    mmi_chset_utf8_to_ucs2_string((U8*) msg_str, BRW_CURRENT_CERT_STR_LEN + 1, (U8*) temp_str);

    OslMfree(issuer_str);
    OslMfree(valid_not_bfr_str);
    OslMfree(valid_not_aft_str);
    OslMfree(serial_num_str);
    OslMfree(sig_alg_name_str);
    OslMfree(subject_str);
    OslMfree(type_str);
    OslMfree(version_str);
}

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_session_info_str
 * DESCRIPTION
 *  This func is used for creating the session info string from the data 
 * sent by service to display to the user
 * PARAMETERS
 *  msg_str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_get_session_info_str(U8 *msg_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_str[BRW_SESSION_INFO_STR_LEN + 1];
    U8 *key_exch_alg_str;
    U8 *bulk_encr_alg_str;
    U8 *hash_alg_str;
    U8 *sec_conn_type_str;
    U8 *str_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = (U8*) GetString(STR_ID_BRW_KEY_EXCH_ALG);
    key_exch_alg_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) key_exch_alg_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_BULK_ENCR_ALG);
    bulk_encr_alg_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) bulk_encr_alg_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_HASH_ALG);
    hash_alg_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) hash_alg_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_SEC_CONN_TYPE);
    sec_conn_type_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) sec_conn_type_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    memset(temp_str, 0, BRW_SESSION_INFO_STR_LEN + 1);

    sprintf(
        (S8*) temp_str,
        "%s\n%d\n\n%s\n%d\n\n%s\n%d\n\n%s\n%d",
        key_exch_alg_str,
        g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->key_exchange_alg,
        bulk_encr_alg_str,
        g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->blk_encrypt_alg,
        hash_alg_str,
        g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->hash_alg,
        sec_conn_type_str,
        g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->sec_conn_type);

    mmi_chset_utf8_to_ucs2_string((U8*) msg_str, BRW_SESSION_INFO_STR_LEN + 1, (U8*) temp_str);

    OslMfree(key_exch_alg_str);
    OslMfree(bulk_encr_alg_str);
    OslMfree(hash_alg_str);
    OslMfree(sec_conn_type_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_copy_current_certificate
 * DESCRIPTION
 *  Function to copy the current certificate contents
 * PARAMETERS
 *  dest_p      [IN]        
 *  src_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_copy_current_certificate(
        mmi_brw_certificate_content_struct *dest_p,
        wps_sec_get_current_cert_rsp_struct *src_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U32 size; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(dest_p->issuer, src_p->issuer, src_p->issuer_len + 1);
    dest_p->not_after = src_p->not_after;
    dest_p->not_before = src_p->not_before;
    memcpy(dest_p->serial_num, src_p->serial_num, src_p->serial_num_len + 1);
    dest_p->serial_num_len = src_p->serial_num_len;
    memcpy(dest_p->sig_alg_name, src_p->sig_alg_name, src_p->sig_alg_name_len + 1);
    memcpy(dest_p->subject, src_p->subject, src_p->subject_len + 1);
    dest_p->type = src_p->type;
    dest_p->version = src_p->version;
    return;
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_copy_trusted_certificate
 * DESCRIPTION
 *  Function to copy the trusted certificate contents
 * PARAMETERS
 *  dest_p      [IN]        
 *  src_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_copy_trusted_certificate(
        mmi_brw_certificate_content_struct *dest_p,
        wps_sec_cert_content_struct *src_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U32 size; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(dest_p->issuer, src_p->issuer, src_p->issuer_len + 1);
    dest_p->not_after = src_p->not_after;
    dest_p->not_before = src_p->not_before;
    memcpy(dest_p->serial_num, src_p->serial_num, src_p->serial_num_len + 1);
    dest_p->serial_num_len = src_p->serial_num_len;
    memcpy(dest_p->sig_alg_name, src_p->sig_alg_name, src_p->sig_alg_name_len + 1);
    memcpy(dest_p->subject, src_p->subject, src_p->subject_len + 1);
    dest_p->type = src_p->type;
    dest_p->version = src_p->version;
    return;
}
#endif /* WAP_SEC_SUPPORT */


/******************************ADDRESS LIST START****************************/
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_fte_show_address_list
 * DESCRIPTION
 *  This function is the to create a separate group for the screens to be
 * displayed from the rendered page toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_fte_show_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_scr_group_id = mmi_frm_group_create_ex(g_brw_app_cntx.brw_scr_group_id, 
                                                           BRW_RENDERED_PAGE_OPTIONS_GRP_ID,
                                                           mmi_brw_rendered_page_options_group_proc,
                                                           (void*)NULL,
                                                           MMI_FRM_NODE_SMART_CLOSE_FLAG); 
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
#else
    mmi_brw_app_dmgr_pre_entry_address_list();
#endif
}
#endif /* #ifdef __MMI_ICON_BAR_SUPPORT__ */
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_address_list
 * DESCRIPTION
 *  This function is the pre entry function for the address list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_address_list(void)
{
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read address history list from NVRAM if not already read */
    srv_brw_read_address_list_data();

    /* Calculate the number of entries */
    srv_brw_address_list_get_number_of_items();
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
    mmi_asc_to_ucs2((CHAR*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, (CHAR*) L"");
    mmi_brw_app_if_show_enter_url_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_enter_url
 * DESCRIPTION
 *  This is the pre entry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_enter_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, 0, sizeof(g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url));
    mmi_asc_to_ucs2((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);
    mmi_brw_app_if_show_enter_url_screen();
}

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords
 * DESCRIPTION
 *  This is the pre entry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    srv_brw_read_address_list_data();
#endif

#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    srv_brw_read_search_item_list_data();
#endif

    memset(g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, 0, sizeof(g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url));
    mmi_brw_app_if_show_enter_url_screen();
}
#endif


#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_address_list_url
 * DESCRIPTION
 *  This function is to launch a URL present in the address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_address_list_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = MMI_TRUE;
    g_brw_app_cntx.brw_dynamic_cntx_p->reset_hiliter_flag = MMI_TRUE;
    /* EnterAddressOption Screen should not into history when we try to fetch url from
       Enter Address list. */
#if 0 //TODO check if with menu cui this requirement will be fullfilled or not
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_asc_to_ucs2(
        (S8*) g_brw_current_url,
        (S8*) srv_brw_address_list_get_url(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item - 1));
    mmi_brw_app_pre_entry_goto_url();
    /* If the highlighted item is already at top then change nothing */
    if (g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item - 1)
    {
        srv_brw_address_list_set_item_at_top(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item - 1);
        srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST, NULL); //write list to NVRAM

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_addr_list_item
 * DESCRIPTION
 *  Function to add new item to the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_addr_list_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID prev_scrn_group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_brw_address_list_add_item((S8*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url) == SRV_BRW_ERROR_INVALID_URL)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
        return;
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = MMI_TRUE;
    g_brw_app_cntx.brw_dynamic_cntx_p->reset_hiliter_flag = MMI_TRUE;
    mmi_ucs2cpy((PS8) g_brw_current_url, (PS8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url);
    prev_scrn_group_id = g_brw_app_cntx.brw_scr_group_id;
    mmi_brw_app_pre_entry_goto_url();   /* fetch the url */
    mmi_frm_scrn_close(prev_scrn_group_id, SCR_ID_BRW_ENTER_URL);
    cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
}
#else

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_entered_url
 * DESCRIPTION
 *  Function to add new item to the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_entered_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID prev_scrn_group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_brw_validate_url((U8*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1) < 0)
    {
		mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
        return;
    }
    mmi_ucs2cpy((PS8) g_brw_current_url, (PS8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url);
    prev_scrn_group_id = g_brw_app_cntx.brw_scr_group_id;
    mmi_brw_app_pre_entry_goto_url();   /* fetch the url */
    mmi_frm_scrn_close(prev_scrn_group_id, SCR_ID_BRW_ENTER_URL);
    cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
}
#endif /*  __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */


/*********************************ADDRESS LIST END**************************/

/*********************************SEARCH ITEMS LIST START**************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_search_list_item
 * DESCRIPTION
 *  Function to add new item to the search items list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_search_list_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID prev_scrn_group_id;
    U8* ascii_keyword;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    srv_brw_search_item_list_add_item((S8*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, SRV_BRW_SEARCH_ENGINE_GOOGLE);
#endif
    ascii_keyword = (U8*)srv_brw_malloc(SRV_BRW_SEARCH_ITEM_LENGTH + 1);
    memset(ascii_keyword, 0, SRV_BRW_SEARCH_ITEM_LENGTH + 1);
    mmi_chset_ucs2_to_utf8_string((CHAR*)ascii_keyword, SRV_BRW_SEARCH_ITEM_LENGTH, (CHAR*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url);
    prev_scrn_group_id = g_brw_app_cntx.brw_scr_group_id;
    mmi_brw_app_pre_entry_render_page();   /* show the rendered page screen */
    srv_brw_launch_search_string((U8*)ascii_keyword, SRV_BRW_SEARCH_ENGINE_GOOGLE);
    srv_brw_free(ascii_keyword);
    mmi_frm_scrn_close(prev_scrn_group_id, SCR_ID_BRW_ENTER_URL);
}
/*********************************SEARCH ITEMS LIST END**************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_search_or_input_url_item
 * DESCRIPTION
 *  Function to add new item to the search items list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_search_or_input_url_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2strlen((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url) == 0)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_INPUT, MMI_EVENT_PROPLEM);
        return;
    }
    if (srv_brw_validate_url_ex((U8*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1, MMI_FALSE) < 0)
    {
        mmi_brw_app_dmgr_add_search_list_item();
    }
    else
    {
    #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
        mmi_brw_app_dmgr_add_addr_list_item();
    #else
        mmi_brw_app_dmgr_launch_entered_url();
    #endif
    }
}

#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_ICON_BAR_SUPPORT__
/***********************************BOOKMARK START**************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_fte_show_bookmark_list
 * DESCRIPTION
 *  This function is the to create a separate group for the screens to be
 * displayed from the rendered page toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_fte_show_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_scr_group_id = mmi_frm_group_create_ex(g_brw_app_cntx.brw_scr_group_id, 
                                                           BRW_RENDERED_PAGE_OPTIONS_GRP_ID,
                                                           mmi_brw_rendered_page_options_group_proc,
                                                           (void*)NULL,
                                                           MMI_FRM_NODE_SMART_CLOSE_FLAG);     
    mmi_brw_app_dmgr_pre_entry_bookmark_list();
}
#endif /* #ifdef __MMI_ICON_BAR_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_bookmark_list
 * DESCRIPTION
 *  This function is to perform the tasks before opening the Bookmark 
 * list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_bookmarks_context_init();

    /* highlighting the first element on entering */
    g_brw_bkm_cntx.sel_file_index = 0;

    /* displaying the bookmark list */
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
    {
        /* create vbookmark folder and root bookmark file if not already created */
        error_code = srv_brw_bkm_initialize_bookmark_context();
        if (error_code < 0)
        {
            srv_brw_bkm_deinitialize_bookmark_context();
            mmi_brw_app_file_system_error_handler(error_code);
            return;
        }
        mmi_brw_app_create_bookmark_list();
        mmi_brw_app_if_show_bookmarks_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_to_bookmark
 * DESCRIPTION
 *  This function is the external interface for adding bookmark from other
 *  applications with user interface
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_scr_id;
    S32 error_code;
    U8 temp_buffer[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * BRW_UTF8_ENCODING_LENGTH] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = srv_brw_bkm_initialize_bookmark_context();
    if (error_code < 0)
    {
        srv_brw_bkm_deinitialize_bookmark_context();
        mmi_brw_app_file_system_error_handler(error_code);
        return;
    }
    if (!mmi_brw_app_check_available_bookmark_memory())
    {
        srv_brw_bkm_deinitialize_bookmark_context();
        return;
    }
    /* Remove the add bookmark screen if opened and it common screens.
       Update the top screen ID as the Bookmark screen has been removed. */
    mmi_frm_group_close(BRW_ADD_BOOKMARK_GRP_ID);
    g_brw_bkm_add_type = BRW_BKM_ADD_TO_BOOKMARK;
    if(srv_phb_check_ucs2_character(g_brw_current_title))
    {
        mmi_chset_ucs2_to_utf8_string(
            (U8*) temp_buffer,
            SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN * BRW_UTF8_ENCODING_LENGTH,
            (U8*) g_brw_current_title);
        mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1, (U8*) temp_buffer);
    }
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    mmi_brw_app_if_show_add_bookmark_screen();
#else
    mmi_brw_app_dmgr_add_bookmark();
#endif
}


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_open_bookmark_folder
 * DESCRIPTION
 *  It opens the selected bookmark folder to display all bookmark files and
 *  directories present in that folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_open_bookmark_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) g_brw_bkm_cntx.sel_folder_name, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title);
    g_brw_bkm_cntx.sel_file_index = 0;
    mmi_brw_app_create_bookmark_list();
    mmi_brw_app_if_show_browser_dummy_screen();
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_rename_folder
 * DESCRIPTION
 *  This func is used for copying the folder name in the buffer before 
 * performing the rename operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_rename_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type = BRW_BKM_FOLDER_RENAME;

    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    g_brw_display_info_str = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((PS8) g_brw_display_info_str, (PS8) g_brw_bkm_cntx.sel_file_name);
    mmi_chset_utf8_to_ucs2_string((S8*) g_brw_display_info_str, 
        (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
        (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title);

    mmi_brw_app_if_show_bookmarks_create_folder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_bookmark_folder
 * DESCRIPTION
 *  This function is to invoke the service API to remove the selected
 * bookmark folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_bookmark_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    srv_brw_bkm_bookmark_list_struct bkm_list[SRV_BRW_BKM_MAX_COUNT] = {0};
    U8 list_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_count = mmi_brw_app_get_bookmark_items(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title,
        bkm_list);
    
    for(;list_count > 0; list_count--)
    {
        result = srv_brw_bkm_delete_bookmark(bkm_list[list_count - 1].actual_index);
        if(result < 0)
        {
            break;
        }
    }

    if(result == 0)
    {
        result = srv_brw_bkm_delete_bookmark(g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index);
    }

    if (result >= 0)
    {
        mmi_brw_app_create_bookmark_list();
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_GLOBAL_DELETED,
            MMI_EVENT_EXPLICITLY_DELETED);
    }
    else
    {
        mmi_brw_app_file_system_error_handler(result);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_bookmark
 * DESCRIPTION
 *  This function is to launch the URL stored in the currently selected Bookmark
 * file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
    mmi_brw_app_pre_entry_goto_url();
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_edit_bookmark
 * DESCRIPTION
 *  This function is to copy the selected Bookmark content into buffers for
 * editing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_edit_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string((S8*) g_brw_current_title, 
        SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
        (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title);
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
    g_brw_bkm_add_type = BRW_BKM_ADD_BOOKMARK;
    mmi_brw_app_if_show_edit_bookmark_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_all_user_files
 * DESCRIPTION
 *  This function is to delete all the Bookmark files present in the Bookmark
 * root folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_all_user_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = 0;
    U8 array_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(array_index = 0; array_index < g_brw_bkm_cntx.total_file_count; array_index++)
    {
        if(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[array_index].actual_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
        {
            error_code = srv_brw_bkm_delete_bookmark(g_brw_bkm_cntx.bookmark_list[array_index].actual_index);
            if(error_code < 0)
            {
                break;
            }
        }
    }
    mmi_brw_app_create_bookmark_list();
    if (error_code >= 0)
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_GLOBAL_DELETED,
            MMI_EVENT_EXPLICITLY_DELETED);
    }
    else
    {
        mmi_brw_app_file_system_error_handler(error_code);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_add_bookmark
 * DESCRIPTION
 *  This function is to perform the tasks before displaying the ADD Bookmark
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_brw_app_check_available_bookmark_memory())
    {
        return;
    }

    memset(g_brw_current_title, 0, sizeof(g_brw_current_title));
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);

    g_brw_bkm_scr_id = mmi_frm_scrn_get_active_id();
    g_brw_bkm_add_type = BRW_BKM_ADD_BOOKMARK;

    /* Remove the Add Bookmark screen if present and its related editor common screens */
    mmi_frm_group_close(BRW_ADD_BOOKMARK_GRP_ID);
    mmi_brw_app_if_show_add_bookmark_screen();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_bookmark_file
 * DESCRIPTION
 *  This function is to delete the selected Bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_bookmark_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = srv_brw_bkm_delete_bookmark(g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index);
    if (error_code >= 0)
    {
        mmi_brw_app_create_bookmark_list();
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_GLOBAL_DELETED,
            MMI_EVENT_EXPLICITLY_DELETED);
    }
    else
    {
        mmi_brw_app_file_system_error_handler(error_code);
    }
    return;
}


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_set_bookmark_as_homepage
 * DESCRIPTION
 *  This function sets the currently selected bookmark url as homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_set_bookmark_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 url_ascii[SRV_BRW_MAX_URL_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) url_ascii, (S8*) g_brw_bkm_cntx.sel_file_url);
    mmi_brw_app_set_url_as_homepage(url_ascii);
}
#endif

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_create_folder
 * DESCRIPTION
 *  This func is used to perform the tasks before displaying the create folder
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_brw_app_check_available_bookmark_memory())
    {
        return;
    }
    g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type = BRW_BKM_FOLDER_CREATE;
    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));

    g_brw_display_info_str = (U8*)srv_brw_malloc((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) g_brw_display_info_str, "");

    mmi_brw_app_if_show_bookmarks_create_folder();
}
#endif


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_browse_path
 * DESCRIPTION
 *  This function is to perform the tasks before displaying the Browser path
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_browse_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlighting the first element on entering */
    g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index = 0;
    g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level = MMI_TRUE;
    g_brw_bkm_cntx.bkm_dynamic_cntx->selected_file_index = g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index;
    mmi_brw_app_if_show_bookmark_browse_path_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_browse_path_select_folder
 * DESCRIPTION
 *  This function is to perform the required task for which the Browse path
 * screen was displayed(Copy/Move) onthe selection of the Select Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_browse_path_select_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 actual_index, selected_file_index;
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO) &&
        !mmi_brw_app_check_available_bookmark_memory())
    {
        return;
    }
    actual_index = g_brw_bkm_cntx.bkm_dynamic_cntx->bookmark_list[g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index].actual_index;
    selected_file_index = g_brw_bkm_cntx.bkm_dynamic_cntx->selected_file_index;

    obj = (srv_brw_bookmark_file_struct*) OslMalloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));

    mmi_chset_utf8_to_ucs2_string((S8*) obj->file_name, 
        SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
        (S8*) g_srv_brw_cntx.bkm_cntx_p[selected_file_index].title);
    mmi_asc_to_ucs2((S8*) obj->file_url, (S8*) g_srv_brw_cntx.bkm_cntx_p[selected_file_index].url);
    if(!g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        strcpy((S8*)obj->parent_folder, (S8*)g_srv_brw_cntx.bkm_cntx_p[actual_index].title);
    }

    if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO)
    {
        obj->selected_bookmark_index = SRV_BRW_BKM_INVALID_INDEX;
        error_code = srv_brw_bookmark_validate_file_for_add(obj);
        if (error_code == SRV_BRW_BKM_ERROR_OK)
        {
            error_code = srv_brw_bookmark_add_item(obj);
        }
    }
    else
    {
        obj->selected_bookmark_index = selected_file_index;
        error_code = srv_brw_bookmark_validate_file_for_edit(obj);
        if (error_code == SRV_BRW_BKM_ERROR_OK)
        {
            error_code = srv_brw_bookmark_edit_item(obj, FALSE);
        }
    }
    OslMfree(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    if(error_code == SRV_BRW_BKM_ERROR_OK)
    {
        if(!g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
        {
            strcpy((S8*) g_brw_bkm_cntx.sel_folder_name, (S8*) g_srv_brw_cntx.bkm_cntx_p[actual_index].title);
        }
        else
        {
            g_brw_bkm_cntx.sel_folder_name[0] = '\0';
        }
        g_brw_bkm_cntx.sel_file_index = 0;
        mmi_brw_app_create_bookmark_list();
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BOOKMARK_BROWSE_PATH);
        return;
    }
    if(error_code == SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY ||
        error_code < 0)
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BOOKMARK_BROWSE_PATH);
        return;
    }
    if(error_code == SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS)
    {
        
        mmi_brw_app_browse_path_replace_file_confirm();
        return;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_bookmark
 * DESCRIPTION
 *  This function is to add a new bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));
    mmi_ucs2ncpy((S8*)obj->file_name, (S8*)g_brw_current_title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*)obj->file_url, (S8*)g_brw_current_url, SRV_BRW_MAX_URL_LEN);
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if(g_brw_bkm_add_type != BRW_BKM_ADD_TO_BOOKMARK)
    {
        strcpy((S8*)obj->parent_folder, (S8*)g_brw_bkm_cntx.sel_folder_name);
    }
#endif
#endif
    obj->selected_bookmark_index = SRV_BRW_BKM_INVALID_INDEX;

    error_code = srv_brw_bookmark_validate_file_for_add(obj);
    if (error_code == SRV_BRW_BKM_ERROR_OK)
    {
        error_code = srv_brw_bookmark_add_item(obj);
    }
    srv_brw_free(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    if(error_code == SRV_BRW_BKM_ERROR_OK)
    {
        mmi_brw_app_create_bookmark_list();
        cui_inline_close(g_brw_app_cntx.brw_inline_cid);
        return;
    }
    
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    if(error_code == SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY ||
        error_code < 0)
    {
        cui_inline_close(g_brw_app_cntx.brw_inline_cid);
        return;
    }
#endif

#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    if(error_code == SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS)
    {
        mmi_brw_app_add_bookmark_replace_file_confirm();
        return;
    }
#endif
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_bookmark_replace_file
 * DESCRIPTION
 *  This function is to replace and existing bookmark with a new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_bookmark_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    U8 file_path[(SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));
    mmi_ucs2ncpy((S8*)obj->file_name, (S8*)g_brw_current_title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*)obj->file_url, (S8*)g_brw_current_url, SRV_BRW_MAX_URL_LEN);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if(g_brw_bkm_add_type != BRW_BKM_ADD_TO_BOOKMARK)
    {
        strcpy((S8*)obj->parent_folder, (S8*)g_brw_bkm_cntx.sel_folder_name);
    }
#endif
    obj->selected_bookmark_index = SRV_BRW_BKM_INVALID_INDEX;

    error_code = srv_brw_bookmark_add_replace_item(obj);
    srv_brw_free(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    mmi_brw_app_create_bookmark_list();
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_edit_bookmark
 * DESCRIPTION
 *  Function to edit the contents of a bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_edit_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    MMI_BOOL internal_format = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));
    mmi_ucs2ncpy((S8*)obj->file_name, (S8*)g_brw_current_title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*)obj->file_url, (S8*)g_brw_current_url, SRV_BRW_MAX_URL_LEN);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    strcpy((S8*)obj->parent_folder, (S8*)g_brw_bkm_cntx.sel_folder_name);
#endif
    obj->selected_bookmark_index = g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index;

    error_code = srv_brw_bookmark_validate_file_for_edit(obj);
    if (error_code == SRV_BRW_BKM_ERROR_OK)
    {
        error_code = srv_brw_bookmark_edit_item(obj, internal_format);
    }

    srv_brw_free(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    if(error_code <= 0 && error_code != FS_INVALID_FILENAME)
    {
        mmi_brw_app_create_bookmark_list();
        cui_inline_close(g_brw_app_cntx.brw_inline_cid);
        mmi_frm_group_close(BRW_OPEN_BOOKMARKS_FROM_FMGR_GRP_ID);
    }
    if(error_code == SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS)
    {
        mmi_brw_app_edit_bookmark_replace_file_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_edit_bookmark_replace_file
 * DESCRIPTION
 *  This function is to replace and existing bookmark with a new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_edit_bookmark_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    MMI_BOOL internal_format = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));
    mmi_ucs2ncpy((S8*)obj->file_name, (S8*)g_brw_current_title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*)obj->file_url, (S8*)g_brw_current_url, SRV_BRW_MAX_URL_LEN);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    strcpy((S8*)obj->parent_folder, (S8*)g_brw_bkm_cntx.sel_folder_name);
#endif
    obj->selected_bookmark_index = g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index;

    error_code = srv_brw_bookmark_edit_replace_item(obj, internal_format);
    srv_brw_free(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    // TODO CHECK
    mmi_brw_app_create_bookmark_list();
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_group_close(BRW_OPEN_BOOKMARKS_FROM_FMGR_GRP_ID);
}
#endif /* #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__ */


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_create_bookmark_folder
 * DESCRIPTION
 *  This function is to create or rename a bookmark folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_create_bookmark_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_folder_struct *obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (srv_brw_bookmark_folder_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_folder_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_folder_struct));

    if (g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type == SRV_BRW_BKM_FOLDER_CREATE)
    {
        mmi_ucs2ncpy((S8*)obj->folder_name, (S8*)g_brw_display_info_str, SRV_BRW_MAX_TITLE_LENGTH);
        obj->selected_folder_index = SRV_BRW_BKM_INVALID_INDEX;
    }
    else
    {
        mmi_ucs2ncpy((S8*)obj->folder_name, (S8*)g_brw_display_info_str, SRV_BRW_MAX_TITLE_LENGTH);
        obj->selected_folder_index = g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index;
    }

    error_code = srv_brw_bookmark_validate_folder(obj, g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type);
    if (error_code == SRV_BRW_BKM_ERROR_OK)
    {
        error_code = srv_brw_bookmark_create_folder(obj, g_brw_bkm_cntx.bkm_dynamic_cntx->folder_op_type);
    }
    srv_brw_free(obj);
    if(error_code == SRV_BRW_BKM_ERROR_OK)
    {
        if(g_brw_bkm_browse_path_event != BRW_BKM_BROWSE_PATH_NONE)
        {
            mmi_brw_app_create_bookmark_folders_list();
        }
        mmi_brw_app_create_bookmark_list();
        mmi_brw_app_handle_bookmark_error_code(SRV_BRW_BKM_ERROR_FOLDER_CREATED);
        cui_filename_editor_close(g_brw_app_cntx.file_naming_rule_cid);
    }
    else
    {
        mmi_brw_app_handle_bookmark_error_code(error_code);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_save_to_bookmark
 * DESCRIPTION
 *  This function is to save a file to bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bookmark_file_struct *obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_brw_app_check_available_bookmark_memory())
    {
        cui_inline_close(g_brw_app_cntx.brw_inline_cid);
        return;
    }
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));
    mmi_ucs2ncpy((S8*)obj->file_name, (S8*)g_brw_ext_bkm_cntx_p->bookmark_name, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    mmi_ucs2ncpy((S8*)obj->file_url, (S8*)g_brw_ext_bkm_cntx_p->bookmark_url, SRV_BRW_MAX_URL_LEN);
    obj->selected_bookmark_index = SRV_BRW_BKM_INVALID_INDEX;
    srv_brw_bookmarks_modify_file_for_save(obj->file_name, SRV_BRW_ROOT_PARENT_INDEX);
    error_code = srv_brw_bookmark_add_item(obj);
    srv_brw_free(obj);
    mmi_brw_app_handle_bookmark_error_code(error_code);
    if(error_code == SRV_BRW_BKM_ERROR_OK)
    {
        mmi_vbkm_clean_one_file_buffer();
        mmi_frm_group_close(BRW_RECV_BOOKMARKS_GRP_ID);
    }
    else
    {
        cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    }
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_select_bookmark_open_folder
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_select_bookmark_open_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 current_file_count = 0;
    srv_brw_bkm_bookmark_list_struct bookmark_list[SRV_BRW_BKM_MAX_COUNT];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_file_count = g_brw_bkm_sel_bkm_cntx.total_file_count;
    memcpy(bookmark_list, g_brw_bkm_sel_bkm_cntx.bookmark_list, SRV_BRW_BKM_MAX_COUNT);

    strcpy((S8*) g_brw_bkm_sel_bkm_cntx.sel_folder_name, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[g_brw_bkm_sel_bkm_cntx.sel_file_index].actual_index].title);
    mmi_brw_app_create_select_bookmark_list();

    if (g_brw_bkm_sel_bkm_cntx.total_file_count)
    {
        /* highlighting the first element on entering */
        g_brw_bkm_sel_bkm_cntx.sel_file_index = 0;

        /* here it is used for highlighting the default menu item */
        mmi_brw_app_if_show_browser_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        g_brw_bkm_sel_bkm_cntx.total_file_count = current_file_count;
        memcpy(g_brw_bkm_sel_bkm_cntx.bookmark_list, bookmark_list, SRV_BRW_BKM_MAX_COUNT);
        g_brw_bkm_sel_bkm_cntx.sel_folder_name[0] = '\0';
        mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_select_bookmark_done
 * DESCRIPTION
 *  This function is to send the file selected by the user in the select 
 * Bookmark screen to the module that invoked the select bookmark operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_select_bookmark_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) g_brw_current_title, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[g_brw_bkm_sel_bkm_cntx.sel_file_index].actual_index].title);
    strcpy((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[g_brw_bkm_sel_bkm_cntx.sel_file_index].actual_index].url);
    mmi_brw_sel_bkm_send_result(EVT_ID_CUI_BKM_SEL_BKM_RESULT, g_brw_current_url, g_brw_current_title);
    return;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_bookmark_memory_status
 * DESCRIPTION
 *  This function is to get the Bookmarks memory status to be displayed in the
 * view screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_get_bookmark_memory_status(U8* output_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *avail_str;
    U8 *alloc_str;
    U8 *total_str;
    U8 *str_p;
    U8 temp_str[BRW_MEMORY_STATUS_MSG_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(output_str);
    str_p = (U8*) GetString(STR_ID_BRW_AVAILABLE);
    avail_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) avail_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_ALLOCATED);
    alloc_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) alloc_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_TOTAL);
    total_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) total_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    sprintf(
        (S8*) temp_str,
        "%s %d \n%s %d \n%s %d ",
        avail_str,
        SRV_BRW_BKM_MAX_COUNT - g_srv_brw_cntx.bookmark_count,
        alloc_str,
        g_srv_brw_cntx.bookmark_count,
        total_str,
        SRV_BRW_BKM_MAX_COUNT);

    mmi_chset_utf8_to_ucs2_string((U8*) output_str, BRW_MEMORY_STATUS_MSG_LEN + 1, (U8*) temp_str);

    OslMfree(avail_str);
    OslMfree(alloc_str);
    OslMfree(total_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_bookmark_options
 * DESCRIPTION
 *  This is the Pre Entry function for bookmark options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_bookmark_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_browse_path_event = BRW_BKM_BROWSE_PATH_NONE;
    mmi_brw_app_if_show_bookmark_options_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_bookmark_options_parent_menu
 * DESCRIPTION
 *  This function is to get the parent menu item of the menu tree that will be
 * displayed in the bookmark options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_dmgr_get_bookmark_options_parent_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_types_enum selected_file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_cntx.total_file_count)
    {
        selected_file_type = g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].type;
        if(selected_file_type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
        {
            return MENU_ID_BRW_BKM_OPTIONS_FOR_USER_FILE;
        }
        else if(selected_file_type == SRV_BRW_BKM_TYPE_DEFAULT_FILE)
        {
            return MENU_ID_BRW_BKM_OPTIONS_FOR_DEFAULT_FILE;
        }
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        else if(selected_file_type == SRV_BRW_BKM_TYPE_FOLDER)
        {
            return MENU_ID_BRW_BKM_OPTIONS_FOR_FOLDER;
        }
#endif
    }
    return MENU_ID_BRW_BKM_OPTIONS_FOR_EMPTY_FOLDER;
}
#endif /* __MMI_VBOOKMARK__ */


#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_add_to_bookmark_from_fmgr
 * DESCRIPTION
 *  This function is used to save the selected vbookmark file into bookmark
 *  application invoked from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_to_bookmark_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = srv_brw_bkm_initialize_bookmark_context();
    if (error_code < 0)
    {
        srv_brw_bkm_deinitialize_bookmark_context();
        mmi_brw_app_file_system_error_handler(error_code);
        return;
    }

    if (!mmi_brw_app_check_available_bookmark_memory())
    {
        return;
    }
    mmi_ucs2cpy((S8*) g_brw_current_title, (S8*) g_brw_ext_bkm_cntx_p->bookmark_name);
    mmi_ucs2cpy((S8*) g_brw_current_url, (S8*) g_brw_ext_bkm_cntx_p->bookmark_url);
    mmi_brw_app_dmgr_add_to_bookmark();
}
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_view_bookmark_str
 * DESCRIPTION
 *  This func is used for displaying the bookmark details
 * PARAMETERS
 *  msg_str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_get_view_bookmark_str(U8 *msg_str, U8* title, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *bkm_title_str;
    U8 *bkm_url_str;
    U8 temp_str[BRW_VIEW_BOOKMARK_STR_LEN + 1];
    U8 *str_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = (U8*) GetString(STR_ID_BRW_NAME);
    bkm_title_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) bkm_title_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_GLOBAL_ADDRESS);
    bkm_url_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) bkm_url_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    memset(temp_str, 0, BRW_VIEW_BOOKMARK_STR_LEN + 1);

    sprintf(
        (S8*) temp_str,
        "%s:\n%s\n\n%s:\n%s",
        bkm_title_str,
        title,
        bkm_url_str,
        url);

    mmi_chset_utf8_to_ucs2_string((U8*) msg_str, BRW_VIEW_BOOKMARK_STR_LEN + 1, (U8*) temp_str);

    OslMfree(bkm_title_str);
    OslMfree(bkm_url_str);
}


/***********************************BOOKMARK END*****************************/


/*******************************MISCELLANEOUS********************************/
#ifdef __MMI_OP12_BRW_SEARCH_MENU__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_open_search_web
 * DESCRIPTION
 *  Entry function for Search menu on the Internet Services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_open_search_web(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_brw_current_url, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((S8*) g_brw_current_url, (S8*) WAP_CUSTOM_CFG_SEARCH_WEB_URL, SRV_BRW_MAX_URL_LEN);
    mmi_brw_app_pre_entry_goto_url();
}
#endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_open_homepage
 * DESCRIPTION
 *  This function is to launch the homepage URL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_open_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/****************** service api to get prof contents **************/
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    if (g_srv_brw_cntx.homepage_setting == SRV_BRW_HOMEPAGE_SETTING_DEFAULT)
#endif
    {
        CHAR *url_ascii;
    #ifdef __MMI_WLAN_FEATURES__
        if(g_brw_app_cntx.brw_dynamic_cntx_p->is_using_wifi)
        {
            url_ascii = (CHAR*)srv_wap_prof_get_homepage(srv_brw_convert_sim_setting_to_profile_sim_id(SRV_BRW_ACTIVE_SIM_SETTING_WLAN), SRV_WAP_PROF_APPID_BRW, (U8) - 1);
        }
        else
    #endif
        {
            url_ascii = (CHAR*)srv_wap_prof_get_homepage(srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id), SRV_WAP_PROF_APPID_BRW, (U8) - 1);
        }
        mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) url_ascii);
        OslMfree(url_ascii);
    }
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    else
    {
        U8* url_ascii;
        url_ascii = (U8*) srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
        memset(url_ascii, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
        srv_brw_get_user_defined_homepage(url_ascii);
        mmi_asc_n_to_ucs2((S8*) g_brw_current_url, (S8*) url_ascii, SRV_BRW_MAX_URL_LEN);
        srv_brw_free(url_ascii);
    }
#endif
    if (srv_brw_validate_url(g_brw_current_url, WAP_MAX_SEARCH_URL_LENGTH) < 0)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
        return;
    }
    mmi_brw_app_pre_entry_goto_url();
}


#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_last_web_address
 * DESCRIPTION
 *  This function is used for launching last web address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_last_web_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *last_web_address;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_web_address = (U8*) srv_brw_malloc(SRV_BRW_LAST_WEB_ADDR_LENGTH);
    memset(last_web_address, 0, SRV_BRW_LAST_WEB_ADDR_LENGTH);

    srv_brw_read_last_web_address(last_web_address);
    if (strlen((S8*) last_web_address) == 0)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)last_web_address);
        mmi_brw_app_pre_entry_goto_url();
    }
    srv_brw_free(last_web_address);
}
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */


#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_embedded_link
 * DESCRIPTION
 *  to launch the embedded link
 * PARAMETERS
 *  void
 *  item_index(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_embedded_link(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_brw_current_url, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) wap_embed_link_default.embed_link[g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item - g_brw_app_cntx.brw_dynamic_cntx_p->fixed_menu_items].embed_link_url);
    mmi_brw_app_pre_entry_goto_url();
}
#endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */
/*****************************MISCELLANEOUS END******************************/


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************RECENT PAGES START*****************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_recent_pages_url
 * DESCRIPTION
 *  This function is to launch the URL of the selected recent page in the 
 * recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_recent_pages_url(void)
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
        g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_RECENT_PAGE;
        return;
    }
    else if (ret == CBM_OK)
    {
        mmi_brw_app_srv_hdlr_open_recent_page();
        mmi_brw_app_pre_entry_render_page();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_recent_page
 * DESCRIPTION
 *  This function is to send the delete request to the service for deleting 
 * the selected recent page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_show_progress_screen(STR_ID_BRW_RECENT_PAGES, STR_GLOBAL_DELETING);
    obj.rsp_callback = mmi_brw_srv_hdlr_delete_recent_page;
    data.index = srv_brw_recent_page_get_actual_index(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    obj.req_data = (void*)&data;

    srv_brw_delete_recent_page_req(&obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_all_recent_pages
 * DESCRIPTION
 *  This function is to delete all the recent pages present. In Q05A it could
 * also be used to delete all the recent pages item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_all_recent_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_show_progress_screen(STR_ID_BRW_RECENT_PAGES, STR_GLOBAL_DELETING);

    obj.rsp_callback = mmi_brw_srv_hdlr_delete_all_recent_page;
    srv_brw_delete_all_recent_pages_req(&obj);
}


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_set_as_homepage
 * DESCRIPTION
 *  This func is used for setting the selected URL as the current homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_brw_app_dmgr_set_recent_page_url_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_url_as_homepage((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->url);
}
#endif

#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_recent_page_list_item_to_bookmark
 * DESCRIPTION
 *  This function is to invoke the add to bookmark operation for adding an
 * recent pages list entry by passing all the required data
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_brw_app_dmgr_add_recent_page_list_item_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_title,
        (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->title);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->url);

    mmi_brw_app_dmgr_add_to_bookmark();
}
#endif /* __MMI_VBOOKMARK__ */ 
#endif

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_open_recent_page_host
 * DESCRIPTION
 *  This function is to invoke the add to bookmark operation for adding an
 * recent pages list entry by passing all the required data
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_brw_app_dmgr_open_recent_page_host(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_create_recent_page_list_for_selected_host(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    mmi_brw_app_if_show_recent_pages_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_recent_host
 * DESCRIPTION
 * This function is to invoke the Browser service for deleting the selected
 * recent pages host
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_recent_host(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_show_progress_screen(STR_ID_BRW_RECENT_HOSTS, STR_GLOBAL_DELETING);
    srv_brw_delete_recent_host_req(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item, mmi_brw_srv_hdlr_delete_recent_page);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_sort_recent_page_by_site
 * DESCRIPTION
 *  This func is used for sorting the recent pages in site wise order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_sort_recent_page_by_site(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_update_recent_page_sorting_method(WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_sort_recent_page_by_last_visited
 * DESCRIPTION
 *  This func is used for sorting the recent pages in last visited order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_sort_recent_page_by_last_visited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_update_recent_page_sorting_method(WAP_BAM_RECENT_PAGE_SORT_OPTION_LAST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_sort_recent_page_by_most_visited
 * DESCRIPTION
 *  This func is used for sorting the recent pages in most visited order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_sort_recent_page_by_most_visited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_update_recent_page_sorting_method(WAP_BAM_RECENT_PAGE_SORT_OPTION_FREQ);
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_recent_page_options
 * DESCRIPTION
 *  Pre Entry function for stored pages list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_recent_page_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlighted item must be filled up before this */
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p));
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    mmi_brw_app_show_progress_screen(STR_ID_BRW_RECENT_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_recent_page;
    data.index = srv_brw_recent_page_get_actual_index(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    obj.req_data = (void*)&data;
    srv_brw_get_recent_page_req(&obj);    
}

/******************************RECENT PAGES END******************************/
#endif


/****************************RENDERED PAGES START****************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendered_page_edit
 * DESCRIPTION
 *  This is the function to take some action on the selection of an edit
 *  item on the rendered page and notify the BAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendered_page_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p);
#ifdef OBIGO_Q03C_BROWSER
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching == MMI_TRUE)
    {
        mmi_brw_app_pre_entry_render_page();
        return;
    }
#endif /* OBIGO_Q03C_BROWSER */

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type == WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT
#ifdef OBIGO_Q03C_BROWSER
        || g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type == WAP_BAM_FOCUSED_ELEMENT_SELECT
#endif /* OBIGO_Q03C_BROWSER */
       )
    {
        /* showing the temporary busy screen */
        mmi_brw_app_set_progress_screen_params(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
        mmi_brw_app_if_show_temp_progressing_screen();
    }
    else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type == WAP_BAM_FOCUSED_ELEMENT_SELECT)
    {
        mmi_brw_app_pre_entry_render_page();
    }
    else
    {
        mmi_brw_app_pre_entry_render_page();
    }
    bam_activate_browser_input();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendered_page_reset
 * DESCRIPTION
 *  This is the request function to take some action on the selection of a reset
 *  item on the rendered page and to notify BAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendered_page_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_activate_browser_input();
    mmi_brw_app_pre_entry_render_page();
}


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendered_page_select_file
 * DESCRIPTION
 *  This is the request function to take some action on the selection of an
 *  select file item on rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendered_page_select_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_activate_browser_input();
    mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
}
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendered_page_select_mode
 * DESCRIPTION
 *  This is the request function to take some action on the selection of the
 *  select Mode menu in rendered page options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendered_page_select_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    if (g_srv_brw_cntx.rendering_mode == wap_bam_setting_val_rend_text
        || g_srv_brw_cntx.navigation_mode == wap_bam_setting_val_nav_scroll)
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_ID_BRW_FUNCTION_NOT_ALLOWED,
            MMI_EVENT_ERROR);
        return;
    }
#endif /* OBIGO_Q05A */
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }

    mmi_brw_app_select_mode_confirm();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_activate_select_mode
 * DESCRIPTION
 *  This function is used for activating the picture select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_activate_select_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag = MMI_TRUE;

    srv_brw_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_this_link
 * DESCRIPTION
 *  This function is used for fetching the currently selected link on the
 *  rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_this_link(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_activate_browser_input();
    mmi_brw_app_pre_entry_render_page();
}


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_set_as_homepage
 * DESCRIPTION
 *  This function is used for setting the current page URL
 *  as the new homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_brw_app_dmgr_set_this_page_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_url_as_homepage((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
}
#endif

#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_this_page_to_bookmark
 * DESCRIPTION
 *  This function is used for adding the opened page as a bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_this_page_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    if(strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title) == 0)
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) g_brw_current_title,
            (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
    }
    else
#endif
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) g_brw_current_title,
            (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
    }
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);

    mmi_brw_app_dmgr_add_to_bookmark();
}
#endif /* __MMI_VBOOKMARK__ */ 


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_store_this_page
 * DESCRIPTION
 *  This function is to invoke the interface function of the full screen 
 * editor to store the currently opened page into offline memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_store_this_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }

    if (g_brw_display_info_str)
    {
        srv_brw_free_browser_memory((void**)&(g_brw_display_info_str));
	}
    g_brw_display_info_str = (U8*)srv_brw_malloc((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_display_info_str,
        (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);

    mmi_brw_app_if_show_edit_store_offline_screen();
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_this_page_properties
 * DESCRIPTION
 *  This function is the pre entry function to display the current page
 * properties screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_this_page_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_size[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p);

    mmi_brw_app_reset_object_properties();

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name,
        (BRW_OBJECT_PROPERTIES_NAME_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_ADDRESS] = MMI_TRUE;
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_address,
        (BRW_OBJECT_PROPERTIES_ADDRESS_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->document_bytes_total > 0)
    {
        srv_brw_convert_int_to_unicode_string(
            (U8*) page_size,
            (U32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->document_bytes_total);
        mmi_ucs2cat((S8*) page_size, (S8*) L" ");
        mmi_ucs2cat((S8*) page_size, (S8*) get_string(STR_ID_BRW_BYTES));
    }
    else
    {
        mmi_ucs2cpy((S8*) page_size, (S8*) get_string(STR_ID_BRW_UNKNOWN));
    }

    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size, (S8*) page_size);
    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_count = BRW_THIS_PAGE_PROPERTIES_COUNT;

    mmi_brw_app_if_show_object_properties_screen();
}
#endif /*#ifdef OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_select_mode_save_as
 * DESCRIPTION
 *  This function sends the request for saving the selected object
 *  in picture select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_select_mode_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    srv_brw_ren_page_object_action_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_select_mode_exit
 * DESCRIPTION
 *  This function sends the request to service for exiting from the picture 
 * select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_select_mode_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag = FALSE;
#ifdef OBIGO_Q03C_BROWSER
    srv_brw_clear_focused_element();
#endif /* OBIGO_Q03C_BROWSER */
    srv_brw_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE);
    if(mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN))
    {
        //TODO CHeCK GoBackToHistory(SCR_ID_BRW_BROWSER_MAIN);
        mmi_frm_scrn_close_active_id();
    }
}

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_save_page_object
 * DESCRIPTION
 *  This function is used for saving a selected page object in the page objects
 * list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_save_page_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }

    srv_brw_activate_resource_req(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_refresh_page
 * DESCRIPTION
 *  This function is used for sending the reload request to the service for 
 * refetching of the page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_refresh_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_pre_entry_render_page();

#ifdef OBIGO_Q03C_BROWSER
    if(g_brw_app_cntx.brw_dynamic_cntx_p->reload_req_processing)
    {
        return;
    }
    g_brw_app_cntx.brw_dynamic_cntx_p->reload_req_processing = MMI_TRUE;
#endif
    srv_brw_reload_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_navigate_forward
 * DESCRIPTION
 *  This function is used for sending the forward navigation request to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_navigate_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_navigate_req(WAP_BAM_MOVE_FORWARD);
    mmi_brw_app_pre_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_navigate_backward
 * DESCRIPTION
 *  This function is used for sending the backward navigation request to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_navigate_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_navigate_req(WAP_BAM_MOVE_BACKWARD);
    mmi_brw_app_pre_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_ren_page_options_parent_menu
 * DESCRIPTION
 *  This function is used for getting the parent menu item of the menu tree
 * to be displayed in the rendered page options menu depending on the select
 * mode or normal mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_dmgr_get_ren_page_options_parent_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->select_mode_flag == MMI_TRUE)
    {
        return MENU_ID_BRW_SELECT_MODE_OPTIONS;
    }
    else
    {
        return MENU_ID_BRW_RENDERED_PAGE_OPTIONS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_page_objects_save_as
 * DESCRIPTION
 *  This function sends the request for saving the selected object
 *  in picture select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_page_objects_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    srv_brw_ren_page_object_action_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_select_mode_image_properties
 * DESCRIPTION
 *  Pre entry function to display image properties screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_select_mode_image_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 page_size[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p);

    mmi_brw_app_reset_object_properties();

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name,
        (BRW_OBJECT_PROPERTIES_NAME_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->title);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->size > 0)
    {
        srv_brw_convert_int_to_unicode_string((U8*) page_size, (U32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->size);
        mmi_ucs2cat((S8*) page_size, (S8*) L" ");
        mmi_ucs2cat((S8*) page_size, (S8*) get_string(STR_ID_BRW_BYTES));
    }
    else
    {
        mmi_ucs2cpy((S8*) page_size, (S8*) get_string(STR_ID_BRW_UNKNOWN));
    }
    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size, (S8*) page_size);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_count = BRW_SELECT_MODE_IMAGE_PROP_COUNT;

    mmi_brw_app_if_show_object_properties_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_page_object_properties
 * DESCRIPTION
 *  Pre entry function for displaying properties of the selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_page_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_size[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p);

    mmi_brw_app_reset_object_properties();

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name,
        (BRW_OBJECT_PROPERTIES_NAME_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->title);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->size > 0)
    {
        srv_brw_convert_int_to_unicode_string((U8*) page_size, (U32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->size);
        mmi_ucs2cat((S8*) page_size, (S8*) L" ");
        mmi_ucs2cat((S8*) page_size, (S8*) get_string(STR_ID_BRW_BYTES));
    }
    else
    {
        mmi_ucs2cpy((S8*) page_size, (S8*) get_string(STR_ID_BRW_UNKNOWN));
    }

    mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size, (S8*) page_size);

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_count = BRW_PAGE_OBJECT_PROPERTIES_COUNT;

    mmi_brw_app_if_show_object_properties_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_page_object_options
 * DESCRIPTION
 *  This function sends the request for saving the selected object
 *  in picture select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_page_object_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    U16 hilited_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p));
    hilited_index = GetHighlightedItem();
    mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_page_objects;
    data.index = srv_brw_page_objects_get_actual_index(hilited_index);
    obj.req_data = (void*)&data;
    srv_brw_get_resource_req(&obj);
}

#endif /* OBIGO_Q05A */
/*****************************RENDERED PAGES END*****************************/


/*******************************SETTINGS START*******************************/
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_thumbnail_status
 * DESCRIPTION
 *  This function is used for updating the thumbnail status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_thumbnail_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.thumbnail_status == wap_bam_setting_val_thumb_enable)
    {
        g_srv_brw_cntx.thumbnail_status = wap_bam_setting_val_thumb_disable;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        g_srv_brw_cntx.thumbnail_status = wap_bam_setting_val_thumb_enable;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_GLOBAL_ON));
    }
    RedrawCategoryFunction();
    srv_brw_change_setting_value_req(
        wap_bam_setting_value_type_int,
        wap_bam_setting_id_thumbnail,
        g_srv_brw_cntx.thumbnail_status,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_screen_size
 * DESCRIPTION
 *  This function is used for changing the screen size value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_screen_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.screen_size_status)
    {
        g_srv_brw_cntx.screen_size_status = MMI_FALSE;
        ChangeLeftSoftkey(STR_ID_BRW_FULL, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_GLOBAL_NORMAL));
    }
    else
    {
        g_srv_brw_cntx.screen_size_status = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_NORMAL, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_ID_BRW_FULL));
    }
    // update screen size in NVRAM
    RedrawCategoryFunction();
    mmi_brw_app_resize_screen_req();
}
#endif /* OBIGO_Q05A */
#ifdef __BAIDU_TRANSCODING_SUPPORT__
void mmi_brw_app_dmgr_switch_off_baidu_proxy(void)
{
    g_srv_brw_cntx.baidu_proxy_status = 0;
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
    srv_brw_change_setting_value_req(
	wap_bam_setting_value_type_int,
	wap_bam_setting_id_transcode_proxy,
	g_srv_brw_cntx.baidu_proxy_status,
	NULL);
}

void mmi_brw_app_dmgr_user_confirm_baidu_proxy(void)
{
    g_srv_brw_cntx.baidu_proxy_status = MMI_TRUE;
    
    mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_GLOBAL_ON));
    RedrawCategoryFunction();
    ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
    srv_brw_change_setting_value_req(
        wap_bam_setting_value_type_int,
        wap_bam_setting_id_transcode_proxy,
        g_srv_brw_cntx.baidu_proxy_status,
        NULL);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_baidu_proxy_status
 * DESCRIPTION
 *  This function is used for changing the screen size value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_baidu_proxy_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.baidu_proxy_status)
    {
        g_srv_brw_cntx.baidu_proxy_status = MMI_FALSE;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*) GetString(STR_GLOBAL_OFF));
        // update screen size in NVRAM
        RedrawCategoryFunction();
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
        srv_brw_change_setting_value_req(
            wap_bam_setting_value_type_int,
            wap_bam_setting_id_transcode_proxy,
            g_srv_brw_cntx.baidu_proxy_status,
            NULL);
    }
    else
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_BAIDU_PROXY_USER_CONFIRM));
        //mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

        mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_user_confirm_baidu_proxy, mmi_frm_scrn_close_active_id, MMI_FALSE);
        
    }
    
}
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__

#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_9way_mode
 * DESCRIPTION
 *  This function is used for changing the 9 way navigation mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_9way_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.nine_way_mode = !g_brw_app_cntx.nine_way_mode;

    srv_brw_change_setting_value_req(
        wap_bam_setting_value_type_int,
        wap_bam_setting_id_9way,
        g_brw_app_cntx.nine_way_mode,
        NULL);

    mmi_brw_app_ui_draw_display_popup_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendering_modes_standard
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendering_modes_standard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_rendering_mode(wap_bam_setting_val_rend_normal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendering_modes_text_wrap
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendering_modes_text_wrap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_rendering_mode(wap_bam_setting_val_rend_wrap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendering_modes_screen_optimized
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendering_modes_screen_optimized(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_rendering_mode(wap_bam_setting_val_rend_narrow);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rendering_modes_text_only
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rendering_modes_text_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_rendering_mode(wap_bam_setting_val_rend_text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_navigation_modes_four_way
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_navigation_modes_four_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_navigation_mode(wap_bam_setting_val_nav_4_way);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_navigation_modes_two_way
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_navigation_modes_two_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_navigation_mode(wap_bam_setting_val_nav_2_way);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_navigation_modes_scrolling
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_navigation_modes_scrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_navigation_mode(wap_bam_setting_val_nav_scroll);
}


#ifdef __MMI_VECTOR_FONT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_font_size_small
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_font_size_small(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_font_size(BRW_FONT_SIZE_SMALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_font_size_medium
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_font_size_medium(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_font_size(BRW_FONT_SIZE_MEDIUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_font_size_large
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_brw_app_dmgr_font_size_large(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_font_size(BRW_FONT_SIZE_LARGE);
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_read_browser_preferences_struct
 * DESCRIPTION
 *  This function is to read the changes made by the user in the preferences 
 * screen to save those changes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_read_browser_preferences_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /****************** Time Out ******************/

   /****************** Show Images ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_NEVER_INDEX)
    {
        g_srv_brw_cntx.show_images_status = wap_bam_setting_val_images_never;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT  - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ALWAYS_INDEX)
    {
        g_srv_brw_cntx.show_images_status = wap_bam_setting_val_images_always;
    }
   /****************** Show Images ******************/

#ifdef OBIGO_Q05A

   /****************** Show Videos ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_NEVER_INDEX)
    {
        g_srv_brw_cntx.show_videos_status = wap_bam_setting_val_movies_never;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ALWAYS_INDEX)
    {
        g_srv_brw_cntx.show_videos_status = wap_bam_setting_val_movies_always;
    }
   /****************** Show Videos ******************/

   /****************** Play Sounds ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_NEVER_INDEX)
    {
        g_srv_brw_cntx.play_sounds_status = wap_bam_setting_val_sounds_never;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ALWAYS_INDEX)
    {
        g_srv_brw_cntx.play_sounds_status = wap_bam_setting_val_sounds_always;
    }
   /****************** Play Sounds ******************/

   /****************** Load Unknown Media ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_NEVER_INDEX)
    {
        g_srv_brw_cntx.load_unknown_media_status = wap_bam_setting_val_no_mime_never;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ALWAYS_INDEX)
    {
        g_srv_brw_cntx.load_unknown_media_status = wap_bam_setting_val_no_mime_always;
    }
   /****************** Load Unknown Media ******************/

   /****************** CSS ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.css_status = wap_bam_setting_val_css_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.css_status = wap_bam_setting_val_css_enable;
    }
   /****************** CSS ******************/

   /****************** Script ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.script_status = wap_bam_setting_val_script_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.script_status = wap_bam_setting_val_script_enable;
    }
   /****************** Script ******************/

#endif /* OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
    /****************** Cache ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.cache_status = wap_bam_setting_val_cache_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.cache_status = wap_bam_setting_val_cache_enable;
    }
   /****************** Cache ******************/
#endif

   /****************** Cookie ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.cookie_status = wap_bam_setting_val_cookies_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.cookie_status = wap_bam_setting_val_cookies_enable;
    }
   /****************** Cookie ******************/

#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
   /****************** Shortcuts ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.shortcuts_status = wap_bam_setting_val_shortcuts_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.shortcuts_status = wap_bam_setting_val_shortcuts_enable;
    }
   /****************** Shortcuts ******************/
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
   /****************** Security Warnings ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.security_warnings_status = wap_bam_setting_val_sec_warning_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.security_warnings_status = wap_bam_setting_val_sec_warning_enable;
    }
   /****************** Security Warnings ******************/
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
   /****************** Send Device ID ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.send_device_id_status = wap_bam_setting_val_imei_disable;
    }
    else if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_ENABLE_INDEX)
    {
        g_srv_brw_cntx.send_device_id_status = wap_bam_setting_val_imei_enable;
    }
   /****************** Send Device ID ******************/
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
   /****************** Send Device ID ******************/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT - CUI_INLINE_ITEM_ID_BASE)] == BRW_PREF_DISABLE_INDEX)
    {
        g_srv_brw_cntx.post_session_info_status = MMI_FALSE;
    }
    else
    {
        g_srv_brw_cntx.post_session_info_status = MMI_TRUE;
    }
   /****************** Send Device ID ******************/
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_save_browser_preferences
 * DESCRIPTION
 *  This function is to save the changes made by the user in the Browser
 * Preferences screen and send the set profile req to BAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_save_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 time_out_val;
    S8 str_value[20];
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(str_value, (S8*) g_brw_app_cntx.brw_dynamic_cntx_p->BrwTimeoutValue);
    time_out_val = atoi(str_value);
    //mmi_frm_scrn_close_active_id();
    if (time_out_val < BRW_TIME_OUT_MIN_VAL || time_out_val > BRW_TIME_OUT_MAX_VAL)
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_ID_BRW_INVAL_TIMEOUT,
            MMI_EVENT_PROPLEM);
        return;
    }

    g_srv_brw_cntx.timeout_value = time_out_val;

    // TODO read the inline structure
    mmi_brw_app_dmgr_read_browser_preferences_struct();
    mmi_brw_app_dmgr_write_browser_preferences();
    
    /* showing the busy screen */
    mmi_brw_app_show_progress_screen(STR_ID_BRW_PREFERENCES, STR_GLOBAL_SAVING);

    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
    mmi_frm_group_close(g_brw_app_cntx.brw_inline_cui_gid);                

    
    g_brw_app_cntx.brw_launching_pad = BRW_LPD_SETTINGS_PREF;
    mmi_brw_app_srv_hdlr_set_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_write_browser_preferences
 * DESCRIPTION
 *  This function is to write the Browser preferences to the NVRAM by calling
 * Browser service API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_write_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_update_settings_data(SRV_BRW_NVRAM_TIMEOUT_VALUE);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SHOW_IMAGE_MODE);

#ifdef OBIGO_Q05A
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SHOW_VIDEO);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_PLAY_SOUND);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_LOAD_UNKOWN_MEDIA);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_CSS);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SCRIPTS);
#endif /* OBIGO_Q05A */

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_CACHE);

    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_COOKIE);

#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SHORTCUTS);
#endif 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SECURITY_WARNINGS);
#endif 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SEND_DEVICE_ID);
#endif 

#ifdef __MMI_BRW_POST_SESSION_INFO__
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_POST_SESSION_INFO);
#endif 
}


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_trusted_certificate
 * DESCRIPTION
 *  This function is to send the delete trusted certificate request to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_trusted_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    mmi_brw_app_show_progress_screen(STR_ID_BRW_TRUSTED_CERTIFICATES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_delete_trusted_cert;
    data.index = srv_brw_trusted_certificate_get_actual_id(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    obj.req_data = (void*)&data;
    srv_brw_trusted_certificates_delete_req(&obj);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_trusted_certificate
 * DESCRIPTION
 *  This function is to get the data to be displayed on the trusted cert view 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
void mmi_brw_app_dmgr_get_trusted_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlighted item must be filled up before this */
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    obj.rsp_callback = mmi_brw_srv_hdlr_view_trusted_cert;
    data.index = srv_brw_trusted_certificate_get_actual_id(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    obj.req_data = (void*)&data;
    obj.user_data = data.index;
    srv_brw_get_trusted_certificate_req(&obj);
    // Set the service view trusted cert flag for the service to differentiate this case with others
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->view_cert_flag = MMI_TRUE;
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_current_certificate
 * DESCRIPTION
 *  This function is to get the data to be displayed on the trusted cert view 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
void mmi_brw_app_dmgr_get_current_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj.rsp_callback = mmi_brw_srv_hdlr_get_current_cert;
    srv_brw_get_current_certificate_req(&obj);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_current_session_info
 * DESCRIPTION
 *  This function is to get the data to be displayed on the trusted cert view 
 * screen if the check data function returns false
 * PARAMETERS
 *  screen id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
void mmi_brw_app_dmgr_get_current_session_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlighted item must be filled up before this */
    obj.rsp_callback = mmi_brw_srv_hdlr_get_session_info;
    srv_brw_get_session_info_req(&obj);
}
#endif /* OBIGO_Q05A */

#endif /* WAP_SEC_SUPPORT */
 

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_encoding_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_encoding_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 selected_encoding_method;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selected_encoding_method = g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item;
    if (g_srv_brw_cntx.encoding_method_index != selected_encoding_method)
    {
        g_srv_brw_cntx.encoding_method_index = selected_encoding_method;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX);
        mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url, sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url), (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
        srv_brw_load_url_req((U8*)g_brw_current_url, g_brw_app_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id);
        g_brw_app_cntx.brw_dynamic_cntx_p->encoding_type_new_flag = MMI_TRUE;
    }
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}
#endif /* OBIGO_Q05A */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_get_post_session_info_str
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  msg_str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_get_post_session_info_str(U8 *msg_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *sess_start_time_str;
    U8 *sess_end_time_str;
    U8 *data_downloaded_str;
    U8 *data_uploaded_str;
    U8 temp_str[BRW_POST_SESSION_INFO_STR_LEN + 1];
    U8 *str_p;
    U8 downloaded_bytes_str[50];
    U8 uploaded_bytes_str[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_p = (U8*) GetString(STR_ID_BRW_SESSION_START_TIME);
    sess_start_time_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) sess_start_time_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_BRW_SESSION_END_TIME);
    sess_end_time_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) sess_end_time_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_TOTAL_DATA_DOWNLOADED);
    data_downloaded_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) data_downloaded_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    str_p = (U8*) GetString(STR_ID_TOTAL_DATA_UPLOADED);
    data_uploaded_str = (U8*) OslMalloc(BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1) * sizeof(U8));
    mmi_chset_ucs2_to_utf8_string(
        (U8*) data_uploaded_str,
        BRW_UTF8_ENCODING_LENGTH * (mmi_ucs2strlen((S8*) str_p) + 1),
        (U8*) str_p);

    /* convert downloaded bytes into standard format */
    mmi_brw_app_util_format_size(total_bytes_downloaded, (S8*) downloaded_bytes_str);

    /* convert uploaded bytes into standard format */
    mmi_brw_app_util_format_size(total_bytes_uploaded, (S8*) uploaded_bytes_str);

    memset(temp_str, 0, BRW_POST_SESSION_INFO_STR_LEN + 1);

    sprintf(
        (S8*) temp_str,
        "%s\n%d/%d/%d %02d:%02d:%02d\n\n%s\n%d/%d/%d %02d:%02d:%02d\n\n%s\n%s\n\n%s\n%s",
        sess_start_time_str,
        start_session_data_time.nDay,
        start_session_data_time.nMonth,
        start_session_data_time.nYear,
        start_session_data_time.nHour,
        start_session_data_time.nMin,
        start_session_data_time.nSec,
        sess_end_time_str,
        end_session_data_time.nDay,
        end_session_data_time.nMonth,
        end_session_data_time.nYear,
        end_session_data_time.nHour,
        end_session_data_time.nMin,
        end_session_data_time.nSec,
        data_downloaded_str,
        downloaded_bytes_str,
        data_uploaded_str,
        uploaded_bytes_str);

    mmi_chset_utf8_to_ucs2_string((U8*) msg_str, BRW_POST_SESSION_INFO_STR_LEN + 1, (U8*) temp_str);

    OslMfree(sess_start_time_str);
    OslMfree(sess_end_time_str);
    OslMfree(data_downloaded_str);
    OslMfree(data_uploaded_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_post_session_info
 * DESCRIPTION
 *  This func is used storing the session information into static variables
 *  for displaying the session information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_post_session_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&start_session_data_time, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time, sizeof(applib_time_struct));
    applib_dt_get_rtc_time(&end_session_data_time);
    total_bytes_downloaded = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_downloaded;
    total_bytes_uploaded = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_uploaded;
    mmi_brw_app_if_show_post_session_info_screen();
}
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_homepage_setting
 * DESCRIPTION
 *  This func is used for storing the homepage setting if the previously selected
 *  and the newly selected setting are different
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_homepage_setting(U8 homepage_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.homepage_setting != homepage_setting)
    {
        g_srv_brw_cntx.homepage_setting = homepage_setting;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_HOMEPAGE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_update_user_defined_homepage
 * DESCRIPTION
 *  This func is used for storing the homepage URL provided by the
  * user in the editor after validation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_update_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_error_enum error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = srv_brw_set_as_homepage(g_brw_current_url);
    if(error_code != SRV_BRW_ERROR_OK)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_INVALID_URL, MMI_EVENT_PROPLEM);
        return;
    }
    mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
    cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
    mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_homepage_edit
 * DESCRIPTION
 *  This func is pre entry function to the homepage editor screen
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_homepage_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* url_ascii;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_ascii = (U8*) srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
    memset(url_ascii, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
    srv_brw_get_user_defined_homepage(url_ascii);
    if(strlen(url_ascii) != 0)
    {
        mmi_asc_n_to_ucs2((S8*) g_brw_current_url, (S8*) url_ascii, SRV_BRW_MAX_URL_LEN);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);
    }
    mmi_brw_app_if_show_edit_homepage();
    srv_brw_free(url_ascii);
}
#endif

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_trusted_certificates
 * DESCRIPTION
 *  This func is to delete a trusted certificate
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_trusted_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item].type == WPS_SEC_CERT_READ_ONLY)
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_ID_BRW_READ_ONLY_CERTIFICATE, MMI_EVENT_PROPLEM);
    }
    else
    {
        mmi_brw_app_delete_trusted_certificates_confirm();
    }
}
#endif /* WAP_SEC_SUPPORT */

/*******************************SETTINGS END*******************************/


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/****************************STORED PAGES START****************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_stored_page
 * DESCRIPTION
 *  This function is to call the service API to delete the selected stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_stored_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    mmi_brw_app_show_progress_screen(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_DELETING);
    obj.rsp_callback = mmi_brw_srv_hdlr_delete_save_page;
    data.index = g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item;
    obj.req_data = (void*)&data;
    srv_brw_delete_stored_page_req(&obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_all_stored_pages
 * DESCRIPTION
 *  This function is to call the service API to delete the entire stored page
 * list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_all_stored_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_show_progress_screen(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_DELETING);
    obj.rsp_callback = mmi_brw_srv_hdlr_delete_all_save_page;
    srv_brw_delete_all_stored_pages_req(&obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_open_stored_page
 * DESCRIPTION
 *  This function is to open the selected stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_open_stored_page(void)
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
        g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_STORED_PAGE;
        return;
    }
    else if (ret == CBM_OK)
    {
        mmi_brw_app_srv_hdlr_open_stored_page();
        mmi_brw_app_pre_entry_render_page();
    }
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_stored_page_properties
 * DESCRIPTION
 *  This function is the pre entry function for the stored page properties
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_stored_page_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_str[100];
    applib_time_struct time_obj;
    S32 local_time_in_sec;
    S32 page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p);

    mmi_brw_app_reset_object_properties();

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
        mmi_chset_utf8_to_ucs2_string(
            (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name,
            (BRW_OBJECT_PROPERTIES_NAME_LEN + 1) * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label);

        g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_ADDRESS] = MMI_TRUE;
        mmi_chset_utf8_to_ucs2_string(
            (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_address,
            (BRW_OBJECT_PROPERTIES_ADDRESS_LEN + 1) * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url);

        g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
        page_size = (S32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->data_size;
        if (page_size > 0)
        {
            srv_brw_convert_int_to_unicode_string((U8*) temp_str, (U32) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->data_size);
            mmi_ucs2cat((S8*) temp_str, (S8*) L" ");
            mmi_ucs2cat((S8*) temp_str, (S8*) get_string(STR_ID_BRW_BYTES));
        }
        else
        {
            mmi_ucs2cpy((S8*) temp_str, (S8*) get_string(STR_ID_BRW_UNKNOWN));
        }
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size, (S8*) temp_str);

        g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_DATE] = MMI_TRUE;
        local_time_in_sec = applib_dt_sec_utc_to_local(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->date);
        if (applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE))
        {
            UI_character_type temp_time_buffer[20] = {0};
	    date_string((UI_time*)&time_obj, temp_time_buffer, DT_IDLE_SCREEN);
	    mmi_ucs2ncpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_date, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));
            mmi_ucs2ncat((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_date, (S8*) "\0", 1);
            //sprintf((S8*) temp_str, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);
            //mmi_asc_to_ucs2((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_date, (S8*) temp_str);
        }
    }

    g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_count = BRW_STORED_PAGE_PROPERTIES_COUNT;
    mmi_brw_app_if_show_object_properties_screen();
}
#endif /* OBIGO_Q05A */


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_set_stored_page_url_as_homepage
 * DESCRIPTION
 *  This func is used for setting the URL of the selected saved page as 
 * the current homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_set_stored_page_url_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_url_as_homepage((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url);
}
#endif

#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_add_stored_pages_list_item_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Enter Address Add To Bookmarks screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_add_stored_pages_list_item_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_title,
        (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url);

    mmi_brw_app_dmgr_add_to_bookmark();
}
#endif /* __MMI_VBOOKMARK__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_save_stored_page
 * DESCRIPTION
 *  Pre Entry function for saving a new stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_save_stored_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_stored_page_operation_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*)g_brw_current_title, (S8*)(g_brw_display_info_str), SRV_BRW_MAX_TITLE_LENGTH);

    if(!mmi_ucs2strlen((S8*)g_brw_current_title))
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME, MMI_EVENT_PROPLEM);
        return;
    }
    mmi_brw_app_show_progress_screen(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_save_page;
    data.page_label = g_brw_current_title;
    obj.req_data = (void*)&data;
    srv_brw_save_as_stored_page_req(&obj);
    cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_rename_stored_page
 * DESCRIPTION
 *  Pre Entry function for renaming a new stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_rename_stored_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_stored_page_operation_req_struct data;
    U8 g_brw_current_title_temp[(SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*)g_brw_current_title, (S8*)g_brw_display_info_str, SRV_BRW_MAX_TITLE_LENGTH);

    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_title_temp,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label);
    if (!mmi_ucs2ncmp
        ((S8*) g_brw_current_title, (S8*) g_brw_current_title_temp, (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH))
    {
        mmi_brw_app_ui_draw_display_popup_ext(
            STR_GLOBAL_SAVED,
            MMI_EVENT_EXPLICITLY_SAVED);
        cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
        return;
    }

    if(!mmi_ucs2strlen((S8*)g_brw_current_title))
    {
        mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME, MMI_EVENT_PROPLEM);
        return;
    }

    mmi_brw_app_show_progress_screen(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_save_page;
    obj.user_data = 1;
    data.page_label = g_brw_current_title;
    data.index = g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item;
    obj.req_data = (void*)&data;
    srv_brw_rename_stored_page_req(&obj);
    cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_rename_stored_page
 * DESCRIPTION
 *  Pre Entry function for renaming a stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_rename_stored_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_display_info_str)
    {
        srv_brw_free_browser_memory((void**)&(g_brw_display_info_str));
	}
    g_brw_display_info_str = (U8*)srv_brw_malloc((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_display_info_str,
        (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label);

    mmi_brw_app_if_show_stored_page_rename_screen();

}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_stored_pages_list
 * DESCRIPTION
 *  Pre Entry function for stored pages list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_stored_pages_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_is_in_usb_mode())
    {
        return;
    }
    mmi_brw_app_if_show_stored_pages_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_stored_page_options
 * DESCRIPTION
 *  Pre Entry function for stored pages list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_stored_page_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item >= 0);
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p));
    mmi_brw_app_show_progress_screen(STR_ID_BRW_STORED_PAGES, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_get_save_page;
    data.index = g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item;
    obj.req_data = (void*)&data;
    srv_brw_get_stored_page_req(&obj);
}
/****************************STORED PAGES END******************************/

#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

/****************************SHORTCUTS START********************************/
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_add_shortcut
 * DESCRIPTION
 *  Pre Entry function for add shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_add_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_brw_current_title, 0, sizeof(g_brw_current_title));
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);
    mmi_brw_app_if_show_edit_shortcut();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_pre_entry_edit_shortcut
 * DESCRIPTION
 *  Pre Entry function for edit shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_pre_entry_edit_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_brw_current_title, (PS8) srv_brw_shortcuts_list_get_title(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item));
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) srv_brw_shortcuts_list_get_url(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item));
    mmi_brw_app_if_show_edit_shortcut();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_save_shortcut
 * DESCRIPTION
 *  function to save the shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_save_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_ucs2strlen((S8*)g_brw_current_title))
    {
        mmi_brw_app_ui_draw_display_popup(
            (PU8) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_PROPLEM);
        return;
    }

    if (srv_brw_validate_url(g_brw_current_url, WAP_MAX_SEARCH_URL_LENGTH) < 0)
    {
        mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_GLOBAL_INVALID_URL), MMI_EVENT_PROPLEM);
        return;
    }
    srv_brw_update_shortcut_info(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item, (U8*)g_brw_current_title, (U8*)g_brw_current_url);
    mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
    cui_inline_close(g_brw_app_cntx.brw_inline_cid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_launch_shortcut
 * DESCRIPTION
 *  function to launch the shortcut URL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_launch_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) srv_brw_shortcuts_list_get_url(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item));
    mmi_brw_app_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dmgr_delete_shortcut
 * DESCRIPTION
 *  function to delete the shortcut information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dmgr_delete_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_current_title[0] = '\0';
    g_brw_current_url[0] = '\0';
    srv_brw_update_shortcut_info(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item, (U8*)g_brw_current_title, (U8*)g_brw_current_url);
    mmi_brw_app_ui_draw_display_popup(
            (U8*) GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS);
}
/****************************SHORTCUTS END********************************/
#endif

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPDMGR_C */
