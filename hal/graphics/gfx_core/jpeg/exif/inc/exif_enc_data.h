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
 *   exif_enc_data.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_ENC_DATA_V2_H__
#define __EXIF_ENC_DATA_V2_H__

#include "exif_enc_structure.h"
#include "exif_enc_enum.h"

EXIF_RETURN_STATUS_ENUM exif_data_new(EXIF_DATA *data_ptr, void *mem_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_set_default(EXIF_DATA *data_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_create_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_add_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, EXIF_ENTRY *entry_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_remove_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id);
EXIF_RETURN_STATUS_ENUM exif_data_remove_all_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd);
EXIF_RETURN_STATUS_ENUM exif_data_get_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned short tag_id, EXIF_ENTRY *entry_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_get_tag_count_in_ifd(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int *ifd_count);
EXIF_RETURN_STATUS_ENUM exif_data_get_entry_by_index(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, unsigned int index, EXIF_ENTRY *entry_ptr);
EXIF_RETURN_STATUS_ENUM exif_data_save_encoded_data(EXIF_DATA *data_ptr);
unsigned int exif_data_get_total_encoded_length(EXIF_DATA *data_ptr);
unsigned int exif_data_get_content_length(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd);
unsigned int exif_data_get_working_memory_size(void);



#endif  // End of #ifndef __EXIF_ENC_DATA_V2_H__
