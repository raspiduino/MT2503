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
*  EngineerModeAudio.c
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Engineer mode audio related file. 
*    It includes:
*       -  Set Mode
*       -  Normal Mode
*       -  Loud SP Mode
*       -  Headset Mode
*       -  Ring tone
*       -  Speech enhancement
*       -  Set Max Swing
*       -  TV out
*       -  Debug Info
*       -  Auto VM
*       -  TTS
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include 
*****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_ENGINEER_MODE__
#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
#include "MMIDataType.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "custom_user_profiles_defs.h"
#include "custom_srv_prof_defs.h"
#include "mmi_msg_struct.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "string.h"
#include "stack_config.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "gui_typedef.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stdio.h"
#include "custom_em.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories.h"
#include "device.h"
#include "wgui_inline_edit.h"
#include "ImeGprot.h"
#include "kal_public_api.h"
#include "stdlib.h"
#include "wgui_categories_inputs.h"
#include "wgui_include.h"

#include "mdi_audio.h"
#include "med_api.h"
#include "med_struct.h"
#include "l1audio.h"
#include "ProfilesSrvGprot.h"
#include "CommonScreens.h"
#if (defined(__MMI_SOUND_RECORDER__) && (__PLUTO_MMI_PACKAGE__))
#include "mmi_rp_app_soundrecorder_def.h"
#endif
#include "InlineCuiGprot.h"
#include "EngineerModeGProt.h"
#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeAudio.h"

#include "mmi_rp_app_engineermode1_def.h"
/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    MMI_EM_AUD_GAIN_CAP = (CUI_INLINE_ITEM_ID_BASE + 0),
    MMI_EM_AUD_GAIN_EDIT,
    MMI_EM_AUD_STEP_CAP,
    MMI_EM_AUD_STEP_EDIT,
    MMI_EM_AUD_INLINE_ID_TOTAL
} mmi_em_aud_inline_enum;

#define EM_AUDIO_TONE_NUM   (SRV_PROF_AUD_TONE_END_OF_ENUM - SRV_PROF_AUD_TONE1)
#define EM_AUDIO_RING_NUM   (SRV_PROF_AUD_RING_END_OF_ENUM - SRV_PROF_AUD_RING1)


typedef struct
{
    audio_param_struct AudioParameter;
    U16 AudioParam_debug_info[16];
    EmVolumeModeEnum currentVolumeMode;
    EmVolumeTypeEnum currentVolumeType;
    EmAudioProfileStruct gAudioProfile;
    EmAudioProfileStruct gAudioProfileOrg;
    U32 hilit_index;
    S16 currentVolume;
    WCHAR  MaxAnalogGain[8];
    BOOL isPopup;
    WCHAR  Step[8];
    U8 activeRingToneIndex;
    S32 currentKeyShift;
    mmi_menu_id cur_hight_id;
} mmi_em_aud_cntx_struct;

/***************************************************************************** 
* Static Declaration
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
mmi_em_aud_cntx_struct *mmi_em_aud_cntx_p = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/*****************************************
 ** Audio->main menu hdlr
 ****************************************/
static void mmi_em_aud_main_menu_hdlr(void);
static void mmi_em_aud_main_menu_free_adm_hdlr(void);
//static void EmAudioScrDelCallback(void);
#ifdef __MMI_EM_AUDIO__
static void CheckAudioProfile(void);
static MMI_RET mmi_em_audio_quer_update_proc(mmi_event_struct *evt);
#endif
/*****************************************
 ** Audio->Tone setting
 ****************************************/
#ifdef __MMI_EM_AUDIO__
static void mmi_em_aud_ring_tone_list_init(void);
static void mmi_em_aud_ring_tone_hdlr(void);
static void mmi_em_aud_ring_tone_menu_exit_hdlr(void);
static void mmi_em_aud_popup_finish_hdlr(void);
static void mmi_em_aud_ring_tone_hilit_hdlr(S32 nIndex);
/*****************************************
 ** Audio->Set mode
 ****************************************/
static void mmi_em_aud_set_mode_hdlr(cui_menu_event_struct *evt);
static void mmi_em_aud_set_mode_pre_hdlr(cui_menu_event_struct *evt);
/*****************************************
 ** Audio->Set valum
 ****************************************/
static void mmi_em_aud_set_valum_inline_scrn(void);
static void mmi_em_aud_set_valum_scrn(void);
static MMI_RET mmi_em_aud_set_valum_inline_proc(mmi_event_struct *evt);
static void mmi_em_aud_set_valum_inline_scrn(void);
/*****************************************
 ** Audio->normal mode
 ****************************************/

/*****************************************
 ** Audio->Normal mode->Fir
 ****************************************/
static void mmi_em_aud_normal_mode_fir_hdlr(cui_menu_event_struct *evt);
static void mmi_em_aud_normal_mode_fir_pre_hdlr(cui_menu_event_struct *evt);
/*****************************************
 ** Audio->Head set mode
 ****************************************/

#endif /* __MMI_EM_AUDIO__ */
/*****************************************
 ** Audio->Param edit setting
 ****************************************/
static void mmi_em_aud_set_param_hdlr(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data);
#if defined( __MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__)
static void mmi_em_aud_set_param_edit_hdlr(cui_menu_event_struct *evt);
#endif
/*****************************************
 ** Audio->Auto Record setting
 ****************************************/
#ifdef __MMI_EM_AUDIO_AUTO_VM__ 
static void mmi_em_aud_auto_vm_setting_pre_hdlr(cui_menu_event_struct *evt);
static void mmi_em_aud_auto_vm_setting_hdlr(cui_menu_event_struct *evt);
#endif/*__MMI_EM_AUDIO_AUTO_VM__*/

/***************************************************************************** 
* Global Function 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_em_audio_debug_info_init
 * DESCRIPTION
 *  set debug info at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_audio_debug_info_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j;
    extern const unsigned short L1Audio_Debug_Info[16];
    U16 AudioParam_debug_info[16] = {0};
    U16 nvram_ids[4] = {
            NVRAM_AUDIO_DEBUG_INFO1,
            NVRAM_AUDIO_DEBUG_INFO2,
            NVRAM_AUDIO_DEBUG_INFO3,
            NVRAM_AUDIO_DEBUG_INFO4
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 4; i++)
    {
        ReadValueSlim(nvram_ids[i], &AudioParam_debug_info[i * 4], DS_DOUBLE);
        
        if(AudioParam_debug_info[i * 4] == 0xFFFF)
        {
            for (j = 0; j < 4; j++)
            {
               AudioParam_debug_info[j + i * 4] = L1Audio_Debug_Info[j + i * 4];
            }
            WriteValueSlim(nvram_ids[i], &AudioParam_debug_info[i * 4], DS_DOUBLE);
        }
    }

#ifdef __MTK_TARGET__       
    /* Set debug info param to L1 directly. */
    L1Audio_SetDebugInfo(AudioParam_debug_info);
