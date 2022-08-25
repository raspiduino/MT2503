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
 * FactoryMode.Res
 *
 * Project:
 * --------
 *   PlutoMMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 23 2013 yuan.yin
 * [MAUI_03463891] [Pluto Slim Phase3 IT Test] [11BW1332OF_6260Slim_Dev][Free test][Factory mode]can't enter the menu
 * FM enter sw version invalidate modification.
 *
 * 10 21 2013 yuan.yin
 * [MAUI_03463593] Screen Group patch back to 11C
 * EM FM Slim.
 *
 * 01 31 2013 yuan.yin
 * [MAUI_03322007] [SWPL Approved][MT6260]3-in-1 current sensor
 * .
 *
 * 01 04 2013 yuan.yin
 * [MAUI_03299111] Pluto Cosmos SG EM FM Slim
 * .
 *
 * 12 25 2012 yuan.yin
 * [MAUI_03299111] Pluto Cosmos SG EM FM Slim
 * .
 *
 * 12 04 2012 yuan.yin
 * [MAUI_03282750] FM Slim
 * .
 *
 * 12 02 2012 xiufeng.zhang
 * [MAUI_03280715] [EM][FM] Remove the unused strings
 * .
 *
 * 11 29 2012 xiufeng.zhang
 * [MAUI_03278229] [EM][FM] patch 11BW1232OF_SLIM_DEV back to 11B branch
 * .
 *
 * 06 26 2012 feng.yang
 * [MAUI_03207588] [FM Request][Phase Out] Phase out FM->Charger
 * .
 *
 * 06 18 2012 mengmeng.cao
 * [MAUI_03201196] Log In option shown at wrong position in the options menu
 * .build error
 *
 * 06 18 2012 mengmeng.cao
 * [MAUI_03201196] Log In option shown at wrong position in the options menu
 * .add dual touch
 *
 * 04 18 2012 feng.yang
 * [MAUI_03170814] [EMFM]Move timer to module own res file
 * .
 *
 * 03 26 2012 mengmeng.cao
 * [MAUI_03065523] [FM Request] 2-mic NR test mode
 * .
 *
 * 03 16 2012 feng.yang
 * [MAUI_03150467] [FM][1] Fatal Error (0xb03, 0x1196e9) - TIMER_HI
 * .
 *
 * 02 29 2012 feng.yang
 * [MAUI_03139117] [G-sensor]mCube support calibration check in
 * .
 *
 * 02 22 2012 feng.yang
 * [MAUI_03135149] [Sensor service]mCube motion sensor porting support
 * .
 *
 * 02 07 2012 mengmeng.cao
 * [MAUI_03099337] [EM Request] Internal speaker amp over current detection
 * .
 *
 * 02 07 2012 mengmeng.cao
 * [MAUI_03122613] other branches about MAUI_03122473 11BW1144SP.W12.05 MoDIS error for CHAMPAGNE55N_DEMO_gprs(FTE_HVGA_TCARD)
 * .
 *
 * 11 02 2011 feng.yang
 * [MAUI_03058415] [HAL Rule 5]: Non-HAL MUST NOT refer to HAL private stuffs![MAUI.11B.W11.41]
 * .
 *
 * 10 24 2011 chuangjie.xia
 * [MAUI_03061624] [EMFM]remove stop button when show progress for some case
 * .
 *
 * 09 01 2011 chuangjie.xia
 * [MAUI_03018206] [MAUI][TRUNK 11B][NFC]add NFC project
 * .
 *
 * 08 30 2011 yiping.xie
 * [MAUI_03015969] [FM-Camera] fm camera for LGE check in
 * .
 *
 * 08 23 2011 feng.yang
 * [MAUI_03011284] [FM 2.0]Fix daily build error for FM camera preview
 * .
 *
 * 08 10 2011 feng.yang
 * [MAUI_03003122] [FM SLIM]Add compile option on Melody version
 * .
 *
 * 08 03 2011 feng.yang
 * [MAUI_02997940] Fix daliy build error
 * .
 *
 * 08 03 2011 feng.yang
 * [MAUI_02993968] [FM] Run to UART ,press Send key, can not Re-do UART test
 * .
 *
 * 07 27 2011 feng.yang
 * [MAUI_02993465] Phase out FM Radio channel1,2 from FM and modify loopback
 * .
 *
 * 07 25 2011 feng.yang
 * [MAUI_02991177] Add compile option in factorymode.res
 * .
 *
 * 07 23 2011 feng.yang
 * [MAUI_02990772] [FM2.0]Check in PXS and dual mic
 * .
 *
 * 07 15 2011 feng.yang
 * [MAUI_02985042] FM SLIM enhance
 * .
 *
 * 07 04 2011 feng.yang
 * [MAUI_02976309] Fix FM silm Fatal Error (4, 1740ec) - MMI
 * .
 *
 * 06 30 2011 feng.yang
 * [MAUI_02974605] remove frm history code and remove old str
 * .
 *
 * 06 27 2011 feng.yang
 * [MAUI_02966570] [VT] Fatal Error (431, 9f) - DRVHISR
 * .
 *
 * 06 24 2011 feng.yang
 * [MAUI_02970061] FM2.0_SLIM and move EM auto_test_setting into FM
 * .
 *
 * 06 23 2011 feng.yang
 * [MAUI_02970061] FM2.0_SLIM and move EM auto_test_setting into FM
 * .
 *
 * 03 31 2011 kefeng.lian
 * [MAUI_02658703] [EM Request] [Phase Out] Phase out FM->LCD Contract
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if 0

