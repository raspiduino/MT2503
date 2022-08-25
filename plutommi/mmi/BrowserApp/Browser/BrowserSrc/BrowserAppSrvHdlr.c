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
 * removed!
 *
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPSRVHDLR_C
#define MMI_BROWSERAPPSRVHDLR_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppSrvHdlr.h"
#include "BrowserResDef.h"
#include "BrowserAppMain.h"
#include "BrowserAppInterface.h"
#include "BrowserAppDMgr.h"
#include "DtcntSrvGprot.h"  /* For CBM related APIs and enum */

#include "GpioSrvGprot.h" /* for the backlight related APIs */

#include "MMIDataType.h"
#include "BrowserSrvProts.h"
#include "kal_general_types.h"
#include "BrowserAppTypes.h"
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvGprot.h"
#include "UriAgentSrvGprot.h"
#include "mmi_rp_app_browser_def.h"
#include "BrowserSrvInterface.h"
#include "wap_adp.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
#include "BrowserAppUIDraw.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvConfig.h"
#include "kal_public_api.h"
#include "Conversions.h"
#include "app_mem.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "DebugInitDef_Int.h"
#include "browser_api.h"
#include "common_nvram_editor_data_item.h"
#include "NotificationGprot.h"
#include "wps_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_browser_def.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "wgui_categories.h"
#include "bam_api.h"
#include "BrowserSrvGprot.h"

extern void bam_reset_open_bearer_status(void);
extern void HDIa_widgetResetWcacheMemoryPtr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_register_callback_events
 * DESCRIPTION
 *  This function is used to register the Application function for the various
 * events that will be sent by the service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_register_callback_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register for the events emitted by the Browser service */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_create_instance
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * create instance request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_create_instance(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_POST_SESSION_INFO__
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_BRW_POST_SESSION_INFO);
#endif
    if(mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    else
    {
     #ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
        if (g_srv_brw_cntx.clear_brw_data_flag)
        {
            srv_brw_clear_browser_data_on_sim_change();
        }
    #endif /* __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__ */ 

        mmi_brw_app_session_init();
        if(g_brw_app_cntx.sat_profile_update ||
            g_brw_app_cntx.is_resend_profile_required)
        {
            mmi_brw_app_srv_hdlr_set_profile_req();
        }
        else
        {
        #ifdef OBIGO_Q03C_BROWSER
            mmi_brw_app_launch_browser();
        #else /* OBIGO_Q03C_BROWSER */
            mmi_brw_app_srv_hdlr_set_profile_req();
        #endif /* OBIGO_Q03C_BROWSER */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_set_profile
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * set profile request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_set_profile(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        if (g_brw_app_cntx.brw_launching_pad == BRW_LPD_ACTIVE_PROFILE_CHANGED)
        {
            g_brw_app_cntx.actv_prof_changed_cb(SRV_WAP_PROF_ERR);
        }
        return;
    }
    if(g_brw_app_cntx.is_resend_profile_required)
    {
        g_brw_app_cntx.is_resend_profile_required = MMI_FALSE;
    }
    if(g_brw_app_cntx.sat_profile_update)
    {
        g_brw_app_cntx.sat_profile_update = MMI_FALSE;
        g_brw_app_cntx.is_resend_profile_required = MMI_TRUE;
    }
    mmi_brw_app_launch_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_launch_browser
 * DESCRIPTION
 *  This func is used for pwerforming the required task depending on the value 
 * stored in the launching pad variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_launch_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear the sap_msg_id before performing any further tasks as it can get set while
       loading a URL for further use */
    g_srv_brw_cntx.sap_msg_id = 0;
#ifdef __MMI_URI_AGENT__
    if(g_brw_app_cntx.uha_info_p)
    {
        if (g_brw_app_cntx.uha_info_p->uri_agent_cb)
        {
            g_brw_app_cntx.uha_info_p->uri_agent_cb(g_brw_app_cntx.uha_info_p->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_TRUE);
            g_brw_app_cntx.uha_info_p->uri_agent_cb = NULL;
        }
        srv_brw_free_OSL_memory((void**)&(g_brw_app_cntx.uha_info_p));
    }
#endif /* __MMI_URI_AGENT__ */

    switch (g_brw_app_cntx.brw_launching_pad)
    {
        case BRW_LPD_MAIN_MENU:
        {
        #ifdef __MMI_Q05A_LAUNCH_SCREEN__
            srv_brw_read_shortcut_list_data();
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_LAUNCH_PAGE,
                                                       mmi_brw_app_if_show_shortcuts_list,
                                                       BRW_SCREEN_GROUP,
                                                       mmi_brw_internet_service_screen_proc);
        #else
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_INTERNET_SERVICES,
                                                       mmi_brw_app_if_show_internet_services_menu,
                                                       BRW_SCREEN_GROUP,
                                                       mmi_brw_internet_service_screen_proc);
        #endif
            g_brw_app_cntx.brw_dynamic_cntx_p->mainMenuEntryFlag = MMI_TRUE;
            break;
        }
        case BRW_LPD_EXTERNAL_LOAD_URL_REQ:
        {
            kal_int8 ret = mmi_brw_app_open_bearer();
            if(ret == CBM_WOULDBLOCK)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_OUTSIDE_URL;
                return;
            }
            else if (ret == CBM_OK)
            {
                mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
                mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                           mmi_brw_app_pre_entry_render_page,
                                                           BRW_RENDERED_PAGE_GRP_ID,
                                                           mmi_brw_rendered_page_group_proc);
            }
            break;
        }
    #ifdef OBIGO_Q05A 
        case BRW_LPD_EXTERNAL_LOAD_DATA_REQ:
        {
            kal_int8 ret = mmi_brw_app_open_bearer();
            if(ret == CBM_WOULDBLOCK)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->launch_type = BRW_LAUNCH_TYPE_OUTSIDE_URL;
                return;
            }
            else if (ret == CBM_OK)
            {
                mmi_brw_srv_hdlr_load_data_req();
                mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                           mmi_brw_app_pre_entry_render_page,
                                                           BRW_RENDERED_PAGE_GRP_ID,
                                                           mmi_brw_rendered_page_group_proc);
            }
            break;
        }
    #endif /* OBIGO_Q05A */

        case BRW_LPD_SETTINGS_PREF:
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
            {
                mmi_brw_app_ui_draw_display_popup(
                    (U8*) GetString(STR_GLOBAL_SAVED),
                    MMI_EVENT_EXPLICITLY_SAVED);
            }
            mmi_brw_app_delete_busy_screen();
            mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BROWSER_PREFERENCES);
            break;
        }
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
        case BRW_LPD_RESTORE_BRW_SETTINGS:
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
            {
                mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
                mmi_brw_app_ui_draw_display_popup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    MMI_EVENT_SUCCESS);
            }
            mmi_brw_app_delete_busy_screen();
            break;
        }
