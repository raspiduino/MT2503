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
 *    pdn_hw_mt6260_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PDN HW registers for MT6252 series chips.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6261_SERIES_H__
#define __PDN_HW_MT6261_SERIES_H__

/******************************************************************************************************************************/
/* #define CONFIG_base                 (0xA0010000) /\*Configuration Registers(Clock, Power Down, Version and Reset)      *\/ */
/******************************************************************************************************************************/
#define DRVPDN_MCUSYS_PDN_CON0      (CONFIG_base+0x0300)
#define DRVPDN_MCUSYS_PDN_CON1      (CONFIG_base+0x0304)
#define DRVPDN_MCUSYS_PDN_CON2      (CONFIG_base+0x0308)

#define DRVPDN_MCUSYS_PDN_CON0_SET  (CONFIG_base+0x0310)
#define DRVPDN_MCUSYS_PDN_CON1_SET  (CONFIG_base+0x0314)
#define DRVPDN_MCUSYS_PDN_CON2_SET  (CONFIG_base+0x0318)

#define DRVPDN_MCUSYS_PDN_CON0_CLR  (CONFIG_base+0x0320)
#define DRVPDN_MCUSYS_PDN_CON1_CLR  (CONFIG_base+0x0324)
#define DRVPDN_MCUSYS_PDN_CON2_CLR  (CONFIG_base+0x0328)

#define DRVPDN_CON0_SW_LCD          0x0001
#define DRVPDN_CON0_SW_RESIZER      0x0002
#define DRVPDN_CON0_SW_ROTDMA       0x0004
#define DRVPDN_CON0_SW_CAM_BCLK     0x0008
#define DRVPDN_CON0_SW_PAD2CAM      0x0010
#define DRVPDN_CON0_SW_G2D          0x0020
#define DRVPDN_CON0_SW_MM_COLOR     0x0040
#define DRVPDN_CON0_SW_SLCD         0x0080
#define DRVPDN_CON0_SW_MD2G_26M     0x0100
#define DRVPDN_CON0_SW_BT_26M       0x0200
#define DRVPDN_CON0_SW_CAM_48M      0x0400
#define DRVPDN_CON0_DMA2SFC         0x0800
#define DRVPDN_CON0_2GDMA2SFC       0x1000
#define DRVPDN_CON0_SW_BT_BUS       0x2000
#define DRVPDN_CON0_BT_ARM7         0x8000

#define DRVPDN_CON1_SEJ		          0x0001
#define DRVPDN_CON1_DMA		          0x0002
#define DRVPDN_CON1_USB		          0x0004
#define DRVPDN_CON1_MSDC            0x0008
#define DRVPDN_CON1_SIM		          0x0010
#define DRVPDN_CON1_SIM2	          0x0020
#define DRVPDN_CON1_I2C             0x0040
#define DRVPDN_CON1_SPI             0x0080
#define DRVPDN_CON1_OSTIMER         0x0100
#define DRVPDN_CON1_SLCD_EMI_IDLE       0x200
#define DRVPDN_CON1_SPISLV	          0x1000
#define DRVPDN_CON1_UART1	          0x2000
#define DRVPDN_CON1_UART2	          0x4000
#define DRVPDN_CON1_UART3	          0x8000

#define DRVPDN_CON2_PWM          0x0001 /*spec : PWM1*/
#define DRVPDN_CON2_PWM1          0x0001 /*spec : PWM1, alias pf PWM */
#define DRVPDN_CON2_BTIF         0x0002
#define DRVPDN_CON2_GPT          0x0004
#define DRVPDN_CON2_I2C_18V      0x0008
#define DRVPDN_CON2_PWM4          0x0010 /*spec : PWM2, rename to PWM4 */
//#define DRVPDN_CON2_LZMA         0x0010
#define DRVPDN_CON2_ROM          0x0020
#define DRVPDN_CON2_EFUSE        0x0040
#define DRVPDN_CON2_SW_LPM       0x0080
#define DRVPDN_CON2_SFC_DCM_PROT1           0x0100
#define DRVPDN_CON2_SFC_DCM_PROT0           0x0200
//#define DRVPDN_CON2_NFI          0x0200
#define DRVPDN_CON2_MSDC2        0x0400
#define DRVPDN_CON2_SFC          0x0800
//#define DRVPDN_CON2_SPI_NAND     0x1000
#define DRVPDN_CON2_FM_F26M      0x2000
#define DRVPDN_CON2_FM_BCLK      0x4000


/* MD2GSYS */
/*******************************************************************/
/* #define MD2GCONFG_base              (0x82C00000) /\*MD2GSYS *\/ */
/*******************************************************************/
#define DRVPDN_MD2GSYS_CG_CON0          (MD2GCONFG_base+0x0000)
#define DRVPDN_MD2GSYS_CG_CON2          (MD2GCONFG_base+0x0008)
#define DRVPDN_MD2GSYS_CG_CON4          (MD2GCONFG_base+0x0030)

