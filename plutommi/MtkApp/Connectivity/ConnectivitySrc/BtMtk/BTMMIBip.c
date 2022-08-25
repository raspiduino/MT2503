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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BTMMIBip.c
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BIP_SUPPORT__)

/***************************************************************************** 
 * Include 
 *****************************************************************************/


#include "bluetooth_struct.h"

#include "BtcmSrvGprot.h"
#include "BTMMIObexGprots.h"

#include "BTMMIBipGprot.h"
#include "BipSrvGprot.h"
#include "BTMMIBip.h"


#ifdef __USB_IN_NORMAL_MODE__
#include "USBSrvGprot.h"
#endif 

#include "app_mine.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "BTMMISendGprots.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "NotificationGprot.h"
#include "Unicodexdcl.h"
#include "stack_config.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "fs_errcode.h"
#include "gui_data_types.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
 /***************************************************************************** 
 * Define
 *****************************************************************************/

/* display thumbnail list in image browser */
//#define __MMI_BIP_LIST_THUMBNAIL__

#define BIP_NOTY_STR_SIZE     (128)

U16 mmi_bip_notify_str[BIP_NOTY_STR_SIZE];


#define MAX_IMG_DETAIL_NAME 35

#define MMI_BIP_SMALL_SCREEN_WIDTH 128

#define MMI_BIP_IS_WIDE_SCREEN (UI_DEVICE_WIDTH > MMI_BIP_SMALL_SCREEN_WIDTH)

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * CONTEXT
 *****************************************************************************/
mmi_bip_struct mmi_bip_cntx;
mmi_bip_struct *mmi_bip_p = &mmi_bip_cntx;

/***************************************************************************** 
 * Function prototype
 *****************************************************************************/
extern U8 PhnsetGetDefEncodingType(void);
#ifdef __MMI_WEBCAM__
extern MMI_BOOL mmi_usb_webcam_is_active(void);
#endif


static void mmi_bipr_init_cntx(void);
static S32 mmi_bipr_event_hdlr(S32 srv_hd, U32 event_id, void *para);
static void mmi_bipr_start_ind_hdlr(void *para);
static void mmi_bipr_stop_ind_hdlr(void *para);
static void mmi_bipr_authorize_ind_hdlr(void *para);
static void mmi_bipr_connect_ind_hdlr(void *para);
static void mmi_bipr_disconn_ind_hdlr(void *para);
static void mmi_bipr_recv_ind_hdlr(void *para);
static void mmi_bipr_accept_file(void);
static void mmi_bipr_reject_file(void);
static void mmi_bt_bip_authorize_rsp_hdler(srv_bt_cm_bt_addr *bd_addr,U32 profile_id, U32 result);
static void mmi_bipr_recv_notify_hdlr(S32 hd, U32 event, S32 retval);
//static void mmi_bipr_get_recv_drv_callback (U32 uuid, U8 drv, MMI_BOOL selected);
static void mmi_bipr_notify_recv_err(mmi_bt_bip_error_enum cause);

//static void mmi_bip_gen_folder(U16 *path, U8 drv);
static void mmi_bip_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte);
//static void mmi_bip_request_notify_err_hdlr(UI_string_type string, mmi_event_notify_enum event_id);
//static void mmi_bip_notify_err_info(mmi_bt_bip_error_enum cause);
#ifdef __MMI_USB_SPLIT_SUPPORT__
static void mmi_bt_bip_usb_mode_cnf_hdlr(void *msg);
#endif

static U16 *mmi_bip_compose_string(U16 type);
static void mmi_bipr_scr_recv_img_notify(void);
static void mmi_bip_delete_screen(U16 scrn_id);
static void mmi_bipr_clear_push_scrs(void);

#ifdef __MMI_BT_RECV_OBJ_DETAIL__
/* PUSH server */
static U16 * mmi_bipr_compose_img_detail(void);
static void mmi_bipr_detail_confirm_hdlr(void);
static MMI_BOOL mmi_bipr_entry_detail_confirm(mmi_scenario_id scen_id, void *arg);
static void mmi_bipr_entry_detail_confirm_scr(void);
static void mmi_bipr_exit_detail_confirm_scr(void);
static mmi_ret mmi_bipr_detail_confirm_proc(mmi_event_struct *evt);
static mmi_ret mmi_bipr_detail_confirm_scr_leave_proc(mmi_event_struct *evt);
static void mmi_bipr_accept_file(void);
static void mmi_bipr_reject_file(void);

#endif



#ifdef __BIP_PULL_SUPPORT__
static void mmi_bipi_send_get_imglist_req(void);
static void mmi_bipi_send_get_img_req(S8 *img_handle);
static void mmi_bipi_send_get_imgprop_req(S8 *img_handle);
static void mmi_bipi_send_get_imgthm_req(S8 *img_handle);
static void mmi_bipr_send_get_imglist_ind_msg_to_self(void);
static void mmi_bipi_get_imglist_cnf_hdlr(void *msg);
static void mmi_bipi_get_img_cnf_hdlr(void *msg);
static void mmi_bipi_get_imgprop_cnf_hdlr(void *msg);
static void mmi_bipi_get_thm_cnf_hdlr(void *msg);
static void mmi_bipi_pull_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp);
static void mmi_bipi_pull_continue_ind_hdlr(bt_bip_continue_ind_struct *ind);
static void mmi_bipr_get_imglist_ind_hdlr(void *msg);
static void mmi_bipr_get_img_ind_hdlr(void *msg);
static void mmi_bipr_get_imgprop_ind_hdlr(void *msg);
static void mmi_bipr_get_thm_ind_hdlr(void *msg);
static mmi_bip_construct_imglist_ret_enum mmi_bipr_compose_image_list_xml(mmi_bip_find_type_enum find_type, U32 *img_count);
#ifdef __MMI_BIP_COMPOSE_IMGLIST_XML_IN_ADP__
static mmi_bip_construct_imglist_ret_enum mmi_bipr_construct_img_list(mmi_bip_find_type_enum find_type, U32 *img_count);
#endif
static void mmi_bipr_delete_tmp_imglist_file(void);
static void mmi_bipr_close_tmp_imglist_file(void);
static void mmi_bipr_close_tmp_imglist_file_continually(void);
static MMI_BOOL bip_share_folder_exist(void);
static void mmi_bip_work_folder_init(void);
static int mmi_bipr_open_imglist_files(void);
static int mmi_bipr_write_imglist_xml_header(void);
static int mmi_bipr_write_imglist_xml_tail(void);
static int mmi_bipr_write_imghdle_buf2file(
                    S8 *hdlnm_buf, 
                    UINT32 hdlnm_buflen, 
                    S8 *xml_buf, 
                    UINT32 xml_buflen, 
                    UINT32 xml_item_size,
                    UINT32 *wr_cnt);


static void mmi_bip_compose_imghandle_str(U8 *imghandle, U16 count);
static U8 mmi_bip_construct_filter_pattern(FS_Pattern_Struct *bip_filter_pattern, U8 max_cnt);
static void mmi_bip_get_imgfile_postfix(S8 *postfix, U16 *tmp_file);
static S16 mmi_bip_get_partial_imglist(U16 start_index, U16 max_num);
static U8 mmi_bipr_pull_get_filename_with_imghandle(S8 *img_handle, S8 *file_name, S8 *ucs2_name);
static mmi_bt_bip_error_enum mmi_bip_rename_pulled_thm(S8 * dst_thm_name);
static mmi_bt_bip_error_enum mmi_bip_create_file(U16 *filename);
static mmi_bt_bip_error_enum mmi_bip_create_folder_if_not_exist(U16 *folder_name, mmi_bip_role_type_enum role, MMI_BOOL popup_info);


static void mmi_bipi_get_all_images(void);
static void mmi_bipi_get_selected_images(void);
static void mmi_bipi_get_next_image(void);
static void mmi_bipi_get_cur_imgprop(void);
static void mmi_bipi_get_cur_imgthm(void);
static void mmi_bipi_get_next_thm(S32 index);
static void mmi_bipi_pull_refresh_imglist(void);
static void mmi_bipi_entry_start_get_image(void);
static void mmi_bipi_start_get_image(void);
static void mmi_bipi_refresh_download_list(void);
static void mmi_bipi_pull_exec_operation(mmi_bipi_cur_user_operation_enum oper_type);
static void mmi_bipi_pull_abort_getting_images_operation(void);
static void mmi_bipi_pull_connect_cancel(void);
static S32 mmi_bipi_pull_get_img_handle_from_index(S32 index, S8 *img_handle);
static void mmi_bipi_pull_entry_canceling(void);
static void mmi_bipi_pull_entry_imglist_browser(void);
static void mmi_bipi_pull_entry_imglist_option(void);
static void mmi_bipi_pull_entry_getting_img(void);
static void mmi_bipi_pull_entry_getting_imgprop(void);
static void mmi_bipi_pull_entry_getting_imgthm(void);
static void mmi_bipi_pull_entry_refreshing_scr(void);
static void mmi_bipi_pull_entry_img_detail(void);
static void mmi_bipi_pull_entry_preview_thumbnail(void);
static void mmi_bipi_pull_entry_exit_confirm_scr(void);
static void mmi_bipi_pull_entry_exit_confirm_scr_LSK(void);
static void mmi_bipi_pull_entry_disconnecting(void);
static void mmi_bipi_pull_imglist_highlight_hdlr(S32 index);
static void mmi_bipi_pull_imglist_option_highlight_hdlr(S32 index);
static void mmi_bipi_pull_imglist_option_LSK(void);
static void mmi_bipi_pull_redraw_bk_imglist_browser();
static void mmi_bipi_pull_refresh_imglist_category(void);
static S32 mmi_bipi_pull_get_img_handle_for_display(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void mmi_bipi_pull_get_img_thm_for_display(S32 index, U8 *image_filename, S32 max_size, U16 *default_image_id);
static void mmi_bipi_pull_scr_imglist_gotten(void);
static void mmi_bipi_pull_exit_imglist_browser(void);
static void mmi_bipi_pull_exit_preview_scr(void);
static U8 mmi_bipi_pull_connecting_screen_del_cb(void *p);
static U8 mmi_bipi_pull_imglist_browser_del_cb(void *p);
static U8 mmi_bipi_pull_recving_screen_del_cb(void *p);
static void mmi_bip_history_replace(U16 out_scr, U16 in_scr);
static void mmi_bipi_pull_entry_getimage_rst_notify_scr(void);
static void mmi_bipi_pull_notify_scr_browse(void);
static void mmi_bipi_pull_build_getimage_result_string(void);
static void mmi_bipi_pull_app_mem_free(void);
static void mmi_bipi_get_obj_info(mmi_bt_recv_obj_info_struct *obj_info_p);
static void mmi_bip_request_notify_err_hdlr(UI_string_type string, mmi_event_notify_enum event_id);

static void mmi_bipi_notify_recv_err(mmi_bt_bip_error_enum cause);

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_init
 * DESCRIPTION
 *  This function is to initialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bip_init();
    mmi_bipi_init();
    mmi_bipr_init_cntx();
#ifdef __MMI_USB_SPLIT_SUPPORT__
    SetProtocolEventHandler(mmi_bt_bip_usb_mode_cnf_hdlr, MSG_ID_BT_BIP_ENTER_USB_MODE_CNF);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_deinit
 * DESCRIPTION
 *  This function is to deinitialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bip_deinit();
    mmi_bipi_deinit();
    
    srv_bip_close(mmi_bip_p->bipr_push_cntx.app_hd);
    mmi_bip_p->bipr_push_cntx.app_hd = 0;
    
}

#define MMI_BIP_PUSH_RESPONDER

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_disconnect_client
 * DESCRIPTION
 *  This function is to deactivate the BIP application
 * PARAMETERS
 *  bd_addr         [IN]        
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_disconnect_client(srv_bt_cm_bt_addr bd_addr, U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIPS_DISCONNECT_CLIENT, cm_conn_id);
    
    //mmi_bip_p->bipr_push_cntx.disconn_from_cm = MMI_TRUE;
    /* search the selected connection index */
    srv_bipr_disconn_client(mmi_bip_p->bipr_push_cntx.app_hd, cm_conn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_deinit
 * DESCRIPTION
 *  This function is to deinitialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 event_mask;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_bip_p->bipr_push_cntx.cur_recv_cnt = 0;
    mmi_bip_p->bipr_push_cntx.total_recv_cnt = 0;
    mmi_bip_p->bipr_push_cntx.app_hd = 0;
    mmi_bip_p->bipr_push_cntx.recv_drv = 0;

	mmi_bip_p->bipr_push_cntx.app_hd = srv_bip_open(SRV_BIP_RESPONDER_ROLE);

    if (mmi_bip_p->bipr_push_cntx.app_hd < 0)
        return;
    
    event_mask = SRV_BIP_EVENT_START |
                SRV_BIP_EVENT_STOP |
                SRV_BIP_EVENT_AUTHORIZE_NOTIFY |
                SRV_BIP_EVENT_CONN_NOTIFY |
                SRV_BIP_EVENT_DISCONN_NOTIFY |
                SRV_BIP_EVENT_GET_CAPABILITY_NOTIFY |
                SRV_BIP_EVENT_RECV_NOTIFY;

    srv_bip_set_notify(mmi_bip_p->bipr_push_cntx.app_hd, event_mask, (bt_notify) mmi_bipr_event_hdlr);
    	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_event_hdlr
 * DESCRIPTION
 *  This function is deactivate BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_bipr_event_hdlr(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_hd <= 0)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    if ( srv_hd == mmi_bip_p->bipr_push_cntx.app_hd)
    {
        switch(event_id)
        {
            case SRV_BIP_EVENT_START:
                mmi_bipr_start_ind_hdlr(para);
                break;

            case SRV_BIP_EVENT_STOP:
                mmi_bipr_stop_ind_hdlr(para);
                break;

            case SRV_BIP_EVENT_AUTHORIZE_NOTIFY:
                mmi_bipr_authorize_ind_hdlr(para);
                break;

            case SRV_BIP_EVENT_CONN_NOTIFY:
                mmi_bipr_connect_ind_hdlr(para);
                break;

            case SRV_BIP_EVENT_DISCONN_NOTIFY:
                mmi_bipr_disconn_ind_hdlr(para);
                break;

            case SRV_BIP_EVENT_RECV_NOTIFY:
                mmi_bipr_recv_ind_hdlr(para);
                break;

            default:
                break;
        }

        return SRV_BIP_RESULT_OK;
    }
    return SRV_BIP_RESULT_INVALID_PARAM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_start_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_stop_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);

    srv_bip_close(mmi_bip_p->bipr_push_cntx.app_hd);

    mmi_bip_p->bipr_push_cntx.app_hd = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_authorize_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_authorize_notify_struct *auth_notify = (srv_bip_authorize_notify_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* send failed response */
        srv_bipr_reject(mmi_bip_p->bipr_push_cntx.app_hd, 0xFF);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    MMIBIP_SET_FLAG(MMIBIP_AUTHORIZE_IND);
    mmi_bt_authorize_ind_notify(
        auth_notify->dev_name, 
        &(auth_notify->bt_addr),
        SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID,
        (void *)mmi_bt_bip_authorize_rsp_hdler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_connect_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_conn_notify_struct *conn_notify = (srv_bip_conn_notify_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_disconn_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_disconn_notify_struct *disconn_notify = (srv_bip_disconn_notify_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_bip_p->bipr_push_cntx.recv_hd > 0)
    {
        mmi_bt_stop_receive(mmi_bip_p->bipr_push_cntx.recv_hd, BTRECV_RET_FAIL);
    }

    if(mmi_bip_p->flag & MMIBIP_AUTHORIZE_IND)
    {
        mmi_bt_authorize_screen_close(SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
        MMIBIP_RESET_FLAG(MMIBIP_AUTHORIZE_IND);
    }
    /* delete screen if necessary */
    mmi_bipr_clear_push_scrs();
    mmi_bip_p->bipr_push_cntx.recv_drv = 0;

    if (mmi_bip_p->bipr_push_cntx.cur_recv_cnt > 0)
    {
        mmi_bip_p->bipr_push_cntx.total_recv_cnt += mmi_bip_p->bipr_push_cntx.cur_recv_cnt;

        mmi_bipr_scr_recv_img_notify();
        
        mmi_bip_p->bipr_push_cntx.cur_recv_cnt = 0;
    }

#ifdef __MMI_BT_RECV_OBJ_DETAIL__
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_BT_ACCESS_REQ, 
        mmi_bipr_entry_detail_confirm, 
        NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_start_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_recv_ind_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_recv_notify_struct *recv_notify = (srv_bip_recv_notify_struct *)para;
    //mmi_bt_bip_error_enum bip_err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIP_RECV_IND_HANDLE, recv_notify->type);
    switch(recv_notify->type)
    {
        case SRV_BIP_RECV_BEGIN:
            if (mmi_bt_receiving_disabled())
            {
                mmi_bipr_reject_file();
                return;
            }
            mmi_bip_p->bipr_push_cntx.conn_id = recv_notify->conn_id;

            mmi_bip_p->bipr_push_cntx.detail.total_len = recv_notify->u.detail.total_len;
            
        #ifdef __MMI_BT_RECV_OBJ_DETAIL__
            
            srv_bip_truncate_obj_name(
                mmi_bip_p->bipr_push_cntx.detail.name, 
                recv_notify->u.detail.name, 
                (MAX_IMG_DETAIL_NAME + 1) * ENCODING_LENGTH, 
                MMI_FALSE);
        
            mmi_bip_p->bipr_push_cntx.detail.encoding = recv_notify->u.detail.encoding;
            
            mmi_bip_p->bipr_push_cntx.recv_drv = 0;
            mmi_bipr_detail_confirm_hdlr();
        #else
            mmi_wcscpy(mmi_bip_p->bipr_push_cntx.detail.name, recv_notify->u.detail.name);

            mmi_bipr_accept_file();

        #endif
            break;

        case SRV_BIP_RECV_READY:
            mmi_wcscpy(mmi_bip_p->bipr_push_cntx.detail.name, recv_notify->u.detail.name);
            mmi_bip_p->bipr_push_cntx.detail.total_len = recv_notify->u.detail.total_len;

            mmi_bipr_accept_file();
            
            break;

        case SRV_BIP_RECV_SUCCESS:
            if (mmi_bip_p->bipr_push_cntx.recv_hd > 0)
            {
                mmi_bt_stop_receive(mmi_bip_p->bipr_push_cntx.recv_hd, BTRECV_RET_SUCC);
            }
            
            break;

        case SRV_BIP_RECV_FAIL:
            if (mmi_bip_p->bipr_push_cntx.recv_hd > 0)
            {
                mmi_bt_stop_receive(mmi_bip_p->bipr_push_cntx.recv_hd, recv_notify->u.err_code);
            }

            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_accept_file
 * DESCRIPTION
 *  This function is to accept a file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_accept_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info obj;
    bt_recv_storage storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIPR_ACCEPT_FILE);
    StopTimer(BT_PROG_UPDATE_TIMER);

    obj.name = (WCHAR *)mmi_bip_p->bipr_push_cntx.detail.name;
    obj.size = mmi_bip_p->bipr_push_cntx.detail.total_len;
    obj.type = MIME_TYPE_IMAGE;
    obj.mime = NULL;

    MMI_BIP_LOG_PATH(mmi_bip_p->bipr_push_cntx.detail.name);


    storage.drive = mmi_bip_p->bipr_push_cntx.recv_drv;
    storage.folder = NULL;  
    
    mmi_frm_scrn_set_leave_proc(
                mmi_bip_p->bipr_push_cntx.gid ,
                SCR_BIP_RECV_FILE_CONFIRM,
                (mmi_proc_func) NULL);
    mmi_frm_group_close(mmi_bip_p->bipr_push_cntx.gid);
            
    mmi_bip_p->bipr_push_cntx.recv_hd = mmi_bt_start_receive(
                                            mmi_bipr_recv_notify_hdlr,
                                            &obj,
                                            &storage,
                                            BTRECV_OPT_BKGOUND);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_reject_file
 * DESCRIPTION
 *  This function is to reject a file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_reject_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIPR_REJECT_FILE);
    StopTimer(BT_PROG_UPDATE_TIMER);

    /* Send failed connect response to OBEX task */
    srv_bipr_reject(mmi_bip_p->bipr_push_cntx.app_hd, mmi_bip_p->bipr_push_cntx.conn_id);

    mmi_frm_scrn_set_leave_proc(
            mmi_bip_p->bipr_push_cntx.gid ,
            SCR_BIP_RECV_FILE_CONFIRM,
            (mmi_proc_func) NULL);

    mmi_frm_group_close(mmi_bip_p->bipr_push_cntx.gid);
    
    //mmi_bip_delete_screen(SCR_BIP_RECV_FILE_CONFIRM);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_recv_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd: handle
 *  event: recv event
 *  retval: return success or failed
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_recv_notify_hdlr(S32 hd, U32 event, S32 retval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bip_error_enum bip_err;
    U16 recv_path[MMI_BIP_RECV_FOLDER];
    U16 ucs_drv[2] = {0};
    U8 asc_drv[2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case BTRECV_EV_START:
            if (retval == BTRECV_RET_SUCC)
            {
                mmi_bt_get_receive_info(hd, (void *)recv_path, BTRECV_INFO_STORAGE);

                if (mmi_bip_p->bipr_push_cntx.recv_drv == 0)
                {
                    ucs_drv[0] = recv_path[0];
                    mmi_ucs2_to_asc((S8 *)asc_drv, (S8 *)ucs_drv);
                    mmi_bip_p->bipr_push_cntx.recv_drv = asc_drv[0];
                }

                srv_bipr_accept(
                    mmi_bip_p->bipr_push_cntx.app_hd, 
                    mmi_bip_p->bipr_push_cntx.conn_id,
                    recv_path);
            }
            else
            {
                srv_bipr_reject(mmi_bip_p->bipr_push_cntx.app_hd, mmi_bip_p->bipr_push_cntx.conn_id);
                
                switch(retval)
                {
                    case BTRECV_RET_MSDC_MISSED:
                        bip_err = MMI_BIP_ERR_MEDIA_CHANGED;
                        break;

                    case BTRECV_RET_MEMORY_FULL:
                        bip_err = MMI_BIP_ERR_DISK_FULL;
                        break;
                        
                    default:
                        bip_err = MMI_BIP_ERR_FILE_WRITE_FAIL;
                        break;
                }
                
                if (bip_err != MMI_BIP_ERR_FILE_WRITE_FAIL)
                {
                    mmi_bipr_notify_recv_err(bip_err);
                }
                
            }
            break;
            
        case BTRECV_EV_DONE:
          
            mmi_bip_p->bipr_push_cntx.recv_hd = 0;
            
            if (retval == BTRECV_RET_SUCC)
            {
                mmi_bt_get_receive_info(hd, (void *)mmi_bip_p->bipr_push_cntx.recv_path, BTRECV_INFO_OBJ_FLDR);
								mmi_bip_p->bipr_push_cntx.cur_recv_cnt ++;
            }
            else
            {
                if (retval == MMI_BIP_PARTIAL_CONTENT || retval == BTRECV_RET_USER_ABORT)
                {
                    return;
                }
                
                if (mmi_bip_p->bipr_push_cntx.cur_recv_cnt == 0)
                {
                    if (retval == BTRECV_RET_MSDC_MISSED)
                    {
                        bip_err = MMI_BIP_ERR_MEDIA_CHANGED;
                    }
                    else if (retval == BTRECV_RET_MEMORY_FULL)
                    {
                        bip_err = MMI_BIP_ERR_DISK_FULL;
                    }
                    else if (retval == BTRECV_RET_FAIL)
                    {
                    		bip_err = MMI_BIP_RECV_ERR;
                    }
                    else if (retval == BTRECV_RET_PENDING)
                    {
                        bip_err = MMI_BIP_ERR_FILE_WRITE_FAIL;
                    }
                    else
                    {
                        bip_err = retval;
                    }
                    
                    if (bip_err == MMI_BIP_ERR_DISK_FULL || 
                        bip_err == MMI_BIP_ERR_FS_WRITE_PROTECTION || 
                        bip_err == MMI_BIP_ERR_DRM_NO_RIGHTS ||
                        bip_err == MMI_BIP_ERR_FS_DEVICE_BUSY ||
                        bip_err == MMI_BIP_ERR_ROOT_DIR_FULL ||
                        bip_err == MMI_BIP_ERR_MEDIA_CHANGED ||
                        bip_err == MMI_BIP_RECV_ERR)
                    {
                        mmi_bipr_notify_recv_err(bip_err);
                    }
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                }
            }
            break;
            
        default:
            break;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_bip_authorize_rsp_hdler(srv_bt_cm_bt_addr *bd_addr,U32 profile_id, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIP_AUTHORIZE_RSP, result);
    
    if (profile_id == SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID)
    {
        MMIBIP_RESET_FLAG(MMIBIP_AUTHORIZE_IND);
        if (result)
        {  
            srv_bipr_accept(mmi_bip_p->bipr_push_cntx.app_hd, 0xFF, NULL);
        }
        else
        {
            srv_bipr_reject(mmi_bip_p->bipr_push_cntx.app_hd, 0xFF);
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_notify_recv_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_notify_recv_err(mmi_bt_bip_error_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 * notify_str = NULL;
    mmi_event_notify_enum event_id = MMI_EVENT_FAILURE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIP_NOTIFY_RECV_ERR, cause);

#ifdef __USB_IN_NORMAL_MODE__

    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* usb mode: don't popup */
        return;
    }
#endif

    switch (cause)
    {
        case MMI_BIP_ERR_DISK_FULL:
            notify_str = (U8 *)GetString(STR_GLOBAL_MEMORY_FULL);
            break;

        case MMI_BIP_ERR_ROOT_DIR_FULL:
            notify_str = (U8 *)GetString((U16)srv_fmgr_fs_error_get_string(FS_ROOT_DIR_FULL));
            break;

        case MMI_BIP_ERR_FILE_OPEN_FAIL:
            notify_str = (U8 *)GetString(STR_BIP_OPEN_FILE_FAIL);
            break;

        case MMI_BIP_ERR_FILE_WRITE_FAIL:
            notify_str = (U8 *)GetString(STR_BT_WRITE_FILE_FAIL);
            break;

        case MMI_BIP_ERR_FILE_READ_FAIL:
            notify_str = (U8 *)GetString(STR_BIP_READ_FILE_FAIL);
            break;

        case MMI_BIP_ERR_XML_GEN_FAIL:
            notify_str = (U8 *)GetString(STR_BIP_XML_GEN_FAIL);
            break;

        case MMI_BIP_ERR_DISCONNECTED:

            notify_str = (U8 *)GetString(STR_BIP_CON_DISCONNECTED);
            break;

        case MMI_BIP_ERR_FS_DEVICE_BUSY:
            notify_str = (U8 *)GetString((U16)srv_fmgr_fs_error_get_string(FS_DEVICE_BUSY));
            break;

        case MMI_BIP_ERR_BTCHIP_REASON:
            notify_str = (U8 *)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
            break;

        case MMI_BIP_ERR_SERVICE_UNAVAILABLE:
            notify_str = (U8 *)GetString(STR_BIP_SERVICE_UNAVAILABLE);
            break;

        case MMI_BIP_PARTIAL_CONTENT:

            notify_str = (U8 *)GetString(STR_BT_PARTIAL_CONTENT);
            event_id = MMI_EVENT_SUCCESS;
            break;

        case MMI_BIP_ERR_BROWSE_FAILED:
            notify_str = (U8 *)GetString(STR_BIP_BROWSE_FAILED);
            break;

        case MMI_BIP_ERR_OUT_OF_MEMORY:
            notify_str = (U8 *)GetString(STR_BIP_OUT_OF_MEMORY);
            break;

        case MMI_BIP_ERR_TIMEOUT:
            notify_str = (U8 *)GetString(STR_BIP_REQ_TIMEOUT);
            break;

        case MMI_BIP_ERR_MEDIA_CHANGED:
            notify_str = (U8 *)GetString(STR_BT_NO_CARD);
            break;
    
        case MMI_BIP_ERR_XML_PARSE_FAIL:
            notify_str = (U8 *)GetString(STR_BIP_XML_PARSE_FAILED);
            break;
            
        case MMI_BIP_ERR_FSQUOTA_FULL:
            notify_str = (U8 *)GetString(STR_BIP_FSQUOTA_FULL);
            break;

        /* OBEX error code */
        case MMI_BIP_ERR_NOT_FOUND:
            notify_str = (U8 *)GetString(STR_BIP_NOT_FOUND);
            break;

        case MMI_BIP_ERR_FORBIDDEN:
            notify_str = (U8 *)GetString(STR_BIP_FORBIDDEN);
            break;

        case MMI_BIP_ERR_REQUEST_TIME_OUT:
            notify_str = (U8 *)GetString(STR_BIP_REQ_TIMEOUT);
            break;
    
        case MMI_BIP_ERR_BAD_REQUEST:            
            notify_str = (U8 *)GetString(STR_BIP_BAD_REQUEST);
            break;
    
        case MMI_BIP_ERR_UNAUTHORIZED:
            notify_str = (U8 *)GetString(STR_BIP_UNAUTHORIZED);
            break;

        case MMI_BIP_ERR_METHOD_NOT_ALLOWED:
            notify_str = (U8 *)GetString(STR_BIP_METHOD_NOT_ALLOWED);
            break;

        case MMI_BIP_ERR_NOT_ACCEPTABLE:
            notify_str = (U8 *)GetString(STR_GLOBAL_UNFINISHED);
            break;

        case MMI_BIP_ERR_UNSUPPORT_MEDIA_TYPE:
            notify_str = (U8 *)GetString(STR_BIP_UNSUPPORT_MEDIA_TYPE);
            break;

        case MMI_BIP_ERR_INTERNAL_SERVER_ERR:
            notify_str = (U8 *)GetString(STR_BIP_INTERNAL_SERVER_ERR);
            break;

        case MMI_BIP_ERR_NO_FILES_RECEIVED:
            notify_str = (U8 *)GetString(STR_GLOBAL_UNFINISHED);
            break;

        case MMI_BIP_ERR_FS_WRITE_PROTECTION:    
            notify_str = (U8 *)GetString((U16)srv_fmgr_fs_error_get_string(FS_WRITE_PROTECTION));
            break;
    
        case MMI_BIP_ERR_REQ_URL_TOO_LARGE:
            notify_str = (U8 *)GetString((U16)srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR));
            break;
    
        case MMI_BIP_ERR_DRM_NO_RIGHTS:    
            notify_str = (U8 *)GetString(STR_BT_DRM_PROHIBITED);
            break;
         
         case MMI_BIP_ERR_CONFLICT:
            notify_str = (U8 *)GetString(STR_BIP_CURRENT_UNAVAILABLE);
            break;
        case MMI_BIP_RECV_ERR:
        		notify_str = (U8 *)GetString(STR_BT_RECEIVE_FAIL);
        		break;
    
        default:
            notify_str = (U8 *)GetString(STR_GLOBAL_UNFINISHED);
            break;

    }

    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,event_id ,(UI_string_type) notify_str);
}


#define MMI_BIP_COMMON_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bip_print_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sz                  [IN]        
 *  tmp_str             [?]         
 *  b_print_0byte       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bip_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sz > 1024 * 1024)
    {
        sz = sz / 1024;
        kal_wsprintf(tmp_str, "%d.%dMB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 1024)
    {
        kal_wsprintf(tmp_str, "%d.%dKB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 0)    /* less than 1024 */
    {
        kal_wsprintf(tmp_str, "%dB", (U16) (sz));
    }
    else if (b_print_0byte)
    {
        kal_wsprintf(tmp_str, "%dB", 0);
    }
    else
    {
        tmp_str[0] = 0;
        tmp_str[1] = 0;
    }
}



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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_WEBCAM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_responder_received_folder
 * DESCRIPTION
 *  This function is to get BIP responder received folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 * mmi_bt_bip_get_server_received_folder(void)
{
    return (S8*)(mmi_bip_p->bipr_push_cntx.recv_path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_recv_images_cnt
 * DESCRIPTION
 *  This function is to get received files count.
 *  
 *  PARAMETERS: 
 *  void
 *  RETURNS: 
 * received file counter.
 *****************************************************************************/
U32 mmi_bt_bip_get_recv_images_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIP_GET_RECV_IMG_CNT,mmi_bip_p->bipr_push_cntx.total_recv_cnt);
    return mmi_bip_p->bipr_push_cntx.total_recv_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_set_recv_images_cnt
 * DESCRIPTION
 *  This function is to set received files count.
 *  
 *  PARAMETERS: 
 *  cnt     [IN]        
 *  RETURNS: 
 *  received file counter.
 *****************************************************************************/
void mmi_bt_bip_set_recv_images_cnt(U32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BIP_SET_RECV_IMG_CNT,cnt);
    mmi_bip_p->bipr_push_cntx.total_recv_cnt = cnt;
}

#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_USB_SPLIT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_enter_usb_mode_hdlr
 * DESCRIPTION
 *  This function process to compose string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_bip_enter_usb_mode_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flag = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bipi_usb_mode_check();
    
    if (srv_bipr_is_working())
    {
        srv_bipr_disconn_client(mmi_bip_p->bipr_push_cntx.app_hd, 0);
        srv_bip_send_cancel(flag);
        srv_usb_block_event(MSG_ID_BT_BIP_ENTER_USB_MODE_CNF);
    }
    mmi_bt_bip_set_recv_images_cnt(0);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_usb_mode_cnf_hdlr
 * DESCRIPTION
 *  This function process to compose string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_bip_usb_mode_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_USB_MODE_CNF_HDLR);

    /* delete the tmp receiving file */

    /* responder */
    mmi_bipi_usb_mode_cnf_hdlr();

    if (mmi_bip_p->bipr_push_cntx.recv_hd > 0)
    {
        mmi_bt_stop_receive(mmi_bip_p->bipr_push_cntx.recv_hd, BTRECV_RET_USER_ABORT);
    }
    
    srv_usb_unblock_event(MSG_ID_BT_BIP_ENTER_USB_MODE_CNF);
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_usb_mode_check
 * DESCRIPTION
 *  This function process to check usb mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_bip_usb_mode_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL b_check = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_USB_MODE_CHECK);

    /* USB will call this check-func two times continually.
     * At the second time, if check-func return TRUE, 
     * the cnf-hdlr will be called.
     */
     b_check = mmi_bipi_usb_mode_check();
    if (srv_bipr_is_working())
    {
        b_check = MMI_TRUE;
        srv_bipr_disconn_client(mmi_bip_p->bipr_push_cntx.app_hd, 0);
    }
    mmi_bt_bip_set_recv_images_cnt(0);
    MMI_BIP_LOG1(MMI_BIP_USB_MODE_CHECK_RETURN, b_check);
    return b_check;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_usb_mode_cnf_hdlr
 * DESCRIPTION
 *  This function process to compose string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_usb_mode_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_USB_MODE_CNF_HDLR);

    /* delete the tmp receiving file */

    /* responder */
    mmi_bipi_usb_mode_cnf_hdlr();

    if (mmi_bip_p->bipr_push_cntx.recv_hd > 0)
    {
        mmi_bt_stop_receive(mmi_bip_p->bipr_push_cntx.recv_hd, BTRECV_RET_USER_ABORT);
    }
}
#endif
#else
mmi_ret mmi_bt_bip_enter_usb_mode_hdlr(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_server_pause_fs_operation
 * DESCRIPTION
 *  This function process to pause fs operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_server_pause_fs_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_PAUSE_FS_OPER);  
    mmi_bip_p->bipr_push_cntx.pause_fs_oper = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_server_continue_fs_operation
 * DESCRIPTION
 *  This function process to continue fs operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_server_continue_fs_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_CONTINUE_FS_OPER);
    mmi_bip_p->bipr_push_cntx.pause_fs_oper = MMI_FALSE;
    
#ifdef __BIP_PULL_SUPPORT__
    if (srv_bip_p->bipr_cntx.state == MMI_BIPR_STATE_CONSTRUCTING_IMGLIST)
    {
        mmi_bt_bipr_send_get_imglist_ind_msg_to_self();
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_server_is_working
 * DESCRIPTION
 *  This function process to return status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bip_is_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bip_is_run();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_is_receiving
 * DESCRIPTION
 *  This function process to return status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bip_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bip_is_receiving();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_server_is_working
 * DESCRIPTION
 *  This function process to return status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bip_server_is_working(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bipr_is_working();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_client_is_idle
 * DESCRIPTION
 *  This function process to return status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bip_client_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_bipi_is_idle();
}



#define MMI_BIP_PUSH_SCREEN
/*****************************************************************************
 * FUNCTION
 *  mmi_bip_compose_string
 * DESCRIPTION
 *  This function process to compose string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 *mmi_bip_compose_string(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *string = mmi_bip_notify_str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {  
        case MMI_BIPI_ABORTING_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_GLOBAL_CANCELLING) );
            break;
            
        case MMI_BIPI_CONNECTING_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_GLOBAL_CONNECTING) );
            break;
            
        case MMI_BIPI_DISCONNECTING_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_DISCONNECTING) );
            break;
    #ifdef __BIP_PULL_SUPPORT__          
        case MMI_BIPI_EXIT_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_CON_EXIT) );
            break;
            
        case MMI_BIPI_GETTING_IMGPROP_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_GETTING_IMGPROP) );
            break;
            
        case MMI_BIPI_GETTING_IMGTHM_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_GETTING_IMGTHM) );
            break;
            
        case MMI_BIPI_REFRESH_IMGLIST_NOTY:
            mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_REFRESHING) );
            break;
     #endif
        case MMI_BIPR_IMG_RECV_NOTY:
            {             
                //U16 tmp = 0; U16 *tmp_str = L"\\";
                U32 len;  
                mmi_wcscpy(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_RECV_FILE_IND) );   
                mmi_wcscat(mmi_bip_notify_str,  (U16 *)L" '"); 
                len = mmi_wcslen(mmi_bip_notify_str);
                mmi_bt_get_fldr_name(&mmi_bip_notify_str[len], mmi_bip_p->bipr_push_cntx.recv_path);
                mmi_wcscat(mmi_bip_notify_str,  (U16 *) L"' "); 
                mmi_wcscat(mmi_bip_notify_str, (U16 *)GetString(STR_BIP_NOTY_RECV_FOLDER));
            }
            break;

        default:
            MMI_ASSERT(0);
            return NULL;
                
    }
    return string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_scr_recv_img_notify
 * DESCRIPTION
 *  notify user that an image has been received
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_scr_recv_img_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIP_SCR_RECV_IMG_IND);

    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,MMI_EVENT_SUCCESS ,(UI_string_type)mmi_bip_compose_string(MMI_BIPR_IMG_RECV_NOTY));

    if (mmi_idle_is_active() || GetActiveScreenId() == SCR_OPP_NOTY_FILE_RECV)
    {
        mmi_idle_display();
    }

}


/*****************************************************************************
 * FUNCTION
mmi_bipr_clear_push_scrs * DESCRIPTION
 *  Clear responder screen on disconnection
 * PARAMETERS
 *  cause              
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_clear_push_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_PROG_UPDATE_TIMER);
    mmi_bip_delete_screen(SCR_BIP_RECV_FILE_CONFIRM);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bip_delete_screen
 * DESCRIPTION
 *  This function is to delete screen
 * PARAMETERS
 *  out_scr     [IN]        
 *  in_scr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bip_delete_screen(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bip_p->bipr_push_cntx.gid != 0)
    {
        mmi_frm_scrn_set_leave_proc(
            mmi_bip_p->bipr_push_cntx.gid ,
            scrn_id,
            (mmi_proc_func) NULL);
    }
    if (scrn_id == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close(mmi_bip_p->bipr_push_cntx.gid, scrn_id);
    }
}

#ifdef __MMI_BT_RECV_OBJ_DETAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_compose_recv_img_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 * mmi_bipr_compose_img_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* str_info = mmi_bip_notify_str;
    S8 tmp_str[32]; /* convert tmp_str to UCS2*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy( str_info, (U16 *)GetString(STR_BT_OBJ_TILE));
    mmi_wcscat(str_info, (U16 *)GetString(STR_BT_QUESTION_MARK));
    mmi_wcscat(str_info, (U16 *) L"\r\n\r\n");
    /* name */
    mmi_wcscat(str_info, (U16 *) GetString(STR_BT_OBJ_NAME));

    mmi_wcscat(str_info, (U16 *) mmi_bip_p->bipr_push_cntx.detail.name);

    mmi_wcscat(str_info, (U16 *) L"\r\n");

    /* encoding */
    mmi_wcscat(str_info, (U16 *) GetString(STR_BT_OBJ_TYPE));

    switch (mmi_bip_p->bipr_push_cntx.detail.encoding)
    {
        case BT_BIP_IMG_TYPE_JPEG:
            mmi_wcscat(str_info, (U16 *) L"JPEG");
            break;
            
        case BT_BIP_IMG_TYPE_GIF:
            mmi_wcscat(str_info, (U16 *) L"GIF");
            break;
            
        case BT_BIP_IMG_TYPE_WBMP:
            mmi_wcscat(str_info, (U16 *) L"WBMP");
            break;
            
        case BT_BIP_IMG_TYPE_BMP:
            mmi_wcscat(str_info, (U16 *) L"BMP");
            break;
            
        case BT_BIP_IMG_TYPE_PNG:
            mmi_wcscat(str_info, (U16 *) L"PNG");
            break;
            
        default:
            mmi_wcscat(str_info, (U16 *)GetString(STR_BIP_UNKNOWN));
            break;            
    }
    mmi_wcscat(str_info, (U16 *) L"\r\n");
    
    /* size */
    mmi_wcscat(str_info, (U16 *) GetString(STR_BT_OBJ_SIZE));
    mmi_bip_print_size(mmi_bip_p->bipr_push_cntx.detail.total_len, (U16*) tmp_str, MMI_TRUE);

    mmi_wcscat(str_info, (U16 *) tmp_str); 
    return str_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_detail_confirm_hdlr
 * DESCRIPTION
 *  defer recv_file confirm screeen when incoming call is on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_detail_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BIPR_DETAIL_CONFIRM_HDLR);
    
    mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BT_ACCESS_REQ,
            MMI_EVENT_INFO,
            mmi_bipr_entry_detail_confirm,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_entry_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bipr_entry_detail_confirm(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_bip_p->bipr_push_cntx.gid = mmi_frm_group_create(
                                        GRP_ID_ROOT, 
                                        GRP_ID_BIP_OBJ_DETAIL, 
                                        mmi_bipr_detail_confirm_proc, 
                                        NULL);

    mmi_frm_group_enter(mmi_bip_p->bipr_push_cntx.gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_bipr_entry_detail_confirm_scr();

    return MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_entry_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_entry_detail_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* construct image detail info */
   
    if (mmi_frm_scrn_enter(
            mmi_bip_p->bipr_push_cntx.gid, 
            SCR_BIP_RECV_FILE_CONFIRM, 
            mmi_bipr_exit_detail_confirm_scr, 
            mmi_bipr_entry_detail_confirm_scr, 
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
        mmi_bipr_compose_img_detail();
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        
        ShowCategory7Screen(
            STR_GLOBAL_BLUETOOTH,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*) mmi_bip_notify_str,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_bipr_accept_file, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bipr_reject_file, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_bipr_accept_file,KEY_EVENT_UP);
        
        mmi_frm_scrn_set_leave_proc(
            mmi_bip_p->bipr_push_cntx.gid ,
            SCR_BIP_RECV_FILE_CONFIRM,
            (mmi_proc_func) mmi_bipr_detail_confirm_scr_leave_proc);

        StartTimer(BT_PROG_UPDATE_TIMER, BIP_PUSH_IND_PROG_UPD_DUR, mmi_bipr_reject_file);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_exit_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_exit_detail_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_entry_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bipr_detail_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_bip_p->bipr_push_cntx.gid = 0;
            break;

        case EVT_ID_GROUP_INACTIVE:
            
            break;
            
        default:
            break;
          
    }

    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_obj_detail_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bipr_detail_confirm_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            MMI_BIP_LOG(MMI_BIP_RECV_FILE_CONFIRM_DEL_CB);
            mmi_bipr_reject_file();
            break;

        default:
            break;
    }

    return MMI_RET_OK;

}
#endif


#ifdef __BIP_PULL_SUPPORT__


#define MMI_BIP_PULL_INITIATOR_FUNC
/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bipi_pull_get_image(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_IMAGE, srv_bip_p->bipi_cntx.state);

    srv_bip_p->bipi_cntx.cur_img_gotten_size = 0;

    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_CONNECTED:
            mmi_bipi_send_get_img_req(img_handle);
            return MMI_TRUE;

        default:
            mmi_bipi_notify_recv_err(MMI_BIP_ERR_INVALID_STATUS);
            return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_send_get_imglist_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_send_get_imglist_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_req_struct *req;
    bt_bip_img_info_struct desc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGLIST_REQ,srv_bip_p->bipi_cntx.state);
    
    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        mmi_bipi_notify_recv_err(MMI_BIP_ERR_INVALID_STATUS);
        
        return;
    }

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_GETTING_IMGLIST);

    req = (bt_bip_get_img_list_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_list_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
#if 0
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    req->start_index = 0;
    req->max_img_handle_number = BT_BIP_MAX_RETURNED_IMG_HANDLES;       // 0xFFFF; /* uint16 */
#endif /* 0 */ 

    memset(&desc, 0, sizeof(bt_bip_img_info_struct));
    desc.define_pixel_with_range = KAL_FALSE;

    req->img_list_descriptor = desc;

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_LIST_REQ, req);

    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_SEND_IMGLIST_REQ/*MMI_BIP_OPER_GET_IMGLIST*/;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_send_get_img_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_send_get_img_req(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_req_struct *req;
    S32 retval;
    //mmi_bt_bip_error_enum bip_error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMG_REQ,srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        return;
    }
    retval = mmi_bt_gen_temp_obj(
                    srv_bip_p->bipi_cntx.img_path,
                    mmi_bip_p->pull_recv_drive);

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
#endif
    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_GETTING_IMG);

    srv_bip_p->bipi_cntx.cur_img_gotten_size = 0;
    srv_bip_p->bipi_cntx.cur_img_total_size = RECV_UNKNOWN_SIZE;
    memcpy(srv_bip_p->bipi_cntx.img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_GET_IMG;

    req = (bt_bip_get_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    mmi_ucs2cpy((S8*) req->img_path, (S8*) srv_bip_p->bipi_cntx.img_path);

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_send_get_imgprop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_send_get_imgprop_req(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGPROP_REQ,srv_bip_p->bipi_cntx.state);
    
    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        return;
    }

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_GETTING_IMGPROP);

    req = (bt_bip_get_img_prop_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_prop_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_PROP_REQ, req);

    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_GET_IMGPROP;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_send_get_imgthm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_send_get_imgthm_req(S8 *img_handle)
{
#ifdef __MMI_BIP_USE_GETTHM_FUNC_TO_GET_THM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_linked_thumbnail_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGTHM_REQ,srv_bip_p->bipi_cntx.state);
    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        return;
    }

    req =
        (bt_bip_get_linked_thumbnail_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_linked_thumbnail_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    mmi_ucs2cpy((S8*) req->img_path, srv_bip_p->bipi_cntx.thm_path);
    mmi_ucs2cat((S8*) req->img_path, (S8*) BIP_PULL_I_TMP_FILENAME);

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_REQ, req);

#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGTHM_REQ,srv_bip_p->bipi_cntx.state);
    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        return;
    }

    srv_bip_p->bipi_cntx.cur_img_gotten_size = 0;
    srv_bip_p->bipi_cntx.cur_img_total_size = 0;

    req = (bt_bip_get_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    mmi_ucs2cpy((S8*) req->img_path, (S8*) srv_bip_p->bipi_cntx.thm_path);
    mmi_ucs2cat((S8*) req->img_path, (S8*) BIP_PULL_I_TMP_FILENAME);
    
    /* image descriptor */
    req->img_descriptor.encoding = BT_BIP_IMG_TYPE_JPEG;
    req->img_descriptor.specified_pixel_width = BT_BIP_THM_WIDTH;
    req->img_descriptor.specified_pixel_height= BT_BIP_THM_HEIGHT;

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_REQ, req);

#endif

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_GETTING_THM);
    memcpy(srv_bip_p->bipi_cntx.img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_send_find_cont_msg_to_self
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_send_get_imglist_ind_msg_to_self(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_ind_struct* ind = (bt_bip_get_img_list_ind_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_list_ind_struct)); 
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ind->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;
    memset(&(ind->img_list_descriptor), 0, sizeof(bt_bip_img_info_struct));
    ind->max_img_handle_number = 0;
    ind->start_index = 0;
    ind->latest_captured = MMI_FALSE;
    /* to identify the self msg */    
    mmi_ucs2cpy((S8 *)ind->img_list_descriptor.friendly_name, (S8*)MMI_BIP_TO_SELF_ID);

    msg.oslSrcId = MOD_MMI;
    msg.oslDestId = MOD_MMI;
    msg.oslMsgId = MSG_ID_BT_BIP_GET_IMG_LIST_IND;
    msg.oslSapId = INVALID_SAP;
    msg.oslDataPtr = (oslParaType*) ind;
    msg.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&msg);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_imglist_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_imglist_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_cnf_struct *cnf = (bt_bip_get_img_list_cnf_struct*) msg;
    mmi_bt_bip_error_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGLIST_CNF, cnf->cnf_code, srv_bip_p->bipi_cntx.state);

    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_IMGLIST)
    {
        /* send abort request because user already abort */
        return;
    }

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS || cnf->cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        memcpy(srv_bip_p->bipi_cntx.img_list_path, cnf->img_list_path, sizeof(cnf->img_list_path));
        MMI_BIP_LOG_PATH(cnf->img_list_path);

        MMI_BIP_LOG1(MMI_BT_BIP_GET_IMGLIST_NUM, cnf->img_count);

        /* img handle number in img list */
        srv_bip_p->bipi_cntx.img_handle_num_in_imglist = cnf->img_count;
        srv_bip_p->bipi_cntx.start_index += cnf->img_count - 1;
    }
    /* notify screen */
    result = mmi_bip_convert_cnf_code_to_bip_err((U8)cnf->cnf_code);
    mmi_bipi_pull_scr_get_imglist_end(result);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_img_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_img_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_cnf_struct *cnf = (bt_bip_get_img_cnf_struct*) msg;
    U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    U8 cnf_code = cnf->cnf_code;
    mmi_bip_error_enum create_rst = MMI_BIP_SUCCESS;
    mmi_bt_bip_error_enum rename_rst = MMI_BIP_SUCCESS;
    S32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMG_CNF, cnf->cnf_code, srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_IMG &&
        srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_THM)
    {
        /* send abort request because user already abort */
        return;
    }

    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMG)
    {
        mmi_ucs2cpy((S8*) tmp_file, (S8*) srv_bip_p->bipi_cntx.img_path);
    }
    else
    {
        mmi_ucs2cpy((S8*) tmp_file, (S8*) srv_bip_p->bipi_cntx.thm_path);
        
        mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
    }
        
    if (cnf->cnf_code != BT_BIP_CNF_SUCCESS)
    {
        /* delete tmp file */
        FS_Delete((U16*) tmp_file);
    }


    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMG)
    {
        if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
        {
            /* rename received image name */
            S8 dst_img_name[BIP_MAX_FILE_NAME_LEN];
            S8 *p_postfix;

            if (srv_bip_p->bipi_cntx.cur_img_total_size != RECV_UNKNOWN_SIZE)
                srv_bip_p->bipi_cntx.cur_img_gotten_size = srv_bip_p->bipi_cntx.cur_img_total_size;
            else
                srv_bip_p->bipi_cntx.cur_img_gotten_size = cnf->data_len;

            /* construct received image name */
            mmi_asc_to_ucs2((S8*) dst_img_name, (S8*) srv_bip_p->bipi_cntx.img_handle);
            p_postfix = dst_img_name + (BT_BIP_IMG_HANDLE_LEN - 1) * 2;
            /* append postfix */
            mmi_bip_get_imgfile_postfix(p_postfix, tmp_file);

            if (srv_bip_p->bipi_cntx.cur_img_gotten_size == 0)
            {
                /* 0 byte file. There is no such a file, so create it now */
                create_rst = mmi_bip_create_file(tmp_file);
                srv_bip_p->bipi_cntx.cur_img_total_size = cnf->data_len;
            }

            if (create_rst == MMI_BIP_SUCCESS)
            {
                retval = mmi_bt_release_temp_obj(
                                    srv_bip_p->bipi_cntx.img_path,
                                    (U16 *)dst_img_name,
                                    NULL);

                if ((retval >= 0) && MMIBIP_FLAG_IS_ON(MMIBIP_MASK_SUCC_RECV_FILE))
                {
                    mmi_bt_compose_recv_full_path(
                            srv_bip_p->bipi_cntx.img_path_file,
                            mmi_bip_p->pull_recv_drive,
                            (U16 *)dst_img_name);
                    mmi_bt_get_fldr_path(srv_bip_p->bipi_cntx.img_path_file, srv_bip_p->bipi_cntx.img_path_file);
                    MMIBIP_RESET_FLAG(MMIBIP_MASK_SUCC_RECV_FILE);
                }

            }
            
            if (create_rst != MMI_BIP_SUCCESS || retval < 0)
            {
                /* delete tmp file */
                FS_Delete((U16*) tmp_file);
                if (create_rst != MMI_BIP_SUCCESS)
                    cnf_code = mmi_bip_convert_bip_err_to_cnf_code(create_rst);                
                else
                    cnf_code = mmi_bip_convert_fs_err_to_bip_err(retval);
            }
        }
        
        MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);        
        srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;

        /* notify screen: gotten a image  */
        mmi_bipi_scr_get_img_cnf((U8)cnf_code);
    }
    else /* get thumbnail */
    {
        S8 dst_thm_name[BIP_MAX_FILE_NAME_LEN];
        FS_HANDLE fh;

        if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
        {
            fh = FS_Open((WCHAR*)tmp_file, FS_READ_ONLY);
            if (fh > 0)
            {
                FS_Close(fh);
            }
            else
            {
                /* 0 byte file. There is no such a file, so create it now */
                create_rst = mmi_bip_create_file(tmp_file);
            }

            if (create_rst == MMI_BIP_SUCCESS)
            {
                /* rename received thm name */
                rename_rst = mmi_bip_rename_pulled_thm(dst_thm_name);
            }
            if (create_rst != MMI_BIP_SUCCESS || rename_rst != MMI_BIP_SUCCESS)
            {
                /* delete tmp file */
                FS_Delete((U16*) tmp_file);
                if (create_rst != MMI_BIP_SUCCESS)
                    cnf_code = mmi_bip_convert_bip_err_to_cnf_code(create_rst);                
                else
                    cnf_code = mmi_bip_convert_bip_err_to_cnf_code(rename_rst);
            }
        }
        
        MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);
        srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;

        mmi_bipi_scr_get_thm_cnf((U8) cnf_code, (U8*) srv_bip_p->bipi_cntx.thm_path, (U8*)dst_thm_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_imgprop_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_imgprop_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_cnf_struct *cnf = (bt_bip_get_img_prop_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGPROP_CNF, cnf->cnf_code, srv_bip_p->bipi_cntx.state);
    //ASSERT(cnf->cm_conn_id == srv_bip_p->bipi_cntx.cm_conn_id);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_IMGPROP)
    {
        /* send abort request because user already abort */
        return;
    }

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        /* print info into string? */
        mmi_bip_p->img_encoding = cnf->native_img.encoding;
        mmi_bip_p->img_width = cnf->native_img.specified_pixel_width;
        mmi_bip_p->img_height = cnf->native_img.specified_pixel_height;
        mmi_bip_p->img_size = cnf->native_img.size;
        mmi_ucs2cpy((S8*) mmi_bip_p->img_name, (S8*) cnf->native_img.friendly_name);
    }


    mmi_bipi_get_imgprop_end((U8)cnf->cnf_code);

    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_thm_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_thm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_linked_thumbnail_cnf_struct *cnf = (bt_bip_get_linked_thumbnail_cnf_struct*) msg;
    S8 dst_thm_name[BIP_MAX_FILE_NAME_LEN];
    mmi_bt_bip_error_enum rename_rst = MMI_BIP_SUCCESS;
    U8 cnf_code = BT_BIP_CNF_SUCCESS;
    U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    mmi_bt_bip_error_enum create_rst = MMI_BIP_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_THM_CNF, cnf->cnf_code, srv_bip_p->bipi_cntx.state);

    //ASSERT(cnf->cm_conn_id == srv_bip_p->bipi_cntx.cm_conn_id);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_THM)
    {
        /* send abort request because user already abort */
        return;
    }

    /* recieved file name */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) srv_bip_p->bipi_cntx.thm_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        FS_HANDLE fh;

        fh = FS_Open((WCHAR*)tmp_file, FS_READ_ONLY);
        if (fh > 0)
        {
            FS_Close(fh);
        }
        else
        {
            /* 0 byte file. There is no such a file, so create it now */
            create_rst = mmi_bip_create_file(tmp_file);
        }

        if (create_rst == MMI_BIP_SUCCESS)
        {
            /* rename received thm name */
            rename_rst = mmi_bip_rename_pulled_thm(dst_thm_name);
        }
        if (create_rst != MMI_BIP_SUCCESS || rename_rst != MMI_BIP_SUCCESS)
        {
            /* delete tmp file */
            FS_Delete((U16*) tmp_file);
            if (create_rst != MMI_BIP_SUCCESS)
                cnf_code = mmi_bip_convert_bip_err_to_cnf_code(create_rst);                
            else
                cnf_code = mmi_bip_convert_bip_err_to_cnf_code(rename_rst);        
        }
    }
    
    if (cnf_code != BT_BIP_CNF_SUCCESS) 
    {
        /* failed */

        /* delete tmp file */
        FS_Delete((U16*) tmp_file);
    }

    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;
    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);

    /* notify screen */
    mmi_bipi_scr_get_thm_cnf((U8) cnf_code, (U8*) srv_bip_p->bipi_cntx.thm_path, (U8*)dst_thm_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_abort_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_ABORT_RSP msg
 * PARAMETERS
 *  rsp     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    MMI_BOOL b_continue_pull;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_PULL_ABORT_CNF, srv_bip_p->bipi_cntx.state,srv_bip_p->bipi_cntx.cur_oper);

    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_ABORTING:
            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);
            
            /* notify screen */
            b_continue_pull = mmi_bipi_pull_scr_aborted();

            break;

        case SRV_BIPI_STATE_DISCONNECTING:
            if (!srv_bip_p->bipi_cntx.b_disconnect_req_sent)
            {
                mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
            }
            break;

        default:
            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);

            break;
    }

    /* delete tmp file */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) srv_bip_p->bipi_cntx.img_path);
    //mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
    ret = FS_Delete((U16*) tmp_file);
        
    if (srv_bip_p->bipi_cntx.cur_oper == MMI_BIP_OPER_GET_IMG)
    {
        /* notify screen */
        mmi_bipi_pull_img_end(MMI_BIP_ERR_CANCELED_BY_USER);
    }
    else if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_DISCONNECTING)
    {
        /* disconnecting state need aborting screen */
        mmi_bipi_clear_pull_scrs();
    }
    srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_disconnect
 * DESCRIPTION
 *  This is common function to abort connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(mmi_bip_PULL_DISCONNECT, srv_bip_p->bipi_cntx.state);

    mmi_bipi_pull_connect_cancel_comm(MMI_TRUE);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_connect_cancel_comm
 * DESCRIPTION
 *  This is common function to abort connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_connect_cancel_comm(MMI_BOOL TpDisconnect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMGLIST ||
        srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_THM)
    {
        if (TpDisconnect)
        {
            mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
        }
        else
        {
            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_DISCONNECTING);
            mmi_bipi_send_abort_req(srv_bip_p->bipi_cntx.cm_conn_id);
        }
    }
    else if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_CONNECTING ||
             srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_CONNECTED)
    {
        srv_bt_cm_reg_pairing_permission(SRV_BT_CM_OBEX_IMAGING_UUID,(void*)mmi_bipi_pairing_permit);
        
        StopTimer(BT_BIP_REQ_TIMER); /* stop the connect timer */
        mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
       
        /*reslove CR MAUI_01390675*/
    }
    else
    {
        return;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_abort_getting_images
 * DESCRIPTION
 *  This is common function to abort getting object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_abort_getting_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_ABORT_GETIMG,srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMGLIST ||
        srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMG ||
        srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMGPROP ||
        srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_THM)
    {
        MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_ABORTING);
        mmi_bipi_send_abort_req(srv_bip_p->bipi_cntx.cm_conn_id);
    }
    else if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_CONNECTING)
    {
        mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
    }
    else if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_CONNECTED)
    {
        /* delete Aborting screen if present*/
        mmi_bipi_clear_pull_scrs();

        /* notify screen */
        mmi_bipi_pull_img_end(MMI_BIP_ERR_CANCELED_BY_USER);
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_exit_image_browser
 * DESCRIPTION
 *  This function is to exit image browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_exit_image_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_EXIT_IMAGE_BROWSER, srv_bip_p->bipi_cntx.state);
    
    srv_bip_p->bipi_cntx.b_user_disconnect = MMI_TRUE;

    /* Disconnect the BIP connection */
    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_GETTING_IMGLIST:
        case SRV_BIPI_STATE_GETTING_IMG:
        case SRV_BIPI_STATE_GETTING_IMGPROP:
        case SRV_BIPI_STATE_GETTING_THM:
            mmi_bipi_pull_entry_disconnecting();
            mmi_bipi_send_abort_req(srv_bip_p->bipi_cntx.cm_conn_id);
            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_DISCONNECTING);
            break;

        case SRV_BIPI_STATE_CONNECTED:
            mmi_bipi_pull_entry_disconnecting();
            mmi_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
            break;

        case SRV_BIPI_STATE_ABORTING:
            /* stop abort timer here? */
            mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
            break;

        default:
            break;
    }

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_FILE_RECV, NULL);
    DeleteScreenIfPresent(SCR_BIP_NOTY_FILE_RECV);    
}



#define MMI_BIP_PULL_RESPONDER_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_continue_ind_hdlr(bt_bip_continue_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_CONTINUE_IND, srv_bip_p->bipi_cntx.state);
    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMGLIST &&
        srv_bip_p->bipi_cntx.cur_oper == MMI_BIP_OPER_SEND_IMGLIST_REQ)
    {
        srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_GET_IMGLIST;
    }

    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_GETTING_IMGLIST:
            break;

        case SRV_BIPI_STATE_GETTING_IMGPROP:
            break;
            
        case SRV_BIPI_STATE_GETTING_THM:
            break;

        case SRV_BIPI_STATE_GETTING_IMG:

            /* update gotten_size */
            srv_bip_p->bipi_cntx.cur_img_gotten_size += ind->data_len;
            if (srv_bip_p->bipi_cntx.cur_img_total_size == RECV_UNKNOWN_SIZE)
                srv_bip_p->bipi_cntx.cur_img_total_size = ind->obj_len;

            break;

        case SRV_BIPI_STATE_ABORTING:
        case SRV_BIPI_STATE_DISCONNECTING:
            return;

        default:
            mmi_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
            return;
    }

    /* send continue rsp */
    mmi_bip_send_continue_rsp(ind->cm_conn_id, BT_BIP_CNF_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_get_imglist_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_get_imglist_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_ind_struct *ind = (bt_bip_get_img_list_ind_struct*) msg;
    bt_bip_get_img_list_rsp_struct *rsp;
    U8 cnf_code = GOEP_INTERNAL_SERVER_ERR/*BT_BIP_CNF_FAILED*/;
    U32 total_img_count = 0;
    S32 img_count = 0;
    mmi_bip_construct_imglist_ret_enum ret = MMI_BIPR_CONSTRUCT_IMGLIST_FAILED;
    mmi_bip_find_type_enum find_type = MMI_BIPR_FIND_START;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMGLIST_IND,srv_bip_p->bipr_cntx.state);

    /* check if the msg is from self */
    if (mmi_ucs2cmp((S8*)ind->img_list_descriptor.friendly_name, (S8*)MMI_BIP_TO_SELF_ID) == 0)
    {
        MMI_BIP_LOG(MMI_BT_BIP_RECV_SELF_MSG);
        if (srv_bip_p->bipr_cntx.state != MMI_BIPR_STATE_CONSTRUCTING_IMGLIST)
        {
            mmi_bipr_delete_tmp_imglist_file();
            return;
        }
        
        /* from self : to continue constructing image list */
        find_type = MMI_BIPR_FIND_CONTINUE;
        goto Construct_Continue;
    }
    
    srv_bip_p->bipr_cntx.cur_cmd = MMI_BIP_OPER_GET_IMGLIST;
    
    switch (srv_bip_p->bipr_cntx.state)
    {
        case MMI_BIPR_STATE_CONNECTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
            
        case MMI_BIPR_STATE_RECEIVING_IMG:
        case MMI_BIPR_STATE_RECEIVING_THM:
            cnf_code = GOEP_SERVICE_UNAVAILABLE/*BT_BIP_CNF_FAILED*/;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            return;
    }

    /*
     * search shared_folder for image files, 
     * *  and write img_handle & img_name into a file.
     * *  build img_list, and write img_list into file
     */
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_BIP_LOG(MMI_BT_BIP_IN_USB_IMGLIST);
        cnf_code = GOEP_SERVICE_UNAVAILABLE;

        goto SEND_GETIMGLIST_RSP;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* check if the shared folder exist */
    if (!bip_share_folder_exist())
    {
        cnf_code = GOEP_GONE;
    }
    
    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        if (ind->max_img_handle_number == 0 || ind->start_index == 0)
        {
Construct_Continue:        
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_CONSTRUCTING_IMGLIST);

            if (srv_bip_p->bipr_cntx.b_pause_fs_oper)
            {                    
                MMI_BIP_LOG(MMI_BT_BIP_FS_OPER_PAUSED);        
                return;
            }

            /* the first get: construct img list */
            
#ifdef __MMI_BIP_COMPOSE_IMGLIST_XML_IN_ADP__
            ret = mmi_bipr_construct_img_list(find_type, &total_img_count);
#else
            ret = mmi_bipr_compose_image_list_xml(find_type, &total_img_count);
#endif    
    
            if (ret == MMI_BIPR_CONSTRUCT_IMGLIST_CONTINUE)
            {
                /* send msg to self */
                mmi_bipr_send_get_imglist_ind_msg_to_self();
                /* don't send rsp msg until finished */
                return;
            }
            
            if (ret == MMI_BIPR_CONSTRUCT_IMGLIST_FAILED)
            {
                /* construction failed */
                total_img_count = 0;
            }
            srv_bip_p->bipr_cntx.img_count = total_img_count;
        }

        if (ind->start_index > 0 && 
           (ret == MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS || 
            ret == MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT))
        {
            /* Initiator want the image list, maybe partial */
            img_count = mmi_bip_get_partial_imglist(ind->start_index, ind->max_img_handle_number);
        }
        else
        {
            /* Initiator want the total image number */
            img_count = srv_bip_p->bipr_cntx.img_count;
        }

        if (ret == MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS && img_count >= 0)
        {
            cnf_code = BT_BIP_CNF_SUCCESS;
        }
        else if (ret == MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT && img_count > 0)
        {
            cnf_code = BT_BIP_PARTIAL_CONTENT;
        }
        else
        {
            cnf_code = GOEP_INTERNAL_SERVER_ERR/*BT_BIP_CNF_FAILED*/;
        }
    }

