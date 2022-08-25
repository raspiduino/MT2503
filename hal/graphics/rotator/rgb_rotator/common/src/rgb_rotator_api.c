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
 *   rgb_rotator_api.c
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
 * removed!
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

#include <string.h>

#include "drv_features_rotator.h"

#if defined(ROTATOR_STANDALONE)
   #include "stdio.h"
   #include "stdlib.h"

   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"

   #if defined(__MTK_TARGET__)
      #define malloc get_ctrl_buffer      ///< for SW encoder.
      #define free   free_ctrl_buffer     ///< for SW encoder.

      #if defined(RGB_ROTATOR_HW_SUPPORT)
         static kal_mutexid _rgb_rotator_state_mutex = NULL;
      #endif

      extern kal_bool INT_QueryExceptionStatus(void);
   #endif

   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      #include "drv_gfx_dynamic_switch.h"
   #endif
#endif

#include "rotator_enum.h"

#include "rgb_rotator_structure.h"
#include "rgb_rotator_int.h"

#include "gfx_cache_switch_behavior_enum.h"

#if defined(RGB_ROTATOR_HW_SUPPORT)
   static RGB_ROTATOR_HANDLE_STRUCT _rgb_rotator_hw_handle;
#endif

#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX



static kal_bool _rgb_rotator_set_window_intersection(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   RGB_ROTATOR_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);
   RGB_ROTATOR_WINDOW_STRUCT *srcClipWindow = &(handle->srcClipWindow);
   RGB_ROTATOR_WINDOW_STRUCT *dstClipWindow = &(handle->dstClipWindow);
   RGB_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
   RGB_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   kal_uint32 dstWidth = handle->dstWidth;
   kal_uint32 dstHeight = handle->dstHeight;

   kal_int32 diffTopleftX, diffTopleftY;
   kal_int32 diffButtonrightX, diffButtonrightY;
   kal_int32 startDstWindowTopleftX, startDstWindowTopleftY;
   kal_int32 startDstWindowButtonrightX, startDstWindowButtonrightY;
   kal_int32 topleftX, topleftY;
   kal_int32 buttonrightX, buttonrightY;
   kal_uint32 width, height;

   startDstWindowTopleftX = dstWindow->startX;
   startDstWindowTopleftY = dstWindow->startY;
   startDstWindowButtonrightX = (dstWindow->startX) + (dstWindow->width) - 1;
   startDstWindowButtonrightY = (dstWindow->startY) + (dstWindow->height) - 1;

   topleftX = startDstWindowTopleftX;
   topleftY = startDstWindowTopleftY;

   buttonrightX = MIN((kal_int32)dstWidth - 1, startDstWindowButtonrightX);
   buttonrightY = MIN((kal_int32)dstHeight - 1, startDstWindowButtonrightY);

   if(KAL_TRUE == (handle->dstClipWindowEnable))
   {
      topleftX = MAX(topleftX, dstClipWindow->startX);
      topleftY = MAX(topleftY, dstClipWindow->startY);

      buttonrightX = MIN(buttonrightX, (dstClipWindow->startX) + ((kal_int32)(dstClipWindow->width)) - 1);
      buttonrightY = MIN(buttonrightY, (dstClipWindow->startY) + ((kal_int32)(dstClipWindow->height)) - 1);
   }
   if(buttonrightX <  topleftX)
      return KAL_FALSE;
   if(buttonrightY <  topleftY)
      return KAL_FALSE;

   width = buttonrightX - topleftX + 1;
   height = buttonrightY - topleftY + 1;

   if(width <=  0)
      return KAL_FALSE;
   if(height <=  0)
      return KAL_FALSE;

   diffTopleftX = topleftX - startDstWindowTopleftX;
   diffTopleftY = topleftY - startDstWindowTopleftY;
   diffButtonrightX = startDstWindowButtonrightX - buttonrightX;
   diffButtonrightY = startDstWindowButtonrightY - buttonrightY;

   switch(handle->rotation)
   {
      case ROTATOR_CW_ROTATE_ANGLE_000:
      {
         srcClipWindow->startX = srcWindow->startX + diffTopleftX;
         srcClipWindow->startY = srcWindow->startY + diffTopleftY;
         srcClipWindow->width = width;
         srcClipWindow->height = height;
      }
      break;
      case ROTATOR_CW_ROTATE_ANGLE_090:
      {
         srcClipWindow->startX = srcWindow->startX + diffTopleftY;
         srcClipWindow->startY = srcWindow->startY + diffButtonrightX;
         srcClipWindow->width = height;
         srcClipWindow->height = width;
      }
      break;
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180)
         case ROTATOR_CW_ROTATE_ANGLE_180:
         {
            srcClipWindow->startX = srcWindow->startX + diffButtonrightX;
            srcClipWindow->startY = srcWindow->startY + diffButtonrightY;
            srcClipWindow->width = width;
            srcClipWindow->height = height;
         }
         break;
      #endif
      case ROTATOR_CW_ROTATE_ANGLE_270:
      {
         srcClipWindow->startX = srcWindow->startX + diffButtonrightY;
         srcClipWindow->startY = srcWindow->startY + diffTopleftX;
         srcClipWindow->width = height;
         srcClipWindow->height = width;
      }
      break;
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000)
         case ROTATOR_CW_ROTATE_ANGLE_MIRROR_000:
         {
            srcClipWindow->startX = srcWindow->startX + diffButtonrightX;
            srcClipWindow->startY = srcWindow->startY + diffTopleftY;
            srcClipWindow->width = width;
            srcClipWindow->height = height;
         }
         break;
      #endif

      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090)
         case ROTATOR_CW_ROTATE_ANGLE_MIRROR_090:
         {
            srcClipWindow->startX = srcWindow->startX + diffTopleftY;
            srcClipWindow->startY = srcWindow->startY + diffTopleftX;
            srcClipWindow->width = height;
            srcClipWindow->height = width;
         }
         break;
      #endif
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180)
         case ROTATOR_CW_ROTATE_ANGLE_MIRROR_180:
         {
            srcClipWindow->startX = srcWindow->startX + diffTopleftX;
            srcClipWindow->startY = srcWindow->startY + diffButtonrightY;
            srcClipWindow->width = width;
            srcClipWindow->height = height;
         }
         break;
      #endif
      #if defined(RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270)
         case ROTATOR_CW_ROTATE_ANGLE_MIRROR_270:
         {
            srcClipWindow->startX = srcWindow->startX + diffButtonrightY;
            srcClipWindow->startY = srcWindow->startY + diffButtonrightX;
            srcClipWindow->width = height;
            srcClipWindow->height = width;
         }
         break;
      #endif
      default:
         ASSERT(0);
   }

   targetClipWindow->startX = topleftX;
   targetClipWindow->startY = topleftY;
   targetClipWindow->width = width;
   targetClipWindow->height = height;

   return KAL_TRUE;
}



