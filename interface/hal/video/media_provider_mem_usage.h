/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   media_provider_mem_usage.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIA_PROVIDER_MEM_USE_H
#define _MEDIA_PROVIDER_MEM_USE_H

#include "media_provider_mem_usage_internal.h"

/****************
 * MP4 provider *
 ****************/
#if defined(__VE_MP43GP_FILE_FORMAT_SUPPORT__)
#define MP4_MP_CORE_MEM_SIZE (MP4_MP_CORE_MEM_SIZE_IF)
#define MP4_MP_AUDIO_MEM_SIZE (MP4_MP_AUDIO_MEM_SIZE_IF)
#define MP4_MP_VIDEO_MEM_SIZE (MP4_MP_VIDEO_MEM_SIZE_IF)
#define MP4_MP_SUBTITLE_MEM_SIZE (MP4_MP_SUBTITLE_MEM_SIZE_IF)

// Preview
#define MP4_MP_CORE_PREVIEW_MEM_SIZE  (MP4_MP_CORE_PREVIEW_MEM_SIZE_IF)
#define MP4_MP_AUDIO_PREVIEW_MEM_SIZE (MP4_MP_AUDIO_PREVIEW_MEM_SIZE_IF)
#define MP4_MP_VIDEO_PREVIEW_MEM_SIZE (MP4_MP_VIDEO_PREVIEW_MEM_SIZE_IF)
#define MP4_MP_SUBTITLE_PREVIEW_MEM_SIZE (MP4_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF)
#endif /* defined(__VE_MP43GP_FILE_FORMAT_SUPPORT__) */


/****************
 * AVI provider *
 ****************/
#if defined(__VE_SP_AVI__)
#define AVI_MP_CORE_MEM_SIZE (AVI_MP_CORE_MEM_SIZE_IF)
#define AVI_MP_AUDIO_MEM_SIZE (AVI_MP_AUDIO_MEM_SIZE_IF)
#define AVI_MP_VIDEO_MEM_SIZE (AVI_MP_VIDEO_MEM_SIZE_IF)
#define AVI_MP_SUBTITLE_MEM_SIZE (AVI_MP_SUBTITLE_MEM_SIZE_IF)

#define AVI_MP_CORE_PREVIEW_MEM_SIZE  (AVI_MP_CORE_PREVIEW_MEM_SIZE_IF)
#define AVI_MP_AUDIO_PREVIEW_MEM_SIZE (AVI_MP_AUDIO_PREVIEW_MEM_SIZE_IF)
#define AVI_MP_VIDEO_PREVIEW_MEM_SIZE (AVI_MP_VIDEO_PREVIEW_MEM_SIZE_IF)
#define AVI_MP_SUBTITLE_PREVIEW_MEM_SIZE (AVI_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF)
#endif /* defined(__VE_SP_AVI__) */


/****************
 * RM  provider *
 ****************/
#if defined(__VE_SP_RM__)
#define RM_MP_CORE_MEM_SIZE (RM_MP_CORE_MEM_SIZE_IF)
#define RM_MP_AUDIO_MEM_SIZE (RM_MP_AUDIO_MEM_SIZE_IF)
#define RM_MP_VIDEO_MEM_SIZE (RM_MP_VIDEO_MEM_SIZE_IF)
#define RM_MP_SUBTITLE_MEM_SIZE (RM_MP_SUBTITLE_MEM_SIZE_IF)

#define RM_MP_CORE_PREVIEW_MEM_SIZE  (RM_MP_CORE_PREVIEW_MEM_SIZE_IF)
#define RM_MP_AUDIO_PREVIEW_MEM_SIZE (RM_MP_AUDIO_PREVIEW_MEM_SIZE_IF)
#define RM_MP_VIDEO_PREVIEW_MEM_SIZE (RM_MP_VIDEO_PREVIEW_MEM_SIZE_IF)
#define RM_MP_SUBTITLE_PREVIEW_MEM_SIZE (RM_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF)
#endif /* defined(__RM_DEC_SUPPORT__) */


/****************
 * FLV provider *
 ****************/
#if defined(__VE_FLV_FILE_FORMAT_SUPPORT__)
#define FLV_MP_CORE_MEM_SIZE (FLV_MP_CORE_MEM_SIZE_IF)
#define FLV_MP_AUDIO_MEM_SIZE (FLV_MP_AUDIO_MEM_SIZE_IF)
#define FLV_MP_VIDEO_MEM_SIZE (FLV_MP_VIDEO_MEM_SIZE_IF)
#define FLV_MP_SUBTITLE_MEM_SIZE (FLV_MP_SUBTITLE_MEM_SIZE_IF)

#define FLV_MP_CORE_PREVIEW_MEM_SIZE  (FLV_MP_CORE_PREVIEW_MEM_SIZE_IF)
#define FLV_MP_AUDIO_PREVIEW_MEM_SIZE (FLV_MP_AUDIO_PREVIEW_MEM_SIZE_IF)
#define FLV_MP_VIDEO_PREVIEW_MEM_SIZE (FLV_MP_VIDEO_PREVIEW_MEM_SIZE_IF)
#define FLV_MP_SUBTITLE_PREVIEW_MEM_SIZE (FLV_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF)
#endif /* defined(__VE_FLV_FILE_FORMAT_SUPPORT__) */


/****************
 * MKV provider *
 ****************/
#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)
#define MKV_MP_CORE_MEM_SIZE (MKV_MP_CORE_MEM_SIZE_IF)
#define MKV_MP_AUDIO_MEM_SIZE (MKV_MP_AUDIO_MEM_SIZE_IF)
#define MKV_MP_VIDEO_MEM_SIZE (MKV_MP_VIDEO_MEM_SIZE_IF)
#define MKV_MP_SUBTITLE_MEM_SIZE (MKV_MP_SUBTITLE_MEM_SIZE_IF)

#define MKV_MP_CORE_PREVIEW_MEM_SIZE  (MKV_MP_CORE_PREVIEW_MEM_SIZE_IF)
#define MKV_MP_AUDIO_PREVIEW_MEM_SIZE (MKV_MP_AUDIO_PREVIEW_MEM_SIZE_IF)
#define MKV_MP_VIDEO_PREVIEW_MEM_SIZE (MKV_MP_VIDEO_PREVIEW_MEM_SIZE_IF)
#define MKV_MP_SUBTITLE_PREVIEW_MEM_SIZE (MKV_MP_SUBTITLE_PREVIEW_MEM_SIZE_IF)
#endif /* defined(__VE_MKV_FILE_FORMAT_SUPPORT__) */


/***********************
 * Streaming  provider *
 ***********************/
#if (defined(STREAM_SUPPORT) || defined(__MTV_SUPPORT__))
#define STREAMING_MP_CORE_MEM_SIZE (STREAMING_MP_CORE_MEM_SIZE_IF)
#define STREAMING_MP_AUDIO_MEM_SIZE (STREAMING_MP_AUDIO_MEM_SIZE_IF)
#define STREAMING_MP_VIDEO_MEM_SIZE (STREAMING_MP_VIDEO_MEM_SIZE_IF)
#define STREAMING_MP_SUBTITLE_MEM_SIZE (STREAMING_MP_SUBTITLE_MEM_SIZE_IF)
#endif /* defined(__MED_STREAM_MOD__) */

#endif /* _MEDIA_PROVIDER_MEM_USE_H */

