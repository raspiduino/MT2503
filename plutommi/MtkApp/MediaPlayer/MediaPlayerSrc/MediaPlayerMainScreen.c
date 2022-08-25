/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  MedplyMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player main screen drawing prototype
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "MMI_features.h"

#ifndef __MMI_MEDIA_PLAYER_FTE__
#ifdef __MMI_MEDIA_PLAYER__

    #include "TimerEvents.h"
    #include "gdi_include.h"
    #include "FileMgrSrvGProt.h"
    #include "mdi_datatype.h"
    #include "mdi_audio.h"
    #include "MMIDataType.h"
    #include "gdi_datatype.h"
    #include "gui_windows.h"
    #include "MediaPlayerEnumDef.h"
    #include "kal_general_types.h"
    #include "wgui.h"
    #include "mmi_frm_input_gprot.h"
    #include "gdi_const.h"
    #include "MMI_media_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_media_app_trc.h"
    #include "kal_trace.h"
    #include "wgui_categories_util.h"
    #include "gui.h"
    #include "mmi_frm_history_gprot.h"
    #include "kal_public_api.h"
    #include "MediaAppWidgetDef.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "app_mem.h"
    #include "gdi_lcd_config.h"
    #include "lcd_sw_inc.h"
    #include "Conversions.h"
    #include "gui_typedef.h"
    #include "wgui_include.h"
    #include "PixcomFontEngine.h"
    #include "CustThemesRes.h"
    #include "meta_tag_api.h"
    #include "Unicodexdcl.h"
    #include "gui_data_types.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "fs_errcode.h"
    #include "mdi_video.h"
    #include "MMI_features_mediaplayer.h"
    #include "stack_config.h"
    #include "CustDataRes.h"
    #include "GlobalResDef.h"
    #include "ScreenRotationGprot.h"
    #include "wgui_inputs.h"
    #include "lcd_if.h"
    #include "GpioSrvGprot.h"
    #include "mmi_rp_app_medply_def.h"
    #include "SSCStringTable.h"
    #include "string.h"
    #include "SoundEffect.h"
    #include "mmi_rp_file_type_def.h"
    #include "wgui_softkeys.h"

#include "gui_font_size.h"

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
#include "lyrics_parser.h"
#endif

#include "PhoneSetupGprots.h"
#include "med_main.h"
#include "med_utility.h"
#include "mdi_include.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

#include "MediaPlayerGprot.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerPlayList.h"

#include "MediaPlayerMainScreen.h"
#include "resource_mediaplayer_skins.h"

#if defined(__MMI_MAINLCD_320X240__)
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER    0
#else
#define MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER    1
#endif

#ifdef __MMI_FTE_SUPPORT_SLIM__
#define MMI_MSCR_FTE_SLIM_SUPPORT
#endif

#if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__) 
#define MMI_MSCR_FTE_20_SUPPORT
#endif


#ifdef __MMI_VIDEO_3D_ANAGLYPH__
#define MMI_MSCR_SHOW_3D_VIDEO_ICON
#endif

#define MMI_MSCR_ERR_IMG_ID                 0

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#define MMI_MSCR_SPECTRUM_NUM               16
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#define MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
#if defined(__MMI_MAINLCD_320X480__)
#define MMI_MSCR_SUBTITLE_FONT_SIZE                   20
#else
#define MMI_MSCR_SUBTITLE_FONT_SIZE                   16
#endif
#define MMI_MSCR_SUBTITLE_HOR_GAP                     2
#define MMI_MSCR_SUBTITLE_CF_DEEPTH                   4
/*due to some char will not align, such as "p" and "g", may be partcially cut if set subtitle layer height equal to line_num*font_height
  *so, line_num = actual_line_number * 2. 
  * e.g when we want to show 2 line subtitle, MMI_MSCR_SUBTITLE_LINE_NUMBER must defined to 4.
  */
#define MMI_MSCR_SUBTITLE_LINE_NUMBER                 4
#define MMI_MSCR_SUBTITLE_MAX_BUF_SIZE                (MMI_MSCR_SUBTITLE_LINE_NUMBER*MMI_MSCR_SUBTITLE_FONT_SIZE*GDI_LCD_HEIGHT*MMI_MSCR_SUBTITLE_CF_DEEPTH)
#else  /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */
#define MMI_MSCR_SUBTITLE_MAX_BUF_SIZE                0
#endif  /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */



#define MMI_MSCR_COLOR_DEPTH                2
#define MMI_MSCR_LAYER_BUFFER_SIZE          MEDPLY_MAIN_SCREEN_LAYER_SIZE
#define MMI_MSCR_LAYER_COLOR_BACKGROUND     GDI_COLOR_BLACK
#define MMI_MSCR_LAYER_COLOR_TRANSPARENT    GDI_COLOR_TRANSPARENT 
#define MMI_MSCR_TEXT_FIXED_COLOR           (gui_color(255, 255, 255))
#define MMI_MSCR_FILE_NAME_LEN              SRV_FMGR_PATH_MAX_FILE_NAME_LEN
#define MMI_MSCR_FILE_PATH_LEN              SRV_FMGR_PATH_MAX_LEN
#define MMI_MSCR_USER_RATE_MAX_LEVEL        5
/*
**  (MDI_AUD_VOL_EX_NUM-1)  used in 0 can hear sound
**  MDI_AUD_VOL_EX_MUTE_MAX used in 0 can not hear sound, mute
*/
#define MMI_MSCR_VOLUME_MAX_LEVEL           MDI_AUD_VOL_EX_MUTE_MAX
#define MMI_MSCR_ARTWORK_SIZE				MEDPLY_MAIN_SCREEN_ARTWORK_SIZE

/*  
**  DEFINE MAIN SCREEN CONTEXT STRUCT
*/
typedef struct
{ 
    U64             duration;
    U64             playtime;
    U64             seektime;
	U64				cachetime;
    U32             flags;
	S32             lsk_trunc;
    S32             rsk_trunc;

    U8*             artwork_mem;/*This memory must same large as layer_mem*/
    U8*             layer_mem;
    gdi_handle      layer_hdl[MMI_MSCR_LAYER_ID_TOTAL];
    gdi_handle      layer_base_hdl;
    gdi_handle      layer_merge_hdl;
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    gdi_handle      layer_prev_icon_bar_hdl;
#endif /*#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)*/
    gdi_handle      layer_osd_hdl;    

    gdi_handle      layer_full_scr_hdl;
    //HAL
    gdi_handle      layer_video_hw_hdl;

    gdi_handle      ani_osd_hdl;
    gdi_handle      ani_demo_hdl;

    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    gdi_handle      layer_subtitle_hdl;     /* subtitle layer */
    #endif

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    mmi_medply_meta_struct*             meta_p; /*lyrics mode also need init meta*/
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    spectrum_struct*    spectrum_p;
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__)
    void*    lyric_p;
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#endif    

/*#if defined(__MMI_MEDIA_PLAYER_VIDEO__)*/
    mmi_medply_video_play_para_struct*  video_p;
/*#endif*/
    scrolling_text      title_scroll;

    U16 title_txt[MMI_MSCR_FILE_NAME_LEN];
    U16 layer_full_scr_w;
    U16 layer_full_scr_h;
    U16 img_idx[17];
    U8  rgn_hide_flag[MMI_MSCR_BUTTON_ID_EX_TOTAL];
    U8  rgn_disable_flag[MMI_MSCR_BUTTON_ID_EX_TOTAL];
    U8  rgn_push_down_id;
    U8  ui_status;
    U8  id_animation;
    U8  view_content;
    U8  view_content_fullscr;
    U8  seek_duration_dst_range;
    U8  loading_percent;
    U8  data_from;
    U8  video_flags;
    U8  is_paint_ticks;
    
}   mmi_medply_ui_handle_struct;

/*MACRO FOR MAIN CONTEXT UI FLAGS*/
#define MMI_MSCR_HD_HAS_ROTATE_BY_LAYER     0x00000001  /*Check Whether LCD has been rotate by layer*/
#define MMI_MSCR_HD_HAS_FULL_SCREEN         0x00000002  /*Check Whether Current play is in full screen*/
#define MMI_MSCR_HD_HAS_PLAYING_TIMER       0x00000004
#define MMI_MSCR_HD_HAS_SEEKING_TIMER       0x00000008

#define MMI_MSCR_HD_HAS_SEEKING_WITH_PEN    0x00000010  
#define MMI_MSCR_HD_HAS_SEEKING_WITH_KEY    0x00000020
#define MMI_MSCR_HD_HAS_OSD_IMAGE           0x00000040
#define MMI_MSCR_HD_HAS_PREPARED_VIEW       0x00000080

#define MMI_MSCR_HD_HAS_INIT_TITLE          0x00000200
#define MMI_MSCR_HD_HAS_MOVE_TITLE          0x00000400
#define MMI_MSCR_HD_HAS_LKEY_DOWN           0x00000800

#define MMI_MSCR_HD_HAS_RKEY_DOWN           0x00001000
#define MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV   0x00004000
#define MMI_MSCR_HD_HAS_INIT_SPECTRUM       0x00008000

#define MMI_MSCR_HD_HAS_PLAY_SPECTRUM       0x00010000
#define MMI_MSCR_HD_HAS_PAINT_BG            0x00020000
#define MMI_MSCR_HD_HAS_STATUS_TIMER        0x00040000
#define MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE   0x00080000 

#define MMI_MSCR_HD_NEED_RESTART_ANI		0x00100000
#define MMI_MSCR_HD_FULL_LAYER_ROTATE		0x00200000
#define MMI_MSCR_HD_HAS_USED_ARTWORK_MEM    0x00400000
#define MMI_MSCR_HD_HAS_NO_ANI_BLT_CB       0x00800000

#define MMI_MSCR_HD_HAS_PAUSE_VIEW          0x01000000
#define MMI_MSCR_HD_HAS_PAUSE_ALL           0x02000000
#define MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER	0x08000000

#define MMI_MSCR_HD_IS_WAITING_STATUS       0x10000000
#define MMI_MSCR_HD_IS_VIDEO_CONTENT        0x20000000 
#define MMI_MSCR_HD_IS_VIDEO_BG             0x40000000
#define MMI_MSCR_HD_IS_DELTETING            0x80000000

/*
**  DEFINE VIDEO LAYER FLAGS   
*/
#define MMI_MSCR_HD_VID_HAS_RESIZE_LAYER            0x01
#define MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER         0x02
#define MMI_MSCR_HD_VID_HAS_PAINT_BG                0x04

/*  DEFINE GLOBAL VARIABLE
*/
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
static  lyrics_meta_struct*                 g_lyrics    = NULL;
static  mmi_medply_lyrics_box_struct        g_lyrics_box;
#endif /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/

static  mmi_medply_rect_struct              g_blt_rgn;
static  mmi_medply_ui_struct                g_mscr_ui;
static  mmi_medply_ui_handle_struct*        g_mscr_hd   = NULL;
static  gdi_handle                          g_gdi_layer_hd = NULL;
static  U32                                 g_mscr_flag = 0;

#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
#ifndef MMI_MSCR_FTE_20_SUPPORT
static  U16 g_mscr_protect_ext [] = 
{
    MED_TYPE_DAF,
    MED_TYPE_MUSICAM,
    /*MED_TYPE_WMA*/ 
};
static  U8  mmi_mscr_is_protect_file(U16* filepath);
#endif
#endif
/*
**  MACRO FOR MAIN UI FLAGS g_mscr_flag
*/
#define MMI_MSCR_UI_HAS_INIT                0x01
#define MMI_MSCR_UI_HAS_PARSE_LYRICS        0x02
#define MMI_MSCR_UI_IS_LYRICS_READY         0x04

#define MMI_MSCR_UI_UPDATE_PLAY_TIME        400     /*MS*/

//bql: revise for 6252H video playback performance issue
#if defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
#define MMI_MSCR_UI_UPDATE_PLAY_TIME_VIDEO        1000     /*MS*/
#else
#define MMI_MSCR_UI_UPDATE_PLAY_TIME_VIDEO        MMI_MSCR_UI_UPDATE_PLAY_TIME     /*MS*/
#endif

#define MMI_MSCR_UI_UPDATE_SEEK_TIME        100     /*MS*/
#define MMI_MSCR_UI_UPDATE_STATUS_TIME      200
#define MMI_MSCR_UI_UPDATE_SEEK_CONTENT     5000

#define mmi_mscr_clean_blt_rgn()            \
    do                                      \
    {                                       \
        g_blt_rgn.x = 0;                    \
        g_blt_rgn.y = 0;                    \
        g_blt_rgn.w = 0;                    \
        g_blt_rgn.h = 0;                    \
                                            \
    } while (0)


/*  
*   DEFINE  INLINE FUNCTION
*/
static  void        mmi_mscr_create_handle(void);
static  void        mmi_mscr_delete_handle(void);
static  gdi_handle  mmi_mscr_create_layer(U8* mem_p, S32 mem_size, 
                        mmi_medply_rect_struct* rgn_p);
static  void        mmi_mscr_prepare_hw_video_layer(MMI_BOOL is_full);
static  void        mmi_mscr_prepare_layer(void);
static  void        mmi_mscr_unprepare_layer(void); 

static  void        mmi_mscr_init_meta(void);
static  void        mmi_mscr_prepare_meta(void);
static  void        mmi_mscr_unprepare_meta(void);
#ifndef MMI_MSCR_FTE_20_SUPPORT
static  void        mmi_mscr_init_title_text(void);
static  void        mmi_mscr_init_title_scroll(void);  
static  void        mmi_mscr_draw_title_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2);  
static  void        mmi_mscr_draw_title_scroll_callback(void); 
#endif

static  void        mmi_mscr_draw_meta_title_scroll_callback(void);
#ifndef MMI_MSCR_FTE_20_SUPPORT
static  void        mmi_mscr_draw_meta_album_scroll_callback(void);
#endif
static  void        mmi_mscr_draw_meta_artist_scroll_callback(void);
static  void        mmi_mscr_draw_meta_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2);

static  void        mmi_mscr_prepare_view_content(void);
static  void        mmi_mscr_unprepare_view_content(void);
static  void        mmi_mscr_update_video_content(void);
static  U8          mmi_mscr_get_view_content(void);
static  void        mmi_mscr_init_view_content(void);

static  void        mmi_mscr_init_video(void);
static  void        mmi_mscr_deinit_video(void);
static  void        mmi_mscr_init_regn_status(void);
static  void        mmi_mscr_init_ui_status(void);
static  void        mmi_mscr_init_sk_position(void);
static  void        mmi_mscr_update_ui_status(void);
static  void        mmi_mscr_set_status_and_ani(U8 ui_status, U8 id_ani);
static  void        mmi_mscr_update_playing(void);
static  void        mmi_mscr_config_layer_rotate(void);
static  void        mmi_mscr_config_layer_blt(void);
static  void        mmi_mscr_config_backlight(void);
static  void        mmi_mscr_enable_backlight(U8 is_enable);

#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__)
static  void*       mmi_mscr_malloc_mem_lyrics(kal_uint32 nSize, kal_uint32 user_data);
static  void        mmi_mscr_free_mem_lyrics(void* p, kal_uint32 user_data);
static  void        mmi_mscr_prepare_lyrics(void);
static  void        mmi_mscr_unprepare_lyrics(void);
static  void        mmi_mscr_parse_lyrics(void);
static  void        mmi_mscr_config_lyrics(void);
static  void        mmi_mscr_update_lyrics(void);
static  void        mmi_mscr_draw_lyrics(void);
#endif  /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
static  void        mmi_mscr_init_spectrum(void);
static  void        mmi_mscr_play_spectrum(void);
static  void        mmi_mscr_stop_spectrum(void);
static  void		mmi_mscr_uninit_spectrum(void);
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

static  void        mmi_mscr_draw_text(mmi_medply_rect_struct* rgn_p,
                                       mmi_medply_rect_struct* rgn_clip_p,
                                       U16* txt_p, U8 attr_w, U8 attr_h,
                                       U8 use_border, S32 trunc_w);
/*MACRO FOR DRAW TEXT*/
#define MMI_MSCR_TXT_DRAW_ALEFT             0x02
#define MMI_MSCR_TXT_DRAW_ARIGHT            0x04
#define MMI_MSCR_TXT_DRAW_ATOP              0x02
#define MMI_MSCR_TXT_DRAW_ABOTTOM           0x04

static  void        mmi_mscr_draw_scroll(scrolling_text* scroll_p,
                                         U32* flags,
                                         U32 flag_init,
                                         U32 flag_move, 
                                         U32 attr_draw,
                                         MMI_BOOL is_scroll);

static  void        mmi_mscr_start_playing(void);
static  void        mmi_mscr_stop_playing(void);
static  void        mmi_mscr_draw_osd_loading(void);
static  void        mmi_mscr_start_osd_animation(U16 ani_id);
static  void        mmi_mscr_stop_osd_animation(U8 is_restore);
static  void        mmi_mscr_play_video_demo(void);
static  void        mmi_mscr_draw_video_demo(void);
static  void        mmi_mscr_stop_video_demo(void);

static  void        mmi_mscr_merge_blt_rgn(S16 x, S16 y, S16 w, S16 h);

static  void        mmi_mscr_draw_background(void);
static  void        mmi_mscr_draw_background_for_video(void);
static  void        mmi_mscr_draw_title(void);
#if defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && !defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
static  void        mmi_mscr_draw_title_ex(void);
#endif
static  void        mmi_mscr_draw_panel(void);
static  void        mmi_mscr_draw_view(void);

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
static  void        mmi_mscr_draw_status_bar_bg(void);
#endif

static  void        mmi_mscr_draw_artwork(void);
static  void        mmi_mscr_draw_meta(void);

#if !defined (__MMI_FTE_SUPPORT__)
static  void        mmi_mscr_draw_softkey(U8 key_id, U32 down_f);
static  void        mmi_mscr_draw_softkey_ex(U8 key_id, U32 down_f);
#endif

static  void        mmi_mscr_draw_image_box(mmi_medply_img_box_struct* img_p);
static  void        mmi_mscr_draw_image_box_ex(mmi_medply_img_box_struct* img_p);
static  void        mmi_mscr_draw_ticks(void);
static  void        mmi_mscr_config_button_image(U8 id);
static  void        mmi_mscr_update_redraw_button(void);
static  void        mmi_mscr_draw_buttons(void);
static  void        mmi_mscr_draw_button_id(U8 id);
//#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
static  void        mmi_mscr_clean_button_id(U8 id, gdi_handle layer);
//#endif
static  void 		mmi_mscr_draw_button_id_ex(U8 id, gdi_handle layer);
static  MMI_BOOL    mmi_mscr_draw_image_mem(mmi_medply_rect_struct* rgn_p, 
                        U8* img_p, U32 img_size,
                        U8 img_type, U8 resize_f);

#ifdef __MMI_TOUCH_SCREEN__
static  MMI_BOOL    mmi_mscr_is_pt_in_rgn(mmi_pen_point_struct* pos_p, 
                                          mmi_medply_rect_struct* rgn_p);
static  U8          mmi_mscr_get_pt_range(S16 x, mmi_medply_rect_struct* rgn_p);
#endif

static  void        mmi_mscr_seek_begin(void);
static  void        mmi_mscr_seek_update(void);
static  void        mmi_mscr_seek_end(U8 is_resume);
static  void        mmi_mscr_update_seeking(void);
static  void        mmi_mscr_show_moving(U8 update_content);
static  void        mmi_mscr_draw_duration(void);
static  void        mmi_mscr_update_duration(void);

static  void 		mmi_mscr_blt_demo_callback(GDI_RESULT ret);

static  void        mmi_mscr_pause(void);
static  void        mmi_mscr_resume(void);
static  void        mmi_mscr_pause_view(void);
static  void        mmi_mscr_resume_view(void);

static  void        mmi_mscr_resize_video_layer(void);
static  void 		mmi_mscr_restore_full_screen(void);

static  void        mmi_mscr_prepare_full_scr(void);
static  void        mmi_mscr_unprepare_full_scr(void);
static  S32         mmi_mscr_draw_osd_background(MMI_BOOL with_clip);

/*
**  Inline warp function
*/
static  U64         mmi_inline_get_duration(void);
static  U64         mmi_inline_get_playtime(void);
static  void        mmi_inline_set_playtime(U64 playtime);
static  U8          mmi_inline_get_cache_percent(void);
static  U32         mmi_inline_get_cache_step(void);
static  U32         mmi_inline_get_media_type(void);
#ifdef __MMI_VIDEO_STREAM__
static  U32         mmi_inline_get_media_format(void);
#endif
static  U32         mmi_inline_get_video_track(void);
static  U16*        mmi_inline_get_title_path(U8* data_from);
static  U8          mmi_inline_get_volume_level(void);
static  U8          mmi_inline_get_status(void);
static  U8          mmi_inline_is_volume_mute(void);
static  U8          mmi_inline_is_seekable(void);
static  MMI_ID      mmi_inline_get_group_id(void);
#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
static  MMI_BOOL  mmi_inline_is_3d_mode(void);
#endif
static  U8          mmi_inline_is_full_screen(void);
static  U8          mmi_inline_is_single_play(void);
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
static  U8          mmi_inline_is_spectrum_blocked(void);
#endif
static  U8          mmi_inline_is_duration_seek_able(void);
static  U8          mmi_inline_is_stream_url(void);
#if !defined (__MMI_FTE_SUPPORT__)
static  U8          mmi_inline_is_resizeable_image(U16* file_path, 
                                                   S32 src_w, S32 src_h, 
                                                   S32 dst_w, S32 dst_h);
#endif
static  U8          mmi_inline_is_background_call(void);
static  U8          mmi_inline_is_button_disable(S32 button_id);
static  void        mmi_inline_reset_button_up(mmi_medply_regn_id_enum id);
#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
MMI_BOOL            mmi_inline_has_subtitle(void);
static void         mmi_inline_set_subtitle_font_size(U8 font_size);
#endif



/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_prepare
* DESCRIPTION
*  Enter new screen, call this function to prepare memory and resource
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE);
	
    mmi_mscr_create_handle();  
    mmi_mscr_prepare_layer();   
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    mmi_mscr_init_title_scroll();   
    #endif
    mmi_mscr_init_ui_status();
    mmi_mscr_clean_blt_rgn();

    /*MAUI_01599613, need check if view content has ready*/
    if ((MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content) &&
        (MMI_MEDPLY_ANI_BT_CONNECTING == g_mscr_hd->id_animation))
    {
        mmi_mscr_update_video_content();
    }
	mmi_mscr_prepare_view_content();

	MMI_MSCR_MSG_TRACE(0);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_unprepare
* DESCRIPTION
*  Exit main screen, call this function to release screen based memory and resource
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER & g_mscr_hd->flags))
    {
        gdi_layer_lock_frame_buffer();
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER;
    }

    g_mscr_hd->flags |= MMI_MSCR_HD_IS_DELTETING;

    /*Stop Seek timer*/
    mmi_mscr_seek_end(0);    
    /*Stop OSD ani*/
    mmi_mscr_stop_osd_animation(0);
    /*Stop Scroll Text and Playing timer and Spectrum and demo video Ani*/
    mmi_mscr_pause();
    /* Unregist status icon in title */
#if defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && !defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
    wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif
    /*Stop status timer*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_STATUS_TIMER)
    {
        gui_cancel_timer(mmi_mscr_update_ui_status);
    }   

    /*lyrics maybe lock the frame buffer*/
    if (MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER & g_mscr_hd->flags)
    {
        gdi_layer_unlock_frame_buffer();
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER;
	}

    mmi_mscr_unprepare_view_content();
    mmi_mscr_unprepare_layer();    
    mmi_mscr_enable_backlight(0);
    
    mmi_mscr_delete_handle();

	MMI_MSCR_MSG_TRACE(0);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_prepare_view
* DESCRIPTION
*  update view content, do special init for each content 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_prepare_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE_VIEW);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_prepare_view_content();
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_unprepare_view
* DESCRIPTION
*  release view content 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_unprepare_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE_VIEW);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_unprepare_view_content();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_redraw
* DESCRIPTION
*  redraw main screen according to current status, but not blt to lcd
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_REDRAW);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_lock_frame_buffer();

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)    
    {        
        /*Only View in Full Screen*/
        mmi_mscr_draw_view();
        /*Set Layer for get layer invalidate region*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
        {
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAINT_BG;
            g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_PAINT_BG;
            mmi_mscr_draw_background();
        }
        /*Clear Video Region to Black Color*/
        if (!(g_mscr_hd->video_flags & MMI_MSCR_HD_VID_HAS_PAINT_BG) && 
            (g_mscr_hd->flags & MMI_MSCR_HD_IS_VIDEO_BG))
        {
            g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_PAINT_BG;
            mmi_mscr_draw_background_for_video();
        }
        mmi_mscr_draw_title();
        mmi_mscr_draw_view();
        mmi_mscr_draw_panel();  
        /*Set Layer for get layer invalidate region*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl);
    }
  
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();

	if (g_mscr_hd->flags & MMI_MSCR_HD_FULL_LAYER_ROTATE)
	{
		MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
		mmi_medply_main_screen_set_clip_rgn((S16)layer_y, (S16)layer_x,
        	(S16)layer_h, (S16)layer_w);
	}
	else
	{
		mmi_medply_main_screen_set_clip_rgn((S16)layer_x, (S16)layer_y,
        	(S16)layer_w, (S16)layer_h);
	}
    
    gdi_layer_unlock_frame_buffer();

	MMI_MSCR_MSG_TRACE(0);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_reset
* DESCRIPTION
*  reset main screen
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_main_screen_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_RESET);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    g_lyrics_box.line_focus_id = LYRICS_MAX_LINES;
#endif
    mmi_mscr_update_duration();
    mmi_mscr_seek_end(0);
    mmi_mscr_stop_playing();
    mmi_mscr_stop_osd_animation(1);

    mmi_medply_main_screen_redraw();

    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_start_playing();
    }    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_delete
* DESCRIPTION
*  screen has deleted from history, call this function to release APP Based or other
*   global memory
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
U8 mmi_medply_main_screen_delete(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return  MMI_HIST_ALLOW_DELETING;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_blt
* DESCRIPTION
*  blt to LCD according to redraw function, it will have no effect when call this function
*   without any redraw happend.
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle h1,h2,h3,h4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }

    if (0 == g_blt_rgn.w || 0 == g_blt_rgn.h)
    {
        MMI_MSCR_ERR_TRACE(g_blt_rgn.w);
        return;
    }

	if (MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER & g_mscr_hd->flags)
	{
		gdi_layer_unlock_frame_buffer();
		g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER;
	}

    gdi_layer_blt_previous(g_blt_rgn.x, g_blt_rgn.y, g_blt_rgn.x + g_blt_rgn.w-1, 
        g_blt_rgn.y + g_blt_rgn.h-1);
	gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_HDL, h1,h2,h3,h4);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_RGN, g_blt_rgn.x, g_blt_rgn.y, g_blt_rgn.w, g_blt_rgn.h);

    mmi_mscr_clean_blt_rgn();

    /*
    **  do init ui status in redraw function
    **  because the ui status change will caused animation or spectrum start
    **  the animation should blt better after screen has been paint.
    */
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_WAITING_STATUS)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_IS_WAITING_STATUS;
        if ((MMI_MEDPLY_STATUS_READY == g_mscr_hd->ui_status || 
            MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status) && 
            (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
        {
            mmi_mscr_update_video_content();
        }
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, g_mscr_hd->id_animation);
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
    }
	MMI_MSCR_MSG_TRACE(0);
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_and_draw_button
* DESCRIPTION
*  Set main screen button status and redraw button.
* PARAMETERS
*  mmi_medply_regn_id_enum      : region id or button id
*  mmi_medply_regn_status_enum  : region status       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_set_and_draw_button(
                mmi_medply_regn_id_enum id,
                mmi_medply_regn_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_AND_DRAW_BUTTON,id,status);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    /* build warning fix: if (id < 0 || id >= MMI_MSCR_BUTTON_ID_EX_TOTAL) */
    if (id >= MMI_MSCR_BUTTON_ID_EX_TOTAL)
    {
        MMI_MSCR_ERR_TRACE(id);
        return;
    }
    switch(status)
    {
    case MMI_MEDPLY_RGN_STATUS_DOWN:
        
        g_mscr_hd->rgn_push_down_id = id;
        g_mscr_hd->rgn_disable_flag[id] = 0; 
        break;
    case MMI_MEDPLY_RGN_STATUS_UP:
        
        g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;
        g_mscr_hd->rgn_disable_flag[id] = 0; 
        
        mmi_mscr_config_button_image((U8)id);
        break;
    case MMI_MEDPLY_RGN_STATUS_DISABLE:
        if (id == g_mscr_hd->rgn_push_down_id)
        {
            g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;    
        }        
        g_mscr_hd->rgn_disable_flag[id] = 1; 
        break;
    default:
        
        ASSERT(0);
        break;
    }    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_MSG_TRACE(1);
        return;
    }    
    if (0 == g_mscr_hd->rgn_hide_flag[id])
    {
        mmi_mscr_draw_button_id((U8)id);

        mmi_mscr_merge_blt_rgn(g_mscr_ui.touch_btn[id].pen_rgn.x,
            g_mscr_ui.touch_btn[id].pen_rgn.y,
            g_mscr_ui.touch_btn[id].pen_rgn.w,
            g_mscr_ui.touch_btn[id].pen_rgn.h);
		MMI_MSCR_MSG_TRACE(2);
    }
    MMI_MSCR_MSG_TRACE(3);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_volume
