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
 * AnswerMachineSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for auto answer machine.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "wgui_categories_CM.h" /* for 20 screen */
#include "FileMgrSrvGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "dcl.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Aud_defs.h"
#include "App_datetime.h"
#include "AnswerMachineType.h"
#include "AnswerMachineGprot.h"
#include "AnswerMachineProt.h"

#include "MMIDataType.h"
#include "FontRes.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "mmi_frm_scenario_gprot.h"
#include "DateTimeType.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "device.h"
#include "wgui.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_typedef.h"
#include "GpioSrvGprot.h"
#include "SSCStringHandle.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "mmi_rp_app_autoam_def.h"
#include "UcmSrvGprot.h"

#ifdef __CTM_SUPPORT__
#include "CtmSrvGprot.h"
#endif 

#ifdef __MMI_BT_SUPPORT__
#include "BtcmSrvGprot.h"
#endif 
#include "ReminderSrvGprot.h" /* Reminder or Alaram*/ 

#if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
#include "NetSetAppGprot.h"
#endif

/*
 * function
 */
void (*mmi_autoam_end_call_callback) (mmi_autoam_callback_enum result);

/*
 * Globle variable
 */

extern mmi_autoam_setting_struct g_autoam_setting;
extern mmi_autoam_message_struct g_autoam_message;
mmi_autoam_speech_struct g_autoam_speech;
extern U16 g_autoam_last_valid_name[];

extern U8 g_autoam_msg_buf[];
extern U8 g_autoam_idle_display_flag;
extern U8 g_autoam_idle_number_before_view;
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

extern MMI_BOOL g_autoam_del_all_flag;

U16 g_autoam_in_call_path[MMI_AUTOAM_MAX_FULL_NAME_LEN];
static S8 g_autoam_key_detect_ref;
static S8 g_autoam_key_detect_on;
S32 g_autoam_last_error;

U8 g_autoam_file_header[MMI_AUTOAM_FILE_HEADER_LEN];
static U8 g_autoam_file_unread[MMI_AUTOAM_MAX_REOCRD_NUM];

/*
 * Define
 */

#define MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT 3000
#define MMI_AUTOAM_LOGIN_PASSWD_TIMEOUT 10000   /* user input max interval time */
#define MMI_AUTOAM_MAX_TIMES_PASSWD_INPUT 3     /* MAX try passwd times */

#define MMI_AUTOAM_REMOTE_KEY_PLAY_UNREAD    '1'
#define MMI_AUTOAM_REMOTE_KEY_PLAY_ALL    '2'
#define MMI_AUTOAM_REMOTE_KEY_PLAY_ONE       '3'
#define MMI_AUTOAM_REMOTE_KEY_CONFIRM     '#'

/***************************************************************************** 
 * functions
 ******************************************************************************/
#ifdef ___AUTOAM_MY_DEBUG___

void mmi_autoam_debug_create_dummy_msg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_start_answer_incoming_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_start_answer_incoming_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_autoam_start_answer_incoming((U8*) "123", (U8*) L"aaa", NULL);
}
#endif /* ___AUTOAM_MY_DEBUG___ */ 

#define AUTOAM_EXTERNAL_API


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_get_pickup_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_autoam_get_pickup_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_GET_PICKUP_DURATION, g_autoam_setting.pickup);
    return g_autoam_setting.pickup;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_check_switch_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_check_switch_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        return MMI_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* check if is deleting record */
    if (g_autoam_del_all_flag == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHECK_SWITCH_DELETEING);
        return MMI_FALSE;
    }

    /* check if setting driver is valid */
    if (SRV_FMGR_PUBLIC_DRV == g_autoam_setting.drv_letter)
    {
        if (FS_GetDevStatus(g_autoam_setting.drv_letter, FS_FEATURE_STATE_ENUM) < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHECK_SWITCH_DRIVE_PUBLIC);
            return MMI_FALSE;
        }
    }
    else
    {
        if (((FS_GetDevStatus(g_autoam_setting.drv_letter, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR) ||
             (FS_GetDevStatus(g_autoam_setting.drv_letter, FS_FEATURE_STATE_ENUM) < FS_NO_ERROR)) &&
            (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_FEATURE_STATE_ENUM) < FS_NO_ERROR))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHECK_SWITCH_DRIVE_SETTING);
            return MMI_FALSE;
        }
    }

    mmi_autoam_create_dest_folder();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHEC_SWITCH_ON, g_autoam_setting.turn_on);
    return (MMI_BOOL)g_autoam_setting.turn_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_end_answer_incoming
 * DESCRIPTION
 *  This interface is provide for UCM to stop autoam when the call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_end_answer_incoming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_END_INCOMING, g_autoam_speech.state);

    /* stop record */
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_RECORD)
    {
        g_autoam_speech.state = MMI_AUTOAM_STATE_REMOTE_STOP;
        mdi_audio_stop_record();
    }
    else
    {
        g_autoam_speech.state = MMI_AUTOAM_STATE_REMOTE_STOP;
        mdi_audio_snd_stop();
    }
    /* stop key detect */
    if (g_autoam_key_detect_ref > 0)
    {
        mmi_autoam_stop_key_detection();
    }

    /* close file */
    if (g_autoam_speech.fd > 0)
    {
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
    }
    mmi_autoam_quit_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_end_answer_notify
 * DESCRIPTION
 *  Auto answer machine quit by itself, and notify if call need quit.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_end_answer_notify(mmi_autoam_callback_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_autoam_quit_screen();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_END_NOTIFY, result);
    mmi_autoam_end_call_callback(result);
    if (g_autoam_speech.fd > 0)
    {
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_start_answer_incoming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phone_num           [IN]        
 *  name                [IN]        
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_start_answer_incoming(
            const U8 *phone_num,
            const U8 *name,
            void (*callback_func) (mmi_autoam_callback_enum result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_START_INCOMING);
    /* memorize the call related info */
    ASSERT(phone_num && name);
    mmi_asc_n_to_ucs2((S8*) g_autoam_speech.number, (S8*) phone_num, MMI_AUTOAM_CALL_NUMBER_LEN);
    memcpy(g_autoam_message.number, phone_num, MMI_AUTOAM_CALL_NUMBER_LEN);
    g_autoam_message.sim_no = 0;
 #ifdef __GEMINI__            
    if( (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE, NULL)) > 0)    
    {
        g_autoam_message.sim_no = 1;
    }
    else if( (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM2, NULL)) > 0)
    {
        g_autoam_message.sim_no = 2;
    }
#if (MMI_MAX_SIM_NUM >= 3)    
    else if( (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM3, NULL)) > 0)
    {
        g_autoam_message.sim_no = 3;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if( (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM4, NULL)) > 0)
    {
        g_autoam_message.sim_no = 4;
    }
#endif
#endif

#if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

	mmi_ucs2ncpy((CHAR*)g_autoam_message.sim_name, (CHAR*)mmi_netset_get_sim_name((mmi_sim_enum)g_autoam_message.sim_no), (MMI_NETSET_SIM_NAME_MAX_LEN * 2));

#endif



#endif  /* __MMI_DUAL_SIM_MASTER__ */

    mmi_ucs2ncpy((S8*) g_autoam_speech.name, (S8*) name, MMI_AUTOAM_CALL_NAME_LEN);
    /* init global varialbe */
    g_autoam_key_detect_ref = 0;
    g_autoam_key_detect_on = MMI_AUTOAM_OFF;

    /* init structure */
    g_autoam_speech.message_num_all = 0;
    g_autoam_speech.message_num_unread = 0;
    memset(g_autoam_speech.passwd_buf, 0, MMI_AUTOAM_REMOTE_PASSWD_LEN + 1);
    g_autoam_speech.passwd_count = 0;
    g_autoam_speech.remote_key = 0;
    g_autoam_speech.repeat_count = 0;
    g_autoam_speech.state = MMI_AUTOAM_STATE_IDLE;
    g_autoam_speech.isMute = MMI_AUTOAM_OFF;
    mmi_autoam_end_call_callback = callback_func;

    /* If exist record list screen, quit and release file handler */
    mmi_frm_group_close(GRP_ID_AUTOAM_MESSAGE);

    /* end bg sound */
    mdi_audio_snd_stop();

    /* init language */
    mmi_autoam_init_language_type();

    /* load record file */
    if (!mmi_autoam_file_load_incall(&(g_autoam_speech.fd), &(g_autoam_speech.message_num_all)))
    {
        ASSERT(0);
    }

    /* Get begin time */
    DTGetRTCTime(&g_autoam_speech.begin_time);

#ifndef ___AUTOAM_MY_DEBUG___
    /* entry AutoAM Greeting screen */
    mmi_autoam_entry_greeting_in_call();
