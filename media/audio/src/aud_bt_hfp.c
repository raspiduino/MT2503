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
 * aud_bt_hfp.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes BT HFP service functions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
//#include "fat_fs.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"
#include "aud_bt_hfp.h"
#ifdef __MED_BT_HF_MOD__
#include "bt_adp_hf.h"
#endif

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__) 
//#include "bt_dm_struct.h"
#include "bluetooth_hfg_struct.h"
#include "bt_hfg.h"
#include "btdrv_types.h"
//#include "bt_hfadp_struct.h"

extern kal_bool aud_bt_hfp_sco_connect_req(void);
extern kal_bool aud_bt_hfp_sco_disconnect_req(void);

typedef struct
{
    module_type src_mod_id;
    kal_uint16 connect_id;
    kal_bool audio_path_on;
    kal_bool speech_path_on;
    kal_uint8 state;
    aud_bt_hfp_cmd_enum next_cmd;
    kal_uint8 speech_mode;
    kal_uint8 mic_mute_flag;
    kal_uint16 sco_mode;
	void* pContext;
	void* req_Context;
} aud_bt_hfp_context_struct;

aud_bt_hfp_context_struct aud_bt_hfp_ctx;
//static const device_tones_struct aud_bt_silence_tone[] = { 0, 0, 100,  0,   0 };
#ifdef __MED_BT_HF_MOD__
static kal_uint16 hf_connect_id = 0;
kal_bool incoming_bt_dialer_sco = 0;
#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BCM_AT_CMD__
	aud_bt_hfp_ctx.src_mod_id = MOD_BCM;  /* set BCM as the default receiver */
#else
	aud_bt_hfp_ctx.src_mod_id = MOD_MMI;  /* set MMI as the default receiver */
