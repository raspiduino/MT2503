#include "mmi_features.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
<APP id="APP_UNIFIEDCOMPOSER">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,mmi_rp_srv_editor_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
		<!--String Resource Area-->

#ifdef __MMI_MMS_POSTCARD__
	<STRING id="STR_ID_UC_MESSAGE"/>
#endif
#ifdef __MMI_PHOTOEDITOR__
    <STRING id="STR_UC_EDIT_IMAGE"/>
#endif
#ifdef __MMI_MMS_POSTCARD__    
    <STRING id="STR_UC_NO_IMAGE"/>
#endif
	<STRING id="STR_UC_SLIDE_OPTION_ID"/>
	<STRING id="STR_UC_SEND_OPTION_ID"/>
	<STRING id="STR_UC_MESSAGE_TYPE_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_DETAIL_MESSAGE_TYPE_ID"/>
#endif
	<STRING id="STR_UC_RESEND_ID"/>
	<STRING id="STR_UC_ATTACHMENT_LIST_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_DETAIL_ATTACHMENT_LIST_ID"/>
#endif
	<STRING id="STR_UC_DELETE_SLIDE_ID"/>
	<STRING id="STR_UC_SLIDE_TIMING_ID"/>
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
	<STRING id="STR_UC_CC_ID"/>
	<STRING id="STR_UC_BCC_ID"/>
#endif
#ifdef __MMI_MMS_POSTCARD__
	<STRING id="STR_UC_TO_OPTION_ID"/>
#endif
	<STRING id="STR_UC_MSG_SIZE_EXCEED_ID"/>
	<STRING id="STR_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID"/>
	<STRING id="STR_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID"/>
	<STRING id="STR_UC_ADDR_LENGTH_EXCEED_ID"/>
	<STRING id="STR_UC_NUMBER_LENGTH_EXCEED_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_DETAIL_PAGES_ID"/>
	<STRING id="STR_UC_DETAIL_TOTAL_MESSAGES_ID"/>
	<STRING id="STR_UC_DETAIL_SIZE_ID"/>
#endif
	<STRING id="STR_UC_PROHIBIT_BY_CREATION_MODE_ID"/>
	<STRING id="STR_UC_NO_SPACE_ID"/>
	<STRING id="STR_UC_READ_REPORT_ID"/>
	<STRING id="STR_UC_DELIVERY_REPORT_ID"/>
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__	
	<STRING id="STR_UC_VALIDITY_PERIOD_ID"/>
#endif
	<STRING id="STR_UC_DELIVERY_TIME_ID"/>
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__	
    <STRING id="STR_UC_VALIDITY_PERIOD_1_HOUR_ID"/>
	<STRING id="STR_UC_VALIDITY_PERIOD_6_HOUR_ID"/>
	<STRING id="STR_UC_VALIDITY_PERIOD_12_HOUR_ID"/>
	<STRING id="STR_UC_VALIDITY_PERIOD_1_DAY_ID"/>
	<STRING id="STR_UC_VALIDITY_PERIOD_1_WEEK_ID"/>
#endif
	<STRING id="STR_UC_DELIVERY_TIME_IMMEDIATE_ID"/>
	<STRING id="STR_UC_DELIVERY_TIME_1_HOUR_ID"/>
	<STRING id="STR_UC_DELIVERY_TIME_12_HOUR_ID"/>
	<STRING id="STR_UC_DELIVERY_TIME_24_HOUR_ID"/>
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
	<STRING id="STR_UC_HIDE_SENDER_ID"/>
#endif
	<STRING id="STR_UC_FAIL_TO_INSERT_SIGNATURE_ID"/>
	<STRING id="STR_UC_DISCARD_EDITED_MSG_ID"/>
	<STRING id="STR_UC_WRITE_MSG_ID"/>
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
	<STRING id="STR_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID"/>
#endif
	<STRING id="STR_UC_STORAGE_FILE_IO_ERROR_ID"/>
	<STRING id="STR_UC_STORAGE_FULL_MSG_CONTENT_LOSS_ID"/>
	<STRING id="STR_UC_NO_RECIPIENT_ID"/>
	<STRING id="STR_ID_UC_INVALID_RECIPIENT"/>
	<STRING id="STR_ID_UC_INVALID_RECIPIENTS_REMOVED"/>
	<STRING id="STR_UC_PLS_ADD_RECIPIENT_ID"/>
	<STRING id="STR_UC_CREATING_ID"/>
#if !defined(__MMI_MMS_BGSR_SUPPORT__)
	<STRING id="STR_UC_SENDING_MMS_ID"/>
#endif
	<STRING id="STR_UC_ABORTED_ID"/>
	<STRING id="STR_UC_SEND_SUCCESS_SAVE_SUCCESS"/>
	<STRING id="STR_UC_SEND_SUCCESS_SAVE_FAIL"/>
#if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
	<STRING id="STR_UC_SEND_FAIL_SAVE_SUCCESS"/>
	<STRING id="STR_UC_SEND_FAIL_SAVE_FAIL"/>
#endif
	<STRING id="STR_UC_CONTENT_ERROR_ID"/>
	<STRING id="STR_UC_RECIPIENT_NUMBER_EXCEED_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_MSG_DETAIL_RECIPIENTS_ID"/>
#endif
	<STRING id="STR_UC_CAN_NOT_PLAY_COMPLETE"/>
	<STRING id="STR_UC_UNSUPPORT_CONTENT_ID"/>
	<STRING id="STR_UC_NO_ENOUGH_WORKING_SPACE_ID"/>
	<STRING id="STR_UC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID"/>
	<STRING id="STR_UC_MAX_SLIDE_NUM_REACHED_ID"/>
	<STRING id="STR_UC_TOO_MANY_MSG_ID"/>
	<STRING id="STR_UC_CONFIG_ERROR_ID"/>
	<STRING id="STR_UC_SERVER_TIMEOUT_ID"/>
	<STRING id="STR_UC_SERVER_ERROR_ID"/>
	<STRING id="STR_UC_SERVICE_DENIED_ID"/>
	<STRING id="STR_UC_UNSUPPORT_CONTENT_BY_SERVER_ID"/>
	<STRING id="STR_UC_UNKNOWN_APN_ID"/>
	<STRING id="STR_UC_UNAUTHORIZED_ID"/>
	<STRING id="STR_UC_SEND_FAIL_ID"/>
	<STRING id="STR_UC_SEND_FAIL_NO_BOX_ID"/>
        <STRING id="STR_UC_SEND_FAIL_NO_BOX_ID_LOWER"/>
	<STRING id="STR_UC_SYSTEM_RESOURCES_EXHAUSTED_ID"/>
	<STRING id="STR_UC_FILE_CORRUPT_ID"/>
	<STRING id="STR_UC_FAILED_TO_ADD_MEDIA_ID"/>
	<STRING id="STR_UC_FILE_EMPTY_ID"/>
