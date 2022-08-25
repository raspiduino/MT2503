/*
*arlo
*/
#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MCAREV30__

#define CUST_MCARE_IMG_PATH "..\\\\..\\\\mmi\\\\tencentmcare\\\\porting\\\\images\\\\" 

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="TENCENT_MCARE">
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    
    #if MCR_MTK_VER>=MTK_VER_1210
    	<MEMORY base = "300*1024" heap = "300*1024" fg="2*1024*1024" />
    #endif
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_MCAREV30_MAIN"/>
    <STRING id="STR_TENCENT_MCARE_BROWSER"/>
		<STRING id="STR_TENCENT_MCARE_FARM"/>
		<STRING id="STR_TENCENT_MCARE_PASTURE"/>
		<STRING id="STR_TENCENT_MCARE_RUNNING"/>
		<STRING id="STR_TENCENT_MCARE_QQ_RUNNING"/>
		<STRING id="STR_TENCENT_MCARE_INSERT_VALID_SIM"/>
		<STRING id="STR_TENCENT_MCARE_IS_ON_FLY_MODE"/>
		<STRING id="STR_MCARE_STORAGE_ERROR_NOTE"/>
		<STRING id="STR_MCARE_SIM_ERROR"/>
		<STRING id="STR_MCARE_NOT_ENOUGH_MEM"/>
		<STRING id="STR_MCARE_STORAGE_NO_SPACE"/>
		<STRING id="STR_MCARE_FILE_CORRUPT_RESTART"/>
		<STRING id="STR_MCARE_LOAD_FAIL"/>
		<STRING id="STR_MCARE_FILE_CORRUPT_ERR"/>
		<STRING id="STR_MCARE_EXEC_FAIL"/>
		<STRING id="STR_MCARE_NETWORK_NOT_READY"/>
		<STRING id="STR_MCARE_USB_MODE"/>
		<STRING id="STR_MCARE_LAST"/>
	<!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_MCAREV30_MAIN" >CUST_MCARE_IMG_PATH"mcare.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_MCR">CUST_MCARE_IMG_PATH"mcare_status.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_ON">CUST_MCARE_IMG_PATH"qq.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_OFF">CUST_MCARE_IMG_PATH"offline.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_AWAY">CUST_MCARE_IMG_PATH"away.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_INVISBLE">CUST_MCARE_IMG_PATH"hide.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_MESSEGE">CUST_MCARE_IMG_PATH"messege.bmp"</IMAGE>
	<MENU id="MENU_MCAREV30_MAIN" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_MCAREV30_MAIN"
    	  img="IMG_MCAREV30_MAIN" 
    	  highlight="mmi_mcare_hilite"
          shortcut="ON" shortcut_img="IMG_MCAREV30_MAIN" launch="mcarev30_main">
	</MENU>
	#ifdef __MCAREV30_BROWSER__
	<IMAGE id="IMG_MCARE_QQ_BROWSER_LOGO">CUST_MCARE_IMG_PATH"M_Browser.gif"</IMAGE>
	<MENU id="MENU_ID_TENCENT_MCARE_BROWSER" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_TENCENT_MCARE_BROWSER"
    	  img="IMG_MCARE_QQ_BROWSER_LOGO" 
    	  highlight="mmi_mcare_browser_hilite"
          shortcut="ON" shortcut_img="IMG_MCARE_QQ_BROWSER_LOGO" launch="MCareV30_BrowserMain">
	</MENU>
	#endif
	#ifdef __MCAREV30_FARM__
	<IMAGE id="IMG_MCARE_QQ_FARM_LOGO">CUST_MCARE_IMG_PATH"M_Farm.gif"</IMAGE>
	<MENU id="MENU_ID_TENCENT_FARM" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_TENCENT_MCARE_FARM"
    	  img="IMG_MCARE_QQ_FARM_LOGO" 
    	  highlight="mmi_mcare_farm_hilite"
          shortcut="ON" shortcut_img="IMG_MCARE_QQ_FARM_LOGO" launch="MCareV30_FarmMain">
	</MENU>
	#endif
	#ifdef __MCAREV30_PASTURE__
	<IMAGE id="IMG_MCARE_QQ_PASTURE_LOGO">CUST_MCARE_IMG_PATH"M_Pasture.gif"</IMAGE>
	<MENU id="MENU_ID_TENCENT_PASTURE" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_TENCENT_MCARE_PASTURE"
    	  img="IMG_MCARE_QQ_PASTURE_LOGO" 
    	  highlight="mmi_mcare_pasture_hilite"
          shortcut="ON" shortcut_img="IMG_MCARE_QQ_PASTURE_LOGO" launch="MCareV30_PastureMain">
	</MENU>
	#endif

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
    <SCREEN id="SCR_ID_MCARE_LIST"/>
    <!--Screen Group Id-->
    <SCREEN id="GRP_ID_MCARE_LIST"/>
    <SCREEN id="GRP_ID_MCARE_TOTAL"/>   
 	<!--Screen ID Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
</APP>
#elif defined(__MCARE_COMMON__)

