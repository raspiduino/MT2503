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
 *   SDKMMAudio.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
#ifndef _SDKMMAUDIO_H_
#define _SDKMMAUDIO_H_

#include "MMI_features.h"

#include "mdi_datatype.h"
//#include "mdi_include.h"
#include "Mdi_audio.h"

    #include "MMIDataType.h"
    #include "kal_general_types.h"
/* Audio */
extern mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style);

extern mdi_result mdi_audio_play_string(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data);
extern mdi_result mdi_audio_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_play_string_portion_with_vol_path(
       			    void *audio_data,
		            U32 len,
		            U8 format,
					U32 start_offset,
					U32 end_offset,
		            U8 play_style,
		            mdi_ext_callback handler,
		            void *user_data,
		            U8 volume,
		            U8 path);
extern mdi_result mdi_audio_play_string_with_vol_path_non_block(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_ext_callback handler, void *user_data);
extern mdi_result mdi_audio_play_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_ext_callback handler,
                    void* user_data,
                    U8 volume,
                    U8 path);

extern mdi_result mdi_audio_stop_id(U16 audio_id);
extern mdi_result mdi_audio_stop_string(void);
extern mdi_result mdi_audio_stop_file(void);
extern mdi_result mdi_audio_stop_all(void);
extern mdi_result mdi_audio_stop_fmr(void);
extern mdi_result mdi_audio_pause(mdi_ext_callback handler, void *user_data);
extern mdi_result mdi_audio_resume(mdi_ext_callback handler, void *user_data);

extern mdi_result mdi_audio_start_record_with_limit(
                    void *file_name,
                    U8 format,
                    U8 quality,
                    mdi_ext_callback handler,
                    void* user_data,
                    U32 size_limit,
                    U32 time_limit);
extern mdi_result mdi_audio_stop_record(void);
extern void mdi_audio_resume_background_play(void);
extern void mdi_audio_suspend_background_play(void);

extern void mdi_audio_set_volume(U8 type, U8 volume);

extern void mdi_audio_set_mute(U8 vol_type, MMI_BOOL mute);

extern U32 mdi_audio_get_midi_size_limit(void);

extern void mdi_audio_set_headset_mode_output_path(unsigned char device);
extern mdi_result mdi_audio_set_vibrator_enabled(MMI_BOOL enable);
extern mdi_state mdi_audio_get_state(void);

extern MMI_BOOL mdi_audio_is_background_play_suspended(void);
extern MMI_BOOL mdi_audio_is_idle(void);
extern MMI_BOOL mdi_audio_is_playing(U16 audio_mode);
extern MMI_BOOL mdi_audio_is_speech_mode(void);
extern mdi_result mdi_audio_start_calc_spectrum(void);
extern mdi_result mdi_audio_stop_calc_spectrum(void);
extern mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p);
extern MMI_BOOL mdi_audio_is_pure_audio(void *file_name);
extern mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p);
extern mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p);
extern mdi_result mdi_audio_get_progress_time(U32 *progress_time_p);
extern mdi_result mdi_audio_set_progress_time(U32 progress);

/*audio build cache*/
extern void mdi_audio_start_build_cache(
                    kal_wchar *filename,
                    U8 *cache_p, 
                    U32 cache_size,
                    U8 *file_buf_p,
                    U32 file_buf_size,
                    U8 *proc_buf_p,
                    U32 proc_buf_size,
                    void (*handler)(void*),
                    U32 *build_cache_progress);
extern void mdi_audio_stop_build_cache(void);
extern void mdi_audio_close_build_cache(void);
extern void mdi_audio_reset_build_cache_variables(void);
extern MMI_BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p);
extern MMI_BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p);

extern void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration));
extern MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename);


