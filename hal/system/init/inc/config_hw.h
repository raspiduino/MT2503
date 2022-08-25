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
 *   config_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CONFIG_HW_H__
#define __CONFIG_HW_H__

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_non_specific_general_types.h"
#include "reg_base.h"




/*******************************************************************************
 * header files body
 *******************************************************************************/

#if defined(MT6268T)
#define MT6268T_SERIES_CONFIG
#endif  /* MT6268T */

#if defined(MT6268H)
#define MT6268T_SERIES_CONFIG
#endif  /* MT6268H */


/*******************************************************************************
 * Version
 *******************************************************************************/
#if defined(MT6276_S01) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
 
#define HW_VER                   ((volatile UINT16P)(VERSION_base+0x0000))
#define FW_VER                   ((volatile UINT16P)(VERSION_base+0x0004))
#define SW_VER                   FW_VER
#define HW_CODE                  ((volatile UINT16P)(VERSION_base+0x0008))
#define HW_SUBCODE               ((volatile UINT16P)(VERSION_base+0x000C))

#else /* MT6276_S01 || MT6250 */ 

#define HW_VER                   ((volatile UINT16P)(CONFIG_base+0x0000))
#define FW_VER                   ((volatile UINT16P)(CONFIG_base+0x0004))
#define SW_VER                   FW_VER
#define HW_CODE                  ((volatile UINT16P)(CONFIG_base+0x0008))
#if defined(MT6253E) || defined(MT6253L) || defined(MT6276) || defined(MT6252H) || defined(MT6252)
#define HW_SUBCODE               ((volatile UINT16P)(CONFIG_base+0x000C))
#endif

#endif /* MT6276_S01 */


/*******************************************************************************
 * System special register
 *******************************************************************************/
#if defined(MT6573)
#define SW_MISC_L                ((volatile UINT32P)(AP_CONFIG_base+0x160))
#define SW_MISC_H                ((volatile UINT32P)(AP_CONFIG_base+0x164))
/* MT6573 */
#elif defined(MT6250)
#define SW_MISC_L                ((volatile UINT32P)(CONFIG_base+0x228))
#define SW_MISC_H                ((volatile UINT32P)(CONFIG_base+0x22C))
/* MT6250 */
#else
#define SW_MISC_L                ((volatile UINT32P)(CONFIG_base+0x10))
#define SW_MISC_H                ((volatile UINT32P)(CONFIG_base+0x14))
#endif

/*******************************************************************************
 * CLK registers
 *******************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230)

#define MPLL                     ((volatile UINT16P)(CONFIG_base+0x100))   /* MPLL Freq control */
#define DPLL                     ((volatile UINT16P)(CONFIG_base+0x104))   /* DPLL Freq control */
#define UPLL                     ((volatile UINT16P)(CONFIG_base+0x108))   /* UPLL Freq control */
#define TPLL                     ((volatile UINT16P)(CONFIG_base+0x10C))   /* TPLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x110))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */

#elif defined(MT6268T_SERIES_CONFIG)

#define PLL1                     ((volatile UINT16P)(CONFIG_base+0x100))   /* PLL1 Freq control */
#define PLL2                     ((volatile UINT16P)(CONFIG_base+0x104))   /* PLL2 Freq control */
#define PLL3                     ((volatile UINT16P)(CONFIG_base+0x108))   /* PLL3 Freq control */
#define PLL4                     ((volatile UINT16P)(CONFIG_base+0x10C))   /* PLL4 Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x110))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define PLL5                     ((volatile UINT16P)(CONFIG_base+0x120))   /* PLL5 Freq control */
#define PLL6                     ((volatile UINT16P)(CONFIG_base+0x124))   /* PLL6 Freq control */
#define PLLSEL                   ((volatile UINT16P)(CONFIG_base+0x128))   /* PLLSEL */
#define UMTS_DIV                 ((volatile UINT16P)(CONFIG_base+0x12C))   /* UMTS Clock Divider */
#define SDMCON                   ((volatile UINT16P)(CONFIG_base+0x180))   /* Sigma-Delta Control */


#elif defined(MT6253T) || defined(MT6253)

#define PLL                      ((volatile UINT16P)(0x83000000+0x204))   /* PLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(0x83000000+0x100))   /* Clock control */
#define EMICLK_CON               ((volatile UINT16P)(CONFIG_base+0x110))   /* EMI Clock Control */

#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define ARB_1T_EN                ((volatile UINT16P)(CONFIG_base+0x714))   /* Bus Arbitration 1T Enable */
#define LYR2_EMPTY_EN            ((volatile UINT16P)(CONFIG_base+0x018))   /* AHB Layer2 Hold Master Enable */
#define LYR2_EMPTY               ((volatile UINT16P)(CONFIG_base+0x01C))   /* AHB Layer2 Hold Master Status */
#define MPLL_CON1                ((volatile UINT16P)(0x83000214))
#define UPLL_CON1                ((volatile UINT16P)(0x8300020C))
#define TDMA_FHSTR0              ((volatile UINT16P)(0x82000320)) 
#define TDMA_FHSTR1              ((volatile UINT16P)(0x82000324)) 
#define TDMA_FHSTR2              ((volatile UINT16P)(0x82000328)) 
#define TDMA_FHSTR3              ((volatile UINT16P)(0x8200032C)) 
#define TDMA_FHSTR4              ((volatile UINT16P)(0x82000330)) 
#define TDMA_FHSTR5              ((volatile UINT16P)(0x82000334)) 
#define TDMA_TQWRAP              ((volatile UINT16P)(0x82000004)) // TDMA counter wrap
#define TDMA_TQWRAPI             ((volatile UINT16P)(0x82000008)) // TDMA counter wrap
#define TDMA_EVT_VALID           ((volatile UINT16P)(0x8200000C)) // TMDA VALID strobe timing
#define MPLL_TDMAWB01            ((volatile UINT16P)(0x83000220))
#define MPLL_TDMAWB23            ((volatile UINT16P)(0x83000224))
#define MPLL_TDMAWB45            ((volatile UINT16P)(0x83000228))


#elif defined(MT6251)

#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define PLL_CON0                 ((volatile UINT16P)(PLL_base+0x100))
#define PLL_CON1                 ((volatile UINT16P)(PLL_base+0x104))
#define PLL_CON2                 ((volatile UINT16P)(PLL_base+0x108))
#define PLL_CON3                 ((volatile UINT16P)(PLL_base+0x10C))
#define PLL_CON4                 ((volatile UINT16P)(PLL_base+0x110))
#define PLL_CON5                 ((volatile UINT16P)(PLL_base+0x114))
#define PLL_CON6                 ((volatile UINT16P)(PLL_base+0x118))
#define UPLL_CON2                ((volatile UINT16P)(PLL_base+0x208))
#define UPLL_CON3                ((volatile UINT16P)(PLL_base+0x20C))
#define MPLL_CON2                ((volatile UINT16P)(PLL_base+0x308))
#define MPLL_CON3                ((volatile UINT16P)(PLL_base+0x30C))
#define LYR2_EMPTY_EN            ((volatile UINT16P)(CONFIG_base+0x018))   /* AHB Layer2 Hold Master Enable */
#define LYR2_EMPTY               ((volatile UINT16P)(CONFIG_base+0x01C))   /* AHB Layer2 Hold Master Status */
#define SF_MISC_CTL              ((volatile UINT32P)(SFI_base + 0x0018))

#elif defined(MT6253E) || defined(MT6253L)

#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define ARB_1T_EN                ((volatile UINT16P)(CONFIG_base+0x714))   /* Bus Arbitration 1T Enable */
#define LYR2_EMPTY_EN            ((volatile UINT16P)(CONFIG_base+0x030))   /* AHB Layer2 Hold Master Enable */
#define LYR2_EMPTY               ((volatile UINT16P)(CONFIG_base+0x034))   /* AHB Layer2 Hold Master Status */
#define EMI_CLK_SEL              ((volatile UINT32P)(CONFIG_base+0x120))   /* EMI clock switch register */
#define CLKSQ_CON0               ((volatile UINT16P)(PLL_CLKSQ_base+0x100))   /* Clock control */
#define CLKSQ_CON1               ((volatile UINT16P)(PLL_CLKSQ_base+0x104))   /* Clock control */
#define PLL_CON1                 ((volatile UINT16P)(PLL_CLKSQ_base+0x204))   /* PLL Freq control */
#define MPLL_CON1                ((volatile UINT16P)(PLL_CLKSQ_base+0x214))
#define UPLL_CON1                ((volatile UINT16P)(PLL_CLKSQ_base+0x20C))
#define MPLL_TDMAWB01            ((volatile UINT16P)(PLL_CLKSQ_base+0x220))
#define MPLL_TDMAWB23            ((volatile UINT16P)(PLL_CLKSQ_base+0x224))
#define MPLL_TDMAWB45            ((volatile UINT16P)(PLL_CLKSQ_base+0x228))
#define TDMA_FHSTR0              ((volatile UINT16P)(TDMA_base+0x320)) 
#define TDMA_FHSTR1              ((volatile UINT16P)(TDMA_base+0x324)) 
#define TDMA_FHSTR2              ((volatile UINT16P)(TDMA_base+0x328)) 
#define TDMA_FHSTR3              ((volatile UINT16P)(TDMA_base+0x32C)) 
#define TDMA_FHSTR4              ((volatile UINT16P)(TDMA_base+0x330)) 
#define TDMA_FHSTR5              ((volatile UINT16P)(TDMA_base+0x334)) 
#define TDMA_TQWRAP              ((volatile UINT16P)(TDMA_base+0x004)) // TDMA counter wrap
#define TDMA_TQWRAPI             ((volatile UINT16P)(TDMA_base+0x008)) // TDMA counter wrap
#define TDMA_EVT_VALID           ((volatile UINT16P)(TDMA_base+0x00C)) // TMDA VALID strobe timing


#elif defined(MT6252H) || defined(MT6252)
#define ACIF_CON0                ((volatile UINT32P)(CONFIG_base+0x700))   /* MISC IO driving control */
#define ACIF_CON1                ((volatile UINT32P)(CONFIG_base+0x704))   /* MISC IO driving control */
#define ACIF_CON2                ((volatile UINT32P)(CONFIG_base+0x708))   /* MISC IO driving control */
#define ACIF_CON3                ((volatile UINT32P)(CONFIG_base+0x70C))   /* MISC IO driving control */

