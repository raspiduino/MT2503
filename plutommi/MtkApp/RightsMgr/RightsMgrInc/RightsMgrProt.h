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
 *  RightsMgrProt.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Header file for Rights Manager internal usage
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __RIGHTSMGRPROT_H__
#define __RIGHTSMGRPROT_H__

/*
 * Include 
 */
//#include "RightsMgrResDef.h"
#include "app_datetime.h"
//#include "FileMgr.h"
//#include "drm_gprot.h"
//#include "MenuCUIgprot.h"
//#include "AlertScreen.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "RightsMgrGProt.h"
#include "drm_def.h"
#include "mmi_frm_events_gprot.h"

#ifdef __MMI_RMGR__
/*
 * Define
 */
#define MMI_RMGR_LIST_RO_NUM (10)
#define MMI_RMGR_WHITE_LIST_NUM (5)
#define MMI_RMGR_WHITE_LIST_URL_MAX_LEN (128)
#define MMI_RMGR_MAX_GEN_INFO_NUM (5)
#define MMI_RMGR_MAX_HTTP_PROFILE_NUM (5)


/*
 * Typedef 
 */

/* rights manager context structure */
typedef struct
{
    MMI_BOOL trans_state;
    MMI_BOOL allow_scan_disk;

    U8 scan_serial;

    /* rights manager selection index */
    U8 rmgr_sel_idx;
    U8 menu_cui_id;

    /* list ro */
    S32 ro_idx;

#ifdef __DRM_V02__    
    /* white list */
    U8 wl_sel_idx;
    S8 wl_count;
    S8 input_buffer[(MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1) *ENCODING_LENGTH];
#endif /* __DRM_V02__ */

    S32 current_idx;
} mmi_rmgr_cntx_struct;

typedef struct
{
    S32 ro_num;
    MMI_BOOL refresh;
}rmgr_list_ro_cntx_struct;

//structure for event handling in app srv interaction
typedef struct    //Akhil
{
	MMI_EVT_PARAM_HEADER 
	U16 str_id;  //string id for the popup
	mmi_event_notify_enum evt_type;  //type success or failure
}   mmi_rmgr_dlagent_evt_struct;



extern rmgr_list_ro_cntx_struct rmgr_list_ro_cntx;

/*
 * Global Variable 
 */
extern mmi_rmgr_cntx_struct *const mmi_rmgr_p;

/*
 * Global Function 
 */
extern void mmi_rmgr_list_ro_entry_main(void);
extern void mmi_rmgr_whitelist_entry_main(void);
extern void mmi_rmgr_gen_info_entry_main(void);
extern void mmi_rmgr_sweep_entry_main(void);
extern void mmi_rmgr_http_profile_entry_main(void);
extern void mmi_rmgr_ui_init(void);
extern void mmi_rmgr_send_sweep_req(S32 index);
extern U16 mmi_rmgr_get_root_icon(void);
extern void mmi_rmgr_send_process_database_req(kal_uint8 type, kal_int32 index, kal_wchar *path);
extern void mmi_rmgr_recv_process_database_cnf(void *msg);
extern void mmi_rmgr_entry_db_progressing(U16 str_id, U8 serial, MMI_BOOL can_cancel, MMI_BOOL cancel_when_exit);
extern void mmi_rmgr_entry_db(void);
extern void mmi_rmgr_entry_fmgr(void);
extern MMI_BOOL mmi_rmgr_db_check_status(void);
extern void mmi_rmgr_clear_unlock_screen(void);
extern void mmi_rmgr_register_unlock_session(
                                        FS_HANDLE handle,
                                        U16 *path,
                                        U8 permission,
                                        MMI_BOOL more,
                                        U8 *url,
                                        U32 url_size,
                                        U16 icon,
                                        mmi_rmgr_ri_callback callback);
extern void mmi_rmgr_wipe_unlock_session(void);
extern void mmi_rmgr_scan_disk(void);
extern void mmi_rmgr_entry_activate(void);

extern void mmi_drm_show_info(void);
extern MMI_BOOL mmi_drm_need_show_info(void);
extern void mmi_drm_ui_init(void);


