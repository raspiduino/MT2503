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
*   avk_mm_profile.cpp
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
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
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

extern "C"
{
#include "SettingDefs.h"        
#include "CommonScreens.h"      
#include "FileMgrGProt.h"
#include "SettingProfile.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_multimedia.h"
}


typedef struct
{

	U32 m_nCurCaseIdx;
	U8 m_nProfileCount;
	U8 m_nRingLevel;
	
} vs_service_profile_context_struct;

typedef void (*testFunctionEntry) (void);
typedef struct
{
	U32 m_itemIdx;
	WCHAR* m_pwszItemName;
	testFunctionEntry m_pfunc;
}vs_service_profile_test_item_struct;


void vs_service_profile_001_play_tone(void);
void vs_service_profile_002_play_tone_with_filepath(void);
void vs_service_profile_003_play_tone_with_full_struct(void);
void vs_service_profile_004_play_tone_with_id(void);
void vs_service_profile_005_play_tone_with_text(void);
void vs_service_profile_006_active_mode(void);
void vs_service_profile_007_deactive_mode(void);
void vs_service_profile_008_get_file_path_by_audio_id(void);
void vs_service_profile_009_get_num_of_profiles(void);
void vs_service_profile_010_get_ring_vol(void);



WCHAR g_wstrPath[20] = {'c',':','\\','\\','p','r','o','f','i','l','e','.','m','p','3','\0'};


vs_service_profile_context_struct g_vs_service_profile_context;



#define VS_SERVICE_PROFILE_MAX_TEST_CASE_COUNT 128



