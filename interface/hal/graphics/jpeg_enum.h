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
 *   jpeg_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Enum for JPEG codec unified interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_ENUM_H__
#define __JPEG_ENUM_H__

typedef enum {
   JPEG_STATUS_OK = 0,
   JPEG_STATUS_CODEC_UNAVAILABLE,
   JPEG_STATUS_IDP_ERROR,
   JPEG_STATUS_INVALID_PARAMETER,
   JPEG_STATUS_INVALID_OPERATION,
   JPEG_STATUS_INVALID_HANDLE,
   JPEG_STATUS_IO_ERROR,

   JPEG_STATUS_DEC_ERROR_PARSE_INCOMPLETE,
   JPEG_STATUS_DEC_ERROR_INVALID_FILE,
   JPEG_STATUS_DEC_ERROR_INVALID_BUFFER,
   JPEG_STATUS_DEC_ERROR_READ_ERROR,
   JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT,
   JPEG_STATUS_DEC_ERROR_INVALID_WIDTH,
   JPEG_STATUS_DEC_ERROR_INVALID_HEIGHT,
   JPEG_STATUS_DEC_ERROR_IDP_UNAVAILABLE,
   JPEG_STATUS_DEC_ERROR_GENERAL_ERROR,
   JPEG_STATUS_DEC_ERROR_INSUFFICIENT_MEMORY,
   JPEG_STATUS_DEC_ERROR_SOURCE_DIMENSION_ERROR,
   JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR,
   JPEG_STATUS_DEC_ERROR_CORRUPT_FILE,

   JPEG_STATUS_ENC_BUSY,
   JPEG_STATUS_ENC_ABORT,
   JPEG_STATUS_ENC_ERROR_NOT_UNSUPPORT_HW,
   JPEG_STATUS_ENC_ERROR_NOT_UNSUPPORT_SW,
   JPEG_STATUS_ENC_ERROR_UNSUPPORTED_FORMAT,
   JPEG_STATUS_ENC_ERROR_UNSUPPORTED_THUMBNAIL_SIZE,
   JPEG_STATUS_ENC_ERROR_NO_NEED_THUMBNAIL,
   JPEG_STATUS_ENC_ERROR_SIZE_OVERFLOW,
   JPEG_STATUS_ENC_ERROR_DST_BUFFER_OVERWRITE_SRC_BUFFER,
   JPEG_STATUS_ENC_ERROR_INVALID_WIDTH,
   JPEG_STATUS_ENC_ERROR_INVALID_HEIGHT,
   JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY,
   JPEG_STATUS_ENC_ERROR_IDP_UNAVAILABLE
} JPEG_STATUS_ENUM;



typedef enum {
   JPEG_CODEC_STATE_FREE = 0,             /// the module is free to use
   JPEG_CODEC_STATE_IDLE,                 /// the module is acquired by some body
   JPEG_CODEC_STATE_BUSY,                 /// the module is working
   JPEG_CODEC_STATE_ABORT,                /// the module is abort
   JPEG_CODEC_STATE_PAUSED,               /// the module is paused (encode: stall, decode: breakpoint)
   JPEG_CODEC_STATE_ERROR,                /// the module stopped due to error
   JPEG_CODEC_STATE_COMPLETE,             /// the module stopped and IDP also stopped

   JPEG_CODEC_STATE_EOF,                  /// notice that this enum is used only internally by HW decoder.
                                          /// the module stopped due to EOF, notice that IDP may be still busy

   JPEG_CODEC_STATE_PAUSING,              /// notice that this enum is used only internally by SW decoder.
                                          /// It means that the SW decoder is to be paused.

   JPEG_CODEC_STATE_STOPPING              /// notice that this enum is used only internally by SW decoder.
                                          /// It means that the SW decoder is to be stopped.
} JPEG_CODEC_STATE_ENUM;



typedef enum {
   JPEG_YUV_FORMAT_UNSUPPORTED = 0,
   JPEG_YUV_FORMAT_NON_STANDARD = 111,
   JPEG_YUV_FORMAT_YUV444 = 444,
   JPEG_YUV_FORMAT_YUV422 = 422,
   JPEG_YUV_FORMAT_YUV411 = 411,
   JPEG_YUV_FORMAT_YUV420 = 420,
   JPEG_YUV_FORMAT_GRAYLEVEL = 400,
   JPEG_YUV_FORMAT_PACKED_UYVY422 = 222
} JPEG_YUV_FORMAT_ENUM;



typedef enum {
   JPEG_RGB_FORMAT_UNSUPPORTED = 0,
   JPEG_RGB_FORMAT_GRAYLEVEL,
   JPEG_RGB_FORMAT_RGB565,
   JPEG_RGB_FORMAT_RGB888,       /// R is high-byte
   JPEG_RGB_FORMAT_BGR888,       /// B is high-byte
   JPEG_RGB_FORMAT_ARGB8888,
   JPEG_RGB_FORMAT_ARGB6666
} JPEG_RGB_FORMAT_ENUM;



typedef enum {
   JPEG_CODEC_TYPE_HW = 0,
   JPEG_CODEC_TYPE_SW
} JPEG_CODEC_TYPE_ENUM;



typedef enum {
   JPEG_SCENARIO_TYPE_JPEG = 0,
   JPEG_SCENARIO_TYPE_MJPEG
} JPEG_SCENARIO_TYPE_ENUM;


