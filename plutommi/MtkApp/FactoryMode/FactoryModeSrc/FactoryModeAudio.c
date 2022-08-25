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
 * FactoryModeAudio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Audio, it include Echo loop, MIC Echo loop, Loudspk,
 *   Ringtone, MTBF, headset, Recevier...
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
 ********************************************************************************/
 #include "MMI_features.h"
	 
#ifdef __MMI_FACTORY_MODE__
/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "ps_public_struct.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "nvram_defs.h"
#include "gui.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_msg_struct.h"
#include "AlarmFrameworkProt.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "SensorSrvGport.h"


#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PixcomFontEngine.h"

#include "resource_audio.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"

#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "fmt_struct.h"

#include "mmi_rp_srv_gpio_def.h"
#include "wgui_categories.h"
#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
#include "l1audio.h"
#endif

#include "dcl.h"

#include "init.h"
#include "device.h"
#include "custom_em.h"

#include "custom_equipment.h"
//#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "lcd_sw_inc.h"
#include "resource_verno.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

#ifdef __MMI_FM_RADIO__
#include "aud_defs.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_fmrdo_def.h"
#endif /*__PLUTO_MMI_PACKAGE__*/
#endif

#include "adc_channel.h"
#include "ShutdownSrvGprot.h"

#include "mmi_rp_app_factorymode_def.h"
#include "MenuCuiGprot.h"
#include "FactoryModeGProt.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"

#ifdef __MMI_CLIPBOARD__
#include "ImeGprot.h"
#endif /* __MMI_CLIPBOARD__ */


/* amp over current protect*/
#include "aud_main.h"
#include "l1audio.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/*Radio*/
#ifdef __MMI_FM_RADIO__
#ifdef __COSMOS_MMI_PACKAGE__
    #define MMI_FM_RADIO_INDICATE "Fre+:  END\nFre-:  SEND\nVol+:  VOL UP\nVol-:  VOL DOWN"
    #define MMI_FM_RADIO_INDICATE_LEN   150
    #define MMI_FM_RADIO_STRING_LEN 110 + MMI_FM_RADIO_INDICATE_LEN
#else
    #define MMI_FM_RADIO_STRING_LEN 110
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif 

/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/

/***************************************************************************** 
* global val / function
*****************************************************************************/
extern MMI_ID g_fm_gourp_id;
extern mmi_fm_item_cntxt_struct *g_fm_contxt;

MMI_BOOL g_fm_echoloop2_need_close = MMI_FALSE;

/*-------------- MTBF---------------- */

#pragma arm section rodata = "SECONDARY_RODATA"

static const device_tones_struct SPK_test_tone[FM_MTBF_SPK_MAX] = 
{
    {400, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 1},
    {600, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 2},
    {800, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 3},
    {850, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 4},
    {850, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 5},
    {900, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 6},
    {1000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 7},
    {2000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 8},
    {4000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 9},
    {8000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 0}
};

#pragma arm section rodata


static const device_tones_struct REV_test_tone[FM_MTBF_REV_MAX] = 
{
    {400, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 1},
    {500, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 2},
    {600, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 3},
    {600, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 4},
    {700, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 5},
    {800, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 6},
    {1000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 7},
    {1500, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 8},
    {2000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 9},
    {3000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 0}
};


/***************************************************************************** 
* static  function
*****************************************************************************/
static void FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_ENUM status);
static void mmi_fm_set_echo_loop(U32 state, U16 s, kal_bool on);
static void mmi_fm_set_headset(MMI_BOOL HeadsetTestOn, audio_mode_enum mode,kal_bool on, U16 s );
static void mmi_fm_MTBF_tone_callback(kal_uint32 arg1, void *arg2);
static void mmi_fm_play_MTBF_tone(device_tones_struct *table);
static void mmi_fm_exe_mtbf(void);
#ifdef __MMI_FM_MTBF__
static void mmi_fm_exit_mtbf(void);
static void mmi_fm_stop_mtbf(void);
#endif /* __MMI_FM_MTBF__ */

/* Radio */
static void FmFMRadioLeftArrowHdlr(void);
static void FmFMRadioRightArrowHdlr(void);
static void FmFMRadioUpArrowHdlr(void);
static void FmFMRadioDownArrowHdlr(void);

static void mmi_fm_update_radio_scrn(void);
static void EntryFMRADIOChannelTest(void);
static void FmFMRadioLeftArrowHdlr(void);
static void FmFMRadioRightArrowHdlr(void);
static void FmFMRadioUpArrowHdlr(void);
static void FmFMRadioDownArrowHdlr(void);

#ifdef __PLUTO_MMI_PACKAGE__

static void mmi_fm_set_radio_test(U16 nDataItemId, U16 str_id, U8 index);
#else
static void mmi_fm_set_radio_test(U16 text_id, U8 index);
#endif

void mmi_fm_setloud_spk(U8 flag,MMI_BOOL LoudSpkTestOn,U8 mode,U16 s);
extern void FM_SetGpioReq(U8 type, U8 level);
extern void FM_SetGpioLEDReq(U8 level);
extern void FM_SetGpioVirbateReq(U8 level);
extern void FM_SetGpioLEDReq(U8 level);

/***************************************************************************** 
* Code body
*****************************************************************************/
#define MMI_FM_AUDIO_UTIL_FUNC
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_loopback
 * DESCRIPTION
 *	Because of HAL rule, custom_em_set_loopback must be move to here,
 *  and rename mmi_fm_set_loopback.This function will be run in MED task.
 * PARAMETERS
 *  on      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_set_loopback(kal_uint32 on, void* arg )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__TC01__) && defined(__ACOUSTIC_LOOPBACK_SUPPORT__) && defined(__MTK_TARGET__)
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
#else
    if (on)
    {
     	L1SP_SetAfeLoopback(KAL_TRUE);
		L1SP_Afe_On(L1SP_AFE_MODE_UL_OPEN | L1SP_AFE_MODE_DL_OPEN);
    }
    else
    {
    	L1SP_Afe_Off();
		L1SP_SetAfeLoopback(KAL_FALSE);
    }
#endif
}


