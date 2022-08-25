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
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 * -------
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __J2ME__

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
#include "GpioSrvGprot.h"            /* SRV_BACKLIGHT_SHORT_TIME */
#include "IdleNotificationManagerGprot.h"
#include "IdleGprot.h"
#include "TimerEvents.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "JavaAgencyGProt.h"
#include "jam_msg_handler.h"
#include "jal.h"
#include "jam_internal.h"
#include "jpush_interface.h"
#include "jam_interface.h"

#include "UcmSrvGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif

#include "jam_mvm_manager.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "mmi_rp_vapp_java_def.h"
#else
#include "ScrLockerGprot.h"
#endif
extern java_context_struct g_java;


/*****************************************************************************
** 5. JAVA_TIMEALARM_PUSH
**    mmi_java_recv_timealarm_push_ind
**    mmi_java_recv_timealarm_push_get_setting_cnf
**    mmi_java_send_timealarm_push_res
**    mmi_java_entry_timealarm_push_res
**    mmi_java_exit_timealarm_push_res
**    mmi_java_send_timealarm_push_res_yes
**    mmi_java_send_timealarm_push_res_no
**    mmi_java_entry_timealarm_push_launch
**    mmi_java_exit_timealarm_push_launch
*****************************************************************************/
mmi_java_timealarm_push_ind_struct timealarm_push_ind_msg[MAX_PUSH_REGISTRY];
kal_bool timealarm_push_ind_msg_used[MAX_PUSH_REGISTRY] = {KAL_FALSE};
static kal_bool timealarm_push_processing = KAL_FALSE;
static U32 timealarm_push_processing_index;
static kal_bool push_launch_success = KAL_TRUE; 

extern void jam_external_mid_start_req_handler(ilm_struct * ilm_ptr);
kal_bool g_is_asm_allow_to_launch = KAL_TRUE;
extern java_java_mid_start_req_struct  g_java_start_last_req;


/* =========================================== */
/* 0: can launch                               */
/* 1: BG call cannot launch but need to popup  */
/*                                             */
/* =========================================== */
kal_uint8 mmi_java_push_env_launch_status = 0;
/*****************************************************************************
 * FUNCTION
 *  fetch_time_alarm_event_id
 * DESCRIPTION
 *  Look for a timealarm
 * PARAMETERS
 *  void
 * RETURNS
 *  0~ MAX_PUSH_REGISTRY-1 : have one more timealarm
 *  -1 : means no timealarm
 *****************************************************************************/
static S32 fetch_time_alarm_event_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_FETCH_EVENT);  
    for (i = 0; i < MAX_PUSH_REGISTRY; i++)
        if (timealarm_push_ind_msg_used[i])
        {
            return i;
        }


    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  new_time_alarm_event_id
 * DESCRIPTION
 *  Get a position to save a new timealarm
 * PARAMETERS
 *  void
 * RETURNS
 *  0~ MAX_PUSH_REGISTRY-1 : have position
 *  -1 : means no position
 *****************************************************************************/
static S32 new_time_alarm_event_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_ADD_EVENT);       
    for (i = 0; i < MAX_PUSH_REGISTRY; i++)
        if (!timealarm_push_ind_msg_used[i])
        {
            timealarm_push_ind_msg_used[i] = KAL_TRUE;
            return i;
        }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  delete_time_alarm_event_id
 * DESCRIPTION
 *  Delete the timealarm
 * PARAMETERS
 *  id      [IN]        The id of timealarm which should be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
static void delete_time_alarm_event_id(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_DELETE_EVENT,id);      
    ASSERT(timealarm_push_ind_msg_used[id]);

    timealarm_push_ind_msg_used[id] = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_send_message
 * DESCRIPTION
 *  send message
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_push_send_message(module_type src_id, module_type dst_id, S32 sap_id, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *send_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	send_ilm = allocate_ilm(src_id);
    send_ilm->src_mod_id = src_id;
    send_ilm->dest_mod_id = dst_id;
    send_ilm->msg_id = msg_id;
    send_ilm->local_para_ptr = (local_para_struct *) local_para_ptr;
    send_ilm->peer_buff_ptr = (peer_buff_struct *) peer_buff_ptr;
    send_ilm->sap_id = sap_id;

    msg_send_ext_queue(send_ilm);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_repush_handler
 * DESCRIPTION
 *  try to push previous timealarm push again 
 *  the previous timealarm push is blocked due to the current AP don't want it popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_timealarm_repush_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_timealarm_push_ind_struct *timealarm_push_ind_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_REPUSH);       
       
	timealarm_push_ind_ptr = /*(mmi_java_timealarm_push_ind_struct*)*/
							 construct_local_para(sizeof(mmi_java_timealarm_push_ind_struct), TD_CTRL);
    timealarm_push_ind_ptr->pushalarm_type = -1;
    
    mmi_java_send_message_from_active_mod(MOD_MMI, J2ME_MMI_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND, timealarm_push_ind_ptr);

}
static kal_bool timer_set = KAL_FALSE;


