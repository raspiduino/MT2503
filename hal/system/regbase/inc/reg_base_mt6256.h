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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __REG_BASE_MT6256_H__
#define __REG_BASE_MT6256_H__
 
#if defined(MT6256_S00)     

/*
 *  For MT6256 E1 register base
 */ 

#define CONFIG_base            	 (0x70000000)
#define EMI_base                 (0x70010000)
#define CIRQ_base                (0x70020000)
#define DMA_base                 (0x70030000)
#define UART1_base               (0x70040000)
#define UART2_base               (0x70050000)
#define UART3_base               (0x70060000)
#define GPT_base                 (0x70070000)
#define KP_base                  (0x70080000)
#define PWM_base                 (0x70090000)
#define SIM_base                 (0x700A0000)
#define BTIF_base                (0x700B0000)
#define RTC_base                 (0x700C0000)
#define IRDA_base                (0x700D0000)
#define I2C_base                 (0x700E0000)
#define MSDC_base                (0x700F0000)
#define MSDC2_base               (0x70100000)
#define NFI_base                 (0x70110000)
#define SIM2_base                (0x70120000)
#define NFIECC_base              (0x70130000)
#define SEJ_base                 (0x70140000)
#define TDMA_base                (0x70150000)
#define AUXADC_base              (0x70170000)
#define SHAREG1_base             (0x70180000)
#define SHAREG2_base             (0x70190000)
#define PLL_base                 (0x701A0000)
#define MIXED_base               (0x701B0000)
#define EFUSE_base             	 (0x701C0000)
#define GPIO_base                (0x701D0000)
#define RGU_base                 (0x701E0000)
#define ACCDET_base              (0x701F0000)
#define USB_base                 (0x72000000)
#define MD2GCONFG_base           (0x80000000)
#define BSI_base                 (0x80010000)
#define BPI_base                 (0x80020000)
#define APC_base                 (0x80030000)
#define DIVIDER_base             (0x80040000)
#define FCS_base                 (0x80050000)
#define GCU_base                 (0x80060000)
#define CSD_ACC_base           	 (0x80070000)
#define SHARE1_base              (0x80080000)
#define IRDBG1_base              (0x80090000)
#define SHARE2_base              (0x800A0000)
#define IRDBG2_base              (0x800B0000)
#define PATCH_base               (0x800C0000)
#define AFE_base                 (0x800D0000)
#define BFE_base                 (0x800E0000)
#define FM_base                  (0x800F0000)
#define DPRAM_CPU_base           (0x82000000)
#define DPRAM2_CPU_base          (0x83000000)
#define IDMA_base                (0x84000000)
#define IDMA2_base               (0x85000000)
#define MMCONFG_base             (0x90000000)
#define R_DMA_base               (0x90010000)
#define CAM_base                 (0x90020000)
#define CAMERA_base              (0x90020000)
#define JPEG_CODEC_base          (0x90030000)
#define BRZ_base                 (0x90040000)
#define CRZ_base                 (0x90050000)
#define OVL_DMA_base             (0x90060000)
#define IMGPROC_base             (0x90070000)
#define ROT_DMA0_base            (0x90080000)
#define PRZ_base                 (0x90090000)
#define ROT_DMA1_base            (0x900A0000)
#define VRZ_base                 (0x900B0000)
#define ROT_DMA2_base            (0x900C0000)
#define JPEG_DMA_base            (0x900D0000)
#define GRAPH_OVL_base           (0x900E0000)
#define ROT_DMA3_base            (0x900F0000)
#define G2D_base                 (0x90100000)
#define GCMQ_base                (0x90110000)
#define IT_DMA_base              (0x90120000)
#define SPI_base                 (0x90130000)
#define GMC_base                 (0x90140000)
#define LCD_base                 (0x92000000)