extern void mmi_fm_set_loopback2(kal_uint32 on, void* arg )
{
	if (on)
	{
		L1SP_SetAfeLoopback2(KAL_TRUE);
     	L1SP_Afe_On(L1SP_AFE_MODE_UL_OPEN | L1SP_AFE_MODE_DL_OPEN);
	}
	else
	{
		L1SP_SetAfeLoopback2(KAL_FALSE);
        L1SP_Afe_Off();
	}
	 
}

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
extern void mmi_fm_set_acoustic_loopback(kal_uint32 on, void* arg )
{
	if (on)
	{
	  L1SP_SetInputSource(L1SP_MICROPHONE1);
	  L1SP_SetOutputDevice(L1SP_SPEAKER2);
      ABF_SetAcousticLoopback(KAL_TRUE);

	}
	else
	{
		ABF_SetAcousticLoopback(KAL_FALSE);
	}
}

extern void mmi_fm_set_disable_2mic_nr_back(kal_uint32 on, void* arg )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* make remake media  */
    if (on)
    {  
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_set_disable_2mic_nr_back on");
	    L1SP_SetInputSource(L1SP_MICROPHONE1);
	    L1SP_SetOutputDevice(L1SP_SPEAKER2);
        L1SP_SetDualMicNR(KAL_FALSE);
        ABF_SetAcousticLoopback(KAL_TRUE);
    }
    else
    {
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_set_disable_2mic_nr_back off");
        L1SP_SetDualMicNR(KAL_TRUE);
        ABF_SetAcousticLoopback(KAL_FALSE);
    }

}
#endif

#define MMI_AUDIO_SEND_MSG

/*****************************************************************************
 * FUNCTION
 *	FM_SendSetAudioModeReq
 * DESCRIPTION
 *	
 * PARAMETERS
 *	mode		[IN]		
 * RETURNS
 *	void
 *****************************************************************************/
extern void FM_SendSetAudioModeReq(U8 mode)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mdi_audio_set_audio_mode(mode);
}

/*****************************************************************************
 * FUNCTION
 *	FM_SendStopAudioReq
 * DESCRIPTION
 *	
 * PARAMETERS
 *	index		[IN]		
 * RETURNS
 *	void
 *****************************************************************************/
extern void FM_SendStopAudioReq(U8 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/*
	 * mmi_eq_stop_audio_req_struct* msg_p;
	 * 
	 * msg_p = OslConstructDataPtr(sizeof(mmi_eq_stop_audio_req_struct));
	 * msg_p->sound_id = index+MIN_MIDI_ID;
	 * FM_SendMsg(MSG_ID_MMI_EQ_STOP_AUDIO_REQ, msg_p, NULL);
	 */
	srv_profiles_stop_tone(SRV_PROF_TONE_FM);
}

#define MMI_FM_ECHO_LOOP

/*--------   Echo loop -------- */

/*****************************************************************************
 * FUNCTION
 *  FM_RestoreAudio
 * DESCRIPTION
 *  It will be used by GPIO and FM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_RestoreAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_eachloop_struct * eachloop_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eachloop_cntx = &(g_fm_contxt->eachloop_contxt);
    
    if (g_fm_contxt->loudspk_contxt.LoudSpkTestOn || 
        eachloop_cntx->ReceiverTestOn)
    {
        mdi_audio_stop_id(TONE_KEY_NORMAL);
    }
    if (eachloop_cntx->EchoLoopTestOn || 
        eachloop_cntx->HeadsetTestOn)
    {
        //mmi_fm_set_loopback(KAL_FALSE);
        
        aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback,
				KAL_FALSE,
				NULL);
    }
    if (eachloop_cntx->RingToneTestOn)
    {
        FM_SendStopAudioReq(0);
    }

    /* MTK Brian modified for deinit special mode, 2003/12/03 */
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
}

/*****************************************************************************
 * FUNCTION
 *  FM_RESET_AUDIO_STATE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_ENUM status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_eachloop_struct * eachloop_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eachloop_cntx = &(g_fm_contxt->eachloop_contxt);
    
    if ((eachloop_cntx->g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_ECHOLOOP) &&
       (status != FM_AUDIO_TEST_STAT_ECHOLOOP))
    {
        eachloop_cntx->EchoLoopTestOn = MMI_FALSE;
    }
    else if ((eachloop_cntx->g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_RINGTONE) &&
            (status != FM_AUDIO_TEST_STAT_RINGTONE))
    {
        eachloop_cntx->RingToneTestOn = FALSE;
    }
    else if((eachloop_cntx->g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_RECEIVER) && 
        (status != FM_AUDIO_TEST_STAT_RECEIVER)) 
    {
        eachloop_cntx->ReceiverTestOn = FALSE;
    }
    eachloop_cntx->g_FM_AUDIO_TEST_STATUS = status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_echo_loop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_set_echo_loop(U32 state, U16 s, kal_bool on)
{
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    /* open loopback */
    kal_sleep_task(kal_milli_secs_to_ticks(200));
	L1SP_SetOutputVolume(196,0);
    mmi_frm_kbd_set_tone_state((mmi_frm_kbd_tone_state_enum)state);

   // mmi_fm_set_loopback(on);
           aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback,
				on,
				NULL);

    change_left_softkey(s, 0); 
}
/*****************************************************************************
 * FUNCTION
 *  EntryFMEchoLoopHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_echo_loop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_eachloop_struct * eachloop_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eachloop_cntx = &(g_fm_contxt->eachloop_contxt);
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_ECHOLOOP);

    if (!(eachloop_cntx->EchoLoopTestOn))
    {
        eachloop_cntx->EchoLoopTestOn = MMI_TRUE; 

        mmi_fm_set_echo_loop(MMI_KEY_TONE_DISABLED, STR_GLOBAL_OFF, KAL_TRUE);

    }
    else
    {
        eachloop_cntx->EchoLoopTestOn = MMI_FALSE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */

        mmi_fm_set_echo_loop(MMI_KEY_TONE_ENABLED, STR_GLOBAL_ON, KAL_FALSE);
        
      	//	gui_touch_feedback_enable_tone_internal();
		//gui_touch_feedback_enable_vibrate_internal();
    }
    redraw_left_softkey();
}

