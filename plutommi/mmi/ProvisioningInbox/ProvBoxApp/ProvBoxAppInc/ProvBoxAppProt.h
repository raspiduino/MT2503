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
 * ProvBoxAppProt.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef MMI_PROVBOX_APP_PROT_H
#define MMI_PROVBOX_APP_PROT_H

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "MMIDataType.h"
#include "mmi_inet_app_trc.h"

#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
#include "mmi_frm_gestures_gprot.h"
#endif
#endif

#include "wgui_touch_screen.h"

#include "UMGProt.h"

#ifdef __MMI_PROV_IN_UM__
#include "UmSrvDefs.h"
#include "UmSrvStruct.h"
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#include "Vsrv_ncenter.h"
#include "UMNcenterGProt.h"
#endif

#include "CcaSrvGprot.h"

#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"

/*----------------------------------------------------------------------------*/
/* TRACE group                                                                */
/*----------------------------------------------------------------------------*/
#define MMI_PROVBOXAPP_TRC_INFO                    MMI_INET_TRC_G9_PROVINBOX
#define MMI_PROVBOXAPP_TRC_WARNING                 MMI_INET_TRC_G9_PROVINBOX
#define MMI_PROVBOXAPP_TRC_ERROR                   MMI_INET_TRC_G9_PROVINBOX

/* ProvBox context structure */
/*****************************************************************************
 * const variable
 *****************************************************************************/
#define MMI_PROVBOX_MSG_ID_INVAILD           (-1)

#define MMI_PROVBOX_MAX_MEM_SIZE             (3*1024)

#define MMI_PROVBOX_FLAG_BIT_NMGR_NOTIFY     (0X00000001)
#define MMI_PROVBOX_FLAG_BIT_INSTALL         (0X00000002)
#define MMI_PROVBOX_FLAG_BIT_CLOSING_WIDGET_INST (0X00000004)

#define MMI_PROVBOX_FLAG_BIT_IDX_NMGR_NOTIFY (0)
#define MMI_PROVBOX_FLAG_BIT_IDX_INSTALL     (0 + 1)
#define MMI_PROVBOX_FLAG_BIT_IDX_CLOSING_WIDGET_INST    (0 + 2)

#define MMI_PROVBOX_NMGR_QUERY_TEXT_MAX_LEN  (32)

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#define MMI_PROVBOX_FTE_TOOLBAR_NUM          (2)

#define MMI_PROVBOX_VIEWER_FTE_TOOLBAR_NUM   (2)
#endif

#define MMI_PROVBOX_PROPERTIES_MAX_LEN       (160)
#define MMI_PROVBOX_PROPERTIES_BUF_SIZE      ((MMI_PROVBOX_PROPERTIES_MAX_LEN + 1) * ENCODING_LENGTH)

#define MMI_PROVBOX_ADDR_MAX_LEN             (60)

#define MMI_PROVBOX_UCS2_NEW_LINE            (L"\n")
#define MMI_PROVBOX_UCS2_SPACE               (L" ")
#define MMI_PROVBOX_UCS2_EMPTY_STRING        (L"")


#define MMI_PROVBOX_LIST_TIME_MAX_LEN        (15 + 1 + 10)

#define MMI_PROVBOX_DATE_TIME_MAX_LEN        (14)
#define MMI_PROVBOX_DATE_TIME_BUF_SIZE       ((MMI_PROVBOX_DATE_TIME_MAX_LEN + 1) * ENCODING_LENGTH)


#define MMI_PROVBOX_IP_MAX_LEN               (15)
#define MMI_PROVBOX_IP_MAX_SEG_VAL           (255)
#define MMI_PROVBOX_IP_DOT                   L'.'
#define MMI_PROVBOX_IP_MAX_SEG_LEN           (3)
#define MMI_PROVBOX_IP_MAX_SEG_NUM           (4)

#define MMI_PROVBOX_ITER_VIEWER_MID_STR_MAX_LEN (255)

/*****************************************************************************
 * Macro define
 *****************************************************************************/

#define MMI_PROVBOX_GET_BIT_VALUE(_param, _idx, _bit) \
                (((_param) & (_bit)) >> (_idx))
            
