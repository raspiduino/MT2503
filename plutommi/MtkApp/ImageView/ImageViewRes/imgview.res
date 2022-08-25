/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/**
 *  opyright Notice
 *  2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *  ancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

FILENAME: imageview.res

PURPOSE: add imageviewer resource

REMARKS: nil

AUTHOR: Jibin Zhang

DATE: Mar-8-2003

**************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "CustomCfg.h"
#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif
#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustResDef.h"
//#include "MMI_features_camera.h"
#include "ImgViewerConfig.h"
#define __MMI_IV_ULTRA_SLIM__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_IMAGE_VIEWER_EX__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_IMAGEVIEWER"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.imageviewer"         /* Use "native.mtk." as the prefix of application name */
    name = "STR_ID_IMGVIEW_NAME"                    /* The string to be displayed under the main menu icon */
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
    img = "IMG_ID_IMGVIEW_VUI_MAIN_MENU_APP_ICON"   /* Main menu icon image */
#endif
    launch = "mmi_imgview_launch"                   /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                     * the function prototype should be:
                                                     *
                                                     *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                     *
                                                     * Note that the group_id of the application should be returned if launch successfully.
                                                     * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#else /* defined(__MMI_APP_MANAGER_SUPPORT__) */
   name = "STR_ID_IMGVIEW_NAME"
#endif
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="lcd_sw_inc.h"/>
    <INCLUDE file="PopulateRes.h"/>
    <INCLUDE file="CustResDef.h"/>
    <INCLUDE file="FileMgrServiceResDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>

    /*********************************************
    **                     String               **
    **********************************************/
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_IMGVIEW_NAME"/>
#ifndef __MMI_IVF_OPTION__
    <STRING id="STR_ID_IMGVIEW_ROTATE"/>
#endif
#ifndef __MMI_IVF_MOTION__
    <STRING id="STR_ID_IMGVIEW_ROTATE_VIEW"/>
#endif
#ifndef __MMI_IV_PLUTO_SLIM__
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE_LIST"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE_MATRIX"/>
#endif
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_FILENAME"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_RESOLUTION"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_SIZE"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_CREATE_TIME"/>
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <STRING id="STR_ID_IMGVIEW_OPTION_SEND_TO_SNS"/>
#endif

    /*********************************************
    **                     Images               **
    **********************************************/
#ifndef __MMI_FTE_SUPPORT__

#define IV_IMG_PATH_SPECIFIC    CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\"
#ifdef __MMI_SLIM_IMG_RES__
#define IV_IMG_PATH_APP_ICON    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\ImageViewer\\\\"
#define IV_IMG_PATH_COMMON      CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\"
#define IV_ICON_EXT     ".bmp"
#else
#define IV_IMG_PATH_APP_ICON    IV_IMG_PATH_SPECIFIC
#define IV_IMG_PATH_COMMON      IV_IMG_PATH_SPECIFIC
#define IV_ICON_EXT     ".png"
#define IV_ENABLE_FORCE_TYPE
#endif

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24) && defined(IV_ENABLE_FORCE_TYPE)
#define IV_ICON_TYPE    force_type="FORCE_ABM"
#else
#define IV_ICON_TYPE
#endif

    <!-----------------------------------------------------New Image Resource Area------------------------------------------------------>
#ifndef __MMI_IV_PLUTO_SLIM__
    <IMAGE id="IMG_ID_IMGVIEW_MAIN_ICON">IV_IMG_PATH_APP_ICON"SB_Viewer.bmp"</IMAGE>
#endif
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
    <IMAGE id="IMG_ID_IMGVIEW_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\ImageViewer.png"</IMAGE>
#endif
#endif
#ifndef __MMI_IV_PLUTO_SLIM__
    <IMAGE id="IMG_ID_IV_ERROR">IV_IMG_PATH_SPECIFIC"iv_error.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IV_LOAD">IV_IMG_PATH_SPECIFIC"iv_load.bmp"</IMAGE>
#endif
#ifdef __DRM_SUPPORT__
    <IMAGE id="IMG_ID_IV_ERROR_NO_RIGHT">IV_IMG_PATH_SPECIFIC"iv_drm.bmp"</IMAGE>
#endif

#if defined (__MMI_IVF_OSD_PANEL__)
    <IMAGE id="IMG_ID_IV_BTN_ZOOMIN" IV_ICON_TYPE>IV_IMG_PATH_COMMON"zoom_in"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_ZOOMOUT" IV_ICON_TYPE>IV_IMG_PATH_COMMON"zoom_out"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_CWR" IV_ICON_TYPE>IV_IMG_PATH_COMMON"cw"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_CCWR" IV_ICON_TYPE>IV_IMG_PATH_COMMON"ccw"IV_ICON_EXT</IMAGE>
