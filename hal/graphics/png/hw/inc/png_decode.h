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
 *    png_decode.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG HW decoder API header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PNG_DECODE_H__
#define __PNG_DECODE_H__

#include "kal_general_types.h"
#include "png_decode_structure.h"
#include "drv_features_png.h"

/// #ifdef PNG_WIN32_STANDALONE
///    #include "kal_non_specific_general_types.h"
/// #endif //   PNG_WIN32_STANDALONE
/// 
/// /// ASSERT defintion
/// #ifdef PNG_WIN32_STANDALONE
///    #ifdef WIN32
///       #ifndef ASSERT
///          #include "assert.h"
///          #define ASSERT assert
///       #endif
///    #else
///       #include "string.h"
///       #ifndef ASSERT
///          #define ASSERT(I) while(!(I)) {};
///       #endif
///    #endif
/// #else
///    #include "kal_release.h"
/// #endif


#if defined(USE_HW_PNG_DECODER)

#include "rs_buffer.h"
#include "png_drv_common.h"
#include "png_info.h"
/// #include "png_status.h"
#include "png_decode_enum.h"

#define min(x,y) (((x) < (y)) ? (x) : (y))

/// typedef void (*callback_func_ptr)(PNG_RET_ENUM);

//------------------------ public API----------------------------------------------------

/** 
 *  Initialize png decoder hardware and software data structure. 
 *  @remark MUST be invoked at the very first
 */   
PNG_STATUS_ENUM pngInit(void);

/** 
 *  call this function to reset all configurations 
 *  @remark NOT ALLOWED INVOKING WHEN DECODING \n
 */
PNG_STATUS_ENUM pngReset(void);

/** 
 *  Deinitialize hardware png decoder and software data structure  
 *  @remark MUST be invoked at last if no further using png decoder  
 */   
PNG_STATUS_ENUM pngFinalize(void);

/** 
 *  register the callback function which is invoked when hardware png decoder raises an interrupt
 *  @param png_callback a function pointer which return void with PNG_STATUS_ENUM as parameters
 */   
PNG_STATUS_ENUM pngHookCallback(callback_func_ptr png_callback);

/** 
 *  Set the working buffers in internal / external memory for PNG decoder
 *  @param internalBuf internal memory start address as working buffer of png decoder (MUST BE WORD ALIGNED)
 *  @param externalBuf external memory start address as working buffer of png decoder (MUST BE WORD ALIGNED)
 */      
PNG_STATUS_ENUM pngSetWorkingBuffer (kal_uint32* internalBuf, kal_uint32* externalBuf);

/** 
 *  set png source through ring_sequential buffer API in RSB_OP_SEQUENTIAL_BUFFER operation mode
 *  @param rsb pointer to the a RS_BUFFER structure \n
 *  @param is_src_end indicate whether the source is the last segment
 *  @remark caller must write source to sequential buffer before calling pngSetWorkingBuffer() \n
 *               rs buffer's head must 4-byte aligned
 */   
PNG_STATUS_ENUM pngSetSourceData(RS_BUFFER *rsb, kal_bool is_src_end);

/** 
 *  set the start address, dimension, and output color format of canvas (png lcd display buffer)
 *  @param canvas_start_adr the canvas buffer start address (MUST BE WORD ALIGNED)
 *  @param width canvas width
 *  @param height canvas height
 *  @param out_color_format canvas output color format
 */      
PNG_STATUS_ENUM pngSetCanvas(void* canvas_start_adr, kal_int32 width, kal_int32 height, PNG_DECODE_COLOR_FORMAT_ENUM out_color_format);

/** 
 *  Set the resizing output window with start coordinate, width and height
 *  @param up_left_x x-coordinate of upper-left corner of resizing destination window
 *  @param up_left_y y-coordinate of upper-left corner of resizing destination window
 *  @param dst_w width of resizing destination window
 *  @param dst_h height of resizing destination window
 */      
PNG_STATUS_ENUM pngSetOutputWindow(kal_int32 up_left_x, kal_int32 up_left_y, kal_int32 dst_w, kal_int32 dst_h);

