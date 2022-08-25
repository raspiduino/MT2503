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
 *    png_decode_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG decode API 
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __PNG_DECODE_API_H__
#define __PNG_DECODE_API_H__

#include "png_decode_enum.h"
#include "fsal.h"
#include "gfx_cache_switch_behavior_enum.h"

typedef struct PNG_DECODER_T* PNG_DECODER_HANDLE;

/**
 * @brief              Get the PNG decoder handle.
 * @param decoderType  specify whether HW decoder or SW decoder is to be acquired
 * @param handlePtr    pointer to obtain the decoder handle
 * @return             If the function succeeds, the return value is PNG_STATUS_OK and the handle is returned in handlePtr;
 *                     otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
PNG_STATUS_ENUM pngDecGetDecoder(PNG_DECODER_TYPE_ENUM decoderType, PNG_DECODER_HANDLE *handlePtr);



/**
 * @brief            Release the PNG decoder handle.
 * @param handle     the decoder handle in use
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks          MUST be invoked at last if no further using png decoder 
 */
PNG_STATUS_ENUM pngDecReleaseDecoder(PNG_DECODER_HANDLE handle);



/**
 * @brief              Query the PNG decoder type in use(PNG_DECODER_TYPE_HW or PNG_DECODER_TYPE_SW)
 * @param handle       the decoder handle in use
 * @param decoderType  pointer to obtain the decoder type
 * @return             If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks
 */
PNG_STATUS_ENUM pngDecQueryDecoderType(PNG_DECODER_HANDLE handle, PNG_DECODER_TYPE_ENUM *decoderType);



/**
 * @brief            Call this function to reset all configurations 
 * @param handle     the decoder handle in use 
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks          NOT ALLOWED INVOKING WHEN DECODING
 */
PNG_STATUS_ENUM pngDecReset(PNG_DECODER_HANDLE handle);



/**
 * @brief                 Set the callback function for the decoder.
 * @param handle          the decoder handle in use  
 * @param pngdec_callback the specified callback function
 * @return                If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned. 
 * @remarks
 */
PNG_STATUS_ENUM pngDecHookCallback(PNG_DECODER_HANDLE handle, 
                                   void (*pngdec_callback)(PNG_STATUS_ENUM status));
       
       

/**
 * @brief                  Query the necessary working memory for the decoder.
 * @param handle           the decoder handle in use   
 * @param internal_mem_sz  pointer to unsigned int to obtain the best internal memory size(MUST BE WORD ALIGNED)
 * @param external_mem_sz  pointer to unsigned int to obtain the best external memory size(MUST BE WORD ALIGNED)
 * @return                 If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.  
 * @remarks
 */                            
PNG_STATUS_ENUM pngDecQueryWorkingBufferSize(PNG_DECODER_HANDLE handle, kal_uint32* internal_mem_sz, kal_uint32* external_mem_sz);



/**
 * @brief              Set the necessary working memory for the decoder.
 * @param handle       the decoder handle in use   
 * @param internalBuf  pointer to starting address of the internal working memory
 * @param externalBuf  pointer to starting address of the external working memory
 * @return             If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.   
 * @remarks
 */  
PNG_STATUS_ENUM pngDecSetWorkingBuffer(PNG_DECODER_HANDLE handle, kal_uint32* internalBuf, kal_uint32* externalBuf);




/**
 * @brief                   Query the necessary file buffer size for the decoder.
 * @param handle            the decoder handle in use    
 * @param bestFileBuffSize  pointer to unsigned int to obtain the best file buffer size
 * @param minFileBuffSize   pointer to unsigned int to obtain the minimum file buffer size
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.   
 * @remarks
 */  
PNG_STATUS_ENUM pngDecQueryFileBufferSize(PNG_DECODER_HANDLE handle,
                                          kal_uint32 *bestFileBuffSize,
                                          kal_uint32 *minFileBuffSize);
    
    

     
/**
 * @brief          Query the necessary file buffer size for the decoder.
 * @param handle   the decoder handle in use    
 * @param src_w    the image width in pixel
 * @param src_h    the image height in pixel
 * @return         If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.   
 * @remarks        This function must be invoked after calling pngDecSetSourceFile(), since the parsing of PNG file \n
 *                 are done inside pngDecSetSourceFile()
 */                                         
PNG_STATUS_ENUM pngDecGetImgDimension(PNG_DECODER_HANDLE handle, kal_int32* src_w, kal_int32* src_h);



/**
 * @brief          Set to output file built-in background color when transparent
 * @param handle   the decoder handle in use   
 * @return         If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.   
 * @remarks
 */                                   
