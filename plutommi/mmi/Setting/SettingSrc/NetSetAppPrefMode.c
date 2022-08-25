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
 * NetSetAppPrefMode.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is UI flow of network setup application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "MMIDataType.h"
#include "NetSetSrvGprot.h"

#ifdef __MMI_WLAN_FEATURES__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "mmi_rp_app_netset_def.h"
#include "NetSetAppGprot.h"
#include "NetSetAppProt.h"
#include "UcmGProt.h"
//#include "NetSetSrvGprot.h"
#include "NetSetSrvProt.h"

#include "ModeSwitchAppGProt.h"
#include "ModeSwitchSrvGProt.h"

#include "custom_events_notify.h"   /* Display popup event enum */

#include "Dtcntsrvgprot.h"
#include "Dtcntsrviprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "NotificationGprot.h"

/* auto add by kw_check begin */
#include "kal_general_types.h"
#include "menucuigprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_srv_dtcnt_def.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "wndrv_cnst.h"
#include "string.h"
/* auto add by kw_check end */
#include "app_str.h"
#include "custom_wlan_ui_config.h"
#include "ucmsrvGprot.h"
#include "mmi_frm_utility_gprot.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/
static srv_netset_pref_mode_enum pref_mode;
static srv_netset_pref_mode_enum selected_mode;

/* Max WLAN SSID is 32 characters per spec. (+1: for null-terminated) */
/* Extend the length to 65, in order to fix */
/* In some language, WLAN OFF string may exceed 33 */
#define MAX_WLAN_SSID_LEN           65

/* WLAN SSID string buffer. */
static WCHAR gWLANProviderName[MAX_WLAN_SSID_LEN];
static MMI_BOOL g_wlan_is_invalid;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern const U16 gIndexIconsImageList[];

#define  PLMN_NAME_LENGTH     30    /* PLMN string length */

/***************************************************************************** 
* Local Function
*****************************************************************************/
/*static void mmi_netset_switch_pref_mode(void);*/
static void mmi_netset_pref_mode_switch_progress(void);
static mmi_ret mmi_netset_pref_mode_switch_progress_leave_proc(mmi_event_struct *param);
static mmi_ret mmi_netset_pref_mode_switch_rsp(mmi_event_struct *ptr_rsp);
static mmi_ret mmi_netset_pref_mode_proc(mmi_event_struct *evt);
static void mmi_init_netset_pref_mode_menu(cui_menu_event_struct *evt);
static void mmi_netset_pre_check_pref_mode(mmi_menu_id mode);
/***************************************************************************** 
* External Function
*****************************************************************************/
/* temp extern functions */
extern U8 mmi_netset_get_active_preferred_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_pref_mode
 * DESCRIPTION
 *  Entry preferred mode menu and create a new screen group 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_pref_mode(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
	PopupNoSupport();
    return;
#endif

    if(srv_ucm_is_any_call())
    {
    	mmi_ucm_app_entry_error_message();
        return;
    }

#ifdef __DM_LAWMO_SUPPORT__
	if (mmi_phnset_check_dm_lock_popup())
	{
        return;
	}
#endif /* __DM_LAWMO_SUPPORT__ */

	mmi_frm_group_create_ex(
		parent_gid, 
        GRP_ID_NETSET_PREF_MODE, 
        mmi_netset_pref_mode_proc, 
        NULL,
		 MMI_FRM_NODE_SMART_CLOSE_FLAG);
	cui_menu_create_and_run(
		GRP_ID_NETSET_PREF_MODE, 
        CUI_MENU_SRC_TYPE_APPCREATE, 
        CUI_MENU_TYPE_APPSUB, 
        MENU_ID_NETSET_PREF_MODE, 
        MMI_FALSE, 
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pref_mode_proc
 * DESCRIPTION
 *  Proc function for preferred mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_pref_mode_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_init_netset_pref_mode_menu(menu_evt);
        return MMI_RET_OK;
        
	case EVT_ID_CUI_MENU_ITEM_SELECT:
	case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_netset_pre_check_pref_mode(menu_evt->highlighted_menu_id);
        return MMI_RET_OK;
        
	default:
		break;
	}
    if (!cui_menu_is_menu_event(evt->evt_id))
	{
	    return MMI_RET_OK;
	}
    return MMI_RET_DONT_CARE;
}

 
 