/** 
 *  Set output PNG image clipping window
 *  @param  up_left_x x-coordinate of upper-left corner of clipping window
 *  @param  up_left_y y-coordinate of upper-left corner of clipping window
 *  @param  down_right_x x-coordinate of down-right corner of clipping window
 *  @param  down_right_y y-coordinate of down-right corner of clipping window
 */      
PNG_STATUS_ENUM pngSetClipWindow(kal_int32 up_left_x, kal_int32 up_left_y, kal_int32 down_right_x, kal_int32 down_right_y);

/** 
 *  For Alpha blending with user assigned alpha value
 *  @param userAlpha user assigned alpha value
 */   
PNG_STATUS_ENUM pngSetAlphaValue(kal_int32 userAlpha);

/** 
 *  set alpha blending mode and blending buffer color format \n
 *  For Alpha blending outcome effects, there are 4 effect settings.\n
 *  1. user-specified single alpha value (always be per-alpha):\n
 *  dstColor = userAlpha x pngColor + (1 - userAlpha) x bldColor \n\n
 *  
 *  2. PNG built-in alpha:\n
 *  dstColor = pngAlpha x pngColor + (1 - pngAlpha) x bldColor\n
 *    pngAlpha may comes from several sources:\n
 *  i.   the alpha component of the pixel if the color type is ARGB \n
 *  ii.  the alpha component of the pixel if the color type is grayscale with alpha \n
 *  iii. the single alpha defined in the transparent chunk if the color type is not palette type \n
 *  iv.  the per-palette-entry alpha defined in the transparent chunk if the color type is palette type \n\n
 *  
 *  3. blending buffer (always be per-pixel):\n
 *  dstColor = dstAlpha x pngColor + (1 - dstAlpha) x bldColor\n
 *      This mode works only when the destination buffer is ARGB mode.\n
 *  \n
 *  4. none\n
 *  \n
 *  @param mode set blending mode from PNG_BLEND_MODE_ENUM.
 *  @param color_format the blending buffer color format from PNG_DECODE_COLOR_FORMAT_ENUM
 */   
PNG_STATUS_ENUM pngSetBlendingMode(PNG_BLEND_MODE_ENUM mode, PNG_DECODE_COLOR_FORMAT_ENUM color_format);

/** 
 *  set the blending buffer start address to PNG decoder
 *  @param blend_buf_adr the start address of blending buffer
 */   
PNG_STATUS_ENUM pngSetBlendingBuffer(void* blend_buf_adr);

/** 
 *  set the replaced color as new color
 *  @param orgColor original color that should be replaced
 *  @param newColor new color that will replace the original color
 */
PNG_STATUS_ENUM pngSetReplaceColor(png_color orgColor, png_color newColor);

/** 
 *  set timeout period to handle a hardware hang
 *  @param timeout_msec timeout value (unit = 10 ms)
 */      
PNG_STATUS_ENUM pngSetTimeoutValue(kal_int32 timeout_msec);

/** 
 *   trigger PNG HW to decode the image after AP/GDI setting all property of PNG decoder
 */
PNG_STATUS_ENUM pngDecodeStart(void);

/** 
 *   Resume hw decoder to decode from the source address set by pngSetSourceData() \n
 *   should be invoked by GDI/AP after hw decoder raising an interrupt
 */
PNG_STATUS_ENUM pngDecodeResume(void);

/**
 *  Get the working buffer configuration of hardware png decoder
 *  @param internal_mem_sz return the size (in bytes)  of working buffer in internal memory
 *  @param external_mem_sz return the size (in bytes) of working buffer in external memory
 */
PNG_STATUS_ENUM pngGetWorkingBufferSize(kal_uint32* internal_mem_sz, kal_uint32* external_mem_sz);

/**
 *  Get the width and height of png image 
 *  @param src_w return the image width in pixel
 *  @param src_h return the image height in pixel
 */
PNG_STATUS_ENUM pngGetImgDimension(kal_int32* src_w, kal_int32* src_h);


/**
 *  Output file built-in background color when transparent
 */
PNG_STATUS_ENUM pngSetBgColorOut(void);

/**
 *  Query if file alpha exists
 *  @return 1 if file alpha exists
 *  @return 0 if file alpha does not exist
 *  @return -1 if pngSetSourceData() is not invoked in advance
 * 
 */
