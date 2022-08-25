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
 *   reg_base_mt6255.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_MT6255_H__
#define __REG_BASE_MT6255_H__
 
#define CONFIG_base            	    (0x80000000)
#define EMI_base                    (0x80010000)
#define CIRQ_base                   (0x80020000)
#define DMA_base                    (0x80030000)
#define UART1_base                  (0x80040000)
#define UART2_base                  (0x80050000)
#define UART3_base                  (0x80060000)
#define GPT_base                    (0x80070000)
#define KP_base                     (0x80080000)
#define PWM_base                    (0x80090000)
#define SIM_base                    (0x800A0000)
#define BTIF_base                   (0x800B0000)
#define RTC_base                    (0x800C0000)
#define ABBSYS_base                 (0x800D0000)
#define I2C_base                    (0x800E0000)
#define MSDC_base                   (0x800F0000)
#define MSDC2_base                  (0x80100000)
#define NFI_base                    (0x80110000)
#define SIM2_base                   (0x80120000)
#define NFIECC_base                 (0x80130000)
#define SEJ_base                    (0x80140000)
#define TDMA_base                   (0x80150000)
#define NLI_ARB_base                (0x80160000)
#define AUXADC_base                 (0x80170000)
#define SHAREG_base                 (0x80190000)
#define PLL_base                    (0x801A0000)
#define MIXED_base                  (0x801B0000)
#define EFUSE_base             	    (0x801C0000)
#define GPIO_base                   (0x801D0000)
#define RGU_base                    (0x801E0000)
#define ACCDET_base                 (0x801F0000)
#define HIF0_base                   (0x80200000)
#define HIF1_base                   (0x80210000)
#define FM_base                     (0x80220000)
#define RWGEN_base                  (0x80230000)
#define SFI_base                    (0x80240000)
#define USB_base                    (0x82000000)
#define USBSIF_base                 (0x82800000)

#define MD2GCONFG_base              (0x81000000)
#define BSI_base                    (0x81010000)
#define BPI_base                    (0x81020000)
#define APC_base                    (0x81030000)
#define DIVIDER_base                (0x81040000)
#define FCS_base                    (0x81050000)
#define GCU_base                    (0x81060000)
#define CSD_ACC_base                (0x81070000)
#define SHARE_base                  (0x810A0000)
#define IRDBG_base                  (0x810B0000)
#define PATCH_base                  (0x810C0000)
#define AFE_base                    (0x810D0000)
#define BFE_base                    (0x810E0000)
#define IDMA_base                   (0x86000000)
#define DPRAM_CPU_base              (0x86200000)

#define MMCONFG_base                (0x98000000)
#define R_DMA_base                  (0x98010000)
#define CAM_base                    (0x98020000)
#define CAMERA_base                 (0x98020000)
#define CRZ_base                    (0x98050000)
#define IMGPROC_base                (0x98070000)
#define VDO_ROT_base                (0x98080000)
#define RGB_ROT1_base               (0x980A0000)
#define SPI_base                    (0x980C0000)
#define LCD_base                    (0x980D0000)
#define SCAM_base                   (0x980E0000)
#define VRZ_base                    (0x98100000)
#define G2D_base                    (0x98110000)
#define GMC_base                    (0x98120000)
#define MP4JPG_base                 (0x98130000)

#define BT_RAM_base                 (0x71000000)
#define BT_PATCH_base               (0x72000000)
#define BT_CFG_base                 (0x73000000)
#define BT_CIRQ_base                (0x73010000)
#define BT_DMA_base                 (0x73020000)
#define BT_ARM7_BTIF_base           (0x73030000)
#define BT_PKV_base                 (0x73040000)
#define BT_TIM_base                 (0x73050000)
#define BT_RF_base                  (0x73060000)
#define BT_MODEM_base               (0x73070000)
#define BT_DEBUG_base               (0x73080000)

