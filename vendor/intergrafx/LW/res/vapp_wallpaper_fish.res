#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"


<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__)
<APP id="APP_VENUS_WALLPAPER_FISH">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_IG_FISH"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
#if defined(__VENUS_3D_UI_ENGINE__)
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_FISH_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_fish_hw.jpg"</IMAGE>
#else
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_FISH_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_fish.jpg"</IMAGE>
#endif

</APP>
#endif

