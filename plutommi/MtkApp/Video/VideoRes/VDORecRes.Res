
#include "MMI_features.h"
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
#include "MMI_features_video.h"
#include "CustResDef.h"				/* resource path define */
#endif

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VDOREC"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
   package_name = "native.mtk.vdorec"         /* Use "native.mtk." as the prefix of application name */
    name = "STR_ID_VDOREC_APP_NAME"                    /* The string to be displayed under the main menu icon */
	#if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    img = "IMG_ID_VDOREC_MAINMENU_APP_ICON"   /* Main menu icon image */
	#endif
    launch = "mmi_vdorec_lauch"               /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                     * the function prototype should be:
                                                     *
                                                     *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                     *
                                                     * Note that the group_id of the application should be returned if launch successfully.
                                                     * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif
#else /*__MMI_APP_MANAGER_SUPPORT__&& __MMI_CAMCORDER__*/
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
   name = "STR_ID_VDOREC_APP_NAME"
#endif
#endif
>

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,MainMenuDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>


/*****************************************************************************
 * string id 
 *****************************************************************************/
    
	<STRING id="STR_ID_VDOREC_APP_NAME"/>
	<STRING id="STR_ID_VDOREC_CAMCODER_SETTING"/>
	<STRING id="STR_ID_VDOREC_VIDEO_SETTING"/>
	<STRING id="STR_ID_VDOREC_SIZE_LIMIT"/>
	<STRING id="STR_ID_VDOREC_TIME_LIMIT"/>
	<STRING id="STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY"/>
    <STRING id="STR_ID_VDOREC_NOTIFY_ERROR"/>
    //<STRING id="STR_ID_VDOREC_NOTIFY_SAVING"/>   /* use global saving */ 
    <STRING id="STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW"/>
    <STRING id="STR_ID_VDOREC_NOTIFY_SYSTEM_TOO_BUSY"/>

    #ifndef __VDOREC_FEATURE_SLIM_UE__
        <STRING id="STR_ID_VDOREC_NOTIFY_PLZ_SAVE_FIRST"/>
        <STRING id="STR_ID_VDOREC_NOTIFY_SAVED"/>
    #endif
    
	#ifdef __VDOREC_FEATURE_SELF_RECORD__
		<STRING id="STR_ID_VDOREC_SELF_RECORD"/>
	#endif

    #ifdef __VDOREC_FEATURE_EV__
		<STRING id="STR_ID_VDOREC_EV"/>	/* STR_ID_VDOREC_EV_START */
		#ifdef __VDOREC_FEATURE_EV_4__
			<STRING id="STR_ID_VDOREC_EV_N4"/>
		#endif
		#ifdef __VDOREC_FEATURE_EV_3__
			<STRING id="STR_ID_VDOREC_EV_N3"/>
		#endif
		#ifdef __VDOREC_FEATURE_EV_2__
			<STRING id="STR_ID_VDOREC_EV_N2"/>
		#endif
		<STRING id="STR_ID_VDOREC_EV_N1"/>
		<STRING id="STR_ID_VDOREC_EV_0"/>
		<STRING id="STR_ID_VDOREC_EV_P1"/>
		#ifdef __VDOREC_FEATURE_EV_2__
			<STRING id="STR_ID_VDOREC_EV_P2"/>
		#endif
		#ifdef __VDOREC_FEATURE_EV_3__
			<STRING id="STR_ID_VDOREC_EV_P3"/>
		#endif
		#ifdef __VDOREC_FEATURE_EV_4__
			<STRING id="STR_ID_VDOREC_EV_P4"/>
		#endif
	#endif /*__VDOREC_FEATURE_EV__*/
    
    #ifdef __VDOREC_FEATURE_VIDEO_SIZE__
        <STRING id="STR_ID_VDOREC_VIDEO_SIZE"/> /*STR_ID_VDOREC_VIDEO_SIZE_START*/
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
            <STRING id="STR_ID_VDOREC_VIDEO_SIZE_SQCIF"/>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
            <STRING id="STR_ID_VDOREC_VIDEO_SIZE_QQVGA"/>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
            <STRING id="STR_ID_VDOREC_VIDEO_SIZE_QCIF"/>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
            <STRING id="STR_ID_VDOREC_VIDEO_SIZE_QVGA"/>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
            <STRING id="STR_ID_VDOREC_VIDEO_SIZE_CIF"/>
        #endif
    #endif /*__VDOREC_FEATURE_VIDEO_SIZE__*/

	#ifdef __VDOREC_FEATURE_VIDEO_QTY__
		<STRING id="STR_ID_VDOREC_VIDEO_QTY"/>	/*STR_ID_VDOREC_VIDEO_QTY_START*/
		#if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY2_LOW"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY2_NORMAL"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY2_HIGH"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY2_FINE"/>
			#endif
		#else
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY_LOW"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY_NORMAL"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY_HIGH"/>
			#endif
			#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
				<STRING id="STR_ID_VDOREC_VIDEO_QTY_FINE"/>
			#endif
		#endif
	#endif /*__VDOREC_FEATURE_VIDEO_QTY__*/

    #ifdef __VDOREC_FEATURE_BANDING__
		<STRING id="STR_ID_VDOREC_BANDING"/>	/*STR_ID_VDOREC_BANDING_START*/
		<STRING id="STR_ID_VDOREC_BANDING_50HZ"/>
		<STRING id="STR_ID_VDOREC_BANDING_60HZ"/>
	#endif

    #ifdef __VDOREC_FEATURE_WB__
		<STRING id="STR_ID_VDOREC_WB"/>	/* use as STR_ID_VDOREC_WB_START*/
		#ifdef __VDOREC_FEATURE_WB_AUTO__
			<STRING id="STR_ID_VDOREC_WB_AUTO"/>
		#endif
		#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
			<STRING id="STR_ID_VDOREC_WB_DAYLIGHT"/>
		#endif
		#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
			<STRING id="STR_ID_VDOREC_WB_TUNGSTEN"/>
		#endif
		#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
			<STRING id="STR_ID_VDOREC_WB_FLUORESCENT"/>
		#endif
		#ifdef __VDOREC_FEATURE_WB_CLOUD__
			<STRING id="STR_ID_VDOREC_WB_CLOUD"/>
		#endif
		#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
			<STRING id="STR_ID_VDOREC_WB_INCANDESCENCE"/>
		#endif
    #endif /*__VDOREC_FEATURE_WB__*/

    #ifdef __VDOREC_FEATURE_EFFECT__
	    <STRING id="STR_ID_VDOREC_EFFECT_SETTING"/>	/* use as STR_ID_VDOREC_EFFECT_START*/

        #ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
    		<STRING id="STR_ID_VDOREC_EFFECT_NORMAL"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    		<STRING id="STR_ID_VDOREC_EFFECT_GRAYSCALE"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
    		<STRING id="STR_ID_VDOREC_EFFECT_SEPIA"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    		<STRING id="STR_ID_VDOREC_EFFECT_SEPIA_GREEN"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    		<STRING id="STR_ID_VDOREC_EFFECT_SEPIA_BLUE"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    		<STRING id="STR_ID_VDOREC_EFFECT_COLOR_INVERT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    		<STRING id="STR_ID_VDOREC_EFFECT_GRAY_INVERT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    		<STRING id="STR_ID_VDOREC_EFFECT_BLACKBOARD"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    		<STRING id="STR_ID_VDOREC_EFFECT_WHITEBOARD"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    		<STRING id="STR_ID_VDOREC_EFFECT_COPPER_CARVING"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    		<STRING id="STR_ID_VDOREC_EFFECT_BLUE_CARVING"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    		<STRING id="STR_ID_VDOREC_EFFECT_EMBOSSMENT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
    		<STRING id="STR_ID_VDOREC_EFFECT_CONTRAST"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_JEAN__
    		<STRING id="STR_ID_VDOREC_EFFECT_JEAN"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
    		<STRING id="STR_ID_VDOREC_EFFECT_SKETCH"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_OIL__
    		<STRING id="STR_ID_VDOREC_EFFECT_OIL"/>
        #endif
    #endif /*__VDOREC_FEATURE_EFFECT__*/

    #ifdef __VDOREC_FEATURE_NIGHT__
		<STRING id="STR_ID_VDOREC_NIGHT"/>	/* STR_ID_VDOREC_NIGHT_START */
		<STRING id="STR_ID_VDOREC_NIGHT_OFF"/>
		<STRING id="STR_ID_VDOREC_NIGHT_ON"/>
	#endif

	#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
		<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT"/>	/*STR_ID_VDOREC_LED_HIGHLIGHT_START*/
		#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_OFF"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_ON"/>
		#endif
		#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_OFF"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_WHITE"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_RED"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_GREEN"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_BLUE"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_YELLOW"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_PURPLE"/>
			<STRING id="STR_ID_VDOREC_LED_HIGHLIGHT_CYAN"/>
		#endif
	#endif /*__VDOREC_FEATURE_LED_HIGHLIGHT__*/	
   
	#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
		<STRING id="STR_ID_VDOREC_SIZE_LIMIT_NO_LIMIT"/>
		<STRING id="STR_ID_VDOREC_SIZE_LIMIT_1"/>
		<STRING id="STR_ID_VDOREC_SIZE_LIMIT_2"/>
		<STRING id="STR_ID_VDOREC_SIZE_LIMIT_3"/>
	#endif /*__VDOREC_FEATURE_SIZE_LIMIT__*/

	#ifdef __VDOREC_FEATURE_TIME_LIMIT__
		<STRING id="STR_ID_VDOREC_TIME_LIMIT_NO_LIMIT"/>
		<STRING id="STR_ID_VDOREC_TIME_LIMIT_1"/>
		<STRING id="STR_ID_VDOREC_TIME_LIMIT_2"/>
		<STRING id="STR_ID_VDOREC_TIME_LIMIT_3"/>
	#endif /*__VDOREC_FEATURE_TIME_LIMIT__*/

	#ifdef __VDOREC_FEATURE_RECORD_AUD__
		<STRING id="STR_ID_VDOREC_RECORD_AUD"/>	/*STR_ID_VDOREC_RECORD_AUD_START*/
		<STRING id="STR_ID_VDOREC_RECORD_AUD_OFF"/>
		<STRING id="STR_ID_VDOREC_RECORD_AUD_ON"/>
	#endif /*__VDOREC_FEATURE_RECORD_AUD__*/

	#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
		<STRING id="STR_ID_VDOREC_VIDEO_FORMAT"/>	/*STR_ID_VDOREC_VIDEO_FORMAT_START*/
		<STRING id="STR_ID_VDOREC_VIDEO_FORMAT_3GP"/>
		<STRING id="STR_ID_VDOREC_VIDEO_FORMAT_MP4"/>
	#endif /*__VDOREC_FEATURE_VIDEO_FORMAT__*/

	#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    	<STRING id="STR_ID_VDOREC_ACCEPT_CALL"/>	/*STR_ID_VDOREC_ACCEPT_CALL_START*/
        <STRING id="STR_ID_VDOREC_ACCEPT_CALL_ON"/>
        <STRING id="STR_ID_VDOREC_ACCEPT_CALL_OFF"/>
    #endif

    #ifdef __VDOREC_FEATURE_RESTORE_DEFAULT__
        <STRING id="STR_ID_VDOREC_RESTORE_DEFAULT"/>
        <STRING id="STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM"/>
    #endif
    
    #if defined(__MMI_BT_SUPPORT__)
        <STRING id="STR_ID_VDOREC_NOTIFY_BT_IS_WORKING"/>
    #endif
    
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        <STRING id="STR_ID_VDOREC_DELETE"/>
        <STRING id="STR_ID_VDOREC_NOTIFY_DELETE_CONFIRM"/>
        <STRING id="STR_ID_VDOREC_CONTINUE"/>
    #endif /*__VDOREC_FEATURE_PREVIEW_SAVED_FILE__*/

    #ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
        <STRING id="STR_ID_VDOREC_TO_CAMERA"/>
    #endif


