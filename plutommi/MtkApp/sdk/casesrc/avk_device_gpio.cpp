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
*   tst_gpio.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*  3rd Party Integration Development Environment(for Gpio test)
*
* Author:
* -------
* -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifdef __MAUI_SDK_TEST__

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#include "gpiosrvgprot.h"
#include "avk_setting_DevProfile.h"

/* NON SDK API */
#include "SettingDefs.h"
#include "CommonScreens.h"
#include "FileMgrGProt.h"
#include "SettingProfile.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"

/* internal */
#include "mmi_rp_app_sdk_test_def.h"
#include "TimerEvents.h"
//#include "avk_device_backlight.h"



#ifndef NON_ALIGN_TEST_TM_ID
#define NON_ALIGN_TEST_TM_ID    KEY_TIMER_ID_NONE
#endif

#ifndef TST_GPIO_TIMER_ID
#define TST_GPIO_TIMER_ID NON_ALIGN_TEST_TM_ID
#endif

#ifndef TST_GPIO_TIMER_DELAY_1S
#define TST_GPIO_TIMER_DELAY_1S  1*1000
#endif

#ifndef TST_GPIO_TIMER_DELAY_3S
#define TST_GPIO_TIMER_DELAY_3S  3*1000
#endif

vs_dev_gpio_vibrate         		g_vibrate;
vs_dev_gpio_device_level    	device_level;
vs_dev_play_pattern  			g_play_pattern;
vs_dev_gpio_device_mute 		g_device_mute;
vs_dev_gpio_volume 			g_device_volume;
vs_dev_speech_mode_volume 	g_speech_mode_volume;
S32 						g_vs_dev_gpio_option_index;

extern void ShowCategory227Screen(
        U8 *title_string,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        void (*display_call_back) (dm_coordinates *coordinate),
        MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point));

// screen enter 
void vs_dev_gpio_set_device_level_screen_enter(void);
void vs_dev_gpio_set_device_level_callback(void);
void vs_dev_gpio_set_device_level_add_callback(void);
void vs_dev_gpio_set_device_level_sub_callback(void);
void vs_dev_gpio_set_device_level_add(void);
void vs_dev_gpio_set_device_level_sub(void);
void vs_dev_gpio_set_device_type_add(void);
void vs_dev_gpio_set_device_type_sub(void);


// display screen callback
void vs_dev_gpio_earphone_is_plug_in_display_screen_enter(dm_coordinates *coordinate);
void vs_dev_gpio_phone_is_mute_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_get_mode_volume_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_enable_hand_free_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_disable_hand_free_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_unmute_phone_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_mute_phone_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_device_level_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_device_level_device_draw_detail(gpio_device_enum e_device, U8 u_level);

void vs_dev_gpio_set_volume_and_draw_detail(srv_gpio_vol_type_enum volume_type, U8 volume_level);
void vs_dev_gpio_speech_save_mode_volume_display_screen(dm_coordinates *coordinate);

void vs_dev_gpio_set_device_mute_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_device_mute_device_type_add(void);
void vs_dev_gpio_set_device_mute_device_type_sub(void);
void vs_dev_gpio_set_device_mute_device_change_mute_status(void);
void vs_dev_gpio_set_device_mute_draw_detail(srv_gpio_audio_device_enum device, MMI_BOOL mute_on);

void vs_dev_gpio_set_volume_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_volume_type_add(void);
void vs_dev_gpio_set_volume_type_sub(void);
void vs_dev_gpio_set_volume_level_add(void);
void vs_dev_gpio_set_volume_level_sub(void);


void vs_dev_gpio_speech_save_mode_volume_draw_detail(U8 volume);
void vs_dev_gpio_speech_save_mode_volume_level_add(void);
void vs_dev_gpio_speech_save_mode_volume_level_sub(void);

void vs_dev_gpio_play_pattern_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_play_pattern_draw_detail(srv_gpio_pattern_id_enum pattern, srv_gpio_pattern_type_enum action);
void vs_dev_gpio_play_pattern_id_add(void);
void vs_dev_gpio_play_pattern_id_sub(void);
void vs_dev_gpio_play_pattern_type_add(void);
void vs_dev_gpio_play_pattern_type_sub(void);

void vs_dev_gpio_earphone_is_plug_in_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_set_mode_volume_display_screen(dm_coordinates *coordinate);


void avk_device_gpio_pen_up_hdlr()
{
	StopTimer(TST_GPIO_TIMER_ID);
} 


