#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__)
<APP id="APP_VENUS_WALLPAPER_INTERGRAFX"
    package_name="intergrafx.wallpaper"
    name="STR_ID_LIVE_WALLPAPER_INTERGRAFX"
    type="venus" hidden_in_mainmenu="true">

#if defined(__VENUS_3D_UI_ENGINE__)
    <MEMORY base="2*1024*1024" />
    <APPCONCURRENT concurrent_w_order="VAPP_PLATFORM_CONTEXT, APP_VENUS_WALLPAPER_INTERGRAFX, VAPP_WIDGET_DELEGATOR_IDLE, VAPP_WIDGET_ADP, VAPP_LAUNCHER"/>
#else
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="6*1024*1024" />
    #else
        <MEMORY base="4*1024*1024" />
    #endif
    <APPCONCURRENT concurrent="APP_VENUS_WALLPAPER_INTERGRAFX, VAPP_WIDGET_DELEGATOR"/>
    <APPCONCURRENT concurrent_w_order="APP_JAVA, VAPP_PLATFORM_CONTEXT, APP_VENUS_WALLPAPER_INTERGRAFX, VAPP_WIDGET_ADP, VAPP_WIDGET_DELEGATOR_IDLE, VAPP_HOME"/>
#endif
    

</APP>
#endif


