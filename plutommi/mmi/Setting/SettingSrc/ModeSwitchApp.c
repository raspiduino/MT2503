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
 *  ModeSwitchApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for mode switch application
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/

#include "MMI_features.h"

#if (MMI_MAX_SIM_NUM >= 2)

/***************************************************************************** 
* Include
*****************************************************************************/
#include "ModeSwitchAppGprot.h"
#include "PhoneSetup.h"
#include "AlarmFrameworkProt.h"
#include "ModeSwitchSrvGProt.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "IdleGprot.h"
#include "NetSetAppGprot.h"
#include "NotificationGprot.h"
#include "mmi_frm_utility_gprot.h"

/* auto add by kw_check begin */
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "mmi_rp_app_mode_switch_def.h"
#include "mmi_frm_events_gprot.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "mmi_frm_nvram_gprot.h"
#include "AlertScreen.h"
#include "menucuigprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "CommonScreensResDef.h"
#include "NetSetSrvGprot.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
/* auto add by kw_check end */
#include "ModeSwitchAppProt.h"
#include "UcmSrvGprot.h" /* call count checking */
#include "wgui_touch_screen.h"
#include "l4crac_enums.h"
#include "mmi_msg_struct.h"
#include "stack_msgs.h"
#include "CommonScreens.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "FlightModeGProt.h" /* for mmi_phnset_check_dm_lock_popup */
#endif
#ifdef __MMI_BACKGROUND_CALL__
#include "UcmGProt.h" /* for mmi_ucm_app_entry_error_message */
#endif
#include "BootupSrvIprot.h"
#include "BootupSrvGprot.h"
#include "RestoreGprot.h"
#include "ReminderSrvGprot.h"
#include "AlarmProt.h"      
/***************************************************************************** 
* Static Declaration
*****************************************************************************/
#ifndef __MTK_TARGET__
extern void mmi_netset_modis_trace(char* format, ...);

#define PHNSET_TRACE0(tr, f)              mmi_netset_modis_trace(f)
#define PHNSET_TRACE1(tr, f, a1)          mmi_netset_modis_trace(f, a1)
#define PHNSET_TRACE2(tr, f, a1, a2)      mmi_netset_modis_trace(f, a1, a2)
#define PHNSET_TRACE3(tr, f, a1, a2, a3)  mmi_netset_modis_trace(f, a1, a2, a3)
#else
#define PHNSET_TRACE0(tr, f)              MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f)
#define PHNSET_TRACE1(tr, f, a1)          MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1)
#define PHNSET_TRACE2(tr, f, a1, a2)      MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1, a2)
#define PHNSET_TRACE3(tr, f, a1, a2, a3)  MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, f, a1, a2, a3)
#endif

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#if (MMI_MAX_SIM_NUM >= 3)
typedef struct
{
    U8 highlight_index;
    U8 mark_flag[SRV_SIM_CTRL_MAX_SIM_NUM]; // Gemini+
} mmi_mode_switch_cntx_struct;

static mmi_mode_switch_cntx_struct* g_mmi_mode_switch_cntx_p;
#endif
/***************************************************************************** 
* Local Function
*****************************************************************************/


/***************************************************************************** 
* External Function
*****************************************************************************/
static mmi_ret mmi_mode_switch_switch_progress_leave_proc(mmi_event_struct *param);
static mmi_ret mmi_mode_switch_switch_mode_callback(mmi_event_struct *result);


typedef enum
{
    MMI_MODE_SWITCH_DYNAMIC_MODE_SCREEN,
    MMI_MODE_SWITCH_QUERY_MODE_SCREEN,
    MMI_MODE_SWITCH_MODE_SCREEN_TOTAL
} mmi_mode_switch_screen_enum;
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
static U8 g_cur_switch_type;
#endif
static U8 g_mode_switch_screen;
static U8 g_need_query_screen;
static srv_mode_switch_type_enum g_mode_switch_original_mode;
static MMI_BOOL g_mode_switch_is_check_service_enabled;
static MMI_BOOL g_mode_switch_sim_is_no_full_service[MMI_SIM_TOTAL] = {MMI_TRUE};

#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
extern void mmi_highlight_mode_switch_type(void);
extern void mmi_hint_mode_switch_type(U16 index);
static void mmi_mode_switch_entry_switch_type_screen(void);
static mmi_ret mmi_mode_switch_type_proc(mmi_event_struct *param);
static void mmi_mode_switch_init_switch_type(void);
static void mmi_mode_switch_set_switch_type_confirm(void);
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
static void mmi_mode_switch_entry_query_switch_screen(void);
static void mmi_mode_switch_query_screen_entry_from_idle_int(mmi_scrn_essential_struct *scrn_data);
#if (!defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
static MMI_BOOL mmi_mode_switch_setting_is_valid(void);
#endif
extern void mmi_highlight_mode_switch_setting(void);
static void mmi_mode_switch_switch_setting_back(void);
static U8 mmi_mode_switch_check_entry_switch_mode(void);
static U32 mmi_mode_switch_get_mode_screen_hilite_menu_id(void);
static mmi_ret mmi_mode_switch_setting_proc(mmi_event_struct *param);
static void mmi_mode_switch_init_setting_menu(void);
static void mmi_mode_switch_switch_mode_item(U32 sel_menu_id);
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
static MMI_BOOL g_mode_switch_sim_mode_popup_is_disabled;
#endif


/* COMMON FUNCTIONS FOR BOTH DUAL SIM AND SINGLE SIM */
/*****************************************************************************
 * FUNCTION
 *  mmi_highlight_mode_switch_setting
 * DESCRIPTION
 *  high light function of mode switch setting
 * PARAMETERS
 *  void      
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_highlight_mode_switch_setting(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifndef __MTK_TARGET__
	SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
	return;
#endif /* __MTK_TARGET__ */
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	SetLeftSoftkeyFunction(mmi_netset_sim_name_setting_launch, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_netset_sim_name_setting_launch, KEY_EVENT_UP);
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
	SetLeftSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_get_setting_title_string
 * DESCRIPTION
 *  Gemini+ specific menu string 
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_mode_switch_get_setting_title_string(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 4)
    return STR_ID_MODE_SWITCH_SETTING_4SIM;
#elif (MMI_MAX_SIM_NUM == 3)
    return STR_ID_MODE_SWITCH_SETTING_3SIM;
