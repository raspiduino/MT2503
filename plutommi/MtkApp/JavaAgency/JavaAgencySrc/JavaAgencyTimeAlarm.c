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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "jam_mvm_manager.h"

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

#ifdef __MMI_NCENTER_SUPPORT__
#include "JavaAgencyNCenter.h"
#endif
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
#include "FileMgrSrvGProt.h"
#endif

mmi_java_push_cntx_struct g_mmi_java_push_cntx;

/* ========================================================================= */
/*                                                                           */
/*                            constant define region                         */
/*                                                                           */
/* ========================================================================= */
#define MMI_JAVA_REPUSH_LONG_INTERVAL (5 * 60 * 1000)  /* 5 min */
#define MMI_JAVA_REPUSH_SHORT_INTERVAL (4 * 1000)  /* 5 min */


/* ========================================================================= */
/*                                                                           */
/*                      global variables define region                       */
/*                                                                           */
/* ========================================================================= */
kal_bool g_is_asm_allow_to_launch = KAL_TRUE;
kal_char *g_mmi_java_push_setting_mids_storage;
U16 g_mmi_java_push_terminate_vm_id = 0;
#ifdef __MMI_NCENTER_SUPPORT__
NMGR_HANDLE g_mmi_java_push_nmgr_handle;
#endif

char temp_storage[10] = "0000";
char temp_name[10] = "push";
mmi_java_check_push_mid_running_rsp_struct temp_rsp_msg;


/* ========================================================================= */
/*                                                                           */
/*                        extern / predefine region                          */
/*                                                                           */
/* ========================================================================= */
extern java_java_mid_start_req_struct  g_java_start_last_req;
extern java_context_struct g_java;
extern kal_bool g_jam_in_terminating;
extern kal_eventgrpid g_java_event_group_1;
extern kal_eventgrpid g_java_event_group_2;
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
extern kal_uint32 g_jam_mvm_whole_heap_size;
#endif

