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
 *   yuv_rotator_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   YUV Rotator
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

      #if defined(YUV_ROTATOR_HW_SUPPORT)
         static kal_mutexid _yuv_rotator_state_mutex = NULL;
      #endif

      extern kal_bool INT_QueryExceptionStatus(void);
  #endif

   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      #include "drv_gfx_dynamic_switch.h"
   #endif
#endif

#include "rotator_enum.h"

#include "yuv_rotator_structure.h"
#include "yuv_rotator_int.h"

#include "gfx_cache_switch_behavior_enum.h"

#if defined(YUV_ROTATOR_HW_SUPPORT)
   static YUV_ROTATOR_HANDLE_STRUCT _yuv_rotator_hw_handle;
#endif

#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX



static kal_bool _yuv_rotator_check_range(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   YUV_ROTATOR_WINDOW_STRUCT *srcWindow = &(handle->srcWindow);
   YUV_ROTATOR_WINDOW_STRUCT *dstWindow = &(handle->dstWindow);

   if(((srcWindow->startX) < 0) || ((srcWindow->startY) < 0) ||
      ((dstWindow->startX) < 0) || ((dstWindow->startY) < 0))
   {
      return KAL_FALSE;
   }

   return KAL_TRUE;
}



ROTATOR_STATUS_ENUM yuvRotatorInit(void)
{
   #if defined(YUV_ROTATOR_HW_SUPPORT)
      if(yuv_rotator_drv_init() < 0)
      {
         return ROTATOR_STATUS_HW_ERROR;
      }
   #endif

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorGetHandle(YUV_ROTATOR_HANDLE_STRUCT **handlePtr, ROTATOR_MODE_ENUM mode)
{
   YUV_ROTATOR_HANDLE_STRUCT *handle = NULL;
   ROTATOR_TYPE_ENUM type = ROTATOR_TYPE_HW;

   switch (mode)
   {
      case ROTATOR_MODE_HW:
      {
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            *handlePtr = &_yuv_rotator_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)

               if(KAL_TRUE == kal_query_systemInit())
               {
                   *handlePtr = NULL;
                   return ROTATOR_STATUS_BUSY;
               }

               if (NULL == _yuv_rotator_state_mutex)
               {
                  _yuv_rotator_state_mutex = kal_create_mutex("YUV Rotator State");
                  ASSERT(_yuv_rotator_state_mutex != NULL);
               }

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_yuv_rotator_state_mutex);
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
                  {
                     kal_give_mutex(_yuv_rotator_state_mutex);
                     *handlePtr = NULL;
                     return ROTATOR_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  kal_give_mutex(_yuv_rotator_state_mutex);
               }
               else
               {
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
                  {
                     *handlePtr = NULL;
                     return ROTATOR_STATUS_BUSY;
                  }

                  memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
               }
            #else
               if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
               {
                  *handlePtr = NULL;
                  return ROTATOR_STATUS_BUSY;
               }

               memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
               handle->state = ROTATOR_STATE_SETTING_PARAMETER;
            #endif

            type = ROTATOR_TYPE_HW;
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// YUV_ROTATOR_HW_SUPPORT
      }
      case ROTATOR_MODE_SW:
      {
         handle = (YUV_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(YUV_ROTATOR_HANDLE_STRUCT));
         if(!handle)
         {
            return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
         }

         memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
         handle->state = ROTATOR_STATE_SETTING_PARAMETER;
         *handlePtr = handle;

         type = ROTATOR_TYPE_SW;
      }
      break;
      case ROTATOR_MODE_AUTO:
      {
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            *handlePtr = &_yuv_rotator_hw_handle;
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

                  if (NULL == _yuv_rotator_state_mutex)
                  {
                     _yuv_rotator_state_mutex = kal_create_mutex("UV Rotator State");
                     ASSERT(_yuv_rotator_state_mutex != NULL);
                  }

                  if (KAL_TRUE != INT_QueryExceptionStatus())
                  {
                     kal_take_mutex(_yuv_rotator_state_mutex);
                     if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
                     {
                        kal_give_mutex(_yuv_rotator_state_mutex);
                        *handlePtr = NULL;
                        type = ROTATOR_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                     handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                     kal_give_mutex(_yuv_rotator_state_mutex);
                  }
                  else
                  {
                    if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
                     {
                        *handlePtr = NULL;
                        type = ROTATOR_TYPE_SW;
                        break;
                     }

                     memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                     handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  }

                  type = ROTATOR_TYPE_HW;

              }while(0);

              if(ROTATOR_TYPE_SW == type)
              {
                 handle = (YUV_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                 if(!handle)
                 {
                    return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                 }
                 memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                 handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                 *handlePtr = handle;
              }
            #else
               do
               {
                  if((ROTATOR_STATE_IDLE != (handle->state)) || (yuv_rotator_drv_open()))
                  {
                     *handlePtr = NULL;
                     type = ROTATOR_TYPE_SW;
                     break;
                  }

                  memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;

                  type = ROTATOR_TYPE_HW;

               }while(0);

               if(ROTATOR_TYPE_SW == type)
               {
                  handle = (YUV_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                  if(!handle)
                  {
                     return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                  }
                  memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                  handle->state = ROTATOR_STATE_SETTING_PARAMETER;
                  *handlePtr = handle;
               }
            #endif
         }
         #else
         {
            handle = (YUV_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(YUV_ROTATOR_HANDLE_STRUCT));
            if(!handle)
            {
               return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
            }

            memset(handle, 0, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
            handle->state = ROTATOR_STATE_SETTING_PARAMETER;
            *handlePtr = handle;

            type = ROTATOR_TYPE_SW;
         }
         #endif /// YUV_ROTATOR_HW_SUPPORT
      }
      break;
      default:
         ASSERT(0);
   }
   handle->mode = mode;
   handle->type = type;

   return ROTATOR_STATUS_OK;
}



extern ROTATOR_STATUS_ENUM yuvRotatorGetStatus(YUV_ROTATOR_HANDLE_STRUCT *handle);
ROTATOR_STATUS_ENUM yuvRotatorReleaseHandle(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            #if defined(__MTK_TARGET__)
               {
                  ROTATOR_STATUS_ENUM status =  yuvRotatorGetStatus(handle);

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
            
#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
               /// Source
               if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->srcBufferCacheSwitchBehavior)
               {
                  if(ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcCanvasType))
                  {
                     drv_gfx_dynamic_switch_cacheable(&(handle->srcBuffer[0]), handle->srcBufferSize[0], KAL_FALSE);
                     if((handle->srcBufferSize[1]) > 0)
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->srcBuffer[1]), handle->srcBufferSize[1], KAL_FALSE);
                     }
                     if((handle->srcBufferSize[2]) > 0)
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->srcBuffer[2]), handle->srcBufferSize[2], KAL_FALSE);
                     }
                     handle->srcCanvasType = ROTATOR_MEMORY_TYPE_NO_SWITCH;
                  }
               }
               /// Destination
               if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
               {
                  if(ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->dstCanvasType))
                  {
                     drv_gfx_dynamic_switch_cacheable(&(handle->dstBuffer[0]), handle->dstBufferSize[0], KAL_FALSE);
                     if((handle->dstBufferSize[1]) > 0)
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->dstBuffer[1]), handle->dstBufferSize[1], KAL_FALSE);
                     }
                     
                     if((handle->dstBufferSize[2]) > 0)
                     {
                        drv_gfx_dynamic_switch_cacheable(&(handle->dstBuffer[2]), handle->dstBufferSize[2], KAL_FALSE);                   
                     }
                     handle->dstCanvasType = ROTATOR_MEMORY_TYPE_NO_SWITCH;
                  }
               }