/*
 *  Shared device alias definition, even for ARMv5 or prior platform, they'll be 
 *  defined for easier software porting
 */
#define CONFIG_SD_base         	    (CONFIG_base)
#define EMI_SD_base                 (EMI_base)
#define CIRQ_SD_base                (CIRQ_base)
#define DMA_SD_base                 (DMA_base)
#define UART1_SD_base               (UART1_base)
#define UART2_SD_base               (UART2_base)
#define UART3_SD_base               (UART3_base)
#define GPT_SD_base                 (GPT_base)
#define KP_SD_base                  (KP_base)
#define PWM_SD_base                 (PWM_base)
#define SIM_SD_base                 (SIM_base)
#define BTIF_SD_base                (BTIF_base)
#define RTC_SD_base                 (RTC_base)
#define ABBSYS_SD_base              (ABBSYS_base)
#define I2C_SD_base                 (I2C_base)
#define MSDC_SD_base                (MSDC_base)
#define MSDC2_SD_base               (MSDC2_base)
#define NFI_SD_base                 (NFI_base)
#define SIM2_SD_base                (SIM2_base)
#define NFIECC_SD_base              (NFIECC_base)
#define SEJ_SD_base                 (SEJ_base)
#define TDMA_SD_base                (TDMA_base)
#define NLI_ARB_SD_base             (NLI_ARB_base)
#define AUXADC_SD_base              (AUXADC_base)
#define SHAREG_SD_base              (SHAREG_base)
#define PLL_SD_base                 (PLL_base)
#define MIXED_SD_base               (MIXED_base)
#define EFUSE_SD_base          	    (EFUSE_base)
#define GPIO_SD_base                (GPIO_base)
#define RGU_SD_base                 (RGU_base)
#define ACCDET_SD_base              (ACCDET_base)
#define HIF0_SD_base                (HIF0_base)
#define HIF1_SD_base                (HIF1_base)
#define FM_SD_base                  (FM_base)
#define RWGEN_SD_base               (RWGEN_base)
#define SFI_SD_base                 (SFI_base)
#define USB_SD_base                 (USB_base)
#define USBSIF_SD_base              (USBSIF_base)

#define MD2GCONFG_SD_base           (MD2GCONFG_base)
#define BSI_SD_base                 (BSI_base)
#define BPI_SD_base                 (BPI_base)
#define APC_SD_base                 (APC_base)
#define DIVIDER_SD_base             (DIVIDER_base)
#define FCS_SD_base                 (FCS_base)
#define GCU_SD_base                 (GCU_base)
#define CSD_ACC_SD_base             (CSD_ACC_base)
#define SHARE_SD_base               (SHARE_base)
#define IRDBG_SD_base               (IRDBG_base)
#define PATCH_SD_base               (PATCH_base)
#define AFE_SD_base                 (AFE_base)
#define BFE_SD_base                 (BFE_base)
#define IDMA_SD_base                (IDMA_base)
#define DPRAM_CPU_SD_base           (DPRAM_CPU_base)

#define MMCONFG_SD_base             (MMCONFG_base)
#define R_DMA_SD_base               (R_DMA_base)
#define CAM_SD_base                 (CAM_base)
#define CAMERA_SD_base              (CAMERA_base)
#define CRZ_SD_base                 (CRZ_base)
#define IMGPROC_SD_base             (IMGPROC_base)
#define VDO_ROT_SD_base             (VDO_ROT_base)
#define VRZ_SD_base                 (VRZ_base)
#define RGB_ROT1_SD_base            (RGB_ROT1_base)
#define SPI_SD_base                 (SPI_base)
#define LCD_SD_base                 (LCD_base)
#define SCAM_SD_base                (SCAM_base)
#define G2D_SD_base                 (G2D_base)
#define GMC_SD_base                 (GMC_base)
#define MP4JPG_SD_base              (MP4JPG_base)

#endif  /* !__REG_BASE_MT6255_H__ */

