#include "MMI_features.h" 
#include "custresdef.h"

#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_NPPLG">

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_NPPLG_ERROR_TITLE"/>
    <STRING id="STR_ID_NPPLG_NETWORK_ERROR"/>
    <STRING id="STR_ID_NPPLG_FAIL_TO_PLAY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_NPPLG_AV_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PLAY_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PLAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Pause_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PAUSE_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Pause_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PAUSE_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Pause_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Stop_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_STOP_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Stop_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_STOP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Stop_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_REWIND">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\BackForward_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_REWIND_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\BackForward_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_REWIND_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\BackForward_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_FAST_FORWARD">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\FastForward_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_FAST_FORWARD_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\FastForward_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_FAST_FORWARD_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\FastForward_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_SPEAKER_ON">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\SpeakerOn_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_SPEAKER_ON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\SpeakerOn_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_SPEAKER_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\SpeakerOff_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_SPEAKER_OFF_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\SpeakerOff_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_MEDIA_PLAYER">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\MediaPlayer_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_MEDIA_PLAYER_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\MediaPlayer_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_MEDIA_PLAYER_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\MediaPlayer_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_MEDIA_PLAYER_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PLAY_ONLY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_STOP_ONLY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Stop.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_VIDEO_LARGE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Audio_only_large.gif"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_VIDEO_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Audio_only_small.gif"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PROGRESS_FG">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Progress_bar_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PROGRESS_BG">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Progress_bar_background.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PROGRESS_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\indicator.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PROGRESS_PANEL">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Panel_background2.9slice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\highlight.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PLAY_PANEL">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Panel_background.9slice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_PROCESSING">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Progress"</IMAGE>
    <IMAGE id="IMG_ID_NPPLG_AV_CTRL_SEPARATE_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\separate_line.png"</IMAGE>
    
#if defined(__MMI_USB_SUPPORT__)
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="npplg_av_main_exit_usb_mode"/>
#endif

</APP>

#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
