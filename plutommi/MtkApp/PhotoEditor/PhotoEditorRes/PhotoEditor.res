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
/*****************************************************************************
*
* Filename:
* ---------
*  PhotoEditor.res
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  PhotoEditor resource population file
*
* Author:
* -------
*  Wenyan Yang (MTK80495)
*                      
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 06 11 2012 wenyan.yang
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 03 23 2012 wenyan.yang
 * [MAUI_03146841] [Performance]_Gallery  photoArt _FTE_feature_performance test fail for victor56v12(HVGA)
 * .
 *
 * 02 24 2012 wenyan.yang
 * [MAUI_03119322] FTE2.0 photo editor check in
 * .
 *
 * 02 21 2012 wenyan.yang
 * [MAUI_03119322] FTE2.0 photo editor check in
 * .
 *
 * 01 18 2012 wenyan.yang
 * [MAUI_03119322] FTE2.0 photo editor check in
 * .
 *
 * 09 14 2011 wenyan.yang
 * [MAUI_03026279] Patch from CBR of ch.ko
 * .
 *
 * 05 10 2011 wenyan.yang
 * [MAUI_02933789] [Phase out old version]phase out old version of photo editor
 * .
 *
 * 05 06 2011 wenyan.yang
 * [MAUI_02932417] [Daily build error]
 * .
 *
 * 02 18 2011 wenyan.yang
 * [MAUI_02870325] Scalado check in 11A and MAUI [MBJ]
 * MAUI SCALADO CHECK IN
 *
 * 11 18 2010 wenyan.yang
 * [MAUI_02641352] [NVRAM Cache Migrate] from /nvram_mgr.res to APP.res----Imageviewer & Imagetiles
 * .
 *
 * 08 04 2010 wenyan.yang
 * [MAUI_02306568] [TCD-MDED-REQ-001338,  TCD-MDED-REQ-001336]test case failed
 * .
 *
 * Jun 12 2010 mtk80495
 * [MAUI_02209864] [10A Photo Editor]group id enum name is wrong(should be "GRP_" not "GPR_")
 * 
 *
 * Jun 11 2010 mtk80495
 * [MAUI_02208985] [10A Photo Editor]FmgrServiceHandler is moved to APP
 * 
 *
 * Jun 4 2010 mtk80495
 * [MAUI_02205569] [10A Photo editor]check in known issue(Image tile compile option)
 * 
 *
 * Apr 29 2010 mtk80495
 * [MAUI_02186666] [Photo Editor 10A]reentry cui will assert
 * 
 *
 * Apr 20 2010 mtk80495
 * [MAUI_02399634] [LGE TD SFT 96]it doesn't show the icon's image in Photo editor
 * 
 *
 * Apr 13 2010 mtk80495
 * [MAUI_02178638] [Photo Editor]Fix build error
 * 
 *
 * Apr 7 2010 mtk80495
 * [MAUI_02176961] [Photo Editor]10A check in
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"
#include "drv_features.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef DEVELOPER_BUILD_FIRST_PASS
#ifdef __MMI_PHOTOEDITOR__

#ifdef __MMI_FTE_SUPPORT__
#define __MMI_PHOEDT_STYLE_FTE__
#ifdef __MMI_TOUCH_SCREEN__
#define __MMI_PHOEDT_STYLE_FTE_CLIP__
#endif
#endif

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define  PHOEDT_PNG_OUTPUT_TYPE   "FORCE_ABM"
#else
#define  PHOEDT_PNG_OUTPUT_TYPE   "FORCE_AB2"
#endif

<APP id="APP_PHOEDT"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.photoeditor"         /* Use "native.mtk." as the prefix of application name */
    name = "STR_ID_PHOEDT_APP_NAME"                 /* The string to be displayed under the main menu icon */
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)   //MM_ICON
    img = "IMG_ID_PHOEDT_VUI_MAIN_MENU_APP_ICON"    /* Main menu icon image */
    #endif /* #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) */
    launch = "mmi_phoedt_launch"                    /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                     * the function prototype should be:
                                                     *
                                                     *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                     *
                                                     * Note that the group_id of the application should be returned if launch successfully.
                                                     * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif /* defined(__MMI_APP_MANAGER_SUPPORT__) */
