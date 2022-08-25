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
 *   jaia_int.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JAIA_INT_H__
#define __JAIA_INT_H__

#include "jaia_structure_int.h"
#include "jaia_structure.h"
#include "jaia_enum.h"

#include "fsal.h"
#include "kal_general_types.h"


#define JAIA_INT_MEM_ALIGN  4
#define JAIA_EXT_MEM_ALIGN  32
#define JAIA_ALIGN(n, byte)  (((n) + ((byte)-1)) & (~((byte) - 1)))
#define JAIA_MAX(a, b)  (((a) >= (b))?(a):(b))



JAIA_RETURN_STATUS_ENUM jaia_create_workspace(JAIA_HANDLE *jaia_workspace, JAIA_BUFFER *workspace_buffer);
JAIA_RETURN_STATUS_ENUM jaia_create_workspace_with_fsal_handle(JAIA_HANDLE *jaia_workspace, STFSAL *file_handle, JAIA_BUFFER *init_buffer);

JAIA_RETURN_STATUS_ENUM jaia_set_source_file(JAIA_HANDLE jaia_workspace, STFSAL *file_handle);
JAIA_RETURN_STATUS_ENUM jaia_release_workspace(JAIA_HANDLE jaia_workspace);
JAIA_RETURN_STATUS_ENUM jaia_start_with_exif(JAIA_HANDLE jaia_workspace);
JAIA_RETURN_STATUS_ENUM jaia_start_with_jfxx(JAIA_HANDLE jaia_workspace);
JAIA_RETURN_STATUS_ENUM jaia_prepare_to_query_working_memory(JAIA_HANDLE jaia_workspace);
JAIA_RETURN_STATUS_ENUM jaia_query_working_memory(JAIA_HANDLE jaia_workspace, unsigned int *int_mem_size, unsigned int *ext_mem_size);
JAIA_RETURN_STATUS_ENUM jaia_set_working_memory(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *int_working_mem, JAIA_BUFFER *ext_working_mem);

JAIA_RETURN_STATUS_ENUM jaia_query_encode_working_memory(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *encode_src_image_info, JAIA_IMAGE_INFO *encode_dst_image_info);
JAIA_RETURN_STATUS_ENUM jaia_encode_dst_jpeg_image(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *encode_src_image_info, JAIA_IMAGE_INFO *encode_dst_image_info);

JAIA_RETURN_STATUS_ENUM jaia_get_recommand_resolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                      kal_uint32 target_image_width, kal_uint32 target_image_height,
                                                      kal_uint32 *dst_image_width, kal_uint32 *dst_image_height);


#endif  /// End of #ifndef __JAIA_INT_H__
