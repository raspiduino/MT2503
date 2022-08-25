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
 *   jpeg_mem_int.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Memory size definition for JPEG decoding.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_MEM_INT_H__
#define __JPEG_MEM_INT_H__

#include "drv_features_jpeg.h"

#if !defined(JPEG_CODEC_STANDALONE)
   #include "idp_mem_def.h"
#endif

#ifndef MIN
#define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
#define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX

/// Macro for read buffer and FSAL cache buffer.
#define JPEG_MARKER_SEGMENT_MAX_LENGTH                         (65536)

/// Default progressive JPEG image width
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE_03M)
   #define JPEG_DEC_MAX_PROG_IMAGE_WIDTH                          640
   #define JPEG_DEC_MAX_PROG_IMAGE_HEIGHT                         480
#elif defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE_1M)
   #define JPEG_DEC_MAX_PROG_IMAGE_WIDTH                          1280
   #define JPEG_DEC_MAX_PROG_IMAGE_HEIGHT                         960
#elif defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE_2M)
   #define JPEG_DEC_MAX_PROG_IMAGE_WIDTH                          1600
   #define JPEG_DEC_MAX_PROG_IMAGE_HEIGHT                         1200
#elif defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE_3M)
   #define JPEG_DEC_MAX_PROG_IMAGE_WIDTH                          2048
   #define JPEG_DEC_MAX_PROG_IMAGE_HEIGHT                         1536
#else
   #define JPEG_DEC_MAX_PROG_IMAGE_WIDTH                          0
   #define JPEG_DEC_MAX_PROG_IMAGE_HEIGHT                         0
#endif

#if defined(EXIF_SUPPORT)
   #define JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE                   (5120)
#else
   #define JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE                   (0)
#endif
/// sizeof(EXIF_APP1_INFO)
#define EXIF_APP1_INFO_STRUCTURE_MEM_SIZE                      ((1940 + 1024) + 4)

#define JPEG_DEC_FSAL_CACHE_SIZE                               (2 * 1024)   ///< The suggested buffer size for FSAL read cache.

#define JPEG_DEC_MAX_PROG_MCU_PER_ROW                          (JPEG_DEC_MAX_PROG_IMAGE_WIDTH / 8) // For YUV420 case

/// Macro for working memory.
#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
   #define JPEG_HW_DEC_MAX_FILE_BUFFER_SIZE                     (JPEG_MARKER_SEGMENT_MAX_LENGTH + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE + 200 * 1024) ///< the suggested buffer size for file read buffer
   #define JPEG_HW_DEC_MIN_FILE_BUFFER_SIZE                     (JPEG_MARKER_SEGMENT_MAX_LENGTH + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE + 200 * 1024) ///< the suggested buffer size for file read buffer
   #define JPEG_HW_DEC_FILE_BUFFER_SIZE                         JPEG_HW_DEC_MIN_FILE_BUFFER_SIZE
#else
   #define JPEG_HW_DEC_MAX_FILE_BUFFER_SIZE                     (0)
   #define JPEG_HW_DEC_MIN_FILE_BUFFER_SIZE                     (0)
   #define JPEG_HW_DEC_FILE_BUFFER_SIZE                         (0)
#endif

// add 32byte alignment for dynamic cache switching
#define JPEG_SW_DEC_MAX_FILE_BUFFER_SIZE                        ((32 * 1024 + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE + 31) &(~31))
#define JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE                        ((32 * 1024 + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE + 31) &(~31))
#define JPEG_SW_DEC_WORKING_BUFFER_MARGIN                       (512)

#define JPEG_SW_DEC_BASIC_STRUCTURE_MEM_SIZE                    ((3660 + 3) & ~3)

///#define JPEG_SW_ENC_V2_BASIC_EXT_MEM_SIZE                    (((sizeof(SWJE_FRAGMENT_PROCESSOR) + 3) & 0xFFFFFFFC) +   \
///                                                             (((sizeof(SWJE_FDCT_QUANT_UNIT) * 3) + 3) & 0xFFFFFFFC) + \
///                                                             ((sizeof(SWJE_HUFFMAN_ENCODER) + 3) & 0xFFFFFFFC) +       
#define JPEG_SW_ENC_BASIC_STRUCTURE_MEM_SIZE                    (((448 + 1024) + 3) & 0xFFFFFFFC)

#endif
