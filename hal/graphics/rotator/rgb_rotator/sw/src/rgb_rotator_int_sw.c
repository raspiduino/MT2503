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
 *   rgb_rotator_int_sw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   RGB Rotator
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

#include "rotator_enum.h"

#include "drv_features_rotator.h"
#include "rgb_rotator_structure.h"

#include "sw_rgb_rotator_gray.h"
#include "sw_rgb_rotator_rgb565.h"
#include "sw_rgb_rotator_rgb888.h"
#include "sw_rgb_rotator_argb8888.h"
#include "sw_rgb_rotator_argb6666.h"


ROTATOR_STATUS_ENUM sw_rgb_rotator_query_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                           kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   kal_uint32 size = 0;

   #if defined(SW_ROTATOR_WITH_INTERNAL_MEMORY)
   {
      const int srcWidth = handle->srcWidth;
      const int dstWidth = handle->dstWidth;

      if ((ROTATOR_CW_ROTATE_ANGLE_000 == (handle->rotation)) ||
          (ROTATOR_CW_ROTATE_ANGLE_MIRROR_180 == (handle->rotation)))
      {
          size = 0;           // rotation 0 and rotation 180 mirror use memcpy and don't have to use internal memory
      }
      else
      {
         switch(handle->srcColorFormat)
         {
            case ROTATOR_COLOR_FORMAT_ENUM_GRAY:
               size = 0;
            break;
            case ROTATOR_COLOR_FORMAT_ENUM_RGB565:
               size = (srcWidth << 1);
            break;
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_RGB888)
               case ROTATOR_COLOR_FORMAT_ENUM_RGB888:
               case ROTATOR_COLOR_FORMAT_ENUM_BGR888:
                  size = (srcWidth * 3 - (srcWidth * 3) % 12);    // 12 bytes alignment
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB8888)
               case ROTATOR_COLOR_FORMAT_ENUM_ARGB8888:
               case ROTATOR_COLOR_FORMAT_ENUM_PARGB8888:
                  /// ARGB8888 doesn't support internal memory speed-up
                  size = 0;
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB6666)
               case ROTATOR_COLOR_FORMAT_ENUM_ARGB6666:
               case ROTATOR_COLOR_FORMAT_ENUM_PARGB6666:
                  /// ARGB6666 doesn't support internal memory speed-up
                  size = 0;
               break;
            #endif
            default:
              return ROTATOR_STATUS_NOT_SUPPORT_COLOR_FORMAT;
         }

      }
   }
   #else
      size = 0;
   #endif

   (*extMemBest) = 0;
   (*extMemMin) = 0;
   (*intMemBest) = size;
   (*intMemMin) = size;

   return ROTATOR_STATUS_OK;
}




ROTATOR_STATUS_ENUM sw_rgb_rotator_set_working_memory(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   #if defined(SW_ROTATOR_WITH_INTERNAL_MEMORY)
   {
      kal_uint32 size = handle->intMemorySize;
      kal_uint32 addr = handle->intMemoryAddr;
      const int srcWidth = handle->srcWidth;

      if(!((ROTATOR_CW_ROTATE_ANGLE_000 == (handle->rotation)) ||
          (ROTATOR_CW_ROTATE_ANGLE_MIRROR_180 == (handle->rotation))))
      {
         switch(handle->srcColorFormat)
         {
            case ROTATOR_COLOR_FORMAT_ENUM_GRAY:
               size = 0;
               addr = NULL;
            break;
            case ROTATOR_COLOR_FORMAT_ENUM_RGB565:
               if(size < 32) // 16 pixels
               {
                  // too small buffer for speed-up
                  size = 0;
                  addr = NULL;
               }
               else if (size >= (srcWidth << 1))
               {
                  size = srcWidth << 1;
               }
               else
               {
                  // if the buffer width is even, it can have better performance
                  size &=  0xFFFFFFFC;
               }
            break;
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_RGB888)
               case ROTATOR_COLOR_FORMAT_ENUM_RGB888:
               case ROTATOR_COLOR_FORMAT_ENUM_BGR888:
                  if(size < 36) // 11 pixels
                  {
                     // too small buffer for speed-up
                     size = 0;
                     addr = NULL;
                  }
                  else if (size >= (srcWidth * 3))
                  {
                      // 12 bytes alignment
                     size = srcWidth * 3 - srcWidth % 12;
                  }
                  else
                  {
                     // 12 bytes alignment
                     size = size - size % 12;
                  }
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB8888)
               case ROTATOR_COLOR_FORMAT_ENUM_ARGB8888:
               case ROTATOR_COLOR_FORMAT_ENUM_PARGB8888:
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB6666)
               case ROTATOR_COLOR_FORMAT_ENUM_ARGB6666:
               case ROTATOR_COLOR_FORMAT_ENUM_PARGB6666:
               break;
            #endif
            default:
              return ROTATOR_STATUS_NOT_SUPPORT_COLOR_FORMAT;
         }
      }

      handle->intMemoryAddr = addr;
      handle->intMemorySize = size;
   }
   #else

   #endif

   return ROTATOR_STATUS_OK;
}





