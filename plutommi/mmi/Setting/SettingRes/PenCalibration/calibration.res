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
 * PhoneSeetting.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Calibration resource file with XML format.   
 *
 * Author:
 * -------
 *   Lina Yuan
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
 * 05 14 2012 xiangnan.qi
 * [MAUI_03140833] FTE 2.0 phase out theme wallpaper setting.
 * .roll back calbration muti touch
 *
 * 05 11 2012 xiangnan.qi
 * [MAUI_03100025] Setting_nitz&restore revise check-in code
 * .calibration cowork. add option __TOUCH_PANEL_MULTITOUCH__
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 01 14 2011 cong.zhou
 * [MAUI_02648392] Disable pen calibration when __TOUCH_PANEL_CAPACITY__ is turned on
 * .
 *
 * 12 03 2010 cong.zhou
 * [MAUI_02642758] [Setting] Add pen calibration to avoid sanity test error
 * .
 *
 * 12 03 2010 cong.zhou
 * [MAUI_02642758] [Setting] Add pen calibration to avoid sanity test error
 * .
 *
 * Apr 14 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_CALIBRATION">

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "STR_CALIBRATION_SETTING"/>
    <STRING id = "STR_CALIBRATION_WELCOME_TEXT"/>
    <!-- do not change the order of these three strings -->
    <STRING id = "STR_CALIBRATION_TOP_LEFT_TEXT"/>
    <STRING id = "STR_CALIBRATION_BOTTOM_RIGHT_TEXT"/>
    <STRING id = "STR_CALIBRATION_CENTER_TEXT"/>
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */
    
    <!-- image ------------------------------------------------------------------------------------>
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    <IMAGE id = "IMG_CALIBRATION_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_PCA.bmp"</IMAGE>
    <IMAGE id = "IMG_CALIBRATION_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Calibration\\\\CALI_SMALL.gif"</IMAGE>
    <IMAGE id = "IMG_CALIBRAION_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Calibration\\\\CALI_SMALL.gif"</IMAGE>
    <IMAGE id = "IMG_CALIBRATION_CENTER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Calibration\\\\CALI_CENTER.gif"</IMAGE>


#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 


    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_CALIBRATION_SETTING"/>

    <!-- group ----------------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_PHNSET_CALIBRATION"/>    

    <!-- menu ------------------------------------------------------------------------------------->
#if (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)) && !defined(__TOUCH_PANEL_CAPACITY__)
    <MENU id = "MENU_SETTING_CALIBRATION" type = "APP_MAIN" str = "STR_CALIBRATION_SETTING" img = "IMG_CALIBRATION_MENU_ICON" highlight = "HighlightCalibrationSetting">
    </MENU>
    
#endif /* __MMI_TOUCH_SCREEN__ */


</APP>


