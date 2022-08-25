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

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_IMAGE_VIEWER_EX__)
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
    //<INCLUDE file="ImageViewerResDef.h"/>
#if defined(__MMI_SLIDESHOW__)
    <INCLUDE file="mmi_rp_app_slideshow_def.h"/>
#endif
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
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE_LIST"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_STYLE_MATRIX"/>
    <STRING id="STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD"/>
#if defined(__DRM_SUPPORT__)
    <STRING id="STR_ID_IMGVIEW_NOTIFY_MULTIPART_NOT_SUPPORT"/>
#endif /* __DRM_SUPPORT__ */
    <STRING id="STR_ID_IMGVIEW_CONFIRM_PRINT"/>
#if defined(__MMI_BPP_SUPPORT__)
    <STRING id="STR_ID_IMGVIEW_PRINT_NOT_SUPPORT"/>
#endif /* __MMI_BPP_SUPPORT__ */
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_FILENAME"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_TYPE"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_RESOLUTION"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_SIZE"/>
    <STRING id="STR_ID_IMGVIEW_OPTION_IMG_INFO_CREATE_TIME"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX1"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX2"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX3"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX4"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX5"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX6"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX7"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX8"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX9"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX10"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX11"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_OPTION_HELP_CNTX12"/>
    <STRING id="STR_ID_IMGVIEW_ONLY_ONE_IMAGE_VISIBLE"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_DRM_NEED_RIGHT"/>
    <STRING id="STR_ID_IMGVIEW_VIEW_GET_RIGHT_FAIL"/>
    <STRING id="STR_ID_IMGVIEW_SYSTEM_BUSY"/>
    <STRING id="STR_ID_IMGVIEW_PLAY_SPEED"/>
    <STRING id="STR_ID_IMGVIEW_MOBILE_TV_PLAYER_BG_RUNNING"/>
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <STRING id="STR_ID_IMGVIEW_OPTION_SEND_TO_SNS"/>
#endif

    /*********************************************
    **                     Images               **
    **********************************************/
#define EX_IMG_PATH		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewerex\\\\"
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define  ICON_TYPE   "FORCE_ABM"
#else
#define  ICON_TYPE   "FORCE_AB2"
#endif

#if defined(__MMI_REDUCED_KEYPAD__) && defined (__MMI_TOUCH_SCREEN__)
#define __MMI_IMGVIEWEX_TOUCH__	/* touch only, without key */
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_IMGVIEW_MAIN_ICON">EX_IMG_PATH"SB_Viewer.bmp"</IMAGE>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
    <IMAGE id="IMG_ID_IMGVIEW_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\ImageViewer.png"</IMAGE>
#endif
#endif

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    <IMAGE id="IMG_ID_IVEX_SLIDING_BAR_BG">EX_IMG_PATH"IVEX_SLIDING_BAR_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SLIDER_UP">EX_IMG_PATH"IVEX_SLIDER.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SLIDER_DOWN">EX_IMG_PATH"IVEX_SLIDER.png"</IMAGE>
#endif

#if !(defined(__MMI_FTE_SUPPORT__))
    <IMAGE id="IMG_ID_IVEX_PANEL_SHADOW_P">EX_IMG_PATH"IVEX_panel_shadow.png"</IMAGE>
#if defined(__IMAGE_VIEWER_EX_MEM_SLIM__)
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_P">EX_IMG_PATH"IVEX_panel_bg.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SK_BG_P">EX_IMG_PATH"IVEX_sk_bg.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_P">EX_IMG_PATH"IVEX_panel_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SK_BG_P">EX_IMG_PATH"IVEX_sk_bg.png"</IMAGE>
#endif
    /* Shadow and background under Horizon screen -> number = 3 */
    <IMAGE id="IMG_ID_IVEX_PANEL_SHADOW_H">EX_IMG_PATH"IVEX_h_panel_shadow.png"</IMAGE>
