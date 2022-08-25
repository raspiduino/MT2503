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
 *   WlanAppCore.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Logic flow for handling all kinds of event
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifdef __TCPIP__
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_WLAN_FEATURES__
#include "DtcntSrvIprot.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "DataAccountDef.h"
#include "DataAccountStruct.h"
#include "wndrv_cnst.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "mmi_frm_events_gprot.h"
#include "stdlib.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_history_gprot.h"
#include "gui_typedef.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "custom_events_notify.h"
#include "CommonScreens.h"
#include "DataAccountEnum.h"
#include "supc_abm_msgs.h"
#include "wndrv_supc_types.h"
#include "DataAccountProt.h"
#include "stdio.h"
#include "ModeSwitchSrvGProt.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#ifdef __MMI_CCA_SUPPORT__
#include "mmi_rp_app_cca_def.h"
#endif
#include "TimerEvents.h"
#include "DataAccountCore.h"
#include "wgui_categories_text_viewer.h"
/***************************************************************************** 
 * Global variable
 *****************************************************************************/
extern mmi_id wlan_parent_group_id;
extern supc_abm_bss_info_struct g_cui_hilt_profile;
extern supc_abm_bss_info_struct g_wlan_hilt_profile;
extern U8 g_auto_conn_ap_total;
extern U8 g_auto_conn_ap_idx;
extern mmi_id g_wlan_ap_list_group_id;     
extern mmi_id g_wlan_ap_list_cui_id;
extern MMI_BOOL g_wapi_test_mode;
extern srv_dtcnt_prof_wlan_struct g_srv_wlan_prof;
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_profile_struct g_profile_saved_temp;
MMI_BOOL is_insert_disconn;
MMI_BOOL is_sleep;
MMI_BOOL scan_after_abort_connect;
mmi_wlan_auto_conn_cb_func_ptr  g_auto_conn_cb;

/***************************************************************************** 
 * Function declaration
 *****************************************************************************/
 //remove for option slim
#if 0
/* under construction !*/
#endif
static void mmi_wlan_after_connect_success(srv_dtcnt_wlan_conn_res_struct *cnf, supc_abm_bss_info_struct *active_ap);
static void mmi_wlan_after_connect_failed(srv_dtcnt_wlan_conn_res_struct *cnf);
static void mmi_wlan_update_scrn_after_connect(srv_dtcnt_wlan_conn_res_struct *cnf);
static void mmi_wlan_after_scan_network_success(srv_dtcnt_wlan_scan_result_struct *cnf);
void mmi_wlan_list_auto_conn_scan_result_cb(U32 job_id, void *user_data, srv_dtcnt_wlan_scan_result_struct *scan_res);
void mmi_wlan_list_auto_conn_start(srv_dtcnt_wlan_scan_result_struct *scan_res);
void mmi_wlan_list_auto_conn_inform_caller(mmi_wlan_auto_conn_action_enum action);
void mmi_wlan_set_power_saving_mode_cb(void *user_data, srv_dtcnt_wlan_req_res_enum res);

//remove for option slim
#if 0
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_dtcnt_query_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof_id      [IN]   profile id of wlan profile 
 *  dtcnt_prof   [IN]   structure to store profile's info 
 * RETURNS
 *  srv_dtcnt_result_enum: SRV_DTCNT_RESULT_SUCCESS | FAILED
 *****************************************************************************/
srv_dtcnt_result_enum mmi_wlan_dtcnt_query_profile(U32 prof_id, srv_dtcnt_prof_wlan_struct *dtcnt_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct prof_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_info.prof_type = SRV_DTCNT_BEARER_WIFI;
    prof_info.prof_data = dtcnt_prof;
    prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    result =  srv_dtcnt_store_qry_prof(prof_id, &prof_info);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_dtcnt_store_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_prof      [IN]   wlan app profile.
 *  is_add        [IN]   add or update
 *  fields        [IN]   elements need to add or update
 * RETURNS
 *  Return SRV_DTCNT_RESULT_SUCCESS on success, otherwise return error code.
 *****************************************************************************/
srv_dtcnt_result_enum mmi_wlan_dtcnt_store_profile(mmi_wlan_profile_struct *app_prof, U32 is_add, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct wlan_prof_data;
    srv_dtcnt_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_STORE_PROF, is_add);
    
    mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, app_prof, 0);

    wlan_prof_data.prof_data = &g_srv_wlan_prof;
    wlan_prof_data.prof_fields = fields;
    wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

    if (is_add)
    {
        result =  srv_dtcnt_store_add_prof(&wlan_prof_data, &(app_prof->profile_id));
    }
    else
    {
        result =  srv_dtcnt_store_update_prof(app_prof->profile_id, &wlan_prof_data);
    }

    ASSERT(result == SRV_DTCNT_RESULT_SUCCESS);
    
    return result;
}

//remove for option slim
#if 0
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_connect_request
 * DESCRIPTION
 *  send connect request to data account service.
 *
 * PARAMETERS
 *  app_prof      [IN]   wlan profile     
 * RETURNS
 *  Return SRV_DTCNT_RESULT_SUCCESS on success, otherwise return error code. 
 *****************************************************************************/
srv_dtcnt_result_enum mmi_wlan_send_connect_request(mmi_wlan_profile_struct *app_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_conn_prof_struct conn_prof;
    srv_dtcnt_prof_wlan_struct *srv_prof;
    srv_dtcnt_result_enum retn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.conn_num++;
    
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, TRUE);

    mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, app_prof, 0);
    srv_prof = &g_srv_wlan_prof;

    conn_prof.num_prof = 1;
    conn_prof.prof_data= &srv_prof;
    conn_prof.connect_type = ONE_PROFILE_SELECT;
#ifdef __WPS_SUPPORT__
    if(MMI_WLAN_UI_CONNECT_BY_WPS == mmi_wlan_get_ui_flow ())
    {
        conn_prof.connect_type = g_wlan_display_context.conn_type;
    }