#ifdef __SUPPORT_JAVA_PUSH__
void mmi_java_push_recv_get_setting_cnf_hdlr(void *MsgStruct);
MMI_BOOL mmi_java_push_recv_get_running_cnf(void);
#ifndef __COSMOS_MMI_PACKAGE__
MMI_BOOL mmi_java_push_entry_confirm(mmi_scenario_id scen_id, void *arg);
void mmi_java_push_enter_confirm(void);
#endif
void mmi_java_push_confirm_hdlr(void);
void mmi_java_push_vm_terminate_hdlr(void);
void mmi_java_push_launch_ask_terminate_cb(BOOL terminate, U16 vm_id);
void mmi_java_push_send_get_setting_req(U32 session_id, U32 mids_id, kal_char* root);
void mmi_java_push_timealarm_repush_handler(void);
U8 mmi_java_push_confirm_destroy_cb();
extern MMI_BOOL srv_usb_is_in_mass_storage_mode(void);  
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
        if (g_mmi_java_push_cntx.push_entry_used[i])
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
        if (!g_mmi_java_push_cntx.push_entry_used[i])
        {
            g_mmi_java_push_cntx.push_entry_used[i] = KAL_TRUE;
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
    ASSERT(g_mmi_java_push_cntx.push_entry_used[id]);

    g_mmi_java_push_cntx.push_entry_used[id] = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_repush_and_finish_session
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_repush_and_finish_session(U32 interval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(J2ME_TIMEALARM_TIMER, interval, (FuncPtr) mmi_java_push_timealarm_repush_handler);   
    g_mmi_java_push_cntx.timer_set = KAL_TRUE;
    g_mmi_java_push_cntx.is_processing = KAL_FALSE;

}   


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_timealarm_repush_handler
 * DESCRIPTION
 *  try to push previous timealarm push again 
 *  the previous timealarm push is blocked due to the current AP don't want it popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_timealarm_repush_handler(void)
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
    timealarm_push_ind_ptr->pushalarm_type = (kal_uint32)-1;
    timealarm_push_ind_ptr->show_busy_popup = KAL_FALSE;
    
    mmi_java_send_message_from_active_mod(MOD_MMI, J2ME_MMI_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND, timealarm_push_ind_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_check_screen_del_scr_callback
 * DESCRIPTION
 *  delete CB for stopping the cancel of poupup screen  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #if 0
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
#endif 
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_check_screen_endkey_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press end key  in "FAIL LAUNCH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_check_screen_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_FAIL_ENDKEY_HDLR);       

    ClearInputEventHandler(MMI_DEVICE_ALL);
    g_java.is_push  = KAL_FALSE;
    mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_LONG_INTERVAL);   
    g_mmi_java_push_cntx.is_launch = KAL_TRUE;
    //SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL);      
    mmi_idle_display();   

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_check_screen_timeout_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_check_screen_timeout_callback(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id, screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_java.is_push  = KAL_FALSE;
    mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_LONG_INTERVAL);   
    g_mmi_java_push_cntx.is_launch = KAL_TRUE;    
    //SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, NULL);
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
    if (screen_id == SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        mmi_frm_scrn_close_active_id();
    }  
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_check_launch_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_push_check_launch_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CHECK_LAUNCH_HDLR);  
    if(!g_mmi_java_push_cntx.is_launch)
    {
        
        if (
        #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
            mmi_nmgr_is_active() || 
        #endif 
            mmi_idle_is_active())
        
        {
            g_java.is_push = MMI_FALSE;
            mmi_java_push_launch_callback(g_java.push_session_id,g_java.push_permission,g_java.push_execute);
            return;
        }
        
        group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        if(!mmi_frm_scrn_enter(
            group_id, 
            SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, 
            NULL, 
            NULL, 
            MMI_FRM_FULL_SCRN))
        {
            return;
        } 
        
        ShowCategory21Screen(
            STR_JAVA_LAUNCH_FAIL,
            mmi_java_get_install_title_icon(),
            NULL,
            0,
            NULL,
            0,
            STR_JAVA_LAUNCH_FAIL_CONFIRM,
            NULL);
        
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);                
        SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);        
        SetKeyHandler(mmi_java_push_check_screen_endkey_hdlr,KEY_END,KEY_EVENT_DOWN);
        //SetDelScrnIDCallbackHandler(SCR_JAVA_TIMEALARM_PUSH_LUANCH_FAIL, mmi_java_push_check_screen_del_scr_callback); 
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        StartTimer(J2ME_NOT_READY_TIMER, 2000, mmi_java_push_check_screen_timeout_callback);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_check_launch_handler
 * DESCRIPTION
 *  check the Java launch is success or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_check_launch_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, mmi_java_push_check_launch_callback, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_launch
 * DESCRIPTION
 *  Start to launch the MIDlet for time alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 session_id = -1;
   // U8 is_popup_allow;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM);          
    if ((session_id = fetch_time_alarm_event_id()) < 0)
    {
        g_mmi_java_push_cntx.timer_set = KAL_FALSE;
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_EMPTY);          
        return; /* no time alarm event should launch.. */
    }
    
    if (!g_mmi_java_push_cntx.is_processing && 
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
        g_mmi_java_push_cntx.is_processing = KAL_TRUE;
        g_mmi_java_push_cntx.processing_idx = session_id;

        SetProtocolEventHandler((PsFuncPtr) mmi_java_push_recv_get_setting_cnf_hdlr, MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF);

        g_mmi_java_push_setting_mids_storage = (kal_char*)get_ctrl_buffer(strlen(g_mmi_java_push_cntx.push_entry[session_id].mids_storage_name) + 1);
        strcpy((kal_char*) g_mmi_java_push_setting_mids_storage, (const kal_char*) g_mmi_java_push_cntx.push_entry[session_id].mids_storage_name);
        g_mmi_java_push_setting_mids_storage[strlen(g_mmi_java_push_cntx.push_entry[session_id].mids_storage_name)] = 0;
        
        mmi_java_push_send_get_setting_req(0, 0, g_mmi_java_push_setting_mids_storage);
    }
    else
    {
        #ifdef __MMI_BACKGROUND_CALL__
        
        /* first from can launch state to BG call status */
        if (!g_mmi_java_push_cntx.first_push_during_bgcall_arrive && srv_ucm_is_background_call())
        {
            g_mmi_java_push_cntx.first_push_during_bgcall_arrive = MMI_TRUE;
        #ifndef __COSMOS_MMI_PACKAGE__
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_JAVA_PUSH_LAUNCH_CONFIRM_IN_BGCALL), MMI_EVENT_FAILURE, NULL);
        #else
            vapp_java_display_push_popup(STR_JAVA_PUSH_LAUNCH_CONFIRM_IN_BGCALL);
        #endif
            //mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
            StartTimer(J2ME_TIMEALARM_TIMER, MMI_JAVA_REPUSH_SHORT_INTERVAL, (FuncPtr) mmi_java_push_timealarm_repush_handler);   
            g_mmi_java_push_cntx.timer_set = KAL_TRUE;
        }
        else                            
        #endif
        {                
            /* print the reason of popup deny */
            if (mmi_java_is_in_voice_call())
            {
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_LAUNCH_TIMEALARM_POPUP_DENY,1);         
            }
            if (g_mmi_java_push_cntx.is_processing)           
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
            //mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
            StartTimer(J2ME_TIMEALARM_TIMER, MMI_JAVA_REPUSH_SHORT_INTERVAL, (FuncPtr) mmi_java_push_timealarm_repush_handler);   
            g_mmi_java_push_cntx.timer_set = KAL_TRUE;
        }            
    }
}