/*
vs_dev_gpio_backlight_get_timer_state_screen_enter       srv_backlight_get_timer_state
vs_dev_gpio_backlight_is_on_screen_enter                 srv_backlight_is_on
vs_dev_gpio_backlight_get_hf_time_screen_enter           srv_backlight_get_hf_time
vs_dev_gpio_backlight_is_lcd_sleep_screen_enter          srv_backlight_is_lcd_sleep
vs_dev_gpio_backlight_get_level_screen_enter             srv_backlight_get_level
vs_dev_gpio_backlight_close_screen_enter                 srv_backlight_close
vs_dev_gpio_backlight_turn_off_keypad_light_screen_enter srv_backlight_turn_off_keypad_light
vs_dev_gpio_backlight_half_mode_screen_enter             srv_backlight_half_mode
vs_dev_gpio_backlight_turn_on_screen_enter               srv_backlight_turn_on / srv_backlight_turn_off

vs_dev_gpio_play_vibrate_screen_enter                    srv_gpio_play_vibrate

vs_dev_gpio_earphone_is_plug_in_display_screen_enter     srv_earphone_is_plug_in
vs_dev_gpio_speech_is_phone_mute_screen_enter            srv_speech_is_phone_mute
vs_dev_gpio_clam_is_close_screen_enter                   srv_clam_is_close
vs_dev_gpio_set_device_level_screen_enter                srv_gpio_set_device_level                       
vs_dev_gpio_speech_set_mode_volume_screen_enter          srv_speech_set_mode_volume                      
vs_dev_gpio_speech_get_mode_volume_screen_enter          srv_speech_get_mode_volume
vs_dev_gpio_speech_disable_hand_free_screen_enter        srv_speech_disable_hand_free
vs_dev_gpio_speech_enable_hand_free_screen_enter         srv_speech_enable_hand_free
vs_dev_gpio_speech_mute_phone_screen_enter               srv_speech_mute_phone
vs_dev_gpio_speech_unmute_phone_screen_enter             srv_speech_unmute_phone
vs_dev_gpio_set_device_mute_screen_enter                 srv_gpio_set_device_mute
vs_dev_gpio_set_volume_screen_enter                      srv_gpio_set_volume
vs_dev_gpio_mode_volume_screen_enter                     srv_speech_save_mode_volume
vs_dev_gpio_play_pattern_screen_enter                    srv_gpio_play_pattern

*/

gpio_device_enum gpio_device_enum_value []= 
{
    GPIO_DEV_LED_MAINLCD	   ,  /* Main LCD backlight */
    GPIO_DEV_LED_SUBLCD        ,  /* Sub LCD backlight */
    GPIO_DEV_LED_STATUS_1      ,  /* Status LED  R*/
    GPIO_DEV_LED_STATUS_2      ,  /* Status LED  G*/
    GPIO_DEV_LED_STATUS_3      ,  /* Status LED   B*/
    GPIO_DEV_LED_KEY           ,  /* Keypad backlight */
    GPIO_DEV_VIBRATOR          ,  /* Vibrator */
    GPIO_DEV_FLASHLIGHT        ,  /* FlashLight */        
};


void vs_dev_gpio_earphone_is_plug_in_display_screen(dm_coordinates *coordinate)
{
    MMI_BOOL b_earphone_is_in = srv_earphone_is_plug_in();
    AVK_LOG_FUN(srv_earphone_is_plug_in,AVK_PASS);
    // display title
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    if(b_earphone_is_in) // earphone in 
    {   
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"Earphone is plug in");
    }
    else //  earphone not in 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"Earphone is NOT plug in");
    }
}

void vs_dev_gpio_phone_is_mute_display_screen(dm_coordinates *coordinate)
{
    MMI_BOOL b_phone_mute = srv_speech_is_phone_mute();
    AVK_LOG_FUN(srv_speech_is_phone_mute,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    if(b_phone_mute) // earphone in 
    {   
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"Phone is mute");
    }
    else //  earphone not in 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"Phone is NOT mute");
    }
}

void vs_dev_gpio_clam_is_close_display_screen(dm_coordinates *coordinate)
{
    MMI_BOOL b_is_clam_close = srv_clam_is_close();
    AVK_LOG_FUN(srv_clam_is_close,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    if(b_is_clam_close) // earphone in 
    {   
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"clam is close");
    }
    else //  earphone not in 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"clam is open");
    }
}

void vs_dev_gpio_speech_get_mode_volume_display_screen(dm_coordinates *coordinate)
{
    U8 volume         = 0;
    U8 vol_buf[4]   = {0};   
    volume = srv_speech_get_mode_volume();
    AVK_LOG_FUN(srv_speech_get_mode_volume,AVK_PASS);
    kal_wsprintf((WCHAR *)vol_buf,       "%d",   volume);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"audio volume = :");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);     
    gui_print_bordered_text((UI_string_type)(vol_buf));        
}

