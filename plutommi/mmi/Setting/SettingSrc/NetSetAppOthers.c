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
 * NetSetAppOthers.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/***************************************************************************** 
* Include
*****************************************************************************/
#include "NetSetAppProt.h"
#include "NetSetAppGprot.h"

#include "NetSetSrvProt.h"
#include "NetSetSrvGprot.h"


#include "L3_inc_enums.h"   /* AUTOMATIC_MODE & MANUAL_MODE enum */
#include "custom_events_notify.h"   /* Display popup event enum */


#include "mmi_rp_app_netset_def.h"

#include "MENUCuiGprot.h"
#include "NWInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "plmnenum.h"

/* auto add by kw_check begin */
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "AlertScreen.h"
#include "mmi_msg_struct.h"
#include "l4crac_enums.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
/* auto add by kw_check end */
#include "NetworkSetupGprot.h"  ///for old API
#include "BootupSrvGprot.h"
#include "ModeSwitchAppGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "IdleGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "CommonScreens.h"
#include "ps_public_enum.h"
#include "mmi_rp_srv_datetime_def.h"

#if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)
#include "hal_ul1_struct.h" // after HAL
extern kal_bool UL1D_Get_FDD_HSPA_Phy_Category(FDD_HSDPA_CATEGORY_E *hsdpa_cat, FDD_HSUPA_CATEGORY_E *hsupa_cat);
#endif /* defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__) */

#ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
#include "mmi_rp_app_engineermode1_def.h"
#endif
/***************************************************************************** 
* External Variable
*****************************************************************************/

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
static U8 mmi_pch_status = 0;
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#define  PLMN_NAME_LENGTH     30    /* PLMN string length */

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Service selection */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */


#ifdef __MONITOR_PAGE_DURING_TRANSFER__
static mmi_ret mmi_netset_set_pch_status_rsp(mmi_event_struct *ptr_rsp);
static mmi_ret mmi_netset_get_pch_status_rsp(mmi_event_struct *ptr_rsp);
static void mmi_netset_set_pch_finish(MMI_BOOL result);
static void mmi_netset_set_pch_progress(void);
static mmi_ret mmi_netset_set_pch_progress_leave_proc(mmi_event_struct *evt);
static mmi_ret mmi_netset_pch_sync_check_int(mmi_event_struct *evt);
static mmi_ret mmi_netset_pch_sync_check_rsp(mmi_event_struct *evt); 
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
static mmi_ret mmi_netset_set_hspa_rsp(mmi_event_struct *ptr_rsp);
static mmi_ret mmi_netset_hspa_progress_leave_proc(mmi_event_struct *evt);
static void mmi_netset_entry_hspa_progress(void);
static mmi_ret mmi_netset_get_hspa_status_rsp(mmi_event_struct *ptr_rsp);
static mmi_ret mmi_netset_hspa_popup_confirm_proc(mmi_event_struct *evt);
#endif
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
/***************************************************************************** 
* External Function
*****************************************************************************/


/* temp extern functions */
#ifdef __MMI_NETSET_3G_ENHANCE__
#define MMI_NO_CELL_FLAG_TIME (60 * 1000)
static MMI_BOOL g_3g_nocell_is_time_out;
static void mmi_netset_3g_nocell_service_selection_progress(void);
static void mmi_netset_3g_nocell_set_time_out_flag(U8 flag);
static MMI_BOOL mmi_netset_3g_nocell_is_time_out(void);
static void mmi_netset_3g_nocell_timeout(void);
static mmi_ret mmi_netset_3g_nocell_check_rsp(mmi_event_struct *evt);
static void mmi_netset_3g_nocell_entry_query_screen(void);
static void mmi_netset_3g_entry_nocell_query_menu(void);
static mmi_ret mmi_netset_3g_nocell_query_proc(mmi_event_struct *evt);
static void mmi_netset_3g_rat_change_auto_rsp(U16 result, void* ptr_rsp);
#endif /* __MMI_NETSET_3G_ENHANCE__ */

#ifdef __MMI_3G_SWITCH__
static MMI_RET mmi_netset_entry_3g_switch_proc(mmi_event_struct *evt);
static void mmi_netset_entry_3g_switch_init(cui_menu_event_struct *evt);
static void mmi_netset_entry_3g_switch_select(MMI_MENU_ID sel_id);
static void mmi_netset_3g_switch_entry_confirm(void);
static MMI_RET mmi_netset_set_3g_sim_capability_rsp(mmi_event_struct *evt);
static void mmi_netset_entry_3g_switch_progress(void);
#endif

/* Network Setup -> Service Selection */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
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
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */


/* Monitor page during transfer */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
static mmi_sim_enum g_netset_set_pch_sim;
static U8 g_netset_set_pch_sim_num;
static U8 g_netset_pch_mode;
static MMI_BOOL g_netset_pch_is_get;
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_pch_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_netset_get_pch_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_netset_pch_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hint_netset_pch_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* mmi_hint_netset_pch_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pch_status = g_netset_pch_mode;

    switch (g_netset_pch_mode)
    {
        case 0:
            return (CHAR*)GetString(STR_ID_NETSET_PCH_DATA_PREFER);
            
		case 1:
            return (CHAR*)GetString(STR_ID_NETSET_PCH_CALL_PREFER);

        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_set_pch_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    srv_netset_set_pch_mode(g_netset_set_pch_sim, (srv_netset_pch_mode_enum)mmi_pch_status, mmi_netset_set_pch_status_rsp, NULL);	
    g_netset_set_pch_sim_num++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_set_pch_status_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* ignore the response */
    mmi_nw_set_gprs_transfer_preference_rsp_struct *local = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_pch_mode_rsp_data;
#ifdef __GEMINI__    
    if (local->result)
	{        
        // Check if all SIM has been switched
        if (g_netset_set_pch_sim_num < MMI_SIM_TOTAL)
    	{
            mmi_event_struct evt;
            switch (g_netset_set_pch_sim)
        	{
        	case MMI_SIM1:
        		g_netset_set_pch_sim = MMI_SIM2;
        		break;
            #if (MMI_MAX_SIM_NUM >= 3)
        	case MMI_SIM2:
        		g_netset_set_pch_sim = MMI_SIM3;
        		break;
            #if (MMI_MAX_SIM_NUM >= 4)                
        	case MMI_SIM3:
        		g_netset_set_pch_sim = MMI_SIM4;
        		break;
            #endif
            #endif
                default:
                        break;
        	}

            // post execute the set request to prevent clearing the callback
            MMI_FRM_INIT_EVENT(&evt, 0);
            mmi_frm_post_event(&evt, (mmi_proc_func)mmi_netset_set_pch_status_req, NULL);
            return MMI_RET_OK;
    	}
    }
#endif
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    {
        U8 i;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
    	{
            srv_netset_set_peer_pch_mode(mmi_frm_index_to_sim(i), (mmi_pch_status == SRV_NETSET_DATA_PREFER ? MMI_FALSE : MMI_TRUE));
    	}
    }
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
    /* there is no monitor peer pch setting */
    g_netset_pch_mode = mmi_pch_status;
    mmi_netset_set_pch_finish(local->result); 
        
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_finish
 * DESCRIPTION
 *  Close PCH setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_set_pch_finish(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_PCH_PROGRESS, NULL);
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_PCH_PROGRESS);
    
	if (result)
	{
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

	}
	else
	{
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}

	cui_menu_close(mmi_netset_get_sub_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_pch_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_update_pch_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_netset_pch_is_get)
    {
        mmi_netset_update_main_menu_hint();
	return;
    }
    srv_netset_get_pch_mode(MMI_SIM1, mmi_netset_get_pch_status_rsp, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_pch_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_get_pch_status_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_transfer_preference_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_pch_mode_rsp_data;

	if (rsp_msg->result)
	{
		g_netset_pch_mode = rsp_msg->prefer;
	}
	else
	{
		g_netset_pch_mode = DATA_PREFER;
	}
    mmi_pch_status = g_netset_pch_mode;
    g_netset_pch_is_get = MMI_TRUE;
	mmi_netset_update_main_menu_hint();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pch_confirm_to_set
 * DESCRIPTION
 *  Confirm to switch the setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_pch_confirm_to_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_set_pch_progress();
	mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_PCH_CONFIRM);
    mmi_netset_set_pch_status_req();
}

