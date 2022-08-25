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

#ifndef _FMGR_FSDATA_H_
#define _FMGR_FSDATA_H_

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#define _MMI_FMGR_FSDATA_CHECK_DIRCACHE_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "FileMgrProt.h"
#include "MMIDataType.h"
#include "FileMgrGProt.h"
#include "mmi_rp_file_type_def.h"
#include "fs_type.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"

/****************************************************************************
* Define
*****************************************************************************/


/********************************* Setting **********************************/

#ifndef FMGR_SRV_PART
/* buffer size for File Cache, will occupy [Nx124] bytes */
#ifdef __MMI_SLIM_FILE_MANAGER__
#define FMGR_CACHE_ENTRY_COUNT          (10)
#else 
#define FMGR_CACHE_ENTRY_COUNT          (32)
#endif 

#if (FMGR_CACHE_ENTRY_COUNT) < (FMGR_MATRIX_COLUMN_NUM*FMGR_MATRIX_ROW_NUM*2+4)
    #undef FMGR_CACHE_ENTRY_COUNT
    #define FMGR_CACHE_ENTRY_COUNT  (FMGR_MATRIX_COLUMN_NUM*FMGR_MATRIX_ROW_NUM*2+4)
#endif
#endif

/********************************** Macro **********************************/


/********************************** Enum  **********************************/


/********************************* Typedef ********************************/

/* Sort_enhance */

typedef S32 (*mmi_fmgri_fsdata_load_response_callback)(U32 user_data, S32 result);
typedef S32 (*mmi_fmgri_fsdata_load_progress_callback)(U32 user_data, S32 result, S32 progress);

typedef S32 (*mmi_fmgri_fsdata_instance_load_response_callback)(U8 instance_id, S32 result, S32 search_index);
typedef S32 (*mmi_fmgri_fsdata_instance_load_progress_callback)(U8 instance_id, S32 total_count, S32 progress_count);

typedef struct 
{
    U8                      state;
    S8                      *file_path;
    U16                     sort_flag;
#if defined(_MMI_FMGR_ASYNC_SORT_SUPPORT_)
    /* Sort_enhance */    
    S8                      *sort_buffer;
    U32                     sort_buffer_size;
    U32                     sort_handle;
//    S8                      *work_buffer;
//    U32                     work_buffer_size;

    mmi_fmgri_fsdata_load_response_callback rsp_callback;
    mmi_fmgri_fsdata_load_progress_callback progress_callback;
#endif

    S32                     count;              /* total file count */
    S32                     cache_start_idx;
    S32                     cache_end_idx;
    S32                     cache_buffer_count;       /* size of buffer */
    S32                     progress_count;
    FMGR_FILE_INFO_STRUCT   *cache_buffer;
        
    FMGR_FILTER             filter_type;
            
#ifdef _MMI_FMGR_FSDATA_CHECK_DIRCACHE_
    FS_FileOpenHint         hint_data;
#endif
} mmi_fmgr_fsdata_info_struct;

typedef struct mmi_fmgr_fsdata_context_struct
{
    U8 instance_id;    /* which instance is using instance_data */
    BOOL                        file_cache_locked;
    U16 sort_option;
    mmi_fmgri_fsdata_instance_load_response_callback instance_rsp_cb;
    mmi_fmgri_fsdata_instance_load_progress_callback instance_progress_cb;    
    SRV_FMGR_FILELIST_HANDLE file_list_hdl;
    MMI_BOOL file_list_lock;
    S32 load_file_index;    
#if defined(_MMI_FMGR_ASYNC_SORT_SUPPORT_)
    mmi_fmgr_fsdata_info_struct *curr_info;     /* current info occupy fmt task */
#endif        
}mmi_fmgr_fsdata_context_struct;


/* FSData init function */
extern void mmi_fmgri_fsdata_init(void);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern S32  mmi_fmgri_fsdata_search_file_index(U8 instance_id, S8* filename);

extern void mmi_fmgri_fsdata_set_sort_option(U16 sort_type);
extern U16  mmi_fmgri_fsdata_get_sort_option(void);

extern SRV_FMGR_FILELIST_HANDLE mmi_fmgri_fsdata_get_current_file_list_hdl(void);
extern void mmi_fmgri_fsdata_unlock_file_list(void);
extern SRV_FMGR_FILELIST_HANDLE mmi_fmgri_fsdata_lock_file_list(void);
extern MMI_BOOL mmi_fmgri_fsdata_is_file_list_locked(void);

/* This is not related to mount state */
extern U8   mmi_fmgri_fsdata_get_drive_count(void);
extern S8*  mmi_fmgri_fsdata_get_drive_leading_pattern(srv_fmgr_drv_type_enum index);

/* This is related to mount state */
extern U32  mmi_fmgri_fsdata_get_drive_mask(void);
extern S16  mmi_fmgri_fsdata_get_drive_type(U32 drive_mask, S32 index);
extern S8   mmi_fmgri_fsdata_get_drive_count_by_mask(U32 drive_mask);

extern U8   mmi_fmgri_fsdata_is_msdc_present(void);

extern S32  mmi_fmgri_fsdata_get_msdc_name(const U16* path, U16* name_buffer, S32 name_buf_size);

/* Smallp Added */
extern void mmi_fmgri_fsdata_lock_cache_buffer(FMGR_FILE_INFO_STRUCT** buffer_pp, S32* buffer_count_p);
extern void mmi_fmgri_fsdata_unlock_cache_buffer(FMGR_FILE_INFO_STRUCT* buffer_p);

