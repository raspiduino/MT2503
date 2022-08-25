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
 * SnsApp.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is the resource for SNS app feature.
 *
 * Author:
 * -------
 *  Xiaolin Chen (mtk80776)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 11 2012 xiaolin.chen
 * [MAUI_03197320] [FTE SNS] SNS app MMI feature option
 * .
 *
 * 06 08 2012 xiaolin.chen
 * [MAUI_03199512] [Feature Switch Verification Fail]TOUCH_PANEL_SUPPORT from TP_INTERNAL to NONE
 * .
 *
 * 06 05 2012 xiaolin.chen
 * [MAUI_03197320] [FTE SNS] SNS app MMI feature option
 * .
 *
 * 05 23 2012 xiaolin.chen
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 * 05 18 2012 xiaolin.chen
 * [MAUI_03183029] [FTE SNS][NCetner] new feature
 * .
 *
 * 05 18 2012 xiaolin.chen
 * [MAUI_03187763] [FTE] Upgrade new feature check in
 * .
 *
 * 05 16 2012 xiaolin.chen
 * [MAUI_03184022] [SNS]In this case show fail to capture .
 * .
 *
 * 05 15 2012 xiaolin.chen
 * [MAUI_03183029] [FTE SNS][NCetner] new feature
 * .
 *
 * 05 02 2012 xiaolin.chen
 * [MAUI_03150627] [FTE SNS] Add some trace and code vibrate
 * .
 *
 * 04 23 2012 xiaolin.chen
 * [MAUI_03173030] [SNS_IV]There has no "Comment" option at happening image viewer
 * .
 *
 * 04 21 2012 xiaolin.chen
 * [MAUI_03172890] [FTE SNS] Cannnot view comments of photo
 * .
 *
 * 04 18 2012 xiaolin.chen
 * [MAUI_03144519] [Pluto SNS OOM] stop fun n games screen should not be shown in the mentioned case
 * .
 *
 * 04 05 2012 xiaolin.chen
 * [MAUI_03162437] wrong popup shown when failed to unlike
 * .
 *
 * 04 05 2012 xiaolin.chen
 * [MAUI_03161094] wrong popup
 * .
 *
 * 03 28 2012 xiaolin.chen
 * [MAUI_03150627] [FTE SNS] Add some trace and code vibrate
 * .
 *
 * 03 24 2012 xiaolin.chen
 * [MAUI_03155765] [FTE SNS] Twitter feature
 * .
 *
 * 03 20 2012 xiaolin.chen
 * [MAUI_03150627] [FTE SNS] Add some trace and code vibrate
 * .
 *
 * 03 19 2012 xiaolin.chen
 * [MAUI_03151204] log in?string is inconsistency
 * .
 *
 * 03 15 2012 xiaolin.chen
 * [MAUI_03149579] [IV_SNS]String issue
 * .
 *
 * 03 12 2012 xiaolin.chen
 * [MAUI_03144008] [FTE SNS] String error
 * .
 *
 * 03 10 2012 xiaolin.chen
 * [MAUI_03143317] done should be "send" on new status screen
 * .
 *
 * 03 08 2012 xiaolin.chen
 * [MAUI_03142695] wrong title is shown
 * .
 *
 * 03 08 2012 xiaolin.chen
 * [MAUI_03145259] [FTE SNS] Setting is no available provider string
 * .
 *
 * 03 08 2012 xiaolin.chen
 * [MAUI_03142741] Unlike not present in view picture
 * .
 *
 * 03 08 2012 xiaolin.chen
 * [MAUI_03142663] hint should be reply
 * .
 *
 * 03 06 2012 xiaolin.chen
 * [MAUI_03142426] [FTE SNS] __MMI_ICON_BAR_SUPPORT__ compile option missed
 * .
 *
 * 02 24 2012 xiaolin.chen
 * [MAUI_03106396] [Pluto SNS] SNS new feature check in
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined(__SOCIAL_NETWORK_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__)

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SNS"
#if defined (__MMI_SNS_CENTER__) && defined (__MMI_APP_MANAGER_SUPPORT__)
     package_name = "native.mtk.sns"
     name = "STR_ID_SNS_CENTER"
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__))//MM_ICON
     img = "IMG_ID_SNS_FTE_LAUNCHER"
#endif
     launch = "mmi_sns_app_mgr_proc"

    package_proc = "mmi_sns_appmgr_package_proc"
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_app_mainmenu_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SNS_CENTER"/>

    <STRING id="STR_ID_SNS_HAPPENINGS"/>
    <STRING id="STR_ID_SNS_ME"/>
    <STRING id="STR_ID_SNS_DM"/>
    <STRING id="STR_ID_SNS_NOTIFICATIONS"/>

    <STRING id="STR_ID_SNS_ADD_NEW_STATUS"/>
    <STRING id="STR_ID_SNS_FILTER"/>

    <STRING id="STR_ID_SNS_NEW_STATUS"/>
    <STRING id="STR_ID_SNS_INSERT_PIC"/>
    <STRING id="STR_ID_SNS_REMOVE_PIC"/>
    <STRING id="STR_ID_SNS_CAMERA"/>

    <STRING id="STR_ID_SNS_ADD_TO_FAVORITE"/>
    <STRING id="STR_ID_SNS_REMOVE_FROM_FAVORITE"/>

    <STRING id="STR_ID_SNS_DIRECT_MSG"/>
    <STRING id="STR_ID_SNS_NEW_DIRECT_MSG"/>
    <STRING id="STR_ID_SNS_HINT_NEW"/>

    <STRING id="STR_ID_SNS_ALL_OF_ACCOUNT"/>
    <STRING id="STR_ID_SNS_FAVORITE_FRIENDS"/>

    <STRING id="STR_ID_SNS_MY_HAPPENINGS"/>
    <STRING id="STR_ID_SNS_ALBUMS"/>
    <STRING id="STR_ID_SNS_PERSONAL_INFO"/>
    <STRING id="STR_ID_SNS_AT_ME"/>
    <STRING id="STR_ID_SNS_COMMENTS"/>
    <STRING id="STR_ID_SNS_FRIENDS_REQ"/>

    <STRING id="STR_ID_SNS_COMMENT"/>
    <STRING id="STR_ID_SNS_LIKE"/>
    <STRING id="STR_ID_SNS_UNLIKE"/>
    <STRING id="STR_ID_SNS_RETWEET"/>
    <STRING id="STR_ID_SNS_SAVE_TO_LOCAL"/>


    <STRING id="STR_ID_SNS_SETTING"/>
    <STRING id="STR_ID_SNS_ACCOUNT_SETTING"/>
    <STRING id="STR_ID_SNS_DATA_ACCOUNT"/>
    <STRING id="STR_ID_SNS_ACCOUNT"/>
    <STRING id="STR_ID_SNS_ADD_ACCOUNT"/>

    <STRING id="STR_ID_SNS_LOGIN"/>
    <STRING id="STR_ID_SNS_LOGIN_NAME"/>
    <STRING id="STR_ID_SNS_LOGIN_PASSWD"/>
    <STRING id="STR_ID_SNS_CONTACT_PHOTO"/>
    <STRING id="STR_ID_SNS_SYNC_CONTACT"/>
    <STRING id="STR_ID_SNS_SYNC_CALENDAR"/>
    <STRING id="STR_ID_SNS_LSK_SYNC"/>

    <STRING id="STR_ID_SNS_REJECT"/>

    <STRING id="STR_ID_SNS_REFRESH_SYNC_DATA"/>
    <STRING id="STR_ID_SNS_DELETE_ACCOUNT"/>

    <STRING id="STR_ID_SNS_NO_ACCOUNT"/>

    <STRING id="STR_ID_SNS_INFO_PHONE"/>
    <STRING id="STR_ID_SNS_INFO_EMAIL"/>
    <STRING id="STR_ID_SNS_INFO_BIRTHDAY"/>
    <STRING id="STR_ID_SNS_INFO_GENDER"/>
    <STRING id="STR_ID_SNS_INFO_ADDRESS"/>
    <STRING id="STR_ID_SNS_INFO_PROFILE_URL"/>

    <STRING id="STR_ID_SNS_INFO_GENDER_UNKNOWN"/>
    <STRING id="STR_ID_SNS_INFO_GENDER_MALE"/>
    <STRING id="STR_ID_SNS_INFO_GENDER_FEMALE"/>

    <STRING id="STR_ID_SNS_MANAGEMENT"/>

    <STRING id="STR_ID_SNS_SELECT_ONE_RECIPIENT"/>
    <STRING id="STR_ID_SNS_EXIT_QUERY"/>

    <STRING id="STR_ID_SNS_NO_MORE_ACCOUNT_LOGIN"/>
    <STRING id="STR_ID_SNS_LOGIN_PROCESSING"/>
    <STRING id="STR_ID_SNS_INVALID_USER_NP"/>
    <STRING id="STR_ID_SNS_FAIL_LOGIN"/>
    <STRING id="STR_ID_SNS_LOGOUT_PROCESSING"/>
    <STRING id="STR_ID_SNS_SYNC_PROCESSING"/>
    <STRING id="STR_ID_SNS_SYNC_FRIEND_FAIL"/>
    <STRING id="STR_ID_SNS_SYNC_CALENDAR_FAIL"/>

    <STRING id="STR_ID_SNS_TIPS_INPUT_CONTENT"/>

    <STRING id="STR_ID_SNS_FRIEND"/>

    <STRING id="STR_ID_SNS_NO_HAPPENINGS"/>
    <STRING id="STR_ID_SNS_NO_DIRECT_MSG"/>
    <STRING id="STR_ID_SNS_NO_SNS_FRIENDS"/>
    <STRING id="STR_ID_SNS_NO_COMMENTS"/>
    <STRING id="STR_ID_SNS_NO_FRIENDS_REQUESTS"/>
    <STRING id="STR_ID_SNS_NO_ALBUMS"/>
    <STRING id="STR_ID_SNS_NO_PHOTOS"/>
    <STRING id="STR_ID_SNS_NO_CONTENTS"/>
    <STRING id="STR_ID_SNS_NO_AT_ME"/>
    <STRING id="STR_ID_SNS_NO_AVAILABLE_PROVIDER"/>

    <STRING id="STR_ID_SNS_IMAGE_DOWNLOAD_FAILED"/>
    <STRING id="STR_ID_SNS_IAMGE_DOWNLOADING"/>

    <STRING id="STR_ID_SNS_VIEW_IMAGE"/>

    <STRING id="STR_ID_SNS_ACTIVITY_LIKE"/>
    <STRING id="STR_ID_SNS_ACTIVITY_LIKES"/>
    <STRING id="STR_ID_SNS_ACTIVITY_COMMENT"/>
    <STRING id="STR_ID_SNS_ACTIVITY_COMMENTS"/>

    <STRING id="STR_ID_SNS_ACCOUNT_LOGOUT"/>

    <STRING id="STR_ID_SNS_FAILED_SEND_TO"/>
    <STRING id="STR_ID_SNS_FAILED_TO_LIKE"/>
    <STRING id="STR_ID_SNS_FAILED_TO_UNLIKE"/>
    <STRING id="STR_ID_SNS_FAILED_TO_RETWEET"/>

    <STRING id="STR_ID_SNS_ACCOUNTS"/>
    <STRING id="STR_ID_SNS_FRIENDS"/>
    <STRING id="STR_ID_SNS_ACCOUNT_ODD"/>
    <STRING id="STR_ID_SNS_FRIEND_ODD"/>

    <STRING id="STR_ID_SNS_REFRESHING"/>

    <STRING id="STR_ID_SNS_VIEW_COMMENTS"/>

    /* DO NOT modify below */
    <STRING id="STR_ID_SNS_SYNC_INTERVAL"/>
    <STRING id="STR_ID_SNS_SYNC_MANUAL"/>
    <STRING id="STR_ID_SNS_SYNC_1_HOUR"/>
    <STRING id="STR_ID_SNS_SYNC_3_HOURS"/>
    <STRING id="STR_ID_SNS_SYNC_6_HOURS"/>
    <STRING id="STR_ID_SNS_SYNC_12_HOURS"/>
    <STRING id="STR_ID_SNS_SYNC_1_DAY"/>
    <STRING id="STR_ID_SNS_SYNC_1_WEEK"/>

    /* DO NOT modify below */
    <STRING id="STR_ID_SNS_NEWS_REMINDER"/>
    <STRING id="STR_ID_SNS_NEWS_NEVER"/>
    <STRING id="STR_ID_SNS_NEWS_5_MINS"/>
    <STRING id="STR_ID_SNS_NEWS_15_MINS"/>
    <STRING id="STR_ID_SNS_NEWS_30_MINS"/>
    <STRING id="STR_ID_SNS_NEWS_1_HOUR"/>
    <STRING id="STR_ID_SNS_NEWS_3_HOURS"/>

