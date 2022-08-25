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
 * med_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes function prototypes of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MED_MAIN_H
#define _MED_MAIN_H

#include "l1audio.h"
#include "mpl_common.h" // mpl common type definition
#include "mpl_player.h" // mpl player interface definition

/* this shall be sync with aud_defs.h, backward compatible */
typedef enum
{
    MED_RES_OK = 0,                 /* 0 */
    MED_RES_FAIL,                   /* 1 */
    MED_RES_BUSY,                   /* 2 */
    MED_RES_DISC_FULL,              /* 3 */
    MED_RES_OPEN_FILE_FAIL,         /* 4 */
    MED_RES_END_OF_FILE,            /* 5 */
    MED_RES_TERMINATED,             /* 6 */
    MED_RES_BAD_FORMAT,             /* 7 */
    MED_RES_INVALID_FORMAT,         /* 8 */
    MED_RES_ERROR,                  /* 9 */
    MED_RES_NO_DISC,                /* 10 */
    MED_RES_NOT_ENOUGH_SPACE,       /* 11 */
    MED_RES_INVALID_HANDLE,         /* 12 */
    MED_RES_NO_HANDLE,              /* 13 */
    MED_RES_RESUME,                 /* 14 */
    MED_RES_BLOCKED,                /* 15 */
    MED_RES_MEM_INSUFFICIENT,       /* 16 */
    MED_RES_BUFFER_INSUFFICIENT,    /* 17 */
    MED_RES_FILE_EXIST,             /* 18 */
    MED_RES_WRITE_PROTECTION,       /* 19 */
    MED_RES_PARAM_ERROR,            /* 20 */
    /* MP4,AAC */
    MED_RES_UNSUPPORTED_CHANNEL,    /* 21 */
    MED_RES_UNSUPPORTED_FREQ,
    MED_RES_UNSUPPORTED_TYPE,
    MED_RES_UNSUPPORTED_OPERATION,
    MED_RES_PARSER_ERROR,
    MED_RES_VIDEO_ERROR,
    MED_RES_AUDIO_ERROR,
    MED_RES_FSAL_ERROR,
    MED_RES_MP4_PRODUCER_ERROR,
    MED_RES_MP4_SAMPLEDATA_ERROR,
    MED_RES_MP4_NO_VIDEO_TRACK,
    MED_RES_MP4_NO_AUDIO_TRACK,
    /* VR */
    MED_RES_ID_MISMATCH,            /* 33 */
    MED_RES_ID_EXIST,
    MED_RES_TRAINING_CONTINUE,
    MED_RES_NO_SOUND,
    MED_RES_TOO_SIMILAR,
    MED_RES_TOO_DIFFERENT,
    MED_RES_NO_MATCH,
    MED_RES_SPEAK_TOO_LONG,
    MED_RES_SPEAK_TOO_SHORT,
    /* MP4,AAC */
    MED_RES_AUDIO_END,              /* 42 */
    MED_RES_VIDEO_END,
    MED_RES_VIDEO_IMAGE_TOO_LARGE,
    MED_RES_VIDEO_FILE_TOO_LARGE,
    MED_RES_VIDEO_FRAME_RATE_TOO_HIGH,
    MED_RES_VIDEO_SEEK_PARTIAL_DONE,
    /* VRSI */
    MED_RES_VRSI_OK,                /* 48 */
    MED_RES_VRSI_ERR_UNINITIALIZED,
    MED_RES_VRSI_ERR_BUSY,
    MED_RES_VRSI_ERR_MEM_INSUFFICIENT,
    MED_RES_VRSI_ERR_DATA_ERROR,
    MED_RES_VRSI_ERR_LIBRARY_CORRUPT,
    MED_RES_VRSI_ERR_BAD_GRAMMAR,
    MED_RES_VRSI_ERR_LANG_NOT_SUPPORT,
    MED_RES_VRSI_ERR_NO_MATCH_TAG,
    MED_RES_VRSI_ERR_TTS_TOO_LONG,
    MED_RES_VRSI_ERR_SESSION,
    MED_RES_VRSI_ERR_NO_SOUND,
    MED_RES_VRSI_ERR_CMD_TRN_FAIL,
    MED_RES_VRSI_ERR_CMD_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_ADP_FAIL,
    MED_RES_VRSI_ERR_UNKNOWN,       /* 64 */
    /* FM Record */
    MED_RES_STOP_FM_RECORD,         /* 65 */
    /* Audio Post Process */
    MED_RES_UNSUPPORTED_SPEED,      /* 66 */
    /* A2DP */
    MED_RES_A2DP_CLOSE,
    MED_RES_A2DP_DISCOVER_SEP_FAIL,
    MED_RES_A2DP_GET_SEP_CAP_FAIL,
    MED_RES_A2DP_NO_MATCH_CAP,
    MED_RES_A2DP_CONFIG_STREAM_FAIL,
    MED_RES_A2DP_RECONFIG_STREAM_FAIL,
    MED_RES_A2DP_OPEN_STREAM_FAIL,
    MED_RES_A2DP_START_STREAM_FAIL,
    MED_RES_A2DP_PAUSE_STREAM_FAIL,  /* 75 */
    /* HFP */
    MED_RES_HFP_CLOSE,
    /* Image */
    MED_RES_IMG_DECODE_TIME_OUT,
    MED_RES_ROOT_DIR_FULL,

    /* Barcode Reader */
    MED_RES_BR_IMAGE_ERROR,         /* 79 */
    MED_RES_BR_MODULE_ERROR,
    MED_RES_BR_OUT_OF_MEMORY,
    MED_RES_BR_OVER_VERSION,
    MED_RES_BR_DECODE_TIMEOUT,
    MED_RES_BR_ERROR_BARCODE_TYPE,

    /* Video - pdl */
    MED_RES_PDL_AUDIO_UNDERFLOW,    /* 85 */
    MED_RES_PDL_VIDEO_UNDERFLOW,

    /* Streaming */
    MED_RES_STREAM_BEARER_DISCONNECTED,     /* 87 */
    MED_RES_STREAM_INVALID_SDP,
    MED_RES_STREAM_RTSP_SET_CHANNEL_FAIL,
    MED_RES_STREAM_RTSP_REQUEST_FAIL,       /* 90 */
    MED_RES_STREAM_RTSP_REQUEST_FORBIDDEN,
    MED_RES_STREAM_PLAY_FINISH,
    MED_RES_STREAM_BUFFER_UNDERFLOW,
    MED_RES_STREAM_BUFFER_OVERFLOW,
    MED_RES_STREAM_INVALID_RESOLUTION,
    MED_RES_STREAM_INVALID_PARAMETER,
    MED_RES_STREAM_STOP_TIMEOUT,
    MED_RES_STREAM_UNSUPPORTED_CODEC,
    MED_RES_STREAM_INVALID_MEDIA,

    MED_RES_VDOEDT_ENCODE_FAIL,     /* 100 */
    MED_RES_DECODER_NOT_SUPPORT,
    MED_RES_REACH_STOP_TIME,
    MED_RES_VRSI_ERR_EVALUATE_LIMIT,  /* 103 */
    MED_RES_IMGAE_ENCODED_SIZE_LARGER_THAN_EXPECTATION, /* 104 */
    MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE,
    MED_RES_VIDEO_ALREADY_STOPPED,
    MED_RES_STREAM_UNSUPPORTED_BANDWIDTH,

    /* bitstream */
    MED_RES_BITSTREAM_FAILED,
    MED_RES_BITSTREAM_UNSUPPORTED_CODEC,
    MED_RES_BITSTREAM_INVALID_RESOLUTION,
    MED_RES_BITSTREAM_MEMORY_INSUFFICIENT,
    MED_RES_BITSTREAM_BUFFER_OVERFLOW,
    MED_RES_BITSTREAM_BUFFER_UNDERFLOW,
    MED_RES_BITSTREAM_INVALID_FORMAT,
    MED_RES_BITSTREAM_RECOVER,                /* 115 */

    /* audio extension */
    MED_RES_AUD_DEMO_END,                     /* 116 */
    MED_RES_AUD_DUR_UPDATED,                  /* 117 */

    MED_RES_BITSTREAM_BUFFER_NOT_AVAILABLE,   /* 118 */

    /* disk io error */
    MED_RES_DISK_IO_ERROR,                    /* 119 */

    MED_RES_BITSTREAM_INVALID_PARAMETER,
    MED_RES_BITSTREAM_NOT_SUPPORTED,          /* 121 */

    MED_RES_OK_ASYNC,
    MED_RES_PLAY_FINISH,
    MED_RES_STOP_TIME_REACHED,
    MED_RES_PLAY_STOPPED,
    MED_RES_PDL_BUFFER_INSUFFICIENT,
    MED_RES_MJPG_SKIP_FRAME,                  /* 127 */
    MED_RES_NO_REQUIRED_TRACK,
    
    MED_RES_STREAM_REC_DUR_TOO_SHORT,         /* 129 */
    MED_RES_VIDEO_NO_FRAME_ENCODED,    
    MED_RES_OVER_LIMIT,  /* 131 */
    MED_RES_UPGRADE_NONE,
    MED_RES_UPGRADE_NEED,
    MED_RES_UPGRADE_MANDATORY,
    MED_RES_VIDEO_TRACK_ERROR, /* 135 */
    MED_RES_AUDIO_TRACK_ERROR,
    MED_NO_OF_RES
}
med_result_enum;