#include "MMI_features.h"
#include "FactoryModeUtil.h"
#include "custresdef.h"
#include "SettingDefs.h"                // FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS



<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_FACTORYMODE_RES">

#ifdef __MMI_FM_LCD_CONTRAST__

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_CONTRAST_LEVEL" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_CONTRAST_MAINLCD_LEVEL_VALUE] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_FM_LCD_CONTRAST__ */

</APP>

#endif



#include "MMI_features.h"            
#include "custresdef.h"
#ifdef __MMI_FACTORY_MODE__




<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_FACTORYMODE">
    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "SettingDefs.h"/>   // FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS
    <INCLUDE file = "custresdef.h"/>
    
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_FM_ROOT"/>
    <STRING id = "STR_ID_FM_VERSION"/>
    <STRING id = "STR_ID_FM_BBCHIP_VER"/>
    <STRING id = "STR_ID_FM_DSPCODE_VER"/>
    <STRING id = "STR_ID_FM_DSPATCH_VER"/>
    
    /* Lisen 0921 */
    <STRING id = "STR_ID_FM_SW_SUMMARY"/>
    <STRING id = "STR_ID_FM_SW_VER"/>

#ifdef __MMI_FM_RES_BIN__
    <STRING id = "STR_ID_FM_RESOURCE_BIN"/>
    <STRING id = "STR_ID_FM_RESOURCE_LANGPACK"/>
    <STRING id = "STR_ID_FM_RESOURCE_CUSTPACK"/>
#endif


    <STRING id = "STR_ID_FM_HW_VER"/>
    
#ifdef __MMI_FM_MELODY_VERSION__
    <STRING id = "STR_ID_FM_MELODY_VER"/>
#endif

    <STRING id = "STR_ID_FM_ISN"/>
    

    <STRING id = "STR_ID_FM_BUILD_TIME"/>


    <STRING id = "STR_ID_FM_LED"/>
    <STRING id = "STR_ID_FM_LED_MAIN"/>
    #ifdef __MMI_SUBLCD__
        <STRING id = "STR_ID_FM_LED_SUB"/>
    #endif
    <STRING id = "STR_ID_FM_LED_KEYPAD"/>
    #ifndef __MMI_HIDE_STATUS_LED_R__    
        <STRING id = "STR_ID_FM_LED_STATUS_R"/>
    #endif
    #ifndef __MMI_HIDE_STATUS_LED_G__    
        <STRING id = "STR_ID_FM_LED_STATUS_G"/>
    #endif
    #ifndef __MMI_HIDE_STATUS_LED_B__    
        <STRING id = "STR_ID_FM_LED_STATUS_B"/>
    #endif
    <STRING id = "STR_ID_FM_LCD"/>

#ifdef __MMI_FM_KEYPAD_TEST__
    <STRING id = "STR_ID_FM_KEYPAD"/>
#endif


    <STRING id = "STR_ID_FM_LOUDSPK"/>
    <STRING id = "STR_ID_FM_LOUDSPK_AMP_OVER_CURRENT_DETECTION"/>
    <STRING id = "STR_ID_FM_EACHLOOP"/>
    
#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__    
    <STRING id = "STR_ID_FM_EACHLOOP2"/>
    <STRING id = "STR_ID_FM_2MICNR_TEST"/>
    <STRING id = "STR_ID_FM_DISABLE_2_MIC_NR_TEST"/>
#endif
    
    <STRING id = "STR_ID_FM_VIBRATOR"/>
    <STRING id = "STR_ID_FM_VIBRATOR_3_1_FIRST"/>
    <STRING id = "STR_ID_FM_VIBRATOR_3_1_SECOND"/>
    <STRING id = "STR_ID_FM_ADC"/>
    <STRING id = "STR_ID_FM_RECEIVER"/>
    <STRING id = "STR_ID_FM_HEADSET"/>
    #ifdef __MMI_FM_CHARGER__
        <STRING id = "STR_ID_FM_CHARGER"/>
    #endif
    <STRING id = "STR_ID_FM_RTC"/>
#ifdef __ATV_SUPPORT__    
    <STRING id = "STR_ID_FM_MATV"/>
#endif
    

#ifdef __MMI_FM_AUTO_TEST__  
    <STRING id = "STR_ID_FM_AUTO_TEST_ROOT"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_REPORT"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_RESULT"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_PASS"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_FAIL"/>


    <STRING id = "STR_ID_FM_AUTO_TEST_RETEST"/>
    //<STRING id = "STR_GLOBAL_EXIT"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_ALLDONE"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_ALLPASSED"/>
    //<STRING id = "STR_GLOBAL_FAILED"/>
    <STRING id = "STR_ID_FM_AUTO_TEST_UNFINISHED"/>
    <STRING id = "STR_ID_FM_AUTOTEST_LED_R"/>
    <STRING id = "STR_ID_FM_AUTOTEST_LED_G"/>
    <STRING id = "STR_ID_FM_AUTOTEST_LED_B"/>
    <STRING id = "STR_ID_FM_AUTOTEST_CLAM"/>
    <STRING id = "STR_ID_FM_AUTOTEST_BACKLIGHT"/>
    <STRING id = "STR_ID_FM_AUTOTEST_RECEIVER"/>
    <STRING id = "STR_ID_FM_AUTOTEST_MIC"/>
    <STRING id = "STR_ID_FM_AUTOTEST_SPEAKER"/>
    <STRING id = "STR_ID_FM_AUTOTEST_HEADSET"/>
    <STRING id = "STR_ID_FM_AUTOTEST_MELODY"/>
    <STRING id = "STR_ID_FM_AUTOTEST_VIB"/>
    <STRING id = "STR_ID_FM_AUTOTEST_NAND"/>
    
 #ifdef __MMI_FM_UART_TEST__
    <STRING id = "STR_ID_FM_AUTOTEST_UART"/>
 #endif
 
    <STRING id = "STR_ID_FM_AUTOTEST_LEFT_SPEAKER"/>
    <STRING id = "STR_ID_FM_AUTOTEST_RIGHT_SPEAKER"/>
