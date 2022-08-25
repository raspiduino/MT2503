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
 *   rgb_resizer_api.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_resizer.h"

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
   #include "kal_public_defs.h"
   #include "kal_public_api.h"
   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      #include "drv_gfx_dynamic_switch.h"
   #endif

   #if defined(__MTK_TARGET__)
      #define malloc get_ctrl_buffer      ///< for SW encoder.
      #define free   free_ctrl_buffer     ///< for SW encoder.

      #if defined(RGB_RESIZER_HW_SUPPORT)
         static kal_mutexid _rgb_resizer_state_mutex = NULL;
      #endif
      extern kal_bool INT_QueryExceptionStatus(void);

   #endif

   #include "cache_sw.h"
#endif



#include "resizer_enum.h"
#include "rgb_resizer_structure.h"
#include "rgb_resizer_int.h"

#include "gfx_cache_switch_behavior_enum.h"


#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX

#if defined(RGB_RESIZER_HW_SUPPORT)
   static RGB_RESIZER_HANDLE_STRUCT _rgb_resizer_hw_handle;
#endif


static kal_bool _rgb_resizer_set_window_intersection(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   RGB_RESIZER_WINDOW_STRUCT *targetClipWindow = &(handle->targetClipWindow);
   RGB_RESIZER_WINDOW_STRUCT *dstClipWindow = &(handle->dstClipWindow);
   RGB_RESIZER_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);
   kal_uint32 dstWidth = handle->dstWidth;
   kal_uint32 dstHeight = handle->dstHeight;

   kal_int32 topleftX, topleftY;
   kal_int32 buttonrightX, buttonrightY;

   if((dstWindow->startX) >= 0)
   {
      topleftX = MAX(0, dstWindow->startX);
   }
   else
   {
      topleftX = 0;
   }

   if((dstWindow->startY) >= 0)
   {
      topleftY = MAX(0, dstWindow->startY);
   }
   else
   {
      topleftY = 0;
   }

   buttonrightX = MIN(dstWidth - 1, (dstWindow->startX) + (dstWindow->width) - 1);
   buttonrightY = MIN(dstHeight - 1, (dstWindow->startY) + (dstWindow->height) - 1);

   if(KAL_TRUE == (handle->dstClipWindowEnable))
   {
      topleftX = MAX(topleftX, dstClipWindow->startX);
      topleftY = MAX(topleftY, dstClipWindow->startY);

      buttonrightX = MIN(buttonrightX, (dstClipWindow->startX) + ((kal_int32)(dstClipWindow->width)) - 1);
      buttonrightY = MIN(buttonrightY, (dstClipWindow->startY) + ((kal_int32)(dstClipWindow->height)) - 1);
   }
   if( buttonrightX <  topleftX)
      return KAL_FALSE;
   if( buttonrightY <  topleftY)
      return KAL_FALSE;

   targetClipWindow->startX = topleftX;
   targetClipWindow->startY = topleftY;

   targetClipWindow->width = buttonrightX - topleftX + 1;
   targetClipWindow->height = buttonrightY - topleftY + 1;

   if( (targetClipWindow->width) <=  0)
      return KAL_FALSE;
   if( (targetClipWindow->height) <=  0)
      return KAL_FALSE;

   return KAL_TRUE;
}



static kal_bool _rgb_resizer_check_range(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   RGB_RESIZER_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   RGB_RESIZER_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);

   if(((srcWindow->startX) < 0) || ((srcWindow->startY) < 0))
   {
      return KAL_FALSE;
   }

   if((kal_int32)((dstWindow->startX) + (dstWindow->width) - 1) < 0)
   {
      return KAL_FALSE;
   }

   if((kal_int32)((dstWindow->startY) + (dstWindow->height) - 1) < 0)
   {
      return KAL_FALSE;
   }

   if(KAL_TRUE == (handle->dstClipWindowEnable))
   {
      RGB_RESIZER_WINDOW_STRUCT *dstClipWindow = &(handle->dstClipWindow);

      if(((dstClipWindow->startX) < 0) || ((dstClipWindow->startY) < 0))
      {
         return KAL_FALSE;
      }
   }

   return KAL_TRUE;
}



