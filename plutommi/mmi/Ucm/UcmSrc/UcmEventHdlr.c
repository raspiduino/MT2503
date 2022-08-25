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
 *  UCMMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM event handler source file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_UCM__

#include "mmi_rp_app_ucm_def.h"
#include "mmi_rp_core_ucm_def.h"
#include "mdi_audio.h" /* MMI_EVENT_SUCCESS. in which include custom_events_notify.h */
#include "UCMGProt.h"
#include "UCMProt.h"
#include "UcmCoreProt.h"
#include "UcmSrvGProt.h"
#ifdef __MMI_VIDEO_TELEPHONY__
#include "UcmVtCallScrGProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef __MMI_CALL_INDICATOR__
#include "StatusIconRes.h" /* for IMG_SI_CALL_INDICATOR_ACTIVE related */
#endif /* __MMI_CALL_INDICATOR__ */
#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundGProt.h"  /* mmi_bgsnd_util_stop_play_sound(); */
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */
#include "MMIDataType.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "gui.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_timer_gprot.h"
#include "custom_events_notify.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "kal_public_api.h"
#include "GpioSrvGprot.h"
#ifdef __PXS_APP_ENABLE__
#include "SensorSrvGport.h"
#endif /* __PXS_APP_ENABLE__ */
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_availability_changed_evt_struct */
#include "SensorSrvGport.h"
#include "CallSetSrvGprot.h"
#include "ScrLockerGprot.h"
#include "ModeSwitchSrvGProt.h"
#if defined(__MMI_NCENTER_SUPPORT__) 
#include "vapp_ncenter_gprot.h"
#endif /* defined(__MMI_NCENTER_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_notify_hdlr
 * DESCRIPTION
 *  This function is to handle the act notify sent from ucm srv
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_act_notify_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_rsp_struct *accept_rsp;
    srv_ucm_act_notify_evt_struct *act_notify;
    srv_ucm_act_rsp_struct* dial_rsp;
    srv_ucm_act_rsp_struct *rsp;
    srv_ucm_single_call_act_req_struct *start_notify_req;
    srv_ucm_act_rsp_struct *end_rsp;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    act_notify = (srv_ucm_act_notify_evt_struct *) para;
	
    /* update call indicator */
#ifdef __MMI_CALL_INDICATOR__
    /* update the call indicator icon on the status bar*/

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_ACTIVE);
        wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);
    }
    else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_HOLD);
        wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);
    }
    else
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CALL_INDICATOR);
    }