#endif
    g_wlan_display_context.send_conn_req_ing = MMI_TRUE;
    cui_menu_close(g_wlan_display_context.option_menu_cui_id);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_PREPARE_CONN_PROFILE, 
        g_wlan_display_context.conn_num, g_wlan_display_context.ui_flow);
	if(srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED)
	{
	    is_insert_disconn = MMI_TRUE;
	}
    retn = srv_dtcnt_wlan_connect_by_app_prof(&conn_prof, NULL, NULL);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_APP_PROF, 
        retn, srv_prof->profile_id, srv_prof->ssid_len, srv_prof->priority);
    
    return retn;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_scan_request
 * DESCRIPTION
 *  send scan request to data account service.
 *  
 * PARAMETERS
 *  callback    -   WLAN scan result callback function
 *  user_data   -   User data
 * RETURNS
 *  U32 - scan job id. 
 *****************************************************************************/
U32 mmi_wlan_send_scan_request(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data)
{
    if (g_wlan_display_context.ui_flow == MMI_WLAN_UI_ABORT_CONNECT)
    {
        scan_after_abort_connect = MMI_TRUE;
    }
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_SCANNING);

    g_wlan_display_context.scan_job_id = srv_dtcnt_wlan_scan(callback, user_data);

    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, TRUE);
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SCAN_JOB, g_wlan_display_context.scan_job_id);

    return g_wlan_display_context.scan_job_id;
}
//remove for option slim
#if 0
/* under construction !*/
#endif
 /*****************************************************************************
 * FUNCTION
 *  mmi_wlan_activate_event_hdlr
 * DESCRIPTION
 *  function to handle the active indication.
 * PARAMETERS
 *    void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_activate_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init_event_hdlr
 * DESCRIPTION
 *  function to handle the init indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_init_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_init_res_ind_evt_struct *init_evt;
    srv_dtcnt_result_enum result;
    srv_dtcnt_wlan_power_mode_enum power_save_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_TOTAL;
	mmi_frm_node_struct node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_evt = (srv_dtcnt_wlan_init_res_ind_evt_struct *)param;

    //mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
    mmi_wlan_set_status_bar_icon();
    memcpy(g_wlan_display_context.mac_addr, init_evt->mac_addr, WNDRV_MAC_ADDRESS_LEN);

	mmi_frm_node_info_init (&node);
	node.id = SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST;
	node.entry_proc = (mmi_proc_func) mmi_wlan_entry_new_wizard_list;
	mmi_frm_scrn_insert (wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST, &node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
	mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);

    // set power saving mode
    if (srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_NULL &&
		srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
    {
	    result = srv_dtcnt_wlan_get_power_mode (&power_save_mode);
	    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_GET_POWER_SAVING_MODE, power_save_mode);
	    if(SRV_DTCNT_RESULT_SUCCESS == result)
	    {
	        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SET_POWER_SAVING_MODE, power_save_mode);
	        srv_dtcnt_wlan_set_power_mode(
	            power_save_mode,
	            mmi_wlan_set_power_saving_mode_cb,
	            NULL);
	    }
    }
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
    // return when scanning for network 
    if(MMI_WLAN_UI_SCANNING == mmi_wlan_get_ui_flow ())
    {
        return;
    }

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST)
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ENABLED_BACKGROUND)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);
        
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST);
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST ||
             mmi_frm_scrn_is_present(wlan_parent_group_id, 
                                     SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST, 
                                     MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ENABLED_BACKGROUND)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);
        
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
        mmi_frm_group_close(wlan_parent_group_id);
        /* Close certificates selection page */ 
#ifdef __CERTMAN_SUPPORT__
         mmi_certman_select_certificates_ind(
             MOD_MMI, 
             (kal_bool)MMI_CERTMAN_CANCEL, 
             KAL_FALSE, 
             0, 
             MMI_CERTMAN_CERT_GROUP_ALL, 
             MMI_CERTMAN_CERT_TYPE_ALL);
#endif /* __CERTMAN_SUPPORT__ */

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_activate_event_hdlr
 * DESCRIPTION
 *  function to handle the active indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_deinit_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_deinit_res_ind_evt_struct* evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_dtcnt_wlan_deinit_res_ind_evt_struct*) param;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DEINIT_EVENT, evt->res);
    if(SRV_DTCNT_WLAN_REQ_RES_DONE != evt->res)
    {
        return;
    }
    is_sleep = MMI_FALSE;
	g_wlan_display_context.deinit_when_connected = MMI_FALSE;
	#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#endif
#endif
    g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
    g_wlan_display_context.connected_wlan_profile = NULL;
    g_wlan_display_context.active_wlan_profile_index = 0;
    mmi_wlan_update_status_icon(0, FALSE);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_PROCESSING ||
        mmi_frm_scrn_is_present(wlan_parent_group_id, 
                                SCR_ID_DTCNT_WLAN_PROCESSING,
                                MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_STORE_PROF, 1);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        mmi_wlan_entry_saved_profile();
#endif
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PROCESSING);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_STORE_PROF, 2);
		#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        mmi_wlan_redraw_conn_status_screen();
#endif
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST || 
             mmi_frm_scrn_is_present(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_STORE_PROF, 5);
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_POWER_OFF)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);

        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PROCESSING);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_TYPE);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
        
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_default_eap_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wep_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_setting_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_tcp_ip_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_ttls_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_peap_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_tls_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_user_info_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.wlan_advan_cui_id);
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_cert_cui_id);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_psk_cui_id);
#endif /* __MMI_HIDE_WAPI__ */
#endif
        
        if (g_wlan_display_context.wlan_editor_cui_id != GRP_ID_INVALID)
        {
            cui_fseditor_close(g_wlan_display_context.wlan_editor_cui_id);
            g_wlan_display_context.wlan_editor_cui_id = GRP_ID_INVALID;
        }
        if (g_wlan_display_context.wlan_inline_editor_cui_id != GRP_ID_INVALID)
        {
            cui_fseditor_close(g_wlan_display_context.wlan_inline_editor_cui_id);
            g_wlan_display_context.wlan_inline_editor_cui_id = GRP_ID_INVALID;
        }
        /* Close certificates selection page */ 
