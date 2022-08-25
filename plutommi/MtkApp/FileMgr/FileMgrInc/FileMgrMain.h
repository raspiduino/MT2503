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

#ifndef _FMGR_MAIN_H_
#define _FMGR_MAIN_H_

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#include "FileMgrProt.h"
#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrSrvGProt.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "FileMgrInstance.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
/****************************************************************************
* Include Files                                                                
*****************************************************************************/


/****************************************************************************
* Define
*****************************************************************************/

/********************************* Setting **********************************/


/********************************** Macro **********************************/
//#define FMGR_MAX_MARK_ITEM          50 /* at most 50 files can be marked in a time */
//#define FMGR_MAX_MARK_CACHE_SIZE    (UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * 2)


/********************************** Enum  **********************************/


/********************************* Typedef ********************************/

/* FMGR Main context structure */
typedef struct mmi_fmgr_main_context_struct
{    
    U8  client_id;
    U8  client_action;
    U8  client_copy_id;
    U8  client_copy_action;
    U8 async_fs_state;
    U8 async_fs_aborting;
    U8 async_fs_instance_id;
    U8 _align0;
    mmi_id client_copy_sel_id;
    mmi_id editor_cui_id;
    mmi_id imageviewer_cui_id;
    mmi_fmgr_instance_struct *instance;
    void *app_mem_pool;
    PS8 ext_name;
    S32 async_fs_job_id;
#ifdef FMGR_TAB_SUPPORT
    U32 destination_tab_id; /* tab id of destination folder (copy / move) */
#endif /* FMGR_TAB_SUPPORT */
#ifdef __DM_LAWMO_SUPPORT__
    MMI_BOOL post_endkey;
#endif    
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    MMI_BOOL action_from_ms;
    mmi_fmgr_instance_struct *ms_caller_instance;  // This is FMGR or App (Imageviewer/Ebook)instance 
    U32 ms_id;
    S8 ms_highlight_filename[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH];
	S16 mul_sel_inst_id;
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__)
    U8  ms_total_count;
    mmi_id ms_pict_cui_id;
#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__) */
#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */    
    FMGR_FILTER delete_filter_type;    
    S8 old_file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    S8 new_file_name[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
          
}mmi_fmgr_main_context_struct;



/****************************************************************************
* Global variable
*****************************************************************************/

extern const mmi_fmgri_instance_callback_table_struct mmi_fmgri_main_table;

/****************************************************************************
* Global Function
*****************************************************************************/
extern void mmi_fmgri_main_init(void);

extern void mmi_fmgri_main_init_mmi_context(void);

extern void mmi_fmgri_main_create_folder(mmi_fmgr_instance_struct *instance);

extern void mmi_fmgri_main_rename_drive(mmi_fmgr_instance_struct *instance);
extern void mmi_fmgri_main_entry_card_detail(mmi_fmgr_instance_struct *instance);
extern void fmgr_main_entry_card_detail(mmi_scrn_essential_struct* arg);

extern void mmi_fmgri_main_rename(mmi_fmgr_instance_struct *instance);

extern void mmi_fmgri_main_delete_single(mmi_fmgr_instance_struct *instance);
#ifndef __MMI_SLIM_FILE_MANAGER__
extern void mmi_fmgri_main_delete_all(mmi_fmgr_instance_struct *instance);
#endif
extern void mmi_fmgri_main_send_delete_req(S8* path, U32 type, U8 action, FMGR_FILTER* filter,
                                           PsFuncPtr callback, 
                                           void* buffer, U32 buf_size);


//extern void mmi_fmgr_main_send_delete_several_req(PU8 path, U32 type, PsFuncPtr callback, PsFuncPtr delete_several_callback);

extern mmi_ret mmi_fmgri_main_drive_confirm_cb(mmi_alert_result_evt_struct *evt);

extern void mmi_fmgri_main_drive_confirm(mmi_fmgr_instance_struct *instance, U8 action);

extern void mmi_fmgri_main_send_format_req(U8 drive, U32 level, PsFuncPtr callback);

extern void mmi_fmgri_main_send_unmount_req(U8 index, U32 mode, PsFuncPtr callback);

extern void mmi_fmgri_main_detail(mmi_fmgr_instance_struct *instance);

extern void mmi_fmgri_main_forward(mmi_fmgr_instance_struct *instance, U16 menu_id);

extern void mmi_fmgri_main_copy(mmi_fmgr_instance_struct *instance);
extern void mmi_fmgri_main_move(mmi_fmgr_instance_struct *instance);