/*****************************************************************************
 * FUNCTION
 *  mmi_java_cannot_be_canceled_screen_del_scr_callback
 * DESCRIPTION
 *  delete CB for stopping the cancel of poupup screen  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_java_cannot_be_canceled_screen_del_scr_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CANNOT_BE_DELETED);       
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_confirm_endkey_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press end key  in "TIMEALARM PUSH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_timealarm_push_confirm_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CONFIRM_ENDKEY_HDLR);       
    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    mmi_idle_display();   
    mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_FALSE);
    SetKeyHandler(NULL,KEY_END,KEY_EVENT_DOWN);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_dummy_endkey_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press end key  in dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_timealarm_push_dummy_endkey_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/           
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CONFIRM_ENDKEY_HDLR);       
    
    timealarm_push_processing = KAL_FALSE;              
    SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);         
    mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_FALSE);
    SetDelScrnIDCallbackHandler(SCR_JAVA_DUMMY, NULL);       
    
    return KAL_FALSE;      

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_fail_endkey_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press end key  in "FAIL LAUNCH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_timealarm_push_fail_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_FAIL_ENDKEY_HDLR);       

    ClearInputEventHandler(MMI_DEVICE_ALL);
    StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
    g_java.is_push  = KAL_FALSE;
    timer_set = KAL_TRUE;
    timealarm_push_processing = KAL_FALSE;       
    push_launch_success = KAL_TRUE;
    SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL);      
    mmi_idle_display();   

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_fail_handler
 * DESCRIPTION
 *  process faled to launch Java situation  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_launch_fail_handler(void)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_FAIL_HDLR);           
    ClearInputEventHandler(MMI_DEVICE_ALL);
    StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
    g_java.is_push  = KAL_FALSE;
    timer_set = KAL_TRUE;
    timealarm_push_processing = KAL_FALSE;    
    push_launch_success = KAL_TRUE;      
    SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL);     
    GoBackHistory(); 
}

void mmi_java_timealarm_launch_fail_screen_cb(void)
{
    
    StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
    g_java.is_push  = KAL_FALSE;
    timer_set = KAL_TRUE;
    timealarm_push_processing = KAL_FALSE;       
    push_launch_success = KAL_TRUE;    
    SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL);     
    if (GetActiveScreenId() == SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        GoBackHistory();
    }  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_check_launch_handler
 * DESCRIPTION
 *  check the Java launch is success or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_check_launch_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CHECK_LAUNCH_HDLR);  

    if(!push_launch_success){
		    if (mmi_nmgr_is_active() || mmi_idle_is_active())
		    {
			      g_java.is_push = MMI_FALSE;
        	  mmi_java_timealarm_push_callback(g_java.push_session_id,g_java.push_permission,g_java.push_execute);
			      return;
		    }

        EntryNewScreen(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL, NULL, NULL);
        
        ShowCategory21Screen(
            STR_JAVA_LAUNCH_FAIL,
            mmi_java_get_install_title_icon(),
            NULL,
            0,
            NULL,
            0,
            STR_JAVA_LAUNCH_FAIL_CONFIRM,
            NULL);
        //SetLeftSoftkeyFunction(mmi_java_launch_fail_handler, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);                
        SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);        
        SetKeyHandler(mmi_java_timealarm_push_fail_endkey_hdlr,KEY_END,KEY_EVENT_DOWN);
        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, mmi_java_cannot_be_canceled_screen_del_scr_callback); 
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        StartTimer(J2ME_NOT_READY_TIMER, 2000, mmi_java_timealarm_launch_fail_screen_cb);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive MMI_JAVA_RECV_TIMEALARM_PUSH_IND
 *  The message means java want to launch a MIDlet for timealarm
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_recv_timealarm_push_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 session_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND);

    if(((mmi_java_timealarm_push_ind_struct*) MsgStruct)->pushalarm_type != -1)
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH);

        session_id = new_time_alarm_event_id();

        /* ASSERT(0<= session_id);// too many time alarm, maybe memory leak ? or java task allow more timealarm ? */
        if (session_id < 0)
        {
            return; /* drop this timealarm event, because there are too many event need to process */
        }

        kal_mem_cpy(
                    &timealarm_push_ind_msg[session_id],
                    (mmi_java_timealarm_push_ind_struct*) MsgStruct,
                    sizeof(mmi_java_timealarm_push_ind_struct));
        if (!timer_set)
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH_GO);
            mmi_java_launch_time_alarm();
        }        
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH_GO);    
        mmi_java_launch_time_alarm();
    }


}



