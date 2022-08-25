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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "config_hw.h"
#include "emi_hw.h"
#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
#include "wdt_hw.h"
#include "bmt.h"
#include "dcl.h"
#include "drvpdn.h"
#include "SST_init.h"   /* for sw version check in INT_Version_Check() */
#include <stdio.h>
#include <string.h>
#include <rt_misc.h>   /* for __rt_lib_init() */
#include <stdlib.h>
#include "cache_sw.h"
#include "page.h"
#include "l1_interface.h"
#include "bl_features.h"
#include "bl_setting.h"
#include "bl_loader.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "ex_item.h"



#ifdef __CHIP_VERSION_CHECK__
#include "Uart_sw.h"
#endif /* __CHIP_VERSION_CHECK__ */


#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /* __MULTI_BOOT__ */
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "cp15.h"
#endif   /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif /* __SMART_PHONE_MODEM__ */

#if defined(__DSP_FCORE4__)
#include "mdci.h"
#include "SST_dmdsp_ex.h"
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */
#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#endif
#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
#endif

/*******************************************************************************
 * Define pragma
 *******************************************************************************/

#ifdef __ADS__
#if (!defined(MT6208) && !defined(MT6205B))
#pragma import __use_realtime_division
#endif   /* !MT6208 && MT6205B */
#else   /* __ADS__ */
#pragma import __use_realtime_division
#endif   /* __ADS__ */


/*******************************************************************************
 * Define global data
 *******************************************************************************/
/* define the WDT restart register and abnormal reset check resgister */
/* [BB porting] please make sure the register address is correct and scatter file palced in the correct region */
#pragma arm section rodata = "INIT_RODATA"
const kal_uint32 g_WATCHDOG_RESTART_REG   = WDT_RESTART;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = WDT_RESTART_KEY;
#if defined(EMI_base)
const kal_uint32 g_EMI_BASE_REG            = EMI_base;
#endif /* EMI_base */

#if !defined(MT6575)
const kal_uint32 g_ABNORMAL_RST_REG       = WDT_RSTINTERVAL;
const kal_uint32 g_ABNORMAL_RST_VAL        = WDT_RSTINTERVAL_VAL;
#else /* MT6575 */
const kal_utin32 g_ABNORMAL_RST_REG       = WDT_LENGTH;
const kal_uint32 g_ABNORMAL_RST_VAL        = WDT_LENGTH_TOUT; 
#endif /* MT6575 */
#pragma arm section rodata


/*******************************************************************************
 * Declare import data
 *******************************************************************************/

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/



