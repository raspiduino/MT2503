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
 *  UcmKernelBT.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_CALL_SUPPORT__
#include "mdi_audio.h"
#include "mmi_rp_app_ucmbt_def.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_app_ucm_def.h"
#endif /* __MMI_TELEPHONY_SUPPORT__ */

#include "BtcmSrvGprot.h"
#include "BTDialerSrvGprot.h"

#include "UcmGProtBT.h"
#include "UcmProtBT.h"

#include "GlobalResDef.h" // STR_GLOBAL_ERROR
#include "Resource_audio.h" // TONE_CALL_WAITING
#include "GpioSrvGprot.h" // srv_vibrator_on
#include "UcmSrvGprot.h"
#include "BthScoPathSrvGProt.h"
#ifdef __MMI_UCM_BT_CALL_RECORDER__
#include "USBsrvGprot.h"
#endif /* __MMI_UCM_BT_CALL_RECORDER__ */
#include "UcmBTSrvGprot.h"
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif
#include "VolumeHandler.h" /* For SetDefaultVolumeKeyHandlers */

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
#include "mmi_frm_input_event.h"
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */


#ifdef __MMI_UCM_BT_CALL_RECORDER__
MYTIME g_ucm_bt_start_record_time;//Maintain time duration of the record call
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_error_cnf_hdlr_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void          [IN] 
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_ucm_error_cnf_hdlr_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ERR_HDLR);
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_FAIL);
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */
    mmi_popup_display_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, NULL);
    mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_UNSPECIFIED_ERROR);
    mmi_ucm_stop_incoming_ringtone_bt();
    mmi_ucm_delete_all_screen_bt();
    mmi_ucm_clean_all_bt();
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_notify_hdlr_bt
 * DESCRIPTION
 *  To handle events send from BT dialler
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_act_notify_hdlr_bt(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_act_notify_evt_struct* act_notify;
    srv_ucm_bt_act_rsp_struct* rsp;
    srv_ucm_bt_ata_act_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_notify = (srv_ucm_bt_act_notify_evt_struct *) para;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ACT_NOFITY, act_notify->act_op, act_notify->notify_type);

    /* 1. START */
    if (SRV_UCM_BT_ACT_NOTIFY_START == act_notify->notify_type)
    {
        switch (act_notify->act_op)
        {
            case SRV_UCM_BT_ACCEPT_ACT:
                req = (srv_ucm_bt_ata_act_req_struct*)act_notify->ptr;
                g_ucm_p_bt->hilite_call_id = req->call_id;
                break;

            default:
                break;
        }
    }
    /* 2. END */
    else
    {
        switch (act_notify->act_op)
        {
            case SRV_UCM_BT_DIAL_ACT:

                rsp = (srv_ucm_bt_act_rsp_struct*)act_notify->ptr;
                if (SRV_UCM_BT_RESULT_OK != rsp->result)
                {
                    mmi_ucm_error_cnf_hdlr_bt();
                }
                else
                {
                    mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_OK);
                }
                break;

            case SRV_UCM_BT_ACCEPT_ACT:
            case SRV_UCM_BT_HOLD_ACT:
            case SRV_UCM_BT_RETRIEVE_ACT:
            case SRV_UCM_BT_SWAP_ACT:
            case SRV_UCM_BT_END_SINGLE_ACT:
            case SRV_UCM_BT_END_ALL_ACT:
                rsp = (srv_ucm_bt_act_rsp_struct*)act_notify->ptr;
                if (SRV_UCM_BT_RESULT_OK != rsp->result)
                {
                    mmi_ucm_error_cnf_hdlr_bt();
                }
                break;

            default:
                break;
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
static srv_prof_ret mmi_ucm_ker_btb_notify_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BTB_NOTIFY_CB, result);

//resume play ringtone from sco link
	mdi_audio_bt_hfp_turn_on();

    if (result != MDI_AUDIO_TERMINATED)
        mdi_audio_resume_background_play();    
    
    return 0;    
}

void mmi_ucm_btb_play_incoming_ringtone_bt(void)
{
	S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
	srv_ucm_bt_call_info_struct call_info;

#if 1	
//#ifdef DIGIT_TONE_SUPPORT	
	if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, call_list) > 0)
	{
		if (srv_ucm_bt_query_call_data(call_list[0], &call_info))
		{
			mdi_audio_suspend_background_play();
//////stop play ringtone from sco link channel, and play incoming call number
//////when play complete, resume play ringtone from sco link
			mdi_audio_bt_hfp_turn_off();
			
			mdi_audio_play_text_with_vol_path(
				(U8*)call_info.dis_name,
				mmi_ucs2strlen((S8*)call_info.dis_name),
				100, 
				mmi_ucm_ker_btb_notify_callback, 
				NULL, 
				MDI_AUD_VOL_EX(12),
				MDI_DEVICE_SPEAKER_BOTH);  
		}
	}
