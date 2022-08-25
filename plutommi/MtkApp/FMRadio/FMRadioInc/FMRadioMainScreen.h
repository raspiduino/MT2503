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

/*******************************************************************************
* Filename:
* ---------
*  FMRadioMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing prototype
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _FM_RADIO_MAIN_SCREEN_H
#define _FM_RADIO_MAIN_SCREEN_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "gui_windows.h"
#include "FMRadioDef.h"
#include "kal_non_specific_general_types.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

typedef struct
{
    S16 x, y;
    S16 w, h;
} fmrdo_main_rect_struct;

typedef struct
{
    U8 type;    /* 0: horizontal, 1: vertical */
    signed char ind_offset;
    U8 ind_start_gap;
    U8 ind_end_gap;
    S16 x, y;
    S16 w, h;
    S16 ind_w, ind_h;
    PU8 bg_img, ind_img;
} fmrdo_main_tuner_scale_struct;

#ifdef __MMI_FM_RADIO_RDS__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    PU8 dis_img;
} fmrdo_main_ind_struct;
#endif/*__MMI_FM_RADIO_RDS__*/

#ifdef __MMI_FM_RADIO_ANIMATION__
typedef struct
{
    S16 x, y;
    /* S16 w, h; */
    gdi_handle img_handle;
    PU8 animation_img;
} fmrdo_main_animation_struct;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    PU8 dis_img;
    MMI_BOOL down;
} fmrdo_main_push_down_button_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_MAINLCD_96X64__
typedef struct
{
    S16 x, y;
    PU8 animation_img;
} fmrdo_main_animation_struct;

typedef struct
{
    color frequency_text_on_color;
    color frequency_text_off_color;

    color channel_name_text_color;
    color channel_name_text_border_color;

#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_ind_struct rds_ind;
    fmrdo_main_ind_struct af_ind;
    fmrdo_main_ind_struct tp_ind;
    fmrdo_main_rect_struct rds_text;
    scrolling_text rds_text_scroll;
    UI_character_type rds_text_str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
    MMI_BOOL is_rds_text_scroll_ready;
    color rds_text_color;
    color rds_text_border_color;
#endif/*__MMI_FM_RADIO_RDS__*/

fmrdo_main_animation_struct animation;
    fmrdo_main_rect_struct channel_name;
    fmrdo_main_rect_struct frequency;
    scrolling_text channel_name_scroll;
    UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];

#if defined(__MMI_FM_RADIO_RECORD__)
    fmrdo_main_toggle_button_struct rec_button;
    fmrdo_main_toggle_button_struct rec_pause_button;
    U16 rec_base_num_id;
    U16 rec_num_col_id;
    S16 timer_hr_0_offset_x;
    S16 timer_hr_1_offset_x;
    S16 timer_col_0_offset_x;
    S16 timer_min_0_offset_x;
    S16 timer_min_1_offset_x;
    S16 timer_col_1_offset_x;
    S16 timer_sec_0_offset_x;
    S16 timer_sec_1_offset_x;
    S16 timer_offset_y;
    S16 timer_offset_x2;
    S16 timer_offset_y2;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    U8 skin_index;
    MMI_BOOL is_ready;
    MMI_BOOL is_channel_name_scroll_ready;
} fmrdo_main_draw_struct;


#elif defined( __MMI_FTE_SUPPORT__)
typedef struct
{
    U8 type;    /* 0: horizontal, 1: vertical */
    U8 ind_left_gap;
    U8 ind_top_gap;
    S16 x, y;
    S16 w, h;
    PU8 bg_img;
    PU8 ind_img, ind_hl_img;
    S32 ind_w, ind_h;
} fmrdo_main_volume_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 bg_img;
} fmrdo_main_reocrd_bar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 on_up_img;
    PU8 off_up_img;
} fmrdo_main_toggle_button_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 on_up_img, on_down_img;
    PU8 off_up_img, off_down_img;
} fmrdo_bar_toggle_button_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img;
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        PU8 down_img; 
    #endif
    PU8 dis_img;
} fmrdo_main_push_button_struct;