/*************************************************************************
* FUNCTION
*  AnalogDieID
*
* DESCRIPTION
*  This function returns identification of analog die
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  Identification of analog die
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
analog_die_id AnalogDieID()
{
#if defined(MT6218B)

   if (*(ANALOG_HW_VERSION) == 0x0000 && *(ANALOG_HW_CODE) == 0x0000)
      return B63216A;
   else if (*(ANALOG_HW_VERSION) == 0x8c00 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216A;
   else
      return UNKNOWN_ANALOG_DIE;

#elif defined(MT6219)   /* #ifdef MT6218B */

   if (*(ANALOG_HW_VERSION) == 0x8c00 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216A;
   else if (*(ANALOG_HW_VERSION) == 0x8c01 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216B;
   else
      return UNKNOWN_ANALOG_DIE;

#else   /* #ifdef MT6218B */

   return UNKNOWN_ANALOG_DIE;

#endif   /* MT6218B */
}

#if defined(__CHIP_VERSION_CHECK__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* [BB porting] Please make sure the version register and build code is correct */
extern void U_PutUARTByte(UART_PORT port, kal_uint8 data);
void INT_Version_Check(void)
{
   volatile register kal_uint16 HwCode;
   register kal_uint8 HExtra = ' ';
   register kal_uint16 BuildCode;
   volatile register kal_int32 i;

   HwCode = *HW_CODE;
   BuildCode = *HW_VER;
   
   // MT6217AT/AN
   if ((HwCode == 0x6218) && (BuildCode == 0x8B03))
   {
      HwCode = 0x6217;
   }
   // MT6223P
   else if ((HwCode == 0x6223) && (*((volatile kal_uint16 *)(CONFIG_base+0xf010)) & 0x8000))
   {
      HExtra = 'P';
   }
   // MT6226M
   else if ((HwCode == 0x6219) && ((BuildCode & 0xFF00) == 0x8B00))
   {
      HwCode = 0x6226;
      HExtra = 'M';
   }
   // MT6226D
   else if ((HwCode == 0x6226) && ((BuildCode & 0xFF00) == 0x8D00))
   {
      HExtra = 'D';
   }
   // MT6227D
   else if ((HwCode == 0x6227) && ((BuildCode & 0xFF00) == 0x8D00))
   {
      HExtra = 'D';
   }
#if defined(MT6235) || defined(MT6235B)   
   else if ((HwCode == 0x6235) && ( 0x1 & (*(volatile unsigned long *)0x8000F018)) )
   {
      HExtra = 'B'; 
   }
#endif /* MT6235 && MT6235B */
   // MT6253E (HW_CODE=0x6250)
#if defined(MT6253E) || defined(MT6253L)
   else if ((HwCode == 0x6250) && ((*HW_SUBCODE & 0xFF00) == 0x8A00))
   {
      HExtra = 'E';
   }   
   // MT6253L (HW_CODE=0x6250)
   else if ((HwCode == 0x6250) && ((*HW_SUBCODE  & 0xFF00) == 0x8B00))
   {
      HExtra = 'L';
   }   
#elif defined(MT6252H) || defined(MT6252)  /* MT6253E || MT6253L */
   // MT6258H & MT6258 (HW_CODE=0x6250)
   else if ((HwCode == 0x6250) && ((*HW_SUBCODE & 0xFF00) == 0x8A00))
   {
      HExtra = 'H';
   }   
#endif /* MT6253E || MT6253L */
   // MT6276M  (HW_CODE=0x6270 & HW_SUBCODE = 0x8A00)
#if defined(MT6276)
   else if ((HwCode == 0x6270) && ((*HW_SUBCODE & 0xFF00) == 0x8A00))
   {
      HwCode = 0x6276;
   }   
#endif /* MT6276 */



#if defined(MT6205B)
   BuildCode = 0x6205;
#elif defined(MT6217)
   BuildCode = 0x6217;
#elif defined(MT6219)
   BuildCode = 0x6219;
#elif defined(MT6223)
   BuildCode = 0x6223;
#elif defined (MT6223P)
   BuildCode = 0x6223;
   #define   ExtraVer 'P'
#elif defined(MT6225)
   BuildCode = 0x6225;
#elif defined(MT6253T)
   BuildCode = 0x6253;
#elif defined(MT6253)
   BuildCode = 0x6253;
#elif defined(MT6251)
   BuildCode = 0x6251;
#elif defined(MT6253E)
   BuildCode = 0x6250;
   #define   ExtraVer 'E'   
#elif defined(MT6253L)
   BuildCode = 0x6250;
   #define   ExtraVer 'L'      
#elif defined(MT6252H)
   BuildCode = 0x6250;
   #define   ExtraVer 'H'   
#elif defined(MT6252)
   BuildCode = 0x6250;
#elif defined(MT6250)
   BuildCode = 0x625A;
#elif defined(MT6260)
   BuildCode = 0x6260;
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
   BuildCode = 0x6261;
#elif defined(MT6226)
   BuildCode = 0x6226;
#elif defined(MT6226D)
   BuildCode = 0x6226;
   #define   ExtraVer 'D'
#elif defined(MT6226M)
   BuildCode = 0x6226;
   #define   ExtraVer 'M'
#elif defined(MT6227)
   BuildCode = 0x6227;
#elif defined(MT6227D)
   BuildCode = 0x6227;
   #define   ExtraVer 'D'
#elif defined(MT6228)
   BuildCode = 0x6228;
#elif defined(MT6229)
   BuildCode = 0x6229;
#elif defined(MT6230)
   BuildCode = 0x6230;
#elif defined(MT6235) 
   BuildCode = 0x6235;
#elif defined(MT6235B)
   BuildCode = 0x6235;
   #define   ExtraVer 'B'
#elif defined(MT6238) 
   BuildCode = 0x6238;
#elif defined(MT6239)
   BuildCode = 0x6239; 
#elif defined(MT6516)
   BuildCode = 0x6516; 
#elif defined(MT6268A) || defined(MT6268)
   BuildCode = 0x6268;
#elif defined(MT6236) || defined(MT6236B)
   BuildCode = 0x6236;
#elif defined(MT6270A)
   BuildCode = 0x6270;
#elif defined(MT6256)
   BuildCode = 0x6256;
#elif defined(MT6255)
   BuildCode = 0x6255;
#elif defined(MT6276)
   BuildCode = 0x6276;
#elif defined(MT6573)
   BuildCode = 0x6573;
#else
   BuildCode = 0;
#endif

#ifndef ExtraVer
   #define   ExtraVer ' '
#endif


#if defined(__GEMINI__)
   
   if (*HW_CODE == 0x6223)
   {
      if (*HW_VER >= 0x8a05  && (*((volatile kal_uint16 *)(CONFIG_base+0xf010)) & 0x8000))
      {
      }
      else
      {
         while(1)
         {
            U_PutUARTByte(uart_port1, ' ');
            U_PutUARTByte(uart_port1, 'H');
            U_PutUARTByte(uart_port1, 'W');
            U_PutUARTByte(uart_port1, '=');
            U_PutUARTByte(uart_port1, 'M');
            U_PutUARTByte(uart_port1, 'T');
            for(i = 12; i >= 0; i -= 4)
            {
               U_PutUARTByte(uart_port1, '0' + ((HwCode >> i) & 0x0F));
            }
            U_PutUARTByte(uart_port1, HExtra);
            U_PutUARTByte(uart_port1, ',');
            U_PutUARTByte(uart_port1, ' ');
            U_PutUARTByte(uart_port1, 'S');
            U_PutUARTByte(uart_port1, 'W');
            U_PutUARTByte(uart_port1, '=');
            U_PutUARTByte(uart_port1, 'G');
            U_PutUARTByte(uart_port1, 'E');
            U_PutUARTByte(uart_port1, 'M');
            U_PutUARTByte(uart_port1, 'I');
            U_PutUARTByte(uart_port1, 'N');
            U_PutUARTByte(uart_port1, 'I');
            U_PutUARTByte(uart_port1, '\r');
            U_PutUARTByte(uart_port1, '\n');
         }
      }
   }
   
#endif /* __GEMINI__ */

   if ((HwCode != BuildCode) || (HExtra != ExtraVer))
   {
      U_PutUARTByte(uart_port1, '@');
      while(1)
      {
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'H');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((HwCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, HExtra);
         U_PutUARTByte(uart_port1, ',');
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'S');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((BuildCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, ExtraVer);
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, '\r');
         U_PutUARTByte(uart_port1, '\n');   
         
         for(i = 0xFFFFF; i > 0; i--) ;
         U_PutUARTByte(uart_port1, '#');
      }
   }
}