#else /* DIGIT_TONE_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* DIGIT_TONE_SUPPORT */

}

#endif/*#ifdef __MMI_UCM_BT_BTBOX_NOLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ind_hdlr_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct          [IN]          
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_ind_hdlr_bt(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_ind_evt_struct* ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ind = (srv_ucm_bt_ind_evt_struct *) para;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_IND_NOFITY, ind->ind_type);

    switch (ind->ind_type)
    {
        case SRV_UCM_BT_INCOMING_CALL_IND:
        {
            srv_ucm_bt_incoming_call_ind_struct* incoming = (srv_ucm_bt_incoming_call_ind_struct*)ind->ptr;
            if (!mmi_ucm_is_dev_allow_bt(incoming->srv_hd))
            {
                mmi_ucm_another_device_notify_bt(SRV_UCM_BT_INCOMING_CALL_IND, incoming->srv_hd);
                break;
            }
            else if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
            {
                mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
            }

            if (IsMyTimerExist(UCM_MO_PROCESSING_TIMER_BT))
            {
                g_ucm_p_bt->refresh_srv = 0;
                StopTimer(UCM_MO_PROCESSING_TIMER_BT);
            }
            mmi_ucm_set_hilite_call_info_bt(incoming->call_id);
            mmi_ucm_set_hilite_dev_info_bt(incoming->srv_hd);
            mmi_ucm_enter_incoming_call_bt();
        }
        break;

        case SRV_UCM_BT_OUTGOING_CALL_IND:
        {
            srv_ucm_bt_outgoing_call_ind_struct* outgoing = (srv_ucm_bt_outgoing_call_ind_struct*)ind->ptr;
            if (!mmi_ucm_is_dev_allow_bt(outgoing->srv_hd))
            {
                break;
            }
            else if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
            {
                mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
            }

            if (IsMyTimerExist(UCM_MO_PROCESSING_TIMER_BT))
            {
                g_ucm_p_bt->refresh_srv = 0;
                StopTimer(UCM_MO_PROCESSING_TIMER_BT);
            }
            mmi_ucm_set_hilite_call_info_bt(outgoing->call_id);
            mmi_ucm_set_hilite_dev_info_bt(outgoing->srv_hd);
            mmi_ucm_enter_outgoing_call_bt();
        }
        break;

        case SRV_UCM_BT_RING_IND:
        {
            #ifndef __MMI_UCM_BT_BTBOX_NOLCD__			
            mmi_ucm_play_incoming_ringtone_bt();
			#else			
			mmi_ucm_btb_play_incoming_ringtone_bt();
			#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
        }
        break;

        case SRV_UCM_BT_RELEASE_IND:
        {
            srv_ucm_bt_release_call_ind_struct* release = (srv_ucm_bt_release_call_ind_struct*)ind->ptr;
            if (!mmi_ucm_is_dev_allow_bt(release->srv_hd))
            {
                mmi_ucm_another_device_notify_bt(SRV_UCM_BT_RELEASE_IND, release->srv_hd);
                break;
            }
            else if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
            {
                mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
            }
            if (IsMyTimerExist(UCM_FORCE_REFRESH_TIMER_BT))
            {
                StopTimer(UCM_FORCE_REFRESH_TIMER_BT);
            }
            mmi_ucm_release_ind_bt(ind->ptr);
        }
        break;

        case SRV_UCM_BT_REFRESH_IND:
        {
            srv_ucm_bt_refresh_call_ind_struct* refresh = (srv_ucm_bt_refresh_call_ind_struct*)ind->ptr;
            if (!mmi_ucm_is_dev_allow_bt(refresh->srv_hd))
            {
                mmi_ucm_another_device_notify_bt(SRV_UCM_BT_REFRESH_IND, refresh->srv_hd);
                break;
            }
            else if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
            {
                mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
            }
            if (IsMyTimerExist(UCM_FORCE_REFRESH_TIMER_BT))
            {
                StopTimer(UCM_FORCE_REFRESH_TIMER_BT);
            }
            mmi_ucm_set_hilite_dev_info_bt(refresh->srv_hd);
            g_ucm_p_bt->disconnecting = 0;
            mmi_ucm_refresh_ind_bt(refresh->srv_hd);
        }
        break;

    #ifdef __BT_SPK_VOL_CONTROL__
        case SRV_UCM_BT_VGS_SYNC_IND:
        {
            srv_ucm_bt_vgs_ind_struct* vgs = (srv_ucm_bt_vgs_ind_struct*)ind->ptr;
            if (!mmi_ucm_is_dev_allow_bt(vgs->srv_hd))
            {
                mmi_ucm_another_device_notify_bt(SRV_UCM_BT_VGS_SYNC_IND, vgs->srv_hd);
                break;
            }
            else if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
            {
                mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
            }

            mmi_ucm_speaker_vol_ind_bt(vgs->gain);
        #ifndef __MMI_UCM_BT_BTBOX_NOLCD__
            SetDefaultVolumeKeyHandlers();
            EntryScrSetKeyPadVolumeLevel();
        #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
        }
        break;
    #endif

        case SRV_UCM_BT_RESET_CALL_LIST_IND:
        {
            mmi_ucm_error_cnf_hdlr_bt();
        }
        break;

        case SRV_UCM_BT_HF_INIT_IND:
        {
            mmi_ucm_init_bt();
        }
        break;

        case SRV_UCM_BT_HF_DEINIT_IND:
        {
            mmi_ucm_deint_bt();
        }
        break;

        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_btdialer_and_accept_option_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void          [IN]          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_btdialer_and_accept_option_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL];
    srv_ucm_call_info_struct* call_info;

    /*----------------------------------------------------------------*/
    /* Code	                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0
        && g_ucm_p_bt->is_need_accept)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ACT_END_AND_ACCEPT,0);
        g_ucm_p_bt->is_need_accept = MMI_FALSE;
        call_info = OslMalloc(sizeof(srv_ucm_call_info_struct));
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, index_list) != 1)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ACT_END_AND_ACCEPT, 1);
            OslMfree(call_info);
            return;
        }
    
        if (srv_ucm_query_call_data(index_list[0], call_info))
        {
            memcpy(&check_act_req.action_uid, &call_info->uid_info, sizeof(srv_ucm_id_info_struct));
            if (SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, &check_act_req))
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ACT_END_AND_ACCEPT, 2);
                srv_ucm_act_request(SRV_UCM_ACCEPT_ACT, &check_act_req, NULL, NULL);
            }
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_ACT_END_AND_ACCEPT, 3);
        }
        OslMfree(call_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_endkey_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_endkey_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BTD_BOX_UI_STYLE__
    U16 rsk = (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_BT_HAND_HELD) : (STR_ID_UCM_BT_HAND_FREE);
#endif
    DisableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
#ifdef __MMI_BTD_BOX_UI_STYLE__
    DisableRightSoftkey(STR_ID_UCM_BT_END_CALL, 0);
#else
    DisableRightSoftkey(rsk, 0);
#endif /* __MMI_BTD_BOX_UI_STYLE__  */
    mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    mmi_ucm_end_single_action_bt();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_ringtone_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_play_ringtone_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_play_req_struct play_req;

    /*----------------------------------------------------------------*/
    /* Code                                         */
    /*----------------------------------------------------------------*/
    // just for BQB TP/ICA/BV-05-I
    if (srv_bt_cm_get_bqb_test_flag() && srv_bt_dialer_get_bqb_bsir_enable() == 1)
    {
        if (srv_btsco_is_sco_open())
        {
            mdi_audio_bt_hfp_turn_off();
        }
    }

    srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_INCOMING_CALL);

    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&play_req.volume);
    play_req.aud_path = MDI_DEVICE_LOUDSPEAKER;
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_TYPE, &play_req.play_style);
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_TONE, &play_req.audio_id);
    play_req.callback = NULL;
    play_req.audio_type = SRV_PROF_AUDIO_STRING;
    srv_prof_play_tone_with_full_struct(&play_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_ringtone_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_play_tone_after_vibration_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_TONE_AFTER_VIBRATION_BT);
    srv_vibrator_off(); /* O */
    mmi_ucm_play_ringtone_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_incoming_ringtone_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_incoming_ringtone_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_alert_type_enum alert_type = SRV_PROF_ALERT_TYPE_INVALID;

    /*----------------------------------------------------------------*/
    /* Code                                         */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_RING_TONE);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
        || srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
    {
        mmi_ucm_play_waitingtone_bt();
    }
    else if (!srv_btsco_is_sco_open())
    {
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, &alert_type);
        switch(alert_type)
        {
            case SRV_PROF_ALERT_TYPE_RING:
            {
                g_ucm_p_bt->tone_type = MMI_UCM_BT_RING_TONE;
                mmi_ucm_play_ringtone_bt();
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            {
                g_ucm_p_bt->tone_type = MMI_UCM_BT_RING_TONE;
                srv_vibrator_on();
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            {
                g_ucm_p_bt->tone_type = MMI_UCM_BT_RING_TONE;
                srv_vibrator_on();
                mmi_ucm_play_ringtone_bt();
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            {
                g_ucm_p_bt->tone_type = MMI_UCM_BT_RING_TONE;
                srv_vibrator_on();
                StartTimer(UCM_TONE_AFTER_VIBRATION_BT, MMI_UCM_VIB_THEN_RING_DURATION, mmi_ucm_play_tone_after_vibration_bt);
            }
            break;
            case SRV_PROF_ALERT_TYPE_SILENT:
            {
            }
            break;
            default:                
            break;
        }
    }
#ifdef __MMI_UCM_BT_IN_BAND_RING_TONE_OUT__
    else if (srv_btsco_is_sco_open() && (srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev)
           && srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev,  SRV_UCM_BT_INCOMING_STATE, NULL)
           == srv_ucm_bt_query_call_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_ALL, NULL))
           && mdi_audio_get_audio_mode() != AUD_MODE_LOUDSPK)
    {
        g_ucm_p_bt->tone_type = MMI_UCM_BT_INBAND_RING_TONE;
        srv_speech_enable_hand_free();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_waitingtone_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_waitingtone_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ring_type_enum ring_type = SRV_PROF_RING_TYPE_ONCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_TYPE, &ring_type);

    g_ucm_p_bt->tone_type = MMI_UCM_BT_WAITING_TONE;

    srv_prof_play_tone_with_id(
            SRV_PROF_TONE_WAITING_CALL,
            TONE_CALL_WAITING,
            ring_type,
            NULL);
}