#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define ARB_1T_EN                ((volatile UINT16P)(CONFIG_base+0x714))   /* Bus Arbitration 1T Enable */
#define LYR2_EMPTY_EN            ((volatile UINT16P)(CONFIG_base+0x030))   /* AHB Layer2 Hold Master Enable */
#define LYR2_EMPTY               ((volatile UINT16P)(CONFIG_base+0x034))   /* AHB Layer2 Hold Master Status */
#define EMI_CLK_SEL              ((volatile UINT32P)(CONFIG_base+0x120))   /* EMI clock switch register */
#define CLKSQ_CON0               ((volatile UINT16P)(PLL_CLKSQ_base+0x100))   /* Clock control */
#define CLKSQ_CON1               ((volatile UINT16P)(PLL_CLKSQ_base+0x104))   /* Clock control */
#define PLL_CON0                 ((volatile UINT16P)(PLL_CLKSQ_base+0x200))   /* PLL Freq control */
#define PLL_CON1                 ((volatile UINT16P)(PLL_CLKSQ_base+0x204))   /* PLL Freq control */
#define MPLL_CON1                ((volatile UINT16P)(PLL_CLKSQ_base+0x214))
#define UPLL_CON1                ((volatile UINT16P)(PLL_CLKSQ_base+0x20C))
#define SPLL_CON1                ((volatile UINT16P)(PLL_CLKSQ_base+0x234))
#define MPLL_TDMAWB01            ((volatile UINT16P)(PLL_CLKSQ_base+0x220))
#define MPLL_TDMAWB23            ((volatile UINT16P)(PLL_CLKSQ_base+0x224))
#define MPLL_TDMAWB45            ((volatile UINT16P)(PLL_CLKSQ_base+0x228))
#define TDMA_FHSTR0              ((volatile UINT16P)(TDMA_base+0x320)) 
#define TDMA_FHSTR1              ((volatile UINT16P)(TDMA_base+0x324)) 
#define TDMA_FHSTR2              ((volatile UINT16P)(TDMA_base+0x328)) 
#define TDMA_FHSTR3              ((volatile UINT16P)(TDMA_base+0x32C)) 
#define TDMA_FHSTR4              ((volatile UINT16P)(TDMA_base+0x330)) 
#define TDMA_FHSTR5              ((volatile UINT16P)(TDMA_base+0x334)) 
#define TDMA_TQWRAP              ((volatile UINT16P)(TDMA_base+0x004)) // TDMA counter wrap
#define TDMA_TQWRAPI             ((volatile UINT16P)(TDMA_base+0x008)) // TDMA counter wrap
#define TDMA_EVT_VALID           ((volatile UINT16P)(TDMA_base+0x00C)) // TMDA VALID strobe timing

#elif defined(MT6250)

#define CLKSQ_CON0               ((volatile UINT16P)(MIXED_base+0x20))   /* Clock control */
#define MPLL_CON1                ((volatile UINT16P)(MIXED_base+0x104))
#define UPLL_CON1                ((volatile UINT16P)(MIXED_base+0x144))
#define BOOT_CON                 ((volatile UINT16P)(BOOT_ENG_base +0x0000))

#elif defined(MT6260)

#define CLKSQ_CON0               ((volatile UINT16P)(MIXED_base+0x20))   /* Clock control */
#define MPLL_CON1                ((volatile UINT16P)(MIXED_base+0x104))
#define UPLL_CON1                ((volatile UINT16P)(MIXED_base+0x144))
#define BOOT_CON                 ((volatile UINT16P)(BOOT_ENG_base +0x0000))

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)

#define CLKSQ_CON0               ((volatile UINT16P)(MIXED_base+0x20))   /* Clock control */
#define MPLL_CON1                ((volatile UINT16P)(MIXED_base+0x104))
#define UPLL_CON1                ((volatile UINT16P)(MIXED_base+0x144))
#define BOOT_CON                 ((volatile UINT16P)(BOOT_ENG_base +0x0000))

#elif defined(MT6225) || defined(MT6223) || defined(MT6223P)

#define PLL                      ((volatile UINT16P)(CONFIG_base+0x100))   /* PLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x110))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */

#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)

#define PLL                      ((volatile UINT16P)(PLL_base+0x000))      /* PLL Freq control */
#define PLL2                     ((volatile UINT16P)(PLL_base+0x004))      /* PLL Freq control 2 */
#define CPLL                     ((volatile UINT16P)(PLL_base+0x008))      /* CPLL Freq control */
#define CPLL2                    ((volatile UINT16P)(PLL_base+0x00C))      /* CPLL Freq control 2 */
#define TPLL                     ((volatile UINT16P)(PLL_base+0x010))      /* TPLL Freq control */
#define TPLL2                    ((volatile UINT16P)(PLL_base+0x014))      /* TPLL Freq control 2 */
#define CLK_CON                  ((volatile UINT16P)(PLL_base+0x018))      /* Clock control */
#define PDN_CON                  ((volatile UINT16P)(PLL_base+0x01C))      /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define IDN_SEL                  ((volatile UINT16P)(CONFG_BASE+0x0200))   /* Internal Debug Select Register. */
#define RAMSCR_11_CON            ((volatile UINT16P)(CONFIG_base+0x0A2C))
#define RAMSCR_16_CON            ((volatile UINT16P)(CONFIG_base+0x0A40))
#define RAMSCR_17_CON            ((volatile UINT16P)(CONFIG_base+0x0A44))
#define PLL2_TPLL_PDN            0x0001

#elif defined(MT6268A)

#define PLL                      ((volatile UINT16P)(MIXED_base+0x000))    /* PLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(MIXED_base+0x014))    /* Clock control */
#define PDN_CON                  ((volatile UINT16P)(MIXED_base+0x010))    /* Power down control */
#define UPLL                     ((volatile UINT16P)(MIXED_base+0x030))     
#define MPLL                     ((volatile UINT16P)(MIXED_base+0x020)) 
#define DPLL                     ((volatile UINT16P)(MIXED_base+0x028)) 
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define MCUCLK_CON2              ((volatile UINT16P)(CONFIG_base+0x11C))   /* MCU Clock Control */
#define GCLOCK_CON               ((volatile UINT16P)(CONFIG_base+0x120))
#define PWR_CON                  ((volatile UINT16P)(CONFIG_base+0x130))
#define PWR_VIO                  ((volatile UINT16P)(CONFIG_base+0x134))
#define IDN_SEL                  ((volatile UINT16P)(CONFIG_base+0x200))

#elif defined(MT6268)