#endif /*__MMI_FM_AUTO_TEST__*/



    
    
#if defined(__MMI_FM_TC01_CAMERA_TEST__)
    <STRING id = "STR_ID_FM_CAMERA_TEST"/>
#endif

#if defined(__MMI_FM_CAMERA_PREVIEW__)    
    <STRING id = "STR_ID_FM_CAMERA"/>
#endif /__MMI_FM_CAMERA_PREVIEW__/

#if 0
#if 1 //def __FM_CAMERA_TUNNING__    
    <STRING id = "STR_ID_FM_CAMERA_SAVE_CONFRIM"/>
    <STRING id = "STR_ID_FM_CAMERA_RESTORE_CONFIRM"/>
#endif /*__FM_CAMERA_TUNNING__*/ 

#endif

#if (defined(NAND_SUPPORT))   
    <STRING id = "STR_ID_FM_NAND_FLASH"/>
#endif   
#ifdef __MMI_FM_LCD_CONTRAST__ 
    <STRING id = "STR_ID_FM_LCD_CONTRAST"/>
    <STRING id = "STR_ID_FM_LCD_CONTRAST_MAIN"/>
#ifdef __MMI_SUBLCD__    
    <STRING id = "STR_ID_FM_LCD_CONTRAST_SUB"/>
#endif /*__MMI_SUBLCD__*/
#endif /*__MMI_FM_LCD_CONTRAST__*/
   
    <STRING id = "STR_ID_FM_LCD_AUTO"/>
    <STRING id = "STR_ID_FM_LCD_R"/>
    <STRING id = "STR_ID_FM_LCD_G"/>
    <STRING id = "STR_ID_FM_LCD_B"/>
    <STRING id = "STR_ID_FM_LCD_W"/>
    <STRING id = "STR_ID_FM_LCD_BLACK"/>
    
    <STRING id = "STR_ID_FM_RTC_NOTIFY"/>
    //<STRING id = "STR_GLOBAL_MEMORY_CARD"/>
    #ifdef __MMI_FM_MTBF__            
        <STRING id = "STR_ID_FM_MTBF"/>
    #endif
    
#ifdef __MMI_FM_UART_TEST__
    <STRING id = "STR_ID_FM_UART"/>
#endif /*__MMI_FM_UART_TEST__*/

#ifdef __MMI_TOUCH_SCREEN__    
    <STRING id = "STR_ID_FM_PARALLEL_TEST"/>
    <STRING id = "STR_ID_FM_N_CROSS_M_TEST"/>
#endif /*__MMI_TOUCH_SCREEN__*/    
#ifdef __MMI_FM_RADIO__    
    <STRING id = "STR_ID_FM_FM_RADIO"/>
    <STRING id = "STR_ID_FM_FM_RADIO_CHANNEL_1"/>

#ifdef __MMI_FM_FMRADIO_PHASE_OUT__
    <STRING id = "STR_ID_FM_FM_RADIO_CHANNEL_2"/>
    <STRING id = "STR_ID_FM_FM_RADIO_CHANNEL_3"/>
#endif

#endif /*__MMI_FM_RADIO__*/ 
    
    #ifdef __MMI_FM_PXS_SENSOR__
        <STRING id = "STR_ID_FM_PXS"/>
    #endif
    
#ifdef __ACOUSTIC_LOOPBACK_SUPPORT__
    <STRING id = "STR_ID_FM_ACOUSTIC_LOOPBACK"/>
#endif    
    
#ifdef  __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__    
    <STRING id = "STR_ID_FM_TOUCH_PANEL"/>
    <STRING id = "STR_ID_FM_TOUCH_PANEL_LINER_TEST"/>
    <STRING id = "STR_ID_FM_TOUCH_PANEL_JITTER_TEST"/>
#endif /*__MMI_FM_TOUCH_PANEL_ACCURACY_TEST__*/

#ifdef __TOUCH_PANEL_MULTITOUCH__
		<STRING id = "STR_ID_FM_DUAL_TOUCH_CALIBRATION"/>
		<!----------------- Image Id ------------------------------------------>
    <!-- Dual touch image------------------------------------------------------->
    #if defined (__COSMOS_MMI_PACKAGE__) 
		<IMAGE id = "IMG_FM_DUAL_TOUCH_DOWN">RES_IMG_ROOT"\\\\FM\\\\Calibration_down.png"</IMAGE>
    <IMAGE id = "IMG_FM_DUAL_TOUCH_NOR">RES_IMG_ROOT"\\\\FM\\\\Calibration_nor.png"</IMAGE>
		#else
    <IMAGE id = "IMG_FM_DUAL_TOUCH_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FM\\\\Calibration_down.png"</IMAGE>
    <IMAGE id = "IMG_FM_DUAL_TOUCH_NOR">CUST_IMG_PATH"\\\\MainLCD\\\\FM\\\\Calibration_nor.png"</IMAGE>
    #endif
