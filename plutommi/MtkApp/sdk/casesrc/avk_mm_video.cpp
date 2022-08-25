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
*   tst_appser_mm_video.c
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

#include "avk_mm_video.h"
#include "GlobalResDef.h"
#include "FileMgrGProt.h"
#include "SettingDefs.h"        
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "med_api.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_multimedia.h"
#include "avk_MmData.h"
#include "mdi_video.h"
#include "mdi_bitstream.h"
#include "custom_data_account.h"
#include "soc_api.h"
#include "DataAccountDef.h"
#include "DataAccountGProt.h"
#include "ABM_SOC_ENUMS.H"
#include "abm_api.h"
#include "cbm_api.h"
#include "Conversions.h"
extern MDI_RESULT mdi_video_ply_close(void);
}




#define AMR_HEADER "#!AMR\n"


vs_mm_video_context_struct g_vs_mm_video_cntx;


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
void vs_mm_video_misc_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip,void *user_data);
#endif

/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_resume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_resume(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
    mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);
    SetKeyHandler(vs_mm_video_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
    vs_mm_video_001_play();
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_play
* DESCRIPTION
*  play the open file
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_play(void)
{


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)


    U32 blt_layer;
    U32 play_layer;
    MDI_RESULT ret;


    blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
    play_layer = (GDI_LAYER_ENABLE_LAYER_1);

    ret = mdi_video_ply_seek(g_vs_mm_video_cntx.play_time);

    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {

        mmi_frm_scrn_close_active_id();
    }

    gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, g_vs_mm_video_cntx.play_layer_handle, 0, 0);

    mdi_video_ply_enable_partial_display();

    ret = mdi_video_ply_play(
        g_vs_mm_video_cntx.play_layer_handle,   /* play layer handle */
        blt_layer,                              /* blt layer */
        play_layer,                             /* play_layer_flag */
        1,                                      /* repeat */
        TRUE,                                   /* visual update */
        TRUE,                                   /* play aud */
        MDI_DEVICE_SPEAKER2,                    /* audio path */
        0,                                      /* rotate */
        100,                                    /* speed factor */
        vs_mm_video_misc_play_finish_hdlr,
        NULL);     
    if (ret >= MDI_RES_VDOPLY_SUCCEED)
    {
        g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_PLAY;

    }
    else
    {

        mmi_frm_scrn_close_active_id();
    }

    return;
