/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*   mpl_vt.h
*
* Project:
* --------
*	MediaTek
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*=============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*-----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
*==============================================================================
*****************************************************************************/

#ifndef MPL_VT_H
#define MPL_VT_H

#include "kal_general_types.h"
#include "mpl_common.h" // the common defition for MPL
//#include "video_types_v2.h"
//#include "va2_comp_video_renderer.h"
//#include "video_encoder_component_if_v2.h"
#include "lcd_if.h"
#include "video_encoder_if.h"

#define VIDEO_VT_IL_INPUT_BUFFER_Q_NUM 10

typedef void (*PFN_EVENT_CALLBACK_T)(void *param);

typedef struct
{
    kal_uint8* ext_conponent_mem_ptr;
    kal_uint8* int_conponent_mem_ptr;
    kal_uint32 ext_conponent_mem_size;
    kal_uint32 int_conponent_mem_size;
} VideoCall_alloc_memory_struct;

typedef struct
{
    PFN_EVENT_CALLBACK_T *prEncCallback;
    PFN_EVENT_CALLBACK_T *prDecCallback;
    VideoCall_alloc_memory_struct alloc_memory_param;
} VideoCall_ilclient_init_param_struct;

typedef struct
{
    kal_uint8* ext_conponent_mem_ptr;
    kal_uint8* int_conponent_mem_ptr;
} VideoCall_free_memory_struct;

typedef struct
{
    VideoCall_free_memory_struct free_memory_param;
} VideoCall_ilclient_deinit_param_struct;

typedef enum
{
    MPL_VT_PARAM_PFN_GET_BUFFER ,            /*  */
    MPL_VT_PARAM_PFN_RETURN_BUFFER ,      /*  */
    MPL_VT_PARAM_CODEC_ENCODE_FORMAT,    /*  */
    MPL_VT_PARAM_CODEC_DECODE_TYPE,    /*  */
    MPL_VT_PARAM_ENCODE_IFRAME,             /**/
    MPL_VT_PARAM_GET_SNAPSHOT,    /*  */
    MPL_VT_PARAM_GET_VOS,
    MPL_VT_PARAM_SET_CONTROL_VOS,    
    MPL_VT_PARAM_TOTAL_MAX

}mpl_vt_param_enum;

typedef kal_uint8* (*PFN_VAL_VT_GET_BUFFER_T)(void);
typedef void (*PFN_VAL_VT_COMPLETE_BUFFER_T)(kal_uint8* pu1BuffAddr);

typedef enum  // for MPL_VT_PARAM_CODEC_ENCODE_FORMAT
{
    VIDEO_ENC_INPUT_YUV_LINE_BASE = 0,
    VIDEO_ENC_INPUT_YUV_BLOCK_BASE
}VIDEO_ENC_INPUT_TYPE;

typedef enum
{
    MPL_VT_SCENARIO_ENC,
    MPL_VT_SCENARIO_DEC,
    MPL_VT_SCENARIO_MAX
}mpl_vt_scenario_enum;

typedef enum
{
    MPL_VT_CONTROL_INIT,          /*  */
    MPL_VT_CONTROL_OPEN,         /*  */
    MPL_VT_CONTROL_PAUSE,       /*  */
    MPL_VT_CONTROL_RESUME,     /*  */
    MPL_VT_CONTROL_CLOSE,        /*  */
    MPL_VT_CONTROL_DEINIT,       /*  */
    MPL_VT_CONTROL_TOTAL_MAX
}mpl_vt_control_enum;

typedef enum {
    VIDEO_CALL_CODEC_NONE,
    VIDEO_CALL_CODEC_MPEG4 = 1,
    VIDEO_CALL_CODEC_H263 = 2,
    VIDEO_CALL_CODEC_H264 = 4,
    VIDEO_CALL_CODEC_VC1 = 8
} VIDEO_CALL_CODEC_TYPE;

typedef enum
{
    VIDEO_CALL_QUALITY_LOW = 2,
    VIDEO_CALL_QUALITY_NORMAL,
    VIDEO_CALL_QUALITY_FINE,
    VIDEO_CALL_QUALITY_HIGH,
    VIDEO_CALL_QUALITY_LOW_LIGHT,
    VIDEO_CALL_MAX_QUALITY_LEVEL
}VIDEO_CALL_QUALITY;

typedef struct
{
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 bitrate;
    kal_uint32 frame_rate;
    kal_uint32 yuv_skip_count;
    VIDEO_CALL_QUALITY quality_mode;
    Media_Format audio_format;
    kal_uint32 max_packet_size;
//    video_call_callback  callback;
    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;

    // advance feature
    kal_bool b_yuv_source;
    kal_uint32 yuv_duration;
    kal_uint32 yuv_addr;
}Video_Call_Enc_Info;

typedef struct
{
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 bitrate;

} VideoCall_enc_init_param_struct;

