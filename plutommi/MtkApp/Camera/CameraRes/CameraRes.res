
#include "CustomCfg.h"
#include "BuildCfg.h"
#include "MMI_features.h"

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "MMI_features_camera.h"
#include "CustResDef.h"

#include "custom_wap_config.h"            // WAP_CUSTOM_CFG_DEFAULT_HOMEPAGE
#include "SettingDefs.h"                // FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS
#include "custom_mmi_default_value.h"    // LEVEL5
#endif

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */

<APP id="APP_CAMERA"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    package_name = "native.mtk.camcera"         /* Use "native.mtk." as the prefix of application name */
    name = "STR_ID_CAMERA_APP_NAME"                    /* The string to be displayed under the main menu icon */
    #if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    img = "IMG_ID_CAMCO_APP_ICON"   /* Main menu icon image */
    #endif
    launch = "mmi_camera_lauch"               /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                     * the function prototype should be:
                                                     *
                                                     *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                     *
                                                     * Note that the group_id of the application should be returned if launch successfully.
                                                     * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif
#else /*__MMI_APP_MANAGER_SUPPORT__&& __MMI_CAMCORDER__*/
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
   name = "STR_ID_CAMERA_APP_NAME"
#endif
#endif
>

<APPCONCURRENT concurrent_w_order="APP_CAMERA, APP_IMAGEVIEWER"/>

//minus anonymouse memory, and then add the jpeg decode size, when jpeg decode the thumbnail memory is released, so it can minus
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)

#ifdef __MMI_CAMERA_MULTI_OSD_LAYER__
	#if defined(JPEG_SW_DEC_EXT_MIN_MEM_SIZE)
	<MEMORY heap= "0" extra_base="base(SRV_MDI_CAMERA_FULL)- GDI_ASM_MEM_SIZE  - MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE + $(JPEG_SW_DEC_EXT_MIN_MEM_SIZE)" fg="fg(SRV_MDI_CAMERA_FULL)+ $(CAMERA_OSD_BUFFER_SIZE)" inc="CameraGprot.h,jpeg_mem.h,med_global.h"/> 
    #endif
    #if defined(JPEG_HW_DEC_EXT_MIN_MEM_SIZE)
	<MEMORY heap= "0" extra_base="base(SRV_MDI_CAMERA_FULL)- GDI_ASM_MEM_SIZE  - MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE + $(JPEG_HW_DEC_EXT_MIN_MEM_SIZE)" fg="fg(SRV_MDI_CAMERA_FULL)+ $(CAMERA_OSD_BUFFER_SIZE)" inc="CameraGprot.h,jpeg_mem.h,med_global.h"/> 
    #endif
#else
    #if defined(JPEG_SW_DEC_EXT_MIN_MEM_SIZE)
		<MEMORY heap= "0" extra_base="base(SRV_MDI_CAMERA_FULL)- GDI_ASM_MEM_SIZE - MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE + $(JPEG_SW_DEC_EXT_MIN_MEM_SIZE)" fg="$(CAMERA_APP_MEM_POOL)+ fg(SRV_MDI_CAMERA_FULL)" inc="CameraGprot.h,jpeg_mem.h,med_global.h"/> 
    #endif
    #if defined(JPEG_HW_DEC_EXT_MIN_MEM_SIZE)
		<MEMORY heap= "0" extra_base="base(SRV_MDI_CAMERA_FULL)- GDI_ASM_MEM_SIZE - MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE + $(JPEG_HW_DEC_EXT_MIN_MEM_SIZE)" fg="$(CAMERA_APP_MEM_POOL)+ fg(SRV_MDI_CAMERA_FULL)" inc="CameraGprot.h,jpeg_mem.h,med_global.h"/> 
    #endif

#endif

    <CACHEDATA type="short" id="NVRAM_CAM_FILENAME_SEQ_NO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> CameraApp </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SCR_SNAPSHOT_SEQ_NO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> CameraApp </DESCRIPTION>
    </CACHEDATA>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="SlideShowResDef.h,GlobalResDef.h,FileMgrServiceResDef.h,ImageViewerResDef.h,PopulateRes.h"/>
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_CAMERA_APP_NAME"/>
    <STRING id="STR_ID_CAMERA_TO_IMGVIEW"/>
    <STRING id="STR_ID_CAMERA_CAMERA_SETTING"/>
    <STRING id="STR_ID_CAMERA_IMAGE_SETTING"/>



#if defined(__MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__)
    <STRING id="STR_ID_CAMERA_TO_VDOREC"/>
#endif
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    <STRING id="STR_ID_CAMERA_SELF_CAPTURE"/>
#endif
    <STRING id="STR_ID_CAMERA_RESTORE_DEFAULT"/>
#ifdef __CAMERA_FEATURE_WB_MANUAL__
    <STRING id="STR_ID_CAMERA_WB_HELP"/>
#endif
#if defined(__MMI_MMS_POSTCARD__)
    <STRING id="STR_ID_CAMERA_TO_POSTCARD"/>
#endif


#ifdef __CAMERA_FEATURE_EFFECT__
    
    <STRING id="STR_ID_CAMERA_EFFECT_SETTING"/>	/* use as STR_ID_CAMERA_EFFECT_START. Don't insert anyting between it and it's next*/
#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
    <STRING id="STR_ID_CAMERA_EFFECT_NORMAL"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
    <STRING id="STR_ID_CAMERA_EFFECT_GRAYSCALE"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
    <STRING id="STR_ID_CAMERA_EFFECT_SEPIA"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
    <STRING id="STR_ID_CAMERA_EFFECT_SEPIA_GREEN"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
    <STRING id="STR_ID_CAMERA_EFFECT_SEPIA_BLUE"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
    <STRING id="STR_ID_CAMERA_EFFECT_COLOR_INVERT"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
    <STRING id="STR_ID_CAMERA_EFFECT_GRAY_INVERT"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
    <STRING id="STR_ID_CAMERA_EFFECT_BLACKBOARD"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
    <STRING id="STR_ID_CAMERA_EFFECT_WHITEBOARD"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
    <STRING id="STR_ID_CAMERA_EFFECT_COPPER_CARVING"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
    <STRING id="STR_ID_CAMERA_EFFECT_BLUE_CARVING"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
    <STRING id="STR_ID_CAMERA_EFFECT_EMBOSSMENT"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
    <STRING id="STR_ID_CAMERA_EFFECT_CONTRAST"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
    <STRING id="STR_ID_CAMERA_EFFECT_JEAN"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
    <STRING id="STR_ID_CAMERA_EFFECT_SKETCH"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_OIL__
    <STRING id="STR_ID_CAMERA_EFFECT_OIL"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_1"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_2"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_3"/>
#endif
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_SET"/>
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT"/>
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_BRIGHTNESS"/>
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_SATURATION"/>
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_CONTRAST"/>
    <STRING id="STR_ID_CAMERA_EFFECT_CUSTOM_FX_HUE"/>
#endif
#ifdef __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__
#ifdef __CAMERA_FEATURE_EFFECT_EFFECT_LOMO__
		<STRING id="STR_ID_CAMERA_EFFECT_LOMO"/>
#endif 
#ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_RED__
		<STRING id="STR_ID_CAMERA_EFFECT_COLOR_RED"/>
#endif 
#ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_YELLOW__
		<STRING id="STR_ID_CAMERA_EFFECT_COLOR_YELLOW"/>
#endif 
#ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_GREEN__
		<STRING id="STR_ID_CAMERA_EFFECT_COLOR_GREEN"/>
#endif 
#ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_BLUE__
		<STRING id="STR_ID_CAMERA_EFFECT_COLOR_BLUE"/>
#endif 
#endif   
#endif /* __CAMERA_FEATURE_EFFECT__ */

#ifdef __CAMERA_FEATURE_ADD_FRAME__
    <STRING id="STR_ID_CAMERA_ADD_FRAME"/>	/*use as STR_ID_CAMERA_ADD_FRAME_START*/
    <STRING id="STR_ID_CAMERA_ADD_FRAME_OFF"/>

#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_NORMAL"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_TILESHOT"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_COLOR_IDX"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_1__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_1"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_2__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_2"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_3__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_3"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_4__)|| defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_4"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_5__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_5"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_6__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_6"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_7__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_7"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_8__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_8"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_9__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_9"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_10__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__)
    <STRING id="STR_ID_CAMERA_ADD_FRAME_10"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_CUSTOM_1"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_CUSTOM_2"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_CUSTOM_3"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_CUSTOM_4"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
    <STRING id="STR_ID_CAMERA_ADD_FRAME_CUSTOM_5"/>