#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_nmgr_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
mmi_ret mmi_java_push_nmgr_proc(mmi_event_struct *evt)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
    {
        mmi_event_struct push_evt;

#ifdef __MMI_USB_SUPPORT__
        if(srv_usb_is_in_mass_storage_mode())
        {
            g_mmi_java_push_cntx.option_choice = 2;
        }
        else
#endif
        {
            g_mmi_java_push_cntx.option_choice = 0;
        }

        MMI_FRM_INIT_EVENT(&push_evt, 0);
        MMI_FRM_POST_EVENT(&push_evt, mmi_java_push_ncenter_event_proc, NULL);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 mmi_java_push_nmgr_notify
 *  mmi_java_push_send_get_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_nmgr_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct alert_info;
    WCHAR temp[60];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
#ifdef __COSMOS_MMI_PACKAGE__
    alert_info.app_id = VAPP_JAVA;
#else
    alert_info.app_id = APP_JAVA;
#endif
    alert_info.scen_id = MMI_SCENARIO_ID_JAVA_TIME_ALARM;
    alert_info.event_type = MMI_EVENT_JAVA_PUSH;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK | MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
    alert_info.behavior_mask = FORCE_STATUS_BAR;
    alert_info.status_bar_para.display_string = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    mmi_ucs2cpy((CHAR *)temp, (const CHAR *)GetString(STR_JAVA_PUSH_ARRIVE));
    alert_info.status_bar_para.display_string = temp;
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_JAVA_PUSH;
    alert_info.app_proc_para.scrn_group_proc = &mmi_java_push_nmgr_proc;
    alert_info.app_proc_para.user_data = NULL;
    g_mmi_java_push_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_send_get_setting_req
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
void mmi_java_push_send_get_setting_req(U32 session_id, U32 mids_id, kal_char* root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_mids_get_setting_req_struct*) construct_local_para(sizeof(mmi_java_mids_get_setting_req_struct), TD_CTRL);
    msg->session_id = (kal_uint32)session_id;
    msg->mids_id = (kal_uint32)mids_id;
    msg->storage_name = root;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_PUSH_GET_SETTING_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_recv_get_setting_cnf_hdlr
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to decide
 *  the response data for PushAlarmPermissionCnf
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_recv_get_setting_cnf_hdlr(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;
    mmi_java_check_push_mid_running_req_struct *req_msg;  
    kal_uint32 event_group;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;

    if(strcmp(g_mmi_java_push_setting_mids_storage, msg->storage_name))
    {
        mmi_java_recv_mids_get_setting_cnf(MsgStruct);
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);             
        return;
    }

    free_ctrl_buffer(g_mmi_java_push_setting_mids_storage);
    g_mmi_java_push_setting_mids_storage = NULL;
    
    /* for fix the issue : the midlet is deleted  or incoming call arrives at the same time */
    /* for fix issue : block when mids install, delete, update in MMI layer */
    if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx]  || mmi_java_is_in_voice_call() || 
       !mmi_java_is_push_allowed_to_launch() || jam_mvm_has_launching_midlet())
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF_ERROR);    
        mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);      
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
        mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
        return;
    }

    /* get push midlet running state */
    //SetProtocolEventHandler((PsFuncPtr) mmi_java_push_recv_get_running_cnf, MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_RSP);

    req_msg = (mmi_java_check_push_mid_running_req_struct*) construct_local_para(sizeof(mmi_java_check_push_mid_running_req_struct), TD_CTRL);
    req_msg->mid_storage_name = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mids_storage_name;
    req_msg->mid_id = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mid_id;
    g_mmi_java_push_cntx.check_mid_running_result = 0;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ, req_msg);
    kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PUSH_CHECK_RUNNING, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
    
    if (mmi_java_push_recv_get_running_cnf())
    {
        if (g_java.mids_setting.permission_push == PERMISSION_NEVER ||
            g_java.mids_setting.permission_push == PERMISSION_DENY ||
            g_java.mids_setting.permission_push == PERMISSION_USER_DENIED)
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_NEVER);    
#ifndef __COSMOS_MMI_PACKAGE__
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));               
#else
            vapp_java_display_push_popup(STR_JAVA_ERROR_CODE_VERIFY_FAILED);
#endif
            mmi_java_push_send_push_res(
                g_mmi_java_push_cntx.processing_idx,
                g_java.mids_setting.permission_push,
                KAL_FALSE);
        }
        else if (g_java.mids_setting.permission_push == PERMISSION_SESSION ||
                 g_java.mids_setting.permission_push == PERMISSION_ONE_SHOT ||
                 g_java.mids_setting.permission_push == PERMISSION_BLANKET ||
                 g_java.mids_setting.permission_push == PERMISSION_DENY_SESSION)
        {
                /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
                if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] ||mmi_java_is_in_voice_call())
                {
                    mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
                    return;
                }  
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);        
#ifndef __MMI_NCENTER_SUPPORT__
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_push_entry_confirm, NULL);
#else
            mmi_java_push_nmgr_notify();
            mmi_java_push_ncenter_event_show();
#endif

        }
        else if (g_java.mids_setting.permission_push == PERMISSION_ALLOW ||
                 g_java.mids_setting.permission_push == PERMISSION_BLANKET_GRANTED)
        {
            /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
            if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] ||mmi_java_is_in_voice_call())
            {
                mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
                return;
            }        
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CONFIRM);          

            /* use nmgr to show confirm */
#ifndef __MMI_NCENTER_SUPPORT__            
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_push_entry_confirm, NULL);
#else
            mmi_java_push_nmgr_notify();
            mmi_java_push_ncenter_event_show();
#endif
        }
        else
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_OTHERS);  
#ifndef __COSMOS_MMI_PACKAGE__
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED));
#else
            vapp_java_display_push_popup(STR_JAVA_ERROR_CODE_VERIFY_FAILED);