/*  sweep */
void mmi_rmgr_period_sweep_db_timeout_hdlr(void);

/*
 * DRM Exported for RightsMgr
 */
extern void DRM_slave_common_hdlr(void *MsgStruct, int mod_src, void *ilm_p);
extern void DRM_app_process_obj_hdlr(void *local_para_ptr);
extern void DRM_app_install_obj_hdlr(void *local_para_ptr);
extern void DRM_app_ro_expiry_hdlr(void *local_para_ptr);
extern void DRM_app_activate_hdlr(void *local_para_ptr);
extern void DRM_app_parse_drm_message_hdlr(void *local_para_ptr);
extern void DRM_app_process_database_hdlr(void *local_para_ptr);
extern void DRM_app_get_ro_num_hdlr(void *local_para_ptr);
extern void DRM_app_encode_drm_message_hdlr(void *local_para_ptr);
extern void DRM_app_scan_disk_hdlr(void *local_para_ptr);

extern kal_int32 DRM_process_database(
                    kal_uint8 type,
                    kal_int32 index,
                    kal_wchar *path,
                    kal_uint8 *serial,
                    drm_general_callback callback);
extern kal_int32 DRM_scan_disk(kal_uint8 type, kal_wchar *path, kal_uint8 *serial, drm_general_callback callback);
extern kal_int32 DRM_get_ro_num(kal_uint8 *serial, drm_general_callback callback, drm_proc_db_ro_count_flag_enum flag);
extern kal_int32 DRM_get_ro_list(kal_int32 index, kal_char *alias, kal_uint32 size, drm_proc_db_ro_count_flag_enum flag);
extern void DRM_free_ro_list(void);
extern kal_int32 DRM_delete_ro_by_seed(kal_uint8* seed, kal_int32 seed_len);
extern void DRM_free_ro_detail(void);

extern kal_bool DRM_toggle_tracking(kal_bool to_get);
extern kal_int32 DRM_get_domain_num(void);
extern kal_bool DRM_get_trust_state(void);
extern kal_bool DRM_get_ro_shareability(kal_int32 index);
extern kal_int32 DRM_get_version(void);
extern kal_uint8 DRM_get_object_method_by_ref(kal_int32 ro_index, drm_proc_db_ro_count_flag_enum flag);
extern kal_int32 DRM_get_constraint_by_ref(kal_int32 ro_index, kal_uint8 permission, drm_constraint_struct *cons);

extern kal_int32 DRM_init_whitelist(void);
extern kal_bool DRM_get_whitelist(kal_char *list_buffer, kal_uint8 index);
extern kal_int32 DRM_add_whitelist(kal_char *list_buffer);
extern kal_bool DRM_del_whitelist(kal_char *list_buffer);
extern void DRM_free_whitelist(void);

extern kal_int32 DRM_import_certificate(kal_wchar *path);

extern kal_bool DRM_get_secure_time(applib_time_struct *time);
extern kal_int32 DRM_get_ro_dbsize(kal_int32 *total);

extern mmi_ret mmi_rmgr_main_evt_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_ro_options_evt_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_db_proc_evt_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_activate_leave_proc(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_list_ro_delete_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_ro_sweep_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_backup_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_restore_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_auth_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_db_check_conf_callback(mmi_event_struct *evt);
extern mmi_ret mmi_rmgr_whitelist_conf_callback(mmi_event_struct *evt);

extern U8 mmi_rmgr_reboot_ms_slave(void *info, int mod_src);
extern void mmi_rmgr_reboot_ms(void *msg);
extern mmi_ret mmi_rmgr_db_app_leave_proc(mmi_event_struct *evt);

extern void mmi_rmgr_stime_expiry_hdlr(void *MsgStruct, int mod_src, void *ilm_p);
extern mmi_ret mmi_rmgr_dlagent_notify_handler(mmi_event_struct *evt);  //Akhil

#endif /* __MMI_RMGR__ */
#endif /* __RIGHTSMGRPROT_H__ */ 

