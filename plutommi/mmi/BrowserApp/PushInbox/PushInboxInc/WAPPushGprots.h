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
 * WAPPushGprots.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file have the declaration of external function.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __PUSH_MSG_GPROT__
#define __PUSH_MSG_GPROT__
//#include "WapPushSrvGprots.h"
    #include "pmg_struct.h"
    #include "MsgViewerCuiGProt.h"
 
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "UmSrvDefs.h"

#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_PUSH_IN_UM__
#include "UMGProt.h"
#endif

/*----------------------------------------------------------------*/
/* Functions declaration for global functions                     */
/*----------------------------------------------------------------*/

extern void mmi_wap_push_nmgr_get_unread_msg(void);
extern void mmi_wap_push_nmgr_cancel_unread_msg(void);
extern MMI_BOOL srv_push_nmgr_if_new_msg_event(void);
extern void mmi_brw_push_pre_entry_inbox_validation(void);
extern void mmi_wap_push_tb_evnt_query_push(S32 num);
extern MMI_BOOL mmi_brw_push_is_new_msg_popup_scr_active(void);
extern void mmi_push_um_delete_all_res(void *msg);
extern void mmi_push_handle_um_multiple_select_rsp(void *p);
extern MMI_ID mmi_push_pre_entry_push_setting(void);
extern void mmi_push_pre_entry_push_setting_ex(void);
extern MMI_BOOL mmi_push_close_push_inbox_screens (void);
//extern void mmi_wap_push_handle_add_bkm_rsp (srv_wap_push_add_bkm_error  ret_code);
extern MMI_ID mmi_brw_push_open_service_inbox (U16 title_icon_id);
extern void mmi_push_open_service_message_setting (U16 title_icon_id);
extern void mmi_wap_push_get_profile_info (U16 sim_id, wps_pmg_channel_struct *ch_info);
extern void mmi_wap_push_set_title_icon (U16 title_icon_id);

extern mmi_ret srv_push_entry_folder_hdlr(mmi_event_struct *para);
#ifdef __MMI_PUSH_IN_UM__
extern S32 mmi_wap_push_get_um_option_menu_id(void);
extern MMI_BOOL mmi_push_handle_entry_msg_wap_push(mmi_um_entry_msg_struct *entry_msg_param);
extern mmi_ret mmi_push_option_cb_hdlr(mmi_event_struct *menu_cui_evt, mmi_um_opt_para_struct * um_option_para);
extern mmi_ret mmi_wap_push_scrhdlr_lsk_um_list_opt_menu (mmi_event_struct *menu_cui_evt, mmi_um_opt_para_struct * um_option_para );

#ifdef __MMI_FTE_SUPPORT__
extern MMI_BOOL srv_push_check_um_delete (srv_um_msg_enum msg_type, U32 msg_id);
extern void srv_push_activated_um_delete (mmi_id scr_grp_id, srv_um_msg_enum msg_type, U32 msg_id);
#endif /* __MMI_FTE_SUPPORT__ */


#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __UM_SUPPORT__ 
extern void mmi_wap_push_if_launch_viewer (mmi_id parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type);
#endif

extern mmi_ret mmi_wap_push_service_msg_setting_proc (mmi_event_struct *evt);
extern void mmi_wap_push_setting_entry_main_menu (void);
extern void mmi_wap_push_entry_service_message (void);
extern mmi_ret mmi_wap_push_service_msg_main_manu_proc (mmi_event_struct *evt);

extern void cui_wap_push_service_msg_setting_launch (mmi_id parent_gid);
extern void cui_wap_push_service_msg_main_menu_launch (mmi_id parent_gid);
#endif /* __WAP_PUSH_SUPPORT__ */
#endif /* __PUSH_MSG_GPROT__ */
