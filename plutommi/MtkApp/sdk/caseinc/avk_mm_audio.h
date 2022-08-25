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
 *   tst_appser_mm_audio.h
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


#ifndef TST_APPSER_MM_AUDIO_H
#define TST_APPSER_MM_AUDIO_H

#define VS_MM_BUFFER_SIZE        (128)
#define VS_MM_AUDIO_OPTON_SIZE    (35)
#include "mdi_audio.h"
#include "nvram_default_audio.h"


#define VS_MM_AUDIO_SAMPLE_DUMMY_BG        (127)
#define VS_MM_AUDIO_BUILD_CACHE_SIZE (2*1024)           /* audio build cache size */
#define VS_MM_AUDIO_BUILD_CACHE_FILE_BUF_SIZE 1024      /* audio build cache file buffer size */
#define VS_MM_AUDIO_BUILD_CACHE_PROC_BUF_SIZE (32*1024) /* audio build cache process buffer size */
#define VS_MM_AUDIO_FRM_MIN_FM_FREQUENCY 875
#define VS_MM_AUDIO_FRM_MAX_FM_FREQUENCY 1080
#define VS_MM_AUDIO_FRM_RDS_PS_NAME_SIZE 10
#define VS_MM_AUDIO_FRM_RDS_RT_SIZE      64  

#ifdef __MMI_AUDIO_PLAYER__
#define MMI_BACKGROUND_APP MDI_BACKGROUND_APP_AUDPLY
#else
#define MMI_BACKGROUND_APP MDI_BACKGROUND_APP_MEDPLY
#endif 


typedef enum
{
    VS_MM_AUDIO_FORMAT_SMF = 1,
    VS_MM_AUDIO_FORMAT_WAV,
    VS_MM_AUDIO_FORMAT_IMELODY,
    VS_MM_AUDIO_FORMAT_AMR,
    /* add states above this line */
    VS_MM_AUDIO_FORMAT_LAST_ONE
} vs_mm_audio_string_type_enum;

typedef enum
{
    STREAM_STATE_IDLE,
    STREAM_STATE_PLAY
}vs_mm_stream_state_enum;

#define VS_MM_AUDIO_STREAM_CACHE_SIZE 2500



typedef struct
{
    S32 index;
    S32 num;
    U8 stop;
    S32 count;
    S32 sub_type;
    UI_character_type filename[VS_MM_BUFFER_SIZE];
    UI_character_type record_file_name[VS_MM_BUFFER_SIZE];
    PU8 audio_buffer;
    U32 total_time;
    U32 play_time;
    U8 total_time_str[VS_MM_BUFFER_SIZE];
    U8 play_time_str[VS_MM_BUFFER_SIZE];
    U8 audio_level;
    S8 mute;
    S8 suspended;
    S8 bg_playing;
    U32 cur_offset;
    U32 cache_duration;
    U8 cache_duration_buf[VS_MM_BUFFER_SIZE];
    U32 total_duration;
    U8 total_duration_buf[VS_MM_BUFFER_SIZE];
    U8 audio_cache[VS_MM_AUDIO_BUILD_CACHE_SIZE];
    U8 *audio_cache_file_buf_p;
    U8 *audio_cache_proc_buf_p;
    U32 audio_build_cache_progress;
    S32 magnitude_index;
    S32 reverb_index;
    U8 surround_mode;
    U8 amplitude_val[16];
    U8 top[16];
    S32 speed;
    U16 freq;
    BOOL mono;
    S32 type;
    U8 str_type;
    U16 id_type;
    U32 buffer_size;
    S8 file_buf[VS_MM_BUFFER_SIZE];
    S8 progress_buf[VS_MM_BUFFER_SIZE];
    S8 state_buf[VS_MM_BUFFER_SIZE];
    S8 midi_size_ptr[VS_MM_BUFFER_SIZE];
    mdi_handle aud_handle;
    mdi_result result;
    vs_mm_stream_state_enum status;
    U32 offset;
    BOOL wait_buffer;
    S32 player_handle;
    BOOL finish;
    PS8 media_buffer;
    UI_character_type prog_name[VS_MM_AUDIO_FRM_RDS_PS_NAME_SIZE];
    UI_character_type radio_text[VS_MM_AUDIO_FRM_RDS_RT_SIZE + 1];
	mdi_handle m_handle032;
	
    U16 m_signalBand[20];
} vs_mm_audio_context_struct;

