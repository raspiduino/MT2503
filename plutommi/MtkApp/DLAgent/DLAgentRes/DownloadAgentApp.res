/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */

<APP id="APP_DOWNLOADAGENT">	
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file = "GlobalResDef.h"/>
   
   
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <SCREEN id="SCR_DA_APP"/>

    <!--Kernal-->
    <SCREEN id="SCR_ID_DA_JOB_LIST"/>
    <SCREEN id="SCR_ID_DA_JOB_OPTION"/>
    <SCREEN id="SCR_ID_DA_JOB_DETAIL"/>
    <SCREEN id="SCR_ID_DA_JOB_OBJECT_DESCRIPTION"/>
    <SCREEN id="SCR_ID_DA_JOB_CALLBACK_CONFIRM"/>
    <SCREEN id="SCR_ID_DA_JOB_ABORT_CONFIRM"/>
    <SCREEN id="SCR_ID_DA_NEW_PUSH_IND"/>
    <SCREEN id="SCR_ID_DA_DRM_PROCESSING"/>

		<!--List every screen ID of them for debug purpose-->
    <!--Select storage: Instance 0-->
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_BEGIN_0"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_MARKER_0"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_SEL_DRV_0"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_0"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_OPTIONS_0"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_END_0"/>

    <!--Select storage: Instance 1-->
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_BEGIN_1"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_MARKER_1"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_SEL_DRV_1"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_1"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_OPTIONS_1"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_END_1"/>

     <!--Select storage: Instance 2-->
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_BEGIN_2"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_MARKER_2"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_SEL_DRV_2"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_2"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_OPTIONS_2"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_END_2"/>

     <!--Select storage: Instance 3-->
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_BEGIN_3"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_MARKER_3"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_SEL_DRV_3"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_3"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_FILENAME_OPTIONS_3"/>
    <SCREEN id="SCR_ID_DA_SELECT_STORAGE_END_3"/>

     <!--Confirm screen resource-->
    <SCREEN id="SCR_ID_DA_CONFIRM_0"/>
    <SCREEN id="SCR_ID_DA_CONFIRM_1"/>
    <SCREEN id="SCR_ID_DA_CONFIRM_2"/>
    <SCREEN id="SCR_ID_DA_CONFIRM_3"/>

    <SCREEN id="SCR_ID_DA_DOWNLOAD_MOVING"/>
    <SCREEN id="SCR_ID_DA_PUSH_MOVING"/>
    <SCREEN id="SCR_ID_DA_SCREEN_AUTH"/>

    <SCREEN id="SCR_ID_DA_DOWNLOAD_PREFETCHING_CANCELLING"/>
    <SCREEN id="SCR_ID_DA_DOWNLOAD_PLEASE_WAIT"/>
    <SCREEN id="SCR_ID_DA_FULL_SCREEN_POPUP"/>
    
    <!--OMA-->
    <SCREEN id="SCR_ID_DA_OMA_DOWNLOAD_OPTION"/>
    <SCREEN id="SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD"/>

    <!--dummy-->
    <SCREEN id="SCR_ID_DA_DUMMY"/>
    <SCREEN id="SCR_ID_DA_WAITING_DUMMY"/>

    <!--Trigger-when-enter screen resource-->
    <SCREEN id="SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_0"/>
    <SCREEN id="SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_1"/>
    <SCREEN id="SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_2"/>
    <SCREEN id="SCR_ID_DA_TRIGGER_WHEN_ENTER_DUMMY_3"/>
	
    
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
	
		<!----General----> 
    <STRING id="STR_ID_DA_NEW_PUSH"/>
    <STRING id="STR_ID_DA_PROMPT_DL_COMPLETE"/>

    <STRING id="STR_ID_DA_UNABLE_TO_SAVE_FILE"/>
    

    <STRING id="STR_ID_DA_READY_FOR_USE_ASK_SUFFIX_EXT"/>
    <STRING id="STR_ID_DA_READY_FOR_USE_ASK_SUFFIX"/>
    <STRING id="STR_ID_DA_PROCESSING"/>
    <STRING id="STR_ID_DA_ERROR_FILE_MISMATCH"/>
    
    <STRING id="STR_ID_DA_ERROR_CONNECT_CLOSED"/>
    <STRING id="STR_ID_DA_ERROR_STORAGE_IS_UNAVAILABLE"/>
    <STRING id="STR_ID_DA_PROMPT_TIME_REMAIN_EXT"/>
    <STRING id="STR_DA_INSERT_MEMORY_CARD"/> 	
    <STRING id="STR_DA_INSERT_MEM_CARD"/> 
    <STRING id="STR_DLA_FAILED_TO_DOWNLOAD"/>
    <STRING id="STR_ID_DA_PROMPT_SEC"/>
    <STRING id="STR_ID_DA_PROMPT_SECS"/>
    <STRING id="STR_ID_DA_PROMPT_MIN"/>
    <STRING id="STR_ID_DA_PROMPT_MINS"/>
    <STRING id="STR_ID_DA_JOB_USE"/>
#ifndef __MMI_DA_CONF_PAGE_SLIM__
    <STRING id="STR_DA_EMPTY_USERNAME"/>
    <STRING id="STR_ID_DA_DOWNLOAD_FAILED"/>
    <STRING id="STR_ID_DA_SELECT_FOLDER"/>
    <STRING id="STR_ID_DA_JOB_USE"/>
    <STRING id="STR_ID_DA_CALLBACK_NOW"/>
    <STRING id="STR_ID_DA_DISCARD_ASK"/>
    <STRING id="STR_ID_DA_BROWSER_CLOSED"/>
    <STRING id="STR_ID_DA_FILE_WRITING_ERROR"/>
    <STRING id="STR_ID_DA_POPUP_CAN_NOT_START_WITH_SPACE"/>
    <STRING id="STR_ID_DA_POPUP_CAN_NOT_START_WITH_DOT"/>
#ifdef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
    <STRING id="STR_ID_DA_VIEW_OBJECT_DESC_SHORT"/>
#endif
    
#ifdef __DRM_SUPPORT__
    <STRING id="STR_ID_DA_NO_RIGHTS"/>
    <STRING id="STR_ID_DA_WAITING_FOR_RIGHTS"/>
    <STRING id="STR_ID_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME"/>
    <STRING id="STR_ID_DA_RIGHTS_DELAYED_SUFFIX"/>
#endif

    
    <!----Prompt----> 
    <STRING id="STR_ID_DA_PROMPT_SIZE"/>
    <STRING id="STR_ID_DA_PROMPT_TYPE"/>
    <STRING id="STR_ID_DA_PROMPT_NAME"/>
    <STRING id="STR_ID_DA_PROMPT_ESTIMATED"/>
    <STRING id="STR_ID_DA_PROMPT_UNKNOWN"/>
    <STRING id="STR_ID_DA_PROMPT_TIME_REMAIN"/>
    <STRING id="STR_ID_DA_PROMPT_NOT_SUPPORT"/>
    <STRING id="STR_ID_DA_PROMPT_NOT_SUPPORT_END"/>
    
    <STRING id="STR_ID_DA_PROMPT_EXCEED_MAX_DL"/>
    <STRING id="STR_ID_DA_PROMPT_EXCEED_MAX_JOB"/>
    
    

    <STRING id="STR_ID_DA_SAVED_TO_PHONE"/>
    <STRING id="STR_ID_DA_SAVED_TO_CARD"/>
    
    <!----Job----> 
    <STRING id="STR_ID_DA_JOB_LIST"/>
	<STRING id="STR_ID_DA_NO_OTHER_STORAGE"/>


#ifdef __MMI_DA_RESUME__
    <STRING id="STR_ID_DA_JOB_RESUME"/>
    <STRING id="STR_ID_DA_ERROR_RESUME_FAIL"/>
    <STRING id="STR_ID_DA_PROMPT_RESUME_NOT_SUPPORTED_BY_SERVER"/>
    <STRING id="STR_ID_DA_ERROR_TEMP_UNAVAILABLE"/>