/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_display_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  coordinate        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_display_screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR wszBuf[256] = {0};
	S32 index = g_vs_service_profile_context.m_nCurCaseIdx+1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_move_text_cursor(5, 130);

	switch (index)
	{
		case 1:
			gui_print_bordered_text((UI_string_type) L"hear sound?");
			break;
		case 2:
			gui_print_bordered_text((UI_string_type) L"hear sound?");

			break;
		case 3:
			gui_print_bordered_text((UI_string_type) L"hear sound?");
			
			break;
		case 4:
			gui_print_bordered_text((UI_string_type) L"hear sound?");

			break;
		case 5:
			gui_print_bordered_text((UI_string_type) L"hear sound?"); 

			break;
		case 6:
			gui_print_bordered_text((UI_string_type) L"active slient mode ");
			gui_move_text_cursor(5,170);
			gui_print_bordered_text((UI_string_type) L"you should not hear ");
			break;
		case 7:
			gui_print_bordered_text((UI_string_type) L"deactive slient mode ");
			gui_move_text_cursor(5,170);
			gui_print_bordered_text((UI_string_type) L"you should hear tone");
			break;
		case 8:

			gui_print_bordered_text((UI_string_type) L"already done,press pass");

			
			break;
		case 9:
			kal_wsprintf(wszBuf,"total %d profiles",g_vs_service_profile_context.m_nProfileCount);
			gui_print_bordered_text((UI_string_type)wszBuf);

			break;
		case 10:
			kal_wsprintf(wszBuf,"ring vol is %d",g_vs_service_profile_context.m_nRingLevel);			
			gui_print_bordered_text((UI_string_type)wszBuf);

			break;
			
		default:
			break;
	}

}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_log_and_return
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bSuccess        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_log_and_return(MMI_BOOL bSuccess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	//vs_tfw_trace_result(g_vs_service_profile_test_item_array[g_vs_service_profile_context.m_nCurCaseIdx].m_pwszItemName, bSuccess, 0, VS_TA_SERVICE_PROFILE);
	//vs_tfw_finish_case_extern(g_vs_service_profile_test_item_array[g_vs_service_profile_context.m_nCurCaseIdx].m_itemIdx, SCR_ID_VS_PROFILE_001);

}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_play_pass
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_play_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(srv_prof_is_tone_playing(INCOMING_CALL_TONE))
	{
		srv_profiles_stop_tone(INCOMING_CALL_TONE);
	}
	AVK_LOG_FUN(srv_prof_is_tone_playing,AVK_PASS);
	AVK_LOG_FUN(srv_profiles_stop_tone,AVK_PASS);

	
	vs_service_profile_log_and_return(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_play_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_play_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(srv_prof_is_tone_playing(INCOMING_CALL_TONE))
	{
		srv_profiles_stop_tone(INCOMING_CALL_TONE);
	}
	AVK_LOG_FUN(srv_prof_is_tone_playing,AVK_PASS);
	AVK_LOG_FUN(srv_profiles_stop_tone,AVK_PASS);
	vs_service_profile_log_and_return(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_prompt_screen_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_prompt_screen_enter(void)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_PROFILE_002, NULL, vs_service_profile_prompt_screen_enter, MMI_FRM_FULL_SCRN);
	ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_service_profile_display_screen, NULL);

	AVK_SET_PASSKEY(vs_service_profile_play_pass);
	AVK_SET_FAILKEY(vs_service_profile_play_fail);
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_001_play_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_service_profile_001_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;
	MDI_AUDIO_PLAY_MODE_ENUM mdi_audio_play_mode;
	
	srv_prof_volume_level volume;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_vs_service_profile_context.m_nCurCaseIdx = 0;
	srv_prof_is_setting_available(SRV_PROF_SETTINGS_RING_VOL_LEVEL);
	AVK_LOG_FUN(srv_prof_is_setting_available,AVK_PASS);

	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void *)&volume);
	AVK_LOG_FUN(srv_prof_get_current_profile_value,AVK_PASS);

	srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void *)&volume);	
	AVK_LOG_FUN(srv_prof_set_current_profile_value,AVK_PASS);

	srv_prof_set_current_profile_tone_with_file_path(SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE, (WCHAR*)L"d:\\card4mt.mid");
	AVK_LOG_FUN(srv_prof_set_current_profile_tone_with_file_path,AVK_PASS);
	
	srv_prof_if_can_vibrate();
	AVK_LOG_FUN(srv_prof_if_can_vibrate,AVK_PASS);

	vs_service_profile_prompt_screen_enter();
	mdi_audio_play_mode = srv_prof_play_tone_query_mdi_play_mode(INCOMING_CALL_TONE);
	AVK_LOG_FUN(srv_prof_play_tone_query_mdi_play_mode,AVK_PASS);

	ret = srv_prof_play_tone(INCOMING_CALL_TONE,NULL);
	AVK_LOG_FUN(srv_prof_play_tone,AVK_PASS);

	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "vs_service_profile_001_play_tone fail");

	}
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_002_play_tone_with_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_service_profile_002_play_tone_with_filepath(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	char letter;
	g_vs_service_profile_context.m_nCurCaseIdx = 1;
	vs_service_profile_prompt_screen_enter();
	letter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

	if (letter>='a'&& letter<='z')
	{
		g_wstrPath[0] = L'a'+ (char)letter - 'a';
	}
	if (letter>='A'&& letter<='Z')
	{
		g_wstrPath[0] = L'A'+(char)letter - 'A';
	}

	ret = srv_prof_play_tone_with_filepath(
		INCOMING_CALL_TONE, 
		g_wstrPath,
		SRV_PROF_RING_TYPE_REPEAT, 
		NULL
		);
	
	AVK_LOG_FUN(srv_prof_play_tone_with_filepath,AVK_PASS);

	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "vs_service_profile_002_play_tone_with_filepath fail");
	}

}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_003_play_tone_with_full_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_service_profile_003_play_tone_with_full_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;
	srv_prof_audio_id audio_id; 
	srv_prof_volume_level volume;
	srv_prof_play_req_struct play_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 2;
	vs_service_profile_prompt_screen_enter();
	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void *)&volume);
	AVK_LOG_FUN(srv_prof_get_current_profile_value,AVK_PASS);

	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_TONE,(void*)&audio_id);	
	AVK_LOG_FUN(srv_prof_get_current_profile_value,AVK_PASS);

	srv_prof_play_req_struct_init(&play_req, INCOMING_CALL_TONE);
	AVK_LOG_FUN(srv_prof_play_req_struct_init,AVK_PASS);

	play_req.audio_id = audio_id;
	play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
	play_req.volume = volume;
	play_req.tone_type = INCOMING_CALL_TONE;
	play_req.aud_path = MDI_DEVICE_SPEAKER_BOTH;
	play_req.callback = NULL;
	play_req.audio_type = SRV_PROF_AUDIO_STRING;
	ret =srv_prof_play_tone_with_full_struct(&play_req);
	
	AVK_LOG_FUN(srv_prof_play_tone_with_full_struct,AVK_PASS);
	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "vs_service_profile_003_play_tone_with_full_struct fail");
	}
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_004_play_tone_with_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_service_profile_004_play_tone_with_id(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	g_vs_service_profile_context.m_nCurCaseIdx = 3;
	vs_service_profile_prompt_screen_enter();
	ret = srv_prof_play_tone_with_id(INCOMING_CALL_TONE, 
		SRV_PROF_AUD_RING1, 
		SRV_PROF_RING_TYPE_REPEAT, 
		NULL);
	
	AVK_LOG_FUN(srv_prof_play_tone_with_id,AVK_PASS);

	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "vs_service_profile_004_play_tone_with_id fail");
	}
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_005_play_tone_with_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_005_play_tone_with_text(void)
{
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 4;
	vs_service_profile_prompt_screen_enter();

    ret = srv_prof_play_tone_with_text(SRV_PROF_TONE_INCOMING_CALL, 
                                          (U8*)L"123",
                                          100,
                                          NULL);
	
	AVK_LOG_FUN(srv_prof_play_tone_with_text,AVK_PASS);

		kal_prompt_trace(MOD_IDLE, "profile_005 ret =%d",ret);
	


#else
	AVK_LOG_FUN_UNSUPPORTED(srv_prof_play_tone_with_text);

	AVK_ASYN_DONE();
#endif

}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_006_active_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_006_active_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 5;
	vs_service_profile_prompt_screen_enter();
	ret = srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
	AVK_LOG_FUN(srv_prof_activate_profile_by_external_module,AVK_PASS);
	
	if(SRV_PROF_RET_FAIL == ret || SRV_PROF_RET_PROFILE_NOT_SUPPORTED == ret )
	{
		kal_prompt_trace(MOD_IDLE, "vs_service_profile_006_active_mode fail error %d",ret);
	}

	ret = srv_prof_play_tone_with_id(INCOMING_CALL_TONE, 
		SRV_PROF_AUD_RING1, 
		SRV_PROF_RING_TYPE_REPEAT, 
		NULL);
	
	AVK_LOG_FUN(srv_prof_play_tone_with_id,AVK_PASS);

	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "srv_prof_play_tone_with_id fail");
	}
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_007_deactive_mode
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_007_deactive_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 6;
	vs_service_profile_prompt_screen_enter();
	ret = srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
	if(SRV_PROF_RET_FAIL == ret || SRV_PROF_RET_PROFILE_NOT_SUPPORTED == ret )
	{
		kal_prompt_trace(MOD_IDLE, "srv_prof_activate_profile_by_external_module fail error %d",ret);
		return;
	}

	ret = srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
	
	AVK_LOG_FUN(srv_prof_deactivate_profile_by_external_module,AVK_PASS);
	if(SRV_PROF_RET_FAIL == ret || SRV_PROF_RET_PROFILE_NOT_SUPPORTED == ret )
	{
		kal_prompt_trace(MOD_IDLE, "srv_prof_deactivate_profile_by_external_module fail error %d",ret);
		return;
	}

	ret = srv_prof_play_tone_with_id(INCOMING_CALL_TONE, 
		SRV_PROF_AUD_RING1, 
		SRV_PROF_RING_TYPE_REPEAT, 
		NULL);

	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "srv_prof_play_tone_with_id fail");
	}
}