#ifdef __CERTMAN_SUPPORT__
         mmi_certman_select_certificates_ind(
             MOD_MMI, 
             (kal_bool)MMI_CERTMAN_CANCEL, 
             KAL_FALSE, 
             0, 
             MMI_CERTMAN_CERT_GROUP_ALL, 
             MMI_CERTMAN_CERT_TYPE_ALL);
#endif /* __CERTMAN_SUPPORT__ */        
        // Clear history data and close group
        mmi_wlan_network_clear_history_data();
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_STORE_PROF, 7);
        /* After SyncML done, receive deinit event if wifi is off previously*/
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PROCESSING);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
                
        if (g_wlan_display_context.wlan_editor_cui_id != GRP_ID_INVALID)
        {
            cui_fseditor_close(g_wlan_display_context.wlan_editor_cui_id);
        }
        
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_default_eap_cui_id);    
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_connect_event_hdlr
 * DESCRIPTION
 *  function to handle the active indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_connect_res_ind_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_conn_res_ind_evt_struct *conn_evt;
    srv_dtcnt_wlan_conn_res_struct *cnf;
    supc_abm_bss_info_struct *temp_profile;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    conn_evt = (srv_dtcnt_wlan_conn_res_ind_evt_struct *)param;
    cnf = &(conn_evt->conn_result);

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONTEXT_CONN_NUM, 
        g_wlan_display_context.conn_num, g_wlan_display_context.ui_flow);
    is_insert_disconn = MMI_FALSE;
    g_wlan_display_context.send_conn_req_ing = MMI_FALSE;
    if (g_wlan_display_context.conn_num > 0)
    {
        if (--g_wlan_display_context.conn_num > 0)
        {
            if(MMI_WLAN_UI_CONNECT_BY_CUI == mmi_wlan_get_ui_flow ())
            {
                mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            }
            return;
        }
    }
    
    if(MMI_WLAN_UI_CONNECT_BY_CUI == mmi_wlan_get_ui_flow ())
    {
        temp_profile = &g_cui_hilt_profile;
    }
    else
    {   
        temp_profile = &g_wlan_hilt_profile;
    }

    switch(cnf->result)
    {
    case SRV_DTCNT_RESULT_SUCCESS:
        mmi_wlan_after_connect_success (cnf, temp_profile);
        break;
    case SRV_DTCNT_RESULT_FAILED:
    case SRV_DTCNT_RESULT_ABORTED:
    case SRV_DTCNT_RESULT_TERMINATED:
        mmi_wlan_after_connect_failed (cnf);
        break;
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_connect_ind_event_hdlr
 * DESCRIPTION
 *  function to handle the connect indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_connect_ind_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_scrn_id;
    srv_dtcnt_wlan_conn_ind_evt_struct *conn_evt;
    srv_dtcnt_wlan_conn_res_struct *ind;
    mmi_wlan_profile_struct* connected_ap = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0
#ifdef __MMI_OP01_WIFI__    
/* under construction !*/
#endif
#endif
    g_wlan_display_context.send_conn_req_ing = MMI_FALSE;

    if (g_wlan_display_context.conn_num > 0)
    {
        --g_wlan_display_context.conn_num;
    }
    
    conn_evt = (srv_dtcnt_wlan_conn_ind_evt_struct *)param;
    ind = &(conn_evt->conn_result);

    connected_ap = mmi_wlan_search_profile(ind);
	#if 0    
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
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
#endif


    if(connected_ap)
    {
        g_wlan_display_context.connected_wlan_profile = connected_ap;
        g_wlan_display_context.ssid_len = (U8)ind->ssid_len;
        memcpy(g_wlan_display_context.ssid, ind->ssid, ind->ssid_len);
        memcpy(g_wlan_display_context.bssid, ind->bssid, MAX_MAC_ADDR_LEN);
        g_wlan_display_context.curr_channel_number = ind->channel_number;
	g_wlan_display_context.pass_len = ind->passphase_len;
        // update status bar and refresh the main ap list
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
    }
    else
    {
        // send disconnect request ?!
        return;
    }
    
    active_scrn_id = mmi_frm_scrn_get_active_id();
    
    if (active_scrn_id == SCR_ID_DTCNT_WLAN_ABORTING)
    {
        mmi_frm_scrn_close_active_id();
    }
    else if(active_scrn_id == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
	mmi_wlan_show_activated_popup ();
#endif
    }
    else if (active_scrn_id == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
	mmi_wlan_redraw_conn_status_screen();
#endif

    }
    else if (active_scrn_id == SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_REFRESH_PRIORITY_LIST);
        mmi_wlan_refresh_change_priority_list();
    }
    else
    {
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_ABORTING);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_disconnect_event_hdlr
 * DESCRIPTION
 *  function to handle the disconnect indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_disc_res_ind_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISCONNECT_IND_EVENT, 
        g_wlan_display_context.conn_num, g_wlan_display_context.ui_flow);
	if (g_wlan_display_context.deinit_when_connected == MMI_TRUE)
	    return;
    // the number of connection is larger than 1, not to change the status icon in the connecting procedure
    g_wlan_display_context.send_conn_req_ing = MMI_FALSE;

    if ((g_wlan_display_context.conn_num < 1) &&
        (SRV_DTCNT_WLAN_STATUS_ACTIVE == srv_dtcnt_wlan_status ()))
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
    }

    g_wlan_display_context.ssid_len = 0;
    memset(g_wlan_display_context.ssid, 0, MAX_SSID_LEN);
    memset(g_wlan_display_context.bssid, 0, MAX_MAC_ADDR_LEN);
    g_wlan_display_context.connected_wlan_profile = NULL;
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif
#endif


    switch(mmi_wlan_get_ui_flow ())
    {
        case MMI_WLAN_UI_DISC_AFTER_LOGIN_FAILED:
        case MMI_WLAN_UI_PORTAL_LOGOUT:
            mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            break;
        case MMI_WLAN_UI_ABORT_CONNECT:
            if(SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST == mmi_frm_scrn_get_active_id())
            {
            #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
							mmi_wlan_refresh_wizard_main_scrn();
#endif
			

            }
            mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            return;
        default:
            break;
    }
 
    if (g_wlan_display_context.conn_num > 0)
    {        
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_WIFI_SEND_DISCONNECT_CNF_1);
    /* If nothing to do then we can remove the progress screen */
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        mmi_frm_scrn_close_active_id();
        if (is_sleep == MMI_FALSE)
        {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_CNF_SHOW_DISCONNECT_POPUP);
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_DISCONNECTED)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);
    }
    }
	else if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_CUI_WLAN_LIST)
    {
        cui_wlan_disconnect_event_hdlr (param);
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_redraw_conn_status_screen();
#endif

    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_CNF_REFRESH_PRIORITY_LIST);
        mmi_wlan_refresh_change_priority_list();
    }
    else if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_refresh_wizard_main_scrn();