SEND_GETIMGLIST_RSP:
  
    rsp = (bt_bip_get_img_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_list_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = ind->cm_conn_id;
    rsp->cnf_code = cnf_code;
    if (cnf_code == BT_BIP_CNF_SUCCESS || cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        rsp->img_count = img_count;
        if (ind->start_index > 0)
        {
            mmi_ucs2cpy((S8*) rsp->img_list_path, (S8*) srv_bip_p->bipr_cntx.cur_img_list_path);
        }
        else
        {
            mmi_ucs2cpy((S8*) rsp->img_list_path, (S8*) srv_bip_p->bipr_cntx.img_list_path);
        }

        MMI_BIP_LOG_PATH(rsp->img_list_path);
    }

    if (cnf_code == BT_BIP_CNF_SUCCESS || cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING_LPT);
    }
    else
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_CONNECTED);
        /* delete the tmp files */
        FS_Delete((U16*)srv_bip_p->bipr_cntx.img_list_path);
        FS_Delete((U16*)srv_bip_p->bipr_cntx.cur_img_list_path);
    }

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_LIST_RSP, rsp);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_get_img_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_get_img_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_ind_struct *ind = (bt_bip_get_img_ind_struct*) msg;
    bt_bip_get_img_rsp_struct *rsp = NULL;
    U8 cnf_code = GOEP_INTERNAL_SERVER_ERR;
    U8 find_rst = GOEP_NOT_FOUND;
    int rt;
    int hFile;
    U16 img_path[SRV_FMGR_PATH_MAX_LEN];
    MMI_BOOL b_thm_gotten = MMI_FALSE;
    MMI_BOOL b_req_thm = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMG_IND,srv_bip_p->bipr_cntx.state);

    //ASSERT(srv_bip_p->bipr_cntx.cm_conn_id == ind->cm_conn_id);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case MMI_BIPR_STATE_CONNECTED:
            rsp = (bt_bip_get_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_rsp_struct));
            BIP_MEMSET(rsp);    /* memory init */

#ifdef __USB_IN_NORMAL_MODE__
            if (mmi_usb_is_in_mass_storage_mode())
            {
                MMI_BIP_LOG(MMI_BT_BIP_IN_USB_GETIMG);
                cnf_code = GOEP_SERVICE_UNAVAILABLE;
                break;
            }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

            /* check if the shared folder exist */
            if (!bip_share_folder_exist())
            {
                cnf_code = GOEP_GONE;
                break;
            }
            
            strcpy((char*)srv_bip_p->bipr_cntx.cur_img_handle, (char*)ind->img_handle);

            find_rst = mmi_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) rsp->img_path, NULL);

            if (find_rst == BT_BIP_CNF_SUCCESS)    /* find filename */
            {
                /* check if this file exists */
                hFile = FS_Open((U16 *)rsp->img_path, FS_READ_ONLY);
                if (hFile < 0)
                {      
                    if (hFile == FS_ACCESS_DENIED)
                    {
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 22);
                        cnf_code = GOEP_CONFLICT;
                    }
                    else                     /* not find */
                    {
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 23);
                        cnf_code = GOEP_NOT_FOUND;
                    }
                    break;
                }
                else
                {
                    rt = FS_Close(hFile);
                    MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, rt);
                }
            
                MMI_BIP_LOG_PATH(rsp->img_path);

            #if defined(__DRM_SUPPORT__)
                /* drm check: if allow to forward out */
                if (!DRM_interdev_movable(0, (kal_wchar*) rsp->img_path))
                {
                    MMI_BIP_LOG(MMI_BT_BIP_DRM_FORBIDDEN);
                    cnf_code = GOEP_METHOD_NOT_ALLOWED;
                    break;
                }
            
                if (!DRM_validate_permission(0, (kal_wchar *)rsp->img_path, DRM_PERMISSION_DISPLAY))
                {
                    MMI_BIP_LOG(MMI_BT_BIP_DRM_VALIDATE_PREMISSION);
                    
                    cnf_code = GOEP_METHOD_NOT_ALLOWED;
                    break;
                }

            #endif /* defined(__DRM_SUPPORT__) */ 
                    /* check if thm is requested */
                if (ind->img_descriptor.encoding == BT_BIP_IMG_TYPE_JPEG && 
                    ind->img_descriptor.specified_pixel_width == BT_BIP_THM_WIDTH && 
                    ind->img_descriptor.specified_pixel_height == BT_BIP_THM_HEIGHT)
                {
                    /* thm is requested */
                    MMI_BIP_LOG(MMI_BT_BIP_THM_IS_REQUESTED);
                    b_req_thm = MMI_TRUE;

                    mmi_ucs2cpy((S8*) img_path, (S8*) rsp->img_path);

                    /* call api to get thumbnail of this image */
                    b_thm_gotten = mmi_bip_generate_thumbnail((U16*) img_path, 
                                                (U16*) rsp->img_path, 
                                                BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH,
                                                MMI_BIP_RESPONDER_ROLE);
                    if (b_thm_gotten)
                    {
                        cnf_code = BT_BIP_CNF_SUCCESS;
                    }
                }
                else
                {                    
                    /* native image is requested */
                    cnf_code = BT_BIP_CNF_SUCCESS;
                }
            }
            else /* find_rst is not SUCCESS */
            {
                /* maybe file path is too long */
                cnf_code = find_rst;
            }
            break;

        case MMI_BIPR_STATE_RECEIVING_IMG:
        case MMI_BIPR_STATE_RECEIVING_THM:
            rsp = (bt_bip_get_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_rsp_struct));
            BIP_MEMSET(rsp);    /* memory init */
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            return;
    }
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;
    rsp->cnf_code = cnf_code;

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        if (b_req_thm == MMI_TRUE)
        {
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING_LPT);
        }
        else
        {
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING_IMG);
        }

    }

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_get_imgprop_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_get_imgprop_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_ind_struct *ind = (bt_bip_get_img_prop_ind_struct*) msg;
    bt_bip_get_img_prop_rsp_struct *rsp;
    U16 img_path[SRV_FMGR_PATH_MAX_LEN];
    U32 width, height;
    int rt;
    U8 cnf_code = GOEP_INTERNAL_SERVER_ERR;
    U8 find_rst = GOEP_NOT_FOUND;
    FS_HANDLE hFile;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMGPROP_IND,srv_bip_p->bipr_cntx.state);

    //ASSERT(srv_bip_p->bipr_cntx.cm_conn_id == ind->cm_conn_id);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case MMI_BIPR_STATE_CONNECTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
            
        case MMI_BIPR_STATE_RECEIVING_IMG:
        case MMI_BIPR_STATE_RECEIVING_THM:
            cnf_code = GOEP_SERVICE_UNAVAILABLE/*BT_BIP_CNF_FAILED*/;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            return;
    }

    rsp = (bt_bip_get_img_prop_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_prop_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_BIP_LOG(MMI_BT_BIP_IN_USB_IMGPROP);
        cnf_code = GOEP_SERVICE_UNAVAILABLE;
        goto SEND_GETPROP_RSP;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* check if the shared folder exist */
    if (!bip_share_folder_exist())
    {
        cnf_code = GOEP_GONE;
    }

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        find_rst = mmi_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) img_path, (S8*)(rsp->native_img.friendly_name));

        if (find_rst == BT_BIP_CNF_SUCCESS)    /* find filename */
        {
            rsp->native_img.encoding = mmi_bip_get_image_type((U16*) img_path);

            hFile = FS_Open((U16*) img_path, FS_READ_ONLY);

            if (hFile >= 0)
            {
                rt = FS_GetFileSize(hFile, &rsp->native_img.size);
                MMI_BIP_LOG2(MMI_BT_BIP_FS_GETFILESIZE_RETRUN, rt, rsp->native_img.size);

                rt = FS_Close(hFile);
                MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, rt);

                result = gdi_image_get_dimension_file((S8 *)img_path, (S32*) & width, (S32*) & height);

                MMI_BIP_LOG_PATH(img_path);
                MMI_BIP_LOG3(MMI_BT_BIP_GDI_GET_DIMENSION, result,width,height);

                if (result == GDI_SUCCEED)
                {
                    rsp->native_img.specified_pixel_width = (U16) width;
                    rsp->native_img.specified_pixel_height = (U16) height;
                }
                else
                {
                    MMI_BIP_LOG(MMI_BT_BIP_GET_DIMENSION_FAILED);
                    
                    rsp->native_img.specified_pixel_width = (U16) 0;
                    rsp->native_img.specified_pixel_height = (U16) 0;
                }

                MMI_BIP_LOG(MMI_BT_BIP_FRIENDLY_NAME);
                MMI_BIP_LOG_PATH(rsp->native_img.friendly_name);

            }
            else
            {
                if (hFile == FS_ACCESS_DENIED)
                {
                    MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 22);
                    cnf_code = GOEP_CONFLICT;
                }
                else
                {
                   MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 23);
                   cnf_code = GOEP_NOT_FOUND;
                }
            
            }
            
            if (cnf_code != BT_BIP_CNF_SUCCESS)
            {
                memset(rsp->native_img.friendly_name, 0, BT_BIP_MAX_IMG_NAME_LEN);
            }
        }
        else /* find_rst is not SUCCESS */
        {
            /* maybe file path is too long */
            cnf_code = find_rst;
        }
    }

SEND_GETPROP_RSP:

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING_LPT);

    }
    rsp->cnf_code = cnf_code;

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_PROP_RSP, rsp);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_get_thm_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipr_get_thm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_linked_thumbnail_ind_struct *ind = (bt_bip_get_linked_thumbnail_ind_struct*) msg;
    bt_bip_get_linked_thumbnail_rsp_struct *rsp;
    U8 find_rst = GOEP_NOT_FOUND;
    U8 cnf_code = GOEP_INTERNAL_SERVER_ERR;
    U16 img_path[SRV_FMGR_PATH_MAX_LEN];
    MMI_BOOL b_thm_gotten = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_THM_IND,srv_bip_p->bipr_cntx.state);

    //ASSERT(srv_bip_p->bipr_cntx.cm_conn_id == ind->cm_conn_id);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case MMI_BIPR_STATE_CONNECTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
            
        case MMI_BIPR_STATE_RECEIVING_IMG:
        case MMI_BIPR_STATE_RECEIVING_THM:
            cnf_code = GOEP_INTERNAL_SERVER_ERR/*BT_BIP_CNF_FAILED*/;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            return;
    }

    rsp =
        (bt_bip_get_linked_thumbnail_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_linked_thumbnail_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
#ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            MMI_BIP_LOG(MMI_BT_BIP_DRM_FORBIDDEN);
            cnf_code = GOEP_SERVICE_UNAVAILABLE;
            goto SEND_GETTHM_RSP;
        }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

        /* check if the shared folder exist */
        if (!bip_share_folder_exist())
        {
            cnf_code = GOEP_GONE;
            goto SEND_GETTHM_RSP;
        }

        find_rst = mmi_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) img_path, NULL);

        if (find_rst == BT_BIP_CNF_SUCCESS)    /* find filename */
        {
            FS_HANDLE hFile = FS_Open((U16 *)img_path, FS_READ_ONLY);
            if (hFile < 0)
            {
                /* not find */
                MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 21);
                cnf_code = GOEP_NOT_FOUND;
            }
            else
            {
                FS_Close(hFile);

           #if defined(__DRM_SUPPORT__)
                /* drm check: if allow to forward out */
                if (!DRM_interdev_movable(0, (kal_wchar*) img_path))
                {
                    MMI_BIP_LOG(MMI_BT_BIP_DRM_FORBIDDEN);
                    cnf_code = GOEP_METHOD_NOT_ALLOWED;
                }
                else
            #endif /* defined(__DRM_SUPPORT__) */ 
                {
                    /* call api to get thumbnail of this image */
                    b_thm_gotten = mmi_bip_generate_thumbnail((U16*) img_path, 
                                              (U16*) rsp->img_path, 
                                              BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH,
                                              MMI_BIP_RESPONDER_ROLE);

                    if (b_thm_gotten)
                    {
                        cnf_code = BT_BIP_CNF_SUCCESS;
                    }
                    else
                    {
                        cnf_code = GOEP_INTERNAL_SERVER_ERR/*BT_BIP_CNF_FAILED*/;
                    }
                }
            }
        }
        else /* find_rst is not SUCCESS */
        {
            /* maybe file path is too long */
            cnf_code = find_rst;
        }
    }
    
SEND_GETTHM_RSP:
    
    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING_LPT);
    }
    
    rsp->cnf_code = cnf_code;
    srv_bip_send_msg(MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_compose_image_list_xml
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_bip_find_type_enum: new start, or continue 
 *  img_count       [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_bip_construct_imglist_ret_enum mmi_bipr_compose_image_list_xml(mmi_bip_find_type_enum find_type, U32 *img_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static FS_Pattern_Struct bip_filter_pattern[MMI_BIP_MAX_FILTER_PATTERN_NUM];
    static U8 filter_count;
    static S32 file_count = 0;
    static U16 found_file_count = 0;
    static S32 ucs2_name_idx = 0;
    U32 start_index = 0;
    U16 path[SRV_FMGR_PATH_MAX_LEN];
    FS_DOSDirEntry file_info;
    bt_bip_img_min_info_struct img_info;
    bip_img_handle_name_struct handle_name_info;
    bip_img_ucs2_name_struct ucs2_name_info;
    U32 write_len;
    int ret, wr_ret;
    mmi_bip_construct_imglist_ret_enum rst = MMI_BIPR_CONSTRUCT_IMGLIST_FAILED;
    S8 *xml_buf = NULL;
    UINT32 xml_buf_len = 0;
    S8 *hdlname_buf = NULL;
    UINT32 hdlname_buf_len = 0;
    UINT32 wr2file_item_num;
    UINT32 xml_item_size;
    UINT32 hdlname_item_size;
    UINT32 max_cache_num;
    UINT32 cached_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_IMGLIST);

    /* alloc buffer */
    xml_buf = get_ctrl_buffer(MMI_BIP_COMPOSE_XML_BUF_SIZE);
    hdlname_buf = get_ctrl_buffer(MMI_BIP_COMPOSE_HDLNAME_SIZE);
    xml_buf_len = 0;
    hdlname_buf_len = 0;
    memset(xml_buf, 0, MMI_BIP_COMPOSE_XML_BUF_SIZE);

    /* compute max_cache_num */
    hdlname_item_size = sizeof(bip_img_handle_name_struct);
    xml_item_size = strlen("<image handle=\"\" created=\"\"/>\n") 
                    + BT_BIP_IMG_HANDLE_LEN - 1
                    + BT_BIP_MAX_TIME_LEN - 1;

    max_cache_num = MMI_BIP_MIN(MMI_BIP_COMPOSE_HDLNAME_SIZE / hdlname_item_size, 
                        MMI_BIP_COMPOSE_XML_BUF_SIZE / xml_item_size);

    /* Continue to find*/
    if (find_type == MMI_BIPR_FIND_CONTINUE)
    {
        MMI_BIP_LOG(MMI_BT_BIP_CONTINUE_CONSTRCT_IMGLIST);

        if (srv_bip_p->bipr_cntx.fs_handle_name >= 0)
        {
            MMI_BIP_LOG(MMI_BT_BIP_CONTINUE_FIND);
            goto Find_Continue;
        }
    }

    /* Start to find */
    MMI_BIP_LOG(MMI_BT_BIP_START_FIND);
    file_count = 0;
    ucs2_name_idx = 0;
    found_file_count = 0;
    
    srv_bip_p->bipr_cntx.fs_imglist = -1;
    srv_bip_p->bipr_cntx.fs_handle_name = -1;
    srv_bip_p->bipr_cntx.fs_ucs2_name = -1;
    
    /* open file handle */
    ret = mmi_bipr_open_imglist_files();
    if (ret < 0)
    {
        goto ERR_RET;
    }

    /* compose the image list header */ 
    wr_ret = mmi_bipr_write_imglist_xml_header();        
    if (wr_ret != FS_NO_ERROR)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 11);
        goto ERR_RET;
    }

    filter_count = mmi_bip_construct_filter_pattern(bip_filter_pattern, MMI_BIP_MAX_FILTER_PATTERN_NUM);

    
    kal_wsprintf(path, "%w*.*", 
        (U16 *)mmi_bt_get_setting_int(BTFF_ITEM_BIP_FLDR_PATH));
    
    srv_bip_p->bipr_cntx.fs_Find = FS_FindFirstN(
                (U16*) path,
                bip_filter_pattern,
                filter_count,
                0,
                0,
                0,
                &file_info,
                (U16*) handle_name_info.found_name,
                BIPR_MAX_NAME_BUF_LEN,
                start_index,
                FS_FIND_DEFAULT);

    MMI_BIP_LOG1(MMI_BT_BIP_FINDFIRST_RETURN, srv_bip_p->bipr_cntx.fs_Find);

    if (srv_bip_p->bipr_cntx.fs_Find>= 0)
    {
        do
        {
            /* check file attribute */
            if ((file_info.Attributes & (FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
            {
                //MMI_BIP_LOG_PATH(handle_name_info.img_name);

                if (file_info.NTReserved == FS_SFN_MATCH)
                {
                    /* other encoding, such as file on memory card */
                    MMI_BIP_LOG2(MMI_BT_BIP_SHORT_NAME, (found_file_count+1), ucs2_name_idx);
                    handle_name_info.ucs2_name_idx = ucs2_name_idx;
                    ucs2_name_idx++;
                
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) ucs2_name_info.ucs2_name,
                        BIPR_MAX_NAME_BUF_LEN,
                        (U8*) handle_name_info.found_name,
                        PhnsetGetDefEncodingType());

                    wr_ret = FS_Write(srv_bip_p->bipr_cntx.fs_ucs2_name, &ucs2_name_info, sizeof(ucs2_name_info), &write_len);
                    if (wr_ret != FS_NO_ERROR)
                    {
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 1);
                        goto ERR_RET;
                    }

                    //MMI_BIP_LOG_PATH(handle_name_info.img_name);
                }
                else
                {
                    handle_name_info.ucs2_name_idx = -1;
                }

                /* construct img-list info, and write it into file */
                memset(&img_info, 0, sizeof(img_info));
                mmi_bip_compose_imghandle_str(img_info.img_handle, found_file_count+1);
                /*
                 * img_info.created;
                 * img_info.modified;
                 */
                sprintf((char*)img_info.created,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.CreateDateTime.Year1980 + 1980,
                    file_info.CreateDateTime.Month,
                    file_info.CreateDateTime.Day,
                    file_info.CreateDateTime.Hour,
                    file_info.CreateDateTime.Minute,
                    file_info.CreateDateTime.Second2);

                /* construct img handle-name info, and write to buffer */
                strcpy((char*)handle_name_info.img_handle, (char*)img_info.img_handle);

                /* write image handle-name to buffer */                
                memcpy(hdlname_buf + hdlname_buf_len, &handle_name_info, hdlname_item_size);
                hdlname_buf_len += hdlname_item_size;

                /* write image item to buffer */
                xml_item_size = sprintf(xml_buf + xml_buf_len,
                                   "<image handle=\"%s\" created=\"%s\"/>\n",
                                   img_info.img_handle, img_info.created);
                xml_buf_len += xml_item_size;

                /* already cached a new one in buffer */
                cached_cnt++;
                if (cached_cnt == max_cache_num)
                {
                    /* write buffer data to file */
                    wr_ret = mmi_bipr_write_imghdle_buf2file(
                                          hdlname_buf, hdlname_buf_len, 
                                          xml_buf, xml_buf_len, xml_item_size, 
                                          &wr2file_item_num);
                    hdlname_buf_len = 0;
                    xml_buf_len = 0;
                    cached_cnt = 0;
                    file_count += wr2file_item_num;

                    if (wr_ret != FS_NO_ERROR)
                    {
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 12);
                        goto ERR_RET;
                    }
                }

#ifdef __MMI_BIP_COMPOSE_MODIFIED_TIME_TO_IMGLIST_XML__ 
                sprintf((char*)img_info.modified,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.DateTime.Year1980 + 1980,
                    file_info.DateTime.Month,
                    file_info.DateTime.Day,
                    file_info.DateTime.Hour,
                    file_info.DateTime.Minute,
                    file_info.DateTime.Second2);
#endif


                /* an image file has been found */
                found_file_count++;

            }

            if (found_file_count % MMI_BIP_ONE_TIME_MAX_FIND_NUM == 0)
            {
                /* PAUSE now, Continue to find next time */
                rst = MMI_BIPR_CONSTRUCT_IMGLIST_CONTINUE;

                goto SUCC_RET;
            }
            
Find_Continue:
    
            /* find the next image file */
            ret = FS_FindNextN(
                    srv_bip_p->bipr_cntx.fs_Find,
                    bip_filter_pattern,
                    filter_count,
                    0,
                    &file_info,
                    (U16*) handle_name_info.found_name,
                    BIPR_MAX_NAME_BUF_LEN,
                    FS_FIND_DEFAULT);
            
        } while (ret == FS_NO_ERROR &&
                            found_file_count < BT_BIP_RESPONDER_MAX_IMGHDLE_NUM
                    /* && ucs2_name_idx < BT_BIP_RESPONDER_MAX_SFN_NUM */);
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_FINDFIRST_FAILED);
        /* delete the previous img list: maybe it contains old value. */
        ret = FS_Delete((U16*) srv_bip_p->bipr_cntx.img_list_path);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_DELETE_RETURN, ret);        
    }

    MMI_BIP_LOG1(MMI_BT_BIP_CONSTRUCT_IMGLIST_COUNT, found_file_count);
    
    if (ret == FS_NO_ERROR && 
        (found_file_count == BT_BIP_RESPONDER_MAX_IMGHDLE_NUM /* || ucs2_name_idx == BT_BIP_RESPONDER_MAX_SFN_NUM */))
    {
        /* there are extra images */
        MMI_BIP_LOG2(MMI_BT_BIP_CONSTRUCT_IMGLIST_PARTIAL_CONTENT, found_file_count, ucs2_name_idx);
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT;
    }
    else if (found_file_count >= 0)
    {
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS;
    }    

    /* success return */    
