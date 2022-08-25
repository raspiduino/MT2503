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
 * PoweronCharger.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Power On when Charger connects 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 
#include "AllAppGprot.h"
#include "ShutdownSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "ProtocolEvents.h"
#include "PowerOnChargerProt.h"
#include "GpioSrvGprot.h"
#include "SettingGprots.h"
#include "AlarmFrameWorkProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __MMI_USB_SUPPORT__ */ 


#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) 
#include "UcAppGprot.h"
#endif

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIThemes.h"
#endif 

#if defined(__DM_LAWMO_SUPPORT__)
#include "dmuigprot.h"
#endif

#include "datetimetype.h"
#include "app_datetime.h"
#include "Custom_events_notify.h"

#include "UcmSrvGprot.h"

#include "ProfilesSrvGProt.h"
#include "CharBatSrvGprot.h"
#include "CharBatSrvProt.h"

/* auto add by kw_check begin */

#include "device.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "CustDataRes.h"
#include "mmi_rp_app_charger_def.h"
#include "AlertScreen.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gdi_include.h"
#include "mdi_audio.h"
#include "PixcomFontEngine.h"
#include "stack_msgs.h"
#include "custom_led_patterns.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"
#include "NotificationGprot.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_history_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_res_range_def.h"
/* auto add by kw_check end */

/***************************************************************************** 
* Global Variable
*****************************************************************************/
charbat_context_struct g_charbat_context = 
{
    0,                  /* g_charbat_context.PowerOnCharger */
    0,                  /* g_charbat_context.PowerOnChargingPeriod */
    0,                  /* g_charbat_context.ChargingAbnormal */
    0,                  /* g_charbat_context.ChargingComplete */
    0,                  /* g_charbat_context.LowBatteryFlag */
    0,                  /* g_charbat_context.LowBatteryTxProhibitFlag */
    BATTERY_LEVEL_0,    /* g_charbat_context.chargerLevel */
    PMIC_VBAT_STATUS,   /* g_charbat_context.batteryStatus */
    0,                  /* g_charbat_context.isChargerConnected */
    0,                  /* g_charbat_context.LowBatteryCutOffCallCnt */
    0                   /* g_charbat_context.BatteryNotifyModId */    
};

static U8 g_usb_popup_show = 0;
#ifdef __MMI_BTBOX_NOLCD__
MMI_BOOL is_charger_in = MMI_FALSE;
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_BOOL mmi_devmgr_is_charging = MMI_FALSE;
static U16 g_abnormal_id;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_charger_check_low_power_off(S32 battery_level);
#ifdef __MMI_BTBOX_NOLCD__
static void mmi_charger_check_low_battery(S32 battery_level);
#endif
static void mmi_charger_clear_usb_popup_show(void);
static void ShowChargingScr(void);
static void ShowChargingCompleteScr(void);
static void ExitAbnormalBatteryIndPopup(void);
static void LowBatteryShutDownScrTimeout(void);
static void AbnormalBatteryIndPopup(void);
static void ChargerDetectTimeoutHdlr(void);

#ifdef __MMI_SUBLCD__
static void ShowSubLCDAbnormalPopup(void);
static void ShowSubLCDChargingCompleteScr(void);
static void ExitSubLCDChargingCompleteScr(void);
static void ShowSubLCDChargingScr(void);
static void ExitSubLCDChargingScr(void);
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void InitFramework(void);
extern void InitHardwareEvents(void);
extern void ShowUsbChgCmpltScr(void);
extern void DeInitFramework_KeyAndEventHandler(void);


#ifdef __CLASSAB_VOLUME_PROTECTION__ 
#include "med_struct.h"
//#include "med_sap.h"
static void mmi_charbat_save_pwr_popup(void *info)
{   
    l4audio_batt_state_ind_struct *p = (l4audio_batt_state_ind_struct *)info;

    if (p->is_battery_low)
        BatteryIndicationPopup(STR_BATTERY_SAVE_POWER_ON);
    else
        BatteryIndicationPopup(STR_BATTERY_SAVE_POWER_OFF);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_charger_enable_charging_icon
 * DESCRIPTION
 *  GPIO_DETECT_IND arrives before POWER_ON_IND. But framework is initialized
 *  by POWER_ON_IND and the charging animation can not be set at the time.
 *  After framework initialized, this proc will be executed afterward. By
 *  determine charger state to enable the animation.
 * PARAMETERS
 *  evt     [IN] mmi_bootup_early_init_evt_struct*
 * RETURNS
 *  MMI_RET_OK to continue event routing
 *****************************************************************************/
mmi_ret mmi_charger_enable_charging_icon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_charbat_is_charging())
    {
        IdleScreenChargerConnected(KAL_FALSE);
    }
#ifdef __CLASSAB_VOLUME_PROTECTION__
    SetProtocolEventHandler(mmi_charbat_save_pwr_popup, MSG_ID_L4AUD_BATTERY_STATE_IND);
#endif
    return MMI_RET_OK;
}


