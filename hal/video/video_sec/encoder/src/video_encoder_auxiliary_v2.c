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
 *   video_encoder_auxiliary_v2.c
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
 *
 *
 ****************************************************************************/
#include "drv_features_video.h"
#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"
#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif
#if defined (__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_SUPPORT_ENCODER__)

#include "drv_comm.h"
#include "vcodec_v2_trc.h"
#include "kal_general_types.h"
#include "video_types_v2.h"
#include "video_encoder_component_v2.h"
#include "yuv_encoder_component_v2.h"
#include "video_encoder_common_adapter_v2.h"
#include "video_codec_custom_setting_v2.h"
#include "video_codec_mem_v2.h"
#include "video_muxer_if_v2.h"
#include "video_memory_usage_v2.h"

#if defined(__VE_MPEG4_ENC_HW_SUPPORT__)
    #include "mpeg4_hw_encoder_component_v2.h"
#endif
#if defined(__VE_MJPEG_ENC_SUPPORT__)
    #include "mjpeg_encoder_component_v2.h"
#endif

extern void VideoEncoderSetParam2Adapt(VIDEO_ENCODER_PARAM_TYPE_T eParamType, void * pu1Param);

kal_bool VideoEncoderSetCodecNScenario(VIDEO_ENCODER_TYPE_T eType, VIDEO_ENCODER_MGR_T* prMgr)
{
    VIDEO_ENCODER_CODEC_T eCodecType;
    kal_bool fgShortHeader = KAL_FALSE;

    switch (eType)
    {
#if defined(__VE_MPEG4_ENC_SW_SUPPORT__)
    case VIDEO_ENCODER_MPEG4:
        prMgr->eCodec = CODEC_MPEG4;
        eCodecType = ENCODER_CODEC_TYPE_MPEG4;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetVideoEncoderAdapterHandle(VADP_CODEC_MPEG4, VADP_RECORDER);
        break;

    case VIDEO_ENCODER_H263:
        prMgr->eCodec = CODEC_H263;
        eCodecType = ENCODER_CODEC_TYPE_H263;
        fgShortHeader = KAL_TRUE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetVideoEncoderAdapterHandle(VADP_CODEC_H263, VADP_RECORDER);
        break;

    #if defined(__VE_VIDEO_VT_SUPPORT__)
    case VIDEO_ENCODER_MPEG4_VT:
        prMgr->eCodec = CODEC_MPEG4;
        eCodecType = ENCODER_CODEC_TYPE_MPEG4;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_VT;
        prMgr->prCodecAPI = GetVideoEncoderAdapterHandle(VADP_CODEC_MPEG4, VADP_VIDEOCALL);
        break;

    case VIDEO_ENCODER_H263_VT:
        prMgr->eCodec = CODEC_H263;
        eCodecType = ENCODER_CODEC_TYPE_H263;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_VT;
        prMgr->prCodecAPI = GetVideoEncoderAdapterHandle(VADP_CODEC_H263, VADP_VIDEOCALL);
        break;
    #endif // __VE_VIDEO_VT_SUPPORT__
#endif //__VE_MPEG4_ENC_SW_SUPPORT__

#if defined(__VE_MPEG4_ENC_HW_SUPPORT__)
    case VIDEO_ENCODER_MPEG4:
        prMgr->eCodec = CODEC_MPEG4;
        eCodecType = ENCODER_CODEC_TYPE_MPEG4;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_ENCODER);
        break;

    case VIDEO_ENCODER_H263:
        prMgr->eCodec = CODEC_H263;
        eCodecType = ENCODER_CODEC_TYPE_H263;
        fgShortHeader = KAL_TRUE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_ENCODER);
        break;

    #if defined(__VE_VIDEO_VT_SUPPORT__)
    case VIDEO_ENCODER_MPEG4_VT:
        prMgr->eCodec = CODEC_MPEG4;
        eCodecType = ENCODER_CODEC_TYPE_MPEG4;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_VT;
        prMgr->prCodecAPI = GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_VT);
        break;

    case VIDEO_ENCODER_H263_VT:
        prMgr->eCodec = CODEC_H263;
        eCodecType = ENCODER_CODEC_TYPE_H263;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_VT;
        prMgr->prCodecAPI = GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_VT);
        break;
    #endif //__VE_VIDEO_VT_SUPPORT__
#endif //__VE_MPEG4_ENC_HW_SUPPORT__

#if defined(__VE_MJPEG_ENC_SUPPORT__)
    case VIDEO_ENCODER_MJPEG:
        prMgr->eCodec = CODEC_MJPEG;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetMJPEGEncoderHandler(MJPEG_SCENARIO_RECORDER);
        break;
#endif //__VE_MJPEG_ENC_SUPPORT__

