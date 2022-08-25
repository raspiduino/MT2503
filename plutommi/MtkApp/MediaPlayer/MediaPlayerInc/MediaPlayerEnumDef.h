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
*  MediaPlayerEnumDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player enum define
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef MEDIA_PLAYER_ENUM_DEF_H
#define MEDIA_PLAYER_ENUM_DEF_H

#include "MMI_features.h"

#ifdef __MMI_MEDIA_PLAYER__
#include "mmi_features_mediaplayer.h"

typedef enum
{
    MEDPLY_MAIN_DISABLED = -1,
    MEDPLY_MAIN_PLAY = 0,
    MEDPLY_MAIN_PREV,
    MEDPLY_MAIN_NEXT,
    MEDPLY_MAIN_STOP,
    NO_OF_MEDPLY_MAIN_BUTTONS,
    MEDPLY_MAIN_PAUSE
} medply_main_buttons_enum;

typedef enum
{
    MEDPLY_FAIL_PLAY_TYPE_MED_ISSUE,
    MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE,
    MEDPLY_FAIL_PLAY_TYPE_TOTAL
}mmi_medply_fail_play_enum;


typedef enum
{
    /* play settings    */
    MMI_MEDPLY_SETTINGS_SKIN_INDEX,         /* U8 ,skin index 0: theme 1: from file    */
    MMI_MEDPLY_SETTINGS_SKIN_PATH,          /* U8 array, skin image path from file           */
    MMI_MEDPLY_SETTINGS_BG_PLAY,            /* U8 ,background play 0:off 1: on         */
    MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE,    /* default storage: driver letter. */    
    MMI_MEDPLY_SETTINGS_REPEAT,             /* U8 ,repeat play 0: off 1:repeat one 2:repeat all  */
    MMI_MEDPLY_SETTINGS_SHUFFULE,           /* U8 0:off 1: on*/
    MMI_MEDPLY_SETTINGS_MOTIONSENSOR,       /* U8 0: off  1: on */
    /* audio settings   */
    MMI_MEDPLY_SETTINGS_AUDIO_SPEED,        /* U16 ,audio play speed:slow2,slow1,normal,fast1,fast2*/
    MMI_MEDPLY_SETTINGS_MAINSCR_DISP,       /* U8 ,main screen display content:spectrum,lyrics,detail,artwork*/
    /* video settings   */
    MMI_MEDPLY_SETTINGS_BRIGHTNESS,         /* U16 ,brightness: -5,-4,...,0,...,4,5     */
    MMI_MEDPLY_SETTINGS_CONTRAST,           /* U16 ,contrast:  -5,-4,...,0,...,4,5      */
    MMI_MEDPLY_SETTINGS_VIDEO_SPEED,        /* U16 video play speed                    */
    MMI_MEDPLY_SETTINGS_PLAY_MODE,           /* U16 ,2d,3d      */
    /* bt settings      */
    MMI_MEDPLY_SETTINGS_BT_OUTPUT,          /* U8 ,0:off  1:on                         */
    MMI_MEDPLY_SETTINGS_BT_HEADSET,         /* bt headset info  NULL(BT OFF)       */
    /* network settings */
    MMI_MEDPLY_SETTINGS_ACTIVE_PROFILE_IDX,  /* U8 */
    MMI_MEDPLY_SETTINGS_PROFILE,            /* network profile info                */
    MMI_MEDPLY_SETTINGS_SUBTITLE_LCC,
    MMI_MEDPLY_SETTINGS_SUBTITLE_TRACK_INDEX,
    MMI_MEDPLY_SETTINGS_TYPE_ALL	
}mmi_medply_settings_type_enum;

typedef enum
{
    MMI_MEDPLY_SKIN_DEFAULT,
    MMI_MEDPLY_SKIN_FROM_FILE,
    MMI_MEDPLY_SKIN_NUM_ALL
}mmi_medply_settings_skin_enum;

typedef enum
{
    MMI_MEDPLY_SETTINGS_REPEAT_OFF,
    MMI_MEDPLY_SETTINGS_REPEAT_ONE,
    MMI_MEDPLY_SETTINGS_REPEAT_ALL,
    MMI_MEDPLY_SETTINGS_REPEAT_ENUM_ALL
}mmi_medply_settings_repeat_enum;

