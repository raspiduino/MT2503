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
 *   VdoPlyUltraSlimApp.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   low cost video player for 32+32 & 32+16 project.
 *
 * Author:
 * -------
 * -------
 *
 *
 *------------------------------------------------------------------------------
 *============================================================================
 * $Log$
 *
 * 09 20 2011 qiang.zhang
 * removed!
 * .
 *
 * 07 05 2011 qiang.zhang
 * removed!
 * .
 *
 * 06 30 2011 qiang.zhang
 * removed!
 * .
 *
 * 06 14 2011 qiang.zhang
 * removed!
 * .
 *
 * 06 13 2011 qiang.zhang
 * removed!
 * .
 *
 * 05 26 2011 qiang.zhang
 * removed!
 * .
 *
 * 05 24 2011 qiang.zhang
 * removed!
 * .
 *
 * 02 26 2011 qiang.zhang
 * removed!
 * .
 *
 * 01 08 2011 qiang.zhang
 * removed!
 * .
 *
 * 01 07 2011 qiang.zhang
 * removed!
 * .
 *
 * 01 07 2011 qiang.zhang
 * removed!
 * .
 *
 * 12 30 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 30 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 29 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 29 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 23 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 21 2010 qiang.zhang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_ULC_VIDEO_PLAYER__

#include "GlobalResDef.h"
#include "VdoPlyUltraSlimApp.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mmi_rp_app_vdoply_def.h"
#include "VdoPlyGProt.h"
#include "AlertScreen.h"
#include "Mdi_include.h"
#include "mdi_video.h"
#include "GpioSrvGprot.h"
#include "gui_font_size.h"
#include "wgui_include.h"

#ifdef __MMI_MAINLCD_320X240__
#define MMI_VDOPLY_LANDSCAPE_SCREEN
#endif

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__)
#define MMI_VDOPLY_HAS_BACKGROUND_CALL
#endif

#ifdef __USB_IN_NORMAL_MODE__
#define MMI_VDOPLY_NEED_CHECK_USB
#endif 
	
     /*MACRO FOR MAIN CONTEXT FLAGS*/
#define MMI_VDOPLY_FROM_FILE                0x00000001
#define MMI_VDOPLY_FROM_ID                  0x00000002
        
#define MMI_VDOPLY_MUTE                     0x00000004
#define MMI_VDOPLY_PREV_ROTATE_BY_LAYER     0x00000008
        
#define MMI_VDOPLY_AUDIO_ONLY_FILE          0x00000010
    
#define MMI_VDOPLY_IS_FILE_OPENED           0x00000020
#define MMI_VDOPLY_IS_FILE_PLAYING          0x00000040