#ifndef __MMI_NETSET_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_pch_confirm_scr
 * DESCRIPTION
 *  Display confirm screen for change PCH setting to data prefer 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_entry_pch_confirm_scr(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
    srv_prof_tone_enum tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        GRP_ID_NETSET_MAIN, 
        SCR_ID_NETSET_SET_PCH_CONFIRM, 
        NULL, 
        (FuncPtr)mmi_netset_entry_pch_confirm_scr, 
        MMI_FRM_UNKNOW_SCRN))
	{
	    return;
	}

    EnableCenterSoftkey(NULL, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory163Screen(
            (UI_string_type)GetString(STR_GLOBAL_YES), 
            (PU8)GetImage(IMG_GLOBAL_YES), 
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO), 
            (UI_string_type)GetString(STR_ID_NETSET_PCH_QUERY), 
            image_id, 
            NULL);

    if (tone_id)
        srv_prof_play_tone(tone_id, NULL);       

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_netset_pch_confirm_to_set, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_netset_pch_confirm_to_set, KEY_EVENT_UP);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_set_pch_confirm(mmi_menu_id pch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pch_status = (U8)pch;
    g_netset_set_pch_sim = MMI_SIM1;
    g_netset_set_pch_sim_num = 0;
#ifndef __MMI_NETSET_SLIM__
    if (pch == CALL_PREFER)
    {
        mmi_netset_pch_confirm_to_set();
    }
    else
    {
        mmi_frm_scrn_first_enter(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_PCH_CONFIRM, (FuncPtr)mmi_netset_entry_pch_confirm_scr, NULL);
    }
#else
		mmi_netset_pch_confirm_to_set();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_pch_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netset_pch_menu(cui_menu_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[2];
	mmi_menu_id i = 0;
	U8 hilite = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilite = mmi_pch_status;
	
    for (i = 0; i < 2; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        2, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_NETSET_PCH), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
	
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)0,
            (WCHAR*)get_string((U16)STR_ID_NETSET_PCH_DATA_PREFER));
		
		cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)1,
            (WCHAR*)get_string((U16)STR_ID_NETSET_PCH_CALL_PREFER));
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));
    if (!mmi_frm_is_in_backward_scenario())
    {	
        cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)hilite);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_progress
 * DESCRIPTION
 *  Display the progressing popup when set PCH 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_set_pch_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSET_SET_PCH_PROGRESS, 
		NULL, 
		mmi_netset_set_pch_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_ID_NETSET_PCH,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_PCH_PROGRESS, mmi_netset_set_pch_progress_leave_proc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_pch_progress_leave_proc
 * DESCRIPTION
 *  Leave proc for set PCH progressing screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_set_pch_progress_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_PROHIBIT_SCRN_ENTER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pch_sync_check
 * DESCRIPTION
 *  Check if setting of monitor self PCH and monitor peer PCH is sync 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_pch_sync_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_netset_set_pch_sim = MMI_SIM_NONE;
    mmi_netset_pch_sync_check_int(NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pch_sync_check_int
 * DESCRIPTION
 *  Check if setting of monitor self PCH and monitor peer PCH is sync 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_pch_sync_check_int(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_netset_set_pch_sim == MMI_SIM_NONE)
	{
        g_netset_set_pch_sim = MMI_SIM1;
	    srv_netset_get_pch_mode(g_netset_set_pch_sim, mmi_netset_pch_sync_check_rsp, NULL);
        return MMI_RET_OK;
	}

    sim_num = mmi_frm_sim_to_index(g_netset_set_pch_sim);
    if ((sim_num + 1) < MMI_MAX_SIM_NUM)
	{
        g_netset_set_pch_sim = mmi_frm_index_to_sim(sim_num + 1);
        srv_netset_get_pch_mode(g_netset_set_pch_sim, mmi_netset_pch_sync_check_rsp, NULL);
	}
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__    
    else
    {
        srv_netset_get_peer_pch_mode(mmi_netset_pch_sync_check_rsp, NULL);
    }
#endif    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pch_sync_check_rsp
 * DESCRIPTION
 *  Response handler for PCH sync checking 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_pch_sync_check_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
	case EVT_ID_SRV_NETSET_GET_PCH_MODE_RSP:
    {
        mmi_nw_get_gprs_transfer_preference_rsp_struct *rsp_msg = ((srv_netset_rsp_event_struct*)evt)->rsp_data.get_pch_mode_rsp_data;
		if (g_netset_set_pch_sim == MMI_SIM1)
		{
            /* compare with the SIM1 setting */
            mmi_event_struct post_evt;

		    g_netset_pch_mode = rsp_msg->prefer;

            MMI_FRM_INIT_EVENT(&post_evt, 0);
            mmi_frm_post_event(&post_evt, mmi_netset_pch_sync_check_int, NULL);
		}
        else
        {
            if (g_netset_pch_mode != rsp_msg->prefer)
        	{
                /* not sync, update the setting */
        	    srv_netset_set_pch_mode(g_netset_set_pch_sim, (srv_netset_pch_mode_enum)g_netset_pch_mode, mmi_netset_pch_sync_check_rsp, NULL);
        	}
            else
            {
                /* Sync, query the next setting */
                mmi_event_struct post_evt;
                MMI_FRM_INIT_EVENT(&post_evt, 0);
                mmi_frm_post_event(&post_evt, mmi_netset_pch_sync_check_int, NULL);
            }
        }
		break;
	}
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__    
	case EVT_ID_SRV_NETSET_GET_PEER_PCH_MODE_RSP:
	{
        mmi_nw_get_monitor_peer_pch_rsp_struct *rsp_msg = ((srv_netset_rsp_event_struct*)evt)->rsp_data.get_peer_pch_mode_rsp_data;
        if (rsp_msg->on_off != g_netset_pch_mode)
    	{
            U8 i;
            for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
                srv_netset_set_peer_pch_mode(mmi_frm_index_to_sim(i), (g_netset_pch_mode == SRV_NETSET_DATA_PREFER ? MMI_FALSE : MMI_TRUE));
            }
    	}
		break;
	}        
#endif    
    
	case EVT_ID_SRV_NETSET_SET_PCH_MODE_RSP:
    {
        /* Sync, query the next setting */
        mmi_event_struct post_evt;
        MMI_FRM_INIT_EVENT(&post_evt, 0);
        mmi_frm_post_event(&post_evt, mmi_netset_pch_sync_check_int, NULL);
		break;
	}
        
	default:
		break;
	}
    return MMI_RET_OK;
}
 

#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
/* Monitor page during transfer */


