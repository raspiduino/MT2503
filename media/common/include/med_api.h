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
 * med_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes exported apis of media task.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _MED_API_H
#define _MED_API_H

#include "cal_comm_def.h"
#include "pano_comm_def.h"   /* postproc related definition */

#include "med_struct.h"     /* message structure */
#include "med_global.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mpl_common.h" // mpl common type definition
/*==== CONSTANT ====*/

enum
{
    AUD_BLOCK_ALL = 0,
    AUD_BLOCK_ALL_EXCEPT_TONE,
    AUD_NO_OF_BLOCK_LEVEL
};

/* MMAPI audio type */
enum
{
    MMA_TYPE_UNKNOWN = -1,
    MMA_TYPE_MIDI = 0,
    MMA_TYPE_TONE,
    MMA_TYPE_WAV,
    MMA_TYPE_IMY,
    MMA_TYPE_AMR,
    MMA_TYPE_DAF,
    MMA_TYPE_MUSICAM,
    MMA_TYPE_AAC,
    MMA_TYPE_AU,
    MMA_TYPE_AWB,
    MMA_TYPE_WMA,
    MMA_TYPE_M4A,
    MMA_TYPE_AIFF,
    MMA_TYPE_RA,
    MMA_TYPE_RM,
    MMA_TYPE_RMVB,
    MMA_TYPE_RV,
    MMA_TYPE_APE,
    MMA_TYPE_MP4,
    MMA_TYPE_3GP,
    MMA_TYPE_FLV,
    MMA_TYPE_F4V,    
    MMA_TYPE_F4A,
    MMA_TYPE_VORBIS,
    MMA_TYPE_FLAC,
    MMA_NO_OF_AUDIO_TYPE
};

/* MMAPI video type */
enum
{
    MMA_TYPE_MPEG = 0,
    MMA_TYPE_H263,
    MMA_TYPE_CAM,
    MMA_NO_OF_VIDEO_TYPE
};

typedef struct
{
    kal_uint8 audio_id;
    kal_uint8 play_style;
    kal_uint64 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
}
aud_play_id_struct;

typedef struct
{
    kal_uint8 src_id;
    kal_uint8 *data_p;
    kal_uint32 len;
    kal_uint8 format;
    kal_uint8 play_style;
    kal_uint64 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    kal_uint8 blocking;
}
aud_play_string_struct;

typedef struct
{
    kal_uint8 src_id;
    kal_wchar *file_name_p;
    kal_uint8 play_style;
    kal_uint64 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void *cache_p;
}
aud_play_file_struct;

typedef struct {
    kal_uint16 *text_string;
    kal_uint16 str_type;    /* String Type */
    kal_uint16 lang;        /* Language */
    kal_uint16 app_type;    /* Application Type */
    kal_uint16 gander;      /* Gender */
    kal_uint16 identifier;  /* id for the request */
    kal_uint16 app_id;      /* app id */
    kal_uint8 volume;       /* Volume, from 0~6 */
    kal_uint8 path;         /* Audio Path */
    kal_uint8 pitch;        /* Audio Pitch, from 0~100 */
    kal_uint8 speed;        /* Audio Speed, from 0~100 */
} aud_tts_struct;

/************  MMA  ***********/
/* This must be sync with those defined in l1audio.h */
typedef enum
{
    MED_SUCCESS,
    MED_FAIL,
    MED_REENTRY,
    MED_NOT_INITIALIZED,
    MED_BAD_FORMAT,
    MED_BAD_PARAMETER,
    MED_BAD_COMMAND,
    MED_NO_HANDLER,
    MED_UNSUPPORTED_CHANNEL,
    MED_UNSUPPORTED_FREQ,
    MED_UNSUPPORTED_TYPE
} med_status_enum;

/* This must be sync with those defined in l1audio.h */
typedef enum
{
    MED_NONE,
    MED_DATA_REQUEST,
    MED_DATA_NOTIFICATION,
    MED_END,
    MED_ERROR,
    MED_REPEATED,
    MED_TERMINATED,
    MED_LED_ON,
    MED_LED_OFF,
    MED_VIBRATOR_ON,
    MED_VIBRATOR_OFF,
    MED_BACKLIGHT_ON,
    MED_BACKLIGHT_OFF
} med_event_enum;

typedef kal_int32 med_handle;
typedef kal_int32 med_event;
typedef kal_int32 med_status;
typedef void (*med_handler) (kal_int32 handle, kal_int32 event);

typedef struct
{
    kal_uint16 app_id;
    med_handler handler;
    kal_uint8 media_type;
    kal_uint8 *data;
    kal_int32 size;
    kal_wchar *file_path;
    kal_int16 repeats;  /* 0: Endless */
    kal_bool progressive_dl; /* Is a progrevvice downloading file */
    kal_uint8 output_path;
}
mma_player_struct;

typedef struct
{
    kal_uint16 app_id;
    med_handler handler;
    kal_uint8 media_type;
    kal_uint8 *data;
    kal_int32 size;
    kal_wchar *file_path;
    kal_int16 repeats;  /* 0: Endless */
    kal_bool progressive_dl; /* Is a progrevvice downloading file */
    kal_uint8 output_path;
    void *user_data; 
}
mma_player_async_struct;

#define GET_ARGB_A(_x_) (kal_uint8)((((kal_uint32)_x_)&0xff000000)>>24)
#define GET_ARGB_R(_x_) (kal_uint8)((((kal_uint32)_x_)&0x00ff0000)>>16)
#define GET_ARGB_G(_x_) (kal_uint8)((((kal_uint32)_x_)&0x0000ff00)>>8)
#define GET_ARGB_B(_x_) (kal_uint8)((((kal_uint32)_x_)&0x000000ff))

#define SET_ARGB(_a_,_r_,_g_,_b_) ((((kal_uint32)_a_)<<24)| \
                                    (((kal_uint32)_r_)<<16)|\
                                    (((kal_uint32)_g_)<<8)| \
                                    (((kal_uint32)_b_)))

enum
{
    CAM_SRC_ISP = 0,
    CAM_SRC_MEM,
    CAM_NO_OF_SRC
};


/* camera param enum */
enum
{
    CAM_PARAM_NONE = 0,
    CAM_PARAM_ZOOM_FACTOR,
    CAM_PARAM_CONTRAST,
    CAM_PARAM_BRIGHTNESS,
    CAM_PARAM_HUE,
    CAM_PARAM_GAMMA,
    CAM_PARAM_WB,
    CAM_PARAM_EXPOSURE,
    CAM_PARAM_EFFECT,
    CAM_PARAM_BANDING,
    CAM_PARAM_SATURATION,
    CAM_PARAM_NIGHT_MODE,
    CAM_PARAM_SHARPNESS,
    CAM_PARAM_EV_VALUE,
    CAM_PARAM_FLASH,
    CAM_PARAM_FLASH_MODE = CAM_PARAM_FLASH,
    CAM_PARAM_AE_METERING,
    CAM_PARAM_AF_KEY,
    CAM_PARAM_AF_METERING,
    CAM_PARAM_AF_MODE,
    CAM_PARAM_MANUAL_FOCUS_DIR,
    CAM_PARAM_SHUTTER_PRIORITY,
    CAM_PARAM_APERTURE_PRIORITY,
    CAM_PARAM_ISO,
    CAM_PARAM_DSC_MODE,
    CAM_PARAM_YUV_AF_STATUS,
    CAM_PARAM_AF_OPERATION,
    CAM_PARAM_AF_RANGE,
    CAM_PARAM_FD,
    CAM_PARAM_SD,
    CAM_PARAM_3A_ENABLE,
    CAM_NO_OF_PARAM
};

/* camera mwb operation */
enum
{
    CAM_MWB_ADJUST = 0,
    CAM_MWB_BACKUP,
    CAM_MWB_RESTORE,
    CAM_NO_OF_MWB
};

/* zoom factor enum */
enum
{
    CAM_ZOOM_1X = 0,
    CAM_ZOOM_2X,
    CAM_ZOOM_4X,
    CAM_ZOOM_6X,
    CAM_ZOOM_8X,
    CAM_NO_OF_ZOOM
};

/* Image effect enum */
enum
{
    CAM_EFFECT_NOMRAL = 0,
    CAM_EFFECT_SEPIA,
    CAM_EFFECT_WHITELINE,
    CAM_EFFECT_BLACKLINE,
    CAM_EFFECT_BW,
    CAM_EFFECT_GRAYEDGE,
    CAM_EFFECT_FILM,
    CAM_NO_OF_EFFECT
};


/* Camera- Jpeg encode quality enum */
enum
{
    CAM_JPG_QTY_LOW = 0,
    CAM_JPG_QTY_NORMAL,
    CAM_JPG_QTY_HIGH,
    CAM_JPG_QTY_FINE,
    CAM_NO_OF_JPG_QTY
};

/* camera image rotate/mirror enum */
enum
{
    CAM_IMAGE_NORMAL = 0,
    CAM_IMAGE_ROTATE_90,
    CAM_IMAGE_ROTATE_180,
    CAM_IMAGE_ROTATE_270,
    CAM_IMAGE_MIRROR,
    CAM_IMAGE_MIRROR_ROTATE_90,
    CAM_IMAGE_MIRROR_ROTATE_180,
    CAM_IMAGE_MIRROR_ROTATE_270,
    CAM_NO_OF_IMAGE_ROTATE
};