#endif/*__BCM_AT_CMD__*/

    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);
    aud_bt_hfp_ctx.audio_path_on = KAL_FALSE;
    aud_bt_hfp_ctx.speech_path_on = KAL_FALSE;    
    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    aud_bt_hfp_ctx.speech_mode = BT_HFP_EARPHONE_MODE;
    aud_bt_hfp_ctx.mic_mute_flag = 0;
    aud_bt_hfp_ctx.sco_mode = 0;
	aud_bt_hfp_ctx.pContext = NULL;
	aud_bt_hfp_ctx.req_Context = NULL;
    
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_close_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* media_bt_audio_close_req_struct* msg_p = (media_bt_audio_close_req_struct*)ilm_ptr->local_para_ptr; */

    AUD_BT_HFP_FUNC_ENTRY1(AUD_BT_HFP_CLOSE_REQ_HDLR, aud_bt_hfp_ctx.audio_path_on);    
    aud_bt_hfp_set_audio_path(KAL_FALSE);

    if (!aud_bt_hfp_sco_disconnect_req())
    {
        aud_send_bt_audio_close_cnf(aud_bt_hfp_ctx.src_mod_id, MED_RES_OK);
    }

    /* To make sure message send to BT task before MMI task continues */
    /* Because there may have sleep function when change audio path */
    aud_set_event(AUD_EVT_BT_CLOSE_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_open_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_req_struct *msg_p = (media_bt_audio_open_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY1(AUD_BT_HFP_OPEN_REQ_HDLR, aud_bt_hfp_ctx.state)
    
    aud_bt_hfp_ctx.src_mod_id = ilm_ptr->src_mod_id;
    aud_bt_hfp_ctx.speech_mode = msg_p->mode;
	aud_bt_hfp_ctx.pContext    = msg_p->pContext;
	aud_bt_hfp_ctx.req_Context = msg_p->req_context;
	#ifdef __MED_BT_HF_MOD__
		if(msg_p->profile==BT_HF)
    		hf_connect_id = msg_p->connect_id;
		//else if(msg_p->profile==BT_HFP)
	#endif 
			//aud_bt_hfp_ctx.connect_id = msg_p->connect_id;

    if( aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE )
    {
        MED_ASSERT(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE);

        aud_bt_hfp_sco_connect_req();
    }
    else
    {
        aud_send_bt_audio_open_cnf(aud_bt_hfp_ctx.src_mod_id, MED_RES_BUSY, BT_HFG_RESULT_MED_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_turn_on_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2( AUD_BT_HFP_TURN_ON_REQ_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on );

    /* Turn on path if path is not turn on yet */
    if(!aud_bt_hfp_ctx.audio_path_on && aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_OPEN)
    {
        aud_bt_hfp_ctx.audio_path_on = KAL_TRUE;
        aud_bt_hfp_set_audio_path_on();
        aud_bt_hfp_set_speech_path_on();
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_turn_off_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_turn_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY1( AUD_BT_HFP_TURN_OFF_REQ_HDLR, aud_bt_hfp_ctx.audio_path_on )

    /* Turn off path if path is on */
    if(aud_bt_hfp_ctx.audio_path_on)
    {
        aud_bt_hfp_ctx.audio_path_on = KAL_FALSE;
        aud_bt_hfp_set_audio_path_off();
        aud_bt_hfp_set_speech_path_off();
    }

    /* To make sure message send to BT task before MMI task continues */
    /* Because there may have sleep function when change audio path */
    aud_set_event(AUD_EVT_BT_TURN_OFF_AUDIO);
}

#ifdef __MED_BT_HF_MOD__
/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_bt_dialer_sco_ind_timer_hdlr
 * DESCRIPTION
 *  When incoming BT dialer SCO, MED should not set l1audio driver to bt dialer mode to avoid
 *  phone reset, So MED will inform BT service the IND, and if BT service do not set sco mode 
 *  or not disconnect the sco in 3s, MED will call this callback to disconnect the sco 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_bt_dialer_sco_ind_timer_hdlr(void *arg)
{
    med_stop_timer(AUD_BT_DIALER_SCO_IND_TIMER);

    if(incoming_bt_dialer_sco)
    {
    #ifdef __BT_HF_PROFILE__
		aud_send_bt_hf_sco_disconnect_req(MOD_BT,hf_connect_id);
    #endif
        incoming_bt_dialer_sco = 0;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_sco_connect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool processed = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE)
    {
        if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
        {
            /* Set audio (music, FM) path before connect request, to mute audio */
            aud_bt_hfp_set_audio_path_on();
		#ifdef __MED_BT_HF_MOD__
            if (AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode))
            {
            #ifdef __BT_HF_PROFILE__
				aud_send_bt_hf_sco_connect_req(MOD_BT,hf_connect_id);
            #endif
            }
            else
        #endif/*__MED_BT_HF_MOD__*/
            {
            #ifdef __BT_HFG_PROFILE__
                aud_send_bt_hfg_sco_connect_req(MOD_BT,aud_bt_hfp_ctx.pContext,aud_bt_hfp_ctx.req_Context);
            #endif
            }
        }
        else
        {
            processed = KAL_FALSE;
        }
    }

    if (processed)
    {
        aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_CONNECT_SCO;
    }

    return processed;
}



/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_sco_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool processed = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE)
    {
        if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_OPEN)
        {
            
        #ifdef __MED_BT_HF_MOD__
            if (AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)|| incoming_bt_dialer_sco)
            {
                med_stop_timer(AUD_BT_DIALER_SCO_IND_TIMER);
                incoming_bt_dialer_sco = 0;
            #ifdef __BT_HF_PROFILE__
				aud_send_bt_hf_sco_disconnect_req(MOD_BT,hf_connect_id);
            #endif
                aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_BT_DIALER_SCO); // Reset SCO Mode as BT service require, when connect, bt service will set the mode again 
            }
            else
        #endif/*__MED_BT_HF_MOD__*/
            {
            #ifdef __BT_HFG_PROFILE__
                aud_send_bt_hfg_sco_disconnect_req(MOD_BT, aud_bt_hfp_ctx.pContext,aud_bt_hfp_ctx.req_Context);
            #endif /* __BT_HFG_PROFILE__ */
            }
        }
        else
        {
            processed = KAL_FALSE;
        }
    }

    if (processed)
    {
        aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_DISCONNECT_SCO;
    }

    return processed;
}
#ifdef __MED_BT_HF_MOD__
/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hf_sco_connect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_sco_connect_cnf_struct *msg_p = (bt_hf_sco_connect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_bool next_disc = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3( AUD_BT_HFP_SCO_CONNECT_CNF_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on, msg_p->result)
    
    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;

    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);

	#ifdef __MED_MEGA_PHONE__
		if(aud_speech_is_megaphone_on())
		{
			aud_speech_enable_normal_megaphone(KAL_FALSE);
			aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
		}
	#endif
        aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id,BT_HF,msg_p->connection_id);

        if (next_disc)
        {
            /* turn off audio path first due to it is on before connect */
            aud_bt_hfp_set_audio_path_off();
            aud_bt_hfp_sco_disconnect_req();
        }
        else
        {
            /* Set path after the connect request */
            aud_bt_hfp_set_audio_path(KAL_TRUE);

            /* Play a short mute tone to clear data in audio buffer to avoid noise in eSCO retransmission */          
			if(!(AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
            {
            #ifndef __CVSD_CODEC_SUPPORT__
                TONE_Play((const L1SP_Tones*)aud_bt_silence_tone);
                //kal_prompt_trace(MOD_MED,"aud_bt_hfp_set_speech_path_on, silence tone play");
            #endif /*__CVSD_CODEC_SUPPORT__*/
            }
        }

    #ifdef __GAIN_TABLE_SUPPORT__
        /* Notify MMI that BT is connected */
        aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_CONNECT, NULL);
    #endif
    }
    else
    {
        /* Set path back after connect fail, to unmute audio */
        aud_bt_hfp_set_audio_path_off();

        /* If speech path is turned on durning connecting, also need to turn if off when SCO connect fail */
        if(aud_bt_hfp_ctx.speech_path_on)
        {
            aud_bt_hfp_set_speech_path_off();
        }

        aud_send_bt_audio_open_cnf(aud_bt_hfp_ctx.src_mod_id, MED_RES_FAIL, msg_p->result);

	#ifdef __MED_MEGA_PHONE__
		if(aud_speech_is_megaphone_on())
		{
			aud_speech_enable_normal_megaphone(KAL_TRUE);
			aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
		}
	#endif

        if (next_disc)
        {
            aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, MED_RES_OK,BT_HF,msg_p->connection_id);
        }
		
		if((AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
		{
		  aud_bt_hfp_ctx.sco_mode &= ~((kal_uint16)AUD_BT_HFP_MODE_BT_DIALER_SCO); // Reset SCO Mode as BT service require, when connect, bt service will set the mode again
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hf_sco_connect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     bt_hf_sco_connect_ind_struct *msg_p = (bt_hf_sco_connect_ind_struct*)ilm_ptr->local_para_ptr; 
    kal_bool next_disc = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SCO_CONNECT_IND_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.sco_mode)
    
    MED_ASSERT(aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);
	hf_connect_id = msg_p->connection_id;

    aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id,BT_HF,msg_p->connection_id);
	
    incoming_bt_dialer_sco = 1;
	
#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
        aud_speech_enable_normal_megaphone(KAL_FALSE);
		if(!incoming_bt_dialer_sco)
		{
			aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
		}
	}
