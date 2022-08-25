/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_SFI.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SFI (serial flash interface) related setting.
 *
 * Author:
 * -------
 * -------
 *
 *   Memory Device database last modified on 2011/7/8
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__SERIAL_FLASH_EN__) //This compile option only enables when SERIAL_FLASH_SUPPORT in make file is TRUE

#include "kal_release.h"
#include <reg_base.h>
#include <emi_hw.h>
#include <init.h>
#include "MemoryDevice_TypeDef.h"
#include "config_hw.h"
#include "cache_hw.h"
#include "flash_sf.h"
#include "flash_opt.h"

#include "pll.h"
#include "combo_flash_init.h"
#include "combo_sfi_defs.h"
#include "custom_EMI_release.h" // Get EMI EPLL clock compile option for MT6255
#include "flash_sfi_release.h"  // Get __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ definition
#if (defined(MT6251) && defined(__UBL__))
extern kal_bool BL_Init_isUSBMetaFromBootROM(void);
#endif

#ifdef __MTK_TARGET__  //Put combo_mem_hw_list_dcm into Second Part to 1. avoid being located to ZIMAGE 2. Avoid Leakage problem
#pragma arm section rodata = "SECOND_PART"
#include "custom_sfi.h"
#endif /* __MTK_TARGET__ */


#ifdef __MTK_TARGET__
#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && defined(__EXT_BOOTLOADER__) // MT6250 MT6260/61/2501/2502 only: if SF is init in ExtBootloader & this is the ext bootloader
#pragma arm section code = "INTERNCODE", rodata = "INTERNDATA", zidata = "INTERNDATA"
#else
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif // defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && defined(__EXT_BOOTLOADER__)
#endif /* __MTK_TARGET__ */




/*************************************************************************
* FUNCTION
*  custom_setSFI()
*
* DESCRIPTION
*   This routine aims to set SFI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

//-----------------------------------------------------------------------------
// MCP Serial Flash EMI/SFI settings
//-----------------------------------------------------------------------------

// include type defines (to be modified by EMI/SFI owner)

#if defined(MT6251) || defined(MT6253L)|| defined(MT6252) ||defined(MT6255) ||defined(MT6250) ||defined(MT6280) ||defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && defined(__EXT_BOOTLOADER__) // MT6250 MT6260/61/2501/2502 only: if SF is init in ExtBootloader & this is the ext bootloader
#pragma arm section rodata = "INTERNDATA"
#else
#pragma arm section rodata = "EMIINITCONST"
#endif //defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && defined(__EXT_BOOTLOADER__)
#define COMBO_MEM_HW_INST_NAME combo_mem_hw_list
#define COMBO_MEM_HW_TYPE_MODIFIER  static const
#include "combo_sfi_config.h"
#endif //defined(MT6251) || defined(MT6253L)|| defined(MT6252) ||defined(MT6255) ||defined(MT6250) ||defined(MT6280) ||defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

int sfi_index, CS_COUNT_SFI;
kal_uint32 SFI_DCM_index = __SFI_DCM_COMBO_INDEX_UND;

#if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int8 custom_setSFI(void)
{
#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && !defined(__EXT_BOOTLOADER__) // if SF is init in ExtBootloader & this is the small bootloader


#if defined(MT6260) 
	
    /* Normal Mode Configuration */
	  /*SF clock Enable  Notice: PDN_CLR to enable SF clock */
    SFI_WriteReg16(PDN_CLRD2,(SFI_ReadReg16(PDN_CLRD2)|RG_SFC_SW_CG));
      /*SF pad switch: SF or SPI-Nand */
    SFI_WriteReg16(HW_MISC2, (SFI_ReadReg16(HW_MISC2)|PAD_SWITCH));
      /*SF GPIO configuration*/	
      // Step 1. Set GPIO to SFI
    SFI_WriteReg32(SF_GPIO_MODE8, (SFI_ReadReg32(SF_GPIO_MODE8)&SF_GPIO_MODE8_CLR)|SF_GPIO67|SF_GPIO68|SF_GPIO69|SF_GPIO70|SF_GPIO71);
    SFI_WriteReg32(SF_GPIO_MODE9, (SFI_ReadReg32(SF_GPIO_MODE9)&SF_GPIO_MODE9_CLR)|SF_GPIO72);

	/* GPIO high-Z Enable*/
	  /* Normal MODE */
    SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~(SF_NORMAL_MODE_R0_R1_SET1& ~SF_NORMAL_MODE_R0_R1_Dual_SET))));
    SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~(SF_NORMAL_MODE_R0_R1_SET1& ~SF_NORMAL_MODE_R0_R1_Dual_SET))));
    SFI_WriteReg16(GPIO_RESEN2, (SFI_ReadReg16(GPIO_RESEN2)& (~SF_NORMAL_MODE_R0_R1_SET2)));
    SFI_WriteReg16(GPIO_RESEN5, (SFI_ReadReg16(GPIO_RESEN5)& (~SF_NORMAL_MODE_R0_R1_SET2)));

      /* SLT  MODE */
	if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_SLT_MODE_R0_R1_SET)));
        SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_SLT_MODE_R0_R1_SET)));
    }

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
    /* GPIO high-Z Enable*/
      /* Normal MODE */
      SFI_WriteReg32(SFIO_CFG0, (SFI_ReadReg32(SFIO_CFG0)& (SF_NORMAL_HIGHZ)));
      SFI_WriteReg32(SFIO_CFG1, (SFI_ReadReg32(SFIO_CFG1)& (SF_NORMAL_HIGHZ)));
      SFI_WriteReg32(SFIO_CFG2, (SFI_ReadReg32(SFIO_CFG2)& (SF_NORMAL_HIGHZ)));

      /* SLT  MODE */
    if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg32(GPIO_RESEN0_1, (SFI_ReadReg32(GPIO_RESEN0_1)& (SF_SLT_HIGHZ)));
        SFI_WriteReg32(GPIO_RESEN1_1, (SFI_ReadReg32(GPIO_RESEN1_1)& (SF_SLT_HIGHZ)));
        SFI_WriteReg32(GPIO_DRV1, (SFI_ReadReg32(GPIO_DRV1)&(SF_SLT_DRIVING_CLR))|SF_SLT_DRIVING_12mA ); //SLT driving 12mA
    }
#endif //defined(MT6260)

    return 0;

#else   // !__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ || __EXT_BOOTLOADER__

    const CMEMEntrySFI *sfi;
    kal_uint32 tmp_val, i;
    #if defined(MT6261) || defined(MT2501) || defined(MT2502)
    kal_uint32 tmp_driving;
    #else
    kal_uint16 tmp_driving;
    #endif
