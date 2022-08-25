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
 *   video_stream_if_v2.h
 *
 * Project:
 * --------
 *  MAUI - Video Architecture 2
 *
 * Description:
 * ------------
 *   Streaming APIs
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __VIDEO_STREAM_IF_V2_H__
#define __VIDEO_STREAM_IF_V2_H__

#ifdef __VIDEO_ARCHI_V2__

////////////////////////////////////////////////
//     internal use
////////////////////////////////////////////////

#include "l1audio.h"
#include "video_types_v2.h"
#include "video_decoder_demuxer_if_v2.h"
#include "video_player_if_v2.h"

//.................................................. from video_stream_if.h

/* supported rtp types */
typedef enum
{
  VIDEO_DEC_STREAM_RTP_SCENARIO,
  VIDEO_DEC_STREAM_MTV_SCENARIO
}VIDEO_DEC_STREAM_SCENARIO;

/* supported rtp types */
typedef enum
{
    VIDEO_DEC_STREAM_NONE,
    VIDEO_DEC_STREAM_MPEG4,
    VIDEO_DEC_STREAM_H263,
    VIDEO_DEC_STREAM_H264
}VIDEO_DEC_STREAM_TYPE;

/* different codec types */
typedef enum
{
    video_rtp_codec_none = 0,
    video_rtp_codec_mp4 = 1,
    video_rtp_codec_h263 = 2,
    video_rtp_codec_h264 = 4,
    video_rtp_codec_vc1 = 8
} video_rtp_codec_type;

/* RTP status */
typedef enum
{
    VIDEO_RTP_OK=0,
    VIDEO_RTP_UNDERFLOW,
    VIDEO_RTP_OVERFLOW,
    VIDEO_RTP_PACKET_LOST,
    VIDEO_RTP_PACKET_ERROR,
    VIDEO_RTP_ERROR,
    VIDEO_RTP_RESOLUTION_ERR,
    VIDEO_RTP_RESOLUTION_NOT_READY
} VIDEO_RTP_STATUS;

/* RTP callback events */
typedef enum
{
    VIDEO_RTP_EVENT_OVERFLOW=10,
    VIDEO_RTP_EVENT_UNDERFLOW,
    VIDEO_RTP_EVENT_PACKET_LOSS,
    VIDEO_RTP_EVENT_RESOLUTION_ERR,
    VIDEO_RTP_EVENT_DECODE_ERROR
} VIDEO_RTP_EVENT;

typedef struct
{
    kal_uint32  timescale;
    kal_uint8   profile_level;
    kal_uint8   *pconfig;			// store VOS
    kal_uint32  vos_length;
}video_rtp_mp4_cap;

typedef struct
{
    kal_uint32  timescale;
    kal_uint8   profile;
    kal_uint8   level;
}video_rtp_h263_cap;

typedef struct
{
    kal_uint32  timescale;	// Sampling rate
    kal_uint8   packetization_mode;	// 0: single NAL mode. 1: Non-interleaved mode. 2: Interleaved mode. Default 0 if not present.
    kal_uint8   profile_idc;					// u(8)
    kal_uint8   level_idc;					// u(8)
    kal_uint8   *AVC_config_record;      //pps & sps data is put hear
    kal_uint32  AVC_config_record_size;
} video_rtp_h264_cap;

/* H.264 related */
#define H264_RTP_HEADER_SIZE 2
#define H264_RTP_AGGREGATE_LENGTH_SIZE 2
typedef enum
{
	H264_RTP_SINGLE_NALU_MODE = 0,
	H264_RTP_NON_INTERLEAVED_MODE = 1,
	H264_RTP_INTERLEAVED_MODE = 2
}H264_RTP_PACKETIZATION_MODE;

//.................................................. ~from video_stream_if.h


//#define VIDEO_STREAM_UNIT_TEST 1

#ifdef VIDEO_STREAM_UNIT_TEST
#include "video_filereader_component_v2.h"
extern MP4_Parser_Status eGParserStatus;
extern STMp4Parser *prGMp4Parser;
extern STFSAL *prGFSAL;
#define VIDEO_STREAM_PUTFRAME_EVENT_COMPLETE	  ((kal_uint32)0x00000010)
#endif

