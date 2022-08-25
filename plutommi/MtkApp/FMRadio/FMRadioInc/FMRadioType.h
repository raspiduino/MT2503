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
*  FMRadioType.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio type definition
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _FM_RADIO_TYPE_H
#define _FM_RADIO_TYPE_H

#include "MMI_features.h"
#ifdef __MMI_BTBOX_NOLCD__
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "nvram_common_defs.h"
#include "FMRadioResDef.h"

typedef enum
{
    FMRADIO_STATE_IDLE = 0,
    FMRADIO_STATE_PLAYING,
    FMRADIO_STATE_RECORD,
    FMRADIO_STATE_RECORD_PAUSE,
    FMRADIO_STATE_SEARCH_ONE,
    FMRADIO_STATE_SEARCH_ALL,
    FMRADIO_STATE_BT_CONNECTING,
    NO_OF_FMRADIO_STATE
} fmradio_state_enum;

typedef struct
{   
    U16 step_freq;
    U16 frequency;
    fmradio_state_enum  state;
    U8  volume;
    U8  mono;
    BOOL is_search_on;
    BOOL is_preempted;
    mmi_id group_id;
} mmi_fmradio_struct;

typedef struct
{
    U16 freq;
    U16 stop_freq;
    BOOL is_step_up;
} mmi_fmradio_search_one_struct;


#define MDI_FMRADIO_VOL_EX_MAX 16
#define MDI_FMRADIO_VOL_EX_MIN 0
#define DEFAULT_FM_VOL 12 
#define MIN_FM_FREQUENCY FM_RADIO_MIN_FREQ //875
#define MAX_FM_FREQUENCY FM_RADIO_MAX_FREQ //1080
#define DEFAULT_FM_FREQUENCY 971 //971

#else //__MMI_BTBOX_NOLCD__

#ifdef __MMI_FM_RADIO__

#include "gui_data_types.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "FMRadioDef.h"
#include "nvram_common_defs.h"

#if defined(__MMI_FM_RADIO_RECORD__)
#include "FileMgrSrvGProt.h"
#endif

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

#if defined(__MMI_FM_RADIO_RECORD__)
typedef struct
{
    U8 drive;
    //U8 format;
    U8 quality;
    U32 duration;
    U32 last_duration_ticks;
    UI_character_type fullName[SRV_FMGR_PATH_MAX_LEN+1];
    MMI_BOOL user_abort;
} mmi_fmrdo_record_struct;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#ifdef __MMI_FM_RADIO_RDS__

typedef struct
{
	MMI_BOOL is_rds_on;	/*Whether rds is on by user or not*/
	MMI_BOOL is_tp_on;/*Auto traffic programme is on or not*/
	MMI_BOOL is_af_on;/*Alternate frequency service is on or off*/
}mmi_fmrdo_rds_setting_struct;
typedef struct
{
	mmi_fmrdo_rds_setting_struct rds_setting;
	U16 status_mask;
	UI_character_type prog_name[MMI_FMRDO_RDS_PS_NAME_SIZE];
	UI_character_type radio_text[MMI_FMRDO_RDS_RT_SIZE + 1];
}mmi_fmrdo_rds_struct;

#endif/*__MMI_FM_RADIO_RDS__*/

typedef struct
{
    U16 freq[FM_RADIO_CHANNEL_NUM];
    UI_character_type name[FM_RADIO_CHANNEL_NUM][12];
} mmi_fmrdo_channel_list_struct;

#ifdef __MMI_FM_VIA_A2DP__
typedef struct
{
	U16 sample_rate;
	MMI_BOOL is_stereo;
}mmi_fmrdo_a2dp_struct;	
#endif