#endif /* __MMI_BRW_APP_DEPENDENT_MACRO__ */

        case BRW_LPD_ACTIVE_PROFILE_CHANGED:
        {
            if (srv_brw_is_holding_bearer())
            {
                srv_brw_set_bearer(MMI_FALSE);
            }
            g_brw_app_cntx.actv_prof_changed_cb(SRV_WAP_PROF_SUCCESS);
            break;
        }
    #ifdef __SAT__
        case BRW_LPD_SAT_LAUNCH_REQ:
        {
            mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                       mmi_brw_app_pre_entry_render_page,
                                                       BRW_RENDERED_PAGE_GRP_ID,
                                                       mmi_brw_rendered_page_group_proc);
            break;
        }
    #endif /* __SAT__ */ 
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
    #endif /* __MMI_OP11_HOMESCREEN__ */ 
    #if (MMI_MAX_SIM_NUM >= 2)
        case BRW_LPD_TEMP_PROFILE_CHANGED:
        {
            g_srv_brw_cntx.is_profile_req_received = MMI_TRUE;
            g_brw_app_cntx.is_resend_profile_required = MMI_TRUE;
            if (!g_brw_app_cntx.brw_dynamic_cntx_p->is_bearer_active)
            {
                mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
                mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                           mmi_brw_app_pre_entry_render_page,
                                                           BRW_RENDERED_PAGE_GRP_ID,
                                                           mmi_brw_rendered_page_group_proc);
            }
            else
            {
                return;
            }
            break;
        }
    #endif /*  (MMI_MAX_SIM_NUM >= 2) */
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        case BRW_LPD_HOME_SCR_ENTER_ADDRESS:
        {
            g_brw_app_cntx.brw_launching_pad_for_OHS = BRW_LPD_HOME_SCR_ENTER_ADDRESS ;
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_ENTER_URL,
                                                           mmi_brw_app_dmgr_pre_entry_address_list,
                                                           BRW_SCREEN_GROUP,
                                                           mmi_brw_internet_service_screen_proc);
            break;
        }
        case BRW_LPD_HOME_SCR_USER_DEFINED_BKM:
        {
            g_brw_app_cntx.brw_launching_pad_for_OHS = BRW_LPD_HOME_SCR_USER_DEFINED_BKM ;
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BOOKMARKS,
                                                           mmi_brw_app_dmgr_pre_entry_bookmark_list,
                                                           BRW_SCREEN_GROUP,
                                                           mmi_brw_internet_service_screen_proc);
            break;
        }
    #endif /* ORANGE HOME SCREEN   */ 
    #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
        case BRW_LPD_SESSION_CLOSED:
        {
            mmi_brw_app_deinit();
            mmi_brw_app_delete_busy_screen();
            break;
        }
    #endif /* __MMI_RMGR_SEAMLESS_UNLOCK__ */

        case BRW_LPD_WIFI_PREFER_LAUNCH:
        {
         #ifdef OBIGO_Q05A
            mmi_brw_app_continue_launch_browser();
            mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_BROWSER_MAIN,
                                                       mmi_brw_app_pre_entry_render_page,
                                                       BRW_RENDERED_PAGE_GRP_ID,
                                                       mmi_brw_rendered_page_group_proc);
         #else
            srv_brw_open_bearer_rsp(1);
         #endif
            break;
        }

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
        case BRW_LPD_WIFI_PREFER_RELAUNCH:
        {
            mmi_brw_app_continue_relaunch_browser();
            break;
        }
#endif

        case BRW_LPD_NONE:
        default:
        {
            break;
        }
    }
    g_brw_app_cntx.brw_launching_pad = BRW_LPD_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_instance
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Delete instance request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_instance(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_INFUSIO__
    S8 java_param[WAP_BAM_MAX_URL_LEN + 1];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (g_srv_brw_cntx.brw_instance_id > 0)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending = MMI_FALSE;
        /* stop server connection response timer */
        mmi_brw_app_stop_server_connection_timer();
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        /* stop splash screen timer */
        mmi_brw_app_stop_splash_screen_timer();
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        /* stop timer and page size checking */
    #ifdef __MMI_BRW_LOADING_TIME_CHECKING__
        StopTimer(BRW_LOADING_TIME_CHECK_TIMER);
    #endif 
    #if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
        mmi_brw_app_remove_loading_size_time_screens();
    #endif

        /* deinitialize whole browser global context */
        mmi_brw_app_global_context_deinit();
        srv_brw_destroy_dynamic_service();

        /* de-initalize ADM memory */
        if (g_srv_brw_cntx.brw_adm_id)
        {
            kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
            g_srv_brw_cntx.brw_adm_id = NULL;
        }

        /* deinit browser application ASM memory */
        if (g_brw_app_memory_pool)
        {
        #ifdef OBIGO_Q03C_BROWSER
            wapadp_set_wap_app_mem(NULL,TRUE);
            HDIa_widgetResetWcacheMemoryPtr();
        #endif /* OBIGO_Q03C_BROWSER */
            applib_asm_free_r(APP_BROWSER, g_brw_app_memory_pool);
            g_brw_app_memory_pool = NULL;
        }

        if(g_brw_app_cntx.close_evt > 0)
        {
            mmi_brw_app_notify_wap_close();
        }

    #ifdef OBIGO_Q03C_BROWSER
        wapadp_set_wap_app_mem(NULL,FALSE);
    #elif OBIGO_Q05A
        resetAppMemPool();
    #endif /* OBIGO_Q03C_BROWSER */


        /* if the browser app is terminated by some other App then
           send the success notification to MMI */
        if (g_brw_app_cntx.brw_launching_pad == BRW_LPD_ASM_TERMINATE)
        {
            /* Notify MMI that this application is already stopped */
            applib_mem_ap_notify_stop_finished(APP_BROWSER, KAL_TRUE);
            g_brw_app_cntx.brw_launching_pad = BRW_LPD_NONE;
        }

        /* re-launch the browser if it is waiting for delete instance response */
        if (g_brw_app_cntx.common_gateway_flag)
        {
            mmi_brw_app_common_gateway();
            return;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_global_context_deinit
 * DESCRIPTION
 *  Deinitializing all the browser global context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_global_context_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
    if (g_srv_brw_cntx.brw_adm_id)
    {
        mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));


    #ifdef __MMI_VBOOKMARK__
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        mmi_brw_app_free_browser_memory ((void**)&(g_brw_bkm_cntx.bkm_dynamic_cntx));
    #endif
    #endif 
        mmi_brw_app_dynamic_context_deinit();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_dynamic_context_deinit
 * DESCRIPTION
 *  This func is used for deinitializing the browser dynamic context
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_dynamic_context_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_app_cntx.brw_dynamic_cntx_p != NULL)
    {
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->requested_url_p));
    #ifdef WAP_SEC_SUPPORT
    #ifdef OBIGO_Q05A
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p));
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p));
    #endif /* OBIGO_Q05A */
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p));
    #endif
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p));

    }
}


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_save_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Save Page request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_save_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
    if(user_data > 0)
    {
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);
    }
    mmi_brw_app_delete_busy_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_save_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get Saved Page request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_save_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
