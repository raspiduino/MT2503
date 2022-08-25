#if 0
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GLOBALDEFS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    //<INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_GLOBAL_0">"0"</STRING>
    <STRING id="STR_GLOBAL_1">"1"</STRING>
    <STRING id="STR_GLOBAL_2">"2"</STRING>
    <STRING id="STR_GLOBAL_3">"3"</STRING>
    <STRING id="STR_GLOBAL_4">"4"</STRING>
    <STRING id="STR_GLOBAL_5">"5"</STRING>
    <STRING id="STR_GLOBAL_6">"6"</STRING>
    <STRING id="STR_GLOBAL_7">"7"</STRING>
    <STRING id="STR_GLOBAL_8">"8"</STRING>
    <STRING id="STR_GLOBAL_9">"9"</STRING>
    <STRING id="STR_GLOBAL_10">"10"</STRING>

    <STRING id="STR_GLOBAL_ABORT"/>
    <STRING id="STR_GLOBAL_ABORTING"/>
    <STRING id="STR_GLOBAL_ACCEPT"/>
    <STRING id="STR_GLOBAL_ACCOUNTS"/>
    <STRING id="STR_GLOBAL_ACTIVATE"/>
    <STRING id="STR_GLOBAL_ACTIVATED"/>
    <STRING id="STR_GLOBAL_ADD"/>
    <STRING id="STR_GLOBAL_ADDRESS"/>
    <STRING id="STR_GLOBAL_ALARM"/>
    <STRING id="STR_GLOBAL_AS_EMAIL"/>
    <STRING id="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
    <STRING id="STR_GLOBAL_AS_TEXT_MESSAGE"/>
    <STRING id="STR_GLOBAL_ATTACHMENT"/>
    <STRING id="STR_GLOBAL_AUTHENTICATION"/>
    <STRING id="STR_GLOBAL_AUTOMATIC"/>
    <STRING id="STR_GLOBAL_BACK"/>
    <STRING id="STR_GLOBAL_BUSY_TRY_LATER"/>
    <STRING id="STR_GLOBAL_CANCEL"/>
    <STRING id="STR_GLOBAL_CANCELLING"/>
    <STRING id="STR_GLOBAL_CLEAR"/>
    <STRING id="STR_GLOBAL_CLOSE"/>
    <STRING id="STR_GLOBAL_CONFIRM"/>
    <STRING id="STR_GLOBAL_CONNECT"/>
    <STRING id="STR_GLOBAL_CONNECTING"/>
    <STRING id="STR_GLOBAL_CONTENT"/>
    <STRING id="STR_GLOBAL_CONTINUE"/>
    <STRING id="STR_GLOBAL_COPYING"/>
    <STRING id="STR_GLOBAL_CURRENTLY_NOT_AVAILABLE"/>
    <STRING id="STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL"/>
    <STRING id="STR_GLOBAL_CUSTOM"/>
    <STRING id="STR_GLOBAL_DATA_ACCOUNT"/>
    <STRING id="STR_GLOBAL_DATE"/>
    <STRING id="STR_GLOBAL_DEACTIVATE"/>
    <STRING id="STR_GLOBAL_DEFAULT"/>
    <STRING id="STR_GLOBAL_DELETE"/>
    <STRING id="STR_GLOBAL_DELETE_ALL"/>
    <STRING id="STR_GLOBAL_DELETED"/>
    <STRING id="STR_GLOBAL_DELETING"/>
    <STRING id="STR_GLOBAL_DETAILS"/>
    <STRING id="STR_GLOBAL_DIALLED_CALLS"/>
    <STRING id="STR_GLOBAL_DIAL"/>
    <STRING id="STR_GLOBAL_DISCARD"/>
    <STRING id="STR_GLOBAL_DISCONNECT"/>
    <STRING id="STR_GLOBAL_DISCONNECTING"/>
    <STRING id="STR_GLOBAL_DONE"/>
    <STRING id="STR_GLOBAL_DOWNLOAD"/>
    <STRING id="STR_GLOBAL_DOWNLOAD_ASK"/>
    <STRING id="STR_GLOBAL_DOWNLOADING"/>
    <STRING id="STR_GLOBAL_DRAFTS"/>
    <STRING id="STR_GLOBAL_DRM_FILE_EXISTS"/>
    <STRING id="STR_GLOBAL_DRM_FS_ERROR"/>
    <STRING id="STR_GLOBAL_DRM_INVALID_FORMAT"/>
    <STRING id="STR_GLOBAL_DRM_NON_DRM"/>
    <STRING id="STR_GLOBAL_DRM_PROCESSING"/>
    <STRING id="STR_GLOBAL_DRM_PROHIBITED"/>
    <STRING id="STR_GLOBAL_DRM_RO_RECEIVED"/>
    <STRING id="STR_GLOBAL_DRM_SIZE_TOO_BIG"/>
    <STRING id="STR_GLOBAL_EARPHONE_IN"/>
    <STRING id="STR_GLOBAL_EARPHONE_OUT"/>
    <STRING id="STR_GLOBAL_EDIT"/>
    <STRING id="STR_GLOBAL_EMAIL"/>
    <STRING id="STR_GLOBAL_EMPTY"/>
    <STRING id="STR_GLOBAL_EMPTY_LIST"/>
    <STRING id="STR_GLOBAL_ERROR"/>
    <STRING id="STR_GLOBAL_EXIT"/>
    <STRING id="STR_GLOBAL_FAILED_TO_SAVE"/>
    <STRING id="STR_GLOBAL_FAILED_TO_SEND"/>
    <STRING id="STR_GLOBAL_FAST"/>
    <STRING id="STR_GLOBAL_FILE_ALREADY_EXISTS"/>
    <STRING id="STR_GLOBAL_FILE_NOT_FOUND"/>
    <STRING id="STR_GLOBAL_FILENAME"/>
    <STRING id="STR_GLOBAL_FORMAT"/>
    <STRING id="STR_GLOBAL_FORWARD"/>
    <STRING id="STR_GLOBAL_GO_TO"/>
    <STRING id="STR_GLOBAL_GPRS"/>
    <STRING id="STR_GLOBAL_GSM"/>
    <STRING id="STR_GLOBAL_HELP"/>
    <STRING id="STR_GLOBAL_HIGH"/>
    <STRING id="STR_GLOBAL_HTTP"/>
    <STRING id="STR_GLOBAL_INBOX"/>
    <STRING id="STR_GLOBAL_INPUT_METHOD"/>
    <STRING id="STR_GLOBAL_INSTALL"/>
    <STRING id="STR_GLOBAL_INSUFFICIENT_MEMORY"/>
    <STRING id="STR_GLOBAL_INVALID"/>
    <STRING id="STR_GLOBAL_INVALID_DATA_ACCOUNT"/>
    <STRING id="STR_GLOBAL_INVALID_EMAIL_ADDRESS"/>
    <STRING id="STR_GLOBAL_INVALID_EMAIL_ADDRESSES"/>
    <STRING id="STR_GLOBAL_INVALID_FILENAME"/>
    <STRING id="STR_GLOBAL_INVALID_FORMAT"/>
    <STRING id="STR_GLOBAL_INVALID_INPUT"/>
    <STRING id="STR_GLOBAL_INVALID_NUMBER"/>
    <STRING id="STR_GLOBAL_INVALID_NUMBERS"/>
    <STRING id="STR_GLOBAL_INVALID_RECIPIENTS"/>
    <STRING id="STR_GLOBAL_INVALID_URL"/>
    <STRING id="STR_GLOBAL_LIST"/>
    <STRING id="STR_GLOBAL_LOADING"/>
    <STRING id="STR_GLOBAL_LOGIN"/>
    <STRING id="STR_GLOBAL_LOGO"/>
    <STRING id="STR_GLOBAL_LOGOUT"/>
    <STRING id="STR_GLOBAL_LOW"/>
    <STRING id="STR_GLOBAL_MANUAL"/>
    <STRING id="STR_GLOBAL_MARK"/>
    <STRING id="STR_GLOBAL_MARK_ALL"/>
    <STRING id="STR_GLOBAL_MAXIMUM"/>
    <STRING id="STR_GLOBAL_MEDIUM"/>
    <STRING id="STR_GLOBAL_MEMORY_CARD"/>
    <STRING id="STR_GLOBAL_MEMORY_FULL"/>
    <STRING id="STR_GLOBAL_MEMORY_STATUS"/>
    <STRING id="STR_GLOBAL_MISSED_CALLS"/>
    <STRING id="STR_GLOBAL_MOVING"/>
    <STRING id="STR_GLOBAL_MULTIMEDIA_MESSAGE"/>
    <STRING id="STR_GLOBAL_MUTE"/>
    <STRING id="STR_GLOBAL_NO"/>
    <STRING id="STR_GLOBAL_NO_MEMORY_CARD"/>
    <STRING id="STR_GLOBAL_NONE"/>
    <STRING id="STR_GLOBAL_NORMAL"/>
    <STRING id="STR_GLOBAL_NOT_AVAILABLE"/>
    <STRING id="STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL"/>
    <STRING id="STR_GLOBAL_NOT_ENOUGH_MEMORY"/>
    <STRING id="STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR"/>
    <STRING id="STR_GLOBAL_NOT_SUPPORTED"/>
    <STRING id="STR_GLOBAL_OFF"/>
    <STRING id="STR_GLOBAL_OK"/>
    <STRING id="STR_GLOBAL_ON"/>
    <STRING id="STR_GLOBAL_OPEN"/>
    <STRING id="STR_GLOBAL_OPTIONS"/>
    <STRING id="STR_GLOBAL_OUTBOX"/>
    <STRING id="STR_GLOBAL_OVERWRITE_EXISTING_FILE"/>
    <STRING id="STR_GLOBAL_PASSWORD"/>
    <STRING id="STR_GLOBAL_PAUSE"/>
    <STRING id="STR_GLOBAL_PHONE"/>
    <STRING id="STR_GLOBAL_PICTURE"/>
    <STRING id="STR_GLOBAL_PLAY"/>
    <STRING id="STR_GLOBAL_PLEASE_WAIT"/>
    <STRING id="STR_GLOBAL_PLEASE_INPUT_THE_FILENAME"/>
    <STRING id="STR_GLOBAL_PREFERRED_STORAGE"/>
    <STRING id="STR_GLOBAL_PREVIEW"/>
    <STRING id="STR_GLOBAL_PRINT"/>
    <STRING id="STR_GLOBAL_PRIORITY"/>
    <STRING id="STR_GLOBAL_PROXY"/>
    <STRING id="STR_GLOBAL_QUIT"/>
    <STRING id="STR_GLOBAL_READ"/>
    <STRING id="STR_GLOBAL_RECEIVED"/>
    <STRING id="STR_GLOBAL_RECEIVED_CALLS"/>
    <STRING id="STR_GLOBAL_RECEIVING"/>
    <STRING id="STR_GLOBAL_RECIPIENTS"/>
    <STRING id="STR_GLOBAL_REFRESH"/>
    <STRING id="STR_GLOBAL_REMOVE"/>
    <STRING id="STR_GLOBAL_REMOVED"/>
    <STRING id="STR_GLOBAL_RENAME"/>
    <STRING id="STR_GLOBAL_REPLACE"/>
    <STRING id="STR_GLOBAL_REPLY"/>
    <STRING id="STR_GLOBAL_RESEND"/>
    <STRING id="STR_GLOBAL_RESET"/>
    <STRING id="STR_GLOBAL_RESUME"/>
    <STRING id="STR_GLOBAL_RINGTONE"/>
    <STRING id="STR_GLOBAL_SAVE"/>
    <STRING id="STR_GLOBAL_SAVE_ASK"/>
    <STRING id="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>
    <STRING id="STR_GLOBAL_SAVED"/>
    <STRING id="STR_GLOBAL_SAVING"/>
    <STRING id="STR_GLOBAL_SEARCH"/>
    <STRING id="STR_GLOBAL_SEARCHING"/>
    <STRING id="STR_GLOBAL_SELECT"/>
    <STRING id="STR_GLOBAL_SEND"/>
    <STRING id="STR_GLOBAL_SEND_MESSAGE"/>
    <STRING id="STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE"/>
    <STRING id="STR_GLOBAL_SEND_TEXT_MESSAGE"/>
    <STRING id="STR_GLOBAL_SENDING"/>
    <STRING id="STR_GLOBAL_SENT"/>
    <STRING id="STR_GLOBAL_SETTINGS"/>
    <STRING id="STR_GLOBAL_SIM"/>
    <STRING id="STR_GLOBAL_SLOW"/>
    <STRING id="STR_GLOBAL_SORT_BY"/>
    <STRING id="STR_GLOBAL_START"/>
    <STRING id="STR_GLOBAL_STOP"/>
    <STRING id="STR_GLOBAL_STORAGE"/>
    <STRING id="STR_GLOBAL_SUBJECT"/>
    <STRING id="STR_GLOBAL_SUBMIT"/>
    <STRING id="STR_GLOBAL_TEXT"/>
    <STRING id="STR_GLOBAL_TEXT_MESSAGE"/>
    <STRING id="STR_GLOBAL_TIME"/>
    <STRING id="STR_GLOBAL_UDP_PORT"/>
    <STRING id="STR_GLOBAL_UNFINISHED"/>
    <STRING id="STR_GLOBAL_UNMARK"/>
    <STRING id="STR_GLOBAL_UNMARK_ALL"/>
    <STRING id="STR_GLOBAL_UNSUPPORTED_FORMAT"/>
    <STRING id="STR_GLOBAL_UPDATE"/>
    <STRING id="STR_GLOBAL_URL"/>
    <STRING id="STR_GLOBAL_USE_TEMPLATE"/>
    <STRING id="STR_GLOBAL_USERNAME"/>
    <STRING id="STR_GLOBAL_VIA_BLUETOOTH"/>
    <STRING id="STR_GLOBAL_VIA_INFRARED"/>
    <STRING id="STR_GLOBAL_VIDEO"/>
    <STRING id="STR_GLOBAL_VIEW"/>
    <STRING id="STR_GLOBAL_VOLUME"/>
    <STRING id="STR_GLOBAL_WAP"/>
    <STRING id="STR_GLOBAL_YES"/>
    <STRING id="STR_GLOBAL_CLIPBOARD"/>
    <STRING id="STR_GLOBAL_INSERT_MEMORY_CARD"/>
    <STRING id="STR_GLOBAL_MC_REMOVED_USE_PHONE"/>
    <STRING id="STR_GLOBAL_MC_REMOVED"/>
    <STRING id="STR_GLOBAL_MC_INSERTED"/>
    <STRING id="STR_GLOBAL_OTG_REMOVED_USE_PHONE"/>
    <STRING id="STR_GLOBAL_OTG_REMOVED"/>
    <STRING id="STR_GLOBAL_OTG_CONNECTED"/>

	<STRING id="STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE"/>
	<STRING id="STR_GLOBAL_NO_NUMBER"/>
	ADD_APPLICATION_STRING2(STR_GLOBAL_NO_NUMBER, "No number", "Global String- No number" );

    <STRING id="STR_GLOBAL_SUNDAY"/>
    <STRING id="STR_GLOBAL_MONDAY"/>
    <STRING id="STR_GLOBAL_TUESDAY"/>
    <STRING id="STR_GLOBAL_WEDNESDAY"/>
    <STRING id="STR_GLOBAL_THURSDAY"/>
    <STRING id="STR_GLOBAL_FRIDAY"/>
    <STRING id="STR_GLOBAL_SATURDAY"/>
    <STRING id="STR_GLOBAL_SUNDAY_SHORT"/>
    <STRING id="STR_GLOBAL_MONDAY_SHORT"/>
    <STRING id="STR_GLOBAL_TUESDAY_SHORT"/>
    <STRING id="STR_GLOBAL_WEDNESDAY_SHORT"/>
    <STRING id="STR_GLOBAL_THURSDAY_SHORT"/>
    <STRING id="STR_GLOBAL_FRIDAY_SHORT"/>
    <STRING id="STR_GLOBAL_SATURDAY_SHORT"/>
    <STRING id="STR_GLOBAL_JANUARY_SHORT"/>
    <STRING id="STR_GLOBAL_FEBRUARY_SHORT"/>
    <STRING id="STR_GLOBAL_MARCH_SHORT"/>
    <STRING id="STR_GLOBAL_APRIL_SHORT"/>
    <STRING id="STR_GLOBAL_MAY_SHORT"/>
    <STRING id="STR_GLOBAL_JUNE_SHORT"/>
    <STRING id="STR_GLOBAL_JULY_SHORT"/>
    <STRING id="STR_GLOBAL_AUGEST_SHORT"/>
    <STRING id="STR_GLOBAL_SEPTEMBER_SHORT"/>
    <STRING id="STR_GLOBAL_OCTOBER_SHORT"/>
    <STRING id="STR_GLOBAL_NOVEMBER_SHORT"/>
    <STRING id="STR_GLOBAL_DECEMBER_SHORT"/>

    <STRING id="STR_GLOBAL_END"/>
    

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
        
    /* force ABM to speed up 6223 + QVGA */
