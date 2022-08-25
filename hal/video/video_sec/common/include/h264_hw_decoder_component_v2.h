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
 *   h264_hw_decoder_component_v2.h
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
 * removed!
 *
 * removed!
 ****************************************************************************/
#ifndef H264_HW_DECODER_COMPONENT_V2_H
#define H264_HW_DECODER_COMPONENT_V2_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_H264_DEC_HW_SUPPORT__

#include "video_codec_if_v2.h"
#include "kal_general_types.h"

#define H264_HW_MAX_OUT_IDX      32

typedef struct
{
    kal_bool fgIsCodecInit;
    kal_bool fgEOF;
    kal_bool fgBsBufferCacheable;
    kal_bool fgFrmBufferCacheable;
    kal_bool fgFrmBufferSwitch;
    kal_bool fgCropping;
    kal_bool fgExtMemReplaceIntMem;
    kal_bool fgExtMemReplaceIntMemSwitch;
    kal_uint16 u2GetPicInOneTrigger;
    kal_uint16 u2FrameWidth;
    kal_uint16 u2FrameHeight;
    kal_uint32 u4BufferSize;
    kal_uint32 u4IntMemAlignSize;
    kal_uint32 u4IntMemOriginalAddr;
    kal_uint32 u4IntMemAddr;
    kal_uint32 u4ExtMemAddr;
    kal_uint32 u4BitRate;
    kal_uint32 u4FrameRate;
    kal_uint32 u4OutWIdx;
    kal_uint32 u4OutRIdx;
    kal_uint32 au4OutputList[H264_HW_MAX_OUT_IDX];
    kal_uint32 u4PicCnt;
    kal_uint32 u4DummyYUV;
}H264_HW_DECODER_CTRL_T;

/* return bitstream buffer structure */
typedef struct
{
    kal_uint8 *pBsAddr;            /* pointer to bitstream buffer */
    kal_uint32 BsTotalLen;         /* total length of bistream buffer */
    //kal_uint32 NaluCnt;             /* count of nalu of current frame decoding */
    //kal_uint32 totalNalu;          /* total number of nalu in current frame */
    kal_bool fgUsed;
} H264_HW_DEC_RETURN_BS_T;


VIDEO_DECODER_CODEC_API_T* GetH264HwDecoderHandler(VIDEO_DECODER_SCENARIO_T eType);

#endif /* __VE_H264_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* H264_HW_DECODER_COMPONENT_V2_H */ 

