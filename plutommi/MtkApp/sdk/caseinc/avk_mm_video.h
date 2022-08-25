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
 *   tst_appser_mm_video.h
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
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#ifndef TST_APPSER_MM_VIDEO_H
#define TST_APPSER_MM_VIDEO_H

#ifdef MJPG_DECODE
#define VS_MM_AVI_SUPPORT
#endif


#define VS_MM_VIDEO_PLAY_FILE_OPTION_SIZE  (2)
#define VS_MM_VIDEO_PLAY_FILE_TYPE_SIZE  (3)
#define VS_MM_VIDEO_OPTON_SIZE    (7)
#define VS_MM_BUFFER_SIZE        (128)


typedef enum
{
    VS_MM_VIDEO_STATE_IDLE,
    VS_MM_VIDEO_STATE_OPEN,
    VS_MM_VIDEO_STATE_PAUSE,
    VS_MM_VIDEO_STATE_PLAY,
    /* add states above this line */
    VS_MM_VIDEO_STATE_LAST_ONE
} vs_mm_video_state_enum;

typedef enum
{
    VS_MM_VIDEO_TYPE_FILE,
    VS_MM_VIDEO_TYPE_FILE_CLIP,
    VS_MM_VIDEO_TYPE_ID_CLIP,
    VS_MM_VIDEO_TYPE_BUFFER_CLIP,
    /* add video type above this line */
    VS_MM_VIDEO_TYPE_LAST_ONE
} vs_mm_video_type_enum;


typedef enum
{

#ifdef __VDOREC_FEATURE_EV_4__
    VS_MM_VIDEO_SETTING_EV_POS_4,
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    VS_MM_VIDEO_SETTING_EV_POS_3,
#endif 

#ifdef __VDOREC_FEATURE_EV_2__
    VS_MM_VIDEO_SETTING_EV_POS_2,
#endif 

    VS_MM_VIDEO_SETTING_EV_POS_1,
    VS_MM_VIDEO_SETTING_EV_ZERO,
    VS_MM_VIDEO_SETTING_EV_NEG_1,

#ifdef __VDOREC_FEATURE_EV_2__
    VS_MM_VIDEO_SETTING_EV_NEG_2,
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    VS_MM_VIDEO_SETTING_EV_NEG_3,
#endif 

#ifdef __VDOREC_FEATURE_EV_4__
    VS_MM_VIDEO_SETTING_EV_NEG_4,
#endif 

    VS_MM_VIDEO_SETTING_EV_COUNT
} vs_mm_video_setting_ev_enum;

typedef struct
{
    S32 index;
    S32 count;
    S32 sub_type;
    S32 num;
    gdi_handle play_layer_handle;
    gdi_handle osd_layer_handle;
    vs_mm_video_state_enum state;
    vs_mm_video_type_enum type;
    U64 play_time;
    S32 offset_x;
    S32 offset_y;
    S32 normal_width;
    S32 normal_height;
    U64 total_time;
    S32 audio_level;
    S32 file_option;
    U16 brightness;
    U16 filepath[VS_MM_BUFFER_SIZE];
    U16 play_id;
    U16 vdo_file[VS_MM_BUFFER_SIZE];
    U16 para_ev;
    U16 para_zoom;
    U16 total_time_str[VS_MM_BUFFER_SIZE];
    U16 play_ptr[VS_MM_BUFFER_SIZE];
    U16 rec_is_ptr[VS_MM_BUFFER_SIZE];
    U16 rec_size_ptr[VS_MM_BUFFER_SIZE];
    U16 rec_zoom_ptr[VS_MM_BUFFER_SIZE];
    U16 rec_time_ptr[VS_MM_BUFFER_SIZE];
    BOOL lcm_update;
    BOOL re_enter;
} vs_mm_video_context_struct;

//#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
void vs_mm_video_001_open_file(void);
void vs_mm_video_001_close_file(void);
void vs_mm_video_001_play(void);
void vs_mm_video_001_pause(void);
void vs_mm_video_001_resume(void);
void vs_mm_video_001_stop(void);
void vs_mm_video_001_set_stop_time(void);
void vs_mm_video_001_is_playing(void);
void vs_mm_video_001_set_brightness(void);
void vs_mm_video_001_set_audio_level(void);

void vs_mm_video_002_open_clip(void);
void vs_mm_video_003_open_id(void);
void vs_mm_video_004_open_buffer(void);

void vs_mm_video_005_rec_save(void);
void vs_mm_video_005_rec_resume(void);
void vs_mm_video_005_rec_stop(void);
void vs_mm_video_005_rec_pause(void);
void vs_mm_video_005_preview_stop(void);
void vs_mm_video_005_rec_start(void);
void vs_mm_video_005_preview(void);
void vs_mm_video_005_rec_file(void);
void vs_mm_video_005_is_recording(void);
void vs_mm_video_005_get_record_file_size(void);
void vs_mm_video_005_get_max_zoom(void);
void vs_mm_video_005_get_curr_time(void);
void vs_mm_video_005_rec_update_blt_pause(void);
void vs_mm_video_005_rec_update_blt_resume(void);
void vs_mm_video_005_rec_update_para_ev(void);
void vs_mm_video_005_rec_update_para_zoom(void);
void vs_mm_video_006_rec_file_error(void);

void vs_mm_video_misc_get_file_path(U16 *path, U16 *file);
void vs_mm_video_misc_play_file_setting_save(void);
void vs_mm_video_misc_draw_screen(void);
void vs_mm_video_misc_play_finish_hdlr(MDI_RESULT result, void *user_data);
void vs_mm_video_misc_file_screen_enter(void);
void vs_mm_video_misc_clip_screen_enter(void);
void vs_mm_video_misc_seek_result(MDI_RESULT mdi_res);
void vs_mm_video_misc_file_screen_exit(void);
void vs_mm_video_misc_record_file_screen_exit(void);
void vs_mm_video_misc_rec_result_hdlr(MDI_RESULT result, void* user_data);
void vs_mm_video_misc_rec_save_result_hdlr(MDI_RESULT result,void* user_data);
void vs_mm_video_misc_draw_rec_time(void);
void vs_mm_video_misc_draw_rec_size(void);
void vs_mm_video_misc_draw_rec_zoom(void);
void vs_mm_video_misc_draw_rec_state(void);
void vs_mm_video_misc_time_and_size_cnt(void);
void vs_mm_video_misc_draw_play_state(void);
void vs_mm_video_misc_noblock_seek_result_callback(MDI_RESULT result);
void vs_mm_video_misc_pass(void);
void vs_mm_video_misc_fail(void);
void vs_mm_video_misc_manual(void);
//#endif

void vs_mm_misc_init_video(void);
void vs_mm_video_option_highlight_hdlr(S32 index);
void vs_mm_video_entry_scr(void);

void vs_mm_bitstream_record_entry_scr();
void vs_mm_bitstream_entry_highlight(S32 index);
//void vs_mm_bitstream_record(void);

void  vs_mm_video_007_stream_play(void);
void vs_mm_video_008_pdl(void);

#endif /* TST_APPSER_MM_VIDEO */ 

#endif /* __MAUI_SDK_TEST__ */ 