kal_int32 pngFileAlphaExist(void);


/**
 *  Query if file transparency exists
 *  @return 1 if file transparency exists
 *  @return 0 if file transparency does not exist
 *  @return -1 if pngSetSourceData() is not invoked in advance
 * 
 */
kal_int32 pngFileTransparencyExist(void);


/**
 *  Query hw png decoder status for polling
 *  @return PNG_STATUS_OK decoding is completely done
 *  @return PNG_STATUS_IN_DECODING hw png decoder is decoding
 *  @return PNG_STATUS_DECODE_INCOMPLETE decoding pause due to input source empty 
 *  @return PNG_STATUS_ERROR_DECODE_FAILED decoding error happened
 * 
 */
PNG_STATUS_ENUM pngGetDecodeStatus(void);

PNG_STATUS_ENUM pngGetDecodeState(PNG_DECODER_STATE_ENUM *decoderState);


void _pngDecGetState(PNG_DECODER_STATE_ENUM *dec_state);
void _pngDecSetState(PNG_DECODER_STATE_ENUM new_dec_state);
void pngGetInfo(MY_PNG_INFO **my_info_ptr);
void pngGetHwCfg(PNG_HW_INFO **my_cfg_ptr);
#endif //   #if defined(USE_HW_PNG_DECODER)
#endif //   __PNG_DECODE_H__


/*!@mainpage PNG decoder interface
 *  @author  Loreal Chang
 *  @version 1.0
 *  @date    2007/12/10
 *  
 * @section PNG decoder interface introduction
 * The document is to provide one obvious document that descripts software interface for GDI and Application 
 * which have to use hardware PNG decoder. \n
 * This software inteface interacts between GDI and PNG hardware engine. GDI/AP could just use 
 * these functions to set png decoding configurations, and trigger the process of PNG decoder 
 * HW engine.\n\n
 *
 *
 * The API is supported after 07B branch. \n
 *
 */