#define PLL                      ((volatile UINT16P)(MIXED_base+0x000))    /* PLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(MIXED_base+0x014))    /* Clock control */
#define PDN_CON                  ((volatile UINT16P)(MIXED_base+0x010))    /* Power down control */
#define UPLL                     ((volatile UINT16P)(MIXED_base+0x030))
#define MPLL                     ((volatile UINT16P)(MIXED_base+0x020))
#define DPLL                     ((volatile UINT16P)(MIXED_base+0x028))
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define MCUCLK_CON2              ((volatile UINT16P)(CONFIG_base+0x11C))   /* MCU Clock Control */
#define GCLOCK_CON               ((volatile UINT16P)(CONFIG_base+0x120))
#define CLK_INFO                 ((volatile UINT16P)(CONFIG_base+0x124))
#define PWR_CON                  ((volatile UINT16P)(CONFIG_base+0x130))
#define PWR_VIO                  ((volatile UINT16P)(CONFIG_base+0x134))
#define IDN_SEL                  ((volatile UINT16P)(CONFIG_base+0x200))

#elif defined(TK6516) || defined(MT6516)

#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x0204))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x0208))   /* MCU Clock Control */

#elif defined(MT6236) || defined(MT6236B)

#define PLL_CON0                 ((volatile UINT16P)(PLL_base+0x200))
#define PLL_CON1                 ((volatile UINT16P)(PLL_base+0x204))
#define UPLL_CON0                ((volatile UINT16P)(PLL_base+0x300))
#define UPLL_CON1                ((volatile UINT16P)(PLL_base+0x304))
#define MPLL_CON0                ((volatile UINT16P)(PLL_base+0x400))
#define MPLL_CON1                ((volatile UINT16P)(PLL_base+0x404))
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x200))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x204))   /* MCU Clock Control */
#define MCUCLK_CON2              ((volatile UINT16P)(CONFIG_base+0x208))   /* MCU Clock Control */
#define GCLOCK_CON               ((volatile UINT16P)(CONFIG_base+0x20C))
#define CLK_INFO                 ((volatile UINT16P)(CONFIG_base+0x218))
#define PWR_CON                  ((volatile UINT16P)(CONFIG_base+0x300))
#define GMC_MPU_CON              ((volatile UINT16P)(CONFIG_base+0x610))
#define MCUSYS_DELSEL0           ((volatile UINT32P)(CONFIG_base+0x730))

#elif defined(MT6270A)

#define PLL                      			       ((volatile UINT16P)(MIXED_Base+0x000))   			/* PLL Freq control */
#define CLK_CON                  			((volatile UINT16P)(MIXED_Base+0x014))   			/* Clock control */
#define PDN_CON                  			((volatile UINT16P)(MIXED_Base+0x010))   			/* Power down control */

#define PLL_CON0                                   ((volatile UINT16P)(MIXED_Base+0x0200))                  
#define PLL_CON1                                   ((volatile UINT16P)(MIXED_Base+0x0204))  

#define UPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0300)) 	
#define UPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0304)) 	
#define UPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0308)) 	
#define UPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x030C)) 	


#define MPLL_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0400)) 	
#define MPLL_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0404)) 	
#define MPLL_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0408)) 	
#define MPLL_CON3                                 ((volatile UINT16P)(MIXED_Base+0x040C)) 	

#define DDS_CON0                                 ((volatile UINT16P)(MIXED_Base+0x0500)) 
#define DDS_CON1                                 ((volatile UINT16P)(MIXED_Base+0x0504)) 
#define DDS_CON2                                 ((volatile UINT16P)(MIXED_Base+0x0508)) 
#define DDS_CON3                                 ((volatile UINT16P)(MIXED_Base+0x050C)) 

#define SIMLS_CON                               ((volatile UINT16P)(MIXED_Base+0x0C00)) 

#define SLEEP_CON                               ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON                            ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define MCUCLK_CON2                          ((volatile UINT16P)(CONFIG_base+0x11C))   /* MCU Clock Control */
#define GCLOCK_CON                            ((volatile UINT16P)(CONFIG_base+0x120))
#define CLK_INFO                                 ((volatile UINT16P)(CONFIG_base+0x124))
#define PWR_CON                                 ((volatile UINT16P)(CONFIG_base+0x130))
#define PWR_VIO                                  ((volatile UINT16P)(CONFIG_base+0x134))
#define IDN_SEL                                   ((volatile UINT16P)(CONFIG_base+0x200))

#elif defined(MT6256) || defined(MT6255)