#ifdef __MMI_UC_SUB_PREFIX_MMS__
	<STRING id="STR_UC_RE_ID"/>
#endif
#ifdef __MMI_UC_SUB_PREFIX_MMS__
	<STRING id="STR_UC_FW_ID"/>
#endif
	<STRING id="STR_UC_SIGNATURE_OBJECT_MISSED_ID"/>
	<STRING id="STR_UC_FAIL_TO_RESIZE_IMAGE_ID"/>
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
	<STRING id="STR_UC_SLIDE_TEXT_TIMING_ID"/>
	<STRING id="STR_UC_SLIDE_IMAGE_TIMING_ID"/>
	<STRING id="STR_UC_SLIDE_AUDIO_TIMING_ID"/>
	<STRING id="STR_UC_SLIDE_VIDEO_TIMING_ID"/>
#endif
	<STRING id="STR_UC_START_TIME_ID"/>
	<STRING id="STR_UC_END_TIME_ID"/>
	<STRING id="STR_UC_EXCEED_SLIDE_TIME_ID"/>
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
	<STRING id="STR_UC_SAVE_AS_TEMPLATE_ID"/>
#endif
	<STRING id="STR_UC_LESS_THAN_MEDIA_TIME_ID"/>
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__	
    <STRING id="STR_UC_MMS_SIZE_CONFIRM_MSG_1"/>
	<STRING id="STR_UC_MMS_SIZE_CONFIRM_MSG_2"/>
#endif
	<STRING id="STR_UC_INTERVAL_PREFIX_ID"/>
	<STRING id="STR_UC_INTERVAL_INFIX_ID"/>
	<STRING id="STR_UC_SERVER_ID"/>
	<STRING id="STR_UC_KB_ID"/>
	<STRING id="STR_UC_RESIZE_IMAGE_UNCHANGED_ID"/>
	<STRING id="STR_UC_WARNING_MODE_CONFIRM"/>
	<STRING id="STR_UC_WARNING_MODE_SIG_CONFIRM"/>
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	<STRING id="STR_UC_INSERT_CARD"/>
	<STRING id="STR_UC_CARD_NOT_PRESENT_CONFIRM"/>
	<STRING id="STR_UC_MAX_MSG_CARD_CONFIRM"/>
	<STRING id="STR_UC_MAX_MSG_PHONE_CONFIRM"/>
#endif
	<STRING id="STR_UC_DELETE_ASK_ID"/>
	<STRING id="STR_UC_DELETE_ALL_ASK_ID"/>
	<STRING id="STR_UC_CONN_TYPE_MAX_SIZE_REACHED_ID"/>
	<STRING id="STR_UC_SEND_FRM_SIM1"/>
	<STRING id="STR_UC_SEND_FRM_SIM2"/>
	<STRING id="STR_UC_SEND_FRM_SIM3"/>
	<STRING id="STR_UC_SEND_FRM_SIM4"/>
	<STRING id="STR_UC_SEND_TO_ID"/>
	<STRING id="STR_UC_ADD_RECIPIENT"/>
	<STRING id="STR_UC_ADD_SUBJECT_ID"/>
	<STRING id="STR_UC_EDIT_SUBJECT_ID"/>
	<STRING id="STR_UC_ENTER_RECIPIENT_ID"/>
	<STRING id="STR_UC_ADD_FROM_CONTACTS_ID"/>
	<STRING id="STR_UC_EDIT_RECIPIENT_ID"/>
	<STRING id="STR_UC_REMOVE_RECIPIENT_ID"/>
	<STRING id="STR_UC_REMOVE_ALL_RECIPIENTS_ID"/>
	<STRING id="STR_UC_CHANGE_TO_TO_ID"/>
	<STRING id="STR_UC_CHANGE_TO_CC_ID"/>
	<STRING id="STR_UC_CHANGE_TO_BCC_ID"/>
	<STRING id="STR_UC_SAVE_TO_DRAFT_ID"/>
	<STRING id="STR_UC_ADD_RECIPIENT_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_UC_SEND_MMS_ID"/>
	<STRING id="STR_UC_SEND_SMS_ID"/>
	<STRING id="STR_UC_REMOVE_EMS_OBJECT_CONFIRM"/>
	<STRING id="STR_UC_CORRUPT_MSG_DELETE_CONFIRM"/>
#endif
	<STRING id="STR_UC_WRITE_MSG_SUBJECT_ID"/>
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
	<STRING id="STR_UC_TEXT_OPTIONS_ID"/>
#endif
	<STRING id="STR_UC_PICTURE_OPTIONS_ID"/>
	<STRING id="STR_UC_REMOVE_PICTURE_ID"/>
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
	<STRING id="STR_UC_REPLACE_PICTURE_ID"/>
	<STRING id="STR_UC_REPLACE_AUDIO_ID"/>
	<STRING id="STR_UC_REPLACE_VIDEO_ID"/>
	<STRING id="STR_UC_REPLACE_ATTACHMENT_ID"/>
#endif
	<STRING id="STR_UC_SOUND_OPTIONS_ID"/>
	<STRING id="STR_UC_REMOVE_AUDIO_ID"/>
	<STRING id="STR_UC_VIDEO_OPTIONS_ID"/>
	<STRING id="STR_UC_REMOVE_VIDEO_ID"/>
	<STRING id="STR_UC_ATTACHMENT_OPTIONS_ID"/>
	<STRING id="STR_UC_REMOVE_ATTACHMENT_ID"/>
	<STRING id="STR_UC_ADD_MY_PICTURES_ID"/>
	<STRING id="STR_UC_ADD_MY_SOUNDS_ID"/>
	<STRING id="STR_UC_ADD_MY_VIDEOS_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_TAKE_PICTURE_ID"/>
	<STRING id="STR_UC_RECORD_SOUND_ID"/>
	<STRING id="STR_UC_RECORD_VIDEO_ID"/>
#endif
	<STRING id="STR_UC_ADD_PICTURE_ID"/>
	<STRING id="STR_UC_ADD_SOUND_ID"/>
	<STRING id="STR_UC_ADD_VIDEO_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_UC_SWITCH_TO_SMS_ID"/>
	<STRING id="STR_UC_SWITCH_TO_MMS_ID"/>
	<STRING id="STR_UC_SWITCHED_TO_SMS_ID"/>
	<STRING id="STR_UC_SWITCHED_TO_MMS_ID"/>
