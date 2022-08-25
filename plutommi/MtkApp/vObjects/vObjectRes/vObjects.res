
#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VOBJECT">

    <INCLUDE file = "GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
#ifdef __MMI_VCARD__
    <STRING id="STR_ID_VCARD"/>
#endif
#ifdef __MMI_VCALENDAR__
    <STRING id="STR_ID_VCLNDR"/>
#endif
#ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VBKM"/>
#endif
    
#ifdef __MMI_VCARD__
    <STRING id="STR_ID_VOBJ_RECV_VCARD"/>
#endif

#ifdef __MMI_VCALENDAR__
    <STRING id="STR_ID_VOBJ_RECV_VCLNDR"/>
#endif

#ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VOBJ_RECV_VBKM"/>
#endif

    <STRING id="STR_ID_VOBJ_RECEIVE_FALL"/>
    
#ifdef __MMI_FILE_MANAGER__
    <STRING id="STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>
#ifdef __MMI_VCARD__
    <STRING id="STR_ID_VOBJ_DUPLICATE_FILENAME"/>
    <STRING id="STR_ID_VOBJ_FILE_PATH_TOO_LONG"/>
#endif
#endif /* __MMI_FILE_MANAGER__ */
    
	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->

    <SCREEN id = "SCR_ID_VOBJ_RECV_OBJECT"/>
    <SCREEN id = "GRP_ID_VOBJ_BEGIN"/>
    <SCREEN id = "GRP_ID_VOBJ_REC_IMPS"/>
    <SCREEN id = "GRP_ID_VOBJ_REC_IDLE"/>
    <SCREEN id = "GRP_ID_VOBJ_END"/>

	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->
	
    <MENUITEM id = "MENU_ID_VOBJ_FMGR_SEND_SMS" str = "@OID:STR_GLOBAL_AS_TEXT_MESSAGE"/>
    
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)|| defined(__MMI_VBOOKMARK__)    
    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_VOBJ_FMGR_SEND_SMS" enabler="mmi_vobj_fmgr_use_enabler" handler="mmi_vobj_fmgr_use_handler"/>
    </FILE_TYPES>
#endif   

    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_vobj_exit_usb_ms_callback"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_vobj_phone_format_handler"/>
#endif

    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

</APP>