#endif  /* __MMI_CALL_INDICATOR__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_P3, act_notify->act_op, act_notify->act_type, act_notify->notify_type);
    switch (act_notify->act_op)
    {
        case SRV_UCM_DIAL_ACT:
        {
            /* 1. START */
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
            {
            #ifdef __PXS_APP_ENABLE__
                if (MMI_FALSE == g_ucm_p->pxs_turn_on)
                {
                    srv_sensor_pxs_turn_on();
                    g_ucm_p->pxs_turn_on = MMI_TRUE;
                }
            #endif /* __PXS_APP_ENABLE__ */

                /* prevent idle screen flashes before calling screen in auto redial cases */
                if (mmi_frm_group_get_active_id() == GRP_ID_UCM_AUTO_REDIAL)
                {
                    mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
                }
                else
                {
                    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, (mmi_proc_func) NULL);
                    mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
                }

                mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MO);
                mmi_ucm_entry_gray_screen(GRP_ID_UCM_MO);
                mmi_frm_group_close(GRP_ID_UCM_PRE_MO);

            #ifdef __MMI_TOUCH_SCREEN__
                /* stop virtual keypad tone if necessary. Ex. speed dial case */
                mmi_pen_reset();
            #endif /* __MMI_TOUCH_SCREEN__ */
                /*clear hdlr in case user press key many times on purpose before screen is displayed*/
                /*must have outgoing ind or rel ind to display new screen, the hdlr will recover at that time*/
                ClearInputEventHandler(MMI_DEVICE_ALL);
                SetKeyUpHandler(UI_dummy_function, KEY_END);
                SetKeyDownHandler(UI_dummy_function, KEY_END);
                SetKeyLongpressHandler(UI_dummy_function, KEY_END);
                SetKeyRepeatHandler(UI_dummy_function, KEY_END);
                /*do nothing, the outgoing call screen will be dispalyed when handling outgoing_ind*/
            }
            /* 2. END */
            else if (SRV_UCM_ACT_NOTIFY_TYPE_END == act_notify->notify_type) 
            {
                dial_rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, dial_rsp->result_info.result);
                if (dial_rsp->result_info.result == SRV_UCM_RESULT_OK)
                {
                    if (SRV_UCM_ACT_TYPE_SINGLE == act_notify->act_type || SRV_UCM_ACT_TYPE_COMPOUND_SECOND == act_notify->act_type)
                    {
                        mmi_ucm_go_back_screen_check();
                    }

                #ifdef __BT_SPK_VOL_CONTROL__
                    /*handle vol control*/
                    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)
                    {
                        /* do not register vol control callback for csd/data call */
                        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) == 0)
                        {    
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DIAL_ACT_RSP_OK_VOL_CONTROL_START);
                            mdi_audio_bt_register_volume_sync_callback(APP_UCM, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_ucm_volume_control_callback);
                        }
                    }
                #endif /* __BT_SPK_VOL_CONTROL__ */
                }
                else  /* dial_rsp->result_info.result != SRV_UCM_RESULT_OK */
                {
                    /*SS won't ret fail*/
                    mmi_ucm_handle_dial_rsp_fail(dial_rsp->result_info);   
                }
            }
        }
        break;

        case SRV_UCM_ACCEPT_ACT:
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
            {
                StopTimer(UCM_AUTO_ANSWER_TIMER);
                mmi_ucm_pre_enter_processing_screen(SRV_UCM_ACCEPT_ACT, GRP_ID_UCM_MT);
            }
            else
            {
                accept_rsp = (srv_ucm_act_rsp_struct*)act_notify->ptr;
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, accept_rsp->result_info.result);
                /* will trigger enter incall screen if result = T and popup error msg if result = F */
                mmi_ucm_set_no_counter_status(accept_rsp->no_counter);      
                mmi_ucm_accept_act_rsp(accept_rsp, act_notify->act_type);
            }
        }
        break;

        case SRV_UCM_HOLD_ACT: 
        case SRV_UCM_RETRIEVE_ACT:
        case SRV_UCM_SPLIT_ACT:  
        case SRV_UCM_CONFERENCE_ACT:
    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_DEFLECT_ACT:
    #endif /* __MMI_UCM_DEFLECT__ */
    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
    #endif /* __MMI_UCM_ECT__ */
    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:
    #endif /* __MMI_UCM_TRANSFER__ */
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))      
        case SRV_UCM_VT_FALLTO_VOICE_ACT:            
    #endif /* __MMI_VIDEO_TELEPHONY__ */        
        {
            /* Because for SWAP compound actions, the swapping screen will be displayed when receiving 
            SWAP start notify. Does not show each step, hold and retrieve individually */
            if (SRV_UCM_SWAP_ACT == act_notify->comp_act_op)
            {
                break;
            }
            
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
            #ifdef __MMI_UCM_DEFLECT__
                if (act_notify->act_op == SRV_UCM_DEFLECT_ACT)
                {
                    mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_MT);
                }
                else 
            #endif /* __MMI_UCM_DEFLECT__ */
            #ifdef __MMI_UCM_ECT__
                if (act_notify->act_op == SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT)
                {
                    /* MO > Incall */
                    if (mmi_frm_group_is_present(GRP_ID_UCM_MO))
                    {
                        mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_MO);
                    }
                    else
                    {
                        mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_INCALL);
                    }
                }
                else 
             #endif /* __MMI_UCM_ECT__ */
                if ((SRV_UCM_HOLD_ACT == act_notify->act_op) && 
                    (SRV_UCM_ACT_TYPE_COMPOUND_FIRST == act_notify->act_type) &&
                    (SRV_UCM_HOLD_AND_ACCEPT_ACT == srv_ucm_query_curr_action()))
                {
                    /* special handle for SRV_UCM_HOLD_AND_ACCEPT_ACT */
                    mmi_ucm_pre_enter_processing_screen(act_notify->act_op, mmi_frm_group_get_active_id());
					
                }
            #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))   
                else if (SRV_UCM_VT_FALLTO_VOICE_ACT == act_notify->act_op)
                {
                    mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_MT);
                }
            #endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__ */    
                else
                {
                  mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_INCALL);
                }

                /* special handle for SRV_UCM_HOLD_AND_DIAL_ACT */
                if ((SRV_UCM_HOLD_ACT == act_notify->act_op) && 
                    (SRV_UCM_ACT_TYPE_COMPOUND_FIRST == act_notify->act_type) &&
                    (SRV_UCM_HOLD_AND_DIAL_ACT == srv_ucm_query_curr_action()))
                {
                    mmi_ucm_entry_gray_screen(GRP_ID_UCM_PRE_MO);
                }
                
            }
            else
            {
                rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;

                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, rsp->result_info.result);            

                if (rsp->result_info.result == SRV_UCM_RESULT_OK)
                {  
                #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))      
                    if (SRV_UCM_VT_FALLTO_VOICE_ACT == act_notify->act_op)
                    {
                        /* Do nothing, if mmi_ucm_go_back_screen_check, fall to screen will be deleted */
    
                    }
                    else
                #endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__*/        
                    if (SRV_UCM_ACT_TYPE_SINGLE == act_notify->act_type || SRV_UCM_ACT_TYPE_COMPOUND_SECOND == act_notify->act_type)
                    {
                        mmi_ucm_go_back_screen_check();
                    }
                }
                else
                {
                    mmi_ucm_display_popup_when_call_exist((UI_string_type) rsp->result_info.error_msg, MMI_EVENT_FAILURE);
                    mmi_ucm_go_back_screen_check();
                }
            }
        }
        break;
      
        case SRV_UCM_END_SINGLE_ACT:
        case SRV_UCM_END_CONFERENCE_ACT:
        case SRV_UCM_END_ALL_ACT: 
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ 
        case SRV_UCM_END_ALL_ACTIVE_ACT:
#endif
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        case SRV_UCM_END_ALL_HELD_ACT:
#endif
        case SRV_UCM_END_ALL_PROCESSING_ACT:
        {     
            /* if there is no call when rece end notify with error result, don't display error popup */
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
            {
                if (act_notify->act_op == SRV_UCM_END_SINGLE_ACT)
                {
                    start_notify_req = (srv_ucm_single_call_act_req_struct*) act_notify->ptr;
                
                    if (MMI_TRUE == srv_ucm_query_call_exist(&(start_notify_req->action_uid), SRV_UCM_INCOMING_STATE))
                    {
                        mmi_ucm_stop_incoming_tone();
                        /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                        StopTimer(UCM_AUTO_ANSWER_TIMER);
                    }
                }
                else if (act_notify->act_op == SRV_UCM_END_ALL_ACT)
                {
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
                    {
                        mmi_ucm_stop_incoming_tone();
                        /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                        StopTimer(UCM_AUTO_ANSWER_TIMER);                       
                    }
                }
                /* if single or conpound _2nd, means these end actions is user-aware, so ues gray screen */
                if (act_notify->act_type == SRV_UCM_ACT_TYPE_SINGLE || act_notify->act_type == SRV_UCM_ACT_TYPE_COMPOUND_SECOND)
                {
                    /* clear hdlr in case user press key many times on purpose before screen is displayed */
                    /* must have disconnecting ind or rel ind to display new screen, the hdlr will recover at that time */
                    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
                    {
                         SetKeyUpHandler(UI_dummy_function, KEY_END);
                         SetKeyDownHandler(mmi_ucm_end_key, KEY_END);
                         SetKeyLongpressHandler(UI_dummy_function, KEY_END);
                         SetKeyRepeatHandler(UI_dummy_function, KEY_END);
                    }
                }
                else /* SRV_UCM_ACT_TYPE_COMPOUND_FIRST, ,means this end action is not user-aware */
                {
 mmi_ucm_close_processing_scrn(); /* in case clam close in the processing screen */
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__             
                    if ((SRV_UCM_END_ALL_ACTIVE_ACT == act_notify->act_op) &&
                        (SRV_UCM_ACT_TYPE_COMPOUND_FIRST == act_notify->act_type) &&
                        (SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT == srv_ucm_query_curr_action()))
                    {
                        /* special handle for SRV_UCM_HOLD_AND_ACCEPT_ACT */
                        mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_INCALL);
                    }
                    else
                    {
#endif
                        mmi_ucm_pre_enter_processing_screen(act_notify->act_op, mmi_frm_group_get_active_id());
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
                    }
#endif
                }
            }
            else
            {
                end_rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
            
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, end_rsp->result_info.result);

                
                /* [UCM3.0] if compound action 1st fail, user may not understand the error msg */
                if (SRV_UCM_RESULT_OK != end_rsp->result_info.result)
                {
                    mmi_ucm_display_popup_when_call_exist((UI_string_type)end_rsp->result_info.error_msg, MMI_EVENT_FAILURE);
                }
            }
        }
        break;

		/* compound actions */

        case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
        case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
        case SRV_UCM_HOLD_AND_ACCEPT_ACT:
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {   
                /* for it's 2nd action= accept. even */
                mmi_ucm_stop_incoming_tone();
                /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                StopTimer(UCM_AUTO_ANSWER_TIMER);
            }
        }
        break;    
 #ifndef __SLIM_UCM__            
        case SRV_UCM_END_ALL_AND_DIAL_ACT:
        {
        #ifdef __MMI_VIDEO_TELEPHONY__
            rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
            if (SRV_UCM_ACT_NOTIFY_TYPE_END == act_notify->notify_type && 
                SRV_UCM_RESULT_OK != rsp->result_info.result) 
            {
                mmi_ucm_vt_set_is_switch_action(MMI_FALSE);
                mmi_ucm_vt_set_switch_call_type(SRV_UCM_CALL_TYPE_END_OF_ENUM);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
        }
        break;
#endif             
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
        case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
#endif
        case SRV_UCM_HOLD_AND_DIAL_ACT:
        {
            /* do nothing */
        }
        
        break;
        
        case SRV_UCM_SWAP_ACT:	
        {
            /* For swap action, want to show swapping, swapped, not display each step like other compound actions*/
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
            {
                mmi_ucm_pre_enter_processing_screen(act_notify->act_op, GRP_ID_UCM_INCALL);                
            }
            else
            {
                rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, rsp->result_info.result);            

                if (rsp->result_info.result != SRV_UCM_RESULT_OK)
                {
                    mmi_ucm_display_popup_when_call_exist((UI_string_type) rsp->result_info.error_msg, MMI_EVENT_FAILURE);
                }

                mmi_ucm_go_back_screen_check();
            }
            
        }
        break;

        case SRV_UCM_START_DTMF_ACT:
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
                g_ucm_p->call_misc.is_dtmf_start = MMI_TRUE;
            }
            else
            {
                MMI_ASSERT(0); /* these is action without rsp, so it's impossible to get end notify */
            }
        }
        break;

        case SRV_UCM_STOP_DTMF_ACT:	
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
                g_ucm_p->call_misc.is_dtmf_start = MMI_FALSE;
            }
            else
            {
            	MMI_ASSERT(0); /* these is action without rsp, so it's impossible to get end notify */
            }
        }
        break;

        case SRV_UCM_SEND_DTMF_DIGITS_ACT:
        {
            /* do nothing */
        }
        break;

        default:
        {
           
        }
        break;   
    }
    return MMI_RET_OK; 	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the indication sent from ucm srv
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct *ind;
    srv_ucm_incoming_call_ind_struct *incoming_ind;
    srv_ucm_outgoing_call_ind_struct *outgoing_ind;
    srv_ucm_alert_ind_struct *alert_ind;
    srv_ucm_notify_ind_struct *notify_ind;
    srv_ucm_connect_ind_struct *connect_ind;
    srv_ucm_disconnecting_ind_struct *disconnecting_ind;
    srv_ucm_release_ind_struct *release_ind;
    srv_ucm_call_cost_ind_struct *call_cost_ind;
    srv_ucm_auto_redial_ind_struct *auto_redial_ind;