RESIZER_STATUS_ENUM rgbResizerGetHandle(RGB_RESIZER_HANDLE_STRUCT **handlePtr, RESIZER_MODE_ENUM mode, RESIZER_QUALITY_ENUM resizerQuality)
{
   RGB_RESIZER_HANDLE_STRUCT *handle = NULL;
   RESIZER_TYPE_ENUM type = RESIZER_TYPE_HW;

   switch (mode)
   {
      case RESIZER_MODE_HW:
      {
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            *handlePtr = &_rgb_resizer_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)
               if (NULL == _rgb_resizer_state_mutex)
               {
                  _rgb_resizer_state_mutex = kal_create_mutex("RGB Resizer State");
                  ASSERT(_rgb_resizer_state_mutex != NULL);
               }

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_rgb_resizer_state_mutex);
                  if((RESIZER_STATE_IDLE != (handle->state)) || (rgb_resizer_drv_open()))
                  {
                     kal_give_mutex(_rgb_resizer_state_mutex);
                     *handlePtr = NULL;
                     return RESIZER_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                  handle->state = RESIZER_STATE_SETTING_PARAMETER;
                  kal_give_mutex(_rgb_resizer_state_mutex);
               }
               else
               {
                  if((RESIZER_STATE_IDLE != (handle->state)) || (rgb_resizer_drv_open()))
                  {
                     *handlePtr = NULL;
                     return RESIZER_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                  handle->state = RESIZER_STATE_SETTING_PARAMETER;
               }
            #else
               if(RESIZER_STATE_IDLE != (handle->state))
               {
                  *handlePtr = NULL;
                  return RESIZER_STATUS_BUSY;
               }

               memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
               handle->state = RESIZER_STATE_SETTING_PARAMETER;
            #endif

            type = RESIZER_TYPE_HW;
         }
         break;
         #else
            return RESIZER_STATUS_NOT_SUPPORT;
         #endif /// RGB_RESIZER_HW_SUPPORT
      }
      case RESIZER_MODE_SW:
      {
         handle = (RGB_RESIZER_HANDLE_STRUCT *)malloc(sizeof(RGB_RESIZER_HANDLE_STRUCT));
         if(!handle)
         {
            return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
         }

         memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
         handle->state = RESIZER_STATE_SETTING_PARAMETER;
         *handlePtr = handle;

         type = RESIZER_TYPE_SW;
      }
      break;
      case RESIZER_MODE_AUTO:
      {
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            *handlePtr = &_rgb_resizer_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)
               do
               {
                  if (NULL == _rgb_resizer_state_mutex)
                  {
                     _rgb_resizer_state_mutex = kal_create_mutex("RGB Resizer State");
                     ASSERT(_rgb_resizer_state_mutex != NULL);
                  }

                  if (KAL_TRUE != INT_QueryExceptionStatus())
                  {
                     kal_take_mutex(_rgb_resizer_state_mutex);
                     if((RESIZER_STATE_IDLE != (handle->state)) || (rgb_resizer_drv_open()))
                     {
                        kal_give_mutex(_rgb_resizer_state_mutex);
                        *handlePtr = NULL;
                        type = RESIZER_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                     handle->state = RESIZER_STATE_SETTING_PARAMETER;
                     kal_give_mutex(_rgb_resizer_state_mutex);
                  }
                  else
                  {
                     if((RESIZER_STATE_IDLE != (handle->state)) || (rgb_resizer_drv_open()))
                     {
                        *handlePtr = NULL;
                        type = RESIZER_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                     handle->state = RESIZER_STATE_SETTING_PARAMETER;
                  }

                  type = RESIZER_TYPE_HW;

              }while(0);

              if(RESIZER_TYPE_SW == type)
              {
                 handle = (RGB_RESIZER_HANDLE_STRUCT *)malloc(sizeof(RGB_RESIZER_HANDLE_STRUCT));
                 if(!handle)
                 {
                    return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
                 }
                 memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                 handle->state = RESIZER_STATE_SETTING_PARAMETER;
                 *handlePtr = handle;
              }
            #else
               do
               {
                  if(RESIZER_STATE_IDLE != (handle->state))
                  {
                     *handlePtr = NULL;
                     type = RESIZER_TYPE_SW;
                     break;
                  }

                  memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                  handle->state = RESIZER_STATE_SETTING_PARAMETER;

                  type = RESIZER_TYPE_HW;

               }while(0);

               if(RESIZER_TYPE_SW == type)
               {
                  handle = (RGB_RESIZER_HANDLE_STRUCT *)malloc(sizeof(RGB_RESIZER_HANDLE_STRUCT));
                  if(!handle)
                  {
                     return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
                  }
                  memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                  handle->state = RESIZER_STATE_SETTING_PARAMETER;
                  *handlePtr = handle;
               }
            #endif
         }
         #else
         {
            handle = (RGB_RESIZER_HANDLE_STRUCT *)malloc(sizeof(RGB_RESIZER_HANDLE_STRUCT));
            if(!handle)
            {
                return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
            }

            memset(handle, 0, sizeof(RGB_RESIZER_HANDLE_STRUCT));
            handle->state = RESIZER_STATE_SETTING_PARAMETER;
            *handlePtr = handle;

            type = RESIZER_TYPE_SW;
         }
         #endif /// RGB_RESIZER_HW_SUPPORT
      }
      break;
      default:
         ASSERT(0);
   }
   handle->mode = mode;
   handle->type = type;
   handle->quality = resizerQuality;

   return RESIZER_STATUS_OK;
}


