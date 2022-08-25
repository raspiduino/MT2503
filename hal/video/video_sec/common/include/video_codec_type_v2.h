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
 *   video_codec_type_v2.h
 *
 * Project:
 * --------
 *	MTK
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/
#ifndef VIDEO_CODEC_TYPE_V2_H
#define VIDEO_CODEC_TYPE_V2_H

/****************************************************************************
 ****************************************************************************
 *
 *  Common enum
 *
 ****************************************************************************
 ****************************************************************************/
typedef enum
{
    CODEC_NONE          = (0x0),
    CODEC_H264          = (0x1),
    CODEC_MPEG4         = (0x1<<1),
    CODEC_H263          = (0x1<<2),
    CODEC_RV9_10        = (0x1<<3),
    CODEC_MJPEG         = (0x1<<4),
    CODEC_YUV           = (0x1<<5),
    CODEC_MJPG_BYPASS   = (0x1<<6),
    CODEC_VP8           = (0x1<<7)
} VIDEO_CODEC_T;

typedef enum
{
    VIDEO_CODEC_FRAMETYPE_I,
    VIDEO_CODEC_FRAMETYPE_P,
    VIDEO_CODEC_FRAMETYPE_B,    
    VIDEO_CODEC_HEADER,
    VIDEO_CODEC_FRM_DROPPED,
    VIDEO_CODEC_UNKNOWN_TYPE
} VIDEO_CODEC_FRAME_TYPE_T;


/****************************************************************************
 ****************************************************************************
 *
 *  decoder component enum
 *
 ****************************************************************************
 ****************************************************************************/

/****************************************************************************
*   VIDEO_DECODER_CODEC_ERROR_T
*
*   Error code of adaptation layers
*
****************************************************************************/ 
typedef enum
{
    VIDEO_DECODER_CODEC_ERROR_NONE,
    VIDEO_DECODER_CODEC_ERROR,
    VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT,
    VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK,
    VIDEO_DECODER_CODEC_BSQUE_FULL,
    VIDEO_DECODER_CODEC_BSQUE_OVERFLOW,
    VIDEO_DECODER_CODEC_EXCEED_MAX_RETRY
} VIDEO_DECODER_CODEC_ERROR_T; 

/****************************************************************************
*   VIDEO_DECODER_PARAM_TYPE_T
*
*   Parameters for adaptation layers
*
****************************************************************************/
typedef enum
{
    VIDEO_DECODER_PARAM_EOF,
    VIDEO_DECODER_PARAM_QUERY_RESOLUTION_AHEAD,
    VIDEO_DECODER_PARAM_QUERY_RESOLUTION,
    VIDEO_DECODER_PARAM_QUERY_PREDICATION_TIME,
    VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT,
    VIDEO_DECODER_PARAM_CAPABILITY,
    VIDEO_DECODER_PARAM_NOT_BUFFERING,
    VIDEO_DECODER_PARAM_BUFFERING,
    VIDEO_DECODER_PARAM_BITRATE,
    VIDEO_DECODER_PARAM_FRAMERATE,
    VIDEO_DECODER_PARAM_FLUSH_BUFFER,
    VIDEO_DECODER_PARAM_HEADER_RETRY,
    VIDEO_DECODER_PARAM_DECRYPTION_MODE,
    VIDEO_DECODER_PARAM_SET_DECODE_MODE,
    VIDEO_DECODER_PARAM_GET_DECODE_MODE,
    VIDEO_DECODER_PARAM_SET_CTRL_VOS,
    VIDEO_DECODER_PARAM_GET_SBSFLAG
} VIDEO_DECODER_PARAM_TYPE_T;

/*********************************************
*   VIDEO_DECODER_ACTION_T
*
*   Indicate the action decoder would like to do
*
*   Decoder would decide which action it would like to do according to priority and efficiency
*   in the beginning of _VideoDecoderDataHdlr()
*
*   ACTION_COMMAND deal with command from IL client
*   ACTION_INPUT_BUFFER deal with bitstream buffer
*   ACTION_OUTPUT_BUFFER deal with frame buffer
*   ACTION_INPUT_RESENT_FULL deal with resending bitstream buffer
*   ACTION_OUTPUT_RESENT_FULL deal with resending frame buffer
*
**********************************************/
typedef enum
{
    DECODER_ACTION_NONE = 0,
    DECODER_ACTION_COMMAND,
    DECODER_ACTION_INPUT_BUFFER,
    DECODER_ACTION_OUTPUT_BUFFER,
    DECODER_ACTION_INPUT_RESENT_FULL,
    DECODER_ACTION_OUTPUT_RESENT_FULL
}VIDEO_DECODER_ACTION_T;