#if defined(MT6260) //Add GPIO, clock, pad switch configuration here in case only mini-bootloader init SF device
	
    /* Normal Mode Configuration */
	  /*SF clock Enable  Notice: PDN_CLR to enable SF clock */
    SFI_WriteReg16(PDN_CLRD2,(SFI_ReadReg16(PDN_CLRD2)|RG_SFC_SW_CG));
      /*SF pad switch: SF or SPI-Nand */
    SFI_WriteReg16(HW_MISC2, (SFI_ReadReg16(HW_MISC2)|PAD_SWITCH));
      /*SF GPIO configuration*/	
      // Step 1. Set GPIO to SFI
    SFI_WriteReg32(SF_GPIO_MODE8, (SFI_ReadReg32(SF_GPIO_MODE8)&SF_GPIO_MODE8_CLR)|SF_GPIO67|SF_GPIO68|SF_GPIO69|SF_GPIO70|SF_GPIO71);
    SFI_WriteReg32(SF_GPIO_MODE9, (SFI_ReadReg32(SF_GPIO_MODE9)&SF_GPIO_MODE9_CLR)|SF_GPIO72);

	/* GPIO high-Z Enable*/
	  /* Normal MODE */
    SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~(SF_NORMAL_MODE_R0_R1_SET1& ~SF_NORMAL_MODE_R0_R1_Dual_SET))));
    SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~(SF_NORMAL_MODE_R0_R1_SET1& ~SF_NORMAL_MODE_R0_R1_Dual_SET))));
    SFI_WriteReg16(GPIO_RESEN2, (SFI_ReadReg16(GPIO_RESEN2)& (~SF_NORMAL_MODE_R0_R1_SET2)));
    SFI_WriteReg16(GPIO_RESEN5, (SFI_ReadReg16(GPIO_RESEN5)& (~SF_NORMAL_MODE_R0_R1_SET2)));

      /* SLT  MODE */
	if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_SLT_MODE_R0_R1_SET)));
        SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_SLT_MODE_R0_R1_SET)));
    }
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
    /* GPIO high-Z Enable*/
      /* Normal MODE */
      SFI_WriteReg32(SFIO_CFG0, (SFI_ReadReg32(SFIO_CFG0)& (SF_NORMAL_HIGHZ)));
      SFI_WriteReg32(SFIO_CFG1, (SFI_ReadReg32(SFIO_CFG1)& (SF_NORMAL_HIGHZ)));
      SFI_WriteReg32(SFIO_CFG2, (SFI_ReadReg32(SFIO_CFG2)& (SF_NORMAL_HIGHZ)));

      /* SLT  MODE */
    if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg32(GPIO_RESEN0_1, (SFI_ReadReg32(GPIO_RESEN0_1)& (SF_SLT_HIGHZ)));
        SFI_WriteReg32(GPIO_RESEN1_1, (SFI_ReadReg32(GPIO_RESEN1_1)& (SF_SLT_HIGHZ)));
        SFI_WriteReg32(GPIO_DRV1, (SFI_ReadReg32(GPIO_DRV1)&(SF_SLT_DRIVING_CLR))|SF_SLT_DRIVING_12mA ); //SLT driving 12mA
    }
#endif //defined(MT6260)

    /*--------------------------------------------------------------------------
     * 1. Slow down SF_CLK to 26Mhz for META mode
     * At META mode, the PLL will be enabled
     * At non-META mode, bootrom will disable PLL
     *--------------------------------------------------------------------------*/
#if (defined(MT6251) && defined(__UBL__))
    if(BL_Init_isUSBMetaFromBootROM())
    {
     *PLL_CON4 = 0x1575; // need to set the SF_CLK to 26Mhz for serial flash device config, for the case of META mode will enable PLL to 78/104Mhz
     for(i=0; i< 0x2000; i++);	
    }
#endif
#if defined(MT6255)
    *VSF_CON3 |= 0x1;      //Enable VSF_AUTO_OFF_EN to make Internal VSF drop with WDT reset
    *VSF_CON0 &= 0xFF0F;   //Clear VSF_VOSEL
    *VSF_CON0 |= 0x61;     //Set Internal VSF to 3.3V
    *SFC_CTRL_SET |= 0x20;
#endif
#if defined(MT6280)
    //Set GPIO to SFI
    GPIO_SET_MODE(84, GPIO84_MODE_SFIO2);
    GPIO_SET_MODE(85, GPIO85_MODE_SFIO1);
    GPIO_SET_MODE(86, GPIO86_MODE_SFIO0);
    GPIO_SET_MODE(87, GPIO87_MODE_SFCS);
    GPIO_SET_MODE(88, GPIO88_MODE_SFCLK);
    GPIO_SET_MODE(89, GPIO89_MODE_SFIO3);
#endif

    sfi_index=CMEM_EMIINIT_Index();  // API CMCP_EMIINIT_Index() is defined in combo_flash_init.h

    // if __COMBO_MCP_SUPPORT__ was not defined, CMEM_EMIINIT_Index() always retunrs 0.
    // if __COMBO_MCP_SUPPORT__ was defined, CMEM_EMIINIT_Index() returns the index to the sfi config structure.
    //    => if the returned index < 0, means the flash was not included in the mcp list

    if (sfi_index<0)    {
        // Add error handler here
        while(1);
    }

    /*--------------------------------------------------------------------------
     * Step 1.
     * 1. Switch mode QPI/SPI Quad
     * 2. Set Burst/Wrap length
     *--------------------------------------------------------------------------*/
    sfi=&combo_mem_hw_list.List[sfi_index];   // the structure name "combo_mem_hw_list" can be renamed by SFI owner

#if defined(__SFI_CLK_78MHZ__) || defined(__SFI_CLK_80MHZ__)
    // Device Initialization
#if defined(MT6280) //Skip Switch mode and set Wrap/Dummy if Direct Read Keep Bit is set
if (!((SFI_ReadReg32(RW_SFI_STA2_CTL)) & SFI_KEEP_READ_SETTING))
#endif
    SFI_Dev_Command_List(0,sfi->DevInit_78M);

    /*--------------------------------------------------------------------------
     * Step 2. Initialize Serial Flash Control Registers
     *--------------------------------------------------------------------------*/
    SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_78M[SFC_MAC_CTL]);
    SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_78M[SFC_DR_CTL]);

#if defined(MT6251)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL_1]);
    SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_78M[SFC_DLY_CTL_1]);
    *ACIF_CON4 = sfi->HWConf_78M[SFC_Driving_1];
    *ACIF_CON5 = sfi->HWConf_78M[SFC_Driving_2];
    
#if defined(__UBL__)
    if(BL_Init_isUSBMetaFromBootROM()) //need to set SFC to async mode, casue of PLL is to set to 0x1575 at META mode
    {
    tmp_val = SFI_ReadReg32(RW_SFI_MAC_CTL);
    SFI_WriteReg32(RW_SFI_MAC_CTL, tmp_val&0xFFFFFDFF);
    }
#endif
#elif defined(MT6253L)||defined(MT6252)
	// if efuse bits shows it is for 1st timing
	if((*ProcessID&0x03000000) == 0x0)
	{
		SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL_1]);
     	SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_78M[SFC_DLY_CTL_1]);
	}
	// if efuse bits shows it is for 2nd timing
	else
	{
	 	SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL_2]);
     	SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_78M[SFC_DLY_CTL_2]);
	}	
    tmp_val = *ACIF_CON0 & 0xFFF0FFFF;
    *ACIF_CON0 = tmp_val | (sfi->HWConf_78M[SFC_Driving_1] <<16);
    
#elif defined(MT6255)   
	SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_78M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_78M[SFC_DLY_CTL3]);
	tmp_val = *IO_DRV2 & 0xFF000000;
    *IO_DRV2 = tmp_val | sfi->HWConf_78M[SFC_Driving];
#elif defined(MT6250)||defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_78M[SFC_MISC_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_78M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_78M[SFC_DLY_CTL3]);
    #if defined(MT6261) || defined(MT2501) || defined(MT2502)
    tmp_driving = *SFIO_CFG0_DRV & 0xFFF8FFF8;
    *SFIO_CFG0_DRV = tmp_driving | (sfi->HWConf_78M[SFC_Driving]);
    tmp_driving = *SFIO_CFG1_DRV & 0xFFF8FFF8;
    *SFIO_CFG1_DRV = tmp_driving | (sfi->HWConf_78M[SFC_Driving]);
    tmp_driving = *SFIO_CFG2_DRV & 0xFFF8FFF8;
    *SFIO_CFG2_DRV = tmp_driving | (sfi->HWConf_78M[SFC_Driving]);
    #else
	tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
    *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_78M[SFC_Driving]);
    #endif
    /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
	#if defined(MT6250)
    SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_78M[SFC_Driving]<<12));
	#endif
#elif defined(MT6280) 
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_78M[SFC_MISC_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_78M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_78M[SFC_DLY_CTL3]);
    SFI_WriteReg32(RW_SFI_STA2_CTL, SFI_KEEP_READ_SETTING); //Set Direct Read Keep Bit
	tmp_driving = *GPIO_DRV6 & 0xC003; //GPIO_DRV6[13:2] for SF driving
    *GPIO_DRV6 = tmp_driving | (kal_uint16)(sfi->HWConf_78M[SFC_Driving]);

#else
	#error "Undefined BB chips"
#endif //defined(MT6251)

