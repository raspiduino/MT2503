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
 *   exif_dec_id.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This header file defines the EXIF ID.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_DEC_ID_V2_H__
#define __EXIF_DEC_ID_V2_H__


// 0th / 1st IFD TIFF Tags
#define TIFF_TAG_ID_IMAGE_WIDTH                    0x0100
#define TIFF_TAG_ID_IMAGE_HEIGHT                   0x0101
#define TIFF_TAG_ID_BITS_PER_SAMPLE                0x0102
#define TIFF_TAG_ID_COMPRESSION                    0x0103
#define TIFF_TAG_ID_PHOTOMETRIC_INTERPRETATION     0x0106
#define TIFF_TAG_ID_IMAGE_DESCRIPTION              0x010E
#define TIFF_TAG_ID_MAKE                           0x010F
#define TIFF_TAG_ID_MODEL                          0x0110
#define TIFF_TAG_ID_STRIP_OFFSETS                  0x0111
#define TIFF_TAG_ID_ORIENTATION                    0x0112
#define TIFF_TAG_ID_SAMPLES_PER_PIXEL              0x0115
#define TIFF_TAG_ID_ROWS_PER_STRIP                 0x0116
#define TIFF_TAG_ID_STRIP_BYTE_COUNTS              0x0117
#define TIFF_TAG_ID_X_RESOLUTION                   0x011A
#define TIFF_TAG_ID_Y_RESOLUTION                   0x011B
#define TIFF_TAG_ID_PLANAR_CONFIGURATION           0x011C
#define TIFF_TAG_ID_RESOLUTION_UNIT                0x0128
#define TIFF_TAG_ID_TRANSFER_FUNCTION              0x012D
#define TIFF_TAG_ID_SOFTWARE                       0x0131
#define TIFF_TAG_ID_DATE_TIME                      0x0132
#define TIFF_TAG_ID_ARTIST                         0x013B
#define TIFF_TAG_ID_WHITE_POINT                    0x013E
#define TIFF_TAG_ID_PRIMARY_CHROMATICITIES         0x013F
#define TIFF_TAG_ID_JPEG_INTERCHANGE_FORMAT        0x0201
#define TIFF_TAG_ID_JPEG_INTERCHANGE_FORMAT_LENGTH 0x0202
#define TIFF_TAG_ID_Y_CB_CR_COEFFICIENTS           0x0211
#define TIFF_TAG_ID_Y_CB_CR_SUBSAMPLING            0x0212
#define TIFF_TAG_ID_Y_CB_CR_POSITIONING            0x0213
#define TIFF_TAG_ID_REFERENCE_BLACK_WHITE          0x0214
#define TIFF_TAG_ID_COPYRIGHT                      0x8298
#define TIFF_TAG_ID_EXIF_IFD_POINTER               0x8769
#define TIFF_TAG_ID_GPS_INFO_IFD_POINTER           0x8825