#endif
    
#endif	/*__CAMERA_FEATURE_ADD_FRAME__*/

    <STRING id="STR_ID_CAMERA_DELETE_ASK"/>

#ifdef __CAMERA_FEATURE_CONT_SHOT__
		<STRING id="STR_ID_CAMERA_CONT_SHOT"/>	/*use as STR_ID_CAMERA_CONT_SHOT_START*/
        <STRING id="STR_ID_CAMERA_CONT_SHOT_OFF"/>
        <STRING id="STR_ID_CAMERA_CONT_SHOT_1"/>
    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
        <STRING id="STR_ID_CAMERA_CONT_SHOT_2"/>
    #endif
    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
        <STRING id="STR_ID_CAMERA_CONT_SHOT_3"/>
    #endif
    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        <STRING id="STR_ID_CAMERA_CONT_SHOT_BURST"/>
    #endif
    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        <STRING id="STR_ID_CAMERA_CONT_SHOT_TILE"/>
    #endif
#endif	/* __CAMERA_FEATURE_CONT_SHOT__ */

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
		<STRING id="STR_ID_CAMERA_DELAY_TIMER"/>	/* use as STR_ID_CAMERA_DELAY_TIMER_START */
        <STRING id="STR_ID_CAMERA_DELAY_TIMER_OFF"/>
        <STRING id="STR_ID_CAMERA_DELAY_TIMER_1"/>
    #ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
        <STRING id="STR_ID_CAMERA_DELAY_TIMER_2"/>
    #endif
    #ifdef __CAMERA_FEATURE_DELAY_TIMER_3__
        <STRING id="STR_ID_CAMERA_DELAY_TIMER_3"/>
    #endif
#endif	/*__CAMERA_FEATURE_DELAY_TIMER__*/

#ifdef __CAMERA_FEATURE_WB__
    <STRING id="STR_ID_CAMERA_WB"/>	/* use as STR_ID_CAMERA_WB_START */
    #ifdef __CAMERA_FEATURE_WB_AUTO__
        <STRING id="STR_ID_CAMERA_WB_AUTO"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
        <STRING id="STR_ID_CAMERA_WB_DAYLIGHT"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
        <STRING id="STR_ID_CAMERA_WB_TUNGSTEN"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
        <STRING id="STR_ID_CAMERA_WB_FLUORESCENT"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_CLOUD__
        <STRING id="STR_ID_CAMERA_WB_CLOUD"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
        <STRING id="STR_ID_CAMERA_WB_INCANDESCENCE"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_MANUAL__
        <STRING id="STR_ID_CAMERA_WB_MANUAL"/>
    #endif
#endif
        
#ifdef __CAMERA_AUTOFOCUS_METERING__
    <STRING id="STR_ID_CAMERA_AUTOFOCUS_METERING"/>	/* use as STR_ID_CAMERA_AUTOFOCUS_START*/

    #ifdef __CAMERA_AUTOFOCUS_1_ZONE__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_1_ZONE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_3_ZONE__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_3_ZONE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_5_ZONE__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_5_ZONE"/>
    #endif

#endif	/*__CAMERA_AUTOFOCUS_METERING__*/

#ifdef __CAMERA_AUTOFOCUS_MODE__
    <STRING id="STR_ID_CAMERA_AUTOFOCUS_MODE"/>	/* use as STR_ID_CAMERA_AUTOFOCUS_MODE_START*/

    #ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_MODE_AUTO"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_MODE_MACRO"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_MODE_INFINITE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        <STRING id="STR_ID_CAMERA_AUTOFOCUS_MODE_MANUAL"/>
    #endif
#endif	/*__CAMERA_AUTOFOCUS_MODE__*/
        
#ifdef __CAMERA_DSC_MODE__
    <STRING id="STR_ID_CAMERA_DSC_MODE"/>		/* use as STR_ID_CAMERA_DSC_MODE_START*/
    #ifdef __CAMERA_DSC_MODE_AUTO__
        <STRING id="STR_ID_CAMERA_DSC_MODE_AUTO"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
        <STRING id="STR_ID_CAMERA_DSC_MODE_SHUTTER_PRI"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
        <STRING id="STR_ID_CAMERA_DSC_MODE_APERTURE_PRI"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_PORTRAIT__
        <STRING id="STR_ID_CAMERA_DSC_MODE_PORTRAIT"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_LANDSCAPE__
        <STRING id="STR_ID_CAMERA_DSC_MODE_LANDSCAPE"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_SPORT__
        <STRING id="STR_ID_CAMERA_DSC_MODE_SPORT"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_FLOWER__
        <STRING id="STR_ID_CAMERA_DSC_MODE_FLOWER"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_NIGHT__
        <STRING id="STR_ID_CAMERA_DSC_MODE_NIGHT"/>
    #endif
    #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        <STRING id="STR_ID_CAMERA_ISO"/>
    #endif
#endif	/*__CAMERA_DSC_MODE__*/

#if defined(__CAMERA_FEATURE_FLASH__)
		<STRING id="STR_ID_CAMERA_FLASH"/>	/* use as STR_ID_CAMERA_FLASH_START */
#endif
#if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
    <STRING id="STR_ID_CAMERA_FLASH_OFF"/>
    <STRING id="STR_ID_CAMERA_FLASH_ON"/>
#endif
#ifdef __CAMERA_FEATURE_FLASH__
    #ifdef __CAMERA_FEATURE_FLASH_AUTO__
        <STRING id="STR_ID_CAMERA_FLASH_AUTO"/>
    #endif
    #ifdef __CAMERA_FEATURE_FLASH_REDEYE__
        <STRING id="STR_ID_CAMERA_FLASH_REDEYE"/>
    #endif
#endif


#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT"/>	/* use as STR_ID_CAMERA_LED_HIGHLIGHT_START*/

#if defined(__CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__)
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_OFF"/>
#endif
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_ON"/>
#endif
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_WHITE"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_RED"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_GREEN"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_BLUE"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_YELLOW"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_PURPLE"/>
    <STRING id="STR_ID_CAMERA_LED_HIGHLIGHT_CYAN"/>
#endif
#endif	/*__CAMERA_FEATURE_LED_HIGHLIGHT__*/
    
#ifdef __CAMERA_FEATURE_SHUTTER_SOUND__
    <STRING id="STR_ID_CAMERA_SHUTTER_SOUND"/>	/* use as STR_ID_CAMERA_SHUTTER_SOUND_START*/
    #ifdef __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
        <STRING id="STR_ID_CAMERA_SHUTTER_SOUND_OFF"/>
    #endif
    #ifdef __CAMERA_FEATURE_SHUTTER_SOUND_1__
        <STRING id="STR_ID_CAMERA_SHUTTER_SOUND_1"/>
    #endif
    #ifdef __CAMERA_FEATURE_SHUTTER_SOUND_2__
        <STRING id="STR_ID_CAMERA_SHUTTER_SOUND_2"/>
    #endif
    #ifdef __CAMERA_FEATURE_SHUTTER_SOUND_3__
        <STRING id="STR_ID_CAMERA_SHUTTER_SOUND_3"/>
    #endif
#endif

#ifdef __CAMERA_FEATURE_EV__
    <STRING id="STR_ID_CAMERA_EV"/>		/*use as STR_ID_CAMERA_EV_START*/
    #ifdef __CAMERA_FEATURE_EV_4__
        <STRING id="STR_ID_CAMERA_EV_N4"/>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <STRING id="STR_ID_CAMERA_EV_N3"/>
    #endif
    #ifdef __CAMERA_FEATURE_EV_2__
        <STRING id="STR_ID_CAMERA_EV_N2"/>
    #endif
    <STRING id="STR_ID_CAMERA_EV_N1"/>
    <STRING id="STR_ID_CAMERA_EV_0"/>
    <STRING id="STR_ID_CAMERA_EV_P1"/>
    #ifdef __CAMERA_FEATURE_EV_2__
        <STRING id="STR_ID_CAMERA_EV_P2"/>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <STRING id="STR_ID_CAMERA_EV_P3"/>
    #endif
    #ifdef __CAMERA_FEATURE_EV_4__
        <STRING id="STR_ID_CAMERA_EV_P4"/>
    #endif
#endif

#ifdef __CAMERA_FEATURE_CONTRAST__
    <STRING id="STR_ID_CAMERA_CONTRAST"/>	/*use as STR_ID_CAMERA_CONTRAST_START*/
    <STRING id="STR_ID_CAMERA_CONTRAST_HIGH"/>
    <STRING id="STR_ID_CAMERA_CONTRAST_MEDIUM"/>
    <STRING id="STR_ID_CAMERA_CONTRAST_LOW"/>