#endif /* ___AUTOAM_MY_DEBUG___ */ 
    srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);
    return MMI_TRUE;
}

#define AUTOAM_STATE_SWITCH
/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_entry_greeting_in_call_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_autoam_entry_greeting_in_call_scrn_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
       case EVT_ID_SCRN_DEINIT:
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_GREETING_SCREEN_DELETE_CALLBACK);
	mmi_autoam_set_unmute();	
	break;

    }
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_entry_greeting_in_call
 * DESCRIPTION
 *  Entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_entry_greeting_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_back = mmi_frm_is_in_backward_scenario();
    U8 *guiBuffer = NULL;
    U16 rsk = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTOAM_GREETING, NULL, (void*)NULL);

	mmi_frm_group_enter(GRP_ID_AUTOAM_GREETING, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_scrn_enter(
		GRP_ID_AUTOAM_GREETING,
		SCR_ID_AUTOAM_GREETING,
		NULL,
		mmi_autoam_entry_greeting_in_call,
		MMI_FRM_FULL_SCRN);
	
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (mmi_autoam_loud_option())
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            rsk = STR_ID_AUTOAM_RSK_HANDS_HELD;
        }
        else
        {
            rsk = STR_ID_AUTOAM_RSK_HANDS_FREE;
        }
    }

#if defined(__MMI_MAINLCD_320X480__)
    /* for HVGA */
    wgui_catcall_set_button(get_string(STR_ID_AUTOAM_LSK_ANSWER), mmi_autoam_answer_call_by_hand);
    ShowCategory20Screen(
        STR_ID_AUTOAM_LSK_ANSWER,
        IMG_GLOBAL_OK,
        rsk,
        0,
        NULL,
        (U8*) g_autoam_speech.name,
        (UI_time*) & g_autoam_speech.begin_time,
        0,
        IMG_ID_AUTOAM_GREETING,
        NULL,
        MMI_FALSE,
        guiBuffer);
#else /* defined(__MMI_MAINLCD_320X480__) */ 
    ShowCategory20Screen(
        STR_ID_AUTOAM_LSK_ANSWER,
        IMG_GLOBAL_OK,
        rsk,
        0,
        NULL,
        (U8*) g_autoam_speech.name,
        (UI_time*) & g_autoam_speech.begin_time,
        0,
        IMG_ID_AUTOAM_GREETING,
        NULL,
        MMI_FALSE,
        guiBuffer);
#endif /* defined(__MMI_MAINLCD_320X480__) */ 
    SetLeftSoftkeyFunction(mmi_autoam_answer_call_by_hand, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_autoam_answer_call_by_hand, KEY_EVENT_UP);	
   /* Set RSK to change speaker */
 
