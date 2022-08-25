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
 *  UcmUiBTl.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM kernel source file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_BT_CALL_SUPPORT__

#include "CommonScreens.h"
#include "UcmGProtBT.h"
#include "UcmProtBT.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_app_ucm_def.h"
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#include "mmi_rp_app_ucmbt_def.h"

#include "BtcmSrvGprot.h"
#include "BTDialerSrvGprot.h"
#include "Conversions.h"  // for mmi_chset_utf8_to_ucs2_string
#include "custom_ecc.h"
#include "csmcc_enums.h"
#include "UcmBTSrvGprot.h"
#include "GpioSrvGprot.h" // SRV_BACKLIGHT_SHORT_TIME
#include "VolumeHandler.h" // SetKeyPadVolUp
#include "Wgui_categories_util.h" // get_string
#include "wgui_touch_screen.h" // mmi_tap_type_enum
#include "GlobalResDef.h" // STR_GLOBAL_ERROR
#include "wgui_categories_popup.h" // ShowCategory63Screen
#include "PowerOnChargerProt.h" // ChgrPlayLowBatTone
#include "CharBatSrvGprot.h" // srv_charbat_is_low_battery
#include "UcmProt.h" // mmi_ucm_play_incoming_tone
#include "mmi_frm_scenario_gprot.h" // mmi_scenario_evt_struct
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
#include "mmi_frm_input_event.h"
#include "BTMMIAntilostScr.h"
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

#define __MMI_BT_BQB_TEST__ 1

#ifndef __MMI_TELEPHONY_SUPPORT__
static mmi_ucm_dial_from_bt_struct* g_dial_from_bt_para_p;
static mmi_ucm_make_call_para_struct* g_make_call_para_bt;
#endif

/* ==================================================================================== */
/* =============Initialization========================================================= */
/* ==================================================================================== */
void mmi_ucm_handle_incall_option_bt(mmi_id owner_gid);
void mmi_ucm_set_loud_speaker_bt(void);
static void mmi_ucm_enter_dtmf_editor_bt(void);
static void mmi_ucm_pre_entry_dtmf_editor_bt(void);
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
static void mmi_ucm_call_end_timeout_handler_bt(void);
static mmi_ret mmi_ucm_btb_input_event_proc(mmi_event_struct *evt);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_dtmf_to_ascii_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  digit     [IN]    
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_ucm_convert_dtmf_to_ascii_bt(U16 *digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (*digit)
    {
        case KEY_0:
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
            return '0' + (*digit) - KEY_0;
        case KEY_STAR:
            return '*';
        case KEY_POUND:
            return '#';
        default:
            return KEY_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_dtmf_action_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyCode     [IN]    
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_ucm_send_dtmf_action_bt(U16 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_digit;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_dtmf_act_req_struct act_req;
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asc_digit = mmi_ucm_convert_dtmf_to_ascii_bt(&keyCode);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SEND_DTMF, asc_digit);

    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, group_list))
    {
    }
    else if (srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, group_list))
    {
    }
    else
    {
        return;
    }

    srv_ucm_bt_query_call_data(group_list[0], &call_info);

    act_req.digit = asc_digit;
    act_req.srv_hd = call_info.srv_hd;
    srv_ucm_bt_act_request(SRV_UCM_BT_SEND_DTMF_ACT, &act_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_dtmf_by_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_ucm_send_dtmf_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);

    if (MMI_FALSE == wgui_inputs_dialer_is_dialer_keys(keyCode))
    {
        return;
    }

    /* For first spec digit keycode like '*' to disable highlight */
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    mmi_ucm_send_dtmf_action_bt(keyCode);
    mmi_ucm_pre_entry_dtmf_editor_bt();
    wgui_inputs_dialer_display_char(keyCode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_call_end
 * DESCRIPTION
 *  Enter call end popup screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_call_end_bt(mmi_ucm_bt_call_end_struct *call_end_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_need_accept = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p_bt->is_end_all_action && srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
    {
        is_need_accept = g_ucm_p_bt->is_need_accept;
        mmi_ucm_clean_all_bt();
        g_ucm_p_bt->is_need_accept = is_need_accept;
        mmi_ucm_delete_all_screen_bt();
    }
        
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    if (mmi_frm_group_is_present(GRP_ID_UCM_BT_CALL_END))
        return;
    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_CALL_END);
    mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_END);
    StartTimer(UCM_NOTIFY_DURATION_TIMER_BT, MMI_UCM_NOTIFY_TIMEOUT_BT, mmi_ucm_call_end_timeout_handler_bt);
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */

    if(mmi_frm_scrn_is_present(GRP_ID_UCM_BT_CALL_END, SCR_ID_UCM_BT_CALL_END, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_BT_CALL_END, SCR_ID_UCM_BT_CALL_END);
    }
    if (mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
    {
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    }
    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_CALL_END);

    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_BT_CALL_END, SCR_ID_UCM_BT_CALL_END, 
        (FuncPtr)mmi_ucm_entry_call_end_bt, 
        (void*)call_end_p);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_end_timeout_handler
 * DESCRIPTION
 *  ucm call end timeout handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_end_timeout_handler_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 call_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_END_TIMEOT_HANDLER, call_count, g_ucm_p_bt->is_end_all_action, g_ucm_p_bt->is_need_accept);

    StopTimer(UCM_NOTIFY_DURATION_TIMER_BT);
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_ucm_send_update_clog_evt_bt();
#else 
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_ACTIVE);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_HELD);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_END);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_FAIL);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLUP);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLDOWN);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLMUTE);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

    if (g_ucm_p_bt->is_need_accept && call_count == 0)
    {
        mmi_ucm_end_btdialer_and_accept_option_bt();
    }
    if (call_count == 0 && !g_ucm_p_bt->is_end_all_action)
    {
        mmi_ucm_clean_all_bt();
    }

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_frm_input_event_enable_notify();
#endif 

    mmi_frm_group_close(GRP_ID_UCM_BT_CALL_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_end
 * DESCRIPTION
 *  show call end popup
 * PARAMETERS
 *   call_end:          [IN]    call end info structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_end_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MessageString[MMI_UCM_END_TEXT_LEN_BT];
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    CHAR TimeString[32];
    S32 str_len = 0;
    mmi_ucm_bt_call_end_struct *call_end_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_CALL_END_BT);

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BT_CALL_END,
                    (FuncPtr)mmi_ucm_exit_call_end_bt,
                    (FuncPtr)mmi_ucm_entry_call_end_bt,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }
    

    call_end_p = (mmi_ucm_bt_call_end_struct*)mmi_frm_scrn_get_user_data(scr_info->group_id, SCR_ID_UCM_BT_CALL_END);

    mmi_ucs2ncpy((CHAR*)MessageString, (CHAR*)call_end_p->disp_msg, MMI_UCM_END_TEXT_LEN_BT);
    
    if ((call_end_p->call_duration.nDay + 
        call_end_p->call_duration.nHour +  
        call_end_p->call_duration.nMin + 
        call_end_p->call_duration.nSec) != 0)
    {
        duration_string(
            (UI_time*) & (call_end_p->call_duration),
            (UI_string_type) TimeString,
            DT_ACTIVE_CALL_SCREEN);

        str_len = mmi_ucs2strlen((CHAR*)MessageString);
        if ((MMI_UCM_END_TEXT_LEN_BT - str_len) > mmi_ucs2strlen((CHAR*)newline))
        {
            mmi_ucs2ncat((CHAR*)MessageString, (CHAR*)newline, (MMI_UCM_END_TEXT_LEN_BT - str_len));
        }
        str_len = mmi_ucs2strlen((CHAR*)MessageString);

        if ((MMI_UCM_END_TEXT_LEN_BT - str_len) > mmi_ucs2strlen((CHAR*)TimeString))
        {
            mmi_ucs2ncat((CHAR*)MessageString, (CHAR*)TimeString, (MMI_UCM_END_TEXT_LEN_BT - str_len));
        }
    }

    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_END, KEY_EVENT_DOWN);
    ShowCategory63Screen((U8*) MessageString, call_end_p->image_id, NULL);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_BT_CALL_END, SCR_ID_UCM_BT_CALL_END, (mmi_proc_func) mmi_ucm_call_end_screen_delete_proc_bt); 
      
    StartTimer(UCM_NOTIFY_DURATION_TIMER_BT, MMI_UCM_NOTIFY_TIMEOUT_BT, mmi_ucm_call_end_timeout_handler_bt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_end_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for cal end screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_call_end_screen_delete_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:            
        {
            mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
            mmi_ucm_bt_call_end_struct *call_end_p = (mmi_ucm_bt_call_end_struct *)mmi_frm_scrn_get_user_data(scenario_evt->targ_group, scenario_evt->targ_scrn); 
            /* free memory */
            if(call_end_p->disp_msg != NULL)
            {
                OslMfree(call_end_p->disp_msg);
                call_end_p->disp_msg = NULL;
            }
            if(call_end_p != NULL)
            {
                OslMfree(call_end_p);
                call_end_p = NULL;
            }
        }
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_refresh_ind_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ucm_refresh_ind_bt(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_id[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    S32 connect_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_INCOMING_STATE, call_id) > 0)
    {
        g_ucm_p_bt->hilite_call_id = call_id[0];
        mmi_ucm_enter_incoming_call_bt();
        if (g_ucm_p_bt->tone_type == MMI_UCM_BT_NONE_TONE)
        {
            mmi_ucm_play_incoming_ringtone_bt();
        }
    }
    else if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_OUTGOING_STATE, call_id) > 0)
    {
        g_ucm_p_bt->hilite_call_id = call_id[0];
        mmi_ucm_enter_outgoing_call_bt();
    }
    else
    {
        connect_count = srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_CALL_STATE_CONNECTED, call_id);

        if (connect_count == 1)
        {
            g_ucm_p_bt->hilite_call_id = call_id[0];
        }
        else if (connect_count > 1)
        {
            g_ucm_p_bt->hilite_call_id = call_id[0];
            if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_ACTIVE_STATE, call_id) > 0)
            {
                g_ucm_p_bt->hilite_call_id = call_id[0];
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
        mmi_ucm_enter_in_call_bt();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_release_ind_bt
 * DESCRIPTION
 *  This function is a leave proc for cal end screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ucm_release_ind_bt(srv_ucm_bt_release_call_ind_struct* call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_bt_call_end_struct *call_end_p; /* free mem when screen deinit */
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    U16 *call_end_message = OslMalloc(sizeof(U16) * (SRV_UCM_BT_MAX_ERR_MSG_LEN + 1)); /* free mem when screen deinit */
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(call_info);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_BT, call_info->srv_hd, call_info->call_id);

    g_ucm_p_bt->disconnecting = 0;

#ifdef __MMI_FTE_SUPPORT__
    mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_RELEASE_EVENT);