/*****************************************************************************
 * FUNCTION
 *  HightlightFMEchoLoopHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_echo_loop_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_fm_common_set_left_softkey(g_fm_contxt->eachloop_contxt.EchoLoopTestOn);
}


#define MMI_FM_MIC_ECHO_LOOP

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
extern void mmi_fm_select_echo_loop2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    kal_sleep_task(kal_milli_secs_to_ticks(200));
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    if (!L1SP_GetAfeLoopbackStatus())
    {
		//gui_touch_feedback_disable_tone_internal();
		//gui_touch_feedback_disable_vibrate_internal();

		aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback2,
				KAL_TRUE,
				NULL);
        mmi_fm_common_set_left_softkey(MMI_TRUE);
		g_fm_echoloop2_need_close = MMI_TRUE;
    }
    else
    {
		aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback2,
				KAL_FALSE,
				NULL);
        mmi_fm_common_set_left_softkey(MMI_FALSE);
		g_fm_echoloop2_need_close = MMI_FALSE;
    }    
}

extern void mmi_fm_highlight_echo_loop2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    mmi_fm_common_set_left_softkey(L1SP_GetAfeLoopbackStatus());   
}


/*****************************************************************************
* FUNCTION
*  mmi_fm_2micnr_rsp_microphone_volumet three
* DESCRIPTION
*  deal with the rsp
* PARAMETERS
*  inMsg         MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP
* RETURNS
*  void
*****************************************************************************/
void mmi_fm_2micnr_rsp_microphone_volumet(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP , NULL);
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_rsp_microphone_volumet");/* delete */
    if (rsp_p->result)
    {
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_rsp_microphone_volumet TRUE %d", rsp_p->audio_prof_out.mic[3]);/* delete */
        L1SP_SetMicrophoneVolume(rsp_p->audio_prof_out.mic[3]);
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
		aud_util_proc_in_med(MOD_MMI, mmi_fm_set_acoustic_loopback, KAL_TRUE, NULL);
        mmi_fm_common_set_left_softkey(MMI_TRUE);
        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_fm_2micnr_test_req_microphone_volumet
* DESCRIPTION
*  deal with the req
* PARAMETERS
* void          
* RETURNS
*  void
*****************************************************************************/
void mmi_fm_2micnr_req_microphone_volumet()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_req_struct *msg_p;
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_req_microphone_volumet");/* delete */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP, mmi_fm_2micnr_rsp_microphone_volumet);
    
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_get_audio_profile_req_struct));
    msg_p->audio_prof_in.mode = AUD_MODE_NORMAL;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ, msg_p, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_2micnr_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_2micnr_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ABF_GetAcousticLoopbackStatus())
    {   
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_select_2micnr_test FALSE");/* delete */
        g_fm_contxt->two_micnr.two_micnr_test = KAL_TRUE;
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);   
        mmi_fm_2micnr_req_microphone_volumet();
    }
    else
    {
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_highlight_2micnr_test TRUE");;/* delete */
        g_fm_contxt->two_micnr.two_micnr_test = KAL_FALSE;
        aud_util_proc_in_med(MOD_MMI, mmi_fm_set_acoustic_loopback, KAL_FALSE, NULL);
        mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_highlight_2micnr_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_2micnr_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ABF_GetAcousticLoopbackStatus())
    {
        mmi_fm_common_set_left_softkey(MMI_TRUE);
    }
    else
    {
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_fm_disable_2micnr_rsp_microphone_volumet three
* DESCRIPTION
*  deal with the rsp
* PARAMETERS
*  inMsg           MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP
* RETURNS
*  void
*****************************************************************************/
void mmi_fm_disable_2micnr_rsp_microphone_volumet(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP , NULL);
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_disable_2micnr_rsp_microphone_volumet");/* delete */
    if (rsp_p->result)
    {
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_disable_2micnr_rsp_microphone_volumet TRUE %d", rsp_p->audio_prof_out.mic[3]);/* delete */
        L1SP_SetMicrophoneVolume(rsp_p->audio_prof_out.mic[3]);
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
		aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_disable_2mic_nr_back,
				KAL_TRUE,
				NULL);
        mmi_fm_common_set_left_softkey(MMI_TRUE); 
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_fm_disable_2micnr_test_req_microphone_volumet
* DESCRIPTION
*  deal with the req
* PARAMETERS
* void          
* RETURNS
*  void
*****************************************************************************/
void mmi_fm_disable_2micnr_req_microphone_volumet()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_req_struct *msg_p;
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_disable_2micnr_req_microphone_volumet");/* delete */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP, mmi_fm_disable_2micnr_rsp_microphone_volumet);
    
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_get_audio_profile_req_struct));
    msg_p->audio_prof_in.mode = AUD_MODE_NORMAL;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_disable_2micnr_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_disable_2micnr_test(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = ABF_GetAcousticLoopbackStatus();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_select_disable_2micnr_test: %d", temp);
    
    if (!ABF_GetAcousticLoopbackStatus())
    {   
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_select_disable_2micnr_test FALSE");/* delete */
        g_fm_contxt->two_micnr.disable_2micnr_test = KAL_TRUE;
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);   
        mmi_fm_disable_2micnr_req_microphone_volumet();
    }
    else
    {
        kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_select_disable_2micnr_test TRUE");/* delete */
        g_fm_contxt->two_micnr.disable_2micnr_test = KAL_FALSE;
        aud_util_proc_in_med(MOD_MMI, mmi_fm_set_disable_2mic_nr_back, KAL_FALSE, NULL);
        mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_highlight_disable_2micnr_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_disable_2micnr_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (ABF_GetAcousticLoopbackStatus())
    {
        mmi_fm_common_set_left_softkey(MMI_TRUE); 
    }
    else
    {
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_2micnr_hdlr_earphone_plug_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
extern mmi_ret mmi_fm_2micnr_hdlr_earphone_plug_in(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fm_contxt != NULL)
    {
        if(g_fm_contxt->two_micnr.two_micnr_test)
        {
            kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_hdlr_earphone_plug_in for mmi_fm_set_acoustic_loopback");
            aud_util_proc_in_med(MOD_MMI, mmi_fm_set_acoustic_loopback, KAL_FALSE, NULL);
            mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
            g_fm_contxt->two_micnr.two_micnr_test = KAL_FALSE;
            mmi_fm_common_set_left_softkey(MMI_FALSE);
        }

        if(g_fm_contxt->two_micnr.disable_2micnr_test)
        {
            kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_hdlr_earphone_plug_in for mmi_fm_set_disable_2mic_nr_back");
            aud_util_proc_in_med(MOD_MMI, mmi_fm_set_disable_2mic_nr_back, KAL_FALSE, NULL);
            mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
            g_fm_contxt->two_micnr.disable_2micnr_test = KAL_FALSE;
            mmi_fm_common_set_left_softkey(MMI_FALSE);
        }
    }
    
    return MMI_RET_OK;
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_2micnr_hdlr_earphone_plug_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
extern mmi_ret mmi_fm_2micnr_hdlr_earphone_plug_out(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fm_contxt == NULL)
    {
    }
    else
    {
        if(g_fm_contxt->two_micnr.two_micnr_test)
        {
            kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_hdlr_earphone_plug_out for mmi_fm_set_acoustic_loopback");
            aud_util_proc_in_med(MOD_MMI, mmi_fm_set_acoustic_loopback, KAL_FALSE, NULL);
            mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
            g_fm_contxt->two_micnr.two_micnr_test = KAL_FALSE;
            mmi_fm_common_set_left_softkey(MMI_FALSE);
        }

        if(g_fm_contxt->two_micnr.disable_2micnr_test)
        {
            kal_prompt_trace(MOD_MMI_COMMON_APP,"mmi_fm_2micnr_hdlr_earphone_plug_out for mmi_fm_set_disable_2mic_nr_back");
            aud_util_proc_in_med(MOD_MMI, mmi_fm_set_disable_2mic_nr_back, KAL_FALSE, NULL);
            mdi_audio_set_audio_mode(g_fm_contxt->two_micnr.two_micnr_audio_mode_enum);
            g_fm_contxt->two_micnr.disable_2micnr_test = KAL_FALSE;
            mmi_fm_common_set_left_softkey(MMI_FALSE);
        }
    }
    return MMI_RET_OK;

}


#endif /*__MMI_FM_DUAL_MIC_ECHO_LOOP__*/


#ifdef __ACOUSTIC_LOOPBACK_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  HighlightFMAcousticLoopHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_acoustic_loopback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_common_set_left_softkey(L1SP_AcousticLoopbackStatus());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_acoustic_loopback_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_acoustic_loopback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (L1SP_AcousticLoopbackStatus())
    {
        L1SP_AcousticLoopbackOff();
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    }
    else
    {
        L1SP_AcousticLoopbackOn();
        mmi_fm_common_set_left_softkey(MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_stop_acoustic_loopback_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_stop_acoustic_loopback_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (L1SP_AcousticLoopbackStatus())
    {
        L1SP_AcousticLoopbackOff();

    }
}
#endif

#define MMI_FM_RING_TONE

/*--------   Ring_tone -------- */

/*****************************************************************************
 * FUNCTION
 *  FM_SendPlayAudioReq
 * DESCRIPTION
 *  It used by FM and quick test
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_SendPlayAudioReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_play_tone_with_id(SRV_PROF_TONE_FM, (U16)(index + SRV_PROF_AUD_TONE1), SRV_PROF_RING_TYPE_REPEAT, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRingToneHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_ring_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL *isRingtoneOn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    isRingtoneOn = &(g_fm_contxt->eachloop_contxt.RingToneTestOn);
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_RINGTONE);

    if (!(*isRingtoneOn))
    {
        *isRingtoneOn = TRUE;
        /* set gain */
        Media_SetOutputVolume(255, 0);
        /* play MIDI_1 */
        FM_SendPlayAudioReq(0);
        mmi_fm_common_set_left_softkey(MMI_TRUE);
    }
    else
    {
        *isRingtoneOn = FALSE;
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* stop MIDI */
        FM_SendStopAudioReq(0);
        mmi_fm_common_set_left_softkey(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  HightlightFMRingToneHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_ring_tone_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_common_set_left_softkey(g_fm_contxt->eachloop_contxt.RingToneTestOn);

}

#define MMI_FM_HEADSET
#ifndef __MMI_FM_PLUTO_6261_SLIM__
/*-------------  headset ------------ */

/*****************************************************************************
 * FUNCTION
 *  HightlightFMHeadsetHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_fm_common_set_left_softkey(g_fm_contxt->eachloop_contxt.HeadsetTestOn);
}

static void mmi_fm_set_headset(MMI_BOOL HeadsetTestOn, audio_mode_enum mode,kal_bool on, U16 s )
{
    g_fm_contxt->eachloop_contxt.HeadsetTestOn = HeadsetTestOn;
    /* set audio mode to Headset */

    FM_SendSetAudioModeReq(mode);

    if (on)
    {
        TONE_SetOutputVolume(255, 0);
        mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE); 
    }
    else
    {
        /* stop 1K tone */
        mdi_audio_stop_id(TONE_KEY_NORMAL);
    }
    change_left_softkey(s, 0);
}

