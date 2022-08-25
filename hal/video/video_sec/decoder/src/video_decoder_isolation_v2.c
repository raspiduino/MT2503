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
 *   video_decoder_isolation_v2.c
 *
 * Project:
 * --------
 *  MTK
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
 *
 *
 *
 ****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "drv_comm.h"
#include "video_types_v2.h"
#include "video_comm_v2.h"
#include "vcodec_v2_trc.h"
#include "video_codec_type_v2.h"
#include "video_decoder_component_internal_v2.h"

#include "video_decoder_common_adapter_v2.h"
#include "video_codec_custom_setting_v2.h"
#include "mjpeg_decoder_component_v2.h"

#ifdef __VE_MPEG4_DEC_HW_SUPPORT__
#include "mpeg4_hw_decoder_component_v2.h"
#endif
#ifdef __VE_H264_DEC_HW_SUPPORT__
#include "h264_hw_decoder_component_v2.h"
#endif

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

kal_uint32 _VideoDecoderGetYUVBufferSize(VIDEO_DECODER_MGR_T *prDecoderMGR)
{
    kal_uint32 u4BufferSize = 0;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &prDecoderMGR->rVDMgrDNZ;
    VIDEO_DECODER_CUSTOM_SETTINGS_T*pVDMgrCustomSetting = &prVDMgrDNZ->rCustomSettings;

    switch(prVDMgrDNZ->eScenario)
    {
        case VIDEO_SCENARIO_PLAYER:
        case VIDEO_SCENARIO_KMV:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4H264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4MPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4RV9TotalBufferSize;  //RV9_TOTAL_BUFFER_SIZE;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4MJPEGTotalBufferSize;  //MJPEG_TOTAL_BUFFER_SIZE;
                    break;
#endif

#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4VP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

#ifdef __VE_VIDEO_VT_SUPPORT__
        case VIDEO_SCENARIO_VT:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4MPEG4VTTotalBufferSize;
                    break;
#endif
                default:
                    ASSERT(0);
                    break;
            }
            break;
        }
#endif

        case VIDEO_SCENARIO_QVGA:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAH264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGARV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMJPEGTotalBufferSize;
                    break;
#endif

#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAVP8TotalBufferSize;
                    break;
#endif
                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        // preview
        case VIDEO_SCENARIO_PREVIEW:
	case VIDEO_SCENARIO_PREVIEW_KMV:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4PreviewH264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4PreviewMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4PreviewRV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4PreviewMJPEGTotalBufferSize;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4PreviewVP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_QCIF:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4QCIFH264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4QCIFMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4QCIFRV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4QCIFMJPEGTotalBufferSize;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4QCIFVP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_VGA:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4VGAH264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4VGAMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4VGARV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4VGAMJPEGTotalBufferSize;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4VGAVP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_CIF:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                u4BufferSize = pVDMgrCustomSetting->u4CIFH264TotalBufferSize;
                break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4CIFMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4CIFRV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4CIFMJPEGTotalBufferSize;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4CIFVP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_UPTOCIF:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                u4BufferSize = pVDMgrCustomSetting->u4UPTOCIFH264TotalBufferSize;
                break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOCIFMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOCIFRV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOCIFMJPEGTotalBufferSize;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOCIFVP8TotalBufferSize;
                    break;
#endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_UPTOQVGA:
        {
            switch(prVDMgrDNZ->eCodec)
            {
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOQVGAH264TotalBufferSize;
                    break;
#endif
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOQVGAMPEG4TotalBufferSize;
                    break;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOQVGARV9TotalBufferSize;
                    break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOQVGAMJPEGTotalBufferSize;
                    break;
#endif

#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4UPTOQVGAVP8TotalBufferSize;
                    break;
#endif
                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        case VIDEO_SCENARIO_QVGA_MPEG4SP:
        {
            switch(prVDMgrDNZ->eCodec)
            {
                #if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                case CODEC_H264:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4SPH264TotalBufferSize;
                    break;
                #endif

                #if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
                case CODEC_MPEG4:
                case CODEC_H263:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4SPMPEG4TotalBufferSize;
                    break;
                #endif

                #ifdef __VE_RV_DEC_SW_SUPPORT__
                case CODEC_RV9_10:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4SPRV9TotalBufferSize;
                    break;
                #endif

                #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
                case CODEC_MJPEG:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4SPMJPEGTotalBufferSize;
                    break;
                #endif

                #ifdef __VE_VP8_DEC_SW_SUPPORT__
                case CODEC_VP8:
                    u4BufferSize = pVDMgrCustomSetting->u4QVGAMPEG4SPVP8TotalBufferSize;
                    break;
                #endif

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }

        default:
            ASSERT(0);
            break;
    }

    return u4BufferSize;
}

kal_bool _VideoDecoderScenarioTypeChecking(VIDEO_DECODER_MGR_T *prDecoderMGR, VIDEO_DECODER_CODEC_T eCodec, VIDEO_DECODER_SCENARIO_T eScenario)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &prDecoderMGR->rVDMgrDNZ;
    prVDMgrDNZ->eScenario = eScenario;

    switch (eCodec)
    {
#ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        case VIDEO_CODEC_MPEG4:
        {
            prVDMgrDNZ->eCodec = CODEC_MPEG4;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
            case VIDEO_SCENARIO_KMV:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_PLAYER);
                break;

            #ifdef __VE_VIDEO_VT_SUPPORT__
            case VIDEO_SCENARIO_VT:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_VIDEOCALL);
                break;
            #endif

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_QVGA);
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_QVGA_MPEG4SP);
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
	    case VIDEO_SCENARIO_PREVIEW_KMV:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_PREVIEW);
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_QCIF);
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_VGA);
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_CIF);
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_UPTOCIF);
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_MPEG4, VADP_UPTOQVGA);
                break;


            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;

        case VIDEO_CODEC_H263:
        {
            prVDMgrDNZ->eCodec = CODEC_H263;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
            case VIDEO_SCENARIO_KMV:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263,VADP_PLAYER);
                break;

            #ifdef __VE_VIDEO_VT_SUPPORT__
            case VIDEO_SCENARIO_VT:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_VIDEOCALL);
                break;
            #endif

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_QVGA);
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_QVGA_MPEG4SP);
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_PREVIEW);
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_QCIF);
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_VGA);
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_CIF);
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_UPTOCIF);
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H263, VADP_UPTOQVGA);
                break;

            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;
#endif

#ifdef __VE_MPEG4_DEC_HW_SUPPORT__
        case VIDEO_CODEC_MPEG4:
        {
            prVDMgrDNZ->eCodec = CODEC_MPEG4;

            prVDMgrDNZ->prCodecAPI = GetMPEG4HwDecoderHandler(eScenario);
        }
        break;

        case VIDEO_CODEC_H263:
        {
            prVDMgrDNZ->eCodec = CODEC_H263;

            prVDMgrDNZ->prCodecAPI = GetMPEG4HwDecoderHandler(eScenario);
        }
        break;
#endif

#ifdef __VE_H264_DEC_SW_SUPPORT__
        case VIDEO_CODEC_H264:
        {
            prVDMgrDNZ->eCodec = CODEC_H264;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
            case VIDEO_SCENARIO_KMV:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_PLAYER);
                break;

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_QVGA);
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_QVGA_MPEG4SP);
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
	    case VIDEO_SCENARIO_PREVIEW_KMV:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_PREVIEW);
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_QCIF);
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_VGA);
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_CIF);
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_UPTOCIF);
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_H264, VADP_UPTOQVGA);
                break;

            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;
#endif

#ifdef __VE_H264_DEC_HW_SUPPORT__
        case VIDEO_CODEC_H264:
        {
            prVDMgrDNZ->eCodec = CODEC_H264;

            prVDMgrDNZ->prCodecAPI = GetH264HwDecoderHandler(eScenario);
        }
        break;
#endif