SUCC_RET:

    /* write the remain buffer data to file */
    if (cached_cnt > 0)
    {
        wr_ret = mmi_bipr_write_imghdle_buf2file(
                        hdlname_buf, hdlname_buf_len, 
                        xml_buf, xml_buf_len, xml_item_size, 
                        &wr2file_item_num);

        file_count += wr2file_item_num;
    }

    *img_count = file_count;

    if ((rst == MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS || 
         rst == MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT) && 
         file_count >= 0)
    {   
        /* compose has finished */
        
        /* write tail to file*/
        mmi_bipr_write_imglist_xml_tail();

        /* close the tmp file handle */
        mmi_bipr_close_tmp_imglist_file();
    }
    
    /* free the buffer */
    free_ctrl_buffer(xml_buf);
    free_ctrl_buffer(hdlname_buf);
    
    return rst;


    /* return when some error happen */
ERR_RET: 

    if (file_count > 0) /* partial content */
    {
        MMI_BIP_LOG2(MMI_BT_BIP_CONSTRUCT_IMGLIST_PARTIAL_CONTENT, file_count, ucs2_name_idx);

        *img_count = file_count;
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT;

        /* write tail to file*/
        mmi_bipr_write_imglist_xml_tail();

        /* close the tmp file handle */
        mmi_bipr_close_tmp_imglist_file();
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_IMGLIST_FAILED);
    
        mmi_bipr_delete_tmp_imglist_file();

        file_count = 0;
        *img_count = 0;

        rst = MMI_BIPR_CONSTRUCT_IMGLIST_FAILED;    
    }

    /* free the buffer */
    free_ctrl_buffer(xml_buf);
    free_ctrl_buffer(hdlname_buf);

    return rst;

}


#ifdef __MMI_BIP_COMPOSE_IMGLIST_XML_IN_ADP__
/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_construct_img_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_bip_find_type_enum: new start, or continue 
 *  img_count       [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_bip_construct_imglist_ret_enum mmi_bipr_construct_img_list(mmi_bip_find_type_enum find_type, U32 *img_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static FS_Pattern_Struct bip_filter_pattern[MMI_BIP_MAX_FILTER_PATTERN_NUM];
    static U8 filter_count;
    U32 start_index = 0;
    U16 path[SRV_FMGR_PATH_MAX_LEN];
    FS_DOSDirEntry file_info;
    static S32 file_count = 0;
    static S32 ucs2_name_idx = 0;
    bt_bip_img_min_info_struct img_info;
    bip_img_handle_name_struct handle_name_info;
    bip_img_ucs2_name_struct ucs2_name_info;
    S8 tmp_str[BT_BIP_IMG_HANDLE_LEN];
    U32 write_len;
    S8 *dst, *src;
    int ret, wr_ret;
    int len, i;
    mmi_bip_construct_imglist_ret_enum rst = MMI_BIPR_CONSTRUCT_IMGLIST_FAILED;
#ifdef CHECK_PATHLEN_WHEN_COMPOSE_IMGLIST_XML
    S32 share_folder_len;
    S32 filename_len;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_IMGLIST);
    
    share_folder_len = mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, NULL, 0);
    share_folder_len /= 2;
    
    if (find_type == MMI_BIPR_FIND_CONTINUE)
    {
        MMI_BIP_LOG(MMI_BT_BIP_CONTINUE_CONSTRCT_IMGLIST);

        if (srv_bip_p->bipr_cntx.fs_handle_name >= 0)
        {
            MMI_BIP_LOG(MMI_BT_BIP_CONTINUE_FIND);
            goto Find_Continue;
        }
    }

    MMI_BIP_LOG(MMI_BT_BIP_START_FIND);
    file_count = 0;
    ucs2_name_idx = 0;
    
    srv_bip_p->bipr_cntx.fs_imglist = -1;
    srv_bip_p->bipr_cntx.fs_handle_name = -1;
    srv_bip_p->bipr_cntx.fs_ucs2_name = -1;

    filter_count = mmi_bip_construct_filter_pattern(bip_filter_pattern, MMI_BIP_MAX_FILTER_PATTERN_NUM);

    kal_wsprintf(path, "%w*.*", 
        (U16 *)mmi_bt_get_setting_int(BTFF_ITEM_BIP_FLDR_PATH));

    srv_bip_p->bipr_cntx.fs_Find = FS_FindFirstN(
                (U16*) path,
                bip_filter_pattern,
                filter_count,
                0,
                0,
                0,
                &file_info,
                (U16*) handle_name_info.found_name,
                BIPR_MAX_NAME_BUF_LEN,
                start_index,
                FS_FIND_DEFAULT);

    MMI_BIP_LOG1(MMI_BT_BIP_FINDFIRST_RETURN, srv_bip_p->bipr_cntx.fs_Find);

    if (srv_bip_p->bipr_cntx.fs_Find>= 0)
    {
        /* open the image list file */
        srv_bip_p->bipr_cntx.fs_imglist = FS_Open((U16*) srv_bip_p->bipr_cntx.img_list_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (srv_bip_p->bipr_cntx.fs_imglist < 0)
        {
           MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_imglist, 9);
            goto Error;
        }
        /* open the handle-name file */
        srv_bip_p->bipr_cntx.fs_handle_name = FS_Open((U16*) srv_bip_p->bipr_cntx.img_handle_name_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (srv_bip_p->bipr_cntx.fs_handle_name < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_handle_name, 10);
            goto Error;
        }

        /* open the ucs2-name file */
        srv_bip_p->bipr_cntx.fs_ucs2_name = FS_Open((U16*) srv_bip_p->bipr_cntx.img_ucs2_name_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (srv_bip_p->bipr_cntx.fs_ucs2_name < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_ucs2_name, 11);
            goto Error;
       }

        do
        {
            /* check file attribute */
            if ((file_info.Attributes & (FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
            {
                //MMI_BIP_LOG_PATH(handle_name_info.img_name);

                if (file_info.NTReserved == FS_SFN_MATCH)
                {
                    /* other encoding, such as file on memory card */
                    MMI_BIP_LOG2(MMI_BT_BIP_SHORT_NAME, (file_count+1), ucs2_name_idx);
                
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) ucs2_name_info.ucs2_name,
                        BIPR_MAX_NAME_BUF_LEN,
                        (U8*) handle_name_info.found_name,
                        PhnsetGetDefEncodingType());
#ifdef CHECK_PATHLEN_WHEN_COMPOSE_IMGLIST_XML
                    /* check ucs2 filename length */
                    filename_len = mmi_ucs2strlen((S8 *)ucs2_name_info.ucs2_name);
                    if (share_folder_len + filename_len > SRV_FMGR_PATH_MAX_LEN)
                    {
                        /* PATH is too long */
                        MMI_BIP_LOG2(MMI_BT_BIP_PATH_TOO_LONG, share_folder_len, filename_len));
                        MMI_BIP_LOG_PATH(info.found_name);

                        /* skip this long file path */
                        goto Find_Continue;
                    }
#endif
                    handle_name_info.ucs2_name_idx = ucs2_name_idx;
                    ucs2_name_idx++;

                    wr_ret = FS_Write(srv_bip_p->bipr_cntx.fs_ucs2_name, &ucs2_name_info, sizeof(ucs2_name_info), &write_len);
                    if (wr_ret != FS_NO_ERROR)
                    {
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 1);
                        goto Error;
                    }

                    //MMI_BIP_LOG_PATH(handle_name_info.img_name);
                }
                else
                {
                    handle_name_info.ucs2_name_idx = -1;
                }

#ifdef CHECK_PATHLEN_WHEN_COMPOSE_IMGLIST_XML
                /* check filename length */
                filename_len = mmi_ucs2strlen((S8 *)handle_name_info.found_name);
                if (share_folder_len + filename_len > SRV_FMGR_PATH_MAX_LEN)
                {
                    /* PATH is too long */
                    MMI_BIP_LOG2(MMI_BT_BIP_PATH_TOO_LONG, share_folder_len, filename_len));
                    MMI_BIP_LOG_PATH(info.found_name);

                    /* skip this long file path */
                    goto Find_Continue;
                }
#endif                
                /* construct img handle-name info, and write it into file */
                strcpy((char*)handle_name_info.img_handle, (char*)img_info.img_handle);
                wr_ret = FS_Write(srv_bip_p->bipr_cntx.fs_handle_name, &handle_name_info, sizeof(handle_name_info), &write_len);
                if (wr_ret != FS_NO_ERROR)
                   {
                    MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 3);
                    goto Error;
                }

                /* construct img-list info, and write it into file */
                memset(&img_info, 0, sizeof(img_info));
                strcpy((char*)img_info.img_handle, MMI_BIP_IMG_HANDLE_PREFIX);
                kal_sprintf(tmp_str, "%d", (file_count+1));
                len = strlen(tmp_str);
                if (len > 0)
                {
                    dst = (S8*) (img_info.img_handle + BT_BIP_IMG_HANDLE_LEN - len - 1);
                    src = tmp_str;

                    for (i = 0; i < len; i++)
                        *dst++ = *src++;
                }
                /*
                 * img_info.created;
                 * img_info.modified;
                 */
                sprintf((char*)img_info.created,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.CreateDateTime.Year1980 + 1980,
                    file_info.CreateDateTime.Month,
                    file_info.CreateDateTime.Day,
                    file_info.CreateDateTime.Hour,
                    file_info.CreateDateTime.Minute,
                    file_info.CreateDateTime.Second2);

                sprintf((char*)img_info.modified,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.DateTime.Year1980 + 1980,
                    file_info.DateTime.Month,
                    file_info.DateTime.Day,
                    file_info.DateTime.Hour,
                    file_info.DateTime.Minute,
                    file_info.DateTime.Second2);


                wr_ret = FS_Write(srv_bip_p->bipr_cntx.fs_imglist, &img_info, sizeof(img_info), &write_len);
                if (wr_ret != FS_NO_ERROR)
                {
                    MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 2);
                    goto Error;
                }

                /* an image file has been recorded */
                file_count++;

            }

            if (file_count % MMI_BIP_ONE_TIME_MAX_FIND_NUM == 0)
            {
                return MMI_BIPR_CONSTRUCT_IMGLIST_CONTINUE;
            }
            
Find_Continue:
    
            /* find the next image file */
            ret = FS_FindNextN(
                    srv_bip_p->bipr_cntx.fs_Find,
                    bip_filter_pattern,
                    filter_count,
                    0,
                    &file_info,
                    (U16*) handle_name_info.found_name,
                    BIPR_MAX_NAME_BUF_LEN,
                    FS_FIND_DEFAULT);
            
        } while (ret == FS_NO_ERROR && 
                 file_count < BT_BIP_RESPONDER_MAX_IMGHDLE_NUM && 
                 ucs2_name_idx < BT_BIP_RESPONDER_MAX_SFN_NUM );

        /* close the tmp file handle */
        mmi_bipr_close_tmp_imglist_file();
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_FINDFIRST_FAILED);
        /* delete the previous img list: maybe it contains old value. */
        ret = FS_Delete((U16*) srv_bip_p->bipr_cntx.img_list_path);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_DELETE_RETURN, ret);        
    }

    MMI_BIP_LOG1(MMI_BT_BIP_CONSTRUCT_IMGLIST_COUNT, file_count);

    *img_count = file_count;
    
    if (ret == FS_NO_ERROR && 
       (file_count == BT_BIP_RESPONDER_MAX_IMGHDLE_NUM || 
        ucs2_name_idx == BT_BIP_RESPONDER_MAX_SFN_NUM))
    {
        /* there are extra images */
        MMI_BIP_LOG2(MMI_BT_BIP_CONSTRUCT_IMGLIST_PARTIAL_CONTENT, file_count, ucs2_name_idx);
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT;
    }
    else if (file_count >= 0)
    {
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS;
    }    

    return rst;

Error:

    if (file_count > 0) /* partial content */
    {
        MMI_BIP_LOG2(MMI_BT_BIP_CONSTRUCT_IMGLIST_PARTIAL_CONTENT, file_count, ucs2_name_idx);
        /* close the tmp file handle */
        mmi_bt_bipr_close_tmp_imglist_file();

        *img_count = file_count;
        rst = MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT;

        return rst;
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_IMGLIST_FAILED);
    
        mmi_bipr_delete_tmp_imglist_file();

        file_count = 0;
        *img_count = 0;

        return MMI_BIPR_CONSTRUCT_IMGLIST_FAILED;    
    }
}

#endif /* __MMI_BIP_COMPOSE_IMGLIST_XML_IN_ADP__ */






static void mmi_bipr_delete_tmp_imglist_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_DELETE_TMP_IMGLIST_FILE);
    
    mmi_bipr_close_tmp_imglist_file();
    FS_Delete((U16*) srv_bip_p->bipr_cntx.img_list_path);
}


static void mmi_bipr_close_tmp_imglist_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_DELETE_TMP_IMGLIST_FILE);

    /* the handle-name file */
    if (srv_bip_p->bipr_cntx.fs_handle_name >= 0)
    {
        ret = FS_Close(srv_bip_p->bipr_cntx.fs_handle_name);
        if (ret >= FS_NO_ERROR)
        {
            srv_bip_p->bipr_cntx.fs_handle_name = -1;
        }
        else if (MMI_BIP_FS_DEVICE_BUSY(ret))
        {
            MMI_BIP_LOG1(MMI_BT_BIP_FSCLOSE_HANDLENAME_DEVBUSY, ret);
            mmi_bipr_close_tmp_imglist_file_continually();
        }
    }
    /* the ucs2-name file */
    if (srv_bip_p->bipr_cntx.fs_ucs2_name >= 0)
    {
        ret = FS_Close(srv_bip_p->bipr_cntx.fs_ucs2_name);
        if (ret >= FS_NO_ERROR)
        {
            srv_bip_p->bipr_cntx.fs_ucs2_name = -1;
        }
        else if (MMI_BIP_FS_DEVICE_BUSY(ret))
        {
            MMI_BIP_LOG1(MMI_BT_BIP_FSCLOSE_UCS2NAME_DEVBUSY, ret);
            mmi_bipr_close_tmp_imglist_file_continually();
        }
    }
    /* the image list file */
    if (srv_bip_p->bipr_cntx.fs_imglist >= 0)
    {
        ret = FS_Close(srv_bip_p->bipr_cntx.fs_imglist);
        if (ret >= FS_NO_ERROR)
        {
            srv_bip_p->bipr_cntx.fs_imglist = -1;
        }
        else if (MMI_BIP_FS_DEVICE_BUSY(ret))
        {
            MMI_BIP_LOG1(MMI_BT_BIP_FSCLOSE_IMGLIST_DEVBUSY, ret);
            mmi_bipr_close_tmp_imglist_file_continually();
        }
    }
    /* the fs_find handle */
    if (srv_bip_p->bipr_cntx.fs_Find >= 0)
    {
        ret = FS_FindClose(srv_bip_p->bipr_cntx.fs_Find);
        if (ret >= FS_NO_ERROR)
        {
            srv_bip_p->bipr_cntx.fs_Find = -1;
        }
        else if (MMI_BIP_FS_DEVICE_BUSY(ret))
        {
            MMI_BIP_LOG1(MMI_BT_BIP_FSFINDCLOSE_DEVBUSY, ret);
            mmi_bipr_close_tmp_imglist_file_continually();
        }
    }

}


static void mmi_bipr_close_tmp_imglist_file_continually(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_DELETE_TMP_IMGLIST_FILE_CONTINUALLY);

    StartTimer(BT_BIP_FS_TIMER, MMI_BIP_FS_CONT_DUR, mmi_bt_bipr_close_tmp_imglist_file);
} 


static MMI_BOOL bip_share_folder_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *share_fldr;
    S32 length, retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, NULL, 0);
    share_fldr = OslMalloc(length);
    mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, share_fldr, length);

    retval = FS_GetAttributes(share_fldr);
    if (retval < FS_NO_ERROR)
    {
        MMI_BIP_LOG1(MMI_BT_BIP_OPEN_SHARED_FOLDER_ERROR, retval);
        OslMfree(share_fldr);
        return MMI_FALSE;
    }

    OslMfree(share_fldr);

    return MMI_TRUE;    
}


#define MMI_BIP_PULL_REQ_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_all_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_all_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_ALL_IMG, mmi_bip_p->img_total);
    mmi_bip_p->get_type = MMI_BIP_GET_ALL_IMG;
    mmi_bip_p->cur_idx_to_get_img = 0;
    mmi_bip_p->img_num_to_get = mmi_bip_p->img_total;

    mmi_bipi_entry_start_get_image();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_selected_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_selected_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_SELECTED_IMG, mmi_bip_p->selected_img_num);
    ASSERT(mmi_bip_p->selected_img_num > 0);

    mmi_bip_p->get_type = MMI_BIP_GET_SELECTED_IMG;

    while (mmi_bip_p->checkbox_values[i] == 0 && i < mmi_bip_p->img_total)
        i++;

    mmi_bip_p->cur_idx_to_get_img = i;
    mmi_bip_p->img_num_to_get = mmi_bip_p->selected_img_num;

    mmi_bipi_entry_start_get_image();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_next_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_next_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = mmi_bip_p->cur_idx_to_get_img;
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_NEXT_IMG, idx);
   
    mmi_bipi_pull_get_img_handle_from_index(idx, cur_img_handle);

    mmi_bipi_pull_get_image(cur_img_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_cur_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_cur_imgprop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_CUR_IMGPROP);
    mmi_bip_p->b_stop_bg_getting_thm = MMI_TRUE;

    /* get img_handle from cur_index */
    ret = mmi_bipi_pull_get_img_handle_from_index(mmi_bip_p->cur_index, mmi_bip_p->cur_img_handle);
    if (ret > 0)
    {
        mmi_bipi_pull_entry_getting_imgprop();

        mmi_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMGPROP);
    }
    else
    {
        /* pop up */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_cur_imgthm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_cur_imgthm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_index = mmi_bip_p->cur_index;
#if 0    
/* under construction !*/
/* under construction !*/
#endif
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_CUR_IMGTHM);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    
#endif

    /* thm has not been gotten, get it now */

    mmi_bip_p->b_stop_bg_getting_thm = MMI_TRUE;

    /* get img_handle from cur_index */
    ret = mmi_bipi_pull_get_img_handle_from_index(cur_index, mmi_bip_p->cur_img_handle);
    if (ret > 0)
    {
        mmi_bip_p->b_user_get_thm = MMI_TRUE;
        
        mmi_bipi_pull_entry_getting_imgthm();

        mmi_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_THM);
    }
    else
    {
        /* pop up */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_next_thm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_next_thm(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_NEXT_THM);
    mmi_bipi_pull_get_img_handle_from_index(index, cur_img_handle);
    mmi_bipi_send_get_imgthm_req((S8*) cur_img_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_refresh_imglist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_refresh_imglist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_REFRESH_IMGLIST);
    mmi_bipi_pull_entry_refreshing_scr();

    g_bip_context.bip_initiator_cntx.start_index = 0;

    mmi_bip_p->b_refreshed = MMI_TRUE;
    mmi_bip_p->b_stop_bg_getting_thm = MMI_TRUE;

    mmi_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_REFRESH_IMGLIST);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_entry_start_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_entry_start_get_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bip_p->received_img_num = 0;
    mmi_bip_p->cur_getting_num = 1;
    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;
    g_bip_context.bip_initiator_cntx.cur_img_total_size = RECV_UNKNOWN_SIZE;
    mmi_bip_p->b_stop_bg_getting_thm = MMI_TRUE;
    mmi_bip_p->pull_recv_drive = SRV_FMGR_PUBLIC_DRV;

#ifdef __MMI_BT_RECV_DRV_SWITCH__

    mmi_bip_p->b_selecting_drv = MMI_TRUE;
    /* get received drive */
    MMI_BIP_LOG(MMI_BT_BIP_CALL_GET_DRIVE_BEFORE_GETIMAGE);
    mmi_bth_get_receive_drive(MMI_BT_OBEX_IMAGING_UUID, mmi_bipi_get_recv_drive_callback); 

#else

    mmi_bipi_start_get_image();

#endif /*__MMI_BT_RECV_DRV_SWITCH__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_start_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_start_get_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_bt_bip_error_enum rst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_bipi_pull_entry_getting_img();

    mmi_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_refresh_download_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_refresh_download_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = mmi_bip_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_REFRESH_DOWNLOAD_LIST);

    if (mmi_bip_p->checkbox_values[idx])
    {
        mmi_bip_p->checkbox_values[idx] = 0;
        mmi_bip_p->selected_img_num--;
        ChangeLeftSoftkey(STR_BIP_ADDTO_GETLIST, IMG_GLOBAL_OPTIONS);
    }
    else
    {
        mmi_bip_p->checkbox_values[idx] = 1;
        mmi_bip_p->selected_img_num++;
        ChangeLeftSoftkey(STR_GLOBAL_REMOVE, IMG_GLOBAL_OPTIONS);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_cur_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_exec_operation(mmi_bipi_cur_user_operation_enum oper_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_EXEC_OPER, oper_type);

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    if (mmi_bipi_pull_is_getting_thm())
    {
        mmi_bip_p->next_oper = oper_type;
        
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_ABORTING);
        mmi_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);

        return;
    }
#endif

    switch (oper_type)
    {
    case MMI_BIP_NEXT_OPER_GET_IMGPROP:
        mmi_bipi_send_get_imgprop_req(mmi_bip_p->cur_img_handle);
        break;

    case MMI_BIP_NEXT_OPER_GET_THM:
        mmi_bipi_send_get_imgthm_req(mmi_bip_p->cur_img_handle);
        break;

    case MMI_BIP_NEXT_OPER_GET_IMG:
        MMIBIP_SET_FLAG(MMIBIP_MASK_SUCC_RECV_FILE);
        mmi_bipi_get_next_image();
        break;

    case MMI_BIP_NEXT_OPER_REFRESH_IMGLIST:
        mmi_bipi_send_get_imglist_req();
        break;

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_abort_getting_images_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_abort_getting_images_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_ABORT_GET_IMG);

    mmi_bip_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    
    mmi_bipi_pull_abort_getting_images();    
    
    if ((g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_ABORTING) ||
        (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_DISCONNECTING))
    {
        //mmi_bipi_pull_entry_aborting();
        mmi_bipi_pull_entry_canceling();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_connect_cancel
 * DESCRIPTION
 *  This is common function to abort connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_connect_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_CONNECT_CANCEL,g_bip_context.bip_initiator_cntx.state);

    mmi_bipi_pull_connect_cancel_comm(MMI_FALSE);

    mmi_bipi_pull_entry_canceling();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_get_img_handle_from_index
 * DESCRIPTION
 *  Rerturn img handle
 * PARAMETERS
 *  index           [IN]        
 *  img_handle      [?]      
 *  data_size(?)        [IN]
 *  menu_data(?)        [OUT]
 *  start_index(?)      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_bipi_pull_get_img_handle_from_index(S32 index, S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_min_info_struct item;
    U32 offset = index * sizeof(bt_bip_img_min_info_struct);
    FS_HANDLE hFile;
    int len, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_IMGHANDLE_FROM_INDEX, index);
    hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_list_path, FS_READ_ONLY);
    if (hFile < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 35);
        return 0;
    }
    ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
    ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
    MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 16);

    strcpy((S8*) img_handle, (S8*) item.img_handle);

    FS_Close(hFile);

    return 1;
}