#define MMI_PROVBOX_SET_BIT_VALUE(_param, _bit) \
            do {                                \
                (_param) = (_param) | (_bit);   \
            } while(0)
            
#define MMI_PROVBOX_RESET_BIT_VALUE(_param, _bit) \
            do {                                  \
                (_param) = (_param) & ~(_bit);    \
            } while(0)
            
#define MMI_PROVBOX_GET_AVALIABLE_VALUE(_param, _idx) \
                (_param) & (1 << (_idx))

#define MMI_PROVBOX_RESET_VALUE(_param, _idx)     \
            do {                                  \
                (_param) &= ~(1 << (_idx));       \
            } while(0)

/*****************************************************************************
 * inter date struct define
 *****************************************************************************/
typedef struct
{
    MMI_ID um_grp_id;
    MMI_ID group_id;
    MMI_ID menu_id;
    U32 flags;
    U32 cur_msg_id;
    U16 cur_box_type;
    U16 cur_hilit_idx;
    S32 traverse_msg_num;
    void *user_data;   /* use for inteviewer */
    WCHAR *properties;
#ifdef __MMI_UM_ITERATOR_VIEWER__
    WCHAR * um_iter_viewer_mid_str;
    mmi_um_iter_viewer_result_struct* um_iter_node;
#endif
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    MMI_BOOL view_from_widget;
#endif
#if defined(__MMI_NCENTER_SUPPORT__)
    vsrv_ngroup_handle ncenter_gid;
    vsrv_notification_handle ncenter_nid;
    vsrv_notification_handle ncenter_full_nid;
#endif
    NMGR_HANDLE hnmgr;
} mmi_provbox_context_struct;


/*****************************************************************************
 * Enum define
 *****************************************************************************/
typedef enum
{
    MMI_PROVBOX_OP_NONE,
    MMI_PROVBOX_OP_INITING,
    MMI_PROVBOX_OP_DELECTING,
    MMI_PROVBOX_OP_DELECTING_ALL,
    MMI_PROVBOX_OP_INSTALLING,
    MMI_PROVBOX_OP_GETTING_LIST_INFO,
    MMI_PROVBOX_OP_READING_PROPERTIES,
    MMI_PROVBOX_OP_END_OF_ITEM
} mmi_provbox_op_enum;

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
typedef enum
{
    MMI_PROVBOX_FTE_TOOLBAR_CMD_INSTALL = 0,
    MMI_PROVBOX_FTE_TOOLBAR_CMD_DELETE,
    MMI_PROVBOX_FTE_TOOLBAR_CMD_MAX_ITEM
} mmi_provbox_fte_toolbar_cmd_enum;
#endif

typedef enum
{
    MMI_PROVBOX_TRANS_ID_NULL = 0,
    MMI_PROVBOX_TRANS_ID_PROVBOX_GET_MSG_NUM,
    MMI_PROVBOX_TRANS_ID_PROVBOX_UPDATA_MSG_NUM,
    MMI_PROVBOX_TRANS_ID_PROVBOX_UM_OP_GET_MSG_NUM,
    MMI_PROVBOX_TRANS_ID_PROVBOX_GET_LISG_INFO_BY_INDEX,
    MMI_PROVBOX_TRANS_ID_PROVBOX_OP_GET_LIST_INFO_BY_ID,
    MMI_PROVBOX_TRANS_ID_PROVBOX_UM_GET_LIST_INFO_BY_IDS,
    MMI_PROVBOX_TRANS_ID_PROVBOX_TRAVERSE_GET_LIST_INFO_BY_IDS,
    MMI_PROVBOX_TRANS_ID_PROVBOX_GET_SORT_INFO,
    MMI_PROVBOX_TRANS_ID_PROVBOX_GET_MSG_INFO,
    MMI_PROVBOX_TRANS_ID_DELETE_MSG,
    MMI_PROVBOX_TRANS_ID_DELETE_ALL,
    MMI_PROVBOX_TRANS_ID_MULTI_OP,
    MMI_PROVBOX_TRANS_ID_UPDATE_MSG_INFO,
    MMI_PROVBOX_TRANS_ID_CCA_PROCESS_MSG,
    MMI_PROVBOX_TRANS_ID_MAX_ITEM
} mmi_provbox_trans_id_enum;