#endif
            mmi_java_push_send_push_res(
                g_mmi_java_push_cntx.processing_idx,
                g_java.mids_setting.permission_push,
                KAL_FALSE);
        }
    }
    else
    {
        mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_recv_get_running_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_java_push_recv_get_running_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
    if(!(g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_FG) || 
        (g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_SUITE_LAUNCH_BUT_MIDLET))    
#else
    if (g_mmi_java_push_cntx.check_mid_running_result == (kal_uint8)KAL_FALSE)
#endif
    {
#if (MAX_VM_INSTANCE_NUM > 1)
        if(g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_VM_IS_SLOT_FULL)                
        {
            g_mmi_java_push_cntx.is_VM_full = MMI_TRUE;                   
        }
        else
        {
            g_mmi_java_push_cntx.is_VM_full = MMI_FALSE;
        }

        if(g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_OTHERS_SUITE_LAUNCH_IN_FG)
        {
            g_mmi_java_push_cntx.is_need_to_minimize_midlet = MMI_TRUE;  
        }             
        else
        {
            g_mmi_java_push_cntx.is_need_to_minimize_midlet = MMI_FALSE;  
        }

        if(g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_SUITE_LAUNCH_BUT_MIDLET ||
           g_mmi_java_push_cntx.check_mid_running_result & JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_BG)
        {
            g_mmi_java_push_cntx.is_terminate_push_midlet = MMI_TRUE;                  
        }        
        else
        {
            g_mmi_java_push_cntx.is_terminate_push_midlet = MMI_FALSE; 
        }
#endif        
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_app_group_proc
 * DESCRIPTION
 *  the proc function for camcorder App.
 * PARAMETERS
 *  evt     [IN]        The event pass in
 * RETURNS
 *  mmi_ret [OUT] the result of event handling
 *****************************************************************************/
mmi_ret mmi_java_push_group_proc(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (evt->evt_id)
    {
           
        case EVT_ID_GROUP_GOBACK:           
        case EVT_ID_GROUP_DELETE_REQ:       
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:    
        #if defined(J2ME_SLIM_MEMORY_SUPPORT)
            if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
            {
                mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
            }
            else
        #endif
            if(g_mmi_java_push_cntx.scrn_force_del_check)
            {
                mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
            }                
            mmi_java_push_confirm_destroy_cb();
            break;
            
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            if(g_mmi_java_push_cntx.scrn_force_del_check)
            {
                mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);          
            }                
            mmi_java_push_confirm_destroy_cb();
            break;
    }


    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_vm_status_hihite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index     [IN]       
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_java_push_vm_status_hihite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_push_cntx.vm_status_menu_hilite_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_exit_vm_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]       
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_java_push_exit_vm_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_java_push_cntx.running_mid_list != NULL)
    {
        for(i = 0; i < g_mmi_java_push_cntx.running_mid_count; i++)
        {
            if(g_mmi_java_push_cntx.running_mid_list[i].mid_name != NULL)
            {
                free_ctrl_buffer(g_mmi_java_push_cntx.running_mid_list[i].mid_name);
                g_mmi_java_push_cntx.running_mid_list[i].mid_name = NULL;
            }
        }
        free_ctrl_buffer(g_mmi_java_push_cntx.running_mid_list);
        g_mmi_java_push_cntx.running_mid_list = NULL;
        g_mmi_java_push_cntx.running_mid_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_enter_vm_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     [IN]       
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_java_push_enter_vm_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *icon_items[MAX_VM_INSTANCE_NUM];
    U8 *text_items[MAX_VM_INSTANCE_NUM];
    U8 item_num = 0;
    U8 i;
    mmi_java_get_running_mids_req_struct *get_running_mids_req;
    kal_uint32 event_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_OPTION);
#ifdef __PLUTO_MMI_PACKAGE__
    if(!mmi_frm_scrn_enter(GRP_ID_JAVA_TIMEALARM_PUSH, 
                           SCR_JAVA_TIMEALARM_PUSH_CONFIRM_VT_OPTION, 
                           mmi_java_push_exit_vm_status_screen, 
                           mmi_java_push_enter_vm_status_screen, 
                           MMI_FRM_FULL_SCRN))
    {
        return;
    }
#endif
    memset(icon_items, 0, sizeof(icon_items));

    g_mmi_java_push_cntx.running_mid_list = NULL;
    get_running_mids_req = (mmi_java_get_running_mids_req_struct*) construct_local_para(sizeof(mmi_java_get_running_mids_req_struct), TD_CTRL);
    get_running_mids_req->running_mid_list = &g_mmi_java_push_cntx.running_mid_list;
    get_running_mids_req->count = &g_mmi_java_push_cntx.running_mid_count;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
         MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_REQ, get_running_mids_req);
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GET_RUNNING_LIST, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);

    item_num = g_mmi_java_push_cntx.running_mid_count;
    for(i = 0; i < item_num; i++)
    {
        text_items[i] = (PU8) g_mmi_java_push_cntx.running_mid_list[i].mid_name;
        icon_items[i] = (PU8) GetImage(IMG_ID_JAVA_PLAY);
    }
#ifdef __PLUTO_MMI_PACKAGE__
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    RegisterHighlightHandler(mmi_java_push_vm_status_hihite_hdlr);
     #ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif 
    ShowCategory170Screen(
        (PU8) GetString(STR_ID_FNG_JAVA_TASK_MANAGER),
        (PU8) GetImage(mmi_java_get_title_icon()),
        (PU8) GetString(STR_GLOBAL_STOP),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        item_num,
        text_items,
        icon_items,
        0,
        g_mmi_java_push_cntx.vm_status_menu_hilite_idx,
        guiBuffer);        

    SetLeftSoftkeyFunction(mmi_java_push_vm_terminate_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_push_vm_terminate_hdlr, KEY_EVENT_UP); 
#elif defined(__COSMOS_MMI_PACKAGE__)
    vapp_java_close_venus_screen();
    g_mmi_java_push_cntx.is_exit_tskmgr = KAL_FALSE;
    if (g_java.screen_after_terminate == TER_ENTRY_TASK_MANAGER)
    {
        g_java.screen_after_terminate = TER_ENTRY_NONE;
    }
    vapp_java_task_manager_entry(KAL_TRUE);