#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_pause
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_pause(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_video_cntx.state == VS_MM_VIDEO_STATE_PLAY)
    {
        g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_PAUSE;

        gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, g_vs_mm_video_cntx.play_layer_handle, 0, 0);

        vs_mm_video_001_stop();
        mdi_video_ply_get_cur_play_time(&g_vs_mm_video_cntx.play_time);
    }
    SetKeyHandler(vs_mm_video_001_resume, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_stop(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_stop();
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_close_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_close_file(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_video_cntx.type == VS_MM_VIDEO_TYPE_FILE)
    {
        mdi_video_ply_close_file();
    }
    else if (g_vs_mm_video_cntx.type == VS_MM_VIDEO_TYPE_FILE_CLIP)
    {
        mdi_video_ply_close_clip_file();
    }
    else if (g_vs_mm_video_cntx.type == VS_MM_VIDEO_TYPE_ID_CLIP)
    {
        mdi_video_ply_close_clip_id();
    }
    else if (g_vs_mm_video_cntx.type == VS_MM_VIDEO_TYPE_BUFFER_CLIP)
    {
        mdi_video_ply_close_clip_buffer();
    }
#endif
}





/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_set_stop_time
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_set_stop_time(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_get_cur_play_time(&cur_time);
    mdi_video_ply_set_stop_time(cur_time + 2);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_is_playing
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_is_playing(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR dst[32] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.play_ptr, 0, VS_MM_BUFFER_SIZE*2);



    if (mdi_video_is_playing())
    {
        mmi_chset_convert(MMI_CHSET_ASCII, MMI_CHSET_UCS2,  "state: play", (char*)dst, sizeof(dst));
        mmi_wcscpy( g_vs_mm_video_cntx.play_ptr,  dst);
    }
    else
    {
        mmi_chset_convert(MMI_CHSET_ASCII, MMI_CHSET_UCS2,  "state: idle", (char*)dst, sizeof(dst));
        mmi_wcscpy( g_vs_mm_video_cntx.play_ptr,  dst);
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_set_brightness
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_set_brightness(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.brightness++;

    mdi_video_ply_set_brightness(g_vs_mm_video_cntx.brightness);

    if (g_vs_mm_video_cntx.brightness >= 10)
    {
        g_vs_mm_video_cntx.brightness = 0;
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_set_audio_level
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_set_audio_level(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.audio_level++;

    if (g_vs_mm_video_cntx.audio_level % 3 == 0)
    {
        mdi_video_ply_set_audio_level(1);
    }
    else if (g_vs_mm_video_cntx.audio_level % 3 == 1)
    {
        mdi_video_ply_set_audio_level(99);
    }
    else
    {
        mdi_video_ply_set_audio_level(50);
    }

    gdi_layer_blt_previous(5, 310, 220, 338);
#endif

}






/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_preview
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_preview(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;
    U32 fast_zoom_factor;
    U32 fast_zoom_step;
    mdi_camera_zoom_info zoom_info;
    U16 count;
    U32 i;
    mdi_video_rec_spec_struct video_rec_table; 
    U32 s = 0, q = 0, f = 0;
    MMI_BOOL is_real_item = MMI_TRUE;
    MMI_BOOL is_found =  MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.offset_x = 30;
    g_vs_mm_video_cntx.offset_y = 150;
    g_vs_mm_video_cntx.normal_width = 176;
    g_vs_mm_video_cntx.normal_height = 144;

    gdi_layer_create(
        g_vs_mm_video_cntx.offset_x,
        g_vs_mm_video_cntx.offset_y,
        g_vs_mm_video_cntx.normal_width,
        g_vs_mm_video_cntx.normal_height,
        &g_vs_mm_video_cntx.play_layer_handle);

    gdi_layer_get_base_handle(&g_vs_mm_video_cntx.osd_layer_handle);
    gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, g_vs_mm_video_cntx.play_layer_handle, 0, 0);

    mdi_video_rec_load_default_setting(&video_preview_data);

    AVK_LOG_FUN(mdi_video_rec_load_default_setting,AVK_PASS);

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
#endif

    video_preview_data.wb = MDI_VIDEO_WB_AUTO;
    video_preview_data.ev = MDI_VIDEO_EV_0;
    video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
    video_preview_data.effect = MDI_VIDEO_EFFECT_NOMRAL;

    video_preview_data.night = FALSE;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_270;
    video_preview_data.size_limit = 0;
    video_preview_data.record_aud = TRUE;
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
    video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;

    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &video_rec_table, sizeof(video_rec_table));
        
        switch (video_rec_table.video_size)
        {                        
            case MDI_VIDEO_REC_RESOLUTION_176x144:            
                s = MDI_VIDEO_VIDEO_SIZE_QCIF;
                q = video_rec_table.quality;
                f = video_rec_table.video_format;
                is_found = MMI_TRUE;
            break;  

            default:
                break;
        }

        if (is_found)
            break;

    }

    if (is_found)
    {
        video_preview_data.video_format = f;
        video_preview_data.video_qty = q;    
    }
    else
    {
        AVK_LOG_FUN(mdi_video_rec_preview_start,AVK_FAIL);
        mdi_video_rec_power_off();
        return;
    }

    mdi_video_rec_enable_partial_display();     
    AVK_LOG_FUN(mdi_video_rec_enable_partial_display,AVK_PASS);


    mdi_video_rec_preview_start(
        g_vs_mm_video_cntx.play_layer_handle,
        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
        GDI_LAYER_ENABLE_LAYER_1,
        MMI_TRUE,
        &video_preview_data);
    
    AVK_LOG_FUN(mdi_video_rec_preview_start,AVK_PASS);

    mdi_video_rec_update_para_effect(MDI_VIDEO_EFFECT_NOMRAL);
    
    AVK_LOG_FUN(mdi_video_rec_update_para_effect,AVK_PASS);
    mdi_video_rec_update_para_wb(MDI_VIDEO_WB_AUTO);
    
    AVK_LOG_FUN(mdi_video_rec_update_para_wb,AVK_PASS);
    mdi_video_rec_update_para_night(0);
    AVK_LOG_FUN(mdi_video_rec_update_para_night,AVK_PASS);

    mdi_video_rec_query_zoom_info(&zoom_info);
    AVK_LOG_FUN(mdi_video_rec_query_zoom_info,AVK_PASS);

    mdi_video_rec_get_fast_zoom_factor(&fast_zoom_factor);
    AVK_LOG_FUN(mdi_video_rec_get_fast_zoom_factor,AVK_PASS);


    mdi_video_rec_get_fast_zoom_step(&fast_zoom_step);
    
    AVK_LOG_FUN(mdi_video_rec_get_fast_zoom_step,AVK_PASS);

    mdi_video_rec_start_fast_zoom(TRUE, (U8) mdi_video_rec_get_max_zoom_factor(176,144), 1, 1);
    
    AVK_LOG_FUN(mdi_video_rec_start_fast_zoom,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_get_max_zoom_factor,AVK_PASS);
    
    mdi_video_rec_stop_fast_zoom();
    
    AVK_LOG_FUN(mdi_video_rec_stop_fast_zoom,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_update_blt_pause,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_update_blt_resume,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_update_para_ev,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_update_para_zoom,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_record_pause,AVK_PASS);
    AVK_LOG_FUN(mdi_video_rec_record_resume,AVK_PASS);

    SetLeftSoftkeyFunction(vs_mm_video_misc_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_video_misc_fail, KEY_EVENT_UP);

    SetKeyHandler(vs_mm_video_005_rec_update_blt_pause, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_video_005_rec_update_para_ev, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_mm_video_005_rec_update_para_zoom, KEY_DOWN_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_preview_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_preview_stop(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    mdi_video_rec_preview_stop();
    AVK_LOG_FUN(mdi_video_rec_preview_stop,AVK_PASS);

#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_start
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_start(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    U8 str_buf[VS_MM_BUFFER_SIZE];
    U8 wstr_buf[VS_MM_BUFFER_SIZE];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_video_cntx.num == 5)
    {
        result =  mdi_video_rec_record_start((S8*) L"Y:\\error.avi", vs_mm_video_misc_rec_result_hdlr,NULL);   
        AVK_LOG_FUN(mdi_video_rec_record_start,AVK_PASS);

        if (result != MDI_RES_VDOREC_SUCCEED)
        {
            mdi_video_rec_record_stop();
            mdi_video_rec_preview_stop();
            mdi_video_rec_power_off();

            AVK_LOG_FUN(mdi_video_rec_record_stop,AVK_PASS);
            AVK_LOG_FUN(mdi_video_rec_preview_stop,AVK_PASS);
            AVK_LOG_FUN(mdi_video_rec_power_off,AVK_PASS);

            gdi_layer_resize(UI_device_width, UI_device_height);
            gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, 0, 0, 0);

            gui_set_text_color(gui_color(128, 0, 255));
            gdi_draw_solid_rect(5, 70, 220, 98, GDI_COLOR_WHITE);
            gui_move_text_cursor(5, 70);
            sprintf((PS8) str_buf, (PS8) "%d", (U16) (result));
            mmi_asc_to_wcs((U16*) wstr_buf, (PS8) str_buf);
            gui_print_text((UI_string_type) wstr_buf );            
            gdi_layer_blt_previous(5, 70, 200, 98);

            return;
        }
    }

#ifndef VS_MM_AVI_SUPPORT
    vs_mm_video_misc_play_file_setting_save();
#endif 

    FS_Delete((PU16) g_vs_mm_video_cntx.vdo_file);

    result = mdi_video_rec_record_start((S8*) g_vs_mm_video_cntx.vdo_file, vs_mm_video_misc_rec_result_hdlr,NULL);
    kal_prompt_trace(MOD_IDLE,"record start ret = %d",result);

    vs_mm_video_misc_draw_rec_time();
    vs_mm_video_misc_draw_rec_size();
    /* vs_mm_video_misc_draw_rec_state(); */

    gui_start_timer(1000, vs_mm_video_misc_time_and_size_cnt);
#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_stop(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(vs_mm_video_misc_time_and_size_cnt);
    mdi_video_rec_record_stop();

    AVK_LOG_FUN(mdi_video_rec_record_stop,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_pause
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_pause(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_rec_record_pause(KAL_TRUE);

    AVK_LOG_FUN(mdi_video_rec_record_pause,AVK_PASS);
    gui_cancel_timer(vs_mm_video_misc_time_and_size_cnt);
    SetKeyHandler(vs_mm_video_005_rec_resume, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_resume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_resume(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_rec_record_resume();

    AVK_LOG_FUN(mdi_video_rec_record_resume,AVK_PASS);
    gui_start_timer(1000, vs_mm_video_misc_time_and_size_cnt);
    SetKeyHandler(vs_mm_video_005_rec_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_cancel_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_cancel_save(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_rec_stop_save();

    AVK_LOG_FUN(mdi_video_rec_stop_save,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_save(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_rec_stop();
    vs_mm_video_005_preview_stop();

    SetKeyHandler(vs_mm_video_005_rec_cancel_save, KEY_LEFT_ARROW, KEY_EVENT_UP);

#ifndef VS_MM_AVI_SUPPORT
    vs_mm_video_misc_play_file_setting_save();
#endif 

    result = mdi_video_rec_save_file((PS8) g_vs_mm_video_cntx.vdo_file, vs_mm_video_misc_rec_save_result_hdlr,NULL);
    AVK_LOG_FUN(mdi_video_rec_save_file,AVK_PASS);

    kal_prompt_trace(MOD_IDLE,"rec_save_file ret = %d",result);
#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_is_recording
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_is_recording(void)
{
#if defined(__MMI_VIDEO_RECORDER__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.play_ptr, 0, VS_MM_BUFFER_SIZE*2);

    if (mdi_video_is_recording())
    {
        mmi_wcscpy( (WCHAR *)g_vs_mm_video_cntx.rec_is_ptr,  (WCHAR *)L"state: record");
    }
    else
    {
        mmi_wcscpy( (WCHAR *)g_vs_mm_video_cntx.rec_is_ptr,  (WCHAR *)L"state: idle");
    }

    AVK_LOG_FUN(mdi_video_is_recording,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_get_record_file_size
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_get_record_file_size(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.rec_size_ptr, 0, VS_MM_BUFFER_SIZE*2);
    memset(str_buf, 0, VS_MM_BUFFER_SIZE);

    sprintf((PS8) str_buf, (PS8) "size: %d kb", (U16) (mdi_video_rec_get_record_file_size() / 1000));

    mmi_asc_to_wcs( g_vs_mm_video_cntx.rec_size_ptr, (PS8) str_buf);

    AVK_LOG_FUN(mdi_video_rec_get_record_file_size,AVK_PASS);

#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_get_max_zoom
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_get_max_zoom(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.rec_zoom_ptr, 0, VS_MM_BUFFER_SIZE*2);
    memset(str_buf, 0, VS_MM_BUFFER_SIZE);

    sprintf(
        (PS8) str_buf,
        (PS8) "zoom: %d",
        mdi_video_rec_get_max_zoom_factor(g_vs_mm_video_cntx.normal_width, g_vs_mm_video_cntx.normal_height));

    mmi_asc_to_wcs( g_vs_mm_video_cntx.rec_zoom_ptr, (PS8) str_buf);

    AVK_LOG_FUN(mdi_video_rec_get_max_zoom_factor,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_get_curr_time
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_get_curr_time(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_buf[VS_MM_BUFFER_SIZE];
    U64 rec_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.rec_time_ptr, 0, VS_MM_BUFFER_SIZE*2);
    memset(str_buf, 0, VS_MM_BUFFER_SIZE);
    mdi_video_rec_get_cur_record_time(&rec_time);

    sprintf((PS8) str_buf, (PS8) "time: %d sec", (U16) (rec_time / 1000));

    mmi_asc_to_wcs( g_vs_mm_video_cntx.rec_time_ptr, (PS8) str_buf);

    AVK_LOG_FUN(mdi_video_rec_get_cur_record_time,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_update_blt_pause
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_update_blt_pause(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_rec_update_blt_pause();

    AVK_LOG_FUN(mdi_video_rec_update_blt_pause,AVK_PASS);


    SetKeyHandler(vs_mm_video_005_rec_update_blt_resume, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_update_blt_resume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_update_blt_resume(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_video_rec_update_blt_resume(
        g_vs_mm_video_cntx.play_layer_handle,
        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
        GDI_LAYER_ENABLE_LAYER_1,
        MMI_TRUE);

    AVK_LOG_FUN(mdi_video_rec_update_blt_resume,AVK_PASS);


    SetKeyHandler(vs_mm_video_005_rec_update_blt_pause, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_update_para_ev
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_update_para_ev(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_video_cntx.para_ev < VS_MM_VIDEO_SETTING_EV_COUNT - 1)
    {
        g_vs_mm_video_cntx.para_ev++;
    }
    else
    {
        g_vs_mm_video_cntx.para_ev = 0;
    }

    mdi_video_rec_update_para_ev(g_vs_mm_video_cntx.para_ev);

    AVK_LOG_FUN(mdi_video_rec_update_para_ev,AVK_PASS);
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_update_para_zoom
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_update_para_zoom(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //#ifndef MT6238
    if (g_vs_mm_video_cntx.para_zoom < 20)
    {
        g_vs_mm_video_cntx.para_zoom = g_vs_mm_video_cntx.para_zoom + 2;
    }
    else
    {
        g_vs_mm_video_cntx.para_zoom = 10;
    }
    mdi_video_rec_update_para_zoom(g_vs_mm_video_cntx.para_zoom);

    AVK_LOG_FUN(mdi_video_rec_update_para_zoom,AVK_PASS);
#endif
}





/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_play_file_setting_save
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_play_file_setting_save(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR vr3gp[] = {'v','d','o','r','e','c','.','3','g','p','\0'};
    WCHAR vrmp4[] = {'v','d','o','r','e','c','.','m','p','4','\0'};
    WCHAR vmp4[] = {'v','i','d','e','o','.','m','p','4','\0'};
#ifdef __MTK_TARGET__
    WCHAR v3gp[] = {'v','i','d','e','o','.','3','g','p','\0'};
#else
    WCHAR v3gp[] = {'v','i','d','e','o','.','m','p','g','\0'};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vs_mm_video_cntx.filepath, 0, sizeof(g_vs_mm_video_cntx.filepath));
    memset(g_vs_mm_video_cntx.vdo_file, 0, sizeof(g_vs_mm_video_cntx.vdo_file));

    switch (g_vs_mm_video_cntx.sub_type)
    {
    case 1:
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.vdo_file, vr3gp);
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.filepath, v3gp);
        g_vs_mm_video_cntx.play_id = VDO_ID_VS_MM_3GP_PLAY;
        break;
    case 2:
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.vdo_file, vrmp4);
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.filepath, vmp4);
        g_vs_mm_video_cntx.play_id = VDO_ID_VS_MM_MP4_PLAY;
        break;
    default:
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.vdo_file, vr3gp);
        vs_mm_video_misc_get_file_path(g_vs_mm_video_cntx.filepath, v3gp);
        g_vs_mm_video_cntx.play_id = VDO_ID_VS_MM_3GP_PLAY;
        break;
    }
    return;

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_get_file_path
* DESCRIPTION
*  
* PARAMETERS
*  path        [?]
*  file        [?]
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_get_file_path(U16 *path, U16 *file)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[VS_MM_BUFFER_SIZE];

    WCHAR  fmgrvideo[] = {'V','i','d','e','o','\\','\0'}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fileBuf, 0, VS_MM_BUFFER_SIZE);
    memset(path, 0, VS_MM_BUFFER_SIZE);

    mmi_wcscat((U16*) path, (U16*) AVK_TEST_FILE_PATH);
    mmi_wcscat((U16*) path, (U16*) L"avk_mm_video\\");
    mmi_wcscat((U16*) path, (U16*) file);


}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_screen
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dis_str[VS_MM_BUFFER_SIZE];
    U8 dis_buf[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_str, 0, VS_MM_BUFFER_SIZE);

    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);

    switch (g_vs_mm_video_cntx.num)
    {
    case 0:
        gui_print_text((UI_string_type) L"play video file");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        sprintf((PS8) dis_buf, (PS8) "total time: %d sec", (U16) (g_vs_mm_video_cntx.total_time / 1000));
        mmi_asc_to_wcs( g_vs_mm_video_cntx.total_time_str, (PS8) dis_buf);
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"volume: 50");
        gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.total_time_str);
        break;
    case 1:
        gui_print_text((UI_string_type) L"play video clip");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        sprintf((PS8) dis_buf, (PS8) "total time: %d sec", (U16) (g_vs_mm_video_cntx.total_time / 1000));
        mmi_asc_to_wcs( g_vs_mm_video_cntx.total_time_str, (PS8) dis_buf);
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"volume: 50");
        gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.total_time_str);
        break;
    case 2:
        gui_print_text((UI_string_type) L"play video id");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        sprintf((PS8) dis_buf, (PS8) "total time: %d sec", (U16) (g_vs_mm_video_cntx.total_time / 1000));
        mmi_asc_to_wcs( g_vs_mm_video_cntx.total_time_str, (PS8) dis_buf);
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"volume: 50");
        gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.total_time_str);
        break;
    case 3:
        gui_print_text((UI_string_type) L"play video buffer");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        sprintf((PS8) dis_buf, (PS8) "total time: %d sec", (U16) (g_vs_mm_video_cntx.total_time / 1000));
        mmi_asc_to_wcs(g_vs_mm_video_cntx.total_time_str, (PS8) dis_buf);
        gui_move_text_cursor(5, 70);
        gui_print_bordered_text((UI_string_type) L"volume: 50");
        gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);
        gui_move_text_cursor(5, 100);
        gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.total_time_str);
        break;
    case 4:
        gui_print_text((UI_string_type) L"record video");
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));

        gui_move_text_cursor(5, 70);

        if (g_vs_mm_video_cntx.file_option == 1)
        {
            gui_print_bordered_text((UI_string_type) L"type: mp4");
        }
        else if (g_vs_mm_video_cntx.file_option == 0)
        {
            gui_print_bordered_text((UI_string_type) L"type: 3gp");
        }
        else
        {
            gui_print_bordered_text((UI_string_type) L"type: avi");
        }
        break;
    default:
        break;
    }

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_open_done_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result          [IN]        
*  vdo_clip        [?]
* RETURNS
*  void
*****************************************************************************/
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

void vs_mm_video_misc_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip,void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (result >= 0)
    {
        U32 blt_layer;
        U32 play_layer;
        blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
        play_layer = (GDI_LAYER_ENABLE_LAYER_1);
        g_vs_mm_video_cntx.offset_x = 30;       /* (MMI_content_width - vdo_clip->width) >> 1; */
        g_vs_mm_video_cntx.offset_y = 150;      /* (MMI_content_height - vdo_clip->height) >> 1; */
        g_vs_mm_video_cntx.normal_width = 176;  /* vdo_clip->width; */
        g_vs_mm_video_cntx.normal_height = 144; /* vdo_clip->height; */

        gdi_layer_create(
            g_vs_mm_video_cntx.offset_x,
            g_vs_mm_video_cntx.offset_y,
            g_vs_mm_video_cntx.normal_width,
            g_vs_mm_video_cntx.normal_height,
            &g_vs_mm_video_cntx.play_layer_handle);

        g_vs_mm_video_cntx.play_time = 0;
        g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_OPEN;
        g_vs_mm_video_cntx.total_time = vdo_clip->total_time_duration;
        g_vs_mm_video_cntx.audio_level = 0;
        g_vs_mm_video_cntx.brightness = 5;
        g_vs_mm_video_cntx.lcm_update = TRUE;

        /* vs_mm_video_misc_draw_play_state(); */
        vs_mm_video_misc_draw_screen();

        gdi_layer_get_base_handle(&g_vs_mm_video_cntx.osd_layer_handle);
        gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, g_vs_mm_video_cntx.play_layer_handle, 0, 0);

        ret = mdi_video_ply_seek_and_get_frame(g_vs_mm_video_cntx.play_time, g_vs_mm_video_cntx.play_layer_handle);
        AVK_LOG_FUN(mdi_video_ply_seek_and_get_frame,AVK_PASS);

            #ifdef VIDEO_UNIT_TEST
    ret = MDI_RES_VDOPLY_SUCCEED;
    #endif
        if (ret != MDI_RES_VDOPLY_SUCCEED)
        {
            mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY);
        }

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);


        mdi_video_ply_enable_partial_display();

        AVK_LOG_FUN(mdi_video_ply_enable_partial_display,AVK_PASS);

    ret = mdi_video_ply_play(
        g_vs_mm_video_cntx.play_layer_handle,   /* play layer handle */
        blt_layer,                              /* blt layer */
        play_layer,                             /* play_layer_flag */
        1,                                      /* repeat */
        TRUE,                                   /* visual update */
        TRUE,                                   /* play aud */
        MDI_DEVICE_SPEAKER2,                    /* audio path */
        0,                                      /* rotate */
        100,                                    /* speed factor */
        vs_mm_video_misc_play_finish_hdlr,
        NULL);   
    
    AVK_LOG_FUN(mdi_video_ply_play,AVK_PASS);
        #ifdef VIDEO_UNIT_TEST
    ret = MDI_RES_VDOPLY_SUCCEED;
    #endif
    if (ret >= MDI_RES_VDOPLY_SUCCEED)
    {
        g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_PLAY;

    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }

        //AVK_SET_PASSKEY(vs_mm_video_misc_pass);
        SetLeftSoftkeyFunction(vs_mm_video_misc_pass, KEY_EVENT_UP);
        SetRightSoftkeyFunction(vs_mm_video_misc_fail, KEY_EVENT_UP);


        AVK_LOG_FUN(mdi_video_ply_play,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_set_brightness,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_set_stop_time,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_set_audio_level,AVK_PASS);

        SetKeyHandler(vs_mm_video_001_set_brightness, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(vs_mm_video_001_set_stop_time, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(vs_mm_video_001_set_audio_level, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(vs_mm_video_001_pause, KEY_LEFT_ARROW, KEY_EVENT_UP);

    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }

}
#endif


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_play_finish_hdlr
* DESCRIPTION
*  called when the file play end
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_play_finish_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_001_close_file();

    return;
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_file_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_file_screen_exit(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vs_mm_video_cntx.play_layer_handle != 0)
    {
        if (g_vs_mm_video_cntx.state == VS_MM_VIDEO_STATE_PLAY || g_vs_mm_video_cntx.state == VS_MM_VIDEO_STATE_PAUSE)
        {
            vs_mm_video_001_stop();
            g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_OPEN;
        }
        if (g_vs_mm_video_cntx.state == VS_MM_VIDEO_STATE_OPEN)
        {
            vs_mm_video_001_close_file();
        }

        gdi_layer_free(g_vs_mm_video_cntx.play_layer_handle);
        g_vs_mm_video_cntx.play_layer_handle = 0;

        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, 0, 0, 0);

    }

    return;
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_seek_result
* DESCRIPTION
*  
* PARAMETERS
*  mdi_res     [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_seek_result(MDI_RESULT mdi_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_res >= MDI_RES_VDOPLY_SUCCEED)
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}

/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_record_file_screen_exit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_record_file_screen_exit(void)
{
#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_rec_stop();
    vs_mm_video_005_preview_stop();

    mdi_video_rec_power_off();
    AVK_LOG_FUN(mdi_video_rec_power_off,AVK_PASS);


    if (g_vs_mm_video_cntx.play_layer_handle != 0)
    {
        gdi_layer_free(g_vs_mm_video_cntx.play_layer_handle);
        g_vs_mm_video_cntx.play_layer_handle = 0;

        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_set_blt_layer(g_vs_mm_video_cntx.osd_layer_handle, 0, 0, 0);

    }

    return;
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_rec_result_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_rec_result_hdlr(MDI_RESULT result, void* user_data)
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
*  vs_mm_video_misc_rec_save_result_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_rec_save_result_hdlr(MDI_RESULT result,void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dis_buf[VS_MM_BUFFER_SIZE];
    U8 dis_tem[VS_MM_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dis_buf, 0, VS_MM_BUFFER_SIZE);
    memset(dis_tem, 0, VS_MM_BUFFER_SIZE);
    sprintf((PS8) dis_buf, (PS8) "error code: %d ", result);
    mmi_asc_to_wcs((U16*) dis_tem, (PS8) dis_buf);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
    case MDI_RES_VDOREC_ERR_DISK_FULL:
        //      mmi_popup_display_simple( L"MDI_RES_VDOREC_ERR_DISK_FULL", MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
        break;

    case MDI_RES_VDOREC_ERR_NO_DISK:
        //      mmi_popup_display_simple( L"MDI_RES_VDOREC_ERR_NO_DISK", MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
        break;

    case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
        //      mmi_popup_display_simple(L"MDI_RES_VDOREC_ERR_WRITE_PROTECTION",MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
        break;

        /* followings are serious error, has to exit app */
    case MDI_RES_VDOREC_ERR_HW_NOT_READY:
    case MDI_RES_VDOREC_ERR_POWER_ON_FAILED:
        //      mmi_popup_display_simple(L"MDI_RES_VDOREC_ERR_HW_NOT_READY",MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
        mmi_frm_scrn_close_active_id();
        break;

    case MDI_RES_VDOREC_ERR_PREVIEW_FAILED:
    case MDI_RES_VDOREC_ERR_RESUME_FAILED:
    case MDI_RES_VDOREC_ERR_PAUSE_FAILED:
    case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
    case MDI_RES_VDOREC_ERR_RECORD_FAILED:
        //      mmi_popup_display_simple(L"MDI_RES_VDOREC_ERR_PREVIEW_FAILED",MMI_EVENT_FAILURE, GRP_ID_AVK, NULL);
        mmi_frm_scrn_close_active_id();
        break;

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        /* error of open saved video file  */
    case MDI_RES_VDOPLY_ERR_FAILED:
    case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
    case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
    case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
    case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
    case MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT:
    case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:
    case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
    case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
        mmi_popup_display_simple( L"MDI_RES_VDOPLY_ERR_FAILED", MMI_EVENT_WARNING, GRP_ID_AVK, NULL);
        break;
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */ 

    default:
        break;
    }

}

