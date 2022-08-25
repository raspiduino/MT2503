
#include "MMI_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
#if defined(__GB_WINGUO_4_U__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GB_WINGUO" 
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    package_name="native.guobi.winguo_u"
    name="STR_GB_WINGUO_LOG"
    img="IMG_WG_WINGUO_ICON"
    launch="GB_WG_Search_Web_Launch" 
	#ifndef BROWSER_SUPPORT
	hidden_in_mainmenu = "true"
	#endif
#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    >

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    
    <STRING id="STR_GB_WINGUO_LOG"/>
    <STRING id="STR_GB_WINGUO_SEARCH"/>
    <STRING id="STR_GB_WINGUO_HOMEPAGE"/>
    <STRING id="STR_GB_WINGUO_NET_PRESS_UP"/>
		
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    
    <IMAGE id="IMG_WG_WINGUO_LOGO_OUT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_GB_WG.png"</IMAGE>
    <IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_search.png"</IMAGE>
    <IMAGE id="IMG_WG_WINGUO_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\winguo_icon.png"</IMAGE>
		
	/* ----------------------------------------------------------screen id----------------------------------------------------------------- */
	
    <SCREEN id="GRP_GB_WINGUO_SCREEN"/>
    <SCREEN id="SCR_GB_WINGUO_SCREEN"/>
    
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    
	<MENU id="MENU_ID_SEARCH_WEB_WINGUO_ENTRY" str="STR_GB_WINGUO_LOG" img="IMG_WG_WINGUO_LOGO_OUT" highlight="GB_WG_Search_Web_Highlight_Hdlr"></MENU>

</APP>
#endif /* #if defined(__GB_WINGUO_4_U__)*/