void vs_dev_gpio_speech_disable_hand_free_display_screen(dm_coordinates *coordinate)
{
    srv_speech_disable_hand_free();
    AVK_LOG_FUN(srv_speech_disable_hand_free,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Disable hands free");
}

void vs_dev_gpio_speech_enable_hand_free_display_screen(dm_coordinates *coordinate)
{
    srv_speech_enable_hand_free();
    AVK_LOG_FUN(srv_speech_enable_hand_free,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Enable hands free");
}
void vs_dev_gpio_speech_mute_phone_display_screen(dm_coordinates *coordinate)
{
    srv_speech_mute_phone();
    AVK_LOG_FUN(srv_speech_mute_phone,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Speech Mute Phone");
}

void vs_dev_gpio_speech_unmute_phone_display_screen(dm_coordinates *coordinate)
{
    srv_speech_unmute_phone();
    AVK_LOG_FUN(srv_speech_unmute_phone,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Speech Unmute Phone");
}

void vs_dev_gpio_set_device_level_display_screen(dm_coordinates *coordinate)
{
    srv_backlight_half_mode();
    AVK_LOG_FUN(srv_backlight_half_mode,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2);
    gui_print_bordered_text((UI_string_type) L"Set Levels of Devices: ");

    // show user info
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"LEFT and RIGHT center key");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"Change device type");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"UP and DOWN center key");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);
    gui_print_bordered_text((UI_string_type) L"Change level");

    vs_dev_gpio_set_device_level_device_draw_detail(device_level.e_device,device_level.u_level);
}

void vs_dev_gpio_set_device_level_volume_add(void)
{
    if((U8)device_level.u_level+1<= LED_LIGHT_LEVEL5)
    {
        device_level.u_level++;
        // start a timer to add device_level.e_device++ auto
        srv_gpio_set_device_level(device_level.e_device,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail(device_level.e_device,device_level.u_level);
    }
}
void vs_dev_gpio_set_device_level_volume_sub(void)
{
    if(device_level.u_level-1>= LED_LIGHT_LEVEL0)
    {
        device_level.u_level--;
        // start a timer to add device_level.e_device++ auto
        srv_gpio_set_device_level(device_level.e_device,(srv_gpio_dev_level_enum)device_level.u_level);
 	    AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);	
        vs_dev_gpio_set_device_level_device_draw_detail(device_level.e_device,device_level.u_level);
    }
}

void vs_dev_gpio_set_device_level_device_draw_detail(gpio_device_enum e_device, U8 u_level)
{
    U8 dis_buf[VS_MM_BUFFER_SIZE];
    U8 dis_str[VS_MM_BUFFER_SIZE];
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gui_print_bordered_text((UI_string_type) L"Device Type: ");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*10);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*10-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*11, GDI_COLOR_RED);// Debug.
    switch(e_device)
    {
    case GPIO_DEV_LED_MAINLCD:
        gui_print_bordered_text((UI_string_type) L"Main LCD backlight.");
        break;
    case GPIO_DEV_LED_SUBLCD:
        gui_print_bordered_text((UI_string_type) L"Sub LCD backlight.");
        break;
    case GPIO_DEV_LED_STATUS_1:            
        gui_print_bordered_text((UI_string_type) L"Status LED R.");
        break;
    case GPIO_DEV_LED_STATUS_2:            
        gui_print_bordered_text((UI_string_type) L"Status LED G.");
        break;
    case GPIO_DEV_LED_STATUS_3:            
        gui_print_bordered_text((UI_string_type) L"Status LED B.");
        break;
    case GPIO_DEV_LED_KEY:
        gui_print_bordered_text((UI_string_type) L"Keypad backlight.");
        break;
    case GPIO_DEV_VIBRATOR:        
        gui_print_bordered_text((UI_string_type) L"Vibrator.");
        break;
    case GPIO_DEV_FLASHLIGHT:                                                    
        gui_print_bordered_text((UI_string_type) L"FlashLight.");
        break;
    default:
        gui_print_bordered_text((UI_string_type) L"Error");
        break;
    }

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*11);
    gui_print_bordered_text((UI_string_type) L"volume level: ");    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*12);
    sprintf((CHAR *) dis_buf, (CHAR *) "= %d", u_level);
    mmi_asc_to_wcs((U16*) dis_str, (CHAR *) dis_buf);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*12-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*13, GDI_COLOR_RED);// Debug.
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
}

void vs_dev_gpio_set_device_mute_display_screen(dm_coordinates *coordinate)
{
    g_device_mute.audio_device_type   = AUDIO_DEVICE_SPEAKER;
    g_device_mute.b_mute_on                 = MMI_FALSE;
    srv_gpio_set_device_mute( g_device_mute.audio_device_type,g_device_mute.b_mute_on);
    AVK_LOG_FUN(srv_gpio_set_device_mute,AVK_PASS); 
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*1);
    gui_print_bordered_text((UI_string_type) L"Audio Device Mute Test: ");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);
    gui_print_bordered_text((UI_string_type) L"UP&DOWN center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"change Audio Device type");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"LEFT&RIGHT center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"change mute status");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    gui_print_bordered_text((UI_string_type) L"Audio Device Type: ");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*11);
    gui_print_bordered_text((UI_string_type) L"Muted?: ");    

    vs_dev_gpio_set_device_mute_draw_detail((srv_gpio_audio_device_enum)device_level.e_device,(MMI_BOOL)device_level.u_level);

}

void vs_dev_gpio_set_device_mute_device_change_mute_status(void)
{

    if(MMI_TRUE == g_device_mute.b_mute_on)
    {
        g_device_mute.b_mute_on = MMI_FALSE;
        srv_gpio_set_device_mute(g_device_mute.audio_device_type , g_device_mute.b_mute_on );
        AVK_LOG_FUN(srv_gpio_set_device_mute,AVK_PASS);
        vs_dev_gpio_set_device_mute_draw_detail(g_device_mute.audio_device_type , g_device_mute.b_mute_on );
    }
    else if(MMI_FALSE == g_device_mute.b_mute_on)
    {
        g_device_mute.b_mute_on = MMI_TRUE;
        srv_gpio_set_device_mute(g_device_mute.audio_device_type , g_device_mute.b_mute_on );
        AVK_LOG_FUN(srv_gpio_set_device_mute,AVK_PASS);
        vs_dev_gpio_set_device_mute_draw_detail(g_device_mute.audio_device_type , g_device_mute.b_mute_on );
    }
}

void vs_dev_gpio_set_device_mute_draw_detail(srv_gpio_audio_device_enum device, MMI_BOOL mute_on)
{
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*9-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*10, GDI_COLOR_RED);// Debug.

    switch(device)
    {
    case AUDIO_DEVICE_SPEAKER:
        gui_print_bordered_text((UI_string_type) L"audio_device:SPEAKER.");   /* Tone, Keypad sound to play on audio device. */
        break;
    case AUDIO_DEVICE_MICROPHONE:
        gui_print_bordered_text((UI_string_type) L"audio_device:MICROPHONE.");  /* Microphone sound to send on audio device. */
        break;
    case AUDIO_DEVICE_BUZZER:            
        gui_print_bordered_text((UI_string_type) L"audio_device:BUZZER.");   /* Ring tone sound to play on audio device. */
        break;
    case AUDIO_DEVICE_GMI:            
        gui_print_bordered_text((UI_string_type) L"audio_device:GMI.");   /* MIDI/Melody sound to play on audio device */
        break;
    case AUDIO_DEVICE_SPEAKER2:
        gui_print_bordered_text((UI_string_type) L"audio_device:SPEAKER2.");    /* earphone, carkit */
        break;
    case AUDIO_DEVICE_LOUDSPEAKER:            
        gui_print_bordered_text((UI_string_type) L"audio_device:LOUDSPEAKER.");   /* loudspeaker for free sound */
        break;
    case AUDIO_DEVICE_SPEAKER_BOTH:            
        gui_print_bordered_text((UI_string_type) L"audio_device:SPEAKER1&2.");  /* FTE feedback */
        break;            
    default:
        gui_print_bordered_text((UI_string_type) L"audio_device: Error");
        break;
    }
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*12);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*12-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*13, GDI_COLOR_RED);// Debug.
    switch(mute_on)
    {
    case MMI_FALSE :
        gui_print_bordered_text((UI_string_type) L"MUTE ON: TRUE");
        break;
    case MMI_TRUE :
        gui_print_bordered_text((UI_string_type)L"MUTE ON: FALSE");
        break;
    default:
        gui_print_bordered_text((UI_string_type)L"MUTE ON: ERROR");    
        break;
    }
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD

}

/*********************************************************************************************************************************************************************/
void vs_dev_gpio_set_volume_display_screen(dm_coordinates *coordinate)
{
    g_device_volume.type        = VOL_TYPE_CTN;
    g_device_volume.volume     = 0;
	 #if 0 
/* under construction !*/
/* under construction !*/
	 #endif
	 mdi_audio_set_volume(g_device_volume.type, g_device_volume.volume);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*1);
    gui_print_bordered_text((UI_string_type) L"Set Volume: ");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);
    gui_print_bordered_text((UI_string_type) L"UP&DOWN center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"change volume type");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"LEFT&RIGHT center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"change volume level");

    vs_dev_gpio_set_volume_and_draw_detail((srv_gpio_vol_type_enum)device_level.e_device,device_level.u_level);

}