#endif
}


static void mmi_java_push_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_push_cntx.option_choice = index;
}


#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_enter_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_enter_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    //U8 *str;
    U16 text_items[3];  
    U16 icon_items[3];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_OPTION);

    if(!mmi_frm_scrn_enter(
        GRP_ID_JAVA_TIMEALARM_PUSH, 
        SCR_JAVA_TIMEALARM_PUSH_CONFIRM_OPTION, 
        NULL, 
        mmi_java_push_enter_option_screen, 
        MMI_FRM_FULL_SCRN))
    {
        return;
    }         
    
   // str = (U8*) get_string(STR_JAVA_PUSH_LAUNCH_ASK); 
    text_items[0] = (STR_GLOBAL_YES);
    text_items[1] = (STR_GLOBAL_NO);
    text_items[2] = (STR_JAVA_PUSH_LAUNCH_ASK_ME_LATER);
    icon_items[0] = (IMG_MENU3108_JAVA);
    icon_items[1] = (IMG_MENU3108_JAVA);
    icon_items[2] = (IMG_MENU3108_JAVA);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_java_push_highlight_handler); 
  #ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
  #endif
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
        g_mmi_java_push_cntx.option_choice,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_java_push_confirm_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_push_confirm_hdlr, KEY_EVENT_UP);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_confirm_destroy_cb
 * DESCRIPTION
 *  TimeAlarm Push Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_push_confirm_destroy_cb()
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_JAVA_TIME_ALARM);

    return 1;
}


