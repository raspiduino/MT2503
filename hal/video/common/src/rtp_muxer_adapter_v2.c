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
 *   rtp_muxer_adapter_v2.c
 *
 * Project:
 * --------
 *   MAUI
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
 ****************************************************************************/
#include "drv_features_video.h"

//#ifdef __VE_DCM_WITH_COMPRESSION__
//#include "dcmgr.h" //DCM
//#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
//#endif

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_SUPPORT_RTP_MUXER_ADAPTER__

#include "kal_public_api.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"

#include "vcodec_v2_trc.h"
#include "video_muxer_if_v2.h"
#include "vcodec_enc_demuxer_if.h"
#include "rtp_muxer_adapter_v2.h"
#include "rtp_muxer_adapter_if_v2.h"
#include "rtp_api.h"

#define _RTP_DEBUG_ASSERT() do{ASSERT(0);}while(0)
#define MAX_RTP_PAYLOAD_SIZE 			(1408)		// 
#define SPS_PERIOD						(1000000) 	//ms
#define MAX_SOCK_ADDR_LEN          	(28)	  	// socket address length

/*
#define TIME_PER_AMR_FRAME            (20000)         // AMR: 20ms per frame
#define SIZE_PER_AMR_FRAME          	(33)            // AMR: 33 bytes per frame for RTP 
#define SIZE_PER_PCM_FRAME          	(16)           // PCM: 160 bytes per frame for RTP 
#define TIME_PER_PCM_FRAME          	(2000)         // PCM
*/

/******************************************************************************
* Static global variable(s)
******************************************************************************/
static RTP_MUXER_ADAPTER_STATE_T _rRTPALMgr;
static kal_eventgrpid g_eEvent;

//#define __RTP_DUMP__
#ifdef __RTP_DUMP__
static FS_HANDLE g_hVFile;
static FS_HANDLE g_hAFile;
#endif

#define SWAP_4(x)    (((x & 0x000000FF) << 24) |     \
                     ((x & 0x0000FF00) <<  8) |                 \
                     ((x & 0x00FF0000) >>  8) |                 \
                     ((x & 0xFF000000) >> 24))

static kal_uint8 *_RTP_Strcpy(kal_uint8 *to, const kal_uint8 *from)
{
   kal_uint8 *temp = to;

   while ( *from )
      *to++ = *from++;

   *to=0;
   
   return temp;
}


static void _RTP_CallBack(const kal_uint32 u4Event, void* const pParam)
{
    RTP_MUXER_ADAPTER_STATE_T* _prALMgr = &_rRTPALMgr;
    _prALMgr->pfnCallBack(u4Event, pParam);
}

static void _RTP_ReturnData(kal_uint32 u4DataType, kal_uint8* pu1Addr, kal_uint32 u4Size)
{
    MUXER_PROCESS_PARAM_T rParam;

    kal_mem_set(&rParam, 0, sizeof(rParam));
    rParam.u4DataType = u4DataType;
    rParam.arData[0].fgValid = KAL_TRUE;
    rParam.arData[0].pu1Addr = pu1Addr;
    rParam.arData[0].u4Size = u4Size;
    rParam.arData[1].fgValid = KAL_FALSE;
    _RTP_CallBack(RTP_EVENT_RETURN_BUFFER, &rParam);
}

__inline static VIDEO_ERROR_TYPE_T _RTP_ParseAMRHeader(kal_uint8 u1AMRType, kal_uint8 u1FrameHeader, kal_uint8 *pu1FrameLength)
{
    kal_uint8 u1FrameType;
    kal_uint8 u1FQI;

    static const kal_uint16 lenSpeechBitsAMR[] =
    {
        95, 103, 118, 134, 148, 159, 204, 244, 39
    };

    u1FrameType = (u1FrameHeader >> 3) & 0x0F;
    u1FQI = (u1FrameHeader >> 2) & 0x01;
    if (u1FQI == 0)
    {
        return VIDEO_ERROR_PARSER_ERROR;
    }

    if (u1AMRType == 0)
    {
        u1FQI = 8;   // AMR
    }
    else
    {
        u1FQI = 9;   // AMR-WB
    }

    if (u1FrameType <= u1FQI)
    {
        *pu1FrameLength = (lenSpeechBitsAMR[u1FrameType] + 7) / 8;
    }
    else if (u1FrameType == 15)
    {
        *pu1FrameLength = 0;
    }
    else
    {
        return VIDEO_ERROR_PARSER_ERROR;
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Parse AMR Data
 */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __RTP_DEBUG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif 

static void _RTP_Send(kal_int8 rtp_handle, kal_uint8 *payload, kal_int32 payload_len,  kal_int32 timestamp, kal_bool fgFrameEn)
{
    if (KAL_FALSE == MuxerQueryStopState())
    {
        rtp_send(rtp_handle, payload, payload_len, timestamp, fgFrameEn);
    }
    else
    {
        kal_prompt_trace(MOD_VIDEO, "[RTPAdapter] Got instant stop, don't send data again");
    }
}


__inline static void _RTP_Send_Video_Sequence(kal_uint64 u8Timestamp)
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    if (u8Timestamp == 0 || (u8Timestamp > (prRTPALMgr->u8LastSPSTime + SPS_PERIOD)))
    {
        drv_trace1(TRACE_GROUP_10, RTPAL_SEND_SEQUENCE_HEADER, (kal_uint32)prRTPALMgr->u4SeqHeaderSize);
        _RTP_Send(prRTPALMgr->vid_rtp_handle, prRTPALMgr->au1SeqHeader, prRTPALMgr->u4SeqHeaderSize, u8Timestamp, KAL_TRUE);
        prRTPALMgr->u8LastSPSTime = u8Timestamp;
    }
}

__inline static VIDEO_ERROR_TYPE_T _RTP_Send_Partial_MPEG4_Video(kal_int8 rtp_handle, kal_uint8* const pu1Addr, const kal_uint32 u4Size, kal_uint64 u8Timestamp, kal_bool fgMark)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4Index = 0;
    kal_uint32 u4Count = u4Size / (MAX_RTP_PAYLOAD_SIZE);
    kal_uint32 u4LeftSize = u4Size % (MAX_RTP_PAYLOAD_SIZE);

    drv_trace2(TRACE_GROUP_9, RTPAL_SEND_PT_MPEG4_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), (kal_uint32)u4Size);
    if (u4LeftSize == 0)
    {
        u4LeftSize = MAX_RTP_PAYLOAD_SIZE;
        u4Count -= 1;
    }
	
    // Send to RTP Task
    for(; u4Index < u4Count; u4Index++)
    {
        kal_uint8* const pu1CurAddr = pu1Addr + u4Index * MAX_RTP_PAYLOAD_SIZE;
        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), u4Index, (kal_uint32)pu1CurAddr, MAX_RTP_PAYLOAD_SIZE);
        _RTP_Send(rtp_handle, pu1CurAddr, MAX_RTP_PAYLOAD_SIZE, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), KAL_FALSE);
    }

    if(u4LeftSize > 0)
    {
        kal_uint8* const pu1CurAddr = pu1Addr + u4Index * MAX_RTP_PAYLOAD_SIZE;
        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), u4Index, (kal_uint32)pu1CurAddr, u4LeftSize);
        _RTP_Send(rtp_handle, pu1CurAddr, u4LeftSize, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), fgMark);
    }

    return eError;
}