mmi_frm_scrn_set_leave_proc(
	GRP_ID_AUTOAM_GREETING,
	SCR_ID_AUTOAM_GREETING,
	mmi_autoam_entry_greeting_in_call_scrn_leave_proc);
   
    SetKeyHandler(mmi_autoam_answer_call_by_hand, KEY_SEND, KEY_EVENT_DOWN);
    if (mmi_autoam_loud_option())
    {
        SetRightSoftkeyFunction(mmi_autoam_set_loud_speaker, KEY_EVENT_UP);
    }

    /* mute microphone */
    mmi_autoam_set_mute();

    if (!is_back)
    {
        mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_GREETING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_greeting_delete_callback
 * DESCRIPTION
 *  this function is the callback function when record screen is deleted
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_autoam_greeting_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_GREETING_SCREEN_DELETE_CALLBACK);
    mmi_autoam_set_unmute();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_record_state_switch
 * DESCRIPTION
 *  record state switch function
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_record_state_switch(mmi_autoam_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_RECORD_STATE, state);
    switch (state)
    {
        case MMI_AUTOAM_STATE_GREETING:
            g_autoam_speech.state = state;
            mmi_autoam_play_greeting();
            break;
        case MMI_AUTOAM_STATE_HINT_TIME:
            g_autoam_speech.state = state;
            if (g_autoam_setting.duration == 0)
            {
                /* unlimit duration, wait for hotkey directly */
                mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT);
            }
            else
            {
                mmi_autoam_play_prompt();
            }
            break;
        case MMI_AUTOAM_STATE_RECORD:
            g_autoam_speech.state = state;
            mmi_autoam_record_in_call();
            break;
        case MMI_AUTOAM_STATE_RECORD_TIMEOUT:
        case MMI_AUTOAM_STATE_RECORD_DISCFULL:
        case MMI_AUTOAM_STATE_GOODBYE:
            g_autoam_speech.state = state;
            mmi_autoam_play_prompt();
            break;
        case MMI_AUTOAM_STATE_RECORD_QUIT:
            g_autoam_speech.state = state;
            mmi_autoam_end_answer_notify(MMI_AUTOAM_CALLBACK_END);
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_login_state_switch
 * DESCRIPTION
 *  Login State switch.
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_login_state_switch(mmi_autoam_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  mmi_frm_node_struct  new_node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_LOGIN_STATE, state);
    switch (state)
    {
        case MMI_AUTOAM_STATE_LOGIN_GREETING:
            g_autoam_speech.state = state;
            /* Set dispaly begin time */
            /* DTGetRTCTime(&g_autoam_speech.begin_time); */
            if (SCR_ID_AUTOAM_GREETING == mmi_frm_scrn_get_active_id())
            {
                mmi_autoam_entry_record_in_call();
            }
            else
            {
    			new_node_info.id = SCR_ID_AUTOAM_RECORD_VOICE_MESSAGE;
    			new_node_info.entry_proc = (mmi_proc_func) &mmi_autoam_entry_record_in_call;
    			mmi_frm_scrn_replace(GRP_ID_AUTOAM_GREETING, SCR_ID_AUTOAM_GREETING, &new_node_info);
         
            }
            mmi_autoam_play_prompt();
            break;
        case MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN:
            g_autoam_speech.state = state;
            g_autoam_speech.passwd_count = 0;
            memset(g_autoam_speech.passwd_buf, 0, 5);
            mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_PASSWD_TIMEOUT);
            break;
        case MMI_AUTOAM_STATE_LOGIN_PASSWD_RECV:
            StopTimer(AUTOAM_TIMER_KEY_DETECT);
            StartTimer(AUTOAM_TIMER_KEY_DETECT, MMI_AUTOAM_LOGIN_PASSWD_TIMEOUT, mmi_autoam_key_detection_timeout);
            g_autoam_speech.state = state;
            break;
        case MMI_AUTOAM_STATE_LOGIN_PASSWD_CHECK:
            g_autoam_speech.repeat_count++;
            if (mmi_autoam_login_passwd_check())
            {
                /* play remote greeting */
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_GREETING);
            }
            else
            {
                if (g_autoam_speech.repeat_count >= MMI_AUTOAM_MAX_TIMES_PASSWD_INPUT)
                {
                    /* input psswd error too many times */
                    mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_GOODBYE);
                }
                else
                {
                    /* play passwd error */
                    g_autoam_speech.state = MMI_AUTOAM_STATE_LOGIN_PASSWD_ERROR;
                    mmi_autoam_play_prompt();
                }
            }
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_remote_state_switch
 * DESCRIPTION
 *  Remote State switch.
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_remote_state_switch(mmi_autoam_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_REMOTE_STATE, state);
    switch (state)
    {
        case MMI_AUTOAM_STATE_REMOTE_GREETING:
            g_autoam_speech.state = state;
            mmi_autoam_play_prompt();
            break;
        case MMI_AUTOAM_STATE_REMOTE_ENTRY:
            g_autoam_speech.message_num_unread = mmi_autoam_file_check_unread(g_autoam_speech.fd, g_autoam_speech.message_num_all);
            if (g_autoam_speech.message_num_unread > 0)
            {
                g_autoam_speech.reset_flag = 1; /* reset play cntx */
                g_autoam_speech.state = MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD;
            }
            else
            {
                g_autoam_speech.state = MMI_AUTOAM_STATE_REMOTE_NO_NEW;
            }
            mmi_autoam_play_prompt();
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_REPLAY_UNREAD:
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL:
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE:
            g_autoam_speech.state = state;
            mmi_autoam_play_prompt();
            break;
        case MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ALL:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ONE:
            g_autoam_speech.state = state;
            if (g_autoam_speech.reset_flag == 1)
            {
                mmi_autoam_reset_play_cnxt();
            }
            bret = mmi_autoam_play_find_next();
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_FIND_NEXT_RET, bret);
            if (bret)
            {
                if (mmi_autoam_play_record_msg() != 0)
                {
                    mmi_autoam_play_msg_callback(888, NULL);
                }
            }
            else
            {
                /* play end */
                g_autoam_speech.state = MMI_AUTOAM_STATE_REMOTE_PLAY_END;
                mmi_autoam_play_prompt();
            }
            break;
        case MMI_AUTOAM_STATE_REMOTE_PLAY_END:
            g_autoam_speech.state = state;
            mmi_autoam_play_prompt();
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_greeting_callback
 * DESCRIPTION
 *  This function is to play greeting file
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_greeting_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_GREETING_CALLBACK, result, g_autoam_speech.state);

    /* if remote user stop call, quit autoam */
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_STOP ||
        g_autoam_speech.state == MMI_AUTOAM_STATE_STOP_BY_ANSWER)
    {
        return;
    }

    if (result == MDI_AUDIO_END_OF_FILE)
    {
        mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_HINT_TIME);
    }
    else
    {
        /* Play file failed, and try to play string */
        mmi_autoam_play_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_ditone_callback
 * DESCRIPTION
 *  This function is .
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_ditone_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_DITONE_CALLBACK, result, g_autoam_speech.state);
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_STOP ||
        g_autoam_speech.state == MMI_AUTOAM_STATE_STOP_BY_ANSWER)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_msg_callback
 * DESCRIPTION
 *  This functon is
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_msg_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_MSG_CALLBACK, result, g_autoam_speech.state);
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_STOP ||
        g_autoam_speech.state == MMI_AUTOAM_STATE_STOP_BY_ANSWER)
    {
        return;
    }
    else if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ONE ||
             g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD ||
             g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ALL)
    {
        /* after play the 2nd di tone, wait 2 second for key detect */
        mmi_autoam_play_di_tone();
        mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_bg_callback
 * DESCRIPTION
 *  This function is the callback function of play greeting file
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_bg_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Play finish */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_BG_CALLBACK, result, g_autoam_speech.state);

    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_STOP ||
        g_autoam_speech.state == MMI_AUTOAM_STATE_STOP_BY_ANSWER)
    {
        return;
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        switch (g_autoam_speech.state)
        {
            /*-------------record state-----------*/
            case MMI_AUTOAM_STATE_GREETING:
                mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_HINT_TIME);
                break;
            case MMI_AUTOAM_STATE_HINT_TIME:
                /* Wait for user remote access kry */
                mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT);
                break;
            case MMI_AUTOAM_STATE_RECORD_DISCFULL:
            case MMI_AUTOAM_STATE_RECORD_TIMEOUT:
                mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_GOODBYE);
                break;
            case MMI_AUTOAM_STATE_GOODBYE:
                mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD_QUIT);
                break;
      /*--------------Remote login-----------*/
            case MMI_AUTOAM_STATE_LOGIN_GREETING:
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN);
                break;
            case MMI_AUTOAM_STATE_LOGIN_PASSWD_ERROR:
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN);
                break;
      /*--------------Remote control-----------*/
            case MMI_AUTOAM_STATE_REMOTE_GREETING:
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_ENTRY);
                break;
            case MMI_AUTOAM_STATE_REMOTE_NO_NEW:
            case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD:
                mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT);       /* wait 2 seconts for key input */
                break;
                /* remote command key 1,2,3 prompt call back */
            case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL:
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_ALL);
                break;
            case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE:
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_ONE);
                break;
            case MMI_AUTOAM_STATE_REMOTE_PRE_REPLAY_UNREAD:
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD);
                break;
                /* play message call back */
            case MMI_AUTOAM_STATE_REMOTE_PLAY_ALL:
            case MMI_AUTOAM_STATE_REMOTE_PLAY_ONE:
            case MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD:
                mmi_autoam_remote_state_switch((mmi_autoam_state_enum)g_autoam_speech.state);
                break;
            case MMI_AUTOAM_STATE_REMOTE_PLAY_END:
                mmi_autoam_start_key_detection(MMI_AUTOAM_LOGIN_COMMOND_TIMEOUT);
                break;
            default:
                ASSERT(0);
                break;
        }
    }
    else
    {
        mmi_autoam_end_answer_notify(MMI_AUTOAM_CALLBACK_END);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_key_detection_callback
 * DESCRIPTION
 *  key detection callback funtion
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_key_detection_callback(S16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_KEY_DETECT_CALLBACK, key, g_autoam_speech.state);
    switch (g_autoam_speech.state)
    {
    /*------------Record state------------*/
        case MMI_AUTOAM_STATE_HINT_TIME:
            if (key == g_autoam_setting.hot_key)
            {
                /* check user put in remote control hot key, and entry log in state */
                mmi_autoam_stop_key_detection();
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_GREETING);
            }
            break;
   /*------------Login state------------*/
        case MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN:
            /* reset passwd info */
            g_autoam_speech.passwd_buf[g_autoam_speech.passwd_count] = (U8) key;
            g_autoam_speech.passwd_count++;
            /* reset key detect time out */
            if (key == MMI_AUTOAM_REMOTE_KEY_CONFIRM)
            {
                mmi_autoam_stop_key_detection();
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_PASSWD_CHECK);
            }
            else
            {
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_PASSWD_RECV);
            }
            break;
        case MMI_AUTOAM_STATE_LOGIN_PASSWD_RECV:
            g_autoam_speech.passwd_buf[g_autoam_speech.passwd_count] = (U8) key;
            g_autoam_speech.passwd_count++;
            if (key == MMI_AUTOAM_REMOTE_KEY_CONFIRM || g_autoam_speech.passwd_count > MMI_AUTOAM_REMOTE_PASSWD_LEN)
            {
                mmi_autoam_stop_key_detection();
                mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_PASSWD_CHECK);
            }
            break;
   /*---------------Remote state---------------*/
        case MMI_AUTOAM_STATE_REMOTE_NO_NEW:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_END:
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ONE:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ALL:
            if (key == MMI_AUTOAM_REMOTE_KEY_PLAY_UNREAD)
            {
                mmi_autoam_stop_key_detection();
                g_autoam_speech.reset_flag = 1;
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PRE_REPLAY_UNREAD);
            }
            else if (key == MMI_AUTOAM_REMOTE_KEY_PLAY_ALL)
            {
                mmi_autoam_stop_key_detection();
                g_autoam_speech.reset_flag = 1;
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL);
            }
            else if (key == MMI_AUTOAM_REMOTE_KEY_PLAY_ONE)
            {
                mmi_autoam_stop_key_detection();
                g_autoam_speech.reset_flag = 1;
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE);
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_key_detection_timeout
 * DESCRIPTION
 *  key detection time out funtion
 * PARAMETERS
 *  void
 *  key(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_key_detection_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_KEY_DETECT_TIMEOUT, g_autoam_speech.state);

    mmi_autoam_stop_key_detection();
    switch (g_autoam_speech.state)
    {
            /* remote access hotkey timeout */
        case MMI_AUTOAM_STATE_HINT_TIME:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD);
            break;
            /* remote access receive passwd timeout */
        case MMI_AUTOAM_STATE_LOGIN_DETECT_BEGIN:
        case MMI_AUTOAM_STATE_LOGIN_PASSWD_RECV:
            mmi_autoam_login_state_switch(MMI_AUTOAM_STATE_LOGIN_PASSWD_CHECK);
            break;
            /* remote access play message */
        case MMI_AUTOAM_STATE_REMOTE_NO_NEW:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_GOODBYE);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD:
            if(g_autoam_key_detect_on == MMI_AUTOAM_OFF)
            {
                mmi_autoam_play_di_tone();  /* hint user key detect time out */
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD);
            }
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ONE:
            if(g_autoam_key_detect_on == MMI_AUTOAM_OFF)
            {
                mmi_autoam_play_di_tone();  /* hint user key detect time out */
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_ONE);
            }            
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL:
        case MMI_AUTOAM_STATE_REMOTE_PLAY_ALL:
            if(g_autoam_key_detect_on == MMI_AUTOAM_OFF)
            {
                mmi_autoam_play_di_tone();  /* hint user key detect time out */
                mmi_autoam_remote_state_switch(MMI_AUTOAM_STATE_REMOTE_PLAY_ALL);
            }            
            break;
        case MMI_AUTOAM_STATE_REMOTE_PLAY_END:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_GOODBYE);
            break;
        default:
            ASSERT(0);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_record_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  key(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_record_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_RECORD_CALLBACK, result, g_autoam_speech.state);

    mmi_autoam_file_write_new_msg();
    mmi_ucs2cpy((S8*) g_autoam_last_valid_name, (S8*) g_autoam_speech.name);
    /* set flag for idle dispaly and status icon */
    g_autoam_idle_display_flag = MMI_TRUE;
    g_autoam_idle_number_before_view++;
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_AUTOAM_REC);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_AUTOAM_UNREAD);
    wgui_status_icon_bar_update();

    /* if remote user stop call, quit autoam */
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_STOP ||
        g_autoam_speech.state == MMI_AUTOAM_STATE_STOP_BY_ANSWER)
    {
        return;
    }

    switch (result)
    {
            /* If file exist, write record list */
        case MDI_AUDIO_SUCCESS:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD_TIMEOUT);
            break;
            /* MAUI_01825857,change to quit state directly */
        case MDI_AUDIO_TERMINATED:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD_QUIT);
            break;
        case MDI_AUDIO_DISC_FULL:
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD_DISCFULL);
            break;
        default:
            g_autoam_last_error = result;
            mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_RECORD_QUIT);
            break;
    }
}