/*****************************************************************************
 * FUNCTION
 *  EntryFMHeadsetHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fm_contxt->eachloop_contxt.HeadsetTestOn)
    {
        mmi_fm_set_headset(MMI_TRUE,AUD_MODE_HEADSET,KAL_TRUE,STR_GLOBAL_OFF);
    }
    else
    {
        mmi_fm_set_headset(MMI_FALSE,AUD_MODE_NORMAL,KAL_FALSE,STR_GLOBAL_ON);
    }
    redraw_left_softkey();
}
#endif /* __MMI_FM_PLUTO_6261_SLIM__ */


#pragma arm section code = "SECONDARY_ROCODE"

#define MMI_FM_MTBF

/*--------  MTBF -------- */

static void mmi_fm_MTBF_tone_callback(kal_uint32 arg1, void *arg2)
{
    switch(arg1)
    {
        case MMI_FM_TONE_ACT_PLAY:
            TONE_Play((const L1SP_Tones*)arg2);
            break;
            
        case MMI_FM_TONE_ACT_STOP:
            TONE_Stop();
            break;

        default:
            break;
    }
}

static void mmi_fm_play_MTBF_tone(device_tones_struct *table)
{
    aud_util_proc_in_med(MOD_MMI, 
        mmi_fm_MTBF_tone_callback,
        MMI_FM_TONE_ACT_PLAY,
        table);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_stop_MTBF_tone
 * DESCRIPTION
 *  If goback to idle or exit group, it will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_stop_MTBF_tone(void)
{
    aud_util_proc_in_med(MOD_MMI,
        mmi_fm_MTBF_tone_callback,
        MMI_FM_TONE_ACT_STOP,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_exe_mtbf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_exe_mtbf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 Count_ms = FM_MTBF_PERIOD * g_fm_contxt->mtbf_contxt.MTBF_counter;
    mmi_fm_mtbf_struct *mtbf_cntx;
    U8  type = GPIO_DEV_LED_KEY;
    U8  level = LED_LIGHT_LEVEL5;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtbf_cntx = &(g_fm_contxt->mtbf_contxt);
    /* LCD */
    if ((Count_ms % FM_MTBF_LCD_CYCLE) == 0)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        gui_lock_double_buffer();

        switch (mtbf_cntx->MTBF_state_LCD)
        {
            case FM_MTBF_LCD_R:
                FM_HandleInitialColor(255, 0, 0);
                break;
            case FM_MTBF_LCD_G:
                FM_HandleInitialColor(0, 255, 0);
                break;
            case FM_MTBF_LCD_B:
                FM_HandleInitialColor(0, 0, 255);
                break;
            case FM_MTBF_LCD_W:
                FM_HandleInitialColor(255, 255, 255);
                break;
            default:
                ASSERT(0);
                return;
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

        if (mtbf_cntx->MTBF_state_LCD == FM_MTBF_LCD_END)
        {
            mtbf_cntx->MTBF_state_LCD = FM_MTBF_LCD_START;
        }
        else
        {
            mtbf_cntx->MTBF_state_LCD++;
        }

    }

    /* LED */
    if ((Count_ms % FM_MTBF_LED_CYCLE) == 0)
    {
        FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
        FM_SetGpioLEDReq(LED_LIGHT_LEVEL0);

        switch (mtbf_cntx->MTBF_state_LED)
        {
            case FM_MTBF_LED_KEYPAD:
                type = GPIO_DEV_LED_KEY;
                level = LED_LIGHT_LEVEL5;               
            case FM_MTBF_LED_R:
                type = GPIO_DEV_LED_STATUS_1;
                level = LED_LIGHT_LEVEL5;               
            case FM_MTBF_LED_G:
                type = GPIO_DEV_LED_STATUS_2;
                level = LED_LIGHT_LEVEL5;
            case FM_MTBF_LED_B:
                type = GPIO_DEV_LED_STATUS_3;
                level = LED_LIGHT_LEVEL5;
                FM_SetGpioReq(type, level);
                break;
            default:
                ASSERT(0);
                return;
        }

        if (mtbf_cntx->MTBF_state_LED == FM_MTBF_LED_END)
        {
            mtbf_cntx->MTBF_state_LED = FM_MTBF_LED_START;
        }
        else
        {
            mtbf_cntx->MTBF_state_LED++;
        }
    }

    /* VIB */
    if ((Count_ms % FM_MTBF_VIB_CYCLE) == 0)
    {
        FM_SetGpioVirbateReq((mtbf_cntx->MTBF_state_VIB == FM_MTBF_VIB_ON) ? VIBRATOR_ON : VIBRATOR_OFF);

        if (mtbf_cntx->MTBF_state_VIB == FM_MTBF_VIB_END)
        {
            mtbf_cntx->MTBF_state_VIB = FM_MTBF_VIB_START;
        }
        else
        {
            mtbf_cntx->MTBF_state_VIB++;
        }
    }

    /* Speaker */
    if ((Count_ms % FM_MTBF_SPK_CYCLE) == 0 && mtbf_cntx->AUD_TEST_ON == FM_MTBF_AUD_SPK)
    {
        /* Louk Speaker Mode */
        mmi_fm_stop_MTBF_tone();
        kal_sleep_task(20);
        FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
        /* TONE_SetOutputDevice(L1SP_LOUD_SPEAKER); */
        TONE_SetOutputVolume(255, 0);
        mmi_fm_play_MTBF_tone((device_tones_struct *)SPK_test_tone);

        type = MMI_TRUE;
    }
    else /* Receiver */ if ((Count_ms % FM_MTBF_REV_CYCLE) == 0 && mtbf_cntx->AUD_TEST_ON == FM_MTBF_AUD_REV)
    {
        /* Normal Mode */
        mmi_fm_stop_MTBF_tone();
        kal_sleep_task(20);
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* TONE_SetOutputDevice(L1SP_SPEAKER1); */
        TONE_SetOutputVolume(255, 0);
        mmi_fm_play_MTBF_tone((device_tones_struct *)REV_test_tone);

        type = MMI_TRUE;
    }
    if(MMI_TRUE == type)
    {
        if (mtbf_cntx->AUD_TEST_ON == FM_MTBF_AUD_END)
        {
            mtbf_cntx->AUD_TEST_ON = FM_MTBF_AUD_START;
        }
        else
        {
            mtbf_cntx->AUD_TEST_ON++;
        }
    }   

   /***** Prepare for the next step *****/
    mtbf_cntx->MTBF_counter++;
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, FM_MTBF_PERIOD, mmi_fm_exe_mtbf);
}

/*****************************************************************************
 * FUNCTION
 *  FM_BACK_TO_NORMAL_STATE
 * DESCRIPTION
 *  It will be called by FM and Quick test when exit MTBF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_back_to_normal_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_eachloop_struct *eachloop_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eachloop_cntx = &(g_fm_contxt->eachloop_contxt);
    
    g_fm_contxt->common_contxt.sequence_counter = 0;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    eachloop_cntx->ReceiverTestOn = FALSE;
    eachloop_cntx->EchoLoopTestOn = MMI_FALSE;
    g_fm_contxt->loudspk_contxt.LoudSpkTestOn = MMI_FALSE;
    eachloop_cntx->HeadsetTestOn = FALSE;

    /* LED */
    FM_SetGpioLEDReq(LED_LIGHT_LEVEL0);

    /* LCD */
    FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);