#endif

#ifdef __MMI_FM_NFC_SUPPORT__
    <STRING id = "STR_ID_FM_NFC"/>
    <STRING id = "STR_ID_FM_NFC_SWP_SELF_TEST"/>
    <STRING id = "STR_ID_FM_NFC_CANT_TEST"/>
    <STRING id = "STR_ID_FM_NFC_TAG_UID_RW"/>
    <STRING id = "STR_ID_FM_NFC_CARD_MODE"/>
    <STRING id = "STR_ID_FM_NFC_CARD_MODE_OPT"/>
    <STRING id = "STR_ID_FM_NFC_CARD_MODE_OPT_SWP"/>
    <STRING id = "STR_ID_FM_NFC_CARD_MODE_OPT_NFC_WI"/>
    <STRING id = "STR_ID_FM_NFC_TESTING"/>
    <STRING id = "STR_ID_FM_NFC_STOPING"/>    
    <STRING id = "STR_ID_FM_NFC_FAILED"/>
    <STRING id = "STR_ID_FM_NFC_PASS"/>
#endif /**/    

#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
	
	<STRING id = "STR_ID_FM_MOTION_SENSOR_CALI"/>
	<STRING id = "STR_ID_FM_MOTION_SENSOR_CALI_FINISHED"/>
	<STRING id = "STR_ID_FM_MOTION_SENSOR_CALI_TIMEOUT"/>
	<STRING id = "STR_ID_FM_MOTION_SENSOR_CALI_NOTIFICATION"/>
	<STRING id = "STR_ID_FM_MOTION_SENSOR_CALI_WRITE_FAIL">Write fail</STRING>

#endif

	<STRING id = "STR_ID_FM_VBAT">ADC_VBAT</STRING>
	<STRING id = "STR_ID_FM_BTEMP">ADC_VBATTMP</STRING>
	<STRING id = "STR_ID_FM_VAUX">ADC_VAUX</STRING>
	<STRING id = "STR_ID_FM_CURRENT">ADC_VISENSE</STRING>
	<STRING id = "STR_ID_FM_VCHGR">ADC_VCHGR</STRING> 



    <!----------------- Menu Id ------------------------------------------->
    <MENU id="MENU_ID_FM_ROOT" type = "APP_SUB" str="STR_ID_FM_ROOT">        
#ifndef __MMI_FM_MERGE_AUTO_TEST__  
		<MENUITEM_ID>MENU_ID_FM_VERSION</MENUITEM_ID>  
    #ifdef __MMI_FM_RES_BIN__
        <MENUITEM_ID>MENU_ID_FM_RESOURCE_BIN</MENUITEM_ID>
    #endif /* __MMI_FM_RES_BIN__ */
        <MENUITEM id="MENU_ID_FM_EACHLOOP" str="STR_ID_FM_EACHLOOP"/>
    #ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__    
        <MENUITEM id="MENU_ID_FM_EACHLOOP2" str="STR_ID_FM_EACHLOOP2"/>
        <MENUITEM id="MENU_ID_FM_2MICNR_TEST" str="STR_ID_FM_2MICNR_TEST" />
        <MENUITEM id="MENU_ID_FM_DISABLE_2_MIC_NR_TEST" str="STR_ID_FM_DISABLE_2_MIC_NR_TEST"/>
    #endif
    #ifdef __ACOUSTIC_LOOPBACK_SUPPORT__
        <MENUITEM id="MENU_ID_FM_ACOUSTIC_LOOPBACK" str="STR_ID_FM_ACOUSTIC_LOOPBACK"/>
    #endif
    
    
    #ifdef __MMI_FM_KEYPAD_TEST__
        <MENUITEM id="MENU_ID_FM_KEYPAD" str="STR_ID_FM_KEYPAD"/>
	#endif
        <MENUITEM id="MENU_ID_FM_VIBRATOR" str="STR_ID_FM_VIBRATOR"/>
        <MENUITEM id="MENU_ID_FM_LOUDSPK" str="STR_ID_FM_LOUDSPK"/>        
        <MENUITEM id="MENU_ID_FM_RINGTONE" str="STR_GLOBAL_RINGTONE"/>
    #ifdef __SUPPORT_LED_FEATURE__
        <MENUITEM_ID>MENU_ID_FM_LED</MENUITEM_ID>
    #endif /* __SUPPORT_LED_FEATURE__ */
        <MENUITEM_ID>MENU_ID_FM_LCD</MENUITEM_ID>
    #ifdef __MMI_FM_LCD_CONTRAST__        
        <MENUITEM_ID>MENU_ID_FM_LCD_CONTRAST</MENUITEM_ID>
    #endif                        
        <MENUITEM id="MENU_ID_FM_RECEIVER" str="STR_ID_FM_RECEIVER"/>
#endif /* __MMI_FM_MERGE_AUTO_TEST__ */
        <MENUITEM id="MENU_ID_FM_ADC" str="STR_ID_FM_ADC"/>            

	 #ifdef __MMI_FM_CHARGER__
        <MENUITEM id="MENU_ID_FM_CHARGER" str="STR_ID_FM_CHARGER"/>
   #endif

#ifndef __MMI_FM_MERGE_AUTO_TEST__	
        <MENUITEM id="MENU_ID_FM_HEADSET" str="STR_ID_FM_HEADSET"/>
#endif /* __MMI_FM_MERGE_AUTO_TEST__ */        
        
        <MENUITEM id="MENU_ID_FM_RTC" str="STR_ID_FM_RTC"/>        