#endif
    <STRING id="STR_ID_DA_JOB_EXIST"/>
	<STRING id="STR_ID_DA_JAVA_JOB_EXIST"/>
    
    <STRING id="STR_ID_DA_JOB_MOVE"/>
    <STRING id="STR_ID_DA_JOB_REMOVE_ALL"/>
    
    <!----OMA----> 
#if defined (__MMI_OMA_DD_DOWNLOAD__)
    <STRING id="STR_ID_DA_PROMPT_VENDOR"/>
    <STRING id="STR_ID_DA_PROMPT_DESC"/>
    <STRING id="STR_ID_DA_PROMPT_INFOURL"/>
    <STRING id="STR_ID_DA_FAILED"/>
    <STRING id="STR_ID_DA_OMA_DOWNLOADING_ICON"/>
    <STRING id="STR_ID_DA_OMA_SEND_REPORT"/>
    <STRING id="STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL"/>
    <STRING id="STR_ID_DA_OMA_ERROR_SEND_REPORT_CANCEL"/>
    <STRING id="STR_ID_DA_OMA_VIEW_DD"/>
#endif
	  <STRING id="STR_ID_DA_JOB_OPEN_INFO_PAGE"/>
#ifdef __MMI_DA_RESUME__
    <STRING id="STR_ID_DA_POPUP_SUSPENDED"/>
#endif
    <STRING id="STR_ID_DA_POPUP_CANCEL_ASK"/>
    <STRING id="STR_ID_DA_POPUP_SEND_ASK"/>
    <STRING id="STR_ID_DA_PROMPT_NEED_DOWNLOADING_NOTIFY_CHARGE"/>
    <STRING id="STR_ID_DA_DOWNLOADING_DESCRIPTOR"/>
     <STRING id="STR_ID_DA_SELECT_FOLDER"/>
	<STRING id="STR_ID_DA_DOWNLOADS"/>
/* Ncenter */
#if defined (__MMI_NCENTER_SUPPORT__)
<STRING id="STR_ID_DA_NEW_PUSHED_OBJECT"/>
<STRING id="STR_DLA_FILES_ARE_DOWNLOADING"/>
<STRING id="STR_DLA_FILES_ARE_FAILED_TO_DOWNLOAD"/>
<STRING id="STR_DLA_FILES_ARE_COMPLETED_DOWNLOAD"/>
<STRING id="STR_DLA_IS_DOWNLOADING"/>
<STRING id="STR_DLA_IS_FAILED_TO_DOWNLOAD"/>
<STRING id="STR_DLA_IS_COMPLETED_DOWNLOAD"/>
<STRING id="STR_DLA_DOWNLOADED"/>  

<STRING id="STR_ID_DA_DOWNLOADING"/>
<STRING id="STR_ID_DA_ASK_DISCARD_DOWNLOADING"/>
<STRING id="STR_ID_DA_PUSHED_OBJECT"/>
<STRING id="STR_ID_DA_COMPLETED"/>
#endif
/* Ncenter */    	
#endif    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
 #ifndef __MMI_DA_CONF_PAGE_SLIM__	
	 	<IMAGE id="IMG_ID_DA_DOWNLOAD_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\SB_AP.bmp"</IMAGE>		
		<IMAGE id="IMG_ID_DA_DOWNLOAD_PROGRESS_BANNER">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DLT_loading.gif"</IMAGE>

		<IMAGE id="IMG_ID_DA_DOWNLOAD_STATE_COMPLETE">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DL_Complete.bmp"</IMAGE>
		<IMAGE id="IMG_ID_DA_DOWNLOAD_STATE_LOADING">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DL_Loading.bmp"</IMAGE>
#ifdef __MMI_DA_RESUME__
		<IMAGE id="IMG_ID_DA_DOWNLOAD_STATE_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DL_Pause.bmp"</IMAGE>
#endif
		<IMAGE id="IMG_ID_DA_DOWNLOAD_STATE_PROCESSING">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DL_wait.bmp"</IMAGE>
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_ICON_BAR_SUPPORT__)
	    <IMAGE id="IMG_ID_DA_TOOLBAR_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_play.png"</IMAGE>
	    <IMAGE id="IMG_ID_DA_TOOLBAR_PLAY_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_play_dis.png"</IMAGE>