#endif

    mmi_ucm_stop_incoming_ringtone_bt();

    if (srv_ucm_bt_query_call_count_ext(call_info->srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
    {
        S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
        srv_ucm_bt_call_info_struct info;
        srv_ucm_bt_force_refresh_act_req_struct force_refresh;
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
        if (srv_speech_is_phone_mute() == MMI_TRUE)
        {
            srv_speech_unmute_phone();
        }

        mmi_ucm_set_hilite_dev_info_bt(0);

        if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, call_list) > 0)
        {
            if (srv_ucm_bt_query_call_data(call_list[0], &info))
            {
                force_refresh.srv_hd = info.srv_hd;
                mmi_ucm_set_hilite_dev_info_bt(info.srv_hd);
                srv_ucm_bt_act_request(SRV_UCM_BT_FORCE_REFRESH_ACT, &force_refresh);
            }
        }
    }

#ifdef __MMI_UCM_BT_CALL_RECORDER__
    if (srv_ucm_bt_query_call_count_ext(call_info->srv_hd, SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) == 0)
    {
       if (mdi_audio_is_recording())
        {
            mmi_ucm_end_record_option_bt();
        } 
    }
#endif /*__MMI_UCM_BT_CALL_RECORDER__*/
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    call_end_p = OslMalloc(sizeof(mmi_ucm_bt_call_end_struct)); 

    memcpy(&call_end_p->call_duration, &call_info->duration, sizeof(MYTIME));
    mmi_ucs2ncpy((CHAR*)call_end_message, (CHAR*)GetString(STR_ID_UCM_BT_CALL_ENDED), MMI_UCM_END_TEXT_LEN_BT);
    call_end_p->disp_msg = call_end_message;
 
    mmi_ucm_tab_highlight_bt();
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
    mmi_ucm_enter_call_end_bt(call_end_p);
    mmi_ucm_go_back_screen_check_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_call_end
 * DESCRIPTION
 *  This just stops timer which was started in the entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_call_end_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXIT_CALL_END_BT);
    StopTimer(UCM_NOTIFY_DURATION_TIMER_BT);
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED,NULL) > 0
          && !mmi_frm_group_is_present(GRP_ID_UCM_BT_INCALL))
    {
        mmi_ucm_enter_in_call_bt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_incoming_call
 * DESCRIPTION
 *  Exit function for incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_incoming_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT);
#endif /* __MMI_FTE_SUPPORT__ */
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    srv_backlight_turn_off();
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_outgoing_call_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_outgoing_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT);
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_in_call_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_in_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT);
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_jump_bt
 * DESCRIPTION
 *  Jump to tab based on index for Category403.
 * PARAMETERS
 *  index       [IN]        Current highlight tab
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_jump_bt(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_count;
    S32 group_index[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_count = srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, group_index);

    g_ucm_p_bt->hilite_call_id= group_index[index];

    if(group_count > 0)
    {
        mmi_ucm_enter_in_call_bt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_prev
 * DESCRIPTION
 *  Move to previous tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_prev_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    S32 group_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_count = srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev,SRV_UCM_BT_CALL_STATE_CONNECTED, group_index);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_TAP_PRE, g_ucm_p_bt->hilite_call_id, group_count);

    if (group_count == 1 && group_index[0] > 0)
    {
        g_ucm_p_bt->hilite_call_id = group_index[0];
    #ifdef __MMI_BTD_BOX_UI_STYLE__
        /* volume control, should transfer repeat key to in call screen */
        mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    #endif /* __MMI_BTD_BOX_UI_STYLE__ */
        mmi_ucm_enter_in_call_bt();
        return;
    }
    else if (group_count > 1)
    {
        if (g_ucm_p_bt->hilite_call_id == group_index[0])
        {
            g_ucm_p_bt->hilite_call_id = group_index[1];
        }
        else if (g_ucm_p_bt->hilite_call_id == group_index[1])
        {
            g_ucm_p_bt->hilite_call_id = group_index[0];
        }
    #ifdef __MMI_BTD_BOX_UI_STYLE__
        /* volume control, should transfer repeat key to in call screen */
        mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    #endif /* __MMI_BTD_BOX_UI_STYLE__ */
        mmi_ucm_enter_in_call_bt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_next
 * DESCRIPTION
 *  Move to next tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_next_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_tab_prev_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_highlight
 * DESCRIPTION
 *  Adjust highlight tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_highlight_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    S32 group_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_TAP_HIGHLIGH, g_ucm_p_bt->hilite_call_id);
    group_count = srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_CONNECTED, group_index);
    if (group_count > 1)
    {
        if (g_ucm_p_bt->hilite_call_id == group_index[0])
        {
            g_ucm_p_bt->hilite_call_id = group_index[1];
        }
        else if (g_ucm_p_bt->hilite_call_id == group_index[1])
        {
            g_ucm_p_bt->hilite_call_id = group_index[0];
        }
        else if (srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, group_index) > 0)
        {
            g_ucm_p_bt->hilite_call_id = group_index[0];
        }
        else if (srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, group_index) > 0)
        {
            g_ucm_p_bt->hilite_call_id = group_index[0];
        }
    }
    else if (group_count == 1)
    {
        g_ucm_p_bt->hilite_call_id= group_index[0];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_go_back_screen_check
 * DESCRIPTION
 *  Go back to screen based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_go_back_screen_check_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 incoming;
    U8 outgoing;
    U8 connected;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_GO_BACK_SCREEN_CHECK);

    if (srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev))
    {
        incoming = srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_INCOMING_STATE, NULL);
        outgoing = srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_OUTGOING_STATE, NULL);
        connected = srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, NULL);
    }
    else
    {
        incoming = srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL);
        outgoing = srv_ucm_bt_query_call_count(SRV_UCM_BT_OUTGOING_STATE, NULL);
        connected = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL);
    }

    if (incoming == 0 && mmi_frm_group_is_present(GRP_ID_UCM_BT_MT))
    {
        mmi_frm_group_close(GRP_ID_UCM_BT_MT);
    }
    if (outgoing == 0)
    {
        if (mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
        {
            mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
        }
        if (mmi_frm_group_is_present(GRP_ID_UCM_BT_MO))
        {
            mmi_frm_group_close(GRP_ID_UCM_BT_MO);
        }
    }
    if (connected == 0)
    {
    #ifndef __MMI_UCM_BT_BTBOX_NOLCD__
        mmi_ucm_close_cui_bt(&g_ucm_p_bt->incall_opt_cui_id);
    #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
        if (mmi_frm_group_is_present(GRP_ID_UCM_BT_INCALL))
        {
            mmi_frm_group_close(GRP_ID_UCM_BT_INCALL);
        }
    }
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    else
    {
        mmi_ucm_bt_close_processing_scrn();
    }
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for in call screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_in_call_screen_delete_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:  
        case EVT_ID_SCRN_DELETE_REQ:
        {

        }
        break;

        case EVT_ID_SCRN_DEINIT:
        {
            /* delete all cui triggered by outgoing call scrn - here: option menu */             
            mmi_ucm_close_cui_bt(&g_ucm_p_bt->incall_opt_cui_id);
        }
        break;  
    }   
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_end_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_outgoing_call_endkey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisableRightSoftkey(STR_GLOBAL_ABORT, 0);
    mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    mmi_ucm_end_single_action_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_rsk_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_rsk_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_MT_END_KEY);
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        DisableRightSoftkey(STR_ID_UCM_BT_REJECT, 0);
        DisableLeftSoftkey(STR_ID_UCM_BT_ANSWER, 0);

        mmi_ucm_end_single_action_bt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_end_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_incoming_call_endkey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_MT_END_KEY);
    mmi_ucm_end_single_action_bt();
}