/* begin audio api test */
void vs_mm_audio_001_play_id(void);
void vs_mm_audio_001_pause(void);
void vs_mm_audio_001_resume(void);
void vs_mm_audio_001_stop(void);
void vs_mm_audio_001_set_volume_add(void);
void vs_mm_audio_001_set_volume_sub(void);
void vs_mm_audio_001_set_headset_mode_output_path(void);
void vs_mm_audio_001_idle_or_play(void);
void vs_mm_audio_001_get_progress_time(void);
void vs_mm_audio_001_set_progress_time(void);

void vs_mm_audio_002_play_string(void);
U32 vs_mm_audio_002_get_midi_buffer(void);
void vs_mm_audio_003_play_string_vol_path(void);
void vs_mm_audio_004_play_string_portion_vol_path(void);
void vs_mm_audio_005_play_string_vol_path_non_block(void);
void vs_mm_audio_006_play_file(void);
void vs_mm_audio_006_vibrator_disable(void);
void vs_mm_audio_006_vibrator_enable(void);
void vs_mm_audio_006_get_midi_file_limit(void);

void vs_mm_audio_007_play_file_vol_path(void);

void vs_mm_audio_008_play_file_portion_vol_path(void);
void vs_mm_audio_009_record_start(void);
void vs_mm_audio_009_record_stop(void);

void vs_mm_audio_010_background_play(void);
void vs_mm_audio_010_bg_play_operate(void);

void vs_mm_audio_011_snd_play_string(void);
void vs_mm_audio_012_snd_play_file(void);
void vs_mm_audio_012_snd_screen(dm_coordinates *coordinate);
void vs_mm_audio_012_snd_stop_hdlr(void);
void vs_mm_audio_012_snd_set_volume_add(void);
void vs_mm_audio_012_snd_set_volume_sub(void);
void vs_mm_audio_012_snd_is_idle(void);
void vs_mm_audio_012_snd_play_screen_exit(void);
void vs_mm_audio_012_snd_play_screen_enter(void);

void vs_mm_audio_013_build_cache(void);

void vs_mm_audio_014_tts_stop(void);
void vs_mm_audio_014_tts_pause(void);
void vs_mm_audio_014_tts_resume(void);
void vs_mm_audio_014_tts(void);

void vs_mm_audio_015_eq_turn_off(void);
void vs_mm_audio_015_eq_set_magnitude(void);
void vs_mm_audio_015_eq(void);

void vs_mm_audio_016_reverb_stop(void);
void vs_mm_audio_016_reverb_set_coeff(void);
void vs_mm_audio_016_reverb(void);

void vs_mm_audio_017_surround_turn_off(void);
void vs_mm_audio_017_surround_turn_on(void);
void vs_mm_audio_017_surround(void);

void vs_mm_audio_018_spectrum_stop(void);
void vs_mm_audio_018_spectrum_start(void);
void vs_mm_audio_018_spectrum(void);
void vs_mm_audio_018_spectrum_end(void);

void vs_mm_audio_019_stretch_stop(void);
void vs_mm_audio_019_stretch_set_speed(void);
void vs_mm_audio_019_stretch_file(void);
void vs_mm_audio_020_stretch_string(void);

void vs_mm_audio_021_is_speech_mode(void);
void vs_mm_audio_021_speech_stop(void);
void vs_mm_audio_021_speech_start(void);
void vs_mm_audio_021_speech(void);