PNG_STATUS_ENUM pngDecSetBgColorOut(PNG_DECODER_HANDLE handle);



/**
 * @brief          Query if the file alpha exist
 * @param handle   the decoder handle in use   
 * @return         If the function succeeds, the return value is 1, otherwise the 0 is return
 * @remarks
 */      
kal_int32 pngDecIsFileAlphaExist(PNG_DECODER_HANDLE handle);



/**
 * @brief          Query if the file contain transparency
 * @param handle   the decoder handle in use   
 * @return         If the function succeeds, the return value is 1, otherwise the 0 is return   
 * @remarks
 */        
kal_int32 pngDecIsFileTransparencyExist(PNG_DECODER_HANDLE handle);



/**
 * @brief        Get the state of the decoder.
 * @param handle the decoder handle in use    
 * @param state  pointer to PNG_DECODER_STATE_ENUM to obtain the state
 * @return       If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.    
 * @remarks
 */     
PNG_STATUS_ENUM pngDecGetDecodeState(PNG_DECODER_HANDLE handle, PNG_DECODER_STATE_ENUM *state);


/**
 * @brief               Set the time out value of PNG decoder.(Only take effect for HW PNG decoder)
 * @param handle        the decoder handle in use   
 * @param timeout_msec  timeout value (unit = 10 ms)
 * @return              If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.    
 * @remarks
 */     
PNG_STATUS_ENUM pngDecSetTimeoutValue(PNG_DECODER_HANDLE handle, kal_int32 timeout_msec);



/** 
 *  @brief  Set alpha blending mode and blending buffer color format \n
 *  @param handle         the decoder handle in use    
 *  @param blendBuffAddr  set blending mode from PNG_BLEND_MODE_ENUM.
 *  @param blndBuffW      the buffer width of blending buffer        
 *  @param blndBuffH      the buffer height of blending buffer        
 *  @param color_format   the blending buffer color format from PNG_DECODE_COLOR_FORMAT_ENUM  
 *  @param blend_mode     set blending mode from PNG_BLEND_MODE_ENUM. 
 *  <For HW PNG decoder>
 *  For Alpha blending outcome effects, there are 4 effect settings.\n
 *  1. PNG_BLEND_USER_ASSIGNED:user-specified single alpha value (always be per-alpha):\n
 *  dstColor = userAlpha x pngColor + (1 - userAlpha) x bldColor \n\n
 *  
 *  2. PNG_BLEND_FILE_ALPHA:PNG built-in alpha:\n
 *  dstColor = pngAlpha x pngColor + (1 - pngAlpha) x bldColor\n
 *    pngAlpha may comes from several sources:\n
 *  i.   the alpha component of the pixel if the color type is ARGB \n
 *  ii.  the alpha component of the pixel if the color type is grayscale with alpha \n
 *  iii. the single alpha defined in the transparent chunk if the color type is not palette type \n
 *  iv.  the per-palette-entry alpha defined in the transparent chunk if the color type is palette type \n\n
 *  
 *  3. PNG_BLEND_BUFFER:blending buffer (always be per-pixel):\n
 *  dstColor = dstAlpha x pngColor + (1 - dstAlpha) x bldColor\n
 *      This mode works only when the destination buffer is ARGB mode.\n
 *  \n
 *  4. PNG_BLEND_NONE:none\n
 *  \n
 *  <For SW PNG decoder> \n
 *  Only support the setting of PNG_BLEND_BUFFER \n 
 *  @return              If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 */      
PNG_STATUS_ENUM pngDecSetAlphaBlending(PNG_DECODER_HANDLE handle, 
                                       void* blendBuffAddr, 
                                       kal_uint32 blndBuffW, 
                                       kal_uint32 blndBuffH,
                                       PNG_DECODE_COLOR_FORMAT_ENUM color_format, 
                                       PNG_BLEND_MODE_ENUM blend_mode);        



/**
 * @brief            Set the replacement color of PNG decoder.
 * @param handle         the decoder handle in use     
 * @param rep_enable Enable or disable the color replacement for PNG decoder
 * @param new_r      new red color that will replace the original color
 * @param new_g      new green color that will replace the original color
 * @param new_b      new blue color that will replace the original color
 * @param ori_r      original red color that should be replaced
 * @param ori_g      original green color that should be replaced
 * @param ori_b      original blue color that should be replaced
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */                                            
PNG_STATUS_ENUM pngDecSetColorReplacement(PNG_DECODER_HANDLE handle, kal_bool rep_enable, 
                                          kal_uint8 new_r, kal_uint8 new_g, kal_uint8 new_b,
                                          kal_uint8 ori_r, kal_uint8 ori_g, kal_uint8 ori_b);