#if (defined(MT6223) || defined(MT6223P)) && defined(__MMI_MAINLCD_240X320__)
    #define GLOBAL_FORCE_TYPE "FORCE_ABM"
#else
    #define GLOBAL_FORCE_TYPE "AUTO_TYPE"
#endif
    /* add an empty image icon */
    <IMAGE id="IMG_NONE" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>

    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_GLOBAL_L1" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB1.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L2" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB2.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L3" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB3.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L4" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB4.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L5" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB5.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L6" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB6.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L7" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB7.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L8" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB8.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L9" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB9.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L10" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB10.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L11" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB11.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L12" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB12.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L13" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB13.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L14" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB14.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L15" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB15.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L16" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB16.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L17" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB17.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L18" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB18.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L19" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB19.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L20" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB20.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L21" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB21.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L22" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB22.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L23" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB23.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L24" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB24.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L25" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB25.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L26" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB26.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L27" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB27.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L28" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB28.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L29" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB29.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_L30" force_type=GLOBAL_FORCE_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\ListMenuIcon\\\\L_NB30.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_OK" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_BACK" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_YES" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_NO" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_OPTIONS" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_CLEAR" >"..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_STATUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_STATU.bmp"</IMAGE>
    <IMAGE id="IMG_VICON" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp"</IMAGE>
    <IMAGE id="IMG_TIME" >CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_TIME.bmp"</IMAGE>
    <IMAGE id="IMG_REPEAT" >CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_REPT.bmp"</IMAGE>
    <IMAGE id="IMG_CAL" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\DateAndTime\\\\ST_CALEN.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_QUESTION" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_QUE"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_GLOBAL_SAVE" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_SAV"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_GLOBAL_DELETED" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_GLOBAL_WARNING" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_WARN"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id="IMG_GLOBAL_PROGRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_PRO"</IMAGE>  /* For SAT */
#else    
    <IMAGE id="IMG_GLOBAL_PROGRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_PRO"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
#endif    
    <IMAGE id="IMG_GLOBAL_DEFAULT" >"..\\\\..\\\\Customer\\\\Images\\\\Default.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_ERROR" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_ERR"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_GLOBAL_INFO" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_INF"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_EARPHONE_POPUP_SUBLCD" >CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_EAR.BMP"</IMAGE>
    <IMAGE id="IMG_GLOBAL_SUCCESS" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_SUC"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_GLOBAL_FAIL" >CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_FAIL"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>


    <IMAGE id="IMG_GLOBAL_CALL_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Call_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_COMMON_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Common_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_DIAL_PAD_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Dial_Pad_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_FORWARD_MSG_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Forward_Msg_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_MARK_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Mark_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_NEXT_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Next_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_OPTION_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Option_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_REPLY_MSG_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Reply_Msg_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_SAVE_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Save_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_SEARCH_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\SearchWeb_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_SEND_MSG_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Send_Msg_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_OPTION_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Common_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_WEB_BROWSER_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Web_Browser_CSK.bmp"</IMAGE>

    /* Remove these CSK icon after W10.17 - Start */
    <IMAGE id="IMG_GLOBAL_PHB_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Phonebook_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_SELECT_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Select_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_VIEW_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\View_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_READ_MSG_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Read_Msg_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_DOWNLOAD_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Download_CSK.bmp"</IMAGE>
    <IMAGE id="IMG_GLOBAL_BOOKMARK_CSK" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Bookmark_CSK.bmp"</IMAGE>
    /* Remove these CSK icon after W10.17 - End */