#if defined(__IMAGE_VIEWER_EX_MEM_SLIM__)
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_H">EX_IMG_PATH"IVEX_h_panel_bg.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SK_BG_H">EX_IMG_PATH"IVEX_h_sk_bg.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_H">EX_IMG_PATH"IVEX_h_panel_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_SK_BG_H">EX_IMG_PATH"IVEX_h_sk_bg.png"</IMAGE>
#endif

#ifdef __MMI_IMGVIEWEX_TOUCH__
    /* ICON UP state under Vertical screen -> number = 11 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_P">EX_IMG_PATH"IVEX_zi.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_P">EX_IMG_PATH"IVEX_zo.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_P">EX_IMG_PATH"IVEX_cw.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_P">EX_IMG_PATH"IVEX_ccw.png"</IMAGE>
    /* ICON DOWN state under Vertical screen -> number = 11 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DOWN_P">EX_IMG_PATH"IVEX_zi_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DOWN_P">EX_IMG_PATH"IVEX_zo_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DOWN_P">EX_IMG_PATH"IVEX_cw_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DOWN_P">EX_IMG_PATH"IVEX_ccw_press.png"</IMAGE>
    /* ICON UP state under Horizon screen -> number = 9 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_H">EX_IMG_PATH"IVEX_h_zi.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_H">EX_IMG_PATH"IVEX_h_zo.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_H">EX_IMG_PATH"IVEX_h_cw.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_H">EX_IMG_PATH"IVEX_h_ccw.png"</IMAGE>
    /* ICON DOWN state under Horizon screen -> number = 9 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DOWN_H">EX_IMG_PATH"IVEX_h_zi_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DOWN_H">EX_IMG_PATH"IVEX_h_zo_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DOWN_H">EX_IMG_PATH"IVEX_h_cw_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DOWN_H">EX_IMG_PATH"IVEX_h_ccw_press.png"</IMAGE>
    /* ICON DISABLE state under P/H screen -> number = 10 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_P">EX_IMG_PATH"IVEX_zi_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_P">EX_IMG_PATH"IVEX_zo_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_P">EX_IMG_PATH"IVEX_cw_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_P">EX_IMG_PATH"IVEX_ccw_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_H">EX_IMG_PATH"IVEX_h_zi_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_H">EX_IMG_PATH"IVEX_h_zo_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_H">EX_IMG_PATH"IVEX_h_cw_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_H">EX_IMG_PATH"IVEX_h_ccw_disable.png"</IMAGE>

#else	/*__MMI_IMGVIEWEX_TOUCH__*/
    /* ICON UP state under Vertical screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_P">EX_IMG_PATH"IVEX_zi_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_P">EX_IMG_PATH"IVEX_zo_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_P">EX_IMG_PATH"IVEX_cw_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_P">EX_IMG_PATH"IVEX_ccw_wk.png"</IMAGE>
    /* ICON DOWN state under Vertical screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DOWN_P">EX_IMG_PATH"IVEX_zi_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DOWN_P">EX_IMG_PATH"IVEX_zo_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DOWN_P">EX_IMG_PATH"IVEX_cw_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DOWN_P">EX_IMG_PATH"IVEX_ccw_press_wk.png"</IMAGE>
    /* ICON DISABLE state under Vertical screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_P">EX_IMG_PATH"IVEX_zi_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_P">EX_IMG_PATH"IVEX_zo_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_P">EX_IMG_PATH"IVEX_cw_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_P">EX_IMG_PATH"IVEX_ccw_disable_wk.png"</IMAGE>
    /* ICON UP state under Horizon screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_H">EX_IMG_PATH"IVEX_L_zi_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_H">EX_IMG_PATH"IVEX_L_zo_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_H">EX_IMG_PATH"IVEX_L_cw_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_H">EX_IMG_PATH"IVEX_L_ccw_wk.png"</IMAGE>
    /* ICON DOWN state under Horizon screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DOWN_H">EX_IMG_PATH"IVEX_L_zi_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DOWN_H">EX_IMG_PATH"IVEX_L_zo_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DOWN_H">EX_IMG_PATH"IVEX_L_cw_press_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DOWN_H">EX_IMG_PATH"IVEX_L_ccw_press_wk.png"</IMAGE>
    /* ICON DISABLE state under Horizon screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_H">EX_IMG_PATH"IVEX_L_zi_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_H">EX_IMG_PATH"IVEX_L_zo_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_H">EX_IMG_PATH"IVEX_L_cw_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_H">EX_IMG_PATH"IVEX_L_ccw_disable_wk.png"</IMAGE>

#endif /* __MMI_IMGVIEWEX_TOUCH__ */

		/* Softkey for portrait */
    <IMAGE id="IMG_ID_IVEX_LSK_UP_P">EX_IMG_PATH"IVEX_option_P.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_UP_P">EX_IMG_PATH"IVEX_exit_P.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_UP_P">EX_IMG_PATH"IVEX_switch_P.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_UP_P">EX_IMG_PATH"IVEX_slideshow_P.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_UP_P">EX_IMG_PATH"IVEX_slideshow_stop_P.png"</IMAGE>

    <IMAGE id="IMG_ID_IVEX_LSK_DOWN_P">EX_IMG_PATH"IVEX_option_P_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_DOWN_P">EX_IMG_PATH"IVEX_exit_P_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_DOWN_P">EX_IMG_PATH"IVEX_switch_P_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_DOWN_P">EX_IMG_PATH"IVEX_slideshow_P_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_DOWN_P">EX_IMG_PATH"IVEX_slideshow_stop_P_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_DISABLE_P">EX_IMG_PATH"IVEX_slideshow_disable.png"</IMAGE>
		/* Softkey for Horizental */
    <IMAGE id="IMG_ID_IVEX_LSK_UP_H">EX_IMG_PATH"IVEX_option_L.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_UP_H">EX_IMG_PATH"IVEX_exit_L.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_UP_H">EX_IMG_PATH"IVEX_switch_L.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_UP_H">EX_IMG_PATH"IVEX_slideshow_L.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_UP_H">EX_IMG_PATH"IVEX_slideshow_stop_L.png"</IMAGE>

    <IMAGE id="IMG_ID_IVEX_LSK_DOWN_H">EX_IMG_PATH"IVEX_option_L_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_DOWN_H">EX_IMG_PATH"IVEX_exit_L_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_DOWN_H">EX_IMG_PATH"IVEX_switch_L_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_DOWN_H">EX_IMG_PATH"IVEX_slideshow_L_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_DOWN_H">EX_IMG_PATH"IVEX_slideshow_stop_L_press.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_DISABLE_H">EX_IMG_PATH"IVEX_h_slideshow_disable.png"</IMAGE>

    /* transfer effect icon -> number = 14 */
    <IMAGE id="IMG_ID_IVEX_HINT_DRM" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_drm.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_FILE_ERR" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_file_error.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_0" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_01.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_1" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_02.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_2" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_03.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_3" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_04.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_4" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_05.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_5" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_06.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_6" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_07.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_7" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_08.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_8" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_09.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_9" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_10.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_10" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_11.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_11" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_12.png"</IMAGE>

