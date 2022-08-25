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
 *   bl_Init.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the initialization functions of bootloader
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "fs_internal_def.h"
#include "kal_general_types.h"
//Special workaround for RHR: include init.h first to get correct PDN address
#include "init.h"
#include "config_hw.h"
#include "reg_base.h"
#include "bl_MTK_BB_REG.h"
#include "bl_init.h"
#include "bl_common.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_loader.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#include <rt_misc.h>   /* for __rt_lib_init() */
//#include "init.h"
#include "feature_def.h"
#include "dcl.h"
#include "dcl_gpio.h"
#include "dcl_f32k_clk.h"
#include "pll.h"
#include "drvpdn.h"

#ifdef __SV5_ENABLED__
#include "bl_GFH_body.h"
#include "br_GFH_file_info.h"
#include "br_GFH_arm_bl_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH.h"
#include "maui_GFH_body.h"
#include "br_bl_param.h"
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#include "br_GFH_emi_list.h"
#endif
#endif /* __SV5_ENABLED__ */

#ifdef __LCD_DRIVER_IN_BL__
#include "device.h"
#endif /* __LCD_DRIVER_IN_BL__ */

#include "rtc_hw.h"
#include "dcl_mixedsys_reg.h"

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
#define REMAPPING_MASK (custom_RAM_baseaddr()-1)

/*************************************************************************
 * Structure definition
 *************************************************************************/
typedef struct 
{
    kal_uint32 size;
    kal_uint32 payload[8];
} BL_SWB_STRUCT;

typedef enum
{
   BL_LCD_UNINIT       = 0x00000000,
   BL_LCD_INITED       = 0x00000001,
   BL_LCD_BACKLIGHT_ON = 0x00000002
} E_BL_LCD_STATUS;

/*************************************************************************
 * External reference definition
 *************************************************************************/

#ifdef __LCD_DRIVER_IN_BL__
extern kal_bool custom_uem_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
/* LCD HW init related functions */
extern void PWM_initialize(void);

#endif /* __LCD_DRIVER_IN_BL__ */

extern kal_int8 custom_setEMI(void);
extern kal_int8 custom_setAdvEMI(void);

extern void NFIReconfigure2(void);
extern kal_uint32 SST_Get_MAUI_Paired_Version(kal_uint32 rom_base);
extern kal_uint32 SST_Get_MAUI_Feature_Combination(kal_uint32 rom_base, kal_uint32 *pFeatureCombination);
extern kal_uint32 SwitchToLogicalFTL(void);

extern void HW_wait_32k_start(void);
extern void HW_TDMA_Start(void);
extern void NLDShareBusCenCtrl(void);

extern const LOG_LEVEL bootloader_debug_level;

#ifdef __SV5_ENABLED__
extern GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void);
extern kal_bool bl_Is_Brom_Cmd_Mode_Disabled(void);
extern kal_uint32 DummyReference(void);
extern void InitFlashDriver(void);
#endif

extern void set_debug_level(LOG_LEVEL level);
extern void lpwr_init(void);
extern void DRVPDN_ini(void);
extern void custom_setSFIExt(void);
extern void BL_Chr_Init(void);
extern void SSS_Init_Crypto_Drv(void * cb_ts_record, void * cb_ts_info);

#if defined(__CRYPTO_SHARED_DRV__)
extern void SSS_Init_Share_Crypto_Drv(void * cb_ts_record, void * cb_ts_info, kal_uint32 init_tbl);
#endif

#ifdef MT6260
extern pmu6260_check_vcore_oc(void);
#endif

/*************************************************************************
 * Forward declearaion
 *************************************************************************/

/*************************************************************************
 * Global variables definition
 *************************************************************************/

#pragma arm section rodata = "BL_RESV_REGION", rwdata = "BL_RESV_REGION"

BL_SWB_STRUCT g_bl_swb_struct = {sizeof(BL_SWB_STRUCT)-4};

#pragma arm section rodata, rwdata

ECO_VERSION eco_version = (ECO_VERSION)(0xff); /* only used in PLL setup, force it to be in RW */

#ifdef __LCD_DRIVER_IN_BL__
E_BL_LCD_STATUS g_lcd_status = BL_LCD_UNINIT;
#endif /* __LCD_DRIVER_IN_BL__ */

/*************************************************************************
 * Main code
 *************************************************************************/

/**********************************************************
Description : Setting MCU PLL.
Input       : None
Output      : None
***********************************************************/
void INT_RestorePLL(void)
{

}

/**********************************************************
Description : Restart watchdog counter.
Input       : None
Output      : None
***********************************************************/

void WacthDogRestart(void)
{
   *(volatile kal_uint32 *)(WDT_RESTART) = WDT_RESTART_CMD;
}

/**********************************************************
Description : Disable watchdog counter.
Input       : None
Output      : None
***********************************************************/

void WacthDogDisable(void)
{
   *(volatile kal_uint32 *)(WDT_MODE) = WDT_DISABLE_CMD;
}

/**********************************************************
Description : Trigger Software Reset
Input       : None
Output      : None
***********************************************************/
void WatchDogResetAll(void)
{
   *(volatile kal_uint16 *)(WDT_SWRST) = WDT_SWRST_CMD;
   while(1);
}

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Wait for 32KHz clock srouce stable.
Input       : None
Output      : None
***********************************************************/
void WaitFor32KStable(void)
{
#if ( defined(MT6516) && defined(__APPLICATION_PROCESSOR__) ) || defined(MT6270A)

   return;

#else /* MT6516 && __APPLICATION_PROCESSOR__ */

   kal_uint32 i;


   /* 32K calibration */
   HW_TDMA_Start();
   for (i = 0; i < 1000; i++) {
   }
   HW_wait_32k_start();

#endif /* MT6516 && __APPLICATION_PROCESSOR__ */

}

