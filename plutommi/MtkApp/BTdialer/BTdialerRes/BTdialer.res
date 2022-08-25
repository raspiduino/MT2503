#include "MMI_features.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>
/* Needed header files of the compile option in XML files, if you need others need to add here */

/* APP tag, include your app name defined in MMIDataType.h */
#ifndef __MMI_BT_DIALER_SUPPORT__
<APP id="APP_BT_DIALER"
>
</APP>  
#endif 

#ifdef __MMI_BT_DIALER_SUPPORT__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BT_DIALER" 
#if defined(__MMI_APP_MANAGER_SUPPORT__)
     package_name = "native.mtk.btdialer"             /* Use "native.mtk." as the prefix of application name */
     name = "@OID:STR_ID_BT_DIALER_TITLE"                 /* The string to be displayed under the main menu icon */
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
     img = "IMG_ID_BT_DIALER_ICON"            /* Main menu icon image */                  /* Application will be default shown on the main menu (if not defining this tag).
* If your application is not expected to be displayed on main menu, you have to define this tag.
*/
#endif
     launch = "mmi_btdialer_app_launch_func"   /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
 * the function prototype should be:
 *
*    typedef MMI_ID (*mmi_btdialer_app_launch_func) (void* param, U32 param_size);
*
 * Note that the group_id of the application should be returned if launch successfully.
 * If the application could not be launched for some reason, GRP_ID_INVALID should be returned.
 */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can file the ID */
    <!--Include Area--> 
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_all_defs.h"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of CUST_IMG_PATH"" */
    /* Image ID's Start */
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    <IMAGE id="IMG_ID_BT_DIALER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherAppList\\\\MainMenu\\\\BT_DIALER.png"</IMAGE>
    #endif
#endif /*__MMI_APP_MANAGER_SUPPORT__*/	

    /* please add all screen IDs below this line */
	<SCREEN id="SCR_ID_BT_DIALER"/>

	<!-----------------BT Dialer Service Events begin--------------------------------------------------->
    <EVENT id="EVT_ID_DIALER_EVENT_ID" type="SENDER"/>
    <EVENT id="EVT_ID_BT_DIALER_DISCONN_EVENT_ID" type="SENDER"/>
    <EVENT id="EVT_ID_DIALER_EVENT_ALL_CALL_END_ID" type="SENDER"/>
#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
    <EVENT id="EVT_ID_BT_DIALER_ACL_DISCONN_EVENT_ID" type="SENDER"/>
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/
	
#ifdef __MMI_BT_SPEAKER_SUPPORT__	

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
	<STRING id="STR_ID_BT_SPEAKER_TITLE_MESSAGE"/>
		<STRING id="STR_ID_BT_DIALER_TITLE"/>
    /* String ID's Start */
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of CUST_IMG_PATH"" */


    /* Image ID's Start */
	/*
    <IMAGE id="IMG_ID_BT_SPEAKER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_HOME.bmp"</IMAGE>
	<IMAGE id="BT_SPEAKER_TITLE_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_HOME.bmp"</IMAGE>
	*/
	#ifdef __MMI_FTE_SUPPORT__
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_HIGHLIGHT_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>
	#else /*__MMI_FTE_SUPPORT__*/
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.bmp"</IMAGE>
	<IMAGE id="IMG_ID_BT_MAIN_SKIN1_HIGHLIGHT_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\highlight.9slice.png"</IMAGE>
	#endif /*__MMI_FTE_SUPPORT__*/
	
	/* please add all screen IDs below this line */
	<SCREEN id="GRP_ID_BT_SPEAKER"/>
    <SCREEN id="SCR_ID_BT_SPEAKER"/>
	<SCREEN id="SCR_ID_BT_SPEAKER_REFRESH_SCREEN"/>
	
<!----------------------------------------------------------------------------------------
******** MISC section 
------------------------------------------------------------------------------------------>
    <CACHEDATA type="byte" id="NVRAM_BT_SPEAKER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X03] </DEFAULT_VALUE>
        <DESCRIPTION>BT Speaker</DESCRIPTION>
    </CACHEDATA>
	
    <!-----------------BTSCO Service Timer begin--------------------------------------------------->
    <TIMER id="BT_AVRCP_CT_CMD_FRAME_TIMEOUT"/>	
	<TIMER id="BT_A2DP_SINK_STREAM_START_TIMER"/>	
	<TIMER id="BT_SPEAKER_LOADING_SCREEN_TIMER"/>	
#endif /*__MMI_BT_SPEAKER_SUPPORT__*/	
</APP>    
#endif  /*  __MMI_BT_DIALER_SUPPORT__  */



