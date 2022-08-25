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
 * NetSetApp.c
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
#include "AlertScreen.h"
#include "mmi_rp_app_netset_def.h"

#include "ModeSwitchSrvGProt.h"
#include "ModeSwitchAppGprot.h"
#include "SIMCtrlSrvGprot.h"
#include "MenuCUIGprot.h"
#include "Cphssrvgprot.h"
#include "NwUsabSrvGprot.h"

/* auto add by kw_check begin */
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "sim_common_enums.h"
#include "CustDataRes.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "gui_data_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "UcmGProt.h"
#include "UcmSrvGprot.h"
#ifdef __MANUAL_MODE_NW_SEL__	
#include "CphsSrvGprot.h"
#endif

/* auto add by kw_check end */
#if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)
#include "hal_ul1_struct.h" // after HAL
extern kal_bool UL1D_Get_FDD_HSPA_Phy_Category(FDD_HSDPA_CATEGORY_E *hsdpa_cat, FDD_HSUPA_CATEGORY_E *hsupa_cat);
#endif /* defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__) */
#include "NetSetSrvGprot.h"
/***************************************************************************** 
* External Variable
*****************************************************************************/
mmi_netset_cntx_struct *g_netset_cntx_ptr = NULL;

mmi_netset_cntx_struct g_netset_cntx[MMI_SIM_TOTAL];

/***************************************************************************** 
* Global Variable
*****************************************************************************/
static MMI_ID netset_menu_cui_id = 0;
static MMI_ID netset_sub_menu_id;
/* Indicate current highlight on preferred mode, avoid highlight incorrect after switch preferred mode */
#ifdef __MMI_WLAN_FEATURES__
static MMI_BOOL g_netset_highlight_preferred_mode; 
#endif

static mmi_sim_enum mmi_netset_curr_sim = MMI_SIM_NONE;
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__)*/

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static WCHAR* g_sim_menu_title_str = NULL;
#endif
/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Network Setup Main Entry Function */
static void mmi_entry_netset_main(void);

static mmi_ret mmi_netset_main_proc(mmi_event_struct *param);

static mmi_ret mmi_netset_menu_cui_select_evt_hdlr(mmi_event_struct *param);
static mmi_ret mmi_netset_menu_cui_entry_evt_hdlr(mmi_event_struct *param);

static U8 mmi_netset_set_item_info(mmi_event_struct *param);
static void mmi_netset_hint_hdlr(cui_menu_event_struct *evt);
#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_netset_update_main_menu(cui_menu_event_struct* evt);
#endif
static void mmi_netset_update_sim_menu(cui_menu_event_struct* evt);
static MMI_BOOL mmi_netset_is_retrieve_data_needed(void);

const static FuncPtr g_netset_update_sim_menu_hdlr[] = 
{
    /* Service mode */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
    /* GPRS connection mode */
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
    mmi_netset_get_gprs_mode_req,
#endif /* __MMI_GPRS_FEATURES__ */
    /* HSPA setting */
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__)
	mmi_netset_get_hspa_status_req,
#endif
    NULL  /* dummy one, please add callbacks before this entity */
};


/***************************************************************************** 
* External Function
*****************************************************************************/

/* Network Setup Context functions for multi-SIM */
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_cntx_set_ptr
 * DESCRIPTION
 *   
 * PARAMETERS
 *  sim_id      [IN]    SIM interface
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_cntx_set_ptr(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE1(TRC_MMI_NETSET_SET_CNTX_PTR, "[NetSetApp.c] mmi_netset_cntx_set_ptr set mmi_netset_curr_sim [%d]", sim_id);
    mmi_netset_curr_sim = sim_id;
    g_netset_cntx_ptr = &g_netset_cntx[mmi_frm_sim_to_index(sim_id)];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_active_sim
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  current operator SIM
 *****************************************************************************/
mmi_sim_enum mmi_netset_get_active_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    NETSET_TRACE1(TRC_MMI_NETSET_GET_ACTIVE_SIM, "[NetSetApp.c] mmi_netset_get_active_sim return [%d]", mmi_netset_curr_sim);
    return mmi_netset_curr_sim;
}
/* Network Setup Context functions for multi-SIM */