#ifdef __MMI_FTE_SUPPORT__ 	
    if(g_brw_app_cntx.brw_toolbar_launch_point == BRW_LAUNCH_FROM_STORED_PAGE_ADD_BKM)
    {
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_STORED_PAGE_OPTIONS,
                                                   mmi_brw_app_dmgr_add_stored_pages_list_item_to_bookmark,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
    }
    else
#endif /*__MMI_FTE_SUPPORT__*/ 
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_STORED_PAGE_OPTIONS,
                                                   mmi_brw_app_if_show_stored_page_options_menu,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_save_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Delete/Delete all Save Page request to handle the tasks that should be 
 * performed on receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_save_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);
    mmi_brw_app_delete_busy_screen();  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_all_save_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Delete/Delete all Save Page request to handle the tasks that should be 
 * performed on receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_all_save_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_STORED_PAGES);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);
    mmi_brw_app_delete_busy_screen();  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_save_page_list
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get saved pages list request to handle the tasks that should be 
 * performed on receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_save_page_list(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_list_rsp_struct *list_data = (srv_brw_list_rsp_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    if(list_data->num_count == 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE);
        }
        mmi_brw_app_delete_busy_screen();
        return;
    }

    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_STORED_PAGES,
                                               mmi_brw_app_if_show_stored_pages_list,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);

}

#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_page_objects_list
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get page objects list request to handle the tasks that should be 
 * performed on receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_page_objects_list(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_list_rsp_struct *list_data = (srv_brw_list_rsp_struct*)obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    if(list_data->num_count == 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE);
        }
        mmi_brw_app_delete_busy_screen();
        srv_brw_get_resource_list_end_req();
        return;
    }
    
    srv_brw_create_rendered_page_object_lists();
    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_PAGE_OBJECT_TYPES,
                                               mmi_brw_app_if_show_page_object_types,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_page_objects
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get page objects list request to handle the tasks that should be 
 * performed on receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_page_objects(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);

    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_PAGE_OBJECTS_OPTIONS,
                                               mmi_brw_app_if_show_page_objects_options,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);
}
#endif /* OBIGO_Q05A */


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_recent_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get Recent Page request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_recent_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
#ifdef __MMI_FTE_SUPPORT__ 	
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    if(g_brw_app_cntx.brw_toolbar_launch_point == BRW_LAUNCH_FROM_RECENT_PAGE_ADD_BKM)
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_RECENT_PAGE_OPTIONS,
                                                   mmi_brw_app_dmgr_add_recent_page_list_item_to_bookmark,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
    }
    else
#endif
#endif /*__MMI_FTE_SUPPORT__*/ 
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_RECENT_PAGE_OPTIONS,
                                                   mmi_brw_app_if_show_recent_page_options_menu,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_recent_page_list
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get Recent Page list request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_recent_page_list(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_list_rsp_struct *list_data = (srv_brw_list_rsp_struct*)obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    if(list_data->num_count == 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE);
        }
        mmi_brw_app_delete_busy_screen();
        return;
    }
#ifdef OBIGO_Q05A
    if (g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
    {
        srv_brw_create_recent_page_host_list();
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_RECENT_PAGES_HOST,
                                                   mmi_brw_app_if_show_recent_pages_host_screen,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
    }
    else
#endif /* OBIGO_Q05A */
    {
        srv_brw_create_recent_page_list();
        mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_RECENT_PAGES,
                                                   mmi_brw_app_if_show_recent_pages_list,
                                                   g_brw_app_cntx.brw_scr_group_id,
                                                   NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_recent_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Delete Recent Page request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_recent_page(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
    {
    #ifdef OBIGO_Q05A
        if (g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
        {
            mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_RECENT_PAGES);
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST);
        }
    #endif /* OBIGO_Q05A */
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);                
    }
    mmi_brw_app_delete_busy_screen();
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_recent_page
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Delete Recent Page request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_all_recent_page(S32 user_data, U32 result, void *obj)
{
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
#ifdef OBIGO_Q05A
    if (g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
    {
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST);
    }
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_RECENT_PAGES_HOST);
#endif /* OBIGO_Q05A */
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_RECENT_PAGES);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);                
    mmi_brw_app_delete_busy_screen();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_clear_data
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * Clear data request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_clear_data(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_bam_error_code(result))
    {
        return;
    }
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
    {
        mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
        mmi_brw_app_ui_draw_display_popup(
            (U8*) GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS);
    }
    mmi_brw_app_delete_busy_screen();

}


#ifdef __MMI_URI_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_uri_ind_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_URI_REQ_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_uri_ind_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_uri_req_event_struct *uri_evt = (srv_brw_uri_req_event_struct*)evt;
    srv_uriagent_err_enum err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
    mmi_rmgr_unlock_session_callback();
