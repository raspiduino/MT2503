/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#if defined(__MMI_SOUND_RECORDER__)

#include "CustResDef.h"         /* for image/audio path */
#include "custom_mmi_default_value.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_SOUNDRECORDER"
#ifdef __MMI_APP_MANAGER_SUPPORT__
    package_name = "native.mtk.sndrec"
    name = "STR_ID_SNDREC_MAIN"
 #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    img = "IMG_ID_SNDREC_VUI_MAIN_MENU_APP_ICON"
 #endif
    launch = "mmi_sndrec_launch_function"
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
>
	<INCLUDE file="GlobalResDef.h,FileMgrResDef.h"/>
	<INCLUDE file ="mmi_rp_all_defs.h"/>
	
	<STRING id="STR_ID_SNDREC_MAIN"/>
	<STRING id="STR_ID_SNDREC_NEW_RECORD"/>
#ifndef __MMI_SNDREC_SLIM__
	<STRING id="STR_ID_SNDREC_APPEND"/>
#endif    /* __MMI_SNDREC_SKIN__ */
	<STRING id="STR_ID_SNDREC_SETTING_QUALITY"/>
#ifdef __MMI_SNDREC_SKIN__
	<STRING id="STR_ID_SNDREC_PLS_RECORD"/>
	<STRING id="STR_ID_SNDREC_RECORDING"/>
	<STRING id="STR_ID_SNDREC_REC_PAUSED"/>
	<STRING id="STR_ID_SNDREC_PLAYING"/>
	<STRING id="STR_ID_SNDREC_PLAY_PAUSED"/>
#endif /* __MMI_SNDREC_SKIN__ */
    <STRING id="STR_ID_SNDREC_SYSTEM_ERROR"/>
#ifdef __VM_CODEC_SUPPORT__	
	<STRING id="STR_ID_SNDREC_AUTO_RECORD_ON"/>
#endif  /* __VM_CODEC_SUPPORT__ */	
	<STRING id="STR_ID_SNDREC_AUDIO_PLAY_FAIL"/>
	<STRING id="STR_ID_SNDREC_REC_ERROR"/>
	<STRING id="STR_ID_SNDREC_SPEECH_OFF"/>
	<STRING id="STR_ID_SNDREC_SMS_RECORD_TIMEOUT"/>
	<STRING id="STR_ID_SNDREC_DISC_FULL"/>
#ifdef __CTM_SUPPORT__
	<STRING id="STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL"/>
#endif    /* __CTM_SUPPORT__ */
#ifdef __MMI_OP12_SNDREC_STYLE__	
	<STRING id="STR_ID_SNDREC_DISCARD_ASK"/>
#endif	/* __MMI_OP12_SNDREC_STYLE__ */
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    <STRING id="STR_ID_SNDREC_MY_RECORDS"/>
    <STRING id="STR_ID_SNDREC_RECORD"/>
#endif


#ifdef __MMI_APP_MANAGER_SUPPORT__
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
	<IMAGE id="IMG_ID_SNDREC_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\SoundRecorder.png"</IMAGE>
    #endif
#endif
/* This image ID is used for sound recorder menu display but for slim numbering icons are present */
#ifndef __MMI_SNDREC_SLIM__
	<IMAGE id="IMG_ID_SNDREC_MAIN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\SoundRecorder\\\\SB_SR.bmp"</IMAGE>
#endif    /* __MMI_SNDREC_SKIN__ */

