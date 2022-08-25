/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#ifdef __J2ME__
    #include "j2me_custom.h"
#endif

#if defined(__MMI_MY_FAVORITE__)

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MYFAVORITE"
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    package_name="native.mtk.myfavorite"
    name ="STR_ID_MY_FAVORITE_MAIN"
    img = "IMG_ID_KEY_LAUNCHER_MY_FAVORITE"
    launch="mmi_my_favorite_entry_main"
#endif
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
#if defined(__MMI_MY_FAVORITE_JAVABOX__)
    <INCLUDE file="mmi_rp_app_java_def.h"/>
#endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_MY_FAVORITE_MAIN">My Favorite</STRING>

    /**********************Folder Strings*******************************/
    #if defined(__MMI_MY_FAVORITE_IMAGES__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_IMAGES">Images</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_AUDIO__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_AUDIO">Audio</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_VIDEO__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_VIDEO">Video</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_MMSBOX__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_MMSBOX">MMS Box</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_JAVABOX__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_JAVABOX">Java Box</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_GPLUSGAME">G+ Game</STRING>
        <STRING id="STR_ID_MY_FAVORITE_WAP_GPLUSGAME">G+ Game download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_SWFLASH__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_SWFLASH">SWflash</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_THEME__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_THEME">Themes</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_OTHERS__)
        <STRING id="STR_ID_MY_FAVORITE_FOLDER_OTHERS">Others</STRING>
    #endif

    /**********************Hyperlink Strings*******************************/
    #if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_IMAGES">Image download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_AUDIO">Audio download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_VIDEO">Video download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_MMSBOX">MMS download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_JAVA_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_JAVA">Java download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_SWFLASH">Flash download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_THEME">Theme download</STRING>
    #endif
    #if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
        <STRING id="STR_ID_MY_FAVORITE_WAP_OTHERS">Others download</STRING>
    #endif



    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <IMAGE id="IMG_ID_MY_FAVORITE_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF.PNG"</IMAGE>

    #if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
        <IMAGE id="IMG_ID_KEY_LAUNCHER_MY_FAVORITE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\MainMenu\\\\MF.png"</IMAGE>
    #endif

    /**********************Title Icon*******************************/
    #if defined(__MMI_MY_FAVORITE_IMAGES__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_IMAGES" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_IM.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_AUDIO__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_AUDIO" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_AU.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_VIDEO__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_VIDEO" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_VI.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_MMSBOX__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_MMSBOX" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_MM.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_JAVABOX__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_JAVABOX" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_JA.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_GPLUSGAME" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_GP.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_SWFLASH__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_SWFLASH" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_SW.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_THEME__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_THEME" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_TH.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_OTHERS__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_OTHERS" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_OT.PNG"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_MEMORYCARD__)
        <IMAGE id="IMG_ID_MY_FAVORITE_TITLE_MEMORY_CARD" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_MC.PNG"</IMAGE>
    #endif

    /**********************Menu list Icon*******************************/
    #if defined(__MMI_MY_FAVORITE_IMAGES__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_IMAGES" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_AUDIO__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_AUDIO" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_VIDEO__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_VIDEO" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_MMSBOX__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_MMSBOX" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_JAVABOX__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_JAVABOX" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Javabox.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_GPLUSGAME" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_GPlusGame.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_GPLUSGAME" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_GPlusGame_Url.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_SWFLASH__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_SWFLASH" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWflash.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_THEME__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_THEME" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_OTHERS__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_OTHERS" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_MEMORYCARD__)
        <IMAGE id="IMG_ID_MY_FAVORITE_FOLDER_MEMORY_CARD" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MemoryCard.bmp"</IMAGE>
    #endif

    /**********************Hyperlink Icon (URL icon & Large URL icon)*******************************/
    #if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_IMAGES" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_IMAGES_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_AUDIO" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_AUDIO_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_VIDEO" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_VIDEO_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_MMSBOX" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_MMSBOX_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_JAVA_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_JAVABOX" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_JavaBox_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_JAVABOX_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_JavaBox_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_SWFLASH" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWFlash_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_SWFLASH_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWFlash_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_THEME" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_THEME_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_OTHERS" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_OTHERS_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other_Url_Large.bmp"</IMAGE>
    #endif
    #if defined(__MMI_MY_FAVORITE_IMGVIEW_HYPERLINK__)
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_IMGVIEW" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_ImageView_Url.bmp"</IMAGE>
        <IMAGE id="IMG_ID_MY_FAVORITE_WAP_IMGVIEW_LARGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_ImageView_Url_Large.bmp"</IMAGE>
    #endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

#if defined(__MMI_MY_FAVORITE_JAVABOX__)
    <MENUITEM id="MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN" str="STR_GLOBAL_OPEN" highlight="mmi_my_favorite_highlight_javabox_open"/>

  #if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
    <MENUITEM id="MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS_OPEN" str="STR_GLOBAL_OPEN" highlight="mmi_my_favorite_highlight_gplusgame_open"/>
  #endif

    <MENUITEM id="MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING" str="STR_ID_FNG_SETTING_JAVA" highlight="mmi_my_favorite_highlight_javabox_setting"/>
  #ifdef OGDR_SECURITY_SETTING
        <MENUITEM id="MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY" str="STR_ID_FNG_SECURITY_JAVA" highlight="mmi_my_favorite_highlight_javabox_security"/>
  #endif

  #if (MAX_VM_INSTANCE_NUM > 1)
        <MENUITEM id="MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_MANAGER" str="STR_ID_FNG_JAVA_TASK_MANAGER"/>
  #endif

#endif /* __MMI_MY_FAVORITE_JAVABOX__ */

  #if defined(__MMI_MY_FAVORITE_JAVABOX__)
    <!--Menu Tree Area-->
    <MENU id="MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group="MENU_GROUP_MYFAVORITE_JAVABOX">
        <MENUITEM_ID default="TRUE">MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING</MENUITEM_ID>
    #ifdef OGDR_SECURITY_SETTING
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY</MENUITEM_ID>
    #endif
    #if (MAX_VM_INSTANCE_NUM > 1)
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_MANAGER</MENUITEM_ID>
    #endif
    </MENU>
  #endif /* __MMI_MY_FAVORITE_JAVABOX__ */

  #if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
    <MENU id="MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group="MENU_GROUP_MYFAVORITE_GPLUS">
        <MENUITEM_ID default="TRUE">MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS_OPEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING</MENUITEM_ID>
    #ifdef OGDR_SECURITY_SETTING
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY</MENUITEM_ID>
    #endif
    #if (MAX_VM_INSTANCE_NUM > 1)
        <MENUITEM_ID>MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_MANAGER</MENUITEM_ID>
    #endif
    </MENU>
  #endif


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_MY_FAVORITE"/>
    <SCREEN id="SCR_MY_FAVORITE_MAIN"/>
    <SCREEN id="GRP_ID_MY_FAVORITE_OPTION"/>

</APP>



#endif    /* __MMI_MY_FAVORITE__ */