#ifdef __MMI_DA_RESUME__
	    <IMAGE id="IMG_ID_DA_TOOLBAR_SUSPEND">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_suspend.png"</IMAGE>
	    <IMAGE id="IMG_ID_DA_TOOLBAR_SUSPEND_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_suspend_dis.png"</IMAGE>
	    <IMAGE id="IMG_ID_DA_TOOLBAR_RESUME">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_resume.png"</IMAGE>
#endif
	    <IMAGE id="IMG_ID_DA_TOOLBAR_CANCEL">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_cancel.png"</IMAGE>
	    <IMAGE id="IMG_ID_DA_TOOLBAR_CANCEL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_cancel_dis.png"</IMAGE>
	    <IMAGE id="IMG_ID_DA_TOOLBAR_REMOVE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\DLAgent\\\\TB_remove.png"</IMAGE>
#endif
#if defined (__MMI_NCENTER_SUPPORT__)
  <IMAGE id="IMG_ID_DA_NC_DOWNLOAD">CUST_IMG_PATH"\\\\MainLCD\\\\Ncenter\\\\Icons\\\\icon_download.png"</IMAGE>
	<IMAGE id="IMG_ID_DA_NC_COMPLETE">CUST_IMG_PATH"\\\\MainLCD\\\\Ncenter\\\\Icons\\\\icon_complete.png"</IMAGE>
	<IMAGE id="IMG_ID_DA_NC_FAILED">CUST_IMG_PATH"\\\\MainLCD\\\\Ncenter\\\\Icons\\\\icon_alert.png"</IMAGE>
	<IMAGE id="IMG_ID_DA_NC_PUSH">CUST_IMG_PATH"\\\\MainLCD\\\\Ncenter\\\\Icons\\\\icon_info.png"</IMAGE>	
#endif 
    
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

	#if defined (__MMI_OMA_DD_DOWNLOAD__)
		<MENU id="MENU_ID_DA_OMA_DL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
			<MENUITEM_ID>MENU_ID_DA_OMA_DL_OPTION_DOWNLOAD_NOW</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_DA_OMA_DL_OPTION_VIEW_DD</MENUITEM_ID></MENU>
		<MENUITEM id="MENU_ID_DA_OMA_DL_OPTION_DOWNLOAD_NOW" str="STR_GLOBAL_DOWNLOAD"/>
		<MENUITEM id="MENU_ID_DA_OMA_DL_OPTION_VIEW_DD" str="STR_ID_DA_OMA_VIEW_DD"/>
#endif
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__)	
	    <MENU id="MENU_ID_DA_JOB_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_VIEW_DETAIL</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_PLAY</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_USE_NOW</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_SUSPEND</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_RESUME</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_MOVE</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_RENAME</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_CANCEL</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_REMOVE</MENUITEM_ID>
	        <MENUITEM_ID>MENU_ID_DA_JOB_OPTION_REMOVE_ALL</MENUITEM_ID></MENU>
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_PLAY" str="STR_GLOBAL_PLAY"/>
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_VIEW_DETAIL" str="STR_GLOBAL_DETAILS"/>
#endif
#ifndef __MMI_DA_CONF_PAGE_SLIM__
	    <MENUITEM id="MENU_ID_DA_JOB_OPTION_OPEN_INFO_PAGE" str="STR_ID_DA_JOB_OPEN_INFO_PAGE"/>
#endif		
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_CANCEL" str="STR_GLOBAL_CANCEL"/>
#ifdef __MMI_DA_RESUME__
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_SUSPEND" str="STR_GLOBAL_PAUSE"/>
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_RESUME" str="STR_ID_DA_JOB_RESUME"/>
#endif
		
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__)
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_USE_NOW" str="STR_ID_DA_JOB_USE"/>
	    <MENUITEM id="MENU_ID_DA_JOB_OPTION_MOVE" str="STR_ID_DA_JOB_MOVE"/>
	    <MENUITEM id="MENU_ID_DA_JOB_OPTION_RENAME" str="STR_GLOBAL_RENAME"/>
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_REMOVE" str="STR_GLOBAL_REMOVE"/>
		<MENUITEM id="MENU_ID_DA_JOB_OPTION_REMOVE_ALL" str="STR_ID_DA_JOB_REMOVE_ALL"/>
