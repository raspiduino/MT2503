#include "mmi_features.h"
#include "custresdef.h"
#include "custom_equipment.h"


<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_GPIO">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

<!----------------- Group Id ------------------------------------------->             
    <SCREEN id = "GRP_ID_GPIO_ROOT"/>
    <SCREEN id = "GRP_ID_GPIO_BACKLIGHT_SETTING"/>
    <SCREEN id = "GRP_ID_GPIO_LED_SETTING"/>

<!----------------- Screen Id ------------------------------------------->             
    <SCREEN id = "SCR_ID_GPIO_BACKLIGHT_SETTING"/>
    <SCREEN id = "SCR_ID_GPIO_CONTRAST_SETTING"/>
    <SCREEN id = "SCR_ID_GPIO_COVER_SETTING"/>

<!-- 
**************************************** String section ***************************************
--> 
    <STRING id="STR_ID_PHNSET_GPIO_SETTING"/>
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    <STRING id="STR_ID_PHNSET_GPIO_LED"/>
    <STRING id="STR_ID_PHNSET_LED_SWITCHING"/>
#endif    
    <STRING id="STR_ID_PHNSET_GPIO_BACKLITE"/>
    <STRING id="STR_ID_PHNSET_GPIO_BACKLITE_LEVEL"/>
#ifdef __MMI_GPIO_SUPPORT_BL_TIME_SETTING__
    <STRING id="STR_ID_PHNSET_GPIO_BACKLITE_HF_TIME"/>
#endif
#ifndef __MMI_MRE_DISABLE_FMGR__
	<STRING id="STR_ID_AM_MRE_CURRENT_VERSION"/>
#endif
 
#ifdef __MMI_PHNSET_GPIO_COVER__    
    <STRING id="STR_ID_PHNSET_GPIO_COVER_CLOSE"/>
    <STRING id="STR_ID_PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE"/>
    <STRING id="STR_ID_PHNSET_GPIO_COVER_CLOSE_REJECT_CALL"/>
    <STRING id="STR_ID_PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK"/>    
#endif
#ifdef __LCD_COLOR_ENGINE_SUPPORT__
    <STRING id="STR_ID_PHNSET_PICTURE_QUALITY"/>    
    <STRING id="STR_ID_PHNSET_PICTURE_QUALITY_ENABLED"/>    
    <STRING id="STR_ID_PHNSET_PICTURE_QUALITY_DISABLED"/>    
#endif

    
<!-- 
**************************************** Menu section *****************************************
-->
        
    <MENU id = "MENU_ID_PHNSET_GPIO_SETTING" type = "APP_SUB" str = "STR_ID_PHNSET_GPIO_SETTING" >
    #if !defined(HARDWARE_LED_NOT_SUPPORT)
        <MENUITEM_ID> MENU_ID_PHNSET_GPIO_LED </MENUITEM_ID>
    #endif	
        <MENUITEM id = "MENU_ID_PHNSET_GPIO_BACKLITE" str = "STR_ID_PHNSET_GPIO_BACKLITE"/>
    #ifndef __MMI_MRE_DISABLE_FMGR__
    #ifndef __BT_DIALER_SUPPORT__
		<MENUITEM id = "MENU_ID_PHNSET_MRE_CURRENT_VERSION" str ="STR_ID_AM_MRE_CURRENT_VERSION"/>
		#endif
		#endif
    #ifdef __MMI_COVER_CLOSE_SETTING__    
        <MENUITEM id = "MENU_ID_PHNSET_GPIO_COVER_CLOSE" str = "STR_ID_PHNSET_GPIO_COVER_CLOSE"/>
    #endif    
            <MENUITEM_ID>MENU_ID_PHNSET_PICTURE_QUALITY</MENUITEM_ID>
    </MENU>

#ifdef __LCD_COLOR_ENGINE_SUPPORT__
    <MENU id = "MENU_ID_PHNSET_PICTURE_QUALITY" type = "APP_SUB" str = "STR_ID_PHNSET_PICTURE_QUALITY" >
        <MENUITEM id = "MENU_ID_PHNSET_PICTURE_QUALITY_ON" str = "STR_GLOBAL_ON" />
        <MENUITEM id = "MENU_ID_PHNSET_PICTURE_QUALITY_OFF" str = "STR_GLOBAL_OFF" />
    </MENU>
#endif
    
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    <MENU id = "MENU_ID_PHNSET_GPIO_LED" type = "APP_SUB" str = "STR_ID_PHNSET_GPIO_LED" flag = "RADIO">
        <MENUITEM id = "MENU_ID_PHNSET_GPIO_LED_ON" str = "STR_GLOBAL_ON" />
        <MENUITEM id = "MENU_ID_PHNSET_GPIO_LED_OFF" str = "STR_GLOBAL_OFF" />
    </MENU>
#endif


	<!------------------------------------------------------Other Resource---------------------------------------------------------->
#ifdef __LCD_COLOR_ENGINE_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_SETTING_PICTURE_QUALITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Picture Quality </DESCRIPTION>
    </CACHEDATA>
#endif
    
</APP>	    
