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

/*******************************************************************************
 * Filename:
 * ---------
 *   note.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file
 *
 * Author:
 * -------
 *   Jinchuan Gou mtk80241
 *
 *******************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_NOTE"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#ifdef __MMI_NOTE_APP__
     package_name = "native.mtk.note"           /* Use "native.mtk." as the prefix of application name */
     name = "STR_ID_NOTE_APP"                   /* The string to be displayed under the main menu icon */
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
     img = "IMG_ID_MAIN_MENU_NOTE_APP"          /* Main menu icon image */
#endif
     launch = "mmi_note_app_launch_func"        /* Launch function of application. When tap on the icon in main menu, the function will be invoked. */
#endif /*__MMI_NOTE_APP__ */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>

#ifdef __MMI_NOTE_APP__

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>  
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
    <STRING id="STR_ID_NOTE_APP"/>
    <STRING id="STR_ID_NOTE_MARK_SEVERAL"/>
    <STRING id="STR_ID_NOTE_DELETE_MARKED"/>
	<STRING id="STR_ID_NOTE_NEW_NOTE"/>
	<STRING id="STR_ID_NOTE_DELETE_NOTE_ASK"/>
	<STRING id="STR_ID_NOTE_DELETE_MARKED_ASK"/>
	<STRING id="STR_ID_NOTE_NOTE_DELETED"/>
	<STRING id="STR_ID_NOTE_ITEM_LIMIT"/>
	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
    <!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Audio Resource Area-->
	<!--Audio Resource Area-->
    <IMAGE id="IMG_ID_NOTE_APP">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\meeting.bmp"</IMAGE>
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
    <IMAGE id="IMG_ID_MAIN_MENU_NOTE_APP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\launcher\\\\Mainmenu\\\\Icons\\\\Note.png"</IMAGE>
#endif
	<!--End Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Media Resource Area-->
	<!--Media Resource Area-->
	<!--End Media Resource Area-->
	<!--End Media Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->
	<SCREEN id = "SCR_ID_NOTE_START"/>
	<SCREEN id = "SCR_ID_NOTE_LIST"/>
	<SCREEN id = "SCR_ID_NOTE_LIST_OPTION"/>	
	<SCREEN id = "SCR_ID_NOTE_VIEW"/>
	<SCREEN id = "SCR_ID_NOTE_VIEW_OPTION"/>
	<SCREEN id = "SCR_ID_NOTE_EDIT"/>	
	<SCREEN id = "SCR_ID_NOTE_EDIT_OPTION"/>
	<SCREEN id = "SCR_ID_NOTE_MARK"/>
	<SCREEN id = "SCR_ID_NOTE_MARK_OPTION"/>
	<SCREEN id = "SCR_ID_NOTE_END"/>
	<SCREEN id = "GRP_ID_NOTE_MAIN"/>
    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->
  
	<MENU id="MENU_ID_NOTE_APP_MAIN" type="APP_MAIN" str="STR_ID_NOTE_APP" img="IMG_ID_NOTE_APP"
		shortcut = "ON" shortcut_img = "IMG_ID_NOTE_APP" launch = "mmi_note_launch" highlight="mmi_note_highlight_main">
    </MENU>
    
    <MENU id="MENU_ID_NOTE_MARK_SEVERAL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_NOTE_MARK" str="STR_GLOBAL_MARK"/>
        <MENUITEM id="MENU_ID_NOTE_UNMARK" str="STR_GLOBAL_UNMARK"/>
        <MENUITEM id="MENU_ID_NOTE_MARK_ALL" str="STR_GLOBAL_MARK_ALL"/>
        <MENUITEM id="MENU_ID_NOTE_UNMARK_ALL" str="STR_GLOBAL_UNMARK_ALL"/>
        <MENUITEM id="MENU_ID_NOTE_MARKED_DEL" str="STR_ID_NOTE_DELETE_MARKED"/>
    </MENU>
	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

#endif /* __MMI_NOTE_APP__ */

</APP>



