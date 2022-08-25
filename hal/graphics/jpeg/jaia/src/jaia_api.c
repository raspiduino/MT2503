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
 *   jaia_api.c
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
#ifdef WIN32
#include <stdio.h>
#endif

#include "drv_features_jpeg.h"
#include "jpeg_decode_api.h"
#include "jpeg_mem_int.h"
#include "jpeg_enum.h"
#include "jpeg_decode_structure.h"

#include "kal_general_types.h"
#include "fsal.h"

#include "exif_enc_tag.h"
#include "exif_enc_api.h"
#include "exif_enc_enum.h"
#include "exif_enc_structure.h"

#include "jaia_enum.h"
#include "jaia_structure.h"
#include "jaia_structure_int.h"
#include "jaia_int.h"
#include "jaia_mem.h"
#include "jaia_tn.h"
#include "jaia_qvi.h"
#include "jaia_exif.h"
#include "jaia_api.h"
 

#if defined(__JAIA_SUPPORT__)

JAIA_RETURN_STATUS_ENUM jaiaQueryWorkspaceBuffer(kal_uint32 *wb_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;
    kal_uint32 read_buffer_size = 0;
    kal_uint32 fsal_buffer_size = 0;
    kal_uint32 exif_working_memory_size = 0;

    if (NULL == wb_size)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    // need jpg decode handle only
    fsal_buffer_size = JPEG_DEC_FSAL_CACHE_SIZE + EXIF_APP1_INFO_STRUCTURE_MEM_SIZE;

#if defined(EXIF_SUPPORT)
    exif_working_memory_size = JAIA_EXIF_BUF_SIZE;
#endif
    *wb_size = 32 + sizeof(JAIA_WORKSPACE) + JAIA_TEMP_BUF_SIZE + exif_working_memory_size + read_buffer_size + fsal_buffer_size;

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateWorkspace(JAIA_HANDLE *jaia_workspace, JAIA_BUFFER *workspace_buffer)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if ((NULL == workspace_buffer->buff_addr) || (0 == workspace_buffer->buff_size))
    {
        return JAIA_BUFFER_INSUFFICIENT_MEMORY;
    }

    ret_status = jaia_create_workspace(jaia_workspace, workspace_buffer);

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaSetSourceFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;
#if defined(EXIF_SUPPORT)
    EXIF_RETURN_STATUS_ENUM ret_status_exif;
    kal_uint32 best_size_0;
    void *buffer_addr_0;
#endif

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    ret_status = jaia_set_source_file(jaia_workspace, file_handle);
    if (JAIA_RETURN_OK != ret_status)
    {
        return ret_status;
    }

#if defined(EXIF_SUPPORT)
    /// Create exif data structure.
    best_size_0 = JAIA_EXIF_BUF_SIZE;
    buffer_addr_0 = (void *)smmMallocAligned(&jaia_workspace->workspace_mem_smm, best_size_0, 4);

    ret_status_exif = exifCreateDataStructure(&jaia_workspace->exif_data, buffer_addr_0, best_size_0);
    if (JPEG_STATUS_OK != ret_status_exif)
    {
        return JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL;
    }
    
    /// Update exif information to JAIA workspace from JPEG parser.
    ret_status = jaia_exif_update_exif_info_from_parser(jaia_workspace);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetSourceImageResolution(JAIA_HANDLE jaia_workspace, kal_uint32 *image_width, kal_uint32 *image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    *image_width = jaia_workspace->main_jpeg_width;
    *image_height = jaia_workspace->main_jpeg_height;

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaReleaseWorkspace(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

#if defined(EXIF_SUPPORT)
    if (jaia_workspace->exif_data)
    {
       exifReleaseDataStructure(jaia_workspace->exif_data);
    }
#endif

    ret_status = jaia_release_workspace(jaia_workspace);

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaSetDestinationFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    jaia_workspace->dst_output_mode = JAIA_OUTPUT_TO_FILE;
    jaia_workspace->dst_jpeg_fsal_handle = file_handle;

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaSetDestinationBuffer(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *file_buffer)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    jaia_workspace->dst_output_mode = JAIA_OUTPUT_TO_MEMORY;
    jaia_workspace->dst_jpeg_file_buffer = file_buffer;

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExif(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    jaia_workspace->exif_proc_type = JAIA_EXIF_PROC_NO_EXIF;
    ret_status = JAIA_RETURN_OK;
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetTagCountInIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 *ifd_count)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifGetTagCountInIfd(jaia_workspace->exif_data, ifd, ifd_count))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_GET_EXIF_ENTRY_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifEntryByIndex(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 index, EXIF_ENTRY *entry_ptr)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifGetEntryByIndex(jaia_workspace->exif_data, ifd, index, entry_ptr))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_GET_EXIF_ENTRY_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaAddExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifAddEntry(jaia_workspace->exif_data, ifd, entry_ptr))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_OUTPUT_EXIF_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifGetEntry(jaia_workspace->exif_data, ifd, tag_id, entry_ptr))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_GET_EXIF_ENTRY_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifRemoveEntry(jaia_workspace->exif_data, ifd, tag_id))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_OUTPUT_EXIF_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExifIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (EXIF_RETURN_OK == exifRemoveAllEntry(jaia_workspace->exif_data, ifd))
    {
       ret_status = JAIA_RETURN_OK;
    }
    else
    {
       ret_status = JAIA_RETURN_OUTPUT_EXIF_FAIL;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaAddThumbnail(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *tn_src_image_info, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if ((tn_dst_image_width > jaia_workspace->main_jpeg_width) || (tn_dst_image_height > jaia_workspace->main_jpeg_height) ||
        (tn_dst_image_width < 16) || (tn_dst_image_height < 16))
    {
        return JAIA_RETURN_INVALID_TN_RESOLUTION;
    }

    ret_status = jaia_tn_add(jaia_workspace, tn_src_image_info, tn_dst_image_width, tn_dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if ((tn_dst_image_width > jaia_workspace->main_jpeg_width) || (tn_dst_image_height > jaia_workspace->main_jpeg_height) ||
        (tn_dst_image_width < 16) || (tn_dst_image_height < 16))
    {
        return JAIA_RETURN_INVALID_TN_RESOLUTION;
    }

    ret_status = jaia_tn_create(jaia_workspace, tn_dst_image_width, tn_dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveThumbnail(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    ret_status = jaia_tn_remove(jaia_workspace);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetRecommendThumbnailResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                            kal_uint32 *dst_image_width, kal_uint32 *dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if ((NULL == dst_image_width) || (NULL == dst_image_height))
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    ret_status = jaia_get_recommand_resolution(src_image_width, src_image_height, 160, 120, dst_image_width, dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetJFXXThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if ((NULL == jaia_workspace) || (NULL == thumbnail_type) || (NULL == thumbnail_offset) || (NULL == thumbnail_size))
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    *thumbnail_type = jaia_workspace->app1_tn_dst_image.type;
    *thumbnail_offset = jaia_workspace->app1_tn_offset;
    *thumbnail_size = jaia_workspace->app1_tn_dst_image.size;
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_THUMBNAIL;

#if defined(EXIF_SUPPORT)
   #if defined(__JPEG_THUMBNAIL_SUPPORT__)
    if ((NULL == jaia_workspace) || (NULL == thumbnail_type) || (NULL == thumbnail_offset) || (NULL == thumbnail_size))
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    *thumbnail_type = jaia_workspace->app1_tn_dst_image.type;
    *thumbnail_offset = jaia_workspace->app1_tn_offset;
    *thumbnail_size = jaia_workspace->app1_tn_dst_image.size;
    ret_status = JAIA_RETURN_OK;
#endif
#else
   ret_status = JAIA_RETURN_UNSUPPORT_EXIF;
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaAddQVI(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *qvi_src_image_info, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_QVI;

#if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if ((qvi_dst_image_width > jaia_workspace->main_jpeg_width) || (qvi_dst_image_height > jaia_workspace->main_jpeg_height) ||
        (qvi_dst_image_width < 16) || (qvi_dst_image_height < 16))
    {
        return JAIA_RETURN_INVALID_QVI_RESOLUTION;
    }

    ret_status = jaia_qvi_add(jaia_workspace, qvi_src_image_info, qvi_dst_image_width, qvi_dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateQVI(JAIA_HANDLE jaia_workspace, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_QVI;

#if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if ((qvi_dst_image_width > jaia_workspace->main_jpeg_width) || (qvi_dst_image_height > jaia_workspace->main_jpeg_height) ||
        (qvi_dst_image_width < 16) || (qvi_dst_image_height < 16))
    {
        return JAIA_RETURN_INVALID_QVI_RESOLUTION;
    }

    ret_status = jaia_qvi_create(jaia_workspace, qvi_dst_image_width, qvi_dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveQVI(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_QVI;

#if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    ret_status = jaia_qvi_remove(jaia_workspace);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetQVI(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_QVI;

#if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
    if ((NULL == jaia_workspace) || (NULL == thumbnail_offset) || (NULL == thumbnail_size))
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    *thumbnail_offset = jaia_workspace->qvi_offset;
    *thumbnail_size = jaia_workspace->qvi_dst_image.size;
    ret_status = JAIA_RETURN_OK;
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetRecommendQVIResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                      kal_uint32 display_width, kal_uint32 display_height,
                                                      kal_uint32 *dst_image_width, kal_uint32 *dst_image_height)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_QVI;

#if defined(__JPEG_QUICK_VIEW_IMAGE_SUPPORT__)
    ret_status = jaia_get_recommand_resolution(src_image_width, src_image_height, display_width, display_height, dst_image_width, dst_image_height);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaQueryWorkingMemory(JAIA_HANDLE jaia_workspace, kal_uint32 *int_mem_size, kal_uint32 *ext_mem_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;
#if defined(EXIF_SUPPORT)
    EXIF_RETURN_STATUS_ENUM ret_status_exif = EXIF_RETURN_OK;
    EXIF_ENTRY exif_entry;
#endif

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

#if defined(EXIF_SUPPORT)
    if (JAIA_EXIF_PROC_EXIF_WITH_JPEG_TNUMBNAIL == jaia_workspace->exif_proc_type)
    {
        if ((JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_PARSING != jaia_workspace->app1_tn_proc_type) && (JAIA_TN_PROC_UNCOMPRESSED_THUMBNAIL_FROM_PARSING != jaia_workspace->app1_tn_proc_type))
        {
            /// Create necessary exif tags for JPEG thumbnail.
            exifSetEntryInfo(&exif_entry, EXIF_TAG_EXIF_IFD_POINTER, EXIF_FORMAT_LONG, 1, 4);
            ret_status_exif = exifCreateEntry(jaia_workspace->exif_data, EXIF_IFD_0, &exif_entry);
            if (EXIF_RETURN_OK != ret_status_exif)
            {
                return JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL;
            }

            exifSetEntryInfo(&exif_entry, EXIF_TAG_COMPRESSION, EXIF_FORMAT_SHORT, 1, 2);
            ret_status_exif = exifCreateEntry(jaia_workspace->exif_data, EXIF_IFD_1, &exif_entry);
            if (EXIF_RETURN_OK != ret_status_exif)
            {
                return JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL;
            }

            exifSetEntryInfo(&exif_entry, EXIF_TAG_JPEG_INTERCHANGE_FORMAT, EXIF_FORMAT_LONG, 1, 4);
            ret_status_exif = exifCreateEntry(jaia_workspace->exif_data, EXIF_IFD_1, &exif_entry);
            if (EXIF_RETURN_OK != ret_status_exif)
            {
                return JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL;
            }

            exifSetEntryInfo(&exif_entry, EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH, EXIF_FORMAT_LONG, 1, 4);
            ret_status_exif = exifCreateEntry(jaia_workspace->exif_data, EXIF_IFD_1, &exif_entry);
            if (EXIF_RETURN_OK != ret_status_exif)
            {
                return JAIA_RETURN_CREATE_EXIF_ENTRY_FAIL;
            }
        }
    }

    /// For parsing process, JAIA do not assign thumbnail size again.
    if ((JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_PARSING != jaia_workspace->app1_tn_proc_type) && (JAIA_TN_PROC_UNCOMPRESSED_THUMBNAIL_FROM_PARSING != jaia_workspace->app1_tn_proc_type))
    {
        jaia_workspace->exif_data->thumbnail_size = 0;
    }

    /// For user provided JPEG thumbnail process.
    if (JAIA_TN_PROC_JPEG_THUMBNAIL_FROM_USER_PROVIDE == jaia_workspace->app1_tn_proc_type)
    {
        kal_uint32 exif_size = 0;

        exif_size = exifGetTotalEncodedDataLength(jaia_workspace->exif_data) - jaia_workspace->exif_data->thumbnail_size;

        /// APP1 can not larger than 64K bytes.
        if (0xFFFF < (exif_size + jaia_workspace->tn_src_image.size))
        {
            return JAIA_RETURN_EXIF_SEGMENT_OVERFLOW;
        }

        jaia_workspace->app1_tn_dst_image = jaia_workspace->tn_src_image;
        jaia_workspace->exif_data->thumbnail_size = jaia_workspace->app1_tn_dst_image.size;
    }
#endif

    ret_status = jaia_prepare_to_query_working_memory(jaia_workspace);
    if (JAIA_RETURN_OK != ret_status)
    {
        return ret_status;
    }

    ret_status = jaia_query_working_memory(jaia_workspace, int_mem_size, ext_mem_size);
    if (JAIA_RETURN_OK != ret_status)
    {
        return ret_status;
    }

#if defined(EXIF_SUPPORT)
    /// Exif output buffer.
    if (JAIA_EXIF_PROC_NO_EXIF != jaia_workspace->exif_proc_type)
    {
        *ext_mem_size += exifGetTotalEncodedDataLength(jaia_workspace->exif_data) - jaia_workspace->exif_data->thumbnail_size;
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaSetWorkingMemory(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *int_working_mem, JAIA_BUFFER *ext_working_mem)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    ret_status = jaia_set_working_memory(jaia_workspace, int_working_mem, ext_working_mem);

#if defined(EXIF_SUPPORT)
    /// Exif output buffer.
    if (JAIA_EXIF_PROC_NO_EXIF != jaia_workspace->exif_proc_type)
    {
        jaia_workspace->exif_buffer.buff_size = exifGetTotalEncodedDataLength(jaia_workspace->exif_data) - jaia_workspace->exif_data->thumbnail_size;
        // Prepare EXIF buffer from smm
        jaia_workspace->exif_buffer.buff_addr = smmMallocAligned(&jaia_workspace->ext_mem_smm, jaia_workspace->exif_buffer.buff_size, JAIA_INT_MEM_ALIGN);
    }
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaStart(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

#if defined(EXIF_SUPPORT)
    ret_status = jaia_start_with_exif(jaia_workspace);
#else
    ret_status = jaia_start_with_jfxx(jaia_workspace);
#endif

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaGetResult(JAIA_HANDLE jaia_workspace, void **jpeg_start_addr, kal_uint32 *jpeg_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    *jpeg_start_addr = (void *)jaia_workspace->dst_jpeg_file_buffer->buff_addr;
    *jpeg_size = jaia_workspace->jpeg_write_index;

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaSetCheckAbortFunction(JAIA_HANDLE jaia_workspace, kal_int32 (*check_abort_func)(void))
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;

    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    if (check_abort_func)
    {
        jaia_workspace->check_abort_func = check_abort_func;
    }

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaiaUpdateAllExifEntry(JAIA_HANDLE jaia_workspace)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_UNSUPPORT_EXIF;

#if defined(EXIF_SUPPORT)
    if (NULL == jaia_workspace)
    {
        return JAIA_RETURN_INVALID_POINTER;
    }

    exifWrapperConvertAllLegacyIFD(jaia_workspace->exif_data);
#endif

    return ret_status;
}

#else

JAIA_RETURN_STATUS_ENUM jaiaQueryWorkspaceBuffer(kal_uint32 *wb_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateWorkspace(JAIA_HANDLE *jaia_workspace, JAIA_BUFFER *workspace_buffer)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaSetSourceFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetSourceImageResolution(JAIA_HANDLE jaia_workspace, kal_uint32 *image_width, kal_uint32 *image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaReleaseWorkspace(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaSetDestinationFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaSetDestinationBuffer(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *file_buffer)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExif(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetTagCountInIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 *ifd_count)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifEntryByIndex(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 index, EXIF_ENTRY *entry_ptr)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaAddExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveExifIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaAddThumbnail(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *tn_src_image_info, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveThumbnail(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetRecommendThumbnailResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                            kal_uint32 *dst_image_width, kal_uint32 *dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetJFXXThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetExifThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaAddQVI(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *qvi_src_image_info, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaCreateQVI(JAIA_HANDLE jaia_workspace, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaRemoveQVI(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetQVI(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetRecommendQVIResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                      kal_uint32 display_width, kal_uint32 display_height,
                                                      kal_uint32 *dst_image_width, kal_uint32 *dst_image_height)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaQueryWorkingMemory(JAIA_HANDLE jaia_workspace, kal_uint32 *int_mem_size, kal_uint32 *ext_mem_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaSetWorkingMemory(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *int_working_mem, JAIA_BUFFER *ext_working_mem)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaStart(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaGetResult(JAIA_HANDLE jaia_workspace, void **jpeg_start_addr, kal_uint32 *jpeg_size)
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaSetCheckAbortFunction(JAIA_HANDLE jaia_workspace, kal_int32 (*check_abort_func)(void))
{
    return JAIA_RETURN_UNSUPPORTED;
}



JAIA_RETURN_STATUS_ENUM jaiaUpdateAllExifEntry(JAIA_HANDLE jaia_workspace)
{
    return JAIA_RETURN_UNSUPPORTED;
}
#endif