static kal_bool _rgb_rotator_check_range(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   RGB_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   RGB_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);

   if(((srcWindow->startX) < 0) || ((srcWindow->startY) < 0) ||
      ((dstWindow->startX) < 0) || ((dstWindow->startY) < 0))
   {
      return KAL_FALSE;
   }

   if(KAL_TRUE == (handle->dstClipWindowEnable))
   {
      RGB_ROTATOR_WINDOW_STRUCT *dstClipWindow = &(handle->dstClipWindow);

      if(((dstClipWindow->startX) < 0) || ((dstClipWindow->startY) < 0))
      {
         return KAL_FALSE;
      }
   }

   return KAL_TRUE;
}



ROTATOR_STATUS_ENUM rgbRotatorInit(void)
{
   #if defined(RGB_ROTATOR_HW_SUPPORT)
      if(rgb_rotator_drv_init() < 0)
      {
         return ROTATOR_STATUS_HW_ERROR;
      }
   #endif

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorGetHandle(RGB_ROTATOR_HANDLE_STRUCT **handlePtr, ROTATOR_MODE_ENUM mode)
{
   RGB_ROTATOR_HANDLE_STRUCT *handle = NULL;
   ROTATOR_TYPE_ENUM type = ROTATOR_TYPE_HW;

   switch (mode)
   {
      case ROTATOR_MODE_HW:
      {
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            *handlePtr = &_rgb_rotator_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)

               if(KAL_TRUE == kal_query_systemInit())
               {
                   *handlePtr = NULL;
                   return ROTATOR_STATUS_BUSY;
               }

               if (NULL == _rgb_rotator_state_mutex)
               {
                  _rgb_rotator_state_mutex = kal_create_mutex("RGB Rotator State");
                  ASSERT(_rgb_rotator_state_mutex != NULL);
               }

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_rgb_rotator_state_mutex);
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
                  {
                     kal_give_mutex(_rgb_rotator_state_mutex);
                     *handlePtr = NULL;
                     return ROTATOR_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  kal_give_mutex(_rgb_rotator_state_mutex);
               }
               else
               {
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
                  {
                     *handlePtr = NULL;
                     return ROTATOR_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
               }
            #else
               if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
               {
                  *handlePtr = NULL;
                  return ROTATOR_STATUS_BUSY;
               }

               memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
               handle->state = ROTATOR_STATE_SETTING_PARAMETER;
            #endif

            type = ROTATOR_TYPE_HW;
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// RGB_ROTATOR_HW_SUPPORT
      }
      case ROTATOR_MODE_SW:
      {
         handle = (RGB_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(RGB_ROTATOR_HANDLE_STRUCT));
         if(!handle)
         {
            return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
         }

         memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
         handle->state = ROTATOR_STATE_SETTING_PARAMETER;
         *handlePtr = handle;

         type = ROTATOR_TYPE_SW;
      }
      break;
      case ROTATOR_MODE_AUTO:
      {
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            *handlePtr = &_rgb_rotator_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)
               do
               {
                  if(KAL_TRUE == kal_query_systemInit())
                  {
                      *handlePtr = NULL;
                      type = ROTATOR_TYPE_SW;
                      break;
                  }

                  if (NULL == _rgb_rotator_state_mutex)
                  {
                     _rgb_rotator_state_mutex = kal_create_mutex("RGB Rotator State");
                     ASSERT(_rgb_rotator_state_mutex != NULL);
                  }

                  if (KAL_TRUE != INT_QueryExceptionStatus())
                  {
                     kal_take_mutex(_rgb_rotator_state_mutex);
                     if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
                     {
                        kal_give_mutex(_rgb_rotator_state_mutex);
                        *handlePtr = NULL;
                        type = ROTATOR_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                     handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                     kal_give_mutex(_rgb_rotator_state_mutex);
                  }
                  else
                  {
                    if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
                     {
                        *handlePtr = NULL;
                        type = ROTATOR_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                     handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  }

                  type = ROTATOR_TYPE_HW;

              }while(0);

              if(ROTATOR_TYPE_SW == type)
              {
                 handle = (RGB_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                 if(!handle)
                 {
                    return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                 }
                 memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                 handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                 *handlePtr = handle;
              }
            #else
               do
               {
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (rgb_rotator_drv_open()))
                  {
                     *handlePtr = NULL;
                     type = ROTATOR_TYPE_SW;
                     break;
                  }

                  memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;

                  type = ROTATOR_TYPE_HW;

               }while(0);

               if(ROTATOR_TYPE_SW == type)
               {
                  handle = (RGB_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                  if(!handle)
                  {
                     return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                  }
                  memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  *handlePtr = handle;
               }
            #endif
         }
         #else
         {
            handle = (RGB_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(RGB_ROTATOR_HANDLE_STRUCT));
            if(!handle)
            {
                return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
            }

            memset(handle, 0, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
            handle->state = ROTATOR_STATE_SETTING_PARAMETER;
            *handlePtr = handle;

            type = ROTATOR_TYPE_SW;
         }
         #endif /// RGB_ROTATOR_HW_SUPPORT
      }
      break;
      default:
         ASSERT(0);
   }
   handle->mode = mode;
   handle->type = type;

   return ROTATOR_STATUS_OK;
}



extern ROTATOR_STATUS_ENUM rgbRotatorGetStatus(RGB_ROTATOR_HANDLE_STRUCT *handle);
ROTATOR_STATUS_ENUM rgbRotatorReleaseHandle(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            #if defined(__MTK_TARGET__)
               {
                  ROTATOR_STATUS_ENUM status =  rgbRotatorGetStatus(handle);
                  
                  switch(status)
                  {
                     case ROTATOR_STATUS_BUSY:
                        return ROTATOR_STATUS_BUSY;
                     case ROTATOR_STATUS_COMPLETE:
                     case ROTATOR_STATUS_STATE_ERROR:
                     case ROTATOR_STATUS_NOT_SUPPORT:
                     break;
                     default:
                        ASSERT(0);
                  }
               }


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
               {
                  if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
                  {
                     if(ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->dstCanvasType))
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->dstBuffer), handle->dstBufferSize, KAL_FALSE);
                        handle->dstCanvasType = ROTATOR_MEMORY_TYPE_NO_SWITCH;
                     }
                  }

                  if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->srcBufferCacheSwitchBehavior)
                  {
                     if(ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcCanvasType))
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->srcBuffer), handle->srcBufferSize, KAL_FALSE);
                        handle->srcCanvasType = ROTATOR_MEMORY_TYPE_NO_SWITCH;
                     }
                  }
               }