/**********************************************************
Description : Device initialization according to definition.
Input       : None
Output      : None
***********************************************************/
void NFIDriverInit(void)
{
#if defined(_NAND_FLASH_BOOTING_)
#if defined(MT6236) || defined(MT6236B)
   //Carlos: Bootloader turns on the NFI power as temp sol since the driver got wrong address of PDN
   PDN_CLR(PDN_NFI);
#endif

#ifndef __NFI_SHARED_DRV__
   /* Without bootloader header, we have no idea about the characteristic of mounted NAND flash. */
   NFIReconfigure();
#endif

#if defined(MT6255) && defined(__NFI_SHARED_DRV__)
   #define MCU_SFC_CTRL_SET 		((volatile kal_uint32*)(CONFIG_base+0x61C))
   *MCU_SFC_CTRL_SET	&= ~0x20;	//Disable NLD share with SF.
#endif

#endif

   // Disable power-down control of DMA
#ifndef __OLD_PDN_ARCH__
   PDN_CLR(PDN_DMA);
#elif defined(MT6235) || defined(MT6235B) 
   *(volatile kal_uint16 *)(DRVPDN_CON0_CLR) = DRVPDN_CON0_DMA;
#elif defined(MT6268) || defined(MT6268T)
   *(volatile kal_uint16 *)(CG_CLR0) = CG_CON0_DMA;
#endif

}

#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", rwdata = "EMIINITRW", zidata = "EMIINITZI"

static kal_bool isUSBMetaFromBootROM = KAL_FALSE;

void efuse_test(kal_uint32);
void printModeAndRTC(void);
kal_bool BL_Init_isUSBMetaFromBootROM(void)
{
   return isUSBMetaFromBootROM;
}

void SetPLLEMI(void *pParam)
{
#ifdef __MTK_INTERNAL__   
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL */

   pll_init_mode pllInitMode = PLL_MODE_MAUI;

   TS_BEGIN(TSID_BL_SET_PLLEMI);
   
#ifdef MT6260
    pmu6260_check_vcore_oc();
#endif

   //Here we only restart WDT. WDT will be disabled if necessary when features are initiated
   WacthDogRestart();

   isUSBMetaFromBootROM = KAL_FALSE;

#ifdef __SV5_ENABLED__

   if(((BL_Param_v4*)(pParam))->m_brom_flags & BL_PARAM_USB_COM_ENABLED)
   {
      pllInitMode = PLL_MODE_USB_META;
      isUSBMetaFromBootROM = KAL_TRUE;
   }

#endif /* __SV5_ENABLED__ */

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#ifdef __MT6261_PRODUCTION_IMPROVE__
     printModeAndRTC();
	 efuse_test(0);
#endif

#ifdef __MTK_INTERNAL__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL */

   TS_BEGIN(TSID_BL_SET_EMI);
   custom_setEMI();
   custom_setSFI();
   TS_END(TSID_BL_SET_EMI);   

   TS_BEGIN(TSID_BL_SET_PLL);
   INT_SetPLL(pllInitMode);
   TS_END(TSID_BL_SET_PLL);

   TS_BEGIN(TSID_BL_SET_ADVEMI);
   custom_setAdvEMI();
   custom_setAdvSFI();
   TS_END(TSID_BL_SET_ADVEMI);      

#else

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   TS_BEGIN(TSID_BL_SET_PLL);
   INT_SetPLL(pllInitMode);
   TS_END(TSID_BL_SET_PLL);

   TS_BEGIN(TSID_BL_SET_EMI);
   custom_setEMI();
   TS_END(TSID_BL_SET_EMI);   
#else   
   if (BlFeatureCombination() & MAUI_FC_NOR_FLASH_BOOTING)
   {
      INT_SetPLL(pllInitMode);
      custom_setEMI();
   }
   else
   {
      custom_setEMI();

#if defined(MT6253L_S01) || defined(MT6252) || defined(__SERIAL_FLASH_EN__)
      custom_setSFI();
#endif

      INT_SetPLL(pllInitMode);

#if defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6276) || defined(MT6256)
      TS_BEGIN(TSID_BL_SET_ADVEMI);
      custom_setAdvEMI();
      TS_END(TSID_BL_SET_ADVEMI);      
#endif

#if defined(MT6253L_S01) || defined(MT6252) || defined(MT6251) || defined(__SERIAL_FLASH_EN__)
      TS_BEGIN(TSID_BL_SET_ADVEMI);
      custom_setAdvSFI();
      TS_END(TSID_BL_SET_ADVEMI);  
#endif
   }
#endif

#endif /* MT6255 and new EMI flow */

   TS_END(TSID_BL_SET_PLLEMI);
}

#pragma arm section code, rodata, rwdata, zidata


void TimeStampInit(void)
{
#ifdef __TIME_STAMP__

   WacthDogRestart();

   DclF32K_Initialize();
   
   WaitFor32KStable();
   
   WacthDogRestart();

   TS_Init(KAL_TRUE);

   TS_BEGIN(TSID_BL_TOTAL);
   TS_BEGIN(TSID_BL_BOOTLOADER);

#endif
}

/*************************************************************************
* FUNCTION
*  printModeAndRTC
*  sefuse_divege_pllInit
*  efuse_diverge_reboot
*  efuse_test
* DESCRIPTION
*  EFUSE patch
*
* Owner: JY Lan
*
*
*************************************************************************/