#ifdef __MMI_NCENTER_SUPPORT__
typedef enum
{
#ifdef __MMI_PROV_IN_UM__
    MMI_PROVBOX_NCENTER_NID_START = MMI_UM_UI_NCENTER_PROV_BASE,
#else
    MMI_PROVBOX_NCENTER_NID_START = 0,
#endif
    MMI_PROVBOX_NCENTER_NID_NEW_SETTING = MMI_PROVBOX_NCENTER_NID_START,
    MMI_PROVBOX_NCENTER_NID_INBOX_FULL,
    MMI_PROVBOX_NCENTER_NID_MAX_ITEM
} mmi_provbox_ncenter_nid_enum;
#endif

/*****************************************************************************
 * typedef define
 *****************************************************************************/
typedef  void (*mmi_provbox_event_hdlr_funcp)(mmi_event_struct* evt);

/*****************************************************************************
 * struct define
 *****************************************************************************/
typedef struct
{
    // U32 event_id;
    mmi_provbox_event_hdlr_funcp call_bacl_func;
} mmi_provbox_event_hdlr_struct;

/* =======================================================================
 * ProvBox initial handle
 * ======================================================================= */
extern mmi_provbox_context_struct *mmi_provbox_get_cntx(void);

extern void mmi_provbox_app_enter_init(void);

extern void mmi_provbox_app_deinit(void);

extern void mmi_provbox_app_error_hdlr(void);

/* =======================================================================
 * Operate message handle
 * ======================================================================= */
extern srv_provbox_result_enum mmi_provbox_msg_install(U32 msg_id);

extern void mmi_provbox_msg_install_done(srv_cca_process_prov_msg_cnf_struct *data);

extern mmi_ret mmi_provbox_msg_delete_confirm(mmi_event_struct *evt);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
extern mmi_ret mmi_provbox_msg_move_to_achive_confirm(mmi_event_struct *evt);
#endif

extern void mmi_provbox_msg_delete(U32 msg_id);

extern void mmi_provbox_msg_read_properties(U32 msg_id, WCHAR * properties);

extern void mmi_provbox_handle_new_msg_ind(srv_provbox_evt_new_msg_ind_struct *data);

/* =======================================================================
 * memory handle
 * ======================================================================= */
extern void *mmi_provbox_malloc(U32 size);

extern void mmi_provbox_free(void *p);

extern KAL_ADM_ID mmi_provbox_mem_init(U32 buffer);

/* =======================================================================
 * inter utilite handle
 * ======================================================================= */
extern MMI_BOOL mmi_provbox_is_in_call(void);

extern U8 mmi_provbox_get_sims_status(void);

extern MMI_BOOL mmi_provbox_is_item_shown(void);

extern MMI_BOOL mmi_provbox_is_unread_msg(srv_provbox_msg_read_status_enum read_status);

extern void mmi_provbox_get_msg_address(
                WCHAR *addr, mmi_sim_enum sim_id,
                srv_provbox_msg_type_enum msg_type, 
                srv_provbox_addr_struct* msg_addr);

extern MMI_BOOL mmi_provbox_ip_addr_is_validate(U16 *ip, S32 len);

extern void mmi_provbox_compose_data_time(WCHAR* data_time, U32 timestamp);

extern void mmi_provbox_compose_properties(WCHAR* properties, srv_provbox_msg_cmn_info_struct *data);

extern U32 mmi_provbox_get_new_msg_idx(void);

extern U8 mmi_provbox_get_new_msg_sim_id(void);

extern U16 mmi_provbox_get_msg_hilit_idx(void);

extern mmi_provbox_result_enum mmi_provbox_result_pboxsrv2mine(srv_provbox_result_enum srv_result);

#ifdef __MMI_PROV_IN_UM__

extern srv_um_msg_box_enum mmi_provbox_box_type_pbox2um(srv_provbox_box_type_enum srv_box_type);

extern void mmi_provbox_add_address(
                srv_um_msg_detail_struct* detail,
                WCHAR* addr,
                srv_um_addr_enum type,
                srv_um_addr_group_enum group);
         