#endif /* __MTK_TARGET__ */

}


#define EM_AUDIO_MSG_HANDLER
/*****************************************
 ** Audio->Message handler
 ****************************************/
/*****************************************************************************
* FUNCTION
*  EngineerModePlayAudioReq
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
*  type        [IN]        
* RETURNS
*  void
*****************************************************************************/
void EngineerModePlayAudioReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16  sound_id = index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= EM_AUDIO_TONE_NUM)
    {
        sound_id += SRV_PROF_AUD_RING1 - EM_AUDIO_TONE_NUM;
    }
    else
    {
        sound_id += SRV_PROF_AUD_TONE1;
    }
    srv_prof_play_tone_with_id(SRV_PROF_TONE_EM, sound_id, SRV_PROF_RING_TYPE_ONCE, NULL);
}

/*****************************************************************************
* FUNCTION
*  EngineerModeStopAudioReq
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
*  type        [IN]        
* RETURNS
*  void
*****************************************************************************/
void EngineerModeStopAudioReq(U8 index, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_profiles_stop_tone(SRV_PROF_TONE_EM);
}


/*****************************************************************************
* FUNCTION
*  EngineerModeSetVolumeReq
* DESCRIPTION
*  
* PARAMETERS
*  volumeType      [IN]        
*  volumeLevel     [IN]        
* RETURNS
*  void
*****************************************************************************/
void EngineerModeSetVolumeReq(U8 volumeType, U8 volumeLevel)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	TONE_SetOutputVolume(volumeLevel, 0);
	KT_SetOutputVolume(volumeLevel, 0);
	L1SP_SetMicrophoneVolume(volumeLevel);
	Media_SetOutputVolume(volumeLevel, 0);
	L1SP_SetOutputVolume(volumeLevel, 0);
	L1SP_SetSidetoneVolume(volumeLevel);
	Media_SetOutputVolume(volumeLevel, 0);
	mmi_em_success_popup();
}

/*****************************************************************************
* FUNCTION
*  EngineerModeGetAudioProfileReq
* DESCRIPTION
*  
* PARAMETERS
*  mode        [IN]        
* RETURNS
*  void
*****************************************************************************/
void EngineerModeGetAudioProfileReq(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_req_struct *msg_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP, EngineerModeGetAudioProfileRes);
    
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_get_audio_profile_req_struct));
    msg_p->audio_prof_in.mode = mode;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ, msg_p, NULL);
}


/*****************************************************************************
* FUNCTION
*  EngineerModeGetAudioProfileRes
* DESCRIPTION
*  
* PARAMETERS
*  inMsg       [?]     
* RETURNS
*  void
*****************************************************************************/
U8 EngineerModeGetAudioProfileRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP , NULL);
    
    if (rsp_p->result)
    {
        EmUpdateAudioProfile(&rsp_p->audio_prof_out);
    }
	return 0;
}


/*****************************************************************************
* FUNCTION
*  EngineerModeSetAudioProfileReq
* DESCRIPTION
*  
* PARAMETERS
*  audioProfile        [?]     
* RETURNS
*  void
*****************************************************************************/
void EngineerModeSetAudioProfileReq(void *audioProfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_profile_req_struct *msg_p;
    EmAudioProfileStruct *p = (EmAudioProfileStruct*) audioProfile;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP, EngineerModeSetAudioProfileRes);
    
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_audio_profile_req_struct));
    msg_p->audio_prof.mode = p->mode;
    memcpy(msg_p->audio_prof.speech, p->speech, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.keytone, p->keytone, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.melody, p->melody, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.sound, p->sound, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.mic, p->mic, MAX_EM_VOLUME_LEVEL);
    msg_p->audio_prof.sidetone = p->sidetone;
    memcpy(msg_p->audio_prof.tv_out_volume_gain, p->tvout, MAX_EM_VOLUME_LEVEL);
    msg_p->audio_prof.max_melody_volume_gain = p->vol_16_level_max_gain;
    msg_p->audio_prof.melody_volume_gain_step = p->vol_16_level_step;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ, msg_p, NULL);

}


/*****************************************************************************
* FUNCTION
*  EngineerModeSetAudioProfileRes
* DESCRIPTION
*  
* PARAMETERS
*  inMsg       [?]     
* RETURNS
*  void
*****************************************************************************/
U8 EngineerModeSetAudioProfileRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_profile_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP, NULL);
    
    mmi_em_display_notify_popup(rsp_p->result);
	return 0;
}


/*****************************************************************************
* FUNCTION
*  EngineerModeGetAudioParamReq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EngineerModeGetAudioParamReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP, EngineerModeGetAudioParamRes);
    
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ, NULL, NULL);
}


/*****************************************************************************
* FUNCTION
*  EngineerModeGetAudioParamRes
* DESCRIPTION
*  
* PARAMETERS
*  inMsg       [?]     
* RETURNS
*  void
*****************************************************************************/
U8 EngineerModeGetAudioParamRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_param_rsp_struct *rsp_p = (mmi_eq_get_audio_param_rsp_struct*) inMsg;
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP, NULL);

    if (rsp_p->result)
    {
        /* Read debug info from NVRAM directly, not through message*/
        ReadValueSlim(NVRAM_AUDIO_DEBUG_INFO1, &cntx->AudioParam_debug_info[0], DS_DOUBLE);
        ReadValueSlim(NVRAM_AUDIO_DEBUG_INFO2, &cntx->AudioParam_debug_info[4], DS_DOUBLE);
 
        EmUpdateAudioParam((U8*) & (rsp_p->audio_para));
    }
    else
    {
        mmi_em_fail_popup();
    }
	return 0;
}


/*****************************************************************************
* FUNCTION
*  EngineerModeSetAudioParamReq
* DESCRIPTION
*  
* PARAMETERS
*  audioParam      [?]     
* RETURNS
*  void
*****************************************************************************/
void EngineerModeSetAudioParamReq(void *audioParam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_param_req_struct *msg_p;
    audio_param_struct *p = (audio_param_struct*) audioParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP, EngineerModeSetAudioParamRes);

    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_audio_param_req_struct));

    memcpy(&msg_p->audio_para, p, sizeof(audio_param_struct));

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ, msg_p, NULL);
}


/*****************************************************************************
* FUNCTION
*  EngineerModeSetAudioParamRes
* DESCRIPTION
*  
* PARAMETERS
*  inMsg       [?]     
* RETURNS
*  void
*****************************************************************************/
U8 EngineerModeSetAudioParamRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_param_rsp_struct *rsp_p = inMsg;
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP, NULL);
    
    if (rsp_p->result)
    {
        /* Write debug info from NVRAM directly, not through message*/
        WriteValueSlim(NVRAM_AUDIO_DEBUG_INFO1, &cntx->AudioParam_debug_info[0], DS_DOUBLE);
        WriteValueSlim(NVRAM_AUDIO_DEBUG_INFO2, &cntx->AudioParam_debug_info[4], DS_DOUBLE);

    #ifdef __MTK_TARGET__       
        /* Set debug info param to L1 directly. */
        L1Audio_SetDebugInfo(cntx->AudioParam_debug_info);
    #endif /* __MTK_TARGET__ */
    }

    mmi_em_display_notify_popup(rsp_p->result);
	return 0;
}


