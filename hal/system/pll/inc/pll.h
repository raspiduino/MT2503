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
 *   init.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _PLL_H
#define _PLL_H

#include "kal_general_types.h"

/*************************************************************************
 * Define data structure
 *************************************************************************/

/* MCU clock */
typedef enum mcu_clock_enum_t {
   MCU_13MHZ = 0x0000,
   MCU_15_36MHZ = 0x0000,
   MCU_20_3125MHZ = 0x0000,
   MCU_26MHZ = 0x0001,
   MCU_30_72MHZ = 0x0001,
   MCU_39MHZ = 0x0002,
   MCU_52MHZ = 0x0003,
   MCU_61_44MHZ = 0x0003,
   MCU_65MHZ = 0x0004,
   MCU_78MHZ = 0x0005,
   MCU_91MHZ = 0x0006,
   MCU_104MHZ = 0x0007,
   MCU_122_88MHZ = 0x0007,
   MCU_208MHZ = 0x0008,
   MCU_245_76MHZ = 0x0009,
   MCU_152MHZ = 0x000A,
   MCU_312MHZ = 0x000B,
   MCU_520MHZ = 0x000C,   
   MCU_650MHZ = 0x000D,
   MCU_416MHZ = 0x000E,
   MCU_260MHZ = 0x000F,
   MCU_364MHZ = 0x0010,

   SSC_NORMAL = 0xFFF0,
   SSC_IDLE = 0xFFF1,
   SSC_MCU_LOW_SPEED1 = 0xFFF2,
   SSC_DSP_LOW_SPEED1 = 0xFFF3,
   SSC_BUS_LOW_SPEED1 = 0xFFF4,
   SSC_EMI_LOW_SPEED1 = 0xFFF5,
   SSC_COMBINATION = 0xFFF6,
   SSC_MCU_LOW_SPEED2 = 0xFFF7,
   SSC_EMI_NON_EPLL = 0xFFF8,
   SSC_EMI_EPLL = 0xFFF9,
} mcu_clock_enum;

/* PLL initialization mode */
typedef enum {
    PLL_MODE_MAUI,
    PLL_MODE_USB_META
} pll_init_mode;


/*************************************************************************
 * Define HW register
 *************************************************************************/
#if defined(MT6250)

#define PLL_CLKSQ_CON0    ((volatile kal_uint16*)(MIXED_base+0x0020))

#define PLL_PLL_CON2      ((volatile kal_uint16*)(MIXED_base+0x0048))
#define PLL_PLL_CON3      ((volatile kal_uint16*)(MIXED_base+0x004C))
#define PLL_PLL_CON4      ((volatile kal_uint16*)(MIXED_base+0x0050))
#define PLL_PLL_CON6      ((volatile kal_uint16*)(MIXED_base+0x0058))
#define PLL_PLL_CON7      ((volatile kal_uint16*)(MIXED_base+0x005C))

#define PLL_CLKSW_FDIV0   ((volatile kal_uint16*)(MIXED_base+0x0070))
#define PLL_CLKSW_FDIV1   ((volatile kal_uint16*)(MIXED_base+0x0074))
#define PLL_CLKSW_FDIV2   ((volatile kal_uint16*)(MIXED_base+0x0078))
#define PLL_CLKSW_FDIV3   ((volatile kal_uint16*)(MIXED_base+0x007C))
#define PLL_CLKSW_FDIV4   ((volatile kal_uint16*)(MIXED_base+0x0080))
#define PLL_CLKSW_FDIV5   ((volatile kal_uint16*)(MIXED_base+0x0084))

#define PLL_DPM_CON0      ((volatile kal_uint16*)(MIXED_base+0x0090))
#define PLL_DPM_CON1      ((volatile kal_uint16*)(MIXED_base+0x0094))

#define PLL_MPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0100))
#define PLL_MPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0104))
#define PLL_MPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0108))
#define PLL_MPLL_CON3     ((volatile kal_uint16*)(MIXED_base+0x010C))

#define PLL_UPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0140))
#define PLL_UPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0144))
#define PLL_UPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0148))
#define PLL_UPLL_CON3     ((volatile kal_uint16*)(MIXED_base+0x014C))

#define PLL_MDDS_CON0     ((volatile kal_uint16*)(MIXED_base+0x0640))
#define PLL_MDDS_CON1     ((volatile kal_uint16*)(MIXED_base+0x0644))
#define PLL_MDDS_CON2     ((volatile kal_uint16*)(MIXED_base+0x0648))

#define PLL_PLLTD_CON0    ((volatile kal_uint16*)(MIXED_base+0x0700))
#define PLL_PLLTD_CON1    ((volatile kal_uint16*)(MIXED_base+0x0704))
#define PLL_PLLTD_CON2    ((volatile kal_uint16*)(MIXED_base+0x0708))
#define PLL_PLLTD_CON3    ((volatile kal_uint16*)(MIXED_base+0x070C))
#define PLL_PLLTD_CON4    ((volatile kal_uint16*)(MIXED_base+0x0710))
#define PLL_PLLTD_CON5    ((volatile kal_uint16*)(MIXED_base+0x0714))
#define PLL_PLLTD_CON6    ((volatile kal_uint16*)(MIXED_base+0x0718))
#define PLL_PLLTD_CON7    ((volatile kal_uint16*)(MIXED_base+0x071C))

