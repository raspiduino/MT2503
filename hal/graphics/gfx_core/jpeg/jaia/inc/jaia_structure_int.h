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
 *   jaia_structure_int.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JAIA_STRUCTURE_INT_H__
#define __JAIA_STRUCTURE_INT_H__

#include "jaia_structure.h"
#include "jaia_enum.h"
#include "jpeg_encode_structure.h"
#include "jpeg_decode_structure.h"
#include "exif_enc_enum.h"
#include "exif_enc_structure.h"

#include "fsal.h"
#include "kal_general_types.h"
#include "simple_memory_manager.h"
 

typedef struct JAIA_WORKSPACE_T
{
    STFSAL *src_jpeg_fsal_handle;               ///< Source JPEG FSAL handle. For input.
    STFSAL *dst_jpeg_fsal_handle;               ///< Destination JPEG FSAL handle. For output.
    JAIA_BUFFER *dst_jpeg_file_buffer;          ///< Destination JPEG file buffer. For output.
    kal_uint32 dst_output_mode;                 ///< Destination output mode. Output to file or memory buffer.
    kal_uint32 jpeg_write_index;                ///< JPEG output index.

    STSMM workspace_mem_smm;                    ///< JAIA workspace SMM structure.

    STSMM int_mem_smm;                          ///< Internal memory SMM structure.
    JAIA_BUFFER int_working_buffer;             ///< Internal memory working buffer.

    STSMM ext_mem_smm;                          ///< External memory SMM structure.
    JAIA_BUFFER file_copy_buffer;               ///< Buffer for file copy. To speed up from source JPEG to destination JPEG.
    JAIA_BUFFER exif_buffer;                    ///< Exif encode output buffer.
    JAIA_BUFFER temporal_buffer;                ///< Temporal buffer.
    JAIA_BUFFER ext_working_buffer;             ///< External memory working buffer.

    JAIA_IMAGE_INFO temporal_image;             ///< Temporal image information.

    EXIF_DATA *exif_data;                       ///< Exif data structure pointer.
    JPEG_ENCODER_HANDLE jpeg_encode_handle;     ///< JPEG encode handle.
    JPEG_DECODER_HANDLE jpeg_decode_handle;     ///< JPEG decode handle.
    kal_uint32 jpeg_encode_int_mem_size;        ///< JPEG encode internal memory size.
    kal_uint32 jpeg_encode_ext_mem_size;        ///< JPEG encode external memory size.

    JAIA_EXIF_PROC_ENUM exif_proc_type;         ///< Exif process type.
    kal_uint32 exif_offset;                     ///< Exif information offset in original JPEG image.

    JAIA_IMAGE_INFO tn_src_image;               ///< Source image information of thumbnail.
    JAIA_TN_PROC_ENUM app0_tn_proc_type;        ///< Thumbnail process type of APP0. This is only for JFXX in JAIA.
    kal_uint32 app0_tn_offset;                  ///< APP0 thumbnail image offset in original JPEG image.
    JAIA_IMAGE_INFO app0_tn_dst_image;          ///< Destination image information of thumbnail for APP0.
    JAIA_TN_PROC_ENUM app1_tn_proc_type;        ///< Thumbnail process type of APP1. This is for Exif.
    kal_uint32 app1_tn_offset;                  ///< APP1 thumbnail image offset in original JPEG image.
    JAIA_IMAGE_INFO app1_tn_dst_image;          ///< Destination image information of thumbnail for APP1.

    JAIA_IMAGE_INFO qvi_src_image;              ///< Source image information of QVI.
    JAIA_QVI_PROC_ENUM qvi_proc_type;           ///< QVI process type.
    kal_uint32 qvi_offset;                      ///< QVI image offset in original JPEG image.
    kal_uint32 qvi_dst_offset;                  ///< QVI image offset in destination JPEG image.
    kal_uint32 qvi_marker_offset;               ///< QVI marker segment in destination JPEG image.
    JAIA_IMAGE_INFO qvi_dst_image;              ///< Destination image information of QVI.

    kal_uint32 main_jpeg_offset;                ///< Main JPEG image offset in original JPEG image.
    kal_uint32 main_jpeg_size;                  ///< Main JPEG image size in original JPEG image.
    kal_uint32 main_jpeg_width;                 ///< Main JPEG image width in original JPEG image.
    kal_uint32 main_jpeg_height;                ///< Main JPEG image height in original JPEG image.

    kal_int32 (*check_abort_func)(void);        ///< 

} JAIA_WORKSPACE;

typedef struct JAIA_WORKSPACE_T* JAIA_HANDLE;


#endif  /// End of #ifndef __JAIA_STRUCTURE_INT_H__