#define MMI_VDOPLY_INTERRUPTION_ENTRY       0x00000100

 /***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 mmi_vdoply_context_struct  g_vdoply;
 mmi_vdoply_context_struct* g_vdoply_ptr = NULL;

 /***************************************************************************** 
 * Extern function
 *****************************************************************************/
 extern pBOOL srv_usb_check_path_exported(CHAR *path);
 void mmi_usb_app_unavailable_popup(U16 stringID);
 extern pBOOL srv_usb_is_in_mass_storage_mode(void);
    
 static mmi_ret cui_vdoply_player_screen_proc(mmi_event_struct* evt);
 static MMI_BOOL cui_vdoply_entry_player_screen(void);
 static mmi_ret  cui_vdoply_single_player_proc(mmi_event_struct *evt);
 static void     cui_vdoply_exit_player_screen(void);
 static void     cui_vdoply_evt_exit(MMI_BOOL is_with_popup, MMI_ID_TYPE error_str);

 static void cui_vdoply_prepare_layer(void);
 static void cui_vdoply_unprepare_layer(void);
 static void cui_vdoply_set_blt_layer(void);
 static void cui_vdoply_blt_screen(void);
 static void cui_vdoply_draw_audio_only_image(void);

 static void cui_vdoply_entry_state(mmi_vdoply_state_enum state);
 static void cui_vdoply_do_exit_action(void);
 static void cui_vdoply_do_open_action(void);
 static void cui_vdoply_do_play_action(void);
 static void cui_vdoply_do_pause_action(void);

 static void cui_vdoply_player_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data);
 static void cui_vdoply_player_play_finish_hdlr(MDI_RESULT result, void *user_data);

 static void cui_vdoply_set_key_event(void);
 static void cui_vdoply_on_play_button_release(void);
 static void cui_vdoply_on_exit_button_release(void);
 static void cui_vdoply_on_volume_up_button_release(void);
 static void cui_vdoply_on_volume_down_button_release(void);

 static MMI_BOOL cui_vdoply_load_volume(void);
 static void     cui_vdoply_save_volume(void);
 static void     cui_vdoply_update_volume(void);
 
 static MMI_BOOL cui_vdoply_is_background_call(void);
 static MMI_BOOL cui_vdoply_check_and_exit_with_error_popup(MDI_RESULT result);
 
 static mmi_ret mmi_vdoply_player_proc(mmi_event_struct *evt);
 static void mmi_vdoply_entry_player_main_screen(cui_vdoply_type_enum video_type, cui_vdoply_param_struct* param);
        

 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_create
  * DESCRIPTION
  * 
  * PARAMETERS
  *  parent_id       [IN]        parent group id of cui
  *  type                [IN]        video resource type, for Ultra slim only support
  *                               CUI_VDOPLY_TYPE_FILE,
  *                            CUI_VDOPLY_TYPE_ID
  *  param      [IN]        video player create param
  *
  * RETURNS
  *  cui id
  *****************************************************************************/
 MMI_ID cui_vdoply_create(mmi_id parent_id, cui_vdoply_type_enum video_type,cui_vdoply_param_struct* param)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MMI_ID gid;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(g_vdoply_ptr != NULL)
     {
         return GRP_ID_INVALID;
     }
     
     if (cui_vdoply_is_background_call())
     {
         mmi_popup_display_simple(                   
              (UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE),                               
               MMI_EVENT_FAILURE,                                  
               parent_id,                                 
               NULL);
         return GRP_ID_INVALID;
     }
 
     if(video_type == CUI_VDOPLY_TYPE_FILE)
     {
    #ifdef MMI_VDOPLY_NEED_CHECK_USB
         if (srv_usb_is_in_mass_storage_mode())
         {
             /* in mass storage mode */
 
             if (srv_usb_check_path_exported(param->video_hdr.file_name))
             {
                 /* file is in exported device */
                 mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                 return GRP_ID_INVALID;
             }
         }
    #endif
     }
     
      gid = mmi_frm_group_create(
                     parent_id, 
                     GRP_ID_VDOPLY_SINGLE_PLAYER, 
                     cui_vdoply_single_player_proc,
                     NULL);
                     
     if (GRP_ID_INVALID == gid)
     {
         return GRP_ID_INVALID;
     }
 
     g_vdoply_ptr = &g_vdoply;
     kal_mem_set(g_vdoply_ptr, 0, sizeof(mmi_vdoply_context_struct));
 
     switch(video_type)
     {
         case CUI_VDOPLY_TYPE_FILE:
             g_vdoply_ptr->flag |= MMI_VDOPLY_FROM_FILE;
             mmi_ucs2cpy(g_vdoply_ptr->file_name, param->video_hdr.file_name);
             break;
             
         case CUI_VDOPLY_TYPE_ID:
             g_vdoply_ptr->flag |= MMI_VDOPLY_FROM_ID;
             g_vdoply_ptr->video_id = param->video_hdr.video_id;
             break;
             
         default:
             MMI_ASSERT(0);
             break;
     }
  
     return gid;
     
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_run
  * DESCRIPTION
  * run video player cui
  * PARAMETERS
  *  cid       [IN]         id of video player cui
  * RETURNS
  *  void
  *****************************************************************************/