void printModeAndRTC(void)
{
   kal_int32 i;
   kal_char efuse_STR[] = "m:   ";
   int reg = (*(P_U32)(0xa0010224));
   
   efuse_STR[3] = (((reg & 0xf000)>>12)+0x30);
   //efuse_STR[2] = rtc_getCount() + 0x41;
   efuse_STR[2] = ((*(volatile kal_uint16 *)(RTC_NEW_SPAR2) & RTC_NEW_SPAR_MASK) >> RTC_NEW_SPAR_OFFSET)  + 0x41;
   //efuse_STR[4] = (rtc_getCount()& 0x1);
   for(i=0; i<sizeof(efuse_STR); i++)
   {
      PutUARTByte(efuse_STR[i]);
   }
   
   /*when print log, Delay 5ms*/
   //for (i = 0; i < 500000; i++) {}
   gpt4_busy_wait_us(2000);

}
void efuse_divege_pllInit(kal_uint32 rtcInput)
{
				
        volatile kal_uint32 i, reg_val, loop_1us, tmp;

    

        // enable HW mode TOPSM control and clock CG of PLL control 
        *PLL_PLL_CON2 = 0x0000; // 0xA0170048, bit 12, 10 and 8 set to 0 to enable TOPSM control 
        // bit 4, 2 and 0 set to 0 to enable clock CG of PLL control
        *PLL_PLL_CON3 = 0x0000; // 0xA017004C, bit 12 set to 0 to enable TOPSM control

        // enable delay control 
        *PLL_PLLTD_CON0= 0x0000; //0x A0170700, bit 0 set to 0 to enable delay control

        //wait for 1us for TOPSM and delay (HW) control signal stable
        gpt4_busy_wait_us(1);

        //enable and reset UPLL
        tmp = *PLL_UPLL_CON0;
        tmp  |= 0x0001;
        *PLL_UPLL_CON0 = tmp; // 0xA0170140, bit 0 set to 1 to enable UPLL and generate reset of UPLL
     
        //select MPLL frequency


	if((( rtcInput == 2) || ( rtcInput == 5)))
	{
        	*PLL_MPLL_CON0  = 0x1400; // 0xA0170100, set MPLL = 520M
        	*PLL_MPLL_CON1  = 0x0000; // 0xA0170104, set post divider = /1
	}
	else if((( rtcInput == 3)))
	{
        	*PLL_MPLL_CON0  = 0x1800; // 0xA0170100, set MPLL = 624M
	        *PLL_MPLL_CON1  = 0x0000; // 0xA0170104, set post divider = /1	
	}
	else{// rtcInput = 1 or 4
	        *PLL_MPLL_CON0  = 0x1400; // 0xA0170100, set MPLL = 520M
        	*PLL_MPLL_CON1  = 0x0000; // 0xA0170104, set post divider = /1	
	}
			
        //enable MDDS
        *PLL_MDDS_CON0 = 0x0001; //0x A0170640, bit 0 set to 1 to enable MDDS

        //enable and reset MPLL
        tmp = *PLL_MPLL_CON0;
        tmp  |= 0x0001;
        *PLL_MPLL_CON0  = tmp; //0xA0170100, bit 0 set to 1 to enable MPLL and generate reset of MPLL

        //wait 50us for PLL and DDS settle
        gpt4_busy_wait_us(50);

        //Disable DDS LDO PG detector to save power
        tmp = *PLL_PLL_CON4;
        tmp  &= 0xFFFB;
        *PLL_PLL_CON4 = tmp; //0xA0170050, bit 2 set to 0


	//clock switch
	if((( rtcInput == 2) || ( rtcInput == 3) || ( rtcInput == 5))){//atpg,  rtcInput = 2 or 3
        // Sequence to switch to PLL clocks as below: 
		if(( rtcInput == 3) )
			*PLL_CLK_CONDA |= 0x8100; //0xA001_0100, disables MPLL/5.5, enables MPLL/6 and UPLL/2 clock divider
		else // rtcInput == 2 or 5
			*PLL_CLK_CONDA |= 0x0100; //0xA001_0100, enables MPLL/6 and UPLL/2 clock divider

		if(( rtcInput == 3) )
		{
			*PLL_CLK_CONDH = 0xDA12; // 0xA001_011C, SFC_MUX_SEL = 3'b010
			*PLL_CLK_CONDA |=0x1000; //0xA001_0100, ARM sets to 208M
		}
		else // rtcInput == 2 or 5
		{
			*PLL_CLK_CONDH = 0xD001; // 0xA001_011C, SFC_MUX_SEL = 3'b001
		}
	        *PLL_CLK_CONDC = 0x8008;   // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider
        	// wait for 2us to enable divider
        	gpt4_busy_wait_us(2);

	        // 0xA001_0108, sets gfmux
        	// sfc_gfmux_sel = 1'b1, 
	        // arm_gfmux_sel = 3'b100,
        	// dsp_gfmux_sel = 1'b1,
	        // x4g_gfmux_sel = 1'b1, 
        	// rg_pllck_sel  = 1'b1
	        *PLL_CLK_CONDC = 0xB621; 
	}//atpg,  rtcInput = 2 or 3 or 5
	else if((( rtcInput == 1) || ( rtcInput == 4)))
	{
	}
}
/*
	rtcInput is a value between 1~5
*/
void efuse_diverge_reboot(kal_uint32 rtcInput)
{
	    int i = 0;



				efuse_divege_pllInit(rtcInput);
				
   custom_setEMI();
   custom_setSFI();
	
   			custom_setAdvEMI();
   			custom_setAdvSFI();


						//set EMIMBIST
						*(volatile kal_uint32 *) (0xA0050308) = 0x10002FFF;  //range: 0x20_0000 to max (保留0x0~0x20_0000，假如有其他人要使用)
						*(volatile kal_uint32 *) (0xA0050300) = 0xA55A2321;  //long burst write, random access
				
				//set Vcore, VIO18, VIO28 according to rtc
				switch(rtcInput){
					case 1:
							DRV_SetData(0xA0700230, 0x01f0, 0x060);
							DRV_SetData(0xA0700154, 0x00f0, 0x80);
							DRV_SetData(0xA0700204, 0x00f0, 0x80);
        /*Delay 4ms*/
							//for (i = 0; i < 100; i++) {}
							gpt4_busy_wait_us(4);
							break;
					case 2:
							DRV_SetData(0xA0700230, 0x01f0, 0x080);
							DRV_SetData(0xA0700154, 0x00f0, 0x70);
							DRV_SetData(0xA0700204, 0x00f0, 0x70);
        /*Delay 4ms*/
							//for (i = 0; i < 1000000; i++) {}
							gpt4_busy_wait_us(4);
							break;
					case 3:
							DRV_SetData(0xA0700230, 0x01f0, 0x040);
							DRV_SetData(0xA0700154, 0x00f0, 0x80);
							DRV_SetData(0xA0700204, 0x00f0, 0x70);
        /*Delay 4ms*/
							//for (i = 0; i < 1000000; i++) {}
							gpt4_busy_wait_us(4);
							break;
					case 4:
							DRV_SetData(0xA0700230, 0x01f0, 0x060);
							DRV_SetData(0xA0700154, 0x00f0, 0x70);
							DRV_SetData(0xA0700204, 0x00f0, 0x70);
        /*Delay 4ms*/
							//for (i = 0; i < 100000; i++) {}
							gpt4_busy_wait_us(4);
							break;
					case 5:
							DRV_SetData(0xA0700230, 0x01f0, 0x080);
							DRV_SetData(0xA0700154, 0x00f0, 0x80);
							DRV_SetData(0xA0700204, 0x00f0, 0x80);
        /*Delay 4ms*/
							//for (i = 0; i < 100; i++) {}
							gpt4_busy_wait_us(4);
							break;
					default:
							while(1);
				}


				





#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


        /*           LSRSTB = 0
                        // LSRSTB (GPIO45: output low) testmode

        */
        *(volatile kal_uint32 *)(0xA0020318) = 0x00002000;
        *(volatile kal_uint32 *)(0xA0020014) = 0x00002000;       







        *(volatile kal_uint32 *)(0xA0700A84) = (*(P_U32)(0xA0700A84)) & 0xFFF7 ;
        /*Delay 10us, =>really it is 1us*/
        //for (i = 0; i < 1000; i++) {}
        gpt4_busy_wait_us(10);
        

        /*Reboot*/
        *(volatile kal_uint32 *)(0xA0700120) = (*(P_U32)(0xA0700120)) & 0xFFFE ;

				/*while loop here, previous command is to shutdown Vcore, need time for LDO falling*/
				while(1);


}
void efuse_test(kal_uint32 printLog)
{
    #define WDT_base                RGU_base
    #define WDT_STATUS  	           (WDT_base+0x000C)
    #define WDT_STATUS_BITMASK	 0x8000
    
    int reg = (*(P_U32)(0xa0010224));
    kal_uint16 atpg_mode_counter = 0;
    kal_uint16 reg_value = 0;

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //RTC unprotect
    //DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT1);
    *(volatile kal_uint16 *)(RTC_PROT) = (kal_uint16)(RTC_PROTECT1);
    //DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
    *(volatile kal_uint16 *)(RTC_WRTGR) = (kal_uint16)(RTC_WRTGR_WRTGR);
    //while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
    while(*(volatile kal_uint16 *)(RTC_BBPU) & 0x40);
    
    //DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT2);
    *(volatile kal_uint16 *)(RTC_PROT) = (kal_uint16)(RTC_PROTECT2);
    //DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
    *(volatile kal_uint16 *)(RTC_WRTGR) = (kal_uint16)(RTC_WRTGR_WRTGR);
    //while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
    while(*(volatile kal_uint16 *)(RTC_BBPU) & 0x40);

    if( ((reg & 0xf000) == 0x1000)  || printLog)
    {

	    //if not meta mode and not watchdog reset
        if (((*(volatile kal_uint16 *)(0xA0010010)&0x0001)==0) && ((*(volatile kal_uint16 *)(WDT_STATUS) & WDT_STATUS_BITMASK)==0))
        {
            //if first power on
            if (((*(volatile kal_uint16 *)(RTC_POWERKEY1)!=RTC_POWERKEY1_KEY) || (*(volatile kal_uint16 *)(RTC_POWERKEY2)!=RTC_POWERKEY2_KEY)) &&
                ((*(volatile kal_uint16 *)(RTC_POWERKEY1)!=RTC_POWERKEY2_KEY) || (*(volatile kal_uint16 *)(RTC_POWERKEY2)!=RTC_POWERKEY1_KEY)))
            {
                *(volatile kal_uint16 *)(RTC_POWERKEY1) = RTC_POWERKEY2_KEY;
                *(volatile kal_uint16 *)(RTC_POWERKEY2) = RTC_POWERKEY1_KEY;
                //reset counter
                *(volatile kal_uint16 *)(RTC_NEW_SPAR2) = *(volatile kal_uint16 *)(RTC_NEW_SPAR2) & (~RTC_NEW_SPAR_MASK);
                //DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
                *(volatile kal_uint16 *)(RTC_WRTGR) = (kal_uint16)(RTC_WRTGR_WRTGR);
                //while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
                while(*(volatile kal_uint16 *)(RTC_BBPU) & 0x40);
            }
    
            atpg_mode_counter = (*(volatile kal_uint16 *)(RTC_NEW_SPAR2) & RTC_NEW_SPAR_MASK) >> RTC_NEW_SPAR_OFFSET;
    
            if ((((*(volatile kal_uint16 *)(CHR_CON0 + RGS_CHRDET_OFFSET) & RGS_CHRDET_MASK)!=0) && (atpg_mode_counter < 1)) ||
                (((*(volatile kal_uint16 *)(CHR_CON0 + RGS_CHRDET_OFFSET) & RGS_CHRDET_MASK)==0) && (atpg_mode_counter < 5)))
            {
                atpg_mode_counter++;
                reg_value = *(volatile kal_uint16 *)(RTC_NEW_SPAR2);
                reg_value &= ~RTC_NEW_SPAR_MASK;
                reg_value |= atpg_mode_counter<<RTC_NEW_SPAR_OFFSET;
                *(volatile kal_uint16 *)(RTC_NEW_SPAR2) = reg_value;
                *(volatile kal_uint16 *)(RTC_BBPU) = (*(volatile kal_uint16 *)(RTC_BBPU) & (~0x8)) | 0x4300;
                //DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
                *(volatile kal_uint16 *)(RTC_WRTGR) = (kal_uint16)(RTC_WRTGR_WRTGR);
                //while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
                while(*(volatile kal_uint16 *)(RTC_BBPU) & 0x40);
    
                //reboot
                efuse_diverge_reboot(atpg_mode_counter);
            }
        }
    }

	//if meta mode
    if ((*(volatile kal_uint16 *)(0xA0010010)&0x0001)==1)
    {
        /* keypad disabled, which can be used for escaping ATPG mode during battery-off power-off
            KCOL0    (GPIO16: output low ) [0]
            KROW1    (GPIO20: output low ) test_ck
            KROW0    (GPIO21: output high) tm_trap_enable
        */
        *(volatile kal_uint32 *)(0xA0020308) = 0x00110000; // GPIO_DOUT0_CLR
        *(volatile kal_uint32 *)(0xA0020304) = 0x00200000; // GPIO_DOUT0_SET
        *(volatile kal_uint32 *)(0xA0020004) = 0x00310000; // GPIO_DIR0_SET
        *(volatile kal_uint32 *)(0xA0020c28) = 0x00770007; // GPIO_MODE2_CLR
    }

	//atpg_mode_count = 0;
	*(volatile kal_uint16 *)(RTC_NEW_SPAR2) = *(volatile kal_uint16 *)(RTC_NEW_SPAR2) & (~RTC_NEW_SPAR_MASK);
    //DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
    *(volatile kal_uint16 *)(RTC_WRTGR) = (kal_uint16)(RTC_WRTGR_WRTGR);
    //while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
    while(*(volatile kal_uint16 *)(RTC_BBPU) & 0x40);

}
void Init(kal_uint32 random_seed, kal_uint32 param)
{
   extern kal_uint32 g_randomSeed;
   extern kal_bool SST_SWB_Init(kal_uint32 *pBootloader);
   extern kal_uint8  g_emi_param[2];
	 
   kal_uint32 sss_init_param = 0;
	 
   TS_BEGIN(TSID_BL_INIT);

   //Init UART
   uart_init();

   set_debug_level(bootloader_debug_level);
   
   BL_PRINT(LOG_INFO, "Init Start\n\r");

   //32K
   WacthDogRestart();

   DclF32K_Initialize();
   
   WaitFor32KStable();
   
   WacthDogRestart();

   //Init PDN
#if !defined(__BL_SLIM_SEG__) && !defined(__BRINGUP_SUPPORT__) && !defined(MT6250)
   /* PDN control initialization */
#if defined(__DRV_SUPPORT_LPWR__)   
   lpwr_init();
   DRVPDN_ini();
#endif
   
#endif /* !__BL_SLIM_SEG__ && !__BRINGUP_SUPPORT__ && !MT6250 */

   //Init NFI
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
   if (BlFeatureCombination() & MAUI_FC_NOR_FLASH_BOOTING)
#endif
   {
      NFIDriverInit();
   }

   //Init bootloader internal service & dummy reference
   g_randomSeed = random_seed;

   //EMI owner requested. Only for 6256
#if defined(MT6256)
   __EMI_StoreEmiData(g_emi_param);
#endif

   bl_print(LOG_NONE, "", g_bl_swb_struct.size);

#ifdef __SV5_ENABLED__
   {
      extern BL_Param_v4 *g_pBROM_BL_Param;
      extern kal_bool g_bromCmdModeDisabled;
      
      g_pBROM_BL_Param = (BL_Param_v4*)param;
      sss_init_param = g_pBROM_BL_Param->m_sd_crypto_lib_tbl_addr;
      
      g_bromCmdModeDisabled = bl_Is_Brom_Cmd_Mode_Disabled();
      
      DummyReference();
   }

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   {
      //Temp dummy reference
      extern const GFH_EMI_LIST_v5 EMI_INFO_2;
      bl_print(LOG_NONE, "", &EMI_INFO_2);
   }
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#endif /* __SV5_ENABLED__ */

   //Init feature-related services
#if !defined(__16_3_SEG__) && !defined(__BRINGUP_SUPPORT__)

#if defined(__CRYPTO_SHARED_DRV__)
   SSS_Init_Share_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC, sss_init_param);
