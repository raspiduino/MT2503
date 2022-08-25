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
 *  PhoneBookpbapcWearable.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PHONE_BOOK_PBAPC_WEARABLE_H__
#define __PHONE_BOOK_PBAPC_WEARABLE_H__

#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)

#include "MMIDataType.h"
#include "MMI_include.h"

#include "MMI_common_app_trc.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "custom_phb_config.h"
#include "mmi_frm_scenario_gprot.h"
#include "MenuCuiGprot.h"

#include "PhbpbapSrvGprot.h"
#include "UcmSrvGprot.h"
#include "SmsUmBtMapProt.h"
#include "SmsAppGprot.h"
#include "UCMGProt.h"
#include "BtcmSrvGprot.h"

#include "Vcard_lib.h"

#include "PhoneBookResDef.h"
#include "mmi_rp_app_phonebook_def.h"
#include "PhoneBookProt.h"
#include "PhbCuiGprot.h"


#define MAX_PHB_PBAPC_MAX_FIELDS                        (5)

#define MMI_PHB_PBAPC_TRACE_GROUP                       TRACE_GROUP_9

//#define MMI_PHB_PBAPC_READ_PHONE_ONLY

typedef struct
{
    S32 ret;
    S32 sel_index;
} mmi_phb_pbapc_sel_num_rsp_struct;

typedef struct
{
    U8 cb_type; /* 0: pse entry, 1: select number */
    void *type_rsp;
    void *user_data;
} mmi_phb_pbapc_cb_info_struct;

typedef S32(*mmi_phb_pbapc_cb_func)(mmi_phb_pbapc_cb_info_struct *cb_info);


typedef struct
{
    MMI_ID parent_id;
    srv_phb_pbap_storage_enum read_storage;
    U16 total_pse_contact;
    U16 pse_phone_num;
    U16 pse_sim_num;
    MMI_BOOL data_ready;
    U16 pse_list_index;/* highlight item index*/
    U16 pse_entry_index;/*store_index*/
    srv_phb_pbap_storage_enum contact_storage;

    /* select number operation 0: msg, 1: call. */
    U8 op_type;
    void *sel_num_ud;
    mmi_phb_pbapc_cb_func sel_cb_func;
    MMI_ID sel_num_pid;
    mmi_phb_pbapc_phb_info_struct sel_phb_info;
    S32 sel_hlight_index;/*chose which number in view*/
    /* view pse contact detail */
    mmi_phb_pbapc_phb_info_struct pse_phb;
    S32 hlight_index;
    /* read pse cb info */
    void *user_data;
    mmi_phb_pbapc_cb_func cb_func;
    /* global buff */
    srv_phb_pbapc_list_entry_struct  pse_contact[MMI_PHB_PBAPC_MAX_PSE_CONTACT];
    /* PHB search suppport */
#if 0
/* under construction !*/
/* under construction !*/
#endif
    MMI_BOOL is_full;

    /* select contact cui cntx */
    mmi_id cui_sel_contact_pid;
    void *cui_sel_contact_ud;
    U16 cui_pse_list_index;
    U16 cui_pse_entry_index;
    srv_phb_pbap_storage_enum cui_contact_storage;
    mmi_phb_pbapc_phb_info_struct cui_pse_phb;
    /* list type, 0: phb, 1: cui */
    U8 list_type;

    U16 *local_contact_id;
    U16 local_contact_count;
    U16 local_contact_hlight_index;
    U16 *qsearch_input_buffer;
    U16 phb_input_buffer[MMI_PHB_NAME_LENGTH + 1];
    U16 cui_input_buffer[MMI_PHB_NAME_LENGTH + 1];
    U16 local_qsearch_input_buffer[MMI_PHB_NAME_LENGTH + 1];

    /* high light tab, 0: init, 1: local, 2: bt */
    U8 phb_list;
    U8 cui_list;
    /* list state: 0: init, 1: active, 2: inactive */
    U8 list_state;
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
    /* symbol picker */
    //U8 symbol_show;
    /* state: 0: null, 1: call */
    U8 phb_state;

    /* loading */
    MMI_ID load_gid;
#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
    U16 contact_array[SRV_PHB_PBAPC_CONTACT_COUNT];                     /* contact list content */
    U16 contact_count;                      /* contact count */
#endif
    /*for V3.0 */
    srv_phb_pbapc_btd_enum bt_index;
    U8 is_stop[SRV_PBAPC_LINK_NUM];
    U8 is_inbg[SRV_PBAPC_LINK_NUM];
} mmi_phb_pbapc_cntx_struct;


/* func */

void mmi_phb_pbapc_entry_list_tab(void);

void mmi_phb_pbapc_exit_list_tab(void);

void mmi_phb_pbapc_entry_list(void);

void mmi_phb_pbapc_exit_list(void);

mmi_phb_pbapc_cntx_struct *mmi_phb_pbapc_get_cntx(void);

void mmi_phb_pbapc_set_list_type(U8 list_type);