/*****************************************************************************
 * image id 
 *****************************************************************************/

    #if defined(__DIRECT_SENSOR_SUPPORT__) && ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))
        #define VDOREC_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD_DIRECT_SENSOR\\\\"
    #else
        #define VDOREC_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\"
    #endif

#ifndef __MMI_VIDEO_RECORDER_SLIM__
	#if defined(__VDOREC_FEATURE_SLIM_UE__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
        <IMAGE id="IMG_ID_VDOREC_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\submenu\\\\Camera\\\\SB_VR.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_VDOREC_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\SB_VR.bmp"</IMAGE>
	#endif
#else
		<IMAGE id="IMG_ID_VDOREC_APP_ICON">VDOREC_OSD_PATH"timer_num_0.bmp"</IMAGE> // temp image id
#endif
	
    #ifdef __MMI_SUBLCD__
    	<IMAGE id="IMG_ID_VDOREC_SUBLCD_ICON">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\Video\\\\SB_VdoRec.gif"</IMAGE>
    #endif
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
	  <IMAGE id="IMG_ID_VDOREC_MAINMENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\VideoRecorder.png"</IMAGE>
#endif
#endif
    #if defined(__DIRECT_SENSOR_SUPPORT__)
        #ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
            <IMAGE id="IMG_ID_VDOREC_OSD_BG">VDOREC_OSD_PATH"CAM_BG_L.gif"</IMAGE>
        #else
            <IMAGE id="IMG_ID_VDOREC_OSD_BG">VDOREC_OSD_PATH"CAM_BG_P.gif"</IMAGE>
        #endif /*__VDOREC_FEATURE_HORIZONTAL_VIEW__*/
    #endif /*__DIRECT_SENSOR_SUPPORT__*/