#else
   SSS_Init_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC);
#endif /* __CRYPTO_SHARED_DRV__ */

   {
#ifdef __SV5_ENABLED__
      extern kal_uint32 Image$$BL_GFH_SECTION$$Base;
      SST_SWB_Init((kal_uint32*)&Image$$BL_GFH_SECTION$$Base);
#else
      extern kal_uint32 Image$$READ_ONLY$$Base;
      SST_SWB_Init((kal_uint32*)&Image$$READ_ONLY$$Base);
#endif
   }

#endif /* !__16_3_SEG__ && !__BRINGUP_SUPPORT__ */


   BL_PRINT(LOG_INFO, "Init done, %x\n\r", g_randomSeed);
   TS_END(TSID_BL_INIT);

#ifdef MT6276
   TS_BEGIN(TSID_BL_INIT2);
   evb_fail_detection();
   TS_END(TSID_BL_INIT2);   
#endif /* MT6276 */

}

#endif /* __MINI_BOOTLOADER__ */

kal_uint32 BlFeatureCombination(void)
{
#ifndef __SV5_ENABLED__
   return g_ExtBootloaderInfo.m_feature_combination;
#else

#ifdef __MINI_BOOTLOADER__
   return g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#else
   return g_ext_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#endif

#endif /* __SV5_ENABLED__ */
}


#ifdef __EXT_BOOTLOADER__

void InitFPU(void)
{
#if defined (__ARM_FPUV2__)
   extern kal_uint32 cp15_enable_cp(void);
   extern void set_fpu_runfastmode(void);
   extern void enable_arm_fpu(void);

   cp15_enable_cp();
   enable_arm_fpu();
   set_fpu_runfastmode();
#endif
}

void ShutDownModule()
{
#if defined(MT6250)
   PDN_SET(PDN_ROM);
#endif
}

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
void InitUSBDLGPIO(void)
{
#ifdef __CUST_NEW__    
   if ( gpio_usbdl_pin != NO_USBDL_GPIO )
   {
      DCL_HANDLE handle;
      handle = DclGPIO_Open(DCL_GPIO, gpio_usbdl_pin);
      
      //GPIO_ModeSetup( gpio_usbdl_pin, 0 );
      DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
      
      //GPIO_InitIO( 0, gpio_usbdl_pin );
      DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
      
      //GPIO_PullenSetup(gpio_usbdl_pin, KAL_TRUE);
      DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
      
      //GPIO_PullSelSetup(gpio_usbdl_pin, KAL_TRUE);
      DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
      
      DclGPIO_Close(handle);
   }
#endif /* __CUST_NEW__ */   
}
#endif /* __USB_DOWNLOAD__ || __UART_DOWNLOAD__ */

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)

