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
 *   mjpeg_decoder_component_v2.h
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
 *
 * removed!
 ****************************************************************************/
#ifndef MJPEG_DECODER_COMPONENT_V2_H
#define MJPEG_DECODER_COMPONENT_V2_H

#ifdef __VIDEO_ARCHI_V2__
#ifdef __MJPEG_DEC_SW_SUPPORT__

#include "video_codec_if_v2.h"
#include "video_types_v2.h"
#include "jpeg_decode_api.h"
#include "app_ltlcom.h"

#define EVENT_MJPEG_DEC_COMPLETE       ((kal_uint32)0x00000001)
#define EVENT_MJPEG_DEC_RESUME         ((kal_uint32)0x00000002)

typedef struct
{
    kal_bool fgIsCodecInit;
    kal_bool fgEOF;
    kal_bool fgBsBufferCacheable;
    kal_bool fgBsSrcCacheable;
    kal_bool fgFrmBufferCacheable;
    kal_bool fgFrmBufferSwitch;
    kal_bool fgErrorDecoding;
    kal_uint16 u2FrameWidth;
    kal_uint16 u2FrameHeight;
    kal_uint16 u2RealFrameWidth;
    kal_uint16 u2RealFrameHeight;
    JPEG_DECODER_HANDLE rMJPEGHandle;
    kal_uint32 u4SelectedWidthFactor;
    kal_uint32 u4SelectedHeightFactor;
    kal_uint32 u4BufferSize;
    kal_uint32 u4IntMemAddr;
    kal_uint32 u4IntMemSize;
    kal_uint32 u4ExtMemAddr;
    kal_uint32 u4ExtMemSize;  
    kal_uint32 u4OutAddr;
    kal_uint8 *pu1Cache;
    kal_uint8 *pu1ReadBuffer;
    kal_eventgrpid EventId;
    kal_uint64 u8FrameTime;
}MJPEG_DECODER_CTRL_T;


VIDEO_DECODER_CODEC_API_T* GetMJPEGDecoderHandler(VIDEO_DECODER_SCENARIO_T eType);

#endif /* __MJPEG_DEC_SW_SUPPORT__ */
#endif /* __VIDEO_ARCHI_V2__ */
#endif /* MJPEG_DECODER_COMPONENT_V2_H */ 