#endif

    }
	#if 0
#ifdef __MMI_OP01_WIFI__    
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
#endif   

    else
    {
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PROCESSING);
    }
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_disconn_event_hdlr
 * DESCRIPTION
 *  function to handle the ipaddr query.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_disc_ind_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_screen_id;
    MMI_ID active_group_id;
    // srv_dtcnt_wlan_disc_ind_evt_struct *disconn_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISCONNECT_EVENT);
    g_wlan_display_context.send_conn_req_ing = MMI_FALSE;
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);

    g_wlan_display_context.ssid_len = 0;
    memset(g_wlan_display_context.ssid, 0x00, MAX_SSID_LEN);
    memset(g_wlan_display_context.bssid, 0x00, MAX_MAC_ADDR_LEN);
    g_wlan_display_context.connected_wlan_profile = NULL;
	#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif    
#endif  


    active_screen_id = mmi_frm_scrn_get_active_id();
    active_group_id  = mmi_frm_group_get_active_id ();
    
    if (active_screen_id == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_redraw_conn_status_screen();
#endif

    }
    /* Refresh ap priority list when receive disconnect indicate */
    else if (active_screen_id == SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_IND_REFRESH_PRIORITY_LIST);
        mmi_wlan_refresh_change_priority_list();
    }    
    else if (active_screen_id == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST
		#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif
#endif

             && is_sleep == MMI_FALSE)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_IND_SHOW_DISCONNECT_POPUP);
        mmi_display_popup((UI_string_type) GetString(STR_ID_DTCNT_WLAN_DISCONNECTED), MMI_EVENT_SUCCESS);
    }
    else if(active_screen_id == SCR_ID_DTCNT_CUI_WLAN_LIST)
    {
        cui_wlan_disconnect_event_hdlr (param);
    }
    else if ((g_wlan_display_context.option_menu_cui_id != GRP_ID_INVALID) &&
        (active_group_id == g_wlan_display_context.option_menu_cui_id) &&
        is_sleep == MMI_FALSE)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_IND_SHOW_DISCONNECT_POPUP);
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_DISCONNECTED)),
            MMI_EVENT_SUCCESS, 
            GRP_ID_ROOT,
            NULL);
    }
    else if (active_screen_id == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        mmi_frm_scrn_close_active_id();
        if (is_sleep == MMI_FALSE)
        {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DISC_CNF_SHOW_DISCONNECT_POPUP);
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_DISCONNECTED)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);
    }
    }
	#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_scan_event_hdlr
 * DESCRIPTION
 *  function to handle the scan confirm.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_scan_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_scan_res_ind_evt_struct *scan_evt;
    srv_dtcnt_wlan_scan_result_struct *scan_result;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scan_evt = (srv_dtcnt_wlan_scan_res_ind_evt_struct *)param;
    scan_result = &(scan_evt->scan_res);

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SCAN_EVENT, scan_result->result);

    switch(scan_result->result)
    {
    case SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS:    /* WLAN scan success */
        mmi_wlan_after_scan_network_success (scan_result);
        break;
    case SRV_DTCNT_WLAN_SCAN_RESULT_FAILED:     /* WLAN scan failed */
    case SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED:    /* WLAN scan service is aborted */
		#if 0
#ifdef __MMI_OP01_WIFI__        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);
        break;
    default:
        break;
    }
    // update status icon bar
    mmi_wlan_set_status_bar_icon ();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_curr_ap_info_event_hdlr
 * DESCRIPTION
 *  function to handle the current ap information indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_curr_ap_info_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_curr_ap_info_evt_struct *ap_evt;
    srv_dtcnt_wlan_curr_ap_info_struct *ind;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AP_INFO_EVENT);

    ap_evt = (srv_dtcnt_wlan_curr_ap_info_evt_struct *)param;
    ind = &(ap_evt->curr_ap_info);

    g_wlan_display_context.rssi = (S32) ind->rssi;
    if(ind->current_data_rate == 0)
    {
	g_wlan_display_context.current_data_rate = ind->ht_current_data_rate;
    }
    else
    {
        g_wlan_display_context.current_data_rate = ind->current_data_rate;
    }
    
    
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_redraw_conn_status_screen();
#endif

    }
    /*else if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        mmi_wlan_redraw_network_settings_screen();
    }*/

    mmi_wlan_update_signal_level_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ipaddr_conflict_event_hdlr
 * DESCRIPTION
 *  function to handle the ipaddr conflict.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_ipaddr_conflict_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
                
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.notification_pending == TRUE ||
        mmi_frm_scrn_is_present(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_IPADDR_CONFILICT_IND, MMI_FRM_NODE_ALL_FLAG) == TRUE ||
        mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_IPADDR_CONFILICT_IND)
    {
        return;
    }
    
    g_wlan_display_context.play_tone_flag = TRUE;
    mmi_dtcnt_entry_ipaddr_conflict_ind();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ipaddr_update_event_hdlr
 * DESCRIPTION
 *  function to handle the ipaddr update indication.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_ipaddr_update_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_ipaddr_update_evt_struct *addr_evt;
    srv_dtcnt_wlan_ipaddr_update_struct *ind;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_evt = (srv_dtcnt_wlan_ipaddr_update_evt_struct *)param;
    ind = &(addr_evt->new_ipaddr);

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_WIFI_IPADDR_UPDATE, ind->ip_addr[0], ind->ip_addr[1], ind->ip_addr[2], ind->ip_addr[3]);
    memcpy(g_wlan_display_context.curr_ip_addr, ind->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_wlan_display_context.curr_netmask, ind->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_wlan_display_context.curr_gateway, ind->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_wlan_display_context.curr_dns1, ind->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_wlan_display_context.curr_dns2, ind->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_redraw_conn_status_screen();
#endif

    }
    g_wlan_display_context.notification_pending = FALSE;
    #if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ipaddr_query_event_hdlr
 * DESCRIPTION
 *  function to handle the ipaddr query.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_ipaddr_change_query_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_ipaddr_change_qry_evt_struct *addr_evt;
    srv_dtcnt_wlan_ipaddr_update_struct ipaddr_info;
    mmi_wlan_profile_struct *prof;
                
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_IPADDR_QUERY_EVENT);
    
    addr_evt = (srv_dtcnt_wlan_ipaddr_change_qry_evt_struct *)param;

    if (is_insert_disconn == MMI_TRUE
	|| g_wlan_display_context.connected_wlan_profile == NULL)
    {
#ifdef __WPS_SUPPORT__
        if(MMI_WLAN_UI_CONNECT_BY_WPS == mmi_wlan_get_ui_flow ())
        {
            prof = &g_profile_saved_temp;
            // Use DHCP by default
            prof->use_dhcp = MMI_TRUE;
        }
        else
        {
            prof = &g_wlan_display_context.temp_profile;
        }
#else
        prof = &g_wlan_display_context.temp_profile;
#endif
        is_insert_disconn = MMI_FALSE;
    }
    else
    {
        prof = g_wlan_display_context.connected_wlan_profile;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_IPADDR_QUERY_INFO, g_wlan_display_context.connected_wlan_profile, prof->use_dhcp);

    memcpy(ipaddr_info.ip_addr, prof->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(ipaddr_info.netmask, prof->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(ipaddr_info.gateway, prof->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(ipaddr_info.dns1, prof->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(ipaddr_info.dns2, prof->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);

    if(!prof->use_dhcp)
    {        
        memcpy(g_wlan_display_context.curr_ip_addr, prof->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(g_wlan_display_context.curr_netmask, prof->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(g_wlan_display_context.curr_gateway, prof->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(g_wlan_display_context.curr_dns1, prof->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(g_wlan_display_context.curr_dns2, prof->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }

    if (addr_evt->ipaddr_change_cb)
    {
        addr_evt->ipaddr_change_cb((MMI_BOOL)prof->use_dhcp, &ipaddr_info);
    }
}
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_chip_invalid_event_hdlr
 * DESCRIPTION
 *  function to handle the chip invalid.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_chip_invalid_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
                
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INIT_FAIL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

}

static void mmi_wlan_after_connect_success(srv_dtcnt_wlan_conn_res_struct *cnf, supc_abm_bss_info_struct *active_ap)
{
    MMI_BOOL update_scrn_flag = MMI_TRUE;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_RESULT_SUCCESS, 
                            g_wlan_display_context.ui_flow, cnf->profile_id);
    if (MMI_WLAN_UI_ABORT_CONNECT == mmi_wlan_get_ui_flow () ||
		scan_after_abort_connect == MMI_TRUE)
    {
        scan_after_abort_connect = MMI_FALSE;
        return;
    }
    
    g_wlan_display_context.wizard_profile_changed = MMI_TRUE;            
    g_wlan_display_context.connected_wlan_profile = mmi_wlan_find_profile(cnf->profile_id);
    g_wlan_display_context.ssid_len = (U8)cnf->ssid_len;
    memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
    //g_wlan_display_context.pass_len = cnf->passphase_len;
    memset(&g_wlan_display_context.ssid, 0, SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
    memcpy(g_wlan_display_context.ssid, cnf->ssid, cnf->ssid_len);
    memcpy(g_wlan_display_context.bssid, cnf->bssid, MAX_MAC_ADDR_LEN);
    g_wlan_display_context.curr_channel_number = cnf->channel_number;
    //mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);

    if (active_ap->rssi > -40)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, FALSE);
    }
    else if (active_ap->rssi > -60)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, FALSE);
    }
    else if (active_ap->rssi > -70)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, FALSE);
    }
    else if (active_ap->rssi > -80)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, FALSE);
    }
    else
    {
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
    }
    if (MMI_WLAN_UI_CONNECT_BY_WPS != mmi_wlan_get_ui_flow () &&
	MMI_WLAN_UI_CONNECT_BY_API != mmi_wlan_get_ui_flow ())
    {
        /* To save the WLAN profile automatically */
        if ((g_wlan_display_context.search_connect_need_save ||
            g_wlan_display_context.connected_wlan_profile == NULL) ||
            g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
        {    
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_EVENT, cnf->ssid_len);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_EVENT, active_ap->ssid_len);
            if (cnf->ssid_len &&
                cnf->ssid_len == active_ap->ssid_len &&
                strncmp((const char*)active_ap->ssid, (const char*)cnf->ssid, cnf->ssid_len) == 0 &&
                g_wlan_display_context.search_connect_need_save == MMI_TRUE)
            {
                mmi_wlan_save_connected_ap(active_ap);
            }
            g_wlan_display_context.search_connect_need_save = MMI_FALSE;
        }
    }

    switch(mmi_wlan_get_ui_flow ())
    {
        case MMI_WLAN_UI_AUTO_CONN:
        case MMI_WLAN_UI_CONNECT_BY_API:
        case MMI_WLAN_UI_CONNECT_BY_CUI:
            if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_REFRESH_MAIN_LIST);
				#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif  /* __MMI_OP01_WIFI__ */