/* Special Effect for Playback and Post-processing */
enum
{
    CAM_EFFECT_DEC_NORMAL = 0,
    CAM_EFFECT_DEC_GRAYSCALE,
    CAM_EFFECT_DEC_SEPIA,
    CAM_EFFECT_DEC_SEPIAGREEN,
    CAM_EFFECT_DEC_SEPIABLUE,
    CAM_EFFECT_DEC_COLORINV,
    CAM_EFFECT_DEC_GRAYINV,
    CAM_EFFECT_DEC_WATERCOLOR,
    CAM_EFFECT_DEC_LIGHTBLUR,
    CAM_EFFECT_DEC_BLUR,
    CAM_EFFECT_DEC_STRONGBLUR,
    CAM_EFFECT_DEC_UNSHARP,
    CAM_EFFECT_DEC_SHARPEN,
    CAM_EFFECT_DEC_MORESHARPEN,
    CAM_EFFECT_DEC_MEDIAN,
    CAM_EFFECT_DEC_DILATION,
    CAM_EFFECT_DEC_EROSION,
    CAM_NO_OF_EFFECT_DEC
};

/* Adjustment Effect for Preview, Capture and MPEG4 Encode */
enum
{
    CAM_ADJ_ENC_NONE = 0,
    CAM_ADJ_ENC_HUE,
    CAM_ADJ_ENC_SATURATION,
    CAM_ADJ_ENC_GAMMA,
    CAM_ADJ_ENC_ADJR,
    CAM_ADJ_ENC_ADJG,
    CAM_ADJ_ENC_ADJB,
    CAM_ADJ_ENC_CONTRAST,
    CAM_ADJ_ENC_BRIGHTNESS,
    CAM_NO_OF_ADJ_ENC
};

/* Adjustment Effect for Playback and Post-processing */
enum
{
    CAM_ADJ_DEC_NONE = 0,
    CAM_ADJ_DEC_HUE,
    CAM_ADJ_DEC_SATURATION,
    CAM_ADJ_DEC_GAMMA,
    CAM_ADJ_DEC_ADJR,
    CAM_ADJ_DEC_ADJG,
    CAM_ADJ_DEC_ADJB,
    CAM_ADJ_DEC_CONTRAST,
    CAM_ADJ_DEC_BRIGHTNESS,
    CAM_NO_OF_ADJ_DEC
};

/* Image - Jpeg encode quality enum */
enum
{
    IMG_JPG_QTY_LOW = 0,
    IMG_JPG_QTY_NORMAL,
    IMG_JPG_QTY_HIGH,
    IMG_JPG_QTY_FINE,
    IMG_NO_OF_JPG_QTY
};

/* preview frame rate enum */
enum
{
    CAMERA_PERVIEW_FRAME_RATE = 0,
    VIDEO_PERVIEW_FRAME_RATE = 1
};

/* camera operation enum */
enum
{
    CAM_DSC_MODE = 0,
    CAM_AE_METERING,
    CAM_AF_KEY,
    CAM_AF_METERING,/* !MT6238 */
    CAM_AF_MODE,/* !MT6238 */
    CAM_MANUAL_FOCUS_DIR,
    CAM_SHUTTER_PRIORITY,/* !MT6238 */
    CAM_APERTURE_PRIORITY,/* !MT6238 */
    CAM_ISO,/* !MT6238 */
    CAM_FLASH_MODE,
    CAM_AF_OPERATION_MODE,/* MT6238 */
    CAM_AF_RANGE,/* MT6238 */
    CAM_3A_ENABLE,
    CAM_NO_OF_CAMERA_OPERATION
};


/*Dual camera modification start*/
enum
{
   CAM_MAIN_CAMERA,
   CAM_SUB_CAMERA
};
/*Dual camera modification end*/



/* af preview rotate enum */
enum
{
    CAM_AF_PREVIEW_ROTATE_0 = 0,
    CAM_AF_PREVIEW_ROTATE_90,
    CAM_AF_PREVIEW_ROTATE_180,
    CAM_AF_PREVIEW_ROTATE_270,
    CAM_NO_OF_AF_PREVIEW_ROTATE
};

/* menual focus direction enum */
enum
{
    CAM_FOCUS_STOP = 0,
    CAM_FOCUS_FORWARD,
    CAM_FOCUS_BACKWARD,
    CAM_FOCUS_FORWARD_CONTINUE,
    CAM_FOCUS_BACKWARD_CONTINUE,
    CAM_NO_OF_FOCUS_DIR
};

/* HDR buffer type */
enum
{
    CAM_HDR_CAPTURE_QUICKVIEW_RAWDATA = 0,          /* The quick view of capture image */
    CAM_HDR_CAPTURE_MAINIMAGE_JPEG,                 /* The main image of capture image */
    CAM_HDR_PROCESSED_QUICKVIEW_RAWDATA,            /* The quick view of HDR image */
    CAM_HDR_PROCESSED_MAINIMAGE_JPEG,               /* The main image of HDR image */
    CAM_NO_HDR_BUFFER_TYPE
};

/********************************************************
 *  Add for Query API
 ********************************************************/
#define CAM_PANO_MAX_SHOT_NUM (PANO_MAX_INPUT_IMAGE_NUM)





enum
{
	CAM_VIDEO_CODEDEC_MPEG=0,
	CAM_VIDEO_CODEDEV_H263,
	CAM_NO_OF_VEDIO_CODEDEC
};


/* video quality */
typedef enum
{
    VID_REC_QTY_LOW = 0,
    VID_REC_QTY_NORMAL,
    VID_REC_QTY_HIGH,
    VID_REC_QTY_FINE,

    VID_NO_OF_REC_QTY
} media_vid_rec_qty_enum;


/********************************************************/

/*==== DATATYPE ====*/

typedef struct
{
    kal_uint16 camera_append_zoom_step;
    kal_uint16 camera_append_scene_mode;
    kal_uint16 camera_append_shot_count;
}camera_log_append_struct;

#define MAX_JPEG_NUM    (20)
typedef struct
{
    kal_uint32 file_size[MAX_JPEG_NUM];
    kal_uint32 file_address[MAX_JPEG_NUM];
}
jpegs_struct;

#if defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE)
/* image */

typedef struct
{
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint8 image_quality;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint16 target_width;
    kal_uint16 target_height;
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 file_buffer_len;
    kal_uint32 expected_encode_size;
    kal_int32 *file_size_p;
    kal_uint16 seq_num;
    kal_uint8 blocking;
    kal_uint8 gray_mode;
    kal_uint8 input_type;
    kal_bool background_encode;
    kal_uint8 jpeg_yuv_mode;    /* YUV420, YUV422 or Gray mode */

    kal_bool thumbnail_mode;    /* add thumbnail in JPEG file or not */
    kal_uint16 thumbnail_width;
    kal_uint16 thumbnail_height;

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE */
    kal_uint8 overlay_color_depth;              /* 1/2/4/8 bpp */
    kal_uint8 overlay_frame_source_key;         /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */
}
img_encode_struct;

typedef struct
{
    kal_uint32 src_image_address;   /* the source image buffer start address */
    kal_uint32 dest_image_address;  /* the destination image buffer start address */
    kal_uint32 dest_buffer_size;    /* the buffer size of destination image buffer size */
    kal_uint16 src_width;           /* the width of image source */
    kal_uint16 src_height;          /* the height of image source */
    kal_uint16 src_pitch;           /* the pitch width of image source */
    kal_uint16 target_width;        /* the width of target image */
    kal_uint16 target_height;       /* the height of target image */
    kal_uint16 image_clip_x1;       /* image clip window start x */
    kal_uint16 image_clip_x2;       /* image clip window end x */
    kal_uint16 image_clip_y1;       /* image clip window start y */
    kal_uint16 image_clip_y2;       /* image clip window end x */
    kal_uint16 seq_num;             /* use for non-blocking mode */
    kal_uint8 blocking;
    kal_uint8 type;                 /* IBR1_TYPE_RGB565 or IBR1_TYPE_RGB888 */
    kal_uint8 data_order;           /* IBR1_ORDER_BGR888 or IBR1_ORDER_RGB888 */
    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */
}
img_resize_struct;

#endif /* defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE) */

/* video */

/* Bit stream type, not the file format */
enum
{
    VID_3GP_BIT_STREAM = 0,
    VID_MP4_BIT_STREAM,
    VID_NO_OF_BIT_STREAM
};

/* video em mode enum */
enum
{
    VID_EM_MODE_DISABLED = 0,
    VID_EM_MODE_ULTRA_HIGH_BITRATE,
    VID_NO_OF_EM_MODE
};

/* video param enum */
enum
{
    VID_PARAM_NONE = 0,
    VID_PARAM_CONTRAST,     /* Set */
    VID_PARAM_BRIGHTNESS,   /* Set */
    VID_PARAM_TRACK_INDEX,  /* Set */
    VID_PARAM_KEY_FRAME_TIME, /* Get */
    VID_PARAM_SUBTITLE_TRACK, /* Set */
    VID_PARAM_SUBTITLE_FONT_SIZE, /* Set */    
    VID_PARAM_SLEEP_TIME,  /* Set */
    VID_PARAM_STOP_TIME,  /* Set */
    VID_PARAM_CONTENT_DESC, /* Get */
    VID_PARAM_TIME_TO_FRAME, /* Get */
    VID_PARAM_FRAME_TO_TIME, /* Get */
    VID_PARAM_MOT_META, /* Get */
    VID_PARAM_SCRAMBLE_BUFFER, /* Set */
    VID_NO_OF_PARAM
};

#if defined (MP4_DECODE) || defined (MJPG_DECODE) || defined(__RM_DEC_SUPPORT__)

typedef struct
{
    kal_wchar *file_name_p;

    kal_uint16 image_x;
    kal_uint16 image_y;
    kal_uint32 total_frame_num;
}
vid_open_file_struct;

typedef struct
{
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 data_size;
    kal_uint16 seq_num;
    kal_uint16 max_width;
    kal_uint16 max_height;
    kal_uint16 *image_width;
    kal_uint16 *image_height;
    kal_uint64 *total_time;
    kal_uint8 blocking;
    kal_uint8 play_audio;
}
vid_open_struct;