#elif defined(__SFI_CLK_104MHZ__) /* __SFI_CLK_78MHZ__ */
   // Device Initialization
    SFI_Dev_Command_List(0,sfi->DevInit_104M);

    /*--------------------------------------------------------------------------
     * Step 2. Initialize Serial Flash Control Registers
     *--------------------------------------------------------------------------*/
    SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_104M[SFC_MAC_CTL]);
    SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_104M[SFC_DR_CTL]);

#if defined(MT6251)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL_1]);
    SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_104M[SFC_DLY_CTL_1]);
    *ACIF_CON4 = sfi->HWConf_104M[SFC_Driving_1];
    *ACIF_CON5 = sfi->HWConf_104M[SFC_Driving_2];
#elif defined(MT6253L)||defined(MT6252)
	// if efuse bits shows it is for 1st timing
	if((*ProcessID&0x03000000) == 0x0)
	{
		SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL_1]);
     	SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_104M[SFC_DLY_CTL_1]);
	}
	// if efuse bits shows it is for 2nd timing
	else
	{
	 	SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL_2]);
     	SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_104M[SFC_DLY_CTL_2]);
	}	
    tmp_val = *ACIF_CON0 & 0xFFF0FFFF;
    *ACIF_CON0 = tmp_val | (sfi->HWConf_104M[SFC_Driving_1] <<16);
    
#elif defined(MT6255)   
	SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_104M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_104M[SFC_DLY_CTL3]);
	tmp_val = *IO_DRV2 & 0xFF000000;
    *IO_DRV2 = tmp_val | sfi->HWConf_104M[SFC_Driving];
#elif defined(MT6250)|| defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_104M[SFC_MISC_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_104M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_104M[SFC_DLY_CTL3]);
    #if defined(MT6261) || defined(MT2501) || defined(MT2502)
    tmp_driving = *SFIO_CFG0_DRV & 0xFFF8FFF8;
    *SFIO_CFG0_DRV = tmp_driving | (sfi->HWConf_104M[SFC_Driving]);
    tmp_driving = *SFIO_CFG1_DRV & 0xFFF8FFF8;
    *SFIO_CFG1_DRV = tmp_driving | (sfi->HWConf_104M[SFC_Driving]);
    tmp_driving = *SFIO_CFG2_DRV & 0xFFF8FFF8;
    *SFIO_CFG2_DRV = tmp_driving | (sfi->HWConf_104M[SFC_Driving]);
    #else
    tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving
    *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_104M[SFC_Driving]);
    #endif
    /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
	#if defined(MT6250)	
    SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_104M[SFC_Driving]<<12));
	#endif
#else
	#error "Undefined BB chips"
#endif // defined(MT6251)


#elif defined(__SFI_CLK_130MHZ__) /* __SFI_CLK_78MHZ__  ||  __SFI_CLK_80MHZ__ */
    // Device Initialization
    SFI_Dev_Command_List(0,sfi->DevInit_130M);

    /*--------------------------------------------------------------------------
     * Step 2. Initialize Serial Flash Control Registers
     *--------------------------------------------------------------------------*/
    SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_130M[SFC_MAC_CTL]);
    SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_130M[SFC_DR_CTL]);


#if defined(MT6251) || defined(MT6253L) || defined(MT6252) || defined(MT6255)||defined(MT6280)
    #error "Undefined BB chips of SFC 130MHz"
#elif defined(MT6250)|| defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_130M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_130M[SFC_MISC_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_130M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_130M[SFC_DLY_CTL3]);
    #if defined(MT6261) || defined(MT2501) || defined(MT2502)
    tmp_driving = *SFIO_CFG0_DRV & 0xFFF8FFF8;
    *SFIO_CFG0_DRV = tmp_driving | (sfi->HWConf_130M[SFC_Driving]);
    tmp_driving = *SFIO_CFG1_DRV & 0xFFF8FFF8;
    *SFIO_CFG1_DRV = tmp_driving | (sfi->HWConf_130M[SFC_Driving]);
    tmp_driving = *SFIO_CFG2_DRV & 0xFFF8FFF8;
    *SFIO_CFG2_DRV = tmp_driving | (sfi->HWConf_130M[SFC_Driving]);
    #else
    tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving
    *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_130M[SFC_Driving]);
    #endif
    /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
    #if defined(MT6250)	
    SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_130M[SFC_Driving]<<12));
    #endif
#endif


#elif defined(__SFI_CLK_166MHZ__)
    // Device Initialization
    SFI_Dev_Command_List(0,sfi->DevInit_166M);

    /*--------------------------------------------------------------------------
     * Step 2. Initialize Serial Flash Control Registers
     *--------------------------------------------------------------------------*/
    SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_166M[SFC_MAC_CTL]);
    SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_166M[SFC_DR_CTL]);


#if defined(MT6251) || defined(MT6253L) || defined(MT6252) || defined(MT6255)||defined(MT6280)||defined(MT6250)|| defined(MT6261) || defined(MT2501) || defined(MT2502)
    #error "Undefined BB chips of SFC 130MHz"
#elif defined(MT6260)
    SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_166M[SFC_MISC_CTL]);
    SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_166M[SFC_MISC_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_166M[SFC_DLY_CTL2]);
    SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_166M[SFC_DLY_CTL3]);
    tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving
    *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_166M[SFC_Driving]);

#endif


#endif /* __SFI_CLK_78MHZ__ */

    /*--------------------------------------------------------------------------
     * Step 3. EFuse Post process of IO driving/ Sample clk delay/ Input delay
     * Currently, only for MT6250 and MT6260
     *--------------------------------------------------------------------------*/