<MENU id="MENU_ID_DA_DOWNLOAD_CNF_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
       <MENUITEM_ID>MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE</MENUITEM_ID>
       <MENUITEM_ID>MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE_TO</MENUITEM_ID> </MENU>
       
    <MENUITEM id="MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE" str="STR_GLOBAL_SAVE"/>
    <MENUITEM id="MENU_ID_DA_DOWNLOAD_CNF_OPT_SAVE_TO" str="STR_ID_DA_SELECT_FOLDER"/> 
 #endif    		
		
 	
	
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_PROGRESS" proc="mmi_da_evt_show_progress"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB_MSG" proc="mmi_da_evt_popup_for_job_msg"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP" proc="mmi_da_evt_popup"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_DISPLAY_JOB_LIST" proc="mmi_da_evt_display_job_list"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_PROGRESSING_CLOSE" proc="mmi_da_evt_close_processing"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_ERRORCODE_WITH_CALLBACK" proc="mmi_da_evt_popup_error_code_with_callback"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_NEW_DOWNLOAD_CONFIRM_SCREEN" proc="mmi_da_evt_new_download_confirm_screen"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_SET_ACTIVE_DOWNLOAD_CONFIRM_SCREEN" proc="mmi_da_evt_set_active_download_confirm_screen"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_WPS_HTTP_RSP_CALLBACK" proc="mmi_da_evt_wps_http_rsp_callback"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_CONFIRM_OMA_DOWNLOAD" proc="mmi_da_evt_confirm_oma_download"/>
	<RECEIVER id="EVT_ID_DLA_SRV_OMA_HANDLE_HTTP_RSP" proc="mmi_da_evt_oma_handle_http_rsp"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_USER_AUTH_SCREEN" proc="mmi_da_evt_show_user_auth_screen"/>
	<RECEIVER id="EVT_ID_DLA_SRV_PUSH_PROCESS_ITEM" proc="mmi_da_evt_push_process_item"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_JOB_STATUS" proc="mmi_da_evt_update_job_status"/>
	<RECEIVER id="EVT_ID_DLA_SRV_CLICK_JOB" proc="mmi_da_evt_click_job"/>
	<RECEIVER id="EVT_ID_DLA_SRV_JOB_ABORTED_CALLBACK" proc="mmi_da_evt_job_aborted_callback"/>
	<RECEIVER id="EVT_ID_DLA_SRV_REMOVE_JOB_SCREENS" proc="mmi_da_evt_remove_job_screen"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SELECT_STORAGE" proc="mmi_da_evt_select_storage"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SET_STORAGE_INSTANCE" proc="mmi_da_set_active_select_storage_instance"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_DISPLAY_JOB_DETAIL" proc="mmi_da_evt_display_job_detail"/>			
	<RECEIVER id="EVT_ID_DLA_SRV_DRM_SAVE_AS" proc="mmi_da_job_drm_save_as"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_CONTENT_BY_DRM_PROCESSING" proc="mmi_da_update_content_by_drm_processing"/>
	<RECEIVER id="EVT_ID_DLA_SRV_CLOSE_APP" proc="mmi_da_evt_close_app"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_NCENTER" proc="mmi_da_evt_update_ncenter"/>
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_ERROR_FOR_JOB" proc="mmi_da_evt_popup_error_for_job"/>
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB" proc="mmi_da_evt_popup_for_job"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_NMGR_POPUP" proc="mmi_da_show_nmgr_alert"/>
        #if defined (BROWSER_SUPPORT)
        <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_da_enter_idle_screen_notify"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_da_scr_select_storage_on_dev_plug_out"/>
#endif
	<RECEIVER id="EVT_ID_DLA_SRV_IS_USB_AVAILABLE" proc="mmi_da_evt_usb_available"/>
</APP>
#endif //__MMI_DOWNLOAD_AGENT__