#ifndef __MMI_FM_MERGE_AUTO_TEST__	
    #ifdef __MMI_FM_MTBF__            
        <MENUITEM id="MENU_ID_FM_MTBF" str="STR_ID_FM_MTBF"/>
    #endif
        
    #ifdef __MMI_FM_UART_TEST__
        <MENUITEM id="MENU_ID_FM_UART" str="STR_ID_FM_UART"/>					   
    #endif
    
    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))							   
		<MENUITEM id="MENU_ID_FM_MEMORY_CARD" str="STR_GLOBAL_MEMORY_CARD"/>
    #endif
    #if (defined(NAND_SUPPORT))
        <MENUITEM id="MENU_ID_FM_NAND_FLASH" str="STR_ID_FM_NAND_FLASH"/>
    #endif
    
   #if defined(__MMI_FM_TC01_CAMERA_TEST__)
        <MENUITEM id="MENU_ID_FM_CAMERA_TEST" str="STR_ID_FM_CAMERA_TEST"/>
   #endif


   #if  defined(__MMI_FM_CAMERA_PREVIEW__)
    <MENUITEM_ID>MENU_ID_FM_CAMERA</MENUITEM_ID>
    #endif


    #if defined(__MMI_TOUCH_SCREEN__)
        <MENUITEM id="MENU_ID_FM_PARALLEL_LINE" str="STR_ID_FM_PARALLEL_TEST"/>
        <MENUITEM id="MENU_ID_FM_N_CROSS_M" str="STR_ID_FM_N_CROSS_M_TEST"/>
    #endif /*__MMI_TOUCH_SCREEN__*/
    
    #ifdef __MMI_FM_RADIO__
        <MENUITEM_ID>MENU_ID_FM_FMRADIO</MENUITEM_ID>
    #endif    
    
    /*    
    #if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
        <MENUITEM id="MENU_ID_FM_GPS" str="STR_ID_FM_GPS"/>
    #endif
    */

    #ifdef __ATV_SUPPORT__
        <MENUITEM id="MENU_ID_FM_MATV" str="STR_ID_FM_MATV"/>
    #endif

    #ifdef  __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
        <MENUITEM_ID>MENU_ID_FM_TOUCH_PANEL</MENUITEM_ID>
    #endif /*__MMI_FM_TOUCH_PANEL_ACCURACY_TEST__*/
    #ifdef __TOUCH_PANEL_MULTITOUCH__
				<MENUITEM id="MENU_ID_FM_DUAL_TOUCH_CALIBRATION" str="STR_ID_FM_DUAL_TOUCH_CALIBRATION"/>
    #endif
    #ifdef __MMI_FM_PXS_SENSOR__
        <MENUITEM id="MENU_ID_FM_PXS_SENSOR" str="STR_ID_FM_PXS"/>
    #endif   
#endif /* __MMI_FM_MERGE_AUTO_TEST__ */

     #ifdef __MMI_FM_AUTO_TEST__
        <MENUITEM_ID>MENU_ID_FM_MISC_AUTO_TEST_SETTING</MENUITEM_ID>
    #endif 

#ifndef __MMI_FM_MERGE_AUTO_TEST__    
    #ifdef __MMI_FM_NFC_SUPPORT__
        <MENUITEM_ID>MENU_ID_FM_NFC</MENUITEM_ID>
    #endif /*__MMI_FM_NFC_SUPPORT__*/ 
    

	#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
		<MENUITEM_ID>MENU_ID_FM_MOTION_SENSOR_CALI</MENUITEM_ID>
	#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/
#endif /* __MMI_FM_MERGE_AUTO_TEST__ */   
    </MENU>


    
    <!----------------- Misc. | Auto Test Setting --------------------------------->
#ifdef __MMI_FM_AUTO_TEST__
        <!----------------- Screen Id ----------------------------------------->
        <SCREEN id = "SCR_ID_FM_MISC_AUTO_TEST_SETTING"/>
        <SCREEN id = "SCR_ID_FM_MISC_AUTO_TEST_ADD"/>
        <SCREEN id = "SCR_ID_FM_AUTO_TEST_ENTER_PRIORITY"/>
        <SCREEN id = "SCR_ID_FM_MISC_AUTO_TEST_CHANGE_PRIORITY"/>
    
        <!----------------- String Id ----------------------------------------->             
        <STRING id = "STR_ID_FM_MISC_AUTO_TEST_SETTING">Quick test list</STRING>
        <STRING id = "STR_ID_FM_AUTO_TEST_ADD">Add from list</STRING>
        <STRING id = "STR_ID_FM_AUTO_TEST_CHANGE_PRIORITY">Change priority</STRING>
        //<STRING id = "STR_ID_FM_AUTO_TEST_REMOVE">Remove</STRING>
        <STRING id = "STR_ID_FM_AUTO_TEST_ENTER_PRIORITY">Enter priority</STRING>
        
        <!----------------- Menu Id ------------------------------------------->             
        <MENU id = "MENU_ID_FM_MISC_AUTO_TEST_SETTING" type = "APP_SUB" str = "STR_ID_FM_MISC_AUTO_TEST_SETTING">
        </MENU>
    
        <MENU id = "MENU_ID_FM_AUTO_TEST_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
            <MENUITEM id = "MENU_ID_FM_AUTO_TEST_ADD" str = "STR_ID_FM_AUTO_TEST_ADD"/>
            <MENUITEM id = "MENU_ID_FM_AUTO_TEST_CHANGE_PRIORITY" str = "STR_ID_FM_AUTO_TEST_CHANGE_PRIORITY"/>
            <MENUITEM id = "MENU_ID_FM_AUTO_TEST_REMOVE" str = "STR_GLOBAL_REMOVE"/>
        </MENU>