//#if 0
#if defined(MT6250)||defined(MT6260)
    //Driving Adjustment (-4,-3,-2,-1,0,1,2,3) b'[2-0]
    tmp_val = SFC_GET_EfuseBits(SFC_DRIVING_OFFSET,SFC_DRIVING_SIZE);
    if(SFC_IS_NEGATIVE(tmp_val,SFC_DRIVING_SIZE))
    {
        tmp_driving = *GPIO_DRV0 & GPIO_DRV0_MASK;
        tmp_driving -= (kal_uint16)(SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_DRIVING_SIZE)<<GPIO_DRV0_OFFSET);
        *GPIO_DRV0 = (*GPIO_DRV0 & ~GPIO_DRV0_MASK) | tmp_driving; //External SF
        #if defined(MT6250)
        SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(((kal_uint32)tmp_driving)<<12)); //Internal SF
        #endif
    }
    else
    {
        tmp_driving = *GPIO_DRV0 & GPIO_DRV0_MASK;
        tmp_driving += (kal_uint16)(tmp_val<<GPIO_DRV0_OFFSET);
        *GPIO_DRV0 = (*GPIO_DRV0 & ~GPIO_DRV0_MASK) | tmp_driving; //External SF
        #if defined(MT6250)
        SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(((kal_uint32)tmp_driving)<<12)); //Internal SF
        #endif
    }
    //Data delay Adjustment (0,1,2,3) b'[10-3]
    SFI_WriteReg32(RW_SFI_DLY_CTL2, SFI_ReadReg32(RW_SFI_DLY_CTL2) +
    (SFC_GET_EfuseBits(SFC_INPUT0_DLY_OFFSET,SFC_INPUT0_DLY_SIZE) | (SFC_GET_EfuseBits(SFC_INPUT1_DLY_OFFSET,SFC_INPUT1_DLY_SIZE)<<8)
    | (SFC_GET_EfuseBits(SFC_INPUT2_DLY_OFFSET,SFC_INPUT2_DLY_SIZE)<<16) | (SFC_GET_EfuseBits(SFC_INPUT3_DLY_OFFSET,SFC_INPUT3_DLY_SIZE)<<24)));
    
    //Sample clk delay Adjustment (-2^5 ~ 2^5-1) b'[16-11]
    tmp_val = SFC_GET_EfuseBits(SFC_SAMPLECLK_DLY_OFFSET,SFC_SAMPLECLK_DLY_SIZE);
    if(SFC_IS_NEGATIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE))
    {

        SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_ReadReg32(RW_SFI_DLY_CTL3)- (SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)+(SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
    }
    else
    {
        SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_ReadReg32(RW_SFI_DLY_CTL3)+ (tmp_val+(tmp_val<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
    }    
#endif
    return 0;
#endif  // __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ && !__EXT_BOOTLOADER__

}

#else  // !defined(__DUAL_SERIAL_FLASH_SUPPORT__)

kal_int32 SFI_GetSFSizeSetting(kal_uint32 size)
{
    if (size == 16 * 1024 * 1024 / 8)   // 16 MBit
    {
        return 0;
    }
    else if (size == 32 * 1024 * 1024 / 8)  // 32 MBit
    {
        return 1;
    }
    else if (size == 64 * 1024 * 1024 / 8)  // 64 MBit
    {
        return 2;
    }
    else if (size == 128 * 1024 * 1024 / 8)  // 128 MBit
    {
        return 3;
    }
    else if (size == 256 * 1024 * 1024 / 8)  // 256MBit
    {
        return 4;
    }
    else if (size == 512 * 1024 * 1024 / 8)  // 512 MBit
    {
        return 5;
    }
    else if (size == 1024 * 1024 * 1024 / 8)  // 1 GBit
    {
        return 6;
    }
    else if (size == 2048 * 1024 * 1024 / 8)  // 2 GBit
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

kal_int8 custom_setSFI(void)
{
#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && !defined(__EXT_BOOTLOADER__) // if SF is init in ExtBootloader & this is the small bootloader

    #if defined(MT6260) 
	
    /* Normal Mode Configuration */
	  /*SF clock Enable  Notice: PDN_CLR to enable SF clock */
    SFI_WriteReg16(PDN_CLRD2,(SFI_ReadReg16(PDN_CLRD2)|RG_SFC_SW_CG));
      /*SF pad switch: SF or SPI-Nand */
    SFI_WriteReg16(HW_MISC2, (SFI_ReadReg16(HW_MISC2)|PAD_SWITCH));
      /*SF GPIO configuration*/	
      // Step 1. Set GPIO to SFI
    SFI_WriteReg32(SF_GPIO_MODE8, (SFI_ReadReg32(SF_GPIO_MODE8)&SF_GPIO_MODE8_CLR)|SF_GPIO67|SF_GPIO68|SF_GPIO69|SF_GPIO70|SF_GPIO71);
    SFI_WriteReg32(SF_GPIO_MODE9, (SFI_ReadReg32(SF_GPIO_MODE9)&SF_GPIO_MODE9_CLR)|SF_GPIO72);

	
	/* Dual SF configuration */
	SFI_WriteReg32(SF_GPIO_MODE8, SFI_ReadReg32(SF_GPIO_MODE8) | GPIO_SF2_Enable);

	/* GPIO high-Z Enable*/
	  /* Normal MODE */
    SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_NORMAL_MODE_R0_R1_SET1)));
    SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_NORMAL_MODE_R0_R1_SET1)));
    SFI_WriteReg16(GPIO_RESEN2, (SFI_ReadReg16(GPIO_RESEN2)& (~SF_NORMAL_MODE_R0_R1_SET2)));
    SFI_WriteReg16(GPIO_RESEN5, (SFI_ReadReg16(GPIO_RESEN5)& (~SF_NORMAL_MODE_R0_R1_SET2)));

      /* SLT  MODE */
	if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_SLT_MODE_R0_R1_SET)));
        SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_SLT_MODE_R0_R1_SET)));
    }
	
	#endif //defined(MT6260)

    return 0;