#ifdef __MMI_FTE_SUPPORT__
/* FTE Changes
    - Remove Background image, change to use submenu background(Apply in all FTE Project)
    - Remove images of disabled status, change to 50% transparency(Apply in all FTE Project)
    - Remove unused images, new design no need(Apply in all FTE Project)
*/
    #if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT)

       #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_LIST.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_LIST_DIS.png"</IMAGE>
       #endif

	#if defined(__MMI_FTE_SUPPORT_SLIM__)
	//<IMAGE id="IMG_ID_SNDREC_FTE_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\BG.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\line.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_CROSS">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\Button_BG.png"</IMAGE>
	#else
	//<IMAGE id="IMG_ID_SNDREC_FTE_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SND_BG.png"</IMAGE>
	#endif

	#if (defined(__MMI_SNDREC_SLIM__) && defined(__MMI_MAINLCD_240X320__))
	<IMAGE id="IMG_ID_SNDREC_FTE_ANIMAL">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MPLAYER_ANI_AUD_ONLY.png"</IMAGE>
	#else
	<IMAGE id="IMG_ID_SNDREC_FTE_ANIMAL">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_ANI.gif"</IMAGE>
	#endif

	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\REC.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\play.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\prev.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\next.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\stop.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\HIGHLIGHT.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\option.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\back.png"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\option_down.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\back_down.png"</IMAGE>
	
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SIGN_REC.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SIGN_PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\line.png"</IMAGE>

	#if defined(__MMI_OP02_LEMEI__)
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\pause_dis.png"</IMAGE>
	#endif

	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\REC_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\play_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\prev_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\next_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\stop_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\option_dis.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\back_dis.png"</IMAGE>
	
    #elif defined(__MMI_FTE_SUPPORT_SLIM__)
	//<IMAGE id="IMG_ID_SNDREC_FTE_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\BG.9slice.png"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_ANIMAL">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_ANI.gif"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\REC.png"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PLAY.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\prev.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\NEXT.png"</IMAGE>
       #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_LIST.png"</IMAGE>
       #endif
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\STOP.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\HIGHLIGHT.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\OPTION.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\BACK.png"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_REC_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_SIGN_REC.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_SIGN_PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\LINE.png"</IMAGE>

	#if defined(__MMI_OP02_LEMEI__)
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PAUSE_DIS.png"</IMAGE>
	#endif

	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\REC_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PLAY_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\PREV_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\NEXT_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\SNDREC_LIST_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\STOP_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\OPTION_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\BACK_DIS.png"</IMAGE>

    #else /* __MMI_FTE_SUPPORT_SLIM__ */
	//<IMAGE id="IMG_ID_SNDREC_FTE_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_BG.gif"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_ANIMAL">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_ANI.gif"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_REC.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PLAY.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PREVIOUS.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_NEXT.png"</IMAGE>
       #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_LIST.png"</IMAGE>
       #endif
	<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_STOP.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_HIGHLIGHT.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SK_OPTION.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SK_BACK.png"</IMAGE>

	<IMAGE id="IMG_ID_SNDREC_FTE_REC_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SIGN_REC.png"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SIGN_PAUSE.png"</IMAGE>

	#if defined(__MMI_OP02_LEMEI__)
	<IMAGE id="IMG_ID_SNDREC_FTE_REC_PAUSE_SIGN_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PAUSE_DIS.png"</IMAGE>
	#endif

	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_REC_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PLAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PLAY_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_PREVIOUS_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_NEXT_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_LIST_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_LIST_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_BUTTON_STOP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_STOP_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_LSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SK_OPTION_DIS.png"</IMAGE>
	//<IMAGE id="IMG_ID_SNDREC_FTE_SKIN_RSK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\FTE\\\\SNDREC_SK_BACK_DIS.png"</IMAGE>
    #endif /* __MMI_FTE_SUPPORT_SLIM__ */
