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
 *   jaia_api.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JAIA_API_H__
#define __JAIA_API_H__

#include "exif_enc_enum.h"
#include "exif_enc_structure.h"
#include "jaia_structure.h"
#include "jaia_enum.h"

#include "kal_general_types.h"
#include "fsal.h"

 
typedef struct JAIA_WORKSPACE_T* JAIA_HANDLE;

/**
 * @brief                       Query JAIA workspace buffer needed.
 * @param wb_size               Mininum workspace buffer needed. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process] User should run this API before create JAIA workspace to get minimum workspace buffer needed.
 */
JAIA_RETURN_STATUS_ENUM jaiaQueryWorkspaceBuffer(kal_uint32 *wb_size);



/**
 * @brief                       Create a JAIA workspace with a workspace buffer.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param workspace_buffer      Workspace buffer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaCreateWorkspace(JAIA_HANDLE *jaia_workspace, JAIA_BUFFER *workspace_buffer);



/**
 * @brief                       Set source FSAL file handle(original JPEG image) and run pre-processing.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param file_handle           JPEG file FSAL handle.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaSetSourceFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle);



/**
 * @brief                       Get original JPEG image's resolution.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param image_width           Image width. For return.
 * @param image_height          Image height. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process] Run this function after jaiaSetSourceFile().
 */
JAIA_RETURN_STATUS_ENUM jaiaGetSourceImageResolution(JAIA_HANDLE jaia_workspace, kal_uint32 *image_width, kal_uint32 *image_height);



/**
 * @brief                       Release JAIA workspace.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaReleaseWorkspace(JAIA_HANDLE jaia_workspace);



/**
 * @brief                       Set destination file handle to JAIA workspace.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param file_handle           Destination FSAL file handle.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaSetDestinationFile(JAIA_HANDLE jaia_workspace, STFSAL *file_handle);



/**
 * @brief                       Set destination file buffer to JAIA workspace.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param file_buffer           Destination FSAL file handle.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaSetDestinationBuffer(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *file_buffer);



/**
 * @brief                       Query working memory.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param int_mem_size          Internal memory size. For return.
 * @param ext_mem_size          External memory size. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process] Please do query/set memory between all configuration done and jaiaStart().
 */
JAIA_RETURN_STATUS_ENUM jaiaQueryWorkingMemory(JAIA_HANDLE jaia_workspace, kal_uint32 *int_mem_size, kal_uint32 *ext_mem_size);



/**
 * @brief                       Set working memory.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param int_working_mem       Internal memory address and size.
 * @param ext_working_mem       External memory address and size.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process] Please do query/set memory between all configuration done and jaiaStart().
 */
JAIA_RETURN_STATUS_ENUM jaiaSetWorkingMemory(JAIA_HANDLE jaia_workspace, JAIA_BUFFER *int_working_mem, JAIA_BUFFER *ext_working_mem);



/**
 * @brief                       Start all action of JAIA.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaStart(JAIA_HANDLE jaia_workspace);



/**
 * @brief                       
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetResult(JAIA_HANDLE jaia_workspace, void **jpeg_start_addr, kal_uint32 *jpeg_size);



/**
 * @brief                       Remove exif information.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaRemoveExif(JAIA_HANDLE jaia_workspace);



/**
 * @brief                       Get tag counts in IFD.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   Ifd ID we want to get its tag count.
 * @param ifd_count             Ifd count. return to caller.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetTagCountInIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 *ifd_count);



/**
 * @brief                       Get an exif entry information from the jaia data structure by order number.
 *                              In this function, it will get the entry information and put it into entry_ptr.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   IFD for which we get entry information from it.
 * @param index                 Order number for which we want to get entry information.
 * @param entry_ptr             Pointer to the entry information we obtain from exif data structure.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetExifEntryByIndex(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, kal_uint32 index, EXIF_ENTRY *entry_ptr);



/**
 * @brief                       Add an exif entry and hook on the jaia data structure by using the input exif entry.
 *                              In this function, it will attach the input exif entry into exif data structure.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   Assign ifd for which we want to hook on it.
 * @param entry_ptr             Exif entry which carries tag_id, tag_counts, tag_format and entry data size.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process] entry_ptr can not free until jaia workspace released.
 */
JAIA_RETURN_STATUS_ENUM jaiaAddExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr);