void vs_mm_audio_022_fmr(void);
void vs_mm_audio_022_fmr_freq_seek_start(void);
void vs_mm_audio_022_fmr_freq_seek_callback(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid);
void vs_mm_audio_022_fmr_is_valid_stop(void);
void vs_mm_audio_022_fmr_stop(void);
void vs_mm_audio_022_fmr_power_on(void);
void vs_mm_audio_022_fmr_power_off(void);
void vs_mm_audio_022_fmr_record_callback(S32 result, void *user_data);
//#ifdef FM_RADIO_RECORD
void vs_mm_audio_022_fmr_record_pause(void);
void vs_mm_audio_022_fmr_record_resume(void);
//#endif /* FM_RADIO_RECORD */ 

void vs_mm_audio_023_mma_exit(void);
void vs_mm_audio_023_mma_stop(void);
void vs_mm_audio_023_mma_play(void);
void vs_mm_audio_023_mma_resume(void);
void vs_mm_audio_023_mma_pause(void);
void vs_mm_audio_023_mma_cb(kal_int32 handle, kal_int32 result, void* user_data);
void vs_mm_audio_023_mma_refresh(void);
void vs_mm_audio_023_mma(void);

void vs_mm_audio_024_play_err_file(void);


void vs_mm_audio_025_stream_put_data(void);
void vs_mm_audio_025_stream_play(void);


void vs_mm_audio_misc_play_file_setting_save(void);
void vs_mm_audio_misc_set_volume_sub(volume_type_enum type);
void vs_mm_audio_misc_set_volume_add(volume_type_enum type);
void vs_mm_audio_misc_spectrum_time_cnt(void);
void vs_mm_audio_misc_progress_time_cnt(void);

void vs_mm_audio_misc_record_file_setting_save(void);
void vs_mm_audio_misc_play_err_file_setting_save(void);

void vs_mm_audio_misc_cache_update_duration(U32 duration);
void vs_mm_audio_misc_cache_draw_items(void);
void vs_mm_audio_misc_set_string_buffer(vs_mm_audio_string_type_enum type);
U8 *vs_mm_audio_misc_get_audio_data(MMI_ID_TYPE i, U8 *type, U32 *filelen);
void vs_mm_audio_misc_record_callback(mdi_result result, void *user_data);
void vs_mm_audio_misc_play_callback(mdi_result result, void *user_data);
void vs_mm_audio_misc_pause_callback(mdi_result result, void *user_data);
void vs_mm_audio_misc_resume_callback(mdi_result result, void *user_data);
void vs_mm_audio_misc_get_file_path(CHAR* path, CHAR* file);
void vs_mm_audio_misc_display_screen(dm_coordinates *coordinate);
void vs_mm_audio_misc_display_err_screen(dm_coordinates *coordinate);
void vs_mm_audio_misc_play_file_screen_enter(void);
void vs_mm_audio_misc_play_err_file_screen_enter(void);
void vs_mm_audio_misc_play_string_screen_enter(void);
void vs_mm_audio_misc_play_id_screen_enter(void);
void vs_mm_audio_misc_play_screen_exit(void);
void vs_mm_audio_misc_record_screen_enter(void);
void vs_mm_audio_misc_record_screen_exit(void);
void vs_mm_audio_misc_snd_screen_enter(void);
void vs_mm_audio_misc_snd_screen_exit(void);
void vs_mm_audio_misc_bg_screen_enter(void);
void vs_mm_audio_misc_bg_screen_exit(void);
void vs_mm_audio_misc_vibrator_screen_enter(void);
void vs_mm_audio_misc_surround_screen_enter(void);
void vs_mm_audio_misc_speech_screen_enter(void);
void vs_mm_audio_misc_speech_screen_exit(void);
void vs_mm_audio_misc_fmr_screen_enter(void);
void vs_mm_audio_misc_fmr_get_signal_level_callback(U8 signal_level);
void vs_mm_audio_misc_fmr_is_valid_callback(MMI_BOOL is_valid);
void vs_mm_audio_misc_fmr_draw_freq(void);
void vs_mm_audio_misc_eq_screen_enter(void);
void vs_mm_audio_misc_reverb_screen_enter(void);
void vs_mm_audio_misc_spectrum_screen_enter(void);
/* Anwar - Begin */
void vs_mm_audio_misc_bass_screen_enter(void);
void vs_mm_audio_026_bass_turn_on(void);
void vs_mm_audio_026_bass_turn_off(void);

