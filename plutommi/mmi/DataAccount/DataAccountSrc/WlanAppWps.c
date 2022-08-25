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
 *   WlanAppWps.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   WPS project in MAUI - MMI Part
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
/*******************************************************************************
 * Include Header File
 *******************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_WLAN_FEATURES__
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "AlertScreen.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "DataAccountEnum.h"
#include "DataAccountStruct.h"
#include "DataAccountCore.h"
#include "DtcntSrvGprot.h"
#include "DataAccountProt.h"
#include "mmi_rp_srv_status_icons_def.h"

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
extern mmi_id wlan_parent_group_id;
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_profile_struct g_profile_saved_temp;
extern mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];

U8 g_wps_info[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
MMI_ID g_wps_info_popup_gid;
MMI_ID g_wps_info_waiting_popup_id;
U8 overlapped_value;

#ifdef __WPS_SUPPORT__
mmi_ret mmi_wlan_wps_waiting_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
	    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_EXIT_SEARCHING_END_KEY, evt->evt_id);
	    mmi_frm_scrn_close_active_id();
	    mmi_wlan_set_status_bar_icon ();
            srv_dtcnt_wlan_disconnect();
	break;
        }
    return MMI_RET_OK;
}
void mmi_wlan_wps_show_waiting_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_WPS_PROCESSING,
        NULL,
        mmi_wlan_wps_show_waiting_popup,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    mmi_frm_scrn_set_leave_proc (
            wlan_parent_group_id, 
            SCR_ID_DTCNT_WLAN_WPS_PROCESSING, 
            mmi_wlan_wps_waiting_scr_leave_proc);

	
#ifndef  WIFI_AUTH_PSK_ONLY

    /* if existed, redraw */
    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_FIND_NETWORK,
        0,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_ID_DTCNT_WLAN_POPUP_SEARCH,
        NULL);
#else
	ShowCategory66Screen(
		   STR_ID_DTCNT_WLAN_FIND_NETWORK,
		   0,
		   0,
		   0,
		   0,
		   0,
		   (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
		   mmi_get_event_based_image(MMI_EVENT_PROGRESS),
		   NULL);
#endif

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_wlan_exit_wps_info_popup, KEY_EVENT_UP);
}
void mmi_wlan_wps_send_conn_req(wlan_wps_conn_type wps_conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_wlan_profile_struct* profile;
    //mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_wps_show_waiting_popup();
    // send WPS connect request to Dtcnt SRV
    profile = &g_profile_saved_temp;       
    memset(profile, 0, sizeof(mmi_wlan_profile_struct));
    profile->use_dhcp = MMI_TRUE;
    
    switch(wps_conn_type)
    {
    case WLAN_WPS_PBC:
        g_wlan_display_context.conn_type = START_WPS_PBC;
        break;
    case WLAN_WPS_PIN:
        g_wlan_display_context.conn_type = START_WPS_PIN;
		switch(g_wlan_display_context.wizard_list_option)
		{
		    case WLAN_MATCH_SA: 
            case WLAN_MATCH_SE_SA:
			case WLAN_MATCH_SE_SA_C:
			case WLAN_MATCH_SA_C:
			if(g_wlan_display_context.active_wlan_profile_p)
	    	{
				profile->ssid_len = g_wlan_display_context.active_wlan_profile_p->ssid_len;
				memcpy(
					profile->ssid, 
					g_wlan_display_context.active_wlan_profile_p->ssid, 
					profile->ssid_len);
			}
			break;
			case WLAN_MATCH_SE:
			if(g_wlan_display_context.active_ap)
	    	{
				profile->ssid_len = g_wlan_display_context.active_ap->ssid_len;
				memcpy(
					profile->ssid, 
					g_wlan_display_context.active_ap->ssid, 
					profile->ssid_len);
			}
			break;
		}
		
        break;
    default:
        MMI_ASSERT (0);
        break;
    }
    g_wlan_display_context.conn_type_index = wps_conn_type;
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_CONNECT_BY_WPS);

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_CONNECT_REQ, g_wlan_display_context.conn_type);
    mmi_wlan_send_connect_request (profile);
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wps_info_ind_hdlr
 * DESCRIPTION
 *  update the WPS info screen
 *  including PIN code and time left
 * PARAMETERS
 * mmi_event_struct* param
 * kal_uint8   action;  // 0: about countdown  1: about pin-code
 * kal_uint32  value;   // if action is countdown, it is seconds
                        // if action is pin, it is pincode value
 * kal_bool show;       // KAL_FALSE: un-visible, KAL_TRUE: visible
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wps_info_ind_hdlr(mmi_event_struct* param)
{
    srv_dtcnt_wlan_wps_info_evt_struct* wpsInfoEvt = 
                                (srv_dtcnt_wlan_wps_info_evt_struct*)param;

    if(wpsInfoEvt)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_EVT_HDLR, wpsInfoEvt->num);
        if(wpsInfoEvt->num == 1)
        {
            mmi_wlan_set_wps_info (wpsInfoEvt->info[0].action, wpsInfoEvt->info[0].value);
            
            
        }
        else if(wpsInfoEvt->num == 2)
        {
            mmi_wlan_set_wps_info (wpsInfoEvt->info[0].action, wpsInfoEvt->info[0].value);
            mmi_wlan_set_wps_info (wpsInfoEvt->info[1].action, wpsInfoEvt->info[1].value);
        }
    }
    

	if(MMI_TRUE == mmi_frm_scrn_is_present(
                    wlan_parent_group_id, 
                    SCR_ID_DTCNT_WLAN_WPS_PROCESSING, 
                    MMI_FRM_NODE_ALL_FLAG))
        {      
            mmi_frm_scrn_close_active_id();
            // show wps connect info popup
            mmi_wlan_entry_wps_connect_info ();
        }
}

