#include "mmi_features.h"
#include "custresdef.h"
#include "gdi_features.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_CHARGER">
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file = "gdi_features.h"/>

<!----------------- Group Id ------------------------------------------->             
    <SCREEN id = "GRP_ID_CHARGER_ROOT"/>

<!----------------- Screen Id ------------------------------------------->             
    <SCREEN id = "SCR_CHARGER_POWER_ON"/>
    <SCREEN id = "SCR_CHARGING_COMPLETE"/>
    <SCREEN id = "SCR_ABNORMAL_CHARGING"/>
    <SCREEN id = "SCR_LOW_POWEROFF_SCR"/>

  #ifdef __MMI_BTBOX_NOLCD__
    
    <AUDIO id="AUD_ID_BTBOX_CHARGER_COMPLETE" desc="charger-complete" path="charge_done.mp3">CUST_ADO_PATH"\\\\BTBox\\\\charge_done.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BTBOX_CHARGER_LOW_WARNING" desc="low battery-warning" path="low_alert.mp3">CUST_ADO_PATH"\\\\BTBox\\\\low_alert.mp3"</AUDIO>
   

    <!--NOTIFY Area-->
   <NOTIFY id="BTBOX_CHARGER_IN"  desc="charger-in"  led="INPUT_EVENT_LED_ID_5" vib="INPUT_EVENT_VIB_INDX_0"/>
   <NOTIFY id="BTBOX_CHARGER_COMPLETE"   desc="charger-complete" led="INPUT_EVENT_LED_ID_6" voice="AUD_ID_BTBOX_CHARGER_COMPLETE" />
   <NOTIFY id="BTBOX_CHARGER_OUT"  desc="charger-out"  led="INPUT_EVENT_LED_ID_8"/>
   <NOTIFY id="BTBOX_CHARGER_LOW_WARNING"  desc="low battery-warning" led="INPUT_EVENT_LED_ID_4" voice="AUD_ID_BTBOX_CHARGER_LOW_WARNING"/>
 #endif

<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_LOW_BATTERY"/>
    <STRING id="STR_CHARGER_CONNECTED"/>
    <STRING id="STR_CHARGER_REMOVED"/>
    <STRING id="STR_USB_CHARGER_CONNECTED"/>
    <STRING id="STR_USB_CHARGER_REMOVED"/>
    <STRING id="STR_LOW_BATTERY_SHUTDOWN"/>
    <STRING id="STR_LOW_BATTERY_MT_PROHIBIT"/>
    <STRING id="STR_ID_CHARGER_CHARGING_ERROR"/>
    <STRING id="STR_ID_CHARGER_BATTERY_ERROR"/>
#ifdef __CLASSAB_VOLUME_PROTECTION__    
    <STRING id="STR_BATTERY_SAVE_POWER_ON"/>
    <STRING id="STR_BATTERY_SAVE_POWER_OFF"/>
#endif    

#ifdef __PLUTO_MMI_PACKAGE__

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   

#ifdef __OP01_FWPBW__
    <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\CHARGINGslim"</IMAGE>
    <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\CHARG_DONE.bmp"</IMAGE>

#else /* __OP01_FWPBW__ */

#if defined(__MMI_SLIM_IMG_RES__)
    #if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)
        #if !defined(GDI_USING_GIF)
            <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.png"</IMAGE>
        #else
            <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.gif"</IMAGE>
        #endif
        <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charge_Done.png"</IMAGE>
    #elif defined(__MMI_MAINLCD_128X128__)
        #if !defined(GDI_USING_GIF)
            <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.bmp"</IMAGE>
        #else
            <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.gif"</IMAGE>
        #endif
        <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charge_Done.jpg"</IMAGE>
    #elif defined(__MMI_MAINLCD_96X64__)
        <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging"</IMAGE>
        <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\CHARGF.bmp"</IMAGE>
    #else
        <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.gif"</IMAGE>
        <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charge_Done.gif"</IMAGE>
   #endif
#else /* __MMI_SLIM_IMG_RES__ */
    <IMAGE id="IMG_ID_CHARGER_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charging.gif"</IMAGE>
    <IMAGE id="IMG_ID_CHARGER_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\Charge_Done.gif"</IMAGE>
#endif /* __MMI_SLIM_IMG_RES__ */
#endif /* __OP01_FWPBW__ */

#ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_SUBLCD_CHARGER_POWER_ON">CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_char.gif"</IMAGE>    
    <IMAGE id="IMG_SUBLCD_CHARGING_COMPLETE">CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_charok.bmp"</IMAGE>    
    <IMAGE id="IMG_SUBLCD_ABNORMAL_BATTERY">CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_charwg.bmp"</IMAGE>    	
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    
    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="mmi_charbat_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER" proc="mmi_charbat_other_evt_hdlr"/>

	<TIMER id="LOW_BATTERY_SCR_TIMER"/>
	<TIMER id="BOOTUP_CHARGER_DETECT_TIMER"/>

#endif /* __PLUTO_MMI_PACKAGE__ */

</APP>

