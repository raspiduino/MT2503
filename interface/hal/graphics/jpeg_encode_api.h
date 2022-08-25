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
 *   jpeg_encode_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of encode API for JPEG codec unified interface.
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
#ifndef __JPEG_ENCODE_API_H__
#define __JPEG_ENCODE_API_H__

/*
 * \headerfile jpeg_encode.h <jpeg_encode.h>
 * \anchor jpeg_encode.h
 */

#include "kal_general_types.h"

#include "fsal.h"

#include "jpeg_enum.h"
#include "jpeg_misc_api.h"

typedef struct JPEG_ENCODER_T* JPEG_ENCODER_HANDLE;

/**
 * @brief            Get the JPEG encoder resource.
 * @param codecType  specify whether HW codec or SW codec is to be acquired
 * @param handlePtr  pointer to obtain the encoder handle
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncGetEncoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_ENCODER_HANDLE *handlePtr);



/**
 * @brief         Release the JPEG encoder handle.
 * @param handle  the encoder handle to be released
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 */
JPEG_STATUS_ENUM jpegEncReleaseEncoder(JPEG_ENCODER_HANDLE handle);



/**
 * @brief         Set the source mode for the encoder.
 * @param handle  the encoder handle in use
 * @param srcMode srcMode must be one of following value:
 *                JPEG_ENCODE_SOURCE_ISP
 *                JPEG_ENCODE_SOURCE_YUV_BUFFER
 *                JPEG_ENCODE_SOURCE_RGB_BUFFER
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 *    Image data may comes from either ISP or image buffer.
 *    However, the JPEG_ENC_SRC_FROM_ISP is available for HW JPEG encoder only.
 */
JPEG_STATUS_ENUM jpegEncSetSrcMode(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_SOURCE_ENUM srcMode);



/**
 * @brief         Set the ROI of the source window for the encoder.
 * @param handle  the encoder handle in use
 * @param srcWindow   the ROI of the source window
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetSrcWindow(JPEG_ENCODER_HANDLE handle, MY_RECTANGLE* srcWindow);



/**
 * @brief         Set the source dimension for the encoder.
 * @param handle  the encoder handle in use
 * @param width   width of the source dimension
 * @param height  height of the source dimension
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetSrcDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height);



/**
 * @brief         Get the source dimension for the encoder.
 * @param handle  the encoder handle in use
 * @param width   width of the source dimension
 * @param height  height of the source dimension
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncGetSrcDimension(JPEG_ENCODER_HANDLE handle, kal_uint32* width, kal_uint32* height);



/**
 * @brief            Set the source RGB format for the encoder.
 * @param handle     the encoder handle in use
 * @param rgbFormat  the RGB format of the source image data
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetSrcRGBFormat(JPEG_ENCODER_HANDLE handle, JPEG_RGB_FORMAT_ENUM rgbFormat);



/**
 * @brief         Set the source RGB buffer for the encoder.
 * @param handle  the encoder handle in use
 * @param buffer  pointer to the source RGB buffer
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetRGBBuffer(JPEG_ENCODER_HANDLE handle, void *buffer, kal_uint32 bufferSize);



/**
 * @brief            Set the source YUV buffer for the encoder.
 * @param handle     the encoder handle in use
 * @param yuvFormat  the YUV format of the source image data, must be one of the following values:
 *                   JPEG_YUV_FORMAT_YUV444
 *                   JPEG_YUV_FORMAT_YUV422
 *                   JPEG_YUV_FORMAT_YUV411
 *                   JPEG_YUV_FORMAT_YUV420
 *                   JPEG_YUV_FORMAT_GRAYLEVEL
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks          This feature is platform-dependent.
 */
JPEG_STATUS_ENUM jpegEncSetSrcYUVFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM yuvFormat);



/**
 * @brief         Set the Y, U, V component buffer respectively for the encoder.
 * @param handle  the encoder handle in use
 * @param yBuffer starting address of the Y component buffer
 * @param uBuffer starting address of the U component buffer
 * @param vBuffer starting address of the V component buffer
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       This feature is platform-dependent.
 */
JPEG_STATUS_ENUM jpegEncSetYUVBuffer(JPEG_ENCODER_HANDLE handle,
                                     void *yBuffer, void *uBuffer, void *vBuffer,
                                     kal_uint32 yBufferSize, kal_uint32 uBufferSize, kal_uint32 vBufferSize);



