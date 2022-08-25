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
 *   exif_enc_api.c
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
#if defined(__MTK_TARGET__)
   #include "kal_public_api.h"
   #include "string.h"
   
   #define malloc get_ctrl_buffer      ///< For exif v2 encoder.
   #define free   free_ctrl_buffer     ///< For exif v2 encoder.
#elif defined(WIN32)
   #include <stdlib.h>
   #include <stdio.h>
#endif

#include "exif_enc_enum.h"
#include "exif_enc_structure.h"
#include "exif_enc_entry.h"
#include "exif_enc_data.h"
#include "exif_enc_mem.h"
#include "exif_enc_utility.h"



#if defined(EXIF_SUPPORT)

EXIF_RETURN_STATUS_ENUM exifCreateDataStructure(EXIF_DATA **data_ptr, void *buff_addr, unsigned int buff_size)
{
    EXIF_RETURN_STATUS_ENUM ret_status;
    unsigned int mem_size;

    if ((NULL == data_ptr) || (NULL == buff_addr))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    /// Initial exif data structure handle.
    mem_size = sizeof(EXIF_DATA);
    *data_ptr = (EXIF_DATA *)malloc(mem_size);
    memset(*data_ptr, 0, mem_size);

    /// Initial exif memory. (simple memory manager)
    exif_mem_new(&(*data_ptr)->exif_smm, buff_addr, buff_size);

    /// Create exif data structure.
    ret_status = exif_data_new(*data_ptr, &(*data_ptr)->exif_smm);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifReleaseDataStructure(EXIF_DATA *data_ptr)
{
    free(data_ptr);

    return EXIF_RETURN_OK;
}



EXIF_RETURN_STATUS_ENUM exifSetDefaultData(EXIF_DATA *data_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    ret_status = exif_data_set_default(data_ptr);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifCreateEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if ((NULL == data_ptr) || (NULL == entry_ptr))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_create_entry(data_ptr, ifd, entry_ptr);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifAddEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if ((NULL == data_ptr) || (NULL == entry_ptr))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_add_entry(data_ptr, ifd, entry_ptr);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifRemoveEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_remove_entry(data_ptr, ifd, tag_id);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifRemoveAllEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_remove_all_entry(data_ptr, ifd);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifGetEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if ((NULL == data_ptr) || (NULL == entry_ptr))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_get_entry(data_ptr, ifd, tag_id, entry_ptr);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifGetTagCountInIfd(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int *ifd_count)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if ((NULL == data_ptr) || (NULL == ifd_count))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_get_tag_count_in_ifd(data_ptr, ifd, ifd_count);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifGetEntryByIndex(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int index, EXIF_ENTRY *entry_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (ifd >= EXIF_IFD_COUNT)
    {
        return EXIF_RETURN_OVER_MAX_IFD_LIMIT;
    }

    ret_status = exif_data_get_entry_by_index(data_ptr, ifd, index, entry_ptr);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifSaveEncodedData(EXIF_DATA *data_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (NULL == data_ptr->dst_buffer_start_addr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (NULL == data_ptr->dst_buffer_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    if (0 == data_ptr->dst_buffer_left)
    {
        return EXIF_RETURN_INSUFFICIENT_MEMORY;
    }

    ret_status = exif_data_save_encoded_data(data_ptr);

    return ret_status;
}



unsigned int exifGetTotalEncodedDataLength(EXIF_DATA *data_ptr)
{
    unsigned int data_length;

    if (NULL == data_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    data_length = exif_data_get_total_encoded_length(data_ptr);

    return data_length;
}



EXIF_RETURN_STATUS_ENUM exifSetEntryInfo(EXIF_ENTRY *entry_ptr, unsigned short tag_id, EXIF_TAG_FORMAT_ENUM tag_format, unsigned int tag_counts, unsigned int entry_data_size)
{
    EXIF_RETURN_STATUS_ENUM ret_status;

    if (NULL == entry_ptr)
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    ret_status = exif_entry_set_entry_info(entry_ptr, tag_id, tag_format, tag_counts, entry_data_size);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM exifSetDstBuffer(EXIF_DATA *data_ptr, unsigned char *dst_buffer_addr, unsigned int dst_buffer_size)
{
    if ((NULL == data_ptr) || (NULL == dst_buffer_addr))
    {
        return EXIF_RETURN_INVALID_POINTER;
    }

    data_ptr->dst_buffer_start_addr = dst_buffer_addr;
    data_ptr->dst_buffer_ptr = dst_buffer_addr;
    data_ptr->dst_buffer_left = dst_buffer_size;

    return EXIF_RETURN_OK;
}



unsigned int exifGetWorkingMemorySize(void)
{
    return exif_data_get_working_memory_size();
}



void exifSetSshort(unsigned char *buffer_addr, EXIF_SSHORT_T value)
{
    exif_set_sshort(buffer_addr, EXIF_BYTE_ORDER_LITTLE_ENDIAN, value);
}



void exifSetShort(unsigned char *buffer_addr, EXIF_SHORT_T value)
{
    exif_set_short(buffer_addr, EXIF_BYTE_ORDER_LITTLE_ENDIAN, value);
}



void exifSetSlong(unsigned char *buffer_addr, EXIF_SLONG_T value)
{
    exif_set_slong(buffer_addr, EXIF_BYTE_ORDER_LITTLE_ENDIAN, value);
}



void exifSetLong(unsigned char *buffer_addr, EXIF_LONG_T value)
{
    exif_set_long(buffer_addr, EXIF_BYTE_ORDER_LITTLE_ENDIAN, value);
}



void exifSetRational(unsigned char *buffer_addr, EXIF_RATIONAL_T value)
{
    exif_set_rational(buffer_addr, EXIF_BYTE_ORDER_LITTLE_ENDIAN, value);
}



#else

EXIF_RETURN_STATUS_ENUM exifCreateDataStructure(EXIF_DATA **data_ptr, void *buff_addr, unsigned int buff_size)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifReleaseDataStructure(EXIF_DATA *data_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifSetDefaultData(EXIF_DATA *data_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifCreateEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifAddEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifRemoveEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifRemoveAllEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifGetEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifGetTagCountInIfd(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int *ifd_count)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifGetEntryByIndex(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int index, EXIF_ENTRY *entry_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifSaveEncodedData(EXIF_DATA *data_ptr)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



unsigned int exifGetTotalEncodedDataLength(EXIF_DATA *data_ptr)
{
    return 0;
}



EXIF_RETURN_STATUS_ENUM exifSetEntryInfo(EXIF_ENTRY *entry_ptr, unsigned short tag_id, EXIF_TAG_FORMAT_ENUM tag_format, unsigned int tag_counts, unsigned int entry_data_size)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



EXIF_RETURN_STATUS_ENUM exifSetDstBuffer(EXIF_DATA *data_ptr, unsigned char *dst_buffer_addr, unsigned int dst_buffer_size)
{
    return EXIF_RETURN_UNSUPPORT_EXIF;
}



unsigned int exifGetWorkingMemorySize(void)
{
    return 0;
}



void exifSetSshort(unsigned char *buffer_addr, EXIF_SSHORT_T value)
{
}



void exifSetShort(unsigned char *buffer_addr, EXIF_SHORT_T value)
{
}



void exifSetSlong(unsigned char *buffer_addr, EXIF_SLONG_T value)
{
}



void exifSetLong(unsigned char *buffer_addr, EXIF_LONG_T value)
{
}



void exifSetRational(unsigned char *buffer_addr, EXIF_RATIONAL_T value)
{
}

#endif // #if defined(EXIF_SUPPORT)