>

<INCLUDE file="GlobalResDef.h"/>
<INCLUDE file="CustomCfg.h"/>
#ifdef FIRST_PASS
<INCLUDE file="BuildCfg.h"/>
#endif

/* String resource area */
    <STRING id="STR_ID_PHOEDT_APP_NAME"/>
    <STRING id="STR_ID_PHOEDT_SELECT_FROM_FILE"/>
#ifdef __MMI_CAMERA__
    <STRING id="STR_ID_PHOEDT_CAPTURE_CAMERA"/>
#endif /* __MMI_CAMERA__ */
    <STRING id="STR_ID_PHOEDT_ADD_EFFECT"/>
    <STRING id="STR_ID_PHOEDT_ADJUST"/>
    <STRING id="STR_ID_PHOEDT_ADD_ICON"/>
    <STRING id="STR_ID_PHOEDT_ROTATE"/>
    <STRING id="STR_ID_PHOEDT_FLIP"/>
#ifdef __MMI_TOUCH_SCREEN__
    <STRING id="STR_ID_PHOEDT_DOODLE"/>
    <STRING id="STR_ID_PHOEDT_DOODLE_COLOR"/>
#endif /* __MMI_TOUCH_SCREEN__ */
    <STRING id="STR_ID_PHOEDT_UNDO"/>


    /* frame */
    <STRING id="STR_ID_PHOEDT_ADD_FRAME"/>
    <STRING id="STR_ID_PHOEDT_FRAME_START"/>
    <STRING id="STR_ID_PHOEDT_FRAME_1"/>
    <STRING id="STR_ID_PHOEDT_FRAME_2"/>
    <STRING id="STR_ID_PHOEDT_FRAME_3"/>
    <STRING id="STR_ID_PHOEDT_FRAME_4"/>
    <STRING id="STR_ID_PHOEDT_FRAME_5"/>
    <STRING id="STR_ID_PHOEDT_FRAME_6"/>
    <STRING id="STR_ID_PHOEDT_FRAME_7"/>
    <STRING id="STR_ID_PHOEDT_FRAME_8"/>
    <STRING id="STR_ID_PHOEDT_FRAME_9"/>
    <STRING id="STR_ID_PHOEDT_FRAME_10"/>
    <STRING id="STR_ID_PHOEDT_FRAME_11"/>
    <STRING id="STR_ID_PHOEDT_FRAME_12"/>


    /* help info */
    <STRING id="STR_ID_PHOEDT_HELP_SEND_INFO"/>
    <STRING id="STR_ID_PHOEDT_HELP_SAVE_INFO"/>
    <STRING id="STR_ID_PHOEDT_HELP_EFFECT_INFO"/>
    <STRING id="STR_ID_PHOEDT_HELP_FRAME_INFO"/>
    <STRING id="STR_ID_PHOEDT_HELP_ICON_INFO"/>
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    <STRING id="STR_ID_PHOEDT_HELP_CLIP_INFO_FTE"/>
#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
    <STRING id="STR_ID_PHOEDT_HELP_CLIP_INFO"/>
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_PHOEDT_STYLE_FTE__
    <STRING id="STR_ID_PHOEDT_HELP_DOODLE_INFO_FTE"/>