__inline static void _RTP_Send_One_MPEG4_Video()
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_VIDEO];
    kal_uint32 u4Index = 0;
    kal_bool fgMark = KAL_FALSE;
	
    for(; u4Index < MAX_BUFFER_PARTITION; u4Index++)
    {
        RTP_BUFFER_T *prRTPBuffer = &prRTPBufMgr->arRTPbuffer[u4Index];

        if (u4Index == (MAX_BUFFER_PARTITION - 1) ||
            prRTPBufMgr->arRTPbuffer[u4Index + 1].fgValid == KAL_FALSE)
        {
            fgMark = KAL_TRUE;
        }

        if (prRTPBuffer->fgValid)
        {
            kal_uint8*	pu1Addr = prRTPBuffer->pu1Addr;
            kal_uint32	u4Size = prRTPBuffer->u4Size;
            _RTP_Send_Partial_MPEG4_Video(prRTPALMgr->vid_rtp_handle, pu1Addr, u4Size, prRTPBufMgr->u8Timestamp, fgMark);
            _RTP_ReturnData(MX_DATATYPE_VIDEO, pu1Addr, u4Size);
            kal_mem_set(prRTPBuffer, 0, sizeof(RTP_BUFFER_T));
        }
    }
    prRTPBufMgr->fgUsed = KAL_FALSE;
    //_RTP_Send_Video_Sequence(prRTPBufMgr->u8Timestamp);
}

__inline static VIDEO_ERROR_TYPE_T _RTP_Send_Partial_H264_Video(kal_int8 rtp_handle, kal_uint8* const pu1Addr, const kal_uint32 u4Size, kal_uint64 u8Timestamp, kal_uint8 *pauFUHeader, kal_bool fgMark, kal_bool fgFirstFU)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    kal_uint32 u4Index = 0;
    kal_uint32 u4Count = u4Size / (MAX_RTP_PAYLOAD_SIZE);
    kal_uint32 u4LeftSize = u4Size % (MAX_RTP_PAYLOAD_SIZE);
    kal_uint32 u4FuHeaderSize = 2;

    drv_trace2(TRACE_GROUP_9, RTPAL_SEND_PT_H264_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), (kal_uint32)u4Size);	
    prRTPALMgr->pau1H264RTPPayload[0] = pauFUHeader[0];
    prRTPALMgr->pau1H264RTPPayload[1] = pauFUHeader[1];

    if (u4LeftSize == 0)
    {
        u4LeftSize = MAX_RTP_PAYLOAD_SIZE;
        u4Count -= 1;
    }
	
	// Send to RTP Task
    for(; u4Index < u4Count; u4Index++)
    {
        kal_uint8* const pu1CurAddr = pu1Addr + u4Index * MAX_RTP_PAYLOAD_SIZE;

        if (fgFirstFU == KAL_TRUE)
        {
            prRTPALMgr->pau1H264RTPPayload[1] |= 0x80;
            fgFirstFU = KAL_FALSE;
        }
        else
        {
            prRTPALMgr->pau1H264RTPPayload[1] &= 0x7F;
        }

        kal_mem_cpy(&prRTPALMgr->pau1H264RTPPayload[u4FuHeaderSize], pu1CurAddr, MAX_RTP_PAYLOAD_SIZE);
        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), u4Index, (kal_uint32)pu1CurAddr, MAX_RTP_PAYLOAD_SIZE);
        _RTP_Send(rtp_handle, prRTPALMgr->pau1H264RTPPayload, MAX_RTP_PAYLOAD_SIZE + u4FuHeaderSize, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), KAL_FALSE);
    }
	
    if(u4LeftSize > 0)
    {
        kal_uint8* const pu1CurAddr = pu1Addr + u4Index * MAX_RTP_PAYLOAD_SIZE;

        if (fgFirstFU == KAL_TRUE)
        {
            prRTPALMgr->pau1H264RTPPayload[1] |= 0x80;
        }
        else
        {
            prRTPALMgr->pau1H264RTPPayload[1] &= 0x7F;
        }

        if (fgMark == KAL_TRUE)
        {
            prRTPALMgr->pau1H264RTPPayload[1] |= 0x40;
        }

        kal_mem_cpy(&prRTPALMgr->pau1H264RTPPayload[u4FuHeaderSize], pu1CurAddr, u4LeftSize);
        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_VIDEO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), u4Index, (kal_uint32)pu1CurAddr, u4LeftSize);
        _RTP_Send(rtp_handle, prRTPALMgr->pau1H264RTPPayload, u4LeftSize + u4FuHeaderSize, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), fgMark);
    }

    return eError;
}