/*************************************************************************
* FUNCTION
*  INT_SW_VersionCheck
*
* DESCRIPTION
*  This function checks if sw sec version is matched with chip sw sec version
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SW_VersionCheck(void)
{
   kal_int8 chipSWSecVer;
   kal_int8 binSWSecVer;
   char tempStr[50];

   /* SW second version check */
   chipSWSecVer = *SW_VER & 0x00FF;
   binSWSecVer = SW_MINOR_VER;

   sprintf(tempStr, "Chip SW second version: %02d", chipSWSecVer);
   tst_sys_trace(tempStr);
   sprintf(tempStr, "Bin file SW second version: %02d", binSWSecVer);
   tst_sys_trace(tempStr);

   if(binSWSecVer < chipSWSecVer) {
      /* show catcher log warning */
      tst_sys_trace("[Warning] SW second version of bin file is smaller than chip!");
   }
}
#else /* __CHIP_VERSION_CHECK__ && !__UBL__ */
/* fake function */
void INT_Version_Check(void)
{
}

void INT_SW_VersionCheck(void)
{
}
#endif /* __CHIP_VERSION_CHECK__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  INT_ecoVersion
*
* DESCRIPTION
*  This function returns the ECO version number of baseband chipset
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* [BB porting] Please make sure the the correlated enum and code is added since the default case is ext_assert */
/* Please be aware that new chips may use INT_SW_SecVersion */
ECO_VERSION INT_ecoVersion(void)
{
#if defined(MT6205B)

   if (*HW_CODE == 0x6205 && *HW_VER == 0x8b00)

      return EN;

   return MT6205B_latest_chip;

#elif defined(MT6218)   /* MT6205B */

   if (*HW_CODE == 0x6218 && *HW_VER == 0x8a00)

      return AN;

   return MT6218_latest_chip;

#elif defined(MT6218B)   /* MT6205B */

   if (*HW_CODE == 0x6218 && *HW_VER == 0x8b00)

      return BN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b01)

      return CN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b02) {

      if (AnalogDieID() == B63216A)

         return DN;

      else if (AnalogDieID() == C63216A)

         return EN;

   } else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b03)

      return FN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b04)

      return GN;

   return MT6218B_latest_chip;

