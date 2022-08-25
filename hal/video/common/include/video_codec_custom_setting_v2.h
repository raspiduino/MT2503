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
 *   video_codec_custom_setting_v2.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *
 *
 ****************************************************************************/
#ifndef VIDEO_CODEC_CUSTOM_SETTING_V2_H
#define VIDEO_CODEC_CUSTOM_SETTING_V2_H

#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#include "kal_general_types.h"
#include "video_types_v2.h"

/****************************************************************************
*   VIDEO_ADAPTOR_CODEC_T
*
*
****************************************************************************/
typedef enum
{
    VADP_CODEC_NONE      = 0,
    VADP_CODEC_H264      = (0x01),
    VADP_CODEC_MPEG4     = (0x01<<1),
    VADP_CODEC_H263      = (0x01<<2),
    VADP_CODEC_RV9_10    = (0x01<<3),
    VADP_CODEC_VP8       = (0x01<<4)
} VIDEO_ADAPTOR_CODEC_T;

/****************************************************************************
*   VIDEO_ADAPTOR_SCENARIO_T
*
*
****************************************************************************/
typedef enum
{
    VADP_SCENARIO_NONE,
    VADP_PLAYER,
    VADP_RECORDER,
    VADP_VIDEOCALL,
    VADP_QVGA,
    VADP_QCIF,
    VADP_VGA,
    VADP_CIF,
    VADP_PREVIEW,
    VADP_UPTOCIF,
    VADP_UPTOQVGA,
    VADP_QVGA_MPEG4SP
} VIDEO_ADAPTOR_SCENARIO_T;

typedef struct
{
    kal_uint32  u4MaxWidth;
    kal_uint32  u4MaxHeight;
    kal_uint32  u4MaxQtyWidth;
    kal_uint32  u4MaxQtyHeight;
    kal_uint32  u4MaxNormalWidth;
    kal_uint32  u4MaxNormalHeight;
}VIDEO_DECODER_RESIZER_SETTINGS_T;

