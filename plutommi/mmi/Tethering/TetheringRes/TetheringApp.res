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
 * tethering.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering application plutommi resource.
 *
 * Author:
 * -------
 * Yixiong Zhao(mtk80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 16 2012 yixiong.zhao
 * [MAUI_03168679] [Proxy Address Support Domain Name Input] check in to 11B
 * Check in proxy url for tethering.
 *
 * 02 21 2012 yixiong.zhao
 * [MAUI_03134397] [Need Patch] [Sanity Fail] Sanity Test of MAUI\LUFFY76V22_DEMO_HSPA(FTE).W12.08 "tethering"  is Fail!!
 * .
 *
 * 12 21 2011 yixiong.zhao
 * [MAUI_03102823] [Tethering] Wi-Fi tethering support multi-language SSID
 * .
 *
 * 10 27 2011 yixiong.zhao
 * [MAUI_03062905] [sap]SAP connect, the da in wifi tethering show empty name
 * .
 *
 * 10 12 2011 yixiong.zhao
 * [MAUI_03036813] SIM Recovery Enhancement check-in
 * .
 *
 * 03 16 2011 yixiong.zhao
 * [MAUI_02896433] [must to solve] [Luffy76 WiFi tethering][3G DM][CHT] Turn off the Wi-Fi Tethering in no service takes more time
 * .
 *
 * 03 11 2011 youzhong.cheng
 * [MAUI_02451894] [Hotspot] Hotspot should not disconnect when Phone automatically switch from 3G to 2G network
 * .
 *
 * 02 18 2011 youzhong.cheng
 * [MAUI_02652256] [USB tethering] plutommi check in
 * .
 *
 * 12 31 2010 yixiong.zhao
 * [MAUI_02643373] [RHR] Check-in
 * solve resgen error.
 *
 * 12 25 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * .
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
#ifdef __MMI_TETHERING__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_TETHERING">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="mmi_rp_srv_tethering_def.h"/>
    <INCLUDE file="mmi_rp_srv_editor_def.h"/>
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_APP_TETHERING_SWITCH"/>
    <STRING id="STR_ID_APP_TETHERING_MINIMIZE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#ifdef __MMI_TETHERING_WIFI__
    <MENUITEM id="MENU_ID_TETHERING_WIFI_HS" str="STR_ID_SRV_TETHERING_WIFI_HS" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_ID_TETHERING_DATA_ACCOUNT" str="STR_GLOBAL_DATA_ACCOUNT" img="IMG_GLOBAL_L2"/>
    <MENUITEM id="MENU_ID_TETHERING_CONN_INFO" str="STR_ID_SRV_TETHERING_CONN_INFO" img="IMG_GLOBAL_L3"/>
    <MENUITEM id="MENU_ID_TETHERING_HELP" str="STR_GLOBAL_HELP" img="IMG_GLOBAL_L4"/>
#else    
    <MENUITEM id="MENU_ID_TETHERING_DATA_ACCOUNT" str="STR_GLOBAL_DATA_ACCOUNT" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_ID_TETHERING_CONN_INFO" str="STR_ID_SRV_TETHERING_CONN_INFO" img="IMG_GLOBAL_L2"/>
    <MENUITEM id="MENU_ID_TETHERING_HELP" str="STR_GLOBAL_HELP" img="IMG_GLOBAL_L3"/>
#endif
    <MENUITEM id="MENU_ID_TETHERING_WIFI_SSID_EDITOR_OPTION_DONE" str="STR_GLOBAL_DONE"/>

    <MENU id="MENU_ID_TETHERING" type="APP_MAIN" str="STR_ID_SRV_TETHERING" highlight="mmi_tethering_highlight_main">
    #ifdef __MMI_TETHERING_WIFI__
        <MENUITEM_ID>MENU_ID_TETHERING_WIFI_HS</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_TETHERING_DATA_ACCOUNT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_TETHERING_CONN_INFO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_TETHERING_HELP</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_TETHERING_WIFI_SSID_EDITOR_OPTION" type="APP_OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_TETHERING_WIFI_SSID_EDITOR_OPTION_DONE</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_TETHERING_MAIN"/>

    <SCREEN id="SCR_ID_TETHERING_MAIN"/>
    <SCREEN id="SCR_ID_TETHERING_WIFI_SSID_EDITOR"/>
    <SCREEN id="SCR_ID_TETHERING_WIFI_HS"/>
    <SCREEN id="SCR_ID_TETHERING_CONN_INFO"/>
    <SCREEN id="SCR_ID_TETHERING_PROXY"/>
    <SCREEN id="SCR_ID_TETHERING_HELP"/>
    <SCREEN id="SCR_ID_TETHERING_HELP_USB"/>

    <SCREEN id="GRP_ID_TETHERING_USB"/>
    <SCREEN id="SCR_ID_TETHERING_USB_CONFIRM"/>
    <SCREEN id="SCR_ID_TETHERING_USB_RECONNECT"/>

    //add for wifi tethering reconnect
    <SCREEN id="SCR_ID_TETHERING_WIFI_HS_RECONNECT"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE" proc="mmi_tethering_no_sim_available_hdlr"/>

</APP>
#endif /* __MMI_TETHERING__ */
