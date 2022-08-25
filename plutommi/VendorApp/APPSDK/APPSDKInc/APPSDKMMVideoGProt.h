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
 *  SDKMMVideo.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKMMVIDEO_H_
#define _SDKMMVIDEO_H_

#include "MMI_features.h"

#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_video.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/**** RECORDER ****/
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
extern MDI_RESULT mdi_video_rec_power_on(const U16 app_id);
extern MDI_RESULT mdi_video_rec_power_off(void);
extern MDI_RESULT mdi_video_rec_record_start(S8 *filename, void (*record_result_callback) (MDI_RESULT, void*), void* user_data);
extern MDI_RESULT mdi_video_rec_record_stop(void);
extern MDI_RESULT mdi_video_rec_record_pause(MMI_BOOL stop_preview);
extern MDI_RESULT mdi_video_rec_record_resume(void);
extern MDI_RESULT mdi_video_rec_preview_start(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,                     /* which layer shall be blt by driver */
                    U32 preview_layer_flag,                 /* preview on which layer */
                    MMI_BOOL is_lcd_update,
                    mdi_video_setting_struct *setting_p);   /* video setting */
extern MDI_RESULT mdi_video_rec_preview_stop(void);
extern MDI_RESULT mdi_video_rec_save_file(S8 *filepath, void (*save_result_callback) (MDI_RESULT,void*), void* user_data);
extern MDI_RESULT mdi_video_rec_stop_save(void);
extern BOOL       mdi_video_rec_has_unsaved_file(S8 *filepath);
extern void       mdi_video_rec_delete_unsaved_file(S8 *filepath);
extern void       mdi_video_rec_get_cur_record_time(U64 *cur_record_time);
extern void       mdi_video_rec_update_para_ev(U16 para);
extern void       mdi_video_rec_update_para_zoom(U16 para);
extern U16        mdi_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height);
extern U64        mdi_video_rec_get_record_file_size(void);
extern void       mdi_video_rec_load_default_setting(mdi_video_setting_struct *setting_p);
extern MDI_RESULT mdi_video_rec_enable_partial_display(void);               /* allows to draw partial video out of lcd region */
#endif /* __MMI_VIDEO_RECORDER__ */


/* special function for Java, to update blt region while preview / record / record paused */
extern MDI_RESULT mdi_video_rec_update_blt_pause(void);
extern MDI_RESULT mdi_video_rec_update_blt_resume(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,     
                    U32 preview_layer_flag, 
                    MMI_BOOL is_lcd_update);

/* non blocking open */
extern MDI_RESULT mdi_video_ply_open_file(
                    const U16 app_id,
                    const S8 *filename,
                    void (*open_result_callback)(MDI_RESULT, mdi_video_info_struct *, void *), void *user_data);
extern MDI_RESULT mdi_video_ply_close_file(void);

extern MDI_RESULT mdi_video_ply_play(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,                         /* which layer shall be blt by driver */
                    U32 play_layer_flag, 
                    U16 repeat_count, 
                    BOOL is_visual_update, 
                    BOOL is_play_audio,
                    U8 audio_path, 
                    U16 rotate, 
                    S16 play_speed, 
                    void (*play_finish_callback) (MDI_RESULT, void *),
                    void *user_data); /* call back when play finied */

extern MDI_RESULT mdi_video_ply_stop(void);
extern MDI_RESULT mdi_video_ply_seek(U64 time);
extern MDI_RESULT mdi_video_ply_seek_and_get_frame(U64 time, gdi_handle player_layer_handle);
extern MDI_RESULT mdi_video_ply_snapshot(gdi_handle layer_handle, PS8 file_name);
extern void       mdi_video_ply_get_cur_play_time(U64 *cur_play_time);

extern MDI_RESULT mdi_video_ply_non_block_seek(U64 time, void (*seek_result_callback) (MDI_RESULT, void *user_data), void *user_data);
extern MDI_RESULT mdi_video_ply_non_block_seek_and_get_frame(
                    U64 time,
                    gdi_handle player_layer_handle,
                    void (*seek_result_callback) (MDI_RESULT, void *user_data),
                    void *user_data);

extern MDI_RESULT mdi_video_ply_stop_non_block_seek(void);
extern MDI_RESULT mdi_video_ply_set_brightness(U16 brightness);
extern MDI_RESULT mdi_video_ply_enable_partial_display(void);               /* allows to draw partial video out of lcd region */

extern MDI_RESULT mdi_video_ply_set_stop_time(U64 stop_time);               /* used by Java only */
extern MDI_RESULT mdi_video_ply_set_audio_level(U16 aud_level);             /* used by Java only */ 
extern MDI_RESULT mdi_video_ply_check_is_able_to_play(PS8 file_name);       /* call this function to check if the file can play or not */

/**** Video Clip ****/
/* these interfaces will not opened aud only video */
extern MDI_RESULT mdi_video_ply_open_clip_file(
                    const U16 app_id,
                    const S8 *filename, 
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_file(void);

extern MDI_RESULT mdi_video_ply_open_clip_id(
                    const U16 app_id,
                    U16 video_id, 
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_id(void);

extern MDI_RESULT mdi_video_ply_open_clip_buffer(
                    const U16 app_id,
                    const U8 *file_buffer,
                    const U32 buffer_len,
                    mdi_video_info_struct *info);
extern MDI_RESULT mdi_video_ply_close_clip_buffer(void);                

extern MDI_RESULT mdi_video_ply_enable_aud_only_video_clip(void);
extern BOOL mdi_video_is_playing(void);
extern BOOL mdi_video_is_recording(void);

#endif /* _SDKMMVIDEO_H_ */ 