/* #ifdef __MMI_NCENTER_SUPPORT__ */
    <STRING id="STR_ID_SNS_NCENTER_TITLE"/>
    <STRING id="STR_ID_SNS_NCENTER_NEW_COMMENT"/>
    <STRING id="STR_ID_SNS_NCENTER_NEW_MESSAGE"/>
    <STRING id="STR_ID_SNS_NCENTER_FRIEND_REQ"/>
    <STRING id="STR_ID_SNS_NCENTER_NEW_COMMENTS"/>
    <STRING id="STR_ID_SNS_NCENTER_NEW_MESSAGES"/>
    <STRING id="STR_ID_SNS_NCENTER_FRIEND_REQS"/>

/* #endif  __MMI_NCENTER_SUPPORT__ */


/* #ifdef __MMI_SNS_VPP_UPGRADE__ */
    <STRING id="STR_ID_SNS_UPGRADE_SUCCESS"/>
    <STRING id="STR_ID_SNS_UPGRADE_FAIL"/>

/* #endif */


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_SNS_APP">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Listicon\\\\SNS_center.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Listicon\\\\SNS_setting.png"</IMAGE>

/* #ifdef __MMI_APP_MANAGER_SUPPORT__ */
    <IMAGE id="IMG_ID_SNS_FTE_LAUNCHER">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\mainmenu\\\\icons\\\\SNS.png"</IMAGE>