#ifdef __MMI_FM_LCD_CONTRAST__
    /* LCD contrast */
    srv_gpio_setting_set_mianlcd_contrast(7);
    srv_gpio_setting_set_sublcd_contrast(7);
#endif /* __MMI_FM_LCD_CONTRAST__ */

    //Lisen 0702
    //Receiver : stop 1K tone
    mdi_audio_stop_id(TONE_KEY_NORMAL);

    /* MIC: close loopback */
    //mmi_fm_set_loopback(KAL_FALSE);
	   aud_util_proc_in_med(MOD_MMI,
		mmi_fm_set_loopback,
		KAL_FALSE,
		NULL);

    /* Ringtone */
    eachloop_cntx->RingToneTestOn = FALSE;
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    /* stop MIDI */
    FM_SendStopAudioReq(0);

    /* VIB */
    FM_SetGpioVirbateReq(VIBRATOR_OFF);
}

#ifdef __MMI_FM_MTBF__
/*****************************************************************************
 * FUNCTION
 *  ExitFMMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_exit_mtbf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	srv_backlight_turn_off();
    mmi_fm_back_to_normal_state();
    FM_RestoreAudio();
}

/*****************************************************************************
 * FUNCTION
 *  FM_StopMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_stop_mtbf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    //FM_BACK_TO_NORMAL_STATE();
    srv_backlight_turn_off();
    mmi_fm_back_to_normal_state();
        
    FM_RestoreAudio();
    mmi_fm_stop_MTBF_tone();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_mtbf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_fm_mtbf_struct *mtbf_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtbf_cntx = &(g_fm_contxt->mtbf_contxt);
    mmi_frm_scrn_enter
        (g_fm_gourp_id, 
        SCR_ID_FM_MTBF, 
        mmi_fm_exit_mtbf,
        mmi_fm_select_mtbf, 
        MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    mtbf_cntx->AUD_TEST_ON = FM_MTBF_AUD_START;
    mtbf_cntx->MTBF_counter = 0;
    mtbf_cntx->MTBF_state_LCD = FM_MTBF_LCD_START;
    mtbf_cntx->MTBF_state_LED = FM_MTBF_LED_START;
    mtbf_cntx->MTBF_state_VIB = FM_MTBF_VIB_START;
    
    mmi_fm_exe_mtbf();

    ShowCategory7Screen(
        STR_ID_FM_MTBF,
        NULL,
        (U16) NULL,
        (U16) NULL,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_OK,
        NULL,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_fm_stop_mtbf, KEY_EVENT_UP);
    
#ifdef __COSMOS_MMI_PACKAGE__    
    SetKeyUpHandler(mmi_fm_stop_mtbf, KEY_BACK);
#endif
}
#endif /*  __MMI_FM_MTBF__ */