#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_entry_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_push_entry_confirm(mmi_scenario_id scen_id, void *arg)
{
#ifndef __COSMOS_MMI_PACKAGE__
    if(mmi_scr_locker_is_locked() || mmi_scr_locker_is_launched())
    {
        g_java.isinlock = KAL_TRUE;
        mmi_idle_display();
    }
    else
#endif
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_JAVA_TIMEALARM_PUSH, mmi_java_push_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_java_push_enter_confirm();
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_enter_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_enter_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
   // U8 is_popup_allow;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM);    
    
    
    /* for fix the issue : push launch when keypad is locked */    
    if(g_mmi_java_push_cntx.first_push_during_bgcall_arrive)
    {
        g_mmi_java_push_cntx.first_push_during_bgcall_arrive = MMI_FALSE;            
    }  
    g_mmi_java_push_cntx.scrn_force_del_check = MMI_TRUE;

    g_mmi_java_push_cntx.option_choice = 0;

    mmi_frm_start_scenario(MMI_SCENARIO_ID_JAVA_TIME_ALARM);

    if(!mmi_frm_scrn_enter(
        GRP_ID_JAVA_TIMEALARM_PUSH, 
        SCR_JAVA_TIMEALARM_PUSH_CONFIRM, 
        NULL, 
        mmi_java_push_enter_confirm, 
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = (U8*)(get_string(STR_JAVA_PUSH_LAUNCH_ASK));
#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
#endif
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
    SetLeftSoftkeyFunction(mmi_java_push_enter_option_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);        
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_push_enter_option_screen, KEY_EVENT_UP);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}
#endif


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
#ifndef __COSMOS_MMI_PACKAGE__
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
        if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] ||mmi_java_is_in_voice_call())
        {
            mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
            mmi_idle_display();   
            return;
        }        
        //mmi_java_push_enter_confirm();
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_TIME_ALARM, MMI_EVENT_INFO, mmi_java_push_entry_confirm, NULL);
    }
    else
    {
        if(!mmi_frm_scrn_enter(mmi_frm_group_get_active_id(), SCR_JAVA_TIMEALARM_PUSH_CONFIRM_VT_OPTION, NULL, NULL, MMI_FRM_FULL_SCRN))
        {
            return;
        } 
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
#endif
}


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


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_send_push_res
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
void mmi_java_push_send_push_res(U32 session_id, S8 permission, kal_bool execute)
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
    if(g_mmi_java_push_cntx.push_entry_used[session_id])
    {   

        if(execute)
        {
            g_java.is_push  = KAL_TRUE;
            g_java.push_session_id = session_id;
            g_java.push_permission = permission; 
            g_java.push_execute = execute;

            g_mmi_java_push_cntx.is_launch = KAL_FALSE;
            
        /* in some low end platform, the processing time is longer enought to be viewas as launch fail */            
        /* in future, maybe nees FW to help to notify us if gotoildescreen fail */
        #if defined(MT6225)            
            StartTimer(J2ME_TIMEALARM_TIMER, 6000, (FuncPtr) mmi_java_push_check_launch_handler);
        #else
            StartTimer(J2ME_TIMEALARM_TIMER, 3000, (FuncPtr) mmi_java_push_check_launch_handler);
        #endif            
        }
        else
        {
            msg = (mmi_java_timealarm_push_res_struct *) construct_local_para(sizeof(mmi_java_timealarm_push_res_struct), TD_CTRL);

            msg->callback_entry = g_mmi_java_push_cntx.push_entry[session_id].callback_entry;
            msg->execute = execute;
            msg->mid_class_name = g_mmi_java_push_cntx.push_entry[session_id].mid_class_name;
            msg->mid_id = g_mmi_java_push_cntx.push_entry[session_id].mid_id;
            msg->mids_storage_name = g_mmi_java_push_cntx.push_entry[session_id].mids_storage_name;
            msg->mids_permission = permission;
            msg->pushalarm_type = g_mmi_java_push_cntx.push_entry[session_id].pushalarm_type;
            msg->session_id = g_mmi_java_push_cntx.push_entry[session_id].session_id;

            mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES, msg);

            delete_time_alarm_event_id(session_id);
            mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_TIMEALARM_PUSH_RES_ERROR);    
        if (g_mmi_java_push_cntx.is_processing && g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] == KAL_FALSE)
        {
            mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_launch_ask_terminate_proc
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before launch push
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_push_launch_ask_terminate_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.screen_after_terminate = TER_ENTRY_LAUNCH_WHEN_PUSH;
    jam_enter_terminate_mode(g_mmi_java_push_terminate_vm_id);
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_entry_terminating(KAL_FALSE);
    #endif
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
void mmi_java_push_launch_ask_terminate_cb(BOOL terminate, U16 vm_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_VM_TERMINATED);    
    if(terminate)
    {
        g_mmi_java_push_terminate_vm_id = vm_id;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, mmi_java_push_launch_ask_terminate_proc, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_launch_after_terminate_hdlr
 * DESCRIPTION
 *  Callback function to handle
 *  
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_launch_after_terminate_hdlr(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    ClearInputEventHandler(MMI_DEVICE_ALL);
#endif        
    mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_TRUE);
    g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;  
    mmi_idle_display();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_vm_terminate_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_vm_terminate_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
    if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] || mmi_java_is_in_voice_call())
    {
        mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);        
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
        mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);      
        return;
    }
     
    if (g_mmi_java_push_cntx.vm_status_menu_hilite_idx >= 0)  
    {
    mmi_java_check_push_mid_running_req_struct *req_msg;
        kal_uint32 event_group;
        
        req_msg = (mmi_java_check_push_mid_running_req_struct*) construct_local_para(sizeof(mmi_java_check_push_mid_running_req_struct), TD_CTRL);
        req_msg->mid_storage_name = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mids_storage_name;
        req_msg->mid_id = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mid_id;
        g_mmi_java_push_cntx.check_mid_running_result = 0;
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ, req_msg);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PUSH_CHECK_RUNNING, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
        if (!mmi_java_push_recv_get_running_cnf())
        {
            ClearInputEventHandler(MMI_DEVICE_ALL);
            g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
            mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
            mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
        }
        else
        {
            if(g_mmi_java_push_cntx.is_VM_full)
        {
            g_mmi_java_push_cntx.is_VM_full = MMI_FALSE;
                g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;   
            mmi_java_push_launch_ask_terminate_cb(KAL_TRUE, 
                g_mmi_java_push_cntx.running_mid_list[g_mmi_java_push_cntx.vm_status_menu_hilite_idx].vm_id);            
            mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
        } 
        else
        {
            ClearInputEventHandler(MMI_DEVICE_ALL);
            mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_TRUE);
            g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;  
                #ifdef __COSMOS_MMI_PACKAGE__
                if (vapp_launcher_is_active())
                {
                    mmi_java_entry_mid_launch_from_idle();
                }
                else
                #endif
                {
                mmi_idle_display();
                }
            }
        }
    }
    else
    {
    
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_dummy_endkey_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press end key  in dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_push_dummy_endkey_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/           
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CONFIRM_ENDKEY_HDLR);       
    
    g_mmi_java_push_cntx.is_processing = KAL_FALSE;              
    g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;        
    mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
    //SetDelScrnIDCallbackHandler(SCR_JAVA_DUMMY, NULL);       
    
    return KAL_FALSE;      

}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_confirm_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES", "NO" , "ASK ME LATER"  
 *  in "TIMEALARM PUSH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    /* for fix the issue : the midlet is deleted  or incoming call arrive at the same time */    
    if(!g_mmi_java_push_cntx.push_entry_used[g_mmi_java_push_cntx.processing_idx] || mmi_java_is_in_voice_call() || !mmi_java_is_push_allowed_to_launch()
       || (g_jam_in_terminating && g_java.screen_after_terminate != TER_ENTRY_LAUNCH_WHEN_PUSH)
#ifdef __COSMOS_MMI_PACKAGE__
       || vapp_java_is_in_low_battery()
#endif
        )
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_CONFIRM_ANSWER_HDLR_ERROR);     

        if(g_mmi_java_push_cntx.option_choice == 2)
        {
            mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_LONG_INTERVAL);
        }
        else
        {
            mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);        
        }    
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);      
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_JAVA_TIMEALARM_PUSH_INVALID), MMI_EVENT_FAILURE, NULL);      
        #elif defined(__COSMOS_MMI_PACKAGE__)
        vapp_java_display_push_popup(STR_JAVA_TIMEALARM_PUSH_INVALID);
        #endif

        return;
    }
     
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (g_mmi_java_push_cntx.option_choice == 0 && FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        g_mmi_java_push_cntx.option_choice = 1;
#ifdef __COSMOS_MMI_PACKAGE__
        vapp_java_display_push_popup(STR_JAVA_ERROR_CODE_NO_CARD);
#else
        mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_NO_CARD, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
#endif
    }