#endif
	
    if (next_disc)
    {
        if(incoming_bt_dialer_sco)
        {
			aud_send_bt_hf_sco_disconnect_req(MOD_BT,hf_connect_id);
        }
    }
    /* Can not accept SCO connect while FM recording. */
    else if(AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode) &&
           (aud_context_p->state == AUD_MEDIA_RECORD || aud_context_p->state == AUD_MEDIA_RECORD_PAUSED))
    {        
        if(incoming_bt_dialer_sco)
        {
			aud_send_bt_hf_sco_disconnect_req(MOD_BT,hf_connect_id);
        }
	}
    else
    {

        /* Play a short mute tone to clear data in audio buffer to avoid noise in eSCO retransmission */
		if(incoming_bt_dialer_sco)
		{
            med_start_timer(AUD_BT_DIALER_SCO_IND_TIMER, 3000, aud_bt_hfp_bt_dialer_sco_ind_timer_hdlr, 0);
		}
		/* when we are playing and sco connect ,it will interrupt play ,so we should not set audio path*/
		if(aud_context_p->state!=AUD_MEDIA_IDLE)
		{
			return;
		}
		aud_bt_hfp_set_audio_path(KAL_TRUE);
		if(!(AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
        {
        #ifndef __CVSD_CODEC_SUPPORT__
            TONE_Play((const L1SP_Tones*)aud_bt_silence_tone);
            //kal_prompt_trace(MOD_MED,"aud_bt_hfp_set_speech_path_on, silence tone play");
        #endif /*__CVSD_CODEC_SUPPORT__*/
        }

    #ifdef __GAIN_TABLE_SUPPORT__
        /* Notify MMI that BT is connected */
        aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_CONNECT, NULL);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hf_sco_disconnect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_sco_disconnect_cnf_struct *msg_p = (bt_hf_sco_disconnect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 result;
    kal_bool next_conn = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3(
        AUD_BT_HFP_SCO_DISCONNECT_CNF_HDLR,
        aud_bt_hfp_ctx.state,
        aud_bt_hfp_ctx.audio_path_on,
        msg_p->result)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
    {
        return;
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        result = MED_RES_OK;
    }
    else
    {
        result = MED_RES_FAIL;
    }

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, result,BT_HF,msg_p->connection_id);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that BT is disconnected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_DISCONNECT, NULL);
#endif

#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
        aud_speech_enable_normal_megaphone(KAL_TRUE);
		aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
	}