void vs_mm_audio_misc_bt_volume_screen_enter(void);
void vs_mm_audio_misc_play_file_through_bt_screen_enter(void);
#ifdef __BT_SPK_VOL_CONTROL__
extern MMI_BOOL vs_mm_audio_misc_027_bt_volume_sync_callback(U8 volume, MMI_BOOL is_mute);
#endif


void vs_mm_audio_022_fmr_rds_enable(void);
void vs_mm_audio_022_fmr_rds_disable(void);
void vs_mm_audio_022_fmr_rds_redraw(void);
#ifdef __FM_RADIO_RDS_SUPPORT__ 
void vs_mm_audio_022_fmr_rds_callback(mdi_rds_event_struct *buffer,void* user_data);
#endif
void vs_mm_audio_022_fmr_rds_polling(void); 

void vs_mm_audio_misc_bg_play_by_app(void);
void vs_mm_audio_029_misc_play(void);
void vs_mm_audio_029_bg_play_by_app_operate(void);
MMI_BOOL vs_mm_audio_029_misc_bg_callback_hdlr(mdi_result result);
mmi_ret vs_mm_audio_029_bg_play_delete_history_hdlr(mmi_event_struct *event);

void vs_mm_audio_006_get_size_limit(void);
MMI_BOOL vs_mm_audio_001_is_aac_file_seekable(void);

void vs_mm_audio_028_play_text(void);
void vs_mm_audio_misc_play_text_screen_enter(void);

void vs_mm_audio_030_play_voice_tag(void);
void vs_mm_audio_misc_play_voice_tag_screen_enter(void);

void vs_mm_audio_031_vr_voice_record(void);
void vs_mm_audio_misc_vr_voice_record_screen_enter(void);

/* Anwar - End */

// Isiah Begin

void vs_mm_audio_032(void);
void vs_mm_audio_033(void);
void vs_mm_audio_034(void);
void vs_mm_audio_035(void);

// Isiah End
void vs_mm_audio_misc_draw_string_type(void);
void vs_mm_audio_misc_draw_file_type(void);
void vs_mm_audio_misc_id_pass(void);
void vs_mm_audio_misc_id_fail(void);
void vs_mm_audio_misc_string_pass(void);
void vs_mm_audio_misc_string_fail(void);
void vs_mm_audio_misc_file_pass(void);
void vs_mm_audio_misc_file_fail(void);
void vs_mm_audio_misc_record_pass(void);
void vs_mm_audio_misc_record_fail(void);
void vs_mm_audio_misc_other_pass(void);
void vs_mm_audio_misc_other_fail(void);
void vs_mm_audio_misc_fmr_pass(void);
void vs_mm_audio_misc_fmr_fail(void);
void vs_mm_audio_misc_mma_pass(void);
void vs_mm_audio_misc_mma_fail(void);
void vs_mm_audio_misc_err_file_pass(void);
void vs_mm_audio_misc_err_file_fail(void);
//#if defined(__BITSTREAM_API_SUPPORT__)
void vs_mm_audio_misc_stream_play_screen_enter(void);
void vs_mm_audio_misc_play_stream_pass(void);
void vs_mm_audio_misc_play_stream_fail(void);
void vs_mm_audio_misc_display_stream_screen(dm_coordinates *coordinate);
//#endif
void vs_mm_audio_misc_manual(void);
void vs_mm_audio_entry_scr(void);

void vs_mm_misc_init_audio(void);

#endif /* VS_MMAUDIO_H */ 

#endif /* __MAUI_SDK_TEST__ */ 