extern MMI_BOOL mmi_fmgri_fsdata_is_out_of_cache(S32 index);

/* Sort_enhance */

extern S32 mmi_fmgri_fsdata_load_data(mmi_fmgr_fsdata_info_struct* info,
                        S8* filepath, FMGR_FILTER *filter_type, U16 sort_type,
                        FMGR_FILE_INFO_STRUCT* buffer, S32 buffer_count);

extern S32 mmi_fmgri_fsdata_load_data_async(mmi_fmgr_fsdata_info_struct* info,
                        S8* filepath, FMGR_FILTER *filter_type, U16 sort_type,
                        FMGR_FILE_INFO_STRUCT* buffer, S32 buffer_count,
                        mmi_fmgri_sort_buffer_callback alloc_callback, U32 alloc_userdata,
                        mmi_fmgri_fsdata_load_response_callback rsp_cb,
                        mmi_fmgri_fsdata_load_progress_callback progress_cb,
                        S32 prefer_index,
                        S8* highlight_filename);

extern S32 mmi_fmgri_fsdata_load_data_sync(mmi_fmgr_fsdata_info_struct* info,
                        S8* filepath, FMGR_FILTER *filter_type, U16 sort_type,
                        FMGR_FILE_INFO_STRUCT* buffer, S32 buffer_count);

extern S32 mmi_fmgri_fsdata_free_data(mmi_fmgr_fsdata_info_struct* info);

extern S32 mmi_fmgri_fsdata_get_file_info(mmi_fmgr_fsdata_info_struct* info, S32 index, FMGR_FILE_INFO_STRUCT *file_info, S8 allow_blocking);

extern S32 mmi_fmgri_fsdata_get_file_count(mmi_fmgr_fsdata_info_struct* info);
extern S32 mmi_fmgri_fsdata_get_ready_count(mmi_fmgr_fsdata_info_struct* info);

/* for instance */
extern S32 mmi_fmgri_fsdata_instance_load_data_async(U8 instance_id,
                        mmi_fmgri_fsdata_instance_load_response_callback rsp_cb,
                        mmi_fmgri_fsdata_instance_load_progress_callback progress_cb,
                        S8* highlight_filename);

extern mmi_ret mmi_fmgr_fsdata_load_file_result_proc(mmi_event_struct *param);
extern S32 mmi_fmgri_fsdata_instance_release_load(U8 instance_id);
extern S32 mmi_fmgri_fsdata_instance_get_file_info(U8 instance_id, S32 index, FMGR_FILE_INFO_STRUCT *file_info);
extern S32 mmi_fmgri_fsdata_instance_get_file_info_ex(U8 instance_id, S32 index, FMGR_FILE_INFO_STRUCT *file_info);
extern S32 mmi_fmgri_fsdata_instance_get_total_count(U8 instance_id);

extern S32 mmi_fmgri_fsdata_instance_force_release(void);

extern void mmi_fmgri_fsdata_instance_load_empty_data(U8 instance_id);

extern S32 mmi_fmgri_fsdata_instance_export(U8 instance_id, mmi_fmgr_fsdata_info_struct* info);
extern S32 mmi_fmgri_fsdata_instance_import(U8 instance_id, mmi_fmgr_fsdata_info_struct* info);
extern S32 mmi_fmgr_fsdata_instance_refresh_drive_list(U8 instance_id);

extern S32 mmi_fmgri_fsdata_instance_get_drive_info(U8 instance_id, S32 index, fmgr_drive_info_struct *drv_info);

extern S32 mmi_fmgri_fsdata_instance_is_empty_folder(U8 instance_id);

/* for gui set flag */
extern void mmi_fmgri_fsdata_gui_set_cache_flag(U8 instance_id, S32 index, S32 flag, S32 on_off);
extern S32 mmi_fmgri_fsdata_gui_get_cache_flag(U8 instance_id, S32 index, S32 flag);

/* for enable/disable FS check */
extern void mmi_fmgri_fsdata_fscheck_enable(S32 on_off);

/* tool api, convert FSDirEntry */
extern void mmi_fmgri_fsdata_convert_fsentry(FMGR_FILE_INFO_STRUCT *info, FS_DOSDirEntry* fs_entry, S8* filename);

/* tool api, to check if a folder has matching file or not */
extern S32 mmi_fmgri_fsdata_is_empty_folder(S8* filepath, FMGR_FILTER *filter_type);

/* tool api, if a file with filename > 40, change it to short name */
extern S32 mmi_fmgri_fsdata_convert_filename(S8* original_path, S8* new_filepath);

/* find API wrapper */
extern S32 mmi_fmgri_fsdata_findfirst(FS_HANDLE *fh,
                               S8* filepath, 
                               FMGR_FILTER *file_type,
                               FMGR_FILE_INFO_STRUCT *file_info,
                               S32 start_index);
extern S32 mmi_fmgri_fsdata_findnext(FS_HANDLE fh,
                               FMGR_FILTER *file_type,
                               FMGR_FILE_INFO_STRUCT *file_info);
extern S32 mmi_fmgri_fsdata_findclose(FS_HANDLE fh);

/****************************************************************************
* Local Function
*****************************************************************************/

#endif /* _FMGR_FSDATA_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */
