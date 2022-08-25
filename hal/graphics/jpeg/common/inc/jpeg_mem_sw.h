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
 *   jpeg_mem_sw.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG codec unified interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_MEM_SW_H__
#define __JPEG_MEM_SW_H__

#include "drv_features_jpeg.h"
#include "jpeg_mem_int.h"

/// SW Encoder + SW Decoder
/// ******************************************************************SW Encoder******************************************************************
#if defined(__SW_JPEG_ENCODER_SUPPORT__)
   #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
      ///#include "swje_const_tables.h"
      ///#define JPEG_SW_ENC_BASIC_INT_MEM_SIZE          (((SWJE_HUFF_DC_BITS_BITS + 3) & 0xFFFFFFFC) * 2 +                \
      ///                                                ((SWJE_HUFF_DC_VAL_BITS + 3) & 0xFFFFFFFC) * 2 +                  \
      ///                                                ((SWJE_HUFF_DC_TRANSLATION_BITS * 2 + 3) & 0xFFFFFFFC) * 2 +      \
      ///                                                ((SWJE_HUFF_DC_TRANSLATION_BITS + 3) & 0xFFFFFFFC) * 2 +          \
      ///                                                ((SWJE_HUFF_AC_BITS_BITS + 3) & 0xFFFFFFFC) * 2 +                 \
      ///                                                ((SWJE_HUFF_AC_VAL_BITS + 3) & 0xFFFFFFFC) * 2 +                  \
      ///                                                ((SWJE_HUFF_AC_TRANSLATION_BITS * 2 + 3) & 0xFFFFFFFC) * 2 +      \
      ///                                                ((SWJE_HUFF_AC_TRANSLATION_BITS + 3) & 0xFFFFFFFC) * 2 +          \
      ///                                                64* 4)
      #define JPEG_SW_ENC_BASIC_INT_MEM_SIZE          (JPEG_SW_ENC_BASIC_STRUCTURE_MEM_SIZE + 2292 + 128 + 128 + 256 + 256 + (64 * 4) + (64 * 4))

      /// We may not get enough memory from MDP
      #define JPEG_SW_ENC_BASIC_EXT_MEM_SIZE          (0 + JPEG_SW_ENC_BASIC_INT_MEM_SIZE)

   #else
      #define JPEG_SW_ENC_BASIC_INT_MEM_SIZE          0
      #define JPEG_SW_ENC_BASIC_EXT_MEM_SIZE          (JPEG_SW_ENC_BASIC_STRUCTURE_MEM_SIZE +       \
                                                      128 + 128 + 256 + 256 + (64 * 4) + (64 * 4))
   #endif

   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)

      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
         #define JPEG_SW_ENC_RGB_TEMP_MIN_MEM_SIZE    (16 * 16 + 8 * 8 + 8 * 8 + 16 * 16 * 3)              ///3 means RGB888
      #else
         #define JPEG_SW_ENC_RGB_TEMP_MIN_MEM_SIZE    (16 * 16 + 8 * 8 + 8 * 8)
      #endif

      #define JPEG_SW_ENC_RGB_MAX_MEM_SIZE            (((((JPEG_SW_ENC_RGB_TEMP_MIN_MEM_SIZE * JPEG_MAX_WIDTH / 16) + 3) & 0xFFFFFFFC) * 2) + 0x3E8)
      #define JPEG_SW_ENC_RGB_MIN_MEM_SIZE            JPEG_SW_ENC_RGB_MAX_MEM_SIZE
   #else
      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
         #define JPEG_SW_ENC_RGB_MIN_MEM_SIZE         (16 * 16 + 8 * 8 + 8 * 8 + 16 * 16 * 3)              ///3 means RGB888
      #else
         #define JPEG_SW_ENC_RGB_MIN_MEM_SIZE         (16 * 16 + 8 * 8 + 8 * 8)
      #endif

      #define JPEG_SW_ENC_RGB_MAX_MEM_SIZE            (((JPEG_SW_ENC_RGB_MIN_MEM_SIZE * JPEG_MAX_WIDTH / 16) + 3) & 0xFFFFFFFC)
   #endif

   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
      #define JPEG_SW_ENC_YUV_TEMP_MIN_MEM_SIZE       (16 * 16 + 8 * 8 + 8 * 8)
      #define JPEG_SW_ENC_YUV_MAX_MEM_SIZE            (((JPEG_SW_ENC_YUV_TEMP_MIN_MEM_SIZE * JPEG_MAX_WIDTH / 16) * 2) + 0x3E8)
      #define JPEG_SW_ENC_YUV_MIN_MEM_SIZE            JPEG_SW_ENC_YUV_MAX_MEM_SIZE
   #else
      #define JPEG_SW_ENC_YUV_MIN_MEM_SIZE            (16 * 16 + 8 * 8 + 8 * 8)
      #define JPEG_SW_ENC_YUV_MAX_MEM_SIZE            (JPEG_SW_ENC_YUV_MIN_MEM_SIZE * JPEG_MAX_WIDTH / 16)
   #endif

   #define JPEG_SW_ENC_INT_MIN_MEM_SIZE               JPEG_SW_ENC_BASIC_INT_MEM_SIZE
   #define JPEG_SW_ENC_INT_MAX_MEM_SIZE               JPEG_SW_ENC_BASIC_INT_MEM_SIZE

   #if JPEG_SW_ENC_RGB_MIN_MEM_SIZE > JPEG_SW_ENC_YUV_MIN_MEM_SIZE
       #define JPEG_SW_ENC_EXT_MIN_MEM_SIZE           (JPEG_SW_ENC_BASIC_EXT_MEM_SIZE + JPEG_SW_ENC_RGB_MIN_MEM_SIZE)
   #else
       #define JPEG_SW_ENC_EXT_MIN_MEM_SIZE           (JPEG_SW_ENC_BASIC_EXT_MEM_SIZE + JPEG_SW_ENC_YUV_MIN_MEM_SIZE)
   #endif

   #if JPEG_SW_ENC_RGB_MAX_MEM_SIZE > JPEG_SW_ENC_YUV_MAX_MEM_SIZE
       #define JPEG_SW_ENC_EXT_MAX_MEM_SIZE           (JPEG_SW_ENC_BASIC_EXT_MEM_SIZE + JPEG_SW_ENC_RGB_MAX_MEM_SIZE)
   #else
       #define JPEG_SW_ENC_EXT_MAX_MEM_SIZE           (JPEG_SW_ENC_BASIC_EXT_MEM_SIZE + JPEG_SW_ENC_YUV_MAX_MEM_SIZE)
   #endif

