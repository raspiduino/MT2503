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
 *   exif_enc_structure.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_ENC_STRUCTURE_V2_H__
#define __EXIF_ENC_STRUCTURE_V2_H__

#include "exif_enc_enum.h"
#include "simple_memory_manager.h"



typedef struct EXIF_TAG_FORMAT_T
{
    EXIF_TAG_FORMAT_ENUM format;
    unsigned char size;

} EXIF_TAG_FORMAT;



typedef struct EXIF_ENTRY_T
{
    unsigned short tag_id;                      ///< EXIF tag for this entry.

    EXIF_TAG_FORMAT_ENUM tag_format;            ///< Type of data in this entry.

    unsigned int tag_counts;                    ///< Number of elements in the array, if this is an array entry. Contains 1 for non-array data types.

    unsigned char *entry_data_addr;             ///< Pointer to the raw EXIF data for this entry.

    unsigned int entry_data_size;               ///< Number of bytes in the buffer at data. This must be no less than "exif_format_get_size(tag_format) * tag_counts".

} EXIF_ENTRY;



typedef struct EXIF_CONTENT_T
{
    EXIF_ENTRY *entry_array;                    ///< Entries array

    unsigned int entry_count;                   ///< Entries counts in this content. (Enabled entry number)

} EXIF_CONTENT;



// Represents the entire EXIF data found in an image
typedef struct EXIF_DATA_T
{
	EXIF_CONTENT ifd[EXIF_IFD_COUNT];           ///< Exif content data for each IFD

    STSMM exif_smm;                             ///< Simple memory manager structure for working buffer control.

	unsigned char *thumbnail_addr;              ///< Pointer to thumbnail image, or NULL if not available

	unsigned int thumbnail_size;                ///< Number of bytes in thumbnail image at data

    EXIF_BYTE_ORDER_ENUM byte_order;            ///< Byte order setting.

    EXIF_DATA_OPTION_ENUM option;               ///< Option. (Reserved now)

    unsigned char *dst_buffer_start_addr;       ///< Destination buffer start address.

    unsigned char *dst_buffer_ptr;              ///< Destination buffer pointer.

    unsigned int dst_buffer_left;               ///< Destination buffer size left.

} EXIF_DATA;



#endif  // End of #ifndef __EXIF_ENC_STRUCTURE_V2_H__