#else	/*__MMI_FTE_SUPPORT__*/
		
		#define MULTIMEDIA_IMG_PATH		CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\"
		
    <IMAGE id="IMG_ID_IVEX_PANEL_SHADOW_P" force_type= ICON_TYPE >EX_IMG_PATH"IVEX_panel_shadow.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_P">EX_IMG_PATH"IVEX_panel_bg.9slice.bmp"</IMAGE>
#ifdef __MMI_FTE_SUPPORT_SLIM__
    <IMAGE id="IMG_ID_IVEX_SK_BG_P">EX_IMG_PATH"BG.9slice.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_IVEX_SK_BG_P">EX_IMG_PATH"BG.9slice.png"</IMAGE>
#endif /*__MMI_FTE_SUPPORT_SLIM__*/

    /* Shadow and background under Horizon screen -> number = 3 */
    <IMAGE id="IMG_ID_IVEX_PANEL_SHADOW_H">EX_IMG_PATH"IVEX_h_panel_shadow.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_PANEL_BG_H">EX_IMG_PATH"IVEX_h_panel_bg.9slice.bmp"</IMAGE>
#ifdef __MMI_FTE_SUPPORT_SLIM__
    <IMAGE id="IMG_ID_IVEX_SK_BG_H">EX_IMG_PATH"h_BG.9slice.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_IVEX_SK_BG_H">EX_IMG_PATH"h_BG.9slice.png"</IMAGE>