#endif 
    if (srv_uriagent_has_registered_hdlr(uri_evt->url_string))
    {
        err = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                uri_evt->url_string,
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                mmi_brw_app_if_uri_callback);
        /* Reject the request if URI Agent is still processing */
        if (err == SRV_URIAGENT_ERR_PROCESSING)
        {
        #ifdef OBIGO_Q03C_BROWSER
            srv_brw_uri_req_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);
        #endif /* OBIGO_Q03C_BROWSER */
            mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_ID_BRW_URI_BUSY), MMI_EVENT_PROPLEM);
            return MMI_RET_OK;
        }
        MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
    }
    else
    {
        mmi_brw_app_ui_draw_display_popup((PU8) GetString(STR_GLOBAL_NOT_SUPPORTED), MMI_EVENT_PROPLEM);
    #ifdef OBIGO_Q03C_BROWSER
        srv_brw_uri_req_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);
    #endif /* OBIGO_Q03C_BROWSER */
    }
    return MMI_RET_OK;
}
#endif /* __MMI_URI_AGENT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_error_ind_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_ERROR_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_error_ind_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_content_p;
    srv_brw_rendering_error_event_struct *evt = (srv_brw_rendering_error_event_struct*)event;
    U8 bearer_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->error_code)
    {
        switch (evt->error_code)
        {
        #ifdef OBIGO_Q03C_BROWSER
            case WAP_BAM_ERROR_OUT_OF_MEM_WAP_RESET:
            {
                mmi_brw_app_close_download_and_exit();
                if (mmi_brw_app_is_browser_screen(mmi_frm_scrn_get_active_id()))
                {
                    mmi_frm_scrn_close_active_id();
                }
                break;
            }
        #endif /* OBIGO_Q03C_BROWSER */
#ifdef __BAIDU_TRANSCODING_SUPPORT__
#ifdef OBIGO_Q03C
        case WAP_BAM_ERROR_PAGE_NOT_FOUND: /* 57 */
        {
            /*----------------------------------------------------------------*/
            /* Local Variables                                                */
            /*----------------------------------------------------------------*/
            U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

            /*----------------------------------------------------------------*/
            /* Code Body                                                      */
            /*----------------------------------------------------------------*/
            mmi_ucs2cpy((S8*) msgStr, (S8*) GetString(STR_ID_BRW_SWITCH_OFF_BAIDU_PROXY_CONFIRM));
            //mmi_ucs2cat((S8*) msgStr, (S8*) GetString(STR_ID_BRW_QUESTION_MARK));

            mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, mmi_brw_app_dmgr_switch_off_baidu_proxy, mmi_frm_scrn_close_active_id, MMI_FALSE);
            break;
        }
#endif /* OBIGO_Q03C */
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            /* Only Q05A */
        #ifdef OBIGO_Q05A

                /* Show the warnings pop-up and return back */
            case WAP_BAM_ERROR_LOW_MEMORY:
            case WAP_BAM_ERROR_EXCEED_MAX_NUM_OF_INLINE_VDO:
            case WAP_BAM_ERROR_CANNOT_PLAY_INLINE_VDO_IN_CALL:
            {
            #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
                mmi_rmgr_unlock_session_callback();
            #endif 
                if (mmi_brw_app_is_browser_screen(mmi_frm_scrn_get_active_id()))
                {
                    mmi_brw_app_bam_error_handler(evt->error_code);
                }
                break;
            }
        #endif /* OBIGO_Q05A */

                /* show the error pop-up, de-initialize the browser and exit */
            case WAP_BAM_ERROR_OUT_OF_MEMORY:
            {
            #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
                mmi_rmgr_unlock_session_callback();
            #endif 

                /* stop server connection response timer */
                mmi_brw_app_stop_server_connection_timer();
            #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
                /* stop the splash screen timer */
                mmi_brw_app_stop_splash_screen_timer();
            #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            #ifdef __MMI_BRW_LOADING_TIME_CHECKING__
                StopTimer(BRW_LOADING_TIME_CHECK_TIMER);
            #endif 
                if(mmi_brw_is_browser_active())
                {
                    mmi_brw_app_if_show_out_of_mem_confirm_screen();
                }
            #if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
                mmi_brw_app_remove_loading_size_time_screens();
            #endif 
                break;
            }

                /*
                 * Show the error pop-up and check the following cases -->
                 * * (1) delete rendered page screen if no page is yet rendered
                 * * (2) de-init browser application if no page is yet rendered & it is launched from other application
                 */
            default:
            {
                #ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
                    mmi_rmgr_unlock_session_callback();
                #endif 

                /* stop server connection response timer */
                mmi_brw_app_stop_server_connection_timer();
            #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
                /* stop the splash screen timer */
                mmi_brw_app_stop_splash_screen_timer();
            #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
                /* stop timer and page size checking */
            #ifdef __MMI_BRW_LOADING_TIME_CHECKING__
                if (evt->error_code != WAP_BAM_ERROR_INVALID_URL)
                {
                    StopTimer(BRW_LOADING_TIME_CHECK_TIMER);
                }
            #endif 

            #if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
                mmi_brw_app_remove_loading_size_time_screens();
            #endif 

                /* Identifying the bearer type for WAP_BAM_ERROR_CONNECTION_FAILED & WAP_BAM_ERROR_LONG_IDLE_TIMEOUT error indications */
                if ((evt->error_code == WAP_BAM_ERROR_CONNECTION_FAILED) ||
                    (evt->error_code == WAP_BAM_ERROR_LONG_IDLE_TIMEOUT))
                {
                    srv_brw_get_bearer_type(&bearer_type);
                }

                /* Long idle error indication is being send by the protocol stack thus BAM */
                /* is not aware about this, so we need to send the stop fetching indication to BAM */
            #ifdef __MMI_WAP_GPRS_LINGER_TIMEOUT__
                if (evt->error_code == WAP_BAM_ERROR_LONG_IDLE_TIMEOUT &&
                #ifdef __TCPIP_OVER_CSD__
                    (bearer_type == SRV_DTCNT_BEARER_CSD) || 
                #endif /* #ifdef __TCPIP_OVER_CSD__ */
                    (bearer_type == SRV_DTCNT_BEARER_GPRS))
            #else /* __MMI_WAP_GPRS_LINGER_TIMEOUT__ */ 
                if (evt->error_code == WAP_BAM_ERROR_LONG_IDLE_TIMEOUT
            #ifdef __TCPIP_OVER_CSD__
                    && bearer_type == SRV_DTCNT_BEARER_CSD
            #endif /* #ifdef __TCPIP_OVER_CSD__ */
                    )
        
            #endif /* __MMI_WAP_GPRS_LINGER_TIMEOUT__ */ 
                {
                    if (g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserFetching)
                    {
                        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->need_bearer_release = MMI_TRUE;
                        srv_brw_stop_page_fetching_req();
                    }
                    else
                    {
                        if (srv_brw_is_holding_bearer())
                        {
                            srv_brw_set_bearer(MMI_FALSE);
                        }
                    }
                }

                /* If Upload Progress screen is on top and long idle timeout happens then show long idle timeout popup
                   without checking for bearer type */
                if (evt->error_code == WAP_BAM_ERROR_LONG_IDLE_TIMEOUT &&
                    ((mmi_frm_scrn_get_active_id() == SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN) ||
                     (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN)))
                {
                #ifdef __MMI_WAP_GPRS_LINGER_TIMEOUT__
                    mmi_brw_app_bam_error_handler(evt->error_code);
                    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN);
                #else /* __MMI_WAP_GPRS_LINGER_TIMEOUT__ */ 
                #ifdef __TCPIP_OVER_CSD__
                    if (bearer_type == SRV_DTCNT_BEARER_CSD)
                    {
                        mmi_brw_app_bam_error_handler(evt->error_code);
                        mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN);
                    }
                #endif /* #ifdef __TCPIP_OVER_CSD__ */
                #endif /* __MMI_WAP_GPRS_LINGER_TIMEOUT__ */ 
                }
                /* No need to display any error popups for the following cases: */
                /* (1)error code = WAP_BAM_ERROR_CONNECTION_FAILED and bearer = SRV_DTCNT_BEARER_CSD */
                /* (2)error code = WAP_BAM_ERROR_LONG_IDLE_TIMEOUT and bearer != SRV_DTCNT_BEARER_CSD */
                else if (
                      #ifdef __TCPIP_OVER_CSD__
                         !(evt->error_code == WAP_BAM_ERROR_CONNECTION_FAILED
                         && bearer_type == SRV_DTCNT_BEARER_CSD) && 
                      #endif /* __TCPIP_OVER_CSD__ */
                          !(evt->error_code == WAP_BAM_ERROR_LONG_IDLE_TIMEOUT 
                      #ifdef __TCPIP_OVER_CSD__
                          && bearer_type != SRV_DTCNT_BEARER_CSD
                      #endif /* #ifdef __TCPIP_OVER_CSD__ */
                          ))
                {
                    if (mmi_brw_app_is_browser_screen(mmi_frm_scrn_get_active_id()))
                    {
                        mmi_brw_app_bam_error_handler(evt->error_code);
                        mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN);
                    }
                }
                else
                {
                    return MMI_RET_OK;
                }

                /* delete browser instance if control returns back to the launched 
                   module */
                if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !mmi_brw_app_is_browser_launched_from_main_menu())
                {
                    mmi_brw_app_close_download_and_exit();
                }

                break;
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_document_info_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_DOC_INFO_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_document_info_proc(mmi_event_struct *evt)
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

    /* stop server connection response timer */
    mmi_brw_app_stop_server_connection_timer();
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    if (mmi_brw_app_is_browser_first_accessed_page())
    {
        mmi_brw_app_stop_splash_screen_timer();
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_SPLASH_SCREEN)
        {
            mmi_brw_app_pre_entry_render_page();
            mmi_frm_scrn_close(g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SPLASH_SCREEN);
        }
    }
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