extern void mmi_provbox_remove_address(srv_um_msg_detail_struct* detail);

#endif /* __MMI_PROV_IN_UM__ */
/* =======================================================================
 * inter UI handle
 * ======================================================================= */
extern mmi_event_notify_enum mmi_provbox_get_notify_event(U32 sim_idx);

extern U16 mmi_provbox_get_sim_msg_title(U32 sim_idx);

extern U16 mmi_provbox_get_sim_icon(U32 sim_idx);

/* =======================================================================
 * Screen group handle
 * ======================================================================= */
extern MMI_ID mmi_provbox_scrn_group_create(MMI_ID parent_gid);
extern void mmi_provbox_scrn_group_close(void);

extern mmi_ret mmi_provbox_scrn_group_proc(mmi_event_struct *evt);

extern mmi_ret mmi_provbox_scrn_group_evt_hdlr(mmi_event_struct *evt, mmi_um_opt_para_struct* um_para);

/* =======================================================================
 * List screen handle
 * ======================================================================= */
extern srv_provbox_result_enum mmi_provbox_hilit_idx_set_cur_id(U32 hilit_idx);

extern void mmi_provbox_list_scrn_entry(void);

extern void mmi_provbox_refresh_list_scrn(void);

extern void mmi_provbox_options_create(void);

/* =======================================================================
 * Progress handle
 * ======================================================================= */
extern void mmi_provbox_progress_scrn_show(mmi_provbox_op_enum op_type);

extern void mmi_provbox_progress_scrn_close(void);

/* =======================================================================
 * Properties screen handle
 * ======================================================================= */
extern void mmi_provbox_properties_scrn_show(void);

/* =======================================================================
 * Popup and confirm handle
 * ======================================================================= */
extern void mmi_provbox_popup(U16 text, mmi_event_notify_enum type);

extern void mmi_provbox_notify_popup(srv_provbox_notify_type_enum notify_type);

extern void mmi_provbox_popup_by_str(UI_string_type text, mmi_event_notify_enum type);

extern void mmi_provbox_confirm_display(U16 title_id, 
                mmi_event_notify_enum event_type,
                mmi_proc_func callback,
                void *user_data);

/* =======================================================================
 * Status icon handle
 * ======================================================================= */
extern void mmi_provbox_update_status_icon(void);

extern void mmi_provbox_hide_status_icon(void);


/* =======================================================================
 * NUM handle
 * ======================================================================= */
#ifndef __MMI_PROV_IN_UM__

extern S32 mmi_provbox_list_get_item_info(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
extern void mmi_provbox_fte_toolbar_hdlr(S32 index);

extern void mmi_provbox_fte_intuitive_cmd_handler(mmi_tap_type_enum tap_type, S32 index);
#endif

#endif /* __MMI_PROV_IN_UM__ */

/* =======================================================================
 * UM primitive message handle
 * ======================================================================= */
extern void mmi_provbox_msg_handle_cca_process_prov_msg_cnf(void *msg);

extern void mmi_provbox_send_cca_process_prov_msg_req(U32 msg_id);

/* =======================================================================
 * Iterview screen handle
 * ======================================================================= */
#if defined(__MMI_PROV_IN_UM__) && defined(__MMI_UM_ITERATOR_VIEWER__)
extern MMI_BOOL mmi_provbox_um_iter_query_node(void);

extern void mmi_provbox_um_iter_launch_prev(void);

extern void mmi_provbox_um_iter_launch_next(void);

extern void mmi_provbox_um_iter_viewer(void);

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
extern void mmi_provbox_um_left_gesture_hdlr(mmi_frm_gesture_event_enum gesture_event);

extern void mmi_provbox_um_right_gesture_hdlr(mmi_frm_gesture_event_enum gesture_event);
#endif

extern MMI_RET mmi_provbox_um_iter_viewer_refresh(mmi_um_refresh_evt_struct* refresh_ind);
#endif /* __MMI_UM_ITERATOR_VIEWER__  && __MMI_PROV_IN_UM__ */

#ifdef __MMI_NCENTER_SUPPORT__
extern void mmi_provbox_ncenter_notify_inbox_full(void);
#endif

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
#endif /* MMI_PROVBOX_APP_PROT_H */