kal_char *g_mmi_java_push_setting_mids_storage;

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_push_get_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ to MOD_JAM to get setting of
 * MIDS
 *  
 * PARAMETERS
 *  session_id      [IN]        
 *  mids_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_push_get_setting_req(U32 session_id, U32 mids_id, kal_char* root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_mids_get_setting_req_struct*) construct_local_para(sizeof(mmi_java_mids_get_setting_req_struct), TD_CTRL);
    msg->mids_id = (kal_uint32)mids_id;
    msg->storage_name = (kal_char*)root;

    mmi_java_push_send_message(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_PUSH_GET_SETTING_REQ, msg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_time_alarm
 * DESCRIPTION
 *  Start to launch the MIDlet for time alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_time_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 session_id = -1;
    U8 is_popup_allow;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM);          
    if ((session_id = fetch_time_alarm_event_id()) < 0)
    {
        timer_set = KAL_FALSE;
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_EMPTY);          
        return; /* no time alarm event should launch.. */
    }

    if (!timealarm_push_processing && 
#ifdef __DM_LAWMO_SUPPORT__       
        !mmi_dmui_is_phone_lock()&&
#endif
        mmi_java_is_push_allowed_to_launch()              /* for fix issue : block when mids install, delete, update in MMI layer*/
        //!(g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL)      /* To prevent from send msg again when option has sent */
       )
        /*!install_update_status.is_normal_install && */  /* for fix issue : the push popup when installing midlet */
        /*!g_jam_in_remove_state)                     */  /* for fix issue : the push popup when removing midlet */
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_ALLOW);     
        ASSERT(0 <= session_id);
        timealarm_push_processing = KAL_TRUE;
        timealarm_push_processing_index = session_id;
    #ifdef __OP02__
        SetProtocolEventHandler(
            (PsFuncPtr) mmi_java_recv_timealarm_push_get_setting_cnf_hdlr,
            MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF);        
    #else
        SetProtocolEventHandler(
            (PsFuncPtr) mmi_java_recv_timealarm_push_get_setting_cnf,
            MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF);
    #endif    
        g_mmi_java_push_setting_mids_storage = (kal_char*)get_ctrl_buffer(strlen(timealarm_push_ind_msg[session_id].mids_storage_name) + 1);
        strcpy((kal_char *) g_mmi_java_push_setting_mids_storage, (const kal_char *) timealarm_push_ind_msg[session_id].mids_storage_name);
        
        mmi_java_send_push_get_setting_req(
            0,
            jam_call_back_functions.jam_get_mids_id_from_push_name(timealarm_push_ind_msg[session_id].mids_storage_name),
            g_mmi_java_push_setting_mids_storage);
    }
    else
    {
        #ifdef __MMI_BACKGROUND_CALL__
        
        /* first from can launch state to BG call status */
        if (!mmi_java_push_env_launch_status && srv_ucm_is_background_call())
        {
            mmi_java_push_env_launch_status = 1;
            //mmi_display_popup((UI_string_type)GetString(STR_JAVA_PUSH_LAUNCH_CONFIRM_IN_BGCALL),MMI_EVENT_FAILURE);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_JAVA_PUSH_LAUNCH_CONFIRM_IN_BGCALL), MMI_EVENT_FAILURE, NULL);
            StartTimer(J2ME_TIMEALARM_TIMER,  10 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);    /* waiting 10 seconds, and try again... */
            timer_set = KAL_TRUE;                            
        }
        else                            
        #endif
        {                
            /* print the reason of popup deny */
            if (!is_popup_allow == POPUP_ALL_ON)
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,0);         
            }
            if (mmi_java_is_in_voice_call())
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,1);         
            }
            if (timealarm_push_processing)           
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,2);         
            }
            if (install_update_status.is_normal_install)
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,3);         
            }
            if (g_jam_in_remove_state)
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,4);         
            }
            if (!mmi_java_is_push_allowed_to_launch())
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,5);         
            }
            if ((g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL))
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,6);         
            }               