#else /* __MMI_PHOEDT_STYLE_FTE__ */
    <STRING id="STR_ID_PHOEDT_HELP_DOODLE_INFO"/>
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_TOUCH_SCREEN__ */


    /* notify */
    <STRING id="STR_ID_PHOEDT_NOTIFY_UNLOCK_MEMORY_CARD"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_EXIT_CONFIRM"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_IMAGE_TOO_WIDE"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_UNFIT_FOR_EDIT"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_UNDO"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_CANNOT_UNDO"/>
    <STRING id="STR_ID_PHOEDT_NOTIFY_UNSAVE_SEND"/>
    <STRING id="STR_ID_PHOEDT_EXTERNAL_EXIT"/>
    <STRING id="STR_ID_PHOEDT_EXTERNAL_EXIT_SAVE_PRE"/>


    /* save */
    <STRING id="STR_ID_PHOEDT_EDIT_FILENAME"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_OTHER_SIZE"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_1280X960"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_960X1280"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_640X480"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_480X640"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_320X240"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_240X320"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_176X146"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_146X176"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_160X120"/>
    <STRING id="STR_ID_PHOEDT_SAVE_AS_FIT_120X160"/>


    /* clip */
    <STRING id="STR_ID_PHOEDT_CLIP"/>
    <STRING id="STR_ID_PHOEDT_MAINLCD_CLIP"/>
#ifdef __MMI_SUBLCD__
    <STRING id="STR_ID_PHOEDT_SUBLCD_CLIP"/>
#endif
    <STRING id="STR_ID_PHOEDT_MANUAL_CLIP"/>
    <STRING id="STR_ID_PHOEDT_CLIP_ORIGINAL_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_16TO9_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_9TO16_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_4TO3_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_3TO4_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_3TO2_RATIO"/>
    <STRING id="STR_ID_PHOEDT_CLIP_2TO3_RATIO"/>


    /* misc */
    <STRING id="STR_ID_PHOEDT_TITLE_PREFIX"/>
    <STRING id="STR_ID_PHOEDT_TITLE_SUFFIX"/>

/* img resource area */
    <IMAGE id="IMG_ID_PHOEDT_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SB_PhotoEditor.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_APP_PROCESS">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\loading.gif"</IMAGE>
#if defined(__MMI_APP_MANAGER_SUPPORT__) && (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
    <IMAGE id="IMG_ID_PHOEDT_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\PhotoEditor.png"</IMAGE>
#endif /* #if defined(__MMI_APP_MANAGER_SUPPORT__) && (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) */
    /* Used for matrix select doodle color */
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_COLOR_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_col.bmp"</IMAGE>


#ifdef __MMI_PHOEDT_STYLE_FTE__
    <IMAGE id="IMG_ID_PHOEDT_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_drawer_bg.9slice.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_BTN_HL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_LEFT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_arrow_l.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_RIGHT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_arrow_r.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_LEFT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_rotate_l.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_RIGHT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_rotate_r.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_UP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_zoom_in.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_UP_ICON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_zoom_in_d.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_DOWN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_zoom_out.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_DOWN_ICON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_zoom_out_d.png"</IMAGE>


    /* doodle */
#ifdef __MMI_TOUCH_SCREEN__ 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_HL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_hl.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_UP">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_drawer_indicator.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_drawer_indicator2.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_LINE_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_brush.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_LINE_1">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_brush_3.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_LINE_2">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_brush_2.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_LINE_3">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_brush_1.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_COLOR">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_color_picker.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_ERASER_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_eraser.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_ERASER_1">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_eraser_3.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_ERASER_2">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_eraser_2.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_DOODLE_ERASER_3">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\doodle_eraser_1.png"</IMAGE> 
#endif /* __MMI_TOUCH_SCREEN__ */


    /* clip */
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    <IMAGE id="IMG_ID_PHOEDT_CLIP_MASK">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip_mask.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_CLIP_FRAME">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\crop_frame.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_CLIP_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_ball_n.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_CLIP_INDICATOR_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_ball_hl.png"</IMAGE>
#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_LEFTUP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_crop_lt.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_RIGHTDOWN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_crop_rd.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_MOVE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_crop.png"</IMAGE> 
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


    /* flip */
    <IMAGE id="IMG_ID_PHOEDT_FLIP_VER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_flip_v.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FLIP_HOR_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\btn_flip_h.png"</IMAGE>


    /* adjust */
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SLIDER_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_ball_hl.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SLIDER">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_ball_n.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BAR">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_bar.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_bar_bg.9slice.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BAR_HL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adjust_hl.9slice.png"</IMAGE> 
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BRIGHTNESS">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adj_brightness.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_CONTRAST">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adj_contrast.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SHARPNESS">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adj_sharpness.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_HUE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adj_hue.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SATURATION">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\adj_saturation.png"</IMAGE>


#else /* __MMI_PHOEDT_STYLE_FTE__ */
    <IMAGE id="IMG_ID_PHOEDT_LEFT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_left_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_LEFT_ARROW_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_left_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_RIGHT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_right_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_RIGHT_ARROW_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_right_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_LEFT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_rotate_left.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_LEFT_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_rotate_left_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_RIGHT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_rotate_right.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ROTATE_RIGHT_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_rotate_right_sel.bmp"</IMAGE>


    /* doodle */
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_PHOEDT_HIDE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_hide.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_HIDE_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_hide_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_LINE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_line1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ERASER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_eraser.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_SMALL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_line1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_NORMAL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_line2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_LARGE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_line3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_ERASER_SMALL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_eraser1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_ERASER_NORMAL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_eraser2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SIZE_ERASER_LARGE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_doodle_eraser3.bmp"</IMAGE>
#endif /* __MMI_TOUCH_SCREEN__ */


    /* clip */
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_LEFTUP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_LEFTUP_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip2_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_RIGHTDOWN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_RIGHTDOWN_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip3_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_MOVE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_MANUAL_CLIP_MOVE_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_clip1_sel.bmp"</IMAGE>


    /* scale up and down icon */
    <IMAGE id="IMG_ID_PHOEDT_SCALE_UP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_UP_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_up_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_UP_ICON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_up_disable.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_DOWN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_DOWN_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_down_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_SCALE_DOWN_ICON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_down_disable.bmp"</IMAGE>


    /* flip */
    <IMAGE id="IMG_ID_PHOEDT_FLIP_VER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_ver.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FLIP_VER_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_ver_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FLIP_HOR_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_hor.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FLIP_HOR_ICON_SEL">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_hor_sel.bmp"</IMAGE>


    /* adjust */
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SLIDER">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_slider.gif"</IMAGE>
    /* this will be drawn on osd layer(16 bit), so not need to set force_type */
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BAR">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bar.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BRIGHTNESS">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bright.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_BRIGHTNESS_HILIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bright_h.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_CONTRAST">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_contrast.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_CONTRAST_HILIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_contrast_h.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SHARPNESS">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_sharpness.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SHARPNESS_HILIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_sharpness_h.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_HUE">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_hue.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_HUE_HILIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_hue_h.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SATURATION">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_saturation.gif"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ADJUST_SATURATION_HILIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_saturation_h.gif"</IMAGE>
#endif /* __MMI_PHOEDT_STYLE_FTE__ */


    /* frames */
    <IMAGE id="IMG_ID_PHOEDT_FRAME_START">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_00.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_1">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_01.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_2">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_02.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_3">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_03.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_4">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_04.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_5">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_05.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_6">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_06.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_7">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_07.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_8">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_08.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_9">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_09.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_10">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_10.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_11">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_11.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_12">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_12.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_FRAME_END">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_frame_00.png"</IMAGE>


    /* lovely icons */
    <IMAGE id="IMG_ID_PHOEDT_ICON_START">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_00.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_1">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_01_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_2">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_02_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_3">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_03_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_4">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_04_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_5">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_05_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_6">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_06_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_7">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_07_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_8">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_08_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_9">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_09_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_10">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_10_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_11">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_11_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_12">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_12_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_13">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_13_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_14">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_14_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_15">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_15_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_16">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_16_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_17">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_17_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_18">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_18_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_19">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses01_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_20">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses02_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_21">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses03_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_22">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair01.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_23">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair02.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_24">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair03.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_25">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat01.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_26">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat02.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_27">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat03.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_28">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache01.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_29">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache02_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_30">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache03_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_31">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows01_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_32">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows01_R.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_33">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows02_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_34">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows02_R.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_35">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows03_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_36">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows03_R.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_37">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows04_L.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_38">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows04_R.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_END">CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_00.png"</IMAGE>


    /* Bellow small icons are used to draw matrix selector screen */
    <IMAGE id="IMG_ID_PHOEDT_ICON_1_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_01_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_2_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_02_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_3_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_03_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_4_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_04_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_5_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_05_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_6_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_06_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_7_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_07_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_8_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_08_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_9_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_09_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_10_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_10_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_11_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_11_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_12_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_12_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_13_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_13_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_14_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_14_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_15_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_15_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_16_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_16_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_17_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_17_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_18_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_18_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_19_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses01_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_20_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses02_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_21_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Glasses03_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_22_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair01_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_23_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair02_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_24_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hair03_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_25_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat01_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_26_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat02_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_27_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_Hat03_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_28_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache01_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_29_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache02_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_30_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_mustache03_S.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_31_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows01_L3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_32_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows01_R3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_33_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows02_L3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_34_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows02_R3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_35_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows03_L3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_36_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows03_R3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_37_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows04_L3.png"</IMAGE>
    <IMAGE id="IMG_ID_PHOEDT_ICON_38_SMALL" force_type=PHOEDT_PNG_OUTPUT_TYPE>CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_brows04_R3.png"</IMAGE>