/* #endif */

    <IMAGE id="IMG_ID_SNS_TAB_HAPPEN">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Tabbar_icon\\\\SNS_Tab_Happenings.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TAB_ME">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Tabbar_icon\\\\SNS_Tab_ME.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TAB_DM">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Tabbar_icon\\\\SNS_Tab_DM.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TAB_NOTIF">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Tabbar_icon\\\\SNS_Tab_Notice.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_ALL_ACCOUNT">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\\Listicon\\\\SNS_center.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_FAVORITE_GROUP">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\\Listicon\\\\SNS_Favorit.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_IMAGE_MARKER">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\SNS_Multimedia_icon\\\\SNS_Image.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_HEAD_SINGLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Default_icon\\\\SNS_Default_single.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_HEAD_MULTI">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Default_icon\\\\SNS_Default_Multi.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_FAVORITE_MARK">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Default_icon\\\\SNS_Favorit_friends.png"</IMAGE>

/* #ifdef __MMI_APP_HOMESCREEN_SNS__ */
    <IMAGE id="IMG_ID_SNS_IDLE_FRIEND">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_Friends.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_IDLE_FAVORITE_FR">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_Favorite.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_IDLE_HAPPEN">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_Happenings.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_IDLE_MY_PROF">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_Me.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_IDLE_DM">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_DM.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_IDLE_NOTIF">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Idle\\\\SNS_Shortcut_Notice.png"</IMAGE>
/* #endif */

    <IMAGE id="IMG_ID_SNS_DEFAULT_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\default_image\\\\NoImage.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_ALBUM_DOWNLOAD">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\default_image\\\\Default_Update.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_ALBUM_ERROR">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\default_image\\\\Default_Que.png"</IMAGE>

/* #ifdef __MMI_ICON_BAR_SUPPORT__ */
    <IMAGE id="IMG_ID_SNS_TOOLBAR_REFRESH">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Refresh.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_REFRESH_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Refresh_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_ADD">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Add.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_ADD_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Add_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_COMMENT">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Comment.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_COMMENT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Comment_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_FORWARD">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\SNS\\\\Forward.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_FORWARD_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Forward_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_LIKE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Like.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_LIKE_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Like_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_ADD_PIC">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Add_pic.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_ADD_PIC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Add_pic_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_SEND">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\send.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_SEND_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\send_dis.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_TOOLBAR_NEW_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\TB_write_message.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_NEW_MSG_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\TB_write_message_dis.png"</IMAGE>

    <IMAGE id="IMG_ID_SNS_TOOLBAR_RETWEET">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Retweet.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_TOOLBAR_RETWEET_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\Toolbar\\\\Retweet_dis.png"</IMAGE>