#endif/*__MMI_FM_AUTO_TEST__*/    
    <!----------------- EM Item End ----------------------------------------------->

    <MENU id="MENU_ID_FM_VERSION" type = "APP_SUB" str="STR_ID_FM_VERSION">
        <MENUITEM id="MENU_ID_FM_SW_SUMMARY" str="STR_ID_FM_SW_SUMMARY"/>
        <MENUITEM id="MENU_ID_FM_SW_VER" str="STR_ID_FM_SW_VER"/>
    #ifdef __MMI_FM_MELODY_VERSION__
        <MENUITEM id="MENU_ID_FM_MELODY_VER" str="STR_ID_FM_MELODY_VER"/>
    #endif /*MENU_ID_FM_MELODY_VER*/
        <MENUITEM id="MENU_ID_FM_ISN" str="STR_ID_FM_ISN"/>
        <MENUITEM id="MENU_ID_FM_BBCHIP_VER" str="STR_ID_FM_BBCHIP_VER"/>
        <MENUITEM id="MENU_ID_FM_DSPCODE_VER" str="STR_ID_FM_DSPCODE_VER"/>
        <MENUITEM id="MENU_ID_FM_DSPATCH_VER" str="STR_ID_FM_DSPATCH_VER"/>
        <MENUITEM id="MENU_ID_FM_HW_VER" str="STR_ID_FM_HW_VER"/>


        <MENUITEM id="MENU_ID_FM_BUILD_TIME" str="STR_ID_FM_BUILD_TIME"/>


    </MENU>

    #ifdef __MMI_FM_RES_BIN__
    <MENU id="MENU_ID_FM_RESOURCE_BIN" type = "APP_SUB" str="STR_ID_FM_RESOURCE_BIN">
        <MENUITEM id="MENU_ID_FM_RESOURCE_LANGPACK" str="STR_ID_FM_RESOURCE_LANGPACK"/>
        <MENUITEM id="MENU_ID_FM_RESOURCE_CUSTPACK" str="STR_ID_FM_RESOURCE_CUSTPACK"/>
    </MENU>
    #endif /* __MMI_FM_RES_BIN__ */
    #ifdef __SUPPORT_LED_FEATURE__
    <MENU id="MENU_ID_FM_LED" type = "APP_SUB" str="STR_ID_FM_LED">
        <MENUITEM id="MENU_ID_FM_LED_MAIN" str="STR_ID_FM_LED_MAIN"/>
    #ifdef __MMI_SUBLCD__        
        <MENUITEM id="MENU_ID_FM_LED_SUB" str="STR_ID_FM_LED_SUB"/>
    #endif    
        <MENUITEM id="MENU_ID_FM_LED_KEYPAD" str="STR_ID_FM_LED_KEYPAD"/>
    #ifndef __MMI_HIDE_STATUS_LED_R__    
        <MENUITEM id="MENU_ID_FM_LED_STATUS_R" str="STR_ID_FM_LED_STATUS_R"/>
    #endif
    #ifndef __MMI_HIDE_STATUS_LED_G__    
        <MENUITEM id="MENU_ID_FM_LED_STATUS_G" str="STR_ID_FM_LED_STATUS_G"/>
    #endif
    #ifndef __MMI_HIDE_STATUS_LED_B__    
        <MENUITEM id="MENU_ID_FM_LED_STATUS_B" str="STR_ID_FM_LED_STATUS_B"/>
    #endif
    </MENU>
    #endif /* __SUPPORT_LED_FEATURE__ */
#ifndef __MMI_MAINLCD_96X64__ 
    <MENU id="MENU_ID_FM_LCD" type = "APP_SUB" str="STR_ID_FM_LCD">
        <MENUITEM id="MENU_ID_FM_LCD_AUTO" str="STR_ID_FM_LCD_AUTO"/>
        <MENUITEM id="MENU_ID_FM_LCD_R" str="STR_ID_FM_LCD_R"/>
        <MENUITEM id="MENU_ID_FM_LCD_G" str="STR_ID_FM_LCD_G"/>
        <MENUITEM id="MENU_ID_FM_LCD_B" str="STR_ID_FM_LCD_B"/>
        <MENUITEM id="MENU_ID_FM_LCD_W" str="STR_ID_FM_LCD_W"/>
        <MENUITEM id="MENU_ID_FM_LCD_BLACK" str="STR_ID_FM_LCD_BLACK"/>        
    </MENU>
#endif /* __MMI_MAINLCD_96X64__ */
#ifdef __MMI_FM_LCD_CONTRAST__    
    <MENU id="MENU_ID_FM_LCD_CONTRAST" type = "APP_SUB" str="STR_ID_FM_LCD_CONTRAST">
        <MENUITEM id="MENU_ID_FM_LCD_CONTRAST_MAINLCD" str="STR_ID_FM_LCD_CONTRAST_MAIN"/>
    #ifdef __MMI_SUBLCD__    
        <MENUITEM id="MENU_ID_FM_LCD_CONTRAST_SUBLCD" str="STR_ID_FM_LCD_CONTRAST_SUB"/>
    #endif         
    </MENU>    
#endif /*__MMI_FM_LCD_CONTRAST__*/