typedef enum
{
    MMI_MEDPLY_SETTINGS_SHUFFLE_OFF,
    MMI_MEDPLY_SETTINGS_SHUFFLE_ON
}mmi_medply_settings_shuffle_enum;


typedef enum
{
    MMI_MEDPLY_SETTINGS_OFF,
    MMI_MEDPLY_SETTINGS_ON,
    MMI_MEDPLY_SETTINGS_ALL
}mmi_medply_settings_on_off_enum;


typedef enum
{
    MMI_MEDPLY_MAINSCR_DISP_DETAIL,
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    MMI_MEDPLY_MAINSCR_DISP_SPECTRUM,
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    MMI_MEDPLY_MAINSCR_DISP_LYRICS,
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */
#ifdef __MMI_MEDPLY_MAIN_DISP_ARTWORK__//add by yongbin
    MMI_MEDPLY_MAINSCR_DISP_ARTWORK,
#endif /*  __MMI_MEDPLY_MAIN_DISP_ARTWORK__ */
    MMI_MEDPLY_MAINSCR_DISP_ALL
}mmi_medply_settings_mainscr_display_enum;

typedef enum
{
    MMI_MEDPLY_DISABLED_CONTROL_BUTTONS,    /* play(pause) | stop | prev | next */
    MMI_MEDPLY_DISABLED_PLAY,              /* play key*/
    MMI_MEDPLY_DISABLED_PAUSE,              /* pause key*/
    MMI_MEDPLY_DISABLED_KUROACT,            /* kuro activate */
    MMI_MEDPLY_DISABLED_SNAPSHOT,           /* snapshot */
    MMI_MEDPLY_DISABLED_ZOOM,               /* full screen */
    MMI_MEDPLY_DISABLED_PROGRESS_BAR,       /* progress bar */
    MMI_MEDPLY_DISABLED_VOL_INC,            /* vol inc */
    MMI_MEDPLY_DISABLED_VOL_DEC,            /* vol dec */

    MMI_MEDPLY_DISABLED_VOCAL_REMOVAL,      /*vocal removal*/
    MMI_MEDPLY_DISABLED_PITCH_INC,          /*pitch inc*/
    MMI_MEDPLY_DISABLED_PITCH_DEC,          /*pitch dec*/

    MMI_MEDPLY_DISABLED_PREV_NEXT,

    MMI_MEDPLY_DISABLED_PLAY_MODE,

    MMI_MEDPLY_DISABLED_TOTAL
}mmi_medply_disabled_button_enum;

typedef enum
{
    MEDPLY_WIDGET_STATE_IDLE,
    MEDPLY_WIDGET_STATE_PLAY,
    MEDPLY_WIDGET_STATE_PROCESSING,
    MEDPLY_WIDGET_STATE_TOTAL
}mmi_medply_widget_state_enum;

typedef enum
{
    /*core*/
    MEDPLY_STATE_IDLE,
    MEDPLY_STATE_WAIT_NEXT,
    MEDPLY_STATE_WAIT_NEXT_SUSPNEDED,
    MEDPLY_STATE_SNAPSHOT,

    /*audio*/
    MEDPLY_STATE_AUDIO_READY,               /*4*/
    MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING,
    MEDPLY_STATE_AUDIO_PLAY,
    MEDPLY_STATE_AUDIO_PLAY_PROGRESSING,    /*7*/
    MEDPLY_STATE_AUDIO_BT_CONNECTING,
    MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING,
    MEDPLY_STATE_AUDIO_WAIT_ACTIVATE,
    MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE,
    MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE, /*12*/
    MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE,
    MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE,
    MEDPLY_STATE_AUDIO_INTERRUPTED,

    /*video*/
    MEDPLY_STATE_VIDEO_IDLE,                /*16*/
    MEDPLY_STATE_VIDEO_IDLE_PROGRESSING,
    MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING,
    MEDPLY_STATE_VIDEO_OPENING,
    MEDPLY_STATE_VIDEO_READY,               /*20*/
    MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING,
    MEDPLY_STATE_VIDEO_PAUSE_SEEKING,
    MEDPLY_STATE_VIDEO_PLAY,
    MEDPLY_STATE_VIDEO_PLAY_PROGRESSING,
    MEDPLY_STATE_VIDEO_PLAY_SEEKING,        /*25*/
    MEDPLY_STATE_PURE_AUDIO_READY,
    MEDPLY_STATE_PURE_AUDIO_PLAY,
    MEDPLY_STATE_VIDEO_BT_CONNECTING,
    MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING,
    MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING, /*30*/
    MEDPLY_STATE_VIDEO_INTERRUPTED,

    /*streaming*/
    MEDPLY_STATE_STREAM_IDLE,
    MEDPLY_STATE_STREAM_INITED,             /*33*/
    MEDPLY_STATE_STREAM_CONNECTING,
    MEDPLY_STATE_STREAM_CONNECTED,
    MEDPLY_STATE_STREAM_BUFFERING,          /*36*/
    MEDPLY_STATE_STREAM_PLAY,
    MEDPLY_STATE_STREAM_PLAY_PROGRESSING,
    MEDPLY_STATE_STREAM_AUDIO_PLAY,
    MEDPLY_STATE_STREAM_BT_CONNECTING,
    MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING,   /*41*/
    MEDPLY_STATE_STREAM_INTERRUPTED,

    MEDPLY_STATE_TOTAL
} mmi_medply_state_enum;

typedef enum
{
    SINGLE_STATE_IDLE,
    SINGLE_STATE_WAIT_NEXT,

    /*audio*/
    SINGLE_STATE_AUDIO_READY,                       /*2*/
    SINGLE_STATE_AUDIO_PLAY,
    SINGLE_STATE_AUDIO_PAUSE_PROGRESSING,
    SINGLE_STATE_AUDIO_PLAY_PROGRESSING,
    SINGLE_STATE_AUDIO_BT_CONNECTING,
    SINGLE_STATE_AUDIO_WAIT_ACTIVATE,
    SINGLE_STATE_AUDIO_PLAY_WAIT_ACTIVATE,
    SINGLE_STATE_AUDIO_IN_HISTORY,

    /*video*/
    SINGLE_STATE_VIDEO_OPENING,                     /*10*/
    SINGLE_STATE_VIDEO_READY,
    SINGLE_STATE_VIDEO_PLAY,
    SINGLE_STATE_VIDEO_PAUSE_PROGRESSING,
    SINGLE_STATE_VIDEO_PAUSE_SEEKING,
    SINGLE_STATE_VIDEO_PLAY_PROGRESSING,
    SINGLE_STATE_VIDEO_PLAY_SEEKING,
    SINGLE_STATE_VIDEO_BT_CONNECTING,
    SINGLE_STATE_VIDEO_IN_HISTORY,

    /*stream*/
    SINGLE_STATE_STREAM_INITED,                     /*19*/
    SINGLE_STATE_STREAM_CONNECTING,
    SINGLE_STATE_STREAM_CONNECTED,
    SINGLE_STATE_STREAM_BUFFERING,
    SINGLE_STATE_STREAM_PLAY,
    SINGLE_STATE_STREAM_PLAY_PROGRESSING,
    SINGLE_STATE_STREAM_BT_CONNECTING,
    SINGLE_STATE_STREAM_IN_HISTORY,

    /*PDL*/
    SINGLE_STATE_PDL_VIDEO_OPENING,                 /*27*/
    SINGLE_STATE_PDL_VIDEO_READY,
    SINGLE_STATE_PDL_VIDEO_PLAY,
    SINGLE_STATE_PDL_VIDEO_PAUSE_BUFFERING,
    SINGLE_STATE_PDL_VIDEO_PLAY_BUFFERING,
    SINGLE_STATE_PDL_VIDEO_PAUSE_PROGRESSING,
    SINGLE_STATE_PDL_VIDEO_PAUSE_SEEKING,
    SINGLE_STATE_PDL_VIDEO_PLAY_PROGRESSING,
    SINGLE_STATE_PDL_VIDEO_PLAY_SEEKING,
    SINGLE_STATE_PDL_VIDEO_BT_CONNECTING,
    SINGLE_STATE_PDL_VIDEO_IN_HISTORY,

    SINGLE_STATE_PDL_AUDIO_READY,                   /*38*/
    SINGLE_STATE_PDL_AUDIO_BUFFERING,
    SINGLE_STATE_PDL_AUDIO_PLAY,
    SINGLE_STATE_PDL_AUDIO_BT_CONNECTING,
    SINGLE_STATE_PDL_AUDIO_IN_HISTORY,

    SINGLE_STATE_TOTAL    
}mmi_medply_single_state_enum;

