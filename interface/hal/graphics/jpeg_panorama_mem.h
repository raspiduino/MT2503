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
 *   jpeg_panorama_mem.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG memory.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#ifndef __JPEG_PANORAMA_MEM_H__
#define __JPEG_PANORAMA_MEM_H__

#include "drv_features_jpeg.h"

/// 1. Input/ Output color format
///    Input: RGB565 => Output: YUV422
///    Input: YUV420 => Output: YUV420
/// 2. 35/68/36/76
/// 3. No RGB resize/YUV resize/Rotate/Thumbnail/exif

#if defined(JPEG_CODEC_STANDALONE)
   #define JPEG_PANORAMA_MAX_WIDTH        1280
#else
   #include "feature_comm_def.h"   /// mcu\custom\drv\Camera_common
   #define JPEG_PANORAMA_MAX_WIDTH        PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH
#endif

#if defined(__L1_STANDALONE__) || defined(__UL1_STANDALONE__)

   #define JPEG_ENC_PANORAMA_INT_MIN_MEM_SIZE                     0
   #define JPEG_ENC_PANORAMA_INT_MAX_MEM_SIZE                     0
   #define JPEG_ENC_PANORAMA_EXT_MIN_MEM_SIZE                     0
   #define JPEG_ENC_PANORAMA_EXT_MAX_MEM_SIZE                     0

   #define JPEG_DEC_PANORAMA_INT_MIN_MEM_SIZE                     0
   #define JPEG_DEC_PANORAMA_INT_MAX_MEM_SIZE                     0
   #define JPEG_DEC_PANORAMA_EXT_MIN_MEM_SIZE                     0
   #define JPEG_DEC_PANORAMA_EXT_MAX_MEM_SIZE                     0

   #define JPEG_DEC_ENC_PANORAMA_TOTAL_INT_MIN_MEM_SIZE           0
   #define JPEG_DEC_ENC_PANORAMA_TOTAL_INT_MAX_MEM_SIZE           0
   #define JPEG_DEC_ENC_PANORAMA_TOTAL_EXT_MIN_MEM_SIZE           0
   #define JPEG_DEC_ENC_PANORAMA_TOTAL_EXT_MAX_MEM_SIZE           0

#else

   #if defined(MT6235) || defined(MT6235B) || defined(MT6250) || defined(MT6260)
      /// SW Encoder + SW Decoder
      #include "jpeg_panorama_mem_6235_series.h"

   #elif defined(MT6236) || defined(MT6236B)
      /// HW Encoder + SW Decoder
      #include "jpeg_panorama_mem_6236_series.h"

   #elif defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A) || defined(MT6276) || defined(MT6256)
      /// HW Encoder + HW Decoder
      #include "jpeg_panorama_mem_6238_series.h"

   #elif defined(MT6255) || defined(MT6922)
      /// Hybrid HW Encoder + HW Decoder
      #include "jpeg_panorama_mem_6255_series.h"
      
   /// #elif defined(MT6516) || defined(MT6251)
   /// #if defined(MT6253T) || defined(MT6253) || defined(MT6253D) || defined(MT6253E)  || defined(MT6253L) || defined(MT6252) || defined(MT6252H)

   #else
      #error "The chip do not support JPEG PANORAMA"
   #endif   ///End of all chips

#endif

#endif