#define CUST_MCARE_IMG_PATH "..\\\\..\\\\..\\\\vendor\\\\mcare\\\\adaption\\\\resource\\\\image\\\\" 
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */

<APP id="APP_TENCENT_MCARE_BG"
    package_name="native.mtk.tencent_bg"
    name="STR_MCARE_MAIN_BG"
    img="IMG_MCARE_MAIN_BG"
    launch="MCR_Entry"
    hidden_in_mainmenu="true">

    #if (defined __COSMOS_MMI_PACKAGE__)

   	   <MEMORY heap="330*1024" fg="490*1024"/>
       <APPCONCURRENT concurrent_w_order="APP_TENCENT_MCARE_BG, APP_IDLE"/>

    #else /* __PLUTO_MMI_PACKAGE__ */
   	   <MEMORY heap="330*1024" fg="320*1024"/>
       <APPCONCURRENT concurrent_w_order="APP_TENCENT_MCARE_BG, APP_IDLE"/>

    #endif


    <STRING id="STR_MCARE_MAIN_BG"/>

#ifdef __MMI_MAINLCD_320X480__//charmenli add 2012-6-5
	#ifdef __MMI_VUI_LAUNCHER_KEY__
		<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare_key_launcher_hvga.png"</IMAGE>
	#else
		<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare_320_480.png"</IMAGE>
	#endif
#elif defined (__MMI_MAINLCD_240X320__)
	<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#elif defined (__MMI_MAINLCD_240X400__)
	<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#elif defined (__MMI_MAINLCD_480X800__)
	<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare_480_800.png"</IMAGE>
#else
	<IMAGE id="IMG_MCARE_MAIN_BG" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#endif
</APP>

<APP id="APP_TENCENT_MCARE"
    package_name="native.mtk.tencent"
    name="STR_MCARE_MAIN"
    img="IMG_MCARE_MAIN"
    launch="MCR_Entry">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="GlobalMenuItems.h"/>

    #ifdef __COSMOS_MMI_PACKAGE__   //by purple for 1112
    <INCLUDE file = "mmi_rp_vapp_cosmos_mainmenu_def.h"/>
    #else
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    #endif

    #if (defined __COSMOS_MMI_PACKAGE__)

        #if (defined __MCARE_QQBROWSER__)
        <MEMORY heap="1000*1024" cui="VCUI_FMGR"/> /* 230K+1.5MB */
        #else /* QQ2012 */
        <MEMORY heap="820*1024" cui="VCUI_FMGR"/> /* QQ2012 */
        #endif

    #else /* __PLUTO_MMI_PACKAGE__ */
       <MEMORY heap="650*1024"/> /*QQ2009 or QQ2010*/
    #endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_MCARE_MAIN"/>
    <STRING id="STR_MCARE_QQ"/>
		<STRING id="STR_MCARE_QQBROWSER"/>
		<STRING id="STR_MCARE_QQFARM"/>
		<STRING id="STR_MCARE_QQPASTURE"/>
		<STRING id="STR_MCARE_RUNNING"/>
		<STRING id="STR_MCARE_QQ_RUNNING"/>
		<STRING id="STR_MCARE_INSERT_VALID_SIM"/>
 		<STRING id="STR_MCARE_IS_ON_FLY_MODE"/>   
 		<STRING id="STR_MCARE_STORAGE_ERROR_NOTE"/>
		<STRING id="STR_MCARE_SIM_ERROR"/>
		<STRING id="STR_MCARE_NOT_ENOUGH_MEM"/>
		<STRING id="STR_MCARE_STORAGE_NO_SPACE"/>
		<STRING id="STR_MCARE_FILE_CORRUPT_RESTART"/>
		<STRING id="STR_MCARE_LOAD_FAIL"/>
		<STRING id="STR_MCARE_FILE_CORRUPT_ERR"/>
		<STRING id="STR_MCARE_EXEC_FAIL"/>
		<STRING id="STR_MCARE_NETWORK_NOT_READY"/>
		<STRING id="STR_MCARE_USB_MODE"/>
		<STRING id="STR_MCARE_LAST"/>


 		<STRING id="STR_TENCENT_MCARE_QQ_ONLINE"/>
		<STRING id="STR_TENCENT_MCARE_QQ_INVISBLE"/>
		<STRING id="STR_TENCENT_MCARE_QQ_OFFLINE"/>
		<STRING id="STR_TENCENT_MCARE_QQ_AWAY"/>
		<STRING id="STR_TENCENT_MCARE_QQ_HAVEMSG"/>

		
 		<!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __MMI_MAINLCD_320X480__//charmenli add 2012-6-5
	#ifdef __MMI_VUI_LAUNCHER_KEY__
		<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare_key_launcher_hvga.png"</IMAGE>
	#else
		<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare_320_480.png"</IMAGE>
	#endif
#elif defined (__MMI_MAINLCD_240X320__)
	<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#elif defined (__MMI_MAINLCD_240X400__)
	<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#elif defined (__MMI_MAINLCD_480X800__)
	<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare_480_800.png"</IMAGE>
#else
	<IMAGE id="IMG_MCARE_MAIN" >CUST_MCARE_IMG_PATH"mcare.png"</IMAGE>