#elif defined(MT6217)   /* MT6205B */

   if (*HW_CODE == 0x6217 && *HW_VER == 0x8a00) {

      if (AnalogDieID() == C63216B)

         return BN;
   }

   return MT6217_latest_chip;

#elif defined(MT6219)   /* MT6205B */

   if (*HW_CODE == 0x6219 && *HW_VER == 0x8a00) {

      if (AnalogDieID() == C63216A)

         return AV;

      else if (AnalogDieID() == C63216B)

         return BV;

   } else if (*HW_CODE == 0x6219 && *HW_VER == 0x8a01) {

      if (AnalogDieID() == C63216B)

         return EV;

   }

   return MT6219_latest_chip;

#elif defined(MT6227) || defined(MT6226) || defined(MT6226M)

   /* the hardware code of MT6226M IS 6219 */

   if ( (*HW_CODE == 0x6226 || *HW_CODE == 0x6227 || *HW_CODE == 0x6219) && *HW_VER == 0x8a00) {

      return ECO_E1;

   } else if ( (*HW_CODE == 0x6226 || *HW_CODE == 0x6227 || *HW_CODE == 0x6219) && *HW_VER == 0x8a01) {

      return ECO_E2;

   }

   return MT6227_latest_chip;

#elif defined(MT6225)

   if (*HW_CODE == 0x6225 && *HW_VER == 0x8a00) {
      return ECO_E1;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a01) {
      return ECO_E2;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a02) {
      return ECO_E3;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a03) {
      return ECO_E4;
   }

   return MT6225_latest_chip;

#elif defined(MT6228)

   return MT6228_latest_chip;

#elif defined(MT6229)

   return MT6229_latest_chip;
   
#elif defined(MT6230)

   return MT6230_latest_chip;   
   