#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ADD_CONTACT" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_add_contact.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ADD_CONTACT_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_add_contact_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ADD" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_add_new.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ADD_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_add_new_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ATTACHMENT" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_attachment.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_ATTACHMENT_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_attachment_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_BOOKMARK" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_bookmark.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_BOOKMARK_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_bookmark_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_CALL" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_call.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_CALL_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_call_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_DELETE" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_delete.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_DELETE_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_delete_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_DETAIL" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_detail.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_DETAIL_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_detail_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_EDIT" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_edit_data.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_EDIT_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_edit_data_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_forward_message.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_forward_message_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_MEETING" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_meeting.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_MEETING_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_meeting_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_OPEN" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_open.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_OPEN_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_open_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_reply_message.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_reply_message_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_SEARCH" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_search.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_SEARCH_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_search_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_SEND_MESSAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_send_message.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_send_message_dis.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_WRITE_MESSAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_write_message.png"</IMAGE>
    <IMAGE id="IMG_GLOBAL_TOOLBAR_WRITE_MESSAGE_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\TB_write_message_dis.png"</IMAGE>
#endif /* __MMI_FTE_SUPPORT__ */

    <AUDIO id="ADO_GLOBAL_EMPTYAUDIO">"..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="ADO_GLOBAL_EMPTYAUDIO_EXT" flag="MULTIBIN">"..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="ADO_GLOBAL_NOAUDIO">"..\\\\..\\\\Customer\\\\Audio\\\\NoAudio.mp3"</AUDIO>
    <AUDIO id="ADO_GLOBAL_DEFAULT">"..\\\\..\\\\Customer\\\\Audio\\\\Default.mp3"</AUDIO>




    <!------------------------------------------------------Other Resource---------------------------------------------------------->



