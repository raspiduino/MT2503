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
 * med_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes global context definitions of media task.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef MED_NOT_PRESENT

#ifndef _MED_CONTEXT_H
#define _MED_CONTEXT_H
#include "sd_comm_def.h"
#include "fd_comm_def.h"        // face detection common define header file
#include "mm_comm_def.h"
#include "cal_comm_def.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "l1audio.h"
#include "med_global.h"
#include "med_vid_clip_features.h"
#include "nvram_editor_data_item.h"
#include "med_struct.h"
#include "med_api.h"
#include "kal_public_api.h"
#include "drv_sw_features_mdp.h"
#include "med_vid_clip_context.h"

typedef struct med_aud_player_t med_aud_player_t;
typedef struct med_aud_recorder_t med_aud_recorder_t;

/* Audio Context Struct */
typedef struct
{
    kal_uint8 audio_mode;
    kal_uint8 state;
    kal_uint8 rat_mode;
    kal_uint8 input_device;
    kal_uint8 melody_output_device;
    kal_uint8 melody_max_volume_level;
    kal_uint8 src_id;
    
    kal_bool tone_playing;
    kal_bool speech_on;
    kal_bool audio_mute;
    kal_bool loudness_on;
    kal_bool no_cnf;

    aud_source_type_enum source_type;
    module_type src_mod;
    kal_uint16 identifier;
    
    med_aud_player_t* player_p;
    med_aud_recorder_t* recorder_p;
    kal_uint16 *ring_buf;

    kal_eventgrpid aud_event;
    kal_eventgrpid mma_event;
#if defined(__MED_VR_MOD__) || defined(__MED_VRSI_MOD__)
    kal_eventgrpid vr_event;
#endif 
#if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)
    kal_eventgrpid effect_event;
#endif 
#ifdef __MED_GENERAL_TTS__
    kal_eventgrpid tts_event;
#endif

    custom_acoustic_struct acoustic_data;
    
#ifdef __GAIN_TABLE_SUPPORT__
    kal_uint64 volume_tbl[AUD_MAX_VOLUME_TYPE]; /* 8 volume types */
#endif /* __GAIN_TABLE_SUPPORT__ */

}
aud_context_struct;

#ifdef __MED_SND_MOD__

typedef struct
{
    module_type src_mod;
    kal_uint8 state;
    kal_uint8 med_v_state;    
    kal_uint32 snd_handle;
    kal_uint16 identifier;
} aud_snd_context_struct;

#endif /* __MED_SND_MOD__ */ 

#if defined(__MED___BES_TS_SUPPORT____) || defined(__MED___BES_LIVE_SUPPORT____) || defined(__MED_AUD_SURROUND__) || defined(__MED_AUD_EQUALIZER__)
typedef struct
{
#if defined(__MED___BES_TS_SUPPORT____)
    kal_uint8 state_stretch;    /* Status of time stretch */
#endif
#if defined(__MED___BES_LIVE_SUPPORT____) || defined(__MED_AUD_SURROUND__) || defined(__MED_AUD_EQUALIZER__)
    kal_uint8 state_reverb;     /* Status of reverb */
    kal_uint8 state_surround;   /* Status of 3D surround */
#if defined(__MED_AUD_SURROUND__)
    kal_uint8 mode_surround;    /* Current 3D surround mode */
#endif
    kal_uint8 state_eq;         /* Status of equalizer */
#endif
} aud_app_context_struct;
#endif

#ifdef __MED_CAM_MOD__