#define PLL_CLK_CONDA     ((volatile kal_uint32*)(CONFIG_base+0x0100))
#define PLL_CLK_CONDB     ((volatile kal_uint32*)(CONFIG_base+0x0104))
#define PLL_CLK_CONDC     ((volatile kal_uint32*)(CONFIG_base+0x0108))
#define PLL_CLK_CONDD     ((volatile kal_uint32*)(CONFIG_base+0x010C))
#define PLL_CLK_CONDE     ((volatile kal_uint32*)(CONFIG_base+0x0110))
#define PLL_CLK_CONDF     ((volatile kal_uint32*)(CONFIG_base+0x0114))
#define PLL_CLK_CONDG     ((volatile kal_uint32*)(CONFIG_base+0x0118))
#define PLL_CLK_CONDH     ((volatile kal_uint32*)(CONFIG_base+0x011C))

#define PLL_FH_CON0       ((volatile kal_uint32*)(MIXED_base+0x0500))
#define PLL_FH_CON1       ((volatile kal_uint32*)(MIXED_base+0x0504))
#define PLL_FH_CON2       ((volatile kal_uint32*)(MIXED_base+0x0508))
#define PLL_FH_CON3       ((volatile kal_uint32*)(MIXED_base+0x050C))
#define PLL_FH_CON4       ((volatile kal_uint32*)(MIXED_base+0x0510))

#endif //#if defined(MT6250)


#if defined(MT6260)

#define PLL_CLKSQ_CON0    ((volatile kal_uint16*)(MIXED_base+0x0020))

#define PLL_PLL_CON2      ((volatile kal_uint16*)(MIXED_base+0x0048))
#define PLL_PLL_CON3      ((volatile kal_uint16*)(MIXED_base+0x004C))
#define PLL_PLL_CON4      ((volatile kal_uint16*)(MIXED_base+0x0050))
#define PLL_PLL_CON6      ((volatile kal_uint16*)(MIXED_base+0x0058))
#define PLL_PLL_CON7      ((volatile kal_uint16*)(MIXED_base+0x005C))

#define PLL_DPM_CON0      ((volatile kal_uint16*)(MIXED_base+0x0090))
#define PLL_DPM_CON1      ((volatile kal_uint16*)(MIXED_base+0x0094))

#define PLL_MPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0100))
#define PLL_MPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0104))
#define PLL_MPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0108))

#define PLL_UPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0140))
#define PLL_UPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0144))
#define PLL_UPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0148))

#define PLL_EPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0180))
#define PLL_EPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0184))
#define PLL_EPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0188))

#define PLL_MDDS_CON0     ((volatile kal_uint16*)(MIXED_base+0x0640))
#define PLL_MDDS_CON1     ((volatile kal_uint16*)(MIXED_base+0x0644))
#define PLL_MDDS_CON2     ((volatile kal_uint16*)(MIXED_base+0x0648))

#define PLL_EDDS_CON0     ((volatile kal_uint16*)(MIXED_base+0x0680))
#define PLL_EDDS_CON1     ((volatile kal_uint16*)(MIXED_base+0x0684))
#define PLL_EDDS_CON2     ((volatile kal_uint16*)(MIXED_base+0x0688))

#define PLL_PLLTD_CON0    ((volatile kal_uint16*)(MIXED_base+0x0700))
#define PLL_PLLTD_CON1    ((volatile kal_uint16*)(MIXED_base+0x0704))
#define PLL_PLLTD_CON2    ((volatile kal_uint16*)(MIXED_base+0x0708))
#define PLL_PLLTD_CON3    ((volatile kal_uint16*)(MIXED_base+0x070C))
#define PLL_PLLTD_CON4    ((volatile kal_uint16*)(MIXED_base+0x0710))
#define PLL_PLLTD_CON5    ((volatile kal_uint16*)(MIXED_base+0x0714))
#define PLL_PLLTD_CON6    ((volatile kal_uint16*)(MIXED_base+0x0718))
#define PLL_PLLTD_CON7    ((volatile kal_uint16*)(MIXED_base+0x071C))

#define PLL_CLK_CONDA     ((volatile kal_uint32*)(CONFIG_base+0x0100))
#define PLL_CLK_CONDB     ((volatile kal_uint32*)(CONFIG_base+0x0104))
#define PLL_CLK_CONDC     ((volatile kal_uint32*)(CONFIG_base+0x0108))
#define PLL_CLK_CONDD     ((volatile kal_uint32*)(CONFIG_base+0x010C))
#define PLL_CLK_CONDE     ((volatile kal_uint32*)(CONFIG_base+0x0110))
#define PLL_CLK_CONDF     ((volatile kal_uint32*)(CONFIG_base+0x0114))
#define PLL_CLK_CONDG     ((volatile kal_uint32*)(CONFIG_base+0x0118))
#define PLL_CLK_CONDH     ((volatile kal_uint32*)(CONFIG_base+0x011C))