#endif
	<STRING id="STR_UC_ADVANCED_ID"/>
	<STRING id="STR_UC_PREVIEW_MMS_ID"/>
	<STRING id="STR_UC_ADD_NEW_SLIDE_AFTER_ID"/>
	<STRING id="STR_UC_ADD_NEW_SLIDE_BEFORE_ID"/>
	<STRING id="STR_UC_GO_TO_PREVIOUS_SLIDE_ID"/>
	<STRING id="STR_UC_GO_TO_NEXT_SLIDE_ID"/>
	<STRING id="STR_UC_SLIDE_TIMING_NEW_ID"/>
#if defined(__MMI_MESSAGES_TEMPLATE__)
	<STRING id="STR_UC_INSERT_TEXT_TEMPLATE_ID"/>
#endif
	<STRING id="STR_UC_INSERT_ATTACHMENT_ID"/>
#ifndef __MMI_SLIM_MMS_2__
	<STRING id="STR_UC_INSERT_PHB_NUMBER_ID"/>
	<STRING id="STR_UC_INSERT_PHB_NAME_ID"/>
	<STRING id="STR_UC_INSERT_SIGNATURE_ID"/>
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
	<STRING id="STR_UC_INSERT_BOOKMARK_ID"/>
#endif
	<STRING id="STR_UC_TRUNCATE_NUMBER_ID"/>
#ifdef __MMI_OP02_LEMEI__
	<STRING id="STR_UC_MSG_CLASS_ID"/>
#endif
	<STRING id="STR_UC_IMAGE_TOO_LARGE"/>
	<STRING id="STR_UC_SOME_OBJECT_WITHDREW"/>
	<STRING id="STR_UC_REMOVED_ID"/>
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_UC_ADD_OBJECT_ID"/>
#endif
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
	<STRING id="STR_UC_HEADER_OPTIONS_ID"/>
	<STRING id="STR_UC_WRITE_SMS_ID"/>
	<STRING id="STR_UC_WRITE_MMS_ID"/>
	<STRING id="STR_UC_MAX_RECIPIENT_FIELDS_ID"/>
	<STRING id="STR_UC_SEND_CONT_ID"/>
	<STRING id="STR_UC_SAVE_CONT_ID"/>
#endif
	<STRING id="STR_ID_POSTCARD_ADD_RECIPIENT"/>
#ifdef __MMI_MMS_POSTCARD__
  #ifdef __MMI_PHB_INFO_FIELD__
	<STRING id="STR_ID_POSTCARD_ADD_RECIPIENT_MANUAL"/>
  #endif
	<STRING id="STR_ID_POSTCARD_ADD_RECIPIENT_PHONEBOOK"/>
	<STRING id="STR_ID_POSTCARD_RECIPIENT_NAME_MANDATORY"/>
	<STRING id="STR_ID_POSTCARD_RECIPIENT_STREET_MANDATORY"/>
	<STRING id="STR_ID_POSTCARD_RECIPIENT_CITY_MANDATORY"/>
	<STRING id="STR_ID_POSTCARD_RECIPIENT_STAR_PROHIBITED"/>
	<STRING id="STR_ID_UC_MMS_POSTCARD"/>
#endif
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
	<STRING id="STR_ID_UC_PERSONAL"/>
	<STRING id="STR_ID_UC_ADVERTISEMENT"/>
	<STRING id="STR_ID_UC_INFORMATIONAL"/>
	<STRING id="STR_ID_UC_AUTO"/>
#endif /* OMA13_CON_739_SUPPORT_TEMP_TEST_CODE */ 

		<!--End String Resource Area-->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

	<!--Image Resource Area-->

    <IMAGE id="IMG_UC_ENTRY_SCRN_CAPTION_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG"</IMAGE>
	<IMAGE id="IMG_UC_TO_NUMBER_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mto.bmp"</IMAGE>
	<IMAGE id="IMG_UC_CC_NUMBER_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mcc.bmp"</IMAGE>
	<IMAGE id="IMG_UC_BCC_NUMBER_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mbcc.bmp"</IMAGE>
	#if !defined(__MMI_SLIM_MMS_2__) && defined(__MMI_UC_RECIPIENT_ICON__) && !defined(__MMI_FTE_SUPPORT_SLIM__) 
		<IMAGE id="IMG_UC_TO_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Eto.bmp"</IMAGE>
		<IMAGE id="IMG_UC_CC_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Ecc.bmp"</IMAGE>
		<IMAGE id="IMG_UC_BCC_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Ebcc.bmp"</IMAGE>
	#else
		<IMAGE id="IMG_UC_TO_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mto.bmp"</IMAGE>
		<IMAGE id="IMG_UC_CC_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mcc.bmp"</IMAGE>
		<IMAGE id="IMG_UC_BCC_EMAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\RecipientList\\\\UE_Mbcc.bmp"</IMAGE>
	#endif  /*__MMI_UC_RECIPIENT_ICON__*/
#ifdef __MMI_MMS_POSTCARD__
	<IMAGE id="IMG_UC_POSTCARD_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_Postcard.bmp"</IMAGE>
    <IMAGE id="IMG_UC_MESSAGE_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_Message.bmp"</IMAGE>
	<IMAGE id="IMG_UC_POSTCARD_RECIPIENT_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_ADDR.bmp"</IMAGE>
#endif
#ifdef __DRM_SUPPORT__
    <IMAGE id="IMG_UC_DRM_THUMBNAIL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\DRM.gif"</IMAGE>
#endif
	
