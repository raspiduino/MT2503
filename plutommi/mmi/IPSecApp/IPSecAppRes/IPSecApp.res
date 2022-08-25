#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_IPSEC__
<APP id="APP_IPSEC">
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_IPSECAPP_PROFILE"/>
    <STRING id="STR_ID_IPSECAPP_DEFAULT_PROFILE_NAME1"/>
    <STRING id="STR_ID_IPSECAPP_DEFAULT_PROFILE_NAME2"/>
    <STRING id="STR_ID_IPSECAPP_DEFAULT_PROFILE_NAME3"/>
    <STRING id="STR_ID_IPSECAPP_POLICY"/>
    <STRING id="STR_ID_IPSECAPP_IKE"/>
    <STRING id="STR_ID_IPSECAPP_EDIT_PROFILE"/>
    <STRING id="STR_ID_IPSECAPP_SRC_PORT"/>
    <STRING id="STR_ID_IPSECAPP_SRC_ADDR"/>
    <STRING id="STR_ID_IPSECAPP_DEST_PORT"/>
    <STRING id="STR_ID_IPSECAPP_DEST_ADDR"/>
    <STRING id="STR_ID_IPSECAPP_IPSEC_MODE"/>
    <STRING id="STR_ID_IPSECAPP_TUNNEL_PORT"/>
    <STRING id="STR_ID_IPSECAPP_TUNNEL_ADDR"/>
    <STRING id="STR_ID_IPSECAPP_ALG"/>
    <STRING id="STR_ID_IPSECAPP_ALG_AH_AUTH"/>
    <STRING id="STR_ID_IPSECAPP_ALG_ESP_AUTH"/>
    <STRING id="STR_ID_IPSECAPP_ALG_ESP_ENC"/>
    <STRING id="STR_ID_IPSECAPP_IKE_PRESHARED_KEY"/>
    <STRING id="STR_ID_IPSECAPP_IKE_ENC_METHOD"/>
    <STRING id="STR_ID_IPSECAPP_IKE_DH_METHOD"/>
    <STRING id="STR_ID_IPSECAPP_PORTNUM_OUTOF_RANGE"/>
    <STRING id="STR_ID_IPSECAPP_PORTNUM_EMPTY"/>
    <STRING id="STR_ID_IPSECAPP_ALL_OPTIONS_NONE"/>
    <STRING id="STR_ID_IPSECAPP_TUNNEL_MODE"/>
    <STRING id="STR_ID_IPSECAPP_TRANSPORT_MODE"/>
    <STRING id="STR_ID_IPSECAPP_SELECTION_AUTH_MD5"/>
    <STRING id="STR_ID_IPSECAPP_SELECTION_AUTH_SHA1"/>
    <STRING id="STR_ID_IPSECAPP_SELECTION_ENC_DES"/>
    <STRING id="STR_ID_IPSECAPP_SELECTION_ENC_3DES"/>
    <STRING id="STR_ID_IPSECAPP_PROGRESSING"/>
    <STRING id="STR_ID_IPSECAPP_DEACTIVATED"/>
    <STRING id="STR_ID_IPSECAPP_INPUT_PRE_SHARED_KEY"/>
    <STRING id="STR_ID_IPSECAPP_PROFILE_NAME_EMPTY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_IPSECAPP_SETTINGS" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_IPSecMode.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_PROF_POLICY_SETTINGS" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_Policy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_PROF_IKE_SETTINGS" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_IKE.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_SRC_PORT" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_SrcPort.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_SRC_ADDR" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_SrcAddr.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_DEST_PORT" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_DestPort.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_DEST_ADDR" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_DestAddr.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_MODE" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_IPSecMode.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_TUNNEL_PORT" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_TunnPort.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_TUNNEL_ADDR" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_TunnAddr.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_POLICY_ALG" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_Alg.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_ALG_AH_AUTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_AHAuth.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_ALG_ESP_AUTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_ESPAuth.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_ALG_ESP_ENC" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_ESPEnc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_IKE_PRESHARED_KEY" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_PSK.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_IKE_AUTH_METHOD" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_AUTH.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_IKE_ENC_METHOD" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_Encryption.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IPSECAPP_IKE_DH_METHOD" >CUST_IMG_PATH"\\\\MainLCD\\\\IPSEC\\\\Settings\\\\EM_DHGroup.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    //<MENUITEM id="MENU_ID_IPSECAPP_SETTINGS" str="STR_ID_IPSECAPP_PROFILE" img="IMG_ID_IPSECAPP_SETTINGS" highlight="mmi_ipsec_hilite_main"/>
    <MENUITEM id="MENU_ID_IPSECAPP_PROF_SETTINGS_POLICY" str="STR_ID_IPSECAPP_POLICY"/>
    <MENUITEM id="MENU_ID_IPSECAPP_PROF_SETTINGS_IKE" str="STR_ID_IPSECAPP_IKE"/>
    <MENUITEM id="MENU_ID_IPSECAPP_PROF_LIST_OPT_ACTIVATE" str="@OID:STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_IPSECAPP_PROF_LIST_OPT_DEACTIVATE" str="@OID:STR_GLOBAL_DEACTIVATE"/>
    <MENUITEM id="MENU_ID_IPSECAPP_PROF_LIST_OPT_RENAME" str="@OID:STR_GLOBAL_RENAME"/>

    <!--Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */
    <MENU id="MENU_ID_IPSECAPP_PROF_LIST_OPT_EDIT" type="OPTION" str="@OID:STR_GLOBAL_EDIT">
        <MENUITEM_ID>MENU_ID_IPSECAPP_PROF_SETTINGS_POLICY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IPSECAPP_PROF_SETTINGS_IKE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_IPSECAPP_PROF_LIST_OPT" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID default="TRUE">MENU_ID_IPSECAPP_PROF_LIST_OPT_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID default="TRUE">MENU_ID_IPSECAPP_PROF_LIST_OPT_DEACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IPSECAPP_PROF_LIST_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IPSECAPP_PROF_LIST_OPT_RENAME</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_IPSECAPP_SETTINGS" type="APP_SUB" str="STR_ID_IPSECAPP_PROFILE" img="IMG_ID_IPSECAPP_SETTINGS" highlight="mmi_ipsec_hilite_main">
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_IPSEC"/>

    <SCREEN id="SCR_ID_IPSECAPP_PFOF_LIST"/>
    <SCREEN id="SCR_ID_IPSECAPP_PFOF_LIST_OPT"/>
    <SCREEN id="SCR_ID_IPSECAPP_PFOF_SETTING"/>
    <SCREEN id="SCR_ID_IPSECAPP_PROF_PROGRESSING"/>

    <CACHEDATA type="byte" id="NVRAM_IPSEC_ACTIVATE_ON_START" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Ipsec profile is activated </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IPSEC_ACTIVATE_PROF_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x03] </DEFAULT_VALUE>
        <DESCRIPTION> Ipsec activated profile index </DESCRIPTION>
    </CACHEDATA>

</APP>
#endif    /* __MMI_IPSEC__ */