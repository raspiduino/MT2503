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
*   tst_DevProfile.c
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
* -------Zhibo.tong(mtk80982)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MAUI_SDK_TEST__

#ifndef LOW_COST_SUPPORT


#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************************************/ 
/* NON SDK API */
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "FileMgrGProt.h"
#include "SettingProfile.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"

/* internal */
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_multimedia.h"
#include "avk_setting_DevProfile.h"

/* timer define */
#ifndef AVK_SETTING_DEVICE_PROFILE_TIMER_ID
#define AVK_SETTING_DEVICE_PROFILE_TIMER_ID KEY_TIMER_ID_NONE
#endif

#ifndef AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_1S
#define AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_1S  1*1000
#endif

#ifndef AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_2S
#define AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_2S  2*1000
#endif

#ifndef AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_3S
#define AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_3S  3*1000
#endif

void vs_mm_dev_profile_get_value_string_display_screen(srv_dev_profile_category_enum category);
void vs_mm_dev_profile_get_value_int_display_screen();

void vs_mm_srv_dev_profile_get_value_string_category_add(void);
void vs_mm_srv_dev_profile_get_value_string_category_sub(void);
void vs_mm_dev_profile_get_value_int_category_add(void);
void vs_mm_dev_profile_get_value_int_category_sub(void);

void vs_mm_dev_profile_display_screen_draw_discreption(void);
void vs_mm_dev_profile_display_screen_set_discreption_info(void);
void vs_mm_dev_profile_get_value_int_draw_detail();

MMI_BOOL avk_setting_devProfile_pen_up_hdlr(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point);

MMI_BOOL avk_setting_devProfile_pen_up_hdlr(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point)
{
//	GoBackHistory();
	return MMI_TRUE;
}
static const  int dev_prof_get_string_table_array[] =
{
    dev_profile_platform,               	
    dev_profile_hw_version,            	
    dev_profile_mmi_base,               	
    dev_profile_mmi_version,          	
    dev_profile_current_language,		
};

static const int  dev_prof_get_value_table_array[] =
{
    // 9
    dev_profile_keypad_support,		
    dev_profile_touch_support,          	
    dev_profile_handwriting_support,    
    dev_profile_figer_touch_support, 
    dev_profile_jogball_support, 
    dev_profile_sublcd_key_support,
    dev_profile_mainlcd_width,
    dev_profile_mainlcd_height, 
    dev_profile_sublcd_width, 
    dev_profile_sublcd_height, 
    // 19
    dev_profile_screen_rotate_support, 
    dev_profile_landscape_support, 
    dev_profile_landscape_support_on_portait_lcm,
    dev_profile_heorizontal_camera_support, 
    dev_profile_camera_support, 
    dev_profile_sub_camera_support, 
    dev_profile_sub_camera_rotate_support, 
    dev_profile_webcamera_support, 
    dev_profile_dual_camera_support, 
    dev_profile_fm_radio_enable, 
    // 29
    dev_profile_fm_radio_record_support, 
    dev_profile_fm_radio_bind_earphone, 
    dev_profile_camcorder_support, 
    dev_profile_mediaplay_support, 
    dev_profile_mediaplay_is_playing, 
    dev_profile_kuro_support, 
    dev_profile_mediaplay_show_lyric, 
    dev_profile_audio_player_support, 
    dev_profile_audio_player_show_lyric, 
    dev_profile_mediawall_support, 
    // 39
    dev_profile_photoeditor_support, 
    dev_profile_video_player_support, 
    dev_profile_video_record_support, 
    dev_profile_meidacache_support, 
    dev_profile_slideshow_support, 
    dev_profile_motion_sensor_support, 
    dev_profile_java_support, 
    dev_profile_java_background_support, 
    dev_profile_java_statues_on, 
    dev_profile_mre_support, 
    // 49
    dev_profile_mre_memory_size, 
    dev_profile_support_lanuage_num, 
    dev_profile_gprs_support, 
    dev_profile_tcpip_support, 
    dev_profile_wifi_support, 
    dev_profile_wifi_status_is_on, 
    dev_profile_bt_support, 
    dev_profile_bt_status_is_on, 
    dev_profile_gps_support, 
    dev_profile_agps_support,
    // 59
    dev_profile_dual_sim_support,
    dev_profile_network_intensity, 
    dev_profile_battery_intensity, 
    dev_profile_usb_support, 
    dev_profile_mms_enable,
    dev_profile_email_enable, 
    dev_profile_background_sms_enable, 
    dev_profile_unifined_message_enable, 
    dev_profile_sms_phone_max_item, 
    dev_profile_sms_sim_max_item, 
    // 69
    dev_profile_phb_option_field_enable,
    dev_profile_phb_option_email_enable, 
    dev_profile_phb_birthday_field_enable, 
    dev_profile_phb_info_field_enable, 
    dev_profile_phb_phone_max_item, 
    dev_profile_phb_sim_max_item, 
    dev_profile_ram_usage, 
    dev_profile_keypad_type,
    dev_profile_imageview_version, 
    dev_profile_input_method,
    // 77
    dev_profile_browser_type,
    dev_profile_mre_version,
    dev_profile_mre_memory_provide,
    dev_profile_jpg_decode_type,
    dev_profile_jpg_encode_type,
    dev_profile_gif_decode_type,
    dev_profile_png_decode_type,
    dev_profile_font_engine_type,
};