#endif
               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_rgb_rotator_state_mutex);
                  handle->state = ROTATOR_STATE_IDLE;

                  if(rgb_rotator_drv_close())
                  {
                     ASSERT(0);
                  }

                  kal_give_mutex(_rgb_rotator_state_mutex);
               }
               else
               {
                  if(rgb_rotator_drv_close())
                  {
                     ASSERT(0);
                  }
                  handle->state = ROTATOR_STATE_IDLE;
               }
            #else
               if(rgb_rotator_drv_close())
               {
                  ASSERT(0);
               }
               handle->state = ROTATOR_STATE_IDLE;
            #endif
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// RGB_ROTATOR_HW_SUPPORT
      case ROTATOR_TYPE_SW:
         free(handle);
      break;
      default:
         ASSERT(0);
      break;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetCallbackFunction(RGB_ROTATOR_HANDLE_STRUCT *handle, ROTATOR_CALLBACK_FUNC_PTR rgbRotatorCallback)
{
   if (!rgbRotatorCallback)
   {
      handle->rgbRotatorCallback = NULL;
   }
   else
   {
      handle->rgbRotatorCallback = rgbRotatorCallback;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetSrcBufferInfo(RGB_ROTATOR_HANDLE_STRUCT *handle,
                                               ROTATOR_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->srcColorFormat = colorFormat;
   handle->srcBuffer = bufferAddr;
   handle->srcBufferSize = bufferSize;

   handle->srcWidth = bufferWidth;
   handle->srcHeight = bufferHeight;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetDstBufferInfo(RGB_ROTATOR_HANDLE_STRUCT *handle,
                                               ROTATOR_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->dstColorFormat = colorFormat;
   handle->dstBuffer = bufferAddr;
   handle->dstBufferSize = bufferSize;

   handle->dstWidth = bufferWidth;
   handle->dstHeight = bufferHeight;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetDstBufferSwitchBehavior(RGB_ROTATOR_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->dstBufferCacheSwitchBehavior = behavior;
   #endif

   return ROTATOR_STATUS_OK;
}

/**
 *  Setting the Destination buffer cache switch behavior
 */
ROTATOR_STATUS_ENUM rgbRotatorSetSrcBufferSwitchBehavior(RGB_ROTATOR_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->srcBufferCacheSwitchBehavior = behavior;
   #endif
    
   return ROTATOR_STATUS_OK;
}

ROTATOR_STATUS_ENUM rgbRotatorSetSrcWindow(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   RGB_ROTATOR_WINDOW_STRUCT *window = &(handle->srcWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetDstWindow(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   RGB_ROTATOR_WINDOW_STRUCT *window = &(handle->dstWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetDstClipWindow(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_bool dstClipWindowEnable, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   handle->dstClipWindowEnable = dstClipWindowEnable;
   if(KAL_TRUE == dstClipWindowEnable)
   {
      RGB_ROTATOR_WINDOW_STRUCT *window = &(handle->dstClipWindow);

      window->startX = x;
      window->startY = y;
      window->width = width;
      window->height = height;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetRotation(RGB_ROTATOR_HANDLE_STRUCT *handle, ROTATOR_CW_ROTATE_ANGLE_ENUM rotation)
{
   handle->rotation = rotation;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetColorReplacement(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_bool colorReplaceEnable,
                                                  kal_uint32 oldColor, kal_uint32 newColor)
{
   handle->colorReplaceEnable = colorReplaceEnable;
   handle->colorToAvoid = oldColor;
   handle->colorToReplace = newColor;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetDithering(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_bool ditherEnable)
{
   handle->ditherEnable = ditherEnable;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorCheckAbortFunction(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_int32 (*check_abort_func)(void))
{
   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
         return ROTATOR_STATUS_NOT_SUPPORT;
      case ROTATOR_TYPE_SW:
         handle->checkAbortFunc = check_abort_func;
      break;
      default:
         ASSERT(0);
      break;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorQueryWorkingMemory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                 kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   kal_uint32 hwIntMemBest = 0, hwIntMemMin = 0;
   kal_uint32 hwExtMemBest = 0, hwExtMemMin = 0;
   kal_uint32 swIntMemBest = 0, swIntMemMin = 0;
   kal_uint32 swExtMemBest = 0, swExtMemMin = 0;

   switch (handle->mode)
   {
      case ROTATOR_MODE_HW:
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            rgb_rotator_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// RGB_ROTATOR_HW_SUPPORT
      case ROTATOR_MODE_SW:
         sw_rgb_rotator_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
      break;
      case ROTATOR_MODE_AUTO:
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            rgb_rotator_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         #endif
         sw_rgb_rotator_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
      break;
      default:
         ASSERT(0);
   }

   handle->intMemorySizeBest = MAX(hwIntMemBest, swIntMemBest);
   handle->intMemorySizeMinimum = MAX(hwIntMemMin, swIntMemMin);
   handle->extMemorySizeBest = MAX(hwExtMemBest, swExtMemBest);
   handle->extMemorySizeMinimum = MAX(hwExtMemMin, swExtMemMin);

   *intMemBest = handle->intMemorySizeBest;
   *intMemMin = handle->intMemorySizeMinimum;
   *extMemBest = handle->extMemorySizeBest;
   *extMemMin = handle->extMemorySizeMinimum;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorSetWorkingMemory(RGB_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemAddr, kal_uint32 intMemSize,
                                               kal_uint32 *extMemAddr, kal_uint32 extMemSize)
{
   if(extMemSize < (handle->extMemorySizeMinimum))
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
   if(intMemSize < (handle->intMemorySizeMinimum))
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;

   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
         #if defined(RGB_ROTATOR_HW_SUPPORT)
            break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// RGB_ROTATOR_HW_SUPPORT
      case ROTATOR_TYPE_SW:
      break;
      default:
         ASSERT(0);
      break;
   }

   handle->intMemoryAddr = intMemAddr;
   handle->extMemoryAddr = extMemAddr;
   handle->intMemorySize = intMemSize;
   handle->extMemorySize = extMemSize;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM rgbRotatorStart(RGB_ROTATOR_HANDLE_STRUCT **handle)
{
   #if defined(RGB_ROTATOR_HW_SUPPORT)
      RGB_ROTATOR_HANDLE_STRUCT *backupHandle = NULL;
   #endif
   RGB_ROTATOR_HANDLE_STRUCT *curHandle = (*handle);
   ROTATOR_STATUS_ENUM status = ROTATOR_STATUS_OK;

   ASSERT(ROTATOR_STATE_SETTING_PARAMETER == (curHandle->state));

   if((curHandle->dstColorFormat) != (curHandle->srcColorFormat))
   {
      return ROTATOR_STATUS_NOT_SUPPORT_CSC;
   }
   if(KAL_FALSE == _rgb_rotator_check_range(curHandle))
   {
      return ROTATOR_STATUS_RANGE_CHECK_FAIL;
   }

   if(KAL_FALSE == _rgb_rotator_set_window_intersection(curHandle))
   {
      return ROTATOR_STATUS_OK;
   }

   if(ROTATOR_COLOR_FORMAT_ENUM_GRAY == (curHandle->srcColorFormat))
   {      
      if((KAL_TRUE == (curHandle->ditherEnable)) || (KAL_TRUE == (curHandle->colorReplaceEnable)))
      {
         ASSERT(0);
      }	
   }
   
   if(((curHandle->intMemorySizeMinimum) > (curHandle->intMemorySize)) ||
     ((curHandle->extMemorySizeMinimum) > (curHandle->extMemorySize)))
   {
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
   }

   #if defined(RGB_ROTATOR_HW_SUPPORT)
      if(ROTATOR_TYPE_HW == (curHandle->type))
      {
          kal_bool useHw = KAL_FALSE;

          #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
             /// Source
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->srcBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer), curHandle->srcBufferSize, KAL_TRUE))
                {
                   curHandle->srcCanvasType = ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
                }
             }
             /// Destination
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->dstBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer), curHandle->dstBufferSize, KAL_TRUE))
                {
                   curHandle->dstCanvasType = ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
                }
             }

             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->srcBuffer), curHandle->srcBufferSize))
             {
                ASSERT(0);
             }

             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->dstBuffer), curHandle->dstBufferSize))
             {
                ASSERT(0);
             }
          #endif /// __DYNAMIC_SWITCH_CACHEABILITY__

          curHandle->state = ROTATOR_STATE_BUSY;

          if(KAL_FALSE == (curHandle->ditherEnable))
          {
             // HW
             rgb_rotator_drv_start(curHandle);
             useHw = KAL_TRUE;
          }

          if(KAL_FALSE == useHw)
          {
             if(ROTATOR_MODE_AUTO == (curHandle->mode))
             {
                /// using SW
                /// 1. release HW
                {
                   #if defined(__MTK_TARGET__)
                      if (KAL_TRUE != INT_QueryExceptionStatus())
                      {
                         kal_take_mutex(_rgb_rotator_state_mutex);
                         curHandle->state = ROTATOR_STATE_IDLE;
                         kal_give_mutex(_rgb_rotator_state_mutex);
                      }
                      else
                      {
                         curHandle->state = ROTATOR_STATE_IDLE;
                      }
                   #else
                      curHandle->state = ROTATOR_STATE_IDLE;
                   #endif
                }

                /// 2. close hw handle
                if(rgb_rotator_drv_close())
                {
                   ASSERT(0);
                }

                /// 3. get SW handle, set HW handle to SW handle
                backupHandle = (RGB_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                if(!backupHandle)
                {
                    return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                }
                memcpy(backupHandle, curHandle, sizeof(RGB_ROTATOR_HANDLE_STRUCT));
                backupHandle->type = ROTATOR_TYPE_SW;
                /// 3. pointer to curHandle
                curHandle = backupHandle;
                /// 4. pointer to current handle
                *handle = curHandle;

             }
             else
             {
                curHandle->state = ROTATOR_STATE_ABORTING;
                status = ROTATOR_STATUS_HW_ERROR;
             }
          }
      }
   #endif

   if(ROTATOR_TYPE_SW == (curHandle->type))
   {
      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
         kal_bool srcSwitch = KAL_FALSE;
         kal_bool dstSwitch = KAL_FALSE;
      #endif

      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      {
         if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (curHandle->srcBufferCacheSwitchBehavior))
         {
            srcSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->srcBuffer), curHandle->srcBufferSize, KAL_TRUE);
         }
         if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (curHandle->dstBufferCacheSwitchBehavior))
         {
            dstSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer), curHandle->dstBufferSize, KAL_TRUE);
         }
      }
      #endif

      do
      {
         #if defined(SW_ROTATOR_WITH_INTERNAL_MEMORY)
            status = sw_rgb_rotator_set_working_memory(handle);

            if(ROTATOR_STATUS_OK != status)
            {
               break;
            }

         #endif


         curHandle->state = ROTATOR_STATE_BUSY;
         status = sw_rgb_rotator_start(curHandle);

      }while(0);


      /// SW Rotator

      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      {
         if(KAL_TRUE == srcSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer), curHandle->srcBufferSize, KAL_FALSE);
         }

         if(KAL_TRUE == dstSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer), curHandle->dstBufferSize, KAL_FALSE);
         }
      }
      #endif

      curHandle->state = ROTATOR_STATE_COMPLETE;

      if (curHandle->rgbRotatorCallback)
      {
         curHandle->rgbRotatorCallback(NULL);
      }
   }

   return status;
}



ROTATOR_STATUS_ENUM rgbRotatorGetStatus(RGB_ROTATOR_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
      {
         #if defined(RGB_ROTATOR_HW_SUPPORT)
         {
            if(ROTATOR_STATE_BUSY == (handle->state))
            {
               kal_int32 ret;

               ret = rgb_rotator_drv_get_status();
               switch(ret)
               {
                  case 1:
                    return ROTATOR_STATUS_BUSY;
                  case 0:
                    return ROTATOR_STATUS_COMPLETE;
                  default:
                    ASSERT(0);
               }
            }
            else
            {
                return ROTATOR_STATUS_STATE_ERROR;
            }
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// RGB_ROTATOR_HW_SUPPORT
      }
      case ROTATOR_TYPE_SW:
      break;
      default:
         ASSERT(0);
   }
   return ROTATOR_STATUS_COMPLETE;
}