// enum
#define VIDEO_STREAM_DEC_TYPE_T         VIDEO_DEC_STREAM_TYPE
#define VIDEO_STREAM_CODEC_TYPE_T       video_rtp_codec_type
#define VIDEO_STREAM_STATUS_T           VIDEO_RTP_STATUS
#define VIDEO_STREAM_EVENT_T            VIDEO_RTP_EVENT
#define VIDEO_STREAM_SCENARIO_T         VIDEO_DEC_STREAM_SCENARIO

// struct
#define VIDEO_STREAM_HANDLER_T          Video_Rtp_Handle_Struct
#define VIDEO_STREAM_MPEG4_CAP_T        video_rtp_mp4_cap
#define VIDEO_STREAM_H263_CAP_T         video_rtp_h263_cap
#define VIDEO_STREAM_H264_CAP_T         video_rtp_h264_cap
#define VIDEO_STREAM_CONFIG_T           VIDEO_RTP_CONFIG_STRUCT
#define VIDEO_STREAM_IMAGEDMA_CONFIG_T  MP4DEC_IMGPATH_STRUCT

#ifdef VIDEO_STREAM_UNIT_TEST
#define VIDEO_STREAM_EVENT_FILEREADER_COMPLETE			  ((kal_uint32)0x00000001)
#define VIDEO_STREAM_EVENT_FILEREADER_ERROR				  ((kal_uint32)0x00000002)
#endif

#define VIDEO_STREAM_EVENT_DECODER_COMPLETE               ((kal_uint32)0x00000010)
#define VIDEO_STREAM_EVENT_DECODER_ERROR                  ((kal_uint32)0x00000020)
#define VIDEO_STREAM_EVENT_DECODER_NOTIFY_WAIT_BUFFER     ((kal_uint32)0x00000040)
#define VIDEO_STREAM_EVENT_DECODER_NOTIFY_COMPLETE        ((kal_uint32)0x00000080)

#define VIDEO_STREAM_EVENT_SCHEDULER_COMPLETE             ((kal_uint32)0x00000100)
#define VIDEO_STREAM_EVENT_SCHEDULER_ERROR                ((kal_uint32)0x00000200)

#define VIDEO_STREAM_EVENT_CLOCK_COMPLETE                 ((kal_uint32)0x00001000)
#define VIDEO_STREAM_EVENT_CLOCK_ERROR                    ((kal_uint32)0x00002000)
#define VIDEO_STREAM_EVENT_CLOCK_NOTIFY_START             ((kal_uint32)0x00004000)

#define VIDEO_STREAM_EVENT_RENDER_COMPLETE                ((kal_uint32)0x00010000)
#define VIDEO_STREAM_EVENT_RENDER_ERROR                   ((kal_uint32)0x00020000)

typedef enum
{
    VIDEO_STREAM_COMPONENT_DECODER = 0x1,
    VIDEO_STREAM_COMPONENT_SCHEDULER = 0x2,
    VIDEO_STREAM_COMPONENT_CLOCK = 0x4,
    VIDEO_STREAM_COMPONENT_RENDER = 0x8
}VIDEO_STREAM_COMPONENT_T;

typedef enum
{
    VIDEO_STREAM_DECODER_WAIT_BUFFER = 0x1,
    VIDEO_STREAM_DECODER_COMPLETE = 0x2,
    VIDEO_STREAM_DECODER_ERROR = 0X4,
    VIDEO_STREAM_SCHEDULER_COMPLETE = 0x8,
    VIDEO_STREAM_SCHEDULER_RECOVER = 0x10,
    VIDEO_STREAM_CLOCK_START = 0x20,
    VIDEO_STREAM_RENDER_ERROR = 0x40
}VIDEO_STREAM_IL_EVENT_T;

typedef enum
{
    VIDEO_STREAM_STATE_INIT,
    VIDEO_STREAM_STATE_PLAYING,
    VIDEO_STREAM_STATE_PLAYED,
    VIDEO_STREAM_STATE_STOP,
    VIDEO_STREAM_STATE_CLOSE
}VIDEO_STREAM_STATE_T;