typedef struct
{
    kal_uint8 state;            /* Camera module state */
    kal_uint16 app_id;
    module_type src_mod;        /* the source module of request */
    kal_eventgrpid cam_event;   /* the event group of camera module */

    kal_uint8 media_mode;       /* media mode, FILE, ARRAY, STREAM */
    kal_int32 file_handle;      /* the file handle of the file */
    kal_wchar *open_file_name_p;
    kal_wchar *file_name_p;     /* the capture file name pointer */
    kal_uint32 *file_size_p;    /* the file size pointer for capture result */
    kal_uint16 seq_num;         /* sequence num */
    kal_uint16 cam_id;          /* camera id */
    kal_uint8 source_device;
    kal_uint8 image_quality;    /* image quality */
    kal_uint8 continue_capture;
    STFSAL    fsal_file;

    kal_bool is_quickview_ready;
    kal_bool is_thumbnail_ready;
    kal_bool is_main_jpeg_ready;
    kal_bool is_waiting_save;
    kal_bool is_profiling_on;

    kal_uint8  capture_mode;
    /* preview screen parameters */
    kal_uint16 preview_width;       /* preview screen width */
    kal_uint16 preview_height;      /* preview screen height */
    kal_uint16 preview_offset_x;    /* preview screen offset x */
    kal_uint16 preview_offset_y;    /* preview screen offset y */
    kal_uint32 frame_buffer1_p;     /* pointer of the preview image frame buffer 1 */
    kal_uint32 frame_buffer2_p;     /* pointer of the preview image frame buffer 2 */
    kal_uint32 frame_buffer3_p;     /* pointer of the preview image frame buffer 3 */
    kal_uint32 frame_buffer_temp_p;     /* pointer of the preview image frame temp buffer  */	
    kal_uint32 frame_buffer_size;   /* size of the preview image frame buffer */
//#ifdef DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT
    kal_uint32 app_frame_buffer_p;
    kal_uint32 app_frame_buffer_size;
//#endif
    
    #ifdef MDP_SUPPORT_HW_OVERLAP      
    kal_bool   overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8  overlay_color_depth;              /* The color depth of overlay frame buffer */
    kal_uint8  overlay_frame_source_key;
    kal_uint16 overlay_frame_width;             /* Image width of overlay frame buffer */
    kal_uint16 overlay_frame_height;            /* Image height of overlay frame buffer */
    kal_uint32 overlay_frame_buffer_address;    /* The starting address of overlay frame buffer */
    kal_uint32 overlay_palette_addr;
    kal_uint8  overlay_palette_size;
    #endif    

    MM_IMAGE_FORMAT_ENUM  image_data_format;
    kal_uint8  ui_rotate;
    kal_uint8  preview_rotate;
    kal_uint8  capture_rotate;
    kal_uint8  sensor_rotate;
    kal_uint8  included_angle;      /* the angle between UI and sensor rotate */
    kal_uint8  quickview_lcd_rotate;

    kal_bool   binning_mode;
    kal_bool   is_fast_zoom;      /* fast zoom */
    kal_uint8  zoom_step;            /* current zoom step number */
    kal_uint8  total_zoom_step;      /* total zoom step number */
    kal_uint32 max_zoom_factor;      /* maximum zoom factor */
    kal_uint8  multishot_info;

    kal_uint8  image_mirror;                        /* horizonal/vertical mirror from image sensor */
    CAL_CAMERA_CONTRAST_ENUM        contrast_level;     /* ISP contrast gain level */
    CAL_CAMERA_SATURATION_ENUM      saturation_level;   /* image processor saturation level */
    CAL_CAMERA_SHARPNESS_ENUM       sharpness_level;
    CAL_CAMERA_WB_ENUM              wb_mode;            /* white balance mode */
    CAL_CAMERA_EV_ENUM              ev_value;           /* EV adjust value */
    CAL_CAMERA_BANDING_FREQ_ENUM    banding_freq;       /* Banding frequency selection */
    CAL_CAMERA_IMAGE_EFFECT_ENUM    image_effect;       /* image effect for preview */
    CAL_CAMERA_SCENE_MODE_ENUM      scene_mode;
    CAL_CAMERA_FLASH_ENUM           flash_mode;         /* AUTO, ON, OFF, REDEYE */
    CAL_CAMERA_AF_RANGE_ENUM        af_range;    
    CAL_CAMERA_AF_OPERATION_MODE_ENUM   af_operation_mode;
    CAL_CAMERA_AE_METERING_MODE_ENUM    ae_metering_mode;    

    #ifdef AF_SUPPORT
    CAL_CAMERA_AF_RESULT_STRUCT af_result;
    #endif

    #if defined(__MED_CAM_FD_SUPPORT__)    
    kal_bool   fd_enable;                 /* flag of fd enable: KAL_FALSE, KAL_TRUE */
    kal_bool   sd_enable;
    kal_uint32 extmem_fd_start_address; /* external memroy start address for fd buffer cachable */
    kal_uint32 extmem_fd_size;          /* external memory size for fd buffer cachable */
    FD_RESULT_STRUCT fd_result;
    SD_RESULT_STRUCT sd_result;
    #endif
    kal_uint8 camera_scene_detected_mode;   // for ASD result

    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;             /* external memory size for hardware engine buffer */
    kal_uint8  capture_mem_result;      /* memory out result */

    kal_uint8 expo_bracket_level;
    
    #if defined(__CAM_DZ_NEED_EXTRA_MEM__)
    kal_uint32 dz_extmem_address;       /* external memroy start address for digital zoom */
    kal_uint32 dz_extmem_size;          /* external memory size for digital zoom */
    #endif

    #ifdef __YUVCAM_INTERPOLATION_SW__
    kal_uint16 interpolate_image_width;
    kal_uint16 interpolate_image_height;
    kal_uint32 interpolate_work_buffer_address;
    #endif

    kal_bool   quickview_output; /* is direct couple to another buffer */
    kal_uint8  quickview_output_type;
    kal_uint16 quickview_output_width;
    kal_uint16 quickview_output_height;
    kal_uint32 quickview_output_buffer_address;
    kal_uint32 quickview_output_buffer_size;
    
    kal_uint32 capture_buffer_p;        /* pointer of the capture image buffer */
    kal_uint32 capture_buffer_size;

#if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
    kal_uint32 capture_y_buffer_address;
    kal_uint32 capture_y_buffer_size;
    kal_uint32 capture_u_buffer_address;
    kal_uint32 capture_u_buffer_size;
    kal_uint32 capture_v_buffer_address;
    kal_uint32 capture_v_buffer_size;
#endif

    kal_uint32 app_capture_buffer_p;        /* pointer of the capture image buffer */
    kal_uint32 app_capture_buffer_size;

    #ifdef __MED_CAM_BESTSHOT_SUPPORT__
    kal_uint32 bss_buffer1_p;
    kal_uint32 bss_buffer1_size;
    kal_uint32 bss_buffer2_p;
    kal_uint32 bss_buffer2_size;
    kal_uint32 best_image_buffer_p;
    kal_uint32 best_image_p;
    kal_uint32 best_image_size;
    #endif /* __MED_CAM_BESTSHOT_SUPPORT__ */   
#ifdef __MED_CAM_HDR_SUPPORT__
    kal_uint32 hdr_src_buffer_p;
    kal_uint32 hdr_src_buffer_size;
    kal_uint32 hdr_dst_image_p;                 /* the hdr processed image */
    kal_uint32 hdr_dst_image_size;              /* the hdr processed image size */
    kal_uint32 hdr_working_buffer_p;
    kal_uint32 hdr_working_buffer_size;
    kal_uint32 hdr_quickview_buffer_p;
    kal_uint32 hdr_quickview_buffer_size;
    kal_wchar *hdr_file_name_p;                 /* the file name pointer */
    kal_bool   is_hdr_done;
    kal_bool   is_hdr_waiting_save;
#endif    
    
    void        **capture_buffer_pp;           /* pointer of the capture image buffer */
    kal_uint32  *capture_buffer_size_p;

    kal_bool    raw_capture_enable;         /* enable/disable sensor raw data captured to memory before ISP processing */
    kal_uint32  raw_image_buffer_address;   /* the buffer address for store sensor bayer image */

    kal_uint32 thumbnail_buffer_address;
    kal_uint32 thumbnail_buffer_size;
    kal_uint32 thumbnail_image_address;
    kal_uint32 thumbnail_image_size;

    kal_uint32 jpeg_buffer_address;        /* pointer of the capture image buffer */
    kal_uint32 jpeg_buffer_size;
    kal_uint32 jpeg_image_address;        /* pointer of the capture image buffer */
    kal_uint32 jpeg_image_size;
    
    kal_uint8 snapshot_number;          /* snapshot number */
    kal_uint8 current_shot_number;
    kal_uint8 captured_number;
    jpegs_struct jpeg_file_info;
    jpegs_struct *jpeg_file_info_p;
    /* lcd layer parameters */
    kal_bool lcd_update;
    kal_uint8 lcd_id;                   /* LCD ID */
    kal_uint32 update_layer;            /* the updated layer */
    kal_uint32 hw_update_layer;         

    kal_uint32 file_size;
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint16 image_resolution;

    kal_int8   pano_state;
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    kal_bool   is_bg_stitching;
    kal_bool   is_stitch_done;
    kal_bool   is_waiting_stitch;
    kal_int16  stitch_result;
    kal_uint32 stitch_jpeg_file_address;
    kal_uint32 stitch_jpeg_file_size;
    kal_uint32 stitch_jpeg_file_width;
    kal_uint32 stitch_jpeg_file_height;    
    kal_uint32 stitch_image_address;        /* pointer of the capture image buffer */
    kal_uint32 stitch_image_size;
    kal_uint32 bg_stitch_count;
    MM_IMAGE_FORMAT_ENUM stitch_image_format;
    kal_uint16 stitch_quickview_start_x;
    kal_uint16 stitch_quickview_start_y;
    kal_uint16 stitch_quickview_width;
    kal_uint16 stitch_quickview_height;
    AUTOCAP_RESULT_STRUCT autocap_result;
    kal_uint32 stitch_buffer_address;    
    kal_uint32 stitch_buffer_size;
    kal_uint32 stitch_app_buffer_address;    
    kal_uint32 stitch_app_buffer_size;    
    kal_uint8  stitch_direction;
    kal_uint8  stitch_seq_no;
    kal_bool   quickview_output_resize_by_buffer_size_enable;
#endif /*__MED_CAM_PANORAMA_VIEW_SUPPORT__*/
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    CAL_MAV_RESULT_STRUCT mav_result;
	CAL_MAV_CAP_RESULT_STRUCT mav_cap_result;    
	kal_uint8 mav_seq_num;
#endif /* defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__) */
    kal_bool   is_waiting_burst_capture_stop; /* wiat for burst shot complete */

    kal_bool   jaia_disable;
}
cam_context_struct;