#ifdef WAP_SEC_SUPPORT
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->security_id >= 0)
    {
        mmi_brw_app_set_status_icon(MMI_TRUE);
    }
    else
    {
        mmi_brw_app_set_status_icon(MMI_FALSE);
    }
#endif /* WAP_SEC_SUPPORT */
#ifdef defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (g_brw_app_cntx.isBookmarkLaunched)
    {
        g_brw_app_cntx.isBookmarkLaunched = MMI_FALSE;
    }
#endif /* __MMI_OP11_HOMESCREEN__ */ 

#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status = BRW_FETCHING_STATUS_LOADING;
    mmi_brw_app_ui_draw_ren_page_progressive_bar(g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress, (S8*) GetString(STR_ID_BRW_LOADING));
#else /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 
    mmi_brw_app_set_ren_page_title_string();
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 
#ifdef SLIM_WAP_MMS
#ifdef __MMI_WAP_IMAGE_CACHE_TCARD__
    if(!g_brw_app_cntx.brw_dynamic_cntx_p->is_images_popup_shown)
    {
        if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_ID_BRW_IMAGES_NOT_AVAILABLE),
                MMI_EVENT_FAILURE);
            g_brw_app_cntx.brw_dynamic_cntx_p->is_images_popup_shown = MMI_TRUE;
        }
    }
#endif
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_notify_app_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_NOTIFY_APP_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_notify_app_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_set_ren_page_title_string();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_show_auth_dialog_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SHOW_AUTH_DLG emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_show_auth_dialog_proc(mmi_event_struct *evt)
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

    /* stop server connection response timer */
    mmi_brw_app_stop_server_connection_timer();
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    /* stop splash screen timer */
    mmi_brw_app_stop_splash_screen_timer();
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

#ifdef OBIGO_Q05A
    gBrwAuthDlgSaveOptionStringArray[BRW_APP_AUTH_DLG_SAVE_NONE_INDEX] = GetString(STR_ID_BRW_SAVE_NONE);
    gBrwAuthDlgSaveOptionStringArray[BRW_APP_AUTH_DLG_SAVE_BOTH_INDEX] = GetString(STR_ID_BRW_SAVE_BOTH);
    gBrwAuthDlgSaveOptionStringArray[BRW_APP_AUTH_DLG_SAVE_USERNAME_INDEX] = GetString(STR_ID_BRW_SAVE_ONLY_USERNAME);
#endif

    memset(g_brw_auth_username, 0, sizeof(g_brw_auth_username));
    memset(g_brw_auth_password, 0, sizeof(g_brw_auth_password));
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_auth_username,
        (WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.http_auth_info_p->username);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_auth_password,
        (WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.http_auth_info_p->password);

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_HIGH_SCRN, MMI_EVENT_NON_TONE, mmi_brw_app_pre_entry_auth_dialog_screen, NULL);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_sec_confirm_dlg_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SEC_CONFIRM_DLG emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_sec_confirm_dlg_proc(mmi_event_struct *evt)
{
#ifdef WAP_SEC_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_confirm_action_event_struct *event = (srv_brw_confirm_action_event_struct*)evt;
    wps_show_confirm_dialog_ind_struct *sec = (wps_show_confirm_dialog_ind_struct*)event->data_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RMGR_SEAMLESS_UNLOCK__
    mmi_rmgr_unlock_session_callback();
#endif 

    /* stop server connection response timer */
    mmi_brw_app_stop_server_connection_timer();
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    /* stop splash screen timer */
    mmi_brw_app_stop_splash_screen_timer();
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

    if (!g_brw_app_cntx.sec_confirm_dlg_info_p)
    {
        g_brw_app_cntx.sec_confirm_dlg_info_p = (wps_show_confirm_dialog_ind_struct*)
            OslMalloc(sizeof(wps_show_confirm_dialog_ind_struct));
    }
    g_brw_app_cntx.sec_confirm_dlg_info_p->request_id = sec->request_id;
    g_brw_app_cntx.sec_confirm_dlg_info_p->dialog_type = sec->dialog_type;
    g_brw_app_cntx.sec_confirm_dlg_info_p->buttons = sec->buttons;
    g_brw_app_cntx.sec_confirm_dlg_info_p->title_id = sec->title_id;
    g_brw_app_cntx.sec_confirm_dlg_info_p->text_id = sec->text_id;

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_HIGH_SCRN,MMI_EVENT_DEFAULT, mmi_brw_app_pre_entry_sec_confirm_screen, NULL);
#endif /* WAP_SEC_SUPPORT */
    return MMI_RET_OK;
} 


#ifdef WAP_SEC_SUPPORT

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_session_info
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get session info request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_session_info(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *localBuff_p = (wps_sec_get_session_info_rsp_struct*) obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_wps_error_code(result))
    {
        return;
    }

	if (g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p == NULL)
	{
		g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p =
			(mmi_brw_get_session_info_rsp_struct*) srv_brw_malloc(sizeof(mmi_brw_get_session_info_rsp_struct));
	}
	g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->key_exchange_alg = localBuff_p->key_exchange_alg;
	g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->blk_encrypt_alg = localBuff_p->blk_encrypt_alg;
	g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->hash_alg = localBuff_p->hash_alg;
	g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p->sec_conn_type = localBuff_p->sec_conn_type;

    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    g_brw_display_info_str = (U8*)srv_brw_malloc((BRW_SESSION_INFO_STR_LEN + 1) * ENCODING_LENGTH);

    mmi_brw_app_dmgr_get_session_info_str(g_brw_display_info_str);

    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE,
                                               mmi_brw_app_if_show_view_certificate_screen,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_current_cert
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get current cert request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_current_cert(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_wps_error_code(result))
    {
        return;
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p == NULL)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p =
            (mmi_brw_certificate_content_struct*) srv_brw_malloc(sizeof(mmi_brw_certificate_content_struct));
    }

    mmi_brw_app_dmgr_copy_current_certificate(g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p, (wps_sec_get_current_cert_rsp_struct*)obj);

    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    g_brw_display_info_str = (U8*)srv_brw_malloc((BRW_CURRENT_CERT_STR_LEN + 1) * ENCODING_LENGTH);

    mmi_brw_app_dmgr_get_certificate_str(g_brw_display_info_str,
                                         g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p);

    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE,
                                               mmi_brw_app_if_show_view_certificate_screen,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);

}
#endif /* WAP_SEC_SUPPORT */
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_get_trusted_cert_list
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * get trusted cert request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_get_trusted_cert_list(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_list_rsp_struct *list_data = (srv_brw_list_rsp_struct*)obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_app_check_wps_error_code(result))
    {
        return;
    }
    if(list_data->num_count == 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE);
        }
        mmi_brw_app_delete_busy_screen();
        return;
    }

    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_TRUSTED_CERTIFICATES,
                                               mmi_brw_app_if_show_trusted_certificates_list,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_delete_trusted_cert
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * delete trusted cert request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_delete_trusted_cert(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
    {
        if (result != WPS_OK)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
                MMI_EVENT_PROPLEM);
        }
    }
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_BUSY_SCREEN);
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_view_trusted_cert
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * delete trusted cert request to handle the tasks that should be performed on 
 * receiving the confirmation
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_view_trusted_cert(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *data = (wps_sec_get_cert_rsp_struct*)obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result || (data->cert_id != (U32)user_data))
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_BUSY_SCREEN)
        {
            mmi_brw_app_ui_draw_display_popup(
                (U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
                MMI_EVENT_PROPLEM);
        }
        mmi_brw_app_delete_busy_screen();
        return;
    }

    if (!g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p = (mmi_brw_certificate_content_struct*) srv_brw_malloc(sizeof(mmi_brw_certificate_content_struct));
    }

    mmi_brw_app_dmgr_copy_trusted_certificate(g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p, &data->cert);

    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    g_brw_display_info_str = (U8*)srv_brw_malloc((BRW_CURRENT_CERT_STR_LEN + 1) * ENCODING_LENGTH);

    mmi_brw_app_dmgr_get_certificate_str((U8*) g_brw_display_info_str, 
                                         g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p);


    mmi_brw_app_launch_if_or_insert_in_history(SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE,
                                               mmi_brw_app_if_show_view_certificate_screen,
                                               g_brw_app_cntx.brw_scr_group_id,
                                               NULL);

}