* DESCRIPTION
*  redraw volume  
* PARAMETERS
*  volume: level for display        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    U8  range;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_VOLUME, volume);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    range = (U8)(volume*100/MMI_MSCR_VOLUME_MAX_LEVEL);
    if (range != g_mscr_ui.volume_img.fg_range)
    {
        g_mscr_ui.volume_img.fg_range = range;
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            /*do not update anything in full screen status*/
			MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
            return;
        }
        mmi_mscr_draw_image_box(&g_mscr_ui.volume_img);

        gdi_image_get_dimension_id(g_mscr_ui.volume_img.bg_img_id, &w, &h);

        mmi_mscr_merge_blt_rgn(g_mscr_ui.volume_img.view_x,
            g_mscr_ui.volume_img.view_y, (S16)w, (S16)h);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_duration
* DESCRIPTION
*  redraw duration  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_DURATION);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_update_duration();
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
		return;
    }
    mmi_mscr_draw_duration();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_cache
* DESCRIPTION
*  redraw cache bar  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_CACHE);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_PLAYING_TIMER|MMI_MSCR_HD_HAS_SEEKING_TIMER))
    {
        /*do not update anything in timer update*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    /*Begin Paint*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
    gdi_layer_reset_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);
    
    /*show image box*/
    mmi_mscr_draw_image_box_ex(&g_mscr_ui.duration_img);
    
    /*End Paint*/
    gdi_pop_and_restore_alpha_blending_source_layer();    
    gdi_layer_pop_and_restore_active();
    /*Set blt Region*/
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    w = g_medply_skin.duration_bar_rgn_w;
    h = g_medply_skin.duration_bar_rgn_h;
    #else
    gdi_image_get_dimension_id(g_mscr_ui.duration_img.bg_img_id, &w, &h);    
    #endif
    mmi_mscr_merge_blt_rgn(g_mscr_ui.duration_img.view_x,
            g_mscr_ui.duration_img.view_y, (S16)w, (S16)h);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_down
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_lkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_LSK_DOWN);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags |=  MMI_MSCR_HD_HAS_LKEY_DOWN;
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_RKEY_DOWN;
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    #if !defined (__MMI_FTE_SUPPORT__)
    mmi_mscr_draw_softkey(MMI_MSCR_ITEM_ID_LKEY_BTN, 1);
    #else
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_LKEY,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    #endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_rkey_down
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_rkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_RSK_DOWN);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags |=  MMI_MSCR_HD_HAS_RKEY_DOWN;
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_LKEY_DOWN;
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }    
#if !defined (__MMI_FTE_SUPPORT__)
    mmi_mscr_draw_softkey(MMI_MSCR_ITEM_ID_RKEY_BTN, 1);
#else
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_RKEY,
        MMI_MEDPLY_RGN_STATUS_DOWN);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_up
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_lkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_LSK_UP);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_LKEY_DOWN;
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }    
#if !defined (__MMI_FTE_SUPPORT__)
    mmi_mscr_draw_softkey(MMI_MSCR_ITEM_ID_LKEY_BTN, 0);
#else
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_LKEY,
        MMI_MEDPLY_RGN_STATUS_UP);
#endif
    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_draw_lkey_up
* DESCRIPTION
*  redraw softkey button  
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_draw_rkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_DRAW_RSK_UP);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_RKEY_DOWN;
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
		MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }    
    
#if !defined (__MMI_FTE_SUPPORT__)
    mmi_mscr_draw_softkey(MMI_MSCR_ITEM_ID_RKEY_BTN, 0);
#else
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_RKEY,
        MMI_MEDPLY_RGN_STATUS_UP);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_video_updated
* DESCRIPTION
*  for video play layer need update, set video layer region to blt 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_video_updated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_VIDEO_UPDATE);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    //HAL
    if(g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO_DEMO)
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
	    {
	        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
	    }
	    else
	    {
	        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
	    } 
		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
	    gdi_layer_pop_and_restore_active();
    }
	
   
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        //Set full screen scope as video update clip region, for the animation trancate issue
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    }    
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();
    
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);
    
    if (layer_w > 0 && layer_h > 0)
    {
    	if (g_mscr_hd->flags & MMI_MSCR_HD_FULL_LAYER_ROTATE)
		{
			MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
			mmi_mscr_merge_blt_rgn((S16)layer_y, (S16)layer_x, 
            	(S16)layer_h, (S16)layer_w);
    	}
		else
		{
			mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, 
            	(S16)layer_w, (S16)layer_h);
		}        
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_clear_video_layer
* DESCRIPTION
*  clear video play layer from main screen 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_clear_video_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CLEAR_VIDEO_LAYER);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }

    if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->view_content);
        return;
    }
    //HAL
    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hw_hdl);
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
	gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
    
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);

    if (layer_w > 0 && layer_h > 0)
    {
        mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y, 
            (S16)layer_w, (S16)layer_h);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_get_video_layer
* DESCRIPTION
*  get video play layer from main screen 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
*****************************************************************************/
void mmi_medply_main_screen_get_video_parameter(
            mmi_medply_video_play_para_struct* video_layer_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 video_w, video_h;
    U8  flags;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_GET_PARAMETER);

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (NULL == video_layer_info_p)
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_VIDEO_CONTENT))
    {
    	MMI_MSCR_ERR_TRACE(0);
        return;
    } 
    
    mmi_mscr_update_video_content();
    mmi_mscr_config_layer_blt();
    
    MMI_MSCR_MSG_TRACE(video_layer_info_p->video_width);
    MMI_MSCR_MSG_TRACE(video_layer_info_p->video_height);

    video_w = g_mscr_hd->video_p->video_width;
    video_h = g_mscr_hd->video_p->video_height;
    g_mscr_hd->video_p->video_width   =  video_layer_info_p->video_width;
    g_mscr_hd->video_p->video_height  =  video_layer_info_p->video_height;

    kal_mem_cpy(video_layer_info_p, g_mscr_hd->video_p, 
        sizeof(mmi_medply_video_play_para_struct));

    
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    if(MMI_FALSE == mmi_inline_has_subtitle())
    {
        video_layer_info_p->layer_subtitle_hdl = GDI_NULL_HANDLE;
        MMI_MSCR_MSG_TRACE(0);
    }
    else if(g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
    {
    /* MAUI_03185572, need valid subtitle handle if subtitle present *
     * but it is not configured along with OSD animation image       */
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
        video_layer_info_p->layer_subtitle_hdl = g_mscr_hd->layer_subtitle_hdl;
    }
    #endif 

    if (0 == g_mscr_hd->video_p->video_width ||
        0 == g_mscr_hd->video_p->video_height)
    {
    	MMI_MSCR_MSG_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        flags = MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
    }
    else
    {
        flags = MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
    }
    
    if ((g_mscr_hd->video_flags & flags) && 
        (g_mscr_hd->video_p->video_width == video_w) &&
        (g_mscr_hd->video_p->video_height == video_h))
    {
    	MMI_MSCR_MSG_TRACE(0);
        return;
    }
    
    mmi_mscr_resize_video_layer();        

	if ((g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE) &&
		(MMI_MEDPLY_ANI_VIDEO_OPENING == g_mscr_hd->id_animation) &&
		(g_mscr_hd->flags & MMI_MSCR_HD_NEED_RESTART_ANI))
	{
		MMI_MSCR_ERR_TRACE(g_mscr_hd->id_animation);
		mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, g_mscr_hd->id_animation);
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_get_pt_rgn
* DESCRIPTION
*  get point touched region
* PARAMETERS
*  void       
* RETURNS
*  mmi_medply_regn_id_enum
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
U8   mmi_medply_main_screen_get_pt_rgn(mmi_pen_point_struct pt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);

        return  MMI_MEDPLY_RGN_ID_NULL;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        return  MMI_MEDPLY_RGN_ID_NULL;
    }
	/*User press ctrl panel*/
    if (mmi_mscr_is_pt_in_rgn(&pt, &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL]))
    {
        for (i = MMI_MEDPLY_RGN_ID_PLAY_PAUSE; i < MMI_MSCR_BUTTON_ID_BASIC_TOTAL; i++)
    	{
        	if (mmi_mscr_is_pt_in_rgn(&pt, &g_mscr_ui.touch_btn[i].pen_rgn))
        	{
            	return  i;
        	}
    	}
    	for (i = MMI_MSCR_ITEM_ID_DURATION ; i < MMI_MSCR_ITEM_ID_TOTAL; i++)
    	{
        	if (mmi_mscr_is_pt_in_rgn(&pt, &g_mscr_ui.items_rgn[i]))
        	{
            	return  i + MMI_MEDPLY_RGN_ID_DURATION_BAR - MMI_MSCR_ITEM_ID_DURATION;
        	}
    	}
    }
    return  MMI_MEDPLY_RGN_ID_NULL;
}
#endif  /*#ifdef __MMI_TOUCH_SCREEN__*/


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_clip_rgn
* DESCRIPTION
*  used for blt to lcd, if rgn w and h <= 0, will do nothing;
*  default clip region will get from redraw regions 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_set_clip_rgn(S16 x, S16 y, S16 w, S16 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_CLIP_RGN,x,y,w,h);
	
    g_blt_rgn.x = x;
    g_blt_rgn.y = y;
    g_blt_rgn.w = w;
    g_blt_rgn.h = h;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_full_screen
* DESCRIPTION
*  change view to full screen or not 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_set_full_screen(MMI_BOOL full_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 ani_img_id = MMI_MSCR_ERR_IMG_ID;
    MMI_BOOL    bChange = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_FULL_SCREEN, full_f);

	if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
	if ((MMI_MEDPLY_STATUS_READY == g_mscr_hd->ui_status || 
         MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status) && 
        (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
    {
        mmi_mscr_update_video_content();
    }

    if (full_f)
    {
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
        {           
            bChange = MMI_TRUE;
            mmi_mscr_prepare_full_scr();            
        }
    }
    else
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {     
            bChange = MMI_TRUE;
            mmi_mscr_unprepare_full_scr();            
        }
    }  
    if (bChange)
    {
        mmi_mscr_config_layer_rotate();
        mmi_mscr_config_layer_blt();
        /*  For normal video layer use the same buffer as temp osd animation */
        if (g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO)
        {
            mmi_medply_main_screen_clear_video_layer();
        }
        /*
        **  For Full video Layer has use same buffer with title/view/pannel layers
        **  So when change full screen status, need clear layer first.
        **  Clear layer buffer will do in mmi_medply_main_screen_redraw
        */
        mmi_medply_main_screen_redraw();
		
		if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
		{
			ASSERT(MMI_MSCR_ERR_IMG_ID != g_mscr_hd->id_animation);
	            
			if (MMI_MEDPLY_ANI_LOADING == g_mscr_hd->id_animation) 
			{
				/*loading show*/
				mmi_mscr_draw_osd_loading();
			}
			else
			{
				switch(g_mscr_hd->id_animation)
				{
				case MMI_MEDPLY_ANI_VIDEO_OPENING:

					ani_img_id = g_medply_skin.wait_open_ani_id;
					break;
				case MMI_MEDPLY_ANI_BT_CONNECTING:

					ani_img_id = g_medply_skin.wait_bt_connect_ani_id;
					break;
				case MMI_MEDPLY_ANI_RTP_CONNECTING:

					ani_img_id = g_medply_skin.wait_rtp_connect_ani_id;
					break;
				case MMI_MEDPLY_ANI_SNAP_SHOT:

					ani_img_id = g_medply_skin.wait_snap_shot_ani_id;
					break;
				default :
					ASSERT(0);
					break;
				}
	                /*restart animation*/
	                mmi_mscr_start_osd_animation(ani_img_id);
			}
		}  
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_down
* DESCRIPTION
*  pause currently play timer, to whether need start seeking timer  
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_pen_down(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_ui.duration_img.fg_range > g_mscr_ui.duration_img.md_range )
    {
        MMI_MSCR_ERR_TRACE(g_mscr_ui.duration_img.fg_range);
        MMI_MSCR_ERR_TRACE(g_mscr_ui.duration_img.md_range);
    }
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x,
        &g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION]);
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_PEN;

    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);

    mmi_mscr_seek_begin();    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_move
* DESCRIPTION
*  change video layer to full screen or not 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_pen_move(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x,
        &g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION]);  
    
    mmi_mscr_seek_update();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_pen_up
* DESCRIPTION
*  seek with pen touch, pen up action 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_pen_up(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = mmi_mscr_get_pt_range(x,
        &g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION]);  
    /*will clear seeking flags in end function*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);

    mmi_mscr_seek_end(1);
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_prev
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_seek_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = 0;
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_begin();    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_prev
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_seek_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (0 == mmi_inline_is_duration_seek_able())
    {
        MMI_MSCR_ERR_TRACE(0);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->seek_duration_dst_range = 100;
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_begin();    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_duration_seek_done
* DESCRIPTION
*  use keyboard to seek 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_duration_seek_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }  
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }    
    /*will clear seeking flags in end function*/
    MMI_MSCR_MSG_TRACE(g_mscr_hd->seek_duration_dst_range);
    
    mmi_mscr_seek_end(1);    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_show_loading
* DESCRIPTION
*  show animation loading
* PARAMETERS
*  percent:  loading percentage 
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_show_loading(U8 percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SHOW_LOADING, percent);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (percent > 100)
    {
        MMI_MSCR_ERR_TRACE(percent);
        return;
    }
    g_mscr_hd->loading_percent = percent;
    mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, MMI_MEDPLY_ANI_LOADING);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();

    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    mmi_medply_main_screen_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_hide_loading
* DESCRIPTION
*  hide animation loading
* PARAMETERS
*  void 
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_hide_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, MMI_MEDPLY_ANI_NULL);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    mmi_medply_main_screen_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_play_animation
* DESCRIPTION
*  play animation 
* PARAMETERS
*  animation:     animation id;
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_play_animation(U8 animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PLAY_ANI, animation);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (animation < MMI_MEDPLY_ANI_VIDEO_OPENING || 
        animation > MMI_MEDPLY_ANI_SNAP_SHOT)
    {
        MMI_MSCR_ERR_TRACE(animation);
        return;
    }
    mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, animation);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    mmi_medply_main_screen_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_stop_animation
* DESCRIPTION
*  stop animation 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_stop_animation(U8 animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_ANI);
	MMI_MSCR_MSG_TRACE(animation);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    /*has animation*/
    if ((g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE) || 
        (GDI_NULL_HANDLE != g_mscr_hd->ani_osd_hdl))
    {
    	if (animation != g_mscr_hd->id_animation)
    	{
			MMI_MSCR_ERR_TRACE(g_mscr_hd->id_animation);
			return;
		}
		
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, MMI_MEDPLY_ANI_NULL);
        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
        gdi_layer_get_position(&x, &y);
        gdi_layer_get_dimension(&w, &h);
        gdi_layer_pop_and_restore_active();
    
        mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
        mmi_medply_main_screen_blt();
    }
}


#ifdef __MMI_MEDIA_PLAYER_AUDIO__
/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_play_spectrum
* DESCRIPTION
*  play spectrum 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_play_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PLAY_SPECTRUM);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }

	MMI_MSCR_MSG_TRACE(g_mscr_hd->view_content);
    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (MMI_MSCR_CONTENT_SPECTRUM == g_mscr_hd->view_content)
    {
    	/*clear middle layer, otherwise ani can't disappear after stop*/
		gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
    	gdi_layer_pop_and_restore_active();
    	if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    	{
    		mmi_mscr_play_spectrum();	
    	}        
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_stop_spectrum
* DESCRIPTION
*  stop audio spectrum 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_stop_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_SPECTRUM);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_mscr_stop_spectrum();
#endif
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_lcd_sleep_in_handler
* DESCRIPTION
*  back light has turn off  
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_lcd_sleep_in_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SLEEP_IN);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_mscr_stop_spectrum();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_lcd_sleep_out_handler
* DESCRIPTION
*  back light has turn on, just goto play spectrum
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_lcd_sleep_out_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SLEEP_OUT);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    MMI_MSCR_MSG_TRACE(g_mscr_hd->view_content);
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);
    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
	/*When in full screen, do not restart spectrum*/
	if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
	{
    	if ((MMI_MSCR_CONTENT_SPECTRUM == g_mscr_hd->view_content) &&
        	(MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status))
    	{
        	mmi_mscr_play_spectrum();
    	}
	}
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_widget_callback_hdlr
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/ 
static void mmi_medply_main_screen_widget_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.widget_callback != NULL)
    {
        g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK,NULL);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_file_path
* DESCRIPTION
*  file path changed, need get new lyrics 
* PARAMETERS
*  filename:   
*  file_f:  if play streaming or not local file, should be zero.    
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_set_file_path(U16* filename, MMI_BOOL file_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_FILE_PATH);

    if(g_medply.widget_callback != NULL)
    {
        StartTimer(MEDPLY_WIDGET_CALLBACK_TIMER, 0,mmi_medply_main_screen_widget_callback_hdlr);
    }

    #ifdef __MMI_NCENTER_SUPPORT__
    mmi_medply_ncenter_update_media();
    #endif
    
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    mmi_mscr_stop_playing();
    mmi_mscr_unprepare_view_content();

    if(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    }
    else
    {
        mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    }
    
    mmi_mscr_init_ui_status();
    /*prepare view need remove if Ctrl call mmi_medply_main_screen_prepare_view*/
    mmi_mscr_prepare_view_content();
    /*need config layer rotate again*/
	mmi_mscr_config_layer_rotate();
    /*after change display content, must do layer blt reset*/
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();

    mmi_medply_main_screen_redraw();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_set_status_and_ani
* DESCRIPTION
*  this function need call by mmi_medply_change_status,
*  used for control UI GUI Timer and back light.
* PARAMETERS
*  status:   
*  ani:    
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_set_status_and_ani(U8 status, U8 ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_SET_STATUS_AND_ANI, status, ani);
	
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }    
    MMI_MSCR_MSG_TRACE(status);

    if ((MMI_MEDPLY_STATUS_READY == status || 
         MMI_MEDPLY_STATUS_PLAYING == status) && 
        (MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content))
    {
        mmi_mscr_update_video_content();
    }
    /*Set Blt Region first*/
    if (g_mscr_hd->id_animation != ani)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
        gdi_layer_get_position(&x, &y);
        gdi_layer_get_dimension(&w, &h);
        gdi_layer_pop_and_restore_active();
    
        mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].x,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].y,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h);
        if (g_mscr_hd->ui_status != status)
        {
            mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].x,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].y,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].w,
                g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].h);
        }
    }
    mmi_mscr_set_status_and_ani(status, ani);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_update_title
* DESCRIPTION
*  mainly used when need update title. 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_main_screen_update_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UPDATE_TITLE);
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
    	  MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    
    mmi_mscr_init_title_text();
     mmi_mscr_draw_title();
    mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].x,
   	                       g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].y,
   	                       g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].w,
   	                       g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].h);
    #endif
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_change_status
* DESCRIPTION
*  mainly used for display animation and buffering status. 
* PARAMETERS
*  void       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_change_status(MMI_BOOL blt_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ui_status, ani_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CHANGE_STATUS, blt_f);

    if(g_medply.widget_callback != NULL)
    {
        g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK,NULL);
    }
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_mus_update_op11_hs32_sidebar_info();
#endif

    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (blt_f)
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE;
    }

    mmi_medply_get_ui_status(&ui_status, &ani_id);
	
    if (MMI_MEDPLY_ANI_SNAP_SHOT == ani_id || MMI_MEDPLY_ANI_NULL == ani_id)
    {
        mmi_mscr_update_ui_status();
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_STATUS_TIMER))
    {
        /*MAUI_01959893*/
        if (ani_id != g_mscr_hd->id_animation)
        {
        	g_mscr_hd->flags |= MMI_MSCR_HD_HAS_STATUS_TIMER;
        		gui_start_timer(MMI_MSCR_UI_UPDATE_STATUS_TIME, 
           	mmi_mscr_update_ui_status);
        }        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_get_ui_status
* DESCRIPTION
*  get current animation and playing status. 
* PARAMETERS
*   ui_status:  return current status, whether it's playing
*   id_ani:     Current status need show which animation       
* RETURNS
*  layer handle
 *****************************************************************************/
void mmi_medply_get_ui_status(U8* ui_status, U8* id_ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state       = mmi_inline_get_status(); 
    *ui_status  = MMI_MEDPLY_STATUS_IDLE;
    *id_ani     = MMI_MEDPLY_ANI_NULL;

    if (mmi_inline_is_single_play())
    {  
        switch(state)
        {
        case SINGLE_STATE_AUDIO_READY:        
        case SINGLE_STATE_VIDEO_READY:
        case SINGLE_STATE_PDL_VIDEO_READY:          
        case SINGLE_STATE_PDL_AUDIO_READY:
        case SINGLE_STATE_STREAM_CONNECTED:    

        case SINGLE_STATE_AUDIO_PAUSE_PROGRESSING:    
        case SINGLE_STATE_VIDEO_PAUSE_PROGRESSING:   
        case SINGLE_STATE_PDL_VIDEO_PAUSE_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            break;    
        case SINGLE_STATE_AUDIO_PLAY: 
        case SINGLE_STATE_VIDEO_PLAY:   
        case SINGLE_STATE_STREAM_PLAY: 
        case SINGLE_STATE_PDL_AUDIO_PLAY:    
        case SINGLE_STATE_PDL_VIDEO_PLAY:        
        case SINGLE_STATE_AUDIO_PLAY_PROGRESSING:
        case SINGLE_STATE_VIDEO_PLAY_PROGRESSING:    
        case SINGLE_STATE_STREAM_PLAY_PROGRESSING:  
        case SINGLE_STATE_PDL_VIDEO_PLAY_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_PLAYING;
            break;
        case SINGLE_STATE_AUDIO_BT_CONNECTING:
        case SINGLE_STATE_VIDEO_BT_CONNECTING:
        case SINGLE_STATE_STREAM_BT_CONNECTING:
        case SINGLE_STATE_PDL_VIDEO_BT_CONNECTING:
        case SINGLE_STATE_PDL_AUDIO_BT_CONNECTING:
            /*prepare bt connecting animation*/
            *id_ani     = MMI_MEDPLY_ANI_BT_CONNECTING;
            break;

        case SINGLE_STATE_VIDEO_OPENING:
        case SINGLE_STATE_PDL_VIDEO_OPENING:
            
            *id_ani     = MMI_MEDPLY_ANI_VIDEO_OPENING;
            break;
        case SINGLE_STATE_STREAM_CONNECTING:   
            
            *id_ani     = MMI_MEDPLY_ANI_RTP_CONNECTING;
            break;
        case SINGLE_STATE_PDL_VIDEO_PAUSE_BUFFERING:
        case SINGLE_STATE_PDL_VIDEO_PLAY_BUFFERING:
        case SINGLE_STATE_PDL_AUDIO_BUFFERING:
        case SINGLE_STATE_STREAM_BUFFERING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            *id_ani     = MMI_MEDPLY_ANI_LOADING;
            break;
        default:
            break;
        }
    }
    else
    {
        switch(state)
        {
        case MEDPLY_STATE_AUDIO_READY:
        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_STREAM_CONNECTED:
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:  
        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            break;

		/*
		 *  There three states all background play states, 
		 *  so no not need show animation.
		 */
		case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:    
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
		case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            /*do not add break here*/
        case MEDPLY_STATE_AUDIO_PLAY:    
        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:    
        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            
        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:    
        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:    
            
            *ui_status  = MMI_MEDPLY_STATUS_PLAYING;
            break;
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_BT_CONNECTING:
            /*prepare bt connecting animation*/
            *id_ani     = MMI_MEDPLY_ANI_BT_CONNECTING;
            break;
        case MEDPLY_STATE_VIDEO_OPENING:
                
            *id_ani     = MMI_MEDPLY_ANI_VIDEO_OPENING;
            break;
        case MEDPLY_STATE_STREAM_CONNECTING:   
            
            *id_ani     = MMI_MEDPLY_ANI_RTP_CONNECTING;
            break;
        case MEDPLY_STATE_STREAM_BUFFERING:
            
            *ui_status  = MMI_MEDPLY_STATUS_READY;
            *id_ani     = MMI_MEDPLY_ANI_LOADING;
            break;
        case MEDPLY_STATE_SNAPSHOT:
            
            *id_ani     = MMI_MEDPLY_ANI_SNAP_SHOT;
            break;
        default:
            break;
        }
    }    
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_GET_UI_STATUS, state, *ui_status, *id_ani);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_main_screen_init
* DESCRIPTION
*  INIT SKIN AND UI
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
void mmi_medply_main_screen_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_flag & MMI_MSCR_UI_HAS_INIT)
    {
        return;
    }
    g_mscr_flag |= MMI_MSCR_UI_HAS_INIT;

    /*init layer region*/
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].x = g_medply_skin.title_layer_rgn_x;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].y = g_medply_skin.title_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].w = g_medply_skin.title_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].h = g_medply_skin.title_layer_rgn_h;
    
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].x = g_medply_skin.view_layer_rgn_x;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].y = g_medply_skin.view_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w = g_medply_skin.view_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h = g_medply_skin.view_layer_rgn_h;
    
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].x = g_medply_skin.ctrl_layer_rgn_x;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].y = g_medply_skin.ctrl_layer_rgn_y;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].w = g_medply_skin.ctrl_layer_rgn_w;
    g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].h = g_medply_skin.ctrl_layer_rgn_h;

    /*init title text display region*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].x = g_medply_skin.title_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].y = g_medply_skin.title_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].w = g_medply_skin.title_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].h = g_medply_skin.title_txt_rgn_h;

    /*init meta image & text display region*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].x = g_medply_skin.meta_img_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].y = g_medply_skin.meta_img_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].w = g_medply_skin.meta_img_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].h = g_medply_skin.meta_img_rgn_h;
    
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].x = g_medply_skin.meta_txt_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].y = g_medply_skin.meta_txt_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].w = g_medply_skin.meta_txt_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].h = g_medply_skin.meta_txt_rgn_h;
   
    /*init meta lyrics display region*/ 
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].x = g_medply_skin.lyrics_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].y = g_medply_skin.lyrics_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].w = g_medply_skin.lyrics_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].h = g_medply_skin.lyrics_rgn_h;
    /*init spectrum display region*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].x = g_medply_skin.spectrum_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].y = g_medply_skin.spectrum_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].w = g_medply_skin.spectrum_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].h = g_medply_skin.spectrum_rgn_h;
    /*init duration bar touch region*/
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION].x = g_medply_skin.duration_bar_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION].y = g_medply_skin.duration_bar_rgn_y;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION].w = g_medply_skin.duration_bar_rgn_w;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_DURATION].h = g_medply_skin.duration_bar_rgn_h;
    
    /*init touch button*/
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].view_x = g_medply_skin.play_pause_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].view_y = g_medply_skin.play_pause_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.x = g_medply_skin.play_pause_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.y = g_medply_skin.play_pause_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.w = g_medply_skin.play_pause_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].pen_rgn.h = g_medply_skin.play_pause_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].up_img_id = g_medply_skin.play_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].down_img_id = g_medply_skin.play_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PLAY_PAUSE].disable_img_id = g_medply_skin.play_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].view_x = g_medply_skin.stop_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].view_y = g_medply_skin.stop_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.x = g_medply_skin.stop_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.y = g_medply_skin.stop_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.w = g_medply_skin.stop_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].pen_rgn.h = g_medply_skin.stop_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].up_img_id = g_medply_skin.stop_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].down_img_id = g_medply_skin.stop_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_STOP].disable_img_id = g_medply_skin.stop_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].view_x = g_medply_skin.prev_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].view_y = g_medply_skin.prev_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.x = g_medply_skin.prev_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.y = g_medply_skin.prev_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.w = g_medply_skin.prev_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].pen_rgn.h = g_medply_skin.prev_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].up_img_id = g_medply_skin.prev_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].down_img_id = g_medply_skin.prev_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_PREV].disable_img_id = g_medply_skin.prev_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].view_x = g_medply_skin.next_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].view_y = g_medply_skin.next_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.x = g_medply_skin.next_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.y = g_medply_skin.next_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.w = g_medply_skin.next_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].pen_rgn.h = g_medply_skin.next_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].up_img_id = g_medply_skin.next_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].down_img_id = g_medply_skin.next_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_NEXT].disable_img_id = g_medply_skin.next_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].view_x = g_medply_skin.shuffle_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].view_y = g_medply_skin.shuffle_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.x = g_medply_skin.shuffle_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.y = g_medply_skin.shuffle_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.w = g_medply_skin.shuffle_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].pen_rgn.h = g_medply_skin.shuffle_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].up_img_id = g_medply_skin.shuffle_off_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].down_img_id = g_medply_skin.shuffle_off_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SHUFFLE].disable_img_id = g_medply_skin.shuffle_off_up_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].view_x = g_medply_skin.repeat_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].view_y = g_medply_skin.repeat_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.x = g_medply_skin.repeat_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.y = g_medply_skin.repeat_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.w = g_medply_skin.repeat_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].pen_rgn.h = g_medply_skin.repeat_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].up_img_id = g_medply_skin.repeat_off_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].down_img_id = g_medply_skin.repeat_off_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_REPEAT].disable_img_id = g_medply_skin.repeat_off_up_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].view_x = g_medply_skin.snap_shot_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].view_y = g_medply_skin.snap_shot_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].pen_rgn.x = g_medply_skin.snap_shot_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].pen_rgn.y = g_medply_skin.snap_shot_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].pen_rgn.w = g_medply_skin.snap_shot_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].pen_rgn.h = g_medply_skin.snap_shot_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].up_img_id = g_medply_skin.snap_shot_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].down_img_id = g_medply_skin.snap_shot_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY].disable_img_id = g_medply_skin.snap_shot_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].view_x      = g_medply_skin.zoom_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].view_y      = g_medply_skin.zoom_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.x   = g_medply_skin.zoom_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.y   = g_medply_skin.zoom_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.w   = g_medply_skin.zoom_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].pen_rgn.h   = g_medply_skin.zoom_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].up_img_id   = g_medply_skin.zoom_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].down_img_id     = g_medply_skin.zoom_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_ZOOM].disable_img_id  = g_medply_skin.zoom_disable_img_id;

    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].view_x = g_medply_skin.mode_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].view_y = g_medply_skin.mode_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.x = g_medply_skin.mode_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.y = g_medply_skin.mode_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.w = g_medply_skin.mode_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].pen_rgn.h = g_medply_skin.mode_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].up_img_id = g_medply_skin.mode_2d_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].down_img_id = g_medply_skin.mode_2d_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_MODE].disable_img_id = g_medply_skin.mode_2d_disable_img_id;
    #endif
	
    #if defined (__MMI_FTE_SUPPORT__)
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].view_x     = g_medply_skin.lsk_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].view_y     = g_medply_skin.lsk_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.x  = g_medply_skin.lsk_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.y  = g_medply_skin.lsk_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.w  = g_medply_skin.lsk_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].pen_rgn.h  = g_medply_skin.lsk_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].up_img_id  = g_medply_skin.lsk_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].down_img_id       = g_medply_skin.lsk_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_LKEY].disable_img_id    = g_medply_skin.lsk_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].view_x     = g_medply_skin.rsk_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].view_y     = g_medply_skin.rsk_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.x  = g_medply_skin.rsk_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.y  = g_medply_skin.rsk_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.w  = g_medply_skin.rsk_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].pen_rgn.h  = g_medply_skin.rsk_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].up_img_id  = g_medply_skin.rsk_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].down_img_id     = g_medply_skin.rsk_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_RKEY].disable_img_id  = g_medply_skin.rsk_disable_img_id;
    #endif
    
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].view_x     = g_medply_skin.volume_inc_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].view_y     = g_medply_skin.volume_inc_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].pen_rgn.x  = g_medply_skin.volume_inc_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].pen_rgn.y  = g_medply_skin.volume_inc_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].pen_rgn.w  = g_medply_skin.volume_inc_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].pen_rgn.h  = g_medply_skin.volume_inc_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].up_img_id  = g_medply_skin.volume_inc_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].down_img_id       = g_medply_skin.volume_inc_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_INC].disable_img_id    = g_medply_skin.volume_inc_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].view_x     = g_medply_skin.volume_dec_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].view_y     = g_medply_skin.volume_dec_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].pen_rgn.x  = g_medply_skin.volume_dec_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].pen_rgn.y  = g_medply_skin.volume_dec_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].pen_rgn.w  = g_medply_skin.volume_dec_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].pen_rgn.h  = g_medply_skin.volume_dec_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].up_img_id  = g_medply_skin.volume_dec_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].down_img_id       = g_medply_skin.volume_dec_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_DEC].disable_img_id    = g_medply_skin.volume_dec_disable_img_id;

    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].view_x     = g_medply_skin.volume_spk_pos_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].view_y     = g_medply_skin.volume_spk_pos_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.x  = g_medply_skin.volume_spk_rgn_x;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.y  = g_medply_skin.volume_spk_rgn_y;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.w  = g_medply_skin.volume_spk_rgn_w;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].pen_rgn.h  = g_medply_skin.volume_spk_rgn_h;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].up_img_id  = g_medply_skin.volume_spk_out_up_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].down_img_id     = g_medply_skin.volume_spk_out_down_img_id;
    g_mscr_ui.touch_btn[MMI_MEDPLY_RGN_ID_VOLUME_SPEAK].disable_img_id  = MMI_MSCR_ERR_IMG_ID;

    /*init volume bar display*/
    g_mscr_ui.volume_img.view_x     = g_medply_skin.volume_bar_pos_x;
    g_mscr_ui.volume_img.view_y     = g_medply_skin.volume_bar_pos_y;
    g_mscr_ui.volume_img.bg_img_id  = g_medply_skin.volume_bar_bg_img_id;
    g_mscr_ui.volume_img.fg_img_id  = g_medply_skin.volume_bar_fg_img_id;
    g_mscr_ui.volume_img.md_img_id  = MMI_MSCR_ERR_IMG_ID;
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    g_mscr_ui.volume_img.is_9slice  = MMI_FALSE;
    g_mscr_ui.volume_img.resized_width = 0;
    g_mscr_ui.volume_img.resized_height = 0;
    #endif
    
    /*init meta user rate image */
    g_mscr_ui.rates_img.view_x      = g_medply_skin.rate_img_pos_x;
    g_mscr_ui.rates_img.view_y      = g_medply_skin.rate_img_pos_y;
    g_mscr_ui.rates_img.bg_img_id   = g_medply_skin.rate_bg_img_id;
    g_mscr_ui.rates_img.fg_img_id   = g_medply_skin.rate_fg_img_id;
    g_mscr_ui.rates_img.md_img_id   = MMI_MSCR_ERR_IMG_ID;
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    g_mscr_ui.rates_img.is_9slice  = MMI_FALSE;
    g_mscr_ui.rates_img.resized_width = 0;
    g_mscr_ui.rates_img.resized_height = 0;
    #endif
    
    /*init duration bar display*/
    g_mscr_ui.duration_img.view_x   = g_medply_skin.duration_bar_pos_x;
    g_mscr_ui.duration_img.view_y   = g_medply_skin.duration_bar_pos_y;
    g_mscr_ui.duration_img.bg_img_id    = g_medply_skin.duration_bar_bg_img_id;
    g_mscr_ui.duration_img.fg_img_id    = g_medply_skin.duration_bar_fg_img_id;
    g_mscr_ui.duration_img.md_img_id    = g_medply_skin.duration_bar_md_img_id;
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    g_mscr_ui.duration_img.is_9slice  = MMI_TRUE;
    g_mscr_ui.duration_img.resized_width = g_medply_skin.duration_bar_rgn_w;
    g_mscr_ui.duration_img.resized_height = g_medply_skin.duration_bar_rgn_h;
    #endif
    
    /*init ticks show*/
    g_mscr_ui.ticks_box.view_x          = g_medply_skin.time_pos_x; 
    g_mscr_ui.ticks_box.view_y          = g_medply_skin.time_pos_y;
    g_mscr_ui.ticks_box.base_number_img_id  = g_medply_skin.time_base_number_img_id; 
    g_mscr_ui.ticks_box.bias_img_id         = g_medply_skin.time_bias_img_id;
    g_mscr_ui.ticks_box.colon_img_id        = g_medply_skin.time_colon_img_id;

	/*check animation range*/
	if ((g_medply_skin.wait_ani_w * g_medply_skin.wait_ani_h) <= (MEDPLY_ANI_LAYER_W * MEDPLY_ANI_LAYER_H))
	{
		MMI_MSCR_MSG_TRACE(0);
		g_mscr_ui.wait_ani_w = g_medply_skin.wait_ani_w;
		g_mscr_ui.wait_ani_h = g_medply_skin.wait_ani_h;
	}
	else
	{
		MMI_MSCR_ERR_TRACE(g_mscr_ui.wait_ani_w);
		MMI_MSCR_ERR_TRACE(g_mscr_ui.wait_ani_h);
		g_mscr_ui.wait_ani_w = MEDPLY_ANI_LAYER_W;
		g_mscr_ui.wait_ani_h = MEDPLY_ANI_LAYER_H;
	}

    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    g_mscr_ui.subtitle_rgn.x        = g_medply_skin.view_layer_rgn_x + MMI_MSCR_SUBTITLE_FONT_SIZE;
    g_mscr_ui.subtitle_rgn.y        = g_medply_skin.view_layer_rgn_y + g_medply_skin.view_layer_rgn_h  - 
                                        MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER - MMI_MSCR_SUBTITLE_HOR_GAP;
    g_mscr_ui.subtitle_rgn.w        = g_medply_skin.view_layer_rgn_w - 2 * MMI_MSCR_SUBTITLE_FONT_SIZE;
    g_mscr_ui.subtitle_rgn.h        = MMI_MSCR_SUBTITLE_FONT_SIZE * MMI_MSCR_SUBTITLE_LINE_NUMBER;
    #endif

}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_create_handle
* DESCRIPTION
*  init handle memory
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_create_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* mem_p;
    U32 nBasicSize, nMemSize, nMemExt = 0, nDataSize;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    nMemSize    = sizeof(mmi_medply_ui_handle_struct);
	nBasicSize  = nMemSize;
