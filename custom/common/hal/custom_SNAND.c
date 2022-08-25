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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__UBL__)    // bootloader (both mini & external) only
#if defined(__SPI_NAND_SUPPORT__)

#include "kal_general_types.h"
#include <reg_base.h>
#include "snand_hw.h"
#include "custom_sfi_clock.h"
#include "custom_SNAND.h"
#include "combo_flash_init.h"
#include "flash_opt.h"
#include "pll.h"

#ifdef __MTK_TARGET__  //Put combo_mem_hw_list_dcm into Second Part to 1. avoid being located to ZIMAGE 2. Avoid Leakage problem
#pragma arm section rodata = "SECOND_PART"
#endif /* __MTK_TARGET__ */


#ifdef __MTK_TARGET__
#if defined(__EXT_BOOTLOADER__)
#pragma arm section code = "INTERNCODE", rodata = "INTERNDATA", zidata = "INTERNDATA"
#else
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif
#endif /* __MTK_TARGET__ */

#if defined(MT6260)
#if defined(__EXT_BOOTLOADER__)
#pragma arm section rodata = "INTERNDATA"
#else
#pragma arm section rodata = "EMIINITCONST"
#endif
#include "combo_SNAND_config.h"
#endif

kal_int32 g_snand_combo_idx = -1; // note: invalid combo_idx is -1

void custom_snand_get_combo_idx()
{
#if !defined(__EXT_BOOTLOADER__) // mini bootloader

    // do nothing

#else   // __EXT_BOOTLOADER__

    // if __COMBO_MEMORY_SUPPORT__ was not defined, CMEM_EMIINIT_Index() always retunrs 0.
    // if __COMBO_MEMORY_SUPPORT__ was defined, CMEM_EMIINIT_Index() returns the index to the sfi config structure.
    //    => if the returned index < 0, means the flash was not included in the mcp list

    if (g_snand_combo_idx < 0)
    {
        g_snand_combo_idx = CMEM_EMIINIT_Index();   // API CMCP_EMIINIT_Index() is defined in combo_flash_init.h
    }
#endif
}

CMEMEntrySNAND * custom_snand_get_combo_entry()
{
    custom_snand_get_combo_idx();   // get g_snand_combo_idx

    if (g_snand_combo_idx >= 0)
    {
        return (CMEMEntrySNAND *)(&(combo_mem_hw_list.List[g_snand_combo_idx]));
    }
    else
    {
        return NULL;
    }
}

kal_int8 custom_snand_init_timing(void)
{
#if !defined(__EXT_BOOTLOADER__) // mini bootloader

    return 0;

#else   // __EXT_BOOTLOADER__

    const CMEMEntrySNAND *snand;
    kal_uint16 tmp_driving;

    /*--------------------------------------------------------------------------
     * 1. Slow down SF_CLK to 26Mhz for META mode
     * At META mode, the PLL will be enabled
     * At non-META mode, bootrom will disable PLL
     *--------------------------------------------------------------------------*/

    custom_snand_get_combo_idx();   // get g_snand_combo_idx

    /*--------------------------------------------------------------------------
     * Step 1. Initialize SNF Registers
     *--------------------------------------------------------------------------*/

    if (g_snand_combo_idx >= 0)
    {
        snand = &combo_mem_hw_list.List[g_snand_combo_idx];   // the structure name "combo_mem_hw_list" can be renamed by SFI owner

        #if defined(__SFI_CLK_104MHZ__)

            #if defined(MT6260)
                *RW_SNAND_DLY_CTL1 = snand->hw_conf_104M[SNAND_AUTOGEN_REG_SNF_DLY_CTL1];
                *RW_SNAND_DLY_CTL2 = snand->hw_conf_104M[SNAND_AUTOGEN_REG_SNF_DLY_CTL2];
                *RW_SNAND_DLY_CTL3 = snand->hw_conf_104M[SNAND_AUTOGEN_REG_SNF_DLY_CTL3];
                *RW_SNAND_DLY_CTL4 = snand->hw_conf_104M[SNAND_AUTOGEN_REG_SNF_DLY_CTL4];
                *RW_SNAND_MISC_CTL = snand->hw_conf_104M[SNAND_AUTOGEN_REG_SNF_MISC_CTL];
                tmp_driving = *RW_GPIO_DRV0 & 0xF8FF;   //GPIO_DRV0[10:8] for SPI-NAND driving
                *RW_GPIO_DRV0 = tmp_driving | (kal_uint16)(snand->hw_conf_104M[SNAND_AUTOGEN_REG_DRIVING]);
            #else
        	    #error "Undefined BB chips"
            #endif

        #endif /* __SFI_CLK_104MHZ__ */

    }

    return 0;

#endif  // __SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ && !__EXT_BOOTLOADER__

}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#if defined(__EXT_BOOTLOADER__)

#pragma arm section code = "INTERNCODE", rodata = "INTERNDATA", rwdata = "INTERNDATA", zidata = "INTERNDATA"
#include "custom_sfi_clock.h"

int custom_snand_init_in_extbootloader()
{
#if defined(MT6260)

    kal_uint32  reg_val;
    kal_uint32  tmp;

    // init SNAND
    custom_snand_init_timing();

    // init clock
    #if !defined(__SNAND_STT_EN__)  // STT load: Skip clock raising here
    #if defined(__SFI_CLK_104MHZ__)

    	*PLL_CLK_CONDH &= 0xFFFFFFF0;
    	*PLL_CLK_CONDH |= 0x00000002;
    	*PLL_CLK_CONDC &= 0xFFFFFFFE;
    	*PLL_CLK_CONDC |= 0x00000001;

    #endif
    #endif  // __SNAND_STT_EN__

    /*-------------------------------------------------------------------------------------------------
     * save g_snand_combo_idx for MAUI SPI-NAND Init
     *
     * save it to SNF_ER_CTL2::ERASE_ADDR because erase will not be used between bootloader and MAUI init
     *-------------------------------------------------------------------------------------------------*/
    if (g_snand_combo_idx >= 0)
    {
        tmp = (kal_uint32)g_snand_combo_idx;
    }
    else
    {
        tmp = 0xFF;
    }

    *RW_SNAND_ER_CTL2 = (0xFFFFFF00 | (tmp & 0x000000FF));

#else
    #error "Please add custom_setSNANDExt for SPI-NAND booting project!"
#endif

    return 0;
}

#else   // mini bootloader

    #error "Mini-bootloader should not compile custom_SNAND.c"

#endif  // __EXT_BOOTLOADER__

#pragma arm section code

#else   /* ! __SPI_NAND_SUPPORT__ */

#include "kal_release.h"

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
kal_int8 custom_snand_init_timing(void)
{
	return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#pragma arm section code = "INTERNCODE"
int custom_snand_init_in_extbootloader()
{
    return 0;
}

#pragma arm section code

#endif  // __SPI_NAND_SUPPORT__
#endif  // __UBL__