#else
							mmi_wlan_refresh_wizard_main_scrn();
#endif

            }
            
            // Reset flag
            mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            break;
            
#ifdef __WPS_SUPPORT__            
        case MMI_WLAN_UI_CONNECT_BY_WPS:
            // construct the profile according to the property in the event
            mmi_wlan_wps_construct_profile (&g_profile_saved_temp, cnf);
            // find the corresponding profile in the list
            g_wlan_display_context.connected_wlan_profile = 
                mmi_wlan_wps_search_profile (&g_profile_saved_temp, cnf);
            // save it if not found
            if(g_wlan_display_context.connected_wlan_profile == NULL)
            {
                mmi_wlan_wps_save_connected_ap(&g_profile_saved_temp);
            }
            // close info popup
            mmi_wlan_wps_connect_end ();
            update_scrn_flag = MMI_FALSE;
            break;
#endif  /* __WPS_SUPPORT__ */

        default:
            break;
    }
  #if 0  
#ifdef __MMI_OP01_WIFI__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


    if(update_scrn_flag)
    {
        mmi_wlan_update_scrn_after_connect (cnf);
    }
}

static void mmi_wlan_after_connect_failed(srv_dtcnt_wlan_conn_res_struct *cnf)
{
    MMI_BOOL update_scrn_flag = MMI_TRUE;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_EVENT_ERR);
    g_wlan_display_context.connected_wlan_profile = NULL;
    
    // update status icon bar
    if (srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
    }

    switch(mmi_wlan_get_ui_flow ())
    {
        case MMI_WLAN_UI_NONE:
            break;

        case MMI_WLAN_UI_ABORT_CONNECT:
            update_scrn_flag = MMI_FALSE;
            break;
            
        case MMI_WLAN_UI_CONNECT_BY_API:
        case MMI_WLAN_UI_CONNECT_BY_CUI:
            /* if receive connect event in the wizard main list screen */
            /* refresh screen to keep icon in consistence */
            if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_REFRESH_MAIN_LIST);
				#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
							mmi_wlan_refresh_wizard_main_scrn();
