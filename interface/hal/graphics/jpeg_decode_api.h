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
 *   jpeg_decode.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of decode API for JPEG codec unified interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_DECODE_API_H__
#define __JPEG_DECODE_API_H__

#include "kal_general_types.h"
#include "fsal.h"
#include "jpeg_enum.h"
#include "gfx_cache_switch_behavior_enum.h"



/*
 * \headerfile jpeg_decode.h <jpeg_decode_api.h>
 * \anchor jpeg_decode_api.h
 */

typedef struct JPEG_DECODER_T*   JPEG_DECODER_HANDLE;



/**
 * @brief            Get the JPEG decoder handle by scenario.
 * @param codecType  specify whether HW codec or SW codec is to be acquired
 * @param scenarioType  specify which scenario that we require
 * @param handlePtr  pointer to obtain the decoder handle
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetDecoderExt(JPEG_CODEC_TYPE_ENUM  codecType,
                                   JPEG_SCENARIO_TYPE_ENUM scenarioType, JPEG_DECODER_HANDLE   *handlePtr);



/**
 * @brief            Get the JPEG decoder handle.
 * @param codecType  specify whether HW codec or SW codec is to be acquired
 * @param handlePtr  pointer to obtain the decoder handle
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetDecoder(JPEG_CODEC_TYPE_ENUM  codecType,
                                   JPEG_DECODER_HANDLE   *handlePtr);



/**
 * @brief         Release the JPEG decoder handle.
 * @param handle  the decoder handle to be released
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecReleaseDecoder(JPEG_DECODER_HANDLE handle);



/**
 * @brief               Query the file buffer for the decoder.
 * @param handle        the decoder handle in use
 * @param readBufferSizeBest     pointer to unsigned int to obtain the best file read buffer size
 * @param readBufferSizeMinimum  pointer to unsigned int to obtain the minimum file read buffer size
 * @param fsalCacheSizeBest      pointer to unsigned int to obtain the best FSAL cache buffer size
 * @param fsalCacheSizeMinimum   pointer to unsigned int to obtain the minimum FSAL cache buffer size
 * @return              If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecQueryFileBuffer(JPEG_DECODER_HANDLE handle, 
                                        kal_uint32          *readBufferSizeBest,
                                        kal_uint32          *readBufferSizeMinimum,
                                        kal_uint32          *fsalCacheSizeBest,
                                        kal_uint32          *fsalCacheSizeMinimum);



/**
 * @brief         Set the source file and read buffer for the decoder.
 * @param handle  the decoder handle in use
 * @param fp      the pointer to FSAL structure
 * @param readBufferAddr   the starting address of file read buffer
 * @param readBufferSize   the size of file read buffer
 * @param fsalCacheAddr    the starting address of FSAL cache buffer
 * @param fsalCacheSize    the size of FSAL cache buffer
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       The cache buffer for FSAL is not necessary; however, with the cache buffer provided, the performance 
 *                of file access through FSAL will be greatly improved.
 */
JPEG_STATUS_ENUM jpegDecSetSourceFile(JPEG_DECODER_HANDLE   handle,
                                      STFSAL                *fp, 
                                      void                  *readBufferAddr,
                                      kal_int32             readBufferSize,
                                      void                  *fsalCacheAddr,
                                      kal_int32             fsalCacheSize);



