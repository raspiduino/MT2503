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
 *    drv_features_kbd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for the keypad driver feature option
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_FEATURES_KBD_H__
#define __DRV_FEATURES_KBD_H__

#include "drv_features_chip_select.h"
#if defined(DRV_KBD_6205_SERIES)
   #define DRV_KBD_32KEYS_EQ_BELOW
   #define DRV_KBD_25_KEYS
#elif defined(DRV_KBD_6217_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_42_KEYS
#elif defined(DRV_KBD_6225_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_42_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
#elif defined(DRV_KBD_6218_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_36_KEYS
#elif defined(DRV_KBD_6223_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_35_KEYS
#elif defined(DRV_KBD_6238_SERIES)
   #define DRV_KBD_64KEYS_ABOVE
   #define DRV_KBD_72_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
#elif defined(DRV_KBD_6253_SERIES)
   #define DRV_KBD_48KEYS_ABOVE
   #define DRV_KBD_54_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
   #define DRV_KBD_DRVTOOL_EXTEND_72_KEYS
#elif defined(DRV_KBD_6253EL_SERIES)
    #if defined(__EXTEND_QWERTY_KEYPAD__)
    #define DRV_KBD_48KEYS_ABOVE
    #define DRV_KBD_54_KEYS
   #else
      #define DRV_KBD_64KEYS_ABOVE
      #define DRV_KBD_72_KEYS
   #endif
   #define DRV_KBD_MUX_WITH_GPIO
   #define DRV_KBD_DRVTOOL_EXTEND_72_KEYS
#elif defined(DRV_KBD_6251_SERIES)
   #define DRV_KBD_48KEYS_ABOVE
   #define DRV_KBD_54_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
#elif defined(DRV_KBD_6276_SERIES)
   #define DRV_KBD_64KEYS_ABOVE
   #define DRV_KBD_72_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
   #define DRV_KBD_GPIO_DRIVING_2MA  //only for MT6276 
 // lxg add2.10 for MT6250 start  
 #elif defined(DRV_KBD_6250_SERIES)
  #ifndef __COLUMN_EXTEND_KEYPAD__  //from option.mak
   #define DRV_KBD_64KEYS_ABOVE
   #define DRV_KBD_72_KEYS
   #else
   #define DRV_KBD_48KEYS_ABOVE
   #define DRV_KBD_55_KEYS
  #endif
    #define DRV_KBD_PWRKEY_FROM_EINT  //only for 6250, power key sperate from keypad controler
    #define DRV_KBD_PWRKEY_SATUS_0F00
     #define DRV_KBD_MUX_WITH_GPIO
   // #define DRV_KBD_FOR_BRING_UP          //just for bring up 
// lxg add11.8 for MT6260 
  #elif defined(DRV_KBD_6260_SERIES)

/*sw keypad option*/
#ifndef __BOX_QC_INTERNAL__
#define DRV_KBD_SW_KBD
#endif
#ifdef DRV_KBD_SW_KBD
//#define SW_KBD_API_TEST 
#define SW_KBD_OPTIONAL_SCAN
#define SW_KBD_TRIGGER_EINT
#define SW_KBD_COL_PUPD_1_2M
//#define SW_KBD_DEBUG
#endif
/**/
/*For  keypad performace test*/
//#define DRV_KBD_PERFORMACE_TEST
    #include "keypad_drv.h"
/* keypad type form drv tool, ex: __COLUMN_EXTEND_KEYPAD__*/
#if defined(DRV_KBD_TRIPLE_KEYPAD)
   #define DRV_KBD_64KEYS_ABOVE
#define DRV_KBD_75_KEYS
/*double keypad*/
#elif defined(__COLUMN_EXTEND_KEYPAD__)
   #define DRV_KBD_48KEYS_ABOVE
   #define DRV_KBD_55_KEYS
/*single keypad*/
#else
#define DRV_KBD_64KEYS_ABOVE
#define DRV_KBD_72_KEYS
  #endif
   #define DRV_KBD_PWRKEY_FROM_EINT  //only for 6260, power key sperate from keypad controler
   #define DRV_KBD_PWRKEY_SATUS_0048
   #define DRV_KBD_MUX_WITH_GPIO
//#define DRV_KBD_FOR_BRING_UP          //just for bring up  
//#define DRV_KBD_WAKEUP_EINT_HISR
#elif defined(DRV_KBD_6261_SERIES)
/*sw keypad option*/
#define DRV_KBD_SW_KBD
/*------------------------------------------------------------*/
#if defined(__MTK_INTERNAL__) 
#if defined(__FLAVOR_BTDV3_FTE_QVGA_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_1LINK_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_ON_61PHONE_BQB__)
/* under construction !*/
#endif 
#endif 
/*------------------------------------------------------------*/
#ifdef DRV_KBD_SW_KBD
#define SW_KBD_API_TEST 
#define SW_KBD_OPTIONAL_SCAN
#define SW_KBD_TRIGGER_EINT
#define SW_KBD_COL_PUPD_1_2M
//#define SW_KBD_DEBUG
#endif
/*For  keypad performace test*/
//#define DRV_KBD_PERFORMACE_TEST
#include "keypad_drv.h"
/* keypad type form drv tool, ex: __COLUMN_EXTEND_KEYPAD__*/
#if defined(DRV_KBD_TRIPLE_KEYPAD)
#define DRV_KBD_64KEYS_ABOVE
#define DRV_KBD_75_KEYS
/*double keypad*/
#elif defined(__COLUMN_EXTEND_KEYPAD__)
#ifdef DRV_KBD_SW_KBD
#define DRV_KBD_48KEYS_ABOVE
#define DRV_KBD_55_KEYS
#else /*61 HW keypad use this matrix as the triple key*/
#define DRV_KBD_64KEYS_ABOVE
#define DRV_KBD_75_KEYS
#endif
/*single keypad*/
#else
#define DRV_KBD_64KEYS_ABOVE
#define DRV_KBD_72_KEYS
#endif
#define DRV_KBD_PWRKEY_FROM_EINT  
#define DRV_KBD_PWRKEY_SATUS_0048
#define DRV_KBD_MUX_WITH_GPIO
#define DRV_KBD_STATUS_REG_REORG  /*from MT6261,keypad hw re-orignize key status matrix*/
//#define DRV_KBD_FOR_BRING_UP    /*just for bring up*/
//#define DRV_KBD_WAKEUP_EINT_HISR
#ifndef DRV_KBD_COL_ROW_SEL
#define DRV_KBD_COL_ROW_SEL 0x3ff
#endif
#endif

#ifdef __MEUT__
#define DCL_KBD_INTERFACE
#endif

#endif
