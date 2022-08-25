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
 *  UCMProtBT.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM app internal header file
 *
 * Author:
 * -------
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_BT_PROT_H
#define UCM_BT_PROT_H

/* Include files---------------------------------------------------------------------------- */

#include "MMI_features.h"

#ifdef __MMI_BT_CALL_SUPPORT__
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "wgui_categories_list.h"
#include "custom_mmi_default_value.h"
#include "UcmGprot.h"
#include "app_datetime.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "AlertScreen.h"
#include "BTDialerSrvGprot.h"
#include "wgui_categories_CM.h"
#include "PhbpbapSrvGprot.h"
#include "UcmBTSrvGprot.h"
#include "UcmGProtBT.h"

/* Define----------------------------------------------------------------------------------- */
#define MMI_UCM_NOTIFY_TIMEOUT_BT  (2000)
#define MMI_UCM_MO_PROCESSING_TIMEOUT_BT (12000)
#define MMI_UCM_FORCE_REFRESH_TIME_BT (5000)

#define MMI_UCM_VIB_THEN_RING_DURATION 6000 /* move from profile module */
#define MMI_UCM_DTMF_LEN                   (40)
#define MMI_UCM_END_TEXT_LEN_BT                (50)

/* Maximum number length */
#define SRV_UCM_BT_MAX_ERR_MSG_LEN (50)

#define __MMI_UCM_BT_IN_BAND_RING_TONE_OUT__ 1
/* typedef enum----------------------------------------------------------------------------- */

typedef enum
{
	MMI_UCM_BT_ACTION_NONE,
	MMI_UCM_BT_ACTION_ADD_MO,
	MMI_UCM_BT_ACTION_ADD_MT,
	MMI_UCM_BT_ACTION_DELETE,
	MMI_UCM_BT_ACTION_UPDATE
}mmi_ucm_bt_action_enum;

typedef enum
{
    MMI_UCM_BT_NONE_TONE = 0,
    MMI_UCM_BT_RING_TONE,
    MMI_UCM_BT_WAITING_TONE,
#ifdef __MMI_UCM_BT_IN_BAND_RING_TONE_OUT__
    MMI_UCM_BT_INBAND_RING_TONE,
#endif
    MMI_UCM_BT_INCOMING_TONE_TOTAL
} mmi_ucm_bt_mt_tone_enum;

/* typedef struture------------------------------------------------------------------------- */


typedef struct
{
    MYTIME call_duration;
    U16 *disp_msg;
    U16 *disp_name;
    U16 image_id;
    U16 tone_id;
} mmi_ucm_bt_call_end_struct;

typedef struct
{
    srv_ucm_bt_ind_opcode_enum opcode;
    S32 srv_hd;
} mmi_ucm_bt_dev_noti_struct;


/* Variable----------------------------------------------------------------------------------- */
typedef struct
{
    U8 call_id;
    U8 dir;
    U8 mode;
    U8 multiParty;
    srv_ucm_bt_call_state_enum call_state; //to maintain the varios states of a call like Active, Hold, etc
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    MYTIME start_time;//Maintain time duration of the active call
}mmi_ucm_call_state_cntx_struct;
typedef struct
{
    U8 call_id;
    srv_ucm_bt_call_state_enum call_state;
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];
    U8 dir;
    U8 mode;
    U8 multiParty;
}mmi_ucm_call_info_cntx_struct;

typedef struct
{
    U16 disp_dtmf[MMI_UCM_DTMF_LEN + 1 + 1];
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    S32 hilite_call_id;
    S32 hilite_dev;
    S32 refresh_srv;
    mmi_id incall_opt_cui_id;
    mmi_ucm_bt_mt_tone_enum tone_type;
#ifdef  __MMI_FTE_SUPPORT__
    mmi_ucm_bt_auto_lock_state_enum auto_lock_state;
#endif /* __MMI_FTE_SUPPORT__ */
    mmi_ucm_after_make_call_callback callback;
    void* callback_para;
    mmi_ucm_call_state_cntx_struct release_call_info;
    U8 disconnecting;
    MMI_BOOL is_hide_screen;
    MMI_BOOL is_need_accept;
    MMI_BOOL is_end_all_action;
} mmi_ucm_bt_cntx_struct;

extern mmi_ucm_bt_cntx_struct *g_ucm_p_bt;

