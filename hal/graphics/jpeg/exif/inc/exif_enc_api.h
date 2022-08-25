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
 *   exif_enc_api.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_ENC_API_V2_H__
#define __EXIF_ENC_API_V2_H__

#include "exif_enc_enum.h"
#include "exif_enc_structure.h"


/**
 * @brief                   Create exif data structure.
 * @param data_ptr          EXIF_DATA pointer. Created by caller and can not be NULL.
 * @param buff_addr         Working buffer address.
 * @param buff_size         Working buffer size.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifCreateDataStructure(EXIF_DATA **data_ptr, void *buff_addr, unsigned int buff_size);



/**
 * @brief                   Release exif data structure.
 * @param data_ptr          EXIF_DATA pointer.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifReleaseDataStructure(EXIF_DATA *data_ptr);



/**
 * @brief                   Set exif data structure by default selected tags.
 * @param data_ptr          Exif data structure pointer.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifSetDefaultData(EXIF_DATA *data_ptr);



/**
 * @brief                   Create an exif entry and hook on the exif data structure by using the input exif entry information.
 *                          In this function, it will create the entry data buffer by using working buffer.
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               Assign ifd for which we want to hook on it.
 * @param entry_ptr         Exif entry which carries tag_id, tag_counts, tag_format and entry data size.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifCreateEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr);



/**
 * @brief                   Add an exif entry and hook on the exif data structure by using the input exif entry.
 *                          In this function, it will attach the input exif entry buffer into exif data structure.
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               Assign ifd for which we want to hook on it.
 * @param entry_ptr         Exif entry which carries tag_id, tag_counts, tag_format and entry data size.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifAddEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr);



/**
 * @brief                   Remove an exif entry from the exif data structure by selected tag_id.
 *                          In this function, it will remove all same tag_id in the selected IFD such as duplicated.
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               Assign ifd for which we want to remove from it.
 * @param tag_id            Tag ID for which we want to remove.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifRemoveEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id);



/**
 * @brief                   Remove all exif entries of selected IFD from the exif data structure.
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               Assign ifd for which we want to remove all entries from it.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifRemoveAllEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd);



/**
 * @brief                   Get an exif entry information from the exif data structure by selected tag_id.
 *                          In this function, it will get the entry information and put it into entry_ptr.
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               IFD for which we get entry information from it.
 * @param tag_id            Tag ID for which we want to get its information.
 * @param entry_ptr         Pointer to the entry information we get back from exif data structure.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifGetEntry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr);



/**
 * @brief                   
 *                          
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               IFD for which we get entry information from it.
 * @param ifd_count         Pointer to the entry information we get back from exif data structure.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifGetTagCountInIfd(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int *ifd_count);



/**
 * @brief                   
 *                          
 * @param data_ptr          Exif data structure pointer.
 * @param ifd               IFD for which we get entry information from it.
 * @param index             Pointer to the entry information we get back from exif data structure.
 * @param entry_ptr         Pointer to the entry information we get back from exif data structure.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifGetEntryByIndex(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int index, EXIF_ENTRY *entry_ptr);




/**
 * @brief                   Save exif encoded data to the destination buffer.
 * @param data_ptr          Exif data structure pointer.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifSaveEncodedData(EXIF_DATA *data_ptr);



/**
 * @brief                   Get the total exif encoded data length.
 * @param data_ptr          Exif data structure pointer.
 * @return                  Total exif encoded data length.
 * @remarks
 */
unsigned int exifGetTotalEncodedDataLength(EXIF_DATA *data_ptr);



/**
 * @brief                   Set entry information to the selected entry_ptr.
 * @param entry_ptr         Selected entry pointer.
 * @param tag_id            Tag ID.
 * @param tag_format        Tag format.
 * @param tag_counts        Tag counts.
 * @param entry_data_size   Entry data size.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifSetEntryInfo(EXIF_ENTRY *entry_ptr, unsigned short tag_id, EXIF_TAG_FORMAT_ENUM tag_format, unsigned int tag_counts, unsigned int entry_data_size);



/**
 * @brief                   Set destination buffer information into exif data structure.
 * @param data_ptr          Exif data structure pointer.
 * @param dst_buffer_addr   Destination buffer address.
 * @param dst_buffer_size   Destination buffer size.
 * @return                  If the function succeeds, the return value is EXIF_RETURN_OK; otherwise the error code is returned.
 * @remarks
 */
EXIF_RETURN_STATUS_ENUM exifSetDstBuffer(EXIF_DATA *data_ptr, unsigned char *dst_buffer_addr, unsigned int dst_buffer_size);



/**
 * @brief                   Get exif working memory size.
 * @return                  Total exif working memory size.
 * @remarks
 */
unsigned int exifGetWorkingMemorySize(void);



/**
 * @brief                   Set a EXIF_SSHORT value to the buffer.
 * @param buffer_addr       Buffer address we assign.
 * @param value             Target value.
 * @return                  None
 * @remarks
 */
void exifSetSshort(unsigned char *buffer_addr, EXIF_SSHORT_T value);



/**
 * @brief                   Set a EXIF_SHORT_T value to the buffer.
 * @param buffer_addr       Buffer address we assign.
 * @param value             Target value.
 * @return                  None
 * @remarks
 */
void exifSetShort(unsigned char *buffer_addr, EXIF_SHORT_T value);



/**
 * @brief                   Set a EXIF_SLONG_T value to the buffer.
 * @param buffer_addr       Buffer address we assign.
 * @param value             Target value.
 * @return                  None
 * @remarks
 */
void exifSetSlong(unsigned char *buffer_addr, EXIF_SLONG_T value);



/**
 * @brief                   Set a EXIF_LONG_T value to the buffer.
 * @param buffer_addr       Buffer address we assign.
 * @param value             Target value.
 * @return                  None
 * @remarks
 */
void exifSetLong(unsigned char *buffer_addr, EXIF_LONG_T value);



/**
 * @brief                   Set a EXIF_RATIONAL_T value to the buffer.
 * @param buffer_addr       Buffer address we assign.
 * @param value             Target value.
 * @return                  None
 * @remarks
 */
void exifSetRational(unsigned char *buffer_addr, EXIF_RATIONAL_T value);



#endif  // End of #ifndef __EXIF_ENC_API_V2_H__
