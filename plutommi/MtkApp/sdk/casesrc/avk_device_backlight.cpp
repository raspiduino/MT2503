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
#include "avk_device_backlight.h"


// function map relationship
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

*/

#if defined(__MMI_MAINLCD_320X240__) 	   // WIDTH:320 && HEIGHT:240 (such as LION52)
    #define DRAW_TOP_Y 5
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 17			
#elif defined(__MMI_MAINLCD_320X480__) //WIDTH:320 && HEIGHT:480 (such as JADE36V2)
    #define DRAW_TOP_Y 75
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 25
#else                                  			   // default value (may be issue)
    #define DRAW_TOP_Y 75
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 25
#endif

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

int backlight_turn_on_value = 1;


/*
MMI_BOOL avk_device_BackLight_pen_up_hdlr(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point)
{
	if(MMI_PEN_EVENT_UP == pen_event){	
		GoBackHistory();
	}
	return MMI_TRUE;
} 
*/
void vs_dev_gpio_get_backlight_level_display_screen(void)
{
    U8 mainLCD_backlight_level		= 0;
    U8 subLCD_backlight_level		= 0;
    U8 keypadLCD_backlight_level    = 0;
    U8 temp_buffer_mainLCD[4]		= {0};   
    U8 temp_buffer_subLCD[4]		= {0};   
    U8 temp_buffer_keypadLCD[4]	= {0};    
    mainLCD_backlight_level		= srv_backlight_get_level(SRV_BACKLIGHT_TYPE_MAINLCD);
    subLCD_backlight_level			= srv_backlight_get_level(SRV_BACKLIGHT_TYPE_SUBLCD);
    keypadLCD_backlight_level		= srv_backlight_get_level(SRV_BACKLIGHT_TYPE_KEYPAD);
    AVK_LOG_FUN(srv_backlight_get_level,AVK_PASS);

    kal_wsprintf((WCHAR *)temp_buffer_mainLCD,       "%d",   mainLCD_backlight_level);
    kal_wsprintf((WCHAR *)temp_buffer_subLCD,         "%d",   subLCD_backlight_level);
    kal_wsprintf((WCHAR *)temp_buffer_keypadLCD,    "%d",   keypadLCD_backlight_level);

    // display title
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y); 
    gui_print_text((UI_string_type) L"gpio:get_backlight_level()");

    // show main LCD backlight level
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
    gui_print_bordered_text((UI_string_type) L"mainLCD_backlight_level:");
    mmi_fe_show_string_ext(DRAW_TOP_X,DRAW_TOP_Y+DISTANCE_TWO_LINE*3,temp_buffer_mainLCD);

    // show sub LCD backlight level
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"subLCD_backlight_level:");
    mmi_fe_show_string_ext(DRAW_TOP_X,DRAW_TOP_Y+DISTANCE_TWO_LINE*5,temp_buffer_subLCD);

    // show keypad LCD backlight level
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"keypadLCD_backlight_level:");
    mmi_fe_show_string_ext(DRAW_TOP_X,DRAW_TOP_Y+DISTANCE_TWO_LINE*7,temp_buffer_keypadLCD);

    return ;
}

void vs_dev_gpio_backlight_is_on_display_screen(dm_coordinates *coordinate)    
{
    MMI_BOOL b_mainlcd_is_on    = MMI_FALSE;
#ifdef __MMI_SUBLCD__
    MMI_BOOL b_sublcd_is_on     = MMI_FALSE;
#endif
    MMI_BOOL b_keypad_is_on     = MMI_FALSE;
    WCHAR * FALSE_pointer       = (WCHAR*)L"FALSE";
    WCHAR * TRUE_pointer        = (WCHAR*)L"TRUE";
    b_mainlcd_is_on             = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);  /* FALSE = dark,TRUE = full light or half light */
#ifdef __MMI_SUBLCD__
    b_sublcd_is_on              = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_SUBLCD);     /* FALSE = dark,TRUE = full light or half light */
