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
 * 
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_USB_SUPPORT__
#ifndef __COSMOS_MMI_PACKAGE__

#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "PixcomFontEngine.h"
#include "mdi_audio.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "custom_led_patterns.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "mmi_rp_app_charger_def.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "wgui_categories_idlescreen.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "device.h"
#include "AllAppGprot.h"
#include "PenCalibrationSrvGprot.h"
#include "GeneralSettingSrvGprot.h"
#include "PhonesetupGprots.h"
#include "gpiosrvgprot.h"
#include "usbsrvgprot.h"
#include "PowerOnChargerProt.h" /* BatteryIndicationPopup() */
#include "usb_mode.h"
#include "bootupsrvGprot.h"
#include "ShutdownsrvGprot.h"
#include "AlarmFrameworkProt.h"
#include "CharBatSrvGProt.h"


#include "mmi_rp_app_usbmmi_def.h"
#include "UsbDeviceDefs.h"
#include "USBSrvIprot.h"
#include "USBSrvGprot.h"

static MMI_ID g_usb_boot_mode_group;

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
extern void InitUnicodeSupport(void);
#endif

extern void InitHardwareEvents(void);
extern void InitSettingBootup(void);
extern void InitSettingNVRAM(void);
//extern void PhnsetReadNvramCalibrationData(void);
extern void InitRingToneComposer(void);
extern void PmgInitExtMelodyStruct(void);
extern MMI_ID srv_reminder_init(mmi_event_struct *evt);
extern void PendingAlarmReminder(void);
extern void InitFramework(void);
extern void InitSoundEffect(void);

static void mmi_usb_boot_enter_group(void);
static MMI_ID mmi_usb_get_boot_group_id(void);
static MMI_ID mmi_usb_get_boot_group_id_ext(void);
static void mmi_usb_close_boot_group(void);
static mmi_ret mmi_usb_boot_group_proc(mmi_event_struct *param);
static void mmi_usb_boot_show_scrn_int(void);
static mmi_ret mmi_usb_boot_scrn_proc (mmi_event_struct *param);
static void mmi_usb_boot_show_scrn(void);
static void mmi_usb_boot_show_charge_cmplt_int(void);
static mmi_ret mmi_usb_boot_charge_cmplt_scrn_proc (mmi_event_struct *param);
static void mmi_usb_boot_close_for_reset(void);
static void mmi_usb_boot_set_power_key(void);

#ifdef __MMI_SUBLCD__
static void mmi_usb_exit_sublcd_scr(void);
static void mmi_usb_show_sublcd_scr(void);
static void mmi_usb_exit_sublcd_charge_cmplt(void);
static void mmi_usb_show_sublcd_charge_cmplt(void);
#endif

//extern charbat_context_struct g_charbat_context;
extern MMI_USB_CONTEXT *mmi_usb_ptr;

/*****************************************************************************
 * FUNCTION
 *  InitializeUsbScr
 * DESCRIPTION
 *  This function is initial function for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void mmi_usb_boot_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    InitUnicodeSupport();
#endif

    PhnsetReadGPIOSetting();
    
    srv_backlight_init_context_early();
    
    srv_usb_init_bootup();
    srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
    
    mmi_fe_init();
    InitFramework();
    setup_UI_wrappers();

    PopulateResData();
    initialize_UI_demo();

    /*init sound effect settings, this shall be done before set lang by nvram 
      since it might effect equalizer values*/
    InitSoundEffect();
    //PhnsetSetLangByNvramValue(); 
    srv_setting_init_language();

    mdi_audio_init();

    InitHardwareEvents();
    InitTime();

    srv_prof_init();
    
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    //PhnsetReadNvramCalibrationData();
    srv_setting_pen_calibration_init_data();
#endif 

    /* InitSettingNVRAM(); */

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    PmgInitExtMelodyStruct();
#endif 
    PhnsetRestoreToNvramContrast();

    srv_reminder_init(NULL);

   
    g_charbat_context.PowerOnCharger = 1;
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
    srv_led_pattern_start_charging();
    wgui_status_icon_bar_set_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
    wgui_status_icon_bar_update();

    PendingAlarmReminder();
#endif

    InitChargerPwrOn();

    /* Enter USB mode will begin charge itself */
    g_charbat_context.isChargerConnected = 1;
    
    #if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    mmi_usb_boot_show_scrn();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    #endif
}


#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_show_sublcd_scr
 * DESCRIPTION
 *  This function is to show sublcd screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED : none(?)
 *****************************************************************************/
