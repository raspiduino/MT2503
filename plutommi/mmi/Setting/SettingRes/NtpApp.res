/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "SettingDefs.h"                // FACTORY_RESTORE_DEFAULT_XXX

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_NTP">

#ifdef __NTPD_SUPPORT__
    <STRING id = "STR_ID_NTP_APP"/>
    <SCREEN id="GRP_ID_NTP_APP"/>
    <IMAGE id="IMG_ID_NTP_ICON"/>

    <MENU id="MENU_ID_NTP_APP" type="OPTION" str="STR_ID_NTP_APP">
        <MENUITEM id="MENU_ID_NTP_SET_ON_OFF"></MENUITEM>
        <MENUITEM id="MENU_ID_NTP_DATA_ACCT"></MENUITEM>
    </MENU>
#endif /* __NTPD_SUPPORT__ */ 
</APP>