void mmi_ucm_stop_waitingtone_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_WAITING_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_incoming_ringtone_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_incoming_ringtone_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_alert_type_enum alert_type = SRV_PROF_ALERT_TYPE_INVALID;

    /*----------------------------------------------------------------*/
    /* Code                                         */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_STOP_RING_TONE, g_ucm_p_bt->tone_type);

    if (g_ucm_p_bt->tone_type == MMI_UCM_BT_WAITING_TONE)
    {
        g_ucm_p_bt->tone_type = MMI_UCM_BT_NONE_TONE;
        mmi_ucm_stop_waitingtone_bt();
    }
    else if (g_ucm_p_bt->tone_type == MMI_UCM_BT_RING_TONE)
    {
        g_ucm_p_bt->tone_type = MMI_UCM_BT_NONE_TONE;

        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, &alert_type);
    
        switch(alert_type)
        {
            case SRV_PROF_ALERT_TYPE_RING:
            {
                srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            {
                srv_vibrator_off();
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            {
                srv_vibrator_off();
                srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
            }
            break;
            case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            {
                srv_vibrator_off();
                StopTimer(UCM_TONE_AFTER_VIBRATION_BT);
                srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL); 
            }
            break;
            case SRV_PROF_ALERT_TYPE_SILENT:
            {
            }
            break;
            default:                
            break;
        }
    
        // just for BQB TP/ICA/BV-05-I
        if (srv_bt_cm_get_bqb_test_flag() && srv_bt_dialer_get_bqb_bsir_enable() == 1)
        {
            if (srv_btsco_is_sco_open())
            {
                mdi_audio_bt_hfp_turn_on();
                srv_bt_dialer_reset_bqb_bsir_enable();
            }
        }
    }