#define MAX_HEADER_DATA_SIZE 100
#define VIDEO_STREAM_NAL_PARAM_CTRL_BUFF_SIZE 100

typedef enum
{
    VIDEO_STREAM_BUFFERFLAG_NONE = 0x00,
    VIDEO_STREAM_BUFFERFLAG_EOF = 0x01,
    VIDEO_STREAM_BUFFERFLAG_STARTTIME = 0x02,
    VIDEO_STREAM_BUFFERFLAG_MAX
}VIDEO_STREAM_BUFFERFLAG_TYPE_T;

typedef struct
{
    kal_uint8   *pu1Buffer;
    kal_uint32  u4BuffSize;
    kal_uint64  u8TimeStamp;
    VIDEO_STREAM_BUFFERFLAG_TYPE_T eFlags;
    void        *pPrivateData;
} VIDEO_STREAM_BUFFERHEADER_TYPE_T;

typedef struct
{
    void *p_codec_cap;
    rtp_audio_codec_type audio_type;
    kal_uint32 uSampleRate;
    void (*video_rtp_callback)(VIDEO_RTP_EVENT event);
    VIDEO_ERROR_TYPE_T (*pfnVideoStreamFreeBitstream)(void *pUserData, VIDEO_STREAM_BUFFERHEADER_TYPE_T *prBuffHeader);
    void *pUserData; // free bitstream handle
    
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;
    kal_uint32 max_lcd_width;
    kal_uint32 max_lcd_height;
}VIDEO_RTP_CONFIG_STRUCT;

typedef struct Video_Rtp_Handle_Struct_t Video_Rtp_Handle_Struct;
struct Video_Rtp_Handle_Struct_t
{
    video_rtp_codec_type  (*GetAvailableCodecs)(Video_Rtp_Handle_Struct *p_handle);
    VIDEO_RTP_STATUS      (*SetActiveCodec)(Video_Rtp_Handle_Struct *p_handle, video_rtp_codec_type type);
    VIDEO_RTP_STATUS      (*GetCapability)(Video_Rtp_Handle_Struct *p_handle, void *p_codec_cap);
    VIDEO_RTP_STATUS      (*Config)(Video_Rtp_Handle_Struct *p_handle,VIDEO_RTP_CONFIG_STRUCT *video_rtp_config);
    VIDEO_RTP_STATUS      (*ImagePathOpen)(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_data_input);
    VIDEO_RTP_STATUS      (*ImagePathClose)(Video_Rtp_Handle_Struct *p_handle);
    VIDEO_RTP_STATUS      (*GetImageResolution)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_width, kal_uint32 *p_height,void (*video_rtp_callback)(VIDEO_RTP_EVENT event));
    VIDEO_RTP_STATUS      (*Start)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_time,void (*video_rtp_callback)(VIDEO_RTP_EVENT event));
    VIDEO_RTP_STATUS      (*Stop) (Video_Rtp_Handle_Struct *p_handle);
    VIDEO_RTP_STATUS      (*Close)(Video_Rtp_Handle_Struct *p_handle);
    VIDEO_RTP_STATUS      (*PutPacket) (Video_Rtp_Handle_Struct *p_handle, kal_uint8 *p_buffer, kal_uint32 buffer_size);
    VIDEO_RTP_STATUS      (*GetPlayTime)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_current_time);
    // new in V2
    VIDEO_RTP_STATUS      (*PutFrameV2) (Video_Rtp_Handle_Struct *prHdlr, VIDEO_STREAM_BUFFERHEADER_TYPE_T *prStreamBuffHeader);
    // ~new in V2
    VIDEO_RTP_STATUS      (*GetBufferDuration)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_buffer_duration);
    VIDEO_RTP_STATUS      (*GetBufferStatus)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *p_percentge_used, kal_uint32 *p_free_space);
    VIDEO_RTP_STATUS      (*SwitchScreen_VideoStop)(Video_Rtp_Handle_Struct *p_handle);
    VIDEO_RTP_STATUS      (*SwitchScreen_VideoStart)(Video_Rtp_Handle_Struct *p_handle, MP4DEC_IMGPATH_STRUCT *p_data_input);
    VIDEO_RTP_STATUS      (*CheckPkts)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 start_seq, kal_uint32 diff_thre);
    VIDEO_RTP_STATUS      (*GetAvailableNumberOfFrames)(Video_Rtp_Handle_Struct *p_handle, kal_uint32 *frame_no, kal_uint32 *required_frame_no);
    VIDEO_RTP_STATUS      (*SetSwitchScreenVideoStop)(Video_Rtp_Handle_Struct *p_handle, kal_bool value);

    // internal use
    VIDEO_DEC_STREAM_SCENARIO   scenario;
    void                        (*callback)(VIDEO_RTP_EVENT event);
    video_rtp_mp4_cap           *p_mp4_cap;
    video_rtp_h263_cap          *p_h263_cap;
    video_rtp_h264_cap          *p_h264_cap;
    VIDEO_DEC_STREAM_TYPE       g_stream_type;
};

