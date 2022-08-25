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
 *  MMSAppOp.h
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  This file contains declaration of APIs defined in MMSAppExt.c and definitions of 
 *  structures and unions used in MMSAppExt.c
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMSAPPOP_H
#define MMSAPPOP_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmssrvgprot.h"
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif 

#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif 

#ifdef __MMI_OP12_TOOLBAR__
#include "IdleToolbarGprot.h"
#endif 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
typedef enum
{
    E_HS_STATE_NONE,
    E_HS_STATE_GET_RECENT_EVENT,
    E_HS_STATE_GET_SOFT_NOTE_EVENT,
    E_HS_STATE_GET_UNREAD_MSG_COUNT_EVENT,
    E_HS_STATE_GET_DATA_EVENT,
    E_HS_STATE_INERUPT_PHONE_SUIT_EVENT,
    E_HS_STATE_MAX
} mmi_umms_op_hs_state;

typedef struct
{
    U32 msg_id;
    U32 num_of_msg_req_by_hs;
    U32 num_of_msg_req_by_hs_for_recent_event;
    U32 hs_start_index;
    U32 hs_start_index_for_recent_event;
    MMI_BOOL wap_is_not_ready_for_indicator;
    MMI_BOOL wap_is_not_ready_for_soft_notes;
    MMI_BOOL wap_is_not_ready_for_data;
    MMI_BOOL g_hs_new_mms_arrived;
    MMI_BOOL g_hs1_new_mms_arrived;
    MMI_BOOL wap_is_not_ready_for_recent_events;
    MMI_BOOL wap_ready_ind_received;
    U32 user_data[MMI_HS_MAX_MENU_DATA_NEW_MMS_NUM];
    U32 user_data_recent_events[MMI_HS_MAX_RECENT_EVENT_NUM];
    mmi_umms_op_hs_state current_hs_event;

} mmi_umms_op_hs_cntx_struct;

typedef struct
{
    //U8 hs_active;
    //BOOL is_recent_event;
    BOOL hs_new_mms_arrived;
} mmi_umms_op_op11_struct;

#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP12_TOOLBAR__
typedef struct
{
    U32 msg_id;
    U32 num_of_msg_req_by_tb;
    U32 umms_tb_start_index;
    U32 user_data[MMI_TB_MAX_NEW_MESSAGE_NUM];
    MMI_BOOL is_tb_active;
    MMI_BOOL is_tb_active_from_idle;
    MMI_BOOL wap_is_ready_for_tb;
    MMI_BOOL umms_tb_new_mms_arrived;
    MMI_BOOL umms_view_from_tb;

    MMI_BOOL tb_active;
    mmi_umms_tb_state current_tb_state;
} mmi_umms_op_tb_struct;

typedef struct
{
    MMI_BOOL tb_active;
    mmi_umms_tb_state current_tb_state;
} mmi_umms_op_op12_struct;
#endif /* __MMI_OP12_TOOLBAR__ */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
typedef struct
{
    U32 msg_id;
    U32 num_of_msg_req_by_hs;
    U32 num_of_msg_req_by_hs_for_recent_event;
    U32 hs_start_index;
    U32 hs_start_index_for_recent_event;
    MMI_BOOL wap_is_not_ready_for_indicator;
    MMI_BOOL wap_is_not_ready_for_soft_notes;
    MMI_BOOL wap_is_not_ready_for_data;
    MMI_BOOL g_hs_new_mms_arrived;
    MMI_BOOL g_hs1_new_mms_arrived;
    MMI_BOOL wap_is_not_ready_for_recent_events;
    MMI_BOOL wap_ready_ind_received;
    MMI_BOOL is_recent_event;
    MMI_BOOL hs_active;
    //U32 user_data[MMI_HS_MAX_MENU_DATA_NEW_MMS_NUM];
    //U32 user_data_recent_events[MMI_HS_MAX_RECENT_EVENT_NUM];
    // mmi_umms_op_hs_state current_hs_event;
    S32 sidebar_id;
    S32 shct_id;
    S32 indctr_id;
    mmi_op11_hs32_shct_data_struct *shct_data_p;
} mmi_umms_op_hs32_cntx_struct;