/* HSPA PREFERENCE SETTING */
#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
static U8 select_hspa = 0;
static U8 max_hspa_mode;
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_is_hspa_setting_available
 * DESCRIPTION
 *  Check if HSPA setting is available 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_netset_is_hspa_setting_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // HSPA bonding checking 
    #ifdef __MTK_TARGET__
    {
        FDD_HSDPA_CATEGORY_E dpa;
        FDD_HSUPA_CATEGORY_E upa;
        MMI_BOOL hide_hspa = MMI_FALSE;
        if (MMI_TRUE == UL1D_Get_FDD_HSPA_Phy_Category(&dpa, &upa))
        {
            NETSET_TRACE2(0, "[NetSetApp.c] mmi_netset_update_sim_menu dpa(%d), upa(%d)", dpa, upa);
            hide_hspa = (FDD_HSDPA_OFF == dpa && FDD_HSUPA_OFF == upa) ? MMI_TRUE : MMI_FALSE;
        }
        #if (MMI_MAX_SIM_NUM == 1)
        else
        {
            /* hide HSPA according to SIM status on single SIM project */
            hide_hspa = srv_nw_usab_is_usable(MMI_SIM1);
        }
        #endif
        return (MMI_BOOL)(!hide_hspa);
    }
    #else /* __MTK_TARGET__ */
        /* UL1D_Get_FDD_HSPA_Phy_Category() will not be build on Modis */
        return srv_nw_usab_is_usable(MMI_SIM1);
    #endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hint_netset_hspa_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* mmi_hint_netset_hspa_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	select_hspa = g_netset_cntx_ptr->hspa_status;
	
	switch (g_netset_cntx_ptr->hspa_status)
    {
	case 0:
		return (CHAR*)GetString(STR_ID_NETSET_HSPA_OFF);
		
	case 1:
		return (CHAR*)GetString(STR_ID_NETSET_HSDPA_ON);
#if defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)
	case 2:
		return (CHAR*)GetString(STR_ID_NETSET_HSDPA_HSUPA_ON);
#endif		
	default:
		return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_hspa_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_set_hspa_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_entry_hspa_progress();

	srv_netset_set_hspa_mode(MMI_NETSET_CURRENT_SIM, (srv_netset_hspa_mode_enum)select_hspa, mmi_netset_set_hspa_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_hspa_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_set_hspa_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_hspa_mode_rsp_struct *local = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_hspa_mode_rsp_data;
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_HSPA_PROGRESS, NULL);
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_HSPA_PROGRESS);

	if (local->result)
	{
		g_netset_cntx_ptr->hspa_status = select_hspa;
        mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        cui_menu_close(mmi_netset_get_sub_menu_id());
	}
	else
	{
        mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_hspa_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_get_hspa_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_get_hspa_mode(MMI_NETSET_CURRENT_SIM, mmi_netset_get_hspa_status_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_hspa_status_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_get_hspa_status_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_hspa_mode_rsp_struct *local;
    FDD_HSDPA_CATEGORY_E dpa;
    FDD_HSUPA_CATEGORY_E upa;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_hspa_mode_rsp_data;

	if (local->result)
	{
		g_netset_cntx_ptr->hspa_status = local->hspa_mode;
	}
	else
	{
		g_netset_cntx_ptr->hspa_status = 0;
	}
    // HSPA bonding checking 
#ifdef __MTK_TARGET__
    if (MMI_TRUE == UL1D_Get_FDD_HSPA_Phy_Category(&dpa, &upa))
    {
	if (FDD_HSDPA_OFF != dpa)
	{
	    max_hspa_mode = L4C_HSDPA_ON;
	}
        #ifdef __HSUPA_SUPPORT__
        if (FDD_HSUPA_OFF != upa)
    	{
    	    max_hspa_mode = L4C_HSDPA_HSUPA_ON; 
    	}
        #endif
        NETSET_TRACE3(0, "[NetSetAppOthers.c] mmi_netset_get_hspa_status_rsp max_hspa_mode(%d), dpa(%d), upa(%d)", max_hspa_mode, dpa, upa);
    }
    else
    {
        ASSERT(0);
    }
    g_netset_cntx_ptr->hspa_status = (g_netset_cntx_ptr->hspa_status > max_hspa_mode) ? max_hspa_mode : g_netset_cntx_ptr->hspa_status;
#else
    max_hspa_mode = L4C_HSDPA_HSUPA_ON;
#endif
	mmi_netset_retrieve_sim_menu_data();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_hspa_progress_leave_proc
 * DESCRIPTION
 *  Leave proc function for hspa progressing screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_hspa_progress_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_PROHIBIT_SCRN_ENTER;
}
 

static void mmi_netset_entry_hspa_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_NETSET_MAIN,
        SCR_ID_NETSET_HSPA_PROGRESS,
        NULL,
        mmi_netset_entry_hspa_progress,
        MMI_FRM_FULL_SCRN);
    //EntryNewScreen(SCR_ID_NETSET_HSPA_PROGRESS, NULL, mmi_netset_entry_hspa_progress, NULL);
    
    ShowCategory66Screen(
        STR_ID_NETSET_HSPA,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_HSPA_PROGRESS, mmi_netset_hspa_progress_leave_proc);
}