/* Network Setup Main Menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_highlight_netset_main
 * DESCRIPTION
 *  This function is high light handler of Settings -> Network Setup
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_highlight_netset_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#if( MMI_MAX_SIM_NUM >= 2)
    SetLeftSoftkeyFunction(mmi_entry_netset_main, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_entry_netset_main, KEY_EVENT_UP);
#else /* MMI_MAX_SIM_NUM >= 2 */
    mmi_netset_cntx_set_ptr(MMI_SIM1);
    SetLeftSoftkeyFunction(mmi_netset_retrieve_sim_menu_data, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_netset_retrieve_sim_menu_data, KEY_EVENT_UP);
#endif /* MMI_MAX_SIM_NUM >= 2 */

    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static mmi_ret mmi_netset_menu_cui_entry_evt_hdlr(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetApp.c] mmi_netset_menu_cui_entry_evt_hdlr()");
#ifndef __MMI_MAINLCD_96X64__
    mmi_netset_hint_hdlr(evt);
#endif

	switch(evt->parent_menu_id)
	{
	case MENU_ID_NETSET_MAIN:
		{
#if (MMI_MAX_SIM_NUM >= 2)
		    mmi_netset_curr_sim = MMI_SIM_NONE;
			mmi_netset_update_main_menu(evt);
#else
			mmi_netset_update_sim_menu(evt);
#endif

#ifdef __MMI_WLAN_FEATURES__
			cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_MODE, MMI_TRUE);
            if (g_netset_highlight_preferred_mode)
            {
                mmi_menu_id preferred_mode_id = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, MENU_ID_NETSET_PREF_MODE);
                cui_menu_set_currlist_highlighted_id(evt->sender_id, MENU_ID_NETSET_PREF_MODE);
                g_netset_highlight_preferred_mode = MMI_FALSE;
            }
#endif            
        /* Get monitor self PCH mode*/
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
 			if(srv_nw_usab_any_sim_is_usable())
			{
                mmi_netset_update_pch_hint();
			}

#endif
            return MMI_RET_OK;
		}

#if (MMI_MAX_SIM_NUM >= 2)
	case MENU_ID_NETSET_SIM1:
	case MENU_ID_NETSET_SIM2:
#if (MMI_MAX_SIM_NUM >= 3)
    case MENU_ID_NETSET_SIM3:
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    case MENU_ID_NETSET_SIM4:
#endif /* MMI_MAX_SIM_NUM >= 4 */
		{
            mmi_netset_update_sim_menu(evt);
            return MMI_RET_OK;
		}
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_PREF_NETWORK__
    case MENU_ID_NETSET_PREF_LIST_OPTION:
        {
            mmi_update_pref_list_option_menu(evt);
            return MMI_RET_OK;
        }
#endif /* __MMI_PREF_NETWORK__ */
#ifdef __MANUAL_MODE_NW_SEL__
#ifdef __MMI_NETSET_SLIM__
     case MENU_ID_NETSET_NETWORK_SELECTION:
#else            
	case MENU_ID_NETSET_NETSEL_SELECT_MODE:
#endif        
		{
			mmi_entry_netsel_select_mode(evt);
            return MMI_RET_OK;
		}
#endif /* __MANUAL_MODE_NW_SEL__ */

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
	case MENU_ID_NETSET_PCH_MODE:
		{
			mmi_entry_netset_pch_menu(evt);
            return MMI_RET_OK;
		}
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
	case MENU_ID_NETSET_HSPA_MODE:
		{
			mmi_entry_netset_hspa_menu(evt);
            return MMI_RET_OK;
		}
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
	default:
		cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
	    break;
	}

    return MMI_RET_OK;
}


