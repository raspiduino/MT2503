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
 *   video_encoder_common_adapter_v2.h
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
 *
 *
 ****************************************************************************/
#ifndef VIDEO_ENCODER_COMMON_ADAPTER_V2_H
#define VIDEO_ENCODER_COMMON_ADAPTER_V2_H

#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "drv_features_video.h"
#include "video_codec_if_v2.h"
#include "video_codec_type_v2.h"
#include "kal_general_types.h"
#include "vcodec_if.h"
#include "vcodec_enc_demuxer_if.h"

typedef struct
{
    kal_bool fgInit;
    kal_bool fgisVT;
    VCODEC_ENC_API_T  *prEncAPI;
    HANDLE hDrvHandle;
    HANDLE hCodecHandle;
    void *prCustomSetting; 
    kal_uint32 u4GetIntMemSize;
#ifdef __VE_VIDEO_VT_SUPPORT__    
    VCODEC_ENC_PACKET_SET_T   rChassis;
#endif
#if defined(__H264_ENC_SW_SUPPORT__)            
    H264_ENC_CONF_REC rConfigRec;
#endif
    VIDEO_ADAPTOR_CODEC_T eCodecType;
} VIDEO_ENCODER_ADAPTER_CTRL_T;


VIDEO_ENCODER_CODEC_API_T* GetVideoEncoderAdapterHandle(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario);
kal_bool VideoAdapterGenStreamHeader(VIDEO_ADAPTOR_CODEC_T eType, kal_uint8* pu1Buffer, kal_uint32 u4BufferSize, 
                                                kal_uint32 u4TimeIncrResolution, kal_uint32* pu4EncodedSize);


#endif /* __VE_VIDEO_ARCHI_V2__*/
#endif /* VIDEO_ENCODER_COMMON_ADAPTER_V2_H */