typedef enum
{
    MEDPLY_TYPE_NONE,
    MEDPLY_TYPE_AUDIO,
    MEDPLY_TYPE_VIDEO,
    MEDPLY_TYPE_STREAM,

    /* below are only for single player*/    
    MEDPLY_TYPE_STREAM_RTSP,
    MEDPLY_TYPE_STREAM_SDP,
    MEDPLY_TYPE_STREAM_RAM,
    MEDPLY_TYPE_PDL_VIDEO,
    MEDPLY_TYPE_PDL_AUDIO,

    MEDPLY_TYPE_TOTAL
} mmi_medply_media_type_enum;


typedef enum
{
    MEDPLY_ERR_AUDIO,
    MEDPLY_ERR_VIDEO,
    MEDPLY_ERR_STREAM,
    MEDPLY_ERR_OTHERS,

    MEDPLY_ERR_TOTAL
} mmi_medply_err_type;

#ifdef __MMI_KURO_SUPPORT__
typedef enum
{
    MEDPLY_ACTIVATE_NONE,
    MEDPLY_ACTIVATE_DEMO_END,
    MEDPLY_ACTIVATE_CURRENT_MEDIA,
    MEDPLY_ACTIVATE_FROM_LIST,
    MEDPLY_ACTIVATE_ALL,

    MEDPLY_ACTIVATE_TOTAL
} mmi_medply_kuro_activate_type;
#endif

typedef enum
{
    MEDPLY_FORMAT_NONE,
/*audio*/
    MEDPLY_FORMAT_DAF,
    MEDPLY_FORMAT_MUSICAN,
    MEDPLY_FORMAT_RA,
    MEDPLY_FORMAT_AMR,
    MEDPLY_FORMAT_AAC,
    MEDPLY_FORMAT_AWB,
    MEDPLY_FORMAT_BSAC,
    MEDPLY_FORMAT_ODF,
    MEDPLY_FORMAT_WAV,
    MEDPLY_FORMAT_MID,
    MEDPLY_FORMAT_MIDI,
    MEDPLY_FORMAT_IMY,
    MEDPLY_FORMAT_AIFF,
    MEDPLY_FORMAT_AIF,
    MEDPLY_FORMAT_AIFC,
    MEDPLY_FORMAT_AU,
    MEDPLY_FORMAT_SND,
    MEDPLY_FORMAT_MMF,
    MEDPLY_FORMAT_WMA,
    MEDPLY_FORMAT_M4A,
    MEDPLY_FORMAT_3GPA,
    MEDPLY_FORMAT_MP4A,
    MEDPLY_FORMAT_3G2A,
    MEDPLY_FORMAT_3GA,
    MEDPLY_FORMAT_APE,
    MEDPLY_FORMAT_OGG,
    MEDPLY_FORMAT_FLAC,
/*video*/
    MEDPLY_FORMAT_3GP,
    MEDPLY_FORMAT_MP4,
    MEDPLY_FORMAT_MPG,
    MEDPLY_FORMAT_3G2,
    MEDPLY_FORMAT_RV,
    MEDPLY_FORMAT_RM,
    MEDPLY_FORMAT_RMVB,
    MEDPLY_FORMAT_AVI,
    MEDPLY_FORMAT_FLV,
    MEDPLY_FORMAT_F4V,
    MEDPLY_FORMAT_MKV,
    MEDPLY_FORMAT_WEBM,
    MEDPLY_FORMAT_MK3D,
    MEDPLY_FORMAT_MOT,
    MEDPLY_FORMAT_KMV,
    MEDPLY_FORMAT_QKMV,
/*streaming*/    
    MEDPLY_FORMAT_RTSP,
    MEDPLY_FORMAT_SDP,
    MEDPLY_FORMAT_RAM,
/* Vendor */
    KURO_FORMAT_KUR,

    MEDPLY_FORMAT_TOTAL
} mmi_medply_media_format_enum;