typedef struct
{
    fmrdo_main_push_button_struct LSK;
    fmrdo_main_push_button_struct RSK;

    color channel_name_text_color;
    color channel_name_text_border_color;

    PU8 bg_img;
#ifdef __MMI_FTE_SUPPORT_SLIM__
    PU8 bg_line;
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

#if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
        S16 line_img_x, line_img_y;
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        S16 line_img_w, line_img_h;
    #endif
        PU8 line_img;
        S16 cross_img_x, cross_img_y;
        PU8 cross_img;
#endif

    fmrdo_main_volume_struct volume;
    fmrdo_bar_toggle_button_struct vol_img;
    PU8 vol_tune_img;
    PU8 vol_empty_img;
    fmrdo_main_push_button_struct step_down_button;
    fmrdo_main_push_button_struct step_up_button;
    fmrdo_main_push_button_struct memo_dn_button;
    fmrdo_main_push_button_struct memo_up_button;
    fmrdo_main_toggle_button_struct power_button;
    fmrdo_main_rect_struct channel_name;
    fmrdo_main_push_button_struct highlight_img;
    S16 frequency_y;
    S16 frequency_h;
    U16 freq_base_num_id;
    PU8 freq_dot;
    PU8 freq_mhz;
    S16 freq_h_offset_x;
    S16 freq_ten_offset_x;
    S16 freq_one_offset_x;
    S16 freq_dot_offset_x;
    S16 freq_dot_offset_y;
    S16 freq_dec_offset_x;
    S16 freq_mhz_offset_x;
    S16 freq_mhz_offset_y;
    scrolling_text channel_name_scroll;
    UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT    
    PU8 speaker_image_on_up, speaker_image_on_down;
    PU8 speaker_image_off_up, speaker_image_off_down;
    U16 speaker_image_x, speaker_image_y;
    PU8 volume_bg_image, volume_fg_image;
    U16 volume_image_x, volume_image_y;
#endif

#if defined(__MMI_FM_RADIO_RECORD__)
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        S16 rec_sgn_x, rec_sgn_y;
        PU8 rec_sgn_img;
        PU8 rec_sgn_pause_img;

        PU8 LSK_resume_img_up, LSK_resume_img_down;
        PU8 LSK_pause_img_up, LSK_pause_img_down;
        PU8 RSK_stop_img_up, RSK_stop_img_down;

    #else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    fmrdo_main_toggle_button_struct rec_button;
    fmrdo_main_reocrd_bar_struct rec_bar;
    fmrdo_bar_toggle_button_struct bar_record_button;
    fmrdo_bar_toggle_button_struct bar_stop_record;
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    
    U16 rec_base_num_id;
    U16 rec_num_col_id;
    S16 timer_hr_0_offset_x;
    S16 timer_hr_1_offset_x;
    S16 timer_col_0_offset_x;
    S16 timer_min_0_offset_x;
    S16 timer_min_1_offset_x;
    S16 timer_col_1_offset_x;
    S16 timer_sec_0_offset_x;
    S16 timer_sec_1_offset_x;
    S16 timer_offset_y;
    S16 timer_offset_x2;
    S16 timer_offset_y2;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    #ifdef __MMI_FM_RADIO_ANIMATION__
    fmrdo_main_animation_struct animation;
    #endif 
    MMI_BOOL is_ready;
    MMI_BOOL is_channel_name_scroll_ready;

#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_ind_struct rds_ind;
    fmrdo_main_ind_struct af_ind;
    fmrdo_main_ind_struct tp_ind;
    fmrdo_main_rect_struct rds_text;
    scrolling_text rds_text_scroll;
    UI_character_type rds_text_str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
    MMI_BOOL is_rds_text_scroll_ready;
    color rds_text_color;
    color rds_text_border_color;
#endif/*__MMI_FM_RADIO_RDS__*/
} fmrdo_main_draw_struct;
#else /* __MMI_FTE_SUPPORT__ */
typedef struct
{
    U8 type;    /* 0: horizontal, 1: vertical */
    U8 ind_start_gap;
    U8 ind_end_gap;
    S16 x, y;
    S16 w, h;
    PU8 fg_img;
#ifdef __MMI_SLIM_IMG_RES__
    PU8 bg_img;
#endif
} fmrdo_main_volume_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 on_up_img, on_down_img;
    PU8 off_up_img, off_down_img;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    PU8 dis_img;
#endif 
} fmrdo_main_toggle_button_struct;


typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
#if defined(__MMI_FM_SKIN_SYN_TO_THEME__) 
    PU8 dis_img;
#endif 
} fmrdo_main_push_button_struct;

typedef struct
{
#ifdef __MMI_SLIM_IMG_RES__
    PU8 btn_bg_img;
    PU8 btn_hl_img;
    PU8 btn_disable_img;
    S16 btn_bg_w, btn_bg_h;
    PU8 title_bg_img;
#else
    PU8 bg_img;
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_main_volume_struct volume;
    fmrdo_main_tuner_scale_struct tuner_scale;
    fmrdo_main_push_button_struct step_down_button;
    fmrdo_main_push_button_struct step_up_button;
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_push_button_struct search_up_button;
    fmrdo_main_push_button_struct search_down_button;
#else
    fmrdo_main_toggle_button_struct search_button;
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_main_toggle_button_struct power_button;
#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_ind_struct rds_ind;
    fmrdo_main_ind_struct af_ind;
    fmrdo_main_ind_struct tp_ind;
    fmrdo_main_rect_struct rds_text;
    scrolling_text rds_text_scroll;
    UI_character_type rds_text_str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
    MMI_BOOL is_rds_text_scroll_ready;
    color rds_text_color;
    color rds_text_border_color;
#endif/*__MMI_FM_RADIO_RDS__*/
#ifdef __MMI_FM_RADIO_ANIMATION__
    fmrdo_main_animation_struct animation;
#endif 
#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
    fmrdo_main_push_down_button_struct setting_button;
    fmrdo_main_push_down_button_struct volume_inc_button;
    fmrdo_main_push_down_button_struct volume_dec_button;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    fmrdo_main_rect_struct channel_name;
    fmrdo_main_rect_struct frequency;
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_rect_struct title;
    fmrdo_main_rect_struct label;
#endif /* __MMI_SLIM_IMG_RES__ */

    scrolling_text channel_name_scroll;
    UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];