#pragma arm section code

#define MMI_FM_FM_RADIO

/*--------  20:  Radio -------- */


U8 flag = 0;

#ifdef __MMI_FM_RADIO__

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_update_radio_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_update_radio_scrn(void)
{
    mmi_frm_scrn_enter
       (g_fm_gourp_id, 
        GLOBAL_SCR_DUMMY, 
        NULL, 
        NULL, 
        MMI_FRM_FULL_SCRN);

    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  EntryFMRADIOChannelTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryFMRADIOChannelTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    CHAR* stringbuf;

    fm_fm_radio_struct *g_fm_fm_radio_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);   
    g_fm_fm_radio_cntx->is_FMRDO_on = 1;
    /* set audio volume */
    mdi_audio_set_volume( AUD_VOLUME_FMR,  MDI_AUD_VOL_MUTE(g_fm_fm_radio_cntx->CurrVolume));	

    /* set FM Radio Frequency */
    mdi_fmr_set_freq( g_fm_fm_radio_cntx->Currfreq);

    /* initialize display string */
    stringbuf = OslMalloc(MMI_FM_RADIO_STRING_LEN);
    stringbuf[0] = stringbuf[1] = 0;

    kal_wsprintf((WCHAR *)stringbuf, "Fre:  %d.%d \n\nVol:    %d\n\n",
        g_fm_fm_radio_cntx->Currfreq/10, g_fm_fm_radio_cntx->Currfreq%10,
        g_fm_fm_radio_cntx->CurrVolume);

#ifdef __COSMOS_MMI_PACKAGE__
    {
        CHAR * indicate = OslMalloc(MMI_FM_RADIO_INDICATE_LEN);
        U32 len = strlen(MMI_FM_RADIO_INDICATE);
        mmi_asc_to_ucs2(indicate, MMI_FM_RADIO_INDICATE);
        mmi_ucs2cat(stringbuf, indicate);
        OslMfree(indicate);
    }    
#endif /*__COSMOS_MMI_PACKAGE__*/

    flag =  mmi_frm_scrn_enter
         (g_fm_gourp_id, 
          SCR_ID_FM_FM_RADIO_CHANNEL_TEST, 
          NULL,
          EntryFMRADIOChannelTest, 
          MMI_FRM_FULL_SCRN);


    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    ShowCategory7Screen(g_fm_fm_radio_cntx->text_id, 0, 0, 0,
                        STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8)stringbuf, guiBuffer);

		 #ifdef __MMI_CLIPBOARD__
    	mmi_imc_clipboard_disconnect();
	 #endif /* __MMI_CLIPBOARD__ */


    OslMfree(stringbuf);
    mmi_fm_set_general_goback_function();

    /* Register End key handler */
    SetKeyDownHandler(mmi_frm_scrn_close_active_id, KEY_END );
    SetKeyDownHandler(FmFMRadioLeftArrowHdlr, KEY_LEFT_ARROW);
    SetKeyDownHandler(FmFMRadioRightArrowHdlr, KEY_RIGHT_ARROW);
    SetKeyDownHandler(FmFMRadioUpArrowHdlr, KEY_UP_ARROW);
    SetKeyDownHandler(FmFMRadioDownArrowHdlr, KEY_DOWN_ARROW);