/*****************************************************************************
* FUNCTION
*  SendSetAudioProfileReq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void SendSetAudioProfileReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSetAudioProfileReq(&mmi_em_aud_cntx_p->gAudioProfile);
}

/*****************************************
 ** Audio->main menu hdlr
 ****************************************/
MMI_EM_INIT_ASM(aud, mmi_em_aud_cntx_p, sizeof(mmi_em_aud_cntx_struct))

static void mmi_em_aud_main_menu_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(aud);
    SendGetAudioParamReq();
    cui_menu_pause(mmi_em_get_main_menu_id());
}

static void mmi_em_aud_main_menu_free_adm_hdlr(void)
{
    MMI_EM_ASM_FREE_FUNC(aud);
    MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(aud));
}


/*****************************************************************************
* FUNCTION
*  EmUpdateAudioProfile
* DESCRIPTION
*  
* PARAMETERS
*  speech          [?]         
*  keytone         [?]         
*  melody          [?]         
*  sound           [?]         
*  mic             [?]         
*  sidetone        [IN]        
* RETURNS
*  void
*****************************************************************************/
void EmUpdateAudioProfile(audio_profile_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(cntx->gAudioProfile.speech, rsp_p->speech, MAX_EM_VOLUME_LEVEL);
    memcpy(cntx->gAudioProfile.keytone, rsp_p->keytone, MAX_EM_VOLUME_LEVEL);
    memcpy(cntx->gAudioProfile.melody, rsp_p->melody, MAX_EM_VOLUME_LEVEL);
    memcpy(cntx->gAudioProfile.sound, rsp_p->sound, MAX_EM_VOLUME_LEVEL);
    memcpy(cntx->gAudioProfile.mic, rsp_p->mic, MAX_EM_VOLUME_LEVEL);
    cntx->gAudioProfile.sidetone = rsp_p->sidetone;
    
    memcpy(cntx->gAudioProfile.tvout, rsp_p->tv_out_volume_gain, MAX_EM_VOLUME_LEVEL);
    cntx->gAudioProfile.vol_16_level_max_gain = rsp_p->max_melody_volume_gain;
    cntx->gAudioProfile.vol_16_level_step = rsp_p->melody_volume_gain_step;
    
    memcpy(&cntx->gAudioProfileOrg, &cntx->gAudioProfile, sizeof(cntx->gAudioProfile));
    
#if defined(__MMI_EM_AUDIO__)
    cntx->gAudioProfile.mode = cntx->currentVolumeMode;
    
    switch (cntx->currentVolumeMode)
    {
        case EM_NORMAL_MODE:
        case EM_HEADSET_MODE:
        case EM_LOUDSP_MODE:
            cui_menu_play(mmi_em_get_main_menu_id());
            break;
    }
#endif /* #if defined(__MMI_EM_AUDIO__) */
}



#if defined(__MMI_EM_AUDIO__)
/*****************************************************************************
 * FUNCTION
 *  custom_em_melody_key_shift
 * DESCRIPTION
 *
 * PARAMETERS
 *  level       [IN]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL mmi_em_aud_melody_key_shift(kal_int32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Media_Control(MEDIA_CTRL_KEY_SHIFT, level) != MEDIA_SUCCESS)
        return KAL_FALSE;;
    return KAL_TRUE;
}

/*****************************************************************************
* FUNCTION
*  SendSetVolumeReq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void SendSetVolumeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSetVolumeReq((U8) mmi_em_aud_cntx_p->currentVolumeType, 
        (U8) mmi_em_aud_cntx_p->currentVolume);
}


/*****************************************************************************
* FUNCTION
*  EngineerModeRingTonePlay
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EngineerModeRingTonePlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
    EngineerModePlayAudioReq(mmi_em_aud_cntx_p->activeRingToneIndex);
}

/*****************************************
 ** Audio->Tone setting
 ****************************************/
/*****************************************************************************
* FUNCTION
*  HighlightRingToneIndex
* DESCRIPTION
*  
* PARAMETERS
*  nIndex      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_ring_tone_hilit_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_aud_cntx_p->isPopup)
    {
        mmi_em_aud_cntx_p->activeRingToneIndex = (U8) nIndex;
        EngineerModeStopAudioReq(0, 0);
        StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_HIGHTLIGHT_DURATION, EngineerModeRingTonePlay);
    }

}

/*****************************************************************************
* FUNCTION
*  mmi_em_aud_ring_tone_list_init
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_ring_tone_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Tone*/
    for (i = 0; i < EM_AUDIO_TONE_NUM; i++)
    {
        kal_wsprintf((WCHAR*)subMenuData[i], "Tone %d", i);
        subMenuDataPtrs[i] = subMenuData[i];
    }
    /* Ring*/
    for (; i < EM_AUDIO_TONE_NUM + EM_AUDIO_RING_NUM; i++)
    {
        kal_wsprintf((WCHAR*)subMenuData[i], "MIDI %d", i - EM_AUDIO_TONE_NUM);
        subMenuDataPtrs[i] = subMenuData[i];
    }    
}


/*****************************************************************************
* FUNCTION
*  mmi_em_aud_popup_finish_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_popup_finish_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_NOTIFYDURATION_TIMER);
    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_AUD_RING_TONE);
    mmi_em_aud_cntx_p->isPopup = MMI_FALSE;
}

static mmi_ret mmi_em_aud_key_up_hdlr_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            U8 MessageString[30];
            U8 key_code;
			
            key_code = (U8)(evt->user_data);
            
            if (KEY_VOL_UP == key_code)
            {
                mmi_em_aud_cntx_p->currentKeyShift += 1;
            }
            else if (KEY_VOL_DOWN == key_code)
            {
                mmi_em_aud_cntx_p->currentKeyShift -= 1;
            }
            
            if (mmi_em_aud_cntx_p->currentKeyShift > MAX_KEY_SHIFT)
            {
                mmi_em_aud_cntx_p->currentKeyShift = MAX_KEY_SHIFT;
            }
            else if (mmi_em_aud_cntx_p->currentKeyShift < (-MAX_KEY_SHIFT))
            {
                mmi_em_aud_cntx_p->currentKeyShift = -MAX_KEY_SHIFT;
            }
            /* currentKeyShift = MIN(currentKeyShift, MAX_KEY_SHIFT); */
            if (!mmi_em_aud_melody_key_shift(mmi_em_aud_cntx_p->currentKeyShift))
            {
                return MMI_RET_OK;
            }

            mmi_em_aud_cntx_p->isPopup = MMI_TRUE;

            if (mmi_em_aud_cntx_p->currentKeyShift > 0)
            {
                kal_wsprintf((WCHAR *) MessageString, "%d halftone Up!", mmi_em_aud_cntx_p->currentKeyShift);
            }
            else if (mmi_em_aud_cntx_p->currentKeyShift < 0)
            {
                kal_wsprintf((WCHAR *) MessageString, "%d halftone Down!", -mmi_em_aud_cntx_p->currentKeyShift); 
            }
            else
            {
                kal_wsprintf((WCHAR *) MessageString, "Key not changed!");
            }

            ShowCategory63Screen(MessageString, 0, NULL);
            
            StartTimer(EM_NOTIFYDURATION_TIMER, EM_NOTIFY_DURATION, mmi_em_aud_popup_finish_hdlr);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            mmi_em_aud_popup_finish_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