#ifdef __MMI_UCM_BT_IN_BAND_RING_TONE_OUT__
    else if (g_ucm_p_bt->tone_type == MMI_UCM_BT_INBAND_RING_TONE)
    {
        g_ucm_p_bt->tone_type = MMI_UCM_BT_NONE_TONE;
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clean_all_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_clean_all_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CLEAN_ALL);
    mmi_ucm_init_context_bt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_hide_state_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_hide_state_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables	                                              */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body	                                                  */
    /*----------------------------------------------------------------*/ 
    return g_ucm_p_bt->is_hide_screen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_hide_state_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_hide_state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_hide_state_bt(MMI_BOOL new_hide_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables	                                              */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body	                                                  */
    /*----------------------------------------------------------------*/ 
    g_ucm_p_bt->is_hide_screen = new_hide_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_headset_key_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ucm_headset_key_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables	                                              */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body	                                                  */
    /*----------------------------------------------------------------*/ 
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        mmi_ucm_incoming_call_sendkey_bt();
    }
    else if (srv_ucm_bt_query_call_count(SRV_UCM_BT_OUTGOING_STATE, NULL) > 0)
    {
        mmi_ucm_outgoing_call_endkey_bt();
    }
    else if (!srv_ucm_is_incoming_call() && !srv_ucm_is_outgoing_call() 
        && srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
    {
        mmi_ucm_end_single_action_bt();
    }
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_headset_key_hdlr_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_headset_key_hdlr_bt(mmi_event_struct* para)
{

    /*----------------------------------------------------------------*/
    /* Local Variables	                                              */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body	                                                  */
    /*----------------------------------------------------------------*/ 
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) > 0)
    {
        mmi_ucm_headset_key_bt();
        return MMI_RET_ERR;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_error_message_bt
 * DESCRIPTION
 *  Error message API for applications which operations are not allowed during in-call.
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_entry_error_message_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_FAIL);
#else /* __MMI_UCM_BT_BTBOX_NOLCD__ */
    mmi_popup_display_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, NULL);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_dial_cb_bt
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_exec_dial_cb_bt(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_EXEC_DIAL_CB, result);

    if (g_ucm_p_bt->callback != NULL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_INVOKE_CALLBACK, g_ucm_p_bt->callback, g_ucm_p_bt->callback_para);
        make_call_cb_para.result = result;
        make_call_cb_para.user_data = g_ucm_p_bt->callback_para;
        g_ucm_p_bt->callback(&make_call_cb_para);
        g_ucm_p_bt->callback = NULL; /* Make sure the callback is called once */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_action
 * DESCRIPTION
 *  execute swap action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_swap_action_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct swap_req;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SWAP_OPTION_BT);

    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, group_list) > 0)
    {
        srv_ucm_bt_query_call_data(group_list[0], &call_info);
        swap_req.act_hd = call_info.srv_hd;
        swap_req.active_id = call_info.call_id;

        if (srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, group_list) > 0)
        {
            srv_ucm_bt_query_call_data(group_list[0], &call_info);
            swap_req.hold_hd = call_info.srv_hd;
            swap_req.hold_id = call_info.call_id;

            if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_SWAP_ACT, &swap_req))
            {
                 srv_ucm_bt_act_request(SRV_UCM_BT_SWAP_ACT, &swap_req);
                 mmi_ucm_bt_enter_processing_screen(GRP_ID_UCM_BT_INCALL, call_info.srv_hd);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_action
 * DESCRIPTION
 *  execute hold single action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_action_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct hold_req;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_HOLD_OPTION_BT);

    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_ACTIVE_STATE, group_list) > 0)
    {
        srv_ucm_bt_query_call_data(group_list[0], &call_info);
        hold_req.act_hd = call_info.srv_hd;
        hold_req.active_id = call_info.call_id;

        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_HOLD_ACT, &hold_req))
        {
             srv_ucm_bt_act_request(SRV_UCM_BT_HOLD_ACT, &hold_req);
             mmi_ucm_bt_enter_processing_screen(GRP_ID_UCM_BT_INCALL, call_info.srv_hd);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_action
 * DESCRIPTION
 *  execute retrieve single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_retrieve_action_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct retrieve_req;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_RETRIEVE_OPTION_BT);

    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_HOLD_STATE, group_list) > 0)
    {
        srv_ucm_bt_query_call_data(group_list[0], &call_info);
        retrieve_req.hold_hd = call_info.srv_hd;
        retrieve_req.hold_id = call_info.call_id;

        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_RETRIEVE_ACT, &retrieve_req))
        {
            srv_ucm_bt_act_request(SRV_UCM_BT_RETRIEVE_ACT, &retrieve_req);
            mmi_ucm_bt_enter_processing_screen(GRP_ID_UCM_BT_INCALL, call_info.srv_hd);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_answer_action_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_answer_action_bt(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_ata_act_req_struct act_req;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SEND_ATA_REQ);

    if ((srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev)
     && srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_INCOMING_STATE, group_list) > 0)
     || srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE, group_list) > 0)
    {
        srv_ucm_bt_query_call_data(group_list[0], &call_info);
        act_req.srv_hd= call_info.srv_hd;
        act_req.call_id = call_info.call_id;

        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_ACCEPT_ACT, &act_req))
        {
            srv_ucm_bt_act_request(SRV_UCM_BT_ACCEPT_ACT, &act_req);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option
 * DESCRIPTION
 *  Check if dial action can be executed or not.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means dial action can be executed
 *****************************************************************************/
void mmi_ucm_dial_action_bt(srv_ucm_bt_atd_act_req_struct* act_req)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code	                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_DIAL_OPTION);

    if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_DIAL_ACT, act_req))
    {
        srv_ucm_bt_act_request(SRV_UCM_BT_DIAL_ACT, act_req);
        mmi_ucm_enter_dialling_bt();
    }
    else
    {
        mmi_ucm_entry_error_message_bt();
        mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
    }
}

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_redial_action_bt
 * DESCRIPTION
 *  Check if dial action can be executed or not.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means dial action can be executed
 *****************************************************************************/
