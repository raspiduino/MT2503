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
 *   tst_Gpio.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
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

#ifndef AVK_DEVICE_BACKLIGHT_H
#define AVK_DEVICE_BACKLIGHT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gpiosrvgprot.h"

#define VS_MM_ID_SUPPORT
#define VS_MM_BUFFER_SIZE       (128)
#define VS_DEV_GPIO_OPTON_SIZE  (24-6) // we have 24 items to test / 10AW11.08MP we subtract 6

typedef struct
{
    U8                  u_level;
    srv_gpio_dev_enum   e_device;
}vs_dev_gpio_device_level;

typedef struct
{
    srv_gpio_pattern_id_enum        e_pattern_id;
    srv_gpio_pattern_type_enum      e_pattern_type;
}vs_dev_gpio_vibrate;

typedef struct
{
    audio_type_enum audio_device_type;
    MMI_BOOL        b_mute_on;              // TRUE:on ,FALSE:off
}vs_dev_gpio_device_mute;

typedef struct
{
    srv_gpio_vol_type_enum  type;       
    U8                            volume; /* 0~7 */
}vs_dev_gpio_volume;

typedef struct
{
    U8                            volume; /* 0~7 */
}vs_dev_speech_mode_volume;

typedef struct
{
//    srv_gpio_pattern_id_enum       pattern_id;
//    srv_gpio_pattern_type_enum    pattern_type;

	U8	   pattern_id;
	U8 	   pattern_type;
}vs_dev_play_pattern;


// screen enter 
void vs_dev_gpio_set_device_level_screen_enter(void);
void vs_dev_gpio_speech_set_mode_volume_screen_enter(void);
void vs_dev_gpio_backlight_get_level_screen_enter(void);
void vs_dev_gpio_speech_is_phone_mute_screen_enter(void);
void vs_dev_gpio_backlight_is_on_screen_enter(void);
void vs_dev_gpio_backlight_get_hf_time_screen_enter(void);
void vs_dev_gpio_backlight_is_lcd_sleep_screen_enter(void);
void vs_dev_gpio_clam_is_close_screen_enter(void);
void vs_dev_gpio_backlight_get_timer_state_screen_enter(void);
void vs_dev_gpio_speech_get_mode_volume_screen_enter(void);
void vs_dev_gpio_speech_disable_hand_free_screen_enter(void);
void vs_dev_gpio_speech_enable_hand_free_screen_enter(void);
void vs_dev_gpio_speech_mute_phone_screen_enter(void);
void vs_dev_gpio_speech_unmute_phone_screen_enter(void);
void vs_dev_gpio_backlight_close_screen_enter(void);
void vs_dev_gpio_backlight_turn_off_keypad_light_screen_enter(void);
void vs_dev_gpio_backlight_half_mode_screen_enter(void);
void vs_dev_gpio_backlight_turn_on_screen_enter(void);
void vs_dev_gpio_set_device_mute_screen_enter(void);
void vs_dev_gpio_set_volume_screen_enter(void);
void vs_dev_gpio_mode_volume_screen_enter(void);
void vs_dev_gpio_play_pattern_screen_enter(void);


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
void vs_dev_gpio_backlight_close_callback(void);
void vs_dev_gpio_backlight_turn_off_keypad_light_callback(void);
void vs_dev_gpio_set_device_level_callback(void);
void vs_dev_gpio_set_device_level_add_callback(void);
void vs_dev_gpio_set_device_level_sub_callback(void);
void vs_dev_gpio_pass(void);
void vs_dev_gpio_fail(void);

// display screen callback
void vs_dev_gpio_phone_is_mute_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_is_on_display_screen(dm_coordinates *coordinate);
//void vs_dev_gpio_backlight_is_on_display_screen(void);
void vs_dev_gpio_backlight_get_hf_time_display_screen(dm_coordinates *coordinate);
//void vs_dev_gpio_backlight_get_hf_time_display_screen(void);
void vs_dev_gpio_backlight_is_lcd_sleep_mode_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_get_timer_state_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_close_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_turn_off_keypad_light_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_half_mode_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_device_level_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_get_mode_volume_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_enable_hand_free_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_disable_hand_free_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_unmute_phone_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_mute_phone_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_set_device_level_device_draw_detail(gpio_device_enum e_device, U8 u_level);

void vs_dev_gpio_backlight_turn_on_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_backlight_turn_on_permanent(void);
void vs_dev_gpio_backlight_turn_on_short_time(void);

void vs_dev_gpio_set_volume_and_draw_detail(srv_gpio_vol_type_enum volume_type, U8 volume_level);

void vs_dev_gpio_play_vibrate_display_screen(srv_gpio_pattern_id_enum pattern_id,srv_gpio_pattern_type_enum pattern_type);
void vs_dev_gpio_play_vibrate_pattern_id_add(void);
void vs_dev_gpio_play_vibrate_pattern_id_sub(void);
void vs_dev_gpio_play_vibrate_pattern_type_add(void);
void vs_dev_gpio_play_vibrate_pattern_type_sub(void);
void vs_dev_gpio_play_vibrate_draw_detail(srv_gpio_pattern_id_enum id, srv_gpio_pattern_type_enum type);

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
void vs_dev_gpio_get_backlight_level_display_screen(void);
void vs_dev_gpio_speech_save_mode_volume_level_add(void);
void vs_dev_gpio_speech_save_mode_volume_level_sub(void);

void vs_dev_gpio_play_pattern_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_play_pattern_draw_detail(srv_gpio_pattern_id_enum pattern, srv_gpio_pattern_type_enum action);
void vs_dev_gpio_play_pattern_id_add(void);
void vs_dev_gpio_play_pattern_id_sub(void);
void vs_dev_gpio_play_pattern_type_add(void);
void vs_dev_gpio_play_pattern_type_sub(void);
void vs_dev_gpio_play_vibrate_screen_enter(srv_gpio_pattern_id_enum pattern_id,srv_gpio_pattern_type_enum pattern_type);
void vs_dev_gpio_earphone_is_plug_in_display_screen(dm_coordinates *coordinate);
void vs_dev_gpio_speech_set_mode_volume_display_screen(dm_coordinates *coordinate);


#endif /* AVK_DEVICE_BACKLIGHT_H */ 


#ifdef __cplusplus
}
#endif

#endif /* __MAUI_SDK_TEST__ */ 


