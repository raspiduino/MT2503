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
 *  ProvBoxUI.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  ProvBoxUI resource file.
 *
 * Author:
 * -------
 *  Ying Fang (mtk80514)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 05 2014 sushil.sagar
 * [MAUI_03486818] [MT6261 Driver]  SMS Slim 6261 Check-in
 * change UM_FOLDER to UM_SUPPORT.
 *
 * 03 04 2014 sushil.sagar
 * [MAUI_03486818] [MT6261 Driver]  SMS Slim 6261 Check-in
 * .
 *
 * 12 25 2012 sushil.sagar
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * pluto slim check in.
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 06 13 2012 jianhua.zhao
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 05 09 2012 kefeng.lian
 * [MAUI_03179323] [CMCC Case Fail][8.1.5.1]²»֧³?ռ�¢¼�ѷ¢?Ϣµ?IM¿¨?Ϣɸѡ¹¦?
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /***************************************************************************** 
  * Include 
  *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "CustomCfg.h"
#include "CustResDef.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_PROVBOX"
#if defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
    package_name = "native.mtk.provbox"
    name = "STR_ID_PROVBOX_APP"
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
    img = "IMG_ID_PROVBOX_MENU_ICON"
#endif
    launch = "mmi_provbox_appmgr_launch"
#endif
>

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
#ifndef __COSMOS_MMI__
	#ifdef __UM_SUPPORT__
    <INCLUDE file="mmi_rp_app_unifiedmessage_def.h"/>
    #endif
#endif /* __COSMOS_MMI__ */

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_PROVBOX_NOTIFY_IND" proc="mmi_provbox_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_PROVBOX_NEW_MSG_IND" proc="mmi_provbox_event_hdlr"/>
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_PROVBOX_APP"/>

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    <STRING id="STR_ID_PROVBOX_MOVED"/>
    <STRING id="STR_ID_PROVBOX_FAIL_TO_MOVE"/>
    <STRING id="STR_ID_PROVBOX_MOVE_TO_ARCHIVE_CONFIRM"/>
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    <STRING id="STR_ID_PROVBOX_DELETE_ALL_POPUP_MSGS"/>
    <STRING id="STR_ID_PROVBOX_DELETE_ALL_POPUP"/>
    <STRING id="STR_ID_PROVBOX_HINT_MESSAGES"/>
    <STRING id="STR_ID_PROVBOX_HINT_MESSAGE"/>
    <STRING id="STR_ID_PROVBOX_NOT_INSTALLED"/>
    <STRING id="STR_ID_PROVBOX_NO_NUMBER"/>
    <STRING id="STR_ID_PROVBOX_SIM1_NAME"/>
    <STRING id="STR_ID_PROVBOX_SIM2_NAME"/>
    <STRING id="STR_ID_PROVBOX_SIM3_NAME"/>
    <STRING id="STR_ID_PROVBOX_SIM4_NAME"/>
    <STRING id="STR_ID_PROVBOX_SIM_NAME"/>
    <STRING id="STR_ID_PROVBOX_NMGR_QUERY_UNREAD_MSGS"/>
    <STRING id="STR_ID_PROVBOX_DELETE_ALL_FAIL"/>
    <STRING id="STR_ID_PROVBOX_DELETE_FAIL"/>
    <STRING id="STR_ID_PROVBOX_DELETE_ALL_CONFIRM"/>
    <STRING id="STR_ID_PROVBOX_DELETE_CONFIRM"/>
    <STRING id="STR_ID_PROVBOX_MSG_TYPE"/>
    <STRING id="STR_ID_PROVBOX_RECEIVE"/>
    <STRING id="STR_ID_PROVBOX_FROM"/>
    <STRING id="STR_ID_PROVBOX_INSTALL_TIME"/>
    <STRING id="STR_ID_PROVBOX_PROV_ITEM_NAME"/>
    <STRING id="STR_ID_PROVBOX_MOVE_TO_ACHIVE"/>
    <STRING id="STR_ID_PROVBOX_EMPTY_MSG">No message</STRING>
    <STRING id="STR_ID_PROVBOX_FULL">Provisioning message full</STRING>
    <STRING id="STR_ID_PROVBOX_FULL_SUB">Provisioning message reached</STRING>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>        

    <IMAGE id="IMG_ID_PROVBOX_APP_ICON"> CUST_IMG_PATH"\\\\MainLCD\\\\ProvBox\\\\SB_ProvBox.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PROVBOX_UNREAD"> CUST_IMG_PATH"\\\\MainLCD\\\\ProvBox\\\\ProvBox_MsgUnread.bmp"</IMAGE>        
    <IMAGE id="IMG_ID_PROVBOX_READ"> CUST_IMG_PATH"\\\\MainLCD\\\\ProvBox\\\\ProvBox_MsgRead.bmp"</IMAGE>
