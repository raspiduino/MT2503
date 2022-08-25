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
 *   video_codec_custom_setting_v2.c
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
#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)
#include "video_codec_custom_setting_v2.h"
#include "video_codec_mem_v2.h"
#include "video_codec_mem_custom_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_comm_component_v2.h"
#include "video_types_v2.h"
#include "RVSwDecMem.h"
#include "MPEG4HWEncMem.h"
#include "sw_video_decode_custom.h"
#include "hw_video_decode_custom.h"
#include "sw_video_encode_custom.h"
#include "hw_video_encode_custom.h"
#include "video_memory_usage_v2.h"
#include "vcodec_v2_trc.h"

kal_bool VideoDecoderGetResizerSetting(VIDEO_DECODER_RESIZER_SETTINGS_T* prSetting)
{
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__

    prSetting->u4MaxWidth          =   MJPEG_DEC_MAX_WIDTH;
    prSetting->u4MaxHeight         =   MJPEG_DEC_MAX_HEIGHT;
    prSetting->u4MaxQtyWidth       =   MJPEG_DEC_MAX_QTY_WIDTH;
    prSetting->u4MaxQtyHeight      =   MJPEG_DEC_MAX_QTY_HEIGHT;
    prSetting->u4MaxNormalWidth    =   MJPEG_DEC_MAX_NORMAL_WIDTH;
    prSetting->u4MaxNormalHeight   =   MJPEG_DEC_MAX_NORMAL_HEIGHT;

    return KAL_TRUE;

#else

    return KAL_FALSE;
    
#endif    
}

