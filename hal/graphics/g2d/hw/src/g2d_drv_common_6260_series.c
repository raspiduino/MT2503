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
 *   g2d_drv_common_6260_series.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_g2d.h"

//#if defined (__DRV_GRAPHICS_G2D_6260_SERIES__)
#if (defined(G2D_HW_SUPPORT) || defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT))

#include "kal_general_types.h"

#if defined(G2D_CODEC_STANDALONE)
   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
#elif defined(G2D_FPGA)
   #include "assert.h"
   #ifndef ASSERT
      #define ASSERT(x) { if (!(x))  while (1); }
   #endif

   ///#include "cm_header.h"
   ///#include "sal_header.h"
   #include "cirq.h"
#else
   #include "kal_public_defs.h"
   #include "kal_public_api.h"
   #include "intrCtrl.h"         /// define IRQ_G2D_CODE
#endif

#include "g2d_enum.h"
#include "g2d_structure.h"
#include "g2d_macro.h"
#include "g2d_drv_6260_series.h"

#if defined(__MTK_TARGET__) || defined(G2D_FPGA)
#else
   extern kal_uint32 g2d_hw_registers[100];
#endif

static G2D_CALLBACK_FUNC_PTR _g2d_hw_hisr_callback = NULL;

#if defined(__MTK_TARGET__) || defined(G2D_FPGA)

static kal_uint8 _g2d_hw_init_flag = 0;

#if !defined(G2D_FPGA)
   #include "mm_power_ctrl.h"    /// mm power gating

   ///#include "hisr_config.h"
   #include "drv_gfx_hisr_ctrl.h"
#endif



void g2d_drv_isr_hisr(void)
{
   CLEAR_G2D_INT_STATUS;

   if (!_g2d_hw_hisr_callback)
   {
      IRQUnmask(IRQ_G2D_CODE);
      return;
   }
   else
   {
      (*_g2d_hw_hisr_callback)(NULL);
   }

   IRQUnmask(IRQ_G2D_CODE);
}



static void  _g2d_drv_isr_lisr(void)
{
   IRQMask(IRQ_G2D_CODE);

   #if defined(G2D_FPGA)
      g2d_drv_isr_hisr();
   #else
      drv_gfx_hisr_activate(DRV_GFX_HISR_MODULE_G2D);
   #endif
}



static void _g2d_drv_isr_init()
{
   #if !defined(G2D_FPGA) && !defined(__L1_STANDALONE__)  && !defined(__UL1_STANDALONE__)
      // register G2D HW LISR
      IRQ_Register_LISR(IRQ_G2D_CODE, _g2d_drv_isr_lisr,"G2D ISR");
      IRQUnmask(IRQ_G2D_CODE);

      drv_gfx_hisr_hook_callback(DRV_GFX_HISR_MODULE_G2D, g2d_drv_isr_hisr);
   #endif
}



void g2d_drv_power_on(void)
{
   #if !defined(G2D_FPGA)
      /// Power on G2D Engine
      mm_enable_power(MMPWRMGR_G2D);
   #endif
}



void g2d_drv_power_off(void)
{
   #if !defined(G2D_FPGA)
      /// Power off G2D
      mm_disable_power(MMPWRMGR_G2D);
   #endif
}


void g2d_drv_init(void)
{
   HARD_RESET_G2D_ENGINE;

   if (0 == _g2d_hw_init_flag)
   {
      #if defined(G2D_FPGA)
         EnableIRQ();
         //SAL_IRQ_Code_Unmask(IRQ_G2D_CODE);
         register_isr(IRQ_G2D_CODE, _g2d_drv_isr_lisr);
         //SAL_IRQ_Code_Sens(IRQ_G2D_CODE, LEVEL_SENSITIVE);
      #endif

      IRQSensitivity(IRQ_G2D_CODE, LEVEL_SENSITIVE);

      _g2d_drv_isr_init();
      IRQUnmask(IRQ_G2D_CODE);
   }
   else
   {
      _g2d_hw_init_flag = 1;
   }
}