#ifdef __MMI_VOIP__
    srv_ucm_start_processing_ind_struct *start_processing_ind;
    srv_ucm_stop_processing_ind_struct *stop_processing_ind;
#endif /* __MMI_VOIP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ind = (srv_ucm_ind_evt_struct *) para;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_IND_HDLR_P1, ind->ind_type);

    /* update the call indicator icon on the status bar */
#ifdef __MMI_CALL_INDICATOR__
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_ACTIVE);
        wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);
    }
    else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_HOLD);
        wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);
    }
    else
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CALL_INDICATOR);
    }
#endif  /*__MMI_CALL_INDICATOR__*/


    switch (ind->ind_type)
    {
        case SRV_UCM_START_COUNT_IND:
        {
        #ifdef __MMI_VIDEO_TELEPHONY__
            mmi_vtcs_call_status_callback(MMI_TRUE);
        #endif /* __MMI_VIDEO_TELEPHONY__ */

            mmi_ucm_set_no_counter_status(MMI_FALSE);
        }
        break;

        case SRV_UCM_INCOMING_CALL_IND:
        {
            incoming_ind = (srv_ucm_incoming_call_ind_struct*) ind->ptr;
        #if defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__)
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_INCOMING_EVENT);
        #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__) */

            mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MT);
            /* display the incoming call screen */
            mmi_ucm_handle_incoming_call_ind(incoming_ind);
        }
        break;

        case SRV_UCM_OUTGOING_CALL_IND:
        {
            if (!mmi_frm_group_is_present(GRP_ID_UCM_MO))
            {
                mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MO);
            }
            outgoing_ind = (srv_ucm_outgoing_call_ind_struct*) ind->ptr;
            g_ucm_p->call_misc.get_alert_ind = MMI_FALSE;
        #if defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__)
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_OUTGOING_EVENT);
        #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__) */
            mmi_ucm_handle_outgoing_call_ind(outgoing_ind);
        #ifdef __OP01_FWPBW__
            mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_OUTGOING_EVENT);
        #endif /* __OP01_FWPBW__ */
        }
        break;

        case SRV_UCM_ALERT_IND:
        {
            alert_ind = (srv_ucm_alert_ind_struct*)ind->ptr;
            g_ucm_p->call_misc.get_alert_ind = MMI_TRUE;
            mmi_ucm_alert_ind(alert_ind);
        }
        break;

        case SRV_UCM_NOTIFY_IND:
        {
            notify_ind = (srv_ucm_notify_ind_struct*)ind->ptr;
            mmi_ucm_notify_ind(notify_ind);
        }
        break;

        case SRV_UCM_CONNECT_IND:
        {
            connect_ind = (srv_ucm_connect_ind_struct*)ind->ptr;
        #if defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__)
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_CONNECT_EVENT);
        #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__) */
            mmi_ucm_set_no_counter_status(connect_ind->no_counter);
            mmi_ucm_connect_ind(connect_ind);
        }
        break;

        case SRV_UCM_DISCONNECTING_IND:
        {
            disconnecting_ind = (srv_ucm_disconnecting_ind_struct*)ind->ptr;
            mmi_ucm_handle_disconnecting_ind(disconnecting_ind);
        }
        break;

        case SRV_UCM_RELEASE_IND:
        {
            release_ind = (srv_ucm_release_ind_struct*) ind->ptr;
        #if defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__)
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_RELEASE_EVENT);
        #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__) */
            mmi_ucm_release_ind(release_ind);
        }
        break;

#ifdef __AOC_SUPPORT__

        case SRV_UCM_CALL_COST_IND:
        {
            call_cost_ind = (srv_ucm_call_cost_ind_struct*)ind->ptr;
            mmi_ucm_call_cost_ind(call_cost_ind);
        }
        break;
#endif

#ifdef __MMI_CALLSET_AUTO_REDIAL__

        case SRV_UCM_AUTO_REDIAL_IND:
        {
            auto_redial_ind = (srv_ucm_auto_redial_ind_struct*) ind->ptr;
            mmi_ucm_auto_redial_ind(auto_redial_ind);
        }
        break;

        case SRV_UCM_AUTO_REDIAL_CANCEL_IND:
        {
            mmi_ucm_auto_redial_cancel_ind();
        }
        break;