#ifdef __DM_LAWMO_SUPPORT__
            if (mmi_dmui_is_phone_lock)
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,7);         
            }            	
#endif                     	
            StartTimer(J2ME_TIMEALARM_TIMER, 10 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);    /* waiting 10 seconds, and try again... */
            timer_set = KAL_TRUE;
        }            
    }
}


//#if (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_dummy_entry
 * DESCRIPTION
 * PARAMETERS
 *  session_id      [IN]        
 *  permission      [IN]        
 *  execute         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_dummy_entry(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
//#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_callback
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES to MOD_J2ME
 *  to send confirm mids permission and execution status
 * PARAMETERS
 *  session_id      [IN]        
 *  permission      [IN]        
 *  execute         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_java_timealarm_push_callback(U32 session_id, S8 permission, kal_bool execute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_timealarm_push_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_PUSH_CALLBACK,execute);
#if (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    mmi_frm_scrn_enter(
        GRP_ID_ROOT,
        SCR_JAVA_DUMMY,
        NULL,
        mmi_java_push_dummy_entry,
        MMI_FRM_FULL_SCRN);
#endif
    mmi_java_load_setting();

    push_launch_success = KAL_TRUE;
    
    /* for fix the lock screen issue */
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);  
    
    /* for fix the issue : the midlet is deleted */
    if(timealarm_push_ind_msg_used[session_id])
    {    
        if (execute)
        {
            /* for fix the issue : when we will launch java, the incoming call arrives at the same time */
            if(mmi_java_is_in_voice_call())
            {            
                StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
                timer_set = KAL_TRUE;
                timealarm_push_processing = KAL_FALSE;  
                return;
            }
#ifdef J2ME_SLIM_SCREEN_MEMORY_SUPPORT
    jam_enter_screen(0);     //20101223,128+32   
#endif /* J2ME_SLIM_SCREEN_MEMORY_SUPPORT */
        }
        else
        {
            //mmi_display_popup((UI_string_type)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED),MMI_EVENT_FAILURE);
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED), MMI_EVENT_FAILURE, NULL);
        }

        msg = (mmi_java_timealarm_push_res_struct*) construct_local_para(sizeof(mmi_java_timealarm_push_res_struct), TD_CTRL);

        msg->callback_entry = timealarm_push_ind_msg[session_id].callback_entry;
        msg->execute = execute;
        msg->mid_class_name = timealarm_push_ind_msg[session_id].mid_class_name;
        msg->mids_storage_name = timealarm_push_ind_msg[session_id].mids_storage_name;
        msg->mids_permission = permission;
        msg->pushalarm_type = timealarm_push_ind_msg[session_id].pushalarm_type;
        msg->session_id = timealarm_push_ind_msg[session_id].session_id;

        mmi_java_push_send_message(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES, msg, NULL);

        delete_time_alarm_event_id(session_id);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_PUSH_CALLBACK_ERROR);    
    }
    
    timealarm_push_processing = KAL_FALSE;
    StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
    timer_set = KAL_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to decide
 *  the response data for PushAlarmPermissionCnf
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_entry_timealarm_push_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    mmi_java_entry_timealarm_push_confirm();

    return MMI_TRUE;
}