/* Menu-item resource area */
    <MENUITEM id="MENU_ID_PHOEDT_APP" str="STR_ID_PHOEDT_APP_NAME" img="IMG_ID_PHOEDT_APP_ICON"
    highlight="mmi_phoedt_hilight_app" shortcut="ON" shortcut_img="IMG_ID_PHOEDT_APP_ICON" launch="mmi_phoedt_launch"/>


    /* select file options */
    <MENUITEM id="MENU_ID_PHOEDT_SELECT_FROM_FILE" str="STR_ID_PHOEDT_SELECT_FROM_FILE"/>
#ifdef __MMI_CAMERA__
    <MENUITEM id="MENU_ID_PHOEDT_CAPTURE_CAMARA" str="STR_ID_PHOEDT_CAPTURE_CAMERA"/>
#endif /* __MMI_CAMERA__ */


    /* main options */
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS" str="STR_ID_PHOEDT_SAVE_AS"/>
    <MENUITEM id="MENU_ID_PHOEDT_SEND" str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_PHOEDT_ADD_EFFECT" str="STR_ID_PHOEDT_ADD_EFFECT"/>
    <MENUITEM id="MENU_ID_PHOEDT_ADJUST" str="STR_ID_PHOEDT_ADJUST"/>
    <MENUITEM id="MENU_ID_PHOEDT_ADD_FRAME" str="STR_ID_PHOEDT_ADD_FRAME"/>
    <MENUITEM id="MENU_ID_PHOEDT_ADD_ICON" str="STR_ID_PHOEDT_ADD_ICON"/>
    <MENUITEM id="MENU_ID_PHOEDT_ROTATE" str="STR_ID_PHOEDT_ROTATE"/>
    <MENUITEM id="MENU_ID_PHOEDT_FLIP" str="STR_ID_PHOEDT_FLIP"/>
#ifdef __MMI_TOUCH_SCREEN__
    <MENUITEM id="MENU_ID_PHOEDT_DOODLE" str="STR_ID_PHOEDT_DOODLE"/>
