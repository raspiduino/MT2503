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
 * GeneralDeviceInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Utility functions for GPIO
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui.h"
#include "wgui_categories_util.h"
#include "wgui_categories_CM.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "BtcmSrvGprot.h"
#include "GlobalResDef.h"
#include "IdleAppDef.h"
#ifdef __MMI_ENGINEER_MODE__
#include "EngineerModeGprot.h"
#endif
#include "CustDataRes.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"

#include "CommonScreens.h"
#include "BootupSrvGprot.h"
#include "shutdownSrvGprot.h"
#include "GpioSrvGprot.h"

#ifdef __CTM_SUPPORT__
#include "CtmSrvGprot.h"
#endif 

#if defined(__MMI_BT_SUPPORT__)
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_FACTORY_MODE__
#include "FactoryModeProt.h"
#endif /* __MMI_FACTORY_MODE__ */

#if defined(__DM_LAWMO_SUPPORT__)
#include "dmuigprot.h"
#endif

#include "UcmSrvGprot.h"

#ifdef __MMI_SNDREC_SKIN__
#include "SndrecGprot.h"
#endif

/***************************************************************************** 
* Local variable
*****************************************************************************/

/***************************************************************************** 
* Local function
*****************************************************************************/
static void mmi_gpio_earphone_display_popup(MMI_BOOL is_plugin);

/***************************************************************************** 
* Global variable
*****************************************************************************/

/***************************************************************************** 
* External variable
*****************************************************************************/
#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
extern U8 gCurrentMode;
#endif 
//huking
//extern void UI_BLT_double_buffer(S32 x1, S32 y1, S32 x2, S32 y2);

/***************************************************************************** 
* External functitons
*****************************************************************************/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
extern void ShowSubLCDAnalogClockScreen(void);
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_lcd_sleep_out_update_dt
 * DESCRIPTION
 *  This function update datetime area when LCD sleep out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_lcd_sleep_out_update_dt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	UI_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
	
	update_mainlcd_dt_display();
    update_sublcd_dt_display();

    wgui_cat020_update_duration();
    wgui_cat403_update_duration();
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_lcd_sleep_out_repaint_screen
 * DESCRIPTION
 *  This function update datetime area when LCD sleep out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_lcd_sleep_out_repaint_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SUBLCD__)
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    mmi_frm_ui_force_update_now();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* defined(__MMI_SUBLCD__) */ 

    /* redraw main lcd */
    mmi_frm_ui_force_update_now();
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_mute_phone
 * DESCRIPTION
 *  This function mutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_mute_phone(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MUTE);
    wgui_status_icon_bar_update();   
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_unmute_phone
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_unmute_phone(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_MUTE);
    wgui_status_icon_bar_update();	
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_earphone_plug_in
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_earphone_plug_in(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	wgui_status_icon_bar_show_icon(STATUS_ICON_EARPHONE_INDICATOR);
	
    mmi_gpio_earphone_display_popup(MMI_TRUE);    
    
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_earphone_plug_out
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_earphone_plug_out(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_SUPPORT__)
    //if (!mmi_bt_is_hs_connected() && !mmi_bt_is_a2dp_connected())
    if (!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || 
    	  srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ) &&
    	!srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION))
#endif 
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_EARPHONE_INDICATOR);
    }

#ifdef __MMI_FM_RADIO_ON_SUBLCD__
	if (mmi_fmrao_sub_exit_by_earphone_plug_out())
	{
		/* Because the clam is closed, we don't need to display the popup at mainLCD */
		return;
	}
#endif

    mmi_gpio_earphone_display_popup(MMI_FALSE);

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  EarphonePopupSublcd
 * DESCRIPTION
 *  Display earphone plug in/out popup on SubLCD
 *  
 *  PARAMETERS: void
 *****************************************************************************/
void mmi_gpio_earphone_popup_sublcd()
{
	DisplaySubLcdPopup(IMG_EARPHONE_POPUP_SUBLCD);
}


/*****************************************************************************
 * FUNCTION
 *  EarphoneDisplayPopup
 * DESCRIPTION
 *  Display earphone plug in/out popup
 *  
 *  PARAMETERS: BOOL
 *  is_plugin       [IN]        
 *****************************************************************************/