void mmi_netset_set_hspa_confirm(mmi_menu_id hspa)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hspa == g_netset_cntx_ptr->hspa_status)
    {
		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
        cui_menu_close(mmi_netset_get_sub_menu_id());
        return;    
    }
    #ifdef __MMI_BACKGROUND_CALL__
	if (srv_ucm_is_background_call())
	{
		mmi_ucm_app_entry_error_message();
		return ;
	}
	#endif
	select_hspa = (U8)hspa;
    
	mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
	confirm_arg.callback = mmi_netset_hspa_popup_confirm_proc;
	confirm_arg.parent_id = GRP_ID_NETSET_MAIN;
	mmi_confirm_display(
		(WCHAR*)GetString(STR_ID_NETSET_HSPA_CONFIRM_ASK),
		MMI_EVENT_QUERY,
		&confirm_arg);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_hspa_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netset_hspa_menu(cui_menu_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[3];
	mmi_menu_id i = 0;
	U8 hilite = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilite = g_netset_cntx_ptr->hspa_status;
	
    for (i = 0; i < 3; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
#if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)      
        (max_hspa_mode + 1), 
#else
        2,
#endif
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_NETSET_HSPA), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
	
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)0,
            (WCHAR*)get_string((U16)STR_ID_NETSET_HSPA_OFF));
		
		cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)1,
            (WCHAR*)get_string((U16)STR_ID_NETSET_HSDPA_ON));
#if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)
        if (max_hspa_mode == L4C_HSDPA_HSUPA_ON)
    	{
    	    cui_menu_set_item_string(
                evt->sender_id, 
                (mmi_menu_id)2,
                (WCHAR*)get_string((U16)STR_ID_NETSET_HSDPA_HSUPA_ON));
        }
#endif
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));
	
    if (!mmi_frm_is_in_backward_scenario())
    {
        cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)hilite);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_hspa_popup_confirm_proc
 * DESCRIPTION
 *  Proc function for HSPA confirm popup 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_hspa_popup_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)evt;
        switch (confirm_evt->result)
    	{
    	case MMI_ALERT_CNFM_YES:
            mmi_netset_set_hspa_req();
            break;
            
        case MMI_ALERT_CNFM_NO:    		
            cui_menu_close(mmi_netset_get_sub_menu_id());
    		break;
            
    	default:
    		break;
    	}
    }    
    return MMI_RET_OK;	  
}
#endif /* defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) */
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
/* HSPA PREFERENCE SETTING */

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
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
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */



/*****************************************************************************
* FUNCTION
*  mmi_netset_retrieve_opname_from_plmn
* DESCRIPTION
*  
* PARAMETERS
*  plmn        [?]     
*  opname      [?]     
* RETURNS
*  
*****************************************************************************/
S16 mmi_netset_retrieve_opname_from_plmn(U8 *plmn, U8 *opname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_netset_retrieve_opname_from_plmn()");
    return srv_netset_get_opname(plmn, (WCHAR*)opname);
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
#endif     
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_plmn_matching_criteria
* DESCRIPTION
*  Implementation of 23.122 for PLMN match criteria
* PARAMETERS
*  sim_plmn        [IN]
*  bcch_plmn       [IN]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_netset_plmn_matching_criteria(const U8 *sim_plmn, const U8 *bcch_plmn)
{
    return (MMI_BOOL)(!srv_netset_is_plmn_roaming((CHAR*)sim_plmn, (CHAR*)bcch_plmn));
}



/*****************************************************************************
* FUNCTION
 *  mmi_netset_equivalent_plmn_sim_check
* DESCRIPTION
 *  Check PLMN status 
* PARAMETERS
 *  
* RETURNS
 *  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_netset_equivalent_plmn_check_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR plmn[MAX_PLMN_LEN + 1];
    CHAR home_plmn_num[MAX_PLMN_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(home_plmn_num, 0, (MAX_PLMN_LEN + 1));
    memset(plmn, 0, (MAX_PLMN_LEN + 1));
    
    srv_sim_ctrl_get_home_plmn(sim, home_plmn_num, (MAX_PLMN_LEN + 1));
    srv_nw_info_get_nw_plmn(sim, plmn, (MAX_PLMN_LEN + 1));
    return (MMI_BOOL)(!srv_netset_is_plmn_roaming((CHAR*)home_plmn_num, (CHAR*)plmn));
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_equivalent_plmn_check
* DESCRIPTION
*  Check if VPLMN and HPLMN is mapping to the same operator name string
* PARAMETERS
*  void
* RETURNS
*  pBOOL
*****************************************************************************/
pBOOL mmi_netset_equivalent_plmn_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return mmi_netset_equivalent_plmn_check_sim(MMI_SIM1);
}

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
/* under construction !*/
/* under construction !*/
#endif
/* External Interface to Other Application */


#ifdef __MMI_NETSET_3G_ENHANCE__

