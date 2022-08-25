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
 *    custom_drv_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the driver init functions
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_release.h"
#include "kal_public_api.h" 
#include "drv_comm.h"

extern void GPIO_init(void);
extern void spi_ini(void);
extern void LCD_FunConfig(void);
extern void Alter_init(void);
extern void PWM_initialize(void);
extern void NLDShareBusCenCtrl(void);

#if defined(__OFN_SUPPORT__)
extern void OFN_ChipInit(void);
#endif

#if defined(__NFC_SUPPORT__)
extern int phDal4Nfc_uart_reset(long level);
#endif

#if defined(__BTMODULE_MT6236__)||defined(__BTMODULE_MT6276__)
void Brt_MT6236_76_ARM7_Workaround_Stage_1_Bootloader_Step_0_PowerOn_Once_Only_Fake_BtOff(void);
#endif

#ifdef __MT6261_PRODUCTION_IMPROVE__
void MT6261_efuseProtect(void);
#endif

#if defined(__EXT_BUCK__)

extern void gpio_external_buck_set_in_normal_mode(void);
extern void pmu_vcore_voltage_set_in_normal_mode(void);


#endif

void custom_drv_init(void)
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This Workaround should be placed at 1st line of custom_drv_init.
#if defined(__BTMODULE_MT6236__)||defined(__BTMODULE_MT6276__)
    Brt_MT6236_76_ARM7_Workaround_Stage_1_Bootloader_Step_0_PowerOn_Once_Only_Fake_BtOff();
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    GPIO_init(); /* configure GPIO for debugging */
    NLDShareBusCenCtrl();
#ifdef __LCD_SUPPORT__
    spi_ini(); /* For LCD module */
    LCD_FunConfig();
#endif /* __LCD_SUPPORT__ */
    Alter_init();
#ifndef __L1_STANDALONE__
   PWM_initialize();
#endif
#if defined(__OFN_SUPPORT__)
    OFN_ChipInit();
#endif

/*below code is add for init external buck*/
#if defined(__EXT_BUCK__)
	DclPMU_Initialize();
gpio_external_buck_set_in_normal_mode();
pmu_vcore_voltage_set_in_normal_mode();
#endif

#ifdef __MT6261_PRODUCTION_IMPROVE__
	MT6261_efuseProtect();
#endif

}

void custom_drv_init_phase2(void)
{
#ifdef __MT6261_PRODUCTION_IMPROVE__
	MT6261_efuseProtect();
#endif
}

#ifdef __MT6261_PRODUCTION_IMPROVE__

void MT6261_efuseProtect(void)
{
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
}

kal_uint32 efuse_getAdcEfuse(void)
{
	return (DRV_Reg32(0x10000404));
}

kal_uint32 efuse_getPmuEfuse (void)
{
	return (DRV_Reg32(0x10000408));
}

kal_bool efuse_efuseBackupValid(void)
{
	if((0xABABABAB == DRV_Reg32(0x10000400)) && (DRV_Reg32(0x10000404) == DRV_Reg32(0x1000040c)) && (DRV_Reg32(0x10000408) == DRV_Reg32(0x10000410)))
		return KAL_TRUE;
	else
		return KAL_FALSE;
	
}

#endif

void custom_drv_deinit(void)
{
#ifdef __NFC_SUPPORT__
  //Do NFC hardware reset for NFC chip enter active mode
  phDal4Nfc_uart_reset(1);
  phDal4Nfc_uart_reset(0);
  phDal4Nfc_uart_reset(1);
#endif
}