#define MMI_BIP_PULL_REQ_SCR_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_connect_scr
 * DESCRIPTION
 *  This function is to entry the connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_entry_connect_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_CONNECT_SCR);
    
    EntryNewScreen(SCR_BIP_CONNECTING, NULL, mmi_bipi_pull_entry_connect_scr, NULL);

    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_GLOBAL_CONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_bip_compose_string(MMI_BIPI_CONNECTING_NOTY),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bipi_pull_connect_cancel, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, mmi_bipi_pull_connecting_screen_del_cb);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_canceling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_ENTRY_CANCELING_SCR,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_IDLE)
    {
        return;
    }
    
    EntryNewScreen(SCR_BIP_CONNECT_CANCELING, NULL, mmi_bipi_pull_entry_canceling, NULL);

    //MMI_BIPI_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_GLOBAL_CANCELLING, 
                GetRootTitleIcon(MENU_CONN_BT_MAIN),
                0, 0, 0, 0, 
                (U8*) mmi_bip_compose_string(MMI_BIPI_ABORTING_NOTY), 
                mmi_get_event_based_image(MMI_EVENT_PROGRESS), 
                NULL);
    
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_imglist_browser
 * DESCRIPTION
 *  Entry function for image list browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_imglist_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 left_softkey;
    U16 left_softkey_icon;
    U16 right_softkey;
    S32 highlighted_item;
    FS_HANDLE hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_ENTRY_IMGLIST_BROWSER,g_bip_context.bip_initiator_cntx.state);

    /* to fix CR MAUI_00490185, check bk drawing */
    if ((mmi_is_redrawing_bk_screens()) && 
        (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_CONNECTED))
    {
        /* only if is refreshing, then simple draw bk */
        MMI_BIP_LOG(MMI_BT_BIP_REDRAW_BK);
        mmi_bipi_pull_redraw_bk_imglist_browser();
        
        return;
    }

    EntryNewScreen(SCR_BIP_IMGLIST_BROWSER, 
                   mmi_bipi_pull_exit_imglist_browser, 
                   mmi_bipi_pull_entry_imglist_browser, 
                   NULL);

    if (mmi_bip_p->cache_buffer == NULL && mmi_bip_p->img_total > 0)
    {
        mmi_bip_p->cache_size = MMI_BT_BIP_IMGLIST_SCR_CACHE_SIZE;

        mmi_bip_p->cache_buffer = mmi_frm_scrmem_alloc_framebuffer(MMI_BT_BIP_IMGLIST_SCR_CACHE_SIZE);
        if (mmi_bip_p->cache_buffer == NULL)
        {
            MMI_BIP_LOG(MMI_BT_BIP_SCREENMEM_ALLOC_FAILED);
            mmi_bip_p->cache_size = 0;
        }
    }
    
    if (mmi_bip_p->checkbox_values == NULL && mmi_bip_p->img_total > 0)
    {
        mmi_bip_p->checkbox_values = OslMalloc(mmi_bip_p->img_total);
        if (mmi_bip_p->checkbox_values == NULL)
        {
            MMI_BIP_LOG(MMI_BT_BIP_OSLMALLOC_FAILED);
            ASSERT(0);
        }
        memset(mmi_bip_p->checkbox_values, 0, mmi_bip_p->img_total);
    }

    /* check the imagelist file */
    if (mmi_bip_p->img_total > 0)
    {
        hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_list_path, FS_READ_ONLY);    
        if (hFile >= 0)
        {
            FS_Close(hFile);
        }
        else
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 30);
            mmi_bipi_notify_recv_err(MMI_BIP_ERR_FILE_OPEN_FAIL);

            mmi_bip_p->img_total = 0;
        }
    }
    

    guiBuffer = GetCurrGuiBuffer(SCR_BIP_IMGLIST_BROWSER);

    RegisterHighlightHandler(mmi_bipi_pull_imglist_highlight_hdlr);

    /* hilight the last item selected when re-enter img browser screen */
    highlighted_item = mmi_bip_p->sel_obj_id;

    mmi_bip_p->sel_opt_index = 0;
    mmi_bip_p->opt_item_changed = MMI_BIP_OPT_ITEM_CHANGED_NONE;
    
    if (mmi_bip_p->img_total > 0)
    {
        left_softkey = STR_GLOBAL_OPTIONS;
        left_softkey_icon = IMG_GLOBAL_OPTIONS;
        right_softkey = STR_GLOBAL_ON;
    }
    else
    {
        left_softkey = STR_GLOBAL_REFRESH;
        left_softkey_icon = 0;                      
        right_softkey = STR_GLOBAL_EXIT;    /* STR_GLOBAL_BACK; */
    }

    ShowCategory426Screen(
        STR_BIP_IMGLIST_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        left_softkey,
        left_softkey_icon,
        right_softkey,
        IMG_GLOBAL_BACK,
        CHECKBOX_ON_IMAGE_ID,
        CHECKBOX_OFF_IMAGE_ID,
        mmi_bip_p->img_total,
        mmi_bipi_pull_get_img_handle_for_display,
        mmi_bipi_pull_get_img_thm_for_display,
        mmi_bip_p->checkbox_values,
        mmi_bip_p->cache_buffer,
        mmi_bip_p->cache_size,
        highlighted_item,
        guiBuffer);

    if (mmi_bip_p->img_total > 0)
    {
        SetLeftSoftkeyFunction(mmi_bipi_pull_entry_imglist_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bipi_pull_refresh_imglist_category, KEY_EVENT_UP);
        SetKeyHandler(mmi_bipi_pull_entry_imglist_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bipi_pull_refresh_imglist, KEY_EVENT_UP);
        //SetRightSoftkeyFunction(mmi_bipi_pull_empty_imgbrowser_RSK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bipi_pull_entry_exit_confirm_scr, KEY_EVENT_UP);
        SetKeyHandler(mmi_bipi_pull_refresh_imglist, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, mmi_bipi_pull_imglist_browser_del_cb);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_imglist_option
 * DESCRIPTION
 *  This function is to display the option menu of image browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_imglist_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 i;
    S32 highlighted_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_OPTION);
    EntryNewScreen(SCR_BIP_IMGLIST_OPTION, NULL, mmi_bipi_pull_entry_imglist_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BIP_IMGLIST_OPTION);
    RegisterHighlightHandler(mmi_bipi_pull_imglist_option_highlight_hdlr);

    nNumofItem = GetNumOfChild(MENU_CONN_BIP_IMGLIST_OPTION);
    GetSequenceStringIds(MENU_CONN_BIP_IMGLIST_OPTION, nStrItemList);

    /* if no selected images, disable menu item "Get Selected Images" */
    if (mmi_bip_p->selected_img_num == 0)
    {
        for (i = 0; i < nNumofItem && nNumofItem < 20; i++)
        {
            nStrItemList[i] = nStrItemList[i + 1];
        }
        nNumofItem -= 1;
    }

    
    if (mmi_bip_p->opt_item_changed)
    {
        if (mmi_bip_p->opt_item_changed == MMI_BIP_OPT_ITEM_ENABLE_GET_SELECTED)
        {
            highlighted_item = mmi_bip_p->sel_opt_index + 1;
        }
        else
        {
            highlighted_item = mmi_bip_p->sel_opt_index - 1;
        }
        guiBuffer = NULL;
    }
    mmi_bip_p->opt_item_changed = MMI_BIP_OPT_ITEM_CHANGED_NONE;

    SetParentHandler(MENU_CONN_BIP_IMGLIST_BROWSER);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        highlighted_item,//0,
        guiBuffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_bipi_pull_imglist_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bipi_pull_imglist_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_getting_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_getting_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMG);
    EntryNewScreen(SCR_BIP_RECEIVING, NULL, mmi_bipi_pull_entry_getting_img, NULL);

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
#endif
    ShowRecvingScreen(SCR_BIP_RECEIVING, mmi_bipi_get_obj_info);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bipi_pull_abort_getting_images_operation, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, mmi_bipi_pull_recving_screen_del_cb);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMG_DETAIL, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMG_DETAIL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_getting_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_getting_imgprop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMGPROP);
    EntryNewScreen(SCR_BIP_GETTING_IMGPROP, NULL, mmi_bipi_pull_entry_getting_imgprop, NULL);

    //MMI_BIPI_BUILD_GETTING_IMGPROP_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_GETTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_bip_compose_string(MMI_BIPI_GETTING_IMGPROP_NOTY),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    //SetRightSoftkeyFunction(mmi_bipi_pull_abort_simple_operation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bipi_pull_abort_getting_images_operation, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_getting_imgthm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_getting_imgthm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMGTHM);
    EntryNewScreen(SCR_BIP_GETTING_IMGPROP, NULL, mmi_bipi_pull_entry_getting_imgthm, NULL);

    //MMI_BIPI_BUILD_GETTING_IMGTHM_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_GETTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_bip_compose_string(MMI_BIPI_GETTING_IMGTHM_NOTY),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    //SetRightSoftkeyFunction(mmi_bipi_pull_abort_simple_operation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bipi_pull_abort_getting_images_operation, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_refreshing_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_refreshing_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_REFRESH_SCR);
    EntryNewScreen(SCR_BIP_CONNECTING, NULL, mmi_bipi_pull_entry_refreshing_scr, NULL);

    //MMI_BIPI_BUILD_REFRESH_IMGLIST_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_REFRESHING, 
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) mmi_bip_compose_string(MMI_BIPI_REFRESH_IMGLIST_NOTY),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_img_detail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_img_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;
    S8 tmp_str[32]; /* convert tmp_str to UCS2 ? */

//#define IMG_DETAIL_INFO_PREFIX_SPACE L"    "

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_IMG_DETAIL);
    EntryNewScreen(SCR_BIP_IMG_DETAIL, NULL, mmi_bipi_pull_entry_img_detail, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BIP_IMG_DETAIL);

    info = (PU8) subMenuData;

    /* construct image detail info */

    /* name */
    mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_BIP_DETAIL_NAME));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);
    mmi_ucs2cat((PS8) info, (PS8) mmi_bip_p->img_name);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* encoding */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_ENCODING));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    switch (mmi_bip_p->img_encoding)
    {
        case BT_BIP_IMG_TYPE_JPEG:
            mmi_ucs2cat((PS8) info, (PS8) L"JPEG");
            break;
            
        case BT_BIP_IMG_TYPE_GIF:
            mmi_ucs2cat((PS8) info, (PS8) L"GIF");
            break;
            
        case BT_BIP_IMG_TYPE_WBMP:
            mmi_ucs2cat((PS8) info, (PS8) L"WBMP");
            break;
            
        case BT_BIP_IMG_TYPE_BMP:
            mmi_ucs2cat((PS8) info, (PS8) L"BMP");
            break;
            
        case BT_BIP_IMG_TYPE_PNG:
            mmi_ucs2cat((PS8) info, (PS8) L"PNG");
            break;
            
        default:
            mmi_ucs2cat((PS8) info, (PS8)GetString(STR_BIP_UNKNOWN));
            break;            
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* pixel */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_PIXEL));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    if (mmi_bip_p->img_width > 0 && mmi_bip_p->img_height > 0)
    {
        kal_wsprintf(
            (U16*) tmp_str,
            "%d%c%d",
            mmi_bip_p->img_width,
            L'*',
            mmi_bip_p->img_height);
        mmi_ucs2cat((PS8) info, (PS8) tmp_str);
    }
    else
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_UNKNOWN));
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* size */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_SIZE));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    mmi_bip_print_size(mmi_bip_p->img_size, (U16*) tmp_str, MMI_TRUE);

    mmi_ucs2cat((PS8) info, (PS8) tmp_str);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    ShowCategory74Screen(
        STR_BIP_OPTION_DETAIL,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_preview_thumbnail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_preview_thumbnail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_str[BT_BIP_IMG_HANDLE_LEN * ENCODING_LENGTH];
    U16 left_softkey = 0;
    U32 idx = mmi_bip_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_PREVIEW);
    EntryNewScreen(SCR_BIP_THM_PREVIEW, NULL, mmi_bipi_pull_entry_preview_thumbnail, NULL);

    mmi_bip_p->opt_item_changed = MMI_BIP_OPT_ITEM_CHANGED_NONE;
    mmi_bip_p->old_selected_img_num = mmi_bip_p->selected_img_num;

    if (mmi_bip_p->checkbox_values[idx])
    {
        left_softkey = STR_GLOBAL_REMOVE;
    }
    else
    {
        left_softkey = STR_BIP_ADDTO_GETLIST;
    }
        
    /* convert the string to UCS2 */
    mmi_asc_to_ucs2((S8*) title_str, (S8*) mmi_bip_p->cur_img_handle);

    ShowCategory222ScreenInternal(
            (UI_string_type)title_str,                     /* title */
            (PU8)get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)),
            (UI_string_type)GetString(left_softkey),
            (PU8)get_image(IMG_GLOBAL_OPTIONS), 
            (UI_string_type)GetString(STR_GLOBAL_BACK),
            (PU8)get_image(IMG_GLOBAL_BACK),                                /* right soft key */
            GDI_COLOR_WHITE,                                /* content BG color */
            (PS8) NULL,                                     /* button bar string */
            (PS8) mmi_bip_p->img_thm_path,    /* image file name */
            FALSE,                     /* is_short */
            NULL,/* result callback */
            GDI_IMAGE_SRC_FROM_FILE);

    SetLeftSoftkeyFunction(mmi_bipi_refresh_download_list, KEY_EVENT_UP);
    //SetKeyHandler(mmi_bipi_refresh_download_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_bipi_pull_exit_preview_scr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_bipi_pull_exit_preview_scr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_exit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_exit_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_EXIT_CONFIRM_SCR);
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_IDLE)
    { 
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        mmi_confirm_display(
            (WCHAR * )mmi_bip_compose_string(MMI_BIPI_EXIT_NOTY), 
            MMI_EVENT_QUERY, 
            mmi_confirm_property_struct * arg);

        SetLeftSoftkeyFunction(mmi_bipi_pull_entry_exit_confirm_scr_LSK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_exit_confirm_scr_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_exit_confirm_scr_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_EXIT_CFM_LSK);

    mmi_bipi_pull_exit_image_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_entry_disconnecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_ENTRY_DISCONNECTING_SCR,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_IDLE)
    {
        return;
    }

    EntryNewScreen(SCR_BIP_DISCONNECTING, NULL, mmi_bipi_pull_entry_disconnecting, NULL);

    //MMI_BIPI_BUILD_DISCONNECTING_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_DISCONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) mmi_bip_compose_string(MMI_BIPI_DISCONNECTING_NOTY),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_imglist_highlight_hdlr
 * DESCRIPTION
 *  Multi-file selection catefory refresh handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_imglist_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bip_p->cur_index = index;
    mmi_bip_p->sel_obj_id = (U16) index;

    if (mmi_bip_p->checkbox_values[index])
    {
        ChangeRightSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_imglist_option_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for option menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_imglist_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bip_p->sel_opt_index = index;

    /* if no selected images, disable menu item "Get Selected Images" */
    if (mmi_bip_p->selected_img_num == 0)
    {
        index++;
    }

    switch (index)
    {
        case 0:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET;
            break;
            
        case 1:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL;
            break;
            
        case 2:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET_THM;
            break;
            
        case 3:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET_ALL;
            break;
            
        case 4:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_REFRESH;
            break;

        case 5:
            mmi_bip_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_DISCONNECT;
            break;
            
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_imglist_option_LSK
 * DESCRIPTION
 *  This function is to execute the selected action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_imglist_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_OPTION_LSK);
    switch (mmi_bip_p->sel_opt_id)
    {
        case MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL:
            mmi_bipi_get_cur_imgprop();            
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET:
            mmi_bipi_get_selected_images();
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET_ALL:
            mmi_bipi_get_all_images();
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET_THM:
            mmi_bipi_get_cur_imgthm();
            break;

        case MMI_BIP_SCR_SELECT_OPT_REFRESH:
            mmi_bipi_pull_refresh_imglist();
            break;

        case MMI_BIP_SCR_SELECT_OPT_DISCONNECT:
            mmi_bipi_pull_entry_exit_confirm_scr();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_redraw_bk_imglist_browser
 * DESCRIPTION
 *  redraw background screen function for image list browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_redraw_bk_imglist_browser()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_softkey;
    U16 left_softkey_icon;
    U16 right_softkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bip_p->img_total > 0)
    {
        left_softkey = STR_GLOBAL_OPTIONS;
        left_softkey_icon = IMG_GLOBAL_OPTIONS;
        right_softkey = STR_GLOBAL_ON;
    }
    else
    {
        left_softkey = STR_GLOBAL_REFRESH;
        left_softkey_icon = 0;                      
        right_softkey = STR_GLOBAL_EXIT;    /* STR_GLOBAL_BACK; */
    }

    ShowCategory426Screen(
        STR_BIP_IMGLIST_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        left_softkey,
        left_softkey_icon,
        right_softkey,
        IMG_GLOBAL_BACK,
        SMALL_CHECKBOX_ON_IMAGE_ID,
        SMALL_CHECKBOX_OFF_IMAGE_ID,
        0,
        mmi_bipi_pull_get_img_handle_for_display,
        mmi_bipi_pull_get_img_thm_for_display,
        NULL,
        NULL,
        0,
        0,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_refresh_imglist_category
 * DESCRIPTION
 *  Left softkey handler to select/unselect the file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_refresh_imglist_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int idx = mmi_bip_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bip_p->checkbox_values[idx])
    {
        mmi_bip_p->checkbox_values[idx] = 0;
        mmi_bip_p->selected_img_num--;
        ChangeRightSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    else
    {
        mmi_bip_p->checkbox_values[idx] = 1;
        mmi_bip_p->selected_img_num++;
        ChangeRightSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }

    RefreshCategory426Screen();
}





/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_get_img_handle_for_display
 * DESCRIPTION
 *  Rerturn file description to category 426
 * PARAMETERS
 *  start_index     [IN]        
 *  menu_data       [OUT]       
 *  data_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_bipi_pull_get_img_handle_for_display(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_iconlist_menu_item *menu_item = menu_data;
    U32 offset = start_index * sizeof(bt_bip_img_min_info_struct);
    FS_HANDLE hFile;
    bt_bip_img_min_info_struct item;
    int len, ret;
    S32 i = 0, cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGHANDLE_FOR_DISPLAY, start_index, data_size);
    
    hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_list_path, FS_READ_ONLY);
    MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 31);
    
    if (hFile >= 0)
    {
        ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
        if (ret < 0)
        {
            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
            FS_Close(hFile);
            goto ERROR_HANDLING;
        }
        ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
        if (ret != FS_NO_ERROR || len <= 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 10);
            FS_Close(hFile);
            goto ERROR_HANDLING;
        }

        for (i = start_index; i < start_index + data_size && ret == FS_NO_ERROR && len > 0; i++)
        {
            /* convert the string to UCS2 */
            mmi_asc_to_ucs2((S8*) menu_item->item_list[0], (S8*) item.img_handle);
            if (item.created[0] != 0)
            {
                mmi_asc_to_ucs2((S8*) menu_item->item_list[1], (S8*) item.created);
            }
            else
            {
                S8 *pstr = (S8*) menu_item->item_list[1];

                pstr[0] = 0;
                pstr[1] = 0;
            }
            
            MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGHANDLE_FOR_DISPLAY, i, item.img_handle);
            
            menu_item++;
            cnt++;

            ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);

            if ((ret != FS_NO_ERROR || len <= 0) && (cnt < data_size))
            {
                MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 11);
                FS_Close(hFile);
                goto ERROR_HANDLING;
            }
        }
        FS_Close(hFile);
    }
    else
ERROR_HANDLING:        
    {
        MMI_BIP_LOG1(MMI_BT_BIP_CAT426_GET_IMGHDL_CB_READ, cnt);
        if (cnt < data_size)
        {
            for (i = cnt; i < data_size; i++)
            {
                /* clear string info */
                  menu_item->item_list[0][0] = 0x00;
                  menu_item->item_list[0][1] = 0x00;
                
                  menu_item->item_list[1][0] = 0x00;
                  menu_item->item_list[1][1] = 0x00;

                menu_item++;
            }
           cnt = data_size;
        }
    }

    ASSERT(cnt == data_size);
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_get_img_thm_for_display
 * DESCRIPTION
 *  Rerturn image file to category 426
 * PARAMETERS
 *  index                   [IN]        
 *  image_filename          [OUT]       
 *  max_size                [IN]        
 *  default_image_id        [?]       
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_bipi_pull_get_img_thm_for_display(S32 index, U8 *image_filename, S32 max_size, U16 *default_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BIP_LIST_THUMBNAIL__
    U32 offset = index * sizeof(mmi_bip_img_browser_item_struct);
    FS_HANDLE hFile;
    mmi_bip_img_browser_item_struct item;
    int len;
    int ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_THM_FOR_DISPLAY, index);
    *default_image_id = IMG_BIP_DEFAULT_THM;

    image_filename[0] = 0;
    image_filename[1] = 0;

#ifndef __MMI_BIP_LIST_THUMBNAIL__

    return;

#else

    hFile = FS_Open((U16*) mmi_bip_p->img_browser_content_path, FS_READ_ONLY);
    if (hFile >= 0)
    {
        ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
        if (ret != offset)
        {
            FS_Close(hFile);
            return;
        }

        ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
        MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 12);
        FS_Close(hFile);

        if (ret == FS_NO_ERROR && len > 0 && mmi_ucs2strlen(item.thm_name) > 0)
        {
            mmi_ucs2cpy((S8*) image_filename, (S8*) item.thm_name);

            //kal_prompt_trace(MOD_MMI,"[BIP MMI]--- thm filename: ");
            MMI_BIP_LOG(MMI_BT_BIP_THM_FILE_NAME);
            MMI_BIP_LOG_PATH(image_filename)
        }
        else
        {
        }
    }
    else
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 32);
    }