void SwitchGPIOToKeypad(kal_uint8 keypadPin, kal_uint8 setModeCmd, kal_bool setPullEn)
{
   DCL_HANDLE handle;

   if(keypadPin != 0xff)
   {
      handle = DclGPIO_Open(DCL_GPIO, keypadPin);
      
      DclGPIO_Control(handle, setModeCmd, NULL);
      
      if(setPullEn)
      {
         DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, NULL);
         DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, NULL);
      }
      
      DclGPIO_Close(handle);
   }
}

void InitKeypadGPIO(void)
{
#ifdef __CUST_NEW__

#define KEYPAD_GPIO_INIT(x, pullEn) \
   {\
       extern const kal_uint8 gpio_keypad_##x##_pin;\
       extern const kal_uint8 gpio_keypad_##x##_pin_M_DEFAULT;\
       SwitchGPIOToKeypad(gpio_keypad_##x##_pin, gpio_keypad_##x##_pin_M_DEFAULT, pullEn);\
   }

   KEYPAD_GPIO_INIT(col0, KAL_TRUE);
   KEYPAD_GPIO_INIT(col1, KAL_TRUE);
   KEYPAD_GPIO_INIT(col2, KAL_TRUE);
   KEYPAD_GPIO_INIT(col3, KAL_TRUE);
   KEYPAD_GPIO_INIT(col4, KAL_TRUE);
   KEYPAD_GPIO_INIT(col5, KAL_TRUE);
   KEYPAD_GPIO_INIT(col6, KAL_TRUE);
   KEYPAD_GPIO_INIT(col7, KAL_TRUE);
   KEYPAD_GPIO_INIT(col8, KAL_TRUE);
   KEYPAD_GPIO_INIT(col9, KAL_TRUE);
   
   KEYPAD_GPIO_INIT(row0, KAL_FALSE);
   KEYPAD_GPIO_INIT(row1, KAL_FALSE);
   KEYPAD_GPIO_INIT(row2, KAL_FALSE);
   KEYPAD_GPIO_INIT(row3, KAL_FALSE);
   KEYPAD_GPIO_INIT(row4, KAL_FALSE);
   KEYPAD_GPIO_INIT(row5, KAL_FALSE);
   KEYPAD_GPIO_INIT(row6, KAL_FALSE);
   KEYPAD_GPIO_INIT(row7, KAL_FALSE);
   KEYPAD_GPIO_INIT(row8, KAL_FALSE);
   KEYPAD_GPIO_INIT(row9, KAL_FALSE);

#endif

}

#endif /* __USB_DOWNLOAD__ || __UART_DOWNLOAD__ || __CARD_DOWNLOAD__ */

extern void Initialize_FDD_tables(void);
void InitExt(void)
{
   TS_BEGIN(TSID_BL_EXT_INIT);

   custom_setSFIExt();

   NLDShareBusCenCtrl();
   
#ifdef _NAND_FLASH_BOOTING_      
   NFIReconfigure2();
#endif /* _NAND_FLASH_BOOTING_ */

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
   InitUSBDLGPIO();
#endif /* __USB_DOWNLOAD__  || __UART_DOWNLOAD__ */   

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)
   InitKeypadGPIO();
#endif /* __USB_DOWNLOAD__  || __UART_DOWNLOAD__ ||__CARD_DOWNLOAD__ */

#if defined(__CARD_DOWNLOAD__) || defined(__FUNET_ENABLE__)
#if defined(__NANDFDM_TOTAL_BBM__)
   Custom_NAND_Init();
#endif
#endif /* __CARD_DOWNLOAD__  || __FUNET_ENABLE__ */

#if defined(__NOR_FDM_IN_BL__)
	Initialize_FDD_tables();
#endif

//PMU owner confirmd that new chips always have this. (MT6256 is the first one)
//Only disable it on older chips and remove them when phased out
#if ! (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(TK6516) || defined(TK6270) || \
       defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6253T) || defined(MT6253E) || defined(MT6253L) || \
       defined(MT6252) || defined(MT6252H) || defined(MT6251) || defined(MT6276) || defined(TK6280) )
   BL_Chr_Init();
#endif

#if defined(__FUNET_ENABLE__)
   FS_SanityCheck();
#endif /* __FUNET_ENABLE__ */

#if !defined(__BL_SLIM_SEG__)
   /* PDN control initialization */
#if defined(__DRV_SUPPORT_LPWR__)   
   lpwr_init();
   DRVPDN_ini();
#endif
   DclPMU_Initialize();
#endif /* __BL_SLIM_SEG__ */