#endif



kal_int32 g2d_drv_get_hw_status()
{
   return (REG_G2D_STATUS & G2D_STATUS_BUSY_BIT);
}

void g2d_drv_set_replacement_colors(G2D_HANDLE_STRUCT *handle)
{
   /// setting the avoidance and replacement color based on destination color format
   if (KAL_TRUE == handle->colorReplaceEnable)
   {
      /// enable color replacement bit
      REG_G2D_ROI_CON |= G2D_ROI_CON_REPLACEMENT_ENABLE_BIT;

      switch (handle->dstCanvas.colorFormat)
      {
         case G2D_COLOR_FORMAT_GRAY:
         {
            /// REG_G2D_AVOIDANCE_COLOR = handle->colorToAvoid.red;
            /// REG_G2D_REPLACEMENT_COLOR = handle->colorToAvoid.red;
            ASSERT(0);
         }
         break;
         case G2D_COLOR_FORMAT_RGB565:
         {
            REG_G2D_AVOIDANCE_COLOR = G2D_RGB888_TO_RGB565(handle->colorToAvoid.red, handle->colorToAvoid.green,
                                                           handle->colorToAvoid.blue);

            REG_G2D_REPLACEMENT_COLOR = G2D_RGB888_TO_RGB565(handle->colorToReplace.red, handle->colorToReplace.green,
                                                             handle->colorToReplace.blue);
         }
         break;
         case G2D_COLOR_FORMAT_PARGB8888:
         case G2D_COLOR_FORMAT_ARGB8888:
         {
            REG_G2D_AVOIDANCE_COLOR = G2D_ARGB8888_PACKED(handle->colorToAvoid.alpha, handle->colorToAvoid.red,
                                                          handle->colorToAvoid.green, handle->colorToAvoid.blue);

            REG_G2D_REPLACEMENT_COLOR = G2D_ARGB8888_PACKED(handle->colorToReplace.alpha, handle->colorToReplace.red,
                                                            handle->colorToReplace.green, handle->colorToReplace.blue);

         }
         break;
         case G2D_COLOR_FORMAT_RGB888:
         case G2D_COLOR_FORMAT_BGR888:
         {
            REG_G2D_AVOIDANCE_COLOR = G2D_RGB888_PACKED(handle->colorToAvoid.red, handle->colorToAvoid.green,
                                                        handle->colorToAvoid.blue);

            REG_G2D_REPLACEMENT_COLOR = G2D_RGB888_PACKED(handle->colorToReplace.red, handle->colorToReplace.green,
                                                          handle->colorToReplace.blue);


         }
         break;
         case G2D_COLOR_FORMAT_ARGB8565:
         case G2D_COLOR_FORMAT_PARGB8565:
         {

            REG_G2D_AVOIDANCE_COLOR = G2D_ARGB8888_TO_ARGB8565(handle->colorToAvoid.alpha, handle->colorToAvoid.red,
                                                               handle->colorToAvoid.green, handle->colorToAvoid.blue);


            REG_G2D_REPLACEMENT_COLOR = G2D_ARGB8888_TO_ARGB8565(handle->colorToAvoid.alpha, handle->colorToAvoid.red,
                                                                 handle->colorToAvoid.green, handle->colorToAvoid.blue);
         }
         break;
         case G2D_COLOR_FORMAT_ARGB6666:
         case G2D_COLOR_FORMAT_PARGB6666:
         {
            REG_G2D_AVOIDANCE_COLOR = G2D_ARGB8888_TO_ARGB6666(handle->colorToAvoid.alpha, handle->colorToAvoid.red,
                                                               handle->colorToAvoid.green, handle->colorToAvoid.blue);


            REG_G2D_REPLACEMENT_COLOR = G2D_ARGB8888_TO_ARGB6666(handle->colorToAvoid.alpha, handle->colorToAvoid.red,
                                                                 handle->colorToAvoid.green, handle->colorToAvoid.blue);
         }
         break;
         default:
            ASSERT(0);
         break;

      }
   }
}