typedef struct
{
    kal_uint8 get_frame;
    kal_uint32 frame_num;
    kal_uint64 time;
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint8 blocking;
    kal_uint16 seq_num;
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
}
vid_seek_struct;

typedef struct
{
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
}
vid_snapshot_struct;

typedef struct
{
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint16 frame_num;
    kal_uint16 seq_num;
    kal_uint8 blocking;
}
vid_get_iframe_struct;

#endif /* defined (MP4_DECODE) || defined (MJPG_DECODE) */

/* TV output mode */
enum
{
    MED_TV_OUT_DISABLE = 0,
    MED_TV_OUT_MODE1,
    MED_TV_OUT_MODE2,
    MED_TV_OUT_MODE3,
    MED_TV_OUT_MODE4
};

/* TV output format */
enum
{
    MED_TV_FORMAT_NTSC = 0,
    MED_TV_FORMAT_PALM,
    MED_TV_FORMAT_PALC,
    MED_TV_FORMAT_PAL
};

/* TV output parameter types */
enum
{
    MED_TV_PARAM_Y_COMP = 0,
    MED_TV_PARAM_U_COMP,
    MED_TV_PARAM_V_COMP,
    MED_TV_PARAM_AUD_PATH
};

/* TV output parameter values */
enum
{
    MED_TV_PARAM_GAMMA1 = 0,
    MED_TV_PARAM_GAMMA2,
    MED_TV_PARAM_GAMMA3,
    MED_TV_PARAM_GAMMA4,
    MED_TV_PARAM_GAMMA5
};

enum
{
   MED_TV_PARAM_AUD_PATH_BOTH=0,
   MED_TV_PARAM_AUD_PATH_TV,
   MED_TV_PARAM_AUD_PATH_PHONE
};

/* tv out */
typedef struct
{
    kal_uint8 tv_output_mode;
    kal_uint8 tv_output_format;
    kal_uint16 tv_output_width;     /* image width for TV output */
    kal_uint16 tv_output_height;    /* image height for TV output */
    kal_bool  tv_output_vertical_filter;
}
tvo_mode_struct;


enum
{
    CAM_ADJUST_LOW_LEVEL=0,
    CAM_ADJUST_MED_LEVEL,
    CAM_ADJUST_HIGH_LEVEL,
    CAM_NO_OF_ADJUST
};


/*==== PROTOTYPE ====*/
/* audio */
extern void media_aud_set_mute(kal_uint8 vol_type, kal_bool mute);
extern void media_aud_set_audio_mode(kal_uint8 audio_mode);
extern void media_aud_set_device(kal_uint8 audio_type, kal_uint8 device);
extern void media_aud_set_volume(kal_uint8 vol_type, kal_uint64 volume);
extern void media_aud_set_volume_ext(kal_uint8 vol_type, kal_uint64 volume, kal_bool apply, kal_bool blocking);
extern void media_aud_get_volume(kal_uint8 vol_type, kal_uint8* volume);
extern void media_aud_get_max_volume(kal_uint8* max_volume);
#ifdef __GAIN_TABLE_SUPPORT__
extern void media_aud_update_volume(kal_uint8 vol_type, kal_uint64 volume);
#endif /*__GAIN_TABLE_SUPPORT__*/

extern void media_aud_speech_set_fir_coeff(kal_int16 input_idx, kal_int16 output_idx);
extern void media_aud_speech_set_rat_mode(kal_bool speech_on, kal_uint8 rat_mode);
extern void media_aud_speech_set_enhance_mode(kal_uint8 mode);
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
extern void media_aud_speech_set_enhance_mode_ext(kal_uint8 mode, kal_uint16* param_p, kal_uint16* wb_param_p);
#endif /* __SPEECH_MODE_TABLE_SUPPORT__ */

#ifdef __DUAL_MIC_SUPPORT__
extern void mdiea_aud_mic_set_dual_nr(kal_bool is_enable);
#endif /* __DUAL_MIC_SUPPORT__ */