#define CONFIG_SD_base              (0xB0300000)
#define EMI_SD_base                 (0xB0310000)
#define CIRQ_SD_base                (0xB0320000)
#define DMA_SD_base                 (0xB0330000)
#define UART1_SD_base               (0xB0340000)
#define UART2_SD_base               (0xB0350000)
#define UART3_SD_base               (0xB0360000)
#define GPT_SD_base                 (0xB0370000)
#define KP_SD_base                  (0xB0380000)
#define PWM_SD_base                 (0xB0390000)
#define SIM_SD_base                 (0xB03A0000)
#define BTIF_SD_base                (0xB03B0000)
#define RTC_SD_base                 (0xB03C0000)
#define IRDA_SD_base                (0xB03D0000)
#define I2C_SD_base                 (0xB03E0000)
#define MSDC_SD_base                (0xB03F0000)
#define MSDC2_SD_base               (0xB0400000)
#define NFI_SD_base                 (0xB0410000)
#define SIM2_SD_base                (0xB0420000)
#define NFIECC_SD_base              (0xB0430000)
#define SEJ_SD_base                 (0xB0440000)
#define TDMA_SD_base                (0xB0450000)
#define AUXADC_SD_base              (0xB0470000)
#define SHAREG1_SD_base             (0xB0480000)
#define SHAREG2_SD_base             (0xB0490000)
#define PLL_SD_base                 (0xB04A0000)
#define MIXED_SD_base               (0xB04B0000)
#define EFUSE_SD_base             	 (0xB04C0000)
#define GPIO_SD_base                (0xB04D0000)
#define RGU_SD_base                 (0xB04E0000)
#define ACCDET_SD_base              (0xB04F0000)
#define USB_SD_base                 (0xB0700000)
#define MD2GCONFG_SD_base           (0xB0D00000)
#define BSI_SD_base                 (0xB0D10000)
#define BPI_SD_base                 (0xB0D20000)
#define APC_SD_base                 (0xB0D30000)
#define DIVIDER_SD_base             (0xB0D40000)
#define FCS_SD_base                 (0xB0D50000)
#define GCU_SD_base                 (0xB0D60000)
#define CSD_ACC_SD_base           	 (0xB0D70000)
#define SHARE1_SD_base              (0xB0D80000)
#define IRDBG1_SD_base              (0xB0D90000)
#define SHARE2_SD_base              (0xB0DA0000)
#define IRDBG2_SD_base              (0xB0DB0000)
#define PATCH_SD_base               (0xB0DC0000)
#define AFE_SD_base                 (0xB0DD0000)
#define BFE_SD_base                 (0xB0DE0000)
#define FM_SD_base                  (0xB0DF0000)
#define DPRAM_CPU_SD_base           (0xB1000000)
#define DPRAM2_CPU_SD_base          (0xB1300000)
#define MMCONFG_SD_base             (0xB2100000)
#define R_DMA_SD_base               (0xB2110000)
#define CAM_SD_base                 (0xB2120000)
#define JPEG_CODEC_SD_base          (0xB2130000)
#define BRZ_SD_base                 (0xB2140000)
#define CRZ_SD_base                 (0xB2150000)
#define OVL_DMA_SD_base             (0xB2160000)
#define IMGPROC_SD_base             (0xB2170000)
#define ROT_DMA0_SD_base            (0xB2180000)
#define PRZ_SD_base                 (0xB2190000)
#define ROT_DMA1_SD_base            (0xB21A0000)
#define DRZ_SD_base                 (0xB21B0000)
#define ROT_DMA2_SD_base            (0xB21C0000)
#define JPEG_DMA_SD_base            (0xB21D0000)
#define GRAPH_OVL_SD_base           (0xB21E0000)
#define ROT_DMA3_SD_base            (0xB21F0000)
#define G2D_SD_base                 (0xB2200000)
#define GCMQ_SD_base                (0xB2210000)
#define IT_DMA_SD_base              (0xB2220000)
#define SPI_SD_base                 (0xB2230000)
#define GMC_SD_base                 (0xB2240000)
#define LCD_SD_base                 (0xB2800000)

#else   /* MT6256_S00 */

/*
 *  For MT6256 E2 or later register base
 */ 

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
#define USB_base                    (0x82000000)
#define MD2GCONFG_base              (0x70000000)
#define BSI_base                    (0x70010000)
#define BPI_base                    (0x70020000)
#define APC_base                    (0x70030000)
#define DIVIDER_base                (0x70040000)
#define FCS_base                    (0x70050000)
#define GCU_base                    (0x70060000)
#define CSD_ACC_base           	    (0x70070000)
#define DSP_CACHE_base        	    (0x70080000)
#define SHARE_base                  (0x700A0000)
#define IRDBG_base                  (0x700B0000)
#define PATCH_base                  (0x700C0000)
#define AFE_base                    (0x700D0000)
#define BFE_base                    (0x700E0000)
#define IDMA_base                   (0x75000000)
#define DPRAM_CPU_base              (0x75200000)
#define MMCONFG_base                (0x90000000)
#define R_DMA_base                  (0x90010000)
#define CAM_base                    (0x90020000)
#define CAMERA_base                 (0x90020000)
#define JPEG_CODEC_base             (0x90030000)
#define BRZ_base                    (0x90040000)
#define CRZ_base                    (0x90050000)
#define OVL_DMA_base                (0x90060000)
#define IMGPROC_base                (0x90070000)
#define VDO_ROT_base                (0x90080000)
#define PRZ_base                    (0x90090000)
#define RGB_ROT1_base               (0x900A0000)
#define JPEG_DMA_base               (0x900B0000)
#define SPI_base                    (0x900C0000)
#define LCD_base                    (0x900D0000)
#define SCAM_base                   (0x900E0000)
#define RGB_ROT2_base               (0x900F0000)
#define VRZ_base                    (0x90100000)
#define GMC_base                    (0x90120000)
#define VENC_base                   (0x90130000)

