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
 *  ScrLocker.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the screen locker.
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
 * 01 02 2014 ye.tian
 * [MAUI_03481966] WEARABLE_DEVICE [DEV load check in 11C]
 * check in for [WEARABLE_DEVICE]feature[APP auto back to Idle].
 *
 * 12 20 2013 shuanglin.yu
 * [MAUI_03480792] Lock screen UI shows abnormal.
 * fixed build error for update name of str id
 *
 * 12 20 2013 shuanglin.yu
 * [MAUI_03480792] Lock screen UI shows abnormal.
 * check in BT box new feature one key lock screen and long tap unlock screen
 *
 * 10 19 2013 shuanglin.yu
 * [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
 * Check in Calendar/Screen Locker/Saver slim stage 1
 *
 * 03 12 2013 xuezhi.bao
 * [MAUI_03358116] [GPIO_BackLight_005]the backlight does not change from full bright to full dark
 * .
 *
 * 02 26 2013 xuezhi.bao
 * [MAUI_03346771] The title is "security Settin" /"Phone securit" /Sim1 securit" /INput Sim1 PI"  >>last chacrater of all the titles is missing
 * [Change Feature]Change default setting of "screen auto lock" from off to 15 secs.
 *
 * 02 07 2013 renxiao.zeng
 * [MAUI_03318370] [MT6260] Sanity Fail Unable to Unlock the screen after locked
 * .
 *
 * 01 21 2013 xuezhi.bao
 * [MAUI_03307249] [MT6260 pre-SQC]No notification comes on Lock screen when we receive an MMS notification
 * Support displaying notification on Lock screen when receiving an MMS notification.
 *
 * 12 25 2012 xuezhi.bao
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 12 25 2012 xuezhi.bao
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 04 21 2012 yiping.xie
 * [MAUI_03169501] [UE] the item "auto keypad lock" should remove to display , and change the string to 'Screen auto lock"
 * .
 *
 * 04 18 2012 yiping.xie
 * [MAUI_03171110] [lock] move timer ID to res file
 * .
 *
 * 04 13 2012 yiping.xie
 * [MAUI_03167062] after insert USB,should not lock screen at once
 * .
 *
 * 02 21 2012 yiping.xie
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 01 05 2012 yiping.xie
 * [MAUI_03111371] [DM]No wiping screen when wipe data
 * .
 *
 * 12 14 2011 yiping.xie
 * [MAUI_03096928] [TD_Single SIM] The screen can' t Unlock.
 * .
 *
 * 07 08 2011 weilun.liu
 * [MAUI_02976487] ECC call can not be ended when it is dialled on key pad locked screen
 * receive idle before enter instead of enter event, and update wgui softkey after idle showCategory by insert api to idleClassic enter api.
 *
 * 06 21 2011 weilun.liu
 * [MAUI_02966494] [SLIM_UE][Settings]The LSK diaplayed after pressin end key when keypad is locked.
 * update softkey bar after show idle category
 *
 * 06 08 2011 weilun.liu
 * [MAUI_02903937] [Idle] do slim item
 * remove unused context and old api
 *
 * 05 25 2011 weilun.liu
 * [MAUI_02949228] [SLIM] revise screen lock popup
 * screen lock popup revise
 *
 * 01 18 2011 weilun.liu
 * [MAUI_02862898] [Idle] register pre touch event
 * register pre touch event.
 *
 * 12 29 2010 weilun.liu
 * [MAUI_02855915] [SLIM]Unused string removal for SLIM projects
 * wrapped  compile option for unused string.
 *
 * 12 29 2010 weilun.liu
 * [MAUI_02855761] [SLIM] change some images for 32+32 slim projects
 * .
 *
 * 11 17 2010 weilun.liu
 * [MAUI_02839080] [Idle] new mmi cache mech. modification
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 09 30 2010 weilun.liu
 * [MAUI_02824995] [Idle, Scrsaver, ScrLocker, Eons, NwName] callback manager register revise
 * .
 *
 * 08 31 2010 yiruei.wu
 * [MAUI_02615210] Security setting app/srv check-in
 * Check-in
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
//lhm: add for option slim
#include "ScrLockerGprot.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_SCR_LOCKER">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_SLK_UNLOCK"/>
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id="STR_ID_SLK_UNLOCK_2"/>
    <STRING id="STR_ID_SLK_UNLOCK_3"/>
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

#if defined(__DM_LAWMO_SUPPORT__)
    <STRING id="STR_ID_SLK_SOS"/>
#endif

#if defined(__MMI_SCREEN_LOCK_CLASSIC__) && !defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__)
    <STRING id="STR_ID_SLK_KBD_HELP_MSG"/>
    <STRING id="STR_ID_SLK_KBD_HELP_MSG2"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCK_ME_MSG"/>
#endif

#if defined(__MMI_LAUNCHER_APP_LIST__)
    <STRING id="STR_ID_SLK_MISSED_CALL"/>
    <STRING id="STR_ID_SLK_MISSED_CALLS"/>
    <STRING id="STR_ID_SLK_NEW_SMS_MSG"/>
    <STRING id="STR_ID_SLK_NEW_SMS_MSGS"/>
    <STRING id="STR_ID_SLK_NEW_MMS_MSG"/>
    <STRING id="STR_ID_SLK_NEW_MMS_MSGS"/>
#if defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_ID_SLK_FANCY_HELP_MSG"/>
#else
    <STRING id="STR_ID_SLK_FANCY_HELP_MSG_2"/>
#endif
#endif /* defined(__MMI_LAUNCHER_APP_LIST__) */

#if defined(__DM_LAWMO_SUPPORT__)
    <STRING id="STR_ID_SLK_LAWMO_DEVICE_MANAGEMENT"/>
    <STRING id="STR_ID_SLK_LAWMO_LOCKED"/>
    <STRING id="STR_ID_SLK_LAWMO_WIPING"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_WIPING"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_WIPING_DONE"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_LOCKED"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_UNLOCKED"/>
#endif /* defined(__DM_LAWMO_SUPPORT__) */

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
    <STRING id="STR_ID_SLK_TIME_SETTING"/>
    <STRING id="STR_ID_SLK_15_SEC"/>
    <STRING id="STR_ID_SLK_30_SEC"/>
    <STRING id="STR_ID_SLK_1_MIN"/>
    <STRING id="STR_ID_SLK_5_MIN"/>
#endif

#if defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__)
   // <STRING id="STR_ID_SLK_KBD_UNLOCKED_MSG"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCK_ME_MSG_BWUI"/>
#endif

#if defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__) || defined(__MMI_BTD_BOX_UI_STYLE__)
    <STRING id="STR_ID_SLK_KBD_UNLOCKED_MSG"/>
#endif

    <!----- Image Resource Area ----------------------------------------------->
#if defined(__DM_LAWMO_SUPPORT__)
#if defined(__MMI_MAINLCD_128X128__)
    <IMAGE id="IMG_ID_SLK_LOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_KEY.BMP"</IMAGE>
#else
    <IMAGE id="IMG_ID_SLK_LOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_KEY.PNG"</IMAGE>
#endif
#endif

#if defined(__MMI_LAUNCHER_APP_LIST__)
    <IMAGE id="IMG_ID_SLK_MISSED_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_CALL.png"</IMAGE>
    <IMAGE id="IMG_ID_SLK_NEW_SMS_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_SMS.png"</IMAGE>
    <IMAGE id="IMG_ID_SLK_NEW_MMS_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_MMS.png"</IMAGE>
#endif /* defined(__MMI_LAUNCHER_APP_LIST__) */


#if defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__)
    <IMAGE id="IMG_ID_SLK_LOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_WARN.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SLK_UNLOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DONE.bmp"</IMAGE>
#endif


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_SLK_MAIN"/>
    <SCREEN id="SCR_ID_SLK_MAIN"/>
    <SCREEN id="GRP_ID_SLK_SETTING"/>
#if defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__)    
    <SCREEN id="SCR_ID_SLK_POPUP"/>    
#endif
#if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)    
		<SCREEN id="GRP_ID_SLK_MAIN_WDEVICE"/>
		<SCREEN id="GRP_ID_SLK_MAIN_SCREEN_WDEVICE"/>
#endif
    <!----- Menu Resource Area ------------------------------------------------>

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
    <MENU id="MENU_ID_SLK_TIME_SETTING_MENU" type="APP_SUB" str="STR_ID_SLK_TIME_SETTING">
        <MENUITEM_ID>MENU_ID_SLK_SETTING_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_15_SEC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_30_SEC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_1_MIN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_5_MIN</MENUITEM_ID>
    </MENU>
    
    //<MENUITEM id="MENU_ID_SLK_SETTING_ENTRY" str="STR_ID_SLK_TIME_SETTING"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_OFF" str="STR_GLOBAL_OFF"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_15_SEC" str="STR_ID_SLK_15_SEC"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_30_SEC" str="STR_ID_SLK_30_SEC"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_1_MIN" str="STR_ID_SLK_1_MIN"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_5_MIN" str="STR_ID_SLK_5_MIN"/>
#endif /* defined(__MMI_AUTO_KEYPAD_LOCK__) */


    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto KeyPad Lock Status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto KeyPad Lock Timer </DESCRIPTION>
    </CACHEDATA>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->    

    <TIMER id="KEYPAD_LOCK_TIMER"/>
    <TIMER id="IDLE_APP_AUTO_LOCK_TIMER_ID"/>

    <RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MMS_NMGR_ALERT" proc="mmi_slk_main_evt_hdlr"/>
#ifdef __MMI_CLAMSHELL__
    <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_slk_main_evt_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_slk_main_evt_hdlr"/>
#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) || defined(__MMI_SCREEN_LOCK_ANY_TIME__)|| defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
    <RECEIVER id="EVT_ID_GPIO_BACKLIGHT_ON" proc="mmi_slk_main_evt_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_BEFORE_GROUP_ENTER" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_LAUNCHED" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>

#if defined(__PLUTO_MMI_PACKAGE__)
#if defined(__DM_LAWMO_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_slk_lawmo_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND" proc="mmi_slk_lawmo_evt_hdlr"/>
#endif
#endif

    /*
     * This event is emitted when the handset is locked.
     *
     * Structure: mmi_scr_locker_locked_evt_struct
     */
    <EVENT id="EVT_ID_SCR_LOCKER_LOCKED" type="SENDER"/>

    /*
     * This event is emitted when the handset is unlocked.
     *
     * Structure: mmi_scr_locker_unlocked_evt_struct
     */
    <EVENT id="EVT_ID_SCR_LOCKER_UNLOCKED" type="SENDER"/>

    <EVENT id="EVT_ID_SLK_OBJ_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SLK_OBJ_CLOSED_IND"/>
    
#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
    <EVENT id="EVT_ID_SLK_POPUP_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SLK_POPUP_CLOSED_IND"/>
#endif 
    /*
     * This event is emitted before launch screen lock
     *
     * Screen lock will not be launched if register callback return MMI_RET_ERR
     * else return MMI_RET_OK
     *
     * Structure: mmi_scr_locker_pre_lock_evt_struct
     */
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
    <EVENT id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" type="SENDER"/>
#endif    
    
</APP>