static mmi_ret mmi_netset_menu_cui_select_evt_hdlr(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
	mmi_sim_enum sim;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	/* if item non leaf node, should save item info */
	if (mmi_netset_set_item_info(param))
	{
		return MMI_RET_OK;
	}

	switch(evt->highlighted_menu_id)
	{
//#ifdef __MMI_DUAL_SIM_MASTER__
#if( MMI_MAX_SIM_NUM >= 2)
	case MENU_ID_NETSET_SIM1:       
	case MENU_ID_NETSET_SIM2:
#if( MMI_MAX_SIM_NUM >= 3)
    case MENU_ID_NETSET_SIM3:       
#if( MMI_MAX_SIM_NUM >= 4)
	case MENU_ID_NETSET_SIM4:
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >=  3 */
		{
		sim = mmi_frm_index_to_sim(evt->highlighted_menu_id - MENU_ID_NETSET_SIM1);
		#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
			if(SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode(sim) || !srv_sim_ctrl_is_available(sim))
			{
				mmi_popup_display_simple_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
				return MMI_RET_OK;
			}
		#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
			mmi_netset_cntx_set_ptr(sim);
            if (mmi_netset_is_retrieve_data_needed())
        	{
    			cui_menu_pause(evt->sender_id);
    			mmi_netset_retrieve_sim_menu_data();
        	}
            return MMI_RET_OK;
		}
#endif /* MMI_MAX_SIM_NUM >= 2 */
#ifndef __MMI_NETSET_SLIM__
	case MENU_ID_NETSET_NETSEL_AUTO:
		{
			mmi_entry_netsel_auto();
            return MMI_RET_OK;
		}

	case MENU_ID_NETSET_NETSEL_MANUAL:
		{
			mmi_entry_netsel_manual();
            return MMI_RET_OK;
		}
#endif
		/* Network Setup Preferred Network List */
#ifdef __MMI_PREF_NETWORK__        
	case MENU_ID_NETSET_PREF_LIST:
		{
			mmi_entry_netset_pref_list();
            return MMI_RET_OK;
		}

	case MENU_ID_NETSET_PREF_LIST_OPTION_ADD:
		{
			mmi_entry_netset_pref_list_opt_add();
            return MMI_RET_OK;
		}

	case MENU_ID_NETSET_PREF_LIST_OPTION_NEW:
		{
			mmi_entry_netset_pref_list_opt_new();
            return MMI_RET_OK;
		}
		
	case MENU_ID_NETSET_PREF_LIST_OPTION_EDIT:
		{
			mmi_entry_netset_pref_list_opt_edit();
            return MMI_RET_OK;
		}
		
	case MENU_ID_NETSET_PREF_LIST_OPTION_DELETE:
		{
			mmi_entry_netset_pref_list_opt_del();
            return MMI_RET_OK;
		}
        /* Network Setup Preferred Network List */
#endif /* __MMI_PREF_NETWORK__ */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#ifndef __MMI_NETSET_SLIM__
    case MENU_ID_NETSET_NETWORK_SELECTION:
        if (!mmi_netsel_is_available_to_entry())
    	{
            return MMI_RET_DONT_CARE;
    	}
        return MMI_RET_OK;
#endif
#ifdef __MMI_WLAN_FEATURES__
	case MENU_ID_NETSET_PREF_MODE:
		{
            mmi_netset_entry_pref_mode(GRP_ID_NETSET_MAIN);
            g_netset_highlight_preferred_mode = MMI_TRUE;
            return MMI_RET_OK;
		}
#endif 

#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
	case MENU_ID_NETSET_GPRS_CONNECTION:
		mmi_entry_netset_gprs_mode(GRP_ID_NETSET_MAIN, evt->sender_id);
		return MMI_RET_OK;
#endif 

#ifdef __MANUAL_MODE_NW_SEL__
#ifndef __MMI_NETSET_SLIM__
    case MENU_ID_NETSET_NETSEL_SELECT_MODE:
#else
    case MENU_ID_NETSET_NETWORK_SELECTION:
#endif		
#endif 
/* delete for MAUI_03342583 [MT6260] "GPRS transfer pref" settings
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
	case MENU_ID_NETSET_PCH_MODE:
#endif 
*/
#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
	case MENU_ID_NETSET_HSPA_MODE:
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
        {
#ifdef __MMI_BACKGROUND_CALL__
			if (srv_ucm_is_background_call())
			{
				mmi_ucm_app_entry_error_message();
                return MMI_RET_OK;
			}
#endif /* __MMI_BACKGROUND_CALL__ */

			netset_sub_menu_id = cui_menu_create(
				GRP_ID_NETSET_MAIN,
				CUI_MENU_SRC_TYPE_APPCREATE,
				CUI_MENU_TYPE_APPMAIN,
				evt->highlighted_menu_id,
				MMI_FALSE,
				NULL);
			
			cui_menu_set_default_title_image_by_id(netset_sub_menu_id, MAIN_MENU_TITLE_SETTINGS_ICON);
			cui_menu_run(netset_sub_menu_id);
            return MMI_RET_OK;
        }

/* add  for MAUI_03342583 [MT6260] "GPRS transfer pref" settings*/
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
	case MENU_ID_NETSET_PCH_MODE:
        {
			netset_sub_menu_id = cui_menu_create(
				GRP_ID_NETSET_MAIN,
				CUI_MENU_SRC_TYPE_APPCREATE,
				CUI_MENU_TYPE_APPMAIN,
				evt->highlighted_menu_id,
				MMI_FALSE,
				NULL);
			
			cui_menu_set_default_title_image_by_id(netset_sub_menu_id, MAIN_MENU_TITLE_SETTINGS_ICON);
			cui_menu_run(netset_sub_menu_id);
            return MMI_RET_OK;
        }
#endif 
/*add end*/
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 
	
#ifdef __MMI_3G_SWITCH__
	case MENU_ID_NETSET_3G_SERVICE_SWITCH:
		{
			mmi_netset_entry_3g_switch_menu(param);
            return MMI_RET_OK;
		}
#endif	
	default:
	    break;
	}
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_main_proc
 * DESCRIPTION
 *  Proc function for GRP_ID_NETSET_MAIN
 * PARAMETERS
 *  param : [IN]    post event
 * RETURNS
 *  process result
 *****************************************************************************/
static mmi_ret mmi_netset_main_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PREF_NETWORK__
    mmi_ret ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(param->evt_id)
	{
        /* menu CUI event hdlr */
        case EVT_ID_CUI_MENU_ITEM_SELECT: 
			{
				return mmi_netset_menu_cui_select_evt_hdlr(param);
			}
        case EVT_ID_CUI_MENU_LIST_ENTRY: 
			{
				return mmi_netset_menu_cui_entry_evt_hdlr(param);
			}
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			{
				cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
				cui_menu_close(evt->sender_id);
                return MMI_RET_OK;
			}
		case EVT_ID_GROUP_DEINIT:
		#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
			if(g_sim_menu_title_str)
			{
				OslMfree(g_sim_menu_title_str);
				g_sim_menu_title_str = NULL;
			}
		#endif
            return MMI_RET_OK;
		
		default:
			break;
			
	}
    #ifdef __MMI_PREF_NETWORK__
    ret = mmi_netset_pref_list_proc(param);
    if (ret != MMI_RET_DONT_CARE)
	{
	    return ret;
	}
    #endif /* __MMI_PREF_NETWORK__ */
    if (cui_menu_is_menu_event(param->evt_id))
	{
	    return MMI_RET_DONT_CARE;
	}

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_main
 * DESCRIPTION
 *  This function is to enter network setup menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netset_main(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
		GRP_ID_ROOT,
        GRP_ID_NETSET_MAIN,
        mmi_netset_main_proc,
        NULL,
		MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    netset_menu_cui_id = cui_menu_create(
        GRP_ID_NETSET_MAIN,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_NETSET_MAIN,
        MMI_FALSE,
        NULL);
    NETSET_TRACE1(TRC_MMI_NETSET_ENTRY_MAIN_SCREEN, "[NetSetApp.c] mmi_entry_netset_main() %d", netset_menu_cui_id);   
    cui_menu_set_default_title_image_by_id(netset_menu_cui_id, MAIN_MENU_TITLE_SETTINGS_ICON);
    cui_menu_run(netset_menu_cui_id);
  
}


static U8 mmi_netset_set_item_info(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    U8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->parent_menu_id)
	{
#ifdef __MANUAL_MODE_NW_SEL__
#ifdef __MMI_NETSET_SLIM__
     case MENU_ID_NETSET_NETWORK_SELECTION:
#else            
	case MENU_ID_NETSET_NETSEL_SELECT_MODE:
#endif 
		{
			mmi_set_netsel_select_mode(evt->highlighted_menu_id);
			ret = 1;
		}
		break;
#endif /* __MANUAL_MODE_NW_SEL__ */
		
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
	case MENU_ID_NETSET_PCH_MODE:
		{
			mmi_netset_set_pch_confirm(evt->highlighted_menu_id);
			ret = 1;
		}
		break;
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
	case MENU_ID_NETSET_HSPA_MODE:
		{
			mmi_netset_set_hspa_confirm(evt->highlighted_menu_id);
			ret = 1;
		}
		break;
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
	default:
		break;
	}

	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_is_retrieve_data_needed
 * DESCRIPTION
 *  Check if need to retrieve data 
 * PARAMETERS
 *  
 * RETURNS
 *  static MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_netset_is_retrieve_data_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MMI_BOOL)(g_netset_update_sim_menu_hdlr[0] != NULL));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_retrieve_sim_menu_data
 * DESCRIPTION
 *  This function is to get current mode 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_retrieve_sim_menu_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 retrieve_step = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_RETRIEVE_CURRENT_MODE, "[NetSetApp.c] mmi_netset_retrieve_sim_menu_data()");

    if (g_netset_update_sim_menu_hdlr[retrieve_step])
    {
        (*g_netset_update_sim_menu_hdlr[retrieve_step])();
		retrieve_step++;
        return;
    }

    /* reset the retrieve step when it is finished */
    retrieve_step = 0;