#endif

            }

            mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            update_scrn_flag = MMI_FALSE;
            break;
#if 0            
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_OP01_WIFI__ */
#endif

#ifdef __WPS_SUPPORT__
        case MMI_WLAN_UI_CONNECT_BY_WPS:
            mmi_wlan_wps_connect_end ();
            mmi_wlan_popup_conn_result_info(cnf);
            
            update_scrn_flag = MMI_FALSE;
            break;
#endif  /* __WPS_SUPPORT__ */

        default:
            break;
    }

    if(update_scrn_flag)
    {
        mmi_wlan_update_scrn_after_connect(cnf);
    }
}

static void mmi_wlan_update_scrn_after_connect(srv_dtcnt_wlan_conn_res_struct *cnf)
{
    MMI_ID active_scr_id;

    active_scr_id = mmi_frm_scrn_get_active_id();

    // Close "Please Waiting" Popup
    if (mmi_frm_scrn_is_present(
            wlan_parent_group_id, 
            SCR_ID_DTCNT_WLAN_ABORTING, 
            MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_CLOSE_WAITING_POPUP);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

        {
            mmi_wlan_popup_conn_result_info(cnf);
        }
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_ABORTING);
    }
    else if (active_scr_id == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			mmi_wlan_redraw_conn_status_screen();
#endif

    }
    /* if in the menu cui, close menu cui firstly, then show activated popup */
    else if (g_wlan_display_context.option_menu_cui_id == mmi_frm_group_get_active_id())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_CLOSE_OPTION_MENU);
        mmi_wlan_close_menu_cui (&g_wlan_display_context.option_menu_cui_id);
        mmi_wlan_popup_conn_result_info(cnf);
    }
    else if (active_scr_id == SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_REFRESH_PRIORITY_LIST);
        mmi_wlan_refresh_change_priority_list();
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_REFRESH_NOTHING);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_ABORTING);
    }
}

static void mmi_wlan_after_scan_network_success(srv_dtcnt_wlan_scan_result_struct *cnf)
{
    mmi_frm_node_struct node;
    if(MMI_WLAN_UI_ABORT_SCAN == mmi_wlan_get_ui_flow ())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SCAN_EVENT, 3);
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_SCAN_PROCESSING ||
	    mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST ||
	    mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST)
        {
            mmi_wlan_pre_entry_wlan_wizard();           // entry wlan ap list
        }
	else
	{
	    mmi_frm_node_info_init (&node);
            node.id = SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST;
            node.entry_proc = (mmi_proc_func) mmi_wlan_entry_new_wizard_list;
	    mmi_frm_scrn_insert (wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST, &node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
	    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
	}
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);    // set state machine
        return;
    }
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_SCAN_PROCESSING ||
        mmi_frm_scrn_is_present (
            wlan_parent_group_id, 
            SCR_ID_DTCNT_WLAN_SCAN_PROCESSING, 
            MMI_FRM_NODE_ALL_FLAG)
            ||mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST
        )
    {
        mmi_wlan_update_ap_list_after_scan (cnf);
            
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SCAN_EVENT, 2);
        if(g_wlan_display_context.entry_wizard_new_list
           ||mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST
           )
        {
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
					mmi_wlan_pre_entry_wlan_wizard();
#endif

        }
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
#endif
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);
    }
}