#else/*__MMI_FTE_SUPPORT__*/

  #ifndef __MMI_SNDREC_SKIN__

    #ifndef __MMI_MAINLCD_96X64__
 	<IMAGE id="IMG_ID_SNDREC_ANIMAL_RECORD">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play_animation.png"</IMAGE>
    #else
       <IMAGE id="IMG_ID_SNDREC_ANIMAL_RECORD">CUST_IMG_PATH"\\\\MainLCD\\\\SndRec\\\\Record"</IMAGE>
       <IMAGE id="IMG_ID_SNDREC_ANIMAL_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\SndRec\\\\Pause\\\\Record0.bmp"</IMAGE>
    #endif

    #if 0
	<IMAGE id="IMG_ID_SNDREC_ANIMAL_RECORD">CUST_IMG_PATH"\\\\MainLCD\\\\SoundRecorder\\\\SR_record.gif"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_ANIMAL_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\SoundRecorder\\\\SR_RECORD_P.gif"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_ANIMAL_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\SoundRecorder\\\\SR_play.gif"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_ANIMAL_PLY_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\SoundRecorder\\\\SR_PLAY_P.gif"</IMAGE>
    #endif

  #else /* __MMI_SNDREC_SKIN__ */
	<IMAGE id="IMG_ID_SNDREC_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_BG.gif"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_ANIMAL">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_recording.gif"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_REC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_record_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_REC_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_record_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_REC_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_r_pause_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_REC_P_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_r_pause_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PLAY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_play_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PLAY_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_play_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PLAY_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_pause_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PLAY_P_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_pause_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PREV_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_previous_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PREV_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_previous_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_NEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_NEXT_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_LIST_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_LIST_DN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_record_disable.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PLAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_play_disable.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_previous_disable.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_disable.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_LIST_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_next_disable.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_STOP_P_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_r_stop_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_SNDREC_BUTTON_STOP_P_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Sndrec\\\\SR_r_stop_down.bmp"</IMAGE>
  #endif  /* __MMI_SNDREC_SKIN__ */

#endif/*__MMI_FTE_SUPPORT__*/

#if (defined(__MMI_MAINLCD_240X400__) && defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_MAIN" str="STR_ID_SNDREC_MAIN" img="IMG_ID_SNDREC_MAIN_ICON"  highlight="mmi_sndrec_hightlight_main"
shortcut="ON" shortcut_img="IMG_ID_SNDREC_MAIN_ICON" launch="mmi_sndrec_pre_entry_main_screen"/>
<MENU id="MAIN_MENU_OPTION_SNDREC_APP" str="STR_ID_SNDREC_MAIN" img="IMG_ID_SNDREC_MAIN_ICON"  highlight="mmi_sndrec_hightlight_main"/>
#else
<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_MAIN" parent="MAIN_MENU_MULTIMEDIA_MENUID" str="STR_ID_SNDREC_MAIN" 
#ifndef __MMI_SNDREC_SLIM__
	img="IMG_ID_SNDREC_MAIN_ICON"  
#endif    /* __MMI_SNDREC_SKIN__ */
	highlight="mmi_sndrec_hightlight_main" shortcut="ON" 
#ifndef __MMI_SNDREC_SLIM__
	shortcut_img="IMG_ID_SNDREC_MAIN_ICON" 
#endif    /* __MMI_SNDREC_SKIN__ */
	launch="mmi_sndrec_pre_entry_main_screen"/>
#endif

<!--Menu Item Area-->
<MENUITEM id="MENU_ID_SNDREC_NEW_RECORD" str="STR_ID_SNDREC_NEW_RECORD"/>
<MENUITEM id="MENU_ID_SNDREC_RECORD_PLAY" str="STR_GLOBAL_PLAY"/>
#ifndef __MMI_SNDREC_SLIM__
<MENUITEM id="MENU_ID_SNDREC_APPEND" str="STR_ID_SNDREC_APPEND"/>
#endif
#ifndef __MMI_SNDREC_SLIM__
<MENUITEM id="MENU_ID_SNDREC_RENAME" str="STR_GLOBAL_RENAME"/>
<MENUITEM id="MENU_ID_SNDREC_DELETE" str="STR_GLOBAL_DELETE"/>
#endif
<MENUITEM id="MENU_ID_SNDREC_RECORD_LIST" str="STR_GLOBAL_LIST"/>
#ifndef __MMI_SNDREC_SLIM_SETTINGS__
<MENUITEM id="MENU_ID_SNDREC_SETTING" str="STR_GLOBAL_SETTINGS"/>
#endif
#ifndef __MMI_SNDREC_SLIM__
<MENUITEM id="MENU_ID_SNDREC_FORWARD_USE" str="STR_GLOBAL_USE_AS"/>
<MENUITEM id="MENU_ID_SNDREC_FORWARD_SEND" str="STR_GLOBAL_SEND"/>
#endif