#endif
     
    if (g_mmi_java_push_cntx.option_choice == 0)  /* yes */
    {
        mmi_java_check_push_mid_running_req_struct *req_msg;
        kal_uint32 event_group;
        
        req_msg = (mmi_java_check_push_mid_running_req_struct*) construct_local_para(sizeof(mmi_java_check_push_mid_running_req_struct), TD_CTRL);
        req_msg->mid_storage_name = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mids_storage_name;
        req_msg->mid_id = g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mid_id;
        g_mmi_java_push_cntx.check_mid_running_result = 0;
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ, req_msg);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PUSH_CHECK_RUNNING, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
        if (!mmi_java_push_recv_get_running_cnf())
        {
           #ifndef __COSMOS_MMI_PACKAGE__
            ClearInputEventHandler(MMI_DEVICE_ALL);
           #endif
            g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
            #ifndef __COSMOS_MMI_PACKAGE__
            mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
            #else
            //mmi_vjava_close_push_app();
            #endif
            mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
            return;
        }
        
#if (MAX_VM_INSTANCE_NUM > 1)
        if(g_mmi_java_push_cntx.is_need_to_minimize_midlet)
        {
            kal_int32 curr_running_vm_id = jam_mvm_get_current_vm_id();
            g_mmi_java_push_cntx.is_need_to_minimize_midlet = MMI_FALSE;                
            jam_enter_minimize_mode(curr_running_vm_id, KAL_TRUE);
            mmi_frm_group_close(GRP_ID_JAVA_APP);          
        }    
        
        if(!g_mmi_java_push_cntx.is_terminate_push_midlet)
        {        
            if(g_mmi_java_push_cntx.is_VM_full)
            {
                g_mmi_java_push_cntx.is_VM_full = MMI_FALSE;
                g_mmi_java_push_cntx.vm_status_menu_hilite_idx = 0;
                /* show vm status scren */
                mmi_java_push_enter_vm_status_screen(); 
            } 
            else
            {
                ClearInputEventHandler(MMI_DEVICE_ALL);
                mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_TRUE);
                g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;  
                #ifdef __COSMOS_MMI_PACKAGE__
                if (vapp_launcher_is_active())
                {
                    mmi_java_entry_mid_launch_from_idle();
                }
                else
                #endif
                {
                    mmi_idle_display();
                }
            }                 
        }            
        else
        {
            kal_int32 vm_id;
            g_mmi_java_push_cntx.is_terminate_push_midlet = MMI_FALSE;       
            g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;   
            ClearInputEventHandler(MMI_DEVICE_ALL);
            vm_id = jam_mvm_get_vm_id(g_mmi_java_push_cntx.push_entry[g_mmi_java_push_cntx.processing_idx].mids_storage_name, -1);
            mmi_java_push_launch_ask_terminate_cb(KAL_TRUE, vm_id);            
            #ifndef __COSMOS_MMI_PACKAGE__
            mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);     
            #else
            //mmi_vjava_close_push_app();
            #endif
            return;            
        }
#else
        if (jam_mvm_get_running_count() == 1)
        {
            g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;   
        ClearInputEventHandler(MMI_DEVICE_ALL);
            mmi_java_push_launch_ask_terminate_cb(KAL_TRUE, 0);            
            #ifndef __COSMOS_MMI_PACKAGE__
            mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
            #else
            //mmi_vjava_close_push_app();
            #endif            
            return;
        }
       
        ClearInputEventHandler(MMI_DEVICE_ALL);
        mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_TRUE);
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE;  
        #ifdef __COSMOS_MMI_PACKAGE__
        if (vapp_launcher_is_active())
        {
            mmi_java_entry_mid_launch_from_idle();
        }
        else
        #endif
        {
            mmi_java_set_screen_delete_callback_flag(MMI_FALSE);
            mmi_idle_display();
        }