#if 0

    <MENUITEM id="MENU_ID_FM_CAMERA_SENSOR_SETTING" str="STR_ID_FM_CAMERA_SENSOR_SETTING"/>
    <MENUITEM id="MENU_ID_FM_CAMERA_ISP_SETTING" str="STR_ID_FM_CAMERA_ISP_SETTING"/>
    <MENUITEM id="MENU_ID_FM_CAMERA_SAVE_TO_NVRAM" str="STR_ID_FM_CAMERA_SAVE_TO_NVRAM"/>    
    <MENUITEM id="MENU_ID_FM_CAMERA_RESTORE_DEFAULT" str="STR_ID_FM_CAMERA_RESTORE_DEFAULT"/>
    


	/* FM Camera Tunning */
#if defined(__FM_CAMERA_TEST__)
    <MENU id="MENU_ID_FM_CAMERA_TEST" type = "APP_SUB" str="STR_ID_FM_CAMERA_TEST">
        <MENUITEM_ID>MENU_ID_FM_CAMERA_SENSOR_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_ISP_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_SAVE_TO_NVRAM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_RESTORE_DEFAULT</MENUITEM_ID>
    </MENU>
#endif



#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
    <MENU id="MENU_ID_FM_CAMERA" type = "APP_SUB" str="STR_ID_FM_CAMERA">
        <MENUITEM_ID>MENU_ID_FM_CAMERA_SENSOR_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_ISP_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_SAVE_TO_NVRAM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FM_CAMERA_RESTORE_DEFAULT</MENUITEM_ID>
    </MENU>
#endif

#endif

#if defined(__MMI_FM_CAMERA_PREVIEW__)
    <MENUITEM id="MENU_ID_FM_CAMERA" str="STR_ID_FM_CAMERA"/>
#endif



#ifdef __MMI_FM_RADIO__
    <MENU id="MENU_ID_FM_FMRADIO" type = "APP_SUB" str="STR_ID_FM_FM_RADIO">
        <MENUITEM id="MENU_ID_FM_FMRADIO_CHANNEL_1" str="STR_ID_FM_FM_RADIO_CHANNEL_1"/>
        
    #ifdef __MMI_FM_FMRADIO_PHASE_OUT__
        <MENUITEM id="MENU_ID_FM_FMRADIO_CHANNEL_2" str="STR_ID_FM_FM_RADIO_CHANNEL_2"/>
        <MENUITEM id="MENU_ID_FM_FMRADIO_CHANNEL_3" str="STR_ID_FM_FM_RADIO_CHANNEL_3"/>
    #endif
    
    </MENU>
#endif /*__MMI_FM_RADIO__*/

#ifdef  __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
    <MENU id="MENU_ID_FM_TOUCH_PANEL" type = "APP_SUB" str="STR_ID_FM_TOUCH_PANEL">
        <MENUITEM id="MENU_ID_FM_TOUCH_PANEL_LINER_TEST" str="STR_ID_FM_TOUCH_PANEL_LINER_TEST"/>
        <MENUITEM id="MENU_ID_FM_TOUCH_PANEL_JITTER_TEST" str="STR_ID_FM_TOUCH_PANEL_JITTER_TEST"/>
    </MENU>
#endif /*__MMI_FM_TOUCH_PANEL_ACCURACY_TEST__*/




#ifdef __MMI_FM_NFC_SUPPORT__
    <MENU id="MENU_ID_FM_NFC" type = "APP_SUB" str="STR_ID_FM_NFC">
        <MENUITEM id="MENU_ID_FM_NFC_SWP_SELF_TEST" str="STR_ID_FM_NFC_SWP_SELF_TEST"/>
        <MENUITEM id="MENU_ID_FM_NFC_CANT_TEST" str="STR_ID_FM_NFC_CANT_TEST"/>
        <MENUITEM id="MENU_ID_FM_NFC_TAG_UID_RW" str="STR_ID_FM_NFC_TAG_UID_RW"/>
        <MENUITEM id="MENU_ID_FM_NFC_CARD_MODE" str="STR_ID_FM_NFC_CARD_MODE"/>
    </MENU>
#endif /*__MMI_FM_NFC_SUPPORT__*/ 

	#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
	
	<MENUITEM id="MENU_ID_FM_MOTION_SENSOR_CALI" str="STR_ID_FM_MOTION_SENSOR_CALI"/>

	#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/



#if 0							   
	ADD_APPLICATION_MENUITEM((MENU_ID_FM_AUTO_TEST_ROOT, IDLE_SCREEN_MENU_ID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT ));
