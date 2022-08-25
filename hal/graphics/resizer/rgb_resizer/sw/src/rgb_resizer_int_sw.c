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
 *   rgb_resizer_int_sw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   RGB Resizer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#if defined(RESIZER_STANDALONE)
   #include "stdio.h"
   #include "stdlib.h"
   #include <string.h>

   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      ///#include "mmu.h"
      #include "cache_sw.h"
   #endif
#endif


#include "drv_features_resizer.h"
#include "resizer_enum.h"
#include "rgb_resizer_structure.h"

///#include "sw_rgb_resizer_srcacc.h"
#include "sw_rgb_resizer_bilinear.h"
#include "sw_rgb_resizer_nearest.h"
#include "sw_rgb_resizer_box.h"

RESIZER_STATUS_ENUM sw_rgb_resizer_query_working_memory(RGB_RESIZER_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                           kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   ///#ifndef RGB_RESIZER_SW_SUPPORT_WITH_BOX_RESIZER
   ///   const int dstPitch = handle->dstWidth;
   ///#endif
   kal_uint32 size = 0;

   switch(handle->quality)
   {
      case RESIZER_QUALITY_HIGH:
      {
         ///#ifdef RGB_RESIZER_SW_SUPPORT_WITH_BOX_RESIZER
         ///
         ///#else
         ///   switch(handle->dstColorFormat)
         ///   {
         ///      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         ///      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
         ///         case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         ///         case RESIZER_COLOR_FORMAT_ENUM_BGR888:
         ///      #endif
         ///
         ///         /// we can set size = dst_width * 16 + src_width * 4; , But this will waste a lot of memory.
         ///         /// So we add a trick for 16. 16 is used to do the temporary buffer to prevent the buufer to be over-write
         ///         size = dstPitch * 16 + 16;
         ///      break;
         ///      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
         ///         case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
         ///         case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
         ///            /// we can set size = dst_width * 16 + src_width * 4; , But this will waste a lot of memory.
         ///            /// So we add a trick for 16. 16 is used to do the temporary buffer to prevent the buufer to be over-write
         ///            size = dstPitch * 20 + 16;
         ///         break;
         ///      #endif
         ///      default:
         ///        return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
         ///   }
         ///#endif
      }
      break;
      case RESIZER_QUALITY_MEDIUM:
      break;
      case RESIZER_QUALITY_LOW:
      break;
      default:
         ASSERT(0);
   }

   //#if defined(__ARM9_DCACHEABLE__) && defined(__MTK_TARGET__)
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      size = (size + CPU_CACHE_LINE_SIZE_MASK) & (~CPU_CACHE_LINE_SIZE_MASK);
   #endif

   (*extMemBest) = size;
   (*extMemMin) = size;
   (*intMemBest) = 0;
   (*intMemMin) = 0;

   return RESIZER_STATUS_OK;
}



#ifdef RGB_RESIZER_SW_SUPPORT_WITH_BOX_RESIZER
RESIZER_STATUS_ENUM sw_rgb_resizer_box(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   switch(handle->srcColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         swRGBResizerBoxRGB565ToRGB565(handle);
      break;
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
         case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         case RESIZER_COLOR_FORMAT_ENUM_BGR888:
           swRGBResizerBoxRGB888ToRGB888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
            swRGBResizerBoxARGB8888ToARGB8888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB6666)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB6666:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB6666:
            swRGBResizerBoxARGB6666ToARGB6666(handle);
         break;
      #endif
      default:
        return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
   }

   return RESIZER_STATUS_OK;
}

#else



RESIZER_STATUS_ENUM sw_rgb_resizer_srcacc(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   {
      /// Set working buffer
      unsigned char *tmpBuffer;

      tmpBuffer = (unsigned char *)(handle->extMemoryAddr);
      handle->srcaccAccuPtr = tmpBuffer;

      switch(handle->dstColorFormat)
      {
         case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
            case RESIZER_COLOR_FORMAT_ENUM_RGB888:
            case RESIZER_COLOR_FORMAT_ENUM_BGR888:
         #endif
            tmpBuffer += ((handle->dstWidth) * 12);
         break;
         #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
            case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
            case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
               tmpBuffer += ((handle->dstWidth) * 16);
            break;
         #endif
         default:
            return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
      }

      handle->srcaccRowPtr = tmpBuffer;
   }

   switch(handle->srcColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         swRGBResizerSrcaccRGB565ToRGB565(handle);
      break;
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
         case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         case RESIZER_COLOR_FORMAT_ENUM_BGR888:
           swRGBResizerSrcaccRGB888ToRGB888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
            swRGBResizerSrcaccARGB8888ToARGB8888(handle);
         break;
      #endif
      default:
        return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
   }

   return RESIZER_STATUS_OK;
}

#endif



RESIZER_STATUS_ENUM sw_rgb_resizer_bilinear(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   switch(handle->srcColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         swRGBResizerBilinearRGB565ToRGB565(handle);
      break;
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
         case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         case RESIZER_COLOR_FORMAT_ENUM_BGR888:
            swRGBResizerBilinearRGB888ToRGB888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
            swRGBResizerBilinearARGB8888ToARGB8888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB6666)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB6666:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB6666:
            swRGBResizerBilinearARGB6666ToARGB6666(handle);
         break;
      #endif      
      default:
        return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
   }

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM sw_rgb_resizer_nearest(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   switch(handle->srcColorFormat)
   {
      case RESIZER_COLOR_FORMAT_ENUM_RGB565:
         swRGBResizerNearestRGB565ToRGB565(handle);
      break;
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_RGB888)
         case RESIZER_COLOR_FORMAT_ENUM_RGB888:
         case RESIZER_COLOR_FORMAT_ENUM_BGR888:
            swRGBResizerNearestRGB888ToRGB888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB8888)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB8888:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB8888:
            swRGBResizerNearestARGB8888ToARGB8888(handle);
         break;
      #endif
      #if defined(RGB_RESIZER_SW_SUPPORT_WITH_SRC_ARGB6666)
         case RESIZER_COLOR_FORMAT_ENUM_ARGB6666:
         case RESIZER_COLOR_FORMAT_ENUM_PARGB6666:
            swRGBResizerNearestARGB6666ToARGB6666(handle);
         break;
      #endif
      default:
        return RESIZER_STATUS_NOT_SUPPORT_COLOR_FORMAT;
   }

   return RESIZER_STATUS_OK;
}