#if( MMI_MAX_SIM_NUM >= 2 )
	cui_menu_play(netset_menu_cui_id);
#else
	mmi_entry_netset_main();
#endif
}
/* Network Setup Main Menu */

#ifndef __MMI_MAINLCD_96X64__
static void mmi_netset_hint_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if( MMI_MAX_SIM_NUM >= 2 )
	if ((evt->parent_menu_id == MENU_ID_NETSET_SIM1) || (evt->parent_menu_id == MENU_ID_NETSET_SIM2)
        #if (MMI_MAX_SIM_NUM >= 3)
            ||(evt->parent_menu_id == MENU_ID_NETSET_SIM3)
        #endif /* MMI_MAX_SIM_NUM >= 3 */
        #if (MMI_MAX_SIM_NUM >= 4)
            ||(evt->parent_menu_id == MENU_ID_NETSET_SIM4)
        #endif /* MMI_MAX_SIM_NUM == 4 */
       )
#else /* MMI_MAX_SIM_NUM >= 2 */
	if (evt->parent_menu_id == MENU_ID_NETSET_MAIN)
#endif /* MMI_MAX_SIM_NUM >= 2 */
	{
#ifdef __MANUAL_MODE_NW_SEL__
	cui_menu_set_item_hint(
		evt->sender_id, 
		MENU_ID_NETSET_NETWORK_SELECTION,
		(UI_string_type)mmi_hint_netsel_select_mode());
#endif /* __MANUAL_MODE_NW_SEL__ */

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

#if defined(__MMI_GPRS_FEATURES__)
  #if !defined(__MMI_EM_NW_GPRS_CONN__)
	cui_menu_set_item_hint(
		evt->sender_id, 
		MENU_ID_NETSET_GPRS_CONNECTION,
		(UI_string_type)mmi_hint_netset_gprs_connection());
  #else /* __MMI_EM_NW_GPRS_CONN__ */
     cui_menu_set_item_hint(evt->sender_id, MENU_ID_NETSET_GPRS_CONNECTION, MMI_TRUE);
  #endif /* __MMI_EM_NW_GPRS_CONN__ */
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
		cui_menu_set_item_hint(
			evt->sender_id, 
			MENU_ID_NETSET_HSPA_MODE,
			(UI_string_type)mmi_hint_netset_hspa_menu());	    
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
	}