int glb_srv_dev_prof_get_string_table_array_index  = 0;
int glb_srv_dev_prof_get_value_table_arrayindex = 0;

void avk_setting_devProfile_callback(void)
{
    glb_srv_dev_prof_get_value_table_arrayindex ++;
//    int a = (sizeof(dev_prof_get_value_table_array)/sizeof(dev_prof_get_value_table_array[0]));
    if (glb_srv_dev_prof_get_value_table_arrayindex < (sizeof(dev_prof_get_value_table_array)/sizeof(dev_prof_get_value_table_array[0])))
    {
        vs_mm_dev_profile_get_value_int_draw_detail();		
    }
    else
    {
	StopTimer(AVK_SETTING_DEVICE_PROFILE_TIMER_ID);
	AVK_CASE_RESULT(AVK_PASS);
    }
}

void avk_setting_devProfile_stop_callback(void)
{
	StopTimer(AVK_SETTING_DEVICE_PROFILE_TIMER_ID);
	AVK_CASE_RESULT(AVK_PASS);
}

void srv_dev_profile_get_value_notify_user(srv_dev_profile_category_enum category)
{
    switch(category)
    {
        /* string */ 
    case dev_profile_platform:
        gui_print_bordered_text((UI_string_type) L"platform:");   
        break;
    case dev_profile_hw_version:
        gui_print_bordered_text((UI_string_type) L"hw version:");   
        break;
    case dev_profile_mmi_base:             
        gui_print_bordered_text((UI_string_type) L"mmi base:");   
        break;
    case dev_profile_mmi_version:
        gui_print_bordered_text((UI_string_type) L"mmi version:");   
        break;
    case dev_profile_current_language:
        gui_print_bordered_text((UI_string_type) L"current language:");   
        break;
    case dev_profile_keypad_support:
        gui_print_bordered_text((UI_string_type) L"keypad support:");   
        break;
    case dev_profile_touch_support:
        gui_print_bordered_text((UI_string_type) L"touch_support:");   
        break;
    case dev_profile_handwriting_support:  
        gui_print_bordered_text((UI_string_type) L"handwriting support:");   
        break;
    case dev_profile_figer_touch_support:
        gui_print_bordered_text((UI_string_type) L"figer touch support:");   
        break;
    case dev_profile_jogball_support:
        gui_print_bordered_text((UI_string_type) L"jogball support:");   
        break;
    case dev_profile_sublcd_key_support:
        gui_print_bordered_text((UI_string_type) L"sublcd key support:");   
        break;
    case dev_profile_mainlcd_width:
        gui_print_bordered_text((UI_string_type) L"mainlcd width is:");   
        break;
    case dev_profile_mainlcd_height:
        gui_print_bordered_text((UI_string_type) L"mainlcd height:");   
        break;
    case dev_profile_sublcd_width:
        gui_print_bordered_text((UI_string_type) L"sublcd width:");   
        break;
    case dev_profile_sublcd_height:
        gui_print_bordered_text((UI_string_type) L"sublcd height:");   
        break;
    case dev_profile_screen_rotate_support:
        gui_print_bordered_text((UI_string_type) L"screen rotate support:");   
        break;
    case dev_profile_landscape_support:
        gui_print_bordered_text((UI_string_type) L"landscape support:");   
        break;
    case dev_profile_landscape_support_on_portait_lcm:
        gui_print_bordered_text((UI_string_type) L"landscape support on portait lcm:");   
        break;
    case dev_profile_heorizontal_camera_support:
        gui_print_bordered_text((UI_string_type) L"heorizontal camera support:");   
        break;
    case dev_profile_camera_support:
        gui_print_bordered_text((UI_string_type) L"camera support:");   
        break;
    case dev_profile_sub_camera_support:
        gui_print_bordered_text((UI_string_type) L"sub camera support:");   
        break;
    case dev_profile_sub_camera_rotate_support:
        gui_print_bordered_text((UI_string_type) L"sub camera rotate support:");   
        break;
    case dev_profile_webcamera_support:
        gui_print_bordered_text((UI_string_type) L"webcamera support:");   
        break;
    case dev_profile_dual_camera_support:
        gui_print_bordered_text((UI_string_type) L"dual camera support:");   
        break;
    case dev_profile_fm_radio_enable:
        gui_print_bordered_text((UI_string_type) L"fm radio enable:");   
        break;
    case dev_profile_fm_radio_record_support: 
        gui_print_bordered_text((UI_string_type) L"radio record support:");   
        break;
    case dev_profile_fm_radio_bind_earphone:
        gui_print_bordered_text((UI_string_type) L"radio bind earphone:");   
        break;
    case dev_profile_camcorder_support: 
        gui_print_bordered_text((UI_string_type) L"camcorder support:");   
        break;
    case dev_profile_mediaplay_support:
        gui_print_bordered_text((UI_string_type) L"mediaplay support:");   
        break;
    case dev_profile_mediaplay_is_playing:
        gui_print_bordered_text((UI_string_type) L"mediaplay is playing:");   
        break;
    case dev_profile_kuro_support:
        gui_print_bordered_text((UI_string_type) L"kuro support:");   
        break;
    case dev_profile_mediaplay_show_lyric: 
        gui_print_bordered_text((UI_string_type) L"mediaplay show lyric:");   
        break;
    case dev_profile_audio_player_support:
        gui_print_bordered_text((UI_string_type) L"audio player support:");   
        break;
    case dev_profile_audio_player_show_lyric:
        gui_print_bordered_text((UI_string_type) L"audio player show lyric:");   
        break;
    case dev_profile_mediawall_support:
        gui_print_bordered_text((UI_string_type) L"mediawall support:");   
        break;
    case dev_profile_photoeditor_support:
        gui_print_bordered_text((UI_string_type) L"photoeditor support:");   
        break;
    case dev_profile_video_player_support: 
        gui_print_bordered_text((UI_string_type) L"video player support:");   
        break;
    case dev_profile_video_record_support: 
        gui_print_bordered_text((UI_string_type) L"video record support:");   
        break;
    case dev_profile_meidacache_support: 
        gui_print_bordered_text((UI_string_type) L"meidacache support:");   
        break;
    case dev_profile_slideshow_support:
        gui_print_bordered_text((UI_string_type) L"slideshow support:");   
        break;
    case dev_profile_motion_sensor_support:
        gui_print_bordered_text((UI_string_type) L"motion sensor support?");   
        break;
    case dev_profile_java_support:
        gui_print_bordered_text((UI_string_type) L"java support?");   
        break;
    case dev_profile_java_background_support:
        gui_print_bordered_text((UI_string_type) L"java background support?");   
        break;
    case dev_profile_java_statues_on:
        gui_print_bordered_text((UI_string_type) L"java statues on?");   
        break;
    case dev_profile_mre_support:
        gui_print_bordered_text((UI_string_type) L"mre support?");   
        break;
    case dev_profile_mre_memory_size:
        gui_print_bordered_text((UI_string_type) L"mre memory size?");   
        break;
    case dev_profile_support_lanuage_num:
        gui_print_bordered_text((UI_string_type) L"support lanuage num?");   
        break;
    case dev_profile_gprs_support:
        gui_print_bordered_text((UI_string_type) L"gprs support?");   
        break;
    case dev_profile_tcpip_support: 
        gui_print_bordered_text((UI_string_type) L"tcpip support?");   
        break;
    case dev_profile_wifi_support:
        gui_print_bordered_text((UI_string_type) L"wifi support?");   
        break;
    case dev_profile_wifi_status_is_on:
        gui_print_bordered_text((UI_string_type) L"wifi status is on?");   
        break;
    case dev_profile_bt_support:
        gui_print_bordered_text((UI_string_type) L"bt support?");   
        break;
    case dev_profile_bt_status_is_on:
        gui_print_bordered_text((UI_string_type) L"bt status is on?");   
        break;
    case dev_profile_gps_support:
        gui_print_bordered_text((UI_string_type) L"gps support?");   
        break;
    case dev_profile_agps_support:
        gui_print_bordered_text((UI_string_type) L"agps support?");   
        break;
    case dev_profile_dual_sim_support:
        gui_print_bordered_text((UI_string_type) L"dual sim support?");   
        break;
    case dev_profile_network_intensity: 
        gui_print_bordered_text((UI_string_type) L"network intensity?");   
        break;
    case dev_profile_battery_intensity:
        gui_print_bordered_text((UI_string_type) L"battery intensity?");   
        break;
    case dev_profile_usb_support: 
        gui_print_bordered_text((UI_string_type) L"usb support?");   
        break;
    case dev_profile_mms_enable:
        gui_print_bordered_text((UI_string_type) L"mms enable?");   
        break;
    case dev_profile_email_enable:
        gui_print_bordered_text((UI_string_type) L"email enable?");   
        break;
    case dev_profile_background_sms_enable:
        gui_print_bordered_text((UI_string_type) L"background sms enable?");   
        break;
    case dev_profile_unifined_message_enable: 
        gui_print_bordered_text((UI_string_type) L"unifined message enable?");   
        break;
    case dev_profile_sms_phone_max_item:
        gui_print_bordered_text((UI_string_type) L"sms phone max item?");   
        break;
    case dev_profile_sms_sim_max_item:
        gui_print_bordered_text((UI_string_type) L"sms sim max item?");   
        break;
    case dev_profile_phb_option_field_enable:
        gui_print_bordered_text((UI_string_type) L"phb option field enable?");   
        break;
    case dev_profile_phb_option_email_enable:
        gui_print_bordered_text((UI_string_type) L"phb option email enable?");   
        break;
    case dev_profile_phb_birthday_field_enable:
        gui_print_bordered_text((UI_string_type) L"phb birthday field enable?");   
        break;
    case dev_profile_phb_info_field_enable:
        gui_print_bordered_text((UI_string_type) L"phb info field enable?");   
        break;
    case dev_profile_phb_phone_max_item:
        gui_print_bordered_text((UI_string_type) L"phb phone max item?");   
        break;
    case dev_profile_phb_sim_max_item:
        gui_print_bordered_text((UI_string_type) L"phb sim max item?");   
        break;
    case dev_profile_ram_usage:
        gui_print_bordered_text((UI_string_type) L"ram usage?");   
        break;
    case dev_profile_keypad_type:
        gui_print_bordered_text((UI_string_type) L"keypad type?");   
        break;
    case dev_profile_imageview_version:
        gui_print_bordered_text((UI_string_type) L"imageview version?");   
        break;
    case dev_profile_input_method:
        gui_print_bordered_text((UI_string_type) L"input method?");   
        break;
    case dev_profile_browser_type:
        gui_print_bordered_text((UI_string_type) L"browser type?");   
        break;
    case dev_profile_mre_version:
        gui_print_bordered_text((UI_string_type) L"mre version?");   
        break;
    case dev_profile_mre_memory_provide:
        gui_print_bordered_text((UI_string_type) L"mre memory provide?");   
        break;
    case dev_profile_jpg_decode_type:
        gui_print_bordered_text((UI_string_type) L"jpg decode type?");   
        break;
    case dev_profile_jpg_encode_type:
        gui_print_bordered_text((UI_string_type) L"jpg encode type?");   
        break;
    case dev_profile_gif_decode_type:
        gui_print_bordered_text((UI_string_type) L"gif decode type?");   
        break;
    case dev_profile_png_decode_type:
        gui_print_bordered_text((UI_string_type) L"png decode type?");   
        break;
    case dev_profile_font_engine_type:
        gui_print_bordered_text((UI_string_type) L"font engine type?");   
        break;
    default:
        break;
    } 
}

