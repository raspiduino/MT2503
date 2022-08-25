
#include "MMI_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_GB_WINGUO_V2__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GB_WINGUO" 
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    package_name="native.guobi.winguo"
    name="STR_GB_WINGUO_SMARTSEARCH"
    img="IMG_WG_WINGUO_NATIVE_ICON"
    launch="GB_WG_SMD_Search_Screen_Launch" type="venus"
#else /* defined(__MMI_APP_MANAGER_SUPPORT__) */
   name = "STR_GB_WINGUO_SMARTSEARCH"
#endif
    >
#ifdef __COSMOS_MMI_PACKAGE__
#define VAPP_WINGUO_MAX_CUI_MEMORY "max(VCUI_CONTACT_VIEW,VCUI_CONTACT_LIST,VCUI_CONTACT_SAVE,VCUI_DIALER_MAKE_CALL,VUI_SMS_COMPOSER)" 

       <MEMORY heap = "300*1024"
                    extra_base = "300*1024"
                    cui = VAPP_WINGUO_MAX_CUI_MEMORY/>
#else
	<MEMORY base = "300*1024"/>
                    
#endif

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    
    <!-----------------------------------------------------Event handle----------------------------------------------------->
/*		
		<RECIEVER id="EVT_ID_PHB_ADD_CONTACT" proc="srv_sync_contact_addition_notification"/>
		<RECIEVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_sync_contact_modification_notification"/>
		<RECIEVER id="EVT_ID_PHB_DEL_CONTACT" proc="srv_sync_contact_deletion_notification"/>
		<RECEIVER id="EVT_ID_PHB_READY" proc="mmi_phb_ready_hdlr"/>
*/
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    
		<STRING id="STR_GB_WINGUO_SMARTSEARCH"/>
		<STRING id="STR_GB_WINGUO_CALL"/>
		<STRING id="STR_GB_WINGUO_EXIT"/>
		<STRING id="STR_GB_WINGUO_SEARCH"/>
		<STRING id="STR_GB_WINGUO_ENTRY"/>
		<STRING id="STR_GB_WINGUO_INVALID_NUMBER"/>
		<STRING id="STR_GB_WINGUO_NOT_USE"/>
		<STRING id="STR_GB_WINGUO_SMS"/>
		<STRING id="STR_GB_WINGUO_MMS"/>
		<STRING id="STR_GB_WINGUO_SAVE_ITEM"/>
		<STRING id="STR_GB_WINGUO_APP"/>
#if defined(__COSMOS_MMI_PACKAGE__)	
		<STRING id="STR_GB_WINGUO_MESSAGE"/>
		<STRING id="STR_GB_WINGUO_VIEWCONTACT"/>
		<STRING id="STR_GB_WINGUO_NOCONTENT"/>
		<STRING id="STR_GB_WINGUO_NOAPPLICATION"/>
		<STRING id="STR_GB_WINGUO_DELETERECORD"/>
		<STRING id="STR_GB_WINGUO_CALL_TO"/>
		<STRING id="STR_GB_WINGUO_MASSEGE_TO"/>
#endif
		<STRING id="STR_GB_WINGUO_UNNAMED"/>
		<STRING id="STR_GB_WINGUO_NO_NUMBER"/>
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    
    <IMAGE id="IMG_GB_SMARTWINGUO_APPLICATIOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\application.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_FAX">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_FAX.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_HOME_PHONE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_HOME_PHONE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MOBILEPHONE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MOBILEPHONE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_OFFICE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_OFFICE.png"</IMAGE>
#if (MMI_MAX_SIM_NUM >= 3)
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM3.png"</IMAGE>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM4.png"</IMAGE>
#endif		
#if defined(__COSMOS_MMI_PACKAGE__)
    <IMAGE id="IMG_WG_WINGUO_SKIN_LIST_NORMAL_FLAG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skin_list_normal_flag.png"</IMAGE>   
		<IMAGE id="IMG_WG_SMARTDAIL_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_CALL.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SAVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SAVE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SMS.png"</IMAGE>
    <IMAGE id="IMG_WG_SMD_CANCEL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IM_WG_SMD_CANCEL.png"</IMAGE>
    <IMAGE id="IMG_WG_SMD_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IM_WG_SMD_NEW_MSG.png"</IMAGE>
    <IMAGE id="IMG_WG_SMD_SEARCH2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IM_WG_SMD_SEARCH2.png"</IMAGE>
    <IMAGE id="IMG_WG_SMD_DIALPAD">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IM_WG_SMD_DIALPAD.png"</IMAGE>
    <IMAGE id="IMG_WG_SMD_SAVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IM_WG_SMD_SAVE.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCH_G">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_search_g.png"</IMAGE>
#else
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_search.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCH_PRESS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_search_press.png"</IMAGE>
#endif

#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_SHELL_MULTI_PAGE__)
		<IMAGE id="IMG_WG_WINGUO_NATIVE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_WINGUO_NATIVE_ICON.png"</IMAGE>
#endif

	/* ----------------------------------------------------------screen id----------------------------------------------------------------- */
		<SCREEN id="GRP_GB_WINGUO_SCREEN"/>
    <SCREEN id="SCR_GB_WINGUO_SCREEN"/>
    <SCREEN id="SCR_GB_WINGUO_SHOW_SIM"/>
    <SCREEN id="SCR_GB_WINGUO_SELECT_SIM"/>
    <SCREEN id="SCR_GB_WINGUO_SELECT_GPRS"/>
    <SCREEN id="SCR_ID_GB_IDLEHW"/>


//#if (defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__))
//    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetWinguoPublisher"/>
//#endif
#if !defined(__COSMOS_MMI_PACKAGE__)
		<MENU id="MITEM_WINGUO_VIEW_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_WINGUO_DIAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WINGUO_SEND_SMS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WINGUO_SEND_MMS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WINGUO_SAVE_CONTACT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WINGUO_SEARCH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WINGUO_EXIT</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_WINGUO_DIAL" str="STR_GLOBAL_DIAL"/>
    <MENUITEM id="MENU_ID_WINGUO_SEND_SMS" str="STR_GB_WINGUO_SMS"/>
    <MENUITEM id="MENU_ID_WINGUO_SEND_MMS" str="STR_GB_WINGUO_MMS"/>
    <MENUITEM id="MENU_ID_WINGUO_SAVE_CONTACT" str="STR_GB_WINGUO_SAVE_ITEM"/>
    <MENUITEM id="MENU_ID_WINGUO_SEARCH" str="STR_GB_WINGUO_SEARCH"/>
    <MENUITEM id="MENU_ID_WINGUO_EXIT" str="STR_GB_WINGUO_EXIT"/>
#endif
    
/***************************************** Timer ****************************************/

    <TIMER id="GB_WG2_TIME"/>
    <TIMER id="GB_WG2_HW_TIME"/>
    <TIMER id="GB_WG2_SMD_RELEAS_TIME"/>
    

/***************************************** RECEIVER ****************************************/

    <RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="GB_SMD_PhoneNumAddNotification"/>
    <RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="GB_SMD_PhoneNumDeleteNotification"/>
    <RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="GB_SMD_PhoneNumUpdateNotification"/>
    
</APP>
#endif /* #if defined(__MMI_GB_WINGUO__)*/