__inline static void _RTP_Send_FU_H264_NAL()
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_VIDEO];
    RTP_BUFFER_T *prRTPBuffer1 = &prRTPBufMgr->arRTPbuffer[0];
    RTP_BUFFER_T *prRTPBuffer2 = &prRTPBufMgr->arRTPbuffer[1];
    kal_bool fgMark = KAL_FALSE;

	/*
		0					1					2					3
		0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	   | FU indicator  |   FU header   |							   |
	   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+							   |
	   |															   |
	   |						 FU payload 						   |
	   |															   |
	   |							   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	   |							   :...OPTIONAL RTP padding 	   |
	   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

      FU indicator 
	+---------------+
	|0|1|2|3|4|5|6|7|
	+-+-+-+-+-+-+-+-+
	|F|NRI|  Type	|
	+---------------+

      FU header:
	+---------------+
	|0|1|2|3|4|5|6|7|
	+-+-+-+-+-+-+-+-+
	|S|E|R|  Type	|
	+---------------+
	*/
    kal_uint8 au1FU[2] = {0, 0}; 

    // Input Buffer
    // Buffer 1--> NAL Size(32)|NAL TYPE(8)|NAL DATA(...)
    // Buffer 2--> NAL DATA(...)
    kal_uint8 u1NAlUnitStart = prRTPBufMgr->arRTPbuffer[0].pu1Addr[4];
    kal_uint8 u1NRI = (u1NAlUnitStart & 0x60) >> 5;
    kal_uint8 u1NalType = u1NAlUnitStart & 0x1F;

    au1FU[0] |= (u1NRI << 5);
    au1FU[0] |= (28); // FU-A
    au1FU[1] |= u1NalType;

    if (prRTPBuffer2->fgValid == KAL_FALSE)
    {
        fgMark = KAL_TRUE;	
    }

    _RTP_Send_Partial_H264_Video(prRTPALMgr->vid_rtp_handle, prRTPBuffer1->pu1Addr + 5, prRTPBuffer1->u4Size - 5, (kal_uint32)(prRTPBufMgr->u8Timestamp & 0xFFFFFFFF), au1FU, fgMark, KAL_TRUE); 
    _RTP_ReturnData(MX_DATATYPE_VIDEO, prRTPBuffer1->pu1Addr, prRTPBuffer1->u4Size);
    kal_mem_set(prRTPBuffer1, 0, sizeof(RTP_BUFFER_T));
	
    if (prRTPBuffer2->fgValid == KAL_TRUE)
    {
        fgMark = KAL_TRUE;
        _RTP_Send_Partial_H264_Video(prRTPALMgr->vid_rtp_handle, prRTPBuffer2->pu1Addr, prRTPBuffer2->u4Size, (kal_uint32)(prRTPBufMgr->u8Timestamp & 0xFFFFFFFF), au1FU, fgMark, KAL_FALSE); 
        _RTP_ReturnData(MX_DATATYPE_VIDEO, prRTPBuffer2->pu1Addr, prRTPBuffer2->u4Size);
        kal_mem_set(prRTPBuffer2, 0, sizeof(RTP_BUFFER_T));
    }	
}

__inline static void _RTP_Send_Single_H264_NAL()
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_VIDEO];
    RTP_BUFFER_T *prRTPBuffer1 = &prRTPBufMgr->arRTPbuffer[0];
    RTP_BUFFER_T *prRTPBuffer2 = &prRTPBufMgr->arRTPbuffer[1];
    kal_uint32 u4Size = prRTPBuffer1->u4Size;
    kal_uint8* pu1Addr;

    // Input Buffer
    // Buffer 1--> NAL Size(32)|NAL TYPE(8)|NAL DATA(...)
    // Buffer 2--> NAL DATA(...)

    // Merge two buffer to single buffer
    if (prRTPBuffer2->fgValid == KAL_TRUE)
    {
        kal_mem_cpy(&prRTPALMgr->pau1H264RTPPayload, prRTPBuffer1->pu1Addr, u4Size);
        kal_mem_cpy(&prRTPALMgr->pau1H264RTPPayload + u4Size, prRTPBuffer2->pu1Addr, prRTPBuffer2->u4Size);
        u4Size += prRTPBuffer2->u4Size;
        pu1Addr = prRTPALMgr->pau1H264RTPPayload;		
    }
    else
    {
        pu1Addr = prRTPBuffer1->pu1Addr;
    }

    /*
	 0					 1					 2					 3
	 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|F|NRI|  type	|												|
	+-+-+-+-+-+-+-+-+												|
	|																|
	|				Bytes 2..n of a Single NAL unit 				|
	|																|
	|								+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|								:...OPTIONAL RTP padding		|
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      */
	// Ignore NAL size
    _RTP_Send(prRTPALMgr->vid_rtp_handle, pu1Addr + 4, u4Size - 4, (kal_uint32)(prRTPBufMgr->u8Timestamp & 0xFFFFFFFF), KAL_TRUE);

    _RTP_ReturnData(MX_DATATYPE_VIDEO, prRTPBuffer1->pu1Addr, prRTPBuffer1->u4Size);
    kal_mem_set(prRTPBuffer1, 0, sizeof(RTP_BUFFER_T));
    if (prRTPBuffer2->fgValid == KAL_TRUE)
    {
        _RTP_ReturnData(MX_DATATYPE_VIDEO, prRTPBuffer2->pu1Addr, prRTPBuffer2->u4Size);
        kal_mem_set(prRTPBuffer2, 0, sizeof(RTP_BUFFER_T));
    }
}