#endif
    }
    else if(g_mmi_java_push_cntx.option_choice == 1)   /* no */
    {

        ClearInputEventHandler(MMI_DEVICE_ALL);
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
        #ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
        #else
        //mmi_vjava_close_push_app();
        #endif
        mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);

    }
    else if(g_mmi_java_push_cntx.option_choice == 2)   /* ask me later */
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
        #ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
        #else
        //mmi_vjava_close_push_app();
        #endif
        mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_LONG_INTERVAL);

    }
    else
    {
        ASSERT(0);
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_delete_vm_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_delete_vm_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    if (g_mmi_java_push_cntx.is_processing)
    {
#ifdef __PLUTO_MMI_PACKAGE__
        if (mmi_frm_scrn_get_active_id() == SCR_JAVA_TIMEALARM_PUSH_CONFIRM_VT_OPTION)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            if (mmi_frm_scrn_is_present(GRP_ID_JAVA_TIMEALARM_PUSH, SCR_JAVA_TIMEALARM_PUSH_CONFIRM_VT_OPTION, MMI_FRM_NODE_ALL_FLAG))
        {
                mmi_frm_scrn_close(GRP_ID_JAVA_TIMEALARM_PUSH, SCR_JAVA_TIMEALARM_PUSH_CONFIRM_VT_OPTION);
        } 
        }
#elif defined(__COSMOS_MMI_PACKAGE__)
        if (g_mmi_java_push_cntx.is_exit_tskmgr == KAL_TRUE)
        {
            g_mmi_java_push_cntx.is_exit_tskmgr = KAL_FALSE;
            g_mmi_java_push_cntx.option_choice = 0;
            mmi_java_push_confirm_hdlr();
        }
#endif
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_launch_callback
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
void mmi_java_push_launch_callback(U32 session_id, S8 permission, kal_bool execute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_timealarm_push_res_struct *msg;
                #ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_asm_property_struct p;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
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

    g_mmi_java_push_cntx.is_launch = KAL_TRUE;
    
    /* for fix the lock screen issue */
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);  
    
    /* for fix the issue : the midlet is deleted */
    if(g_mmi_java_push_cntx.push_entry_used[session_id])
                {
        if (execute)
        {
            /* for fix the issue : when we will launch java, the incoming call arrives at the same time */
            if(mmi_java_is_in_voice_call())
            {            
                mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_LONG_INTERVAL);
                return;
            }
#if defined(__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    mmi_frm_scrn_enter(
        GRP_ID_ROOT,
        SCR_JAVA_DUMMY,
        NULL,
        mmi_java_push_dummy_entry,
        MMI_FRM_FULL_SCRN);
#endif /* J2ME_SLIM_MEMORY_SUPPORT */
                }
                else
                {
        #ifndef __COSMOS_MMI_PACKAGE__
            mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED), MMI_EVENT_FAILURE, NULL);
        #else
            vapp_java_display_push_popup(STR_JAVA_ERROR_CODE_VERIFY_FAILED);
        #endif
            }

        msg = (mmi_java_timealarm_push_res_struct *) construct_local_para(sizeof(mmi_java_timealarm_push_res_struct), TD_CTRL);

        msg->callback_entry = g_mmi_java_push_cntx.push_entry[session_id].callback_entry;
        msg->execute = execute;
        msg->mid_class_name = g_mmi_java_push_cntx.push_entry[session_id].mid_class_name;
        msg->mid_id = g_mmi_java_push_cntx.push_entry[session_id].mid_id;
        msg->mids_storage_name = g_mmi_java_push_cntx.push_entry[session_id].mids_storage_name;
        msg->mids_permission = permission;
        msg->pushalarm_type = g_mmi_java_push_cntx.push_entry[session_id].pushalarm_type;
        msg->session_id = g_mmi_java_push_cntx.push_entry[session_id].session_id;

    #ifdef __COSMOS_MMI_PACKAGE__
        if(!mmi_frm_group_is_present(APP_JAVA) && execute)
        {
            mmi_frm_group_create_ex(GRP_ID_ROOT, APP_JAVA, NULL, NULL, 0);
            mmi_frm_scrn_enter(APP_JAVA, SCR_JAVA_DUMMY,NULL, mmi_java_push_dummy_entry, MMI_FRM_FULL_SCRN);
            mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA_DUMMY, mmi_java_dummy_entry_leave_proc);
            ShowCategoryDummyScreen();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
            mmi_frm_asm_property_init(&p);
            p.f_prepare_w_reserve = 1;
            p.f_hide_in_oom = 1;
            mmi_frm_asm_set_property(APP_JAVA, &p);
#endif
    #ifdef __MMI_SCREEN_ROTATE__
            mmi_frm_screen_rotate(mmi_frm_get_real_prev_screen_rotate());
    #endif
        }
    #endif
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES, msg);

        delete_time_alarm_event_id(session_id);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_TIMEALARM_PUSH_CALLBACK_ERROR);    
    }
    
    mmi_java_push_repush_and_finish_session(MMI_JAVA_REPUSH_SHORT_INTERVAL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_recv_timealarm_push_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive MMI_JAVA_RECV_TIMEALARM_PUSH_IND
 *  The message means java want to launch a MIDlet for timealarm
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_push_recv_timealarm_push_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 session_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/           
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND);
#ifdef __SUPPORT_JAVA_PUSH__
#ifdef __COSMOS_MMI_PACKAGE__
    if(((mmi_java_timealarm_push_ind_struct*) MsgStruct)->close_dummy_group)
    {
        if (mmi_frm_group_is_present(APP_JAVA))
        {
            mmi_frm_group_close(APP_JAVA);
        }
    }
    if (((mmi_java_timealarm_push_ind_struct*) MsgStruct)->show_busy_popup)
    {
        vapp_java_display_popup(STR_JAVA_VM_BUSY, VJAVA_POPUP_WARNING, VAPP_JAVA_ENTRY_NONE);
    }
#endif
    
    if(((mmi_java_timealarm_push_ind_struct*) MsgStruct)->pushalarm_type != (kal_uint32)-1)
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH);
    
        session_id = new_time_alarm_event_id();

        if (session_id < 0)
        {
            return; /* drop this timealarm event, because there are too many event need to process */
        }

        kal_mem_cpy(
                    &g_mmi_java_push_cntx.push_entry[session_id],
                    (mmi_java_timealarm_push_ind_struct*) MsgStruct,
                    sizeof(mmi_java_timealarm_push_ind_struct));
        if (!g_mmi_java_push_cntx.timer_set)
        {
            MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH_GO);
            mmi_java_push_launch();
        }        
    }
    else
    {
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND_REPUSH_GO);    
        mmi_java_push_launch();
}
#endif
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
#ifdef __SUPPORT_JAVA_PUSH__
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
    
#if defined(__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
        mmi_frm_scrn_enter(
        GRP_ID_ROOT,
        SCR_JAVA_DUMMY,
        NULL,
        mmi_java_push_dummy_entry,
        MMI_FRM_FULL_SCRN); 
#endif /* J2ME_SLIM_MEMORY_SUPPORT */
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_RESEND_TIMEALARM_PUSH_REQ, resend_push_req_ptr);     
#endif
}

#endif /* __J2ME__ */ 