#ifdef __MMI_WLAN_FEATURES__
	/*if (evt->parent_menu_id == MENU_ID_NETSET_MAIN)
	{
		cui_menu_set_item_hint(
			evt->sender_id, 
			MENU_ID_NETSET_PREF_MODE,
			(UI_string_type)mmi_netset_hint_pref_mode());
	}*/
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MANUAL_MODE_NW_SEL__
    #ifndef __MMI_NETSET_SLIM__
	if (evt->parent_menu_id == MENU_ID_NETSET_NETWORK_SELECTION)
	{
		cui_menu_set_item_hint(
			evt->sender_id, 
			MENU_ID_NETSET_NETSEL_SELECT_MODE,
			(UI_string_type)mmi_hint_netsel_select_mode());
	}
	#endif
#endif /* __MANUAL_MODE_NW_SEL__ */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_main_menu_hint
 * DESCRIPTION
 *  update hint for main menu 
 * PARAMETERS
 *  void
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_netset_update_main_menu_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE1(TRC_MMI_NETSET_ENTRY_MAIN_SCREEN, "[NetSetApp.c] mmi_netset_update_main_menu_hint() %d", netset_menu_cui_id);   

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
	cui_menu_set_item_hint(
		netset_menu_cui_id, 
		MENU_ID_NETSET_PCH_MODE,
		(UI_string_type)mmi_hint_netset_pch_menu());
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __MMI_3G_SWITCH__
	cui_menu_set_item_hint(
   		netset_menu_cui_id,
   		MENU_ID_NETSET_3G_SERVICE_SWITCH,
   		(UI_string_type)mmi_netset_3g_switch_get_menu_hint());