#endif
    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }
    else if((AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
	{
      aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_BT_DIALER_SCO);// Reset SCO Mode as BT service require, when connect, bt service will set the mode again
	}
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hf_sco_disconnect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_sco_disconnect_ind_struct *msg_p = (bt_hf_sco_disconnect_ind_struct*)ilm_ptr->local_para_ptr; 
    kal_bool next_conn = (kal_bool)((aud_bt_hfp_cmd_enum)aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY1(AUD_BT_HFP_SCO_DISCONNECT_IND_HDLR, aud_bt_hfp_ctx.state)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
    {
        return;    
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, MED_RES_HFP_CLOSE,BT_HF,msg_p->connection_id);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that BT is disconnected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_DISCONNECT, NULL);
#endif

#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
		aud_speech_enable_normal_megaphone(KAL_TRUE);
		aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
	}
#endif

    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }
    else if((AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
	{
		aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_BT_DIALER_SCO);// Reset SCO Mode as BT service require, when connect, bt service will set the mode again
	}
}

#endif 


#ifdef __MED_BT_HFP_MOD__
/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_connect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_connect_cnf_struct *msg_p = (bt_hfg_sco_connect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_bool next_disc = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3( AUD_BT_HFP_SCO_CONNECT_CNF_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on, msg_p->result)
    
    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;

    if (msg_p->result == BT_STATUS_SUCCESS)
    {
        AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);
	#ifdef __MED_MEGA_PHONE__
		if(aud_speech_is_megaphone_on())
		{
			aud_speech_enable_normal_megaphone(KAL_FALSE);
			aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
		}
	#endif

        aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id,BT_HFP,0);

        if (next_disc)
        {
            /* turn off audio path first due to it is on before connect */
            aud_bt_hfp_set_audio_path_off();
            aud_bt_hfp_sco_disconnect_req();
        }
        else
        {
            /* Set path after the connect request */
            aud_bt_hfp_set_audio_path(KAL_TRUE);

            /* Play a short mute tone to clear data in audio buffer to avoid noise in eSCO retransmission */

            #ifndef __CVSD_CODEC_SUPPORT__
                TONE_Play((const L1SP_Tones*)aud_bt_silence_tone);
            #endif /*__CVSD_CODEC_SUPPORT__*/

        }

    #ifdef __GAIN_TABLE_SUPPORT__
        /* Notify MMI that BT is connected */
        aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_CONNECT, NULL);
    #endif
    }
	else if(msg_p->result == BT_STATUS_PENDING)
	{
		 // do nothing ,and wait BT  sco  connected 
		 
		 aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_CONNECT_SCO;
	}
    else
    {
        /* Set path back after connect fail, to unmute audio */
        aud_bt_hfp_set_audio_path_off();

        /* If speech path is turned on durning connecting, also need to turn if off when SCO connect fail */
        if(aud_bt_hfp_ctx.speech_path_on)
        {
            aud_bt_hfp_set_speech_path_off();
        }

        aud_send_bt_audio_open_cnf(aud_bt_hfp_ctx.src_mod_id, MED_RES_FAIL, msg_p->result);
	#ifdef __MED_MEGA_PHONE__
		if(aud_speech_is_megaphone_on())
		{
			aud_speech_enable_normal_megaphone(KAL_TRUE);
			aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
		}
	#endif

        if (next_disc)
        {
            aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, MED_RES_OK,BT_HFP,0);
        }
		
    }
}





/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_connected_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* bt_hfg_sco_connect_ind_struct *msg_p = (bt_hfg_sco_connect_ind_struct*)ilm_ptr->local_para_ptr; */
    kal_bool next_disc = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SCO_CONNECT_IND_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.sco_mode)
    
    MED_ASSERT(aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);

    aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id,BT_HFP,0);
	