static void mmi_em_aud_key_up_hdlr_scrn(U8 key_code)
{
    mmi_frm_scrn_create(
        mmi_em_get_root_group(), 
        SCR_ID_EM_AUD_RING_TONE,
        mmi_em_aud_key_up_hdlr_scrn_proc, 
        (void*)key_code);
}

static mmi_ret mmi_em_aud_ring_tone_scrn_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct* active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
            
            
            mmi_em_aud_ring_tone_list_init();
            ShowCategory6Screen(
                STR_ID_EM_AUD_RING_TONE,
                0,
                STR_GLOBAL_OK, 0,
                STR_GLOBAL_BACK, 0,
                EM_AUDIO_TONE_NUM + EM_AUDIO_RING_NUM,
                (PU8*) subMenuDataPtrs, NULL,
                0, active_evt->gui_buffer);
            
            break;
        }
        
        case EVT_ID_SCRN_INACTIVE:
        {
            mmi_em_aud_ring_tone_menu_exit_hdlr();
            break;
        }
        
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct* cat_evt = (cat_evt_struct *)evt;
            mmi_em_aud_ring_tone_hilit_hdlr(cat_evt->item_index);
            return MMI_RET_CHANGED;
        }
        
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
            
            if (key_evt->key_type == KEY_EVENT_DOWN)
            {
                if (key_evt->key_code == KEY_VOL_UP || key_evt->key_code == KEY_VOL_DOWN)
                {
                    mmi_em_aud_key_up_hdlr_scrn(key_evt->key_code);
                    return MMI_RET_KEY_HANDLED;
                }
            }
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  EntryEmRingToneMenu
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_ring_tone_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_em_get_root_group(), 
        SCR_ID_EM_AUD_RING_TONE_MENU,
        mmi_em_aud_ring_tone_scrn_proc,
        NULL);
}

/*****************************************************************************
* FUNCTION
*  ExitEmRingToneMenu
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_ring_tone_menu_exit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_aud_cntx_p->isPopup)
    {
        /* stop timer */
        StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
        /* stop ring tone */
        /*
        if (mmi_em_aud_cntx_p->activeRingToneIndex >= (gNoOfImy + gNoOfMidi))
        {
            EngineerModeStopAudioReq((U8) (mmi_em_aud_cntx_p->activeRingToneIndex - (gNoOfImy + gNoOfMidi)), AUD_SOUND);
        }
        else if (mmi_em_aud_cntx_p->activeRingToneIndex >= gNoOfImy)
        {
            EngineerModeStopAudioReq((U8) (mmi_em_aud_cntx_p->activeRingToneIndex - gNoOfImy), AUD_MIDI);
        }
        else
        {
            EngineerModeStopAudioReq(mmi_em_aud_cntx_p->activeRingToneIndex, AUD_IMELODY);
        }
        */
        EngineerModeStopAudioReq((U8) (mmi_em_aud_cntx_p->activeRingToneIndex), AUD_SOUND);
    }
}


/*****************************************************************************
* FUNCTION
*  IsAudioProfileChanged
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
BOOL IsAudioProfileChanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_EM_VOLUME_LEVEL; i++)
    {
        if (cntx->gAudioProfile.melody[i] != cntx->gAudioProfileOrg.melody[i] ||
            cntx->gAudioProfile.sound[i] != cntx->gAudioProfileOrg.sound[i] ||
            cntx->gAudioProfile.keytone[i] != cntx->gAudioProfileOrg.keytone[i] ||
            cntx->gAudioProfile.speech[i] != cntx->gAudioProfileOrg.speech[i] || 
            cntx->gAudioProfile.mic[i] != cntx->gAudioProfileOrg.mic[i] ||
            cntx->gAudioProfile.tvout[i] != cntx->gAudioProfileOrg.tvout[i] )
        {
            return MMI_TRUE;
        }
    }

    if (cntx->gAudioProfile.sidetone != cntx->gAudioProfileOrg.sidetone || 
        cntx->gAudioProfile.vol_16_level_max_gain != cntx->gAudioProfileOrg.vol_16_level_max_gain ||
        cntx->gAudioProfile.vol_16_level_step != cntx->gAudioProfileOrg.vol_16_level_step)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  CheckAudioProfile
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void CheckAudioProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsAudioProfileChanged())
    {
        mmi_em_display_confirm(STR_GLOBAL_UPDATE, 
            mmi_em_get_root_group(),
            MMI_EVENT_QUERY, mmi_em_audio_quer_update_proc);
    }
}

static MMI_RET mmi_em_audio_quer_update_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct *)evt;


    switch(alert_evt->result)
    {
        case MMI_ALERT_CNFM_YES:
            SendSetAudioProfileReq();
            break;
        
        default:
            break;
     }
     return MMI_RET_OK;
}
/*****************************************
 ** Audio->Set mode
 ****************************************/
static void mmi_em_aud_set_mode_pre_hdlr(cui_menu_event_struct *evt)
{
    U8 modeList[] = 
    {
        AUD_MODE_NORMAL,
        AUD_MODE_LOUDSPK,
        AUD_MODE_HEADSET
    };
    U8 audio_mode = mdi_audio_get_audio_mode();
    U16 i, audio_mode_index;
    mmi_menu_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    for (i = audio_mode_index = 0; i < 3; i++)
    {
        if (modeList[i] == (U16) audio_mode)
        {
            audio_mode_index = i;
            break;
        }
    }

    menu_id = cui_menu_get_currlist_menu_id_from_index(evt->sender_id, audio_mode_index);
    cui_menu_set_currlist_highlighted_id(evt->sender_id, menu_id);
}

static void mmi_em_aud_set_mode_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[] = 
    {
        STR_ID_EM_AUD_NORMAL_MODE,
        STR_ID_EM_AUD_LOUDSP_MODE,
        STR_ID_EM_AUD_HEADSET_MODE
    };
    U8 modeList[] = 
    {
        AUD_MODE_NORMAL,
        AUD_MODE_LOUDSPK,
        AUD_MODE_HEADSET
    };
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    mdi_audio_set_audio_mode(modeList[index]);
    mmi_em_popup_by_str(ItemList[index], MMI_EVENT_SUCCESS);
}


