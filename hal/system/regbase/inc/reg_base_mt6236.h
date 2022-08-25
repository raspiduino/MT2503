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
 *   reg_base_mt6236.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for chipset register base and global configuration registers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_MT6236_H__
#define __REG_BASE_MT6236_H__

#define CONFIG_base            	 (0x80000000)
#define EMI_base                 (0x80010000)
#define CIRQ_base                (0x80020000)
#define DMA_base                 (0x80030000)
#define UART1_base               (0x80040000)
#define UART2_base               (0x80050000)
#define UART3_base               (0x80060000)
#define GPT_base                 (0x80070000)
#define KP_base                  (0x80080000)
#define PWM_base                 (0x80090000)
#define SIM_base                 (0x800A0000)
#define ARM9_BTIF_base           (0x800B0000)
#define RTC_base                 (0x800C0000)
#define IRDA_base                (0x800D0000)
#define I2C_base                 (0x800E0000)
#define MSDC_base                (0x800F0000)
#define MSDC2_base               (0x80100000)
#define NFI_base                 (0x80110000)
#define SIM2_base                (0x80120000)
#define SEJ_base                 (0x80140000)
#define TDMA_base                (0x80150000)
#define AFC_base                 (0x80160000)
#define AUXADC_base              (0x80170000)
#define SHAREG1_base             (0x80180000)
#define SHAREG2_base             (0x80190000)
#define PLL_base                 (0x801A0000)
#define MIXED_base               (0x801B0000)
#define EFUSE_base             	 (0x801C0000)
#define GPIO_base                (0x801D0000)
#define RGU_base                 (0x801E0000)
#define ACCDET_base              (0x801F0000)
#define MD2GCONFG_base           (0x81000000)
#define BSI_base                 (0x81010000)
#define BPI_base                 (0x81020000)
#define APC_base                 (0x81030000)
#define DIVIDER_base             (0x81040000)
#define FCS_base                 (0x81050000)
#define GCU_base                 (0x81060000)
#define CSD_ACC_base           	 (0x81070000)
#define SHARE1_base              (0x81080000)
#define IRDBG1_base              (0x81090000)
#define SHARE2_base              (0x810A0000)
#define IRDBG2_base              (0x810B0000)
#define PATCH_base               (0x810C0000)
#define AFE_base                 (0x810D0000)
#define BFE_base                 (0x810E0000)
#define USB_base                 (0x82000000)
#define MMCONFG_base             (0x98000000)
#define GMC_base                 (0x98010000)
#define G2D_base                 (0x98020000)
#define GCMQ_base                (0x98030000)
#define R_DMA0_base              (0x98040000)
#define R_DMA1_base              (0x98050000)
#define W_DMA0_base              (0x98060000)
#define W_DMA1_base              (0x98070000)
#define SPI_base                 (0x98080000)
#define W_DMA2_base              (0x98090000)
#define JPEG_DMA_base            (0x980A0000)
#define CAMERA_base              (0x980B0000)
#define CSI2_base                 (0x980C0000)
#define OVL_DMA_base             (0x980D0000)
#define CRZ_base                 (0x980E0000)
#define DRZ_base                 (0x980F0000)
#define ROT_DMA0_base            (0x98100000)
#define ROT_DMA1_base            (0x98110000)
#define IMGPROC_base             (0x98120000)
#define BS_DMA_base              (0x98130000)
#define TD_DMA_base              (0x98140000)
#define PRZ_base                 (0x98170000)
#define JPEG_ENC_base            (0x98180000)
#define GRAPH_OVL_base           (0x98190000)
#define BTFG_base                (0x73000000)
#define BT_CIRQ_base             (0x73010000)
#define BT_DMA_base              (0x73020000)
#define ARM7_BTIF_base           (0x73030000)
#define BTPKV_base               (0x73040000)
#define BTTIM_base               (0x73050000)
#define BTRF_base                (0x73060000)
#define BTMODEM_base             (0x73070000)
#define BTDBGIF_base             (0x73080000)
#define DPRAM_CPU_base           (0x84000000)
#define DPRAM2_CPU_base          (0x85000000)
#define IDMA_base                (0x86000000)
#define IDMA2_base               (0x87000000)
#define LCD_base                 (0x90000000)


