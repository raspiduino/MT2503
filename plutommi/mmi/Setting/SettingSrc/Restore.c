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
 * Restore.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for restore factory default application
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Restore.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
/*  Include: MMI header file */
#include "ProtocolEvents.h"
#include "ScheduledPowerOnOffGprot.h"
#include "MMIThemes.h"
#include "UCMGprot.h"
#include "custom_nvram_config.h"
#include "RestoreGprot.h"

#include "SettingDefs.h"

#include "AlarmFrameWorkProt.h"
#include "nvram_enums.h"

#if !defined(__MTK_TARGET__)
#include "EngineerModeDef.h"
#endif 

#include "JavaAgencyGProt.h"

#include "ATHandlerProt.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_restore_def.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "CommonScreens.h"
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#include "mmi_pluto_res_range_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "gui_data_types.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "ps_public_struct.h"
#include "device.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "mmi_rp_srv_screensaver_def.h"
#include "mmi_phnset_dispchar.h"
#include "mmi_rp_srv_wallpaper_def.h"
#include "SettingGenum.h"
/* auto add by kw_check end */
#include "SettingProt.h"
#include "SettingGprots.h"
#include "SecSetCuiGprot.h"
#include "SecSetSrvGprot.h"
#include "mmi_rp_app_nitz_def.h"
#include "RestoreSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "SyncMLGprot.h"
#include "ScrLockerGprot.h"
#include "GpioSrvGprot.h"
//FOR IME plug in
#if defined(__MMI_IME_PLUG_IN__)
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif
#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
#include "MREAppMgrSrvGprot.h"
#endif
#include "PhoneSetup.h"
#include "PhoneSetupGprots.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
/*store restore status*/
U8 g_restore_is_processing_flag = MMI_FALSE;

static U32 mmi_restore_dest_mod = MOD_L4C;

static int src_mod_id = MOD_L4C;


/***************************************************************************** 
* External Function
*****************************************************************************/


/***************************************************************************** 
* Local Function
*****************************************************************************/
static void EntryRstRestoreProcessing(void);
static void mmi_restore_entry_restore_screen(void);
static mmi_ret mmi_restore_proc(mmi_event_struct *param);
static void ATRstConfirm(MMI_BOOL result);
static mmi_ret mmi_restore_processing_leave_proc(mmi_event_struct *evt);
#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
extern void mmi_java_send_restore_factory_mode_req(FuncPtr javaCBHandler);
#endif /* #if !defined(MMI_ON_WIN32) && defined(__J2ME__) */
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_restore_entry_check_phone_lock(void);
static mmi_ret mmi_restore_verify_phone_password_proc(mmi_event_struct *evt);
#endif
static U8 mmi_restore_app_callback_msg_rsp(void *msg);
static srv_restore_result_enum mmi_restore_detach_network(void);
static srv_restore_result_enum mmi_restore_app_reboot(void);
static srv_restore_result_enum mmi_restore_stop_audio_play(void);
#ifdef OPERA_BROWSER
static srv_restore_result_enum mmi_restore_full_html_browser(void);
#endif
#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
static srv_restore_result_enum mmi_restore_mre_app_uninstall(void);
#endif

static srv_restore_result_enum mmi_restore_reset_date_time(void);
static srv_restore_result_enum mmi_restore_send_msg_to_wap(void);
static srv_restore_result_enum mmi_setting_restore_java_data(void);
static srv_restore_result_enum mmi_restore_reset_app_status(void);
#if defined(__MMI_IME_PLUG_IN__)
static srv_restore_result_enum mmi_restore_factory_ime(void);
#endif

/***************************************************************************** 
* Restore application function table
*****************************************************************************/
static srv_restore_table_struct mmi_restore_app_table[] =
{
	mmi_restore_stop_audio_play,
	mmi_restore_reset_app_status,
#ifdef __MMI_TELEPHONY_SUPPORT__
	mmi_restore_detach_network,
#ifdef __GEMINI__
	mmi_restore_detach_network,
#if ((MMI_MAX_SIM_NUM >= 3))
	mmi_restore_detach_network,
#if (MMI_MAX_SIM_NUM >= 4)
	mmi_restore_detach_network,
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* __GEMINI__ */
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#if defined(__MMI_IME_PLUG_IN__)
    mmi_restore_factory_ime,
#endif
#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
	mmi_setting_restore_java_data,
#endif /* !defined(MMI_ON_WIN32) && defined(__J2ME__) */
#ifdef OPERA_BROWSER
	mmi_restore_full_html_browser,
#endif
#ifdef WAP_SUPPORT
	mmi_restore_send_msg_to_wap,
#endif /* WAP_SUPPORT */
#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
	mmi_restore_mre_app_uninstall,
#endif
	mmi_restore_reset_date_time,
	mmi_restore_app_reboot,
};