typedef enum
{
    MPL_VT_CODEC_11A = 10,
    MPL_VT_CODEC_MPEG4,
    MPL_VT_CODEC_H263,
    MPL_VT_CODEC_H264,
    MPL_VT_CODEC_UNKNOWN
} MPL_VT_CODEC_TYPE_T;

typedef struct
{
    MPL_VT_CODEC_TYPE_T enc_param_EncoderType;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 bitrate;
    kal_uint32 yuv_duration;
    kal_uint32 yuv_addr;
    kal_bool is_image_view;
    kal_uint32 u4FrameRate;
    kal_bool is_restartopen;
    kal_uint32 u4TimeIncrResolution;

} VideoCall_enc_open_param_struct;

typedef struct
{
    kal_bool dummy;

} VideoCall_enc_close_param_struct;

typedef struct
{
    kal_bool is_running;

} VideoCall_enc_deinit_param_struct;

typedef struct
{
    kal_uint32  u4_width; /**< width in pixel. */
    kal_uint32  u4_height; /**< height in pixel. */
} MPL_VT_RESOLUTION_T;

typedef struct
{
  lcd_frame_update_struct     r_mtk_lcd_config; /**< lcd config. */
  kal_uint32                  dspl_dev_handle; /**< Display Device handle */
  kal_uint32                  dspl_ctx_handle; /**< Display Context handle */
  kal_uint32                  dspl_element_handle; /**< Display Element handle */
} MPL_VT_renderer_display_surface_t;

typedef struct
{
    kal_uint32  u4_fb_addr_plane0; /**< If RGB or YUV packed format is in use, only plane0 is in use. If YUV planar format, Y plane frame buffer address. */
    kal_uint32  u4_fb_addr_plane1; /**< If YUV planar format, U plane frame buffer address. */
    kal_uint32  u4_fb_addr_plane2; /**< If YUV planar format, V plane frame buffer address. */
} MPL_VT__FRAME_BUFFER_ADDRESS_T;

typedef struct
{
  MPL_VT__FRAME_BUFFER_ADDRESS_T  r_fb_addr; /**< fb address(es). */
  kal_uint16                  u2_index; /**< buffer index. */
} MPL_VT_renderer_dst_fb_t;

typedef enum
{
    MPL_VT_RENDERER_COLOR_DEFAULT_ERR = 0 /**< default error. */
  , MPL_VT_RENDERER_COLOR_RGB565
  , MPL_VT_RENDERER_COLOR_RGB888 /**< R in MSB. */
  , MPL_VT_RENDERER_COLOR_BGR888 /**< B in MSB. */
  , MPL_VT_RENDERER_COLOR_ARGB8888
  , MPL_VT_RENDERER_COLOR_PACKED_UYVY422
  , MPL_VT_RENDERER_COLOR_YUV444 /**< YUV444 planar format. */
  , MPL_VT_RENDERER_COLOR_YUV422 /**< YUV422 planar format. */
  , MPL_VT_RENDERER_COLOR_YUV420 /**< YUV420 planar format. */
  , MPL_VT_RENDERER_COLOR_YUV411 /**< YUV411 planar format. */
  , MPL_VT_RENDERER_COLOR_YUV400 /**< YUV400 planar format. */
  , MPL_VT_RENDERER_COLOR_4X4_BLOCK_YUV420 /**< MTK specific 4x4 block-based YUV420 planar format produced by HW video codec. */
  , MPL_VT_RENDERER_COLOR_MAX
} MPL_VT_RENDERER_COLOR_FORMAT_T;

typedef struct
{
    MPL_VT_renderer_display_surface_t lcd_data;
    MPL_VT_CODEC_TYPE_T dec_param_DecoderType;
    MPL_VT_renderer_dst_fb_t dec_param_fb;
    MPL_VT_renderer_dst_fb_t dec_param_fb2;
    MPL_VT_RESOLUTION_T  dec_param_fb_size;
    kal_bool dec_triger_lcd;
    MPL_VT_RESOLUTION_T dec_param_dst_size;
    MPL_VT_RENDERER_COLOR_FORMAT_T format;	
} VideoCall_dec_init_param_struct;

typedef struct
{
  kal_uint16  u2_cw_rotate_angle; /**< CW. 0, 90, 180, 270 only. Default 0. */
  kal_bool    b_flip; /**< KAL_TRUE to enable flipping. Default FALSE. */
} MPL_VT_renderer_rotate_flip_t;

typedef struct
{
    MPL_VT_renderer_rotate_flip_t dec_param_rot_flip;

} VideoCall_dec_open_param_struct;

typedef struct
{
    void* dummy;

} VideoCall_dec_pause_param_struct;

typedef struct
{
    MPL_VT_renderer_display_surface_t lcd_data;
    MPL_VT_renderer_dst_fb_t dec_param_fb;
    MPL_VT_renderer_dst_fb_t dec_param_fb2;
    MPL_VT_renderer_rotate_flip_t dec_param_rot_flip;
    MPL_VT_RESOLUTION_T  dec_param_fb_size;
    MPL_VT_RESOLUTION_T dec_param_dst_size;
    kal_bool dec_triger_lcd;
    kal_bool is_fg_dec;
    kal_bool is_peer_camera_on;

} VideoCall_dec_resume_param_struct;