void g2d_drv_set_clipping_window(G2D_HANDLE_STRUCT *handle)
{
   G2D_WINDOW_STRUCT *targetClipWindow = &handle->targetClipWindow;

   kal_int32 topLeftX = targetClipWindow->topLeft.x;
   kal_int32 topLeftY = targetClipWindow->topLeft.y;
   kal_int32 buttomRightX = targetClipWindow->buttomRight.x;
   kal_int32 buttomRightY = targetClipWindow->buttomRight.y;

   /// -2048 <= x <= 2047
   ASSERT(((unsigned)(topLeftX + 2048)) < 4096);
   ASSERT(((unsigned)(topLeftY + 2048)) < 4096);
   ASSERT(((unsigned)(buttomRightX  + 2048)) < 4096);
   ASSERT(((unsigned)(buttomRightY + 2048)) < 4096);

   #if defined(G2D_FPGA)
      if(handle->clipEnable)
      {
         REG_G2D_ROI_CON |= G2D_ROI_CON_CLIP_ENABLE_BIT;
      }
      else
      {
         REG_G2D_ROI_CON &= ~G2D_ROI_CON_CLIP_ENABLE_BIT;
      }
   #else
      REG_G2D_ROI_CON |= G2D_ROI_CON_CLIP_ENABLE_BIT;
   #endif

   /// clip_min
   REG_G2D_CLP_MIN = (((kal_int16)(topLeftX) & 0xFFFF)<< 16) | ((kal_int16)(topLeftY) & 0xFFFF);
   /// clip_max
   REG_G2D_CLP_MAX = (((kal_int16)(buttomRightX) & 0xFFFF)<< 16) | ((kal_int16)(buttomRightY) & 0xFFFF);
}



void g2d_drv_set_source_color_key(G2D_HANDLE_STRUCT *handle, G2D_COLOR_FORMAT_ENUM colorFormat)
{
   if (KAL_TRUE == handle->srcKeyEnable)
   {
      kal_uint32 src_key = 0;

      ENABLE_G2D_LAYER_CON_SRC_KEY(1);

      switch (colorFormat)
      {
         case G2D_COLOR_FORMAT_GRAY:
         {
            /// src_key = handle->srcKeyValue.red;
            ASSERT(0);
         }
         break;
         case G2D_COLOR_FORMAT_RGB565:
         {
            src_key = G2D_RGB888_TO_RGB565(handle->srcKeyValue.red, handle->srcKeyValue.green, handle->srcKeyValue.blue);
         }
         break;
         case G2D_COLOR_FORMAT_ARGB8888:
         case G2D_COLOR_FORMAT_PARGB8888:
         {
            src_key = G2D_ARGB8888_PACKED(handle->srcKeyValue.alpha, handle->srcKeyValue.red, handle->srcKeyValue.green, handle->srcKeyValue.blue);

         }
         break;
         case G2D_COLOR_FORMAT_RGB888:
         case G2D_COLOR_FORMAT_BGR888:
         {
            src_key = G2D_RGB888_PACKED(handle->srcKeyValue.red, handle->srcKeyValue.green, handle->srcKeyValue.blue);

         }
         break;
         case G2D_COLOR_FORMAT_ARGB8565:
         case G2D_COLOR_FORMAT_PARGB8565:
         {
            src_key = G2D_ARGB8888_TO_ARGB8565(handle->srcKeyValue.alpha, handle->srcKeyValue.red, handle->srcKeyValue.green, handle->srcKeyValue.blue);
         }
         break;
         case G2D_COLOR_FORMAT_ARGB6666:
         case G2D_COLOR_FORMAT_PARGB6666:
         {
            src_key = G2D_ARGB8888_TO_ARGB6666(handle->srcKeyValue.alpha, handle->srcKeyValue.red, handle->srcKeyValue.green, handle->srcKeyValue.blue);
         }
         break;
         default:
            ASSERT(0);
         break;

      }
      SET_G2D_LAYER_SRC_KEY(1, src_key);
   }
}