typedef struct
{
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint8   u1MPEG4BufferNum;
    kal_uint32  u4MPEG4SupportResolution;
    kal_uint32  u4MPEG4NormalMaxResolution;
    kal_uint32  u4MPEG4MaxWidth;
    kal_uint32  u4MPEG4MaxHeight;
    kal_uint32  u4MPEG4WorkingMemory;
    kal_uint32  u4MPEG4TotalBufferSize;

    #ifdef __VE_VIDEO_VT_SUPPORT__
    kal_uint8   u1MPEG4VTBufferNum;
    kal_uint32  u4MPEG4VTSupportResolution;
    kal_uint32  u4MPEG4VTNormalMaxResolution;
    kal_uint32  u4MPEG4VTMaxWidth;
    kal_uint32  u4MPEG4VTMaxHeight;
    kal_uint32  u4MPEG4VTWorkingMemory;
    kal_uint32  u4MPEG4VTTotalBufferSize;
    #endif
#endif

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint8   u1H264BufferNum;
    kal_uint32  u4H264SupportResolution;
    kal_uint32  u4H264NormalMaxResolution;
    kal_uint8   u1H264DecoderLevel;
    kal_uint32  u4H264MaxWidth;
    kal_uint32  u4H264MaxHeight;
    kal_uint32  u4H264WorkingMemory;
    kal_uint32  u4H264DPBSize;
    kal_uint32  u4H264TotalBufferSize;
#endif

#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint8   u1RV9BufferNum;
    kal_uint32  u4RV9SupportResolution;
    kal_uint32  u4RV9NormalMaxResolution;
    kal_uint32  u4RV9MaxWidth;
    kal_uint32  u4RV9MaxHeight;
    kal_uint32  u4RV9NormalMaxWidth;
    kal_uint32  u4RV9NormalMaxHeight;
    kal_uint32  u4RV9WorkingMemory;
    kal_uint32  u4RV9TotalBufferSize;
#endif

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint8   u1MJPEGBufferNum;
    kal_uint32  u4MJPEGSupportResolution;
    kal_uint32  u4MJPEGNormalMaxResolution;
    kal_uint32  u4MJPEGMaxWidth;
    kal_uint32  u4MJPEGMaxHeight;
    kal_uint32  u4MJPEGMaxQtyWidth;
    kal_uint32  u4MJPEGMaxQtyHeight;
    kal_uint32  u4MJPEGMaxNormalWidth;
    kal_uint32  u4MJPEGMaxNormalHeight;
    kal_uint32  u4MJPEGWorkingMemory;
    kal_uint32  u4MJPEGTotalBufferSize;
#endif

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint8   u1VP8BufferNum;
    kal_uint32  u4VP8SupportResolution;
    kal_uint32  u4VP8NormalMaxResolution;
    kal_uint32  u4VP8MaxWidth;
    kal_uint32  u4VP8MaxHeight;
    kal_uint32  u4VP8NormalMaxWidth;
    kal_uint32  u4VP8NormalMaxHeight;
    kal_uint32  u4VP8WorkingMemory;
    kal_uint32  u4VP8TotalBufferSize;
#endif


    // QVGA

    kal_uint32  u4QVGAMaxWidth;
    kal_uint32  u4QVGAMaxHeight;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4QVGAMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4QVGAH264TotalBufferSize;
    kal_uint32  u4QVGAH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4QVGARV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4QVGAMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4QVGAVP8TotalBufferSize;
#endif


    kal_uint32  u4QVGAWorkingMemory;
    kal_uint32  u4QVGATotalBufferSize;
    kal_uint32  u4QVGASupportResolution;


    // QVGAMPEG4SP
    kal_uint32  u4QVGAMPEG4SPMaxWidth;
    kal_uint32  u4QVGAMPEG4SPMaxHeight;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4QVGAMPEG4SPMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4QVGAMPEG4SPH264TotalBufferSize;
    kal_uint32  u4QVGAMPEG4SPH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4QVGAMPEG4SPRV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4QVGAMPEG4SPMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4QVGAMPEG4SPVP8TotalBufferSize;
#endif
    kal_uint32  u4QVGAMPEG4SPWorkingMemory;
    kal_uint32  u4QVGAMPEG4SPTotalBufferSize;
    kal_uint32  u4QVGAMPEG4SPSupportResolution;


    // preview
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4PreviewMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4PreviewH264TotalBufferSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4PreviewRV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4PreviewMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4PreviewVP8TotalBufferSize;
#endif

    kal_uint32  u4PreviewWorkingMemory;
    kal_uint32  u4PreviewTotalBufferSize;
    kal_uint32  u4PreviewTotalMemorySize;

    // QCIF
    kal_uint32  u4QCIFMaxWidth;
    kal_uint32  u4QCIFMaxHeight;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4QCIFMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4QCIFH264TotalBufferSize;
    kal_uint32  u4QCIFH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4QCIFRV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4QCIFMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4QCIFVP8TotalBufferSize;
#endif


    kal_uint32  u4QCIFWorkingMemory;
    kal_uint32  u4QCIFTotalBufferSize;
    kal_uint32  u4QCIFSupportResolution;

    // VGA
    kal_uint32  u4VGAMaxWidth;
    kal_uint32  u4VGAMaxHeight;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4VGAMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4VGAH264TotalBufferSize;
    kal_uint32  u4VGAH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4VGARV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4VGAMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4VGAVP8TotalBufferSize;
#endif

    kal_uint32  u4VGAWorkingMemory;
    kal_uint32  u4VGATotalBufferSize;
    kal_uint32  u4VGASupportResolution;


    // CIF
    kal_uint32	u4CIFMaxWidth;
    kal_uint32	u4CIFMaxHeight;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32	u4CIFMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32	u4CIFH264TotalBufferSize;
    kal_uint32	u4CIFH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32	u4CIFRV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32	u4CIFMJPEGTotalBufferSize;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4CIFVP8TotalBufferSize;
#endif

    kal_uint32	u4CIFWorkingMemory;
    kal_uint32	u4CIFTotalBufferSize;
    kal_uint32	u4CIFSupportResolution;



    // Upto-CIF
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32	u4UPTOCIFMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32	u4UPTOCIFH264TotalBufferSize;
    kal_uint32	u4UPTOCIFH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32	u4UPTOCIFRV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32	u4UPTOCIFMJPEGTotalBufferSize;
    kal_uint32	u4UPTOCIFMJPEGMaxWidth;
    kal_uint32	u4UPTOCIFMJPEGMaxHeight;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4UPTOCIFVP8TotalBufferSize;
#endif

    kal_uint32	u4UPTOCIFWorkingMemory;
    kal_uint32	u4UPTOCIFTotalBufferSize;
    kal_uint32	u4UPTOCIFSupportResolution;


    // UPTOQVGA

#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    kal_uint32  u4UPTOQVGAMPEG4TotalBufferSize;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    kal_uint32  u4UPTOQVGAH264TotalBufferSize;
    kal_uint32  u4UPTOQVGAH264DPBSize;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    kal_uint32  u4UPTOQVGARV9TotalBufferSize;
#endif
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    kal_uint32  u4UPTOQVGAMJPEGTotalBufferSize;
    kal_uint32	u4UPTOQVGAMJPEGMaxWidth;
    kal_uint32	u4UPTOQVGAMJPEGMaxHeight;

#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    kal_uint32  u4UPTOQVGAVP8TotalBufferSize;
#endif

    kal_uint32  u4UPTOQVGAWorkingMemory;
    kal_uint32  u4UPTOQVGATotalBufferSize;
    kal_uint32  u4UPTOQVGASupportResolution;


    kal_uint32  u4InfoExtMemSize;
    kal_uint32  u4FrmBufferSize;
    kal_uint32  u4CodecWorkingMemory;
    kal_uint32  u4DriverWorkingMemory;
} VIDEO_DECODER_CUSTOM_SETTINGS_T;