#ifdef __MMI_FTE_SUPPORT__ 
	#ifdef __MMI_TOUCH_SCREEN__
		<IMAGE id="IMG_UC_FTE_ADD_OBJECT_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniComposer\\\\TB_add_object.png"</IMAGE>
		<IMAGE id="IMG_UC_FTE_DISABLED_ADD_OBJECT_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniComposer\\\\TB_add_object_dis.png"</IMAGE>
	#endif
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		<IMAGE id="IMG_UC_FTE_RECIPIENT_BUTTON_NORMAL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TOCCBCC\\\\To_Button_Normal.png"</IMAGE>
		<IMAGE id="IMG_UC_FTE_RECIPIENT_BUTTON_PRESSED_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TOCCBCC\\\\To_Button_Highlight.png"</IMAGE>
		<IMAGE id="IMG_UC_FTE_AUDIO_BUTTON_NORMAL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Audio_Button_Normal.png"</IMAGE>
		<IMAGE id="IMG_UC_FTE_AUDIO_BUTTON_PRESSED_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Audio_Button_Highlight.png"</IMAGE>
    #endif
	#ifdef __MMI_OP02_LEMEI__
	  	<IMAGE id="IMG_UC_FTE_IMAGE_BUTTON_NORMAL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Image_Button_Normal.png"</IMAGE>
		<IMAGE id="IMG_UC_FTE_VIDEO_BUTTON_NORMAL_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Video_Button_Normal.png"</IMAGE>
	#endif

    #else
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		<IMAGE id="IMG_UC_TO_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\To.bmp"</IMAGE>
		<IMAGE id="IMG_UC_CC_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\CC.bmp"</IMAGE>
		<IMAGE id="IMG_UC_BCC_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\BCC.bmp"</IMAGE>
		<IMAGE id="IMG_UC_AUDIO_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\audio.bmp"</IMAGE>
    #endif
	#ifdef __MMI_OP02_LEMEI__
	    <IMAGE id="IMG_UC_IMAGE_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\pic_icon.bmp"</IMAGE>
		<IMAGE id="IMG_UC_VIDEO_BUTTON_ID" >CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\video_icon.bmp"</IMAGE>
	#endif
	#endif

    <!--End Image Resource Area-->

	<!--------------------------------------------------------------------------------------------------------------------->
        <!--Audio Resource Area-->
        <!--Audio Resource Area-->

        <!--End Audio Resource Area-->
        <!--End Audio Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Media Resource Area-->
        <!--Media Resource Area-->

        <!--End Media Resource Area-->
        <!--End Media Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

		<!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->
  <SCREEN id = "SCR_ID_UC_START"/>
	<SCREEN id = "SCR_ID_UC_DUMMY"/>
	<SCREEN id = "SCR_ID_UC_PROCESSING"/>
	<SCREEN id = "SCR_ID_UC_EDITOR"/>
	<SCREEN id = "SCR_ID_UC_OPT"/>
	<SCREEN id = "SCR_ID_UC_MSG_DETAIL"/>
	<SCREEN id = "SCR_ID_UC_MSG_PREVIEW"/>
	<SCREEN id = "SCR_ID_UC_OPT_INSERT"/>
	<SCREEN id = "SCR_ID_ADD_PICTURE_OPTIONS"/>
	<SCREEN id = "SCR_ID_ADD_SOUND_OPTIONS"/>
	<SCREEN id = "SCR_ID_ADD_VIDEO_OPTIONS"/>
	<SCREEN id = "SCR_ID_ADVANCED_OPTIONS"/>
	<SCREEN id = "SCR_ID_UC_OPT_REMOVE"/>
	<SCREEN id = "SCR_ID_UC_OPT_REPLACE"/>
	<SCREEN id = "SCR_ID_PICTURE_OPTIONS"/>
	<SCREEN id = "SCR_ID_SOUND_OPTIONS"/>
	<SCREEN id = "SCR_ID_VIDEO_OPTIONS"/>
	<SCREEN id = "SCR_ID_ATTACHMENT_OPTIONS"/>
	<SCREEN id = "SCR_ID_TEXT_OPTIONS"/>
	<SCREEN id = "SCR_ID_UC_OPT_ADD_RECIPIENT"/>
	<SCREEN id = "SCR_ID_UC_OPT_ADD_RECIPIENT_OPTIONS"/>
	<SCREEN id = "SCR_ID_UC_OPT_ENTER_RECIPIENT"/>
	<SCREEN id = "SCR_ID_UC_OPT_EDIT_RECIPIENT"/>
	<SCREEN id = "SCR_ID_UC_OPT_ATTACHMENT_LIST"/>
	<SCREEN id = "SCR_ID_UC_OPT_ATTACHMENT_REMOVE"/>
	<SCREEN id = "SCR_ID_UC_OPT_ATTACHMENT_REPLACE"/>
	<SCREEN id = "SCR_ID_UC_OPT_SLIDE_OPT"/>
	<SCREEN id = "SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING"/>
	<SCREEN id = "SCR_ID_UC_OPT_SLIDE_OPT_GOTO"/>
	<SCREEN id = "SCR_ID_UC_OPT_MSG_TYPE_OPT"/>
	<SCREEN id = "SCR_ID_UC_OPT_SEND_OPT"/>
	<SCREEN id = "SCR_ID_UC_PREFERRED_MSG_TYPE"/>
	<SCREEN id = "SCR_ID_UC_SENDING"/>
	<SCREEN id = "SCR_ID_UC_EXIT_OPT"/>
	<SCREEN id = "SCR_ID_UC_PREVIEW_SLIDE_LIST"/>
	<SCREEN id = "SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT"/>
	<SCREEN id = "SCR_ID_UC_SUBJECT_EDITOR"/>
	<SCREEN id = "SCR_ID_UC_CONFIRM"/>
	<SCREEN id = "SCR_ID_UC_SIG_CONFIRM"/>
	<SCREEN id = "SCR_ID_UC_WRITE_MSG_SELECTION"/>
	<SCREEN id = "SCR_ID_UC_SIM_OPT"/>
	<SCREEN id = "SCR_ID_UC_INPUT_METHOD_AND_DONE"/>
	<SCREEN id = "SCR_ID_POSTCARD_RECIPIENT_OPTION"/>
	<SCREEN id = "SCR_ID_POSTCARD_ADDRESS"/>
	<SCREEN id = "SCR_ID_POSTCARD_RECIPIENT_LIST"/>
	<SCREEN id = "SCR_ID_UC_END"/>
	
	 <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
	 <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->

			<MENU id = "MENU_ID_UC_OPT" type = "OPTION" str = "@OID:STR_GLOBAL_OPTIONS" img = "IMG_UC_ENTRY_SCRN_CAPTION_ID">
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
		 #if (MMI_MAX_SIM_NUM >=2)
			<MENU id = "MENU_ID_UC_OPT_SEND" type = "OPTION" str = "@OID:STR_GLOBAL_SEND" >
				<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM1" str = "STR_UC_SEND_FRM_SIM1" />
				<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM2" str = "STR_UC_SEND_FRM_SIM2" />
			#if (MMI_MAX_SIM_NUM >=3)
                            <MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM3" str = "STR_UC_SEND_FRM_SIM3" />
			#if (MMI_MAX_SIM_NUM ==4)	
                          <MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM4" str = "STR_UC_SEND_FRM_SIM4" />
                     #endif
                    #endif
			</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SEND)-->
		#else
			<MENUITEM id = "MENU_ID_UC_OPT_SEND" str = "@OID:STR_GLOBAL_SEND" highlight = "mmi_uc_highlight_send"/> 
		#endif  /* #if (MMI_MAX_SIM_NUM ==2) */
		<MENUITEM id = "MENU_ID_UC_OPT_ADD_RECIPIENT" str = "STR_UC_ADD_RECIPIENT_ID"/>	
