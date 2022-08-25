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
 *   jpeg_parse_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition of JPEG parser.
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

#ifndef __JPEG_PARSE_STRUCTURE_H__
#define __JPEG_PARSE_STRUCTURE_H__

#include "kal_general_types.h"
#include "fsal.h"
#include "jpeg_enum.h"
#include "jpeg_enum_int.h"
#include "exif_dec_structure.h"


/* Definition for mandatory marker to decode a JPEG file */
#define JPEG_MANDATORY_MARKER_SOF_BIT  0x00000001
#define JPEG_MANDATORY_MARKER_DQT_BIT  0x00000002

#define JPEG_MANDATORY_MARKER_CHECK    0x00000003


/// JPEG_FRAME_COMPONENT_INFO structure defines the variables in the 
/// JPEG frame component-specification parameters.
typedef struct JPEG_FRAME_COMPONENT_INFO_T
{
   kal_uint8                  componentID;            ///< Ci
   kal_uint8                  hSamplingFactor;        ///< Hi
   kal_uint8                  vSamplingFactor;        ///< Vi
   kal_uint8                  qTableSelector;         ///< Tqi
} JPEG_FRAME_COMPONENT_INFO;


/// JPEG_FRAME_INFO structure defines the variables in the JPEG frame header.
typedef struct JPEG_FRAME_INFO_T
{
   kal_uint16                 frameHeaderType;        ///< only type 0 and type 2 are supported
   kal_uint16                 frameHeaderLength;      ///< Lf
   kal_uint16                 height;                 ///< Y
   kal_uint16                 width;                  ///< X

   kal_uint8                  samplePrecision;        ///< P
   JPEG_YUV_FORMAT_ENUM       samplingFormat;         ///< YUV sampling format
   kal_uint8                  numberOfComponents;     ///< Nf, we support only 1 and 3
   JPEG_ENCODE_PROCESS_ENUM   encProcess;             ///< encoding process, may be baseline or progressive
   JPEG_FRAME_COMPONENT_INFO  frameComponentInfo[3];  ///< JPEG frame component-specification parameters

   kal_uint32                 hSamplingFactorMax;     ///< the maximum horizontal sampling factor
   kal_uint32                 vSamplingFactorMax;     ///< the maximum vertical sampling factor

   kal_uint32                 paddedWidth;            ///< the padded width after JPEG block padding
   kal_uint32                 paddedHeight;           ///< the padded height after JPEG block padding

   kal_uint32                 mcuPerRow;              ///< number of MCU per MCU row in the JPEG file
   kal_uint32                 mcuPerColumn;           ///< number of MCU per MCU column in the JPEG file
   kal_uint32                 widthInBlocks;          ///< the maximum with of blocks in one MCU
   kal_uint32                 duPerMCU;               ///< number of DU per MCU
} JPEG_FRAME_INFO;


typedef struct JPEG_THUMBNAIL_INFO_T
{
   JPEG_THUMBNAIL_TYPE_ENUM   tn_type;
   kal_uint32                 tn_width;
   kal_uint32                 tn_height;
   kal_uint32                 tn_offset;
   kal_uint32                 tn_data_length;
} JPEG_THUMBNAIL_INFO;


typedef struct JPEG_FILE_INFO_T
{
   STFSAL                     *fileHandle;            ///< FSAL handle for the source image file
   kal_uint32                 realSize;               ///< The real file size of the JPEG file
   kal_uint32                 realOffset;             ///< The real offset of the JPEG file in a file

   JPEG_STATUS_ENUM           parseStatus;            ///< Field to store the last parsing status
   JPEG_PARSE_STATE_ENUM      parseState;             ///< Field to store the last parsing state

   kal_uint8                  segmentMarker[2];       ///< Current segment marker for parsing the info
   kal_uint16                 segmentLength;          ///< The data length in bytes of current segment
   kal_uint16                 segmentConsumed;        ///< How many bytes are consumed during parsing

   kal_uint32                 offsetTableMisc;        ///< The offset where the first DQT/DHT/DRI is found.
                                                      ///< For HW decoder, this is the position where we set to HW.
                                                      ///< For SW decoder, this value indicates the position where
                                                      ///< the information of the decoding tables locates.
                                                      ///< The SW decoder must set the DHT, DQT and DRI for decoding.

   kal_uint32                 offsetECS0;

   JPEG_FRAME_INFO            frameInfo;              ///< The field is for storing the frame related information 

   kal_uint32                 offsetAPPn[9];          ///< Storing file offset of APP0, APP1 and APP2 segment.
                                                      ///< Currently we care about APP0, APP1 and APP2 segments.
   JPEG_THUMBNAIL_INFO        thumbnailInfo;          ///< This is the buffer for storing APP0 segment info
   JPEG_THUMBNAIL_INFO        qviInfo;                ///< This is for Mediatek proprietary quick view image
   EXIF_APP1_INFO             *app1Info;              ///< This is the buffer for storing APP1 segment info

   kal_uint32                 mandatoryMarkerCheck;
} JPEG_FILE_INFO;

typedef JPEG_FILE_INFO  JPEG_PARSER;

#endif  // __JPEG_PARSE_STRUCTURE_H__