__inline static void _RTP_Send_One_H264_Video()
{
    RTP_BUFFER_MGR *prRTPBufMgr = &_rRTPALMgr.rRTPBufMgr[RTP_VIDEO];
    kal_int32 u4NalSize;

	// Get nal size
    kal_mem_cpy(&u4NalSize, prRTPBufMgr->arRTPbuffer[0].pu1Addr, sizeof(u4NalSize));
    u4NalSize = SWAP_4(u4NalSize);

    if (u4NalSize > MAX_RTP_PAYLOAD_SIZE)
    {
        _RTP_Send_FU_H264_NAL();
    }
    else
    {
        _RTP_Send_Single_H264_NAL();	
    }

    prRTPBufMgr->fgUsed = KAL_FALSE;
}

__inline static void _RTP_Send_AMR_Audio()
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_AUDIO];
    RTP_BUFFER_T *prRTPBuffer = &prRTPBufMgr->arRTPbuffer[0];
    kal_uint32 u4SizePerFrame = prRTPALMgr->rAudioConfig.u4AudioFrameSize;
    
    if (prRTPBuffer->fgValid)
    {
        kal_uint64 u8Timestamp = prRTPBufMgr->u8Timestamp;
        kal_uint8*	pu1Addr = prRTPBuffer->pu1Addr;
        kal_uint32	u4Size = prRTPBuffer->u4Size;
        kal_uint32  u4AMRNum =  u4Size / (u4SizePerFrame);
        kal_uint8 *pau1AMRBuffer = prRTPALMgr->pau1AMRRTPPayload;
        kal_uint32  u4Idx = 0;
        kal_uint32	u4RealSize = 1 + u4AMRNum + u4AMRNum * (u4SizePerFrame - 2);
		
		/*
		 0					 1					 2					 3
		 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
		+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		| CMR=1 |1| FT=0  |1|1| FT=9  |1|1| FT=15 |1|0| FT=1  |1|d(0)	|
		+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		|																|
		+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		*/

        for(; u4Idx < u4AMRNum; u4Idx++)
        {
            // CMR
            if(u4Idx == 0)	// First
            {
                pau1AMRBuffer[0] = pu1Addr[0];
                drv_trace2(TRACE_GROUP_9, RTPAL_SEND_AMR_AUDIO, (kal_uint32)pau1AMRBuffer[0], u4AMRNum);	
            }

            // TOC
            pau1AMRBuffer[1 + u4Idx] = pu1Addr[u4SizePerFrame * u4Idx + 1];

            if (u4Idx != u4AMRNum - 1)		// not the End
            {	
                pau1AMRBuffer[1 + u4Idx] |= 0x80;
            }

            // Data
            kal_mem_cpy(&pau1AMRBuffer[1 + u4AMRNum + u4Idx * (u4SizePerFrame-2)], &pu1Addr[u4SizePerFrame * u4Idx + 2], u4SizePerFrame - 2);
		}

        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_AUDIO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), 0, (kal_uint32)pau1AMRBuffer, u4RealSize);

        _RTP_Send(prRTPALMgr->aud_rtp_handle, pau1AMRBuffer, u4RealSize, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), KAL_TRUE);
        _RTP_ReturnData(MX_DATATYPE_AUDIO, pu1Addr, u4Size);
        kal_mem_set(prRTPBuffer, 0, sizeof(RTP_BUFFER_T));
    }
}

__inline static void _RTP_Send_PCM_Audio()
{
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_AUDIO];
    RTP_BUFFER_T *prRTPBuffer = &prRTPBufMgr->arRTPbuffer[0];

    //kal_prompt_trace(MOD_VIDEO,"_RTP_Send_PCM_Audio");
    if (prRTPBuffer->fgValid)
    {
        kal_uint64 u8Timestamp = prRTPBufMgr->u8Timestamp;
        kal_uint8*	pu1Addr = prRTPBuffer->pu1Addr;
        kal_uint32	u4Size = prRTPBuffer->u4Size;

        drv_trace4(TRACE_GROUP_10, RTPAL_RTP_SEND_AUDIO, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), 0, (kal_uint32)pu1Addr, u4Size);
        _RTP_Send(prRTPALMgr->aud_rtp_handle, pu1Addr, u4Size, (kal_uint32)(u8Timestamp & 0xFFFFFFFF), KAL_TRUE);
        _RTP_ReturnData(MX_DATATYPE_AUDIO, pu1Addr, u4Size);
        kal_mem_set(prRTPBuffer, 0, sizeof(RTP_BUFFER_T));
    }
}