#else
				<MENUITEM id = "MENU_ID_UC_OPT_SEND_TO" str = "STR_UC_SEND_TO_ID" highlight = "mmi_uc_highlight_opt_send_to"/>
#endif
				<MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
				<MENU id = "MENU_ID_UC_OPT_HEADER_OPTIONS" str = "STR_UC_HEADER_OPTIONS_ID" img = "IMG_UC_ENTRY_SCRN_CAPTION_ID">
						<MENUITEM id = "MENU_ID_UC_OPT_HEADER_OPT_CC" str = "STR_UC_CC_ID"/>
						<MENUITEM id = "MENU_ID_UC_OPT_HEADER_OPT_BCC" str = "STR_UC_BCC_ID"/>
						<MENUITEM id = "MENU_ID_UC_OPT_HEADER_OPT_SUBJECT" str = "STR_GLOBAL_SUBJECT"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_HEADER_OPTIONS)-->
#endif
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
				<MENU id = "MENU_ID_UC_OPT_TEXT_OPTIONS" type = "OPTION" str = "STR_UC_TEXT_OPTIONS_ID"  highlight = "mmi_uc_highlight_opt_text_options">
					<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING" str = "STR_UC_SLIDE_TEXT_TIMING_ID" highlight = "mmi_uc_highlight_slide_opt_text_timing"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_TEXT_OPTIONS)-->
#endif

				<MENU id = "MENU_ID_UC_OPT_PICTURE_OPTIONS" type = "OPTION" str = "STR_UC_PICTURE_OPTIONS_ID" highlight = "mmi_uc_highlight_opt_picture_options">
					#ifdef __MMI_PHOTOEDITOR__	
						<MENUITEM id = "MENU_ID_UC_OPT_EDIT_IMAGE" str = "STR_UC_EDIT_IMAGE" highlight = "mmi_uc_highlight_opt_edit_image"/>
					#endif /*__MMI_PHOTOEDITOR__*/
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING" str = "STR_UC_SLIDE_IMAGE_TIMING_ID" highlight = "mmi_uc_highlight_slide_opt_image_timing"/>
#endif
						<MENUITEM id = "MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REMOVE" str = "STR_UC_REMOVE_PICTURE_ID" highlight = "mmi_uc_highlight_remove_image"/>
					#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REPLACE" str = "STR_UC_REPLACE_PICTURE_ID" highlight = "mmi_uc_highlight_replace_image"/>
					#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_PICTURE_OPTIONS)-->

				<MENU id = "MENU_ID_UC_OPT_SOUND_OPTIONS" type = "OPTION" str = "STR_UC_SOUND_OPTIONS_ID" highlight = "mmi_uc_highlight_opt_sound_options">
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING" str = "STR_UC_SLIDE_AUDIO_TIMING_ID" highlight = "mmi_uc_highlight_slide_opt_audio_timing"/>
#endif
						<MENUITEM id = "MENU_ID_UC_OPT_AUDIO_OPT_AUDIO_REMOVE" str = "STR_UC_REMOVE_AUDIO_ID" highlight = "mmi_uc_highlight_remove_audio"/>
					#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_AUDIO_OPT_AUDIO_REPLACE" str = "STR_UC_REPLACE_AUDIO_ID" highlight = "mmi_uc_highlight_replace_audio"/>
					#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SOUND_OPTIONS)-->

				<MENU id = "MENU_ID_UC_OPT_VIDEO_OPTIONS" type = "OPTION" str = "STR_UC_VIDEO_OPTIONS_ID" highlight = "mmi_uc_highlight_opt_video_options">
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING" str = "STR_UC_SLIDE_VIDEO_TIMING_ID" highlight = "mmi_uc_highlight_slide_opt_video_timing"/>
#endif
						<MENUITEM id = "MENU_ID_UC_OPT_VIDEO_OPT_VIDEO_REMOVE" str = "STR_UC_REMOVE_VIDEO_ID" highlight = "mmi_uc_highlight_remove_video"/>
					#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_VIDEO_OPT_VIDEO_REPLACE" str = "STR_UC_REPLACE_VIDEO_ID" highlight = "mmi_uc_highlight_replace_video"/>
					#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_VIDEO_OPTIONS)-->
#if !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) || !defined(__MMI_TOUCH_SCREEN__)
				<MENU id = "MENU_ID_UC_OPT_ATTACHMENT_OPTIONS" type = "OPTION" str = "STR_UC_ATTACHMENT_OPTIONS_ID" highlight = "mmi_uc_highlight_opt_attachment_options">
						<MENUITEM id = "MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REMOVE" str = "STR_UC_REMOVE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_remove_attachment"/>
					#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REPLACE" str = "STR_UC_REPLACE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_replace_attachment"/>
					#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ATTACHMENT_OPTIONS)-->
#endif
				<MENU id = "MENU_ID_UC_OPT_ADD_PICTURE" type = "OPTION" str = "STR_UC_ADD_PICTURE_ID" highlight = "mmi_uc_highlight_opt_add_picture">
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_IMAGE" str = "STR_UC_ADD_MY_PICTURES_ID" highlight = "mmi_uc_highlight_insert_image"/>
#ifndef __MMI_SLIM_MMS_2__
					#ifdef __MMI_CAMERA__
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_NEW_IMAGE" str = "STR_UC_TAKE_PICTURE_ID" highlight = "mmi_uc_highlight_insert_new_image"/>
					#endif /* __MMI_CAMERA__ */
#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ADD_PICTURE)-->

				<MENU id = "MENU_ID_UC_OPT_ADD_SOUND" type = "OPTION" str = "STR_UC_ADD_SOUND_ID" highlight = "mmi_uc_highlight_opt_add_sound">
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_AUDIO" str = "STR_UC_ADD_MY_SOUNDS_ID" highlight = "mmi_uc_highlight_insert_audio"/>
#ifndef __MMI_SLIM_MMS_2__
					#ifdef __MMI_SOUND_RECORDER__
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_NEW_AUDIO" str = "STR_UC_RECORD_SOUND_ID" highlight = "mmi_uc_highlight_insert_new_audio"/>
					#endif /* __MMI_SOUND_RECORDER__ */
#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ADD_SOUND)-->

			#ifdef __MMI_MMS_VIDEO_FEATURE__
				<MENU id = "MENU_ID_UC_OPT_ADD_VIDEO" type = "OPTION" str = "STR_UC_ADD_VIDEO_ID" highlight = "mmi_uc_highlight_opt_add_video">
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_VIDEO" str = "STR_UC_ADD_MY_VIDEOS_ID" highlight = "mmi_uc_highlight_insert_video"/>
#ifndef __MMI_SLIM_MMS_2__
					 #if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_NEW_VIDEO" str = "STR_UC_RECORD_VIDEO_ID" highlight = "mmi_uc_highlight_insert_new_video"/>
					#endif /* __MMI_VIDEO_RECORDER__ && !MJPG_ENCODE*/