#define GRAPHSYS_base								(0x98000000)
#define GPU_GP_base									(0x98010000)
#define GPU_L2_base								  (0x98011000)
#define GPU_PMU_base								(0x98012000)
#define GPU_GPMMU_base							(0x98013000)
#define GPU_PP0MMU_base							(0x98014000)
#define GPU_PP0_base							  (0x98018000)

#define BT_RAM_base                 (0xA1000000)
#define BT_PATCH_base               (0xA2000000)
#define BT_CFG_base                 (0xA3000000)
#define BT_CIRQ_base                (0xA3010000)
#define BT_DMA_base                 (0xA3020000)
#define BT_ARM7_BTIF_base           (0xA3030000)
#define BT_PKV_base                 (0xA3040000)
#define BT_TIM_base                 (0xA3050000)
#define BT_RF_base                  (0xA3060000)
#define BT_MODEM_base               (0xA3070000)
#define BT_DEBUG_base               (0xA3080000)

#define CONFIG_SD_base         	    (0xB0000000)
#define EMI_SD_base                 (0xB0010000)
#define CIRQ_SD_base                (0xB0020000)
#define DMA_SD_base                 (0xB0030000)
#define UART1_SD_base               (0xB0040000)
#define UART2_SD_base               (0xB0050000)
#define UART3_SD_base               (0xB0060000)
#define GPT_SD_base                 (0xB0070000)
#define KP_SD_base                  (0xB0080000)
#define PWM_SD_base                 (0xB0090000)
#define SIM_SD_base                 (0xB00A0000)
#define BTIF_SD_base                (0xB00B0000)
#define RTC_SD_base                 (0xB00C0000)
#define I2C_SD_base                 (0xB00E0000)
#define MSDC_SD_base                (0xB00F0000)
#define MSDC2_SD_base               (0xB0100000)
#define NFI_SD_base                 (0xB0110000)
#define SIM2_SD_base                (0xB0120000)
#define NFIECC_SD_base              (0xB0130000)
#define SEJ_SD_base                 (0xB0140000)
#define TDMA_SD_base                (0xB0150000)
#define NLI_ARB_SD_base             (0xB0160000)
#define AUXADC_SD_base              (0xB0170000)
#define SHAREG_SD_base              (0xB0190000)
#define PLL_SD_base                 (0xB01A0000)
#define MIXED_SD_base               (0xB01B0000)
#define EFUSE_SD_base          	    (0xB01C0000)
#define GPIO_SD_base                (0xB01D0000)
#define RGU_SD_base                 (0xB01E0000)
#define ACCDET_SD_base              (0xB01F0000)
#define HIF1_SD_base                (0xB0200000)
#define HIF2_SD_base                (0xB0210000)
#define FM_SD_base                  (0xB0220000)
#define USB_SD_base                 (0xB1000000)
#define MD2GCONFG_SD_base           (0xB2000000)
#define BSI_SD_base                 (0xB2010000)
#define BPI_SD_base                 (0xB2020000)
#define APC_SD_base                 (0xB2030000)
#define DIVIDER_SD_base             (0xB2040000)
#define FCS_SD_base                 (0xB2050000)
#define GCU_SD_base                 (0xB2060000)
#define CSD_ACC_SD_base        	    (0xB2070000)
#define DSP_CACHE_SD_base     	    (0xB2080000)
#define SHARE_SD_base               (0xB20A0000)
#define IRDBG_SD_base               (0xB20B0000)
#define PATCH_SD_base               (0xB20C0000)
#define AFE_SD_base                 (0xB20D0000)
#define BFE_SD_base                 (0xB20E0000)
#define IDMA_SD_base                (0xB3000000)
#define DPRAM_CPU_SD_base           (0xB3200000)
#define MMCONFG_SD_base             (0xB4000000)
#define R_DMA_SD_base               (0xB4010000)
#define CAM_SD_base                 (0xB4020000)
#define CAMERA_SD_base              (0xB4020000)
#define JPEG_CODEC_SD_base          (0xB4030000)
#define BRZ_SD_base                 (0xB4040000)
#define CRZ_SD_base                 (0xB4050000)
#define OVL_DMA_SD_base             (0xB4060000)
#define IMGPROC_SD_base             (0xB4070000)
#define VDO_ROT_SD_base             (0xB4080000)
#define PRZ_SD_base                 (0xB4090000)
#define RGB_ROT1_SD_base            (0xB40A0000)
#define JPEG_DMA_SD_base            (0xB40B0000)
#define SPI_SD_base                 (0xB40C0000)
#define LCD_SD_base                 (0xB40D0000)
#define SCAM_SD_base                (0xB40E0000)
#define RGB_ROT2_SD_base            (0xB40F0000)
#define VRZ_SD_base                 (0xB4100000)
#define GMC_SD_base                 (0xB4120000)


#endif  /* MT6256_S00 */


#endif  /* !__REG_BASE_MT6256_H__ */