static void mmi_ucm_refresh_timeout_hdlr(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 srv_hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(arg);
    srv_hd  = *((S32*)arg);
    mmi_ucm_force_refresh_action_bt(srv_hd);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_sendkey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_group;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_is_any_call())
    {
        active_group = mmi_frm_group_get_active_id();
        mmi_ucm_end_and_accpet_confirm_bt(active_group);
    }
    else
    {
    #ifdef __MMI_FTE_SUPPORT__
        DisableRightSoftkey(STR_ID_UCM_BT_REJECT, 0);
        DisableLeftSoftkey(STR_ID_UCM_BT_ANSWER, 0);
    #endif
        mmi_ucm_answer_action_bt();
        mmi_ucm_stop_incoming_ringtone_bt();
        mmi_ucm_bt_enter_processing_screen(GRP_ID_UCM_BT_MT, g_ucm_p_bt->hilite_dev);
        StartTimerEx(UCM_FORCE_REFRESH_TIMER_BT,
                     MMI_UCM_FORCE_REFRESH_TIME_BT,
                     mmi_ucm_refresh_timeout_hdlr,
                     (void*)&g_ucm_p_bt->hilite_dev);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_sendkey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilite_call = g_ucm_p_bt->hilite_call_id;
    S32 group_count;
    srv_ucm_bt_call_info_struct call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL);

    if (srv_ucm_bt_query_call_data(hilite_call, &call_info))
    {
        if (call_info.call_state == SRV_UCM_BT_ACTIVE_STATE)
        {
            if (group_count > 1)
            {
                mmi_ucm_swap_action_bt();
            }
            else 
            {
                mmi_ucm_hold_action_bt();
            }
        }
        else if (call_info.call_state == SRV_UCM_BT_HOLD_STATE)
        {
            if (group_count > 1) 
            {
                mmi_ucm_swap_action_bt();
            }
            else /* no active call exists */
            {
                mmi_ucm_retrieve_action_bt();
            }
        }
        else
        {
            mmi_ucm_entry_error_message_bt();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_ucm_sg_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_sg_id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_ucm_sg_bt(MMI_ID check_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GRP_ID_UCM_BT_INCALL == check_sg_id) ||
        (GRP_ID_UCM_BT_MT == check_sg_id) ||
        (GRP_ID_UCM_BT_MO == check_sg_id) ||
        (GRP_ID_UCM_BT_PRE_MO == check_sg_id) ||
        (GRP_ID_UCM_BT_CALL_END == check_sg_id))
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_incall_option
 * DESCRIPTION
 *  Shows the incall option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_incall_option_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_ucm_incall_opt_proc_bt */
    /* create menu cui */
    g_ucm_p_bt->incall_opt_cui_id = cui_menu_create_and_run(
                            GRP_ID_UCM_BT_INCALL, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_BT_INCALL_OPTION, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_sidekey
 * DESCRIPTION
 *  Handle side key for UCM call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_sidekey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    SetDefaultVolumeKeyHandlers();
    SetKeyHandler(SetKeyPadVolUp, KEY_VOL_UP, KEY_EVENT_UP);  /* O */
    SetKeyHandler(SetKeyPadVolMaxLongPress, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(SetKeyPadVolDown, KEY_VOL_DOWN, KEY_EVENT_UP);  /* O */
    SetKeyHandler(SetKeyPadVolMinLongPress, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_REPEAT);
#ifdef __MMI_BTD_BOX_UI_STYLE__
    SetKeyHandler(SetKeyPadVolUp, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(SetKeyPadVolUp, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(SetKeyPadVolDown, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(SetKeyPadVolDown, KEY_DOWN_ARROW, KEY_LONG_PRESS);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_incoming_call
 * DESCRIPTION
 *  Enter incoming call scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_incoming_call_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    srv_ucm_bt_call_info_struct call_info;
    mmi_input_event_notify_param param;
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    kal_prompt_trace(MOD_MMI, "mmi_ucm_enter_incoming_call_bt");

    if(mmi_frm_group_is_present(GRP_ID_UCM_BT_MT))
        return;

    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_MT);

    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_OUTGOING);
#ifndef DIGIT_TONE_SUPPORT
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_INCOMING);
#endif /* DIGIT_TONE_SUPPORT */
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_WAITING);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_ACTIVE);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_HELD);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_END);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_FAIL);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLUP);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLDOWN);

    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, call_list) > 0)
    {
        srv_ucm_bt_query_call_data(call_list[0], &call_info);

    }
#if 0
#ifdef DIGIT_TONE_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* DIGIT_TONE_SUPPORT */
/* under construction !*/
#endif /* DIGIT_TONE_SUPPORT */
#endif//0
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */
#ifdef __MMI_FTE_SUPPORT__
    mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_INCOMING_EVENT);
#endif

    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_MT);

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_BT_MT, SCR_ID_UCM_BT_INCOMING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_BT_MT, SCR_ID_UCM_BT_INCOMING); /* ensure no two incoming call screens in the history */
    }
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_BT_MT, SCR_ID_UCM_BT_INCOMING, 
        (FuncPtr)mmi_ucm_entry_incoming_call_bt, 
        (void*)NULL);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_refresh_option_button_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_refresh_option_button_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_softkey_background();
    redraw_left_softkey();
    redraw_right_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_incoming_call
 * DESCRIPTION
 *  Shows the incoming call screen
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_incoming_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;
    U16 notification_str_id = STR_ID_UCM_VOICE_INCOMING;
    U16 rsk_str = 0;
    U16 lsk_str = 0;
    MMI_BOOL is_play_now = MMI_FALSE;
    S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    srv_ucm_bt_call_info_struct call_info;
#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
    wgui_catcall_fte_iconbar_item_struct unlock_item;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCOMING_CALL_BT, g_ucm_p_bt->hilite_dev);

    if (!srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev)
      || srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_INCOMING_STATE, NULL) == 0)
    {
        return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BT_INCOMING,
                    (FuncPtr)mmi_ucm_exit_incoming_call_bt,
                    (FuncPtr)mmi_ucm_entry_incoming_call_bt,
                    MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_INCOMING, NULL);
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_BT_INCOMING);

    if (srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_INCOMING_STATE, call_list) > 0)
    {
        srv_ucm_bt_query_call_data(call_list[0], &call_info);
    }

    if (srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 1)
    {
        lsk_str = STR_ID_UCM_BT_REPLACE;
    }
    else
    {
        lsk_str = STR_ID_UCM_BT_ANSWER;
    }
    rsk_str = STR_ID_UCM_BT_REJECT;
#ifdef __MMI_FTE_SUPPORT__
  #if !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
    mmi_ucm_FTE_fill_unlock_item_bt(&unlock_item);
    wgui_catcall_fte_setup(0, 0, unlock_item, mmi_ucm_FTE_screen_touch_hdlr_bt);
    mmi_ucm_FTE_scrn_update_hdlr_by_lock_state_bt(mmi_ucm_get_auto_lock_state_bt());
  #endif
#endif

    ShowCategory17Screen(
            0,   /* title_id */
            lsk_str,                   /* left_softkey */
            0,                   /* left_softkey_icon */
            rsk_str,    /* right_softkey */
            0,                   /* right_softkey_icon */
            notification_str_id,                   /* NotificationStringId */ 
            (U8*)call_info.dis_name, /* NameOrNumber */
            NULL,                /* IP_Number */
            0,             /* line icon */
            IMG_ID_UCM_BT_INCOMING,     /*default_image_id */
            IMG_ID_UCM_BT_INCOMING,               /* resource_id */
            0,             /* resource_filename */
            WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID,          /* resource_type */
            0,                   /* repeat_count, video/swflash only, repeat_count, 0 = infinite */
            0,        /* is_visaul_update, video/swflash only, update to LCM or not */
            0,      /* is_video_aud, video/swflash only, play video's audio */
            is_play_now,         /* is_play_aud_when_start */
            guiBuffer);

    mmi_ucm_refresh_option_button_bt();
    SetLeftSoftkeyFunction(mmi_ucm_refresh_option_button_bt, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_ucm_incoming_call_sendkey_bt, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_incoming_call_sendkey_bt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ucm_incoming_call_rsk_bt, KEY_EVENT_UP);
    SetKeyHandler(mmi_ucm_incoming_call_sendkey_bt, KEY_SEND, KEY_EVENT_DOWN);
    /* Let incoming call end key behavior will sync to general end key hdlr, but reject RSK and suppress keep in mmi_ucm_incoming_call_endkey */
    mmi_frm_set_key_handler(mmi_ucm_incoming_call_endkey_bt, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_DOWN, KEY_EVENT_DOWN); 

#ifdef __MMI_BTD_BOX_UI_STYLE__
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_LONG_PRESS);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/	
    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_INCOMING, NULL);
 
    if (!mmi_is_redrawing_bk_screens())
    {
        ClearKeyEvents();
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        }

        if (srv_charbat_is_low_battery())
        {
            ChgrPlayLowBatTone();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_outgoing_call
 * DESCRIPTION
 *  Enter the call type selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_outgoing_call_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_OUTGOING_EVENT);
#endif
    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_MO);
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    kal_prompt_trace(MOD_MMI, "mmi_ucm_enter_outgoing_call_bt");

    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_OUTGOING);
  #ifndef DIGIT_TONE_SUPPORT
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_INCOMING);
  #endif /* DIGIT_TONE_SUPPORT */
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_WAITING);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_ACTIVE);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_HELD);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_END);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_FAIL);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLUP);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLDOWN);
    mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_OUTGOING);
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_BT_MO, SCR_ID_UCM_BT_OUTGOING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_BT_MO, SCR_ID_UCM_BT_OUTGOING); /* ensure no two incoming call screens in the history */
    }
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_BT_MO, SCR_ID_UCM_BT_OUTGOING, 
        (FuncPtr)mmi_ucm_entry_outgoing_call_bt,
        (void*)NULL);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}