/**
 * @brief         Set the quality for the encoded JPEG image
 * @param handle  the encoder handle in use
 * @param quality the quality for the encoded JPEG image
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetDstQuality(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_QUALITTY_ENUM quality);



/**
 * @brief         Set the output JPEG format for the encoded JPEG image
 * @param handle  the encoder handle in use
 * @param format  the output JPEG format may be on of the following values:
 *                JPEG_FILE_FORMAT_JPEG
 *                JPEG_FILE_FORMAT_JFXX
 *                JPEG_FILE_FORMAT_EXIF
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetDstFileFormat(JPEG_ENCODER_HANDLE handle, JPEG_FILE_FORMAT_ENUM format);



/**
 * @brief         Set the thumbnail information of the encoded JPEG image
 * @param handle  the encoder handle in use
 * @param type    the type may be on of the following values:
 *                JPEG_THUMBNAIL_TYPE_NONE
 *                JPEG_THUMBNAIL_TYPE_3BPP
 *                JPEG_THUMBNAIL_TYPE_JPEG
 * @param width   the width of thumbnail image
 * @param height  the height of thumbnail image
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       JPEG_THUMBNAIL_TYPE_JPEG is not supported yet on the current implementation.
 */
JPEG_STATUS_ENUM jpegEncSetDstThumbnail(JPEG_ENCODER_HANDLE handle, kal_bool enable, kal_uint32 width, kal_uint32 height);



/**
 * @brief         Set the dimension for the encoded JPEG image
 * @param handle  the encoder handle in use
 * @param width   the width of the output JPEG image
 * @param height  the height of the output JPEG image
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       For JPEG_ENCODE_SOURCE_ISP mode, the destination dimension must be the same as the source dimension.
 */
JPEG_STATUS_ENUM jpegEncSetDstDimension(JPEG_ENCODER_HANDLE handle, kal_uint32 width, kal_uint32 height);



/**
 * @brief               Set the YUV sampling format for the encoded JPEG image
 * @param handle        the encoder handle in use
 * @param sampleFormat  the YUV sampling format of the output JPEG image, must be one of the following values:
 *                      JPEG_YUV_FORMAT_YUV444
 *                      JPEG_YUV_FORMAT_YUV422
 *                      JPEG_YUV_FORMAT_YUV411
 *                      JPEG_YUV_FORMAT_YUV420
 *                      JPEG_YUV_FORMAT_GRAYLEVEL
 * @return              If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks             For JPEG_ENCODE_SOURCE_YUV_BUFFER mode, the destination sample format must be the same as the source sample format.
 */
JPEG_STATUS_ENUM jpegEncSetDstSampleFormat(JPEG_ENCODER_HANDLE handle, JPEG_YUV_FORMAT_ENUM sampleFormat);



/**
 * @brief            Set the output buffer for the encoder.
 * @param handle     the encoder handle in use
 * @param bufferAddr the starting address of the output buffer
 * @param bufferSize the size of the output buffer
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks          The output buffer must be 4-bytes aligned.
 */
JPEG_STATUS_ENUM jpegEncSetDstBuffer(JPEG_ENCODER_HANDLE handle, void *bufferAddr, kal_uint32 bufferSize);



/**
 * @brief            Set the direct file output file handle.
 * @param handle     the encoder handle in use
 * @param fp         the file handle
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks          The output buffer must be 4-bytes aligned.
 */
JPEG_STATUS_ENUM jpegEncSetDirectFileOutputHandle(JPEG_ENCODER_HANDLE handle, STFSAL *fp);



/**
 * @brief                   Set callback function for the encoder.
 * @param handle            the encoder handle in use
 * @param callback_function the callback function of the encoder
 * @return                  If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks                 The callback function will be invoked when the state of the encoder changes.
 */
JPEG_STATUS_ENUM jpegEncSetCallbackFunction(JPEG_ENCODER_HANDLE handle, kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state));



