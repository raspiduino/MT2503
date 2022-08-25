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
 *   jaia_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   ##
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JAIA_ENUM_H__
#define __JAIA_ENUM_H__



typedef enum
{
    JAIA_RETURN_OK = 0,                                     ///< It means function works successfully.
    JAIA_RETURN_INVALID_POINTER,                            ///< Invalud pointer.
    JAIA_RETURN_INVALID_QVI_RESOLUTION,                     ///< Invalid QVI width/height.
    JAIA_RETURN_INVALID_TN_RESOLUTION,                      ///< Invalid thumbnail width/height.
    JAIA_RETURN_UNKNOWN_PROCESS,                            ///< Unknown process assign for QVI/TN process.
    JAIA_RETURN_ENCODE_JPEG_FAIL,                           ///< Encode JPEG fail.
    JAIA_BUFFER_INSUFFICIENT_MEMORY,                        ///< Insufficient memory.
    JAIA_RETURN_CONVERT_IFD_TAG_ERROR,                      ///< IFD tags convert error.
    JAIA_RETURN_FSAL_OUTPUT_ERROR,                          ///< FSAL output error happens.
    JAIA_RETURN_EXIF_SEGMENT_OVERFLOW,                      ///< Exif marker segment overflow.
    JAIA_RETURN_OUTPUT_EXIF_FAIL,                           ///< Output exif fail.
    JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL,                     ///< Create exif entry fail.
    JAIA_RETURN_GET_EXIF_ENTRY_FAIL,                        ///< Get exif entry fail.
    JAIA_RETURN_CAN_NOT_FIND_RECOMMENT_RESOLUTION,          ///< Can not get recomment resolution.
    JAIA_RETURN_USER_ABORT,                                 ///< Abort by user.
    JAIA_RETURN_INIT_ORIGINAL_FILE_FAIL,                    ///< Fail to initial The original JPEG file.
    JAIA_RETURN_QUERY_ENCODE_MEMORY_FAIL,                   ///< Fail to query JPEG encoder memory.
    JAIA_RETURN_UNSUPPORT_QVI,                              ///< Unsupport qvi fail.
    JAIA_RETURN_UNSUPPORT_EXIF,                             ///< Unsupport exif fail.
    JAIA_RETURN_UNSUPPORT_THUMBNAIL,                        ///< Unsupport thumbnail fail.
    JAIA_RETURN_UNSUPPORTED,                                ///< Unsupport jaia fail.

} JAIA_RETURN_STATUS_ENUM;



typedef enum
{
    JAIA_EXIF_PROC_NO_EXIF = 0,                             ///< No exif output for destination file.
    JAIA_EXIF_PROC_EXIF_WITHOUT_TNUMBNAIL,                  ///< Exif information output only.
    JAIA_EXIF_PROC_EXIF_WITH_JPEG_TNUMBNAIL,                ///< Exif information with JPEG thumbnail.
    JAIA_EXIF_PROC_EXIF_WITH_UNCOMPRESSED_THUMBNAIL,        ///< Exif information with uncompressed thumbnail.

} JAIA_EXIF_PROC_ENUM;



typedef enum
{
    JAIA_TN_PROC_NO_THUMBNAIL = 0,                          ///< No thumbnail output for destination file.
    JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_RAW_SOURCE,            ///< (In exif) JPEG thumbnail obtains from YUV/RGB raw source.
    JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_DECODING_SOURCE,       ///< (In exif) JPEG thumbnail obtains from decoding original image.
    JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_USER_PROVIDE,          ///< (In exif) JPEG thumbnail obtains from user provided.
    JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_PARSING,               ///< (In exif) JPEG thumbnail obtains from parsing original image's exif.
    JAIA_TN_PROC_UNCOMPRESSED_THUMBNAIL_FROM_PARSING,       ///< (In exif) Uncompressed image obtains from parsing original image's exif.
    JAIA_TN_PROC_UNCOMPRESSED_THUMBNAIL_FROM_JFXX,          ///< (In jfxx) Uncompressed image obtains from parsing JFXX.

} JAIA_TN_PROC_ENUM;



typedef enum
{
    JAIA_QVI_PROC_NO_QVI = 0,                               ///< No QVI output for destination file.
    JAIA_QVI_PROC_QVI_FROM_RAW_SOURCE,                      ///< QVI obtains from YUV/RGB raw source.
    JAIA_QVI_PROC_QVI_FROM_DECODING_SOURCE,                 ///< QVI obtains from decoding original JPEG image.
    JAIA_QVI_PROC_QVI_FROM_USER_PROVIDE,                    ///< QVI obtains from user provided.
    JAIA_QVI_PROC_QVI_FROM_PARSING,                         ///< QVI obtains from parsing original JPEG image.

} JAIA_QVI_PROC_ENUM;



typedef enum
{
    JAIA_IMAGE_TYPE_UNCOMPRESSED = 0,                       ///< JAIA Image type: uncompressed.
    JAIA_IMAGE_TYPE_JPEG,                                   ///< JAIA Image type: compressed.

} JAIA_IMAGE_TYPE_ENUM;



typedef enum
{
    JAIA_IMAGE_TYPE_RGB888 = 0,                             ///< JAIA color format: RGB888.
    JAIA_IMAGE_TYPE_RGB565,                                 ///< JAIA color format: RGB565.
    JAIA_IMAGE_TYPE_YUV420,                                 ///< JAIA color format: YUV420.
    JAIA_IMAGE_TYPE_PACKED_UYVY422,                         ///< JAIA color format: Packed UYVY422.

} JAIA_IMAGE_COLOR_FORMAT_ENUM;



typedef enum
{
    JAIA_OUTPUT_TO_FILE = 0,                                ///< JAIA output to file.
    JAIA_OUTPUT_TO_MEMORY,                                  ///< JAIA output to memory.

} JAIA_OUTPUT_MODE_ENUM;



#endif  /// End of #ifndef __JAIA_ENUM_H__