void vs_dev_gpio_set_volume_and_draw_detail(srv_gpio_vol_type_enum volume_type, U8 volume_level)
{
    U8 dis_buf[VS_MM_BUFFER_SIZE];
    U8 dis_str[VS_MM_BUFFER_SIZE];

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    gui_print_bordered_text((UI_string_type) L"volume type: ");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*9-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*10, GDI_COLOR_RED);// Debug.

    switch(volume_type)
    {
    case VOL_TYPE_CTN:
        gui_print_bordered_text((UI_string_type) L"call tone.");   /* MMI can apply to associate volume; call tone attribute */
        break;
    case VOL_TYPE_KEY:
        gui_print_bordered_text((UI_string_type) L"keypad tone.");   /* MMI can apply to associate volume; keypad tone attribute */
        break;
    case VOL_TYPE_MIC:            
        gui_print_bordered_text((UI_string_type) L"microphone tone.");    /* microphone attribute */
        break;
    case VOL_TYPE_GMI:            
        gui_print_bordered_text((UI_string_type) L"melody,imelody,midi.");   /* MMI can apply to associate volume; melody, imelody, midi attribute */
        break;
    case VOL_TYPE_SPH:
        gui_print_bordered_text((UI_string_type) L"speech sound.");   /* MMI can apply to associate volume; speech sound attribute */
        break;
    case VOL_TYPE_SID:            
        gui_print_bordered_text((UI_string_type) L"side tone.");    /* side tone attribute */
        break;
    case VOL_TYPE_MEDIA:            
        gui_print_bordered_text((UI_string_type) L"MP3, Wave,...");    /* MMI can apply to associate volume; As MP3, Wave,... attribute */
        break;            
    default:
        gui_print_bordered_text((UI_string_type) L"Error");   /* ERROR */
        break;
    }

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*11);
    sprintf((CHAR *) dis_buf, (CHAR *) "volume level = %d", volume_level);
    mmi_asc_to_wcs((U16*) dis_str, (CHAR *) dis_buf);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*11-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*12, GDI_COLOR_RED);// Debug.
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD

}


// void srv_speech_save_mode_volume(U8 level)
void vs_dev_gpio_speech_save_mode_volume_display_screen(dm_coordinates *coordinate)
{
    g_speech_mode_volume.volume        = 0;
    srv_speech_save_mode_volume(g_speech_mode_volume.volume);  // call srv_gpio I/F
    AVK_LOG_FUN(srv_speech_save_mode_volume,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);
    gui_print_bordered_text((UI_string_type) L"Save Volume: ");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"LEFT&RIGHT center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"change volume level");

    vs_dev_gpio_speech_save_mode_volume_draw_detail(g_speech_mode_volume.volume);
}
void vs_dev_gpio_speech_save_mode_volume_draw_detail(U8 volume)
{
    U8 dis_buf[VS_MM_BUFFER_SIZE];
    U8 dis_str[VS_MM_BUFFER_SIZE];

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    sprintf((CHAR *) dis_buf, (CHAR *) "volume level = %d", volume);
    mmi_asc_to_wcs((U16*) dis_str, (CHAR *) dis_buf);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*8-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*9, GDI_COLOR_RED);// Debug.
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
}

void vs_dev_gpio_play_pattern_display_screen(dm_coordinates *coordinate)
{
    g_play_pattern.pattern_id       = LED_PATTERN_BEGIN;      
    g_play_pattern.pattern_type     = PLAY_STOP;
	
	// call srv_gpio I/F	
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type );
    AVK_LOG_FUN(srv_gpio_play_pattern,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*1);
    gui_print_bordered_text((UI_string_type) L"Set Play Pattern");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);
    gui_print_bordered_text((UI_string_type) L"UP&DOWN center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"change Pattern ID");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"LEFT&RIGHT center key will");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"change Pattern Type");

    vs_dev_gpio_play_pattern_draw_detail((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type );
}

void vs_dev_gpio_play_pattern_draw_detail(srv_gpio_pattern_id_enum pattern, srv_gpio_pattern_type_enum type)
{
    U8 dis_buf[VS_MM_BUFFER_SIZE];
    U8 dis_str[VS_MM_BUFFER_SIZE];

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);
 
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    gui_print_bordered_text((UI_string_type) L"Pattern ID:");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*9-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*10, GDI_COLOR_RED);// Debug.

    switch(pattern)
    {
    /******************************************* LED START *******************************************************/
    case LED_POWER_ON:
        gui_print_bordered_text((UI_string_type) L"LED_POWER_ON.");   
        break;
    case LED_POWER_OFF:
        gui_print_bordered_text((UI_string_type) L"LED_POWER_OFF.");  
        break;
    case LED_BATTERY_WARNING:            
        gui_print_bordered_text((UI_string_type) L"LED_BATTERY_WARNING.");    
        break;
    case LED_BATTERY_LOW:            
        gui_print_bordered_text((UI_string_type) L"LED_BATTERY_LOW.");  
        break;
    case LED_Connect900:
        gui_print_bordered_text((UI_string_type) L"LED_Connect900.");   
        break;
    case LED_Connect1800:            
        gui_print_bordered_text((UI_string_type) L"LED_Connect1800.");    
        break;
    case LED_OnCharging:            
        gui_print_bordered_text((UI_string_type) L"LED_OnCharging.");    
        break;
    case LED_FullCharging:
        gui_print_bordered_text((UI_string_type) L"LED_FullCharging.");   
        break;
    case LED_MessageIn:
        gui_print_bordered_text((UI_string_type) L"LED_MessageIn.");  
        break;
    case LED_MessageRemind:            
        gui_print_bordered_text((UI_string_type) L"LED_MessageRemind.");   
        break;
    case LED_Caller1:            
        gui_print_bordered_text((UI_string_type) L"LED_Caller1.");   
        break;
    case LED_Caller2:
        gui_print_bordered_text((UI_string_type) L"LED_Caller2.");  
        break;
    case LED_Caller3:            
        gui_print_bordered_text((UI_string_type) L"LED_Caller3.");    
        break;
    case LED_Caller4:            
        gui_print_bordered_text((UI_string_type) L"LED_Caller4.");   
        break;                      
    case LED_Caller5:
        gui_print_bordered_text((UI_string_type) L"LED_Caller5.");  
        break;
    case LED_Caller6:
        gui_print_bordered_text((UI_string_type) L"LED_Caller6.");  
        break;
    case LED_LimitService:            
        gui_print_bordered_text((UI_string_type) L"LED_LimitService.");    
        break;
    case LED_NoService:            
        gui_print_bordered_text((UI_string_type) L"LED_NoService.");   
        break;
    case LED_Connect1900:
        gui_print_bordered_text((UI_string_type) L"LED_Connect1900."); 
        break;
    case LED_Roaming:            
        gui_print_bordered_text((UI_string_type) L"LED_Roaming.");   
        break;
        /******************************************* LCD START *******************************************************/
    case LCD_PATTERN_1:
        gui_print_bordered_text((UI_string_type) L"LCD_PATTERN_1."); 
        break;
    case LCD_PATTERN_2:            
        gui_print_bordered_text((UI_string_type) L"LCD_PATTERN_2.");   
        break;        
        /******************************************* VIB START *******************************************************/
    case VIB_PATTERN_1:            
        gui_print_bordered_text((UI_string_type) L"VIB_PATTERN_1.");    
        break;
    case VIB_PATTERN_2:            
        gui_print_bordered_text((UI_string_type) L"VIB_PATTERN_2.");   
        break;
    case VIB_PATTERN_3:
        gui_print_bordered_text((UI_string_type) L"VIB_PATTERN_3."); 
        break;

    default:
        gui_print_bordered_text((UI_string_type) L"Error");  
        break;
    }
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*11);
    gui_print_bordered_text((UI_string_type) L"Pattern TYPE:");
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*12);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*12-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*13, GDI_COLOR_RED);// Debug.

    switch(type)
    {
    case PLAY_STOP :
        gui_print_bordered_text((UI_string_type) L"PLAY TYPE: STOP");
        break;
    case PLAY_REPEAT :
        gui_print_bordered_text((UI_string_type)L"PLAY TYPE: REPEAT");
        break;
    case PLAY_ONCE :
        gui_print_bordered_text((UI_string_type)L"PLAY TYPE: ONCE");
        break;
    default:
        gui_print_bordered_text((UI_string_type)L"PLAY TYPE:ERROR");    
        break;
    }
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); 
}

void vs_dev_gpio_speech_set_mode_volume_display_screen(dm_coordinates *coordinate)
{
    int cur_line =1;
    srv_speech_set_mode_volume();
    AVK_LOG_FUN(srv_speech_set_mode_volume,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"Set speech mode volume as");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"per model it means that");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"the current speech model's");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"volume(Normal model or ");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"Earphone model or ");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"Loadspeaker volume(Normal");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"model or model) will be");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*cur_line++);
    gui_print_bordered_text((UI_string_type) L"set as default volume ");
}

int gpio_device_enum_value_ = (sizeof(gpio_device_enum_value)/sizeof(gpio_device_enum_value[0]));

/* srv_gpio_set_device_level() */
void vs_dev_gpio_set_device_level_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(NULL, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_set_device_level_display_screen, NULL);
    StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_1S,vs_dev_gpio_set_device_level_add_callback);

	SetKeyHandler(vs_dev_gpio_set_device_level_add, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(vs_dev_gpio_set_device_level_sub, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

	SetKeyHandler(vs_dev_gpio_set_device_type_add, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(vs_dev_gpio_set_device_type_sub, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    AVK_SET_PASSKEY(avk_device_gpio_pen_up_hdlr);
    AVK_SET_FAILKEY(avk_device_gpio_pen_up_hdlr);	
    return;                                          
}
void vs_dev_gpio_set_device_level_add(void)
{
	StopTimer(TST_GPIO_TIMER_ID);
    if((U8)device_level.u_level+1<= LED_LIGHT_LEVEL5) // LED_LIGHT_LEVEL5 = 5
    {
        device_level.u_level++;
        srv_gpio_set_device_level((srv_gpio_dev_enum)gpio_device_enum_value_,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail((srv_gpio_dev_enum)gpio_device_enum_value_,device_level.u_level);
    }
}


void vs_dev_gpio_set_device_level_sub(void)
{
	StopTimer(TST_GPIO_TIMER_ID);
    if(device_level.u_level-1>= LED_LIGHT_LEVEL0) // LED_LIGHT_LEVEL0 = 0
    {
        device_level.u_level--;
        srv_gpio_set_device_level((srv_gpio_dev_enum)gpio_device_enum_value_,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail((srv_gpio_dev_enum)gpio_device_enum_value_,device_level.u_level);
    }
}



void vs_dev_gpio_set_device_type_add(void)
{
	StopTimer(TST_GPIO_TIMER_ID);
    if(gpio_device_enum_value_+1<= GPIO_DEV_FLASHLIGHT) // LED_LIGHT_LEVEL5 =		5
    {
        gpio_device_enum_value_+=1;
        srv_gpio_set_device_level((srv_gpio_dev_enum)gpio_device_enum_value_,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail((srv_gpio_dev_enum)gpio_device_enum_value_,device_level.u_level);
    }
}
void vs_dev_gpio_set_device_type_sub(void)
{
	StopTimer(TST_GPIO_TIMER_ID);
    if(gpio_device_enum_value_-1>= GPIO_DEV_LED_MAINLCD) // LED_LIGHT_LEVEL0 = 0
    {
        (gpio_device_enum_value_)-=1;
        srv_gpio_set_device_level((srv_gpio_dev_enum)gpio_device_enum_value_,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail((srv_gpio_dev_enum)gpio_device_enum_value_,device_level.u_level);
    }
}

void vs_dev_gpio_set_device_level_add_callback(void)
{
	
    if((U8)device_level.u_level+1<= LED_LIGHT_LEVEL5) // LED_LIGHT_LEVEL5 = 5
    {
        device_level.u_level++;
        srv_gpio_set_device_level((srv_gpio_dev_enum)device_level.e_device,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail(device_level.e_device,device_level.u_level);
        StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_1S,vs_dev_gpio_set_device_level_add_callback);
    }
    else
    {
        StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_1S,vs_dev_gpio_set_device_level_sub_callback);
    }
}
void vs_dev_gpio_set_device_level_sub_callback(void)
{
    if(device_level.u_level-1>= LED_LIGHT_LEVEL0) // LED_LIGHT_LEVEL0 = 0
    {
        device_level.u_level--;
        srv_gpio_set_device_level((srv_gpio_dev_enum)device_level.e_device,(srv_gpio_dev_level_enum)device_level.u_level);
        AVK_LOG_FUN(srv_gpio_set_device_level,AVK_PASS);
        vs_dev_gpio_set_device_level_device_draw_detail(device_level.e_device,device_level.u_level);
        if(device_level.u_level == 0)
        {
             StopTimer(TST_GPIO_TIMER_ID);
        }
        else
        {
            StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_1S,vs_dev_gpio_set_device_level_sub_callback);
        }
    }
}

void vs_dev_gpio_play_pattern_id_add(void)
{
    // tongzhibo delete here because VIB_PATTERN_4 has been deleted(2011-01-15 16:29)
//    if(g_play_pattern.pattern_id+1> VIB_PATTERN_4)
    if(g_play_pattern.pattern_id+1> VIB_PATTERN_3)
    {
        return ; // arrive the mix value
    }
    else if(g_play_pattern.pattern_id+1> LCD_PATTERN_2)
    {
        if(g_play_pattern.pattern_id >=  VIB_PATTERN_1)
            (U8)g_play_pattern.pattern_id ++;
        else
            g_play_pattern.pattern_id = VIB_PATTERN_1;
    }
    else if(g_play_pattern.pattern_id+1> LED_Roaming)
    {
        if(g_play_pattern.pattern_id ==  LCD_PATTERN_BEGIN)
            (U8)g_play_pattern.pattern_id ++;
        else
            g_play_pattern.pattern_id =  LCD_PATTERN_BEGIN;
    }
    else
    {
        (U8)g_play_pattern.pattern_id++;
    }
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
    vs_dev_gpio_play_pattern_draw_detail((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
}

void vs_dev_gpio_play_pattern_id_sub(void)
{
    if(g_play_pattern.pattern_id<=LED_POWER_ON)
    {
        return;
    }
    else if(g_play_pattern.pattern_id-1<=LCD_PATTERN_BEGIN)
    {
        if(g_play_pattern.pattern_id == LCD_PATTERN_1)
            g_play_pattern.pattern_id = LED_Roaming;
        else    
            (U8)g_play_pattern.pattern_id--;
    }
    else if(g_play_pattern.pattern_id-1<=VIB_PATTERN_BEGIN)
    {
        if(g_play_pattern.pattern_id == VIB_PATTERN_1)
            g_play_pattern.pattern_id = LCD_PATTERN_2;
        else    
            (U8)g_play_pattern.pattern_id--;
    }
    else
    {
        (U8)g_play_pattern.pattern_id--;
    }
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
    vs_dev_gpio_play_pattern_draw_detail((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
}

void vs_dev_gpio_play_pattern_type_add(void)
{
    if(g_play_pattern.pattern_type+1<= PLAY_ONCE)
    {
        g_play_pattern.pattern_type++;
        srv_gpio_play_pattern((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
        vs_dev_gpio_play_pattern_draw_detail((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
    }
}

void vs_dev_gpio_play_pattern_type_sub(void)
{
    if(g_play_pattern.pattern_type-1>= PLAY_STOP)
    {
        g_play_pattern.pattern_type--;
        srv_gpio_play_pattern((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
        vs_dev_gpio_play_pattern_draw_detail((srv_gpio_pattern_id_enum)g_play_pattern.pattern_id , (srv_gpio_pattern_type_enum)g_play_pattern.pattern_type);
    }
}


//srv_earphone_is_plug_in()
void vs_dev_gpio_earphone_is_plug_in_display_screen_enter(dm_coordinates *coordinate)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_earphone_is_plug_in_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);		
}

//srv_speech_is_phone_mute()
void vs_dev_gpio_speech_is_phone_mute_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_phone_is_mute_display_screen, NULL);   
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}

// srv_clam_is_close()
void vs_dev_gpio_clam_is_close_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_clam_is_close_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}

//srv_speech_disable_hand_free()
void vs_dev_gpio_speech_disable_hand_free_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_speech_disable_hand_free_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}
//srv_speech_enable_hand_free()
void vs_dev_gpio_speech_enable_hand_free_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_speech_enable_hand_free_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}
//srv_speech_mute_phone()
void vs_dev_gpio_speech_mute_phone_screen_enter(void)
{    
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_speech_mute_phone_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}
//srv_speech_unmute_phone()
void vs_dev_gpio_speech_unmute_phone_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_speech_unmute_phone_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}

//srv_gpio_play_pattern()
void vs_dev_gpio_play_pattern_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, (U16)AVK_STR_PASS, 0, (U16)AVK_STR_FAIL, 0, vs_dev_gpio_play_pattern_display_screen, NULL);

	SetKeyHandler(vs_dev_gpio_play_pattern_id_add,        KEY_UP_ARROW,   KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_play_pattern_id_sub,        KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_play_pattern_type_add,      KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_play_pattern_type_sub,      KEY_RIGHT_ARROW,KEY_EVENT_UP);
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
}

AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_01,	L"earphone_is_plug_in",		AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_02,	L"speech_is_phone_mute",	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_03,	L"clam_is_close",           	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_04,	L"set_device_level",        	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_05,	L"speech_disable_hand_free", AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_06,	L"speech_enable_hand_free", 	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_07,	L"speech_mute_phone",       	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_08,	L"speech_unmute_phone",     	AVK_DEVICE_GPIO)
AVK_ADD_ITEM(AVK_DEVICE_GPIO_MANUL_ITEM_09,	L"play_pattern",            	AVK_DEVICE_GPIO)


AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_001,AVK_DEVICE_GPIO_MANUL_ITEM_01){   vs_dev_gpio_earphone_is_plug_in_display_screen_enter(0);}
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_002,AVK_DEVICE_GPIO_MANUL_ITEM_02){	vs_dev_gpio_speech_is_phone_mute_screen_enter();        }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_003,AVK_DEVICE_GPIO_MANUL_ITEM_03){	vs_dev_gpio_clam_is_close_screen_enter();               }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_004,AVK_DEVICE_GPIO_MANUL_ITEM_04){	vs_dev_gpio_set_device_level_screen_enter();            }	// has some problem
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_005,AVK_DEVICE_GPIO_MANUL_ITEM_05){	vs_dev_gpio_speech_disable_hand_free_screen_enter();    }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_006,AVK_DEVICE_GPIO_MANUL_ITEM_06){	vs_dev_gpio_speech_enable_hand_free_screen_enter();     }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_007,AVK_DEVICE_GPIO_MANUL_ITEM_07){	vs_dev_gpio_speech_mute_phone_screen_enter();           }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_008,AVK_DEVICE_GPIO_MANUL_ITEM_08){	vs_dev_gpio_speech_unmute_phone_screen_enter();         }
AVK_MANUAL_CASE(AVK_DEVICE_GPIO_MANUL_009,AVK_DEVICE_GPIO_MANUL_ITEM_09){	vs_dev_gpio_play_pattern_screen_enter();                }

#ifdef __cplusplus
}
#endif

#endif