MMI_ID cui_vdoply_run(MMI_ID cid)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MMI_BOOL ret;
     MMI_ID gid;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_ASSERT(GRP_ID_VDOPLY_SINGLE_PLAYER == cid);
         
     gid = mmi_frm_group_enter(cid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     if(gid == GRP_ID_INVALID)
     {
         return gid;
     }
 
     ret = cui_vdoply_load_volume();
     if(ret == MMI_FALSE)
     {
         mmi_frm_group_close(gid);
         return GRP_ID_INVALID;
     }
     
     mmi_frm_scrn_create(
         GRP_ID_VDOPLY_SINGLE_PLAYER,
         SCR_ID_VDOPLY_PLAYER,
         cui_vdoply_player_screen_proc,
         NULL
         );
     return gid;
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_close
  * DESCRIPTION
  * close video player cui
  * PARAMETERS
  *  cid       [IN]         id of video player cui
  * RETURNS
  *  void
  *****************************************************************************/
 void cui_vdoply_close(MMI_ID cid)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_frm_group_close(cid);
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_player_screen_proc
  * DESCRIPTION
  * player screen proc
  * PARAMETERS
  *  evt       [IN]        screen event
  * RETURNS
  *  video player group id
  *****************************************************************************/
 static mmi_ret cui_vdoply_player_screen_proc(mmi_event_struct* evt)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     switch(evt->evt_id)
     { 
	    case EVT_ID_SCRN_ACTIVE:
		{
			cui_vdoply_entry_player_screen();
			break;
                }
 
        case EVT_ID_SCRN_INACTIVE:
     {
			cui_vdoply_exit_player_screen();
			break;
     }
 
		default:
			break;
	}
	return MMI_RET_OK;
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_entry_player_screen
  * DESCRIPTION
  * create video player cui group and screen
  * PARAMETERS
  *  parent_id       [IN]        parent group id of cui
  * RETURNS
  *  video player group id
  *****************************************************************************/
 static MMI_BOOL cui_vdoply_entry_player_screen(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     BOOL pre_rotate;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_VDOPLY_MASSAGE_TRACE(g_vdoply_ptr->flag);
                     
     cui_vdoply_prepare_layer();
 
     cui_vdoply_set_key_event();
 
     pre_rotate = gdi_lcd_get_rotate_by_layer();
     if (pre_rotate)
     {
         g_vdoply_ptr->flag |= MMI_VDOPLY_PREV_ROTATE_BY_LAYER;
     }
     
     srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
 
     /* suspend background audio */
     mdi_audio_suspend_background_play();
     
     mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

     cui_vdoply_set_blt_layer();
  
     cui_vdoply_entry_state(MMI_VDOPLY_STATE_OPENING);
     
     return MMI_TRUE;
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_single_player_proc
  * DESCRIPTION
  * cui proc, need do nothing here
  * PARAMETERS
  *  evt      [IN]        event struct
  * RETURNS
  *  MMI_RET_OK
  *****************************************************************************/
 static mmi_ret cui_vdoply_single_player_proc(mmi_event_struct *evt)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(evt->evt_id == EVT_ID_GROUP_DEINIT)
     {
         g_vdoply_ptr = NULL;
     }
     return MMI_RET_OK;
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_exit_player_screen
  * DESCRIPTION
  *screen exit function
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_exit_player_screen(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
      
     MMI_VDOPLY_MASSAGE_TRACE(g_vdoply_ptr->flag);
     cui_vdoply_entry_state(MMI_VDOPLY_STATE_EXIT);
 
     g_vdoply_ptr->flag |= MMI_VDOPLY_INTERRUPTION_ENTRY;
     
     /* restore rotate layer flag */
     if(g_vdoply_ptr->flag & MMI_VDOPLY_PREV_ROTATE_BY_LAYER)
     {
         g_vdoply_ptr->flag &= (~MMI_VDOPLY_PREV_ROTATE_BY_LAYER);
         gdi_lcd_set_rotate_by_layer(TRUE);
     }
 
     srv_backlight_turn_off();
 
     /* unmute */
     mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
 
     /* resume background audio */
     mdi_audio_resume_background_play();
 
     cui_vdoply_save_volume();
 
     cui_vdoply_unprepare_layer();
 
     /* reset lcd rotate after exit video player*/
     gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
     
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_evt_exit
  * DESCRIPTION
  * send event to parent to exit
  * PARAMETERS
  *  is_with_popup       [IN]        is exit with pop up
  * error_str                 [IN]        error string
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_evt_exit(MMI_BOOL is_with_popup, MMI_ID_TYPE error_str)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     cui_vdoply_exit_evt_struct evt;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_VDOPLY_EXIT_WITH_POPUP, GRP_ID_VDOPLY_SINGLE_PLAYER);
     
     evt.with_popup      = is_with_popup;
     evt.error_str_id    = error_str;
     
     mmi_frm_group_send_to_parent(GRP_ID_VDOPLY_SINGLE_PLAYER, (mmi_group_event_struct*)&evt);
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_prepare_layer
  * DESCRIPTION
  * create layer and init
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_prepare_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_util_create_hw_layer_intmemory_in_struct play_layer_in;
    mdi_util_create_hw_layer_out_struct play_layer_out;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    play_layer_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
#ifdef MMI_VDOPLY_LANDSCAPE_SCREEN
    play_layer_in.width = LCD_WIDTH;
    play_layer_in.height = LCD_HEIGHT;
#else /* MMI_VDOPLY_USING_ROTATE_BUFFER */
    play_layer_in.width = LCD_HEIGHT;
    play_layer_in.height = LCD_WIDTH;
#endif /* MMI_VDOPLY_USING_ROTATE_BUFFER */
    play_layer_in.offset_x = 0;
    play_layer_in.offset_y = 0;
    g_vdoply_ptr->play_wnd_layer_handle = mdi_util_hw_layer_create_with_intmemory(&play_layer_in, &play_layer_out);

    gdi_layer_push_and_set_active(g_vdoply_ptr->play_wnd_layer_handle);
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_unprepare_layer
  * DESCRIPTION
  * free layer
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_unprepare_layer(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     
     /* free play wnd layer */
     if (g_vdoply_ptr->play_wnd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
     {
         mdi_util_hw_layer_free(g_vdoply_ptr->play_wnd_layer_handle);
         g_vdoply_ptr->play_wnd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_set_blt_layer
  * DESCRIPTION
  * set blt layer
  * PARAMETERS
  * void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_set_blt_layer(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     /* enter next state */
     
#ifdef MMI_VDOPLY_LANDSCAPE_SCREEN
         gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
#else
         gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
#endif 
     
         gdi_layer_set_blt_layer(
             g_vdoply_ptr->play_wnd_layer_handle, 
             GDI_NULL_HANDLE, 
             GDI_NULL_HANDLE, 
             GDI_NULL_HANDLE);
             
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_blt_screen
  * DESCRIPTION
  * blt screen
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_blt_screen(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/     
     
#ifdef MMI_VDOPLY_LANDSCAPE_SCREEN
         gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT- 1);
#else 
         gdi_layer_blt_previous(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
#endif 
     
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_draw_audio_only_image
  * DESCRIPTION
  * draw audio only animation background
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_draw_audio_only_image(void)
 {
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height;
    S32 layer_offset_x, layer_offset_y;
    S32 str_width, str_height;
    S32 offset_x, offset_y;
    CHAR* ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_vdoply_ptr->flag | MMI_VDOPLY_AUDIO_ONLY_FILE)
    {
        gdi_layer_push_and_set_active(g_vdoply_ptr->play_wnd_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);
	gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_WHITE); 

	gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_DEFAULT));

	ptr = (CHAR*) GetString(STR_ID_VDOPLY_AUDIO_ONLY);

	gui_measure_string((UI_string_type) ptr, &str_width, &str_height);
	#ifdef __MMI_VECTOR_FONT_SUPPORT__
            gdi_push_and_set_alpha_blending_source_layer(play_layer);
        #endif
		
	offset_y = (layer_height - str_height) >> 1;
	offset_x = (layer_width - str_width) >> 1;

        gui_set_text_color(gui_color(0, 0, 0));
        gui_print_truncated_text(offset_x, offset_y, layer_height, (UI_string_type)ptr);
         
	gdi_layer_pop_and_restore_active();
    } 
        
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_entry_state
  * DESCRIPTION
  *entry video player state
  * PARAMETERS
  *  state       [IN]        the state entrying
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_entry_state(mmi_vdoply_state_enum state)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_VDOPLY_MASSAGE_TRACE(state);
     g_vdoply_ptr->state = state;
     switch(state)
     {
         case MMI_VDOPLY_STATE_EXIT:
             cui_vdoply_do_exit_action();
             break;
         case MMI_VDOPLY_STATE_OPENING:
             cui_vdoply_do_open_action();
             break;
         case MMI_VDOPLY_STATE_PLAY:
             cui_vdoply_do_play_action();
             break;
         case MMI_VDOPLY_STATE_PAUSE:
             cui_vdoply_do_pause_action();
             break;
         default:
             MMI_ASSERT(0);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_do_exit_action
  * DESCRIPTION
  * do exit state action
  * PARAMETERS
  * void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_do_exit_action(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MDI_RESULT ret;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
 
     /*file playing*/
     if(g_vdoply_ptr->flag & MMI_VDOPLY_IS_FILE_PLAYING)
     {
         ret = mdi_video_ply_stop();
         
         if (ret == MDI_RES_VDOPLY_ALREADY_FINISHED)
         {
             MMI_VDOPLY_MASSAGE_TRACE(ret);
         }
         else
         {
             mdi_video_ply_get_cur_play_time(&g_vdoply_ptr->play_time);  
         }
 
         g_vdoply_ptr->flag &= (~MMI_VDOPLY_IS_FILE_PLAYING);
     }
     
     /*file opened*/
     if(g_vdoply_ptr->flag & MMI_VDOPLY_IS_FILE_OPENED)
     {
         if (g_vdoply_ptr->flag & MMI_VDOPLY_FROM_FILE)
         {
             mdi_video_ply_close_file();
         }
         else if (g_vdoply_ptr->flag & MMI_VDOPLY_FROM_ID)
         {
             mdi_video_ply_close_clip_id();
         }
         else
         {
             MMI_ASSERT(0);     
         }
         g_vdoply_ptr->flag &= (~MMI_VDOPLY_IS_FILE_OPENED);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_do_open_action
  * DESCRIPTION
  * do play action
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_do_open_action(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MDI_RESULT ret;
     mdi_video_info_struct video_info;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_vdoply_ptr->flag & MMI_VDOPLY_FROM_FILE)
     {
         ret = mdi_video_ply_open_file(0, g_vdoply_ptr->file_name, cui_vdoply_player_open_done_hdlr, 0);
         MMI_VDOPLY_MASSAGE_TRACE(ret);      
         if (cui_vdoply_check_and_exit_with_error_popup(ret) == MMI_TRUE)       /* true means have error */
         {
             return;
         }
     }
     else if (g_vdoply_ptr->flag & MMI_VDOPLY_FROM_ID)
     {
         /* play from ID is a blocking function, we will call opened done hdlr by ourself */
         ret = mdi_video_ply_open_clip_id(0, g_vdoply_ptr->video_id, &video_info);
 
         MMI_VDOPLY_MASSAGE_TRACE(ret);      
         if (cui_vdoply_check_and_exit_with_error_popup(ret) == MMI_TRUE)       /* true means have error */
         {
             return;
         }
 
         cui_vdoply_player_open_done_hdlr(MDI_RES_VDOPLY_SUCCEED, &video_info, 0);
     }
     else
     {
         MMI_ASSERT(0);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_do_play_action
  * DESCRIPTION
  * do play action
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_do_play_action(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U16 rotate;
     U32 blt_layer;
     U32 play_layer;
     BOOL is_play_audio;
     gdi_handle play_layer_handle;
     MDI_RESULT ret;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
 
     /* should week before play */
     ret = mdi_video_ply_seek_and_get_frame(
              g_vdoply_ptr->play_time,
              g_vdoply_ptr->play_wnd_layer_handle);
 
     if (cui_vdoply_check_and_exit_with_error_popup(ret) == MMI_TRUE)  /* ture means has error popup */
     {
         return;
     }
     
     cui_vdoply_blt_screen();
 
     /* play video */
     play_layer_handle = g_vdoply_ptr->play_wnd_layer_handle;
     blt_layer = GDI_LAYER_ENABLE_LAYER_0;   
     play_layer = GDI_LAYER_ENABLE_LAYER_0;        
     
#ifdef MMI_VDOPLY_LANDSCAPE_SCREEN
         rotate = MDI_VIDEO_LCD_ROTATE_0;    
#else
         rotate = MDI_VIDEO_LCD_ROTATE_270;        
#endif        
     
        
     is_play_audio = TRUE;
     if (cui_vdoply_is_background_call())
     {
         is_play_audio = FALSE;
     }
     
     ret = mdi_video_ply_play(
             play_layer_handle,                      /* play layer handle */
             blt_layer,                              /* blt layer */
             play_layer,                             /* play_layer_flag */
             1,                                      /* repeat */
             TRUE,                                   /* visual update */
             is_play_audio,                          /* play aud */
             MDI_DEVICE_SPEAKER2,                    /* audio path */
             rotate,                                 /* rotate */
             100,                                    /* speed factor */
             cui_vdoply_player_play_finish_hdlr,
             0);    /* play layer */
 
     if (ret == MDI_RES_VDOPLY_SUCCEED)
     {
         g_vdoply_ptr->flag |= MMI_VDOPLY_IS_FILE_PLAYING;
   
         cui_vdoply_blt_screen();                
     }    
     else
     {
         MMI_VDOPLY_ERROR_TRACE(ret);
         cui_vdoply_evt_exit(MMI_TRUE, STR_ID_VDOPLY_NOTIFY_PLAY_FAILED);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_do_pause_action
  * DESCRIPTION
  * do pause action
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_do_pause_action(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MDI_RESULT ret;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(g_vdoply_ptr->flag & MMI_VDOPLY_IS_FILE_PLAYING)
     {
         ret = mdi_video_ply_stop();
         g_vdoply_ptr->flag &= (~MMI_VDOPLY_IS_FILE_PLAYING);
         
         if (ret == MDI_RES_VDOPLY_ALREADY_FINISHED)
         {
             cui_vdoply_evt_exit(MMI_FALSE, 0);
             return;
         }
         
         mdi_video_ply_get_cur_play_time(&g_vdoply_ptr->play_time);  
         
         if (!(g_vdoply_ptr->flag & MMI_VDOPLY_AUDIO_ONLY_FILE))
         {
             if (g_vdoply_ptr->play_time > g_vdoply_ptr->total_time_duration)                       
             {
                 g_vdoply_ptr->play_time = g_vdoply_ptr->total_time_duration;    
             }           
             
             mdi_video_ply_seek_and_get_frame(
                 g_vdoply_ptr->play_time,
                 g_vdoply_ptr->play_wnd_layer_handle);
         }
         cui_vdoply_blt_screen();
     }
     else if(g_vdoply_ptr->flag & MMI_VDOPLY_INTERRUPTION_ENTRY)
     {
         mdi_video_ply_seek_and_get_frame(
                 g_vdoply_ptr->play_time,
                 g_vdoply_ptr->play_wnd_layer_handle);
         cui_vdoply_blt_screen();
     }
     else
     {
         MMI_VDOPLY_ERROR_TRACE(g_vdoply_ptr->flag);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_player_open_done_hdlr
  * DESCRIPTION
  * video file open call back
  * PARAMETERS
  * result       [IN]       open result
  * vdo_clip   [IN]       video information
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_player_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     S32 bbox_width;
     S32 bbox_height;
     S32 resized_offset_x;
     S32 resized_offset_y;
     S32 resized_width;
     S32 resized_height;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_VDOPLY_MASSAGE_TRACE(result);
     /* check if already exit player screen */
     if(g_vdoply_ptr == NULL)
     {
         return;
     }
     
     if (g_vdoply_ptr->state != MMI_VDOPLY_STATE_OPENING)
     {
         return;
     }
     
     if (cui_vdoply_check_and_exit_with_error_popup(result) == MMI_TRUE)
     {   
            return;
     }
     
     /*open sucessfully */
     g_vdoply_ptr->flag |= MMI_VDOPLY_IS_FILE_OPENED;
        
     /* fit it into player window */
     g_vdoply_ptr->total_time_duration = vdo_clip->total_time_duration;
 
     if(vdo_clip->track == MDI_VIDEO_TRACK_A_ONLY)
     {
         g_vdoply_ptr->flag |= MMI_VDOPLY_AUDIO_ONLY_FILE;
         gdi_layer_push_and_set_active(g_vdoply_ptr->play_wnd_layer_handle);
         gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
         gdi_layer_pop_and_restore_active(); 

         cui_vdoply_draw_audio_only_image();
     }
     else
     {
    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
   #ifdef MMI_VDOPLY_LANDSCAPE_SCREEN
             bbox_width = GDI_LCD_WIDTH;
             bbox_height = GDI_LCD_HEIGHT;
	#else
             bbox_width = GDI_LCD_HEIGHT;
             bbox_height = GDI_LCD_WIDTH;
	#endif
         
         gdi_image_util_fit_bbox(
             bbox_width,
             bbox_height,
             vdo_clip->width,
             vdo_clip->height,
             &resized_offset_x,
             &resized_offset_y,
             &resized_width,
             &resized_height);
 
         if (vdo_clip->width == 1 || vdo_clip->height == 1)
          {
             /* error, since we cant - 1 */
             MMI_VDOPLY_ERROR_TRACE(vdo_clip->width);
             cui_vdoply_evt_exit(MMI_TRUE, STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE);
             return;
          }
          if (resized_width == 1)
          {               
             resized_width++;          
          }
 
          if (resized_height == 1)
          {
             resized_height++;   
          }
     
          if (resized_width % 2 != 0)
          {
             /* shrink 1 pixel */
             resized_width --;
          }
 
          if (resized_height % 2 != 0)
          {
             /* shirink 1 pixel */
             resized_height --;
          }
 
 
          /* resize play layer */
         gdi_layer_push_and_set_active(g_vdoply_ptr->play_wnd_layer_handle);
         
         gdi_layer_resize(resized_width, resized_height);
         
         gdi_layer_set_position(
             resized_offset_x,
             resized_offset_y);
        #else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
            gdi_layer_push_and_set_active(g_vdoply_ptr->play_wnd_layer_handle);
        #endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
         gdi_layer_set_background(GDI_COLOR_BLACK);
         gdi_layer_clear(GDI_COLOR_BLACK);
         gdi_layer_pop_and_restore_active();
 
     }
     
     cui_vdoply_update_volume();
     MMI_VDOPLY_MASSAGE_TRACE(g_vdoply_ptr->flag);
     if(g_vdoply_ptr->flag & MMI_VDOPLY_INTERRUPTION_ENTRY)
     {
         cui_vdoply_entry_state(MMI_VDOPLY_STATE_PAUSE); 
     }
     else
     {
         cui_vdoply_entry_state(MMI_VDOPLY_STATE_PLAY); 
     }
                                            
         
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_player_play_finish_hdlr
  * DESCRIPTION
  * play finish call back
  * PARAMETERS
  * result      [IN]        play finish call back result
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_player_play_finish_hdlr(MDI_RESULT result, void *user_data)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MMI_VDOPLY_MASSAGE_TRACE(result);
     /* if not in player screen */
     if(g_vdoply_ptr == NULL)
     {
         return;
     }
     
     if (g_vdoply_ptr->state != MMI_VDOPLY_STATE_PLAY)
     {
         return;
     } 
    
     if (cui_vdoply_check_and_exit_with_error_popup(result) == MMI_TRUE)       /* true means have error */
     {
         return;
     }
 
     g_vdoply_ptr->flag &= (~MMI_VDOPLY_IS_FILE_PLAYING);
     
     cui_vdoply_evt_exit(MMI_FALSE, 0);
     
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_set_key_event
  * DESCRIPTION
  * set key event
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_set_key_event(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     ClearInputEventHandler(MMI_DEVICE_KEY);    
 
     SetKeyHandler(cui_vdoply_on_play_button_release, KEY_LSK, KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_play_button_release, KEY_CSK, KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_exit_button_release, KEY_RSK, KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_volume_up_button_release,KEY_UP_ARROW,KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_volume_down_button_release,KEY_DOWN_ARROW,KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_volume_up_button_release, KEY_VOL_UP, KEY_EVENT_UP);
     SetKeyHandler(cui_vdoply_on_volume_down_button_release, KEY_VOL_DOWN, KEY_EVENT_UP); 
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_on_play_button_release
  * DESCRIPTION
  * play button key event handle
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_on_play_button_release(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(g_vdoply_ptr->state == MMI_VDOPLY_STATE_PLAY)
     {
         cui_vdoply_entry_state(MMI_VDOPLY_STATE_PAUSE);
     }
     else if(g_vdoply_ptr->state == MMI_VDOPLY_STATE_PAUSE)
     {
         cui_vdoply_entry_state(MMI_VDOPLY_STATE_PLAY);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_on_exit_button_release
  * DESCRIPTION
  * exit button key event hdlr
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_on_exit_button_release(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     cui_vdoply_evt_exit(MMI_FALSE, 0);
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_on_volume_up_button_release
  * DESCRIPTION
  * volume turn up key event hdlr
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_on_volume_up_button_release(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(g_vdoply_ptr->flag & MMI_VDOPLY_MUTE)
     {
         g_vdoply_ptr->flag &= (~MMI_VDOPLY_MUTE);
     }
     else if(g_vdoply_ptr->volume < MDI_AUD_VOL_EX_15)
     {
         g_vdoply_ptr->volume++;
     }
     else
     {
         return;
     }
     cui_vdoply_update_volume();
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_on_volume_down_button_release
  * DESCRIPTION
  * volume turn down key event hdlr
  * PARAMETERS
  * void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_on_volume_down_button_release(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if(!(g_vdoply_ptr->flag & MMI_VDOPLY_MUTE))
     {
         if(g_vdoply_ptr->volume > MDI_AUD_VOL_EX_0)
         {
             g_vdoply_ptr->volume--;
         }
         else
         {
             g_vdoply_ptr->flag |= MMI_VDOPLY_MUTE;
         }
         cui_vdoply_update_volume();
     }   
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_load_volume
  * DESCRIPTION
  * load volume from NVRAM
  * PARAMETERS
  *  void
  * RETURNS
  *  MMI_TRUE if sucess
  *  MMI_FALSE if error happens
  *****************************************************************************/
 static MMI_BOOL cui_vdoply_load_volume(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     S16 error;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     
     ReadValue(NVRAM_VDOPLY_VOLUMN, (void*)&g_vdoply_ptr->volume, DS_BYTE, &error);
     if (NVRAM_READ_SUCCESS != error)
     {
         return MMI_FALSE;  
     }
 
     if( g_vdoply_ptr->volume > MDI_AUD_VOL_EX_NUM )
     {
         g_vdoply_ptr->volume = MDI_AUD_VOL_EX_8;
     }
     else if(g_vdoply_ptr->volume == MDI_AUD_VOL_EX_NUM)
     {
         g_vdoply_ptr->flag |= MMI_VDOPLY_MUTE;
         g_vdoply_ptr->volume = MDI_AUD_VOL_EX_0;
     }
 
     return MMI_TRUE;
     
     
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_save_volume
  * DESCRIPTION
  * save volume to NVRAM
  * PARAMETERS
  *  void
  * RETURNS
  * void
  *****************************************************************************/
 static void cui_vdoply_save_volume(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     S16 error;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (g_vdoply_ptr->flag & MMI_VDOPLY_MUTE)
     {
         g_vdoply_ptr->volume = MDI_AUD_VOL_EX_NUM;
         WriteValue(NVRAM_VDOPLY_VOLUMN, (void*)&g_vdoply_ptr->volume, DS_BYTE, &error);
     }
     else
     {
         WriteValue(NVRAM_VDOPLY_VOLUMN, (void*)&g_vdoply_ptr->volume, DS_BYTE, &error);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_update_volume
  * DESCRIPTION
  * update volum
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 static void cui_vdoply_update_volume(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (!cui_vdoply_is_background_call())
     {
         if (g_vdoply_ptr->flag & MMI_VDOPLY_MUTE)
         {       
              mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);      
         }
         else if (g_vdoply_ptr->volume < MDI_AUD_VOL_EX_15)
         {
             mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_ptr->volume));
         }
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_prepare_screen
  * DESCRIPTION
  * create video player cui group and screen
  * PARAMETERS
  *  parent_id       [IN]        parent group id of cui
  * RETURNS
  *  video player group id
  *****************************************************************************/
 static MMI_BOOL cui_vdoply_is_background_call(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
#ifdef MMI_VDOPLY_HAS_BACKGROUND_CALL
     if (srv_ucm_is_background_call())
     {
         return MMI_TRUE;
     }
#endif /* __MMI_BACKGROUND_CALL__ */
 
     return MMI_FALSE;
    
 }
 
 
 /*****************************************************************************
  * FUNCTION
  * cui_vdoply_check_and_exit_with_error_popup
  * DESCRIPTION
  * check and display error popup
  * PARAMETERS
  * result       [IN]        mdi return result
  * RETURNS
  *  video player group id
  *****************************************************************************/
 static MMI_BOOL cui_vdoply_check_and_exit_with_error_popup(MDI_RESULT result)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MMI_ID_TYPE err_strid;
     mmi_event_notify_enum popup_type;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     
     if (result < MDI_RES_VDOPLY_SUCCEED) /* error happened */
     {
         err_strid = mdi_util_get_mdi_error_info(result, &popup_type);
         cui_vdoply_evt_exit(MMI_TRUE,err_strid); 
         return MMI_TRUE;
     }
     else
     {
         return MMI_FALSE;
     }
 
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_vdoply_entry_player_main_screen
  * DESCRIPTION
  *  enter player's screen
  * PARAMETERS
  *  video_type        [IN]        Filename with full path
  *  param        [IN]        Short name, need to covert from BIG5 to Unicode before display
  * RETURNS
  *  void
  *****************************************************************************/
 static void mmi_vdoply_entry_player_main_screen(cui_vdoply_type_enum video_type, cui_vdoply_param_struct* param)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MMI_ID cid;
     MMI_ID gid;
    
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     gid = mmi_frm_group_create_ex(
                     GRP_ID_ROOT, 
                     GRP_ID_VDOPLY_PLAYER, 
                     mmi_vdoply_player_proc,
                     NULL, 
                     MMI_FRM_NODE_SMART_CLOSE_FLAG);                   
     if(GRP_ID_INVALID == gid)
     {
          mmi_popup_display_simple_ext(                   
               STR_GLOBAL_NOT_AVAILABLE,                               
               MMI_EVENT_FAILURE,                                  
               GRP_ID_ROOT,                                 
               NULL);
         return;
     }
     
     cid = cui_vdoply_create(gid, video_type, param);
     if(GRP_ID_INVALID == cid)
     {
          mmi_popup_display_simple_ext(                   
               STR_GLOBAL_NOT_AVAILABLE,                               
               MMI_EVENT_FAILURE,                                  
               GRP_ID_ROOT,                                 
               NULL);
         return;
     }
     
     cid = cui_vdoply_run(cid);
     if(GRP_ID_INVALID == cid)
     {
         mmi_popup_display_simple_ext(                   
               STR_GLOBAL_NOT_AVAILABLE,                               
               MMI_EVENT_FAILURE,                                  
               GRP_ID_ROOT,                                 
               NULL);
     }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_vdoply_entry_player_screen_from_file
  * DESCRIPTION
  *  enter player's screen and play from file
  * PARAMETERS
  *  filename        [IN]        Filename with full path
  *  is_short        [IN]        Short name, need to covert from BIG5 to Unicode before display
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_vdoply_entry_player_screen_from_file(CHAR* filename, MMI_BOOL is_short)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     cui_vdoply_param_struct param;
    
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     param.video_hdr.file_name = filename;
     mmi_vdoply_entry_player_main_screen(CUI_VDOPLY_TYPE_FILE, &param);
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_vdoply_entry_player_screen_from_file
  * DESCRIPTION
  *  enter player's screen and play from file
  * PARAMETERS
  *  filename        [IN]        Filename with full path
  *  is_short        [IN]        Short name, need to covert from BIG5 to Unicode before display
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_vdoply_entry_player_screen_from_id(U16 video_id, U16 video_name_id)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     cui_vdoply_param_struct param;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     param.video_hdr.video_id = video_id;
     mmi_vdoply_entry_player_main_screen(CUI_VDOPLY_TYPE_ID, &param);
 }
 
 
 
 /*****************************************************************************
  * FUNCTION
  *  cui_vdoply_prepare_screen
  * DESCRIPTION
  * create video player cui group and screen
  * PARAMETERS
  *  parent_id       [IN]        parent group id of cui
  * RETURNS
  *  video player group id
  *****************************************************************************/
 static mmi_ret mmi_vdoply_player_proc(mmi_event_struct *evt)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     switch(evt->evt_id)
     {
         case EVT_VDOPLY_EXIT_WITH_POPUP:
         {
             cui_vdoply_exit_evt_struct *vdoply_evt = (cui_vdoply_exit_evt_struct *)evt;
             if(vdoply_evt->with_popup)
             {
                 mmi_popup_display_simple_ext(                   
                       vdoply_evt->error_str_id,                               
                       MMI_EVENT_FAILURE,                                  
                       GRP_ID_VDOPLY_PLAYER,                                 
                       NULL);
             }
             cui_vdoply_close(GRP_ID_VDOPLY_SINGLE_PLAYER);
             break;
         }
         default:
             break;
     }
     return MMI_RET_OK;
 }
 
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_vdoply_init_app
  * DESCRIPTION
  * init app
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_vdoply_init_app(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     
 }
     
#endif