static void mmi_usb_show_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUB_USB_POWER_ON, 0);
    SetSubLCDExitHandler(mmi_usb_exit_sublcd_scr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDUsbScr
 * DESCRIPTION
 *  This function is to exit handler for sublcd screen in usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static void mmi_usb_exit_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = mmi_usb_show_sublcd_scr;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_show_sublcd_charge_cmplt
 * DESCRIPTION
 *  This function is to show sublcd charging complete screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED : none(?)
 *****************************************************************************/
static void mmi_usb_show_sublcd_charge_cmplt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_USB_SUB_CHGR_CMPLT, 0);
    wgui_status_icon_bar_update();
    SetSubLCDExitHandler(mmi_usb_exit_sublcd_charge_cmplt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_exit_sublcd_charge_cmplt
 * DESCRIPTION
 *  This function is to exit handler for sublcd charging complete screen in usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static void mmi_usb_exit_sublcd_charge_cmplt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = mmi_usb_show_sublcd_charge_cmplt;
    AddSubLCDHistory(&SubLCDHistory);
}

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  ShowUsbChgCmpltScr
 * DESCRIPTION
 *  This function is to display main screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
void mmi_usb_boot_show_charge_cmplt(void)
{
    if (!srv_usb_is_connected())
    {
        srv_shutdown_exit_system(0);
    }
    else
    {
        //mmi_usb_boot_show_charge_cmplt_int();
        mmi_frm_scrn_create(
            mmi_usb_get_boot_group_id(), 
            SCR_USB_CHGR_CMPLT,
            mmi_usb_boot_charge_cmplt_scrn_proc,
            NULL);
    }
}

static mmi_ret mmi_usb_boot_charge_cmplt_scrn_proc (mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_usb_boot_show_charge_cmplt_int();
            break;

        default:
            break;
    }

    return MMI_OK;
}

static void mmi_usb_boot_dummy_screen_entry(void)
{
}

static void mmi_usb_boot_close_for_reset(void)
{
    mmi_frm_scrn_enter(GRP_ID_ROOT, GLOBAL_SCR_DUMMY, NULL, mmi_usb_boot_dummy_screen_entry, (mmi_frm_scrn_type_enum)0);
    mmi_usb_close_boot_group();
    srv_usb_app_reset_poweron();
}

static void mmi_usb_boot_show_charge_cmplt_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__)
    extern void wgui_cat9002_show(U16 image_icon_1,U16 image_icon_2, U8 *history_buffer, U8   flags);
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__)
    ShowCategory9Screen(0, IMG_USB_CHGR_CMPLT, NULL);
#else
    wgui_cat9002_show(0,IMG_ID_CHARGER_DONE,NULL,0);
#endif

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(mmi_usb_show_sublcd_charge_cmplt);
#endif /* __MMI_SUBLCD__ */ 

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    mmi_usb_boot_set_power_key();
}

/*****************************************************************************
 * FUNCTION
 *  ShowUsbScr
 * DESCRIPTION
 *  This function is to display main screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
static void mmi_usb_boot_show_scrn(void)
{
    mmi_usb_boot_enter_group();
    mmi_frm_scrn_close(mmi_usb_get_boot_group_id_ext(), SCR_USB_POWER_ON);
    mmi_frm_scrn_create(
        mmi_usb_get_boot_group_id_ext(), 
        SCR_USB_POWER_ON,
        mmi_usb_boot_scrn_proc,
        NULL);
}

static mmi_ret mmi_usb_boot_scrn_proc (mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_usb_boot_show_scrn_int();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

static void mmi_usb_boot_enter_group(void)
{
    if (g_usb_boot_mode_group != GRP_ID_INVALID)
    {
        return;
    }
    g_usb_boot_mode_group = mmi_frm_group_create_ex(GRP_ID_ROOT, 
        GRP_ID_USB_BOOT_MODE, 
        mmi_usb_boot_group_proc, 
        NULL, 
        MMI_FRM_NODE_NONE_FLAG);
}

static MMI_ID mmi_usb_get_boot_group_id(void)
{
    mmi_usb_boot_enter_group();
    return g_usb_boot_mode_group;
}

static MMI_ID mmi_usb_get_boot_group_id_ext(void)
{
    return g_usb_boot_mode_group;
}

static void mmi_usb_close_boot_group(void)
{
    if (g_usb_boot_mode_group == GRP_ID_INVALID)
    {
        return;
    }
    mmi_frm_group_close(g_usb_boot_mode_group);
    g_usb_boot_mode_group = GRP_ID_INVALID;
}

static mmi_ret mmi_usb_boot_group_proc(mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_usb_boot_mode_group = GRP_ID_INVALID;
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_usb_boot_show_scrn_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__)
    extern void wgui_cat9002_show(U16 image_icon_1,U16 image_icon_2, U8 *history_buffer, U8   flags);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

#ifdef __MMI_USB_COPY_RIGHT__
    mmi_popup_display_simple((WCHAR*)GetString(STR_USB_POWER_ON_PROCESSING), 
        MMI_EVENT_PROGRESS, mmi_usb_get_boot_group_id(), NULL);
#else 

    #if !defined(__MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__)
        if (mmi_usb_ptr->still_image==MMI_USB_POWERON_CHARGING_ENABLE)
        {
            ShowCategory106Screen(IMG_ID_USB_CHARGING, NULL, NULL);
        }
        else if (mmi_usb_ptr->still_image==MMI_USB_POWERON_CHARGING_DISABLE)
        {
            ShowCategory106Screen(IMG_USB_POWER_ON, NULL, NULL);            
        }
    #else
        wgui_cat9002_show(0,IMG_ID_CHARGER_CHARGING,NULL,0);
    #endif
#endif 

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(mmi_usb_show_sublcd_scr);
#endif 

    mmi_usb_boot_set_power_key();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_boot_pwrnon_then_poweron
 * DESCRIPTION
 *  This function is to send power on request to PS
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void mmi_usb_boot_pwrnon_then_poweron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_PWRON_THEN_PWRON);

#if defined(__MMI_SUBLCD__)
    lcd_power_on(SUB_LCD, 0);
#endif 
#ifdef __MMI_BTBOX_NOLCD__
    srv_backlight_all_lcd_off();
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
#endif
    mmi_frm_clear_all_key_handler();
#endif /* __MMI_BTBOX_NOLCD__ */
    if (srv_usb_get_status() == SRV_USBSTATUS_MS)
    {
        srv_usb_send_power_on_req();
    }    
    else
    {
        srv_usb_send_power_on_req();
    }
}