void mmi_phb_pbapc_select_op_number(mmi_id parent_id, mmi_phb_pbapc_cb_func sel_cb_func,
                        void *user_data, mmi_phb_pbapc_phb_info_struct *phb_info);

/* local */

static void mmi_phb_pbapc_show_loading(MMI_ID parent_id, MMI_ID scrn_id);

static MMI_RET mmi_phb_pbapc_loading_scrn_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_pse_list_loading_abort(void);

static void mmi_phb_pbapc_pse_list_op_option(void);

static void mmi_phb_pbapc_pse_list_connect(void);


static void mmi_phb_pbapc_pse_list_highlight_hdlr(S32 item_index);

static S32 mmi_phb_pbapc_pse_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);

static void mmi_phb_pbapc_pse_list_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2);

static void mmi_phb_pbapc_entry_show_loading(void);

static S32 mmi_phb_pbapc_search_function(U8 *keyword);

static void mmi_phb_pbapc_show_pse_list(void);

static void cui_phb_pbapc_view_pse_contact(mmi_id parent_id, U16 entry_index, srv_phb_pbap_storage_enum storage);

static void mmi_phb_pbapc_pse_list_call(void);


static mmi_ret mmi_phb_pbapc_view_pse_contact_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_show_loading_abort(MMI_ID parent_id, MMI_ID scrn_id);

static MMI_RET mmi_phb_pbapc_view_contact_scrn_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_show_pse_contact_detail(void);

static U16 mmi_phb_pbapc_get_num_type(U8 num_type);

static MMI_BOOL mmi_phb_pbapc_set_pse_view_flags(S32 index, U32* flag, U32* flag_ex);

static void mmi_phb_pbapc_view_contact_highlight_hdlr(S32 index);

static void mmi_phb_pbapc_view_contact_option(void);

static void  mmi_phb_pbapc_view_contact_op_msg(S32 index);

static void  mmi_phb_pbapc_view_contact_op_call(S32 index);

static void  mmi_phb_pbapc_save_pse_contact(void);

static S32 mmi_phb_pbapc_view_sel_num_cb(mmi_phb_pbapc_cb_info_struct *cb_info);

static void mmi_phb_pbapc_view_contact_option_back(void);

static MMI_RET mmi_phb_pbapc_select_op_number_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_show_select_number(void);

static void mmi_phb_pbapc_select_number_hlight_hdlr(S32 index);

static void mmi_phb_pbapc_select_num_done(S32 ret);

static void mmi_phb_pbapc_select_num_ok(void);

static void mmi_phb_pbapc_select_num_cancel(void);

mmi_ret mmi_phb_pbapc_notify_evt_hdlr(mmi_event_struct *evt);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_phb_pbapc_bt_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif

/* select cui */

static mmi_ret cui_phb_pbapc_select_contact_proc(mmi_event_struct *evt);

static void cui_phb_pbapc_select_contact_entry(void);

static void cui_phb_pbapc_select_contact_exit(void);

static void cui_phb_pbapc_select_contact_local_entry(void);

static void cui_phb_pbapc_select_contact_local_exit(void);

static void cui_phb_pbapc_select_contact_bt_entry(void);

static void cui_phb_pbapc_select_contact_bt_exit(void);

static S32 cui_phb_pbapc_local_get_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items);

static pBOOL cui_phb_pbapc_local_get_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2);

static void cui_phb_pbapc_local_show_list(void);

static void cui_phb_pbapc_local_list_highlight_hdlr(S32 item_index);

static void cui_phb_pbapc_local_list_option(void);

static void cui_phb_pbapc_local_list_option_back(void);

static void cui_phb_pbapc_select_contact_send_req_close(void);

static void cui_phb_pbapc_bt_send_select_result(mmi_phb_pbapc_phb_info_struct *pse_phb, S32 ret);

static void cui_phb_pbapc_pre_select_contact(void);
#if 0
/* under construction !*/
#endif
static S32 cui_phb_pbapc_pre_select_contact_number_cb(mmi_phb_pbapc_cb_info_struct *cb_info);

static void cui_phb_pbapc_bt_send_select_result_ext(mmi_phb_pbapc_phb_info_struct *pse_phb, S32 index, S32 ret);


MMI_BOOL mmi_pbapc_is_bqb_test();

void mmi_pbapc_bqb_start();

static mmi_ret mmi_pbapc_bqb_grp_proc();

static mmi_ret mmi_pbapc_bqb_scr_proc(mmi_event_struct *evt);

static void mmi_pbapc_bqb_show();

static void mmi_pbapc_bqb_highlight_hdlr(S32 index);

static void mmi_pbapc_bqb_option();

static void mmi_pbapc_bqb_back();

static void mmi_pbapc_bqb_read_folder();

static S32 mmi_pbapc_bqb_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

static void mmi_pbapc_bqb_abort();

static void mmi_phb_pbapc_do_by_select(void);


#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#endif /* __PHONE_BOOK_PBAPC_H__ */