/* #endif  __MMI_ICON_BAR_SUPPORT__ */


/* #ifdef __MMI_NCENTER_SUPPORT__ */
    <IMAGE id="IMG_ID_SNS_NCENTER_NEW_COMMENTS">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\NCenter\\\\New_comments.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_NCENTER_NEW_MESSAGES">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\NCenter\\\\New_messages.png"</IMAGE>
    <IMAGE id="IMG_ID_SNS_NCENTER_FRIEND_REQ">CUST_IMG_PATH"\\\\MainLCD\\\\SNS\\\\NCenter\\\\Friend_request.png"</IMAGE>

/* #endif  __MMI_NCENTER_SUPPORT__ */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#ifdef __MMI_SNS_CENTER__
    <MENUITEM id = "MENU_ID_SNS_CENTER" str = "STR_ID_SNS_CENTER"
    #ifndef __MMI_SLIM_IMG_RES__
            img = "IMG_ID_SNS_APP"
    #endif
        highlight = "mmi_service_hilite_sns_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>
#endif

    <MENUITEM id = "MENU_ID_SNS_APP_SETTING" str = "STR_ID_SNS_MANAGEMENT"
        img = "IMG_ID_SNS_SETTING"
        highlight = "mmi_sns_setting_hilite_hdlr" parent = "MAIN_MENU_SETTINGS_MENUID"/>

    <!--Option Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <MENUITEM id="MENU_ID_SNS_VIEW" str="STR_GLOBAL_VIEW" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_REFRESH" str="STR_GLOBAL_REFRESH"/>
    <MENUITEM id="MENU_ID_SNS_REPLY" str="STR_GLOBAL_REPLY" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_FORWARD" str="STR_GLOBAL_FORWARD" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_FILTER" str="STR_ID_SNS_FILTER"/>
    <MENUITEM id="MENU_ID_SNS_DELETE" str="STR_GLOBAL_DELETE" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>

    <MENUITEM id="MENU_ID_SNS_COMMENT" str="STR_ID_SNS_COMMENT" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_LIKE" str="STR_ID_SNS_LIKE" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_UNLIKE" str="STR_ID_SNS_UNLIKE" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_RETWEET" str="STR_ID_SNS_RETWEET" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_SAVE_TO_LOCAL" str="STR_ID_SNS_SAVE_TO_LOCAL" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>
    <MENUITEM id="MENU_ID_SNS_VIEW_IMAGE" str="STR_ID_SNS_VIEW_IMAGE"/>

    <MENUITEM id="MENU_ID_SNS_NEW_STATUS" str="STR_ID_SNS_NEW_STATUS"/>
    <MENUITEM id="MENU_ID_SNS_INSERT_PIC" str="STR_ID_SNS_INSERT_PIC"/>
    <MENUITEM id="MENU_ID_SNS_REMOVE_PIC" str="STR_ID_SNS_REMOVE_PIC"/>
    <MENUITEM id="MENU_ID_SNS_CAMERA" str="STR_ID_SNS_CAMERA"/>

    <MENUITEM id="MENU_ID_SNS_DONE" str="STR_GLOBAL_DONE"/>

    <MENUITEM id="MENU_ID_SNS_ADD_TO_FAVORITE" str="STR_ID_SNS_ADD_TO_FAVORITE"/>
    <MENUITEM id="MENU_ID_SNS_REMOVE_FROM_FAVORITE" str="STR_ID_SNS_REMOVE_FROM_FAVORITE"/>
    <MENUITEM id="MENU_ID_SNS_DIRECT_MSG" str="STR_ID_SNS_DIRECT_MSG"/>

    <MENUITEM id="MENU_ID_SNS_NEW_DIRECT_MSG" str="STR_ID_SNS_NEW_DIRECT_MSG"/>

    <MENUITEM id="MENU_ID_SNS_ACCEPT" str="STR_GLOBAL_ACCEPT"/>
    <MENUITEM id="MENU_ID_SNS_REJECT" str="STR_ID_SNS_REJECT"/>

    <MENUITEM id="MENU_ID_SNS_SEND" str="STR_GLOBAL_SEND"/>

    <MENUITEM id="MENU_ID_SNS_SETTINGS" str="STR_GLOBAL_SETTINGS"/>
    <MENUITEM id="MENU_ID_SNS_LOGIN" str="STR_ID_SNS_LOGIN"/>
    <MENUITEM id="MENU_ID_SNS_CANCEL" str="STR_GLOBAL_CANCEL"/>
    <MENUITEM id="MENU_ID_SNS_REFRESH_SYNC_DATA" str="STR_ID_SNS_REFRESH_SYNC_DATA"/>
    <MENUITEM id="MENU_ID_SNS_DELETE_ACCOUNT" str="STR_ID_SNS_DELETE_ACCOUNT"/>

    <MENUITEM id="MENU_ID_SNS_VIEW_COMMENTS" str="STR_ID_SNS_VIEW_COMMENTS" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS"/>


    /* Happenings list options */
    <MENU id="MENU_ID_SNS_ACTIVITIES_LIST_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group = "MENU_GROUP_ID_SNS_DIFF_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_ADD_NEW_STATUS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_COMMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_LIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_UNLIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_RETWEET</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_FILTER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_DELETE</MENUITEM_ID>
    </MENU>

    /* Happening details options */
    <MENU id="MENU_ID_SNS_ACTIVITY_DETAILS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_COMMENT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SNS_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_LIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_UNLIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_RETWEET</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SNS_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_SAVE_TO_LOCAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_VIEW_IMAGE</MENUITEM_ID>
    </MENU>

    /* Add new status options */
    <MENU id="MENU_ID_SNS_ADD_NEW_STATUS" type="OPTION" str="STR_ID_SNS_ADD_NEW_STATUS">
        <MENUITEM_ID>MENU_ID_SNS_NEW_STATUS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_INSERT_PIC</MENUITEM_ID>
    #ifdef __MMI_SNS_CENTER_TAKE_PHOTO__
        <MENUITEM_ID>MENU_ID_SNS_CAMERA</MENUITEM_ID>
    #endif
    </MENU>

    /* Edite screen options */
    <MENU id="MENU_ID_SNS_EDITOR_ACT_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_INSERT_PIC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REMOVE_PIC</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>

    /* Contacts friends options */
    <MENU id="MENU_ID_SNS_CONTACTS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_ADD_TO_FAVORITE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REMOVE_FROM_FAVORITE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_FILTER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_DIRECT_MSG</MENUITEM_ID>
    </MENU>

    /* Album options */
    <MENU id="MENU_ID_SNS_ALBUM_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_VIEW_IMAGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_VIEW_COMMENTS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_COMMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_LIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_UNLIKE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_SAVE_TO_LOCAL</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SNS_VIEW_COMMENTS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" group="MENU_GROUP_ID_SNS_DIFF_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_COMMENT</MENUITEM_ID>
    </MENU>

    /* DM list options */
    <MENU id="MENU_ID_SNS_DM_LIST_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_NEW_DIRECT_MSG</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_DELETE</MENUITEM_ID>
    </MENU>

    /* DM details options */
    <MENU id="MENU_ID_SNS_DM_DETAILS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_DELETE</MENUITEM_ID>
    </MENU>

    /* Friends request options */
    <MENU id="MENU_ID_SNS_FRIENDS_REQ_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_ACCEPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REJECT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REFRESH</MENUITEM_ID>
    </MENU>

    /* @me & Comments options */
    <MENU id="MENU_ID_SNS_COMMENTS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_COMMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_REFRESH</MENUITEM_ID>
    </MENU>

    /* Direct message options */
    <MENU id="MENU_ID_SNS_EDITOR_MSG_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_SEND</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>

    /* setting login options */
    <MENU id="MENU_ID_SNS_SETTING_LOGIN_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_LOGIN</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
        <MENUITEM_ID>MENU_ID_SNS_CANCEL</MENUITEM_ID>
    </MENU>

    /* setting config/sync options */
    <MENU id="MENU_ID_SNS_SETTING_ACCOUNT_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_REFRESH_SYNC_DATA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_DELETE_ACCOUNT</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Screen Resource--------------------------------------------------------->
    <SCREEN id="GRP_ID_SNS_MAIN"/>
    <SCREEN id="GRP_ID_SNS_MY_PROFILE"/>
    <SCREEN id="GRP_ID_SNS_NOTIFICATION"/>
    <SCREEN id="GRP_ID_SNS_EDITOR"/>
    <SCREEN id="GRP_ID_SNS_SETTING"/>
    <SCREEN id="GRP_ID_SNS_ALBUMS"/>
    <SCREEN id="GRP_ID_SNS_FRIEND_LIST"/>
    <SCREEN id="GRP_ID_SNS_SYNC"/>

    <SCREEN id="SCR_ID_SNS_MAIN"/>
    /* DO NOT modify the order */
    <SCREEN id="SCR_ID_SNS_TAB_ACTIVITY"/>
    <SCREEN id="SCR_ID_SNS_TAB_MY_PROFILE"/>
    <SCREEN id="SCR_ID_SNS_TAB_DM"/>
    <SCREEN id="SCR_ID_SNS_TAB_NOTIF"/>

    <SCREEN id="SCR_ID_SNS_LOADING"/>
    <SCREEN id="SCR_ID_SNS_MY_PROFILE"/>
    <SCREEN id="SCR_ID_SNS_NEWSFEED"/>
    <SCREEN id="SCR_ID_SNS_NOTIFICATION"/>
    <SCREEN id="SCR_ID_SNS_EDITOR"/>
    <SCREEN id="SCR_ID_SNS_SETTING"/>
    <SCREEN id="SCR_ID_SNS_ACCOUNT"/>
    <SCREEN id="SCR_ID_SNS_DATA_ACCOUNT"/>
    <SCREEN id="SCR_ID_SNS_FILTER"/>
    <SCREEN id="SCR_ID_SNS_ALBUMS_LIST"/>
    <SCREEN id="SCR_ID_SNS_ALBUMS_MATRIX"/>
    <SCREEN id="SCR_ID_SNS_IMAGE_VIEWER"/>
    <SCREEN id="SCR_ID_SNS_FRIEND_LIST"/>
    <SCREEN id="SCR_ID_SNS_SUB_MESSAGE"/>
    <SCREEN id="SCR_ID_SNS_SENDING"/>
    <SCREEN id="SCR_ID_SNS_LOGOUT"/>

    <SCREEN id="SCR_ID_SNS_VIEW_COMMENTS"/>
    <SCREEN id="SCR_ID_SNS_NEWS_REMINDER"/>

    <!------------------------------------------------------Event Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_START"         proc="mmi_sns_app_access_network_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_COMPLETE"      proc="mmi_sns_app_access_network_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_NET_FETCH_LIST_START"  proc="mmi_sns_app_access_network_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_NET_FETCH_LIST_END"    proc="mmi_sns_app_access_network_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_ITEM_UPDATED"          proc="mmi_sns_app_access_network_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_PLUGINS_UNLOADED"      proc="mmi_sns_misc_oom_proc"/>