#ifdef __OP02__
void mmi_java_recv_timealarm_push_get_running_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_check_push_mid_running_rsp_struct *rsp_msg; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_java_check_push_mid_running_rsp_struct*) MsgStruct;

    if(rsp_msg->ret != KAL_TRUE)    
    {
        if (g_java.mids_setting.permission_push == PERMISSION_NEVER ||
            g_java.mids_setting.permission_push == PERMISSION_DENY ||
            g_java.mids_setting.permission_push == PERMISSION_USER_DENIED)
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_NEVER);    
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));
            mmi_java_send_timealarm_push_res(
                timealarm_push_processing_index,
                g_java.mids_setting.permission_push,
                KAL_FALSE);
        }
        else if (g_java.mids_setting.permission_push == PERMISSION_SESSION ||
                 g_java.mids_setting.permission_push == PERMISSION_ONE_SHOT ||
                 g_java.mids_setting.permission_push == PERMISSION_BLANKET ||
                 g_java.mids_setting.permission_push == PERMISSION_DENY_SESSION)
        {
                /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
                if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] ||mmi_java_is_in_voice_call())
                {
                    timealarm_push_processing = KAL_FALSE;
                    StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
                    timer_set = KAL_TRUE;        
                    return;
                }  
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);        
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_entry_timealarm_push_confirm_entry_hdlr, NULL);
        }
        else if (g_java.mids_setting.permission_push == PERMISSION_ALLOW ||
                 g_java.mids_setting.permission_push == PERMISSION_BLANKET_GRANTED)
        {
            /* bug fix : the trusted mids push launch when VM is background running */
            /* launch directly will cause assert, so always confirm */ 
            //if(!mmi_java_is_in_idle_screen())
            //{
                /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
                if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] ||mmi_java_is_in_voice_call())
                {
                    timealarm_push_processing = KAL_FALSE;
                    StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
                    timer_set = KAL_TRUE;        
                    return;
                }        
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);          
                mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_entry_timealarm_push_confirm_entry_hdlr, NULL);
            //}
            //else
            //{
            //    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_RUN);  
            //    g_java.is_push = KAL_FALSE;
            //    mmi_java_timealarm_push_callback(timealarm_push_processing_index,g_java.mids_setting.permission_push,KAL_TRUE);
            //}
        }
        else
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_OTHERS);      
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));
            mmi_java_send_timealarm_push_res(
                timealarm_push_processing_index,
                g_java.mids_setting.permission_push,
                KAL_FALSE);
        }    
    }
    else
    {
        mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_FALSE);    
    }
}