#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
        aud_speech_enable_normal_megaphone(KAL_FALSE);

		aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
	}
#endif
	
    if (next_disc)
    {
        aud_bt_hfp_sco_disconnect_req();
    }
    /* Can not accept SCO connect while FM recording. */
    else if(AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode) &&
           (aud_context_p->state == AUD_MEDIA_RECORD || aud_context_p->state == AUD_MEDIA_RECORD_PAUSED))
    {
        aud_bt_hfp_sco_disconnect_req();    
    }
#if defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__)
    /* Can not accept SCO connect while A2DP codec is open */
    else if(aud_bt_a2dp_is_codec_opened())
    {
        aud_bt_hfp_sco_disconnect_req();
    }
#endif /* defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__) */
    else
    {
        aud_bt_hfp_set_audio_path(KAL_TRUE);

        {
        #ifndef __CVSD_CODEC_SUPPORT__
            TONE_Play((const L1SP_Tones*)aud_bt_silence_tone);
            //kal_prompt_trace(MOD_MED,"aud_bt_hfp_set_speech_path_on, silence tone play");
        #endif /*__CVSD_CODEC_SUPPORT__*/
        }

    #ifdef __GAIN_TABLE_SUPPORT__
        /* Notify MMI that BT is connected */
        aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_CONNECT, NULL);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_disconnect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_disconnect_cnf_struct *msg_p = (bt_hfg_sco_disconnect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 result;
    kal_bool next_conn = (kal_bool)(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3(
        AUD_BT_HFP_SCO_DISCONNECT_CNF_HDLR,
        aud_bt_hfp_ctx.state,
        aud_bt_hfp_ctx.audio_path_on,
        msg_p->result)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
    {
        return;
    }

    if (msg_p->result == BT_STATUS_SUCCESS)
    {
        result = MED_RES_OK;
    }
	else if(msg_p->result == BT_STATUS_PENDING)
	{
		return ; // we will wait that sco disconnect complete 
	}
    else
    {
        result = MED_RES_FAIL;
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, result,BT_HFP,0);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that BT is disconnected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_DISCONNECT, NULL);
#endif

#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
        aud_speech_enable_normal_megaphone(KAL_TRUE);
		aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
	}
#endif

    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_disconnected_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* bt_hfg_sco_disconnect_ind_struct *msg_p = (bt_hfg_sco_disconnect_ind_struct*)ilm_ptr->local_para_ptr; */
    kal_bool next_conn = (kal_bool)((aud_bt_hfp_cmd_enum)aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY1(AUD_BT_HFP_SCO_DISCONNECT_IND_HDLR, aud_bt_hfp_ctx.state)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE && aud_bt_hfp_ctx.next_cmd ==AUD_BT_HFP_CMD_NONE)
    {
        return;    
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, MED_RES_HFP_CLOSE,BT_HFP,0);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that BT is disconnected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_SCO_DISCONNECT, NULL);
#endif

#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
	{
		aud_speech_enable_normal_megaphone(KAL_TRUE);
		aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
	}
#endif

    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }
	
}

#endif
/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_is_audio_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_is_audio_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_IS_AUDIO_PATH_ON, aud_bt_hfp_ctx.audio_path_on, aud_bt_hfp_ctx.next_cmd)

    /* Application do not change audio path while BT is on or connecting */
	
#ifdef __MED_BT_HF_MOD__ 
	return ((aud_bt_hfp_ctx.audio_path_on) || (((aud_bt_hfp_cmd_enum)aud_bt_hfp_ctx.next_cmd) == AUD_BT_HFP_CMD_CONNECT_SCO)) && !(AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode));
#else
    return ((aud_bt_hfp_ctx.audio_path_on) || (((aud_bt_hfp_cmd_enum)aud_bt_hfp_ctx.next_cmd) == AUD_BT_HFP_CMD_CONNECT_SCO));