/***************************************************************************** 
* local define
*****************************************************************************/
#define MMI_RESTORE_APP_ITEM (sizeof(mmi_restore_app_table) / sizeof(srv_restore_table_struct))

/*****************************************************************************
 * FUNCTION
 *  HighlightRstScr
 * DESCRIPTION
 *  This function is Highlight handler for  "Restore"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRstScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* Register function for left/right soft key */
#ifdef __MTK_TARGET__
    SetLeftSoftkeyFunction(EntryRstScr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryRstScr, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
#endif 
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRstScr
 * DESCRIPTION
 *  This function is Entry function for "Restore"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phnset_entry_group_check_ex(NULL,GRP_ID_PHNSET_RESTORE))
        return;
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHNSET_RESTORE,
        mmi_restore_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_restore_entry_restore_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_restore_proc
 * DESCRIPTION
 *  Proc function for restore 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_restore_proc(mmi_event_struct *param)
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
            RstStartRestore();
            break;
            
        case MMI_ALERT_CNFM_NO:    		
            mmi_frm_group_close(GRP_ID_PHNSET_RESTORE);
    		break;
            
    	default:
    		break;
    	}
        break;
    }
  #ifdef __MMI_TELEPHONY_SUPPORT__
    case EVT_ID_CUI_VERIFY_RESULT:
	{
	    cui_verify_result_evt_struct* phone_lock_evt = (cui_verify_result_evt_struct*)param;
        if (phone_lock_evt->success)
	{
    	    EntryRstConfirm();
    	}
        else
    	{
            mmi_frm_group_close(GRP_ID_PHNSET_RESTORE);
    	}
        break;            
	}

    case EVT_ID_CUI_VERIFY_CANCEL:
	{
        mmi_frm_group_close(GRP_ID_PHNSET_RESTORE);
        break;
    }
  #endif/* __MMI_TELEPHONY_SUPPORT__*/
	default:
		break;
	}
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_restore_entry_restore_screen
 * DESCRIPTION
 *  Entry restore screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_restore_entry_restore_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
#if 0
/* under construction !*/
#ifdef __HALF_SECURE_RESTORE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __HALF_SECURE_RESTORE__ */ /* Check phone lock code before restore default */
/* under construction !*/
#endif /* __HALF_SECURE_RESTORE__ */ 
#else

	mmi_restore_entry_check_phone_lock();
#endif

#else /* __MMI_TELEPHONY_SUPPORT__*/ 
    EntryRstConfirm();
#endif /* __MMI_TELEPHONY_SUPPORT__ */ 

}
 
#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_entry_check_phone_lock
 * DESCRIPTION
 *  Entry check phone lock CUI 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_restore_entry_check_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id phone_lock_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone_lock_cui_gid = cui_verify_create(GRP_ID_PHNSET_RESTORE, CUI_VERIFY_TYPE_PHONE_PASSWORD);
    cui_verify_run(phone_lock_cui_gid);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  EntryRstConfirm
 * DESCRIPTION
 *  This function is left softkey handler for Yes to reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
	mmi_ucm_app_entry_error_message();
		if (mmi_frm_group_is_present(GRP_ID_PHNSET_RESTORE))
		{
			mmi_frm_group_close(GRP_ID_PHNSET_RESTORE); 
		}
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.callback = NULL;
    confirm_arg.parent_id = GRP_ID_PHNSET_RESTORE;
#ifdef __MMI_MAINLCD_240X320__
    confirm_arg.f_msg_icon = 0;
#endif
    
#if !defined(__MTK_TARGET__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else /* !defined(__MTK_TARGET__) */ 
    mmi_confirm_display_ext(
        STR_SETTING_RESTORE_CONFIRM,
		MMI_EVENT_QUERY,
        &confirm_arg);    
#endif /* !defined(__MTK_TARGET__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  EntryRstRestoreProcessing
 * DESCRIPTION
 *  This function is Entry function to display restore processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryRstRestoreProcessing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_RST_PROCESSING);

    /* Call Exit Handler */
    if (mmi_frm_scrn_enter(
        GRP_ID_PHNSET_RESTORE,
        SCR_RESTORE_PROCESSING,
        NULL,
        EntryRstRestoreProcessing,
        MMI_FRM_FULL_SCRN))
	{
    ShowCategory66Screen(
        STR_ID_RESTORE_TITLE,
        GetRootTitleIcon(MENU_SETTING_RESTORE),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_SETTING_RESTORE_PROCESSING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    //SetKeyHandler(MMI_dummy_function, KEY_END, KEY_LONG_PRESS);
	SetKeyUpHandler(MMI_dummy_function, KEY_END);
	SetKeyDownHandler(MMI_dummy_function, KEY_END);
	SetKeyLongpressHandler(MMI_dummy_function, KEY_END);
}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_app_data
 * DESCRIPTION
 *  This function is to restore application data and NVRAM
 * PARAMETERS
 *  app_id : [IN] application index to restore         
 * RETURNS
 *  0 : fail
 *  1 : success
 *****************************************************************************/
U8 mmi_restore_app_data(U16 app_id, FuncPtr callback)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if (app_id == APP_RESTORE)
        {
		MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RESTORE_TRACE_001);		
            mmi_frm_reset_record(NVRAM_RESET_FACTORY, (U16)app_id, 0, 0, 0);
		srv_restore_start(mmi_restore_app_table, NULL);
        }
        else
        {
		MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RESTORE_TRACE_002);
        mmi_frm_reset_record(NVRAM_RESET_CERTAIN, (U16)app_id, 0, 0, 0);
    }
	return 1;

}