#ifdef __COSMOS_MMI_PACKAGE__
    SetKeyDownHandler(FmFMRadioLeftArrowHdlr, KEY_SEND);
    SetKeyDownHandler(FmFMRadioRightArrowHdlr, KEY_END);
    SetKeyDownHandler(FmFMRadioUpArrowHdlr, KEY_VOL_UP);
    SetKeyDownHandler(FmFMRadioDownArrowHdlr, KEY_VOL_DOWN);
#endif /*__COSMOS_MMI_PACKAGE__*/
    
}

/**************************************************************
**	FUNCTION NAME		: FmFMRadioLeftArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Left Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
static void FmFMRadioLeftArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    fm_fm_radio_struct *g_fm_fm_radio_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);
    
    /* Channel Freq. Range: 875 - 1080 */
    if (g_fm_fm_radio_cntx->Currfreq > 875)
        g_fm_fm_radio_cntx->Currfreq -= 1;

    #ifdef __PLUTO_MMI_PACKAGE__
    /* Restore the changed frequency to NVRAM */
    switch(g_fm_contxt->radio_contxt.FmcurrentHighlightIndex)
    {
        case 0:   /* Channel 1 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_1, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        case 1:   /* Channel 2 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_2, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        case 2:   /* Channel 3 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_3, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        default:
        {
            ASSERT(0);
            return;
        }
    }
    #endif /*__PLUTO_MMI_PACKAGE__*/
     mmi_fm_update_radio_scrn();
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioRightArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Right Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
static void FmFMRadioRightArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    fm_fm_radio_struct *g_fm_fm_radio_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);
    
    /* Channel Freq. Range: 875 - 1080 */    
    if (g_fm_fm_radio_cntx->Currfreq < 1080)
        g_fm_fm_radio_cntx->Currfreq += 1;

    #ifdef __PLUTO_MMI_PACKAGE__ 
    /* Restore the changed frequency to NVRAM */
    switch(g_fm_contxt->radio_contxt.FmcurrentHighlightIndex)
    {
        case 0:   /* Channel 1 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_1, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        case 1:   /* Channel 2 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_2, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        case 2:   /* Channel 3 */
        {
            WriteValueSlim(NVRAM_FM_FM_RADIO_CHANNEL_3, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
            break;
        }
        default:
        {
            ASSERT(0);
            return;
        }
    }
    
    #endif/*__PLUTO_MMI_PACKAGE__*/
    mmi_fm_update_radio_scrn();
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioUpArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Up Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
static void FmFMRadioUpArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fm_fm_radio_struct *g_fm_fm_radio_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);
    
    if (g_fm_fm_radio_cntx->CurrVolume < MAX_VOL_LEVEL - 1)
        g_fm_fm_radio_cntx->CurrVolume++;

	/* set audio volume */
    mdi_audio_set_volume( AUD_VOLUME_FMR,  g_fm_fm_radio_cntx->CurrVolume);

    mmi_fm_update_radio_scrn();

}

/**************************************************************
**	FUNCTION NAME		: FmFMRadioDownArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Down Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
static void FmFMRadioDownArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fm_fm_radio_struct *g_fm_fm_radio_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);
    
    if (g_fm_fm_radio_cntx->CurrVolume > 0)
        g_fm_fm_radio_cntx->CurrVolume--;

    mmi_fm_update_radio_scrn();
}

#ifdef __PLUTO_MMI_PACKAGE__

static void mmi_fm_set_radio_test(U16 nDataItemId, U16 str_id, U8 index)
{
     fm_fm_radio_struct *g_fm_fm_radio_cntx;

     g_fm_fm_radio_cntx = &(g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx);
     

    ReadValueSlim(nDataItemId, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
    if (g_fm_fm_radio_cntx->Currfreq == 0xffff)
    {
        g_fm_fm_radio_cntx->Currfreq = 875;    /* init value */
        WriteValueSlim(nDataItemId, &(g_fm_fm_radio_cntx->Currfreq), DS_SHORT);
    }
    g_fm_fm_radio_cntx->text_id= str_id;
    g_fm_contxt->radio_contxt.FmcurrentHighlightIndex = index;
}

#endif

