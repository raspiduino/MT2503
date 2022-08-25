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
 * med_v_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of media-v task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

#ifndef _MED_V_STRUCT_H
#define _MED_V_STRUCT_H

#include "app_ltlcom.h"
#include "kal_general_types.h"

/*==== DEFINES ========*/
#define MAX_MEDIA_FILE_NAME 512

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 event;
}
media_encode_visual_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_encode_meta_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
}
media_visual_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
}
media_visual_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 audio_start_frame_num;
}
media_visual_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 event;
}
media_decode_visual_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
}
media_visual_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 frame_num;
    kal_uint8 display;
}
media_visual_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_seek_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
}
media_visual_file_merge_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
}
media_visual_file_merge_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 event;
    kal_bool is_update_fps;
}
media_mjpeg_encode_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_temp_1_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_temp_2_struct;

typedef void (*medv_audio_seek_cb_fct) (kal_uint8 reason, void* param);

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    void* cache_p;
    kal_int32 cache_size;
    void* proc_buf_p;
    kal_int32 proc_buf_size;
    kal_uint32 seek_pos;
    medv_audio_seek_cb_fct cb_fct;
    void* cb_param;
}
media_audio_start_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 reason;
    void* user_data;
}
media_audio_seek_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME] ;
    void* cache_p; 
    kal_int32 cache_size;
    medv_audio_seek_cb_fct cb_fct;
    void* cb_param;
}
media_visual_audio_cache_async_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *filename ;
    void* cache_p; 
    kal_int32 cache_size;
    void* file_buf_p;
    kal_int32 file_buf_size;
    void* proc_buf_p;
    kal_int32 proc_buf_size;
    kal_uint32 *build_cache_progress;
}
media_visual_audio_cache_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *build_cache_progress;
    kal_uint8 counter;
}
media_visual_audio_cache_process_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void (*func_p)(void);
}
media_visual_run_low_priority_process_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_v_audio_record_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_v_audio_record_resume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_v_audio_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_v_audio_record_error_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_v_audio_bgsnd_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 snd_handle;
    kal_uint8 event;
}
media_v_audio_bgsnd_process_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_v_audio_bgsnd_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 mode;
}
media_v_cam_bcr_recog_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_v_cam_bcr_recog_cnf_struct, media_v_cam_bcr_abort_recog_cnf_struct, media_v_cam_bcr_abort_recog_req_struct,
media_v_cam_bcr_clear_data_req_struct;

typedef struct
{
    kal_uint16 field_type;
    kal_uint32 x1;
    kal_uint32 y1;
    kal_uint32 x2;
    kal_uint32 y2;
    kal_wchar recog_string[256];
} media_v_cam_bcr_recog_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint8 recog_number;
    media_v_cam_bcr_recog_info_struct* recog_info;
} media_v_cam_bcr_recog_result_ind_struct;



/**
 * Camera Panorama Support 
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 shot_num;
    kal_uint8 direction;
    kal_uint32 jpeg_buffer_p;
    kal_uint32 jpeg_buffer_size;
    kal_uint32 jpeg_src_width;
    kal_uint32 jpeg_src_height;
}
media_v_cam_start_bg_stitch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_v_cam_start_stitch_cnf_struct, media_v_cam_resume_bg_stitch_req_struct,
media_v_cam_stop_stitch_req_struct, media_v_cam_stop_stitch_cnf_struct, 
media_v_cam_pause_stitch_req_struct, media_v_cam_pause_stitch_cnf_struct,
media_v_cam_resume_stitch_req_struct, media_v_cam_resume_stitch_cnf_struct, 
media_v_cam_reset_panorama_req_struct, media_v_cam_reset_panorama_cnf_struct,
media_v_cam_set_stitch_mem_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 seq_no;
    kal_int16 result;
    kal_uint32 jpeg_file_address;
    kal_uint32 jpeg_file_size;
    kal_uint32 jpeg_file_width;
    kal_uint32 jpeg_file_height;
    
}media_v_cam_stitch_result_ind_struct;

/***** Streaming Record begin *****/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  request_id;
    kal_uint32  index;    
    kal_uint64  ms_time_rec;
    kal_uint64  ms_timestamp_ref;
    kal_uint8   frame_num;                      /* video only */
    kal_uint32  frame_buffer_size;
    kal_uint32  *frame_addr_p;
    kal_uint32  *frame_length_p;
    kal_uint32  *frame_flag_p;
    kal_uint32  *frame_timestamp_p;   
    kal_uint32  *aud_frm_data_p;                /* audio only */

} media_v_stream_rec_put_buffer_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 req_id;
    kal_int32  result;
    kal_uint32 index;
    kal_uint64 ms_time_rec;
    kal_uint64 ms_timestamp_ref;
} media_v_stream_rec_put_buffer_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 i_head;
    kal_uint8 i_tail;
    kal_uint8  index_v_track;   /* mtv stream index of video track */    
    kal_uint8  index_a_track;
    void *buffer_p;
    kal_uint32 buffer_count;
    kal_uint64 *ms_vid_t_rec_p;
    kal_uint64 *ms_vid_t_ref_p;
    kal_uint64 *ms_aud_t_rec_p;
    kal_uint64 *ms_aud_t_ref_p;
} media_v_stream_rec_flush_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar  *filename_p;
    kal_uint32 *be_p;
    kal_bool *abort_p;
    kal_uint16 req_id;
    kal_bool drm_encode;
} media_v_stream_rec_save_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
    kal_uint16 req_id;
} media_v_stream_rec_save_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  *be_p;
    kal_bool  init;
    kal_uint16  a_codec_type;
    kal_uint16  v_codec_type;
    kal_uint8 i_audio_track;
    kal_uint8 i_video_track;
    kal_uint32 audio_timescale;
    kal_uint32 video_timescale;
    kal_wchar *filepath_p;
} media_v_stream_rec_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 event;
}
media_visual_mp4_decode_visual_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
}
media_visual_mp4_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_mp4_seek_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 audio_start_frame_num;
}
media_visual_mp4_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    void* data;
}
media_visual_mp4_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void* data;
}
media_visual_mp4_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_mp4_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_mp4_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_visual_mp4_close_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    void* data_p;
}
media_visual_mjpg_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void* data_p;
}
media_visual_mjpg_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 audio_start_frame_num;
    void* data_p;
}
media_visual_mjpg_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void* data_p;
}
media_visual_mjpg_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
    void* data_p;
}
media_visual_mjpg_play_finish_ind_struct;


#endif /* _MED_V_STRUCT_H */ 

#endif /* MED_V_NOT_PRESENT */ 

