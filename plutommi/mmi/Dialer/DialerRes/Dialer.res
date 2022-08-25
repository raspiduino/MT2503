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
 * Dialer.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * Feng (mtk81063)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 21 2013 yingchun.xu
 * [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
 * .check in dialer part.
 *
 * 10 14 2013 yingchun.xu
 * [MAUI_03462439] [BT box] BT box feature check in to 11C
 * .check in for BT box
 *
 * 03 20 2013 yingchun.xu
 * [MAUI_03363784] [SWPL Approved][Change feature]BT Dialer Package Check in
 * .
 *
 * 06 11 2012 f.wang
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 03 23 2012 f.wang
 * [MAUI_03154516] [PHB_SNS][1] Assert fail: DialerCuiFactory.c 290 - MMI, [1] Expression: cntx->num <= (2)
 * .
 *
 * 02 22 2012 f.wang
 * [MAUI_03134994] Dialer tts voice report check in
 * .
 *
 * 01 31 2012 f.wang
 * [MAUI_03121054] [Dialer] BWT dialer check in
 * .
 *
 * 01 31 2012 f.wang
 * [MAUI_03121054] [Dialer] BWT dialer check in
 * .
 *
 * 09 07 2011 f.wang
 * [MAUI_03022359] FTE launcher
 * .
 *
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_DIALER"

#if defined (__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    package_name = "native.mtk.dialer"
    name = "STR_ID_DIALER_MENU"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON    
    img = "IMG_DIAL_ICON_FOR_COSMOS_ID"
#endif    
    hidden_in_mainmenu="false"
    launch = "mmi_dialer_launch"
#endif
>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
#ifdef __MMI_APP_MANAGER_SUPPORT__
	<STRING id = "STR_ID_DIALER_MENU"/>  
#endif  
    <!--End String Resource Area-->
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->
    <!--Image Resource Area-->
    
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
	<IMAGE id="IMG_DIAL_ICON_FOR_COSMOS_ID"> CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Call.png"</IMAGE>
#endif    
    
    <!--End Image Resource Area--> 
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
    <!--Screen ID Area-->
    <SCREEN id = "GRP_ID_DIALER_MAIN"/>	
    
    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->
    
    
    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->
#if 0
#ifdef  __OP01_FWPBW__ 
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_dialer_stop_tone_hdlr"/>
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_dialer_evt_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_TRANSMITTER_HOLD_ON" proc="mmi_dialer_evt_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_TRANSMITTER_PUT_DOWN" proc="mmi_dialer_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="mmi_dialer_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_dialer_evt_hdlr"/>
#endif    
#endif
#ifdef  __GENERAL_TTS__
    <RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_dialer_do_voice_tone_hdlr"/>
#endif

    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
</APP>