#endif		

    #ifdef __MMI_VOIP__
        case SRV_UCM_START_PROCESSING_IND:
        {
            start_processing_ind = (srv_ucm_start_processing_ind_struct*) ind->ptr;
            mmi_ucm_start_processing_ind(start_processing_ind);
        }
        break;

        case SRV_UCM_STOP_PROCESSING_IND:
        {
            stop_processing_ind = (srv_ucm_stop_processing_ind_struct*) ind->ptr;
            mmi_ucm_stop_processing_ind(stop_processing_ind);
        }
        break;
    #endif /* __MMI_VOIP__ */

        case SRV_UCM_QUERY_CANCEL_IND:
        {
            mmi_ucm_query_cancel_ind();
        }
        break;

        case SRV_UCM_REFRESH_IND:
        {
            mmi_ucm_refresh_ind();
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
        
    }
    return MMI_RET_OK; 	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conf_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the confirm indication sent from ucm srv
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_conf_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_cnf_ind_evt_struct *cnf_ind;
    srv_ucm_query_cnf_ind_struct *conf_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cnf_ind = (srv_ucm_cnf_ind_evt_struct *) para;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CONF_IND_HDLR_P1, cnf_ind->op_code);

    switch (cnf_ind->op_code)
    {
        case SRV_UCM_QUERY_CNF_IND:
        {
            conf_ind = (srv_ucm_query_cnf_ind_struct*) cnf_ind->ptr;
            g_ucm_p->cnf_scr.conf_ind_cb = cnf_ind->cnf_callback;
            
            mmi_ucm_query_cnf_ind(conf_ind);
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_post_event_hdlr
 * DESCRIPTION
 *  This function is to handle the post event (EVT_ID_UCM_DISCONNECTING)sent from ucm app itself
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_post_event_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_POST_EVEMT_HDLR);

#ifdef __OP01_FWPBW__
    if (EVT_ID_UCM_FWPCP_LAUCH_DIALER == para->evt_id)
    {
        mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_LAUCH_DIALER_EVENT);
    }
    else
#endif /* __OP01_FWPBW__ */
    {
        /*mmi_evt_mmi_ucm_disconnecting_call_exist_struct* disc_evt = (mmi_evt_mmi_ucm_disconnecting_call_exist_struct*) param;*/
        mmi_ucm_entry_disconnecting_screen(); /*the currect active screen must be incall screen, so no need check again*/
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_speech_status_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the speech indication EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND sent from mdi
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_speech_status_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct* event = (mmi_evt_mdi_audio_speech_ind_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

    switch (event->status)
    {
        case MDI_AUDIO_SPH_PRE_SPEECH_ON:
        case MDI_AUDIO_SPH_PRE_VOIP_ENCODE_START:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PRE_SPEECH_ON_CB_P1, g_ucm_p->call_misc.play_tone);
            /* If speech-on comes while incoming tone is playing, stop incoming tone before turning on speech */
            if (g_ucm_p->call_misc.play_tone != MMI_UCM_NONE)
            {
                mmi_ucm_stop_incoming_tone();
                g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
            }

            mmi_ucm_stop_inband_tone();
        }
        break;
//#ifndef __SLIM_UCM__
        case MDI_AUDIO_SPH_POST_SPEECH_ON:
        case MDI_AUDIO_SPH_POST_VOIP_ENCODE_START:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_POST_SPEECH_ON_CB);
        #ifdef __MMI_BG_SOUND_EFFECT__
        #ifdef __DM_LAWMO_SUPPORT__
        	if (!srv_dm_lawmo_is_locked())
        #endif /* __DM_LAWMO_SUPPORT__ */
            {
                if (srv_ucm_is_emergency_call() == MMI_FALSE)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SPEECH_IND_BGS_START);
                    mmi_bgsnd_common_mtmo_play_sound();
                }
                else
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SPEECH_IND_BGS_STOP);
                    mmi_bgsnd_util_stop_play_sound();
                }
            }
        #endif /* __MMI_BG_SOUND_EFFECT__ */
        }
        break;

	  case MDI_AUDIO_SPH_PRE_SPEECH_OFF:
	  case MDI_AUDIO_SPH_PRE_VOIP_ENCODE_STOP:
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PRE_SPEECH_OFF_CB);
        #ifdef __MMI_BG_SOUND_EFFECT__
            /* [UCM3.0] maybe bgsnd should have pretection mechanism or provid api for ucm app to query status*/
            mmi_bgsnd_util_stop_play_sound();
        #endif /* __MMI_BG_SOUND_EFFECT__ */
        break;


     
        default:
        {
            /* do nothing */
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_headset_key_hdlr
 * DESCRIPTION
 *  This function is to handle the headset key (GPIO_EXT_DEV_KEY_1) sent from GPIO
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_headset_key_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_ucm_headset_key();
        return MMI_RET_ERR;
    }          
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_bt_set_audio_path_hdlr
 * DESCRIPTION
 *  This function is to handle the bt audio switch
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incall_bt_set_audio_path_hdlr(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id scrn_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_UCM_IN_CALL == scrn_id ||
        SCR_ID_UCM_OUTGOING == scrn_id)
    {
        mmi_ucm_refresh_ind();
    }
}


#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_BACKGROUND_CALL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_if_ucm_exit_callback
 * DESCRIPTION
 *  This function is the callback function registered with the UCM service
 *  to be called when the UCM is deleing all the screen in case of outgoing
 *  call
 * PARAMETERS
 *  
 * RETURNS
 *  pBOOL 
 *****************************************************************************/