/*#if defined(__MMI_MEDIA_PLAYER_VIDEO__)*/
    nDataSize   = sizeof(mmi_medply_video_play_para_struct);
	nMemSize += nDataSize;
/*#endif*/

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    nDataSize   = sizeof(mmi_medply_meta_struct);
    if (nDataSize > nMemExt)
    {
        nMemExt = nDataSize;
    }
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    nDataSize   = sizeof(spectrum_struct);
    if (nDataSize > nMemExt)
    {
        nMemExt = nDataSize;
    }
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif  /*__MMI_MEDIA_PLAYER_AUDIO__*/
    
    nMemSize += nMemExt;
    
#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__)
        nDataSize   = MEDPLY_MAIN_SCREEN_LYRICS_SIZE;
        nMemSize += nDataSize;
#endif  /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/
    
    MMI_ASSERT(MEDPLY_MAIN_SCREEN_HDL_SIZE >= nMemSize);
    gdi_layer_create(0,0,GDI_LCD_WIDTH,GDI_LCD_HEIGHT,&g_gdi_layer_hd);
    mem_p = (U8*)((gdi_layer_struct*)(g_gdi_layer_hd))->buf_ptr;
    MMI_ASSERT(mem_p != NULL); 
    
    g_mscr_hd   = (mmi_medply_ui_handle_struct*)mem_p;
    g_mscr_hd->artwork_mem        = (U8*)mem_p+nMemSize;
    /*g_mscr_hd->artwork_mem      = (U8*)mem_p+nMemSize+MMI_MSCR_LAYER_BUFFER_SIZE;*/
    
    nMemSize = nMemSize - nMemExt - MEDPLY_MAIN_SCREEN_LYRICS_SIZE;

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_mscr_hd->meta_p   = (mmi_medply_meta_struct*)(mem_p+nMemSize);
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
    g_mscr_hd->spectrum_p   = (spectrum_struct*)(mem_p+nMemSize);
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__)
    g_mscr_hd->lyric_p   = (mem_p+nMemSize+nMemExt+MMI_MSCR_SUBTITLE_MAX_BUF_SIZE);
#endif  /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif  /*__MMI_MEDIA_PLAYER_AUDIO__*/

/*#if defined(__MMI_MEDIA_PLAYER_VIDEO__)*/
    g_mscr_hd->video_p  = (mmi_medply_video_play_para_struct*)(mem_p+nBasicSize);
/*#endif*/    
    g_mscr_hd->flags            = 0;
    g_mscr_hd->video_flags      = 0;
    g_mscr_hd->ui_status        = MMI_MEDPLY_STATUS_TOTAL;
    g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;     
    g_mscr_hd->loading_percent  = 0;
    g_mscr_hd->ani_osd_hdl      = GDI_NULL_HANDLE;      
    g_mscr_hd->ani_demo_hdl     = GDI_NULL_HANDLE;
    g_mscr_hd->layer_merge_hdl  = GDI_LAYER_EMPTY_HANDLE;

    //HAL
    g_mscr_hd->layer_video_hw_hdl = GDI_NULL_HANDLE;
    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
    g_mscr_hd->layer_subtitle_hdl = GDI_NULL_HANDLE;
    #endif
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_mscr_hd->meta_p->meta_data.artwork.buffer = NULL;
#endif 
    g_mscr_hd->view_content     = MMI_MSCR_CONTENT_NULL;
    g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_NULL;

    /*check whether it's in full screen play*/
    if (mmi_inline_is_full_screen())
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_FULL_SCREEN;
    }    
    g_mscr_hd->is_paint_ticks   = 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_delete_handle
* DESCRIPTION
*  release handle memory
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_delete_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*Release full memory*/
    g_mscr_hd = NULL;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_create_layer
* DESCRIPTION
*   create media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
 *****************************************************************************/
static  gdi_handle  mmi_mscr_create_layer(U8* mem_p, S32 mem_size, 
                        mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle gdi_hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_create_using_outside_memory(
        rgn_p->x, rgn_p->y, rgn_p->w, rgn_p->h,
        &gdi_hd, mem_p, mem_size);
    
    gdi_layer_push_and_set_active(gdi_hd);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();
    
    return  gdi_hd;
}

//HAL
/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_hw_video_layer
* DESCRIPTION
*   
* PARAMETERS
*   
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_hw_video_layer(MMI_BOOL is_full)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_util_create_hw_layer_extmemory_in_struct hw_layer_para_in;
    mdi_util_create_hw_layer_out_struct hw_layer_para_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_video_hw_hdl);
    MMI_MSCR_MSG_TRACE(is_full);
    memset(&hw_layer_para_in, 0, sizeof(mdi_util_create_hw_layer_extmemory_in_struct));
    memset(&hw_layer_para_out, 0, sizeof(mdi_util_create_hw_layer_out_struct));

    if (GDI_NULL_HANDLE != g_mscr_hd->layer_video_hw_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_video_hw_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_video_hw_hdl);
        g_mscr_hd->layer_video_hw_hdl = GDI_NULL_HANDLE;
    }
    if (is_full)
    {
        //hw_layer_para_in.app_id = 0;
        hw_layer_para_in.buffer = (void*)((gdi_layer_struct*)(g_mscr_hd->layer_full_scr_hdl))->buf_ptr;
        hw_layer_para_in.buffer_size = MMI_MSCR_LAYER_BUFFER_SIZE;
        hw_layer_para_in.offset_x = 0;
        hw_layer_para_in.offset_y = 0;
        hw_layer_para_in.width = g_mscr_hd->layer_full_scr_w;
        hw_layer_para_in.height = g_mscr_hd->layer_full_scr_h;
        hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
    }
    else
    {
        //hw_layer_para_in.app_id = 0;
        hw_layer_para_in.buffer = (void*)((gdi_layer_struct*)(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]))->buf_ptr;
        hw_layer_para_in.buffer_size = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w*
                                       g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h*MMI_MSCR_COLOR_DEPTH;
        hw_layer_para_in.offset_x = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].x;
        hw_layer_para_in.offset_y = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].y;
        hw_layer_para_in.width = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w;
        hw_layer_para_in.height = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h;
        hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_VIDEO;
    }
    g_mscr_hd->layer_video_hw_hdl = mdi_util_hw_layer_create_with_extmemory(&hw_layer_para_in, &hw_layer_para_out);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hw_hdl);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_pop_and_restore_active();

    
#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
     MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
     if (GDI_NULL_HANDLE != g_mscr_hd->layer_subtitle_hdl)
     {
         MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
         mdi_util_hw_layer_free(g_mscr_hd->layer_subtitle_hdl);
         g_mscr_hd->layer_subtitle_hdl = GDI_NULL_HANDLE;
     }
     if (is_full)
     {
         hw_layer_para_in.buffer = (void*)g_mscr_hd->artwork_mem;
         hw_layer_para_in.buffer_size = (g_mscr_hd->layer_full_scr_w - 2*MMI_MSCR_SUBTITLE_FONT_SIZE)*
                                       MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER *MMI_MSCR_SUBTITLE_CF_DEEPTH;
         hw_layer_para_in.offset_x = MMI_MSCR_SUBTITLE_FONT_SIZE;
         hw_layer_para_in.offset_y = g_mscr_hd->layer_full_scr_h - MMI_MSCR_SUBTITLE_FONT_SIZE * MMI_MSCR_SUBTITLE_LINE_NUMBER - MMI_MSCR_SUBTITLE_HOR_GAP;
         hw_layer_para_in.width = g_mscr_hd->layer_full_scr_w - 2*MMI_MSCR_SUBTITLE_FONT_SIZE;
         hw_layer_para_in.height = MMI_MSCR_SUBTITLE_FONT_SIZE*MMI_MSCR_SUBTITLE_LINE_NUMBER;
     }
     else
     {
         //hw_layer_para_in.app_id = 0;
         hw_layer_para_in.buffer = (void*)g_mscr_hd->artwork_mem;
         hw_layer_para_in.buffer_size = g_mscr_ui.subtitle_rgn.w*g_mscr_ui.subtitle_rgn.h*MMI_MSCR_SUBTITLE_CF_DEEPTH;
         hw_layer_para_in.offset_x = g_mscr_ui.subtitle_rgn.x;
         hw_layer_para_in.offset_y = g_mscr_ui.subtitle_rgn.y;
         hw_layer_para_in.width = g_mscr_ui.subtitle_rgn.w;
         hw_layer_para_in.height = g_mscr_ui.subtitle_rgn.h;
     }
     hw_layer_para_in.scenario_id = MDI_MULTIMEDIA_SUBTITLE;
     hw_layer_para_in.color_format = GDI_COLOR_FORMAT_32;
     g_mscr_hd->layer_subtitle_hdl = mdi_util_hw_layer_create_with_extmemory(&hw_layer_para_in, &hw_layer_para_out);
    
     gdi_layer_push_and_set_active(g_mscr_hd->layer_subtitle_hdl);
     gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
     gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
     gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
     gdi_layer_pop_and_restore_active();
    
     mmi_inline_set_subtitle_font_size(MMI_MSCR_SUBTITLE_FONT_SIZE);
 #endif

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_layer
* DESCRIPTION
*   create media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 nMemSize, nLeftSize;
    U8* pLayerMem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT
    gdi_bltdb_enable(GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE);
#endif
    gdi_layer_multi_layer_enable();
    gdi_layer_get_base_handle(&g_mscr_hd->layer_base_hdl);

    /*Create OSD Layer On base Layer*/
#ifdef MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT
    g_mscr_hd->layer_mem = mmi_frm_asm_alloc_nc_r(mmi_inline_get_group_id(), MMI_MSCR_LAYER_BUFFER_SIZE*2);
#else
    g_mscr_hd->layer_mem = mmi_frm_asm_alloc_nc_r(mmi_inline_get_group_id(), MMI_MSCR_LAYER_BUFFER_SIZE);
#endif
    pLayerMem = g_mscr_hd->layer_mem;
    nLeftSize = MMI_MSCR_LAYER_BUFFER_SIZE;

    for (i = 0; i < MMI_MSCR_LAYER_ID_TOTAL; i++)
    {
        nMemSize = g_mscr_ui.layer_rgn[i].w*g_mscr_ui.layer_rgn[i].h*
            MMI_MSCR_COLOR_DEPTH;

        MMI_ASSERT(nLeftSize >= nMemSize);
        
        g_mscr_hd->layer_hdl[i] = mmi_mscr_create_layer(pLayerMem, nMemSize, 
            &g_mscr_ui.layer_rgn[i]);
        
        pLayerMem += nMemSize;
        nLeftSize -= nMemSize;
    }
    /*Create Video Play Full Screen Layer use same mem as OSD layer*/
    pLayerMem = g_mscr_hd->layer_mem;

    /* full scr handle */
#if (0 == MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)
    g_mscr_hd->layer_full_scr_w = GDI_LCD_WIDTH;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_HEIGHT;
#else
    g_mscr_hd->layer_full_scr_w = GDI_LCD_HEIGHT;
    g_mscr_hd->layer_full_scr_h = GDI_LCD_WIDTH;
#endif
    gdi_layer_create_using_outside_memory(
        0, 0, g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h, 
        &g_mscr_hd->layer_full_scr_hdl,
        pLayerMem, MMI_MSCR_LAYER_BUFFER_SIZE);

    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_set_source_key(FALSE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* video handle (same with artwork) */
    nMemSize = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w*
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h*MMI_MSCR_COLOR_DEPTH;

    //HAL
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    }
    else
    {
        mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    }

    /* normal osd ani handle */
    pLayerMem = g_mscr_hd->artwork_mem + nMemSize; /* offset with video handle */
	nMemSize = g_mscr_ui.wait_ani_w * g_mscr_ui.wait_ani_h * MMI_MSCR_COLOR_DEPTH;
    gdi_layer_create_using_outside_memory(
        g_medply_skin.wait_ani_x, g_medply_skin.wait_ani_y,
        g_mscr_ui.wait_ani_w, g_mscr_ui.wait_ani_h, 
        &g_mscr_hd->layer_osd_hdl, pLayerMem, nMemSize);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    gdi_layer_set_source_key(TRUE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* status icon bar */
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)    
    g_mscr_hd->layer_prev_icon_bar_hdl = 
        wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR, mmi_mscr_draw_status_bar_bg);
    #endif

    /*init lcd rotate*/
    if (gdi_lcd_get_rotate_by_layer())
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_ROTATE_BY_LAYER;
    }
        gdi_lcd_set_rotate_by_layer(TRUE);

#ifdef MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT
    /*TOP layer*/
    pLayerMem = g_mscr_hd->layer_mem + MMI_MSCR_LAYER_BUFFER_SIZE;
    nMemSize = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].w*
               g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].h*
               MMI_MSCR_COLOR_DEPTH;

    gdi_bltdb_set_blt_buffer(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP], 
                             pLayerMem, 
                             nMemSize, 
                             pLayerMem + nMemSize, 
                             nMemSize);


    /*Panel layer*/
    pLayerMem += nMemSize*2;
    nMemSize = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].w*
               g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].h*
               MMI_MSCR_COLOR_DEPTH;
   
    gdi_bltdb_set_blt_buffer(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL], 
                             pLayerMem, 
                             nMemSize, 
                             pLayerMem + nMemSize, 
                             nMemSize);

#endif

    /*init rotate before blt*/
    mmi_mscr_config_layer_rotate();
    /*init blt layer before draw image or animation*/
    mmi_mscr_config_layer_blt();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_layer
* DESCRIPTION
*   release media player main screen layer
* PARAMETERS
*   mem_p:
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_unprepare_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_previous_to_base();
    gdi_layer_multi_layer_disable();
    
    /*Release gdi layer*/
    for (i = 0; i < MMI_MSCR_LAYER_ID_TOTAL; i++)
    {        
        mmi_mscr_delete_layer(g_mscr_hd->layer_hdl[i]);
    }    
    mmi_mscr_delete_layer(g_mscr_hd->layer_full_scr_hdl);
    mmi_mscr_delete_layer(g_mscr_hd->layer_osd_hdl);
    mmi_mscr_delete_layer(g_gdi_layer_hd);
    //HAL
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_video_hw_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_video_hw_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_video_hw_hdl);
        g_mscr_hd->layer_video_hw_hdl = GDI_NULL_HANDLE;
    }

    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if (GDI_NULL_HANDLE != g_mscr_hd->layer_subtitle_hdl)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->layer_subtitle_hdl);
        mdi_util_hw_layer_free(g_mscr_hd->layer_subtitle_hdl);
        g_mscr_hd->layer_subtitle_hdl = NULL;
    }
    #endif
    
    /* restore rotate layer flag */
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_ROTATE_BY_LAYER)
    {
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {
        gdi_lcd_set_rotate_by_layer(FALSE);
    }    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_mscr_hd->layer_prev_icon_bar_hdl);
#endif

    mmi_frm_asm_free_r(mmi_inline_get_group_id(), (void *)g_mscr_hd->layer_mem);


#ifdef MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT
    gdi_bltdb_disable();
#endif

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_meta
* DESCRIPTION
*   init meta display scroll context
* PARAMETERS
*   void         
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h, s;
    S32 layer_x, layer_y;
    stFontAttribute *font;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);  
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_pop_and_restore_active();
    /*init meta region*/
    x = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].x - layer_x);
    y = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].y - layer_y);
    w = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].w);
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    s = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].h >> 1);
    #else
    s = (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_TXT].h/3);
    #endif
    if (s > 1)
    {   /*keep border of each scrollbar*/
        h = s - 2;
    }
    else
    {
        h = s;
    }    
    /*init title scroll*/    
    g_mscr_hd->meta_p->meta_data.title[0] = 0;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->title,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.title,
        mmi_mscr_draw_meta_title_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
    #ifndef MMI_MEDPLY_COMP_TEXT_FIXED_COLOR    
        *((current_MMI_theme)->media_player_content_text_color),
        *((current_MMI_theme)->media_player_content_text_border_color));
    #else
        MMI_MSCR_TEXT_FIXED_COLOR,
        MMI_MSCR_TEXT_FIXED_COLOR);
    #endif

    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    font = &MMI_small_font;
    #else
    font = gui_font_get_type(GUI_FONT_SIZE_LIST);
    #endif
    kal_mem_cpy(&g_mscr_hd->meta_p->title.text_font, font, sizeof(stFontAttribute));
#ifndef MMI_MEDPLY_COMP_TEXT_WITHOUT_BORDER
    g_mscr_hd->meta_p->title.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
#endif
    /*init album scroll*/
#ifndef MMI_MSCR_FTE_20_SUPPORT
    g_mscr_hd->meta_p->meta_data.album[0] = 0;
    y += s;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->album,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.album,
        mmi_mscr_draw_meta_album_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
    #ifndef MMI_MEDPLY_COMP_TEXT_FIXED_COLOR    
        *((current_MMI_theme)->media_player_content_text_color),
        *((current_MMI_theme)->media_player_content_text_border_color));
    #else
        MMI_MSCR_TEXT_FIXED_COLOR,
        MMI_MSCR_TEXT_FIXED_COLOR);
    #endif
    
    kal_mem_cpy(&g_mscr_hd->meta_p->album.text_font, font, sizeof(stFontAttribute));
#ifndef MMI_MEDPLY_COMP_TEXT_WITHOUT_BORDER
    g_mscr_hd->meta_p->album.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
#endif
#else /* MMI_MSCR_FTE_20_SUPPORT */
    /* 2 pixels For border in artist + 1 pixel for line */
    s += 3;
#endif
    /*init artist scroll*/
    g_mscr_hd->meta_p->meta_data.artist[0] = 0;
    y += s;
    
    gui_create_scrolling_text(
        &g_mscr_hd->meta_p->artist,
        x, y, w, h,
        g_mscr_hd->meta_p->meta_data.artist,
        mmi_mscr_draw_meta_artist_scroll_callback,
        mmi_mscr_draw_meta_scroll_bg,
    #ifndef MMI_MEDPLY_COMP_TEXT_FIXED_COLOR    
        *((current_MMI_theme)->media_player_content_text_color),
        *((current_MMI_theme)->media_player_content_text_border_color));
    #else
        MMI_MSCR_TEXT_FIXED_COLOR,
        MMI_MSCR_TEXT_FIXED_COLOR);
    #endif
    
    kal_mem_cpy(&g_mscr_hd->meta_p->artist.text_font, font, sizeof(stFontAttribute));
#ifndef MMI_MEDPLY_COMP_TEXT_WITHOUT_BORDER
    g_mscr_hd->meta_p->artist.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
#endif
    /*init meta content*/
    g_mscr_hd->meta_p->flags = 0;
    g_mscr_hd->meta_p->meta_data.album[0]       = 0;
    g_mscr_hd->meta_p->meta_data.artist[0]      = 0;
    g_mscr_hd->meta_p->meta_data.title[0]       = 0;
    g_mscr_hd->meta_p->meta_data.user_rating    = 0;
    g_mscr_hd->meta_p->meta_data.artwork.mime_type  = META_TAG_IMG_TOTAL;
    g_mscr_hd->meta_p->meta_data.artwork.size   = 0;
    g_mscr_hd->meta_p->meta_data.lyrics.size    = 0;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_meta
