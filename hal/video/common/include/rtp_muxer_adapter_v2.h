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
 *   rtp_muxer_adapter_v2.h
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
 ****************************************************************************/
#include "drv_features_video.h"
	 
#ifndef __RTP_MUXER_ADAPTER_V2_H__
#define __RTP_MUXER_ADAPTER_V2_H__

#include "video_muxer_if_v2.h"
#include "video_buffer_management_v2.h"

#define MAX_SEQ_HEADER_SIZE (128)
#define RTP_H264_PAYLOAD_SIZE (1024 * 2)
#define RTP_AMR_PAYLOAD_SIZE (256)

#define RTP_VIDEO (0)
#define RTP_AUDIO (1)
#define RTP_MAX	   (2)

typedef struct
{
    kal_uint8*  pu1Addr;
    kal_uint32  u4Size;
    kal_bool    fgValid;
} RTP_BUFFER_T;

typedef struct
{
	kal_uint64 		u8Timestamp;
	RTP_BUFFER_T 	arRTPbuffer[MAX_BUFFER_PARTITION];
	kal_bool   		fgUsed;
}RTP_BUFFER_MGR;

typedef struct
{
    MUXER_AUDIO_CONFIG_T  	rAudioConfig;         // audio configuration
    MUXER_VIDEO_CONFIG_T  	rVideoConfig;         // video configuration
	RTP_BUFFER_MGR			rRTPBufMgr[RTP_MAX];
	PFN_CALLBACK        	pfnCallBack;
	kal_uint8 				pau1H264RTPPayload[RTP_H264_PAYLOAD_SIZE];
	kal_uint8 				pau1AMRRTPPayload[RTP_AMR_PAYLOAD_SIZE];
	
	kal_uint64				u8LastSPSTime;
	kal_uint32				u4SeqHeaderSize;
	kal_uint8				au1SeqHeader[MAX_SEQ_HEADER_SIZE];
	kal_uint8				strSeqHeader[MAX_SEQ_HEADER_SIZE];
	kal_uint32				u4AudioLeftOver;
	kal_uint32				u4AccumulatedAudioSize;
	kal_int8 				vid_rtp_handle;
	kal_int8 				aud_rtp_handle;
} RTP_MUXER_ADAPTER_STATE_T;

#endif
