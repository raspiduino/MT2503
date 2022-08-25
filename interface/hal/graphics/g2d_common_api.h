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
 *   g2d_common_api.h
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
#ifndef __G2D_COMMON_H__
#define __G2D_COMMON_H__

#include "kal_general_types.h"

#include "g2d_enum.h"

#include "gfx_cache_switch_behavior_enum.h"

/// re-define structure
/// This is for compatible with old AP
typedef struct G2D_HANDLE_STRUCT_T G2D_HANDLE_STRUCT;

/**
 *  Perform the G2D hardware engine initalization
 *  @remark must be call before using the G2D engine
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function is used to initialize the G2D hardware
 *           This function will registers the LISR, HISR entry function \n
 *           of G2D module and unmasks G2D IRQ bit
 *           Must be called before using any G2D API
 */
G2D_STATUS_ENUM g2dInit(void);



/**
 *  Get g2d handle
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dGetHandle(G2D_HANDLE_STRUCT **handlePtr, G2D_CODEC_TYPE_ENUM codecType, G2D_GET_HANDLE_MODE_ENUM handleMode);



/**
 *  Release g2d handle
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dReleaseHandle(G2D_HANDLE_STRUCT *handle);


/**
 *  Query the destination buffer range
 *  @param min_width  : minimum of width
 *  @param max_width  : maximum of width
 *  @param min_height : minimum of height
 *  @param max_height : maximum of height
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dQueryDstRGBBufferRange(G2D_HANDLE_STRUCT *handle,
                                          kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);



/**
 *  Set current G2D HW owner
 *  @param owner      : G2D or GOVL
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dSetOwner(G2D_HANDLE_STRUCT *handle, G2D_CODEC_OWNER_ENUM owner);



/**
 *  Setting the callback function for the G2D engine
 *  @param  g2d_status :
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the callback function user defined.
 *           Only if the callback function is set, the interrupt of
 *           hardware G2D will be enable, else the interrupt will be
 *           disable
 *
 */
G2D_STATUS_ENUM g2dSetCallbackFunction(G2D_HANDLE_STRUCT *handle, G2D_CALLBACK_FUNC_PTR g2d_callback);



/**
 *  Setting the clipping window for the destination buffer, all data outside the clipping window will be remained \n
 *  @param clip_enable : enable/disable clipping window flag
 *  @param (x,y)       : base vertex coordinate of clipping window
 *  @param w           : width of the clipping window
 *  @param h           : height of the clipping window
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the clipping window for destination buffer
 *           If clip_enable is TRUE,all data outside the clipping window \n
 *           will be discarded
 */
G2D_STATUS_ENUM g2dSetDstClipWindow(G2D_HANDLE_STRUCT *handle, kal_bool clip_enable, kal_int32 x, kal_int32 y, kal_int32 w, kal_int32 h);



/**
 *  Setting the Color of replacement features
 *  @param color_replace_enable : specified the color replacement is enable or disable
 *  @param a0 : alpha color component to be replaced
 *  @param r0 : red color component to be replaced
 *  @param g0 : green color component to be replaced
 *  @param b0 : blue color component to be replaced
 *  @param a1 : alpha color component to substitute
 *  @param r1 : red color component to substitute
 *  @param g1 : green color component to substitute
 *  @param b1 : blue color component to substitute
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the color components of replacement and
 *           substitute
 */
G2D_STATUS_ENUM g2dSetColorReplacement(G2D_HANDLE_STRUCT *handle,
                                       kal_bool color_replace_enable,
                                       kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0,
                                       kal_uint8 a1, kal_uint8 r1, kal_uint8 g1, kal_uint8 b1);



/**
 *  Setting the source key flag and source key value
 *  @param src_key_enable : enable/disable source color key
 *  @param a0 : alpha color component of source key color
 *  @param r0 : red color component of source key color
 *  @param g0 : green color component of source key color
 *  @param b0 : blue color component of source key color
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 *       if src_key_enable, the setted color will be transparent
 */
G2D_STATUS_ENUM g2dSetSrcKey(G2D_HANDLE_STRUCT *handle, kal_bool src_key_enable, kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0);



/**
 *  Setting the destination buffer information
 *  @param addr         : base address of the destination buffer
 *  @param width        : width of the destination buffer
 *  @param height       : height of the destination buffer
 *  @param color_format : enumaration type of the source color format(GRAY,RGB565,RGB888,ARGB8888,etc)
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the destination buffer information
 *           Must be called before starting the G2D features
 */