#endif

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_is_speech_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_is_speech_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY1(AUD_BT_HFP_IS_SPEECH_PATH_ON, aud_bt_hfp_ctx.speech_path_on)

    return aud_bt_hfp_ctx.speech_path_on;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_path_delay_timer_hdlr
 * DESCRIPTION
 *  Mute microphone before set speech mode and unmute it after a short time
 *  to avoid noise goes to uplink right after connect
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_path_delay_timer_hdlr(void *arg)
{
    L1SP_MuteMicrophone(KAL_FALSE);
    aud_bt_hfp_ctx.mic_mute_flag = 0;
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_query_bt_speech_scenario
 * DESCRIPTION
 *  query the bt speech scenario by currecnt status
 * PARAMETERS
 *  void
 * RETURNS
 *  SPH_ENH_AND_FIR_SCENE
 *****************************************************************************/
SPH_ENH_AND_FIR_SCENE aud_bt_hfp_query_bt_speech_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     SPH_ENH_AND_FIR_SCENE scene = SPH_ENH_AND_FIR_SCENE_BT_EARPHONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* BT on, don't care if it is under recording. Always use BT scenario */
    /* Determine speech parameters */
    if (AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
    #ifndef __FMRADIO_I2S_SUPPORT__
        scene = SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS;
    #endif /* __FMRADIO_I2S_SUPPORT__ */
    }
    else if (AUD_BT_HFP_IS_ATV_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {    
    #ifndef __ATV_I2S_SUPPORT__
        scene = SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS;
    #endif /* __ATV_I2S_SUPPORT__ */
    }
#ifdef __MED_BT_HF_MOD__ 
	else if (AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode))
    {    
        scene = SPH_ENH_AND_FIR_SCENE_BT_CORDLESS;
    }
#endif /*__MED_BT_HF_MOD__*/


	else if (AUD_BT_HFP_IS_MEGAPHONE_SCO(aud_bt_hfp_ctx.sco_mode))
    {    
        scene = SPH_ENH_AND_FIR_SCENE_BT_CORDLESS;
    }

    else
    {     
        if(aud_bt_hfp_ctx.speech_mode == BT_HFP_CARKIT_MODE)
        {
            scene = SPH_ENH_AND_FIR_SCENE_BT_CARKIT;
        }
    }

    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_QUERY_SPEECH_SCENARIO, scene, aud_bt_hfp_ctx.sco_mode);

    return scene;
 
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_speech_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_speech_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_ENH_AND_FIR_SCENE scene ;

#ifdef __MED_CTM_MOD__
    kal_bool need_protect = KAL_FALSE;
#endif
    kal_bool is_mute;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY(AUD_BT_HFP_SET_SPEECH_PATH_ON)

    aud_bt_hfp_ctx.speech_path_on = KAL_TRUE;

    if (aud_context_p->speech_on)
    {
    #ifdef __MED_CTM_MOD__
        if (aud_ctm_is_tty_on())
        {
            /* When TTY is on, don't turn off speech/microphone */
            need_protect = KAL_TRUE;
            L1Ctm_Close();
        }
    #endif

        /* Store mute state because the mute flag will be cleared when speech is off */
        is_mute = L1SP_IsMicrophoneMuted();
        L1SP_Speech_Off();
        L1SP_MuteMicrophone(is_mute);
    }

#ifdef __HD_RECORD__
    if(!aud_rec_query_record_speech_mode(&scene))
#endif
    {
        scene = aud_bt_hfp_query_bt_speech_scenario();
    }

    /* Determine speech parameters */
#ifndef __FMRADIO_I2S_SUPPORT__    
    if (AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        /* Set input source for line-in mode */
        L1SP_SetInputSource(L1SP_LNA_FMRR);
    }
#endif /* __FMRADIO_I2S_SUPPORT__ */    

#ifndef __ATV_I2S_SUPPORT__
    if (AUD_BT_HFP_IS_ATV_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        /* Set input source for line-in mode */
        L1SP_SetInputSource(L1SP_LNA_FMRR);
    }
#endif /* __ATV_I2S_SUPPORT__ */

#ifdef __MED_BT_HF_MOD__ 
    if(!AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode))
#endif
    {
        
    	if(!AUD_BT_HFP_IS_MEGAPHONE_SCO(aud_bt_hfp_ctx.sco_mode))
		{
        /* Mute speech, keypad tone output device */
        aud_speech_set_output_device(0);
        aud_keytone_set_output_device(0);
		}
    }


    /* Mute microphone for a short time to avoid noise goes to uplink */
    if(!L1SP_IsMicrophoneMuted())
    {
        L1SP_MuteMicrophone(KAL_TRUE);
        med_stop_timer(AUD_BT_SET_PATH_TIMER);
        med_start_timer(AUD_BT_SET_PATH_TIMER, 1000, aud_bt_hfp_set_path_delay_timer_hdlr, 0);
        aud_bt_hfp_ctx.mic_mute_flag = 1;
    }