* DESCRIPTION
*   prepare meta display information, this may cost long time
* PARAMETERS
*   void         
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nRet;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    g_mscr_hd->meta_p->meta_data.album[0]           = 0;
    g_mscr_hd->meta_p->meta_data.artist[0]          = 0;
    g_mscr_hd->meta_p->meta_data.title[0]           = 0;
    g_mscr_hd->meta_p->meta_data.user_rating        = 0;
    g_mscr_hd->meta_p->meta_data.artwork.mime_type  = META_TAG_IMG_TOTAL;
    g_mscr_hd->meta_p->meta_data.artwork.size       = MMI_MSCR_ARTWORK_SIZE;
    g_mscr_hd->meta_p->meta_data.lyrics.size        = 0;
    g_mscr_hd->meta_p->meta_data.artwork.buffer     = NULL;
    #else 
    g_mscr_hd->meta_p->meta_data.artwork.buffer_size = MMI_MSCR_ARTWORK_SIZE;
    g_mscr_hd->meta_p->meta_data.artwork.buffer      = g_mscr_hd->artwork_mem;
    #endif
    
    if (mmi_inline_is_single_play())
    {
        /*
        *   Do not display any meta information in single player
        */
        return;
    }
    nRet = mmi_medply_plst_get_current_details(&g_mscr_hd->meta_p->meta_data);
    MMI_MSCR_MSG_TRACE(nRet);
    
    if (MEDPLY_PLST_NO_ERROR > nRet)
    {
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
        /* 
         * MAUI_01746183: from -220 to -229 is meta parser error, 
         * but meta info still valid for DB project.
         * So do not return!
        */
        if ((nRet > MEDPLY_PLST_ERR_META_NO_MEMORY) || (nRet < MEDPLY_PLST_ERR_META_NO_ENOUGH_BUF))
        {
            MMI_MSCR_MSG_TRACE(nRet);
            /* return; */
        }    
    #else
        MMI_MSCR_MSG_TRACE(nRet);
        /* return; */
    #endif
        if ((0 == mmi_ucs2strlen((const CHAR *) g_mscr_hd->meta_p->meta_data.title)) &&
            (0 == mmi_ucs2strlen((const CHAR *) g_mscr_hd->meta_p->meta_data.album)) &&
            (0 == mmi_ucs2strlen((const CHAR *) g_mscr_hd->meta_p->meta_data.artist)))
        {
            MMI_MSCR_ERR_TRACE(nRet);
            return;
        }
    }

    gui_change_scrolling_text(&g_mscr_hd->meta_p->title, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.title);
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    gui_change_scrolling_text(&g_mscr_hd->meta_p->album, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.album);
    #endif
    gui_change_scrolling_text(&g_mscr_hd->meta_p->artist, 
        (UI_string_type)&g_mscr_hd->meta_p->meta_data.artist);

    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    MMI_MSCR_MSG_TRACE(g_mscr_hd->meta_p->meta_data.artwork.size);
    nRet = mmi_medply_plst_get_current_artwork_ex(g_mscr_hd->artwork_mem,
                            &g_mscr_hd->meta_p->meta_data.artwork.size);
    MMI_MSCR_MSG_TRACE(nRet);
    MMI_MSCR_MSG_TRACE(g_mscr_hd->meta_p->meta_data.artwork.size);    

    #else
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
    #endif 
    #endif
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_meta
* DESCRIPTION
*   un-prepare meta content, stop scroll text
* PARAMETERS
*   void         
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_unprepare_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
    {
        g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_MOVE_TITLE;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->title);
    }
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_META_HAS_MOVE_ALBUM;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->album);
    }
    #endif
    if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
    {
        g_mscr_hd->meta_p->flags &= ~MMI_MSCR_META_HAS_MOVE_ARTIST;
        gui_scrolling_text_stop(&g_mscr_hd->meta_p->artist);
    }
    g_mscr_hd->meta_p->flags &= ~(MMI_MSCR_META_HAS_INIT_TITLE|
        MMI_MSCR_META_HAS_INIT_ALBUM|
        MMI_MSCR_META_HAS_INIT_ARTIST); 

}

#ifndef MMI_MSCR_FTE_20_SUPPORT
/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_title_text
* DESCRIPTION
*   init title display txt
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_title_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *pStr, *pDsp;
#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
    U16 *pExt = NULL;
#endif
    S32 index, total;
#if defined(MMI_MEDPLY_COMP_TITLE_FILE_NAME)
    S32             hf;
    FS_DOSDirEntry  file_info;
#endif
    U8  isProtect = 0;
    U8  isShortName = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MMI_MEDPLY_COMP_TITLE_FILE_NAME)
    pDsp = mmi_inline_get_title_path(&g_mscr_hd->data_from);

    if (MMI_MSCR_DATA_FROM_FILE == g_mscr_hd->data_from)
    {
#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
        /*whether it's protect file, such as DAF or WMA*/
        isProtect = mmi_mscr_is_protect_file(pDsp);
#endif
        /*Check whether it's short file name*/
#ifndef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
        hf = FS_FindFirst((WCHAR*)pDsp, 0, 0, &file_info, g_mscr_hd->title_txt, 
            (MMI_MSCR_FILE_NAME_LEN-1) * ENCODING_LENGTH);
        if (hf >= FS_NO_ERROR)
        {
            if (FS_SFN_MATCH == file_info.NTReserved)
            {
                isShortName = 1;
            }
            FS_FindClose(hf);
        }
#else
        if (mmi_inline_is_single_play())
        {
            hf = FS_FindFirst((WCHAR*)pDsp, 0, 0, &file_info, g_mscr_hd->title_txt, 
                (MMI_MSCR_FILE_NAME_LEN-1) * ENCODING_LENGTH);
            if (hf >= FS_NO_ERROR)
            {
                if (FS_SFN_MATCH == file_info.NTReserved)
                {
                    isShortName = 1;
                }
                FS_FindClose(hf);
            }
        }
        else
        {
            if (mmi_medply_plst_curr_title_is_short())
            {
                isShortName = 1;
                MMI_MSCR_MSG_TRACE(isShortName);
            }
        }
#endif
        /*filter the file patch*/
        pStr = (kal_uint16*)mmi_ucs2chr((const CHAR*)(pDsp+1), L':');
        if (NULL != pStr)
        {
            pDsp = pStr+1;
        }
        else
        {
            pStr = pDsp;
        }    
        while((pStr = (kal_uint16*)mmi_ucs2chr((const CHAR*)(pStr+1), L'\\')) 
            != NULL )
        {
            pDsp = pStr+1;
        } 
        
#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
        /*find the ext name position*/
        if (0 != isProtect)
        {
            pStr = pDsp;
            while((pStr = (kal_uint16*)mmi_ucs2chr((const CHAR*)pStr, L'.')) 
                != NULL )
            {
                pExt = pStr;
                pStr++;
            }   
            /*save and replaced the char '.' to terminator '\0'*/
            if (NULL != pExt)
            {
                *pExt = 0;
            }
        }
#endif
    }     
#else   /*need use list name, defined(MMI_MEDPLY_COMP_TITLE_FILE_NAME)*/
    pDsp = NULL;
#endif  /*defined(MMI_MEDPLY_COMP_TITLE_FILE_NAME)*/
    pStr = g_mscr_hd->title_txt;
    /*Stop current scroll*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_MOVE_TITLE)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_MOVE_TITLE;
        gui_scrolling_text_stop(&g_mscr_hd->title_scroll);             
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_INIT_TITLE; 

    if ((0 != mmi_inline_is_single_play()) || 
        (MMI_MSCR_DATA_FROM_FILE != g_mscr_hd->data_from))
    {
        if (0 != isShortName)
        {
            index = PhnsetGetDefEncodingType();
            mmi_chset_mixed_text_to_ucs2_str(
                (kal_uint8*)pStr,
                (kal_int16)((MMI_MSCR_FILE_NAME_LEN - 1) * ENCODING_LENGTH),
                (kal_uint8*)pDsp,
                (mmi_chset_enum)index);
        }
        else
        {
            mmi_ucs2ncpy((CHAR *)pStr, (const CHAR *)pDsp, MMI_MSCR_FILE_NAME_LEN - 1);
        }
    }
    else
    {
        index = mmi_medply_plst_curr_get_curr_index();
        if (index < 0)
        {
            index = 0;
        }
        else
        {
            index += 1;
        }
        total = mmi_medply_plst_curr_get_total();  
        kal_wsprintf((WCHAR*)pStr, "(%d/%d) ", index, total);
        /*Strlen just ucs2 char number*/
        total = mmi_ucs2strlen((const CHAR *)pStr);
        
        if (0 != isShortName)
        {
            index = PhnsetGetDefEncodingType();
            mmi_chset_mixed_text_to_ucs2_str(
                (kal_uint8*)(pStr+total),
                (kal_int16)((MMI_MSCR_FILE_NAME_LEN - total - 1) * ENCODING_LENGTH),
                (kal_uint8*)pDsp,
                (mmi_chset_enum)index);
        }
        else
        {
            mmi_ucs2ncpy((CHAR *)(pStr+total), (const CHAR *)pDsp, 
                MMI_MSCR_FILE_NAME_LEN - total - 1);  
        }
    }
#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
    /*restore the replaced char '.'*/
    if (NULL != pExt)
    {
        *pExt = L'.';
    }
#endif  
    gui_change_scrolling_text(&g_mscr_hd->title_scroll, pStr);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_title_scroll
* DESCRIPTION
*   init title display
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_title_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute *font;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mscr_hd->title_txt[0] = 0;

    gui_create_scrolling_text(
        &g_mscr_hd->title_scroll,
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].x,
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].y,
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].w,
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_TITLE_TXT].h,
        g_mscr_hd->title_txt,
        mmi_mscr_draw_title_scroll_callback,
        mmi_mscr_draw_title_scroll_bg,
    #ifndef MMI_MEDPLY_COMP_TEXT_FIXED_COLOR    
        *((current_MMI_theme)->title_text_color),
        *((current_MMI_theme)->title_text_border_color));
    #else
        MMI_MSCR_TEXT_FIXED_COLOR,
        MMI_MSCR_TEXT_FIXED_COLOR);
    #endif
    
    font = gui_font_get_type(GUI_FONT_SIZE_TITLE);
    kal_mem_cpy(&g_mscr_hd->title_scroll.text_font, font, sizeof(stFontAttribute));
#ifndef MMI_MEDPLY_COMP_TEXT_WITHOUT_BORDER
    g_mscr_hd->title_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
#endif
}
#endif

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_title_scroll_bg
* DESCRIPTION
*   init title display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_status_bar_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(cx1, cy1, cx2, cy2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}
#endif


#ifndef MMI_MSCR_FTE_20_SUPPORT
/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_title_scroll_bg
* DESCRIPTION
*   init title display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_title_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(x1, y1, x2, y2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_title_scroll_callback
* DESCRIPTION
*   draw title scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_title_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    gui_handle_scrolling_text(&g_mscr_hd->title_scroll);
    gdi_layer_pop_and_restore_active();
}
#endif

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_title_scroll_callback
* DESCRIPTION
*   draw meta title scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_title_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->title);
    gdi_layer_pop_and_restore_active();
}


#ifndef MMI_MSCR_FTE_20_SUPPORT
/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_album_scroll_callback
* DESCRIPTION
*   draw meta album scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_album_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->album);
    gdi_layer_pop_and_restore_active();
    #endif
}
#endif


/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_artist_scroll_callback
* DESCRIPTION
*   draw meta artist scroll callback
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_artist_scroll_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gui_handle_scrolling_text(&g_mscr_hd->meta_p->artist);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_meta_scroll_bg
* DESCRIPTION
*   Clean scroll background
* PARAMETERS
*   region x y        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_meta_scroll_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(x1, y1, x2, y2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_video_content
* DESCRIPTION
*   update video content before video playing
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_video_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 view_content_old = g_mscr_hd->view_content;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UPDATE_VIDEO_CONTENT);

    switch(mmi_inline_get_video_track())
    {
    case MDI_VIDEO_TRACK_A_ONLY:
        
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_DEMO;
		g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
        break;
    case MDI_VIDEO_TRACK_AV:
    case MDI_VIDEO_TRACK_V_ONLY:

        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO;
		g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
        break;
    default:  
        
        g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_NULL;                 
        break;
    }   
    
    MMI_MSCR_MSG_TRACE(g_mscr_hd->view_content);
	mmi_mscr_config_layer_rotate();

	/*MAUI_01693420, If need restart osd animation */
	if (g_mscr_hd->flags & (MMI_MSCR_HD_HAS_OSD_IMAGE|MMI_MSCR_HD_HAS_FULL_SCREEN))
	{
		if ((MMI_MSCR_CONTENT_VIDEO_NULL == view_content_old) &&
			(MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content))
		{
			MMI_MSCR_MSG_TRACE(view_content_old);
			g_mscr_hd->flags |= MMI_MSCR_HD_NEED_RESTART_ANI;
		}		
	}
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_get_view_content
* DESCRIPTION
*   get view content
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_mscr_get_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      u8Ret = MMI_MSCR_CONTENT_NULL;
    U8      u8Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_inline_get_media_type())
    {
    case MEDPLY_TYPE_AUDIO:
    case MEDPLY_TYPE_PDL_AUDIO:
        
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_MAINSCR_DISP, 
            (void*)&u8Value);
        
        switch(u8Value)
        {
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        case MMI_MEDPLY_MAINSCR_DISP_SPECTRUM:/*spectrum*/
            
            u8Ret = MMI_MSCR_CONTENT_SPECTRUM;
            break;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
        case MMI_MEDPLY_MAINSCR_DISP_LYRICS:/*lyrics*/
            
            u8Ret = MMI_MSCR_CONTENT_LYRICS;
            break;
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */
#ifdef __MMI_MEDPLY_MAIN_DISP_ARTWORK__
        case MMI_MEDPLY_MAINSCR_DISP_ARTWORK:/*artwork*/
            
            u8Ret = MMI_MSCR_CONTENT_ARTWORK;
            break;
#endif /*  __MMI_MEDPLY_MAIN_DISP_ARTWORK__ */
        case MMI_MEDPLY_MAINSCR_DISP_DETAIL:/*detail*/  
            
            u8Ret = MMI_MSCR_CONTENT_METAINFO;
            break;
        default:
            break;
        }      
        break;
    case MEDPLY_TYPE_VIDEO:
    case MEDPLY_TYPE_PDL_VIDEO:
    case MEDPLY_TYPE_STREAM: 
    case MEDPLY_TYPE_STREAM_RTSP:
    case MEDPLY_TYPE_STREAM_SDP:    
    case MEDPLY_TYPE_STREAM_RAM:    
        
        u8Ret = MMI_MSCR_CONTENT_VIDEO_NULL; 
        break;
    default:
        
        break;
    }    
    return  u8Ret;
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_view_content
* DESCRIPTION
*   init view content
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mscr_hd->view_content = mmi_mscr_get_view_content();
    g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_INIT_VIEW_CONTENT,g_mscr_hd->view_content);

    switch(g_mscr_hd->view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_VIDEO_BG;
        break;        
#endif   
    case MMI_MSCR_CONTENT_METAINFO:  

        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO;
        mmi_mscr_init_meta();
        break;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_VIDEO_DEMO;
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_DEMO:    
    case MMI_MSCR_CONTENT_VIDEO_NULL:    
        
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_VIDEO_CONTENT|MMI_MSCR_HD_IS_VIDEO_BG;
        break;
    default:
        break;
    } 
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_VIDEO_BG) && 
        (g_mscr_hd->video_flags & MMI_MSCR_HD_VID_HAS_PAINT_BG))
    {
        /*Content Change From Video to Audio, Repaint BG*/
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAINT_BG;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_view_content
* DESCRIPTION
*   init view content
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*Resize full screen layer*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl); 
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {   
    	g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
        gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
        gdi_layer_set_position(0, 0);        
		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    }
    gdi_layer_pop_and_restore_active();

    switch(g_mscr_hd->view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_prepare_lyrics();  
        if (!(g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY))
        {
            /*Lyrics Parse failed, change to audio demo mode*/
            g_mscr_hd->view_content = MMI_MSCR_CONTENT_VIDEO_DEMO;
        }
        break;        
#endif   
    case MMI_MSCR_CONTENT_METAINFO:  
                
        mmi_mscr_prepare_meta();
        break;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        mmi_mscr_init_spectrum();
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:    
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        mmi_mscr_init_video();
        break;
    case MMI_MSCR_CONTENT_NULL:
        /* Clear view if content empty */
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
        break;
    default:
        break;
    }
    /*
    *   lyrics mode or kuro mode may change to video demo mode
    *   Do init video demo mode in last step.
    */
    if (MMI_MSCR_CONTENT_VIDEO_DEMO == g_mscr_hd->view_content)
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_VIDEO_CONTENT|MMI_MSCR_HD_IS_VIDEO_BG;
        g_mscr_hd->view_content_fullscr = g_mscr_hd->view_content;
        
        mmi_mscr_init_video();
    }
    /*do set blt layer after video layer resize*/
    mmi_mscr_config_layer_blt();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_view_content
* DESCRIPTION
*   release view content resource
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_unprepare_view_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  view_content = MMI_MSCR_CONTENT_NULL;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        view_content = g_mscr_hd->view_content;
        
    }
    else
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    if (MMI_MSCR_CONTENT_VIDEO_DEMO == view_content)
    {
        mmi_mscr_stop_video_demo();
    }
    
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_DELTETING))
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);    
            gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
            //52H
            mmi_mscr_draw_osd_background(MMI_FALSE);
            gdi_layer_pop_and_restore_active();
        }
    }
    
    g_mscr_hd->view_content = MMI_MSCR_CONTENT_NULL;
    g_mscr_hd->view_content_fullscr = MMI_MSCR_CONTENT_NULL;
    switch(view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_unprepare_lyrics();          
        break;        
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:
        
        mmi_mscr_stop_spectrum();
		mmi_mscr_uninit_spectrum();
        break;
#endif   
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)    
    case MMI_MSCR_CONTENT_METAINFO:  
        
        mmi_mscr_unprepare_meta();
        break;
#endif     
    case MMI_MSCR_CONTENT_VIDEO_DEMO:    
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:
        mmi_mscr_deinit_video();
        break;    
    default:
        break;
    }

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_DELTETING))
    {
		/*need restore full screen layer*/
		mmi_mscr_restore_full_screen();
    }

	/*clear flag after restore full screen*/
	g_mscr_hd->flags &= ~(MMI_MSCR_HD_IS_VIDEO_CONTENT|MMI_MSCR_HD_IS_VIDEO_BG);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_video
* DESCRIPTION
*   init video region
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_init_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
	S32     resize_w, resize_h;
    #endif
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->video_flags);
        return;
    }

    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
	g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
	if (g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO || g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO_NULL)
	{
	    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hw_hdl);
	}
	else
	{
	    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
	}
    
	resize_w = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w;
	resize_h = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h;

	/* 
	* MT6253 HW resizer and UYVY422 have some limitation, frame buffer size:
	* (1) width % 2 = 0
	* (2) height % 2 = 0
	*/ 
	if (resize_w == 1 || resize_h == 1)
	{
		if (1 == resize_w)
		{
			resize_w++;
			MMI_MSCR_ERR_TRACE(resize_w);
		}
		if (1 == resize_h)
		{
			resize_h++;
			MMI_MSCR_ERR_TRACE(resize_w);
		}
	}
	if (resize_w % 2 != 0)
	{
		/* shrink 1 pixel */
		resize_w --;
		MMI_MSCR_MSG_TRACE(resize_w);
	}
	if (resize_h % 2 != 0)
	{
		/* shirink 1 pixel */
		resize_h --;
		MMI_MSCR_MSG_TRACE(resize_h);
	}

    gdi_layer_resize(resize_w, resize_h);
    gdi_layer_set_position(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].x, 
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].y);
    gdi_layer_set_source_key(FALSE, MMI_MSCR_LAYER_COLOR_TRANSPARENT);
	gdi_layer_set_background(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);

    gdi_layer_pop_and_restore_active();  
    #else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    if (g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO || g_mscr_hd->view_content == MMI_MSCR_CONTENT_VIDEO_NULL)
	{
	    gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hw_hdl);
	}
	else
	{
	    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
	}
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);

    gdi_layer_pop_and_restore_active();
    #endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_deinit_video
* DESCRIPTION
*   
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_deinit_video(void)
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
*   mmi_mscr_init_regn_status
* DESCRIPTION
*   init button and image box status
* PARAMETERS
*           
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_regn_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 u8Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(g_mscr_hd->rgn_hide_flag, 0, MMI_MSCR_BUTTON_ID_EX_TOTAL);
#if defined (__MMI_FTE_SUPPORT__)
    /* always hide some bottons in fte layout */
    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SHUFFLE] = 1;
    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_REPEAT] = 1;
    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_VOLUME_INC] = 1;
    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_VOLUME_DEC] = 1;
#endif
    if (mmi_inline_is_single_play())
    {
        //g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 1;
        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_REPEAT] = 1;
        g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SHUFFLE] = 1;
	g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
        #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
	    switch(g_mscr_hd->view_content)
        {  
        case MMI_MSCR_CONTENT_LYRICS:
        case MMI_MSCR_CONTENT_SPECTRUM:
        case MMI_MSCR_CONTENT_METAINFO:
        case MMI_MSCR_CONTENT_NULL:
        case MMI_MSCR_CONTENT_ARTWORK:    
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
            break;
        case MMI_MSCR_CONTENT_VIDEO:
        case MMI_MSCR_CONTENT_VIDEO_DEMO:
        case MMI_MSCR_CONTENT_VIDEO_NULL:            
		#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 0;
		#else
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
		#endif
            break;
        default:
            break;
        }
        #endif
    } 
	else
	{
		switch(g_mscr_hd->view_content)
        {  
        case MMI_MSCR_CONTENT_LYRICS:
        case MMI_MSCR_CONTENT_SPECTRUM:
        case MMI_MSCR_CONTENT_METAINFO:
        case MMI_MSCR_CONTENT_NULL:
        case MMI_MSCR_CONTENT_ARTWORK:    
        
        #if !defined (__MMI_FTE_SUPPORT__)
            g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
        #endif
        #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
        #endif
            break;
        case MMI_MSCR_CONTENT_VIDEO:
        case MMI_MSCR_CONTENT_VIDEO_DEMO:
        case MMI_MSCR_CONTENT_VIDEO_NULL:    
        #if !defined (__MMI_FTE_SUPPORT__)
        #ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
            g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 0;
        #else
            g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
        #endif
        #endif
		#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 0;
		#else
		    g_mscr_hd->rgn_hide_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
		#endif
            break;
        default:
            break;
        }
	}
	
    kal_mem_set(g_mscr_hd->rgn_disable_flag, 0, MMI_MSCR_BUTTON_ID_EX_TOTAL);   

    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_CONTROL_BUTTONS))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_STOP);
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PREV);
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_NEXT); 
    }
    else if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PAUSE))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
    }
    //for CMCC
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PREV_NEXT))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PREV);
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_NEXT); 
    }
    
#if !defined (__MMI_FTE_SUPPORT__)
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_SNAPSHOT))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY);
    }
#endif

    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_ZOOM))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_ZOOM);
    }   
    /*TO Init Speaker*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK);
    /*To Init play or pause buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
    /*To Init Repeat Buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_REPEAT);
    /*To Init Shuffle Buttons*/
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_SHUFFLE);
    /*To init snap shot or active Buttons*/
    //YYB: need notify tools modify skin tools
#if defined (__MMI_FTE_SUPPORT__) 
    /* donot need to config kuro activate button */
#else
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY);
#endif
#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY_MODE))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_MODE);
    } 
#endif
    /*Init Volume Bar*/
    u8Value = mmi_inline_get_volume_level();
    g_mscr_ui.volume_img.md_range     = 0;
    g_mscr_ui.volume_img.fg_range     = u8Value*100/MMI_MSCR_VOLUME_MAX_LEVEL;
    
    if (0 == u8Value)
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_VOLUME_DEC] = 1;
    }
    else if (MMI_MSCR_VOLUME_MAX_LEVEL == u8Value)
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_VOLUME_INC] = 1;
    }
    
    /*Init Duration Bar*/
    if (0 != mmi_inline_is_duration_seek_able())
    {
        g_mscr_ui.duration_img.bg_img_id = g_medply_skin.duration_bar_bg_img_id;
    }
    else
    {
        g_mscr_ui.duration_img.bg_img_id = 
            g_medply_skin.duration_bar_bg_disable_img_id;
    }
    
    /*Init User rate Bar*/
    g_mscr_ui.rates_img.fg_range      = g_mscr_hd->meta_p->meta_data.user_rating*100/
        MMI_MSCR_USER_RATE_MAX_LEVEL;
    g_mscr_ui.rates_img.md_range      = 0;     

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_ui_status
* DESCRIPTION
*   init view display content, and init timer for moving, init blt layers
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_init_ui_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    **  do this for build cache can't update with play time;
    */
    g_mscr_ui.duration_img.md_range = 0;
    g_mscr_ui.duration_img.fg_range = 0;

    mmi_medply_get_ui_status(&g_mscr_hd->ui_status, &g_mscr_hd->id_animation);

    mmi_mscr_update_duration();    
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    mmi_mscr_init_title_text();
    #endif
    mmi_mscr_init_view_content();
    /*
    **  do this after init meta info for user rate box init;
    */
    mmi_mscr_init_regn_status();
    /* init Soft key position */
    mmi_mscr_init_sk_position();

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG)
    {
        /*Can't set status ans animation before main screen has draw out*/
        mmi_mscr_set_status_and_ani(g_mscr_hd->ui_status, g_mscr_hd->id_animation);    
    }
    else
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_IS_WAITING_STATUS;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_init_sk_position
* DESCRIPTION
*   Every time entry new screen, get the region of L/R sk.
* PARAMETERS
*    
* RETURNS
*  void
*****************************************************************************/
void mmi_mscr_init_sk_position(void)
{
#if !defined (__MMI_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16*    str_p = NULL;
    S32     str_w, str_h;
#ifndef MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN
    S32     x, y, w, h, xoff, yoff;
    S32 truncated_width;
    MMI_BOOL is_truncated;
 #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN)

    /* Calculate LSK */
    str_p = (U16*)GetString(STR_GLOBAL_OPTIONS);
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_measure_string(str_p, &str_w, &str_h);

    g_mscr_hd->lsk_trunc = (str_w > g_medply_skin.soft_lkey_rgn_w)? g_medply_skin.soft_lkey_rgn_w : -1;

    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].x = g_medply_skin.soft_lkey_rgn_x;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].y = g_medply_skin.soft_lkey_rgn_y;
    if (-1 == g_mscr_hd->lsk_trunc)
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].w = str_w + 2;
    }
    else
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].w = g_medply_skin.soft_lkey_rgn_w;
    }
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].h = g_medply_skin.soft_lkey_rgn_h;

    /* Calculate RSK */
    str_p = (U16*)GetString(STR_GLOBAL_BACK);
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_measure_string(str_p, &str_w, &str_h);

    g_mscr_hd->rsk_trunc = (str_w > g_medply_skin.soft_rkey_rgn_w)? g_medply_skin.soft_rkey_rgn_w : -1;
    
    
    if (-1 == g_mscr_hd->rsk_trunc)
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].x = 
                g_medply_skin.soft_rkey_rgn_x + g_medply_skin.soft_rkey_rgn_w - str_w - 2;
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].w = str_w + 2;
    }
    else
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].x = g_medply_skin.soft_rkey_rgn_x;
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].w = g_medply_skin.soft_rkey_rgn_w;
    }
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].y = g_medply_skin.soft_rkey_rgn_y;    
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].h = g_medply_skin.soft_rkey_rgn_h;  

#else

    /* 
     * Calculate LSK 
     */
     
    str_p = (U16*)GetString(STR_GLOBAL_OPTIONS);
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    gui_measure_string(str_p, &str_w, &str_h);
    
    is_truncated = wgui_softkey_get_offset(
                       (UI_string_type)str_p, 
                       &xoff, 
                       &yoff, 
                       &truncated_width,
                       MMI_LEFT_SOFTKEY,
                   #ifdef __MMI_SCREEN_ROTATE__
                       mmi_frm_get_screen_rotate()
                   #else
                       MMI_FRM_SCREEN_ROTATE_0
                   #endif
                       );
    wgui_softkey_get_position(MMI_LEFT_SOFTKEY, &x, &y);
    wgui_softkey_get_dimension(MMI_LEFT_SOFTKEY, &w, &h);

    /* set if need trunc */
    g_mscr_hd->lsk_trunc = (is_truncated)? truncated_width : -1;

    /*add one pixel for border*/
    /*xoff += 1;*/        
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].y = (S16)yoff;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].h = (S16)(h-(yoff-y));
    if (r2lMMIFlag)
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].x = (S16)(xoff - str_w);
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].w = (S16)xoff;
    }
    else
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].x = (S16)xoff;
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LKEY_BTN].w = (S16)str_w + 2;
    }   

    /* 
     * Calculate RSK 
     */
    str_p = (U16*)GetString(STR_GLOBAL_BACK);
    
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_measure_string(str_p, &str_w, &str_h);
    is_truncated = wgui_softkey_get_offset(
                       (UI_string_type)str_p, 
                       &xoff, 
                       &yoff, 
                       &truncated_width,
                       MMI_RIGHT_SOFTKEY,
                   #ifdef __MMI_SCREEN_ROTATE__
                       mmi_frm_get_screen_rotate()
                   #else
                       MMI_FRM_SCREEN_ROTATE_0
                   #endif
                       );    
    wgui_softkey_get_position(MMI_RIGHT_SOFTKEY, &x, &y);
    wgui_softkey_get_dimension(MMI_RIGHT_SOFTKEY, &w, &h);
    /* set if need trunc */
    g_mscr_hd->rsk_trunc = (is_truncated)? truncated_width : -1;
    /*remove one pixel for border*/
    /*xoff -= 1;*/
        
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].y = (S16)yoff;
    g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].h = (S16)(h-(yoff-y));
    if (r2lMMIFlag)
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].x = (S16)(xoff - str_w);
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].w = (S16)xoff;
    }
    else
    {
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].x = (S16)xoff;
        g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_RKEY_BTN].w = (S16)str_w + 2;
    }   