void mmi_ucm_redial_action_bt(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dev_count;
    U32 idx;
    srv_bt_cm_bt_addr bd_addr;
    const srv_bt_cm_dev_struct* cm_dev_info;
    srv_ucm_bt_common_act_req_struct act_req;

    /*----------------------------------------------------------------*/
    /* Code	                                      */
    /*----------------------------------------------------------------*/
    dev_count = srv_bt_cm_get_linked_dev_list_idx();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_REDIAL_OPTION, dev_count);

    if(dev_count == 0)
    {
        mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_FAIL);
        return;
    }

    for (idx = 0; idx < dev_count; idx++)
    {
        cm_dev_info = srv_bt_cm_get_linked_dev_info(idx);
        if (cm_dev_info != NULL)
        {
            kal_prompt_trace(MOD_MMI, "mmi_ucm_redial_action_bt idx:%d", idx);
            break;
        }
    }

    bd_addr.lap = cm_dev_info->bd_addr.lap;
    bd_addr.nap = cm_dev_info->bd_addr.nap;
    bd_addr.uap = cm_dev_info->bd_addr.uap;

    act_req.srv_hd = srv_ucm_bt_query_service_hd(&bd_addr);

    if( act_req.srv_hd == -1 )
        return;

    if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_REDIAL_ACT, &act_req))
    {
        srv_ucm_bt_act_request(SRV_UCM_BT_REDIAL_ACT, &act_req);
    }
    else
    {
        mmi_ucm_entry_error_message_bt();
        mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
    }
}
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_action_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ucm_end_single_action_bt(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_info_struct call_info;
    srv_ucm_bt_end_single_act_req_struct act_req;
    /*----------------------------------------------------------------*/
    /* Code	                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_query_call_data(g_ucm_p_bt->hilite_call_id, &call_info))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_END_OPTION_BT, g_ucm_p_bt->hilite_call_id, call_info.call_state);
    
        act_req.srv_hd = call_info.srv_hd;
        act_req.call_id = call_info.call_id;
    
        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_END_SINGLE_ACT, &act_req))
        {
            srv_ucm_bt_act_request(SRV_UCM_BT_END_SINGLE_ACT, &act_req);
            g_ucm_p_bt->disconnecting = call_info.call_id;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_action_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ucm_end_all_action_bt(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_all_act_req_struct act_req;
    S32 group_list[SRV_UCM_BT_ALL_DEV_MAX_GROUP];
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_END_ALL);

    if (srv_ucm_bt_query_group_count_ext(g_ucm_p_bt->hilite_dev, SRV_UCM_BT_CALL_STATE_CONNECTED, group_list) > 0)
    {
        srv_ucm_bt_query_call_data(group_list[0], &call_info);
        act_req.srv_hd= call_info.srv_hd;

        if (SRV_UCM_BT_RESULT_OK == srv_ucm_bt_act_permit(SRV_UCM_BT_END_ALL_ACT, &act_req))
        {
            srv_ucm_bt_act_request(SRV_UCM_BT_END_ALL_ACT, &act_req);
            mmi_ucm_bt_enter_processing_screen(GRP_ID_UCM_BT_INCALL, call_info.srv_hd);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_switch_audio_action_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ucm_switch_audio_action_bt(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_switch_audio_act_req_struct act_req;
    srv_ucm_bt_call_info_struct call_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SWITCH_AUDIO);

    // act_req.srv_hd = call_info.srv_hd;
    srv_ucm_bt_query_call_data(g_ucm_p_bt->hilite_call_id, &call_info);
    act_req.srv_hd = call_info.srv_hd;

    srv_ucm_bt_act_request(SRV_UCM_BT_SWITCH_AUDIO_PATH, &act_req);
}

void mmi_ucm_force_refresh_action_bt(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_force_refresh_act_req_struct act_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_bt_is_valid_service_hd(srv_hd))
    {
        act_req.srv_hd = srv_hd;
        srv_ucm_bt_act_request(SRV_UCM_BT_FORCE_REFRESH_ACT, &act_req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_hilite_dev_info_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  service handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_hilite_dev_info_bt(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p_bt->hilite_dev = srv_hd;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_hilite_dev_info_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  service handle
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_dev_allow_bt(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p_bt->hilite_dev == srv_hd || g_ucm_p_bt->hilite_dev == 0 || !srv_ucm_bt_is_valid_service_hd(g_ucm_p_bt->hilite_dev))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
    kal_prompt_trace(MOD_MMI, "[UCMBT] mmi_ucm_is_dev_allow_bt, result:%d, hili:%d, cur:%d", result, g_ucm_p_bt->hilite_dev, srv_hd);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_hilite_call_info_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  service handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_hilite_call_info_bt(U8 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p_bt->hilite_call_id = call_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_another_device_notify_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  service handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_another_device_notify_bt(srv_ucm_bt_ind_opcode_enum op, S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_bt_dev_noti_struct* notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[UCMBT] another device, op%:%d", op);
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    if (op == SRV_UCM_BT_INCOMING_CALL_IND)
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, 
            GRP_ID_UCM_BT_DEV_NOTI, 
            NULL, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

        notify = OslMalloc(sizeof(mmi_ucm_bt_dev_noti_struct));
        notify->opcode = op;
        notify->srv_hd = srv_hd;

        mmi_frm_scrn_first_enter(
            GRP_ID_UCM_BT_DEV_NOTI, SCR_ID_UCM_BT_DEV_NOTIFY, 
            (FuncPtr)mmi_ucm_entry_notify_bt, 
            (void*)notify);
    }
    else if (op == SRV_UCM_BT_REFRESH_IND || op == SRV_UCM_BT_RELEASE_IND)
    {
        if (mmi_frm_group_is_present(GRP_ID_UCM_BT_DEV_NOTI))
        {
            mmi_frm_group_close(GRP_ID_UCM_BT_DEV_NOTI);
        }
    }
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __BT_SPK_VOL_CONTROL__
    U8 vol_level;
#endif //__BT_SPK_VOL_CONTROL__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_INIT_BT);
    mmi_ucm_init_context_bt();
#ifdef __BT_SPK_VOL_CONTROL__
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_INIT_VOL, mmi_vol_get_speech_vol());
    if (mmi_vol_get_speech_vol() == 0)
    {
        mmi_vol_set_speech_vol(3);
    }
    if (MDI_AUD_VOL_IS_MUTE_LEVEL(srv_speech_get_mode_volume()))
    {
        vol_level = MDI_AUD_VOL_LEVEL_NORMAL_MUTE;
    }
    else
    {
        vol_level = MDI_AUD_VOL_LEVEL_NORMAL;
    }
    mdi_audio_bt_register_volume_sync_callback(APP_BT_DIALER, vol_level, mmi_ucm_vol_control_callback_bt);
#endif //__BT_SPK_VOL_CONTROL__

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deint_bt
 * DESCRIPTION
 *  Releases all call components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deint_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
    mmi_ucm_stop_incoming_ringtone_bt();

    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) != 0)
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
        if (srv_speech_is_phone_mute() == MMI_TRUE)
        {
            srv_speech_unmute_phone();
        }
    }
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
    mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_UNSPECIFIED_ERROR);
#ifdef __MMI_UCM_BT_CALL_RECORDER__
    if (mdi_audio_is_recording())
    {
        mmi_ucm_end_record_option_bt();
    }
#endif /* __MMI_UCM_BT_CALL_RECORDER__ */
    mmi_ucm_init_context_bt();
    mmi_ucm_delete_all_screen_bt();
#ifdef __MMI_TELEPHONY_SUPPORT__
    // Local incoming cal and BT in-calll, disconnect BT connection from SP side.
    if (srv_ucm_is_incoming_call())
    {
        mmi_ucm_play_incoming_tone();
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vol_control_callback
 * DESCRIPTION
 *  Volume control from H-Free device
 * PARAMETERS
 *  volume      IN  volume want to set to HF by AG
 *  is_mute     IN  CM doen't not support mute
 * RETURNS
 *  MMI_TRUE    Set volume to CM OK
 *  MMI_FALSE   Speech is off now
 *****************************************************************************/
MMI_BOOL mmi_ucm_vol_control_callback_bt(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        if (srv_bt_dialer_is_any_call())
        {
            /* Adjust speech volume */
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_VOL_SYNC, volume, is_mute);
            mmi_vol_set_speech_vol(volume);
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_speaker_vol_ind_bt
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_speaker_vol_ind_bt(U8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cur_vol = srv_speech_get_mode_volume();
    U8 vol_level;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MDI_AUD_VOL_IS_MUTE_LEVEL(cur_vol))
    {
        vol_level = MDI_AUD_VOL_LEVEL_NORMAL_MUTE;
    }
    else
    {
        vol_level = MDI_AUD_VOL_LEVEL_NORMAL;
    }
    mdi_audio_bt_register_volume_sync_callback(APP_BT_DIALER, vol_level, mmi_ucm_vol_control_callback_bt);
    mdi_audio_sync_volume_from_bt(gain);
}

#endif /* __BT_SPK_VOL_CONTROL__ */


#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_scrlocker_event_notify_handler_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret mmi_ucm_scrlocker_event_notify_handler_bt(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING)
    {
        if (srv_bt_dialer_is_any_call())
        {
            return MMI_RET_ERR;
        }
    }
    return MMI_RET_OK;
}
#endif /*  __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__ */


#ifdef __MMI_UCM_BT_CALL_RECORDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_start_record_option_bt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mmi_ucm_start_record_option_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    WCHAR filepath[50];
    int record_disk;
    RTC_CTRL_GET_TIME_T   rtc_time;
    DCL_HANDLE rtc_handler;
    kal_uint8 count;
    FS_HANDLE handle;
    FS_DiskInfo disk_info;
    kal_uint64 disk_free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in mass storage mode*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE),MMI_EVENT_FAILURE, NULL);
        return;
    }