#endif							

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_FM_ROOT"/>
    <SCREEN id = "SCR_ID_FM_VERSION"/>
    <SCREEN id = "SCR_ID_FM_VERSION_SUMMARY"/>
    <SCREEN id = "SCR_ID_FM_RESOURCE_BIN"/>
    <SCREEN id = "SCR_ID_FM_RESOURCE_AUDIO"/>
    <SCREEN id = "SCR_ID_FM_RESOURCE_IMAGE"/>
    <SCREEN id = "SCR_ID_FM_RESOURCE_STR"/>
    <SCREEN id = "SCR_ID_FM_RESOURCE_FONT"/>
    <SCREEN id = "SCR_ID_FM_BBCHIP_VER"/>
    <SCREEN id = "SCR_ID_FM_DSPCODE_VER"/>
    <SCREEN id = "SCR_ID_FM_DSPATCH_VER"/>
    <SCREEN id = "SCR_ID_FM_SW_VER"/>
    <SCREEN id = "SCR_ID_FM_HW_VER"/>
    <SCREEN id = "SCR_ID_FM_MELODY_VER"/>
    <SCREEN id = "SCR_ID_FM_ISN"/>
    <SCREEN id = "SCR_ID_FM_BUILD_TIME"/>
    <SCREEN id = "SCR_ID_FM_LED"/>
    <SCREEN id = "SCR_ID_FM_LCD"/>
    <SCREEN id = "SCR_ID_FM_LCD_AUTO"/>
    <SCREEN id = "SCR_ID_FM_LCD_R"/>
    <SCREEN id = "SCR_ID_FM_LCD_G"/>
    <SCREEN id = "SCR_ID_FM_LCD_B"/>
    <SCREEN id = "SCR_ID_FM_LCD_W"/>
    <SCREEN id = "SCR_ID_FM_LCD_CONTRAST"/>
    <SCREEN id = "SCR_ID_FM_LCD_CONTRAST_MAINLCD"/>
    <SCREEN id = "SCR_ID_FM_LCD_CONTRAST_SUBLCD"/>
    <SCREEN id = "SCR_ID_FM_KEYPAD"/>
    <SCREEN id = "SCR_ID_FM_LOUDSPK"/>
    <SCREEN id = "SCR_ID_FM_EACHLOOP"/>
    <SCREEN id = "SCR_ID_FM_VIBRATOR"/>
    <SCREEN id = "SCR_ID_FM_ADC"/>
    <SCREEN id = "SCR_ID_FM_RECEIVER"/>
    <SCREEN id = "SCR_ID_FM_RTC"/>
    <SCREEN id = "SCR_ID_FM_HEADSET"/>
    <SCREEN id = "SCR_ID_FM_CHARGER"/>
    <SCREEN id = "SCR_ID_FM_RINGTONE"/>
    <SCREEN id = "SCR_ID_FM_AUTO_TEST_ROOT"/>    
    <SCREEN id = "SCR_ID_FM_AUTO_TEST_REPORT"/>
    <SCREEN id = "SCR_ID_FM_AUTO_TEST_SUMMARY"/>
    <SCREEN id = "SCR_ID_FM_AUTO_TEST_RESULT"/>
    <SCREEN id = "SCR_ID_FM_AUTO_TEST_START"/>
    <SCREEN id = "SCR_ID_FM_MEMORY_CARD"/>
    <SCREEN id = "SCR_ID_FM_NAND_FLASH"/>
    <SCREEN id = "SCR_ID_FM_CAMERA_TEST"/>
    <SCREEN id = "SCR_ID_FM_CAMERA_TEST_DUMMY"/>
    <SCREEN id = "SCR_ID_FM_CAMERA"/>
    <SCREEN id = "SCR_ID_FM_CAMERA_SENSOR_SETTING"/>
    <SCREEN id = "SCR_ID_FM_CAMERA_ISP_SETTING"/>
    <SCREEN id = "SCR_ID_FM_SETCAMERAPARA"/>
    <SCREEN id = "SCR_ID_FM_MTBF"/>
    
    <SCREEN id = "SCR_ID_FM_MOTION_CALI"/>
    
 #ifdef __MMI_FM_UART_TEST__
    <SCREEN id = "SCR_ID_FM_UART"/>
 #endif
 
    <SCREEN id = "SCR_ID_FM_PARALLEL_PEN"/>
    <SCREEN id = "SCR_ID_FM_N_CROSS_M_PEN"/>
    
    <SCREEN id = "SCR_ID_FM_FM_RADIO"/>
    <SCREEN id = "SCR_ID_FM_FM_RADIO_CHANNEL_TEST"/>
    <SCREEN id = "SCR_ID_FM_KEYPAD_TEST"/>
    <SCREEN id = "SCR_ID_FM_KEYPAD_TEST_RESULT"/>
    <SCREEN id = "SCR_ID_FM_PXS_RAW_DATA"/>
    <SCREEN id = "SCR_ID_FM_TOUCH_PANEL"/>
    <SCREEN id = "GRP_ID_FM_ROOT"/>
    <SCREEN id = "GRP_ID_FM_TOUCH_PANEL"/>
//////////////////////////////////////////#ifdef __TOUCH_PANEL_MULTITOUCH__
		<SCREEN id = "SCR_ID_FM_DUAL_TOUCH_CALIBRATION"/>
    <SCREEN id = "GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION"/>
//////////////////////////////////////////#endif
#ifdef __MMI_FM_NFC_SUPPORT__   
    <SCREEN id = "GRP_ID_FM_NFC"/>
    <SCREEN id = "SCR_ID_FM_NFC_SHOW_PROGRESS"/>
    <SCREEN id = "SCR_ID_FM_NFC_SHOW_UID"/>
#endif    

#ifdef __MMI_FM_LCD_CONTRAST__

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_CONTRAST_LEVEL" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_CONTRAST_MAINLCD_LEVEL_VALUE] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_FM_LCD_CONTRAST__ */


	
	<TIMER id = "FM_LCD_COLOR_CHANGE_TIMER"/>
	<TIMER id = "FM_AUTO_TEST_COMMNON_TIMER"/>

        <TIMER id = "FM_RTC_START_TIMER"/>
	<TIMER id = "FM_VIB_TIMER"/>
	<TIMER id = "FM_GENERAL_TIMER"/>




	

</APP>

#endif /*__MMI_FACTORY_MODE__ */