#else
    return STR_ID_MODE_SWITCH_SETTING_2SIM;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_mode_callback
 * DESCRIPTION
 *  switch mode common callback function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_mode_switch_switch_mode_callback(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_mode_callback(%d)", ((srv_mode_switch_rsp_event_struct*)evt)->result);
    mmi_frm_scrn_set_leave_proc(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SWITCH_PROGRESS, NULL);
    mmi_frm_scrn_close(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SWITCH_PROGRESS);
	if (((srv_mode_switch_rsp_event_struct*)evt)->result)
	{
		mmi_mode_switch_switch_success();

        PHNSET_TRACE2(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_mode_callback() current %d, original %d", srv_mode_switch_get_current_mode(), g_mode_switch_original_mode);
        if (srv_mode_switch_get_switch_type() == SRV_MODE_SWITCH_DYNAMIC_MODE)
    	{
            srv_mode_switch_type_enum mode = (srv_mode_switch_type_enum)(srv_mode_switch_get_current_mode() & ~g_mode_switch_original_mode);
            U8 i;
            for (i = 0; i < MMI_SIM_TOTAL; i++)
        	{
                mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        		if (mode & sim)
            	{
            	    mmi_mode_switch_query_enable_check_service(sim);
                    mode &= ~sim;
            	}
        	}
    	}
	}
	else
	{
		mmi_mode_switch_switch_failed();
	}
    #if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    g_mode_switch_sim_mode_popup_is_disabled = MMI_FALSE;
    #endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
	mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_progress
 * DESCRIPTION
 *  Enter function of mode switch progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_switch_progress(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_progress()");
    if (!mmi_frm_group_is_in_active_serial(GRP_ID_MODE_SWITCH_SETTING))
	{
	    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
		{
		    mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
		}
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_MODE_SWITCH_SETTING,
            NULL,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
	}
    if(!mmi_frm_scrn_enter(
        GRP_ID_MODE_SWITCH_SETTING,
        SCR_ID_MODE_SWITCH_SWITCH_PROGRESS,
        NULL,
        mmi_mode_switch_switch_progress,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SWITCH_PROGRESS, mmi_mode_switch_switch_progress_leave_proc);
    
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
	SetKeyDownHandler(MMI_dummy_function, KEY_END);
	SetKeyUpHandler(MMI_dummy_function, KEY_END);
    ShowCategory66Screen(mmi_mode_switch_get_setting_title_string(),
                         GetRootTitleIcon(MENU_ID_MODE_SWITCH_SETTING), 0, 0, 0, 0,
                         (U8 *) GetString(STR_ID_MODE_SWITCH_SWITCHING), 
						 mmi_get_event_based_image(MMI_EVENT_PROGRESS), NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_progress_leave_proc
 * DESCRIPTION
 *  Leave proc for progressing popup 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_mode_switch_switch_progress_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_progress_leave_proc()");
    return MMI_RET_PROHIBIT_SCRN_ENTER;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_success
 * DESCRIPTION
 *  update BT / IRDA / WLAN status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_switch_success(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //AlmEnableExpiryHandler();
    srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL,MMI_TRUE);
    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*) GetString(STR_GLOBAL_DONE));	
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_failed
 * DESCRIPTION
 *  pop up error and terminate mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_switch_failed(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_failed()");

    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
    }
    
    //AlmEnableExpiryHandler();
    srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL,MMI_TRUE);
}


/* COMMON FUNCTIONS FOR BOTH DUAL SIM AND SINGLE SIM */
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_get_switch_type
 * DESCRIPTION
 *  get mode switch type 
 * PARAMETERS
 *  void     
 * RETURNS
 *  
 *****************************************************************************/
mmi_mode_switch_type_enum mmi_mode_switch_get_switch_type(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (mmi_mode_switch_type_enum)srv_mode_switch_get_switch_type();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_check_entry_switch_mode
 * DESCRIPTION
 *  check function of entry switch mode 
 * PARAMETERS
 *  void      
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_mode_switch_check_entry_switch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_check_entry_switch_mode()");

    if (srv_mode_switch_is_switching())
    {
		PHNSET_TRACE0(0, "[ModeSwitchApp.c] srv_mode_switch_is_switching return 1");
        return 0;
    }

    if (!srv_bootup_protocol_is_ready())
    {
        PHNSET_TRACE0(0, "[ModeSwitchApp.c] srv_bootup_protocol_is_ready return 0");
        return 0;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        PHNSET_TRACE0(0, "[ModeSwitchApp.c] srv_ucm_query_call_count return 1");
        return 0;
    }
#if (!defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
    if (!mmi_mode_switch_setting_is_valid())
    {
        PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_setting_is_valid return 0");
        return 0;
    }
#endif /* (! defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
    return 1;
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_highlight_hdlr
 * DESCRIPTION
 *  The entry function to keep user highlight on SIM selection screen
 * PARAMETERS
 *  index    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mode_switch_cntx_p->highlight_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mode_switch_switch_mode_item(0); // re-use 2-SIM API but meaningless for parameter
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_get_mark_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  *cntx
 * RETURNS
 *  srv_mode_switch_type_enum
 *****************************************************************************/
static srv_mode_switch_type_enum mmi_mode_switch_sim_selection_get_mark_result(mmi_mode_switch_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum sel_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx != NULL);

    sel_setting =  (srv_mode_switch_type_enum)((cntx->mark_flag[0])  // to count MMI_SIM1
                 | (cntx->mark_flag[1] << 1)  // to count MMI_SIM2
                 | (cntx->mark_flag[2] << 2)  // to count MMI_SIM3
    #if (MMI_MAX_SIM_NUM >= 4)
                 | (cntx->mark_flag[3] << 3)  // to count MMI_SIM4
    #endif
				 )
    ;

    return sel_setting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_query_disable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_query_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_mode_switch_sim_selection_get_mark_result(g_mmi_mode_switch_cntx_p) == srv_mode_switch_get_current_mode())
    {
        mmi_mode_switch_sim_selection_done();
        return;
    }

    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.callback = NULL;
    confirm_arg.parent_id = GRP_ID_MODE_SWITCH_SETTING;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_BOOTUP_SIM_NOT_SELECTED),
		MMI_EVENT_QUERY,
        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_query_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  *param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_mode_switch_sim_selection_query_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {    
        case EVT_ID_ALERT_QUIT:
	    {
            mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)param;
            switch (confirm_evt->result)
    	    {
                case MMI_ALERT_CNFM_YES:
                    mmi_mode_switch_sim_selection_done();
                    break;
            
                case MMI_ALERT_CNFM_NO:
                    GoBackHistory();
                    break;

                default:
                    break;
            }
    	}
    }

    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_change_mark_state
 * DESCRIPTION
 *  The entry function to toggle SIM selection mark screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_change_mark_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    standard_check_list_handle_item_select(g_mmi_mode_switch_cntx_p->highlight_index);   

    g_mmi_mode_switch_cntx_p->mark_flag[g_mmi_mode_switch_cntx_p->highlight_index] = !g_mmi_mode_switch_cntx_p->mark_flag[g_mmi_mode_switch_cntx_p->highlight_index];

    if (mmi_mode_switch_sim_selection_get_mark_result(g_mmi_mode_switch_cntx_p) == 0)
    {
        SetLeftSoftkeyFunction(mmi_mode_switch_sim_selection_query_disable, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_mode_switch_sim_selection_done, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_disable_sim
 * DESCRIPTION
 *  The function to disable the item of SIM not inserted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mode_switch_sim_selection_disable_sim(S32 index, U32 *flag, U32 *flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_mode_switch_sim_is_absent(MMI_SIM1) &&
    	mmi_mode_switch_sim_is_absent(MMI_SIM2) &&
    	mmi_mode_switch_sim_is_absent(MMI_SIM3) &&
    #if (MMI_MAX_SIM_NUM >= 4)
    	mmi_mode_switch_sim_is_absent(MMI_SIM4) &&
    #endif
    	index == 0)
    {
        return MMI_FALSE; /* special handling for no sim inserted */
    }


    if (!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index))
#if ( defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
/* If the SIM is not inserted, but RF turn ON, allow the user to switch it OFF */
       /* && srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(index)) == SRV_MODE_SWITCH_OFF*/
#endif /* ( defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
        )
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_mode_switch_sim_selection_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            mmi_mode_switch_switch_setting_back();

            if (g_mmi_mode_switch_cntx_p)
            {
                OslMfree(g_mmi_mode_switch_cntx_p);
                g_mmi_mode_switch_cntx_p = NULL;
            }
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;	
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_fte_tap_callback
 * DESCRIPTION
 *  The entry function to toggle SIM selection mark screen for FTE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_mode_switch_sim_selection_change_mark_state();
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_selection_entry
 * DESCRIPTION
 *  The entry function of SIM selection screen.
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_sim_selection_entry(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U16 num_of_items;
    U16 title_id = STR_ID_BOOTUP_SELECT_SIM, icon_id = 0;
    U8 *gui_buffer;

    static const U16 SIM_ID[] =
    {
        STR_GLOBAL_SIM_1,
        STR_GLOBAL_SIM_2,
#if (MMI_MAX_SIM_NUM >= 3)
        STR_GLOBAL_SIM_3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        STR_GLOBAL_SIM_4
#endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_MODE_SWITCH_SETTING,
            SCR_ID_MODE_SWITCH_SIM_SELECTION,
            NULL,
            (FuncPtr)mmi_mode_switch_sim_selection_entry,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    num_of_items = SRV_SIM_CTRL_MAX_SIM_NUM;

    for (index = 0; index < num_of_items; index++)
    {
        if (!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index)))
        {
            mmi_wsprintf(
                (WCHAR*)subMenuData[index],
                sizeof(subMenuData[0]),
                STR_ID_BOOTUP_SIMX_NOT_INSERTED,
                SIM_ID[index]);
        }
        else
        {
            mmi_wcsncpy(
                (WCHAR*)subMenuData[index],
                get_string(SIM_ID[index]),
                sizeof(subMenuData[0]) / sizeof(WCHAR) - 1);
        }
    }

    RegisterHighlightHandler(mmi_mode_switch_sim_selection_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_mode_switch_sim_selection_disable_sim);

    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

	if (g_mode_switch_screen != MMI_MODE_SWITCH_QUERY_MODE_SCREEN)
	{
        title_id = mmi_mode_switch_get_setting_title_string();
        icon_id = GetRootTitleIcon(MENU_ID_MODE_SWITCH_SETTING);
    }

    ShowCategory12Screen(
        title_id,
        icon_id,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        (U8 **) subMenuDataPtrs,
        g_mmi_mode_switch_cntx_p->mark_flag,
        0,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(mmi_mode_switch_sim_selection_change_mark_state);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_mode_switch_sim_selection_fte_tap_callback);