#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)
typedef enum
{
    MEDPLY_PDL_STATE_EXIT,
    MEDPLY_PDL_STATE_DOWNLOADING,
    MEDPLY_PDL_STATE_FINISHED
} mmi_medply_pdl_state_enum;

typedef enum
{
    MEDPLY_PDL_TYPE_AUDIO,
    MEDPLY_PDL_TYPE_VIDEO,

    MEDPLY_PDL_TYPE_TOTAL
} mmi_medply_pdl_media_type_enum;
#endif

typedef enum
{
    MMI_MEDPLY_RGN_STATUS_DOWN = 0,
    MMI_MEDPLY_RGN_STATUS_UP,
    MMI_MEDPLY_RGN_STATUS_DISABLE,
    MMI_MEDPLY_RGN_STATUS_TOTAL

} mmi_medply_regn_status_enum;

#ifdef __MMI_MEDIA_PLAYER_FTE__

/* 
 * If you want to modify this enum, 
 * please contact with Ruoyao(MTK80202) firstly 
 * !!!
 */
typedef enum
{
    MMI_MEDPLY_RGN_ID_NULL       = 0xff,
    /* in panel*/
    MMI_MEDPLY_RGN_ID_PLAY_PAUSE = 0,   /*MMI_MSCR_BUTTON_IN_PANEL_BEGIN*/ 
#ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
    MMI_MEDPLY_RGN_ID_STOP,
#endif
    MMI_MEDPLY_RGN_ID_PREV,
    MMI_MEDPLY_RGN_ID_NEXT,
    MMI_MEDPLY_RGN_ID_LKEY,
    MMI_MEDPLY_RGN_ID_RKEY,
    MMI_MEDPLY_RGN_ID_MODE,
    MMI_MEDPLY_RGN_ID_ZOOM,             /*5*/
    MMI_MEDPLY_RGN_ID_DURATION_BAR,
    /* MMI_MSCR_BUTTON_IN_PANEL_TOTAL */
    
    /* in view */
    MMI_MEDPLY_RGN_ID_SHUFFLE,          /*MMI_MSCR_BUTTON_IN_VIEW_BEGIN*/
    MMI_MEDPLY_RGN_ID_REPEAT,
    MMI_MEDPLY_RGN_ID_USER_RATING, 
    /* MMI_MSCR_BUTTON_IN_VIEW_TOTAL */

    /*in kuro*/
    MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL,    /*10, MMI_MSCR_BUTTON_IN_POPUP_BEGIN*/    
    MMI_MEDPLY_RGN_ID_PITCH_INC,
    MMI_MEDPLY_RGN_ID_PITCH_DEC,
    MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
    MMI_MEDPLY_RGN_ID_ACTIVATE,            

    /*in volume*/
    MMI_MEDPLY_RGN_ID_VOLUME_BAR,
    MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,     /*15*/
    /*MMI_MSCR_BUTTON_IN_POPUP_TOTAL*/

    /*kuro panel 3 button*/
    MMI_MEDPLY_RGN_ID_KURO, 
    MMI_MEDPLY_RGN_ID_KURO_SHUFFLE,
    MMI_MEDPLY_RGN_ID_KURO_REPEAT,
    /* MMI_MSCR_BUTTON_ID_EX_TOTAL*/
    //MMI_MEDPLY_RGN_ID_VOLUME_BAR,    
        
    /* user ration poup*/
    MMI_MEDPLY_RGN_ID_MODIFY_RATING,
    
    /*No use for FTE*/
    MMI_MEDPLY_RGN_ID_VOLUME_INC,
    MMI_MEDPLY_RGN_ID_VOLUME_DEC,
#ifndef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
    MMI_MEDPLY_RGN_ID_STOP,      
#endif    
    MMI_MEDPLY_RGN_ID_POPUP,

    MMI_MEDPLY_RGN_ID_TOTAL
        
} mmi_medply_regn_id_enum;