typedef enum {
   JPEG_ENCODE_PROCESS_UNSUPPORTED = 0,
   JPEG_ENCODE_PROCESS_BASELINE,
   JPEG_ENCODE_PROCESS_PROGRESSIVE
} JPEG_ENCODE_PROCESS_ENUM;


typedef enum {
   JPEG_ENCODE_SOURCE_UNSUPPORTED = 0,
   JPEG_ENCODE_SOURCE_ISP,          /// for HW JPEG encoder only
   JPEG_ENCODE_SOURCE_YUV_BUFFER,   /// for both HW/SW JPEG encoders
   JPEG_ENCODE_SOURCE_RGB_BUFFER    /// for both HW/SW JPEG encoders
} JPEG_ENCODE_SOURCE_ENUM;



/// The strange enum order is for the compatibility with the legacy driver.
/// Do not modify it!
typedef enum {
   JPEG_ENCODE_QUALITY_LOW = 0,
   JPEG_ENCODE_QUALITY_FAIR = 1,
   JPEG_ENCODE_QUALITY_GOOD = 2,
   JPEG_ENCODE_QUALITY_EXCELLENT = 3,
   JPEG_ENCODE_QUALITY_POOR = 5
} JPEG_ENCODE_QUALITTY_ENUM;



/*********************************************************

               |  JPEG  |  JFIF  |  JFXX  |
 --------------|--------|--------|--------|
  No thumbnail |   V    |   V    |   V    |
 --------------|--------|--------|--------|
  Uncompressed |   X    |   V    |   V    |
  (3 Bpp)      |        |        |        |
 ------------- |--------|--------|--------|
  Compressed   |   X    |   X    |  TBD   |
  (JPEG)       |        |        |        |
 --------------|--------|--------|--------|

*********************************************************/
typedef enum {
   JPEG_FILE_FORMAT_JPEG = 0,    /// the simplest JPEG file format
   JPEG_FILE_FORMAT_JFIF = 1,    /// JFIF Extension
   JPEG_FILE_FORMAT_EXIF = 2,    /// EXIF
   JPEG_FILE_FORMAT_QVIMG = 4    /// Quick view image

} JPEG_FILE_FORMAT_ENUM;

///#define JPEG_FILE_FORMAT_JFIF    JPEG_FILE_FORMAT_JFXX



/// We currently implement the thumbnail in JFIX/JFXX header only.
/// The EXIF thumbnail is not a must-have feature.
typedef enum {
   JPEG_THUMBNAIL_TYPE_NONE = 0,
   JPEG_THUMBNAIL_TYPE_3BPP,     /// Non compressed, 3 bytes per pixel raw data
   JPEG_THUMBNAIL_TYPE_JPEG      /// JPEG compressed, not ready yet
} JPEG_THUMBNAIL_TYPE_ENUM;



typedef enum {
   JPEG_DECODE_MODE_AUTO = 0,
   JPEG_DECODE_MODE_MAIN_IMAGE,
   JPEG_DECODE_MODE_THUMBNAIL,
   JPEG_DECODE_MODE_QUICK_VIEW_IMAGE
} JPEG_DECODE_MODE_ENUM;



typedef enum
{
   ///JPEG_ENCODE_ROTATE_ANGLE_NULL = 0,                 ///< NULL, do not use.
   JPEG_ENCODE_ROTATE_ANGLE_000 = 0,                  ///< No rotation.
   JPEG_ENCODE_ROTATE_ANGLE_090,                      ///< Rotate 90 degree.
   JPEG_ENCODE_ROTATE_ANGLE_180,                      ///< Rotate 180 degree.
   JPEG_ENCODE_ROTATE_ANGLE_270,                      ///< Rotate 270 degree.
   JPEG_ENCODE_ROTATE_ANGLE_MIRROR_000,               ///< Mirror with no rotation.
   JPEG_ENCODE_ROTATE_ANGLE_MIRROR_090,               ///< Rotate 90 degree and mirror.
   JPEG_ENCODE_ROTATE_ANGLE_MIRROR_180,               ///< Rotate 180 degree and mirror.
   JPEG_ENCODE_ROTATE_ANGLE_MIRROR_270                ///< Rotate 270 degree and mirror.
} JPEG_ENCODE_ROTATE_ANGLE_ENUM;


typedef enum
{
   JPEG_DECODE_NO_FLIP_ROTATE_CW_0     = 1,
   JPEG_DECODE_FLIP_HORIZONTAL_ONLY    = 2,
   JPEG_DECODE_NO_FLIP_ROTATE_CW_180   = 3,
   JPEG_DECODE_FLIP_AND_ROTATE_CW_180  = 4,
   JPEG_DECODE_FLIP_AND_ROTATE_CW_270  = 5,
   JPEG_DECODE_NO_FLIP_ROTATE_CW_270   = 6,
   JPEG_DECODE_FLIP_AND_ROTATE_CW_90   = 7,
   JPEG_DECODE_NO_FLIP_ROTATE_CW_90    = 8
} JPEG_DECODE_ROTATE_ANGLE_ENUM;


typedef enum
{            
   JPEG_ENCODE_EVALUATION_MODE_AVERAGE = 0,                  
   JPEG_ENCODE_EVALUATION_MODE_WORST                  
} JPEG_ENCODE_EVALUATION_MODE_ENUM;


#endif   /// _JPEG_ENUM_H_