#define AUTOAM_STATE_MDI


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_greeting
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  result(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_greeting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    /* first try to play user self define greeing */
    if (g_autoam_setting.greeting_default != MMI_AUTOAM_GREETING_DEFAULT)
    {
        ASSERT(g_autoam_setting.greeting_filename);

        /* Check if the format is valid for bg sound */
        result = mdi_audio_snd_check_file_format(g_autoam_setting.greeting_filename);
        if (result == MDI_AUDIO_SUCCESS)
        {
            /* Play User defined greeting file once */
            result = mdi_audio_snd_play_file_with_vol_path(
                        (void*)g_autoam_setting.greeting_filename,
                        1,
                        mmi_autoam_play_greeting_callback,
                        NULL,
                        6,
                        MDI_DEVICE_SPEAKER2);

            /* kal_prompt_trace(MOD_MMI,"[AAM] (mdi_audio_snd_play self define greeting) return :%d", result); */

            if (result == MDI_AUDIO_SUCCESS)
            {
                return;
            }
        }

    }
    /* Play greeting file fail, play string */
    mmi_autoam_play_prompt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_prompt
 * DESCRIPTION
 *  This function is to play hint audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // U16 repeat = 0;  /* Play infinite */
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
    MMI_ID_TYPE audio_id = 0;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_PROMPT_ENTRY, g_autoam_speech.state);
    switch (g_autoam_speech.state)
    {
        case MMI_AUTOAM_STATE_GREETING:
            audio_id = MMI_AUTOAM_AUD_GREETING_DEFAULT(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_HINT_TIME:
            if (g_autoam_setting.duration == 30)
            {
                audio_id = MMI_AUTOAM_AUD_HINT_TIME_30SCD(g_autoam_speech.lan_index);
            }
            else if (g_autoam_setting.duration == 60)
            {
                audio_id = MMI_AUTOAM_AUD_HINT_TIME_1MIN(g_autoam_speech.lan_index);
            }
            else if (g_autoam_setting.duration == 180)
            {
                audio_id = MMI_AUTOAM_AUD_HINT_TIME_3MIN(g_autoam_speech.lan_index);
            }
            else if (g_autoam_setting.duration == 300)
            {
                audio_id = MMI_AUTOAM_AUD_HINT_TIME_5MIN(g_autoam_speech.lan_index);
            }
            else
            {
                ASSERT(0);
            }
            break;
        case MMI_AUTOAM_STATE_RECORD_TIMEOUT:
            audio_id = MMI_AUTOAM_AUD_TIMEOUT(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_RECORD_DISCFULL:
            audio_id = MMI_AUTOAM_AUD_DISCFULL(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_GOODBYE:
            audio_id = MMI_AUTOAM_AUD_GOODBYE(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_LOGIN_GREETING:
            audio_id = MMI_AUTOAM_AUD_LOGIN_GREETING(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_LOGIN_PASSWD_ERROR:
            audio_id = MMI_AUTOAM_AUD_LOGIN_PASSWD_ERROR(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_GREETING:
            audio_id = MMI_AUTOAM_AUD_REMOTE_GREETING(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_UNREAD:
            audio_id = MMI_AUTOAM_AUD_REMOTE_PLAY_UNREAD(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_REPLAY_UNREAD:
            audio_id = MMI_AUTOAM_AUD_REMOTE_REPLAY_UNREAD(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ONE:
            audio_id = MMI_AUTOAM_AUD_REMOTE_REPLAY_ONE(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PRE_PLAY_ALL:
            audio_id = MMI_AUTOAM_AUD_REMOTE_REPLAY_ALL(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_NO_NEW:
            audio_id = MMI_AUTOAM_AUD_REMOTE_NO_NEW(g_autoam_speech.lan_index);
            break;
        case MMI_AUTOAM_STATE_REMOTE_PLAY_END:
            audio_id = MMI_AUTOAM_AUD_REMOTE_PLAY_END(g_autoam_speech.lan_index);
            break;
        default:
            ASSERT(0);
            break;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_PROMPT_ID, audio_id);
    audio_data = get_audio(audio_id, &audio_type, &audio_len);
    ASSERT(audio_data);

    
    result = mdi_audio_snd_play_string_with_vol_path_type(
                (void*)audio_data,
                audio_len,
                1,
                audio_type,
                mmi_autoam_play_bg_callback,
                NULL,
                6,
                MDI_DEVICE_SPEAKER2);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_PROMPT_END, result);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_di_tone
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_play_di_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // U16 repeat = 0;  /* Play infinite */
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
    MMI_ID_TYPE audio_id;
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_DITONE_ENTRY, g_autoam_speech.state);
    audio_id = AUD_ID_AUTOAM_DI_TONE;
    audio_data = get_audio(audio_id, &audio_type, &audio_len);
    ASSERT(audio_data);

    
    result = mdi_audio_snd_play_string_with_vol_path_type(
                (void*)audio_data,
                audio_len,
                1,
                audio_type,
                mmi_autoam_play_ditone_callback,
                NULL,
                6,
                MDI_DEVICE_SPEAKER2);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }
    /* sleep 200 ms */
    kal_sleep_task(44);
    mdi_audio_snd_stop();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_DITONE_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_reset_play_cnxt
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_reset_play_cnxt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_autoam_speech.reset_flag = 0;
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ONE)
    {
        g_autoam_speech.total_play_num = 1;
        g_autoam_speech.curr_play_num = 0;
    }
    else if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ALL)
    {
        g_autoam_speech.total_play_num = g_autoam_speech.message_num_all;
        g_autoam_speech.curr_play_num = 0;
        g_autoam_speech.curr_play_index = 0;
    }
    else if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD)
    {
        g_autoam_speech.total_play_num = g_autoam_speech.message_num_unread;
        g_autoam_speech.curr_play_num = 0;
        g_autoam_speech.curr_play_index = 0;
    }
    else
    {
        ASSERT(0);
    }
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_AUTOAM_RESET_PLAY_CNXT,
        g_autoam_speech.state,
        g_autoam_speech.total_play_num);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_find_next
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  result(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_play_find_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_FIND_NEXT, g_autoam_speech.state);
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ONE)
    {
        if (g_autoam_speech.message_num_all == 0 || g_autoam_speech.curr_play_num >= 1)
        {
            return MMI_FALSE;
        }
        else
        {
            g_autoam_speech.curr_play_num++;
            return MMI_TRUE;
        }
    }
    else if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_ALL)
    {
        if (g_autoam_speech.message_num_all == 0 || g_autoam_speech.curr_play_num == g_autoam_speech.message_num_all)
        {
            return MMI_FALSE;
        }
        else
        {
            g_autoam_speech.curr_play_index = g_autoam_speech.curr_play_num;
            g_autoam_speech.curr_play_num++;
            return MMI_TRUE;
        }
    }
    else if (g_autoam_speech.state == MMI_AUTOAM_STATE_REMOTE_PLAY_UNREAD)
    {
        if (g_autoam_speech.message_num_all == 0 || g_autoam_speech.curr_play_num == g_autoam_speech.message_num_unread)
        {
            return MMI_FALSE;
        }
        else
        {
            g_autoam_speech.curr_play_index = g_autoam_file_unread[g_autoam_speech.curr_play_num];
            g_autoam_speech.curr_play_num++;
            return MMI_TRUE;
        }
    }
    else
    {
        ASSERT(0);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_play_record_msg
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_autoam_play_record_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nLen;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G2_APP,
        MMI_TRC_AUTOAM_PLAY_RECORD_MSG,
        g_autoam_speech.curr_play_index,
        g_autoam_speech.state);
    /* get file */
    FS_Seek(
        g_autoam_speech.fd,
        g_autoam_speech.curr_play_index * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN,
        FS_FILE_BEGIN);
    FS_Read(g_autoam_speech.fd, g_autoam_msg_buf, MMI_AUTOAM_FILE_ONE_MSG_LEN, &nLen);
    g_autoam_message.drv_letter = g_autoam_msg_buf[MMI_AUTOAM_FILE_DRIVE_OFFSET];
    mmi_ucs2ncpy(
        (S8*) g_autoam_message.filename,
        (S8*) & g_autoam_msg_buf[MMI_AUTOAM_FILE_NAME_OFFSET],
        MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN);

    memset(g_autoam_in_call_path, 0, MMI_AUTOAM_MAX_FULL_NAME_LEN);
    kal_wsprintf(
        (kal_wchar*) g_autoam_in_call_path,
        "%c:\\%w%w%w%w",
        g_autoam_message.drv_letter,
        MMI_AUTOAM_DEFAULT_FOLDER_ANSWER_MACHINE,
        MMI_AUTOAM_DEFAULT_FOLDER_MESSAGE,
        g_autoam_message.filename,
        L".wav");

    /* play file */
    
    result = mdi_audio_snd_check_file_format((void*)g_autoam_in_call_path);
    if (result != MDI_AUDIO_SUCCESS)
    {
        g_autoam_last_error = result;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_RECORD_MSG_FMT_ERROR, g_autoam_last_error);
        return result;
    }
    result = mdi_audio_snd_play_file_with_vol_path(
                (void*)g_autoam_in_call_path,
                1,
                mmi_autoam_play_msg_callback,
                NULL,
                6,
                MDI_DEVICE_SPEAKER2);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PLAY_RECORD_MSG_RET, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_record_in_call
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_record_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T   rtc_time;
    DCL_HANDLE rtc_handler = 0;
    MDI_RESULT result;
   mmi_frm_node_struct new_node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_RECORD_IN_CALL);
    /* init message structure */
    mmi_ucs2cpy((S8*) g_autoam_message.callername, (S8*) g_autoam_speech.name);
    g_autoam_message.rec_len = 0;
    g_autoam_message.flag = 0;
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE); 
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)& rtc_time);
    DclRTC_Close(rtc_handler);
    kal_sprintf(
        (char*)g_autoam_message.date,
        "20%02d%02d%02d%02d%02d",
        rtc_time.u1Year,
        rtc_time.u1Mon,
        rtc_time.u1Day,
        rtc_time.u1Hour,
        rtc_time.u1Min);
    /* check and set storage */
     if (srv_fmgr_drv_is_valid((U8) (g_autoam_setting.drv_letter))== MMI_TRUE)
    {
        g_autoam_message.drv_letter = g_autoam_setting.drv_letter;
       
    }
    else
    {
        g_autoam_message.drv_letter = SRV_FMGR_PUBLIC_DRV;
    }
    
    /* create file name */
    kal_wsprintf(
        (kal_wchar*) g_autoam_message.filename,
        "M%02d%02d%02d%02d%02d%d",
            rtc_time.u1Mon,
            rtc_time.u1Day,
            rtc_time.u1Hour,
            rtc_time.u1Min,
            rtc_time.u1Sec,
        		0);
    /* change to storage letter later */
    kal_wsprintf(
        (kal_wchar*) g_autoam_in_call_path,
        "%c:\\%w%w%w%w",
        g_autoam_message.drv_letter,
        MMI_AUTOAM_DEFAULT_FOLDER_ANSWER_MACHINE,
        MMI_AUTOAM_DEFAULT_FOLDER_MESSAGE,
        g_autoam_message.filename,
        L".wav");

    /* play hint "di" done */
    mmi_autoam_play_di_tone();

    result = mdi_audio_start_record_with_limit(
                g_autoam_in_call_path,
                MEDIA_WAV_DVI_ADPCM,
                0,
                mmi_autoam_record_callback,
                NULL,
                0,
                g_autoam_setting.duration);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_RECORD_IN_CALL_1, result);
    if (result == MDI_AUDIO_SUCCESS)
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_AUTOAM_REC);
        /* Set dispaly begin time */
        /* DTGetRTCTime(&g_autoam_speech.begin_time); */
        /* if record request ok, entry record screen. */
        if (SCR_ID_AUTOAM_GREETING == mmi_frm_scrn_get_active_id())
        {
            mmi_autoam_entry_record_in_call();
        }
        else
        {
           
            new_node_info.id = SCR_ID_AUTOAM_RECORD_VOICE_MESSAGE;
            new_node_info.entry_proc = (mmi_proc_func) &mmi_autoam_entry_record_in_call;
            mmi_frm_scrn_replace(GRP_ID_AUTOAM_GREETING, SCR_ID_AUTOAM_GREETING, &new_node_info);

        }

    } 
    else if (result == MDI_AUDIO_DISC_FULL)
    {
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
        g_autoam_speech.state = MMI_AUTOAM_STATE_RECORD_DISCFULL;
        mmi_autoam_play_prompt();
    }
    else
    {
        /* invoke end call function */
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
        g_autoam_speech.state = MMI_AUTOAM_STATE_GOODBYE;
        mmi_autoam_play_prompt();
    }
}