#ifndef __PLUTO_MMI_PACKAGE__
static void mmi_fm_set_radio_test(U16 text_id, U8 index)
{    
    g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.text_id= text_id;
    g_fm_contxt->radio_contxt.FmcurrentHighlightIndex = index;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryFMRADIOChannelTestInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_radio_test(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init volume */
    g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.CurrVolume = 3;

    /* Turn on FM Radio */
    mdi_fmr_power_on_with_path( MDI_DEVICE_SPEAKER2, NULL, NULL);  

    /* Read channel info from NVRAM */
#ifdef __PLUTO_MMI_PACKAGE__
    switch(menu_evt->highlighted_menu_id)
    {
        case MENU_ID_FM_FMRADIO_CHANNEL_1:   /* Channel 1 */
        {

            mmi_fm_set_radio_test(NVRAM_FM_FM_RADIO_CHANNEL_1,STR_ID_FM_FM_RADIO_CHANNEL_1,0);
            break;
        }

   #ifdef __MMI_FM_FMRADIO_PHASE_OUT__
        case MENU_ID_FM_FMRADIO_CHANNEL_2:   /* Channel 2 */
        {
            mmi_fm_set_radio_test(NVRAM_FM_FM_RADIO_CHANNEL_2,STR_ID_FM_FM_RADIO_CHANNEL_2,1);
            break;
        }
        case MENU_ID_FM_FMRADIO_CHANNEL_3:   /* Channel 3 */
        {
            mmi_fm_set_radio_test(NVRAM_FM_FM_RADIO_CHANNEL_3,STR_ID_FM_FM_RADIO_CHANNEL_3,2);
            break;
        }
   #endif
        default:
        {
            ASSERT(0);
            return;
        }
    }
#else /*__PLUTO_MMI_PACKAGE__*/
     /* init Fre value */
    if (g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.Currfreq < 875)
    {
        g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.Currfreq = 875;
    }
    else if (g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.Currfreq >1080)
    {
        g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.Currfreq = 1080;
    }
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_FM_FMRADIO_CHANNEL_1:
            mmi_fm_set_radio_test(STR_ID_FM_FM_RADIO_CHANNEL_1,0);            
            break;

    #ifdef __MMI_FM_FMRADIO_PHASE_OUT__

        case MENU_ID_FM_FMRADIO_CHANNEL_2:
            mmi_fm_set_radio_test(STR_ID_FM_FM_RADIO_CHANNEL_2,1);            
            break;

        default:

            mmi_fm_set_radio_test(STR_ID_FM_FM_RADIO_CHANNEL_3,2);
            break;
    #endif
    }
#endif /*__PLUTO_MMI_PACKAGE__*/
    EntryFMRADIOChannelTest();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_highlight_radio_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_radio_menu(void)
{
    
    /* If FM Radio is turned on, then stop/turn-off it */
    if (g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.is_FMRDO_on)
    {
        mdi_audio_stop_fmr();
        g_fm_contxt->radio_contxt.g_fm_fm_radio_cntx.is_FMRDO_on = 0;
    }
}

#endif /* __MMI_FM_RADIO__ */


#define MMI_FM_RECEIVER

/*------------------- Receiver --------------------------*/

/*****************************************************************************
 * FUNCTION
 *  HightlightFMReceiverHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_highlight_receiver_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_fm_common_set_left_softkey(MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  EntryFMReceiverHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_receiver_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL *isReceiverTestOn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isReceiverTestOn = &(g_fm_contxt->eachloop_contxt.ReceiverTestOn);
    
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_RECEIVER);

    if (!*isReceiverTestOn)
    {
        *isReceiverTestOn = TRUE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        /* play 1K tone */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        TONE_SetOutputVolume(255, 0);
        mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE);
        mmi_fm_common_set_left_softkey(MMI_TRUE);
    }
    else
    {
        *isReceiverTestOn = FALSE;
        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        /* stop 1K tone */
        mdi_audio_stop_id(TONE_KEY_NORMAL);
        mmi_fm_common_set_left_softkey(MMI_FALSE);

    }
}

#define MMI_FM_LOUDSPK

/*--------  LoudSpk  -------- */

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_loud_spk_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_loud_spk_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_common_set_left_softkey(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_setloud_spk_amp_over_current_protect_req_cnf
 * DESCRIPTION
 *  The function for deal with MSG_ID_MEDIA_IN_PROC_CALL_REQ's MSG_ID_MEDIA_IN_PROC_CALL_CNF
 * PARAMETERS
 *  void *msg [IN] about MSG_ID_MEDIA_IN_PROC_CALL_CNF return
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_setloud_spk_amp_over_current_protect_req_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = g_fm_gourp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_in_proc_call_cnf_struct *cnf_msg = (media_in_proc_call_cnf_struct *)msg;
    if(cnf_msg->result == MMI_TRUE)
    {
        mmi_popup_display_simple_ext(STR_ID_FM_LOUDSPK_AMP_OVER_CURRENT_DETECTION, MMI_EVENT_WARNING, grp_id, NULL);
        mmi_fm_setloud_spk(1,MMI_FALSE,AUD_MODE_NORMAL,STR_GLOBAL_ON);
    }
    mmi_frm_clear_protocol_event_handler(MSG_ID_MEDIA_IN_PROC_CALL_CNF, (PsIntFuncPtr)NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_setloud_spk_amp_over_current_protect
 * DESCRIPTION
 *  The function for deal with MSG_ID_MEDIA_IN_PROC_CALL_REQ
 * PARAMETERS
 *  kal_uint32 result [IN]
 *  void *pfunc [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_setloud_spk_amp_over_current_protect_req(kal_uint32 result, void *pfunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_bool result_pfunc = AFE_SPKAMP_OCDetect();
    media_in_proc_call_cnf_struct *cnf_msg = MMI_EM_CONSTRUCT_MSG_DATA(media_in_proc_call_cnf_struct);
    cnf_msg->result = result_pfunc;
    aud_send_ilm(MOD_MMI, MSG_ID_MEDIA_IN_PROC_CALL_CNF, cnf_msg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_loud_spk_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_setloud_spk(U8 flag,MMI_BOOL LoudSpkTestOn,U8 mode,U16 s)
{
    /* internal speaker amp over current protection */
    media_in_proc_call_req_struct *req_msg;
    req_msg = MMI_EM_CONSTRUCT_MSG_DATA(media_in_proc_call_req_struct);
    req_msg->func = (media_in_proc_call_type)mmi_fm_setloud_spk_amp_over_current_protect_req;
    /* end */

    g_fm_contxt->loudspk_contxt.LoudSpkTestOn = LoudSpkTestOn;

    /* set audio mode to LoudSp */
    /* custom_em_set_mode(AUD_MODE_LOUDSPK); */
    FM_SendSetAudioModeReq(mode);
    if (flag == 0)
    {
        /* play 1K tone */
        TONE_SetOutputVolume(255, 0);
        mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE); 
        
        /* internal speaker amp over current protection */
        mmi_frm_set_single_protocol_event_handler(MSG_ID_MEDIA_IN_PROC_CALL_CNF, 
                                       (PsIntFuncPtr)mmi_fm_setloud_spk_amp_over_current_protect_req_cnf);
#ifndef MED_V_NOT_PRESENT
        aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_IN_PROC_CALL_REQ, req_msg, NULL);
#else
        aud_send_ilm(MOD_MED, MSG_ID_MEDIA_IN_PROC_CALL_REQ, req_msg, NULL);
#endif
        /* end */
    }
    else
    {
        /* stop 1K tone */
        mdi_audio_stop_id(TONE_KEY_NORMAL);
    }
   
    change_left_softkey(s, 0);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_loud_spk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_loud_spk(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fm_contxt->loudspk_contxt.LoudSpkTestOn)
    {
        mmi_fm_setloud_spk(0,MMI_TRUE,AUD_MODE_LOUDSPK,STR_GLOBAL_OFF);
    }
    else
    {
        mmi_fm_setloud_spk(1,MMI_FALSE,AUD_MODE_NORMAL,STR_GLOBAL_ON);
    }
    redraw_left_softkey();

}


#endif