#define PLL_CON1                  ((volatile UINT16P)(PLL_base+0x104))
#define PLL_CON2                  ((volatile UINT16P)(PLL_base+0x108))
#define PLL_CON3                  ((volatile UINT16P)(PLL_base+0x10C))
#define PLL_CON4                  ((volatile UINT16P)(PLL_base+0x110))
#define PLL_CON5                  ((volatile UINT16P)(PLL_base+0x114))
#define PLL_CON6                 ((volatile UINT16P)(PLL_base+0x118))
#define PLL_CON7                 ((volatile UINT16P)(PLL_base+0x11C))
#define PLL_CON8                 ((volatile UINT16P)(PLL_base+0x120))
#define UPLL_CON0                 ((volatile UINT16P)(PLL_base+0x200))
#define UPLL_CON1                 ((volatile UINT16P)(PLL_base+0x204))
#define UPLL_CON2                 ((volatile UINT16P)(PLL_base+0x208))
#define UPLL_CON3                 ((volatile UINT16P)(PLL_base+0x20C))
#define UPLL_CON4                 ((volatile UINT16P)(PLL_base+0x210))
#define MPLL_CON0                 ((volatile UINT16P)(PLL_base+0x300))
#define MPLL_CON1                 ((volatile UINT16P)(PLL_base+0x304))
#define MPLL_CON2                 ((volatile UINT16P)(PLL_base+0x308))
#define MPLL_CON3                 ((volatile UINT16P)(PLL_base+0x30C))
#define MPLL_CON4                 ((volatile UINT16P)(PLL_base+0x310))
#define MPLL_CON5                 ((volatile UINT16P)(PLL_base+0x314))
#define NPLL_CON1                 ((volatile UINT16P)(PLL_base+0x404))
#define NPLL_CON2                 ((volatile UINT16P)(PLL_base+0x408))
#define NPLL_CON3                 ((volatile UINT16P)(PLL_base+0x40C))
#define NPLL_CON4                 ((volatile UINT16P)(PLL_base+0x410))
#define NPLL_CON5                 ((volatile UINT16P)(PLL_base+0x414))
#define FPLL_CON1                 ((volatile UINT16P)(PLL_base+0x604))
#define FPLL_CON2                 ((volatile UINT16P)(PLL_base+0x608))
#define FPLL_CON3                 ((volatile UINT16P)(PLL_base+0x60C))
#define FPLL_CON4                 ((volatile UINT16P)(PLL_base+0x610))
#define FPLL_CON5                 ((volatile UINT16P)(PLL_base+0x614))
#define EPLL_CON0                 ((volatile UINT16P)(PLL_base+0x500))
#define EPLL_CON1                 ((volatile UINT16P)(PLL_base+0x504))
#define EPLL_CON2                 ((volatile UINT16P)(PLL_base+0x508))
#define EPLL_CON3                 ((volatile UINT16P)(PLL_base+0x50C))
#define EPLL_CON4                 ((volatile UINT16P)(PLL_base+0x510))
#define EPLL_CON5                 ((volatile UINT16P)(PLL_base+0x514))
#define TDMA_FHCON4               ((volatile UINT16P)(PLL_base+0x810))
#define TDMA_FHCON6               ((volatile UINT16P)(PLL_base+0x818))
#define PLL_MISC_CON              ((volatile UINT16P)(PLL_base+0xA30))
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x200))
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x204))
#define PWR_CON                  ((volatile UINT32P)(CONFIG_base+0x300))

#elif defined(MT6276)

#define PLL_CON0                ((volatile UINT16P)(MIX_ABB_base+0x100))
#define PLL_CON1                ((volatile UINT16P)(MIX_ABB_base+0x104))
#define PLL_CON2                ((volatile UINT16P)(MIX_ABB_base+0x108))
#define PLL_CON3                ((volatile UINT16P)(MIX_ABB_base+0x10C))
#define PLL_CON4                ((volatile UINT16P)(MIX_ABB_base+0x110))
#define PLL_CON5                ((volatile UINT16P)(MIX_ABB_base+0x114))
#define PLLCNTEN_CON            ((volatile UINT16P)(MIX_ABB_base+0x12C))
#define MPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x140))
#define MPLL_CON1               ((volatile UINT16P)(MIX_ABB_base+0x144))
#define MPLL_CON2               ((volatile UINT16P)(MIX_ABB_base+0x148))
#define MPLL_CON3               ((volatile UINT16P)(MIX_ABB_base+0x14C))
#define DPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x180))
#define DPLL_CON1               ((volatile UINT16P)(MIX_ABB_base+0x184))
#define DPLL_CON2               ((volatile UINT16P)(MIX_ABB_base+0x188))
#define DPLL_CON3               ((volatile UINT16P)(MIX_ABB_base+0x18C))
#define EPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x1C0))
#define EPLL_CON1               ((volatile UINT16P)(MIX_ABB_base+0x1C4))
#define EPLL_CON2               ((volatile UINT16P)(MIX_ABB_base+0x1C8))
#define EPLL_CON3               ((volatile UINT16P)(MIX_ABB_base+0x1CC))
#define CPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x200))
#define WPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x240))
#define GPLL_CON0               ((volatile UINT16P)(MIX_ABB_base+0x280))

#define PDN_CON                 ((volatile UINT16P)(MIXED_base+0x010))    /* Power down control */

#define ARM_FSEL                ((volatile UINT16P)(CONFIG_base+0x800))
#define DSP_FSEL                ((volatile UINT16P)(CONFIG_base+0x804))
#define EMI_FSEL                ((volatile UINT16P)(CONFIG_base+0x808))
#define FBUS_FSEL               ((volatile UINT16P)(CONFIG_base+0x80C))
#define SBUS_FSEL               ((volatile UINT16P)(CONFIG_base+0x810))
#define DSP_IDLE_FSEL           ((volatile UINT16P)(CONFIG_base+0x814))
#define EMI_IDLE_FSEL           ((volatile UINT16P)(CONFIG_base+0x818))
#define FBUS_IDLE_FSEL          ((volatile UINT16P)(CONFIG_base+0x81C))
#define SBUS_IDLE_FSEL          ((volatile UINT16P)(CONFIG_base+0x820))
#define RG_CK_ALW_ON            ((volatile UINT16P)(CONFIG_base+0x824))
#define RG_CK_DCM_EN            ((volatile UINT16P)(CONFIG_base+0x828))
#define RG_EMI_DBC              ((volatile UINT16P)(CONFIG_base+0x82C))
#define RG_BUS_DBC              ((volatile UINT16P)(CONFIG_base+0x830))

#elif defined(MT6573)