void mmi_wlan_set_wps_info(U8 action, U32 value)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SET_INFO, action, value);
    if(0 == action)         // countdown, it is seconds
    {
        g_wlan_display_context.left_time = value;
	overlapped_value = 0;
    }
    else if(1 == action)   // pin, it is seconds
    {
        g_wlan_display_context.pin_code = value;
	overlapped_value = 0;
    }
    else if(2 == action)
    {
	 overlapped_value = value;
		
    }
}

void mmi_wlan_entry_wps_connect_info(void)
{
    // compose the wps info string according to connect type
    mmi_wlan_get_wps_connect_info (
        g_wlan_display_context.conn_type_index,
        g_wlan_display_context.left_time,
        g_wlan_display_context.pin_code);

    g_wps_info_popup_gid = mmi_frm_group_create(
                                        wlan_parent_group_id,
                                        GRP_ID_AUTO_GEN,
                                        mmi_wlan_entry_wps_conn_info_proc, 
                                        NULL);
    mmi_frm_group_enter(g_wps_info_popup_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SHOW_INFO_POPUP, g_wps_info_popup_gid);

    // show wps info popup
    mmi_wlan_show_wps_connect_info_scrn ();

    // start timer
    mmi_wlan_wps_connect_timer_start();

    /* turn on the backlight */
    srv_backlight_turn_on (SRV_BACKLIGHT_PERMANENT);
}

void mmi_wlan_show_wps_connect_info_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter (
            g_wps_info_popup_gid, 
            SCR_ID_DTCNT_WLAN_SCAN_RESULT, 
            NULL, 
            mmi_wlan_show_wps_connect_info_scrn, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_wps_info_popup_gid, SCR_ID_DTCNT_WLAN_SCAN_RESULT);
    mmi_frm_scrn_set_leave_proc (
        g_wps_info_popup_gid, 
        SCR_ID_DTCNT_WLAN_SCAN_RESULT, 
        mmi_wlan_wps_conn_info_leave_cb);
    
    if (g_wlan_display_context.conn_type_index == WLAN_WPS_PBC)
    {
    ShowCategory165Screen(
        0, 
        0, 
        STR_GLOBAL_CANCEL, 
        0, 
        (UI_string_type) g_wps_info, 
        (U16) IMG_GLOBAL_INFO, 
        guiBuffer);
	}
	else if(g_wlan_display_context.conn_type_index == WLAN_WPS_PIN)
	{
	    ShowCategory165Screen(
        0, 
        0, 
        STR_GLOBAL_CANCEL, 
        0, 
        (UI_string_type) g_wps_info, 
        0, 
        guiBuffer);
	}
    
    
    SetRightSoftkeyFunction(mmi_wlan_exit_wps_info_popup, KEY_EVENT_UP);
}

