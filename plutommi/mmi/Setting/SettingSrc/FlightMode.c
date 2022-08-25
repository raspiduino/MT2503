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
 *  FlightMode.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup application
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================== 
 *******************************************************************************/

#include "MMI_features.h"
#include "settingGprots.h"
#include "PhoneSetup.h"
#include "FlightModeGprot.h"
#include "UCMGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
#include "SmsSrvGprot.h"
#endif
#include "MessagesMiscell.h"
#if 0
#ifdef __MMI_IMPS__
/* under construction !*/
#endif /* __MMI_IMPS__ */
#endif

#if 0
#ifdef __MMI_OP01_DCD__
/* under construction !*/
#endif
#endif

#include "NwInfoSrvGprot.h"
#include "NetSetSrvProt.h"
#include "ModeSwitchSrvGprot.h"
#include "ModeSwitchSrvprot.h"
#include "menucuigprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_flight_mode_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "custom_events_notify.h"
#include "mmi_common_app_trc.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "l4crac_enums.h"
#include "AlertScreen.h"
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "CommonScreensResDef.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"
#include "l4c_nw_cmd.h"
#include "mmiapi_dm_struct.h"
#include "stack_msgs.h"
//#include "NetSetSrvGprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
/* auto add by kw_check end */
#include "FlightModeGProt.h"
#include "CSP.h"
/*
 * External Variable
 */
extern PHNSET_CNTX g_phnset_cntx;

#ifdef __DM_LAWMO_SUPPORT__
static U8 phnset_dm_locked = 0;
#endif

#include "SimCtrlSrvGprot.h"
#include "NotificationGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "ModeSwitchAppProt.h"
#include "ModeSwitchAppGprot.h"
#include "phonesetupgprots.h"
#include "ModeSwitchSrvProt.h"
#include "AlarmProt.h"      
#include "ATHandlerProt.h"      
#include "MMI_ap_dcm_config.h"
#include "AlarmDef.h"
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BTMMIScrGprots.h"
#endif

/*
 * Local Variable
 */


typedef enum
{
    MENU_NORMAL_MODE,
    MENU_FLIGHT_MODE,
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
    MENU_QUERY_MODE,
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    MENU_FLIGHT_MODE_TOTAL
} mmi_flight_mode_menu_enum;
static mmi_flight_mode_menu_enum g_flight_mode_current_mode;
static mmi_flight_mode_menu_enum g_flight_mode_select_mode;

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