#endif

    SetCenterSoftkeyFunction(mmi_mode_switch_sim_selection_change_mark_state, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (mmi_mode_switch_sim_selection_get_mark_result(g_mmi_mode_switch_cntx_p) == 0)
    {
        SetLeftSoftkeyFunction(mmi_mode_switch_sim_selection_query_disable, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_mode_switch_sim_selection_done, KEY_EVENT_UP);
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SIM_SELECTION, mmi_mode_switch_sim_selection_leave_proc); // Gemini+: need patch
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_pre_entry_mode_switch_screen
 * DESCRIPTION
 *  common screen to hide and display menu before entry switch mode screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_pre_entry_mode_switch_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid = GRP_ID_ROOT;

#if (MMI_MAX_SIM_NUM >= 3)
    U8 index;
    MMI_BOOL sim_currently_inserted, sim_previously_selected;
#else
    //MMI_ID menucui_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_pre_entry_mode_switch_screen()");

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
		mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */  

    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    
	/* can't entry switch mode screen */
	if (mmi_mode_switch_check_entry_switch_mode() == 0)
	{
		PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_check_entry_switch_mode == 0 return");
		mmi_popup_display_simple_ext(STR_ID_MODE_SWITCH_INVALID, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
		return;
    }

#if (MMI_MAX_SIM_NUM >= 3)

    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_MODE_SWITCH_SETTING,
        mmi_mode_switch_sim_selection_query_proc,
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!g_mmi_mode_switch_cntx_p)
    {
        g_mmi_mode_switch_cntx_p = (mmi_mode_switch_cntx_struct*) OslMalloc(sizeof(mmi_mode_switch_cntx_struct));
    }
    else
    {
        MMI_ASSERT(0);
    }

    for (index = 0; index < SRV_SIM_CTRL_MAX_SIM_NUM; index++)
    {
        sim_currently_inserted = (MMI_BOOL)srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index)); // Gemini+
        sim_previously_selected = (MMI_BOOL)(srv_mode_switch_get_current_mode() & (1<<index));
        #if ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
        g_mmi_mode_switch_cntx_p->mark_flag[index] = (sim_currently_inserted && sim_previously_selected) ? 1 : 0;
        #else /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
        /* Enable the switched on RF selection */
        g_mmi_mode_switch_cntx_p->mark_flag[index] = (sim_currently_inserted && sim_previously_selected) ? 1 : 0;
        #endif /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
    }

    if (mmi_mode_switch_sim_is_absent(MMI_SIM1) &&
    	mmi_mode_switch_sim_is_absent(MMI_SIM2) &&
    #if (MMI_MAX_SIM_NUM >= 3)
    	mmi_mode_switch_sim_is_absent(MMI_SIM3) &&
    #if (MMI_MAX_SIM_NUM >= 4)
    	mmi_mode_switch_sim_is_absent(MMI_SIM4) &&
    #endif
    #endif
        MMI_TRUE)
    {
        g_mmi_mode_switch_cntx_p->mark_flag[mmi_frm_sim_to_index(MMI_SIM1)] = (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_SIM1) ? 1 : 0; /* special handling for no sim inserted */
    }

    mmi_frm_scrn_first_enter(
        GRP_ID_MODE_SWITCH_SETTING,
        SCR_ID_MODE_SWITCH_SIM_SELECTION,
        (FuncPtr)mmi_mode_switch_sim_selection_entry,
        NULL);