typedef struct
{
    kal_eventgrpid eEvent;
    VIDEO_COMPONENT_TYPE_T *prDecoderHdlr;
    VIDEO_COMPONENT_TYPE_T *prSchedulerHdlr;
    VIDEO_COMPONENT_TYPE_T *prClockHdlr;
    VIDEO_COMPONENT_TYPE_T *prRenderHdlr;
    VIDEO_ERROR_TYPE_T (*pfnVideoStreamFreeBitstream)(void *pUserData, VIDEO_STREAM_BUFFERHEADER_TYPE_T *prStreamBuffHeader);
    void *pUserData;  // free bitstream handle
    void (*pfnVideoStreamCallback)(VIDEO_RTP_EVENT eEvent);
    VIDEO_STREAM_STATE_T eState;
    VIDEO_STATE_TYPE_T eComponentState;
    VIDEO_DECODER_TYPE_T eCodecType;
    kal_uint32 u4Width;
    kal_uint32 u4Height;
    kal_uint32 u4HdlrType;
    kal_bool fgDecoderComplete;
    kal_bool fgSchedulerComplete;
    kal_bool fgPutHeaderData;
    kal_bool fgFreeHeaderData;
    kal_bool fgChangeDecoderToRun;
    kal_bool fgIsDecoderReady;
    kal_bool fgIsClockReady;
    kal_bool fgIsReadyStart;
    VIDEO_ERROR_TYPE_T eQueryResolutionResult;
    kal_uint8 au1HeaderData[MAX_HEADER_DATA_SIZE];
    kal_uint32 u4HeaderDataSize;
    // The private data is used only for H.264
    // The buffer is used for parameter set record
    H264_DECODER_INPUT_PARAM_T rPrivateData;
    H264_DECODER_PAYLOAD_INFO_T arNALCTRLBuff[VIDEO_STREAM_NAL_PARAM_CTRL_BUFF_SIZE];
}VIDEO_STREAM_STRUCT_T;

#ifndef MACRO_UTILITIES
#define MACRO_UTILITIES

#define AOF( exp )          \
{                           \
    if( !( exp ) )          \
    {ASSERT(0);}            \
}

#define AOT( exp )          \
{                           \
    if( ( exp ) )           \
    {ASSERT(0);}            \
}

#define OFFIBIT( exp )      \
{                           \
    kal_uint32 u4SavedMask; \
    u4SavedMask = SaveAndSetIRQMask(); \
    ( exp );                \
    RestoreIRQMask(u4SavedMask); \
}

#endif //MACRO_UTILITIES

////////////////////////////////////////////////
//     external use
////////////////////////////////////////////////

#define Video_Rtp_Query_Capability VideoStreamQueryCapability
VIDEO_STREAM_HANDLER_T* VideoStreamGetHandle(VIDEO_STREAM_SCENARIO_T eScenario);
VIDEO_STREAM_STATUS_T VideoStreamQueryCapability(VIDEO_STREAM_DEC_TYPE_T eType, void *pCodecCap);
kal_bool VideoStreamQueryStart(void);

#endif /* __VIDEO_ARCHI_V2__ */

#endif /* __VIDEO_STREAM_IF_V2_H__ */