#if defined(__VE_MJPEG_ENC_BYPASS__)
    case VIDEO_ENCODER_MJPEG_DIRECT_COUPLE:
        prMgr->eCodec = CODEC_MJPG_BYPASS;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_BYPASS;
        prMgr->prCodecAPI = NULL;
        break;
#endif

#if defined(__VE_SUPPORT_YUV_RECORDING__)
    case VIDEO_ENCODER_RECORD_YUV:
        prMgr->eCodec = CODEC_YUV;
        eCodecType = ENCODER_CODEC_TYPE_NONE;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        // eEncoderScenario = VIDEO_ENCODER_SCENARIO_YUV_RECORDER;
        prMgr->prCodecAPI = GetYUVEncoderHandler();
        break;
#endif //__VE_SUPPORT_YUV_RECORDING__

#if defined(__VE_POSTPONE_CODEC_SETTING__)
    case VIDEO_ENCODER_UNKNOWN_VT:
        prMgr->eCodec = CODEC_NONE;
        eCodecType = ENCODER_CODEC_TYPE_NONE;
        fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_VT;
        prMgr->prCodecAPI = NULL;
        break;
#endif

#if defined(__VE_H264_ENC_SW_SUPPORT__)
    case VIDEO_ENCODER_H264:
        prMgr->eCodec = CODEC_H264;
        eCodecType = ENCODER_CODEC_TYPE_H264;
        //fgShortHeader = KAL_FALSE;
        prMgr->eEncoderScenario = VIDEO_ENCODER_SCENARIO_ENCODER;
        prMgr->prCodecAPI = GetVideoEncoderAdapterHandle(VADP_CODEC_H264, VADP_RECORDER);
        break;
#endif //__VE_H264_ENC_SW_SUPPORT__

    default:
        return KAL_FALSE;
    }

    VideoEncoderSetParam2Adapt(VENC_PARAM_CODEC_TYPE, (void*)&eCodecType);

#if defined(__VE_MPEG4_ENC_HW_SUPPORT__) || defined(__VE_MPEG4_ENC_SW_SUPPORT__)
    VideoEncoderSetParam2Adapt(VENC_PARAM_SHORT_HEADER, (void*)&fgShortHeader);
#endif

    return KAL_TRUE;
}

void VideoEncodeCheckStackTCM(void)
{
    #if defined(MT6225)||defined(MT6235)||defined(MT6235B)||defined(MT6236)||defined(MT6236B)||defined(MT6253)||defined(MT6253T)
        drv_trace0(TRACE_GROUP_10, VCODEC_STACK_NO_TCM);
        ASSERT(0);
    #endif
}


kal_uint32 GetVideoEncoderExtMemSize(
    VIDEO_ENCODER_TYPE_T eType,
    kal_uint32 u4EncWidth,
    kal_uint32 u4EncHeight
)
{
    VIDEO_ENC_MEMORY_T rMemory;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T rCustomSettings;
    kal_uint32  u4MemoryRequired = 0;

    kal_mem_set((void*)(&rMemory), 0, sizeof(rMemory));
    rMemory.u4Width     =   u4EncWidth;
    rMemory.u4Height    =   u4EncHeight;

    VideoEncoderGetSetting(&rCustomSettings, eType);

#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_MJPEG_DIRECT_COUPLE == eType)
    {
        // should be retrieved from custom setting
        // fix it later
        u4MemoryRequired = rCustomSettings.u4DirectCoupleTotalSize;
        u4MemoryRequired += GetMuxerMemorySize(MUXER_CONTAINER_AVI, MUXER_SCENARIO_RECORD);
    }
    else
#endif
    {
        u4MemoryRequired = rCustomSettings.u4TotalSize;
        u4MemoryRequired -= VENC_YUV_BUFFER_SIZE_CAL(rCustomSettings.u4MaxWidth, rCustomSettings.u4MaxHeight, rCustomSettings.u4FrmNum);
        u4MemoryRequired += VENC_YUV_BUFFER_SIZE_CAL(u4EncWidth, u4EncHeight, rCustomSettings.u4FrmNum);

        if (VIDEO_ENCODER_MJPEG == eType)
        {
            u4MemoryRequired += GetMuxerMemorySize(MUXER_CONTAINER_AVI, MUXER_SCENARIO_RECORD);
        }
        else
        {
            u4MemoryRequired += GetMuxerMemorySize(MUXER_CONTAINER_MP4, MUXER_SCENARIO_RECORD);
        }
    }

    u4MemoryRequired += ADDITIONAL_OVERHEAD;

    return u4MemoryRequired;
}
#endif /*__VE_SUPPORT_ENCODER__*/
#endif /* __VE_VIDEO_ARCHI_V2__*/

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