#else /* (MMI_MAX_SIM_NUM >= 3) */

    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_MODE_SWITCH_SETTING,
        mmi_mode_switch_setting_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(
        GRP_ID_MODE_SWITCH_SETTING,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_MODE_SWITCH_SETTING,
        MMI_FALSE,
        NULL);

#endif /* (MMI_MAX_SIM_NUM >= 3) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_setting_proc
 * DESCRIPTION
 *  Proc function for mode switch setting menu 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_mode_switch_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event = (cui_menu_event_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_menu_is_menu_event(param->evt_id))
	{
        switch (menucui_event->evt_id)
        {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_mode_switch_init_setting_menu();
            return MMI_RET_OK;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            mmi_mode_switch_switch_mode_item(menucui_event->highlighted_menu_id);
            return MMI_RET_OK;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_mode_switch_switch_setting_back();
    		return MMI_RET_OK;
    		
        default:
    		break;
        }	
        return MMI_RET_DONT_CARE;
	}
    return MMI_RET_OK;    
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_init_setting_menu
 * DESCRIPTION
 *  Initialize the mode switch setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_mode_switch_init_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menucui_gid = mmi_frm_group_get_active_id();
    mmi_menu_id highlighted_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_DUALCARD, MMI_FALSE);
    cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_CARD1, MMI_FALSE);
    cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_CARD2, MMI_FALSE);
    cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_FLIGHTMODE, MMI_TRUE);

    if (mmi_mode_switch_sim_is_absent(MMI_SIM2))		/* SIM2 not insert */
    {
        cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_CARD2, MMI_TRUE);
        cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_DUALCARD, MMI_TRUE);
    }
    else
    {
        if (mmi_mode_switch_sim_is_absent(MMI_SIM1))
        {
            cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_CARD1, MMI_TRUE);
            cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_DUALCARD, MMI_TRUE);
        }
    }

    if (g_mode_switch_screen == MMI_MODE_SWITCH_QUERY_MODE_SCREEN)
    {
        cui_menu_set_item_hidden(menucui_gid, MENU_ID_MODE_SWITCH_FLIGHTMODE, MMI_TRUE);
    }

	if (g_mode_switch_screen == MMI_MODE_SWITCH_QUERY_MODE_SCREEN)
	{
        cui_menu_set_currlist_title_by_id(menucui_gid,
            STR_ID_BOOTUP_SELECT_SIM,
            0);
        cui_menu_set_default_left_softkey_by_id(menucui_gid, STR_GLOBAL_OK);
        cui_menu_set_default_right_softkey_by_id(menucui_gid, STR_GLOBAL_CANCEL);        
	}
	else
	{
        cui_menu_set_currlist_title_by_id(menucui_gid,
            mmi_mode_switch_get_setting_title_string(),
            MAIN_MENU_TITLE_SETTINGS_ICON);
        cui_menu_set_default_left_softkey_by_id(menucui_gid, STR_GLOBAL_OK);
        cui_menu_set_default_right_softkey_by_id(menucui_gid, STR_GLOBAL_BACK);        
	}

    if (!mmi_frm_is_in_backward_scenario())
    {
    highlighted_idx = (mmi_menu_id)mmi_mode_switch_get_mode_screen_hilite_menu_id();
    cui_menu_set_currlist_highlighted_id(menucui_gid, highlighted_idx);    
    }

    cui_menu_set_currlist_flags(menucui_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_get_mode_screen_hilite_menu_id
 * DESCRIPTION
 *  get high light item index with different mode screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  U8
 *****************************************************************************/
static U32 mmi_mode_switch_get_mode_screen_hilite_menu_id(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mode_switch_type_enum cur_dm_setting = SRV_MODE_SWITCH_ALL_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_get_mode_screen_hilite_menu_id()");

	cur_dm_setting = srv_mode_switch_get_current_mode();

	PHNSET_TRACE2(0, "[ModeSwitchApp.c] cur_dm_setting[%d] g_mode_switch_screen[%d]",
		cur_dm_setting, g_mode_switch_screen);

	/* static mode, return high light directly */
	switch(cur_dm_setting)
	{
        case SRV_MODE_SWITCH_SIM_ALL:
		{
            #if ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
			return MENU_ID_MODE_SWITCH_DUALCARD;
            #else /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            if (!srv_sim_ctrl_is_inserted(MMI_SIM1) || !srv_sim_ctrl_is_inserted(MMI_SIM2))
            {
                if (srv_sim_ctrl_is_inserted(MMI_SIM2))
            	{
                    /* Only SIM2 inserted */
            	    return MENU_ID_MODE_SWITCH_CARD2;
            	}
                else
                {
                    /* Only SIM1 inserted or no SIM is inserted */
                    return MENU_ID_MODE_SWITCH_CARD1;
                }
            }
            else
            {
                return MENU_ID_MODE_SWITCH_DUALCARD;
            }
            #endif /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
		}

        case SRV_MODE_SWITCH_SIM1:
		{
            #if ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
			return MENU_ID_MODE_SWITCH_CARD1;
            #else /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            if (!srv_sim_ctrl_is_inserted(MMI_SIM1) && srv_sim_ctrl_is_inserted(MMI_SIM2))
        	{
                /* Only SIM2 is inserted */
        	    return MENU_ID_MODE_SWITCH_CARD2;
        	}
            else
            {
                return MENU_ID_MODE_SWITCH_CARD1;
            }
            #endif /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
		}

        case SRV_MODE_SWITCH_SIM2:
		{
            #if ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))
			return MENU_ID_MODE_SWITCH_CARD2;
            #else /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            if (srv_sim_ctrl_is_inserted(MMI_SIM2))
        	{
                /* Only SIM2 is inserted */
        	    return MENU_ID_MODE_SWITCH_CARD2;
        	}
            else
            {
                /* Only SIM1 inserted or no SIM is inserted */
                return MENU_ID_MODE_SWITCH_CARD1;
            }
            #endif /* ( !defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__)) */
		}

        case SRV_MODE_SWITCH_ALL_OFF:
		{
            if (!srv_sim_ctrl_is_inserted(MMI_SIM1) && srv_sim_ctrl_is_inserted(MMI_SIM2))
        	{
                /* Only SIM2 is inserted */
        	    return MENU_ID_MODE_SWITCH_CARD2;
        	}
            else
            {
                return MENU_ID_MODE_SWITCH_CARD1;
            }
		}

        default:
            break;
    }
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_setting_back
 * DESCRIPTION
 *  RSK of switch mode screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_switch_setting_back(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_setting_back()");

	if ((g_mode_switch_screen == MMI_MODE_SWITCH_QUERY_MODE_SCREEN) 
		&& mmi_frm_group_is_in_active_serial(GRP_ID_MODE_SWITCH_SETTING))
	{
		mmi_mode_switch_query_screen_reset_flag();
	}

#if (MMI_MAX_SIM_NUM == 2)
	cui_menu_close(mmi_frm_group_get_active_id());
#endif
}

#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_highlight_mode_switch_type
 * DESCRIPTION
 *  high light function of dual mode mode type setting
 * PARAMETERS
 *  void      
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_highlight_mode_switch_type(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_mode_switch_entry_switch_type_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mode_switch_entry_switch_type_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hint_mode_switch_type
 * DESCRIPTION
 *  hint function of dual mode mode type
 * PARAMETERS
 *  void      
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_hint_mode_switch_type(U16 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mode_switch_bootup_sel_type_enum switch_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_hint_mode_switch_type(%d)", index);
	switch_type = srv_mode_switch_get_switch_type();

	PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_hint_mode_switch_type(switch_type = %d)", switch_type);

	switch(switch_type)
	{
	case SRV_MODE_SWITCH_DYNAMIC_MODE:	
		{
			mmi_ucs2cpy((CHAR*)hintData[index], (CHAR*)GetString(STR_ID_MODE_SWITCH_DYNAMIC_MODE));
		}
		break;

	case SRV_MODE_SWITCH_STATIC_MODE:
		{
			mmi_ucs2cpy((CHAR*)hintData[index], (CHAR*)GetString(STR_ID_MODE_SWITCH_STATIC_MODE));
		}
	    break;

	default:
		{
			MMI_ASSERT(0);
		}
	    break;
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_entry_switch_type_screen
 * DESCRIPTION
 *  entry screen of dual mode type
 * PARAMETERS
 *  void      
 * RETURNS
 *  U8 status : 
 *****************************************************************************/
static void mmi_mode_switch_entry_switch_type_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_id = GRP_ID_ROOT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_entry_switch_type_screen()");

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
		mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */
    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_TYPE))
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    
    mmi_phnset_appcreate_menucui_create(
        parent_id,
        GRP_ID_MODE_SWITCH_TYPE,
        MENU_ID_MODE_SWITCH_TYPE,
        mmi_mode_switch_type_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_type_proc
 * DESCRIPTION
 *  Proc function for mode switch type setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_mode_switch_type_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event = (cui_menu_event_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_menu_is_menu_event(param->evt_id))
	{
        switch (menucui_event->evt_id)
        {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_mode_switch_init_switch_type();
            return MMI_RET_OK;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            g_cur_switch_type = (U8)menucui_event->highlighted_menu_id;
            mmi_mode_switch_set_switch_type_confirm();
            return MMI_RET_OK;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(mmi_frm_group_get_active_id());
    		return MMI_RET_OK;

        default:
    		break;
        }	
        return MMI_RET_DONT_CARE;
	}

    return MMI_RET_OK;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_init_switch_type
 * DESCRIPTION
 *  Initialize the switch type menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_mode_switch_init_switch_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	srv_mode_switch_bootup_sel_type_enum switch_type = srv_mode_switch_get_switch_type();
	U16 nStrItemList[MMI_MODE_SWITCH_TOTAL_MODE] = {STR_ID_MODE_SWITCH_DYNAMIC_MODE, STR_ID_MODE_SWITCH_STATIC_MODE};
    phnset_radio_button_menu_data_struct radio_button_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    radio_button_menu.group_id = GRP_ID_MODE_SWITCH_TYPE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = MMI_MODE_SWITCH_TOTAL_MODE;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = nStrItemList;
    radio_button_menu.highlighted_item_idx = switch_type;
#if (MMI_MAX_SIM_NUM == 4)
    radio_button_menu.menu_title_str_id = STR_ID_MODE_SWITCH_TYPE_4SIM;
#elif (MMI_MAX_SIM_NUM == 3)
    radio_button_menu.menu_title_str_id = STR_ID_MODE_SWITCH_TYPE_3SIM;
#else
    radio_button_menu.menu_title_str_id = STR_ID_MODE_SWITCH_TYPE_2SIM;
#endif

    mmi_phnset_init_radio_button_menu(&radio_button_menu);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_set_switch_type_confirm
 * DESCRIPTION
 *  query confirm screen of mode switch type screen
 * PARAMETERS
 *  S32 index      
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_mode_switch_set_switch_type_confirm(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_set_switch_type_confirm");

    mmi_popup_display_simple_ext(
         STR_GLOBAL_DONE,
         MMI_EVENT_SUCCESS,
         GRP_ID_ROOT,
         NULL);        
     mmi_frm_group_close(GRP_ID_MODE_SWITCH_TYPE);

	if (srv_mode_switch_get_switch_type() != g_cur_switch_type)
	{
        srv_mode_switch_set_switch_type(g_cur_switch_type);
	}
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dualmode_enable_check_service
 * DESCRIPTION
 *  Enable check service, if it is not in full service status, a SIM seleciton
 *  screen will be displayed when go back to idle 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_query_enable_check_service(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mode_switch_get_switch_type() != SRV_MODE_SWITCH_DYNAMIC_MODE)
	{
	    return;
	}
    g_mode_switch_is_check_service_enabled = MMI_TRUE;
    PHNSET_TRACE1(0, "[ModeSwitchApp.c]mmi_mode_switch_query_enable_check_service() %d", sim);
    g_mode_switch_sim_is_no_full_service[mmi_frm_sim_to_index(sim)] = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_query_screen_reset_flag
* DESCRIPTION
*  reset query screen in idle flag
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
void mmi_mode_switch_query_screen_reset_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_reset_flag()");
    g_need_query_screen = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_start
 * DESCRIPTION
 *  start function when network invalid
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_query_screen_start(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_start()");
	g_need_query_screen = 1;

	/* during switch */
	if (srv_mode_switch_is_switching())
	{
		return;
	}

	/* on idle and can switch mode */
	if (mmi_mode_switch_check_entry_switch_mode() && mmi_idle_is_active())
	{
		mmi_idle_display();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_end
 * DESCRIPTION
 *  start function when network valid
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_query_screen_end(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 disp_popup = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_end()");
	g_need_query_screen = 0;

	/* during switch */
	if (srv_mode_switch_is_switching())
	{
		return;
	}

	/* query confirm screen exist need display pop up */
	if (GetActiveScreenId() == SCR_ID_MODE_SWITCH_QUERY_CONFIRM)
	{
		disp_popup = 1;
	}

	/* query switch mode screen exist */
	if ((g_mode_switch_screen == MMI_MODE_SWITCH_QUERY_MODE_SCREEN) 
		&& mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
	{
		disp_popup = 1;
	}

	/* query screen on the top */
	if (disp_popup)
	{
		mmi_popup_display_simple_ext(STR_ID_MODE_SWITCH_QUERY_REMOVED_WITH_VALID_NW, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
	}
	
	/* after network valid query screen and switch mode screen must disappear */
	if ((g_mode_switch_screen == MMI_MODE_SWITCH_QUERY_MODE_SCREEN) 
		&& mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
	{
		mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
	}

    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_QUERY))
	{
	    mmi_frm_group_close(GRP_ID_MODE_SWITCH_QUERY);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_check_from_idle
 * DESCRIPTION
 *  check function of query confirm screen in idle
 * PARAMETERS
 *  void      
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_mode_switch_query_screen_check_from_idle(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_check_from_idle()");

#ifdef __MMI_WLAN_FEATURES__
    if (srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY)
    {
        return 0;
    }
#endif

	if (!g_need_query_screen || srv_mode_switch_get_switch_type() == SRV_MODE_SWITCH_STATIC_MODE)
	{
		PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_mode_switch_check_query_screen_from_idle() return 0 LINE[%d]", __LINE__);
		return 0;
	}

	if (!mmi_mode_switch_check_entry_switch_mode())
	{
		PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_mode_switch_check_query_screen_from_idle() return 0 LINE[%d]", __LINE__);
		return 0;
	}

	PHNSET_TRACE1(0, "[ModeSwitchApp.c] g_need_query_screen[%d]", g_need_query_screen);
	PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_mode_switch_check_query_screen_from_idle() return 0 LINE[%d]", __LINE__);
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_entry_from_idle
 * DESCRIPTION
 *  display query screen in idle
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_query_screen_entry_from_idle(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_entry_from_idle()");

    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_QUERY))
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_MODE_SWITCH_QUERY,
        NULL,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_MODE_SWITCH_QUERY,
        SCR_ID_MODE_SWITCH_QUERY_CONFIRM,
        (FuncPtr)mmi_mode_switch_query_screen_entry_from_idle_int,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_cancel
 * DESCRIPTION
 *  RSK function of query confirm screen in idle
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_query_screen_cancel(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_query_screen_cancel()");

	g_need_query_screen = 0;
    mmi_frm_group_close(GRP_ID_MODE_SWITCH_QUERY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_entry_from_idle_int
 * DESCRIPTION
 *  Internal entry function for mode switch query screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_mode_switch_query_screen_entry_from_idle_int(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        NULL,
        NULL,
        MMI_FRM_UNKNOW_SCRN))
	{
	    return;
	}
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory66Screen(
	STR_ID_BOOTUP_SELECT_SIM,
	0,
	STR_GLOBAL_YES,
	0,
	STR_GLOBAL_NO,
	0,
	(U8*)GetString(STR_ID_MODE_SWITCH_QUERY_CONFIRM),
	mmi_get_event_based_image(MMI_EVENT_QUERY),
	NULL);

    //SetKeyHandler(mmi_mode_switch_query_screen_cancel, KEY_END, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_mode_switch_query_screen_cancel, KEY_END);
    SetLeftSoftkeyFunction(mmi_mode_switch_entry_query_switch_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mode_switch_entry_query_switch_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_mode_switch_query_screen_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_nw_attach_hdlr
 * DESCRIPTION
 *  Show SIM selection again for no available network
 * PARAMETERS
 *  msg     [IN] network attachment indication
 *  src_mod [IN] source module
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_mode_switch_query_nw_attach_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_mode_switch_type_enum mode;
    MMI_BOOL sim_insert[SRV_SIM_CTRL_MAX_SIM_NUM] = {MMI_FALSE};
    MMI_BOOL sim_select[SRV_SIM_CTRL_MAX_SIM_NUM] = {MMI_FALSE};
    U8 sim_insert_count = 0, sim_select_count = 0, sim_no_service_count = 0, index;
    srv_nw_info_service_availability_changed_evt_struct *service_availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED)
	{
	    return MMI_RET_OK;
	}
    
    if (service_availability_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        g_mode_switch_is_check_service_enabled = MMI_FALSE;
		g_mode_switch_sim_is_no_full_service[mmi_frm_sim_to_index(service_availability_evt->sim)] = MMI_FALSE;
        //memset(g_mode_switch_sim_is_no_full_service, MMI_TRUE, sizeof(MMI_BOOL) * MMI_SIM_TOTAL);
        mmi_mode_switch_query_screen_end();
        return MMI_RET_OK;
    }
    if (!g_mode_switch_is_check_service_enabled)
	{
	    return MMI_RET_OK;
	}    
    sim = service_availability_evt->sim;
    mode = srv_mode_switch_get_current_mode();

    PHNSET_TRACE2(0, "[ModeSwitchApp.c]mmi_mode_switch_query_nw_attach_hdlr() sim %d, status %d", sim, service_availability_evt->new_status);

    switch (service_availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_NO_SERVICE:
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
            g_mode_switch_sim_is_no_full_service[mmi_frm_sim_to_index(sim)] = MMI_TRUE;
            break;

        default:
            /* Searching or unstable state */
            break;
    }

    for (index = 0; index < SRV_SIM_CTRL_MAX_SIM_NUM; index++)
    {
        sim_insert[index] = (MMI_BOOL)(!mmi_mode_switch_sim_is_absent(mmi_frm_index_to_sim(index)));
        if (sim_insert[index])
        {
            sim_insert_count++;
        }

        sim_select[index] = (MMI_BOOL)(mode & mmi_frm_index_to_sim(index));
        if (sim_select[index])
        {
            sim_select_count++;
            if (srv_nw_info_get_service_availability(mmi_frm_index_to_sim(index)) == SRV_NW_INFO_SA_NO_SERVICE ||
				 srv_nw_info_get_service_availability(mmi_frm_index_to_sim(index)) == SRV_NW_INFO_SA_LIMITED_SERVICE)
            {
                sim_no_service_count++;
            }
        }
    }

    PHNSET_TRACE2(0, "[ModeSwitchApp.c]mmi_mode_switch_query_nw_attach_hdlr() sim_select_count %d, sim_no_service_count %d", sim_select_count, sim_no_service_count);
    
    if (sim_insert_count <= 1)
    {
        g_mode_switch_is_check_service_enabled = MMI_FALSE;
        memset(g_mode_switch_sim_is_no_full_service, MMI_TRUE, sizeof(MMI_BOOL) * MMI_SIM_TOTAL);
        return MMI_RET_OK;
    }
    
    if (sim_select_count == sim_no_service_count)
    {
        g_mode_switch_is_check_service_enabled = MMI_FALSE;
        memset(g_mode_switch_sim_is_no_full_service, MMI_TRUE, sizeof(MMI_BOOL) * MMI_SIM_TOTAL);
        mmi_mode_switch_query_screen_start();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_query_init
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
void mmi_mode_switch_query_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mode_switch_get_switch_type() != SRV_MODE_SWITCH_STATIC_MODE)
    {
        U8 i;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
    	{
            mmi_mode_switch_query_enable_check_service(mmi_frm_index_to_sim(i));
    	}
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_entry_dynamic_switch_screen
* DESCRIPTION
*  enter dynamic mode switch screen
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
void mmi_mode_switch_entry_dynamic_switch_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_entry_dynamic_switch_screen()");
    g_mode_switch_screen = MMI_MODE_SWITCH_DYNAMIC_MODE_SCREEN;
    mmi_mode_switch_pre_entry_mode_switch_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_entry_query_switch_screen
* DESCRIPTION
*  enter query mode switch screen
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmi_mode_switch_entry_query_switch_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_entry_query_switch_screen()");
    g_mode_switch_screen = MMI_MODE_SWITCH_QUERY_MODE_SCREEN;
    mmi_mode_switch_pre_entry_mode_switch_screen();
}

#if (!defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))

/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_setting_is_valid
 * DESCRIPTION
 *  Check the setting restored in NVRAM and current sim status 
 * PARAMETERS
 *  
 * RETURNS
 *  static U8
 *****************************************************************************/
static MMI_BOOL mmi_mode_switch_setting_is_valid(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mode_switch_type_enum cur_dm_setting = SRV_MODE_SWITCH_ALL_OFF;

    U8 index;
    MMI_BOOL sim_not_inserted, mode_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_setting_is_valid()");

	cur_dm_setting = srv_mode_switch_get_current_mode();
    
	PHNSET_TRACE2(0, "[ModeSwitchApp.c] cur_dm_setting[%d] g_mode_switch_screen[%d]",    
        		cur_dm_setting, g_mode_switch_screen);

    if (mmi_mode_switch_sim_is_absent(MMI_SIM1) &&
    	mmi_mode_switch_sim_is_absent(MMI_SIM2) &&
    #if (MMI_MAX_SIM_NUM >= 3)
    	mmi_mode_switch_sim_is_absent(MMI_SIM3) &&
    #if (MMI_MAX_SIM_NUM >= 4)
    	mmi_mode_switch_sim_is_absent(MMI_SIM4) &&
    #endif
    #endif
    	cur_dm_setting == SRV_MODE_SWITCH_SIM1)
    {
        return MMI_TRUE; /* special handling for no sim inserted */
    }

    for (index = 0; index < SRV_SIM_CTRL_MAX_SIM_NUM; index++)
    {
        sim_not_inserted = (MMI_BOOL)mmi_mode_switch_sim_is_absent(mmi_frm_index_to_sim(index)); // Gemini+
        mode_selected = (MMI_BOOL)(cur_dm_setting & (1<<index));

        if (sim_not_inserted && mode_selected)
        {
        	PHNSET_TRACE0(0, "[ModeSwitchApp.c] can not enter this mode");
    	    return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}
#endif /*(!defined(__SIM_HOT_SWAP_SUPPORT__) && !defined(__SIM_RECOVERY_ENHANCEMENT__))*/

/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_switch_mode_item
 * DESCRIPTION
 *  Enter mode switch progress
 * PARAMETERS
 *  sel_menu_id [IN]    highlight menu item id      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mode_switch_switch_mode_item(U32 sel_menu_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum curr_setting = SRV_MODE_SWITCH_ALL_OFF;
	srv_mode_switch_type_enum sel_setting = SRV_MODE_SWITCH_ALL_OFF;
	U16 hilite = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_switch_mode_item");

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
		mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef __DM_LAWMO_SUPPORT__
	if (mmi_phnset_check_dm_lock_popup())
	{
		return;
	}
#endif /* __DM_LAWMO_SUPPORT__ */

	curr_setting = srv_mode_switch_get_current_mode();

	PHNSET_TRACE1(0, "[ModeSwitchApp.c] srv_mode_switch_get_current_mode return %d", curr_setting);

	PHNSET_TRACE2(0, "[ModeSwitchApp.c] hilite[%d] MenuID[%d]", hilite, sel_menu_id);

#if (MMI_MAX_SIM_NUM >= 3)
    sel_setting =  mmi_mode_switch_sim_selection_get_mark_result(g_mmi_mode_switch_cntx_p);
#else
	switch(sel_menu_id)
	{
	case MENU_ID_MODE_SWITCH_DUALCARD:
		{
			sel_setting = SRV_MODE_SWITCH_SIM_ALL;
		}
		break;

	case MENU_ID_MODE_SWITCH_CARD1:
		{
			sel_setting = SRV_MODE_SWITCH_SIM1;
		}
		break;

	case MENU_ID_MODE_SWITCH_CARD2:
		{
			sel_setting = SRV_MODE_SWITCH_SIM2;
		}
	    break;

	case MENU_ID_MODE_SWITCH_FLIGHTMODE:
		{
			sel_setting = SRV_MODE_SWITCH_ALL_OFF;
		}
	    break;

	default:
		{
			MMI_ASSERT(0);
		}
	    break;
	}
#endif /* (MMI_MAX_SIM_NUM >= 3) */

	mmi_mode_switch_query_screen_reset_flag();

	if (curr_setting == sel_setting)
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
        return;
    }

	mmi_mode_switch_switch_progress();

	/* disable alarm expiry handler */
	//AlmDisableExpiryHandler();
	srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL,MMI_FALSE);
    
    g_mode_switch_original_mode = curr_setting; // for network service status checking
    srv_mode_switch_switch_rf_mode(sel_setting, mmi_mode_switch_switch_mode_callback, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_sim_is_absent
* DESCRIPTION
*  get SIM insert status for mode switch
* PARAMETERS
*  void     
* RETURNS
*  
*****************************************************************************/
U8 mmi_mode_switch_sim_is_absent(mmi_sim_enum sim_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE1(0, "[ModeSwitchApp.c] mmi_mode_switch_sim_is_absent(%d)", sim_enum);
    return !srv_sim_ctrl_is_inserted(sim_enum);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_update_menu_int
 * DESCRIPTION
 *  Update the menu hidden status 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_mode_switch_update_menu_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_MODE_SWITCH_TYPE);
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    mmi_frm_unhide_menu_item(MENU_ID_MODE_SWITCH_SETTING);

    if (!srv_mode_switch_is_network_service_available())
    {
        /* in flight mode */
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__        
        mmi_frm_hide_menu_item(MENU_ID_MODE_SWITCH_TYPE);
#endif
        mmi_frm_hide_menu_item(MENU_ID_MODE_SWITCH_SETTING);
        return;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY)
    {
        /* in WLAN only mode */
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__        
        mmi_frm_hide_menu_item(MENU_ID_MODE_SWITCH_TYPE);
#endif
        mmi_frm_hide_menu_item(MENU_ID_MODE_SWITCH_SETTING);
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_mode_switch_menu_update_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void     
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret mmi_mode_switch_menu_update_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mode_switch_update_menu_int();
    PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_menu_update_hdlr()");

	switch(evt->evt_id)
	{
		case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
	{
	    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
		{
		   mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
		}
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
        if (!srv_mode_switch_is_network_service_available() || 
			mmi_get_current_restore_status() == MMI_TRUE)
    	{
    	    return MMI_RET_OK;
    	}
        g_mode_switch_sim_mode_popup_is_disabled = MMI_FALSE;
        {
            U8 i;
            srv_mode_switch_type_enum mode_setting = SRV_MODE_SWITCH_ALL_OFF;
            srv_sim_ctrl_availability_changed_evt_struct *sim_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

            PHNSET_TRACE3(0, "[ModeSwitchApp.c] mmi_mode_switch_menu_update_hdlr() SIM_AVAILABILITY_CHANGED %d %d %d", sim_evt->is_available_before, sim_evt->unavailable_cause_before, sim_evt->is_available_now);
            if (sim_evt->is_available_before == sim_evt->is_available_now)
        	{
                /* SIM availability is not changed, do not switch RF */
        	    return MMI_RET_OK;
        	}
            
            if (!srv_bootup_is_completed())
        	{
                /* Do not handle the initializing case, it will cause RF incorrect switch after boot up */
        	    return MMI_RET_OK;
        	}
            
            for (i = 0; i < MMI_SIM_TOTAL; i++)
        	{
        		mmi_sim_enum sim = mmi_frm_index_to_sim(i);
                if (srv_sim_ctrl_is_inserted(sim) 
                    && srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_ON)
            	{
                    // If the SIM enum is not the same as the mode enum
                    // Please do revise this
            	    mode_setting |= sim;
            	}
        	}
            
            // SIM is switch from not available to available, turn on the RF
            PHNSET_TRACE0(0, "[ModeSwitchApp.c] switch");
            if (!sim_evt->is_available_before && sim_evt->is_available_now)
        	{
        	    mode_setting |= sim_evt->sim;
        	}

            if (mode_setting == SRV_MODE_SWITCH_ALL_OFF && srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_ALL_OFF)
        	{
        	    mode_setting |= SRV_MODE_SWITCH_SIM1;
        	}
            
		#ifdef __MMI_WLAN_FEATURES__
			    if(srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY )
			    {
			    		srv_mode_switch_type_enum pre_rf_mode = srv_netset_get_prev_rf_mode();
			    		if (!sim_evt->is_available_before && sim_evt->is_available_now)
            	{	
        	    		pre_rf_mode |= sim_evt->sim;
            	}
            	srv_netset_save_prev_rf_mode(pre_rf_mode);
			    }
            else
		#endif /* __MMI_WLAN_FEATURES__ */
            if (mode_setting != srv_mode_switch_get_current_mode())
        	{
                srv_mode_switch_switch_rf_mode(mode_setting, mmi_mode_switch_switch_mode_callback, NULL);
        	}
        }
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
			break;
		}
		case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
		{
            srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)evt;
			if(flightMode->select_flight_mode == SRV_MODE_SWITCH_ON)
			{		
				if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
				{
				   mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
				}
			}					
			break;
		}
		default:
			break;
	}
    return MMI_RET_OK;
}

#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
static MMI_BOOL g_mode_switch_sim_mode_popup_is_disabled;
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_sim_mode_check
 * DESCRIPTION
 *  Check if curren mode is valid
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_mode_switch_sim_mode_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mode_switch_sim_mode_popup_is_disabled)
	{
       return 0;
	}
    
    for (index = 0; index < SRV_SIM_CTRL_MAX_SIM_NUM; index++)
    {
        if (!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index))
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    /* If the SIM is not inserted, but RF turn ON, allow the user to switch it OFF */
            && srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(index)) == SRV_MODE_SWITCH_ON
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            )
        {
            return 1;
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_query_screen_entry_from_idle_int
 * DESCRIPTION
 *  Internal entry function for mode switch query screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_mode_switch_entry_reset_mode_from_idle_int(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        NULL,
        NULL,
        MMI_FRM_UNKNOW_SCRN))
	{
	    return;
	}
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory66Screen(
	STR_ID_BOOTUP_SELECT_SIM,
	0,
	STR_GLOBAL_YES,
	0,
	STR_GLOBAL_NO,
	0,
	(U8*)GetString(STR_ID_MODE_SWITCH_RESET_MODE_CONFIRM),
	mmi_get_event_based_image(MMI_EVENT_QUERY),
	NULL);

    // only display once
    g_mode_switch_sim_mode_popup_is_disabled = MMI_TRUE;

    //SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_END, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_scrn_close_active_id, KEY_END);
    SetLeftSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mode_switch_entry_dynamic_switch_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_display_reset_mode_popup
 * DESCRIPTION
 *  Display reset mode popup 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_entry_reset_mode_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] mmi_mode_switch_display_reset_mode_popup()");

    if (mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_QUERY))
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_MODE_SWITCH_QUERY,
        NULL,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_MODE_SWITCH_QUERY,
        SCR_ID_MODE_SWITCH_QUERY_CONFIRM,
        (FuncPtr)mmi_mode_switch_entry_reset_mode_from_idle_int,
        NULL);
}

 

#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */

#endif /* (MMI_MAX_SIM_NUM >= 2) */