typedef enum
{
    MED_VR_ISD_MODE = 0,
    MED_VR_CSI_MODE,
    MED_VR_PSI_MODE,
    MED_NO_OF_VR_MODE
}
med_vr_mode_enum;

typedef enum
{
    MED_VR_NO_CARE_LANG = 0,
    MED_VR_CHINESE_ENGLISH_LANG,
    MED_VR_CHINESE_LANG,
    MED_VR_ENGLISH_LANG,
    MED_NO_OF_VR_LANG
}
med_vr_lang_enum;

typedef enum
{
    MED_VRSI_TAIWAN_LANG,
    MED_VRSI_CHINA_LANG,
    MED_VRSI_AMERICAN_LANG,
    MED_VRSI_BRITISH_LANG,
    MED_VRSI_INVALID_LANG = 0xff
}
med_vrsi_lang_enum;

typedef enum
{
    MED_VRSI_RECOG_MPR,
    MED_VRSI_RECOG_OK,
    MED_VRSI_DIGIT_RECOG_MPR,
    MED_VRSI_DIGIT_RECOG_OK,
    MED_VRSI_DIGIT_ADAPT_MPR,
    MED_VRSI_DIGIT_ADAPT_OK,
    MED_VRSI_TRAIN_TAG_1ST_MPR,
    MED_VRSI_TRAIN_TAG_2ND_MPR,
    MED_VRSI_TRAIN_TAG_OK,
    MED_VRSI_TTS_OK,
    MED_VRSI_PLAY_TAG_OK,
    MED_VRSI_ERROR
} med_vrsi_event_enum;

