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
*	vrsi.res
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   VRSI resource xml
*
* Author:
* -------
*   mtk80144
*
*==============================================================================
* HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 11 23 2010 yaling.fang
 * [MAUI_02641796] [nvram]check in nvram xml
 * .
 *
 * 11 01 2010 yaling.fang
 * [MAUI_02639242] [callback res] callback res change
 * .
 *
 * Jun 10 2010 mtk80144
 * [MAUI_02208583] [new feature] vrsi fte check in
 * 
 *
 * Jun 7 2010 mtk80144
 * [MAUI_02204873] [Know issue][NFST]in phonebook list press the lsk no responsed
 * 
 *
 * May 31 2010 mtk80144
 * [MAUI_02201950] [VRSI] check in FW10A
 * 
 *
 * May 31 2010 mtk80144
 * [MAUI_02201950] [VRSI] check in FW10A
 * 
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/


/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h" 
#ifdef __MMI_VRSI__

#include "CustResDef.h"         /* for image/audio path */



/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_VRSI">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="MainMenuDef.h,GlobalResDef.h,GlobalMenuItems.h,MMIDataType.h,VRSIResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
	/* Populate MediaPlayer String Start */
    <STRING id="STR_ID_VRSI_APP"/>
    <STRING id="STR_ID_VRSI_SETTING"/>
    <STRING id="STR_ID_VRSI_INIT_PROCESSING"/>
    <STRING id="STR_ID_VRSI_PROCESSING"/>
    <STRING id="STR_ID_VRSI_ENABLE_RCG"/>
    <STRING id="STR_ID_VRSI_DIGIT_ADAPT"/>
    <STRING id="STR_ID_VRSI_REDIAL_DIALED"/>
    <STRING id="STR_ID_VRSI_REDIAL_MISSED"/>
    <STRING id="STR_ID_VRSI_REDIAL_RECEIVED"/>
    <STRING id="STR_ID_VRSI_PROFILE_SILENT"/>
    <STRING id="STR_ID_VRSI_SHORTCUT_ITEM"/>
    <STRING id="STR_ID_VRSI_CITY_ITEM"/>
    /* Prompt String */
    <STRING id="STR_ID_VRSI_HELP_PROMPT"/>
    <STRING id="STR_ID_VRSI_GRAMMAR1_PROMPT"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE2"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE3"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE4"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_HOME"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_HOME2"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_HOME3"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE2"/>    
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE3"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_FAX"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_FAX2"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_FAX3"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_CANCEL"/>
    <STRING id="STR_ID_VRSI_GRAMMAR3_PROMPT"/>
    <STRING id="STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT"/>
    <STRING id="STR_ID_VRSI_GRAMMAR4_PROMPT"/>
    <STRING id="STR_ID_VRSI_DIGIT_PROMPT"/>
    <STRING id="STR_ID_VRSI_DIGIT_ADAPT_PROMPT"/>
    <STRING id="STR_ID_VRSI_TRAIN_TAG_PROMPT1"/>
    <STRING id="STR_ID_VRSI_TRAIN_TAG_PROMPT2"/>
    <STRING id="STR_ID_VRSI_DIAL_PROMPT"/>
    <STRING id="STR_ID_VRSI_DIALING_PROMPT"/>
    <STRING id="STR_ID_VRSI_TTS_INVALID_CMD"/>
    <STRING id="STR_ID_VRSI_TTS_OPERATE_BY_KEY"/>
    <STRING id="STR_ID_VRSI_TTS_RECORD"/>
    <STRING id="STR_ID_VRSI_TTS_RECORD_NO_DATA"/>
    <STRING id="STR_ID_VRSI_TTS_NUMBER_NO_DATA"/>
    <STRING id="STR_ID_VRSI_TTS_FOUND"/>
    <STRING id="STR_ID_VRSI_GRAMMAR5_PROMPT"/>
    <STRING id="STR_ID_VRSI_SPEAK_AGAIN_PROMPT"/>
    <STRING id="STR_ID_VRSI_NO_NUMBER_PROMPT"/>
    <STRING id="STR_ID_VRSI_SWITCHED_PROMPT"/>
    <STRING id="STR_ID_VRSI_CANT_SWITCH_PROMPT"/>
    <STRING id="STR_ID_VRSI_OPENING_PROMPT"/>
    <STRING id="STR_ID_VRSI_CITY_TIME"/>
    <STRING id="STR_ID_VRSI_CITY_TIME_AM"/>
    <STRING id="STR_ID_VRSI_CITY_TIME_PM"/>
    <STRING id="STR_ID_VRSI_CITY_TIME_HOUR"/>
    <STRING id="STR_ID_VRSI_CITY_TIME_MINUTE"/>
    <STRING id="STR_ID_VRSI_DELETE_ALL_QUESTION"/>
    <STRING id="STR_ID_VRSI_DELETE_QUESTION"/>
    <STRING id="STR_ID_VRSI_GRAMMAR2_PROMPT_"/>
    /* Error String */
    <STRING id="STR_ID_VRSI_INIT_FAIL"/>
    <STRING id="STR_ID_VRSI_LANG_NOT_SUPPORT"/>
    <STRING id="STR_ID_VRSI_DIAL_DIGIT_TOO_LONG"/>
    <STRING id="STR_ID_VRSI_NOT_READY"/>
    <STRING id="STR_ID_VRSI_RCG_NOT_FOUND"/>
    <STRING id="STR_ID_VRSI_SD_TAG_FULL"/>
    <STRING id="STR_ID_VRSI_BUSY"/>
    <STRING id="STR_ID_VRSI_ALREADY_IN_MODE"/>
    <STRING id="STR_ID_VRSI_DEMO_ERROR"/>
    /* Traing String */
    <STRING id="STR_ID_VRSI_TRAIN_TAG"/>
    <STRING id="STR_ID_VRSI_NAME_LIST"/>
    <STRING id="STR_ID_VRSI_DAIL_LIST"/>
    <STRING id="STR_ID_VRSI_SHORTCUT_LIST"/>
    <STRING id="STR_ID_VRSI_CITY_LIST"/>
    <STRING id="STR_ID_VRSI_TRAIN_TAG_STATUS"/>
    <STRING id="STR_ID_VRSI_PLAYBACK"/>
    <STRING id="STR_ID_VRSI_REFRESH_SIM"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <IMAGE id="IMG_ID_VRSI_APP" >CUST_IMG_PATH"\\\\MainLCD\\\\VoiceRecg\\\\SB_Speak.bmp"</IMAGE>
   	<IMAGE id="IMG_ID_VRSI_RECORDING" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\Speaking"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    <IMAGE id="IMG_ID_VRSI_SHORTCUT" >CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Shortcut\\\\SB_SC.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VRSI_SIM" >CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_INSIM.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VRSI_PHONE" >CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_INPH.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VRSI_SIM1" >CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_CHOOSE_CARD1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VRSI_SIM2" >CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_CHOOSE_CARD2.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

/******************************************** app menu under main menu ***********************************************/
    <MENU id="MENU_ID_VRSI_SETTING" type= "APP_MAIN" str= "STR_ID_VRSI_SETTING" img = "IMG_ID_VRSI_APP" highlight = "mmi_vrsi_highlight_setting_menu"/>

    
/*VRSI Setting Sub Main Item*/
<MENUITEM id="MENU_ID_VRSI_TRAIN_NAME_LIST" str = "STR_ID_VRSI_NAME_LIST" img = "IMG_GLOBAL_OK"/>
<MENUITEM id="MENU_ID_VRSI_TRAIN_SHORTCUT_LIST" str= "STR_ID_VRSI_SHORTCUT_LIST" img = "IMG_GLOBAL_OK"/>
<MENUITEM id="MENU_ID_VRSI_TRAIN_CITY_LIST" str ="STR_ID_VRSI_CITY_LIST" img="IMG_GLOBAL_OK"/>
<MENUITEM id="MENU_ID_VRSI_TRAIN_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" img = "IMG_GLOBAL_OK"/>
<MENUITEM id="MENU_ID_VRSI_TRAIN_TAG_STATUS" str="STR_ID_VRSI_TRAIN_TAG_STATUS" img="IMG_GLOBAL_OK"/>
<MENU id="MENU_ID_VRSI_SETTING_TRAIN_TAG" type = "APP_SUB" str="STR_ID_VRSI_TRAIN_TAG">
     <MENUITEM_ID>MENU_ID_VRSI_TRAIN_NAME_LIST</MENUITEM_ID>
     <MENUITEM_ID>MENU_ID_VRSI_TRAIN_SHORTCUT_LIST</MENUITEM_ID>
     <MENUITEM_ID>MENU_ID_VRSI_TRAIN_CITY_LIST</MENUITEM_ID>
     <MENUITEM_ID>MENU_ID_VRSI_TRAIN_DELETE_ALL</MENUITEM_ID>
     <MENUITEM_ID>MENU_ID_VRSI_TRAIN_TAG_STATUS</MENUITEM_ID>
</MENU>  


    /*VRSI Setting Main Menu*/
    <MENUITEM id="MENU_ID_VRSI_SETTING_RCG" str="STR_ID_VRSI_ENABLE_RCG" img="IMG_GLOBAL_OK"/>
    #ifdef __MMI_VRSI_DIGIT_ADAPT__ 
    <MENUITEM id="MENU_ID_VRSI_SETTING_DIGIT_ADAPT" str="STR_ID_VRSI_DIGIT_ADAPT" img="IMG_GLOBAL_OK"/>
    #endif
    <MENU id="MENU_ID_VRSI_SETTING_MAIN" type = "APP_SUB" str="STR_ID_VRSI_SETTING">
         <MENUITEM_ID>MENU_ID_VRSI_SETTING_RCG</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_VRSI_SETTING_TRAIN_TAG</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_VRSI_SETTING_DIGIT_ADAPT</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_VRSI_TRAIN_OPTION_ADD" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_VRSI_TRAIN_OPTION_DEL" str="STR_GLOBAL_DELETE" />
    <MENUITEM id="MENU_ID_VRSI_TRAIN_OPTION_PLAY" str="STR_ID_VRSI_PLAYBACK" />
    <MENU id="MENU_ID_VRSI_TRAIN_OPTION_MAIN" type = "APP_SUB">
         <MENUITEM_ID>MENU_ID_VRSI_TRAIN_OPTION_ADD</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_VRSI_TRAIN_OPTION_DEL</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_VRSI_TRAIN_OPTION_PLAY</MENUITEM_ID>
    </MENU>   
        
    
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_VRSI_SETTING_MENU"/>
    <SCREEN id="GRP_ID_VRSI_SETTING_MENU"/>
    <SCREEN id="GRP_ID_VRSI"/>
    <SCREEN id="GRP_ID_VRSI_RCG_MAIN"/>
    <SCREEN id="SCR_ID_VRSI_RCG_MAIN"/>
    <SCREEN id="SCR_ID_VRSI_INIT_PROCESSING"/>
    <SCREEN id="SCR_ID_VRSI_HELP"/>
    <SCREEN id="SCR_ID_VRSI_DIGIT_DIAL_MAIN"/>
    <SCREEN id="SCR_ID_VRSI_DIGIT_DIAL_CONFIRM"/>
    <SCREEN id="SCR_ID_VRSI_DIGIT_DIAL_CONFIRM_IN_HISTORY"/>
    <SCREEN id="SCR_ID_VRSI_DIGIT_ADAPT"/>
    <SCREEN id="GRP_ID_VRSI_DIGIT_ADAPT"/>
    <SCREEN id="SCR_ID_VRSI_DIGIT_ADAPT_PROMPT"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_TAG_MAIN"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_TAG_MAIN"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_OPTION_MAIN"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_OPTION_MAIN"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_PHB_LIST"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_PHB_LIST"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_SHORTCUT_LIST"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_SHORTCUT_LIST"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_CITY_LIST"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_CITY_LIST"/>
    <SCREEN id="SCR_ID_VRSI_TRAIN_TAG_STATUS"/>
    <SCREEN id="GRP_ID_VRSI_TRAIN_TAG_STATUS"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_CONFIRM"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_CONFIRM_IN_HISTORY"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_MULTI_NUM"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_MULTI_NUM_IN_HISTORY"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD"/>
    <SCREEN id="SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD_IN_HISTORY"/>
    <SCREEN id="SCR_ID_VRSI_NAME_QUERY_LIST1"/>
    <SCREEN id="GRP_ID_VRSI_NAME_QUERY_LIST1"/>
    <SCREEN id="GRP_ID_VRSI_SET_CITY"/>
    <SCREEN id="SCR_ID_VRSI_REDIAL_PROMPT"/>
    <SCREEN id="SCR_ID_VRSI_SWITCH_PROFILE_PROMPT"/>
    <SCREEN id="SCR_ID_VRSI_OPEN_SCUT_PROMPT"/>
   
 <!------------------------------------------------------MMI Cache Item Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_VRSI_RCG_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VRSI setting </DESCRIPTION>
    </CACHEDATA>
   
	#ifdef __MMI_VRSI__
	<RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="mmi_vrsi_phb_evt_hdlr"/>
	#endif

        #ifdef __MMI_VRSI__
	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="mmi_vrsi_phb_evt_hdlr"/>
	#endif

    	
	#if defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__)
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="mmi_vrsi_phb_evt_hdlr"/>
	#endif
    
</APP>
#endif