#endif
#endif /* !defined (__MMI_FTE_SUPPORT__) */
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_ui_status
* DESCRIPTION
*   after ctrl status change, use time call update status
* PARAMETERS
*    
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_update_ui_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ui_status, ani_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_STATUS_TIMER;

    mmi_medply_get_ui_status(&ui_status, &ani_id);
    mmi_medply_main_screen_set_status_and_ani(ui_status, ani_id);
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_BLT_STATUS_CHANGE;
        mmi_medply_main_screen_blt();
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_set_status_and_ani
* DESCRIPTION
*   init view display content, and init timer for moving, init blt layers
* PARAMETERS
*   ui_status:  new ui status
*   id_ani:     animation id for main screen to show  
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_set_status_and_ani(U8 ui_status, U8 id_ani)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ani_img_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_MSCR_MSG_TRACE(id_ani);
    /*MAUI_01697260, if id_ani != ani_loading, clear the percent*/
    if (MMI_MEDPLY_ANI_LOADING != id_ani)
    {
        /*
        **  Clean loading percentage in there, 
        **  for the api not used in pair by ctrl
        */
        MMI_MSCR_MSG_TRACE(g_mscr_hd->id_animation);
        g_mscr_hd->loading_percent = 0;
    }
    g_mscr_hd->id_animation = id_ani;
    /*To Stop Animation and remove the OSD flag*/
    switch(id_ani)
    {
    case MMI_MEDPLY_ANI_LOADING:

        ani_img_id = MMI_MSCR_ERR_IMG_ID;
        /*g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;*/        
        mmi_mscr_draw_osd_loading();
        break;
    case MMI_MEDPLY_ANI_VIDEO_OPENING:

        ani_img_id = g_medply_skin.wait_open_ani_id;
        break;
    case MMI_MEDPLY_ANI_BT_CONNECTING:

        ani_img_id = g_medply_skin.wait_bt_connect_ani_id;
        break;
    case MMI_MEDPLY_ANI_RTP_CONNECTING:

        ani_img_id = g_medply_skin.wait_rtp_connect_ani_id;
        break;
    case MMI_MEDPLY_ANI_SNAP_SHOT:

        ani_img_id = g_medply_skin.wait_snap_shot_ani_id;
        break;
    default :
        
        ani_img_id = MMI_MSCR_ERR_IMG_ID;
        break;
    }
    /*
    *   the status need update first before update status
    */
    mmi_mscr_update_duration();
    mmi_mscr_draw_duration();   

    if (g_mscr_hd->ui_status != ui_status)
    {   /*NO status update*/
        MMI_MSCR_MSG_TRACE(ui_status);
        g_mscr_hd->ui_status = ui_status;   
    }
        
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {          
        mmi_mscr_start_playing();
    }
    else
    {
        mmi_mscr_stop_playing();
    }
    /*
    *   The ui status may changed, although ui state may same
    *   button status need update after status change
    */
    mmi_mscr_update_redraw_button();

    if (MMI_MEDPLY_ANI_LOADING != g_mscr_hd->id_animation)
    {
        if (MMI_MSCR_ERR_IMG_ID != ani_img_id)
        {  
            /*g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;*/
            mmi_mscr_start_osd_animation(ani_img_id);
        }    
        else
        {
            /*Stop animation, reset g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;*/
            mmi_mscr_stop_osd_animation(1);
        }
    }
    mmi_mscr_config_layer_blt();  
    mmi_mscr_config_backlight();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_start_playing
* DESCRIPTION
*   begin playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_start_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8  view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 	
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL)
    {   /*Do not show playing in pause status*/
    	MMI_MSCR_MSG_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER))
    {
        if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content)
        {
            gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME_VIDEO, mmi_mscr_update_playing);
        }
        else
        {
            gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME, mmi_mscr_update_playing);
        }
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;        
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_START_PLAYING, view_content);
	
    switch(view_content)
    { 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:  
        /*start to show spectrum*/
        mmi_mscr_play_spectrum();
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        /*start to show video demo ani*/
        mmi_mscr_play_video_demo();
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_playing
* DESCRIPTION
*   stop playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8  view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAYING_TIMER)
    {
        gui_cancel_timer(mmi_mscr_update_playing);
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PLAYING_TIMER;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_PLAYING, view_content);
	
    switch(view_content)
    { 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    case MMI_MSCR_CONTENT_SPECTRUM:  
        /*start to show spectrum*/
        mmi_mscr_stop_spectrum();
        break;
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        /*start to show video demo ani*/
        mmi_mscr_stop_video_demo();
        break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_IS_DELTETING))
        {
            mmi_mscr_update_lyrics();    
            mmi_mscr_draw_lyrics();
        }
        break;        
#endif      
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_update_playing
* DESCRIPTION
*   update playing status
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_update_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content)
    {
        gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME_VIDEO, mmi_mscr_update_playing);
    }
    else
    {
        gui_start_timer(MMI_MSCR_UI_UPDATE_PLAY_TIME, mmi_mscr_update_playing);
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAYING_TIMER;
    mmi_mscr_update_duration();
    mmi_mscr_show_moving(1);    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_layer_rotate
* DESCRIPTION
*   config layers rotate
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_config_layer_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	g_mscr_hd->flags &= ~MMI_MSCR_HD_FULL_LAYER_ROTATE;
    g_mscr_hd->video_p->idp_rotate = MDI_VIDEO_LCD_ROTATE_0;
#if (0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
		/* chipset other than MT6238 */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        g_mscr_hd->video_p->layer_lcd_rotate = MDI_VIDEO_LCD_ROTATE_270;
        }
        else
        {
		gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        g_mscr_hd->video_p->layer_lcd_rotate = MDI_VIDEO_LCD_ROTATE_0;
            }
#else /*(0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/
    /*for landscape*/
    g_mscr_hd->video_p->idp_rotate = MDI_VIDEO_LCD_ROTATE_0;
    g_mscr_hd->video_p->layer_lcd_rotate = MDI_VIDEO_LCD_ROTATE_0;
#endif/*(0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)*/
    
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CONFIG_ROTATE, 
			  g_mscr_hd->video_p->layer_lcd_rotate,	g_mscr_hd->video_p->idp_rotate);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_layer_blt
* DESCRIPTION
*   config blt to lcd layers
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_config_layer_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle h1, h2, h3, h4;
	gdi_handle temp_hdl;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content)
        {
            temp_hdl = g_mscr_hd->layer_video_hw_hdl;
        }        
        else
        {
            temp_hdl = g_mscr_hd->layer_full_scr_hdl;
        }
            
        #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
        if(MMI_TRUE == mmi_inline_has_subtitle())
        {
            if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
            {           
                gdi_layer_set_blt_layer(temp_hdl, g_mscr_hd->layer_subtitle_hdl, g_mscr_hd->layer_osd_hdl, GDI_NULL_HANDLE);
                g_mscr_hd->video_p->layer_hdl = temp_hdl;
                g_mscr_hd->video_p->layer_subtitle_hdl = g_mscr_hd->layer_subtitle_hdl;
                g_mscr_hd->video_p->layer_blt_flag    = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
                g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
                g_mscr_hd->video_p->layer_subtitle_flag   = GDI_LAYER_ENABLE_LAYER_1;
    }
    else
    {       
                gdi_layer_set_blt_layer(temp_hdl, g_mscr_hd->layer_subtitle_hdl, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
                g_mscr_hd->video_p->layer_hdl = temp_hdl;
                g_mscr_hd->video_p->layer_subtitle_hdl = g_mscr_hd->layer_subtitle_hdl;
                g_mscr_hd->video_p->layer_blt_flag    = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
                g_mscr_hd->video_p->layer_subtitle_flag   = GDI_LAYER_ENABLE_LAYER_1;
            }
        }
        else
        #endif
        {
    	if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
    	{
                gdi_layer_set_blt_layer(temp_hdl, g_mscr_hd->layer_osd_hdl, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
                g_mscr_hd->video_p->layer_hdl = temp_hdl;
                g_mscr_hd->video_p->layer_blt_flag    = 
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
            }
            else
            {                          
                gdi_layer_set_blt_layer(temp_hdl, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
                g_mscr_hd->video_p->layer_hdl = temp_hdl;
                g_mscr_hd->video_p->layer_blt_flag    = GDI_LAYER_ENABLE_LAYER_0;
                g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
            }
        }        
    }
    else
    {
        if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content || MMI_MSCR_CONTENT_VIDEO_NULL == g_mscr_hd->view_content)
            {
                temp_hdl = g_mscr_hd->layer_video_hw_hdl;
            }
			else
			{
			    temp_hdl = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID];
			}
        
    	if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
    	{
            gdi_layer_set_blt_layer(
                temp_hdl,             
                g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP], 
                g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL],
                g_mscr_hd->layer_osd_hdl);
			
			if (g_mscr_hd->flags & MMI_MSCR_HD_IS_VIDEO_CONTENT)
			{
				g_mscr_hd->video_p->layer_hdl = g_mscr_hd->layer_video_hw_hdl;
	        	g_mscr_hd->video_p->layer_blt_flag    = 
    	            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | 
        	        GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
        		g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
			}
   		}
    	else
    	{
    	    #ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
            if(MMI_TRUE == mmi_inline_has_subtitle())
            {
                gdi_layer_set_blt_layer(             
                    temp_hdl,
                    g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP],
                    g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL],
                    g_mscr_hd->layer_subtitle_hdl
    	            );
			    g_mscr_hd->video_p->layer_hdl = g_mscr_hd->layer_video_hw_hdl ; 
                g_mscr_hd->video_p->layer_subtitle_hdl = g_mscr_hd->layer_subtitle_hdl;
	            g_mscr_hd->video_p->layer_blt_flag    = 
    	            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 ;
        	    g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
                g_mscr_hd->video_p->layer_subtitle_flag   = GDI_LAYER_ENABLE_LAYER_3;
            }
            else
            #endif
            {
        	    gdi_layer_set_blt_layer(             
                    temp_hdl,
                    g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP],
                    g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL],
                    GDI_LAYER_EMPTY_HANDLE
    	            );
			    g_mscr_hd->video_p->layer_hdl = g_mscr_hd->layer_video_hw_hdl ; 
                g_mscr_hd->video_p->layer_blt_flag    = 
    	            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 ;
        	    g_mscr_hd->video_p->layer_play_flag   = GDI_LAYER_ENABLE_LAYER_0;
                g_mscr_hd->video_p->layer_subtitle_flag   = 0;
            }
    	}
              
    }
	gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_CONFIG_BLT, h1, h2, h3,h4);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_backlight
* DESCRIPTION
*   config backlight
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_config_backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  is_enable = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status))
    {
        switch(g_mscr_hd->view_content)
        {
        case MMI_MSCR_CONTENT_VIDEO:
            
            is_enable = 1;
            break;
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__   
        case MMI_MSCR_CONTENT_LYRICS:
            if (g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY)
            {
                is_enable = 1;
            }
            break;
#endif
        default:
            break;
        }
        /*10A No screen saver*/
        /*if (mmi_inline_is_single_play())
        {
            MMI_MSCR_MSG_TRACE(is_enable);
            is_enable = 1;
        }*/
    }
    mmi_mscr_enable_backlight(is_enable);
	MMI_MSCR_MSG_TRACE(is_enable);
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_enable_backlight
* DESCRIPTION
*   enable back light, when tv out change status, there also change play status.  
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_enable_backlight(U8 is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != is_enable)
    {        
        if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV))
        {
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV;

            /* 
            * This is used to solve a very rare situation. When the screen previous 
            * to this screen is a horizontal screen. Before enter this screen, 
            * the IMELODY turn off the back light. While exit previous screen, 
            * the layer rotate back to normal size and the content is not correct.
            * So when calling srv_backlight_turn_on, 
            * LCD is in sleepin state and draw wrong content to LCD.
            * So we need to clear the buffer first to avoid this situation.
            */
            /*gdi_layer_clear(GDI_COLOR_BLACK); */               
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        }
    }
    else
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV)
        {
            g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_ENABLE_BKLT_NO_TV;

            srv_backlight_turn_off();
        }
    }    
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_osd_loading
* DESCRIPTION
*   draw osd loading 
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_reset_normal_osd_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 x, y;
    S32 w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
    {
        return;
    }
    */
    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
#if (0 != MMI_MEDPLY_COMP_FULLSCR_ROTATE_LAYER)
        x = (GDI_LCD_HEIGHT-g_mscr_ui.wait_ani_w)/2;
        y = (GDI_LCD_WIDTH-g_mscr_ui.wait_ani_h)/2;
#else
        x = (GDI_LCD_WIDTH-g_mscr_ui.wait_ani_w)/2;
        y = (GDI_LCD_HEIGHT-g_mscr_ui.wait_ani_h)/2;
#endif
    }
    else
    {
        x = g_medply_skin.wait_ani_x;
        y = g_medply_skin.wait_ani_y;
    }
    w = g_mscr_ui.wait_ani_w;
    h = g_mscr_ui.wait_ani_h;
    gdi_layer_set_position(x, y);
    gdi_layer_resize(w, h);
    gdi_layer_pop_and_restore_active();

    mmi_mscr_merge_blt_rgn(x, y, w, h);
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_osd_loading
* DESCRIPTION
*   draw osd loading 
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_osd_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, w, h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mscr_stop_osd_animation(0);
    mmi_mscr_pause_view();

	//lry modify: need set flag before prepare_merge_layer
	g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;
	
    mmi_mscr_reset_normal_osd_position();
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {

        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
        mmi_mscr_config_layer_blt();
    }
    else
    {        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    }
    gdi_push_and_set_alpha_blending_source_layer(GDI_NULL_HANDLE);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);

    x1 = g_medply_skin.load_pecentage_bg_x - g_medply_skin.wait_ani_x;
    y1 = g_medply_skin.load_pecentage_bg_y - g_medply_skin.wait_ani_y;

    #ifdef MMI_MSCR_FTE_20_SUPPORT
    w = g_mscr_ui.wait_ani_w;
    h = g_mscr_ui.wait_ani_h;
    gdi_image_draw_resized_id(x1, y1, w, h, IMG_ID_MEDPLY_OSD_LOADING_BG);
    #else
    gdi_image_draw_id(x1, y1, g_medply_skin.load_pecentage_bg_img_id);
    #endif
    
    gdi_layer_push_clip();

    x1 = g_medply_skin.load_pecentage_fg_x - g_medply_skin.wait_ani_x;
    y1 = g_medply_skin.load_pecentage_fg_y - g_medply_skin.wait_ani_y;

    #ifdef MMI_MSCR_FTE_20_SUPPORT
    w = g_medply_skin.load_pecentage_fg_w;
    h = g_medply_skin.load_pecentage_fg_h;
    gdi_image_draw_resized_id(x1, y1, w, h, IMG_ID_MEDPLY_OSD_LOADING_EMPTY);
    #else
    gdi_image_get_dimension_id(g_medply_skin.load_pecentage_fg_img_id, &w, &h);
    #endif

    x2 = x1 + w * g_mscr_hd->loading_percent/100;
    y2 = y1 + h;
    
    gdi_layer_set_clip(x1, y1, x2, y2);   
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    gdi_image_draw_resized_id(x1, y1, w, h, IMG_ID_MEDPLY_OSD_LOADING_FG);
    #else
    gdi_image_draw_id(x1, y1, g_medply_skin.load_pecentage_fg_img_id);
    #endif   
    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_start_osd_animation
* DESCRIPTION
*   start osd animation
* PARAMETERS
*   ani_id: animation id        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_start_osd_animation(U16 ani_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_START_OSD_ANI, ani_id);
	
    mmi_mscr_stop_osd_animation(0);
    mmi_mscr_pause_view();

	/*lry modify: need set flag before prepare_merge_layer*/
	g_mscr_hd->flags |= MMI_MSCR_HD_HAS_OSD_IMAGE;
	g_mscr_hd->flags &= ~MMI_MSCR_HD_NEED_RESTART_ANI;
	
    mmi_mscr_reset_normal_osd_position();
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
		mmi_mscr_config_layer_blt();
    }
    else
    {        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    }
    gdi_push_and_set_alpha_blending_source_layer(GDI_NULL_HANDLE);
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    gdi_image_draw_resized_id(0, 0, g_mscr_ui.wait_ani_w, g_mscr_ui.wait_ani_h, IMG_ID_MEDPLY_OSD_LOADING_BG);
    gdi_image_draw_animation_id(
        g_medply_skin.wait_ani_fg_x - g_medply_skin.wait_ani_x,
        g_medply_skin.wait_ani_fg_y - g_medply_skin.wait_ani_y,
        IMG_ID_MEDPLY_OSD_LOADING_FG_ANI,
        &g_mscr_hd->ani_osd_hdl);
    #else
    gdi_image_draw_animation_id(0, 0, ani_id, &g_mscr_hd->ani_osd_hdl);
    #endif
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_osd_animation
* DESCRIPTION
*   stop osd animation
* PARAMETERS
*   is_restore: whether restore animation region        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_stop_osd_animation(U8 is_restore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_STOP_OSD_ANI, is_restore);
	
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {        
        /*
        **  in full screen playing, can't restore view
        */
        is_restore = 0;
    }
    if (GDI_NULL_HANDLE != g_mscr_hd->ani_osd_hdl)
    {
        if (GDI_ERROR_HANDLE != g_mscr_hd->ani_osd_hdl)
        {
            gdi_image_stop_animation(g_mscr_hd->ani_osd_hdl);
        }
        g_mscr_hd->ani_osd_hdl = GDI_NULL_HANDLE;

        gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }   

	if (! (g_mscr_hd->flags & MMI_MSCR_HD_IS_DELTETING))
	{
	    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
		{
			g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_OSD_IMAGE;

			MMI_MSCR_MSG_TRACE(is_restore);
			if (0 != is_restore)
			{
				mmi_mscr_resume_view();
			}  
		}
	}

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_play_video_demo
* DESCRIPTION
*   play demo video animation
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_play_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    S32 img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_MSCR_MSG_TRACE(0);
	
    if (GDI_NULL_HANDLE != g_mscr_hd->ani_demo_hdl)
    {
    	MMI_MSCR_MSG_TRACE(1);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    }
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);      
    gdi_image_get_dimension_id(g_medply_skin.unsupport_video_def_ani_id, &img_w, &img_h);
    
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);

    MMI_MSCR_MSG_TRACE(w);
    MMI_MSCR_MSG_TRACE(h);

    x = (w - img_w) >> 1;
    y = (h - img_h) >> 1;

    /*When there has osd layer, so need flat two layers*/
    gdi_anim_set_blt_before_callback(mmi_mscr_blt_demo_callback); 

    gdi_image_draw_animation_id(x, y, g_medply_skin.unsupport_video_def_ani_id, 
        &g_mscr_hd->ani_demo_hdl);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_draw_video_demo
* DESCRIPTION
*   draw demo video frame
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_draw_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    S32 img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    } 
    gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
    
    gdi_image_get_dimension_id(g_medply_skin.unsupport_video_def_ani_id, &img_w, &img_h);
    gdi_layer_get_position(&x, &y);
    gdi_layer_get_dimension(&w, &h);
    
    mmi_mscr_merge_blt_rgn((S16)x, (S16)y, (S16)w, (S16)h);

    x = (w - img_w) >> 1;
    y = (h - img_h) >> 1;  
    
    MMI_MSCR_MSG_TRACE(w);
    MMI_MSCR_MSG_TRACE(h);
    
    gdi_image_draw_id(x, y, g_medply_skin.unsupport_video_def_ani_id);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_stop_video_demo
* DESCRIPTION
*   stop demo video animation
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_stop_video_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_MSCR_MSG_TRACE(g_mscr_hd->ani_demo_hdl);
	
    if (GDI_NULL_HANDLE != g_mscr_hd->ani_demo_hdl)
    {
        if (GDI_ERROR_HANDLE != g_mscr_hd->ani_demo_hdl)
        {
            gdi_image_stop_animation(g_mscr_hd->ani_demo_hdl);
        }
        g_mscr_hd->ani_demo_hdl = GDI_NULL_HANDLE;         
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_IS_DELTETING)
    {
        return;
    }
    mmi_mscr_draw_video_demo();
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_blt_demo_callback
* DESCRIPTION
*   process before animation paint to lcd
* PARAMETERS
*   void      
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_blt_demo_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_BLT_DEMO_CB, ret);

    if (NULL == g_mscr_hd)
    {
        /*Add Log for this is callback function, can't ctrl by module itself*/
        MMI_MSCR_ERR_TRACE(g_mscr_hd);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE))
    {
        MMI_MSCR_ERR_TRACE(g_mscr_hd->flags);
        return;
    }
    mmi_medply_main_screen_blt();
}


#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_mscr_free_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
static  void  mmi_mscr_free_mem_lyrics(void* p, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //applib_mem_screen_free(p);
    if (NULL == g_mscr_hd)
    {
        MMI_MSCR_ERR_TRACE(p);
        return;
    }
    if (p == g_mscr_hd->lyric_p)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_USED_ARTWORK_MEM;
        MMI_MSCR_MSG_TRACE(1);

        return;
    }
    MMI_MSCR_ERR_TRACE(p);
    applib_mem_screen_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mscr_malloc_mem_lyrics
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return memory address, 
 *****************************************************************************/
static  void* mmi_mscr_malloc_mem_lyrics(kal_uint32 nSize, kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mscr_hd)
    {
        return  NULL;
    }
    MMI_MSCR_MSG_TRACE(nSize);
    if (nSize >= MMI_MSCR_ARTWORK_SIZE - MMI_MSCR_SUBTITLE_MAX_BUF_SIZE)
    {
        MMI_MSCR_ERR_TRACE(nSize);
        return  applib_mem_screen_alloc_framebuffer(nSize);    
    }

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_USED_ARTWORK_MEM)
    {
        MMI_MSCR_ERR_TRACE(0);
        return  applib_mem_screen_alloc_framebuffer(nSize);    
    }
    else
    {
        MMI_MSCR_MSG_TRACE(1);
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_USED_ARTWORK_MEM;

        return  (void*)g_mscr_hd->lyric_p;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_prepare_lyrics
* DESCRIPTION
*   prepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_prepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 font_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_lyrics_box.time_out   = 0;
    g_lyrics_box.last_time  = (U16)(g_mscr_hd->playtime/MMI_MSCR_UI_UPDATE_PLAY_TIME);
    /*init meta content*/
    g_mscr_hd->meta_p->flags = 0;
    g_mscr_hd->meta_p->meta_data.album[0]       = 0;
    g_mscr_hd->meta_p->meta_data.artist[0]      = 0;
    g_mscr_hd->meta_p->meta_data.title[0]       = 0;
    g_mscr_hd->meta_p->meta_data.user_rating    = 0;
    g_mscr_hd->meta_p->meta_data.artwork.mime_type  = META_TAG_IMG_TOTAL;
    g_mscr_hd->meta_p->meta_data.artwork.size   = 0;
    g_mscr_hd->meta_p->meta_data.lyrics.size    = 0;

    if (NULL == g_lyrics)
    {
        gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST)); 
        font_h = gui_get_character_height();
        /*check normal screen lyrics region is ok*/
        if ((g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].h < (font_h + 2)) || 
            (g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_LYRICS].w <= 4*font_h))
        {
            return;
        }
        g_lyrics_box.font_height    = font_h; 

        g_lyrics = lyrics_parse_create(MMI_MSCR_UI_UPDATE_PLAY_TIME,/*lyrics update ms*/
            mmi_mscr_malloc_mem_lyrics, mmi_mscr_free_mem_lyrics, 0); 
    }    
    if ((NULL != g_lyrics) && !(g_mscr_flag & MMI_MSCR_UI_HAS_PARSE_LYRICS))
    {
        mmi_mscr_parse_lyrics();
        if (g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY)
        {
            mmi_mscr_config_lyrics();
            mmi_mscr_update_lyrics();
        }
        else
        {
            mmi_mscr_unprepare_lyrics();
        }
    } 
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_unprepare_lyrics
* DESCRIPTION
*   unprepare lyrics display
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_unprepare_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (NULL != g_lyrics)
    {     
        lyrics_parse_release();
        g_lyrics = NULL;
    }
    g_mscr_flag &= ~(MMI_MSCR_UI_HAS_PARSE_LYRICS|MMI_MSCR_UI_IS_LYRICS_READY);    
}


/*****************************************************************************
* FUNCTION
*   mmi_mscr_config_lyrics
* DESCRIPTION
*   configure lyrics display region 
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_config_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!(g_mscr_flag & MMI_MSCR_UI_IS_LYRICS_READY))
    {
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    }    
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_layer_get_dimension(&layer_w, &layer_h);
    gdi_layer_pop_and_restore_active();

    g_lyrics_box.line_count     = 
        (U8)(layer_h/(g_lyrics_box.font_height+MMI_MSCR_LYRICS_GAP_H) );    
    if (g_lyrics_box.line_count > MMI_MSCR_LYRICS_MAX_LINE)
    {
        g_lyrics_box.line_count = MMI_MSCR_LYRICS_MAX_LINE;
    }
    g_lyrics_box.line_focus     = g_lyrics_box.line_count/2;
    g_lyrics_box.line_focus_id  = LYRICS_MAX_LINES; 
    g_lyrics_box.line_height    = layer_h/g_lyrics_box.line_count;
    
    g_lyrics_box.rgn_txt.x = layer_x;
    g_lyrics_box.rgn_txt.y = layer_y;
    g_lyrics_box.rgn_txt.w = layer_w;
    g_lyrics_box.rgn_txt.h = g_lyrics_box.line_height*g_lyrics_box.line_count;
    g_lyrics_box.rgn_txt.y = g_lyrics_box.rgn_txt.y + 
        (layer_h - g_lyrics_box.rgn_txt.h) / 2;

    lyrics_unformat_line(g_lyrics);
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST)); 
    /*must do set font before format line*/
    lyrics_format_line(g_lyrics, g_lyrics_box.rgn_txt.w,
        (U32)g_mscr_hd->duration, gui_get_string_width_n); 
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_parse_lyrics
* DESCRIPTION
*  parse lyrics
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_parse_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16*    media_file_path;
    U16*    meta_title = NULL;
    U16     lyric_file_path[MMI_MSCR_FILE_PATH_LEN];
    S32     nRet;
    U16     lyric_err_str_id;
    U8      lyric_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    media_file_path = mmi_inline_get_title_path(&g_mscr_hd->data_from);
    if (MMI_MSCR_DATA_FROM_FILE != g_mscr_hd->data_from)
    {
        return;
    }
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    if(!mmi_inline_is_single_play())
    {
    	nRet = mmi_medply_plst_get_current_details(&g_mscr_hd->meta_p->meta_data);
    	if (MEDPLY_PLST_NO_ERROR == nRet)
    	{
        	meta_title = g_mscr_hd->meta_p->meta_data.title;
    	}
    }
#endif
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
        case LYRICS_ERR_INVAILD_DATA:

            lyric_err_str_id = STR_ID_MEDPLY_MSCR_ERR_DATA_LYRICS_FILE;
            break;
        case LYRICS_ERR_OPEN_FILE_FAILED:

            lyric_err_str_id = STR_ID_MEDPLY_MSCR_ERR_OPEN_LYRICS_FILE;
            break;
        default:

            lyric_err_str_id = STR_ID_MEDPLY_MSCR_NO_LYRICS_FILE;
            break;
        }
        lyrics_set_err_text(g_lyrics, (kal_uint16*)GetString(lyric_err_str_id));
    }
    else
    {
        g_mscr_flag |= MMI_MSCR_UI_IS_LYRICS_READY;
    }
    g_mscr_flag |= MMI_MSCR_UI_HAS_PARSE_LYRICS; 
    g_lyrics_box.line_focus_id = LYRICS_MAX_LINES;  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_lyrics