void g2d_drv_set_dithering(G2D_HANDLE_STRUCT *handle)
{
#if defined(G2D_HW_DITHERING_SUPPORT)
   if(KAL_TRUE == (handle->ditheringEnable))
   {
      if(G2D_DITHERING_MODE_RANDOM_ALGORITHM == (handle->ditheringMode))
      {
         SET_G2D_DI_CON(handle->ditherBitR, handle->ditherBitG, handle->ditherBitB, 0x1);
       
         #if defined(__MTK_TARGET__)
         {
            extern unsigned int drv_get_current_time(void);
            kal_uint32 seed = drv_get_current_time();
            
            SET_G2D_MW_INIT(seed);
            SET_G2D_MZ_INIT(seed);
            
         }
         #elif defined(G2D_FPGA) 
            SET_G2D_MW_INIT(handle->ditherMw);
            SET_G2D_MZ_INIT(handle->ditherMz);
         #else /// defined(G2D_CODEC_STANDALONE)
            SET_G2D_MW_INIT(rand());
            SET_G2D_MZ_INIT(rand());
         #endif
         
      }
      else
      {
         SET_G2D_DI_CON(handle->ditherBitR, handle->ditherBitG, handle->ditherBitB, 0x2);
      }
      
   }
   else
   {
      REG_G2D_DI_CON = 0;
   }
#endif
}



void g2d_drv_set_burst_type(G2D_HANDLE_STRUCT *handle)
{
   #if defined(G2D_FPGA)
      REG_G2D_SLOW_DOWN &= ~(G2D_READ_BURST_TYPE_MASK | G2D_WRITE_BURST_TYPE_MASK);
      REG_G2D_SLOW_DOWN |= (handle->writeBurstType) << 20;
      REG_G2D_SLOW_DOWN |= (handle->readBurstType) << 24;
   #else
      REG_G2D_SLOW_DOWN = 0x00400000;
   #endif
}



void g2d_drv_set_slow_down(G2D_HANDLE_STRUCT *handle)
{
   #if defined(G2D_FPGA)
      REG_G2D_SLOW_DOWN &= ~G2D_SLOW_DOWN_ENABLE_BIT;

      if (KAL_TRUE == (handle->slowDownEnable))
      {
         REG_G2D_SLOW_DOWN |= G2D_SLOW_DOWN_ENABLE_BIT;
         REG_G2D_SLOW_DOWN &= ~G2D_SLOW_DOWN_COUNT_MASK;
         REG_G2D_SLOW_DOWN |= (handle->slowDownCount) & G2D_SLOW_DOWN_COUNT_MASK;
      }
   #endif
}



void g2d_drv_set_tile(G2D_HANDLE_STRUCT *handle)
{
   //Enable Tile
   #if defined(G2D_FPGA)
      ///ASSERT(KAL_FALSE == (handle->autoTileSizeEnable));
      if(KAL_FALSE == (handle->autoTileSizeEnable))
      {
         REG_G2D_ROI_CON |= G2D_ROI_CON_ENABLE_FORCE_TS_BIT;
         switch(handle->tileSize)
         {
            case G2D_TILE_SIZE_TYPE_8x8:
               REG_G2D_ROI_CON |= G2D_ROI_CON_TILE_SIZE_8x8_BIT;
            break;
            case G2D_TILE_SIZE_TYPE_16x8:
               REG_G2D_ROI_CON |= G2D_ROI_CON_TILE_SIZE_16x8_BIT;
            break;
            default:
               ASSERT(0);
         }
      }
      else
      {
      	 REG_G2D_ROI_CON &= ~G2D_ROI_CON_ENABLE_FORCE_TS_BIT;
      }
   #else
      REG_G2D_ROI_CON &= ~G2D_ROI_CON_ENABLE_FORCE_TS_BIT;
      ///REG_G2D_ROI_CON |= G2D_ROI_CON_TILE_SIZE_8x8_BIT;
   #endif
}



