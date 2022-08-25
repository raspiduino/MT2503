#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VCALENDAR">

#ifdef __MMI_VCALENDAR__
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>
    
#ifdef __PLUTO_MMI_PACKAGE__
    <INCLUDE file = "Mmi_rp_app_todolist_def.h"/>
    <INCLUDE file = "Mmi_rp_app_calendar_def.h"/>
#endif

#ifdef __COSMOS_MMI_PACKAGE__
    <INCLUDE file = "Mmi_rp_vapp_alarm_def.h"/>
#endif
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

	<STRING id="STR_ID_VCLNDR_FORWARD"/>
	<STRING id="STR_ID_VCLNDR_SAVE_TO_TDL"/>
	<STRING id="STR_ID_VCLNDR_SAVE_TO_CLNDR"/>
	<STRING id="STR_ID_VCLNDR_TASK_FULL"/>
    

	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->
	
    <SCREEN id = "SCR_ID_VCLNDR_FORWARD"/>
    <SCREEN id = "SCR_ID_VCLNDR_FILENAME"/>
    <SCREEN id = "SCR_ID_VCLNDR_FILENAME_OPT"/>
    <SCREEN id = "SCR_ID_VCLNDR_RECV_OPT"/>    

    <SCREEN id = "GRP_ID_VCLNDR_RECV"/>    
    <SCREEN id = "GRP_ID_VCLNDR_SAVE_TO_FILE"/>    
    <SCREEN id = "GRP_ID_VCLNDR_SAVE_TO_TDL"/>    
    <SCREEN id = "GRP_ID_VCLNDR_SEND"/>    

	
	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->
	
    <MENU id="MENU_VCLNDR_RECV_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_VCLNDR_RECV_OPT_CLNDR" str="STR_ID_VCLNDR_SAVE_TO_CLNDR"/>
        <MENUITEM id="MENU_VCLNDR_RECV_OPT_TDL" str="STR_ID_VCLNDR_SAVE_TO_TDL"/>
#if defined(__MMI_FILE_MANAGER__)
        <MENUITEM id="MENU_VCLNDR_RECV_OPT_FMGR" str="@OID:STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>
#endif
    </MENU>    
    
    <MENUITEM id = "MENU_VCLNDR_USE_AS_EVENT" str = "@OID:ORGANIZER_MENU_CALENDER_STRINGID"/>
    <MENUITEM id = "MENU_VCLNDR_USE_AS_TASK" str = "@OID:STR_ID_TDL_TASKS"/>

	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->
#endif /* __MMI_VCALENDAR__ */
</APP>


#ifdef __MMI_VCALENDAR__
<FILE_TYPES>
    <FILE_OPTION_HDLR option="MENU_VCLNDR_USE_AS_EVENT" enabler="mmi_vcal_fmgr_use_enabler" handler="mmi_vcal_fmgr_use_handler"/>
    <FILE_OPTION_HDLR option="MENU_VCLNDR_USE_AS_TASK" enabler="mmi_vcal_fmgr_use_enabler" handler="mmi_vcal_fmgr_use_handler"/>      
</FILE_TYPES>
#endif