typedef struct
{
    kal_bool dummy;

} VideoCall_dec_close_param_struct;

typedef enum {
    MPL_VT_TRANSMIT_SEND,    /*  */
    MPL_VT_TRANSMIT_GET,    /*  */
    MPL_VT_TRANSMIT_TO_MAX    /*  */
}mpl_vt_transmit_enum;

typedef struct
{
    kal_bool    b_clip_enable; /**< KAL_TRUE to enable clipping function. */
    kal_uint32  u4_clip_top; /**< [0, u4_clip_bottom]. */
    kal_uint32  u4_clip_left; /**< [0, u4_clip_right]. */
    kal_uint32  u4_clip_bottom; /**< [u4_clip_top, (height-1)] */
    kal_uint32  u4_clip_right; /**< [u4_clip_left, (width-1)] */
} MPL_VT_CLIP_WINDOW_T;

typedef struct
{
    void* frame_meta;
    kal_bool b_sync_frame;
    kal_uint8 session_id;
    kal_uint8* frame_data_ptr;
    kal_uint32 frame_size;
    kal_uint32 frame_duration;
    MPL_VT_RESOLUTION_T dec_param_dst_size;
    MPL_VT_CLIP_WINDOW_T  dec_param_clip_wnd;
    kal_bool is_fg_dec;
    kal_bool is_peer_camera_on;

} VideoCall_dec_trigger_param_struct;

typedef struct
{
    kal_uint8* buffer_addr;
    kal_uint32 buffer_size;	
    kal_uint32 width;
    kal_uint32 height;
    MPL_VT_RENDERER_COLOR_FORMAT_T format;

} VideoCall_dec_get_snapshot_param_struct;

typedef struct
{
    kal_uint32 u4Address;
    kal_uint32 u4Length;
} MPEG4_PACKET_PAYLOAD_INFO_T;

typedef struct
{
    kal_uint32 u4PayloadNumber;
    MPEG4_PACKET_PAYLOAD_INFO_T* pu1PayloadAddress;
} MPEG4_PACKET_INPUT_PARAM_T;

typedef struct
{
    kal_uint8 u4Uplink_denominator;
    kal_uint8 u4Uplink_numerator;
} VideoCall_enc_consume_param_struct;

typedef enum{
    MPL_VT_ERROR_NONE,    /*  */
    MPL_VT_ERROR_BUFFER_FULL,    /*  */
    MPL_VT_ERROR_BUFFER_EMPTY    /*  */
}mpl_vt_error_code_enum;

typedef struct
{
    kal_bool b_new_session;
    kal_bool b_new_frame;
    kal_bool b_header_not_complete;
    kal_bool b_sync_frame;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 real_width;
    kal_uint32 real_height;
    kal_uint32 prev_frame_duration;
    kal_uint32 length;
}Video_Call_Parse_Info;

typedef enum
{
	VIDEO_CALL_STATUS_OK = 0,
	VIDEO_CALL_STATUS_CODEC_UNSUPPORT,
	VIDEO_CALL_STATUS_NOT_CODED,
	VIDEO_CALL_STATUS_BUFFER_UNAVIL,
	VIDEO_CALL_STATUS_ERROR,
	VIDEO_CALL_STATUS_ENCODER_CLOSED,
	VIDEO_CALL_STATUS_MAX
}VIDEO_CALL_STATUS;

typedef struct
{
    kal_uint8 * u4Address;
    kal_uint32 u4Length;
} MPL_VT_CONTROL_VOS_T;

typedef struct
{
    void (*init_ilclient)(VideoCall_ilclient_init_param_struct param); /* To init the VT IL Client. (alloc memory)*/
    void (*deinit_ilclient)(VideoCall_ilclient_deinit_param_struct param); /* To deinit the VT IL Client. (free memory)*/
    media_error_t (*get_param)(mpl_vt_param_enum param, void *value); /* To get param*/
    media_error_t (*set_param)(mpl_vt_param_enum param, void *value); /* To set param*/
    media_error_t (*control)(mpl_vt_scenario_enum type, mpl_vt_control_enum control, void * param); /*Control IL Client*/
    mpl_vt_error_code_enum (*transmit)(mpl_vt_scenario_enum type, mpl_vt_transmit_enum control, void * param); /*Transmit buffer to IL Client*/
    kal_bool (*genheader)(VIDEO_ENCODER_GEN_HEADER_PARAM_T* prSetting); /*Gen header for VT control channel*/
    VIDEO_CALL_STATUS (*parse_packet)(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info); /*Control IL Client*/
}mpl_vt_t;

extern  kal_bool construct_mpl_vt(mpl_vt_t* mpl);

#endif  // MPL_VT_H