void g2d_drv_set_hw_hisr_callback(G2D_CALLBACK_FUNC_PTR hisr_callback)
{
   _g2d_hw_hisr_callback = hisr_callback;
}



/// Check function
G2D_STATUS_ENUM g2d_drv_check_dst_canvas_info(kal_uint32 pitch)
{
  if(pitch > 0x2000)
    return G2D_STATUS_RANGE_CHECK_FAIL;
  else
    return G2D_STATUS_OK;
}



/// Check function
G2D_STATUS_ENUM g2d_drv_check_src_canvas_info(kal_uint32 pitch)
{
  if(pitch > 0x2000)
    return G2D_STATUS_RANGE_CHECK_FAIL;
  else
    return G2D_STATUS_OK;
}



/// Check function
G2D_STATUS_ENUM g2d_drv_check_src_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   /// 0 <= x <= 2047
   if(((unsigned)(x)) > 2047)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(y)) > 2047)
      return G2D_STATUS_RANGE_CHECK_FAIL;

   /// 1 <= x <= 2048
   if(((unsigned)(w - 1)) >= 2048)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(h - 1)) >= 2048)
      return G2D_STATUS_RANGE_CHECK_FAIL;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_check_lt_src_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
  return g2d_drv_check_src_window(x, y, w, h);
}



G2D_STATUS_ENUM g2d_drv_check_dst_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   /// -2048 <= x <= 2047
   if(((unsigned)(x + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(y + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;

   /// 1 <= x <= 2048
   if(((unsigned)(w - 1)) >= 2048)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(h - 1)) >= 2048)
      return G2D_STATUS_RANGE_CHECK_FAIL;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_check_lt_dst_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
  return g2d_drv_check_dst_window(x, y, w, h);
}



G2D_STATUS_ENUM g2d_drv_check_clip_window(kal_int32 x, kal_int32 y, kal_uint32 x_max_clip, kal_uint32 y_max_clip)
{
   /// -2048 <= x <= 2047
   if(((unsigned)(x + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(y + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   /// -2048 <= x <= 2047
   if(((unsigned)(x_max_clip + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;
   if(((unsigned)(y_max_clip + 2048)) >= 4096)
      return G2D_STATUS_RANGE_CHECK_FAIL;

   return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_query_src_canvas_info(kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height)
{
  *min_width = 1;
  *max_width = 2048;
  *min_height = 1;
  *max_height = 2048;

  return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_query_dst_canvas_info(kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height)
{
  *min_width = 1;
  *max_width = 2048;
  *min_height = 1;
  *max_height = 2048;

  return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_query_src_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                         kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
  *min_x = 0;
  *max_x = 2047;
  *min_y = 0;
  *max_y = 2047;

  *min_w = 1;
  *max_w = 2048;
  *min_h = 1;
  *max_h = 2048;

  return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_query_dst_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                         kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
  *min_x = -2048;
  *max_x = 2047;
  *min_y = -2048;
  *max_y = 2047;

  *min_w = 1;
  *max_w = 2048;
  *min_h = 1;
  *max_h = 2048;

  return G2D_STATUS_OK;
}



G2D_STATUS_ENUM g2d_drv_query_lt_src_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                            kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
  return g2d_drv_query_src_window(min_x, max_x, min_y, max_y, min_w, max_w, min_h, max_h);
}

G2D_STATUS_ENUM g2d_drv_query_lt_dst_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                            kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h)
{
  return g2d_drv_query_dst_window(min_x, max_x, min_y, max_y, min_w, max_w, min_h, max_h);
}


#endif /// __DRV_GRAPHICS_G2D_6260_SERIES__