G2D_STATUS_ENUM g2dSetDstRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                       kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                       kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);


/**
 *  Setting the Destination buffer cache switch behavior
 */
G2D_STATUS_ENUM g2dSetDstBufferSwitchBehavior(G2D_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);

/**
 *  Setting the Source buffer cache switch behavior
 */
G2D_STATUS_ENUM g2dSetSrcBufferSwitchBehavior(G2D_HANDLE_STRUCT *handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);


/**
 *  Getting the status of G2D engine
 *  @return : if the return is equal to 1, it means that the G2D engine is busy.\n
 *             else the G2D operation is complete
 *  @remarks  This function provide the user to poll the status of G2D, if the callback function
 *            is not setted, user should use this function to check if the 2D engine is busy or not
 */
kal_int32 g2dGetStatus(G2D_HANDLE_STRUCT *handle);



/**
 *  Query the supported function for G2D
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 */
G2D_STATUS_ENUM g2dQuerySupport(G2D_CODEC_TYPE_ENUM codecType, G2D_SUPPORT_FUNCTION_ENUM function);

/**
 *  Setting the source key flag and source key value
 *  @param dithering enable : enable/disable dithering
 *  @param method : dithering's method (random and fixed pattern)
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 *       if dithering, the destination buffer will be added noise dependent on destination color and dithering method.
 */
G2D_STATUS_ENUM g2dSetDithering(G2D_HANDLE_STRUCT *handle, kal_bool dithering_enable, G2D_DITHERING_MODE_ENUM method);


//G2D_STATUS_ENUM g2dSetSlowDownCount(kal_bool slow_down_enable, kal_uint32 slow_down_count);
//G2D_STATUS_ENUM g2dSetReadBurstType(G2D_READ_BURST_TYPE_ENUM read_burst_type);

//G2D_STATUS_ENUM g2dSetWriteBurstType(G2D_WRITE_BURST_TYPE_ENUM write_burst_type);
//G2D_STATUS_ENUM g2dSetCommandQueueBurstType(G2D_CMD_QUEUE_BURST_TYPE_ENUM burst_type);



#if defined(G2D_FPGA)

   G2D_STATUS_ENUM g2dSetReadBurstType(void *handle, G2D_READ_BURST_TYPE_ENUM read_burst_type);
   G2D_STATUS_ENUM g2dSetWriteBurstType(void *handle, G2D_WRITE_BURST_TYPE_ENUM write_burst_type);
   G2D_STATUS_ENUM g2dSetSlowDownCount(void *handle, kal_bool slow_down_enable, kal_uint32 slow_down_count);
   G2D_STATUS_ENUM g2dSetTileSize(void *handle, kal_bool auto_tile_size_enable, G2D_TILE_SIZE_TYPE_ENUM tile_size);
   G2D_STATUS_ENUM g2dSetMaxOutStandingNumber(void *handle, G2D_MAX_OUTSTANDING_NUM_ENUM max_outstanding);

#endif
#endif  /* common.h */