#ifdef __MMI_APP_MANAGER_SUPPORT__
    #if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
    <IMAGE id="IMG_ID_PROVBOX_MENU_ICON"> CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\setting_message.png"</IMAGE>
    #endif
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_ICON_BAR_SUPPORT__)
    <IMAGE id="IMG_ID_PROVBOX_FTE_INSTALL"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\ProvBox\\\\TB_install.png"</IMAGE>
    <IMAGE id="IMG_ID_PROVBOX_FTE_INSTALL_DISABLED"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\ProvBox\\\\TB_install_dis.png"</IMAGE>        
#endif

    <!----------------- Menu Id ------------------------------------------->       
#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_VIEW" str = "STR_GLOBAL_VIEW"/>
#else
    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_INSTALL" str = "STR_GLOBAL_INSTALL"/>
#endif

    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_DELETE" str = "STR_GLOBAL_DELETE"/>

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_MOVE_TO_ARCHIVE" str = "STR_ID_PROVBOX_MOVE_TO_ACHIVE"/>
#endif

#if !defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)|| !defined(__MMI_PROV_IN_UM__)
    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_PROERTIES" str = "STR_GLOBAL_DETAILS"/>
#endif 

#ifndef __MMI_PROV_IN_UM__
    <MENUITEM id = "MENU_ID_PROVBOX_OPTION_DELETE_ALL" str = "STR_GLOBAL_DELETE_ALL"/>
#endif

    <MENU id = "MENU_ID_PROVBOX_OPTION_MENU" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
    #if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_VIEW</MENUITEM_ID>
    #else
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_INSTALL</MENUITEM_ID>
    #endif
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_DELETE</MENUITEM_ID>

    #ifdef __MMI_PROV_IN_UM__
    #ifndef __COSMOS_MMI__
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
    #endif
    #else
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_DELETE_ALL</MENUITEM_ID>
    #endif
    
#ifndef __COSMOS_MMI__ //should remove?
    #if defined(__MMI_PROV_IN_UM__) && defined(__UNIFIED_MESSAGE_SORT_MESSAGE_LIST__)
        <MENUITEM_ID>MENU_ID_UM_SORT_BY_OPT</MENUITEM_ID>
    #endif
    
    #if defined(__MMI_PROV_IN_UM__) && defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__)
        <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>
    #endif
#endif

    #ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_MOVE_TO_ARCHIVE</MENUITEM_ID>
    #endif

#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT</MENUITEM_ID>
#endif

    #if !defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__) || !defined(__MMI_PROV_IN_UM__)
        <MENUITEM_ID>MENU_ID_PROVBOX_OPTION_PROERTIES</MENUITEM_ID>
    #endif
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_PROVBOX_PROGRESSING"/>
    <SCREEN id="SCR_ID_PROVBOX_OPTION"/>
    <SCREEN id="SCR_ID_PROVBOX_PROPERTIES"/>
    <SCREEN id="SCR_ID_PROVBOX_LIST_MENU"/>
    <SCREEN id="SCR_ID_PROVBOX_END"/>

    <!------------------------------------------------------Event handle Resource--------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_PROVBOX_NOTIFY_IND" proc="mmi_provbox_event_hdlr"/>

#ifdef __MMI_PROV_IN_UM__
    <RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="mmi_provbox_msg_handle_um_entry_folder"/>
#endif

#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
    <RECEIVER id="EVT_ID_MMI_UM_REFRESH" proc="mmi_provbox_um_iter_viewer_refresh"/>
#endif

#if defined(__DM_LAWMO_SUPPORT__) && defined(__MMI_PROV_IN_UM__)
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_provbox_lawmo_lock_ind_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" proc="mmi_provbox_lawmo_wipe_ind_hdlr"/>
#endif /* __DM_LAWMO_SUPPORT__ */
<!----------------- XML END --------------------------------------------------->
</APP>

#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
