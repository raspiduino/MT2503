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
 *   worldclock.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file for world clock
 *
 * Author:
 * -------
 *   Wen Wu(MTK80153)
 *
 *******************************************************************************/

#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_WORLDCLOCK"
    #if defined (__MMI_APP_MANAGER_SUPPORT__) && defined (__MMI_WORLD_CLOCK__)
    package_name="native.mtk.worldclock"
    name="STR_WORLD_CLOCK_TITLE"
    #if defined (__MMI_VUI_LAUNCHER__) || defined (__MMI_MAINMENU_SPREAD_SUPPORT__)
		img="IMG_ID_MAINMENU_WORLD_CLOCK"
		#endif
    launch="mmi_world_clock_launch"
    #endif
    >
    <CACHEDATA type="byte" id="CURRENT_CITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Current home city </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="FOREIGN_CITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Current foreign city </DESCRIPTION>
    </CACHEDATA>
    
     <CACHEDATA type="byte" id="NVRAM_SETTING_DT_DST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Current  home city daylight saving </DESCRIPTION>
        <FIELD>
           <OPTION hint="OFF"> [0x00] </OPTION>
	       <OPTION hint="ON">  [0x01] </OPTION>
	    </FIELD>    
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_TIMEZONE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Current time zone value </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_WC_DST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Current foreign city daylight saving </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FRN_TIMEZONE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> current foreign city time zone </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_DOWNLOAD_CITY1" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> sub lcd city 1 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DOWNLOAD_CITY2" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> sub lcd city 2 </DESCRIPTION>
    </CACHEDATA>
    <!--Include Area-->
    #ifdef __MMI_TIMEZONE_SETTING__
    <INCLUDE file="GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_WCLOCK_CITY_NONE"/>
    <STRING id="STR_WCLOCK_CITY1"/>
    <STRING id="STR_WCLOCK_CITY2"/>
    <STRING id="STR_WCLOCK_CITY3"/>
    <STRING id="STR_WCLOCK_CITY4"/>
    <STRING id="STR_WCLOCK_CITY5"/>
    <STRING id="STR_WCLOCK_CITY6"/>
    <STRING id="STR_WCLOCK_CITY7"/>
    <STRING id="STR_WCLOCK_CITY8"/>
    <STRING id="STR_WCLOCK_CITY9"/>
    <STRING id="STR_WCLOCK_CITY10"/>
    <STRING id="STR_WCLOCK_CITY11"/>
    <STRING id="STR_WCLOCK_CITY12"/>
    <STRING id="STR_WCLOCK_CITY13"/>
    <STRING id="STR_WCLOCK_CITY14"/>
    <STRING id="STR_WCLOCK_CITY15"/>
    <STRING id="STR_WCLOCK_CITY16"/>
    <STRING id="STR_WCLOCK_CITY17"/>
    <STRING id="STR_WCLOCK_CITY18"/>
    <STRING id="STR_WCLOCK_CITY19"/>
    <STRING id="STR_WCLOCK_CITY20"/>
    <STRING id="STR_WCLOCK_CITY21"/>
    <STRING id="STR_WCLOCK_CITY22"/>
    <STRING id="STR_WCLOCK_CITY23"/>
    <STRING id="STR_WCLOCK_CITY24"/>
    <STRING id="STR_WCLOCK_CITY25"/>
    <STRING id="STR_WCLOCK_CITY26"/>
    <STRING id="STR_WCLOCK_CITY27"/>
    <STRING id="STR_WCLOCK_CITY28"/>
    <STRING id="STR_WCLOCK_CITY29"/>
    <STRING id="STR_WCLOCK_CITY30"/>
    <STRING id="STR_WCLOCK_CITY31"/>
    <STRING id="STR_WCLOCK_CITY32"/>
    <STRING id="STR_WCLOCK_CITY33"/>
    <STRING id="STR_WCLOCK_CITY34"/>
    <STRING id="STR_WCLOCK_CITY35"/>
    <STRING id="STR_WCLOCK_CITY36"/>
    <STRING id="STR_WCLOCK_CITY37"/>
    <STRING id="STR_WCLOCK_CITY38"/>
    <STRING id="STR_WCLOCK_CITY39"/>
    <STRING id="STR_WCLOCK_CITY40"/>
    <STRING id="STR_WCLOCK_CITY41"/>
    <STRING id="STR_WCLOCK_CITY42"/>
    <STRING id="STR_WCLOCK_CITY43"/>
    <STRING id="STR_WCLOCK_CITY44"/>
    <STRING id="STR_WCLOCK_CITY45"/>
    <STRING id="STR_WCLOCK_CITY46"/>
    <STRING id="STR_WCLOCK_CITY47"/>
    <STRING id="STR_WCLOCK_CITY48"/>
    <STRING id="STR_WCLOCK_CITY49"/>
    <STRING id="STR_WCLOCK_CITY50"/>
    <STRING id="STR_WCLOCK_CITY51"/>
    <STRING id="STR_WCLOCK_CITY52"/>
    <STRING id="STR_WCLOCK_CITY53"/>
    <STRING id="STR_WCLOCK_CITY54"/>
    <STRING id="STR_WCLOCK_CITY55"/>
    <STRING id="STR_WCLOCK_CITY56"/>
    <STRING id="STR_WCLOCK_CITY57"/>
    <STRING id="STR_WCLOCK_CITY58"/>
    <STRING id="STR_WCLOCK_CITY59"/>
    <STRING id="STR_WCLOCK_CITY60"/>
    <STRING id="STR_WCLOCK_CITY61"/>
    <STRING id="STR_WCLOCK_CITY62"/>
    <STRING id="STR_WCLOCK_CITY63"/>
    <STRING id="STR_WCLOCK_CITY64"/>
    <STRING id="STR_WCLOCK_CITY65"/>
    <STRING id="STR_WCLOCK_CITY66"/>
    <STRING id="STR_WCLOCK_CITY67"/>
    <STRING id="STR_WCLOCK_CITY68"/>
    <STRING id="STR_WCLOCK_CITY69"/>
    <STRING id="STR_WCLOCK_CITY70"/>
    <STRING id="STR_WCLOCK_CITY71"/>
    <STRING id="STR_WCLOCK_CITY72"/>
    <STRING id="STR_WCLOCK_CITY73"/>
    <STRING id="STR_WCLOCK_CITY74"/>
    <STRING id="STR_WCLOCK_CITY75"/>
    <STRING id="STR_WCLOCK_CITY76"/>
    <STRING id="STR_WCLOCK_CITY77"/>
    <STRING id="STR_WCLOCK_CITY78"/>
    <STRING id="STR_TOTAL_NUM_CITY"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE_NONE"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE1"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE1"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE2"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE3"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE4"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE5"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE6"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE7"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE8"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE9"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE10"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE11"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE12"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE13"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE14"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE15"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE16"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE17"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE18"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE19"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE20"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE21"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE22"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE23"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE24"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE25"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE26"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE27"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE28"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE29"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE30"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE31"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE32"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE33"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE34"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE35"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE36"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE37"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE38"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE39"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE40"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE41"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE42"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE43"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE44"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE45"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE46"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE47"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE48"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE49"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE50"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE51"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE52"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE53"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE54"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE55"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE56"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE57"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE58"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE59"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE60"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE61"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE62"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE63"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE64"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE65"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE66"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE67"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE68"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE69"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE70"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE71"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE72"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE73"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE74"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE75"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE76"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE77"/>
    <STRING id="STR_WCLOCK_CITY_ABBRE78"/>

     /* The uppper string can be used when world clock doesn't exit*/
     #endif