#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ADD_VIDEO)-->
			#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
				<MENUITEM id = "MENU_ID_UC_OPT_ADD_SUBJECT" str = "STR_UC_ADD_SUBJECT_ID" highlight = "mmi_uc_highlight_opt_add_subject"/>
				<MENUITEM id = "MENU_ID_UC_OPT_EDIT_SUBJECT" str = "STR_UC_EDIT_SUBJECT_ID" highlight = "mmi_uc_highlight_opt_add_subject"/>
#endif
				<MENUITEM id = "MENU_ID_UC_OPT_PREVIEW" str = "STR_UC_PREVIEW_MMS_ID" highlight = "mmi_uc_highlight_opt_preview"/>

				<MENU id = "MENU_ID_UC_OPT_SLIDE_OPT" type = "OPTION" str = "STR_UC_SLIDE_OPTION_ID" highlight = "mmi_uc_highlight_opt_slide_opt">
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_INSERT" str = "STR_UC_ADD_NEW_SLIDE_AFTER_ID" highlight = "mmi_uc_highlight_slide_opt_insert"/>
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE" str = "STR_UC_ADD_NEW_SLIDE_BEFORE_ID" highlight = "mmi_uc_highlight_slide_opt_insert_before"/>
					#ifdef __MMI_MMS_2__
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_TIMING" str = "STR_UC_SLIDE_TIMING_ID" highlight = "mmi_uc_highlight_slide_opt_timing"/>
					#endif /* __MMI_MMS_2__ */
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_DELETE" str = "STR_UC_DELETE_SLIDE_ID" highlight = "mmi_uc_highlight_slide_opt_delete"/>
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_NEXT" str = "STR_UC_GO_TO_NEXT_SLIDE_ID" highlight = "mmi_uc_highlight_slide_opt_next"/>
						<MENUITEM id = "MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS" str = "STR_UC_GO_TO_PREVIOUS_SLIDE_ID" highlight = "mmi_uc_highlight_slide_opt_previous"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SLIDE_OPT)-->

#ifndef __MMI_MMS_STANDALONE_COMPOSER__
				<MENUITEM id = "MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_SMS" str = "STR_UC_SWITCH_TO_SMS_ID" highlight = "mmi_uc_highlight_opt_change_msg_type_to_sms"/>
				<MENUITEM id = "MENU_ID_UC_OPT_MSG_TYPE_CHANGE_TO_MMS" str = "STR_UC_SWITCH_TO_MMS_ID" highlight = "mmi_uc_highlight_opt_change_msg_type_to_mms"/>
#endif

				<MENU id = "MENU_ID_UC_OPT_ADVANCED" type = "OPTION" str = "STR_UC_ADVANCED_ID" highlight = "mmi_uc_highlight_opt_advance_options">
					#if defined(__MMI_MESSAGES_TEMPLATE__)
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE" str = "STR_UC_INSERT_TEXT_TEMPLATE_ID" highlight = "mmi_uc_highlight_insert_text_template"/>
					#endif    
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_ATTACHMENT" str = "STR_UC_INSERT_ATTACHMENT_ID" highlight = "mmi_uc_highlight_insert_attachment"/>
#ifndef __MMI_SLIM_MMS_2__
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_PHB_NUMBER" str = "STR_UC_INSERT_PHB_NUMBER_ID" highlight = "mmi_uc_highlight_insert_phb_number"/>
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_PHB_NAME" str = "STR_UC_INSERT_PHB_NAME_ID" highlight = "mmi_uc_highlight_insert_phb_name"/>
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_BOOKMARK" str = "STR_UC_INSERT_BOOKMARK_ID" highlight = "mmi_uc_highlight_insert_bookmark"/>
#endif
#ifndef __MMI_SLIM_MMS_2__
						<MENUITEM id = "MENU_ID_UC_OPT_INSERT_SIGNATURE" str = "STR_UC_INSERT_SIGNATURE_ID" highlight = "mmi_uc_highlight_insert_signature"/>
#endif /*__MMI_SLIM_MMS_2__*/
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SLIDE_OPT)-->

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
						<MENUITEM id = "MENU_ID_UC_OPT_SAVE_TO_DRAFT" str = "@OID:STR_GLOBAL_SAVE" highlight = "mmi_uc_highlight_save_to_draft"/>
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
						 #if (MMI_MAX_SIM_NUM >=2)
							<MENU id = "MENU_ID_UC_OPT_SAVE_SMS" type = "OPTION" str = "@OID:STR_GLOBAL_SAVE" >
								<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM1</MENUITEM_ID>
								<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM2</MENUITEM_ID>
						#if (MMI_MAX_SIM_NUM >= 3)
                                                        <MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM3</MENUITEM_ID>
                                          #if (MMI_MAX_SIM_NUM == 4)								
                                                         <MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM4</MENUITEM_ID>
                                                   #endif
                                                   #endif
							</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SEND)-->
						#else
							<MENUITEM id = "MENU_ID_UC_OPT_SAVE_SMS" str = "@OID:STR_GLOBAL_SAVE" highlight = "mmi_uc_highlight_save_to_draft"/> 
						#endif  /* #if (MMI_MAX_SIM_NUM ==2) */
    #endif
#else
				<MENUITEM_ID>MENU_ID_UC_OPT_SAVE_TO_DRAFT</MENUITEM_ID>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
				<MENUITEM_ID>MENU_ID_UC_OPT_SAVE_SMS</MENUITEM_ID>
#endif
#endif
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
				<MENUITEM id = "MENU_ID_UC_OPT_SAVE_AS_TEMPLATE" str = "STR_UC_SAVE_AS_TEMPLATE_ID" highlight = "mmi_uc_highlight_save_as_template"/>
#endif

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
							<MENUITEM id = "MENU_ID_UC_OPT_SEND_OPT" str = "STR_UC_SEND_OPTION_ID" />
#endif
#ifndef __MMI_SLIM_MMS_2__
				<MENUITEM id = "MENU_ID_UC_OPT_MSG_DETAIL" str = "@OID:STR_GLOBAL_DETAILS" highlight = "mmi_uc_highlight_opt_msg_detail"/>
#endif
			</MENU> <!--menu_item_end(MENU_ID_UC_OPT)-->

