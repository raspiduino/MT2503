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
 *   yuv_rotator_int_sw.c
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
#include "kal_general_types.h"

#include "rotator_enum.h"

#include "drv_features_rotator.h"
#include "yuv_rotator_structure.h"
#include "sw_yuv_rotator_yuv420p.h"
#include "sw_yuv_rotator_uyvy422.h"
#include "sw_yuv_rotator_yuv420b4x4p.h"


ROTATOR_STATUS_ENUM sw_yuv_rotator_query_working_memory(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                                                           kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   (*extMemBest) = 0;
   (*extMemMin) = 0;
   (*intMemBest) = 0;
   (*intMemMin) = 0;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM sw_yuv_rotator_set_working_memory(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM sw_yuv_rotator_start(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   ROTATOR_STATUS_ENUM status = ROTATOR_STATUS_OK;
   
   switch(handle->srcColorFormat)
   {
      
      case ROTATOR_COLOR_FORMAT_ENUM_YUV420_P:
      {
         switch(handle->rotation)
         {
            case ROTATOR_CW_ROTATE_ANGLE_000:
            {
               status = swYUVRotator000YUV420PToYUV420P(handle);
            }
            break;
            
            case ROTATOR_CW_ROTATE_ANGLE_090:
            {
               status = swYUVRotator090YUV420PToYUV420P(handle);
            }
            break;
           #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
               case ROTATOR_CW_ROTATE_ANGLE_180:
               {
                  status = swYUVRotator180YUV420PToYUV420P(handle);
               }
               break;
            #endif
            case ROTATOR_CW_ROTATE_ANGLE_270:
            {
               status = swYUVRotator270YUV420PToYUV420P(handle);
            }
            break;
            #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
               {
                  status = swYUVRotatorMirror000YUV420PToYUV420P(handle);
               }
               break;
            #endif
            #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
               {
                  status = swYUVRotatorMirror090YUV420PToYUV420P(handle);
               }
               break;
            #endif
            #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
               {
                  status = swYUVRotatorMirror180YUV420PToYUV420P(handle);
               }
               break;
            #endif
            #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
               case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
               {
                  status = swYUVRotatorMirror270YUV420PToYUV420P(handle);
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
      #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_YUV420B4X4P)
         case ROTATOR_COLOR_FORMAT_ENUM_YUV420_B4x4_P:
         {
            {
               /// Not support pitch
               YUV_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
               YUV_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
               
               if(!(((srcWindow->startX) == 0) && ((srcWindow->startY) == 0)))
                  return ROTATOR_STATUS_NOT_SUPPORT_PITCH;
               if(!(((dstWindow->startX) == 0) && ((dstWindow->startY) == 0)))
                  return ROTATOR_STATUS_NOT_SUPPORT_PITCH;
               if(!(((srcWindow->width) == (handle->srcWidth)) && ((srcWindow->height) == (handle->srcHeight))))
                  return ROTATOR_STATUS_NOT_SUPPORT_PITCH;
               if(!(((dstWindow->width) == (handle->dstWidth)) && ((dstWindow->height) == (handle->dstHeight))))
                  return ROTATOR_STATUS_NOT_SUPPORT_PITCH;   
            }
            
            switch(handle->rotation)
            {
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swYUVRotator000YUV420B4x4PToYUV420B4x4P(handle);
               }
               break;
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swYUVRotator090YUV420B4x4PToYUV420B4x4P(handle);
               }
               break;
              #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swYUVRotator180YUV420B4x4PToYUV420B4x4P(handle);
                  }
                  break;
               #endif
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swYUVRotator270YUV420B4x4PToYUV420B4x4P(handle);
               }
               break;
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swYUVRotatorMirror000YUV420B4x4PToYUV420B4x4P(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swYUVRotatorMirror090YUV420B4x4PToYUV420B4x4P(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swYUVRotatorMirror180YUV420B4x4PToYUV420B4x4P(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swYUVRotatorMirror270YUV420B4x4PToYUV420B4x4P(handle);
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
      #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422)
         case ROTATOR_COLOR_FORMAT_ENUM_UYVY422:
         {
            {
               /// Not support pitch
               YUV_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
               YUV_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
                  
               if((0 != ((srcWindow->width) & 0x1)) || (0 != ((dstWindow->width) & 0x1)))
               {
                  return ROTATOR_STATUS_SW_ERROR;
               }
      
            }
            
            switch(handle->rotation)
            {
              #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_000)
               case ROTATOR_CW_ROTATE_ANGLE_000:
               {
                  status = swYUVRotator000UYVY422ToUYVY422(handle);
               }
               break;
			  #endif
              #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_090)
               case ROTATOR_CW_ROTATE_ANGLE_090:
               {
                  status = swYUVRotator090UYVY422ToUYVY422(handle);
               }
               break;
			  #endif
              #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_180)
                  case ROTATOR_CW_ROTATE_ANGLE_180:
                  {
                     status = swYUVRotator180UYVY422ToUYVY422(handle);
                  }
                  break;
               #endif
              #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_270)
               case ROTATOR_CW_ROTATE_ANGLE_270:
               {
                  status = swYUVRotator270UYVY422ToUYVY422(handle);
               }
               break;
              #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_MIRROR_000)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
                  {
                     status = swYUVRotatorMirror000UYVY422ToUYVY422(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_MIRROR_090)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
                  {
                     status = swYUVRotatorMirror090UYVY422ToUYVY422(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_MIRROR_180)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
                  {
                     status = swYUVRotatorMirror180UYVY422ToUYVY422(handle);
                  }
                  break;
               #endif
               #if defined(YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422_ROTATE_ANGLE_MIRROR_270)
                  case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
                  {
                     status = swYUVRotatorMirror270UYVY422ToUYVY422(handle);
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