#ifdef __MMI_FTE_SUPPORT__



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_unlock_hdlr
 * DESCRIPTION
 *  unlock call related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_unlock_hdlr_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_UNLOCK_HDLR, mmi_ucm_get_auto_lock_state_bt());

    mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_UNLOCK_EVENT);

    /* Because the call screen does not change (lock=just redraw some region), so need updated and start timer */
    if (MMI_TRUE == mmi_ucm_FTE_is_lock_mechanism_applied_screens_bt())
    {
        if (MMI_UCM_BT_UNLOCK_STATE == mmi_ucm_get_auto_lock_state_bt())
        {
            wgui_catcall_fte_lock_screen(MMI_FALSE);
        }
        else if (MMI_UCM_BT_WTL_STATE == mmi_ucm_get_auto_lock_state_bt())
        {
            wgui_catcall_fte_lock_screen(MMI_FALSE);
            StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT, MMI_UCM_BT_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr_bt);        
        }
    }        
    else
    {
        /* unlock hdlr is impossible to called when not in lock screen, and lock screen only applied on MT/MO/INCALL */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_fill_unlock_item
 * DESCRIPTION
 *  fill lock item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_fill_unlock_item_bt(wgui_catcall_fte_iconbar_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    item->label = get_string(STR_ID_UCM_TOUCH_TO_UNLOCK);
    item->icon = NULL; 
    item->up = get_image(IMG_ID_UCM_LOCK_ICON_UP);            
    item->down = get_image(IMG_ID_UCM_LOCK_ICON_DOWN);
    item->disable = NULL;
    item->handler = mmi_ucm_FTE_unlock_hdlr_bt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_auto_lock_timeout_hdlr
 * DESCRIPTION
 *  lock call related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_auto_lock_timeout_hdlr_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_LOCK_TIME_OUT, mmi_ucm_get_auto_lock_state_bt());
	
    if (MMI_TRUE == mmi_ucm_FTE_is_lock_mechanism_applied_screens_bt())
    {
        mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_WTL_TIMEOUT_EVENT);
        /* Because the call screen does not change (lock=just redraw some region), so need updated and start timer */
        if (MMI_UCM_BT_LOCK_STATE == mmi_ucm_get_auto_lock_state_bt())
        {
            wgui_catcall_fte_lock_screen(MMI_TRUE);
        }
        else 
        {
           MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_screen_touch_hdlr
 * DESCRIPTION
 *  when the iconbar or SK button is pressend in call screen, this api will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_screen_touch_hdlr_bt(MMI_BOOL is_touched)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_SCRN_TOUCH_HDLR, is_touched, mmi_ucm_get_auto_lock_state_bt());

    if (MMI_FALSE == mmi_ucm_FTE_is_lock_mechanism_applied_screens_bt())
    {   
        MMI_ASSERT(0);
    }
    
    if (is_touched)
    {
        StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT);
    }
    else
    {
        if (MMI_UCM_BT_WTL_STATE == mmi_ucm_get_auto_lock_state_bt())
        {
            StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT, MMI_UCM_BT_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr_bt);        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_is_lock_mechanism_applied_screens
 * DESCRIPTION
 *  check if the current screen is applied lock mechanism.
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_TRUE means the screen support lock mechanism
 *****************************************************************************/
MMI_BOOL mmi_ucm_FTE_is_lock_mechanism_applied_screens_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_scrnID = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((SCR_ID_UCM_BT_OUTGOING == current_scrnID) ||
        (SCR_ID_UCM_BT_INCOMING == current_scrnID) ||
        (SCR_ID_UCM_BT_IN_CALL == current_scrnID))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;      
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_scrn_update_hdlr_by_lock_state
 * DESCRIPTION
 *  to draw lock/unlock scrn and start autolock timer in call screen (MT/MO/INCALL) by given lock state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_scrn_update_hdlr_by_lock_state_bt(mmi_ucm_bt_auto_lock_state_enum lock_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_SCRN_UPDATE_HDLR, lock_state);

    if (MMI_UCM_BT_LOCK_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_TRUE);        
    }
    else if (MMI_UCM_BT_UNLOCK_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_FALSE);
    }
    else if (MMI_UCM_BT_WTL_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_FALSE);
        StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID_BT, MMI_UCM_BT_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr_bt);        
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_outgoing_call
 * DESCRIPTION
 *  Shows the outgoing call screen
 *  This is invoked whenever the User requests for a outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_outgoing_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;
    U16 calling_str_id = STR_ID_UCM_BT_CALLING;
    U16 line_icon = 0;    
    S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    srv_ucm_bt_call_info_struct call_info;
#if defined( __MMI_FTE_SUPPORT__ ) && !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
    wgui_catcall_fte_iconbar_item_struct unlock_item;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_OUTGOING_CALL_BT);

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BT_OUTGOING,
                    (FuncPtr)mmi_ucm_exit_outgoing_call_bt,
                    (FuncPtr)mmi_ucm_entry_outgoing_call_bt,
                    MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_OUTGOING, NULL);
        return;
    }

    mmi_frm_group_close(GRP_ID_UCM_BT_MT);

    if (!mmi_is_redrawing_bk_screens())
    {
        ClearKeyEvents();
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        }
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_BT_OUTGOING);

    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_OUTGOING_STATE, call_list) > 0)
    {
        srv_ucm_bt_query_call_data(call_list[0], &call_info);
    }

#ifdef __MMI_FTE_SUPPORT__
  #if !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
   mmi_ucm_FTE_fill_unlock_item_bt(&unlock_item);
   wgui_catcall_fte_setup(0, 0, unlock_item, mmi_ucm_FTE_screen_touch_hdlr_bt);
   mmi_ucm_FTE_scrn_update_hdlr_by_lock_state_bt(mmi_ucm_get_auto_lock_state_bt());
  #endif
#endif
 
    ShowCategory17Screen(
            0,   /* title_id */ 
            0,        /* left_softkey */
            0,                   /* left_softkey_icon */
            STR_GLOBAL_ABORT,    /* right_softkey */
            0,                   /* right_softkey_icon */
            calling_str_id,                   /* NotificationStringId */ 
            (U8*)call_info.dis_name, /* NameOrNumber */
            0,                /* IP_Number */
            line_icon,             /* line icon */
            IMG_ID_UCM_BT_OUTGOING,     /*default_image_id */
            IMG_ID_UCM_BT_OUTGOING,               /* resource_id */
            0,             /* resource_filename */
            WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID,          /* resource_type */
            0,                   /* repeat_count, video/swflash only, repeat_count, 0 = infinite */
            0,        /* is_visaul_update, video/swflash only, update to LCM or not */
            MMI_FALSE,          /* is_video_aud, video/swflash only, play video's audio */
            MMI_FALSE,         /* is_play_aud_when_start */
            guiBuffer);

    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_DOWN, KEY_EVENT_DOWN); 
    SetRightSoftkeyFunction(mmi_ucm_outgoing_call_endkey_bt, KEY_EVENT_UP);
    mmi_frm_set_key_handler(mmi_ucm_outgoing_call_endkey_bt, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_DOWN, KEY_EVENT_DOWN); 
#ifdef __MMI_BTD_BOX_UI_STYLE__
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_REPEAT);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_OUTGOING, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_incoming_call
 * DESCRIPTION
 *  Enter incoming call scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_in_call_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    kal_prompt_trace(MOD_MMI, "mmi_ucm_enter_in_call_bt");

    if (mmi_frm_group_is_present(GRP_ID_UCM_BT_INCALL))
        return;

    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_INCALL);
  #ifndef DIGIT_TONE_SUPPORT
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_INCOMING);
  #endif /* DIGIT_TONE_SUPPORT */
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_OUTGOING);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_WAITING);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_FAIL);

    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, NULL))
    {
        mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_HELD);
    }
    else
    {
        mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_ACTIVE);
    }

    if(!srv_btsco_is_sco_open())
        mmi_ucm_switch_audio_action_bt();

    mmi_frm_input_event_disable_notify();
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */
#ifdef __MMI_FTE_SUPPORT__
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    if (curr_act_sg_id != GRP_ID_UCM_BT_INCALL)
    {
        mmi_ucm_auto_lock_fsm_hdlr_bt(MMI_UCM_BT_AL_CONNECT_EVENT);
    }
#endif

    mmi_ucm_bt_close_processing_scrn();
 
    mmi_ucm_sg_create_bt(GRP_ID_ROOT, GRP_ID_UCM_BT_INCALL);

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_IN_CALL, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_IN_CALL);
    }
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_IN_CALL, 
        (FuncPtr)mmi_ucm_entry_in_call_bt, 
        (void*)NULL);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_intuitive_cmd_cb_bt
 * DESCRIPTION
 *  In FTE, it should support intuitive command. do nothing when user touch call in incall list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_intuitive_cmd_cb_bt(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    return;  
}
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_in_call
 * DESCRIPTION
 *  Entry function of in call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_in_call_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8* title = NULL;
    U16 rsk_str = 0; 
    U16 lsk_str = 0;
    S32 i ,hilite_call_id;
    S32 hilite_tab_item = 0;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    S32 group_count;
    srv_ucm_bt_call_info_struct call_info;
    MYTIME start_time;
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
    wgui_catcall_fte_iconbar_item_struct unlock_item;
#endif
#ifdef __MMI_UCM_BT_CALL_RECORDER__
    MYTIME *start_record_time_p = NULL;
    U16 call_record_str_id = 0;