#endif /* __MED_CAM_MOD__ */ 

#ifdef __MED_IMG_MOD__
typedef struct
{
    kal_uint8 state;            /* image module state */
    module_type src_mod;        /* the source module of request */
    kal_eventgrpid img_event;   /* the event group of image module */

    kal_uint8 media_mode;       /* the media mode like file, array, stream */
    kal_uint8 media_type;       /* JPG, GIF, ... */
    kal_bool has_retried;
    kal_bool jpeg_retry_thumbnail;
    kal_uint16 prev_result;
    kal_int32 file_handle;      /* the file handle of the file */
    kal_wchar *file_name_p;     /* the file name pointer */
    kal_uint32 *file_size_p;    /* file size pointer after encoding */

    kal_uint8 retry_conut;  /* the retry count for decode/encode in case of hardware failed */
    kal_bool processing;    /* flag to indicate the decoding process is on */

    kal_uint16 seq_num;                 /* sequence num from the request */
    kal_uint32 file_buffer_address;     /* the start address of file located */
    kal_uint32 file_buffer_size;        /* the buffer size of jpeg file */
    kal_uint32 expected_encode_size;
    kal_int32 file_size;               /* the size of file to be decoded or encoded */
    kal_uint32 intmem_start_address;    /* internal memory start address for hardware engine buffer */
    kal_uint32 intmem_size;             /* internal memory size for hardware engine buffer */
    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;             /* external memory size for hardware engine buffer */
    kal_uint32 image_buffer_address;    /* image buffer address for jpeg decode result */
    kal_uint32 image_buffer_size;       /* image buffer size for jpeg decode result */
    kal_uint32 image_buffer_address1;   /* image buffer address 1 for jpeg decode thumbnail if necessary */
    kal_uint16 image_width;             /* the image width after decoder and resizer */
    kal_uint16 image_height;            /* the image height after decoder and resizer */
    kal_uint16 display_width;           /* the display width after decoder and resizer */
    kal_uint16 display_height;          /* the display height after decoder and resizer */
    kal_uint16 image_clip_x1;           /* clip window start x for clipping decoded image */
    kal_uint16 image_clip_x2;           /* clip window end x for clipping decoded image */
    kal_uint16 image_clip_y1;           /* clip window start y for clipping decoded image */
    kal_uint16 image_clip_y2;           /* clip window end y for clipping decoded image */
    kal_uint8 blocking;                 /* blocking decode or not */

    kal_uint32 y_address;    /* image buffer address for jpeg decode result */
    kal_uint32 u_address;    /* image buffer address for jpeg decode result */
    kal_uint32 v_address;    /* image buffer address for jpeg decode result */
    kal_uint32 yuv_channel_size;       /* image buffer size for jpeg decode result */
    kal_uint16 intmem_src; /* intmem_src: external or internal */
    
    void (*callback) (kal_int32 result);
}
img_context_struct;