#endif

#ifdef __CAMERA_FEATURE_NIGHT__
    <STRING id="STR_ID_CAMERA_NIGHT"/>	/* use as STR_ID_CAMERA_NIGHT_START*/
    <STRING id="STR_ID_CAMERA_NIGHT_OFF"/>
    <STRING id="STR_ID_CAMERA_NIGHT_ON"/>
#endif	/*__CAMERA_FEATURE_NIGHT__*/

#ifdef __CAMERA_FEATURE_BANDING__
    <STRING id="STR_ID_CAMERA_BANDING"/>	/*use as STR_ID_CAMERA_BANDING_START*/
    <STRING id="STR_ID_CAMERA_BANDING_50HZ">"50Hz"</STRING>
    <STRING id="STR_ID_CAMERA_BANDING_60HZ">"60Hz"</STRING>
#endif

    <STRING id="STR_ID_CAMERA_IMAGE_SIZE"/>	/* use as STR_ID_CAMERA_IMAGE_SIZE_START*/
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
		<STRING id=STR(CAMERA_COMPOSE_STRID(SS_SUFFIX))>STR(SS_SUFFIX)</STRING>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
		<STRING id=STR(CAMERA_COMPOSE_STRID(S_SUFFIX))>STR(S_SUFFIX)</STRING>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
		<STRING id=STR(CAMERA_COMPOSE_STRID(M_SUFFIX))>STR(M_SUFFIX)</STRING>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
		<STRING id=STR(CAMERA_COMPOSE_STRID(L_SUFFIX))>STR(L_SUFFIX)</STRING>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
		<STRING id=STR(CAMERA_COMPOSE_STRID(LL_SUFFIX))>STR(LL_SUFFIX)</STRING>
#endif


    <STRING id="STR_ID_CAMERA_IMAGE_QTY"/>	/* use as STR_ID_CAMERA_IMAGE_QTY_START*/
#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
    <STRING id="STR_ID_CAMERA_IMAGE_QTY_LOW"/>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
    <STRING id="STR_ID_CAMERA_IMAGE_QTY_NORMAL"/>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
    <STRING id="STR_ID_CAMERA_IMAGE_QTY_HIGH"/>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
    <STRING id="STR_ID_CAMERA_IMAGE_QTY_FINE"/>
#endif

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
    <STRING id="STR_ID_CAMERA_ISO"/>	/*use as STR_ID_CAMERA_ISO_START*/
    #ifdef __CAEMRA_FEATURE_ISO_AUTO__
        <STRING id="STR_ID_CAMERA_ISO_AUTO"/>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_100__
        <STRING id="STR_ID_CAMERA_ISO_100"/>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_200__
        <STRING id="STR_ID_CAMERA_ISO_200"/>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_400__
        <STRING id="STR_ID_CAMERA_ISO_400"/>
    #endif
#endif	/*STR_ID_CAMERA_ISO*/

#ifdef __CAMERA_FEATURE_AE_METER__	
    <STRING id="STR_ID_CAMERA_AE_METER"/>	/*use as STR_ID_CAMERA_AE_METER_START*/
    #ifdef __CAMERA_FEATURE_AE_METER_AUTO__
        <STRING id="STR_ID_CAMERA_AE_METER_AUTO"/>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_SPOT__
        <STRING id="STR_ID_CAMERA_AE_METER_SPOT"/>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_CENTER__
        <STRING id="STR_ID_CAMERA_AE_METER_CENTER"/>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
        <STRING id="STR_ID_CAMERA_AE_METER_AVERAGE"/>
    #endif
#endif	/*__CAMERA_FEATURE_AE_METER__*/

    <STRING id="STR_ID_CAMERA_NOTIFY_NO_MEMORY_CARD"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_WRITE_PROTECTION"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_HW_NOT_READY"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_ERROR"/>
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    <STRING id="STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_ON"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_OFF"/>
    <STRING id="STR_ID_CAMERA_NOFITY_SELF_CAPTURE_SUBLCD_PREVIEW"/>
#endif
#ifdef __CAMERA_FEATURE_CONT_SHOT__
    <STRING id="STR_ID_CAMERA_NOFIFY_CAPTURING"/>
#endif
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    <STRING id="STR_ID_CAMERA_NOFIFY_BURST_CAPTURING"/>
#endif
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
    <STRING id="STR_ID_CAMERA_NOTIFY_SAVING"/>
#endif
    <STRING id="STR_ID_CAMERA_NOTIFY_SAVING_FAIL"/>
#ifdef __CAMERA_FEATURE_RESTORE_DEFAULT__    
    <STRING id="STR_ID_CAMERA_NOTIFY_RESTORE_DEFAULT_CONFIRM"/>
#endif

    <STRING id="STR_ID_CAMERA_NOTIFY_CREATE_DIR_ERR"/>
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    <STRING id="STR_ID_CAMERA_NOTIFY_SAVE_CONFIRM"/>
#endif
    <STRING id="STR_ID_CAMERA_NOTIFY_CAPTURE_FAILED"/>
#ifdef __MMI_SCREEN_SNAPSHOT__
    <STRING id="STR_ID_CAMERA_NOTIFY_SCREEN_CAPTURED"/>
#endif
    <STRING id="STR_ID_CAMERA_NOTIFY_BT_IS_WORKING"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_BEARER_IS_ACTIVE"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_XENON_TIMEOUT"/>
    <STRING id="STR_ID_CAMERA_NOTIFY_XENON_LOW_BATTERY"/>
#ifdef __MMI_CAMERA_23KEY__
    <STRING id="STR_ID_CAMERA_RSK_CAPTURE"/>
#endif




    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#if defined(__DIRECT_SENSOR_SUPPORT__) && ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))
    #define CAMERA_OSD_PATH    CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD_DIRECT_SENSOR\\\\"
#else
    #define CAMERA_OSD_PATH    CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\"
#endif

#ifndef __MMI_CAMERA_SLIM__
#if defined(__MMI_CAMERA_SIMPLE_UI__) && !defined(__CAMERA_FEATURE_FTE_SUPPORT__)
    <IMAGE id="IMG_ID_CAMERA_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\SUBMENU\\\\Camera\\\\SB_camera.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_CAMERA_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\SB_camera.bmp"</IMAGE>
#endif /*__MMI_CAMERA_SIMPLE_UI__*/
#endif

#ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\Camera\\\\SB_Camera.gif"</IMAGE>
#endif

#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
    <IMAGE id="IMG_ID_CAMERA_FORWARD_TO_MMS">CAMERA_OSD_PATH"to_mms.bmp"</IMAGE>
#endif

<!--------White banlance icon ------------>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
	  <IMAGE id="IMG_ID_CAMCO_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Camera.png"</IMAGE>
#endif
#endif
#ifdef __CAMERA_FEATURE_DRAW_ICON__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
#ifdef __CAMERA_FEATURE_WB__
    #ifdef __CAMERA_FEATURE_WB_AUTO__
    #ifdef	__MMI_CAMERA_SIMPLE_UI__
    		<IMAGE id="IMG_ID_CAMERA_OSD_WB_AUTO">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_AUTO">CAMERA_OSD_PATH"wb_auto.bmp"</IMAGE>
    #endif
    #endif
    #ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_DAYLIGHT">CAMERA_OSD_PATH"wb_daylight.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_TUNGSTEN">CAMERA_OSD_PATH"wb_tungsten.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_FLUORESCENT">CAMERA_OSD_PATH"wb_fluorescent.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_WB_CLOUD__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_CLOUD">CAMERA_OSD_PATH"wb_cloudy.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_INCANDESCENCE">CAMERA_OSD_PATH"wb_incandescent.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_WB_MANUAL__
        <IMAGE id="IMG_ID_CAMERA_OSD_WB_MANUAL">CAMERA_OSD_PATH"wb_manual.bmp"</IMAGE>
    #endif
#endif

<!--------Flash icon ------------>
#ifdef __CAMERA_FEATURE_FLASH__
    <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_OFF">CAMERA_OSD_PATH"flash_off.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_ON">CAMERA_OSD_PATH"flash_force_on.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_FLASH_CHARGING">CAMERA_OSD_PATH"flash_charging.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_FLASH_FULL">CAMERA_OSD_PATH"flash_full.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_FLASH_AUTO__
        <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_AUTO">CAMERA_OSD_PATH"flash_auto.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_FLASH_REDEYE__
        <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_REDEYE">CAMERA_OSD_PATH"flash_red_eye.bmp"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_OFF">CAMERA_OSD_PATH"flash_off.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_FLASH_ON">CAMERA_OSD_PATH"flash_force_on.bmp"</IMAGE>