#ifndef __GAIN_TABLE_SUPPORT__
    /* Set speech mode*/
    L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
#endif

    if(aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    #ifdef __MED_CTM_MOD__
        if (need_protect)
        {
            aud_ctm_resume();
        }
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  _aud_bt_hfp_get_output_device_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the output device
 *****************************************************************************/
static kal_uint8 _aud_bt_hfp_get_output_device_by_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = AUDIO_DEVICE_SPEAKER;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set speech output device */
    if(aud_context_p->audio_mode == AUD_MODE_NORMAL)
    {
        audio_path = AUDIO_DEVICE_SPEAKER;
    }
    else if(aud_context_p->audio_mode == AUD_MODE_HEADSET)
    {
        audio_path = AUDIO_DEVICE_SPEAKER2;
    }
    else if(aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
    {
        audio_path = AUDIO_DEVICE_LOUDSPEAKER;
    }
    else
    {
        ASSERT(0);
    }

    return custom_cfg_hw_aud_output_path(audio_path);

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_speech_path_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_speech_path_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 output_device;
    SPH_ENH_AND_FIR_SCENE scene;

#ifdef __MED_CTM_MOD__
    kal_bool need_protect = KAL_FALSE;
#endif
    kal_bool is_mute;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY(AUD_BT_HFP_SET_SPEECH_PATH_OFF)

    aud_bt_hfp_ctx.speech_path_on = KAL_FALSE;

    if (aud_context_p->speech_on)
    {
    #ifdef __MED_CTM_MOD__
        if (aud_ctm_is_tty_on())
        {
            /* When TTY is on, don't turn off speech/microphone */
            need_protect = KAL_TRUE;
            L1Ctm_Close();
        }
    #endif

        /* Store mute state because the mute flag will be cleared when speech is off */
        is_mute = L1SP_IsMicrophoneMuted();
        L1SP_Speech_Off();
        L1SP_MuteMicrophone(is_mute);
    }

    /* Stop delay timer and unmute microphone when set path back to phone */
    med_stop_timer(AUD_BT_SET_PATH_TIMER);
    if(aud_bt_hfp_ctx.mic_mute_flag && L1SP_IsMicrophoneMuted())
    {
        L1SP_MuteMicrophone(KAL_FALSE);
    }
    aud_bt_hfp_ctx.mic_mute_flag = 0;

#ifdef __HD_RECORD__
    if(!aud_rec_query_record_speech_mode(&scene))
#endif
    {
        scene = aud_speech_query_speech_scenario_by_mode(aud_context_p->audio_mode);
    }

#ifndef __GAIN_TABLE_SUPPORT__
    L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
    /* Set Speech Mode*/
#endif

    output_device = _aud_bt_hfp_get_output_device_by_mode();

    /* Restore speech, keypad tone output device path*/
    aud_speech_set_output_device(output_device);
	aud_keytone_set_output_device(output_device);

#ifdef __MED_FMR_MOD__
    /* Restore input source when disconnect SCO */
    L1SP_SetInputSource(aud_context_p->input_device);
#endif /* __MED_FMR_MOD__ */

#ifndef __GAIN_TABLE_SUPPORT__
    /* set speech FIR coefficient */
    aud_speech_set_fir_index_by_mode(aud_context_p->audio_mode);
#endif

    if(aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    #ifdef __MED_CTM_MOD__
        if (need_protect)
        {
            aud_ctm_resume();
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_audio_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 device = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_AUDIO_PATH_ON, aud_bt_hfp_ctx.sco_mode, aud_context_p->melody_output_device);

	#ifdef __MED_BT_HF_MOD__ 
    if(AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode))
		return;
    #endif

    if(aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        device = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER);
    }

#ifdef __MED_FMR_MOD__
    if (AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        aud_fmr_set_output_device(device);
    }
    else
#endif
#ifdef __ATV_SUPPORT__
    if (AUD_BT_HFP_IS_ATV_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        aud_atv_set_output_device(device);
    }
    else
#endif /* __ATV_SUPPORT__ */
    {
        /* Set Audio Path */
        aud_melody_set_output_device(device);
    }

    /* Mute tone, keypad tone output device */
    aud_tone_set_output_device(0);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_audio_path_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 output_device;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_AUDIO_PATH_OFF, aud_context_p->audio_mode, aud_bt_hfp_ctx.sco_mode);

    /* Restore tone output device path*/

    output_device = _aud_bt_hfp_get_output_device_by_mode();
    aud_tone_set_output_device(output_device);