extern kal_int32 media_aud_play_id(module_type src_mod_id, void *id_param);
extern kal_int32 media_aud_stop_id(module_type src_mod_id, kal_uint8 audio_id);
extern kal_int32 media_aud_play_string(module_type src_mod_id, void *string_param);
extern kal_int32 media_aud_stop_string(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_play_file(module_type src_mod_id, void *file_param);
extern kal_int32 media_aud_stop_file(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_start_record(
                    module_type src_mod_id,
                    kal_wchar *file_name,
                    kal_uint8 format,
                    kal_uint8 quality,
                    kal_bool default_input,
                    kal_uint8 input_source,
                    kal_uint32 size_limit,
                    kal_uint32 time_limit);
extern kal_int32 media_aud_stop_record(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_pause(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_resume(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_set_headset_mode_output_path(module_type src_mod_id, kal_uint8 device);
#ifdef __VIBRATION_SPEAKER_SUPPORT__
extern void media_aud_vib_spk_calibration(module_type src_mod_id);
#endif

extern kal_int32 media_aud_set_vibrator_enabled(module_type src_mod_id, kal_uint8 enable);
extern kal_int32 media_aud_store(module_type src_mod_id, kal_uint8 src_id);
extern kal_int32 media_aud_restore(module_type src_mod_id, void *file_param);
extern kal_int32 media_aud_get_spectrum(module_type src_mod_id, kal_uint8 *top_p, kal_uint8 *val_p);
extern kal_int32 media_aud_get_duration(module_type src_mod_id,
                                 void *file_name,
                                 kal_uint8 *audio_data,
                                 kal_uint32 len,
                                 kal_uint8 format,
                                 kal_uint32 *time_p);
extern kal_int32 media_aud_get_mp4_duration(module_type src_mod_id,
                                 void *file_name,
                                 kal_uint8 *audio_data,
                                 kal_uint32 len,
                                 kal_uint8 format,
                                 kal_uint32 *time_p);
extern kal_int32 media_aud_get_progress_time(module_type src_mod_id, kal_uint32 *progress);
extern kal_int32 media_aud_set_progress_time(module_type src_mod_id, kal_uint32 progress);
extern kal_bool media_aud_check_is_pure_audio(module_type src_mod_id, void *file_name);
extern kal_bool media_aud_check_is_file_seekable(module_type src_mod_id, void *file_name);
extern kal_bool media_aud_check_is_file_pausable(module_type src_mod_id, void *file_name);
extern kal_bool media_aud_check_is_resource_available(aud_resource_enum resource);

#ifdef __AUDIO_TRIM_SUPPORT__
extern kal_int32 media_aud_trim_open(kal_wchar* file_name_in, kal_wchar* file_name_out, kal_uint32* handle_p);
extern kal_int32 media_aud_trim_close(kal_uint32 handle);
extern kal_int32 media_aud_trim_start(kal_uint32 handle);
extern kal_int32 media_aud_trim_stop(kal_uint32 handle);
extern kal_int32 media_aud_trim_set_param(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len);
extern kal_int32 media_aud_trim_get_param(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p);
#endif /* __AUDIO_TRIM_SUPPORT__ */

#ifndef MED_V_NOT_PRESENT
/*audio build cache*/
extern void media_aud_start_build_cache_in_async(module_type src_mod_id, kal_wchar* file_name, void* cache_p, kal_int32 cache_size, media_seek_cb_fct cb_fct, void* cb_param);
extern void media_aud_close_build_cache_in_async(module_type src_mod_id);
extern void media_aud_start_build_cache(module_type src_mod_id, void *cache_parm);
extern void media_aud_close_build_cache(module_type src_mod_id);
extern void media_aud_reset_build_cache_variables(module_type src_mod_id);
extern void media_aud_start_seek(module_type src_mod_id, void* file_name, void* cache_p, kal_int32 cache_size, kal_uint32 seek_pos, media_seek_cb_fct cb_fct, void* cb_param);
extern void media_aud_stop_seek(module_type src_mod_id);
#endif /*MED_V_NOT_PRESENT*/

/* fmr */
extern kal_int32 media_aud_fmr_power_on(module_type src_mod_id, kal_uint8 output_path);
extern kal_int32 media_aud_fmr_power_off(module_type src_mod_id);
extern kal_int32 media_aud_fmr_set_output_path(module_type src_mod_id, kal_uint8 output_path);
extern kal_int32 media_aud_fmr_set_freq(module_type src_mod_id, kal_uint16 freq);
extern kal_int32 media_aud_fmr_mute(module_type src_mod_id, kal_uint8 mute);
extern kal_int32 media_aud_fmr_evaluate_threshold(module_type src_mod_id);
extern kal_int32 media_aud_fmr_set_channel(module_type src_mod_id, kal_bool is_mono);

#ifdef __FM_RADIO_HW_SCAN__
extern kal_int32 media_aud_fmr_hw_scan(module_type src_mod_id, kal_uint8 *scan_table);
extern kal_int32 media_aud_fmr_hw_scan_abort(module_type src_mod_id);
#endif /* __FM_RADIO_HW_SCAN__ */

#ifdef __FM_RADIO_HW_SEARCH__
extern kal_int32 media_aud_fmr_seek_start(module_type src_mod_id, kal_uint16 start_freq, kal_bool is_step_up, kal_bool is_preset, kal_int16 space_value);
extern kal_int32 media_aud_fmr_seek_abort(module_type src_mod_id);
#else /* !__FM_RADIO_HW_SEARCH__ */
extern kal_int32 media_aud_fmr_check_is_valid_stop(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up);
extern kal_int32 media_aud_fmr_get_signal_level(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up);
#endif /* __FM_RADIO_HW_SEARCH__ */

#ifdef __FM_RADIO_RDS_SUPPORT__
extern kal_int32 media_aud_fmr_rds_enable(module_type src_mod_id, kal_bool af_enable, kal_bool tp_enable);
extern kal_int32 media_aud_fmr_rds_disable(module_type src_mod_id);
extern kal_int32 media_aud_fmr_rds_poll_rds_event_rds(module_type src_mod_id);
extern void media_aud_fmr_rds_set_buffer(kal_uint16 *RT_Data, kal_uint16 *PS_Data, kal_uint16 *AF_Data, kal_uint16 *TP_Data);
extern void media_aud_fmr_rds_reset_buffer(void);
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#ifdef INTERNAL_ANTENNAL_SUPPORT
extern kal_int32 media_audio_fmr_set_antenna(module_type src_mod_id, kal_bool is_short_antenna);
#endif/* INTERNAL_ANTENNAL_SUPPORT */

#ifdef __VAD_SUPPORT__
extern kal_bool media_aud_switch_vad_on_off(kal_bool on, void* param);
extern kal_bool media_aud_set_vad_level(kal_uint8 level);
extern kal_bool aud_is_vad_on(void);
extern kal_uint8 aud_get_vad_level(void);
#endif

/* MMA */
extern kal_int32 media_mma_aud_open(module_type src_mod_id, mma_player_struct *param, kal_int32 *result);
extern kal_int32 media_mma_set_cache_table(module_type src_mod_id, kal_int32 handle, kal_uint8 *cache_tbl);
extern kal_int32 media_mma_aud_close(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_play(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_stop(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_pause(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_resume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_set_start_time(
                    module_type src_mod_id,
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_int32 start_time);
extern kal_int32 media_mma_aud_set_stop_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 stop_time);
extern kal_int32 media_mma_aud_get_current_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_get_audio_info(module_type src_mod_id, kal_uint16 app_id, kal_wchar* file_path, kal_uint8 media_type, kal_uint8* data, kal_uint32 data_len, void *audio_info);
extern kal_int32 media_mma_aud_get_duration(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_get_updated_duration(module_type src_mod_id, kal_int32 handle);
extern kal_uint8 media_mma_aud_get_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_set_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 volume);
extern kal_int32 media_mma_aud_pdl_write_data_ind(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_bool is_finish);
extern kal_int32 media_mma_aud_pdl_get_buf_percent(module_type src_mod_id, kal_int32 handle, kal_uint32 cache_sec, kal_uint32 *percent);
extern kal_int16 media_mma_aud_get_med_data_type(kal_uint8 mma_type);
extern kal_int32 media_mma_aud_set_param(module_type src_mod_id, kal_int32 handle, kal_uint8 param_type, void* param_value);

#ifdef __MED_MMA_EXTRA_CTRL__
extern kal_int32 media_mma_aud_get_pitch(kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_set_pitch(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 pitch);
extern void media_mma_aud_get_rate_range(kal_uint8 media_type, kal_int32* max_rate_p, kal_int32* min_rate_p);
extern kal_int32 media_mma_aud_get_rate(kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_set_rate(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 rate);
extern kal_int32 media_mma_aud_get_tempo(kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_set_tempo(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 tempo);
extern kal_int32 media_mma_aud_open_device(module_type src_mod_id, kal_uint8 media_type);
extern kal_int32 media_mma_aud_open_device_ext(module_type src_mod_id, kal_uint8 media_type, kal_bool fast_pass);
extern kal_int32 media_mma_aud_close_device(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type);
extern kal_int32 media_mma_aud_send_long_msg(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 *buf, kal_uint16 len);
extern kal_int32 media_mma_aud_send_short_msg(
                    module_type src_mod_id,
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_uint8 type,
                    kal_uint8 data1,
                    kal_uint8 data2);
extern kal_uint8 media_mma_aud_get_channel_volume(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel);
extern kal_int32 media_mma_aud_set_channel_volume(
                    module_type src_mod_id,
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_uint8 channel,
                    kal_uint8 level);
extern void media_mma_aud_get_program(
                kal_int32 handle,
                kal_uint8 media_type,
                kal_uint8 channel,
                kal_int16 *bank,
                kal_int8 *program);
extern kal_int32 media_mma_aud_set_program(
                    module_type src_mod_id,
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_uint8 channel,
                    kal_uint8 bank,
                    kal_uint8 program);
extern kal_bool media_mma_aud_bank_support(kal_int32 handle, kal_uint8 media_type);
extern void media_mma_aud_get_bank_list(
                kal_int32 handle,
                kal_uint8 media_type,
                kal_bool custom,
                const kal_int16 **buf,
                kal_int16 *len);
extern void media_mma_aud_get_program_list(
                kal_int32 handle,
                kal_uint8 media_type,
                kal_int16 bank,
                const kal_int8 **buf,
                kal_int16 *len);
extern const kal_uint8 *media_mma_aud_get_program_name(
                            kal_int32 handle,
                            kal_uint8 media_type,
                            kal_int16 bank,
                            kal_int8 prog);
extern const kal_uint8 *media_mma_aud_get_key_name(
                            kal_int32 handle,
                            kal_uint8 media_type,
                            kal_int16 bank,
                            kal_int8 prog,
                            kal_int8 key);
extern kal_int32 media_mma_aud_set_data(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, mma_player_struct *param);
extern kal_int32 media_mma_aud_is_sp_midi(kal_int32 handle, kal_uint8 media_type);
#endif /* __MED_MMA_EXTRA_CTRL__ */


#if defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)

/* camera */
extern kal_int32 media_cam_set_cam_id(module_type src_mod_id, void *cam_id);
extern kal_int32 media_cam_sensor_query_capability(module_type src_mod_id, void *query_p);
extern kal_int32 media_cam_sensor_query_zoom_info(module_type src_mod_id, void *query_p);
extern kal_int32 media_cam_power_up(module_type src_mod_id, void *power_on);
extern kal_int32 media_cam_power_down(module_type src_mod_id, kal_int16 delay_time);
extern kal_int32 media_cam_preview(module_type src_mod_id, void *preview);
extern void media_cam_stop_preview(module_type src_mod_id);
extern void media_cam_stop(module_type src_mod_id);
extern kal_int32 media_cam_capture(module_type src_mod_id, void *capture);
extern void media_cam_set_param(module_type src_mod_id, kal_uint16 param_id, kal_int16 value);
extern void media_cam_set_flash(module_type src_mod_id, kal_int16 flash_mode);
extern void media_cam_set_cap_resolution(module_type src_mod_id, media_cam_cap_resolution_struct *img_resolution);
extern void media_cam_set_af(module_type src_mod_id, kal_uint16 param_id, kal_int16 value);

extern void media_cam_start_fast_zoom(
                module_type src_mod_id,
                kal_bool zoom_in,
                kal_uint8 zoom_limit,
                kal_uint8 zoom_step,
                kal_uint8 zoom_speed);
extern void media_cam_stop_fast_zoom(module_type src_mod_id);
extern void media_cam_get_zoom_step_factor(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step);
extern kal_uint8 media_cam_get_max_zoom_factor(kal_uint16 image_width, kal_uint16 image_height);
extern kal_int32 media_cam_encode_capture_image(module_type src_mod_id, kal_uint8 **buf_pp, kal_uint32 *buf_size_p);

extern void media_cam_flash_setting(module_type src_mod_id, kal_bool flag);
extern kal_uint8 media_cam_save_image(module_type src_mod_id, kal_wchar* filepath);
extern kal_uint8 media_cam_get_buffer_content(module_type src_mod_id, void* data);
extern kal_uint8 media_cam_get_predicted_image_size(module_type src_mod_id, void* data);
extern void media_cam_get_focus_zone(module_type src_mod_id, media_cam_af_zone_para_struct *zone);
extern void media_cam_get_fd_result(module_type src_mod_id, media_cam_fd_result_struct *fd_result);
extern kal_uint8 media_cam_pause_preview_postproc(module_type src_mod_id);
extern kal_uint8 media_cam_resume_preview_postproc(module_type src_mod_id);
extern kal_uint8 media_cam_set_fd_id(module_type src_mod_id, kal_uint32 fd_id);
extern kal_uint8 media_cam_unset_fd_id(module_type src_mod_id);

extern kal_int32 media_cam_stitch_panorama(module_type src_mod_id, media_cam_start_stitch_req_struct *panorama_data);
extern kal_int32 media_cam_abort_panorama(module_type src_mod_id);
extern kal_int32 media_cam_reset_panorama_3a(module_type src_mod_id);
extern kal_int32 media_cam_pause_panorama(module_type src_mod_id);
extern kal_int32 media_cam_resume_panorama(module_type src_mod_id);
extern kal_int32 media_cam_set_panorama_stitch_memory(module_type src_mod_id, media_cam_set_stitch_mem_req_struct *stitch_data);
extern kal_int32 media_cam_encode_panorama(module_type src_mod_id, media_cam_panorama_encode_req_struct *encode_data);
extern void media_cam_get_autocap_result(module_type src_mod_id, media_cam_autocap_result_struct *autocap_result);

extern kal_int32 media_cam_stop_hdr(module_type src_mod_id, kal_wchar* filepath);
extern kal_int32 media_cam_save_hdr_images(module_type src_mod_id, kal_wchar* captured_filepath, kal_wchar* hdr_filepath);

extern void media_cam_profiling_set_active(module_type src_mod_id, kal_bool is_active);
extern void media_cam_profiling_set_buffer(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size);
extern void media_cam_profiling_log(module_type src_mod_id, kal_uint32 log_id);
extern void media_cam_profiling_get_append(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size);

extern kal_int32 media_cam_stitch_mav(module_type src_mod_id);

extern void media_cam_set_extra_qvi_buffer(module_type src_mod_id, kal_uint32 buf_address, kal_uint32 buf_size);
#endif /* defined (ISP_SUPPORT) */

#if defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE)

/* image */
extern kal_int32 media_img_decode(module_type src_mod_id, void *decode);
extern kal_int32 media_img_encode(module_type src_mod_id, img_encode_struct *encode);
extern void media_img_stop(module_type src_mod_id);
extern kal_int32 media_img_resize(module_type src_mod_id, img_resize_struct *resize);
extern kal_int32 media_img_exif_decode(module_type src_mod_id, void *exif_decode);
#endif /* defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE) */

#if defined(MP4_ENCODE) || defined(MJPG_ENCODE)
extern void         media_vid_stop_fast_zoom(module_type src_mod_id);
extern void         media_vid_get_fast_zoom_factor(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step);
extern void         media_vid_start_fast_zoom(module_type src_mod_id,kal_bool zoom_in,kal_uint8 zoom_limit,kal_uint8 zoom_step,kal_uint8 zoom_speed);
#endif

#if defined (MP4_DECODE) || defined (MJPG_DECODE)
/* video */

extern kal_int32    media_vid_power_up(module_type src_mod_id, media_vid_power_up_req_struct *data);
extern kal_int32    media_vid_power_down(module_type src_mod_id);
extern kal_int32    media_vid_preview(module_type src_mod_id, media_vid_preview_req_struct *data);
extern kal_int32    media_vid_record(module_type src_mod_id, media_vid_record_req_struct *data);
extern kal_int32    media_vid_stop(module_type src_mod_id);
extern kal_int32    media_vid_rec_stop(module_type src_mod_id);
extern void         media_vid_file_merge(module_type src_mod_id, media_vid_file_merge_req_struct *data);
extern kal_int32    media_vid_open(module_type src_mod_id, media_vid_open_req_struct *data);
extern void         media_vid_close(module_type src_mod_id);
extern kal_int32    media_vid_play(module_type src_mod_id, media_vid_play_req_struct *data);
extern kal_int32    media_vid_seek(module_type src_mod_id, media_vid_seek_req_struct *data);
extern kal_int32    media_vid_get_frame(module_type src_mod_id, media_vid_get_frame_req_struct *data);
extern kal_int32    media_vid_pause(module_type src_mod_id, media_vid_pause_req_struct *data);
extern kal_int32    media_vid_resume(module_type src_mod_id);
extern kal_int32    media_vid_check_med_ready(module_type src_mod_id, media_vid_check_med_ready_req_struct *data);
extern kal_int32    media_vid_update_blt_pause(module_type src_mod_id, media_vid_update_blt_pause_req_struct *data);
extern kal_int32    media_vid_update_blt_resume(module_type src_mod_id, media_vid_update_blt_resume_req_struct *data);
extern kal_int32    media_vid_pause_visual_update(module_type src_mod_id, media_vid_pause_visual_update_req_struct *data);
extern kal_int32    media_vid_resume_visual_update(module_type src_mod_id, media_vid_resume_visual_update_req_struct *data);
extern kal_int32    media_vid_set_param(module_type src_mod_id, media_vid_set_param_req_struct *data);
extern kal_int32    media_vid_get_param(module_type src_mod_id, media_vid_get_param_req_struct *data);
extern kal_int32    media_vid_rec_set_param(module_type src_mod_id, kal_uint32 param_id, kal_int16 value);
extern void         media_vid_get_focus_zone(module_type src_mod_id, media_vid_af_zone_para_struct *zone_p);
extern void         media_vid_get_current_record_size(module_type src_mod_id, kal_uint64 *file_size);
extern void         media_vid_get_current_play_time(module_type src_mod_id, kal_uint64 *time);
extern kal_uint32   media_vid_recorder_get_bitrate(void);
extern kal_int32    media_vid_get_decode_time(module_type src_mod_id, kal_uint32 frame_no, kal_uint64 *time);
extern void         media_vid_get_current_record_time(module_type src_mod_id, kal_uint64 *time);
extern void         media_vid_get_current_record_frame_num(module_type src_mod_id, kal_uint64 *frame_num);
extern void         media_vid_get_current_frame_num(module_type src_mod_id, kal_uint32 *frame_num);
extern kal_bool     media_vid_get_is_lcd_updated(void);
#if defined (SUPPORT_MMAPI)
extern kal_int32    media_vid_frame_to_time(kal_uint32 frame, kal_uint64 *time);
extern kal_int32    media_vid_time_to_frame(kal_uint64 time, kal_uint32 *frame);
#endif /* SUPPORT_MMAPI */
extern kal_bool     media_vid_check_unfinished_file(module_type src_mod_id,kal_wchar* file_path);
extern void         media_vid_clean_temp_files(module_type src_mod_id);
extern void         media_vid_set_em_mode(kal_uint8 mode);
extern kal_uint8    media_vid_get_em_mode(void);
extern void         media_vid_set_vt_mode(kal_uint8 mode);
extern kal_uint8    media_vid_get_vt_mode(void);
extern kal_int32    media_vid_set_volume_level(module_type src_mod_id, kal_uint8 volume_level);
extern kal_uint8    media_vid_get_max_digital_zoom_factor(module_type src_mod_id, kal_uint16 target_width, kal_uint16 target_height);
extern void         media_vid_get_audio_profile(module_type src_mod_id, kal_uint8 *channel_no_p, kal_uint16 *sampling_rate_p);
extern kal_int32    media_vid_get_pdl_percent(module_type src_mod_id, media_vid_get_pdl_percent_req_struct *data);
extern kal_int32    media_vid_get_pdl_max_time(module_type src_mod_id, media_vid_get_pdl_max_time_req_struct *data);
extern kal_int32    media_vid_check_is_pdl_file(module_type src_mod_id, media_vid_check_is_pdl_req_struct *data);
extern void         media_vid_stop_fast_zoom(module_type src_mod_id);
extern void         media_vid_get_fast_zoom_factor(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step);
extern void         media_vid_start_fast_zoom(module_type src_mod_id,kal_bool zoom_in,kal_uint8 zoom_limit,kal_uint8 zoom_step,kal_uint8 zoom_speed);
extern void         media_vid_get_reserved_disc_size(module_type src_mod_id, kal_uint32 *size);
extern void         media_vid_set_record_yuv(module_type src_mod_id, kal_bool is_yuv);

#endif /* defined (MP4_DECODE) || defined (MJPG_DECODE) */

#ifdef __DIRECT_SENSOR_SUPPORT__
extern void media_vid_alloc_limited_avi_res(module_type src_mod_id);
extern void media_vid_free_limited_avi_res(module_type src_mod_id);
#endif /* __DIRECT_SENSOR_SUPPORT__ */

#if defined(__MED_TVO_MOD__)

extern void tvo_set_result(kal_int32 result);
extern kal_int32 media_tvo_start(module_type src_mod_id, tvo_mode_struct *mode);
extern void media_tvo_stop(module_type src_mod_id);
extern kal_int32 media_tvo_set_mode(module_type src_mod_id, tvo_mode_struct *mode);
extern kal_int32 media_tvo_set_param(module_type src_mod_id, void *data);
extern kal_uint32 media_tvo_get_current_buffer(module_type src_mod_id);

/* this function is for engineer mode only, for those dont have hw detection */
extern void media_tvo_force_init(void);

#endif /* __MED_TVO_MOD__ */

#ifdef __MED_VR_MOD__
extern kal_uint32 media_aud_vr_new_session_id(void);
extern kal_int32 media_aud_vr_get_version(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang);
extern kal_int32 media_aud_vr_get_param(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_int16 *sim,
                    kal_int16 *diff,
                    kal_int16 *rej);
extern kal_int32 media_aud_vr_set_param(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_int16 sim,
                    kal_int16 diff,
                    kal_int16 rej);
extern kal_int32 media_aud_vr_init_rcg(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 app_id);
extern kal_int32 media_aud_vr_init_trn(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 word_id,
                    kal_uint16 app_id);
extern kal_int32 media_aud_vr_voice_in(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no);
extern kal_int32 media_aud_vr_del_tag(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 word_id);
extern kal_int32 media_aud_vr_check_tag(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 word_id);
extern kal_int32 media_aud_vr_sync_db(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 *id_length_p,
                    kal_uint16 *id_array);
extern kal_int32 media_aud_vr_play_tag(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 word_id,
                    kal_uint16 identifier);
extern kal_int32 media_aud_vr_get_dir(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 *folder_name);
extern kal_int32 media_aud_vr_add_tag(
                    module_type src_mod_id,
                    kal_uint8 mode,
                    kal_uint8 lang,
                    kal_uint8 group_id,
                    kal_uint16 id_length,
                    kal_uint16 *id_array);
extern void media_aud_vr_abort(module_type src_mod_id);
#endif /* __MED_VR_MOD__ */

#ifdef __MED_VRSI_MOD__

extern kal_uint32 media_aud_vrsi_new_session_id(void);
extern void media_aud_vrsi_prompt_cnf(module_type src_mod_id, kal_uint32 session_id);
extern void media_aud_vrsi_read_dgt_adp_prompt(kal_uint8 *pmp_len, const kal_uint16 **pmp_text);
extern kal_uint16 media_aud_vrsi_read_cmd_trn_result(void);
extern void media_aud_vrsi_read_cmd_rcg_result(media_aud_vrsi_cmd_rcg_result_struct *vrsi_rcg_res);
extern void media_aud_vrsi_read_dgt_rcg_result(kal_uint16 *digit_length, kal_uint16 **digit_list);

extern kal_int32 media_aud_vrsi_init(module_type src_mod_id, kal_uint16 app_id);
extern kal_int32 media_aud_vrsi_add_tags(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 *grammar,
                    kal_uint16 tag_num,
                    kal_uint16 **name_list,
                    kal_int32 *long_list,
                    kal_uint8 *is_name_list,
                    kal_uint16 *id_list);
extern kal_int32 media_aud_vrsi_start_cmd_trn(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 *grammar,
                    kal_uint16 *tag_name,
                    kal_int32 tag_long);
extern kal_int32 media_aud_vrsi_start_cmd_rcg(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar);
extern kal_int32 media_aud_vrsi_start_digit_rcg(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 lang,
                    kal_uint16 limit);
extern kal_int32 media_aud_vrsi_start_digit_adapt(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang);
extern kal_int32 media_aud_vrsi_play_tag(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint8 *grammar,
                    kal_uint16 tag_id,
                    kal_uint8 volume,
                    kal_uint8 output_path);
extern kal_int32 media_aud_vrsi_play_TTS(
                    module_type src_mod_id,
                    kal_uint32 session_id,
                    kal_uint16 *text,
                    kal_uint8 volume,
                    kal_uint8 output_path,
                    kal_uint8 lang);
extern kal_int32 media_aud_vrsi_get_tag_num(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num);
extern kal_int32 media_aud_vrsi_get_tag_info(
                    module_type src_mod_id,
                    kal_uint8 *grammar,
                    kal_int32 tag_num,
                    kal_uint16 *id_list,
                    kal_uint16 **name_list,
                    kal_int32 *long_list);
extern kal_int32 media_aud_vrsi_del_tags(
                    module_type src_mod_id,
                    kal_uint8 *grammar,
                    kal_int32 tag_num,
                    kal_uint16 *id_list);
extern kal_int32 media_aud_vrsi_reset_tags(module_type src_mod_id, kal_uint8 *grammar);
extern kal_int32 media_aud_vrsi_sync_db(
                    module_type src_mod_id,
                    kal_uint8 *grammar,
                    kal_int32 tag_num,
                    kal_uint16 *id_list,
                    kal_uint16 **name_list,
                    kal_uint8 *sync_flag);
extern void media_aud_vrsi_abort(module_type src_mod_id, kal_uint32 session_id);
extern void media_aud_vrsi_close(module_type src_mod_id);
extern kal_int32 media_aud_vrsi_get_error_msg(void);
extern kal_int32 media_aud_vrsi_query_tag_id(kal_uint8 *grammar, kal_int32 tag_long, kal_uint16 *tag_id);
extern kal_int32 media_aud_vrsi_query_next_tag_id(kal_uint8 *grammar, kal_uint16 *tag_id);
extern kal_int32 media_aud_vrsi_query_all_tag_ids(
                    kal_uint8 *grammar,
                    kal_int32 tag_long,
                    kal_uint16 buf_size,
                    kal_uint16 *id_buf,
                    kal_uint16 *tag_num,
                    kal_bool *getAll);

#endif /* __MED_VRSI_MOD__ */

#ifdef __MED_SND_MOD__
extern void aud_snd_set_result(kal_int32 result);
extern kal_int32 media_aud_snd_check_byte_stream_format(module_type src_mod_id, kal_uint8 *data, kal_uint32 size);
extern kal_int32 media_aud_snd_check_file_format(module_type src_mod_id, kal_wchar *file_name);
extern kal_int32 media_aud_snd_play_byte_stream(
                    module_type src_mod_id,
                    kal_uint8 *data,
                    kal_int32 size,
                    kal_int16 repeats,
	                kal_uint8 format, 
                    kal_uint8 volume,
                    kal_uint8 output_path,
                    kal_uint16 identifier);
extern kal_int32 media_aud_snd_play_file(
                    module_type src_mod_id,
                    kal_wchar *file_name,
                    kal_int16 repeats,
                    kal_uint8 volu,
                    kal_uint8 output_path,
                    kal_uint16 identifier);
extern kal_int32 media_aud_snd_stop_play(module_type src_mod_id);
extern kal_int32 media_aud_snd_set_volume(module_type src_mod_id, kal_uint8 volume);
#endif /* __MED_SND_MOD__ */

#if defined(__MED_AUD_AUDIO_EFFECT__)
extern void aud_app_set_result(kal_int32 result);
#endif

#if defined(__MED___BES_TS_SUPPORT____)
extern kal_int32 media_stretch_check_stream_format(
                    module_type src_mod_id,
                    kal_uint8 *data,
                    kal_uint32 size,
                    kal_uint16 format);
extern kal_int32 media_stretch_check_file_format(module_type src_mod_id, kal_wchar *file_path);
extern kal_int32 media_stretch_set_speed(module_type src_mod_id, kal_uint16 speed);
extern kal_int32 media_stretch_close(module_type src_mod_id);
#endif /* #if defined(__MED___BES_TS_SUPPORT____) */

#if defined(__MED___BES_LIVE_SUPPORT____)
extern kal_int32 media_aud_reverb_set_mode(kal_uint16 mode);
extern kal_int32 media_aud_reverb_turn_on_effect(void);
extern kal_int32 media_aud_reverb_turn_off_effect(void);
#endif /* #if defined(__MED___BES_LIVE_SUPPORT____) */

#if defined(__MED_AUD_SURROUND__)
extern kal_int32 media_aud_surround_turn_on_effect(kal_uint8 mode);
extern kal_int32 media_aud_surround_turn_off_effect(void);
#endif /* #if defined(__MED_AUD_SURROUND__)*/

#if defined(__MED_AUD_EQUALIZER__)
extern kal_int32 media_aud_eq_set_magnitude(kal_int8 *magnitude);
extern kal_int32 media_aud_eq_turn_on_effect(void);
extern kal_int32 media_aud_eq_turn_off_effect(void);
#endif /* #if defined(__MED_AUD_EQUALIZER__) */

#if defined(__MED_AUD_BASS_ENHANCE__)
extern kal_int32 media_aud_bass_enhance_turn_on_effect(void);
extern kal_int32 media_aud_bass_enhance_turn_off_effect(void);
#endif /*#if defined(__MED_AUD_BASS_ENHANCE__) */

#if defined(__MED_AUD_LOUDNESS__)
extern kal_int32 media_aud_loudness_turn_on_effect(void);
extern kal_int32 media_aud_loudness_turn_off_effect(void);
#endif /*#if defined(__MED_AUD_LOUDNESS__) */

#ifdef __MED_GENERAL_TTS__
extern kal_int32 media_aud_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value);
extern kal_int32 media_aud_tts_play_req(module_type src_mod_id, void *tts_param);
extern kal_int32 media_aud_tts_stop_req(module_type src_mod_id);
extern kal_int32 media_aud_tts_pause_req(module_type src_mod_id);
extern kal_int32 media_aud_tts_resume_req(module_type src_mod_id);
#endif /* #ifdef __MED_GENERAL_TTS__ */

#ifdef __KEY_TONE_DETECTION__
extern kal_int32 media_aud_start_keytone_detect_req(module_type src_mod_id);
extern void media_aud_stop_keytone_detect_req(module_type src_mod_id);
#endif /*__KEY_TONE_DETECTION__*/

#ifdef __MED_BT_MOD__
extern void media_aud_bt_audio_close(kal_uint8 profile);
extern void media_aud_bt_turn_off_audio(kal_uint8 profile);
#endif /*#ifdef __MED_BT_MOD__*/

#ifdef __MED_WEBCAM_MOD__
extern void media_webcam_set_default_jpeg_size(kal_uint8 index, kal_uint32 max_size);
extern kal_int32 media_webcam_set_cam_id(module_type src_mod_id, void *cam_id);
extern kal_int32 media_webcam_start(module_type src_mod_id, void *start);
extern void media_webcam_stop(module_type src_mod_id);
extern kal_int32 media_webcam_pause(module_type src_mod_id, void *pause);
extern kal_int32 media_webcam_resume(module_type src_mod_id, void *resume);
extern kal_int32 media_webcam_capture(module_type src_mod_id);
extern kal_int32 media_webcam_rotate(module_type src_mod_id, void *rotate);
extern kal_int32 media_webcam_pause_connect(module_type src_mod_id);
extern kal_int32 media_webcam_resume_connect(module_type src_mod_id);
extern kal_uint8 media_webcam_get_resolution_num(void);
extern void media_webcam_get_resolution_dimension(kal_uint8 index, kal_uint16 *pwidth, kal_uint16 *pheight);
#endif /* __MED_WEBCAM_MOD__ */

#ifdef __MED_VCALL_MOD__
extern kal_int32 media_vcall_open_video_codec(
                    module_type src_mod_id,
                    media_vcall_view_type_enum recorder_view_type,
                    media_vcall_record_struct *recorder,
                    media_vcall_view_type_enum player_view_type,
                    media_vcall_playback_struct *player);
extern kal_int32 media_vcall_resume_video_codec(
                    module_type src_mod_id,
                    media_vcall_view_type_enum recorder_view_type,
                    media_vcall_record_struct *recorder,
                    media_vcall_view_type_enum player_view_type,
                    media_vcall_playback_struct *player);

extern kal_int32 media_vcall_close_video_codec(module_type src_mod_id);
extern kal_int32 media_vcall_pause_video_codec(module_type src_mod_id);
extern kal_int32 media_vcall_set_memory_param(module_type src_mod_id, kal_bool is_set, kal_uint32 main_wnd_width, kal_uint32 main_wnd_height, kal_uint32 sub_wnd_width, kal_uint32 sub_wnd_height);
extern kal_int32 media_vcall_set_param(module_type src_mod_id, kal_uint32 param_id, kal_int16 value);
extern kal_uint32 media_vcall_get_buffer_content(module_type src_mod_id, void* data);
extern kal_bool media_vall_is_cam_able_to_update_para(void);
#endif /* __MED_VCALL_MOD__ */




/**
  * @defgroup MTV_SAP
  * @{
  */
#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)

/**
  * To initialize the mobile TV engine. A mobile TV engine context will be returned that should be
  * passed to other mobile TV APIs. The request may fail if someone else has already opened the engine
  * exclusively.
  *
  * @param context [out] to receive mobile TV engine context
  * @see MSG_ID_MEDIA_MTV_OPEN_REQ
  */
extern kal_int32 media_mtv_open(module_type src_mod_id, kal_uint32* context, media_mtv_mode_enum mode, kal_uint16 app_id, void *init_param);

/**
  * To configure mobile TV engine about audio, video, and record settings. It should be called after the
  * engine is opened. If there are some existing services started when it is called, these services may
  * get aborted and they need to be restarted again.
  *
  * @param video [in] video settings
  * @param audio [in] audio settings
  * @param record [in] record settings
  * @see MSG_ID_MEDIA_MTV_CONFIG_REQ
  */
extern kal_int32 media_mtv_config(module_type src_mod_id, kal_uint32 context, media_config_video_struct* video, media_config_audio_struct* audio, media_mtv_config_record_struct* record);

/**
  * To find unsaved recording in the recording directory specified by media_mtv_config.
  *
  * @param found [out] KAL_TRUE if there is unsaved recording. KAL_FALSE otherwise.
  * @see MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ
  */
extern kal_int32 media_mtv_find_unsaved_recording(module_type src_mod_id, kal_uint32 context, kal_bool* found);

/**
  * To recover unsaved recording into video file. Note that this function is a non-blocking operation and
  * MSG_ID_MEDIA_COMPLETE_RECOVERING_IND will be sent once the recovering is done.
  *
  * A started recovering can be aborted by calling media_mtv_abort_recovering.
  *
  * @param found [out] TRUE if there is unsaved recording. KAL_FALSE otherwise.
  * @see MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ
  * @see media_mtv_abort_recovering
  */
extern kal_int32 media_mtv_recover_recording(module_type src_mod_id, kal_uint32 context, kal_uint32 seq_no);

/**
  * To abort the recovering of recording. This function has no side effect if the recovering
  * has not been started yet. Any intermidate file generated during recovering will
  * be deleted. Note that you can retry recovering even though it is aborted previously.
  *
  * @see MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ
  */
extern kal_int32 media_mtv_abort_recovering(module_type src_mod_id, kal_uint32 context);

/**
  * To discard unsaved recording immediately.
  *
  * @see MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ
  */
extern kal_int32 media_mtv_discard_unsaved_recording(module_type src_mod_id, kal_uint32 context);

/**
  * To start service searching. Note that this function is a non-blocking operation because it will take a while for the
  * DTV tuner to scanning available services from live signal. The caller should handle MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND and
  * MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND message to know about the result and progress (0 to 100) of service searching.
  *
  * Note that you cannot start a service when the searching operation is in progress.
  *
  * The caller can also specify where the service information comes from. Currently local service database or live signal
  * are supported.
  *
  * The searching can be aborted by calling media_mtv_abort_searching.
  *
  * @param source [in] the source to find services
  * @param band [in] the frequency band to scan if source is live signal
  * @see media_mtv_abort_searching
  * @see MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ
  */
extern kal_int32 media_mtv_search_services(module_type src_mod_id, kal_uint32 context, kal_uint32 source, kal_uint32 band, void *param, kal_uint32 seq_no);

/**
  * To abort service searching.
  *
  * @see MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ
  */
extern kal_int32 media_mtv_abort_searching(module_type src_mod_id, kal_uint32 context);

/**
  * To start a service with specified activities. If the service is started, MEDIA_MTV_SERVICE_STARTED will be
  * sent to notify about the success and MEDIA_MTV_SERVICE_READY will be sent later to indicate that the service
  * is ready for playback or recording.
  *
  * @param activities [in] the activities to perform when the service is started.
  * @see MSG_ID_MEDIA_MTV_START_SERVICE_REQ
  * @see MEDIA_MTV_PLAYER_STARTED
  */
extern kal_int32 media_mtv_start_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 activities, kal_uint32 seq_no);

/**
  * Start time-shift of specified service. Typically time-shift will be started automatically when player is started.
  * However, when it is not appropirate to start player, it must be started explicitly to preserve TV stream.
  *
  * @see MSG_ID_MEDIA_MTV_START_TIMESHIFT_REQ
  */
extern kal_int32 media_mtv_start_timeshift(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no);

/**
  * To start playing a service if it is paused or stopped. If the player is started from stopped state,
  * MEDIA_MTV_PLAYER_STARTED event will be sent to notify the success. By default, the playback will be
  * started in live mode.
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ
  * @see MEDIA_MTV_PLAYER_STARTED
  */
extern kal_int32 media_mtv_player_play(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no);

/**
  * To pause playback of a service. MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED event will be sent to notify the success
  * of pause operation.
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ
  */
extern kal_int32 media_mtv_player_pause(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To stop playing a service. If the player is stopped, MEDIA_MTV_PLAYER_STOPPED event will be
  * sent to notify about the success.
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ
  */
extern kal_int32 media_mtv_player_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);
/**
  * To pause visual update
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_PAUSE_VISUAL_UPDATE_REQ
  */
extern kal_int32 media_mtv_player_pause_visual_update(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To resume visual update
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_RESUME_VISUAL_UPDATE_REQ
  */
extern kal_int32 media_mtv_player_resume_visual_update(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);


/**
  * To seek in time-shifted playback. If the delay is set to zero, the player will enter live mode that will
  * show the live content from broadcasted program. Otherwise, the player will be in delayed mode that the program
  * content comes from time-shift buffer. If the delay is too large, the player will seek to the beginning of
  * buffered content. MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED and MEDIA_MTV_PLAYER_TIMESHIFT_LIVE event are sent to
  * notify the transition between these two modes.
  *
  * @param delay [in] from 0 to max delay allowed
  * @see MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ
  * @see MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED
  * @see MEDIA_MTV_PLAYER_TIMESHIFT_LIVE
  */
extern kal_int32 media_mtv_player_seek(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 delay);

/**
  * To perform trick-mode playback such as 4x fast forward or 2x rewind. The rate is specified in unit of 1/1000.
  * Setting the rate to 1000 means normal 1x playback and 2000 for 2x playback. If the rate is specified in
  * negative value, the playback will be reversed and for example, -500 means reversed 0.5x playback. You can know
  * about current playback rate by media_mtv_player_get_status.
  *
  * Note that the playback rate may get reset to 1x if the playback has reached the beginning or end of buffered
  * content. There are events sent to notify the rate reset.
  *
  * @param rate [in] playback rate
  * @see MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ
  * @see MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT
  * @see MEDIA_MTV_PLAYER_END_OF_CONTENT
  * @see media_mtv_player_get_status
  */
extern kal_int32 media_mtv_player_set_rate(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_int32 rate);

/**
  * To take a video snapshot. The snapshot file will be stored in the same folder as recorded video. A message
  * will be sent to notify a video snapshot has been taken and its event parameter will be a full path of the
  * snapshot file.
  *
  * @see MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ
  * @see MEDIA_MTV_PLAYER_SNAPSHOT_TAKEN
  */
extern kal_int32 media_mtv_player_snapshot(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_wchar* file_path, media_mtv_buf_content_struct *buf_content);

/**
  * To retrieve player status information. This function can be called even if the player is not started.
  *
  * @param status [out] the address to receive player status
  * @see MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ
  */
extern kal_int32 media_mtv_player_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_player_status_struct* status);

/**
  * To get info about specified service.
  *
  * @param info [in] the info struct to fill in
  * @see MSG_ID_MEDIA_MTV_GET_SERVICE_INFO_REQ
  */
extern kal_int32 media_mtv_service_get_info(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_service_info_struct* info);

/**
  * To start recording specified service. The folder to store recorded file is specified by media_mtv_config.
  * The file name of recorded file will be chosen automatically by service name and program title. The client
  * can call media_mtv_recorder_get_status to know about the progress of service recording.
  *
  * MEDIA_MTV_RECORDER_STARTED event will be sent to notify about the success of starting recorder.
  *
  * @see media_mtv_config
  * @see media_mtv_recorder_get_status
  * @see MSG_ID_MEDIA_MTV_RECORDER_START_REQ
  */
extern kal_int32 media_mtv_recorder_start(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, const kal_wchar *service_name, kal_uint32 seq_no);

/**
  * To stop recording immediately. Note that the client should call media_mtv_recorder_save or
  * media_mtv_recorder_discard_recording to save or discard the recording. Otherwise, the unsaved
  * content will not be erased until the service is stopped or the recorder is started again.
  *
  * @see MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ
  * @see MEDIA_MTV_RECORDER_STOPPED
  */
extern kal_int32 media_mtv_recorder_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To pause recording immediately. Note that the client should call media_mtv_recorder_resume/stop after paused.
  *
  * @see MSG_ID_MEDIA_MTV_RECORDER_PAUSE_REQ
  */
extern kal_int32 media_mtv_recorder_pause(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To resume recording immediately.
  *
  * @see MSG_ID_MEDIA_MTV_RECORDER_RESUME_REQ
  */
extern kal_int32 media_mtv_recorder_resume(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To save recorded program into video file. Note that this function is a non-blocking operation because
  * it will take a while for the recorder to perform file conversion from time-shift buffer to video file.
  * Once the recorder finishes file saving, MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED or
  * MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED will be sent to notify the completion.
  *
  * @see MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED
  * @see MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED
  * @see MEDIA_MTV_RECORDER_SAVING
  */
extern kal_int32 media_mtv_recorder_save(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_wchar *file_path, kal_uint32 seq_no);

/**
  * To abort the saving of specified service. This function has no side effect if the saving has not
  * been started yet. Note that you can retry saving even though it is aborted previously.
  *
  * @see MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ
  */
extern kal_int32 media_mtv_recorder_abort_saving(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To discard unsaved recording immediately.
  *
  * @see MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ
  * @see MEDIA_MTV_RECORDER_SAVING
  */
extern kal_int32 media_mtv_recorder_discard_recording(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 seq_no) ;

/**
  * To retrieve recorder status information. This function can be called even if the recorder is not started.
  *
  * @param status [out] the address to receive recorder status
  * @see MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ
  */
extern kal_int32 media_mtv_recorder_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_recorder_status_struct* status);

/**
  * To retrieve service status information.
  *
  * @param status [out] the address to receive service status
  * @see MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ
  */
extern kal_int32 media_mtv_service_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_service_status_struct* status);

/**
  * To stop a started service. If there is any player and recorder opened for this service, the caller need to
  * wait for the completion of closing player and recorder which may be time-consuming. Therefore, the caller
  * can choose to stop the player and recorder manually to prevent blocked waiting. MEDIA_MTV_SERVICE_STOPPED will
  * sent to indicate the service has been stopped completely.
  *
  * @see MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ
  * @see MEDIA_MTV_SERVICE_STOPPED
  */
extern kal_int32 media_mtv_stop_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id);

/**
  * To set service parameter. For some parameters, they can be set before the service is started.
  *
  * @param param [in] parameter ID
  * @param value [in] parameter value
  * @see MSG_ID_MEDIA_MTV_SET_PARAM_REQ
  */
extern kal_int32 media_mtv_set_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32 value);

/**
  * To get service parameter. For some parameters, they can only be queried after the service is started.
  *
  * @param param [in] parameter ID
  * @param value [out] parameter value
  * @see MSG_ID_MEDIA_MTV_GET_PARAM_REQ
  */
extern kal_int32 media_mtv_get_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32* value);

/**
  * To close the mobile TV engine. All started services (and their corresponding player and recorder) will be aborted.
  *
  * Note that closing MTV is an asynchronous operation and the completion will be notify by MEDIA_MTV_SYSTEM_CLOSED event.
  *
  * @see MSG_ID_MEDIA_MTV_CLOSE_REQ
  */
extern kal_int32 media_mtv_close(module_type src_mod_id, kal_uint32 context);

/**
  * To start ESG download.
  *
  * @see MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_DOWNLOAD_REQ
  */
extern kal_int32 media_mtv_media_mtv_esg_download(module_type src_mod_id, kal_uint32 context);

/**
  * To abort ESG download.
  *
  * @see MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_ABORT_DOWNLOADING_REQ
  */
extern kal_int32 media_mtv_media_mtv_esg_abort_downloading(module_type src_mod_id, kal_uint32 context);

/**
  * To send open to ESG query engine.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_OPEN_REQ
  */
extern kal_int32 media_mtv_esg_open(module_type src_mod_id, kal_uint32* context, media_mtv_esg_source_enum source, kal_uint16 app_id);

/**
  * To send close to ESG query engine.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_CLOSE_REQ
  */
extern kal_int32 media_mtv_esg_close(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source);

/**
  * To send query to ESG query engine.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_QUERY_REQ
  */
extern kal_int32 media_mtv_esg_query(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source, kal_int32 type, media_mtv_esg_query_struct *query);

/**
  * To get query results from ESG query engine.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_QUERY_REQ
  */
extern kal_int32 media_mtv_esg_get_results(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source, kal_int32 type, void **buf_p);

/**
  * To finish query of ESG query engine.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_QUERY_REQ
  */
extern kal_int32 media_mtv_esg_query_finish(module_type src_mod_id, kal_uint32 context, media_mtv_esg_source_enum source);

/**
  * To add current service into favorite list.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_QUERY_REQ
  */
extern kal_int32 media_mtv_esg_add_favorite(module_type src_mod_id, kal_uint32 context, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

/**
  * To remove current service from favorite list.
  *
  * @see MSG_ID_MEDIA_MTV_ESG_QUERY_REQ
  */
extern kal_int32 media_mtv_esg_del_favorite(module_type src_mod_id, kal_uint32 context, media_mtv_favorite_type_enum type, kal_uint32 id, kal_char *rid);

/**
  * To get card info
  *
  * @see MSG_ID_MEDIA_MTV_CAS_GET_CARD_INFO_REQ
  */
kal_int32 media_mtv_get_cas_card_info(module_type src_mod_id, kal_uint32 context, media_mtv_cas_card_info_struct* card_info);

#endif /* __MED_MTV_MOD__ || __MED_ATV_MOD__ */
/** @} */


extern kal_int32 media_get_ext_buffer_ext(module_type src_mod_id, void **buffer_p, kal_uint32 buffer_size, char* file_p,long line_p);
extern kal_int32 media_free_ext_buffer_ext(module_type src_mod_id, void **buffer_p, char* file_p,long line_p);
extern kal_int32 media_get_int_buffer_ext(module_type src_mod_id, void **buffer_p, kal_uint32 buffer_size, char* file_p,long line_p);
extern kal_int32 media_free_int_buffer_ext(module_type src_mod_id, void **buffer_p, char* file_p,long line_p);
extern kal_int32 media_get_ext_buffer_with_property(module_type src_mod_id, kal_uint8 property, void **buffer_p, kal_uint32 buffer_size, char* file_p,long line_p);

/* Interface of media memory */
#define media_get_int_buffer(src_mod_id, buffer_p, buffer_size)     media_get_int_buffer_ext(src_mod_id,buffer_p,buffer_size,__FILE__,__LINE__)
#define media_free_int_buffer(src_mod_id, buffer_p)                 media_free_int_buffer_ext(src_mod_id, buffer_p, __FILE__, __LINE__)

#define media_get_ext_buffer(src_mod_id, buffer_p, buffer_size)     media_get_ext_buffer_ext(src_mod_id,buffer_p, buffer_size,__FILE__,__LINE__)
#define media_free_ext_buffer(src_mod_id, buffer_p)                 media_free_ext_buffer_ext(src_mod_id, buffer_p, __FILE__, __LINE__)
#define media_get_ext_buffer_cacheable(src_mod_id, buffer_p, buffer_size)   media_get_ext_buffer_with_property(src_mod_id,MED_EXT_MEMORY_TYPE_CACHEABLE,buffer_p, buffer_size,__FILE__,__LINE__)
#define media_get_ext_buffer_framebuffer(src_mod_id, buffer_p, buffer_size) media_get_ext_buffer_with_property(src_mod_id,MED_EXT_MEMORY_TYPE_FRAMEBUFFER,buffer_p, buffer_size,__FILE__,__LINE__)
#define media_get_ext_buffer_topmost_noncacheable(src_mod_id, buffer_p, buffer_size)     media_get_ext_buffer_with_property(src_mod_id,MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE,buffer_p, buffer_size,__FILE__,__LINE__)
#define media_get_ext_buffer_topmost_cacheable(src_mod_id, buffer_p, buffer_size)     media_get_ext_buffer_with_property(src_mod_id,MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE,buffer_p, buffer_size,__FILE__,__LINE__)

#ifdef __MED_IN_ASM__
#define media_get_asm_buffer(id, src_mod_id, buffer_p, buffer_size)         applib_asm_alloc_nc_r(id, buffer_size)
#define media_get_asm_buffer_cacheable(id, src_mod_id, buffer_p, buffer_size)       applib_asm_alloc_r(id, buffer_size)
#define media_get_asm_buffer_framebuffer(id, src_mod_id, buffer_p, buffer_size)     applib_asm_alloc_nc_r(id, buffer_size)
#define media_get_asm_buffer_topmost_noncacheable(id, src_mod_id, buffer_p, buffer_size)    applib_asm_alloc_nc_r(id, buffer_size)
#define media_get_asm_buffer_topmost_cacheable(id, src_mod_id, buffer_p, buffer_size)       applib_asm_alloc_r(id, buffer_size)
#define media_free_asm_buffer(id, src_mod_id, buffer_p)                     do{applib_asm_free_r(id, *(buffer_p)); *(buffer_p)=NULL;}while(0);
#else
#define media_get_asm_buffer(id, src_mod_id, buffer_p, buffer_size)         media_get_ext_buffer(src_mod_id, buffer_p, buffer_size)
#define media_get_asm_buffer_cacheable(id, src_mod_id, buffer_p, buffer_size)   media_get_ext_buffer_cacheable(src_mod_id, buffer_p, buffer_size)
#define media_get_asm_buffer_framebuffer(id, src_mod_id, buffer_p, buffer_size) media_get_ext_buffer_framebuffer(src_mod_id, buffer_p, buffer_size)
#define media_get_asm_buffer_topmost_noncacheable(id, src_mod_id, buffer_p, buffer_size)  media_get_ext_buffer_topmost_noncacheable(src_mod_id, buffer_p, buffer_size)
#define media_get_asm_buffer_topmost_cacheable(id, src_mod_id, buffer_p, buffer_size)     media_get_ext_buffer_topmost_cacheable(src_mod_id, buffer_p, buffer_size)
#define media_free_asm_buffer(id, src_mod_id, buffer_p)                     media_free_ext_buffer(src_mod_id, buffer_p)
#endif

#if defined(__AUD_REC_INTENSITY__)
extern void media_get_record_intensity(kal_uint32 channel,kal_uint32* strength);
extern void media_get_record_intensity_limit(kal_uint32* max_value,kal_uint32* min_value);
#endif /*__AUD_REC_INTENSITY__*/

#endif /* _MED_API_H */

#endif /* MED_NOT_PRESENT */