#endif

<!--------LED highlight icon ------------>
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    <IMAGE id="IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef	__MMI_CAMERA_SIMPLE_UI__
    		<IMAGE id="IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF">CAMERA_OSD_PATH"led_off.bmp"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_ON">CAMERA_OSD_PATH"led_on.bmp"</IMAGE>
#endif

<!--------EV icon ------------>
#ifdef __CAMERA_FEATURE_EV__
#ifdef __MMI_CAMERA_SIMPLE_UI__
		<IMAGE id="IMG_ID_CAMERA_OSD_EV_HEAD">CAMERA_OSD_PATH"ev.bmp"</IMAGE>
		<IMAGE id="IMG_ID_CAMERA_OSD_EV_HEAD_P">CAMERA_OSD_PATH"ev_p.bmp"</IMAGE>
		<IMAGE id="IMG_ID_CAMERA_OSD_EV_HEAD_0">CAMERA_OSD_PATH"ev_n.bmp"</IMAGE>
		<IMAGE id="IMG_ID_CAMERA_OSD_EV_HEAD_N">CAMERA_OSD_PATH"ev_m.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>

    #ifdef __CAMERA_FEATURE_EV_4__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N4">CAMERA_OSD_PATH"ev_20.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N3">CAMERA_OSD_PATH"ev_15.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_2__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N2">CAMERA_OSD_PATH"ev_10.bmp"</IMAGE>
    #endif
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N1">CAMERA_OSD_PATH"ev_05.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_0">CAMERA_OSD_PATH"ev_0.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P1">CAMERA_OSD_PATH"ev_05.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_EV_2__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P2">CAMERA_OSD_PATH"ev_10.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P3">CAMERA_OSD_PATH"ev_15.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_4__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P4">CAMERA_OSD_PATH"ev_20.bmp"</IMAGE>
    #endif
#else
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_EV_4__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N4">CAMERA_OSD_PATH"ev_n4.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N3">CAMERA_OSD_PATH"ev_n3.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_2__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N2">CAMERA_OSD_PATH"ev_n2.bmp"</IMAGE>
    #endif
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_N1">CAMERA_OSD_PATH"ev_n1.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_0">CAMERA_OSD_PATH"ev_0.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P1">CAMERA_OSD_PATH"ev_p1.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_EV_2__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P2">CAMERA_OSD_PATH"ev_p2.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_3__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P3">CAMERA_OSD_PATH"ev_p3.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EV_4__
        <IMAGE id="IMG_ID_CAMERA_OSD_EV_P4">CAMERA_OSD_PATH"ev_p4.bmp"</IMAGE>
    #endif
#endif /*__MMI_CAMERA_SIMPLE_UI__*/
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_INC">CAMERA_OSD_PATH"ev_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_INC_SEL">CAMERA_OSD_PATH"ev_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_INC_DIS">CAMERA_OSD_PATH"ev_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_DEC">CAMERA_OSD_PATH"ev_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_DEC_SEL">CAMERA_OSD_PATH"ev_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_EV_DEC_DIS">CAMERA_OSD_PATH"ev_dec_dis.bmp"</IMAGE>
#endif

<!--------Image size icon ------------>
	<IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_SIZE_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
		<IMAGE id=STR(CAMERA_COMPOSE_IMGID(SS_SUFFIX))>CAMERA_OSD_PATH"imagesize_"SS_SUFFIX".bmp"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
		<IMAGE id=STR(CAMERA_COMPOSE_IMGID(S_SUFFIX))>CAMERA_OSD_PATH"imagesize_"S_SUFFIX".bmp"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
		<IMAGE id=STR(CAMERA_COMPOSE_IMGID(M_SUFFIX))>CAMERA_OSD_PATH"imagesize_"M_SUFFIX".bmp"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
		<IMAGE id=STR(CAMERA_COMPOSE_IMGID(L_SUFFIX))>CAMERA_OSD_PATH"imagesize_"L_SUFFIX".bmp"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
		<IMAGE id=STR(CAMERA_COMPOSE_IMGID(LL_SUFFIX))>CAMERA_OSD_PATH"imagesize_"LL_SUFFIX".bmp"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_NIGHT__
    <IMAGE id="IMG_ID_CAMERA_OSD_NIGHT_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef	__MMI_CAMERA_SIMPLE_UI__
    		<IMAGE id="IMG_ID_CAMERA_OSD_NIGHT_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_CAMERA_OSD_NIGHT_OFF">CAMERA_OSD_PATH"night_off.bmp"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_CAMERA_OSD_NIGHT_ON">CAMERA_OSD_PATH"night_on.bmp"</IMAGE>
#endif

    <IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_QTY_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
    <IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_QTY_LOW">CAMERA_OSD_PATH"capqty_low.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
    <IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_QTY_NORMAL">CAMERA_OSD_PATH"capqty_normal.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
    <IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_QTY_HIGH">CAMERA_OSD_PATH"capqty_good.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
    <IMAGE id="IMG_ID_CAMERA_OSD_IMAGE_QTY_FINE">CAMERA_OSD_PATH"capqty_fine.bmp"</IMAGE>
#endif

#ifdef __CAMERA_AUTOFOCUS_METERING__
        <IMAGE id="IMG_ID_CAMERA_OSD_FOCUS_METER_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_AUTOFOCUS_1_ZONE__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_1_ZONE">CAMERA_OSD_PATH"aemeter_spot.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_3_ZONE__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_3_ZONE">CAMERA_OSD_PATH"aemeter_center_weight.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_5_ZONE__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_5_ZONE">CAMERA_OSD_PATH"aemeter_average.bmp"</IMAGE>
    #endif
#endif

#ifdef __CAMERA_AUTOFOCUS_MODE__
    <IMAGE id="IMG_ID_CAMERA_OSD_FOCUS_MODE_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_AUTO">CAMERA_OSD_PATH"afmode_auto.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_MACRO">CAMERA_OSD_PATH"afmode_macro.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_INFINITE">CAMERA_OSD_PATH"afmode_cont.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        <IMAGE id="IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_MANUAL">CAMERA_OSD_PATH"afmode_manual.bmp"</IMAGE>
    #endif
#endif

#ifdef __CAMERA_DSC_MODE__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_DSC_MODE_AUTO__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_AUTO">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_SHUTTER_PRI">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_APERTURE_PRI">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_PORTRAIT__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_PORTRAIT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_LANDSCAPE__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_LANDSCAPE">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_SPORT__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_SPORT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_FLOWER__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_FLOWER">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_DSC_MODE_NIGHT__
        <IMAGE id="IMG_ID_CAMERA_OSD_DSC_MODE_NIGHT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
#endif

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        <IMAGE id="IMG_ID_CAMERA_OSD_ISO_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAEMRA_FEATURE_ISO_AUTO__
        <IMAGE id="IMG_ID_CAMERA_OSD_ISO_AUTO">CAMERA_OSD_PATH"iso_auto.bmp"</IMAGE>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_100__
        <IMAGE id="IMG_ID_CAMERA_OSD_ISO_100">CAMERA_OSD_PATH"iso_100.bmp"</IMAGE>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_200__
        <IMAGE id="IMG_ID_CAMERA_OSD_ISO_200">CAMERA_OSD_PATH"iso_200.bmp"</IMAGE>
    #endif
    #ifdef __CAEMRA_FEATURE_ISO_400__
        <IMAGE id="IMG_ID_CAMERA_OSD_ISO_400">CAMERA_OSD_PATH"iso_400.bmp"</IMAGE>
    #endif
#endif