/*! @page page1 User Manual
      This manual would give a simple example about using decoder interface to decode a png image.\n
      
      @section sec1 Example - Decode a png image throug png decoder interface
         A function call diagram is as follow:
         @image html sw_png_state_machine.png "function call diagram"
      @subsection subsec1 1. Initialization
         This function must be invoked before any other functions to initialize png decoder. \n
         1-1 pngInit() \n             
         \n
      @subsection subsec2 2. configuration
         the following five mandatory functions for configuring png decoder is recommanded to be invoked in order: \n
         2-1 pngSetWorkingBuffer() \n
         2-2 pngSetSourceData() \n
         2-3 pngSetCanvas() \n
         2-4 pngSetOutputWindow() \n
         2-5 pngHookCallback() \n
         \n
         To this time, other functions for configuring png decoder is allowed to be invoked without precedence constraints. \n 
         @li pngSetClipWindow() \n
         @li pngSetAlphaValue() \n
         @li pngSetBlendingMode() \n
         @li pngSetBlendingBuffer() \n
         @li pngSetReplaceColor() \n
         @li pngSetBgColorOut() \n
         @li pngSetTimeoutValue() \n
         \n
      @subsection subsec3 3. Decoding 
         After configuring png decoder, trigger png decoding by invoking this function: \n
         3 -1 pngDecodeStart() \n         
         \n
      @subsection subsec4 4. Pause & Resume
         When png decoder finishs decoding source data set by user, the callback function registered in advance will be invoked. \n
         In this way, users can decide whether or not to resume decoding according to the return status. \n
         \n 
            if return status is PNG_STATUS_DECODE_INCOMPLETE, which means png decoder has decodes partial image source, users must \n
            set remaining image source by calling: \n
               pngSetSourceData() \n
               pngDecodeResume() \n
         \n
            if return status is PNG_STATUS_OK, which means png decoder has decoded a complete image source \n
            users can call: \n
               pngReset() to reset all configurations, then set new configurations to decode another source image \n
               pngFinalize() to terminate the processing of decoding \n
         \n
            if return status is PNG_DECODE_ERR, png decoder will be reset implictly (pngReset() is invoked) \n 

      @section sec2 Pseudo Code
      @code

 
      #ifdef USE_HW_PNG_DECODER 
      #include "png_decode.h"
      #include "med_utility.h"
      #include "app_str.h"
      #include "fsal.h"
      
      #include "PNG_IMG_HVGA.h"
      #include "PNG_IMG_QVGA.h"
      #include "PNG_IMG_VGA.h"
      #include "PNG_IMG_WQVGA.h"
      #include "PNG_IMG_WVGA.h"
      
      static png_img_idx = 0;
      static const kal_uint8 *png_img_arr[] = 
      {   
         &png_img_QVGA[0],
         &png_img_WQVGA[0],
         &png_img_HVGA[0],
         &png_img_VGA[0],   
         &png_img_WVGA[0]
      };
      static const kal_int32 png_img_size[] = 
      {
         
         sizeof(png_img_QVGA),
         sizeof(png_img_WQVGA),
         sizeof(png_img_HVGA),
         sizeof(png_img_VGA),      
         sizeof(png_img_WVGA)
      };
      
      static kal_int32 png_img_dec_ms[5] = {0};
      
      PNG_STATUS_ENUM _png_decode_ret;
      volatile kal_int32 hw_interrupted;
      
      __align(4) void *int_mem = NULL;
      __align(4) void *ext_mem = NULL;
      kal_uint32 internal_mem_sz = 0;
      kal_uint32 external_mem_sz = 0;
      
      // BUFFER_SIZE is recommanded to be at least 1KB, and sequential buffer must be 4-byte aligned
      #define BUFFER_SIZE 1024
      __align(4) kal_uint8 my_seq_buf[BUFFER_SIZE];
      
      #define CANVAS_WIDTH 480
      #define CANVAS_HEIGHT 800
      #define PNG_OUTPUT_BLEND_COLOR_FORMAT PNG_FORMAT_RGB565
      #define MAX_BUFFER_SIZE CANVAS_WIDTH * CANVAS_HEIGHT * 2
      static kal_uint8 my_canvas[MAX_BUFFER_SIZE];  // assume canvas output format is PNG_FORMAT_RGB565
      //void *my_canvas;
      static kal_uint8 b_buffer[MAX_BUFFER_SIZE];
      
      void 
      decodeCallBack(PNG_STATUS_ENUM ret) 
      {  
         // should send message instead of invoking function
         _png_decode_ret = ret;      
         hw_interrupted = 1;
      
      }
      
      
      
      void 
      pngTestReset(void)
      {
         pngReset();
         
         // MODIFY: 
         _png_decode_ret = 0;  
         hw_interrupted = 0;          
         memset(my_seq_buf, 0, sizeof(my_seq_buf));
           
      }
      
      #endif //   #ifdef USE_HW_PNG_DECODER

      
             
      void mmi_entry_dev_app_scr(void)
      {
    
          EntryNewScreen(SCR_ID_DEVAPP_MAIN, NULL, mmi_entry_dev_app_scr, NULL);
      
          gdi_layer_clear(GDI_COLOR_BLACK);
          gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
          gdi_layer_set_source_key(0, 0);
          
         #ifdef USE_HW_PNG_DECODER 
         {
            kal_uint32 png_start_time = 0;
            kal_uint32 png_decode_duration = 0; 
            kal_uint32 png_decode_loop_count = 20;
                                  
            const kal_uint8 *read_ptr;           
            RS_BUFFER rsb;     
            kal_int32 ret_value;
            kal_bool is_src_end;
            kal_int32 src_size;             
            kal_int32 i;
                                
            {                                                
               pngGetWorkingBufferSize(&internal_mem_sz, &external_mem_sz);
                    
               int_mem = (void *)med_alloc_int_mem(internal_mem_sz);
               ext_mem = (void *)med_alloc_ext_mem(external_mem_sz);
         
               ASSERT(int_mem);
               ASSERT(ext_mem);         
            }
                  
            while (KAL_TRUE)
            {
               //----------------------------START OF TIME MEASUREMENT-----------------------------            
               png_start_time = drv_get_current_time();              
               
               for (i = 0; i < png_decode_loop_count; i++)
               {                                    
                  //------------------------------initialization--------------------------------      
                  
                  ret_value = rsbInit(&rsb, &my_seq_buf, BUFFER_SIZE, RSB_BIG_ENDIAN, RSB_OP_SEQUENTIAL_BUFFER);
                  ASSERT(1 == ret_value);
                  
                  ret_value = pngInit();
                  ASSERT(PNG_STATUS_OK == ret_value);      
                  
                  pngTestReset();   
                  
                  //------------------------------MANDATORY-------------------------------------
                  
                  //------------------------------hook interrupt call back function-------------
                  pngHookCallback(&decodeCallBack);   
                  
                  //------------------------------Set Working Buffer----------------------------
                  {                           
                     memset(ext_mem, 0, external_mem_sz);
                     memset(int_mem, 0, internal_mem_sz);           
                              
                     ret_value = pngSetWorkingBuffer((kal_uint32 *)int_mem, (kal_uint32 *)ext_mem);
                     ASSERT(PNG_STATUS_OK == ret_value);
                  }
                  
                  //------------------------------Set Source Image------------------------------      
                  // read source image from memory   
                  read_ptr = png_img_arr[png_img_idx];
                  src_size = png_img_size[png_img_idx];
                                    
                  do {    
                     ret_value = min(rsbGetSpaceAvailable(&rsb), src_size);
                     if (src_size == ret_value) {
                        is_src_end = KAL_TRUE;
                     }
                     else {
                        is_src_end = KAL_FALSE;
                     }
                     // write image source from read_ptr to rsb
                     rsbWriteBytes(&rsb, (void *)read_ptr, ret_value);
                     read_ptr += ret_value;
                     src_size -= ret_value;          
                     ret_value = pngSetSourceData(&rsb, is_src_end);       
                  } while(PNG_STATUS_DECODE_INCOMPLETE == ret_value);    // PNG_STATUS_DECODE_INCOMPLETE implies IDAT has not been reached
                  
                    
                  //------------------------------Set Canvas Window------------------------------
                  {                     
                     PNG_DECODE_COLOR_FORMAT_ENUM canvas_color_format;
                     
                     canvas_color_format = PNG_FORMAT_RGB565;                                    
                     memset(&my_canvas[0], 0xFF, MAX_BUFFER_SIZE);  
                     pngSetCanvas((void *)&my_canvas[0], CANVAS_WIDTH, CANVAS_HEIGHT, canvas_color_format);                                             
                  }
                  
                  //------------------------------Set Output Window------------------------------
                  {
                     kal_int32 src_w, src_h;   
                     
                     pngGetImgDimension(&src_w, &src_h);      
                     pngSetOutputWindow(0, 0, src_w, src_h);   
                  }
                  
                  //------------------------------OPTIONAL---------------------------------------
                  {
                     PNG_DECODE_COLOR_FORMAT_ENUM blend_color_format;
                     PNG_BLEND_MODE_ENUM blending_mode;  
                     png_color replaced_color, replace_as_this_color;
                     
                     // MODIFY: parameter settings           
                     pngSetClipWindow(0, 0, CANVAS_WIDTH - 1, CANVAS_HEIGHT - 1);                       
                     
                     // default no output bgcolor
                     // bgcolor outputs only if file built-in bgcolor is available & this API is invoked
                     pngSetBgColorout();
                     
                     pngSetAlphaValue(100);
               
                     blend_color_format = PNG_FORMAT_RGB565;                   
                     // MODIFY: blend buffer content
                     memset(&b_buffer[0], 0xAC, MAX_BUFFER_SIZE);
                     pngSetBlendingBuffer(b_buffer);      
                     blending_mode = PNG_BLEND_USER_ASSIGNED;
                     pngSetBlendingMode(blending_mode, blend_color_format);
                     
                     replaced_color.red = 0;
                     replaced_color.green = 0;
                     replaced_color.blue = 0;
                     replace_as_this_color.red = 0;
                     replace_as_this_color.green = 0;
                     replace_as_this_color.blue = 0;      
                     pngSetReplaceColor(replaced_color, replace_as_this_color);   
                  }
                  
                  pngSetTimeoutValue(30000); // 300sec
                  
                  //------------------------------TRIGGER DECODE---------------------------------
                  
                  ret_value = pngDecodeStart();
                  if (PNG_STATUS_OK != ret_value) {
                     //MODIFY: check error status code
                     return;      
                  }
                  
                  //------------------------------Waiting Interrupt--------------------------------   
                  // MODIFY: if busy waiting is not desired
                  while (!hw_interrupted) {
                    ; // wait
                  }
                  hw_interrupted = 0;
                  
                  
                  //-------------------Set Remaining Source Image (Pause/Resume)--------------------
                  // simulate the behavior of msg handler
                  do {
                     if (PNG_STATUS_OK == _png_decode_ret) {                                        
                        // completly finish decoding            
                        // before starting to decode another png image, pngReset() is mandatory
                        pngReset();
                        
                        break;
                     } else
                     if (PNG_STATUS_DECODE_INCOMPLETE == _png_decode_ret) {  
                        // need set new source data and resume decoding     
                        
                        ret_value = min(rsbGetSpaceAvailable(&rsb), src_size);
                        if (src_size == ret_value) {
                           is_src_end = KAL_TRUE;
                        }
                        else {
                           is_src_end = KAL_FALSE;
                        }
                              
                        rsbWriteBytes(&rsb, (void *)read_ptr, ret_value);
                        read_ptr += ret_value;
                        src_size -= ret_value;                     
                        
                        pngSetSourceData(&rsb, is_src_end);         
                        ret_value = pngDecodeResume();
                        ASSERT(PNG_STATUS_OK == ret_value);
                  
                        // MODIFY: if busy waiting is not desired
                        while (!hw_interrupted) {
                           ; // wait
                        }
                        hw_interrupted = 0;  
                              
                     }
                     else {    
                        // hw decode fail
                        pngReset();
                        // MODIFY: decode error handler
                             
                        break;
                     }
                  }while (KAL_TRUE);                                
               }
               
               png_decode_duration = drv_get_duration_ms(png_start_time); 
               png_img_dec_ms[png_img_idx] = png_decode_duration;          
               //----------------------------END OF TIME MEASUREMENT-----------------------------
               png_img_idx++;
               png_img_idx %= 5;
            };
            
            // free
            if (int_mem)
            {
               med_free_int_mem(&int_mem);
            }
            if (ext_mem)
            {
               med_free_ext_mem(&ext_mem);  
            }
                       
            
            // in this case, the following will not be processed
            ret_value = pngFinalize();
            if (PNG_STATUS_OK != ret_value) 
            {
               ASSERT(0);
            }
                                   
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);                  
         }
         #endif //   #ifdef USE_HW_PNG_DECODER 
      
         SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);
}
      @endcode 
      @code
      {
         #include "png_decode.h"
         #include "med_utility.h"
         #include "app_str.h"
         #include "fsal.h"
         
         kal_uint8 *write_ptr;
         STFSAL read_fp;               
         kal_uint8 ucs2_filename[256];  
                           
         // read source image from file, other settings are the same as above       
         
         //------------------------------Set Source Image------------------------------                       
         ret_value = FSAL_Open(&read_fp, (void *)ucs2_filename, FSAL_READ);
         ASSERT(FSAL_OK == ret_value);
         FSAL_GetFileSize(&read_fp, (kal_uint32 *)&src_size);      
                     
         do {    
            ret_value = min(rsbGetSpaceAvailable(&rsb), src_size);
            if (src_size == ret_value) {
               is_src_end = KAL_TRUE;
            }
            else {
               is_src_end = KAL_FALSE;
            }     
            rsbGetWritePointer(&rsb, (void **)&write_ptr);
            // read data from file, in the meantime, the read buffer is the rs buffer
            // in other word, write data from file to rs buffer
            FSAL_Read_Bytes(&read_fp, write_ptr, ret_value);
            // since write data to rs buffer not through rs buffer API
            // the write pointer must be adjusted
            rsbAdjustWritePointer(&rsb, ret_value);   
            src_size -= ret_value; 
            
            ret_value = pngSetSourceData(&rsb, is_src_end);       
         } while(PNG_STATUS_DECODE_INCOMPLETE == ret_value);    // PNG_STATUS_DECODE_INCOMPLETE implies IDAT has not been reached
      }
      @endcode
 */