#endif


/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_FRM_INPUT_EVT__)
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/*please don't add other tags define to this file, only for INPUT_EVENT*/
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GLOBALDEFS">
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_INPUT_EVENT_APP_SWITCH" evt_desc="Switch App" key_code="KEY_2" key_type="KEY_LONG_PRESS"/>	
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_CHANGE_VISIBILITY" evt_desc="Change BTBOX Visibility" key_code="KEY_3" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_CONNECT" evt_desc=" BT Connect" key_code="KEY_3" key_type="KEY_LONG_PRESS"/>
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_DISCONNECT" evt_desc="BT Disconnect" key_code="KEY_4" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_RESET" evt_desc="BT Reset" key_code="KEY_4" key_type="KEY_LONG_PRESS"/>
	
    #ifdef __MMI_BTB_AT_KEY_SUPPORT__
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_CONNECT" evt_desc=" BT Connect" key_code="KEY_6" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="INPUT_EVENT_APP_ID_COMMON" grp_desc="Common" evt_id="EVT_ID_BTB_RESET" evt_desc="BT Reset" key_code="KEY_7" key_type="KEY_EVENT_UP"/>
    #endif  //__MMI_BTB_AT_KEY_SUPPORT__
/*just for build pass*/
	<AUDIO id="AUD_ID_INPUT_EVT_DUMMY" desc="Empty Audio" path="empty.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\empty.mp3"</AUDIO>
	<AUDIO id="AUD_ID_INPUT_EVT_1" desc="Custom Audio 1" path="custom_1.mp3"></AUDIO>
	<AUDIO id="AUD_ID_INPUT_EVT_2" desc="Custom Audio 2" path="custom_2.mp3"></AUDIO>
	<AUDIO id="AUD_ID_INPUT_EVT_3" desc="Custom Audio 3" path="custom_3.mp3"></AUDIO>
	<AUDIO id="AUD_ID_INPUT_EVT_4" desc="Custom Audio 4" path="custom_4.mp3"></AUDIO>

    <CACHEDATA type="byte" id="NVRAM_INPUT_EVT_NOTIFY_VOLUME">
        <DEFAULT_VALUE> [0x0C] </DEFAULT_VALUE>
        <DESCRIPTION> notify volume </DESCRIPTION>
    </CACHEDATA>
</APP>

#endif