/**
 * @brief            Query if the dithering support or not 
 * @param handle     the decoder handle in use     
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */                                                   
PNG_STATUS_ENUM pngDecQueryDitheringSupport(PNG_DECODER_HANDLE handle);



/**
 * @brief                   Enable or disable the dithering for PNG decoder
 * @param handle            the decoder handle in use     
 * @param dithering_enable  Enable or disable    
 * @return                  If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */       
PNG_STATUS_ENUM pngDecEnableDithering(PNG_DECODER_HANDLE handle, kal_bool dithering_enable);




/**
 * @brief                   Enable or disable the dithering for PNG decoder
 * @param handle            the decoder handle in use     
 * @param canvasStartAddr   pointer to the starting address of canvas buffer  
 * @param width             width of canvas buffer    
 * @param height            height of canvas buffer    
 * @param out_color_format  color format of canvas buffer
 * @return                  If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */        
PNG_STATUS_ENUM pngDecSetCanvas(PNG_DECODER_HANDLE handle, 
                                void *canvasStartAddr, 
                                kal_int32 width, kal_int32 height, 
                                PNG_DECODE_COLOR_FORMAT_ENUM out_color_format);
                                



/**
 * @brief            Enable or disable the dithering for PNG decoder
 * @param handle     the decoder handle in use     
 * @param up_left_x  up left x-coordinate of clipping window
 * @param up_left_y  up left y-coordinate of clipping window
 * @param dst_w      width of output window
 * @param dst_h      height of output window
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */                                      
PNG_STATUS_ENUM pngDecSetOutputWindow(PNG_DECODER_HANDLE handle, 
                                      kal_int32 up_left_x,
                                      kal_int32 up_left_y, 
                                      kal_int32 dst_w, 
                                      kal_int32 dst_h);                                                                                                                                                   



/**
 * @brief            Enable or disable the dithering for PNG decoder
 * @param handle     the decoder handle in use     
 * @param up_left_x  up left x-coordinate of clipping window
 * @param up_left_y  up left y-coordinate of clipping window
 * @param dst_w      width of clipping window
 * @param dst_h      height of clipping window
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.     
 * @remarks
 */                                             
PNG_STATUS_ENUM pngDecSetClipWindow(PNG_DECODER_HANDLE handle, 
                                    kal_int32 up_left_x, 
                                    kal_int32 up_left_y, 
                                    kal_int32 clip_w, 
                                    kal_int32 clip_h);           



/**
 * @brief         Start the decoding process.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks
 */                                         
PNG_STATUS_ENUM pngDecDecodeStart(PNG_DECODER_HANDLE handle);
    
    
    
/**
 * @brief                 Start the decoding process.
 * @param handle          the decoder handle in use
 * @param fp              the pointer to FSAL structure
 * @param fileBufferAddr  the starting address of file buffer 
 * @param fileBufferSize  the size of file buffer 
 * @return        If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks
 */                                                                    
PNG_STATUS_ENUM pngDecSetSourceFile(PNG_DECODER_HANDLE handle, STFSAL *fp,
                                    void *fileBufferAddr, kal_int32 fileBufferSize);                                          
                                          



/**
 * @brief         Resume the decoding process. The decoding data is refill inside resume.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks       this API should be invoked by GDI/AP after hw decoder raising an interrupt (only take effect for HW)
 */     
PNG_STATUS_ENUM pngDecDecodeResume(PNG_DECODER_HANDLE handle);



/**
 * @brief                   Set the check-abort function.
 * @param handle            the decoder handle in use
 * @param check_abort_func  the check abort function
 * @return           If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks          This feature takes effect only for SW PNG decoder.
 *                   The check-abort function will be invoked before the decoding of every row.
 *                   If the check abort function returns non-zero value, the decoding process will be aborted.
 */      
PNG_STATUS_ENUM pngDecSetCheckAbortFunction(PNG_DECODER_HANDLE handle, kal_int32 (*check_abort_func)(void));



/**
 * @brief           Set the destination buffer switch behavior
 * @param handle    the decoder handle in use
 * @param behavior  the cache/non-cached switch behavior of destination buffer, either GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH or GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH
 * @return          If the function succeeds, the return value is PNG_STATUS_OK, otherwise the error code is returned.
 * @remarks       
 */    
PNG_STATUS_ENUM pngDecSetDstBufferSwitchBehavior(PNG_DECODER_HANDLE handle, 
                                                 GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);
                                                 
#endif /* png_common_api.h */