void vs_mm_dev_profile_get_value_string_screen_enter(srv_dev_profile_category_enum category)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, (U16)AVK_STR_PASS, 0, (U16)AVK_STR_FAIL, 0, NULL, NULL);
    vs_mm_dev_profile_get_value_string_display_screen(category);
}

void vs_mm_dev_profile_get_value_int_screen_enter(void)
{
    mmi_frm_scrn_enter(GRP_ID_AVK, NULL, NULL, NULL, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen((U8 *)0, 0, (U16)AVK_STR_PASS, 0, (U16)AVK_STR_FAIL, 0, NULL, NULL);
    vs_mm_dev_profile_get_value_int_display_screen();
}

void vs_mm_dev_profile_get_value_string_draw_detail(srv_dev_profile_category_enum category)
{
    const CHAR * p = srv_dev_profile_get_value_string(category);    
    AVK_LOG_FUN(srv_dev_profile_get_value_string,AVK_PASS);	
    U8 dis_buf[VS_MM_BUFFER_SIZE] = {0};
    U8 dis_str[VS_MM_BUFFER_SIZE] = {0};
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);
    if(' '!= *p)
    {
        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
        gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*5-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*6, GDI_COLOR_RED);// Debug.
        srv_dev_profile_get_value_notify_user(category);
        gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD

        gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);        
        sprintf((CHAR*) dis_buf, (CHAR*) "= %s", p);
        mmi_asc_to_wcs((U16*) dis_str, (CHAR*) dis_buf);
        gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*8-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*9, GDI_COLOR_RED);// Debug.
        gui_print_text((UI_string_type) dis_str);
        gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD    
    }
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);	
//    StartTimer(AVK_SETTING_DEVICE_PROFILE_TIMER_ID,AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_2S,avk_setting_devProfile_stop_callback);
    
}

