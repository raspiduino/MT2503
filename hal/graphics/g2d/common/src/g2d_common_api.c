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
 *   g2d_common_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   G2D Driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#include "string.h"

#if defined(G2D_CODEC_STANDALONE)
   #include "stdio.h"
   #include "stdlib.h"

   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
#elif defined(G2D_FPGA)
   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
#else
   #include "kal_public_api.h"
   #include "kal_public_defs.h"
   #include "cache_sw.h"

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)   
      #include "drv_gfx_dynamic_switch.h"
   #endif

   #if defined(__MTK_TARGET__)
      #define malloc get_ctrl_buffer      ///< for SW encoder.
      #define free   free_ctrl_buffer     ///< for SW encoder.

      kal_mutexid g2d_state_mutex = NULL;
      extern kal_bool INT_QueryExceptionStatus(void);

   #endif
#endif

#include "drv_features_g2d.h"
#include "g2d_enum.h"
#include "g2d_structure.h"

#include "g2d_drv_api.h"
#include "g2d_mutex.h"
#include "gfx_cache_switch_behavior_enum.h"
#include "ex_public.h"



#if !defined(__MTK_TARGET__) && !defined(G2D_FPGA)
   kal_uint32 g2d_hw_registers[100];
#endif

#if defined(__MTK_TARGET__)
EX_BBREG_DUMP g2d_dump;
const kal_uint32 g2d_dump_regions[] = {
#if defined(MT6250)
   0xA0440000, 0x160, 4
#elif defined(MT6255)
   0x98110000, 0x160, 4
#elif defined(MT6260)
   0xA0440000, 0x160, 4
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
   0xA0440000, 0x160, 4
#else
   0, 0, 0
#endif
};
#endif /* __MTK_TARGET__ */
static G2D_HANDLE_STRUCT _g2d_hw_handle;

kal_bool g2d_irq_handler(void* g2d_status)
{
   if (_g2d_hw_handle.g2dCallback)
   {
      _g2d_hw_handle.g2dCallback(NULL);
   }
   return KAL_TRUE;
}

G2D_STATUS_ENUM g2dInit(void)
{
   #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
      #if defined(__MTK_TARGET__)
         if (NULL == g2d_state_mutex)
         {
            g2d_state_mutex = kal_create_mutex("G2D State");
            ASSERT(g2d_state_mutex != NULL);
            g2d_mutex_init(&g2d_mutex);
         }
      #endif
      /// we can't call mutex before task being initialized
      /// kal_take_mutex(g2d_state_mutex);
      /// kal_give_mutex(g2d_state_mutex);
      #if defined(__MTK_TARGET__) || defined(G2D_FPGA)
         g2d_drv_power_on();
         g2d_drv_init();
         g2d_drv_power_off();
      #endif

   #endif

#if defined(__MTK_TARGET__)
   /* register bb reg dump */
   g2d_dump.regions = (kal_uint32*)g2d_dump_regions;
   g2d_dump.num = sizeof(g2d_dump_regions) / (sizeof(kal_uint32) * 3);
   g2d_dump.bbreg_dump_callback = NULL;
   EX_REGISTER_BBREG_DUMP(&g2d_dump);
#endif /* __MTK_TARGET__ */

   return G2D_STATUS_OK;
}