void mmi_charbat_update_status_icon(void)
{
    mmi_charger_enable_charging_icon(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  PreChargeEnd
 * DESCRIPTION
 *  Leave pre-charge stage.
 * PARAMETERS
 *  msg     [IN]        Leaving pre-charge indication
 * RETURNS
 *  void
 *****************************************************************************/
static void PreChargeEnd(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  PreChrKeyPadDummyHdlr
 * DESCRIPTION
 *  Keypad dummy function when pre-charge stage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PreChrKeyPadDummyHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__IOT__)
    mmi_popup_display_simple((WCHAR*)GetString(STR_LOW_BATTERY), MMI_EVENT_WARNING, GRP_ID_CHARGER_ROOT, NULL);
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitializeChargingScr
 * DESCRIPTION
 *  Initialization for power on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_PWRON_CHARGE_INIT);
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    InitUnicodeSupport();
#endif

    gdi_init();

    srv_gpio_setting_init();

#if !defined(__MMI_BTBOX_NOLCD__)
    srv_backlight_init_context_early();
#endif
    srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
#ifdef __MMI_USB_SUPPORT__
#if !defined(__IOT__)
    InitMMIUsbContext();
#else
    srv_usb_init_context();
#endif
#endif 
#ifdef __MMI_WEBCAM__
    mmi_webcam_init_context();
#endif

#if !defined(__IOT__)
    mdi_audio_init();
    mmi_fe_init();   
#endif

    InitFramework();

    InitHardwareEvents();
    InitTime();
#if !defined(__IOT__)
    setup_UI_wrappers();
#endif
    PopulateResData();
#if !defined(__IOT__)
    initialize_UI_demo();
#endif
#if !defined(__MMI_BTBOX_NOLCD__)
	ShowChargingScr();
#endif
    
    /* Precharge Power On */
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_PRECHARGE)
    {
        SetProtocolEventHandler(PreChargeEnd, MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND);
    }

#if !defined(__MMI_BTBOX_NOLCD__)
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
#endif
#if !defined(__IOT__)
    srv_prof_init();
    InitSettingNVRAM();
#endif

    srv_reminder_init(NULL);
#ifdef __MMI_THEMES_APPLICATION__
    InitThemes();
#endif /* __MMI_THEMES_APPLICATION__ */

#if !defined(__MMI_BTBOX_NOLCD__)
    srv_led_pattern_start_charging();
#endif
    g_charbat_context.PowerOnCharger = 1;
    InitChargerPwrOn();
    /* To wake up pending alarm */
#if !defined(__IOT__)
    PendingAlarmReminder();
#endif
}

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)