extern mdi_result mdi_audio_play_file_portion_with_vol_path(
                    void *file_name,
                    U32 start_offset,
                    U32 end_offset,
                    U8 play_style,
                    void *cache_p,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
                    
extern mdi_handle mdi_audio_mma_open_file(U16 app_id, void *file_name, U8 repeats, MMI_BOOL is_pdl, mdi_mma_callback callback, void *user_data);
extern mdi_handle mdi_audio_mma_open_string(U16 app_id, void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback, void *user_data);
extern mdi_result mdi_audio_mma_play(mdi_handle handle);
extern mdi_result mdi_audio_mma_pause(mdi_handle handle);
extern mdi_result mdi_audio_mma_resume(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop(mdi_handle handle);
extern mdi_result mdi_audio_mma_close(mdi_handle handle);
extern kal_bool mdi_audio_mma_is_idle(void);
extern kal_bool mdi_audio_mma_is_open(void);
extern mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, U32 start_time);

/* FM Radio Begin */
/* functions in blocking mode */
extern void mdi_fmr_power_on_with_path(U8 path, mdi_ext_callback handler, void *user_data);
extern void mdi_fmr_power_off(void);
extern void mdi_fmr_set_freq(U16 freq);
extern void mdi_fmr_mute(U8 mute);

/* functions in non-blocking mode */
void mdi_fmr_check_is_valid_stop(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (MMI_BOOL is_valid));
extern void mdi_fmr_cancel_checking_is_valid_stop(void);
void mdi_fmr_get_signal_level(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (U8 sig_lvl));
extern void mdi_fmr_cancel_getting_signal_level(void);
extern void mdi_fmr_evaluate_threshold(void);
extern void mdi_fmr_set_channel(MMI_BOOL is_mono);
/* FM Radio End */

/* FM Radio Record Begin */
#if 1   /* FM_RADIO_RECORD */
extern mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality);
extern void mdi_fmr_record_finish_ind(void *inMsg);
extern mdi_result mdi_fmr_stop_record(void);
extern mdi_result mdi_fmr_pause_record(void);
extern mdi_result mdi_fmr_resume_record(void);
#endif /* 1 */ 
/* FM Radio Record END */

#if defined(BGSND_ENABLE)
extern MMI_BOOL mdi_audio_snd_is_idle(void);
extern mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len);
extern mdi_result mdi_audio_snd_check_file_format(void *file_name);
extern mdi_result mdi_audio_snd_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U16 repeat,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_snd_play_file_with_vol_path(
                    void *file_name,
                    U16 repeat,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern void mdi_audio_snd_play_finish_ind(void *inMsg);
extern mdi_result mdi_audio_snd_stop(void);
extern mdi_result mdi_audio_snd_set_volume(U8 volume);
#endif /* defined(BGSND_ENABLE) */ 

#if defined(__BES_TS_SUPPORT__)
extern mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format);
extern mdi_result mdi_audio_stretch_check_file_format(void *file_name);
extern mdi_result mdi_audio_stretch_set_speed(U16 speed);
extern void mdi_audio_stretch_close(void);
#endif /* #if defined(__BES_TS_SUPPORT__) */

#if defined(__BES_LIVE_SUPPORT__)
extern mdi_result mdi_audio_reverb_set_mode(U16 mode);
extern mdi_result mdi_audio_reverb_turn_on(void);
extern mdi_result mdi_audio_reverb_turn_off(void);
#endif /* #if defined(__BES_LIVE_SUPPORT__) */

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
extern mdi_result mdi_audio_surround_turn_on(U8 mode);
extern mdi_result mdi_audio_surround_turn_off(void);
#endif /* #if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) */

#if defined(__BES_EQ_SUPPORT__)
extern mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude);
extern mdi_result mdi_audio_eq_turn_on(void);
extern mdi_result mdi_audio_eq_turn_off(void);
#endif /* #if defined(__BES_EQ_SUPPORT__) */

/* for All apps */
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void);
void mdi_audio_speech_set_app_id(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);

/* for GSM & WCDMA apps */
mdi_result mdi_audio_speech_codec_start(void);
mdi_result mdi_audio_speech_codec_stop(void);

/* General purpose TTS */
#ifdef __GENERAL_TTS__
extern mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value);
extern mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param);
extern mdi_result mdi_audio_tts_stop(void);
extern mdi_result mdi_audio_tts_pause(void);
extern mdi_result mdi_audio_tts_resume(void);
#endif /*__GENERAL_TTS__*/

#endif /* _SDKMMAUDIO_H_ */