/*****************************************
 ** Audio->Set valum
 ****************************************/
/*****************************************************************************
* FUNCTION
*  EmAudioVolumeUp
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_show_volume_scrn(U8 key_code)
{
    if (
    #ifndef __COSMOS_MMI__
        key_code == KEY_UP_ARROW ||
    #else
        key_code == KEY_SEND ||
    #endif
        key_code == KEY_VOL_UP
    )
    {
        mmi_em_aud_cntx_p->currentVolume += VOLUME_STEP;

        if (mmi_em_aud_cntx_p->currentVolume >= MAX_VOLUME)
        {
            mmi_em_aud_cntx_p->currentVolume = MAX_VOLUME;
        }
    }
    
    if (
    #ifndef __COSMOS_MMI__
        key_code == KEY_DOWN_ARROW ||
    #else
        key_code == KEY_BACK ||
    #endif
        key_code == KEY_VOL_DOWN
    )
    {
        mmi_em_aud_cntx_p->currentVolume -= VOLUME_STEP;

        if (mmi_em_aud_cntx_p->currentVolume <= MIN_VOLUME)
        {
            mmi_em_aud_cntx_p->currentVolume = MIN_VOLUME;
        }
    }

    ShowCategory204Screen(STR_ID_EM_SET_LSK, 0, 
        STR_GLOBAL_BACK, 0, 
        STR_ID_EM_AUD_SET_VOLUME, 
        mmi_em_aud_cntx_p->currentVolume, 0, 0);
}

/*****************************************************************************
* FUNCTION
*  EmGetCurrentVolume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
U8 EmGetCurrentVolume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_em_aud_cntx_p->currentVolumeType)
    {
    case EM_VOL_TYPE_SPH:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.speech[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.sp_gain;
        }
    case EM_VOL_TYPE_KEY:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.keytone[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.kt_gain;
        }
    case EM_VOL_TYPE_MIC:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.mic[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.mic_gain;
        }
    case EM_VOL_TYPE_SID:
        return mmi_em_aud_cntx_p->gAudioProfile.sidetone;
    case EM_VOL_TYPE_MEDIA:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.melody[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.mel_gain;
        }
    case EM_VOL_TYPE_SND:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.sound[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.snd_gain;
        }
    case EM_VOL_TYPE_TVOUT:
        if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
        {
            return mmi_em_aud_cntx_p->gAudioProfile.tvout[mmi_em_aud_cntx_p->hilit_index];
        }
        else
        {
            return mmi_em_aud_cntx_p->gAudioProfile.tvout_gain;
        }
    default:
        return 0;
    }
}

static void mmi_em_audio_set_volume_type_value(U8* volume1, U8* volume2)
{
    if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
    {
        *volume1 = mmi_em_aud_cntx_p->currentVolume;
    }
    else
    {
        SendSetVolumeReq();
        *volume2 = mmi_em_aud_cntx_p->currentVolume;
    }
}
/*****************************************************************************
* FUNCTION
*  EmSetVolume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EmSetVolume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilit_index = mmi_em_aud_cntx_p->hilit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_em_aud_cntx_p->currentVolumeType)
    {
    case EM_VOL_TYPE_SPH:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.speech[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.sp_gain);
        break;
    case EM_VOL_TYPE_KEY:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.keytone[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.kt_gain);
        break;
    case EM_VOL_TYPE_MIC:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.mic[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.mic_gain);
        break;
    case EM_VOL_TYPE_SID:
        mmi_em_aud_cntx_p->gAudioProfile.sidetone = (U8) mmi_em_aud_cntx_p->currentVolume;
        break;
    case EM_VOL_TYPE_MEDIA:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.melody[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.mel_gain);
        break;
    case EM_VOL_TYPE_SND:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.sound[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.snd_gain);
        break;
    case EM_VOL_TYPE_TVOUT:
        mmi_em_audio_set_volume_type_value(
            &mmi_em_aud_cntx_p->gAudioProfile.tvout[hilit_index],
            &mmi_em_aud_cntx_p->gAudioProfile.tvout_gain);
        break;
    }

    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_AUD_RING_TONE);
}

static void mmi_em_aud_set_valum_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_em_aud_cntx_p->hilit_index < MAX_EM_VOLUME_LEVEL)
    {
        EntryEmSideTone();
    }
    else if (mmi_em_aud_cntx_p->hilit_index == MAX_EM_VOLUME_LEVEL)  /* 16 Level */
    {
        mmi_em_aud_set_valum_inline_scrn();
    }
}

static const cui_inline_item_caption_struct g_mmi_em_aud_gain_cap = 
{
    STR_ID_EM_AUD_16_LELVEL_MAX_GAIN,
};

static const cui_inline_item_text_edit_struct g_mmi_em_aud_gain_edit =
{
    0, 0, 4, IMM_INPUT_TYPE_NUMERIC, 0, NULL,
};

static const cui_inline_item_caption_struct g_mmi_em_aud_step_cap = 
{
    STR_ID_EM_AUD_16_LELVEL_STEP,
};

static const cui_inline_item_text_edit_struct g_mmi_em_aud_step_edit =
{
    0, 0, 4, IMM_INPUT_TYPE_NUMERIC, 0, NULL,
};

static const cui_inline_set_item_struct g_mmi_em_aud_level_set_inline[] = 
{
    {MMI_EM_AUD_GAIN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_aud_gain_cap},
    {MMI_EM_AUD_GAIN_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_aud_gain_edit},
    {MMI_EM_AUD_STEP_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_aud_step_cap},
    {MMI_EM_AUD_STEP_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_aud_step_edit}
};

static const cui_inline_struct g_mmi_em_aud_level_set_inline_scrn = 
{
    sizeof(g_mmi_em_aud_level_set_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_AUD_16_LELVEL_VOLUME,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_aud_level_set_inline
};

static MMI_RET mmi_em_aud_set_valum_inline_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 int_gain;
    U16 int_step;
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inline_evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            cui_inline_get_value(inline_evt->sender_id, 
                         MMI_EM_AUD_GAIN_EDIT, 
                         (void *) mmi_em_aud_cntx_p->MaxAnalogGain);
            cui_inline_get_value(inline_evt->sender_id, 
                         MMI_EM_AUD_STEP_EDIT, 
                         (void *) mmi_em_aud_cntx_p->Step);
            int_gain = mmi_wcs_wtoi((WCHAR *) mmi_em_aud_cntx_p->MaxAnalogGain);
            int_step = mmi_wcs_wtoi((WCHAR *) mmi_em_aud_cntx_p->Step);
            if (int_gain > 255)
                int_gain = 255;
            if (int_step > 255)
                int_step = 255;
            mmi_em_aud_cntx_p->gAudioProfile.vol_16_level_max_gain = (U8)int_gain;
            mmi_em_aud_cntx_p->gAudioProfile.vol_16_level_step = (U8)int_step;
            cui_inline_close(inline_evt->sender_id);
        }
        break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

