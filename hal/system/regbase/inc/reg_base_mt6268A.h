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
 *   reg_base_mt6268A.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_MT6268A_H__
#define __REG_BASE_MT6268A_H__

#define USB_base                 (0x62000000)
#define EFUSE_base               (0x84000000)
#define CONFIG_base              (0x84010000)
#define GPIO_base                (0x84020000)
#define RGU_base                 (0x84030000)
#define BPI_base                 (0x84040000)
#define BSI_base                 (0x84050000)
#define TDMA_base                (0x84060000)
#define DIVIDER_base             (0x84070000)
#define AUXADC_base              (0x84080000)
#define AFC_base                 (0x84090000)
#define SHAREG1_base             (0x840A0000)
#define SHAREG2_base             (0x840B0000)
#define MIXED_base               (0x840C0000)
#define RTR_base                 (0x840D0000)
#define EMI_base                 (0x85000000)
#define CIRQ_base                (0x85010000)
#define DMA_base                 (0x85020000)
#define UART1_base               (0x85030000)
#define UART2_base               (0x85040000)
#define UART3_base               (0x85050000)
#define GPT_base                 (0x85060000)
//#define I2C2_base                (0x85070000)
#define I2C_base                 (0x85070000)
#define KP_base                  (0x85080000)
#define PWM_base                 (0x85090000)
#define SIM_base                 (0x850A0000)
#define ETM_base                 (0x850B0000)
#define RTC_base                 (0x850C0000)
#define SEJ_base                 (0x850D0000)
#define MCU_PF_base              (0x850E0000)
#define IRDA_base                (0x850F0000)
//#define I2C_base                 (0x85100000)
#define I2C_DUAL_base            (0x85100000)
#define MSDC_base                (0x85110000)
#define NFI_base                 (0x85120000)
#define SIM2_base                (0x85130000)
#define MSDC2_base               (0x85140000)
#define LOG_base                 (0x85150000)
#define LCD_base                 (0x91000000)
#define MMSYS_base               (0x94000000)
#define GMC_base                 (0x94000000)
#define G2D_base                 (0x94010000)
#define GCMQ_base                (0x94020000)
#define GIFDEC_base              (0x94030000)
#define IMGDMA_base              (0x94040000)
#define PNGDEC_base              (0x94050000)
#define MP4_base                 (0x94060000)
#define MP4_DEBLK_base           (0x94070000)
#define JPEG_base                (0x94080000)
#define TVCON_base               (0x94090000)
#define TVENC_base               (0x940A0000)
#define CAMERA_base              (0x940B0000)
#define IMGPROC_base             (0x940C0000)
#define PRZ_base                 (0x940D0000)
#define CRZ_base                 (0x940E0000)
#define DRZ_base                 (0x940F0000)
#define H264_base                (0x94100000)
#define SPI_base                 (0x94110000)
#define MMCONFG_base             (0x941F0000)
#define DPRAM_CPU_base           (0xA0400000)
#define DPRAM2_CPU_base          (0xA0800000)
#define IDMA_base                (0xA1000000)
#define IDMA2_base               (0xA2000000)
#define APC_base                 (0xA4040000)
#define FCS_base                 (0xA4070000)
#define GCU_base                 (0xA4080000)
#define CSD_ACC_base             (0xA4090000)
#define SHARE1_base              (0xA40A0000)
#define IRDBG1_base              (0xA40B0000)
#define SHARE2_base              (0xA40C0000)
#define IRDBG2_base              (0xA40D0000)
#define PATCH_base               (0xA40E0000)
#define AFE_base                 (0xA40F0000)
#define BFE_base                 (0xA4100000)
#define GCONFG_base              (0xA4110000)
#define TXBRP_base               (0xB4000000)
#define TXCRP_base               (0xB4010000)
#define SRCHR_base               (0xB4020000)
#define RXBFE_base               (0xB4030000)
#define RXSRP_base               (0xB4040000)
#define RAKE_base                (0xB4050000)
#define RXBRP_base               (0xB4060000)
#define BITCP_base               (0xB4070000)
#define F8F9_base                (0xB4080000)
#define LOG3G_base               (0xB4090000)
#define LPBK_base                (0xB40A0000)
#define WCONFG_base              (0xB41F0000)

////////////////////////////////////////////////////////////////
//                Temporary Setting
////////////////////////////////////////////////////////////////
#define PFC_base                 (0x85190000) // ?
#define B2PSI_base               (0x801C0000) // ?