#endif /* __MED_IMG_MOD__ */ 

#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)

typedef enum
{
    VID_TIME_STRETCH_UNKNOWN,
    VID_TIME_STRETCH_NO,
    VID_TIME_STRETCH_YES
} video_time_stretch_enum;

#define VID_MP4_FSAL_BUF_SIZE           (1024 / 4)
#define VID_MP4_STCO_BUF_SIZE           (512 / 4)
#define VID_MP4_STSZ_BUF_SIZE           (512 / 4)
#define VID_MP4_STBL_BUF_SIZE           (1024 / 4 * 8)

typedef struct
{
    kal_uint8 state;

    module_type src_mod;
    kal_eventgrpid vid_event;
    kal_uint16 app_id;
    
    kal_uint16 scenario_id;     /* Give a scenario usage */
#ifdef __VIDEO_SUBTITLE_SUPPORT__     
    mpl_player_external_api_t extern_api;
#endif

    kal_bool is_recorder_existed;

    kal_uint32 sensor_frame_rate;
    kal_uint32 encode_frame_rate;
    kal_uint32 bitrate;

    
    kal_uint8 media_mode;           /* the media mode like file, array, stream */
    kal_uint8 media_type;           /* 3GP, ... */
    kal_int32 file_handle;          /* the file handle of the file */
    kal_uint64 current_time;        /* the current time duration of the video play */
    kal_uint64 current_frame_num;
    kal_uint64 total_time;          /* the total time duration of the video file */
    kal_uint8 audio_channel_no;     /* audio channel count */   
    kal_uint16 audio_sample_rate;   /* audio sample rate */
    med_track_enum open_track;
    kal_bool is_seekable;
#ifdef __VIDEO_CLIPPER_SUPPORT__     
    kal_bool is_proprietary;
#endif
#ifdef __VIDEO_3D_ANAGLYPH__    
    kal_uint32 track_num;
    mpl_player_video_track_info_t track_info[VID_MAX_VIDEO_TRACK_NUM];
#endif   
#ifdef __VIDEO_SUBTITLE_SUPPORT__ 
    kal_uint32 subtitle_num;
    mpl_player_subtitle_track_info_t subtitle_info[VID_MAX_VIDEO_SUBTITLE_NUM];
#endif
    kal_uint8 get_frame;            /* get frame when seek */
    kal_uint8 bit_stream_type;      /* bit stream type, 3GP or MP4 */
    kal_uint64 recorded_size;       /* recorded size (file size) */

    kal_bool is_power_on;
    kal_uint16 seq_num;
    kal_uint16 lcd_id;
    kal_uint16 cam_id;          /* camera id */    
    kal_uint16 rec_app_id;          /* app id */
    kal_uint32 file_buffer_address;     /* the start address of file located */
    kal_uint32 file_size;               /* the size of file to be decoded */
    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;             /* external memory size for hardware engine buffer */
    kal_uint32 encode_one_frame_duration;
    
    kal_uint32 rec_align_buffer_size;
    kal_uint32 rec_align_buffer_address;

    kal_uint32 frame_buffer_size;
    kal_uint32 frame_buffer_address_1;
    kal_uint32 frame_buffer_address_2;  /* double buffer address for idp rotate VR5 */
    kal_uint32 frame_buffer_address_3;  /* frame buffer 3 */
    kal_uint32 frame_buffer_address_temp;  /* frame buffer 3 */
    kal_uint16 image_width;             /* the image width after decoder and resizer */
    kal_uint16 image_height;            /* the image height after decoder and resizer */
    kal_uint16 display_width;           /* the display width after decoder and resizer */
    kal_uint16 display_height;          /* the display height after decoder and resizer */
    kal_uint8 blocking;                 /* blocking decode or not */
    MM_IMAGE_ROTATE_ENUM preview_rotate;
    MM_IMAGE_ROTATE_ENUM included_angle;      /* the angle between UI and sensor rotate */
    MM_IMAGE_ROTATE_ENUM encode_rotate;
    kal_bool is_using_sw_rotator;

    
    kal_uint8 em_mode;                  /* video engineering mode */
    kal_uint8 vt_mode;
    kal_int16 error_code;               /* error code */

    kal_bool is_preview_stopped;        /* is preview stopped when paused */

    /* player */
    kal_bool is_enable_aud_only;        /* allows to open aud only video */
    kal_bool force_seek;
    kal_bool is_lcd_updated;

    kal_wchar current_file_name[MAX_FILE_NAME_LEN]; /* file name for recording */
    kal_wchar storing_path[MAX_FILE_NAME_LEN];      /* file path for recording */

    /* VAL new */
    kal_bool is_fast_zoom;      /* fast zoom */
    kal_uint8 ui_rot_angle;     /* MM_IMAGE_ROTATE_ENUM */
#ifdef __CAM_AUTO_FOCUS__
    CAL_CAMERA_AF_RESULT_STRUCT af_result;
#endif
    kal_bool is_rec_yuv;
}
vid_context_struct;






