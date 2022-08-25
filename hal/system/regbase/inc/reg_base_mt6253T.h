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
 *   reg_base_mt6253T.h
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

#ifndef __REG_BASE_MT6253T_H__
#define __REG_BASE_MT6253T_H__

//#define DPRAM_CPU_base           (0x50000000)
#define USB_base                 (0x70000000)

#define EFUSE_base               (0x80000000)
#define CONFIG_base              (0x80010000) /*FZ, spec: CONFG*/
#define GPIO_base                (0x80020000)
#define RGU_base                 (0x80030000)

#define EMI_base                 (0x81000000)
#define CIRQ_base                (0x81010000)
#define DMA_base                 (0x81020000)
#define UART1_base               (0x81030000)
#define UART2_base               (0x81040000)
#define UART3_base               (0x81050000)
#define GPT_base                 (0x81060000)
#define ALERTER_base             (0x81070000) /*spec : ALTER*/
#define KP_base                  (0x81080000)
#define PWM_base                 (0x81090000)
#define SIM_base                 (0x810a0000)
#define AHBMON_base              (0x810b0000)
#define RTC_base                 (0x810c0000)
#define SEJ_base                 (0x810d0000)
#define SWDBG_base               (0x810e0000)
#define IRDA_base                (0x810f0000)
#define I2C_base                 (0x81100000)
#define MSDC_base                (0x81110000)
#define NFI_base                 (0x81120000)
#define SIM2_base                (0x81130000)

#define TDMA_base                (0x82000000)
#define BSI_base                 (0x82010000)
#define BPI_base                 (0x82020000)
#define APC_base                 (0x82040000)
#define AUXADC_base              (0x82050000)
#define DIVIDER_base             (0x82060000)
#define FCS_base                 (0x82070000)
#define GCU_base                 (0x82080000)
#define CSD_ACC_base             (0x82090000)
#define SHARE_base               (0x820a0000)
#define IRDBG_base               (0x820b0000)
#define SHARE2_base              (0x820c0000)
#define IRDBG2_base              (0x820d0000)
#define PATCH_base               (0x820e0000)
#define AFE_base                 (0x820f0000)
#define BFE_base                 (0x82100000)

#define PLL_CLKSQ_base           (0x83000000)
#define MIXED_base               (0x83010000)

#define GMC_base                 (0x84000000)
#define PRZ_base                 (0x84010000) /*spec : RESZ_base*/
#define CAMERA_base              (0x84020000) /*spec: CAM_base*/
#define DPRAM_CPU_base           (0xA0000000)
#define DPRAM2_CPU_base          (0xA1000000)
#define IDMA_base                (0xA2000000)
#define IDMA2_base               (0xA3000000)

#define L1_CACHE_base            (0x85000000)

#define LCD_base                 (0x90000000)



//#define DPRAM_CPU_SD_base           (0x50000000)
#define USB_SD_base                 (0x70000000)

#define EFUSE_SD_base               (0x80000000)
#define CONFIG_SD_base              (0x80010000) /*FZ, spec: CONFG*/
#define GPIO_SD_base                (0x80020000)
#define RGU_SD_base                 (0x80030000)

#define EMI_SD_base                 (0x81000000)
#define CIRQ_SD_base                (0x81010000)
#define DMA_SD_base                 (0x81020000)
#define UART1_SD_base               (0x81030000)
#define UART2_SD_base               (0x81040000)
#define UART3_SD_base               (0x81050000)
#define GPT_SD_base                 (0x81060000)
#define ALERTER_SD_base             (0x81070000) /*spec : ALTER*/
#define KP_SD_base                  (0x81080000)
#define PWM_SD_base                 (0x81090000)
#define SIM_SD_base                 (0x810a0000)
#define AHBMON_SD_base              (0x810b0000)
#define RTC_SD_base                 (0x810c0000)
#define SEJ_SD_base                 (0x810d0000)
#define SWDBG_SD_base               (0x810e0000)
#define IRDA_SD_base                (0x810f0000)
#define I2C_SD_base                 (0x81100000)
#define MSDC_SD_base                (0x81110000)
#define NFI_SD_base                 (0x81120000)
#define SIM2_SD_base                (0x81130000)

#define TDMA_SD_base                (0x82000000)
#define BSI_SD_base                 (0x82010000)
#define BPI_SD_base                 (0x82020000)
#define APC_SD_base                 (0x82040000)
#define AUXADC_SD_base              (0x82050000)
#define DIVIDER_SD_base             (0x82060000)
#define FCS_SD_base                 (0x82070000)
#define GCU_SD_base                 (0x82080000)
#define CSD_ACC_SD_base             (0x82090000)
#define SHARE_SD_base               (0x820a0000)
#define IRDBG_SD_base               (0x820b0000)
#define SHARE2_SD_base              (0x820c0000)
#define IRDBG2_SD_base              (0x820d0000)
#define PATCH_SD_base               (0x820e0000)
#define AFE_SD_base                 (0x820f0000)
#define BFE_SD_base                 (0x82100000)

#define PLL_CLKSQ_SD_base           (0x83000000)
#define MIXED_SD_base               (0x83010000)

#define GMC_SD_base                 (0x84000000)
#define PRZ_SD_base                 (0x84010000) /*spec : RESZ_SD_base*/
#define CAMERA_SD_base              (0x84020000) /*spec: CAM_SD_base*/
#define DPRAM_CPU_SD_base           (0xA0000000)
#define DPRAM2_CPU_SD_base          (0xA1000000)
#define IDMA_SD_base                (0xA2000000)
#define IDMA2_SD_base               (0xA3000000)

#define L1_CACHE_SD_base            (0x85000000)

#define LCD_SD_base                 (0x90000000)




#endif  /* __REG_BASE_MT6253T_H__ */