#if defined (__MMI_IVF_OSD_SK_TEXT__)
    <IMAGE id="IMG_ID_IV_BTN_LSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"EmptyImage"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_RSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"EmptyImage"IV_ICON_EXT</IMAGE>
#else /*__MMI_IVF_OSD_SK_TEXT__*/
    <IMAGE id="IMG_ID_IV_BTN_LSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"option"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_RSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"back"IV_ICON_EXT</IMAGE>
#endif /*__MMI_IVF_OSD_SK_TEXT__*/
    <IMAGE id="IMG_ID_IV_BTN_BG" IV_ICON_TYPE>IV_IMG_PATH_COMMON"button"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_HL_MASK">IV_IMG_PATH_COMMON"highlight.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_DIS_MASK">IV_IMG_PATH_COMMON"disable.9slice.png"</IMAGE>
#endif /* __MMI_SLIM_IMG_RES__ */

#else /* __MMI_FTE_SUPPORT__ */

#define IV_IMG_PATH_SPECIFIC    CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\"
#define IV_IMG_PATH_APP_ICON    IV_IMG_PATH_SPECIFIC
#define IV_IMG_PATH_COMMON      IV_IMG_PATH_SPECIFIC
#define IV_ICON_EXT     ".bmp"
#define IV_ICON_TYPE

    <!-----------------------------------------------------New Image Resource Area------------------------------------------------------>
#ifndef __MMI_IV_PLUTO_SLIM__    
    <IMAGE id="IMG_ID_IMGVIEW_MAIN_ICON">IV_IMG_PATH_APP_ICON"SB_Viewer.bmp"</IMAGE>
#endif
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
    <IMAGE id="IMG_ID_IMGVIEW_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\ImageViewer.png"</IMAGE>
#endif
#endif
#ifndef __MMI_IV_PLUTO_SLIM__
    <IMAGE id="IMG_ID_IV_ERROR">IV_IMG_PATH_SPECIFIC"iv_error.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IV_LOAD">IV_IMG_PATH_SPECIFIC"iv_load.bmp"</IMAGE>
#endif
#ifdef __DRM_SUPPORT__
    <IMAGE id="IMG_ID_IV_ERROR_NO_RIGHT">IV_IMG_PATH_SPECIFIC"iv_drm.bmp"</IMAGE>
#endif

#if defined (__MMI_IVF_OSD_PANEL__)
    <IMAGE id="IMG_ID_IV_BTN_ZOOMIN" IV_ICON_TYPE>IV_IMG_PATH_COMMON"zoom_in"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_ZOOMOUT" IV_ICON_TYPE>IV_IMG_PATH_COMMON"zoom_out"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_CWR" IV_ICON_TYPE>IV_IMG_PATH_COMMON"cw"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_CCWR" IV_ICON_TYPE>IV_IMG_PATH_COMMON"ccw"IV_ICON_EXT</IMAGE>
#if defined (__MMI_IVF_OSD_SK_TEXT__)
    <IMAGE id="IMG_ID_IV_BTN_LSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"EmptyImage"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_RSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"EmptyImage"IV_ICON_EXT</IMAGE>
#else /*__MMI_IVF_OSD_SK_TEXT__*/
    <IMAGE id="IMG_ID_IV_BTN_LSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"option"IV_ICON_EXT</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_RSK" IV_ICON_TYPE>IV_IMG_PATH_COMMON"back"IV_ICON_EXT</IMAGE>
#endif /*__MMI_IVF_OSD_SK_TEXT__*/
    <IMAGE id="IMG_ID_IV_BTN_BG" IV_ICON_TYPE>IV_IMG_PATH_COMMON"button.9slice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_HL_MASK">IV_IMG_PATH_COMMON"highlight.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IV_BTN_DIS_MASK">IV_IMG_PATH_COMMON"disable.9slice.png"</IMAGE>
#endif /* __MMI_SLIM_IMG_RES__ */

#endif /* __MMI_FTE_SUPPORT__ */

    /*********************************************
    **                     MENU               **
    **********************************************/
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    <MENU id = "MENU_ID_IMGVIEW_APP" type = "APP_MAIN" str = "STR_ID_IMGVIEW_NAME" 
    #ifndef __MMI_IV_PLUTO_SLIM__
        img = "IMG_ID_IMGVIEW_MAIN_ICON" 
    #endif
    highlight = "mmi_imgview_highlight_app" shortcut="ON" 
#ifndef __MMI_IV_PLUTO_SLIM__
    shortcut_img="IMG_ID_IMGVIEW_MAIN_ICON"
#endif
 launch="mmi_imgview_launch"/>
#if (defined(__MMI_MAINLCD_240X400__) && defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
    <MENU id = "MAIN_MENU_OPTION_IMGVIEW_APP" type = "APP_MAIN" str = "STR_ID_IMGVIEW_NAME" img = "MAIN_MENU_IMGVIEW_ICON" highlight = "mmi_imgview_highlight_app"/>