/**
 * @brief         Set the canvas where the JPEG will be decoded to.
 * @param handle  the decoder handle in use
 * @param buffer  the starting address of the canvas buffer
 * @param width   the width of the canvas buffer
 * @param height  the height of the canvas buffer
 * @param format  the color format of the canvas buffer
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecSetRGBCanvas(JPEG_DECODER_HANDLE    handle,
                                     void                   *buffer, 
                                     kal_uint32             width,
                                     kal_uint32             height, 
                                     JPEG_RGB_FORMAT_ENUM   format);



/**
 * @brief         Set the YUV canvas where the JPEG will be decoded to.
 * @param handle  the decoder handle in use
 * @param pComp0  the starting address of the component0 buffer
 * @param pComp1  the starting address of the component1 buffer
 * @param pComp2  the starting address of the component2 buffer
 * @param width   the width of the canvas buffer
 * @param height  the height of the canvas buffer
 * @param format  the color format of the canvas buffer
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecSetYUVCanvas(JPEG_DECODER_HANDLE    handle,
                                     void                   *pComp0,
                                     void                   *pComp1,
                                     void                   *pComp2,
                                     kal_uint32             width,
                                     kal_uint32             height,
                                     JPEG_YUV_FORMAT_ENUM   format);


/**
 * @brief         Set the output window.
 * @param handle  the decoder handle in use
 * @param x       the x coordinate of the left-top of the the output window
 * @param y       the y coordinate of the left-top of the the output window
 * @param w       the width of the output window
 * @param h       the height of the output window
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecSetOutputWindow(JPEG_DECODER_HANDLE handle, 
                                        kal_int32           x,
                                        kal_int32           y,
                                        kal_uint32          w,
                                        kal_uint32          h);



/**
 * @brief         Set the clip window.
 * @param handle  the decoder handle in use
 * @param x       the x coordinate of the left-top of the the clip window
 * @param y       the y coordinate of the left-top of the the clip window
 * @param w       the width of the clip window
 * @param h       the height of the clip window
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       Notice that the clip window is in the canvas coordinate.
 */
JPEG_STATUS_ENUM jpegDecSetClipWindow(JPEG_DECODER_HANDLE   handle, 
                                      kal_int32             x,
                                      kal_int32             y,
                                      kal_uint32            w,
                                      kal_uint32            h);



/**
 * @brief               Query the necessary working memory for the decoder.
 * @param handle        the decoder handle in use
 * @param intMemorySizeBest      pointer to unsigned int to obtain the best internal memory size
 * @param intMemorySizeMinimum   pointer to unsigned int to obtain the minimum internal memory size
 * @param extMemorySizeBest      pointer to unsigned int to obtain the best external memory size
 * @param extMemorySizeMinimum   pointer to unsigned int to obtain the minimum external memory size
 * @return              If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks             Call this function after jpegDecSetSourceFile since the required buffer size will depend on the JPEG format (baseline / progressive).
 */
JPEG_STATUS_ENUM jpegDecQueryWorkingMemory(JPEG_DECODER_HANDLE handle, 
                                           kal_uint32          *intMemorySizeBest,
                                           kal_uint32          *intMemorySizeMinimum,
                                           kal_uint32          *extMemorySizeBest,
                                           kal_uint32          *extMemorySizeMinimum);



/**
 * @brief            Set the necessary working memory for the decoder.
 * @param handle     the decoder handle in use
 * @param intMemory  pointer to starting address of the internal working memory
 * @param intSize    size of the internal working memory
 * @param extMemory  pointer to starting address of the external working memory
 * @param extSize    size of the external working memory
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecSetWorkingMemory(JPEG_DECODER_HANDLE   handle, 
                                         kal_uint32            *intMemory,
                                         kal_uint32            intSize, 
                                         kal_uint32            *extMemory,
                                         kal_uint32            extSize);



/**
 * @brief                   Set the callback function for the decoder.
 * @param handle            the decoder handle in use
 * @param callback_function the specified callback function
 * @return                  If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks                 The callback function will be invoked when the state of the decoder changes.
 */
JPEG_STATUS_ENUM jpegDecSetCallbackFunction(JPEG_DECODER_HANDLE handle, 
                                            kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state));



/**
 * @brief         Get the state of the decoder.
 * @param handle  the decoder handle in use
 * @param state   pointer to JPEG_CODEC_STATE_ENUM to obtain the state
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetDecoderState(JPEG_DECODER_HANDLE handle, JPEG_CODEC_STATE_ENUM *state);



/**
 * @brief         Start the decoding process.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecStart(JPEG_DECODER_HANDLE handle);



/**
 * @brief         Resume the decoding process.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       If the decoder is in pause state, call jpegDecResume to resume the decoding process.
 */
JPEG_STATUS_ENUM jpegDecResume(JPEG_DECODER_HANDLE handle);



