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
*  Profiles.res
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
*  Xudong Sun
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 11 23 2010 yaling.fang
 * [MAUI_02641796] [nvram]check in nvram xml
 * .
 *
 * Apr 13 2010 mtk80223
 * [MAUI_02178843] [Dict]Dictionary 10A check in
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#ifdef __MMI_DICTIONARY__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_DICTIONARY">
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="MainMenuDef.h"/>
    <INCLUDE file="GlobalResDef.h,SettingResDef.h,mmi_rp_srv_editor_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

	<STRING id="STR_DICTIONARY_TITLE"/>
	<STRING id="STR_DICTIONARY_SHOW_MEANING"/>
	<STRING id="STR_DICTIONARY_WILDCARD_SEARCH"/>
	<STRING id="STR_DICTIONARY_EXACT_SEARCH"/>
	<STRING id="STR_DICTIONARY_NO_MATCH_FOUND"/>
    <STRING id="STR_DICTIONARY_LANGUAGE_NOT_SUPPORTED"/>
    <STRING id="STR_DICTIONARY_TTS_SETTING"/>
    <STRING id="STR_DICTIOANRY_TTS_SPEAKING"/>
    <STRING id="STR_DICTIOANRY_TTS_SPEAK_SPEED"/>

    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

	<IMAGE id="IMG_DICTIONARY_EXTRA_MENU_SCREEN" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_ExtraList.bmp"</IMAGE>
	<IMAGE id="IMG_DICTIONARY_WORD_LIST_SCREEN" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_WordList.bmp"</IMAGE>
	<IMAGE id="IMG_DICTIONARY_SEARCH" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_WordListSearch.bmp"</IMAGE>
	<IMAGE id="IMG_DICTIONARY_WAIT" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_WordListWait.bmp"</IMAGE>

#ifdef __MMI_DICTIONARY_WELCOME_SCREEN__

	/* GV Logo*/
#if defined(__MMI_DICT_GV__)
	#if defined(__MMI_DICT_GVCN__)	/*Logo used in China*/
	<IMAGE id="IMG_DICTIONARY_LOGO" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_Logo_GVCN.gif"</IMAGE>
	#else		/*Logo used in Taiwan*/
	<IMAGE id="IMG_DICTIONARY_LOGO" >CUST_IMG_PATH"\\\\MainLCD\\\\Dictionary\\\\Dict_Logo_GV.gif"</IMAGE>
	#endif	
#endif

#endif

    <!-----------------------------------------------------Audio Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="EXTRA_DICTIONARY_MENU" str="STR_DICTIONARY_TITLE" 
              img="IMG_DICTIONARY_EXTRA_MENU_SCREEN" highlight="mmi_dictionary_main_menu_highlight_hdlr"/>
        
    <MENUITEM id="DICTIONARY_OPTION_SHOW_MEANING_MENU" str="STR_DICTIONARY_SHOW_MEANING"/>
              
#ifdef __MMI_DICTIONARY_WILDCARD_SEARCH__              
    <MENUITEM id="DICTIONARY_OPTION_WILDCARD_SEARCH_MENU" str="STR_DICTIONARY_WILDCARD_SEARCH"/>
#endif    

    <MENUITEM id="DICTIONARY_OPTION_EXACT_SEARCH_MENU" str="STR_DICTIONARY_EXACT_SEARCH"/>

#ifdef __MMI_DICTIONARY_TTS__
    <MENUITEM id="DICTIONARY_TTS_SETTING_ON_MENU" str="STR_GLOBAL_ACTIVATE" />
    <MENUITEM id="DICTIONARY_TTS_SETTING_OFF_MENU" str="STR_GLOBAL_DEACTIVATE" />

	<MENU id = "DICTIONARY_OPTION_TTS_SETTING_MENU" type = "APP_SUB" 
	      str = "STR_DICTIONARY_TTS_SETTING">
		<MENUITEM_ID>DICTIONARY_TTS_SETTING_ON_MENU</MENUITEM_ID>
		<MENUITEM_ID>DICTIONARY_TTS_SETTING_OFF_MENU</MENUITEM_ID>
	</MENU>
#endif

	<MENU id = "DICTIONARY_OPTION_MENU" type = "OPTION" 
	      str = "STR_GLOBAL_OPTIONS" img="MAIN_MENU_PROFILES_ICON" >
		<MENUITEM_ID>DICTIONARY_OPTION_SHOW_MEANING_MENU</MENUITEM_ID>
		<MENUITEM_ID>DICTIONARY_OPTION_WILDCARD_SEARCH_MENU</MENUITEM_ID>
		<MENUITEM_ID>DICTIONARY_OPTION_EXACT_SEARCH_MENU</MENUITEM_ID>
		<MENUITEM_ID>DICTIONARY_OPTION_TTS_SETTING_MENU</MENUITEM_ID>
		<MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
	</MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_DICTIONARY_MAIN"/>
    <SCREEN id="SCR_DICTIONARY_RESULT"/>
    <SCREEN id="SCR_DICTIONARY_OPTION"/>
    <SCREEN id="SCR_DICTIONARY_WILDCARD_EXACT_EDITOR"/>
    <SCREEN id="SCR_DICTIONARY_WILDCARD_RESULT_LIST"/>
    <SCREEN id="SCR_DICTIONARY_WELCOME_SCREEN"/>
    <SCREEN id="SCR_DICTIONARY_TTS_SETTING"/>
    
 <!------------------------------------------------------MMI Cache Item Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_DICTIANRY_TTS_ON_OFF">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DICTIANRY_TTS_SPEAK_SPEED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> E_dict setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DICTIANRY_TTS_SPEAK_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> E_dict setting </DESCRIPTION>
    </CACHEDATA>
    
</APP>

#endif