#endif

#ifdef __MMI_IMGVIEWEX_TOUCH__
    /* ICON UP state under Vertical screen -> number = 11 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_P">EX_IMG_PATH"IVEX_zi.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_P">EX_IMG_PATH"IVEX_zo.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_P">EX_IMG_PATH"IVEX_cw.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_P">EX_IMG_PATH"IVEX_ccw.png"</IMAGE>
    /* ICON UP state under Horizon screen -> number = 9 */
    /* ICON DISABLE state under P/H screen -> number = 10 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_P">EX_IMG_PATH"IVEX_zi_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_P">EX_IMG_PATH"IVEX_zo_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_P">EX_IMG_PATH"IVEX_cw_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_P">EX_IMG_PATH"IVEX_ccw_disable.png"</IMAGE>

#else	/*__MMI_IMGVIEWEX_TOUCH__*/
    /* ICON UP state under Vertical screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_P">EX_IMG_PATH"IVEX_zi_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_P">EX_IMG_PATH"IVEX_zo_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_P">EX_IMG_PATH"IVEX_cw_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_P">EX_IMG_PATH"IVEX_ccw_wk.png"</IMAGE>
    /* ICON DISABLE state under Vertical screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_P">EX_IMG_PATH"IVEX_zi_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_P">EX_IMG_PATH"IVEX_zo_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_P">EX_IMG_PATH"IVEX_cw_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_P">EX_IMG_PATH"IVEX_ccw_disable_wk.png"</IMAGE>
    /* ICON UP state under Horizon screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_UP_H">EX_IMG_PATH"IVEX_L_zi_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_UP_H">EX_IMG_PATH"IVEX_L_zo_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_UP_H">EX_IMG_PATH"IVEX_L_cw_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_UP_H">EX_IMG_PATH"IVEX_L_ccw_wk.png"</IMAGE>
    /* ICON DISABLE state under Horizon screen (With number) -> number = 4 */
    <IMAGE id="IMG_ID_IVEX_ZOOMIN_DISABLE_H">EX_IMG_PATH"IVEX_L_zi_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_ZOOMOUT_DISABLE_H">EX_IMG_PATH"IVEX_L_zo_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CWR_DISABLE_H">EX_IMG_PATH"IVEX_L_cw_disable_wk.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CCWR_DISABLE_H">EX_IMG_PATH"IVEX_L_ccw_disable_wk.png"</IMAGE>

#endif /* __MMI_IMGVIEWEX_TOUCH__ */

		/* Softkey for portrait */
    <IMAGE id="IMG_ID_IVEX_LSK_UP_P">MULTIMEDIA_IMG_PATH"option.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_UP_P">MULTIMEDIA_IMG_PATH"back.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_UP_P">EX_IMG_PATH"IVEX_switch_P.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_UP_P">EX_IMG_PATH"IVEX_slideshow.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_UP_P">EX_IMG_PATH"IVEX_slideshow_stop.png"</IMAGE>

    <IMAGE id="IMG_ID_IVEX_LSK_DOWN_P">MULTIMEDIA_IMG_PATH"option_down.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_RSK_DOWN_P">MULTIMEDIA_IMG_PATH"back_down.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_DOWN_P">EX_IMG_PATH"IVEX_switch_P_down.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_PLAY_DOWN_P">EX_IMG_PATH"IVEX_slideshow_down.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_STOP_DOWN_P">EX_IMG_PATH"IVEX_slideshow_stop_down.png"</IMAGE>
		/* Softkey for Horizental */
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_UP_H">EX_IMG_PATH"IVEX_switch_L.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_CSK_ROTATE_DOWN_H">EX_IMG_PATH"IVEX_switch_L_down.png"</IMAGE>
		
		/* button bg */
    <IMAGE id="IMG_ID_IVEX_BTN_BG">EX_IMG_PATH"IVEX.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_BTN_BG_DOWN">EX_IMG_PATH"IVEX_down.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_BTN_BG_H">EX_IMG_PATH"IVEX_h.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_BTN_BG_H_DOWN">EX_IMG_PATH"IVEX_h_down.9slice.png"</IMAGE>

    /* transfer effect icon -> number = 14 */
    <IMAGE id="IMG_ID_IVEX_HINT_DRM" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_drm.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_FILE_ERR" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_file_error.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_0" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_01.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_1" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_03.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_2" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_05.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_3" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_07.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_4" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_09.png"</IMAGE>
    <IMAGE id="IMG_ID_IVEX_HINT_LOADING_5" force_type=ICON_TYPE >EX_IMG_PATH"IVEX_hint_load_11.png"</IMAGE>