ROTATOR_STATUS_ENUM sw_rgb_rotator_start(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   ROTATOR_STATUS_ENUM status = ROTATOR_STATUS_OK;
   
   switch(handle->srcColorFormat)
   {
      case ROTATOR_COLOR_FORMAT_ENUM_RGB565:
      {
         switch(handle->rotation)
         {
            case ROTATOR_CW_ROTATE_ANGLE_000:
            {
               status = swRGBRotator000RGB565ToRGB565(handle);
            }
            break;
            case ROTATOR_CW_ROTATE_ANGLE_090:
            {
               status = swRGBRotator090RGB565ToRGB565(handle);
            }
            break;
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
               case ROTATOR_CW_ROTATE_ANGLE_180:
               {
                  status = swRGBRotator180RGB565ToRGB565(handle);
               }
               break;
            #endif
            case ROTATOR_CW_ROTATE_ANGLE_270:
            {
               status = swRGBRotator270RGB565ToRGB565(handle);
            }
            break;
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
               {
                  status = swRGBRotatorMirror000RGB565ToRGB565(handle);
               }
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
               {
                  status = swRGBRotatorMirror090RGB565ToRGB565(handle);
               }
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
               {
                  status = swRGBRotatorMirror180RGB565ToRGB565(handle);
               }
               break;
            #endif
            #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
               {
                  status = swRGBRotatorMirror270RGB565ToRGB565(handle);
               }
               break;
            #endif
            default:
            {
               status = ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE;
            }
         }
      }
      break;
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_RGB888)
         case ROTATOR_COLOR_FORMAT_ENUM_RGB888:
         case ROTATOR_COLOR_FORMAT_ENUM_BGR888:
         {
            switch(handle->rotation)
            {
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swRGBRotator000RGB888ToRGB888(handle);
               }
               break;
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swRGBRotator090RGB888ToRGB888(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swRGBRotator180RGB888ToRGB888(handle);
                  }
                  break;
               #endif
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swRGBRotator270RGB888ToRGB888(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swRGBRotatorMirror000RGB888ToRGB888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swRGBRotatorMirror090RGB888ToRGB888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swRGBRotatorMirror180RGB888ToRGB888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swRGBRotatorMirror270RGB888ToRGB888(handle);
                  }
                  break;
               #endif
               default:
               {
                  status = ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE;
               }
            }
         }
         break;
      #endif
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB8888)
         case ROTATOR_COLOR_FORMAT_ENUM_ARGB8888:
         case ROTATOR_COLOR_FORMAT_ENUM_PARGB8888:
         {
            switch(handle->rotation)
            {
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swRGBRotator000ARGB8888ToARGB8888(handle);
               }
               break;
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swRGBRotator090ARGB8888ToARGB8888(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swRGBRotator180ARGB8888ToARGB8888(handle);
                  }
                  break;
               #endif
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swRGBRotator270ARGB8888ToARGB8888(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swRGBRotatorMirror000ARGB8888ToARGB8888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swRGBRotatorMirror090ARGB8888ToARGB8888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swRGBRotatorMirror180ARGB8888ToARGB8888(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swRGBRotatorMirror270ARGB8888ToARGB8888(handle);
                  }
                  break;
               #endif
               default:
               {
                  status = ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE;
               }
            }
         }
         break;
      #endif
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB6666)
         case ROTATOR_COLOR_FORMAT_ENUM_ARGB6666:
         case ROTATOR_COLOR_FORMAT_ENUM_PARGB6666:
         {
            switch(handle->rotation)
            {
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swRGBRotator000ARGB6666ToARGB6666(handle);
               }
               break;
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swRGBRotator090ARGB6666ToARGB6666(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swRGBRotator180ARGB6666ToARGB6666(handle);
                  }
                  break;
               #endif
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swRGBRotator270ARGB6666ToARGB6666(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swRGBRotatorMirror000ARGB6666ToARGB6666(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swRGBRotatorMirror090ARGB6666ToARGB6666(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swRGBRotatorMirror180ARGB6666ToARGB6666(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swRGBRotatorMirror270ARGB6666ToARGB6666(handle);
                  }
                  break;
               #endif
               default:
               {
                  status = ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE;
               }
            }
         }
         break;
      #endif
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_SRC_GRAY)
         case ROTATOR_COLOR_FORMAT_ENUM_GRAY:
         {            
            switch(handle->rotation)
            {
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swRGBRotator000GRAYToGRAY(handle);
               }
               break;
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swRGBRotator090GRAYToGRAY(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swRGBRotator180GRAYToGRAY(handle);
                  }
                  break;
               #endif
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swRGBRotator270GRAYToGRAY(handle);
               }
               break;
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swRGBRotatorMirror000GRAYToGRAY(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swRGBRotatorMirror090GRAYToGRAY(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swRGBRotatorMirror180GRAYToGRAY(handle);
                  }
                  break;
               #endif
               #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swRGBRotatorMirror270GRAYToGRAY(handle);
                  }
                  break;
               #endif
               default:
               {
                  status = ROTATOR_STATUS_NOT_SUPPORT_ROTATE_ANGLE;
               }
            }
         }
         break;
      #endif
      default:
        status = ROTATOR_STATUS_NOT_SUPPORT_COLOR_FORMAT;
   }
   return status;   
}