/*****************************************************************************
 * FUNCTION
 *  ShowChargingScr
 * DESCRIPTION
 *  Show charging screen when phone bootup bcos of charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowChargingScr_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_CHARGER_ROOT, SCR_CHARGER_POWER_ON, NULL, ShowChargingScr_int, MMI_FRM_UNKNOW_SCRN))
        return;
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_PWRON_CHARGE_SCREEN, srv_bootup_get_booting_mode());
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    entry_full_screen();

    wgui_cat9002_show(IMG_ID_CHARGER_CHARGING,0,NULL,0);
	
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_PRECHARGE)
    {        
        if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
        {
            SetKeyLongpressHandler(PreChrKeyPadDummyHdlr, KEY_POWER); 
        }
        else
        {
            SetKeyLongpressHandler(PreChrKeyPadDummyHdlr, KEY_END);
        }           
        SetProtocolEventHandler(PreChargeEnd, MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND);
    }
    else
    {
        if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
        {
            SetKeyLongpressHandler(ChargingPwnOnThanPwnOn, KEY_POWER); 
        }
        else
        {
            SetKeyLongpressHandler(ChargingPwnOnThanPwnOn, KEY_END);
        }                   
    }

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(ShowSubLCDChargingScr);
#endif

}
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/

/*****************************************************************************
 * FUNCTION
 *  ShowChargingScr
 * DESCRIPTION
 *  Show charging screen when phone bootup bcos of charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CHARGER_ROOT, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    ShowChargingScr_int();
}


#ifdef __MMI_SUBLCD__

MMI_BOOL mmi_charbat_show_sublcd_battery_status_icon(void)
{
    if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL) ||
        (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM) ||
        ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_INVALID) &&
         ((uem_get_power_on_mode() == POWER_ON_KEYPAD) ||
          (uem_get_power_on_mode() == POWER_ON_ALARM))))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDChargingScr
 * DESCRIPTION
 *  Show power on charging screen on SUBLCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowSubLCDChargingScr(void)
{
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clam_is_close())
    {
        ExecSubLCDCurrExitHandler();
        ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
        SetSubLCDExitHandler(ExitSubLCDChargingScr);
    }
    else
    {
        ExecSubLCDCurrExitHandler();
        ShowCategory304Screen(IMG_SUBLCD_CHARGER_POWER_ON, 0);
        SetSubLCDExitHandler(ExitSubLCDChargingScr);
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUBLCD_CHARGER_POWER_ON, 0);
    SetSubLCDExitHandler(ExitSubLCDChargingScr);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDChargingScr
 * DESCRIPTION
 *  Exit power on charging screen from sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitSubLCDChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDChargingScr;
    AddSubLCDHistory(&SubLCDHistory);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  InitChargerPwrOn
 * DESCRIPTION
 *  Initialise protocol handlers for power on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitChargerPwrOn()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_charbat_init_event_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  ChargingPwnOnThanPwnOn
 * DESCRIPTION
 *  Fn to be called to power on the phone for long press of End key during power
 *  on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChargingPwnOnThanPwnOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_power_on_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_CHARGER_ROOT, GLOBAL_SCR_DUMMY, NULL, ChargingPwnOnThanPwnOn, MMI_FRM_FG_ONLY_SCRN))
        return;

    mmi_frm_scrn_close(GRP_ID_CHARGER_ROOT, SCR_CHARGING_COMPLETE);
    mmi_frm_scrn_close(GRP_ID_CHARGER_ROOT, SCR_CHARGER_POWER_ON);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

//#if defined(__MMI_SUBLCD__)
//    lcd_power_on(SUB_LCD, KAL_FALSE);
//#endif 

    
    myMsgPtr = (mmi_eq_power_on_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_power_on_req_struct));
    myMsgPtr->fun = ALARM_RESET;
    myMsgPtr->rst = 0;
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_POWERKEY_ON);

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_ON_REQ, 
                    (oslParaType*) myMsgPtr, NULL);

    g_charbat_context.PowerOnCharger = 0;
}


/*****************************************************************************
 * FUNCTION
 *  BatteryStatusRsp
 * DESCRIPTION
 *  Call back function for battery status indication.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryStatusRsp(void *info)
{
    srv_charbat_status_ind_hdlr(info);
}


#if defined(__IOT__)
U8 AlmIsRTCPwron(void)
{
    srv_bootup_mode_enum mode;
    
    mode = srv_bootup_get_booting_mode();

    return ((mode == SRV_BOOTUP_MODE_ALARM) ? 1 : 0);
}

MMI_BOOL mmi_alm_is_in_alarm(void)
{
    return MMI_FALSE;
}
#endif

#if !defined(__MMI_BTBOX_NOLCD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_charbat_main_evt_hdlr
 * DESCRIPTION
 *  Call back function for battery status indication.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_charbat_main_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    srv_charbat_evt_notify_struct *p = (srv_charbat_evt_notify_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_MAIN_EVT_HDLR, p->status, p->battery_level);
    g_charbat_context.batteryStatus = p->status;

    switch (p->status)
    {
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_CHARGER_IN:
            string_id = STR_USB_CHARGER_CONNECTED;
            /* PASS */
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_IN:
        {
            if (!string_id)
            {
                string_id = STR_CHARGER_CONNECTED;
            }
            mmi_devmgr_is_charging = MMI_TRUE;
            g_charbat_context.isChargerConnected = 1;
            mmi_charger_clear_usb_popup_show();
            
        #if defined(__MMI_USB_SUPPORT__) && !defined(__IOT__)
            mmi_usb_set_background_still(MMI_FALSE);
        #endif 

                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
                
                if (srv_bootup_is_booting())
                {
                    IdleScreenChargerConnected(KAL_TRUE);
                }
                else
                {
                    g_charbat_context.ChargingComplete = 0; /* To prevent reentrence of charging complete screen */
                    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

                    if (!g_charbat_context.PowerOnCharger)
                    {
                        BatteryIndicationPopup(string_id);
                    }
                    IdleScreenChargerConnected(KAL_FALSE);
                }
            break;
        }
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_IN:
        {
            g_charbat_context.isChargerConnected = 1;
        #if defined(__MMI_USB_SUPPORT__) && !defined(__IOT__)
            mmi_usb_set_background_still(MMI_TRUE);
        #endif
            mmi_devmgr_is_charging = MMI_FALSE;
            mmi_charger_clear_usb_popup_show();
            
            if (!srv_bootup_is_launched())
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_NO_CHARGER_IN_BEFORE_POWER_ON_IND);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
                
                if (srv_bootup_is_booting())
                {
                    IdleScreenChargerDisconnected();
                }
                else
                {
                    g_charbat_context.ChargingComplete = 0; /* To prevent reentrence of charging complete screen */
                    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

                    if (!g_charbat_context.PowerOnCharger)
                    {
                        IdleScreenChargerDisconnected();
                    }
                }
            }   
            break;
        }
    #endif /* MMI_USB_SUPPORT */
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:
            string_id = STR_USB_CHARGER_REMOVED;
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_OUT:
        {
            if (!string_id)
            {
                string_id = STR_CHARGER_REMOVED;
            }
            g_charbat_context.ChargingComplete = 0; /* to prevent reentrence of charging complete screen */
            g_charbat_context.isChargerConnected = 0;
            mmi_devmgr_is_charging = MMI_FALSE;

        #if defined(__MMI_USB_SUPPORT__) && !defined(__IOT__)
            mmi_usb_set_background_still(MMI_TRUE);
        #endif 

            if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL &&
                !srv_bootup_is_launched())
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_OUT_BEFORE_POWER_ON_IND);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
                
                srv_led_pattern_stop_battery_warning();
                if (g_charbat_context.PowerOnCharger &&
                    mmi_alm_is_in_alarm() == 0 && srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_USB)
                {
                    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_OFF_REQ, 
                        NULL, NULL);
                }
                else if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM &&
                		 mmi_alm_is_in_alarm() == 0)
                {
                    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_OFF_REQ, 
                           NULL, NULL);
                }
                else if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_USB) /* Don't turn on backlight & pop up screen in USB power on mode */
                {
                        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
                    #ifdef __MMI_USB_SUPPORT__
                        /* check is in mass storage mode */
                        if (
                    #ifdef __USB_IN_NORMAL_MODE__
                    		!srv_usb_is_in_mass_storage_mode() &&
                    #endif
                            (srv_usb_get_status() != SRV_USBSTATUS_PICTBRIGE) &&
                            !srv_usb_is_connected() /* to prevent popup twice */
                           )
                    #endif
                        {
                            if (p->status == PMIC_CHARGER_OUT)
                            {
                                /* not in mass storage, can show the plug-out prompt */                        
                                BatteryIndicationPopup(string_id);
                            }
                            else
                            {
                                BatteryIndicationPopupEx(string_id);
                            }
                        }
                    mmi_frm_scrn_close(GRP_ID_CHARGER_ROOT, SCR_CHARGER_POWER_ON);
                    srv_led_pattern_stop_charging();

                    if (g_charbat_context.ChargingAbnormal)
                    {
                        g_charbat_context.ChargingAbnormal = 0;
                    }
                }
                
                IdleScreenChargerDisconnected();
            }
            g_charbat_context.PowerOnCharger = 0;

            break;
        }

        case PMIC_CHARGE_COMPLETE:  /* battery full charged. */
        {
            g_charbat_context.chargerLevel = BATTERY_LEVEL_3;

         MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_get_booting_mode(), g_charbat_context.PowerOnCharger);
        
                if (g_charbat_context.PowerOnCharger)
                {
                    if (srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE) == MMI_FALSE && (AlmIsRTCPwron() == 0))
                    {
                        srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);
                    #ifdef __MMI_USB_SUPPORT__
                        if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_USB)
                        {
                        #if !defined(__IOT__)
                            ShowUsbChgCmpltScr();
                        #endif
                        }
                        else
                    #endif /* __MMI_USB_SUPPORT__ */ 
                        {
                        #if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
                            ShowChargingCompleteScr();
                            srv_led_pattern_start_full_charging();
                            IdleScreenBatteryFullCharged();
                        #else
                            srv_led_pattern_start_full_charging();
                        #endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
                        }
                    }
                }

                    g_charbat_context.ChargingComplete = 1;
                #ifdef __MMI_LED_POWERON_CHARGEFULL__
                    srv_led_pattern_start_full_charging();
                #endif /* __MMI_LED_POWERON_CHARGEFULL__ */ 
                    IdleScreenBatteryFullCharged();
            break;
        }

        case PMIC_VBAT_STATUS:
        {
            g_charbat_context.chargerLevel = p->battery_level;

            mmi_charger_check_low_power_off(p->battery_level);
            BatteryStatusIndication(p->battery_level);
            break;
        }

        case PMIC_OVERVOLPROTECT:
        case PMIC_OVERCHARGECURRENT:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_INVALID_CHARGER:
        case PMIC_LOWCHARGECURRENT:
        case PMIC_CHARGE_BAD_CONTACT:
        {
            ChargingAbnormalHandler(STR_ID_CHARGER_CHARGING_ERROR);
            break;
        }

        case PMIC_OVERBATTEMP:
        case PMIC_INVALID_BATTERY:
        case PMIC_LOWBATTEMP:
        case PMIC_BATTERY_BAD_CONTACT:
        {
            ChargingAbnormalHandler(STR_ID_CHARGER_BATTERY_ERROR);
            break;
        }

        default:
            break;
    }
	return MMI_RET_OK;
}
#else
mmi_ret mmi_charbat_main_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    srv_charbat_evt_notify_struct *p = (srv_charbat_evt_notify_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_MAIN_EVT_HDLR, p->status, p->battery_level);
    g_charbat_context.batteryStatus = p->status;

    switch (p->status)
    {
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_CHARGER_IN:
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_IN:
        {

            mmi_devmgr_is_charging = MMI_TRUE;
            g_charbat_context.isChargerConnected = 1;
            is_charger_in = MMI_TRUE;

                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
                
		    if (!srv_bootup_is_booting())
			{
	            g_charbat_context.ChargingComplete = 0; 
			}
			mmi_frm_input_event_notify_remove(BTBOX_CHARGER_OUT, NULL);
		//	mmi_frm_input_event_notify_remove(BTBOX_CHARGER_LOW_WARNING, NULL);
			mmi_frm_input_event_notify(BTBOX_CHARGER_IN, NULL);
            break;
        }
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_IN:
        {
            g_charbat_context.isChargerConnected = 1;
          
            is_charger_in = MMI_TRUE;
            mmi_devmgr_is_charging = MMI_FALSE;
            
            
            if (!srv_bootup_is_launched())
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_NO_CHARGER_IN_BEFORE_POWER_ON_IND);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
                
                if (!srv_bootup_is_booting())
                {
                    g_charbat_context.ChargingComplete = 0; /* To prevent reentrence of charging complete screen */

                }
            }   
         /*  mmi_frm_input_event_notify(BTBOX_CHARGER_IN, NULL);*/
            break;
        }
    #endif /* MMI_USB_SUPPORT */
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_OUT:
			break;
        case PMIC_USB_CHARGER_OUT:
         
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_OUT:
        {
         
            g_charbat_context.ChargingComplete = 0; /* to prevent reentrence of charging complete screen */
            g_charbat_context.isChargerConnected = 0;
            mmi_devmgr_is_charging = MMI_FALSE;
            if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL &&
                !srv_bootup_is_launched())
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_OUT_BEFORE_POWER_ON_IND);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_is_booting(), g_charbat_context.PowerOnCharger);
               
                if (g_charbat_context.PowerOnCharger && srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_USB)
                {
                    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_OFF_REQ, 
                        NULL, NULL);
                }
                else if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_USB) /* Don't turn on backlight & pop up screen in USB power on mode */
                {

                    if (g_charbat_context.ChargingAbnormal)
                    {
                        g_charbat_context.ChargingAbnormal = 0;
                    }
                }
                
            }
		  
            g_charbat_context.PowerOnCharger = 0;
		
			mmi_frm_input_event_notify_remove(BTBOX_CHARGER_COMPLETE, NULL);
			mmi_frm_input_event_notify_remove(BTBOX_CHARGER_IN, NULL);
			if(p->battery_level>BATTERY_LOW_WARNING)
            {
				mmi_frm_input_event_notify_remove(BTBOX_CHARGER_LOW_WARNING, NULL);
			}
            mmi_frm_input_event_notify(BTBOX_CHARGER_OUT, NULL);
            break;
        }

        case PMIC_CHARGE_COMPLETE:  /* battery full charged. */
        {
            g_charbat_context.chargerLevel = BATTERY_LEVEL_3;

         MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_AFTER_POWER_ON, 
                    srv_bootup_get_booting_mode(), g_charbat_context.PowerOnCharger);
        
                if (g_charbat_context.PowerOnCharger)
                {
                    if (srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE) == MMI_FALSE && (AlmIsRTCPwron() == 0))
                    {
                        srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);
					
                    }
                }

                    g_charbat_context.ChargingComplete = 1;

			mmi_frm_input_event_notify_remove(BTBOX_CHARGER_IN, NULL); 
			mmi_frm_input_event_notify(BTBOX_CHARGER_COMPLETE, NULL);
            break;
        }

        case PMIC_VBAT_STATUS:
        {
            g_charbat_context.chargerLevel = p->battery_level;

			if(g_charbat_context.isChargerConnected==0 && is_charger_in == MMI_TRUE)
			{
                mmi_frm_input_event_notify_remove(BTBOX_CHARGER_IN, NULL); 
				is_charger_in = MMI_FALSE;
			}
			if(p->battery_level<BATTERY_LEVEL_0)
            {
                mmi_charger_check_low_battery(p->battery_level);
            }else{
               
			    batteryLowCount = 0; 
			    lowBatteryAlarmThreshold = 0; 
			    srv_charbat_set_low_bat_flag(MMI_FALSE);			    
				mmi_frm_input_event_notify_remove(BTBOX_CHARGER_LOW_WARNING, NULL);
			}
            break;
        }

        case PMIC_OVERVOLPROTECT:
        case PMIC_OVERCHARGECURRENT:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_INVALID_CHARGER:
        case PMIC_LOWCHARGECURRENT:
        case PMIC_CHARGE_BAD_CONTACT:
        case PMIC_OVERBATTEMP:
        case PMIC_INVALID_BATTERY:
        case PMIC_LOWBATTEMP:
        case PMIC_BATTERY_BAD_CONTACT:
        default:
            break;
    }
	return MMI_RET_OK;
}