typedef struct
{
    kal_uint32  u4DirectCoupleTotalSize;
    kal_uint32  u4BypassModeTotalBitstreamSize;
    kal_uint32  u4BypassModeOneBistreamSize;
    kal_uint32  u4BypassModeOneBistreamAlignedSize;
    kal_uint32  u4BypassModeBistreamNum;

    kal_uint32  u4TotalSize;

    kal_uint32  u4YuvHeaderQSize;
    kal_uint32  u4TimeStampQSize;
    kal_uint32  u4CmdQItemSize;
    kal_uint32  u4InputQItemSize;
    kal_uint32  u4OutputQItemSize;
    kal_uint32  u4YuvHeaderQItemSize;
    kal_uint32  u4TimeStampQItemSize;
    kal_uint32  u4CmdQNum;
    kal_uint32  u4InputQNum;
    kal_uint32  u4OutputQNum;
    kal_uint32  u4YuvHeaderQNum;
    kal_uint32  u4TimeStampQNum;
    kal_uint32  u4CacheLineSize;
    kal_uint32  u4ChassisItemSize;
    kal_uint32  u4ChassisNum;
    kal_uint32 u4ResendQSize;

    // Values below would depend on codec
    kal_uint32  u4MaxWidth;
    kal_uint32  u4MaxHeight;
    kal_uint32  u4MaxYuvBufferSize;
    kal_uint32  u4CodecMemorySize;
    kal_uint32  u4BitBufferSize;
    kal_uint32  u4FrmNum;
    kal_uint32  u4MinFrmNum;
} VIDEO_ENCODER_CUSTOM_SETTINGS_T;

extern kal_bool VideoDecoderGetResizerSetting(VIDEO_DECODER_RESIZER_SETTINGS_T* prSetting);
extern void VideoDecoderGetSetting(VIDEO_DECODER_CUSTOM_SETTINGS_T *prSetting);
extern void VideoEncoderGetSetting(VIDEO_ENCODER_CUSTOM_SETTINGS_T *prSetting, VIDEO_ENCODER_TYPE_T eType);
extern kal_bool VideoEncoderGetYuvFramesAndBufferSize(kal_uint32 u4Width,
        kal_uint32 u4Height, kal_uint32 *pu4Frames, kal_uint32 *pu4BufferSize);


#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_CUSTOM_SETTING_V2_H */