void mmi_wlan_exit_wps_info_popup(void)
{
    g_wlan_display_context.send_conn_req_ing = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
    mmi_wlan_wps_connect_end ();
    //send disc request and increase the count of abort action
    srv_dtcnt_wlan_disconnect();
    mmi_wlan_set_ui_flow(MMI_WLAN_UI_ABORT_CONNECT);
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
}

void mmi_wlan_wps_close_info_popup(void)
{
    if(g_wps_info_popup_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_wps_info_popup_gid);
        g_wps_info_popup_gid = GRP_ID_INVALID;
    }
}

mmi_ret mmi_wlan_wps_conn_info_leave_cb(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_LEAVE_IN_END_KEY);
	    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
            //1. stop timer
            mmi_wlan_wps_connect_timer_stop ();
            //2. send disc request
            srv_dtcnt_wlan_disconnect();
            break;
    }
    return MMI_RET_OK;
}

mmi_ret mmi_wlan_entry_wps_conn_info_proc(mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_POPUP_ENTER);
            break;
        case EVT_ID_GROUP_DEINIT:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_POPUP_DEINIT);
            break;
    }
    return MMI_RET_OK;
}


void mmi_wlan_get_wps_connect_info(wlan_wps_conn_type wps_conn_type, S32 left_time, U32 pin_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *info;
    U8 mins = 0, secs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = (PU8) g_wps_info;

    switch(wps_conn_type)   /* CONNECTION INFO */
    {
    case WLAN_WPS_PIN:
	if (overlapped_value == 0)
	{
        mmi_ucs2cpy((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_WPS_CONN_HELP_INFO));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
	}
        else
        {
            mmi_ucs2cpy((CHAR*)info, (const CHAR*)L"\n");
        }
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_WPS_PIN));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L":");
        sprintf(tempBuf, "%08d", pin_code);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_WPS_CONN_TIME_LEFT));
	mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        mins = left_time/60;
        secs = left_time - mins * 60;
        sprintf(tempBuf, "0%d", mins);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L":");
	if(secs > 9)
        {
	    sprintf(tempBuf, "%d", secs);
        }
        else
        {
	    sprintf(tempBuf, "0%d", secs);
        }
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, tempBufUnicode);
        break;
    case WLAN_WPS_PBC:
        mmi_ucs2cpy((CHAR *)info, GetString(STR_ID_DTCNT_WLAN_WPS_CONN_TIME_LEFT));
	mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        mins = left_time/60;
        secs = left_time - mins * 60;
        sprintf(tempBuf, "0%d", mins);
            mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
            mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L":");
        if(secs > 9)
        {
            sprintf(tempBuf, "%d", secs);
        }
            else
        {
	    sprintf(tempBuf, "0%d", secs);
        }
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode); 
	mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        break;
    default:
        break;
    }
	if (overlapped_value == 1)
	{
	    if(wps_conn_type == WLAN_WPS_PIN)
	    {
	        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
	    }
		mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_WPS_AP_OVERLAPPED));
	}
}

void mmi_wlan_wps_connect_timer_start(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_START_TIMER);
    StartTimer(
        WIFI_WPS_CONNECT_TIMER, 
        1000, 
        mmi_wlan_wps_connect_timeout_cb);
}

void mmi_wlan_wps_connect_timer_stop(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_STOP_TIMER);
    StopTimer (WIFI_WPS_CONNECT_TIMER);
}