#endif /*__MMI_UCM_BT_CALL_RECORDER__*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (!srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev)
      || (srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev)
       && srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) == 0))
    {
        return;
    }

    mmi_ucm_go_back_screen_check_bt();

    if (!mmi_frm_scrn_enter(
            scr_info->group_id,
            SCR_ID_UCM_BT_IN_CALL,
            (FuncPtr)mmi_ucm_exit_in_call_bt,
            (FuncPtr)mmi_ucm_entry_in_call_bt,
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_UCM_BT_INCALL, 
            SCR_ID_UCM_BT_IN_CALL, 
            (mmi_proc_func)mmi_ucm_in_call_screen_delete_proc_bt);
        return;
    }

    group_count = srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, group_list);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCALL_BT, group_count, g_ucm_p_bt->hilite_call_id);

    mmi_ucm_stop_incoming_ringtone_bt();

    hilite_call_id = g_ucm_p_bt->hilite_call_id;

    gui_buffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_BT_IN_CALL);

    for (i = 0; i < group_count; i++)
    {
        srv_ucm_bt_query_call_data(group_list[i], &call_info);

        if (call_info.call_state == SRV_UCM_BT_ACTIVE_STATE)
        {
            MMI_tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_ACTIVE);
        }
        else if (call_info.call_state == SRV_UCM_BT_HOLD_STATE)
        {
            MMI_tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_HOLD);            
        }

        MMI_tab_bar_items[i].text = NULL;
        MMI_tab_bar_items[i].flags = 0; /* no blink */

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL,TRC_MMI_UCM_ENTRY_INCALL_BT_NUMBERS,
                call_info.call_id, call_info.call_state,
                call_info.num_uri[0],
                call_info.num_uri[1],
                call_info.num_uri[2]);


        if (group_list[i] == hilite_call_id)
        {
            U32 char_num = ((MAX_SUB_MENU_SIZE / ENCODING_LENGTH) < SRV_UCM_BT_MAX_NUM_URI_LEN)?
                (MAX_SUB_MENU_SIZE / ENCODING_LENGTH): SRV_UCM_BT_MAX_NUM_URI_LEN;

            subMenuDataPtrs[0] = subMenuData[0];
    
            if (call_info.multiParty)
            {
                mmi_ucs2cpy((CHAR*)subMenuDataPtrs[0],(CHAR*)GetString(STR_ID_UCM_BT_CONF_CALL));
            }
            else
            {
                mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[0],(CHAR*)call_info.dis_name,char_num);
            }

            title = (U8*)GetString(mmi_ucm_get_call_type_string_id_bt(call_info.call_state));

            memcpy(&start_time, &call_info.start_time, sizeof(MYTIME));

            hilite_tab_item = i;
        }
    }

    lsk_str = STR_GLOBAL_OPTIONS;

#ifndef __MMI_BTD_BOX_UI_STYLE__
    rsk_str = (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_BT_HAND_HELD) : (STR_ID_UCM_BT_HAND_FREE);
#else /*__MMI_BTD_BOX_UI_STYLE__*/
    rsk_str = STR_ID_UCM_BT_END_CALL;
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

#ifdef __MMI_FTE_SUPPORT__
#if !defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_WEARABLE_DEVICE__)
    mmi_ucm_FTE_fill_unlock_item_bt(&unlock_item);
    wgui_catcall_fte_setup(0, 0, unlock_item, mmi_ucm_FTE_screen_touch_hdlr_bt);
    mmi_ucm_FTE_scrn_update_hdlr_by_lock_state_bt(mmi_ucm_get_auto_lock_state_bt());
#endif /*__MMI_MAINLCD_320X240__*/
#endif

#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
#ifdef __MMI_UCM_BT_CALL_RECORDER__
    if(mdi_audio_is_recording())
    {
        call_record_str_id = (U16)STR_ID_UCM_RECORDING;
        start_record_time_p = &g_ucm_bt_start_record_time;
    }

     ShowCategory403Screen(
        title,
        0,
        lsk_str,
        0,
        rsk_str,
        0,
        (S8)group_count,
        (S8)hilite_tab_item,
        MMI_tab_bar_items,
        &start_time,
        0,
        start_record_time_p,//time
        0,  //icon
        call_record_str_id, //string
        subMenuDataPtrs,
        0,//call_icon,
        1,
        0,
        gui_buffer);
#else /*__MMI_UCM_BT_CALL_RECORDER__*/
    ShowCategory403Screen(
        title,
        0,
        lsk_str,
        0,
        rsk_str,
        0,
        (S8)group_count,
        (S8)hilite_tab_item,
        MMI_tab_bar_items,
        &start_time,
        0,
        subMenuDataPtrs,
        0,//call_icon,
        1,
        0,
        gui_buffer);
#endif /*__MMI_UCM_BT_CALL_RECORDER__*/
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
    SetCategory403TabSelectCallback(mmi_ucm_tab_jump_bt);
#endif /* __MMI_TOUCH_SCREEN__ */

    if (group_count > 1)
    {
        /* in new framework key design, won't translate long press and repeat to several down, therefore need to register for long press and repeat here */
    #ifndef __MMI_BTD_BOX_UI_STYLE__
        /* in new framework key design, won't translate long press and repeat to several down, therefore need to register for long press and repeat here */
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_LEFT_ARROW, KEY_LONG_PRESS); 
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_RIGHT_ARROW, KEY_LONG_PRESS); 
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_LEFT_ARROW, KEY_REPEAT); 
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_RIGHT_ARROW, KEY_REPEAT); 
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_LEFT_ARROW, KEY_EVENT_DOWN);   /* move to previous tab */
        SetKeyHandler(mmi_ucm_tab_next_bt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);  /* move to next tab */
    #else /*__MMI_BTD_BOX_UI_STYLE__*/
        SetKeyHandler(mmi_ucm_tab_prev_bt, KEY_UP_ARROW, KEY_EVENT_DOWN);   /* move to previous tab */
        SetKeyHandler(mmi_ucm_tab_next_bt, KEY_DOWN_ARROW, KEY_EVENT_DOWN);  /* move to next tab */
    #endif /*__MMI_BTD_BOX_UI_STYLE__*/
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    /* intuitive cmd */
    wgui_register_tap_callback(mmi_ucm_intuitive_cmd_cb_bt);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    RegisterHighlightHandler(mmi_ucm_highlight_in_call_item_bt);
    SetLeftSoftkeyFunction(mmi_ucm_entry_incall_option_bt, KEY_EVENT_UP);

#ifndef __MMI_BTD_BOX_UI_STYLE__
    SetRightSoftkeyFunction(mmi_ucm_set_loud_speaker_bt, KEY_EVENT_UP);
#else /*__MMI_BTD_BOX_UI_STYLE__*/
    SetRightSoftkeyFunction(mmi_ucm_in_call_endkey_bt, KEY_EVENT_UP);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

    mmi_frm_set_key_handler(mmi_ucm_in_call_endkey_bt, KEY_END, KEY_EVENT_DOWN);

    if (g_ucm_p_bt->disconnecting == hilite_call_id)
    {
        DisableLeftSoftkey(lsk_str, 0);
        DisableRightSoftkey(rsk_str, 0);
        SetKeyHandler(UI_dummy_function, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(UI_dummy_function, KEY_SEND, KEY_EVENT_DOWN);
    }

    if(call_info.call_state == SRV_UCM_BT_ACTIVE_STATE)
    {
        SetKeyHandler(mmi_ucm_hold_action_bt, KEY_SEND, KEY_EVENT_DOWN);
        SetCenterSoftkeyFunction(mmi_ucm_hold_action_bt, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_ucm_retrieve_action_bt, KEY_SEND, KEY_EVENT_DOWN);
        SetCenterSoftkeyFunction(mmi_ucm_retrieve_action_bt, KEY_EVENT_UP);
    }
    if(group_count > 1)
    {
        SetKeyHandler(mmi_ucm_in_call_sendkey_bt, KEY_SEND, KEY_EVENT_DOWN);
        SetCenterSoftkeyFunction(mmi_ucm_in_call_sendkey_bt, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_DOWN, KEY_EVENT_DOWN); 

#ifdef __MMI_BTD_BOX_UI_STYLE__
	SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_REPEAT);
	SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_REPEAT);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
    SetGroupKeyHandler(
            mmi_ucm_send_dtmf_by_key,
            (U16*) PresentAllDialerKeys,
            TOTAL_DIALER_KEYS,
            KEY_EVENT_DOWN);
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_IN_CALL, (mmi_proc_func) mmi_ucm_in_call_screen_delete_proc_bt); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_notify_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for processing screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_bt_notify_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_scenario_evt_struct *sce_evt = (mmi_scenario_evt_struct*)evt;
            mmi_ucm_bt_dev_noti_struct *notify = (mmi_ucm_bt_dev_noti_struct*)mmi_frm_scrn_get_user_data(sce_evt->targ_group, sce_evt->targ_scrn);
            if (notify != NULL)
            {
                OslMfree(notify);
            }
        }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_outgoing_call_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ucm_entry_notify_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* pop_str;
    WCHAR* str;
    srv_ucm_bt_dev_info_struct dev_info;
    mmi_ucm_bt_dev_noti_struct* notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scr_info->group_id,
            SCR_ID_UCM_BT_DEV_NOTIFY,
            NULL,
            (FuncPtr)mmi_ucm_entry_notify_bt,
            MMI_FRM_FG_ONLY_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_DEV_NOTIFY, mmi_ucm_bt_notify_screen_delete_proc);
        return;
    }

    notify = (mmi_ucm_bt_dev_noti_struct*)mmi_frm_scrn_get_user_data(scr_info->group_id, SCR_ID_UCM_BT_DEV_NOTIFY);

    str = (WCHAR*)GetString(STR_ID_UCM_VOICE_INCOMING);
    pop_str = (WCHAR*)OslMalloc((mmi_wcslen(str) + SRV_BT_CM_BD_UCS2_NAME_LEN + 1 + 1) * ENCODING_LENGTH);// 1 is '\n' 

    if (srv_ucm_bt_query_connected_dev_info(notify->srv_hd, &dev_info))
    {
        memcpy (pop_str, dev_info.dev_name, SRV_BT_CM_BD_UCS2_NAME_LEN*ENCODING_LENGTH);
        mmi_wcscat(pop_str, L"\n");
        mmi_wcscat (pop_str, str);
    }
    else
    {
        memcpy (pop_str, str, (mmi_wcslen(str)+1)*ENCODING_LENGTH);
    }

    ShowCategory165Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        (WCHAR*)pop_str,
        mmi_get_event_based_image(MMI_EVENT_INFO),
        NULL);

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    OslMfree(pop_str);
    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_BT_DEV_NOTIFY, mmi_ucm_bt_notify_screen_delete_proc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_type_string_id
 * DESCRIPTION
 *  get call type string id by call type
 * PARAMETERS
 *  void
 * RETURNS
 *  String id
 *****************************************************************************/