/**
 * @brief         Reset the decoder.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecReset(JPEG_DECODER_HANDLE handle);



/**
 * @brief         Get the image dimension of the JPEG image.
 * @param handle  the decoder handle in use
 * @param width   pointer to unsigned short to obtain the width of the JPEG image
 * @param height  pointer to unsigned short to obtain the height of the JPEG image
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetImageDimension(JPEG_DECODER_HANDLE  handle,
                                          kal_uint16           *width,
                                          kal_uint16           *height);



/**
 * @brief            Get the encode process (baseline or progressive) of the JPEG image.
 * @param handle     the decoder handle in use
 * @param process    pointer to JPEG_ENCODE_PROCESS_ENUM to obtain the encode process of the JPEG image
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetEncodeProcess(JPEG_DECODER_HANDLE      handle,
                                         JPEG_ENCODE_PROCESS_ENUM *process);



/**
 * @brief            Get information of the thumbnail resides in the JPEG image.
 * @param handle     the decoder handle in use
 * @param type       pointer to JPEG_THUMBNAIL_TYPE_ENUM to obtain the type of the embedded thumbnail
 * @param width      pointer to an unsigned int to obtain the width of the embedded thumbnail
 * @param height     pointer to an unsigned int to obtain the hegiht of the embedded thumbnail
 * @param offset     pointer to an unsigned int to obtain the offset of the embedded thumbnail data
 * @param size       pointer to an unsigned int to obtain the size of the embedded thumbnail data
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetThumbnailInfo(JPEG_DECODER_HANDLE      handle,
                                         JPEG_THUMBNAIL_TYPE_ENUM *type,
                                         kal_uint32               *width,
                                         kal_uint32               *height,
                                         kal_uint32               *offset,
                                         kal_uint32               *size);



/**
 * @brief               Get data of the thumbnail resides in the JPEG image.
 * @param handle        the decoder handle in use
 * @param dstBuffer     buffer to store the thumbnail data
 * @param dstBufferSize the size of the buffer; after the function returned, it will contain the size of data read into dstBuffer.
 * @return              If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetThumbnailData(JPEG_DECODER_HANDLE   handle,
                                         kal_uint8             *dstBuffer,
                                         kal_uint32            *dstBufferSize);



/**
 * @brief            Set the decode mode for the following JPEG decoding process.
 * @param handle     the decoder handle in use
 * @param mode       the specified decode mode
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks          The mode parameter should be one of the JPEG_DECODE_MODE_AUTO, JPEG_DECODE_MODE_MAIN_IMAGE and JPEG_DECODE_MODE_THUMBNAIL. \n
 *                   If JPEG_DECODE_MODE_AUTO is specified, the decoder will automatically decide to decode the main image or the thumbnail according some rules. \n
 *                   If JPEG_DECODE_MODE_MAIN_IMAGE is specified, the decoder will decode the main image only. \n
 *                   If JPEG_DECODE_MODE_THUMBNAIL is specified, the decoder will try to decode the thumbnail first.
 *                   If there's no thumbnail in the JPEG file, or the decoding of the thumbnail failed, the decoder will try to decode the main image instead.
 */
JPEG_STATUS_ENUM jpegDecSetDecodeMode(JPEG_DECODER_HANDLE   handle,
                                      JPEG_DECODE_MODE_ENUM mode);



/**
 * @brief            Set the check-abort function.
 * @param handle     the decoder handle in use
 * @param check_abort_func    the check abort function
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks          This feature takes effect only for SW JPEG decoder.
 *                   The check-abort function will be invoked before the decoding of every MCU row.
 *                   If the check abort function returns non-zero value, the decoding process will be aborted.
 */
JPEG_STATUS_ENUM jpegDecSetCheckAbortFunction(JPEG_DECODER_HANDLE handle, 
                                              kal_int32 (*check_abort_func)(void));



/**
 * @brief            Get the last error.
 * @param handle     the decoder handle in use
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegDecGetLastError(JPEG_DECODER_HANDLE handle);



/**
 * @brief           Set the destination buffer switch behavior
 * @param handle    the decoder handle in use
 * @param behavior  the cache/non-cached switch behavior of destination buffer, either GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH or GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       
 */    
JPEG_STATUS_ENUM jpegDecSetDstBufferSwitchBehavior(JPEG_DECODER_HANDLE handle, 
                                                 GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);


#endif   /// __JPEG_DECODE_API_H__
