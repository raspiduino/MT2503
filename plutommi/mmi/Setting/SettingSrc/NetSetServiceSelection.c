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
 * NetSetServiceSelection.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is UI flow of network service selection application
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
#include "NetSetSrvGprot.h"
#include "L3_inc_enums.h"   /* AUTOMATIC_MODE & MANUAL_MODE enum */
#include "custom_events_notify.h"   /* Display popup event enum */
#include "MENUCuiGprot.h"
#include "NWInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
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
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "NetworkSetupGprot.h"  ///for old API
#include "BootupSrvGprot.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_netset_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#endif
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_setting_def.h"
#endif
#include "ModeSwitchSrvGprot.h"
#include "IdleGprot.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "UcmSrvGprot.h"
#include "UcmGProt.h"
#include "ModeSwitchAppGprot.h"
#include "NwUsabSrvGprot.h"
#include "AlarmSrvGprot.h"
#include "sim_public_enum.h"

/***************************************************************************** 
* Local define
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/
static mmi_sim_enum netset_curr_sim;
#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__))
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_GPRS_CONN__)) && defined(__MMI_GPRS_FEATURES__)	
static U8 gprs_status;
static U16 gprs_parent_grp_id;
static U8 set_gprs;
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__))
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#endif /* (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)) */


#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_GPRS_CONN__)) && defined(__MMI_GPRS_FEATURES__)	
static mmi_ret mmi_netset_set_gprs_state_rsp(mmi_event_struct *ptr_rsp);
static void mmi_entry_netset_set_gprs_progress(void);
#ifdef __PLUTO_MMI_PACKAGE__
static mmi_ret mmi_netset_get_gprs_mode_rsp(mmi_event_struct *ptr_rsp);
#endif
static void mmi_entry_netset_set_gprs_progress(void);
static mmi_ret mmi_entry_netset_gprs_mode_proc(mmi_event_struct *param);
#ifdef __MMI_EM_NW_GPRS_CONN__
static mmi_ret mmi_em_nw_get_gprs_mode_rsp(mmi_event_struct *ptr_rsp);
#endif /* __MMI_EM_NW_GPRS_CONN__ */
#endif /* (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_GPRS_CONN__)) && defined(__MMI_GPRS_FEATURES__) */

/***************************************************************************** 
* Sevice mode selection mode Function
*****************************************************************************/
#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__))
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
#ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_NW_SERVICE_MODE_SELECTION__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MMI_BACKGROUND_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
        #ifndef __MMI_EM_NW_SERVICE_MODE_SELECTION__
/* under construction !*/
        #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_EM_NW_SERVICE_MODE_SELECTION__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #ifdef __PLUTO_MMI_PACKAGE__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#endif /* __PLUTO_MMI_PACKAGE__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __PLUTO_MMI_PACKAGE__
    #ifdef __MMI_NETSET_3G_ENHANCE__
/* under construction !*/
    #endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef	__MMI_EM_NW_SERVICE_MODE_SELECTION__
/* under construction !*/
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
/* under construction !*/
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
#ifdef __PLUTO_MMI_PACKAGE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __PLUTO_MMI_PACKAGE__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __PLUTO_MMI_PACKAGE__ */
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#endif /* defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__) */



/***************************************************************************** 
* GPRS mode selection mode Function
*****************************************************************************/
#if (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_GPRS_CONN__)) && defined(__MMI_GPRS_FEATURES__)	
#ifdef __MMI_EM_NW_GPRS_CONN__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_entry_gprs_conn_mode
 * DESCRIPTION
 *  entry gprs connectivity from engine mode.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_nw_entry_gprs_conn_mode(MMI_ID menu_id)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_get_gprs_connection_state(MMI_SIM1, mmi_em_nw_get_gprs_mode_rsp, &menu_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_get_gprs_mode_rsp
 * DESCRIPTION
 *  get gprs connectivity mode from em mode.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_em_nw_get_gprs_mode_rsp(mmi_event_struct *ptr_rsp)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_connect_type_rsp_struct *rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_gprs_connection_rsp_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (rsp_msg->result)
    {
        gprs_status = rsp_msg->type;
    }
    else
    {
        gprs_status = 0;
    }

	mmi_entry_netset_gprs_mode(GRP_ID_ROOT, *(U16 *)ptr_rsp->user_data);
	
    return MMI_RET_OK;
}