#ifdef __CAMERA_FEATURE_AE_METER__
        <IMAGE id="IMG_ID_CAMERA_OSD_AE_METER_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_AE_METER_AUTO__
        <IMAGE id="IMG_ID_CAMERA_OSD_AE_METER_AUTO">CAMERA_OSD_PATH"aemeter_auto.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_SPOT__
        <IMAGE id="IMG_ID_CAMERA_OSD_AE_METER_SPOT">CAMERA_OSD_PATH"aemeter_spot.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_CENTER__
        <IMAGE id="IMG_ID_CAMERA_OSD_AE_METER_CENTER">CAMERA_OSD_PATH"aemeter_center_weight.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
        <IMAGE id="IMG_ID_CAMERA_OSD_AE_METER_AVERAGE">CAMERA_OSD_PATH"aemeter_average.bmp"</IMAGE>
    #endif
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME__
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_1">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_2">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_3">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_4">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_5">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_6">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_7">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_8">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_9">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
    <IMAGE id="IMG_ID_CAMERA_OSD_ADD_FRAME_10">CAMERA_OSD_PATH"CAM_add_frame.bmp"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_1">CAMERA_OSD_PATH"CAM_frame_01.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_2">CAMERA_OSD_PATH"CAM_frame_02.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_3">CAMERA_OSD_PATH"CAM_frame_03.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_4">CAMERA_OSD_PATH"CAM_frame_04.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_5">CAMERA_OSD_PATH"CAM_frame_05.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_6">CAMERA_OSD_PATH"CAM_frame_06.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_7">CAMERA_OSD_PATH"CAM_frame_07.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_8">CAMERA_OSD_PATH"CAM_frame_08.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_9">CAMERA_OSD_PATH"CAM_frame_09.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
    <IMAGE id="IMG_ID_CAMERA_ADD_FRAME_10">CAMERA_OSD_PATH"CAM_frame_10.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_1">CAMERA_OSD_PATH"CAM_tile_frame_01.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_2">CAMERA_OSD_PATH"CAM_tile_frame_02.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_3">CAMERA_OSD_PATH"CAM_tile_frame_03.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_4">CAMERA_OSD_PATH"CAM_tile_frame_04.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_5">CAMERA_OSD_PATH"CAM_tile_frame_05.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_6">CAMERA_OSD_PATH"CAM_tile_frame_06.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_7">CAMERA_OSD_PATH"CAM_tile_frame_07.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_8">CAMERA_OSD_PATH"CAM_tile_frame_08.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_9">CAMERA_OSD_PATH"CAM_tile_frame_09.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
    <IMAGE id="IMG_ID_CAMERA_TILE_ADD_FRAME_10">CAMERA_OSD_PATH"CAM_tile_frame_10.gif"</IMAGE>
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_1">CAMERA_OSD_PATH"CAM_color_idx_frame_01.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_1">CAMERA_OSD_PATH"CAM_color_idx2_frame_01.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_2">CAMERA_OSD_PATH"CAM_color_idx_frame_02.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_2">CAMERA_OSD_PATH"CAM_color_idx2_frame_02.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_3">CAMERA_OSD_PATH"CAM_color_idx_frame_03.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_3">CAMERA_OSD_PATH"CAM_color_idx2_frame_03.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_4">CAMERA_OSD_PATH"CAM_color_idx_frame_04.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_4">CAMERA_OSD_PATH"CAM_color_idx2_frame_04.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_5">CAMERA_OSD_PATH"CAM_color_idx_frame_05.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_5">CAMERA_OSD_PATH"CAM_color_idx2_frame_05.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_6">CAMERA_OSD_PATH"CAM_color_idx_frame_06.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_6">CAMERA_OSD_PATH"CAM_color_idx2_frame_06.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_7">CAMERA_OSD_PATH"CAM_color_idx_frame_07.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_7">CAMERA_OSD_PATH"CAM_color_idx2_frame_07.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_8">CAMERA_OSD_PATH"CAM_color_idx_frame_08.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_8">CAMERA_OSD_PATH"CAM_color_idx2_frame_08.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_9">CAMERA_OSD_PATH"CAM_color_idx_frame_09.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_9">CAMERA_OSD_PATH"CAM_color_idx2_frame_09.gif"</IMAGE>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_10">CAMERA_OSD_PATH"CAM_color_idx_frame_10.gif"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_10">CAMERA_OSD_PATH"CAM_color_idx2_frame_10.gif"</IMAGE>
#endif
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */

#ifdef __CAMERA_FEATURE_CONT_SHOT__
    <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef	__MMI_CAMERA_SIMPLE_UI__
    		<IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_1">CAMERA_OSD_PATH"cshot.bmp"</IMAGE>
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_2">CAMERA_OSD_PATH"cshot.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_3">CAMERA_OSD_PATH"cshot.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_BURST">CAMERA_OSD_PATH"cshot.bmp"</IMAGE>
	    #endif
    #else
        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_OFF">CAMERA_OSD_PATH"cshot_off.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_1">CAMERA_OSD_PATH"cshot_1.bmp"</IMAGE>
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_2">CAMERA_OSD_PATH"cshot_3.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_3">CAMERA_OSD_PATH"cshot_5.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
	        <IMAGE id="IMG_ID_CAMERA_OSD_CONT_SHOT_BURST">CAMERA_OSD_PATH"cshot_burst.bmp"</IMAGE>
	    #endif
    #endif
#endif

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
    <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_START">CAMERA_OSD_PATH"selftimer_off.bmp"</IMAGE>
    #ifdef	__MMI_CAMERA_SIMPLE_UI__
    		<IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_1">CAMERA_OSD_PATH"selftimer.bmp"</IMAGE>
	    #ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
	        <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_2">CAMERA_OSD_PATH"selftimer.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_DELAY_TIMER_3__
	        <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_3">CAMERA_OSD_PATH"selftimer.bmp"</IMAGE>
	    #endif
    #else
        <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_OFF">CAMERA_OSD_PATH"selftimer_off.bmp"</IMAGE>
	    <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_1">CAMERA_OSD_PATH"selftimer_5s.bmp"</IMAGE>
	    #ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
	        <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_2">CAMERA_OSD_PATH"selftimer_10s.bmp"</IMAGE>
	    #endif
	    #ifdef __CAMERA_FEATURE_DELAY_TIMER_3__
	        <IMAGE id="IMG_ID_CAMERA_OSD_DELAY_TIMER_3">CAMERA_OSD_PATH"selftimer_15s.bmp"</IMAGE>
	    #endif
    #endif
#endif

#ifdef __CAMERA_FEATURE_EFFECT__
    <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_START">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_NORMAL">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_GRAYSCALE">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_SEPIA">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_SEPIA_GREEN">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_SEPIA_BLUE">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_COLOR_INVERT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_GRAY_INVERT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_BLACKBOARD">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_WHITEBOARD">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_COPPER_CARVING">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_BLUE_CARVING">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_EMBOSSMENT">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_CONTRAST">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_JEAN__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_JEAN">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_SKETCH">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_OIL__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_OIL">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_1">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_2">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
        <IMAGE id="IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_3">CAMERA_OSD_PATH"should_not_exist_only_add_enum.bmp"</IMAGE>
    #endif
#endif
#endif
//here is OSD icon part end

    <IMAGE id="IMG_ID_CAMERA_OSD_CAPTURE">CAMERA_OSD_PATH"capture.bmp"</IMAGE>
#ifndef __MMI_CAMERA_SIMPLE_UI__    
    <IMAGE id="IMG_ID_CAMERA_OSD_CAPTURE_SEL">CAMERA_OSD_PATH"capturing.bmp"</IMAGE>
#ifdef __CAMERA_FEATURE_WB_MANUAL__
    <IMAGE id="IMG_ID_CAMERA_OSD_SAVE">CAMERA_OSD_PATH"save.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_SAVE_SEL">CAMERA_OSD_PATH"save_down.bmp"</IMAGE>
#endif
#endif /* __MMI_CAMERA_SIMPLE_UI__ */

#ifdef __CAMERA_FEATURE_ZOOM__
#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_HEAD">CAMERA_OSD_PATH"zoom_head.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC">CAMERA_OSD_PATH"zoom_in.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC">CAMERA_OSD_PATH"zoom_out.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_SEL">CAMERA_OSD_PATH"zoom_in_down.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL">CAMERA_OSD_PATH"zoom_out_down.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_DIS">CAMERA_OSD_PATH"zoom_in_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_DIS">CAMERA_OSD_PATH"zoom_out_dis.png"</IMAGE>
#elif defined(__MMI_CAMERA_SIMPLE_UI__)
    #ifdef __CAMERA_FEATURE_DRAW_BUTTONS__
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_HEAD">CAMERA_OSD_PATH"zoom_head.9slice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC">CAMERA_OSD_PATH"zoom_in.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC">CAMERA_OSD_PATH"zoom_out.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_SEL">CAMERA_OSD_PATH"zoom_in_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL">CAMERA_OSD_PATH"zoom_out_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_DIS">CAMERA_OSD_PATH"zoom_in_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_DIS">CAMERA_OSD_PATH"zoom_out_dis.bmp"</IMAGE>
    #endif