#ifdef __SV5_ENABLED__

   TS_BEGIN(TSID_BL_INIT_EXT_FLASH_DRV);
   InitFlashDriver();
   TS_END(TSID_BL_INIT_EXT_FLASH_DRV);

   DummyReference();
#endif /* __SV5_ENABLED__ */


#if !defined(__BRINGUP_SUPPORT__)
#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) || defined(__MTK_SECURE_PLATFORM__)
   SSS_Init_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC);
#endif
#endif /* !__BRINGUP_SUPPORT__ */

   TS_END(TSID_BL_EXT_INIT);
}

kal_uint32 MauiFeatureCombination(void)
{
   return g_mauiFeatureCombination;
}

void GetFeatureCombination(void)
{
#ifndef __SV5_ENABLED__
   kal_uint32 addr;
#endif   

   TS_BEGIN(TSID_BL_GET_FATURE_COMINATION);
      
   BL_DEBUG_PRINT("GetFeatureCombination()\n\r");

   g_mauiFeatureCombination = 0;
   
#ifdef __SV5_ENABLED__
{
      GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

      if(pMauiInfo)
      {
         g_mauiFeatureCombination = pMauiInfo->m_feature_combination;
      }
}
#else

#ifdef _NAND_FLASH_BOOTING_
   addr = (kal_uint32)GetVersionInfoAddress();
#else
   addr = (kal_uint32)(MAUI_START_ADDR_NOR & REMAPPING_MASK);
#endif   

   SST_Get_MAUI_Feature_Combination(addr, &g_mauiFeatureCombination);
   
   BL_DEBUG_PRINT("g_mauiFeatureCombination=%x, bl combination=%d\n\r", g_mauiFeatureCombination);

#endif   

   TS_END(TSID_BL_GET_FATURE_COMINATION);
}

kal_bool CheckPairedVersion(void)
{
#ifdef __SV5_ENABLED__

   GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

   if(pMauiInfo)
   {
       if( pMauiInfo->m_bl_maui_paired_ver != g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver)
       {
          BL_PRINT(LOG_ERROR, "Paired version mismatched, %d, %d\n\r", pMauiInfo->m_bl_maui_paired_ver, g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver);
          return KAL_FALSE;
       }
   }

#else
   kal_uint32 paired_version;
   kal_uint32 addr;
   
#ifdef _NAND_FLASH_BOOTING_
   addr = (kal_uint32)GetVersionInfoAddress();
#else
   addr = (kal_uint32)(MAUI_START_ADDR_NOR & REMAPPING_MASK);
#endif   

   paired_version = SST_Get_MAUI_Paired_Version(addr);

   if ( paired_version != 0 && paired_version != g_ExtBootloaderInfo.m_bl_maui_paired_ver )
   {
      BL_PRINT(LOG_ERROR, "Paired version mismatched, %d, %d\n\r", g_ExtBootloaderInfo.m_bl_maui_paired_ver, paired_version);
      return KAL_FALSE;
   }
#endif /* __SV5_ENABLED__ */

   return KAL_TRUE;   
}