typedef enum
{
    MED_VRSI_1ST_TRN_PROMPT,
    MED_VRSI_2ND_TRN_PROMPT,
    MED_VRSI_1ST_DGT_ADP_PROMPT,
    MED_VRSI_2ND_DGT_ADP_PROMPT,
    MED_VRSI_CMD_RCG_PROMPT,
    MED_VRSI_DGT_RCG_PROMPT
} med_vrsi_prompt_mode_enum;

typedef enum
{
    MED_STREAM_ABORT_TYPE_DISCONNECT,
    MED_STREAM_ABORT_TYPE_STOP,

    MED_STREAM_ABORT_COUNT
} med_stream_abort_type_enum;


#ifdef __FM_RADIO_RDS_SUPPORT__
typedef enum
{
    RDS_STATE_DISABLE,
    RDS_STATE_ENABLE,
    RDS_STATE_SWITCHED,
    RDS_STATE_INVALID
}MED_RDS_STATE_ENUM;
#endif /* __FM_RADIO_RDS_SUPPORT__ */ 

typedef enum
{
    FMR_SEEK_WAIT = -1,
    FMR_SEEK_START = 0,
    FMR_SEEK_STOP
} MED_FMR_SEEK_STATE;

#if defined(__DIRECT_SENSOR_SUPPORT__)
void med_get_med_dcm_address(kal_uint32* address);
#endif

//#ifdef __MED_AT_DEBUG__
typedef enum
{
	MED_AT_OK,
	MED_AT_POWERUP_ERROR,
	MED_AT_POWERDOWN_ERROR,
	MED_AT_PREVIEW_ERROR,
	MED_AT_RECORD_ERROR,
	MED_AT_RESUME_ERROR,
	MED_AT_PAUSE_ERROR,
	MED_AT_STOP_ERROR

}med_at_return_enum;
//#endif

#endif /* _MED_MAIN_H */