static kal_uint8 _RTP_Encode6Bit(kal_uint8 x) 
{
    if (x <= 25) 
    {
        return 'A' + x;
    } 
    else if (x <= 51) 
    {
        return 'a' + x - 26;
    } 
    else if (x <= 61) 
    {
        return '0' + x - 52;
    } 
    else if (x == 62)
    {
        return '+';
    } 
    else 
    {
        return '/';
    }
}


static void _RTP_EncodeBase64(kal_uint8 *data, kal_uint32 size, kal_uint8 *out)
{
    kal_uint32 i;
    kal_uint32 idx = 0;
    for (i = 0; i < (size / 3) * 3; i += 3) 
    {
        kal_uint8 x1 = data[i];
        kal_uint8 x2 = data[i + 1];
        kal_uint8 x3 = data[i + 2];

        out[idx++] = _RTP_Encode6Bit(x1 >> 2);
        out[idx++] = _RTP_Encode6Bit((x1 << 4 | x2 >> 4) & 0x3f);
        out[idx++] = _RTP_Encode6Bit((x2 << 2 | x3 >> 6) & 0x3f);
        out[idx++] = _RTP_Encode6Bit(x3 & 0x3f);
            /*
            {
                kal_uint32 y1 = out[idx-4];
                kal_uint32 y2 = out[idx-3];
                kal_uint32 y3 = out[idx-2];
                kal_uint32 y4 = out[idx-1];

                kal_prompt_trace(MOD_VIDEO, "_RTP_EncodeBase64: %x,%x,%x --> %x,%x,%x,%x", 
                	(kal_uint32)x1, 
                	(kal_uint32)x2, 
                	(kal_uint32)x3, 
                	y1, y2, y3, y4);
                }
            */
    }
    switch (size % 3) 
    {
        case 0:
            break;
        case 2:
        {
            kal_uint8 x1 = data[i];
            kal_uint8 x2 = data[i + 1];

            out[idx++] = _RTP_Encode6Bit(x1 >> 2);
            out[idx++] = _RTP_Encode6Bit((x1 << 4 | x2 >> 4) & 0x3f);
            out[idx++] = _RTP_Encode6Bit((x2 << 2) & 0x3f);
            out[idx++] = '=';
            break;
        }
        default:
        {
            kal_uint8 x1 = data[i];

            out[idx++] = _RTP_Encode6Bit(x1 >> 2);
            out[idx++] = _RTP_Encode6Bit((x1 << 4) & 0x3f);
            out[idx++] = '=';
            out[idx++] = '=';
            break;
        }
    }
    out[idx] = 0;
}