extern void mmi_fmgri_main_send_copy_req(U8 action, PU8 src_file, PU8 dest_file, PsFuncPtr callback);
extern void mmi_fmgri_main_send_copy_req_ext(U8 action, PU8 src_file, PU8 dest_file, PsFuncPtr callback, void* rec_buffer, U32 rec_buf_size);

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
extern void mmi_fmgri_main_mark_several(mmi_fmgr_instance_struct *instance, U16 action);
void mmi_fmgr_general_option_mul_sel_handler(mmi_menu_id item_id, const WCHAR *filepath, const srv_fmgr_fileinfo_struct *fileinfo);
extern void mmi_fmgri_main_mark_delete(mmi_fmgr_instance_struct *instance);
extern void mmi_fmgri_main_mark_copy(mmi_fmgr_instance_struct *instance);
extern void mmi_fmgri_main_mark_move(mmi_fmgr_instance_struct *instance);
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__)
extern void mmi_fmgri_main_mark_print(mmi_fmgr_instance_struct *instance);
#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__) */
#ifdef __MMI_OPP_SUPPORT__
extern mmi_ret mmi_fmgri_main_mark_send_confirm_cb(mmi_alert_result_evt_struct *evt);
extern void mmi_fmgri_main_mark_send(mmi_fmgr_instance_struct *instance, U16 menu_id);
#endif
#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

extern void mmi_fmgri_main_cancel_operation(mmi_fmgr_instance_struct *instance);

extern U8 mmi_fmgri_main_get_async_fs_state(void);
extern void mmi_fmgri_main_set_async_fs_state(U8 new_state);
extern void mmi_fmgri_main_clear_async_fs_state(U8 state);

#ifdef __FMGR_USE_EDITOR_CUI__
extern void mmi_fmgri_main_handle_editor_event(mmi_fmgr_instance_struct *instance, mmi_event_struct *param);
#endif /* __FMGR_USE_EDITOR_CUI__ */

/****************************************************************************
* Internal Function
*****************************************************************************/
#ifdef _FMGR_MAIN_C_
extern U16 fmgr_main_options_handler(U16 opt_menu_id, U16 menu_id, U32 data, U16 keyCode);

extern void fmgr_main_entry_editor_option(void);
extern void fmgri_main_return_to_editor(void);

extern void fmgr_main_general_operation_cancel(void);
/*
 *  Delete related API
 */
extern mmi_ret mmi_fmgri_main_delete_confirm_cb(mmi_alert_result_evt_struct *evt);
extern void fmgr_main_delete_confirm(mmi_fmgr_instance_struct *instance, U8 action);
extern void fmgr_main_delete_single(void);
#ifndef __MMI_SLIM_FILE_MANAGER__
extern void fmgr_main_delete_all(void);
#endif
extern void fmgr_main_delete_rsp_center_hdlr(void *info);

extern void fmgr_main_entry_delete_animation(void* arg);
extern U8 fmgr_main_delete_animation_callback(void *param);

#ifdef __FS_SORT_SUPPORT__
extern void fmgr_main_reinit_sort_option(void);
extern void fmgr_main_set_sort(U16 menu_id, mmi_fmgr_instance_struct *instance);
#endif /* __FS_SORT_SUPPORT__ */

extern void fmgr_main_drive_action_hdlr(void);

extern void fmgr_main_entry_drive_animation(void);
extern void fmgr_main_exit_drive_animation(void);

extern S8 fmgr_main_check_delete_all_filter(void* delete_filter_type, U16 type, S8 *ext);

extern void fmgr_main_entry_detail(mmi_scrn_essential_struct* arg);

/*
 *  Copy related API
 */
extern void fmgr_main_entry_copy(mmi_fmgr_instance_struct *instance, U8 action);
extern void fmgr_main_copy_rsp_center_hdlr(void *info);

extern void fmgr_main_entry_copy_animation(void* arg);

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__

extern void fmgr_main_delete_mark(void);
extern U16  fmgr_main_copy_mark(U8 action);

#if defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__)
extern void fmgr_main_print_mark(mmi_fmgr_instance_struct *instance);
extern S32 fmgr_main_mark_print_next(void);
#endif 

#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

extern void fmgr_main_op_abort_processing_hdlr(void *info);

#endif /* _FMGR_MAIN_C_ */

#endif /* _FMGR_MAIN_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */
