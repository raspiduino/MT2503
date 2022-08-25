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
*  AudioPlayerMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Karaoke Source file
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "KaraokeGprot.h"

#ifdef __MMI_KARAOKE__
#include "globalresdef.h"
#include "mmi_frm_scenario_gprot.h"
#include "globalconstants.h"
#include "gui_typedef.h"
#include "FileMgrType.h"
#include "FileMgrCuiGprot.h"
#include "fs_gprot.h"
#include "USBSrvGprot.h"
#include "Conversions.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "Custom_events_notify.h"
#include "mmi_trc_int.h"
#include "mmi_media_app_trc.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "mdi_audio.h"
#include "mmi_rp_app_profiles_def.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif

#include "wgui_categories_btbox.h"
#include "lyrics_parser.h"
#include "gpiosrvgprot.h"

#include "Karaoke.h"
#include "mmi_rp_app_karaoke_def.h"
#include "BthScoPathSrvGProt.h"
#include "AudioPlayerBTNowPlaying.h"

#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
#include "mmi_rp_srv_a2dp_def.h"
#endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)

static mmi_karaoke_context_struct g_karaoke_cntx;



static void mmi_karaoke_list_generate_internal(void);
static void mmi_karaoke_list_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf);
static void mmi_karaoke_list_generate_search(void);
static S32 mmi_karaoke_list_generate_append_one(UI_string_type path, MMI_BOOL is_short);
static void mmi_karaoke_list_generate_cancel(void);

static MMI_BOOL mmi_karaoke_list_remove_all(void);
static S32 mmi_karaoke_list_reload(void);
static S32 mmi_karaoke_list_check_and_set_default_path(UI_string_type file_path, CHAR driver_letter);

static void mmi_karaoke_song_list_sing(void);
static void mmi_karaoke_song_list_add(void);

static void mmi_karaoke_record_list_delete_file(void);
#ifdef __MMI_TELEPHONY_SUPPORT__
static void mmi_karaoke_record_list_use_as_ringtone(void);
#endif  //__MMI_TELEPHONY_SUPPORT__
static void mmi_karaoke_record_list_send_via_bt(void);

void mmi_karaoke_entry_sing_screen(void);
mmi_ret mmi_karaoke_sing_proc(mmi_event_struct *event);
void mmi_karaoke_exit_sing_screen(void);
static void mmi_karaoke_origin_sing(void);
#ifdef __LINE_IN_SUPPORT__
static void mmi_karaoke_force_use_linein_mic(void);
#endif
static void mmi_karaoke_finish_sing(void);
static void mmi_karaoke_resing(void);

void mmi_karaoke_entry_play_record_screen(void);
void mmi_karaoke_exit_play_record_screen(void);
mmi_ret mmi_karaoke_play_record_proc(mmi_event_struct *event);
void mmi_karaoke_redraw_main_progressbar();
static void mmi_karaoke_detelte_record_file(void);
static void mmi_karaoke_sing_callback_hdlr(mdi_result result, void *user_data);
static void mmi_karaoke_play_record_callback_hdlr(mdi_result result, void *user_data);
void mmi_karaoke_get_rec_lyric_filepath(UI_string_type filepath);
void mmi_karaoke_interrupt_callback(S32 result, void *user_data);
void mmi_karaoke_draw_bg_progressbar(MMI_BOOL need_blt);
#ifdef __MMI_TOUCH_SCREEN__
void mmi_karaoke_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_karaoke_pen_move_hdlr(mmi_pen_point_struct pos);
void mmi_karaoke_pen_up_hdlr(mmi_pen_point_struct pos);
#endif
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
static void mmi_karaoke_prepare_lyrics(void);
static void mmi_karaoke_update_lyrics_on_time(void);
#endif  //__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__

static void mmi_karaoke_delay_play(void);
static void mmi_karaoke_clear(void);
static void mmi_karaoke_get_src_lyric_filepath(UI_string_type filepath);

static void mmi_karaoke_inc_aud_vol(void);
static void mmi_karaoke_dec_aud_vol(void);
static void mmi_karaoke_inc_mic_vol(void);
static void mmi_karaoke_dec_mic_vol(void);

void mmi_karaoke_entry_volume_adjust_screen(void);
void mmi_karaoke_exit_volume_adjust_screen(void);
static mmi_ret mmi_karaoke_volume_proc(mmi_event_struct *evt);
static void mmi_karaoke_volume_timer_hdlr(void);
static void mmi_karaoke_update_audio_bar(kal_uint8 index);
static void mmi_karaoke_update_voice_bar(kal_uint8 index);
static void mmi_karaoke_update_select(void);


/* 
**  mp3 mp2 amr aac awb bsac are the four audio types which
**  requires building cache to seek, so we put them in the frist six items
**  for build cache deciding api to reference.
*/
const static UI_character_type karaoke_audio_file_exts[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"amr", 
#ifdef AAC_DECODE
    L"aac",
#endif 
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    L"odf",
#endif
    L"wav",   
    L"mid",
    L"midi", 
    L"imy",
//    L"vm ",
#ifdef AIFF_DECODE
    L"aif",
    L"aiff",
    L"aifc",
#endif
#ifdef AU_DECODE
    L"au",
#endif
#ifdef SND_DECODE
    L"snd",
#endif
#ifdef M4A_DECODE
    L"m4a",
#endif 
#ifdef YAMAHA_MA3
    L"mmf",
#endif 
#ifdef WMA_DECODE
    L"wma",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3gp",
    L"3g2",
    L"mp4",
#endif

#ifdef __RM_DEC_SUPPORT__
	L"ra",
#endif
	
#ifdef __APE_DECODE__
	L"ape",
#endif    
#ifdef __FLAC_DECODE__
    L"flac",
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    L"OGG",
#endif    

    L"\0"   /* end of list */
};


static FS_Pattern_Struct karaoke_audio_pattern_array[] = 
{
#ifdef DAF_DECODE
    {L"*.mp3"},
#ifdef MUSICAM_DECODE
    {L"*.mp2"},
#endif    
#endif
#ifdef AAC_DECODE
    {L"*.aac"},
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif

#ifdef __DRM_V02__
    {L"*.odf"},
#endif

    {L"*.wav"},

#ifdef AIFF_DECODE
    {L"*.aif"},
    {L"*.aiff"},
    {L"*.aifc"},
#endif

#ifdef AU_DECODE
    {L"*.au"},
#endif

#ifdef SND_DECODE
    {L"*.snd"},
#endif

#ifdef YAMAHA_MA3
    {L"*.mmf"},
#endif 

#ifdef WMA_DECODE
    {L"*.wma"},
#endif 

#if defined(__MMI_PURE_AUDIO__)
    {L"*.3gp"},
    {L"*.3g2"},
    {L"*.mp4"},
#endif

#ifdef __RM_DEC_SUPPORT__
    {L"*.ra"},
#endif
	
#ifdef __APE_DECODE__
    {L"*.ape"},
#endif    

#ifdef __FLAC_DECODE__
    {L"*.flac"},
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {L"*.ogg"},
#endif
};


//Add By Zhixiong
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
mmi_karaoke_lyrics_box_struct 	g_karaoke_lyrics_box;
lyrics_meta_struct*  			g_karaoke_lyrics = NULL;
GDI_HANDLE              		karaoke_osd_layer;
static scrolling_text   		karaoke_scrolling_title;
static kal_bool 				karaoke_show_title_done=KAL_FALSE;
#endif  //__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__

#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_get_src_path
 * DESCRIPTION
 *  This file is to get the src file path at the end of the record file
 * PARAMETERS
 *  
 * RETURNS
 *  result of get src path 
 *  0 means sucess
 *  others means fail
 *****************************************************************************/
static S32 mmi_karaoke_get_src_path(void)
{
	CHAR str[5]={0};
	FS_HANDLE fd;
	U32 read_size=0;
	S32 ret=0,result=0;
	S32 offset=0-(sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1)+8);
	
	fd = FS_Open(g_karaoke_cntx.Rec_filepath,FS_READ_WRITE|FS_OPEN_SHARED);
	if(fd > 0)
	{
		ret = FS_Seek(fd,offset,FS_FILE_END);
		ret = FS_Read(fd,str,4,&read_size);
		result = strcmp((CHAR*)str, (CHAR*)"SRC ");
		if((ret < 0) || (4 !=read_size) || result)
		{
			ret = FS_Close(fd);
			return -1;
		}
		
		ret = FS_Read(fd,str,4,&read_size);
		result = strcmp((CHAR*)str, (CHAR*)"0802");
		if((ret < 0) || (4 !=read_size) || result)
		{
			ret = FS_Close(fd);
			return -1;
		}
		
		ret = FS_Read(fd,(kal_char*)g_karaoke_cntx.filefullname,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1),&read_size);
		ret = FS_Close(fd);
		
		fd = FS_Open(g_karaoke_cntx.filefullname,FS_READ_ONLY|FS_OPEN_SHARED);
		if(fd >0)
		{
		    FS_Close(fd);
			return 0;
		}
		else
		{
			memset((kal_char*)g_karaoke_cntx.filefullname,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
		    FS_Close(fd);
		}
	}

	return -1;
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_post_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt_id
 *  proc
 *  user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_post_event(U16 evt_id, mmi_proc_func proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	mmi_event_struct evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&evt, evt_id);
	mmi_frm_post_event(&evt, proc, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mdi_result result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 5, event->evt_id);
    if (mmi_frm_scrn_get_active_id() != SCR_ID_KARAOKE_SING &&
        mmi_frm_scrn_get_active_id() != SCR_ID_KARAOKE_PLAY_RECORD)
    {
        if ((mmi_frm_group_is_present(GRP_ID_KARAOKE_SING) || mmi_frm_group_is_present(GRP_ID_KARAOKE_PLAY_RECORD)) &&
            (event->evt_id == MMI_KARAOKE_EVENT_SING || event->evt_id == MMI_KARAOKE_EVENT_PLAY_RECORD))
        {
			StartTimer(KARAOKE_DELAY_PLAY_TIMER, MMI_KARAOKE_DELAY_PLAY, mmi_karaoke_delay_play);
        }
        return MMI_RET_OK;
    }
    
	switch (event->evt_id)
	{
		case MMI_KARAOKE_EVENT_PREPARE_LYRIC:
		{
            #ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
            g_karaoke_lyrics_box.rgn_txt.x              = LYRICS_X;
            g_karaoke_lyrics_box.rgn_txt.y              = LYRICS_Y;
            g_karaoke_lyrics_box.rgn_txt.w              = LYRICS_width;
            g_karaoke_lyrics_box.rgn_txt.h              = LYRICS_height;
            g_karaoke_lyrics_box.color.r =  84;
            g_karaoke_lyrics_box.color.g =   203;
            g_karaoke_lyrics_box.color.b =   227;
            mmi_karaoke_prepare_lyrics();
            if(g_karaoke_lyrics != NULL)
                mmi_karaoke_update_lyrics_on_time();
            #endif
			break;
		}
		case MMI_KARAOKE_EVENT_SING:
		{
    		result = mdi_audio_play_file_portion_with_vol_path(
                       g_karaoke_cntx.filefullname,
                       g_karaoke_cntx.new_play_time,
                       0,
                       DEVICE_AUDIO_PLAY_ONCE,
                       NULL,
                       mmi_karaoke_sing_callback_hdlr,
                       NULL,
                       (U8)MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol),
                       MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
    		if (result != MDI_AUDIO_SUCCESS)
    		{
    		    //UI_character_type rec_lyricpath[SRV_FMGR_PATH_MAX_LEN + 1];
    			
    		   	//mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
    			//if(rec_lyricpath[0] != NULL)
    			//    FS_Delete(rec_lyricpath);
    		    FS_Delete(g_karaoke_cntx.Rec_filepath);
    			mmi_frm_group_close(GRP_ID_KARAOKE_SING);
    			mmi_popup_display_ext(
    									STR_ID_KARAOKE_ERR_SING_FAIL, 
    									MMI_EVENT_FAILURE, 
    									NULL);
                return MMI_RET_OK;
    		}
			mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PREPARE_LYRIC, mmi_karaoke_event_hdlr, NULL);
    		{
    			UI_character_type src_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    			UI_character_type rec_lyricfoder[(SRV_FMGR_PATH_MAX_LEN+1) + 1+17];
    			//Copy lyric to record folder
    			mmi_karaoke_get_src_lyric_filepath(src_lyricpath);
    			mmi_karaoke_get_rec_lyric_filepath(rec_lyricfoder);
    			if(src_lyricpath[0] != NULL && rec_lyricfoder[0]!= NULL)
    			    FS_Move(src_lyricpath, rec_lyricfoder, FS_MOVE_OVERWRITE|FS_MOVE_COPY, NULL, NULL, 0);
    		}
        	if(!g_karaoke_cntx.mdi_callback_registed)
        	{
        		mdi_audio_register_interrupt_callback(mmi_karaoke_interrupt_callback,NULL);
        		g_karaoke_cntx.mdi_callback_registed = KAL_TRUE;
        	}
			break;
		}
		case MMI_KARAOKE_EVENT_PLAY_RECORD:
		{
            MMI_BOOL need_close_group = MMI_FALSE;
			
            #ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
			if(!g_karaoke_cntx.play_record_for_reviewing)
			{
				result = mmi_karaoke_get_src_path();
			}

			result = mdi_audio_karaoke_remix_turn_on(g_karaoke_cntx.Rec_filepath,0,0);
			if(result != MDI_AUDIO_SUCCESS)
			{
			    mdi_audio_karaoke_remix_turn_off();
			}
			else
			{
			    result = mdi_audio_play_file_portion_with_vol_path(
				   g_karaoke_cntx.filefullname,
				   g_karaoke_cntx.new_play_time,
				   g_karaoke_cntx.duration,
				   DEVICE_AUDIO_PLAY_ONCE,
				   NULL,
				   mmi_karaoke_play_record_callback_hdlr,
				   NULL,
				   (U8)MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol),
				   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
				if((result != MDI_AUDIO_SUCCESS) && (result != MDI_AUDIO_END_OF_FILE))
				{
				    result = mdi_audio_play_file_portion_with_vol_path(
					   g_karaoke_cntx.Rec_filepath,
					   g_karaoke_cntx.new_play_time,
					   0,
					   DEVICE_AUDIO_PLAY_ONCE,
					   NULL,
					   mmi_karaoke_play_record_callback_hdlr,
					   NULL,
					   (U8)MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol),
					   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
				}
			}
            #else
 			result = mdi_audio_play_file_portion_with_vol_path(
					   g_karaoke_cntx.Rec_filepath,
					   g_karaoke_cntx.new_play_time,
					   0,
					   DEVICE_AUDIO_PLAY_ONCE,
					   NULL,
					   mmi_karaoke_play_record_callback_hdlr,
					   NULL,
					   (U8)MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol),
					   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));
			#endif
			g_karaoke_cntx.is_eof = KAL_FALSE;
            
		    if (result == MDI_AUDIO_END_OF_FILE)
            {      
		        mmi_karaoke_play_record_callback_hdlr(MDI_AUDIO_END_OF_FILE,NULL);
            }
			else if (result != MDI_AUDIO_SUCCESS)
			{
				//gdi_lcd_freeze(gdi_freeze);
				if(g_karaoke_cntx.play_record_for_reviewing)
				{
					UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
					mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
					if(rec_lyricpath[0] != NULL)
						FS_Delete(rec_lyricpath);
					FS_Delete(g_karaoke_cntx.Rec_filepath);
				}
				if(g_karaoke_cntx.play_record_for_reviewing
					//||(g_karaoke_cntx.current_list.list_data.highlight == g_karaoke_cntx.current_list.list_data.total-1)
					)
				{
				    need_close_group = MMI_TRUE;
					g_karaoke_cntx.is_interrupted = KAL_FALSE;
				}
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				
				g_karaoke_cntx.is_paused = MMI_TRUE;
				
				mmi_popup_display_ext(
										STR_ID_KARAOKE_ERR_PLAY_RECORD_FAIL, 
										MMI_EVENT_FAILURE, 
										NULL);
                if (need_close_group)
                {
					if(mmi_frm_group_is_present(GRP_ID_KARAOKE_SING))
					    mmi_frm_group_close(GRP_ID_KARAOKE_SING);
					else
						mmi_frm_group_close(GRP_ID_KARAOKE_PLAY_RECORD);
                }
                return MMI_RET_OK;
			}
			mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PREPARE_LYRIC, mmi_karaoke_event_hdlr, NULL);
        	if(!g_karaoke_cntx.mdi_callback_registed)
        	{
        		mdi_audio_register_interrupt_callback(mmi_karaoke_interrupt_callback,NULL);
        		g_karaoke_cntx.mdi_callback_registed = KAL_TRUE;
        	}
			break;
		}
	}

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_delay_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_delay_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (mmi_frm_group_get_active_id() == GRP_ID_KARAOKE_SING && !g_karaoke_cntx.play_record_for_reviewing)
	{
		mmi_karaoke_post_event(MMI_KARAOKE_EVENT_SING, mmi_karaoke_event_hdlr, NULL);
	}
	else
	{
		mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PLAY_RECORD, mmi_karaoke_event_hdlr, NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_is_dev_ready
 * DESCRIPTION
 *  Check whether dev is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_is_dev_ready(MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Check if in USB mode before enter app */
	#if defined(__USB_IN_NORMAL_MODE__)
	if (srv_usb_is_in_mass_storage_mode())
	{
	    if (need_popup)
        {   
		    mmi_usb_app_unavailable_popup(0);
        }
		return MMI_FALSE;
	}
	#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
	if ((error=FS_GetDevStatus((U8)MMI_KARAOKE_DEFAULT_DRV, FS_MOUNT_STATE_ENUM)) != FS_NO_ERROR)
	{
	    if (need_popup)
        {   
    		mmi_popup_display_ext(
    			STR_GLOBAL_INSERT_MEMORY_CARD, 
    			(mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error), 
    			NULL);
        }
		return MMI_FALSE;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_GENERATE_TRACE, 200);
    StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
    g_karaoke_cntx.generate_info.phase = MMI_KARAOKE_GENERATE_PHASE_CANCEL;
    StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER, 20, mmi_karaoke_list_generate_internal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_wait_screen_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_wait_screen_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 3, event->evt_id);

    if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
    {
        title = STR_ID_KARAOKE_SONG_LIST_TITLE;
    }
    else
    {
        title = STR_ID_KARAOKE_RECORD_LIST_TITLE;
    }
    
    switch (event->evt_id)
    {
	    case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            /* do not allow popup sliding for this waiting popup */        
            ShowCategory66Screen(
                title,
                NULL,
                0,
                0,
                STR_GLOBAL_CANCEL,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
        
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
		    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
		    mmi_karaoke_list_struct * list = &(g_karaoke_cntx.current_list);

		    /*----------------------------------------------------------------*/
		    /* Code Body                                                      */
		    /*----------------------------------------------------------------*/
			StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
		    if (!(this->search_handle < 0))
		    {
		        FS_FindClose(this->search_handle);
		    }
		    FS_Close(this->generate_handle);
		    FS_Close(list->fs_hdlr);	
            break;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_karaoke_list_generate_cancel();
            return MMI_RET_KEY_HANDLED;          
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(
        GRP_ID_KARAOKE, 
        GRP_ID_KARAOKE_WAITSCREEN, 
        mmi_karaoke_wait_screen_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(
         GRP_ID_KARAOKE_WAITSCREEN, 
         SCR_ID_KARAOKE_WAITSCREEN, 
         mmi_karaoke_wait_screen_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code            [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_display_popup(S32 error_code, FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
    U16 string_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_code > MMI_KARAOKE_ERR_BEGIN)
    {
        /* handle file system error code. */
        string_id = srv_fmgr_fs_error_get_string(error_code);
        event_type = (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error_code);
        /* handle special case. */
        switch (error_code)
        {
            case FS_NO_MORE_FILES:
                string_id = STR_GLOBAL_EMPTY;
                break;
            default:
                break;
        }
    }
    else
    {
    	event_type = MMI_EVENT_FAILURE;
        /* get string id. */
        switch (error_code)
        {
            case MMI_KARAOKE_ERR_WRITE_FAILED:
                string_id = STR_ID_KARAOKE_ERR_WRITE_FAILED;
                break;
            case MMI_KARAOKE_ERR_READ_FAILED:
                string_id = STR_ID_KARAOKE_ERR_READ_FAILED;
                break;
            case MMI_KARAOKE_ERR_FILE_EXISTS:
                string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                break;
            case MMI_KARAOKE_ERR_LIST_FULL:  
                string_id = STR_ID_KARAOKE_ERR_LIST_FULL;
                break;
            case MMI_KARAOKE_ERR_NOT_PLST:
                string_id = STR_GLOBAL_INVALID_FORMAT;
                break;
            case MMI_KARAOKE_ERR_WRONG_VER:
                string_id = STR_ID_KARAOKE_ERR_WRONG_VERSION;
                break;
            case MMI_KARAOKE_ERR_INVALID_PARA:
                string_id = FMGR_FS_PARAM_ERROR_TEXT;
                break;
            case MMI_KARAOKE_ERR_INVALID_FILENAME:
                string_id = STR_GLOBAL_INVALID_FILENAME;
                event_type = MMI_EVENT_ERROR;
                break;
            case MMI_KARAOKE_ERR_EMPTY_FILENAME:
                string_id = STR_GLOBAL_PLEASE_INPUT_THE_FILENAME;
				event_type = MMI_EVENT_ERROR;
                break;
            case MMI_KARAOKE_ERR_CREATE_FAILED:
                string_id = STR_ID_KARAOKE_ERR_CREATE_FAILED;
                break;
            case MMI_KARAOKE_ERR_EXIST_FILE:
                string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
				event_type = MMI_EVENT_ERROR;
                break;
            case MMI_KARAOKE_ERR_NO_SPACE:
                string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case MMI_KARAOKE_ERR_LIST_DAMAGED:
                string_id = STR_ID_KARAOKE_ERR_DAMAGED;
                break;
            case MMI_KARAOKE_ERR_OPEN_FAILED:
                string_id = STR_ID_KARAOKE_ERR_OPEN_FAILED;
                break;
			case MMI_KARAOKE_ERR_INVALID_FORMAT:
				string_id = STR_GLOBAL_INVALID_FORMAT;
				break;
            default:
                string_id = STR_ID_KARAOKE_ERR_UNKNOWN_ERROR;
                break;        
        }
    }


    if (callback)
    {
        do {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            arg.callback = mmi_alert_normal_exit_helper;
	        arg.parent_id = GRP_ID_ROOT; 
            arg.user_tag = (void *)(callback);
            mmi_popup_display_ext(
                string_id, 
                event_type, 
                &arg);
        } while(0);            

    }
    else
    {
        mmi_popup_display_ext(
            string_id, 
            event_type, 
            NULL);
    }

    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
    }
    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_extract_filename(UI_string_type filename, const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_ptr == NULL)
    {
        *filename = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_check_filename_len
 * DESCRIPTION
 *  check if filename is longer than we can sustain
 * PARAMETERS  
 *  fullfilename        [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_check_filename_len(const UI_string_type fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ch = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = mmi_ucs2rchr((CHAR*)fullfilename, (U16)(L'\\'));

    if (ch == NULL)
    {
        return MMI_FALSE;
    }
    
    if (mmi_ucs2strlen((CHAR*)(ch + 2)) > SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* dot = NULL;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS)));
    size = MAX_SUBMENU_CHARACTERS;
#else
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN)));
    size = MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN;
#endif 
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot && ((kal_wstrlen(filename)-kal_wstrlen(dot)) < size))
    {
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename_without_ext, (U16)L'.');
    if (dot)
    {
        *dot = 0;
    }
    }
    
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot == NULL)
    {
        *ext = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)ext, (CHAR*)(dot + 1), SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_lookup_audio_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_lookup_audio_file_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return -1;
    }
    /* skip ".". */
    {
        CHAR* dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
        if (dot)
        {
            dot += 2;
        }
        else
        {
            dot = (CHAR*)ext;
        }
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        ext_len = mmi_ucs2strlen((CHAR*)dot);
    }
    
    for (i = 0; i < karaoke_audio_file_exts[i][0]; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)karaoke_audio_file_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)karaoke_audio_file_exts[i]))
            {   
                return i;
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_search_continue_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_karaoke_list_search_continue_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_search_continue_req_struct *req_param_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_param_ptr = (mmi_karaoke_search_continue_req_struct*) construct_local_para(sizeof(mmi_karaoke_search_continue_req_struct), TD_CTRL);
    req_param_ptr->context = NULL;
    msg_send5(MOD_MMI, MOD_MMI, MMI_MMI_SAP, (msg_type)MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ, (local_para_struct*)req_param_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_forwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_forwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 return_value = 0;
    FS_DOSDirEntry file_info;
    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    U16 counter = 0;
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
        /* for a short variable name. */
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(this->stack_index < MMI_KARAOKE_MAX_DEPTH_DIRECTORY);
    if (!this->stack[this->stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
        mmi_karaoke_list_search_continue_req();
        return;
    }
    else if (this->stack[this->stack_index].total_sub_folder == 
                                this->stack[this->stack_index].index)
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
        mmi_karaoke_list_search_continue_req();
        return;
    }
    else    /* need forwards. */
    {
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)this->path_cache);
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");

        file_handle = FS_FindFirstN(
                        (PU16)temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        this->stack[this->stack_index].fs_index,
                        FS_FIND_DEFAULT);
        if (file_handle >= 0)
        {
            do
            {
                counter++;
                /* test if pass the filter */
                if (file_info.Attributes & FS_ATTR_DIR)
                {
                    /* check path length. */                    
                    path_length = mmi_ucs2strlen((CHAR*)this->path_cache);
                    sub_folder_length = mmi_ucs2strlen((CHAR*)buf_file_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;
                    if (total_length > (SRV_FMGR_PATH_MAX_LEN - 6))
                    {
                    // TODO: too long path, add trace.
                    	FS_FindClose(file_handle);
                        this->stack[this->stack_index].fs_index += counter;
                        this->stack[this->stack_index].index++;
                    }
                    else 
                    {
                        if ((this->stack_index + 1) < MMI_KARAOKE_MAX_DEPTH_DIRECTORY)
                        {
	                        mmi_ucs2cat((CHAR*)buf_file_name, (CHAR*)L"\\");
                        	if (mmi_ucs2cmp((CHAR*)MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH, (CHAR*)buf_file_name) != 0)
                        	{
                    			FS_FindClose(file_handle);
	                            /* compose next level path. */
	                            mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)buf_file_name);
	                            //mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)L"\\");

	                            /* save level node info. */
	                            this->stack[this->stack_index].fs_index += counter;
	                            this->stack[this->stack_index].index++;

	                            /* entry next level. */
	                            this->stack_index++;
	                            this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST;
	                            
	                            mmi_karaoke_list_search_continue_req();
	                            return;
                        	}
                        }
                        else /* get max depth. */
                        {
                    		FS_FindClose(file_handle);
                            /* to get next file, even have a sub-directory. */
                            this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT;

                            mmi_karaoke_list_search_continue_req();
                            return;
                        }
                    }
                }
                
                return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
            } while (return_value == FS_NO_ERROR);
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
            mmi_karaoke_list_search_continue_req();
            return;
        }
        else
        {
            if (this->stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
                }
                else
                {
                    this->last_error_code = file_handle;
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR;
                }
            }
            else
            {
                this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
            }
            mmi_karaoke_list_search_continue_req();
            return;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_backwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_backwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    CHAR* last_backlash = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (this->stack_index > 0)
    {
        memset(&(this->stack[this->stack_index]), 0, 
                    sizeof(mmi_karaoke_list_stack_node_struct));
        /* update path cache. */
        last_backlash = mmi_ucs2rchr((CHAR*)this->path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (this->phase == MMI_KARAOKE_GENERATE_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((CHAR*)this->path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)L"\\");
        this->stack_index--;
        this->phase = MMI_KARAOKE_GENERATE_PHASE_FORWARDS;
    }
    else
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_FINISH;
    }
    mmi_karaoke_list_search_continue_req();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    mmi_karaoke_list_struct * list = &(g_karaoke_cntx.current_list);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SEARCH_FINISH, 100);
    MMI_ASSERT(this->stack_index == 0);

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }
    FS_Close(this->generate_handle);
    FS_Close(list->fs_hdlr);
    
    if (this->appended_number)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
        {
            mmi_frm_scrn_clean_gui_buf(GRP_ID_KARAOKE_SONG_LIST, SCR_ID_KARAOKE_SONG_LIST);
            mmi_frm_scrn_clean_gui_buf(GRP_ID_KARAOKE_RECORD_LIST, SCR_ID_KARAOKE_RECORD_LIST);
            mmi_frm_scrn_close(GRP_ID_KARAOKE_WAITSCREEN,SCR_ID_KARAOKE_WAITSCREEN);
        }
        
        if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_WAITSCREEN,SCR_ID_KARAOKE_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
        }

        if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
        {
	        U16 pop_str[100];
	        kal_wsprintf(pop_str, "%d %w", this->appended_number, GetString(STR_ID_KARAOKE_SONG_ADDED));
        	mmi_popup_display(
                        (WCHAR*)pop_str, 
                        MMI_EVENT_INFO,
                        NULL);
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
        {
            mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
            mmi_frm_scrn_close(GRP_ID_KARAOKE_WAITSCREEN,SCR_ID_KARAOKE_WAITSCREEN);
           
        }
         if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_WAITSCREEN,SCR_ID_KARAOKE_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_error_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    mmi_karaoke_list_struct * list = &(g_karaoke_cntx.current_list);
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SEARCH_FINISH, 200);
    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }

    FS_Close(this->generate_handle);
    FS_Close(list->fs_hdlr);
       
    ret = this->last_error_code;
        
    if (ret < MMI_KARAOKE_NO_ERROR)
    {
    	if (ret == FS_NO_MORE_FILES)
    	{
    	    if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_WAITSCREEN)
    	    {
                mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
              
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
    	    {
                    mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);

                }
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);

                }
            }
    	}
    	else
        {   
            if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_WAITSCREEN)
            {
    	        mmi_karaoke_display_popup(ret, NULL);
                if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_SONG_LIST,SCR_ID_KARAOKE_SONG_LIST,MMI_FRM_NODE_ALL_FLAG))
                {
                    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
                    }
                     
                    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
                }
                else if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_RECORD_LIST,SCR_ID_KARAOKE_RECORD_LIST,MMI_FRM_NODE_ALL_FLAG))
                {
                    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
                    }
                     
                    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
                }
                else if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE,SCR_ID_KARAOKE_MAIN,MMI_FRM_NODE_ALL_FLAG))
                {
                    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
                    }

                    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
                    mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST);
                    mmi_frm_group_close(GRP_ID_KARAOKE_RECORD_LIST);
                }
                else
                {
                    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
                    }
                }
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
                }
            }
    	}
    }
    
    if (this->appended_number && g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
    {
        U16 pop_str[100];
        kal_wsprintf(pop_str, "%d %w", this->appended_number, GetString(STR_ID_KARAOKE_SONG_ADDED));
    	mmi_popup_display(
                    (WCHAR*)pop_str, 
                    MMI_EVENT_INFO,
                    NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_write_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_karaoke_list_generate_write_to_file(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size = 0;
    S32 ret = MMI_KARAOKE_NO_ERROR;
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (is_short)
    {
        MMI_KARAOKE_MARK_SNAME(path);
    }
    else
    {
        MMI_KARAOKE_MARK_LNAME(path);
    }
    
    ret = FS_Write(this->generate_handle, path, MMI_KARAOKE_LIST_RECORD_SIZE, &write_size);

    if (ret < FS_NO_ERROR)
    {
        return ret;
    }
    else if (write_size != MMI_KARAOKE_LIST_RECORD_SIZE)
    {
        ret = MMI_KARAOKE_ERR_WRITE_FAILED;
    }
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate(UI_string_type fullPath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    CHAR* last_backlash = NULL;
#ifdef __DRM_V02__
    CHAR* ext = NULL;
#endif
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    mmi_karaoke_list_struct * list = &(g_karaoke_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }
    FS_Close(this->generate_handle);
    FS_Close(list->fs_hdlr);
	
    if (fullPath == NULL)
    {
        mmi_karaoke_list_reload();
        
        if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
        return;
    }
    
    if (fullPath[0] != (CHAR)g_karaoke_cntx.current_list.present_list)
    {
        mmi_popup_display_ext(
            STR_ID_KARAOKE_FILE_IN_DIFFERENT_STORAGE, 
            MMI_EVENT_ERROR, 
            NULL);
        
        mmi_karaoke_list_reload();
        
        if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION); 

        return;
    }

    if (g_karaoke_cntx.current_list.list_data.total >= MMI_KARAOKE_MAX_LIST_ITEM)
    {
        mmi_popup_display_ext(
            STR_ID_KARAOKE_ERR_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        
        mmi_karaoke_list_reload();

        if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION); 
        
        return;
    }
    
#ifdef __DRM_V02__
    if (NULL != (ext = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((CHAR*)ext, 
            (CHAR*)L".odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            if (DRM_is_archive(0, (PU16)fullPath))
            {
                is_multi_part_odf = MMI_TRUE;
            }
            else 
            {
                is_multi_part_odf = MMI_FALSE;
            }             
        }
    }
    else
    {
        is_multi_part_odf = MMI_FALSE;
    }
#else
    is_multi_part_odf = MMI_FALSE;
#endif  /* __DRM_V02__ */   

    /* the last character will be '\\' if the path got from filemgr is a folder. */
    last_backlash = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'\\');

    if (2 > mmi_ucs2strlen((CHAR*)last_backlash) || is_multi_part_odf)
    {
        /* 
        ** the backlash is the last character of this path. 
        ** so this is a folder path.
        */
        ret = mmi_karaoke_list_check_and_set_default_path(
                   g_karaoke_cntx.current_list.path, (CHAR)g_karaoke_cntx.current_list.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_karaoke_display_popup(ret, NULL);
            
            mmi_karaoke_list_reload();
            
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            return;
        }
        /* generater need playlist file's handle. */
        ret = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);
        if (ret < 0)
        {
            mmi_karaoke_display_popup(ret, NULL);
            
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
        }
        else
        {
            g_karaoke_cntx.current_list.fs_hdlr = ret;
            ret = FS_Seek(ret, g_karaoke_cntx.current_list.list_data.total * MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                mmi_karaoke_display_popup(ret, NULL);
                
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
                }
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }
            else
            {
                mmi_karaoke_list_generate_from_folder(fullPath, is_multi_part_odf);
            }
        }
    }
    else
    {
        ret = mmi_karaoke_list_check_and_set_default_path(
                   g_karaoke_cntx.current_list.path, (CHAR)g_karaoke_cntx.current_list.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_karaoke_display_popup(ret, NULL);
            mmi_karaoke_list_reload();

            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            return;
        }
    
        /* it is a file. append to playlist directly. */
        ret = mmi_karaoke_list_generate_append_one(fullPath, (MMI_BOOL)is_short);
        if (ret >= FS_NO_ERROR)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                NULL);
        }
        else if (ret == MMI_KARAOKE_ERR_INVALID_FORMAT)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_INVALID_FORMAT, 
                MMI_EVENT_FAILURE, 
                NULL);
        }
        else
        {
            mmi_karaoke_display_popup(ret, NULL);
            mmi_karaoke_list_reload();

            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_SONG_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_append_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_karaoke_list_generate_append_one(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size = 0;
    FS_HANDLE fd = -1;
    S32 result = 0;
    S32 write_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (path[0] != 0)
	{
	    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
		UI_character_type filename_without_ext[SRV_FMGR_PATH_MAX_LEN + 1];
		MMI_BOOL found = MMI_FALSE;
    	U8 i;
		U8 cannot_do_record_array_size = sizeof(karaoke_audio_pattern_array) / sizeof(FS_Pattern_Struct);
		
	    mmi_karaoke_split_filename_ext(path, filename_without_ext, ext);

		for (i = 0; i < cannot_do_record_array_size; i++)
		{
			if (mmi_ucs2cmp((CHAR*)(karaoke_audio_pattern_array[i].Pattern+2), (CHAR*)app_ucs2_strtolower((kal_wchar*)ext)) == 0)
			{
				found = MMI_TRUE;
				break;
			}
		}
		
		if (!found)
		{
		    return MMI_KARAOKE_ERR_INVALID_FORMAT;
		}		
	}
	
    /* we are goign to mark L or S in drive char */
    if (is_short)
    {
        MMI_KARAOKE_MARK_SNAME(path);  /* mark short name */
    }
    else
    {
        MMI_KARAOKE_MARK_LNAME(path);  /* mark long name */
    }
    
    if ((fd = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN)) >= 0)
    {
        if ((write_result = FS_Seek(fd, g_karaoke_cntx.current_list.list_data.total * MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN)) >= FS_NO_ERROR)
        {
            if ((write_result = FS_Write(fd, path, MMI_KARAOKE_LIST_RECORD_SIZE, &size)) >= FS_NO_ERROR)
            {
                g_karaoke_cntx.current_list.list_data.total++;
            }
        }
        
        result = write_result;
        FS_Close(fd);
    }
    else
    {
        result = fd;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_append_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    mmi_karaoke_list_struct* list = &(g_karaoke_cntx.current_list);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SEARCH_FINISH, 300); 
    ClearProtocolEventHandler(MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }

    FS_Close(this->generate_handle);
    FS_Close(list->fs_hdlr);
    
    list->list_data.total = this->total_number;
    
    mmi_karaoke_list_reload();

    if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_WAITSCREEN)    /* user press cancel in wait screen. */
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
    }
    else if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_WAITSCREEN, SCR_ID_KARAOKE_WAITSCREEN, MMI_FRM_NODE_ALL_FLAG))     /* USB plug-in in generate process */
    {
        /* wait screen in history. need delete it. */
        if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN))
        {
            mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
        }
    }
    if (this->appended_number && g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
    {
        U16 pop_str[100];
        kal_wsprintf(pop_str, "%d %w", this->appended_number, GetString(STR_ID_KARAOKE_SONG_ADDED));
    	mmi_popup_display(
                    (WCHAR*)pop_str, 
                    MMI_EVENT_INFO,
                    NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_from_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    mmi_karaoke_list_struct* list = &(g_karaoke_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* init generate variables. */
    memset(this, 0, sizeof(mmi_karaoke_list_generate_struct));   
    
    this->footer_pattern_offset = list->list_data.total * MMI_KARAOKE_LIST_RECORD_SIZE;
    this->generate_handle = list->fs_hdlr;
    this->appended_number = 0;
    this->total_number = list->list_data.total;
    this->last_error_code = 0;
    this->search_handle = -1;
    
    if (is_multi_part_odf)
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_ODF;
    }
    else
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST;
        this->stack_index = 0;
        memset((this->stack), 0, MMI_KARAOKE_MAX_DEPTH_DIRECTORY * sizeof(mmi_karaoke_list_stack_node_struct));
    }
    
    mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)path);
    
    SetProtocolEventHandler(mmi_karaoke_list_generate_internal, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);

    /* entry wait screen. */
    mmi_karaoke_wait_screen_entry();
    
    StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER, 50, mmi_karaoke_list_generate_internal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_GENERATE_INTERNAL, g_karaoke_cntx.generate_info.phase);
	
    if (mmi_frm_group_get_active_id() != GRP_ID_KARAOKE_WAITSCREEN)
    {
        /* Sleep if the waitting screen has been in history. */
        StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER, 500, mmi_karaoke_list_generate_internal);
        return;
    }
    
    switch (g_karaoke_cntx.generate_info.phase)
    {
        case MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST:
            mmi_karaoke_list_generate_search();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT:
            mmi_karaoke_list_generate_search();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_FORWARDS:
            mmi_karaoke_list_generate_forwards();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_BACKWARDS:
        case MMI_KARAOKE_GENERATE_PHASE_BACKWARDS_ODF:
            mmi_karaoke_list_generate_backwards();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_FINISH:
            mmi_karaoke_list_generate_finish();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR:
            mmi_karaoke_list_generate_error_hdlr();
            return;
        case MMI_KARAOKE_GENERATE_PHASE_CANCEL:
            mmi_karaoke_list_generate_cancel_hdlr();
            return;        
        case MMI_KARAOKE_GENERATE_PHASE_SEARCH_ODF:
        #ifdef __DRM_V02__
            mmi_karaoke_list_generate_search_odf();
        #endif  /* __DRM_V02__ */
            return;
        default: 
            MMI_ASSERT(g_karaoke_cntx.generate_info.phase <= MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_generate_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_generate_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ret = FS_NO_ERROR;
    FS_DOSDirEntry file_info;
	MMI_BOOL song_added = MMI_FALSE;

    UI_character_type buf_file_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_shortname = MMI_FALSE;
    mmi_karaoke_list_generate_struct* this = &(g_karaoke_cntx.generate_info);
    U8 pattern_array_size = sizeof(karaoke_audio_pattern_array) / sizeof(FS_Pattern_Struct);
    
#ifdef __DRM_V02__
    UI_character_type odf_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
    MMI_BOOL add_audio = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)file_path, (CHAR*)this->path_cache);
    mmi_ucs2cat((CHAR*)file_path, (CHAR*)L"*.*");
    
    if (this->phase == MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST)
    {
        if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
        {//song list will add pattern to catch audio file who can do karaoke
            ret = FS_FindFirstN(
                    (PU16)file_path,
                    karaoke_audio_pattern_array,
                    pattern_array_size,
                    FS_ATTR_DIR,    /* only search media files in this phase. */
                    0,
                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                    &file_info,
                    (PU16)buf_file_name,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    0,
                    FS_FIND_DEFAULT);
        }
        else
        {
            ret = FS_FindFirstN(
                    (PU16)file_path,
                    NULL,
                    0,
                    FS_ATTR_DIR,    /* only search media files in this phase. */
                    0,
                    FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                    &file_info,
                    (PU16)buf_file_name,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    0,
                    FS_FIND_DEFAULT);
        }
        
        if (ret >= 0)
        {
            this->search_handle = ret;
            this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (this->stack_index < MMI_KARAOKE_MAX_DEPTH_DIRECTORY)
            {
                this->stack[this->stack_index].level = this->stack_index;
                this->stack[this->stack_index].total_sub_folder = 0;
                this->stack[this->stack_index].index = 0;
                this->stack[this->stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(this->stack_index < MMI_KARAOKE_MAX_DEPTH_DIRECTORY);
            }
        }
        else
        {
            if (this->stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
                }
                else
                {
                    this->last_error_code = ret;
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR;
                }
            }
            else
            {
                this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
            }
            mmi_karaoke_list_search_continue_req();
            return;
        }
    }
    else if (this->phase == MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT)
    {
        if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
        {//song list will add pattern to catch audio file who can do karaoke
            ret = FS_FindNextN(
                            this->search_handle,
                            karaoke_audio_pattern_array,
                            pattern_array_size,
                            FS_ATTR_DIR,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        }
        else
        {
            ret = FS_FindNextN(
                            this->search_handle,
                            NULL,
                            0,
                            FS_ATTR_DIR,
                            &file_info,
                            (PU16)buf_file_name,
                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                            FS_FIND_DEFAULT);
        }
        if (ret < 0)
        {
            FS_FindClose(this->search_handle);
            this->search_handle = -1;
            if (ret == FS_NO_MORE_FILES)
            {
                if (!this->stack[this->stack_index].total_sub_folder)
                {
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
                }
                else
                {
                    if (this->stack_index < MMI_KARAOKE_MAX_DEPTH_DIRECTORY)
                    {
                        this->phase = MMI_KARAOKE_GENERATE_PHASE_FORWARDS;
                    }
                    else
                    {
                        this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
                    }
                }
            }
            else
            {
                if (this->stack_index == 0)
                {
                    this->last_error_code = ret;
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR;
                }
                else
                {
                    this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
                }
            }
            mmi_karaoke_list_search_continue_req();
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(this->phase == MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT ||
                   this->phase == MMI_KARAOKE_GENERATE_PHASE_SEARCH_FIRST);
    }
    
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            is_shortname = (MMI_BOOL)((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] == L' ')
                    {
                        break;
                    }
                    file_ext[j] = (UI_character_type) file_info.Extension[j];
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR* ext = mmi_ucs2rchr((CHAR*)buf_file_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)ext, mmi_ucs2strlen((CHAR*)ext));
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }

            if (mmi_karaoke_lookup_audio_file_format(file_ext) >= 0)
            {
            #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((CHAR*)file_ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)file_ext)))
                {
                    add_audio = MMI_FALSE;
                    mmi_ucs2cpy((CHAR*)odf_path, (CHAR*)this->path_cache);
                    mmi_ucs2cat((CHAR*)odf_path, (CHAR*)buf_file_name);
                    
                    if (!DRM_is_archive(0, (PU16)odf_path))
                    {
                        ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                        if (ext_name_p != NULL)
                        {
                            mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));
                            ext_in_odf[strlen((const char *)ext_name_p)] = 0;
                            if (mmi_karaoke_lookup_audio_file_format(ext_in_odf) >= 0)
                            {
                                add_audio = MMI_TRUE;
                            }
                            else
                            {
                                add_audio = MMI_FALSE;
                            }
                        }
                        else
                        {
                            file_ext[0] = 0;
                        }
                    }
                    else
                    {
                        mmi_ucs2ncpy((CHAR*)this->path_cache, (CHAR*)odf_path, (SRV_FMGR_PATH_MAX_LEN+1));
                        this->stack_index++;
                        this->phase = MMI_KARAOKE_GENERATE_PHASE_SEARCH_ODF;
                        mmi_karaoke_list_search_continue_req();
                        return;
                    }
                }
                else
                {
                    add_audio = MMI_TRUE;
                }
                if (add_audio)
            #endif  /* __DRM_V02__ */
                {
                    if (mmi_ucs2strlen((CHAR*)this->path_cache) + 
                        mmi_ucs2strlen((CHAR*)buf_file_name) <= (SRV_FMGR_PATH_MAX_LEN+1))
                    {
                        mmi_ucs2cpy((CHAR*)file_path, (CHAR*)this->path_cache);
                        mmi_ucs2cat((CHAR*)file_path, (CHAR*)buf_file_name);

                        if (this->total_number < MMI_KARAOKE_MAX_LIST_ITEM)
                        {
                            MMI_BOOL is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
                            /* add media file data to data file. */  
                            ret = mmi_karaoke_list_generate_write_to_file(file_path, is_short);
                            
                            if (ret < 0)
                            {
                                FS_FindClose(this->search_handle);
                                this->search_handle = -1;
                                this->last_error_code = ret;
                                this->phase = MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR;
                                mmi_karaoke_list_search_continue_req();
                                return;
                            }
                            else
                            {
								song_added = MMI_TRUE;
                                this->appended_number++;
                                this->total_number++;
                                MMI_ASSERT(this->total_number <= MMI_KARAOKE_MAX_LIST_ITEM);
	                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SEARCH, this->total_number);
                            }
                        }
                        else
                        {
                            FS_FindClose(this->search_handle);
                            this->search_handle = -1;
                            this->last_error_code = MMI_KARAOKE_ERR_LIST_FULL;
                            this->phase = MMI_KARAOKE_GENERATE_PHASE_ERR_HDLR;
                            mmi_karaoke_list_search_continue_req();
                            return;                    
                        }
                    }
                }
            }
        }
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((CHAR*)buf_file_name) < 3)
            {
                if (mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".") &&
                    mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".."))
                {
                    this->stack[this->stack_index].total_sub_folder++;
                }
            }
            else
            {
                this->stack[this->stack_index].total_sub_folder++;
            }
        }

		if (song_added && this->total_number >= MMI_KARAOKE_LIST_SEARCH_LIMIT_IN_LOOP && (this->total_number % MMI_KARAOKE_LIST_SEARCH_LIMIT_IN_LOOP) == 0)
		{
			song_added = MMI_FALSE;
			StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
			this->phase == MMI_KARAOKE_GENERATE_PHASE_SEARCH_NEXT;
			StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER, MMI_KARAOKE_LIST_SEARCH_LOOP_TIMER, mmi_karaoke_list_generate_internal);
			return;
		}
		else
		{
	        if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
	        {//song list will add pattern to catch audio file who can do karaoke
	            ret = FS_FindNextN(
	                            this->search_handle,
	                            karaoke_audio_pattern_array,
	                            pattern_array_size,
	                            FS_ATTR_DIR,
	                            &file_info,
	                            (PU16)buf_file_name,
	                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
	                            FS_FIND_DEFAULT);
	        }
	        else
	        {
	            ret = FS_FindNextN(
	                            this->search_handle,
	                            NULL,
	                            0,
	                            FS_ATTR_DIR,
	                            &file_info,
	                            (PU16)buf_file_name,
	                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
	                            FS_FIND_DEFAULT);
	        }
		}
    } while (ret == FS_NO_ERROR);
    FS_FindClose(this->search_handle);
    FS_Commit(this->generate_handle);
    this->search_handle = -1;
    if (this->stack_index < MMI_KARAOKE_MAX_DEPTH_DIRECTORY)
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_FORWARDS;
    }
    else
    {
        this->phase = MMI_KARAOKE_GENERATE_PHASE_BACKWARDS;
    }
    mmi_karaoke_list_search_continue_req();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_auto_generate
 * DESCRIPTION
 *  auto gen will clear previous list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_auto_generate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[SRV_FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE fd = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_GENERATE_TRACE, 100);
    g_karaoke_cntx.record_auto_gen = MMI_TRUE;
	if (!mmi_karaoke_is_dev_ready(MMI_TRUE))
	{
		mmi_frm_group_close(GRP_ID_KARAOKE);
		return;
	}
    mmi_karaoke_list_remove_all();
    kal_wsprintf(temp_path, "%c:\\", (CHAR)g_karaoke_cntx.current_list.present_list);
    if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)MMI_KARAOKE_SONG_LIST_DEFAULT_PATH);
    else
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH);

	if ((fd = FS_Open(temp_path, FS_READ_ONLY)) >= FS_NO_ERROR)
	{
		FS_Close(fd);
    	mmi_karaoke_list_generate(temp_path, MMI_FALSE);
	}
	else
	{
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_is_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_list_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U16 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    do 
    {
        ret = FS_GetAttributes((PU16)g_karaoke_cntx.current_list.path);
        
        if (i > 30)
        {
            break;
        }
        else
        {
            i++;
        }
    } while (ret == FS_DEVICE_BUSY);
    
    if (0 > ret)
    {
        g_karaoke_cntx.current_list.list_loaded = MMI_FALSE;
    }
    else
    {
        g_karaoke_cntx.current_list.list_loaded = MMI_TRUE;
    }

    return g_karaoke_cntx.current_list.list_loaded;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_list_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_karaoke_list_is_valid())
    {
        if (g_karaoke_cntx.current_list.list_data.total > 0)
        {
            ret = MMI_FALSE;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item
 * RETURNS
 *  U16
 *****************************************************************************/
static S32 mmi_karaoke_list_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_karaoke_list_is_empty())
    {
        return 0;
    }
    else
    {
        return g_karaoke_cntx.current_list.list_data.total;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_current_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_get_current_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_karaoke_list_is_empty())
    {
        return -1;
    }
    else
    {
        return g_karaoke_cntx.current_list.list_data.highlight;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.current_list.list_data.highlight = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&(g_karaoke_cntx.current_list.list_data), 0, sizeof(mmi_karaoke_dynamic_list_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_list
 * DESCRIPTION
 *  read song list to cache.
 * PARAMETERS
 *  cached_num      [OUT]
 *  start_index     [IN]
 * RETURNS
 *  S32     loaded item number/error code
 *****************************************************************************/
static S32 mmi_karaoke_list_get_list(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U32 read_size = 0;
    UI_character_type *ucs2_buff = NULL;
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE fd = -1;
    mmi_karaoke_dynamic_list_data_struct* list = &(g_karaoke_cntx.current_list.list_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_ONLY);
    
    if (fd >= 0)
    {
    	ucs2_buff = (UI_character_type*) OslMalloc((MMI_KARAOKE_LIST_RECORD_SIZE + 1));
        if (FS_Seek(fd, start_index * MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            while (count < MMI_KARAOKE_LIST_BUFF_SIZE && start_index < list->total)
            {
                FS_Read(fd, ucs2_buff, MMI_KARAOKE_LIST_RECORD_SIZE, &read_size);
                if (read_size < MMI_KARAOKE_LIST_RECORD_SIZE)
                {
                    break;
                }
                /* load filename to play list buffer */
                ucs2_buff[MMI_KARAOKE_EOS(read_size)] = 0;   /* make it must be in boundary */
                if (!mmi_karaoke_check_filename_len(ucs2_buff))
                {
                    continue;
                }
                if (MMI_KARAOKE_IS_SNAME(ucs2_buff))
                {
					CHAR* dot = NULL;
                    mmi_karaoke_extract_filename(filename, ucs2_buff);
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*)list->cache[count].filename,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        (U8*)filename,
                        g_chset_text_encoding);
                    dot = mmi_ucs2rchr((CHAR*)list->cache[count].filename, (U16)L'.');
                    if (dot == NULL)
                    {
                        dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                        if (dot != NULL)
                        {
                            mmi_ucs2ncat((CHAR*)list->cache[count].filename, (CHAR*)(dot), 4);
                        }
                    }
                }
                else
                {
                    mmi_karaoke_extract_filename(list->cache[count].filename, ucs2_buff);
                }
                start_index++;
                count++;
            }
        }
        
	    OslMfree(ucs2_buff);
        FS_Close(fd);
        *cached_num = count;
        return count;
    }
    else 
    {
        return fd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_load_cache
 * DESCRIPTION
 *  load song list to buffer
 * PARAMETERS      
 *  start_index           [IN]
 *  item
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_karaoke_list_load_cache(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    S32 ret = FS_NO_ERROR;
    mmi_karaoke_dynamic_list_data_struct* list = &(g_karaoke_cntx.current_list.list_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    /* init some value */
    list->cache_start_index = start_index;

    for (i = 0; i < MMI_KARAOKE_LIST_BUFF_SIZE; i++)
    {
        list->cache[i].filename[0] = 0;
        list->cache[i].ext[0] = 0;
        list->cache[i].file_type = 0;
        list->cache[i].is_short = 0;
    }
   
    ret = mmi_karaoke_list_get_list(&cache_index, start_index);

    if (ret < 0)
    {
        /* error caught. */
        return ret;
    }
    else
    {
        list->cache_start_index = start_index;
        list->cache_end_index = start_index + cache_index;
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_song_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]
 *  fullfilename         [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_get_song_path(S32 item_index, UI_string_type fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;
    U32 read_size;
    FS_HANDLE fd;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_ONLY);
    
    if (ret >= FS_NO_ERROR)
    {
        fd = ret;
        if ((ret = FS_Seek(fd, item_index * MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN)) >= FS_NO_ERROR)
        {
            if ((ret = FS_Read(fd, fullfilename, MMI_KARAOKE_LIST_RECORD_SIZE, &read_size)) >= FS_NO_ERROR)
            {
                if (read_size > 0)
                {
                    MMI_KARAOKE_MARK_DRIVE(fullfilename);
                    fullfilename[MMI_KARAOKE_EOS(read_size)] = 0;    /* make it must be in boundary */
                }
            }
        }
        FS_Close(fd);
    }

    if (ret < FS_NO_ERROR)
    {
        fullfilename[0] = 0;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [OUT]        
 *  img_buff_p          [OUT]         
 *  str_img_mask        [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 file_ext_index;
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    mmi_karaoke_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_karaoke_dynamic_list_data_struct* list = &(g_karaoke_cntx.current_list.list_data);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((item_index < list->cache_start_index) ||
        (item_index >= list->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MMI_KARAOKE_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        if (0 > mmi_karaoke_list_load_cache(load_index))
        {
        	mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
            
            return MMI_TRUE;
        }
    }
    current = item_index - list->cache_start_index;
    memcpy(&item_info, 
            &(list->cache[current]), 
            sizeof(mmi_karaoke_list_item_info_struct));
    
    mmi_karaoke_split_filename_ext(item_info.filename, str_buff, ext);

    *img_buff_p = (PU8) GetImage(IMG_ID_KARAOKE_FILE_ICON);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        mmi_karaoke_list_get_item(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
    }
    
    return num_item;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_get_hint_async(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_karaoke_dynamic_list_data_struct* list = &(g_karaoke_cntx.current_list.list_data);
	UI_character_type filepath[(SRV_FMGR_PATH_MAX_LEN+1) + 1] = {0};
	UI_character_type time_str[20];
    U32 duration;
    U8 hour, min, sec;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    if (item_index >= list->cache_start_index && item_index < list->cache_end_index)
    {
	    kal_wsprintf(
            (WCHAR*)filepath,
            "%c:\\%w%w",
            MMI_KARAOKE_DEFAULT_DRV,
            MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH,
            list->cache[item_index-list->cache_start_index].filename);
    
        mdi_audio_get_duration((void *)filepath, &duration);
        
        hour = duration / 3600000;
        duration -= hour * 3600000;
        min = duration / 60000;
        duration -= min * 60000;
        sec = duration / 1000;
        if (hour > 0)
        {
            kal_wsprintf((WCHAR*)hint_array[0], "%02d:%02d:%02d", hour, min, sec);
        }
        else
        {
            kal_wsprintf((WCHAR*)hint_array[0], "%02d:%02d", min, sec);
        }
    }
    else
    {
        //not in cache
        kal_wsprintf((WCHAR*)hint_array[0], "00:00");
    }
    
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_add_file_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullPath        [IN]
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_add_file_hdlr(UI_string_type fullPath, int is_short)
{
    mmi_karaoke_list_generate(fullPath, is_short);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_fmgr_file_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[SRV_FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                SRV_FMGR_PATH_BUFFER_SIZE);
        
        mmi_karaoke_list_add_file_hdlr(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
    #if defined(__USB_IN_NORMAL_MODE__)
	    if (!srv_usb_is_in_mass_storage_mode())
		    	    
    #endif /* defined(__USB_IN_NORMAL_MODE__) */ 
	   {
	        mmi_popup_display_ext(
	            (srv_fmgr_fs_error_get_string(file_select->result)), 
	            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_select->result), 
	            NULL);
		}	       
        cui_file_selector_close(file_select->sender_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_check_and_set_default_path
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  file_path       [OUT]
 *  driver_letter   [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_check_and_set_default_path(UI_string_type file_path, CHAR driver_letter)
{
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = FS_NO_ERROR;

    kal_wsprintf(path, "%c:\\", (CHAR)driver_letter);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_KARAOKE_LIST_DEFAULT_FOLDER);
    /* check default playlist fodler. */
    ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (ret < FS_NO_ERROR)
    {
        if (ret == FS_FAT_ALLOC_ERROR)
        {
            return ret;
        }
        
        ret = FS_CreateDir(path);
        if (FS_FILE_EXISTS == ret)
        {
            ret = -1;
        }
        else if(FS_NO_ERROR > ret)
        {
            return ret;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
			FS_Close(ret);
            ret = -1;
        }
    }
    else
    {
        FS_Close(ret);
        ret = -1;
    }
    /* always set default playlist folder as hidden. */
    //FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
        mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_KARAOKE_SONG_LIST_DEFAULT_NAME);
    else
        mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_KARAOKE_RECORD_LIST_DEFAULT_NAME);

    mmi_ucs2ncpy((CHAR*)file_path, (CHAR*)path, (SRV_FMGR_PATH_MAX_LEN+1));
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_reload
 * DESCRIPTION
 *  
 * PARAMETERS  
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
static S32 mmi_karaoke_list_reload(void)
{
    S32 i = 0;
    S32 ret = 0, fs_ret;
    U32 read_size = 0, file_size;
    FS_HANDLE fd = -1;
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*config present play list path*/
    ret = mmi_karaoke_list_check_and_set_default_path(
                g_karaoke_cntx.current_list.path, (CHAR)g_karaoke_cntx.current_list.present_list);
    
    if (ret < FS_NO_ERROR)
    {
        return ret;
    }

	ret = FS_GetAttributes(g_karaoke_cntx.current_list.path);

    if (ret < 0)
    {
		/* need create file. */
        fd = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_WRITE | FS_CREATE);

        if (fd < 0)
        {
			return fd;
        }
        else
        {
			FS_Close(fd);
            g_karaoke_cntx.current_list.fs_hdlr = -1;
            g_karaoke_cntx.generate_info.generate_handle = -1;
            g_karaoke_cntx.current_list.list_data.total = 0;
			return 0;
        }
    }
    else
    {
	    fd = FS_Open(g_karaoke_cntx.current_list.path, FS_READ_WRITE);
        fs_ret = FS_GetFileSize(fd, &file_size);
        if (fs_ret < FS_NO_ERROR)
        {
            return fs_ret;
        }
        else
        {            
            g_karaoke_cntx.current_list.list_data.total = file_size / MMI_KARAOKE_LIST_RECORD_SIZE;
        }

    	 if (fd >= 0)
    	 {
	        for (;
	             i < MMI_KARAOKE_MAX_LIST_ITEM &&
	             FS_Read(fd, path, MMI_KARAOKE_LIST_RECORD_SIZE, &read_size) >= FS_NO_ERROR;)
	        {
	            if (read_size < MMI_KARAOKE_LIST_RECORD_SIZE)
	            {
	                break;
	            }
	            
	            {
	                if (i < MMI_KARAOKE_LIST_BUFF_SIZE)
	    		    {
	                    /* load filename to play list buffer */
	                    path[MMI_KARAOKE_EOS(read_size)] = 0;   /* make it must be in boundary */
	                    if (!mmi_karaoke_check_filename_len(path))
	                    {
	                        continue;
	                    }
	                    if (MMI_KARAOKE_IS_SNAME(path))
	                    {
	                        mmi_karaoke_extract_filename(filename, path);
	                        mmi_chset_mixed_text_to_ucs2_str(
	                            (U8*)g_karaoke_cntx.current_list.list_data.cache[i].filename,
	                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
	                            (U8*)filename,
	                            g_chset_text_encoding);
	                    }
	                    else
	                    {
	                        mmi_karaoke_extract_filename(g_karaoke_cntx.current_list.list_data.cache[i].filename, path);
	                    }
	                }
                    else
                    {
                        break;
                    }
	                i++;
	            }
	        }
	        FS_Close(fd);

	        return g_karaoke_cntx.current_list.list_data.total;
	    }
	    else
	    {
	        return fd;
	    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_init
 * DESCRIPTION
 *  init song list
 * PARAMETERS
 *  item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_init(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_reset();
    
    g_karaoke_cntx.current_list.present_list = (U8)MMI_KARAOKE_DEFAULT_DRV;
    
    if (FS_GetDevStatus((U8)MMI_KARAOKE_DEFAULT_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        return;
    }
    
    ret = mmi_karaoke_list_reload();  
    
    if (ret < FS_NO_ERROR)
    {
        g_karaoke_cntx.current_list.list_loaded = MMI_FALSE;
        return;
    }
    g_karaoke_cntx.current_list.list_loaded = MMI_TRUE;
    g_karaoke_cntx.current_list.list_data.total = ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_usb_plug_in_hdlr
 * DESCRIPTION
 *  enter mass storage mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_usb_plug_in_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    /* USB plugin during generate. */
    if (mmi_frm_scrn_is_present(GRP_ID_KARAOKE_WAITSCREEN,SCR_ID_KARAOKE_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG) || SCR_ID_KARAOKE_WAITSCREEN == mmi_frm_scrn_get_active_id())
    {
        //StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
        mmi_karaoke_list_generate_cancel_hdlr();
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
        mmi_frm_group_close(GRP_ID_KARAOKE);
    }
	else
	{
		mmi_frm_group_close(GRP_ID_KARAOKE);
	}
	if(g_karaoke_cntx.is_playing_records || g_karaoke_cntx.is_singing)
    	mmi_karaoke_interrupt_callback(MDI_AUDIO_TERMINATED,NULL);
    g_karaoke_cntx.is_interrupted = KAL_FALSE;
    mmi_karaoke_list_reset();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_usb_plug_out_hdlr
 * DESCRIPTION
 *  exit mass storage mode
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_usb_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
	if(mmi_karaoke_is_dev_ready(MMI_FALSE) && g_karaoke_cntx.Rec_filepath[0] != NULL)
	{
	    UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
	   	mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
		FS_Delete(rec_lyricpath);
	    FS_Delete(g_karaoke_cntx.Rec_filepath);
	}
	g_karaoke_cntx.is_interrupted = KAL_FALSE;
    mmi_karaoke_list_init();
    g_karaoke_cntx.record_auto_gen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_msdc_plug_out_hdlr
 * DESCRIPTION
 *  plug-out t-card
 * PARAMETERS
 *  drv_num
 *  drv_list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    for (i = 0; i < drv_num; i++)
    {
        if ((U8)MMI_KARAOKE_DEFAULT_DRV == (U8)drv_list[i])
        {
            /* in generate process. */
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_WAITSCREEN) || SCR_ID_KARAOKE_WAITSCREEN == mmi_frm_scrn_get_active_id())
            {
                StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
                mmi_karaoke_list_generate_cancel_hdlr();

                mmi_frm_group_close(GRP_ID_KARAOKE_WAITSCREEN);
            }  
            
            StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_REMOVE_WAITSCREEN))
        	{
          	    mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
        	}
            
        	mmi_frm_group_close(GRP_ID_KARAOKE);
			if(g_karaoke_cntx.is_playing_records || g_karaoke_cntx.is_singing)
				mmi_karaoke_interrupt_callback(MDI_AUDIO_TERMINATED,NULL);
            g_karaoke_cntx.is_interrupted = KAL_FALSE;
            memset(&(g_karaoke_cntx.current_list), 0, sizeof(mmi_karaoke_list_struct));
                            
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_msdc_plug_in_hdlr
 * DESCRIPTION
 *  plug in t-card
 * PARAMETERS
 *  drv_num
 *  drv_list
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
	if(mmi_karaoke_is_dev_ready(MMI_FALSE) && g_karaoke_cntx.Rec_filepath[0] != NULL)
	{
	    UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
	   	mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
		FS_Delete(rec_lyricpath);
	    FS_Delete(g_karaoke_cntx.Rec_filepath);
	}
	g_karaoke_cntx.is_interrupted = KAL_FALSE;
    g_karaoke_cntx.record_auto_gen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_karaoke_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    //mmi_karaoke_action_enum action;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 4, event->evt_id);
    switch(event->evt_id)
    {
        #if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
        case EVT_ID_SRV_A2DP_CONNECT:
        {
            if (mmi_frm_group_get_state(GRP_ID_KARAOKE) != MMI_SCENARIO_STATE_NONE)
            {
                if(g_karaoke_cntx.is_playing_records || g_karaoke_cntx.is_singing)
                    mmi_karaoke_interrupt_callback(MDI_AUDIO_TERMINATED,NULL);
                mmi_frm_close_to_idle_group();
            }
            break;
        }
        #endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
#if 0
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
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
#endif  //__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
#endif
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT: 
        {
            srv_fmgr_notification_format_event_struct *fmgr_format
                = (srv_fmgr_notification_format_event_struct*)event;
            
            if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
            {
            }
            else if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                g_karaoke_cntx.current_list.list_loaded = MMI_FALSE;
                mmi_karaoke_list_reset();
            }
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_karaoke_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_karaoke_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount
                = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            {
                memset(&(g_karaoke_cntx.current_list), 0, sizeof(mmi_karaoke_list_struct));
                g_karaoke_cntx.current_list.list_loaded = MMI_FALSE;

                mmi_karaoke_list_reset();
            }
           
            break;

        }
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
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static MMI_BOOL mmi_karaoke_list_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    MMI_BOOL isOK = MMI_FALSE;
    mmi_karaoke_list_struct* list = &(g_karaoke_cntx.current_list);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fd = FS_Open(list->path, FS_READ_WRITE)) >= 0)
    {
        if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Truncate(fd) == FS_NO_ERROR)
            {
                list->list_data.total = 0;
                mmi_karaoke_list_reset();
                isOK = MMI_TRUE;
            }
        }
        FS_Close(fd);
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_transit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_karaoke_list_remove_transit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type file_list_buff[MMI_KARAOKE_REMOVE_BUF_SIZE];       /* use 4698 bytes (it has 5040 bytes) */
    S32 max_buff_size = 0;
    U32 read_size = 0;
    U32 write_size = 0;
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	max_buff_size = MMI_KARAOKE_REMOVE_BUF_SIZE / MMI_KARAOKE_LIST_RECORD_SIZE * MMI_KARAOKE_LIST_RECORD_SIZE;	
	do
    {
    	ret = FS_Seek(g_karaoke_cntx.current_list.remove_hdlr, g_karaoke_cntx.current_list.remove_offset + MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN);
		if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Read(g_karaoke_cntx.current_list.remove_hdlr, file_list_buff, max_buff_size, &read_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Seek(g_karaoke_cntx.current_list.remove_hdlr, g_karaoke_cntx.current_list.remove_offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Write(g_karaoke_cntx.current_list.remove_hdlr, file_list_buff, read_size, &write_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        MMI_ASSERT(read_size == write_size);
        g_karaoke_cntx.current_list.remove_offset += write_size;
    } while (0);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_list_remove_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;
    S32 count = 0;
    mmi_karaoke_list_struct* list = &(g_karaoke_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
	while (ret == FS_NO_ERROR && list->remove_count > 0)
    {
    	ret = mmi_karaoke_list_remove_transit();
		if (ret < FS_NO_ERROR)
        {
			break;
        }
        else
        {
            list->remove_count--;
            count++;
        }
    
		if (count == 19)
        {
			StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER, 100, mmi_karaoke_list_remove_one);
            return;
        }
    } 

	if (!(ret < FS_NO_ERROR))
    {
	    S32 erase_ret = FS_NO_ERROR;
        /* erase the last record */
        erase_ret = FS_Seek(list->remove_hdlr, (list->list_data.total - 1) * MMI_KARAOKE_LIST_RECORD_SIZE, FS_FILE_BEGIN);
        if (erase_ret >= 0)
        {
        	erase_ret = FS_Truncate(list->remove_hdlr);
        }
        
		if (ret < FS_NO_ERROR)
        {
			if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_REMOVE_WAITSCREEN)
			{
				mmi_karaoke_display_popup(ret, NULL);

                mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
                }
			}
			else
			{
                
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_REMOVE_WAITSCREEN))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
                }
			}
		}
        else
        {
    	    FS_Close(list->remove_hdlr);
            list->remove_hdlr = FS_MINIMUM_ERROR_CODE;
            
	        mmi_karaoke_list_reload();

            if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_REMOVE_WAITSCREEN)
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
                {
                    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
                }
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_KARAOKE_REMOVE_WAITSCREEN))
                {
                    mmi_frm_scrn_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN,SCR_ID_KARAOKE_REMOVE_WAITSCREEN);
                }
            }
	        
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_KARAOKE_REMOVE_WAITSCREEN)
        {
		    mmi_karaoke_display_popup(ret, NULL);

            mmi_frm_scrn_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN,SCR_ID_KARAOKE_REMOVE_WAITSCREEN);
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }
        }
        else
        {
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_REMOVE_WAITSCREEN))
            {
                mmi_frm_scrn_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN,SCR_ID_KARAOKE_REMOVE_WAITSCREEN);
            }            
        }
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_list_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
    	case EVT_ID_GROUP_FOCUSED:
		{
			mdi_audio_suspend_background_play();
			break;
    	}
		case EVT_ID_GROUP_DEINIT:
		{
			mdi_audio_resume_background_play();
			break;
    	}
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;            
            
            mmi_karaoke_list_fmgr_file_selector_handle(sel_evt);
            break;
        }
        default:
            break;
    
    
    }
    return MMI_RET_OK;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_wait_scr_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_list_remove_wait_scr_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
	    case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            ShowCategory66Screen(
                STR_ID_KARAOKE_SONG_LIST_TITLE,
                NULL,
                0,
                0,
                0,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
            
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            if(g_karaoke_cntx.current_list.remove_hdlr != FS_MINIMUM_ERROR_CODE)
            {
                FS_Close(g_karaoke_cntx.current_list.remove_hdlr);
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
 *  mmi_karaoke_list_remove_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_remove_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_KARAOKE_REMOVE_WAITSCREEN))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
    }

    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_KARAOKE_REMOVE_WAITSCREEN, 
        mmi_karaoke_list_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

   mmi_frm_scrn_create(
        GRP_ID_KARAOKE_REMOVE_WAITSCREEN, 
        SCR_ID_KARAOKE_REMOVE_WAITSCREEN, 
        mmi_karaoke_list_remove_wait_scr_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;
	mmi_karaoke_list_struct* list = &(g_karaoke_cntx.current_list);
	S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->list_data.total <= 1)
    {
        if (mmi_karaoke_list_remove_all())
	    {
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }
            mmi_frm_scrn_close_active_id();
	    }
	    else
	    {
	  
			mmi_popup_display_ext(
                STR_ID_KARAOKE_CANNOT_UPDATE_LIST_FS_FAIL, 
                MMI_EVENT_FAILURE, 
                NULL);
	                
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }
	    }
    }
    else
    {
     	if ((ret = FS_Open(list->path, FS_READ_WRITE | FS_CACHE_DATA)) >= 0)
    	{
            list->remove_hdlr = ret;
            list->remove_offset = list->list_data.highlight * MMI_KARAOKE_LIST_RECORD_SIZE;
			list->remove_count = 
                (list->list_data.total - list->list_data.highlight - 1) / 
                (MMI_KARAOKE_REMOVE_BUF_SIZE / MMI_KARAOKE_LIST_RECORD_SIZE);
			if ((list->list_data.total - list->list_data.highlight - 1) % 
                (MMI_KARAOKE_REMOVE_BUF_SIZE / MMI_KARAOKE_LIST_RECORD_SIZE) > 0)
            {
				list->remove_count++;
            }
	        mmi_karaoke_list_remove_wait_scr();
		    mmi_karaoke_list_remove_one();
	    }
        else
        {
			/* remove failed! */
			mmi_karaoke_display_popup(ret, NULL);
            if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
            {
                mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
            }        	
        }
   	}	    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_remove_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_karaoke_list_remove_all())
    {
        mmi_karaoke_list_reset();
    }
    else
    {
    	mmi_popup_display_ext(
    	    STR_ID_KARAOKE_CANNOT_UPDATE_LIST_FS_FAIL, 
    	    MMI_EVENT_FAILURE, 
    	    NULL);
        mmi_frm_scrn_close_active_id();        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_entry_remove_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_list_entry_remove_confirm_cb(mmi_alert_result_evt_struct *evt)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        	case MMI_ALERT_CNFM_YES:
            {
                if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
                {
                    if (g_karaoke_cntx.remove_all)
                    {
            		    mmi_karaoke_list_remove_all_confirm();
                    }
                    else
                    {
            		    mmi_karaoke_list_remove_confirm();
                    }
                }
                else
                {
                    mmi_karaoke_record_list_delete_file();
                }
        		break;
            }
        		
            case MMI_ALERT_CNFM_NO:
              	mmi_frm_scrn_close_active_id();
              	break;            
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_entry_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  remove_all
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_list_entry_remove_confirm(MMI_BOOL remove_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.remove_all = remove_all;
    if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
    {
        if (remove_all)
        {
            str = (WCHAR *)GetString(STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL_ASK);
        }
        else
        {
            str = (WCHAR *)GetString(STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ASK);
        }
    }
    else
    {
        
        UI_character_type filename[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
        U16 tmp_str[SRV_FMGR_PATH_MAX_LEN + 20] = {0};
	    mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, g_karaoke_cntx.filefullname);
        mmi_karaoke_extract_filename(filename, g_karaoke_cntx.filefullname);
        kal_wsprintf(tmp_str, "%w\n%w?", get_string(STR_GLOBAL_DELETE), filename);
        str = (WCHAR *)tmp_str;
    }
    
    do {
    	mmi_confirm_property_struct arg;
    	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    	arg.callback = (mmi_proc_func)mmi_karaoke_list_entry_remove_confirm_cb;
    	mmi_confirm_display((WCHAR *)str, MMI_EVENT_QUERY, &arg);
    } while(0);
	
	if (mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_option_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_karaoke_list_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    	case EVT_ID_GROUP_DEINIT:
		{
			if (mmi_frm_group_get_active_id() != GRP_ID_KARAOKE_SING)
			{
				if(g_karaoke_cntx.need_resume || g_karaoke_cntx.is_singing)
				{
					g_karaoke_cntx.need_resume=KAL_FALSE;
					if(!g_karaoke_cntx.need_resume && g_karaoke_cntx.is_singing)
					{
						if(g_karaoke_cntx.mdi_callback_registed)
						{
							mdi_audio_clear_interrupt_callback();
							g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
						}
				        mdi_audio_stop_all();
						mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
						//mdi_audio_resume_background_play();
						g_karaoke_cntx.is_singing = KAL_FALSE;
						#ifdef __LINE_IN_SUPPORT__
						if(g_karaoke_cntx.force_use_linein_mice)
							mdi_audio_force_use_linein_mic(KAL_FALSE);
						#endif
					}
				}
			}
			break;
    	}
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_KARAOKE_SONG_LIST_OPTION_MENU)
            {
                if (mmi_karaoke_list_is_empty())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_SING,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_UPDATE,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_ADD, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL, MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD,MMI_TRUE);
                }
            }
			else if (menu_evt->parent_menu_id == MENU_ID_KARAOKE_SING_OPTION_MENU)
            {
                if(g_karaoke_cntx.origin_enable)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_ORIGIN,MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_NO_ORIGIN,MMI_TRUE);
                }
                #ifdef __LINE_IN_SUPPORT__
				if(!srv_earphone_is_plug_in())
				{
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_LINEIN_MIC,MMI_TRUE);
					cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_EARPHONE,MMI_TRUE);
                }
				else if(g_karaoke_cntx.force_use_linein_mice)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_LINEIN_MIC,MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_KARAOKE_OPTION_EARPHONE,MMI_TRUE);
                }
				#endif
            }
    
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_KARAOKE_SONG_LIST_OPTION_ADD:
                case MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE:
            #ifdef __MMI_TOUCH_SCREEN__
                    wgui_reset_list_item_selected_callback();
            #endif
                    break;

                default:
                    break;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_KARAOKE_SONG_LIST_OPTION_SING :
                    //sing song
                    mmi_karaoke_song_list_sing();
                    break;

                case MENU_ID_KARAOKE_SONG_LIST_OPTION_UPDATE:
                    //update song list
                    mmi_karaoke_list_auto_generate();
                    break;

                case MENU_ID_KARAOKE_SONG_LIST_OPTION_ADD:
                    //add
                    mmi_karaoke_song_list_add();
                    break;

                case MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE:
                    //remove
                    mmi_karaoke_list_entry_remove_confirm(MMI_FALSE);
                    break;
                    
                case MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL:
                    //remove all
                    mmi_karaoke_list_entry_remove_confirm(MMI_TRUE);
                    break;

                case MENU_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD:
                    //manual add songs
                    mmi_karaoke_song_list_add();
                    break;

                case MENU_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD:
                    //auto add songs
                    mmi_karaoke_list_auto_generate();
                    break;

                case MENU_ID_KARAOKE_RECORD_LIST_OPTION_PLAY:
				{
                    //play record
                    mmi_id group_id;
            		g_karaoke_cntx.record_list_highlight_index = g_karaoke_cntx.current_list.list_data.highlight;
					g_karaoke_cntx.is_paused = KAL_FALSE;
					//clean buffer
        			mmi_frm_scrn_clean_gui_buf(GRP_ID_KARAOKE_RECORD_LIST, SCR_ID_KARAOKE_RECORD_LIST);
                    group_id = mmi_frm_group_create_ex(GRP_ID_KARAOKE_RECORD_LIST, GRP_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			        MMI_ASSERT(group_id != GRP_ID_INVALID);
			        mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL);
					
                    break;
                }

                case MENU_ID_KARAOKE_RECORD_LIST_OPTION_DELETE:
                    //delete record
                    mmi_karaoke_list_entry_remove_confirm(MMI_FALSE);
                    break;
                #ifdef __MMI_TELEPHONY_SUPPORT__
                case MENU_ID_KARAOKE_RECORD_LIST_OPTION_USE_AS:
                    //use record as ringtone
                    mmi_karaoke_record_list_use_as_ringtone();
                    break;
                #endif  //__MMI_TELEPHONY_SUPPORT__

                case MENU_ID_KARAOKE_RECORD_LIST_OPTION_SEND:
                    //send record via BT
                    mmi_karaoke_record_list_send_via_bt();
                    break;
                    
				case MENU_ID_KARAOKE_OPTION_ORIGIN:
				case MENU_ID_KARAOKE_OPTION_NO_ORIGIN:
                    mmi_karaoke_origin_sing();
                    break;
                    
				#ifdef __LINE_IN_SUPPORT__
				case MENU_ID_KARAOKE_OPTION_EARPHONE:
				case MENU_ID_KARAOKE_OPTION_LINEIN_MIC:
                    mmi_karaoke_force_use_linein_mic();
                    break;
                    
				#endif
				case MENU_ID_KARAOKE_OPTION_RETRY:
                    mmi_karaoke_resing();
                    break;

                default:
                    break;
            } 
           break;                       
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		{
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_entry_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_list_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U16 menu_id = 0;
    U16 group_id,scrn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    }
	
	mmi_frm_get_active_scrn_id(&group_id,&scrn_id);
	
	if(scrn_id == SCR_ID_KARAOKE_SING)
	{
		group_id = GRP_ID_KARAOKE_SING;
		menu_id = MENU_ID_KARAOKE_SING_OPTION_MENU;
		g_karaoke_cntx.need_resume = MMI_TRUE;
	}
	else if (g_karaoke_cntx.item == MMI_KARAOKE_ITEM_SONG_LIST)
    {
        group_id = GRP_ID_KARAOKE_SONG_LIST;
        menu_id = MENU_ID_KARAOKE_SONG_LIST_OPTION_MENU;
    }
    else
    {
        group_id = GRP_ID_KARAOKE_RECORD_LIST;
		menu_id = MENU_ID_KARAOKE_RECORD_LIST_OPTION_MENU;
    }	

    mmi_frm_group_create_ex(
        group_id, 
        GRP_ID_KARAOKE_LIST_OPTION, 
        mmi_karaoke_list_option_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(
        GRP_ID_KARAOKE_LIST_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION, 
        menu_id, 
        MMI_FALSE, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_sing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_song_list_sing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id group_id;	
	S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, g_karaoke_cntx.filefullname);
	if ((ret = FS_Open(g_karaoke_cntx.filefullname, FS_READ_ONLY)) < FS_NO_ERROR)
	{
        mmi_karaoke_display_popup(ret, NULL);
		return;
	}
	FS_Close(ret);
	
	mmi_frm_group_close(GRP_ID_KARAOKE_SONG_LIST);
    group_id = mmi_frm_group_create_ex(GRP_ID_KARAOKE, GRP_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    MMI_ASSERT(group_id != GRP_ID_INVALID);
    mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_song_list_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_song_list_add(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U8 drv;
    S32 error;
    UI_character_type list_root[5]; /* "C:\" */
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    /* Check if in USB mode before enter app */
    #if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */
    
#ifdef __MMI_FILE_MANAGER__
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET_AUDIO(&filter);
#ifdef __VM_CODEC_SUPPORT__     
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
#endif /*__VM_CODEC_SUPPORT__*/    
#if defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
#endif
#if defined(__VORBIS_DECODE__) && defined(__VORBIS_DECODE_SLIM__)
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_OGG);
#endif
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    mmi_frm_group_create_ex(
        GRP_ID_KARAOKE_SONG_LIST, 
        GRP_ID_KARAOKE_SONG_LIST_ADD, 
        mmi_karaoke_list_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /*config presnet_dir_root*/
    drv = (U8)MMI_KARAOKE_DEFAULT_DRV;
    kal_wsprintf(list_root, "%c:\\", drv);
	if ((error=FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM)) == FS_NO_ERROR)
    {

        cui_gid = cui_file_selector_create(
                                        GRP_ID_KARAOKE_SONG_LIST_ADD,
                                        (WCHAR*)list_root,
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);


        if (cui_gid > GRP_ID_INVALID)
        {
            cui_file_selector_set_title(cui_gid, 0, NULL);
            cui_file_selector_run(cui_gid);
                   
        }
        else
        {   
            mmi_popup_display_ext(
                STR_GLOBAL_NOT_AVAILABLE, 
                MMI_EVENT_FAILURE, 
                NULL);
        }
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_INSERT_MEMORY_CARD, 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error), 
            NULL);
    }
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_song_list_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_song_list_exit_main(void)
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
 *  mmi_karaoke_song_list_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_song_list_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlighted_item = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_karaoke_is_dev_ready(MMI_TRUE))
	{
		mmi_frm_group_close(GRP_ID_KARAOKE);
		return;
	}
    mmi_frm_group_create_ex(
        GRP_ID_KARAOKE, 
        GRP_ID_KARAOKE_SONG_LIST, 
        mmi_karaoke_list_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_frm_scrn_enter(GRP_ID_KARAOKE_SONG_LIST, SCR_ID_KARAOKE_SONG_LIST, mmi_karaoke_song_list_exit_main, mmi_karaoke_song_list_entry_main, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    g_karaoke_cntx.item = MMI_KARAOKE_ITEM_SONG_LIST;

    mmi_karaoke_list_init();
    
    /* show category screen */
    if (mmi_karaoke_list_is_empty())
    {
        ShowCategory353Screen(
            (PU8)GetString(STR_ID_KARAOKE_SONG_LIST_TITLE),
            NULL,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        S32 total = mmi_karaoke_list_get_total();
        S32 cat_err = 0;
        /*
        **  2 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item.
        **      2. now playing list screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.        
        */

        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_KARAOKE_SONG_LIST, SCR_ID_KARAOKE_SONG_LIST);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            /* case 2. */
            g_karaoke_cntx.current_list.list_data.highlight = hist->highlighted_item;
        }
        else
        {
            /* case 1. */
            highlighted_item = mmi_karaoke_list_get_current_index();
            if (highlighted_item < 0)
            {
                highlighted_item = 0;
            }
            g_karaoke_cntx.current_list.list_data.highlight = highlighted_item;
        }

        /* register highligh handler */
        RegisterHighlightHandler(mmi_karaoke_list_highlight_hdlr);

        #ifdef __MMI_BT_DIALER_SUPPORT__
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
        #endif
        
        wgui_cat1032_show(
            get_string(STR_ID_KARAOKE_SONG_LIST_TITLE),
            NULL,
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            total,
            mmi_karaoke_list_get_item_async,
            NULL,
            highlighted_item,
            0,    
            IMG_GLOBAL_L1, /* to calculate the coordinate offset of string */
            0,
            guiBuffer,
            &cat_err);
    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_karaoke_list_entry_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_record_list_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_record_list_delete_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[SRV_FMGR_PATH_BUFFER_SIZE];
	S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_karaoke_list_remove_wait_scr();
    
    ret = mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, temp_path);
    if (ret < FS_NO_ERROR)
    {
        mmi_karaoke_display_popup(ret, NULL);
    }
    else
    {
        ret = FS_Delete(temp_path);
        
        if (ret < FS_NO_ERROR)
        {
            mmi_karaoke_display_popup(ret, NULL);
        }
        else
        {
        	UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
		
            g_karaoke_cntx.record_auto_gen = MMI_FALSE;
            g_karaoke_cntx.record_list_highlight_index = g_karaoke_cntx.current_list.list_data.highlight;

            //do not care whether lyric delete or not
    		mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
    		if(rec_lyricpath[0] != NULL)
    			ret = FS_Delete(rec_lyricpath);
        }
		
        mmi_frm_group_close(GRP_ID_KARAOKE_REMOVE_WAITSCREEN);
    }
}


#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_record_list_use_as_ringtone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_record_list_use_as_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret srv_result;
    S32                                 fs_ret;
	UI_character_type rec_filepath[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, rec_filepath);
    if (fs_ret < FS_NO_ERROR)
    {
        mmi_karaoke_display_popup(fs_ret, NULL);
        return;
    }
    
    mmi_prof_app_filemgr_option_hdlr(MENU_ID_PROF_USE_AS_RINGTONE, rec_filepath, NULL);
}
#endif  //__MMI_TELEPHONY_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_record_list_send_via_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_record_list_send_via_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct            fileinfo;
    S32                                 fs_ret;
	UI_character_type rec_filepath[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, rec_filepath);
    if (fs_ret < FS_NO_ERROR)
    {
        mmi_karaoke_display_popup(fs_ret, NULL);
        return;
    }
    
    fs_ret = srv_fmgr_fs_path_get_fileinfo(rec_filepath, &fileinfo);
    if (fs_ret < FS_NO_ERROR)
    {
        mmi_karaoke_display_popup(fs_ret, NULL);
        return;
    }

    mmi_fmgr_to_bt_hdlr(g_karaoke_cntx.current_list.list_data.highlight, rec_filepath, &fileinfo);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_record_list_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_record_list_exit_main(void)
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
 *  mmi_karaoke_record_list_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_record_list_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlighted_item = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_karaoke_is_dev_ready(MMI_TRUE))
	{
		mmi_frm_group_close(GRP_ID_KARAOKE);
		return;
	}
    mmi_frm_group_create_ex(
        GRP_ID_KARAOKE, 
        GRP_ID_KARAOKE_RECORD_LIST, 
        mmi_karaoke_list_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_frm_scrn_enter(GRP_ID_KARAOKE_RECORD_LIST, SCR_ID_KARAOKE_RECORD_LIST, mmi_karaoke_record_list_exit_main, mmi_karaoke_record_list_entry_main, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    g_karaoke_cntx.item = MMI_KARAOKE_ITEM_RECORD_LIST;

    mmi_karaoke_list_init();
    
    if (!g_karaoke_cntx.record_auto_gen)
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_KARAOKE_RECORD_LIST, SCR_ID_KARAOKE_RECORD_LIST);
        mmi_karaoke_list_auto_generate();
        return;
    }
        
    /* show category screen */
    if (mmi_karaoke_list_is_empty())
    {
        ShowCategory353Screen(
            (PU8)GetString(STR_ID_KARAOKE_RECORD_LIST_TITLE),
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        S32 total = mmi_karaoke_list_get_total();
        S32 cat_err = 0;
        /*
        **  2 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item.
        **      2. now playing list screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.        
        */

        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_KARAOKE_RECORD_LIST, SCR_ID_KARAOKE_RECORD_LIST);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            /* case 2. */
            g_karaoke_cntx.current_list.list_data.highlight = hist->highlighted_item;
        }
        else
        {
            /* case 1. */
            highlighted_item = mmi_karaoke_list_get_current_index();
            if (highlighted_item < 0)
            {
                highlighted_item = 0;
            }
        }

        //check whether reload after delete
        if (g_karaoke_cntx.record_list_highlight_index >= 0)
        {
            highlighted_item = g_karaoke_cntx.record_list_highlight_index;
            g_karaoke_cntx.record_list_highlight_index = -1;
        }
        
        g_karaoke_cntx.current_list.list_data.highlight = highlighted_item;

        /* register highligh handler */
        RegisterHighlightHandler(mmi_karaoke_list_highlight_hdlr);
        
        #ifdef __MMI_BT_DIALER_SUPPORT__
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
        #endif
        
        wgui_cat1031_show(
            get_string(STR_ID_KARAOKE_RECORD_LIST_TITLE),
            NULL,
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            total,
            mmi_karaoke_list_get_item_async,
            mmi_karaoke_list_get_hint_async,
            highlighted_item,
            0,    
            IMG_GLOBAL_L1, /* to calculate the coordinate offset of string */
            0,
            guiBuffer,
            &cat_err);
    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_karaoke_list_entry_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);  
}