#define AUTOAM_OTHER


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_start_key_detection
 * DESCRIPTION
 *  start DTMF key detection
 * PARAMETERS
 *  timeout     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_start_key_detection(S32 timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_START_KEY_DETECT, timeout, g_autoam_speech.state);
    if (g_autoam_key_detect_ref != 0)
        ASSERT(0);
    g_autoam_key_detect_ref++;
    StartTimer(AUTOAM_TIMER_KEY_DETECT, timeout, mmi_autoam_key_detection_timeout);
    if (g_autoam_setting.remote_allow == MMI_AUTOAM_ON)
    {
        if (MDI_AUDIO_SUCCESS == mdi_audio_start_keytone_detect(mmi_autoam_key_detection_callback))
        {
            g_autoam_key_detect_on = MMI_AUTOAM_ON;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_stop_key_detection
 * DESCRIPTION
 *  stop DTMF key detection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_stop_key_detection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_STOP_KEY_DETECT, g_autoam_speech.state);
    g_autoam_key_detect_ref--;
    if (g_autoam_key_detect_ref != 0)
        ASSERT(0);
    StopTimer(AUTOAM_TIMER_KEY_DETECT);
    if (g_autoam_setting.remote_allow == MMI_AUTOAM_ON)
    {
        if (MMI_AUTOAM_ON == g_autoam_key_detect_on)
        {
            mdi_audio_stop_keytone_detect();
            g_autoam_key_detect_on = MMI_AUTOAM_OFF;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_load_incall
 * DESCRIPTION
 *  check if file exist , if not, create new one.
 *  get the file handler, count total file number and load file header.
 * PARAMETERS
 *  file_hdlr_p     [?]     
 *  total_num_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_file_load_incall(S32 *file_hdlr_p, U8 *total_num_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fd;
    U16 filepath[MMI_AUTOAM_MAX_FULL_NAME_LEN];
    MMI_BOOL bret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load record file */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_LOAD_FILE);
    kal_wsprintf((kal_wchar*) filepath, "%w%w", MMI_AUTOAM_SYSTEM_FOLDER, MMI_AUTOAM_DEFAULT_RECORD_LIST_NAME);
    fd = FS_Open((const WCHAR*)filepath, FS_READ_WRITE);
    if (fd >= FS_NO_ERROR)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_LOAD_FILE_EXIST);
        /* check if exist file valid */
        bret = mmi_autoam_file_check_format(fd, total_num_p);
        if (MMI_TRUE == bret)
        {
            *file_hdlr_p = fd;
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHECK_FORMAT_ERROR, g_autoam_last_error);
            /* file broken, rewrite a new one */
            if (MMI_TRUE == mmi_autoam_file_renew(fd))
            {
                *file_hdlr_p = fd;
                *total_num_p = 0;
                return MMI_TRUE;
            }
        }
    }
    else
    {
        g_autoam_last_error = fd;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_LOAD_FILE_UNEXIST, g_autoam_last_error);
        /* file not exist, create new one */
        fd = FS_Open((const WCHAR*)filepath, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (fd >= FS_NO_ERROR)
        {
            if (MMI_TRUE == mmi_autoam_file_renew(fd))
            {
                *file_hdlr_p = fd;
                *total_num_p = 0;
                return MMI_TRUE;
            }
        }
        else
        {
            ASSERT(fd);
        }
    }

    *file_hdlr_p = fd;
    *total_num_p = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_LOAD_FILE_FAIL);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_check_format
 * DESCRIPTION
 *  check if the message file list format is right
 * PARAMETERS
 *  fd          [IN]        
 *  number      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_file_check_format(S32 fd, U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 residue;
    U32 file_size;
    U32 nRW;
    S32 fs_ret;
    U32 temp_1, temp_3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fd > 0);
    *number = 0;
    /* check if file is long enough */
    fs_ret = FS_GetFileSize(fd, &file_size);
    if (fs_ret < FS_NO_ERROR || file_size < MMI_AUTOAM_FILE_HEADER_LEN)
    {
        g_autoam_last_error = fs_ret;
        return MMI_FALSE;
    }
    /* check if header valid */
    fs_ret = FS_Seek(fd, 0, FS_FILE_BEGIN);
    fs_ret = FS_Read(fd, g_autoam_file_header, MMI_AUTOAM_FILE_HEADER_LEN, &nRW);
    if (fs_ret < FS_NO_ERROR || nRW != MMI_AUTOAM_FILE_HEADER_LEN)
    {
        g_autoam_last_error = fs_ret;
        return MMI_FALSE;
    }
    if (g_autoam_file_header[MMI_AUTOAM_FILE_HEADER_LEN - 1] != 0xEE)
    {
        return MMI_FALSE;
    }
    /* check if record format valid */
    temp_1 = MMI_AUTOAM_FILE_HEADER_LEN;    
    temp_3 = file_size - temp_1;
    residue = (file_size - MMI_AUTOAM_FILE_HEADER_LEN) % MMI_AUTOAM_FILE_ONE_MSG_LEN;
    residue = temp_3 % MMI_AUTOAM_FILE_ONE_MSG_LEN;
    if (residue != 0)
    {
        return MMI_FALSE;
    }
    /* check if header info match with record number */
    while ((g_autoam_file_header[i] != 0xFF) && (g_autoam_file_header[i] != 0xEE))
    {
        if (i >= MMI_AUTOAM_FILE_HEADER_LEN)
        {
            return MMI_FALSE;
        }
        i++;
    }
    *number = i;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CHECK_FORMAT_OK, i);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_renew
 * DESCRIPTION
 *  recreate a new message list
 * PARAMETERS
 *  fd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_file_renew(S32 fd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U32 nRW;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fd > 0);
    /* set header data */
    memset(g_autoam_file_header, 0xFF, MMI_AUTOAM_MAX_REOCRD_NUM);
    g_autoam_file_header[MMI_AUTOAM_FILE_HEADER_LEN - 1] = 0xEE;
    /* rewrite file */
    fs_ret = FS_Seek(fd, 0, FS_FILE_BEGIN);
    if (fs_ret >= FS_NO_ERROR)
    {
        fs_ret = FS_Truncate(fd);
        if (fs_ret >= FS_NO_ERROR)
        {
            fs_ret = FS_Write(fd, g_autoam_file_header, MMI_AUTOAM_FILE_HEADER_LEN, &nRW);
            if (fs_ret >= FS_NO_ERROR)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_FILE_RENEW_OK);
                FS_Commit(fd);
                return MMI_TRUE;
            }
        }
    }
    g_autoam_last_error = fs_ret;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_FILE_RENEW_ERROR, g_autoam_last_error);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_find_blank_pos
 * DESCRIPTION
 *  Search the header of record file, find the valid postion,
 *  then read the flag, theck if the record is already invalid.
 * PARAMETERS
 *  fd              [IN]        
 *  pHeader         [?]         
 *  blank_pos       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_file_find_blank_pos(S32 fd, U8 *pHeader, U8 *blank_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_pos = 0;
    U8 total_num = 0;
    U8 count = 0;
    U8 read_flag;
    S32 fs_ret;
    U32 nRW;
    MMI_BOOL flag = MMI_FALSE;
    MMI_BOOL flag_all_protect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fd);
    ASSERT(pHeader);

    /* check total number */
    while ((pHeader[total_num] != 0xFF) && (pHeader[total_num] != 0xEE))
    {
        total_num++;
    }

    /* check if there is blank position between valid records */
    while (temp_pos < total_num)
    {
        for (count = 0; count < total_num; count++)
        {
            if (pHeader[count] == temp_pos)
            {
                /* the position is used, and already record in header */
                flag = MMI_TRUE;
                break;
            }
        }
        if (MMI_TRUE == flag)
        {
            /* try to find next position */
            flag = MMI_FALSE;
            temp_pos++;
        }
        else
        {
            /* find blank position is temp_pos */
            break;
        }
    }
    /* check if the record flag is not valid */
    if (temp_pos < total_num)
    {
        fs_ret = FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
        if (fs_ret < FS_NO_ERROR)
        {
            g_autoam_last_error = fs_ret;
            return MMI_FALSE;
        }
        fs_ret = FS_Read(fd, &read_flag, 1, &nRW);
        if (fs_ret < FS_NO_ERROR)
        {
            g_autoam_last_error = fs_ret;
            return MMI_FALSE;
        }
        if ((read_flag & MMI_AUTOAM_MSG_VALID_FLAG) != 0)
        {
            /* kal_prompt_trace(MOD_MMI,"[AutoAM] (mmi_autoam_file_find_blank_pos) error pos:%d", temp_pos); */
            read_flag &= (U8) ~ MMI_AUTOAM_MSG_VALID_FLAG;
            fs_ret = FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
            FS_Write(fd, &read_flag, 1, &nRW);
            FS_Commit(fd);
        }
    }

    /* total message exceed 100, find the first not protect */
    if (temp_pos >= MMI_AUTOAM_MAX_REOCRD_NUM)
    {
        flag_all_protect = MMI_TRUE;
        for (count = 0; count < MMI_AUTOAM_MAX_REOCRD_NUM; count++)
        {
            temp_pos = pHeader[count];
            fs_ret = FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
            FS_Read(fd, &read_flag, 1, &nRW);
            if ((read_flag & MMI_AUTOAM_MSG_PROTECT_FLAG) == 0)
            {
                /* kal_prompt_trace(MOD_MMI,"[AutoAM] find unprotected pos. pos:%d", temp_pos); */
                read_flag &= (U8) ~ MMI_AUTOAM_MSG_VALID_FLAG;
                FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
                FS_Write(fd, &read_flag, 1, &nRW);
                memcpy(&pHeader[count], &pHeader[count + 1], MMI_AUTOAM_MAX_REOCRD_NUM - 1 - count);
                FS_Seek(fd, 0, FS_FILE_BEGIN);
                FS_Write(fd, pHeader, MMI_AUTOAM_MAX_REOCRD_NUM - 1, &nRW);
                FS_Commit(fd);
                g_autoam_speech.message_num_all = MMI_AUTOAM_MAX_REOCRD_NUM - 1;
                flag_all_protect = MMI_FALSE;
                break;
            }
        }
    }

    if (flag_all_protect)
    {
        temp_pos = pHeader[0];
        /* kal_prompt_trace(MOD_MMI,"[AutoAM] total mssage larger than 100. new_pos:%d", temp_pos); */
        /* set the first message invalid */
        fs_ret = FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
        FS_Read(fd, &read_flag, 1, &nRW);
        read_flag &= (U8) ~ MMI_AUTOAM_MSG_VALID_FLAG;
        fs_ret = FS_Seek(fd, temp_pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
        FS_Write(fd, &read_flag, 1, &nRW);
        /* move header */
        memcpy(&pHeader[0], &pHeader[1], MMI_AUTOAM_MAX_REOCRD_NUM - 1);
        FS_Seek(fd, 0, FS_FILE_BEGIN);
        FS_Write(fd, pHeader, MMI_AUTOAM_MAX_REOCRD_NUM - 1, &nRW);
        FS_Commit(fd);
        /* the num_all is current total number, so do not include next write message. */
        g_autoam_speech.message_num_all = MMI_AUTOAM_MAX_REOCRD_NUM - 1;
    }

    *blank_pos = temp_pos;
    return MMI_TRUE;
}