#define CONFIG_SD_base            	(0x80000000)
#define EMI_SD_base                 (0x80010000)
#define CIRQ_SD_base                (0x80020000)
#define DMA_SD_base                 (0x80030000)
#define UART1_SD_base               (0x80040000)
#define UART2_SD_base               (0x80050000)
#define UART3_SD_base               (0x80060000)
#define GPT_SD_base                 (0x80070000)
#define KP_SD_base                  (0x80080000)
#define PWM_SD_base                 (0x80090000)
#define SIM_SD_base                 (0x800A0000)
#define ARM9_BTIF_SD_base           (0x800B0000)
#define RTC_SD_base                 (0x800C0000)
#define IRDA_SD_base                (0x800D0000)
#define I2C_SD_base                 (0x800E0000)
#define MSDC_SD_base                (0x800F0000)
#define MSDC2_SD_base               (0x80100000)
#define NFI_SD_base                 (0x80110000)
#define SIM2_SD_base                (0x80120000)
#define SEJ_SD_base                 (0x80140000)
#define TDMA_SD_base                (0x80150000)
#define AFC_SD_base                 (0x80160000)
#define AUXADC_SD_base              (0x80170000)
#define SHAREG1_SD_base             (0x80180000)
#define SHAREG2_SD_base             (0x80190000)
#define PLL_SD_base                 (0x801A0000)
#define MIXED_SD_base               (0x801B0000)
#define EFUSE_SD_base             	(0x801C0000)
#define GPIO_SD_base                (0x801D0000)
#define RGU_SD_base                 (0x801E0000)
#define ACCDET_SD_base              (0x801F0000)
#define MD2GCONFG_SD_base           (0x81000000)
#define BSI_SD_base                 (0x81010000)
#define BPI_SD_base                 (0x81020000)
#define APC_SD_base                 (0x81030000)
#define DIVIDER_SD_base             (0x81040000)
#define FCS_SD_base                 (0x81050000)
#define GCU_SD_base                 (0x81060000)
#define CSD_ACC_SD_base           	(0x81070000)
#define SHARE1_SD_base              (0x81080000)
#define IRDBG1_SD_base              (0x81090000)
#define SHARE2_SD_base              (0x810A0000)
#define IRDBG2_SD_base              (0x810B0000)
#define PATCH_SD_base               (0x810C0000)
#define AFE_SD_base                 (0x810D0000)
#define BFE_SD_base                 (0x810E0000)
#define USB_SD_base                 (0x82000000)
#define MMCONFG_SD_base             (0x98000000)
#define GMC_SD_base                 (0x98010000)
#define G2D_SD_base                 (0x98020000)
#define GCMQ_SD_base                (0x98030000)
#define R_DMA0_SD_base              (0x98040000)
#define R_DMA1_SD_base              (0x98050000)
#define W_DMA0_SD_base              (0x98060000)
#define W_DMA1_SD_base              (0x98070000)
#define SPI_SD_base                 (0x98080000)
#define W_DMA2_SD_base              (0x98090000)
#define JPEG_DMA_SD_base            (0x980A0000)
#define CAMERA_SD_base              (0x980B0000)
#define CSI2_SD_base                (0x980C0000)
#define OVL_DMA_SD_base             (0x980D0000)
#define CRZ_SD_base                 (0x980E0000)
#define DRZ_SD_base                 (0x980F0000)
#define ROT_DMA0_SD_base            (0x98100000)
#define ROT_DMA1_SD_base            (0x98110000)
#define IMGPROC_SD_base             (0x98120000)
#define BS_DMA_SD_base              (0x98130000)
#define TD_DMA_SD_base              (0x98140000)
#define PRZ_SD_base                 (0x98170000)
#define JPEG_ENC_SD_base            (0x98180000)
#define GRAPH_OVL_SD_base           (0x98190000)
#define BTFG_SD_base                (0x73000000)
#define BT_CIRQ_SD_base             (0x73010000)
#define BT_DMA_SD_base              (0x73020000)
#define ARM7_BTIF_SD_base           (0x73030000)
#define BTPKV_SD_base               (0x73040000)
#define BTTIM_SD_base               (0x73050000)
#define BTRF_SD_base                (0x73060000)
#define BTMODEM_SD_base             (0x73070000)
#define BTDBGIF_SD_base             (0x73080000)
#define DPRAM_CPU_SD_base           (0x84000000)
#define DPRAM2_CPU_SD_base          (0x85000000)
#define IDMA_SD_base                (0x86000000)
#define IDMA2_SD_base               (0x87000000)
#define LCD_SD_base                 (0x90000000)

#endif  /* !__REG_BASE_MT6236_H__ */