/**
 * @brief                       Get an exif entry information from the jaia data structure by selected tag_id.
 *                              In this function, it will get the entry information and put it into entry_ptr.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   IFD for which we get entry information from it.
 * @param tag_id                Tag ID for which we want to get its information.
 * @param entry_ptr             Pointer to the entry information we get back from exif data structure.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr);



/**
 * @brief                       Remove an exif entry from the jaia data structure by selected tag_id.
 *                              In this function, it will remove all same tag_id in the selected IFD such as duplicated.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   Assign ifd for which we want to remove from it.
 * @param tag_id                Tag ID for which we want to remove.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaRemoveExifEntry(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd, unsigned short tag_id);



/**
 * @brief                       Remove all exif entries of selected IFD from the jaia data structure.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param ifd                   Assign ifd for which we want to remove all entries from it.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaRemoveExifIfd(JAIA_HANDLE jaia_workspace, EXIF_IFD_ENUM ifd);



/**
 * @brief                       Add thumbnail from input source image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param tn_src_image_info     Thumbnail's source image information.
 * @param tn_dst_image_width    Thumbnail's destination image width.
 * @param tn_dst_image_height   Thumbnail's destination image height.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaAddThumbnail(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *tn_src_image_info, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height);



/**
 * @brief                       Create thumbnail from decoding original JPEG image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param tn_dst_image_width    Thumbnail's destination image width.
 * @param tn_dst_image_height   Thumbnail's destination image height.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaCreateThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 tn_dst_image_width, kal_uint32 tn_dst_image_height);



/**
 * @brief                       Remove JFXX and exif thumbnail from original JPEG image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaRemoveThumbnail(JAIA_HANDLE jaia_workspace);



/**
 * @brief                       Get thumbnail resolution by auto calculating.
 * @param src_image_width       Source image width. Source image is the original JPEG image.
 * @param src_image_height      Source image height. Source image is the original JPEG image.
 * @param dst_image_width       Destination image width. For return. (Thumbnail's width)
 * @param dst_image_height      Destination image height. For return. (Thumbnail's height)
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetRecommendThumbnailResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                            kal_uint32 *dst_image_width, kal_uint32 *dst_image_height);



/**
 * @brief                       Get JFXX thumbnail information.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param thumbnail_type        Thumbnail type (Compressed or uncompressed). For return.
 * @param thumbnail_offset      Thumbnail offset in JPEG file. For return.
 * @param thumbnail_size        Thumbnail size. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetJFXXThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size);



/**
 * @brief                       Get exif thumbnail information.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param thumbnail_type        Thumbnail type (Compressed or uncompressed). For return.
 * @param thumbnail_offset      Thumbnail offset in JPEG file. For return.
 * @param thumbnail_size        Thumbnail size. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetExifThumbnail(JAIA_HANDLE jaia_workspace, kal_uint32 *thumbnail_type, kal_uint32 *thumbnail_offset, kal_uint32 *thumbnail_size);



/**
 * @brief                       Add QVI from user input source image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param qvi_src_image_info    QVI's source image information.
 * @param qvi_dst_image_width   QVI's destination image width.
 * @param qvi_dst_image_height  QVI's destination image height.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaAddQVI(JAIA_HANDLE jaia_workspace, JAIA_IMAGE_INFO *qvi_src_image_info, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height);



/**
 * @brief                       Create QVI from decoding original JPEG image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param qvi_dst_image_width   QVI's destination image width.
 * @param qvi_dst_image_height  QVI's destination image height.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaCreateQVI(JAIA_HANDLE jaia_workspace, kal_uint32 qvi_dst_image_width, kal_uint32 qvi_dst_image_height);



/**
 * @brief                       Remove QVI from original JPEG image.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaRemoveQVI(JAIA_HANDLE jaia_workspace);



/**
 * @brief                       Get QVI information.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param qvi_offset            QVI image information. For return.
 * @param qvi_size              QVI image information. For return.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetQVI(JAIA_HANDLE jaia_workspace, kal_uint32 *qvi_offset, kal_uint32 *qvi_size);



/**
 * @brief                       Get recommand QVI resolution by auto calculating.
 * @param src_image_width       Source image width. Source image is the original JPEG image.
 * @param src_image_height      Source image height. Source image is the original JPEG image.
 * @param display_width         Display width. (Target width)
 * @param display_height        Display height. (Target height)
 * @param dst_image_width       Destination image width. For return. (QVI's width)
 * @param dst_image_height      Destination image height. For return. (QVI's height)
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaGetRecommendQVIResolution(kal_uint32 src_image_width, kal_uint32 src_image_height,
                                                      kal_uint32 display_width, kal_uint32 display_height,
                                                      kal_uint32 *dst_image_width, kal_uint32 *dst_image_height);



/**
 * @brief                       Set the check-abort function.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @param check_abort_func      The check abort function
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Optional in JAIA Process]
 *                              The check-abort function will be invoked during jaia action process.
 *                              If the check abort function returns non-zero value, the JAIA process will be aborted.
 */
JAIA_RETURN_STATUS_ENUM jaiaSetCheckAbortFunction(JAIA_HANDLE jaia_workspace, kal_int32 (*check_abort_func)(void));



/**
 * @brief                       Update all exif legacy entry of JAIA.
 * @param jaia_workspace        JAIA workspace data structure pointer.
 * @return                      If the function succeeds, the return value is JAIA_RETURN_OK; otherwise the error code is returned.
 * @remarks                     [Mandatory in JAIA Process]
 */
JAIA_RETURN_STATUS_ENUM jaiaUpdateAllExifEntry(JAIA_HANDLE jaia_workspace);



#endif  /// End of #ifndef __JAIA_API_H__