#endif
    b_keypad_is_on              = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_KEYPAD);    /* FALSE = dark,TRUE = full light or half light */

    AVK_LOG_FUN(srv_backlight_is_on,AVK_PASS);

    // show main LCD backlight status
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
    gui_print_bordered_text((UI_string_type) L"mainLCD_backlight_is_on?:");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);     
    gui_print_bordered_text((UI_string_type) ((b_mainlcd_is_on != 0)? TRUE_pointer:FALSE_pointer));

    // show sub LCD backlight status
#ifdef __MMI_SUBLCD__
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"subLCD_backlight_is_on?:");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);     
    gui_print_bordered_text((UI_string_type) ((b_sublcd_is_on != 0)? TRUE_pointer:FALSE_pointer));    
#endif

    // show keypad LCD backlight status
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"keypadLCD_backlight_is_on?:");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);     
    gui_print_bordered_text((UI_string_type) ((b_keypad_is_on != 0)? TRUE_pointer:FALSE_pointer));        

    return ;
}

//void vs_dev_gpio_backlight_get_hf_time_display_screen(dm_coordinates *coordinate)    
void vs_dev_gpio_backlight_get_hf_time_display_screen(dm_coordinates *coordinate)    
{
    S32 hf_time = 0;
    S32 time[4]       = {0};   
    hf_time = srv_backlight_get_hf_time();
    AVK_LOG_FUN(srv_backlight_get_hf_time,AVK_PASS);
    kal_wsprintf((WCHAR *)time,       "%d",   hf_time);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"backlight_get_hf_time = :");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);     
    gui_print_bordered_text((UI_string_type)(time));        
}

void vs_dev_gpio_backlight_is_lcd_sleep_mode_display_screen(dm_coordinates *coordinate)
{
    MMI_BOOL b_lcd_sleep = MMI_FALSE;
    b_lcd_sleep = srv_backlight_is_lcd_sleep();
    AVK_LOG_FUN(srv_backlight_is_lcd_sleep,AVK_PASS);

    // display title
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y); 
    gui_print_bordered_text((UI_string_type) L"backlight mode:");
    if(b_lcd_sleep) // sleep mode
    {   
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"backlight is sleep mode");
    }
    else  // NOT sleep mode
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"backlight is not sleep mode");
    }
}

void vs_dev_gpio_backlight_get_timer_state_display_screen(dm_coordinates *coordinate)
{
    U32 backlight_timer_state = srv_backlight_get_timer_state();
    AVK_LOG_FUN(srv_backlight_get_timer_state,AVK_PASS);

    // display title
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    if(SRV_BACKLIGHT_TIMER_STATE_NO_TIMER == backlight_timer_state) 
    {   
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"TIMER_STATE: ");
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3); 
        gui_print_bordered_text((UI_string_type) L"  NO_TIMER");
    }
    else if(SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE == backlight_timer_state) 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"TIMER_STATE: ");
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3); 
        gui_print_bordered_text((UI_string_type) L"  HALF_MODE");
    }
    else if(SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE == backlight_timer_state) 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"TIMER_STATE: ");
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3); 
        gui_print_bordered_text((UI_string_type) L"  FOR SLEEP_MODE");
    }
    else if(SRV_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE == backlight_timer_state) 
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"TIMER_STATE: ");
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3); 
        gui_print_bordered_text((UI_string_type) L"  IN SLEEP_MODE");
    }
    else // error
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2); 
        gui_print_bordered_text((UI_string_type) L"Get Timer Status ERROR");
    }	
}

void vs_dev_gpio_backlight_close_display_screen(dm_coordinates *coordinate)
{
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"after 3 seconds we will");    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gui_print_bordered_text((UI_string_type) L"Immediate Close Baclight ");    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Not going thru Half Mode "); 

	gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);
    gui_print_bordered_text((UI_string_type) L"--------------------------"); 

	gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    gui_print_bordered_text((UI_string_type) L"And then after 3 seconds ");    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gui_print_bordered_text((UI_string_type) L"the backlight will be turn on."); 
}

void vs_dev_gpio_backlight_open_callback(void)
{
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    StopTimer(TST_GPIO_TIMER_ID);
}

void vs_dev_gpio_backlight_close_callback(void)
{
    srv_backlight_close();
    StopTimer(TST_GPIO_TIMER_ID);
    StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_3S,vs_dev_gpio_backlight_open_callback);
}

void vs_dev_gpio_backlight_turn_off_keypad_light_display_screen(dm_coordinates *coordinate)
{
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"after 3s Turn Off Keypad Light");    
    StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_3S,vs_dev_gpio_backlight_turn_off_keypad_light_callback);
}

void vs_dev_gpio_backlight_turn_off_keypad_light_callback(void)
{
    srv_backlight_turn_off_keypad_light();
    AVK_LOG_FUN(srv_backlight_turn_off_keypad_light,AVK_PASS);
    StopTimer(TST_GPIO_TIMER_ID);
}

void vs_dev_gpio_backlight_half_mode_display_screen(dm_coordinates *coordinate)
{
    srv_backlight_half_mode();
    AVK_LOG_FUN(srv_backlight_half_mode,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2);
    gui_print_bordered_text((UI_string_type) L"Takes the Backlight to");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"Half Mode.(Backlit is");    

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"dimmed but not black)");
}

void vs_dev_gpio_backlight_turn_on_display_screen_draw_details()
{
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*10-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*11, GDI_COLOR_RED);// Debug.
	
    switch(backlight_turn_on_value)
    {
    case GPIO_DEV_LED_MAINLCD:
		gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*10);
        gui_print_bordered_text((UI_string_type) L"1.Permanent ");
        break;
    case GPIO_DEV_LED_SUBLCD:
		gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*10);
        gui_print_bordered_text((UI_string_type) L"2.Short Time ");
        break;
    default:
        break;
    }
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD	
}

void vs_dev_gpio_backlight_turn_on_display_screen(dm_coordinates *coordinate)
{
    int row = 0;
	srv_backlight_turn_off();
    srv_backlight_turn_on((srv_backlight_timer_type_enum)backlight_turn_on_value);
    AVK_LOG_FUN(srv_backlight_turn_on,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*row);
    gui_print_bordered_text((UI_string_type) L"USER GUIDE");
    gui_set_text_border_color(gui_color(0, 0, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"BackLight has two type");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"1.Permanent:");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"backlith will never dimmed");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"or black");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"2.Short_time:");    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"Backlith will dimmed first");
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"finally black in a short time");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"(default is short time mode)");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"LEFT/RIGHT key change type");
	
	vs_dev_gpio_backlight_turn_on_display_screen_draw_details();
}

void vs_dev_gpio_backlight_turn_on_permanent(void)
{
    int row = 10;
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    AVK_LOG_FUN(srv_backlight_turn_on,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*row);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*row-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*(row+1), GDI_COLOR_RED);// refurbish
    gui_print_bordered_text((UI_string_type) L"Current tpye: Permanent");

    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
}
void vs_dev_gpio_backlight_turn_off(void)
{
    int row = 10;
    srv_backlight_turn_off();
    AVK_LOG_FUN(srv_backlight_turn_off,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    /*    
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*(++row));
    gui_print_bordered_text((UI_string_type) L"LEFT/RIGHT key change type");
    */
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*row);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*row-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*(row+1), GDI_COLOR_RED);// refurbish
    gui_print_bordered_text((UI_string_type) L"Current tpye: turn off");
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
}
/**********************************************************************************************/