void vs_mm_dev_profile_get_value_int_draw_detail()
{
    U16 value =0;
    U8 dis_buf[VS_MM_BUFFER_SIZE] = {0};
    U8 dis_str[VS_MM_BUFFER_SIZE] = {0};
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    value = srv_dev_profile_get_value_int((srv_dev_profile_category_enum)dev_prof_get_value_table_array[glb_srv_dev_prof_get_value_table_arrayindex]);
    AVK_LOG_FUN(srv_dev_profile_get_value_int,AVK_PASS);
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*5);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*5-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*6+10, GDI_COLOR_RED);// Debug.
    srv_dev_profile_get_value_notify_user((srv_dev_profile_category_enum)dev_prof_get_value_table_array[glb_srv_dev_prof_get_value_table_arrayindex]);
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*8);
    sprintf((CHAR*) dis_buf, (CHAR*) "= %d", value);
    mmi_asc_to_wcs((U16*) dis_str, (CHAR*) dis_buf);
    gdi_draw_solid_rect(0, DRAW_TOP_Y+DISTANCE_TWO_LINE*8-5,UI_DEVICE_WIDTH, DRAW_TOP_Y+DISTANCE_TWO_LINE*9+5, GDI_COLOR_RED);// Debug.
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT); // must blt the screen otherwise nothing will print on LCD

    StartTimer(AVK_SETTING_DEVICE_PROFILE_TIMER_ID,AVK_SETTING_DEVICE_PROFILE_TIMER_DELAY_2S,avk_setting_devProfile_callback);

    AVK_SET_PASSKEY(avk_setting_devProfile_stop_callback);
    AVK_SET_FAILKEY(avk_setting_devProfile_stop_callback);		
}