#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/

mmi_ret mmi_charbat_other_evt_hdlr(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER:
        {
            BatteryIndicationPopup(STR_LOW_BATTERY);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


void LowBatteryCommonAction(void) // will be phase out
{
    // please refer srv_charbat_low_battery_common_action();
}

#if !defined(__MMI_BTBOX_NOLCD__)	

/* battery is too low, if not connect charger,USB, will power off */
static void mmi_charger_check_low_power_off(S32 battery_level)
{
    if (BATTERY_LOW_POWEROFF != battery_level)
        return;
    
    if (!srv_charbat_is_charging() && !srv_bootup_is_booting())
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_LOW_BATTERY_POWER_OFF);
    #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))                
        mmi_uc_battery_low_callback();
    #endif                
        ShowLowPowerShutdownScr();
    }
}
#endif
#ifdef __MMI_BTBOX_NOLCD__
static void mmi_charger_check_low_battery(S32 battery_level)
{

      
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, 
        TRC_MMI_GPIO_PMIC_LOW_BATTERY_HANDLER, 
        lowBatteryAlarmThreshold, 
        batteryLowCount, 
        srv_charbat_is_low_battery(),
        srv_charbat_check_if_mo_allow());
    
    switch (battery_level)
    {
        case BATTERY_LOW_POWEROFF: 
        {       
			   #if 1      	    
			    if (!srv_charbat_is_charging() && !srv_bootup_is_booting())
			    {
				
				
				

                    srv_shutdown_normal_start(APP_CHARGER);   
			    }

				if(srv_charbat_is_charging())
				{
		              /*low battery , but it is charging.*/                         
		              kal_prompt_trace(MOD_MMI,"[charger]low power off but charging.");	  
				}
			    #endif
				
            break;
        }
        
        case BATTERY_LOW_TX_PROHIBIT:
		case BATTERY_LOW_WARNING:
        {

	            srv_charbat_set_low_bat_threshold(5);					
						
	            srv_charbat_set_low_bat_flag(MMI_TRUE);

			   if (srv_bootup_is_booting())
	           {
	                srv_charbat_reset_low_bat_cnt();
	           }
	           else if(!srv_charbat_is_charging() && batteryLowCount >= lowBatteryAlarmThreshold)
	           {
				            batteryLowCount = 0;
						
							/*notify low warning*/
							kal_prompt_trace(MOD_MMI,"[charger]notify low warning before");
							mmi_frm_input_event_notify(BTBOX_CHARGER_LOW_WARNING, NULL);
	                        kal_prompt_trace(MOD_MMI,"[charger]notify low warning after");
				      
	           }else{
                 batteryLowCount++;
	           }
	        break;
        }
        
        default:
        {	 
			break;
        }
    }
	
}
#endif

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)

