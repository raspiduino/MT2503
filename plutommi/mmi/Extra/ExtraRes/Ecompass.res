/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 
#include "MMI_features.h"
//#include "ExtraResDef.h"

#if defined(__MMI_ECOMPASS__)
//#include "EcompassResDef.h"
#include "EcompassProt.h"
//#include "EcompassDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
//#include "PopulateRes.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_ECOMPASS">

	<CACHEDATA type="short" id="NVRAM_EC_DEFAULT_CITY">
        <DEFAULT_VALUE> [0xE2, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA> 


	<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String IDs for the application*/

    <STRING id="STR_ID_EC_MENU"/>
    
    <STRING id="STR_ID_EC_CHOICE"/>

    <STRING id="STR_ID_EC_CALIBRATION"/>
    <STRING id="STR_ID_EC_CALIBRATING"/>    

    <STRING id="STR_ID_EC_ROTATION"/>
    <STRING id="STR_ID_EC_CALI_ABORTED"/>

    <STRING id="STR_ID_EC_STRONG_SIG"/>
    <STRING id="STR_ID_EC_NEED_CALI"/>

    <STRING id="STR_ID_EC_SET_LOC"/>    
    <STRING id="STR_ID_EC_SET_DEC"/>
    <STRING id="STR_ID_EC_CALIBRATE"/>

    <STRING id="STR_ID_EC_COUNTRY"/>
    <STRING id="STR_ID_EC_CITY"/>

    <STRING id="STR_ID_EC_DECL"/>    
    <STRING id="STR_ID_EC_DEC_ANGLE"/>
    <STRING id="STR_ID_EC_DEC_DIR"/>
    <STRING id="STR_ID_EC_EAST"/>
    <STRING id="STR_ID_EC_WEST"/>
    
    <STRING id="STR_ID_EC_NE"/>
    <STRING id="STR_ID_EC_SE"/>
    <STRING id="STR_ID_EC_SW"/>
    <STRING id="STR_ID_EC_NW"/>
    <STRING id="STR_ID_EC_DEGREE"/>    
    <STRING id="STR_ID_EC_RANGE"/>
    <STRING id="STR_ID_EC_MAN_CHOICE"/>
    <STRING id="STR_ID_EC_CALI_FAIL"/>
    <STRING id="STR_ID_EC_COMMA"/>
    <STRING id="STR_ID_EC_MECCA"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <IMAGE id="IMG_ID_EC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Compass\\\\SB_COMPASS.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

     /*This menu id will be added in the end as this is the part of extra menu*/ 

     <MENU id="EXTRA_ECOMPASS_MENU" str="STR_ID_EC_MENU" img="IMG_ID_EC_ICON" highlight="HighlightEcompassMenu"
     shortcut="ON" shortcut_img="IMG_ID_EC_ICON" launch="mmi_ecompass_entry_clb_choice_screen">       
     </MENU>


    <MENUITEM id="ECOMPASS_OPTIONS_SET_LOCATION" str="STR_ID_EC_SET_LOC"/>  
    <MENUITEM id="ECOMPASS_OPTIONS_SET_DECLINATION" str="STR_ID_EC_SET_DEC"/>  
    <MENUITEM id="ECOMPASS_OPTIONS_CALIBRATE" str="STR_ID_EC_CALIBRATE"/>  

    <MENU id="ECOMPASS_OPTIONS_MENU" type="OPTION" str="STR_ID_EC_MENU">
        <MENUITEM_ID>ECOMPASS_OPTIONS_SET_LOCATION</MENUITEM_ID>
        <MENUITEM_ID>ECOMPASS_OPTIONS_SET_DECLINATION</MENUITEM_ID>
       	<MENUITEM_ID>ECOMPASS_OPTIONS_CALIBRATE</MENUITEM_ID>
    </MENU>

	<MENU id="ECOMPASS_COUNTRY_MENU"/>
	</MENU>
	
	<MENU id="ECOMPASS_CITY1"/>    
	</MENU>
	
    <MENU id="ECOMPASS_CITY2"/>    
	</MENU>

    <MENU id="ECOMPASS_CITY3"/>    
	</MENU>

    <MENU id="ECOMPASS_CITY4"/>	  
	</MENU>

    <MENU id="ECOMPASS_CITY5"/>
	</MENU>

    <MENU id="ECOMPASS_CITY6"/>	  
	</MENU>

    <MENU id="ECOMPASS_CITY7"/>    
	</MENU>

    <MENU id="ECOMPASS_CITY8"/>	  
	</MENU>

    <MENU id="ECOMPASS_CITY9"/>
	</MENU>

    <MENU id="ECOMPASS_CITY10"/>	  
	</MENU>

    <MENU id="ECOMPASS_CITY11"/>     
	</MENU>

    <MENU id="ECOMPASS_CITY12"/>	  
	</MENU>

	<MENU id="ECOMPASS_CITY13"/>
	</MENU>

	<MENU id="ECOMPASS_CITY14"/>	  
	</MENU>

	<MENU id="ECOMPASS_CITY15"/>
	</MENU>

    <MENU id="ECOMPASS_DUMMY_MENU" str="STR_ID_EC_MENU">
        <MENUITEM_ID>ECOMPASS_OPTIONS_MENU</MENUITEM_ID>       
    </MENU>
   
    <!------------------------------------------------------Screen Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_EC_CLB_CHOICE"/>
    <SCREEN id="SCR_ID_EC_ROTATION"/>
    <SCREEN id="SCR_ID_EC_ANIMATION"/>
    <SCREEN id="SCR_ID_EC_DIRECTION"/>
    <SCREEN id="SCR_ID_EC_OPTIONS"/>
    <SCREEN id="SCR_ID_EC_SET_COUNTRY"/>
    <SCREEN id="SCR_ID_EC_SET_CITY"/>
    <SCREEN id="SCR_ID_EC_DECLINATION"/>
    <SCREEN id="SCR_ID_EC_MAN_CHOICE"/>

   <!------------------------------------------------------Screen Resource---------------------------------------------------------->
    /*call back manager registration*/
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_ecompass_lcd_sleepin_handler"/>	
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_ecompass_lcd_sleepout_handler"/>	

</APP>
    


  
#endif /* DEVELOPER_BUILD_FIRST_PASS */ /* defined(__MMI_ECOMPASS__) */
#endif /* defined(__MMI_ECOMPASS__) */ 






















