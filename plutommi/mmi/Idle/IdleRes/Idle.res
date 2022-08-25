/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  Idle.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the idle screen application.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 18 2014 ting.wang
 * [MAUI_03488091] [BTDv3] check-in to 11C
 * BT dialer v3.0, idle with 2 bt profile link, check in.
 *
 * 12 30 2013 renxiao.zeng
 * [MAUI_03481771] [WEARABLE_DEVICE]check in to 11C
 * .
 *
 * 10 21 2013 lu.xiao
 * [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
 * .
 *
 * 10 17 2013 lu.xiao
 * [MAUI_03461832] [BT dialer v2.x] check-in to 11C
 * .
 *
 * 07 02 2013 lu.xiao
 * [MAUI_03438781] [SWPL Approved][BT dialer V2] patchback to 11BW1308MP
 * .check in idle app and mainmenu.
 *
 * 03 01 2013 shengxi.xu
 * [MAUI_03332365] [FMGR]always show "please insert memory card"
 * .
 *
 * 02 21 2013 shengxi.xu
 * [MAUI_03342142] Video wallpaper get rremoved when we press End key after setting it
 * .
 *
 * 11 23 2012 lu.xiao
 * [MAUI_03260501] [MSZ] Remove unused string in 11BW1232OF_SLIM_DEV
 * .Check in to 11B.
 *
 * 04 11 2012 chuangjie.xia
 * [MAUI_03166257] Move Timer ID to Module Own Res File
 * .move timer id
 *
 * 03 07 2012 chuangjie.xia
 * [MAUI_03143743] [Pluto Memory Enhancement] Merge ASM and MED
 * .
 *
 * 12 28 2011 chuangjie.xia
 * [MAUI_03106629] [UE]subLCD show wallpaper before showing Logo when open subLCD
 * .
 *
 * 12 05 2011 chuangjie.xia
 * [MAUI_03085891] [SubLCD]Sublcd wallpaper always show white screen .
 * .
 *
 * 06 08 2011 weilun.liu
 * [MAUI_02903937] [Idle] do slim item
 * remove unused context and old api
 *
 * 02 11 2011 weilun.liu
 * [MAUI_02869187] [Idle] remove csd icon code in idleClassic
 * remove cbm bear info
 *
 * 11 29 2010 weilun.liu
 * [MAUI_02843121] [Idle] remove idle obsolete api
 * remove idle obsolete api.
 *
 * 11 28 2010 weilun.liu
 * [MAUI_02842932] [Idle] Network name service revision and provide api for idle service indication string
 * revise network name service to support providing service indication string for specific sim.
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 10 26 2010 ch.ko
 * [MAUI_02831748] [Sub-LCD] Check-in feature
 * Check-in sub-LCD feature.
 *
 * 09 30 2010 weilun.liu
 * [MAUI_02824995] [Idle, Scrsaver, ScrLocker, Eons, NwName] callback manager register revise
 * .
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
/* <APP id="APP_IDLE" type="venus" name ="STR_ID_IDLE_APP_NAME"> */
<APP id="APP_IDLE" type="venus" name ="STR_ID_IDLE_MAIN_MENU">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>
    
    <!----- Memory setting----------------------------------------------------->



    <MEMORY heap="$(IDLE_ASM_HEAP_SIZE) + base(APP_VENUS_WALLPAPER)" fg="$(VFX_SYS_MEM_VRT_SIZE)+$(IDLE_ASM_FG_SIZE)" vrt_mem_factor="IDLE_ASM_VRT_MEM_FACTOR" inc="IdleMemCfg.h, vfx_sys_config.h"/>

    <!----- String Resource Area ---------------------------------------------->
    /* <STRING id="STR_ID_IDLE_APP_NAME"/> */
	<STRING id="STR_ID_IDLE_MAIN_MENU"/>
    <STRING id="STR_ID_IDLE_CONTACT"/>
    
#if 0 
    <STRING id="STR_ID_IDLE_LOCK_PROMPT"/>

#if defined(__MMI_OP01_WITH_WAP_KEY__)
    <STRING id="STR_ID_IDLE_ENTRY_WAP_CONFIRM"/>
#endif

#if defined(__OP12__)
    <STRING id="STR_ID_IDLE_OP12_LIVE"/>
#endif
#endif

#if defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_AUDIO"/>
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_BROWSER"/>
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_DIAL"/>
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_MG"/>
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_ALL_CALLS"/>
#if defined(__MMI_BT_DIALER_SUPPORT__)
    <STRING id="STR_ID_IDLE_ICON_SHORTCUT_HINT_BT_DIALER"/>
#endif
#endif /* defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__) */

#if defined(__MMI_BT_DIALER_SUPPORT__)
    <STRING id="STR_ID_IDLE_BTDIALER_CONNECT"/>
    <STRING id="STR_ID_IDLE_BTDIALER_DISCONNECT"/>
    <STRING id="STR_ID_IDLE_BTDIALER_CONNECTED_DEVICE"/>
#endif /* defined(__MMI_BT_DIALER_SUPPORT__) */

    <!----- Image Resource Area ----------------------------------------------->
#if defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_AUDIO_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_AUDIO_UP.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_BROSWER_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_BROSWER_UP.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_DIAL_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_DIAL_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_DIAL_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_DIAL_UP.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_MG_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_MG_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_MG_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_MG_UP.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_MISSCALL_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_MISSCALL_UP.png"</IMAGE>
#if defined(__MMI_BT_DIALER_SUPPORT__)
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_BT_DIALER_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_BT_DIALER_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_ICON_SHORTCUT_BT_DIALER_UP">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Shortcut\\\\TH_BT_DIALER_UP.png"</IMAGE>
#endif
#endif /* defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__) */

#ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_ID_IDLE_SUBLCD_LOGO">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_ON.bmp"</IMAGE>
#endif


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_IDLE_MAIN"/>
    <SCREEN id="SCR_ID_IDLE_MAIN"/>
    <SCREEN id="SCR_ID_IDLE_SUBLCD"/>


    <!----- Menu Resource Area ------------------------------------------------>


    <!----- Timer Resource Area ---- ------------------------------------------>
#if 0
#ifdef __OP12__    
    <TIMER id = "IDLE_DELAYED_RSK_TIMER"/>
#endif
#endif
    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_PHB_OWNER_NUMBER_CHANGED" proc="mmi_idle_main_evt_hdlr"/>

#ifdef __HOMEZONE_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED" proc="mmi_idle_main_evt_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_NW_NAME_CHANGED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_SAVER_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_SAVER_EXIT" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_UNLOCKED" proc="mmi_idle_main_evt_hdlr"/>

#ifdef __TCPIP__
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_ACTIVE" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECTED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INACTIVE" proc="mmi_idle_main_evt_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_CALLSET_LINE_SWITCHED" proc="mmi_idle_main_evt_hdlr"/>

#ifdef __MMI_CLAMSHELL__
    <RECEIVER id="EVT_ID_PHNSET_SUBWALLPAPER_CHANGED_NOTIFY" proc="mmi_idle_main_evt_hdlr"/>
#endif

    /*
     * This event is emitted after the handset enters the Idle App.
     *
     * Structure: mmi_idle_group_enter_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_GROUP_ENTER" type="SENDER"/>

    /*
     * This event is emitted after the handset exits the Idle App.
     *
     * Structure: mmi_idle_group_exit_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_GROUP_EXIT" type="SENDER"/>

    /*
     * This event is emitted after the handset enters the Idle main screen.
     *
     * Structure: mmi_idle_enter_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_ENTER" type="SENDER"/>

    /*
     * This event is emitted after the handset exits the Idle main screen.
     *
     * Structure: mmi_idle_exit_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_EXIT" type="SENDER"/>

    /*
     * This event is emitted after the Idle App is launched. This event can be
     * used if APP wants to show its screen after the Idle is launched. Please
     * return -1 to stop the event routing if your APP shows its own screen.
     *
     * Structure: mmi_idle_launched_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_LAUNCHED" type="SENDER"/>

    /*
     * This event is emitted before the handset enters the Idle App.
     *
     * Structure: mmi_idle_before_group_enter_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_BEFORE_GROUP_ENTER" type="SENDER"/>

    /*
     * This event is emitted before the handset exits the Idle App.
     *
     * Structure: mmi_idle_before_group_exit_evt_struct
     */
    <EVENT id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" type="SENDER"/>

    <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_GROUP_EXIT" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_EXIT" proc="mmi_idle_main_evt_hdlr"/>

#if defined(__MMI_BT_DIALER_SUPPORT__)
    #if !defined(__MMI_WEARABLE_DEVICE__)
    <RECEIVER id="EVT_ID_DIALER_CONN_EVENT_ID" proc="mmi_idle_classic_BT_dialer_event_handler"/>
    <RECEIVER id="EVT_ID_DIALER_DISCONN_EVENT_ID" proc="mmi_idle_classic_BT_dialer_event_handler"/>
    #endif  //!defined(__MMI_WEARABLE_DEVICE__)
    <RECEIVER id="EVT_ID_IDLE_LAUNCHED" proc="mmi_idle_classic_BT_dialer_event_handler"/>
#endif

    <EVENT id="EVT_ID_IDLE_MAIN_NOTIFY_REQ"/>
    <EVENT id="EVT_ID_IDLE_MAIN_UPDATE_REQ"/>
   
</APP>