__inline static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterOpen(void)
{
    kal_mem_set(&_rRTPALMgr, 0, sizeof(_rRTPALMgr));
    _rRTPALMgr.vid_rtp_handle = -1;
    _rRTPALMgr.aud_rtp_handle = -1;
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterInit(void)
{
    if (g_eEvent == NULL)
    {
        g_eEvent = kal_create_event_group("RTPAdapter");
    }
    else
    {
        kal_uint32 u4EventGroup;
        kal_retrieve_eg_events(g_eEvent, 0x1, KAL_OR_CONSUME, &u4EventGroup, KAL_NO_SUSPEND);
    }

#ifdef __RTP_DUMP__
        {
            WCHAR au2TempFileWorkingPath[64];
            kal_wsprintf(au2TempFileWorkingPath, "%s", "E:\\Videos\\video_dump.m4v");
            g_hVFile = FS_Open(au2TempFileWorkingPath, (FS_READ_WRITE | FS_CREATE_ALWAYS));
            
            kal_wsprintf(au2TempFileWorkingPath, "%s", "E:\\Videos\\audio_dump.raw");
            g_hAFile = FS_Open(au2TempFileWorkingPath, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        }
#endif

    //_rRTPALMgr.pau1H264RTPPayload = (kal_uint8*)MuxerAdaptGetMemory(RTP_H264_PAYLOAD_SIZE, KAL_TRUE);
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    //kal_prompt_trace(MOD_VIDEO, "_RTP_MuxerAdapterGetParam(%d)", eType);
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;
    
    switch (eType)
    {
    case MUXER_GET_MEMORY_SIZE:
        {
            *(kal_uint32*)pParam = 0;	// TODO: support later
        }
        break;
    case MUXER_GET_CURRENT_FILE_SIZE:
        {
            *(kal_uint64*)pParam = 0;
        }
        break;
    case MUXER_GET_RETURNING_VIDEO_BUFFER_NUMBER:
        {
            *(kal_uint32*)pParam = 1;
        }
        break;
    case MUXER_GET_RETURNING_AUDIO_BUFFER_NUMBER:
        {
            *(kal_uint32*)pParam = 1; // TODO: FIXME
        }
        break;
    case MUXER_GET_RTP_SEQ_HEADER:
        {
            kal_uint32 u4EventGroup;
            kal_uint8 *pstrBuffer = (kal_uint8 *)pParam;
            kal_retrieve_eg_events(g_eEvent, 0x1, KAL_OR, &u4EventGroup, KAL_SUSPEND);
            _RTP_Strcpy(pstrBuffer, prRTPALMgr->strSeqHeader);
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    }

    return eError;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterSetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

	//kal_prompt_trace(MOD_VIDEO, "_RTP_MuxerAdapterSetParam(%d)", eType);
	
	switch (eType)
	{
    case MUXER_SET_SCENARIO:
        {
            // Not support
        }
        break;
    case MUXER_SET_VIDEO_CONFIG:
        {
            _rRTPALMgr.rVideoConfig = *(MUXER_VIDEO_CONFIG_T*)(pParam);
        }
        break;
    case MUXER_SET_AUDIO_CONFIG:
        {
            _rRTPALMgr.rAudioConfig = *(MUXER_AUDIO_CONFIG_T*)(pParam);
        }
        break;

    case MUXER_SET_FILE_NAME_PATH:
        {
            // Not support
        }
        break;

    case MUXER_SET_WORKING_PATH:
        {
            // Not support
        }
        break;

    case MUXER_SET_CALLBACK:
        {
            _rRTPALMgr.pfnCallBack = (PFN_CALLBACK)pParam;
        }
        break;
    case MUXER_SET_SIZE_LIMIT:
        {
            // Not support
        }
        break;
    case MUXER_SET_TIME_LIMIT:
        {
            // Not support
        }
        break;
    case MUXER_SET_VIDEO_WRITE_THRESHOLD:
        {
            // Not support
        }
        break;
    case MUXER_SET_VIDEO_RTP_HANDLE:
        {
            _rRTPALMgr.vid_rtp_handle = *(kal_int8*)(pParam);
            drv_trace2(TRACE_GROUP_9, RTPAL_SET_RTP_HANDLE, (kal_uint32)_rRTPALMgr.vid_rtp_handle, (kal_uint32)_rRTPALMgr.aud_rtp_handle);
        }
        break;
    case MUXER_SET_AUDIO_RTP_HANDLE:
        {
            _rRTPALMgr.aud_rtp_handle = *(kal_int8*)(pParam);
            drv_trace2(TRACE_GROUP_9, RTPAL_SET_RTP_HANDLE, (kal_uint32)_rRTPALMgr.vid_rtp_handle, (kal_uint32)_rRTPALMgr.aud_rtp_handle);
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    };
    return eError;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterDirectlyGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    //kal_prompt_trace(MOD_VIDEO, "_RTP_MuxerAdapterDirectlyGetParam(%d)", eType);
    switch (eType)
    {
    case MUXER_IS_TEMP_FILE_EXISTED:
        {
            eError = VIDEO_ERROR_MUXER_NO_TEMP_FILE;
        }
        break;
    case MUXER_GET_MIN_SPACE_TO_RECORD:
        {
            MUXER_GET_MIN_SPACE_T *prMinSpaceParam = (MUXER_GET_MIN_SPACE_T *)pParam;
            {
                prMinSpaceParam->u4MinSpace = 0;
            }
        }
        break;

    case MUXER_GET_VIDEO_BITSTREAM_LEFTOVER:
        {
            // Not support
        }
        break;
    case MUXER_GET_AUDIO_HEADERSIZE:
        {
            *(kal_uint32*)pParam = 0;
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    };

    return eError;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterDirectlySetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    //kal_prompt_trace(MOD_VIDEO, "_RTP_MuxerAdapterDirectlySetParam(%d)", eType);
    switch (eType)
	{
        case MUXER_CLEAR_TEMP_FILE:
            {
            }
            break;
        case MUXER_SET_VIDEO_WRITE_THRESHOLD:
            {
            }
            break;
        default:
            {
                return VIDEO_ERROR_MUXER_NOT_SUPPORT;
            }
    };

    return eError;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterProcessData(MUXER_PROCESS_PARAM_T * pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;

    drv_trace4(TRACE_GROUP_10, RTPAL_RTP_PROCESS_DATA, pParam->u4DataType, (kal_uint32)(pParam->u8TimeStamp & 0xFFFFFFFF), pParam->arData[0].u4Size, pParam->arData[1].u4Size);
    // video or audio
    switch (pParam->u4DataType)
    {
        case MX_DATATYPE_VIDEO_SEQUENCE_HEADER:
        {
            if (pParam->arData[0].fgValid)
            {
                if (prRTPALMgr->rVideoConfig.eEncoderType ==  VIDEO_ENCODER_MPEG4)
                {
                    prRTPALMgr->u4SeqHeaderSize = pParam->arData[0].u4Size;
                    kal_mem_cpy(prRTPALMgr->au1SeqHeader, pParam->arData[0].pu1Addr, prRTPALMgr->u4SeqHeaderSize);              
                    // profile-level-id=8; config=000001b008000001b50ea020202f000001000000012000c788ba9850584121463f
                    // To string
                    {
                        kal_uint32 u4Idx = 0;
                        sprintf((char*)prRTPALMgr->strSeqHeader, "%s", "profile-level-id=8; config=");
                        for (;u4Idx < prRTPALMgr->u4SeqHeaderSize; u4Idx++)
                        {
                            sprintf((char*)prRTPALMgr->strSeqHeader, "%s%.2X", prRTPALMgr->strSeqHeader, prRTPALMgr->au1SeqHeader[u4Idx]);
                        }
                    }
#ifdef __RTP_DUMP__
                    {
                        kal_uint32 Written;
                        FS_Write(g_hVFile, prRTPALMgr->au1SeqHeader, prRTPALMgr->u4SeqHeaderSize, &Written);
                        FS_Commit(g_hVFile);
                    }
#endif	
                }
                else if (prRTPALMgr->rVideoConfig.eEncoderType ==  VIDEO_ENCODER_H264)
                {
                    kal_uint32 u4SPSSize, u4PPSSize;
                    kal_uint8* pBuffer = pParam->arData[0].pu1Addr;
                    kal_uint8* pSeqBuffer = &(prRTPALMgr->au1SeqHeader[0]);
                    //H264_ENC_CONF_REC * const prH264Configuration = (H264_ENC_CONF_REC *)pParam->pPrivateData;

                    kal_mem_cpy(&u4SPSSize, pBuffer, sizeof(u4SPSSize));
                    u4SPSSize = SWAP_4(u4SPSSize);
                    kal_mem_cpy(&u4PPSSize, pBuffer + 4 + u4SPSSize, sizeof(u4PPSSize));
                    u4PPSSize = SWAP_4(u4PPSSize);

                    kal_prompt_trace(MOD_VIDEO, "H264Configuration: SPSSize(%x), PPSSize(%x)", u4SPSSize, u4PPSSize);

                    prRTPALMgr->u4SeqHeaderSize = 8 + u4SPSSize + u4PPSSize;
                    kal_mem_cpy(pSeqBuffer, pBuffer, prRTPALMgr->u4SeqHeaderSize);
                    // 
                    // profile-level-id=42C00C;sprop-parameter-sets=Z0LADLkQWJ0IAAADAAgAAAMB5HihVQ==,aM48gA==
                    {
                        kal_uint8 au1Tmp[MAX_SEQ_HEADER_SIZE];
                        sprintf((char*)prRTPALMgr->strSeqHeader, "%s%.2X%.2X%.2X%s", "profile-level-id=", 
                                pSeqBuffer[5], 
                                pSeqBuffer[6], 
                                pSeqBuffer[7],
                                ";sprop-parameter-sets=");
                        _RTP_EncodeBase64(pSeqBuffer + 4, u4SPSSize, au1Tmp);
                        sprintf((char*)prRTPALMgr->strSeqHeader, "%s%s,", prRTPALMgr->strSeqHeader, au1Tmp);	
                        _RTP_EncodeBase64(pSeqBuffer + 8 + u4SPSSize, u4PPSSize, au1Tmp);
                        sprintf((char*)prRTPALMgr->strSeqHeader, "%s%s", prRTPALMgr->strSeqHeader, au1Tmp);
                    }
#ifdef __RTP_DUMP__	
                    {
                        kal_uint32 Written;
                        kal_uint8 auSync[4] = {0, 0, 0, 1};
                        FS_Write(g_hVFile, auSync, sizeof(auSync), &Written);
                        FS_Write(g_hVFile, pBuffer + sizeof(auSync), u4SPSSize, &Written);
                        FS_Write(g_hVFile, auSync, sizeof(auSync), &Written);
                        FS_Write(g_hVFile, pBuffer + sizeof(auSync) + u4SPSSize + sizeof(auSync), u4PPSSize, &Written);
                        //FS_Write(g_hVFile, _rRTPALMgr.au1SeqHeader, _rRTPALMgr.u4SeqHeaderSize, &Written);
                        FS_Commit(g_hVFile);
                    }
#endif			
                }
                else
                {
                    _RTP_DEBUG_ASSERT();	
                }
                kal_prompt_trace(MOD_VIDEO, "Debug(%s)", prRTPALMgr->strSeqHeader);
                kal_set_eg_events(g_eEvent, 0x1, KAL_OR);
                
                _RTP_ReturnData(MX_DATATYPE_VIDEO_SEQUENCE_HEADER, pParam->arData[0].pu1Addr, pParam->arData[0].u4Size);
                _RTP_CallBack(RTP_EVENT_RDY_2_SEND_VIDEO, &(pParam->u4DataType));
            }
            else
            {
                _RTP_DEBUG_ASSERT();
            }
		}
        break;
    case MX_DATATYPE_VIDEO:
        {
            RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_VIDEO];
            if(prRTPBufMgr->fgUsed == KAL_FALSE)
            {
                kal_uint32 u4Index = 0;
                for(; u4Index < MAX_BUFFER_PARTITION; u4Index++)
                {
                    if (pParam->arData[u4Index].fgValid)
                    {
                        RTP_BUFFER_T *prRTPbuffer = &prRTPBufMgr->arRTPbuffer[u4Index];
                        prRTPbuffer->fgValid = KAL_TRUE;
                        prRTPbuffer->pu1Addr = pParam->arData[u4Index].pu1Addr;
                        prRTPbuffer->u4Size = pParam->arData[u4Index].u4Size;
#ifdef __RTP_DUMP__	
                        {
                            kal_uint32 Written;
                            if (u4Index == 0)
                            {
                                kal_uint8 auSync[4] = {0, 0, 0, 1};
                                FS_Write(g_hVFile, auSync, sizeof(auSync), &Written);
                                FS_Write(g_hVFile, prRTPbuffer->pu1Addr + sizeof(auSync), prRTPbuffer->u4Size - sizeof(auSync), &Written);
                            }
                            else
                            {
                                FS_Write(g_hVFile, prRTPbuffer->pu1Addr, prRTPbuffer->u4Size, &Written);
                            }
                            // FS_Write(g_hVFile, prRTPbuffer->pu1Addr, prRTPbuffer->u4Size, &Written);
                            FS_Commit(g_hVFile);
                        }
#endif			
                    }
                }
                prRTPBufMgr->u8Timestamp = pParam->u8TimeStamp;
                prRTPBufMgr->fgUsed = KAL_TRUE;
                _RTP_CallBack(RTP_EVENT_RDY_2_SEND_VIDEO, &(pParam->u4DataType));
            }
            else
            {
                _RTP_DEBUG_ASSERT();
            }		
        }
        break;
    case MX_DATATYPE_AUDIO:
        {
            Media_Format eAudioFormat = prRTPALMgr->rAudioConfig.eAudioFormat;
            RTP_BUFFER_MGR *prRTPBufMgr = &prRTPALMgr->rRTPBufMgr[RTP_AUDIO];
            kal_uint32 u4SizePerFrame = prRTPALMgr->rAudioConfig.u4AudioFrameSize;
            kal_uint32 u4TimePerFrame = prRTPALMgr->rAudioConfig.u4AudioFrameDuration * 1000; // in us           
            
            drv_trace4(TRACE_GROUP_9, RTPAL_RTP_AUDIO_INFO, eAudioFormat, u4SizePerFrame, u4TimePerFrame, 0);    
            if (pParam->arData[0].fgValid)
            {
                RTP_BUFFER_T *prRTPbuffer = &prRTPBufMgr->arRTPbuffer[0];
                if (prRTPbuffer->fgValid == KAL_FALSE)
                {
                    prRTPbuffer->fgValid = KAL_TRUE;
                    prRTPbuffer->pu1Addr = pParam->arData[0].pu1Addr;
                    prRTPbuffer->u4Size = pParam->arData[0].u4Size;
                    prRTPBufMgr->u8Timestamp = (prRTPALMgr->u4AccumulatedAudioSize / (u4SizePerFrame)) * (u4TimePerFrame);
                    prRTPALMgr->u4AccumulatedAudioSize += prRTPbuffer->u4Size;
                    //_RTP_ParseAMRData(0, prRTPbuffer->pu1Addr, prRTPbuffer->u4Size);
                    _RTP_CallBack(RTP_EVENT_RDY_2_SEND_AUDIO, &(pParam->u4DataType));

#ifdef __RTP_DUMP__	
                    {
                        kal_uint32 Written;
                        FS_Write(g_hAFile, prRTPbuffer->pu1Addr, prRTPbuffer->u4Size, &Written);
                        FS_Commit(g_hAFile);
                    }
#endif			   
                }
            }      
        }
        break;
    default:
        {
        }
        break;
    };

    return eError;	
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterWriteData2File(MUXER_WRITE_PARAM_T * pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    RTP_MUXER_ADAPTER_STATE_T *prRTPALMgr = &_rRTPALMgr;

    drv_trace1(TRACE_GROUP_10, RTPAL_RTP_WRITE_DATA, pParam->u4DataType);
	
    switch (pParam->u4DataType)
    {
    case MX_DATATYPE_VIDEO_SEQUENCE_HEADER:
        {
            _RTP_Send_Video_Sequence(0);
        }
        break;
	case MX_DATATYPE_VIDEO:
        {
            if (prRTPALMgr->rVideoConfig.eEncoderType ==  VIDEO_ENCODER_MPEG4)
            {
                _RTP_Send_One_MPEG4_Video();
            }
            else if(prRTPALMgr->rVideoConfig.eEncoderType ==  VIDEO_ENCODER_H264)
            {
                _RTP_Send_One_H264_Video();
            }
        }
        break;
        case MX_DATATYPE_AUDIO:
            {
                Media_Format eAudioFormat = prRTPALMgr->rAudioConfig.eAudioFormat;
                if (MEDIA_FORMAT_AMR_TRANSMIT == eAudioFormat)
                {
                    _RTP_Send_AMR_Audio();
                }
                else if (MEDIA_FORMAT_G711_ALAW == eAudioFormat || MEDIA_FORMAT_G711_ULAW == eAudioFormat)
                {
                    _RTP_Send_PCM_Audio();
                }  			
            }
            break;
    case MX_DATATYPE_ALL:
        {
            if (pParam->fgFlush == KAL_TRUE)
            {
            }
            else
            {
            }
        }
        break;
    default:
        {
        }
        break;
    };

    return eError;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterCreateFile(void)
{
    return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterDeInit(void)
{
    drv_trace0(TRACE_GROUP_9, RTPAL_RTP_DEINIT);
#ifdef __RTP_DUMP__
    FS_Close(g_hVFile);
    g_hVFile = 0;

    FS_Close(g_hAFile);
    g_hAFile = 0;
#endif

    //MuxerAdaptFreeMemory(_rRTPALMgr.pau1H264RTPPayload);
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _RTP_MuxerAdapterClose(void)
{
    drv_trace0(TRACE_GROUP_9, RTPAL_RTP_CLOSE);

    return VIDEO_ERROR_NONE;
}

static const MUXER_ADAPT_API_T _RTPAdapterAPI =
{
    _RTP_MuxerAdapterOpen,
    _RTP_MuxerAdapterInit,
    _RTP_MuxerAdapterGetParam,
    _RTP_MuxerAdapterSetParam,
    _RTP_MuxerAdapterDirectlyGetParam,
    _RTP_MuxerAdapterDirectlySetParam,
    _RTP_MuxerAdapterProcessData,
    _RTP_MuxerAdapterWriteData2File,
    _RTP_MuxerAdapterCreateFile,
    _RTP_MuxerAdapterDeInit,
    _RTP_MuxerAdapterClose
};

MUXER_ADAPT_API_T* RTPMuxerAdapterGetHandle(void)
{
    return (MUXER_ADAPT_API_T* )&_RTPAdapterAPI;
}

#endif  // __VE_SUPPORT_RTP_MUXER_ADAPTER__
#endif  // __VE_VIDEO_ARCHI_V2__

//#ifdef __VE_DCM_WITH_COMPRESSION__
//#pragma arm section code, rodata
//#endif