#endif /* WAP_SEC_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_select_file_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SELECT_FILE_IND emitted by the Browser service
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_select_file_proc(mmi_event_struct *evt)
{
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_FILE_MANAGER__)
    mmi_brw_app_if_select_upload_file();
#else /* defined (__MMI_FILE_MANAGER__) */ 
    srv_brw_select_file_rsp(WAP_BAM_ERROR_FILE_SELECTION_FAILED, (U8*) NULL);
#endif /* defined (__MMI_FILE_MANAGER__) */ 
    mmi_brw_app_delete_busy_screen();
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_start_transaction_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_start_transaction_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_START_TRANSACTION, g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserFetching);

    /* start server connection request timer */
    StartTimer(
        BRW_SERVER_CONNECTION_TIMER,
        g_srv_brw_cntx.timeout_value * 1000,
        mmi_brw_app_if_server_connection_timer_callback);
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
    g_brw_app_cntx.brw_dynamic_cntx_p->is_page_size_checked = MMI_FALSE;
#endif 
#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
    /* start loading time timer */
    if (WAP_CUSTOM_CFG_BRW_LOADING_TIME_THRESHOLD > 0)
    {
        StartTimer(
            BRW_LOADING_TIME_CHECK_TIMER,
            WAP_CUSTOM_CFG_BRW_LOADING_TIME_THRESHOLD * 60 * 1000,
            mmi_brw_app_if_loading_time_check_timer_callback);
    }
#endif /* __MMI_BRW_LOADING_TIME_CHECKING__ */ 
    g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting = MMI_FALSE;

    if (!g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action)
    {
        mmi_brw_app_ren_page_set_LSK();
        mmi_brw_app_ren_page_set_RSK();
    #ifdef __MMI_FTE_SUPPORT__
        mmi_brw_app_change_ren_page_FTE_toolbar_state();
    #endif
    }
#ifdef OBIGO_Q05A
    if (g_brw_app_cntx.brw_dynamic_cntx_p->encoding_type_new_flag)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->encoding_type_new_flag = MMI_FALSE;
    }
    else
    {
        /* setting encoding method to "Auto Select" */
        g_srv_brw_cntx.encoding_method_index = 0;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX);
    }
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    /* Set the upload completed flag to false */
    g_brw_app_cntx.brw_dynamic_cntx_p->upload_status = BRW_UPLOAD_STATUS_UPLOADING;
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */

#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status = BRW_FETCHING_STATUS_CONNECTING;
    g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress = 0;
    mmi_brw_app_ui_draw_ren_page_progressive_bar(
        g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress,
        (S8*) GetString(STR_ID_BRW_CONNECTING));
#else    
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
    mmi_brw_app_set_ren_page_title_icon();
#endif
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_continue_transaction_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_continue_transaction_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_rendering_status_event_struct *event = (srv_brw_rendering_status_event_struct*)evt;
    srv_brw_rendering_status_struct *status = (srv_brw_rendering_status_struct*)event->ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
    if (g_brw_app_cntx.brw_dynamic_cntx_p->is_page_size_checked == MMI_FALSE)
    {
        if ((WAP_CUSTOM_CFG_BRW_PAGE_SIZE_THRESHOLD > 0) && (status->document_bytes_read > 0))
        {
            U32 total_bytes;

            total_bytes = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->document_bytes_total + status->resources_bytes;
            if (total_bytes > (WAP_CUSTOM_CFG_BRW_PAGE_SIZE_THRESHOLD * 1024))
            {
                if ((status->document_number_of_requested >
                     (status->document_number_of_downloaded + status->document_number_of_failed)) &&
                    (status->resources_number_of_requested >
                     (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_downloaded + g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_failed)))
                {
                    g_brw_app_cntx.brw_dynamic_cntx_p->is_page_size_checked = MMI_TRUE;
                    mmi_brw_app_page_size_checking();
                }
            }
        }
    }
#endif /* __MMI_BRW_PAGE_SIZE_CHECKING__ */ 
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    /* If the uploading has not completed */
    if (g_brw_app_cntx.brw_dynamic_cntx_p->upload_status == BRW_UPLOAD_STATUS_UPLOADING)
    {
        /* If the upload bytes sent and total both are greater than 0
           then call the mmi_brw_show_upload_progress funtion to show
           the upload progress to the user */
        if ( g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent > 0 &&
             g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total > 0)
        {
            mmi_brw_app_show_upload_progress();
            /* If the uploading has completed then start the 2 second timer */
            if (g_brw_app_cntx.brw_dynamic_cntx_p->upload_status == BRW_UPLOAD_STATUS_COMPLETE)
            {
                StartTimer(
                    BRW_UPLOAD_COMPLETED_TIMER,
                    BRW_UPLOAD_PROGRESS_TIMER_VALUE,
                    mmi_brw_app_if_upload_completed_timer_callback);
            }
        }
    }
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    mmi_brw_app_update_fetching_progress();
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */

#if (defined __MMI_BRW_PAGE_FETCHING_STATUS__ || defined __MMI_BRW_FILE_UPLOAD_SUPPORT__ )
#ifdef OBIGO_Q03C_BROWSER
    bam_received_transaction_status();