static void mmi_em_aud_set_valum_inline_scrn(void)
{
    U8  gain = 0;
    U8  step = 0;
    MMI_ID gid;
    MMI_ID inline_id;

    gain = mmi_em_aud_cntx_p->gAudioProfile.vol_16_level_max_gain;
    step = mmi_em_aud_cntx_p->gAudioProfile.vol_16_level_step;

    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_aud_set_valum_inline_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);
              
    inline_id = cui_inline_create(gid, &g_mmi_em_aud_level_set_inline_scrn);
    kal_wsprintf(mmi_em_aud_cntx_p->MaxAnalogGain, "%d", gain);
    cui_inline_set_value(inline_id, MMI_EM_AUD_GAIN_EDIT, (void*)mmi_em_aud_cntx_p->MaxAnalogGain);
    kal_wsprintf(mmi_em_aud_cntx_p->Step, "%d", step);
    cui_inline_set_value(inline_id, MMI_EM_AUD_STEP_EDIT, (void*)mmi_em_aud_cntx_p->Step);
    cui_inline_run(inline_id);
}

/*****************************************
 ** Audio->Set side tone
 ****************************************/
static mmi_ret mmi_em_aud_set_side_tone_scrn_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_em_aud_cntx_p->currentVolume = EmGetCurrentVolume();
            ShowCategory204Screen(STR_ID_EM_SET_LSK, 0, 
                STR_GLOBAL_BACK, 0, STR_ID_EM_AUD_SET_VOLUME, 
                mmi_em_aud_cntx_p->currentVolume, 0, 0);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            EmSetVolume();
            return MMI_RET_KEY_HANDLED;
        }
        
        case EVT_ID_ON_KEY:
        {
            MMI_BOOL result = MMI_FALSE;
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
            
            if (key_evt->key_type == KEY_EVENT_DOWN)
            {
                if (key_evt->key_code == KEY_VOL_UP || key_evt->key_code == KEY_VOL_DOWN)
                    result = MMI_TRUE;

            #ifndef __COSMOS_MMI__
                if (key_evt->key_code == KEY_UP_ARROW || key_evt->key_code == KEY_DOWN_ARROW)
                    result = MMI_TRUE;
            #endif

            #ifdef __COSMOS_MMI__
                if (key_evt->key_code == KEY_SEND || key_evt->key_code == KEY_BACK)
                    result = MMI_TRUE;
            #endif

                if (result)
                {
                    mmi_em_aud_show_volume_scrn(key_evt->key_code);
                    return MMI_RET_KEY_HANDLED;
                }
            }
            
            if (key_evt->key_code == KEY_EVENT_UP)
            {
                return MMI_RET_KEY_HANDLED;
            }
            break;
        }
        
        default:
            break;            
    }
    
    return MMI_RET_OK;
}
/*****************************************************************************
* FUNCTION
*  EntryEmSideTone
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryEmSideTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(
        mmi_em_get_root_group(),
        SCR_ID_EM_AUD_RING_TONE,
        mmi_em_aud_set_side_tone_scrn_proc,
        NULL);
}

/*****************************************************************************
* FUNCTION
*  SendGetAudioProfileReq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void SendGetAudioProfileReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeGetAudioProfileReq((U8) mmi_em_aud_cntx_p->currentVolumeMode);
}

/*****************************************
 ** Audio->Normal mode->Fir
 ****************************************/
static void mmi_em_aud_normal_mode_fir_pre_hdlr(cui_menu_event_struct *evt)
{
    mmi_menu_id menu_id;


    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    if (mmi_em_aud_cntx_p->AudioParameter.selected_FIR_output_index > 8)
    {
        mmi_em_aud_cntx_p->AudioParameter.selected_FIR_output_index = 0;//just fix menu cui issue
    }
    menu_id = cui_menu_get_currlist_menu_id_from_index(evt->sender_id, 
                  mmi_em_aud_cntx_p->AudioParameter.selected_FIR_output_index);
    cui_menu_set_currlist_highlighted_id(evt->sender_id, menu_id);
}

static void mmi_em_aud_normal_mode_fir_hdlr(cui_menu_event_struct *evt)
{
    S32 index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;


    cntx->AudioParameter.selected_FIR_output_index = index;    
    EngineerModeSetAudioParamReq(&cntx->AudioParameter);
}

static void mmi_em_aud_mode_hdlr(EmVolumeModeEnum mode_type)
{
    mmi_em_aud_cntx_p->currentVolumeMode = mode_type;
    SendGetAudioProfileReq();
    cui_menu_pause(mmi_em_get_main_menu_id());
}
#endif /* (__MMI_EM_AUDIO__) */

/*****************************************
 ** Audio->Param edit setting
 ****************************************/