/*****************************************************************************
* FUNCTION
*  mmi_netset_hint_pref_mode
* DESCRIPTION
*  Hint handler for MENU_ID_NETSET_PREF_MODE
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
CHAR* mmi_netset_hint_pref_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR* ret = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_hint_pref_mode()");
    pref_mode = (srv_netset_pref_mode_enum)mmi_netset_get_active_preferred_mode();

    switch (pref_mode)
    {
    case P_GSM_ONLY:
        ret = (CHAR*) GetString(STR_ID_NETSET_PREF_MODE_GSM_ONLY);
        break;
    case P_WLAN_ONLY:
        ret = (CHAR*) GetString(STR_ID_NETSET_PREF_MODE_WLAN_ONLY);
        break;
    case P_GSM_PREFERRED:
        ret = (CHAR*) GetString(STR_ID_NETSET_PREF_MODE_GSM_PREF);
        break;
    case P_WLAN_PREFERRED:
        ret = (CHAR*) GetString(STR_ID_NETSET_PREF_MODE_WLAN_PREF);
        break;
    default:
        break;
    }
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_init_netset_pref_mode_menu
 * DESCRIPTION
 *  This function is to enter preferred mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_init_netset_pref_mode_menu(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_menu_id list_of_ids[4];
	mmi_menu_id i = 0;
	U8 hilite = 0;
    U16 nStrItemList[4] = 
    {
        STR_ID_NETSET_PREF_MODE_GSM_ONLY,
        STR_ID_NETSET_PREF_MODE_WLAN_ONLY,
        STR_ID_NETSET_PREF_MODE_GSM_PREF,
        STR_ID_NETSET_PREF_MODE_WLAN_PREF
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    for (i = 0; i < 4; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        4, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_NETSET_PREF_MODE), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
	
	for (i = 0; i < 4; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)i,
            (WCHAR*)get_string(nStrItemList[i]));
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));
    
	hilite = pref_mode;
	if (!mmi_frm_is_in_backward_scenario())
	{
    cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)hilite);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pre_check_pref_mode
 * DESCRIPTION
 *  This function is to enter preferred mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_pre_check_pref_mode(mmi_menu_id mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_pre_check_pref_mode()");  
    if(srv_ucm_is_any_call())
    {
    	mmi_ucm_app_entry_error_message();
        return;
    }
    selected_mode = (srv_netset_pref_mode_enum)mode;
    if (mode == srv_netset_get_pref_mode())
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*) GetString(STR_GLOBAL_DONE));
        cui_menu_close(GRP_ID_NETSET_PREF_MODE);
    }

    mmi_netset_pref_mode_switch_progress();

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_mode_switch_get_switch_type() == SRV_MODE_SWITCH_DYNAMIC_MODE)
	{
        srv_netset_set_pref_mode((srv_netset_pref_mode_enum)mode, MMI_TRUE, mmi_netset_pref_mode_switch_rsp, NULL);	
	}
    else
#endif /* MMI_MAX_SIM_NUM >= 2 */
    {
        srv_netset_set_pref_mode((srv_netset_pref_mode_enum)mode, MMI_FALSE, mmi_netset_pref_mode_switch_rsp, NULL);	        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pref_mode_switch_progress
 * DESCRIPTION
 *  This function is to enter preferred mode switch progress
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_pref_mode_switch_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_PREF_MODE, 
		SCR_ID_NETSET_PREF_MODE_PROGRESS, 
		NULL, 
		mmi_netset_pref_mode_switch_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_ID_NETSET_PREF_MODE,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_PREF_MODE, SCR_ID_NETSET_PREF_MODE_PROGRESS, mmi_netset_pref_mode_switch_progress_leave_proc);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pref_mode_switch_progress_leave_proc
 * DESCRIPTION
 *  Leave proc for preferred mode switching 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_pref_mode_switch_progress_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_PROHIBIT_SCRN_ENTER;	
}

/*
 *  WLAN operator name on idle
 */
/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_mode_switch_done
* DESCRIPTION
*  switch preferred mode success function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_netset_pref_mode_switch_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_netset_rsp_event_struct *evt = (srv_netset_rsp_event_struct*)ptr_rsp;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE1(0, "[NetSetAppPrefMode.c] mmi_netset_pref_mode_switch_rsp(%d)", ((srv_netset_rsp_event_struct*)ptr_rsp)->result);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_PREF_MODE, SCR_ID_NETSET_PREF_MODE_PROGRESS, NULL);
    mmi_frm_scrn_close(GRP_ID_NETSET_PREF_MODE, SCR_ID_NETSET_PREF_MODE_PROGRESS);
    /* Failed to switch preferred mode */
    if (evt->result == 0)
	{
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));	    
        return MMI_RET_OK;
	}

    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*) GetString(STR_GLOBAL_DONE));
    mmi_frm_group_close(GRP_ID_NETSET_PREF_MODE);

    
    NETSET_TRACE2(0, "[NetSetAppPrefMode.c] pref_mode[%d] selected_mode[%d]", pref_mode, selected_mode);

    #if (MMI_MAX_SIM_NUM >= 2)
    if (srv_mode_switch_get_switch_type() == SRV_MODE_SWITCH_DYNAMIC_MODE
        && pref_mode == SRV_NETSET_PREF_MODE_WLAN_ONLY 
        && selected_mode != SRV_NETSET_PREF_MODE_WLAN_ONLY)
    {
	U8 i;
        mmi_sim_enum sim;
        for (i = 0; i < MMI_SIM_TOTAL; i ++)
    	{
            sim = mmi_frm_index_to_sim(i);
    	    if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_ON)
            {
        	mmi_mode_switch_query_enable_check_service(sim);
            }
    	}
    }
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    
    return MMI_RET_OK;
}