#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
				<MENU id = "MENU_ID_UC_OPT_ATTACHMENT_OPTIONS" type = "OPTION" str = "STR_UC_ATTACHMENT_OPTIONS_ID">
						<MENUITEM id = "MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REMOVE" str = "STR_UC_REMOVE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_remove_attachment"/>
					#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
						<MENUITEM id = "MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REPLACE" str = "STR_UC_REPLACE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_replace_attachment"/>
					#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ATTACHMENT_OPTIONS)-->
#endif

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
			<MENU id = "MENU_ID_UC_OPT_ADD_RECIPIENT" type = "OPTION" >
					 #if (MMI_MAX_SIM_NUM >=2)
						<MENU id = "MENU_ID_UC_OPT_SEND" type = "OPTION" str = "@OID:STR_GLOBAL_SEND" >
							<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM1" str = "STR_UC_SEND_FRM_SIM1" />
							<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM2" str = "STR_UC_SEND_FRM_SIM2" />
#if (MMI_MAX_SIM_NUM >= 3)							
<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM3" str = "STR_UC_SEND_FRM_SIM3" />
#if (MMI_MAX_SIM_NUM == 4)
							<MENUITEM id = "MENU_ID_UC_OPT_SEND_SIM4" str = "STR_UC_SEND_FRM_SIM4" />
#endif
#endif
						</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SEND)-->
					#else
						<MENUITEM id = "MENU_ID_UC_OPT_SEND" str = "@OID:STR_GLOBAL_SEND" highlight = "mmi_uc_highlight_send"/> 
					#endif  /* #if (MMI_MAX_SIM_NUM ==2) */
						<MENUITEM id = "MENU_ID_UC_OPT_SEND_OPT" str = "STR_UC_SEND_OPTION_ID" />
						<MENUITEM id = "MENU_ID_UC_OPT_EDIT_RECIPIENT" str = "STR_UC_EDIT_RECIPIENT_ID" highlight = "mmi_uc_highlight_edit_recipient"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_RECIPIENT" str = "STR_UC_REMOVE_RECIPIENT_ID" highlight = "mmi_uc_highlight_remove_recipient"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_ALL_RECIPIENTS" str = "STR_UC_REMOVE_ALL_RECIPIENTS_ID" highlight = "mmi_uc_highlight_remove_all_recipients"/>
						<MENUITEM id = "MENU_ID_UC_OPT_CHANGE_TO_TO" str = "STR_UC_CHANGE_TO_TO_ID" highlight = "mmi_uc_highlight_change_to_to"/>
						<MENUITEM id = "MENU_ID_UC_OPT_CHANGE_TO_CC" str = "STR_UC_CHANGE_TO_CC_ID" highlight = "mmi_uc_highlight_change_to_cc"/>
						<MENUITEM id = "MENU_ID_UC_OPT_CHANGE_TO_BCC" str = "STR_UC_CHANGE_TO_BCC_ID" highlight = "mmi_uc_highlight_change_to_bcc"/>
						<MENUITEM id = "MENU_ID_UC_OPT_SAVE_TO_DRAFT" str = "@OID:STR_GLOBAL_SAVE" highlight = "mmi_uc_highlight_save_to_draft"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
						 #if (MMI_MAX_SIM_NUM >=2)
							<MENU id = "MENU_ID_UC_OPT_SAVE_SMS" type = "OPTION" str = "@OID:STR_GLOBAL_SAVE" >
								<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM1</MENUITEM_ID>
								<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM2</MENUITEM_ID>
#if (MMI_MAX_SIM_NUM >= 3)								
<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM3</MENUITEM_ID>
#if (MMI_MAX_SIM_NUM == 4)
								<MENUITEM_ID>MENU_ID_UC_OPT_SEND_SIM4</MENUITEM_ID>
#endif
#endif
							</MENU> <!--menu_item_end(MENU_ID_UC_OPT_SEND)-->
						#else
							<MENUITEM id = "MENU_ID_UC_OPT_SAVE_SMS" str = "@OID:STR_GLOBAL_SAVE" highlight = "mmi_uc_highlight_save_to_draft"/> 
						#endif  /* #if (MMI_MAX_SIM_NUM ==2) */
#endif
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_ADD_RECIPIENT)-->
#endif

            <MENU id="MENU_ID_UC_EDITOR_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
                <MENUITEM_ID>MENU_ID_UC_EDITOR_OPTION_DONE</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_UC_EDITOR_OPTION_CANCEL</MENUITEM_ID>
                <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
            </MENU>
     
            <MENUITEM id="MENU_ID_UC_EDITOR_OPTION_DONE" str="@OID:STR_GLOBAL_DONE"/>

            <MENUITEM id="MENU_ID_UC_EDITOR_OPTION_CANCEL" str="@OID:STR_GLOBAL_CANCEL" />			
	#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
			<MENU id = "MENU_ID_UC_OPT_INSERT" type = "OPTION" str = "STR_UC_SLIDE_OPTION_ID" img = "IMG_UC_ENTRY_SCRN_CAPTION_ID" flag = "MOVEABLEWITHINPARENT">
						<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_IMAGE</MENUITEM_ID>
#ifndef __MMI_SLIM_MMS_2__
						#ifdef __MMI_CAMERA__
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_NEW_IMAGE</MENUITEM_ID>
						#endif /* __MMI_CAMERA__ */
#endif
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_AUDIO</MENUITEM_ID>
#ifndef __MMI_SLIM_MMS_2__
						#ifdef __MMI_SOUND_RECORDER__
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_NEW_AUDIO</MENUITEM_ID>
						#endif /* __MMI_SOUND_RECORDER__ */
#endif
						<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_VIDEO</MENUITEM_ID>
#ifndef __MMI_SLIM_MMS_2__
						#if defined(__MMI_VIDEO_RECORDER__) && !defined(MJPG_ENCODE)
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_NEW_VIDEO</MENUITEM_ID>
						#endif /* __MMI_VIDEO_RECORDER__ && !MJPG_ENCODE*/
#endif
						#if defined(__MMI_MESSAGES_TEMPLATE__)
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE</MENUITEM_ID>
						#endif  
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_ATTACHMENT</MENUITEM_ID>
#ifndef __MMI_SLIM_MMS_2__
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_PHB_NUMBER</MENUITEM_ID>
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_PHB_NAME</MENUITEM_ID>
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_BOOKMARK</MENUITEM_ID>
#endif
#ifndef __MMI_SLIM_MMS_2__
							<MENUITEM_ID>MENU_ID_UC_OPT_INSERT_SIGNATURE</MENUITEM_ID>
