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
 *   mpeg4_hw_encoder_component_v2.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file declares the adaptor of mpeg4 hw encoder
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#ifndef MPEG4_HW_ENCODER_COMPONENT_V2_H
#define MPEG4_HW_ENCODER_COMPONENT_V2_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_ENC_HW_SUPPORT__

#include "video_types_v2.h"
#include "video_codec_if_v2.h"

#include "kal_general_types.h"
#include "mpeg4_hw_encore_v2.h"

typedef struct
{
    VIDEO_ENCODER_QUALITY_T  eQuality;
    VIDEO_ENCODER_SCENARIO_T eScenario;
    VIDEO_ENCODER_CODEC_T    eCodecType;
    MPEG4_ENCORE_MEM_INFO rMPEG4Mem;
    kal_uint32 u4MaxPktSize;
    kal_uint32 u4FrameRate;
    kal_uint32 u4GenHeaderFrameRate;
    kal_uint64 u8TimeStamp;
    kal_uint8* pu1YUV;
    kal_uint8* pu1Buffer;
    void (*pfYUVDone) (kal_uint8 *);
    void (*pfEncPause) (kal_uint8 *);
    void (*pfBITSDone) (void);
}MPEG4_HW_ENCODER_CTRL_T;

VIDEO_ENCODER_CODEC_API_T* GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_T eScenario);
kal_bool    MPEG4HWGenStreamHeader(kal_uint8* pu1Buffer, kal_uint32 u4BufferSize, kal_uint32 u4TimeIncrResolution, kal_uint32* pu4EncodedSize);

void MPEG4EncCallbackYUVDone(kal_uint8* pu1Ptr);
void MPEG4EncCallbackEncPause(kal_uint8* pu1Ptr);
void MPEG4EncCallbackBITSDone(void);

#endif /* __VE_MPEG4_ENC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* MPEG4_HW_ENCODER_COMPONENT_V2_H */