void VideoDecoderGetSetting(VIDEO_DECODER_CUSTOM_SETTINGS_T* prSetting)
{
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u1MPEG4BufferNum         =   MPEG4_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM;
    prSetting->u4MPEG4SupportResolution =   MPEG4_SUPPORT_RESOLUTION;
    prSetting->u4MPEG4NormalMaxResolution = MPEG4_MAX_NORMAL_MODE_RESOLUTION;
    prSetting->u4MPEG4MaxWidth          =   MPEG4_DEC_MAX_WIDTH;
    prSetting->u4MPEG4MaxHeight         =   MPEG4_DEC_MAX_HEIGHT;
    prSetting->u4MPEG4WorkingMemory     =   MPEG4_DEC_WORKING_MEM;
    prSetting->u4MPEG4TotalBufferSize   =   MPEG4_FRM_BUFFER_SIZE;

    drv_trace4(TRACE_FUNC, VDEC_MPEG4_SP_SEPC, MPEG4_DEC_MAX_WIDTH_SP, MPEG4_DEC_MAX_HEIGHT_SP, MPEG4_DEC_MAX_NORMAL_WIDTH_SP, MPEG4_DEC_MAX_NORMAL_HEIGHT_SP);

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        drv_trace4(TRACE_GROUP_10, VDEC_MPEG4_ASP_SEPC, MPEG4_DEC_MAX_WIDTH_ASP, MPEG4_DEC_MAX_HEIGHT_ASP, MPEG4_DEC_MAX_NORMAL_WIDTH_ASP, MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP);
    #endif

    #if defined(__VE_VIDEO_VT_SUPPORT__)
    prSetting->u1MPEG4VTBufferNum         =   MPEG4_VT_BUFFER_NUM;
    prSetting->u4MPEG4VTSupportResolution =   MPEG4_VT_SUPPORT_RESOLUTION;
    prSetting->u4MPEG4VTNormalMaxResolution = MPEG4_VT_SUPPORT_RESOLUTION;
    prSetting->u4MPEG4VTMaxWidth          =   MPEG4_VT_DEC_MAX_WIDTH;
    prSetting->u4MPEG4VTMaxHeight         =   MPEG4_VT_DEC_MAX_HEIGHT;
    prSetting->u4MPEG4VTWorkingMemory     =   MPEG4_VT_DEC_WORKING_MEM;
    prSetting->u4MPEG4VTTotalBufferSize   =   MPEG4_VT_TOTAL_BUFFER_SIZE;

    drv_trace2(TRACE_FUNC, VDEC_MPEG4VT_SEPC, MPEG4_VT_DEC_MAX_WIDTH, MPEG4_VT_DEC_MAX_HEIGHT);
    #endif
#endif

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u1H264BufferNum          =   H264_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM;
    prSetting->u4H264SupportResolution  =   H264_SUPPORT_RESOLUTION;
    prSetting->u4H264NormalMaxResolution = H264_MAX_NORMAL_MODE_RESOLUTION;
    prSetting->u1H264DecoderLevel       =   H264_DECODER_LEVEL;
    prSetting->u4H264MaxWidth           =   H264_DEC_MAX_WIDTH;
    prSetting->u4H264MaxHeight          =   H264_DEC_MAX_HEIGHT;
    prSetting->u4H264WorkingMemory      =   H264_DEC_WORKING_MEM;
    prSetting->u4H264DPBSize            =   H264_DEC_DPB_SIZE;
    prSetting->u4H264TotalBufferSize    =   H264_FRM_BUFFER_SIZE;

    drv_trace4(TRACE_FUNC, VDEC_H264_BP_SEPC, H264_DEC_MAX_WIDTH_BP, H264_DEC_MAX_HEIGHT_BP, H264_DEC_MAX_NORMAL_WIDTH_BP, H264_DEC_MAX_NORMAL_HEIGHT_BP);

    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        drv_trace4(TRACE_GROUP_10, VDEC_H264_MPHP_SEPC, H264_DEC_MAX_WIDTH_MPHP, H264_DEC_MAX_HEIGHT_MPHP, H264_DEC_MAX_NORMAL_WIDTH_MPHP, H264_DEC_MAX_NORMAL_HEIGHT_MPHP);
    #endif
#endif

#if defined(__VE_RV_DEC_SW_SUPPORT__)
    prSetting->u1RV9BufferNum           =   RV9_EXTRA_BUFFER_NUM + RM_DECODER_ESSENTIAL_BUFFER_NUM;
    prSetting->u4RV9SupportResolution   =   RV9_SUPPORT_RESOLUTION;
    prSetting->u4RV9NormalMaxResolution =   RV9_MAX_NORMAL_MODE_RESOLUTION;
    prSetting->u4RV9MaxWidth           =   RV9_DEC_MAX_WIDTH;
    prSetting->u4RV9MaxHeight          =   RV9_DEC_MAX_HEIGHT;
    prSetting->u4RV9NormalMaxWidth      =   RV9_DEC_MAX_NORMAL_WIDTH;
    prSetting->u4RV9NormalMaxHeight     =   RV9_DEC_MAX_NORMAL_HEIGHT;
    prSetting->u4RV9WorkingMemory       =   RV9_DEC_WORKING_MEM;
    prSetting->u4RV9TotalBufferSize     =   RV9_FRM_BUFFER_SIZE;

    drv_trace4(TRACE_FUNC, VDEC_RM_SEPC, RV9_DEC_MAX_WIDTH, RV9_DEC_MAX_HEIGHT, RV9_DEC_MAX_NORMAL_WIDTH, RV9_DEC_MAX_NORMAL_HEIGHT);
#endif

#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u1MJPEGBufferNum         =   MJPEG_EXTRA_BUFFER_NUM + DECODER_ESSENTIAL_BUFFER_NUM;
    prSetting->u4MJPEGSupportResolution =   MJPEG_SUPPORT_RESOLUTION;
    prSetting->u4MJPEGNormalMaxResolution = MJPEG_MAX_NORMAL_MODE_RESOLUTION;
    prSetting->u4MJPEGMaxWidth          =   MJPEG_DEC_MAX_WIDTH;
    prSetting->u4MJPEGMaxHeight         =   MJPEG_DEC_MAX_HEIGHT;
    prSetting->u4MJPEGWorkingMemory     =   MJPEG_DEC_WORKING_MEM;
    prSetting->u4MJPEGTotalBufferSize   =   MJPEG_FRM_BUFFER_SIZE;

    drv_trace4(TRACE_FUNC, VDEC_MJPEG_SEPC, MJPEG_DEC_MAX_WIDTH, MJPEG_DEC_MAX_HEIGHT, MJPEG_DEC_MAX_NORMAL_WIDTH, MJPEG_DEC_MAX_NORMAL_HEIGHT);
#endif

#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u1VP8BufferNum           =   VP8_EXTRA_BUFFER_NUM + VP8_DECODER_ESSENTIAL_BUFFER_NUM;
    prSetting->u4VP8SupportResolution   =   VP8_SUPPORT_RESOLUTION;
    prSetting->u4VP8NormalMaxResolution =   VP8_MAX_NORMAL_MODE_RESOLUTION;
    prSetting->u4VP8MaxWidth            =   VP8_DEC_MAX_WIDTH;
    prSetting->u4VP8MaxHeight           =   VP8_DEC_MAX_HEIGHT;
    prSetting->u4VP8NormalMaxWidth      =   VP8_DEC_MAX_NORMAL_WIDTH;
    prSetting->u4VP8NormalMaxHeight     =   VP8_DEC_MAX_NORMAL_HEIGHT;
    prSetting->u4VP8WorkingMemory       =   VP8_DEC_WORKING_MEM;
    prSetting->u4VP8TotalBufferSize     =   VP8_FRM_BUFFER_SIZE;

    drv_trace4(TRACE_FUNC, VDEC_VP8_SEPC, VP8_DEC_MAX_WIDTH, VP8_DEC_MAX_HEIGHT, VP8_DEC_MAX_NORMAL_WIDTH, VP8_DEC_MAX_NORMAL_HEIGHT);
#endif

    // QVGA
    prSetting->u4QVGAMaxWidth          =   320;
    prSetting->u4QVGAMaxHeight         =   240;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4QVGAMPEG4TotalBufferSize   =   MPEG4_QVGA_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4QVGAH264TotalBufferSize    =   H264_QVGA_NORMAL_BUFFER_SIZE;
    prSetting->u4QVGAH264DPBSize       =   H264_QVGA_DEC_DPB_SIZE;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
    prSetting->u4QVGARV9TotalBufferSize     =   RV9_QVGA_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4QVGAMJPEGTotalBufferSize   =   MJPEG_QVGA_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4QVGAVP8TotalBufferSize     =   VP8_QVGA_NORMAL_BUFFER_SIZE;
#endif


    prSetting->u4QVGAWorkingMemory     =   QVGA_CODEC_WORKING_MEM_SIZE;
    prSetting->u4QVGATotalBufferSize   =   QVGA_FRM_BUFFER_SIZE;
    prSetting->u4QVGASupportResolution =   RESOLUTION_320x240;


    // QVGAMPEG4SP
    prSetting->u4QVGAMPEG4SPMaxWidth               =   320;
    prSetting->u4QVGAMPEG4SPMaxHeight              =   240;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4QVGAMPEG4SPMPEG4TotalBufferSize   =   MPEG4_QVGAMPEG4SP_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4QVGAMPEG4SPH264TotalBufferSize    =   H264_QVGA_NORMAL_BUFFER_SIZE;
    prSetting->u4QVGAMPEG4SPH264DPBSize            =   H264_QVGA_DEC_DPB_SIZE;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
    prSetting->u4QVGAMPEG4SPRV9TotalBufferSize     =   RV9_QVGA_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4QVGAMPEG4SPMJPEGTotalBufferSize   =   MJPEG_QVGA_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4QVGAMPEG4SPVP8TotalBufferSize     =   VP8_QVGA_NORMAL_BUFFER_SIZE;
#endif
    prSetting->u4QVGAMPEG4SPWorkingMemory     =   QVGAMPEG4SP_CODEC_WORKING_MEM_SIZE;
    prSetting->u4QVGAMPEG4SPTotalBufferSize   =   QVGAMPEG4SP_FRM_BUFFER_SIZE;
    prSetting->u4QVGAMPEG4SPSupportResolution =   RESOLUTION_320x240;


    // preview
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4PreviewMPEG4TotalBufferSize   =   MPEG4_PREVIEW_FRM_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4PreviewH264TotalBufferSize    =   H264_PREVIEW_FRM_BUFFER_SIZE;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
    prSetting->u4PreviewRV9TotalBufferSize     =   RV9_PREVIEW_FRM_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4PreviewMJPEGTotalBufferSize   =   MJPEG_PREVIEW_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4PreviewVP8TotalBufferSize     =   VP8_PREVIEW_FRM_BUFFER_SIZE;
#endif

    prSetting->u4PreviewWorkingMemory     =   PREVIEW_CODEC_WORKING_MEM_SIZE;
    prSetting->u4PreviewTotalBufferSize   =   PREVIEW_FRM_BUFFER_SIZE;
    prSetting->u4PreviewTotalMemorySize   =   PREVIEW_TEMP_TOTAL_MEM_SIZE;

    prSetting->u4InfoExtMemSize       = INFO_MEM_SIZE;
    prSetting->u4FrmBufferSize          =   FRM_BUFFER_SIZE;
    prSetting->u4CodecWorkingMemory     =   CODEC_WORKING_MEM_SIZE;
    prSetting->u4DriverWorkingMemory    =   VIDEO_DEC_WORKING_MEM_SIZE;

    // QCIF
    prSetting->u4QCIFMaxWidth		   =   176;
    prSetting->u4QCIFMaxHeight		   =   144;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4QCIFMPEG4TotalBufferSize	=	MPEG4_QCIF_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4QCIFH264TotalBufferSize	=	H264_QCIF_NORMAL_BUFFER_SIZE;
    prSetting->u4QCIFH264DPBSize	   	=   H264_QCIF_DEC_DPB_SIZE;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    prSetting->u4QCIFRV9TotalBufferSize 	=	RV9_QCIF_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4QCIFMJPEGTotalBufferSize	=	MJPEG_QCIF_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4QCIFVP8TotalBufferSize         =   VP8_QCIF_NORMAL_BUFFER_SIZE;
#endif

    prSetting->u4QCIFWorkingMemory	   =   QCIF_CODEC_WORKING_MEM_SIZE;
    prSetting->u4QCIFTotalBufferSize       =   QCIF_FRM_BUFFER_SIZE;
    prSetting->u4QCIFSupportResolution     =   RESOLUTION_176x144;

    // VGA
    prSetting->u4VGAMaxWidth		   =   640;
    prSetting->u4VGAMaxHeight		   =   480;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4VGAMPEG4TotalBufferSize	=	MPEG4_VGA_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4VGAH264TotalBufferSize	=	H264_VGA_NORMAL_BUFFER_SIZE;
    prSetting->u4VGAH264DPBSize	   		=   H264_VGA_DEC_DPB_SIZE;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    prSetting->u4VGARV9TotalBufferSize 	=	RV9_VGA_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4VGAMJPEGTotalBufferSize	=	MJPEG_VGA_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4VGAVP8TotalBufferSize          =   VP8_VGA_NORMAL_BUFFER_SIZE;
#endif
    prSetting->u4VGAWorkingMemory	   =   VGA_CODEC_WORKING_MEM_SIZE;
    prSetting->u4VGATotalBufferSize   =   VGA_FRM_BUFFER_SIZE;
    prSetting->u4VGASupportResolution =   RESOLUTION_640x480;

    // CIF
    prSetting->u4CIFMaxWidth		   =   352;
    prSetting->u4CIFMaxHeight		   =   288;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4CIFMPEG4TotalBufferSize	=	MPEG4_CIF_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4CIFH264TotalBufferSize	=	H264_CIF_NORMAL_BUFFER_SIZE;
    prSetting->u4CIFH264DPBSize			=	H264_CIF_DEC_DPB_SIZE;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    prSetting->u4CIFRV9TotalBufferSize 	=	RV9_CIF_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4CIFMJPEGTotalBufferSize	=	MJPEG_CIF_BUFFER_SIZE;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4CIFVP8TotalBufferSize     =   VP8_CIF_NORMAL_BUFFER_SIZE;
#endif
    prSetting->u4CIFWorkingMemory	  =   CIF_CODEC_WORKING_MEM_SIZE;
    prSetting->u4CIFTotalBufferSize   =   CIF_FRM_BUFFER_SIZE;
    prSetting->u4CIFSupportResolution =   RESOLUTION_352x288;


    // UP TO CIF
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4UPTOCIFMPEG4TotalBufferSize	=	MPEG4_UPTOCIF_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4UPTOCIFH264TotalBufferSize	    =	H264_UPTOCIF_NORMAL_BUFFER_SIZE;
    prSetting->u4UPTOCIFH264DPBSize			    =	H264_UPTOCIF_DEC_DPB_SIZE;
#endif
#ifdef __VE_RV_DEC_SW_SUPPORT__
    prSetting->u4UPTOCIFRV9TotalBufferSize 	    =	RV9_UPTOCIF_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4UPTOCIFMJPEGTotalBufferSize	=	MJPEG_UPTOCIF_BUFFER_SIZE;
    prSetting->u4UPTOCIFMJPEGMaxWidth           =   MJPEG_UPTOCIF_DEC_MAX_WIDTH;
    prSetting->u4UPTOCIFMJPEGMaxHeight          =   MJPEG_UPTOCIF_DEC_MAX_HEIGHT;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4UPTOCIFVP8TotalBufferSize      =   VP8_UPTOCIF_NORMAL_BUFFER_SIZE;
#endif
    prSetting->u4UPTOCIFWorkingMemory	        =   UPTOCIF_CODEC_WORKING_MEM_SIZE;
    prSetting->u4UPTOCIFTotalBufferSize         =   UPTOCIF_FRM_BUFFER_SIZE;


    // UP TO QVGA
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    prSetting->u4UPTOQVGAMPEG4TotalBufferSize   =   MPEG4_UPTOQVGA_NORMAL_BUFFER_SIZE;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    prSetting->u4UPTOQVGAH264TotalBufferSize    =   H264_UPTOQVGA_NORMAL_BUFFER_SIZE;
    prSetting->u4UPTOQVGAH264DPBSize            =   H264_UPTOQVGA_DEC_DPB_SIZE;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
    prSetting->u4UPTOQVGARV9TotalBufferSize     =   RV9_UPTOQVGA_NORMAL_BUFFER_SIZE;
#endif
#if defined(__VE_MJPEG_DEC_SW_SUPPORT__)
    prSetting->u4UPTOQVGAMJPEGTotalBufferSize   =   MJPEG_UPTOQVGA_BUFFER_SIZE;
    prSetting->u4UPTOQVGAMJPEGMaxWidth          =   MJPEG_UPTOQVGA_DEC_MAX_WIDTH;
    prSetting->u4UPTOQVGAMJPEGMaxHeight         =   MJPEG_UPTOQVGA_DEC_MAX_HEIGHT;
#endif
#if defined(__VE_VP8_DEC_SW_SUPPORT__)
    prSetting->u4UPTOQVGAVP8TotalBufferSize     =   VP8_UPTOQVGA_NORMAL_BUFFER_SIZE;
#endif



    return;
}