/*****************************************************************************
 * FUNCTION
 *  RstStartRestore
 * DESCRIPTION
 *  This function is left soft key function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RstStartRestore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_restore_is_processing_flag = MMI_TRUE;
    EntryRstRestoreProcessing();

#ifdef __J2ME__
    mmi_java_is_allow_stopped_popup_display(MMI_FALSE);
#endif
    
	mmi_restore_app_data(APP_RESTORE, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_restore_send_msg_to_wap
 * DESCRIPTION
 *  This function is to send  MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_send_msg_to_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetProtocolEventHandler(mmi_restore_app_callback_msg_rsp, MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF);
    mmi_frm_send_ilm(MOD_WAP, MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ, NULL, NULL);
	return SRV_RESTORE_HOLD;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_reset_date_time
 * DESCRIPTION
 *  This function is to reset date and time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_reset_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_eq_set_rtc_time_req_struct *time;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	SetProtocolEventHandler(mmi_restore_app_callback_msg_rsp, HW_SET_TIME_REQ_SUCCESS);
    time = OslAllocDataPtr(mmi_eq_set_rtc_time_req_struct);
    
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = 0;
    time->info.data_time.rtc_min = 0;
    time->info.data_time.rtc_hour = 0;
	
    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = 1;
    time->info.data_time.rtc_mon = 1;
    time->info.data_time.rtc_wday = DOW(2004,1,1);
    time->info.data_time.rtc_year = 4; 
    mmi_frm_send_ilm(MOD_L4C, HW_SET_TIME_REQ, (oslParaType*)time, NULL);
	return SRV_RESTORE_HOLD;
}


#if !defined(MMI_ON_WIN32) && defined(__J2ME__)

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_restore_java_data
 * DESCRIPTION
 *  This function is call restore function of java application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_setting_restore_java_data(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_java_send_restore_factory_mode_req((FuncPtr)mmi_restore_app_callback_msg_rsp);
	return SRV_RESTORE_HOLD;
}
#endif /* #if !defined(MMI_ON_WIN32) && defined(__J2ME__) */

#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_mre_app_uninstall
 * DESCRIPTION
 *  This function is call restore function of mre application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_mre_app_uninstall(void)
{
	srv_mre_appmgr_preinstall_tcard_app_uninstall();
	return SRV_RESTORE_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_reset_app_status
 * DESCRIPTION
 *  This function is start to restore settings to factory default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_reset_app_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add alarm deinit function for shutdown crash */
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RESTORE_TRACE_003);
	srv_reminder_deinit();

#ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RESTORE_TRACE_005);
    mmi_syncml_restore_factory_default();
#endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */

#ifdef __MMI_THEMES_V2_SUPPORT__
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RESTORE_TRACE_006);
    ActivateDefaultTheme();
#endif /* __MMI_THEMES_V2_SUPPORT__ */

#ifdef __MMI_USB_SUPPORT__
    ClearProtocolEventHandler(PRT_EQ_USB_DETECT_IND);
    ClearProtocolEventHandler(PRT_BATTERY_STATUS_IND);
#endif 
	return SRV_RESTORE_OK;
}