#define PLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x100))
#define PLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x104))
#define PLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x108))
#define PLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x10C))
#define PLL_CON4                  ((volatile UINT16P)(MIX_ABB_base+0x110))
#define PLL_CON5                  ((volatile UINT16P)(MIX_ABB_base+0x114))
#define MPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x140))
#define MPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x144))
#define MPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x148))
#define MPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x14C))
#define DPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x180))
#define DPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x184))
#define DPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x188))
#define DPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x18C))
#define EPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x1C0))
#define EPLL_CON1                  ((volatile UINT16P)(MIX_ABB_base+0x1C4))
#define EPLL_CON2                  ((volatile UINT16P)(MIX_ABB_base+0x1C8))
#define EPLL_CON3                  ((volatile UINT16P)(MIX_ABB_base+0x1CC))
#define CPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x200))
#define WPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x240))
#define GPLL_CON0                  ((volatile UINT16P)(MIX_ABB_base+0x280))

#define PDN_CON                    ((volatile UINT16P)(MIXED_base+0x010))    /* Power down control */

#define AP_ARM_FSEL             ((volatile UINT16P)(AP_CONFIG_base+0x100))
#define DSP_FSEL                ((volatile UINT16P)(AP_CONFIG_base+0x104))
#define EMI_FSEL                ((volatile UINT16P)(AP_CONFIG_base+0x108))
#define FBUS_FSEL               ((volatile UINT16P)(AP_CONFIG_base+0x10C))
#define SBUS_FSEL               ((volatile UINT16P)(AP_CONFIG_base+0x110))
#define DSP_IDLE_FSEL           ((volatile UINT16P)(AP_CONFIG_base+0x114))
#define EMI_IDLE_FSEL           ((volatile UINT16P)(AP_CONFIG_base+0x118))
#define FBUS_IDLE_FSEL          ((volatile UINT16P)(AP_CONFIG_base+0x11C))
#define SBUS_IDLE_FSEL          ((volatile UINT16P)(AP_CONFIG_base+0x120))
#define RG_CK_ALW_ON            ((volatile UINT16P)(AP_CONFIG_base+0x124))
#define RG_CK_DCM_EN            ((volatile UINT16P)(AP_CONFIG_base+0x128))
#define RG_EMI_DBC              ((volatile UINT16P)(AP_CONFIG_base+0x12C))
#define RG_BUS_DBC              ((volatile UINT16P)(AP_CONFIG_base+0x130))


#else

#define MPLL                    ((volatile UINT16P)(CONFIG_base+0x100))   /* PLL1 Freq control */
#define DPLL                    ((volatile UINT16P)(CONFIG_base+0x104))   /* PLL2 Freq control */
#define CLK_CON                 ((volatile UINT16P)(CONFIG_base+0x108))   /* Clock control */
#define SLEEP_CON               ((volatile UINT16P)(CONFIG_base+0x10C))   /* Clock control */

#if !defined(MT6208) && !defined(MT6205B)
#define UPLL                     ((volatile UINT16P)(CONFIG_base+0x110))   /* USB Freq control */
#endif /* !MT6208 && !MT6205B */

#if defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x114))   /* MCU Clock Control */
#endif   /* MT6217 || MT6226 || MT6227 || MT6226M  || defined(MT6227D) || defined(MT6226D)*/

#endif


/*******************************************************************************
 * Reset registers
 *******************************************************************************/
#define SW_RSTN                  ((volatile UINT16P)(CONFIG_base+0x0200))  /* Software reset register */
#define SW_DSP_RSTN              ((volatile UINT16P)(CONFIG_base+0x0204))  /* CPU to DSP reset register */


/*******************************************************************************
 * Software power-down control registers
 *******************************************************************************/
#if defined(TK6516)
#define PDN_CON1                 ((volatile UINT16P)(CONFIG_base+0x0304))  /* Power-down control 1 */
#define PDN_CON2                 ((volatile UINT16P)(CONFIG_base+0x0308))  /* Power-down control 2 */
#define PDN_CON4                 ((volatile UINT16P)(CONFIG_base+0x0310))  /* Power-down control 4 */
#define PDN_SET1                 ((volatile UINT16P)(CONFIG_base+0x0324))  /* Power-down set 1 */
#define PDN_SET2                 ((volatile UINT16P)(CONFIG_base+0x0328))  /* Power-down set 2 */
#define PDN_SET4                 ((volatile UINT16P)(CONFIG_base+0x0330))  /* Power-down set 4 */
#define PDN_CLR1                 ((volatile UINT16P)(CONFIG_base+0x0344))  /* Power-down clear 1 */
#define PDN_CLR2                 ((volatile UINT16P)(CONFIG_base+0x0348))  /* Power-down clear 2 */
#define PDN_CLR4                 ((volatile UINT16P)(CONFIG_base+0x0350))  /* Power-down clear 4 */
 
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
#define PDN_CON0                 ((volatile UINT16P)(CONFIG_base+0x0300))  /* Power-down control 1 */
#define PDN_CON1                 ((volatile UINT16P)(CONFIG_base+0x0304))  /* Power-down control 2 */
#define PDN_CON2                 ((volatile UINT16P)(CONFIG_base+0x0308))  /* Power-down control 3 */
#define PDN_CON3                 ((volatile UINT16P)(CONFIG_base+0x030C))  /* Power-down control 4 */
#define PDN_SET0                 ((volatile UINT16P)(CONFIG_base+0x0310))  /* Power-down set 1 */
#define PDN_SET1                 ((volatile UINT16P)(CONFIG_base+0x0314))  /* Power-down set 2 */
#define PDN_SET2                 ((volatile UINT16P)(CONFIG_base+0x0318))  /* Power-down set 3 */
#define PDN_SET3                 ((volatile UINT16P)(CONFIG_base+0x031C))  /* Power-down set 4 */
#define PDN_CLR0                 ((volatile UINT16P)(CONFIG_base+0x0320))  /* Power-down clear 1 */
#define PDN_CLR1                 ((volatile UINT16P)(CONFIG_base+0x0324))  /* Power-down clear 2 */
#define PDN_CLR2                 ((volatile UINT16P)(CONFIG_base+0x0328))  /* Power-down clear 3 */
#define PDN_CLR3                 ((volatile UINT16P)(CONFIG_base+0x032C))  /* Power-down clear 4 */