typedef struct
{   
    U16 step_freq;
    U16 frequency;
    S16 channel_index;
    U8  state;
    U8  volume;
    U8  mono;
    U8  skin_index;
    U8  selected_button;
    U8  normal_repeat_step_count;
    U8  twinkle_frequency_count;
    MMI_BOOL is_search_on;
    MMI_BOOL is_power_on;
    MMI_BOOL is_button_down;
    MMI_BOOL is_long_press_number_key;
    MMI_BOOL is_ready;
    MMI_BOOL in_main_screen;
    MMI_BOOL is_preempted;
    MMI_BOOL is_background_play;

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    U8 loud_speaker_on;
#endif /* __MMI_FM_RADIO_LOUD_SPEAK__ */
    U8 mute;
    U8 prev_volume;
#ifdef __MMI_FM_RADIO_RDS__
	mmi_fmrdo_rds_struct rds;
#endif/*__MMI_FM_RADIO_RDS__*/
#if defined(__MMI_FM_RADIO_RECORD__)
    mmi_fmrdo_record_struct rec;
#endif /* __MMI_FM_RADIO_RECORD__ */
    mmi_fmrdo_channel_list_struct channel_list;
} mmi_fmrdo_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x;
    S16 y;
} fmrdo_point_struct;

typedef struct
{
    const fmrdo_point_struct *points;
    S16 num;
} fmrdo_polygon_area_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_MAINLCD_96X64__
typedef struct
{
    U8 LSK_text_border_color_r, LSK_text_border_color_g, LSK_text_border_color_b;
    U8 LSK_text_color_r, LSK_text_color_g, LSK_text_color_b;
    U8 RSK_text_border_color_r, RSK_text_border_color_g, RSK_text_border_color_b;
    U8 RSK_text_color_r, RSK_text_color_g, RSK_text_color_b;

    U8 channel_name_text_border_color_r, channel_name_text_border_color_g, channel_name_text_border_color_b;
    U8 channel_name_text_color_r, channel_name_text_color_g, channel_name_text_color_b;


	S16 channel_name_x, channel_name_y;
    S16 channel_name_w, channel_name_h;
	

    U8 frequency_text_on_color_r, frequency_text_on_color_g, frequency_text_on_color_b;
    U8 frequency_text_off_color_r, frequency_text_off_color_g, frequency_text_off_color_b;

	S16 frequency_x, frequency_y;
    S16 frequency_w, frequency_h;

    S16 animation_x, animation_y;
    U16 animation_image_id;

#if defined(__MMI_FM_RADIO_RECORD__)
    U16 rec_button_image_id;
    U16 rec_pause_button_image_id;
    S16 rec_button_x, rec_button_y;
    U16 rec_duration_number_id_base;    /* base is 0, 1 is base plus 1, 2 is base plus 2, ... */
    U16 rec_duration_number_col_image_id;
    S16 rec_duration_x, rec_duration_y;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;

} mmi_fmrdo_skin_struct;