* DESCRIPTION
*  update lyrics display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 lineID, nextID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_lyrics)
    {
        /*screen may delete by delete call back function*/
        return;
    }
    g_lyrics_box.last_time = (U16)(g_mscr_hd->playtime/MMI_MSCR_UI_UPDATE_PLAY_TIME);

    lineID = lyrics_get_line(g_lyrics, g_lyrics_box.last_time);
    if (lineID == g_lyrics_box.line_focus_id)
    {
        if (g_lyrics_box.last_time > g_lyrics->lines_p[lineID].id_time)
        {
            g_lyrics_box.time_out = 
                (U16)(g_lyrics_box.last_time - g_lyrics->lines_p[lineID].id_time);
        }
        else
        {
            g_lyrics_box.time_out = 0;
        }
        return;
    }
    
    if (lineID < LYRICS_MAX_LINES)
    {
        nextID = g_lyrics->lines_p[lineID].id_next;
    }
    else
    {
        nextID = LYRICS_MAX_LINES;
    }
    if (nextID < LYRICS_MAX_LINES)
    {
        g_lyrics_box.next_time = g_lyrics->lines_p[nextID].id_time;
    }
    else
    {
        g_lyrics_box.next_time = 
            (U32)(g_mscr_hd->duration/MMI_MSCR_UI_UPDATE_PLAY_TIME);
    }
    g_lyrics_box.curr_time      = g_lyrics->lines_p[lineID].id_time;
    g_lyrics_box.line_focus_id  = lineID;

    if (g_lyrics_box.last_time > g_lyrics->lines_p[lineID].id_time)
    {
        g_lyrics_box.time_out   = 
            (U16)(g_lyrics_box.last_time - g_lyrics->lines_p[lineID].id_time);
    }
    else
    {
        g_lyrics_box.time_out   = 0;
    }
    
    g_lyrics_box.line_id[g_lyrics_box.line_focus] = g_lyrics_box.line_focus_id;
    lineID = g_lyrics_box.line_focus_id;
    
    for (i = g_lyrics_box.line_focus-1; i >= 0; i--)
    {
        if (lineID < LYRICS_MAX_LINES)
        {
            g_lyrics_box.line_id[i] = g_lyrics->lines_p[lineID].id_prev;
            lineID = g_lyrics_box.line_id[i];
        }
        else
        {
            g_lyrics_box.line_id[i] = LYRICS_MAX_LINES;
        }
    }
    lineID = g_lyrics_box.line_focus_id;
    for (i = g_lyrics_box.line_focus+1; i <= g_lyrics_box.line_count; i++)
    {   
        if (lineID < LYRICS_MAX_LINES)
        {
            g_lyrics_box.line_id[i] = g_lyrics->lines_p[lineID].id_next;
            lineID = g_lyrics_box.line_id[i];
        }
        else
        {
            g_lyrics_box.line_id[i] = LYRICS_MAX_LINES;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_lyrics
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_lyrics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     layer_x, layer_y;
    S16     x, y, h, yOff, yBeg;
    U16     *pStr, u16Tmp, nLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if ((NULL == g_lyrics) || !(g_mscr_flag & MMI_MSCR_UI_HAS_PARSE_LYRICS) )
    {
        MMI_MSCR_ERR_TRACE(g_lyrics);
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*in full screen, use video layer to draw lyrics text*/
        gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
        /*  for video layer buffer also been used as image data temp buffer
        *   so before draw video layer, clean layer first.
        */
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_full_scr_hdl);
    }
    else
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
        mmi_mscr_draw_osd_background(MMI_FALSE);
        /*Vector font need set alpha blending layer*/
        gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);
    }
    gdi_layer_get_position(&layer_x, &layer_y);  
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST));
    
    x = g_lyrics_box.rgn_txt.x;
    y = g_lyrics_box.rgn_txt.y;  
    h = g_lyrics_box.rgn_txt.h;
    
    if (g_lyrics_box.next_time > g_lyrics_box.curr_time)
    {
        yOff = (S16)(g_lyrics_box.line_height*g_lyrics_box.time_out/
            (g_lyrics_box.next_time-g_lyrics_box.curr_time));
    }
    else
    {
        yOff = 0;
    }
    yBeg = (S16)(y-layer_y);
    
    g_lyrics_box.rgn_txt.x = (S16)(x-layer_x);
    g_lyrics_box.rgn_txt.y = (S16)(y-layer_y-yOff);
    g_lyrics_box.rgn_txt.h = g_lyrics_box.line_height;     
    
    kal_mem_cpy(&g_lyrics_box.rgn_clip, &g_lyrics_box.rgn_txt, 
        sizeof(mmi_medply_rect_struct));
    
    for (i = 0; i <= g_lyrics_box.line_count; i++)
    {
        pStr = NULL;
        if (g_lyrics_box.line_id[i] < LYRICS_MAX_LINES)
        {
            pStr = g_lyrics->lines_p[g_lyrics_box.line_id[i]].st_text;
            nLen = g_lyrics->lines_p[g_lyrics_box.line_id[i]].ln_text; 
        }
        if (NULL != pStr)
        {
            if (g_lyrics_box.rgn_txt.y < yBeg)
            {
                g_lyrics_box.rgn_clip.y = yBeg;
                g_lyrics_box.rgn_clip.h = g_lyrics_box.rgn_txt.y - yBeg + 
                    g_lyrics_box.rgn_txt.h;
            }
            else if (g_lyrics_box.rgn_txt.y+g_lyrics_box.font_height > yBeg+h)
            {
                g_lyrics_box.rgn_clip.y = g_lyrics_box.rgn_txt.y;
                g_lyrics_box.rgn_clip.h = yBeg + h - g_lyrics_box.rgn_txt.y;
            }
            else
            {
                g_lyrics_box.rgn_clip.y = g_lyrics_box.rgn_txt.y;
                g_lyrics_box.rgn_clip.h = g_lyrics_box.rgn_txt.h;
            }
            
            u16Tmp = pStr[nLen];
            pStr[nLen] = 0;   

            if (i == g_lyrics_box.line_focus)
            {
                gui_set_text_border_color(MMI_MSCR_LYRICS_FOCUS_COLOR_BG);  
                gui_set_text_color(MMI_MSCR_LYRICS_FOCUS_COLOR_FG); 

                mmi_mscr_draw_text(&g_lyrics_box.rgn_txt, &g_lyrics_box.rgn_clip, 
                    pStr, 0, MMI_MSCR_TXT_DRAW_ATOP, 1, -1);
            }
            else
            {
                gui_set_text_border_color(MMI_MSCR_LYRICS_NORMAL_COLOR_BG); 
                gui_set_text_color(MMI_MSCR_LYRICS_NORMAL_COLOR_FG); 

                mmi_mscr_draw_text(&g_lyrics_box.rgn_txt, &g_lyrics_box.rgn_clip, 
                    pStr, 0, MMI_MSCR_TXT_DRAW_ATOP, 1, -1);
            } 
            pStr[nLen] = u16Tmp;
        }
        g_lyrics_box.rgn_txt.y += g_lyrics_box.line_height;        
    }
    g_lyrics_box.rgn_txt.x = x;
    g_lyrics_box.rgn_txt.y = y;
    g_lyrics_box.rgn_txt.h = h;   
    
    gdi_pop_and_restore_alpha_blending_source_layer(); 
    gdi_layer_pop_and_restore_active();
}

#endif /*#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_spectrum_callback
* DESCRIPTION
*  draw spectrum display background
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void    mmi_mscr_draw_spectrum_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(x1, y1, x2, y2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_init_spectrum
* DESCRIPTION
*  INIT spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_init_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_INIT_SPECTRUM)
    {
        return;
    }
    
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_INIT_SPECTRUM;

    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
    mmi_mscr_draw_osd_background(MMI_FALSE);
    gdi_layer_pop_and_restore_active();

    g_mscr_hd->spectrum_p->start_x = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].x;
    g_mscr_hd->spectrum_p->start_y = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].y;
    g_mscr_hd->spectrum_p->width   = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].w;
    g_mscr_hd->spectrum_p->height  = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_SPECTRUM].h;
    
    g_mscr_hd->spectrum_p->number_of_bars  = MMI_MSCR_SPECTRUM_NUM;
    g_mscr_hd->spectrum_p->style           = STYLE_BARS;
    g_mscr_hd->spectrum_p->target_lcd      = GDI_LCD_MAIN_LCD_HANDLE;
    g_mscr_hd->spectrum_p->target_layer    = g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]; 
    g_mscr_hd->spectrum_p->draw_callback    = mmi_mscr_draw_spectrum_callback;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_play_spectrum
* DESCRIPTION
*  play spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_play_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_spectrum_blocked())
    {   
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    
        if (srv_backlight_is_lcd_sleep())
        {
            MMI_MSCR_MSG_TRACE(1);
            return;
        }
        
    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_SEEKING_WITH_KEY|MMI_MSCR_HD_HAS_SEEKING_WITH_PEN))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAY_SPECTRUM))
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PLAY_SPECTRUM;

        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        
        mdi_audio_start_calc_spectrum();
        mmi_audio_spectrum_init_display(g_mscr_hd->spectrum_p);
        mmi_audio_spectrum_start_display(g_mscr_hd->spectrum_p);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_stop_spectrum
* DESCRIPTION
*  stop spectrum display
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_stop_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PLAY_SPECTRUM)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PLAY_SPECTRUM;
        
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);

        mdi_audio_stop_calc_spectrum(); 
        mmi_audio_spectrum_stop_display(g_mscr_hd->spectrum_p);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_uninit_spectrum
* DESCRIPTION
*  clear spectrum flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_uninit_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mscr_hd->flags &= ~ MMI_MSCR_HD_HAS_INIT_SPECTRUM;
}

#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_text
* DESCRIPTION
*  draw text
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_text(mmi_medply_rect_struct* rgn_p,
                                mmi_medply_rect_struct* rgn_clip_p,
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
		if (0 != use_border && attr_w == MMI_MSCR_TXT_DRAW_ARIGHT)
		{
			str_w = trunc_w - 2;
		}
		else
		{
			str_w = trunc_w;		
		}
    }

        
    if (0 != rgn_clip_p)
    {
        gui_push_text_clip();
        gui_set_text_clip(rgn_clip_p->x-1, rgn_clip_p->y-1, 
            rgn_clip_p->x+rgn_clip_p->w+1, rgn_clip_p->y+rgn_clip_p->h+1);
    }    
    switch(attr_w)
    {
    case MMI_MSCR_TXT_DRAW_ALEFT:
        
        x = rgn_p->x;
        break;
    case MMI_MSCR_TXT_DRAW_ARIGHT:
        
        /*The Str_w may not exactly right*/
        x = rgn_p->x + (rgn_p->w/* - 1*/) - str_w;
        break;
    default:
        
        x = rgn_p->x + (rgn_p->w - str_w) / 2;
        break;
    }    
    if (r2lMMIFlag)
    {        
        x += str_w;
        if (0 != use_border)
        {
            x -= 2;
        }
    } 
    
    switch(attr_h)
    {
    case MMI_MSCR_TXT_DRAW_ATOP:
        
        y = rgn_p->y;
        break;
    case MMI_MSCR_TXT_DRAW_ABOTTOM:
        
        y = rgn_p->y + (rgn_p->h - 1) - str_h;
        break;
    default:
        
        y = rgn_p->y + (rgn_p->h - str_h) / 2;
        break;
    } 
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
*  mmi_mscr_merge_blt_rgn
* DESCRIPTION
*  merge blt region
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_merge_blt_rgn(S16 x, S16 y, S16 w, S16 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S16 x2, y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_MERGE_BLT_RGN, x,y,w,h);
	
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }
    if (g_blt_rgn.h == 0 || g_blt_rgn.w == 0)
    {
        mmi_medply_main_screen_set_clip_rgn(x, y, w, h);
        return;
    }
    x2 = g_blt_rgn.x + g_blt_rgn.w;
    y2 = g_blt_rgn.y + g_blt_rgn.h;

    if (g_blt_rgn.x > x)
    {
        g_blt_rgn.x = x;
    }
    if (g_blt_rgn.y > y)
    {
        g_blt_rgn.y = y;
    }
    if (x2 < x + w)
    {
        x2 = x + w;
    }
    if (y2 < y + h)
    {
        y2 = y + h;
    }  
    g_blt_rgn.w = x2 - g_blt_rgn.x;
    g_blt_rgn.h = y2 - g_blt_rgn.y;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_background
* DESCRIPTION
*   draw background, normal only need do this one time, when change from full screen
*   need redraw background
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    S32     offset_x, offset_y;
    
    #if !defined (__MMI_FTE_SUPPORT__)
    S32     w, h, resize_w, resize_h;
    U16     bg_file_path[MMI_MSCR_FILE_PATH_LEN];
    U8      u8Value;
    #endif
    
    U8      u8IsFileRight = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl);
    gdi_layer_get_position(&offset_x, &offset_y);
#if !defined (__MMI_FTE_SUPPORT__)
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SKIN_INDEX, 
        (void*)&u8Value);

    MMI_MSCR_MSG_TRACE(u8Value);

    if (MMI_MEDPLY_SKIN_DEFAULT != u8Value)
    {
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SKIN_PATH, 
            (void*)bg_file_path);
        gdi_image_get_dimension_file((char*)bg_file_path, &w, &h);

        if (0 < w && 0 < h && mmi_medply_setting_check_drm_display_perm((U16*)bg_file_path))
        {   
            /*To get image fit size and offset*/
            gdi_image_util_fit_bbox(GDI_LCD_WIDTH, GDI_LCD_HEIGHT,
                w, h, &offset_x, & offset_y, &resize_w, &resize_h);

            if (mmi_inline_is_resizeable_image(bg_file_path, w, h, 
                resize_w, resize_h))
            {            
                gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
                if (GDI_SUCCEED == gdi_image_draw_resized_file(offset_x, offset_y,
                        resize_w, resize_h, bg_file_path))
                {
                    u8IsFileRight = 1;
                }
            }
            else
            {
                if (w != GDI_LCD_WIDTH || h != GDI_LCD_HEIGHT)
                {
                    offset_x = (GDI_LCD_WIDTH - w) >> 1;
                    offset_y = (GDI_LCD_HEIGHT - h) >> 1;
                }
                else
                {
                    offset_x = 0;
                    offset_y = 0;
                }

		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);

                if (GDI_SUCCEED == gdi_image_draw_file(offset_x, offset_y, 
                    bg_file_path))
                {
                    u8IsFileRight = 1;
                }
            }
            
        }
    }
#endif    
    if (0 == u8IsFileRight)
    {
    #if !defined (__MMI_FTE_SUPPORT__)    
        if (NULL == current_MMI_theme->special_screen_bkg_filler)
        {   
            MMI_MSCR_ERR_TRACE(0);
            gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        }
        else
        {
            gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
                current_MMI_theme->special_screen_bkg_filler);
        }
    #else
        MMI_MSCR_ERR_TRACE(0);
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        /*FTE Key version revise*/
        /* New FTE changes - Remove background images and use theme background images */
    #if 0
        #if defined(MMI_MSCR_FTE_SLIM_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
        #endif
    #endif
        gui_draw_filled_area(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, 
            current_MMI_theme->sub_menu_bkg_filler);
    #ifndef __MMI_MAINLCD_320X240__
        /* For LQVGA no need to show softkey background filler */
        gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
    #endif
    #endif
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mi_mscr_draw_background_for_video
* DESCRIPTION
*   Clip video region to black color
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_background_for_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_medply_rect_struct*  rgn_p;
#ifdef __MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__
    S32 x, y, w, h;
#endif /*__MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    rgn_p = &g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID];
    if (rgn_p->w < 1 || rgn_p->h < 1)
    {
        return;
    }
    gdi_layer_push_and_set_active(g_mscr_hd->layer_base_hdl); 
    gdi_draw_solid_rect(rgn_p->x, rgn_p->y, 
        rgn_p->x + rgn_p->w - 1, 
        rgn_p->y + rgn_p->h - 1, 
        MMI_MSCR_LAYER_COLOR_BACKGROUND);

    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

#ifdef __MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__
    gdi_image_get_dimension_id(IMG_ID_MEDPLY_VIDEO_SHADOW_TOP, &w, &h);
    x = rgn_p->x + (rgn_p->w - w)/2;
    y = rgn_p->y - h;    
    gdi_image_draw_id(x, y, IMG_ID_MEDPLY_VIDEO_SHADOW_TOP);

    gdi_image_get_dimension_id(IMG_ID_MEDPLY_VIDEO_SHADOW_BOTTOM, &w, &h);
    x = rgn_p->x + (rgn_p->w - w)/2;
    y = rgn_p->y + rgn_p->h;    
    gdi_image_draw_id(x, y, IMG_ID_MEDPLY_VIDEO_SHADOW_BOTTOM);
#endif /*__MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__*/

    gdi_pop_and_restore_alpha_blending_source_layer(); 
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_title
* DESCRIPTION
*   draw title bar
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    //bql: revise for 6252H video playback performance issue
#if defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && !defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
    S32 h1 = 0, h2 = 0,w1 = 0, w2 = 0;
    #ifdef __MMI_CALL_INDICATOR__
        S32 w3 = 0, h3 = 0;
    #endif
    #if (MMI_MAX_SIM_NUM >= 2)
        S32 w4 = 0, h4 = 0;
    #endif
#endif /* MMI_SHOW_STATUS_ICON_IN_TITLE MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

    mmi_mscr_draw_osd_background(MMI_FALSE);
    
#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    wgui_status_icon_bar_update();      
#endif

#ifndef MMI_MSCR_FTE_20_SUPPORT
    mmi_mscr_draw_scroll(
        &g_mscr_hd->title_scroll, 
        &g_mscr_hd->flags,
        MMI_MSCR_HD_HAS_INIT_TITLE,
        MMI_MSCR_HD_HAS_MOVE_TITLE, 
        (MMI_MSCR_TXT_DRAW_ATOP << 8),
        MMI_FALSE
        );
#endif
    //gdi_layer_save_bmp_file(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP], (CHAR*)L"D:\\2.bmp");

//bql: revise for 6252H video playback performance issue
#if defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && !defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
    wgui_status_icon_bar_register_integrated_redraw(mmi_mscr_draw_title_ex);
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_SIGNAL_STRENGTH, &w1, &h1);
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_BATTERY_STRENGTH, &w2, &h2);
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SIGNAL_STRENGTH, 0, 0);
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_BATTERY_STRENGTH, 320 - w2, 0);
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, &w4, &h4);
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, w1 + STATUS_ICON_X_GAP - 1, 0);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_CALL_INDICATOR__
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_CALL_INDICATOR, &w3, &h3);
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_CALL_INDICATOR, 320 - w2 - STATUS_ICON_X_GAP - w3, 0);
    #endif /* __MMI_CALL_INDICATOR__ */
#endif

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

}

#if defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && !defined(MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_mscr_draw_title_ex
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mscr_draw_title_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 h1 = 0, h2 = 0,w1 = 0, w2 = 0;
    #ifdef __MMI_CALL_INDICATOR__
        S32 w3 = 0, h3 = 0;
    #endif
    #if (MMI_MAX_SIM_NUM >= 2)
        S32 w4 = 0, h4 = 0;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        return;
    }

    gdi_layer_lock_frame_buffer();

    wgui_status_icon_bar_register_integrated_redraw(mmi_mscr_draw_title_ex);
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_SIGNAL_STRENGTH, &w1, &h1);
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_BATTERY_STRENGTH, &w2, &h2);
#ifdef __MMI_CALL_INDICATOR__
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_CALL_INDICATOR, &w3, &h3);
#endif /* __MMI_CALL_INDICATOR__ */
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, &w4, &h4);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_TOP]);
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

    gdi_layer_push_clip(); 
    gdi_layer_set_clip(0, 0, w1, h1);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_set_clip(320 - w2, 0, 320, h2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    #ifdef __MMI_CALL_INDICATOR__
    gdi_layer_set_clip(320 - w2 - STATUS_ICON_X_GAP - w3, 0, 320 - w2 - STATUS_ICON_X_GAP, h3);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    #endif /* __MMI_CALL_INDICATOR__ */
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    gdi_layer_pop_clip();

    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SIGNAL_STRENGTH, 0, 0);
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_BATTERY_STRENGTH, 320 - w2, 0);
#ifdef __MMI_CALL_INDICATOR__
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_CALL_INDICATOR, 320 - w2 - STATUS_ICON_X_GAP - w3, 0);
#endif /* __MMI_CALL_INDICATOR__ */
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, w1 + STATUS_ICON_X_GAP - 1, 0);
#endif  /* __MMI_DUAL_SIM_MASTER__ */


    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].x, 
                           g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].y,
                           g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].w,
                           g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_TOP].h);
}
#endif /* MMI_SHOW_STATUS_ICON_IN_TITLE */

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_osd_background
* DESCRIPTION
*  draw osd layer background with background image 
* PARAMETERS
*  with_clip: [IN]if with clip region
* RETURNS
*  GDI_RESULT
 *****************************************************************************/
static S32 mmi_mscr_draw_osd_background(MMI_BOOL with_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    gdi_handle act_lhdr;
    gdi_layer_struct* act_l;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAINT_BG))
    {
        g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAINT_BG;
        g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_PAINT_BG;
        mmi_mscr_draw_background();
    }
    gdi_layer_get_active(&act_lhdr);
    act_l = (gdi_layer_struct*)act_lhdr;
    if (with_clip)
    {
        /* base layer start from 0,0 postion */
        ret = gdi_bitblt_resized(
                    g_mscr_hd->layer_base_hdl, 
                    act_l->clipx1 + act_l->offset_x, 
                    act_l->clipy1 + act_l->offset_y, 
                    act_l->clipx2 + act_l->offset_x, 
                    act_l->clipy2 + act_l->offset_y, 
                    act_l->clipx1, 
                    act_l->clipy1, 
                    act_l->clipx2, 
                    act_l->clipy2);
    }
    else
    {
        /* base layer start from 0,0 postion */
        ret = gdi_bitblt_resized(
                    g_mscr_hd->layer_base_hdl, 
                    0 + act_l->offset_x, 
                    0 + act_l->offset_y, 
                    act_l->width - 1 + act_l->offset_x, 
                    act_l->height - 1 + act_l->offset_y, 
                    0,
                    0,
                    act_l->width - 1,
                    act_l->height - 1);
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_scroll
* DESCRIPTION
*   draw scroll text
* PARAMETERS
*  scroll_p :
*  flag_init:
*  flag_scroll:        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_scroll(scrolling_text* scroll_p,
                                  U32* flags,
                                  U32 flag_init, 
                                  U32 flag_move, 
                                  U32 attr_draw, 
                                  MMI_BOOL is_scroll)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/       
    mmi_medply_rect_struct rgn;
    S32 str_w, str_h;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gui_set_text_color(scroll_p->text_color); 

    if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
    {
        gui_set_text_border_color(scroll_p->text_border_color);
    }
    gui_set_font(&scroll_p->text_font);
    
    rgn.x = scroll_p->x;
    rgn.y = scroll_p->y;
    rgn.w = scroll_p->width;
    rgn.h = scroll_p->height;
    
    if (is_scroll)
    {
        if (!(*flags & flag_init))
        {
            *flags |= flag_init;        
            gui_measure_string(scroll_p->text, &str_w, &str_h);
        
            /*Add Two Pixtel for text border*/
            /*if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
            {
                str_w += 2;
            }*/
            
            if (str_w > scroll_p->width)
            {       
                if (!(*flags & flag_move))
                {
                    *flags |= flag_move;
                    gui_scrolling_text_start(scroll_p);
                }
            }
            else
            {
                if (*flags & flag_move)
                {
                    *flags &= ~flag_move;
                    gui_scrolling_text_stop(scroll_p);                
                }
            }
        }
        if (*flags & flag_move)
        {
            /*To Show Scrolling Text*/
            gui_redraw_scrolling_text(scroll_p);
        }
        else
        {
            if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 1, -1);
            }
            else
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 0, -1);
            }
        }    
    }
    else
    {
        gui_measure_string(scroll_p->text, &str_w, &str_h);
        if (str_w > scroll_p->width)
        {
            if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)MMI_MSCR_TXT_DRAW_ALEFT, (U8)MMI_MSCR_TXT_DRAW_ATOP, 1, scroll_p->width);
            }
            else
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)MMI_MSCR_TXT_DRAW_ALEFT, (U8)MMI_MSCR_TXT_DRAW_ATOP, 0, scroll_p->width);
            }
        }
        else
        {
            if (scroll_p->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 1, -1);
            }
            else
            {
                mmi_mscr_draw_text(&rgn, &rgn, scroll_p->text, 
                    (U8)(attr_draw&0xff), (U8)((attr_draw>>8)&0xff), 0, -1);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_view
* DESCRIPTION
*   draw view region
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U8 view_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        view_content = g_mscr_hd->view_content_fullscr;
    }
    else
    {
        view_content = g_mscr_hd->view_content;
    }
    MMI_MSCR_MSG_TRACE(view_content);  

    switch(view_content)
    {    
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:    	

        mmi_mscr_draw_lyrics();
        break;
#endif    
#if defined(MMI_MEDPLY_COMP_META_WITHOUT_ARTWORK)
    case MMI_MSCR_CONTENT_ARTWORK:      
        
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
        mmi_mscr_draw_osd_background(MMI_FALSE);
        gdi_layer_pop_and_restore_active();
        mmi_mscr_draw_artwork();
        break;    
#endif
#if defined(__MMI_MEDIA_PLAYER_AUDIO__)    
    case MMI_MSCR_CONTENT_METAINFO:     
        
        mmi_mscr_draw_meta();
        break;  
#endif
    case MMI_MSCR_CONTENT_VIDEO_DEMO:
        
        MMI_MSCR_MSG_TRACE(g_mscr_hd->ani_demo_hdl);
        if (GDI_NULL_HANDLE == g_mscr_hd->ani_demo_hdl)
        {
            mmi_mscr_draw_video_demo();  
        }        
        break;  
	case MMI_MSCR_CONTENT_SPECTRUM:
           /* need to redraw background while return from interupt , since MID layer will be dirty in ful*/
           gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
           mmi_mscr_draw_osd_background(MMI_FALSE);
           gdi_layer_pop_and_restore_active();
		break;
    case MMI_MSCR_CONTENT_VIDEO_NULL: 
    case MMI_MSCR_CONTENT_VIDEO:
	case MMI_MSCR_CONTENT_NULL:
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_panel
* DESCRIPTION
*   draw panel region
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*Begin Paint*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
    //52H
    mmi_mscr_draw_osd_background(MMI_FALSE);

    gdi_layer_reset_clip();

    g_mscr_hd->is_paint_ticks = 0;

    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);
    
    /*show duration bar*/
    mmi_mscr_draw_image_box_ex(&g_mscr_ui.duration_img);
    mmi_mscr_draw_ticks();
    
    /*show volume*/
    mmi_mscr_draw_image_box_ex(&g_mscr_ui.volume_img);
    
    #if !defined (__MMI_FTE_SUPPORT__)
    /*DRAW softkeys*/    
    mmi_mscr_draw_softkey_ex(MMI_MSCR_ITEM_ID_LKEY_BTN, 
        g_mscr_hd->flags&MMI_MSCR_HD_HAS_LKEY_DOWN);
    mmi_mscr_draw_softkey_ex(MMI_MSCR_ITEM_ID_RKEY_BTN, 
        g_mscr_hd->flags&MMI_MSCR_HD_HAS_RKEY_DOWN);
    #endif
    /*paint control buttons*/
    mmi_mscr_draw_buttons();

    /*End Paint*/
    gdi_pop_and_restore_alpha_blending_source_layer();    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_artwork
* DESCRIPTION
*   draw artwork
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_artwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_medply_rect_struct  rgn;
    S32         layer_x, layer_y;
    S16         x, y;
    MMI_BOOL    img_draw_f = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);
    gdi_layer_reset_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

    gdi_layer_get_position(&layer_x, &layer_y);   
    x = (S16)(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].x - layer_x);
    y = (S16)(g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].y - layer_y);
    
    if (0 != g_mscr_hd->meta_p->meta_data.artwork.size)
    {
        rgn.x = x;
        rgn.y = y;
        rgn.w = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].w;
        rgn.h = g_mscr_ui.items_rgn[MMI_MSCR_ITEM_ID_META_IMG].h;

        img_draw_f = mmi_mscr_draw_image_mem(&rgn, 
            g_mscr_hd->artwork_mem, 
            g_mscr_hd->meta_p->meta_data.artwork.size,
            g_mscr_hd->meta_p->meta_data.artwork.mime_type, 1);
    }
    
    if (MMI_FALSE == img_draw_f)
    {
        gdi_image_draw_id(x, y, g_medply_skin.meta_def_img_id);
    }
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    /*show user rate*/
    g_mscr_ui.rates_img.fg_range = g_mscr_hd->meta_p->meta_data.user_rating*100/
        							MMI_MSCR_USER_RATE_MAX_LEVEL;
    mmi_mscr_draw_image_box_ex(&g_mscr_ui.rates_img);
#endif

    gdi_pop_and_restore_alpha_blending_source_layer();     
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_meta
* DESCRIPTION
*   draw meta
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U32 attr = (MMI_MSCR_TXT_DRAW_ATOP << 8);
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    S32 layer_offset_x,layer_offset_y;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
    mmi_mscr_draw_osd_background(MMI_FALSE);
    gdi_layer_pop_and_restore_active();

#if !defined(MMI_MEDPLY_COMP_META_WITHOUT_ARTWORK)
    mmi_mscr_draw_artwork();
#endif
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);     
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

    /*show meta text*/
#if !defined(MMI_MEDPLY_COMP_DISPLAY_META_MIDDLE) || defined (__MMI_MAINLCD_128X160__)
    attr |= MMI_MSCR_TXT_DRAW_ALEFT;
#endif
    mmi_mscr_draw_scroll(&g_mscr_hd->meta_p->title, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_TITLE,
        MMI_MSCR_META_HAS_MOVE_TITLE,
        attr,
        MMI_TRUE);
#ifdef MMI_MSCR_FTE_20_SUPPORT
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
     gdi_image_draw_id(
            g_medply_skin.line_x - layer_offset_x, 
            g_medply_skin.line_y - layer_offset_y, 
            g_medply_skin.line_img_id);
#else
    mmi_mscr_draw_scroll(&g_mscr_hd->meta_p->album, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_ALBUM,
        MMI_MSCR_META_HAS_MOVE_ALBUM,
        attr,
        MMI_TRUE);