/**
 * @brief               Query the necessary working memory for the encoder.
 * @param handle        the encoder handle in use
 * @param intMemorySize pointer to unsigned int to obtain the internal memory size
 * @param extMemorySize pointer to unsigned int to obtain the internal memory size
 * @return              If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncQueryWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                           kal_uint32 *intMemorySizeBest, kal_uint32 *intMemorySizeMinimum,
                                           kal_uint32 *extMemorySizeBest, kal_uint32 *extMemorySizeMinimum);



/**
 * @brief            Set the necessary working memory for the encoder.
 * @param handle     the encoder handle in use
 * @param intMemory  pointer to starting address of the internal working memory
 * @param intSize    size of the internal working memory
 * @param extMemory  pointer to starting address of the external working memory
 * @param extSize    size of the external working memory
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetWorkingMemory(JPEG_ENCODER_HANDLE handle,
                                         kal_uint32 *intMemory, kal_uint32 intSize,
                                         kal_uint32 *extMemory, kal_uint32 extSize);



/**
 * @brief                   Set the temporal information for the quick view image encoding
 * @param handle            the encoder handle in use
 * @param qviBufferAddr     pointer to starting address of the quick view image
 * @param qviWidth          width of the quick view image
 * @param qviHeight         height of the quick view image
 * @param qviColorFormat    color format of the quick view image
 * @param qviRotAngle       rot angle of the quick view image
 * @return                  If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetQVITempInfo(JPEG_ENCODER_HANDLE handle, void *qviBufferAddr,
                                       kal_uint32 qviWidth, kal_uint32 qviHeight,
                                       kal_uint32 qviColorFormat, kal_uint32 qviRotAngle);



/**
 * @brief         Get the state of the encoder.
 * @param handle  the encoder handle in use
 * @param state   pointer to JPEG_CODEC_STATE_ENUM to obtain the state
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncGetEncoderState(JPEG_ENCODER_HANDLE handle, JPEG_CODEC_STATE_ENUM *state);



/**
 * @brief         Set rotation to encoder.
 * @param handle  the encoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetRotation(JPEG_ENCODER_HANDLE handle, JPEG_ENCODE_ROTATE_ANGLE_ENUM angle);



/**
 * @brief         Abort the encoding process.
 * @param handle  the encoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncSetCheckAbortFunction(JPEG_ENCODER_HANDLE handle,
                                              kal_int32 (*check_abort_func)(void));



/**
 * @brief         Set the Dynamic Quantization Adjustment to JPEG image
 * @param handle  the encoder handle in use
 * @param enable  to enable or not
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks       JPEG_THUMBNAIL_TYPE_JPEG is not supported yet on the current implementation.
 */
JPEG_STATUS_ENUM jpegEncSetDynamicQuantAdjustment(JPEG_ENCODER_HANDLE handle, kal_bool enable);



/**
 * @brief         Start the encoding process.
 * @param handle  the encoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncStart(JPEG_ENCODER_HANDLE handle);



/**
 * @brief         Reset the encoder.
 * @param handle  the encoder handle in use
 * @return        If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncReset(JPEG_ENCODER_HANDLE handle);



/**
 * @brief            Get the information of the encoded JPEG image.
 * @param handle     the encoder handle in use
 * @param startPtr   pointer to obtain the address of the encoded buffer
 * @param length     pointer to obtain the encoded size
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncGetEncodedData(JPEG_ENCODER_HANDLE handle, kal_uint8 **startPtr, kal_uint32 *length);



/**
 * @brief                   Query the buffer sizewhich should be reserved for JPEG Enocder destination buffer.
 * @param bufferSize        pointer to obtain the destination reserved size
 * @param quality the quality for the encoded JPEG image 
 * @param dstFormat         the YUV sampling format of the output JPEG image.
 * @param width             the width of the output JPEG image
 * @param height            the height of the output JPEG image
 * @param metadataEnable    enable metadata or not 
 * @return                  If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncQueryDstBufferSize(kal_uint32 *bufferSize,
                                           JPEG_ENCODE_EVALUATION_MODE_ENUM mode,
                                           JPEG_ENCODE_QUALITTY_ENUM quality,
                                           JPEG_YUV_FORMAT_ENUM dstFormat, kal_uint32 dstWidth, kal_uint32 dstHeight,
                                           kal_bool metadataEnable);



/**
 * @brief            Get the information of the error code.
 * @param handle     the encoder handle in use
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpegEncGetLastError(JPEG_ENCODER_HANDLE handle);

#endif   /// __JPEG_ENCODE_H__