#else
typedef enum
{
    MMI_MEDPLY_RGN_ID_NULL       = 0xff,
    MMI_MEDPLY_RGN_ID_PLAY_PAUSE = 0,
    MMI_MEDPLY_RGN_ID_STOP,
    MMI_MEDPLY_RGN_ID_PREV,
    MMI_MEDPLY_RGN_ID_NEXT,
    MMI_MEDPLY_RGN_ID_SHUFFLE,
    MMI_MEDPLY_RGN_ID_REPEAT,
    MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
    MMI_MEDPLY_RGN_ID_ACTIVATE,
    MMI_MEDPLY_RGN_ID_ZOOM,
    MMI_MEDPLY_RGN_ID_MODE,
    #if defined (__MMI_FTE_SUPPORT__)
    /* in FTE mode need change softkey to image */
    MMI_MEDPLY_RGN_ID_LKEY,
    MMI_MEDPLY_RGN_ID_RKEY,
    #endif
    MMI_MEDPLY_RGN_ID_VOLUME_INC,
    MMI_MEDPLY_RGN_ID_VOLUME_DEC,
    MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,         /*MMI_MSCR_BUTTON_ID_EX_TOTAL in no kuro support*/

    MMI_MEDPLY_RGN_ID_VOCAL_REMOVAL,        /*15*/
    #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
    /* seperate kuro activate button from snap shot in FTE mode */
    MMI_MEDPLY_RGN_ID_KURO_ACTIVATE,
    #endif    
    MMI_MEDPLY_RGN_ID_PITCH_INC,
    MMI_MEDPLY_RGN_ID_PITCH_DEC,            /*MMI_MSCR_BUTTON_ID_EX_TOTAL in kuro support*/

    MMI_MEDPLY_RGN_ID_DURATION_BAR,
    #if !defined (__MMI_FTE_SUPPORT__)
    MMI_MEDPLY_RGN_ID_LKEY,
    MMI_MEDPLY_RGN_ID_RKEY,
    #endif
    /*no use*/
    MMI_MEDPLY_RGN_ID_KURO, 
    MMI_MEDPLY_RGN_ID_KURO_SHUFFLE,
    MMI_MEDPLY_RGN_ID_KURO_REPEAT,
    MMI_MEDPLY_RGN_ID_VOLUME_BAR,  
    MMI_MEDPLY_RGN_ID_MODIFY_RATING,
    MMI_MEDPLY_RGN_ID_USER_RATING,

    MMI_MEDPLY_RGN_ID_TOTAL
        
} mmi_medply_regn_id_enum;
#endif /*__MMI_MEDIA_PLAYER_FTE__*/

typedef enum
{
    MMI_MEDPLY_SCREEN_NORMAL,
    MMI_MEDPLY_SCREEN_FULL,
    MMI_MEDPLY_SCREEN_KURO,
    MMI_MEDPLY_SCREEN_VOLUME,
    MMI_MEDPLY_SCREEN_RATING,

    MMI_MEDPLY_SCREEN_TOTAL

} mmi_medply_main_screen_status_enum;

typedef enum
{
    MMI_MEDPLY_STATUS_IDLE         = 0,
    MMI_MEDPLY_STATUS_READY,    
    MMI_MEDPLY_STATUS_PLAYING,
    MMI_MEDPLY_STATUS_TOTAL
        
} mmi_medply_ui_status_enum;

typedef enum
{
    MMI_MEDPLY_ANI_NULL,
    MMI_MEDPLY_ANI_LOADING, 
    MMI_MEDPLY_ANI_VIDEO_OPENING,
    MMI_MEDPLY_ANI_BT_CONNECTING,
    MMI_MEDPLY_ANI_RTP_CONNECTING,
    MMI_MEDPLY_ANI_SNAP_SHOT,
    MMI_MEDPLY_ANI_TOTAL
        
} mmi_medply_ui_ani_enum;

typedef enum
{
    MMI_MEDPLY_ENTRY_MAINMENU,
    MMI_MEDPLY_ENTRY_MAINSCRN, 
    MMI_MEDPLY_ENTRY_LISTMGR,

    MMI_MEDPLY_ENTRY_TOTAL
} mmi_medply_main_entry_enum;



#endif /*__MMI_MEDIA_PLAYER__*/

#endif /* MEDIA_PLAYER_ENUM_DEF_H */ 