/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_008_get_file_path_by_audio_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_008_get_file_path_by_audio_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret = SRV_PROF_RET_FAIL;
	mdi_result mdi_ret = MDI_AUDIO_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 7;
	vs_service_profile_prompt_screen_enter();
	//ret = srv_prof_get_file_path_by_audio_id(path_buf,AUD_ID_PROF_EXT1); 
	if(SRV_PROF_RET_FAIL == ret)
	{
		kal_prompt_trace(MOD_IDLE, "srv_prof_get_file_path_by_audio_id fail");
	}

	//mdi_ret = mdi_audio_play_file(path_buf, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL,NULL);
	if(MDI_AUDIO_SUCCESS != mdi_ret)
	{
		kal_prompt_trace(MOD_IDLE,"mdi_audio_play_file ret %d",mdi_ret);
	}
}

/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_009_get_num_of_profiles
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_009_get_num_of_profiles()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_vs_service_profile_context.m_nCurCaseIdx = 8;
	g_vs_service_profile_context.m_nProfileCount = srv_prof_get_num_of_profiles();
	
	AVK_LOG_FUN(srv_prof_get_num_of_profiles,AVK_PASS);

	vs_service_profile_prompt_screen_enter();
}


/*****************************************************************************
 * FUNCTION
 *  vs_service_profile_010_get_ring_vol
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void vs_service_profile_010_get_ring_vol()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_vs_service_profile_context.m_nCurCaseIdx = 9;
	g_vs_service_profile_context.m_nRingLevel = srv_prof_get_ring_vol();
	
	AVK_LOG_FUN(srv_prof_get_ring_vol,AVK_PASS);

	vs_service_profile_prompt_screen_enter();

	if(srv_prof_if_can_ring())
	{
		ret = srv_prof_play_tone_with_id(INCOMING_CALL_TONE, 
		SRV_PROF_AUD_RING3, 
		SRV_PROF_RING_TYPE_REPEAT, 
		NULL);

		if(SRV_PROF_RET_FAIL == ret)
		{
			kal_prompt_trace(MOD_IDLE, "srv_prof_play_tone_with_id fail ret = %d",ret);
		}	
	}
	
	AVK_LOG_FUN(srv_prof_if_can_ring,AVK_PASS);
}



AVK_TEST_ALL(AVK_MM_PROFILE)


AVK_ADD_ITEM(AVK_PROFILE_ITEM_001,L"Profile 001",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_002,L"Profile 002",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_003,L"Profile 003",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_004,L"Profile 004",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_005,L"Profile 005",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_006,L"Profile 006",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_007,L"Profile 007",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_008,L"Profile 008",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_009,L"Profile 009",AVK_MM_PROFILE);
AVK_ADD_ITEM(AVK_PROFILE_ITEM_010,L"Profile 010",AVK_MM_PROFILE);



AVK_MANUAL_CASE(AVK_PROFILE_MANUAL1,AVK_PROFILE_ITEM_001)
{
	vs_service_profile_001_play_tone();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL2,AVK_PROFILE_ITEM_002)
{ 
	vs_service_profile_002_play_tone_with_filepath();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL3,AVK_PROFILE_ITEM_003)
{
	vs_service_profile_003_play_tone_with_full_struct();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL4,AVK_PROFILE_ITEM_004)
{  
	vs_service_profile_004_play_tone_with_id();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL5,AVK_PROFILE_ITEM_005)
{
	vs_service_profile_005_play_tone_with_text();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL6,AVK_PROFILE_ITEM_006)
{
	vs_service_profile_006_active_mode();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL7,AVK_PROFILE_ITEM_007)
{
	vs_service_profile_007_deactive_mode();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL8,AVK_PROFILE_ITEM_008)
{   
	vs_service_profile_008_get_file_path_by_audio_id();
}

AVK_MANUAL_CASE(AVK_PROFILE_MANUAL9,AVK_PROFILE_ITEM_009)
{    
	vs_service_profile_009_get_num_of_profiles();
}
AVK_MANUAL_CASE(AVK_PROFILE_MANUAL10,AVK_PROFILE_ITEM_010)
{    
	vs_service_profile_010_get_ring_vol();

}












#endif