#ifdef __MMI_UCM_BT_CALL_RECORDER__ 
extern MYTIME g_ucm_bt_start_record_time;
#endif
/* Function---------------------------------------------------------------------------------- */
/* UcmEventHdlr.c */

/* ==================================================================================== */
/* =============Kernel EventHdlr related=============================================== */
/* ==================================================================================== */

/* ==================================================================================== */
/* ============= VT Core related====================================================== */
/* ==================================================================================== */ 

/* UcmUi.c */
/* ==================================================================================== */
/* =============Initialization========================================================= */
/* ==================================================================================== */
void mmi_ucm_init_context_bt(void);
void mmi_ucm_bt_register_hf_connection_event(srv_bt_dialer_notify_event_struct* notify);
void mmi_ucm_entry_error_message_bt(void);
void mmi_ucm_call_launch_bt(mmi_ucm_bt_make_call_para_struct *make_call_para);
mmi_ucm_bt_action_enum mmi_ucm_sync_call_list(mmi_ucm_call_state_cntx_struct* call_state_cntx,mmi_ucm_call_info_cntx_struct* call_info);
srv_ucm_bt_call_state_enum mmi_ucm_call_state_type_btsrv_to_app_bt(srv_bt_dialer_AtCallState_enum btsrv_type);
void mmi_ucm_send_update_clog_evt_bt(void);
void mmi_ucm_clean_all_bt(void);
void mmi_ucm_play_incoming_ringtone_bt(void);
void mmi_ucm_stop_incoming_ringtone_bt(void);
void mmi_ucm_incoming_call_sendkey_bt(void);
MMI_BOOL mmi_ucm_get_hide_state_bt(void);
void mmi_ucm_set_hide_state_bt(MMI_BOOL new_hide_state);
void mmi_ucm_release_ind_bt(srv_ucm_bt_release_call_ind_struct* call_info);
void mmi_ucm_refresh_ind_bt(S32 srv_hd);
#ifdef __MMI_UCM_BT_CALL_RECORDER__
void mmi_ucm_start_record_option_bt(void);
void mmi_ucm_end_record_option_bt(void);
void mmi_ucm_start_record_evt_hdlr_bt(mdi_result result, void *user_data);
void mmi_ucm_sndrec_in_call_action_bt(void);
#endif/*__MMI_UCM_BT_CALL_RECORDER__*/

/* ==================================================================================== */
/* =============UI Screen flow========================================================= */
/* ==================================================================================== */
void mmi_ucm_exit_incoming_call_bt(mmi_scrn_essential_struct* scr_info); 
void mmi_ucm_exit_outgoing_call_bt(mmi_scrn_essential_struct* scr_info);
void mmi_ucm_exit_in_call_bt(mmi_scrn_essential_struct* scr_info); 

void mmi_ucm_highlight_in_call_item_bt(S32 index);     
void mmi_ucm_tab_jump_bt(S32 index);
void mmi_ucm_tab_prev_bt(void); 
void mmi_ucm_tab_next_bt(void); 
void mmi_ucm_tab_highlight_bt(void); 
void mmi_ucm_go_back_screen_check_bt(void);

void mmi_ucm_hold_action_bt(void);
void mmi_ucm_retrieve_action_bt(void);
void mmi_ucm_swap_action_bt(void);
void mmi_ucm_end_single_action_bt(void);
void mmi_ucm_answer_action_bt();
void mmi_ucm_dial_action_bt(srv_ucm_bt_atd_act_req_struct* act_req);
void mmi_ucm_end_all_action_bt(void);
void mmi_ucm_switch_audio_action_bt(void);
void mmi_ucm_force_refresh_action_bt(S32 srv_hd);

/* ==================================================================================== */
/* =============category ============================================================== */
/* ==================================================================================== */


void mmi_ucm_enter_incoming_call_bt(void);
void mmi_ucm_entry_incoming_call_bt(mmi_scrn_essential_struct* scr_info);

void mmi_ucm_enter_outgoing_call_bt(void);
void mmi_ucm_entry_outgoing_call_bt(mmi_scrn_essential_struct* scr_info);


void mmi_ucm_enter_in_call_bt(void);
void mmi_ucm_entry_in_call_bt(mmi_scrn_essential_struct* scr_info);


void mmi_ucm_entry_call_end_bt(mmi_scrn_essential_struct* scr_info);
void mmi_ucm_exit_call_end_bt(mmi_scrn_essential_struct* scr_info);

void mmi_ucm_enter_dialling_bt(void);
void mmi_ucm_entry_dialling_bt(mmi_scrn_essential_struct* scr_info);

