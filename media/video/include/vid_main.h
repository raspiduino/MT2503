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
 * vid_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of video module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
#ifndef VID_MAIN_H
#define VID_MAIN_H

#ifndef MED_NOT_PRESENT

#define MED_HIDE_VIDEO_TEMP_FILE
#ifdef MED_HIDE_VIDEO_TEMP_FILE
#define VID_TEMP_FILE_ATTRIBUTES FS_READ_WRITE|FS_CREATE_ALWAYS|FS_ATTR_HIDDEN
#else 
#define VID_TEMP_FILE_ATTRIBUTES FS_READ_WRITE|FS_CREATE_ALWAYS
#endif 


#include "fs_type.h"
#include "med_global.h"
#include "kal_public_defs.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "med_status.h"
#include "fsal.h"
#include "stack_config.h"
#include "med_main.h"
#include "vid_if.h"

#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)

typedef enum
{
    VID_EVT_NOWAIT      = 0x00000000,
    VID_EVT_RECORD      = 0x00000001,
    VID_EVT_STOP        = 0x00000002,
    VID_EVT_OPEN_FILE   = 0x00000004,
    VID_EVT_CLOSE_FILE  = 0x00000008,
    VID_EVT_PLAY        = 0x00000010,
    VID_EVT_SEEK        = 0x00000020,
    VID_EVT_PAUSE       = 0x00000040,
    VID_EVT_RESUME      = 0x00000080,
    VID_EVT_SNAPSHOT    = 0x00000100,
    VID_EVT_GET_IFRAME  = 0x00000200,
    VID_EVT_GET_INFO    = 0x00000400,
    VID_EVT_FILE_MERGE  = 0x00000800,
    VID_EVT_OPEN        = 0x00001000,
    VID_EVT_CLOSE       = 0x00002000,
    VID_EVT_PREVIEW     = 0x00004000,
    VID_EVT_POWER_ON    = 0x00008000,    
    VID_EVT_BLOCK       = 0x00010000,
    VID_EVT_FAST_ZOOM   = 0x00020000,
    VID_EVT_GET_FAST_ZOOM_FACTOR = 0x00040000,
    VID_EVT_SET_PARAM = 0x00080000,
    VID_EVT_AUTOFOCUS = 0X00100000,
    VID_EVT_GET_FRAME = 0x00200000,
    VID_EVT_START     = 0x00400000,
    VID_EVT_MPL_EVENT = 0x00800000,
    VID_EVT_MPL_STOP  = 0x01000000,
    VID_EVT_MPL_SAVE  = 0x02000000
}
vid_wait_event_enum;


#define VID_HAS_TRACK(track_) ((vid_context_p->video_track&track_)!=0)

#define VID_SYSTEM_FOLDER           (L"z:\\@Videos")
#define VID_INIT_FILE               (L"z:\\@Videos\\video_file.ini")
#define VID_DUMMY_INIT_FILE         (L"z:\\@Videos\\video_dummy_file.ini")
#define VID_AUDIO_FILE              (L"~audio.tmp")
#define VID_AUDIO_SAMPLE_FILE       (L"~audio_sample.tmp")
#define VID_AUDIO_REAL_META_FILE    (L"~audio_real_meta.tmp")
#define VID_VISUAL_FILE             (L"~visual.tmp")
#define VID_VISUAL_META_FILE        (L"~visual_meta.tmp")
#define VID_VISUAL_REAL_META_FILE   (L"~visual_real_meta.tmp")

#define VID_PDL_BUFFER_TIME_FOR_PLAY    (1000*6)    /* cache 6 sec for buffering */


/*==== PROTOTYPE ===========*/
/* main */
extern void vid_startup_hdlr(ilm_struct *ilm_ptr);
extern void vid_main(ilm_struct *ilm_ptr);
extern kal_bool vid_init(void);

/* msg handler */