#ifdef __MMI_WORLD_CLOCK__

    <STRING id="STR_WORLD_CLOCK_TITLE"/>
#ifdef __MMI_WORLD_CLOCK_SUBLCD_SETTING__
    <STRING id="STR_WORLD_CLOCK_MENU2"/>
    <STRING id="STR_WORLD_CLOCK_CITY1"/>
    <STRING id="STR_WORLD_CLOCK_CITY2"/>
    <STRING id="STR_WORLD_SELECT_CITY"/>
#endif /* __MMI_WORLD_CLOCK_SUBLCD_SETTING__ */

    <STRING id="STR_WORLD_CLOCK_DST_FOREIGN"/>

#ifdef __MMI_WC_TZ_SUPPORT__
    <STRING id="STR_WORLD_CLOCK_LOCAL"/>
    <STRING id="STR_WORLD_CLOCK_GMT"/>    
#endif /* __MMI_WC_TZ_SUPPORT__ */
    <STRING id="ORGANIZER_MENU_WORLDCLOCK_STRINGID"/>

#endif /* __MMI_WORLD_CLOCK__ */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if 0
    /* Some other AP use this icon */
 #ifdef __FTE_NON_SLIM_RES__
 	<IMAGE id="SUN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\DAY.png"</IMAGE>
 #else
    <IMAGE id="SUN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\DAY.bmp"</IMAGE>
 #endif
#endif
#ifdef __MMI_WORLD_CLOCK__
#ifndef __MMI_WC_TZ_SUPPORT__
    <IMAGE id="SUN_ICON2">CUST_IMG_PATH"\\\\MainLCD\\\\Worldclock\\\\DAY.bmp"</IMAGE>
    <IMAGE id="MOON_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\NIGHT.bmp"</IMAGE>