/*****************************************************************************
* FUNCTION
*  mmi_netset_3g_nocell_service_selection_progress
* DESCRIPTION
*  Entry service selection progress screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_3g_nocell_service_selection_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
        GRP_ID_NETSET_MAIN,
		SCR_ID_NETSET_SET_RAT_PROGRESS, 
		NULL, 
		mmi_netset_3g_nocell_service_selection_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
	ShowCategory66Screen(
        STR_ID_NETSET_SERVICE_SELECTION,
		GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_set_time_out_flag
 * DESCRIPTION
 *  Set the flag for 3G no service time out 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_3g_nocell_set_time_out_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE1(0, "mmi_netset_3g_nocell_set_time_out_flag (%d)", flag);
    g_3g_nocell_is_time_out = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_is_time_out
 * DESCRIPTION
 *  Check the 3G no service time out status 
 * PARAMETERS
 *  void
 * RETURNS
 *  static MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_netset_3g_nocell_is_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE1(0, "mmi_netset_3g_nocell_is_time_out (%d)", g_3g_nocell_is_time_out);
    return g_3g_nocell_is_time_out;
}
 

void mmi_netset_3g_nocell_start_timer(void)
{
    NETSET_TRACE0(0, "mmi_netset_3g_nocell_start_timer");    
    if (!IsMyTimerExist(MMI_NETSET_3G_WAIT_TIMER) 
        && srv_sim_ctrl_is_available(MMI_SIM1)
        && !mmi_netset_3g_nocell_is_time_out() 
        && (srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_NO_SERVICE))
	{
    	StartTimer(MMI_NETSET_3G_WAIT_TIMER, MMI_NO_CELL_FLAG_TIME, mmi_netset_3g_nocell_timeout);
    	mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);	
    }
}

void mmi_netset_3g_nocell_stop_timer(void)
{
    NETSET_TRACE0(0, "mmi_netset_3g_nocell_stop_timer"); 
    if (IsMyTimerExist(MMI_NETSET_3G_WAIT_TIMER))
	{    
        StopTimer(MMI_NETSET_3G_WAIT_TIMER);
    }
    mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_timeout
 * DESCRIPTION
 *  Time out handler for 3G no service timer 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_3g_nocell_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMI_NETSET_3G_WAIT_TIMER);
    NETSET_TRACE0(0, "mmi_netset_3g_nocell_timeout");     
    if ((!mmi_netset_3g_nocell_is_time_out()) 
        && srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_ALL_OFF
        && (srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_NO_SERVICE)
        && srv_sim_ctrl_is_available(MMI_SIM1))
	{
        mmi_netset_3g_nocell_set_time_out_flag(MMI_TRUE);
	    if (mmi_idle_is_active())
		{
		    mmi_idle_display();
		}
	}
}


U8 mmi_netset_rat_idle_notify(void)
{
    return (U8)mmi_netset_3g_nocell_is_time_out();
}


void mmi_netset_rat_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Do not display RAT selection menu when network selection mode is automatic already */
    srv_netset_get_rat_mode(MMI_SIM1, mmi_netset_3g_nocell_check_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_check_rsp
 * DESCRIPTION
 *  RSP for get RAT mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_netset_3g_nocell_check_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_evt->rsp_data.get_rat_mode_rsp_data->result
        && rsp_evt->rsp_data.get_rat_mode_rsp_data->rat_mode == 3)
	{
        mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);	    
	}
    else
    {
        mmi_netset_3g_nocell_entry_query_screen();
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_enter_query_screen
 * DESCRIPTION
 *  Entry query screen for 3G no cell 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_3g_nocell_entry_query_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct confirm_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE); 
	mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
	confirm_arg.callback = mmi_netset_3g_nocell_query_proc;
	confirm_arg.parent_id = GRP_ID_ROOT;
	mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_NETSET_3G_NO_SERVICE_INFO),
	    MMI_EVENT_QUERY,
	    &confirm_arg);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_entry_nocell_query_menu
 * DESCRIPTION
 *  Entry the menu of 3G no cell reselection 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_3g_entry_nocell_query_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_netset_cntx_set_ptr(MMI_SIM1);
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_NETSET_MAIN,
        mmi_netset_3g_nocell_query_proc,
        NULL);
    mmi_frm_group_enter(GRP_ID_NETSET_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    menu_cui_gid = cui_menu_create(
        GRP_ID_NETSET_MAIN,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_NETSET_3G_NOCELL_MENU,
        MMI_FALSE,
        NULL);
    cui_menu_run(menu_cui_gid);
    mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_query_proc
 * DESCRIPTION
 *  Proc function for 3G no service menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netset_3g_nocell_query_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
	{
	case EVT_ID_CUI_MENU_LIST_ENTRY:
        cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        break;
        
	case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
    	    if(menu_evt->highlighted_menu_id == MENU_ID_NETSET_3G_CHANGE_AUTO)
    		{
			mmi_frm_scrn_first_enter(
				GRP_ID_NETSET_MAIN,
				SCR_ID_NETSET_SET_RAT_PROGRESS,
				(FuncPtr)mmi_netset_3g_nocell_service_selection_progress,
				NULL);
    			srv_netset_set_rat_mode(MMI_SIM1, 3, mmi_netset_3g_rat_change_auto_rsp, NULL);
    		}

    	    if(menu_evt->highlighted_menu_id == MENU_ID_NETSET_NETSEL_MANUAL)
    		{
    			mmi_entry_netsel_manual();
    		}
    	}
		break;        

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);
        cui_menu_close(menu_evt->sender_id);
        break;

    case EVT_ID_GROUP_DEINIT:
        mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);
	break;

    case EVT_ID_ALERT_QUIT:
    {
        mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)evt;
        
        if (confirm_evt->result == MMI_ALERT_CNFM_YES)
    	{
            mmi_netset_3g_entry_nocell_query_menu();
            mmi_alert_dismiss(confirm_evt->alert_id);
        }
        else if (confirm_evt->result == MMI_ALERT_CNFM_NO)
    	{
            mmi_alert_dismiss(confirm_evt->alert_id);    	
    	}
     }    

	default:
		break;
    }
    return MMI_RET_OK;
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_rat_change_auto
 * DESCRIPTION
 *  Change RAT mode to automatic 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_3g_rat_change_auto_rsp(U16 result, void* ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_rat_mode_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_nw_set_rat_mode_rsp_struct*)ptr_rsp;

	if (rsp_msg->result)
	{
        if (mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_RAT_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{        
    		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    	}
	}
	else
	{
        if (mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_SET_RAT_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{                
    		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    	}
	}
    mmi_netset_3g_nocell_set_time_out_flag(MMI_FALSE);
	mmi_frm_group_close(GRP_ID_NETSET_MAIN);
}
 


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_3g_nocell_check_hdlr
 * DESCRIPTION
 *  Handler for 3G no cell checking in bootup 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_netset_3g_nocell_check_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(0, "mmi_netset_3g_nocell_check_hdlr ()");
    switch (evt->evt_id)
	{
    case EVT_ID_SRV_BOOTUP_COMPLETED:
    	{
            if (srv_nw_usab_is_usable(MMI_SIM1))
            {
                mmi_netset_3g_nocell_start_timer();
            }
            break;
        }
        
	default:
		break;
	}
    return MMI_RET_OK;
}
#endif /* __MMI_NETSET_3G_ENHANCE__ */

