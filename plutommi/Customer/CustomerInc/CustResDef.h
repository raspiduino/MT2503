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
 *  CustResDefPLUTO.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file intends for custom resource definitions
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUST_RES_DEF_H
#define _CUST_RES_DEF_H

#include "MMI_features.h"

#ifdef __MMI_AUTO_LANG_EN__
#define MMI_DEFLANGSSC_FOR_AUTO    "*#0044#"
#endif

#define SSC_SW_VERSION             "*#8375#"
#define SSC_HW_VERSION             "*#357#" //Not used if __MMI_HW_VERSION__ is not turned on
#define SSC_ENGINEERING_MODE       "*#3646633#"
#define SSC_FACTORY_MODE           "*#66*#"
#define SSC_FACTORY_MODE_AUTOTEST  "*#87#"
#define SSC_SERIAL_NUMBER          "*#33778#"

#ifdef __MMI_FM_LCD_CONTRAST__
#define SSC_SET_LCD_CONTRAST       "*#523#"
#endif

#define SSC_IR_OPEN                "*#678#"
#define SSC_IR_CLOSE               "*#876#"
#define SSC_VENDORAPP              "*#3366*#"
#ifdef __FLAVOR_VENDOR_SDK__
#define SSC_AVKAPP                 "*#87285*#"
#endif
/* for SSC disable */
#define SSC_DISABLE_FOR_SHIPMENT   "*#6810#"

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
#define SSC_SML_ADD_CODE           "###765*02#"
#define SSC_SML_REMOVE_CODE        "###765*07#"
#define SSC_SML_LOCK_CODE          "###765*05#"
#define SSC_SML_UNLOCK_CODE        "###765*08#"
#define SSC_SML_DEACTIVATE_CODE    "###765*78#" /* permanent unlock */
#define SSC_SML_LOCK_CMD           "*7525#"
#define SSC_SML_UNLOCK_CMD         "#7525#"
#define SSC_SML_QUERY_CMD          "*#7525#"
#ifdef __MMI_SML_NP_ONLY__
#define SSC_SML_UNLOCK_NP_CMD      "*#7525*01#"
#define SSC_SML_UNLOCK_NSP_CMD     "*#7525*02#"
#define SSC_SML_UNLOCK_SP_CMD      "*#7525*03#"
#define SSC_SML_UNLOCK_CP_CMD      "*#7525*04#"
#define SSC_SML_UNLOCK_SIMP_CMD    "*#7525*05#"
#define SSC_SML_UNLOCK_NS_SP_CMD   "*#7525*06#"
#define SSC_SML_UNLOCK_SIM_C_CMD   "*#7525*07#"
#endif /* __MMI_SML_NP_ONLY__ */
#endif /* __MMI_SML_MENU__ */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
#define SSC_OP11_HOMESCREEN        "*#20801#"
#endif /* __MMI_OP11_HOMESCREEN__ */

#define SSC_DISABLE_KEYPAD_LOCK_BY_END_KEY  "*#5566183#"

#define CUST_IMG_BASE_PATH			"..\\\\..\\\\Customer\\\\Images"

//MTK Leo added, to customize mmi
	#define CUS_STR_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustStrRes.c" //Filename containg the array of CUSTOM_STRING.
	#define CUS_STR_MAP_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustStrMap.c" //Filename containg the array of CUSTOM_STRING_MAP.
	#define CUS_IMG_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgRes.c" //Filename containg the array of CUSTOM_IMAGE.
	#define CUS_IMG_MAP_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgMap.c" //Filename containg the array of CUSTOM_IMAGE_MAP.
	#define CUS_MENU_DATA_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustMenuRes.c" //Filename containg the array of CUSTOM_MENU.
	#define CUS_IMG_HW_FILENAME		"..\\..\\Customer\\CustResource\\PLUTO_MMI\\CustImgDataHW.h"

#if defined(__VENUS_MMI__) && defined(__COSMOS_MMI__)
    /* Image path define for COSMOS */
    #if defined(__MMI_MAINLCD_240X320__)
      #define CUST_IMG_PATH_ROOT        "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X320"
    	#define CUST_IMG_PATH           "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X320\\\\MainLCD\\\\Legacy"
    	#define RES_IMG_ROOT            "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X320\\\\MainLCD\\\\Default"
    	#define RES_THEME_ROOT          "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X320\\\\MainLCD"
    #elif defined(__MMI_MAINLCD_240X400__)
      #define CUST_IMG_PATH_ROOT        "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X400"
    	#define CUST_IMG_PATH           "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X400\\\\MainLCD\\\\Legacy"
    	#define RES_IMG_ROOT            "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X400\\\\MainLCD\\\\Default"
    	#define RES_THEME_ROOT          "..\\\\..\\\\Customer\\\\Images\\\\COSMOS240X400\\\\MainLCD"
    #elif defined(__MMI_MAINLCD_320X480__)
      #define CUST_IMG_PATH_ROOT        "..\\\\..\\\\Customer\\\\Images\\\\COSMOS320X480"
    	#define CUST_IMG_PATH           "..\\\\..\\\\Customer\\\\Images\\\\COSMOS320X480\\\\MainLCD\\\\Legacy"
    	#define RES_IMG_ROOT            "..\\\\..\\\\Customer\\\\Images\\\\COSMOS320X480\\\\MainLCD\\\\Default"
    	#define RES_THEME_ROOT          "..\\\\..\\\\Customer\\\\Images\\\\COSMOS320X480\\\\MainLCD"
    #elif defined(__MMI_MAINLCD_480X800__)
      #define CUST_IMG_PATH_ROOT        "..\\\\..\\\\Customer\\\\Images\\\\COSMOS480X800"
    	#define CUST_IMG_PATH           "..\\\\..\\\\Customer\\\\Images\\\\COSMOS480X800\\\\MainLCD\\\\Legacy"
    	#define RES_IMG_ROOT            "..\\\\..\\\\Customer\\\\Images\\\\COSMOS480X800\\\\MainLCD\\\\Default"
    	#define RES_THEME_ROOT          "..\\\\..\\\\Customer\\\\Images\\\\COSMOS480X800\\\\MainLCD"
    #else
    	#error COSMOS image only support 240X320 240X400 320X480
    #endif
    