#endif 
}



void mmi_bipi_pull_scr_get_imglist_end (mmi_bt_bip_error_enum rst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_GET_IMGLIST_END);
    if (rst == MMI_BIP_SUCCESS || rst == MMI_BIP_PARTIAL_CONTENT)
    {
        if (rst == MMI_BIP_PARTIAL_CONTENT)
        {
            mmi_bip_notify_err_info(MMI_BIP_PARTIAL_CONTENT);
        }
        mmi_bipi_pull_scr_imglist_gotten();
    }
    else if (rst != MMI_BIP_ERR_DISCONNECTED)
    {
         if (mmi_bip_p->b_refreshed)
        {
            mmi_bipi_notify_recv_err(MMI_BIP_ERR_BROWSE_FAILED);
        }
        else
         {
            mmi_bipi_notify_recv_err(rst);
        }

        mmi_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }
    mmi_bip_p->b_refreshed = MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_scr_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_scr_imglist_gotten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int hFile;
    //U16 activeScrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_IMGLIST_GOTTEN);

    /* delete the old value */
    FS_Delete((U16*) mmi_bip_p->img_browser_content_path); 

    /* create empty thm name list file */
    hFile = FS_Open((U16*) mmi_bip_p->img_browser_content_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (hFile >= 0)
        FS_Close(hFile);
    else
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 40);

    mmi_bip_p->sel_obj_id = 0;

    /* release previous memory */
    mmi_bipi_pull_app_mem_free();


    if (mmi_bip_p->b_refreshed)
    {
        mmi_bip_p->selected_img_num = 0;
        /* clear the flag */
        mmi_bip_p->b_refreshed = MMI_FALSE;
    }
    
    mmi_bip_p->img_total = g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist;
    if (mmi_bip_p->img_total > BT_BIP_MAX_IMGHDLE_NUM)
        mmi_bip_p->img_total = BT_BIP_MAX_IMGHDLE_NUM;

    /* delete the previous imglist browser screen, if present */
    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_BROWSER);
        
    g_bip_context.bip_initiator_cntx.b_user_disconnect = MMI_FALSE;

    //if (mmi_bip_isForegroundScreen(SCR_BIP_CONNECTING))
    if (SCR_BIP_CONNECTING == GetActiveScreenId())
    {        
        /* display image list */
        mmi_bipi_pull_entry_imglist_browser();
    
    }
    else
    {
        /* fix CR [MAUI_01191435]: insert the imglist browser after the connecting screen */
        history ImglistScr;

        ImglistScr.scrnID = SCR_BIP_IMGLIST_BROWSER;
        ImglistScr.entryFuncPtr = mmi_bipi_pull_entry_imglist_browser;

        InsertHistoryAfterThisScrnReference(SCR_BIP_CONNECTING, &ImglistScr);
        SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, mmi_bipi_pull_imglist_browser_del_cb);
    }

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    /* get the first thm */
    mmi_bip_p->cur_idx_to_get_thm = 0;
    if (g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist > 0)
    {
        mmi_bipi_get_next_thm(mmi_bip_p->cur_idx_to_get_thm);
    }

#endif /* __MMI_BIP_LIST_THUMBNAIL__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_scr_aborted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bipi_pull_scr_aborted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_proc = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_SCR_ABORTED, mmi_bip_p->next_oper);

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    switch(mmi_bip_p->next_oper)
    {
        case MMI_BIP_NEXT_OPER_GET_IMG:
            mmi_bipi_get_next_image();
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_GET_THM:
            mmi_bipi_send_get_imgthm_req(mmi_bip_p->cur_img_handle);
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_GET_IMGPROP:
            mmi_bipi_send_get_imgprop_req(mmi_bip_p->cur_img_handle);
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_REFRESH_IMGLIST:
            mmi_bipi_send_get_imglist_req();
            b_proc = MMI_TRUE;
            break;

        default:
            break;
    }
#endif
    mmi_bip_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    return b_proc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_exit_imglist_browser
 * DESCRIPTION
 *  Exit function for image list browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_exit_imglist_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_EXIT_IMGLIST_BROWSER,g_bip_context.bip_initiator_cntx.state);
    if (mmi_bip_p->cache_buffer != NULL)
    {
        mmi_frm_scrmem_free(mmi_bip_p->cache_buffer);
    }
    mmi_bip_p->cache_buffer = NULL;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_exit_preview_scr
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_exit_preview_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_EXIT_PREVIEW);

#ifndef __MMI_BIP_LIST_THUMBNAIL__
    /* delete current thm file */
    FS_Delete((U16*)mmi_bip_p->img_thm_path);
#endif

    if ((mmi_bip_p->old_selected_img_num == 0) && 
        (mmi_bip_p->selected_img_num == 1))
    {
        mmi_bip_p->opt_item_changed = MMI_BIP_OPT_ITEM_ENABLE_GET_SELECTED;
    }
    else if ((mmi_bip_p->old_selected_img_num == 1) && 
             (mmi_bip_p->selected_img_num == 0))
    {
        mmi_bip_p->opt_item_changed = MMI_BIP_OPT_ITEM_DISABLE_GET_SELECTED;
    }
 

    /* go back history */
    mmi_frm_scrn_close_active_id();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_connecting_screen_del_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_bipi_pull_connecting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CONNECTING_SCR_DEL_CB);

    if (MMI_TRUE == mmi_bipi_pull_is_connecting())
    {
        mmi_bipi_pull_disconnect();

    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_imglist_browser_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting file_browser screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_bipi_pull_imglist_browser_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IMGBROWSER_SCR_DEL_CB,g_bip_context.bip_initiator_cntx.state);

    if ((g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_IDLE) && 
        (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_DISCONNECTING))
    {
        mmi_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);       /* MMI_BIP_TP_DISCONNECT); */

    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_recving_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting receiving screen
 * PARAMETERS
 *  p     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_bipi_pull_recving_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_RECVING_SCR_DEL_CB);

    if (MMI_TRUE == mmi_bipi_pull_is_recving())
    {
        mmi_bip_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;    
        mmi_bipi_pull_abort_getting_images();    
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_scr_connect_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_scr_connect_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_SCR_CONNECT_TERMINATED);
    
    /* delete the thm name list file */
    ret = FS_Delete((U16*) mmi_bip_p->img_browser_content_path);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_DELETE_RETURN, ret);

    /* release malloced memory, if any */
    mmi_bipi_pull_app_mem_free();

    /* reset variables; */
    FS_Delete((U16*) mmi_bip_p->img_browser_content_path);
    mmi_bip_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    mmi_bip_p->b_refreshed = MMI_FALSE;
    mmi_bip_p->b_user_get_thm = MMI_FALSE;
    mmi_bip_p->b_stop_bg_getting_thm = MMI_FALSE;
    mmi_bip_p->selected_img_num = 0;
    mmi_bip_p->sel_obj_id = 0;
    mmi_bip_p->sel_opt_id = 0;
    mmi_bip_p->sel_opt_index = 0;


#ifdef __MMI_BT_RECV_DRV_SWITCH__    
             
    if (mmi_bip_p->b_selecting_drv)
    {
        mmi_bip_p->b_selecting_drv = MMI_FALSE;
        
        MMI_BIP_LOG(MMI_BT_BIPR_CANCEL_GET_RECV_DRV);
        mmi_bth_cancel_get_receive_drive(MMI_BT_OBEX_IMAGING_UUID, MMI_FALSE);
    }
#endif /*__MMI_BT_RECV_DRV_SWITCH__*/ 

    mmi_bipi_clear_pull_scrs();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_clear_pull_scrs
 * DESCRIPTION
 *  This function is to clear BIP screens
 * PARAMETERS
 *  disc_reset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_clear_pull_scrs(U8 disc_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_I_CLEAR_SCR);

    mmi_bip_delete_screen(SCR_BIP_CONNECTING);
    mmi_bip_delete_screen(SCR_BIP_CONNECT_CANCELING);
    mmi_bip_delete_screen(SCR_BIP_RECEIVING);
    mmi_bip_delete_screen(SCR_BIP_DISCONNECTING);
    mmi_bip_delete_screen(SCR_BIP_IMGLIST_BROWSER);
    mmi_bip_delete_screen(SCR_BIP_GETTING_IMGPROP);
    mmi_bip_delete_screen(SCR_BIP_IMG_DETAIL);
    mmi_bip_delete_screen(SCR_BIP_THM_PREVIEW);
    mmi_bip_delete_screen(SCR_BIP_EXIT_CONFIRM);
      
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_history_replace
 * DESCRIPTION
 *  This function is a AddHistory wrapper function
 * PARAMETERS
 *  out_scr     [IN]        
 *  in_scr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bip_history_replace(U16 out_scr, U16 in_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_HISTORY_REPLACE);
    switch (in_scr)
    {
        case SCR_BIP_IMGLIST_BROWSER:
            HistoryReplace(out_scr, in_scr, mmi_bipi_pull_entry_imglist_browser);
            SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, mmi_bipi_pull_imglist_browser_del_cb);
            break;

        case SCR_BIP_IMG_DETAIL:
            HistoryReplace(out_scr, in_scr, mmi_bipi_pull_entry_img_detail);
            break;

        case SCR_BIP_THM_PREVIEW:
            HistoryReplace(out_scr, in_scr, mmi_bipi_pull_entry_preview_thumbnail);
            break;

        case SCR_BIP_NOTY_FILE_RECV:
            HistoryReplace(out_scr, in_scr, mmi_bipi_pull_entry_getimage_rst_notify_scr);
            break;

        default:
            break;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_notify_user_abort_req_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_notify_user_abort_req_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ABORT_REQ_TIMEOUT_NOTIFY_USER);
    
    mmi_bipi_notify_recv_err(MMI_BIP_ERR_TIMEOUT);

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    HistoryReplace(SCR_BIP_CONNECT_CANCELING, SCR_BIP_DISCONNECTING, mmi_bipi_pull_entry_disconnecting);
}


#define MMI_BIP_PULL_CNF_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_scr_get_img_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_scr_get_img_cnf(U8 cnf_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_done = MMI_FALSE;
    mmi_bt_bip_error_enum rst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG3(MMI_BT_BIP_SCR_GET_IMG_CNF, cnf_code,mmi_bip_p->received_img_num,mmi_bip_p->cur_getting_num);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {

        if (GetActiveScreenId() == SCR_BIP_RECEIVING)
        {
            /* update progress */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            UpdateRecvingScreen(SCR_BIP_RECEIVING);
        }
    
        mmi_bip_p->received_img_num++;
    }
        
    /* check if done */
    if (mmi_bip_p->cur_getting_num == mmi_bip_p->img_num_to_get)
    {
        /* all selected images has been gotten */
        b_done = MMI_TRUE;
    }
    else
    {
        if (mmi_bip_p->get_type == MMI_BIP_GET_ALL_IMG)
        {
            mmi_bip_p->cur_idx_to_get_img++;
        }
        else if (mmi_bip_p->get_type == MMI_BIP_GET_SELECTED_IMG)
        {
            int i = mmi_bip_p->cur_idx_to_get_img + 1;

            while (mmi_bip_p->checkbox_values[i] == 0 && i < mmi_bip_p->img_total)
                i++;
            mmi_bip_p->cur_idx_to_get_img = i;
        }
    }

    /* if disconnected, then don't continue to get */
    if (cnf_code == BT_BIP_DISCONNECTED || 
        cnf_code == BT_BIP_DISK_FULL || 
        cnf_code == BT_BIP_FS_QUOTA_FULL || 
        cnf_code == BT_BIP_FS_MEDIA_CHANGED || 
        //cnf_code == GOEP_SERVICE_UNAVAILABLE || 
        cnf_code == GOEP_GONE
        )
    {
        b_done = MMI_TRUE;
    }
    
    if (b_done)
    {
        /* pull image end */
        rst = mmi_bip_convert_cnf_code_to_bip_err(cnf_code);
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
#endif        
        mmi_bipi_pull_img_end(rst);
    }
    else
    {
        /* continue to get the next image */
        mmi_bip_p->cur_getting_num++;
        mmi_bipi_get_next_image();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_scr_get_thm_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  thm_path        [?]   
 *  cnf_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_scr_get_thm_cnf(U8 cnf_code, U8 *thm_path, U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BIP_LIST_THUMBNAIL__
    mmi_bip_img_browser_item_struct item;
    int index;
    U32 offset;
    FS_HANDLE hFile;
    int len;
    int ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(mmi_bip_SCR_GET_THM_CNF, cnf_code);

#ifdef __MMI_BIP_LIST_THUMBNAIL__

    if (!mmi_bip_p->b_user_get_thm)
    {
        index = mmi_bip_p->cur_idx_to_get_thm;
    }
    else
    {
        index = mmi_bip_p->cur_index;
    }

    offset = index * sizeof(mmi_bip_img_browser_item_struct);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {        
        hFile = FS_Open((U16*) mmi_bip_p->img_browser_content_path, FS_READ_WRITE);
        
        if (hFile >= 0)
        {
            /* read out the old value */
            ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
            ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
            MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 15);
            
            /* write the new value */
            mmi_ucs2cpy((S8*) item.thm_name, (S8*) thm_path);
            mmi_ucs2cat((S8*) item.thm_name, (S8*) name);

            //kal_prompt_trace(MOD_MMI,"[BIP MMI]--- index=%d, thm_name: ", index);
            MMI_BIP_LOG1(MMI_BIPI_SCR_GET_THM_CNF, index);
            MMI_BIP_LOG_PATH(item.thm_name);
            
            ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
            ret = FS_Write(hFile, &item, sizeof(item), (UINT*) & len);
            MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, ret, 10);
            
            FS_Close(hFile);

            if (!mmi_bip_p->b_stop_bg_getting_thm)
            {
                //kal_prompt_trace(MOD_MMI,"[BIP MMI]---RefreshCategory426Screen...\n");
                MMI_BIP_LOG(MMI_BIPI_SCR_REFRESHCATEGORY426);
                RefreshCategory426Screen();            
            }
        }
        else
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 34);
        }

    }

    /* get next thm */
    if (index < mmi_bip_p->img_total - 1 && !mmi_bip_p->b_stop_bg_getting_thm)
    {
        index++;
        mmi_bipi_get_next_thm(index);
        mmi_bip_p->cur_idx_to_get_thm = index;
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_GET_THM_END);
    }
#endif    

    if (mmi_bip_p->b_user_get_thm)
    {

        if (cnf_code == BT_BIP_CNF_SUCCESS)
        {
            mmi_ucs2cpy((S8*)mmi_bip_p->img_thm_path, (S8*)thm_path);
            mmi_ucs2cat((S8*)mmi_bip_p->img_thm_path, (S8*)name);

            MMI_BIP_LOG(MMI_BT_BIP_USER_GET_THM);
            MMI_BIP_LOG_PATH(mmi_bip_p->img_thm_path);

            //if (mmi_bip_isForegroundScreen(SCR_BIP_GETTING_IMGPROP))
            if (SCR_BIP_GETTING_IMGPROP == GetActiveScreenId())
            {
                /* Preview the thumbnail*/
                mmi_bipi_pull_entry_preview_thumbnail();
            }
            else
            {
                /* place the imglist browser into history */
                mmi_bip_history_replace(SCR_BIP_GETTING_IMGPROP, SCR_BIP_THM_PREVIEW);
            }
        }
        else if (cnf_code != BT_BIP_DISCONNECTED)
        {
            mmi_bt_bip_error_enum bip_err = mmi_bip_convert_cnf_code_to_bip_err(cnf_code);
            /* pop up */
            mmi_bipi_notify_recv_err(bip_err);
        }
        
        SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);        
        DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);

        mmi_bip_p->b_user_get_thm = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_imgprop_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_get_imgprop_end(U8 cnf_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bip_error_enum bip_err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_IMGPROP_END, cnf_code);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        /* display info of cnf->native_img */
        //if (mmi_bip_isForegroundScreen(SCR_BIP_GETTING_IMGPROP))
        if (SCR_BIP_GETTING_IMGPROP == GetActiveScreenId())
        {
            mmi_bipi_pull_entry_img_detail();
        }
        else
        {
            mmi_bip_history_replace(SCR_BIP_GETTING_IMGPROP, SCR_BIP_IMG_DETAIL);
        }
    }
    else
    {
        /* failed */
        if (cnf_code != BT_BIP_DISCONNECTED)
        {
            bip_err = mmi_bip_convert_cnf_code_to_bip_err(cnf_code);
            mmi_bipi_notify_recv_err(bip_err);
        }
    }
    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_img_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_img_end(mmi_bt_bip_error_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 CurScrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG3(MMI_BT_BIP_PULL_IMG_END, result,mmi_bip_p->received_img_num,mmi_bip_p->img_num_to_get);

   // StopTimer(FMGR_PROG_UPDATE_TIMER);

    /* if user canceled , then no notify info */
    if (result == MMI_BIP_ERR_CANCELED_BY_USER || result == MMI_BIP_ERR_GEN_FILE_FAIL)
    {
        goto CLEAR_PULL_SCR;
    }


    /* if all failed, then only popup */
    if (mmi_bip_p->received_img_num == 0)
    {
        if (result != MMI_BIP_ERR_DISCONNECTED)
        { 
            mmi_bipi_notify_recv_err(MMI_BIP_ERR_NO_FILES_RECEIVED);
        }

        goto CLEAR_PULL_SCR;
    }

    if (SCR_BIP_RECEIVING == GetActiveScreenId() ||
        SCR_BIP_CONNECT_CANCELING== GetActiveScreenId())
    {
        mmi_bipi_pull_entry_getimage_rst_notify_scr();

        srv_prof_play_tone(SRV_PROF_TONE_GENERAL_TONE,NULL);
        TurnOnBacklight(1);
    }
    else
    {
        if (IsScreenPresent(SCR_BIP_RECEIVING))
            mmi_bip_history_replace(SCR_BIP_RECEIVING, SCR_BIP_NOTY_FILE_RECV);
        else
            mmi_bip_history_replace(SCR_BIP_CONNECT_CANCELING, SCR_BIP_NOTY_FILE_RECV);
    }
    
CLEAR_PULL_SCR:

    CurScrID = GetActiveScreenId();
    if (SCR_BIP_CONNECT_CANCELING == CurScrID)
    {
        if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_DISCONNECTING)
        {
            /* disconnecting state need aborting screen */
            mmi_frm_scrn_close_active_id();
        }
    }
    else if (SCR_BIP_RECEIVING == CurScrID)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);        
        DeleteScreenIfPresent(SCR_BIP_RECEIVING);            
        SetDelScrnIDCallbackHandler(SCR_BIP_CONNECT_CANCELING, NULL);        
        DeleteScreenIfPresent(SCR_BIP_CONNECT_CANCELING);            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_entry_getimage_rst_notify_scr
 * DESCRIPTION
 *  This function is to display get image result notify screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_entry_getimage_rst_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 StrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_IDLE_NOTIFY_SCR);

    mmi_bipi_pull_build_getimage_result_string();

    EntryNewScreen(SCR_BIP_NOTY_FILE_RECV, NULL, mmi_bipi_pull_entry_getimage_rst_notify_scr, NULL);

    if (mmi_bip_p->received_img_num > 0)
        StrID = STR_BIP_NOTY_RECV_FILE_BROWSE;
    else
        StrID = 0;

    ShowCategory154Screen(
        STR_BIP_IMGLIST_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        StrID,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) mmi_bip_notify_str,
        NULL,
        IMG_GLOBAL_INFO,
        NULL);

    if (mmi_bip_p->received_img_num > 0)
    SetLeftSoftkeyFunction(mmi_bipi_pull_notify_scr_browse, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECT_CANCELING, NULL);
    
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_CONNECT_CANCELING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_notify_scr_browse
 * DESCRIPTION
 *  This function is to browse the received images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_NOTIFY_SCR_BROWSE);
    
    FMGR_FILTER_INIT(&filter);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8 *)g_bip_context.bip_initiator_cntx.img_path_file))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    MMI_BIP_LOG_PATH(g_bip_context.bip_initiator_cntx.img_path);

    /* FMGR_Revise */
    mmi_fmgr_browse_path(
        APP_BIP,
        0,
        filter,
        (S8*)g_bip_context.bip_initiator_cntx.img_path_file,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_FILE_RECV, NULL);
    DeleteScreenIfPresent(SCR_BIP_NOTY_FILE_RECV);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_display_get_image_result
 * DESCRIPTION
 *  
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_pull_build_getimage_result_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 recv_num;
    U16 failed_num;
    U16 cnt_str[8];
    S8 *file = GetString(STR_BIP_FILE);
    S8 *files = GetString(STR_BIP_FILES);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_num = mmi_bip_p->received_img_num;
    
    failed_num = mmi_bip_p->img_num_to_get- recv_num;

    memset(mmi_bip_notify_str, 0, sizeof(mmi_bip_notify_str));

    if ((recv_num > 1) && (recv_num == mmi_bip_p->img_num_to_get))
    {
        /* all files received*/
        mmi_ucs2cpy( (S8 *)mmi_bip_notify_str, (S8 *)GetString(STR_BT_ALL_FILE_RECEIVED));
    }
    else if (recv_num == 0)
    {
        /* unfinished*/
        mmi_ucs2cpy( (S8 *)mmi_bip_notify_str, (S8 *)GetString(STR_GLOBAL_UNFINISHED)); 
    }
    else
    {
        /*1 or n files received*/
        kal_wsprintf((U16*) cnt_str, "%d ", recv_num);
        mmi_ucs2cpy( (S8 *)mmi_bip_notify_str, (S8 *)cnt_str); 
        mmi_ucs2cat((S8 *)mmi_bip_notify_str,((recv_num > 1) ? files : file));
        mmi_ucs2cat( (S8 *)mmi_bip_notify_str, (S8 *)GetString(STR_BIP_RECEIVED) ); 
    }
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
#endif   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_app_mem_free
 * DESCRIPTION
 *  Free APP-shared memory allocated for file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_pull_app_mem_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_APP_MEM_FREE);

    if (mmi_bip_p->checkbox_values)
    {
        OslMfree(mmi_bip_p->checkbox_values);
        mmi_bip_p->checkbox_values = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_obj_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_bt_recv_obj_info_struct obj_info_p: it record obj info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_get_obj_info(mmi_bt_recv_obj_info_struct *obj_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj_info_p->cur_obj_num = mmi_bip_p->cur_getting_num;
    obj_info_p->total_obj_num =  mmi_bip_p->img_num_to_get;
    
    obj_info_p->recv_obj_size = g_bip_context.bip_initiator_cntx.cur_img_gotten_size;
    obj_info_p->total_obj_size = g_bip_context.bip_initiator_cntx.cur_img_total_size;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_get_receive_drive_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uuid: profile uuid
 *  drv: selected drive
 *  selected: if user select a drive
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_get_recv_drive_callback (U32 uuid, U8 drv, MMI_BOOL selected)
{
#ifdef __MMI_BT_RECV_DRV_SWITCH__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG4(MMI_BT_BIPI_GET_DRIVE_CB, uuid, drv, selected,g_bip_context.bip_responder_cntx.state);

    mmi_bip_p->b_selecting_drv = MMI_FALSE;
    
    if (selected)
    {
        mmi_bip_p->pull_recv_drive = drv;
        mmi_bipi_start_get_image();
    }

#endif /*__MMI_BT_RECV_DRV_SWITCH__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_notify_recv_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bipi_notify_recv_err(mmi_bt_bip_error_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 suppress_level = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    suppress_level =  mmi_bt_get_interrupt_suppress_level();
    MMI_BIP_LOG2(MMI_BIPI_NOTIFY_ERR, cause, suppress_level);

    if (cause == MMI_BIP_ERR_DISK_FULL)
    {
        if ((suppress_level & MMI_FRM_INT_BT_LEVEL_2))
        {
            return;
        }
    }
    else
    {
        if ((suppress_level & MMI_FRM_INT_BT_LEVEL_1))
        {
            return;
        }
    }

    switch (cause)
    {
        case MMI_BIP_SUCCESS:
            mmi_popup_display((WCHAR *) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
            break;

        case MMI_BIP_ERR_SCO_REJECT:
            /* support device busy case for MT6601 */
            goto CLEAR_SCRS;
            break;

       default:
           mmi_bip_notify_err_info(cause);
              break;
    }

  CLEAR_SCRS:
      mmi_bipi_clear_push_scrs();
}



#define MMI_BIP_LIB_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bip_work_folder_init
 * DESCRIPTION
 *  This function is to initialize BIP work folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bip_work_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;
    U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    U16 *share_fldr;
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    /* compose responder's receive folder */
    srv_bip_p->bipr_cntx.recv_drive = SRV_FMGR_PUBLIC_DRV;
    mmi_bip_compose_recv_folder(MMI_BIP_RESPONDER_ROLE, MMI_FALSE);

    length = mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, NULL, 0);
    share_fldr = OslMalloc(length);
    mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, share_fldr, length);

    h = FS_Open(share_fldr, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else
    {
        ret = mmi_bt_gen_folder(share_fldr, 0);
        if (ret < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, ret, 2);
        }
    }
    OslMfree(share_fldr);
    
    h = FS_Open((U16*) BIP_FOLDER_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else    /* Error handling */
    {
         MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, h, 3);
        ret = FS_CreateDir((U16*) BIP_FOLDER_PATH);
        if (ret < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, ret, 2);
        }
    }

    h = FS_Open((U16*) BIP_RECV_THM_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else    /* Error handling */
    {
         MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, h, 4);
        ret = FS_CreateDir((U16*) BIP_RECV_THM_PATH);
        if (ret < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, ret, 3);
            MMI_BIP_LOG(MMI_BT_BIP_CREATE_RECV_THM_PATH_FAILED);
        }
    }

    h = FS_Open((U16*) BIP_GEN_THM_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else    /* Error handling */
    {
         MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, h, 5);
        ret = FS_CreateDir((U16*) BIP_GEN_THM_PATH);
        if (ret < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, ret, 4);
             MMI_BIP_LOG(MMI_BT_BIP_CREATE_GEN_THM_PATH_FAILED);
        }
    }

    h = FS_Open((U16*) BIP_TEMP_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else    /* Error handling */
    {
         MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, h, 6);
        ret = FS_CreateDir((U16*) BIP_TEMP_PATH);
        if (ret < 0)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, ret, 5);
            MMI_BIP_LOG(MMI_BT_BIP_CREATE_TEMP_PATH_FAILED);
        }
    }

    /* build default path */

    /* responder's img_list path */
    mmi_ucs2cpy((S8*) srv_bip_p->bipr_cntx.img_list_path, (S8*) BIP_IMG_LIST_PATH_FILE);

    /* responder's current img_list path */
    mmi_ucs2cpy((S8*) srv_bip_p->bipr_cntx.cur_img_list_path, (S8*) BIP_CUR_IMG_LIST_PATH_FILE);

    /* responder's img handle-name list file */
    mmi_ucs2cpy((S8*) srv_bip_p->bipr_cntx.img_handle_name_path, (S8*) BIP_TMP_IMG_HDLE_NAME_FILE);
    mmi_ucs2cpy((S8*) srv_bip_p->bipr_cntx.img_ucs2_name_path, (S8*) BIP_TMP_IMG_UCS2_NAME_FILE);

    /* pull initiator's recieved thumbnail path */
    mmi_ucs2cpy((S8*) srv_bip_p->bipi_cntx.thm_path, (S8*) BIP_RECV_THM_PATH);

    /* pull initiator's thm list file name */
    mmi_ucs2cpy((S8*) mmi_bip_p->img_browser_content_path, (S8*) BIP_TMP_IMG_THM_NAME_FILE);

    /* delete tmp files that hasn't been deleted by accidence */

    /* PULL_initiator */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) srv_bip_p->bipi_cntx.img_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
    FS_Delete((U16*) tmp_file);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_open_imglist_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  The return value of FS_Open
 *****************************************************************************/