#elif defined(MT6223)   || defined(MT6223P)

  if (*HW_CODE == 0x6223 && *HW_VER == 0x8a04) {
      return ECO_A1;   
   }
   else if (*HW_CODE == 0x6223 && *HW_VER >= 0x8a07) { /* used by SIM (JY Lan) */
      if ( *((volatile kal_uint16 *)(CONFIG_base+0xf010)) & (0x1 << 14)) {
         return ECO_D_AFTER_E10;
      } else if ( *((volatile kal_uint16 *)(CONFIG_base+0xf010)) & (0x1 << 15)) {
         return ECO_C_AFTER_E10;
      }      
   }   
   else if (*HW_CODE == 0x6223 && *HW_VER >= 0x8a05) {
     if (*HW_VER == 0x8a06 && *SW_MISC_H == 0x0100) {
      return ECO_B;
   } else if ( *((volatile kal_uint16 *)(CONFIG_base+0xf010)) & (0x1 << 14)) {
      return ECO_D;
   } else if ( *((volatile kal_uint16 *)(CONFIG_base+0xf010)) & (0x1 << 15)) {
      return ECO_C;
   }
   }

   return MT6223_latest_chip;

#elif defined(MT6227D) || defined(MT6226D)

   if (*HW_CODE == 0x6227 && *HW_VER == 0x8D01) {
      return ECO_E3;
   } else if (*HW_CODE == 0x6227 && *HW_VER == 0x8D02) {
      return ECO_E4; 
   }
   return MT6227D_latest_chip;

#elif defined(MT6238)

   if ( 0x20070329 == *(volatile UINT32P)(0x840b0274)  && *HW_CODE == 0x6238 && *HW_VER == 0x8A00 ) {
      return ENG_E1;
   } 
   else if (0x20070918 == *(volatile UINT32P)(0x840b0274) && *HW_CODE == 0x6238 && *HW_VER == 0x8A00 ) {
      return ENG_E2; 
   }
   else if (*HW_CODE == 0x6238 && *HW_VER == 0x8A01) {
      return ECO_E3;
   }
   
   return MT6238_latest_chip;

#elif  defined(MT6239)

   if (0x20070329 == *(volatile UINT32P)(0x840b0274)  && *HW_CODE == 0x6239 && *HW_VER == 0x8A00 ) {
      return ENG_E1;
   } 
   else if (0x20070918 == *(volatile UINT32P)(0x840b0274) && *HW_CODE == 0x6239 && *HW_VER == 0x8A00 ) {
      return ENG_E2; 
   }
   else if (*HW_CODE == 0x6239 && *HW_VER == 0x8A01) {
      return ECO_E3;
   }

   return MT6239_latest_chip;

#elif defined(MT6235) || defined(MT6235B)

   if(*HW_CODE == 0x6235 && *HW_VER == 0x8A00)
   {
        return ECO_E1;
   }
   else if(*HW_CODE == 0x6235 && *HW_VER == 0x8A01)
   {
      return ECO_E2;
   }
   else if (*HW_CODE == 0x6235 && ( 0x8A02 == *HW_VER || 0x8A03 == *HW_VER))
   {
      if ( 0x2 & (*(volatile unsigned long *)0x8000F018))
         return ECO_E4_R;
      else
         return ECO_E4;
   }
   else if (*HW_CODE == 0x6235 && 0x8A04 == *HW_VER)
   {
        return ECO_E5;
   }
   else if (*HW_CODE == 0x6235 && *HW_VER == 0x8B00)
   {
      return AL_E1;
   }

   return MT6235_latest_chip;

#elif defined(MT6268T) || defined(MT6268H)

   return MT6268T_latest_chip;

#elif defined(TK6516)

   return TK6516_latest_chip;

#elif defined(MT6516)

   return MT6516_latest_chip;

#elif defined(MT6268A)

   return MT6268A_latest_chip;