#if defined (___AUTOAM_MY_DEBUG___)
void mmi_autoam_debug_create_dummy_msg()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nLen;
    U8 flag = MMI_AUTOAM_MSG_VALID_FLAG;
    U8 end_tag = MMI_AUTOAM_FILE_END_TAG;
    S32 ret;
    U8 pos;
    U32 milliseconds;
    S32 residue;

#ifdef ___AUTOAM_MY_DEBUG___
    S32 i = 1000;
    U16 filepath[MMI_AUTOAM_MAX_FULL_NAME_LEN];
    S32 fd;
	S32 pos_idx = 0;
#endif /* ___AUTOAM_MY_DEBUG___ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_autoam_message.drv_letter = SRV_FMGR_PUBLIC_DRV;
    i = rand();
    kal_wsprintf((kal_wchar*) g_autoam_message.filename, "%d", i);
    g_autoam_message.rec_len = i / 1000;
    residue = i % 1000;
    if (residue >= 500)
    {
        g_autoam_message.rec_len++;
    }
    g_autoam_message.sim_no = 3;
	mmi_ucs2ncpy((CHAR*)g_autoam_message.sim_name, (CHAR*)mmi_netset_get_sim_name(3), MMI_NETSET_SIM_NAME_MAX_LEN);

    kal_wsprintf((kal_wchar*) g_autoam_message.callername, "CN%d", i);
    kal_sprintf((kal_char*) g_autoam_message.number, "%d", i);
    memcpy(g_autoam_message.date, "200809070101", 12);
    kal_wsprintf(
        (kal_wchar*) filepath,
        "%c:\\%w%w%w%w",
        g_autoam_message.drv_letter,
        MMI_AUTOAM_DEFAULT_FOLDER_ANSWER_MACHINE,
        MMI_AUTOAM_DEFAULT_FOLDER_MESSAGE,
        g_autoam_message.filename,
        L".wav");
    fd = FS_Open((const WCHAR*)filepath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    FS_Close(fd);
	

	for(pos_idx = 0; pos_idx < MMI_AUTOAM_MAX_REOCRD_NUM - 1; pos_idx++)
	{
	    FS_Write(g_autoam_speech.fd, &flag, 1, &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.sim_no, 1, &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.drv_letter, 1, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.filename, (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * 2), &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.rec_len, 2, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.date, 12, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.callername, (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * 2), &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.number, MMI_AUTOAM_CALL_NUMBER_LEN, &nLen);
		#if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
		FS_Write(g_autoam_speech.fd, g_autoam_message.sim_name, (MMI_NETSET_SIM_NAME_MAX_LEN * 2), &nLen);
		#endif
        FS_Write(g_autoam_speech.fd, &end_tag, 1, &nLen);
		g_autoam_file_header[pos_idx] = pos_idx;
	}
	   FS_Seek(g_autoam_speech.fd, 0, FS_FILE_BEGIN);
	   FS_Write(g_autoam_speech.fd, g_autoam_file_header, MMI_AUTOAM_FILE_HEADER_LEN, &nLen);


    FS_Close(g_autoam_speech.fd);
    g_autoam_speech.fd = 0;
 
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_write_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  key(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_file_write_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nLen;
    U8 flag = MMI_AUTOAM_MSG_VALID_FLAG;
    U8 end_tag = MMI_AUTOAM_FILE_END_TAG;
    S32 ret;
    U8 pos;
    U32 milliseconds;
    S32 residue;

#ifdef ___AUTOAM_MY_DEBUG___
    S32 i;
    U16 filepath[MMI_AUTOAM_MAX_FULL_NAME_LEN];
    S32 fd;
#endif /* ___AUTOAM_MY_DEBUG___ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_WRITE_NEW_MSG, g_autoam_speech.state);

    mmi_autoam_file_find_blank_pos(g_autoam_speech.fd, g_autoam_file_header, &pos);
    ret = mdi_audio_get_duration(g_autoam_in_call_path, &milliseconds);
    g_autoam_message.rec_len = (ret == MDI_AUDIO_SUCCESS ? milliseconds / 1000 : 0);
    residue = milliseconds % 1000;
    if (residue >= 500)
    {
        g_autoam_message.rec_len++;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_WRITE_NEW_MSG_1, pos, g_autoam_message.rec_len);

#ifdef ___AUTOAM_MY_DEBUG___
    /* ----------------------------for UT------------------------- */
    g_autoam_message.drv_letter = SRV_FMGR_PUBLIC_DRV;
    i = rand();
    kal_wsprintf((kal_wchar*) g_autoam_message.filename, "%d", i);
    g_autoam_message.rec_len = i / 1000;
    residue = i % 1000;
    if (residue >= 500)
    {
        g_autoam_message.rec_len++;
    }

    kal_wsprintf((kal_wchar*) g_autoam_message.callername, "CN%d", i);
    kal_sprintf((kal_char*) g_autoam_message.number, "%d", i);
    memcpy(g_autoam_message.date, "200809070101", 12);
    kal_wsprintf(
        (kal_wchar*) filepath,
        "%c:\\%w%w%w%w",
        g_autoam_message.drv_letter,
        MMI_AUTOAM_DEFAULT_FOLDER_ANSWER_MACHINE,
        MMI_AUTOAM_DEFAULT_FOLDER_MESSAGE,
        g_autoam_message.filename,
        L".wav");
    fd = FS_Open((const WCHAR*)filepath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    FS_Close(fd);

    /* ------------------------------------------------------------------ */
#endif /* ___AUTOAM_MY_DEBUG___ */ 

    ret = FS_Seek(g_autoam_speech.fd, pos * MMI_AUTOAM_FILE_ONE_MSG_LEN + MMI_AUTOAM_FILE_HEADER_LEN, FS_FILE_BEGIN);
    if (ret >= FS_NO_ERROR)
    {
        FS_Write(g_autoam_speech.fd, &flag, 1, &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.sim_no, 1, &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.drv_letter, 1, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.filename, (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * 2), &nLen);
        FS_Write(g_autoam_speech.fd, &g_autoam_message.rec_len, 2, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.date, 12, &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.callername, (MMI_AUTOAM_MAX_DISPLAY_FILE_NAME_LEN * 2), &nLen);
        FS_Write(g_autoam_speech.fd, g_autoam_message.number, MMI_AUTOAM_CALL_NUMBER_LEN, &nLen);
        #if defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        FS_Write(g_autoam_speech.fd, g_autoam_message.sim_name, (MMI_NETSET_SIM_NAME_MAX_LEN * 2), &nLen);
        #endif
        FS_Write(g_autoam_speech.fd, &end_tag, 1, &nLen);
    }
    else
    {
        g_autoam_last_error = ret;
    }

    /* refresh header */
    if (g_autoam_speech.message_num_all >= MMI_AUTOAM_MAX_REOCRD_NUM)
    {
        g_autoam_speech.message_num_all = MMI_AUTOAM_MAX_REOCRD_NUM - 1;
    }
    FS_Seek(g_autoam_speech.fd, g_autoam_speech.message_num_all, FS_FILE_BEGIN);
    FS_Write(g_autoam_speech.fd, &pos, 1, &nLen);

    FS_Close(g_autoam_speech.fd);
    g_autoam_speech.fd = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_WRITE_NEW_MSG_2, nLen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_file_check_unread
 * DESCRIPTION
 *  This function is to count unread file number
 * PARAMETERS
 *  fd              [IN]        
 *  total_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_autoam_file_check_unread(S32 fd, U8 total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 pos = 0;
    U8 count = 0;
    U8 flag = 0;
    S32 fs_ret;
    U32 nLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fd);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_FILE_CHECK_UNREAD, total_num);
    memset(g_autoam_file_unread, 0, MMI_AUTOAM_MAX_REOCRD_NUM);
    for (; i < total_num; i++)
    {
        pos = g_autoam_file_header[i];
        fs_ret = FS_Seek(fd, MMI_AUTOAM_FILE_HEADER_LEN + (pos * MMI_AUTOAM_FILE_ONE_MSG_LEN), FS_FILE_BEGIN);
        if (fs_ret < FS_NO_ERROR)
        {
            g_autoam_last_error = fs_ret;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_FILE_CHECK_UNREAD_ERROR, g_autoam_last_error);
            continue;
        }
        FS_Read(fd, &flag, 1, &nLen);
        /* if the record is unread, count+1 and save to unread array */
        if ((flag & MMI_AUTOAM_MSG_READ_FLAG) == 0)
        {
            g_autoam_file_unread[count] = pos;
            count++;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_FILE_CHECK_UNREAD_RET, count);
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_login_passwd_check
 * DESCRIPTION
 *  This function is check if user input right passwd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_login_passwd_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PASSWD_CHECK);
    /* check if the last byte is '#' */
    if (g_autoam_speech.passwd_buf[MMI_AUTOAM_REMOTE_PASSWD_LEN] != MMI_AUTOAM_REMOTE_KEY_CONFIRM)
    {
        MMI_TRACE(
            MMI_MEDIA_TRC_G2_APP,
            MMI_TRC_AUTOAM_PASSWD_CHECK_1,
            g_autoam_speech.passwd_buf[0],
            g_autoam_speech.passwd_buf[1],
            g_autoam_speech.passwd_buf[2],
            g_autoam_speech.passwd_buf[3],
            g_autoam_speech.passwd_buf[MMI_AUTOAM_REMOTE_PASSWD_LEN]);
        return MMI_FALSE;
    }

    if (0 == memcmp(g_autoam_speech.passwd_buf, g_autoam_setting.password, MMI_AUTOAM_REMOTE_PASSWD_LEN))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_PASSWD_CHECK_2);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(
            MMI_MEDIA_TRC_G2_APP,
            MMI_TRC_AUTOAM_PASSWD_CHECK_3,
            g_autoam_setting.password[0],
            g_autoam_setting.password[1],
            g_autoam_setting.password[2],
            g_autoam_setting.password[3],
            g_autoam_speech.passwd_buf[0],
            g_autoam_speech.passwd_buf[1],
            g_autoam_speech.passwd_buf[2],
            g_autoam_speech.passwd_buf[3],
            g_autoam_speech.passwd_buf[MMI_AUTOAM_REMOTE_PASSWD_LEN]);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_quit_screen
 * DESCRIPTION
 *  Auto answer machine clear itself's screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_quit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_QUIT_SCREEN);
    mmi_frm_group_close(GRP_ID_AUTOAM_GREETING);
    srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_TRUE); 	

}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_init_language_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_init_language_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) ||
        !strcmp((S8*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
    {
        g_autoam_speech.lan_index = AUD_ID_LANGUAGE_1_BEGIN;
    }
    else
    {
        g_autoam_speech.lan_index = AUD_ID_LANGUAGE_DEFAULT_BEGIN;
    }

}

#define CALL_RELATED
/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_entry_record_in_call_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_autoam_entry_record_in_call_scrn_leave_proc(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(info->evt_id  == EVT_ID_SCRN_DEINIT)
    {
		if (g_autoam_speech.state == MMI_AUTOAM_STATE_RECORD)
		{
			mdi_audio_stop_record();
		}
		else
		{
			#if defined(BGSND_ENABLE)
			mdi_audio_snd_stop();
			#endif 
		}
		/* close file */
		if (g_autoam_speech.fd > 0)
		{
			FS_Close(g_autoam_speech.fd);
			g_autoam_speech.fd = 0;
		}
		/* stop key detect */
		if (g_autoam_key_detect_ref > 0)
		{
			mmi_autoam_stop_key_detection();
		}
		mmi_autoam_set_unmute();

    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_entry_record_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  result(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_entry_record_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 rsk = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    	mmi_frm_scrn_enter(
		GRP_ID_AUTOAM_GREETING,
		SCR_ID_AUTOAM_RECORD_VOICE_MESSAGE,
		NULL,
		mmi_autoam_entry_record_in_call,
		MMI_FRM_FULL_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (mmi_autoam_loud_option())
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            rsk = STR_ID_AUTOAM_RSK_HANDS_HELD;
        }
        else
        {
            rsk = STR_ID_AUTOAM_RSK_HANDS_FREE;
        }
    }

#if defined(__MMI_MAINLCD_320X480__)
    /* for HVGA */
    wgui_catcall_set_button(get_string(STR_ID_AUTOAM_LSK_ANSWER), mmi_autoam_answer_call_by_hand);
    ShowCategory20Screen(
        STR_ID_AUTOAM_LSK_ANSWER,
        IMG_GLOBAL_OK,
        rsk,
        0,
        NULL,
        (U8*) g_autoam_speech.name,
        (UI_time*) & g_autoam_speech.begin_time,
        0,
        IMG_ID_AUTOAM_BACKGROUND,
        NULL,
        MMI_FALSE,
        guiBuffer);
#else /* defined(__MMI_MAINLCD_320X480__) */ 
    ShowCategory20Screen(
        STR_ID_AUTOAM_LSK_ANSWER,
        IMG_GLOBAL_OK,
        rsk,
        0,
        NULL,
        (U8*) g_autoam_speech.name,
        (UI_time*) & g_autoam_speech.begin_time,
        0,
        IMG_ID_AUTOAM_BACKGROUND,
        NULL,
        MMI_FALSE,
        guiBuffer);
#endif /* defined(__MMI_MAINLCD_320X480__) */ 
    SetLeftSoftkeyFunction(mmi_autoam_answer_call_by_hand, KEY_EVENT_UP);
     ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
     SetCenterSoftkeyFunction(mmi_autoam_answer_call_by_hand, KEY_EVENT_UP);
    
     mmi_frm_scrn_set_leave_proc(
		GRP_ID_AUTOAM_GREETING,
		SCR_ID_AUTOAM_RECORD_VOICE_MESSAGE,
		mmi_autoam_entry_record_in_call_scrn_leave_proc);
	 
    SetKeyHandler(mmi_autoam_answer_call_by_hand, KEY_SEND, KEY_EVENT_DOWN);
    if (mmi_autoam_loud_option())
    {
        SetRightSoftkeyFunction(mmi_autoam_set_loud_speaker, KEY_EVENT_UP);
    }

    /* Delete Greeting Screen */
    mmi_frm_scrn_close(GRP_ID_AUTOAM_GREETING, SCR_ID_AUTOAM_GREETING);

    mmi_autoam_set_mute();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_set_mute
 * DESCRIPTION
 *  this function is switch off microphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_set_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set microphone mute */
    if (MMI_AUTOAM_OFF == g_autoam_speech.isMute)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_SET_MUTE);
        g_autoam_speech.isMute = MMI_AUTOAM_ON;
        /* L1SP_SetMicrophoneVolume(0); */
        mdi_audio_set_volume(MDI_VOLUME_MIC, MDI_AUD_VOL_MUTE(0));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_set_unmute
 * DESCRIPTION
 *  this function is switch on microphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_set_unmute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_AUTOAM_ON == g_autoam_speech.isMute)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_SET_UNMUTE);
        g_autoam_speech.isMute = MMI_AUTOAM_OFF;
        mdi_audio_set_mic_volume();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_loud_option
 * DESCRIPTION
 *  this function is switch on microphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_autoam_loud_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    if (srv_bt_cm_is_incall_aud_swap2bt() == TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_AUDIO_SWAP2BT);
        return MMI_FALSE;
    }