#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
U8 mmi_netset_get_cell_info_status(void)
{
	return 0;
}
#endif 

// TODO REMOVE START
//#ifdef __MMI_DUAL_SIM_MASTER__
#if (MMI_MAX_SIM_NUM >= 2)
void mmi_netset_card2_update_network_info_screen(void)
{
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif
}

void mmi_netset_notify_invalid_sim2(void)
{

}
#endif /* MMI_MAX_SIM_NUM >= 2 */

mmi_ret mmi_nw_adp_on_home_plmn_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mmi_idle_is_active() && srv_bootup_is_completed())
    {
        mmi_idle_update_service_area();
        /*idle_screen_show_network_details();*/
    }

    return MMI_RET_OK;
}

mmi_ret mmi_nw_adp_sim1_service_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *availability_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    // TODO: OTHER SIM?
    if (availability_evt->sim != MMI_SIM1)
    {
        return MMI_RET_OK;
    }

    switch (availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_FULL_SERVICE:
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
        #endif

        #ifdef __MMI_NETSET_3G_ENHANCE__
            mmi_netset_3g_nocell_stop_timer(); /* stop 3g notify timer */
        #endif
        
            break;

        case SRV_NW_INFO_SA_LIMITED_SERVICE:
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
        #endif
        
            break;

        case SRV_NW_INFO_SA_NO_SERVICE:
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
        #endif
        
            break;

        case SRV_NW_INFO_SA_SEARCHING:
        default:
            break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_3G_SWITCH__
static mmi_sim_enum sel_3g_cap_sim = MMI_SIM1;
static mmi_sim_enum curr_3g_cap_sim = MMI_SIM1;
/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_menu
* DESCRIPTION
*  Entry 3g service swtich screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_netset_entry_3g_switch_menu(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
	if (srv_ucm_is_background_call())
	{
		mmi_ucm_app_entry_error_message();
		return ;
	}
#endif
	mmi_frm_group_create_ex(GRP_ID_NETSET_MAIN,
							GRP_ID_NETSET_3G_SERVICE_SWITCH,
							mmi_netset_entry_3g_switch_proc,
							NULL,
							MMI_FRM_NODE_SMART_CLOSE_FLAG);

	cui_menu_create_and_run(GRP_ID_NETSET_3G_SERVICE_SWITCH,
							CUI_MENU_SRC_TYPE_RESOURCE,
							CUI_MENU_TYPE_APPSUB,
							MENU_ID_NETSET_3G_SERVICE_SWITCH,
							MMI_FALSE,
							NULL);

}

/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_proc
* DESCRIPTION
*  Entry 3g service swtich proc
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_netset_entry_3g_switch_proc(mmi_event_struct *evt)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct * event = (cui_menu_event_struct *)evt;
	mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)evt;
	//mmi_sim_enum sim_type = srv_netset_get_3g_capacity_sim();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			mmi_netset_entry_3g_switch_init(event);
			break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
		case EVT_ID_CUI_MENU_ITEM_TAP:
		case EVT_ID_CUI_MENU_ITEM_SELECT:
			mmi_netset_entry_3g_switch_select(event->highlighted_menu_id);
			sel_3g_cap_sim = mmi_frm_index_to_sim(event->highlighted_menu_id);
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(event->sender_id);
			break;
		case EVT_ID_ALERT_QUIT:
			switch (confirm_evt->result)
    		{
    		case MMI_ALERT_CNFM_YES:
				mmi_netset_entry_3g_switch_progress();
				srv_netset_set_3g_sim_capability_req(sel_3g_cap_sim, SRV_NETSET_RAT_GSM_UMTS, mmi_netset_set_3g_sim_capability_rsp, NULL);				
				break;
            
			case MMI_ALERT_CNFM_NO:    		
    			mmi_frm_group_close(GRP_ID_NETSET_3G_SERVICE_SWITCH);
    			break;
			
			default:
				break;
			}
			break;
		default:
			break;
		
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_init
* DESCRIPTION
*  Entry 3g service swtich init
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_entry_3g_switch_init(cui_menu_event_struct *evt)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	U16 list_of_ids[2];
	mmi_id menu_id = evt->sender_id;
		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < 2; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        menu_id, 
        2, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(menu_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title_by_id(
        menu_id, 
        STR_ID_NETSET_3G_SERVICE_SWITCH, 
        NULL);
	
    cui_menu_set_item_string_by_id(
        menu_id, 
        list_of_ids[0],
        STR_GLOBAL_SIM_1);
	
	cui_menu_set_item_string_by_id(
        menu_id, 
        list_of_ids[1],
		STR_GLOBAL_SIM_2);	
	curr_3g_cap_sim = srv_netset_get_3g_capability_sim();
    cui_menu_set_currlist_highlighted_id(menu_id, mmi_frm_sim_to_index(curr_3g_cap_sim));
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_select
* DESCRIPTION
*  Entry 3g service swtich select handlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_entry_3g_switch_select(MMI_MENU_ID sel_id)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//MMI_MENU_ID curr_id = mmi_frm_sim_to_index(srv_netset_get_3g_capacity_sim());

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(mmi_frm_sim_to_index(curr_3g_cap_sim) == sel_id)
	{
		srv_netset_set_3g_capacity_sim(curr_3g_cap_sim);
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
		mmi_frm_group_close(GRP_ID_NETSET_3G_SERVICE_SWITCH);
		return;
	}
	#ifdef __MMI_BACKGROUND_CALL__
	else if (srv_ucm_is_background_call())
	{
		mmi_ucm_app_entry_error_message();
		return ;
	}
	#endif
	else
	{
		mmi_netset_3g_switch_entry_confirm();
	}

}