void mmi_wlan_wps_connect_timeout_cb(void)
{
    if(g_wlan_display_context.left_time <= 1)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_INFO_TIMER_OUT);
        mmi_wlan_wps_connect_end ();
        // send disconnect request and increase counter
        srv_dtcnt_wlan_disconnect();
        mmi_wlan_set_ui_flow(MMI_WLAN_UI_ABORT_CONNECT);
    }
    else
    {
        // Start timer
        StartTimer(WIFI_WPS_CONNECT_TIMER, 
            1000, 
            mmi_wlan_wps_connect_timeout_cb);
		
        --g_wlan_display_context.left_time;
        // Update wps connect info
        if(g_wlan_display_context.conn_type_index == WLAN_WPS_PBC)
        {
            mmi_wlan_get_wps_connect_info (
                WLAN_WPS_PBC, 
                g_wlan_display_context.left_time, 
                g_wlan_display_context.pin_code);
        }
        else
        {
            mmi_wlan_get_wps_connect_info (
                WLAN_WPS_PIN, 
                g_wlan_display_context.left_time, 
                g_wlan_display_context.pin_code);
        }

        if (g_wps_info_popup_gid == mmi_frm_group_get_active_id())
        {
            wgui_cat_popup_update_string((UI_string_type)g_wps_info);
        }
        
    }
}

void mmi_wlan_wps_connect_end(void)
{
    // reset flag
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    // stop timer
    mmi_wlan_wps_connect_timer_stop ();
    // close info popup
    mmi_wlan_wps_close_info_popup ();
    // switch to GPIO backlight mechanism
    srv_backlight_turn_off ();
}

void mmi_wlan_wps_construct_profile(mmi_wlan_profile_struct* profile, srv_dtcnt_wlan_conn_res_struct *connRes)
{
    U8 name[MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH];
    
    // Set property
    profile->profile_id = connRes->profile_id;
    profile->ssid_len = (U8)connRes->ssid_len;
    memcpy (profile->ssid, connRes->ssid, connRes->ssid_len);
    profile->channel = connRes->channel_number;
    profile->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
    profile->auth_mode = (srv_dtcnt_wlan_auth_mode_enum)connRes->auth_type;
    profile->encrypt_mode = (srv_dtcnt_wlan_encrypt_mode_enum)connRes->encry_mode;
    profile->eap_peap_auth_type = connRes->eap_peap_auth_type;
    profile->eap_ttls_auth_type = connRes->eap_ttls_auth_type;
    //memcpy (profile->passphrase, connRes->passphase, connRes->passphase_len);
    memset (profile->psk, 0, SRV_DTCNT_PROF_MAX_PSK_LEN);
    memcpy (profile->psk, connRes->passphase, connRes->passphase_len);
    profile->passphrase_len = connRes->passphase_len;
    // Set AP's Name here
    memset(&name, 0, MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH);
    // convert ssid from ascii to unicode, and set it as name by default
    custom_wlan_ssid_convert(
            (const char*) profile->ssid, 
            (char*) name, 
            profile->ssid_len);
    memcpy(profile->name, &name, MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH);
}