<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_OPTION" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
	<MENUITEM_ID>MENU_ID_SNDREC_NEW_RECORD</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_RECORD_PLAY</MENUITEM_ID>
       #ifndef __MMI_SNDREC_SLIM__
	<MENUITEM_ID>MENU_ID_SNDREC_APPEND</MENUITEM_ID>
       #endif
       #ifndef __MMI_SNDREC_SLIM__
	<MENUITEM_ID>MENU_ID_SNDREC_RENAME</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_DELETE</MENUITEM_ID>
       #endif
	<MENUITEM_ID>MENU_ID_SNDREC_RECORD_LIST</MENUITEM_ID>
       #ifndef __MMI_SNDREC_SLIM_SETTINGS__
	<MENUITEM_ID>MENU_ID_SNDREC_SETTING</MENUITEM_ID>
       #endif
       #ifndef __MMI_SNDREC_SLIM__
	<MENUITEM_ID>MENU_ID_SNDREC_FORWARD_USE</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_FORWARD_SEND</MENUITEM_ID>
       #endif
</MENU>

<!--Menu Item Area-->
<MENUITEM id="MENU_ID_SNDREC_LIST_PLAY" str="STR_GLOBAL_PLAY" />
#ifndef __MMI_SNDREC_SLIM__
<MENUITEM id="MENU_ID_SNDREC_LIST_APPEND" str="STR_ID_SNDREC_APPEND"/>
#endif
<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_REC_OPTION" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
	<MENUITEM_ID>MENU_ID_SNDREC_LIST_PLAY</MENUITEM_ID>
       #ifndef __MMI_SNDREC_SLIM__
	<MENUITEM_ID>MENU_ID_SNDREC_LIST_APPEND</MENUITEM_ID>
       #endif
	#ifdef __PLUTO_MMI_PACKAGE__
	#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	<MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
	#endif
	<MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
    #ifndef __MMI_SLIM_FILE_MANAGER__
	<MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
	#endif
	<MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_FORWARD_USE</MENUITEM_ID>
	<MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>
	#endif
</MENU>

<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_RENAME_OPTION" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
	<MENUITEM_ID>MENU_ID_SNDREC_OPTION_SAVE</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_OPTION_INPUT_METHOD</MENUITEM_ID>
</MENU>

#ifdef __MMI_OP12_SNDREC_STYLE__
<!--Menu Item Area-->
<MENUITEM id="MENU_ID_SNDREC_SAVE_OPTION_PLAY" str="STR_GLOBAL_PREVIEW" />
<MENUITEM id="MENU_ID_SNDREC_SAVE_OPTION_SAVE" str="STR_GLOBAL_SAVE" />
<MENUITEM id="MENU_ID_SNDREC_SAVE_OPTION_DISCARD" str="STR_GLOBAL_DISCARD" />

<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_SAVE_OPTION" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
	<MENUITEM_ID>MENU_ID_SNDREC_FORWARD_SEND</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_SAVE_OPTION_PLAY</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_SAVE_OPTION_SAVE</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_SAVE_OPTION_DISCARD</MENUITEM_ID>
</MENU>

#ifdef __MMI_MMS__
<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_SAVE_OPTION_SEND" parent="MENU_ID_SNDREC_SAVE_OPTION" str="STR_GLOBAL_SEND" img="0"/>
#endif /* __MMI_MMS__ */

<!--Menu Item Area-->
<MENUITEM id="MENU_ID_SNDREC_SAVE_OPTION_RENAME_SAVE" str="STR_GLOBAL_DONE" />

<!--Menu Tree Area-->
<MENU id="MENU_ID_SNDREC_SAVE_OPTION_RENAME_OPTION" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
	<MENUITEM_ID>MENU_ID_SNDREC_SAVE_OPTION_RENAME_SAVE</MENUITEM_ID>
	<MENUITEM_ID>MENU_ID_SNDREC_OPTION_INPUT_METHOD</MENUITEM_ID>
</MENU>
#endif /* __MMI_OP12_SNDREC_STYLE__ */


