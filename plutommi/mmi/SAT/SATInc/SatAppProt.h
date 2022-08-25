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
 *  SatAppProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SAT feature.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_SATAPPPROT_H
#define _MMI_SATAPPPROT_H

#include "MMIDataType.h"
#include "SatSrvGprot.h"
#include "UcmSrvGprot.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "NotificationGprot.h"
#include "mmi_frm_scenario_gprot.h"

typedef enum
{   
    SAT_RES_OK,
    SAT_RES_IMMEDIATE_OK,
    SAT_RES_DELAY_OK,
    SAT_RES_HELP,
    SAT_RES_BACK,
    SAT_RES_CANCEL,
    SAT_RES_ABORT,
    SAT_RES_TERMINATED,
    SAT_RES_NO_RESPONSE
} mmi_sat_response_enum;

typedef struct
{
    mmi_sim_enum sim_id;
    srv_sat_cmd_enum cmd_type;
    void *data_ptr;
    FuncPtr func_p;

    U8 menu_index;
    U8 item_index;

    U8  input_min_len;
    U8  input_max_len;
    CHAR *input_buf;
    MMI_BOOL is_yes_no;

    MMI_BOOL is_wait_scrn;
    U16 wait_string;
    U16 wait_image;

    MMI_BOOL is_sent;
    U8  alm_enable_flag;
} mmi_sat_group_data_struct;

typedef enum
{
    SAT_TIMER_WAIT,
    SAT_TIMER_CLEAR_DELAY,
    SAT_TIMER_NO_RESPONSE,
    SAT_TIMER_HELP,
    SAT_TIMER_POPUP,
    SAT_TIMER_PLAY_TONE,
    SAT_TIMER_REFRESH_REBOOT
} mmi_sat_timer_enum;

typedef struct
{
    srv_sat_cmd_enum cmd_type;
    MMI_BOOL is_inform;
} mmi_sat_timer_data_struct;

typedef struct
{
    mmi_sim_enum sim_id;
    MMI_ID parent_grp_id;
} mmi_sat_wait_scrn_data_struct;


extern U16 gCurrLangIndex;

extern mmi_sim_enum mmi_sat_call_type_to_sim_id(srv_ucm_call_type_enum call_type);

extern MMI_BOOL mmi_sat_enter_app_group(mmi_id parent_grp_id, mmi_sim_enum sim_id, mmi_id *grp_c_id, void *user_data);
extern mmi_ret mmi_sat_app_group_proc(mmi_event_struct *evt);

extern mmi_ret mmi_sat_recv_ind(mmi_event_struct *evt); 
extern mmi_ret mmi_sat_recv_ucm_ind(mmi_event_struct *evt);
extern mmi_ret mmi_sat_recv_idle_ind(mmi_event_struct *evt);

extern void mmi_sat_handle_setup_menu_cmd(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_handle_instant_cmd(srv_sat_proactive_sim_struct *cmd_info);

extern void mmi_sat_refresh_app_menu(mmi_sim_enum sim_id, MMI_BOOL is_present);

/* setup menu */
//extern void mmi_sat_main_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern void mmi_sat_main_menu_scrn_exit(void);
extern MMI_BOOL mmi_sat_main_menu_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);		// slim

extern void mmi_sat_main_and_sub_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info);

/* select item */
//extern void mmi_sat_select_item_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_sub_menu_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_sub_menu_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);		// slim

extern U8 mmi_sat_get_menu_id(mmi_id gid);
extern void mmi_sat_hilit_menu_index_hdlr(S32 index);
extern PU8 mmi_sat_get_cmd_hint(srv_sat_cmd_enum cmd_type, srv_sat_cmd_enum for_cmd_type);

/* display text */
extern void mmi_sat_display_text_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_display_text_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_display_text_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);		// slim

/* get inkey */
//extern void mmi_sat_get_inkey_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_get_inkey_scrn_entry(mmi_scrn_essential_struct* scrn_info);
//extern MMI_BOOL mmi_sat_get_inkey_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);	// slim

extern void mmi_sat_get_in_scrn_entry(mmi_scrn_essential_struct* scrn_info);

extern void mmi_sat_get_process(srv_sat_proactive_sim_struct *cmd_info);
extern MMI_BOOL mmi_sat_get_input_and_inkey_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);
/* get input */
//extern void mmi_sat_get_input_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_get_input_scrn_entry(mmi_scrn_essential_struct* scrn_info);
//extern MMI_BOOL mmi_sat_get_input_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);	// slim

extern MMI_BOOL mmi_sat_input_text_check(mmi_sat_group_data_struct *group_data);
extern void mmi_sat_input_option_hdlr(void);
extern mmi_ret mmi_sat_input_option_proc(mmi_event_struct *evt);

/* play tone */
//extern void mmi_sat_play_tone_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_play_tone_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_play_tone_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);		// slim

/* send sms */
extern void mmi_sat_send_sms_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_send_sms_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern void mmi_sat_send_s_scrn_entry(mmi_scrn_essential_struct* scrn_info);

/* send ss */
//extern void mmi_sat_send_ss_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_send_ss_scrn_entry(mmi_scrn_essential_struct* scrn_info);

//extern void mmi_sat_send_ss_result_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_send_ss_result_scrn_entry(mmi_scrn_essential_struct* scrn_info);
//extern MMI_BOOL mmi_sat_send_ss_result_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);			// slim

