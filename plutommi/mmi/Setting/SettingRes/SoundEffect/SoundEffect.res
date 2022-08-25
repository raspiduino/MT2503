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
 * SoundEffect.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Sound effect resource file with XML format.   
 *
 * Author:
 * -------
 *   Kinse Lin
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 11 26 2010 kinse.lin
 * [MAUI_02832467] [NVRAM] apply new mmi cache mechanism
 * .
 *
 * 11 23 2010 kinse.lin
 * [MAUI_02832467] [NVRAM] apply new mmi cache mechanism
 * .
 *
 * 10 28 2010 kinse.lin
 * [MAUI_02832467] [NVRAM] apply new mmi cache mechanism
 * .
 *
 * 09 15 2010 kinse.lin
 * [MAUI_02620681] [Sound Effect] adopt new resource gen and remove from Setting Reousce
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SOUND_EFFECT__
#include "CustResDef.h"         /* for image/audio path */


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_SOUNDEFFECT">
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_SETTING_SOUND_EFFECT"/>
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    <STRING id="STR_ID_SETTING_BASS_ENHANCEMENT"/>
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    <STRING id="STR_ID_SETTING_AUDIO_EFFECT"/>
#endif
#if defined(__MMI_AUDIO_SURROUND_EFFECT__) && defined(__MMI_AUDIO_REVERB_EFFECT__)
    <STRING id="STR_ID_SETTING_AUDIO_EFFECT_NO_COEXIST"/>
#endif

#ifdef __MMI_AUDIO_EQUALIZER__
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_1"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_2"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_3"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_4"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_5"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_6"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_7"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SET_8"/>
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SETTIN_NAME_EDIT_TITLE"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_SETTING_INVALID_NAME"/>
    <STRING id="STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT_CONFIRM"/>
#endif
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5"/>
    <STRING id="STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6"/>
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    <STRING id="STR_ID_SETTING_AUDIO_SURROUND_EFFECT"/>
    <STRING id="STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE"/>
    <STRING id="STR_ID_SETTING_AUDIO_SURROUND_MODE1"/>
    <STRING id="STR_ID_SETTING_AUDIO_SURROUND_MODE2"/>
#endif


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_SETTING_SOUND_EFFECT">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SNDEFT.bmp"</IMAGE>
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    <IMAGE id="IMG_ID_SETTING_BASS_ENHANCEMENT">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SoundEffect\\\\ST_SUPER_BASS.bmp"</IMAGE>
#endif
    //<IMAGE id="IMG_ID_SETTING_AUDIO_EQUALIZER">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SoundEffect\\\\ST_AUDIO_EQ.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SETTING_AUDIO_REVERB_EFFECT">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SoundEffect\\\\ST_AUDIO_REVERB.bmp"</IMAGE>
    //<IMAGE id="IMG_ID_SETTING_AUDIO_SURROUND_EFFECT">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SoundEffect\\\\ST_AUDIO_3D.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    <MENUITEM id="MNEU_SETTING_BASS_ENHANCEMENT" str="STR_ID_SETTING_BASS_ENHANCEMENT" img="IMG_ID_SETTING_BASS_ENHANCEMENT"/>
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    <MENUITEM id="MENU_SETTING_AUDIO_EFFECT" str="STR_ID_SETTING_AUDIO_EFFECT" img="IMG_ID_SETTING_AUDIO_REVERB_EFFECT"/>

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__

    <MENUITEM id="MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_SELECT" str="STR_GLOBAL_SELECT"/>
    <MENUITEM id="MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RENAME" str="STR_GLOBAL_RENAME"/>
    <MENUITEM id="MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RESET" str="STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT"/>

    <MENU id="MENU_SETTING_AUDIO_EQUALIZER_SET_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS"> 
        <MENUITEM_ID>MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_SELECT</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_EDIT</MENUITEM_ID> 
        <MENUITEM_ID>MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RESET</MENUITEM_ID>
    </MENU>
#endif

#endif

    <MENU id="MENU_SETTING_SOUND_EFFECT" type="OPTION" str="STR_ID_SETTING_SOUND_EFFECT" img = "IMG_ID_SETTING_SOUND_EFFECT" highlight="mmi_settings_sound_effect_highlight_hdlr">
        <MENUITEM_ID>MENU_SETTING_AUDIO_EFFECT</MENUITEM_ID>
        <MENUITEM_ID>MNEU_SETTING_BASS_ENHANCEMENT</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <SCREEN id="GRP_ID_SETTING_SOUND_EFFECT"/>
    <SCREEN id="SCR_ID_SETTING_SOUND_EFFECT"/>
    <SCREEN id="GRP_ID_SETTING_AUDIO_EFFECT"/>
    <SCREEN id="SCR_ID_SETTING_AUDIO_EFFECT"/>
    <SCREEN id="SCR_ID_SETTING_BASS_ENHANCEMENT"/>
    <SCREEN id="SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS"/> 
    <SCREEN id="SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT"/> 
    <SCREEN id="SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT"/>
    <SCREEN id="SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION"/>

    <CACHEDATA type="byte" id="NVRAM_BYTE_AUDIO_REVERB_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Sound effects </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_AUDIO_SURROUND_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Sound effects </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_AUDIO_EFFECT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Sound effects </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_AUDIO_BASS_ENHANCEMENT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Sound effects </DESCRIPTION>
    </CACHEDATA>

//    <CACHEDATA type="short" id="NVRAM_AUDIO_MIC_VOLUME_SET" restore_flag="TRUE">
//        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
//        <DESCRIPTION> Sound effects </DESCRIPTION>
//    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_EDITABLE_EQ_RENAME_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Sound effects </DESCRIPTION>
    </CACHEDATA>

</APP>
#endif