#ifdef __MED_FMR_MOD__
    /* Set FM Radio Path */
    if (AUD_BT_HFP_IS_FM_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        aud_audio_set_fmrdo_path_volume(aud_context_p->audio_mode);
    }
    else
#endif /* __MED_FMR_MOD__ */
#ifdef __ATV_SUPPORT__
    /* Update ATV path */
    if (AUD_BT_HFP_IS_ATV_VIA_BT_SCO(aud_bt_hfp_ctx.sco_mode))
    {
        aud_audio_set_atv_path_volume(aud_context_p->audio_mode);
    }
    else
#endif /* __ATV_SUPPORT__ */
    /* Set Audio Path */
    {
        aud_audio_set_melody_path_volume(aud_context_p->audio_mode);
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_audio_path(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3(AUD_BT_HFP_SET_AUDIO_PATH, aud_bt_hfp_ctx.speech_path_on, aud_bt_hfp_ctx.audio_path_on, on)

    if (((aud_bt_hfp_ctx.audio_path_on && !on) || (!aud_bt_hfp_ctx.audio_path_on && on)) ||
        ((aud_bt_hfp_ctx.speech_path_on && !on) || (!aud_bt_hfp_ctx.speech_path_on && on)))
    {
        aud_bt_hfp_ctx.audio_path_on = on;
    
        if (on)
        {
            aud_bt_hfp_set_audio_path_on();
            aud_bt_hfp_set_speech_path_on();
        }
        /* Off */
        else
        {
            aud_bt_hfp_set_audio_path_off();
            aud_bt_hfp_set_speech_path_off();            
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  _aud_bt_hfp_reconfig_speech_path
 * DESCRIPTION
 *  reconfig speech path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_bt_hfp_reconfig_speech_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(aud_bt_hfp_is_speech_path_on())
    {
        aud_bt_hfp_set_speech_path_off();
        aud_bt_hfp_set_speech_path_on();
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_sco_mode
 * DESCRIPTION
 *  This function is used to set SCO mode. The speech parameters will be set
 *  according to the specified SCO mode.
 * PARAMETERS
 *  mode        [IN]    The SCO mode to be set.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_sco_mode(aud_bt_hfp_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_bt_hfp_ctx.sco_mode |= (kal_uint16)mode;

    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_SCO_MODE, mode, aud_bt_hfp_ctx.sco_mode)

    /* Change BT mode if SCO connected */
    _aud_bt_hfp_reconfig_speech_path();

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_get_sco_mode
 * DESCRIPTION
 *  This function is used to get current SCO mode.
 * PARAMETERS
 *  mode        [IN]    The SCO mode to be set.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_get_sco_mode(kal_uint16* sco_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sco_mode = aud_bt_hfp_ctx.sco_mode;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_reset_sco_mode
 * DESCRIPTION
 *  This function is used to reset a SCO mode.
 * PARAMETERS
 *  mode        [IN]    The SCO mode to be reset.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_reset_sco_mode(aud_bt_hfp_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_bt_hfp_ctx.sco_mode &= ~((kal_uint16)mode);

    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_RESET_SCO_MODE, mode, aud_bt_hfp_ctx.sco_mode)

    /* Change BT mode if SCO connected */
    _aud_bt_hfp_reconfig_speech_path();

}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_sco_mode_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_sco_mode_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_set_sco_mode_req_struct *msg_p = (media_bt_audio_set_sco_mode_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    aud_bt_hfp_ctx.sco_mode |= (kal_uint16)msg_p->mode;
	
	if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
	{
		return;
	}

	
#ifdef __MED_BT_HF_MOD__
	if(incoming_bt_dialer_sco && (AUD_BT_HFP_IS_BT_DIALER_SCO(aud_bt_hfp_ctx.sco_mode)))
	{
        med_stop_timer(AUD_BT_DIALER_SCO_IND_TIMER);
		if(aud_bt_hfp_ctx.audio_path_on ==KAL_FALSE)
		{
			aud_bt_hfp_set_audio_path(KAL_TRUE);
		}
		_aud_bt_hfp_reconfig_speech_path();
		incoming_bt_dialer_sco =0;
	}
#endif

    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_SCO_MODE, msg_p->mode, aud_bt_hfp_ctx.sco_mode)

}


#endif /* __MED_BT_HFP_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