#else   // !__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ || __EXT_BOOTLOADER__

    const CMEMEntrySFI *sfi;
    kal_uint32 tmp_val, i;
    kal_uint16 tmp_driving;
    kal_int32 SF1_SIZE;
    kal_uint8 k=0;
	#if defined(MT6260)  //Add GPIO, clock, pad switch configuration here in case only mini-bootloader init SF device
	
    /* Normal Mode Configuration */
	  /*SF clock Enable  Notice: PDN_CLR to enable SF clock */
    SFI_WriteReg16(PDN_CLRD2,(SFI_ReadReg16(PDN_CLRD2)|RG_SFC_SW_CG));
      /*SF pad switch: SF or SPI-Nand */
    SFI_WriteReg16(HW_MISC2, (SFI_ReadReg16(HW_MISC2)|PAD_SWITCH));
      /*SF GPIO configuration*/	
      // Step 1. Set GPIO to SFI
    SFI_WriteReg32(SF_GPIO_MODE8, (SFI_ReadReg32(SF_GPIO_MODE8)&SF_GPIO_MODE8_CLR)|SF_GPIO67|SF_GPIO68|SF_GPIO69|SF_GPIO70|SF_GPIO71);
    SFI_WriteReg32(SF_GPIO_MODE9, (SFI_ReadReg32(SF_GPIO_MODE9)&SF_GPIO_MODE9_CLR)|SF_GPIO72);

	
	/* Dual SF configuration */
	SFI_WriteReg32(SF_GPIO_MODE8, SFI_ReadReg32(SF_GPIO_MODE8) | GPIO_SF2_Enable);

	/* GPIO high-Z Enable*/
	  /* Normal MODE */
    SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_NORMAL_MODE_R0_R1_SET1)));
    SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_NORMAL_MODE_R0_R1_SET1)));
    SFI_WriteReg16(GPIO_RESEN2, (SFI_ReadReg16(GPIO_RESEN2)& (~SF_NORMAL_MODE_R0_R1_SET2)));
    SFI_WriteReg16(GPIO_RESEN5, (SFI_ReadReg16(GPIO_RESEN5)& (~SF_NORMAL_MODE_R0_R1_SET2)));

      /* SLT  MODE */
	if((SFI_ReadReg32(SEJ_base)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
    {
        SFI_WriteReg16(GPIO_RESEN1, (SFI_ReadReg16(GPIO_RESEN1)& (~SF_SLT_MODE_R0_R1_SET)));
        SFI_WriteReg16(GPIO_RESEN4, (SFI_ReadReg16(GPIO_RESEN4)& (~SF_SLT_MODE_R0_R1_SET)));
    }
	
	#endif //defined(MT6260)
	
    //Enable 2CE GPIO
    #if defined(MT6250)
    i = SFI_ReadReg32(GPIO_SF2);
    SFI_WriteReg32(GPIO_SF2,GPIO_SF2_Enable);
	#endif
    //Enable SF2 and Set SF1 size 
    if ((SF1_SIZE = SFI_GetSFSizeSetting(EMINIT_CMEM_GET_NOR_FLASH_SIZE(0)))<0)    {
        // Add error handler here
        while(1);
    }    
    if(SF1_SIZE == SFI_GetSFSizeSetting(DUAL_NOR_FLASH_SIZE))
    {
    /* Only one SF exists because we allow like (128,128) (256,0) Dual SF pair */
        CS_COUNT_SFI =1;
        #if defined(MT6250)
        SFI_WriteReg32(GPIO_SF2,i); // If only one SF, restore original value of GPIO_SF2
        #elif defined(MT6260)
        SFI_WriteReg32(SF_GPIO_MODE8, SFI_ReadReg32(SF_GPIO_MODE8) & (~GPIO_SF2_Enable));
		#else
        #error "Undefined BB chips"
		#endif
    }
    else
    {
        CS_COUNT_SFI =2;
        /* ONly Enable SF2 when SF2 is existed. */
        SFI_WriteReg32(RW_SFI_MISC_CTL3,SFI_ReadReg32(RW_SFI_MISC_CTL3)|SFI_SF2_EN|((SF1_SIZE<<4)&0x000000F0));
    }
   
    
    for(;k<CS_COUNT_SFI;k++)
    {    
        sfi_index=CMEM_EMIINIT_Index(k);  // API CMCP_EMIINIT_Index() is defined in combo_flash_init.h
        // if __COMBO_MCP_SUPPORT__ was not defined, CMEM_EMIINIT_Index() always retunrs 0.
        // if __COMBO_MCP_SUPPORT__ was defined, CMEM_EMIINIT_Index() returns the index to the sfi config structure.
        //    => if the returned index < 0, means the flash was not included in the mcp list
        if (sfi_index<0)    {
            // Add error handler here
            while(1);
        }
     /*--------------------------------------------------------------------------
         * Step 1.
         * 1. Switch mode QPI/SPI Quad
         * 2. Set Burst/Wrap length
         *--------------------------------------------------------------------------*/
        sfi=&combo_mem_hw_list.List[sfi_index];   // the structure name "combo_mem_hw_list" can be renamed by SFI owner



#if defined(__SFI_CLK_78MHZ__) 
        // Device Initialization
        SFI_Dev_Command_List(k, sfi->DevInit_78M);

     /*--------------------------------------------------------------------------
         * Step 2. Initialize Serial Flash Control Registers
         *--------------------------------------------------------------------------*/
        
#if defined(MT6250)||defined(MT6260)
        if(k==0)
        {   
            /*Common Initialization*/    
            SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_78M[SFC_MAC_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_78M[SFC_MISC_CTL]);
			/* 3.0V dual SF driving must be 6mA*/
			if(CS_COUNT_SFI==2 && sfi->HWConf_78M[SFC_Driving]<=0x200)
		    {
		        tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(0x200);    
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
				#if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(0x200<<12));
                #endif
		    }
            /* 3.0V Single SF driving keeps 4mA*/
			else
			{
                tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_78M[SFC_Driving]);    
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
                #if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_78M[SFC_Driving]<<12));
                #endif
			}
            /*Individual SF Initialization CS0*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_78M[SFC_DR_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_78M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_78M[SFC_DLY_CTL2]);
			/*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
			if(CS_COUNT_SFI==2)
                SFI_WriteReg32(RW_SFI_DLY_CTL3, (sfi->HWConf_78M[SFC_DLY_CTL3]+0x05000005));
			else
                SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_78M[SFC_DLY_CTL3]);
        }
        else
        {
            /*Individual SF Initialization CS1*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL2, sfi->HWConf_78M[SFC_DR_CTL]);
            if( (SFI_ReadReg32(RW_SFI_MISC_CTL2)&0x1) != 0x0 ) // If CS0 no wrap, CS1 should not use wrap. Wrap of SFC has only one bit, for both SF.
                SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_78M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL5, sfi->HWConf_78M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
            SFI_WriteReg32(RW_SFI_DLY_CTL6, (sfi->HWConf_78M[SFC_DLY_CTL3]+0x05000005));
        }
#else
	#error "Undefined BB chips"
#endif //defined(MT6250)||defined(MT6260)

#elif defined(__SFI_CLK_104MHZ__) /* __SFI_CLK_78MHZ__ */
       // Device Initialization
        SFI_Dev_Command_List(k, sfi->DevInit_104M);

      /*--------------------------------------------------------------------------
          * Step 2. Initialize Serial Flash Control Registers
         *--------------------------------------------------------------------------*/

#if defined(MT6250)||defined(MT6260)
        if(k==0)
        {   
            /*Common Initialization*/
            SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_104M[SFC_MAC_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_104M[SFC_MISC_CTL]);
			/* 3.0V dual SF driving must be 6mA*/
			if(CS_COUNT_SFI==2 && sfi->HWConf_104M[SFC_Driving]<=0x200)
		    {
		        tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(0x200);    
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
                #if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(0x200<<12));
                #endif
		    }
            /* 3.0V Single SF driving keeps 4mA*/
			else
			{
                tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_104M[SFC_Driving]);
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
                #if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_104M[SFC_Driving]<<12));
                #endif
            }
            /*Individual SF Initialization CS0*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_104M[SFC_DR_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_104M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_104M[SFC_DLY_CTL2]);
			/*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
			if(CS_COUNT_SFI==2)
                SFI_WriteReg32(RW_SFI_DLY_CTL3, (sfi->HWConf_104M[SFC_DLY_CTL3]+0x05000005));
            else
                SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_104M[SFC_DLY_CTL3]);
        }
        else
        {
            /*Individual SF Initialization CS1*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL2, sfi->HWConf_104M[SFC_DR_CTL]);
            if( (SFI_ReadReg32(RW_SFI_MISC_CTL2)&0x1) != 0x0 ) // If CS0 no wrap, CS1 should not use wrap. Wrap of SFC has only one bit, for both SF.
                SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_104M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL5, sfi->HWConf_104M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
            SFI_WriteReg32(RW_SFI_DLY_CTL6, (sfi->HWConf_104M[SFC_DLY_CTL3]+0x05000005));
        }
#else
	#error "Undefined BB chips"
#endif //defined(MT6250)||defined(MT6260)



#elif defined(__SFI_CLK_130MHZ__) /* __SFI_CLK_78MHZ__  ||  __SFI_CLK_80MHZ__ */
        // Device Initialization
        SFI_Dev_Command_List(k, sfi->DevInit_130M);

       /*--------------------------------------------------------------------------
            * Step 2. Initialize Serial Flash Control Registers
           *--------------------------------------------------------------------------*/
           
#if defined(MT6250)||defined(MT6260)
        if(k==0)
        {   
            /*Common Initialization*/
            SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_130M[SFC_MAC_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_130M[SFC_MISC_CTL]);
			/* 3.0V dual SF driving must be 6mA*/
			if(CS_COUNT_SFI==2 && sfi->HWConf_130M[SFC_Driving]<=0x200)
		    {
		        tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(0x200);    
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
                #if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(0x200<<12));
                #endif
		    }
            /* 3.0V Single SF driving keeps 4mA*/
			else
			{
                tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_130M[SFC_Driving]);
                /* SF_MISC_CTL_3[22:20] for SF driving of internal SF*/
                #if defined(MT6250)
                SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(sfi->HWConf_130M[SFC_Driving]<<12));
                #endif
			}
            /*Individual SF Initialization CS0*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_130M[SFC_DR_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_130M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_130M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
			if(CS_COUNT_SFI==2)
                SFI_WriteReg32(RW_SFI_DLY_CTL3, (sfi->HWConf_130M[SFC_DLY_CTL3]+0x05000005));
			else
                SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_130M[SFC_DLY_CTL3]);
        }
        else
        {
            /*Individual SF Initialization CS1*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL2, sfi->HWConf_130M[SFC_DR_CTL]);
            if( (SFI_ReadReg32(RW_SFI_MISC_CTL2)&0x1) != 0x0 ) // If CS0 no wrap, CS1 should not use wrap. Wrap of SFC has only one bit, for both SF.
                SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_130M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL5, sfi->HWConf_130M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
            SFI_WriteReg32(RW_SFI_DLY_CTL6, (sfi->HWConf_130M[SFC_DLY_CTL3]+0x05000005));
        }
#else
	#error "Undefined BB chips"
#endif //defined(MT6250)||defined(MT6260)

#elif defined(__SFI_CLK_166MHZ__)
        // Device Initialization
        SFI_Dev_Command_List(k, sfi->DevInit_166M);

       /*--------------------------------------------------------------------------
            * Step 2. Initialize Serial Flash Control Registers
           *--------------------------------------------------------------------------*/
           
#if defined(MT6260)
        if(k==0)
        {   
            /*Common Initialization*/
            SFI_WriteReg32(RW_SFI_MAC_CTL, sfi->HWConf_166M[SFC_MAC_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL, sfi->HWConf_166M[SFC_MISC_CTL]);
			/* 3.0V dual SF driving must be 6mA*/
			if(CS_COUNT_SFI==2 && sfi->HWConf_166M[SFC_Driving]<=0x200)
		    {
		        tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(0x200);    
		    }
            /* 3.0V Single SF driving keeps 4mA*/
			else
			{
                tmp_driving = *GPIO_DRV0 & 0xF8FF; //GPIO_DRV0[10:8] for SF driving of external SF
                *GPIO_DRV0 = tmp_driving | (kal_uint16)(sfi->HWConf_166M[SFC_Driving]);
			}
            /*Individual SF Initialization CS0*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL, sfi->HWConf_166M[SFC_DR_CTL]);
            SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_166M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL2, sfi->HWConf_166M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
			if(CS_COUNT_SFI==2)
                SFI_WriteReg32(RW_SFI_DLY_CTL3, (sfi->HWConf_166M[SFC_DLY_CTL3]+0x05000005));
			else
                SFI_WriteReg32(RW_SFI_DLY_CTL3, sfi->HWConf_166M[SFC_DLY_CTL3]);
        }
        else
        {
            /*Individual SF Initialization CS1*/
            SFI_WriteReg32(RW_SFI_DIRECT_CTL2, sfi->HWConf_166M[SFC_DR_CTL]);
            if( (SFI_ReadReg32(RW_SFI_MISC_CTL2)&0x1) != 0x0 ) // If CS0 no wrap, CS1 should not use wrap. Wrap of SFC has only one bit, for both SF.
                SFI_WriteReg32(RW_SFI_MISC_CTL2, sfi->HWConf_166M[SFC_MISC_CTL2]);
            SFI_WriteReg32(RW_SFI_DLY_CTL5, sfi->HWConf_166M[SFC_DLY_CTL2]);
            /*Sample clock delay of dual SF must right shift 5 setps in comparison to Single SF*/
            SFI_WriteReg32(RW_SFI_DLY_CTL6, (sfi->HWConf_166M[SFC_DLY_CTL3]+0x05000005));
        }
#else
	#error "Undefined BB chips"
#endif //defined(MT6250)||defined(MT6260)


#endif /* __SFI_CLK_78MHZ__ */
    }

    /*--------------------------------------------------------------------------
     * Step 3. EFuse Post process of IO driving/ Sample clk delay/ Input delay
     * Currently, only for MT6250 and MT6260
     *--------------------------------------------------------------------------*/
//#if 0
#if defined(MT6250)||defined(MT6260)
    //Driving Adjustment (-4,-3,-2,-1,0,1,2,3) b'[2-0]
    tmp_val = SFC_GET_EfuseBits(SFC_DRIVING_OFFSET,SFC_DRIVING_SIZE);
    if(SFC_IS_NEGATIVE(tmp_val,SFC_DRIVING_SIZE))
    {
        tmp_driving = *GPIO_DRV0 & GPIO_DRV0_MASK;
        tmp_driving -= (kal_uint16)(SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_DRIVING_SIZE)<<GPIO_DRV0_OFFSET);
        *GPIO_DRV0 = (*GPIO_DRV0 & ~GPIO_DRV0_MASK) | tmp_driving; //External SF
        #if defined(MT6250)
        SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(((kal_uint32)tmp_driving)<<12)); //Internal SF
        #endif
    }
    else
    {
        tmp_driving = *GPIO_DRV0 & GPIO_DRV0_MASK;
        tmp_driving += (kal_uint16)(tmp_val<<GPIO_DRV0_OFFSET);
        *GPIO_DRV0 = (*GPIO_DRV0 & ~GPIO_DRV0_MASK) | tmp_driving; //External SF
        #if defined(MT6250)
        SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3)&0xFF8FFFFF|(((kal_uint32)tmp_driving)<<12)); //Internal SF
        #endif
    }
    //Data delay Adjustment (0,1,2,3) b'[10-3]
    /*SF1's Data delay adjustment*/
    SFI_WriteReg32(RW_SFI_DLY_CTL2, SFI_ReadReg32(RW_SFI_DLY_CTL2) +
    (SFC_GET_EfuseBits(SFC_INPUT0_DLY_OFFSET,SFC_INPUT0_DLY_SIZE) | (SFC_GET_EfuseBits(SFC_INPUT1_DLY_OFFSET,SFC_INPUT1_DLY_SIZE)<<8)
    | (SFC_GET_EfuseBits(SFC_INPUT2_DLY_OFFSET,SFC_INPUT2_DLY_SIZE)<<16) | (SFC_GET_EfuseBits(SFC_INPUT3_DLY_OFFSET,SFC_INPUT3_DLY_SIZE)<<24)));
    /*SF2's Data delay adjustment*/
    SFI_WriteReg32(RW_SFI_DLY_CTL5, SFI_ReadReg32(RW_SFI_DLY_CTL5) +
    (SFC_GET_EfuseBits(SFC_INPUT0_DLY_OFFSET,SFC_INPUT0_DLY_SIZE) | (SFC_GET_EfuseBits(SFC_INPUT1_DLY_OFFSET,SFC_INPUT1_DLY_SIZE)<<8)
    | (SFC_GET_EfuseBits(SFC_INPUT2_DLY_OFFSET,SFC_INPUT2_DLY_SIZE)<<16) | (SFC_GET_EfuseBits(SFC_INPUT3_DLY_OFFSET,SFC_INPUT3_DLY_SIZE)<<24)));

    
    //Sample clk delay Adjustment (-2^5 ~ 2^5-1) b'[16-11]
    tmp_val = SFC_GET_EfuseBits(SFC_SAMPLECLK_DLY_OFFSET,SFC_SAMPLECLK_DLY_SIZE);
    if(SFC_IS_NEGATIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE))
    {
        /*SF1's sample clk delay adjustment*/
        SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_ReadReg32(RW_SFI_DLY_CTL3)- (SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)+(SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
        /*SF2's sample clk delay adjustment*/
        SFI_WriteReg32(RW_SFI_DLY_CTL6, SFI_ReadReg32(RW_SFI_DLY_CTL6)- (SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)+(SFC_NEGATIVE_TO_POSITIVE(tmp_val,SFC_SAMPLECLK_DLY_SIZE)<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
    }
    else
    {
        /*SF1's sample clk delay adjustment*/
        SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_ReadReg32(RW_SFI_DLY_CTL3)+ (tmp_val+(tmp_val<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
        /*SF2's sample clk delay adjustment*/
        SFI_WriteReg32(RW_SFI_DLY_CTL6, SFI_ReadReg32(RW_SFI_DLY_CTL6)+ (tmp_val+(tmp_val<<SFIFO_WR_EN_DLY_SEL_OFFSET)) );
    }    
#endif
    return 0;
#endif  // __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ && !__EXT_BOOTLOADER__
}

#endif // !defined(__DUAL_SERIAL_FLASH_SUPPORT__)



/*************************************************************************
* FUNCTION
*  custom_setAdvSFI()
*
* DESCRIPTION
*   This routine aims to set additional SFI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/


kal_int8 custom_setAdvSFI(void)
{
#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && !defined(__EXT_BOOTLOADER__) // if SF is init in ExtBootloader & this is the small bootloader

    return 0;

#else   // !__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ || __EXT_BOOTLOADER__

   kal_int8    status = 0;

#if defined(MT6251)

    #if defined(__SFI_CLK_104MHZ__) 
        *PLL_CON1 = 0x0425; // DSP: MPLL 104Mhz, SF: MPLL 104Mhz, GSM: from UPLL, DCM: from MPLL
        
    #elif defined(__SFI_CLK_78MHZ__)
      *PLL_CON1 = 0x0415; // DSP: MPLL 104Mhz, SF: MPLL 78Mhz, GSM: from UPLL, DCM: from MPLL
    #endif
    *PLL_CON4 = 0x5575; // need to set the SF_CLK to 78/104Mhz, for the case of Flash Tool will set SF_CLK to 26Mhz
    
#elif defined(MT6253L)||defined(MT6252)

  #if defined(__SFI_CLK_104MHZ__) 
        *PLL_CON0 &= 0xFFFC;
        *PLL_CON0 |= 0x0003;

    #elif defined(__SFI_CLK_78MHZ__) 
      *PLL_CON0 &= 0xFFFC;
        *PLL_CON0 |= 0x0002;
  #endif
#elif defined (MT6255)
	
	#if defined(__SFI_CLK_104MHZ__) 
	  *PLL_CON2 &= 0xFFF0;
	  *PLL_CON2 |= 0x0004; //Select SF source form HBUS 104MHz
	#elif defined(__SFI_CLK_78MHZ__) 
		#if defined(__EMI_CLK_166MHZ__)
	  		*PLL_CON2 &= 0xFFF0;
	  		*PLL_CON2 |= 0x000A; //EPLL 312MHz, SFC 78MHz = EPLL / 3
		#elif defined(__EMI_CLK_200MHZ__)
			*PLL_CON2 &= 0xFFF0;
	  		*PLL_CON2 |= 0x0008; //EPLL 390MHz, SFC 78MHz = EPLL / 5
	    #else
      		#error "Undefined EPLL source"
		#endif
	#endif //__SFI_CLK_104MHZ__
#elif defined(MT6250) || defined(MT6280) ||defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
//MT6250 and MT6280 and MT6260/61/2501/2502 SFC PLL setting will be done by PLL owner
#else
	#error "Undefined BB chips"
#endif //defined(MT6251)

   return status;

#endif  // __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ && !__EXT_BOOTLOADER__
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#if defined(MT6252) || defined(MT6250) || defined(MT6280)
static kal_uint32 save_sf_mac_ctrl, save_pll_con0;
#endif

kal_uint32 SFI_DLY_CTL_High;
kal_uint32 SFI_MISC_CTL_High;
kal_uint32 SFI_DLY_CTL_Low;
kal_uint32 SFI_MISC_CTL_Low;

#pragma arm section rwdata , rodata , zidata

#pragma arm section code = "SECOND_PART"
int custom_SFIDynamicClockSwitch_Init()
{
     const CMEMEntrySFI_DCM *sfi;
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    SFI_DCM_index = CMEM_Index(0);   
#else
    SFI_DCM_index = CMEM_Index();
#endif

   sfi=&combo_mem_hw_list_dcm.List[SFI_DCM_index]; 
 
#if defined(MT6252)

#if defined(__SFI_CLK_104MHZ__) 

    if((*ProcessID&0x03000000) == 0x0)
    {
        SFI_DLY_CTL_High = sfi->HWConf_104M[2];
        SFI_MISC_CTL_High = sfi->HWConf_104M[1];
    }
    else
    {
        SFI_DLY_CTL_High = sfi->HWConf_104M[4];
        SFI_MISC_CTL_High = sfi->HWConf_104M[3];
    }
   
#elif defined(__SFI_CLK_78MHZ__) 

    if((*ProcessID&0x03000000) == 0x0)
    {
        SFI_DLY_CTL_High = sfi->HWConf_78M[2];
        SFI_MISC_CTL_High = sfi->HWConf_78M[1];
    }
    else
    {
        SFI_DLY_CTL_High = sfi->HWConf_78M[4];
        SFI_MISC_CTL_High = sfi->HWConf_78M[3];
    }
#endif // defined(__SFI_CLK_104MHZ__) 

   SFI_DLY_CTL_Low = sfi->HWConf_13M[2];
   SFI_MISC_CTL_Low = sfi->HWConf_13M[1]; 
   return 0;
#elif defined(MT6250) //defined(MT6252)

#if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
#if defined(__SFI_CLK_130MHZ__) 
  SFI_DLY_CTL_High = sfi->HWConf_130M[2];
  SFI_MISC_CTL_High = sfi->HWConf_130M[0];
#elif defined(__SFI_CLK_104MHZ__) 
  SFI_DLY_CTL_High = sfi->HWConf_104M[2];
  SFI_MISC_CTL_High = sfi->HWConf_104M[0];
#elif defined(__SFI_CLK_78MHZ__) 
  SFI_DLY_CTL_High = sfi->HWConf_78M[2];
  SFI_MISC_CTL_High = sfi->HWConf_78M[0];
#endif // defined(__SFI_CLK_130MHZ__) 
  SFI_DLY_CTL_Low = sfi->HWConf_26M[2];
  SFI_MISC_CTL_Low = sfi->HWConf_26M[0];
#endif //!defined(__DUAL_SERIAL_FLASH_SUPPORT__)
  return 0;

#elif defined(MT6280) //defined(MT6252)
#if defined(__SFI_CLK_80MHZ__) 
  SFI_DLY_CTL_High = sfi->HWConf_78M[2];
  SFI_MISC_CTL_High = sfi->HWConf_78M[0];
#endif // defined(__SFI_CLK_80MHZ__)
  SFI_DLY_CTL_Low = sfi->HWConf_26M[2];
  SFI_MISC_CTL_Low = sfi->HWConf_26M[0]; 
  return 0;

#elif defined(MT6251) || defined(MT6255) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
  return 0;  
#else
	#error "Undefined BB chips"
#endif /* defined(MT6252) */

}

#pragma arm section code = "INTSRAM_ROCODE"

int custom_SFIDynamicClockSwitch(mcu_clock_enum clock)
{
/**
  * The DCM switch process is a highly-DCM-design-dependent flow, so we will wrap the whole flow with the whole chip options.
  */

#if defined(MT6252)

   register kal_uint32 tmp;

   switch (clock)
   {
      case MCU_104MHZ:
      case MCU_52MHZ:
         /* Recover MAC ctrl */
      SFI_WriteReg32( RW_SFI_MAC_CTL, save_sf_mac_ctrl );

      /* Recover delay setting */
     SFI_WriteReg32(RW_SFI_DLY_CTL, SFI_DLY_CTL_High);

     /* Recover MISC CTRL */
     SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_MISC_CTL_High);     

     /* Recover PLL Setting */
     *PLL_CON0 = save_pll_con0;

         break;

      case MCU_13MHZ:

         save_sf_mac_ctrl = SFI_ReadReg32(RW_SFI_MAC_CTL);
     save_pll_con0 = *PLL_CON0;

     /* Using Disable sync and double sync mode */
     SFI_WriteReg32( RW_SFI_MAC_CTL, ( save_sf_mac_ctrl & 0xFFFF7DFF ) );

     /* Set 13MHz Delay */
     //SFI_WriteReg32(RW_SFI_DLY_CTL, sfi->HWConf_13M[2]);
     SFI_WriteReg32(RW_SFI_DLY_CTL,  SFI_DLY_CTL_Low);

     /* Set MISC CTRL and make sure that 1T delay and invert clock are  OFF */
     tmp = SFI_ReadReg32( RW_SFI_MISC_CTL );
     //SFI_WriteReg32( RW_SFI_MISC_CTL, ((tmp & 0x00FFFE70 )| (sfi->HWConf_13M[1] & 0xFF00000F)) );
     SFI_WriteReg32( RW_SFI_MISC_CTL, ((tmp & 0x00FFFE70 )| (SFI_MISC_CTL_Low & 0xFF00000F)) );
#if defined(EXT_26M)
         /* Using CLKSQ and div by 2 */
         *PLL_CON0 = (*PLL_CON0 & 0xFFF8 ) | 0x4;
#elif defined (EXT_13M) /* EXT_26M */
         /* Using CLKSQ */
         *PLL_CON0 = (*PLL_CON0 & 0xFFF8 );
#endif   /* EXT_26M */
         break;

      default:
         return -1;
   }

   return 0;
#elif defined (MT6250)

#if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
   switch (clock)
   {
      case MCU_260MHZ:
      /* Recover delay setting */
     SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_DLY_CTL_High);
      /* Recover 1T delay or Inverse clock setting */
     SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_MISC_CTL_High);
     /* Recover PLL Setting */
     *PLL_CLK_CONDC = save_pll_con0;
         break;

      case MCU_26MHZ:
     save_pll_con0 = *PLL_CLK_CONDC;
     /* Set 26MHz Delay */
     SFI_WriteReg32(RW_SFI_DLY_CTL3,  SFI_DLY_CTL_Low);
      /* Reset 1T delay or Inverse clock setting */
     SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_MISC_CTL_Low);
      
     *PLL_CLK_CONDC = (*PLL_CLK_CONDC & 0xFFFFFFF8) | 0x1;
         break;

      default:
         return -1;
   }