#endif
    mmi_mscr_draw_scroll(&g_mscr_hd->meta_p->artist, &g_mscr_hd->meta_p->flags,
        MMI_MSCR_META_HAS_INIT_ARTIST,
        MMI_MSCR_META_HAS_MOVE_ARTIST,
        attr,
        MMI_TRUE);
       
    gdi_pop_and_restore_alpha_blending_source_layer(); 
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_softkey
* DESCRIPTION
*   draw artwork
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
#if !defined (__MMI_FTE_SUPPORT__)
static  void mmi_mscr_draw_softkey(U8 key_id, U32 down_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 adding = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

    mmi_mscr_draw_softkey_ex(key_id, down_f);

    gdi_pop_and_restore_alpha_blending_source_layer();    
    gdi_layer_pop_and_restore_active();
    /*
    Adding one pixel for border
    Adding one pixel for press down
    */
    if (0 != down_f)
    {
        adding++;
    }
    mmi_mscr_merge_blt_rgn((S16)(g_mscr_ui.items_rgn[key_id].x-adding), 
        (S16)(g_mscr_ui.items_rgn[key_id].y-adding),
        (S16)(g_mscr_ui.items_rgn[key_id].w+adding),
        (S16)(g_mscr_ui.items_rgn[key_id].h+adding));
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_softkey_ex
* DESCRIPTION
*   draw artwork
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_softkey_ex(U8 key_id, U32 down_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_medply_rect_struct  rgn;
    S32     layer_x, layer_y;
    U16*    str_p = NULL;
    U8      attr_w = 0, attr_h = 0;
    S32     trunc_w = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(key_id)
    {
    case MMI_MSCR_ITEM_ID_LKEY_BTN:
        
        if (0 != mmi_inline_is_single_play())
        {   /*Paint nothing in single player*/
            return;
        }
        if (0 != mmi_inline_is_background_call())
        {
            /*Paint nothing in background call*/
            return;
        }
        trunc_w = g_mscr_hd->lsk_trunc;
        str_p = (U16*)GetString(STR_GLOBAL_OPTIONS);
        
        if (0 != down_f)
        {            
            gui_set_text_color(*((current_MMI_theme)->LSK_down_text_color));    
        }
        else
        {
            gui_set_text_color(*((current_MMI_theme)->LSK_up_text_color));
        }  
#if defined(MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN)        
        attr_w = MMI_MSCR_TXT_DRAW_ALEFT;
#else
        attr_w = MMI_MSCR_TXT_DRAW_ALEFT;
        attr_h = MMI_MSCR_TXT_DRAW_ATOP;
#endif
        break;
    case MMI_MSCR_ITEM_ID_RKEY_BTN:

        trunc_w = g_mscr_hd->rsk_trunc;
        str_p = (U16*)GetString(STR_GLOBAL_BACK);
        
        if (0 != down_f)
        {            
            gui_set_text_color(*((current_MMI_theme)->LSK_down_text_color));    
        }
        else
        {
            gui_set_text_color(*((current_MMI_theme)->LSK_up_text_color));
        }
#if defined(MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN)     
        attr_w = MMI_MSCR_TXT_DRAW_ARIGHT;
#else
        attr_w = MMI_MSCR_TXT_DRAW_ALEFT;
        attr_h = MMI_MSCR_TXT_DRAW_ATOP;
#endif    
        break;
    default:
        
        ASSERT(0);
        break;
    }      
    gdi_layer_get_position(&layer_x, &layer_y);  
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    gui_set_text_border_color(*((current_MMI_theme)->softkey_text_border_color));

    rgn.x = (S16)(g_mscr_ui.items_rgn[key_id].x - layer_x);
    rgn.y = (S16)(g_mscr_ui.items_rgn[key_id].y - layer_y);
    rgn.w = g_mscr_ui.items_rgn[key_id].w;
    rgn.h = g_mscr_ui.items_rgn[key_id].h;
    /*There has one pixel for border*/
    //52H
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(rgn.x - 1, rgn.y - 1, rgn.x + rgn.w + 2, 
        rgn.y + rgn.h + 2);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();

    if (0 != down_f)
    {
        rgn.x += 1; 
        rgn.y += 1;
    }
    mmi_mscr_draw_text(&rgn, &rgn, str_p, attr_w, attr_h, 1, trunc_w);
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_image_box_ex
* DESCRIPTION
*  INIT SKIN
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_image_box_ex(mmi_medply_img_box_struct* img_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&offset_x, &offset_y);
    x1 = img_p->view_x - offset_x;
    y1 = img_p->view_y - offset_y;
    
    #ifdef MMI_MSCR_FTE_20_SUPPORT
    if(img_p->is_9slice)
    {
        gdi_image_draw_resized_id(x1, y1, img_p->resized_width, 
                img_p->resized_height, img_p->bg_img_id);
    }
    else
    #endif
    {
        gdi_image_draw_id(x1, y1, img_p->bg_img_id);
    }
    
    gdi_layer_push_clip(); 
    
    if (img_p == &g_mscr_ui.duration_img && !mmi_inline_is_seekable())
    {
        //MAUI_02830510
        /* do not draw cached mid bar, while current media is un-seekable */
    }
    else if (0 != img_p->md_range && MMI_MSCR_ERR_IMG_ID != img_p->md_img_id)
    {
        #ifdef MMI_MSCR_FTE_20_SUPPORT
        if(img_p->is_9slice)
        {
            offset_x = img_p->resized_width;
            offset_y = img_p->resized_height;
        }
        else
        #endif
        {
            gdi_image_get_dimension_id(img_p->md_img_id, &offset_x, &offset_y);
        }
        
        x2 = x1 + offset_x * img_p->md_range/100;
        y2 = y1 + offset_y;
        
        gdi_layer_set_clip(x1, y1, x2, y2);   

        #ifdef MMI_MSCR_FTE_20_SUPPORT
        gdi_image_draw_resized_id(x1, y1, img_p->resized_width, 
                img_p->resized_height, img_p->md_img_id);
        #else
        gdi_image_draw_id(x1, y1, img_p->md_img_id);
        #endif
    }
    
    if (0 != img_p->fg_range && MMI_MSCR_ERR_IMG_ID != img_p->fg_img_id)
    {
        #ifdef MMI_MSCR_FTE_20_SUPPORT
        if(img_p->is_9slice)
        {
            offset_x = img_p->resized_width;
            offset_y = img_p->resized_height;
        }
        else
        #endif
        {
            gdi_image_get_dimension_id(img_p->fg_img_id, &offset_x, &offset_y);
        }        
        
        x2 = x1 + offset_x * img_p->fg_range/100;
        y2 = y1 + offset_y;           
        
        gdi_layer_set_clip(x1, y1, x2, y2);   

        #ifdef MMI_MSCR_FTE_20_SUPPORT
        gdi_image_draw_resized_id(x1, y1, img_p->resized_width, 
                img_p->resized_height,img_p->fg_img_id);
        #else
        gdi_image_draw_id(x1, y1, img_p->fg_img_id);
        #endif
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_ticks
* DESCRIPTION
*  draw time ticks
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 i, x, y, total = 17;
    S32 num_w, col_w;
#ifndef MMI_MSCR_FTE_20_SUPPORT
    S32 bias_w;
#endif
    S32 offset_x, offset_y;
    U32 time;
    U16 h, m, s;
    U16 img_idx[17];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    time = (U32)((g_mscr_hd->playtime+500)/1000);
    h = time/ 3600;  
    if (h > 99)
    {   /*Error protected*/
        MMI_MSCR_MSG_TRACE(h);
        h = 99;
        m = 59;
        s = 59;
    }
    else
    {
        m = (time - h * 3600) / 60;
        s = (time - h * 3600 - m * 60);
    }
    /*init play time image*/
    img_idx[0] = g_mscr_ui.ticks_box.base_number_img_id + h/10;
    img_idx[1] = g_mscr_ui.ticks_box.base_number_img_id + h%10;
    img_idx[2] = g_mscr_ui.ticks_box.colon_img_id;
    
    img_idx[3] = g_mscr_ui.ticks_box.base_number_img_id + m/10;
    img_idx[4] = g_mscr_ui.ticks_box.base_number_img_id + m%10;
    img_idx[5] = g_mscr_ui.ticks_box.colon_img_id;
    
    img_idx[6] = g_mscr_ui.ticks_box.base_number_img_id + s/10;
    img_idx[7] = g_mscr_ui.ticks_box.base_number_img_id + s%10;

    img_idx[8] = g_mscr_ui.ticks_box.bias_img_id;

    time = (U32)((g_mscr_hd->duration+500) / 1000);
    h = (U16)(time / 3600);    
    if (h > 99)
    {   /*Error protected*/
        MMI_MSCR_MSG_TRACE(h);
        h = 99;
        m = 59;
        s = 59;
    }
    else
    {
        m = (time - h * 3600) / 60;
        s = (time - h * 3600 - m * 60);
    }
    /*init duration time image*/
    img_idx[9]  = g_mscr_ui.ticks_box.base_number_img_id + h/10;
    img_idx[10] = g_mscr_ui.ticks_box.base_number_img_id + h%10;
    img_idx[11] = g_mscr_ui.ticks_box.colon_img_id;

    img_idx[12] = g_mscr_ui.ticks_box.base_number_img_id + m/10;
    img_idx[13] = g_mscr_ui.ticks_box.base_number_img_id + m%10;
    img_idx[14] = g_mscr_ui.ticks_box.colon_img_id;

    img_idx[15] = g_mscr_ui.ticks_box.base_number_img_id + s/10;
    img_idx[16] = g_mscr_ui.ticks_box.base_number_img_id + s%10;
  
    
  
    gdi_layer_get_position(&offset_x, &offset_y);
    x = g_mscr_ui.ticks_box.view_x - offset_x;
    y = g_mscr_ui.ticks_box.view_y - offset_y;
    
    gdi_image_get_dimension_id(g_mscr_ui.ticks_box.base_number_img_id, &num_w, &offset_y);
    gdi_image_get_dimension_id(g_mscr_ui.ticks_box.colon_img_id, &col_w, &offset_y);
    #ifndef MMI_MSCR_FTE_20_SUPPORT
    gdi_image_get_dimension_id(g_mscr_ui.ticks_box.bias_img_id, &bias_w, &offset_y);
    #endif
    
    for (i = 0; i < total; i++)
    {
        #ifdef MMI_MSCR_FTE_20_SUPPORT
        if(i == 8)
        {
            x = g_mscr_ui.ticks_box.bias_img_id;
            continue;
        }
        #endif
        
        if (0 == g_mscr_hd->is_paint_ticks || g_mscr_hd->img_idx[i] != img_idx[i])
        {
        gdi_image_draw_id(x, y, img_idx[i]);
        }
        if (g_mscr_ui.ticks_box.colon_img_id == img_idx[i])
        {
            x += col_w;
        }
        #ifndef MMI_MSCR_FTE_20_SUPPORT
        else if (g_mscr_ui.ticks_box.bias_img_id == img_idx[i])
        {
            x += bias_w;
        }
        #endif
        else
        {
            x += num_w;
        }
        g_mscr_hd->img_idx[i] = img_idx[i];
    }
    g_mscr_hd->is_paint_ticks = 1;

}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_buttons
* DESCRIPTION
*  draw 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y;
    S32 i, x, y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gdi_layer_get_position(&layer_x, &layer_y); 
    
    for (i = 0; i < MMI_MSCR_BUTTON_ID_EX_TOTAL; i++)
    {
    #if defined (__MMI_FTE_SUPPORT__) 
        if (MMI_MEDPLY_RGN_ID_LKEY == i)
        {
            if (0 != mmi_inline_is_single_play())
            {   /*Paint nothing in single player*/
                continue;
            }
            if (0 != mmi_inline_is_background_call())
            {
                /*Paint nothing in background call*/
                continue;
            }
        }
    #endif
        
        x = g_mscr_ui.touch_btn[i].view_x - layer_x;
        y = g_mscr_ui.touch_btn[i].view_y - layer_y;
        
        if (0 != g_mscr_hd->rgn_hide_flag[i])
        {
            continue;
        }
        if (0 != g_mscr_hd->rgn_disable_flag[i])
        {
            /* New FTE changes - remove disabled buttons and use 50% transparency */
        #if !defined (__MMI_FTE_SUPPORT__)
            ASSERT(g_mscr_ui.touch_btn[i].disable_img_id != MMI_MSCR_ERR_IMG_ID);
            gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[i].disable_img_id);
        #else
            gui_draw_image_id_with_alpha_transparent(g_mscr_ui.touch_btn[i].disable_img_id, x, y, 125);
        #endif
        }
        else
        {
            #ifdef MMI_MSCR_FTE_20_SUPPORT
            if(g_mscr_ui.touch_btn[i].down_img_id == g_mscr_ui.touch_btn[i].up_img_id)
            {
                gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[i].down_img_id);
                if (i == g_mscr_hd->rgn_push_down_id)
                {
                    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
                    gdi_image_draw_id(x, y, IMG_ID_MEDPLY_FTE_HL_BTN);
                    gdi_pop_and_restore_alpha_blending_source_layer();
                }
            }
            else
            #endif
            {
                if (i == g_mscr_hd->rgn_push_down_id)
                {
                    gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[i].down_img_id);
                }
                else
                {
                    gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[i].up_img_id);
                }
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_config_button_image
* DESCRIPTION
*  config button image id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_config_button_image(U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  u8Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MEDPLY_RGN_ID_REPEAT:
        /*Single Player do not support repeater*/
        if (mmi_inline_is_single_play())
        {
            u8Value = MMI_MEDPLY_SETTINGS_REPEAT_OFF;
        }
        else
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT, 
                (void*)&u8Value);
        }        
        if (MMI_MEDPLY_SETTINGS_REPEAT_OFF == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.repeat_off_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.repeat_off_down_img_id;
        }
        else if (MMI_MEDPLY_SETTINGS_REPEAT_ONE == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.repeat_one_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.repeat_one_down_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.repeat_all_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.repeat_all_down_img_id;
        }
    	break;
    case MMI_MEDPLY_RGN_ID_SHUFFLE:

        /*Single Player do not support shuffle*/
        if (mmi_inline_is_single_play())
        {
            u8Value = MMI_MEDPLY_SETTINGS_OFF;
        }
        else
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SHUFFULE, 
                (void*)&u8Value);
        }
        if (MMI_MEDPLY_SETTINGS_OFF == u8Value)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.shuffle_off_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.shuffle_off_down_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.shuffle_on_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.shuffle_on_down_img_id;
        }
    	break;
    case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:

        if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.pause_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.pause_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.pause_disable_img_id;            
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.play_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.play_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.play_disable_img_id;
        }
        break;
		
    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
    case MMI_MEDPLY_RGN_ID_MODE:
        
        if (mmi_inline_is_3d_mode())
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.mode_3d_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.mode_3d_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.mode_2d_disable_img_id;            
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.mode_2d_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.mode_2d_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.mode_2d_disable_img_id;
        }
        break;
	#endif
		
    case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:

        if (mmi_inline_is_volume_mute())
        {
            g_mscr_ui.touch_btn[id].up_img_id   = 
                g_medply_skin.volume_spk_mute_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = 
                g_medply_skin.volume_spk_mute_down_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = 
                g_medply_skin.volume_spk_out_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = 
                g_medply_skin.volume_spk_out_down_img_id;
        }
        break;
    case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
		if (g_mscr_hd->flags & MMI_MSCR_HD_IS_VIDEO_CONTENT)
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.snap_shot_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.snap_shot_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.snap_shot_disable_img_id;
        }
        else
        {
            g_mscr_ui.touch_btn[id].up_img_id   = g_medply_skin.act_key_up_img_id;
            g_mscr_ui.touch_btn[id].down_img_id = g_medply_skin.act_key_down_img_id;
            g_mscr_ui.touch_btn[id].disable_img_id = 
                g_medply_skin.act_key_disable_img_id;
        }
		break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_button_id
* DESCRIPTION
*  draw button by id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_button_id(U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_FTE_SUPPORT__)
    if (MMI_MEDPLY_RGN_ID_LKEY == id)
    {
        if (0 != mmi_inline_is_single_play())
        {   /*Paint nothing in single player*/
            return;
        }
        if (0 != mmi_inline_is_background_call())
        {
            /*Paint nothing in background call*/
            return;
        }
    }
#endif

    if (0 != g_mscr_hd->rgn_hide_flag[id])
    {
        return;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        return;
    }
    if (id < MMI_MSCR_BUTTON_ID_BASIC_TOTAL)
    {
		mmi_mscr_draw_button_id_ex(id, g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
	}
	else
	{
		MMI_MSCR_ERR_TRACE(id);
	}
}

//#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
/*****************************************************************************
* FUNCTION
*  mmi_mscr_clean_button_id
* DESCRIPTION
*  draw button by id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_clean_button_id(U8 id, gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_rect_struct  rgn;
    S32     layer_x, layer_y;
    S32     img_w, img_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&layer_x, &layer_y);
    gdi_image_get_dimension_id(g_mscr_ui.touch_btn[id].down_img_id, &img_w, &img_h);
    
    rgn.x = (S16)(g_mscr_ui.touch_btn[id].view_x - layer_x);
    rgn.y = (S16)(g_mscr_ui.touch_btn[id].view_y - layer_y);
    rgn.w = (S16)img_w;
    rgn.h = (S16)img_h;
    
    gdi_layer_push_clip(); 
    gdi_layer_set_clip(rgn.x, rgn.y, rgn.x + rgn.w - 1, 
        rgn.y + rgn.h - 1);   
    mmi_mscr_draw_osd_background(MMI_TRUE);
    gdi_layer_pop_clip();
}
//#endif

/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_button_id
* DESCRIPTION
*  draw button by id
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_button_id_ex(U8 id, gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x, layer_y;
    S32 x, y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer); 
    
    gdi_layer_get_position(&layer_x, &layer_y);
    
    x = g_mscr_ui.touch_btn[id].view_x - layer_x;
    y = g_mscr_ui.touch_btn[id].view_y - layer_y;  
    
    if (0 != g_mscr_hd->rgn_disable_flag[id])
    {
        #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
        if(MMI_MEDPLY_RGN_ID_MODE == id)
        {
            mmi_mscr_clean_button_id(id, layer);
        }
        else
        #endif
        {
        #if !defined (__MMI_FTE_SUPPORT__)
            gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[id].disable_img_id);
        #else
            mmi_mscr_clean_button_id(id, layer);
            gdi_layer_reset_clip();
            gui_draw_image_id_with_alpha_transparent(g_mscr_ui.touch_btn[id].disable_img_id, x, y, 125);
        #endif
        }
    }
    else
    {
        #ifdef MMI_MSCR_FTE_20_SUPPORT
        if(g_mscr_ui.touch_btn[id].down_img_id == g_mscr_ui.touch_btn[id].up_img_id)
        {
            mmi_mscr_clean_button_id(id, layer);
            gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[id].down_img_id);
            if (id == g_mscr_hd->rgn_push_down_id)
            {
                gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
                gdi_image_draw_id(x, y, IMG_ID_MEDPLY_FTE_HL_BTN);
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
        }
        else
        #endif
        {
            if (g_mscr_hd->rgn_push_down_id == id)
            {
                gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[id].down_img_id);
            }
            else
            {
                gdi_image_draw_id(x, y, g_mscr_ui.touch_btn[id].up_img_id);
            }
        }
    }    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_image_mem
* DESCRIPTION
*  draw image from memory
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_BOOL mmi_mscr_draw_image_mem(mmi_medply_rect_struct* rgn_p, 
                                         U8* img_p, U32 img_size,
                                         U8 img_type, U8 resize_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, resize_w, resize_h; 
    GDI_RESULT  ret_val;
    U8  gdi_img_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch(img_type)
    {
    case META_TAG_IMG_PNG :     gdi_img_type = GDI_IMAGE_TYPE_PNG; break;
    case META_TAG_IMG_JPG:      gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
    case META_TAG_IMG_JPEG:     gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
    case META_TAG_IMG_GIF:      gdi_img_type = GDI_IMAGE_TYPE_GIF; break;
    case META_TAG_IMG_BMP:      gdi_img_type = GDI_IMAGE_TYPE_BMP; break;

    default:                    return  MMI_FALSE;
    }
    if (0 != resize_f)
    {
        ret_val = gdi_image_get_dimension_mem(gdi_img_type, img_p, img_size,
            &w, &h);
        if (GDI_SUCCEED != ret_val)
        {
            return  MMI_FALSE;
        }
        /*To get image fit size and offset*/
        gdi_image_util_fit_bbox(rgn_p->w, rgn_p->h,
            w, h, &x, & y, &resize_w, &resize_h);

        ret_val = gdi_image_draw_resized_mem(rgn_p->x + x, 
            rgn_p->y + y, resize_w, resize_h, img_p, gdi_img_type, img_size);   
    }
    else
    {
        ret_val = gdi_image_draw_mem(rgn_p->x, rgn_p->y, img_p, gdi_img_type,
            img_size);
    }
    if (GDI_SUCCEED != ret_val)
    {
        return  MMI_FALSE;
    }
    return  MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_image_box
* DESCRIPTION
*  draw progress
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_image_box(mmi_medply_img_box_struct* img_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*Begin Paint*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
    gdi_layer_reset_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);
      
    /*show image box*/
    mmi_mscr_draw_image_box_ex(img_p);
    
    /*End Paint*/
    gdi_pop_and_restore_alpha_blending_source_layer();    
    gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_mscr_is_pt_in_rgn
* DESCRIPTION
*  check whether touch point in region 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_BOOL mmi_mscr_is_pt_in_rgn(mmi_pen_point_struct* pos_p, 
                                       mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if ((pos_p->x >= rgn_p->x) && (pos_p->x <= rgn_p->x+rgn_p->w) &&
        (pos_p->y >= rgn_p->y) && (pos_p->y <= rgn_p->y+rgn_p->h))
    {
        return  MMI_TRUE;
    }
    return  MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_get_pt_range
* DESCRIPTION
*  check whether touch point in region 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_mscr_get_pt_range(S16 x, mmi_medply_rect_struct* rgn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8 range;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x < rgn_p->x)
    {
        range = 0;
    }
    else if (x >= rgn_p->x + rgn_p->w)
    {
        range = 100;
    }
    else
    {
        range = (x-rgn_p->x)*100/rgn_p->w;
    }
    return  range;
}
#endif  /*#ifdef __MMI_TOUCH_SCREEN__*/


/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_begin
* DESCRIPTION
*  begin seek 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_seek_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U64 dst_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Stop playing first*/
    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_stop_playing();
    }  

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_SEEKING_TIMER;
        gui_cancel_timer(mmi_mscr_update_seeking);
    }
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();
    g_mscr_hd->duration = mmi_inline_get_duration();
    g_mscr_hd->seektime = g_mscr_hd->playtime;
    dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        if (g_mscr_ui.duration_img.md_range < 100)
        {
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_TIMER;
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
        }
        if (g_mscr_hd->playtime != dst_time)
        {
            if (g_mscr_hd->seek_duration_dst_range <= g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = g_mscr_hd->seek_duration_dst_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            else if (g_mscr_ui.duration_img.fg_range > g_mscr_ui.duration_img.md_range)
            {
                /*  if g_mscr_ui.duration_img.fg_range == g_mscr_ui.duration_img.md_range
                *   do not update play tim
                */
                g_mscr_ui.duration_img.fg_range = g_mscr_ui.duration_img.md_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            mmi_mscr_show_moving(1);
        }
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        if ((g_mscr_hd->playtime != dst_time) ||
            (g_mscr_ui.duration_img.md_range < 100))
        {   
            g_mscr_hd->flags |= MMI_MSCR_HD_HAS_SEEKING_TIMER;
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_update
* DESCRIPTION
*  begin seek 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_seek_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U64 dst_time, play_time;
    U32 step;
    S32 w, h;
    MMI_BOOL isforward = MMI_TRUE;
    U8  fg_range, md_range, update_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    md_range = g_mscr_ui.duration_img.md_range;
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent();
    /*For duration may change in build cache*/
    g_mscr_hd->duration = mmi_inline_get_duration();

    MMI_MSCR_MSG_TRACE(g_mscr_hd->duration);
    
    dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;
    update_content = 0;/*default: not to update content in seeking*/
    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {       
        if (g_mscr_hd->playtime != dst_time)
        {            
            if (g_mscr_hd->seek_duration_dst_range <= g_mscr_ui.duration_img.md_range)
            {
                update_content = 1;
                g_mscr_ui.duration_img.fg_range = g_mscr_hd->seek_duration_dst_range;
                g_mscr_hd->playtime = g_mscr_ui.duration_img.fg_range*g_mscr_hd->duration/100;
            }
            else if (g_mscr_ui.duration_img.fg_range != g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = g_mscr_ui.duration_img.md_range;
				/*MAUI_01835043, can get exact playtime*/
				g_mscr_hd->playtime = g_mscr_hd->cachetime;
                if (g_mscr_hd->playtime - g_mscr_hd->seektime >= MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                {
                	MMI_MSCR_MSG_TRACE(g_mscr_ui.duration_img.md_range);
                    g_mscr_hd->seektime = g_mscr_hd->playtime;
                    update_content = 1;
                }
            }            
            mmi_mscr_show_moving(update_content);
        }
        else if (md_range < 100)
        {
            /*To speed draw image to layer*/
            mmi_mscr_draw_image_box(&g_mscr_ui.duration_img);            
            #ifdef MMI_MSCR_FTE_20_SUPPORT
            w = g_medply_skin.duration_bar_rgn_w;
            h = g_medply_skin.duration_bar_rgn_h;
            #else
            gdi_image_get_dimension_id(g_mscr_ui.duration_img.bg_img_id, &w, &h);            
            #endif
            mmi_mscr_merge_blt_rgn(g_mscr_ui.duration_img.view_x,
                g_mscr_ui.duration_img.view_y, (S16)w, (S16)h);
            
            mmi_medply_main_screen_blt();
        }
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        if (g_mscr_hd->playtime != dst_time) 
        {   
            play_time = g_mscr_hd->playtime;
            step = mmi_inline_get_cache_step();
            if (play_time < dst_time)
            {
            		isforward = MMI_TRUE;
                if (play_time + step < dst_time)
                {
                    play_time += step;
                }
                else
                {
                    play_time = dst_time;
                }
            }
            else if (play_time > dst_time)
            {
            		isforward = MMI_FALSE;
                if (play_time > step)
                {
                    play_time -= step;
                }
                else
                {
                    play_time = 0;
                }
            }          
            if (g_mscr_hd->duration > 0)
            {
                fg_range = (U8)(play_time*100/g_mscr_hd->duration);
            }
            else
            {
                MMI_MSCR_ERR_TRACE(g_mscr_hd->duration);
                fg_range = 0;
            } 
            if (fg_range <= g_mscr_ui.duration_img.md_range)
            {
                g_mscr_ui.duration_img.fg_range = fg_range;
                g_mscr_hd->playtime = play_time;
                if (g_mscr_hd->playtime > g_mscr_hd->seektime)
                {
                    if (g_mscr_hd->playtime - g_mscr_hd->seektime >= 
                        MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                    {
                        g_mscr_hd->seektime = g_mscr_hd->playtime;
                        update_content = 1;
                    }
                }
                else
                {
                    if (g_mscr_hd->seektime - g_mscr_hd->playtime >= 
                        MMI_MSCR_UI_UPDATE_SEEK_CONTENT)
                    {
                        g_mscr_hd->seektime = g_mscr_hd->playtime;
                        update_content = 1;
                    }
                }
                if (g_mscr_hd->playtime == dst_time)
                {
                    update_content = 1;
                }
				/*MAUI_01835043, can get exact playtime*/
				if ((fg_range == g_mscr_ui.duration_img.md_range) & isforward)
				{
				    if (g_mscr_hd->cachetime >= g_mscr_hd->playtime)
                    {
                        g_mscr_hd->playtime = g_mscr_hd->cachetime;
					    if (g_mscr_hd->seektime != g_mscr_hd->playtime)
					    {
						    MMI_MSCR_MSG_TRACE(g_mscr_ui.duration_img.md_range);
						    g_mscr_hd->seektime = g_mscr_hd->playtime;
                            update_content = 1;                            
					    }
                    }
                    else
                    {
                        MMI_MSCR_ERR_TRACE(g_mscr_hd->playtime);
                        MMI_MSCR_ERR_TRACE(g_mscr_hd->cachetime);
                        g_mscr_hd->playtime = g_mscr_hd->cachetime;
                    }
				}
                mmi_mscr_show_moving(update_content);
            }
        }
        else if (md_range < 100)
        {
            /*To speed draw image to layer*/
            mmi_mscr_draw_image_box(&g_mscr_ui.duration_img);            
            #ifdef MMI_MSCR_FTE_20_SUPPORT
            w = g_medply_skin.duration_bar_rgn_w;
            h = g_medply_skin.duration_bar_rgn_h;
            #else
            gdi_image_get_dimension_id(g_mscr_ui.duration_img.bg_img_id, &w, &h);            
            #endif
            mmi_mscr_merge_blt_rgn(g_mscr_ui.duration_img.view_x,
                g_mscr_ui.duration_img.view_y, (S16)w, (S16)h);

            mmi_medply_main_screen_blt();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_seek_end
* DESCRIPTION
*  seek end 
* PARAMETERS
*  is_resume        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_seek_end(U8 is_resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U32 has_begin = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        has_begin |= MMI_MSCR_HD_HAS_SEEKING_WITH_KEY;
    }
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        has_begin |= MMI_MSCR_HD_HAS_SEEKING_WITH_PEN;
    }
    if (0 == has_begin)
    {
        MMI_MSCR_ERR_TRACE(has_begin);
        return;
    }
    g_mscr_hd->flags &= ~has_begin;

    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_TIMER)
    {
        g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_SEEKING_TIMER;
        gui_cancel_timer(mmi_mscr_update_seeking);
    }
    mmi_inline_set_playtime(g_mscr_hd->playtime);

    if (0 != is_resume && MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_start_playing();
    }    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_seeking
* DESCRIPTION
*  update seek timer 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_seeking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U64 dst_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_PEN)
    {
        if (g_mscr_ui.duration_img.md_range < 100)
        {
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);

            mmi_mscr_seek_update();
        }        
    }
    else if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_SEEKING_WITH_KEY)
    {
        dst_time = g_mscr_hd->seek_duration_dst_range*g_mscr_hd->duration/100;

        if ((g_mscr_hd->playtime != dst_time) ||
            (g_mscr_ui.duration_img.md_range < 100))
        {   
            gui_start_timer(MMI_MSCR_UI_UPDATE_SEEK_TIME, mmi_mscr_update_seeking);
            mmi_mscr_seek_update();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_show_moving
* DESCRIPTION
*  show seeking 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_show_moving(U8 update_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    S32 layer_x, layer_y, layer_w, layer_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Begin Paint*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))    
    {
        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
        gdi_layer_reset_clip();
        gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);

        /*show duration bar*/
        mmi_mscr_draw_image_box_ex(&g_mscr_ui.duration_img);
        mmi_mscr_draw_ticks();
        
        /*End Paint*/
        gdi_pop_and_restore_alpha_blending_source_layer();    
        gdi_layer_pop_and_restore_active();
        
        mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].x,
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].y, 
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].w, 
            g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].h);
    }  

    if ((0 != update_content) && 
        (MMI_MSCR_CONTENT_LYRICS == g_mscr_hd->view_content))
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
        }
        else
        {
            gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]);           
        }
        gdi_layer_get_position(&layer_x, &layer_y);  
        gdi_layer_get_dimension(&layer_w, &layer_h);
        gdi_layer_pop_and_restore_active();
        
        mmi_mscr_merge_blt_rgn((S16)layer_x, (S16)layer_y,
            (S16)layer_w, (S16)layer_h);
    
        