#else
   #define JPEG_SW_ENC_INT_MIN_MEM_SIZE               0
   #define JPEG_SW_ENC_INT_MAX_MEM_SIZE               0
   #define JPEG_SW_ENC_EXT_MIN_MEM_SIZE               0
   #define JPEG_SW_ENC_EXT_MAX_MEM_SIZE               0
#endif /// __SW_JPEG_ENCODER_SUPPORT__
/// ******************************************************************SW Encoder******************************************************************

/// ******************************************************************SW Decoder******************************************************************
#define JPEG_SW_DEC_BASELINE_MIN_MEM_SIZE             (JPEG_SW_DEC_BASIC_STRUCTURE_MEM_SIZE +               													\
                                                       2444 * 2 +                                /* Huffman decode DC table size  */  \
                                                       3468 * 2 +                                /* Huffman decode AC table size  */ 	\
                                                       16 * 8 * 128 +                            /* Huffman decoder output buffer */ 	\
                                                       16 * 8 * 128 +                            /* Dequant & IDCT output buffer  */ 	\
                                                       JPEG_SW_DEC_WORKING_BUFFER_MARGIN         /* Extra working buffer margin   */  )
#define JPEG_SW_DEC_BASELINE_MAX_MEM_SIZE             JPEG_SW_DEC_BASELINE_MIN_MEM_SIZE

#define JPEG_SW_DEC_PROGRESSIVE_MIN_MEM_SIZE          (JPEG_SW_DEC_BASIC_STRUCTURE_MEM_SIZE +               													\
                                                       2444 * 12 +     													 /* Huffman decode DC table size */  	\
                                                       3468 * 12 +     													 /* Huffman decode AC table size  */  \
                                                       JPEG_DEC_MAX_PROG_MCU_PER_ROW * 8 * 128 + /* Huffman decoder output buffer */  \
                                                       JPEG_DEC_MAX_PROG_MCU_PER_ROW * 8 * 128 + /* Dequant & IDCT output buffer  */  \
                                                       JPEG_SW_DEC_WORKING_BUFFER_MARGIN				 /* Extra working buffer margin   */  )
#define JPEG_SW_DEC_PROGRESSIVE_MAX_MEM_SIZE          JPEG_SW_DEC_PROGRESSIVE_MIN_MEM_SIZE

#ifdef SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
   #define JPEG_SW_DEC_INT_MIN_MEM_SIZE               0
   #define JPEG_SW_DEC_INT_MAX_MEM_SIZE               0
   #define JPEG_SW_DEC_EXT_MIN_MEM_SIZE               (JPEG_SW_DEC_PROGRESSIVE_MIN_MEM_SIZE + JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE)
   #define JPEG_SW_DEC_EXT_MAX_MEM_SIZE               (JPEG_SW_DEC_PROGRESSIVE_MAX_MEM_SIZE + JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE)
#else
   #define JPEG_SW_DEC_INT_MIN_MEM_SIZE               0
   #define JPEG_SW_DEC_INT_MAX_MEM_SIZE               0
   #define JPEG_SW_DEC_EXT_MIN_MEM_SIZE               (JPEG_SW_DEC_BASELINE_MIN_MEM_SIZE + JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE)
   #define JPEG_SW_DEC_EXT_MAX_MEM_SIZE               (JPEG_SW_DEC_BASELINE_MAX_MEM_SIZE + JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE)
#endif  // __SW_JPEG_DECODER_SUPPORT_PROGRESSIVE__
/// ******************************************************************SW Decoder******************************************************************

#endif