#else
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_HEAD">CAMERA_OSD_PATH"zoom_head.9slice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_00">CAMERA_OSD_PATH"\\\\num_0.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_01">CAMERA_OSD_PATH"\\\\num_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_02">CAMERA_OSD_PATH"\\\\num_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_03">CAMERA_OSD_PATH"\\\\num_3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_04">CAMERA_OSD_PATH"\\\\num_4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_05">CAMERA_OSD_PATH"\\\\num_5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_06">CAMERA_OSD_PATH"\\\\num_6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_07">CAMERA_OSD_PATH"\\\\num_7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_08">CAMERA_OSD_PATH"\\\\num_8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_09">CAMERA_OSD_PATH"\\\\num_9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_DOT">CAMERA_OSD_PATH"\\\\num_dot.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_NUM_DASH">CAMERA_OSD_PATH"\\\\num_dash.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_BAR">CAMERA_OSD_PATH"zoom_head.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC">CAMERA_OSD_PATH"zoom_in.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC">CAMERA_OSD_PATH"zoom_out.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_SEL">CAMERA_OSD_PATH"zoom_in_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL">CAMERA_OSD_PATH"zoom_out_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_INC_DIS">CAMERA_OSD_PATH"zoom_in_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CAMERA_OSD_ZOOM_DEC_DIS">CAMERA_OSD_PATH"zoom_out_dis.bmp"</IMAGE>
#endif	/*__MMI_CAMERA_SIMPLE_UI__*/
#endif



    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */    
#if defined(__MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__)
    <MENUITEM id="MENU_ID_CAMERA_TO_VDOREC_APP" str="STR_ID_CAMERA_TO_VDOREC" highlight="mmi_camera_highlight_to_vdorec_app"/>
#endif
    <MENUITEM id="MENU_ID_CAMERA_TO_IMGVIEW" str="STR_ID_CAMERA_TO_IMGVIEW"/>
    <MENUITEM id="MENU_ID_CAMERA_CAMERA_SETTING" str="STR_ID_CAMERA_CAMERA_SETTING"/> 
    <MENUITEM id="MENU_ID_CAMERA_IMAGE_SETTING" str="STR_ID_CAMERA_IMAGE_SETTING"/>
    <MENUITEM id="MAIN_MENU_OPTION_CAMERA_APP" str="STR_ID_CAMERA_APP_NAME" highlight="mmi_camera_hilight_app"/>

#ifdef __CAMERA_FEATURE_WB__
    #ifdef __CAMERA_FEATURE_WB_AUTO__
        <MENUITEM id="MENU_ID_CAMERA_WB_AUTO" str="STR_ID_CAMERA_WB_AUTO"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
        <MENUITEM id="MENU_ID_CAMERA_WB_DAYLIGHT" str="STR_ID_CAMERA_WB_DAYLIGHT"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
        <MENUITEM id="MENU_ID_CAMERA_WB_TUNGSTEN" str="STR_ID_CAMERA_WB_TUNGSTEN"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
        <MENUITEM id="MENU_ID_CAMERA_WB_FLUORESCENT" str="STR_ID_CAMERA_WB_FLUORESCENT"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_CLOUD__
        <MENUITEM id="MENU_ID_CAMERA_WB_CLOUD" str="STR_ID_CAMERA_WB_CLOUD"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
        <MENUITEM id="MENU_ID_CAMERA_WB_INCANDESCENCE" str="STR_ID_CAMERA_WB_INCANDESCENCE"/>
    #endif
    #ifdef __CAMERA_FEATURE_WB_MANUAL__
        <MENUITEM id="MENU_ID_CAMERA_WB_MANUAL" str="STR_ID_CAMERA_WB_MANUAL"/>
    #endif
#endif

#ifdef __CAMERA_AUTOFOCUS_METERING__
    #ifdef __CAMERA_AUTOFOCUS_1_ZONE__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_1_ZONE" str="STR_ID_CAMERA_AUTOFOCUS_1_ZONE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_3_ZONE__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_3_ZONE" str="STR_ID_CAMERA_AUTOFOCUS_3_ZONE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_5_ZONE__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_5_ZONE" str="STR_ID_CAMERA_AUTOFOCUS_5_ZONE"/>
    #endif
#endif

#ifdef __CAMERA_AUTOFOCUS_MODE__
    #ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_MODE_AUTO" str="STR_ID_CAMERA_AUTOFOCUS_MODE_AUTO"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_MODE_MACRO" str="STR_ID_CAMERA_AUTOFOCUS_MODE_MACRO"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_MODE_INFINITE" str="STR_ID_CAMERA_AUTOFOCUS_MODE_INFINITE"/>
    #endif
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        <MENUITEM id="MENU_ID_CAMERA_AUTOFOCUS_MODE_MANUAL" str="STR_ID_CAMERA_AUTOFOCUS_MODE_MANUAL"/>
    #endif
#endif

#ifdef __CAMERA_DSC_MODE__
    #ifdef __CAMERA_DSC_MODE_AUTO__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_AUTO" str="STR_ID_CAMERA_DSC_MODE_AUTO"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_PORTRAIT__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_PORTRAIT" str="STR_ID_CAMERA_DSC_MODE_PORTRAIT"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_LANDSCAPE__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_LANDSCAPE" str="STR_ID_CAMERA_DSC_MODE_LANDSCAPE"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_SPORT__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_SPORT" str="STR_ID_CAMERA_DSC_MODE_SPORT"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_FLOWER__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_FLOWER" str="STR_ID_CAMERA_DSC_MODE_FLOWER"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_NIGHT__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_NIGHT" str="STR_ID_CAMERA_DSC_MODE_NIGHT"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_SHUTTER_PRI" str="STR_ID_CAMERA_DSC_MODE_SHUTTER_PRI"/>
    #endif
    #ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
        <MENUITEM id="MENU_ID_CAMERA_DSC_MODE_APERTURE_PRI" str="STR_ID_CAMERA_DSC_MODE_APERTURE_PRI"/>
    #endif
    #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        #ifdef __CAEMRA_FEATURE_ISO_AUTO__
            <MENUITEM id="MENU_ID_CAMERA_ISO_AUTO" str="STR_ID_CAMERA_ISO_AUTO"/>
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_100__
            <MENUITEM id="MENU_ID_CAMERA_ISO_100" str="STR_ID_CAMERA_ISO_100"/>
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_200__
            <MENUITEM id="MENU_ID_CAMERA_ISO_200" str="STR_ID_CAMERA_ISO_200"/>
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_400__
            <MENUITEM id="MENU_ID_CAMERA_ISO_400" str="STR_ID_CAMERA_ISO_400"/>
        #endif
    #endif
#endif

#ifdef __CAMERA_FEATURE_EFFECT__
    #ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_NORMAL" str="STR_ID_CAMERA_EFFECT_NORMAL"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_GRAYSCALE" str="STR_ID_CAMERA_EFFECT_GRAYSCALE"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_SEPIA" str="STR_ID_CAMERA_EFFECT_SEPIA"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_SEPIA_GREEN" str="STR_ID_CAMERA_EFFECT_SEPIA_GREEN"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_SEPIA_BLUE" str="STR_ID_CAMERA_EFFECT_SEPIA_BLUE"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_COLOR_INVERT" str="STR_ID_CAMERA_EFFECT_COLOR_INVERT"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_GRAY_INVERT" str="STR_ID_CAMERA_EFFECT_GRAY_INVERT"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_BLACKBOARD" str="STR_ID_CAMERA_EFFECT_BLACKBOARD"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_WHITEBOARD" str="STR_ID_CAMERA_EFFECT_WHITEBOARD"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_COPPER_CARVING" str="STR_ID_CAMERA_EFFECT_COPPER_CARVING"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_BLUE_CARVING" str="STR_ID_CAMERA_EFFECT_BLUE_CARVING"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_EMBOSSMENT" str="STR_ID_CAMERA_EFFECT_EMBOSSMENT"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_CONTRAST" str="STR_ID_CAMERA_EFFECT_CONTRAST"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_JEAN__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_JEAN" str="STR_ID_CAMERA_EFFECT_JEAN"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_SKETCH" str="STR_ID_CAMERA_EFFECT_SKETCH"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_OIL__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_OIL" str="STR_ID_CAMERA_EFFECT_OIL"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_1" str="STR_ID_CAMERA_EFFECT_CUSTOM_FX_1"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_2" str="STR_ID_CAMERA_EFFECT_CUSTOM_FX_2"/>
    #endif
    #ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
        <MENUITEM id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_3" str="STR_ID_CAMERA_EFFECT_CUSTOM_FX_3"/>
    #endif
    #ifdef __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__
    #ifdef __CAMERA_FEATURE_EFFECT_EFFECT_LOMO__
		<MENUITEM id="MENU_ID_CAMERA_EFFECT_LOMO" str="STR_ID_CAMERA_EFFECT_LOMO"/>
    #endif 
    #ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_RED__
		<MENUITEM id="MENU_ID_CAMERA_EFFECT_COLOR_RED" str="STR_ID_CAMERA_EFFECT_COLOR_RED"/>
    #endif 
    #ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_YELLOW__
		<MENUITEM id="MENU_ID_CAMERA_EFFECT_COLOR_YELLOW" str="STR_ID_CAMERA_EFFECT_COLOR_YELLOW"/>
    #endif 
    #ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_GREEN__
		<MENUITEM id="MENU_ID_CAMERA_EFFECT_COLOR_GREEN" str="STR_ID_CAMERA_EFFECT_COLOR_GREEN"/>
    #endif 
    #ifdef __CAMERA_FEATURE_EFFECT_EFFECT_COLOR_BLUE__
		<MENUITEM id="MENU_ID_CAMERA_EFFECT_COLOR_BLUE" str="STR_ID_CAMERA_EFFECT_COLOR_BLUE"/>
    #endif 
    #endif 
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    <MENUITEM id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET" str="STR_ID_CAMERA_EFFECT_CUSTOM_FX_SET" highlight="mmi_camera_highlight_custom_fx_set"/>
    <MENUITEM id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT" str="STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT" highlight="mmi_camera_highlight_custom_fx_edit"/>
