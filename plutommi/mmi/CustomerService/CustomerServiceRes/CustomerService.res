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
 * version.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Setting version resource file with XML format.
 *
 * Author:
 * -------
 *   Jia Liu
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
 * 04 06 2012 guoyi.zhao
 * [MAUI_03160247] No need to have the menu Connectivity in Settings
 * .
 *
 * 03 26 2012 jiaowei.li
 * [MAUI_03155822] CMCC TD key launcher homescreen and mainmenu check in
 * modify feature resource App Tag attribute with key launcher function.
 *
 * 09 26 2011 jiaowei.li
 * [MAUI_03036813] SIM Recovery Enhancement check-in
 * .Simcard Recovery Add Event ID Process.
 *
 * 05 03 2011 jia.liu
 * [MAUI_02929098] [Need Patch][Build Error] MAUI.W11.19 build error for MT6253D_EVB_gprs(SIM_HOT_SWAP_GEMINI)
 * .
 *
 * 04 26 2011 jia.liu
 * [MAUI_02922314] SIM Hot Swap Check in
 * .
 *
 * 11 05 2010 jia.liu
 * [MAUI_02639644] [Case fail] “设置”菜单中没有“版本”菜单
 * .
 *
 * Jun 23 2010 mtk80517
 * [MAUI_02213846] No Browser but MMS Support
 * 
 *
 * Jun 2 2010 mtk80517
 * [MAUI_02291972] go to wrong screen when click CSK icon
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_CUSTOMER_SERVICE"
	 #if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
	 package_name="native.mtk.customerservice" 
     name ="STR_ID_CUSTSER_TITLE" 
     img = "IMG_ID_KEY_LAUNCH_CS_APP_ICON"
     launch="mmi_custser_launch"
     #endif
>

#ifdef __MMI_CUSTOMER_SERVICE__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_CUSTSER_TITLE"/>
    <STRING id="STR_ID_CUSTSER_GUIDELINE"/>
    <STRING id="STR_ID_CUSTSER_GUIDELINE_CONTENT"/>
    <STRING id="STR_ID_CUSTSER_SALE"/>
    <STRING id="STR_ID_CUSTSER_SMS_SALE"/>
    <STRING id="STR_ID_CUSTSER_HOTLINE"/>
    <STRING id="STR_ID_CUSTSER_MANAGER"/>
    <STRING id="STR_ID_CUSTSER_MYMONWAP"/>
    <STRING id="STR_ID_CUSTSER_MYMONWAP_CONTENT"/>
    <STRING id="STR_ID_CUSTSER_MONWAP"/>
    <STRING id="STR_ID_CUSTSER_MONWAP_SMS"/>
    <STRING id="STR_ID_CUSTSER_MONWAP_SMS_CONTENT"/>
    <STRING id="STR_ID_CUSTSER_MONWAP_MMS"/>
    <STRING id="STR_ID_CUSTSER_MONWAP_MMS_CONTENT"/>
    <STRING id="STR_ID_CUSTSER_SETTING"/>
    <STRING id="STR_ID_CUSTSER_SETTING_HOTLINE"/>
    <STRING id="STR_ID_CUSTSER_SETTING_MANAGER"/>
    <STRING id="STR_ID_CUSTSER_SETTING_MANAGER_NAME"/>
    <STRING id="STR_ID_CUSTSER_SETTING_MANAGER_NUM"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_CUSTSER_GUIDELINE">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_ServiceGuide.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CUSTSER_SALE_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_SMSSale.bmp"</IMAGE>
#ifdef BROWSER_SUPPORT
    <IMAGE id="IMG_ID_CUSTSER_SALE">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_HandService.bmp"</IMAGE>
#endif
    <IMAGE id="IMG_ID_CUSTSER_HOTLINE">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_ServiceHotline.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CUSTSER_MANAGER">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_CustomerManager.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CUSTSER_MYMONWAP">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_MyMonternet.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CUSTSER_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\CustomerServices\\\\CS_Setting.bmp"</IMAGE>
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_KEY_LAUNCH_CS_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\MainMenu\\\\SV.png"</IMAGE>
#endif
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENU id="MENU_ID_CUSTSER_GUIDELINE" str="STR_ID_CUSTSER_GUIDELINE" img="IMG_ID_CUSTSER_GUIDELINE"/>
    <MENU id="MENU_ID_CUSTSER_SMS_SALE" str="STR_ID_CUSTSER_SMS_SALE" img="IMG_ID_CUSTSER_SALE_SMS"/>
#ifdef BROWSER_SUPPORT
    <MENU id="MENU_ID_CUSTSER_SALE" str="STR_ID_CUSTSER_SALE" img="IMG_ID_CUSTSER_SALE"/>
#endif
    <MENU id="MENU_ID_CUSTSER_HOTLINE" str="STR_ID_CUSTSER_HOTLINE" img="IMG_ID_CUSTSER_HOTLINE"/>
    <MENU id="MENU_ID_CUSTSER_MANAGER" str="STR_ID_CUSTSER_MANAGER" img="IMG_ID_CUSTSER_MANAGER"/>
    <MENU id="MENU_ID_CUSTSER_MYMONWAP" str="STR_ID_CUSTSER_MYMONWAP" img="IMG_ID_CUSTSER_MYMONWAP"/>

    <MENUITEM id="MENU_ID_CUSTSER_SETTING_HOTLINE" str="STR_ID_CUSTSER_SETTING_HOTLINE" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_ID_CUSTSER_SETTING_MANAGER" str="STR_ID_CUSTSER_SETTING_MANAGER" img="IMG_GLOBAL_L2"/>

    <MENU id="MENU_ID_CUSTSER_SETTING" type="OPTION" str="STR_ID_CUSTSER_SETTING" img="IMG_ID_CUSTSER_SETTING">
        <MENUITEM_ID>MENU_ID_CUSTSER_SETTING_HOTLINE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CUSTSER_SETTING_MANAGER</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_CUSTOMER_SERVICE"/>
    <SCREEN id="SCR_ID_CUSTSER_TEXTVIEWER"/>
    <SCREEN id="SCR_ID_CUSTSER_MYMONWAP"/>

    <!------------------------------------------------------Callback Mgr Resource Area------------------------------------------------------->     
#if (defined __SIM_HOT_SWAP_SUPPORT__) || (defined __SIM_RECOVERY_ENHANCEMENT__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_custser_sim_ctrl_detected_hdlr"/>
#endif

#endif /* __MMI_CUSTOMER_SERVICE__ */

</APP>

