/*Needed header files of the compile option in XML files */
#include "mmi_features.h"
#include "CustResDef.h"         /* for image/audio path */
#include "custom_mmi_default_value.h"
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_BT_MUSIC"
#if defined(__MMI_BT_MUSIC__) && defined(__MMI_APP_MANAGER_SUPPORT__)
        package_name = "native.mtk.audioplayerbt"         /* Use "native.mtk." as the prefix of application name */
        name = "STR_ID_AUDPLY_BT_TITLE"                    /* The string to be displayed under the main menu icon */
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
        img = "IMG_ID_AUDPLY_VUI_MAIN_MENU_APP_ICON"   /* Main menu icon image */
#endif
        launch = "mmi_bt_music_entry_main"               
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>

	  <STRING id="STR_ID_AUDPLY_BT_TITLE"/>
	  
	  
	  
    #if defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
    <IMAGE id="IMG_ID_AUDPLY_BT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\AudioPlayer\\\\SB_AudioPlayer.bmp"</IMAGE>
    #elif defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id="IMG_ID_AUDPLY_BT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\\AUDIOPLAYER\\\\SB_AudioPlayer.bmp"</IMAGE>
    #else
    <IMAGE id="IMG_ID_AUDPLY_BT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\AudioPlayer\\\\SB_AudioPlayer.bmp"</IMAGE>
    #endif
      
    <!--Menu Tree Area-->
    <MENU id="MAIN_MENU_BT_MUSIC_APP_MENUID" parent="MAIN_MENU_MULTIMEDIA_MENUID" str="STR_ID_AUDPLY_BT_TITLE" img="IMG_ID_AUDPLY_BT_ICON " highlight="HighlightAudioPlayerBt"
    shortcut="ON" shortcut_img="IMG_ID_AUDPLY_BT_ICON" launch="mmi_bt_music_entry_main"/>

		<SCREEN id="GRP_ID_BT_MUSIC_MAIN"/>
		<SCREEN id="GRP_ID_BT_CONNECT_MAIN"/>

</APP>