#endif //!defined(__DUAL_SERIAL_FLASH_SUPPORT__)
   return 0;
   
#elif defined (MT6280)
      switch (clock)
      {
         case MCU_480MHZ:
         /* Recover delay setting */
        SFI_WriteReg32(RW_SFI_DLY_CTL3, SFI_DLY_CTL_High);
         /* Recover 1T delay or Inverse clock setting */
        SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_MISC_CTL_High);
        /* Recover PLL Setting */
        *PLL_CLKSW_CKSEL2 = (kal_uint16)save_pll_con0;
            break;
   
         case MCU_26MHZ:
        save_pll_con0 = *PLL_CLKSW_CKSEL2;
        /* Set 26MHz Delay */
        SFI_WriteReg32(RW_SFI_DLY_CTL3,  SFI_DLY_CTL_Low);
        /* Reset 1T delay or Inverse clock setting */
        SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_MISC_CTL_Low);
        
        *PLL_CLKSW_CKSEL2 = (*PLL_CLKSW_CKSEL2 & 0xFFF0) | 0x1;
            break;
   
         default:
            return -1;
      }
      
      return 0;

#elif defined(MT6251) || defined(MT6255) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
  return 0;
#else
	#error "Undefined BB chips"
#endif   /* MT6252H || MT6252 */


}