U16 mmi_ucm_get_call_type_string_id_bt(srv_ucm_bt_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (call_state == SRV_UCM_BT_ACTIVE_STATE)
    {
        str_id = STR_ID_UCM_BT_ACTIVE;
    }
    else if (call_state == SRV_UCM_BT_HOLD_STATE)
    {
        str_id = STR_ID_UCM_BT_PAIRED_HOLD;
    }
    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_in_call_item
 * DESCRIPTION
 *  Highlight index in the active call screen.
 * PARAMETERS
 *  index       [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_in_call_item_bt(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_ucm_p_bt->hilite_index = index; // muti call list with same states
    //wgui_cat403_set_duration(start_time);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_all_screen
 * DESCRIPTION
 *  delete all UCM screens in histroy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_all_screen_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_ALL_SCREEN_BT);

    mmi_frm_group_close(GRP_ID_UCM_BT_MT);
    mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    mmi_frm_group_close(GRP_ID_UCM_BT_MO);
    mmi_frm_group_close(GRP_ID_UCM_BT_INCALL);
    mmi_frm_group_close(GRP_ID_UCM_BT_CALL_END);
    mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_ACTIVE);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_HELD);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_END);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_FAIL);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLUP);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLDOWN);
    mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLMUTE); 
    mmi_frm_input_event_enable_notify();
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_close_cui
 * DESCRIPTION
 *  close cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_close_cui_bt(mmi_id *cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID != *cui_id)
    {
        cui_menu_close(*cui_id);
        *cui_id = GRP_ID_INVALID;
    }
}


#ifdef __MMI_BT_BQB_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_for_bqb_test_mode_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_for_bqb_test_mode_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_bqb_test_flag())
    {
         srv_bt_dialer_release_all_active_calls(g_ucm_p_bt->hilite_dev, 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_for_bqb_test_mode_hold
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_for_bqb_test_mode_hold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_bqb_test_flag())
    {
         srv_bt_dialer_hold_all_active_calls(g_ucm_p_bt->hilite_dev, 2);
    }
}
#endif /* __MMI_BT_BQB_TEST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for incall
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_incall_sg_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:  
        case EVT_ID_CUI_MENU_ITEM_HILITE:    
        case EVT_ID_CUI_MENU_ITEM_SELECT:    
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_ucm_incall_opt_proc_bt(evt);
            break;
        
        default:
            break;
    }
    return MMI_RET_OK;
}


#ifndef __MMI_TELEPHONY_SUPPORT__
static void mmi_ucm_call_select_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dial_from_bt_para_p->menu_index == 0)
    {
        mmi_ucm_call_launch(0,g_make_call_para_bt);
    }
    else if (g_dial_from_bt_para_p->menu_index > 0 &&  g_dial_from_bt_para_p->menu_index <= SRV_UCM_BT_MAX_DEV)
    {
        memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, 
               &g_dial_from_bt_para_p->dev_addr[g_dial_from_bt_para_p->menu_index-1],
               sizeof(srv_bt_cm_bt_addr));
        mmi_ucm_call_launch_bt(&g_dial_from_bt_para_p->make_call_from_bt);
    }
}


static void mmi_ucm_call_select_main_menu_entry(MMI_ID cui_gid, mmi_ucm_bt_make_call_para_struct* make_bt_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 dev_name[SRV_BT_CM_BD_UCS2_NAME_LEN];
    U32 dev_count;
    U32 idx;
    const srv_bt_cm_dev_struct* cm_dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dial_from_bt_para_p == NULL)
    {
        g_dial_from_bt_para_p = OslMalloc(sizeof(mmi_ucm_dial_from_bt_struct));
    }

    memcpy(&g_dial_from_bt_para_p->make_call_from_bt, make_bt_call_para, sizeof(mmi_ucm_bt_make_call_para_struct));

    g_dial_from_bt_para_p->menu_index = 1;

    dev_count = srv_bt_cm_get_linked_dev_list_idx();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP_P1, 301, dev_count);
    MMI_ASSERT(SRV_UCM_BT_MAX_DEV >= dev_count);

    for (idx = 0; idx < dev_count; idx++)
    {
        cm_dev_info = srv_bt_cm_get_linked_dev_info(idx);

        if (cm_dev_info != NULL)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP_P1, 302, idx);

            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (dev_name),
                SRV_BT_CM_BD_NAME_UCS2_LEN,
                (kal_uint8*) cm_dev_info->name);

            if (idx == 0)
            {
                cui_menu_set_item_string(cui_gid, MENU_ID_UCM_FROM_BT_CALL, (WCHAR*)dev_name);
                if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, &cm_dev_info->bd_addr))
                {
                    cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_TRUE);
                }
                memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, &cm_dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));
            }
            else if (idx == 1)
            {
                cui_menu_set_item_string(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, (WCHAR*)dev_name);
                if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, &cm_dev_info->bd_addr))
                {
                    cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_TRUE);
                }
            }
            memcpy(&g_dial_from_bt_para_p->dev_addr[idx], &cm_dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));
        }
    }

    SetKeyDownHandler(mmi_ucm_call_select_sendkey_hdlr, KEY_SEND);
}


