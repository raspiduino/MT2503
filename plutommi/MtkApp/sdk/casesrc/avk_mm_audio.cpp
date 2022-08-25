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
*   tst_appser_mm_audio.c
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
#include "BTMMIScrGprots.h"
#include "BtcmSrvGprot.h"
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "FileMgrGProt.h"
#include "SettingProfile.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"
#include "mdi_bitstream.h"
#include "avk_mm_audio.h"
#include "nvram_default_audio.h"
#include "Med_api.h"
}


vs_mm_audio_context_struct g_vs_mm_audio_cntx;

__align(2)
const U8 g_vs_dummy_bg[] = 
{
    0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06,
    0x00, 0x00, 0x00, 0x01, 0x01, 0xE0, 0x4D, 0x54,
    0x72, 0x6B, 0x00, 0x00, 0x00, 0x69, 0x00, 0xFF,
    0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C,
    0x65, 0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F,
    0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20,
    0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62,
    0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03,
    0x43, 0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04,
    0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00,
    0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0,
    0x00, 0xC0, 0x0C, 0x00, 0xB0, 0x07, 0x64, 0x00,
    0xB9, 0x07, 0x50, 0x00, 0x99, 0x26, 0x5A, 0x3C,
    0x27, 0x7D, 0x14, 0x90, 0x5D, 0x27, 0x81, 0x5C,
    0x99, 0x27, 0x00, 0x81, 0x34, 0x26, 0x00, 0x50,
    0x90, 0x5D, 0x00, 0x00, 0xFF, 0x2F, 0x00,
};



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_play_id
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_play_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 0;

    vs_mm_audio_misc_play_id_screen_enter();

    mdi_audio_set_volume(VOL_TYPE_MEDIA,5);

    AVK_LOG_FUN(mdi_audio_set_volume,AVK_PASS);

    result = mdi_audio_play_id(49, DEVICE_AUDIO_PLAY_CRESCENDO);
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_id,   return :%d", result);

    AVK_LOG_FUN(mdi_audio_play_id,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        return;
    }  

    if (srv_earphone_is_plug_in())
    {
        mdi_audio_set_audio_mode(MDI_AUD_MODE_HEADSET);

    }
    else
    {
        mdi_audio_set_audio_mode(MDI_AUD_MODE_NORMAL);
    } 

    AVK_LOG_FUN(mdi_audio_set_audio_mode,AVK_PASS);

    AVK_LOG_FUN(mdi_audio_is_file_pausable,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_pause,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_resume,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_stop_id,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_set_headset_mode_output_path,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_idle,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_playing,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_get_state,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_recording,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_get_progress_time,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_set_progress_time,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_pure_audio,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_aac_file_seekable,AVK_PASS);	
    kal_prompt_trace(MOD_MMS, "audio case 1 end");

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_pause
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    MMI_BOOL is_plausible;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_plausible = mdi_audio_is_file_pausable((void*)g_vs_mm_audio_cntx.filename);
    if (!is_plausible)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_pause, error cause : File not plausibe");
        return;
    }

    result = mdi_audio_pause(vs_mm_audio_misc_pause_callback, NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_pause, error code :%d;\n", result);
    }
    else
    {
        gui_set_text_border_color(gui_color(255, 255, 255));
        gdi_draw_solid_rect(5, 70, 240, 98, GDI_COLOR_WHITE);
        vs_mm_audio_001_idle_or_play();
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gdi_layer_blt_previous(5, 70, 240, 98);

        if (g_vs_mm_audio_cntx.num == 5)
        {
            gui_cancel_timer(vs_mm_audio_misc_progress_time_cnt);
        }

        SetKeyHandler(vs_mm_audio_001_resume, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_resume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_resume(vs_mm_audio_misc_resume_callback, NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_resume, error code :%d;\n", result);
    }
    else
    {
        gui_set_text_border_color(gui_color(255, 255, 255));
        gdi_draw_solid_rect(5, 70, 240, 98, GDI_COLOR_WHITE);
        vs_mm_audio_001_idle_or_play();
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gdi_layer_blt_previous(5, 70, 240, 98);
        if (g_vs_mm_audio_cntx.num == 5)
        {
            gui_start_timer(1000, vs_mm_audio_misc_progress_time_cnt);
        }

        SetKeyHandler(vs_mm_audio_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.stop = 1;

    switch (g_vs_mm_audio_cntx.num)
    {
    case 0:
        {
            mdi_audio_stop_id(49);
            mdi_audio_stop_all();
            break;
        }
    case 1:
        {
            mdi_audio_stop_string();
            mdi_audio_stop_all();
            break;
        }
    case 2:
    case 3:
    case 4:
        {
            mdi_audio_stop_all();
            break;
        }
    case 5:
        {
            gui_cancel_timer(vs_mm_audio_misc_progress_time_cnt);
            mdi_audio_stop_file();
            mdi_audio_stop_all();
            break;
        }
    case 6:
    case 7:
        {
            mdi_audio_stop_all();
            break;
        }
    case 12:
    case 25:	
        {
            mdi_audio_stop_file();
            mdi_audio_stop_all();
            break;
        }
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_set_volume_add
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_set_volume_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_audio_misc_set_volume_add(VOL_TYPE_MEDIA);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_set_volume_sub
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_set_volume_sub(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_audio_misc_set_volume_sub(VOL_TYPE_MEDIA);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_set_headset_mode_output_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_set_headset_mode_output_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
    mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_3);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 100);
    gdi_draw_solid_rect(5, 100, 240, 128, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) L"path: both");
    gdi_layer_blt_previous(5, 100, 240, 128);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_idle_or_play
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_idle_or_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.state_buf, 0, VS_MM_BUFFER_SIZE);

    if (mdi_audio_is_idle())
    {
        mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: idle");
    }
    else if (mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE))
    {
        mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: play file");
    }
    else if (mdi_audio_is_playing(MDI_AUDIO_PLAY_ID))
    {
        mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: play id");
    }
    else if (mdi_audio_is_playing(MDI_AUDIO_PLAY_STRING))
    {
        mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: play string");
    }
    else
    {
        if (mdi_audio_get_state() == MDI_AUDIO_PLAY_PAUSED)
        {
            mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: play pause");
        }
        else if (mdi_audio_get_state() == MDI_AUDIO_PLAY)
        {
            mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: play");
        }
        else if (mdi_audio_get_state() == MDI_AUDIO_SPEECH_ON)
        {
            mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: speech");
        }
        else if (mdi_audio_is_recording())
        {
            mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: record");
        }

        else
        {
            mmi_wcscpy((U16*) g_vs_mm_audio_cntx.state_buf, (U16*) L"state: no state");
        }

    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_get_progress_time
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_get_progress_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR disp_temp_buf[VS_MM_BUFFER_SIZE];
    mdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_audio_get_progress_time(&g_vs_mm_audio_cntx.cur_offset);
    memset(g_vs_mm_audio_cntx.progress_buf, 0, VS_MM_BUFFER_SIZE);
    memset(disp_temp_buf, 0, VS_MM_BUFFER_SIZE);

    if (ret == MDI_AUDIO_SUCCESS)
    {
        sprintf(disp_temp_buf, "progress: %d", g_vs_mm_audio_cntx.cur_offset);
        mmi_asc_to_wcs((U16*) g_vs_mm_audio_cntx.progress_buf, disp_temp_buf);
    }
    else
    {
        mmi_asc_to_wcs((U16*) g_vs_mm_audio_cntx.progress_buf, (CHAR*) "progress: error");
    }

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_set_progress_time
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_set_progress_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_set_progress_time((U32) g_vs_mm_audio_cntx.cur_offset);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_set_progress_time, error code :%d;\n", result);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_is_pure_audio
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_001_is_pure_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_is_pure_audio((void*)g_vs_mm_audio_cntx.filename))
    {
        //it's pure aduio
    }
    else
    {
        //it's not pure aduio
    }
}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_001_is_aac_file_seekable
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL vs_mm_audio_001_is_aac_file_seekable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_seekable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(AAC_DECODE)
    if (!(mdi_audio_is_aac_file_seekable((void*)g_vs_mm_audio_cntx.filename)))
    {
        is_seekable = MMI_FALSE;
    }
#endif
    return is_seekable;


}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_002_play_string
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_002_play_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 1;

    vs_mm_audio_misc_set_string_buffer((vs_mm_audio_string_type_enum)g_vs_mm_audio_cntx.sub_type);
    vs_mm_audio_misc_draw_string_type();

    mdi_audio_set_volume(VOL_TYPE_MEDIA,5);

    result = mdi_audio_play_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        vs_mm_audio_misc_play_callback,
        NULL);

    kal_prompt_trace(MOD_MMS, "mdi_audio_play_string,  return %d", result);

    AVK_LOG_FUN(mdi_audio_play_string,AVK_PASS);


    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    result = mdi_audio_get_duration_by_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        (U32*) & g_vs_mm_audio_cntx.total_time);

    AVK_LOG_FUN(mdi_audio_get_duration_by_string,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration_by_string, error code :%d;\n", result);
    }
    vs_mm_audio_misc_play_string_screen_enter();


}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_003_play_string_vol_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_003_play_string_vol_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 2;


    vs_mm_audio_misc_set_string_buffer(VS_MM_AUDIO_FORMAT_SMF);

    result = mdi_audio_play_string_with_vol_path(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_string_with_vol_path return %d", result);

    AVK_LOG_FUN(mdi_audio_play_string_with_vol_path,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    result = mdi_audio_get_duration_by_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        (U32*) & g_vs_mm_audio_cntx.total_time);

    AVK_LOG_FUN(mdi_audio_get_duration_by_string,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration_by_string, error code :%d;\n", result);
    }

    vs_mm_audio_misc_play_string_screen_enter();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_004_play_string_portion_vol_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_004_play_string_portion_vol_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 3;

    vs_mm_audio_misc_set_string_buffer(VS_MM_AUDIO_FORMAT_SMF);

    result = mdi_audio_play_string_portion_with_vol_path(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        500,
        3000,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    AVK_LOG_FUN(mdi_audio_play_string_portion_with_vol_path,AVK_PASS);
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_string_portion_with_vol_path return %d", result);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    result = mdi_audio_get_duration_by_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        (U32*) & g_vs_mm_audio_cntx.total_time);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration_by_string, error code :%d;\n", result);
    }

    vs_mm_audio_misc_play_string_screen_enter();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_005_play_string_vol_path_non_block
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_005_play_string_vol_path_non_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 4;

    vs_mm_audio_misc_set_string_buffer(VS_MM_AUDIO_FORMAT_SMF);

    result = mdi_audio_play_string_with_vol_path_non_block(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_string_with_vol_path_non_block return %d", result);


    AVK_LOG_FUN(mdi_audio_play_string_with_vol_path_non_block,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    result = mdi_audio_get_duration_by_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        (U32*) & g_vs_mm_audio_cntx.total_time);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration_by_string, error code :%d;\n", result);
    }

    vs_mm_audio_misc_play_string_screen_enter();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_006_play_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_006_play_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 5;
    vs_mm_audio_misc_play_file_screen_enter();

    vs_mm_audio_misc_draw_file_type();

    mdi_audio_set_volume(VOL_TYPE_MEDIA,5);


    if (mdi_audio_is_resource_available(MDI_AUDIO_PLAY_FILE,NULL))
    {
        result = mdi_audio_play_file(
            (void*) g_vs_mm_audio_cntx.filename,
            DEVICE_AUDIO_PLAY_CRESCENDO,
            NULL,
            vs_mm_audio_misc_play_callback,
            NULL);
    }
    else
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_is_resource_available  =  FALSE \n");
        ASSERT(0);

    }


    AVK_LOG_FUN(mdi_audio_is_resource_available,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_play_file,AVK_PASS);
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_file return %d", result);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    gui_start_timer(1000, vs_mm_audio_misc_progress_time_cnt);

    result = mdi_audio_get_duration((void*)g_vs_mm_audio_cntx.filename, (U32*) & g_vs_mm_audio_cntx.total_time);
    AVK_LOG_FUN(mdi_audio_get_duration,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration, error code :%d;\n", result);

    }



    AVK_LOG_FUN(mdi_audio_get_midi_size_limit,AVK_PASS);

    AVK_LOG_FUN(mdi_audio_set_vibrator_enabled,AVK_PASS);

    AVK_LOG_FUN(mdi_audio_get_size_limit,AVK_PASS);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_006_get_midi_file_limit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_006_get_midi_file_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.midi_size_ptr, 0, VS_MM_BUFFER_SIZE);
    memset(str_buf, 0, VS_MM_BUFFER_SIZE);

    sprintf(str_buf, (CHAR*) "size limit: %d", mdi_audio_get_midi_size_limit());


    mmi_asc_to_wcs((U16*) g_vs_mm_audio_cntx.midi_size_ptr, str_buf);
}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_006_get_size_limit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_006_get_size_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.midi_size_ptr, 0, VS_MM_BUFFER_SIZE);
    memset(str_buf, 0, VS_MM_BUFFER_SIZE);

    sprintf(str_buf, (CHAR*) "Imelody size limit: %d", mdi_audio_get_size_limit(MDI_FORMAT_IMELODY));

    mmi_asc_to_wcs((U16*) g_vs_mm_audio_cntx.midi_size_ptr, str_buf);
}



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_006_vibrator_disable
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_006_vibrator_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_text_cursor(5, 160);
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 160, 240, 188, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) L"vibrator: disable");
    gdi_layer_blt_previous(5, 160, 240, 188);

    result = mdi_audio_set_vibrator_enabled((kal_bool)FALSE);


    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_set_vibrator_enabled, error code :%d;\n", result);
        return;
    }

    SetKeyHandler(vs_mm_audio_006_vibrator_enable, KEY_UP_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_006_vibrator_enable
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_006_vibrator_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_text_cursor(5, 160);
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 160, 240, 188, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) L"vibrator: enable");
    gdi_layer_blt_previous(5, 160, 240, 188);

    result = mdi_audio_set_vibrator_enabled((kal_bool)TRUE);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_set_vibrator_enabled, error code :%d;\n", result);
        return;
    }

    SetKeyHandler(vs_mm_audio_006_vibrator_disable, KEY_UP_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_007_play_file_vol_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_007_play_file_vol_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 6;
    vs_mm_audio_misc_play_file_screen_enter();

    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");

    result = mdi_audio_play_file_with_vol_path(
        (void*) g_vs_mm_audio_cntx.filename,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    kal_prompt_trace(MOD_MMS, "mdi_audio_play_file_with_vol_path return %d", result);


    AVK_LOG_FUN(mdi_audio_play_file_with_vol_path,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    result = mdi_audio_get_duration((void*)g_vs_mm_audio_cntx.filename, (U32*) & g_vs_mm_audio_cntx.total_time);
    AVK_LOG_FUN(mdi_audio_get_duration,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration, error code :%d;\n", result);
    }

    AVK_LOG_FUN(mdi_audio_get_audio_mode,AVK_PASS);

}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_008_play_file_portion_vol_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_008_play_file_portion_vol_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 7;

    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");
	
	result = mdi_audio_get_duration((void*) g_vs_mm_audio_cntx.filename, (U32*) & g_vs_mm_audio_cntx.total_time);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration, error code :%d;\n", result);
        return;
    }

    result = mdi_audio_play_file_portion_with_vol_path(
        (void*) g_vs_mm_audio_cntx.filename,
        1000,
        9000,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    kal_prompt_trace(MOD_MMS, "mdi_audio_play_file_portion_with_vol_path return %d", result);


    AVK_LOG_FUN(mdi_audio_play_file_portion_with_vol_path,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    vs_mm_audio_misc_play_file_screen_enter();
}

void vs_mm_audio_009_get_record_time_timer_callback(void)
{
    mdi_audio_get_record_time();

    AVK_LOG_FUN(mdi_audio_get_record_time,AVK_PASS);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_009_record_start
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_009_record_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 8;

    vs_mm_audio_misc_record_file_setting_save();
    mdi_audio_terminate_background_play();

    AVK_LOG_FUN(mdi_audio_terminate_background_play,AVK_PASS);
    FS_Delete((PU16) g_vs_mm_audio_cntx.record_file_name);

    if (g_vs_mm_audio_cntx.sub_type == 1)
    {
        result = mdi_audio_start_record_with_limit(
            (void*) g_vs_mm_audio_cntx.record_file_name,
            MDI_FORMAT_AMR,
            0,      /* 0: Low, >0: High */
            vs_mm_audio_misc_record_callback,
            NULL,
            51200,  /* Max record size in byte. 0: unlimited */
            10);    /* Max record time in sec.  0: unlimited */
    }
    else
    {
        result = mdi_audio_start_record_with_limit(
            (void*) g_vs_mm_audio_cntx.record_file_name,
            MDI_FORMAT_WAV,
            0,      /* 0: Low, >0: High */
            vs_mm_audio_misc_record_callback,
            NULL,
            204800, /* Max record size in byte. 0: unlimited */
            10);    /* Max record time in sec.  0: unlimited */
    }

    AVK_LOG_FUN(mdi_audio_start_record_with_limit,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_start_record_with_limit, error code :%d;\n", result);
        return;
    }
    else
    {
        gui_start_timer(1000, vs_mm_audio_009_get_record_time_timer_callback);
    }

    vs_mm_audio_misc_record_screen_enter();

    AVK_LOG_FUN(mdi_audio_stop_record,AVK_PASS);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_009_record_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_009_record_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_stop_record();

    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_play_file((void*) g_vs_mm_audio_cntx.record_file_name, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL, NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_010_bg_play_operate
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_010_bg_play_operate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR disp_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.suspended == 0)
    {
        g_vs_mm_audio_cntx.suspended = 1;
        mdi_audio_get_progress_time(&g_vs_mm_audio_cntx.play_time);
        mdi_audio_suspend_background_play();
    }
    else
    {
        g_vs_mm_audio_cntx.suspended = 0;
        mdi_audio_resume_background_play();
    }

    memset(disp_buf, 0, VS_MM_BUFFER_SIZE);

    if (mdi_audio_is_background_play_suspended())
    {
        mmi_asc_to_wcs((WCHAR*) disp_buf, (CHAR*) "bg is suspended");
    }
    else
    {
        mmi_asc_to_wcs((WCHAR*) disp_buf, (CHAR*) "bg is not suspended");
    }
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 200, 98, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) disp_buf);
    gdi_layer_blt_previous(5, 70, 200, 98);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_011_snd_play_string
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_011_snd_play_string(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 10;

    audio_data = vs_mm_audio_misc_get_audio_data(AUD_ID_VS_MM_SND_PLAY, &audio_type, &audio_len);

    if (audio_data == NULL)
    {
        ASSERT(0);
    }

    result = mdi_audio_snd_check_string_format(audio_data, audio_len);

    AVK_LOG_FUN(mdi_audio_snd_check_string_format,AVK_PASS);
    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_check_string_format, error code :%d;\n", result);
        ASSERT(0);
        return;
    }

    result = mdi_audio_snd_play_string_with_vol_path(
        audio_data,
        audio_len,
        0,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_DEVICE_SPEAKER2);

    AVK_LOG_FUN(mdi_audio_snd_play_string_with_vol_path,AVK_PASS);
    kal_prompt_trace(MOD_MMS, "mdi_audio_snd_play_string_with_vol_path,  code :%d", result);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
    }

    vs_mm_audio_misc_snd_screen_enter();
#else /* defined(BGSND_ENABLE) */ 
    kal_prompt_trace(MOD_MMS, "audio case 11 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_snd_play_string_with_vol_path);
    AVK_ASYN_DONE();
#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_012_snd_stop_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_012_snd_stop_hdlr(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.stop = 1;

    result = mdi_audio_snd_stop();

    AVK_LOG_FUN(mdi_audio_snd_stop,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_stop, error code :%d;\n", result);
    }

#else /* defined(BGSND_ENABLE) */ 
#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_012_snd_set_volume_add
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_012_snd_set_volume_add(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.audio_level >= 6)
    {
        return;
    }
    else
    {
        g_vs_mm_audio_cntx.audio_level++;
    }

    result = mdi_audio_snd_set_volume(g_vs_mm_audio_cntx.audio_level);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_set_volume, error code :%d;\n", result);
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 130);
    gdi_draw_solid_rect(5, 130, 200, 158, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "volume level: %d", g_vs_mm_audio_cntx.audio_level + 1);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 130, 200, 158);
#else /* defined(BGSND_ENABLE) */ 
#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_012_snd_set_volume_sub
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_012_snd_set_volume_sub(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.audio_level == MDI_AUD_VOL_1)
    {
        return;
    }
    else
    {
        g_vs_mm_audio_cntx.audio_level--;
    }

    result = mdi_audio_snd_set_volume(g_vs_mm_audio_cntx.audio_level);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_set_volume, error code :%d;\n", result);
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 130);
    gdi_draw_solid_rect(5, 130, 200, 158, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "volume level: %d", g_vs_mm_audio_cntx.audio_level + 1);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 130, 200, 158);
#else /* defined(BGSND_ENABLE) */ 
#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_012_snd_is_idle
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_012_snd_is_idle(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_snd_is_idle())
    {
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"state: idle");
    }
    else
    {
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"state: play");
    }
#else /* defined(BGSND_ENABLE) */ 
#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_012_snd_play_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_012_snd_play_file(void)
{
#if defined(BGSND_ENABLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 11;

    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"snd.wav");

    result = mdi_audio_snd_check_file_format((void*) g_vs_mm_audio_cntx.file_buf);

    AVK_LOG_FUN(mdi_audio_snd_check_file_format,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_check_file_format, error code :%d;\n", result);
        ASSERT(0);
        return;
    }

    result = mdi_audio_snd_play_file_with_vol_path(
        (void*) g_vs_mm_audio_cntx.file_buf,
        0,
        vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    AVK_LOG_FUN(mdi_audio_snd_play_file_with_vol_path,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_snd_play_file_with_vol_path, error code :%d;\n", result);
        ASSERT(0);

        return;
    }

    vs_mm_audio_misc_snd_screen_enter();

    AVK_LOG_FUN(mdi_audio_snd_set_volume,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_snd_is_idle,AVK_PASS);
#else /* defined(BGSND_ENABLE) */ 
    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_snd_play_file_with_vol_path);
    kal_prompt_trace(MOD_MMS, "audio case 12 not support");


    AVK_ASYN_DONE();

#endif /* defined(BGSND_ENABLE) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_013_build_cache_fail_callback
* DESCRIPTION
*  
* PARAMETERS
*  inMsg       [?]  
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_013_build_cache_fail_callback(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_013_build_cache
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_013_build_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    CHAR str_buf_temp[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 12;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_PLAY, vs_mm_audio_misc_play_screen_exit, NULL, MMI_FRM_FULL_SCRN);

    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.amr");

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    if (mdi_audio_is_duration_need_build_cache((void*) g_vs_mm_audio_cntx.filename))
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_is_duration_need_build_cache true");

        memset(g_vs_mm_audio_cntx.audio_cache, 0, VS_MM_AUDIO_BUILD_CACHE_SIZE);

        g_vs_mm_audio_cntx.audio_cache_file_buf_p = (U8*) mmi_frm_scrmem_alloc(VS_MM_AUDIO_BUILD_CACHE_FILE_BUF_SIZE);

        if (g_vs_mm_audio_cntx.audio_cache_file_buf_p == NULL)
        {
            ASSERT(0);
            kal_prompt_trace(MOD_MMS, "mmi_frm_scrmem_alloc error;\n");
            return;
        }

        g_vs_mm_audio_cntx.audio_cache_proc_buf_p = (U8*) mmi_frm_scrmem_alloc(VS_MM_AUDIO_BUILD_CACHE_PROC_BUF_SIZE);

        if (g_vs_mm_audio_cntx.audio_cache_proc_buf_p == NULL)
        {
            kal_prompt_trace(MOD_MMS, "mmi_frm_scrmem_alloc error;\n");
            return;
        }

        mdi_audio_reset_build_cache_variables();

        mdi_audio_start_build_cache(
            (kal_wchar*) g_vs_mm_audio_cntx.filename,
            g_vs_mm_audio_cntx.audio_cache,
            VS_MM_AUDIO_BUILD_CACHE_SIZE,
            g_vs_mm_audio_cntx.audio_cache_file_buf_p,
            VS_MM_AUDIO_BUILD_CACHE_FILE_BUF_SIZE,
            g_vs_mm_audio_cntx.audio_cache_proc_buf_p,
            VS_MM_AUDIO_BUILD_CACHE_PROC_BUF_SIZE,
            vs_mm_audio_013_build_cache_fail_callback,
            &g_vs_mm_audio_cntx.audio_build_cache_progress);

        if (!mdi_audio_build_cache_get_cache_duration(&g_vs_mm_audio_cntx.cache_duration))
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_build_cache_get_cache_duration 0");
        }
        else
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_build_cache_get_cache_duration 1");

            memset(str_buf_temp, 0, VS_MM_BUFFER_SIZE);
            memset(g_vs_mm_audio_cntx.cache_duration_buf, 0, VS_MM_BUFFER_SIZE);
            sprintf((CHAR*) str_buf_temp, (CHAR*)"curr: %d sec.", g_vs_mm_audio_cntx.cache_duration / 1000);
            mmi_asc_to_wcs((WCHAR*) g_vs_mm_audio_cntx.cache_duration_buf, str_buf_temp);
        }

        if (!mdi_audio_build_cache_get_total_duration(&g_vs_mm_audio_cntx.total_duration))
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_build_cache_get_total_duration 2");

        }
        else
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_build_cache_get_total_duration 3");

            memset(str_buf_temp, 0, VS_MM_BUFFER_SIZE);
            memset(g_vs_mm_audio_cntx.total_duration_buf, 0, VS_MM_BUFFER_SIZE);
            sprintf((CHAR*) str_buf_temp, (CHAR*)"total: %d sec.", g_vs_mm_audio_cntx.total_duration / 1000);
            mmi_asc_to_wcs((WCHAR*) g_vs_mm_audio_cntx.total_duration_buf, str_buf_temp);
        }


        mdi_audio_regisiter_auto_update_duration_handler(vs_mm_audio_misc_cache_update_duration);

        result = mdi_audio_play_file(
            (void*) g_vs_mm_audio_cntx.filename,
            DEVICE_AUDIO_PLAY_CRESCENDO,
            g_vs_mm_audio_cntx.audio_cache,
            vs_mm_audio_misc_play_callback,
            NULL);

        if (result != MDI_AUDIO_SUCCESS)
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
            ASSERT(0);
        }
        g_vs_mm_audio_cntx.play_time = 0;

        SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
        SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
        SetKeyHandler(vs_mm_audio_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
    else
    {
            kal_prompt_trace(MOD_MMS, "no need to build cache");
    }

    AVK_LOG_FUN(mdi_audio_is_duration_need_build_cache,AVK_PASS);

    AVK_LOG_FUN(mdi_audio_reset_build_cache_variables,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_start_build_cache,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_build_cache_get_cache_duration,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_build_cache_get_total_duration,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_regisiter_auto_update_duration_handler,AVK_PASS);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_014_tts_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_014_tts_stop(void)
{
#ifdef __GENERAL_TTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_tts_stop();

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_tts_stop, error code :%d;\n", result);
    }
#else
#endif /* __GENERAL_TTS__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_014_tts_pause
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_014_tts_pause(void)
{
#ifdef __GENERAL_TTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_tts_pause();

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_tts_pause, error code :%d;\n", result);
    }

    SetKeyHandler(vs_mm_audio_014_tts_resume, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
#endif /* __GENERAL_TTS__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_014_tts_resume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_014_tts_resume(void)
{
#ifdef __GENERAL_TTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_tts_resume();

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_tts_resume, error code :%d;\n", result);
    }

    SetKeyHandler(vs_mm_audio_014_tts_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
#endif /* __GENERAL_TTS__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_014_tts
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_014_tts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GENERAL_TTS__
    mdi_audio_tts_struct tts_play;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 13;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_TTS, NULL, vs_mm_audio_014_tts, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    tts_play.text_string = (U16*) GetString(STR_ID_VS_MM_AUDIO_TTS);
    tts_play.str_type = MDI_TTS_STR_TEXT;
    tts_play.lang = MDI_TTS_LANG_TWN;
    tts_play.app_type = MDI_TTS_TYPE_GENERAL;
    tts_play.gander = MDI_TTS_GENDER_MALE;
    tts_play.volume = 5;
    tts_play.path = MDI_DEVICE_SPEAKER2;
    tts_play.pitch = 50;
    tts_play.speed = 25;
    tts_play.callback = NULL;

    mdi_audio_tts_set_attr(MDI_TTS_ATTR_INPUT_CODEPAGE, MDI_TTS_VALUE_CODEPAGE_UTF16LE);

    result = mdi_audio_tts_play(tts_play);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_tts_play, error code :%d;\n", result);
    }

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_014_tts_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);


    AVK_LOG_FUN(mdi_audio_tts_set_attr,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_tts_play,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_tts_stop,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_tts_resume,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_tts_pause,AVK_PASS);

#else
    kal_prompt_trace(MOD_MMS, "audio case 14 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_tts_play);

    AVK_ASYN_DONE();

#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_015_eq_turn_off
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_015_eq_turn_off(void)
{
#if defined(__BES_EQ_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_eq_turn_off();

    AVK_LOG_FUN(mdi_audio_eq_turn_off,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_eq_turn_off, error code :%d;\n", result);
    }

    g_vs_mm_audio_cntx.stop = 1;
    mdi_audio_stop_file();
#else
#endif /* defined(__BES_EQ_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_015_eq_set_magnitude
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_015_eq_set_magnitude(void)
{
#if defined(__BES_EQ_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.magnitude_index++;

    result = mdi_audio_eq_set_magnitude((S8*) NVRAM_EF_AUDIO_EQUALIZER_DEFAULT->
        magnitude[g_vs_mm_audio_cntx.magnitude_index]);

    AVK_LOG_FUN(mdi_audio_eq_set_magnitude,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_eq_set_magnitude, error code :%d;\n", result);
    }

    mdi_audio_eq_turn_on();

    AVK_LOG_FUN(mdi_audio_eq_turn_on,AVK_PASS);

    if (g_vs_mm_audio_cntx.magnitude_index >= 7)
    {
        g_vs_mm_audio_cntx.magnitude_index = 0;
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 200, 98, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "magnitude index: %d", g_vs_mm_audio_cntx.magnitude_index);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 70, 200, 98);
#else
#endif /* defined(__BES_EQ_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_016_reverb_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_016_reverb_stop(void)
{
#ifdef __BES_LIVE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_REVERB_EFFECT__

    mdi_audio_reverb_turn_off(); 
#endif
    g_vs_mm_audio_cntx.stop = 1;
    mdi_audio_stop_file();
#else
#endif /* __BES_LIVE_SUPPORT__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_016_reverb_set_coeff
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_016_reverb_set_coeff(void)
{

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_017_surround_turn_off
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_017_surround_turn_off(void)
{
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_surround_turn_off();
    AVK_LOG_FUN(mdi_audio_surround_turn_off,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_surround_turn_off, error code :%d;\n", result);
    }

    g_vs_mm_audio_cntx.stop = 1;
    mdi_audio_stop_file();
#else
#endif /* defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) */ /* __MMI_AUDIO_SURROUND_EFFECT__ */
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_017_surround_turn_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_017_surround_turn_on(void)
{
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.surround_mode == 0)
    {
        g_vs_mm_audio_cntx.surround_mode++;
    }
    else
    {
        g_vs_mm_audio_cntx.surround_mode--;
    }

    result = mdi_audio_surround_turn_on(g_vs_mm_audio_cntx.surround_mode);

    AVK_LOG_FUN(mdi_audio_surround_turn_on,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_surround_turn_on, error code :%d;\n", result);
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 200, 98, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "surround mode: %d", g_vs_mm_audio_cntx.surround_mode);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 70, 200, 98);
#else
#endif /* defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) */ /* __MMI_AUDIO_SURROUND_EFFECT__ */

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_018_spectrum_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_018_spectrum_stop(void)
{
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_stop_calc_spectrum();

    AVK_LOG_FUN(mdi_audio_stop_calc_spectrum,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_stop_calc_spectrum, error code :%d;\n", result);
    }

    gui_cancel_timer(vs_mm_audio_misc_spectrum_time_cnt);
    SetKeyHandler(vs_mm_audio_018_spectrum_start, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ /* defined(__BES_TS_SUPPORT__) */
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_018_spectrum_start
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_018_spectrum_start(void)
{
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_start_calc_spectrum();

    AVK_LOG_FUN(mdi_audio_start_calc_spectrum,AVK_PASS);

    result = mdi_audio_get_spectrum(g_vs_mm_audio_cntx.top, g_vs_mm_audio_cntx.amplitude_val);
    AVK_LOG_FUN(mdi_audio_get_spectrum,AVK_PASS);


    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_spectrum, error code :%d;\n", result);
    }

    gui_start_timer(500, vs_mm_audio_misc_spectrum_time_cnt);

    SetKeyHandler(vs_mm_audio_018_spectrum_stop, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ /* defined(__BES_TS_SUPPORT__) */
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_018_spectrum_end
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_018_spectrum_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.stop = 1;
    gui_cancel_timer(vs_mm_audio_misc_spectrum_time_cnt);
    mdi_audio_stop_file();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_019_stretch_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_019_stretch_stop(void)
{
#if defined(__BES_TS_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stretch_close();
    AVK_LOG_FUN(mdi_audio_stretch_close,AVK_PASS);


    g_vs_mm_audio_cntx.stop = 1;

    mdi_audio_stop_all();

#else
#endif /* defined(__BES_TS_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_019_stretch_set_speed
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_019_stretch_set_speed(void)
{
#if defined(__BES_TS_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.speed++;

    if (g_vs_mm_audio_cntx.speed >= 3)
    {
        g_vs_mm_audio_cntx.speed = -2;
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 200, 98, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "curr speed: %d", g_vs_mm_audio_cntx.speed);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 70, 200, 98);

    if (g_vs_mm_audio_cntx.speed == -2)
    {
        result = mdi_audio_stretch_set_speed(MDI_AUDIO_SPEED_SLOW2);
    }
    else if (g_vs_mm_audio_cntx.speed == -1)
    {
        result = mdi_audio_stretch_set_speed(MDI_AUDIO_SPEED_SLOW1);
    }
    else if (g_vs_mm_audio_cntx.speed == 0)
    {
        result = mdi_audio_stretch_set_speed(MDI_AUDIO_SPEED_NORMAL);
    }
    else if (g_vs_mm_audio_cntx.speed == 1)
    {
        result = mdi_audio_stretch_set_speed(MDI_AUDIO_SPEED_FAST1);
    }
    else
    {
        result = mdi_audio_stretch_set_speed(MDI_AUDIO_SPEED_FAST2);
    }

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_stretch_set_speed, error code :%d;\n", result);
    }

    AVK_LOG_FUN(mdi_audio_stretch_set_speed,AVK_PASS);

#else
#endif /* defined(__BES_TS_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_019_stretch_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_019_stretch_file(void)
{
#if defined(__BES_TS_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 18;

    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));
    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_STRETCH, NULL, vs_mm_audio_019_stretch_file, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    result = mdi_audio_play_file(
        (void*) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }

    result = mdi_audio_stretch_check_file_format((void*)g_vs_mm_audio_cntx.file_buf);

    AVK_LOG_FUN(mdi_audio_stretch_check_file_format,AVK_PASS);

    if (result == MDI_AUDIO_UNSUPPORTED_SPEED)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_stretch_check_file_format, error code :%d;\n", result);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }
    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_019_stretch_set_speed, KEY_LEFT_ARROW, KEY_EVENT_UP);
    return;
#else
    kal_prompt_trace(MOD_MMS, "audio case 19 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_stretch_check_file_format);

    AVK_ASYN_DONE();
#endif /* defined(__BES_TS_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_020_stretch_string
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_020_stretch_string(void)
{
#if defined(__BES_TS_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 19;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_STRETCH, NULL, vs_mm_audio_020_stretch_string, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    vs_mm_audio_misc_set_string_buffer(VS_MM_AUDIO_FORMAT_SMF);
    g_vs_mm_audio_cntx.play_time = 0;

    result = mdi_audio_play_string(
        g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        g_vs_mm_audio_cntx.str_type,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_string, error code :%d;\n", result);
        //DeleteScreenIfPresent(SCR_ID_VS_MM_AUDIO_STRETCH);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }

    result = mdi_audio_stretch_check_string_format(
        (void*)g_vs_mm_audio_cntx.audio_buffer,
        g_vs_mm_audio_cntx.buffer_size,
        MDI_FORMAT_SMF);

    AVK_LOG_FUN(mdi_audio_stretch_check_string_format,AVK_PASS);

    if (result == MDI_AUDIO_UNSUPPORTED_SPEED)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_stretch_check_string_format, error code :%d;\n", result);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }
    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_019_stretch_set_speed, KEY_LEFT_ARROW, KEY_EVENT_UP);
    return;
#else
    kal_prompt_trace(MOD_MMS, "audio case 20 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_stretch_check_string_format);

    AVK_ASYN_DONE();

#endif /* defined(__BES_TS_SUPPORT__) */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_021_speech_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_021_speech_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_speech_codec_stop();


    if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_GSM)
    {
        result = mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);

        if (result != MDI_AUDIO_SUCCESS)
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_speech_session_stop, error code :%d;\n", result);
        }
    }

    vs_mm_audio_021_is_speech_mode();

    SetKeyHandler(vs_mm_audio_021_speech_start, KEY_LEFT_ARROW, KEY_EVENT_UP);

    AVK_LOG_FUN(mdi_audio_speech_codec_stop,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_speech_get_app_id,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_speech_session_stop,AVK_PASS);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_021_speech_start
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_021_speech_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_GSM)
    {
        result = mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_GSM);

        if (result != MDI_AUDIO_SUCCESS)
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_speech_session_start, error code :%d;\n", result);
        }
    }
    mdi_audio_speech_codec_start();
    vs_mm_audio_021_is_speech_mode();

    SetKeyHandler(vs_mm_audio_021_speech_stop, KEY_LEFT_ARROW, KEY_EVENT_UP);

    AVK_LOG_FUN(mdi_audio_speech_session_start,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_speech_codec_start,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_is_speech_mode,AVK_PASS);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_021_is_speech_mode
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_021_is_speech_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 220, 98, GDI_COLOR_WHITE);

    if (mdi_audio_is_speech_mode())
    {
        gui_print_bordered_text((UI_string_type) L"speech mode: speech");
    }
    else
    {
        gui_print_bordered_text((UI_string_type) L"speech mode: idle");
    }

    gdi_layer_blt_previous(5, 70, 220, 98);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_power_off
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_power_off();

    AVK_LOG_FUN(mdi_fmr_power_off,AVK_PASS);
}

void vs_mm_audio_022_fmr_power_on_callback (mdi_result result, void* user_data)
{

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_power_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, vs_mm_audio_022_fmr_power_on_callback, NULL);
    mdi_fmr_set_freq(g_vs_mm_audio_cntx.freq);

    mdi_fmr_set_output_path(MDI_DEVICE_SPEAKER_BOTH);

    AVK_LOG_FUN(mdi_fmr_power_on_with_path,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_set_freq,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_get_signal_level,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_check_is_valid_stop,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_set_output_path,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_stop_fmr,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_set_mute,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_evaluate_threshold,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_start_record,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_pause_record,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_resume_record,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_stop_record,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_stop_fmr,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_set_channel,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_rds_enable,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_rds_set_buffer,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_rds_disable,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_rds_reset_buffer,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_rds_poll_rds_event_rds,AVK_PASS);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_stop_fmr();

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_stop_fmr, error code :%d;\n", result);
    }
}










/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_freq_seek_abort
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_freq_seek_abort(void)
{
#ifdef __FM_RADIO_HW_SEARCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_freq_seek_abort();

#endif /* __FM_RADIO_HW_SEARCH__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_set_volume_sub
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_set_volume_sub(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_audio_misc_set_volume_sub((volume_type_enum)MDI_VOLUME_FMR);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_set_volume_add
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_set_volume_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_audio_misc_set_volume_add((volume_type_enum)MDI_VOLUME_FMR);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_freq_seek_callback
* DESCRIPTION
*  
* PARAMETERS
*  stop_freq           [IN]        
*  signal_level        [IN]        
*  is_valid            [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_freq_seek_callback(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
#ifdef __FM_RADIO_HW_SEARCH__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMS,"stop_freq=%d,signal=%d,is_valid=%d",stop_freq,signal_level,is_valid);

#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_freq_seek_start
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_freq_seek_start(void)
{
#ifdef __FM_RADIO_HW_SEARCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_evaluate_threshold();
    mdi_fmr_freq_seek_start(VS_MM_AUDIO_FRM_MIN_FM_FREQUENCY, (kal_bool)1, MMI_TRUE, 100, vs_mm_audio_022_fmr_freq_seek_callback);
#endif
}




/*****************************************************************************
* FUNCTION
*  vs_mm_audio_022_fmr_set_channel
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_022_fmr_set_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 190);
    gdi_draw_solid_rect(5, 190, 200, 218, GDI_COLOR_WHITE);

    if (g_vs_mm_audio_cntx.mono == FALSE)
    {
        g_vs_mm_audio_cntx.mono = TRUE;
        gui_print_text((UI_string_type) L"channel: mono");
    }
    else
    {
        g_vs_mm_audio_cntx.mono = FALSE;
        gui_print_text((UI_string_type) L"channel: stereo");
    }
    gdi_layer_blt_previous(5, 190, 200, 218);

    mdi_fmr_set_channel((kal_bool)g_vs_mm_audio_cntx.mono);

}




/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_exit
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_mma_close(g_vs_mm_audio_cntx.aud_handle);

    AVK_LOG_FUN(mdi_audio_mma_close,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_close, error code :%d;\n", result);
    }

    g_vs_mm_audio_cntx.aud_handle = 0;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_stop
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //result_pdl =  mdi_audio_mma_pdl_write_data_ind(g_vs_mm_audio_cntx.aud_handle, MMI_TRUE);
    result = mdi_audio_mma_stop(g_vs_mm_audio_cntx.aud_handle);

    AVK_LOG_FUN(mdi_audio_mma_stop,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_stop, error code :%d;\n", result);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_play
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_mma_set_start_time(g_vs_mm_audio_cntx.aud_handle, 0);
    result = mdi_audio_mma_play(g_vs_mm_audio_cntx.aud_handle);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_play, error code :%d;\n", result);
    }

    AVK_LOG_FUN(mdi_audio_mma_set_start_time,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_play,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_resume,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_pause,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_stop,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_close,AVK_PASS);


}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_resume
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_mma_resume(g_vs_mm_audio_cntx.aud_handle);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_resume, error code :%d;\n", result);
    }

    SetKeyHandler(vs_mm_audio_023_mma_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_pause
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_mma_pause(g_vs_mm_audio_cntx.aud_handle);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_pause, error code :%d;\n", result);
    }

    SetKeyHandler(vs_mm_audio_023_mma_resume, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma_cb
* DESCRIPTION
*  
* PARAMETERS
*  handle      [IN]        
*  result      [IN]        
*  RETURNS          MDI_RESULT(?)
*****************************************************************************/
void vs_mm_audio_023_mma_cb(kal_int32 handle, kal_int32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.aud_handle != 0)
    {
        mdi_audio_mma_stop(g_vs_mm_audio_cntx.aud_handle);
        mdi_audio_mma_close(g_vs_mm_audio_cntx.aud_handle);
        g_vs_mm_audio_cntx.aud_handle = 0;
    }

    g_vs_mm_audio_cntx.aud_handle = mdi_audio_mma_open_string(0, (void*)g_vs_dummy_bg, VS_MM_AUDIO_SAMPLE_DUMMY_BG, MDI_FORMAT_SMF, 0, NULL, NULL);
    ret = mdi_audio_mma_play(g_vs_mm_audio_cntx.aud_handle);

    if (ret != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_play, error code :%d;\n", ret);
    }
}



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_023_mma
* DESCRIPTION
*  redraw_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_023_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 info[] = {'T','e','s','t','\0'};
    mdi_result result;
    U16 filepath[100];
    mdi_result result_pdl = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 22;
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_MMA, NULL, vs_mm_audio_023_mma, MMI_FRM_FULL_SCRN);
    ShowCategory74Screen(
        STR_ID_VS_MM_AUDIO,
        0,
        STR_ID_VS_MM_PASS,
        0,
        STR_ID_VS_MM_FAIL,
        0,
        (U8*) info,
        mmi_wcslen(info),
        NULL);

    SetLeftSoftkeyFunction(vs_mm_audio_misc_mma_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_mma_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_023_mma_stop, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_023_mma_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);

    memset(g_vs_mm_audio_cntx.audio_cache, 0, VS_MM_AUDIO_BUILD_CACHE_SIZE);

    if (mdi_audio_mma_is_open() == MMI_TRUE)
    {
        mdi_audio_mma_stop(g_vs_mm_audio_cntx.aud_handle);
        mdi_audio_mma_close(g_vs_mm_audio_cntx.aud_handle);
        g_vs_mm_audio_cntx.aud_handle = 0;
    }

    if (mdi_audio_mma_is_idle() == MMI_FALSE)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_is_idle;\n");
        return;
    }

    vs_mm_audio_misc_get_file_path((CHAR*) filepath, (CHAR*) L"audio.wav");

    g_vs_mm_audio_cntx.aud_handle = mdi_audio_mma_open_file(ASM_ANONYMOUS_ID, (void*)filepath, 0, MMI_FALSE, vs_mm_audio_023_mma_cb, NULL);


    if (g_vs_mm_audio_cntx.aud_handle == 0)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_open_file error;\n");
        return;
    }

    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, 4);
    result = mdi_audio_mma_play(g_vs_mm_audio_cntx.aud_handle);
    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_mma_play, error code :%d;\n", result);
        return;
    }




    AVK_LOG_FUN(mdi_audio_mma_is_open,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_is_idle,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_open_file,AVK_PASS);

}





void vs_mm_audio_025_stream_callback(S32 hdl, S32 result)
{
    return;
}


void vs_mm_audio_025_stream_stop()
{
#if defined(__BITSTREAM_API_SUPPORT__)
    gui_cancel_timer(vs_mm_audio_025_stream_put_data);

    if(g_vs_mm_audio_cntx.player_handle!=0)
    {
        mdi_bitstream_audio_stop(g_vs_mm_audio_cntx.player_handle);
        mdi_bitstream_audio_close(g_vs_mm_audio_cntx.player_handle);
		g_vs_mm_audio_cntx.player_handle = 0;
    }
#else
#endif
}


void vs_mm_audio_025_stream_put_data(void)
{
#if defined(__BITSTREAM_API_SUPPORT__)
    S32 ret;
    int file_handler = 0;
    U32 read_counter = 0;
    U32 file_size = 0;
    mdi_bitstream_audio_buffer_status status;
    mdi_bitstream_audio_start_param	  asp;		
    mdi_bitstream_audio_buffer_status tmpstatus;
    S8 stream_read_cache[VS_MM_AUDIO_STREAM_CACHE_SIZE];

    memset(stream_read_cache,0,VS_MM_AUDIO_STREAM_CACHE_SIZE);

    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");

    file_handler = FS_Open((const U16 *)g_vs_mm_audio_cntx.filename, FS_READ_ONLY);

    if( file_handler<0 )
    {
        ASSERT(0);
        vs_mm_audio_025_stream_stop();
        return;
    }

    FS_GetFileSize(file_handler, &file_size);


    if (g_vs_mm_audio_cntx.finish==TRUE)
    {
        FS_Close(file_handler);
        vs_mm_audio_025_stream_stop();
        return;
    }

    FS_Seek(file_handler,g_vs_mm_audio_cntx.offset,FS_FILE_BEGIN);

    ret = mdi_bitstream_audio_get_buffer_status(g_vs_mm_audio_cntx.player_handle,&status);

    if(MDI_RES_BITSTREAM_SUCCEED!=ret)
    {
        vs_mm_audio_025_stream_stop();
        return;
    }

    while( read_counter < status.free_buf_size && FALSE == g_vs_mm_audio_cntx.finish )
    {
        U32 need_read = 0;
        U32 act_read =  0;
        U32 used_data = 0;

        if((status.free_buf_size-read_counter) < VS_MM_AUDIO_STREAM_CACHE_SIZE)
        {
            need_read = status.free_buf_size - read_counter;
        }
        else
        {
            need_read = VS_MM_AUDIO_STREAM_CACHE_SIZE;
        }

        if(g_vs_mm_audio_cntx.offset+need_read>file_size)
        {
            need_read = file_size-need_read-1;
            g_vs_mm_audio_cntx.finish = TRUE;
        }

        FS_Read(file_handler,stream_read_cache,need_read,&act_read);

        g_vs_mm_audio_cntx.offset += act_read;
        read_counter += act_read;

        ret = mdi_bitstream_audio_put_data(g_vs_mm_audio_cntx.player_handle,(U8* )stream_read_cache,act_read,&used_data);

        if(MDI_RES_BITSTREAM_SUCCEED != ret)
        {
            ASSERT(0);
            vs_mm_audio_025_stream_stop();
            return;
        }

    }

    FS_Close(file_handler);

    if(STREAM_STATE_IDLE == g_vs_mm_audio_cntx.status)
    {	
        ret = mdi_bitstream_audio_get_buffer_status(g_vs_mm_audio_cntx.player_handle,&tmpstatus);

        if(MDI_RES_BITSTREAM_SUCCEED!=ret)
        {
            vs_mm_audio_025_stream_stop();
            return;
        }

        if(tmpstatus.free_buf_size == 0)
        {
            asp.start_time = 0;
            asp.audio_path= (U8)MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2);
            asp.volume=(U8)MDI_AUD_VOL_EX(MDI_AUD_VOL_2);

            ret = mdi_bitstream_audio_start(g_vs_mm_audio_cntx.player_handle, &asp);

            if(MDI_RES_BITSTREAM_SUCCEED!=ret)
            {
                ASSERT(0);
                return;
            }
            g_vs_mm_audio_cntx.status = STREAM_STATE_PLAY;
        }
        else
        {
            g_vs_mm_audio_cntx.wait_buffer = TRUE;
        }

    }

    if(g_vs_mm_audio_cntx.wait_buffer)
    {
        g_vs_mm_audio_cntx.wait_buffer = FALSE;
        gui_start_timer(10, vs_mm_audio_025_stream_put_data);
    }
    else
    {
        gui_start_timer(1000, vs_mm_audio_025_stream_put_data);
    }
#else
#endif
}


void vs_mm_audio_025_stream_play(void)
{	
#if defined(__BITSTREAM_API_SUPPORT__)
    MDI_RESULT ret;
    mdi_bitstream_audio_cfg_struct	stream_cfg;
    stream_cfg.codec_type = MDI_BITSTREAM_CODEC_TYPE_DAF;
    g_vs_mm_audio_cntx.status = STREAM_STATE_IDLE;
    g_vs_mm_audio_cntx.wait_buffer = FALSE;
    g_vs_mm_audio_cntx.finish = FALSE;
    g_vs_mm_audio_cntx.offset = 0; 
    g_vs_mm_audio_cntx.num = 24;

    ret = mdi_bitstream_audio_open_handle(&g_vs_mm_audio_cntx.player_handle,&stream_cfg,vs_mm_audio_025_stream_callback);

    if(MDI_RES_BITSTREAM_SUCCEED!=ret)
    {
        vs_mm_audio_025_stream_stop();
        return;
    }

    gui_start_timer(10, vs_mm_audio_025_stream_put_data);

    vs_mm_audio_misc_stream_play_screen_enter();


    AVK_LOG_FUN(mdi_bitstream_audio_open_handle,AVK_PASS);
    AVK_LOG_FUN(mdi_bitstream_audio_start,AVK_PASS);
    AVK_LOG_FUN(mdi_bitstream_audio_put_data,AVK_PASS);
    AVK_LOG_FUN(mdi_bitstream_audio_stop,AVK_PASS);
    AVK_LOG_FUN(mdi_bitstream_audio_close,AVK_PASS);
#else
    kal_prompt_trace(MOD_MMS, "audio case 25 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_bitstream_audio_open_handle);

    AVK_ASYN_DONE();
#endif	
}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_026_bass_turn_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_026_bass_turn_on(void)
{
#if defined(__BES_BASS_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    result = mdi_audio_bass_enhance_turn_on();

    AVK_LOG_FUN(mdi_audio_bass_enhance_turn_on,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_bass_on, error code :%d;\n", result);
    }


#else
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ /* defined(__BES_TS_SUPPORT__) */
}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_026_bass_turn_off
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_026_bass_turn_off(void)
{
#if defined(__BES_BASS_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    result = mdi_audio_bass_enhance_turn_off();

    AVK_LOG_FUN(mdi_audio_bass_enhance_turn_off,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_bass_on, error code :%d;\n", result);
    }

    g_vs_mm_audio_cntx.stop = 1;
    mdi_audio_stop_file();

#else
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ /* defined(__BES_TS_SUPPORT__) */
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_stream_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_stream_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_PASS);
    g_vs_mm_audio_cntx.count = 1;
    vs_mm_audio_025_stream_stop();
    GoBackHistory();
    AVK_ASYN_DONE();

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_stream_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_stream_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.count = 1;
    vs_mm_audio_025_stream_stop();
    GoBackHistory();
    AVK_ASYN_DONE();

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_display_stream_screen
* DESCRIPTION
*  
* PARAMETERS
*  coordinate      [?]     
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_display_stream_screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dis_str[VS_MM_BUFFER_SIZE];
    U8 dis_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);

    gui_print_text((UI_string_type) L"stream file");
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gui_print_bordered_text((UI_string_type) L"volume level: 2");
    gui_move_text_cursor(5, 100);
    gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
}



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_stream_play_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_stream_play_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_STREAM, NULL, vs_mm_audio_misc_stream_play_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(
        0,
        0,
        STR_ID_VS_MM_PASS,
        0,
        STR_ID_VS_MM_FAIL,
        0,
        vs_mm_audio_misc_display_stream_screen,
        NULL);

    SetLeftSoftkeyFunction(vs_mm_audio_misc_play_stream_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_play_stream_fail, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bg_play_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bg_play_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bg_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  
*****************************************************************************/
BOOL vs_mm_audio_misc_bg_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.wav");

//#ifdef __MMI_AUDIO_PLAYER__
//    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
//#endif

    mdi_audio_play_file_portion_with_vol_path(
        (void*) g_vs_mm_audio_cntx.filename,
        g_vs_mm_audio_cntx.play_time,
        0,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_bg_play_callback,
        NULL,
        (U8) MDI_AUD_VOL_EX(g_vs_mm_audio_cntx.audio_level),
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bg_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bg_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
#endif
    mdi_audio_stop_file();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bg_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bg_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 9;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BG_PLAY, NULL, vs_mm_audio_misc_bg_screen_enter, MMI_FRM_FULL_SCRN);
    g_vs_mm_audio_cntx.suspended = 0;
    g_vs_mm_audio_cntx.play_time = 0;

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.wav");

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_010_bg_play_operate, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_set_volume_add
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_set_volume_add(volume_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    U8 volume = g_vs_mm_audio_cntx.audio_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_vs_mm_audio_cntx.audio_level >= 6)
    {
        return;
    }
    else
    {
        g_vs_mm_audio_cntx.audio_level = mdi_audio_incr_volume(volume);
    }

    if (g_vs_mm_audio_cntx.audio_level == MDI_AUD_VOL_1)
    {
        if (type != MDI_VOLUME_FMR)
        {
            mdi_audio_set_mute(VOL_TYPE_MEDIA, (kal_bool)0);
        }
        else
        {
            mdi_fmr_mute(0);
        }
    }

    mdi_audio_set_volume((U8) type, g_vs_mm_audio_cntx.audio_level);

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 130);
    gdi_draw_solid_rect(5, 130, 200, 158, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "volume level: %d", g_vs_mm_audio_cntx.audio_level);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 130, 200, 158);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_set_volume_sub
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_set_volume_sub(volume_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    U8 volume = g_vs_mm_audio_cntx.audio_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (g_vs_mm_audio_cntx.audio_level == MDI_AUD_VOL_1)
    {
        return;
    }
    else
    {
        g_vs_mm_audio_cntx.audio_level = mdi_audio_decr_volume(volume);
    }

    if (g_vs_mm_audio_cntx.audio_level == MDI_AUD_VOL_1)
    {
        if (type != MDI_VOLUME_FMR)
        {
            mdi_audio_set_mute(VOL_TYPE_MEDIA, (kal_bool)1);
        }
        else
        {
            mdi_fmr_mute(1);
        }
    }

    if (g_vs_mm_audio_cntx.audio_level > MDI_AUD_VOL_1)
    {
        mdi_audio_set_volume((U8) type, g_vs_mm_audio_cntx.audio_level);
    }

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 130);
    gdi_draw_solid_rect(5, 130, 200, 158, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "volume level: %d", g_vs_mm_audio_cntx.audio_level);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 130, 200, 158);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_cache_draw_items
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_cache_draw_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    gui_move_text_cursor(5, 70);
    gui_print_text((UI_string_type) g_vs_mm_audio_cntx.cache_duration_buf);
    gui_move_text_cursor(5, 100);
    gui_print_text((UI_string_type) g_vs_mm_audio_cntx.total_duration_buf);
    gdi_layer_blt_previous(5, 70, 240, 98);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_get_audio_data
* DESCRIPTION
*  
* PARAMETERS
*  i           [IN]        
*  type        [?]
*  filelen     [?]
* RETURNS
*  
*****************************************************************************/
U8 *vs_mm_audio_misc_get_audio_data(MMI_ID_TYPE i, U8 *type, U32 *filelen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *s = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(type != NULL && filelen != NULL);

    *type = 0;;
    *filelen = 0;

    if (i == 0)
    {
        return (NULL);
    }

    s = (U8*) GetAudio((U16) i);
    if (s == NULL)
    {
        return (NULL);
    }
    if (s[0] == '\0')
    {
        return (NULL);
    }

    *type = s[0];

    *filelen |= (U32) (s[1]);
    *filelen |= (U32) ((U32) s[2] << 8);
    *filelen |= (U32) ((U32) s[3] << 16);
    *filelen |= (U32) ((U32) s[4] << 24);

    return (s + 8);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_file_setting_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_file_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    switch (g_vs_mm_audio_cntx.sub_type)
    {
    case 1:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");
        break;
    case 2:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.wav");
        break;
    case 3:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.amr");
        break;
    case 4:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.aac");
        break;
    case 5:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"aacplus.aac");
        break;
    case 6:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mid");
        break;
    case 7:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.imy");
        break;
    case 8:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp2");
        break;
    default:
        break;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_err_file_setting_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_err_file_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    switch (g_vs_mm_audio_cntx.sub_type)
    {
    case 1:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.mp3");
        break;
    case 2:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.wav");
        break;
    case 3:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.amr");
        break;
    case 4:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.aac");
        break;
    case 5:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"aacpluserr.aac");
        break;
    case 6:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.mid");
        break;
    case 7:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.imy");
        break;
    case 8:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audioerr.mp2");
        break;
    default:
        break;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_file_setting_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_record_file_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_audio_cntx.record_file_name, 0, sizeof(g_vs_mm_audio_cntx.record_file_name));

    switch (g_vs_mm_audio_cntx.sub_type)
    {
    case 1:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.record_file_name, (CHAR*) L"record.amr");
        break;
    case 2:
        vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.record_file_name, (CHAR*) L"record.wav");
        break;
    default:
        break;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_progress_time_cnt
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_progress_time_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    vs_mm_audio_001_get_progress_time();
    gui_move_text_cursor(5, 100);
    gdi_draw_solid_rect(5, 100, 240, 128, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.progress_buf);
    gdi_layer_blt_previous(5, 100, 240, 128);
    gui_start_timer(1000, vs_mm_audio_misc_progress_time_cnt);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_spectrum_time_cnt
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_spectrum_time_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32	height = 0;
    mdi_result ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    ret = mdi_audio_get_spectrum(g_vs_mm_audio_cntx.top, g_vs_mm_audio_cntx.amplitude_val);
    ASSERT(ret == MDI_AUDIO_SUCCESS);
    height = g_vs_mm_audio_cntx.top[i] - g_vs_mm_audio_cntx.amplitude_val[i];
    for (i = 0; i < 16; i++)
    {
        kal_prompt_trace(MOD_MMS, "spectum height:%d", height);
    }



    gui_start_timer(500, vs_mm_audio_misc_spectrum_time_cnt);
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_draw_freq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_draw_freq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_buf_temp[VS_MM_BUFFER_SIZE];
    S32 str_w, str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_buf_temp, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    sprintf((CHAR*) dis_buf_temp, (CHAR*) "FM %d.%d", g_vs_mm_audio_cntx.freq / 10, g_vs_mm_audio_cntx.freq % 10);

    mmi_asc_to_wcs((WCHAR*) dis_buf, dis_buf_temp);
    gui_measure_string((UI_string_type) dis_buf, &str_w, &str_h);
    gui_move_text_cursor(5, 160);
    gdi_draw_solid_rect(5, 160, 200, 188, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) dis_buf);
    gdi_layer_blt_previous(5, 160, 200, 188);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_is_valid_callback
* DESCRIPTION
*  
* PARAMETERS
*  is_valid        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_is_valid_callback(MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 220, 98, GDI_COLOR_WHITE);

    if (is_valid == TRUE)
    {
        gui_print_bordered_text((UI_string_type) L"fre: valid");
    }
    else
    {
        gui_print_bordered_text((UI_string_type) L"fre: invalid");
    }

    gdi_layer_blt_previous(5, 70, 220, 98);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_get_signal_level_callback
* DESCRIPTION
*  
* PARAMETERS
*  signal_level        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_get_signal_level_callback(U8 signal_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR disp_buf[VS_MM_BUFFER_SIZE];
    CHAR disp_temp_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(disp_buf, 0, VS_MM_BUFFER_SIZE);
    memset(disp_temp_buf, 0, VS_MM_BUFFER_SIZE);

    sprintf(disp_temp_buf, "signal level: %d", signal_level);

    mmi_asc_to_wcs((WCHAR*) disp_buf, disp_temp_buf);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 100);
    gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);

    gui_print_bordered_text((UI_string_type) disp_buf);
    gdi_layer_blt_previous(5, 100, 220, 128);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_screen_enter(void)
{
#ifdef __FM_RADIO_HW_SEARCH__


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.freq = VS_MM_AUDIO_FRM_MIN_FM_FREQUENCY;
    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.mono = FALSE;
    g_vs_mm_audio_cntx.mute = 0;
    g_vs_mm_audio_cntx.play_time = 0;
    g_vs_mm_audio_cntx.num = 21;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_FRM, NULL, vs_mm_audio_misc_fmr_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    SetLeftSoftkeyFunction(vs_mm_audio_misc_fmr_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_fmr_fail, KEY_EVENT_UP);

    vs_mm_audio_022_fmr_power_on();

    SetKeyHandler(vs_mm_audio_022_fmr_freq_seek_start, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_022_fmr_freq_seek_abort, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_022_fmr_set_volume_sub, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_022_fmr_set_volume_add, KEY_UP_ARROW, KEY_EVENT_UP);


#else
    kal_prompt_trace(MOD_MMS, "audio case 22 not support");
    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_surround_turn_on);
    AVK_ASYN_DONE();
#endif  



}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_speech_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_speech_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_is_speech_mode())
    {
        mdi_audio_speech_codec_stop();

        if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_GSM)
        {
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_speech_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_speech_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 20;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_SPEECH, vs_mm_audio_misc_speech_screen_exit, vs_mm_audio_misc_speech_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_021_speech_start, KEY_LEFT_ARROW, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_surround_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_surround_screen_enter(void)
{
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 16;

    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_SURROUND, NULL, vs_mm_audio_misc_surround_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    mdi_audio_surround_turn_on(g_vs_mm_audio_cntx.surround_mode);

    result = mdi_audio_play_file(
        (void*) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL);
    kal_prompt_trace(MOD_MMS, "mdi_audio_play_file return %d", result);


    if (result != MDI_AUDIO_SUCCESS)
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
        ASSERT(0);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_017_surround_turn_on, KEY_LEFT_ARROW, KEY_EVENT_UP);
    //#endif /* defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) */
#else
    kal_prompt_trace(MOD_MMS, "audio case 17 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_surround_turn_on);

    AVK_ASYN_DONE();
#endif  

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_eq_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_eq_screen_enter(void)
{
#if defined(__BES_EQ_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 14;

    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));
    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_EQ, NULL, vs_mm_audio_misc_eq_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    mdi_audio_eq_set_magnitude((S8*) NVRAM_EF_AUDIO_EQUALIZER_DEFAULT->magnitude[g_vs_mm_audio_cntx.magnitude_index]);
    mdi_audio_eq_turn_on();

    result = mdi_audio_play_file(
        (void*) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    } 

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_015_eq_set_magnitude, KEY_LEFT_ARROW, KEY_EVENT_UP);
    //#endif /* defined(__BES_EQ_SUPPORT__) */
#else
    kal_prompt_trace(MOD_MMS, "audio case 15 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_eq_turn_on);

    AVK_ASYN_DONE();
#endif  

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_reverb_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_reverb_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_result result;

    g_vs_mm_audio_cntx.num = 15;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_REVERB, NULL, vs_mm_audio_misc_reverb_screen_enter, MMI_FRM_FULL_SCRN);
    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;


#ifdef __MMI_AUDIO_REVERB_EFFECT__

    mdi_audio_reverb_set_mode(3);
    result = mdi_audio_reverb_turn_on();
#endif
    result = mdi_audio_play_file(
        (void*) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    } 
    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_spectrum_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_spectrum_screen_enter(void)
{
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 17;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_SPECTRUM, NULL, vs_mm_audio_misc_spectrum_screen_enter, MMI_FRM_FULL_SCRN);
    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    result = mdi_audio_play_file(
        (void*) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        ASSERT(0);
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);
        //DeleteScreenIfPresent(SCR_ID_VS_MM_AUDIO_SPECTRUM);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;
    }
    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_018_spectrum_start, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
    kal_prompt_trace(MOD_MMS, "audio case 18 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_start_calc_spectrum);

    AVK_ASYN_DONE();

#endif
}
/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bass_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bass_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__BES_BASS_SUPPORT__)	
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 25;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BASS, NULL, vs_mm_audio_misc_bass_screen_enter, MMI_FRM_FULL_SCRN);
    memset(g_vs_mm_audio_cntx.file_buf, 0, sizeof(g_vs_mm_audio_cntx.file_buf));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.file_buf, (CHAR*) L"audio.mp3");

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    result = mdi_audio_play_file(
        (void *) g_vs_mm_audio_cntx.file_buf,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        (mdi_ext_callback)vs_mm_audio_misc_play_callback,
        NULL);

    if (result != MDI_AUDIO_SUCCESS)
    {
        GoBackHistory();
        AVK_ASYN_DONE();

        return;
    }
    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_026_bass_turn_on, KEY_LEFT_ARROW, KEY_EVENT_UP);
    return;
#else
    kal_prompt_trace(MOD_MMS, "audio case 26 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_audio_bass_enhance_turn_on);

    AVK_ASYN_DONE();
#endif /*__BES_BASS_SUPPORT__*/
}
/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bt_volume_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bt_volume_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    WCHAR wszError[] = { 'e','r','r','o','r','\0'};
    WCHAR wszError1[] = { 'e','r','r','o','r','1','\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vs_mm_audio_cntx.num = 26;

    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");

    /* Need to redirect audio thru BT to test this case */
#if defined(__MMI_A2DP_SUPPORT__)
    if (SRV_BT_CM_POWER_ON != srv_bt_cm_get_power_status())
    {
        srv_bt_cm_switch_on();
    }

#else
    AVK_LOG_FUN_UNSUPPORTED(srv_bt_cm_get_power_status);

    kal_prompt_trace(MOD_MMS,"audio case 27 not support");
        AVK_ASYN_DONE();
    return; 
#endif

    mdi_audio_suspend_background_play();

#ifdef __BT_SPK_VOL_CONTROL__
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    mdi_audio_bt_register_volume_sync_callback(APP_SDK_TEST,MDI_AUD_VOL_LEVEL_NORMAL,vs_mm_audio_misc_027_bt_volume_sync_callback);
#endif
#endif

    result = mdi_audio_play_file_with_vol_path(
        (void*) g_vs_mm_audio_cntx.filename,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        (mdi_ext_callback)vs_mm_audio_misc_play_callback,
        NULL,
        MDI_AUD_VOL_3,
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER));

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_set_volume_to_bt(MDI_AUD_VOL_3);
#endif /*__BT_SPK_VOL_CONTROL__*/

    if (result != MDI_AUDIO_SUCCESS)              
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_get_duration, error code :%d;\n", result);

        mdi_audio_resume_background_play();

#ifdef __BT_SPK_VOL_CONTROL__
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
        mdi_audio_bt_clear_volume_sync_callback(APP_SDK_TEST);
#endif 
#endif        

        return;

    }


    vs_mm_audio_misc_play_file_through_bt_screen_enter();

}



#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_027_bt_volume_sync_callback
* DESCRIPTION
*  
* PARAMETERS
*
* RETURNS
*  
*****************************************************************************/
MMI_BOOL vs_mm_audio_misc_027_bt_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //mdi_audio_sync_volume_from_bt(volume);

    g_vs_mm_audio_cntx.audio_level = volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if (g_vs_mm_audio_cntx.audio_level >= 16)
    {
    return;
    }*/

    mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_vs_mm_audio_cntx.audio_level)));

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 130);
    gdi_draw_solid_rect(5, 130, 200, 158, GDI_COLOR_WHITE);
    sprintf((CHAR*) dis_buf, (CHAR*) "volume level: %d", g_vs_mm_audio_cntx.audio_level);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 130, 200, 158);
    return MMI_TRUE;



}
#endif



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_028_play_text
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_028_play_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)	
    U16 text_str[] = {20139, 20228, 20956, 0};
    WCHAR text_buf[VS_MM_BUFFER_SIZE];
    U16 length = 0;
    U16 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 27;

    mmi_ucs2cpy((CHAR*)g_vs_mm_audio_cntx.state_buf,(CHAR *)text_str);
    length = mmi_wcslen(text_str);
    if (length > 0)
    {
        result = mdi_audio_play_text_with_vol_path(
            (U8*) text_str,
            length,
            100,
            NULL,
            NULL,
            srv_prof_get_ring_vol(),
            MDI_DEVICE_SPEAKER2);

        AVK_LOG_FUN(mdi_audio_play_text_with_vol_path,AVK_PASS);

        if (result != MDI_AUDIO_SUCCESS)
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_play_text_with_vol_path, error code :%d;\n", result);
            return;
        }

        vs_mm_audio_misc_play_text_screen_enter();


    }
    else
    {
        kal_prompt_trace(MOD_MMS, "mdi_audio_play_text_with_vol_path : Invalid text");
        return;
    }	

#else
    kal_prompt_trace(MOD_MMS,"audio case 28 not support");

    AVK_LOG_FUN_UNSUPPORTED(srv_bt_cm_get_power_status);

    AVK_ASYN_DONE();
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_text_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_text_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_030, NULL, vs_mm_audio_misc_play_text_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    SetLeftSoftkeyFunction(vs_mm_audio_misc_file_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_file_fail, KEY_EVENT_UP);

}
/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_bg_play_by_app
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_bg_play_by_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vs_mm_audio_cntx.num = 26;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BG_PLAY_BY_APP, NULL, vs_mm_audio_misc_bg_play_by_app, MMI_FRM_FULL_SCRN);
    g_vs_mm_audio_cntx.suspended = 0;
    g_vs_mm_audio_cntx.play_time = 0;

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    mdi_audio_set_background_handler(MMI_BACKGROUND_APP,(mdi_bg_callback) vs_mm_audio_029_misc_bg_callback_hdlr,NULL);
    AVK_LOG_FUN(mdi_audio_set_background_handler,AVK_PASS);


    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BG_PLAY_BY_APP, vs_mm_audio_029_bg_play_delete_history_hdlr);

    vs_mm_audio_029_misc_play();


    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_029_bg_play_by_app_operate, KEY_LEFT_ARROW, KEY_EVENT_UP);

}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_029_misc_play
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_029_misc_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 order = -1;
    U8 empty = 0;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.suspended = mdi_audio_is_background_play_suspended();
    order = mdi_audio_get_background_callback_order(MMI_BACKGROUND_APP);
    empty = mdi_audio_get_background_callback_register_app_num();


    AVK_LOG_FUN(mdi_audio_is_background_play_suspended,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_get_background_callback_order,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_get_background_callback_register_app_num,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_clear_background_handler,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_clear_other_background_handler,AVK_PASS);




//    /* This could happen when timer experied after suspend background play or another play or record req by others */
//    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FOUR_VALS,g_vs_mm_audio_cntx.suspended,empty,order,-1);

    if (g_vs_mm_audio_cntx.suspended || empty==0 || order!=0 || !mdi_audio_is_idle())
    {

        kal_prompt_trace(MOD_MMS,"File play not allowed");


    }
    else
    {

        result = mdi_audio_play_file(
            (void*) g_vs_mm_audio_cntx.filename,
            DEVICE_AUDIO_PLAY_CRESCENDO,
            NULL,
            (mdi_ext_callback)vs_mm_audio_misc_bg_play_callback,
            NULL);

        if (result != MDI_AUDIO_SUCCESS)
        {
            kal_prompt_trace(MOD_MMS, "mdi_audio_play_file, error code :%d;\n", result);


        }

    }

}
/*****************************************************************************
* FUNCTION
*  vs_mm_audio_029_bg_play_delete_history_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  mmi_event_struct
* RETURNS
*  MMI_BOOL
*****************************************************************************/
mmi_ret vs_mm_audio_029_bg_play_delete_history_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:

        if (!g_vs_mm_audio_cntx.bg_playing)
        {
            mdi_audio_stop_file();
            mdi_audio_clear_background_handler(MMI_BACKGROUND_APP);

        }	
        else
        {
            if (mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE))
            {
                mdi_audio_clear_other_background_handler(MMI_BACKGROUND_APP);
        	  	}
            else
            {

                mdi_audio_clear_background_handler(MMI_BACKGROUND_APP);

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
*  vs_mm_audio_029_bg_play_by_app_operate
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_029_bg_play_by_app_operate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 disp_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_vs_mm_audio_cntx.bg_playing)
    {
        mdi_audio_get_progress_time(&g_vs_mm_audio_cntx.play_time);
        g_vs_mm_audio_cntx.bg_playing = 1;
        mdi_audio_suspend_background_play_by_app((MDI_AUD_SUSPEND_BG_APP)MMI_BACKGROUND_APP);
    }
    else
    {
        g_vs_mm_audio_cntx.bg_playing = 0;
        mdi_audio_resume_background_play_by_app((MDI_AUD_SUSPEND_BG_APP)MMI_BACKGROUND_APP);

    }	

    memset(disp_buf, 0, VS_MM_BUFFER_SIZE);

    if (mdi_audio_is_background_play_suspended())
    {
        mmi_asc_to_wcs((WCHAR*) disp_buf, (CHAR*) "bg is suspended    ");
    }
    else
    {
        mmi_asc_to_wcs((WCHAR*) disp_buf, (CHAR*) "bg is not suspended");
    }
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    gdi_draw_solid_rect(5, 70, 200, 98, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) disp_buf);
    gdi_layer_blt_previous(5, 70, 200, 98);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_029_misc_bg_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL vs_mm_audio_029_misc_bg_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");

    mdi_audio_play_file_portion_with_vol_path(
        (void*) g_vs_mm_audio_cntx.filename,
        g_vs_mm_audio_cntx.play_time,
        0,
        DEVICE_AUDIO_PLAY_CRESCENDO,
        NULL,
        (mdi_ext_callback)vs_mm_audio_misc_bg_play_callback,
        NULL,
        (U8) MDI_AUD_VOL_EX(g_vs_mm_audio_cntx.audio_level),
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    return MMI_TRUE;

}




