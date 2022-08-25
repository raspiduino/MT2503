#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VBOOKMARK">

#ifdef __MMI_VBOOKMARK__
    <INCLUDE file = "GlobalResDef.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

    <STRING id="STR_ID_VBKM_SAVE_TO_BOOKMARK"/>
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
    <STRING id="STR_ID_VBKM_SAVE_TO_FMGR"/>
#endif

	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->
	
    <SCREEN id = "SCR_ID_VBKM_RECEIVE_OPTION"/>
	
	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->

    <MENU id="MENU_ID_VBKM_RECV_OPTION" type="OPTION" str="0">
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    <MENUITEM id="MENU_ID_VBKM_RECV_OPTION_VIEW" str="STR_GLOBAL_VIEW"/>
#endif
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
#if defined(__MMI_FILE_MANAGER__)
        <MENUITEM id="MENU_ID_VBKM_RECV_OPTION_SAVE_TO_FMGR" str="STR_ID_VBKM_SAVE_TO_FMGR"/>
#endif        
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
        <MENUITEM id="MENU_ID_VBKM_RECV_OPTION_SAVE_TO_BOOKMARK" str="STR_ID_VBKM_SAVE_TO_BOOKMARK"/>
    </MENU>        


	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->
#endif /* __MMI_VBOOKMARK__ */
</APP>