static int mmi_bipr_open_imglist_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open the image list file */
    srv_bip_p->bipr_cntx.fs_imglist = FS_Open((U16*) srv_bip_p->bipr_cntx.img_list_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (srv_bip_p->bipr_cntx.fs_imglist < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_imglist, 9);
        return srv_bip_p->bipr_cntx.fs_imglist;
    }
    /* open the handle-name file */
    srv_bip_p->bipr_cntx.fs_handle_name = FS_Open((U16*) srv_bip_p->bipr_cntx.img_handle_name_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (srv_bip_p->bipr_cntx.fs_handle_name < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_handle_name, 10);
        return srv_bip_p->bipr_cntx.fs_handle_name;
    }

    /* open the ucs2-name file */
    srv_bip_p->bipr_cntx.fs_ucs2_name = FS_Open((U16*) srv_bip_p->bipr_cntx.img_ucs2_name_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (srv_bip_p->bipr_cntx.fs_ucs2_name < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, srv_bip_p->bipr_cntx.fs_ucs2_name, 11);
        return srv_bip_p->bipr_cntx.fs_ucs2_name;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_write_imglist_xml_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  The return value of FS_Write
 *****************************************************************************/
static int mmi_bipr_write_imglist_xml_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 imglist_header[] = "<images-listing version=\"1.0\">\n";
    int wr_ret;
    UINT written_bytes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write tail to file*/
    wr_ret = FS_Write(
            srv_bip_p->bipr_cntx.fs_imglist, 
            imglist_header, strlen(imglist_header), 
            &written_bytes);

    if (wr_ret < 0)
        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 32);

    return wr_ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_write_imglist_xml_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  The return value of FS_Write
 *****************************************************************************/
static int mmi_bipr_write_imglist_xml_tail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 imglist_tail[] = "</images-listing>\n";
    int wr_ret;
    UINT written_bytes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write tail to file*/
    wr_ret = FS_Write(
            srv_bip_p->bipr_cntx.fs_imglist, 
            imglist_tail, strlen(imglist_tail), 
            &written_bytes);

    if (wr_ret < 0)
        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 33);

    return wr_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipr_write_imghdle_buf2file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hdlnm_buf    [IN]
 *  hdlnm_buflen [IN]
 *  xml_buf       [IN]
 *  xml_buflen    [IN]
 *  xml_item_size [IN]
 *  wr_cnt       [OUT]     
 * RETURNS
 *  The return value of FS_Write
 *****************************************************************************/
static int mmi_bipr_write_imghdle_buf2file(
                    S8 *hdlnm_buf, 
                    UINT32 hdlnm_buflen, 
                    S8 *xml_buf, 
                    UINT32 xml_buflen, 
                    UINT32 xml_item_size,
                    UINT32 *wr_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UINT written_bytes;
    int wr_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *wr_cnt = 0;
    
    /* write buffer data to file */
    wr_ret = FS_Write(
                srv_bip_p->bipr_cntx.fs_handle_name, 
                hdlnm_buf, hdlnm_buflen, 
                &written_bytes);                    
    
    if (wr_ret != FS_NO_ERROR)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 2);
        goto RET;
    }

    wr_ret = FS_Write(
                srv_bip_p->bipr_cntx.fs_imglist, 
                xml_buf, xml_buflen, 
                &written_bytes);   
    
    *wr_cnt = written_bytes/xml_item_size;

    if (wr_ret != FS_NO_ERROR)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, wr_ret, 3);
    }

RET:
    MMI_BIP_LOG2(MMI_BT_BIP_WRITE_IMGHDL_BUF2FILE_RETURN, wr_ret, *wr_cnt);
    
    return wr_ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bip_compose_imghandle_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imghandle   [OUT]
 *  count       [IN]     
 * RETURNS
 *  The return value of FS_Write
 *****************************************************************************/
static void mmi_bip_compose_imghandle_str(U8 *imghandle, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp_str[BT_BIP_IMG_HANDLE_LEN];
    U8 *dst, *src;
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((char*)imghandle, MMI_BIP_IMG_HANDLE_PREFIX);
    kal_sprintf((char*)tmp_str, "%d", count);
    len = strlen((char*)tmp_str);
    if (len > 0)
    {
        dst = (U8*) (imghandle + BT_BIP_IMG_HANDLE_LEN - len - 1);
        src = tmp_str;

        for (i = 0; i < len; i++)
            *dst++ = *src++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_construct_filter_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bip_filter_pattern      [?]     
 *  max_cnt                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_bip_construct_filter_pattern(FS_Pattern_Struct *bip_filter_pattern, U8 max_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_Pattern_Struct *p_pattern = bip_filter_pattern;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.jpg");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.jpeg");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.gif");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.bmp");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.wbmp");
    p_pattern++;
    i++;
#ifdef GDI_USING_PNG    
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.png");
    p_pattern++;
    i++;

    MMI_BIP_LOG(MMI_BT_BIP_PNG_MACRO_DEFINED);
#else    

    MMI_BIP_LOG(MMI_BT_BIP_PNG_MACRO_NOT_DEFINED);
#endif
    return i;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bip_get_imgfile_postfix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  postfix         [?]     
 *  tmp_file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bip_get_imgfile_postfix(S8 *postfix, U16 *tmp_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 img_type;
    bt_bip_img_format_enum img_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //img_type = gdi_image_get_type_from_file(tmp_file);
    img_type = mmi_bip_get_image_type((U16*)tmp_file);

    switch (img_type)
    {
        case BT_BIP_IMG_TYPE_JPEG:
            mmi_ucs2cpy(postfix, (S8*) L".jpg");
            break;
            
        case BT_BIP_IMG_TYPE_PNG:
            mmi_ucs2cpy(postfix, (S8*) L".png");
            break;
            
        case BT_BIP_IMG_TYPE_BMP:
            mmi_ucs2cpy(postfix, (S8*) L".bmp");
            break;
            
        case BT_BIP_IMG_TYPE_WBMP:
            mmi_ucs2cpy(postfix, (S8*) L".wbmp");
            break;
            
        case BT_BIP_IMG_TYPE_GIF:
            mmi_ucs2cpy(postfix, (S8*) L".gif");
            break;
            
        default:
            MMI_BIP_LOG(MMI_BT_BIP_DEFAULT_JPG);
            mmi_ucs2cpy(postfix, (S8*) L".jpg"); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_get_partial_imglist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [in] start index
 *  max_num           [in] max img handle number to return
 * RETURNS
 *  the real img handle number gotten 
 *****************************************************************************/
static S16 mmi_bip_get_partial_imglist(U16 start_index, U16 max_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hDstFile;
    FS_HANDLE hImglist;
    bt_bip_img_min_info_struct img_info;
    U32 offset;    
    U32 len;
    int ret, rt;
    S16 read_cnt = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_PARTIAL_IMGLIST, start_index, max_num);

    /* open the total img_list file */
    hImglist = FS_Open((U16*) srv_bip_p->bipr_cntx.img_list_path, FS_READ_ONLY);
    
    if (hImglist < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hImglist, 12);
        return 0;
    }
    /* open the cur_img_list file */
    hDstFile = FS_Open((U16*) srv_bip_p->bipr_cntx.cur_img_list_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (hDstFile < 0)
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hDstFile, 13);
        FS_Close(hImglist);
        return -1;
    }

    /* seek the img list file to proper offset */
    offset = start_index * sizeof(bt_bip_img_min_info_struct);
    ret = FS_Seek(hImglist, offset, FS_FILE_BEGIN);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);

    /* read out the source */
    ret = FS_Read(hImglist, &img_info, sizeof(bt_bip_img_min_info_struct), &len);
    MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 3);
    while (ret == FS_NO_ERROR && read_cnt < max_num && len > 0)
    {
        /* write into the dst file */
        rt = FS_Write(hDstFile, &img_info, sizeof(bt_bip_img_min_info_struct), &len);

        if (rt != FS_NO_ERROR)
        {
            MMI_BIP_LOG2(MMI_BT_BIP_FS_WRITE_RETURN, ret, 4);
            goto Ret_err;
        }

        MMI_BIP_LOG2(BT_MMI_BIP_GET_PARTIAL_IMGLIST, rt, len);
        read_cnt++;

        /* read out the next source */
        ret = FS_Read(hImglist, &img_info, sizeof(bt_bip_img_min_info_struct), &len);
    }
    
    FS_Close(hDstFile);
    FS_Close(hImglist);
    MMI_BIP_LOG1(MMI_BT_BIP_CONSTRUCT_IMGLIST_COUNT, read_cnt);

    return read_cnt;
    
Ret_err:

    FS_Close(hDstFile);
    FS_Close(hImglist);
    FS_Delete((U16*) srv_bip_p->bipr_cntx.cur_img_list_path);

    return -1;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_pull_get_filename_with_imghandle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [IN] 
 *  file_name       [OUT]
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_bipr_pull_get_filename_with_imghandle(S8 *img_handle, S8 *file_name, S8 *ucs2_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    FS_HANDLE hUcs2File;
    bip_img_handle_name_struct info;
    bip_img_ucs2_name_struct ucs2name_info;
    U32 read_len;
    int ret;
    MMI_BOOL found_name = MMI_FALSE;
    MMI_BOOL found_ucs2_name = MMI_FALSE;
    int offset;
    S32 filename_len, share_folder_len;
    U8  find_rst = GOEP_NOT_FOUND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_FILENAME_WITH_HANDLE, img_handle);
    
    hFile = FS_Open((U16*) srv_bip_p->bipr_cntx.img_handle_name_path, FS_READ_ONLY);
    if (hFile > 0)
    {
        ret = FS_Read(hFile, &info, sizeof(info), &read_len);
        MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 1);
        while (ret == FS_NO_ERROR && read_len > 0)
        {
            if (strcmp(info.img_handle, img_handle) == 0)
            {
                /* find it */

                /* check filename length */
                share_folder_len = mmi_bt_get_setting_string(BTFF_ITEM_BIP_FLDR_PATH, NULL, 0);
                share_folder_len /= 2;
                filename_len = mmi_ucs2strlen((S8 *)info.found_name);
                if (share_folder_len + filename_len > SRV_FMGR_PATH_MAX_LEN)
                {
                    /* PATH is too long */
                    MMI_BIP_LOG2(MMI_BT_BIP_PATH_TOO_LONG, share_folder_len, filename_len);
                    MMI_BIP_LOG_PATH(info.found_name);
                    
                    /* return PATH TOO LONG */
                    find_rst = GOEP_REQ_URL_TOO_LARGE;
                    
                    break;
                }

                kal_wsprintf((U16 *)file_name, "%w%w", 
                    (U16 *)mmi_bt_get_setting_int(BTFF_ITEM_BIP_FLDR_PATH),
                    (U16 *)info.found_name);

                if (ucs2_name != NULL)
                {
                    if (info.ucs2_name_idx >= 0)
                    {
                        MMI_BIP_LOG1(MMI_BT_BIP_NEED_FIND_UCS2_NAME, info.ucs2_name_idx);    
                        /* open and read ucs2_name file */
                        hUcs2File = FS_Open((U16*) srv_bip_p->bipr_cntx.img_ucs2_name_path, FS_READ_ONLY);
                        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hUcs2File, 8);
                        if (hUcs2File >= 0)
                        {
                            offset = info.ucs2_name_idx * sizeof(ucs2name_info);
                            ret = FS_Seek(hUcs2File, offset, FS_FILE_BEGIN);
                            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
                            if (ret == offset)
                            {
                                ret = FS_Read(hUcs2File, &ucs2name_info, sizeof(ucs2name_info), &read_len);
                                MMI_BIP_LOG2(MMI_BT_BIP_FS_READ_RETURN, ret, 2);
                                if (ret == FS_NO_ERROR)
                                {
                                    MMI_BIP_LOG(MMI_BT_BIP_FOUND_UCS2_NAME);
                                    mmi_ucs2cpy((S8*) ucs2_name, (S8*) ucs2name_info.ucs2_name);
                                    found_ucs2_name = MMI_TRUE;
                                }
                            }
                            FS_Close(hUcs2File);
                        }
                    }

                    if (!found_ucs2_name)
                    {
                       /* use the raw file name */
                       MMI_BIP_LOG(MMI_BT_BIP_NOT_FOUND_UCS2_NAME);
                       mmi_ucs2cpy((S8*) ucs2_name, (S8*) info.found_name);
                    }
                }
                
                found_name = MMI_TRUE;
                MMI_BIP_LOG(MMI_BT_BIP_FIND_FILENAME);
                MMI_BIP_LOG_PATH(file_name);
                break;
            }
            ret = FS_Read(hFile, &info, sizeof(info), &read_len);
        }
        ret = FS_Close(hFile);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, ret);
    }
    else
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 24);
    }

    if (!found_name)
    {
        MMI_BIP_LOG(MMI_BT_BIP_GET_FILENAME_WITH_HANDLE_FAILED);
    }
    else
    {
        find_rst = BT_BIP_CNF_SUCCESS;
    }
    
    return find_rst;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_construct_recved_thm_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path_file      
 *  dst_path            
 *  path_size               
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_bip_error_enum mmi_bip_rename_pulled_thm(S8 * dst_thm_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bip_error_enum rst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_PULLED_THM);

    mmi_asc_to_ucs2((S8*) dst_thm_name, (S8*) srv_bip_p->bipi_cntx.img_handle);
    mmi_ucs2cat((S8*) dst_thm_name, (S8*) L"_thm");
    /* append postfix: thm always is jpg */
    mmi_ucs2cat((S8*) dst_thm_name, (S8*) L".jpg");

    /* rename the tmp file name */
    rst = mmi_bip_rename_recved_file(
        (U16*) srv_bip_p->bipi_cntx.thm_path,
        (U16*) dst_thm_name,
        (U16*) BIP_PULL_I_TMP_FILENAME);
    
    return rst;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_create_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename          [in]  file name    
 * RETURNS
 *  bip error 
 *****************************************************************************/
mmi_bt_bip_error_enum mmi_bip_create_file(U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bip_error_enum rst = MMI_BIP_SUCCESS;
    int hFile;
    U16 *path = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hFile = FS_Open((U16*)filename, FS_CREATE_ALWAYS);
    if (hFile >= 0)
    {
        FS_Close(hFile);
    }
    else
    {
        MMI_BIP_LOG2(MMI_BT_BIP_FS_OPEN_RETURN, hFile, 15);

        if (hFile == FS_PATH_NOT_FOUND)
        {
            /* get the path info */
            path = OslMalloc(SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH);
            if (path == NULL)
            {
                MMI_BIP_LOG(MMI_BT_BIP_OSLMALLOC_FAILED);
                return MMI_BIP_ERR_OUT_OF_MEMORY;
            }
            memset(path, 0, SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH);

            mmi_bip_get_file_name(filename, path, NULL, 0);

            /* create the folder */
            hFile = FS_CreateDir((U16*)path);
            MMI_BIP_LOG2(MMI_BT_BIP_FS_CREATEDIR_RETURN, hFile, 21);

            OslMfree(path);

            if (hFile >= 0)
            {
                  hFile = FS_Open((U16*)filename, FS_CREATE_ALWAYS);
                if (hFile >= 0)
                {
                    FS_Close(hFile);
                }
            }
        }
        if (hFile < 0)
        {
            rst = mmi_bt_bip_convert_fs_err_to_bip_err(hFile);
        }      
    }     

    return rst;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_is_recving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: 
 *    BOOL
 *****************************************************************************/
MMI_BOOL mmi_bipi_pull_is_recving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_RECVING,srv_bip_p->bipi_cntx.state);
    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_ABORTING:
        case SRV_BIPI_STATE_IDLE:
        case SRV_BIPI_STATE_CONNECTED:
        case SRV_BIPI_STATE_CONNECTING:
        case SRV_BIPI_STATE_DISCONNECTING:
            return MMI_FALSE;
            
        default:
            return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_pull_is_connecting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: 
 *   BOOL
 *****************************************************************************/
MMI_BOOL mmi_bipi_pull_is_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_CONNECTING,srv_bip_p->bipi_cntx.state);
    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_GETTING_IMGLIST:
        case SRV_BIPI_STATE_CONNECTING:
        case SRV_BIPI_STATE_CONNECTED:
            return MMI_TRUE;
            
        default:
            return MMI_FALSE;
    }
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_getting_thm
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: 
 *   BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_bipi_pull_is_getting_thm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_GETTING_THM,srv_bip_p->bipi_cntx.state);
    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_THM)
    {
        MMI_BIP_LOG(MMI_BT_BIPI_PULL_IS_GETTING_THM_RETURN_TRUE);
        return MMI_TRUE;
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIPI_PULL_IS_GETTING_THM_RETURN_FALSE);
        return MMI_FALSE;
    }
}


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
#endif
#endif  /* __MMI_BIP_SUPPORT__ */
#endif  /* __MMI_BT_MTK_SUPPORT__ */