void vs_dev_gpio_play_vibrate_display_screen(srv_gpio_pattern_id_enum pattern_id,srv_gpio_pattern_type_enum pattern_type)
{
    srv_gpio_play_vibrate(pattern_id,pattern_type);
    AVK_LOG_FUN(srv_gpio_play_vibrate,AVK_PASS);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*2);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*6);
    gui_print_bordered_text((UI_string_type) L"Pattern ID: ");    

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*9);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*10);

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*11);
    gui_print_bordered_text((UI_string_type) L"Pattern Type: ");

    vs_dev_gpio_play_vibrate_draw_detail(pattern_id,pattern_type);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);				
}
void vs_dev_gpio_play_vibrate_draw_detail(srv_gpio_pattern_id_enum id, srv_gpio_pattern_type_enum type)
{
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*7);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*7-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*8, GDI_COLOR_RED);// Debug.

    switch(id)
    {
    case VIB_PATTERN_1:
        gui_print_bordered_text((UI_string_type) L"Vib pattern 1.");  
        break;
    case VIB_PATTERN_2:
        gui_print_bordered_text((UI_string_type) L"Vib pattern 2.");  
        break;
    case VIB_PATTERN_3:            
        gui_print_bordered_text((UI_string_type) L"Vib pattern 3.");  
        break;
    default:
        gui_print_bordered_text((UI_string_type) L"Vib pattern Error");
        break;
    }
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
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD
}


void vs_dev_gpio_backlight_turn_on_left_key_handler(void)
{
    if( SRV_BACKLIGHT_PERMANENT==(srv_backlight_timer_type_enum)backlight_turn_on_value) // 0 ==backlight_turn_on_value
    {
        backlight_turn_on_value+=1;
        srv_backlight_turn_off();
		srv_backlight_turn_on((srv_backlight_timer_type_enum)backlight_turn_on_value); 
		vs_dev_gpio_backlight_turn_on_display_screen_draw_details();
    }
}
void vs_dev_gpio_backlight_turn_on_right_key_handler(void)
{
    if( SRV_BACKLIGHT_SHORT_TIME==(srv_backlight_timer_type_enum)backlight_turn_on_value) // 0 ==backlight_turn_on_value
    {
        backlight_turn_on_value-=1;

		srv_backlight_turn_on((srv_backlight_timer_type_enum)backlight_turn_on_value);
		vs_dev_gpio_backlight_turn_on_display_screen_draw_details();
    }
}


/*************************************************************************************************/

//srv_gpio_play_vibrate()
void vs_dev_gpio_play_vibrate_screen_enter(srv_gpio_pattern_id_enum pattern_id,srv_gpio_pattern_type_enum pattern_type)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0,NULL , NULL);
    vs_dev_gpio_play_vibrate_display_screen( pattern_id, pattern_type);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	                                       
}

//srv_backlight_is_on()
void vs_dev_gpio_backlight_is_on_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_is_on_display_screen, NULL);	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);                      
}
//srv_backlight_get_hf_time()
void vs_dev_gpio_backlight_get_hf_time_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_get_hf_time_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);               
}
//srv_backlight_is_lcd_sleep()
void vs_dev_gpio_backlight_is_lcd_sleep_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_is_lcd_sleep_mode_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

//srv_backlight_get_timer_state()
void vs_dev_gpio_backlight_get_timer_state_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_get_timer_state_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