#if (defined(__VDOREC_FEATURE_MMS_SUPPORT__) || defined(__VDOREC_FEATURE_BT_SEND_SUPPORT__) || defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)
    	<IMAGE id="IMG_ID_VDOREC_FORWARD_TO_MMS">VDOREC_OSD_PATH"VR_mms.bmp"</IMAGE>
#endif

		#if defined(__VDOREC_FEATURE_FTE_SUPPORT__)
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD">VDOREC_OSD_PATH"resume.png"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD_SEL">VDOREC_OSD_PATH"resume.png"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE">VDOREC_OSD_PATH"record_pause.png"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE_SEL">VDOREC_OSD_PATH"record_pause.png"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME">VDOREC_OSD_PATH"resume.png"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME_SEL">VDOREC_OSD_PATH"resume.png"</IMAGE>
	  #elif defined(__VDOREC_FEATURE_SLIM_UE__)
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD">VDOREC_OSD_PATH"record.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD_SEL">VDOREC_OSD_PATH"record.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE">VDOREC_OSD_PATH"record_pause.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE_SEL">VDOREC_OSD_PATH"record_pause.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME">VDOREC_OSD_PATH"record.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME_SEL">VDOREC_OSD_PATH"record.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD">VDOREC_OSD_PATH"resume.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RECORD_SEL">VDOREC_OSD_PATH"resume_down.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE">VDOREC_OSD_PATH"pause.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PAUSE_SEL">VDOREC_OSD_PATH"pause_down.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME">VDOREC_OSD_PATH"resume.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_RESUME_SEL">VDOREC_OSD_PATH"resume_down.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_SK_OPTION">VDOREC_OSD_PATH"options.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_OPTION_SEL">VDOREC_OSD_PATH"options_down.bmp"</IMAGE>    
        <IMAGE id="IMG_ID_VDOREC_SK_STOP">VDOREC_OSD_PATH"stop.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_STOP_SEL">VDOREC_OSD_PATH"stop_down.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_BACK">VDOREC_OSD_PATH"back.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_BACK_SEL">VDOREC_OSD_PATH"back_down.bmp"</IMAGE>
    #endif

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
    <IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_0">VDOREC_OSD_PATH"timer_num_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_1">VDOREC_OSD_PATH"timer_num_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_2">VDOREC_OSD_PATH"timer_num_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_3">VDOREC_OSD_PATH"timer_num_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_4">VDOREC_OSD_PATH"timer_num_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_5">VDOREC_OSD_PATH"timer_num_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_6">VDOREC_OSD_PATH"timer_num_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_7">VDOREC_OSD_PATH"timer_num_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_8">VDOREC_OSD_PATH"timer_num_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_NUMBER_9">VDOREC_OSD_PATH"timer_num_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_VDOREC_TIME_COL">VDOREC_OSD_PATH"timer_colon.bmp"</IMAGE>
	#endif

	#ifdef __VDOREC_FEATURE_EV__
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_INC">VDOREC_OSD_PATH"ev_inc.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL">VDOREC_OSD_PATH"ev_inc_sel.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS">VDOREC_OSD_PATH"ev_inc_dis.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_DEC">VDOREC_OSD_PATH"ev_dec.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL">VDOREC_OSD_PATH"ev_dec_sel.bmp"</IMAGE>
    	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS">VDOREC_OSD_PATH"ev_dec_dis.bmp"</IMAGE>
    #endif

	#ifdef __VDOREC_FEATURE_EV__
        <IMAGE id="IMG_ID_VDOREC_OSD_EV_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>

        #ifdef __VDOREC_FEATURE_SLIM_UE__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_HEAD">VDOREC_OSD_PATH"ev.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_N">VDOREC_OSD_PATH"ev_m.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_Z">VDOREC_OSD_PATH"ev_n.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_P">VDOREC_OSD_PATH"ev_p.bmp"</IMAGE>

        	    <IMAGE id="IMG_ID_VDOREC_OSD_EV_0">VDOREC_OSD_PATH"ev_0.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_1">VDOREC_OSD_PATH"ev_05.bmp"</IMAGE>
            #ifdef __VDOREC_FEATURE_EV_2__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_2">VDOREC_OSD_PATH"ev_10.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_3__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_3">VDOREC_OSD_PATH"ev_15.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_4__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_4">VDOREC_OSD_PATH"ev_20.bmp"</IMAGE>
            #endif

        #else
        
            #ifdef __VDOREC_FEATURE_EV_4__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_N4">VDOREC_OSD_PATH"ev_n4.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_3__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_N3">VDOREC_OSD_PATH"ev_n3.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_2__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_N2">VDOREC_OSD_PATH"ev_n2.bmp"</IMAGE>
            #endif
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_N1">VDOREC_OSD_PATH"ev_n1.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_0">VDOREC_OSD_PATH"ev_0.bmp"</IMAGE>
        		<IMAGE id="IMG_ID_VDOREC_OSD_EV_P1">VDOREC_OSD_PATH"ev_p1.bmp"</IMAGE>
            #ifdef __VDOREC_FEATURE_EV_2__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_P2">VDOREC_OSD_PATH"ev_p2.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_3__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_P3">VDOREC_OSD_PATH"ev_p3.bmp"</IMAGE>
            #endif
            #ifdef __VDOREC_FEATURE_EV_4__
                <IMAGE id="IMG_ID_VDOREC_OSD_EV_P4">VDOREC_OSD_PATH"ev_p4.bmp"</IMAGE>
            #endif

        #endif
        
            <IMAGE id="IMG_ID_VDOREC_OSD_EV_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
    #endif /*__VDOREC_FEATURE_EV__*/

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
	#ifdef __VDOREC_FEATURE_ZOOM__
	    #if defined(__VDOREC_FEATURE_FTE_SUPPORT__)
					<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD">VDOREC_OSD_PATH"zoom_head.9slice.png"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC">VDOREC_OSD_PATH"zoom_in.png"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL">VDOREC_OSD_PATH"zoom_in_down.png"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS">VDOREC_OSD_PATH"zoom_in_dis.png"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC">VDOREC_OSD_PATH"zoom_out.png"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL">VDOREC_OSD_PATH"zoom_out_down.png"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS">VDOREC_OSD_PATH"zoom_out_dis.png"</IMAGE> 
	    #elif defined(__VDOREC_FEATURE_SLIM_UE__)
					<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD">VDOREC_OSD_PATH"zoom_head.9slice.bmp"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC">VDOREC_OSD_PATH"zoom_in.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL">VDOREC_OSD_PATH"zoom_in_sel.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS">VDOREC_OSD_PATH"zoom_in_dis.bmp"</IMAGE> 
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC">VDOREC_OSD_PATH"zoom_out.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL">VDOREC_OSD_PATH"zoom_out_sel.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS">VDOREC_OSD_PATH"zoom_out_dis.bmp"</IMAGE>
	    #else
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC">VDOREC_OSD_PATH"zoom_in.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL">VDOREC_OSD_PATH"zoom_in_sel.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS">VDOREC_OSD_PATH"zoom_in_dis.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC">VDOREC_OSD_PATH"zoom_out.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL">VDOREC_OSD_PATH"zoom_out_sel.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS">VDOREC_OSD_PATH"zoom_out_dis.bmp"</IMAGE>        
            <IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD">VDOREC_OSD_PATH"zoom_head.bmp"</IMAGE>
            <IMAGE id="IMG_ID_VDOREC_TOUCH_OSD_ZOOM_TAIL">VDOREC_OSD_PATH"zoom_tail.bmp"</IMAGE>
            <IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_0">VDOREC_OSD_PATH"num_0.bmp"</IMAGE>    //this use to get timer image width
            <IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_1">VDOREC_OSD_PATH"num_1.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_2">VDOREC_OSD_PATH"num_2.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_3">VDOREC_OSD_PATH"num_3.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_4">VDOREC_OSD_PATH"num_4.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_5">VDOREC_OSD_PATH"num_5.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_6">VDOREC_OSD_PATH"num_6.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_7">VDOREC_OSD_PATH"num_7.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_8">VDOREC_OSD_PATH"num_8.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_NUMBER_9">VDOREC_OSD_PATH"num_9.bmp"</IMAGE>
        	<IMAGE id="IMG_ID_VDOREC_EFFECT_DOT">VDOREC_OSD_PATH"num_dot.bmp"</IMAGE>
        #endif
	#endif
	#endif

	#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
        <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_SQCIF">VDOREC_OSD_PATH"capsize_sqcif.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_QQVGA">VDOREC_OSD_PATH"capsize_qqvga.bmp"</IMAGE>
        #endif
        #if 0
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_QCIF">VDOREC_OSD_PATH"capsize_qcif.bmp"</IMAGE>
        #endif
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_QVGA">VDOREC_OSD_PATH"capsize_qvga.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_CIF">VDOREC_OSD_PATH"capsize_cif.bmp"</IMAGE>
        #endif
    	<IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_SIZE_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
    #endif

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
	#ifdef __VDOREC_FEATURE_VIDEO_QTY__
        <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
        #ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_LOW">VDOREC_OSD_PATH"capqty_low.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_NORMAL">VDOREC_OSD_PATH"capqty_normal.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_HIGH">VDOREC_OSD_PATH"capqty_good.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
            <IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_FINE">VDOREC_OSD_PATH"capqty_fine.bmp"</IMAGE>
        #endif
    	<IMAGE id="IMG_ID_VDOREC_OSD_VIDEO_QTY_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
	#endif
	#endif

	#ifdef __VDOREC_FEATURE_WB__
	    <IMAGE id="IMG_ID_VDOREC_OSD_WB_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>	
        #ifdef __VDOREC_FEATURE_WB_AUTO__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_AUTO">VDOREC_OSD_PATH"wb_auto.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_DAYLIGHT">VDOREC_OSD_PATH"wb_daylight.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_TUNGSTEN">VDOREC_OSD_PATH"wb_tungsten.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_FLUORESCENT">VDOREC_OSD_PATH"wb_fluorescent.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_WB_CLOUD__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_CLOUD">VDOREC_OSD_PATH"wb_cloudy.bmp"</IMAGE>
        #endif
        #ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
            <IMAGE id="IMG_ID_VDOREC_OSD_WB_INCANDESCENCE">VDOREC_OSD_PATH"wb_incandescent.bmp"</IMAGE>
        #endif
	    <IMAGE id="IMG_ID_VDOREC_OSD_WB_ALL">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
    #endif /*__VDOREC_FEATURE_WB__*/

	#ifdef __VDOREC_FEATURE_NIGHT__
        <IMAGE id="IMG_ID_VDOREC_OSD_NIGHT_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>    
        <IMAGE id="IMG_ID_VDOREC_OSD_NIGHT_OFF">VDOREC_OSD_PATH"night_off.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_OSD_NIGHT_ON">VDOREC_OSD_PATH"night_on.bmp"</IMAGE>	
	    <IMAGE id="IMG_ID_VDOREC_OSD_NIGHT_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
	#endif
	
    #ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    	<IMAGE id="IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
        #ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
			<IMAGE id="IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_OFF">VDOREC_OSD_PATH"led_off.bmp"</IMAGE>
			<IMAGE id="IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_ON">VDOREC_OSD_PATH"led_on.bmp"</IMAGE>
        #endif
	    <IMAGE id="IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
    #endif /*__VDOREC_FEATURE_LED_HIGHLIGHT__*/	

    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__    //no these images now
    	<IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_OFF">VDOREC_OSD_PATH"sizelimit_off.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_1">VDOREC_OSD_PATH"sizelimit_1.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_2">VDOREC_OSD_PATH"sizelimit_2.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_3">VDOREC_OSD_PATH"sizelimit_3.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_VDOREC_OSD_SIZE_LIMIT_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
	#endif /*__VDOREC_FEATURE_SIZE_LIMIT__*/

	#ifdef __VDOREC_FEATURE_TIME_LIMIT__    //no these images now
	    <IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_OFF">VDOREC_OSD_PATH"timelimit_off.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_1">VDOREC_OSD_PATH"timelimit_1.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_2">VDOREC_OSD_PATH"timelimit_2.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_3">VDOREC_OSD_PATH"timelimit_3.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_VDOREC_OSD_TIME_LIMIT_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
	#endif /*__VDOREC_FEATURE_TIME_LIMIT__*/
		
    #ifdef __VDOREC_FEATURE_RECORD_AUD__
        <IMAGE id="IMG_ID_VDOREC_OSD_RECORD_AUD_START">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_RECORD_AUD_OFF">VDOREC_OSD_PATH"aud_off.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_RECORD_AUD_ON">VDOREC_OSD_PATH"aud_on.bmp"</IMAGE>
		<IMAGE id="IMG_ID_VDOREC_OSD_RECORD_AUD_END">VDOREC_OSD_PATH"vdo_empty_image_file.bmp"</IMAGE>
	#endif /*__VDOREC_FEATURE_RECORD_AUD__*/	

    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    		#if defined(__VDOREC_FEATURE_FTE_SUPPORT__)
          <IMAGE id="IMG_ID_VDOREC_SK_PLAY">VDOREC_OSD_PATH"play.png"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_SK_PLAY_SEL">VDOREC_OSD_PATH"play_down.png"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_SK_PLAY_PAUSE">VDOREC_OSD_PATH"pause.png"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_SK_DELETE">VDOREC_OSD_PATH"delete.png"</IMAGE>
          <IMAGE id="IMG_ID_VDOREC_SK_DELETE_SEL">VDOREC_OSD_PATH"delete_down.png"</IMAGE>
        #else
        <IMAGE id="IMG_ID_VDOREC_SK_PLAY">VDOREC_OSD_PATH"play.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PLAY_SEL">VDOREC_OSD_PATH"play_down.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_PLAY_PAUSE">VDOREC_OSD_PATH"pause.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_DELETE">VDOREC_OSD_PATH"delete.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_SK_DELETE_SEL">VDOREC_OSD_PATH"delete_down.bmp"</IMAGE>
        #endif
    #endif /*__VDOREC_FEATURE_PREVIEW_SAVED_FILE__*/    

    #ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
        <IMAGE id="IMG_ID_VDOREC_PROGRESS_FILL">VDOREC_OSD_PATH"video_progress_fg.bmp"</IMAGE>
        <IMAGE id="IMG_ID_VDOREC_PROGRESS_EMPTY">VDOREC_OSD_PATH"video_progress_bg.bmp"</IMAGE>
    #endif /*__VDOREC_FEATURE_LIMIT_PROGRESS_BAR__*/
    

