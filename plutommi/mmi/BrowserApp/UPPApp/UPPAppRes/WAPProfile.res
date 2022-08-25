/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include  "WAPProfileSrvType.h"


#ifdef WAP_SUPPORT

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MMI_WAP_PROF">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
	<STRING id="STR_ID_WAP_PROF_CBM_BROWSER"/>

#if 0
	<STRING id="STR_ID_WAP_PROF_DTCNT_ALREADY_CONFIGURED"/>
#endif

#ifdef PROV_SUPPORT
	<STRING id="STR_ID_WAP_PROF_PROV_BOOKMARKS_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_BOOKMARK"/>
	<STRING id="STR_ID_WAP_PROF_COLON_CHAR"/>

	<STRING id="STR_ID_WAP_PROF_PROV_ERR_MSG_BKM_NOT_AVAILABLE"/>
	<STRING id="STR_ID_WAP_PROF_ERR_MSG_INVALID_DATA_ACCOUNT"/>
#endif

#ifdef __CCA_SUPPORT__	
#if defined(__MMI_MMS_2__)
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTINGS"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_CM_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_RM_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_MA_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_MS_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_PCADDR_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_RESTRICTED"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_WARNING"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_FREE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_DISABLE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_ENABLE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_LOCKED"/>
#endif 
#endif
  
  <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SCREEN id="GRP_ID_WAP_PROF_DTCNT_DISPLAY"/>
#ifndef __SRV_UPP_SLIM__
    <SCREEN id="SCR_ID_WAP_PROF_PLEASE_WAIT"/>
  #endif
  #ifdef PROV_SUPPORT
    <SCREEN id="SCR_ID_WAP_PROF_PROV_DISPLAY_INFO"/>
  #endif

  /* Event Handlers Begin*/
/*****************************UPP Srv events ***********************************************/

#ifdef PROV_SUPPORT
    <SENDER id="EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND" hfile="WAPprovisioningSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND" hfile="WAPprovisioningSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND" hfile="WAPprovisioningSrvGProt.h"/>
	 <SENDER id="EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND" hfile="WAPProfileSrvGProt.h"/>
#endif
    <SENDER id="EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_DISPLAY_POPUP_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_CLOSE_CUI_IND" hfile="WAPProfileSrvGProt.h"/>
#ifndef __SRV_UPP_SLIM__
	<SENDER id="EVT_ID_SRV_UPP_ENTRY_PLEASE_WAIT_SCRN" hfile="WAPProfileSrvGProt.h"/>
#endif
    <SENDER id="EVT_ID_SRV_UPP_CHECK_DTCNT_VALID" hfile="WAPProfileSrvGProt.h"/>
    <SENDER id="EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED" hfile="WAPProfileSrvGProt.h"/>

#ifdef PROV_SUPPORT
    <RECEIVER id="EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND" proc="mmi_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND" proc="mmi_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND" proc="mmi_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND" proc="mmi_wap_prof_app_dtcnt_ready_check_hdlr"/>
#endif
	<RECEIVER id="EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND" proc="mmi_wap_prof_app_entry_cui_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_DISPLAY_POPUP_IND" proc="mmi_wap_prof_app_show_popup_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_CLOSE_CUI_IND" proc="mmi_wap_prof_app_close_cui"/>
	<RECEIVER id="EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND" proc="mmi_wap_prof_app_activate_profile_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_UPP_CHECK_DTCNT_VALID" proc="mmi_wap_prof_app_is_dtcnt_valid_hdlr"/>
   <RECEIVER id="EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED" proc="mmi_wap_prof_app_is_re_entry_allowed"/>
 
/*****************************UPP Srv events ***********************************************/ 
</APP>
#endif