#elif defined(MT6253T) || defined(MT6253)

   if (*HW_CODE == 0x6253)
   {
        if (*HW_VER == 0x8000) {
            return ECO_E2;
        } else if (*HW_VER == 0x8a00) {
            return ECO_E3;
        } else if (*HW_VER == 0x8a01) {
            return ECO_E4;
        } else if (*HW_VER == 0x8a02) { //for E5, E6 and E7
            if ((*SW_MISC_H>>8) == 0x0)
                return ECO_E5; // ECO_E6 and ECO_E7_0 are same as ECO_E5
            else if ((*SW_MISC_H>>8) == 0x1)
                return ECO_E7_1;
            else if ((*SW_MISC_H>>8) == 0x2)
                return ECO_E7_2;
        } else if (*HW_VER == 0x8a03) {
            return ECO_E8;
        }
    }

   return MT6253_latest_chip;


#elif defined(MT6251)
   if(*HW_CODE == 0x6251 && *HW_VER == 0x8a00)
   {
        return ECO_E1;
   }

   return MT6251_latest_chip;

#elif defined(MT6253E) || defined(MT6252H)


    if(*HW_CODE == 0x6250 && *HW_VER == 0xca00)
    {
       return ECO_E1;
    }
    else if(*HW_CODE == 0x6250 && *HW_VER == 0xca01)
    {
        return ECO_E2;
    }
    else if(*HW_CODE == 0x6250 && *HW_VER == 0xca02)
    {
        return ECO_E3;
    }

    return MT6253E_latest_chip;
   
#elif defined(MT6253L) || defined(MT6252)

    if(*HW_CODE == 0x6250 && *HW_VER == 0xca00)
    {
       return ECO_E1;
    }
    else if(*HW_CODE == 0x6250 && *HW_VER == 0xca01)
    {
        return ECO_E2;
    }
    else if(*HW_CODE == 0x6250 && *HW_VER == 0xca02)
    {
        return ECO_E3;
    }

    return MT6253L_latest_chip;   

#elif defined(MT6250)

   return MT6250_latest_chip;

#elif defined(MT6260)

   return MT6260_latest_chip;

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)

   return MT6261_latest_chip;

#elif defined(MT6268)

   if( *HW_CODE == 0x6268 && *HW_VER == 0x8b00) {
       return ECO_E1;
   }
   else if( *HW_CODE == 0x6268 && *HW_VER == 0x8b01) {
       return ECO_E2;
   }
   
   return MT6268_latest_chip;   

#elif defined(MT6236) || defined(MT6236B)

   if( *HW_CODE == 0x6236 && *HW_VER == 0x8a00) {
       return ECO_E1;
   }
   else if( *HW_CODE == 0x6236 && *HW_VER == 0x8a01) {
       return ECO_E2;
   }
   else if( *HW_CODE == 0x6236 && *HW_VER == 0x8a02) {
       return ECO_E3;
   }

   return MT6236_latest_chip;

#elif defined(MT6270A)

   return MT6270A_latest_chip;

#elif defined(MT6256)

   return MT6256_latest_chip;

#elif defined(MT6255)

   return MT6255_latest_chip;

#elif defined(MT6276)

   if( *HW_CODE == 0x6276 && *HW_VER == 0x8a00) {
       return ECO_E1;
   }
   else if (( *HW_CODE == 0x6276 || *HW_CODE == 0x6270 ) && *HW_VER == 0xca00)
   {
        return ECO_E2;
   }

   

   return MT6276_latest_chip;

#elif defined(MT6573)
    
    
   if( *HW_CODE == 0x6573 && *HW_VER == 0x8a00) {
       return ECO_E1;
   }

   return MT6573_latest_chip;
    

#else   /* MT6205B */

   /* no one should invoke this function for unknown chip */

   ASSERT(0);

   return 0;

#endif   /* MT6025B */
}