/*****************************************************************************
 * menu id 
 *****************************************************************************/

    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        <MENU id="MENU_ID_VDOREC_APP" str="MAIN_MENU_VDOREC_TEXT" highlight="mmi_vdorec_hilight_app" img="MAIN_MENU_VDOREC_ICON" shortcut="ON" shortcut_img="MAIN_MENU_VDOREC_ICON" launch="mmi_vdorec_lauch"/>
    	<MENU id="MAIN_MENU_OPTION_VDOREC_APP" str="STR_ID_VDOREC_APP_NAME" highlight="mmi_vdorec_hilight_app" img="IMG_ID_VDOREC_APP_ICON"/>
    #else
    	<MENU id="MAIN_MENU_OPTION_VDOREC_APP" str="STR_ID_VDOREC_APP_NAME" highlight="mmi_vdorec_hilight_app" img="IMG_ID_VDOREC_APP_ICON"/>
        <MENU id="MENU_ID_VDOREC_APP" str="STR_ID_VDOREC_APP_NAME" highlight="mmi_vdorec_hilight_app" img="IMG_ID_VDOREC_APP_ICON" shortcut="ON" shortcut_img="IMG_ID_VDOREC_APP_ICON" launch="mmi_vdorec_lauch"/>
    #endif /*__MMI_BI_DEGREE_MAIN_MENU_STYLE__*/

    <MENU id="MENU_ID_VDOREC_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_ID_VDOREC_TO_CAMERA</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_VDOREC_CAMCODER_SETTING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_VDOREC_VIDEO_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VDOREC_WHITE_BALANCE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_SETTING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_VDOREC_SELF_RECORD</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_VDOREC_STORAGE</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_VDOREC_RESTORE_DEFAULT</MENUITEM_ID>
	</MENU>

	#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
    	<MENUITEM id="MENU_ID_VDOREC_TO_CAMERA" str="STR_ID_VDOREC_TO_CAMERA"/>
    #endif
	
	#ifdef __VDOREC_FEATURE_MERGE_MENU__
		<MENUITEM id="MENU_ID_VDOREC_CAMCODER_SETTING" str="STR_ID_VDOREC_CAMCODER_SETTING"/>
	#else
		<MENUITEM id="MENU_ID_VDOREC_CAMCODER_SETTING" str="STR_ID_VDOREC_CAMCODER_SETTING"/>
		<MENUITEM id="MENU_ID_VDOREC_VIDEO_SETTING" str="STR_ID_VDOREC_VIDEO_SETTING"/>
	#endif /*__VDOREC_FEATURE_MERGE_MENU__*/

    #ifdef __VDOREC_FEATURE_WB__
        <MENUITEM id="MENU_ID_VDOREC_WHITE_BALANCE" str="STR_ID_VDOREC_WB" hint="mmi_vdorec_hint_wb"/>
    #endif
	
    #ifdef __VDOREC_FEATURE_EFFECT__
		<MENU id="MENU_ID_VDOREC_EFFECT_SETTING" type="OPTION" str="STR_ID_VDOREC_EFFECT_SETTING" hint="mmi_vdorec_hint_effect_setting">
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_NORMAL</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_GRAYSCALE</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_SEPIA</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_SEPIA_GREEN</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_SEPIA_BLUE</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_COLOR_INVERT</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_GRAY_INVERT</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_BLACKBOARD</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_WHITEBOARD</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_COPPER_CARVING</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_BLUE_CARVING</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_EMBOSSMENT</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_CONTRAST</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_JEAN</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_SKETCH</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_VDOREC_EFFECT_OIL</MENUITEM_ID>
		</MENU>
        #ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_NORMAL" str="STR_ID_VDOREC_EFFECT_NORMAL"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_GRAYSCALE" str="STR_ID_VDOREC_EFFECT_GRAYSCALE"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_SEPIA" str="STR_ID_VDOREC_EFFECT_SEPIA"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_SEPIA_GREEN" str="STR_ID_VDOREC_EFFECT_SEPIA_GREEN"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_SEPIA_BLUE" str="STR_ID_VDOREC_EFFECT_SEPIA_BLUE"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_COLOR_INVERT" str="STR_ID_VDOREC_EFFECT_COLOR_INVERT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_GRAY_INVERT" str="STR_ID_VDOREC_EFFECT_GRAY_INVERT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_BLACKBOARD" str="STR_ID_VDOREC_EFFECT_BLACKBOARD"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_WHITEBOARD" str="STR_ID_VDOREC_EFFECT_WHITEBOARD"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_COPPER_CARVING" str="STR_ID_VDOREC_EFFECT_COPPER_CARVING"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_BLUE_CARVING" str="STR_ID_VDOREC_EFFECT_BLUE_CARVING"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_EMBOSSMENT" str="STR_ID_VDOREC_EFFECT_EMBOSSMENT"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_CONTRAST" str="STR_ID_VDOREC_EFFECT_CONTRAST"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_JEAN__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_JEAN" str="STR_ID_VDOREC_EFFECT_JEAN"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_SKETCH" str="STR_ID_VDOREC_EFFECT_SKETCH"/>
        #endif
        #ifdef __VDOREC_FEATURE_EFFECT_OIL__
			<MENUITEM id="MENU_ID_VDOREC_EFFECT_OIL" str="STR_ID_VDOREC_EFFECT_OIL"/>
        #endif
    #endif /*__VDOREC_FEATURE_EFFECT__*/

    #ifdef __VDOREC_FEATURE_SELF_RECORD__   //not use now
		<MENUITEM id="MENU_ID_VDOREC_SELF_RECORD" str="STR_ID_VDOREC_SELF_RECORD"/>
	#endif

    #ifdef __VDOREC_FEATURE_STORAGE__
		<MENUITEM id="MENU_ID_VDOREC_STORAGE" str="STR_GLOBAL_STORAGE" hint="mmi_vdorec_hint_storage"/>
	#endif    

	#ifdef __VDOREC_FEATURE_RESTORE_DEFAULT__
	    <MENUITEM id="MENU_ID_VDOREC_RESTORE_DEFAULT" str="STR_ID_VDOREC_RESTORE_DEFAULT"/>
	#endif

    #ifndef __VDOREC_FEATURE_SLIM_UE__
    	<MENU id="MENU_ID_VDOREC_SEND" type="OPTION" str="STR_GLOBAL_SEND">
    		<MENUITEM_ID>MENU_ID_VDOREC_TO_MMS</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_VDOREC_TO_EMAIL</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_VDOREC_TO_BT</MENUITEM_ID>
    	</MENU>

        #ifdef __VDOREC_FEATURE_MMS_SUPPORT__
    	    <MENUITEM id="MENU_ID_VDOREC_TO_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG" highlight="mmi_vdorec_highlight_to_mms"/>
        #endif
        #ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
    	    <MENUITEM id="MENU_ID_VDOREC_TO_EMAIL" str="STR_GLOBAL_AS_EMAIL" highlight="mmi_vdorec_highlight_to_email"/>
        #endif
        #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
    	    <MENUITEM id="MENU_ID_VDOREC_TO_BT" str="STR_GLOBAL_VIA_BLUETOOTH" highlight="mmi_vdorec_highlight_to_bluetooth"/>
        #endif
    #endif

    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        <MENU id="MENU_ID_VDOREC_PREVIEW_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        #ifdef __VDOREC_FEATURE_MERGE_SEND_OPTION__
            <MENUITEM_ID>MENU_ID_VDOREC_SEND</MENUITEM_ID>
        #else
            <MENUITEM_ID>MENU_ID_VDOREC_TO_MMS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_VDOREC_TO_EMAIL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_VDOREC_TO_BT</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_VDOREC_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_VDOREC_CONTINUE</MENUITEM_ID>
        </MENU>
            <MENUITEM id="MENU_ID_VDOREC_DELETE" str="STR_ID_VDOREC_DELETE"/>
        #ifdef __VDOREC_FEATURE_RSK_DELETE__
            <MENUITEM id="MENU_ID_VDOREC_CONTINUE" str="STR_ID_VDOREC_CONTINUE"/>
        #endif
        #ifdef __VDOREC_FEATURE_MMS_SUPPORT__
            <MENUITEM id="MENU_ID_VDOREC_TO_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
        #endif
        #ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
            <MENUITEM id="MENU_ID_VDOREC_TO_EMAIL" str="STR_GLOBAL_AS_EMAIL"/>
        #endif
        #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
            <MENUITEM id="MENU_ID_VDOREC_TO_BT" str="STR_GLOBAL_VIA_BLUETOOTH"/>
        #endif
    #endif /*__VDOREC_FEATURE_PREVIEW_SAVED_FILE__*/
    