#endif
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_OFF" str="STR_ID_CAMERA_ADD_FRAME_OFF"/>
#if defined(__CAMERA_FEATURE_ADD_FRAME_1__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_1" str="STR_ID_CAMERA_ADD_FRAME_1"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_2__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_2" str="STR_ID_CAMERA_ADD_FRAME_2"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_3__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_3" str="STR_ID_CAMERA_ADD_FRAME_3"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_4__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_4" str="STR_ID_CAMERA_ADD_FRAME_4"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_5__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_5" str="STR_ID_CAMERA_ADD_FRAME_5"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_6__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_6" str="STR_ID_CAMERA_ADD_FRAME_6"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_7__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_7" str="STR_ID_CAMERA_ADD_FRAME_7"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_8__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_8" str="STR_ID_CAMERA_ADD_FRAME_8"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_9__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_9" str="STR_ID_CAMERA_ADD_FRAME_9"/>
#endif
#if defined(__CAMERA_FEATURE_ADD_FRAME_10__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__)
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_10" str="STR_ID_CAMERA_ADD_FRAME_10"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_CUSTOM_1" str="STR_ID_CAMERA_ADD_FRAME_CUSTOM_1"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_CUSTOM_2" str="STR_ID_CAMERA_ADD_FRAME_CUSTOM_2"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_CUSTOM_3" str="STR_ID_CAMERA_ADD_FRAME_CUSTOM_3"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_CUSTOM_4" str="STR_ID_CAMERA_ADD_FRAME_CUSTOM_4"/>
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
    <MENUITEM id="MENU_ID_CAMERA_ADD_FRAME_CUSTOM_5" str="STR_ID_CAMERA_ADD_FRAME_CUSTOM_5"/>
#endif
#endif

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    <MENUITEM id="MENU_ID_CAMERA_SELF_CAPTURE" str="STR_ID_CAMERA_SELF_CAPTURE"/>
#endif
#ifdef __CAMERA_FEATURE_STORAGE__
    <MENUITEM id="MENU_ID_CAMERA_STORAGE_PHONE" str="STR_GLOBAL_PHONE"/>
    <MENUITEM id="MENU_ID_CAMERA_STORAGE_MEMORY_CARD" str="STR_GLOBAL_MEMORY_CARD"/>
#endif
#ifdef __CAMERA_FEATURE_RESTORE_DEFAULT__
    <MENUITEM id="MENU_ID_CAMERA_RESTORE_DEFAULT" str="STR_ID_CAMERA_RESTORE_DEFAULT"/>
 #endif
#ifdef __MMI_SUBLCD_CAMERA__
    <MENUITEM id="MENU_ID_CAMERA_SUBLCD_PREVIEW" str="STR_ID_CAMERA_APP_NAME" highlight="mmi_sublcd_camera_hilight_preview"/>
#if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
    <MENUITEM id="MENU_ID_CAMERA_SUBLCD_FLASH_ON" str="STR_ID_CAMERA_FLASH_ON"/>
    <MENUITEM id="MENU_ID_CAMERA_SUBLCD_FLASH_OFF" str="STR_ID_CAMERA_FLASH_OFF"/>
#endif
    <MENUITEM id="MENU_ID_CAMERA_SUBLCD_EXIT" str="STR_GLOBAL_EXIT" highlight="mmi_sublcd_camera_hilight_exit"/>
#endif
    <MENUITEM id="MENU_ID_CAMERA_CONFIRM_OPTION_DELETE" str="STR_GLOBAL_DELETE"/>
#if defined(__MMI_PHOTOEDITOR__)
    <MENUITEM id="MENU_ID_CAMERA_CONFIRM_OPTION_EDIT" str="STR_GLOBAL_EDIT"/>
#endif
    <MENUITEM id="MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/* highlight="mmi_camera_hilight_forward_to_mms"*//>
    <MENUITEM id="MENU_ID_CAMERA_FORWARD_OPTION_TO_BT" str="STR_GLOBAL_VIA_BLUETOOTH"/>
    <MENUITEM id="MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL" str="STR_GLOBAL_AS_EMAIL"/>
#if defined(__MMI_MMS_POSTCARD__)
    <MENUITEM id="MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD" str="STR_ID_CAMERA_TO_POSTCARD"/>
#endif

    <!--Menu Tree Area-->

#ifdef __MMI_CAMERA_SLIM__
			<MENU id="MENU_ID_CAMERA_APP" str="STR_ID_CAMERA_APP_NAME" highlight="mmi_camera_hilight_app" shortcut="ON" launch="mmi_camera_lauch">
			</MENU>
#else
			<MENU id="MENU_ID_CAMERA_APP" str="STR_ID_CAMERA_APP_NAME" highlight="mmi_camera_hilight_app" img="IMG_ID_CAMERA_APP_ICON" shortcut="ON" shortcut_img="IMG_ID_CAMERA_APP_ICON" launch="mmi_camera_lauch">
			</MENU>
#endif
    
    <MENU id="MENU_ID_CAMERA_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CAMERA_TO_VDOREC_APP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_TO_IMGVIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_CAMERA_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_IMAGE_SETTING</MENUITEM_ID>
        
        #if 0
        <MENUITEM_ID>MENU_ID_CAMERA_WB</MENUITEM_ID>
        #endif
        #if 0
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE</MENUITEM_ID>
        #endif
        #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        <MENUITEM_ID>MENU_ID_CAMERA_ISO</MENUITEM_ID>
        #endif
		#ifdef __CAMERA_AUTOFOCUS__
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_MODE</MENUITEM_ID>
        #endif
		#ifdef __CAMERA_AUTOFOCUS_METERING__
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_METERING</MENUITEM_ID>
        #endif
        #ifdef __CAMERA_FEATURE_EFFECT__
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_SETTING</MENUITEM_ID>
        #endif
		#ifdef __CAMERA_FEATURE_ADD_FRAME__
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME</MENUITEM_ID>
        #endif
		#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        <MENUITEM_ID>MENU_ID_CAMERA_SELF_CAPTURE</MENUITEM_ID>
        #endif
		
        <MENUITEM_ID>MENU_ID_CAMERA_STORAGE</MENUITEM_ID>
        
#ifdef __CAMERA_FEATURE_RESTORE_DEFAULT__
        <MENUITEM_ID>MENU_ID_CAMERA_RESTORE_DEFAULT</MENUITEM_ID>
#endif
    </MENU>

    <MENU id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_SAVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_RESTORE_DEFAULT</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_CAMERA_STORAGE" type="OPTION" str="STR_GLOBAL_STORAGE">
        <MENUITEM_ID>MENU_ID_CAMERA_STORAGE_PHONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_STORAGE_MEMORY_CARD</MENUITEM_ID>
    </MENU>

#ifdef __MMI_SUBLCD_CAMERA__
    <MENU id="MENU_ID_CAMERA_SUBLCD_FLASH" type="OPTION" highlight="mmi_sublcd_camera_hilight_flash">
        <MENUITEM_ID>MENU_ID_CAMERA_SUBLCD_FLASH_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_SUBLCD_FLASH_OFF</MENUITEM_ID>
    </MENU>