/*********************************************
*   VIDEO_DECODER_MESSAGE_T
*
*   Used for distinguishing the message from different source
*
**********************************************/
typedef enum
{
    DECODER_MSG_COMMAND = 0,
    DECODER_MSG_FILLBUFFER,
    DECODER_MSG_EMPTYBUFFER,
    DECODER_MSG_WAKEUP
}VIDEO_DECODER_MESSAGE_T;

/*********************************************
*   VIDEO_DECODER_BUFFER_PORT_T
*
*   Used for distinguishing two different ports
*   BUFFER_PORT_INPUT is the port of file reader/IL client/...
*   BUFFER_PORT_OUTPUT is the port of scheduler/IL client/...
*
**********************************************/
typedef enum
{
    DECODER_BUFFER_PORT_INPUT = 0,
    DECODER_BUFFER_PORT_OUTPUT
}VIDEO_DECODER_BUFFER_PORT_T;

/*********************************************
*   VIDEO_DECODER_FLUSH_STATE_T
*
*   Used for distinguishing flush state
*
**********************************************/
typedef enum
{
	DECODER_FLUSH_STATE_NONE = 0,
	DECDOER_FLUSH_STATE_FLUSH,
	DECDOER_FLUSH_STATE_DONE
}VIDEO_DECODER_FLUSH_STATE_T;

typedef enum
{
    DECODER_MDT_INPUT_BITSTREAM = 0,
    DECODER_MDT_SEND_FRAME,
    DECODER_MDT_RETURN_FRAME,
    DECODER_MDT_MAX
}VIDEO_DECODER_MEMORY_DUMP_TYPE_T;


typedef enum
{
    DECODER_DBM_NONE = 0,
    DECODER_DBM_INPUT_BITSTREAM = 0x1,
    DECODER_DBM_SEND_FRAME = 0x2,
    DECODER_DBM_RETURN_FRAME = 0x4,
    DECODER_DBM_INPUT_BITSTREAM_CS = 0x10,
    DECODER_DBM_SEND_FRAME_CS = 0x20,
    DECODER_DBM_RETURN_FRAME_CS = 0x40
}VIDEO_DECODER_DEBUG_MODE_T;


/****************************************************************************
 ****************************************************************************
 *
 *  encoder component enum
 *
 ****************************************************************************
 ****************************************************************************/

/****************************************************************************
*   VIDEO_ENCODER_ACTION_T
*
*   Different Actions in the main loop
*
****************************************************************************/
typedef enum
{
    ACTION_NONE = 0,
    ACTION_COMMAND,
    ACTION_INPUT_BUFFER,
    ACTION_OUTPUT_BUFFER,
    ACTION_RETURN_YUV,
    ACTION_RESEND_BITSTREAM,
    ACTION_ENCODE_OLD_FRAME
} VIDEO_ENCODER_ACTION_T;


/****************************************************************************
*   VIDEO_ENCODER_BUFFER_PORT_T
*
*   Used for distinguishing two different ports
*   BUFFER_PORT_INPUT is the port of IDP/IL client/...
*   BUFFER_PORT_OUTPUT is the port of file writer/IL client/...
*
****************************************************************************/
typedef enum
{
    BUFFER_PORT_INPUT = 0,
    BUFFER_PORT_OUTPUT
} VIDEO_ENCODER_BUFFER_PORT_T;


/****************************************************************************
*   VIDEO_ENCODER_INTERNAL_STATE_T
*
*   Internal states for stop state transition
*
****************************************************************************/
typedef enum
{
    VIDEO_ENCODER_INT_STATE_INIT,
    VIDEO_ENCODER_INT_STATE_STOPPING,
    VIDEO_ENCODER_INT_STATE_STOPPED
} VIDEO_ENCODER_INTERNAL_STATE_T;


/****************************************************************************
*   VIDEO_ENCODER_CHASSIS_STATUS_T
*
*   State of chassis
*
****************************************************************************/
typedef enum
{
    VIDEO_ENCODER_CHASSIS_FREE      = 0,
    VIDEO_ENCODER_CHASSIS_IN_USE    = 1
} VIDEO_ENCODER_CHASSIS_STATUS_T;