void mmi_wlan_wps_save_connected_ap(mmi_wlan_profile_struct* connected_ap)
{
    U8 i, j;
    U8 index = 0, priority = 0;
    U32 profile_id = 0;
    U32 highest_priority_index;
    U32 add_ap = MMI_TRUE;
    U32 fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].ssid_len == 0)
        {
            break;
        }
    }
    
    /* If there is no empty slot, replay a same-type one, if no same type, not replace */
    if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        add_ap = MMI_FALSE;
        fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));

        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (connected_ap->network_type == g_wlan_profile[i]->network_type)
            {
                index = g_wlan_profile[i]->index;
                profile_id = g_wlan_profile[i]->profile_id;
                priority = g_wlan_profile[i]->priority;
                memcpy(g_wlan_profile[i], connected_ap, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[i]->index = index;
                g_wlan_profile[i]->profile_id = profile_id;
                g_wlan_profile[i]->priority = priority;
                g_wlan_display_context.connected_wlan_profile = g_wlan_profile[i];
                break;
            }
        }
        /* If there is no infrastructure type wlan profile, replace the highest priority adhoc wlan profile */
        if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
        {
            highest_priority_index = 0;
            for (i = 1; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
            {
                if (g_wlan_profile[i]->priority < g_wlan_profile[highest_priority_index]->priority)
                {
                    highest_priority_index = i;
                }
            }
            index = g_wlan_profile[highest_priority_index]->index;
            profile_id = g_wlan_profile[highest_priority_index]->profile_id;
            priority = g_wlan_profile[highest_priority_index]->priority;
            memcpy(g_wlan_profile[highest_priority_index], connected_ap, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[highest_priority_index]->index = index;
            g_wlan_profile[highest_priority_index]->profile_id = profile_id;
            g_wlan_profile[highest_priority_index]->priority = priority;
            g_wlan_display_context.adhoc_prof_num--;
            g_wlan_display_context.infra_prof_num++;
            g_wlan_display_context.connected_wlan_profile = g_wlan_profile[highest_priority_index];
        }
        else
        {
            g_wlan_display_context.connected_wlan_profile = g_wlan_profile[i];
        }
    }
    else
    {
        if(g_wlan_display_context.adhoc_prof_num == 0)
        {
            connected_ap->priority = ++g_wlan_display_context.prof_num;
            memcpy(&g_wlan_prof_list[i], connected_ap, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        }
        else
        {
            for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
            {
                g_wlan_profile[j] = g_wlan_profile[j-1];
                g_wlan_profile[j]->priority++;
            }
            connected_ap->priority = g_wlan_display_context.infra_prof_num + 1;
            memcpy(&g_wlan_prof_list[i], connected_ap, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[i];
            g_wlan_display_context.prof_num++;
        }
        g_wlan_display_context.infra_prof_num++;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SAVE_CONNECTED_AP, 
            g_wlan_prof_list[i].priority, g_wlan_display_context.infra_prof_num, g_wlan_display_context.adhoc_prof_num);
        g_wlan_display_context.connected_wlan_profile = &g_wlan_prof_list[i];
    }
    
    /* save profile */
    mmi_wlan_dtcnt_store_profile(g_wlan_display_context.connected_wlan_profile, add_ap, fields);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif
#endif

    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority > 0)
        {            
            fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            mmi_wlan_dtcnt_store_profile(&(g_wlan_prof_list[i]), 0, fields);            
        }
    }
}

mmi_wlan_profile_struct* mmi_wlan_wps_search_profile(mmi_wlan_profile_struct *profile, srv_dtcnt_wlan_conn_res_struct *conn_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(conn_res->profile_id == 0) /* temp profile */
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SEARCH_CONNECTED_AP, 
            profile->ssid_len, conn_res->ssid_len);
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if ((g_wlan_profile[i]->ssid_len == profile->ssid_len) &&
                (strncmp((const char*)g_wlan_profile[i]->ssid, (const char*)profile->ssid, profile->ssid_len) == 0) &&
                (g_wlan_profile[i]->network_type == profile->network_type) &&
                (g_wlan_profile[i]->auth_mode == profile->auth_mode) &&
                (g_wlan_profile[i]->encrypt_mode == profile->encrypt_mode))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SEARCH_CONNECTED_AP_FOUND, conn_res->profile_id);
                return g_wlan_profile[i];
            }
        }
    }
    else
    {
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if (g_wlan_profile[i]->profile_id == conn_res->profile_id)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SEARCH_CONNECTED_AP_FOUND, conn_res->profile_id);
                return g_wlan_profile[i];
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WPS_SEARCH_CONNECTED_AP_NOT_FOUND, conn_res->profile_id);
    return NULL;
}

#endif /* __WPS_SUPPORT__ */
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __TCPIP__ */ 

