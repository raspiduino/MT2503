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
 * ProvBoxAppGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox UI main procedure.
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

#ifndef MMI_PROVBOX_APP_GPROT_H
#define MMI_PROVBOX_APP_GPROT_H

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#ifdef __MMI_PROV_IN_UM__
#include "UMGprot.h"

#include "UMSrvGprot.h"
#endif

#include "mmi_cb_mgr_gprot.h"

#include "provboxsrvgprot.h"

/*****************************************************************************
 * Const variable
 *****************************************************************************/
typedef enum
{
    MMI_PROVBOX_RESULT_OK = 0,
    MMI_PROVBOX_RESULT_FAIL,
    MMI_PROVBOX_RESULT_MEM_FULL,
    MMI_PROVBOX_RESULT_BOX_FULL,
    MMI_PROVBOX_RESULT_MSG_NOT_FOUND,
    MMI_PROVBOX_RESULT_SYS_BUSY,
    MMI_PROVBOX_RESULT_CCA_BUSY,
    MMI_PROVBOX_RESULT_PARTIAL_DELETED,
    MMI_PROVBOX_RESULT_READING_MSG,
    MMI_PROVBOX_RESULT_MAX_ITEM
} mmi_provbox_result_enum;

/*****************************************************************************
 * Macro define
 *****************************************************************************/
 
 
extern void mmi_provbox_app_init(void);

extern MMI_BOOL mmi_provbox_app_is_ready(void);

extern MMI_ID mmi_provbox_scrn_group_get_id(void);

/*===========================================================================
 * Event Handle
 *==========================================================================*/
extern mmi_ret mmi_provbox_event_hdlr(mmi_event_struct* evt);

#if defined(__DM_LAWMO_SUPPORT__) && defined(__MMI_PROV_IN_UM__)
extern mmi_ret mmi_provbox_lawmo_lock_ind_hdlr(mmi_event_struct *evt);

extern mmi_ret mmi_provbox_lawmo_wipe_ind_hdlr(mmi_event_struct* evt);
#endif /* __DM_LAWMO_SUPPORT__ && __MMI_PROV_IN_UM__ */

/*===========================================================================
 * NMGR Handle
 *==========================================================================*/
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
extern void mmi_provbox_nmgr_query(void);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

extern void mmi_provbox_nmgr_hdlr(void *user_data);
extern U8 mmi_provbox_idle_new_msg_check(void);
extern void mmi_provbox_idle_new_msg_ind(void);
extern void mmi_provbox_nmgr_cancel(void);

/*===========================================================================
 * FTE Handle
 *==========================================================================*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_PROV_IN_UM__) && defined(__MMI_TOUCH_SCREEN__)

extern MMI_BOOL mmi_provbox_um_reply_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_forward_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_send_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_edit_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_resend_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_delete_check(srv_um_msg_enum msg_type, U32 msg_id);

extern MMI_BOOL mmi_provbox_um_activate_reply(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);

extern MMI_BOOL mmi_provbox_um_activate_forward(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);

extern MMI_BOOL mmi_provbox_um_activate_send(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);

extern MMI_BOOL mmi_provbox_um_activate_edit(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);

extern MMI_BOOL mmi_provbox_um_activate_resend(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);

extern MMI_BOOL mmi_provbox_um_activate_delete(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id);
#endif /* __MMI_FTE_SUPPORT__ && __MMI_PROV_IN_UM__ && __MMI_TOUCH_SCREEN__ */



#ifndef __MMI_PROV_IN_UM__
extern MMI_ID mmi_provbox_pre_entry_from_message(MMI_ID parent_grp_id);

#else /* define __MMI_PROV_IN_UM__ */

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
extern void mmi_provbox_um_set_sort_info(
                srv_um_list_idx_data_union *list_data, 
                const srv_provbox_msg_cmn_info_struct* msg_info,
                const S16 msg_size,
                U8 list_idx_type);
#endif

#ifdef __MMI_UM_CONVERSATION_BOX__
extern S32 mmi_provbox_um_traverse_process_msg_detail(
               srv_provbox_msg_cmn_info_struct *info, 
               S16 msg_size,
               U32 um_user_data,
               srv_um_detail_field_enum um_detail_field,
               srv_um_traverse_func um_traverse_callback);
#endif


extern void mmi_provbox_um_set_msg_info(
                srv_um_msg_info_struct *um_msg_info, 
                srv_provbox_msg_cmn_info_struct *cmn_info);
                
extern MMI_ID mmi_provbox_um_enter_msg(mmi_um_entry_msg_struct* um_entry_info);

extern MMI_MENU_ID mmi_provbox_um_get_option_menu_id(void);

extern MMI_RET mmi_provbox_um_menu_cui_proc(mmi_event_struct *evt, mmi_um_opt_para_struct* para);


extern void mmi_provbox_send_um_new_msg_ind(U8 sim_id, U32 msg_id, U32 timestamp);

extern MMI_RET mmi_provbox_msg_handle_um_entry_folder(mmi_event_struct *para);

extern void mmi_provbox_send_um_refresh_ind(U32 msg_id, void* user_data,srv_um_refresh_enum type);

extern void mmi_provbox_um_scrn_deinit(void);

extern void mmi_provbox_um_iter_launch_viewer(MMI_ID parent_gid, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type);

#endif /* __MMI_PROV_IN_UM__ */

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
 
#endif /* MMI_PROVBOX_APP_GPROT_H */