/*************************************************************************
* FUNCTION
*  INT_GetCurrentTime
*
* DESCRIPTION
*  This function access 32KHz Counter and return Counter Value
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  Value of 32KHz Counter
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* [BB porting] confirm with L1 if the function is support in new chip */
#if defined(__MTK_TARGET__)
#if defined(__UBL__) || defined(__FUE__)
#pragma arm section code = "INTERNCODE"
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#pragma arm section code = "SNORCODE"
#endif
#endif //__MTK_TARGET__

kal_uint32 INT_GetCurrentTime(void)
{
#if (defined(MT6516) && defined(__APPLICATION_PROCESSOR__))  || (defined(MT6573) && defined(__APPLICATION_PROCESSOR__))
   return 0; // Not Support Yet
#else   
   /* 
    * Call API provided by L1
    */
   return HW_TDMA_GET_32KCNT();
#endif /* MT6516 && __APPLICATION_PROCESSOR__ */   
}

#if defined(__MTK_TARGET__)
#if defined(__UBL__) || defined(__FUE__)|| defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#pragma arm section code
#endif //__UBL__  || __SINGLE_BANK_NOR_FLASH_SUPPORT__
#endif //__MTK_TARGET__

/*************************************************************************
* FUNCTION
*  INT_ChipName
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Make sure if the rule is changed or need to add for a new chip */
CHIP_NAME INT_ChipName(void)
{

#if defined(MT6276)

   if (*HW_CODE == 0x6276 && *HW_SUBCODE== 0x8A00)
   {
      return CHIP_MT6276;
   }
   else if (*HW_CODE == 0x6270 && *HW_SUBCODE== 0x8A00)
   {
      return CHIP_MT6276M;
   }

#elif defined(MT6238) || defined(MT6239)
   
   if (*HW_CODE == 0x6238)
      return CHIP_MT6233;
   else if (*HW_CODE == 0x6239)
      return CHIP_MT6239;
   else 
      return CHIP_UNKNOWN;

#elif defined(MT6235) || defined(MT6235B)

   if ( 0x1 & (*(volatile unsigned long *)0x8000F018))
      return CHIP_MT6235B;
   else
      return CHIP_MT6235;      

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)

    unsigned int val = ((*(volatile unsigned int *)0xA01C0108) >> 28) & 0x3;
    if (val == 0x1)
        return CHIP_MT2501;
    else if (val == 0x2)
        return CHIP_MT2502;
    else
        return CHIP_MT6261;
        
#else   
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return CHIP_UNKNOWN;   
#endif /* MT6276 */
}


/*************************************************************************
* FUNCTION
*  INT_SW_SecVersion
*
* DESCRIPTION
*  This function is used for SW to query the software secondary version
*  
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Check if the chip support new version and if the SW secondary version is changed */
SW_SECVERSION INT_SW_SecVersion(void)
{

#if defined(MT6276) || defined(MT6251) || defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6261) || defined(MT2501) || defined(MT2502)

    if ( (*SW_VER & 0x00FF) == 0x00)
    {
        return SW_SEC_0;
    }
    else if ((*SW_VER & 0x00FF) == 0x01)
    {
        return SW_SEC_1;
    }
   else if ((*SW_VER & 0x00FF) == 0x02)
    {
        return SW_SEC_2;
    }
    else
    {
        return SW_LATEST_SEC;
    }

#else

    ASSERT(0);
    
#endif

}

/*************************************************************************
* FUNCTION
*  INT_ChipGroup
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*  
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] May not need to maintain this, check if we could remove */
CHIP_GROUP INT_ChipGroup(void)
{
#if defined(MT6253)

    #define FAB_CODE ((*SW_MISC_H >> 8) & 0xFF)

    if (!(*CHIPID3 & (0x1 << 25)))
    {
        return GP_MT6253;
    }
    else if ( (FAB_CODE >= 2) && (FAB_CODE <= 32) )
    {
        
        return GP_MT6253D;
    }
    else
    {
        return GP_MT6253DV;
    } 

#else   
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return GP_UNKNOWN;   
#endif /* MT6253  */
}