/*****************************************************************************
 * FUNCTION
 *  BatteryStatusIndication
 * DESCRIPTION
 *  This function shows the level on status icons of mainlcd nad sublcd.
 * PARAMETERS
 *  battery_voltage     [IN]        Battery level
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryStatusIndication(U8 battery_voltage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 battery_grid_percentage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (battery_voltage)
    {
        case BATTERY_LOW_POWEROFF:      /* pass */
        case BATTERY_LOW_TX_PROHIBIT:   /* pass */
        case BATTERY_LOW_WARNING:       /* pass */
        case BATTERY_LEVEL_0:
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_LOW_BATTERY_WARNING, battery_voltage);
            battery_grid_percentage = 0;
            break;
        }

        case BATTERY_LEVEL_1:   /* pass */
        case BATTERY_LEVEL_2:   /* pass */
        case BATTERY_LEVEL_3:   /* pass */
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_BATTERY_LEVEL, battery_voltage);
            battery_grid_percentage = 33 * (battery_voltage - BATTERY_LEVEL_0);
            break;
        }

        default:
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_BATTERY_STATE_UNKNOWN_VOLTAGE);
            battery_grid_percentage = 33; // 1 grid
            break;
        }
    }
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_BATTERY_STRENGTH, battery_grid_percentage);
#ifdef __MMI_SUBLCD__
    if (mmi_charbat_show_sublcd_battery_status_icon())
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, battery_grid_percentage);
#endif 
}
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/