/*****************************************************************************
 * FUNCTION
 *  HighlightKaraokeSongList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightKaraokeSongList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_karaoke_song_list_entry_main, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_karaoke_song_list_entry_main,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightKaraokeRecordList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightKaraokeRecordList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_karaoke_record_list_entry_main, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_karaoke_record_list_entry_main,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[3];
    U16 ItemIcons[3];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = GetNumOfChild_Ext(MAIN_MENU_KARAOKE_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_KARAOKE_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_KARAOKE_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_KARAOKE_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory52Screen(
        STR_ID_KARAOKE_NAME,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	if(g_karaoke_cntx.is_interrupted)
	{
	    mmi_id group_id;
        g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
		g_karaoke_cntx.is_paused = KAL_FALSE;
		group_id = mmi_frm_group_create_ex(GRP_ID_KARAOKE, GRP_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		MMI_ASSERT(group_id != GRP_ID_INVALID);
		mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&g_karaoke_cntx, 0, sizeof(mmi_karaoke_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_bt_music_disconnect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP, "[KARAOKE]mmi_karaoke_bt_music_disconnect_callback,result:%d", result);
    if (result)
    {
        mmi_karaoke_launch();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_LAUNCH, 100); 
	#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_karaoke_bt_music_disconnect_callback);
        //return;
    }
	#endif
    
	if (!mmi_karaoke_is_dev_ready(MMI_TRUE))
    {
        return;
    }
    if (!mmi_karaoke_is_active())
    {   
        if(!g_karaoke_cntx.is_interrupted)
    	    memset(&g_karaoke_cntx, 0, sizeof(mmi_karaoke_context_struct));
        g_karaoke_cntx.group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_KARAOKE, mmi_karaoke_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        MMI_ASSERT(g_karaoke_cntx.group_id != GRP_ID_INVALID);
        mmi_frm_scrn_create(g_karaoke_cntx.group_id, SCR_ID_KARAOKE_MAIN, mmi_karaoke_proc, NULL);
    }

	ReadValue(NVRAM_KARAOKE_VOL, &g_karaoke_cntx.vol, DS_BYTE, &error);
	if(g_karaoke_cntx.vol > MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.vol = 12;
		WriteValue(NVRAM_KARAOKE_VOL, &g_karaoke_cntx.vol, DS_BYTE, &error);
    }

	ReadValue(NVRAM_KARAOKE_AUD_VOL, &g_karaoke_cntx.aud_vol, DS_BYTE, &error);
	if(MDI_KARAOKE_VOL_EX_MIN > g_karaoke_cntx.aud_vol || g_karaoke_cntx.aud_vol > MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.aud_vol = KARAOKE_AUD_VOL_DEFAULT;
		WriteValue(NVRAM_KARAOKE_AUD_VOL, &g_karaoke_cntx.aud_vol, DS_BYTE, &error);
    }

	ReadValue(NVRAM_KARAOKE_MIC_VOL, &g_karaoke_cntx.mic_vol, DS_BYTE, &error);
	if(MDI_KARAOKE_VOL_EX_MIN > g_karaoke_cntx.mic_vol || g_karaoke_cntx.mic_vol > MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.mic_vol = KARAOKE_MIC_VOL_DEFAULT;
		WriteValue(NVRAM_KARAOKE_MIC_VOL, &g_karaoke_cntx.mic_vol, DS_BYTE, &error);
    }

	#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
	ReadValue(NVRAM_KARAOKE_REMIX_AUD_VOL, &g_karaoke_cntx.remix_aud_vol, DS_BYTE, &error);
	if(MDI_KARAOKE_VOL_EX_MIN > g_karaoke_cntx.remix_aud_vol || 
		g_karaoke_cntx.remix_aud_vol > MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.remix_aud_vol = KARAOKE_REMIX_AUD_VOL_DEFAULT;
		WriteValue(NVRAM_KARAOKE_REMIX_AUD_VOL, &g_karaoke_cntx.remix_aud_vol, DS_BYTE, &error);
    }

	ReadValue(NVRAM_KARAOKE_REMIX_MIC_VOL, &g_karaoke_cntx.remix_mic_vol, DS_BYTE, &error);
	if(MDI_KARAOKE_VOL_EX_MIN > g_karaoke_cntx.remix_mic_vol || 
		g_karaoke_cntx.remix_mic_vol > MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.remix_mic_vol = KARAOKE_REMIX_MIC_VOL_DEFAULT;
		WriteValue(NVRAM_KARAOKE_REMIX_MIC_VOL, &g_karaoke_cntx.remix_mic_vol, DS_BYTE, &error);
    }
	#endif

	ReadValue(NVRAM_KARAOKE_FOCUS_AUD, &g_karaoke_cntx.focus_on_aud_vol, DS_BYTE, &error);
	ReadValue(NVRAM_KARAOKE_AUD_MUTE, &g_karaoke_cntx.aud_mute, DS_BYTE, &error);
	ReadValue(NVRAM_KARAOKE_MIC_MUTE, &g_karaoke_cntx.mic_mute, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_karaoke
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_karaoke(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_karaoke_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_karaoke_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_is_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_karaoke_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_get_active_id() == GRP_ID_KARAOKE)
        return MMI_TRUE;

    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_karaoke_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 0, event->evt_id);
    switch (event->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_karaoke_entry_screen();
            break;
        case EVT_ID_SCRN_INACTIVE:
            mmi_karaoke_exit_screen();
            break;
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
			if(g_karaoke_cntx.Rec_filepath[0] != 0 && (g_karaoke_cntx.is_singing || g_karaoke_cntx.play_record_for_reviewing))
			{
			    UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 + 17];
				mdi_audio_stop_all();
			   	mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
				FS_Delete(rec_lyricpath);
			    FS_Delete(g_karaoke_cntx.Rec_filepath);
				memset((kal_char*)g_karaoke_cntx.Rec_filepath,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
				memset((kal_char*)g_karaoke_cntx.filefullname,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
				g_karaoke_cntx.is_playing_records = KAL_FALSE;
				g_karaoke_cntx.is_singing = KAL_FALSE;
				g_karaoke_cntx.is_interrupted = KAL_FALSE;
			    g_karaoke_cntx.need_resume = KAL_FALSE;
			}
			break;
    }
    return MMI_RET_OK;
}

//#ifndef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
//#define __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
//#endif
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
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
 *  mmi_karaoke_redraw_title_background
 * DESCRIPTION
 *  redraw karaoke title background
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_title_background(S32 x1, S32 y1, S32 x2, S32 y2)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER_SKIN_SLIM__
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);//audply_main_text_bg_color);
#endif
#else
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);//audply_main_text_bg_color);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_scroll_title_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_scroll_title_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&karaoke_scrolling_title);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_background
 * DESCRIPTION
 *  redraw karaoke background
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_background(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = TITLE_X;
    S32 y1 = TITLE_Y;
    S32 x2 = UI_DEVICE_WIDTH;// - 1;
    S32 y2 = TITLE_Y + TITLE_height + LYRICS_height + TIME_height + KARAOKE_FG_PROGRESS_H + 20;// Need to do

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0	
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif
/* under construction !*/
#endif
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();
#if 0
/* under construction !*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_title
 * DESCRIPTION
 *  redraw karaoke title background
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_title(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 title_h=0, title_w=0;
    S32 x1 = TITLE_X;
    S32 y1 = TITLE_Y;
    S32 x2 = TITLE_X + TITLE_width;//- 1;
    S32 y2 = TITLE_Y + TITLE_height;//- 1;
    S32 x_offset = 0;
    S32 y_offset = 0;
	UI_character_type filename[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(karaoke_show_title_done)
		gui_scrolling_text_stop(&karaoke_scrolling_title);

#if 0
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif
/* under construction !*/
#endif
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
	
	gui_set_font(&MMI_medium_font);
    gui_set_text_color(MMI_KARAOKE_TITLE_COLOR);
	if(!g_karaoke_cntx.is_singing)
		mmi_karaoke_extract_filename(filename,g_karaoke_cntx.Rec_filepath);
	else
		mmi_karaoke_extract_filename(filename,g_karaoke_cntx.filefullname);
    
    memset(g_karaoke_cntx.song_title, 0, sizeof(g_karaoke_cntx.song_title));
	mmi_karaoke_split_filename_ext(filename,g_karaoke_cntx.song_title,ext);
    
	if (!mmi_ucs2strlen((CHAR*)g_karaoke_cntx.song_title))
    {
        mmi_ucs2ncpy((CHAR *)g_karaoke_cntx.song_title, (CHAR *)GetString(STR_ID_KARAOKE_NAME), SRV_FMGR_PATH_MAX_LEN + 1);
    }
	
	gui_measure_string(g_karaoke_cntx.song_title, &title_w, &title_h);	

	x_offset = 10;
	y_offset = (TITLE_height- title_h) / 2;

    if (title_w > TITLE_width - (x_offset*2))
    {
	    gui_create_scrolling_text(
	        &karaoke_scrolling_title,
	        x1 + x_offset,
	        y1 + y_offset,
	        TITLE_width - (x_offset*2),
	        TITLE_height - (y_offset*2),
	        g_karaoke_cntx.song_title,
	        mmi_karaoke_scroll_title_handler,
	        mmi_karaoke_redraw_title_background,
	        gui_color(0, 200, 0),
	        gui_color(0, 0, 0));
		/* scrolling */
		gui_scrolling_text_stop(&karaoke_scrolling_title);
        gui_show_scrolling_text(&karaoke_scrolling_title);
    }
    else
    {
        /* background */
        //gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#ifdef __MMI_BIDI_ALG__
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (TITLE_width + title_w) / 2, y1 + y_offset);
        }
        else
#endif
        {
            gui_move_text_cursor(x1 + (TITLE_width - title_w) / 2, y1 + y_offset);
        }

        gui_set_line_height(title_h);
        gui_print_text(g_karaoke_cntx.song_title);
    }
	
	karaoke_show_title_done = MMI_TRUE;
/*	
    //gdi_layer_pop_and_restore_active();
	//mmi_audply_gdi_layer_pop_clip_blt(x1,y1,x1+x2,y1+y2);
	gdi_layer_pop_clip();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1,y1,x1+x2,y1+y2);
    #endif
	gdi_layer_pop_and_restore_active();
*/
	gdi_layer_pop_clip();
#if 0
/* under construction !*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_transte_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  second      [IN]        
 *  time        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_transte_time(U32 second, mmi_karaoke_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time->second = second % 60;
    second /= 60;
    time->minute = second % 60;
    second /= 60;
    time->hour = second;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_time
 * DESCRIPTION
 *  redraw karaoke title background
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_time(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = TIME_X;
    S32 y1 = TIME_Y -1;
    S32 x2 = TIME_X + TIME_width;// - 1;
    S32 y2 = TIME_Y + TIME_height -2;// - 1 + LYRICS_height;
	mmi_karaoke_time_struct time1, time2;
	UI_character_type time_string[20]={0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_lyrics == NULL)
	{
	    U32 timerduration = 0;
		mdi_audio_get_progress_time(&g_karaoke_cntx.new_play_time);
		
		if ((g_karaoke_cntx.new_play_time % 1000) > 500)
	    {
		    timerduration = 1000 - (g_karaoke_cntx.new_play_time % 1000);
	    }
		else
	    {
		    timerduration = MMI_KARAOKE_UI_UPDATE_PLAY_TIME;
	    }
		StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,timerduration,mmi_karaoke_redraw_time);
	}
	
	if(g_karaoke_cntx.new_play_time > g_karaoke_cntx.duration)
		g_karaoke_cntx.new_play_time = g_karaoke_cntx.duration;
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
	gui_lock_double_buffer();
#endif
	gdi_layer_push_and_set_active(karaoke_osd_layer);  
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
	
	gui_set_font(&MMI_small_font);
    gui_set_text_color(MMI_KARAOKE_TIME_COLOR);
    //Show record picture & Time
	gdi_draw_solid_circle(x1+5,y1+TIME_height/2,5,GDI_COLOR_RED);
	mmi_karaoke_transte_time(g_karaoke_cntx.new_play_time / 1000, &time1);
    mmi_karaoke_transte_time(g_karaoke_cntx.duration / 1000, &time2);
    kal_wsprintf(
        time_string,
        "%02d:%02d:%02d / %02d:%02d:%02d",
        time1.hour,
        time1.minute,
        time1.second,
        time2.hour,
        time2.minute,
        time2.second);
	gui_move_text_cursor(x1+15,y1);
	gui_print_text(time_string);

    gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1,y1,x2,y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_play_record_time
 * DESCRIPTION
 *  redraw karaoke title background
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_play_record_time(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = PLAY_REC_TIME_X;
    S32 y1 = PLAY_REC_TIME_Y;
    S32 x2 = PLAY_REC_TIME_X + PLAY_REC_TIME_width;// - 1;
    S32 y2 = PLAY_REC_TIME_Y + PLAY_REC_TIME_height;// - 1 + LYRICS_height;
    S32 str_x=0,str_y=0;
	mmi_karaoke_time_struct time1;
	UI_character_type time_string[20]={0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.new_play_time > g_karaoke_cntx.duration)
		g_karaoke_cntx.new_play_time = g_karaoke_cntx.duration;
	
#if(UI_DOUBLE_BUFFER_SUPPORT)
	gui_lock_double_buffer();
#endif
	gdi_layer_push_and_set_active(karaoke_osd_layer);  
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
	
    //Show record picture & Time
	gui_set_font(&MMI_small_font);
	gui_set_text_color(MMI_KARAOKE_TIME_COLOR);
	mmi_karaoke_transte_time(g_karaoke_cntx.new_play_time / 1000, &time1);
    kal_wsprintf(
        time_string,
        "%02d:%02d:%02d",
        time1.hour,
        time1.minute,
        time1.second);
	gui_move_text_cursor(x1,y1);
	gui_print_text(time_string);

    mmi_karaoke_transte_time(g_karaoke_cntx.duration / 1000, &time1);
	kal_wsprintf(
        time_string,
        "%02d:%02d:%02d",
        time1.hour,
        time1.minute,
        time1.second);
	gui_measure_string(time_string,&str_x,&str_y);
	gui_move_text_cursor(x2-str_x,y1);
	gui_print_text(time_string);
	
	gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1,y1,x2,y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_free_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
static  void  mmi_karaoke_free_mem_lyrics(void* p, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    applib_mem_screen_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_malloc_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return memory address, 
 *****************************************************************************/
static  void* mmi_karaoke_malloc_mem_lyrics(kal_uint32 nSize, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     return  applib_mem_screen_alloc_framebuffer(nSize);   
}

/*****************************************************************************
* FUNCTION
*   mmi_karaoke_unprepare_lyrics
* DESCRIPTION
*   unprepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
void mmi_karaoke_unprepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	GDI_HANDLE base_handle;
	S32 x1, y1, x2, y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL != g_karaoke_lyrics)
    {     
        lyrics_parse_release();
        g_karaoke_lyrics = NULL;
    }
	  
	  if(!g_karaoke_lyrics_box.is_ready)
	  {
	  	 return;
	  }
	 srv_backlight_turn_off();    
	g_karaoke_lyrics_box.is_ready = 0;
	//if(g_audply.in_main_screen)  //Need TO DO
	{
	    x1 = g_karaoke_lyrics_box.rgn_txt.x;
	    y1 = g_karaoke_lyrics_box.rgn_txt.y;  
	    x2 = x1 + g_karaoke_lyrics_box.rgn_txt.w;
	    y2 = y1 + g_karaoke_lyrics_box.rgn_txt.h;;

#if(UI_DOUBLE_BUFFER_SUPPORT)
	    gui_lock_double_buffer();
#endif


#ifdef __GDI_MEMORY_PROFILE_2__
	    gdi_layer_push_and_set_active(karaoke_osd_layer);  //Need To DO
#endif 

	    gui_push_clip();


	    gdi_layer_set_clip(x1,y1,x2,y2);
	    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);
	
    	//mmi_audply_redraw_animation();  //Need TO DO

	    gui_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
	    gdi_layer_pop_and_restore_active();
#endif

#if(UI_DOUBLE_BUFFER_SUPPORT)
	    gui_unlock_double_buffer();
	    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif
	}

}


/*****************************************************************************
* FUNCTION
*   mmi_karaoke_config_lyrics
* DESCRIPTION
*   configure lyrics display region 
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_karaoke_config_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!g_karaoke_lyrics_box.is_ready)
    {
        return;
    }
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    gui_set_font(&MMI_medium_font);
    g_karaoke_lyrics_box.font_height = gui_get_character_height();
    g_karaoke_lyrics_box.line_count = 
        (U8)((LYRICS_height-10)/(g_karaoke_lyrics_box.font_height+MMI_KARAOKE_LYRICS_GAP_H) );    
    if (g_karaoke_lyrics_box.line_count > MMI_KARAOKE_LYRICS_MAX_LINE)
    {
        g_karaoke_lyrics_box.line_count = MMI_KARAOKE_LYRICS_MAX_LINE;
    }
    g_karaoke_lyrics_box.line_focus     = MMI_KARAOKE_LYRICS_MAX_LINE/2 - 1;
    g_karaoke_lyrics_box.line_focus_id  = KARAOKE_LYRIC_MAX_LINE_COUNT; 
    g_karaoke_lyrics_box.line_height    = g_karaoke_lyrics_box.rgn_txt.h/g_karaoke_lyrics_box.line_count;
    
    
    g_karaoke_lyrics_box.rgn_txt.h = g_karaoke_lyrics_box.line_height*g_karaoke_lyrics_box.line_count;
	
    gdi_image_stop_animation_all();
    lyrics_unformat_line(g_karaoke_lyrics);
    lyrics_format_line(g_karaoke_lyrics, g_karaoke_lyrics_box.rgn_txt.w,
        (U32)g_karaoke_cntx.duration, gui_get_string_width_n); 
}


/*****************************************************************************
* FUNCTION
*  mmi_karaoke_parse_lyrics
* DESCRIPTION
*  parse lyrics
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_karaoke_parse_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16*    media_file_path;
    U16    meta_title[255+2];
    U16     lyric_file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32     nRet;
    U16     lyric_err_str_id = STR_GLOBAL_ERROR;
    U8      lyric_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_karaoke_cntx.is_singing)
		media_file_path = g_karaoke_cntx.Rec_filepath;
	else
        media_file_path = g_karaoke_cntx.filefullname;
	mmi_karaoke_extract_filename(meta_title,media_file_path);
   
    lyric_ret = lyrics_convert_file_name(media_file_path, 
        meta_title, lyric_file_path); 
    
    if (LYRICS_ERR_NONE == lyric_ret)
    {
        lyric_ret = lyrics_parse_file(lyric_file_path);
    }
    if (LYRICS_ERR_NONE != lyric_ret)
    {
        switch(lyric_ret)
        {
        	lyric_err_str_id = STR_ID_KARAOKE_ERR_DATA_LYRICS_FILE; //Need TO DO
            break;
        case LYRICS_ERR_OPEN_FILE_FAILED:

            lyric_err_str_id = STR_ID_KARAOKE_ERR_OPEN_LYRICS_FILE;  //Need TO DO
            break;
        default:
            lyric_err_str_id = STR_ID_KARAOKE_NO_LYRICS_FILE;    //Need TO DO
			break;
        }
        lyrics_set_err_text(g_karaoke_lyrics, (kal_uint16*)GetString(lyric_err_str_id));
    }
    else
    {
      g_karaoke_lyrics_box.is_ready = 1;
    }
  
    g_karaoke_lyrics_box.line_focus_id = KARAOKE_LYRIC_MAX_LINE_COUNT;  
}


/*****************************************************************************
* FUNCTION
*  mmi_karaoke_draw_text
* DESCRIPTION
*  draw text
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_karaoke_draw_text(mmi_karaoke_rect_struct* rgn_p,
                                mmi_karaoke_rect_struct* rgn_clip_p,
                                U16* txt_p, U8 attr_w, U8 attr_h,
                                U8 use_border, S32 trunc_w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 x, y, str_w, str_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string(txt_p, &str_w, &str_h);
    if (0 != use_border)
    {
        str_h += 2;
        str_w += 2;
    }
	if (trunc_w > 0)
    {
		
		str_w = trunc_w;		
		
    }

        
    if (0 != rgn_clip_p)
    {
        gui_push_text_clip();
        gui_set_text_clip(rgn_clip_p->x, rgn_clip_p->y, 
            rgn_clip_p->x+rgn_clip_p->w, rgn_clip_p->y+rgn_clip_p->h);
    }    
  
        
        x = rgn_p->x + (rgn_p->w - str_w) / 2;
   
    if (r2lMMIFlag)
    {        
        x += str_w;
        if (0 != use_border)
        {
            x -= 2;
        }
    } 
    
    y = rgn_p->y;
    gui_move_text_cursor(x, y);
    
    if (trunc_w < 0)
    {
        if (0 != use_border)
        {
            gui_print_bordered_text(txt_p);
        }
        else
        {
            gui_print_text(txt_p);
        }
    }
    else
    {
        if (0 != use_border)
        {
            gui_print_truncated_borderd_text(x, y, trunc_w, txt_p);
        }
        else
        {
            gui_print_truncated_text(x, y, trunc_w, txt_p);
        }
    }
    
    
    if (0 != rgn_clip_p)
    {
        gui_pop_text_clip();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_karaoke_update_lyrics
* DESCRIPTION
*  update lyrics display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_karaoke_update_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 lineID, nextID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_karaoke_lyrics)
    {
        /*screen may delete by delete call back function*/
        return;
    }
    g_karaoke_lyrics_box.last_time = (U16)(g_karaoke_cntx.new_play_time/MMI_KARAOKE_UI_UPDATE_PLAY_TIME);

    lineID = lyrics_get_line(g_karaoke_lyrics, g_karaoke_lyrics_box.last_time);
    if (lineID == g_karaoke_lyrics_box.line_focus_id)
    {
        if (g_karaoke_lyrics_box.last_time > g_karaoke_lyrics->lines_p[lineID].id_time)
        {
            g_karaoke_lyrics_box.time_out = 
                (U16)(g_karaoke_lyrics_box.last_time - g_karaoke_lyrics->lines_p[lineID].id_time);
        }
        else
        {
            g_karaoke_lyrics_box.time_out = 0;
        }
        return;
    }
    
    if (lineID < KARAOKE_LYRIC_MAX_LINE_COUNT)
    {
        nextID = g_karaoke_lyrics->lines_p[lineID].id_next;
    }
    else
    {
        nextID = KARAOKE_LYRIC_MAX_LINE_COUNT;
    }
    if (nextID < KARAOKE_LYRIC_MAX_LINE_COUNT)
    {
        g_karaoke_lyrics_box.next_time = g_karaoke_lyrics->lines_p[nextID].id_time;
    }
    else
    {
        g_karaoke_lyrics_box.next_time = 
            (U32)(g_karaoke_cntx.duration/MMI_KARAOKE_UI_UPDATE_PLAY_TIME);
    }
    g_karaoke_lyrics_box.curr_time      = g_karaoke_lyrics->lines_p[lineID].id_time;
    g_karaoke_lyrics_box.line_focus_id  = lineID;

    if (g_karaoke_lyrics_box.last_time > g_karaoke_lyrics->lines_p[lineID].id_time)
    {
        g_karaoke_lyrics_box.time_out   = 
            (U16)(g_karaoke_lyrics_box.last_time - g_karaoke_lyrics->lines_p[lineID].id_time);
    }
    else
    {
        g_karaoke_lyrics_box.time_out   = 0;
    }
    
    g_karaoke_lyrics_box.line_id[g_karaoke_lyrics_box.line_focus] = g_karaoke_lyrics_box.line_focus_id;
    lineID = g_karaoke_lyrics_box.line_focus_id;
    
    for (i = g_karaoke_lyrics_box.line_focus-1; i >= 0; i--)
    {
        if (lineID < KARAOKE_LYRIC_MAX_LINE_COUNT)
        {
            g_karaoke_lyrics_box.line_id[i] = g_karaoke_lyrics->lines_p[lineID].id_prev;
            lineID = g_karaoke_lyrics_box.line_id[i];
        }
        else
        {
            g_karaoke_lyrics_box.line_id[i] = KARAOKE_LYRIC_MAX_LINE_COUNT;
        }
    }
    lineID = g_karaoke_lyrics_box.line_focus_id;
    for (i = g_karaoke_lyrics_box.line_focus+1; i <= g_karaoke_lyrics_box.line_count; i++)
    {   
        if (lineID < KARAOKE_LYRIC_MAX_LINE_COUNT)
        {
            g_karaoke_lyrics_box.line_id[i] = g_karaoke_lyrics->lines_p[lineID].id_next;
            lineID = g_karaoke_lyrics_box.line_id[i];
        }
        else
        {
            g_karaoke_lyrics_box.line_id[i] = KARAOKE_LYRIC_MAX_LINE_COUNT;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_karaoke_draw_lyrics
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_karaoke_draw_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S16     x, y, h, w,yOff, yBeg;
    U16     *pStr, u16Tmp, nLen;
	U16 font_r, font_g, font_b;
	U16 skin_r, skin_g, skin_b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL == g_karaoke_lyrics)|| !g_karaoke_lyrics_box.is_ready)
    {
       // MMI_audply_ERR_TRACE(g_audply_lyrics);
        return;
    }
	
	if(!g_karaoke_cntx.is_singing)
	    mmi_karaoke_redraw_main_progressbar();
	else
		mmi_karaoke_redraw_time();
	
	skin_r = g_karaoke_lyrics_box.color.r;
	skin_g = g_karaoke_lyrics_box.color.g;
	skin_b = g_karaoke_lyrics_box.color.b;
	x = g_karaoke_lyrics_box.rgn_txt.x;
    y = g_karaoke_lyrics_box.rgn_txt.y;  
    h = g_karaoke_lyrics_box.rgn_txt.h;
	w = g_karaoke_lyrics_box.rgn_txt.w;

#if(UI_DOUBLE_BUFFER_SUPPORT)
	gui_lock_double_buffer();
#endif
   	//gdi_layer_get_base_handle(&karaoke_osd_layer);
   	gdi_layer_push_and_set_active(karaoke_osd_layer);  //NEED TO DO
	gdi_layer_set_clip(x,y,x+w,y+h);
    gdi_draw_solid_rect(x, y, x + w, y + h,GDI_COLOR_TRANSPARENT);

    gui_set_font(&MMI_medium_font);
    gui_set_text_color(gui_color(0, 200, 0));
    
    if (g_karaoke_lyrics_box.next_time > g_karaoke_lyrics_box.curr_time)
    {
        yOff = (S16)(g_karaoke_lyrics_box.line_height*g_karaoke_lyrics_box.time_out/
            (g_karaoke_lyrics_box.next_time-g_karaoke_lyrics_box.curr_time));
    }
    else
    {
        yOff = 0;
    }
    yBeg = 0;
    
    g_karaoke_lyrics_box.rgn_txt.x = x;
    g_karaoke_lyrics_box.rgn_txt.y = y;
    g_karaoke_lyrics_box.rgn_txt.h = g_karaoke_lyrics_box.line_height;     
    
    kal_mem_cpy(&g_karaoke_lyrics_box.rgn_clip, &g_karaoke_lyrics_box.rgn_txt, 
        sizeof(mmi_karaoke_rect_struct));
    
    for (i = 0; i <= g_karaoke_lyrics_box.line_count; i++)
    {
        pStr = NULL;
        if (g_karaoke_lyrics_box.line_id[i] < LYRICS_MAX_LINES)
        {
            pStr = g_karaoke_lyrics->lines_p[g_karaoke_lyrics_box.line_id[i]].st_text;
            nLen = g_karaoke_lyrics->lines_p[g_karaoke_lyrics_box.line_id[i]].ln_text; 
        }
        if (NULL != pStr)
        {
            if (g_karaoke_lyrics_box.rgn_txt.y < yBeg)
            {
                g_karaoke_lyrics_box.rgn_clip.y = yBeg;
                g_karaoke_lyrics_box.rgn_clip.h = g_karaoke_lyrics_box.rgn_txt.y - yBeg + 
                    g_karaoke_lyrics_box.rgn_txt.h;
            }
            else if (g_karaoke_lyrics_box.rgn_txt.y - y + 2 +g_karaoke_lyrics_box.font_height > yBeg+h)
            {
                g_karaoke_lyrics_box.rgn_clip.y = g_karaoke_lyrics_box.rgn_txt.y;
                g_karaoke_lyrics_box.rgn_clip.h = yBeg + h - g_karaoke_lyrics_box.rgn_txt.y;
            }
            else
            {
                g_karaoke_lyrics_box.rgn_clip.y = g_karaoke_lyrics_box.rgn_txt.y;
                g_karaoke_lyrics_box.rgn_clip.h = g_karaoke_lyrics_box.rgn_txt.h;
            }
            
            u16Tmp = pStr[nLen];
            pStr[nLen] = 0;   

            if (i == g_karaoke_lyrics_box.line_focus)
            {
               gui_set_text_color(MMI_KARAOKE_LYRICS_FOCUS_COLOR_FG); 
			
                mmi_karaoke_draw_text(&g_karaoke_lyrics_box.rgn_txt, &g_karaoke_lyrics_box.rgn_clip, 
                    pStr, 0, 0, 0, -1);
            }
            else
            {
				font_r = (skin_r * (g_karaoke_lyrics_box.line_count *3 - (i*2)))/(g_karaoke_lyrics_box.line_count*4);
				font_g = (skin_g * (g_karaoke_lyrics_box.line_count * 3- (i*2)))/(g_karaoke_lyrics_box.line_count*4);
				font_b = (skin_b * (g_karaoke_lyrics_box.line_count * 3 - (i*2)))/(g_karaoke_lyrics_box.line_count*4);
				gui_set_text_color(gui_color(font_r, font_g, font_b)); 
                mmi_karaoke_draw_text(&g_karaoke_lyrics_box.rgn_txt, &g_karaoke_lyrics_box.rgn_clip, 
                    pStr, 0, 0, 0, -1);
            } 
         
            pStr[nLen] = u16Tmp;
        }
        g_karaoke_lyrics_box.rgn_txt.y += g_karaoke_lyrics_box.line_height;        
    }
    g_karaoke_lyrics_box.rgn_txt.x = x;
    g_karaoke_lyrics_box.rgn_txt.y = y;
    g_karaoke_lyrics_box.rgn_txt.h = h;   
    
   	gdi_layer_pop_and_restore_active();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x, y, x + w, y + h);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
* FUNCTION
*   mmi_karaoke_prepare_lyrics
* DESCRIPTION
*   prepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static void mmi_karaoke_prepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_lyrics_box.time_out   = 0;
    g_karaoke_lyrics_box.last_time  = (U16)(g_karaoke_cntx.new_play_time/MMI_KARAOKE_UI_UPDATE_PLAY_TIME);

    if (NULL == g_karaoke_lyrics)
    {
        g_karaoke_lyrics = lyrics_parse_create(MMI_KARAOKE_UI_UPDATE_PLAY_TIME,/*lyrics update ms*/
            mmi_karaoke_malloc_mem_lyrics, mmi_karaoke_free_mem_lyrics, 0);
    }    
    mmi_karaoke_parse_lyrics();
    if(g_karaoke_lyrics_box.is_ready)
    {
        mmi_karaoke_config_lyrics();
        mmi_karaoke_update_lyrics();
		//mmi_audply_reset_skin_layer();  //Need To DO
		mmi_karaoke_draw_lyrics();				
    }
    else
    {
        mmi_karaoke_unprepare_lyrics();
    }
}

static void mmi_karaoke_update_lyrics_on_time(void)
{
    U32 timerduration = 0;
	
    mdi_audio_get_progress_time(&g_karaoke_cntx.new_play_time);
	if(g_karaoke_cntx.new_play_time > g_karaoke_cntx.duration)
		g_karaoke_cntx.new_play_time = g_karaoke_cntx.duration;
	mmi_karaoke_update_lyrics();
	mmi_karaoke_draw_lyrics();
	
	if ((g_karaoke_cntx.new_play_time % 1000) > 500)
    {
	    timerduration = 1000 - (g_karaoke_cntx.new_play_time % 1000);
    }
	else
    {
	    timerduration = MMI_KARAOKE_UI_UPDATE_PLAY_TIME;
    }
	StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,timerduration,mmi_karaoke_update_lyrics_on_time);  //NEED TO DO
}


void mmi_karaoke_stop_update_lyric(void)
{
	mmi_karaoke_update_lyrics();
	mmi_karaoke_draw_lyrics();
}
#endif/*__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_get_record_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_karaoke_get_record_filepath(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_character_type filename[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type filename_without_ext[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
	FS_HANDLE handle;
	S32 result;
	kal_uint8 count=0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_karaoke_extract_filename(filename,g_karaoke_cntx.filefullname);
	mmi_karaoke_split_filename_ext(filename,filename_without_ext,ext);

	/* Check if destination folder exists before record. */
    kal_wsprintf((WCHAR*) filepath, "%c:\\%w", MMI_KARAOKE_DEFAULT_DRV, MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH);

	handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);
    if (handle < FS_NO_ERROR)
    {
        if (handle == FS_FAT_ALLOC_ERROR)
        {
            return;
        }
        
        handle = FS_CreateDir(filepath);
        if(FS_NO_ERROR != handle)
        {
            return;
        }
        else
        {
            FS_SetAttributes(filepath, FS_ATTR_DIR);
			FS_Close(handle);
        }
    }
    else
    {
        FS_Close(handle);
    }

    /* Get full path */
	kal_wsprintf(
            filepath,
            "%c:\\%w%w.wav",
            MMI_KARAOKE_DEFAULT_DRV,
            MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH,
            filename_without_ext);
	/* Check if filename duplicate */
    handle = FS_Open(filepath, FS_READ_ONLY);
	if (handle < FS_NO_ERROR)
    {
    	return;
    }
	
	FS_Close(handle);
	
    for (count = 1; count < 100; count++)
    {
        kal_wsprintf(
            filepath,
            "%c:\\%w%w%d.wav",
            MMI_KARAOKE_DEFAULT_DRV,
            MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH,
            filename_without_ext,
            count);   

        /* Check if filename duplicate */
        handle = FS_Open(filepath, FS_READ_ONLY);
        if (handle < FS_NO_ERROR)
        {
        	return;
        }
		
		FS_Close(handle);
    }
	
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_get_src_lyric_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] filepath
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_karaoke_get_src_lyric_filepath(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16*    media_file_path;
    U16    meta_title[255+2];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	media_file_path = g_karaoke_cntx.filefullname;
	mmi_karaoke_extract_filename(meta_title,media_file_path);
   
    lyrics_convert_file_name(media_file_path, 
        meta_title, filepath); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_get_rec_lyric_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] filepath
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_karaoke_get_rec_lyric_folder(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Check if destination folder exists before record. */
    kal_wsprintf((WCHAR*) filepath, "%c:\\%w", MMI_KARAOKE_DEFAULT_DRV, MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH);
    srv_fmgr_fs_create_folder((const WCHAR *)filepath);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_get_rec_lyric_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] filepath
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_karaoke_get_rec_lyric_filepath(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_character_type filename[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type filename_without_ext[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
	UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
	S32 result;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_karaoke_extract_filename(filename,g_karaoke_cntx.Rec_filepath);
	mmi_karaoke_split_filename_ext(filename,filename_without_ext,ext);

	/* Check if destination folder exists before record. */
    kal_wsprintf((WCHAR*) filepath, "%c:\\%w", MMI_KARAOKE_DEFAULT_DRV, MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH);
    result = srv_fmgr_fs_create_folder((const WCHAR *)filepath);

    if(result != FS_NO_ERROR)
    {
        return;
    }

    /* Get full path */
	kal_wsprintf(
            filepath,
            "%c:\\%w%w.lrc",
            MMI_KARAOKE_DEFAULT_DRV,
            MMI_KARAOKE_RECORD_LIST_DEFAULT_PATH,
            filename_without_ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_play_record_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_karaoke_play_record_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 1, event->evt_id);
    switch (event->evt_id)
    {
    	case EVT_ID_GROUP_ACTIVE:
		{
			mdi_audio_suspend_background_play();
			break;
    	}
    	case EVT_ID_GROUP_DEINIT:
		{
            mmi_karaoke_clear();
			mdi_audio_resume_background_play();
	        StopTimer(KARAOKE_DELAY_PLAY_TIMER);
			break;
    	}
        case EVT_ID_SCRN_ACTIVE:
            mmi_karaoke_entry_play_record_screen();
            break;
        case EVT_ID_SCRN_INACTIVE:
            mmi_karaoke_exit_play_record_screen();
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_play_pause_record_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_play_pause_record_file(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.is_playing_records == KAL_TRUE)
	{   
	    mdi_audio_stop_file();
		dm_add_softkey_id(STR_GLOBAL_PLAY, STR_GLOBAL_BACK);
		dm_redraw_category_screen();
		SetLeftSoftkeyFunction(mmi_karaoke_play_pause_record_file, KEY_EVENT_UP);
		StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
		g_karaoke_cntx.is_playing_records = KAL_FALSE;
		g_karaoke_cntx.is_paused = KAL_TRUE;
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
		dm_add_softkey_id(STR_GLOBAL_PAUSE, STR_GLOBAL_BACK);
		dm_redraw_category_screen();
		SetLeftSoftkeyFunction(mmi_karaoke_play_pause_record_file, KEY_EVENT_UP);
		if(g_karaoke_lyrics == NULL)
			StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,MMI_KARAOKE_UI_UPDATE_PLAY_TIME,mmi_karaoke_redraw_main_progressbar);
		else
		    StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,MMI_KARAOKE_UI_UPDATE_PLAY_TIME,mmi_karaoke_update_lyrics_on_time);
        g_karaoke_cntx.is_playing_records = KAL_TRUE;
		g_karaoke_cntx.is_paused = KAL_FALSE;
		//if (result == MDI_AUDIO_END_OF_FILE)
		//    mmi_karaoke_play_record_callback_hdlr(MDI_AUDIO_END_OF_FILE,NULL);

		mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PLAY_RECORD, mmi_karaoke_event_hdlr, NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_resing_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_resing_confirm_cb(mmi_alert_result_evt_struct *evt)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        	case MMI_ALERT_CNFM_YES:
            {
                g_karaoke_cntx.need_resume = KAL_FALSE;
				g_karaoke_cntx.need_resing = KAL_TRUE;
				g_karaoke_cntx.is_interrupted = KAL_FALSE;
				if(g_karaoke_cntx.mdi_callback_registed)
				{
					mdi_audio_clear_interrupt_callback();
					g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
				}
				//mdi_audio_resume_background_play();
				mdi_audio_stop_file();
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
			    FS_Delete(g_karaoke_cntx.Rec_filepath);
        		break;
            }
			
            case MMI_ALERT_CNFM_NO:
				g_karaoke_cntx.need_resume = KAL_TRUE;
              	mmi_frm_scrn_close_active_id();
              	break;            
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_finish_sing_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_finish_sing_confirm_cb(mmi_alert_result_evt_struct *evt)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        	case MMI_ALERT_CNFM_YES:
            {
                g_karaoke_cntx.need_resume = KAL_FALSE;
				g_karaoke_cntx.is_interrupted = KAL_FALSE;
				if(g_karaoke_cntx.is_singing)
				{
				    g_karaoke_cntx.is_singing = KAL_FALSE;
					if(g_karaoke_cntx.mdi_callback_registed)
					{
						mdi_audio_clear_interrupt_callback();
						g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
					}
					//mdi_audio_resume_background_play();
				    mdi_audio_stop_file();
				}
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
        		break;
            }
			
            case MMI_ALERT_CNFM_NO:
				g_karaoke_cntx.need_resume = KAL_TRUE;
              	mmi_frm_scrn_close_active_id();
				//GoBackToHistory();
              	break;            
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_resing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_resing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //MMI_ASSERT(group_id != GRP_ID_INVALID);
    //mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL);
	
    if(mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    }
	g_karaoke_cntx.need_resume = KAL_TRUE;
	do {
    	mmi_confirm_property_struct arg;
    	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
		arg.parent_id = GRP_ID_KARAOKE_SING;
    	arg.callback = (mmi_proc_func)mmi_karaoke_resing_confirm_cb;
    	mmi_confirm_display((WCHAR *)(GetString(STR_ID_KARAOKE_RETRY_ASK)), MMI_EVENT_QUERY, &arg);
    } while(0);
	g_karaoke_cntx.need_resume = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_origin_sing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_origin_sing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.need_resume = KAL_TRUE;
	g_karaoke_cntx.origin_enable = !g_karaoke_cntx.origin_enable;
	
	if(g_karaoke_cntx.origin_enable)
	    mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
	else
		mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
	
    if(mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    }
}

#ifdef __LINE_IN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_force_use_linein_mic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_force_use_linein_mic(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.need_resume = KAL_TRUE;
	g_karaoke_cntx.force_use_linein_mice = !g_karaoke_cntx.force_use_linein_mice;
	
	if(g_karaoke_cntx.force_use_linein_mice)
	    mdi_audio_force_use_linein_mic(KAL_TRUE);
	else
		mdi_audio_force_use_linein_mic(KAL_FALSE);
	
    if(mmi_frm_group_is_present(GRP_ID_KARAOKE_LIST_OPTION))
    {
        mmi_frm_group_close(GRP_ID_KARAOKE_LIST_OPTION);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_prev_next_icon
 * DESCRIPTION
 *  redraw karaoke animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_prev_next_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	GDI_HANDLE img_handle;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	img_handle = GDI_ERROR_HANDLE;
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(karaoke_osd_layer);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_anim_set_blt_after_callback(NULL);//(mmi_audply_anim_blt_after_callback);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_layer_push_and_set_clip(KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W,
        KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H);
	gdi_draw_solid_rect(KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W,
        KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H,
        GDI_COLOR_TRANSPARENT);
    gdi_image_draw_animation(
        KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        get_image(IMG_ID_KARAOKE_PLAY_REC_PREV),
        &img_handle);

    /* gdi will not blt first frame, so we need blt it self */
    gdi_layer_blt_previous( KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W,
        KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H);
    gdi_layer_pop_clip();

	gdi_layer_push_and_set_clip(KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W,
		KARAOKE_NEXT_ICON_Y + KARAOKE_NEXT_ICON_H);
	gdi_draw_solid_rect(KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W,
		KARAOKE_NEXT_ICON_Y + KARAOKE_NEXT_ICON_H,GDI_COLOR_TRANSPARENT);
	gdi_image_draw_animation(
		KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		get_image(IMG_ID_KARAOKE_PLAY_REC_NEXT),
		&img_handle);

	/* gdi will not blt first frame, so we need blt it self */
	gdi_layer_blt_previous( KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W,
		KARAOKE_NEXT_ICON_Y + KARAOKE_NEXT_ICON_H);
	gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
}

//#ifdef  __MMI_BTD_BOX_UI_STYLE__

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_prev_highlite_icon
 * DESCRIPTION
 *  draw karaoke prev button down highlite icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_prev_highlite_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 w_fg, h_fg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(karaoke_osd_layer);
    gdi_push_and_set_alpha_blending_source_layer(karaoke_osd_layer);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_anim_set_blt_after_callback(NULL);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_image_get_dimension(get_image(IMG_ID_KARAOKE_PLAY_REC_PREV), &w_fg, &h_fg);

    gdi_layer_push_and_set_clip(
        KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        KARAOKE_PREV_ICON_X + w_fg,
        KARAOKE_PREV_ICON_Y + h_fg);
	gui_draw_filled_area(0,0,UI_device_width-1,UI_device_height-1, 
 	       current_MMI_theme->sub_menu_bkg_filler);
    /* draw button */
    gdi_image_draw(KARAOKE_PREV_ICON_X, KARAOKE_PREV_ICON_Y, get_image(IMG_ID_KARAOKE_PLAY_REC_PREV));
    /* draw highlite*/
    gdi_image_draw_resized(
        KARAOKE_PREV_ICON_X, 
        KARAOKE_PREV_ICON_Y+2, 
        w_fg-5, 
        h_fg-5, 
        get_image(IMG_ID_KARAOKE_PLAY_REC_FG_DOWN));

    gdi_layer_blt_previous(
        KARAOKE_PREV_ICON_X,
        KARAOKE_PREV_ICON_Y,
        KARAOKE_PREV_ICON_X + w_fg,
        KARAOKE_PREV_ICON_Y + h_fg);
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_prev_next_down_icon
 * DESCRIPTION
 *  draw karaoke next button down highlite icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_next_highlite_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 w_fg, h_fg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(karaoke_osd_layer);
    gdi_push_and_set_alpha_blending_source_layer(karaoke_osd_layer);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_anim_set_blt_after_callback(NULL);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_image_get_dimension(get_image(IMG_ID_KARAOKE_PLAY_REC_NEXT), &w_fg, &h_fg);

	gdi_layer_push_and_set_clip(
        KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		KARAOKE_NEXT_ICON_X + w_fg,
		KARAOKE_NEXT_ICON_Y + h_fg);
	gui_draw_filled_area(0,0,UI_device_width-1,UI_device_height-1, 
 	       current_MMI_theme->sub_menu_bkg_filler);
    /* draw button */
    gdi_image_draw(KARAOKE_NEXT_ICON_X, KARAOKE_NEXT_ICON_Y, get_image(IMG_ID_KARAOKE_PLAY_REC_NEXT));
    /* draw highlite*/
    gdi_image_draw_resized(
        KARAOKE_NEXT_ICON_X+3, 
        KARAOKE_NEXT_ICON_Y+2, 
        w_fg-5, 
        h_fg-5, 
        get_image(IMG_ID_KARAOKE_PLAY_REC_FG_DOWN));

	/* gdi will not blt first frame, so we need blt it self */
	gdi_layer_blt_previous(
	    KARAOKE_NEXT_ICON_X,
		KARAOKE_NEXT_ICON_Y,
		KARAOKE_NEXT_ICON_X + w_fg,
		KARAOKE_NEXT_ICON_Y + h_fg);
	gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
}
//#endif /*  __MMI_BTD_BOX_UI_STYLE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_finish_sing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_finish_sing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //MMI_ASSERT(group_id != GRP_ID_INVALID);
    //mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL);
    g_karaoke_cntx.need_resume = KAL_TRUE;
	do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.parent_id = GRP_ID_KARAOKE_SING;
	arg.callback = (mmi_proc_func)mmi_karaoke_finish_sing_confirm_cb;
	mmi_confirm_display((WCHAR *)GetString(STR_ID_KARAOKE_FINISH_ASK), MMI_EVENT_QUERY, &arg);
	} while(0);
	g_karaoke_cntx.need_resume = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_prev_next_key_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_prev_next_key_down(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.key_longpress = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_play_record_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_play_record_next(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.key_longpress)
	{
        g_karaoke_cntx.key_longpress = MMI_FALSE;
		return;
	}
//#ifdef  __MMI_BTD_BOX_UI_STYLE__
	mmi_karaoke_redraw_next_highlite_icon();
	kal_sleep_task(10);
//#endif
    mmi_karaoke_exit_play_record_screen();
	g_karaoke_cntx.current_list.list_data.highlight++;
	g_karaoke_cntx.current_list.list_data.highlight%=g_karaoke_cntx.current_list.list_data.total;
    g_karaoke_cntx.record_list_highlight_index = g_karaoke_cntx.current_list.list_data.highlight;
	g_karaoke_cntx.is_paused = MMI_TRUE;
	mmi_karaoke_entry_play_record_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_play_record_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_play_record_prev(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.key_longpress)
	{
        g_karaoke_cntx.key_longpress = MMI_FALSE;
		return;
	}
	
//#ifdef  __MMI_BTD_BOX_UI_STYLE__
	mmi_karaoke_redraw_prev_highlite_icon();
	kal_sleep_task(10);
//#endif

    mmi_karaoke_exit_play_record_screen();
	if(g_karaoke_cntx.current_list.list_data.highlight == 0)
		g_karaoke_cntx.current_list.list_data.highlight=g_karaoke_cntx.current_list.list_data.total -1;
	else
	{
		g_karaoke_cntx.current_list.list_data.highlight--;
		g_karaoke_cntx.current_list.list_data.highlight%=g_karaoke_cntx.current_list.list_data.total;
	}
    g_karaoke_cntx.record_list_highlight_index = g_karaoke_cntx.current_list.list_data.highlight;
	g_karaoke_cntx.is_paused = MMI_TRUE;
	mmi_karaoke_entry_play_record_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_aud_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_karaoke_cntx.aud_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.aud_vol < MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.aud_vol++;
	}
	else if(g_karaoke_cntx.aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	{
	    g_karaoke_cntx.aud_vol = MDI_KARAOKE_VOL_EX_MAX;
	}
	else
	{
        g_karaoke_cntx.aud_vol = KARAOKE_AUD_VOL_DEFAULT;
	}
	mmi_karaoke_update_audio_bar(g_karaoke_cntx.aud_vol);
	if(g_karaoke_cntx.aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_set_karaoke_digitgain_req(KARAOKE_AUD_GAIN_MAX,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
	else
		media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
	
	if( g_karaoke_cntx.aud_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_AUD_VOL, &g_karaoke_cntx.aud_vol, DS_BYTE);
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_INC_AUD_VOL, g_karaoke_cntx.aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_dec_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_aud_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_karaoke_cntx.aud_vol > MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.aud_vol--;
	}
	else if(g_karaoke_cntx.aud_vol == MDI_KARAOKE_VOL_EX_MIN)
	{
	    g_karaoke_cntx.aud_vol = MDI_KARAOKE_VOL_EX_MIN;
	}
	else
	{
        g_karaoke_cntx.aud_vol = KARAOKE_AUD_VOL_DEFAULT;
	}
	mmi_karaoke_update_audio_bar(g_karaoke_cntx.aud_vol);
	media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
										g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.aud_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_AUD_VOL, &g_karaoke_cntx.aud_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_DEC_AUD_VOL, g_karaoke_cntx.aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_mic_vol(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(g_karaoke_cntx.mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.mic_vol < MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.mic_vol++;
	}
	else if(g_karaoke_cntx.mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.mic_vol = MDI_KARAOKE_VOL_EX_MAX;
	}
	else
	{
		g_karaoke_cntx.mic_vol =KARAOKE_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.mic_vol);
	if(g_karaoke_cntx.mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											KARAOKE_MIC_GAIN_MAX);
	else
		media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_MIC_VOL, &g_karaoke_cntx.mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_INC_MIC_VOL, g_karaoke_cntx.mic_vol);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_dec_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_mic_vol(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	if(g_karaoke_cntx.mic_vol > MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.mic_vol--;
	}
	else if(g_karaoke_cntx.mic_vol == MDI_KARAOKE_VOL_EX_MIN)
	{
		g_karaoke_cntx.mic_vol = MDI_KARAOKE_VOL_EX_MIN;
	}
	else
	{
		g_karaoke_cntx.mic_vol = KARAOKE_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.mic_vol);
	media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
										g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
	if( g_karaoke_cntx.mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_MIC_VOL, &g_karaoke_cntx.mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_DEC_MIC_VOL, g_karaoke_cntx.mic_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_set_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index[in]: the aud volume index to set
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_set_aud_vol(kal_uint8 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index >= MDI_KARAOKE_VOL_EX_MIN && index <= MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.aud_vol = index;
	}
	else
	{
        g_karaoke_cntx.aud_vol = KARAOKE_AUD_VOL_DEFAULT;
	}
	mmi_karaoke_update_audio_bar(g_karaoke_cntx.aud_vol);
	if(g_karaoke_cntx.aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_set_karaoke_digitgain_req(KARAOKE_AUD_GAIN_MAX,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
	else
		media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.aud_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_AUD_VOL, &g_karaoke_cntx.aud_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SET_AUD_VOL, g_karaoke_cntx.aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_set_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index[IN]: the MIC volume index to set
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_set_mic_vol(kal_uint8 index)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(index >= MDI_KARAOKE_VOL_EX_MIN && index <= MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.mic_vol = index;
	}
	else
	{
		g_karaoke_cntx.mic_vol = KARAOKE_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.mic_vol);
	if(g_karaoke_cntx.mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											KARAOKE_MIC_GAIN_MAX);
	else
		media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,
											g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
	
	if( g_karaoke_cntx.mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_MIC_VOL, &g_karaoke_cntx.mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SET_MIC_VOL, g_karaoke_cntx.mic_vol);
}


#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_remix_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_remix_aud_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.remix_aud_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.remix_aud_vol < MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.remix_aud_vol++;
	}
	else if(g_karaoke_cntx.remix_aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	{
	    g_karaoke_cntx.remix_aud_vol = MDI_KARAOKE_VOL_EX_MAX;
	}
	else
	{
        g_karaoke_cntx.remix_aud_vol = KARAOKE_REMIX_AUD_VOL_DEFAULT;
	}
	mmi_karaoke_update_audio_bar(g_karaoke_cntx.remix_aud_vol);
	if(g_karaoke_cntx.remix_aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_karaoke_set_remix_audio_gain_req(KARAOKE_REMIX_AUD_GAIN_MAX);
	else
		media_aud_karaoke_set_remix_audio_gain_req(g_karaoke_cntx.remix_aud_vol*KARAOKE_REMIX_AUD_GAIN_UNIT);

	if( g_karaoke_cntx.remix_aud_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_AUD_VOL, &g_karaoke_cntx.remix_aud_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_INC_REMIX_AUD_VOL, g_karaoke_cntx.remix_aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_dec_remix_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_remix_aud_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.remix_aud_vol > MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.remix_aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.remix_aud_vol--;
	}
	else if(g_karaoke_cntx.remix_aud_vol == MDI_KARAOKE_VOL_EX_MIN)
	{
	    g_karaoke_cntx.remix_aud_vol = MDI_KARAOKE_VOL_EX_MIN;
	}
	else
	{
        g_karaoke_cntx.remix_aud_vol = KARAOKE_REMIX_AUD_VOL_DEFAULT;
	}
    mmi_karaoke_update_audio_bar(g_karaoke_cntx.remix_aud_vol);
	media_aud_karaoke_set_remix_audio_gain_req(g_karaoke_cntx.remix_aud_vol*KARAOKE_REMIX_AUD_GAIN_UNIT);

	if( g_karaoke_cntx.remix_aud_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_AUD_VOL, &g_karaoke_cntx.remix_aud_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_DEC_REMIX_AUD_VOL, g_karaoke_cntx.remix_aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_remix_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_remix_mic_vol(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(g_karaoke_cntx.remix_mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.remix_mic_vol < MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.remix_mic_vol++;
	}
	else if(g_karaoke_cntx.remix_mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.remix_mic_vol = MDI_KARAOKE_VOL_EX_MAX;
	}
	else
	{
		g_karaoke_cntx.remix_mic_vol = KARAOKE_REMIX_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.remix_mic_vol);
	if(g_karaoke_cntx.remix_mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_karaoke_set_remix_voice_gain_req(KARAOKE_REMIX_MIC_GAIN_MAX);
	else
		media_aud_karaoke_set_remix_voice_gain_req(g_karaoke_cntx.remix_mic_vol*KARAOKE_REMIX_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.remix_mic_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_MIC_VOL, &g_karaoke_cntx.remix_mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_INC_REMIX_MIC_VOL, g_karaoke_cntx.remix_mic_vol);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_dec_remix_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_remix_mic_vol(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(g_karaoke_cntx.remix_mic_vol > MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.remix_mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.remix_mic_vol--;
	}
	else if(g_karaoke_cntx.remix_mic_vol == MDI_KARAOKE_VOL_EX_MIN)
	{
		g_karaoke_cntx.remix_mic_vol = MDI_KARAOKE_VOL_EX_MIN;
	}
	else
	{
		g_karaoke_cntx.remix_mic_vol = KARAOKE_REMIX_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.remix_mic_vol);
	media_aud_karaoke_set_remix_voice_gain_req(g_karaoke_cntx.remix_mic_vol*KARAOKE_REMIX_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.remix_mic_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_MIC_VOL, &g_karaoke_cntx.remix_mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_DEC_REMIX_MIC_VOL, g_karaoke_cntx.remix_mic_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_set_remix_aud_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index[in]: the remix aud volume index to set
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_set_remix_aud_vol(kal_uint8 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(index >= MDI_KARAOKE_VOL_EX_MIN && index <= MDI_KARAOKE_VOL_EX_MAX)
    {
        g_karaoke_cntx.remix_aud_vol = index;
	}
	else
	{
        g_karaoke_cntx.remix_aud_vol = KARAOKE_REMIX_AUD_VOL_DEFAULT;
	}
	mmi_karaoke_update_audio_bar(g_karaoke_cntx.remix_aud_vol);
	if(g_karaoke_cntx.remix_aud_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_karaoke_set_remix_audio_gain_req(KARAOKE_REMIX_AUD_GAIN_MAX);
	else
		media_aud_karaoke_set_remix_audio_gain_req(g_karaoke_cntx.remix_aud_vol*KARAOKE_REMIX_AUD_GAIN_UNIT);

	if( g_karaoke_cntx.remix_aud_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_aud_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_AUD_VOL, &g_karaoke_cntx.remix_aud_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SET_REMIX_AUD_VOL, g_karaoke_cntx.remix_aud_vol);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_set_remix_mic_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index[IN]: the remix MIC volume index to set
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_set_remix_mic_vol(kal_uint8 index)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(g_karaoke_cntx.remix_mic_vol >= MDI_KARAOKE_VOL_EX_MIN && g_karaoke_cntx.remix_mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
	{
		g_karaoke_cntx.remix_mic_vol = index;
	}
	else
	{
		g_karaoke_cntx.remix_mic_vol = KARAOKE_REMIX_MIC_VOL_DEFAULT;
	}
	mmi_karaoke_update_voice_bar(g_karaoke_cntx.remix_mic_vol);
	if(g_karaoke_cntx.remix_mic_vol == MDI_KARAOKE_VOL_EX_MAX)
	    media_aud_karaoke_set_remix_voice_gain_req(KARAOKE_REMIX_MIC_GAIN_MAX);
	else
		media_aud_karaoke_set_remix_voice_gain_req(g_karaoke_cntx.remix_mic_vol*KARAOKE_REMIX_MIC_GAIN_UNIT);

	if( g_karaoke_cntx.remix_mic_vol >= MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.remix_mic_vol <= MDI_KARAOKE_VOL_EX_MAX)
		WriteValueSlim(NVRAM_KARAOKE_REMIX_MIC_VOL, &g_karaoke_cntx.remix_mic_vol, DS_BYTE);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_SET_REMIX_MIC_VOL, g_karaoke_cntx.remix_mic_vol);
}

#endif /*__KARAOKE_NEED_KEEP_SRC_PATH__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_switch_vol_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_switch_vol_focus(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef  __MMI_BTD_BOX_UI_STYLE__
	g_karaoke_cntx.key_longpress=MMI_TRUE;
	#endif
    g_karaoke_cntx.focus_on_aud_vol = !g_karaoke_cntx.focus_on_aud_vol;
	mmi_karaoke_update_select();
	StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
	WriteValueSlim(NVRAM_KARAOKE_FOCUS_AUD, &g_karaoke_cntx.focus_on_aud_vol, DS_BYTE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_set_vol_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_set_vol_focus(MMI_BOOL focus_on_aud_vol)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_karaoke_cntx.focus_on_aud_vol = focus_on_aud_vol;
	WriteValueSlim(NVRAM_KARAOKE_FOCUS_AUD, &g_karaoke_cntx.focus_on_aud_vol, DS_BYTE);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_total_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_karaoke_cntx.vol < MDI_KARAOKE_VOL_EX_MAX)
	{	
	    S16 error;	
		ReadValue(NVRAM_KARAOKE_VOL,
			&g_karaoke_cntx.vol,
			DS_BYTE,
			&error);
		g_karaoke_cntx.vol++;
		if(g_karaoke_cntx.vol <= MDI_KARAOKE_VOL_EX_MAX)
		{
			WriteValue(NVRAM_KARAOKE_VOL,&g_karaoke_cntx.vol, DS_BYTE, &error);
			if(g_karaoke_cntx.is_singing || g_karaoke_cntx.is_playing_records)
			    mdi_audio_set_volume(VOL_TYPE_MEDIA,MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol));
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_total_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( g_karaoke_cntx.vol > MDI_KARAOKE_VOL_EX_MIN && 
		g_karaoke_cntx.vol <=MDI_KARAOKE_VOL_EX_MAX )
	{	
	    S16 error;	
		ReadValue(NVRAM_KARAOKE_VOL,
			&g_karaoke_cntx.vol,
			DS_BYTE,
			&error);
		g_karaoke_cntx.vol--;
		WriteValue(NVRAM_KARAOKE_VOL,&g_karaoke_cntx.vol,DS_BYTE, &error);
		if(g_karaoke_cntx.is_singing || g_karaoke_cntx.is_playing_records)
		    mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_EX_MUTE(g_karaoke_cntx.vol));
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_inc_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_INC_VOL, g_karaoke_cntx.is_singing,g_karaoke_cntx.focus_on_aud_vol);
	
#ifdef	__MMI_BTD_BOX_UI_STYLE__
	if(g_karaoke_cntx.key_longpress)
	{
		g_karaoke_cntx.key_longpress = MMI_FALSE;
	    return;
	}
#endif
    if(g_karaoke_cntx.aud_mute || g_karaoke_cntx.mic_mute)
	{
		if(g_karaoke_cntx.focus_on_aud_vol)
			g_karaoke_cntx.aud_mute = MMI_FALSE;
		else
			g_karaoke_cntx.mic_mute = MMI_FALSE;
	}
	if(!(mmi_frm_group_is_present(GPR_ID_KARAOKE_VOLUME)))
	{
		mmi_id group_id,parent_id;
		g_karaoke_cntx.need_resume = KAL_TRUE;
		parent_id = mmi_frm_group_get_active_id();
		group_id = mmi_frm_group_create_ex(parent_id, GPR_ID_KARAOKE_VOLUME, mmi_karaoke_volume_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		MMI_ASSERT(group_id != GRP_ID_INVALID);
		mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_VOLUME, mmi_karaoke_volume_proc, NULL);
		g_karaoke_cntx.need_resume = KAL_FALSE;
	}

	if(g_karaoke_cntx.is_singing)
	{
        if(g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_inc_aud_vol();
		else
			mmi_karaoke_inc_mic_vol();
	}
	else
	{
	    #ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
		if(g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_inc_remix_aud_vol();
		else /*__KARAOKE_NEED_KEEP_SRC_PATH__*/
			mmi_karaoke_inc_remix_mic_vol();
		#else
        mmi_karaoke_inc_total_vol();
		#endif /*__KARAOKE_NEED_KEEP_SRC_PATH__*/
	}

	StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_inc_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_dec_vol(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_DEC_VOL, g_karaoke_cntx.is_singing,g_karaoke_cntx.focus_on_aud_vol);
	
    #ifdef	__MMI_BTD_BOX_UI_STYLE__
	if(g_karaoke_cntx.key_longpress)
	{
		g_karaoke_cntx.key_longpress = MMI_FALSE;
		return;
	}
    #endif
	if(!(mmi_frm_group_is_present(GPR_ID_KARAOKE_VOLUME)))
	{
		mmi_id group_id,parent_id;
		g_karaoke_cntx.need_resume = KAL_TRUE;
		parent_id = mmi_frm_group_get_active_id();
		group_id = mmi_frm_group_create_ex(parent_id, GPR_ID_KARAOKE_VOLUME, mmi_karaoke_volume_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		MMI_ASSERT(group_id != GRP_ID_INVALID);
		mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_VOLUME, mmi_karaoke_volume_proc, NULL);
		g_karaoke_cntx.need_resume = KAL_FALSE;
	}
	
    if(g_karaoke_cntx.is_singing)
	{
        if(g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_dec_aud_vol();
		else
			mmi_karaoke_dec_mic_vol();
	}
	else
	{
	    #ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
		if(g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_dec_remix_aud_vol();
		else /*__KARAOKE_NEED_KEEP_SRC_PATH__*/
			mmi_karaoke_dec_remix_mic_vol();
		#else
        mmi_karaoke_dec_total_vol();
		#endif /*__KARAOKE_NEED_KEEP_SRC_PATH__*/
	}
	
	StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
}


#ifdef __MMI_TOUCH_SCREEN__
void mmi_karaoke_pen_down_hdlr(mmi_pen_point_struct pos)
{
	if((KARAOKE_PREV_ICON_X <=pos.x && pos.x<=(KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W))
		&&(KARAOKE_PREV_ICON_Y<=pos.y && pos.y <= (KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H))) 
	{
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_PREV;
		mmi_karaoke_redraw_prev_highlite_icon();
		return;
	}
	else if((KARAOKE_NEXT_ICON_X <=pos.x && pos.x<=(KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W))
		&&(KARAOKE_NEXT_ICON_Y<=pos.y && pos.y <= (KARAOKE_NEXT_ICON_Y + KARAOKE_NEXT_ICON_H))) 
	{
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_NEXT;
		mmi_karaoke_redraw_next_highlite_icon();
		return;
	}
	
	wgui_general_pen_down_hdlr(pos);
}

void mmi_karaoke_pen_move_hdlr(mmi_pen_point_struct pos)
{
	if (g_karaoke_cntx.pen_status != MMI_KARAOKE_PEN_STATUS_NONE &&
		(pos.x < KARAOKE_PREV_ICON_X || pos.x > (KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W) ||
		 (pos.x > (KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W) && pos.x < KARAOKE_NEXT_ICON_X) ||
		 pos.y < KARAOKE_PREV_ICON_Y || pos.y > (KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H)))
	{
		mmi_karaoke_redraw_prev_next_icon();
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_NONE;
	}
	
	wgui_general_pen_move_hdlr(pos);
}

void mmi_karaoke_pen_up_hdlr(mmi_pen_point_struct pos)
{
	if (g_karaoke_cntx.pen_status != MMI_KARAOKE_PEN_STATUS_NONE)
	{
		if((KARAOKE_PREV_ICON_X <=pos.x && pos.x<=(KARAOKE_PREV_ICON_X + KARAOKE_PREV_ICON_W))
			&&(KARAOKE_PREV_ICON_Y<=pos.y && pos.y <= (KARAOKE_PREV_ICON_Y + KARAOKE_PREV_ICON_H))) 
		{
			mmi_karaoke_play_record_prev();
			return;
		}
		else if((KARAOKE_NEXT_ICON_X <=pos.x && pos.x<=(KARAOKE_NEXT_ICON_X + KARAOKE_NEXT_ICON_W))
			&&(KARAOKE_NEXT_ICON_Y<=pos.y && pos.y <= (KARAOKE_NEXT_ICON_Y + KARAOKE_NEXT_ICON_H))) 
		{
			mmi_karaoke_play_record_next();
			return;
		}
	}
	
	wgui_general_pen_up_hdlr(pos);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_save_record_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_save_record_file(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //MMI_ASSERT(group_id != GRP_ID_INVALID);
    //mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_SING, mmi_karaoke_sing_proc, NULL);
	if(g_karaoke_cntx.mdi_callback_registed)
	{
		mdi_audio_clear_interrupt_callback();
		g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
	}
    mdi_audio_stop_file();
	memset((kal_char*)g_karaoke_cntx.Rec_filepath,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
	memset((kal_char*)g_karaoke_cntx.filefullname,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
    g_karaoke_cntx.record_auto_gen = MMI_FALSE;
	g_karaoke_cntx.is_interrupted = KAL_FALSE;
	g_karaoke_cntx.play_record_for_reviewing = KAL_FALSE;
	if(mmi_frm_group_is_present(GRP_ID_KARAOKE_SING))
	    mmi_frm_group_close(GRP_ID_KARAOKE_SING);
	else
		mmi_frm_group_close(GRP_ID_KARAOKE_PLAY_RECORD);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_delete_record_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_karaoke_delete_record_confirm_cb(mmi_alert_result_evt_struct *evt)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        	case MMI_ALERT_CNFM_YES:
            {   
				UI_character_type rec_lyricpath[(SRV_FMGR_PATH_MAX_LEN+1) + 1 +17];
				g_karaoke_cntx.need_resume = KAL_FALSE;
				g_karaoke_cntx.play_record_for_reviewing = KAL_FALSE;
				g_karaoke_cntx.is_interrupted = KAL_FALSE;
				g_karaoke_cntx.is_playing_records= KAL_FALSE;

				if(g_karaoke_cntx.mdi_callback_registed)
				{
					mdi_audio_clear_interrupt_callback();
					g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
				}
				mdi_audio_stop_file();
				mmi_karaoke_get_rec_lyric_filepath(rec_lyricpath);
				if(rec_lyricpath[0] != NULL)
				    FS_Delete(rec_lyricpath);
			    FS_Delete(g_karaoke_cntx.Rec_filepath);
				memset((kal_char*)g_karaoke_cntx.Rec_filepath,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
				memset((kal_char*)g_karaoke_cntx.filefullname,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
				if(mmi_frm_group_is_present(GRP_ID_KARAOKE_SING))
				    mmi_frm_group_close(GRP_ID_KARAOKE_SING);
				else
					mmi_frm_group_close(GRP_ID_KARAOKE_PLAY_RECORD);

				//mdi_audio_resume_background_play();
        		break;
            }
			
			case MMI_POPUP_INTERRUPT_EXIT:
			case MMI_ALERT_CNFM_NO:
				if(g_karaoke_cntx.is_playing_records)
				{
					g_karaoke_cntx.need_resume = KAL_TRUE;
				}
				g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
              	//mmi_frm_scrn_close_active_id();
              	break;  
			/*	
            case MMI_ALERT_CNFM_NO:
				g_karaoke_cntx.need_resume = KAL_TRUE;
				g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
              	//mmi_frm_scrn_close_active_id();
              	break;    
              	*/
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_detelte_record_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_karaoke_detelte_record_file(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_karaoke_cntx.need_resume = KAL_TRUE;
	do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    if (mmi_frm_group_get_active_id() == GRP_ID_KARAOKE_PLAY_RECORD)
	    arg.parent_id = GRP_ID_KARAOKE_PLAY_RECORD;
    else
        arg.parent_id = GRP_ID_KARAOKE_SING;
	arg.callback = (mmi_proc_func)mmi_karaoke_delete_record_confirm_cb;
	mmi_confirm_display((WCHAR *)GetString(STR_ID_KARAOKE_DISCARD_RECORD_ASK), MMI_EVENT_QUERY, &arg);
	} while(0);
	g_karaoke_cntx.need_resume = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_animation
 * DESCRIPTION
 *  redraw karaoke animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __GDI_MEMORY_PROFILE_2__
/* under construction !*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/* under construction !*/
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
#endif
	if (g_karaoke_cntx.animation_hdlr != GDI_NULL_HANDLE)
		gdi_image_stop_animation(g_karaoke_cntx.animation_hdlr);
	
    gdi_layer_push_and_set_clip(LYRICS_PICTURE_X,
        LYRICS_PICTURE_Y,
        LYRICS_PICTURE_X + LYRICS_PICTURE_width,
        LYRICS_PICTURE_Y + LYRICS_PICTURE_height);
	gdi_draw_solid_rect(LYRICS_PICTURE_X,
        LYRICS_PICTURE_Y,
        LYRICS_PICTURE_X + LYRICS_PICTURE_width,
        LYRICS_PICTURE_Y + LYRICS_PICTURE_height,
        GDI_COLOR_TRANSPARENT);
    gdi_image_draw_animation(
        LYRICS_PICTURE_X,
        LYRICS_PICTURE_Y,
        get_image(IMG_ID_KARAOKE_PLAY_ANIMATION),
        &g_karaoke_cntx.animation_hdlr);

    gdi_layer_pop_clip();	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GDI_MEMORY_PROFILE_2__
/* under construction !*/
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_interrupt_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_karaoke_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_karaoke_cntx.mdi_callback_registed)
	{
		mdi_audio_clear_interrupt_callback();
		g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
	}
	g_karaoke_cntx.need_resume = KAL_FALSE;
	g_karaoke_cntx.is_playing_records = MMI_FALSE;
	g_karaoke_cntx.is_singing = MMI_FALSE;

	mdi_audio_stop_file();
	mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_interrupt_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_karaoke_interrupt_callback(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_karaoke_cntx.is_playing_records)
        return;

    mmi_karaoke_clear();
    
	mmi_frm_group_close(GRP_ID_KARAOKE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_sing_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_karaoke_sing_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_PROC, 2, event->evt_id);
    switch (event->evt_id)
    {
    	case EVT_ID_GROUP_ENTER:
		{
			mdi_audio_suspend_background_play();
			break;
    	}
    	case EVT_ID_GROUP_DEINIT:
		{
            mmi_karaoke_clear();
			mdi_audio_resume_background_play();
	        StopTimer(KARAOKE_DELAY_PLAY_TIMER);
			break;
    	}
        case EVT_ID_SCRN_ACTIVE:
        {
        	if(g_karaoke_cntx.need_resume && g_karaoke_cntx.is_interrupted&&g_karaoke_cntx.is_singing)
        		g_karaoke_cntx.is_interrupted = KAL_FALSE;
            if (g_karaoke_cntx.is_interrupted || g_karaoke_cntx.play_record_for_reviewing)
            {
        	    g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
        		//g_karaoke_cntx.is_paused = KAL_FALSE;
                mmi_karaoke_exit_sing_screen();    
                mmi_karaoke_entry_play_record_screen();
            }
            else
            {
                mmi_karaoke_entry_sing_screen();
            }
            break;
        }
        case EVT_ID_SCRN_INACTIVE:
        {
            mmi_karaoke_exit_sing_screen();
			if(g_karaoke_cntx.play_record_for_reviewing || g_karaoke_cntx.is_playing_records)
				mmi_karaoke_exit_play_record_screen();
            
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_sing_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_sing_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (result)
    {
        case MDI_AUDIO_TERMINATED:
		{
			/* handle result */
			if(g_karaoke_cntx.need_resing || g_karaoke_cntx.is_interrupted) //when resing or interrupted,not goto the play record screen
				return;
            
			g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
			g_karaoke_cntx.is_paused = KAL_FALSE;
            g_karaoke_cntx.need_resume = KAL_FALSE;
			StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
			if(g_karaoke_cntx.mdi_callback_registed)
			{
				mdi_audio_clear_interrupt_callback();
				g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
			}
			if(g_karaoke_cntx.is_singing)
			    mdi_audio_stop_file();
			mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
			g_karaoke_cntx.is_singing = KAL_FALSE;
			#ifdef __LINE_IN_SUPPORT__
			if(g_karaoke_cntx.force_use_linein_mice)
				mdi_audio_force_use_linein_mic(KAL_FALSE);
			#endif
            break;
        }
		case MDI_AUDIO_END_OF_FILE:
            {
                //mmi_id group_id,scrn_id;
				g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;
				g_karaoke_cntx.is_paused = KAL_FALSE;
                g_karaoke_cntx.need_resume = KAL_FALSE;
				StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
				if(g_karaoke_cntx.mdi_callback_registed)
				{
					mdi_audio_clear_interrupt_callback();
					g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
				}
				if(g_karaoke_cntx.is_singing)
				    mdi_audio_stop_file();
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
				g_karaoke_cntx.is_singing = KAL_FALSE;
				#ifdef __LINE_IN_SUPPORT__
				if(g_karaoke_cntx.force_use_linein_mice)
					mdi_audio_force_use_linein_mic(KAL_FALSE);
				#endif

                mmi_frm_group_close(GRP_ID_KARAOKE_SING);
				//mmi_frm_get_active_scrn_id(&group_id,&scrn_id);
				//if(scrn_id != SCR_ID_KARAOKE_SING)
                //    mmi_frm_scrn_close_active_id();
			    //group_id = mmi_frm_group_create_ex(GRP_ID_KARAOKE_SING, GRP_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			    //if(group_id != GRP_ID_INVALID);
			    //    mmi_frm_scrn_create(group_id, SCR_ID_KARAOKE_PLAY_RECORD, mmi_karaoke_play_record_proc, NULL);
            }
            break;
		case MDI_AUDIO_DISC_FULL:
		{
			mmi_popup_display_ext(
						STR_ID_KARAOKE_ERR_WRITE_DATA_FAIL, 
						MMI_EVENT_FAILURE, 
						NULL);
			StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
			if(g_karaoke_cntx.mdi_callback_registed)
			{
				mdi_audio_clear_interrupt_callback();
				g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
			}
			mdi_audio_stop_file();
			mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
			g_karaoke_cntx.need_resume = MMI_FALSE;
			g_karaoke_cntx.is_interrupted = KAL_TRUE;
			break;
		}
		case MDI_AUDIO_ERROR:
		default:
		{
			mmi_popup_display_ext(
						STR_ID_KARAOKE_ERR_SING_FAIL, 
						MMI_EVENT_FAILURE, 
						NULL);
			StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
			if(g_karaoke_cntx.mdi_callback_registed)
			{
				mdi_audio_clear_interrupt_callback();
				g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
			}
			mdi_audio_stop_file();
			mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
			g_karaoke_cntx.need_resume = MMI_FALSE;
			g_karaoke_cntx.is_interrupted = KAL_TRUE;
			break;
		}
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_play_record_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_play_record_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U16 group_id,scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* ignore it */
    if (!g_karaoke_cntx.is_playing_records)
    {
        return;
    }

    /* handle result */

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
			{
                g_karaoke_cntx.new_play_time = 0;
				g_karaoke_cntx.is_playing_records = KAL_FALSE;
				g_karaoke_cntx.is_paused = KAL_TRUE;
				mmi_frm_get_active_scrn_id(&group_id,&scrn_id);
				if(scrn_id == SCR_ID_KARAOKE_PLAY_RECORD || scrn_id == SCR_ID_KARAOKE_SING)
				{
				    g_karaoke_cntx.is_eof = KAL_TRUE;
				    mmi_karaoke_redraw_main_progressbar();
					kal_sleep_task(10);
					mmi_karaoke_draw_bg_progressbar(MMI_TRUE);
					mmi_karaoke_redraw_play_record_time();
					if(!g_karaoke_cntx.play_record_for_reviewing)
					{
					    dm_add_softkey_id(STR_GLOBAL_PLAY, STR_GLOBAL_BACK);
					    dm_redraw_category_screen();
					    SetLeftSoftkeyFunction(mmi_karaoke_play_pause_record_file, KEY_EVENT_UP);
					}
				}
				StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
				//mdi_audio_resume_background_play();
		    }
		    break;
			
        case MDI_AUDIO_TERMINATED:
        default:
            {
				StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
				mdi_audio_stop_file();
				//mdi_audio_resume_background_play();
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_entry_sing_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_entry_sing_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//S16 error;
	mdi_result result;
    BOOL gdi_freeze = KAL_FALSE;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(!g_karaoke_cntx.need_resume && !g_karaoke_cntx.play_record_for_reviewing)
    {
		if(srv_fmgr_drv_check_free_size((U8)MMI_KARAOKE_DEFAULT_DRV, 2) == FS_DISK_FULL)
		{
			mmi_frm_group_close(GRP_ID_KARAOKE_SING);
	        mmi_popup_display_ext(
							STR_ID_KARAOKE_ERR_DISC_FULL, 
							MMI_EVENT_FAILURE, 
							NULL);
			return;
		}

        mmi_karaoke_get_record_filepath(g_karaoke_cntx.Rec_filepath);
	}
	
	gdi_freeze = gdi_lcd_get_freeze();
	gdi_lcd_freeze(TRUE);
	gdi_layer_get_base_handle(&karaoke_osd_layer);
	ShowCategory8002Screen(STR_ID_KARAOKE_NAME,STR_GLOBAL_OPTIONS,STR_ID_KARAOKE_FINISH);
	SetLeftSoftkeyFunction(mmi_karaoke_list_entry_option, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_karaoke_finish_sing, KEY_EVENT_UP);
	
#ifdef  __MMI_BTD_BOX_UI_STYLE__
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
#else
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_UP);
#endif
	mmi_karaoke_redraw_background();

	g_karaoke_cntx.songtitle_x = TITLE_X;
	g_karaoke_cntx.songtitle_y = TITLE_Y;
	g_karaoke_cntx.songtitle_width  = TITLE_width;
	g_karaoke_cntx.songtitle_height = TITLE_height;
	if(!g_karaoke_cntx.need_resume && !g_karaoke_cntx.play_record_for_reviewing)
	    g_karaoke_cntx.is_singing = KAL_TRUE;
	
	mmi_karaoke_redraw_title();
	mmi_karaoke_redraw_time();
    if(g_karaoke_lyrics == NULL)
    {
        mmi_karaoke_redraw_animation();
        StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,MMI_KARAOKE_UI_UPDATE_PLAY_TIME,mmi_karaoke_redraw_time);
    }

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
    
	if(!g_karaoke_cntx.need_resume && !g_karaoke_cntx.play_record_for_reviewing)
    {
        //mdi_audio_suspend_background_play();
		g_karaoke_cntx.new_play_time = 0;
		g_karaoke_cntx.origin_enable = KAL_FALSE;
		#ifdef __LINE_IN_SUPPORT__
		g_karaoke_cntx.force_use_linein_mice = KAL_FALSE;
		#endif
		mdi_audio_get_duration(g_karaoke_cntx.filefullname,&g_karaoke_cntx.duration);
		if (0 == g_karaoke_cntx.duration)
		{
		    FS_Delete(g_karaoke_cntx.Rec_filepath);
			mmi_frm_group_close(GRP_ID_KARAOKE_SING);
			mmi_popup_display_ext(
									STR_ID_KARAOKE_ERR_SING_FAIL, 
									MMI_EVENT_FAILURE, 
									NULL);
			return;
		}
		
		mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,g_karaoke_cntx.Rec_filepath);
		mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_PLAY_REC_MIX,g_karaoke_cntx.Rec_filepath);
		mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);

        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
		srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_KARAOKE);
        #endif  //defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	
		StopTimer(KARAOKE_DELAY_PLAY_TIMER);
		StartTimer(KARAOKE_DELAY_PLAY_TIMER, MMI_KARAOKE_DELAY_PLAY, mmi_karaoke_delay_play);
        
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
	}
	else if (g_karaoke_lyrics == NULL)
	{
        mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PREPARE_LYRIC, mmi_karaoke_event_hdlr, NULL);
	}
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	//mmi_karaoke_redraw_title();
	//mmi_karaoke_redraw_time();

    #if 0
	#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
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

	//if(g_karaoke_lyrics == NULL)
	//	mmi_karaoke_redraw_animation();

	ClearKeyEvents();
    //if(g_karaoke_lyrics == NULL)
	//	StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,MMI_KARAOKE_UI_UPDATE_PLAY_TIME,mmi_karaoke_redraw_time);
	//else
	//    StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,MMI_KARAOKE_UI_UPDATE_PLAY_TIME,mmi_karaoke_update_lyrics_on_time);

	g_karaoke_cntx.need_resume = KAL_FALSE;
	g_karaoke_cntx.is_interrupted = KAL_TRUE;
	g_karaoke_cntx.need_resing = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_exit_sing_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_exit_sing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//if(!g_karaoke_cntx.need_resume)
	if (g_karaoke_cntx.animation_hdlr != GDI_NULL_HANDLE)
	{
		gdi_image_stop_animation(g_karaoke_cntx.animation_hdlr);
	}
	
    if(karaoke_show_title_done)
    {
		gui_scrolling_text_stop(&karaoke_scrolling_title);
		karaoke_show_title_done = KAL_FALSE;
    }
	
	StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
	mmi_karaoke_stop_update_lyric();
    mmi_karaoke_unprepare_lyrics();
#endif /*__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__*/
	if(g_karaoke_cntx.mdi_callback_registed)
	{
		mdi_audio_clear_interrupt_callback();
		g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
	}

    if(!g_karaoke_cntx.need_resume && g_karaoke_cntx.is_singing)
	{
        mdi_audio_stop_all();
		mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
		//mdi_audio_resume_background_play();
		g_karaoke_cntx.is_singing = KAL_FALSE;
		#ifdef __LINE_IN_SUPPORT__
		if(g_karaoke_cntx.force_use_linein_mice)
			mdi_audio_force_use_linein_mic(KAL_FALSE);
		#endif
	}
    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_KARAOKE);
    #endif  //defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_draw_bg_progressbar
 * DESCRIPTION
 *  redraw karaoke main progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_draw_bg_progressbar(MMI_BOOL need_blt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_FG_PROGRESS_X;
	S32 y1 = KARAOKE_FG_PROGRESS_Y;
	S32 x2 = KARAOKE_FG_PROGRESS_X + KARAOKE_FG_PROGRESS_W;
	S32 y2 = KARAOKE_FG_PROGRESS_Y + KARAOKE_FG_PROGRESS_H - 1;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
#if 0
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif
#endif
	//gdi_layer_push_and_set_active(karaoke_osd_layer);  
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
	gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);

	/* draw progress bg */
	gdi_image_draw_resized(
		KARAOKE_BG_PROGRESS_X + 1, 
		KARAOKE_BG_PROGRESS_Y + 1, 
		KARAOKE_BG_PROGRESS_W- 2, 
		KARAOKE_BG_PROGRESS_H - 2, 
		(PU8) GetImage(IMG_ID_KARAOKE_PROGRESS_BAR_BG));
	
	gdi_layer_pop_clip();
#if 0
/* under construction !*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
	if (need_blt)
		gdi_layer_blt_previous(0 ,0,UI_device_width - 1 ,UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_draw_bg_progressbar
 * DESCRIPTION
 *  redraw karaoke main progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_main_progressbar()
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_FG_PROGRESS_X;
	S32 y1 = KARAOKE_FG_PROGRESS_Y;
	S32 x2 = KARAOKE_FG_PROGRESS_X + KARAOKE_FG_PROGRESS_W - 1;
	S32 y2 = KARAOKE_FG_PROGRESS_Y + KARAOKE_FG_PROGRESS_H - 1;
	U32 dx ; 
	U32 elapsed_ms = 0;
	MMI_BOOL seekable = KAL_TRUE;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
	gui_lock_double_buffer();
#endif
	if(g_karaoke_lyrics == NULL)
	{
	    U32 timerduration = 0;
		mdi_audio_get_progress_time(&g_karaoke_cntx.new_play_time);

		if ((g_karaoke_cntx.new_play_time % 1000) > 500)
	    {
		    timerduration = 1000 - (g_karaoke_cntx.new_play_time % 1000);
	    }
		else
	    {
		    timerduration = MMI_KARAOKE_UI_UPDATE_PLAY_TIME;
	    }
		StartTimer(KARAOKE_PROCESS_ADD_FILE_TIMER,timerduration,mmi_karaoke_redraw_main_progressbar);
	}
	if(g_karaoke_cntx.is_eof)
	{
		g_karaoke_cntx.new_play_time = 0;
		elapsed_ms = g_karaoke_cntx.duration;
		g_karaoke_cntx.is_eof = KAL_FALSE;
	}
	else
    	elapsed_ms = g_karaoke_cntx.new_play_time;
	dx = (U32)(KARAOKE_FG_PROGRESS_W * ((float)elapsed_ms/(float)g_karaoke_cntx.duration));
    x2=x1+dx;
	
	mmi_karaoke_redraw_play_record_time();

	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
	gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_TRANSPARENT);

	/* draw progress bg */
	gdi_image_draw_resized(
		KARAOKE_BG_PROGRESS_X, 
		KARAOKE_BG_PROGRESS_Y, 
		x2+2, 
		KARAOKE_BG_PROGRESS_H - 1, 
		(PU8) GetImage(IMG_ID_KARAOKE_PROGRESS_BAR_FG));
	
	gdi_layer_pop_clip();

	//gdi_layer_pop_and_restore_active();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1,y1,x2,y2);
	
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */
//gdi_layer_blt_previous(0 ,0,UI_device_width - 1 ,UI_device_height - 1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_entry_play_record_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_entry_play_record_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//S16 error;
	mdi_result result;
    BOOL gdi_freeze = KAL_FALSE;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(g_karaoke_cntx.is_interrupted && !g_karaoke_cntx.play_record_for_reviewing)
		g_karaoke_cntx.play_record_for_reviewing = KAL_TRUE;

	gdi_freeze = gdi_lcd_get_freeze();
	gdi_lcd_freeze(TRUE);
	gdi_layer_get_base_handle(&karaoke_osd_layer);
	
	if(g_karaoke_cntx.play_record_for_reviewing)
	{
	    ShowCategory8002Screen(STR_ID_KARAOKE_NAME,STR_ID_KARAOKE_DISCARD_RECORD,STR_ID_KARAOKE_SAVE_RECORD);
	    SetRightSoftkeyFunction(mmi_karaoke_save_record_file, KEY_EVENT_UP);
		SetLeftSoftkeyFunction(mmi_karaoke_detelte_record_file, KEY_EVENT_UP);
		
#ifdef  __MMI_BTD_BOX_UI_STYLE__
        SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
#else
        SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_UP);
#endif
	}
	else
	{
	    if(g_karaoke_cntx.is_paused == KAL_FALSE)
	        ShowCategory8002Screen(STR_ID_KARAOKE_NAME,STR_GLOBAL_PAUSE,STR_GLOBAL_BACK);
		else
			ShowCategory8002Screen(STR_ID_KARAOKE_NAME,STR_GLOBAL_PLAY,STR_GLOBAL_BACK);
		#ifdef  __MMI_BTD_BOX_UI_STYLE__
        SetKeyHandler(mmi_karaoke_prev_next_key_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
    	SetKeyHandler(mmi_karaoke_prev_next_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_karaoke_play_record_prev, KEY_UP_ARROW, KEY_EVENT_UP);
    	SetKeyHandler(mmi_karaoke_play_record_next, KEY_DOWN_ARROW, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
		#else
		SetKeyHandler(mmi_karaoke_play_record_prev, KEY_LEFT_ARROW, KEY_EVENT_UP);
    	SetKeyHandler(mmi_karaoke_play_record_next, KEY_RIGHT_ARROW, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_UP);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
		SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_UP);
		#endif
		SetLeftSoftkeyFunction(mmi_karaoke_play_pause_record_file, KEY_EVENT_UP);

		#ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_register_down_handler(mmi_karaoke_pen_down_hdlr);
        mmi_pen_register_up_handler(mmi_karaoke_pen_up_hdlr);
        mmi_pen_register_move_handler(mmi_karaoke_pen_move_hdlr);
        #endif /* __MMI_TOUCH_SCREEN__ */ 
	}
	
	mmi_karaoke_redraw_background();
	if(!g_karaoke_cntx.need_resume && !g_karaoke_cntx.play_record_for_reviewing)
		mmi_karaoke_list_get_song_path(g_karaoke_cntx.current_list.list_data.highlight, g_karaoke_cntx.Rec_filepath);
	mmi_karaoke_redraw_title();
		
    mmi_karaoke_draw_bg_progressbar(MMI_FALSE);

    if(g_karaoke_lyrics == NULL)
		mmi_karaoke_redraw_animation();
    if(!g_karaoke_cntx.play_record_for_reviewing)
	    mmi_karaoke_redraw_prev_next_icon();
	mmi_karaoke_redraw_play_record_time();

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
	
    if(!g_karaoke_cntx.need_resume)
    {
		//mdi_audio_suspend_background_play();
		g_karaoke_cntx.new_play_time = 0;
		mdi_audio_get_duration(g_karaoke_cntx.Rec_filepath,&g_karaoke_cntx.duration);
		//mmi_karaoke_redraw_background();
		//mmi_karaoke_redraw_title();
		
		if (!g_karaoke_cntx.is_paused)
		{
			StopTimer(KARAOKE_DELAY_PLAY_TIMER);
			StartTimer(KARAOKE_DELAY_PLAY_TIMER, MMI_KARAOKE_DELAY_PLAY, mmi_karaoke_delay_play);
		}
        
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
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
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
    }
	else if (g_karaoke_lyrics == NULL)
	{
        mmi_karaoke_post_event(MMI_KARAOKE_EVENT_PREPARE_LYRIC, mmi_karaoke_event_hdlr, NULL);
	}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    if(g_karaoke_lyrics == NULL)
		mmi_karaoke_redraw_main_progressbar();
	//else
	//    mmi_karaoke_update_lyrics_on_time();

    #if 0
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
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

	if(g_karaoke_cntx.is_paused)
    {   
        if(g_karaoke_cntx.new_play_time==0)
			mmi_karaoke_draw_bg_progressbar(MMI_TRUE);
        StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
    }
	g_karaoke_cntx.need_resume = KAL_FALSE;
	if(g_karaoke_cntx.play_record_for_reviewing)
	    g_karaoke_cntx.is_interrupted = KAL_TRUE;
	if(g_karaoke_cntx.is_paused == KAL_FALSE)
	    g_karaoke_cntx.is_playing_records = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_exit_play_record_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_exit_play_record_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_karaoke_cntx.animation_hdlr != GDI_NULL_HANDLE)
	{
		gdi_image_stop_animation(g_karaoke_cntx.animation_hdlr);
	}
	
    if(karaoke_show_title_done)
    {
		gui_scrolling_text_stop(&karaoke_scrolling_title);
		karaoke_show_title_done = KAL_FALSE;
    }
	StopTimer(KARAOKE_PROCESS_ADD_FILE_TIMER);
#ifdef __MMI_KARAOKE_LYRIC_NLINE_DISPLAY__
	mmi_karaoke_stop_update_lyric();
    mmi_karaoke_unprepare_lyrics();
#endif /*__MMI_KARAOKE_LYRIC_NLINE_DISPLAY__*/
	if(g_karaoke_cntx.mdi_callback_registed)
	{
		mdi_audio_clear_interrupt_callback();
		g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
	}

	if(!g_karaoke_cntx.need_resume && g_karaoke_cntx.is_playing_records)
	{
	    mdi_audio_stop_file();
	    //mdi_audio_resume_background_play();
		g_karaoke_cntx.is_playing_records = KAL_FALSE;
		
		if(!g_karaoke_cntx.play_record_for_reviewing)
		{
			memset((kal_char*)g_karaoke_cntx.Rec_filepath,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
			memset((kal_char*)g_karaoke_cntx.filefullname,0,sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_LEN + 1));
		}
	}
	g_karaoke_cntx.play_record_for_reviewing = KAL_FALSE;
}


#if 1
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_spk_highlite_icon
 * DESCRIPTION
 *  draw karaoke spk highlite icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_spk_highlite_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_SPK_ICON_X;
    S32 y1 = KARAOKE_VOL_SPK_ICON_Y;
    S32 x2 = KARAOKE_VOL_SPK_ICON_X+KARAOKE_VOL_ICON_W;
    S32 y2 = KARAOKE_VOL_SPK_ICON_Y+KARAOKE_VOL_ICON_H;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_BLACK);
	
	gdi_image_draw_resized_id(KARAOKE_VOL_SPK_ICON_X,
		            		  KARAOKE_VOL_SPK_ICON_Y,
		            		  KARAOKE_VOL_ICON_W,
		            		  KARAOKE_VOL_ICON_H,
		            		  IMG_ID_KARAOKE_PLAY_REC_FG_DOWN);

	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_redraw_spk_highlite_icon
 * DESCRIPTION
 *  draw karaoke mic highlite icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_redraw_mic_highlite_icon(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_MIC_ICON_X;
	S32 y1 = KARAOKE_VOL_MIC_ICON_Y;
	S32 x2 = KARAOKE_VOL_MIC_ICON_X+KARAOKE_VOL_ICON_W;
	S32 y2 = KARAOKE_VOL_MIC_ICON_Y+KARAOKE_VOL_ICON_H;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
	gdi_draw_solid_rect(x1,y1,x2,y2,GDI_COLOR_BLACK);
	
	gdi_image_draw_resized_id(KARAOKE_VOL_MIC_ICON_X,
							  KARAOKE_VOL_MIC_ICON_Y,
							  KARAOKE_VOL_ICON_W,
							  KARAOKE_VOL_ICON_H,
							  IMG_ID_KARAOKE_PLAY_REC_FG_DOWN);

	gdi_layer_pop_clip();
	gdi_layer_blt_previous(x1,y1,x2,y2);
}


void mmi_karaoke_pen_down_vol_hdlr(mmi_pen_point_struct pos)
{
    if((KARAOKE_VOL_SPK_SEL_X <=pos.x && pos.x<=(KARAOKE_VOL_SPK_SEL_X + KARAOKE_VOL_SEL_W))
		&&(KARAOKE_VOL_SPK_SEL_Y<=pos.y && pos.y <= (KARAOKE_VOL_SPK_SEL_X + KARAOKE_VOL_SEL_H))) 
    {
        if(!g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_switch_vol_focus();
	}
	else if((KARAOKE_VOL_MIC_SEL_X <=pos.x && pos.x<=(KARAOKE_VOL_MIC_SEL_X + KARAOKE_VOL_SEL_W))
		&&(KARAOKE_VOL_MIC_SEL_Y<=pos.y && pos.y <= (KARAOKE_VOL_MIC_SEL_X + KARAOKE_VOL_SEL_H)))
	{
	    if(g_karaoke_cntx.focus_on_aud_vol)
			mmi_karaoke_switch_vol_focus();
	}
	if((KARAOKE_VOL_SPK_BG_X <=pos.x && pos.x<=(KARAOKE_VOL_SPK_BG_X + KARAOKE_VOL_BG_W))
		&&(KARAOKE_VOL_SPK_BG_Y<=pos.y && pos.y <= (KARAOKE_VOL_SPK_BG_Y + KARAOKE_VOL_BG_H))) 
	{
	    StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK;
		return;
	}
	else if((KARAOKE_VOL_MIC_BG_X <=pos.x && pos.x<=(KARAOKE_VOL_MIC_BG_X + KARAOKE_VOL_BG_W))
		&&(KARAOKE_VOL_MIC_BG_Y<=pos.y && pos.y <= (KARAOKE_VOL_MIC_BG_Y + KARAOKE_VOL_BG_H))) 
	{
	    StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC;
		return;
	}
	else if((KARAOKE_VOL_SPK_ICON_X <=pos.x && pos.x<=(KARAOKE_VOL_SPK_ICON_X + KARAOKE_VOL_ICON_W))
		&&(KARAOKE_VOL_SPK_ICON_Y<=pos.y && pos.y <= (KARAOKE_VOL_SPK_ICON_Y + KARAOKE_VOL_ICON_H))) 
	{
	    StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK_ICON;
		return;
	}
	else if((KARAOKE_VOL_MIC_ICON_X <=pos.x && pos.x<=(KARAOKE_VOL_MIC_ICON_X + KARAOKE_VOL_ICON_W))
		&&(KARAOKE_VOL_MIC_ICON_Y <=pos.y && pos.y <= (KARAOKE_VOL_MIC_ICON_Y + KARAOKE_VOL_ICON_H))) 
	{
	    StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC_ICON;
		return;
	}
	
	wgui_general_pen_down_hdlr(pos);
}


void mmi_karaoke_pen_move_vol_hdlr(mmi_pen_point_struct pos)
{
    if(g_karaoke_cntx.pen_status != MMI_KARAOKE_PEN_STATUS_NONE)
    {
        StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
	}
	
	if (g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK&&
		(KARAOKE_VOL_SPK_BG_X <= pos.x && pos.x <= (KARAOKE_VOL_SPK_BG_X + KARAOKE_VOL_BG_W) &&
		 KARAOKE_VOL_SPK_BG_Y <= pos.y && pos.y <= (KARAOKE_VOL_SPK_BG_Y + KARAOKE_VOL_BG_H)))
	{
	    float temp;
		kal_uint8 index=MDI_KARAOKE_VOL_EX_MAX;
		temp = (float)(KARAOKE_VOL_SPK_BG_Y+KARAOKE_VOL_BG_H -pos.y)/KARAOKE_VOL_BG_H;
		if(temp<0)
			temp=0;
		else if(temp >1)
			temp = 1;
		index = (kal_uint8)(index*temp);
		if(index && g_karaoke_cntx.aud_mute)
			g_karaoke_cntx.aud_mute = MMI_FALSE;
		if(g_karaoke_cntx.is_singing)
			mmi_karaoke_set_aud_vol(index);
		else
			mmi_karaoke_set_remix_aud_vol(index);
	}
	else if (g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC&&
		(KARAOKE_VOL_MIC_BG_X <= pos.x && pos.x <= (KARAOKE_VOL_MIC_BG_X + KARAOKE_VOL_BG_W) &&
		 KARAOKE_VOL_MIC_BG_Y <= pos.y && pos.y <= (KARAOKE_VOL_MIC_BG_Y + KARAOKE_VOL_BG_H)))
	{
	    float temp;
		kal_uint8 index=MDI_KARAOKE_VOL_EX_MAX;
		temp = (float)(KARAOKE_VOL_MIC_BG_Y+KARAOKE_VOL_BG_H -pos.y)/KARAOKE_VOL_BG_H;
		if(temp<0)
			temp=0;
		else if(temp >1)
			temp = 1;
		index = (kal_uint8)(index*temp);
		if(index && g_karaoke_cntx.mic_mute)
			g_karaoke_cntx.mic_mute = MMI_FALSE;
		if(g_karaoke_cntx.is_singing)
			mmi_karaoke_set_mic_vol(index);
		else
			mmi_karaoke_set_remix_mic_vol(index);
	}
	
	wgui_general_pen_move_hdlr(pos);
}

void mmi_karaoke_pen_up_vol_hdlr(mmi_pen_point_struct pos)
{
	if (g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK&&
		(KARAOKE_VOL_SPK_BG_X <= pos.x && pos.x <= (KARAOKE_VOL_SPK_BG_X + KARAOKE_VOL_BG_W) &&
		 KARAOKE_VOL_SPK_BG_Y <= pos.y && pos.y <= (KARAOKE_VOL_SPK_BG_Y + KARAOKE_VOL_BG_H)))
	{
	    float temp;
		kal_uint8 index=MDI_KARAOKE_VOL_EX_MAX;

		StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		
		temp = (float)(KARAOKE_VOL_SPK_BG_Y+KARAOKE_VOL_BG_H -pos.y)/KARAOKE_VOL_BG_H;
		if(temp<0)
			temp=0;
		else if(temp >1)
			temp = 1;
		index = (kal_uint8)(index*temp);
		if(index && g_karaoke_cntx.aud_mute)
			g_karaoke_cntx.aud_mute = MMI_FALSE;
		
		if(g_karaoke_cntx.is_singing)
			mmi_karaoke_set_aud_vol(index);
		else
			mmi_karaoke_set_remix_aud_vol(index);
	}
	else if (g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC&&
		(KARAOKE_VOL_MIC_BG_X <= pos.x && pos.x <= (KARAOKE_VOL_MIC_BG_X + KARAOKE_VOL_BG_W) &&
		 KARAOKE_VOL_MIC_BG_Y <= pos.y && pos.y <= (KARAOKE_VOL_MIC_BG_Y + KARAOKE_VOL_BG_H)))
	{
	    float temp;
		kal_uint8 index=MDI_KARAOKE_VOL_EX_MAX;

		StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		
		temp = (float)(KARAOKE_VOL_MIC_BG_Y+KARAOKE_VOL_BG_H -pos.y)/KARAOKE_VOL_BG_H;
		if(temp<0)
			temp=0;
		else if(temp >1)
			temp = 1;
		index = (kal_uint8)(index*temp);
		if(index && g_karaoke_cntx.mic_mute)
			g_karaoke_cntx.mic_mute = MMI_FALSE;
		if(g_karaoke_cntx.is_singing)
			mmi_karaoke_set_mic_vol(index);
		else
			mmi_karaoke_set_remix_mic_vol(index);
	}
	else if(g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_SPK_ICON &&
		(KARAOKE_VOL_SPK_ICON_X <=pos.x && pos.x<=(KARAOKE_VOL_SPK_ICON_X + KARAOKE_VOL_ICON_W))
		&&(KARAOKE_VOL_SPK_ICON_Y<=pos.y && pos.y <= (KARAOKE_VOL_SPK_ICON_Y + KARAOKE_VOL_ICON_H))) 
	{
        StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		
		#ifdef	__MMI_BTD_BOX_UI_STYLE__
		mmi_karaoke_redraw_spk_highlite_icon();
		kal_sleep_task(10);
		#endif
		g_karaoke_cntx.aud_mute = !g_karaoke_cntx.aud_mute;
		if(g_karaoke_cntx.aud_mute)
		{
		    mmi_karaoke_update_audio_bar(0);
		}
		else
		{
		    if(g_karaoke_cntx.is_singing)
				mmi_karaoke_set_aud_vol(g_karaoke_cntx.aud_vol);
			else
				mmi_karaoke_set_remix_aud_vol(g_karaoke_cntx.remix_aud_vol);
		}
	}
	else if(g_karaoke_cntx.pen_status == MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC_ICON &&
		(KARAOKE_VOL_MIC_ICON_X <=pos.x && pos.x<=(KARAOKE_VOL_MIC_ICON_X + KARAOKE_VOL_ICON_W))
		&&(KARAOKE_VOL_MIC_ICON_Y <=pos.y && pos.y <= (KARAOKE_VOL_MIC_ICON_Y + KARAOKE_VOL_ICON_H))) 
	{
	    StopTimer(KARAOKE_VOLUME_ADJUST_TIMER);
	    StartTimer(KARAOKE_VOLUME_ADJUST_TIMER, MMI_KARAOKE_VOLUME_DELAY, mmi_karaoke_volume_timer_hdlr);
		
        #ifdef  __MMI_BTD_BOX_UI_STYLE__
		mmi_karaoke_redraw_mic_highlite_icon();
		kal_sleep_task(10);
        #endif
		g_karaoke_cntx.mic_mute = !g_karaoke_cntx.mic_mute;
		if(g_karaoke_cntx.mic_mute)
		{
		    mmi_karaoke_update_voice_bar(0);
		}
		else
		{
		    if(g_karaoke_cntx.is_singing)
				mmi_karaoke_set_mic_vol(g_karaoke_cntx.mic_vol);
			else
				mmi_karaoke_set_remix_mic_vol(g_karaoke_cntx.remix_mic_vol);
		}
	}

	g_karaoke_cntx.pen_status = MMI_KARAOKE_PEN_STATUS_DOWN_IN_MIC_ICON;
	
	wgui_general_pen_up_hdlr(pos);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_update_spk_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_update_spk_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_SPK_ICON_X;
    S32 y1 = KARAOKE_VOL_SPK_ICON_Y;
    S32 x2 = KARAOKE_VOL_SPK_ICON_X+KARAOKE_VOL_ICON_W;
    S32 y2 = KARAOKE_VOL_SPK_ICON_Y+KARAOKE_VOL_ICON_H;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_UPDATE_SPK_ICON, g_karaoke_cntx.is_singing,g_karaoke_cntx.aud_mute,g_karaoke_cntx.mic_mute);
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);
	
	if(g_karaoke_cntx.aud_mute)
		gdi_image_draw_id(KARAOKE_VOL_SPK_ICON_X,KARAOKE_VOL_SPK_ICON_Y,IMG_ID_KARAOKE_VOL_SPK_MUTE);
	else
	    gdi_image_draw_id(KARAOKE_VOL_SPK_ICON_X,KARAOKE_VOL_SPK_ICON_Y,IMG_ID_KARAOKE_VOL_SPK);

	if(g_karaoke_cntx.aud_mute)
	{
	    if(g_karaoke_cntx.is_singing)
    	{   if(g_karaoke_cntx.mic_mute)
		        media_aud_set_karaoke_digitgain_req(0,0);
	        else
				media_aud_set_karaoke_digitgain_req(0,g_karaoke_cntx.mic_vol*KARAOKE_MIC_GAIN_UNIT);
    	}
		else
			media_aud_karaoke_set_remix_audio_gain_req(0);
	}
	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_update_mic_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_update_mic_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_MIC_ICON_X;
    S32 y1 = KARAOKE_VOL_MIC_ICON_Y;
    S32 x2 = KARAOKE_VOL_MIC_ICON_X+KARAOKE_VOL_ICON_W;
    S32 y2 = KARAOKE_VOL_MIC_ICON_Y+KARAOKE_VOL_ICON_H;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_UPDATE_MIC_ICON, g_karaoke_cntx.is_singing,g_karaoke_cntx.aud_mute,g_karaoke_cntx.mic_mute);
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);
	
	if(g_karaoke_cntx.mic_mute)
		gdi_image_draw_id(x1,y1,IMG_ID_KARAOKE_VOL_MIC_MUTE);
	else
	    gdi_image_draw_id(x1,y1,IMG_ID_KARAOKE_VOL_MIC);

	if(g_karaoke_cntx.mic_mute)
	{
	    if(g_karaoke_cntx.is_singing)
	    {
	        if(g_karaoke_cntx.aud_mute)
			    media_aud_set_karaoke_digitgain_req(0,0);
		    else
			    media_aud_set_karaoke_digitgain_req(g_karaoke_cntx.aud_vol*KARAOKE_AUD_GAIN_UNIT,0);
	    }
		else
			media_aud_karaoke_set_remix_voice_gain_req(0);
	}
	
	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_update_audio_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_update_audio_bar(kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_SPK_BG_X+1;
    S32 y1 = KARAOKE_VOL_SPK_BG_Y+1;
    S32 x2 = KARAOKE_VOL_SPK_BG_X + KARAOKE_VOL_BG_W-2;//- 1;
    S32 y2 = KARAOKE_VOL_SPK_BG_Y + KARAOKE_VOL_BG_H-2;//- 1;
    float temp=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_UPDATE_AUD_BAR, index);
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);

	if(g_karaoke_cntx.aud_mute)
		temp=0;
	else
	    temp = (float)index/MDI_KARAOKE_VOL_EX_MAX;
	
	if(temp == 0)
		g_karaoke_cntx.aud_mute = MMI_TRUE;
	else
		g_karaoke_cntx.aud_mute = MMI_FALSE;
	mmi_karaoke_update_spk_icon();
	
	gdi_image_draw_resized_id(KARAOKE_VOL_SPK_BG_X,
		   					  KARAOKE_VOL_SPK_BG_Y+KARAOKE_VOL_BG_H*(1-temp),
		   					  KARAOKE_VOL_BG_W,
		   					  KARAOKE_VOL_BG_H*temp,
		   					  IMG_ID_KARAOKE_VOL_FG);
	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_update_voice_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_update_voice_bar(kal_uint8 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_MIC_BG_X+1;
	S32 y1 = KARAOKE_VOL_MIC_BG_Y+1;
	S32 x2 = KARAOKE_VOL_MIC_BG_X + KARAOKE_VOL_BG_W-2;//- 1;
	S32 y2 = KARAOKE_VOL_MIC_BG_Y + KARAOKE_VOL_BG_H-2;//- 1;
	float temp=0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_UPDATE_MIC_BAR, index);
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
	gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);
	if(g_karaoke_cntx.mic_mute)
		temp=0;
	else
	    temp = (float)index/MDI_KARAOKE_VOL_EX_MAX;
	if(temp == 0)
		g_karaoke_cntx.mic_mute = MMI_TRUE;
	else
		g_karaoke_cntx.mic_mute = MMI_FALSE;
	mmi_karaoke_update_mic_icon();
	
	gdi_image_draw_resized_id(KARAOKE_VOL_MIC_BG_X,
							  KARAOKE_VOL_MIC_BG_Y+KARAOKE_VOL_BG_H*(1-temp),
							  KARAOKE_VOL_BG_W,
							  KARAOKE_VOL_BG_H*temp,
							  IMG_ID_KARAOKE_VOL_FG);
	gdi_layer_pop_clip();
	gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_update_audio_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_update_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 x1 = KARAOKE_VOL_SPK_SEL_X;
    S32 y1 = KARAOKE_VOL_SPK_SEL_Y;
    S32 x2 = KARAOKE_VOL_SPK_SEL_X + KARAOKE_VOL_SEL_W;//- 1;
    S32 y2 = KARAOKE_VOL_SPK_SEL_Y + KARAOKE_VOL_SEL_H;//- 1;
    kal_uint8 index=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_UPDATE_FOCUS, g_karaoke_cntx.focus_on_aud_vol);
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);
	if(g_karaoke_cntx.focus_on_aud_vol)
	{
	    gdi_image_draw_resized_id(KARAOKE_VOL_SPK_SEL_X,
			   					  KARAOKE_VOL_SPK_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_SEL);
	}
	else
	{
		gdi_image_draw_resized_id(KARAOKE_VOL_SPK_SEL_X,
			   					  KARAOKE_VOL_SPK_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_UNSEL);
	}
	gdi_image_draw_resized_id(KARAOKE_VOL_SPK_BG_X,
		   					  KARAOKE_VOL_SPK_BG_Y,
		   					  KARAOKE_VOL_BG_W,
		   					  KARAOKE_VOL_BG_H,
		   					  IMG_ID_KARAOKE_VOL_BG);
	if(g_karaoke_cntx.is_singing)
		mmi_karaoke_update_audio_bar(g_karaoke_cntx.aud_vol);
	else
		mmi_karaoke_update_audio_bar(g_karaoke_cntx.remix_aud_vol);
	
	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);

    x1 = KARAOKE_VOL_MIC_SEL_X;
    y1 = KARAOKE_VOL_MIC_SEL_Y;
    x2 = KARAOKE_VOL_MIC_SEL_X + KARAOKE_VOL_SEL_W;//- 1;
    y2 = KARAOKE_VOL_MIC_SEL_Y + KARAOKE_VOL_SEL_H;//- 1;
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BG_COLOR);
	if(g_karaoke_cntx.focus_on_aud_vol)
	{
	    gdi_image_draw_resized_id(KARAOKE_VOL_MIC_SEL_X,
			   					  KARAOKE_VOL_MIC_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_UNSEL);
	}
	else
	{
		gdi_image_draw_resized_id(KARAOKE_VOL_MIC_SEL_X,
			   					  KARAOKE_VOL_MIC_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_SEL);
	}
	gdi_image_draw_resized_id(KARAOKE_VOL_MIC_BG_X,
		   					  KARAOKE_VOL_MIC_BG_Y,
		   					  KARAOKE_VOL_BG_W,
		   					  KARAOKE_VOL_BG_H,
		   					  IMG_ID_KARAOKE_VOL_BG);
	if(g_karaoke_cntx.is_singing)
		mmi_karaoke_update_voice_bar(g_karaoke_cntx.mic_vol);
	else
		mmi_karaoke_update_voice_bar(g_karaoke_cntx.remix_mic_vol);
	
	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_entry_volume_adjust_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_entry_volume_adjust_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = KARAOKE_VOL_LAYER_X;
    S32 y1 = KARAOKE_VOL_LAYER_Y;
    S32 x2 = KARAOKE_VOL_LAYER_X + KARAOKE_VOL_LAYER_W;//- 1;
    S32 y2 = KARAOKE_VOL_LAYER_Y + KARAOKE_VOL_LAYER_H;//- 1;
    kal_uint8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_VOL_ENTRY);
	
	gdi_layer_push_and_set_clip(x1,y1,x2,y2);
    gdi_draw_solid_rect(x1,y1,x2,y2,MMI_KARAOKE_VOL_POP_BORDER_COLOR);
	gdi_draw_solid_rect(x1+2,y1+2,x2-2,y2-2,MMI_KARAOKE_VOL_POP_BG_COLOR);

	if(g_karaoke_cntx.focus_on_aud_vol)
	{
	    gdi_image_draw_resized_id(KARAOKE_VOL_SPK_SEL_X,
			   					  KARAOKE_VOL_SPK_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_SEL);
		gdi_image_draw_resized_id(KARAOKE_VOL_MIC_SEL_X,
			   					  KARAOKE_VOL_MIC_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_UNSEL);
	}
	else
	{
	    gdi_image_draw_resized_id(KARAOKE_VOL_SPK_SEL_X,
			   					  KARAOKE_VOL_SPK_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_UNSEL);
		gdi_image_draw_resized_id(KARAOKE_VOL_MIC_SEL_X,
			   					  KARAOKE_VOL_MIC_SEL_Y,
			   					  KARAOKE_VOL_SEL_W,
			   					  KARAOKE_VOL_SEL_H,
			   					  IMG_ID_KARAOKE_VOL_SEL);
	}

	gdi_image_draw_resized_id(KARAOKE_VOL_SPK_BG_X,
		   					  KARAOKE_VOL_SPK_BG_Y,
		   					  KARAOKE_VOL_BG_W,
		   					  KARAOKE_VOL_BG_H,
		   					  IMG_ID_KARAOKE_VOL_BG);
	gdi_image_draw_resized_id(KARAOKE_VOL_MIC_BG_X,
		   					  KARAOKE_VOL_MIC_BG_Y,
		   					  KARAOKE_VOL_BG_W,
		   					  KARAOKE_VOL_BG_H,
		   					  IMG_ID_KARAOKE_VOL_BG);
	
	if(g_karaoke_cntx.is_singing)
		mmi_karaoke_update_audio_bar(g_karaoke_cntx.aud_vol);
	else
		mmi_karaoke_update_audio_bar(g_karaoke_cntx.remix_aud_vol);

	if(g_karaoke_cntx.is_singing)
		mmi_karaoke_update_voice_bar(g_karaoke_cntx.mic_vol);
	else
		mmi_karaoke_update_voice_bar(g_karaoke_cntx.remix_mic_vol);

	gdi_layer_pop_clip();
    gdi_layer_blt_previous(x1,y1,x2,y2);

	clear_key_handlers();

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
	#ifdef  __MMI_BTD_BOX_UI_STYLE__
	g_karaoke_cntx.key_longpress=MMI_FALSE;
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_UP_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_UP);
	#else
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_VOL_UP, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_VOL_DOWN, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_inc_vol, KEY_UP_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
	SetKeyHandler(mmi_karaoke_dec_vol, KEY_DOWN_ARROW, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_LEFT_ARROW, KEY_EVENT_UP);
	SetKeyHandler(mmi_karaoke_switch_vol_focus, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    #endif
    
    #ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler(mmi_karaoke_pen_down_vol_hdlr);
	mmi_pen_register_up_handler(mmi_karaoke_pen_up_vol_hdlr);
	mmi_pen_register_move_handler(mmi_karaoke_pen_move_vol_hdlr);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_exit_volume_adjust_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_karaoke_exit_volume_adjust_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 group_id,scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_get_active_scrn_id(&group_id,&scrn_id);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_VOL_EXIT,scrn_id,g_karaoke_cntx.is_singing,g_karaoke_cntx.is_playing_records);
	if ((scrn_id == SCR_ID_KARAOKE_VOLUME))
	{
		if(g_karaoke_cntx.need_resume || g_karaoke_cntx.is_singing)
		{
			g_karaoke_cntx.need_resume=KAL_FALSE;
			if(!g_karaoke_cntx.need_resume && g_karaoke_cntx.is_singing)
			{
				if(g_karaoke_cntx.mdi_callback_registed)
				{
					mdi_audio_clear_interrupt_callback();
					g_karaoke_cntx.mdi_callback_registed = KAL_FALSE;
				}
		        mdi_audio_stop_all();
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
				g_karaoke_cntx.is_singing = KAL_FALSE;
				#ifdef __LINE_IN_SUPPORT__
				if(g_karaoke_cntx.force_use_linein_mice)
					mdi_audio_force_use_linein_mic(KAL_FALSE);
				#endif
			}
		}
		mmi_frm_group_close(GPR_ID_KARAOKE_VOLUME);
	}
	else
	{
	    if(g_karaoke_cntx.is_singing || g_karaoke_cntx.is_playing_records)
            g_karaoke_cntx.need_resume = KAL_TRUE;
		else
			g_karaoke_cntx.is_paused = KAL_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_volume_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_karaoke_volume_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_VOL_TIME_HDLR);
	g_karaoke_cntx.need_resume = KAL_TRUE;
	mmi_frm_group_close(GPR_ID_KARAOKE_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_volume_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_karaoke_volume_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_KARAOKE_VOL_PROC,evt->evt_id);
    switch (evt->evt_id)
    {
    	case EVT_ID_GROUP_DEINIT:
		{
			break;
    	}

		case EVT_ID_GROUP_ENTER:
		    break;
		case EVT_ID_SCRN_ACTIVE:
            mmi_karaoke_entry_volume_adjust_screen();
            break;
        case EVT_ID_SCRN_INACTIVE:
            mmi_karaoke_exit_volume_adjust_screen();
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif

#endif  //__MMI_KARAOKE__