/*****************************************************************************
* FUNCTION
*  vs_mm_audio_030_play_voice_tag
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_030_play_voice_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
#ifdef VR_ENABLE
    S32 result;


    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.num = 28;



    result = mdi_audio_play_voice_tag(
        MED_VR_ISD_MODE,
        MED_VR_NO_CARE_LANG,
        MMI_VRSD_GROUP_ALL,
        15,
        NULL,
        NULL);
    AVK_LOG_FUN(mdi_audio_play_voice_tag,AVK_PASS);

    if (result != MDI_AUDIO_SUCCESS)
   	{
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_030_play_voice_tag, error code :%d;\n", result);
        return;
   	}

    vs_mm_audio_misc_play_voice_tag_screen_enter();




#else
#endif
}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_voice_tag_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_voice_tag_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_031, NULL, vs_mm_audio_misc_play_voice_tag_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    SetLeftSoftkeyFunction(vs_mm_audio_misc_file_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_file_fail, KEY_EVENT_UP);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_031_vr_voice_record
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_031_vr_voice_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef VR_ENABLE
    mdi_result result;
    U32 session_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vs_mm_audio_cntx.num = 29;

    session_id = media_aud_vr_new_session_id();
    result = media_aud_vr_init_rcg(
        MOD_MMS,
        session_id,
        MED_VR_ISD_MODE,
        MED_VR_NO_CARE_LANG,
        MMI_VRSD_GROUP_ALL);

    if (result == MED_RES_OK)
    {
        result = mdi_audio_start_vr_voice_record( session_id, 1, NULL, NULL);
        if (result != MED_RES_OK)
        {
            kal_prompt_trace(MOD_MMS, "vs_mm_audio_031_vr_voice_record, error code :%d;\n", result);
            return;
        }

        vs_mm_audio_misc_vr_voice_record_screen_enter();                     

    }
    else
    {
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_031_vr_voice_record, error code :%d;\n", result);
        return;


    }

#else
#endif




}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_vr_voice_record_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_vr_voice_record_screen_enter(void)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_032, NULL, vs_mm_audio_misc_vr_voice_record_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    SetLeftSoftkeyFunction(vs_mm_audio_misc_record_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_record_fail, KEY_EVENT_UP);



}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_vibrator_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_vibrator_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_VIBRATOR, NULL, vs_mm_audio_misc_vibrator_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_GLOBAL_ON, 0, STR_GLOBAL_BACK, 0, vs_mm_audio_misc_display_screen, NULL);
    g_vs_mm_audio_cntx.play_time = 0;

    SetKeyHandler(vs_mm_audio_006_vibrator_enable, KEY_UP_ARROW, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_cache_update_duration
* DESCRIPTION
*  
* PARAMETERS
*  duration        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_cache_update_duration(U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_buf[VS_MM_BUFFER_SIZE];
    CHAR dis_str[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d sec.", duration / 1000);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);

    gui_move_text_cursor(5, 220);
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 220, 200, 248, GDI_COLOR_WHITE);
    gui_print_bordered_text((UI_string_type) dis_str);
    gdi_layer_blt_previous(5, 220, 200, 248);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_snd_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_snd_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearKeyEvents();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_snd_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_snd_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BG_PLAY, vs_mm_audio_misc_snd_screen_exit, vs_mm_audio_misc_snd_screen_enter, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);

    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.play_time = 0;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_other_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_other_fail, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_012_snd_set_volume_add, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_012_snd_set_volume_sub, KEY_DOWN_ARROW, KEY_EVENT_UP);


    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_record_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(result == MDI_AUDIO_SUCCESS || result == MDI_AUDIO_TERMINATED))
    {
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_record_callback, error code :%d;\n", result);
    }

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_record_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearKeyEvents();
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

    if (mmi_frm_get_active_scenario_id() == MMI_SCENARIO_ID_INVALID)
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_record_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_audio_cntx.sub_type == 1)
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

        MMI_ASSERT(mmi_frm_is_scenario_started(MMI_SCENARIO_ID_HIGHEST_SCRN));

        mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_RECORD, vs_mm_audio_misc_record_screen_exit, vs_mm_audio_misc_record_screen_enter, MMI_FRM_FULL_SCRN);

        ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    }

    g_vs_mm_audio_cntx.play_time = 0;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_record_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_record_fail, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_set_string_buffer
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_set_string_buffer(vs_mm_audio_string_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 audio_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    case VS_MM_AUDIO_FORMAT_SMF:
        g_vs_mm_audio_cntx.audio_buffer =
            (PU8) vs_mm_audio_misc_get_audio_data(
            AUD_ID_VS_MM_MID_PLAY,
            &audio_type,
            &g_vs_mm_audio_cntx.buffer_size);
        g_vs_mm_audio_cntx.str_type = MDI_FORMAT_SMF;
        break;
    case VS_MM_AUDIO_FORMAT_WAV:
        g_vs_mm_audio_cntx.audio_buffer =
            (PU8) vs_mm_audio_misc_get_audio_data(
            AUD_ID_VS_MM_WAV_PLAY,
            &audio_type,
            &g_vs_mm_audio_cntx.buffer_size);
        g_vs_mm_audio_cntx.str_type = MDI_FORMAT_WAV;
        break;
    case VS_MM_AUDIO_FORMAT_IMELODY:
        g_vs_mm_audio_cntx.audio_buffer =
            (PU8) vs_mm_audio_misc_get_audio_data(
            AUD_ID_VS_MM_IMY_PLAY,
            &audio_type,
            &g_vs_mm_audio_cntx.buffer_size);
        g_vs_mm_audio_cntx.str_type = MDI_FORMAT_IMELODY;
        break;
    case VS_MM_AUDIO_FORMAT_AMR:
        g_vs_mm_audio_cntx.audio_buffer =
            (PU8) vs_mm_audio_misc_get_audio_data(
            AUD_ID_VS_MM_AMR_PLAY,
            &audio_type,
            &g_vs_mm_audio_cntx.buffer_size);
        g_vs_mm_audio_cntx.str_type = MDI_FORMAT_AMR;
        break;
    default:
        g_vs_mm_audio_cntx.audio_buffer =
            (PU8) vs_mm_audio_misc_get_audio_data(
            AUD_ID_VS_MM_MID_PLAY,
            &audio_type,
            &g_vs_mm_audio_cntx.buffer_size);
        g_vs_mm_audio_cntx.str_type = MDI_FORMAT_SMF;
        break;

    }

    if (g_vs_mm_audio_cntx.audio_buffer == NULL)
    {
        return;
    }

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_display_screen
* DESCRIPTION
*  
* PARAMETERS
*  coordinate      [?]   
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_display_screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    CHAR dis_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);

    switch (g_vs_mm_audio_cntx.num)
    {
    case 0:
        gui_print_text((UI_string_type) L"play id");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"type: wav");
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"path: speaker2");
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "Audio Mode: %d ", mdi_audio_get_audio_mode());
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;
    case 1:
        gui_print_text((UI_string_type) L"play string");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);

        if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_SMF)
        {
            gui_print_bordered_text((UI_string_type) L"type: mid");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_WAV)
        {
            gui_print_bordered_text((UI_string_type) L"type: wav");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_IMELODY)
        {
            gui_print_bordered_text((UI_string_type) L"type: imy");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"type: amr");
        }

        gui_move_text_cursor(5, 100);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        break;
    case 2:
        gui_print_text((UI_string_type) L"play string with vol path");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);

        gui_move_text_cursor(5, 100);

        if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_SMF)
        {
            gui_print_bordered_text((UI_string_type) L"type: mid");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_WAV)
        {
            gui_print_bordered_text((UI_string_type) L"type: wav");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_IMELODY)
        {
            gui_print_bordered_text((UI_string_type) L"type: imy");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"type: amr");
        }

        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");

        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;
    case 3:
        gui_print_text((UI_string_type) L"play string portion");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);

        gui_move_text_cursor(5, 100);

        if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_SMF)
        {
            gui_print_bordered_text((UI_string_type) L"type: mid");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_WAV)
        {
            gui_print_bordered_text((UI_string_type) L"type: wav");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_IMELODY)
        {
            gui_print_bordered_text((UI_string_type) L"type: imy");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"type: amr");
        }
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;
    case 4:
        gui_print_text((UI_string_type) L"play string no block");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);

        gui_move_text_cursor(5, 100);

        if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_SMF)
        {
            gui_print_bordered_text((UI_string_type) L"type: mid");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_WAV)
        {
            gui_print_bordered_text((UI_string_type) L"type: wav");
        }
        else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_IMELODY)
        {
            gui_print_bordered_text((UI_string_type) L"type: imy");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"type: amr");
        }
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;
    case 5:
        gui_print_text((UI_string_type) L"play file");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"progress: 0");
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        gui_move_text_cursor(5, 190);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 220);
        sprintf((CHAR*) dis_buf, (CHAR*) "Seekable: %d ",(U8)vs_mm_audio_001_is_aac_file_seekable());
        mmi_asc_to_wcs((WCHAR*) dis_str,  dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;

    case 6:
        gui_print_text((UI_string_type) L"play file vol path");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);


        break;
    case 7:
        gui_print_text((UI_string_type) L"play file portion");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;
    case 8:
        gui_print_text((UI_string_type) L"record file");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"max time: 10 sec");
        gui_move_text_cursor(5, 100);
        if (g_vs_mm_audio_cntx.type == 0)
        {
            gui_print_bordered_text((UI_string_type) L"max size: 50 k");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"max size: 200 k");
        }
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.record_file_name);
        gui_move_text_cursor(5, 160); 
        vs_mm_audio_001_idle_or_play(); 
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        break;
    case 9:
        gui_print_text((UI_string_type) L"bg play control");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"bg is not suspended");
        break;
    case 10:
        gui_print_text((UI_string_type) L"snd play string");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        vs_mm_audio_012_snd_is_idle();
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"type: wav");
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        break;
    case 11:
        gui_print_text((UI_string_type) L"snd play file");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        vs_mm_audio_012_snd_is_idle();
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        break;
    case 12:
        gui_print_text((UI_string_type) L"build cache");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));

        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        break;
    case 13:
        gui_print_text((UI_string_type) L"tts");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) GetString((U16) (STR_ID_VS_MM_AUDIO_TTS)));
        break;
    case 14:
        gui_print_text((UI_string_type) L"eq");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"magnitude index: 0");
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 15:
        gui_print_text((UI_string_type) L"reverb");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        sprintf((CHAR*) dis_buf, (CHAR*) "reverb index: %d ", g_vs_mm_audio_cntx.reverb_index);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 16:
        gui_print_text((UI_string_type) L"surround");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        sprintf((CHAR*) dis_buf, (CHAR*) "surround mode: %d ", g_vs_mm_audio_cntx.surround_mode);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 17:
        gui_print_text((UI_string_type) L"spectrum");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 18:
        gui_print_text((UI_string_type) L"stretch file");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        sprintf((CHAR*) dis_buf, (CHAR*) "curr speed: %d", g_vs_mm_audio_cntx.speed);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 19:
        gui_print_text((UI_string_type) L"stretch string");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        sprintf((CHAR*) dis_buf, (CHAR*) "curr speed: %d", g_vs_mm_audio_cntx.speed);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"type: wav");
        break;
    case 20:
        gui_print_text((UI_string_type) L"speech");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"speech mode: idle");
        break;
    case 21:
        gui_print_text((UI_string_type) L"FM Radio");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"fre: invalid");
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"signal level: 0");
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        gui_print_bordered_text((UI_string_type) L"FM 87.5");
        gui_move_text_cursor(5, 190);
        gui_print_text((UI_string_type) L"channel: stereo");

        break;
    case 24:
        gui_print_text((UI_string_type) L"bass");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.file_buf);
        break;
    case 25:
        gui_print_text((UI_string_type) L"bass");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_move_text_cursor(5, 70);
        vs_mm_audio_001_idle_or_play();
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) L"progress: 0");
        gui_move_text_cursor(5, 130);
        gui_print_bordered_text((UI_string_type) L"volume level: 3");
        gui_move_text_cursor(5, 160);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
        gui_move_text_cursor(5, 190);
        sprintf((CHAR*) dis_buf, (CHAR*) "duration: %d ", g_vs_mm_audio_cntx.total_time);
        mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
        gui_print_bordered_text((UI_string_type) dis_str);
        break;

    case 26:
        gui_print_text((UI_string_type) L"bt play");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        break;

    case 27:
        gui_print_text((UI_string_type) L"Play text");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        break;

    case 28:
        gui_print_text((UI_string_type) L"Play voice tag");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        //gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
        break;
    case 29:
        gui_print_text((UI_string_type) L"VR  voice record");
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"Session Id : 1");
        break;





    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_display_err_screen
* DESCRIPTION
*  
* PARAMETERS
*  coordinate      [?]     
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_display_err_screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR dis_str[VS_MM_BUFFER_SIZE];
    CHAR dis_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);

    gui_print_text((UI_string_type) L"play file");
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 70);
    vs_mm_audio_001_idle_or_play();
    gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.state_buf);
    gui_move_text_cursor(5, 100);
    gui_print_bordered_text((UI_string_type) L"progress: 0");
    gui_move_text_cursor(5, 130);
    gui_print_bordered_text((UI_string_type) L"volume level: 3");
    gui_move_text_cursor(5, 160);
    gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
    gui_move_text_cursor(5, 190);
    sprintf((CHAR*) dis_buf, (CHAR*) "open err: %d ", g_vs_mm_audio_cntx.result);
    mmi_asc_to_wcs((WCHAR*) dis_str, dis_buf);
    gui_print_bordered_text((UI_string_type) dis_str);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearKeyEvents();

    kal_prompt_trace(MOD_MMS,"vs_mm_audio_misc_play_screen_exit 0");
    gui_cancel_timer(vs_mm_audio_misc_progress_time_cnt);

    if (g_vs_mm_audio_cntx.audio_cache_file_buf_p != NULL)
    {
        mmi_frm_scrmem_free(g_vs_mm_audio_cntx.audio_cache_file_buf_p);
        g_vs_mm_audio_cntx.audio_cache_file_buf_p = NULL;
    }

    kal_prompt_trace(MOD_MMS,"vs_mm_audio_misc_play_screen_exit 1");
    if (g_vs_mm_audio_cntx.audio_cache_proc_buf_p != NULL)
    {
        mmi_frm_scrmem_free(g_vs_mm_audio_cntx.audio_cache_proc_buf_p);
        g_vs_mm_audio_cntx.audio_cache_proc_buf_p = NULL;
    }

    kal_prompt_trace(MOD_MMS,"vs_mm_audio_misc_play_screen_exit 2");
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_id_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_id_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_PLAY, vs_mm_audio_misc_play_screen_exit, vs_mm_audio_misc_play_id_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    g_vs_mm_audio_cntx.mute = 0;
    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.total_time = 0;
    g_vs_mm_audio_cntx.stop = 0;
    g_vs_mm_audio_cntx.cur_offset = 0;
    g_vs_mm_audio_cntx.play_time = 0;
    g_vs_mm_audio_cntx.audio_cache_file_buf_p = NULL;
    g_vs_mm_audio_cntx.audio_cache_proc_buf_p = NULL;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_id_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_id_fail, KEY_EVENT_UP);

    SetKeyHandler(vs_mm_audio_001_set_volume_add, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_volume_sub, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_headset_mode_output_path, KEY_RIGHT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_string_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_string_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_PLAY, vs_mm_audio_misc_play_screen_exit, vs_mm_audio_misc_play_string_screen_enter, MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    g_vs_mm_audio_cntx.mute = 0;
    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.total_time = 0;
    g_vs_mm_audio_cntx.stop = 0;
    g_vs_mm_audio_cntx.cur_offset = 0;
    g_vs_mm_audio_cntx.play_time = 0;
    g_vs_mm_audio_cntx.audio_cache_file_buf_p = NULL;
    g_vs_mm_audio_cntx.audio_cache_proc_buf_p = NULL;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_string_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_string_fail, KEY_EVENT_UP);

    SetKeyHandler(vs_mm_audio_001_set_volume_add, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_volume_sub, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_headset_mode_output_path, KEY_RIGHT_ARROW, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_file_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_file_screen_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_PLAY, vs_mm_audio_misc_play_screen_exit, vs_mm_audio_misc_play_file_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    g_vs_mm_audio_cntx.mute = 0;
    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.total_time = 0;
    g_vs_mm_audio_cntx.stop = 0;
    g_vs_mm_audio_cntx.cur_offset = 0;
    g_vs_mm_audio_cntx.play_time = 0;
    g_vs_mm_audio_cntx.audio_cache_file_buf_p = NULL;
    g_vs_mm_audio_cntx.audio_cache_proc_buf_p = NULL;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_file_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_file_fail, KEY_EVENT_UP);

    SetKeyHandler(vs_mm_audio_001_set_volume_add, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_volume_sub, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_audio_001_set_headset_mode_output_path, KEY_RIGHT_ARROW, KEY_EVENT_UP);

}

/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_file_through_bt_screen_enter
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_file_through_bt_screen_enter(void)
{


    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_BT_VOLUME, NULL, vs_mm_audio_misc_play_file_through_bt_screen_enter, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);


    g_vs_mm_audio_cntx.mute = 0;
    g_vs_mm_audio_cntx.audio_level = MDI_AUD_VOL_3;
    g_vs_mm_audio_cntx.total_time = 0;
    g_vs_mm_audio_cntx.stop = 0;
    g_vs_mm_audio_cntx.cur_offset = 0;
    g_vs_mm_audio_cntx.play_time = 0;
    g_vs_mm_audio_cntx.audio_cache_file_buf_p = NULL;
    g_vs_mm_audio_cntx.audio_cache_proc_buf_p = NULL;

    SetLeftSoftkeyFunction(vs_mm_audio_misc_file_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_file_fail, KEY_EVENT_UP);

}





/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_resume_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_resume_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if you have pasue and resume, this function but not play 
    callback function will be called when play finished */
    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
    case MDI_AUDIO_TERMINATED:
        mdi_audio_stop_build_cache();
        mdi_audio_close_build_cache();
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_resume_callback, code value :%d;\n", result);
        break;
    case MDI_AUDIO_FAIL:
    case MDI_AUDIO_BUSY:
    case MDI_AUDIO_DISC_FULL:
    case MDI_AUDIO_OPEN_FILE_FAIL:
    case MDI_AUDIO_BAD_FORMAT:
    case MDI_AUDIO_INVALID_FORMAT:
    case MDI_AUDIO_ERROR:
    case MDI_AUDIO_NO_DISC:
    case MDI_AUDIO_NO_SPACE:
    case MDI_AUDIO_BLOCKED:
    case MDI_AUDIO_PARAM_ERROR:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_resume_callback, error code :%d;\n", result);
        break;
    case MDI_AUDIO_RESUME:
    default:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_resume_callback, code value :%d;\n", result);
        break;
    }

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_pause_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_pause_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
    case MDI_AUDIO_TERMINATED:
        mdi_audio_stop_build_cache();
        mdi_audio_close_build_cache();
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, code value :%d;\n", result);
        break;
    case MDI_AUDIO_FAIL:
    case MDI_AUDIO_BUSY:
    case MDI_AUDIO_DISC_FULL:
    case MDI_AUDIO_OPEN_FILE_FAIL:
    case MDI_AUDIO_BAD_FORMAT:
    case MDI_AUDIO_INVALID_FORMAT:
    case MDI_AUDIO_ERROR:
    case MDI_AUDIO_NO_DISC:
    case MDI_AUDIO_NO_SPACE:
    case MDI_AUDIO_BLOCKED:
    case MDI_AUDIO_PARAM_ERROR:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, error code :%d;\n", result);
        break;
    case MDI_AUDIO_RESUME:
    default:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, code value :%d;\n", result);
        break;
    }

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_play_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_play_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(vs_mm_audio_misc_progress_time_cnt);

    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
    case MDI_AUDIO_TERMINATED:
        mdi_audio_stop_build_cache();
        mdi_audio_close_build_cache();
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, code value :%d;\n", result);
        break;
    case MDI_AUDIO_FAIL:
    case MDI_AUDIO_BUSY:
    case MDI_AUDIO_DISC_FULL:
    case MDI_AUDIO_OPEN_FILE_FAIL:
    case MDI_AUDIO_BAD_FORMAT:
    case MDI_AUDIO_INVALID_FORMAT:
    case MDI_AUDIO_ERROR:
    case MDI_AUDIO_NO_DISC:
    case MDI_AUDIO_NO_SPACE:
    case MDI_AUDIO_BLOCKED:
    case MDI_AUDIO_PARAM_ERROR:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, error code :%d;\n", result);
        break;
    case MDI_AUDIO_RESUME:
    default:
        kal_prompt_trace(MOD_MMS, "vs_mm_audio_misc_play_callback, code value :%d;\n", result);
        break;
    }

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_get_file_path
* DESCRIPTION
*  
* PARAMETERS
*  path        [?]    
*  file        [?]    
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_get_file_path(CHAR* path, CHAR* file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //    S8 fileBuf[VS_MM_BUFFER_SIZE];
    kal_wchar wszAudio[] = {0x0041, 0x0075, 0x0064, 0x0069, 0x006F, 0x005C, 0x0000};  /* default folder = Audio */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //    memset(fileBuf, 0, VS_MM_BUFFER_SIZE);
    memset(path, 0, VS_MM_BUFFER_SIZE);

    mmi_wcscat((U16*) path, (U16*) AVK_TEST_FILE_PATH);
    mmi_wcscat((U16*) path, (U16*) L"avk_mm_audio\\");
    mmi_wcscat((U16*) path, (U16*) file);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_draw_string_type
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_draw_string_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 70, 220, 98, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 70);

    gui_move_text_cursor(5, 70);

    if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_SMF)
    {
        gui_print_bordered_text((UI_string_type) L"type: mid");
    }
    else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_WAV)
    {
        gui_print_bordered_text((UI_string_type) L"type: wav");
    }
    else if (g_vs_mm_audio_cntx.str_type == MDI_FORMAT_IMELODY)
    {
        gui_print_bordered_text((UI_string_type) L"type: imy");
    }
    else
    {
        gui_print_bordered_text((UI_string_type) L"type: amr");
    }

    gdi_layer_blt_previous(5, 70, 220, 98);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_draw_file_type
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_draw_file_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 160, 220, 188, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 160);
    gui_print_bordered_text((UI_string_type) g_vs_mm_audio_cntx.filename);
    gdi_layer_blt_previous(5, 160, 220, 188);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_id_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_id_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMS,"audio id pass 0");

    AVK_CASE_RESULT(AVK_PASS);
    switch (g_vs_mm_audio_cntx.count)
    {
    case 1:
        vs_mm_audio_001_stop();

        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_id_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_id_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);
    switch (g_vs_mm_audio_cntx.count)
    {
    case 1:
        vs_mm_audio_001_stop();
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_string_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_string_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_PASS);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 1:
        {
            vs_mm_audio_001_stop();
            GoBackHistory();
            AVK_ASYN_DONE();
        }
        break;
    case 2:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;
    case 3:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;
    case 4:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;

    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_string_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_string_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 1:

        vs_mm_audio_001_stop();
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 2:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();


                break;
            }
        }
        break;
    case 3:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;
    case 4:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;

    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_file_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_file_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_CASE_RESULT(AVK_PASS);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 5:
        {
            vs_mm_audio_001_stop();
            GoBackHistory();
            AVK_ASYN_DONE();	

        }
        break;

    case 6:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();


                break;
            }
        }
        break;
    case 7:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                break;
            }
        }

    case 26:
        {
#ifdef __BT_SPK_VOL_CONTROL__
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
            mdi_audio_bt_clear_volume_sync_callback(APP_SDK_TEST);
#endif 
#endif    			
            vs_mm_audio_001_stop();
            GoBackHistory();
            AVK_ASYN_DONE();


        }
        break;

    case 27:
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 28:
        GoBackHistory();
        AVK_ASYN_DONE();

        break;


    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_file_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_file_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 5:
        {
            vs_mm_audio_001_stop();
            GoBackHistory();
            AVK_ASYN_DONE();
        }

        break;
    case 6:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;
    case 7:
        {
            switch (g_vs_mm_audio_cntx.count)
            {
            case 1:
                vs_mm_audio_001_stop();
                g_vs_mm_audio_cntx.count = 1;
                g_vs_mm_audio_cntx.sub_type = 1;
                GoBackHistory();
                AVK_ASYN_DONE();

                break;
            }
        }
        break;
    case 26:
        {
#ifdef __BT_SPK_VOL_CONTROL__
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
            mdi_audio_bt_clear_volume_sync_callback(APP_SDK_TEST);
#endif 
#endif    
            vs_mm_audio_001_stop();
            mdi_audio_resume_background_play();
            GoBackHistory();
            AVK_ASYN_DONE();
        }
        break;

    case 27:
        GoBackHistory();
        AVK_ASYN_DONE();
        break;

    case 28:
        GoBackHistory();
        AVK_ASYN_DONE();

        break;	


    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_record_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_PASS);
    switch (g_vs_mm_audio_cntx.count)
    {
    case 1:
        vs_mm_audio_009_record_stop();
        g_vs_mm_audio_cntx.count++;
        break;
    case 2:
        mdi_audio_stop_file();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    }
}
void vs_mm_audio_misc_record_fail(void)
{
    AVK_CASE_RESULT(AVK_FAIL);

    switch (g_vs_mm_audio_cntx.count)
    {
    case 1:
        vs_mm_audio_009_record_stop();
        g_vs_mm_audio_cntx.count++;
        break;
    case 2:
        mdi_audio_stop_file();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_record_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/



/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_other_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_other_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_CASE_RESULT(AVK_PASS);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 9:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_misc_bg_screen_exit();
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 10:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_012_snd_stop_hdlr();
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 11:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_012_snd_stop_hdlr();
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 12:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        mdi_audio_stop_all();
        vs_mm_audio_misc_play_screen_exit();
        GoBackHistory();
        AVK_ASYN_DONE();

        break;
    case 13:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_014_tts_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 14:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
#if defined(__BES_EQ_SUPPORT__)
        vs_mm_audio_015_eq_turn_off();
#endif 
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 15:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_016_reverb_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 16:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_017_surround_turn_off();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 17:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_018_spectrum_end();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 18:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_019_stretch_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 19:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_019_stretch_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 20:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 25:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_026_bass_turn_off();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;

    case 26:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        mdi_audio_clear_background_handler(MMI_BACKGROUND_APP);
        mdi_audio_stop_file();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;



    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_other_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_other_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);
    switch (g_vs_mm_audio_cntx.num)
    {
    case 9:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_misc_bg_screen_exit();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 10:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_012_snd_stop_hdlr();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 11:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_012_snd_stop_hdlr();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 12:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        mdi_audio_stop_all();
        vs_mm_audio_misc_play_screen_exit();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 13:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_014_tts_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 14:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
#if defined(__BES_EQ_SUPPORT__)
        vs_mm_audio_015_eq_turn_off();
#endif 
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 15:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_016_reverb_stop();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 16:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_017_surround_turn_off();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 17:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_018_spectrum_end();
        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 18:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_019_stretch_stop();

        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 19:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_019_stretch_stop();

        GoBackHistory();
        AVK_ASYN_DONE();
        break;
    case 20:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;

        GoBackHistory();
        AVK_ASYN_DONE();
        break;

    case 24:

        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        vs_mm_audio_026_bass_turn_off();

        GoBackHistory();
        AVK_ASYN_DONE();
        break;

    case 26:
        g_vs_mm_audio_cntx.count = 1;
        g_vs_mm_audio_cntx.sub_type = 1;
        mdi_audio_clear_background_handler(MMI_BACKGROUND_APP);
        mdi_audio_stop_file();

        GoBackHistory();
        AVK_ASYN_DONE();
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_PASS);

    vs_mm_audio_022_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();

}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_fmr_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_fmr_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);
    vs_mm_audio_022_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();
}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_mma_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_mma_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_PASS);

    vs_mm_audio_023_mma_stop();
    vs_mm_audio_023_mma_exit();
    g_vs_mm_audio_cntx.count = 1;
    g_vs_mm_audio_cntx.sub_type = 1;

    GoBackHistory();
    AVK_ASYN_DONE();


}