#endif
    <MENUITEM id="MENU_ID_PHOEDT_UNDO" str="STR_ID_PHOEDT_UNDO"/>
    <MENUITEM id="MENU_ID_PHOEDT_HELP" str="STR_GLOBAL_HELP"/>


    /* frames */
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_1" str="STR_ID_PHOEDT_FRAME_1"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_2" str="STR_ID_PHOEDT_FRAME_2"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_3" str="STR_ID_PHOEDT_FRAME_3"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_4" str="STR_ID_PHOEDT_FRAME_4"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_5" str="STR_ID_PHOEDT_FRAME_5"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_6" str="STR_ID_PHOEDT_FRAME_6"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_7" str="STR_ID_PHOEDT_FRAME_7"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_8" str="STR_ID_PHOEDT_FRAME_8"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_9" str="STR_ID_PHOEDT_FRAME_9"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_10" str="STR_ID_PHOEDT_FRAME_10"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_11" str="STR_ID_PHOEDT_FRAME_11"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_12" str="STR_ID_PHOEDT_FRAME_12"/>


    /* clip */
    <MENUITEM id="MENU_ID_PHOEDT_MAINLCD_CLIP" str="STR_ID_PHOEDT_MAINLCD_CLIP"/>
#ifdef __MMI_SUBLCD__
    <MENUITEM id="MENU_ID_PHOEDT_SUBLCD_CLIP" str="STR_ID_PHOEDT_SUBLCD_CLIP"/>
#endif /* __MMI_SUBLCD__ */
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_ORIGINAL_RATIO" str="STR_ID_PHOEDT_CLIP_ORIGINAL_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_16TO9_RATIO" str="STR_ID_PHOEDT_CLIP_16TO9_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_9TO16_RATIO" str="STR_ID_PHOEDT_CLIP_9TO16_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_4TO3_RATIO" str="STR_ID_PHOEDT_CLIP_4TO3_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_3TO4_RATIO" str="STR_ID_PHOEDT_CLIP_3TO4_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_3TO2_RATIO" str="STR_ID_PHOEDT_CLIP_3TO2_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_2TO3_RATIO" str="STR_ID_PHOEDT_CLIP_2TO3_RATIO"/>
    <MENUITEM id="MENU_ID_PHOEDT_MANUAL_CLIP" str="STR_ID_PHOEDT_MANUAL_CLIP"/>


    /* save */
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_1280X960" str="STR_ID_PHOEDT_SAVE_AS_FIT_1280X960"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_960X1280" str="STR_ID_PHOEDT_SAVE_AS_FIT_960X1280"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_640X480" str="STR_ID_PHOEDT_SAVE_AS_FIT_640X480"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_480X640" str="STR_ID_PHOEDT_SAVE_AS_FIT_480X640"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_320X240" str="STR_ID_PHOEDT_SAVE_AS_FIT_320X240"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_240X320" str="STR_ID_PHOEDT_SAVE_AS_FIT_240X320"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_176X146" str="STR_ID_PHOEDT_SAVE_AS_FIT_176X146"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_146X176" str="STR_ID_PHOEDT_SAVE_AS_FIT_146X176"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_160X120" str="STR_ID_PHOEDT_SAVE_AS_FIT_160X120"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_AS_FIT_120X160" str="STR_ID_PHOEDT_SAVE_AS_FIT_120X160"/>


    /* help */
    <MENUITEM id="MENU_ID_PHOEDT_ICON_HELP" str="STR_ID_PHOEDT_ADD_ICON"/>
    <MENUITEM id="MENU_ID_PHOEDT_CLIP_HELP" str="STR_ID_PHOEDT_CLIP"/>
    <MENUITEM id="MENU_ID_PHOEDT_SAVE_HELP" str="STR_ID_PHOEDT_SAVE_AS"/>
    <MENUITEM id="MENU_ID_PHOEDT_EFFECT_HELP" str="STR_ID_PHOEDT_ADD_EFFECT"/>
    <MENUITEM id="MENU_ID_PHOEDT_FRAME_HELP" str="STR_ID_PHOEDT_ADD_FRAME"/>
#ifdef __MMI_TOUCH_SCREEN__
    <MENUITEM id="MENU_ID_PHOEDT_DOODLE_HELP" str="STR_ID_PHOEDT_DOODLE"/>
