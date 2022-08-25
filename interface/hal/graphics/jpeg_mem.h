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
 *   jpeg_mem.h
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
#ifndef __JPEG_MEM_H__
#define __JPEG_MEM_H__

#include "drv_features_jpeg.h"
#include "jpeg_mem_int.h"

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX
#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN


#if !(defined(MT6223) || defined(MT6223P) || defined(MT6516) || defined(MT6573) || defined(MT6575))

   #define UNKNOWN_MEM_SIZE                                     0
   #define JPEG_01M_MAX_WIDTH                                   352
   #define JPEG_03M_MAX_WIDTH                                   640
   #define JPEG_1M_MAX_WIDTH                                    1280
   #define JPEG_2M_MAX_WIDTH                                    1600
   #define JPEG_3M_MAX_WIDTH                                    2048
   #define JPEG_5M_MAX_WIDTH                                    2592
   #define JPEG_8M_MAX_WIDTH                                    3264   //3264 * 2448

   #if defined(ISP_SUPPORT)
      #if !defined(JPEG_CODEC_STANDALONE)
         #include "sensor_capability.h"
      #endif
      #if (defined(__YUVCAM_INTERPOLATION_SW__)||defined(__YUVCAM_INTERPOLATION_HW__))
         #if defined(__IMAGE_SENSOR_01M__)
            #define JPEG_MAX_WIDTH                           JPEG_03M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_03M__)
            #define JPEG_MAX_WIDTH                           JPEG_1M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_1M__)
            #define JPEG_MAX_WIDTH                           JPEG_2M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_2M__)
            #define JPEG_MAX_WIDTH                           JPEG_3M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_3M__)
            #define JPEG_MAX_WIDTH                           JPEG_5M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_5M__)
            #define JPEG_MAX_WIDTH                           JPEG_8M_MAX_WIDTH
         #else
            #error "The interpolation for this resolution doesn't support now"
         #endif

      #else
         #if defined(__IMAGE_SENSOR_01M__)
            #define JPEG_MAX_WIDTH                           JPEG_01M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_03M__)
            #define JPEG_MAX_WIDTH                           JPEG_03M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_1M__)
            #define JPEG_MAX_WIDTH                           JPEG_1M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_2M__)
            #define JPEG_MAX_WIDTH                           JPEG_2M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_3M__)
            #define JPEG_MAX_WIDTH                           JPEG_3M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_5M__)
            #define JPEG_MAX_WIDTH                           JPEG_5M_MAX_WIDTH
         #elif defined(__IMAGE_SENSOR_8M__)
            #define JPEG_MAX_WIDTH                           JPEG_8M_MAX_WIDTH
         #else
            #define JPEG_MAX_WIDTH                           JPEG_03M_MAX_WIDTH
         #endif

      #endif
   #else

      #define JPEG_MAX_WIDTH                                 JPEG_03M_MAX_WIDTH
   #endif
#endif

/// Med is define in med_global.h
/// MAX_MED_JPG_DEC_EXT_MEM_SIZE (MAX_IMG_DEC_EXT_MEM_SIZE+MAX_IMG_DEC_FILE_BUFFER_LEN)
/// GDI will use MAX_PROG_JPG_DEC_EXT_MEM_SIZE and MAX_IMG_DEC_EXT_MEM_SIZE
/// (GDI_IMAGE_JPEG_USE_LESS_BUF_SIZE ?)

#if defined(__L1_STANDALONE__) || defined(__UL1_STANDALONE__)

   #define JPEG_HW_ENC_INT_MIN_MEM_SIZE                         0
   #define JPEG_HW_ENC_INT_MAX_MEM_SIZE                         0
   #define JPEG_HW_ENC_EXT_MIN_MEM_SIZE                         0
   #define JPEG_HW_ENC_EXT_MAX_MEM_SIZE                         0

   #define JPEG_HW_DEC_INT_MIN_MEM_SIZE                         0
   #define JPEG_HW_DEC_INT_MAX_MEM_SIZE                         0
   #define JPEG_HW_DEC_EXT_MIN_MEM_SIZE                         0
   #define JPEG_HW_DEC_EXT_MAX_MEM_SIZE                         0
      
   #define JPEG_ENC_INT_MIN_MEM_SIZE                            0
   #define JPEG_ENC_INT_MAX_MEM_SIZE                            0
   #define JPEG_ENC_EXT_MIN_MEM_SIZE                            0
   #define JPEG_ENC_EXT_MAX_MEM_SIZE                            0

   #define JPEG_DEC_INT_MIN_MEM_SIZE                            0
   #define JPEG_DEC_INT_MAX_MEM_SIZE                            0
   #define JPEG_DEC_EXT_MIN_MEM_SIZE                            0
   #define JPEG_DEC_EXT_MAX_MEM_SIZE                            0

   #define JPEG_DEC_ENC_TOTAL_INT_MIN_MEM_SIZE                  0
   #define JPEG_DEC_ENC_TOTAL_INT_MAX_MEM_SIZE                  0
   #define JPEG_DEC_ENC_TOTAL_EXT_MIN_MEM_SIZE                  0
   #define JPEG_DEC_ENC_TOTAL_EXT_MAX_MEM_SIZE                  0

   #define JPEG_ENC_EXIF_MAX_MEM_SIZE                           0

#else
   #if defined(MT6235) || defined(MT6235B) || defined(MT6253T) || defined(MT6253) || defined(MT6253E)  || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      /// SW Encoder + SW Decoder
      #include "jpeg_mem_6235_series.h"

   #elif defined(MT6236) || defined(MT6236B)
      /// HW Encoder + SW Decoder
      #include "jpeg_mem_6236_series.h"

   #elif defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A) || defined(MT6276) || defined(MT6256)
      /// HW Encoder + HW Decoder
      #include "jpeg_mem_6238_series.h"

   #elif defined(MT6255) || defined(MT6922)
      /// Hybrid HW Encoder + Hybrid HW Decoder
      #include "jpeg_mem_6255_series.h"

   #elif defined(MT6516) || defined(MT6251) || defined(MT6573) || defined(MT6575)
      #define JPEG_HW_ENC_INT_MIN_MEM_SIZE                  0
      #define JPEG_HW_ENC_INT_MAX_MEM_SIZE                  0
      #define JPEG_HW_ENC_EXT_MIN_MEM_SIZE                  0
      #define JPEG_HW_ENC_EXT_MAX_MEM_SIZE                  0
      
      #define JPEG_HW_DEC_INT_MIN_MEM_SIZE                  0
      #define JPEG_HW_DEC_INT_MAX_MEM_SIZE                  0
      #define JPEG_HW_DEC_EXT_MIN_MEM_SIZE                  0
      #define JPEG_HW_DEC_EXT_MAX_MEM_SIZE                  0

   #else
      #error "The chip do not support JPEG Encode and Decode"
   #endif   ///End of all chips

#endif
#endif   // __JPEG_CODEC_MEM_H__