static mmi_ret mmi_netset_wlan_status_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_dtcnt_wlan_bearer_status_evt_struct *evt = (srv_dtcnt_wlan_bearer_status_evt_struct *)param;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_wlan_status_hdlr()");
    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS:
		NETSET_TRACE1(0, "[NetSetAppPrefMode.c] evt_status(%d)", evt->status);
        mmi_netset_refresh_wlan_status(evt->status);
        break;

    default:
        break;
    }	
    return MMI_RET_OK;
}


void mmi_netset_init_pref_mode(void)
{
	mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS, mmi_netset_wlan_status_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_refresh_wlan_status
 * DESCRIPTION
 *  Refresh WLAN status (gWLANProviderName) 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_refresh_wlan_status(U8 wlan_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE1(0, "[NetSetAppPrefMode.c] mmi_netset_refresh_wlan_status wlan_status(%d)", wlan_status);    
    switch (wlan_status)
	{
	case SRV_DTCNT_WLAN_STATUS_INACTIVE:
		mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_WLAN_OFF));
		break;

	case SRV_DTCNT_WLAN_STATUS_ACTIVE:
        if (g_wlan_is_invalid)
    	{
            mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_INVALID_WLAN));	
            return;
    	}    
		mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_WLAN_ON));
		break;
		
	case SRV_DTCNT_WLAN_STATUS_CONNECTED:
		{
			S8 wlan_asc[MAX_WLAN_SSID_LEN];
			srv_dtcnt_prof_str_info_qry_struct dtcnt_prof;
            if (g_wlan_is_invalid)
        	{
                mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_INVALID_WLAN));	
                return;
        	}              
			dtcnt_prof.dest = wlan_asc;
			dtcnt_prof.dest_len = (MAX_WLAN_SSID_LEN - 1);
			memset(wlan_asc, 0, MAX_WLAN_SSID_LEN);
			srv_dtcnt_wlan_get_connected_ap_ssid(&dtcnt_prof);

			NETSET_TRACE0(0, "[NetSetAppPrefMode.c] SRV_DTCNT_WLAN_STATUS_CONNECTED");
			
			/*mmi_asc_n_to_ucs2((S8 *) gWLANProviderName, (S8 *)dtcnt_prof.dest, dtcnt_prof.dest_len);*/
			custom_wlan_ssid_convert((CHAR *)dtcnt_prof.dest, (CHAR *) gWLANProviderName, dtcnt_prof.req_len);
		}
	    break;
		
	case SRV_DTCNT_WLAN_STATUS_INVALID_MAC:
		mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_INVALID_WLAN));
	    break;

	default:
	    break;        
	}
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_get_wlan_provider_name
* DESCRIPTION
*  This function gets the WLAN provider name.
* PARAMETERS
*  void
* RETURNS
*  WLAN provider name.
*****************************************************************************/
const U8 *mmi_netset_get_wlan_provider_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_get_wlan_provider_name()");
    wlan_status = srv_dtcnt_wlan_status();    
    mmi_netset_refresh_wlan_status(wlan_status);
    /* Check if WLAN provider name is to long */
    if (app_ucs2_strlen((kal_int8 *)gWLANProviderName) >= MAX_WLAN_SSID_LEN)
	{
	    ASSERT(0);
	}
    
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        return (U8*)gWLANProviderName;
    }
    
    return NULL;
}


/*****************************************************************************
* FUNCTION
 *  mmi_netset_wlan_init_hdlr
 * DESCRIPTION
 *  Handler for WLAN init, check MAC address if the MAC address is invalid, 
 *  refresh the provider name. 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_netset_wlan_init_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_init_res_ind_evt_struct *init_ind = (srv_dtcnt_wlan_init_res_ind_evt_struct*)evt;
    U8 invalid_mac[6] = {0x00, 0x0c, 0xe7, 0x00, 0x00, 0x00}; /* default MAC address */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_wlan_init_hdlr()");
    if (evt->evt_id != EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND)
	{
   	    return MMI_RET_OK;
	}
    /* Check if MAC address is invalid */
    if (memcmp(init_ind->mac_addr, invalid_mac, WNDRV_MAC_ADDRESS_LEN) == 0)
	{
        mmi_wcscpy((WCHAR*) gWLANProviderName, (WCHAR*)GetString(STR_ID_NETSET_INVALID_WLAN));	         
    	NETSET_TRACE0(0, "[NetSetAppPrefMode.c] mmi_netset_wlan_init_hdlr() INVALID MAC");
	    g_wlan_is_invalid = MMI_TRUE;
	}
    else
    {
	    g_wlan_is_invalid = MMI_FALSE;        
    }
    return MMI_RET_OK;
}
#endif /* __MMI_WLAN_FEATURES__ */

/*****************************************************************************
* FUNCTION
*  mmi_netset_get_active_preferred_mode
* DESCRIPTION
*  Get active preferred mode
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8 mmi_netset_get_active_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_netset_get_pref_mode();
}