#if defined(__MMI_IME_PLUG_IN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_factory_ime
 * DESCRIPTION
 *  Send ime msg to plug in 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_factory_ime(void)
{
    /* inform vendor to rest ime to factory setting*/
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_RESTOR_FACTRORY_SETTING, 0, 0);
	return SRV_RESTORE_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_detach_network
 * DESCRIPTION
 *  Detach network befor reboot 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_detach_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* Detach network */
	SetProtocolEventHandler(mmi_restore_app_callback_msg_rsp, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    mmi_frm_send_ilm((oslModuleType)mmi_restore_dest_mod, MSG_ID_MMI_NW_PWROFF_DETACH_REQ, NULL, NULL);
    mmi_restore_dest_mod++;
	return SRV_RESTORE_HOLD;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if 0
#ifdef __MMI_SCREEN_SAVER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_LCD_PARTIAL_ON__) && defined(__MMI_LCD_PARTIAL_ON_ENABLED__)
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
#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  RstGetWallpaperImgIdDefault
 * DESCRIPTION
 *  This function is to get wallpaper image id default value
 * PARAMETERS
 *  void
 * RETURNS
 *  Image ID
 *****************************************************************************/
U16 RstGetWallpaperImgIdDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gWallPaperId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive value for wall paper id from nvram */
    mmi_dispchar_get_img_id(RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER, &(gWallPaperId));
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_RST_WP_IMAGE_ID, gWallPaperId);

    /* return default value for wall paper id */
    return gWallPaperId;
}
#if 0
#ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUB_WALLPAPER__ */ 
#endif

/*****************************************************************************
 * FUNCTION
 *  ATRstFactoryDefault
 * DESCRIPTION
 *  AT command restore factory default
 * PARAMETERS
 *  ind     [?]     
 *  in    msg      no action(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHNSET_AT_DISABLE__
void ATRstFactoryDefault(void *ind, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR password[16];
    mmi_factory_restore_req_ind_struct *msg = (mmi_factory_restore_req_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{	
		mmi_at_general_res_req_struct *rsp_msg;
		
		rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
		
		rsp_msg->result = MMI_FALSE;
		
		mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp_msg, NULL);
		return;
	}
    src_mod_id = mod_id;
    mmi_asc_n_to_ucs2((CHAR*)password, (CHAR*)msg->pwd, 16);


    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "ATRstFactoryDefault()");    
#ifdef __MMI_TELEPHONY_SUPPORT__
    srv_secset_verify_phone_password((const WCHAR*)password, mmi_restore_verify_phone_password_proc, NULL);
#endif
}
#endif

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_verify_phone_password_proc
 * DESCRIPTION
 *  Proc function for verify phone password from AT 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_restore_verify_phone_password_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT)
	{
	    srv_secset_verify_phone_password_result_evt_struct *verify_evet = (srv_secset_verify_phone_password_result_evt_struct*)evt;
        ATRstConfirm(verify_evet->success);
        return MMI_RET_OK;
	}
	    return MMI_RET_DONT_CARE;
}
#endif
 

/*****************************************************************************
 * FUNCTION
 *  ATRstConfirm
 * DESCRIPTION
 *  This function is to handle AT command restore factory default
 *  Following functions: RstStartRestore
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void ATRstConfirm(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "ATRstConfirm(%d)", result);    
    if (result)
    {
        rsp_msg->result = MMI_TRUE;
        RstStartRestore();
    }
    else
    {
        rsp_msg->result = MMI_FALSE;
    }

    mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp_msg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_get_current_restore_status
 * DESCRIPTION
 * get current restore status.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS 
 *  g_restore_is_processing_flag 1:processing; 0:none
 *****************************************************************************/
U8 mmi_get_current_restore_status(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return g_restore_is_processing_flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_app_callback_msg_rsp
 * DESCRIPTION
 *  This function is to receive message response
 *  Functionality:
 * PARAMETERS
 *  app_id : [IN] check app_id restore or not         
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_restore_app_callback_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RST_SRV_TRACE_005);
	srv_restore_process_callback();
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_restore_app_reboot
 * DESCRIPTION
 *  This function is to reboot mobile
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_app_reboot(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	extern mmi_ret srv_reminder_on_time_change_notify(mmi_event_struct *evt);
	MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_RST_SRV_TRACE_009);
    srv_reminder_on_time_change_notify(NULL);
	AlmATPowerReset(MMI_FALSE, 3);
	return SRV_RESTORE_HOLD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_restore_stop_audio_play
 * DESCRIPTION
 *  Stop audio play 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_stop_audio_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
	return SRV_RESTORE_OK;
}

#ifdef OPERA_BROWSER
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_full_html_browser
 * DESCRIPTION
 *  This function is to send MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_restore_result_enum mmi_restore_full_html_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	SetProtocolEventHandler(mmi_restore_app_callback_msg_rsp, MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_CNF);
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_REQ, NULL, NULL);
	return SRV_RESTORE_HOLD;
}
#endif /* OPERA_BROWSER */

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_restore_notify_screen_lock_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret mmi_restore_notify_screen_lock_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING &&
		g_restore_is_processing_flag == 1)
    {
    	if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
		{
			srv_backlight_all_lcd_off();
			return MMI_RET_ERR;
		}
		else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
		{
			return MMI_RET_ERR;
		}
    }
    return MMI_RET_OK;
}
#endif /* #ifdef __MMI_SCREEN_LOCK_ANY_TIME__ */