typedef struct
{
    U8 hs_active;
    /* BOOL is_recent_event; */
    BOOL hs_new_mms_arrived;
} mmi_umms_op_op11_hs32_struct;
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

extern void mmi_umms_op_wap_ready_hdlr(void);

#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif 

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
extern void mmi_umms_op_hs_clear_recent_event(void);

extern void mmi_umms_op_set_key_hndlr_for_mms_view_from_data_ext(U16 key_code, U16 key_type, void *user_data);
extern void mmi_umms_op_set_key_hndlr_for_mms_view_from_data(U16 key_code, U16 key_type, void *user_data);
extern void mmi_umms_op_hs_get_recent_mms(S32 num);
extern void mmi_umms_op_hs_get_recent_mms_rsp_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_op_set_data_for_recent_event(srv_mms_recent_evt_list_rsp_struct *msg_rsp);
extern U32 mmi_umms_op_get_recent_event_msg_list_count(void);
extern U32 mmi_umms_op_get_start_index_for_recent_event(void);
extern void mmi_umms_op_init_hs_context(void);
extern void mmi_umms_op_hs_entry_clear_all_event(void);
extern void mmi_umms_op_hs_get_header(U32 user_data, U16 key_code, BOOL is_recent_event);

extern void mmi_umms_op_set_op11_data(BOOL hs_active, BOOL is_recent_event);
extern void mmi_umms_op_set_new_mms_arrived(MMI_BOOL is_new_mms_arrived);
extern mmi_umms_op_op11_struct *mmi_umms_op_get_op11_data(void);
extern void mmi_umms_op_reset_op11_data(void);

#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

#ifdef __MMI_OP12_TOOLBAR__
extern MMI_BOOL mmi_umms_op_toolbar_option_hdlr(U16 menu_id);
extern void mmi_umms_op_tb_evnt_query_mms(S32 num);
extern void mmi_umms_op_tb_evnt_query_mms_rsp_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_op_update_start_index_for_tb(U32 new_start_index);
extern void mmi_umms_op_set_data_for_tb(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp);
extern void mmi_umms_op_set_key_hndlr_for_mms_view_from_tb(U16 key_code, U16 key_type, void *user_data);
extern void mmi_umms_op_set_key_hndlr_for_multi_hndlr_for_tb(U16 key_code, U16 key_type);
extern void mmi_umms_op_init_tb_context(void);
extern void mmi_umms_op_tb_entry_option_live(void);
extern void mmi_umms_op_view_from_tb(U16 key_code, U32 user_data);
extern void mmi_umms_op_tb_call(U16 key_code, U32 user_data);
extern void mmi_umms_op_tb_call_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void mmi_umms_op_tb_delete(U16 key_code, U32 user_data);

extern void mmi_umms_op_set_op12_data(BOOL tb_active, mmi_umms_tb_state current_tb_state);
extern mmi_umms_op_op12_struct *mmi_umms_op_get_op12_data(void);
extern void mmi_umms_op_reset_op12_data(void);

#endif /* __MMI_OP12_TOOLBAR__ */ 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern void mmi_mms_query_sidebar_info_for_ready(void);
extern void mmi_mms_query_sidebar_info(S32 sidebar_id, S32 indctr_id);
extern void mmi_umms_op_hs32_get_mms_unread_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_op11_hs32_get_mms_shct_data_on_ready(void);
extern void mmi_op11_hs32_get_mms_shct_data(S32 sidebar_id, S32 shct_id, void *shct_data_p);
extern void mmi_umms_op_get_hs32_unread_msg_list_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_op_set_data_for_hs32(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp);
extern void mmi_mms_update_op11_hs32_shct_data(void);
extern void mmi_umms_op_set_op11_hs32_data(MMI_BOOL hs_active);
extern void mmi_umms_op_set_hs32_new_mms_arrived(MMI_BOOL is_new_mms_arrived);
extern mmi_umms_op_op11_hs32_struct *mmi_umms_op_get_op11_hs32_data(void);
extern void mmi_umms_op_reset_op11_hs32_data(void);
extern void mmi_umms_op_hs32_get_header(U32 user_data, U16 key_code);
extern void mmi_umms_op_init_hs32_context(void);
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

extern mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para);

#endif /* __MMI_MMS_2__ */ 
#endif /* MMSAPPOP_H */ 