#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
#define PDN_CON0                 (MDMCUSYS_base+0x0000)
#define PDN_SET0                 (MDMCUSYS_base+0x0020)
#define PDN_CLR0                 (MDMCUSYS_base+0x0040)
#define PDN_CON1                 (MDMCUSYS_base+0x0100)
#define PDN_SET1                 (MDMCUSYS_base+0x0120)
#define PDN_CLR1                 (MDMCUSYS_base+0x0140)

#define PDN_CON0_TDMA            0x00000004

#elif defined(MT6236) || defined(MT6236B)

#define PDN_CON0                    ((volatile kal_uint16 *)(CONFIG_base+0x0700)) /* Power-down control 1 */
#define PDN_CON1                    ((volatile kal_uint16 *)(CONFIG_base+0x0704)) /* Power-down control 2 */
#define PDN_CON2                    ((volatile kal_uint16 *)(CONFIG_base+0x0708)) /* Power-down control 3 */
#define PDN_CON3                    ((volatile kal_uint16 *)(CONFIG_base+0x070C)) /* Power-down control 4 */
#define PDN_SET0                    ((volatile kal_uint16 *)(CONFIG_base+0x0710)) /* Power-down set 1 */
#define PDN_SET1                    ((volatile kal_uint16 *)(CONFIG_base+0x0714)) /* Power-down set 2 */
#define PDN_SET2                    ((volatile kal_uint16 *)(CONFIG_base+0x0718)) /* Power-down set 3 */
#define PDN_SET3                    ((volatile kal_uint16 *)(CONFIG_base+0x071C)) /* Power-down set 4 */
#define PDN_CLR0                    ((volatile kal_uint16 *)(CONFIG_base+0x0720)) /* Power-down clear 1 */
#define PDN_CLR1                    ((volatile kal_uint16 *)(CONFIG_base+0x0724)) /* Power-down clear 2 */
#define PDN_CLR2                    ((volatile kal_uint16 *)(CONFIG_base+0x0728)) /* Power-down clear 3 */
#define PDN_CLR3                    ((volatile kal_uint16 *)(CONFIG_base+0x072C)) /* Power-down clear 4 */

#else

#define PDN_CON0                 ((volatile UINT16P)(CONFIG_base+0x0300))  /* Power-down control 1 */
#define PDN_CON1                 ((volatile UINT16P)(CONFIG_base+0x0304))  /* Power-down control 2 */
#define PDN_CON2                 ((volatile UINT16P)(CONFIG_base+0x0308))  /* Power-down control 3 */
#define PDN_CON3                 ((volatile UINT16P)(CONFIG_base+0x030C))  /* Power-down control 4 */
#define PDN_SET0                 ((volatile UINT16P)(CONFIG_base+0x0310))  /* Power-down set 1 */
#define PDN_SET1                 ((volatile UINT16P)(CONFIG_base+0x0314))  /* Power-down set 2 */
#define PDN_SET2                 ((volatile UINT16P)(CONFIG_base+0x0318))  /* Power-down set 3 */
#define PDN_SET3                 ((volatile UINT16P)(CONFIG_base+0x031C))  /* Power-down set 4 */
#define PDN_CLR0                 ((volatile UINT16P)(CONFIG_base+0x0320))  /* Power-down clear 1 */
#define PDN_CLR1                 ((volatile UINT16P)(CONFIG_base+0x0324))  /* Power-down clear 2 */
#define PDN_CLR2                 ((volatile UINT16P)(CONFIG_base+0x0328))  /* Power-down clear 3 */
#define PDN_CLR3                 ((volatile UINT16P)(CONFIG_base+0x032C))  /* Power-down clear 4 */
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) || defined(MT6268T_SERIES_CONFIG)
#define PDN_CON4                 ((volatile UINT16P)(CONFIG_base+0x0330))  /* Power-down control 5 */
#define PDN_SET4                 ((volatile UINT16P)(CONFIG_base+0x0334))  /* Power-down set 5 */
#define PDN_CLR4                 ((volatile UINT16P)(CONFIG_base+0x0338))  /* Power-down clear 5 */
#endif /* MT6228 || MT6229 || MT6230 || MT6238 || MT6239 || MT6268T_SERIES_CONFIG */

#endif /* TK6516 */

/*******************************************************************************
 * MISC.
 *******************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T_SERIES_CONFIG)

#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0400))  /* APB bus crontrol */
#define SLOWDN_CON               ((volatile UINT16P)(CONFIG_base+0x0404))  /* Slow down control register */
#define AHB_CON                  ((volatile UINT16P)(CONFIG_base+0x0500))  /* AHB bus crontrol */
#define SYSRAM_CON               ((volatile UINT16P)(CONFIG_base+0x0600))  /* SYSRAM control */
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0700))  /* Analog chip interface control 0 */
#define ACIF_CON2                ((volatile UINT16P)(CONFIG_base+0x0708))  /* Analog chip interface control 2 */
#define WAVE_SD_CON              ((volatile UINT16P)(CONFIG_base+0x0800))  /* Wave table slow down control */
#define ROM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0900))  /* MCU ROM setting control */
#define RAM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0a00))  /* MCU RAM setting control */
#define EFUSE_CON                ((volatile UINT16P)(CONFIG_base+0xf000))  /* eFuse control */
#define CHIPID1                  ((volatile UINT16P)(CONFIG_base+0xf010))  /* Chip ID register 1 */
#define CHIPID2                  ((volatile UINT16P)(CONFIG_base+0xf014))  /* Chip ID register 2 */
#define CHIPID3                  ((volatile UINT16P)(CONFIG_base+0xf018))  /* Chip ID register 3 */
#define CHIPID4                  ((volatile UINT16P)(CONFIG_base+0xf01c))  /* Chip ID register 4 */