#ifdef __MMI_USB_COPY_RIGHT__


/*****************************************************************************
 * FUNCTION
 *  UsbPowerOnFinishHdlr
 * DESCRIPTION
 *  This function is usb power on finish indication event handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static void mmi_usb_boot_finish_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(mmi_usb_get_boot_group_id(), SCR_USB_POWER_ON_DONE, NULL, mmi_usb_boot_finish_hdlr, 0))
    {
        return;
    }

    ShowCategory106Screen(IMG_USB_POWER_ON, NULL, NULL);

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(mmi_usb_show_sublcd_scr);
#endif 
    mmi_usb_boot_set_power_key();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_init_event_hdlr
 * DESCRIPTION
 *  Init MMI event handler
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_boot_init_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_usb_boot_finish_hdlr, PRT_EQ_USB_POWER_ON_FINISH_IND);
}

#endif /* __MMI_USB_COPY_RIGHT__ */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_usb_set_background_still
 * DESCRIPTION
 *  Set background image
 * PARAMETERS
 *  isStill     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_boot_set_background_still(MMI_BOOL isStill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_charbat_context.isChargerConnected)
    {
        return;
    }
    
    if (isStill)
    {
        if (mmi_usb_ptr->still_image == MMI_USB_POWERON_CHARGING_DISABLE &&
            mmi_frm_scrn_get_active_id() == SCR_USB_POWER_ON)
        {
            return;
        }
        if (g_usb_boot_mode_group != GRP_ID_INVALID)
            mmi_usb_ptr->still_image = MMI_USB_POWERON_CHARGING_DISABLE;
    }
    else
    {
        if (mmi_usb_ptr->still_image == MMI_USB_POWERON_CHARGING_ENABLE &&
            mmi_frm_scrn_get_active_id() == SCR_USB_POWER_ON)
        {
            return;
        }
        if (g_usb_boot_mode_group != GRP_ID_INVALID)
            mmi_usb_ptr->still_image = MMI_USB_POWERON_CHARGING_ENABLE;
    }

    if (mmi_frm_scrn_get_active_id() == SCR_USB_POWER_ON)
    {
        mmi_usb_boot_show_scrn();
    }
}

static void mmi_usb_boot_set_power_key(void)
{
    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        SetKeyLongpressHandler(mmi_usb_boot_close_for_reset, KEY_POWER);        
    }
    else
    {
        SetKeyLongpressHandler(mmi_usb_boot_close_for_reset, KEY_END);
    }
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
#endif

void mmi_usb_close_power_off_screen(void)
{
    if (g_usb_boot_mode_group == GRP_ID_INVALID)
        return;
    if (!mmi_alm_is_in_alarm())
        mmi_frm_scrn_enter(GRP_ID_ROOT, GLOBAL_SCR_DUMMY, NULL, mmi_usb_boot_dummy_screen_entry, (mmi_frm_scrn_type_enum)0);
    mmi_usb_close_boot_group();
    //mmi_alm_enable_pwroff();
}


#endif /* __MMI_USB_FTO_SUPPORT__*/
#endif /* __MMI_USB_SUPPORT__*/