#if defined(__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__)    
            mmi_mscr_update_lyrics();
            mmi_mscr_draw_lyrics();
#endif  /*__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__*/     
    }
    mmi_medply_main_screen_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_draw_duration
* DESCRIPTION
*  update duration image and ticks
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_draw_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        /*do not update anything in full screen status*/
        return;
    }
    /*Begin Paint*/
    gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_CTL]);
    gdi_layer_reset_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_mscr_hd->layer_base_hdl);
    
    /*show image box*/
    mmi_mscr_draw_image_box_ex(&g_mscr_ui.duration_img);
    mmi_mscr_draw_ticks();
    
    /*End Paint*/
    gdi_pop_and_restore_alpha_blending_source_layer();    
    gdi_layer_pop_and_restore_active();
    
    mmi_mscr_merge_blt_rgn(g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].x,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].y,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].w,
        g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_CTL].h);
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_redraw_button
* DESCRIPTION
*  update duration image 
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_redraw_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_CONTROL_BUTTONS))
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_STOP);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PREV);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_NEXT);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    }
    else if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PAUSE))
    {
        /* only stop enabled*/
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 1;
        mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    }
    else
    {
        g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PLAY_PAUSE] = 0;
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_STOP] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_STOP);
        }
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    }
    //for CMCC
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PREV_NEXT))
    {
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_PREV] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_PREV);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PREV);
        } 
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_NEXT] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_NEXT);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_NEXT);
        }
    }
        
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_SNAPSHOT))
    {
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY);
        }
    }
    else
    {
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY);
        }
    }
    if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_ZOOM))
    {
        if (0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 1;
            mmi_inline_reset_button_up(MMI_MEDPLY_RGN_ID_ZOOM);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_ZOOM);
        }
    }   
    else
    {
        if (1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_ZOOM] = 0;
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_ZOOM);
        }
    }

    #ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
	if (mmi_inline_is_button_disable(MMI_MEDPLY_DISABLED_PLAY_MODE))
    {
        if(0 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 1;
            mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_MODE);
        }
    } 
	else
    {
        if(1 == g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE])
        {
            g_mscr_hd->rgn_disable_flag[MMI_MEDPLY_RGN_ID_MODE] = 0;
            mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_MODE);
            mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_MODE);
        }
    }
    #endif
	
    mmi_mscr_config_button_image(MMI_MEDPLY_RGN_ID_PLAY_PAUSE); 
    mmi_mscr_draw_button_id(MMI_MEDPLY_RGN_ID_PLAY_PAUSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_update_duration
* DESCRIPTION
*  update duration time and duration image
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mscr_hd->duration = mmi_inline_get_duration();

    if (g_mscr_hd->flags & 
        (MMI_MSCR_HD_HAS_SEEKING_WITH_PEN|MMI_MSCR_HD_HAS_SEEKING_WITH_KEY))
    {   /*Do not update playtime in Seek status*/
        return;
    }
    g_mscr_hd->playtime = mmi_inline_get_playtime();
    
    if (g_mscr_hd->duration > 0)
    {
        g_mscr_ui.duration_img.fg_range = 
            (U8)(g_mscr_hd->playtime*100/g_mscr_hd->duration);
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->duration);
        g_mscr_ui.duration_img.fg_range = 0;
    }    
    /*must do get cache after play time updated*/
    g_mscr_ui.duration_img.md_range = (U8)mmi_inline_get_cache_percent(); 
    
    /*Init Duration Bar background image*/
    if (0 != mmi_inline_is_duration_seek_able())
    {
        g_mscr_ui.duration_img.bg_img_id = g_medply_skin.duration_bar_bg_img_id;
    }
    else
    {
        g_mscr_ui.duration_img.bg_img_id = 
            g_medply_skin.duration_bar_bg_disable_img_id;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_pause
* DESCRIPTION
*  pause timer and scroll text for full screen play
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL)
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAUSE_ALL;
	g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAUSE_VIEW;

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_MOVE_TITLE)
        {
            gui_scrolling_text_stop(&g_mscr_hd->title_scroll);             
        }
        if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
        {
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->title);
            }
            #ifndef MMI_MSCR_FTE_20_SUPPORT
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->album);
            }
            #endif
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
            {
                gui_scrolling_text_stop(&g_mscr_hd->meta_p->artist);
            }
        }
    }
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);

    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_stop_playing();
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_resume
* DESCRIPTION
*  resume timer and scroll text for back from full screen play
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_ALL))
    {
        MMI_MSCR_MSG_TRACE(g_mscr_hd->flags);
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAUSE_ALL;
	g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAUSE_VIEW;

    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN))
    {
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_MOVE_TITLE)
        {
            gui_scrolling_text_start(&g_mscr_hd->title_scroll);             
        }
        if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
        {
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->title);
            }
            #ifndef MMI_MSCR_FTE_20_SUPPORT
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->album);
            }
            #endif
            if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
            {
                gui_scrolling_text_start(&g_mscr_hd->meta_p->artist);
            }
        }
    }
    MMI_MSCR_MSG_TRACE(g_mscr_hd->ui_status);

    if (MMI_MEDPLY_STATUS_PLAYING == g_mscr_hd->ui_status)
    {
        mmi_mscr_start_playing();
    } 
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_pause_view
* DESCRIPTION
*  pause timer and scroll text for in view layer
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_pause_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_VIEW)
    {
        return;
    }
    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_PAUSE_VIEW;    

    if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
    {
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
        {
            gui_scrolling_text_stop(&g_mscr_hd->meta_p->title);
        }
        #ifndef MMI_MSCR_FTE_20_SUPPORT
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
        {
            gui_scrolling_text_stop(&g_mscr_hd->meta_p->album);
        }
        #endif
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
        {
            gui_scrolling_text_stop(&g_mscr_hd->meta_p->artist);
        }
    }  
    mmi_medply_main_screen_stop_spectrum(); 
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_resume_view
* DESCRIPTION
*  resume timer and scroll text in view layer
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_resume_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_mscr_hd->flags & MMI_MSCR_HD_HAS_PAUSE_VIEW))
    {
        return;
    }
    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_PAUSE_VIEW;

    if (MMI_MSCR_CONTENT_METAINFO == g_mscr_hd->view_content)
    {
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_TITLE)
        {
            gui_scrolling_text_start(&g_mscr_hd->meta_p->title);
        }
        #ifndef MMI_MSCR_FTE_20_SUPPORT
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ALBUM)
        {
            gui_scrolling_text_start(&g_mscr_hd->meta_p->album);
        }
        #endif
        if (g_mscr_hd->meta_p->flags & MMI_MSCR_META_HAS_MOVE_ARTIST)
        {
            gui_scrolling_text_start(&g_mscr_hd->meta_p->artist);
        }
    }   
    mmi_mscr_draw_view();
    mmi_medply_main_screen_play_spectrum();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_resize_video_layer
* DESCRIPTION
*  reset video layer for video play
* PARAMETERS
*  void     
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_resize_video_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    S32     offset_x, offset_y, x, y, video_w, video_h;
    S32     resize_w, resize_h, layer_w, layer_h;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
    {
        mmi_mscr_update_video_content();
        if (MMI_MSCR_CONTENT_VIDEO != g_mscr_hd->view_content)
        {
            MMI_MSCR_ERR_TRACE(g_mscr_hd->view_content);
            return;
        }
    }

    #ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    /*To get image fit size and offset*/    
    if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
    {
        video_w = g_mscr_hd->video_p->video_width;
        video_h = g_mscr_hd->video_p->video_height;
        x = 0;
        y = 0;

        layer_w = g_mscr_hd->layer_full_scr_w;
        layer_h = g_mscr_hd->layer_full_scr_h;
    }
    else
    {
        video_w = g_mscr_hd->video_p->video_width;
        video_h = g_mscr_hd->video_p->video_height;

        x = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].x;
        y = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].y;

        layer_w = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].w;
        layer_h = g_mscr_ui.layer_rgn[MMI_MSCR_LAYER_ID_MID].h;
    }
    MMI_MSCR_MSG_TRACE(layer_w);
    MMI_MSCR_MSG_TRACE(layer_h);
    
    gdi_image_util_fit_bbox(
            ((layer_w > MDI_VDOPLY_MAX_HW_LAYER_SIZE) ? MDI_VDOPLY_MAX_HW_LAYER_SIZE : layer_w),
            ((layer_h > MDI_VDOPLY_MAX_HW_LAYER_SIZE) ? MDI_VDOPLY_MAX_HW_LAYER_SIZE : layer_h),
        video_w, video_h, &offset_x, &offset_y, &resize_w, &resize_h);

    MMI_MSCR_MSG_TRACE(resize_w);
    MMI_MSCR_MSG_TRACE(resize_h);

		/* 
		* MT6253 HW resizer has some limitation, frame buffer size:
		* (1) width % 2 = 0
		* (2) height % 2 = 0
		*/ 
		if (resize_w == 1 || resize_h == 1)
		{
			if (1 == resize_w)
			{
				resize_w++;
				MMI_MSCR_ERR_TRACE(resize_w);
			}
			if (1 == resize_h)
			{
				resize_h++;
				MMI_MSCR_ERR_TRACE(resize_w);
			}
		}
		if (resize_w % 2 != 0)
		{
			/* shrink 1 pixel */
			resize_w --;
			MMI_MSCR_MSG_TRACE(resize_w);
		}
		if (resize_h % 2 != 0)
		{
			/* shirink 1 pixel */
			resize_h --;
			MMI_MSCR_MSG_TRACE(resize_h);
		}
		/* need re-calculate offset due to w,h coordinate */
		if (layer_w >= resize_w)
		{
			offset_x = (layer_w - resize_w) / 2 ;
			MMI_MSCR_MSG_TRACE(offset_x);
		}
		if (layer_h >= resize_h)
		{
			offset_y = (layer_h - resize_h) / 2 ;
			MMI_MSCR_MSG_TRACE(offset_y);
		}
		
        if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_FULL_SCREEN)
        {
            g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
        }
        else
        {
            g_mscr_hd->video_flags |= MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
        }
        gdi_layer_push_and_set_active(g_mscr_hd->video_p->layer_hdl);
        gdi_layer_resize(resize_w, resize_h); 
        gdi_layer_set_position(x + offset_x, y + offset_y);
        
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND); 
        gdi_layer_pop_and_restore_active();

        /*do set blt layer after video layer resize*/
        mmi_mscr_config_layer_blt();
        #endif
}

/*****************************************************************************
* FUNCTION
*   mmi_mscr_restore_full_screen
* DESCRIPTION
*   init video region
* PARAMETERS
*           
* RETURNS
*  void
*****************************************************************************/
static  void mmi_mscr_restore_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_MSCR_MSG_TRACE(g_mscr_hd->video_flags);
	if (g_mscr_hd->video_flags & MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER)
	{
		g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;

		gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
	    gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
    	gdi_layer_set_position(0,0);
    	gdi_layer_pop_and_restore_active();  

		/*reconfig blt layer after resize*/
		mmi_mscr_config_layer_blt();
		MMI_MSCR_MSG_TRACE(1);
	}
    
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_prepare_full_scr
* DESCRIPTION
*  prepare full screen UI
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_prepare_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_PREPARE_FULL_SCREEN);
	
    /*Change to Full Screen, pause main screen first*/
    mmi_mscr_pause();

    //HAL
    media_type = mmi_inline_get_media_type();
    if(media_type != MEDPLY_TYPE_AUDIO && media_type != MEDPLY_TYPE_PDL_AUDIO)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_TRUE);
    }

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    /*Icon Bar default is show, need hide it when change to full screen*/
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif 

    g_mscr_hd->flags |= MMI_MSCR_HD_HAS_FULL_SCREEN;
    
    	/*clear */
		if (g_mscr_hd->flags & MMI_MSCR_HD_HAS_OSD_IMAGE)
		{
            gdi_layer_push_and_set_active(g_mscr_hd->layer_osd_hdl);
    	gdi_layer_clear(MMI_MSCR_LAYER_COLOR_TRANSPARENT);
    	gdi_layer_pop_and_restore_active();  
		}
	
    gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
	if (MMI_MSCR_CONTENT_VIDEO == g_mscr_hd->view_content_fullscr)
	{
		g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_FULLAYER;
		/*Clear Full screen to background color, For memory has been same used with Normal screen*/
		gdi_layer_resize(g_mscr_hd->layer_full_scr_w, g_mscr_hd->layer_full_scr_h);
		gdi_layer_set_position(0, 0);
	}
    gdi_layer_pop_and_restore_active();
	mmi_mscr_config_layer_blt();

    switch(g_mscr_hd->view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_config_lyrics();
        mmi_mscr_update_lyrics();
        break;        
#endif   
	case MMI_MSCR_CONTENT_NULL:	
	case MMI_MSCR_CONTENT_VIDEO_DEMO:
		gdi_layer_push_and_set_active(g_mscr_hd->layer_full_scr_hdl);
		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
		gdi_layer_pop_and_restore_active();
		break;
		
	case MMI_MSCR_CONTENT_VIDEO:	
	case MMI_MSCR_CONTENT_VIDEO_NULL:
		gdi_layer_push_and_set_active(g_mscr_hd->layer_video_hw_hdl);
		gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
		gdi_layer_pop_and_restore_active();
		break;
		
    default:
        break;
    }
    mmi_mscr_resume();
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_unprepare_full_scr
* DESCRIPTION
*  restore normal screen ui
* PARAMETERS
*  void       
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_mscr_unprepare_full_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MSCR_UNPREPARE_FULL_SCREEN);
	
    /*Change from Full Screen, pause main screen first*/
    mmi_mscr_pause();
    //HAL
    media_type = mmi_inline_get_media_type();
    if(media_type != MEDPLY_TYPE_AUDIO && media_type != MEDPLY_TYPE_PDL_AUDIO)
    {
        mmi_mscr_prepare_hw_video_layer(MMI_FALSE);
    }

#if defined(MMI_MEDPLY_COMP_ICONBAR_SHOW)
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif

    g_mscr_hd->flags &= ~MMI_MSCR_HD_HAS_FULL_SCREEN;
    mmi_mscr_update_duration();

    switch(g_mscr_hd->view_content)
    {
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__    
    case MMI_MSCR_CONTENT_LYRICS:
        
        mmi_mscr_config_lyrics();
        mmi_mscr_update_lyrics();
        break;        
#endif       
    case MMI_MSCR_CONTENT_SPECTRUM: 
		gdi_layer_lock_frame_buffer();
		g_mscr_hd->flags |= MMI_MSCR_HD_HAS_LOCK_FRAME_BUFFER;
    case MMI_MSCR_CONTENT_NULL:

        gdi_layer_push_and_set_active(g_mscr_hd->layer_hdl[MMI_MSCR_LAYER_ID_MID]); 
        gdi_layer_clear(MMI_MSCR_LAYER_COLOR_BACKGROUND);
        gdi_layer_pop_and_restore_active();
        break;
    case MMI_MSCR_CONTENT_VIDEO:
    case MMI_MSCR_CONTENT_VIDEO_NULL:
        g_mscr_hd->video_flags &= ~MMI_MSCR_HD_VID_HAS_RESIZE_LAYER;
        break;
    default:
        break;
    }
    mmi_mscr_resume();
}


#ifndef MMI_MSCR_FTE_20_SUPPORT
#ifndef MMI_MEDPLY_COMP_ALL_EXT_FILE_NAME_SHOW
/*****************************************************************************
* FUNCTION
*  mmi_mscr_is_protect_file
* DESCRIPTION
*  check the file ext, whether it's protect files
* PARAMETERS
*  filepath:    file full path        
* RETURNS
*  void
 *****************************************************************************/
static  U8  mmi_mscr_is_protect_file(U16* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U32 i, u32Count;
    U16 u16FileFormat;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u16FileFormat = med_get_media_type(filepath);
    if (MED_TYPE_NONE == (med_type_enum)u16FileFormat)
    {
        return  0;
    }
    u32Count = sizeof(g_mscr_protect_ext)/sizeof(U16);

    for (i = 0; i < u32Count; i++)
    {
        if (u16FileFormat == g_mscr_protect_ext[i])
        {
            return  1;
        }
    }
    return  0;
}
#endif
#endif


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_duration
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U64 mmi_inline_get_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(g_single.duration);
        return  g_single.duration;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE(g_medply.duration);
        return  g_medply.duration;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_playtime
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U64 mmi_inline_get_playtime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(g_single.current_time);
        return  g_single.current_time;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE(g_medply.current_time);
        return  g_medply.current_time;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_playtime
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_inline_set_playtime(U64 playtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_MSCR_MSG_TRACE(playtime);
	
    if (mmi_inline_is_single_play())
    {
        g_single.current_time = playtime;
    }
    else
    {
        g_medply.current_time = playtime;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_cache_percent
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_get_cache_percent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
	U8 u8CachePer;
	U64 u64Duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	u64Duration = mmi_inline_get_duration();
	
	if (mmi_medply_get_build_cache_process(&g_mscr_hd->cachetime))
	{
		if (u64Duration != 0)
		{
			u8CachePer = g_mscr_hd->cachetime * 100 / u64Duration;
		}
		else
		{
			MMI_MSCR_ERR_TRACE(g_mscr_hd->cachetime);
			u8CachePer = 0;
		}
	}
	else
	{
		u8CachePer = 100;
		g_mscr_hd->cachetime = u64Duration;
		MMI_MSCR_MSG_TRACE(u64Duration);
	}

	if (0 == mmi_inline_is_duration_seek_able())
	{
		MMI_MSCR_MSG_TRACE(u8CachePer);
		return  u8CachePer;
	}
	/*Cache less then play percent, use play time*/
    if (u8CachePer < g_mscr_ui.duration_img.fg_range)
    {
        u8CachePer = g_mscr_ui.duration_img.fg_range;
    }
    /*Cache less then old cache percent, use old percent*/
    if (u8CachePer < g_mscr_ui.duration_img.md_range)
    {
        u8CachePer = g_mscr_ui.duration_img.md_range;
    }
    /*  Sync play time to cache time, should do in driver or in ctrl module,
    *   not in main screen
    */
    MMI_MSCR_MSG_TRACE(u8CachePer);
    return  u8CachePer;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_cache_step
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U32 mmi_inline_get_cache_step(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.progress_speed);

        return  g_single.progress_speed;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.progress_speed);

        return  g_medply.progress_speed;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_media_type
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U32 mmi_inline_get_media_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(g_single.media_type);
        return  g_single.media_type;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE( g_medply.media_type);
        return  g_medply.media_type;
    }
}

#ifdef __MMI_VIDEO_STREAM__

/*****************************************************************************
* FUNCTION
*  mmi_inline_get_media_format
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U32 mmi_inline_get_media_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(MEDPLY_FORMAT_TOTAL);
        /*g_single.; without media_format like g_medply*/
        return  MEDPLY_FORMAT_TOTAL;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE(g_medply.media_format);
        return  g_medply.media_format;
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_inline_get_video_track
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U32 mmi_inline_get_video_track(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER_VIDEO__)
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.track);

        return  g_single.track;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.track);

        return  g_medply.track;
    }
#else
    return 0;
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_title_path
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U16*    mmi_inline_get_title_path(U8* data_from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        /*stream title*/
        if (0 != g_single.specified_title[0] && 
            0 != g_single.specified_title[1])
        {
            *data_from = MMI_MSCR_DATA_FROM_STREAM;
            
            return  (U16*)g_single.specified_title;
        }

        if (0 != g_single.filefullpath[0])
        {
            if (0 != mmi_inline_is_stream_url())
            {
                *data_from = MMI_MSCR_DATA_FROM_STREAM;
            }
            else
            {
                *data_from = MMI_MSCR_DATA_FROM_FILE;
            }
            return  (U16*)g_single.filefullpath;
        }
    }
    else
    {
#ifdef __MMI_MEDIA_PLAYER_STREAM__
        /*stream title*/
        if (0 != g_medply.stream_title[0] && 
            0 != g_medply.stream_title[1])
        {
            *data_from = MMI_MSCR_DATA_FROM_STREAM;

            return  (U16*)g_medply.stream_title;
        }
#endif
        if (0 != g_medply.filefullpath[0])
        {
            if (0 != mmi_inline_is_stream_url())
            {
                *data_from = MMI_MSCR_DATA_FROM_STREAM;
            }
            else
            {
                *data_from = MMI_MSCR_DATA_FROM_FILE;
            }
            return  (U16*)g_medply.filefullpath;
        }
    }
    *data_from = MMI_MSCR_DATA_FROM_NULL;

    return  (U16*)GetString(STR_ID_MEDPLY_APP_TITLE);
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_volume_level
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_get_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(g_single.volume);
        return  g_single.volume;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE(g_medply.volume);
        return  g_medply.volume;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_status
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(g_single.state);
        return  g_single.state;
    }
    else
    {
    	MMI_MSCR_MSG_TRACE(g_medply.state);
        return  g_medply.state;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_get_group_id
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_ID mmi_inline_get_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
    	MMI_MSCR_MSG_TRACE(GRP_ID_MEDPLY_SINGLE);
        return  GRP_ID_MEDPLY_SINGLE;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(APP_MEDPLY);
        return  APP_MEDPLY;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_inline_is_seekable
* DESCRIPTION
*  inline function to get seekable flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_seekable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.seekable);
        return  g_single.seekable;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.seekable);
        return  g_medply.seekable;
    }
}

#ifdef MMI_MSCR_SHOW_3D_VIDEO_ICON
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_3d_mode
* DESCRIPTION
*  inline function to get seekable flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  MMI_BOOL mmi_inline_is_3d_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
	U16 play_mode;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.has_2d_mode);
        MMI_MSCR_MSG_TRACE(g_single.has_3d_mode);
        if(g_single.has_2d_mode && g_single.has_3d_mode)
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE, &play_mode);
            MMI_MSCR_MSG_TRACE(play_mode);
            if(play_mode == MDI_VIDEO_TRACK_3D)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else if(g_single.has_3d_mode)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
        
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.has_2d_mode);
        MMI_MSCR_MSG_TRACE(g_medply.has_3d_mode);
        if(g_medply.has_2d_mode && g_medply.has_3d_mode)
        {
            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE, &play_mode);
            MMI_MSCR_MSG_TRACE(play_mode);
            if(play_mode == MDI_VIDEO_TRACK_3D)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else if(g_medply.has_3d_mode)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
	
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_volume_mute
* DESCRIPTION
*  inline function to get volume mute flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_volume_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_inline_is_single_play())
    {
        return  g_single.mute;
    }
    else
    {
        return  g_medply.mute;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_full_screen
* DESCRIPTION
*  check current play is in full screen
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  g_medply.fullscreen;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_single_play
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_single_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  mmi_medply_is_single_player_activated();
}


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_spectrum_blocked
* DESCRIPTION
*  inline function to get value from ctrl
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_spectrum_blocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
    if (mmi_inline_is_single_play())
    {
        return  0;
    }
    else
    {
        return  g_medply.A2DP_blocked;
    }
#else
    return  0;
#endif
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_duration_seek_able
* DESCRIPTION
*  inline function to check duration is seek able
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_duration_seek_able(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_background_call())
    {
        /*In background call, disabled seek*/
        return  0;
    }

    return !mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PROGRESS_BAR) ;

}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_stream_url
* DESCRIPTION
*  inline function to check the fullfilepath whether it's stream url
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8  mmi_inline_is_stream_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U32 u32Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u32Value = mmi_inline_get_media_type();
    if (MEDPLY_TYPE_STREAM_RTSP == u32Value)
    {
        return 1;
    }
#ifdef __MMI_VIDEO_STREAM__
    if (MEDPLY_TYPE_STREAM == u32Value)
    {
        u32Value = mmi_inline_get_media_format();
        if (MEDPLY_FORMAT_RTSP == u32Value)
        {
            return  1;
        }
    }
#endif
    return  0;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_resizeable_image
* DESCRIPTION
*  inline function to check the image, whether it can resize
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
#if !defined (__MMI_FTE_SUPPORT__)
static  U8 mmi_inline_is_resizeable_image(U16* file_path, 
                                          S32 src_w, S32 src_h, 
                                          S32 dst_w, S32 dst_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    U32 u32Value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u32Value = srv_fmgr_types_find_type_by_filename_str((WCHAR*)file_path);
    switch(u32Value)
    {
        /*
        *   Only JPG support turn large
        */    
    case FMGR_TYPE_JPG:
    case FMGR_TYPE_JPEG:

        return  1;
#if 0 //defined(MT6238)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    default:
        
        /*
        *   Other image type only support turn small
        */
        if (src_w > dst_w && src_h > dst_h)
        {
            return  1;
        }
        break;
    }
    return  0;
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_inline_is_background_call
* DESCRIPTION
*  inline function to check whether the background call valid;
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_background_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        return 1;
    }
#endif /* __MMI_BACKGROUND_CALL__ */
    
    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_inline_is_button_disable
* DESCRIPTION
*  inline function to check whether the button is disabled;
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  U8 mmi_inline_is_button_disable(S32 button_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != mmi_inline_is_background_call())
    {
        /*In background call, button need disabled*/
        return  1;
    }
    if (mmi_medply_is_button_disabled((mmi_medply_disabled_button_enum)button_id))
    {
        return  1;
    }
    return  0;
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_reset_button_up
* DESCRIPTION
*  inline function to check whether the button is disabled;
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static  void mmi_inline_reset_button_up(mmi_medply_regn_id_enum id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == g_mscr_hd->rgn_push_down_id)
    {
        g_mscr_hd->rgn_push_down_id = MMI_MSCR_BUTTON_ID_EX_TOTAL;    
    }
}

#ifdef MMI_MEDPLY_MSCR_SUBTITLE_SUPPORT
/*****************************************************************************
* FUNCTION
*  mmi_inline_is_3d_mode
* DESCRIPTION
*  inline function to get seekable flag
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
MMI_BOOL mmi_inline_has_subtitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.media_type == MEDPLY_TYPE_AUDIO)
    {
        /* No subtitles for audio files */
        return MMI_FALSE;
    }
    else if (mmi_inline_is_single_play())
    {
        MMI_MSCR_MSG_TRACE(g_single.has_subtitle);
        return  g_single.has_subtitle;
    }
    else
    {
        MMI_MSCR_MSG_TRACE(g_medply.has_subtitle);
        return  g_medply.has_subtitle;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_inline_set_subtitle_font_size
* DESCRIPTION
*  inline function to set subtitle font size
* PARAMETERS
*  void        
* RETURNS
*  void
 *****************************************************************************/
static void mmi_inline_set_subtitle_font_size(U8 font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MSCR_MSG_TRACE(font_size);
    g_medply.subtitle_font_size = font_size;
}

#endif


#endif /*__MMI_MEDIA_PLAYER__*/
#endif /*__MMI_MEDIA_PLAYER_FTE__*/
