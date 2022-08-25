/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#if defined (__MMI_FILE_MANAGER__)

#ifndef _FMGR_SERVICE_H_
#define _FMGR_SERVICE_H_

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif


/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "FileMgrInstance.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrGProt.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"

/****************************************************************************
* Define
*****************************************************************************/

/********************************* Setting **********************************/


/********************************** Macro **********************************/


/********************************** Enum  **********************************/


/********************************* Typedef ********************************/
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
typedef void (*mmi_fmgri_multi_sel_close_callback)(U32 ms_id, U32 user_data);
#endif

/****************************************************************************
* Global variable
*****************************************************************************/

#ifdef __DRM_V02__
extern const mmi_fmgri_instance_callback_table_struct mmi_fmgri_serv_archive_table;
#endif
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
extern const mmi_fmgri_instance_callback_table_struct mmi_fmgri_serv_multi_select_table;
#endif

/****************************************************************************
* Internal Function
*****************************************************************************/

extern void mmi_fmgri_service_init(void);

/* internal select path */
extern U32  mmi_fmgri_serv_select_path_internal(U16 app_id, U8 sel_type, FMGR_FILTER filter, 
                                                S8* base_path, PsExtFuncPtr callback,
                                                U8 display_type, U16 title_str_id);

extern U32  mmi_fmgri_serv_select_drive_internal(U16 app_id, 
                                                 mmi_fmgr_select_drv_callback callback, 
                                                 S8 default_highlight_storage);

#if defined(__DRM_V02__)
/* to view a multipart odf */
extern U32  mmi_fmgri_open_archive(mmi_id parent_id, U16 app_id, S8* archive_filepath);
extern void mmi_fmgri_close_archive(U32 id);
#endif

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
/* multi select - instance */
extern U32  mmi_fmgri_serv_multi_sel_internal(mmi_id parent_id, U16 app_id, U16 action, FMGR_FILTER *filter, S8* base_path, 
                                              mmi_fmgri_multi_sel_close_callback callback,
                                              U16 option_menu_id,
                                              S8* default_highlight_name,
                                              U32 user_data);
extern void mmi_fmgri_serv_multi_sel_close(U32 id);

extern S32  mmi_fmgri_serv_multi_sel_get_path(U32 id, S8* buffer, S32 buffer_length);
extern S32  mmi_fmgri_serv_multi_sel_get_index(U32 id);
extern S32  mmi_fmgri_serv_multi_sel_get_file_by_index(U32 id, S32 index, FMGR_FILE_INFO_STRUCT* info);
extern S32  mmi_fmgri_serv_multi_sel_get_mark_array(U32 id);
extern S32  mmi_fmgri_serv_multi_sel_set_mark_array_dirty(U32 id);
extern S32  mmi_fmgri_serv_multi_sel_find_non_mark(U32 id, S32 start_index);

/* multi select array API */
extern S32  mmi_fmgri_msa_add(S32 msa_id, S8* filename, U32 size, MYTIME* time, U8 flag);
extern S32  mmi_fmgri_msa_remove(S32 msa_id, S8* filename);
extern void mmi_fmgri_msa_pop(S32 msa_id);
extern S8*  mmi_fmgri_msa_top(S32 msa_id);
extern MMI_BOOL mmi_fmgri_msa_is_exist(S32 msa_id, S8* filename);
extern S32  mmi_fmgri_msa_count(S32 msa_id);
extern S32  mmi_fmgri_msa_count_filter(S32 msa_id, U8 with_flag);
extern void mmi_fmgri_msa_set_flags(S32 msa_id, U8 match_flag, U8 apply_flag, U8 remove_flag);

#define MMI_FMGRI_MSA_PROCESSED  0x01
#define MMI_FMGRI_MSA_SENDABLE   0x02
#define MMI_FMGRI_MSA_FOLDER     0x04

#endif

#ifndef __MMI_SLIM_FILE_MANAGER__
extern U16  mmi_fmgri_serv_get_drive_string_id(srv_fmgr_drv_type_enum drv_type);
#endif

#endif /* _FMGR_SERVICE_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */
