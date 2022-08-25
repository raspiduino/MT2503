/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtvsmsappres.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *   Luyuan Zhang (mtk80607)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 01 28 2012 luyuan.zhang
 * [MAUI_03119340] There are some mATV string have no chinese translation
 * .
 *
 * 06 16 2011 luyuan.zhang
 * [MAUI_02963600] [Daily build error fix for matv sms & SMS]
 * .
 *
 * 01 05 2011 luyuan.zhang
 * [MAUI_02646824] [Code revise for API remove and memory reduce]
 * .
 *
 * 11 23 2010 luyuan.zhang
 * [MAUI_02729130] [SMS] should use empty as background string.
 * .
 *
 * 11 11 2010 luyuan.zhang
 * [MAUI_02444104] White border is coming on soft key.
 * .
 *
 * 11 03 2010 luyuan.zhang
 * [MAUI_02444606] Wrong pop up comes
 * .
 *
 * 11 03 2010 luyuan.zhang
 * [MAUI_02727243] [SMS] the screen is not refreshed when the sms is deleted
 * .
 *
 * 10 22 2010 luyuan.zhang
 * [MAUI_02638219] [mATV_SMS]string "** message"shall be "** messages"
 * .
 *
 * 10 21 2010 luyuan.zhang
 * [MAUI_02638244] [mATV_SMS]Options fist item not appropriate to be the centre icon
 * .
 *
 * 10 21 2010 luyuan.zhang
 * [MAUI_02638239] [mATV_SMS]title "Insert template"shall be "Template"
 * .
 *
 * 10 09 2010 luyuan.zhang
 * [MAUI_02635498] [SMS  MATV UT] Check in code in preforce
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 
#include "custresdef.h"
#include "mmi_features_mtv_player.h"


<?xml version="1.0" encoding="UTF-8"?>
#ifdef __ATV_SMS_SUPPORT__
<APP id="APP_MTV_SMS">
    <INCLUDE file="GlobalResDef.h"/>
    <!---------------------String Resource Area----------------------------------------------------->
    <!-------------String Resource for SMS on MTV main menu begin-------------------------------->
	 	<STRING id="STR_ID_MTV_SMS_MAIN_TITLE"/>
	 	<STRING id="STR_ID_MTV_SMS_MAIN_WRITE_MESSAGE"/>
		<STRING id="STR_ID_MTV_SMS_MAIN_INBOX"/>
		<STRING id="STR_ID_MTV_SMS_MAIN_DRAFTBOX"/>
		<STRING id="STR_ID_MTV_SMS_MAIN_OUTBOX"/>
		<STRING id="STR_ID_MTV_SMS_MAIN_SENTBOX"/>

	  <!-------------String Resource for SMS on MTV main menu end-------------------------------->
		<!-------------String Resource for SMS Editor begin------------------------------------->
    <STRING id="STR_ID_MTV_SMS_EDITOR_TITLE"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_SEND"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_INPUTMETHOD"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NUMBER"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NAME"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_INSERT_TEMPLATE"/>
    <STRING id="STR_ID_MTV_SMS_EDITOR_SAVE"/>
    <STRING id="STR_ID_MTV_SMS_TEMPLATE_TITLE"/>



		<!-------------String Resource for SMS Editor end------------------------------------->

		<!-------------String Resource for SMS List Option begin-------------------------------->
	  <STRING id="STR_ID_MTV_SMS_LIST_VIEW"/>
		<STRING id="STR_ID_MTV_SMS_LIST_REPLY"/>
		<STRING id="STR_ID_MTV_SMS_LIST_SEND"/>

		<STRING id="STR_ID_MTV_SMS_LIST_RESEND"/>
		<STRING id="STR_ID_MTV_SMS_LIST_FORWARD"/>
		<STRING id="STR_ID_MTV_SMS_LIST_DELETE"/>
		<STRING id="STR_ID_MTV_SMS_LIST_DELETE_ALL"/>
		<!-------------String Resource for SMS List Option end---------------------------------->


		<!-------------String Resource for SMS viewer start------------------------------------->
		<STRING id="STR_ID_MTV_SMS_VIEW_TITLE"/>		
		<STRING id="STR_ID_MTV_SMS_VIEW_REPLY"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_SEND"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_RESEND"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_FORWARD"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_EDIT"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_DELETE"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_FROM"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_TO"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_TIME"/>
		<STRING id="STR_ID_MTV_SMS_VIEW_BODY"/>
	  <!-------------String Resource for SMS viewer end--------------------------------------->

	  <!-------------String Resource for send begin-------------------------------------------->
		<STRING id="STR_ID_MTV_SMS_SEND_INPUT_RECIPIENT_TITLE"/>
		<STRING id="STR_ID_MTV_SMS_SEND_INPUT_SC_TITLE"/>

#ifdef __MMI_DUAL_SIM_MASTER__
    <STRING id="STR_ID_MTV_SMS_SEND_FROM_SIM1"/>
    <STRING id="STR_ID_MTV_SMS_SEND_FROM_SIM2"/>
    <STRING id="STR_ID_MTV_SMS_SAVE_TO_SIM1"/>
		<STRING id="STR_ID_MTV_SMS_SAVE_TO_SIM2"/>
#endif			

	<!-------------String Resource for send end-------------------------------------------->

		<!-------------String Resource for popup begin-------------------------------------------->
		<STRING id="STR_ID_MTV_SMS_NOT_AVAIABLE"/>
		<STRING id="STR_ID_MTV_SMS_READ_FAILED"/>
		
		
		<STRING id="STR_ID_MTV_SMS_IS_DELETE"/>	
		<STRING id="STR_ID_MTV_SMS_IS_DELETE_ALL"/>	
		<STRING id="STR_ID_MTV_SMS_DELETE_FAILED"/>
		
		<STRING id="STR_ID_MTV_SMS_SENDING"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_NOT_SAVED"/>	
		<STRING id="STR_ID_MTV_SMS_SENT"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_SAVED"/>		
		<STRING id="STR_ID_MTV_SMS_SENT_FAILED_NOT_SAVED"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_FAILED"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_FAILED_SAVED"/>	
		
		<STRING id="STR_ID_MTV_SMS_SENT_CANCEL"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_CANCELING"/>	
		<STRING id="STR_ID_MTV_SMS_SENT_CANCELED"/>	
		
		<STRING id="STR_ID_MTV_SMS_INVALID_NUMBER"/>	
		<STRING id="STR_ID_MTV_SMS_EMPTY_SC"/>	
		<STRING id="STR_ID_MTV_SMS_LIST_HINT"/>	
		<STRING id="STR_ID_MTV_SMS_LIST_HINTS"/>	
		
	  <STRING id="STR_ID_MTV_SMS_REMOVE_OBJECT_CONFIRM"/>	
		<STRING id="STR_ID_MTV_SMS_RECIPIENT_SEARCH"/>	
	  <STRING id="STR_ID_MTV_SMS_DATA_EXCEEDED"/>
	  <STRING id="STR_ID_MTV_SMS_DATA_INVALID"/>

#if (defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__))
		<STRING id="STR_ID_MTV_SMS_USER_DEF_TEMP"/>
		<STRING id="STR_ID_MTV_SMS_PREDEF_TEMP"/>
#endif /* (defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__)) */

		<STRING id="STR_ID_MTV_SMS_DELETE_ALL_INOBX"/>	
		<STRING id="STR_ID_MTV_SMS_DELETE_ALL_OUTBOX"/>	
		<STRING id="STR_ID_MTV_SMS_DELETE_ALL_DRAFTS"/>	
	  <STRING id="STR_ID_MTV_SMS_DELETE_ALL_SENTBOX"/>	
	  <STRING id="STR_ID_MTV_SMS_NO_NUMBER"/>	
	  <STRING id="STR_ID_MTV_SMS_UPDATING_MSG"/>	
	  
 	  <STRING id="STR_ID_MTV_SMS_EMPTY_LIST"/>	

	<!-------------String Resource for send end-------------------------------------------->
	<!-------------String Resource for other------ end-------------------------------------->
#ifdef __MMI_SLIM_IMG_RES__
	<IMAGE id="IMG_MTV_SMS_SENDING_MESSAGE_ANI">CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Sending\\\\SS_SEND_SLIM"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
#endif
    <!--------------Menu Resource Area------------------------------------------------------>
    <!--------------Menu Resource Area------------------------------------------------------>
    <!--------------Menu Resource for main screen begin--------------------------------------->

	<MENU id="MENU_ID_MTV_SMS_MAIN_WRITE_MESSAGE" str="STR_ID_MTV_SMS_MAIN_WRITE_MESSAGE"  highlight="mmi_mtv_sms_write_msg_hilite_handler"/>
	<MENU id="MENU_ID_MTV_SMS_MAIN_INBOX" str="STR_ID_MTV_SMS_MAIN_INBOX" highlight="mmi_mtv_sms_hilite_inbox"/>
	<MENU id="MENU_ID_MTV_SMS_MAIN_OUTBOX" str="STR_ID_MTV_SMS_MAIN_OUTBOX" highlight="mmi_mtv_sms_hilite_outbox"/>
	<MENU id="MENU_ID_MTV_SMS_MAIN_DRAFTBOX" str="STR_ID_MTV_SMS_MAIN_DRAFTBOX" highlight="mmi_mtv_sms_hilite_draftbox"/>
	<MENU id="MENU_ID_MTV_SMS_MAIN_SENTBOX" str="STR_ID_MTV_SMS_MAIN_SENTBOX" highlight="mmi_mtv_sms_hilite_sentbox"/>

	
	
	
	<MENU id="MENU_ID_MTV_SMS_MAIN_ROOT" type="APP_MAIN" str="STR_ID_MTV_SMS_MAIN_TITLE">
		<MENUITEM_ID>MENU_ID_MTV_SMS_MAIN_WRITE_MESSAGE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_MAIN_INBOX</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_MAIN_DRAFTBOX</MENUITEM_ID>		
	  <MENUITEM_ID>MENU_ID_MTV_SMS_MAIN_OUTBOX</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_MAIN_SENTBOX</MENUITEM_ID>
	</MENU>
  <!--------------Menu Resource for main screen end--------------------------------------->

 
  <!--------------Menu Resource for list screen begin--------------------------------------->
	<MENU id="MENU_ID_MTV_SMS_LIST_VIEW" str="STR_ID_MTV_SMS_LIST_VIEW" highlight="mmi_mtv_sms_list_view_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_REPLY" str="STR_ID_MTV_SMS_LIST_REPLY" highlight="mmi_mtv_sms_list_reply_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_RESEND" str="STR_ID_MTV_SMS_LIST_RESEND" highlight="mmi_mtv_sms_list_resend_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_SEND" str="STR_ID_MTV_SMS_LIST_SEND" highlight="mmi_mtv_sms_list_send_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_EDIT" str="STR_ID_MTV_SMS_VIEW_EDIT" highlight="mmi_mtv_sms_list_edit_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_FORWARD" str="STR_ID_MTV_SMS_LIST_FORWARD" highlight="mmi_mtv_sms_list_forward_hilite"/>
  <MENU id="MENU_ID_MTV_SMS_LIST_DELETE" str="STR_ID_MTV_SMS_LIST_DELETE" highlight="mmi_mtv_sms_list_delete_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_LIST_DELETE_ALL" str="STR_ID_MTV_SMS_LIST_DELETE_ALL" highlight="mmi_mtv_sms_list_deleteall_hilite"/>
	
	<MENU id="MENU_ID_MTV_SMS_LIST_ROOT" type="OPTIONS">
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_VIEW</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_REPLY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_RESEND</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_SEND</MENUITEM_ID>		
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_EDIT</MENUITEM_ID>		
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_FORWARD</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_DELETE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_LIST_DELETE_ALL</MENUITEM_ID>			
	</MENU>
  <!--------------Menu Resource for list screen end--------------------------------------->
  
  <!--------------Menu Resource for viewer screen begin--------------------------------------->
	<MENU id="MENU_ID_MTV_SMS_VIEW_EDIT" str="STR_ID_MTV_SMS_VIEW_EDIT" highlight="mmi_mtv_sms_viewer_edit_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_VIEW_REPLY" str="STR_ID_MTV_SMS_VIEW_REPLY" highlight="mmi_mtv_sms_viewer_reply_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_VIEW_RESEND" str="STR_ID_MTV_SMS_VIEW_RESEND" highlight="mmi_mtv_sms_viewer_resend_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_VIEW_SEND" str="STR_ID_MTV_SMS_VIEW_SEND" highlight="mmi_mtv_sms_viewer_send_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_VIEW_FORWARD" str="STR_ID_MTV_SMS_VIEW_FORWARD" highlight="mmi_mtv_sms_viewer_forward_hilite"/>
  <MENU id="MENU_ID_MTV_SMS_VIEW_DELETE" str="STR_ID_MTV_SMS_VIEW_DELETE" highlight="mmi_mtv_sms_viewer_delete_hilite"/>


	
	<MENU id="MENU_ID_MTV_SMS_VIEW_ROOT" type="OPTIONS">
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_REPLY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_RESEND</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_SEND</MENUITEM_ID>		
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_EDIT</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_FORWARD</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_VIEW_DELETE</MENUITEM_ID>
	</MENU>
  <!--------------Menu Resource for viewer screen end--------------------------------------->

  
   <!--------------Menu Resource for editor screen begin--------------------------------------->
	<MENU id="MENU_ID_MTV_SMS_EDITOR_SEND" str="STR_ID_MTV_SMS_EDITOR_SEND" highlight="mmi_mtv_sms_editor_option_send_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_ED_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD"/>
	<MENU id="MENU_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NAME" str="STR_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NAME" highlight="mmi_mtv_sms_editor_option_insert_name_hilite"/>
	<MENU id="MENU_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NUMBER" str="STR_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NUMBER" highlight="mmi_mtv_sms_editor_option_insert_number_hilite"/>
#ifdef __MMI_MESSAGES_TEMPLATE__
	<MENU id="MENU_ID_MTV_SMS_EDITOR_INSERT_TEMPLATE" str="STR_ID_MTV_SMS_EDITOR_INSERT_TEMPLATE" highlight="mmi_mtv_sms_editor_option_insert_template_hilite"/>
#endif
	<MENU id="MENU_ID_MTV_SMS_EDITOR_SAVE" str="STR_ID_MTV_SMS_EDITOR_SAVE" highlight="mmi_mtv_sms_editor_option_save_hilite"/>

	<MENU id="MENU_ID_MTV_SMS_EDITOR_ROOT" type="OPTIONS">
		<MENUITEM_ID>MENU_ID_MTV_SMS_EDITOR_SEND</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_ED_OPT_INPUT_METHOD</MENUITEM_ID>
#ifdef __MMI_MESSAGES_TEMPLATE__
		<MENUITEM_ID>MENU_ID_MTV_SMS_EDITOR_INSERT_TEMPLATE</MENUITEM_ID>	
#endif
		<MENUITEM_ID>MENU_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NAME</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_EDITOR_INSERT_CONTACT_NUMBER</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MTV_SMS_EDITOR_SAVE</MENUITEM_ID>
	</MENU>
  <!--------------Menu Resource for editor screen end--------------------------------------->
	#ifdef __MMI_DUAL_SIM_MASTER__  
		<MENU id="MENU_ID_MTV_SMS_SEND_BY_SIM1" str="STR_ID_MTV_SMS_SEND_FROM_SIM1" highlight="mmi_mtv_sms_sending_hilite_sim1"/>
		<MENU id="MENU_ID_MTV_SMS_SEND_BY_SIM2" str="STR_ID_MTV_SMS_SEND_FROM_SIM2" highlight="mmi_mtv_sms_sending_hilite_sim2"/>
		<MENU id="MENU_ID_MTV_SMS_SEND_SELECT_SIM" type="OPTIONS">
			<MENUITEM_ID>MENU_ID_MTV_SMS_SEND_BY_SIM1</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_MTV_SMS_SEND_BY_SIM2</MENUITEM_ID>	
		</MENU>	
		<MENU id="MENU_ID_MTV_SMS_SAVE_TO_SIM1" str="STR_ID_MTV_SMS_SAVE_TO_SIM1" highlight="mmi_mtv_sms_save_hilite_sim1"/>
		<MENU id="MENU_ID_MTV_SMS_SAVE_TO_SIM2" str="STR_ID_MTV_SMS_SAVE_TO_SIM2" highlight="mmi_mtv_sms_save_hilite_sim2"/>
		<MENU id="MENU_ID_MTV_SMS_SAVE_SELECT_SIM" type="OPTIONS">
			<MENUITEM_ID>MENU_ID_MTV_SMS_SAVE_TO_SIM1</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_MTV_SMS_SAVE_TO_SIM2</MENUITEM_ID>	
		</MENU>	
	#endif

    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_READ">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_READ_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_UNREAD">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_UNREAD_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_SENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_SENT_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_UNSENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_UNSENT_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_SS_NCOMP">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_NCOMP_1.bmp"</IMAGE>

    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_READ">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_READ_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_UNREAD">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_UNREAD_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_SENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\SS_SENT_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_UNSENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\SS_UNSENT_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_SS_NCOMP">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_NCOMP_2.bmp"</IMAGE>

    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_SENDING">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\\SS_SENDING_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_WAITING">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\\SS_WAITING_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_MASTER_MESSAGE_FAILTOSENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\\SS_FAILTOSENT_1.bmp"</IMAGE>

    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_SENDING">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\\SS_SENDING_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_WAITING">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\\SS_WAITING_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MTV_SMS_SLAVE_MESSAGE_FAILTOSENT">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\\SS_FAILTOSENT_2.bmp"</IMAGE>


    <!-------------1 range-------------------------------------> 

    <!--------------Other Resource---------------------------------------------------------->
	<SCREEN id="SCR_ID_MTV_SMS_MAIN_MENU"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_LIST"/>
	<SCREEN id="SCR_ID_MTV_SMS_LIST_OPTIONS"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_VIEWER"/>
	<SCREEN id="SCR_ID_MTV_SMS_VIEWER_OPTIONS"/>	

	<SCREEN id="SCR_ID_MTV_SMS_EDITOR"/>
	<SCREEN id="SCR_ID_MTV_SMS_EDITOR_OPTIONS"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_READING"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_SENDING"/>
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_SEND_RESULT"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_SAVING"/>
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_SAVE_RESULT"/>
	
#ifdef __MMI_DUAL_SIM_MASTER__  	
	<SCREEN id="SCR_ID_MTV_SMS_SAVE_SIM_SELECTT"/>
	<SCREEN id="SCR_ID_MTV_SMS_SEND_SIM_SELECTT"/>
#endif

	<SCREEN id="SCR_ID_MTV_SMS_CONFIRM_DELETE"/>
	<SCREEN id="SCR_ID_MTV_SMS_CONFIRM_DELETE_ALL"/>
	<SCREEN id="SCR_ID_MTV_SMS_CONFIRM_DELETE_VIEWER"/>
	<SCREEN id="SCR_ID_MTV_SMS_CONFIRM_REMOVE"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_DELETE_RESULT"/>	
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING"/>
	
	<SCREEN id="SCR_ID_MTV_SMS_TEMPLATE_LIST"/>
	<SCREEN id="SCR_ID_MTV_SMS_RECIPIENT_EDITOR"/>
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_CANCELING"/>
	<SCREEN id="SCR_ID_MTV_SMS_TEMPLATE_LIST_SELECT"/>
	<SCREEN id="SCR_ID_MTV_SMS_POPUP_ID"/>

</APP>

#endif