#endif /*__MMI_FTE_SUPPORT__*/

    /*********************************************
    **                     MENU               **
    **********************************************/
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    <MENU id = "MENU_ID_IMGVIEW_APP" type = "APP_MAIN" str = "STR_ID_IMGVIEW_NAME" img = "IMG_ID_IMGVIEW_MAIN_ICON" highlight = "mmi_imgview_highlight_app" shortcut="ON" shortcut_img="IMG_ID_IMGVIEW_MAIN_ICON" launch="mmi_imgview_launch"/>
#if (defined(__MMI_MAINLCD_240X400__) && defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
    <MENU id = "MAIN_MENU_OPTION_IMGVIEW_APP" type = "APP_MAIN" str = "STR_ID_IMGVIEW_NAME" img = "MAIN_MENU_IMGVIEW_ICON" highlight = "mmi_imgview_highlight_app"/>
#endif

    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_DETAIL" str = "STR_GLOBAL_VIEW" highlight = "mmi_imgview_highlight_view_detail"/>
#if defined(__MMI_PHOTOEDITOR__)
    <MENUITEM id = "MENU_ID_IMGVIEW_ENTRY_PHOTOEDITOR" str = "STR_GLOBAL_EDIT" highlight = "mmi_imgview_highlight_entry_photoeditor"/>
#endif
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_STYLE_LIST" str = "STR_ID_IMGVIEW_VIEW_STYLE_LIST"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX" str = "STR_ID_IMGVIEW_VIEW_STYLE_MATRIX"/>
    <MENU id = "MENU_ID_IMGVIEW_VIEW_STYLE" str = "STR_ID_IMGVIEW_VIEW_STYLE" hint = "mmi_imgview_hint_view_style">
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX</MENUITEM_ID>
    </MENU>
#ifdef __FS_CARD_SUPPORT__
    <MENUITEM id = "MENU_ID_IMGVIEW_STORAGE" str = "STR_GLOBAL_STORAGE" hint = "mmi_imgview_hint_set_storage"/>