#endif
}

#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_main_menu
 * DESCRIPTION
 *  Update the main menu in multi SIM project 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_update_main_menu(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
 	WCHAR buffer[56];
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
    
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		mmi_sim_enum sim = mmi_frm_index_to_sim(i);
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__	
		cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_SIM1 + i, (MMI_BOOL)(!srv_sim_ctrl_is_inserted(sim)));
		if(srv_sim_ctrl_get_num_of_inserted() <= 1)
		{
			cui_menu_set_item_string_by_id(evt->sender_id, MENU_ID_NETSET_SIM1 + i, STR_GLOBAL_SIM);
		}
		else if(mmi_netset_get_sim_name_with_simx_and_brace(sim, buffer, 56) == 0)
		{
			cui_menu_set_item_string(evt->sender_id, MENU_ID_NETSET_SIM1 + i, buffer);
		}
	#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
		cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_SIM1 + i, (MMI_BOOL)(!srv_nw_usab_is_usable(sim)));
	#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
	}
#ifdef __MONITOR_PAGE_DURING_TRANSFER__    
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PCH_MODE, (MMI_BOOL)(!srv_nw_usab_any_sim_is_usable()));
#endif
}
#endif
 
 
static void mmi_netset_update_sim_menu(cui_menu_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__	
	if(g_sim_menu_title_str)
	{
		OslMfree(g_sim_menu_title_str);
		g_sim_menu_title_str = NULL;
	}
	g_sim_menu_title_str = OslMalloc(64);
	
	if(srv_sim_ctrl_get_num_of_inserted() <= 1)
	{
		cui_menu_set_currlist_title_by_id(evt->sender_id, STR_GLOBAL_SIM, 0);
	}
	else if(mmi_netset_get_sim_name_with_simx_and_brace(MMI_NETSET_CURRENT_SIM, g_sim_menu_title_str, 64) == 0)
	{
		cui_menu_set_currlist_title(evt->sender_id, g_sim_menu_title_str, 0);
	}
#endif /*__MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    
#if (MMI_MAX_SIM_NUM == 1)
	#ifdef __MMI_WLAN_FEATURES__
	{
        MMI_BOOL hidden_flag = !srv_nw_usab_is_usable(MMI_NETSET_CURRENT_SIM);
    	cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_NETWORK_SELECTION, hidden_flag);
    	#ifdef __MMI_PREF_NETWORK__
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST, hidden_flag);
        #endif
    	#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
/* under construction !*/
        #endif