void vs_mm_dev_profile_display_screen_set_discreption_info(void)
{    
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
}
void vs_mm_dev_profile_display_screen_draw_discreption(void)
{
    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*1);
    gui_print_bordered_text((UI_string_type) L"dev profile get string");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*3);
    gui_print_bordered_text((UI_string_type) L"LEFT&RIGHT center key will");

    gui_move_text_cursor(DRAW_TOP_X, DRAW_TOP_Y+DISTANCE_TWO_LINE*4);
    gui_print_bordered_text((UI_string_type) L"change Pattern Type");	
}

void vs_mm_dev_profile_get_value_string_display_screen(srv_dev_profile_category_enum category)
{
    vs_mm_dev_profile_display_screen_set_discreption_info();
    vs_mm_dev_profile_get_value_string_draw_detail(category);
}

void vs_mm_dev_profile_get_value_int_display_screen(void)
{
    vs_mm_dev_profile_display_screen_set_discreption_info();
    vs_mm_dev_profile_get_value_int_draw_detail();
}

#ifdef __cplusplus
}
#endif

#endif /* LOW_COST_SUPPORT */

/*******************************************************************************************************/ 

AVK_ADD_ITEM(AVK_DEVPROFILE_MANUL_ITEM_001,L"DevProfile_001",AVK_SET_DEV)
AVK_ADD_ITEM(AVK_DEVPROFILE_MANUL_ITEM_002,L"DevProfile_002",AVK_SET_DEV)

