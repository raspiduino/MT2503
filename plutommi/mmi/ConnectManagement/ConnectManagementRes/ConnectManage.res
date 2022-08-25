#include "MMI_features.h" 
#include "custresdef.h"

#ifdef __MMI_CBM_CONNECTION_MANAGER__

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_CONNECTMANAGE">

/* When you use any ID of other module, you need to add that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>
    

<!-- 
**************************************** Menu section *****************************************
-->

<MENU id="MENU_ID_CNMGR_APP" str="STR_ID_CNMGR_MAIN" highlight="mmi_cnmgr_entry_bearer_list_highlight_hdlr"/>

<MENU id="MENU_ID_CNMGR_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
    <MENUITEM_ID>MENU_ID_CNMGR_OPTION_DETAIL</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_CNMGR_OPTION_DISC</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_CNMGR_OPTION_DISC_ALL</MENUITEM_ID>
</MENU>

<MENUITEM id="MENU_ID_CNMGR_OPTION_DETAIL" str="STR_GLOBAL_DETAILS"/>
<MENUITEM id="MENU_ID_CNMGR_OPTION_DISC" str="STR_GLOBAL_DISCONNECT"/>
<MENUITEM id="MENU_ID_CNMGR_OPTION_DISC_ALL" str="STR_ID_CNMGR_DISC_ALL"/>

<!-- 
**************************************** String section ***************************************
-->

<STRING id="STR_ID_CNMGR_MAIN"/>
<STRING id="STR_ID_CNMGR_DISC_CONFIRM"/>
<STRING id="STR_ID_CNMGR_DISC_ALL"/>
<STRING id="STR_ID_CNMGR_DISC_ALL_CONFIRM"/>
<STRING id="STR_ID_CNMGR_NO_CONNECTION"/>
<STRING id="STR_ID_CNMGR_DETAIL_APN"/>
<STRING id="STR_ID_CNMGR_DETAIL_TYPE"/>
<STRING id="STR_ID_CNMGR_DETAIL_TYPE_CSD"/>
<STRING id="STR_ID_CNMGR_DETAIL_TYPE_DAILUP"/>
<STRING id="STR_ID_CNMGR_DETAIL_NUMBER"/>
<STRING id="STR_ID_CNMGR_DETAIL_STATUS"/>
<STRING id="STR_ID_CNMGR_DETAIL_NO_TRANSFER"/>
<STRING id="STR_ID_CNMGR_DETAIL_TRANSFERING"/>
<STRING id="STR_ID_CNMGR_DETAIL_DISCONNECTED"/>
<STRING id="STR_ID_CNMGR_DETAIL_SENT_DATA_SIZE"/>
<STRING id="STR_ID_CNMGR_DETAIL_RECEIVED_DATA_SIZE"/>
<STRING id="STR_ID_CNMGR_DETAIL_ALL_DATA_SIZE"/>
<STRING id="STR_ID_CNMGR_DETAIL_UPLOAD_RATE"/>
<STRING id="STR_ID_CNMGR_DETAIL_DOWNLOAD_RATE"/>
<STRING id="STR_ID_CNMGR_DETAIL_CONN_TIME"/>

<!-- 
**************************************** Screen id section ****************************************
-->

<SCREEN id="SCR_ID_CNMGR_BEARER_LIST"/>
<SCREEN id="SCR_ID_CNMGR_BEARER_DETAIL"/>
<SCREEN id="SCR_ID_CNMGR_OPTION"/>
<SCREEN id="SCR_ID_CNMGR_DISCONNECT_PROCESS"/>

<!-- 
**************************************** image ****************************************
-->
<IMAGE id = "IMG_ID_CNMGR_MAIN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\submenu\\\\services\\\\CBM\\\\SB_CM.bmp"</IMAGE>

</APP>

#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