/* under construction !*/
    	#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__    
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PCH_MODE, hidden_flag);
#endif
	}
    #endif /* __MMI_WLAN_FEATURES__ */
#endif		

#if defined(__MMI_GPRS_FEATURES__)
    #if !defined(__MMI_EM_NW_GPRS_CONN__)	
	cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_GPRS_CONNECTION, (MMI_BOOL)(!mmi_netset_is_gprs_connection_setting_available(MMI_NETSET_CURRENT_SIM)));
    #else
    cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_GPRS_CONNECTION, MMI_TRUE);
	#endif
#endif


	cui_menu_set_item_hidden(
		evt->sender_id, 
		MENU_ID_NETSET_NETWORK_SELECTION, 
		(MMI_BOOL)(!srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_PLMN_MODE, MMI_NETSET_CURRENT_SIM)));

/*#if (MMI_MAX_SIM_NUM >= 2)
	if (MMI_NETSET_CURRENT_SIM == MMI_SIM1)
#endif
	{*/
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__)
	cui_menu_set_item_hidden(evt->sender_id, 
		MENU_ID_NETSET_HSPA_MODE, 
		(MMI_BOOL)(!mmi_netset_is_hspa_setting_available() || (MMI_NETSET_CURRENT_SIM != srv_netset_get_3g_capability_sim())));
#endif

		#if (MMI_MAX_SIM_NUM >= 2)
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		#endif
/*	}
#if (MMI_MAX_SIM_NUM >= 2)
	else
	{
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__)
#ifdef __MMI_3G_SWITCH__
#else
	cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_HSPA_MODE, (MMI_BOOL)(!mmi_netset_is_hspa_setting_available()));
#endif
#endif
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
		cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_SERVICE_SELECTION, g_netset_hide_rat_setting);
		#endif
	}
#endif  */  
#ifdef __MANUAL_MODE_NW_SEL__
#ifndef __MMI_NETSET_SLIM__
		cui_menu_set_item_hidden(
			evt->sender_id, 
			MENU_ID_NETSET_NETSEL_SELECT_MODE, 
			(MMI_BOOL)(!srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_PLMN_MODE, mmi_netset_curr_sim)));
#endif
#endif
}


MMI_ID mmi_netset_get_sub_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return netset_sub_menu_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_ctrl_changed_hdlr
 * DESCRIPTION
 *  Handler for SIM control changed 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_netset_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
    {
        srv_sim_ctrl_availability_changed_evt_struct *change_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;        
        if ((change_evt->is_available_before && 
				!change_evt->is_available_now && 
				change_evt->sim == mmi_netset_get_active_sim())|| 
				MMI_SIM_NONE == mmi_netset_get_active_sim() ||
				srv_sim_ctrl_get_one_available_sim() == 0 ||/* If no SIM is inserted, close the general setting menu */
				change_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE ||
				change_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE)
		{
			if (mmi_frm_group_is_present(GRP_ID_NETSET_MAIN))
			{
				mmi_frm_group_close(GRP_ID_NETSET_MAIN);
				if(srv_sim_ctrl_get_one_available_sim())
				{
				     mmi_entry_netset_main();
			    }
    	    }
    	}
        break;
    }
	    
	case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
	{
		srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)evt;
		if(flightMode->select_flight_mode == SRV_MODE_SWITCH_ON)
		{		
			if (mmi_frm_group_is_present(GRP_ID_NETSET_MAIN))
			{
			   mmi_frm_group_close(GRP_ID_NETSET_MAIN);
			}
		}					
		break;
	}
	    
	default:
	break;
    }
    return MMI_RET_OK;
}

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__ENS_RAT_BALANCING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__ENS_RAT_BALANCING__) */
mmi_ret mmi_netset_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MONITOR_PAGE_DURING_TRANSFER__	
    extern void mmi_netset_pch_sync_check(void);
#endif
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__ENS_RAT_BALANCING__)   
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__ENS_RAT_BALANCING__) */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    mmi_netset_pch_sync_check();
#endif
    return MMI_RET_OK;
}

/* External Interface to Other Application */