/*!@mainpage HW G2D driver Interface
 *  @author  Robin Huang
 *  @version 1.0
 *  @date    2008/4/24
 *
 * @section G2D driver interface introduction
 * The purpose of this document is to provide an clear definition and usage of the
 * G2D driver APIs.
 * All the related G2D APIs are described in this document. For the usage of G2D APIs,
 * it usually combined with the GDI interface. The AP programmers might use the APIs
 * GDI provided instead of use G2D API dircetly. Howerver, if you want to access the
 * G2D HW directly, these APIs could assist you interacting with HW G2D Engine.
 * It is noted that only the bitblt and font draw features are provided in this driver
 * API document.
 *
 * The APIs are supported after 08A branch. \n
 */

 /*! @page page1 User Manual
      This manual would give a simple example about using G2D interface to perform bitblt & font draw.\n


      @section sec1 Sample Code, this sample code is to demonstrate how to use G2D APIs.
      @code

      kal_uint8 *fb_ptr = NULL;
      kal_uint32 fb_w, fb_h;

      static void _display_result(kal_uint32 w, kal_uint32 h, kal_uint8 *buf, gdi_handle layer_active, kal_uint32 bpp);
      static void _copy_image_to_local_buf(kal_uint8 *dst_ptr, kal_uint8 *src_ptr, kal_int32 w, kal_int32 h, kal_uint32 bpp);

      #include "g2d_cmn_hdr.h"

      static void G2D_API_USAGE_EXAMPLE(void);
      static void _g2d_bitblt_test(void);
      static void _g2d_font_test(void);

      void g2d_call_back_func(G2D_STATUS_ENUM status);

      /// test image and test buffer
      #include "src320_240.dat"
      #include "src240_320.dat"
      #include "dst240_320.dat"


      kal_uint8 src_buf[240*320*4];
      kal_uint8 dst_buf[240*320*4];

      kal_uint8 font_a[100] = {0x1C,
                               0x22,
                               0x63,
                               0x7F,
                               0x41,
                               0x41 };


      void mmi_entry_dev_app_scr(void)
      {

          EntryNewScreen(SCR_ID_DEVAPP_MAIN, NULL, mmi_entry_dev_app_scr, NULL);

          gdi_layer_clear(GDI_COLOR_BLACK);
          gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

          SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

          /// G2D_API_USAGE_EXAMPLE();

          _g2d_bitblt_test();
          _g2d_font_test();

      }


      volatile kal_int32 callback_flag = 1;
      void g2d_call_back_func(G2D_STATUS_ENUM status)
      {
         callback_flag = 0;
      }



      void _g2d_bitblt_test()
      {
         kal_int32 i;
         gdi_handle g2d_active_layer = 0;
         G2D_COLOR_FORMAT_ENUM  src_clr_fmt = G2D_COLOR_FORMAT_RGB565;
         G2D_COLOR_FORMAT_ENUM  dst_clr_fmt = G2D_COLOR_FORMAT_RGB565;
         BITBLT_ROT_ANGLE_ENUM rotate_mode = BITBLT_MIRROR_ROTATE_90;
         BITBLT_MODE_ENUM      bitblt_mode = BITBLT_ONLY;   /// either BITBLT_ONLY, BITBLT_ALPHA_BLENDING, or BITBLT_ROP2

         kal_uint32 src_rect_w  = 75;
         kal_uint32 src_rect_h  = 150;

         kal_uint32 dst_rect_w  = 150;
         kal_uint32 dst_rect_h  = 75;

         _copy_image_to_local_buf(&src_buf[0], src320_240, 320, 240, 2);
         _copy_image_to_local_buf(&dst_buf[0], dst240_320, 240, 320, 2);

         /// polling, use g2dGetStatus();
         {
            g2dInit();
            /// common api setting
            g2dSetDstBufferInfo((kal_uint8 *)dst_buf, 240, 320, dst_clr_fmt);

            g2dSetColorReplacement(KAL_FALSE, 0, 255, 0, 0,
                                              0, 0, 0, 255);

            g2dSetDstClip(KAL_TRUE, 0, 0, 240, 320);

            g2dSetSrcKey(KAL_FALSE, 0, 0, 0, 0);

            /// bitblt api setting
            g2dBitBltSetSrcBufferInfo((kal_uint8 *)src_buf, 320, 240, src_clr_fmt);

            g2dBitBltSetDestinationKey(KAL_FALSE, 0, 0, 0, 0);
            g2dBitBltSetOperationMode(bitblt_mode);

            g2dBitBltSetDstRect(50, 50, dst_rect_w, dst_rect_h);
            g2dBitBltSetSrcRect(50, 50, src_rect_w, src_rect_h);

            /// BITBLT_MIRROR_ROTATE_90 = 0, BITBLT_ROTATE_90, BITBLT_ROTATE_270, BITBLT_MIRROR_ROTATE_270
            for (i = 0 ; i < 4 ; i++)
            {
               rotate_mode = i;
               g2dBitBltSetRotateMode(rotate_mode);
               g2dBitBltStart();
               while(g2dGetStatus()) {} ;

               _display_result(240, 320, &dst_buf[0], g2d_active_layer, 2);

               /// refresh internal buffer
               _copy_image_to_local_buf(&dst_buf[0], dst240_320, 320, 240, 2);
            }

            g2dDeInit();
          }

         /// interrupt, use  g2dSetCallbackFunction(G2D_CALLBACK_FUNC_PTR g2d_status);
         {
            g2dInit();

            /// common api setting
            g2dSetCallbackFunction(&g2d_call_back_func);

            g2dSetDstBufferInfo((kal_uint8 *)dst_buf, 240, 320, dst_clr_fmt);

            g2dSetColorReplacement(KAL_FALSE, 0, 255, 0, 0,
                                              0, 0, 0, 255);

            g2dSetDstClip(KAL_TRUE, 0, 0, 240, 320);

            g2dSetSrcKey(KAL_FALSE, 0, 0, 0, 0);

            /// bitblt api setting
            g2dBitBltSetSrcBufferInfo((kal_uint8 *)src_buf, 320, 240, src_clr_fmt);

            g2dBitBltSetDestinationKey(KAL_FALSE, 0, 0, 0, 0);
            g2dBitBltSetOperationMode(bitblt_mode);

            g2dBitBltSetDstRect(0, 0, dst_rect_w, dst_rect_h);
            g2dBitBltSetSrcRect(0, 0, src_rect_w, src_rect_h);

            /// BITBLT_MIRROR_ROTATE_90 = 0, BITBLT_ROTATE_90, BITBLT_ROTATE_270, BITBLT_MIRROR_ROTATE_270
            for (i = 0 ; i < 4 ; i++)
            {
               rotate_mode = i;
               g2dBitBltSetRotateMode(rotate_mode);
               g2dBitBltStart();

               while(callback_flag) {};
               callback_flag = 1;

               _display_result(240, 320, &dst_buf[0], g2d_active_layer, 2);

               /// refresh internal buffer
               _copy_image_to_local_buf(&dst_buf[0], dst240_320, 320, 240, 2);
            }

            g2dDeInit();
          }
      }



      static void _g2d_font_test(void)
      {

         kal_int32 test_tilt_table[32];
         gdi_handle g2d_active_layer = 0;

         G2D_COLOR_FORMAT_ENUM src_clr_fmt = G2D_COLOR_FORMAT_RGB565;
         G2D_COLOR_FORMAT_ENUM dst_clr_fmt = G2D_COLOR_FORMAT_RGB565;

         _copy_image_to_local_buf(&dst_buf[0], dst240_320, 240, 320, 2);

         /// display the destination image before G2D action
         _display_result(240, 320, &dst_buf[0], g2d_active_layer, 2);

         g2dInit();

         /// common api setting
         g2dSetDstBufferInfo(dst_buf, 240, 320, dst_clr_fmt);

         g2dSetColorReplacement(KAL_FALSE,
                                0, 255, 0, 0,
                                0, 0, 0, 255);

         g2dSetDstClip(KAL_FALSE, 0, 0, 8, 8); /// x,y,w,h

         g2dSetSrcKey(KAL_FALSE, 0, 0, 0, 0);

         /// font related api setting
         g2dFontSetSrcBufferInfo(font_a);

         g2dFontSetTiltMode(KAL_FALSE, &test_tilt_table[0]);

         g2dFontSetForegroundColor(0x00, 0x00, 0x00, 0x00); /// draw black color font

         g2dFontSetBackgroundColor(KAL_FALSE, 0, 148, 131, 187);

         g2dFontSetObjInfo(0, 0, 8, 8);

         g2dFontCachingStart();

         while(g2dGetStatus()) {};

         g2dDeInit();

         _display_result(240, 320, &dst_buf[0], g2d_active_layer, 2);
      }



      static void _display_result(kal_uint32 w, kal_uint32 h, kal_uint8 *buf, gdi_handle layer_active, kal_uint32 bpp)
      {

         gdi_layer_create_using_outside_memory(0, 0, w, h, &layer_active, &buf[0], w*h*bpp);

         fb_ptr = gdi_act_layer->buf_ptr;
         fb_w   = gdi_act_layer->width;
         fb_h   = gdi_act_layer->height;

         gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
         gdi_layer_blt_ext(layer_active, 0, 0, 0, 0, 0, 0, 0, fb_w - 1, fb_h - 1);

      }



      static void _copy_image_to_local_buf(kal_uint8 *dst_ptr, kal_uint8 *src_ptr, kal_int32 w, kal_int32 h, kal_uint32 bpp)
      {
         kal_int32 i = 0;

         for (i = 0; i < w * h * bpp ; i++)
         {
            dst_ptr[i] = src_ptr[i];
         }

      }



      static void G2D_API_USAGE_EXAMPLE(void)
      {
          g2dInit();
             .
          common API setting
             .
             .
             .
          feature related API setting
             .
             .
             .
          g2dXXXXStart()

          g2DeInit();

      }
      @endcode
*/