kal_bool CheckFeatureCompatibility(kal_uint32 mauiFeatureSet)
{
   kal_uint32 blFeatureSet = BlFeatureCombination();

   kal_bool featureIncomp = KAL_FALSE;

   if( (blFeatureSet & MAUI_FC_SECURE) != (mauiFeatureSet & MAUI_FC_SECURE) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( !(blFeatureSet & MAUI_FC_FOTA) && (mauiFeatureSet & MAUI_FC_FOTA) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( !(blFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) && (mauiFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) )
   {
      featureIncomp = KAL_TRUE;
   }

   if( (blFeatureSet & MAUI_FC_FAST_LOGO) != (mauiFeatureSet & MAUI_FC_FAST_LOGO) )
   {
      featureIncomp = KAL_TRUE;
   }

   return (kal_bool)(!featureIncomp);

}

kal_bool CheckFeatureCombination(void)
{
#ifdef __SV5_ENABLED__
   if(g_maui_load_addr != INVALID_START_ADDR)
#endif /* __SV5_ENABLED__ */
   {
      if( CheckFeatureCompatibility(g_mauiFeatureCombination) == KAL_FALSE )
      {
         BL_PRINT(LOG_ERROR, "Incompatible features, mauiFeature=%d\n\r", g_mauiFeatureCombination);
         return KAL_FALSE;
      }
   }

   return KAL_TRUE;   
}


#ifdef __LCD_DRIVER_IN_BL__

void BL_LCDHWInit(void)
{
#ifndef __L1_STANDALONE__
   if((g_lcd_status & BL_LCD_INITED) == 0)
   {
      /* HW initialization */
      DclPW_Initialize();
      
      //GPIO_init();          //Not init GIPO here or other one's setting will be overwritten
      DclGPIO_Initialize();

      DclPWM_Initialize();
      PWM_initialize();
      DclPMU_Initialize();
      g_lcd_status |= BL_LCD_INITED;
   }
#endif /* !__L1_STANDALONE__ */
}

/**********************************************************
Description : BL_LCDSetBackLight.
Input       : None
Output      : None
***********************************************************/
void BL_LCDSetBackLight(void)
{
   if((g_lcd_status & BL_LCD_BACKLIGHT_ON) == 0)
   {
      kal_uint32 BBPU;
      kal_uint32 count = 0;

#ifndef __L1_STANDALONE__
      custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif /* !__L1_STANDALONE__ */
      g_lcd_status |= BL_LCD_BACKLIGHT_ON;
   }
}


#endif /* __LCD_DRIVER_IN_BL__ */

void SetWDTNormalResetFlag(void)
{
   DCL_HANDLE rtc_handler;
   RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;

   rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
   DclRTC_Control(rtc_handler, RTC_CMD_PROT_UNLOCK, (DCL_CTRL_DATA_T *)NULL);
   
   rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
   rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
   DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA	
   DclRTC_Close(rtc_handler);
}

#endif /* __EXT_BOOTLOADER__ */

#ifdef __RVCT__
/*************************************************************************
* FUNCTION
*  __user_initial_stackheap
*
* DESCRIPTION
*  This dummy function is implemented to make the linker happy for RVCT.
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
__value_in_regs struct __initial_stackheap __user_initial_stackheap(unsigned i0, unsigned i1, unsigned i2, unsigned i3)
{
   struct __initial_stackheap config;

   config.heap_base = i1;
   config.heap_limit = i1;
   config.stack_base = i1; 
   config.stack_limit = 0;

   return config;
}

/*************************************************************************
* FUNCTION
*  __ARM_get_argv
*
* DESCRIPTION
*  This dummy function is implemented to suppress argc,argv processing
*  in standard C library
*
* CALLS
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*************************************************************************/
__value_in_regs struct __argc_argv $Sub$$__ARM_get_argv(void *ptr)
{
    struct __argc_argv a = {0};
    return a;
}

/*************************************************************************
* FUNCTION SYMBOL
*  __use_no_heap
*
* DESCRIPTION
*  You can reference the __use_no_heap or __use_no_heap_region symbols in
*  your code in order to guarantee that no heap using functions are linked
*  in from the ARM library.
*
*************************************************************************/
//#pragma import(__use_no_heap)

#pragma import(__user_initial_stackheap)
#endif   /* __RVCT__ */

/*************************************************************************
* FUNCTION SYMBOL
*  pmu6276_efuse_calibration_bl
*
* DESCRIPTION
*  API to do pmu setting for 73
*
*************************************************************************/
#if defined(MT6276)
void pmu6276_efuse_calibration_bl(void)
{
   // E-FUSE calibration
   kal_uint32 val32;
   kal_uint16 val16;
   
   // 1. *(BASE+0x104)[7:4]   RG_STRUP_IREF_TRIM (4b)
   val32 = *(volatile kal_uint32 *)(EFUSE_base+0x104);
   
   // 2. *(BASE+0x104)[21]         RG_VPROC_VFBADJ enable (1b)
   //     *(BASE+0x104)[20:16]         RG_VPROC_VFBADJ (5b)
   if (val32 & 0x00200000) // Bit28: Trim enable bit
   {
      val16 = (kal_uint16)((val32 & 0x001f0000)>>16); 
   }
   else
   {
      val16 = 7;
   }
   
   //PMU_DRV_SetData16(0x81150940, 0x01f0, val16<<4);   
   *(volatile kal_uint16 *)(0x81150940) = ((*(volatile kal_uint16 *)(0x81150940)) & (~0x01f0)) | (val16<<4);   
   
   //dummy loop for 50us at least
   for(val32=0; val32<2000; val32++)
   {
      ;
   }
}
#endif

/**********************************************************
Description : initialization of internal RAM
Input       : None
Output      : None
***********************************************************/
void PreInit(void)
{
#if defined(MT6250)
#if defined(__EX_HW_RESET__)
   *(P_U16)(ANA_CFGSYS_base + 0x0038) = 0x0601;
#else
   *(P_U16)(ANA_CFGSYS_base + 0x0038) = 0x0701;
#endif
   *(P_U16)(ANA_CFGSYS_base + 0x0034) = ((*(P_U16)(ANA_CFGSYS_base + 0x0034)) & 0x0fff) | 0x2000;
#endif
   
#if defined(MT6276)
   //Power on MM sysram
   *(volatile kal_uint32*)(MMSYS_CONFG_base+0x0344) = 0x00000002;

   pmu6276_efuse_calibration_bl();

#endif

}

/**********************************************************
Description : initialization of DTLB
Input       : None
Output      : None
***********************************************************/
void Init_DTLB(void)
{
#if defined(__MTK_SECURE_PLATFORM__) && !defined(__SV5_ENABLED__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239)) && defined(_NAND_FLASH_BOOTING_)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ && !__SV5_ENABLED__ */  

}

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Generation of the random seed
Input       : None
Output      : Generated seed
***********************************************************/

#ifndef __SV5_ENABLED__
#if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B) || defined(MT6236)  || defined(MT6236B)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#elif defined(MT6268A) || defined(MT6268)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9200A000;
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#else
static const kal_uint32 RAND_GEN_START_ADDR = 0x40002000;
#endif
#endif

kal_uint32 GenerateRandomSeed()
{
   const kal_uint32 SEED_REGION_SIZE = 1024;
   
   kal_uint32 *p, *q, seed;
   
#ifdef __SV5_ENABLED__

   extern kal_uint32 Image$$DUMMY_END$$Base;

   q = (kal_uint32*)&Image$$DUMMY_END$$Base;
   p = q-SEED_REGION_SIZE/4;

#else

   p = (kal_uint32 *)RAND_GEN_START_ADDR;
   q = (kal_uint32 *)(RAND_GEN_START_ADDR + SEED_REGION_SIZE);

#endif

   /* generate a random number via reading internal SRAM or 32K-clock calibration */
   for (seed = 0; p < q; p++) {
      /* XOR memory data */
      seed = seed ^ *p;
   }

   return seed;

}
#endif /* __MINI_BOOTLOADER__ */


/* Make linker happy */
BL_Info_Wrapper_st g_pass_info;

kal_uint32 INT_GetBootloaderFlag(void)
{
	return 0;
}
/* Make linker happy */

#ifdef MT6260
/* The following functions is for solving MT6260 ESD problem */
void setWDTforESD(void)
{
    *((volatile kal_uint32 *)(RGU_base + 0x0004)) = 0x0808;
    *((volatile kal_uint32 *)(RGU_base + 0x0008)) = 0x1971;
    *((volatile kal_uint32 *)(RGU_base + 0x0000)) = *((volatile kal_uint32 *)(RGU_base + 0x0000)) | 0x2201;
}
#endif
