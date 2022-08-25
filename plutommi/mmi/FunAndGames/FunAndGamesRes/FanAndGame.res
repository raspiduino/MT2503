
#include "MMI_features.h"
#include "CustomCfg.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_FUNANDGAMES" name="STR_SCR3000_FUNANDGAMES_CAPTION">

<STRING id="STR_SCR3000_FUNANDGAMES_CAPTION"/>
<SCREEN id="SCR_ID_FUNANDGAMEG_GROUP"/>

/* Intergrafx 3d game */
#if defined(__MMI_3D_GAME_INTERGRAFX__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__MMI_APP_MANAGER_SUPPORT__)

#if defined(__VENUS_3D_UI_ENGINE__)
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="max(17*1024*1024, total(SRV_MDI_VDOPLY))" />
    #else    
        <MEMORY base="max(15*1024*1024, total(SRV_MDI_VDOPLY))" />
    #endif
#else
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="8*1024*1024" />
    #else
        <MEMORY base="6*1024*1024" />
    #endif
#endif

<SCREEN id="SCR_ID_IG_MAIN"/>
<STRING id="STR_ID_3D_GAME_INTERGRAFX"/>
<IMAGE id="IMG_ID_3D_GAME_INTERGRAFX">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_3DGAME.bmp"</IMAGE>
<MENUITEM id="MENU_ID_3D_GAME_INTERGRAFX" str="STR_ID_3D_GAME_INTERGRAFX" img="IMG_ID_3D_GAME_INTERGRAFX" highlight="mmi_fng_3d_game_intergrafx_hilight_hdlr"/>
#endif

#ifdef __MMI_GAME__
<STRING id="STR_MENU3105_GAMES"/>
<IMAGE id="IMG_MENU3105_GAMES">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_FGGAME.bmp"</IMAGE>
<MENUITEM id="MENU3105_GAMES" str="STR_MENU3105_GAMES" img="IMG_MENU3105_GAMES" highlight="mmi_game_highlight_app"/>
#endif
#if 0
#ifdef __MMI_MOTION_APP__
<STRING id="STR_ID_MOTION_APP"/>
<IMAGE id="IMG_ID_MOTION_APP">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_MOTION.bmp"</IMAGE>
<MENUITEM id="MENU_ID_MOTION_APP" str="STR_ID_MOTION_APP" img="IMG_ID_MOTION_APP" highlight="mmi_motion_highlight_app"/>
#endif
#endif
#ifdef __MMI_3D_GAME__
<STRING id="STR_ID_3D_GAME"/>
<IMAGE id=""/>
<IMAGE id="IMG_ID_3D_GAME">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_3DGAME.bmp"</IMAGE>
<MENUITEM id="MENU_ID_FNG_3D_GAME" str="STR_ID_3D_GAME" img="IMG_ID_3D_GAME" highlight="mmi_game3d_highlight_app"/>
#endif

</APP>