#if defined(MT6268T_SERIES_CONFIG)
#define ACIF_CON3                ((volatile UINT16P)(CONFIG_base+0x070C))  /* Analog chip interface control 3 */
#define ACIF_CON4                ((volatile UINT16P)(CONFIG_base+0x0710))  /* Analog chip interface control 4 */
#define ACIF_CON5                ((volatile UINT16P)(CONFIG_base+0x0714))  /* Analog chip interface control 5 */
#endif /* MT6268T_SERIES_CONFIG */


#elif defined(MT6253)

#define CHIPID3                 ((volatile UINT32P)(EFUSE_base+0xf018))  /* Chip ID register 3 */

#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)  /* MT6228 || MT6229 || MT6230 || MT6268T_SERIES_CONFIG */

#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0404))  /* APB bus crontrol */
#define SLOWDN_CON               ((volatile UINT16P)(CONFIG_base+0x0408))  /* Slow down control register */
#define AHB_CON                  ((volatile UINT16P)(CONFIG_base+0x0500))  /* AHB bus crontrol */
#define SYSRAM_CON               ((volatile UINT16P)(CONFIG_base+0x0600))  /* SYSRAM control */
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0700))  /* Analog chip interface control 0 */
#define ACIF_CON1                ((volatile UINT16P)(CONFIG_base+0x0704))  /* Analog chip interface control 1 */
#define ACIF_CON2                ((volatile UINT16P)(CONFIG_base+0x0708))  /* Analog chip interface control 2 */
#define WAVE_SD_CON              ((volatile UINT16P)(CONFIG_base+0x0800))  /* Wave table slow down control */
#define ROM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0900))  /* MCU ROM setting control */
#define RAM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0a00))  /* MCU RAM setting control */
#define EFUSE_CON                ((volatile UINT32P)(0x80000000))          /* eFuse control */
#define CHIPID1                  ((volatile UINT32P)(EFUSE_CON+0x0010))    /* Chip ID register 1 */
#define CHIPID2                  ((volatile UINT32P)(EFUSE_CON+0x0014))    /* Chip ID register 2 */
#define CHIPID3                  ((volatile UINT32P)(EFUSE_CON+0x0018))    /* Chip ID register 3 */
#define CHIPID4                  ((volatile UINT32P)(EFUSE_CON+0x001c))    /* Chip ID register 4 */

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T_SERIES_CONFIG */

#if defined(MT6226M)
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0704))  /* Analog chip interface control 0 */
#endif  /* MT6226M */

#if !defined(MT6208) && !defined(MT6205B) && !defined(MT6252H) && !defined(MT6252) && !defined(MT6250) && !defined(MT6260) && !defined(MT6261) && !defined(MT2501) && !defined(MT2502)
#define ACIF_CON1                ((volatile UINT16P)(CONFIG_base+0x0704))  /* Analog Chip Interface Control Register 1 */
#endif   /* !MT6208 && !MT6205B */

#if defined(MT6225) || defined(MT6253T) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0404))  /* APB bus crontrol */
#define SYSRAM_CON               ((volatile UINT16P)(CONFIG_base+0x0600))  /* SYSRAM control */
#endif  /* MT6225 || MT6253T || MT6253 || MT6251 || MT6253E || MT6253L */


#if defined(MT6223) || defined(MT6223P)
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0700))  /* Analog chip interface control 0 */
#endif /* MT6223 || MT6223P */

#if defined(TK6516) || defined(MT6516)
#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0404))  /* APB bus crontrol */
#endif

/*************************************************************************
 * Define HW register
 *************************************************************************/

/* analog */
#if !defined(MT6208) && !defined(MT6205B)
#if !defined(AC_ODS_CON)
#define AC_ODS_CON               ((volatile UINT16P)(MIXED_base + 0x0000))
#endif  /* !AC_ODS_CON */

#if !defined(ANALOG_HW_VERSION)
#define ANALOG_HW_VERSION        ((volatile UINT16P)(MIXED_base + 0x0004))
#endif  /* !ANALOG_HW_VERSION */

#if !defined(ANALOG_HW_CODE)
#define ANALOG_HW_CODE           ((volatile UINT16P)(MIXED_base + 0x0008))
#endif  /* !ANALOG_HW_CODE */

#endif /* !MT6208 && !MT6205B */

/* boot mode control register */
#if defined(MT6225)
//#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120000)
// Change BOOT_CONFIG from GPIO_DIR1 to LCD_PCNF0 in case USB BootLoader involved
// applied since 07BW0748MP~
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x9000001A)
#elif defined(MT6208) || defined(MT6205B)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120004)
#elif defined(MT6218B) || defined(MT6217) || defined(MT6219) || defined(MT6268T) || defined(MT6268H)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
#elif defined(MT6226) || defined(MT6227) || defined(MT6226M) 
//#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
// Change BOOT_CONFIG from GPIO_DIR2 to LCD_PCNF0 in case USB BootLoader involved
// applied since 07BW0748MP~
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x9000001A)
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
#elif ( defined(MT6227D)  || defined(MT6226D))
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80000010)
#elif defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x800200C0)
#else /* New chip will have SW_MISC_L, plesae do not specify specific address */
#define BOOT_CONFIG_ADDR         SW_MISC_L
#endif



#endif  /* !__CONFIG_HW_H__ */