#if defined(__MMI_FM_RADIO_RECORD__)
    fmrdo_main_toggle_button_struct rec_button;
    fmrdo_main_toggle_button_struct rec_pause_button;
    U16 rec_base_num_id;
    U16 rec_num_col_id;
    S16 timer_hr_0_offset_x;
    S16 timer_hr_1_offset_x;
    S16 timer_col_0_offset_x;
    S16 timer_min_0_offset_x;
    S16 timer_min_1_offset_x;
    S16 timer_col_1_offset_x;
    S16 timer_sec_0_offset_x;
    S16 timer_sec_1_offset_x;
    S16 timer_offset_y;
    S16 timer_offset_x2;
    S16 timer_offset_y2;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    U8 skin_index;
    MMI_BOOL is_ready;
    MMI_BOOL is_channel_name_scroll_ready;
} fmrdo_main_draw_struct;
#endif /* __MMI_FTE_SUPPORT__ */

extern void mmi_fmrdo_exit_mainscreen(void);

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
extern void mmi_fmrdo_init_for_theme(void);
#endif 
extern void mmi_fmrdo_init_main_images(S32 skin_index);
extern void mmi_fmrdo_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index);
extern void mmi_fmrdo_hide_main(void);
extern void mmi_fmrdo_redraw_main_LSK_down(void);
extern void mmi_fmrdo_redraw_main_RSK_down(void);
extern void mmi_fmrdo_redraw_main_LSK_up(void);
extern void mmi_fmrdo_redraw_main_RSK_up(void);
extern void mmi_fmrdo_scroll_channel_name_hdlr(void);
extern void mmi_fmrdo_redraw_main_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmrdo_redraw_main_all(void);
#ifdef __MMI_SLIM_IMG_RES__
extern void mmi_fmrdo_redraw_main_title(void);
extern void mmi_fmrdo_redraw_main_freq_label(void);
#endif /*__MMI_SLIM_IMG_RES__*/
extern void mmi_fmrdo_redraw_main_frequency(U16 freq, MMI_BOOL is_shown);
extern void mmi_fmrdo_reset_volume_bar(void);
extern void mmi_fmrdo_redraw_bar_toggle_button(U8 button, MMI_BOOL is_down, MMI_BOOL is_on, MMI_BOOL is_shown);
extern void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str);
extern void mmi_fmrdo_redraw_main_channel_tuner(U16 freq);
extern void mmi_fmrdo_redraw_main_volume(void);
extern void mmi_fmrdo_redraw_main_push_button(U8 button, MMI_BOOL is_down);
extern void mmi_fmrdo_restore_main_SK(void);
extern void mmi_fmrdo_redraw_main_volumebar(U8 volume, MMI_BOOL is_shown);
extern void mmi_fmrdo_update_record_bar(void);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmrdo_redraw_main_push_down_button(U8 button, MMI_BOOL is_down);
extern void mmi_fmrdo_redraw_main_volum_icon(U8 button);
#endif /* __MMI_TOUCH_SCREEN__ */ 
extern void mmi_fmrdo_redraw_main_toggle_button(U8 button, MMI_BOOL is_down, MMI_BOOL is_on, MMI_BOOL is_shown);

#ifdef __MMI_FM_RADIO_ANIMATION__
extern void mmi_fmrdo_animation_start(void);
extern void mmi_fmrdo_animation_stop(void);
extern S32 mmi_fmrdo_get_animation_handle(void);
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
extern void mmi_fmrdo_redraw_record_frequency(U16 freq, MMI_BOOL is_shown);

#if defined(__MMI_FM_RADIO_RECORD__)
extern void mmi_fmrdo_change_main_SK_record(void);
extern void mmi_fmrdo_change_main_SK_pause(void);
extern void mmi_fmrdo_redraw_main_time_duration(MMI_BOOL is_shown);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

extern void mmi_fmrdo_redraw_disabled_buttons(void);
extern pBOOL mmi_fmrdo_need_disable_button(U8 button);
extern pBOOL mmi_fmrdo_need_disable_push_button(fmrdo_main_button_enum button);
#endif /* __MMI_FM_RADIO__ */ 
#endif /* _FM_RADIO_MAIN_SCREEN_H */ 

