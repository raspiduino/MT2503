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
 *   jpeg_encode_wrapper.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Wrapper for JPEG.
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

#ifndef __JPEG_ENCODE_WRAPPER_H__
#define __JPEG_ENCODE_WRAPPER_H__

#include "kal_general_types.h"

#include "fsal.h"

#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_misc_api.h"


typedef struct JPEG_WRAPPER_T {

   JPEG_ENCODE_SOURCE_ENUM srcMode;

   kal_uint32 srcWidth;
   kal_uint32 srcHeight;
   MY_RECTANGLE srcWindow;                ///< source window (ROI)

   kal_uint32 dstWidth;
   kal_uint32 dstHeight;

   void *dstBufferAddr;
   kal_uint32 dstBufferSize;

   JPEG_ENCODE_ROTATE_ANGLE_ENUM rotation;

   void *srcRGBBuffer;
   void *srcYUVBuffer[3];
   kal_uint32 srcBufferSize[3];
   JPEG_RGB_FORMAT_ENUM srcRGBFormat;
   JPEG_YUV_FORMAT_ENUM srcSamplingFormat;

   JPEG_ENCODE_QUALITTY_ENUM dstQuality;
   JPEG_YUV_FORMAT_ENUM dstSamplingFormat;

   JPEG_FILE_FORMAT_ENUM dstFileFormat;

   /// Thumbnail attributes
   kal_bool enableThumbnail;
   kal_uint32 thumbnailWidth;
   kal_uint32 thumbnailHeight;

   STFSAL *pDstFileHandle;

   void *intMemoryAddr;
   void *extMemoryAddr;
   kal_uint32 intMemorySize;
   kal_uint32 extMemorySize;

   kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state);

   /// Quick view image temporal information
   void *qviImageBufferAddr;
   kal_uint32 qviImageWidth;
   kal_uint32 qviImageHeight;
   kal_uint32 qviImageColorFormat;
   kal_uint32 qviImageRotAngle;

} JPEG_WRAPPER;




/**
 * @brief            				Get the JPEG encoder resource.
 * @param codecType  				specify whether HW codec or SW codec is to be acquired
 * @param jpegWrapperHandle pointer to obtain the encoder handle
 * @return           				If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   				otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpeg_wrapper_open(JPEG_ENCODER_HANDLE *jpegWrapperHandle, JPEG_CODEC_TYPE_ENUM codecType);



/**
 * @brief            				start the JPEG encode.
 * @param wrapperPtr  			The JPEG parameter
 * @param jpegWrapperHandle pointer to obtain the encoder handle
 * @return           				If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   				otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpeg_wrapper_start(JPEG_ENCODER_HANDLE jpegWrapperHandle, JPEG_WRAPPER *wrapperPtr);



/**
 * @brief            				Get the JPEG encoder state.
 * @param jpegState  			  The JPEG encoder state
 * @param jpegWrapperHandle pointer to obtain the encoder handle
 * @return           				If the function succeeds, the return value is JPEG_STATUS_OK and the handle is returned in handlePtr;
 *                   				otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
JPEG_STATUS_ENUM jpeg_wrapper_get_encoder_state(JPEG_ENCODER_HANDLE jpegWrapperHandle, JPEG_CODEC_STATE_ENUM *jpegState);



/**
 * @brief            				Get the information of the encoded JPEG image.
 * @param jpegWrapperHandle the encoder handle in use
 * @param encodeBufferAddr  pointer to obtain the address of the encoded buffer
 * @param encodeBufferAddr  pointer to obtain the encoded size
 * @return           If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
JPEG_STATUS_ENUM jpeg_wrapper_get_encoded_data(JPEG_ENCODER_HANDLE jpegWrapperHandle, kal_uint8 **encodeBufferAddr, kal_uint32 *encodeBufferSize);


/**
 * @brief         					Release the JPEG encoder handle.
 * @param jpegWrapperHandle the encoder handle in use
 * @return        					If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 */
JPEG_STATUS_ENUM jpeg_wrapper_close(JPEG_ENCODER_HANDLE jpegWrapperHandle);



/**
 * @brief                   Release the JPEG encoder handle.
 * @param bufferSize        the size of buffer
 * @param quality           the quality for the encoded JPEG image
 * @param dstFormat         the YUV sampling format of the output JPEG image.
 * @param width             the width of the output JPEG image
 * @param height            the height of the output JPEG image
 * @return                  If the function succeeds, the return value is JPEG_STATUS_OK; otherwise the error code is returned.
 */
JPEG_STATUS_ENUM jpeg_wrapper_query_dst_buffer_size(kal_uint32 *bufferSize,
                                                    JPEG_ENCODE_QUALITTY_ENUM quality,
                                                    JPEG_YUV_FORMAT_ENUM dstFormat, kal_uint32 dstWidth, kal_uint32 dstHeight);

#endif /// __JPEG_WRAPPER_H__