/*****************************************************************************
 * FUNCTION
 *  IS_LOW_BATTERY
 * DESCRIPTION
 *  This function checks if battery is low.
 *  OLD API, please use new api
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  voltage low
 *  MMI_FALSE: noe voltage low
 *****************************************************************************/
BOOL IS_LOW_BATTERY(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_charbat_is_low_battery();
}

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
/*****************************************************************************
 * FUNCTION
 *  BatteryIndicationPopup
 * DESCRIPTION
 *  General popup fn for charger events.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryIndicationPopup(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_type;
    mmi_scenario_id scenario_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_BATTERYINDICATION_POPUP);

#if defined(__DM_LAWMO_SUPPORT__)
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif

#if !defined(__MMI_MAINLCD_94X64__) && !defined(__MMI_MAINLCD_128X128__)
    if (stringId == STR_CHARGER_CONNECTED || stringId == STR_CHARGER_REMOVED ||
        stringId == STR_USB_CHARGER_CONNECTED || stringId == STR_USB_CHARGER_REMOVED)
        return; /* In other resolution, don't show popup*/
#endif
    if (( stringId == STR_LOW_BATTERY) || ( stringId == STR_LOW_BATTERY_MT_PROHIBIT))
    {
        event_type = MMI_EVENT_WARNING;
        scenario_id = MMI_SCENARIO_ID_BATTERY_HIGHEST;
    }
#ifdef __CLASSAB_VOLUME_PROTECTION__
    else if ((stringId == STR_BATTERY_SAVE_POWER_ON) || (stringId == STR_BATTERY_SAVE_POWER_OFF))
    {
        event_type = MMI_EVENT_INFO;
        scenario_id = MMI_SCENARIO_ID_BATTERY_HIGHEST;
    }