#endif /*  __USB_IN_NORMAL_MODE__ */
    /* Check if memory card is inserted before record. */
    record_disk = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    if(record_disk < FS_NO_ERROR)
    {
       mmi_popup_display((WCHAR*)(UI_string_type)GetString((U16)srv_fmgr_fs_error_get_string(record_disk)), MMI_EVENT_FAILURE, NULL);
       return;
    }
    result = FS_GetDevStatus((UINT)record_disk, FS_MOUNT_STATE_ENUM);
    if(result < FS_NO_ERROR)
    { 
       mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MMI_EVENT_FAILURE, NULL);
       return;
    }

    /* Check if has enough space before record. */
    kal_wsprintf(filepath, "%c:\\", record_disk);
    result = FS_GetDiskInfo((const WCHAR *)filepath, &disk_info, FS_DI_FREE_SPACE);
    if(result >= FS_NO_ERROR)
     {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space <= 0)    /*  free space request. */
        {
          /* popup "Memory full" */
          mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE, NULL);
          return;
        } 
     }
    else
     {  
    mmi_popup_display((WCHAR*)(UI_string_type)GetString((U16)srv_fmgr_fs_error_get_string(result)), MMI_EVENT_FAILURE, NULL); 
    return;
     }
     
    /* Check if destination folder exists before record. */
    kal_wsprintf((WCHAR*) filepath, "%c%w", record_disk, L":\\Record\\");
    result = srv_fmgr_fs_create_folder((const WCHAR *)filepath);
    if(result < FS_NO_ERROR)
    {
        return;
    }
    
    /* Get full path */
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE); 
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *) &rtc_time);
    DclRTC_Close(rtc_handler);

    for (count = 0; count < 100; count++)
    {
        kal_wsprintf(
            filepath,
            "%c%w%02d%02d%02d%02d%02d%02d.wav",
            FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE),
            L":\\Record\\",
            rtc_time.u1Mon,
            rtc_time.u1Day,
            rtc_time.u1Hour,
            rtc_time.u1Min,
            rtc_time.u1Sec,
            count);  

        /* Check if filename duplicate */
       // handle = FS_Open(filepath, FS_READ_WRITE | FS_CREATE);
        handle = FS_Open(filepath, FS_READ_ONLY);
        if (handle >= FS_NO_ERROR)
        {
            FS_Close(handle);
            if(count == 99)
            {
                return;
            } 
       }
       else
       {
           break;
       }
     }

    /* start record */
    result = mdi_audio_start_record(
                filepath,
                MDI_FORMAT_WAV_DVI_ADPCM,                    
                MDI_AUDIO_REC_QUALITY_LOW,
                mmi_ucm_start_record_evt_hdlr_bt,
                NULL);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_START_RCD, result);
    if (result == MDI_AUDIO_SUCCESS)
    {
       /* set state to record */
       DTGetRTCTime(&g_ucm_bt_start_record_time);
    }
    else
    {
      mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_record_option_bt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mmi_ucm_end_record_option_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_stop_record();
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_END_RCD, result);
    if (result == MDI_AUDIO_SUCCESS)
    {
        memset(&g_ucm_bt_start_record_time, 0, sizeof(MYTIME));//to do free start record time
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_start_record_evt_hdlr_bt
 * DESCRIPTION
 *
 * PARAMETERS
 *  result  [IN]
 *  user_data  [IN]
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mmi_ucm_start_record_evt_hdlr_bt(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (result == MDI_AUDIO_DISC_FULL)
    {
        /* Restore audio recorder's state */
	//show error popup
	mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE, NULL);
    }
}
#endif /* __MMI_UCM_BT_CALL_RECORDER__*/