/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_get_setting_cnf_hdlr
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to decide
 *  the response data for PushAlarmPermissionCnf
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_timealarm_push_get_setting_cnf_hdlr(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;
    mmi_java_check_push_mid_running_req_struct *req_msg;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF);
    
    /* fix bug : reset the get setting handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;

    if(g_mmi_java_push_setting_mids_storage != msg->storage_name)
    {
        mmi_java_recv_mids_get_setting_cnf(MsgStruct);
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
        timer_set = KAL_TRUE;                
        return;
    }        
    
    free_ctrl_buffer(msg->storage_name);
    msg->storage_name = NULL;
    
    /* for fix the issue : the midlet is deleted  or incoming call arrives at the same time */
    /* for fix issue : block when mids install, delete, update in MMI layer */
    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index]  || mmi_java_is_in_voice_call() || !mmi_java_is_push_allowed_to_launch())
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
        timer_set = KAL_TRUE;        
        return;
    }

    if (msg->error_code == J2ME_NO_ERROR)
    {
        g_java.mids_trusted = (U8) msg->mids_trusted;

        kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
    }
    else
    {
        /* for fix the issue : the midlet is deleted */
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 5 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);           
        return;
    }
    
    SetProtocolEventHandler(
        (PsFuncPtr) mmi_java_recv_timealarm_push_get_running_cnf,
        MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_RSP);

    req_msg = (mmi_java_check_push_mid_running_req_struct*) construct_local_para(sizeof(mmi_java_check_push_mid_running_req_struct), TD_CTRL);
    req_msg->session_id = 0;
    req_msg->mid_storage_name = timealarm_push_ind_msg[timealarm_push_processing_index].mids_storage_name;
    
    mmi_java_push_send_message(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ, req_msg, NULL);
        
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to decide
 *  the response data for PushAlarmPermissionCnf
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_timealarm_push_get_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF);
    
    /* fix bug : reset the get setting handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;

    if(g_mmi_java_push_setting_mids_storage != msg->storage_name)
    {
        mmi_java_recv_mids_get_setting_cnf(MsgStruct);
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
        timer_set = KAL_TRUE;                
        return;
    }        
    
    free_ctrl_buffer(msg->storage_name);
    msg->storage_name = NULL;
    
    /* for fix the issue : the midlet is deleted  or incoming call arrives at the same time */
    /* for fix issue : block when mids install, delete, update in MMI layer */
    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index]  || mmi_java_is_in_voice_call() || !mmi_java_is_push_allowed_to_launch())
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
        timer_set = KAL_TRUE;        
        return;
    }

    if (msg->error_code == J2ME_NO_ERROR)
    {
        g_java.mids_trusted = (U8) msg->mids_trusted;

        kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
    }
    else
    {
        /* for fix the issue : the midlet is deleted */
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 5 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);           
        return;
    }

    if (g_java.mids_setting.permission_push == PERMISSION_NEVER ||
        g_java.mids_setting.permission_push == PERMISSION_DENY ||
        g_java.mids_setting.permission_push == PERMISSION_USER_DENIED)
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_NEVER);    
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));
        mmi_java_send_timealarm_push_res(
            timealarm_push_processing_index,
            g_java.mids_setting.permission_push,
            KAL_FALSE);
    }
    else if (g_java.mids_setting.permission_push == PERMISSION_SESSION ||
             g_java.mids_setting.permission_push == PERMISSION_ONE_SHOT ||
             g_java.mids_setting.permission_push == PERMISSION_BLANKET ||
             g_java.mids_setting.permission_push == PERMISSION_DENY_SESSION)
    {
		    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
		    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] ||mmi_java_is_in_voice_call())
		    {
		        timealarm_push_processing = KAL_FALSE;
		        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
		        timer_set = KAL_TRUE;        
		        return;
		    }    	
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);        
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_entry_timealarm_push_confirm_entry_hdlr, NULL);
    }
    else if (g_java.mids_setting.permission_push == PERMISSION_ALLOW ||
             g_java.mids_setting.permission_push == PERMISSION_BLANKET_GRANTED)
    {
        /* bug fix : the trusted mids push launch when VM is background running */
        /* launch directly will cause assert, so always confirm */ 
        //if(!mmi_java_is_in_idle_screen())
        //{
		    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
		    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] ||mmi_java_is_in_voice_call())
		    {
		        timealarm_push_processing = KAL_FALSE;
		        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
		        timer_set = KAL_TRUE;        
		        return;
		    }        
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);          
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_entry_timealarm_push_confirm_entry_hdlr, NULL);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_OTHERS);      
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));
        mmi_java_send_timealarm_push_res(
            timealarm_push_processing_index,
            g_java.mids_setting.permission_push,
            KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_timealarm_push_res
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES to MOD_J2ME
 *  to send confirm mids permission and execution status
 * PARAMETERS
 *  session_id      [IN]        
 *  permission      [IN]        
 *  execute         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_timealarm_push_res(U32 session_id, S8 permission, kal_bool execute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_timealarm_push_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_TIMEALARM_PUSH_RES,execute);
    
    /* for fix the issue : the midlet is deleted */
    if(timealarm_push_ind_msg_used[session_id])
    {   

        if(execute)
        {
            g_java.is_push  = KAL_TRUE;
            g_java.push_session_id = session_id;
            g_java.push_permission = permission; 
            g_java.push_execute = execute;

            push_launch_success = KAL_FALSE;
            
/* in some low end platform, the processing time is longer enought to be viewas as launch fail */            
/* in future, maybe nees FW to help to notify us if gotoildescreen fail */
#if defined(MT6225)            
            StartTimer(J2ME_TIMEALARM_TIMER, 6 * 1000, (FuncPtr) mmi_java_check_launch_handler);
#else
            StartTimer(J2ME_TIMEALARM_TIMER, 3 * 1000, (FuncPtr) mmi_java_check_launch_handler);
#endif            
        }
        else
        {
            msg = (mmi_java_timealarm_push_res_struct*) construct_local_para(sizeof(mmi_java_timealarm_push_res_struct), TD_CTRL);

            msg->callback_entry = timealarm_push_ind_msg[session_id].callback_entry;
            msg->execute = execute;
            msg->mid_class_name = timealarm_push_ind_msg[session_id].mid_class_name;
            msg->mids_storage_name = timealarm_push_ind_msg[session_id].mids_storage_name;
            msg->mids_permission = permission;
            msg->pushalarm_type = timealarm_push_ind_msg[session_id].pushalarm_type;
            msg->session_id = timealarm_push_ind_msg[session_id].session_id;

            mmi_java_push_send_message(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES, msg, NULL);

            delete_time_alarm_event_id(session_id);
            timealarm_push_processing = KAL_FALSE;
            StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
            /* mmi_java_launch_time_alarm(); */    
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_TIMEALARM_PUSH_RES_ERROR);    
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_delete_callback
 * DESCRIPTION
 *  Send abort message to VM to terminate installing
 * PARAMETERS
 *  in_param    [IN]    no use here
 * RETURNS
 *  return if we want to stop delete the screen
 *****************************************************************************/
BOOL mmi_java_timealarm_push_confirm_del_cb(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_DELETED);

    if( (U32)in_param == MMI_HIST_DELETE_SCREEN_TYPE  || (U32)in_param == MMI_HIST_DELETE_SCREEN_IN_END_KEY_TYPE )
    {
        timer_set = KAL_TRUE;
        timealarm_push_processing = KAL_FALSE;
        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_handler
 * DESCRIPTION
 *  Handle Function: revoked when selected item changed
 * PARAMETERS
 *  index       [IN]        Index of selected item
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_java_push_highlight_index;

static void mmi_java_push_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_push_highlight_index = index;
}

void mmi_java_confirm_option_setting()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;
    U16 text_items[3];  
    U16 icon_items[3];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_OPTION);

    EntryNewScreen(SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION, NULL, mmi_java_confirm_option_setting, NULL);
    
    str = (U8*) get_string(STR_JAVA_PUSH_LAUNCH_ASK); 
    text_items[0] = (STR_GLOBAL_YES);
    text_items[1] = (STR_GLOBAL_NO);
    text_items[2] = (STR_JAVA_PUSH_LAUNCH_ASK_ME_LATER);
    icon_items[0] = (IMG_MENU3108_JAVA);
    icon_items[1] = (IMG_MENU3108_JAVA);
    icon_items[2] = (IMG_MENU3108_JAVA);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION);

    RegisterHighlightHandler(mmi_java_push_highlight_handler); 
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        3,
        text_items,
        icon_items,
        NULL,
        0,
        0,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_java_timealarm_push_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);     
    SetCenterSoftkeyFunction(mmi_java_timealarm_push_confirm_yes_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_timealarm_push_confirm_endkey_hdlr,KEY_END,KEY_EVENT_DOWN);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_timealarm_push_confirm
 * DESCRIPTION
 *  TimeAlarm Push Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_timealarm_push_confirm_destroy_cb(void *arg)
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_JAVA_TIME_ALARM);

    return 1;
}