#elif defined( __MMI_FTE_SUPPORT__)
typedef struct
{
    U16 bg_image_id;
    U8 channel_name_text_border_color_r, channel_name_text_border_color_g, channel_name_text_border_color_b;
    U8 channel_name_text_color_r, channel_name_text_color_g, channel_name_text_color_b;
    S16 channel_name_x, channel_name_y;
    S16 channel_name_w, channel_name_h;
#ifdef __FTE_NON_SLIM_RES__
    U16 frequency_number_id_base;
    U16 freq_dot_id;
    U16 freq_mhz_id;
#endif
    S16 frequency_x, frequency_y;
    S16 frequency_w, frequency_h;
#ifndef __FTE_NON_SLIM_RES__
    S16 frequency_mhz_offset_x;
#endif
    S16 frequency_mhz_offset;
    U16 lsk_img_id;
	U16	lsk_dis_img_id;
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 lsk_img_down_id;
#endif
    S16 lsk_img_x, lsk_img_y;
    U16 rsk_img_id;
	U16 rsk_dis_img_id;
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 rsk_img_down_id;
#endif
    S16 rsk_img_x, rsk_img_y;

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 speaker_image_on_up_id;
    U16 speaker_image_on_down_id;
    U16 speaker_image_off_up_id;
    U16 speaker_image_off_down_id;
    U16 speaker_image_x, speaker_image_y;
    U16 volume_bg_image_id, volume_fg_image_id;
    U16 volume_image_x, volume_image_y;
#else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    U8 volume_bar_type;                 /* 0: horizontal, 1: vertical */
    U16 volume_image_id;
    U16 volume_image_on_id;
    U16 volume_image_off_id;
    U16 volume_image_tune_id;
    U16 volume_image_empty_id;
    U16 volume_image_ind_id;
    U16 volume_image_ind_hl_id;
    S16 volume_bar_x, volume_bar_y;
    U8 volume_ind_start_gap, volume_ind_end_gap;
    S16 volume_image_x, volume_image_y;
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    U16 step_down_button_up_image_id;
    U16 step_down_button_up_dis_image_id;
    S16 step_down_button_x, step_down_button_y;
    U16 step_up_button_up_image_id;
    U16 step_up_button_up_dis_image_id;
    S16 step_up_button_x, step_up_button_y;
    U16 memo_down_button_up_image_id;
    U16 memo_down_button_up_dis_image_id;
    S16 memo_down_button_x, memo_down_button_y;
    U16 memo_up_button_up_image_id;
    U16 memo_up_button_up_dis_image_id;
    S16 memo_up_button_x, memo_up_button_y;
    U16 power_button_on_up_image_id;
    U16 power_button_off_up_image_id;
    S16 power_button_x, power_button_y;
    U16 highlight_img_id;
#ifdef __MMI_TOUCH_SCREEN__
    fmrdo_polygon_area_struct power_button_area;
    fmrdo_polygon_area_struct record_button_area;
    fmrdo_polygon_area_struct step_down_button_area;
    fmrdo_polygon_area_struct step_up_button_area;
    fmrdo_polygon_area_struct memo_dec_button_area;
    fmrdo_polygon_area_struct memo_inc_button_area;
    fmrdo_polygon_area_struct VOL_area;
    fmrdo_polygon_area_struct VOL_mute_area;
    fmrdo_polygon_area_struct VOL_ind_area;
    fmrdo_polygon_area_struct record_pause_area;
    fmrdo_polygon_area_struct record_stop_area;
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        fmrdo_polygon_area_struct key_only_speaker_mute_area;
    #endif
#endif /* __MMI_TOUCH_SCREEN__ */ 
#if defined(__MMI_FM_RADIO_RECORD__)

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 LSK_resume_img_up_id, LSK_resume_img_down_id;
    U16 LSK_pause_img_up_id, LSK_pause_img_down_id;
    U16 RSK_stop_img_up_id, RSK_stop_img_down_id;

    U16 rec_sgn_image_id, rec_sgn_pause_image_id;
    U16 rec_sgn_image_x, rec_sgn_image_y;

    U16 rec_duration_number_id_base;    /* base is 0, 1 is base plus 1, 2 is base plus 2, ... */
    U16 rec_duration_number_col_image_id;
    S16 rec_duration_x, rec_duration_y;
#else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    U16 rec_button_image_id;
    U16 rec_button_dis_image_id;
    S16 rec_button_x, rec_button_y;
    U16 rec_duration_number_id_base;    /* base is 0, 1 is base plus 1, 2 is base plus 2, ... */
    U16 rec_duration_number_col_image_id;
    S16 rec_duration_x, rec_duration_y;
    U16 rec_tool_bg_img_id;
    S16 rec_tool_x, rec_tool_y;
    U16 rec_tool_rec_on_up_img_id;
    U16 rec_tool_rec_on_down_img_id;
    U16 rec_tool_rec_off_up_img_id;
    U16 rec_tool_rec_off_down_img_id;
    S16 rec_tool_rec_x, rec_tool_rec_y;
    U16 rec_tool_stop_up_img_id;
    U16 rec_tool_stop_down_img_id;
    S16 rec_tool_stop_x, rec_tool_stop_y;
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
    S16 line_img_x, line_img_y;
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    S16 line_img_w, line_img_h;
    #endif
    U16 line_img_id;
    S16 cross_img_x, cross_img_y;
    U16 cross_img_id;
#endif
#ifdef __MMI_FM_RADIO_RDS__
        U8 rds_text_border_color_r, rds_text_border_color_g, rds_text_border_color_b;
        U8 rds_text_color_r, rds_text_color_g, rds_text_color_b;
        S16 rds_text_x, rds_text_y;
        S16 rds_text_w, rds_text_h;
         /*af*/
        U16 af_ind_up_image_id;
        U16 af_ind_down_image_id;
        U16 af_ind_disable_image_id;
        S16 af_ind_x, af_ind_y;
        /*rds*/
        U16 rds_ind_up_image_id;
        U16 rds_ind_down_image_id;
        U16 rds_ind_disable_image_id;
        S16 rds_ind_x, rds_ind_y;
        /*tp*/
        U16 tp_ind_up_image_id;
        U16 tp_ind_down_image_id;
        U16 tp_ind_disable_image_id;
        S16 tp_ind_x, tp_ind_y;
#endif/*__MMI_FM_RADIO_RDS__*/

#ifdef __MMI_FM_RADIO_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 


#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U8 center_key_mapping;
#endif
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} mmi_fmrdo_skin_struct;
#else /* __MMI_FTE_SUPPORT__ */
typedef struct
{
    U8 LSK_text_border_color_r, LSK_text_border_color_g, LSK_text_border_color_b;
    U8 LSK_text_color_r, LSK_text_color_g, LSK_text_color_b;
    U8 RSK_text_border_color_r, RSK_text_border_color_g, RSK_text_border_color_b;
    U8 RSK_text_color_r, RSK_text_color_g, RSK_text_color_b;
#ifdef __MMI_SLIM_IMG_RES__
    U16 button_bg_img_id;
    U16 button_hl_img_id;
    U16 button_disable_img_id;
    U16 title_bg_image_id;
#else /* __MMI_SLIM_IMG_RES__ */
    U16 bg_image_id;
#endif /* __MMI_SLIM_IMG_RES__ */
    U8 channel_name_text_border_color_r, channel_name_text_border_color_g, channel_name_text_border_color_b;
    U8 channel_name_text_color_r, channel_name_text_color_g, channel_name_text_color_b;
    S16 channel_name_x, channel_name_y;
    S16 channel_name_w, channel_name_h;
    U8 frequency_text_on_color_r, frequency_text_on_color_g, frequency_text_on_color_b;
    U8 frequency_text_off_color_r, frequency_text_off_color_g, frequency_text_off_color_b;
    S16 frequency_x, frequency_y;
    S16 frequency_w, frequency_h;
#ifdef __MMI_SLIM_IMG_RES__
    U8  title_text_color_r, title_text_color_g, title_text_color_b;
    U8  title_text_border_color_r, title_text_border_color_g, title_text_border_color_b;
    S16 title_x, title_y;
    S16 title_w, title_h;
    U8  label_text_color_r, label_text_color_g, label_text_color_b;
    S16 label_x, label_y;
    S16 label_w, label_h; 
#endif /* __MMI_SLIM_IMG_RES__ */
    U8 volume_bar_type;                 /* 0: horizontal, 1: vertical */
    U16 volume_image_id;
#ifdef __MMI_SLIM_IMG_RES__
    U16 volume_bg_image_id;
#endif /* __MMI_SLIM_IMG_RES__ */
    S16 volume_bar_x, volume_bar_y;
    U8 volume_ind_start_gap, volume_ind_end_gap;
    U8 tuner_scale_type;                /* 0: horizontal, 1: vertical */
    U16 tuner_scale_bg_image_id;
    U16 tuner_scale_ind_image_id;
    S16 tuner_scale_x, tuner_scale_y;
    signed char tunner_scale_ind_offset;
    U8 tuner_scale_start_gap, tuner_scale_end_gap;
    U16 step_down_button_up_image_id;
    U16 step_down_button_down_image_id;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 step_down_button_disable_image_id;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    S16 step_down_button_x, step_down_button_y;
    U16 step_up_button_up_image_id;
    U16 step_up_button_down_image_id;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 step_up_button_disable_image_id;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    S16 step_up_button_x, step_up_button_y;
#ifdef __MMI_SLIM_IMG_RES__
    U16 search_down_button_up_image_id;
    U16 search_down_button_down_image_id;
    S16 search_down_button_x, search_down_button_y;
    U16 search_up_button_up_image_id;
    U16 search_up_button_down_image_id;
    S16 search_up_button_x, search_up_button_y;
#else /* __MMI_SLIM_IMG_RES__ */
    U16 search_button_on_up_image_id;
    U16 search_button_on_down_image_id;
    U16 search_button_off_up_image_id;
    U16 search_button_off_down_image_id;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 search_button_disable_image_id;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    S16 search_button_x, search_button_y;
#endif /* __MMI_SLIM_IMG_RES__ */
    U16 power_button_on_up_image_id;
    U16 power_button_on_down_image_id;
    U16 power_button_off_up_image_id;
    U16 power_button_off_down_image_id;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 power_button_disable_image_id;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    S16 power_button_x, power_button_y;
#ifdef __MMI_FM_RADIO_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
#ifdef __MMI_TOUCH_SCREEN__
#ifndef __MMI_SLIM_IMG_RES__
    S16 volume_inc_x, volume_inc_y;
    U16 volume_inc_up_image_id, volume_inc_down_image_id;
    U16 volume_inc_disable_image_id;
    S16 volume_dec_x, volume_dec_y;
    U16 volume_dec_up_image_id, volume_dec_down_image_id;
    U16 volume_dec_disable_image_id;
    S16 setting_x, setting_y;
    U16 setting_up_image_id, setting_down_image_id;
#endif /* __MMI_SLIM_IMG_RES__ */
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 setting_disable_image_id;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */

#ifndef __MMI_SLIM_IMG_RES__
    fmrdo_polygon_area_struct volume_inc_area;
    fmrdo_polygon_area_struct volume_dec_area;
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_polygon_area_struct step_down_button_area;
    fmrdo_polygon_area_struct step_up_button_area;
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_polygon_area_struct search_down_button_area;
    fmrdo_polygon_area_struct search_up_button_area;
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_polygon_area_struct power_button_area;
#ifndef __MMI_SLIM_IMG_RES__
    fmrdo_polygon_area_struct search_button_area;
    fmrdo_polygon_area_struct setting_area;
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_polygon_area_struct frequency_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
#if defined(__MMI_FM_RADIO_RECORD__)
    U16 rec_button_image_id;
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    U16 rec_button_dis_image_id;
#endif 
    U16 rec_pause_button_image_id;
    S16 rec_button_x, rec_button_y;
    U16 rec_duration_number_id_base;    /* base is 0, 1 is base plus 1, 2 is base plus 2, ... */
    U16 rec_duration_number_col_image_id;
    S16 rec_duration_x, rec_duration_y;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
#ifdef __MMI_FM_RADIO_RDS__
    U8 rds_text_border_color_r, rds_text_border_color_g, rds_text_border_color_b;
    U8 rds_text_color_r, rds_text_color_g, rds_text_color_b;
    S16 rds_text_x, rds_text_y;
    S16 rds_text_w, rds_text_h;
     /*af*/
    U16 af_ind_up_image_id;
    U16 af_ind_down_image_id;
    U16 af_ind_disable_image_id;
    S16 af_ind_x, af_ind_y;
    /*rds*/
    U16 rds_ind_up_image_id;
    U16 rds_ind_down_image_id;
    U16 rds_ind_disable_image_id;
    S16 rds_ind_x, rds_ind_y;
    /*tp*/
    U16 tp_ind_up_image_id;
    U16 tp_ind_down_image_id;
    U16 tp_ind_disable_image_id;
    S16 tp_ind_x, tp_ind_y;
  
#endif/*__MMI_FM_RADIO_RDS__*/

    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} mmi_fmrdo_skin_struct;
#endif /* __MMI_FTE_SUPPORT__ */


#endif /* __MMI_FM_RADIO__ */ 
#endif /*__MMI_BTBOX_NOLCD__*/
#endif /* _FM_RADIO_TYPE_H */ 

