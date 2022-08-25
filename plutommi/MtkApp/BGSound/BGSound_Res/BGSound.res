#include "MMI_features.h"
#include "CustResDef.h"
<?xml version = "1.0" encoding = "UTF-8"?>

#ifdef __MMI_BG_SOUND_EFFECT__

<APP id = "APP_BGSOUND" name="STR_ID_BGSND_BASE">
    <INCLUDE file = "GlobalResDef.h"/>
         <!--------------------------------------------------------------------------------------------------------------------->
         <!--String Resource Area-->
         <!--String Resource Area-->

    <!--sync menu string-->
    <STRING id = "STR_ID_BGSND_BG_SOUND"/>
    <STRING id = "STR_ID_BGSND_STATUS"/>
    <STRING id = "STR_ID_BGSND_MO_STATUS"/>
    <STRING id = "STR_ID_BGSND_PLAYBACK_SETUP"/>
    <STRING id = "STR_ID_BGSND_EFFECT_LIST"/>

    <STRING id = "STR_ID_BGSND_ONCE"/>
    <STRING id = "STR_ID_BGSND_INTERVAL"/>
    <STRING id = "STR_ID_BGSND_CONTINUE"/>
    <STRING id = "STR_ID_BGSND_PLAY_MODE_CAP"/>
    <STRING id = "STR_ID_BGSND_VOLUME_CAP"/>
    <STRING id = "STR_ID_BGSND_INVALID_INTERVAL"/>

    <STRING id = "STR_ID_BGSND_INVALID_VOLUME"/>
    <STRING id = "STR_ID_BGSND_INVALID_FILE"/>
    <STRING id = "STR_ID_BGSND_DEL_FILE_CONFIRM"/>
    <STRING id = "STR_ID_BGSND_OPEN_FILE_FAIL"/>
    <STRING id = "STR_ID_BGSND_PLAY_FAIL"/>
    <STRING id = "STR_ID_BGSND_LIST_FULL"/>

    <STRING id = "STR_ID_BGSND_FILE_DUPLICATED"/>
    <STRING id = "STR_ID_BGSND_CTM_MODE_ON"/>
    <STRING id = "STR_ID_BGSND_NO_EFFECT"/>
    <STRING id = "STR_ID_BGSND_EFFECT_1"/>
    <STRING id = "STR_ID_BGSND_EFFECT_2"/>
    <STRING id = "STR_ID_BGSND_EFFECT_3"/>
    <STRING id = "STR_ID_BGSND_EFFECT_4"/>
    <STRING id = "STR_ID_BGSND_EFFECT_5"/>
    <STRING id = "STR_ID_BGSND_EFFECT_6"/>
    <STRING id = "STR_ID_BGSND_EFFECT_7"/>
    <STRING id = "STR_ID_BGSND_EFFECT_8"/>
    <STRING id = "STR_ID_BGSND_EFFECT_9"/>
    <STRING id = "STR_ID_BGSND_EFFECT_10"/>

    <STRING id = "STR_ID_BGSND_EFFECT_11"/>
    <STRING id = "STR_ID_BGSND_EFFECT_12"/>
    <STRING id = "STR_ID_BGSND_EFFECT_13"/>
    <STRING id = "STR_ID_BGSND_EFFECT_14"/>
    <STRING id = "STR_ID_BGSND_EFFECT_15"/>

    <STRING id = "STR_ID_BGSND_EFFECT_16"/>
    <STRING id = "STR_ID_BGSND_EFFECT_17"/>
    <STRING id = "STR_ID_BGSND_EFFECT_18"/>
    <STRING id = "STR_ID_BGSND_EFFECT_19"/>
    <STRING id = "STR_ID_BGSND_EFFECT_20"/>
    <!--End-->

        <!--End String Resource Area-->
        <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->





        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Image Resource Area-->
        <!--Image Resource Area-->

    <IMAGE id = "IMG_ID_BGSND_APP">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Settings\\\\SoundEffect\\\\ST_BGplay.bmp"</IMAGE>
       
        <!--End Image Resource Area-->
        <!--End Image Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->



        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Audio Resource Area-->
        <!--Audio Resource Area-->

   <AUDIO id = "AUD_ID_BGSND_EFFECT1">CUST_ADO_PATH"\\\\BGSound\\\\Effect01.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT2">CUST_ADO_PATH"\\\\BGSound\\\\Effect02.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT3">CUST_ADO_PATH"\\\\BGSound\\\\Effect03.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT4">CUST_ADO_PATH"\\\\BGSound\\\\Effect04.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT5">CUST_ADO_PATH"\\\\BGSound\\\\Effect05.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT6">CUST_ADO_PATH"\\\\BGSound\\\\Effect06.wav"</AUDIO> 
   <AUDIO id = "AUD_ID_BGSND_EFFECT7">CUST_ADO_PATH"\\\\BGSound\\\\Effect07.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT8">CUST_ADO_PATH"\\\\BGSound\\\\Effect08.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT9">CUST_ADO_PATH"\\\\BGSound\\\\Effect09.wav"</AUDIO>
   <AUDIO id = "AUD_ID_BGSND_EFFECT10">CUST_ADO_PATH"\\\\BGSound\\\\Effect10.wav"</AUDIO>
   
        <!--End Audio Resource Area-->
        <!--End Audio Resource Area-->

        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->

    <SCREEN id = "SCR_ID_BGSND_CALL_SETUP"/>
    <SCREEN id = "SCR_ID_BGSND_CS_PLAYBACK"/>
    <SCREEN id = "SCR_ID_BGSND_CS_EFFECT"/>
    <SCREEN id = "SCR_ID_BGSND_CS_EXT_EFFECT_OPT"/>
    <SCREEN id = "SCR_ID_BGSND_MO_CALL_LIST"/>
    <SCREEN id = "SCR_ID_BGSND_MT_CALL_LIST"/>
    <SCREEN id = "SCR_ID_BGSND_CALL_MANAGE"/>
    <SCREEN id = "SCR_ID_BGSND_CM_SETTING"/>
    <SCREEN id = "SCR_ID_BGSND_CM_EFFECT"/>
    
    
        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->
        
    

        <!--Account_1-->

        <MENU id = "MENU_ID_BGSND_CALL_SETUP" type = "APP_MAIN" str = "STR_ID_BGSND_BG_SOUND" img = "IMG_ID_BGSND_APP"
           #ifndef __UCM_SUPPORT__
                highlight = "mmi_bgsnd_highlight_call_setup"
           #endif /* __UCM_SUPPORT__ */     
                flag = "NONMOVEABLE">           

            <MENUITEM id = "MENU_ID_BGSND_CALL_SETUP_STATUS" str = "STR_ID_BGSND_MO_STATUS"/>
            <MENUITEM id = "MENU_ID_BGSND_CALL_SETUP_SETTING" str = "STR_ID_BGSND_PLAYBACK_SETUP"/>
            <MENUITEM id = "MENU_ID_BGSND_CALL_SETUP_LIST" str = "STR_ID_BGSND_EFFECT_LIST"/>
        </MENU> 

         <!--Account_2-->

        <MENUITEM id = "MENU_ID_BGSND_CM_OPT_STATUS" str = "STR_ID_BGSND_STATUS"/>
        <MENUITEM id = "MENU_ID_BGSND_CM_OPT_SETTING" str = "STR_ID_BGSND_PLAYBACK_SETUP"/>
        <MENUITEM id = "MENU_ID_BGSND_CM_OPT_LIST" str = "STR_ID_BGSND_EFFECT_LIST"/>


        <MENU id = "MENU_ID_BGSND_CM_OPT_EFFECT" type = "APP_MAIN" str = "STR_ID_BGSND_BG_SOUND" 
             #ifndef __UCM_SUPPORT__   
            /* Call Management Screen. (In Call) */
             highlight = "mmi_bgsnd_highlight_call_manage"
             #endif /* __UCM_SUPPORT__ */
             flag = "MOVEABLEWITHINPARENT">
                <MENUITEM_ID>MENU_ID_BGSND_CM_OPT_STATUS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_BGSND_CM_OPT_SETTING</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_BGSND_CM_OPT_LIST</MENUITEM_ID>
        </MENU> 

        <!--Account_3-->

        <MENUITEM id = "MENU_ID_BGSND_EXT_EFFECT_SELECT" str = "@OID:STR_GLOBAL_SELECT" />
        <MENUITEM id = "MENU_ID_BGSND_EXT_EFFECT_EDIT" str = "@OID:STR_GLOBAL_EDIT" />
        <MENUITEM id = "MENU_ID_BGSND_EXT_EFFECT_DELETE" str = "@OID:STR_GLOBAL_DELETE" />


        <MENU id = "MENU_ID_BGSND_EXT_EFFECT_OPTION" type = "OPTION" str = "@OID:STR_GLOBAL_OPTIONS" flag = "NONMOVEABLE">
                <MENUITEM_ID>MENU_ID_BGSND_EXT_EFFECT_SELECT</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_BGSND_EXT_EFFECT_EDIT</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_BGSND_EXT_EFFECT_DELETE</MENUITEM_ID>
        </MENU> 

        <!--Account_4-->

        <MENUITEM id = "MENU_ID_BGSND_EXT_EFFECT_ADD" str = "@OID:STR_GLOBAL_ADD"/>
        
        <MENU id = "MENU_ID_BGSND_EXT_EFFECT_OPTION_ADD" str = "@OID:STR_GLOBAL_SELECT">
                <MENUITEM_ID>MENU_ID_BGSND_EXT_EFFECT_ADD</MENUITEM_ID>
        </MENU>


        /* Callback manager*/  
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_bgsound_notify_hdlr"/>

    /* Timer s*/  
    <TIMER id="BGSND_HIGHLIGHT_TIMER"/>
    <TIMER id="BGSND_INTERVAL_TIMER"/>

</APP>
#endif /* __MMI_BG_SOUND_EFFECT__*/