void mmi_java_entry_timealarm_push_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 is_popup_allow;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM);    
    
    
    /* for fix the issue : push launch when keypad is locked */    
    if(mmi_scr_locker_is_locked())
    {
        g_java.isinlock = KAL_TRUE;
        mmi_idle_display();
    }
    else
    {
    		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        if(mmi_java_push_env_launch_status == 1)
        {
            mmi_java_push_env_launch_status = 0;            
        }            
        mmi_frm_start_scenario(MMI_SCENARIO_ID_JAVA_TIME_ALARM);

            EntryNewScreen(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL, mmi_java_entry_timealarm_push_confirm, NULL);

        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, mmi_java_timealarm_push_confirm_del_cb);
        mmi_frm_set_destroy_scrn_callback(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, mmi_java_timealarm_push_confirm_destroy_cb);
        /* playRequestedTone(WARNING_TONE); */            
        guiBuffer = (U8*)(get_string(STR_JAVA_PUSH_LAUNCH_ASK));
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        ShowCategory74Screen(
            STR_JAVA_LAUNCH_ASK,
            mmi_java_get_install_title_icon(),
            STR_GLOBAL_OPTIONS,
            0,
            0,
            0,
            guiBuffer,
            mmi_ucs2strlen((S8*) guiBuffer),
            NULL);
        SetLeftSoftkeyFunction(mmi_java_confirm_option_setting, KEY_EVENT_UP);
        SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_java_confirm_option_setting, KEY_EVENT_UP);
        SetKeyHandler(mmi_java_timealarm_push_confirm_endkey_hdlr,KEY_END,KEY_EVENT_DOWN);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_islock
 * DESCRIPTION
 *  Check if unlock action is required
 * PARAMETERS
 *  void
 * RETURNS
 *  non-0: indication required, 0: indication not required
 *****************************************************************************/
U8 mmi_java_timealarm_islock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    if(g_java.isinlock)
    {
        return KAL_TRUE;
    }
    else