#endif /* __MMI_EM_NW_GPRS_CONN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_is_gprs_connection_setting_available
 * DESCRIPTION
 *  Check if the GPRS connection setting is available for the imput SIM 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_netset_is_gprs_connection_setting_available(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	#ifdef __MMI_3G_SWITCH__
		sim_interface_enum sim_idx = l4c_gemini_get_switched_sim_id(mmi_frm_sim_to_index(sim));
	#else
		sim_interface_enum sim_idx = (sim_interface_enum)mmi_frm_sim_to_index(sim);
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    return MMI_TRUE;
#else
    return is_test_sim(sim_idx);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hint_netset_gprs_connection
 * DESCRIPTION
 *  Get gprs hint string for menu cui. 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

CHAR* mmi_hint_netset_gprs_connection(void)
{
	switch(gprs_status)
	{
	case 0:
		return (CHAR*)GetString(STR_ID_NETSET_GPRS_CONNECTION_WHENNEEDED);
		
	case 1:
		return (CHAR*)GetString(STR_ID_NETSET_GPRS_CONNECTION_ALWAYS);
	    
	default:
	    break;
	}

	return NULL;
}

/* Network Setup GPRS Connection Mode */
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_gprs_mode
 * DESCRIPTION
 *  This function is to enter GPRS Connection Mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netset_gprs_mode(mmi_id parent_id, mmi_id menu_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//MMI_ID grp_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MMI_BACKGROUND_CALL__
		if (srv_ucm_is_background_call())
		{
			mmi_ucm_app_entry_error_message();
			return ;
		}
#endif
#endif
	gprs_parent_grp_id = mmi_frm_group_create_ex(parent_id,
							GRP_ID_AUTO_GEN,
							mmi_entry_netset_gprs_mode_proc,
							NULL,
							MMI_FRM_NODE_SMART_CLOSE_FLAG);

	cui_menu_create_and_run(gprs_parent_grp_id,
							CUI_MENU_SRC_TYPE_RESOURCE,
							CUI_MENU_TYPE_APPSUB,
							menu_id,
							MMI_FALSE,
							NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_gprs_mode_proc
 * DESCRIPTION
 *  This function is proc function of screen of set GPRS connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_entry_netset_gprs_mode_proc(mmi_event_struct *param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
	mmi_id menu_id = evt->sender_id;
    mmi_menu_id list_of_ids[2];
	mmi_menu_id i;
	U32 hilite;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	hilite = gprs_status;
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			for (i = 0; i < 2; i++) 
		    {
		        list_of_ids[i] = i;
		    }
		    
		    cui_menu_set_currlist(
		        menu_id, 
		        2, 
		        list_of_ids);
		    
		    cui_menu_set_currlist_flags(menu_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
			
		    cui_menu_set_currlist_title(
		        menu_id, 
		        (WCHAR*)get_string(STR_ID_NETSET_GPRS_CONNECTION), 
		        NULL);
			
	        cui_menu_set_item_string_by_id(
	            menu_id, 
	            list_of_ids[0],
	            STR_ID_NETSET_GPRS_CONNECTION_WHENNEEDED);
			
			cui_menu_set_item_string_by_id(
	            menu_id, 
	            list_of_ids[1],
				STR_ID_NETSET_GPRS_CONNECTION_ALWAYS);	
		#ifndef __MMI_EM_NW_GPRS_CONN__
			cui_menu_set_default_title_image_by_id(menu_id, MAIN_MENU_TITLE_SETTINGS_ICON);
		#endif
		    cui_menu_set_currlist_highlighted_id(menu_id, (mmi_menu_id)hilite);
			break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
			cui_menu_set_currlist_left_softkey_by_id(
		        menu_id, 
		        STR_GLOBAL_OK);
			cui_menu_set_currlist_right_softkey_by_id(
		        menu_id, 
		        STR_GLOBAL_BACK);
			
			break;

		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			mmi_netset_set_gprs_state(evt->highlighted_menu_id);
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
	        cui_menu_close(menu_id);
		default:
			break;
			
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_set_gprs_progress
 * DESCRIPTION
 *  This function is progressing screen of set GPRS connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netset_set_gprs_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		gprs_parent_grp_id, 
		SCR_ID_NETSET_SET_GPRS_PROGRESS, 
		NULL, 
		mmi_entry_netset_set_gprs_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_ID_NETSET_GPRS_CONNECTION,
        NULL,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_gprs_state
 * DESCRIPTION
 *  This function is to enter GPRS Connection Mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_set_gprs_state(mmi_menu_id gprs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (gprs_status == gprs)	//same GPRS status	
	{
	    mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        mmi_frm_group_close(gprs_parent_grp_id);
	}
	else
	{
		mmi_entry_netset_set_gprs_progress();
		set_gprs = (U8)gprs;
	#ifndef __MMI_EM_NW_GPRS_CONN__
		srv_netset_set_gprs_connection_state(MMI_NETSET_CURRENT_SIM, (srv_netset_gprs_connect_mode_enum)gprs, mmi_netset_set_gprs_state_rsp, NULL);
	#else
		srv_netset_set_gprs_connection_state(MMI_SIM1, (srv_netset_gprs_connect_mode_enum)gprs, mmi_netset_set_gprs_state_rsp, NULL);
	#endif
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_gprs_state_rsp
 * DESCRIPTION
 *  This function is response function of GPRS Connection Mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_set_gprs_state_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_gprs_connect_type_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_gprs_connection_rsp_data;

    if (rsp_msg->result)
    {
        gprs_status = set_gprs;
        if (mmi_frm_scrn_is_present(gprs_parent_grp_id, SCR_ID_NETSET_SET_GPRS_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(gprs_parent_grp_id, SCR_ID_NETSET_SET_GPRS_PROGRESS);            
            mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
			mmi_frm_group_close(gprs_parent_grp_id);
    	}
    }
    else
    {
        if (mmi_frm_scrn_is_present(gprs_parent_grp_id, SCR_ID_NETSET_SET_GPRS_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(gprs_parent_grp_id, SCR_ID_NETSET_SET_GPRS_PROGRESS);            
    		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    	}        
    }
    return MMI_RET_OK;
}

#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_gprs_mode_req
 * DESCRIPTION
 *  This function is to get current gprs connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_get_gprs_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_netset_get_gprs_connection_state(MMI_NETSET_CURRENT_SIM, mmi_netset_get_gprs_mode_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_gprs_mode_rsp
 * DESCRIPTION
 *  This function is response function of get current gprs connection state 
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_get_gprs_mode_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_connect_type_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_gprs_connection_rsp_data;

    if (rsp_msg->result)
    {
        gprs_status = rsp_msg->type;
    }
    else
    {
        gprs_status = 0;
    }
#ifndef __MMI_EM_NW_GPRS_CONN__
    mmi_netset_retrieve_sim_menu_data();
#endif
    return MMI_RET_OK;
}
#endif /* __PLUTO_MMI_PACKAGE__ */

#endif /* (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_EM_NW_GPRS_CONN__)) && defined(__MMI_GPRS_FEATURES__)	 */