#else /* defined(__VENUS_MMI__) && defined(__COSMOS_MMI__) */
    /* Image path define for Pluto MMI */
#if defined(__MMI_FTE_SUPPORT__)

// Note: FTE SLIM Image only support 240X320
#if (defined(__32_32_SEG__) || defined(__64_32_SEG__) || defined(__32_64_SEG__))
    #if defined(__MMI_MAINLCD_240X320__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE_SLIM240X320"    
    #else
		#if defined(__MMI_MAINLCD_320X240__)
		    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE320X240"
		#elif defined(__MMI_MAINLCD_240X240__)
		    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE_SLIM240X240"	
	    #elif defined(__MMI_MAINLCD_240X400__)
		    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE240X400"
	    #elif defined(__MMI_MAINLCD_320X480__)
		    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE320X480"
	    #elif defined(__MMI_MAINLCD_480X800__)
		    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE480X800"
	    #else
		    #error FTE SLIM image only support 240X320, FTE image only support 320X240 240X400 320X480 480X800
	    #endif
    #endif
#else // __32_32_SEG__
    #if defined(__MMI_MAINLCD_240X320__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE240X320"
    #elif defined(__MMI_MAINLCD_320X240__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE320X240"
	#elif defined(__MMI_MAINLCD_240X240__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE_SLIM240X240"		
    #elif defined(__MMI_MAINLCD_240X400__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE240X400"
    #elif defined(__MMI_MAINLCD_320X480__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE320X480"
    #elif defined(__MMI_MAINLCD_480X800__)
	    #define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\FTE480X800"
    #else
	    #error FTE image only support 240X320 320X240 240X400 320X480 480X800
    #endif
#endif //__32_32_SEG__

#else /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_MAINLCD_96X64__)
  #define CUST_IMG_PATH     "..\\\\..\\\\Customer\\\\Images\\\\PLUTO96X64"
#elif defined(__MMI_MAINLCD_128X64__)
  #define CUST_IMG_PATH     "..\\\\..\\\\Customer\\\\Images\\\\PLUTO128X64"
#elif defined(__MMI_MAINLCD_128X160__)	
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO128X160"
#elif defined(__MMI_MAINLCD_176X220__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO176X220"
#elif defined(__MMI_MAINLCD_240X320__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO240X320"
#elif defined(__MMI_MAINLCD_320X240__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO320X240"
#elif defined(__MMI_MAINLCD_240X400__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO240X400"
#elif defined(__MMI_MAINLCD_320X480__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO320X480"
#elif defined(__MMI_MAINLCD_360X640__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO360X640"
#elif defined(__MMI_MAINLCD_480X800__)
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO480X800"   
#else
	#define CUST_IMG_PATH			"..\\\\..\\\\Customer\\\\Images\\\\PLUTO128X128"
#endif

#endif /* __MMI_FTE_SUPPORT__ */

#define CUST_IMG_PATH_ROOT CUST_IMG_PATH
#define RES_THEME_ROOT
#define RES_IMG_ROOT

#endif /* __VENUS_MMI__ */    


/* 20061103 SubLCD start */
#if defined(CUST_SUBLCD_PATH)
    #undef CUST_SUBLCD_PATH
#endif
#if defined(__MMI_SUBLCD_48X64BW__)
    #define CUST_SUBLCD_PATH			"..\\\\..\\\\Customer\\\\Images\\\\SubLCDBW48X64"
#elif defined(__MMI_SUBLCD_64X96__)
    #define CUST_SUBLCD_PATH			"..\\\\..\\\\Customer\\\\Images\\\\SubLCD64X96"
#elif defined(__MMI_SUBLCD_96X64BW__)
    #define CUST_SUBLCD_PATH			"..\\\\..\\\\Customer\\\\Images\\\\SubLCDBW96X64"
#elif defined(__MMI_SUBLCD_96X64__)
    #define CUST_SUBLCD_PATH			"..\\\\..\\\\Customer\\\\Images\\\\SubLCD96X64"
#elif defined(__MMI_SUBLCD_128X128__)
    #define CUST_SUBLCD_PATH			"..\\\\..\\\\Customer\\\\Images\\\\SubLCD128X128"
#endif
/* 20061103 SubLCD end */
/*101205 audio resource Calvin Satrt */
	#define CUST_ADO_PATH			"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO"
/*101205 audio resource Calvin End */

#define CUST_BINARY_PATH			"..\\\\..\\\\Customer\\\\Binary"

#ifndef __OPTR_NONE__
#include "Operator_CustResDef.h"
#endif


#define CUST_THIRD_ROM_BIN_PATH     "..\\..\\Customer\\CustResource"

#endif


