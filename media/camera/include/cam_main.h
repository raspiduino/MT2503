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
 * cam_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#include "med_global.h"

#ifdef __MED_CAM_MOD__

#ifndef _CAM_MAIN_H
#define _CAM_MAIN_H

#include "kal_public_defs.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "med_struct.h"

#define CAM_POWER_UP_INIT_TIME      200 /* ms, Power up polling first time period */
#define CAM_POWER_UP_POLLING_TIME   20  /* ms, Power up periodic polling time out period */
#define CAM_PREVIEW_INIT_TIME      10   /* ms, Preview polling first time period */

#ifdef CAMERA_MODULE_WITH_LCD
#define CAM_PREVIEW_POLLING_TIME    200 /* ms, Preview periodic polling time period */
#else 
#define CAM_PREVIEW_POLLING_TIME    10  /* ms, Preview periodic polling time period */
#endif 
#define CAM_CAPTURE_INIT_TIME      20   /* ms, Capture polling first time period */
#define CAM_CAPTURE_POLLING_TIME    20  /* ms, Capture periodic polling time period */

#define MAX_POWER_UP_CHECK_COUNT 4
#define MAX_PREVIEW_CHECK_COUNT 150
#define MAX_PREVIEW_RETRY_COUNT 3
#define MAX_CAPTURE_CHECK_COUNT 400
#define MAX_CAPTURE_RETRY_COUNT 3

#define CAPTURE_MEM_MARGIN  (512)       /* Minimal necessary storage space for capture. */
#define MIN_JPG_FILE_SIZE (128) /* Minimal necessary storage space for capture. */

typedef enum
{
    CAM_EVT_NOWAIT = 0,
    CAM_EVT_PREVIEW = 0x0001,
    CAM_EVT_STOP = 0x0002,
    CAM_EVT_CAPTURE = 0x0004,
    CAM_EVT_SET_PARAM = 0x0008,
    CAM_EVT_POWER_UP = 0x0010,
    CAM_EVT_AUTOFOCUS = 0X0020,
    CAM_EVT_GET_FAST_ZOOM_FACTOR = 0x0040,
    CAM_EVT_FAST_ZOOM = 0X0080,
    CAM_EVT_SET_PAL = 0X0100,
    CAM_EVT_GET_FOCUS_STEPS = 0X0200,
    CAM_EVT_POWER_DOWN = 0x0400,
    CAM_EVT_SAVE = 0x0800,
    CAM_EVT_GET_FOCUS_ZONE = 0x1000,
    CAM_EVT_BLOCK = 0x2000,
    CAM_EVT_FD = 0x4000,
    CAM_EVT_ENCODE_JPEG = 0x8000,
    CAM_EVT_QUICKVIEW = 0x00010000,
    CAM_EVT_PANO_IMG_READY = 0x00020000,
    CAM_EVT_PANO_BG_STITCH_READY = 0x00040000,
    CAM_EVT_PANO_STITCH_READY = 0x00080000,
    CAM_EVT_GET_BUFF_CONTENT = 0x00100000,
    CAM_EVT_HDR_QUICKVIEW = 0x00200000,
    CAM_EVT_HDR_MAINIMAGE = 0x00400000,
    CAM_EVT_HDR_SAVE = 0x00800000,
    CAM_EVT_PANO_QUICKVIEW_READY = 0x01000000,
    CAM_EVT_MAV_CAPTURE_IMG_READY = 0x02000000,
    CAM_EVT_MAV_STITCH_IMG_READY = 0x04000000
}
cam_wait_event_enum;

typedef enum
{
    CAM_NVRAM_READ = 0,
    CAM_NVRAM_WRITE    
}
cam_nvram_access_enum;


typedef enum {
    CAM_PANO_IDLE = 0,
    CAM_PANO_STITCH_BG,
    CAM_PANO_STITCH_BG_PAUSE,
    CAM_PANO_STITCH_FINAL,
    CAM_PANO_STITCH_PAUSE,
    CAM_PANO_STITCH_DONE
} camera_pano_state_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
extern void cam_wait_event(cam_wait_event_enum evt);
extern void cam_set_event(cam_wait_event_enum evt);

#define CAM_WAIT_EVENT(evt) cam_wait_event(evt);
#define CAM_SET_EVENT(evt) cam_set_event(evt);
#endif
/*==== PROTOTYPE ===========*/
/* main */
extern void cam_startup_hdlr(ilm_struct *ilm_ptr);
extern void cam_main(ilm_struct *ilm_ptr);
extern kal_bool cam_init(void);

/* msg handler */
extern kal_int16 cam_set_flash(kal_int16 flash_mode);
extern void cam_set_flash_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_set_camera_id_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_sensor_query_capability_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_sensor_query_zoom_info_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_send_nvram_startup_req(void);

extern void cam_set_cap_resolution_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_power_up_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_power_down_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_preview_callback(kal_uint8 cause);