#ifdef __VE_RV_DEC_SW_SUPPORT__
        case VIDEO_CODEC_RV9_10:
        {
            prVDMgrDNZ->eCodec = CODEC_RV9_10;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_PLAYER);
                break;

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_QVGA);
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_QVGA_MPEG4SP);
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_PREVIEW);
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_QCIF);
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_VGA);
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_CIF);
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_UPTOCIF);
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_RV9_10, VADP_UPTOQVGA);
                break;

            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        case VIDEO_CODEC_MJPEG:
        {
            prVDMgrDNZ->eCodec = CODEC_MJPEG;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetMJPEGDecoderHandler(eScenario);
                if (prVDMgrDNZ->prCodecAPI == NULL)
                {
                    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                    return KAL_FALSE;
                }
                break;


            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;
#endif

#ifdef __VE_VP8_DEC_SW_SUPPORT__
        case VIDEO_CODEC_VP8:
        {
            prVDMgrDNZ->eCodec = CODEC_VP8;

            switch (eScenario)
            {
            case VIDEO_SCENARIO_PLAYER:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_PLAYER);
                break;

            case VIDEO_SCENARIO_QVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_QVGA);
                break;

            case VIDEO_SCENARIO_QVGA_MPEG4SP:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_QVGA_MPEG4SP);
                break;

            // preview
            case VIDEO_SCENARIO_PREVIEW:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_PREVIEW);
                break;

            case VIDEO_SCENARIO_QCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_QCIF);
                break;

            case VIDEO_SCENARIO_VGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_VGA);
                break;

            case VIDEO_SCENARIO_CIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_CIF);
                break;

            case VIDEO_SCENARIO_UPTOCIF:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_UPTOCIF);
                break;

            case VIDEO_SCENARIO_UPTOQVGA:
                prVDMgrDNZ->prCodecAPI = GetVideoDecoderAdapterHandle(VADP_CODEC_VP8, VADP_UPTOQVGA);
                break;

            default:
                drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
                return KAL_FALSE;
            }
        }
        break;