#endif

    #ifdef __MMI_APP_MANAGER_SUPPORT__
    #if defined (__MMI_VUI_LAUNCHER__) || defined (__MMI_MAINMENU_SPREAD_SUPPORT__)
    <IMAGE id="IMG_ID_MAINMENU_WORLD_CLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\WorldClock.PNG"</IMAGE>
    #endif
    #endif
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_MAINLCD_128X160__
    <IMAGE id="WORLD_CLOCK_IMAGE1">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\touch\\\\map01.gif"</IMAGE>
#else
    <IMAGE id="WORLD_CLOCK_IMAGE1">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\map01.gif"</IMAGE>
#endif
#ifndef __MMI_WC_TZ_SUPPORT__
    <IMAGE id="WORLD_CLOCK_LEFT_ARROW_UP">CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WUpL.bmp"</IMAGE>
    <IMAGE id="WORLD_CLOCK_LEFT_ARROW_DOWN">CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDownL.bmp"</IMAGE>
    <IMAGE id="WORLD_CLOCK_RIGHT_ARROW_UP">CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDUpR.bmp"</IMAGE>
    <IMAGE id="WORLD_CLOCK_RIGHT_ARROW_DOWN">CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDownR.bmp"</IMAGE>
#endif /* __MMI_WC_TZ_SUPPORT__ */
#else /* __MMI_TOUCH_SCREEN__ */
    <IMAGE id="WORLD_CLOCK_IMAGE1">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\map01.gif"</IMAGE>
    <IMAGE id="WORLD_CLOCK_IMAGE2">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\map02.gif"</IMAGE>
    <IMAGE id="WORLD_CLOCK_IMAGE3">CUST_IMG_PATH"\\\\MainLCD\\\\WorldClock\\\\map03.gif"</IMAGE>

#endif /* __MMI_TOUCH_SCREEN__ */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

#ifdef __MMI_OP12_MENU_12MATRIX__
     <MENU id="ORGANIZER_WORLDCLOCK_MENU" 
     	   type="APP_MAIN" 
     	   str="ORGANIZER_MENU_WORLDCLOCK_STRINGID" 
     	   highlight="HighlightWCMenu">
#else
	<MENU id="ORGANIZER_WORLDCLOCK_MENU" 
		  type="APP_MAIN" 
		  str="ORGANIZER_MENU_WORLDCLOCK_STRINGID" 
		  highlight="HighlightWCMenu"
		  shortcut="ON" launch="EntryWcBrowseCity">
#endif
		<MENUITEM id="MITEM_WORLDCLOCK_BROWSECITY" str="STR_WORLD_CLOCK_TITLE" highlight="HighlightWcBrowseCity"></MENUITEM>
#ifdef __MMI_WORLD_CLOCK_SUBLCD_SETTING__
         <MENU id="MITEM_WORLDCLOCK_SUBLCDDISPLAY" type="APP_SUB" str="STR_WORLD_CLOCK_MENU2" highlight="HighlightWcSubLcd">
             <MENUITEM id="MITEM_WORLDCLOCK_SUBLCDDISPLAY_CITY1" str="STR_WORLD_CLOCK_CITY1" hint="WcHintCity1"></MENUITEM>
             <MENUITEM id="MITEM_WORLDCLOCK_SUBLCDDISPLAY_CITY2" str="STR_WORLD_CLOCK_CITY2" hint="WcHintCity2"></MENUITEM>
         </MENU>
#endif
     </MENU>

    <MENU id="MENU_ID_WC_DST_OPT" type="APP_OPTION" str="STR_WORLD_CLOCK_DST_FOREIGN">
       <MENUITEM id="MENU_ID_WC_DST_SETTING" str="STR_WORLD_CLOCK_DST_FOREIGN"></MENUITEM>
    </MENU>
    
    <MENU id="MENU_ID_WC_DST_CFG_OPT" type="APP_OPTION">
       <MENUITEM id="MENU_ID_WC_DST_CFG_ON"></MENUITEM>
       <MENUITEM id="MENU_ID_WC_DST_CFG_OFF"></MENUITEM>
    </MENU>  
   
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_WC"/>
    <SCREEN id="GRP_ID_WC_SUB_LCD"/>
    <SCREEN id="GRP_ID_WC_SELECT"/>
    <SCREEN id="GRP_ID_WC_DST"/>    
    <SCREEN id="SCR_ID_WC_BROWSE_CITY"/>
    <SCREEN id="SCR_ID_WC_APP"/>
    <SCREEN id="SCR_ID_WC_OPTIONS"/>
    <SCREEN id="SCR_ID_WC_DST"/>
    <SCREEN id="SCR_ID_WC_TOTAL"/>

#endif /* __MMI_WORLD_CLOCK__ */

</APP>