#if defined (__MMI_NCENTER_SUPPORT__ ) && defined (__MMI_SNS_CENTER__)
    <RECEIVER id="EVT_ID_SRV_SNS_COUNTS_UPDATED"        proc="mmi_sns_ncenter_counter_update_proc"/>
    <RECEIVER id="EVT_ID_SRV_SNS_READY"                 proc="mmi_sns_ncenter_init_proc"/>

#endif /* __MMI_NCENTER_SUPPORT__ */

#ifdef __MMI_SNS_VPP_UPGRADE__
    <RECEIVER id="EVT_ID_SRV_SNS_PLUGINS_UPGRADED"      proc="mmi_sns_misc_upgrade_proc"/>

#endif


    <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>


<APP id="APP_SNS_DUMMY"
     name="STR_ID_SNS_DUMMY_APP"
     hidden_in_mainmenu="ture"
>
    <MEMORY extra_base="5"/>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SNS_DUMMY_APP"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    <!--Option Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */


    <!------------------------------------------------------Screen Resource--------------------------------------------------------->
    <SCREEN id="GRP_ID_SNS_DUMMY_APP"/>

    <!------------------------------------------------------Event Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SNS_PLUGIN_TO_LOAD"         proc="mmi_sns_dummy_app_launch_proc"/>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>


#endif /* defined(__SOCIAL_NETWORK_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) */