extern RESIZER_STATUS_ENUM rgbResizerGetStatus(RGB_RESIZER_HANDLE_STRUCT *handle);
RESIZER_STATUS_ENUM rgbResizerReleaseHandle(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case RESIZER_TYPE_HW:
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            #if defined(__MTK_TARGET__)
               {
                  RESIZER_STATUS_ENUM status =  rgbResizerGetStatus(handle);

                  switch(status)
                  {
                     case RESIZER_STATUS_BUSY:
                        return RESIZER_STATUS_BUSY;
                     case RESIZER_STATUS_COMPLETE:
                     case RESIZER_STATUS_STATE_ERROR:
                     case RESIZER_STATUS_NOT_SUPPORT:
                     break;
                     default:
                        ASSERT(0);
                  }
               }
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
               {
                  if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
                  {
                     if(RESIZER_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->dstCanvasType))
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->dstBuffer), handle->dstBufferSize, KAL_FALSE);
                        handle->dstCanvasType = RESIZER_MEMORY_TYPE_NO_SWITCH;
                     }
                  }             
                  if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->srcBufferCacheSwitchBehavior)
                  {
                     if(RESIZER_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcCanvasType))
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->srcBuffer), handle->srcBufferSize, KAL_FALSE);
                        handle->srcCanvasType = RESIZER_MEMORY_TYPE_NO_SWITCH;
                     }
                  }
               }