#endif
    else
    {
        event_type = MMI_EVENT_INFO;
        scenario_id = MMI_SCENARIO_ID_BATTERY_MEDIUM;
    }
#if !defined(__IOT__)
    mmi_frm_nmgr_popup(scenario_id, event_type, (WCHAR *)GetString(stringId));
#endif
}
#endif/*__MMI_UI_DISPLAY_LEVEL_NONE__*/

void BatteryIndicationPopupEx(U16 stringId)
{
    if (g_usb_popup_show)
    {
        return;
    }
    g_usb_popup_show = 1;
    BatteryIndicationPopup(stringId);
}

static void mmi_charger_clear_usb_popup_show(void)
{
    g_usb_popup_show = 0;
}

MMI_BOOL mmi_pwron_abnormal_charing_entry_func(mmi_scenario_id scen_id, void *arg)
{
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CHARGER_ROOT, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    AbnormalBatteryIndPopup();    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ChargingAbnormalHandler
 * DESCRIPTION
 *  Handle General Abnormal battery ind.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
void ChargingAbnormalHandler(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.isChargerConnected && !srv_bootup_is_booting())
    {
        g_abnormal_id = stringId;
    #if !defined(__IOT__)
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BATTERY_HIGHEST, MMI_EVENT_BATTERY_WARNING, mmi_pwron_abnormal_charing_entry_func, &g_abnormal_id);
    #endif
        srv_led_pattern_start_battery_warning();
        wgui_status_icon_bar_update();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AbnormalBatteryIndPopup
 * DESCRIPTION
 *  Exit General Abnormal battery ind popup.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
static void AbnormalBatteryIndPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_charbat_context.ChargingAbnormal = 1;

    if (!mmi_frm_scrn_enter(GRP_ID_CHARGER_ROOT, SCR_ABNORMAL_CHARGING, ExitAbnormalBatteryIndPopup, AbnormalBatteryIndPopup, MMI_FRM_UNKNOW_SCRN))
        return;

    mmi_frm_start_scenario(MMI_SCENARIO_ID_BATTERY_HIGHEST);

#if !defined(__IOT__)
    ClearKeyEvents();

   icon_id = mmi_get_event_based_image(EVENT_BATTERY_WARNING);          
    
    ShowCategory64Screen(g_abnormal_id, icon_id , 0);
    
#ifdef __MMI_SUBLCD__    
    ShowSubLCDScreen(ShowSubLCDAbnormalPopup);
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);
    if (g_charbat_context.PowerOnCharger == 0)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BATTERY_STRENGTH);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_BATTERY_STRENGTH);
    }
    else
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);   /* Abnormal case */
        ClearKeyHandler(KEY_POWER, KEY_LONG_PRESS);   /* Abnormal case */
    }

    wgui_status_icon_bar_update();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ExitAbnormalBatteryIndPopup
 * DESCRIPTION
 *  Exit General Abnormal battery ind popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitAbnormalBatteryIndPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackSubLCDHistory();  
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BATTERY_HIGHEST);
}

#ifdef __MMI_SUBLCD__

/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDAbnormalPopup
 * DESCRIPTION
 *  General Abnormal battery ind popup for sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowSubLCDAbnormalPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUBLCD_ABNORMAL_BATTERY, 0);
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  ShowLowPowerShutdownScr
 * DESCRIPTION
 *  Show Low power shutdown screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowLowPowerShutdownScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CHARGER_ROOT, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(GRP_ID_CHARGER_ROOT, GLOBAL_SCR_DUMMY, NULL, ShowLowPowerShutdownScr, MMI_FRM_FG_ONLY_SCRN))      
        return;
	
#ifndef __MMI_BT_DIALER_SUPPORT__
    DeInitFramework_KeyAndEventHandler();
#endif

#if !defined(__IOT__)
    ShowCategory64Screen(STR_LOW_BATTERY_SHUTDOWN, IMG_GLOBAL_WARNING, NULL);
    BatteryStatusIndication(BATTERY_LOW_POWEROFF);
#endif

    StartTimer(LOW_BATTERY_SCR_TIMER, LBAT_SHUTDOWN_SCR_TIMER_DUR, LowBatteryShutDownScrTimeout);

    ChgrPlayLowBatTone();
}


/*****************************************************************************
 * FUNCTION
 *  LowBatteryShutDownScrTimeout
 * DESCRIPTION
 *  Call back fn when Low Battery shutdown timer expired.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void LowBatteryShutDownScrTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(LOW_BATTERY_SCR_TIMER);
#ifdef __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__
    srv_shutdown_exit_system(APP_CHARGER);
#else /* __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__ */ 
    /* if low battery shutdown at power on, do no play power off animation */
    if (srv_bootup_is_booting())
    {
        srv_shutdown_exit_system(APP_CHARGER);
    }
    else
    {
        srv_shutdown_normal_start(APP_CHARGER);
    }
#endif /* __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__ */ 
}

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)