/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_rec_time
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_rec_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_get_curr_time();

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 70, 220, 98, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 70);
    gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.rec_time_ptr);
    gdi_layer_blt_previous(5, 70, 220, 98);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_rec_size
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_rec_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_get_record_file_size();
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 100, 220, 128, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 100);
    gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.rec_size_ptr);
    gdi_layer_blt_previous(5, 100, 220, 128);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_rec_zoom
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_rec_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_get_max_zoom();


}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_rec_state
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_rec_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_005_is_recording();

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 340, 220, 368, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 340);
    gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.rec_is_ptr);
    gdi_layer_blt_previous(5, 340, 220, 368);
}
//#endif

/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_draw_play_state
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_draw_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vs_mm_video_001_is_playing();

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_draw_solid_rect(5, 280, 220, 308, GDI_COLOR_WHITE);
    gui_move_text_cursor(5, 280);
    gui_print_bordered_text((UI_string_type) g_vs_mm_video_cntx.play_ptr);
    gdi_layer_blt_previous(5, 280, 220, 308);
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_time_and_size_cnt
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_time_and_size_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
    vs_mm_video_misc_draw_rec_time();
    vs_mm_video_misc_draw_rec_size();
    gui_start_timer(1000, vs_mm_video_misc_time_and_size_cnt);
#endif

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_noblock_seek_result_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_noblock_seek_result_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= MDI_RES_VDOPLY_SUCCEED)
    {

    }
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_pass
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE,"video pass: num = %d,count = %d",g_vs_mm_video_cntx.num,g_vs_mm_video_cntx.count);
    switch (g_vs_mm_video_cntx.num)
    {
    case 0:

    case 1:
        case 2:




    case 3:
            vs_mm_video_misc_file_screen_exit();

            GoBackHistory();
            AVK_ASYN_DONE();


            break;

        

    case 4:
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
        switch (g_vs_mm_video_cntx.count)
        {
        case 1:
            vs_mm_video_005_rec_start();
            g_vs_mm_video_cntx.count++;
            break;
        case 2:
            vs_mm_video_005_rec_save();
            g_vs_mm_video_cntx.count++;

            break;
        case 3:


            g_vs_mm_video_cntx.count = 1;
            g_vs_mm_video_cntx.sub_type = 1;
            vs_mm_video_misc_file_screen_exit();
            GoBackHistory();
            AVK_ASYN_DONE();

            break;
        default:
            break;
        }
#endif
        break;

    default:
        break;
    }

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_misc_fail
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_misc_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        kal_prompt_trace(MOD_IDLE,"video pass: num = %d,count = %d",g_vs_mm_video_cntx.num,g_vs_mm_video_cntx.count);
    switch (g_vs_mm_video_cntx.num)
    {
    case 0:
        case 1:
        case 2:







    case 3:
            vs_mm_video_misc_file_screen_exit();

            GoBackHistory();
            AVK_ASYN_DONE();

            break;
    
            
    
    case 4:
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)

        switch (g_vs_mm_video_cntx.count)
        {
        case 1:
            vs_mm_video_005_rec_start();
            g_vs_mm_video_cntx.count++;
            break;
        case 2:
            vs_mm_video_005_rec_save();
            g_vs_mm_video_cntx.count++;

            break;
        case 3:
    
    
                g_vs_mm_video_cntx.count = 1;
                g_vs_mm_video_cntx.sub_type = 1;
                vs_mm_video_misc_file_screen_exit();
                GoBackHistory();
                AVK_ASYN_DONE();

            break;

        default:
            break;
        }
#endif
        break;



        default:
            break;
        }
    
    }







/*****************************************************************************
* FUNCTION
*  vs_mm_misc_init_video
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_misc_init_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    WCHAR vr3gp[] = {'v','d','o','r','e','c','.','3','g','p','\0'};
    WCHAR vrmp4[] = {'v','d','o','r','e','c','.','m','p','4','\0'};
    WCHAR vmp4[] = {'v','i','d','e','o','.','m','p','4','\0'};
    WCHAR v3gp[] = {'v','i','d','e','o','.','3','g','p','\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.index = 0;
    g_vs_mm_video_cntx.num = 0;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.sub_type = 1;
    g_vs_mm_video_cntx.re_enter = FALSE;
#ifndef MT6238
    g_vs_mm_video_cntx.para_zoom = 10;
#else
    g_vs_mm_video_cntx.para_zoom = 0;
#endif

#ifdef __MMI_VIDEO_PLAY_SUPPORT__

    vs_mm_video_misc_play_file_setting_save();

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_option_highlight_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.index = index;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.sub_type = 1;
    g_vs_mm_video_cntx.re_enter = FALSE;

    item_text = get_item_text(index);

}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_entry_scr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nitems;
    U16 itemlist[9];
    int item = 0;
    U8 *guiBuffer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO, NULL, vs_mm_video_entry_scr, MMI_FRM_FULL_SCRN);
    RegisterHighlightHandler(vs_mm_video_option_highlight_hdlr);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    nitems = GetNumOfChild_Ext(MENU_ID_VS_MM_VIDEO);

    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_001 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_002 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_003 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_004 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_005 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_006 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_007 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_VIDEO_008 ;
    itemlist[item++] = (U16) STR_ID_VS_MM_TEST_ALL ;

    ShowCategory15Screen(
        STR_ID_VS_MM_VIDEO,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nitems,
        itemlist,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    return;
}

/*****************************************************************************
* FUNCTION
*  vs_mm_video_001_open_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_001_open_file(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_IDLE;
    g_vs_mm_video_cntx.type = VS_MM_VIDEO_TYPE_FILE;
    g_vs_mm_video_cntx.play_layer_handle = 0;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.num = 0;



    mmi_frm_scrn_enter(
        GRP_ID_AVK,
        SCR_ID_VS_MM_VIDEO_001_FILE_PLAY,
        vs_mm_video_misc_file_screen_exit,
        vs_mm_video_001_open_file,
        MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);


#ifndef VS_MM_AVI_SUPPORT

    vs_mm_video_misc_play_file_setting_save();

    ret = mdi_video_ply_check_is_able_to_play(NULL);

    AVK_LOG_FUN(mdi_video_ply_check_is_able_to_play,AVK_PASS);

    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mmi_popup_display_simple((WCHAR*)L"can't play, please check the file", MMI_EVENT_ERROR, GRP_ID_AVK, NULL);

        mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_001_FILE_PLAY);

        return;
    }
#endif /* VS_MM_AVI_SUPPORT */
//    mdi_video_set_sleep_time(10, 5);
//  AVK_LOG_FUN(mdi_video_set_sleep_time,AVK_PASS);

//  mdi_video_restore_sleep_time();
//  AVK_LOG_FUN(mdi_video_restore_sleep_time,AVK_PASS);
#if 0
/* under construction !*/
/* under construction !*/
#endif

    //To do clear cache for asm insufficient sometimes 
	applib_mem_ap_free_all_cache();

    ret = mdi_video_ply_open_file( ASM_ANONYMOUS_ID,(PS8) g_vs_mm_video_cntx.filepath, vs_mm_video_misc_open_done_hdlr,NULL);
    AVK_LOG_FUN(mdi_video_ply_open_file,AVK_PASS);

    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {   
        AVK_LOG_FUN(mdi_video_ply_is_drm_file,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_drm_disable_consume_count,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_drm_disable_consume_time,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_drm_disable_time_limit_stop,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_get_total_duration,AVK_PASS);

#ifdef __DRM_SUPPORT__
        if(mdi_video_ply_is_drm_file())
        {
            mdi_video_ply_drm_disable_consume_count();
            mdi_video_ply_drm_disable_consume_time();
            mdi_video_ply_drm_disable_time_limit_stop();
        }
#endif
    }
    else
    {
        mmi_popup_display_simple( g_vs_mm_video_cntx.filepath, MMI_EVENT_WARNING, GRP_ID_AVK, NULL);
        mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_001_FILE_PLAY);
    }

#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_002_open_clip
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_002_open_clip(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_IDLE;
    g_vs_mm_video_cntx.play_layer_handle = 0;
    g_vs_mm_video_cntx.type = VS_MM_VIDEO_TYPE_FILE_CLIP;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.num = 1;


    mmi_frm_scrn_enter(GRP_ID_AVK, 
        SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY,
        vs_mm_video_misc_file_screen_exit,
        vs_mm_video_002_open_clip,
        MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);


#ifndef VS_MM_AVI_SUPPORT
    vs_mm_video_misc_play_file_setting_save();
#endif 

    mdi_video_ply_enable_aud_only_video_clip();
    AVK_LOG_FUN(mdi_video_ply_enable_aud_only_video_clip,AVK_PASS);
    //To do clear cache for asm insufficient sometimes 
	applib_mem_ap_free_all_cache();
	
    ret = mdi_video_ply_open_clip_file(ASM_ANONYMOUS_ID, (PS8) g_vs_mm_video_cntx.filepath, &vdo_clip);
    AVK_LOG_FUN(mdi_video_ply_open_clip_file,AVK_PASS);

    #ifdef VIDEO_UNIT_TEST
    ret = MDI_RES_VDOPLY_SUCCEED;
    #endif
    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        vs_mm_video_misc_open_done_hdlr(MDI_RES_VDOPLY_SUCCEED, &vdo_clip,NULL);
    }
    else
    {
        mmi_popup_display_simple( g_vs_mm_video_cntx.filepath, MMI_EVENT_WARNING, GRP_ID_AVK, NULL);

        mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY);
    }

    return;
#else
#endif
}

/*****************************************************************************
* FUNCTION
*  vs_mm_video_003_open_id
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_003_open_id(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_IDLE;
    g_vs_mm_video_cntx.play_layer_handle = 0;
    g_vs_mm_video_cntx.type = VS_MM_VIDEO_TYPE_ID_CLIP;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.num = 2;

    if (g_vs_mm_video_cntx.sub_type == 1)
    {
        mmi_frm_scrn_enter(GRP_ID_AVK, 
            SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY,
            vs_mm_video_misc_file_screen_exit,
            vs_mm_video_003_open_id,
            MMI_FRM_FULL_SCRN);
        ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);
    }

#ifndef VS_MM_AVI_SUPPORT
    vs_mm_video_misc_play_file_setting_save();
#else 
    g_vs_mm_video_cntx.play_id = VDO_ID_VS_MM_AVI_PLAY;
#endif 
    //To do clear cache for asm insufficient sometimes 
	applib_mem_ap_free_all_cache();

    ret = mdi_video_ply_open_clip_id(ASM_ANONYMOUS_ID, g_vs_mm_video_cntx.play_id, &vdo_clip);
    AVK_LOG_FUN(mdi_video_ply_open_clip_id,AVK_PASS);


    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        /* write log */
        vs_mm_video_misc_open_done_hdlr(MDI_RES_VDOPLY_SUCCEED, &vdo_clip,NULL);
    }
    else
    {
        //      mmi_popup_display_simple( L"open id error, please check the id", MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
        mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY);
    }

#else
#endif
}


/*****************************************************************************
* FUNCTION
*  vs_mm_video_004_open_buffer
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_004_open_buffer(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_video_info_struct vdo_clip;
    kal_uint32 buffer_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.state = VS_MM_VIDEO_STATE_IDLE;
    g_vs_mm_video_cntx.play_layer_handle = 0;
    g_vs_mm_video_cntx.type = VS_MM_VIDEO_TYPE_BUFFER_CLIP;
    g_vs_mm_video_cntx.count = 1;
    g_vs_mm_video_cntx.num = 3;
    kal_prompt_trace(MOD_IDLE,"open buffer sub_type = %d",g_vs_mm_video_cntx.sub_type);


    mmi_frm_scrn_enter(GRP_ID_AVK, 
        SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY,
        vs_mm_video_misc_file_screen_exit,
        vs_mm_video_004_open_buffer,
        MMI_FRM_FULL_SCRN);
    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);


    vs_mm_video_misc_play_file_setting_save();
	//To do clear cache for asm insufficient sometimes 
	applib_mem_ap_free_all_cache();
    if (g_vs_mm_video_cntx.play_id == VDO_ID_VS_MM_MP4_PLAY)
    {
        buffer_length = sizeof(g_vs_video_mp4_buffer);
        ret = mdi_video_ply_open_clip_buffer(ASM_ANONYMOUS_ID, (PU8) g_vs_video_mp4_buffer, buffer_length, &vdo_clip);

    }
    else
    {

        buffer_length = sizeof(g_vs_video_3gp_buffer);
        ret = mdi_video_ply_open_clip_buffer(ASM_ANONYMOUS_ID, (PU8) g_vs_video_3gp_buffer, buffer_length, &vdo_clip);

    }
    AVK_LOG_FUN(mdi_video_ply_open_clip_buffer,AVK_PASS);
 
    if (ret >= MDI_RES_VDOPLY_SUCCEED)
    {
        vs_mm_video_misc_open_done_hdlr(MDI_RES_VDOPLY_SUCCEED, &vdo_clip,NULL);
    }
    else
    {

        mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY);
    }

#else
#endif
}




/*****************************************************************************
* FUNCTION
*  vs_mm_video_005_rec_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_005_rec_file(void)
{
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vs_mm_video_cntx.num = 4;

    mmi_frm_scrn_enter(GRP_ID_AVK, 
        SCR_ID_VS_MM_VIDEO_001_FILE_PLAY,
        vs_mm_video_misc_record_file_screen_exit,
        vs_mm_video_005_rec_file,
        MMI_FRM_FULL_SCRN);

#ifndef VS_MM_AVI_SUPPORT
    vs_mm_video_misc_play_file_setting_save();
#endif 

    ShowCategory227Screen(0, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, NULL, NULL);


    gui_set_text_color(gui_color(128, 0, 255));
    gui_move_text_cursor(5, 40);
    gui_print_text((UI_string_type) L"video record");
    gdi_layer_blt_previous(5, 40, 200, 68);


    if (!g_vs_mm_video_cntx.re_enter)
    {
        g_vs_mm_video_cntx.re_enter = TRUE;

        ret = mdi_video_rec_power_on(ASM_ANONYMOUS_ID);
        
        AVK_LOG_FUN(mdi_video_rec_power_on,AVK_PASS);


        if (ret == MDI_RES_VDOREC_SUCCEED)
        {
            vs_mm_video_005_preview();
        }
        else
        {
            //mmi_popup_display_simple(L"power on error, please check the file",MMI_EVENT_ERROR, GRP_ID_AVK, NULL);
            mmi_frm_scrn_close(GRP_ID_AVK, SCR_ID_VS_MM_VIDEO_001_FILE_PLAY);
        }
    }
#else
#endif
}

/*****************************************************************************
* FUNCTION
*  vs_mm_video_006_rec_file_error
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_006_rec_file_error(void)
{

}








#ifdef __MMI_VIDEO_STREAM__
#define CJL_MDI_STREAM_INIT_FAIL 0
#define CJL_MDI_STREAM_CONNECT_FAIL 1
#define CJL_MDI_STREAM_BUFFER_FAIL 2
#define CJL_MDI_STREAM_PLAY_FAIL 3
#define CJL_MDI_STREAM_DISCONNECT_FAIL 4
#define CJL_MDI_STREAM_DEINIT_FAIL 5

#define CJL_MDI_STREAM_CONNECT_CB_RET_FAIL 6
#define CJL_MDI_STREAM_BUFFER_CB_RET_FAIL 7
#define CJL_MDI_STREAM_FINISH_CB_RET_FAIL 8



typedef struct
{

    gdi_handle play_layer_handle;
    gdi_handle osd_layer_handle;
    U64 play_time;
    S32 offset_x;
    S32 offset_y;
    S32 normal_width;
    S32 normal_height;
    U16 stream_url[2*128];
    U8 aud_channel_no;
    U16 aud_sample_rate;
    MMI_BOOL m_bIsConnect;
    MMI_BOOL m_bIsBuffering;
    MMI_BOOL m_bIsPlaying;
}vs_mm_video_stream_context;

vs_mm_video_stream_context g_vs_mm_video_stream_context;

static  void vs_mm_video_stream_buffering_result_callback(S32 ret, mdi_video_info_struct* video_info,void* user_data);
static void vs_mm_video_stream_get_buf_percentage_timer_cb(void);
static void vs_mm_video_stream_play_finish_callback (S32 ret,void *user_data);
static void vs_mm_video_stream_connect_result_callback(S32 ret, mdi_video_info_struct* video_info,void* user_data);
static void vs_mm_video_stream_init();
static U32 vs_mm_video_stream_get_account();
static void vs_mm_video_stream_pass(void);
static void vs_mm_video_stream_fail(void);



static U32 vs_mm_video_stream_get_account()
{
    cbm_app_info_struct app_info;
    U8 app_id;
    U32 ret;

    app_info.app_icon_id = IMG_ID_VS_MM_MAIN;
    app_info.app_str_id = STR_ID_VS_MM_MAIN;
    app_info.app_type = 0x0800;


    cbm_register_app_id_with_app_info(&app_info, &app_id);
    kal_prompt_trace(MOD_IDLE,"app_id is %d", app_id);

    ret = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID,(cbm_sim_id_enum)0,app_id,(kal_bool)0);

    if (ret == CBM_INVALID_ACCT_ID)
    {
        kal_prompt_trace(MOD_IDLE,"CBM_INVALID_ACCT_ID");

    }
    cbm_deregister_app_id(app_id);
    return ret;
}


static void vs_mm_video_stream_init()
{
    memset(g_vs_mm_video_stream_context.stream_url,0,sizeof(g_vs_mm_video_stream_context.stream_url));
    mmi_asc_to_wcs(g_vs_mm_video_stream_context.stream_url,"rtsp://218.249.47.121:554/H264/pure_video/176x144-avc-10fsp-44.1kbps.3gp");
    g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
    g_vs_mm_video_stream_context.m_bIsBuffering = MMI_FALSE;    
    g_vs_mm_video_stream_context.m_bIsPlaying = MMI_FALSE;
}

static void vs_mm_video_stream_get_buf_percentage_timer_cb(void)
{
    S32 percentage;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_IDLE,"get percent cb");
    ret = mdi_video_stream_get_buf_percentage(&percentage);
    AVK_LOG_FUN(mdi_video_stream_get_buf_percentage,AVK_PASS);

    if (percentage>= 100)
    {
        gui_cancel_timer( vs_mm_video_stream_get_buf_percentage_timer_cb);
    }
    else
    {
        gui_start_timer(300,vs_mm_video_stream_get_buf_percentage_timer_cb);
    }
}

static void vs_mm_video_stream_play_finish_callback (S32 ret,void *user_data)
{
    kal_prompt_trace(MOD_IDLE,"stream finish cb: ret = %d",ret);

    {
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();

        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

        g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsBuffering= MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsPlaying= MMI_FALSE;
        if(g_vs_mm_video_stream_context.play_layer_handle != 0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }
        if(ret == MDI_RES_VDOPLY_SUCCEED)
        {
            //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_TRUE, 0, VS_TA_MM_VIDEO);
            //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
            GoBackHistory();
            AVK_ASYN_DONE();
        }
        else
        {
            //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_FINISH_CB_RET_FAIL, VS_TA_MM_VIDEO);
            //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
            GoBackHistory();
            AVK_ASYN_DONE();
        }
    }


}

static  void vs_mm_video_stream_buffering_result_callback(S32 ret, mdi_video_info_struct* video_info,void* user_data)
{
    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        U32 blt_layer;
        U32 play_layer;
        blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
        play_layer = (GDI_LAYER_ENABLE_LAYER_1);
        kal_prompt_trace(MOD_IDLE,"stream_buffer cb ret success");

        mdi_video_stream_enable_partial_display();

        mdi_video_stream_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_stream_set_contrast(MDI_VIDEO_CONTRAST_0);
        mdi_video_stream_set_audio_level(100);

        mdi_video_stream_set_track(MDI_VIDEO_TRACK_AV);



        AVK_LOG_FUN(mdi_video_stream_enable_partial_display,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_set_brightness,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_set_contrast,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_set_audio_level,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_set_track,AVK_PASS);
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        //mdi_video_set_hw_rotator(0);
        AVK_LOG_FUN(mdi_video_set_hw_rotator,AVK_PASS);
#endif
        ret = mdi_video_stream_play(
            g_vs_mm_video_stream_context.play_layer_handle, 
            blt_layer,
            play_layer, 
            MMI_TRUE, 
            MDI_DEVICE_SPEAKER_BOTH, 
            MDI_VIDEO_LCD_ROTATE_0, 
            vs_mm_video_stream_play_finish_callback,
            NULL);

        AVK_LOG_FUN(mdi_video_stream_play,AVK_PASS);

        if(ret == MDI_RES_VDOPLY_SUCCEED)
        {
            kal_prompt_trace(MOD_IDLE,"mdi_video_stream_play ret success");
            g_vs_mm_video_stream_context.m_bIsPlaying = MMI_TRUE;
        }
        else
        {
            kal_prompt_trace(MOD_IDLE,"mdi_video_stream_play ret fail");            
            gui_cancel_timer( vs_mm_video_stream_get_buf_percentage_timer_cb);
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();


            AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
            AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

            g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
            g_vs_mm_video_stream_context.m_bIsBuffering= MMI_FALSE;
            g_vs_mm_video_stream_context.m_bIsPlaying= MMI_FALSE;
            if(g_vs_mm_video_stream_context.play_layer_handle != 0)
            {
                gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
                g_vs_mm_video_stream_context.play_layer_handle = 0;
            }

            //          vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_PLAY_FAIL, VS_TA_MM_VIDEO);
            //          vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);

            GoBackHistory();
            AVK_ASYN_DONE();

        }


    }
    else
    {

        kal_prompt_trace(MOD_IDLE,"stream_buffer cb ret fail");
        gui_cancel_timer( vs_mm_video_stream_get_buf_percentage_timer_cb);
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();
        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);
        if(g_vs_mm_video_stream_context.play_layer_handle != 0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }

        GoBackHistory();
        AVK_ASYN_DONE();

        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_BUFFER_CB_RET_FAIL, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
    }
}

static void vs_mm_video_stream_connect_result_callback(S32 ret, mdi_video_info_struct* video_info,void* user_data)
{
    kal_prompt_trace(MOD_IDLE,"stream connect cb: ret = %d",ret);

    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
#ifdef __DRM_SUPPORT__
        if(mdi_video_stream_is_drm_streaming())
        {
            mdi_video_stream_drm_disable_consume_count();
            mdi_video_stream_drm_disable_consume_time();
        }
#endif

        AVK_LOG_FUN(mdi_video_stream_is_drm_streaming,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_drm_disable_consume_count,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_drm_disable_consume_time,AVK_PASS);

        mdi_video_stream_get_audio_info(&(g_vs_mm_video_stream_context.aud_channel_no),&(g_vs_mm_video_stream_context.aud_sample_rate));
        AVK_LOG_FUN(mdi_video_stream_get_audio_info,AVK_PASS);

        ret = mdi_video_stream_start_buffering(0,vs_mm_video_stream_buffering_result_callback,NULL);
        AVK_LOG_FUN(mdi_video_stream_start_buffering,AVK_PASS);

        if(ret == MDI_RES_VDOPLY_SUCCEED)
        {
            g_vs_mm_video_stream_context.m_bIsBuffering = MMI_TRUE;
            kal_prompt_trace(MOD_IDLE,"mdi_start_buffering ret success");
            gui_start_timer(300, vs_mm_video_stream_get_buf_percentage_timer_cb);
        }
        else
        {
            kal_prompt_trace(MOD_IDLE,"mdi_start_buffering ret fail");
            if(g_vs_mm_video_stream_context.play_layer_handle != 0)
            {
                gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
                g_vs_mm_video_stream_context.play_layer_handle = 0;
            }
            mdi_video_stream_disconnect();
            mdi_video_stream_deinit();
            AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
            AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);
            g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
            //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_BUFFER_FAIL, VS_TA_MM_VIDEO);
            //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
            GoBackHistory();
            AVK_ASYN_DONE();
        }
    }
    else
    {

        kal_prompt_trace(MOD_IDLE,"stream connect cb ret failed");
        mdi_video_stream_deinit();
        if(g_vs_mm_video_stream_context.play_layer_handle != 0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }

        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_BUFFER_CB_RET_FAIL, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
        GoBackHistory();
        AVK_ASYN_DONE();

    }
}



/*****************************************************************************
* FUNCTION
*  vs_mm_video_stream_play
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_stream_play(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_BOOL b = mmi_frm_scrn_enter(
        GRP_ID_AVK,
        SCR_ID_VS_MM_VIDEO_011,
        NULL,
        vs_mm_video_stream_play,
        MMI_FRM_FULL_SCRN);

    if(b == MMI_TRUE)
    {
        kal_prompt_trace(MOD_IDLE,"mmi_frm_scrn_enter success");
    }
    else
    {
        kal_prompt_trace(MOD_IDLE,"mmi_frm_scrn_enter fail");
    }

    ShowCategory227Screen(0, 0, STR_GLOBAL_YES, 0, STR_GLOBAL_NO, 0, NULL, NULL);
    SetLeftSoftkeyFunction(vs_mm_video_stream_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_video_stream_fail, KEY_EVENT_UP);

    g_vs_mm_video_stream_context.offset_x = 30;       /* (MMI_content_width - vdo_clip->width) >> 1; */
    g_vs_mm_video_stream_context.offset_y = 150;      /* (MMI_content_height - vdo_clip->height) >> 1; */
    g_vs_mm_video_stream_context.normal_width = 176;  /* vdo_clip->width; */
    g_vs_mm_video_stream_context.normal_height = 144; /* vdo_clip->height; */

    ret = gdi_layer_create(
        g_vs_mm_video_stream_context.offset_x,
        g_vs_mm_video_stream_context.offset_y,
        g_vs_mm_video_stream_context.normal_width,
        g_vs_mm_video_stream_context.normal_height,
        &(g_vs_mm_video_stream_context.play_layer_handle));
    kal_prompt_trace(MOD_IDLE,"gdi_layer_create ret = %d",ret);

    gdi_layer_get_base_handle(&g_vs_mm_video_stream_context.osd_layer_handle);
    gdi_layer_set_blt_layer(g_vs_mm_video_stream_context.osd_layer_handle, g_vs_mm_video_stream_context.play_layer_handle, 0, 0);

    vs_mm_video_stream_init();
    ret = mdi_video_stream_init(ASM_ANONYMOUS_ID);

    AVK_LOG_FUN(mdi_video_stream_init,AVK_PASS);
    if(MDI_RES_VDOPLY_SUCCEED == ret)
    {
        kal_prompt_trace(MOD_IDLE,"mdi_video_stream_init ret success");
    }
    else
    {
        kal_prompt_trace(MOD_IDLE,"mdi_video_stream_init ret fail");
        if(g_vs_mm_video_stream_context.play_layer_handle != 0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }
        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_INIT_FAIL, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
        GoBackHistory();
        AVK_ASYN_DONE();
    }
    ret = mdi_video_stream_connect(vs_mm_video_stream_get_account(),MDI_VIDEO_STREAM_RTSP_URL,(S8*)g_vs_mm_video_stream_context.stream_url,MMI_FALSE,NULL,0,MMI_FALSE,32000,6970,vs_mm_video_stream_connect_result_callback,NULL);
    AVK_LOG_FUN(mdi_video_stream_connect,AVK_PASS);

    g_vs_mm_video_stream_context.m_bIsConnect = MMI_TRUE;

    if(MDI_RES_VDOPLY_SUCCEED == ret)
    {       
        kal_prompt_trace(MOD_IDLE,"mdi_video_stream_connect ret success");
    }
    else
    {
        kal_prompt_trace(MOD_IDLE,"mdi_video_stream_connect ret fail");
        if(g_vs_mm_video_stream_context.play_layer_handle != 0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();

        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, CJL_MDI_STREAM_CONNECT_FAIL, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
        GoBackHistory();
        AVK_ASYN_DONE();
    }
}

static void vs_mm_video_stream_pass(void)
{
    kal_prompt_trace(MOD_IDLE,"pass connected= %d, buffering = %d",g_vs_mm_video_stream_context.m_bIsConnect,g_vs_mm_video_stream_context.m_bIsBuffering);
    kal_prompt_trace(MOD_IDLE,"pass playing= %d",g_vs_mm_video_stream_context.m_bIsPlaying);

    gui_cancel_timer( vs_mm_video_stream_get_buf_percentage_timer_cb);
    if(g_vs_mm_video_stream_context.m_bIsPlaying == MMI_TRUE)
    {
        U64 curr_time;
        U32 blt_layer;
        U32 play_layer;
        blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
        play_layer = (GDI_LAYER_ENABLE_LAYER_1);
        mdi_video_stream_get_cur_play_time(&curr_time);

        AVK_LOG_FUN(mdi_video_stream_get_cur_play_time,AVK_PASS);
        mdi_video_stream_pause();

        AVK_LOG_FUN(mdi_video_stream_pause,AVK_PASS);
        mdi_video_stream_resume(
            g_vs_mm_video_stream_context.play_layer_handle, 
            blt_layer,
            play_layer, 
            MMI_TRUE, 
            MDI_DEVICE_SPEAKER_BOTH, 
            0);

        AVK_LOG_FUN(mdi_video_stream_resume,AVK_PASS);

        mdi_video_stream_stop();

        AVK_LOG_FUN(mdi_video_stream_stop,AVK_PASS);
        mdi_video_stream_disconnect();

        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        mdi_video_stream_deinit();  
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

        if(g_vs_mm_video_stream_context.play_layer_handle !=0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }
        g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsBuffering = MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsPlaying = MMI_FALSE;
        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_TRUE, 0, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;

    }

    if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect && MMI_TRUE == g_vs_mm_video_stream_context.m_bIsBuffering )
    {
        mdi_video_stream_stop_buffering();
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();  

        AVK_LOG_FUN(mdi_video_stream_stop_buffering,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

    }
    else if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect && MMI_FALSE == g_vs_mm_video_stream_context.m_bIsBuffering )
    {
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();  

        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);
    }
    else
    {
        if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect)
        {
            mdi_video_stream_disconnect();
        }
        mdi_video_stream_deinit();  
        AVK_LOG_FUN(mdi_video_stream_disconnect,AVK_PASS);
        AVK_LOG_FUN(mdi_video_stream_deinit,AVK_PASS);

    }
    if(g_vs_mm_video_stream_context.play_layer_handle !=0)
    {
        gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
        g_vs_mm_video_stream_context.play_layer_handle = 0;
    }

    g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
    g_vs_mm_video_stream_context.m_bIsBuffering = MMI_FALSE;
    g_vs_mm_video_stream_context.m_bIsPlaying= MMI_FALSE;
    //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_TRUE, 0, VS_TA_MM_VIDEO);
    //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
    GoBackHistory();
    AVK_ASYN_DONE();

}
static void vs_mm_video_stream_fail(void)
{

    gui_cancel_timer( vs_mm_video_stream_get_buf_percentage_timer_cb);
    kal_prompt_trace(MOD_IDLE,"vs_mm_video_stream_fail");

    kal_prompt_trace(MOD_IDLE,"fail connected= %d, buffering = %d",g_vs_mm_video_stream_context.m_bIsConnect,g_vs_mm_video_stream_context.m_bIsBuffering);
    kal_prompt_trace(MOD_IDLE,"fail playing= %d",g_vs_mm_video_stream_context.m_bIsPlaying);

    if(g_vs_mm_video_stream_context.m_bIsPlaying == MMI_TRUE)
    {

        mdi_video_stream_stop_visual_update();
        mdi_video_stream_stop();
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();  
        if(g_vs_mm_video_stream_context.play_layer_handle !=0)
        {
            gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
            g_vs_mm_video_stream_context.play_layer_handle = 0;
        }
        g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsBuffering = MMI_FALSE;
        g_vs_mm_video_stream_context.m_bIsPlaying= MMI_FALSE;
        //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, 0, VS_TA_MM_VIDEO);
        //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
        GoBackHistory();
        AVK_ASYN_DONE();
        return;

    }

    if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect && MMI_TRUE == g_vs_mm_video_stream_context.m_bIsBuffering )
    {
        S32 video_width,video_height;
        mdi_video_stream_get_dimension(&video_width, &video_height); 
        mdi_video_stream_stop_buffering();
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();  

    }
    else if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect && MMI_FALSE == g_vs_mm_video_stream_context.m_bIsBuffering )
    {
        mdi_video_stream_disconnect();
        mdi_video_stream_deinit();  
    }
    else
    {

        if(MMI_TRUE == g_vs_mm_video_stream_context.m_bIsConnect)
        {
            mdi_video_stream_disconnect();
        }
        mdi_video_stream_deinit();  
    }

    if(g_vs_mm_video_stream_context.play_layer_handle !=0)
    {
        gdi_layer_free(g_vs_mm_video_stream_context.play_layer_handle);
        g_vs_mm_video_stream_context.play_layer_handle = 0;
    }

    g_vs_mm_video_stream_context.m_bIsConnect = MMI_FALSE;
    g_vs_mm_video_stream_context.m_bIsBuffering = MMI_FALSE;
    g_vs_mm_video_stream_context.m_bIsPlaying= MMI_FALSE;
    //vs_tfw_trace_result(L"vs_mm_video_007_stream_play", MMI_FALSE, 0, VS_TA_MM_VIDEO);
    //vs_tfw_finish_case_extern(VS_MM_VIDEO_007, SCR_ID_VS_MM_VIDEO);
    GoBackHistory();
    AVK_ASYN_DONE();


}

#endif

/*****************************************************************************
* FUNCTION
*  vs_mm_video_007_stream_play
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_007_stream_play(void)
{
#ifdef __MMI_VIDEO_STREAM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vs_mm_video_stream_play();

#else
AVK_LOG_FUN_UNSUPPORTED(mdi_video_progressive_open_file);
AVK_ASYN_DONE();
#endif
}



#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_PDL__)

typedef struct
{
    gdi_handle play_layer_handle;
    gdi_handle osd_layer_handle;
    U64 play_time;
    S32 offset_x;
    S32 offset_y;
    S32 normal_width;
    S32 normal_height;
}vs_mm_video_pdl_context;

vs_mm_video_pdl_context g_vs_mm_pdl_context;
static void video_pdl_play_finish_callback (MDI_RESULT ret, void *user_data);
static void video_pdl_get_buf_percentage_timer_cb(void);
static void video_pdl_seek_result_callback (MDI_RESULT ret, void *user_data);
static  void video_pdl_open_file_callback (S32 ret , mdi_video_info_struct* video_info, void *user_data);
static void vs_mm_video_pdl_pass(void);
static void vs_mm_video_pdl_fail(void);



static void video_pdl_play_finish_callback (MDI_RESULT ret, void *user_data)
{
    kal_prompt_trace(MOD_IDLE,"video_pdl_play_finish_callback ret = %d",ret);
    if (MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH == ret)
    {
        kal_prompt_trace(MOD_IDLE,"MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH");
        gui_start_timer(300,video_pdl_get_buf_percentage_timer_cb);
    }
    if (MDI_RES_VDOPLY_SUCCEED == ret)
    {
        kal_prompt_trace(MOD_IDLE,"video_pdl_play_finish_callback not enough");

        gui_cancel_timer(video_pdl_get_buf_percentage_timer_cb);
        mdi_video_progressive_close_file();
        AVK_LOG_FUN(mdi_video_progressive_close_file,AVK_PASS);
    }
}

static void video_pdl_get_buf_percentage_timer_cb(void)
{
    S32 percentage;
    S32 ret;

    ret = mdi_video_progressive_get_buf_percentage(&percentage);

    AVK_LOG_FUN(mdi_video_progressive_get_buf_percentage,AVK_PASS);
    kal_prompt_trace(MOD_IDLE,"timecb get_percent ret = %d",ret);
    if (percentage < 100)
    {
        kal_prompt_trace(MOD_IDLE,"timecb  start_timer");

        gui_start_timer(300,video_pdl_get_buf_percentage_timer_cb);
    }
    else
    {
        U32 blt_layer;
        U32 play_layer;
        blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
        play_layer = (GDI_LAYER_ENABLE_LAYER_1);
        kal_prompt_trace(MOD_IDLE,"timecb mdi_video_ply_play");

        ret = mdi_video_ply_play(g_vs_mm_pdl_context.play_layer_handle,
            blt_layer,
            play_layer,
            1,
            MMI_TRUE,
            MMI_TRUE,
            MDI_DEVICE_SPEAKER_BOTH,
            MDI_VIDEO_LCD_ROTATE_0,
            100,            
            (mdi_play_finish_callback)video_pdl_play_finish_callback,
            NULL);

        kal_prompt_trace(MOD_IDLE,"timecb mdi_video_ply_play ret = %d",ret);

    }

}

static void video_pdl_seek_result_callback (MDI_RESULT ret, void *user_data)
{
    S32 percentage;

    kal_prompt_trace(MOD_IDLE,"video_pdl_seek_result_callback");

    if (ret >= MDI_RES_VDOPLY_SUCCEED)
    {
        ret = mdi_video_progressive_get_buf_percentage(&percentage);

        AVK_LOG_FUN(mdi_video_progressive_get_buf_percentage,AVK_PASS);
        kal_prompt_trace(MOD_IDLE,"seekcb get_buf_percentage ret = %d",ret);
        kal_prompt_trace(MOD_IDLE,"seekcb percentage = %d",percentage);
        if (percentage < 100)
        {
            gui_start_timer(300,video_pdl_get_buf_percentage_timer_cb); 
        }
        else
        {
            U32 blt_layer;
            U32 play_layer;
            blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
            play_layer = (GDI_LAYER_ENABLE_LAYER_1);

            mdi_video_ply_set_sleep_time(10, 1);

            AVK_LOG_FUN(mdi_video_ply_set_sleep_time,AVK_PASS);



            ret = mdi_video_ply_play(g_vs_mm_pdl_context.play_layer_handle,
                blt_layer,
                play_layer,
                1,
                MMI_TRUE,
                MMI_TRUE,
                MDI_DEVICE_SPEAKER_BOTH,
                MDI_VIDEO_LCD_ROTATE_0,
                100,            
                (mdi_play_finish_callback)video_pdl_play_finish_callback,
                NULL);

            kal_prompt_trace(MOD_IDLE,"seekcb mdi_video_ply_play ret = %d",ret);


        }
    }
}
static  void video_pdl_open_file_callback (S32 ret , mdi_video_info_struct* video_info, void *user_data)
{
    S32 percentage;
    U64 max_time;
    kal_prompt_trace(MOD_IDLE,"video_pdl_open_file_callback");
    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {

        ret = mdi_video_progressive_get_max_play_time(&max_time);

        AVK_LOG_FUN(mdi_video_progressive_get_max_play_time,AVK_PASS);

        kal_prompt_trace(MOD_IDLE,"opencb get_max_play_time ret = %d",ret);
        kal_prompt_trace(MOD_IDLE,"opencb max_time = %u",max_time);
        ret = mdi_video_progressive_get_buf_percentage (&percentage);

        AVK_LOG_FUN(mdi_video_progressive_get_buf_percentage,AVK_PASS);
        kal_prompt_trace(MOD_IDLE,"opencb get_buf_percentage ret = %d",ret);
        kal_prompt_trace(MOD_IDLE,"opencb percentage = %d",percentage);
        if (percentage < 100)
        {
            gui_start_timer(300,video_pdl_get_buf_percentage_timer_cb);
        }
        else
        {
            U32 blt_layer;
            U32 play_layer;
            blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
            play_layer = (GDI_LAYER_ENABLE_LAYER_1);
            gdi_layer_get_base_handle(&g_vs_mm_pdl_context.osd_layer_handle);
            gdi_layer_set_blt_layer(g_vs_mm_pdl_context.osd_layer_handle, g_vs_mm_pdl_context.play_layer_handle, 0, 0);
            ret = mdi_video_ply_non_block_seek_and_get_frame(0,g_vs_mm_pdl_context.play_layer_handle,
                                                                (mdi_seek_result_callback)video_pdl_seek_result_callback,NULL);

            kal_prompt_trace(MOD_IDLE,"opencb seek_and_get ret = %d",ret);

            if(ret != MDI_RES_VDOPLY_SUCCEED)
            {
                mdi_video_ply_non_block_seek(0,(mdi_seek_result_callback)video_pdl_seek_result_callback,NULL);
            }
            AVK_LOG_FUN(mdi_video_ply_non_block_seek,AVK_PASS);
            AVK_LOG_FUN(mdi_video_ply_non_block_seek_and_get_frame,AVK_PASS);


        }
    }       
}

static void vs_mm_video_pdl_pass(void)
{
    WCHAR pp1[] = { 'z', ':', '\\', '\\', '1', '.', 'j', 'p', 'g', '\0'};
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    int letter =  FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    if (letter>='a'&& letter<='z')
    {
        pp1[0] = L'a'+ (char)letter - 'a';
    }
    if (letter>='A'&& letter<='Z')
    {
        pp1[0] = L'A'+(char)letter - 'A';
    }
#ifdef __MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__

    ret = mdi_video_ply_snapshot(g_vs_mm_pdl_context.play_layer_handle, (PS8)pp1);
    AVK_LOG_FUN(mdi_video_ply_snapshot,AVK_PASS);

    kal_prompt_trace(MOD_IDLE,"mdi_video_ply_snapshot ret = %d",ret);
#else
    kal_prompt_trace(MOD_IDLE,"not support snapshot");

#endif

    kal_prompt_trace(MOD_IDLE,"vs_mm_video_pdl_pass");
    gui_cancel_timer(video_pdl_get_buf_percentage_timer_cb);
    if(mdi_video_is_playing())
    {

        U32 blt_layer;
        U32 play_layer;
        blt_layer = (GDI_LAYER_ENABLE_LAYER_0) | (GDI_LAYER_ENABLE_LAYER_1);
        play_layer = (GDI_LAYER_ENABLE_LAYER_1);
        mdi_video_ply_update_layer_pause();
        mdi_video_ply_update_layer_resume(g_vs_mm_pdl_context.play_layer_handle,blt_layer,play_layer,MMI_TRUE,MDI_VIDEO_LCD_ROTATE_0);
        kal_prompt_trace(MOD_IDLE,"pass mdi_video_is_playing");
        mdi_video_ply_stop();
        mdi_video_progressive_close_file();


        AVK_LOG_FUN(mdi_video_is_playing,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_update_layer_pause,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_update_layer_resume,AVK_PASS);
        AVK_LOG_FUN(mdi_video_ply_stop,AVK_PASS);
        AVK_LOG_FUN(mdi_video_progressive_close_file,AVK_PASS);
    }
    else
    {
        mdi_video_ply_stop_non_block_seek();
        mdi_video_ply_close_file();
    }


    AVK_LOG_FUN(mdi_video_ply_stop_non_block_seek,AVK_PASS);
    AVK_LOG_FUN(mdi_video_ply_close_file,AVK_PASS);

    if(g_vs_mm_pdl_context.play_layer_handle != 0)
    {

        gdi_layer_free(g_vs_mm_pdl_context.play_layer_handle);
        g_vs_mm_pdl_context.play_layer_handle = 0;
    }
    //vs_tfw_trace_result(L"vs_mm_video_008_pdl", MMI_TRUE, 0, VS_TA_MM_VIDEO);
    //vs_tfw_finish_case_extern(VS_MM_VIDEO_008, SCR_ID_VS_MM_VIDEO);

    GoBackHistory();
    AVK_ASYN_DONE();


}
static void vs_mm_video_pdl_fail(void)
{
    kal_prompt_trace(MOD_IDLE,"vs_mm_video_pdl_fail");
    gui_cancel_timer(video_pdl_get_buf_percentage_timer_cb);
    if(mdi_video_is_playing())
    {

        kal_prompt_trace(MOD_IDLE,"fail mdi_video_is_playing");
        mdi_video_ply_stop();
        mdi_video_progressive_close_file();
    }
    else
    {
        mdi_video_ply_stop_non_block_seek();
        mdi_video_ply_close_file();
    }

    if(g_vs_mm_pdl_context.play_layer_handle != 0)
    {
        gdi_layer_free(g_vs_mm_pdl_context.play_layer_handle);
        g_vs_mm_pdl_context.play_layer_handle = 0;
    }


    //vs_tfw_trace_result(L"vs_mm_video_008_pdl", MMI_FALSE, 0, VS_TA_MM_VIDEO);
    //vs_tfw_finish_case_extern(VS_MM_VIDEO_008, SCR_ID_VS_MM_VIDEO);
    GoBackHistory();
    AVK_ASYN_DONE();

}



#endif


/*****************************************************************************
* FUNCTION
*  vs_mm_video_008_pdl
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vs_mm_video_008_pdl(void)
{
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_PDL__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 len;
    MMI_BOOL bIsPdl;

    WCHAR fileBuf[VS_MM_BUFFER_SIZE];
    FS_HANDLE handle;
    UINT filesize;
    S32 letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_AVK,
        9687,
        NULL,
        vs_mm_video_008_pdl,
        MMI_FRM_FULL_SCRN);

    ShowCategory227Screen(0, 0, STR_GLOBAL_YES, 0, STR_GLOBAL_NO, 0, NULL, NULL);
    SetLeftSoftkeyFunction(vs_mm_video_pdl_pass, KEY_EVENT_UP);
    SetRightSoftkeyFunction(vs_mm_video_pdl_fail, KEY_EVENT_UP);



    g_vs_mm_pdl_context.offset_x = 0;       /* (MMI_content_width - vdo_clip->width) >> 1; */
    g_vs_mm_pdl_context.offset_y = 0;      /* (MMI_content_height - vdo_clip->height) >> 1; */
    g_vs_mm_pdl_context.normal_width = 176;  /* vdo_clip->width; */
    g_vs_mm_pdl_context.normal_height = 144; /* vdo_clip->height; */

    gdi_layer_create(
        g_vs_mm_pdl_context.offset_x,
        g_vs_mm_pdl_context.offset_y,
        g_vs_mm_pdl_context.normal_width,
        g_vs_mm_pdl_context.normal_height,
        &g_vs_mm_pdl_context.play_layer_handle);


    memset(fileBuf, 0, sizeof(fileBuf));
    mmi_wcscat((U16*) fileBuf, (U16*) AVK_TEST_FILE_PATH);
    mmi_wcscat((U16*) fileBuf, (U16*) L"avk_mm_video\\");
    mmi_wcscat((U16*) fileBuf, (U16*) L"pdl.3gp");


    handle = FS_Open(fileBuf, FS_READ_ONLY); 
    FS_GetFileSize(handle, &filesize);
    FS_Close(handle);

    kal_prompt_trace(MOD_IDLE,"pdl file size= %u",filesize);

#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)
#ifdef DUAL_CAMERA_SUPPORT
    mdi_video_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
    AVK_LOG_FUN(mdi_video_set_camera_id,AVK_PASS);

#endif 
#endif
	//To do clear cache for asm insufficient sometimes 
	applib_mem_ap_free_all_cache();

    // fileBuffer and file size should be file content and content length
    //ret = mdi_video_progressive_is_pdl_format((U8*)fileBuf,filesize,&bIsPdl);

    //AVK_LOG_FUN(mdi_video_progressive_is_pdl_format,AVK_PASS);
    //kal_prompt_trace(MOD_IDLE,"mdi_video_progressive_is_pdl_format ret= %d,ispdl = %d",ret,bIsPdl);

    //ret = mdi_video_progressive_is_pdl_format((U8*)fileBuf,len,&bIsPdl);

    //kal_prompt_trace(MOD_IDLE,"mdi_video_progressive_is_pdl_format_1 ret= %d,ispdl = %d",ret,bIsPdl);

    ret = mdi_video_progressive_open_file (ASM_ANONYMOUS_ID,(const S8 *)fileBuf,
                                    (mdi_progressive_result_callback)video_pdl_open_file_callback,NULL);
    AVK_LOG_FUN(mdi_video_progressive_open_file,AVK_PASS);

    kal_prompt_trace(MOD_IDLE,"mdi_video_progressive_open_file ret = %d",ret);
#else
    AVK_LOG_FUN_UNSUPPORTED(mdi_video_progressive_open_file);

    AVK_ASYN_DONE();
#endif
}

AVK_TEST_ALL(AVK_MM_VIDEO)

AVK_ADD_ITEM(AVK_VIDEO_ITEM_001,L"Video 001",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_002,L"Video 002",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_003,L"Video 003",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_004,L"Video 004",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_005,L"Video 005",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_006,L"Video 006",AVK_MM_VIDEO);
AVK_ADD_ITEM(AVK_VIDEO_ITEM_007,L"Video 007",AVK_MM_VIDEO);


AVK_MANUAL_CASE(AVK_VIDEO_MANUAL1,AVK_VIDEO_ITEM_001)
{    
    vs_mm_misc_init_video();
    vs_mm_video_001_open_file();

}

AVK_MANUAL_CASE(AVK_VIDEO_MANUAL2,AVK_VIDEO_ITEM_002)
{    
    vs_mm_misc_init_video();
    vs_mm_video_002_open_clip();

}

AVK_MANUAL_CASE(AVK_VIDEO_MANUAL3,AVK_VIDEO_ITEM_003)
{    
    vs_mm_misc_init_video();
    vs_mm_video_003_open_id();
}

AVK_MANUAL_CASE(AVK_VIDEO_MANUAL4,AVK_VIDEO_ITEM_004)
{    
    vs_mm_misc_init_video();
    vs_mm_video_004_open_buffer();
}

AVK_MANUAL_CASE(AVK_VIDEO_MANUAL5,AVK_VIDEO_ITEM_005)
{    
    vs_mm_misc_init_video();
    vs_mm_video_005_rec_file();
}

AVK_MANUAL_CASE(AVK_VIDEO_MANUAL6,AVK_VIDEO_ITEM_006)
{    
    vs_mm_misc_init_video();
    vs_mm_video_007_stream_play();
}


AVK_MANUAL_CASE(AVK_VIDEO_MANUAL7,AVK_VIDEO_ITEM_007)
{    
    vs_mm_misc_init_video();
    vs_mm_video_008_pdl();
}




#endif /* __MAUI_SDK_TEST__ */ 

