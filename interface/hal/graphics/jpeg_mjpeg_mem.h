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
 *   jpeg_mjpeg_mem.h
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
#ifndef __JPEG_MJPEG_MEM_H__
#define __JPEG_MJPEG_MEM_H__

#include "drv_features_jpeg.h"

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX
#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN


#if defined(JPEG_CODEC_STANDALONE)
   #define RESOLUTION_128x96               0
   #define RESOLUTION_176x144              1
   #define RESOLUTION_320x240              2
   #define RESOLUTION_400x240              3
   #define RESOLUTION_352x288              4
   #define RESOLUTION_432x240              5
   #define RESOLUTION_480x320              6
   #define RESOLUTION_640x368              7
   #define RESOLUTION_640x480              8
   #define RESOLUTION_720x480              9
   #define RESOLUTION_800x480              10
   #define RESOLUTION_848x480              11
   #define RESOLUTION_720x576              12
   #define RESOLUTION_800x608              13
   #define RESOLUTION_1024x768             14
   #define RESOLUTION_1280x720             15
   #define RESOLUTION_1280x960             16
   #define RESOLUTION_1280x1024            17
   #define RESOLUTION_1408x1152            18
   #define RESOLUTION_1600x1200            19
   #define RESOLUTION_1920x1088            20


   #define MJPEG_ENC_SUPPORT_RESOLUTION    RESOLUTION_480x320
#endif

#if !(defined(MT6223)||defined(MT6223P)||defined(MT6516))
   #include "sw_video_encode_custom.h"   /// mcu\hal\video\custom

   #if (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_128x96)
      #define JPEG_MJPEG_MAX_WIDTH        128
      #define JPEG_MJPEG_MAX_HEIGHT       96
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_176x144)
      #define JPEG_MJPEG_MAX_WIDTH        176
      #define JPEG_MJPEG_MAX_HEIGHT       144
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_320x240)
      #define JPEG_MJPEG_MAX_WIDTH        320
      #define JPEG_MJPEG_MAX_HEIGHT       240
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_400x240)
      #define JPEG_MJPEG_MAX_WIDTH        400
      #define JPEG_MJPEG_MAX_HEIGHT       240
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_352x288)
      #define JPEG_MJPEG_MAX_WIDTH        352
      #define JPEG_MJPEG_MAX_HEIGHT       288
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_432x240)
      #define JPEG_MJPEG_MAX_WIDTH        432
      #define JPEG_MJPEG_MAX_HEIGHT       240
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_480x320)
      #define JPEG_MJPEG_MAX_WIDTH        480
      #define JPEG_MJPEG_MAX_HEIGHT       320
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x368)
      #define JPEG_MJPEG_MAX_WIDTH        640
      #define JPEG_MJPEG_MAX_HEIGHT       368
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x480)
      #define JPEG_MJPEG_MAX_WIDTH        640
      #define JPEG_MJPEG_MAX_HEIGHT       480
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x480)
      #define JPEG_MJPEG_MAX_WIDTH        720
      #define JPEG_MJPEG_MAX_HEIGHT       480
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x480)
      #define JPEG_MJPEG_MAX_WIDTH        800
      #define JPEG_MJPEG_MAX_HEIGHT       480
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_848x480)
      #define JPEG_MJPEG_MAX_WIDTH        848
      #define JPEG_MJPEG_MAX_HEIGHT       480
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x576)
      #define JPEG_MJPEG_MAX_WIDTH        720
      #define JPEG_MJPEG_MAX_HEIGHT       576
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x608)
      #define JPEG_MJPEG_MAX_WIDTH        800
      #define JPEG_MJPEG_MAX_HEIGHT       608
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
      #define JPEG_MJPEG_MAX_WIDTH        1024
      #define JPEG_MJPEG_MAX_HEIGHT       768
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
      #define JPEG_MJPEG_MAX_WIDTH        1280
      #define JPEG_MJPEG_MAX_HEIGHT       720
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x960)
      #define JPEG_MJPEG_MAX_WIDTH        1280
      #define JPEG_MJPEG_MAX_HEIGHT       960
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x1024)
      #define JPEG_MJPEG_MAX_WIDTH        1280
      #define JPEG_MJPEG_MAX_HEIGHT       1024
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1408x1152)
      #define JPEG_MJPEG_MAX_WIDTH        1408
      #define JPEG_MJPEG_MAX_HEIGHT       1152
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1600x1200)
      #define JPEG_MJPEG_MAX_WIDTH        1600
      #define JPEG_MJPEG_MAX_HEIGHT       1200
   #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1920x1088)
      #define JPEG_MJPEG_MAX_WIDTH        1920
      #define JPEG_MJPEG_MAX_HEIGHT       1088
   #else
      #error "The MJPEG do not support this resolution now"
   #endif