/*****************************************************************************
 * FUNCTION
 *  IdleScreenChargerConnected
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  playtone        [IN]        True/False
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenChargerConnected(U8 playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__IOT__)
    if (playtone == KAL_TRUE)
    {
        srv_prof_tone_enum tone_id = SRV_PROF_TONE_NONE;
        
        tone_id = (srv_prof_tone_enum)mmi_get_event_based_sound(EVENT_BATTERY_NOTIFY);  
        srv_prof_play_tone(tone_id, NULL);        
        //playRequestedTone(AUX_TONE);
    }

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_BATTERY_STRENGTH);
    wgui_status_icon_bar_set_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
#ifdef __MMI_SUBLCD__
    if (mmi_charbat_show_sublcd_battery_status_icon())
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        wgui_status_icon_bar_set_icon_animate(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    }
#endif
    wgui_status_icon_bar_update();
#endif /* !defined(__IOT__) */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_IN);            
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenChargerDisconnected
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenChargerDisconnected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 pp_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //pp_flag = GetInterruptPopupDisplay();
    //if (pp_flag & POPUP_TONE_ON)
    //{
    //    srv_prof_tone_enum tone_id = 0;
        
    //    tone_id = (srv_prof_tone_enum)mmi_get_event_based_sound(EVENT_BATTERY_NOTIFY);  
    //    playRequestedTone((srv_prof_tone_enum)tone_id);
    //}
#if !defined(__IOT__)
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BATTERY_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_BATTERY_STRENGTH);
#ifdef __MMI_SUBLCD__
    if (mmi_charbat_show_sublcd_battery_status_icon())
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    }
#endif
    wgui_status_icon_bar_update();
    BatteryStatusIndication(g_charbat_context.chargerLevel);
#endif
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_OUT);            
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenBatteryFullCharged
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenBatteryFullCharged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BATTERY_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_BATTERY_STRENGTH);
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_BATTERY_STRENGTH, 100);
#ifdef __MMI_SUBLCD__
    if (mmi_charbat_show_sublcd_battery_status_icon())
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
    }
#endif
    wgui_status_icon_bar_update();
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_BATTERY_FULL_CHARGED);                
}


/*****************************************************************************
 * FUNCTION
 *  ShowChargingCompleteScr
 * DESCRIPTION
 *  Show Charging Complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_CHARGE_COMPLETE_SCREEN);
    if (!mmi_frm_scrn_enter(GRP_ID_CHARGER_ROOT, SCR_CHARGING_COMPLETE, NULL, ShowChargingCompleteScr, MMI_FRM_UNKNOW_SCRN))
        return;

    //DinitHistory();
#if !defined(__IOT__)
    wgui_cat9002_show(IMG_ID_CHARGER_DONE, 0, NULL, 0);
#endif

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(ShowSubLCDChargingCompleteScr);
#endif

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        SetKeyLongpressHandler(ChargingPwnOnThanPwnOn, KEY_POWER);
    }
    else
    {
        SetKeyLongpressHandler(ChargingPwnOnThanPwnOn, KEY_END);
    }        
}

#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
#ifdef __MMI_SUBLCD__

/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDChargingCompleteScr
 * DESCRIPTION
 *  Show sublcd charging complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowSubLCDChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
    }
    else
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    {
        ShowCategory304Screen(IMG_SUBLCD_CHARGING_COMPLETE, 0);
    }

    SetSubLCDExitHandler(ExitSubLCDChargingCompleteScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDChargingCompleteScr
 * DESCRIPTION
 *  Exit from sublcd charging complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitSubLCDChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDChargingCompleteScr;
    AddSubLCDHistory(&SubLCDHistory);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_charger_bootup_callback
 * DESCRIPTION
 *  Display Charger status after power on enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_charger_bootup_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.isChargerConnected)
    {
    	StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChargerDetectTimeoutHdlr
 * DESCRIPTION
 *  Display Charger status after power on enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ChargerDetectTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BOOTUP_CHARGER_DETECT_TIMER);

    if (srv_charbat_is_charging())
    {
        IdleScreenChargerConnected(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChgrPlayLowBatTone
 * DESCRIPTION
 *  Display Charger status after power on enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChgrPlayLowBatTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__IOT_NO_MULTIMEDIA__)
    if (!srv_charbat_is_charging())
    {
        srv_prof_play_tone(BATTERY_LOW_TONE, NULL);        
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_get_current_battery_level
 * DESCRIPTION
 *  Gets current battery level
 *  Old API, Please use New API srv_charbat_get_battery_level
 *****************************************************************************/
U8 mmi_gpio_get_current_battery_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* please refer to battery_level_enum for the definition of battery level */
    return (U8)srv_charbat_get_battery_level();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_is_charger_connected
 * DESCRIPTION
 *  Query charger status
 *  Old API, Please use New API srv_charbat_is_charging
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_BOOL mmi_gpio_is_charger_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_charbat_is_charging();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_is_charging_full
 * DESCRIPTION
 *  Query charger status
 *  OLD API, please use srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE)
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_BOOL mmi_gpio_is_charging_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);    
}