typedef enum {
   TIFF_TAG_ENTRY_IMAGE_WIDTH                      ,
   TIFF_TAG_ENTRY_IMAGE_HEIGHT                     ,
   TIFF_TAG_ENTRY_BITS_PER_SAMPLE                  ,
   TIFF_TAG_ENTRY_COMPRESSION                      ,
   TIFF_TAG_ENTRY_PHOTOMETRIC_INTERPRETATION       ,
   TIFF_TAG_ENTRY_IMAGE_DESCRIPTION                ,
   TIFF_TAG_ENTRY_MAKE                             ,
   TIFF_TAG_ENTRY_MODEL                            ,
   TIFF_TAG_ENTRY_STRIP_OFFSETS                    ,
   TIFF_TAG_ENTRY_ORIENTATION                      ,
   TIFF_TAG_ENTRY_SAMPLES_PER_PIXEL                ,
   TIFF_TAG_ENTRY_ROWS_PER_STRIP                   ,
   TIFF_TAG_ENTRY_STRIP_BYTE_COUNTS                ,
   TIFF_TAG_ENTRY_X_RESOLUTION                     ,
   TIFF_TAG_ENTRY_Y_RESOLUTION                     ,
   TIFF_TAG_ENTRY_PLANAR_CONFIGURATION             ,
   TIFF_TAG_ENTRY_RESOLUTION_UNIT                  ,
   TIFF_TAG_ENTRY_TRANSFER_FUNCTION                ,
   TIFF_TAG_ENTRY_SOFTWARE                         ,
   TIFF_TAG_ENTRY_DATE_TIME                        ,
   TIFF_TAG_ENTRY_ARTIST                           ,
   TIFF_TAG_ENTRY_WHITE_POINT                      ,
   TIFF_TAG_ENTRY_PRIMARY_CHROMATICITIES           ,
   TIFF_TAG_ENTRY_JPEG_INTERCHANGE_FORMAT          ,
   TIFF_TAG_ENTRY_JPEG_INTERCHANGE_FORMAT_LENGTH   ,
   TIFF_TAG_ENTRY_Y_CB_CR_COEFFICIENTS             ,
   TIFF_TAG_ENTRY_Y_CB_CR_SUBSAMPLING              ,
   TIFF_TAG_ENTRY_Y_CB_CR_POSITIONING              ,
   TIFF_TAG_ENTRY_REFERENCE_BLACK_WHITE            ,
   TIFF_TAG_ENTRY_COPYRIGHT                        ,
   TIFF_TAG_ENTRY_EXIF_IFD_POINTER                 ,
   TIFF_TAG_ENTRY_GPS_INFO_IFD_POINTER             ,
   TIFF_TAG_ENTRY_MAX_COUNT
} TIFF_TAG_ENTRY_ENUM;



// 0th IFD EXIF Private Tags
#define EXIF_TAG_ID_EXPOSURE_TIME                  0x829A
#define EXIF_TAG_ID_F_NUMBER                       0x829D
#define EXIF_TAG_ID_EXPOSURE_PROGRAM               0x8822
#define EXIF_TAG_ID_SPECTRAL_SENSITIVITY           0x8824
#define EXIF_TAG_ID_ISO_SPEED_RATINGS              0x8827
#define EXIF_TAG_ID_OECF                           0x8828
#define EXIF_TAG_ID_EXIF_VERSION                   0x9000
#define EXIF_TAG_ID_DATE_TIME_ORIGINAL             0x9003
#define EXIF_TAG_ID_DATE_TIME_DIGITIZED            0x9004
#define EXIF_TAG_ID_COMPONENTS_CONFIGURATION       0x9101
#define EXIF_TAG_ID_COMPRESSED_BITS_PER_PIXEL      0x9102
#define EXIF_TAG_ID_SHUTTER_SPEED_VALUE            0x9201
#define EXIF_TAG_ID_APERTURE_VALUE                 0x9202
#define EXIF_TAG_ID_BRIGHTNESS_VALUE               0x9203
#define EXIF_TAG_ID_EXPOSURE_BIASVALUE             0x9204
#define EXIF_TAG_ID_MAX_APERTURE_VALUE             0x9205
#define EXIF_TAG_ID_SUBJECT_DISTANCE               0x9206
#define EXIF_TAG_ID_METERING_MODE                  0x9207
#define EXIF_TAG_ID_LIGHT_SOURCE                   0x9208
#define EXIF_TAG_ID_FLASH                          0x9209
#define EXIF_TAG_ID_FOCAL_LENGTH                   0x920A
#define EXIF_TAG_ID_SUBJECT_AREA                   0x9214
#define EXIF_TAG_ID_MAKER_NOTE                     0x927C
#define EXIF_TAG_ID_USER_COMMENT                   0x9286
#define EXIF_TAG_ID_SUB_SEC_TIME                   0x9290
#define EXIF_TAG_ID_SUB_SEC_TIME_ORIGINAL          0x9291
#define EXIF_TAG_ID_SUB_SEC_TIME_DIGITIZED         0x9292
#define EXIF_TAG_ID_FLASHPIX_VERSION               0xA000
#define EXIF_TAG_ID_COLOR_SPACE                    0xA001
#define EXIF_TAG_ID_PIXEL_X_DIMENSION              0xA002
#define EXIF_TAG_ID_PIXEL_Y_DIMENSION              0xA003
#define EXIF_TAG_ID_RELATED_SOUNDFILE              0xA004
#define EXIF_TAG_ID_INTEROPERABILITY_IFD_POINTER   0xA005
#define EXIF_TAG_ID_FLASH_ENERGY                   0xA20B
#define EXIF_TAG_ID_SPATIAL_FREQUENCY_RESPONSE     0xA20C
#define EXIF_TAG_ID_FOCAL_PLANE_X_RESOLUTION       0xA20E
#define EXIF_TAG_ID_FOCAL_PLANE_Y_RESOLUTION       0xA20F
#define EXIF_TAG_ID_FOCAL_PLANE_RESOLUTION_UNIT    0xA210
#define EXIF_TAG_ID_SUBJECT_LOCATION               0xA214
#define EXIF_TAG_ID_EXPOSURE_INDEX                 0xA215
#define EXIF_TAG_ID_SENSING_METHOD                 0xA217
#define EXIF_TAG_ID_FILE_SOURCE                    0xA300
#define EXIF_TAG_ID_SCENE_TYPE                     0xA301
#define EXIF_TAG_ID_CFA_PATTERN                    0xA302
#define EXIF_TAG_ID_CUSTOM_RENDERED                0xA401
#define EXIF_TAG_ID_EXPOSURE_MODE                  0xA402
#define EXIF_TAG_ID_WHITE_BALANCE                  0xA403
#define EXIF_TAG_ID_DIGITAL_ZOOM_RATIO             0xA404
#define EXIF_TAG_ID_FOCAL_LENGTH_IN_35MM_FILM      0xA405
#define EXIF_TAG_ID_SCENE_CAPTURE_TYPE             0xA406
#define EXIF_TAG_ID_GAIN_CONTROL                   0xA407
#define EXIF_TAG_ID_CONTRAST                       0xA408
#define EXIF_TAG_ID_SATURATION                     0xA409
#define EXIF_TAG_ID_SHARPNESS                      0xA40A
#define EXIF_TAG_ID_DEVICE_SETTING_DESCRIPTION     0xA40B
#define EXIF_TAG_ID_SUBJECT_DISTANCE_RANGE         0xA40C
#define EXIF_TAG_ID_IMAGE_UNIQUE_ID                0xA420

