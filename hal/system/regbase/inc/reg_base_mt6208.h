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
 *   reg_base_mt6208.h
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

#ifndef __REG_BASE_MT6208_H__
#define __REG_BASE_MT6208_H__

#define DPRAM_CPU_base           (0x50000000)
#define IDMA_base                (0x60000000)   /* IDMA */
#define CONFIG_base              (0x80000000)   /* Config registers  (Clk, Power Down, Ver) */
#define EMI_base                 (0x80010000)   /* EMI registers */
#define CIRQ_base                (0x80020000)   /* IRQ Controller */
#define DMA_base                 (0x80030000)   /* DMA Controller */
#define RGU_base                 (0x80040000)   /* Reset Generation Unit */
#define GCU_base                 (0x80060000)   /* GPRS Crypto Unit */
#define NFI_base                 (0x80090000)   /* NAND Flash Interface */
#define SCCB_base                (0x800a0000)   /* Serial Camera Control Bus */
#define GPT_base                 (0x80100000)   /* General Purpose Timer */
#define KP_base                  (0x80110000)   /* Keypad Scanner */
#define GPIO_base                (0x80120000)   /* GPIO */
#define UART1_base               (0x80130000)   /* UART / SIR IrDA */
#define SIM_base                 (0x80140000)   /* SIM Card interface */
#define PWM_base                 (0x80150000)   /* Pulse Width Modulator */
#define ALERTER_base             (0x80160000)   /* Audio Alerter */
#define LCD_base                 (0x80170000)   /* LCD */
#define UART2_base               (0x80180000)   /* UART / SIR IrDA 2 */
#define MMC_base                 (0x80190000)   /* Multi-Media Card */
#define TDMA_base                (0x80200000)   /* TDMA Timer */
#define RTC_base                 (0x80210000)   /* Real Time Clock unit */
#define BSI_base                 (0x80220000)   /* Baseband Serial Interface */
#define BPI_base                 (0x80230000)   /* Baseband Parallel Interface */
#define AFC_base                 (0x80240000)   /* AFC */
#define APC_base                 (0x80250000)   /* TX Power Control */
#define FCS_base                 (0x80260000)   /* FCS Unit */
#define AUXADC_base              (0x80270000)   /* Auxiliary ADC */
#define DIVIDER_base             (0x80280000)   /* Divider/Modulus Coprocessor */
#define CSD_ACC_base             (0x80290000)   /* CSD Format Conversion Coprocessor */
#define SHARE_base               (0x80300000)   /* DSP to CPU interrupt control (shared register) */
#define PATCH_base               (0x80310000)   /* DSP to CPU interrupt control (shared register) */
#define AFE_base                 (0x80400000)   /* Audio interface */
#define BFE_base                 (0x80410000)   /* Base-band Front End */


#define DPRAM_CPU_SD_base           (0x50000000)
#define IDMA_SD_base                (0x60000000)   /* IDMA */
#define CONFIG_SD_base              (0x80000000)   /* Config registers  (Clk, Power Down, Ver) */
#define EMI_SD_base                 (0x80010000)   /* EMI registers */
#define CIRQ_SD_base                (0x80020000)   /* IRQ Controller */
#define DMA_SD_base                 (0x80030000)   /* DMA Controller */
#define RGU_SD_base                 (0x80040000)   /* Reset Generation Unit */
#define GCU_SD_base                 (0x80060000)   /* GPRS Crypto Unit */
#define NFI_SD_base                 (0x80090000)   /* NAND Flash Interface */
#define SCCB_SD_base                (0x800a0000)   /* Serial Camera Control Bus */
#define GPT_SD_base                 (0x80100000)   /* General Purpose Timer */
#define KP_SD_base                  (0x80110000)   /* Keypad Scanner */
#define GPIO_SD_base                (0x80120000)   /* GPIO */
#define UART1_SD_base               (0x80130000)   /* UART / SIR IrDA */
#define SIM_SD_base                 (0x80140000)   /* SIM Card interface */
#define PWM_SD_base                 (0x80150000)   /* Pulse Width Modulator */
#define ALERTER_SD_base             (0x80160000)   /* Audio Alerter */
#define LCD_SD_base                 (0x80170000)   /* LCD */
#define UART2_SD_base               (0x80180000)   /* UART / SIR IrDA 2 */
#define MMC_SD_base                 (0x80190000)   /* Multi-Media Card */
#define TDMA_SD_base                (0x80200000)   /* TDMA Timer */
#define RTC_SD_base                 (0x80210000)   /* Real Time Clock unit */
#define BSI_SD_base                 (0x80220000)   /* Baseband Serial Interface */
#define BPI_SD_base                 (0x80230000)   /* Baseband Parallel Interface */
#define AFC_SD_base                 (0x80240000)   /* AFC */
#define APC_SD_base                 (0x80250000)   /* TX Power Control */
#define FCS_SD_base                 (0x80260000)   /* FCS Unit */
#define AUXADC_SD_base              (0x80270000)   /* Auxiliary ADC */
#define DIVIDER_SD_base             (0x80280000)   /* Divider/Modulus Coprocessor */
#define CSD_ACC_SD_base             (0x80290000)   /* CSD Format Conversion Coprocessor */
#define SHARE_SD_base               (0x80300000)   /* DSP to CPU interrupt control (shared register) */
#define PATCH_SD_base               (0x80310000)   /* DSP to CPU interrupt control (shared register) */
#define AFE_SD_base                 (0x80400000)   /* Audio interface */
#define BFE_SD_base                 (0x80410000)   /* Base-band Front End */


#endif  /* __REG_BASE_MT6208_H__ */