#endif
    <MENUITEM id="MENU_ID_PHOEDT_SEND_HELP" str="STR_GLOBAL_SEND"/>


    /* For fmgr option menu */
    <MENUITEM id="MENU_ID_FMGR_IMG_OPTION_EDIT" str="STR_GLOBAL_EDIT"/>


/* Menu-tree resource area */
    <MENU id="MENU_ID_PHOEDT_SELECT_FILE_OPTION" type="APP_MAIN" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_PHOEDT_SELECT_FROM_FILE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CAPTURE_CAMARA</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_PHOEDT_SAVE_AS_OTHER_SIZE" type="OPTION" str="STR_ID_PHOEDT_SAVE_AS_OTHER_SIZE">
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_1280X960</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_960X1280</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_640X480</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_480X640</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_320X240</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_240X320</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_176X146</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_146X176</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_160X120</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_FIT_120X160</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_PHOEDT_CLIP" type="OPTION" str="STR_ID_PHOEDT_CLIP">
                    <MENUITEM_ID>MENU_ID_PHOEDT_MAINLCD_CLIP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SUBLCD_CLIP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_ORIGINAL_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_16TO9_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_9TO16_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_4TO3_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_3TO4_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_3TO2_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP_2TO3_RATIO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_MANUAL_CLIP</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_PHOEDT_ADD_FRAME_LIST" type="APP_MAIN" str="STR_ID_PHOEDT_ADD_FRAME">
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_1</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_2</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_3</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_4</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_5</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_6</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_7</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_8</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_9</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_10</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_11</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_12</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_PHOEDT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_AS_OTHER_SIZE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SEND</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ADD_EFFECT</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ADD_FRAME</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ADD_ICON</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ADJUST</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ROTATE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_CLIP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_DOODLE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_UNDO</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_HELP</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_PHOEDT_HELP_LIST" type="APP_MAIN" str="STR_GLOBAL_HELP">
                    <MENUITEM_ID>MENU_ID_PHOEDT_SAVE_HELP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_EFFECT_HELP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_FRAME_HELP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_ICON_HELP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_DOODLE_HELP</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_PHOEDT_SEND_HELP</MENUITEM_ID>
    </MENU>

/* Screen resource area */
    /* Photo editor group */
    <SCREEN id="GRP_ID_PHOEDT_GROUP"/>
    <SCREEN id="GRP_ID_PHOEDT_PRE_POPUP_GROUP"/>
    <SCREEN id="GRP_ID_PHOEDT_BEFORE_EDIT_GROUP"/>
    <SCREEN id="GRP_ID_PHOEDT_EDIT_GROUP"/>
    <SCREEN id="GRP_ID_PHOEDT_AFTER_EDIT_GROUP"/>
    <SCREEN id="GRP_ID_PHOEDT_GROUP_END"/>

    /* Photo editor screen */
    <SCREEN id="SCR_ID_PHOEDT_START"/>
    <SCREEN id="SCR_ID_PHOEDT_MAIN"/>
    <SCREEN id="SCR_ID_PHOEDT_EDIT"/>
    <SCREEN id="SCR_ID_PHOEDT_SAVING"/>
    <SCREEN id="SCR_ID_PHOEDT_FRAME_SELECT"/>
    <SCREEN id="SCR_ID_PHOEDT_ICON_SELECT"/>
    <SCREEN id="SCR_ID_PHOEDT_DOODLE_COLOR_SELECT"/>
    <SCREEN id="SCR_ID_PHOEDT_VIEW_IMAGE"/>
    <SCREEN id="SCR_ID_PHOEDT_HELP"/>
    <SCREEN id="SCR_ID_PHOEDT_END"/>
</APP>

<FILE_TYPES>
    <FILE_TYPE_INC file="mmi_rp_app_phoedt_def.h"/>
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_IMG_OPTION_EDIT" enabler="mmi_phoedt_file_type_enabler" handler="mmi_phoedt_file_type_handler"/>
</FILE_TYPES>

#endif /* __MMI_PHOTOEDITOR__ */
#endif /* DEVELOPER_BUILD_FIRST_PASS */