//srv_backlight_close()
void vs_dev_gpio_backlight_close_screen_enter(void)
{
    U8 *gui_buffer;
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, vs_dev_gpio_backlight_close_screen_enter, MMI_FRM_FULL_SCRN);
	gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_close_display_screen, NULL);
	if (gui_buffer == NULL)
	{
		StartTimer(TST_GPIO_TIMER_ID,TST_GPIO_TIMER_DELAY_3S,vs_dev_gpio_backlight_close_callback);
	}
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}
//srv_backlight_turn_off_keypad_light()
void vs_dev_gpio_backlight_turn_off_keypad_light_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_turn_off_keypad_light_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}
//srv_backlight_half_mode()
void vs_dev_gpio_backlight_half_mode_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_half_mode_display_screen, NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}
//srv_backlight_turn_on()
void vs_dev_gpio_backlight_turn_on_screen_exit_proc(void)
{
    if(0 == backlight_turn_on_value)
    {
        backlight_turn_on_value+=1;
        srv_backlight_turn_off();
		srv_backlight_turn_on((srv_backlight_timer_type_enum)backlight_turn_on_value); 
    }
}
void vs_dev_gpio_backlight_turn_on_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, (FuncPtr)vs_dev_gpio_backlight_turn_on_screen_exit_proc, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, AVK_STR_PASS, 0, AVK_STR_FAIL, 0, vs_dev_gpio_backlight_turn_on_display_screen, NULL);

	SetKeyHandler(vs_dev_gpio_backlight_turn_on_left_key_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(vs_dev_gpio_backlight_turn_on_right_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

/************************************** Dot motify the flowing Macro ************************************/
#ifdef __cplusplus
}
#endif

#endif





/* AVK new Framework menu tree */
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM,   L"BackLight",AVK_DEVICE_BACKLIGHT)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_ITEM,    L"Vibrator",AVK_DEVICE_BACKLIGHT)

AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_001,   L"BackLight_001",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_002,   L"BackLight_002",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_003,   L"BackLight_003",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_004,   L"BackLight_004",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_005,   L"BackLight_005",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_006,   L"BackLight_006",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_007,   L"BackLight_007",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_BACKLIGHT_MANUL_ITEM_008,   L"BackLight_008",AVK_DEVICE_BACKLIGHT_MANUL_ITEM)

AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_1,	L"Vib_pattern1_stop", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_2,  L"Vib_pattern1_repeat", AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_3,  L"Vib_pattern1_once", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_1,	L"Vib_pattern2_stop", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_2, 	L"Vib_pattern2_repeat", AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_3,	L"Vib_pattern2_once", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_1,	L"Vib_pattern3_stop", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_2, 	L"Vib_pattern3_repeat", AVK_DEVICE_VIBRATOR_MANUL_ITEM)
AVK_ADD_ITEM(AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_3,	L"Vib_pattern3_once", 	AVK_DEVICE_VIBRATOR_MANUL_ITEM)




AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_001,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_001){	vs_dev_gpio_backlight_get_timer_state_screen_enter();}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_002,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_002){	vs_dev_gpio_backlight_is_on_screen_enter();					}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_003,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_003){	vs_dev_gpio_backlight_get_hf_time_screen_enter();			}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_004,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_004){	vs_dev_gpio_backlight_is_lcd_sleep_screen_enter();			}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_006,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_005){	vs_dev_gpio_backlight_close_screen_enter();					}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_007,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_006){	vs_dev_gpio_backlight_turn_off_keypad_light_screen_enter();	}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_008,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_007){	vs_dev_gpio_backlight_half_mode_screen_enter();				}
AVK_MANUAL_CASE(AVK_DEVICE_BACKLIGHT_MANUL_009,AVK_DEVICE_BACKLIGHT_MANUL_ITEM_008){	vs_dev_gpio_backlight_turn_on_screen_enter();				}

AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_001,AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_1)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_1,PLAY_STOP);	    }
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_002,AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_2)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_1,PLAY_REPEAT);	}
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_003,AVK_DEVICE_VIBRATOR_MANUL_PATTERN1_3)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_1,PLAY_ONCE);	    }
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_004,AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_1)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_2,PLAY_STOP);	    }
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_005,AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_2)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_2,PLAY_REPEAT);	}
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_006,AVK_DEVICE_VIBRATOR_MANUL_PATTERN2_3)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_2,PLAY_ONCE);	    }
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_007,AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_1)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_3,PLAY_STOP);	    }
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_008,AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_2)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_3,PLAY_REPEAT);	}
AVK_MANUAL_CASE(AVK_DEVICE_VIBRATOR_MANUL_009,AVK_DEVICE_VIBRATOR_MANUL_PATTERN3_3)	{	vs_dev_gpio_play_vibrate_screen_enter(VIB_PATTERN_3,PLAY_ONCE);	    }





