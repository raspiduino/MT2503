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
 *   exif_dec_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This header file defines the structure used by EXIF parser.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_DEC_STRUCTURE_V2_H__
#define __EXIF_DEC_STRUCTURE_V2_H__

#include "kal_general_types.h"
#include "fsal.h"
#include "exif_dec_id.h"


#define TIFF_HEADER_BIG_ENDIAN      0x4D4D
#define TIFF_HEADER_LITTLE_ENDIAN   0x4949


typedef struct IFD_FIELD_T {
   kal_uint16 type;
   kal_uint32 count;
   kal_uint32 valueOffset;
} IFD_FIELD;



typedef struct IFD_INFO_T {
   kal_uint32 offsetInFile;      ///< the offset in the file
   kal_uint32 ifdEntryCount;     ///< the number of IFD entries in this IFD
   kal_uint32 ifdEntryFlag[2];   ///< bit mask to indicate the existence of IFD entries
   IFD_FIELD  *ifdFieldPtr;      ///< pointer to the IFD interoperability array
   kal_uint32 nextIFDOffset;     ///< the offset to the next IFD
} IFD_INFO;



typedef struct EXIF_APP1_INFO_T {
   STFSAL *sourceFile;
   kal_uint32 offsetInFile;      ///< the offset of APP1 marker in source file
   kal_uint32 length;            ///< the length of APP1 marker
   
   kal_uint32 byteOrder;         ///< 0x2A004949 for little endian, 0x2A004D4D for big endian
   kal_uint32 offsetIFD0;        ///< the offset of IFD0 in APP1 marker, this value is recorded in TIFF header

   IFD_INFO ifd0Info;            ///< IFD_INFO structure for 0th IFD (IFD0)
   IFD_INFO ifd1Info;            ///< IFD_INFO structure for 1st IFD (IFD1)
   IFD_INFO exifInfo;            ///< IFD_INFO structure for EXIF IFD
   IFD_INFO gpsInfo;             ///< IFD_INFO structure for GPS IFD
   IFD_INFO interoperabilityInfo;             ///< IFD_INFO structure for INTEROPERABILITY IFD

   IFD_FIELD ifd0Attributes[TIFF_TAG_ENTRY_MAX_COUNT];   ///< fields entry for IFD0: main image information
   IFD_FIELD ifd1Attributes[TIFF_TAG_ENTRY_MAX_COUNT];   ///< fields entry for IFD1: thumbnail image information
   IFD_FIELD exifAttributes[EXIF_TAG_ENTRY_MAX_COUNT];   ///< fields entry for EXIF IFD: exif information
   IFD_FIELD gpsAttributes[GPS_TAG_ENTRY_MAX_COUNT];     ///< fields entry for GPS IFD: GPS information
   IFD_FIELD interoperabilityAttributes[INTEROPERABILITY_TAG_ENTRY_MAX_COUNT];     ///< fields entry for INTEROPERABILITY IFD: INTEROPERABILITY information
} EXIF_APP1_INFO;

#endif  // __EXIF_DEC_STRUCTURE_V2_H__