#pragma arm section code

#if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) && defined(__EXT_BOOTLOADER__) // if SF is init in ExtBootloader & this is the ext bootloader

#if defined(MT6250)
// 6250 PLL registers
#define CLK_CONDH   ((volatile unsigned int *)(CONFIG_SD_base + 0x11C))
#define CLK_CONDC   ((volatile unsigned int *)(CONFIG_SD_base + 0x108))
#elif defined(MT6260)
// 6260 PLL registers
#define CLK_CONDH   ((volatile unsigned int *)(CONFIG_base + 0x11C))
#define CLK_CONDC   ((volatile unsigned int *)(CONFIG_base + 0x108))
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
// 6261 PLL registers
#define CLK_CONDH   ((volatile unsigned int *)(CONFIG_base + 0x11C))
#define CLK_CONDC   ((volatile unsigned int *)(CONFIG_base + 0x108))
#define MPLL_CON0   ((volatile unsigned short *)(MIXED_SD_base + 0x100))
#endif

#pragma arm section code = "INTERNCODE", rodata = "INTERNDATA", rwdata = "INTERNDATA", zidata = "INTERNDATA"
#include "custom_sfi_clock.h"

int custom_setSFIExt()
{
#if defined(MT6250)
    // init SFI & SF device (QPI / wrap ...etc)
    custom_setSFI();
    custom_setAdvSFI();
	
#if !defined(__SERIAL_FLASH_STT_EN__) // Not set PLL for Basic STT test
    // init SFI clock
    #if defined(__SFI_CLK_130MHZ__)

        *CLK_CONDH &= 0xFFFFFFF8;
        *CLK_CONDH |= 0x00000001;
        *CLK_CONDC &= 0xFFFFFFF8;
        *CLK_CONDC |= 0x00000004;

    #elif defined(__SFI_CLK_104MHZ__)

        *CLK_CONDH &= 0xFFFFFFF8;
        *CLK_CONDH |= 0x00000003;
        *CLK_CONDC &= 0xFFFFFFF8;
        *CLK_CONDC |= 0x00000002;  //MPLL 780 / 8 =97.5 MHz

    #elif defined(__SFI_CLK_78MHZ__)

        *CLK_CONDH &= 0xFFFFFFF8;
        *CLK_CONDH |= 0x00000004; //*CLK_CONDH |= 0x00000005;  //65MHz setting
        *CLK_CONDC &= 0xFFFFFFF8;
        *CLK_CONDC |= 0x00000004;

    #endif
#endif //!defined(__SERIAL_FLASH_STT_EN__)
#elif defined(MT6260)
    // init SFI & SF device (QPI / wrap ...etc)
    custom_setSFI();
    custom_setAdvSFI();
	
#if !defined(__SERIAL_FLASH_STT_EN__) // Not set PLL for Basic STT test
// init SFI clock
#if defined(__SFI_CLK_166MHZ__) //Use EPLL/4 = 650MHz/4 = 162.5MHz down hopping 0~-8%

	*CLK_CONDH &= 0xFFFFFFF0;
	*CLK_CONDH |= 0x0000000B;
	*CLK_CONDC &= 0xFFFFFFFE;
	*CLK_CONDC |= 0x00000001;

#elif defined(__SFI_CLK_130MHZ__)

	*CLK_CONDH &= 0xFFFFFFF0;
	*CLK_CONDH |= 0x00000001;
	*CLK_CONDC &= 0xFFFFFFFE;
	*CLK_CONDC |= 0x00000001;

#elif defined(__SFI_CLK_104MHZ__)

	*CLK_CONDH &= 0xFFFFFFF0;
	*CLK_CONDH |= 0x00000002;
	*CLK_CONDC &= 0xFFFFFFFE;
	*CLK_CONDC |= 0x00000001;  

#elif defined(__SFI_CLK_78MHZ__)

	*CLK_CONDH &= 0xFFFFFFF0;
	*CLK_CONDH |= 0x00000004; 
	*CLK_CONDC &= 0xFFFFFFFE;
	*CLK_CONDC |= 0x00000001;

#endif
#endif //!defined(__SERIAL_FLASH_STT_EN__)
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
    // init SFI & SF device (QPI / wrap ...etc)
    custom_setSFI();
    custom_setAdvSFI();
	
#if !(defined(__SERIAL_FLASH_STT_EN__) || defined(IC_MODULE_TEST)) // Not set PLL for Basic STT test, SLT test
// init SFI clock

#if defined(__SFI_CLK_130MHZ__)

    if( (*MPLL_CON0&0x3F00) == 0x1800) //MPLL624M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000001; //MPLL/5 = 124.8
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else if( (*MPLL_CON0&0x3F00) == 0x1400) //MPLL520M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000000; //MPLL/4 = 130
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else
    {
        while(1); //Stop here
    }
#elif defined(__SFI_CLK_104MHZ__)

    if( (*MPLL_CON0&0x3F00) == 0x1800) //MPLL624M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000002; //MPLL/6 = 104
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else if( (*MPLL_CON0&0x3F00) == 0x1400) //MPLL520M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000001; //MPLL/5 = 104
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else
    {
	    while(1); //Stop here
    } 

#elif defined(__SFI_CLK_78MHZ__)

    if( (*MPLL_CON0&0x3F00) == 0x1800) //MPLL624M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000004; //MPLL/8 = 78
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else if( (*MPLL_CON0&0x3F00) == 0x1400) //MPLL520M
    {
        *CLK_CONDH &= 0xFFFFFFF0; 
        *CLK_CONDH |= 0x00000003; //MPLL/7 = 74.3
        *CLK_CONDC &= 0xFFFFFFFE; 
        *CLK_CONDC |= 0x00000001;
    }
    else
    {
        while(1); //Stop here
    }

#endif
#endif //!defined(__SERIAL_FLASH_STT_EN__)

#else
    #error "Please add custom_SetSFIExt for __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__!"
#endif  // platforms which supports __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__

    return 0;
}

#else   // !__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ || !__EXT_BOOTLOADER__

int custom_setSFIExt()
{
    return 0;
}

#endif  // __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ && __EXT_BOOTLOADER__

#pragma arm section code

#else   /* ! __SERIAL_FLASH_EN__*/

#include "kal_release.h"
#include "pll.h"

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
kal_int8 custom_setSFI(void)
{	
	return 0;
}

kal_int8 custom_setAdvSFI(void)
{
	return 0;
}
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#pragma arm section code = "SECOND_PART"
int custom_SFIDynamicClockSwitch_Init()
{
	return 0;
}


#pragma arm section code = "INTSRAM_ROCODE"
int custom_SFIDynamicClockSwitch(mcu_clock_enum clock)
{
	return 0;
}
#pragma arm section code = "INTERNCODE"
int custom_setSFIExt()
{
    return 0;
}
#pragma arm section code

#endif  /* __SERIAL_FLASH_EN__*/