#define PLL_FH_CON0       ((volatile kal_uint32*)(MIXED_base+0x0500))
#define PLL_FH_CON1       ((volatile kal_uint32*)(MIXED_base+0x0504))
#define PLL_FH_CON2       ((volatile kal_uint32*)(MIXED_base+0x0508))
#define PLL_FH_CON3       ((volatile kal_uint32*)(MIXED_base+0x050C))
#define PLL_FH_CON4       ((volatile kal_uint32*)(MIXED_base+0x0510))

#endif //#if defined (MT6260)

#if defined(MT6261) || defined(MT2502) || defined(MT2501)

#define PLL_CLKSQ_CON0    ((volatile kal_uint16*)(MIXED_base+0x0020))

#define PLL_PLL_CON4      ((volatile kal_uint16*)(MIXED_base+0x0050))
#define PLL_PLL_CON6      ((volatile kal_uint16*)(MIXED_base+0x0058))
#define PLL_PLL_CON7      ((volatile kal_uint16*)(MIXED_base+0x005C))

#define PLL_MPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0100))
#define PLL_MPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0104))
#define PLL_MPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0108))

#define PLL_UPLL_CON0     ((volatile kal_uint16*)(MIXED_base+0x0140))
#define PLL_UPLL_CON1     ((volatile kal_uint16*)(MIXED_base+0x0144))
#define PLL_UPLL_CON2     ((volatile kal_uint16*)(MIXED_base+0x0148))

#define PLL_MDDS_CON0     ((volatile kal_uint16*)(MIXED_base+0x0640))
#define PLL_MDDS_CON1     ((volatile kal_uint16*)(MIXED_base+0x0644))
#define PLL_MDDS_CON2     ((volatile kal_uint16*)(MIXED_base+0x0648))

#define PLL_PLL_CON2      ((volatile kal_uint16*)(MIXED_base+0x0048))
#define PLL_PLL_CON3      ((volatile kal_uint16*)(MIXED_base+0x004C))

#define PLL_DPM_CON0      ((volatile kal_uint16*)(MIXED_base+0x0090))
#define PLL_DPM_CON1      ((volatile kal_uint16*)(MIXED_base+0x0094))
#define PLL_DPM_CON2      ((volatile kal_uint16*)(MIXED_base+0x0098))

#define PLL_PLLTD_CON0    ((volatile kal_uint16*)(MIXED_base+0x0700))
#define PLL_PLLTD_CON1    ((volatile kal_uint16*)(MIXED_base+0x0704))
#define PLL_PLLTD_CON2    ((volatile kal_uint16*)(MIXED_base+0x0708))
#define PLL_PLLTD_CON3    ((volatile kal_uint16*)(MIXED_base+0x070C))
#define PLL_PLLTD_CON4    ((volatile kal_uint16*)(MIXED_base+0x0710))
#define PLL_PLLTD_CON5    ((volatile kal_uint16*)(MIXED_base+0x0714))
#define PLL_PLLTD_CON6    ((volatile kal_uint16*)(MIXED_base+0x0718))
#define PLL_PLLTD_CON7    ((volatile kal_uint16*)(MIXED_base+0x071C))

#define PLL_CLK_CONDA     ((volatile kal_uint32*)(CONFIG_base+0x0100))
#define PLL_CLK_CONDB     ((volatile kal_uint32*)(CONFIG_base+0x0104))
#define PLL_CLK_CONDC     ((volatile kal_uint32*)(CONFIG_base+0x0108))
#define PLL_CLK_CONDD     ((volatile kal_uint32*)(CONFIG_base+0x010C))
#define PLL_CLK_CONDE     ((volatile kal_uint32*)(CONFIG_base+0x0110))
#define PLL_CLK_CONDF     ((volatile kal_uint32*)(CONFIG_base+0x0114))
#define PLL_CLK_CONDG     ((volatile kal_uint32*)(CONFIG_base+0x0118))
#define PLL_CLK_CONDH     ((volatile kal_uint32*)(CONFIG_base+0x011C))

#define PLL_FH_CON0       ((volatile kal_uint32*)(MIXED_base+0x0500))
#define PLL_FH_CON1       ((volatile kal_uint32*)(MIXED_base+0x0504))
#define PLL_FH_CON2       ((volatile kal_uint32*)(MIXED_base+0x0508))
#define PLL_FH_CON3       ((volatile kal_uint32*)(MIXED_base+0x050C))
#define PLL_FH_CON4       ((volatile kal_uint32*)(MIXED_base+0x0510))

#endif //#if defined(MT6261) || defined(MT2502) || defined(MT2501)

 
/*************************************************************************
 * Define import function prototype
 *************************************************************************/


/*************************************************************************
 * Define customized function prototype
 *************************************************************************/
void INT_SetPLL(pll_init_mode mode);


/*************************************************************************
  * Define macros.
 *************************************************************************/
 #define PLL_SWITCH_STACK_SIZE (512)


#endif  /* !_PLL_H */