extern void vid_release_memory(void);
extern void vid_update_frame_to_buffer(void);
extern kal_uint32 vid_evaluate_residual_size(kal_uint32 video_size);
extern kal_uint32 vid_evaluate_audio_real_meta_file_size(kal_uint64 audio_record_time);
extern kal_uint32 vid_evaluate_audio_meta_file_size(kal_uint64 audio_record_time);
extern kal_uint32 vid_file_visual_residual_size(void);
extern kal_uint32 vid_file_audio_residual_size(void);
extern kal_uint32 vid_file_meta_residual_size(void);
extern kal_uint32 vid_get_current_file_size(void);
extern kal_uint16 vid_get_disc_free_space(kal_wchar *dir_name, kal_uint64 *free);
extern void vid_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_recorder_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_fast_zoom_factor_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_power_up_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_power_down_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_focus_zone_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_rec_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_record_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_open_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_close_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_play_finish_hdlr(void);
extern void vid_play_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_seek_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_frame_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_reserved_disc_size_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_play_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_check_med_ready_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_pause_visual_update_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_resume_visual_update_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_record_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_record_frame_num_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_record_size_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clean_file_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_pdl_percent_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_pdl_max_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_check_is_pdl_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_play_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_seek_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_play_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_encode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_decode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_audio_play_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_error_recover_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_clean_temp_files(void);
extern kal_bool vid_check_unfinished_file(kal_wchar* filepath);
extern void vid_stop_unfinished_task(void);
extern kal_bool vid_is_dummy_aud_playing(void);
extern kal_bool vid_is_audio_channel_available(void);
extern kal_int16 vid_abort_by_client_switching(void);
extern kal_bool vid_is_pdl_audio_buf_underflow(void);
extern void vid_stop_visual(void);
extern void vid_stop_audio(void);
extern void vid_set_handle(kal_int32 handle);
extern void vid_set_vol_level(kal_uint8 vol_level);
extern void vid_calc_max_play_time(void);
/* MED -> MMI Indication */
extern void vid_send_record_finish_ind(kal_int16 result);
extern void vid_send_file_merge_done_ind(kal_int32 result);
extern void vid_send_file_ready_ind(kal_int16 result);
extern void vid_send_play_finish_ind(kal_int16 result);
extern void vid_send_seek_done_ind(kal_int16 result);
extern void vid_send_event_ind(kal_uint32 event, kal_int32 cause);
extern void vid_send_autofocus_process_done_ind(kal_uint8 result, kal_uint32 zone);
extern void vid_clipper_open_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_prepare_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_start_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_close_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_get_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_clipper_event_ind_hdlr(ilm_struct *ilm_ptr);

/* vid recorder internal */
#if defined(__MED_VID_ENC_MOD__)
extern med_result_enum vid_cal_stop_fast_zoom(void);
extern med_result_enum vid_cal_stop_preview(void);

extern med_result_enum vid_recorder_deinit(void);
extern med_result_enum vid_recorder_get_current_record_time(kal_uint64 *current_record_time_p);
extern med_result_enum vid_recorder_stop_record(void);
extern kal_uint32      vid_recorder_evaluate_real_meta_file_size(void);
extern kal_uint32      vid_recorder_get_meta_file_size(void);
extern kal_uint32      vid_recorder_get_video_file_size(void);
extern med_result_enum vid_recorder_get_current_record_size(kal_uint64 *current_record_size_p);
#endif

extern void vid_send_prepare_cnf_ind(kal_int16 result);
extern void vid_send_clip_finish_ind(kal_int16 result);
extern void vid_send_clip_event_ind(kal_uint32 event, kal_int32 cause);

/* api */
extern void vid_set_result(kal_int32 result, kal_uint32 line);
extern void vid_enter_state(kal_uint8 state, kal_uint32 line);
extern void vid_set_event(kal_uint32 event);
extern void vid_wait_event(kal_uint32 event);
extern void vid_set_result_and_event(kal_int32 result, kal_uint32 event);

/* util */
extern void vid_debug_print_cur_state(kal_uint32 line);
extern void vid_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr);


#define VID_WAIT_EVENT(evt) vid_wait_event(evt);
#define VID_SET_EVENT(evt) vid_set_event(evt);

#endif /* __MED_VID_DEC_MOD__  || __MED_VID_REC_MOD__*/

#endif /* MED_NOT_PRESENT */ 
#endif /* _VID_MAIN_H */ 