#endif /* __MMI_BT_SUPPORT__ */ 
#ifdef __CTM_SUPPORT__
    if (srv_ctm_is_opened_as_manual_mode() == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_CTM_IS_OPEN);
        return MMI_FALSE;
    }
#endif /* __CTM_SUPPORT__ */ 

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_record_delete_callback
 * DESCRIPTION
 *  this function is the callback function when record screen is deleted
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_autoam_record_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_autoam_speech.state == MMI_AUTOAM_STATE_RECORD)
    {
        mdi_audio_stop_record();
    }
    else
    {
    #if defined(BGSND_ENABLE)
        mdi_audio_snd_stop();
    #endif 
    }
    /* close file */
    if (g_autoam_speech.fd > 0)
    {
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
    }
    /* stop key detect */
    if (g_autoam_key_detect_ref > 0)
    {
        mmi_autoam_stop_key_detection();
    }

    mmi_autoam_set_unmute();

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_set_loud_speaker
 * DESCRIPTION
 *  Turn on and turn off loud speaker in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_set_loud_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
    {
        ChangeRightSoftkey(STR_ID_AUTOAM_RSK_HANDS_FREE, 0);
        srv_speech_disable_hand_free();
        mmi_popup_display(
            (WCHAR*) ((UI_string_type) GetString(STR_ID_AUTOAM_LOUD_SPEAKER_OFF)),
            MMI_EVENT_SUCCESS,
            NULL);
    }
    else
    {
        ChangeRightSoftkey(STR_ID_AUTOAM_RSK_HANDS_HELD, 0);
        srv_speech_enable_hand_free();
        mmi_popup_display(
            (WCHAR*) ((UI_string_type) GetString(STR_ID_AUTOAM_LOUD_SPEAKER_ON)),
            MMI_EVENT_SUCCESS,
            NULL);
    }
    /* L1SP_SetMicrophoneVolume(0); */
    mdi_audio_set_volume(MDI_VOLUME_MIC, MDI_AUD_VOL_MUTE(0));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_autoam_answer_call_by_hand
 * DESCRIPTION
 *  press LSK to answer the call by hand
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_autoam_answer_call_by_hand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUTOAM_ANSWER_BY_HAND, g_autoam_speech.state);

    if (g_autoam_speech.state == MMI_AUTOAM_STATE_RECORD)
    {
        g_autoam_speech.state = MMI_AUTOAM_STATE_STOP_BY_ANSWER;
        mdi_audio_stop_record();
    }
    else
    {
        g_autoam_speech.state = MMI_AUTOAM_STATE_STOP_BY_ANSWER;
        mdi_audio_snd_stop();
    }
    /* stop key detect */
    if (g_autoam_key_detect_ref > 0)
    {
        mmi_autoam_stop_key_detection();
    }
    /* close file */
    if (g_autoam_speech.fd > 0)
    {
        FS_Close(g_autoam_speech.fd);
        g_autoam_speech.fd = 0;
    }
    mmi_autoam_end_answer_notify(MMI_AUTOAM_CALLBACK_NONE);
}

#endif /* __MMI_AUTO_ANSWER_MACHINE__ */ 