mmi_ret mmi_ucm_if_ucm_exit_callback(mmi_event_struct* para)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_TRUE == mmi_ucm_vt_get_is_switch_action())
	{
        return SRV_UCM_APP_EXIT_QUERY_RESULT_NO;
	}
	else
	{
        return SRV_UCM_APP_EXIT_QUERY_RESULT_YES;
	}
}
#endif /* __MMI_VIDEO_TELEPHONY__&& __MMI_BACKGROUND_CALL__*/


#ifdef __PXS_APP_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pxs_detect_obj_close_hdlr
 * DESCRIPTION
 *  This function is to handle the event EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_pxs_detect_obj_close_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PXS_HDLR_P1, evt->evt_id);

    if (MMI_TRUE == mmi_ucm_pxs_need_to_process())
    {
        srv_backlight_turn_off_ext();
        g_ucm_p->pxs_need_handle = MMI_TRUE;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pxs_detect_obj_away_hdlr
 * DESCRIPTION
 *  This function is to handle the event EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_pxs_detect_obj_away_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PXS_HDLR_P1, evt->evt_id);

    g_ucm_p->pxs_need_handle = MMI_FALSE;

    if (MMI_TRUE == mmi_ucm_pxs_need_to_process())
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pxs_key_proc
 * DESCRIPTION
 *  This function is to handle the event EVT_ID_PRE_KEY_EVT_ROUTING to restart PXS
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK to continue key routing, MMI_RET_STOP_KEY_HANDLE to stop
 *  key routing
 *****************************************************************************/
mmi_ret mmi_ucm_pxs_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
        MMI_FALSE == srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) &&
        MMI_TRUE == g_ucm_p->pxs_turn_on)
    {
        srv_sensor_pxs_turn_off();
        srv_sensor_pxs_turn_on();
    }
    return MMI_RET_OK;
}
#endif /* __PXS_APP_ENABLE__ */


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transmitter_status_hdlr
 * DESCRIPTION
 *  This function is to handle the transmitter status sent from GPIO
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_transmitter_status_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_fwp_call_process_event_enum event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_GPIO_TRANSMITTER_HOLD_ON == evt->evt_id)
    {
        event = MMI_UCM_FWPCP_TRANSMITTER_HOLDON_EVENT;
    }
    else if(EVT_ID_GPIO_TRANSMITTER_PUT_DOWN == evt->evt_id)
    {
        event = MMI_UCM_FWPCP_TRANSMITTER_PUTDOWN_EVENT;
    }
    else
    {
        return MMI_RET_DONT_CARE;
    }
    mmi_ucm_fwp_call_process_event_hdlr(event);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handfree_key_hdlr
 * DESCRIPTION
 *  handfree key handle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK to continue key routing, MMI_RET_STOP_KEY_HANDLE to stop
 *  key routing
 *****************************************************************************/