#endif
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_PLAY" str = "STR_GLOBAL_PLAY"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_USE" str = "STR_GLOBAL_USE_AS"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_SEND" str = "STR_GLOBAL_SEND"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_PRINT" str = "STR_GLOBAL_PRINT"/>
#if defined(__MMI_PHOTOEDITOR__)
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_EDITOR" str = "STR_GLOBAL_EDIT"/>
#endif
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_INFO" str = "STR_ID_IMGVIEW_OPTION_IMG_INFO"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_SETTINGS" str = "STR_GLOBAL_SETTINGS"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_VIEW_OPTION_HELP" str = "STR_GLOBAL_HELP"/>

    <!-- For fmgr option menu -->
    <MENUITEM id = "MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION" parent = "MENU_ID_IMGVIEW_APP" str = "STR_ID_IMGVIEW_OPTION_IMG_INFO"/>
    <MENUITEM id = "MENU_ID_IMGVIEW_OPTION_IMG_VIEW" parent = "MENU_ID_IMGVIEW_APP" str = "STR_GLOBAL_VIEW"/>
    <!-- For fmgr option->send menu -->
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <MENUITEM id = "MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD" str = "STR_ID_IMGVIEW_OPTION_SEND_TO_SNS"/>    
#endif

    <MENU id = "MENU_ID_IMGVIEW_FILE_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" img = "IMG_ID_IMGVIEW_MAIN_ICON">
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_ENTRY_SLIDESHOW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_ENTRY_PHOTOEDITOR</MENUITEM_ID>
    #if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
        <MENUITEM_ID>@OID:MENU_ID_FMGR_IMG_OPTION_PRINT</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
        <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_STORAGE</MENUITEM_ID>
    </MENU>
    <MENU id = "MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" img = "IMG_ID_IMGVIEW_MAIN_ICON">
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_STORAGE</MENUITEM_ID>
    </MENU>
    <MENU id = "MENU_ID_MEDIAVIEW_FILE_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" img = "IMG_ID_IMGVIEW_MAIN_ICON">
        <MENUITEM_ID>@OID:MENU_ID_FMGR_FOLDER_OPEN</MENUITEM_ID>
        <MENUITEM_ID default = "TRUE">MENU_ID_IMGVIEW_VIEW_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_ENTRY_SLIDESHOW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_ENTRY_PHOTOEDITOR</MENUITEM_ID>
    #if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
        <MENUITEM_ID>@OID:MENU_ID_FMGR_IMG_OPTION_PRINT</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
        <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_MEDIAVIEW_EMPTY_FOLDER_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" img = "IMG_ID_IMGVIEW_MAIN_ICON">
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_STYLE</MENUITEM_ID>
    </MENU>

    <MENU id = "MENU_ID_IMGVIEW_VIEW_OPTION" type = "OPTION"
        str = "STR_GLOBAL_OPTIONS" img = "IMG_ID_IMGVIEW_MAIN_ICON">
    #if defined(__MMI_RMGR__)
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_USE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_SEND</MENUITEM_ID>
    #if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
        <MENUITEM_ID>@OID:MENU_ID_FMGR_IMG_OPTION_PRINT</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_EDITOR</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_INFO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_SETTINGS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMGVIEW_VIEW_OPTION_HELP</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Screen ID Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_IMGVIEW_VIEW"/>
    <SCREEN id="SCR_ID_IMGVIEW_OPTION"/>
    <SCREEN id="SCR_ID_IMGVIEW_OPTION_SEND"/>
    <SCREEN id="SCR_ID_IMGVIEW_OPTION_USE"/>
    <SCREEN id="SCR_ID_IMGVIEW_APP"/>
    <SCREEN id="SCR_ID_IMGVIEW_STORAGE"/>
    <SCREEN id="SCR_ID_IMGVIEW_SORTING"/>
    <SCREEN id="SCR_ID_IMGVIEW_HELP"/>
    <SCREEN id="SCR_ID_IMGVIEW_INFO"/>
    <SCREEN id="SCR_ID_IMGVIEW_SETTINGS"/>
    <SCREEN id="SCR_ID_IMGVIEW_DRM_GET_RIGHT"/>
    <SCREEN id="SCR_ID_IMGVIEW_VIEW_STYLE"/>
    <SCREEN id="SCR_ID_IMGVIEW_FOR_OTHER_APP"/>
    <SCREEN id="SCR_ID_IMGVIEW_FROM_FMGR"/>
    <SCREEN id="SCR_ID_IMGVIEW_CONFIRM_PRINT_SCREEN"/>
    <SCREEN id="SCR_ID_IMGVIEW_VIEW_EXT"/>
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
    <FILE_OPTION_HDLR option="MENU_ID_MEDIAVIEW_FILE_OPTION" enabler="mmi_fmgr_option_mediaview_enabler"/>
#ifdef __MMI_SNS_PHOTO_UPLOAD__
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD" enabler="mmi_imgview_sns_photo_upload_enabler" handler="mmi_imgview_sns_photo_upload_handler"/>
#endif
</FILE_TYPES>

<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_imgview_fmgr_notify_hdlr"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_imgview_fmgr_notify_hdlr"/>

#endif /*__MMI_IMAGE_VIEWER__*/