/*****************************************************************************
 * screen id 
 *****************************************************************************/
   
    <SCREEN id="SCR_ID_VDOREC_APP"/>
    <SCREEN id="SCR_ID_VDOREC_OPTION"/>
    <SCREEN id="SCR_ID_VDOREC_CAMCODER_SETTING"/>
    <SCREEN id="SCR_ID_VDOREC_VIDEO_SETTING"/>
    <SCREEN id="SCR_ID_VDOREC_SAVING"/>
    <SCREEN id="SCR_ID_VDOREC_VIDEO_WB"/>
    <SCREEN id="SCR_ID_VDOREC_EFFECT_SETTING"/>
    <SCREEN id="SCR_ID_VDOREC_RESTORE_DEFAULT"/>
    <SCREEN id="SCR_ID_VDOREC_SAVE_CONFIRM"/>
    <SCREEN id="SCR_ID_VDOREC_PREVIEW_OPTION"/>
    <SCREEN id="SCR_ID_VDOREC_SAVED_PREVIEW"/>
    <SCREEN id="SCR_ID_VDOREC_SEND"/>
    <SCREEN id="SCR_ID_VDOREC_STORAGE"/>
    <SCREEN id="SCR_ID_VDOREC_END"/>


/*****************************************************************************
 * NVRAM id 
 *****************************************************************************/

    /* VdoRec NVRAM */
    <CACHEDATA type="short" id="NVRAM_VDOREC_FILENAME_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>


/*****************************************************************************
 * event handler 
 *****************************************************************************/
   
    #ifdef __MMI_USB_SUPPORT__
        <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_vdorec_usb_mode_hdlr2"/>
    #endif
    #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_vdorec_notify_screen_lock_hdlr"/>
	#endif
    
#endif /*defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)*/
</APP>