void mmi_wlan_update_ap_list_after_scan(const srv_dtcnt_wlan_scan_result_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, ap_list_num = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset( g_wlan_display_context.ap_list, 
            0, 
            sizeof(supc_abm_bss_info_struct) * WNDRV_MAX_SCAN_RESULTS_NUM);
    g_wlan_display_context.ap_list_num = 0; /* reset ap list */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AFTER_RECEIVE_SCAN_RES_RSP, cnf->result, cnf->ap_list_num);
    for (index = 0; index < cnf->ap_list_num && ap_list_num < WNDRV_MAX_SCAN_RESULTS_NUM; index++)
    {
        if (cnf->ap_list[index]->ssid_len == 0 || cnf->ap_list[index]->ssid[0] == 0)
        {
            continue;   /* Discard hidden AP */
        }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        if (MMI_TRUE == g_wapi_test_mode && 
            (TRUE == cnf->ap_list[index]->rsn_ie_info_p ||
             TRUE == cnf->ap_list[index]->wpa_ie_info_p ||
             (cnf->ap_list[index]->privacy > 0 && FALSE == cnf->ap_list[index]->wapi_ie_info_p)))
        {
            continue;   /* Discard hidden AP */
        }                
#endif /* __MMI_HIDE_WAPI__ */
#endif
        /*if ((TRUE == cnf->ap_list[index]->rsn_ie_info_p) &&
			(WNDRV_SUPC_NETWORK_IBSS == cnf->ap_list[index]->network_type) &&
			(cnf->ap_list[index]->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE) == 0)
        {
            continue;   
        }*/
        memcpy(
            &g_wlan_display_context.ap_list[ap_list_num],
            cnf->ap_list[index],
            sizeof(supc_abm_bss_info_struct));

        memset (g_wlan_display_context.ap_list[ap_list_num].ssid, 0, WNDRV_SSID_MAX_LEN);
        memcpy (g_wlan_display_context.ap_list[ap_list_num].ssid, 
                cnf->ap_list[index]->ssid, 
                cnf->ap_list[index]->ssid_len);

        ap_list_num++;

    }
    
    g_wlan_display_context.ap_list_num = ap_list_num;

    if(MMI_WLAN_UI_SCANNING == mmi_wlan_get_ui_flow ())
    {
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_set_power_saving_mode_cb
 * DESCRIPTION
 *  Callback function for setting power saving mode
 * PARAMETERS
 *  user_data   [IN]        
 *  res         [IN]    result        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_set_power_saving_mode_cb(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SET_POWER_SAVING_MODE_CB, res);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_id        [IN]        Res. ID of status bar's icon
 *  animate         [IN]        Changing dynamically
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_status_icon(U16 image_id, BOOL animate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_id == 0)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_WLAN_SIGNAL);
        return;
    }
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_WLAN_SIGNAL);
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_WLAN_SIGNAL, image_id);
    if (animate == TRUE)
    {
        wgui_status_icon_bar_set_icon_animate(STATUS_ICON_WLAN_SIGNAL);
    }
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_set_status_bar_icon
 * DESCRIPTION
 *  Set status bar's icon based on current wifi status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_set_status_bar_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();
    switch(wlan_status)
    {
    case SRV_DTCNT_WLAN_STATUS_INACTIVE:
        mmi_wlan_update_status_icon(0, FALSE);
        break;
    case SRV_DTCNT_WLAN_STATUS_ACTIVE:
	     if(g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
	         srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	         srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT)
        {
			       mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, TRUE);
		    }
		    else
		    {
		
        	  mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
		    }
        break;
    case SRV_DTCNT_WLAN_STATUS_CONNECTED:
	if (g_wlan_display_context.rssi > -40)
	{
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, FALSE);
	}
	else if (g_wlan_display_context.rssi > -60)
	{
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, FALSE);
	}
	else if (g_wlan_display_context.rssi > -70)
	{
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, FALSE);
	}
	else if (g_wlan_display_context.rssi > -80)
        {
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, FALSE);
	}
	else
	{
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
	}
        break;
    default:
        mmi_wlan_update_status_icon(0, FALSE);
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_auto_connect
 * DESCRIPTION
 *  Provide interface for CBM to trigger connection to default trust AP(customization) or
 *  trust APs in wlan service database
 * PARAMETERS
 *  cb      :       callback function after calling auto connect api
 * RETURNS
 *  U32     :       Scan job id
 *****************************************************************************/
U32 mmi_wlan_auto_conn_networks(mmi_wlan_auto_conn_cb_func_ptr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != cb);

    wlan_status = srv_dtcnt_wlan_status ();
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AUTO_CONN_PRE_START, wlan_status);

    
    g_auto_conn_cb = cb;
    
    return mmi_wlan_send_scan_request(mmi_wlan_list_auto_conn_scan_result_cb, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_auto_conn_scan_result_cb
 * DESCRIPTION
 *  callback function registered when send scan request
 * PARAMETERS
 *  job_id      [IN]    scan job's id
 *  user_data   [IN]    user data
 *  scan_res    [IN]    scan result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_list_auto_conn_scan_result_cb(
    U32 job_id, 
    void *user_data, 
    srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_WLAN_UI_SCANNING == mmi_wlan_get_ui_flow ())
    {
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AFTER_RECEIVE_SCAN_RES_RSP, scan_res->result, scan_res->ap_list_num);
    switch(scan_res->result)
    {
    case SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS:    /* WLAN scan success */
        // update scan ap list with scan result
        if(0 == scan_res->ap_list_num)
        {
            // inform caller
            mmi_wlan_list_auto_conn_inform_caller (WLAN_AUTO_CONN_ACTION_CANCEL);
        }
        else
        {
            // check result
            mmi_wlan_list_auto_conn_start (scan_res);
            
        }

        break;
    case SRV_DTCNT_WLAN_SCAN_RESULT_FAILED:     /* WLAN scan failed */
    case SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED:    /* WLAN scan service is aborted */
        // inform caller
        mmi_wlan_list_auto_conn_inform_caller (WLAN_AUTO_CONN_ACTION_CANCEL);
        break;
    default:
        MMI_ASSERT(0);
        break;
    }
}