static void mmi_gpio_earphone_display_popup(MMI_BOOL is_plugin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!srv_earphone_status_changed() ||
	    srv_shutdown_is_running() ||	
        (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL && !srv_bootup_is_exception_mode()))
    {
        return;
    }

#ifdef __MMI_ENGINEER_MODE__
    if (gCurrentMode == ENGINEERING_MODE)
    {
        return;
    }
#endif /* __MMI_ENGINEER_MODE__ */ 

#ifdef __MMI_FACTORY_MODE__
    if (gCurrentMode == FACTORY_MODE)
    {
        return;
    }
#endif /* __MMI_FACTORY_MODE__ */ 

#if defined(__DM_LAWMO_SUPPORT__)
    if (mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif 

// Todo: Temp solution, BD suggest remove earphone popup anywhere
#if defined(__OP01__) && defined(__MMI_SNDREC_SKIN__)
    if (mmi_sndrec_is_in_recording())
    {
        return;
    }
#endif

    if (is_plugin == MMI_TRUE)  /* Plug in */
    {
        str_id = STR_GLOBAL_EARPHONE_IN;
    }
    else    /* Plug out */
    {
        str_id = STR_GLOBAL_EARPHONE_OUT;
    }

    /* don't play tone when show popup */
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_EARPHONE, MMI_EVENT_EARPHONE_PLUG_INOUT, (WCHAR *)GetString(str_id));

#ifdef __MMI_SUBLCD__
    if (MMI_TRUE == is_plugin)
    {// BD teams suggest Don't show earphone popup in sub LCD
        //ForceSubLCDScreen(mmi_gpio_earphone_popup_sublcd);//fugui for sublcd master
    }
#endif /* __MMI_SUBLCD__ */ 
}

#ifdef __MMI_CLAMSHELL__

/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_clam_close_goto_idle
 * DESCRIPTION
 *  Function for clam close go back to idle screen
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void mmi_gpio_clam_close_goto_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_CLAMCLOSE_BACK2IDLE__) || defined (__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) )
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        if (srv_earphone_is_plug_in()
        #if defined(__MMI_BT_SUPPORT__)
            || srv_bt_cm_is_incall_aud_swap2bt() == MMI_TRUE
        #endif 
            )
            return;
    }
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_CLAMCLOSE_GOTO_IDEL_END_KEY, GetKeyHandler(KEY_END, KEY_EVENT_DOWN));

#ifdef __MMI_FACTORY_MODE__
    if (gCurrentMode == FACTORY_MODE)
    {
        FM_RestoreAudio();
        return;
    }
#endif /* __MMI_FACTORY_MODE__ */ 

    ClearKeyEvents();
    mmi_frm_send_key_event(KEY_END, KEY_EVENT_DOWN); // Back to idle in Main LCD, except some special app, e.g. PUK...

    #ifdef __MMI_SUBLCD_MASTER_MODE__
        SubLCDMasterModeClamclosed();
    #endif
	
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_clam_open
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_clam_open(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SUBLCD_MASTER_MODE__
    SubLCDMasterModeClamOpen();
#endif/* __MMI_SUBLCD_MASTER_MODE__ */

    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_ALARM)
    {
        srv_backlight_turn_on(1);
    }

    if (!srv_bootup_is_booting())
    {
        if (srv_gpio_allow_clam_tone()&& mdi_audio_mma_is_idle())
        {
            srv_prof_play_tone(COVER_OPEN_TONE, NULL);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_handle_clam_clos
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gpio_handle_clam_close(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_bootup_is_booting())
    {
        mmi_gpio_clam_close_goto_idle();
        
    #ifndef __MMI_SLIDE__
        srv_backlight_close();
    #else /* __MMI_SLIDE__ */ 
        if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM)
        {
            srv_backlight_turn_on(0);
        }
        else
        {
            srv_backlight_turn_on(1);
        }
    #endif /* __MMI_SLIDE__ */ 

        if (srv_gpio_allow_clam_tone()&& mdi_audio_mma_is_idle())
        {
            srv_prof_play_tone(COVER_CLOSE_TONE, NULL);
        }
    }

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    ForceSubLCDScreen(ShowSubLCDAnalogClockScreen);
#endif 

    return MMI_RET_OK;
}

#endif