#endif
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_end_transaction_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_end_transaction_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prevScrId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_END_TRANSACTION,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching,
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p,
        mmi_brw_app_is_browser_launched_from_main_menu());
    /* if currently the Uploading was going on then remove the uploading screens */
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    if (g_brw_app_cntx.brw_dynamic_cntx_p->upload_status == BRW_UPLOAD_STATUS_UPLOADING)
    {
        mmi_brw_app_remove_upload_screens();
    }
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
    {
        /* stop server connection response timer */
        mmi_brw_app_stop_server_connection_timer();
    #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        /* stop the splash screen timer */
        mmi_brw_app_stop_splash_screen_timer();
    #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        /* stop timer and page size checking */
    #ifdef __MMI_BRW_LOADING_TIME_CHECKING__
        StopTimer(BRW_LOADING_TIME_CHECK_TIMER);
    #endif 

    #if defined (__MMI_BRW_PAGE_SIZE_CHECKING__) || defined (__MMI_BRW_LOADING_TIME_CHECKING__)
        mmi_brw_app_remove_loading_size_time_screens();
    #endif 

        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
        #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
            mmi_brw_app_set_ren_page_title_icon();
        #endif
            mmi_brw_app_ren_page_set_LSK();
            mmi_brw_app_ren_page_set_RSK();
        #ifdef __MMI_FTE_SUPPORT__
            mmi_brw_app_change_ren_page_FTE_toolbar_state();
        #endif
            g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_FALSE;
            mmi_frm_group_close(BRW_SCREEN_GROUP);
            mmi_frm_group_close(BRW_RENDERED_PAGE_OPTIONS_GRP_ID);
        #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
            mmi_frm_group_close(BRW_GRP_ID_FILE_UPLOAD);
        #endif

        }
        else if (mmi_brw_app_is_browser_launched_from_main_menu())
        {
        #ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
            if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer)
        #endif
            {
             #ifndef OBIGO_Q05A
                bam_reset_open_bearer_status();
             #endif
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
                mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_BROWSER_MAIN);
            #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
                mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_SPLASH_SCREEN);
            #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
            }
        }
        else
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
            g_brw_app_cntx.brw_dynamic_cntx_p->isBrowserWaiting = MMI_TRUE;
            mmi_frm_group_close(BRW_SCREEN_GROUP);
            mmi_frm_group_close(BRW_RENDERED_PAGE_OPTIONS_GRP_ID);
        #ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_SPLASH_SCREEN)
            {
                mmi_brw_app_if_show_rendered_page_screen();
            }
        #endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
        #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
            mmi_brw_app_set_ren_page_title_icon();
        #endif
            mmi_brw_app_ren_page_set_LSK();
            mmi_brw_app_ren_page_set_RSK();
            #ifdef __MMI_FTE_SUPPORT__
                mmi_brw_app_change_ren_page_FTE_toolbar_state();
            #endif
        }
        /* Remove security and authentication dialogs, if present */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_SHOW_AUTH_DIALOG)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_SHOW_AUTH_DIALOG);
        }
    }
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = MMI_FALSE;
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
    mmi_brw_app_ui_draw_disable_ren_page_progressive_bar();
    mmi_brw_app_set_ren_page_title_string();
    g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status = BRW_TOTAL_FETCHING_STATUS;
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */ 
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 52, 0, 0, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_NONE;
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer = MMI_FALSE;
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_load_url_req
 * DESCRIPTION
 *  This func is to send the load url request to browser service
 * PARAMETERS
 *  url     [IN]        The url to be loaded
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_load_url_req(U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
    if(g_brw_app_cntx.brw_dynamic_cntx_p->load_req_processing)
    {
        return;
    }
    g_brw_app_cntx.brw_dynamic_cntx_p->load_req_processing = MMI_TRUE;
#endif

    srv_brw_load_url_req(url, WAP_BAM_UNKNOWN_CHARSET);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_load_data_req
 * DESCRIPTION
 *  This func is to send the load data request to browser service
 * PARAMETERS
 *  url     [IN]        The url to be loaded
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_load_data_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_load_data_req(g_brw_open_file_cntx.file_path);
}
#endif /* OBIGO_Q05A */


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_open_stored_page
 * DESCRIPTION
 *  This func is to send the load stored page request to browser service
 * PARAMETERS
 *  url     [IN]        The url to be loaded
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_open_stored_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_load_stored_page_req(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */ 


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_open_recent_page
 * DESCRIPTION
 *  This func is to send the load recent page request to browser service
 * PARAMETERS
 *  url     [IN]        The url to be loaded
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_open_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 actual_recent_page_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    actual_recent_page_index = srv_brw_recent_page_get_actual_index(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    srv_brw_load_recent_page_req(actual_recent_page_index);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_set_profile_req
 * DESCRIPTION
 *  This func is used for getting the profile content from the service and
 * then calling the service API to send the set profile req to BAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_set_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_content_p;
    srv_brw_act_req_struct obj = {0};
    srv_brw_set_profile_req_struct prof = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_get_profile_content((void **)&profile_content_p);

    obj.rsp_callback = mmi_brw_srv_hdlr_set_profile;
    prof.currprof = profile_content_p;
#ifdef OBIGO_Q03C_BROWSER
    if (!g_srv_brw_cntx.isWapReady)
    {
        prof.setting_id = wap_bam_setting_type_both;
    }
    else if (g_brw_app_cntx.brw_launching_pad == BRW_LPD_SETTINGS_PREF
        #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
            || g_brw_app_cntx.brw_launching_pad == BRW_LPD_RESTORE_BRW_SETTINGS
        #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
            )
    {
        prof.setting_id = wap_bam_setting_type_settings;
    }
    else
    {
        prof.setting_id = wap_bam_setting_type_profile;
    }
#endif /* OBIGO_Q03C_BROWSER */
    obj.req_data = (void*)&prof;

    srv_brw_set_profile_req_by_data(&obj);

    OslMfree(profile_content_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_wait_user_action_rsp
 * DESCRIPTION
 *  This func is used for sending the response of the user on the prompt screen
 * displayed by OWL/Widget
 * PARAMETERS
 *  positive_key_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_wait_user_action_rsp(MMI_BOOL positive_key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    srv_brw_wait_user_action_rsp(positive_key_state);
#else /* OBIGO_Q05A */
    widget_MMI_key_handler();
#endif /* OBIGO_Q05A */
    g_brw_app_cntx.brw_dynamic_cntx_p->is_wait_user_action = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_delete_instance_req
 * DESCRIPTION
 *  This func is used for sending the delete_instance request to Browser 
 * Service for deleting the Browser instance and closing the Browser session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_delete_instance_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj.rsp_callback = mmi_brw_srv_hdlr_delete_instance;
    srv_brw_delete_instance_req(&obj);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_notify_screen_info
 * DESCRIPTION
 *  This function is to send the notification for screen information to BAM 
 * PARAMETERS
 *  refresh     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_notify_screen_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE title_layer = 0;
    GDI_HANDLE bottom_layer = 0;
    U32 x = 0;
    U32 y = 0;
    U32 w = 0;
    U32 h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat431GetScreenInfo(g_srv_brw_cntx.screen_size_status, &x, &y, &w, &h, &title_layer, &bottom_layer);
    bam_notify_screen_info(x, y, w, h, title_layer, bottom_layer, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_srv_hdlr_clear_data_req
 * DESCRIPTION
 *  This func is used for sending the clear data request to service for clearing
 * the type of data value passed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_srv_hdlr_clear_data_req(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_show_progress_screen(STR_ID_BRW_BROWSER_OPTIONS, STR_GLOBAL_PLEASE_WAIT);
    obj.rsp_callback = mmi_brw_srv_hdlr_clear_data;
    data.index = type;
    obj.req_data = (void*)&data;
    srv_brw_settings_clear_data_req(&obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_error_popup_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_URI_REQ_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_error_popup_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_show_popup_event_struct *popup_evt = (srv_brw_show_popup_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(popup_evt->error_code == SRV_BRW_WAP_NOT_READY)
    {
        mmi_brw_app_ui_draw_display_popup(
            (U8*) GetString(STR_ID_BRW_WAP_NOT_READY),
            MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_brw_app_ui_draw_display_popup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_EXPLICITLY_SAVED);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_start_browser_action_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_START_BROWSER_ACTION_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_start_browser_action_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_startup_req_event_struct *startup_evt = (srv_brw_startup_req_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2ncpy((S8*) g_brw_current_url, (S8*)startup_evt->url_ucs2, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	mmi_brw_start_browser_action(startup_evt->req_type, (U8*)g_brw_current_url);
    return MMI_RET_OK;
}


#ifdef __SAT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_pre_entry_sat_launch
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SAT_LAUNCH_REQ emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_pre_entry_sat_launch(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_sat_launch_req_struct *sat_evt = (srv_brw_sat_launch_req_struct*)arg;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_brw_active_sim_setting_enum sat_sim_setting = sat_evt->sim_setting;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_launching_pad = BRW_LPD_SAT_LAUNCH_REQ;
#ifdef __MMI_WLAN_FEATURES__
    g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_NO_WIFI;
#endif
    mmi_ucs2cpy((S8*)g_brw_current_url, (S8*) sat_evt->url);
    if (sat_evt->browserMode == 0x00 || sat_evt->browserMode == 0x02 || sat_evt->browserMode == 0x01)
    {
        /* launch browser, if not already launched. 
           nothing to do */
        if (mmi_brw_is_browser_active())
        {
            /* if browser is fetching then stop it */
            if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
            {
                srv_brw_stop_page_fetching_req();
            }

        #if (MMI_MAX_SIM_NUM >= 2)
        /* in case of dual sim if a profile of different sim is being activated then wait for 
            the bearer to get deactivated before launching the new URL */
            if (g_srv_brw_cntx.session_sim_id != sat_evt->sim_setting)
            {
                 /* releasing the bearer if held and the profile is being updated */
                if (srv_brw_is_holding_bearer())
                {
                    srv_brw_set_bearer(MMI_FALSE);
                }

                g_brw_app_cntx.brw_launching_pad = BRW_LPD_TEMP_PROFILE_CHANGED;
                g_srv_brw_cntx.is_profile_req_received = MMI_FALSE;
            }
            g_srv_brw_cntx.session_sim_id = sat_evt->sim_setting;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */

            /* showing the busy screen */
            mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
            
            /* setting the SAT profile */
            mmi_brw_app_srv_hdlr_set_profile_req();
        }
        else
        {
            if(!g_srv_brw_cntx.is_create_instance_processing)
            {
            #if (MMI_MAX_SIM_NUM >= 2)
                if (g_srv_brw_cntx.session_sim_id != sat_evt->sim_setting)
                {
                    g_brw_app_cntx.sat_profile_update = MMI_TRUE;
                }
                g_srv_brw_cntx.session_sim_id = sat_sim_setting;
            #endif
                mmi_brw_app_common_gateway();
            }
        }
    }
    else if (sat_evt->browserMode == 0x03)
    {
        /* close the existing browser session and launch new browser session */
        if (mmi_brw_is_browser_active())
        {
            mmi_brw_app_deinit();
#if (MMI_MAX_SIM_NUM >= 2)
            if (g_srv_brw_cntx.session_sim_id != sat_evt->sim_setting)
            {
                g_brw_app_cntx.sat_profile_update = MMI_TRUE;
            }
            g_srv_brw_cntx.session_sim_id = sat_sim_setting;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
        else
        {
            if(!g_srv_brw_cntx.is_create_instance_processing)
            {
                mmi_brw_app_common_gateway();
            }
        }
    }
#ifdef __MMI_WLAN_FEATURES__
    g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_WIFI;
#endif
    OslMfree(sat_evt->url);
    OslMfree(sat_evt);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_sat_launch_req_proc
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SAT_LAUNCH_REQ emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_sat_launch_req_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_sat_launch_req_struct *recv_sat_evt = (srv_brw_sat_launch_req_struct*)evt;
    srv_brw_sat_launch_req_struct *sat_evt = (srv_brw_sat_launch_req_struct*)OslMalloc(sizeof(srv_brw_sat_launch_req_struct));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sat_evt->url = (U8*)OslMalloc(ENCODING_LENGTH * (mmi_ucs2strlen((CHAR*) recv_sat_evt->url) + 1));
    mmi_ucs2cpy((S8*) sat_evt->url, (S8*) recv_sat_evt->url);
    sat_evt->browserMode = recv_sat_evt->browserMode;
    sat_evt->sim_setting = recv_sat_evt->sim_setting;
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_HIGH_SCRN, MMI_EVENT_NON_TONE, mmi_brw_app_pre_entry_sat_launch, sat_evt);
    return MMI_RET_OK;
}
#endif /* __SAT__ */

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_close_sockets
 * DESCRIPTION
 *  This func is the handler function passed to the Browser Service with the
 * close sockets request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_srv_hdlr_close_sockets(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 8, 0, 0, 0);
    ret = mmi_brw_app_open_bearer_ext();
    g_brw_app_cntx.brw_launching_pad = BRW_LPD_WIFI_PREFER_RELAUNCH;
    if(ret == CBM_WOULDBLOCK)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 23, 0, 0, 0);
        g_brw_app_cntx.brw_launching_pad = BRW_LPD_WIFI_PREFER_RELAUNCH;
    }
    else if (ret == CBM_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 24, 0, 0, 0);
        mmi_brw_app_continue_relaunch_browser();
    }
    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_srv_hdlr_open_bearer
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_OPEN_BEARER_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_srv_hdlr_open_bearer(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret_code = CBM_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_brw_app_open_bearer_ext();
    if (ret_code == CBM_OK)
    {
        srv_brw_open_bearer_rsp(1);
    }
    else if(ret_code != CBM_WOULDBLOCK)
    {
        srv_brw_open_bearer_rsp(0);
    }
    if(ret_code == CBM_WOULDBLOCK)
    {
        mmi_brw_app_stop_server_connection_timer();
    }

    return MMI_RET_OK;
}

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSRVHDLR_C */