/*****************************************************************************
* FUNCTION
*  mmi_netset_3g_switch_entry_confirm
* DESCRIPTION
*  Entry 3g service swtich confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_3g_switch_entry_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
	mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
	confirm_arg.callback = mmi_netset_entry_3g_switch_proc;
	confirm_arg.parent_id = GRP_ID_NETSET_3G_SERVICE_SWITCH;
	mmi_confirm_display(
		(WCHAR*)GetString(STR_ID_NETSET_3G_SERVICE_SWITCH_QUERY),
		MMI_EVENT_QUERY,
		&confirm_arg);  
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_set_3g_sim_capability_rsp
* DESCRIPTION
*  Entry 3g service swtich select RSP
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_netset_set_3g_sim_capability_rsp(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_l4c_set_sim_capability_rsp_struct *rsp_msg = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)evt)->rsp_data.set_sim_capability_rsp_data;
	if(rsp_msg->result)
	{
		srv_netset_set_3g_capacity_sim(sel_3g_cap_sim);
		srv_alm_pwr_reset(MMI_FALSE, 3);
	}
	else
	{
		mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
		mmi_frm_scrn_close(GRP_ID_NETSET_3G_SERVICE_SWITCH, SCR_ID_NETSET_3G_SERVICE_SWITCH_PROGRESS);
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_entry_3g_switch_select
* DESCRIPTION
*  Entry 3g service swtich select handlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_entry_3g_switch_progress(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(mmi_frm_scrn_enter(
		GRP_ID_NETSET_3G_SERVICE_SWITCH, 
		SCR_ID_NETSET_3G_SERVICE_SWITCH_PROGRESS, 
		NULL, 
		mmi_netset_entry_3g_switch_progress, 
		MMI_FRM_UNKNOW_SCRN))
	{
	ShowCategory66Screen(
		STR_ID_NETSET_3G_SERVICE_SWITCH,
		NULL,
		0,
		0,
		0,
		0,
		(U8*) GetString(STR_ID_NETSET_3G_SERVICE_SWITCH_PROGRESS),
		mmi_get_event_based_image(MMI_EVENT_PROGRESS),
		NULL);
	}
	ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_LONG_PRESS);

}
/*****************************************************************************
* FUNCTION
*  mmi_netset_3g_switch_set_menu_hint
* DESCRIPTION
*  set 3g service swtich menu hint
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
CHAR* mmi_netset_3g_switch_get_menu_hint(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_sim_enum sim = srv_netset_get_3g_capability_sim();
	CHAR *ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch(sim)
	{
		case MMI_SIM2:
			ret = GetString(STR_GLOBAL_SIM_2);
			break;
		default:
			ret = GetString(STR_GLOBAL_SIM_1);
			break;
	}
	return ret;
}

#endif /* __MMI_3G_SWITCH__ */
// TODO REMOVE END
