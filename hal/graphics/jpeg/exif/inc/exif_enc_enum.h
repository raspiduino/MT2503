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
 *   exif_enc_enum.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_ENC_ENUM_V2_H__
#define __EXIF_ENC_ENUM_V2_H__

/// Exif unsigned byte data type. (1 byte)
typedef unsigned char   EXIF_BYTE_T;
	
/// Exif signed byte data type. (1 byte)
typedef signed char     EXIF_SBYTE_T;
	
/// Exif text string data type.
typedef char *          EXIF_ASCII_T;

/// Exif unsigned short data type. (2 bytes)
typedef unsigned short  EXIF_SHORT_T;

/// Exif signed short data type. (2 bytes)
typedef short           EXIF_SSHORT_T;
	
/// Exif unsigned long data type. (4 bytes)
typedef unsigned int    EXIF_LONG_T;
	
/// Exif signed long data type. (4 bytes)
typedef int             EXIF_SLONG_T;

/// Exif unsigned rational data type.
typedef struct {EXIF_LONG_T numerator; EXIF_LONG_T denominator;} EXIF_RATIONAL_T;

/// Exif signed rational data type.
typedef struct {EXIF_SLONG_T numerator; EXIF_SLONG_T denominator;} EXIF_SRATIONAL_T;

/// Exif undefined data type. (1 byte)
typedef char            EXIF_UNDEFINED_T;



/// Exif return status.
typedef enum
{
    EXIF_RETURN_OK = 0,                         ///< It means function works successfully.
    EXIF_RETURN_INSUFFICIENT_MEMORY,            ///< Working memory is insufficient.
    EXIF_RETURN_INVALID_POINTER,                ///< The pointer is invalid (NULL).
    EXIF_RETURN_OVER_MAX_IFD_LIMIT,             ///< Selected IFD is larger than maxinum ifd defined in EXIF_IFD_ENUM.
    EXIF_RETURN_OVER_MAX_ENTRY_LIMIT,           ///< Over maximum entry limitation defined in EXIF_IFD_XXXX_ENTRY_MAX.
    EXIF_RETURN_NO_IFD_0_INFO,                  ///< When saving encoded exif data, there is no IFD 0 information. IFD 0 information is mandatory.
    EXIF_RETURN_DUPLICATE_ENTRY,                ///< There are duplicated entries stored in the exif data structure.
    EXIF_RETURN_ENTRY_DATA_SIZE_INCORRECT,      ///< entry_data_size != (exif_format_get_size(tag_format) * tag_counts)
    EXIF_RETURN_NO_SELECTED_ENTRY,               ///< Can NOT find the selected entry when get entry from exif data structure.
    EXIF_RETURN_UNSUPPORT_EXIF               ///< Unsupport exif fail.

} EXIF_RETURN_STATUS_ENUM;



// Byte order
typedef enum
{
    EXIF_BYTE_ORDER_BIG_ENDIAN = 0,             ///< Byte order big endian.

    EXIF_BYTE_ORDER_LITTLE_ENDIAN               ///< Byte order little endian.

} EXIF_BYTE_ORDER_ENUM;



/*! Options to configure the behaviour of #ExifData */
typedef enum
{
	EXIF_DATA_OPTION_IGNORE_UNKNOWN_TAGS = 1 << 0,

	EXIF_DATA_OPTION_FOLLOW_SPECIFICATION = 1 << 1,

	EXIF_DATA_OPTION_DONT_CHANGE_MAKER_NOTE = 1 << 2

} EXIF_DATA_OPTION_ENUM;



// EXIF tag data formats
typedef enum
{
    EXIF_FORMAT_NULL                        =  0,
    EXIF_FORMAT_BYTE                        =  1,
    EXIF_FORMAT_ASCII                       =  2,
    EXIF_FORMAT_SHORT                       =  3,
    EXIF_FORMAT_LONG                        =  4,
    EXIF_FORMAT_RATIONAL                    =  5,
    EXIF_FORMAT_SBYTE                       =  6,
    EXIF_FORMAT_UNDEFINED                   =  7,
    EXIF_FORMAT_SSHORT                      =  8,
    EXIF_FORMAT_SLONG                       =  9,
    EXIF_FORMAT_SRATIONAL                   = 10,
    EXIF_FORMAT_FLOAT                       = 11,
    EXIF_FORMAT_DOUBLE                      = 12

} EXIF_TAG_FORMAT_ENUM;



/// Exif IFD enum.
typedef enum {

    EXIF_IFD_0 = 0,                             ///< EXIF IFD 0.
    EXIF_IFD_1,                                 ///< EXIF IFD 1.
    EXIF_IFD_EXIF,                              ///< EXIF IFD EXIF.
    EXIF_IFD_GPS,                               ///< EXIF IFD GPS.
    EXIF_IFD_INTEROPERABILITY,                  ///< EXIF IFD INTEROPERABILITY.
    EXIF_IFD_COUNT                              ///< Maximum IFD number.

} EXIF_IFD_ENUM;



#define EXIF_IFD_0_ENTRY_MAX                        (20)        ///< Maximum entry number in IFD 0.
#define EXIF_IFD_1_ENTRY_MAX                        (20)        ///< Maximum entry number in IFD 1.
#define EXIF_IFD_EXIF_ENTRY_MAX                     (61)        ///< Maximum entry number in IFD EXIF.
#define EXIF_IFD_GPS_ENTRY_MAX                      (32)        ///< Maximum entry number in IFD GPS.
#define EXIF_IFD_INTEROPERABILITY_ENTRY_MAX         (3)         ///< Maximum entry number in IFD INTEROPERABILITY.



#endif  // End of #ifndef __EXIF_ENC_STRUCTURE_V2_H__