#endif



        default:
            drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, eCodec, eScenario, VIDEO_ERROR_UNDEFINED, 0);
            return KAL_FALSE;
    }

    if (NULL == prVDMgrDNZ->prCodecAPI)
    {
        drv_trace2(TRACE_GROUP_10, VDEC_FAIL_GET_HDLR, eCodec, eScenario);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

void _VideoDecodeCheckStackTCM(void)
{
#if defined(MT6225)||defined(MT6235)||defined(MT6235B)||defined(MT6236)||defined(MT6236B)||defined(MT6253)||defined(MT6253T)
    drv_trace0(TRACE_GROUP_10, VCODEC_STACK_NO_TCM);
    ASSERT(0);
#endif
}

kal_uint32 _VideoDecoderGetAvialableCodec(void)
{
    kal_uint32 u4Return = (kal_uint32)(CODEC_H264)
                        + (kal_uint32)(CODEC_MPEG4)
                        + (kal_uint32)(CODEC_H263)
                        + (kal_uint32)(CODEC_RV9_10);
    return u4Return;
}

void _VideoDecoderGetCustomSetting(VIDEO_DECODER_MGR_T *prDecoderMGR, void* pVoid)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &prDecoderMGR->rVDMgrDNZ;

#if defined(__VE_MPEG4_DEC_HW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__) || defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    VIDEO_DECODER_CUSTOM_SETTINGS_T*pVDMgrCustomSetting = &prVDMgrDNZ->rCustomSettings;
#endif

    switch(prVDMgrDNZ->eCodec)
    {
#if (defined(__VE_MPEG4_DEC_HW_SUPPORT__))
        case CODEC_MPEG4:
        case CODEC_H263:
        {
            MPEG4_DECODER_CUSTOM_SETTING_T* pCustomSetting = (MPEG4_DECODER_CUSTOM_SETTING_T*)(pVoid);

            switch(prVDMgrDNZ->eScenario)
            {
                case VIDEO_SCENARIO_PLAYER:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4MPEG4MaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4MPEG4MaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4MPEG4MaxHeight * pVDMgrCustomSetting->u4MPEG4MaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4MPEG4SupportResolution;
                    break;
                }

#ifdef __VE_VIDEO_VT_SUPPORT__
                case VIDEO_SCENARIO_VT:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4MPEG4VTMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4MPEG4VTMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4MPEG4VTMaxHeight * pVDMgrCustomSetting->u4MPEG4VTMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4MPEG4VTSupportResolution;
                    break;
                }
#endif

                case VIDEO_SCENARIO_QVGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QVGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QVGAMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QVGAMaxHeight * pVDMgrCustomSetting->u4QVGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QVGASupportResolution;
                    break;
                }

                // preview
                case VIDEO_SCENARIO_PREVIEW:
		case VIDEO_SCENARIO_PREVIEW_KMV:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4MPEG4MaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4MPEG4MaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4MPEG4MaxHeight * pVDMgrCustomSetting->u4MPEG4MaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4MPEG4SupportResolution;
                    break;
                }

                // QCIF
                case VIDEO_SCENARIO_QCIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QCIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QCIFMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QCIFMaxHeight * pVDMgrCustomSetting->u4QCIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QCIFSupportResolution;
                    break;
                }

                // VGA
                case VIDEO_SCENARIO_VGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4VGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4VGAMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4VGAMaxHeight * pVDMgrCustomSetting->u4VGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // CIF
                case VIDEO_SCENARIO_CIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4CIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4CIFMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4CIFMaxHeight * pVDMgrCustomSetting->u4CIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                // UPTOQVGA
                case VIDEO_SCENARIO_UPTOQVGA:
                {
                    pCustomSetting->u4MaxWidth = 320;
                    pCustomSetting->u4MaxHeight = 240;
                    pCustomSetting->u8MaxResolution= 320*240;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // UPTOCIF
                case VIDEO_SCENARIO_UPTOCIF:
                {
                    pCustomSetting->u4MaxWidth = 352;
                    pCustomSetting->u4MaxHeight = 288;
                    pCustomSetting->u8MaxResolution= 352*288;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                case VIDEO_SCENARIO_QVGA_MPEG4SP:
                    pCustomSetting->u4MaxWidth = 320;
                    pCustomSetting->u4MaxHeight = 240;
                    pCustomSetting->u8MaxResolution= 320*240;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }
#endif

#if (defined(__VE_H264_DEC_HW_SUPPORT__))
        case CODEC_H264:
        {
            H264_DECODER_CUSTOM_SETTING_T* pCustomSetting = (H264_DECODER_CUSTOM_SETTING_T*)(pVoid);
            switch(prVDMgrDNZ->eScenario)
            {
                case VIDEO_SCENARIO_PLAYER:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4H264MaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4H264MaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4H264DPBSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4H264MaxHeight * pVDMgrCustomSetting->u4H264MaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4H264SupportResolution;
                    break;
                }

                case VIDEO_SCENARIO_QVGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QVGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QVGAMaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4QVGAH264DPBSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QVGAMaxHeight * pVDMgrCustomSetting->u4QVGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QVGASupportResolution;
                    break;
                }

                // preview
                case VIDEO_SCENARIO_PREVIEW:
		case VIDEO_SCENARIO_PREVIEW_KMV:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4H264MaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4H264MaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4PreviewH264TotalBufferSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4H264MaxHeight * pVDMgrCustomSetting->u4H264MaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4H264SupportResolution;
                    break;
                }

                // QCIF
                case VIDEO_SCENARIO_QCIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QCIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QCIFMaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4QCIFH264DPBSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QCIFMaxHeight * pVDMgrCustomSetting->u4QCIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QCIFSupportResolution;
                    break;
                }

                // VGA
                case VIDEO_SCENARIO_VGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4VGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4VGAMaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4VGAH264TotalBufferSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4VGAMaxHeight * pVDMgrCustomSetting->u4VGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // CIF
                case VIDEO_SCENARIO_CIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4CIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4CIFMaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4CIFH264TotalBufferSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4CIFMaxHeight * pVDMgrCustomSetting->u4CIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                // UPTOQVGA
                case VIDEO_SCENARIO_UPTOQVGA:
                {
                    pCustomSetting->u4MaxWidth = 320;
                    pCustomSetting->u4MaxHeight = 240;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4UPTOQVGAH264DPBSize;
                    pCustomSetting->u8MaxResolution= 320*240;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // UPTOCIF
                case VIDEO_SCENARIO_UPTOCIF:
                {
                    pCustomSetting->u4MaxWidth = 352;
                    pCustomSetting->u4MaxHeight = 288;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4UPTOCIFH264DPBSize;
                    pCustomSetting->u8MaxResolution= 352*288;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                case VIDEO_SCENARIO_QVGA_MPEG4SP:
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QVGAMPEG4SPMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QVGAMPEG4SPMaxHeight;
                    pCustomSetting->u4DPBSize = pVDMgrCustomSetting->u4QVGAMPEG4SPH264DPBSize;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QVGAMPEG4SPMaxWidth * pVDMgrCustomSetting->u4QVGAMPEG4SPMaxHeight;
                    break;

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        case CODEC_MJPEG:
        {
            MJPEG_DECODER_CUSTOM_SETTING_T* pCustomSetting = (MJPEG_DECODER_CUSTOM_SETTING_T*)(pVoid);

            switch(prVDMgrDNZ->eScenario)
            {
                case VIDEO_SCENARIO_PLAYER:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4MJPEGMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4MJPEGMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4MJPEGMaxHeight* pVDMgrCustomSetting->u4MJPEGMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4MJPEGSupportResolution;
                    break;
                }

                case VIDEO_SCENARIO_QVGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QVGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QVGAMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QVGAMaxHeight* pVDMgrCustomSetting->u4QVGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QVGASupportResolution;
                    break;
                }

                // preview
                case VIDEO_SCENARIO_PREVIEW:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4MJPEGMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4MJPEGMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4MJPEGMaxHeight* pVDMgrCustomSetting->u4MJPEGMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4MJPEGSupportResolution;
                    break;
                }

                // QCIF
                case VIDEO_SCENARIO_QCIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QCIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QCIFMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QCIFMaxHeight * pVDMgrCustomSetting->u4QCIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4QCIFSupportResolution;
                    break;
                }

                // VGA
                case VIDEO_SCENARIO_VGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4VGAMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4VGAMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4VGAMaxHeight * pVDMgrCustomSetting->u4VGAMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // CIF
                case VIDEO_SCENARIO_CIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4CIFMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4CIFMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4CIFMaxHeight * pVDMgrCustomSetting->u4CIFMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                // UPTOQVGA
                case VIDEO_SCENARIO_UPTOQVGA:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4UPTOQVGAMJPEGMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4UPTOQVGAMJPEGMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4UPTOQVGAMJPEGMaxHeight * pVDMgrCustomSetting->u4UPTOQVGAMJPEGMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4VGASupportResolution;
                    break;
                }

                // UPTOCIF
                case VIDEO_SCENARIO_UPTOCIF:
                {
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4UPTOCIFMJPEGMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4UPTOCIFMJPEGMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4UPTOCIFMJPEGMaxHeight * pVDMgrCustomSetting->u4UPTOCIFMJPEGMaxWidth;
                    //pCustomSetting->u4MaxResolutionDefine = pVDMgrCustomSetting->u4CIFSupportResolution;
                    break;
                }

                case VIDEO_SCENARIO_QVGA_MPEG4SP:
                    pCustomSetting->u4MaxWidth = pVDMgrCustomSetting->u4QVGAMPEG4SPMaxWidth;
                    pCustomSetting->u4MaxHeight = pVDMgrCustomSetting->u4QVGAMPEG4SPMaxHeight;
                    pCustomSetting->u8MaxResolution= pVDMgrCustomSetting->u4QVGAMPEG4SPMaxWidth * pVDMgrCustomSetting->u4QVGAMPEG4SPMaxHeight;
                    break;

                default:
                    ASSERT(0);
                    break;
            }
            break;
        }
#endif
        default:
            ASSERT(0);
        break;
    }
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

 #endif /* __VE_VIDEO_ARCHI_V2__ */