mmi_ret mmi_ucm_handfree_key_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);

    if (KEY_F9 == key_evt->key_code && KEY_EVENT_DOWN == key_evt->key_type)
    {
        mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_HANDFREE_KEY_EVENT);
    }
    return MMI_RET_OK;
}
#endif /* __OP01_FWPBW__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sim_availability_changed_hdlr
 * DESCRIPTION
 *  SIM availability handler
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_sim_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *sim_evt = (srv_sim_ctrl_availability_changed_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SIM_AVAILABILITY_CHANGED_HDLR);
    if (sim_evt->is_available_before == sim_evt->is_available_now)
    {
        return MMI_RET_OK;
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (!sim_evt->is_available_now && (!mmi_ucm_vt_check_nw_usable()))
    {
        /* If the preview screen should be closed, means no SIM can make video call.
           So no need to store the preview status and when close the VT group, the status
           will be set to NONE */
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
        {
            mmi_frm_group_close(GRP_ID_UCM_VT);
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!sim_evt->is_available_now)
    {
        if (mmi_frm_scrn_is_present(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_DIAL_CALL_TYPE_MENU, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        }
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    return MMI_RET_OK;
}


#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_callback
 * DESCRIPTION
 *  Motion callback function
 * PARAMETERS
 *  sensor_type     [IN] Sensor type
 *  sensor_data     [IN] Sensor data
 *  user_data       [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_motion_callback(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_turnover_struct *turnover_data;
    srv_sensor_motion_double_tap_struct *double_tap_data;
    MMI_ID active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MOTION_CALLBACK_P1, sensor_type);
    switch(sensor_type)
    {
        case SRV_SENSOR_MOTION_TURNOVER:
            turnover_data = (srv_sensor_motion_turnover_struct *)sensor_data;
            if (SRV_SENSOR_MOTION_TURNOVER_DOWN == turnover_data->direction &&
                srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
                (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) ==
                 srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL)) &&
                MMI_FALSE == g_ucm_p->call_misc.is_ringtone_suppress)
            {
                if (SCR_ID_UCM_INCOMING == active_screen)
                {
                #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__)
                    mmi_ucm_FTE_suppress_incoming_tone_hdlr();
                    mmi_ucm_set_key_after_suppress_ring();
                #else /* defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) */
                    mmi_ucm_suppress_incoming_tone();
                    mmi_ucm_set_key_after_suppress_ring();
                #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) */
                }
                else
                {
                    mmi_ucm_suppress_incoming_tone();
                }
            }
            break;

    #if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
        case SRV_SENSOR_MOTION_DOUBLE_TAP:
            double_tap_data = (srv_sensor_motion_double_tap_struct *)sensor_data;
            if (SRV_SENSOR_MOTION_TAP_DONE == double_tap_data->double_tap_direct &&
                SRV_UCM_RESULT_OK == mmi_ucm_query_sndrec_permit() &&
                MMI_TRUE == mmi_ucm_is_sndrec_handle_screen(active_screen))
            {
                mmi_ucm_sndrec_for_motion();
            }
            break;
    #endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_setting_change_hdlr
 * DESCRIPTION
 *  Motion setting change handler
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_motion_setting_change_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_SRV_FLIP_TO_MUTE_CALL == evt->evt_id)
    {
        if (srv_callset_flip_to_mute_call_get_mode())
        {
            mmi_ucm_motion_turnover_reg();
        }
        else
        {
            mmi_ucm_motion_turnover_dereg();
        }
    }
#if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
    else if (EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL == evt->evt_id)
    {
        if (srv_callset_tap_tap_to_record_in_call_get_mode())
        {
            mmi_ucm_motion_double_tap_reg();
        }
        else
        {
            mmi_ucm_motion_double_tap_dereg();
        }
    }
#endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
    return MMI_RET_OK;
}
#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_backlight_turn_off_query_hdlr
 * DESCRIPTION
 *  This function is used to process EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN
 *  This event is used to query all APP whether GPIO can turn off backlight
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK means it is allowed to turn off backlight;
 *  otherwise means not allowed.
 *****************************************************************************/
mmi_ret mmi_ucm_backlight_turn_off_query_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_scr_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN == evt->evt_id)
    {
        if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
        {
        #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BACKLIGHT_TURN_OFF_QUERY_HDLR_P3, g_ucm_p->call_misc.is_power_key_lcok, curr_scr_id, 1);
	    #else /* __MMI_SCREEN_LOCK_ANY_TIME__ */
			MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BACKLIGHT_TURN_OFF_QUERY_HDLR_P3, 0, curr_scr_id, 1);
		#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
			if (SCR_ID_UCM_INCOMING == curr_scr_id &&
			#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
                !g_ucm_p->call_misc.is_power_key_lcok &&
            #endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
                MMI_TRUE)
            {
                return MMI_RET_ERR;
            }
        }
	#ifdef __MMI_VIDEO_TELEPHONY__
        else if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE, MMI_FALSE, NULL) > 0)
        {
		#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
			MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BACKLIGHT_TURN_OFF_QUERY_HDLR_P3, g_ucm_p->call_misc.is_power_key_lcok, curr_scr_id, 2);
		#else /* __MMI_SCREEN_LOCK_ANY_TIME__ */
			MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BACKLIGHT_TURN_OFF_QUERY_HDLR_P3, 0, curr_scr_id, 2);
		#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
            if (SCR_ID_UCM_VT_INCALL == curr_scr_id &&
			#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
                !g_ucm_p->call_misc.is_power_key_lcok &&
            #endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
                MMI_TRUE)
            {
                return MMI_RET_ERR;
            }
        }
	#endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    return MMI_RET_OK;
}


#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_process_screen_lock
 * DESCRIPTION
 *  This function is used to process EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING
 *  This event is emitted before launch screen lock.
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK means it is allowed to lock screen by common lock;
 *  otherwise means not allowed.
 *****************************************************************************/
