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
 *   jaia_mem.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   ##
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
#ifndef __JAIA_MEM_H__
#define __JAIA_MEM_H__

#if defined(__L1_STANDALONE__) || defined(__UL1_STANDALONE__)
   #define JAIA_STRUCT_BUF_SIZE                 0
   #define JAIA_TEMP_BUF_SIZE                   0
   #define JAIA_EXIF_BUF_SIZE                   0
   #define JAIA_DEC_BUF_SIZE                    0
   
   #define JAIA_FILE_COPY_BUF_SIZE              0
   #define JAIA_ENC_WORKING_BUF_SIZE            0
   #define JAIA_EXIF_DATA_BUF_SIZE              0
   
   #define JAIA_QVI_DESTINATION_BUF_SIZE        0
   #define JAIA_TN_DESTINATION_BUF_SIZE         0
   
   #define JAIA_WORKSPACE_BUF_BASIC_SIZE        0
   #define JAIA_WORKING_BUF_BASIC_SIZE          0
   #define JAIA_WORKING_BUF_QVI_SIZE            0
   #define JAIA_WORKING_BUF_TN_SIZE             0
   #define JAIA_WORKING_BUF_FULL_SIZE           0
   
   #define JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE                     0
   #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE                    0
#else

   #include "drv_features_jpeg.h"
   #include "jpeg_mem_int.h"
   #include "jpeg_mem.h"
   
   #if defined(__PANORAMA_VIEW_SUPPORT__) || defined(__AUTOCAP_PANORAMA_SUPPORT__)
      #include "jpeg_panorama_mem.h"
   #endif
   
   #if defined(__MMI_MAINLCD_96X64__)
       #define JAIA_ENC_QVI_MAX_WIDTH           96
       #define JAIA_ENC_QVI_MAX_HEIGHT          64
   #elif defined(__MMI_MAINLCD_128X128__)
       #define JAIA_ENC_QVI_MAX_WIDTH           128
       #define JAIA_ENC_QVI_MAX_HEIGHT          128
   #elif defined(__MMI_MAINLCD_128X160__)
       #define JAIA_ENC_QVI_MAX_WIDTH           128
       #define JAIA_ENC_QVI_MAX_HEIGHT          160
   #elif defined(__MMI_MAINLCD_160X128__)
       #define JAIA_ENC_QVI_MAX_WIDTH           160
       #define JAIA_ENC_QVI_MAX_HEIGHT          128
   #elif defined(__MMI_MAINLCD_176X220__)
       #define JAIA_ENC_QVI_MAX_WIDTH           176
       #define JAIA_ENC_QVI_MAX_HEIGHT          220
   #elif defined(__MMI_MAINLCD_220X176__)
       #define JAIA_ENC_QVI_MAX_WIDTH           220
       #define JAIA_ENC_QVI_MAX_HEIGHT          176
   #elif defined(__MMI_MAINLCD_240X320__)
       #define JAIA_ENC_QVI_MAX_WIDTH           240
       #define JAIA_ENC_QVI_MAX_HEIGHT          320
   #elif defined(__MMI_MAINLCD_320X240__)
       #define JAIA_ENC_QVI_MAX_WIDTH           320
       #define JAIA_ENC_QVI_MAX_HEIGHT          240
   #elif defined(__MMI_MAINLCD_240X400__)
       #define JAIA_ENC_QVI_MAX_WIDTH           240
       #define JAIA_ENC_QVI_MAX_HEIGHT          400
   #elif defined(__MMI_MAINLCD_400X240__)
       #define JAIA_ENC_QVI_MAX_WIDTH           400
       #define JAIA_ENC_QVI_MAX_HEIGHT          240
   #elif defined(__MMI_MAINLCD_240X432__)
       #define JAIA_ENC_QVI_MAX_WIDTH           240
       #define JAIA_ENC_QVI_MAX_HEIGHT          432
   #elif defined(__MMI_MAINLCD_432X240__)
       #define JAIA_ENC_QVI_MAX_WIDTH           432
       #define JAIA_ENC_QVI_MAX_HEIGHT          240
   #elif defined(__MMI_MAINLCD_320X480__)
       #define JAIA_ENC_QVI_MAX_WIDTH           320
       #define JAIA_ENC_QVI_MAX_HEIGHT          480
   #elif defined(__MMI_MAINLCD_480X320__)
       #define JAIA_ENC_QVI_MAX_WIDTH           480
       #define JAIA_ENC_QVI_MAX_HEIGHT          320  
   #elif defined(__MMI_MAINLCD_360X640__)
       #define JAIA_ENC_QVI_MAX_WIDTH           360
       #define JAIA_ENC_QVI_MAX_HEIGHT          640
   #elif defined(__MMI_MAINLCD_640X360__)
       #define JAIA_ENC_QVI_MAX_WIDTH           640
       #define JAIA_ENC_QVI_MAX_HEIGHT          360              
   #elif defined(__MMI_MAINLCD_480X800__)
       #define JAIA_ENC_QVI_MAX_WIDTH           480
       #define JAIA_ENC_QVI_MAX_HEIGHT          800
   #elif defined(__MMI_MAINLCD_800X480__)
       #define JAIA_ENC_QVI_MAX_WIDTH           800
       #define JAIA_ENC_QVI_MAX_HEIGHT          480
   #else
       // default as QVGA resolution
       #define JAIA_ENC_QVI_MAX_WIDTH           240
       #define JAIA_ENC_QVI_MAX_HEIGHT          320
   #endif
   
   
   // Structure buffer size
   #define JAIA_STRUCT_BUF_SIZE                 512
   #define JAIA_TEMP_BUF_SIZE                   128
   #define JAIA_EXIF_BUF_SIZE                   8192
   #define JAIA_DEC_BUF_SIZE                    (JPEG_DEC_FSAL_CACHE_SIZE + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE)
   
   // Data buffer size
   #define JAIA_FILE_COPY_BUF_SIZE              (2048 + 4)
   #define JAIA_EXIF_DATA_BUF_SIZE              (JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE)
   #if (JPEG_HW_ENC_EXT_MIN_MEM_SIZE >= JPEG_SW_ENC_EXT_MIN_MEM_SIZE)
      #define JAIA_ENC_WORKING_BUF_SIZE         JPEG_HW_ENC_EXT_MIN_MEM_SIZE
   #else
      #define JAIA_ENC_WORKING_BUF_SIZE         JPEG_SW_ENC_EXT_MIN_MEM_SIZE
   #endif
   
   // Destination buffer size
   #define JAIA_QVI_DESTINATION_BUF_SIZE        (JAIA_ENC_QVI_MAX_WIDTH * JAIA_ENC_QVI_MAX_HEIGHT * 3 / 2 + 1024)  // 1.5 * 1 (compression ratio)
   #define JAIA_TN_DESTINATION_BUF_SIZE         (160 * 120 * 3 / 2 + 1024)  // 1.5 * 1 (compression ratio)
   
   // JAIA workspace/working buffer size
   #define JAIA_WORKSPACE_BUF_BASIC_SIZE        (JAIA_STRUCT_BUF_SIZE + JAIA_TEMP_BUF_SIZE + JAIA_EXIF_BUF_SIZE + JAIA_DEC_BUF_SIZE + 32 * 4)
   #define JAIA_WORKING_BUF_BASIC_SIZE          (JAIA_WORKSPACE_BUF_BASIC_SIZE + JAIA_FILE_COPY_BUF_SIZE + JAIA_ENC_WORKING_BUF_SIZE + JAIA_EXIF_DATA_BUF_SIZE + 32 * 3)
   #define JAIA_WORKING_BUF_QVI_SIZE            (JAIA_WORKING_BUF_BASIC_SIZE + JAIA_QVI_DESTINATION_BUF_SIZE + 32)
   #define JAIA_WORKING_BUF_TN_SIZE             (JAIA_WORKING_BUF_BASIC_SIZE + JAIA_TN_DESTINATION_BUF_SIZE + 32)
   #define JAIA_WORKING_BUF_FULL_SIZE           (JAIA_WORKING_BUF_BASIC_SIZE + JAIA_QVI_DESTINATION_BUF_SIZE + JAIA_TN_DESTINATION_BUF_SIZE + 32 * 2)
   
   // Scenario
   #if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
      #define JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE            ((JAIA_WORKING_BUF_FULL_SIZE+31)&0xFFFFFFE0)
   #elif defined(__JPEG_THUMBNAIL_SUPPORT__)
      #define JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE            ((JAIA_WORKING_BUF_TN_SIZE+31)&0xFFFFFFE0)
   #else
      #define JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE            ((JAIA_WORKING_BUF_BASIC_SIZE+31)&0xFFFFFFE0)
   #endif
   
   #if defined(__PANORAMA_VIEW_SUPPORT__)
      #if (JAIA_WORKING_BUF_QVI_SIZE >= JPEG_DEC_ENC_PANORAMA_TOTAL_EXT_MIN_MEM_SIZE)
         #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE        JAIA_WORKING_BUF_QVI_SIZE
      #else
         #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE        JPEG_DEC_ENC_PANORAMA_TOTAL_EXT_MIN_MEM_SIZE
      #endif
   #elif defined(__AUTOCAP_PANORAMA_SUPPORT__)
      #if (JAIA_WORKING_BUF_QVI_SIZE >= JPEG_ENC_PANORAMA_YUV420_EXT_MIN_MEM_SIZE)
         #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE        JAIA_WORKING_BUF_QVI_SIZE
      #else
         #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE        JPEG_ENC_PANORAMA_YUV420_EXT_MIN_MEM_SIZE
      #endif
   #else
      #define JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE           0
   #endif

#endif


#endif  /// End of #ifndef __JAIA_MEM_H__