/*****************************************************************************
* FUNCTION
*  vs_mm_audio_misc_mma_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_audio_misc_mma_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT(AVK_FAIL);

    vs_mm_audio_023_mma_stop();
    vs_mm_audio_023_mma_exit();
    g_vs_mm_audio_cntx.count = 1;
    g_vs_mm_audio_cntx.sub_type = 1;

    GoBackHistory();
    AVK_ASYN_DONE();
}










/*****************************************************************************
* FUNCTION
*  vs_mm_misc_init_audio
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_misc_init_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_audio_cntx.index = 0;
    g_vs_mm_audio_cntx.count = 1;
    g_vs_mm_audio_cntx.num = 0;
    g_vs_mm_audio_cntx.sub_type = 1;
    g_vs_mm_audio_cntx.magnitude_index = 0;
    g_vs_mm_audio_cntx.reverb_index = 0;
    g_vs_mm_audio_cntx.surround_mode = 0;
    g_vs_mm_audio_cntx.speed = 0;
    g_vs_mm_audio_cntx.type = 0;
    g_vs_mm_audio_cntx.bg_playing = 0;
    g_vs_mm_audio_cntx.id_type = AUD_ID_VS_MM_WAV_PLAY;
    memset(g_vs_mm_audio_cntx.filename, 0, sizeof(g_vs_mm_audio_cntx.filename));
    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.filename, (CHAR*) L"audio.mp3");
    memset(g_vs_mm_audio_cntx.record_file_name, 0, sizeof(g_vs_mm_audio_cntx.record_file_name));
    vs_mm_audio_misc_get_file_path((CHAR*) g_vs_mm_audio_cntx.record_file_name, (CHAR*) L"record.amr");
    vs_mm_audio_misc_set_string_buffer(VS_MM_AUDIO_FORMAT_SMF);

    memset(g_vs_mm_audio_cntx.prog_name, 0, sizeof(g_vs_mm_audio_cntx.prog_name));
    memset(g_vs_mm_audio_cntx.radio_text, 0, sizeof(g_vs_mm_audio_cntx.radio_text));


}







void vs_mm_audio_misc_032_pass(void)
{
    mdi_result ret;
    ret = mdi_audio_mma_stop(g_vs_mm_audio_cntx.m_handle032);
    kal_prompt_trace(MOD_MMS,"032 stop ret = %d",ret);
    ret = mdi_audio_mma_close(g_vs_mm_audio_cntx.m_handle032);	
    kal_prompt_trace(MOD_MMS,"032 close ret = %d",ret);
    GoBackHistory();
    AVK_ASYN_DONE();
}

void vs_mm_audio_misc_032_fail(void)
{
    mdi_result ret;
    ret = mdi_audio_mma_stop(g_vs_mm_audio_cntx.m_handle032);
    kal_prompt_trace(MOD_MMS,"032 stop ret = %d",ret);
    ret = mdi_audio_mma_close(g_vs_mm_audio_cntx.m_handle032);	
    kal_prompt_trace(MOD_MMS,"032 close ret = %d",ret);
    GoBackHistory();
    AVK_ASYN_DONE();

}

void vs_mm_audio_misc_033_pass(void)
{
    mdi_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();

}

void vs_mm_audio_misc_033_fail(void)
{
    mdi_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();

}

void vs_mm_audio_misc_034_pass(void)
{
    mdi_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();

}

void vs_mm_audio_misc_034_fail(void)
{
    mdi_fmr_power_off();
    GoBackHistory();
    AVK_ASYN_DONE();

}




void vs_mm_audio_032_misc_enter_screen(void)
{
    g_vs_mm_audio_cntx.num = 31;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_032, NULL, vs_mm_audio_032, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    SetLeftSoftkeyFunction(vs_mm_audio_misc_032_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_032_fail, KEY_EVENT_UP);
}

void vs_mm_audio_033_misc_enter_screen(void)
{
    g_vs_mm_audio_cntx.num = 32;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_033, NULL, vs_mm_audio_033, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    SetLeftSoftkeyFunction(vs_mm_audio_misc_033_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_033_fail, KEY_EVENT_UP);
}
void vs_mm_audio_034_misc_enter_screen(void)
{
    g_vs_mm_audio_cntx.num = 33;

    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_AUDIO_034, NULL, vs_mm_audio_034, MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, vs_mm_audio_misc_display_screen, NULL);
    SetLeftSoftkeyFunction(vs_mm_audio_misc_034_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_audio_misc_034_fail, KEY_EVENT_UP);

}





void vs_mm_audio_032_open_callback(kal_int32 handle, kal_int32 result, void* user_data)
{
    kal_prompt_trace(MOD_MMS,"aud032 open cb:handle = %d",handle);
    kal_prompt_trace(MOD_MMS,"aud032 open cb:result = %d",result);
    kal_prompt_trace(MOD_MMS,"aud032 open cb:user_data = %d",user_data);
    if(result == MDI_AUDIO_DUR_UPDATED)
    {
        U32 duration;
        mdi_audio_mma_get_updated_duration(g_vs_mm_audio_cntx.m_handle032,&duration);
    }
}

void vs_mm_audio_032_seek_callback(kal_uint8 reason, void* user_data)
{
    kal_prompt_trace(MOD_MMS,"aud032 seek cb:reason = %d",reason);
    kal_prompt_trace(MOD_MMS,"aud032 seek cb:user_data = %d",user_data);

}


void vs_mm_audio_032(void)
{
    mdi_handle handle = 0;
    mdi_mma_open_struct openStruct;
    mdi_result result;

    U16 filepath[100];
    U32 duration;

    vs_mm_audio_032_misc_enter_screen();

    vs_mm_audio_misc_get_file_path((CHAR*) filepath, (CHAR*) L"audio.wav");

    openStruct.app_id = ASM_ANONYMOUS_ID;
    openStruct.file_name = filepath;
    openStruct.data = NULL;
    openStruct.data_len = 0;
    openStruct.mdi_format = 0;
    openStruct.repeats = 1;
    openStruct.is_pdl = MMI_FALSE;
    openStruct.callback = vs_mm_audio_032_open_callback;
    openStruct.user_data = NULL;
    openStruct.handle_p = &handle;

    result = mdi_audio_mma_open(&openStruct);
    kal_prompt_trace(MOD_MMS,"032 mma_open ret = %d",result);
    if(*openStruct.handle_p == 0)
    {

        GoBackHistory();
        AVK_ASYN_DONE();
    }
    else
    {
        audInfoStruct audio_info;
        g_vs_mm_audio_cntx.m_handle032 = *(openStruct.handle_p);
        mdi_audio_mma_get_audio_info(ASM_ANONYMOUS_ID,filepath,MMA_TYPE_UNKNOWN,0,0,&audio_info);
        kal_prompt_trace(MOD_MMS,"032 mdi_handle = %d",g_vs_mm_audio_cntx.m_handle032);
        if(g_vs_mm_audio_cntx.m_handle032)
        {
#ifndef __PLUTO_MMI_PACKAGE__		
            mdi_audio_stop_seek();	
#endif
        }

        mdi_audio_mma_get_estimated_duration(g_vs_mm_audio_cntx.m_handle032,&duration);
#ifndef __PLUTO_MMI_PACKAGE__		
        mdi_audio_start_seek((void*)filepath,NULL,0,0,vs_mm_audio_032_seek_callback,NULL);
#endif		
        mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
        result = mdi_audio_mma_play(g_vs_mm_audio_cntx.m_handle032);		
    }


    AVK_LOG_FUN(mdi_audio_mma_open,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_get_audio_info,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_stop_seek,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_get_estimated_duration,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_start_seek,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_play,AVK_PASS);
    AVK_LOG_FUN(mdi_audio_mma_get_updated_duration,AVK_PASS);


}




void vs_mm_audio_033_power_on_callback(mdi_result result, void* user_data)
{
    kal_prompt_trace(MOD_MMS,"033 power cb: ret = %d",result);
}

void vs_mm_audio_033_scan_callback(mdi_fmr_cb_reason_enum result, void* cb_data, void* user_data)
{
    kal_prompt_trace(MOD_MMS,"033 scan cb: result = %d",result);
    kal_prompt_trace(MOD_MMS,"033 scan cb: cb_data = %d",cb_data);
}


void vs_mm_audio_033(void)
{
#ifdef __MMI_FM_RADIO__
#ifndef __PLUTO_MMI_PACKAGE__
    mdi_fmr_scan_req_struct scan_param;
    S32 ret;

    vs_mm_audio_033_misc_enter_screen();

    memset(&(g_vs_mm_audio_cntx.m_signalBand), 0, sizeof(g_vs_mm_audio_cntx.m_signalBand));

    scan_param.sorting = MDI_FMR_SORTING_BY_FREQ;
    scan_param.callback = vs_mm_audio_033_scan_callback;
    scan_param.max_channel = 20;
    scan_param.channel_list = (U16*)(&(g_vs_mm_audio_cntx.m_signalBand));
    scan_param.user_data = NULL;

    mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, vs_mm_audio_033_power_on_callback, NULL);


    mdi_fmr_scan_abort();
    ret = mdi_fmr_scan_start(&scan_param);	
    kal_prompt_trace(MOD_MMS,"033 mdi_fmr_scan_start ret = %d",ret);
    AVK_LOG_FUN(mdi_fmr_scan_abort,AVK_PASS);
    AVK_LOG_FUN(mdi_fmr_scan_start,AVK_PASS);
#endif
#else
    kal_prompt_trace(MOD_MMS, "audio case 31 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_fmr_seek_start);
    AVK_ASYN_DONE();

#endif


    AVK_LOG_FUN(mdi_fmr_power_on_with_path,AVK_PASS);


}


void vs_mm_audio_034_seek_callback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data)
{

    kal_prompt_trace(MOD_MMS,"034 seek cb: result = %d",result);
    kal_prompt_trace(MOD_MMS,"034 seek cb: stop_freq = %d",stop_freq);
    kal_prompt_trace(MOD_MMS,"034 seek cb: is_valid = %d",is_valid);
}

void vs_mm_audio_034(void)
{
    #ifdef __MMI_FM_RADIO__
#ifndef __PLUTO_MMI_PACKAGE__
    MMI_BOOL bIsOn = MMI_FALSE;
    S32 ret;

    mdi_fmr_seek_req_struct seek_param;
    vs_mm_audio_034_misc_enter_screen();

    mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, vs_mm_audio_033_power_on_callback, NULL);
    bIsOn = mdi_audio_is_fm_on();
 

    seek_param.start_freq = 900;
    seek_param.is_step_up = MMI_TRUE;
    seek_param.stop_criteria = MDI_FMR_SEEK_STOP_AT_BOUNDARY;
    seek_param.callback = vs_mm_audio_034_seek_callback;
    seek_param.user_data = NULL;

    ret = mdi_fmr_seek_start(&seek_param);
    kal_prompt_trace(MOD_MMS,"mdi_fmr_seek_start ret = %d",ret);
    AVK_LOG_FUN(mdi_fmr_seek_start,AVK_PASS);


    AVK_LOG_FUN(mdi_fmr_power_on_with_path,AVK_PASS);

    AVK_LOG_FUN(mdi_audio_is_fm_on,AVK_PASS);
#endif
#else
    kal_prompt_trace(MOD_MMS, "audio case 32 not support");

    AVK_LOG_FUN_UNSUPPORTED(mdi_fmr_seek_start);
    AVK_ASYN_DONE();

#endif

}
AVK_TEST_ALL(AVK_MM_AUDIO)

AVK_ADD_ITEM(AVK_AUDIO_ITEM_001,L"Audio 001",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_002,L"Audio 002",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_003,L"Audio 003",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_004,L"Audio 004",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_005,L"Audio 005",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_006,L"Audio 006",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_007,L"Audio 007",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_008,L"Audio 008",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_009,L"Audio 009",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_010,L"Audio 010",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_011,L"Audio 011",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_012,L"Audio 012",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_013,L"Audio 013",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_014,L"Audio 014",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_015,L"Audio 015",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_016,L"Audio 016",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_017,L"Audio 017",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_018,L"Audio 018",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_019,L"Audio 019",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_020,L"Audio 020",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_021,L"Audio 021",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_022,L"Audio 022",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_023,L"Audio 023",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_024,L"Audio 024",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_025,L"Audio 025",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_026,L"Audio 026",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_027,L"Audio 027",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_028,L"Audio 028",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_029,L"Audio 029",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_030,L"Audio 030",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_031,L"Audio 031",AVK_MM_AUDIO);
AVK_ADD_ITEM(AVK_AUDIO_ITEM_032,L"Audio 032",AVK_MM_AUDIO);



AVK_MANUAL_CASE(AVK_AUDIO_MANUAL1,AVK_AUDIO_ITEM_001)
{
    vs_mm_misc_init_audio();

    vs_mm_audio_001_play_id();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL2,AVK_AUDIO_ITEM_002)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_002_play_string();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL3,AVK_AUDIO_ITEM_003)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_003_play_string_vol_path();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL4,AVK_AUDIO_ITEM_004)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_004_play_string_portion_vol_path();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL5,AVK_AUDIO_ITEM_005)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_005_play_string_vol_path_non_block();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL6,AVK_AUDIO_ITEM_006)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_006_play_file();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL7,AVK_AUDIO_ITEM_007)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_007_play_file_vol_path();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL8,AVK_AUDIO_ITEM_008)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_008_play_file_portion_vol_path();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL9,AVK_AUDIO_ITEM_009)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_009_record_start();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL10,AVK_AUDIO_ITEM_010)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_bg_screen_enter();

}


AVK_MANUAL_CASE(AVK_AUDIO_MANUAL11,AVK_AUDIO_ITEM_011)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_011_snd_play_string();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL12,AVK_AUDIO_ITEM_012)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_012_snd_play_file();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL13,AVK_AUDIO_ITEM_013)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_013_build_cache();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL14,AVK_AUDIO_ITEM_014)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_014_tts();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL15,AVK_AUDIO_ITEM_015)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_eq_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL16,AVK_AUDIO_ITEM_016)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_reverb_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL17,AVK_AUDIO_ITEM_017)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_surround_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL18,AVK_AUDIO_ITEM_018)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_spectrum_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL19,AVK_AUDIO_ITEM_019)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_019_stretch_file();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL20,AVK_AUDIO_ITEM_020)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_020_stretch_string();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL21,AVK_AUDIO_ITEM_021)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_speech_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL22,AVK_AUDIO_ITEM_022)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_fmr_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL23,AVK_AUDIO_ITEM_023)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_023_mma();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL24,AVK_AUDIO_ITEM_024)
{
    AVK_CASE_RESULT(AVK_PASS);

    AVK_ASYN_DONE();
}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL25,AVK_AUDIO_ITEM_025)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_025_stream_play();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL26,AVK_AUDIO_ITEM_026)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_bass_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL27,AVK_AUDIO_ITEM_027)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_bt_volume_screen_enter();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL28,AVK_AUDIO_ITEM_028)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_028_play_text();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL29,AVK_AUDIO_ITEM_029)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_misc_bg_play_by_app();

}






AVK_MANUAL_CASE(AVK_AUDIO_MANUAL30,AVK_AUDIO_ITEM_030)
{
    vs_mm_misc_init_audio();


    vs_mm_audio_032();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL31,AVK_AUDIO_ITEM_031)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_033();

}

AVK_MANUAL_CASE(AVK_AUDIO_MANUAL32,AVK_AUDIO_ITEM_032)
{
    vs_mm_misc_init_audio();
    vs_mm_audio_034();

}












#endif /* __MAUI_SDK_TEST__ */ 