void mmi_ucm_entry_notify_bt(mmi_scrn_essential_struct* scr_info);

/* ==================================================================================== */
/* =============UI hint =============================================================== */
/* ==================================================================================== */

/* ==================================================================================== */
/* =============highlight ============================================================= */
/* ==================================================================================== */


void mmi_ucm_delete_all_screen_bt(void);
void mmi_ucm_close_cui_bt(mmi_id *cui_id);
U16 mmi_ucm_get_call_type_string_id_bt(srv_ucm_bt_call_state_enum call_state);

/* ==================================================================================== */
/* =============VT related============================================================= */
/* ==================================================================================== */


/* Group proc */
mmi_ret mmi_ucm_incall_sg_proc_bt(mmi_event_struct *evt);
mmi_ret mmi_ucm_call_end_screen_delete_proc_bt(mmi_event_struct *evt);
MMI_ID mmi_ucm_sg_create_bt(MMI_ID parent_id, MMI_ID group_id);
void mmi_ucm_go_back_BT_call_screen_bt(void);
void mmi_ucm_bt_enter_processing_screen(MMI_ID SG_id, S32 srv_hd);
void mmi_ucm_bt_close_processing_scrn(void);
void mmi_ucm_bt_entry_processing_screen(mmi_scrn_essential_struct* scr_info);
mmi_ret mmi_ucm_bt_processing_screen_delete_proc(mmi_event_struct *evt);
void mmi_ucm_end_and_accpet_confirm_bt(MMI_ID parent_id);
void mmi_ucm_end_and_accpet_entry_confirm_bt(mmi_scrn_essential_struct* scr_info);
void mmi_ucm_end_and_accpet_entry_confirm_bt(mmi_scrn_essential_struct* scr_info);
void mmi_ucm_end_and_accpet_confirm_yes_hdlr_bt(void);
mmi_ret mmi_ucm_act_callback_bt(mmi_event_struct *event);
void mmi_ucm_end_btdialer_and_accept_option_bt(void);
mmi_ret mmi_ucm_incall_opt_proc_bt(mmi_event_struct *evt);
mmi_ret mmi_ucm_call_select_bt_proc(mmi_event_struct *evt);
void mmi_ucm_in_call_endkey_bt(void);
void mmi_ucm_play_waitingtone_bt(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_endkey_bt
 * DESCRIPTION
 *  End key behavior function, FW will call this function when there is any call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_outgoing_call_endkey_bt(void);
void mmi_ucm_exec_dial_cb_bt(srv_ucm_result_enum result);
void mmi_ucm_speaker_vol_ind_bt(U8 gain);
MMI_BOOL mmi_ucm_vol_control_callback_bt(U8 volume, MMI_BOOL is_mute);
void mmi_ucm_speaker_vol_ind_bt(U8 gain);
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_bt(void);
void mmi_ucm_deint_bt(void);
MMI_BOOL mmi_ucm_is_dev_allow_bt(S32 srv_hd);
void mmi_ucm_set_hilite_call_info_bt(U8 call_id);
void mmi_ucm_set_hilite_dev_info_bt(S32 srv_hd);
void mmi_ucm_another_device_notify_bt(srv_ucm_bt_ind_opcode_enum op, S32 srv_hd);

#ifdef __MMI_FTE_SUPPORT__
void mmi_ucm_FTE_unlock_hdlr_bt(void);
void mmi_ucm_FTE_fill_unlock_item_bt(wgui_catcall_fte_iconbar_item_struct *item);
void mmi_ucm_FTE_auto_lock_timeout_hdlr_bt(void);
void mmi_ucm_FTE_screen_touch_hdlr_bt(MMI_BOOL is_touched);
MMI_BOOL mmi_ucm_FTE_is_lock_mechanism_applied_screens_bt(void);
void mmi_ucm_FTE_scrn_update_hdlr_by_lock_state_bt(mmi_ucm_bt_auto_lock_state_enum lock_state);
void mmi_ucm_auto_lock_fsm_hdlr_bt(mmi_ucm_bt_auto_lock_trigger_event_enum event);
#endif

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
extern srv_prof_ret mmi_ucm_btb_notify_callback(srv_prof_ret result);
extern void mmi_ucm_btb_send_notify(U16 notify_id);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

#endif /* __MMI_BT_CALL_SUPPORT__ */
#endif /* UCM_BT_PROT_H */ 