#ifdef __MMI_UCM_BT_BTBOX_NOLCD__

#include "Mdi_audio.h"

srv_prof_volume_level g_ucm_bt_btbox_volume = 5;


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_btb_vol_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_vol_up_button     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_btb_vol_hdlr(MMI_BOOL is_vol_up_button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_vol_up_button)
    {
        if(g_ucm_bt_btbox_volume < 7)
        {
            g_ucm_bt_btbox_volume++;
            mmi_frm_input_event_notify_remove(NOTIFY_UCM_BT_VOLMUTE);
            mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_VOLUP);
        }
    }
    else
    {
        if(g_ucm_bt_btbox_volume > 0)
        {
            g_ucm_bt_btbox_volume--;

            if(g_ucm_bt_btbox_volume == 0)
            {
                mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_VOLMUTE);
            }
            else
            {
                mmi_ucm_btb_send_notify(NOTIFY_UCM_BT_VOLDOWN);
            }
        }
    }    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BTB_VOL_HDLR, is_vol_up_button, g_ucm_bt_btbox_volume);

    mdi_audio_set_volume(MDI_VOLUME_SPH, (U8)MDI_AUD_VOL_MUTE((U8)g_ucm_bt_btbox_volume));
}
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

#endif /* __MMI_BT_CALL_SUPPORT__ */