mmi_ret mmi_ucm_process_screen_lock(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_locker_pre_lock_evt_struct *lock_evt = (mmi_scr_locker_pre_lock_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING == evt->evt_id)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PROCESS_SCREEN_LOCK_P1, lock_evt->lock_mode);
        switch (lock_evt->lock_mode)
        {
            case MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK:
                g_ucm_p->call_misc.is_power_key_lcok = MMI_FALSE;
                return mmi_ucm_screen_lock_auto_lock_hdlr();

            case MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY:
                g_ucm_p->call_misc.is_power_key_lcok = MMI_TRUE;
                return mmi_ucm_screen_lock_power_key_hdlr();

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_screen_lock_auto_lock_hdlr
 * DESCRIPTION
 *  This function is used to process auto common lock
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK means it is allowed to auto lock by common lock;
 *  otherwise means not allowed.
 *****************************************************************************/
mmi_ret mmi_ucm_screen_lock_auto_lock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    MMI_ID curr_scr_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_count((srv_ucm_call_state_enum)(SRV_UCM_INCOMING_STATE | SRV_UCM_OUTGOING_STATE), SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SCREEN_LOCK_AUTO_LOCK_HDLR_P3, curr_act_sg_id, curr_scr_id, 1);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__PXS_APP_ENABLE__)
    #ifndef __MMI_UCM_SLIM__
        if (g_ucm_p->cui_info.incoming_opt_cui_id == curr_act_sg_id ||
            g_ucm_p->cui_info.outgoing_opt_cui_id == curr_act_sg_id)
        {
            /* keep_backlight_off is used to prevent the backlight on when enter incomng or outgoing call screen. */
            g_ucm_p->call_misc.keep_backlight_off = MMI_TRUE;
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_close_cui(&curr_act_sg_id);
            /* Reuse is_power_key_lcok to let the backlight off in incoming call screen */
            g_ucm_p->call_misc.is_power_key_lcok = MMI_TRUE;
            g_ucm_p->call_misc.keep_backlight_off = MMI_FALSE;
        }
    #endif /* __MMI_UCM_SLIM__ */
    #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__PXS_APP_ENABLE__) */
        return MMI_RET_ERR;
    }
    else if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) > 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SCREEN_LOCK_AUTO_LOCK_HDLR_P3, curr_act_sg_id, curr_scr_id, 2);
    #ifdef __PXS_APP_ENABLE__
        if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0 ||
            SCR_ID_UCM_VT_INCALL == curr_scr_id ||
            mmi_ucm_is_lock_not_allowed_screen(curr_scr_id))
        {
            return MMI_RET_ERR;
        }
    #else /* __PXS_APP_ENABLE__ */
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        if (SCR_ID_UCM_IN_CALL == curr_scr_id ||
            SCR_ID_UCM_VT_INCALL == curr_scr_id ||
            mmi_ucm_is_lock_not_allowed_screen(curr_scr_id))
        {
            return MMI_RET_ERR;
        }
        else if (g_ucm_p->cui_info.incall_opt_cui_id == curr_act_sg_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_close_cui(&curr_act_sg_id);
            return MMI_RET_ERR;
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        else if (g_ucm_p->vt_cntx.switch_confirm_scrn == curr_scr_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_alert_dismiss(curr_scr_id);
            return MMI_RET_ERR;
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    #else /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
        return MMI_RET_ERR;
    #endif /*defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    #endif /* __PXS_APP_ENABLE__ */
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_screen_lock_power_key_hdlr
 * DESCRIPTION
 *  This function is used to process power key lock
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK means it is allowed to power key lock by common lock;
 *  otherwise means not allowed.
 *****************************************************************************/
mmi_ret mmi_ucm_screen_lock_power_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    MMI_ID curr_scr_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_count((srv_ucm_call_state_enum)(SRV_UCM_INCOMING_STATE | SRV_UCM_OUTGOING_STATE), SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SCREEN_LOCK_POWER_KEY_HDLR_P3, curr_act_sg_id, curr_scr_id, 1);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__PXS_APP_ENABLE__)
        if (SCR_ID_UCM_INCOMING == curr_scr_id ||
            SCR_ID_UCM_OUTGOING == curr_scr_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_refresh_ind();
        }
    #ifndef __MMI_UCM_SLIM__
        else if (g_ucm_p->cui_info.incoming_opt_cui_id == curr_act_sg_id ||
                 g_ucm_p->cui_info.outgoing_opt_cui_id == curr_act_sg_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_close_cui(&curr_act_sg_id);
        }
    #endif /* __MMI_UCM_SLIM__ */
    #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__PXS_APP_ENABLE__) */
        return MMI_RET_ERR;
    }
    else if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) > 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SCREEN_LOCK_POWER_KEY_HDLR_P3, curr_act_sg_id, curr_scr_id, 2);
    #ifdef __PXS_APP_ENABLE__
        if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0 ||
            mmi_ucm_is_lock_not_allowed_screen(curr_scr_id))
        {
            return MMI_RET_ERR;
        }
    #else /* __PXS_APP_ENABLE__ */
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        if (SCR_ID_UCM_IN_CALL == curr_scr_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_refresh_ind();
            return MMI_RET_ERR;
        }
        else if (g_ucm_p->cui_info.incall_opt_cui_id == curr_act_sg_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_ucm_close_cui(&curr_act_sg_id);
            return MMI_RET_ERR;
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        else if (g_ucm_p->vt_cntx.switch_confirm_scrn == curr_scr_id)
        {
            mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_FORCE_LOCK_EVENT);
            mmi_alert_dismiss(curr_scr_id);
            return MMI_RET_ERR;
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        else if (mmi_ucm_is_lock_not_allowed_screen(curr_scr_id))
        {
            return MMI_RET_ERR;
        }
    #else /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
        return MMI_RET_ERR;
    #endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    #endif /* __PXS_APP_ENABLE__ */
    }
    return MMI_RET_OK;
}
#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */


#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mode_switch_hdlr
 * DESCRIPTION
 *  handler for mode switch indication
 * PARAMETERS
 *  evt    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_mode_switch_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY == evt->evt_id)
    {
        if (SRV_MODE_SWITCH_ON == mode_status->select_flight_mode)
        {
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
            {
                if (mmi_frm_group_is_present(GRP_ID_UCM_VT))
                {
                    mmi_frm_group_close(GRP_ID_UCM_VT);
                }
            }
        }
    }
    return MMI_RET_OK;
}
#endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__) */


#if defined(__MMI_NCENTER_SUPPORT__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ncenter_drag_hdlr
 * DESCRIPTION
 *  handler for ncenter drag
 * PARAMETERS
 *  evt    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_ncenter_drag_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_VAPP_NCENTER_DRAG);

    if (srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) ||
		srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL) 
  
		#if defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__PXS_APP_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
			|| (MMI_UCM_LOCK_STATE == mmi_ucm_get_auto_lock_state()))
        #else
		)
        #endif
    {
        return MMI_RET_ERR;
    }
    return MMI_RET_OK;
}
#endif /* defined(__MMI_NCENTER_SUPPORT__) */


#endif /* __MMI_UCM__ */