typedef enum {
   EXIF_TAG_ENTRY_EXPOSURE_TIME                    ,
   EXIF_TAG_ENTRY_F_NUMBER                         ,
   EXIF_TAG_ENTRY_EXPOSURE_PROGRAM                 ,
   EXIF_TAG_ENTRY_SPECTRAL_SENSITIVITY             ,
   EXIF_TAG_ENTRY_ISO_SPEED_RATINGS                ,
   EXIF_TAG_ENTRY_OECF                             ,
   EXIF_TAG_ENTRY_EXIF_VERSION                     ,
   EXIF_TAG_ENTRY_DATE_TIME_ORIGINAL               ,
   EXIF_TAG_ENTRY_DATE_TIME_DIGITIZED              ,
   EXIF_TAG_ENTRY_COMPONENTS_CONFIGURATION         ,
   EXIF_TAG_ENTRY_COMPRESSED_BITS_PER_PIXEL        ,
   EXIF_TAG_ENTRY_SHUTTER_SPEED_VALUE              ,
   EXIF_TAG_ENTRY_APERTURE_VALUE                   ,
   EXIF_TAG_ENTRY_BRIGHTNESS_VALUE                 ,
   EXIF_TAG_ENTRY_EXPOSURE_BIASVALUE               ,
   EXIF_TAG_ENTRY_MAX_APERTURE_VALUE               ,
   EXIF_TAG_ENTRY_SUBJECT_DISTANCE                 ,
   EXIF_TAG_ENTRY_METERING_MODE                    ,
   EXIF_TAG_ENTRY_LIGHT_SOURCE                     ,
   EXIF_TAG_ENTRY_FLASH                            ,
   EXIF_TAG_ENTRY_FOCAL_LENGTH                     ,
   EXIF_TAG_ENTRY_SUBJECT_AREA                     ,
   EXIF_TAG_ENTRY_MAKER_NOTE                       ,
   EXIF_TAG_ENTRY_USER_COMMENT                     ,
   EXIF_TAG_ENTRY_SUB_SEC_TIME                     ,
   EXIF_TAG_ENTRY_SUB_SEC_TIME_ORIGINAL            ,
   EXIF_TAG_ENTRY_SUB_SEC_TIME_DIGITIZED           ,
   EXIF_TAG_ENTRY_FLASHPIX_VERSION                 ,
   EXIF_TAG_ENTRY_COLOR_SPACE                      ,
   EXIF_TAG_ENTRY_PIXEL_X_DIMENSION                ,
   EXIF_TAG_ENTRY_PIXEL_Y_DIMENSION                ,
   EXIF_TAG_ENTRY_RELATED_SOUNDFILE                ,
   EXIF_TAG_ENTRY_INTEROPERABILITY_IFD_POINTER     ,
   EXIF_TAG_ENTRY_FLASH_ENERGY                     ,
   EXIF_TAG_ENTRY_SPATIAL_FREQUENCY_RESPONSE       ,
   EXIF_TAG_ENTRY_FOCAL_PLANE_X_RESOLUTION         ,
   EXIF_TAG_ENTRY_FOCAL_PLANE_Y_RESOLUTION         ,
   EXIF_TAG_ENTRY_FOCAL_PLANE_RESOLUTION_UNIT      ,
   EXIF_TAG_ENTRY_SUBJECT_LOCATION                 ,
   EXIF_TAG_ENTRY_EXPOSURE_INDEX                   ,
   EXIF_TAG_ENTRY_SENSING_METHOD                   ,
   EXIF_TAG_ENTRY_FILE_SOURCE                      ,
   EXIF_TAG_ENTRY_SCENE_TYPE                       ,
   EXIF_TAG_ENTRY_CFA_PATTERN                      ,
   EXIF_TAG_ENTRY_CUSTOM_RENDERED                  ,
   EXIF_TAG_ENTRY_EXPOSURE_MODE                    ,
   EXIF_TAG_ENTRY_WHITE_BALANCE                    ,
   EXIF_TAG_ENTRY_DIGITAL_ZOOM_RATIO               ,
   EXIF_TAG_ENTRY_FOCAL_LENGTH_IN_35MM_FILM        ,
   EXIF_TAG_ENTRY_SCENE_CAPTURE_TYPE               ,
   EXIF_TAG_ENTRY_GAIN_CONTROL                     ,
   EXIF_TAG_ENTRY_CONTRAST                         ,
   EXIF_TAG_ENTRY_SATURATION                       ,
   EXIF_TAG_ENTRY_SHARPNESS                        ,
   EXIF_TAG_ENTRY_DEVICE_SETTING_DESCRIPTION       ,
   EXIF_TAG_ENTRY_SUBJECT_DISTANCE_RANGE           ,
   EXIF_TAG_ENTRY_IMAGE_UNIQUE_ID                  ,
   EXIF_TAG_ENTRY_MAX_COUNT
} EXIF_TAG_ENTRY_ENUM;


                                                   
#define GPS_TAG_ID_VERSION_ID                      0x0000
#define GPS_TAG_ID_LATITUDE_REF                    0x0001
#define GPS_TAG_ID_LATITUDE                        0x0002
#define GPS_TAG_ID_LONGITUDE_REF                   0x0003
#define GPS_TAG_ID_LONGITUDE                       0x0004
#define GPS_TAG_ID_ALTITUDE_REF                    0x0005
#define GPS_TAG_ID_ALTITUDE                        0x0006
#define GPS_TAG_ID_TIME_STAMP                      0x0007
#define GPS_TAG_ID_SATELLITES                      0x0008
#define GPS_TAG_ID_STATUS                          0x0009
#define GPS_TAG_ID_MEASURE_MODE                    0x000A
#define GPS_TAG_ID_DOP                             0x000B
#define GPS_TAG_ID_SPEED_REF                       0x000C
#define GPS_TAG_ID_SPEED                           0x000D
#define GPS_TAG_ID_TRACK_REF                       0x000E
#define GPS_TAG_ID_TRACK                           0x000F
#define GPS_TAG_ID_IMG_DIRECTION_REF               0x0010
#define GPS_TAG_ID_IMG_DIRECTION                   0x0011
#define GPS_TAG_ID_MAP_DATUM                       0x0012
#define GPS_TAG_ID_DEST_LATITUDE_REF               0x0013
#define GPS_TAG_ID_DEST_LATITUDE                   0x0014
#define GPS_TAG_ID_DEST_LONGITUDE_REF              0x0015
#define GPS_TAG_ID_DEST_LONGITUDE                  0x0016
#define GPS_TAG_ID_DEST_BEARING_REF                0x0017
#define GPS_TAG_ID_DEST_BEARING                    0x0018
#define GPS_TAG_ID_DEST_DISTANCE_REF               0x0019
#define GPS_TAG_ID_DEST_DISTANCE                   0x001A
#define GPS_TAG_ID_PROCESSING_METHOD               0x001B
#define GPS_TAG_ID_AREA_INFORMATION                0x001C
#define GPS_TAG_ID_DATE_STAMP                      0x001D
#define GPS_TAG_ID_DIFFERENTIAL                    0x001E