#endif
    {
        return KAL_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_unlock
 * DESCRIPTION
 *  unlock the idle screen if need
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_java_timealarm_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
           
    if (!mmi_scr_locker_is_locked())
    {
        g_java.isinlock = KAL_FALSE;
		    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
		    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] ||mmi_java_is_in_voice_call())
		    {
		        timealarm_push_processing = KAL_FALSE;
		        StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
		        timer_set = KAL_TRUE;        
		        mmi_idle_display();   
		        return;
		    }        
		    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_entry_timealarm_push_confirm_entry_hdlr, NULL);
    }
    else
    {
        mmi_frm_scrn_enter(mmi_idle_get_group_id(), SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL, mmi_java_timealarm_unlock, MMI_FRM_FG_ONLY_SCRN);
        guiBuffer = (U8*)(get_string(STR_JAVA_PUSH_LAUNCH_ASK));    
        ShowCategory74Screen(
            STR_JAVA_LAUNCH_ASK,
            mmi_java_get_install_title_icon(),
            0,
            0,
            0,
            0,
            guiBuffer,
            mmi_ucs2strlen((S8*) guiBuffer),
            NULL);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_launch_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before launch push
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_launch_ask_terminate_cb(BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_VM_TERMINATED);    
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_LAUNCH_WHEN_PUSH;
        jam_enter_terminate_mode(vm_id);
        mmi_java_entry_terminating(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES", "NO" , "ASK ME LATER"  
 *  in "TIMEALARM PUSH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_timealarm_push_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_ANSWER_HDLR,mmi_java_push_highlight_index);  
    
    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
    if(!timealarm_push_ind_msg_used[timealarm_push_processing_index] || mmi_java_is_in_voice_call())
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_ANSWER_HDLR_ERROR);     
        timealarm_push_processing = KAL_FALSE;
        if(mmi_java_push_highlight_index == 2)
        {
            StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler); 
        }
        else
        {
            StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);         	
        }	
        timer_set = KAL_TRUE;   
        SetDelScrnIDCallbackHandler(SCR_JAVA_DUMMY, NULL);    
        /* for fix the issue : the screen is stay in popup confirm */
        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);   
        //GoBacknHistory(1);
        DeleteScreenIfPresent(SCR_JAVA_TIMEALARM_PUSH_CONFIRM);
        if (GetActiveScreenId() == SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION);
        }          

        return;
    }
    SetDelScrnIDCallbackHandler(SCR_JAVA_DUMMY, NULL);        

    if (mmi_java_push_highlight_index == 0)  /* yes */
    {
        if (jam_is_pause_mode() || jam_is_minimize_mode())
        {
            SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);  
            mmi_java_push_launch_ask_terminate_cb(KAL_TRUE);            
            DeleteScreenIfPresent(SCR_JAVA_TIMEALARM_PUSH_CONFIRM);
            if (GetActiveScreenId() == SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION)
            {
                GoBackHistory();
            }
            else
            {
                DeleteScreenIfPresent(SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION);
            }               
            return;
        }
             
        ClearInputEventHandler(MMI_DEVICE_ALL);
            
        mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_TRUE);
        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);        
        mmi_idle_display();

    }
    else if( mmi_java_push_highlight_index == 1)   /* no */
    {

        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);   
        GoBacknHistory(1);    
        mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_FALSE);

    }
    else if( mmi_java_push_highlight_index == 2)   /* ask me later */
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL);   
        GoBacknHistory(1);   

        StartTimer(J2ME_TIMEALARM_TIMER, 5 * 60 * 1000, (FuncPtr) mmi_java_timealarm_repush_handler);   
        timer_set = KAL_TRUE;
        timealarm_push_processing = KAL_FALSE;

    }
    else
    {
        ASSERT(0);
    }
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_resend_timealarm_push_res
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_resend_timealarm_push_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	java_java_mid_start_req_struct * resend_push_req_ptr;
    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	resend_push_req_ptr = (java_java_mid_start_req_struct *)construct_local_para(sizeof(java_java_mid_start_req_struct), TD_CTRL);	
	resend_push_req_ptr->game_type = g_java_start_last_req.game_type;
	resend_push_req_ptr->mids_id = g_java_start_last_req.mids_id;
	resend_push_req_ptr->mid_id = g_java_start_last_req.mid_id;
	resend_push_req_ptr->mid_name = g_java_start_last_req.mid_name;
	resend_push_req_ptr->storage_name = g_java_start_last_req.storage_name;
	resend_push_req_ptr->session_id = g_java_start_last_req.session_id;
	resend_push_req_ptr->is_launch_as_bg_running= g_java_start_last_req.is_launch_as_bg_running;
	resend_push_req_ptr->wap_prof_id = g_java_start_last_req.wap_prof_id;

#ifdef J2ME_SLIM_SCREEN_MEMORY_SUPPORT
        mmi_frm_scrn_enter(
        GRP_ID_ROOT,
        SCR_JAVA_DUMMY,
        NULL,
        mmi_java_push_dummy_entry,
        MMI_FRM_FULL_SCRN); 
#endif /* J2ME_SLIM_SCREEN_MEMORY_SUPPORT */
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_RESEND_TIMEALARM_PUSH_REQ, resend_push_req_ptr);     
}
#endif /* __J2ME__ */ 