extern MMI_BOOL mmi_sat_send_ss_and_ussd_result_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);

/* send ussd */
extern void mmi_sat_send_ussd_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_send_ussd_scrn_entry(mmi_scrn_essential_struct* scrn_info);

extern void mmi_sat_send_ussd_ss_result_scrn_entry(mmi_scrn_essential_struct* scrn_info);

//extern void mmi_sat_send_ussd_result_process(srv_sat_proactive_sim_struct *cmd_info);
//extern void mmi_sat_send_ussd_result_scrn_entry(mmi_scrn_essential_struct* scrn_info);
//extern MMI_BOOL mmi_sat_send_ussd_result_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);	// slim

/* setup call */
extern void mmi_sat_setup_call_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_setup_call_confirm_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_setup_call_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type, srv_ucm_result_enum *error_code);

extern void mmi_sat_setup_call_ucm_requset(mmi_sim_enum sim_id, srv_ucm_result_enum *error_code);
extern void mmi_sat_ucm_display_popup(srv_ucm_result_enum result);
extern MMI_BOOL mmi_sat_save_calling_icon(mmi_sim_enum sim_id, PU8 icon_data, CHAR *save_path);

/* send dtmf */
extern void mmi_sat_send_dtmf_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_send_dtmf_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_send_dtmf_response(mmi_sat_group_data_struct *group_data, mmi_sat_response_enum res_type);	// slim

/* at command */
#ifdef __SATCB__
extern void mmi_sat_run_at_cmd_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_run_at_cmd_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern void mmi_sat_run_at_cmd_srcn_exit(void);
#endif /* __SATCC__ */

/* refresh */
extern void mmi_sat_sim_refresh_process(srv_sat_proactive_sim_struct *cmd_info);
extern MMI_BOOL mmi_sat_reboot_scrn_entry(mmi_scenario_id scen_id, void *arg);
extern void mmi_sat_nw_detach_before_reboot(mmi_sim_enum sim_id);
extern void mmi_sat_nw_detach_before_reboot_hdlr(void *info, int mod_src);

/* launch browser */
#ifdef __SATCC__
#ifdef BROWSER_SUPPORT
extern void mmi_sat_launch_browser_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_launch_browser_confirm_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern void mmi_sat_launch_browser_method(mmi_id gid);
extern MMI_BOOL mmi_sat_launch_browser_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type);
#endif /* BROWSER_SUPPORT */ 

#endif /* __SATCC__ */

#ifndef __SAT_LOWCOST_UI_DISABLE__
extern void mmi_sat_language_notification_process(srv_sat_proactive_sim_struct *cmd_info);
extern mmi_ret mmi_sat_language_notification_done(mmi_event_struct *param);
#endif /* __SAT_LOWCOST_UI_DISABLE__ */

/* class e */
#ifdef __SATCE__
/* open channel */
extern void mmi_sat_open_channel_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_open_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_open_channel_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type);

/* close channel */
extern void mmi_sat_close_channel_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_close_channel_scrn_entry(mmi_scrn_essential_struct* scrn_info);

#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
extern MMI_BOOL mmi_sat_close_channel_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type);
#endif

/* send data */
extern void mmi_sat_send_data_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_send_data_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_send_data_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type);

/* receive data */
extern void mmi_sat_recv_data_process(srv_sat_proactive_sim_struct *cmd_info);
extern void mmi_sat_recv_data_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern MMI_BOOL mmi_sat_recv_data_response(mmi_sim_enum sim_id, mmi_sat_response_enum res_type);
#endif  /* __SATCE__ */

extern void mmi_sat_me_response_to_cmd(mmi_id grp_id, mmi_sat_response_enum res_type);
extern void mmi_sat_response_ok_hdlr(void);
extern void mmi_sat_response_input_digit_olny_hdlr(void);
extern void mmi_sat_response_back_hdlr(void);
extern void mmi_sat_response_help_hdlr(void);
extern void mmi_sat_response_terminated_hdlr(void);
extern void mmi_sat_response_cancel_hdlr(void);
extern void mmi_sat_response_abort_hdlr(void);

extern void mmi_sat_set_key_and_pen_handler(void);
extern mmi_ret mmi_sat_scrn_generic_leave_proc(mmi_event_struct *param);
extern void mmi_sat_scrn_generic_exit(void);

extern mmi_ret mmi_sat_key_proc(mmi_event_struct *evt);
//extern void mmi_sat_touch_pen_pre_hdlr(U16 touch_event);
extern void mmi_sat_touch_pen_pre_hdlr(mmi_event_struct *evt);																//vikrant

extern void mmi_sat_please_wait_scrn_pre_entry(mmi_sim_enum sim_id, U16 string, U16 image);
extern void mmi_sat_please_wait_scrn_entry(mmi_scrn_essential_struct* scrn_info);
extern void mmi_sat_please_wait_exit(void);

extern void mmi_sat_timer_expiry_hdlr(srv_sat_callback_struct *callback_data);

#ifdef __SAT_DISABLE_ALARM__
extern void mmi_sat_disable_alarm(void);
extern void mmi_sat_enable_alarm(void);
#endif

extern void mmi_sat_measure_string(S32 *width, S32 *height);
extern void mmi_sat_create_folder(void);
extern CHAR *mmi_sat_create_calling_icon_path(mmi_sim_enum sim_id, CHAR **save_path);

#endif /* _MMI_SATAPPPROT_H */