/****************************************************************************
*   VIDEO_ENCODER_PARAM_TYPE_T
*
*   Parameters for adaptation layers
*
****************************************************************************/
typedef enum
{
    //Get parameters
    VENC_PARAM_MEMORY_REQUIREMENT,      //Query ext/int memory requirement for adaptation
    VENC_PARAM_BITSTREAM_IN_CACHE,      //Query the prefer memory type of bitstream buffer, return true means cacheable buffer is preferred
    VENC_PARAM_FRM_BUFFER_ALIGNMENT,    //Query the alignment needed on frame buffer for codec
    VENC_PARAM_HOLD_RES_TILL_RELEASE_FRM,
    VENC_PARAM_IS_BLOCKBASED_YUV,
    VENC_PARAM_GET_CODEC_CONFIG,

    //Set parameters
    VENC_PARAM_WIDTH,
    VENC_PARAM_HEIGHT,
    VENC_PARAM_BITRATE,
    VENC_PARAM_FRAME_RATE,
    VENC_PARAM_GEN_HEADER_FRM_RATE,
    VENC_PARAM_SHORT_HEADER,
    VENC_PARAM_SYNC_INTERVAL,
    VENC_PARAM_MAX_PKG_SIZE,
    VENC_PARAM_FORCE_ENCODE_I,
    VENC_PARAM_QUALITY,
    VENC_PARAM_SCENARIO,
    VENC_PARAM_CODEC_TYPE,
    VENC_PARAM_VT_RESTART,
    VENC_PARAM_ROTATE,
    VENC_PARAM_SET_CALLBACK,
    VENC_PARAM_FLUSH_CODEC
} VIDEO_ENCODER_PARAM_TYPE_T;



/****************************************************************************
*   VIDEO_ENCODER_CODEC_ERROR_T
*
*   Error code of adaptation layers
*
****************************************************************************/
typedef enum{
    VIDEO_ENCODER_CODEC_ERROR_NONE,
    VIDEO_ENCODER_CODEC_ERROR,
    VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH,
    VIDEO_ENCODER_CODEC_NEED_TRIGGER,
    VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT,
    VIDEO_ENCODER_CODEC_REJECT_INPUT
} VIDEO_ENCODER_CODEC_ERROR_T;

/****************************************************************************
*   VIDEO_CODEC_ROTATE_ANGLE_T
*
*   Rotate angle for codec
*
****************************************************************************/
typedef enum{
    VIDEO_CODEC_ROTATE_0,
    VIDEO_CODEC_ROTATE_90,
    VIDEO_CODEC_ROTATE_180,
    VIDEO_CODEC_ROTATE_270
} VIDEO_CODEC_ROTATE_ANGLE_T;

/****************************************************************************
*   VENC_CLEAN_MODE_T
*
*   The moment call schedule controller's clean item
*
****************************************************************************/
typedef enum{
    VENC_CLEAN_AFTER_ENCODE = 0,
    VENC_CLEAN_AT_ENCODE_DONE
} VENC_CLEAN_MODE_T;

/****************************************************************************
*   VENC_CLEAN_MODE_T
*
*   The moment call schedule controller's clean item
*
****************************************************************************/
typedef enum{
    AFTER_ENCODE = 0,
    AT_ENCODE_DONE
} VENC_CLEAN_TIME_T;

/****************************************************************************
*   VENC_BIT_BUFFER_STATE_T
*
*   State of bitstream buffer
*
****************************************************************************/
typedef enum
{
    VENC_BITBUFF_BITSTREAM,
    VENC_BITBUFF_HEADER        
}VENC_BIT_BUFFER_STATE_T;

/****************************************************************************
*   VENC_CODEC_STATE_T
*
*   Define the state machine of codecs
*
****************************************************************************/
typedef enum
{
    VENC_CODEC_STATE_OPEN = 0,
    VENC_CODEC_STATE_INIT,
    VENC_CODEC_STATE_DEINIT,
    VENC_CODEC_STATE_CLOSE
}VENC_CODEC_STATE_T;

/****************************************************************************
*   MJPEG_FUNC_T
*
*   Define function names of mpjeg encoder
*
****************************************************************************/

typedef enum{
    MJPEGEncOpenAdapt_FUNC,
    MJPEGEncInitAdapt_FUNC,
    MJPEGEncGetParameterAdapt_FUNC,
    MJPEGEncSetParameterAdapt_FUNC,
    MJPEGEncGenerateHeader_FUNC,
    MJPEGEncEncodeOneFrame_FUNC,
    MJPEGEncDeInitAdapt_FUNC,
    MJPEGEncCloseAdapt_FUNC,
    MJPEGEncGetNextBitstream_FUNC,
    _MJPEGEncCallback_FUNC,
    GetMJPEGEncoderHandler_FUNC
}MJPEG_FUNC_T;

/****************************************************************************
*    BISTREAM_BUFFER_UNIT_STATUS_T;
*
*   State of bitstream buffer of encoder for bypass mode
*
****************************************************************************/
typedef enum
{
    BS_UNKNOW= 0,
    BS_AVAILABLE,
    BS_ENCODING,
    BS_READY2WRITE,
    BS_WRITING
} BISTREAM_BUFFER_UNIT_STATUS_T;

#endif /* VIDEO_CODEC_TYPE_V2_H */
