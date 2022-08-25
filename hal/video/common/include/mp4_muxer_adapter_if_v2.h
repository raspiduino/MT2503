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
 *   mp4_muxer_adapter_if_v2.h
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
 ****************************************************************************/
#include "drv_features_video.h"

#ifndef __MP4_MUXER_ADAPTER_IF_V2_H__
#define __MP4_MUXER_ADAPTER_IF_V2_H__

#include "video_muxer_if_v2.h"
#include "sw_video_encode_custom.h"
#include "hal_custom_video_if.h"
#include "cache_sw.h"

#define BOX_TIME_SCALE                 8000

// when reach this threshold, file writer will start to write from buffer to file
#if defined(MT6276) || defined(MT6256)
#define MP4_BITSTREAM_THRESHOLD              (64 * 1024)     // 64 KB
#else
#define MP4_BITSTREAM_THRESHOLD              (32 * 1024)     // 32 KB
#endif  // defined(MT6276)

#define MP4_BITSTREAM_FILE_HEADER            32             /* Equal to _u4BitFileOffset */

#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUPPORT_MP4_MUXER_ADAPTER__)
    // Max file path length
    #define _MP4_MAX_SIZE_OF_FILE_NAME (261)
    #define _MP4_SIZE_OF_FILE_NAME_BUFFER (2 * _MP4_MAX_SIZE_OF_FILE_NAME) // sizeof(kal_wchar)

    // Recording
    #if !defined(ENABLE_MP4_MUXER_CUSTOM_SETTING)
        #define MP4_STTS_ARRAY_SIZE_IN_BYTE     (8192)
        #define MP4_STSZ_ARRAY_SIZE_IN_BYTE     (8192)
        #define MP4_STCO_ARRAY_SIZE_IN_BYTE     (8192)
        #define MP4_STSS_ARRAY_SIZE_IN_BYTE     (8192)
    #else
        #define MP4_STTS_ARRAY_SIZE_IN_BYTE     (CUSTOM_MP4_STTS_ARRAY_SIZE_IN_BYTE)
        #define MP4_STSZ_ARRAY_SIZE_IN_BYTE     (CUSTOM_MP4_STSZ_ARRAY_SIZE_IN_BYTE)
        #define MP4_STCO_ARRAY_SIZE_IN_BYTE     (CUSTOM_MP4_STCO_ARRAY_SIZE_IN_BYTE)
        #define MP4_STSS_ARRAY_SIZE_IN_BYTE     (CUSTOM_MP4_STSS_ARRAY_SIZE_IN_BYTE)
    #endif

    #if ((MP4_STTS_ARRAY_SIZE_IN_BYTE % 512) != 0)
        #error "MP4_STTS_ARRAY_SIZE_IN_BYTE must be a multiple of 512."
    #endif  // ((MP4_STTS_ARRAY_SIZE_IN_BYTE % 512) != 0)

    #if ((MP4_STSZ_ARRAY_SIZE_IN_BYTE % 512) != 0)
        #error "MP4_STSZ_ARRAY_SIZE_IN_BYTE must be a multiple of 512."
    #endif  // ((MP4_STSZ_ARRAY_SIZE_IN_BYTE % 512) != 0)

    #if ((MP4_STCO_ARRAY_SIZE_IN_BYTE % 512) != 0)
        #error "MP4_STCO_ARRAY_SIZE_IN_BYTE must be a multiple of 512."
    #endif  // ((MP4_STCO_ARRAY_SIZE_IN_BYTE % 512) != 0)

    #if ((MP4_STSS_ARRAY_SIZE_IN_BYTE % 512) != 0)
        #error "MP4_STSS_ARRAY_SIZE_IN_BYTE must be a multiple of 512."
    #endif  // ((MP4_STSS_ARRAY_SIZE_IN_BYTE % 512) != 0)

    #define MP4_ADM_OVERHEAD       (512)
    #define MP4_MUXER_TOTAL_RECORD_MEM_SIZE (MP4_STTS_ARRAY_SIZE_IN_BYTE + \
                                            MP4_STSZ_ARRAY_SIZE_IN_BYTE + \
                                            MP4_STCO_ARRAY_SIZE_IN_BYTE + \
                                            MP4_STSS_ARRAY_SIZE_IN_BYTE + \
                                            MP4_ADM_OVERHEAD    +   \
                                            (_MP4_SIZE_OF_FILE_NAME_BUFFER + CPU_CACHE_LINE_SIZE) * 4)

    // CreateFile
    #define MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE    (8192)
    #define MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE  (4096 * 2)
    #define MP4_MUXER_TOTAL_CREATEFILE_MEM_SIZE (MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE + \
                                                MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE +    \
                                                MP4_ADM_OVERHEAD    +   \
                                                (_MP4_SIZE_OF_FILE_NAME_BUFFER + CPU_CACHE_LINE_SIZE) * 4)
    // Total
    #if (MP4_MUXER_TOTAL_RECORD_MEM_SIZE > MP4_MUXER_TOTAL_CREATEFILE_MEM_SIZE)
        #define MP4_MUXER_TOTAL_EXT_MEM_SIZE    (MP4_MUXER_TOTAL_RECORD_MEM_SIZE)
    #else
        #define MP4_MUXER_TOTAL_EXT_MEM_SIZE    (MP4_MUXER_TOTAL_CREATEFILE_MEM_SIZE)
    #endif
#else
    #define MP4_MUXER_TOTAL_EXT_MEM_SIZE    (0)
#endif

MUXER_ADAPT_API_T* MP4MuxerAdapterGetHandle(void);

#endif // __MP4_MUXER_ADAPTER_IF_V2_H__