void mmi_wlan_list_auto_conn_start(srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
	#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif /* __MMI_OP01_WIFI__ */
#endif
    MMI_BOOL is_op_network_found = MMI_FALSE;
    MMI_BOOL is_op_network_saved = MMI_FALSE;
    MMI_BOOL is_saved_ap_found = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < scan_res->ap_list_num && index < WNDRV_MAX_SCAN_RESULTS_NUM; index++)
    {
        if (scan_res->ap_list[index]->ssid_len == 0 || scan_res->ap_list[index]->ssid[0] == 0)
        {
            continue;   /* ignore invalid networks */
        }
        
#ifdef __WAPI_SUPPORT__
#ifdef __MMI_HIDE_WAPI__
        if (scan_res->ap_list[index]->wapi_ie_info_p)
        {
            continue;   /* ignore WAPI networks if need to hide it in MMI */
        }
#endif  /* __MMI_HIDE_WAPI__ */
#endif  /* __WAPI_SUPPORT__ */

        if ((TRUE == scan_res->ap_list[index]->rsn_ie_info_p) &&
	    (WNDRV_SUPC_NETWORK_IBSS == scan_res->ap_list[index]->network_type) &&
	    (scan_res->ap_list[index]->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE) == 0)
        {
            continue;   /* Discard hidden AP */
        }

        // Transfer into wlan profile
        memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
        bssinfo_to_profile(
            &g_profile_saved_temp, 
            scan_res->ap_list[index], 
            NULL, 0);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_WIFI__ */
#endif


        if (g_wlan_display_context.prof_num > 0)
        {
            is_saved_ap_found = MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AUTO_CONN_CHECK_SCAN_RES, 
                    is_op_network_saved, is_op_network_found, is_saved_ap_found);
    // 1. connect to specific AP according to Operator's specification
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_WIFI__ */
#endif
    {
    // 2. connect to saved AP if exsited
        if(is_saved_ap_found)
        {
            g_wlan_display_context.send_conn_req_ing = MMI_TRUE;
	    cui_menu_close(g_wlan_display_context.option_menu_cui_id);
#if 0
#ifdef __MMI_OP01_WIFI__		
/* under construction !*/
#endif
#endif
        mmi_alert_dismiss(g_wlan_display_context.delete_confirm_id);
            srv_dtcnt_wlan_connect_by_db_prof (NULL, NULL);
            // set ui state machine
            mmi_wlan_set_ui_flow (MMI_WLAN_UI_CONNECT_BY_API);
        }
        else
        {
            mmi_wlan_list_auto_conn_inform_caller (WLAN_AUTO_CONN_ACTION_CANCEL);
            return;
        }
    }
    mmi_wlan_list_auto_conn_inform_caller (WLAN_AUTO_CONN_ACTION_START);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_list_auto_conn_inform_caller
 * DESCRIPTION
 *  inform caller coresponding action after start auto connect
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_list_auto_conn_inform_caller(mmi_wlan_auto_conn_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_auto_conn_cb)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_AUTO_CONN_INFORM_CALLER, action);
        g_auto_conn_cb(action);    
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_callback_handler
 * DESCRIPTION
 *  function to handle the service callback
 * PARAMETERS
 *    param :      [IN]  event parameter.
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
S32 mmi_wlan_callback_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_ACTIVE);
        mmi_wlan_activate_event_hdlr();
        break;

    case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_INACTIVE);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_INIT_RES_IND);
        mmi_wlan_init_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_DEINIT_RES_IND);
        mmi_wlan_deinit_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_CONN_RES_IND);
        mmi_wlan_connect_res_ind_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_CONN_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_CONN_IND);
        mmi_wlan_connect_ind_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_DISC_RES_IND);
        mmi_wlan_disc_res_ind_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_DISC_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_DISC_IND);
        mmi_wlan_disc_ind_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_SCAN_RES_IND);
        mmi_wlan_scan_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_IPADDR_CHANGE_QRY);
        mmi_wlan_ipaddr_change_query_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_IPADDR_UPDATE);
        mmi_wlan_ipaddr_update_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_CURR_AP_INFO);
	if(mmi_frm_scrn_get_active_id() != SCR_ID_DTCNT_WLAN_ABORTING)
        {
            mmi_wlan_curr_ap_info_event_hdlr(param);
	}
        break;
        
    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_IPADDR_CONFLICT_IND);
        mmi_wlan_ipaddr_conflict_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_CHIP_INVALID);
        mmi_wlan_chip_invalid_event_hdlr(param);
        break;

    case EVT_ID_SRV_DTCNT_WLAN_SLEEP:
		MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_WLAN_POWER_SAVE);
		is_sleep = MMI_TRUE;
#ifdef __WPS_SUPPORT__
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_SCAN_RESULT)
        {
            mmi_wlan_exit_wps_info_popup();
        }
#endif
		srv_dtcnt_wlan_deinit(NULL, NULL);
        break;
	case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
    #ifdef __MMI_TELEPHONY_SUPPORT__
		if(srv_mode_switch_is_network_service_available() == MMI_FALSE)
    #else
        if (MMI_TRUE)
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
		{
		    mmi_wlan_update_status_icon(0, FALSE);
		}
		break;
#ifdef __MMI_CCA_SUPPORT__
    case EVT_ID_SRV_DTCNT_PROV_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_PROV_IND);
        mmi_dtcnt_prov_ind_hdlr(param);
        break;
        
    case EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_PROV_INSTALL_RES_IND);
        mmi_dtcnt_prov_install_one_done(param);
        break;
        
    case EVT_ID_SRV_DTCNT_PROV_DONE_IND:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EVT_PROV_DONE_IND);
        // mmi_dtcnt_prov_install_done(param);
        break;
#endif
#if 0
/* under construction !*/
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif


#ifdef __WPS_SUPPORT__
    case EVT_ID_SRV_DTCNT_WLAN_WPS_INFO:
        mmi_wlan_wps_info_ind_hdlr (param);
        break;
#endif

    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_cui_event_proc
* DESCRIPTION
*  Event proc for screen group, menu cui & inline cui
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_wlan_cui_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    /************************* Screen Group Event *************************/
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            break;

    /************************* Menu CUI Event *****************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_wlan_cui_entry_event_proc(evt);
            break;
            
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_wlan_cui_hilite_event_proc(evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_wlan_cui_select_event_proc(evt);            
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_wlan_cui_close_event_proc(evt);
            break;
        
    /*************************** Editor CUI Event *************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            mmi_wlan_cui_editor_submit_evt_proc (evt);
            break;

        case EVT_ID_CUI_FSEDITOR_CHANGED:
            mmi_wlan_cui_editor_changed_evt_proc (evt);
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            mmi_wlan_cui_editor_abort_evt_proc (evt);
            break;

    /*************************** Inline CUI ********************************/
        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_wlan_cui_inline_submit_evt_proc (evt);
            break;

        case EVT_ID_CUI_INLINE_SET_KEY:
            mmi_wlan_cui_inline_set_key_evt_proc (evt);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            mmi_wlan_cui_inline_abort_evt_proc (evt);
            break;
            
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            mmi_wlan_cui_inline_screen_active_evt_proc (evt);
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            mmi_wlan_cui_inline_notify_event_proc(evt);
            break;
#if 0            
#ifdef  __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_WIFI__ */            
#endif
    }

    return MMI_RET_OK;
}

#endif  /* __MMI_WLAN_FEATURES__ */
#endif  /* __TCPIP__ */