#endif

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_rgb_resizer_state_mutex);
                  handle->state = RESIZER_STATE_IDLE;

                  if(rgb_resizer_drv_close())
                  {
                     ASSERT(0);
                  }

                  kal_give_mutex(_rgb_resizer_state_mutex);
               }
               else
               {
                  if(rgb_resizer_drv_close())
                  {
                     ASSERT(0);
                  }
                  handle->state = RESIZER_STATE_IDLE;
               }
            #else
               handle->state = RESIZER_STATE_IDLE;
            #endif
         }
         break;
         #else
            return RESIZER_STATUS_NOT_SUPPORT;
         #endif /// RGB_RESIZER_HW_SUPPORT
      case RESIZER_TYPE_SW:
         free(handle);
      break;
      default:
         ASSERT(0);
      break;
   }

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetCallbackFunction(RGB_RESIZER_HANDLE_STRUCT *handle, RESIZER_CALLBACK_FUNC_PTR rgbResizerCallback)
{
   if (!rgbResizerCallback)
   {
      handle->rgbResizerCallback = NULL;
   }
   else
   {
      handle->rgbResizerCallback = rgbResizerCallback;
   }

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetSrcBufferInfo(RGB_RESIZER_HANDLE_STRUCT *handle,
                                               RESIZER_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->srcColorFormat = colorFormat;
   handle->srcBuffer = bufferAddr;
   handle->srcBufferSize = bufferSize;

   handle->srcWidth = bufferWidth;
   handle->srcHeight = bufferHeight;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetDstBufferInfo(RGB_RESIZER_HANDLE_STRUCT *handle,
                                               RESIZER_COLOR_FORMAT_ENUM colorFormat, void *bufferAddr, kal_uint32 bufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->dstColorFormat = colorFormat;
   handle->dstBuffer = bufferAddr;
   handle->dstBufferSize = bufferSize;

   handle->dstWidth = bufferWidth;
   handle->dstHeight = bufferHeight;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetDstBufferSwitchBehavior(RGB_RESIZER_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->dstBufferCacheSwitchBehavior = behavior;
   #endif

   return RESIZER_STATUS_OK;
}

RESIZER_STATUS_ENUM rgbResizerSetSrcBufferSwitchBehavior(RGB_RESIZER_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->srcBufferCacheSwitchBehavior = behavior;
   #endif

   return RESIZER_STATUS_OK;
}


RESIZER_STATUS_ENUM rgbResizerSetSrcWindow(RGB_RESIZER_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   RGB_RESIZER_WINDOW_STRUCT *window = &(handle->srcWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetDstWindow(RGB_RESIZER_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   RGB_RESIZER_WINDOW_STRUCT *window = &(handle->dstWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetDstClipWindow(RGB_RESIZER_HANDLE_STRUCT *handle, kal_bool dstClipWindowEnable, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   handle->dstClipWindowEnable = dstClipWindowEnable;
   if(KAL_TRUE == dstClipWindowEnable)
   {
      RGB_RESIZER_WINDOW_STRUCT *window = &(handle->dstClipWindow);

      window->startX = x;
      window->startY = y;
      window->width = width;
      window->height = height;
   }

   return RESIZER_STATUS_OK;
}


RESIZER_STATUS_ENUM rgbResizerSetSrcKey(RGB_RESIZER_HANDLE_STRUCT *handle, kal_bool srcKeyEnable, kal_uint32 srcKeyValue)
{
   handle->srcKeyEnable = srcKeyEnable;
   handle->srcKeyValue = srcKeyValue;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetColorReplacement(RGB_RESIZER_HANDLE_STRUCT *handle, kal_bool colorReplaceEnable,
                                                  kal_uint32 oldColor, kal_uint32 newColor)
{
   handle->colorReplaceEnable = colorReplaceEnable;
   handle->colorToAvoid = oldColor;
   handle->colorToReplace = newColor;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetDithering(RGB_RESIZER_HANDLE_STRUCT *handle, kal_bool ditherEnable)
{
   handle->ditherEnable = ditherEnable;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerCheckAbortFunction(RGB_RESIZER_HANDLE_STRUCT *handle, kal_int32 (*check_abort_func)(void))
{
   switch (handle->type)
   {
      case RESIZER_TYPE_HW:
         return RESIZER_STATUS_NOT_SUPPORT;
      case RESIZER_TYPE_SW:
         handle->checkAbortFunc = check_abort_func;
      break;
      default:
         ASSERT(0);
      break;
   }

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerQueryWorkingMemory(RGB_RESIZER_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                 kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   kal_uint32 hwIntMemBest = 0, hwIntMemMin = 0;
   kal_uint32 hwExtMemBest = 0, hwExtMemMin = 0;
   kal_uint32 swIntMemBest = 0, swIntMemMin = 0;
   kal_uint32 swExtMemBest = 0, swExtMemMin = 0;

   switch (handle->mode)
   {
      case RESIZER_MODE_HW:
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            rgb_resizer_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         break;
         #else
            return RESIZER_STATUS_NOT_SUPPORT;
         #endif /// RGB_RESIZER_HW_SUPPORT
      case RESIZER_MODE_SW:
         sw_rgb_resizer_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
         ////
      break;
      case RESIZER_MODE_AUTO:
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            rgb_resizer_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         #endif
         sw_rgb_resizer_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
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

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerSetWorkingMemory(RGB_RESIZER_HANDLE_STRUCT *handle, kal_uint32 *intMemAddr, kal_uint32 intMemSize,
                                               kal_uint32 *extMemAddr, kal_uint32 extMemSize)
{
   if(extMemSize < (handle->extMemorySizeMinimum))
      return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
   if(intMemSize < (handle->intMemorySizeMinimum))
      return RESIZER_STATUS_NOT_ENOUGH_MEMORY;

   handle->intMemoryAddr = intMemAddr;
   handle->extMemoryAddr = extMemAddr;
   handle->intMemorySize = intMemSize;
   handle->extMemorySize = extMemSize;

   return RESIZER_STATUS_OK;
}



RESIZER_STATUS_ENUM rgbResizerStart(RGB_RESIZER_HANDLE_STRUCT **handle)
{
   #if defined(RGB_RESIZER_HW_SUPPORT)
      RGB_RESIZER_HANDLE_STRUCT *backupHandle = NULL;
   #endif
   RGB_RESIZER_HANDLE_STRUCT *curHandle = (*handle);
   RESIZER_STATUS_ENUM status = RESIZER_STATUS_OK;

   ASSERT(RESIZER_STATE_SETTING_PARAMETER == (curHandle->state));

   if((curHandle->dstColorFormat) != (curHandle->srcColorFormat))
   {
      return RESIZER_STATUS_NOT_SUPPORT_CSC;
   }
   if(KAL_FALSE == _rgb_resizer_check_range(curHandle))
   {
      return RESIZER_STATUS_RANGE_CHECK_FAIL;
   }

   if(KAL_FALSE == _rgb_resizer_set_window_intersection(curHandle))
   {
      return RESIZER_STATUS_OK;
   }

   if(((curHandle->intMemorySizeMinimum) > (curHandle->intMemorySize)) ||
     ((curHandle->extMemorySizeMinimum) > (curHandle->extMemorySize)))
   {
      return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
   }

   #if defined(RGB_RESIZER_HW_SUPPORT)
      if(RESIZER_TYPE_HW == (curHandle->type))
      {
          kal_bool useHw = KAL_FALSE;

          #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
             /// Source
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->srcBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer), curHandle->srcBufferSize, KAL_TRUE))
                {
                   curHandle->srcCanvasType = RESIZER_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
                }
             }
             /// Destination
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->dstBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer), curHandle->dstBufferSize, KAL_TRUE))
                {
                   curHandle->dstCanvasType = RESIZER_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
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

             if((curHandle->extMemoryAddr) && (curHandle->extMemorySize))
             {
                if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->extMemoryAddr), curHandle->extMemorySize))
                {
                   ASSERT(0);
                }
             }
          #endif /// __DYNAMIC_SWITCH_CACHEABILITY__

          curHandle->state = RESIZER_STATE_BUSY;

          if((KAL_FALSE == (curHandle->srcKeyEnable)) && (KAL_FALSE == (curHandle->colorReplaceEnable)))
          {
             // HW
             if(rgb_resizer_drv_start(curHandle) >= 0)
             {
                useHw = KAL_TRUE;
             }
          }

          if(KAL_FALSE == useHw)
          {
             if(RESIZER_MODE_AUTO == (curHandle->mode))
             {
                /// using SW
                /// 1. release HW
                {
                   #if defined(__MTK_TARGET__)
                      if (KAL_TRUE != INT_QueryExceptionStatus())
                      {
                         kal_take_mutex(_rgb_resizer_state_mutex);
                         curHandle->state = RESIZER_STATE_IDLE;
                         kal_give_mutex(_rgb_resizer_state_mutex);
                      }
                      else
                      {
                         curHandle->state = RESIZER_STATE_IDLE;
                      }
                   #else
                      curHandle->state = RESIZER_STATE_IDLE;
                   #endif
                }

                /// 2. close hw handle
                if(rgb_resizer_drv_close())
                {
                   ASSERT(0);
                }

                /// 3. get SW handle, set HW handle to SW handle
                backupHandle = (RGB_RESIZER_HANDLE_STRUCT *)malloc(sizeof(RGB_RESIZER_HANDLE_STRUCT));
                if(!backupHandle)
                {
                    return RESIZER_STATUS_NOT_ENOUGH_MEMORY;
                }
                memcpy(backupHandle, curHandle, sizeof(RGB_RESIZER_HANDLE_STRUCT));
                backupHandle->type = RESIZER_TYPE_SW;
                /// 3. pointer to curHandle
                curHandle = backupHandle;
                /// 4. pointer to current handle
                *handle = curHandle;

             }
             else
             {
                curHandle->state = RESIZER_STATE_ABORTING;
                status = RESIZER_STATUS_HW_ERROR;
             }
          }
      }
   #endif

   if(RESIZER_TYPE_SW == (curHandle->type))
   {
      RGB_RESIZER_WINDOW_STRUCT *srcWindow = &(curHandle->srcWindow);
      RGB_RESIZER_WINDOW_STRUCT *dstWindow = &(curHandle->dstWindow);
      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
         kal_bool srcSwitch = KAL_FALSE;
         kal_bool dstSwitch = KAL_FALSE;
         kal_bool extMemSwitch = KAL_FALSE;
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

         if((curHandle->extMemoryAddr) && (curHandle->extMemorySize))
         {
            extMemSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->extMemoryAddr), curHandle->extMemorySize, KAL_TRUE);
         }
      }
      #endif

      curHandle->state = RESIZER_STATE_BUSY;

      switch(curHandle->quality)
      {
         case RESIZER_QUALITY_HIGH:
            if((KAL_TRUE == (curHandle->srcKeyEnable)) ||
              ((srcWindow->width) < 3) ||
              ((srcWindow->height) < 3) ||
              ((((srcWindow->width) >> 1) < (dstWindow->width)) && (((srcWindow->height) >> 1) < (dstWindow->height))))
            {
               // scale-up
               sw_rgb_resizer_bilinear(curHandle);
            }
            else
            {
               #ifdef RGB_RESIZER_SW_SUPPORT_WITH_BOX_RESIZER
                  sw_rgb_resizer_box(curHandle);
               #else
                  sw_rgb_resizer_srcacc(curHandle);
               #endif

            }
         break;
         case RESIZER_QUALITY_MEDIUM:
            sw_rgb_resizer_bilinear(curHandle);
         break;
         case RESIZER_QUALITY_LOW:
            sw_rgb_resizer_nearest(curHandle);
         break;
         default:
            ASSERT(0);
      }

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

         if(KAL_TRUE == extMemSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->extMemoryAddr), curHandle->extMemorySize, KAL_FALSE);
         }
      }
      #endif

      curHandle->state = RESIZER_STATE_COMPLETE;

      if (curHandle->rgbResizerCallback)
      {
         curHandle->rgbResizerCallback(NULL);
      }
   }

   return status;
}



RESIZER_STATUS_ENUM rgbResizerGetStatus(RGB_RESIZER_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case RESIZER_TYPE_HW:
      {
         #if defined(RGB_RESIZER_HW_SUPPORT)
         {
            if(RESIZER_STATE_BUSY == (handle->state))
            {
               kal_int32 ret;

               ret = rgb_resizer_drv_get_status();
               switch(ret)
               {
                  case 1:
                    return RESIZER_STATUS_BUSY;
                  case 0:
                    return RESIZER_STATUS_COMPLETE;
                  default:
                    ASSERT(0);
               }
            }
            else
            {
                return RESIZER_STATUS_STATE_ERROR;
            }
         }
         break;
         #else
            return RESIZER_STATUS_NOT_SUPPORT;
         #endif /// RGB_RESIZER_HW_SUPPORT
      }
      case RESIZER_TYPE_SW:
      break;
      default:
         ASSERT(0);
   }
   return RESIZER_STATUS_COMPLETE;
}