#endif /*__MMI_SLIM_MMS_2__*/
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_INSERT)-->
		#endif
			
			<MENU id = "MENU_ID_UC_OPT_REMOVE" type = "OPTION" str = "@OID:STR_GLOBAL_REMOVE" highlight = "mmi_uc_highlight_opt_remove">  
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_IMAGE" str = "STR_UC_REMOVE_PICTURE_ID" highlight = "mmi_uc_highlight_remove_image"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_AUDIO" str = "STR_UC_REMOVE_AUDIO_ID" highlight = "mmi_uc_highlight_remove_audio"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_VIDEO" str = "STR_UC_REMOVE_VIDEO_ID" highlight = "mmi_uc_highlight_remove_video"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REMOVE_ATTACHMENT" str = "STR_UC_REMOVE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_remove_attachment"/>
						<MENUITEM id = "MENU_ID_UC_OPT_DONE_SEND" str = "STR_GLOBAL_SEND"  highlight = "mmi_uc_highlight_done_opt_send"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_REMOVE)-->

	#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__				
				<MENU id = "MENU_ID_UC_OPT_REPLACE" type = "OPTION" str = "@OID:STR_GLOBAL_REPLACE" highlight = "mmi_uc_highlight_opt_replace">  
						<MENUITEM id = "MENU_ID_UC_OPT_REPLACE_IMAGE" str = "STR_UC_REPLACE_PICTURE_ID" highlight = "mmi_uc_highlight_replace_image"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REPLACE_AUDIO" str = "STR_UC_REPLACE_AUDIO_ID" highlight = "mmi_uc_highlight_replace_audio"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REPLACE_VIDEO" str = "STR_UC_REPLACE_VIDEO_ID" highlight = "mmi_uc_highlight_replace_video"/>
						<MENUITEM id = "MENU_ID_UC_OPT_REPLACE_ATTACHMENT" str = "STR_UC_REPLACE_ATTACHMENT_ID" highlight = "mmi_uc_highlight_replace_attachment"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_OPT_REPLACE)-->
	#endif
	#ifndef __MMI_FTE_SUPPORT__			
				<MENU id = "MENU_ID_UC_EXIT_OPT" type = "OPTION" str = "@OID:STR_GLOBAL_OPTIONS" >  
                        #ifndef __MMI_MMS_STANDALONE_COMPOSER__
				            <MENUITEM_ID>MENU_ID_UC_OPT_SAVE_SMS</MENUITEM_ID>
                        #endif
						<MENUITEM id = "MENU_ID_UC_EXIT_OPT_SAVE" str = "@OID:STR_GLOBAL_SAVE" highlight = "mmi_uc_highlight_exit_opt_save"/>
						<MENUITEM id = "MENU_ID_UC_EXIT_OPT_EXIT" str = "@OID:STR_GLOBAL_EXIT" highlight = "mmi_uc_highlight_exit_opt_exit"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_EXIT_OPT)-->
	#endif		
				<MENUITEM id = "MENU_ID_UC_OPT_MSG_TYPE_OPT" str = "STR_UC_MESSAGE_TYPE_ID"  />
		

#ifdef __MMI_MMS_POSTCARD__
			<MENUITEM id = "MENU_ID_POSTCARD_TO_OPTION" str = "STR_ID_POSTCARD_ADD_RECIPIENT_PHONEBOOK" highlight = "mmi_postcard_highlight_import_phonebook"/>
			<MENU id = "MENU_ID_UC_WRITE_MSG_SELECTION" type = "OPTION" str = "@OID:STR_GLOBAL_OK" highlight = "mmi_uc_highlight_write_msg_selection" flag = "MOVEABLEWITHINPARENT">
				<MENUITEM id = "MENU_ID_UC_WRITE_MESSAGE" str = "STR_ID_UC_MESSAGE" img = "IMG_UC_MESSAGE_ID" highlight = "mmi_uc_highlight_write_sel_message"/>
				<MENUITEM id = "MENU_ID_UC_WRITE_MMS_POSTCARD" str = "STR_ID_UC_MMS_POSTCARD" img = "IMG_UC_POSTCARD_ID" highlight = "mmi_uc_highlight_write_sel_mms_postcard"/>
			</MENU> <!--menu_item_end(MENU_ID_UC_WRITE_MSG_SELECTION)-->
			
			#ifdef __MMI_PHB_INFO_FIELD__
				<MENU id = "MENU_ID_POSTCARD_IMPORT_OPTION" type = "OPTION" str = "@OID:STR_GLOBAL_OK" highlight = "mmi_uc_highlight_write_msg_selection" flag = "MOVEABLEWITHINPARENT">
					<MENUITEM id = "MENU_ID_POSTCARD_IMPORT_OPTION_MANUAL" str = "STR_ID_POSTCARD_ADD_RECIPIENT_MANUAL" highlight = "mmi_postcard_highlight_import_manual"/>
					<MENUITEM id = "MENU_ID_POSTCARD_IMPORT_OPTION_PHONEBOOK" str = "STR_ID_POSTCARD_ADD_RECIPIENT_PHONEBOOK" highlight = "mmi_postcard_highlight_import_phonebook"/>
				</MENU> <!--menu_item_end(MENU_ID_UC_WRITE_MSG_SELECTION)-->
			#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* __MMI_MMS_POSTCARD__ */
		
 //#if (MMI_MAX_SIM_NUM >=2)
   <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_uc_sim_status_info_hdlr"/>
   <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_uc_sim_status_info_hdlr"/>
//#endif

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_uc_sd_card_plug_in_hdlr_cb"/>
#endif
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_uc_sd_card_plug_out_hdlr_cb"/>


<RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_uc_force_close"/>
<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_uc_usb_ms_plug_in_hdlr"/>
 //#if (MMI_MAX_SIM_NUM >=2)
   <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_uc_sim_status_info_hdlr"/>
   <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_uc_sim_status_info_hdlr"/>
//#endif

    <RECEIVER id="EVT_ID_SRV_MMS_MMA_TERMINATE" proc="mmi_uc_terminate_editor"/>
#ifdef __MMI_CLAMSHELL__
	<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_uc_clam_shell_close_handling"/>
#endif
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_UC_PREFERRED_MSG_TYPE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    <TIMER id="UC_INPROGRESS_TIMER_ID"/>
    <TIMER id="UC_MSG_TYPE_CHECK_TIMER_ID"/>
    <TIMER id="UM_BATTERY_LOW_CHECK_TIMER_ID"/>
    <TIMER id="UC_IMG_RESIZE_TIMER_ID"/>
    <TIMER id="UC_CREATE_RSP_RETRY_TIMER_ID"/>
    <TIMER id="UC_CREATE_RSP_REENTRY_RETRY_TIMER_ID"/>
    
</APP>
#endif