#endif

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(_yuv_rotator_state_mutex);
                  handle->state = ROTATOR_STATE_IDLE;

                  if(yuv_rotator_drv_close())
                  {
                     ASSERT(0);
                  }

                  kal_give_mutex(_yuv_rotator_state_mutex);
               }
               else
               {
                  if(yuv_rotator_drv_close())
                  {
                     ASSERT(0);
                  }
                  handle->state = ROTATOR_STATE_IDLE;
               }
            #else
               if(yuv_rotator_drv_close())
               {
                  ASSERT(0);
               }
               handle->state = ROTATOR_STATE_IDLE;
            #endif
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// YUV_ROTATOR_HW_SUPPORT
      case ROTATOR_TYPE_SW:
         free(handle);
      break;
      default:
         ASSERT(0);
      break;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetCallbackFunction(YUV_ROTATOR_HANDLE_STRUCT *handle, ROTATOR_CALLBACK_FUNC_PTR yuvRotatorCallback)
{
   if (!yuvRotatorCallback)
   {
      handle->yuvRotatorCallback = NULL;
   }
   else
   {
      handle->yuvRotatorCallback = yuvRotatorCallback;
   }

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetSrcBufferInfo(YUV_ROTATOR_HANDLE_STRUCT *handle,
                                               ROTATOR_COLOR_FORMAT_ENUM colorFormat,
                                               void *yBufferAddr, void *uBufferAddr, void *vBufferAddr,
                                               kal_uint32 yBufferSize, kal_uint32 uBufferSize, kal_uint32 vBufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->srcColorFormat = colorFormat;
   handle->srcBuffer[0] = yBufferAddr;
   handle->srcBuffer[1] = uBufferAddr;
   handle->srcBuffer[2] = vBufferAddr;
   handle->srcBufferSize[0] = yBufferSize;
   handle->srcBufferSize[1] = uBufferSize;
   handle->srcBufferSize[2] = vBufferSize;

   handle->srcWidth = bufferWidth;
   handle->srcHeight = bufferHeight;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetDstBufferInfo(YUV_ROTATOR_HANDLE_STRUCT *handle,
                                               ROTATOR_COLOR_FORMAT_ENUM colorFormat,
                                               void *yBufferAddr, void *uBufferAddr, void *vBufferAddr,
                                               kal_uint32 yBufferSize, kal_uint32 uBufferSize, kal_uint32 vBufferSize,
                                               kal_uint32 bufferWidth, kal_uint32 bufferHeight)
{
   handle->dstColorFormat = colorFormat;
   handle->dstBuffer[0] = yBufferAddr;
   handle->dstBuffer[1] = uBufferAddr;
   handle->dstBuffer[2] = vBufferAddr;
   handle->dstBufferSize[0] = yBufferSize;
   handle->dstBufferSize[1] = uBufferSize;
   handle->dstBufferSize[2] = vBufferSize;

   handle->dstWidth = bufferWidth;
   handle->dstHeight = bufferHeight;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetDstBufferSwitchBehavior(YUV_ROTATOR_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->dstBufferCacheSwitchBehavior = behavior;
   #endif

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetSrcWindow(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   YUV_ROTATOR_WINDOW_STRUCT *window = &(handle->srcWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetDstWindow(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 width, kal_uint32 height)
{
   YUV_ROTATOR_WINDOW_STRUCT *window = &(handle->dstWindow);

   window->startX = x;
   window->startY = y;
   window->width = width;
   window->height = height;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorSetRotation(YUV_ROTATOR_HANDLE_STRUCT *handle, ROTATOR_CW_ROTATE_ANGLE_ENUM rotation)
{
   handle->rotation = rotation;

   return ROTATOR_STATUS_OK;
}



ROTATOR_STATUS_ENUM yuvRotatorCheckAbortFunction(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_int32 (*check_abort_func)(void))
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



ROTATOR_STATUS_ENUM yuvRotatorQueryWorkingMemory(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemBest, kal_uint32 *intMemMin,
                                                 kal_uint32 *extMemBest, kal_uint32 *extMemMin)
{
   kal_uint32 hwIntMemBest = 0, hwIntMemMin = 0;
   kal_uint32 hwExtMemBest = 0, hwExtMemMin = 0;
   kal_uint32 swIntMemBest = 0, swIntMemMin = 0;
   kal_uint32 swExtMemBest = 0, swExtMemMin = 0;

   switch (handle->mode)
   {
      case ROTATOR_MODE_HW:
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            yuv_rotator_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// YUV_ROTATOR_HW_SUPPORT
      case ROTATOR_MODE_SW:
         sw_yuv_rotator_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
      break;
      case ROTATOR_MODE_AUTO:
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            yuv_rotator_drv_query_working_memory(handle, &hwIntMemBest, &hwIntMemMin, &hwExtMemBest, &hwExtMemMin);
         }
         #endif
         sw_yuv_rotator_query_working_memory(handle, &swIntMemBest, &swIntMemMin, &swExtMemBest, &swExtMemMin);
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



ROTATOR_STATUS_ENUM yuvRotatorSetWorkingMemory(YUV_ROTATOR_HANDLE_STRUCT *handle, kal_uint32 *intMemAddr, kal_uint32 intMemSize,
                                               kal_uint32 *extMemAddr, kal_uint32 extMemSize)
{
   if(extMemSize < (handle->extMemorySizeMinimum))
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
   if(intMemSize < (handle->intMemorySizeMinimum))
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;

   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
         #if defined(YUV_ROTATOR_HW_SUPPORT)
            break;
         #else
            return ROTATOR_STATUS_NOT_SUPPORT;
         #endif /// YUV_ROTATOR_HW_SUPPORT
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



ROTATOR_STATUS_ENUM yuvRotatorStart(YUV_ROTATOR_HANDLE_STRUCT **handle)
{
   #if defined(YUV_ROTATOR_HW_SUPPORT)
      YUV_ROTATOR_HANDLE_STRUCT *backupHandle = NULL;
   #endif
   YUV_ROTATOR_HANDLE_STRUCT *curHandle = (*handle);
   ROTATOR_STATUS_ENUM status = ROTATOR_STATUS_OK;

   ASSERT(ROTATOR_STATE_SETTING_PARAMETER == (curHandle->state));

   if((curHandle->dstColorFormat) != (curHandle->srcColorFormat))
   {
      return ROTATOR_STATUS_NOT_SUPPORT_CSC;
   }
   if(KAL_FALSE == _yuv_rotator_check_range(curHandle))
   {
      return ROTATOR_STATUS_RANGE_CHECK_FAIL;
   }

   if(((curHandle->intMemorySizeMinimum) > (curHandle->intMemorySize)) ||
     ((curHandle->extMemorySizeMinimum) > (curHandle->extMemorySize)))
   {
      return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
   }

   #if defined(YUV_ROTATOR_HW_SUPPORT)
      if(ROTATOR_TYPE_HW == (curHandle->type))
      {
          kal_bool useHw = KAL_FALSE;

          #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
             /// Source
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->srcBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[0]), curHandle->srcBufferSize[0], KAL_TRUE))
                {
                   if((curHandle->srcBufferSize[1]) > 0)
                   {
                      drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[1]), curHandle->srcBufferSize[1], KAL_TRUE);
                   }
                   if((curHandle->srcBufferSize[2]) > 0)
                   {
                      drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[2]), curHandle->srcBufferSize[2], KAL_TRUE);
                   }
                   curHandle->srcCanvasType = ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
                }
             }
             /// Destination
             if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == curHandle->dstBufferCacheSwitchBehavior)
             {
                if(KAL_TRUE == drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer[0]), curHandle->dstBufferSize[0], KAL_TRUE))
                {
                   if((curHandle->dstBufferSize[1]) > 0)
                   {
                      drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer[1]), curHandle->dstBufferSize[1], KAL_TRUE);
                   }
                   
                   if((curHandle->dstBufferSize[2]) > 0)
                   {
                      drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer[2]), curHandle->dstBufferSize[2], KAL_TRUE);                   
                   }
                   curHandle->dstCanvasType = ROTATOR_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE;
                }
             }


             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->srcBuffer[0]), curHandle->srcBufferSize[0]))
             {
                ASSERT(0);
             }
             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->srcBuffer[1]), curHandle->srcBufferSize[1]))
             {
                ASSERT(0);
             }
             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->srcBuffer[2]), curHandle->srcBufferSize[2]))
             {
                ASSERT(0);
             }

             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->dstBuffer[0]), curHandle->dstBufferSize[0]))
             {
                ASSERT(0);
             }

             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->dstBuffer[1]), curHandle->dstBufferSize[1]))
             {
                ASSERT(0);
             }

             if (INT_QueryIsCachedRAM((kal_uint32)(curHandle->dstBuffer[2]), curHandle->dstBufferSize[2]))
             {
                ASSERT(0);
             }
          #endif /// __DYNAMIC_SWITCH_CACHEABILITY__

          curHandle->state = ROTATOR_STATE_BUSY;

          if(0 == yuv_rotator_drv_start(curHandle))
          {
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
                         kal_take_mutex(_yuv_rotator_state_mutex);
                         curHandle->state = ROTATOR_STATE_IDLE;
                         kal_give_mutex(_yuv_rotator_state_mutex);
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
                if(yuv_rotator_drv_close())
                {
                   ASSERT(0);
                }

                /// 3. get SW handle, set HW handle to SW handle
                backupHandle = (YUV_ROTATOR_HANDLE_STRUCT *)malloc(sizeof(YUV_ROTATOR_HANDLE_STRUCT));
                if(!backupHandle)
                {
                    return ROTATOR_STATUS_NOT_ENOUGH_MEMORY;
                }
                memcpy(backupHandle, curHandle, sizeof(YUV_ROTATOR_HANDLE_STRUCT));
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

   if (ROTATOR_TYPE_SW == (curHandle->type))
   {
      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
         kal_bool srcYSwitch = KAL_FALSE;
         kal_bool srcUSwitch = KAL_FALSE;
         kal_bool srcVSwitch = KAL_FALSE;
         kal_bool dstYSwitch = KAL_FALSE;
         kal_bool dstUSwitch = KAL_FALSE;
         kal_bool dstVSwitch = KAL_FALSE;
      #endif

      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      {
         if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (curHandle->srcBufferCacheSwitchBehavior))
         {
            srcYSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->srcBuffer[0]), curHandle->srcBufferSize[0], KAL_TRUE);

            if((curHandle->srcBufferSize[1]) > 0)
            {
               srcUSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->srcBuffer[1]), curHandle->srcBufferSize[1], KAL_TRUE);
            }

            if((curHandle->srcBufferSize[2]) > 0)
            {
               srcVSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->srcBuffer[2]), curHandle->srcBufferSize[2], KAL_TRUE);
            }
         }
         if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (curHandle->dstBufferCacheSwitchBehavior))
         {
            dstYSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer[0]), curHandle->dstBufferSize[0], KAL_TRUE);

            if((curHandle->dstBufferSize[1]) > 0)
            {
               dstUSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer[1]), curHandle->dstBufferSize[1], KAL_TRUE);
            }

            if((curHandle->dstBufferSize[2]) > 0)
            {
               dstVSwitch = drv_gfx_dynamic_switch_cacheable(&(curHandle->dstBuffer[2]), curHandle->dstBufferSize[2], KAL_TRUE);
            }
         }
      }
      #endif

      do
      {
         curHandle->state = ROTATOR_STATE_BUSY;
         status = sw_yuv_rotator_start(curHandle);

      }while(0);

      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      {
         if(KAL_TRUE == srcYSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[0]), curHandle->srcBufferSize[0], KAL_FALSE);
         }
         if(KAL_TRUE == srcUSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[1]), curHandle->srcBufferSize[1], KAL_FALSE);
         }
         if(KAL_TRUE == srcVSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->srcBuffer[2]), curHandle->srcBufferSize[2], KAL_FALSE);
         }

         if(KAL_TRUE == dstYSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer[0]), curHandle->dstBufferSize[0], KAL_FALSE);
         }
         if(KAL_TRUE == dstUSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer[1]), curHandle->dstBufferSize[1], KAL_FALSE);
         }
         if(KAL_TRUE == dstVSwitch)
         {
            drv_gfx_dynamic_switch_noncacheable(&(curHandle->dstBuffer[2]), curHandle->dstBufferSize[2], KAL_FALSE);
         }
      }
      #endif

      curHandle->state = ROTATOR_STATE_COMPLETE;

      if (curHandle->yuvRotatorCallback)
      {
         curHandle->yuvRotatorCallback(NULL);
      }
   }

   return status;
}



ROTATOR_STATUS_ENUM yuvRotatorGetStatus(YUV_ROTATOR_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case ROTATOR_TYPE_HW:
      {
         #if defined(YUV_ROTATOR_HW_SUPPORT)
         {
            if(ROTATOR_STATE_BUSY == (handle->state))
            {
               kal_int32 ret;

               ret = yuv_rotator_drv_get_status();
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
         #endif /// YUV_ROTATOR_HW_SUPPORT
      }
      case ROTATOR_TYPE_SW:
      break;
      default:
         ASSERT(0);
   }
   return ROTATOR_STATUS_COMPLETE;
}