typedef enum
{
   GPS_TAG_ENTRY_VERSION_ID                        ,
   GPS_TAG_ENTRY_LATITUDE_REF                      ,
   GPS_TAG_ENTRY_LATITUDE                          ,
   GPS_TAG_ENTRY_LONGITUDE_REF                     ,
   GPS_TAG_ENTRY_LONGITUDE                         ,
   GPS_TAG_ENTRY_ALTITUDE_REF                      ,
   GPS_TAG_ENTRY_ALTITUDE                          ,
   GPS_TAG_ENTRY_TIME_STAMP                        ,
   GPS_TAG_ENTRY_SATELLITES                        ,
   GPS_TAG_ENTRY_STATUS                            ,
   GPS_TAG_ENTRY_MEASURE_MODE                      ,
   GPS_TAG_ENTRY_DOP                               ,
   GPS_TAG_ENTRY_SPEED_REF                         ,
   GPS_TAG_ENTRY_SPEED                             ,
   GPS_TAG_ENTRY_TRACK_REF                         ,
   GPS_TAG_ENTRY_TRACK                             ,
   GPS_TAG_ENTRY_IMG_DIRECTION_REF                 ,
   GPS_TAG_ENTRY_IMG_DIRECTION                     ,
   GPS_TAG_ENTRY_MAP_DATUM                         ,
   GPS_TAG_ENTRY_DEST_LATITUDE_REF                 ,
   GPS_TAG_ENTRY_DEST_LATITUDE                     ,
   GPS_TAG_ENTRY_DEST_LONGITUDE_REF                ,
   GPS_TAG_ENTRY_DEST_LONGITUDE                    ,
   GPS_TAG_ENTRY_DEST_BEARING_REF                  ,
   GPS_TAG_ENTRY_DEST_BEARING                      ,
   GPS_TAG_ENTRY_DEST_DISTANCE_REF                 ,
   GPS_TAG_ENTRY_DEST_DISTANCE                     ,
   GPS_TAG_ENTRY_PROCESSING_METHOD                 ,
   GPS_TAG_ENTRY_AREA_INFORMATION                  ,
   GPS_TAG_ENTRY_DATE_STAMP                        ,
   GPS_TAG_ENTRY_DIFFERENTIAL                      ,
   GPS_TAG_ENTRY_MAX_COUNT
} GPS_TAG_ENTRY_ENUM;


                                                   
#define INTEROPERABILITY_TAG_ID_INTER_INDEX                      0x0001

typedef enum
{
   INTEROPERABILITY_TAG_ENTRY_INTER_INDEX                        ,
   INTEROPERABILITY_TAG_ENTRY_MAX_COUNT
} INTEROPERABILITY_TAG_ENTRY_ENUM;

#endif  // __EXIF_DEC_ID_V2_H__


























