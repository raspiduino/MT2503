/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_AUTO_ANSWER_MACHINE__)
<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_AUTOAM">


    <!--Include Area-->    
    <INCLUDE file="GlobalResDef.h,ExtraResDef.h,mmi_rp_app_filemanager_def.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <!---String ID of you Application, we will get string from ref_list.txt for all languages--->     
	<STRING id="STR_ID_AUTOAM_APP"/>
	<STRING id="STR_ID_AUTOAM_LEAVING_MESSAGE"/>
	<STRING id="STR_ID_AUTOAM_RECORD_INCALL_TMP"/>
	<STRING id="STR_ID_AUTOAM_INFO"/>
	<STRING id="STR_ID_AUTOAM_PROTECT"/>
	<STRING id="STR_ID_AUTOAM_UNPROTECT"/>
	<STRING id="STR_ID_AUTOAM_AUTO_ANSWER_SWITCH"/>
	<STRING id="STR_ID_AUTOAM_STORAGE_PHONE"/>
	<STRING id="STR_ID_AUTOAM_STORAGE_CARD"/>
	<STRING id="STR_ID_AUTOAM_PICKUP"/>
	<STRING id="STR_ID_AUTOAM_DURATION"/>
	<STRING id="STR_ID_AUTOAM_GREETING_FILE"/>
	<STRING id="STR_ID_AUTOAM_REMOTE_SETTING"/>
	<STRING id="STR_ID_AUTOAM_REMOTE_SATUS"/>
	<STRING id="STR_ID_AUTOAM_REMOTE_ACCESS"/>
	<STRING id="STR_ID_AUTOAM_REMOTE_HOT_KEY"/>
	<STRING id="STR_ID_AUTOAM_REMOTE_ERROR_RESET"/>
	<STRING id="STR_ID_AUTOAM_RECORD"/>
	<STRING id="STR_ID_AUTOAM_SELECT"/>
	<STRING id="STR_ID_AUTOAM_PICKUP_THREE_SEC"/>
	<STRING id="STR_ID_AUTOAM_PICKUP_FIVE_SEC"/>
	<STRING id="STR_ID_AUTOAM_PICKUP_TEN_SEC"/>
	<STRING id="STR_ID_AUTOAM_PICKUP_THIRTY_SEC"/>
	<STRING id="STR_ID_AUTOAM_PICKUP_ONE_MINUTE"/>
	<STRING id="STR_ID_AUTOAM_DURATION_THIRTY_SEC"/>
	<STRING id="STR_ID_AUTOAM_DURATION_ONE_MINUTE"/>
	<STRING id="STR_ID_AUTOAM_DURATION_THREE_MINUTE"/>
	<STRING id="STR_ID_AUTOAM_DURATION_FIVE_MINUTE"/>
	<STRING id="STR_ID_AUTOAM_DURATION_UN_LIMIT"/>
	<STRING id="STR_ID_AUTOAM_FILENAME_TOO_LONG"/>
	<STRING id="STR_ID_AUTOAM_GREETING_DEFAULT"/>
	<STRING id="STR_ID_AUTOAM_GREETING_FROM_FILE"/>
	<STRING id="STR_ID_AUTOAM_GREETING"/>
	<STRING id="STR_ID_AUTOAM_LSK_ANSWER"/>
	<STRING id="STR_ID_AUTOAM_RSK_HANDS_FREE"/>
	<STRING id="STR_ID_AUTOAM_RSK_HANDS_HELD"/>
	<STRING id="STR_ID_AUTOAM_LOUD_SPEAKER_ON"/>
	<STRING id="STR_ID_AUTOAM_LOUD_SPEAKER_OFF "/>
	<STRING id="STR_ID_AUTOAM_MISSED_MSG"/>
	<STRING id="STR_ID_AUTOAM_PASSWD_ERROR"/>
	<STRING id="STR_ID_AUTOAM_HOTKEY_ERROR"/>
	<STRING id="STR_ID_AUTOAM_INFO_NAME"/>
	<STRING id="STR_ID_AUTOAM_INFO_NUMBER"/>
	<STRING id="STR_ID_AUTOAM_INFO_TIME"/>
	<STRING id="STR_ID_AUTOAM_INFO_DURATION"/>
	<STRING id="STR_ID_AUTOAM_INFO_SECONDS"/>
	<STRING id="STR_ID_AUTOAM_INFO_SECOND"/>
	<STRING id="STR_ID_AUTOAM_INFO_NO_NUMBER"/>
	<STRING id="STR_ID_AUTOAM_DELETE_ASK"/>
	<STRING id="STR_ID_AUTOAM_DELETE_ALL_ASK"/>
	<STRING id="STR_ID_AUTOAM_NO_CARD"/>
	<STRING id="STR_ID_AUTOAM_SECOND_SHORT"/>
	<STRING id="STR_ID_AUTOAM_INVALID_FILE"/>
	<STRING id="STR_ID_AUTOAM_OPEN_FILE_FAIL"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
   <TIMER id="AUTOAM_TIMER_KEY_DETECT"/>

	<IMAGE id="IMG_ID_AUTOAM_APP">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\SB_AutoAnswerMachine.bmp"</IMAGE>
	#if defined(__MMI_MAINLCD_320X480__)
	<IMAGE id="IMG_ID_AUTOAM_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_BackGround.png"</IMAGE>	
	<IMAGE id="IMG_ID_AUTOAM_GREETING">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_Greeting.png"</IMAGE>
	#else
	<IMAGE id="IMG_ID_AUTOAM_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_BackGround.gif"</IMAGE>
	<IMAGE id="IMG_ID_AUTOAM_GREETING">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_Greeting.gif"</IMAGE>
	#endif
	<IMAGE id="IMG_ID_AUTOAM_MESSAGE_READ">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_Read.bmp"</IMAGE>
	<IMAGE id="IMG_ID_AUTOAM_MESSAGE_UNREAD">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_Unread.bmp"</IMAGE>
	<IMAGE id="IMG_ID_AUTOAM_MESSAGE_READ_PROTECT">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_read_Protect.bmp"</IMAGE>
	<IMAGE id="IMG_ID_AUTOAM_MESSAGE_UNREAD_PROTECT">CUST_IMG_PATH"\\\\MainLCD\\\\AnswerMachine\\\\AUTOAM_Unread_Protect.bmp"</IMAGE>


    /* For the detail of scope="XML" please check user manual */

  <!------------------------------------------------------Audio Resource Area------------------------------------------------------>

	<AUDIO id="AUD_ID_AUTOAM_DI_TONE">CUST_ADO_PATH"\\\\AnswerMachine\\\\Di_tone.wav"</AUDIO>	
	<AUDIO id="AUD_ID_LANGUAGE_DEFAULT_BEGIN">CUST_ADO_PATH"\\\\AnswerMachine\\\\dummy.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_GREETING_DEFAULT_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Greeting.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_1MIN_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\1Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_3MIN_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\3Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_5MIN_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\5Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_30SCD_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\30scd.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_TIMEOUT_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\TimeOut.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_DISCFULL_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\DiscFull.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_GOODBYE_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Bye.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_LOGIN_GREETING_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Input_PW.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_LOGIN_PASSWD_ERROR_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Retry_PW.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_GREETING_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Remote.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_NO_NEW_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\No_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_PLAY_UNREAD_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Play_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_UNREAD_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Repaly_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_ONE_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Replay_one.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_ALL_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Replay_all.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_PLAY_END_DEF">CUST_ADO_PATH"\\\\AnswerMachine\\\\English\\\\Play_over.wav"</AUDIO>

	<AUDIO id="AUD_ID_LANGUAGE_1_BEGIN">CUST_ADO_PATH"\\\\AnswerMachine\\\\dummy.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_GREETING_DEFAULT_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Greeting.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_1MIN_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\1Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_3MIN_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\3Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_5MIN_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\5Min.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_HINT_TIME_30SCD_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\30scd.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_TIMEOUT_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\TimeOut.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_DISCFULL_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\DiscFull.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_GOODBYE_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Bye.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_LOGIN_GREETING_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Input_PW.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_LOGIN_PASSWD_ERROR_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Retry_PW.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_GREETING_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Remote.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_NO_NEW_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\No_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_PLAY_UNREAD_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Play_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_UNREAD_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Repaly_UnRead.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_ONE_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Replay_one.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_REPLAY_ALL_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Replay_all.wav"</AUDIO>
	<AUDIO id="AUD_ID_AUTOAM_REMOTE_PLAY_END_1">CUST_ADO_PATH"\\\\AnswerMachine\\\\Chinese\\\\Play_over.wav"</AUDIO>
   
    <!------------------------------------------------------ Screen Ids Area ---------------------------------------------------------->
    
    <SCREEN id = "GRP_ID_AUTOAM_SAVE_PHB_ENTRY"/>
    <SCREEN id = "GRP_ID_AUTOAM_MAIN_ON_IDLE_SCRN"/>
    <SCREEN id = "GRP_ID_AUTOAM_MAIN"/>
    <SCREEN id = "GRP_ID_AUTOAM_VOICE_MESSAGE_OPTION"/>
    <SCREEN id = "GRP_ID_AUTOAM_GREETTING_EMPRY_FOLDER_OPTION"/>
    <SCREEN id = "GRP_ID_AUTOAM_GREETTING_FILE_CHOOSE"/>   
    <SCREEN id = "GRP_ID_AUTOAM_SETTINGS"/>
    <SCREEN id = "GRP_ID_AUTOAM_EDIT_REMOTE_SETTING"/>
    <SCREEN id="GRP_ID_AUTOAM_MAIN"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_OPTION"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_DETAIL"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_DELETE_ANIMATION"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_DELETE_ALL_ANIMATION"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_PLAY"/>
    <SCREEN id="GRP_ID_AUTOAM_SETTING"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING_CHOOSE"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING_DEFAULT_LIST"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING_FILE_LIST"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING_FILE_LIST_OPTION"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING_CHOOSE_STORAGE"/>
    <SCREEN id="GRP_ID_AUTOAM_REMOTE_SETTING"/>
    <SCREEN id="GRP_ID_AUTOAM_GREETING"/>
    <SCREEN id="GRP_ID_AUTOAM_RECORD_VOICE_MESSAGE"/>
    <SCREEN id="GRP_ID_AUTOAM_REMOTE_ACCESS"/>
    <SCREEN id="GRP_ID_AUTOAM_MESSAGE_SELECT_DRV"/>
    <SCREEN id="GRP_ID_AUTOAM_MSG_WAITING"/> 
    <SCREEN id="SCR_ID_AUTOAM_MAIN"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_OPTION"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_DETAIL"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_DELETE_ANIMATION"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_DELETE_ALL_ANIMATION"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_PLAY"/>
    <SCREEN id="SCR_ID_AUTOAM_SETTING"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING_CHOOSE"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING_DEFAULT_LIST"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING_FILE_LIST"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING_FILE_LIST_OPTION"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING_CHOOSE_STORAGE"/>
    <SCREEN id="SCR_ID_AUTOAM_REMOTE_SETTING"/>
    <SCREEN id="SCR_ID_AUTOAM_GREETING"/>
    <SCREEN id="SCR_ID_AUTOAM_RECORD_VOICE_MESSAGE"/>
    <SCREEN id="SCR_ID_AUTOAM_REMOTE_ACCESS"/>
    <SCREEN id="SCR_ID_AUTOAM_MESSAGE_SELECT_DRV"/>
    <SCREEN id="SCR_ID_AUTOAM_MSG_WAITING"/>

   <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

	<MENUITEM id = "MENU_ID_AUTOAM_LEAVING_MESSAGE" str="STR_ID_AUTOAM_LEAVING_MESSAGE" img="IMG_GLOBAL_L1" />
	<MENUITEM id = "MENU_ID_AUTOAM_SETTING" str="STR_GLOBAL_SETTINGS" img="IMG_GLOBAL_L2" />
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_PLAY" str="STR_GLOBAL_PLAY" img="IMG_GLOBAL_L1"/>
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_INFO" str="STR_GLOBAL_DETAILS" img="IMG_GLOBAL_L2"/>
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_DIAL" str="STR_GLOBAL_DIAL" img="IMG_GLOBAL_L3" />
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_SAVE_TO_PBK" str="STR_GLOBAL_SAVE_TO_PHONEBOOK" img="IMG_GLOBAL_L4" />
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_DELETE" str="STR_GLOBAL_DELETE" img="IMG_GLOBAL_L5" />
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" img="IMG_GLOBAL_L6" />
	<MENUITEM id = "MENU_ID_AUTOAM_MESSAGE_OPTION_PROTECT" str="STR_ID_AUTOAM_PROTECT" img="IMG_GLOBAL_L7" />
	<MENUITEM id = "MENU_ID_AUTOAM_GREETTING_FILE_OPTION_PLAY" str="STR_GLOBAL_PLAY"/>
	<MENUITEM id = "MENU_ID_AUTOAM_GREETTING_FILE_OPTION_SELECT" str="STR_ID_AUTOAM_SELECT"/>
	<MENUITEM id = "MENU_ID_AUTOAM_GREETTING_FILE_OPTION_RECORD" str="STR_ID_AUTOAM_RECORD"/>
	<MENUITEM id = "MENU_ID_AUTOAM_GREETTING_FILE_CHOOSE_DEFAULT" str="STR_GLOBAL_DEFAULT" img="IMG_GLOBAL_L1" />
	<MENUITEM id = "MENU_ID_AUTOAM_GREETTING_FILE_CHOOSE_FROM_FILE" str="STR_ID_AUTOAM_GREETING_FROM_FILE" img="IMG_GLOBAL_L2" />


  	 <MENU id = "MENU_ID_AUTOAM_MAIN" type= "APP_SUB" str="STR_ID_AUTOAM_APP" img="IMG_ID_AUTOAM_APP" highlight="mmi_autoam_highlight_main">
            <MENUITEM_ID> MENU_ID_AUTOAM_LEAVING_MESSAGE</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_SETTING</MENUITEM_ID>
  	</MENU>

  	<MENU id = "MENU_ID_AUTOAM_MESSAGE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_ID_AUTOAM_APP" >
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_PLAY</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_INFO</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_DIAL</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_SAVE_TO_PBK</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_DELETE</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_DELETE_ALL</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_MESSAGE_OPTION_PROTECT</MENUITEM_ID>             
  	</MENU>

      	<MENU id = "MENU_ID_AUTOAM_GREETTING_FILE_OPTION"  type="OPTION"  str="@OID:STR_GLOBAL_OPTIONS" img="IMG_ID_AUTOAM_APP">
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_OPTION_PLAY</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_OPTION_SELECT</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_OPTION_RECORD</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>            
            <MENUITEM_ID> MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>                        
  	</MENU>

    
      	<MENU id = "MENU_ID_AUTOAM_GREETTING_EMPRY_FOLDER_OPTION"  type="OPTION" str="@OID:STR_GLOBAL_OPTIONS" img="IMG_ID_AUTOAM_APP">
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_OPTION_RECORD</MENUITEM_ID>                             
  	</MENU>
  	
       <MENU id = "MENU_ID_AUTOAM_GREETTING_FILE_CHOOSE" str="@OID:STR_GLOBAL_SELECT" img="IMG_ID_AUTOAM_APP">
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_CHOOSE_DEFAULT</MENUITEM_ID>
            <MENUITEM_ID> MENU_ID_AUTOAM_GREETTING_FILE_CHOOSE_FROM_FILE</MENUITEM_ID>                        
  	</MENU>

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_autoam_def_storage_hdlr"/>
#endif
	<RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_autoam_answer_update_statusicon"/>

<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_autoam_answer_memory_card_change"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_autoam_answer_memory_card_change"/>    

   
</APP>

#endif