kal_int32 g2dGetStatus(G2D_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
         case G2D_CODEC_TYPE_HW:
         {
            #if defined(__MTK_TARGET__) || defined(G2D_FPGA)
               return g2d_drv_get_hw_status();
            #else
               return 0;
            #endif
         }
         ///break;
      #endif /// G2D_HW_SUPPORT
      case G2D_CODEC_TYPE_SW:
         return 0;
      ///break;
      default:
         ASSERT(0);
      ///break;
   }

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dGetHandle(G2D_HANDLE_STRUCT **handlePtr, G2D_CODEC_TYPE_ENUM codecType, G2D_GET_HANDLE_MODE_ENUM handleMode)
{
   G2D_HANDLE_STRUCT *handle = NULL;

   switch (codecType)
   {
      case G2D_CODEC_TYPE_HW:
         #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
         {
            *handlePtr = &_g2d_hw_handle;
            handle = *handlePtr;
            #if defined(__MTK_TARGET__)
               if(G2D_GET_HANDLE_MODE_BLOCKING_UNTIL_GET_HANDLE == handleMode)
               {
                  if (KAL_TRUE != INT_QueryExceptionStatus())
                  {
                     while(1)
                     {
                        g2d_mutex_lock(&g2d_mutex);
                        if(G2D_STATE_IDLE != (handle->g2dState))
                        {
                           ASSERT(0);
                        }
                        else
                        {
                           memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
                           handle->g2dState = G2D_STATE_SETTING_PARAMETER;
                           break;
                        }
                     }
                  }
                  else
                  {
                     while(1)
                     {
                        if(G2D_STATE_IDLE != (handle->g2dState))
                        {
                           kal_sleep_task(1); // 4.615 ms
                           continue;
                        }
                        else
                        {
                           break;
                        }
                     }
                     memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
                     handle->g2dState = G2D_STATE_SETTING_PARAMETER;
                  }

                  g2d_drv_power_on();
               }
               else
               {
                  if (KAL_TRUE != INT_QueryExceptionStatus())
                  {
                     if (KAL_FALSE == g2d_mutex_lock_fast(&g2d_mutex))
                     {
                        return G2D_STATUS_BUSY;
                     }
                     if(G2D_STATE_IDLE != (handle->g2dState))
                     {
                        ASSERT(0);
                        return G2D_STATUS_BUSY;
                     }
                     memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
                     handle->g2dState = G2D_STATE_SETTING_PARAMETER;
                  }
                  else
                  {
                     if(G2D_STATE_IDLE != (handle->g2dState))
                     {
                        return G2D_STATUS_BUSY;
                     }
                     memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
                     handle->g2dState = G2D_STATE_SETTING_PARAMETER;
                  }

                  g2d_drv_power_on();
               }
            #else
               if(G2D_GET_HANDLE_MODE_BLOCKING_UNTIL_GET_HANDLE == handleMode)
               {
                  while(1)
                  {
                     if(G2D_STATE_IDLE != (handle->g2dState))
                     {
                        continue;
                     }
                     else
                     {
                        break;
                     }
                  }
               }
               else
               {
                  if(G2D_STATE_IDLE != (handle->g2dState))
                  {
                     return G2D_STATUS_BUSY;
                  }
               }
               memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
               handle->g2dState = G2D_STATE_SETTING_PARAMETER;
            #endif
         }
         break;
         #else
            return G2D_STATUS_NOT_SUPPORT;
         #endif /// G2D_HW_SUPPORT
      #if !defined(G2D_FPGA)
         case G2D_CODEC_TYPE_SW:
            handle = (G2D_HANDLE_STRUCT *)malloc(sizeof(G2D_HANDLE_STRUCT));
            /// Can not memset to hw handle to 0
            memset(handle, 0, sizeof(G2D_HANDLE_STRUCT));
            handle->g2dState = G2D_STATE_SETTING_PARAMETER;
            *handlePtr = handle;
         break;
      #endif
      default:
         ASSERT(0);
         *handlePtr = NULL;
      break;
   }
   handle->type = codecType;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dReleaseHandle(G2D_HANDLE_STRUCT *handle)
{
   switch (handle->type)
   {
      case G2D_CODEC_TYPE_HW:
         #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
         {
            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
            {
               kal_int32 colorSize, colorSizeMax;
               G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
               
               if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstCanvasCacheSwitchBehavior)
               {
                  if(G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->dstCanvasType))
                  {
                     G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
                     drv_gfx_dynamic_switch_cacheable(&(dstCanvas->RGBBufferAddr), dstCanvas->RGBBufferSize, KAL_FALSE);
                     handle->dstCanvasType = G2D_MEMORY_TYPE_NO_SWITCH;
                  }
               }

               if (GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->srcCanvasCacheSwitchBehavior)
               {
                  #if defined(G2D_HW_SUPPORT)
                  if(G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcBitbltRGBCanvasType))
                  {
                     G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->bitbltFunc.srcCanvas);

                     drv_gfx_dynamic_switch_cacheable(&(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize, KAL_FALSE);
                     handle->srcBitbltRGBCanvasType = G2D_MEMORY_TYPE_NO_SWITCH;
                  }
                  #endif

                  if(G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcRectFillOverlayRGBCanvasType))
                  {
                     G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->rectFillFunc.srcCanvas);

                     drv_gfx_dynamic_switch_cacheable(&(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize, KAL_FALSE);
                     handle->srcRectFillOverlayRGBCanvasType = G2D_MEMORY_TYPE_NO_SWITCH;
                  }

                  if(G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcLtRGBCanvasType))
                  {
                     G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->ltFunc.srcCanvas);

                     drv_gfx_dynamic_switch_cacheable(&(srcCanvas->RGBBufferAddr), srcCanvas->RGBBufferSize, KAL_FALSE);
                     handle->srcLtRGBCanvasType = G2D_MEMORY_TYPE_NO_SWITCH;
                  }

                  if(G2D_COLOR_FORMAT_UYVY422 == handle->ltFunc.srcCanvas.colorFormat)
                  {
                     colorSizeMax = 1;
                  }
                  else
                  {
                     colorSizeMax = 3;
                  }
                  for(colorSize = 0; colorSize < colorSizeMax; colorSize++)
                  {
                     if(G2D_MEMORY_TYPE_SWITCH_TO_NONCACHEABLE == (handle->srcLtYUVCanvasType[colorSize]))
                     {
                        G2D_CANVAS_INFO_STRUCT *srcCanvas = &(handle->ltFunc.srcCanvas);
                        if(0 != (srcCanvas->YUVBufferSize[colorSize]))
                        {
                           drv_gfx_dynamic_switch_cacheable(&(srcCanvas->YUVBufferAddr[colorSize]), srcCanvas->YUVBufferSize[colorSize], KAL_FALSE);
                           handle->srcLtYUVCanvasType[colorSize] = G2D_MEMORY_TYPE_NO_SWITCH;
                        }
                     }
                  }
               }

            }
            #endif
            #if defined(__MTK_TARGET__)
               if(g2dGetStatus(handle))
                  return G2D_STATUS_BUSY;

               g2d_drv_power_off();

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  handle->g2dState = G2D_STATE_IDLE;
                  g2d_mutex_unlock(&g2d_mutex);
               }
               else
               {
                  handle->g2dState = G2D_STATE_IDLE;
               }
               g2d_mutex_wakeup_wait_task();
            #else
               handle->g2dState = G2D_STATE_IDLE;
            #endif
         }
         break;
         #else
            return G2D_STATUS_NOT_SUPPORT;
         #endif /// G2D_HW_SUPPORT
      #if !defined(G2D_FPGA)
         case G2D_CODEC_TYPE_SW:
            free(handle);
         break;
      #endif
      default:
         ASSERT(0);
      break;
   }

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dQueryDstRGBBufferRange(G2D_HANDLE_STRUCT *handle, kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height)
{
   switch (handle->type)
   {
      #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
         case G2D_CODEC_TYPE_HW:
           g2d_drv_query_dst_canvas_info(min_width, max_width, min_height, max_height);
         break;
      #endif /// G2D_HW_SUPPORT
      case G2D_CODEC_TYPE_SW:
         ASSERT(0);
      break;
      default:
         ASSERT(0);
      break;
   }
   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetOwner(G2D_HANDLE_STRUCT *handle, G2D_CODEC_OWNER_ENUM owner)
{
   #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
	    handle->owner = owner;

      return G2D_STATUS_OK;
   #else
      return G2D_STATUS_NOT_SUPPORT;
   #endif
}



G2D_STATUS_ENUM g2dSetDstRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                       kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                       kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   G2D_CANVAS_INFO_STRUCT *dstCanvas = &(handle->dstCanvas);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   ASSERT(bufferAddr);

   dstCanvas->RGBBufferAddr = bufferAddr;
   dstCanvas->RGBBufferSize = bufferSize;
   dstCanvas->width = width;
   dstCanvas->height = height;
   dstCanvas->colorFormat = colorFormat;

   switch (colorFormat)
   {
       case G2D_COLOR_FORMAT_GRAY :
          dstCanvas->bytesPerPixel = 1;
       break;
       case G2D_COLOR_FORMAT_RGB565 :
          dstCanvas->bytesPerPixel = 2;
       break;
       case G2D_COLOR_FORMAT_RGB888:
       case G2D_COLOR_FORMAT_BGR888:
       case G2D_COLOR_FORMAT_ARGB8565:
       case G2D_COLOR_FORMAT_ARGB6666:
       case G2D_COLOR_FORMAT_PARGB8565:
       case G2D_COLOR_FORMAT_PARGB6666:
          dstCanvas->bytesPerPixel = 3;
       break;
       case G2D_COLOR_FORMAT_ARGB8888:
       case G2D_COLOR_FORMAT_PARGB8888:
          dstCanvas->bytesPerPixel = 4;
       break;
       default:
          ASSERT(0);
       break;
   }

#if defined(MT6255)
#if defined(__MTK_TARGET__)
   if (INT_QueryIsROMSpace((kal_uint32)dstCanvas->RGBBufferAddr))
   {
     EXT_ASSERT(0, (kal_uint32)dstCanvas->RGBBufferAddr, 0, 0);
   }
#endif //#if defined(__MTK_TARGET__)
#endif

   #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
      if(G2D_CODEC_TYPE_HW == (handle->type))
      {
         status = g2d_drv_check_dst_canvas_info(width);

         ///#if defined(__MTK_TARGET__)
         ///{
         ///   ASSERT(INT_QueryIsNonCachedRAM((kal_uint32)bufferAddr, bufferSize));
         ///}
         ///#endif
      }
   #endif

   return status;
}