#endif

#define JPEG_SW_ENC_MJPEG_EXIF_EXT_MAX_MEM_SIZE 0

#if defined(__L1_STANDALONE__) || defined(__UL1_STANDALONE__)

   #define JPEG_ENC_MJPEG_INT_MIN_MEM_SIZE                            0
   #define JPEG_ENC_MJPEG_INT_MAX_MEM_SIZE                            0
   #define JPEG_ENC_MJPEG_EXT_MIN_MEM_SIZE                            0
   #define JPEG_ENC_MJPEG_EXT_MAX_MEM_SIZE                            0


   #define JPEG_DEC_MJPEG_INT_MIN_MEM_SIZE                            0
   #define JPEG_DEC_MJPEG_INT_MAX_MEM_SIZE                            0
   #define JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE                            0
   #define JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE                            0

   #define JPEG_DEC_ENC_MJPEG_TOTAL_INT_MIN_MEM_SIZE                  0
   #define JPEG_DEC_ENC_MJPEG_TOTAL_INT_MAX_MEM_SIZE                  0
   #define JPEG_DEC_ENC_MJPEG_TOTAL_EXT_MIN_MEM_SIZE                  0
   #define JPEG_DEC_ENC_MJPEG_TOTAL_EXT_MAX_MEM_SIZE                  0


   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_EXCELLENT     0
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_GOOD          0
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_FAIR          0
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_LOW           0
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_POOR          0

#else

   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_EXCELLENT     ((JPEG_MJPEG_MAX_WIDTH * JPEG_MJPEG_MAX_HEIGHT * 36) >> 5)
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_GOOD          ((JPEG_MJPEG_MAX_WIDTH * JPEG_MJPEG_MAX_HEIGHT * 33) >> 5)
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_FAIR          ((JPEG_MJPEG_MAX_WIDTH * JPEG_MJPEG_MAX_HEIGHT * 30) >> 5)
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_LOW           ((JPEG_MJPEG_MAX_WIDTH * JPEG_MJPEG_MAX_HEIGHT * 15) >> 5)
   #define JPEG_ENC_MJPEG_DST_MAX_MEM_SIZE_WITH_QUALITY_POOR          ((JPEG_MJPEG_MAX_WIDTH * JPEG_MJPEG_MAX_HEIGHT * 9) >> 5)

   #if defined(MT6235) || defined(MT6235B) || defined(MT6253T) || defined(MT6253) || defined(MT6253E)  || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      /// use SW encoder/decoder only
      #include "jpeg_mjpeg_mem_6235_series.h"

   #elif defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A) 
      /// use SW encoder/decoder only
      #include "jpeg_mjpeg_mem_6236_series.h"

   #elif defined(MT6256)
      /// use HW encoder/decoder only
      #include "jpeg_mjpeg_mem_6238_series.h"

   #elif defined(MT6255) || defined(MT6922)
      /// use Hybrid HW encoder/decoder only
      #include "jpeg_mjpeg_mem_6255_series.h"

   #elif defined(MT6516) || defined(MT6251) || defined(MT6225) || defined(MT6223)||defined(MT6223P)

   #else
      #error "The chip do not support JPEG V2 MJPEG Encode and Decode"
   #endif   ///End of all chips

#endif

#endif