#if defined( __MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__)
/*****************************************************************************
* FUNCTION
*  mmi_em_aud_set_param_edit_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_aud_set_param_edit_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 level = 0;
    S32 hilit_index = 0;
    mmi_em_num_editor_struct cntx = {0};
#ifdef __MMI_EM_AUDIO__
    audio_param_struct * param = &(mmi_em_aud_cntx_p->AudioParameter);
    U16 (*speech_mode_para)[8][16];
#endif //__MMI_EM_AUDIO__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilit_index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
#ifdef __MMI_EM_AUDIO__
    speech_mode_para = &param->speech_mode_para;
#endif //__MMI_EM_AUDIO__
    switch (evt->parent_menu_id)
    {
    #ifdef __MMI_EM_AUDIO__
        case MENU_ID_EM_AUD_SPH_ENH_COMMON_PARA:
            level = (S32) param->speech_common_para[hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_NORMAL_MODE:
            level = (S32) (*speech_mode_para)[0][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_HEADSET_MODE:
            level = (S32) (*speech_mode_para)[1][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_LOUDSPK_MODE:
            level = (S32) (*speech_mode_para)[2][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE:
            level = (S32) (*speech_mode_para)[3][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE:
            level = (S32) (*speech_mode_para)[4][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_AUX1_MODE:
            level = (S32) (*speech_mode_para)[5][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_AUX2_MODE:
            level = (S32) (*speech_mode_para)[6][hilit_index];
            break;
        case MENU_ID_EM_AUD_SPH_ENH_AUX3_MODE:
            level = (S32) (*speech_mode_para)[7][hilit_index];
            break;
    #endif /* __MMI_EM_AUDIO__ */
    #ifdef __MMI_EM_AUDIO_DEBUG_INFO__    
        case MENU_ID_EM_AUD_DEBUG_INFO:
            level = (S32) mmi_em_aud_cntx_p->AudioParam_debug_info[hilit_index];
            break;
    #endif/*__MMI_EM_AUDIO_DEBUG_INFO__*/
        default:
            return;
    }

    mmi_em_aud_cntx_p->hilit_index = hilit_index;
    cntx.value = level;
    cntx.notify = mmi_em_aud_set_param_hdlr;
    cntx.user_data = (void*)evt->parent_menu_id;
    
    kal_wsprintf((WCHAR*)cntx.title_str, "%w %d", get_string(STR_ID_EM_AUD_PARAMETER), hilit_index);
    
    mmi_em_show_num_editor(&cntx);
}
#endif /*(defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO__))*/
static void mmi_em_aud_set_param_hdlr(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;
    S32 hilit_index = mmi_em_aud_cntx_p->hilit_index;
    audio_param_struct * param = &(mmi_em_aud_cntx_p->AudioParameter);
#ifdef __MMI_EM_AUDIO__ 
    U16 (*speech_mode_para)[8][16];
#endif //__MMI_EM_AUDIO__ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_AUDIO__ 
    speech_mode_para = &param->speech_mode_para;
#endif //__MMI_EM_AUDIO__ 
    menu_id = (mmi_menu_id)(0x0FFFF & ((U32)user_data));
    switch (menu_id)
    {
    #ifdef __MMI_EM_AUDIO__ 
        case MENU_ID_EM_AUD_SPH_ENH_COMMON_PARA:
            param->speech_common_para[hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_NORMAL_MODE:
            (*speech_mode_para)[0][hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_HEADSET_MODE:
            (*speech_mode_para)[1][hilit_index] = output_num;
            break;
        
        case MENU_ID_EM_AUD_SPH_ENH_LOUDSPK_MODE:
            (*speech_mode_para)[2][hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE:
            (*speech_mode_para)[3][hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE:
            (*speech_mode_para)[4][hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_AUX1_MODE:
            (*speech_mode_para)[5][hilit_index] = output_num;
            break;

        case MENU_ID_EM_AUD_SPH_ENH_AUX2_MODE:
            (*speech_mode_para)[6][hilit_index] = output_num;
            break;
            
        case MENU_ID_EM_AUD_SPH_ENH_AUX3_MODE:
            (*speech_mode_para)[7][hilit_index] = output_num;
            break;
    #endif /*  __MMI_EM_AUDIO__  */
    #ifdef __MMI_EM_AUDIO_DEBUG_INFO__
        case MENU_ID_EM_AUD_DEBUG_INFO:
            mmi_em_aud_cntx_p->AudioParam_debug_info[hilit_index] = output_num;
            break;
    #endif/*__MMI_EM_AUDIO_DEBUG_INFO__*/ 
    }

    EngineerModeSetAudioParamReq(param);    
}

/*****************************************************************************
* FUNCTION
*  EmUpdateAudioParam
* DESCRIPTION
*  
* PARAMETERS
*  audp        [?]     
* RETURNS
*  void
*****************************************************************************/
void EmUpdateAudioParam(U8 *audp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_param_struct *p = (audio_param_struct*) audp;
    mmi_em_aud_cntx_struct *cntx = mmi_em_aud_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&cntx->AudioParameter, p, sizeof(audio_param_struct));
    cui_menu_play(mmi_em_get_main_menu_id());
}


/*****************************************************************************
* FUNCTION
*  SendGetAudioParamReq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void SendGetAudioParamReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeGetAudioParamReq();
}

/*****************************************
 ** Audio->Auto Record setting
 ****************************************/
#ifdef __MMI_EM_AUDIO_AUTO_VM__
#include "mmi_rp_srv_soundrec_def.h"
#include "SoundRecSrvGProt.h"

void mmi_em_aud_auto_vm_setting_init(void)
{
    U8 ret_value =0;
    MMI_BOOL is_on;
    
    ReadValueSlim(NVRAM_AUTO_VM_SETTING_AUTO_VM, (void*)&ret_value, DS_BYTE);
    if(ret_value == 0)
		is_on = MMI_FALSE;
	else
		is_on = MMI_TRUE;

    srv_soundrec_auto_record_set_status(is_on);
}

static void mmi_em_aud_auto_vm_setting_pre_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret_value;
    mmi_menu_id highlight_menu_id = MENU_ID_EM_MISC_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    
    ReadValueSlim(NVRAM_AUTO_VM_SETTING_AUTO_VM, (void*)&ret_value, DS_BYTE);

    if (ret_value)
    {
        highlight_menu_id = MENU_ID_EM_MISC_ON;
    }
    
    cui_menu_set_currlist_highlighted_id(evt->sender_id, highlight_menu_id);
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

#if 0
#if (defined(__MMI_SOUND_RECORDER__) && defined(__PLUTO_MMI_PACKAGE__) && defined(__VM_CODEC_SUPPORT__))
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
/* under construction !*/
/* under construction !*/
#endif
#endif
}

static void mmi_em_aud_auto_vm_setting_hdlr(cui_menu_event_struct *evt)
{
    U8 ret_value =0;
    MMI_BOOL is_on;

    if (MENU_ID_EM_MISC_ON == evt->highlighted_menu_id)
        ret_value = 1;

    WriteValueSlim(NVRAM_AUTO_VM_SETTING_AUTO_VM, (void*)&ret_value, DS_BYTE);
    if(ret_value == 0)
		is_on = MMI_FALSE;
	else
		is_on = MMI_TRUE;    

    srv_soundrec_auto_record_set_status(is_on);
    mmi_em_display_notify_popup(MMI_TRUE);

#if 0
#if (defined(__MMI_SOUND_RECORDER__) && defined(__PLUTO_MMI_PACKAGE__) && defined(__VM_CODEC_SUPPORT__))
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}
#endif/*__MMI_EM_AUDIO_AUTO_VM__*/


/******
 ** notify screen. notify user how to modify parameter.
 ******/
#ifdef __MMI_EM_AUDIO__
static mmi_ret mmi_em_audio_notify_confirm_proc(mmi_event_struct *param);

void mmi_em_audio_notify_scrn(cui_menu_event_struct *evt)
{
    S32 index = 0;

    
    index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    mmi_em_aud_cntx_p->hilit_index = index;
    mmi_em_aud_cntx_p->cur_hight_id = evt->highlighted_menu_id;
    
    mmi_em_display_confirm_by_str(
    #ifdef __COSMOS_MMI__
        L"send key: value up.\nback key: value down.",
    #else
        L"up key: value up.\ndown key: value down.",
    #endif
        mmi_em_get_root_group(),
        MMI_EVENT_INFO,
        mmi_em_audio_notify_confirm_proc);
}

static mmi_ret mmi_em_audio_notify_confirm_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
    switch (alert->result)
    {
        case MMI_ALERT_CNFM_YES:
        {
            if (MENU_ID_EM_AUD_SIDE_TONE == mmi_em_aud_cntx_p->cur_hight_id)
            {
                mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_SID;
                EntryEmSideTone();
            }
            else
            {
                mmi_em_aud_set_valum_scrn();
            }
            break;
        }
          
          default:
            break;
    }

    return MMI_RET_OK;
}
#endif /* __MMI_EM_AUDIO__ */

void mmi_em_audio_menu_entry_event_hdlr(cui_menu_event_struct *evt)
{
    switch(evt->parent_menu_id)
    {
    #ifdef __MMI_EM_AUDIO__
        /*****************************************
         ** Audio->Set mode
         ****************************************/
        case MENU_ID_EM_AUD_SET_MODE:
            mmi_em_aud_set_mode_pre_hdlr(evt);
            break;

        /*****************************************
         ** Audio->Normal mode
         ****************************************/
        case MENU_ID_EM_AUD_FIR:
            mmi_em_aud_normal_mode_fir_pre_hdlr(evt);
            break;
    #endif /* __MMI_EM_AUDIO__ */

    #ifdef __MMI_EM_AUDIO__
        case MENU_ID_EM_AUD_SPH_ENH_COMMON_PARA:
        case MENU_ID_EM_AUD_SPH_ENH_NORMAL_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_HEADSET_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_LOUDSPK_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX1_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX2_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX3_MODE:
        {
            mmi_em_set_menu_list_items_title(evt->sender_id, STR_ID_EM_AUD_PARAMETER);
            break;
        }
    #endif

    #ifdef __MMI_EM_AUDIO_DEBUG_INFO__
        case MENU_ID_EM_AUD_DEBUG_INFO:
        {
            mmi_em_set_menu_list_items_title(evt->sender_id, STR_ID_EM_AUD_PARAMETER);
            break;
        }
    #endif
    
    /*****************************************
     ** Audio->Auto recode
     ****************************************/
    #ifdef __MMI_EM_AUDIO_AUTO_VM__
        case MENU_ID_EM_AUD_AUTO_VM_SETTING:
            mmi_em_aud_auto_vm_setting_pre_hdlr(evt);
            break;
    #endif

        default:
            break;
    }
}

void mmi_em_audio_menu_sel_event_hdlr(cui_menu_event_struct *event)
{
    if (event->highlighted_menu_id == MENU_ID_EM_MISC_ON ||
        event->highlighted_menu_id == MENU_ID_EM_MISC_OFF)
    {
        switch(event->parent_menu_id)
        {
         #ifdef __MMI_EM_AUDIO_AUTO_VM__
            case MENU_ID_EM_AUD_AUTO_VM_SETTING:
                mmi_em_aud_auto_vm_setting_hdlr(event);
                break;
         #endif /*__MMI_EM_AUDIO_AUTO_VM__*/
            default:
                break;
        }
        return;
    }
    
    switch(event->parent_menu_id)
    {
    #ifdef __MMI_EM_AUDIO__
        /*****************************************
         ** Audio->main menu hdlr
         ****************************************/
        case MENU_ID_EM_AUD_SET_MODE:
            mmi_em_aud_set_mode_hdlr(event);
            break;
        /*****************************************
         ** Audio->Mode Parameter setting
         ****************************************/
        case MENU_ID_EM_AUD_FIR:
            mmi_em_aud_normal_mode_fir_hdlr(event);
            break;

        case MENU_ID_EM_AUD_SPEECH:
        case MENU_ID_EM_AUD_KEY_TONE:
        case MENU_ID_EM_AUD_MELODY:
        case MENU_ID_EM_AUD_SOUND:
        case MENU_ID_EM_AUD_MICROPHONE:
        case MENU_ID_EM_AUD_SIDE_TONE:
            mmi_em_audio_notify_scrn(event);
            break;

        case MENU_ID_EM_AUD_SPH_ENH_COMMON_PARA:
        case MENU_ID_EM_AUD_SPH_ENH_NORMAL_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_HEADSET_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_LOUDSPK_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX1_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX2_MODE:
        case MENU_ID_EM_AUD_SPH_ENH_AUX3_MODE:
    #endif /* __MMI_EM_AUDIO__ */
    #ifdef __MMI_EM_AUDIO_DEBUG_INFO__    
        case MENU_ID_EM_AUD_DEBUG_INFO:
    #endif/*__MMI_EM_AUDIO_DEBUG_INFO__*/
    #if defined( __MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) 
            mmi_em_aud_set_param_edit_hdlr(event);
            break;
    #endif /*(defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO__))*/
        default:
            break;
    }

    switch(event->highlighted_menu_id)
    {
        case MENU_ID_EM_AUDIO:
            mmi_em_aud_main_menu_hdlr();
            break;

    #ifdef __MMI_EM_AUDIO__
       /*****************************************
       ** Audio->main menu hdlr
       ****************************************/
        case MENU_ID_EM_AUD_NORMAL_MODE:
            mmi_em_aud_mode_hdlr(EM_NORMAL_MODE);
            break;

        case MENU_ID_EM_AUD_LOUDSP_MODE:
            mmi_em_aud_mode_hdlr(EM_LOUDSP_MODE);
            break;

        case MENU_ID_EM_AUD_HEADSET_MODE:
            mmi_em_aud_mode_hdlr(EM_HEADSET_MODE);
            break;
    
        case MENU_ID_EM_AUD_SPEECH:
            mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_SPH;
            break;

        case MENU_ID_EM_AUD_KEY_TONE:
            mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_KEY;
            break;
            
        case MENU_ID_EM_AUD_MELODY:
            mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_MEDIA;
            break;
            
        case MENU_ID_EM_AUD_SOUND:
            mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_SND;
            break;
            
        case MENU_ID_EM_AUD_MICROPHONE:
            mmi_em_aud_cntx_p->currentVolumeType = EM_VOL_TYPE_MIC;
            break;
            
        case MENU_ID_EM_AUD_SIDE_TONE:
            mmi_em_audio_notify_scrn(event);
            break;

        case MENU_ID_EM_AUD_RING_TONE:
            mmi_em_aud_ring_tone_hdlr();
            break;
    #endif /* __MMI_EM_AUDIO__ */

        default:
            break;
    }
}

void mmi_em_aud_menu_exit_event_hdlr(cui_menu_event_struct *evt)
{
    switch(evt->parent_menu_id)
    {
        case MENU_ID_EM_AUDIO:
            if (1 == evt->cui_menu_event_flags)
            {
                mmi_em_aud_main_menu_free_adm_hdlr();
            }
            break;
    #ifdef __MMI_EM_AUDIO__
         case MENU_ID_EM_AUD_NORMAL_MODE:
         case MENU_ID_EM_AUD_LOUDSP_MODE:
         case MENU_ID_EM_AUD_HEADSET_MODE:
             if (1 == evt->cui_menu_event_flags)
             {
                 CheckAudioProfile();
             }
             break;
    #endif /* __MMI_EM_AUDIO__ */
    }
}
#endif //defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  

#endif /* __MMI_ENGINEER_MODE__ */