#endif /* defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__) */


#ifdef __MED_WEBCAM_MOD__

typedef struct
{
    kal_uint8 state;                /* Camera module state */
    module_type src_mod;            /* the source module of request */
    kal_eventgrpid webcam_event;    /* the event group of wedcam module */
    kal_uint16 seq_num;             /* sequence num */
    kal_uint16 app_id;
    
    kal_uint8 *buffer_addr;
    kal_uint32 buffer_size;
    MM_IMAGE_ROTATE_ENUM image_rotate;
    kal_uint16 banding;
    kal_uint32 intmem_start_address;    /* internal memory start address for hardware engine buffer */
    kal_uint32 intmem_size;             /* internal memory size for hardware engine buffer */
    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;             /* external memory size for hardware engine buffer */
    kal_uint32 buffer_rotate_working_buf_p;    
    kal_uint32 buffer_rotate_working_buf_size; 

    webcam_default_jpeg_file_info default_jpeg_files;   /* default JPEG files for displaying when interrupt */

    kal_uint8 *jpeg_work_addr;
    kal_uint32 jpeg_work_size;
    
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
webcam_context_struct;

#endif /* __MED_WEBCAM_MOD__ */ 

#ifdef __MED_TVO_MOD__

typedef struct
{
    kal_uint8 state;            /* Camera module state */
    module_type src_mod;        /* the source module of request */
    kal_eventgrpid tvo_event;   /* the event group of camera module */
    kal_uint16 seq_num;         /* sequence num */

    /* TV Setting */
    kal_uint8 tv_output_mode;               /* tv output mode, MED_TVO_MODE1,... */
    kal_uint8 tv_output_format;             /* tv output format, MED_TV_FORMAT_NTSC,... */
    kal_bool tv_output;
    kal_bool tv_connected;                  /* a flag to check whether the TV is connected */
    kal_bool tv_vertical_fileter;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_rotate_buffer1_address;   /* rotate buffer1 for TV source buffer */
    kal_uint32 tv_rotate_buffer2_address;   /* rotate buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
    /* LCD Setting */
    kal_uint32 roi_background_color;        /* set the background color */
}
tvo_context_struct;

#endif /* __MED_TVO_MOD__ */ 

/* Media task Context Struct */
typedef struct
{
    kal_uint16 my_mod_id;
    med_nvram_state_enum nvram_state;

    event_scheduler *event_scheduler_ptr;

    void *ext_mem_p;
    void *aud_mem_p;
#ifdef __VIDEO_STANDALONE_MEMORY__    
    void *vid_mem_p;
#endif

#if defined(__DIRECT_SENSOR_SUPPORT__)
    void *int_dcm_mem_p;
#endif

    aud_context_struct aud_context;
#ifdef __MED_SND_MOD__
    aud_snd_context_struct snd_context;
#endif 
#ifdef __MED_IMG_MOD__
    img_context_struct img_context;
#endif 
#ifdef __MED_CAM_MOD__
    cam_context_struct cam_context;
#endif 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
    vid_context_struct vid_context;
#endif 
#if defined(__MED_WEBCAM_MOD__)
    webcam_context_struct webcam_context;
#endif 
#if defined(__MED_TVO_MOD__)
    tvo_context_struct tvo_context;
#endif
#ifdef __MED_VID_CLIP_MOD__
    vid_clip_context_struct vid_clip_context;
#endif
}
med_context_struct;

/*==== GLOBAL VARIABLES ============*/

/* context of media task */
extern med_context_struct med_context;
extern med_context_struct *med_context_p;

/* context of audio manager tast */
extern aud_context_struct *aud_context_p;

#ifdef __MED_SND_MOD__
extern aud_snd_context_struct *aud_snd_cntx_p;
#endif 
#ifdef __MED_IMG_MOD__
extern img_context_struct *img_context_p;
#endif 
#ifdef __MED_CAM_MOD__
extern cam_context_struct *cam_context_p;
#endif 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
extern vid_context_struct *vid_context_p;
#endif 
#if defined(__MED_WEBCAM_MOD__)
extern webcam_context_struct *webcam_context_p;
#endif 
#if defined(__MED_TVO_MOD__)
extern tvo_context_struct *tvo_context_p;
#endif 
#ifdef __MED_VID_CLIP_MOD__
extern vid_clip_context_struct *vid_clip_context_p;
#endif
/* for media common use */
#endif /* _MED_CONTEXT_H */ 

#endif /* MED_NOT_PRESENT */ 