#endif
    <IMAGE id="IMG_MCARE_STAT_MCR">CUST_MCARE_IMG_PATH"mcare_status.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_ON">CUST_MCARE_IMG_PATH"qq.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_OFF">CUST_MCARE_IMG_PATH"offline.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_AWAY">CUST_MCARE_IMG_PATH"away.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_INVISBLE">CUST_MCARE_IMG_PATH"hide.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_QQ_MESSEGE">CUST_MCARE_IMG_PATH"messege.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_STAT_CONTACT_ON">CUST_MCARE_IMG_PATH"contact.bmp"</IMAGE>
    
    <IMAGE id="IMG_MCARE_NCENTER_MCR">CUST_MCARE_IMG_PATH"ncenter_mcare_status.bmp"</IMAGE>
    <IMAGE id="IMG_MCARE_NCENTER_QQ_ON">CUST_MCARE_IMG_PATH"ncenter_qq.png"</IMAGE>
    <IMAGE id="IMG_MCARE_NCENTER_QQ_OFF">CUST_MCARE_IMG_PATH"ncenter_offline.png"</IMAGE>
    <IMAGE id="IMG_MCARE_NCENTER_QQ_AWAY">CUST_MCARE_IMG_PATH"ncenter_away.png"</IMAGE>
    <IMAGE id="IMG_MCARE_NCENTER_QQ_INVISBLE">CUST_MCARE_IMG_PATH"ncenter_hide.png"</IMAGE>
    <IMAGE id="IMG_MCARE_NCENTER_QQ_MESSEGE">CUST_MCARE_IMG_PATH"ncenter_messege.png"</IMAGE>


#ifndef __COSMOS_MMI_PACKAGE__	
	<MENU id="MENU_ID_MCARE_MAIN" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_MCARE_MAIN"
    	  img="IMG_MCARE_MAIN" 
    	  highlight="MCR_HiliteMenu"
          shortcut="ON" shortcut_img="IMG_MCARE_MAIN" launch="MCR_Entry">
	</MENU>
	#ifdef __MCARE_QQBROWSER__
	<IMAGE id="IMG_MCARE_QQBROWSER_LOGO">CUST_MCARE_IMG_PATH"M_Browser.gif"</IMAGE>
	<MENU id="MENU_ID_MCARE_QQBROWSER" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_MCARE_QQBROWSER"
    	  img="IMG_MCARE_QQBROWSER_LOGO" 
    	  highlight="MCR_HiliteQQBrowser"
          shortcut="ON" shortcut_img="IMG_MCARE_QQBROWSER_LOGO" launch="MCR_EntryQQBrowser">
	</MENU>
	#endif
#if 0
	#ifdef __MCARE_QQFARM__
	<IMAGE id="IMG_MCARE_QQFARM_LOGO">CUST_MCARE_IMG_PATH"M_Farm.gif"</IMAGE>
	<MENU id="MENU_ID_MCARE_QQFARM" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_MCARE_QQFARM"
    	  img="IMG_MCARE_QQFARM_LOGO" 
    	  highlight="MCR_HiliteQQFarm"
          shortcut="ON" shortcut_img="IMG_MCARE_QQFARM_LOGO" launch="MCR_EntryQQFarm">
	</MENU>
	#endif
	#ifdef __MCARE_QQPASTURE__
	<IMAGE id="IMG_MCARE_QQPASTURE_LOGO">CUST_MCARE_IMG_PATH"M_Pasture.gif"</IMAGE>
	<MENU id="MENU_ID_MCARE_QQPASTURE" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_SERVICES_MENUID"
    	  str="STR_MCARE_QQPASTURE"
    	  img="IMG_MCARE_QQPASTURE_LOGO" 
    	  highlight="MCR_HiliteQQPasture"
          shortcut="ON" shortcut_img="IMG_MCARE_QQPASTURE_LOGO" launch="MCR_EntryQQPasture">
	</MENU>
	#endif
#endif
#endif

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
    <SCREEN id="SCR_ID_MCARE_LIST"/>
    <!--Screen Group Id-->
    <SCREEN id="GRP_ID_MCARE_LIST"/>
    <SCREEN id="GRP_ID_MCARE_TOTAL"/>   
 	<!--Screen ID Area-->
    <!--End Screen Resource Area-->
   <!--------------------------------------------------------------------------------------------------------------------->
   
   <!--------------------------------------------------------------------------------------------------------------------->
	<!--event handler Area-->
   <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="MCR_HandleUsbPlugIn"/>
   <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="MCR_HandleUsbPlugOut"/>

   <EVENT id="EVT_ID_VAPP_MCARE_UPDATE_NCENTER" type="SENDER"/>
   <RECEIVER id="EVT_ID_VAPP_MCARE_UPDATE_NCENTER" proc="vapp_mcare_on_ncenter_update"/>

    <RECEIVER id="EVT_ID_SRV_FMGRI_CARD_PLUG_OUT"                proc="MCR_HandleCardPlugOut" />
  <!--event handler Area-->
  <!--------------------------------------------------------------------------------------------------------------------->
  
</APP>
#endif