extern void cam_focus_callback(void *pCallbackPara, kal_uint16 CallbackParaLen);
extern void cam_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_capture_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_encode_capture_image_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_free_working_buffer(void);
extern void cam_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_buffer_content_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_predicted_image_size_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_focus_zone_req_hdlr(ilm_struct* ilm_ptr);
extern void cam_save_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_get_fd_result_req_hdlr(ilm_struct* ilm_ptr);
extern void cam_set_fd_id_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_unset_fd_id_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_pause_preview_postproc_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_resume_preview_postproc_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_stop_fast_zoom(void);
extern void cam_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_focus_steps_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_zoom_step_factor_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_stitch_result_ind_hdlr(ilm_struct *ilm_ptr);
extern void cam_start_stitch_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_stitch_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_resume_stitch_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_pause_stitch_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_reset_panorama_3a_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_set_stitch_mem_hdlr(ilm_struct *ilm_ptr);
extern void cam_encode_panorama_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_autocap_result_req_hdlr(ilm_struct* ilm_ptr);

extern void cam_hdr_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_hdr_save_images_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_send_save_hdr_images_req(module_type src_mod_id, kal_wchar* captured_filepath, kal_wchar* hdr_filepath);

extern void cam_profiling_set_active_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_profiling_set_buffer_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_profiling_log_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_profiling_get_append_req_hdlr(ilm_struct *ilm_ptr);

/* ilm */
extern void cam_send_xenon_flash_status_ind(kal_uint16 seq_num);
extern void cam_send_stitch_result_ind(kal_uint8 seq_no, kal_int16 result, kal_uint32 jpeg_file_address,kal_uint32 jpeg_file_size, kal_uint32 jpeg_file_width, kal_uint32 jpeg_file_height);
extern void cam_send_panorama_quickview_image_ind(kal_int16 result, kal_uint32 start_x,kal_uint32 start_y, kal_uint32 width, kal_uint32 height);
extern void cam_send_hdr_result_ind(kal_int16 result, kal_uint8 buffer_type, kal_uint32 buffer_address, kal_uint32 buffer_size);
extern void cam_send_mav_stitch_result_ind(kal_int16 result, kal_uint32 buffer_address,kal_uint32 buffer_size, kal_uint8 seq_num);
extern void cam_send_mav_capture_image_ready_ind(kal_int16 result, kal_uint8 captured_number, kal_uint8 total_number, kal_uint8 seq_num);

extern void cam_send_set_camera_id_req(module_type src_mod_id, void *data);
extern void cam_send_sensor_query_capability_req(module_type src_mod_id, void *data);
extern void cam_send_sensor_query_zoom_req(module_type src_mod_id, void *data);
extern void cam_send_power_up_req(module_type src_mod_id, void *data);
extern void cam_send_power_down_req(module_type src_mod_id, kal_int16 delay_time);
extern void cam_send_preview_req(module_type src_mod_id, void *data);
extern void media_cam_stop_preview(module_type src_mod_id);
extern void cam_send_capture_req(module_type src_mod_id, void *data);
extern void cam_send_encode_capture_image_req(module_type src_mod_id, kal_uint8 **buf_pp, kal_uint32 *buf_size_p);
extern void cam_send_stop_req(module_type src_mod_id);
extern void cam_send_set_param_req(module_type src_mod_id, kal_uint16 param_id, kal_int32 value);
extern void cam_send_set_flash_req(module_type src_mod_id, kal_int16 flash_mode);
extern void cam_send_set_cap_resolution_req(module_type src_mod_id, void *config);
extern void cam_send_ready_ind(kal_int16 result);
extern void cam_send_preview_fail_ind(kal_int16 result);
extern void cam_send_event_ind(kal_uint32 event, kal_uint8 cause);
extern void cam_send_capture_event_ind(kal_int16 result, kal_uint16 count);
extern void cam_send_autofocus_process_done_ind(kal_uint8 result, kal_uint32 zone);
extern void cam_send_start_fast_zoom_req(
                module_type src_mod_id,
                kal_bool zoom_in,
                kal_uint8 zoom_limit,
                kal_uint8 zoom_step,
                kal_uint8 zoom_speed);
extern void cam_send_stop_fast_zoom_req(module_type src_mod_id);
extern void cam_send_get_zoom_step_factor_req(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step);
extern void cam_send_get_focus_zone_req(module_type src_mod_id, media_cam_af_zone_para_struct* zone);
extern void cam_send_get_fd_result_req(module_type src_mod_id, media_cam_fd_result_struct* fd_result_p);
extern void cam_send_stop_preview_req(module_type src_mod_id);