#endif

    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_DETAIL" str = "STR_GLOBAL_VIEW"/>
#ifndef __MMI_IV_PLUTO_SLIM__
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_STYLE_LIST" str = "STR_ID_IMGVIEW_VIEW_STYLE_LIST"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX" str = "STR_ID_IMGVIEW_VIEW_STYLE_MATRIX"/>
    <MENU id = "MENU_ID_IMGVIEW_VIEW_STYLE" str = "STR_ID_IMGVIEW_VIEW_STYLE">
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX</MENUITEM_ID>
    </MENU>
#endif
    <MENUITEM id = "MENU_ID_IMGVIEW_STORAGE" str = "STR_GLOBAL_STORAGE"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_PLAY" str = "STR_GLOBAL_PLAY"/>
#ifndef __MMI_IVF_MOTION__
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_ROTATE_VIEW" str = "STR_ID_IMGVIEW_ROTATE_VIEW"/>
#endif
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_USE" str = "STR_GLOBAL_USE_AS"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_SEND" str = "STR_GLOBAL_SEND"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_INFO" str = "STR_ID_IMGVIEW_OPTION_IMG_INFO"/>

    <MENU id = "MENU_ID_IMGVIEW_VIEW_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" 
#ifndef __MMI_IV_PLUTO_SLIM__
img = "IMG_ID_IMGVIEW_MAIN_ICON"
#endif
>
    #if defined(__MMI_RMGR__)
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_ROTATE_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_USE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_INFO</MENUITEM_ID>
    </MENU>

    <!-- For fmgr option menu -->
    <MENUITEM id = "MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION" parent = "MENU_ID_IMGVIEW_APP" str = "STR_ID_IMGVIEW_OPTION_IMG_INFO"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_OPTION_IMG_VIEW" parent = "MENU_ID_IMGVIEW_APP" str = "STR_GLOBAL_VIEW"/>
    <!-- For fmgr option->send menu -->
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <MENUITEM id = "MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD" str = "STR_ID_IMGVIEW_OPTION_SEND_TO_SNS"/>    
#endif

    <MENU id = "MENU_ID_IMGVIEW_FILE_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" 
#ifndef __MMI_IV_PLUTO_SLIM__
img = "IMG_ID_IMGVIEW_MAIN_ICON"
#endif
>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_DETAIL</MENUITEM_ID>
#ifndef __MMI_IV_PLUTO_SLIM__
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
#endif
        <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_STORAGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION</MENUITEM_ID>        
    </MENU>

    <MENU id = "MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" 
#ifndef __MMI_IV_PLUTO_SLIM__
img = "IMG_ID_IMGVIEW_MAIN_ICON"
#endif
>
#ifndef __MMI_IV_PLUTO_SLIM__
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
#endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_STORAGE</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Screen ID Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_IMGVIEW_VIEW"/>
    <SCREEN id="SCR_ID_IMGVIEW_IMG_INFO"/>

    <!------------------------------------------------------MMI Cache Item Resource---------------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_IMGVIEW_VIEW_SYTLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> ImageViewer </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_IMGVIEW_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Image Viewer storage </DESCRIPTION>
    </CACHEDATA>

    /* Memory config for ASM2.0
     * NOTE: FMGR SRV & FMGR CUI are treated in a different way:
     *        FMGR CUI uses no ASM, so it's ommited here
     *        FMGR SRV uses ASM, but due to RD resource limitation,
     *                 APP is responsible to config ASM for it
     *  MEMORY <cui="CUI_IMAGEVIEWER" extra_base="base(SRV_FILEMANAGER)"/>
     *  NOTE: CUI_IMAGEVIEWER already includes MAX_FS_SORT_MEM_SIZE, so it's ommited here.  */
    <MEMORY cui="CUI_IMAGEVIEWER"/>
</APP>

<FILE_TYPES>
    <FILE_TYPE_INC file="mmi_rp_app_imageviewer_def.h"/>
    <FILE_OPTION_HDLR option="MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION" enabler="mmi_imgview_file_type_enabler" handler="mmi_imgview_file_type_handler"/>
    <FILE_OPTION_HDLR option="MENU_ID_IMGVIEW_OPTION_IMG_VIEW" enabler="mmi_imgview_view_enabler" handler="mmi_imgview_view_handler"/>
    <FILE_OPTION_HDLR option="MENU_ID_IMGVIEW_FILE_OPTION" enabler="mmi_fmgr_option_imgviewer_enabler"/>
    <FILE_OPTION_HDLR option="MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION" enabler="mmi_fmgr_empty_option_imgviewer_enabler"/>
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD" enabler="mmi_iv_sns_photo_upload_enabler" handler="mmi_iv_sns_photo_upload_handler"/>
#endif
</FILE_TYPES>

<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_imgview_fmgr_notify_hdlr"/>

#endif  /* defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_IMAGE_VIEWER_EX__) */