#define DRVPDN_MD2GSYS_CG_CON0_SET          (MD2GCONFG_base+0x0010)
#define DRVPDN_MD2GSYS_CG_CON2_SET          (MD2GCONFG_base+0x0018)
#define DRVPDN_MD2GSYS_CG_CON4_SET          (MD2GCONFG_base+0x0034)

#define DRVPDN_MD2GSYS_CG_CON0_CLR          (MD2GCONFG_base+0x0020)
#define DRVPDN_MD2GSYS_CG_CON2_CLR          (MD2GCONFG_base+0x0028)
#define DRVPDN_MD2GSYS_CG_CON4_CLR          (MD2GCONFG_base+0x0038)

#define MD2GSYS_CG_CON0_GCC        0x0002
#define MD2GSYS_CG_CON0_IRDMA      0x0040
#define MD2GSYS_CG_CON0_RXBUF      0x0100
#define MD2GSYS_CG_CON0_TXBUF      0x0200
#define MD2GSYS_CG_CON0_IRDBG      0x2000
#define MD2GSYS_CG_CON0_AHB2DSPIO  0x8000

#define MD2GSYS_CG_CON2_APC_PRE    0x0020
#define MD2GSYS_CG_CON2_VAFE       0x0100
#define MD2GSYS_CG_CON2_BFE        0x0200

#define MD2GSYS_CG_CON4_APC        0x0020
#define MD2GSYS_CG_CON4_VAFE       0x0100
#define MD2GSYS_CG_CON4_BFE        0x0200

/* MODEMSYS */
/*************************************************************************/
/* #define MDCONFIG_base               (0x83000000) /\*MODEMSYS_PERI *\/ */
/*************************************************************************/

#define DRVPDN_MODEMSYS_CG_CON2          (MDCONFIG_base+0x0008)
#define DRVPDN_MODEMSYS_CG_CON4          (MDCONFIG_base+0x0088)

#define DRVPDN_MODEMSYS_CG_SET2          (MDCONFIG_base+0x0028)
#define DRVPDN_MODEMSYS_CG_SET4          (MDCONFIG_base+0x00A8)

#define DRVPDN_MODEMSYS_CG_CLR2          (MDCONFIG_base+0x0018)
#define DRVPDN_MODEMSYS_CG_CLR4          (MDCONFIG_base+0x0098)

#define MODEMSYS_CG_CON2_TDMA     0x0001
#define MODEMSYS_CG_CON2_BSI_T    0x0004
#define MODEMSYS_CG_CON2_BPI_T    0x0008
#define MODEMSYS_CG_CON2_DIV      0x0800
#define MODEMSYS_CG_CON2_FCS      0x1000
#define MODEMSYS_CG_CON2_GCU      0x2000

#define MODEMSYS_CG_CON4_BSI      0x0004
#define MODEMSYS_CG_CON4_BPI      0x0008

/* A-Die */
/****************************************************************************************************************************/
/* #define ANA_CFGSYS_base             (0xA0730000) /\*Analog die (MT6100) Configuration Registers (Clock, Reset, etc.) *\/ */
/****************************************************************************************************************************/

#define DRVPDN_ACFG_CLK_CON0            (ANA_CFGSYS_base+0x0008)

#define DRVPDN_ACFG_CLK_SET0            (ANA_CFGSYS_base+0x000C)

#define DRVPDN_ACFG_CLK_CLR0            (ANA_CFGSYS_base+0x0010)

#define DRVPDN_ACFG_CON0_PWM3            0x0001 /*spec : PWM3*/
#define DRVPDN_ACFG_CON0_PWM2            0x0002 /*spec : PWM2*/
#define DRVPDN_ACFG_CON0_AUXADC_BCLK     0x0004 
#define DRVPDN_ACFG_CON0_TP_BCLK         0x0008 
#define DRVPDN_ACFG_CON0_PMU_F26M        0x0010

/* MMSYS */

#define DRVPDN_MMSYS_CG_CON          DRVPDN_MCUSYS_PDN_CON0

#define DRVPDN_MMSYS_CG_SET          DRVPDN_MCUSYS_PDN_CON0_SET

#define DRVPDN_MMSYS_CG_CLR          DRVPDN_MCUSYS_PDN_CON0_CLR

#define MMSYS_CG_CON_G2D         DRVPDN_CON0_SW_G2D
#define MMSYS_CG_CON_LCD         DRVPDN_CON0_SW_LCD
#define MMSYS_CG_CON_MM_COLOR    DRVPDN_CON0_SW_MM_COLOR


#endif  /* !__PDN_HW_MT6260_SERIES_H__ */

