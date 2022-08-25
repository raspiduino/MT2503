#include "mmi_features.h"

#ifdef __MMI_MOT_SUPPORT__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MOT"
name = "STR_ID_MOT_APP_NAME"                    /* The string to be displayed under the main menu icon */
type="pluto"
#if defined(__MMI_APP_MANAGER_SUPPORT__) 
        package_name = "native.mtk.mot"         /* Use "native.mtk." as the prefix of application name */
        #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
        img = "IMG_ID_MOT_VUI_MAIN_MENU_APP_ICON"   /* Main menu icon image */
        #endif
        launch = "mmi_mot_launch"               /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                         * the function prototype should be:
                                                         *
                                                         *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                         *
                                                         * Note that the group_id of the application should be returned if launch successfully.
                                                         * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
<INCLUDE file="GlobalResDef.h"/>

<!----------------------------------------------------- Memory Config Area ----------------------------------------------------->
    <MEMORY heap= "0" extra_base="base(SRV_MOT)+ MMI_MOT_APP_CONTEXT_BUF_SIZE" fg="fg(SRV_MOT)" inc="MotGprot.h"/> 

<!--------------------------------------String resource area------------------->
    <STRING id="STR_ID_MOT_APP_NAME"/>
    <STRING id="STR_ID_MOT_DURATION"/>
    <STRING id="STR_ID_MOT_UNKNOWN_FILENAME"/>
    <STRING id="STR_ID_MOT_UNKNOWN_CLASS"/>
    <STRING id="STR_ID_MOT_FILENAME"/>
    <STRING id="STR_ID_MOT_MOVIE_NAME"/>
    <STRING id="STR_ID_MOT_STARRING"/>
    <STRING id="STR_ID_MOT_YEAR"/>
    <STRING id="STR_ID_MOT_PLOT"/>
    <STRING id="STR_ID_MOT_CATEGORY"/>

<!--------------------------------------Image resource area------------------->
<IMAGE id="IMG_ID_MOT_APP_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MOT\\\\SB_MOT.bmp"</IMAGE>
<IMAGE id="IMG_ID_MOT_DEFAULT_THUMBNAIL" >CUST_IMG_PATH"\\\\MainLCD\\\\MOT\\\\MOT_thumbnail_default.png"</IMAGE>

#if defined(__MMI_APP_MANAGER_SUPPORT__) && (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
    <IMAGE id="IMG_ID_MOT_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\mot.png"</IMAGE>
#endif

<!--------------------------------------Menu resource area-------------------> 
    <MENU id="MENU_ID_MOT_APP" type="APP_MAIN" str="STR_ID_MOT_APP_NAME" img="IMG_ID_MOT_APP_ICON" highlight="mmi_mot_highlight_app">
    </MENU>
    
    <MENUITEM id="MENU_ID_MOT_CATEGORY_LIST_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MOT_CATEGORY_LIST_REFRESH" str="STR_GLOBAL_REFRESH"/>
    <MENU id="MENU_ID_MOT_CATEGORY_LIST_OPTIONS" type="OPTION" str="STR_ID_MOT_APP_NAME">
            <MENUITEM_ID>MENU_ID_MOT_CATEGORY_LIST_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MOT_CATEGORY_LIST_REFRESH</MENUITEM_ID>          
    </MENU>
    
    <MENUITEM id="MENU_ID_MOT_VIDEO_LIST_PLAY_VIDEO" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MOT_VIDEO_LIST_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENU id="MENU_ID_MOT_VIDEO_LIST_OPTIONS" type="OPTION" str="STR_ID_MOT_APP_NAME">
            <MENUITEM_ID>MENU_ID_MOT_VIDEO_LIST_PLAY_VIDEO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MOT_VIDEO_LIST_DETAILS</MENUITEM_ID>          
    </MENU>
    
    <!-------------------------------------------------------------------Screen resource area----------------------------------------------------------->
    <SCREEN id="GRP_ID_MOT"/>
    <SCREEN id="GRP_ID_MOT_VIDEO_CATEGORY"/>
    <SCREEN id="GRP_ID_MOT_VIDEO_DETAILS"/>
    <SCREEN id="SCR_ID_MOT_WAITING_SCREEN"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_CAT_LIST"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_LIST"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_DETAILS"/>    
    
    <!------------------------------------------------------CM Resource---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_mot_app_proc"/>  
</APP>
#endif