G2D_STATUS_ENUM g2dSetDstBufferSwitchBehavior(G2D_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      handle->dstCanvasCacheSwitchBehavior = behavior;
   #endif

   return G2D_STATUS_OK;
}

G2D_STATUS_ENUM g2dSetSrcBufferSwitchBehavior(G2D_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
       handle->srcCanvasCacheSwitchBehavior = behavior;
#endif
    return G2D_STATUS_OK;
}

G2D_STATUS_ENUM g2dSetCallbackFunction(G2D_HANDLE_STRUCT *handle, G2D_CALLBACK_FUNC_PTR g2d_callback)
{
   if (!g2d_callback)
   {
      handle->g2dCallback = NULL;
      handle->callbackEnable = KAL_FALSE;
   }
   else
   {
      handle->g2dCallback = g2d_callback;
      handle->callbackEnable = KAL_TRUE;
   }

   #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
      if((G2D_CODEC_TYPE_HW == (handle->type)) && (G2D_CODEC_OWNER_GOVL == (handle->owner)))
      {
      	  /// setting the hw hisr callback function
         g2d_drv_set_hw_hisr_callback(&g2d_irq_handler);
      }
   #endif

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetDstClipWindow(G2D_HANDLE_STRUCT *handle, kal_bool clipEnable, kal_int32 x, kal_int32 y, kal_int32 w, kal_int32 h)
{
   G2D_COORDINATE_STRUCT *topLeft     = &(handle->clipWindow.topLeft);
   G2D_COORDINATE_STRUCT *buttomRight = &(handle->clipWindow.buttomRight);
   G2D_STATUS_ENUM status = G2D_STATUS_OK;

   handle->clipEnable = clipEnable;

   if (KAL_TRUE == clipEnable)
   {
      kal_uint32 x_min_clip, y_min_clip;
      kal_uint32 x_max_clip, y_max_clip;

      x_min_clip = x;
      y_min_clip = y;
      x_max_clip = x + w - 1;
      y_max_clip = y + h - 1;

      #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
         if(G2D_CODEC_TYPE_HW == (handle->type))
            status = g2d_drv_check_clip_window(x, y, x_max_clip, y_max_clip);
      #endif

      topLeft->x = x_min_clip;
      topLeft->y = y_min_clip;

      buttomRight->x = x_max_clip;
      buttomRight->y = y_max_clip;
   }

   return status;
}



G2D_STATUS_ENUM g2dSetColorReplacement(G2D_HANDLE_STRUCT *handle,
                                       kal_bool colorReplaceEnable,
                                       kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0,
                                       kal_uint8 a1, kal_uint8 r1, kal_uint8 g1, kal_uint8 b1)
{
   handle->colorReplaceEnable = colorReplaceEnable;

   if (KAL_TRUE == colorReplaceEnable)
   {
      handle->colorToAvoid.alpha = a0;
      handle->colorToAvoid.red   = r0;
      handle->colorToAvoid.green = g0;
      handle->colorToAvoid.blue  = b0;

      handle->colorToReplace.alpha = a1;
      handle->colorToReplace.red   = r1;
      handle->colorToReplace.green = g1;
      handle->colorToReplace.blue  = b1;
   }

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetSrcKey(G2D_HANDLE_STRUCT *handle, kal_bool srcKeyEnable, kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0)
{
   if (KAL_TRUE == srcKeyEnable)
   {
      handle->srcKeyEnable = KAL_TRUE;
      handle->srcKeyValue.alpha = a0;
      handle->srcKeyValue.red   = r0;
      handle->srcKeyValue.green = g0;
      handle->srcKeyValue.blue  = b0;
   }
   else
   {
      handle->srcKeyEnable = KAL_FALSE;
   }

   return G2D_STATUS_OK;
}

G2D_STATUS_ENUM g2dSetDithering(G2D_HANDLE_STRUCT *handle, kal_bool dithering_enable, G2D_DITHERING_MODE_ENUM method)
{
#if defined(G2D_HW_DITHERING_SUPPORT)
   if (KAL_TRUE == dithering_enable)
   {
      handle->ditheringEnable = KAL_TRUE;
      handle->ditheringMode = method;
   }
   else
   {
      handle->ditheringEnable = KAL_FALSE;
   }
#endif
    return G2D_STATUS_OK;
}

G2D_STATUS_ENUM g2dQuerySupport(G2D_CODEC_TYPE_ENUM codecType, G2D_SUPPORT_FUNCTION_ENUM function)
{
   switch (codecType)
   {
      case G2D_CODEC_TYPE_HW:
      {
         #if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))
            switch (function)
            {
               case G2D_SUPPORT_FUNCTION_BITBLT:
                  #if defined(G2D_HW_BITBLT_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_RECT_FILL:
                  #if defined(G2D_HW_RECT_FILL_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_NORMAL_FONT:
                  #if defined(G2D_HW_FONT_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_AA_FONT:
                  #if defined(G2D_HW_AA_FONT_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_TILT_FONT:
                  #if defined(G2D_HW_TILT_FONT_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_LT:
                  #if defined(G2D_HW_LT_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_LT_WITH_ALPHA_BLENDING:
                  #if defined(G2D_HW_LT_WITH_ALPHA_BLENDING_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_SAD:
                  #if defined(G2D_HW_SAD_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_OVERLAY:
                  #if defined(G2D_HW_OVERLAY_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               case G2D_SUPPORT_FUNCTION_DITHERING:
                  #if defined(G2D_HW_DITHERING_SUPPORT)
                     return G2D_STATUS_OK;
                  #else
                     return G2D_STATUS_NOT_SUPPORT;
                  #endif
               ///break;
               default:
                  ASSERT(0);
            }
            break;
         #else
            return G2D_STATUS_NOT_SUPPORT;
         #endif /// G2D_HW_SUPPORT
      }
      case G2D_CODEC_TYPE_SW:
      {
         switch (function)
         {
            case G2D_SUPPORT_FUNCTION_LT:
            case G2D_SUPPORT_FUNCTION_LT_WITH_ALPHA_BLENDING:
               return G2D_STATUS_OK;
            default:
               return G2D_STATUS_NOT_SUPPORT;
         }
      }
      ///break;
      default:
         ASSERT(0);
   }
   return G2D_STATUS_OK;
}



#if defined(G2D_FPGA)

G2D_STATUS_ENUM g2dSetReadBurstType(G2D_HANDLE_STRUCT *handle, G2D_READ_BURST_TYPE_ENUM readBurstType)
{
   handle->readBurstType = readBurstType;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetWriteBurstType(G2D_HANDLE_STRUCT *handle, G2D_WRITE_BURST_TYPE_ENUM writeBurstType)
{
   handle->writeBurstType = writeBurstType;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetSlowDownCount(G2D_HANDLE_STRUCT *handle, kal_bool slowDownEnable, kal_uint32 slowDownCount)
{
   handle->slowDownEnable = slowDownEnable;

   if (KAL_TRUE == slowDownEnable)
   {
      handle->slowDownCount = slowDownCount;
   }
   return G2D_STATUS_OK;
}


G2D_STATUS_ENUM g2dSetTileSize(G2D_HANDLE_STRUCT *handle, kal_bool autoTileSizeEnable, G2D_TILE_SIZE_TYPE_ENUM tileSize)
{
   handle->autoTileSizeEnable = autoTileSizeEnable;

   if (KAL_FALSE == autoTileSizeEnable)
   {
      handle->tileSize = tileSize;
   }
   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2dSetMaxOutStandingNumber(G2D_HANDLE_STRUCT *handle, G2D_MAX_OUTSTANDING_NUM_ENUM maxOutstanding)
{
   handle->maxOutstanding = maxOutstanding;

   return G2D_STATUS_OK;
}


#endif /// G2D_FPGA