mmi_ret mmi_ucm_call_select_bt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ucm_bt_make_call_para_struct* make_bt_call_para_p = (mmi_ucm_bt_make_call_para_struct*)menu_evt->app_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_ucm_call_select_main_menu_entry(menu_evt->sender_id, make_bt_call_para_p);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            if (MENU_ID_UCM_FROM_BT_CALL == menu_evt->highlighted_menu_id)
            {
                g_dial_from_bt_para_p->menu_index = 1;
            }
            else if (MENU_ID_UCM_FROM_BT_CALL2 == menu_evt->highlighted_menu_id)
            {
                g_dial_from_bt_para_p->menu_index = 2;
            }
        }
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {   
                case MENU_ID_UCM_FROM_BT_CALL:
                case MENU_ID_UCM_FROM_BT_CALL2:

                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP, 501);
                    memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, 
                           &g_dial_from_bt_para_p->dev_addr[g_dial_from_bt_para_p->menu_index-1],
                           sizeof(srv_bt_cm_bt_addr));

                    mmi_ucm_call_launch_bt(&g_dial_from_bt_para_p->make_call_from_bt);
                    break;

                default:
                    break;
            }
        }
        break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP_P1, 601, menu_evt->sender_id);
            cui_menu_close(menu_evt->sender_id);
        }
        break;
        case EVT_ID_CUI_MENU_LIST_DEINIT:

            if (menu_evt->app_data != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP, 901);
                OslMfree(menu_evt->app_data);
            }
            if (g_dial_from_bt_para_p != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP, 902);
                OslMfree(g_dial_from_bt_para_p);
                g_dial_from_bt_para_p = NULL;
            }
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_opt_proc
 * DESCRIPTION
 *  The proc function of incall option
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_incall_opt_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    mmi_ret ret = MMI_RET_OK;
    MMI_BOOL act_is_executed = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch(menu_evt->parent_menu_id)
            {   
                /* 0 , non-leaf */
                case MENU_ID_UCM_BT_INCALL_OPTION:
                {
                    mmi_ucm_handle_incall_option_bt(menu_evt->sender_id);
                    SetKeyHandler(mmi_ucm_in_call_endkey_bt, KEY_END, KEY_EVENT_DOWN);
                }
                break;
                default:
                break;
            }  
        }
        break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            
            switch(menu_evt->highlighted_menu_id)
            {
                   case MENU_ID_UCM_BT_INCALL_OPTION_HOLD:
                {
                    mmi_ucm_hold_action_bt();
                }
                break;
                   case MENU_ID_UCM_BT_INCALL_OPTION_RETRIEVE:
                {
                    mmi_ucm_retrieve_action_bt();
                }
                break;
                   case MENU_ID_UCM_BT_INCALL_OPTION_SWAP:
                {
                    mmi_ucm_swap_action_bt();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_DTMF:
                {
                    mmi_ucm_pre_entry_dtmf_editor_bt();
                }
                break;
                   case MENU_ID_UCM_BT_INCALL_OPTION_MUTE:
                {
                    srv_speech_mute_phone();
                }
                break;
                   case MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE:
                {
                    srv_speech_unmute_phone();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_END_SINGLE:
                {
                    mmi_ucm_end_single_action_bt();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_END_CONF:
                {
                    mmi_ucm_end_single_action_bt();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_END_ALL:
                {
                    mmi_ucm_end_all_action_bt(); 
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_SWITCH_AUDIO_PATH:
                {
                    mmi_ucm_switch_audio_action_bt();
                }
                break;
            #ifdef __MMI_UCM_BT_CALL_RECORDER__
                case MENU_ID_UCM_BT_INCALL_OPTION_RECODE:
                {
                    mmi_ucm_start_record_option_bt();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE:
                {
                    mmi_ucm_end_record_option_bt();
                }
                break;
            #endif /*__MMI_UCM_BT_CALL_RECORDER__*/
            #ifdef __MMI_BT_BQB_TEST__
                case MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_HOLD:
                {
                    mmi_ucm_for_bqb_test_mode_hold();
                }
                break;
                case MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_END:
                {
                    mmi_ucm_for_bqb_test_mode_end();
                }
                break;
            #endif /* __MMI_BT_BQB_TEST__ */

                default:
                {
                    act_is_executed = MMI_FALSE;    
                }
                break;
            }

            if (act_is_executed)
            {
                mmi_ucm_close_cui_bt(&g_ucm_p_bt->incall_opt_cui_id);
            }
        }
        break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if (menu_evt->sender_id == g_ucm_p_bt->incall_opt_cui_id)
            {
                g_ucm_p_bt->incall_opt_cui_id = GRP_ID_INVALID;
            }
            cui_menu_close(menu_evt->sender_id);
            return ret;
        }

        default:
        break;
    }

    /* mean option menu items which is provided by other applications */
    wgui_inputs_options_menu_handler(evt, GRP_ID_UCM_BT_INCALL);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sg_create
 * DESCRIPTION
 *  create SG based on given sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_ucm_sg_create_bt(MMI_ID parent_id, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID enter_return_id = GRP_ID_INVALID;
    mmi_proc_func proc = NULL;
    mmi_group_enter_flag flag = MMI_FRM_NODE_SMART_CLOSE_FLAG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && defined(__MMI_BT_BTBOX_NOLCD__)
    mmi_bt_anti_lost_screen_close();
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && __MMI_BT_BTBOX_NOLCD__ */

    if (MMI_FALSE == mmi_frm_group_is_present(group_id))
    {
        switch (group_id)
        {
            case GRP_ID_UCM_BT_MO:
            {   
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

            case GRP_ID_UCM_BT_MT:
            {    
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

            case GRP_ID_UCM_BT_INCALL:
            {
            #ifndef __MMI_UCM_BT_BTBOX_NOLCD__
                proc = mmi_ucm_incall_sg_proc_bt;
            #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

            case GRP_ID_UCM_BT_CALL_END:
            {
                flag = MMI_FRM_NODE_SMART_CLOSE_FLAG;
            }
            break;

            default: 
            {
                //MMI_ASSERT(0); 
            } 
            break; 
        }

    #ifdef __MMI_UCM_BT_BTBOX_NOLCD__
        proc = mmi_ucm_btb_input_event_proc;
    #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

        enter_return_id = mmi_frm_group_create_ex(parent_id, group_id, proc, NULL, flag);
    }
    return enter_return_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_processing_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void            [IN]        Title string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_swap_processing_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_force_refresh_act_req_struct refresh_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_MO_PROCESSING_TIMER_BT);
    refresh_req.srv_hd = g_ucm_p_bt->refresh_srv;
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_PROCESSING, MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_PRO_TIMEOUT);
        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_FORCE_REFRESH_ACT, &refresh_req))
        {
            srv_ucm_bt_act_request(SRV_UCM_BT_FORCE_REFRESH_ACT, &refresh_req);
        }
        else
        {
            mmi_ucm_bt_close_processing_scrn();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_processing_screen_internal
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bt_enter_processing_screen(MMI_ID SG_id, S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_PROCESSING_SCRN_BT, SG_id);
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    /*  it is a limitation in FW to handle anti-blinking + hardware blt screen, 
        therefore need to add dummy screen here to prevent screen flash 
        ex. hold and accept, the MT screen disable blt because of caller video */
    if (SCR_ID_UCM_BT_PROCESSING == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_UCM_BT_DUMMY);
    }

    mmi_ucm_bt_close_processing_scrn(); /* delete old processing screen if exists */

    g_ucm_p_bt->refresh_srv = srv_hd;

    mmi_frm_scrn_first_enter(
        SG_id, SCR_ID_UCM_BT_PROCESSING, 
        (FuncPtr)mmi_ucm_bt_entry_processing_screen, 
        (void*)NULL);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_close_processing_scrn
 * DESCRIPTION
 *  close processing scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bt_close_processing_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_PROCESSING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_entry_processing_screen
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bt_entry_processing_screen(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *body_string_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BT_PROCESSING,
                    NULL,
                    (FuncPtr)mmi_ucm_bt_entry_processing_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }


    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_PROCESSING_SCREEN);
    
    body_string_p = (U8*) GetString(STR_ID_UCM_BT_PROCESSING);
    
    ShowCategory66Screen(0, 0, 0, 0, 0, 0, body_string_p, IMG_GLOBAL_PROGRESS, NULL);
    
    mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_EVENT_DOWN);

    mmi_frm_scrn_set_leave_proc(
        scr_info->group_id, 
        SCR_ID_UCM_BT_PROCESSING, 
        (mmi_proc_func) mmi_ucm_bt_processing_screen_delete_proc);

    StartTimer(UCM_MO_PROCESSING_TIMER_BT, 6000, mmi_ucm_swap_processing_timeout_hdlr);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_processing_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for processing screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_bt_processing_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            if (IsMyTimerExist(UCM_MO_PROCESSING_TIMER_BT))
            {
                g_ucm_p_bt->refresh_srv = 0;
                StopTimer(UCM_MO_PROCESSING_TIMER_BT);
            }
        }
        break;   
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_and_accpet_confirm_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_and_accpet_confirm_bt(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        parent_id, SCR_ID_UCM_END_AND_ACCEPT_CONFIRM, 
        (FuncPtr)mmi_ucm_end_and_accpet_entry_confirm_bt, 
        (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_and_accpet_entry_confirm_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_and_accpet_entry_confirm_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_END_AND_ACCEPT_CONFIRM,
                    NULL,
                    (FuncPtr)mmi_ucm_end_and_accpet_entry_confirm_bt,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_END_AND_ACCEPT_CONFIRM, NULL);
        return;
    }

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (WCHAR*) GetString(STR_ID_UCM_BT_CALL_WILL_BE_ENDED),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    SetLeftSoftkeyFunction(mmi_ucm_end_and_accpet_confirm_yes_hdlr_bt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_end_and_accpet_confirm_yes_hdlr_bt, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_END_AND_ACCEPT_CONFIRM, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_and_accpet_confirm_yes_hdlr_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_and_accpet_confirm_yes_hdlr_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CONFIRM_YES, 0);

    if (!srv_ucm_is_incoming_call())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CONFIRM_YES, 1);
        if (SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACT, NULL))
        {
            srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, mmi_ucm_act_callback_bt);
            mmi_frm_scrn_close_active_id();
        }
    }
    else
    {
        U32 call_count;
        call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL);
        g_ucm_p_bt->is_need_accept = MMI_TRUE;
        if (call_count == 1)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CONFIRM_YES, 2);
            mmi_ucm_end_single_action_bt();
        }
        else if (call_count == 2)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CONFIRM_YES, 3);
            mmi_ucm_end_all_action_bt();
        }
        else if (call_count == 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CONFIRM_YES, 4);
            mmi_ucm_end_btdialer_and_accept_option_bt();
        }
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_callback_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event     [IN]    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_act_callback_bt(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct *act_result = (srv_ucm_act_result_evt_struct *) event;
 
    if (EVT_ID_SRV_UCM_ACTION_RESULT == event->evt_id)
    {
        if (SRV_UCM_END_ALL_ACT == act_result->act_op)
        {
            mmi_ucm_answer_action_bt();
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_dialling_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_dialling_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO_SELECT, SCR_ID_UCM_BT_DIALLING, MMI_FRM_NODE_ALL_FLAG))
    {    
        mmi_frm_scrn_close(GRP_ID_UCM_MO_SELECT, SCR_ID_UCM_BT_DIALLING);
    } 
#else
    mmi_frm_group_create_ex(GRP_ID_ROOT, 
        GRP_ID_UCM_MO_SELECT, 
        NULL, 
        NULL, 
        MMI_FRM_NODE_NONE_FLAG);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MO_SELECT, SCR_ID_UCM_BT_DIALLING, 
        (FuncPtr)mmi_ucm_entry_dialling_bt, 
        (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_go_back_BT_call_screen_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_go_back_BT_call_screen_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_ucm_is_any_call() && mmi_ucm_get_hide_state_bt())
    {
        if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
        {
            mmi_ucm_set_hide_state_bt(MMI_FALSE);
            mmi_ucm_enter_incoming_call_bt();
        }
        else if (srv_ucm_bt_query_call_count(SRV_UCM_BT_OUTGOING_STATE, NULL) > 0)
        {
            mmi_ucm_set_hide_state_bt(MMI_FALSE);
            mmi_ucm_enter_outgoing_call_bt();
        }
        else if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
        {
            mmi_ucm_set_hide_state_bt(MMI_FALSE);
            mmi_ucm_enter_in_call_bt();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mo_processing_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_mo_processing_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_MO_PROCESSING_TIMER_BT);
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0
        &&  mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
        mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_UNSPECIFIED_ERROR);
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_dialling_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_dialling_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                scr_info->group_id,
                SCR_ID_UCM_BT_DIALLING,
                NULL,
                (FuncPtr)mmi_ucm_entry_dialling_bt,
                MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(
                GRP_ID_UCM_MO_SELECT, 
                SCR_ID_UCM_BT_DIALLING, 
                NULL);
        return;
    }

    ShowCategory66Screen(NULL,NULL,NULL,NULL,NULL,NULL,
        (PU8)GetString(STR_ID_UCM_BT_PROCESSING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    StartTimer(UCM_MO_PROCESSING_TIMER_BT, MMI_UCM_MO_PROCESSING_TIMEOUT_BT, mmi_ucm_mo_processing_timeout_hdlr);
    SetKeyHandler(UI_dummy_function, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_incall_option_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  owner_gid     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_incall_option_bt(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hold_call_count = srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_HOLD_STATE, NULL);
    S32 active_call_count = srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_ACTIVE_STATE, NULL);
    MMI_BOOL is_end_single = MMI_FALSE;
    MMI_BOOL is_end_all = MMI_FALSE;
    MMI_BOOL is_DTMF = MMI_FALSE;
    srv_ucm_bt_call_info_struct call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_IN_CALL_MENU, hold_call_count, active_call_count);

    srv_ucm_bt_query_call_data(g_ucm_p_bt->hilite_call_id, &call_info);

    if (hold_call_count == 0 && active_call_count > 0) // acitve call only
    {
        is_end_single = MMI_TRUE;
        is_DTMF = MMI_TRUE;
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_HOLD, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_HOLD, MMI_TRUE);
    }