/**********************************************/
AVK_ADD_ITEM(AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_001,L"001_PlatForm",		AVK_DEVPROFILE_MANUL_ITEM_001)
AVK_ADD_ITEM(AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_002,L"002_hw_version",	AVK_DEVPROFILE_MANUL_ITEM_001)
AVK_ADD_ITEM(AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_003,L"003_mmi_base",		AVK_DEVPROFILE_MANUL_ITEM_001)
AVK_ADD_ITEM(AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_004,L"004_mmi_version",	AVK_DEVPROFILE_MANUL_ITEM_001)
AVK_ADD_ITEM(AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_005,L"005_cur_language",	AVK_DEVPROFILE_MANUL_ITEM_001)

/* get string */
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_STRING_01,AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_001){
#ifndef LOW_COST_SUPPORT
	vs_mm_dev_profile_get_value_string_screen_enter((srv_dev_profile_category_enum)dev_prof_get_string_table_array[0]);
#endif
}
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_STRING_02,AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_002){
#ifndef LOW_COST_SUPPORT	
	vs_mm_dev_profile_get_value_string_screen_enter((srv_dev_profile_category_enum)dev_prof_get_string_table_array[1]);
#endif
}
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_STRING_03,AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_003){
#ifndef LOW_COST_SUPPORT	
	vs_mm_dev_profile_get_value_string_screen_enter((srv_dev_profile_category_enum)dev_prof_get_string_table_array[2]);
#endif
}
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_STRING_04,AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_004){
#ifndef LOW_COST_SUPPORT
	vs_mm_dev_profile_get_value_string_screen_enter((srv_dev_profile_category_enum)dev_prof_get_string_table_array[3]);
#endif
}
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_STRING_05,AVK_DEVPROFILE_ITEM_GET_VALUE_STRING_005){
#ifndef LOW_COST_SUPPORT
	vs_mm_dev_profile_get_value_string_screen_enter((srv_dev_profile_category_enum)dev_prof_get_string_table_array[4]);
#endif
}

/* get int */
AVK_MANUAL_CASE(ITEM_MENUL_GET_VALUE_INT_01,AVK_DEVPROFILE_MANUL_ITEM_002){
#ifndef LOW_COST_SUPPORT
	glb_srv_dev_prof_get_value_table_arrayindex = 0;	// must set 0.
	vs_mm_dev_profile_get_value_int_screen_enter();
#endif
}

#endif /* __MAUI_SDK_TEST__ */