/******************************************************************************
* Get the setting for the encoder component.
******************************************************************************/
void VideoEncoderGetSetting(
    VIDEO_ENCODER_CUSTOM_SETTINGS_T *prSet,
    VIDEO_ENCODER_TYPE_T eType)
{
    // Common definitions
    prSet->u4CmdQItemSize           =   VIDEO_COMM_COMMAND_Q_ITEM_SIZE;
    prSet->u4InputQItemSize         =   VIDEO_COMM_INPUT_Q_ITEM_SIZE;
    prSet->u4OutputQItemSize        =   VIDEO_COMM_OUTPUT_Q_ITEM_SIZE;
    // Interface between encoder and codec schedule controller
    prSet->u4InputQNum              =   VIDEO_ENCODER_INPUT_BUFFER_Q_NUM;
    prSet->u4YuvHeaderQNum          =   VIDEO_ENCODER_YUV_HEADER_Q_NUM;
    prSet->u4YuvHeaderQSize         =   VENC_YUV_HEADER_Q_SIZE;
    prSet->u4TimeStampQSize         =   VENC_TIME_STAMP_Q_SIZE;
    prSet->u4YuvHeaderQItemSize     =   VENC_YUV_HEADER_Q_ITEM_SIZE;
    prSet->u4TimeStampQItemSize     =   VENC_TIME_STAMP_Q_ITEM_SIZE;
    prSet->u4CmdQNum                =   VENC_COMMAND_Q_NUM;
    prSet->u4OutputQNum             =   VENC_OUTPUT_BUFFER_Q_NUM;
    prSet->u4TimeStampQNum          =   VENC_TIME_STAMP_Q_NUM;
    prSet->u4CacheLineSize          =   CPU_CACHE_LINE_SIZE_REC;
    prSet->u4ChassisItemSize        =   VENC_SIZE_PER_CHASSIS;
    prSet->u4ChassisNum             =   VENC_MAX_CHASSIS_NUM_X;
    prSet->u4ResendQSize            =   VENC_RESEND_Q_SIZE;


    switch(eType)
    {
    case VIDEO_ENCODER_MPEG4:
    case VIDEO_ENCODER_H263:
    case VIDEO_ENCODER_RECORD_YUV:
#if defined(__VE_MPEG4_ENC_HW_SUPPORT__)
        prSet->u4TotalSize          =   MPEG4_HW_RECORDER_TOTAL_MEM_SIZE;
        prSet->u4MaxWidth           =   MPEG4_HW_ENC_MAX_WIDTH;
        prSet->u4MaxHeight          =   MPEG4_HW_ENC_MAX_HEIGHT;
        prSet->u4BitBufferSize      =   MPEG4_HW_ENC_BIT_BUFFER_SIZE;
        prSet->u4MaxYuvBufferSize   =   MPEG4_HW_ENC_MAX_YUV_BUFFER_SIZE;
        prSet->u4CodecMemorySize    =   MPEG4_HW_ENC_WORKING_MEM_WITH_ADM_OVERHEAD;
        prSet->u4FrmNum             =   MPEG4_HW_ENC_YUV_FRAME_NUM;
        prSet->u4MinFrmNum          =   MPEG4_HW_ENC_MIN_FRAME_NUM;
#elif defined(__VE_MPEG4_ENC_SW_SUPPORT__)
        prSet->u4TotalSize          =   MPEG4_RECORDER_TOTAL_MEM_SIZE;
        prSet->u4MaxWidth           =   MPEG4_ENC_MAX_WIDTH;
        prSet->u4MaxHeight          =   MPEG4_ENC_MAX_HEIGHT;
        prSet->u4BitBufferSize      =   MPEG4_ENC_BIT_BUFFER_SIZE;
        prSet->u4MaxYuvBufferSize   =   MPEG4_ENC_MAX_YUV_BUFFER_SIZE;
        prSet->u4CodecMemorySize    =   MPEG4_ENC_WORKING_MEM_WITH_ADM_OVERHEAD;
        prSet->u4FrmNum             =   MPEG4_ENC_YUV_FRAME_NUM;
        prSet->u4MinFrmNum          =   MPEG4_ENC_MIN_FRAME_NUM;
#else
        ASSERT(0);
#endif  // __VE_MPEG4_ENC_SW_SUPPORT__
        break;
    case VIDEO_ENCODER_MJPEG:
#if defined(__VE_MJPEG_ENC_SUPPORT__)
        prSet->u4TotalSize          =   MJPEG_RECORDER_TOTAL_MEM_SIZE;
        prSet->u4MaxWidth           =   MJPEG_ENC_MAX_WIDTH;
        prSet->u4MaxHeight          =   MJPEG_ENC_MAX_HEIGHT;
        prSet->u4BitBufferSize      =   MJPEG_ENC_BIT_BUFFER_SIZE;
        prSet->u4MaxYuvBufferSize   =   MJPEG_ENC_MAX_YUV_BUFFER_SIZE;
        prSet->u4CodecMemorySize    =   MJPEG_ENC_WORKING_MEM_WITH_ADM_OVERHEAD;
        prSet->u4FrmNum             =   MJPEG_ENC_YUV_FRAME_NUM;
        prSet->u4MinFrmNum          =   MJPEG_ENC_MIN_FRAME_NUM;
#else
        ASSERT(0);
#endif //__VE_MJPEG_ENC_SUPPORT__
        break;
    case VIDEO_ENCODER_H264:
#if defined(__VE_H264_ENC_SW_SUPPORT__)
        prSet->u4TotalSize          =   H264_RECORDER_TOTAL_MEM_SIZE;
        prSet->u4MaxWidth           =   H264_ENC_MAX_WIDTH;
        prSet->u4MaxHeight          =   H264_ENC_MAX_HEIGHT;
        prSet->u4BitBufferSize      =   H264_ENC_BIT_BUFFER_SIZE;
        prSet->u4MaxYuvBufferSize   =   H264_ENC_MAX_YUV_BUFFER_SIZE;
        prSet->u4CodecMemorySize    =   H264_ENC_WORKING_MEM_WITH_ADM_OVERHEAD;
        prSet->u4FrmNum             =   H264_ENC_YUV_FRAME_NUM;
        prSet->u4MinFrmNum          =   H264_ENC_MIN_FRAME_NUM;
#else
        ASSERT(0);
#endif  // __VE_H264_ENC_SW_SUPPORT__
        break;
    case VIDEO_ENCODER_MPEG4_VT:
    case VIDEO_ENCODER_H263_VT:
    case VIDEO_ENCODER_UNKNOWN_VT:
#if defined(__VE_VIDEO_VT_SUPPORT__)
        prSet->u4TotalSize          =   MPEG4_ENC_VT_TOTAL_MEM_SIZE;
        prSet->u4MaxWidth           =   MPEG4_ENC_VT_MAX_WIDTH;
        prSet->u4MaxHeight          =   MPEG4_ENC_VT_MAX_HEIGHT;
        prSet->u4MaxYuvBufferSize   =   MPEG4_ENC_VT_MAX_YUV_BUFFER_SIZE;
        prSet->u4CodecMemorySize    =   MPEG4_ENC_VT_WORKING_MEM_WITH_ADM_OVERHEAD;
        prSet->u4BitBufferSize      =   MPEG4_ENC_VT_BIT_BUFFER_SIZE;
        prSet->u4FrmNum             =   MPEG4_ENC_VT_YUV_FRAME_NUM;
        prSet->u4MinFrmNum          =   MPEG4_ENC_VT_MIN_FRAME_NUM;
#else
        ASSERT(0);
#endif  //__VE_VIDEO_VT_SUPPORT__
        break;
    case VIDEO_ENCODER_MJPEG_DIRECT_COUPLE:
#if defined(__VE_MJPEG_ENC_BYPASS__)
        prSet->u4DirectCoupleTotalSize              =   VENC_COMP_DIRECTCOUPLE_MEMORY_SIZE;
        prSet->u4BypassModeTotalBitstreamSize       =   VENC_COMP_DIRECTCOUPLE_BITSTREAM_SIZE;
        prSet->u4BypassModeOneBistreamSize          =   DIRECTCOUPLD_ONE_BITSTREAM_SIZE;
        prSet->u4BypassModeOneBistreamAlignedSize   =   DIRECTCOUPLE_ONE_BISTREAM_ALIGHED_SIZE;
        prSet->u4BypassModeBistreamNum              =   DIRECTCOUPLE_BISTREAM_NUM;
        prSet->u4MaxWidth                           =   (kal_uint32)(-1);
        prSet->u4MaxHeight                          =   (kal_uint32)(-1);
#else
        ASSERT(0);
#endif    //__VE_MJPEG_ENC_BYPASS__
        break;
    default:
        ASSERT(0);
        break;
    }
}


#endif /*__VIDEO_ARCHI_V2__*/