#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
<MENU id=" MENU_ID_SNDREC_MAIN_PRE_LIST_MENUID" type="APP_SUB" str="STR_ID_SNDREC_MAIN">
        <MENUITEM id="MENU_ID_SNDREC_NEW_RECORD_ENTER" str="STR_ID_SNDREC_NEW_RECORD"/>
        <MENUITEM id="MENU_ID_SNDREC_MY_RECORDS_LIST" str="STR_ID_SNDREC_MY_RECORDS"></MENUITEM>
        <MENUITEM id="MENU_ID_SNDREC_SETTING_LIST" str="STR_GLOBAL_SETTINGS"></MENUITEM>
</MENU>
#endif


<!--Timer ID-->
<TIMER id="SNDREC_TIMER_FILELIST_SEEK"/>

    <SCREEN id="GRP_ID_SNDREC_START_BASE"/>    
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
 	<SCREEN id="GRP_ID_SNDREC_MAIN_PRE_LIST"/>
#endif
	<SCREEN id="GRP_ID_SNDREC_MAIN"/>
	<SCREEN id="GRP_ID_SNDREC_OPTION"/>
	<SCREEN id="GRP_ID_SNDREC_SETTING"/>
	<SCREEN id="GRP_ID_SNDREC_PLAYER"/>
	<SCREEN id="GRP_ID_SNDREC_CREATING"/>
	<SCREEN id="GRP_ID_SNDREC_RENAME"/>
#ifdef __MMI_OP12_SNDREC_STYLE__	
	<SCREEN id="GRP_ID_SNDREC_AUDIO_SAVE_OPTION"/>
	<SCREEN id="GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME"/>
	<SCREEN id="GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION"/>
#endif	
	<SCREEN id="SCR_ID_SNDREC_MAIN"/>
	<SCREEN id="SCR_ID_SNDREC_OPTION"/>
	<SCREEN id="SCR_ID_SNDREC_SETTING"/>
	<SCREEN id="SCR_ID_SNDREC_PLAYER"/>
	<SCREEN id="SCR_ID_SNDREC_CREATING"/>
	<SCREEN id="SCR_ID_SNDREC_DELETE_ANIMATION"/>
#ifdef __MMI_OP12_SNDREC_STYLE__
	<SCREEN id="SCR_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION"/>
#endif

/*
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_sound_recorder_notify_hdlr"/>
#endif
*/
#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_fmgr_sound_recorder_def_storage_hdlr"/>
#endif

	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_sound_recorder_notify_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_sndrec_gpio_event_notify_handler"/>
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
	<RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_sndrec_scrlocker_event_notify_handler"/>
#endif
#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_A2DP_CONNECT" proc="mmi_sndrec_a2dp_connect_callback_hdlr"/>
#endif

/*   
    <CACHEDATA type="byte" id="NVRAM_SNDREC_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SNDREC_STORAGE] </DEFAULT_VALUE>
        <DESCRIPTION> Sound recorder - storage </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SNDREC_FORMAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SNDREC_FORMAT] </DEFAULT_VALUE>
        <DESCRIPTION> Sound recorder - format </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_SNDREC_QUALITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SNDREC_QUALITY] </DEFAULT_VALUE>
        <DESCRIPTION> Sound recorder - quality </DESCRIPTION>
    </CACHEDATA> */
 //#ifdef __VM_CODEC_SUPPORT__	   
    <CACHEDATA type="byte" id="NVRAM_AUTO_VM_SETTING_VM_SUPPORT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Sound recorder - vm support </DESCRIPTION>
    </CACHEDATA>

  //#endif
 
<RECEIVER id="EVT_ID_SRV_PROF_IS_PLAYING" proc="mmi_sound_recorder_broadcast_event_callback_hdlr"/>

</APP>
<FILE_TYPES>
    <FILE_TYPE_INC file="mmi_rp_app_soundrecorder_def.h"/>   
	<FILE_OPTION_HDLR option="MENU_ID_SNDREC_REC_OPTION" enabler="mmi_sndrec_option_enabler"/>
</FILE_TYPES>
#endif /* defined(__MMI_SOUND_RECORDER__) */