#endif

#ifdef __CAMERA_FEATURE_WB__
    <MENU id="MENU_ID_CAMERA_WB" type="OPTION" str="STR_ID_CAMERA_WB">
        <MENUITEM_ID>MENU_ID_CAMERA_WB_AUTO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_DAYLIGHT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_TUNGSTEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_FLUORESCENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_CLOUD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_INCANDESCENCE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_WB_MANUAL</MENUITEM_ID>
    </MENU>
#endif

#ifdef __CAMERA_AUTOFOCUS_METERING__
    <MENU id="MENU_ID_CAMERA_AUTOFOCUS_METERING" type="OPTION" str="STR_ID_CAMERA_AUTOFOCUS_METERING">
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_1_ZONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_3_ZONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_5_ZONE</MENUITEM_ID>
    </MENU>
#endif
             
#ifdef __CAMERA_AUTOFOCUS__
    <MENU id="MENU_ID_CAMERA_AUTOFOCUS_MODE" type="OPTION" str="STR_ID_CAMERA_AUTOFOCUS_MODE">
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_MODE_AUTO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_MODE_MACRO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_MODE_INFINITE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_AUTOFOCUS_MODE_MANUAL</MENUITEM_ID>
    </MENU>
#endif
                        
#ifdef __CAMERA_DSC_MODE__
    <MENU id="MENU_ID_CAMERA_DSC_MODE" type="OPTION" str="STR_ID_CAMERA_DSC_MODE">
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_AUTO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_PORTRAIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_LANDSCAPE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_SPORT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_FLOWER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_NIGHT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_SHUTTER_PRI</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_DSC_MODE_APERTURE_PRI</MENUITEM_ID>
    </MENU>
#endif
    
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
    <MENU id="MENU_ID_CAMERA_ISO" type="OPTION" str="STR_ID_CAMERA_ISO">
        <MENUITEM_ID>MENU_ID_CAMERA_ISO_AUTO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ISO_100</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ISO_200</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ISO_400</MENUITEM_ID>
    </MENU>
#endif

#ifdef __CAMERA_FEATURE_EFFECT__
    <MENU id="MENU_ID_CAMERA_EFFECT_SETTING" type="OPTION" str="STR_ID_CAMERA_EFFECT_SETTING">
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_NORMAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_GRAYSCALE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_SEPIA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_SEPIA_GREEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_SEPIA_BLUE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COLOR_INVERT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_GRAY_INVERT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_BLACKBOARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_WHITEBOARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COPPER_CARVING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_BLUE_CARVING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_EMBOSSMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CONTRAST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_JEAN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_SKETCH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_OIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_CUSTOM_FX_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_LOMO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COLOR_RED</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COLOR_YELLOW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COLOR_GREEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_EFFECT_COLOR_BLUE</MENUITEM_ID>
    </MENU>                                    
#endif

    <MENU id="MENU_ID_CAMERA_CONFIRM_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CAMERA_FORWARD_OPTION</MENUITEM_ID>
        #if defined __MMI_PHOTOEDITOR__
        <MENUITEM_ID>MENU_ID_CAMERA_CONFIRM_OPTION_EDIT</MENUITEM_ID>
        #endif
        <MENUITEM_ID>MENU_ID_CAMERA_CONFIRM_OPTION_DELETE</MENUITEM_ID>
    </MENU>          

#ifdef __CAMERA_FEATURE_ADD_FRAME__
    <MENU id="MENU_ID_CAMERA_ADD_FRAME" type="OPTION" str="STR_ID_CAMERA_ADD_FRAME">
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_NORMAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_TILESHOT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_COLOR_IDX</MENUITEM_ID>
    </MENU>                                        

#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__
    <MENU id="MENU_ID_CAMERA_ADD_FRAME_NORMAL" type="OPTION" str="STR_ID_CAMERA_ADD_FRAME_NORMAL">
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_8</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_9</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_10</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_CUSTOM_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_CUSTOM_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_CUSTOM_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_CUSTOM_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_CUSTOM_5</MENUITEM_ID>
    </MENU>
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_TILESHOT__)

    <MENU id="MENU_ID_CAMERA_ADD_FRAME_TILESHOT" type="OPTION" str="STR_ID_CAMERA_ADD_FRAME_TILESHOT" highlight="mmi_camera_highlight_add_frame2">
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_8</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_9</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_10</MENUITEM_ID>
    </MENU>                                        
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    <MENU id="MENU_ID_CAMERA_ADD_FRAME_COLOR_IDX" type="OPTION" str="STR_ID_CAMERA_ADD_FRAME_COLOR_IDX" highlight="mmi_camera_highlight_add_frame2">
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_8</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_9</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_ADD_FRAME_10</MENUITEM_ID>
    </MENU>                                        
#endif
#endif

#ifdef __MMI_SUBLCD_CAMERA__
    <MENU id="MENU_ID_CAMERA_SUBLCD_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_ID_CAMERA_APP_ICON">
        <MENUITEM_ID>MENU_ID_CAMERA_SUBLCD_PREVIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_SUBLCD_FLASH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_SUBLCD_EXIT</MENUITEM_ID>
    </MENU>                                        
#endif

    <MENU id="MENU_ID_CAMERA_FORWARD_OPTION" type="OPTION" str="STR_GLOBAL_SEND">
        <MENUITEM_ID>MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CAMERA_FORWARD_OPTION_TO_BT</MENUITEM_ID>
    </MENU>
    
    
    <SCREEN id="SCR_ID_CAMERA_APP"/>
    <SCREEN id="SCR_ID_CAMERA_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_CAMERA_SETTING"/>
    <SCREEN id="SCR_ID_CAMERA_IMAGE_SETTING"/>
    <SCREEN id="SCR_ID_CAMERA_EFFECT_SETTING"/>
    <SCREEN id="SCR_ID_CAMERA_ADD_FRAME"/>
    <SCREEN id="SCR_ID_CAMERA_ADD_FRAME_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_ADD_FRAME_VIEW"/>
    <SCREEN id="SCR_ID_CAMERA_CONT_SHOT"/>
    <SCREEN id="SCR_ID_CAMERA_DELAY_TIMER"/>
    <SCREEN id="SCR_ID_CAMERA_STORAGE"/>
    <SCREEN id="SCR_ID_CAMERA_EFFECT_SET_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_EFFECT_EDIT"/>
    <SCREEN id="SCR_ID_CAMERA_EFFECT_SAVE_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_ADD_FRAME_SET_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_RESTORE_DEFAULT"/>
    <SCREEN id="SCR_ID_CAMERA_DSC_MODE"/>
    <SCREEN id="SCR_ID_CAMERA_DSC_MODE_SETTING"/>
    <SCREEN id="SCR_ID_CAMERA_AUTOFOCUS_METERING"/>
    <SCREEN id="SCR_ID_CAMERA_AUTOFOCUS_MODE"/>
    <SCREEN id="SCR_ID_CAMERA_ISO"/>
    <SCREEN id="SCR_ID_CAMERA_WB"/>
    <SCREEN id="SCR_ID_CAMERA_WB_MANUAL"/>
    <SCREEN id="SCR_ID_CAMERA_WB_MANUAL_HELP"/>
    <SCREEN id="SCR_ID_GROUP_CAMERA_SUBLCD"/>
    <SCREEN id="SCR_ID_CAMERA_SUBLCD_APP"/>
    <SCREEN id="SCR_ID_CAMERA_SUBLCD_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_SUBLCD_OPTION_FLASH"/>
    <SCREEN id="SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN"/>
    <SCREEN id="SCR_ID_CAMERA_SCREEN_SNAPSHOT"/>
    <SCREEN id="SCR_ID_CAMERA_FORWARD_OPTION"/>
    <SCREEN id="SCR_ID_CAMERA_END"/>
	#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_camera_notify_screen_lock_hdlr"/>
	#endif
    //#ifdef __MMI_SUBLCD_CAMERA__
    //<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_sublcd_camera_gpio_clam_open_hdlr"/>
    //<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_sublcd_camera_gpio_clam_close_hdlr"/>
    //#endif

    //#if defined(__MMI_SUBLCD_CAMERA__) && defined(__MMI_USB_SUPPORT__)
    //<RECEIVER id="EVT_ID_USB_PERMIT_CFG" proc="mmi_sublcd_camera_usb_plug_proc"/>
    //<RECEIVER id="EVT_ID_USB_MMI_NOTIFY" proc="mmi_sublcd_camera_usb_plug_proc"/>
    //#endif
    
#endif
</APP>