/* api */
extern void cam_set_result(kal_int32 result);
extern void cam_send_save_req(module_type src_mod_id, kal_wchar* filepath);
extern void cam_send_get_buffer_content_req(module_type src_mod_id, void* data);
extern void cam_send_get_predicted_image_size_req(module_type src_mod_id, void* data);
extern void cam_send_pause_preview_postproc_req(module_type src_mod_id);
extern void cam_send_resume_preview_postproc_req(module_type src_mod_id);
extern void cam_send_set_fd_id_req(module_type src_mod_id,kal_uint32 fd_id);
extern void cam_send_unset_fd_id_req(module_type src_mod_id);
extern void cam_send_fd_result_ind(media_cam_fd_result_struct* result);

extern void cam_send_start_stitch_req(module_type src_mod_id, media_cam_start_stitch_req_struct *panorama_data);
extern void cam_send_abort_stitch_req(module_type src_mod_id);
extern void cam_send_reset_panorama_3a_req(module_type src_mod_id);
extern void cam_send_resume_stitch_req(module_type src_mod_id);
extern void cam_send_pause_stitch_req(module_type src_mod_id);
extern void cam_send_stitch_memory_req(module_type src_mod_id, media_cam_set_stitch_mem_req_struct *stitch_data);
extern void cam_send_encode_panorama_req(module_type src_mod_id, media_cam_panorama_encode_req_struct *encode_data);
extern void cam_send_get_autocap_result_req(module_type src_mod_id, media_cam_autocap_result_struct* autocap_result_p);

extern void cam_send_stop_hdr_req(module_type src_mod_id, kal_wchar* filepath);

extern void cam_send_profiling_set_active_req(module_type src_mod_id, kal_bool is_active);
extern void cam_send_profiling_set_buffer_req(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size);
extern void cam_send_profiling_log_req(module_type src_mod_id, kal_uint32 log_id);
extern void cam_send_profiling_get_append_req(module_type src_mod_id, kal_uint32 buf_address);

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))

//#define __CATS_DEBUG_TRACE__

#ifdef __CATS_DEBUG_TRACE__
    #define CATS_TRACE(...) kal_print_string_trace(MOD_ENG, TRACE_INFO, "[CATS]"__VA_ARGS__)
#else
    #define CATS_TRACE(...)
#endif

typedef enum
{
    CATS_FEATURE_GET_SENSOR_ID = 0,
    CATS_FEATURE_GET_PATTERN_FORMAT,
    CATS_FEATURE_GET_TEST_PATTERN,
    CATS_FEATURE_COMPARE_TEST_PATTERN,
    CATS_FEATURE_STESS_TEST,            /* Not used now. */
    CATS_FEATURE_CAMERA_PREVIEW,
    CATS_FEATURE_CAMERA_CAPTURE,
    CATS_FEATURE_VIDEO_PREVIEW,
    CATS_FEATURE_VIDEO_RECORD
}CATS_FEATURE_ENUM;

typedef struct
{
    MM_IMAGE_FORMAT_ENUM        color_format;           /* No used now. */
    kal_uint32                  frame_buffer;
    kal_uint32                  frame_buffer_size;
    MM_IMAGE_ROTATE_ENUM        frame_rot_andle;        /* No used now. */
    kal_uint32                  frame_width;
    kal_uint32                  frame_height;
    kal_uint32                  err_ratio_threshold;    /* It will used in compare phase only. */
}cats_frame_buff_st;

typedef struct
{
    kal_uint32 pattern_size;        /* Total test pattern size in bytes. */
    kal_uint32 err_pattern_cnt;     /* Error pattern size in bytes. */
    kal_uint32 err_ratio;           /* Error ratio in percent, 0 means 0%, 99 means 99%, 0% ~ 100% */
}cats_compare_result_st;

typedef struct
{
    kal_uint32                  capture_buffer_p;       /* Capture working buffer, app provide it. */
    kal_uint32                  capture_buffer_size;    /* The buffer size is MAX_CAM_CAPTURE_ISP_BUF_SIZE */
    MM_IMAGE_ROTATE_ENUM        image_rot_andle;        /* No used now. */

    kal_uint32                  jpeg_image_address;     /* The captured jpeg buffer address */
    kal_uint32                  jpeg_image_size;        /* The captured jpeg image file size. */
    
    kal_uint32                  image_width;
    kal_uint32                  image_height;
    kal_uint16                  image_resolution;
    
    kal_int16                   flash_mode;             /* No used now, flash off now. */
    kal_uint8                   image_quality;          /* No used now, high quality now */
    kal_uint8                   capture_mode;           /* No used now, normal jpeg now. */
    kal_uint8                   snapshot_number;        /* No used now, snap 1 jpeg now. */
}cats_capture_image_st;

MM_ERROR_CODE_ENUM CATSInit(kal_uint16 app_id);
MM_ERROR_CODE_ENUM CATSFeatureCtrl(
                        CATS_FEATURE_ENUM Feature,
                        void *pParaIn,
                        void *pParaOut);
MM_ERROR_CODE_ENUM CATSDeinit();

#endif  /* #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__)) */


#endif /* _CAM_MAIN_H */ 

#endif /* __MED_CAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