#define USB_SD_base                 (0x62000000)
#define EFUSE_SD_base               (0x84000000)
#define CONFIG_SD_base              (0x84010000)
#define GPIO_SD_base                (0x84020000)
#define RGU_SD_base                 (0x84030000)
#define BPI_SD_base                 (0x84040000)
#define BSI_SD_base                 (0x84050000)
#define TDMA_SD_base                (0x84060000)
#define DIVIDER_SD_base             (0x84070000)
#define AUXADC_SD_base              (0x84080000)
#define AFC_SD_base                 (0x84090000)
#define SHAREG1_SD_base             (0x840A0000)
#define SHAREG2_SD_base             (0x840B0000)
#define MIXED_SD_base               (0x840C0000)
#define RTR_SD_base                 (0x840D0000)
#define EMI_SD_base                 (0x85000000)
#define CIRQ_SD_base                (0x85010000)
#define DMA_SD_base                 (0x85020000)
#define UART1_SD_base               (0x85030000)
#define UART2_SD_base               (0x85040000)
#define UART3_SD_base               (0x85050000)
#define GPT_SD_base                 (0x85060000)
//#define I2C2_SD_base                (0x85070000)
#define I2C_SD_base                 (0x85070000)
#define KP_SD_base                  (0x85080000)
#define PWM_SD_base                 (0x85090000)
#define SIM_SD_base                 (0x850A0000)
#define ETM_SD_base                 (0x850B0000)
#define RTC_SD_base                 (0x850C0000)
#define SEJ_SD_base                 (0x850D0000)
#define MCU_PF_SD_base              (0x850E0000)
#define IRDA_SD_base                (0x850F0000)
//#define I2C_SD_base                 (0x85100000)
#define I2C_DUAL_SD_base            (0x85100000)
#define MSDC_SD_base                (0x85110000)
#define NFI_SD_base                 (0x85120000)
#define SIM2_SD_base                (0x85130000)
#define MSDC2_SD_base               (0x85140000)
#define LOG_SD_base                 (0x85150000)
#define LCD_SD_base                 (0x91000000)
#define MMSYS_SD_base               (0x94000000)
#define GMC_SD_base                 (0x94000000)
#define G2D_SD_base                 (0x94010000)
#define GCMQ_SD_base                (0x94020000)
#define GIFDEC_SD_base              (0x94030000)
#define IMGDMA_SD_base              (0x94040000)
#define PNGDEC_SD_base              (0x94050000)
#define MP4_SD_base                 (0x94060000)
#define MP4_DEBLK_SD_base           (0x94070000)
#define JPEG_SD_base                (0x94080000)
#define TVCON_SD_base               (0x94090000)
#define TVENC_SD_base               (0x940A0000)
#define CAMERA_SD_base              (0x940B0000)
#define IMGPROC_SD_base             (0x940C0000)
#define PRZ_SD_base                 (0x940D0000)
#define CRZ_SD_base                 (0x940E0000)
#define DRZ_SD_base                 (0x940F0000)
#define H264_SD_base                (0x94100000)
#define SPI_SD_base                 (0x94110000)
#define MMCONFG_SD_base             (0x941F0000)
#define DPRAM_CPU_SD_base           (0xA0400000)
#define DPRAM2_CPU_SD_base          (0xA0800000)
#define IDMA_SD_base                (0xA1000000)
#define IDMA2_SD_base               (0xA2000000)
#define APC_SD_base                 (0xA4040000)
#define FCS_SD_base                 (0xA4070000)
#define GCU_SD_base                 (0xA4080000)
#define CSD_ACC_SD_base             (0xA4090000)
#define SHARE1_SD_base              (0xA40A0000)
#define IRDBG1_SD_base              (0xA40B0000)
#define SHARE2_SD_base              (0xA40C0000)
#define IRDBG2_SD_base              (0xA40D0000)
#define PATCH_SD_base               (0xA40E0000)
#define AFE_SD_base                 (0xA40F0000)
#define BFE_SD_base                 (0xA4100000)
#define GCONFG_SD_base              (0xA4110000)
#define TXBRP_SD_base               (0xB4000000)
#define TXCRP_SD_base               (0xB4010000)
#define SRCHR_SD_base               (0xB4020000)
#define RXBFE_SD_base               (0xB4030000)
#define RXSRP_SD_base               (0xB4040000)
#define RAKE_SD_base                (0xB4050000)
#define RXBRP_SD_base               (0xB4060000)
#define BITCP_SD_base               (0xB4070000)
#define F8F9_SD_base                (0xB4080000)
#define LOG3G_SD_base               (0xB4090000)
#define LPBK_SD_base                (0xB40A0000)
#define WCONFG_SD_base              (0xB41F0000)

////////////////////////////////////////////////////////////////
//                Temporary Setting
////////////////////////////////////////////////////////////////
#define PFC_SD_base                 (0x85190000) // ?
#define B2PSI_SD_base               (0x801C0000) // ?



#endif  /* __REG_base_MT6238A_H__ */

