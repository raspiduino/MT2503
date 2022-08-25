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
 *   video_codec_custom_adapter_v2.c
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
 *
 *
 ****************************************************************************/

#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#if defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_SW_SUPPORT__) || \
    defined(__VE_RV_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_ENC_SW_SUPPORT__) || defined(__VE_VP8_DEC_SW_SUPPORT__)

#include "kal_release.h"
#include "video_types_v2.h"
#include "vcodec_if.h"
#include "video_codec_custom_adapter_v2.h"
#include "vcodec_customization.h"

VCODEC_DEC_API_T *GetVideoDecoderAPI(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    switch (eType)
    {
#if defined(__VE_H264_DEC_SW_SUPPORT__)
    case VADP_CODEC_H264:
        return GetH264DecoderAPI();
#endif

#if defined(__VE_MPEG4_DEC_SW_SUPPORT__)
    case VADP_CODEC_MPEG4:
    case VADP_CODEC_H263:
        if (eScenario != VADP_VIDEOCALL)
        {
            return GetMPEG4DecoderAPI();
        }
#ifdef __VE_VIDEO_VT_SUPPORT__
        else
        {
            return GetMPEG4VTDecoderAPI();
        }
#endif
#endif

#if defined(__VE_RV_DEC_SW_SUPPORT__)
    case VADP_CODEC_RV9_10:
        return GetRMDecoderAPI();
#endif

#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    case VADP_CODEC_VP8:
        return GetVP8DecoderAPI();
#endif

    default:
        break;
    }

    return NULL;
}

VCODEC_ENC_API_T *GetVideoEncoderAPI(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    switch (eType)
    {
#if defined(__VE_MPEG4_ENC_SW_SUPPORT__)
        case VADP_CODEC_MPEG4:
        case VADP_CODEC_H263:
            if (eScenario == VADP_RECORDER)
            {
                return GetMPEG4EncoderAPI();
            }
#ifdef __VE_VIDEO_VT_SUPPORT__
            else if (eScenario == VADP_VIDEOCALL)
            {
                return GetMPEG4SWVTEncoderAPI();
            }
#endif
            else
            {
                break;
            }
#endif
#if defined (__VE_H264_ENC_SW_SUPPORT__)
        case VADP_CODEC_H264:
            return GetH264EncoderAPI();
#endif
        default:
            break;
    }

    return NULL;
}

void *GetVideoDecoderCustomSetting(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    switch (eType)
    {
#if defined(__VE_H264_DEC_SW_SUPPORT__)
    case VADP_CODEC_H264:
        if (eScenario == VADP_QVGA)
        {
            return (void *)&H264QVGACustomSetting;
        }
        else if (eScenario == VADP_QVGA_MPEG4SP)
        {
            return (void *)&H264QVGAMPEG4SPCustomSetting;
        }
        else if (eScenario == VADP_CIF)
        {
            return (void *)&H264CIFCustomSetting;
        }
        // MAUI_02955479
        else if(eScenario == VADP_PREVIEW)
        {
            return (void *)&H264PreviewCustomSetting;
        }
        else if (eScenario == VADP_UPTOQVGA)
        {
            return (void *)&H264UPTOQVGACustomSetting;
        }
        else if(eScenario == VADP_UPTOCIF)
        {
            return (void *)&H264UPTOCIFCustomSetting;
        }

        return (void *)&H264CustomSetting;
#endif
#if defined(__VE_MPEG4_DEC_SW_SUPPORT__)
    case VADP_CODEC_MPEG4:
    case VADP_CODEC_H263:
        if (eScenario == VADP_PLAYER || eScenario == VADP_PREVIEW) // MAUI_02955479
        {
            return (void *)&MPEG4CustomSetting;
        }
#ifdef __VE_VIDEO_VT_SUPPORT__
        else if (eScenario == VADP_VIDEOCALL)
        {
            return (void *)&MPEG4VTCustomSetting;
        }
#endif
        else if (eScenario == VADP_QVGA)
        {
            return (void *)&MPEG4QVGACustomSetting;
        }
        else if (eScenario == VADP_QVGA_MPEG4SP)
        {
            return (void *)&MPEG4QVGAMPEG4SPCustomSetting;
        }
        else if (eScenario == VADP_CIF)
        {
            return (void *)&MPEG4CIFCustomSetting;
        }
        else if (eScenario == VADP_UPTOQVGA)
        {
            return (void *)&MPEG4UPTOQVGACustomSetting;
        }
        else if (eScenario == VADP_UPTOCIF)
        {
            return (void *)&MPEG4UPTOCIFCustomSetting;
        }
        break;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
    case VADP_CODEC_RV9_10:
        if (eScenario == VADP_QVGA)
        {
            return (void *)&rmvbQVGACustomSetting;
        }
        else if (eScenario == VADP_QVGA_MPEG4SP)
        {
            return (void *)&rmvbQVGAMPEG4SPCustomSetting;
        }
        else if (eScenario == VADP_CIF)
        {
            return (void *)&rmvbCIFCustomSetting;
        }
        else if (eScenario == VADP_UPTOQVGA)
        {
            return (void *)&rmvbUPTOQVGACustomSetting;
        }
        else if (eScenario == VADP_UPTOCIF)
        {
            return (void *)&rmvbUPTOCIFCustomSetting;
        }
        return (void *)&rmvbCustomSetting;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    case VADP_CODEC_VP8:
        if (eScenario == VADP_QVGA)
        {
            return (void *)&VP8QVGACustomSetting;
        }
        else if (eScenario == VADP_QVGA_MPEG4SP)
        {
            return (void *)&VP8QVGAMPEG4SPCustomSetting;
        }
        else if (eScenario == VADP_CIF)
        {
            return (void *)&VP8CIFCustomSetting;
        }
        else if (eScenario == VADP_UPTOQVGA)
        {
            return (void *)&VP8UPTOQVGACustomSetting;
        }
        else if (eScenario == VADP_UPTOCIF)
        {
            return (void *)&VP8UPTOCIFCustomSetting;
        }
        return (void *)&VP8CustomSetting;
#endif
    default:
        break;
    }

    return NULL;
}

void *GetVideoEncoderCustomSetting(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario)
{
    switch (eType)
    {
#if defined(__VE_MPEG4_ENC_SW_SUPPORT__)
    case VADP_CODEC_MPEG4:
    case VADP_CODEC_H263:
        if (eScenario == VADP_RECORDER)
        {
            return (void *)&MPEG4EncoderCustomSetting;
        }
#ifdef __VE_VIDEO_VT_SUPPORT__
        else if (eScenario == VADP_VIDEOCALL)
        {
            return (void *)&MPEG4VTEncoderCustomSetting;
        }
#endif
        else
        {
            break;
        }
#endif
#if defined (__VE_H264_ENC_SW_SUPPORT__)
    case VADP_CODEC_H264:
        return (void *)&H264EncoderCustomSetting;
#endif
    default:
        break;
    }

    return NULL;
}

#endif
#endif /*__VE_VIDEO_ARCHI_V2__*/