#ifdef __MMI_UCM_BT_CALL_RECORDER__
    if (hold_call_count > 0 || active_call_count > 0) // Both acitve and hold call
    {
        if(mdi_audio_is_recording())
        {
            /*Unrecord*/
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_RECODE, MMI_TRUE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE, MMI_FALSE);  
        }
        else
        {
            /*Record*/
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_RECODE, MMI_FALSE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_RECODE, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE, MMI_TRUE);  
    }
#endif /*__MMI_UCM_BT_CALL_RECORDER__*/
    if (hold_call_count > 0 && active_call_count == 0) // hold call only
    {
        is_end_single = MMI_TRUE;
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_RETRIEVE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_RETRIEVE, MMI_TRUE);
    }

    if (hold_call_count > 0 && active_call_count > 0) // swap
    {
        is_end_all = MMI_TRUE;
        is_end_single = MMI_TRUE;
        is_DTMF = MMI_TRUE;
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_SWAP, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_SWAP, MMI_TRUE);
    }

    if (hold_call_count > 0 || active_call_count > 0)
    {
        if(srv_speech_is_phone_mute())
        {/*Unmute*/
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_MUTE, MMI_TRUE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE, MMI_FALSE);
        }
        else
        {/*Mute*/
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_MUTE, MMI_FALSE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_MUTE, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE, MMI_TRUE);  
    }

    if (is_end_single && !call_info.multiParty)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_SINGLE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_SINGLE, MMI_TRUE);
    }

    if (call_info.multiParty)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_CONF, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_CONF, MMI_TRUE);
    }

    if (is_end_all)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_ALL, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_END_ALL, MMI_TRUE);
    }
    if (is_DTMF)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_DTMF, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_DTMF, MMI_TRUE);
    }

    if (srv_bt_cm_get_bqb_test_flag())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_HOLD, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_END, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_HOLD, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_END, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_loud_speaker_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_loud_speaker_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    U16 str = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) /* O */
    {
        str = STR_ID_UCM_BT_HAND_FREE;
        srv_speech_disable_hand_free();
    }
    else
    {
        str = STR_ID_UCM_BT_HAND_HELD;
        srv_speech_enable_hand_free();
    }

    ChangeRightSoftkey(str, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_update_clog_evt_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_send_update_clog_evt_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SEND_CLOG_EVT, 0);
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_BT_CALL_END);
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_dtmf_editor_screen_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_delete_dtmf_editor_screen_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_UCM_BT_INCALL, SCR_ID_UCM_BT_DTMF_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dtmf_editor_key_proc_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_dtmf_editor_key_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)(evt);
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            if (wgui_inputs_dialer_is_dialer_keys(key_code) == MMI_TRUE)
            {
                if (key_type == KEY_EVENT_DOWN)
                {
                     mmi_ucm_send_dtmf_action_bt(key_code);
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_dtmf_editor_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_entry_dtmf_editor_bt(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BT_DTMF_EDITOR,
                    (FuncPtr)NULL,
                    (FuncPtr)mmi_ucm_entry_dtmf_editor_bt,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_key_proc(GRP_ID_ROOT, SCR_ID_UCM_BT_DTMF_EDITOR, mmi_ucm_dtmf_editor_key_proc_bt);
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_BT_DTMF_EDITOR);

#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(NULL);
    SetDialingKeypadPhonebookHandler(NULL);
#endif /* __MMI_TOUCH_SCREEN__ */

    ShowCategory16Screen(
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)g_ucm_p_bt->disp_dtmf,
        (MMI_UCM_DTMF_LEN + 1),
        guiBuffer);

    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_VOL_DOWN, KEY_EVENT_DOWN); 
#ifdef __MMI_BTD_BOX_UI_STYLE__
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_ucm_set_sidekey_bt, KEY_DOWN_ARROW, KEY_LONG_PRESS);
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
    mmi_frm_set_key_handler(mmi_ucm_end_single_action_bt, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_dtmf_editor_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_enter_dtmf_editor_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id dialer_parent_gid = mmi_frm_group_get_active_id();
    dialer_parent_gid = mmi_frm_group_get_top_parent_group_id(dialer_parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_UCM_BT_INCALL == dialer_parent_gid)
    {
        mmi_frm_scrn_first_enter(
            dialer_parent_gid, SCR_ID_UCM_BT_DTMF_EDITOR, 
            (FuncPtr)mmi_ucm_entry_dtmf_editor_bt, 
            (void*)NULL);
    }
    else
    {
       /* because dtmf editor scrn is triggered by user touch key or select items, curr_active group must call scrn */
        MMI_ASSERT(0);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_entry_dtmf_editor_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_pre_entry_dtmf_editor_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Avoid re-entry of DTMF editor */
    mmi_ucm_delete_dtmf_editor_screen_bt();    
    mmi_ucm_close_cui_bt(&g_ucm_p_bt->incall_opt_cui_id);
    memset(g_ucm_p_bt->disp_dtmf, 0, sizeof(g_ucm_p_bt->disp_dtmf));  
    mmi_ucm_enter_dtmf_editor_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_call_key_proc_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_bk_call_key_proc_bt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);

    if (MMI_FALSE == mmi_ucm_is_ucm_sg_bt(curr_act_sg_id))
    {
        if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
        {
            if (key_code == KEY_END && key_type == KEY_EVENT_DOWN)
            {
                if (srv_ucm_is_incoming_call() || g_ucm_p_bt->is_hide_screen)
                {
                    return MMI_RET_OK;
                }
                mmi_ucm_in_call_endkey_bt();
                return MMI_RET_STOP_KEY_HANDLE;
            }
        }
    }
    return MMI_RET_OK;
}


#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_btb_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_prof_ret result    [IN]
 * RETURNS
 *  srv_prof_ret  [OUT]
 *****************************************************************************/
static srv_prof_ret mmi_ucm_btb_notify_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BTB_NOTIFY_CB, result);

    if (result != MDI_AUDIO_TERMINATED)
        mdi_audio_resume_background_play();    
    
    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_btb_send_notify
 * DESCRIPTION
 *  N/A.
 * PARAMETERS
 *  notify_id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_ucm_btb_send_notify(U16 notify_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_input_event_notify_param param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BTB_SEND_NOTIFY, notify_id);

    mmi_frm_input_event_enable_notify();
    param.aud_cb = mmi_ucm_btb_notify_callback;
    mdi_audio_suspend_background_play();
    mmi_frm_input_event_notify_remove(notify_id);
    mmi_frm_input_event_notify(notify_id, &param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_input_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]    
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_btb_input_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BTB_INPUT_EVENT_PROC,evt->evt_id);
    
    switch(evt->evt_id)
    {
        case EVT_UCM_BT_BTBOX_CALL_ANSWER:
            if(srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE, NULL))
            {
                mmi_ucm_answer_action_bt();
            }
            else if(srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, NULL))
            {
               mmi_ucm_end_single_action_bt();
            }
            else if( srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) && srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE, NULL))
            {
               mmi_ucm_answer_action_bt();
            }
            else if( srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) == 2)
            {
                mmi_ucm_end_all_action_bt();
            }
            break;
        case EVT_UCM_BT_BTBOX_CALL_SWAP:
            if(!srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE|SRV_UCM_BT_OUTGOING_STATE, NULL))
            {
                if(2 == srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL))
                {
                    mmi_ucm_swap_action_bt();
                }
                else if(srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, NULL))
                {
                    mmi_ucm_hold_action_bt();
                }
                else if(srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, NULL))
                {
                    mmi_ucm_retrieve_action_bt();
                }
            }
            break;
        case EVT_UCM_BT_BTBOX_CALL_END:  
            mmi_ucm_end_single_action_bt();
            break;
        case EVT_UCM_BT_BTBOX_VOLUP:
            mmi_ucm_btb_vol_hdlr(MMI_TRUE);
            break;
        case EVT_UCM_BT_BTBOX_VOLDOWN:
            mmi_ucm_btb_vol_hdlr(MMI_FALSE);
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}
#endif /*__MMI_UCM_BT_BTBOX_NOLCD__*/
#endif /* __MMI_BT_CALL_SUPPORT__ */