#ifndef MMI_ON_HARDWARE_P
#define NVRAM_EF_SYS_CACHE_OCTET_SIZE 8
#endif 
static U8 g_is_set_flight_mode_from_at;
static int g_at_mod_id;
static void mmi_flight_mode_confirm_to_switch_mode(void);
static void mmi_flight_mode_entry_progress(void);
static mmi_ret mmi_flight_mode_progress_leave_proc(mmi_event_struct *param);
static void mmi_flight_mode_update_current_mode(void);
static mmi_ret mmi_flight_mode_proc(mmi_event_struct *param);
static void mmi_flight_mode_init_list(void);
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif 
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetFlightMode
 * DESCRIPTION
 *  This function is hint handling function for Phone Setup -> Flight Mode
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* hint_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
    if(srv_mode_switch_is_query_mode_enabled())
    {
        hint_str = (CHAR*) GetString(STR_FLIGHT_MODE_QUERY);
    }
    else
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    {
        if (srv_mode_switch_get_network_mode(MMI_SIM1) == SRV_MODE_SWITCH_ON)
    	{
    	    hint_str = (CHAR*) GetString(STR_FLIGHT_MODE_NORMAL);
        }
        else
        {
             hint_str = (CHAR*) GetString(STR_FLIGHT_MODE_SILENT);
        }
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_SETTING_FLIGHT_MODE,
        (WCHAR*)hint_str);
}
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_entry_progress
 * DESCRIPTION
 *  Entry flight mode progressing screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_flight_mode_entry_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        GRP_ID_PHNSET_FLIGHT_MODE,
        SCR_FLIGHT_MODE_PROGRESS,
        NULL,
        (FuncPtr)mmi_flight_mode_entry_progress,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
	SetKeyDownHandler(MMI_dummy_function, KEY_END);
	SetKeyUpHandler(MMI_dummy_function, KEY_END);
    ShowCategory66Screen(
        STR_MENU_FLIGHT_MODE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_FLIGHT_MODE_PROGRESS),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);    
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHNSET_FLIGHT_MODE, SCR_FLIGHT_MODE_PROGRESS, mmi_flight_mode_progress_leave_proc);    
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_progress_leave_proc
 * DESCRIPTION
 *  Leave proc for flight mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_flight_mode_progress_leave_proc(mmi_event_struct *param)
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
 *  mmi_flight_mode_switch_finish
 * DESCRIPTION
 *  Finish to perform mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_flight_mode_switch_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_FM_SELECTION_FINISH);
    
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    srv_sms_send_from_storage_schedule();
#endif
#if 0
#ifdef __MMI_IMPS__        	
/* under construction !*/
#endif
#endif
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHNSET_FLIGHT_MODE, SCR_FLIGHT_MODE_PROGRESS, NULL);
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*) GetString(STR_GLOBAL_DONE));
        mmi_frm_group_close(GRP_ID_PHNSET_FLIGHT_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_switch_rsp
 * DESCRIPTION
 *  Response of mode switch
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_flight_mode_switch_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(g_is_set_flight_mode_from_at)
	{	
		rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
		rsp_msg->result = (kal_bool)((srv_mode_switch_rsp_event_struct*)evt)->result;
		SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, g_at_mod_id, (void*)rsp_msg, NULL);
	    g_is_set_flight_mode_from_at = 0;
    }
	
    mmi_flight_mode_update_current_mode();
    mmi_frm_scrn_set_leave_proc(GRP_ID_PHNSET_FLIGHT_MODE, SCR_FLIGHT_MODE_PROGRESS, NULL);    
    if (((srv_mode_switch_rsp_event_struct*)evt)->result)
    {
		mmi_flight_mode_switch_finish();
        #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_mode_switch_is_network_service_available())
    	{
    	    U8 i;
            for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
                mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        	if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_ON)
            	{
            	    mmi_mode_switch_query_enable_check_service(sim);
            	}
            }
    	}
        else
        {
            mmi_mode_switch_query_screen_reset_flag();
        }
        #endif
    }
    else
    {
        if (mmi_frm_scrn_is_present(GRP_ID_PHNSET_FLIGHT_MODE, SCR_FLIGHT_MODE_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_PHNSET_FLIGHT_MODE, SCR_FLIGHT_MODE_PROGRESS);
    	}
		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
    }
    return MMI_RET_OK;   
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
#ifdef __DM_LAWMO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __DM_LAWMO_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_selection_done
 * DESCRIPTION
 *  Handler for the mode selection by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_flight_mode_selection_done(void)
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
        
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    if (g_flight_mode_select_mode == g_flight_mode_current_mode)
    {
        /* select mode is the same as current mode, so not necessary to send request to L4C */
		mmi_popup_display_simple_ext(
		    STR_GLOBAL_DONE, 
		    MMI_EVENT_SUCCESS,
		    GRP_ID_ROOT,
		    NULL);

        mmi_frm_group_close(GRP_ID_PHNSET_FLIGHT_MODE);/* flight mode menu */
    }
    else
    {
        mmi_flight_mode_confirm_to_switch_mode();
    }
}
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif 
/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_update_current_mode
 * DESCRIPTION
 *  Update current mode to g_flight_mode_current_mode 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_flight_mode_update_current_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
    if (srv_mode_switch_is_query_mode_enabled())
	{
	    g_flight_mode_current_mode = MENU_QUERY_MODE;
	}
    else
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    {
#if (MMI_MAX_SIM_NUM >= 2)
        g_flight_mode_current_mode = srv_mode_switch_is_network_service_available() ? MENU_NORMAL_MODE : MENU_FLIGHT_MODE;
#else
        if (srv_mode_switch_get_network_mode(MMI_SIM1) == SRV_MODE_SWITCH_ON)
    	{
            g_flight_mode_current_mode = MENU_NORMAL_MODE;
    	}        
        else
        {
            g_flight_mode_current_mode = MENU_FLIGHT_MODE;
        }
#endif
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_confirm_to_switch_mode
 * DESCRIPTION
 *  Confirm to perform mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_flight_mode_confirm_to_switch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		#ifdef __MMI_BT_DIALER_SUPPORT__
	if(srv_bt_cm_get_busy_dev() != NULL )
	{
		mmi_frm_nmgr_popup(
							 MMI_SCENARIO_ID_DEFAULT,
							 MMI_EVENT_FAILURE,
							(WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
			kal_prompt_trace(MOD_MMI,"[MIN]mmi_flight_mode_confirm_to_switch_mode  NOT CURRENTLY");
		return;

	}
	#endif
#ifdef __DM_LAWMO_SUPPORT__
	if (mmi_phnset_check_dm_lock_popup())
	{
		return;
	}
#endif /* __DM_LAWMO_SUPPORT__ */
    /* Check if need to switch mode */
    mmi_flight_mode_update_current_mode();
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    if (g_flight_mode_select_mode == MENU_QUERY_MODE)
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
		mmi_frm_group_close(GRP_ID_PHNSET_FLIGHT_MODE);/* flight mode menu */        
        srv_mode_switch_enable_query_mode(MMI_TRUE);
        mmi_flight_mode_update_current_mode();
        return;
    }
    if((g_flight_mode_select_mode != MENU_QUERY_MODE) &&
        (g_flight_mode_current_mode == MENU_QUERY_MODE))
    {
        srv_mode_switch_enable_query_mode(MMI_FALSE);
        if (((g_flight_mode_select_mode == MENU_NORMAL_MODE) && (srv_mode_switch_is_network_service_available()))
            || ((g_flight_mode_select_mode == MENU_FLIGHT_MODE) && (!srv_mode_switch_is_network_service_available())))
    	{
    		mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    		mmi_frm_group_close(GRP_ID_PHNSET_FLIGHT_MODE);/* flight mode menu */    	    
            mmi_flight_mode_update_current_mode();        
            return;
    	}
    }
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */

    mmi_flight_mode_entry_progress();  /* show searching screen */
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
#endif
       srv_mode_switch_switch_flight_mode(((g_flight_mode_select_mode == MENU_FLIGHT_MODE) ? MMI_TRUE : MMI_FALSE),MMI_TRUE, mmi_flight_mode_switch_rsp, NULL);
}

#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetFlightMode
 * DESCRIPTION
 *  This function is Entry function for Phone Setup -> Flight Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_flight_mode_entry(GRP_ID_ROOT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_entry
 * DESCRIPTION
 *  Entry flight mode screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_flight_mode_entry(MMI_ID parent_gid)
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
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */    

#ifndef __MTK_TARGET__
    PopupNoSupport();
    return;
#endif /* __MTK_TARGET__ */

    mmi_flight_mode_update_current_mode();
    mmi_phnset_appcreate_menucui_create(
    parent_gid,
    GRP_ID_PHNSET_FLIGHT_MODE,
    MENU_SETTING_FLIGHT_MODE,
    mmi_flight_mode_proc);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_flight_mode 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_flight_mode_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_flight_mode_init_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        g_flight_mode_select_mode = (mmi_flight_mode_menu_enum)((cui_menu_event_struct*)param)->highlighted_menu_id;
        mmi_flight_mode_selection_done();
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
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
 #endif   
        
    default:
		break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_init_list
 * DESCRIPTION
 *  Initialize the flight mode setting list 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_flight_mode_init_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;
#if (MMI_MAX_SIM_NUM >= 2) || !defined(__MMI_BOOTUP_MODE_SEL_SUPPORT__)
    U8 nNumofItem = 2;
    U16 nStrItemList[2] = {STR_FLIGHT_MODE_NORMAL, STR_FLIGHT_MODE_SILENT};
#else
    U8 nNumofItem = 3;
    U16 nStrItemList[3] = {STR_FLIGHT_MODE_NORMAL, STR_FLIGHT_MODE_SILENT, STR_FLIGHT_MODE_QUERY};
#endif
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    radio_button_menu.group_id = GRP_ID_PHNSET_FLIGHT_MODE;
    radio_button_menu.menu_title_str_id = MENU_SETTING_FLIGHT_MODE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = nNumofItem;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = nStrItemList;
    radio_button_menu.highlighted_item_idx = g_flight_mode_current_mode;
    
    mmi_phnset_init_radio_button_menu(&radio_button_menu);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_popup_in_dialing_sos
 * DESCRIPTION
 *  Popup "flight mode" when dial SOS from insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_flight_mode_is_switching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)srv_mode_switch_is_switching();
}
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif/*__MMI_OP11_HS32_CNX__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_power_on_ind_hdlr
 * DESCRIPTION
 *  Switch flight mode beginning and callback function
 *  Will be called on all project
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_flight_mode_power_on_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PHNSET_TRACE0(0, "[FlightMode.c] mmi_flight_mode_power_on_ind_hdlr()");

    srv_netset_init_pref_mode();
    srv_mode_switch_init();

    return (U8)MMI_FALSE;
}

#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_switch_preferred_mode
 * DESCRIPTION
 *  Switch flight mode beginning and callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_switch_flight_mode(void)	//only for BT to callback
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	extern void* srv_mode_switch_get_temp_func(void);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_FM_SWITCH_MODE);

	srv_mode_switch_update_cb_func();

}
#if 0
#if !defined(__MMI_OP11_HS32_CNX__)
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif 
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_update_status_icon
 * DESCRIPTION
 *  phased out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_update_status_icon(void)
{

}

#ifdef __DM_LAWMO_SUPPORT__
#ifndef __MMI_DEV_NEW_SLIM__
extern void AlmStopAlarmOnHW(void);
extern void AlmCheckAlarmState(void);
#else
extern void srv_reminder_notify_finish(MMI_BOOL pwr_confirm);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dm_lock_handler
 * DESCRIPTION
 *  Handler for DM lock 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phnset_dm_lock_notification_handler(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	srv_dm_lawmo_wipe_ind_evt_struct *lawmo_info = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lawmo_info->cmd)
	{
	case SRV_DM_LAWMO_LOCK_CMD_LOCK:
        if (!phnset_dm_locked)
    	{
    		phnset_dm_locked = 1;

    		//clean RTC reg and clean alarm queue
    		AlmStopAlarmOnHW();
    		ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);    	
			(*lawmo_info->cb)(MMI_TRUE, "PhoneSetting");
    	}
        break;
	case MMI_DMUI_CMD_LAWMO_UNLOCK:
        if (phnset_dm_locked)
    	{
    		phnset_dm_locked = 0;

    		//re init alarm and set alarm
    		//InitAlarmHandler();
    		AlmReInitialize();    	
			(*lawmo_info->cb)(MMI_TRUE, "PhoneSetting");
    	}
		break;
	default:
		break;
	}
	return MMI_RET_OK;
}

void mmi_phnset_dm_lock_handlr(MMI_BOOL lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (lock)	// need lock mobile
	{
		phnset_dm_locked = 1;

		//clean RTC reg and clean alarm queue
		ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);
	}
	else
	{
		phnset_dm_locked = 0;

		//re init alarm and set alarm
		//InitAlarmHandler();
		#ifndef __MMI_DEV_NEW_SLIM__
		AlmCheckAlarmState();
        #else
        srv_reminder_notify_finish(MMI_FALSE);
        #endif
	}
}

U8 mmi_phnset_is_dm_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return phnset_dm_locked;
}

U8 mmi_phnset_check_dm_lock_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_phnset_is_dm_lock())
	{
		mmi_popup_display_simple_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
		return 1;
	}
	else
	{
		return 0;
	}
}

#endif /* __DM_LAWMO_SUPPORT__ */
#ifndef __MMI_PHNSET_AT_DISABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_set_flight_mode_from_at
 * DESCRIPTION
 *  Query flight mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mode_switch_set_flight_mode_from_at(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_req_ind_struct *rsp_msg = (mmi_nw_cfun_state_req_ind_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_is_set_flight_mode_from_at = 1;
	g_at_mod_id = mod_id;
	if(!mmi_frm_group_is_present(GRP_ID_PHNSET_FLIGHT_MODE))
	{
		
		mmi_frm_group_create_ex(GRP_ID_ROOT,
			GRP_ID_PHNSET_FLIGHT_MODE,
			NULL,
			NULL, 
			MMI_FRM_NODE_SMART_CLOSE_FLAG);		 
	}
	
    if (rsp_msg->cfun_state == 0 || rsp_msg->cfun_state == 4)
    {
    	g_flight_mode_select_mode = MENU_FLIGHT_MODE;
    }
    else if (rsp_msg->cfun_state == 1)
    {
		g_flight_mode_select_mode = MENU_NORMAL_MODE;
    }
	srv_mode_switch_set_at_cfun_flag(rsp_msg->cfun_state + 1);
	mmi_flight_mode_confirm_to_switch_mode();

}
#endif

