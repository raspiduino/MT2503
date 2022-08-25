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
 *   reg_base_mt6268t.h
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_TK6516_H__
#define __REG_BASE_TK6516_H__

#define CONFIG_base              (0x80010000)   /* Config registers  (Clk, Power Down, Ver) */
#define RGU_base                 (0x80030000)   /* Reset Generation Unit */
#define CIRQ_base                (0x81010000)   /* IRQ Controller */
#define DMA_base                 (0x81020000)   /* DMA Controller */
#define UART1_ori_base     (0x81030000)   /* UART / SIR IrDA */
#define UART2_ori_base     (0x81040000)   /* UART / SIR IrDA 2 */
#define UART3_ori_base     (0x81050000)   /* UART3 */
#define GPIO_base                (0x80020000)   /* GPIO */
// For TK6516 the UART address must set to back door address (APB bus issue workaround
#define UART1_base               (0xF0023000)   /* UART / SIR IrDA */
#define UART2_base               (0xF0024000)   /* UART / SIR IrDA 2 */
#define UART3_base               (0xF0025000)   /* UART3 */
#define GPT_base                 (0x81060000)   /* General Purpose Timer */
#define SIM_base                 (0x810A0000)   /* SIM Card interface */
#define NFI_base                 (0x81120000)   /* NAND Flash Interface */
#define CCIF_base                (0x81160000)   /* Cross Core Interface */
#define TDMA_base                (0x82000000)   /* TDMA Timer */
//#define SM_base                  (0x82000200)   /* Sleep Mode */
#define BSI_base                 (0x82010000)   /* Baseband Serial Interface */
#define BPI_base                 (0x82020000)   /* Baseband Parallel Interface */
#define AFC_base                 (0x82030000)   /* AFC */
#define APC_base                 (0x82040000)   /* TX Power Control */
#define AUXADC_base              (0x82050000)   /* Auxiliary ADC */
#define DIVIDER_base             (0x82060000)   /* Divider */
#define FCS_base                 (0x82070000)   /* FCS Unit */
#define GCU_base                 (0x82080000)   /* GPRS Crypto Unit */
#define CSD_ACC_base             (0x82090000)   /* CSD_ACC */
#define SHARE_base               (0x820A0000)   /* DSP to CPU interrupt control (shared register) */
#define PATCH_base               (0x820E0000)   /* DSP patch unit */

#define IRDBG_base               (0x820B0000)   /* IRDBG */
#define SHARE2_base              (0x820C0000)   /* DSP2 to CPU interrupt control (shared register) */
#define IRDBG2_base              (0x820D0000)   /* IRDBG2 */
#define BFE_base                 (0x82100000)   /* Base-band Front End */
#define AFE_base                 (0x820F0000)   /* Audio Front End Controller       */
#define MIXED_base               (0x83010000)   /* Analog Chip Interface Controller */

#define DPRAM_CPU_base           (0xA0000000)   /*MCU/DSP Sherif*/
#define DPRAM2_CPU_base          (0xA1000000)   /*MCU/DSP Sherif*/
#define IDMA_base                (0xA2000000)
#define IDMA2_base               (0xA3000000)

//#if 0
//#ifdef __MD_STANDALONE__
#define EMI_base                 (0x81000000)   /* EMI registers */
#define EMI2_base                (0x81190000)   /* EMI2 registers */
#define ALERTER_base             (0x81070000)   /* Audio Alerter */
#define KP_base                  (0x81080000)   /* Keypad Scanner */
#define PWM_base                 (0x81090000)   /* Pulse Width Modulator */
#define CHE_base                 (0x810D0000)   /* Cipher Hash Engine */
#define PFC_base                 (0x810E0000)   /* PPP Framer */
//#endif /*__MD_STANDALONE__*/
//#endif /*#if 0, Added by request*/



#define CONFIG_SD_base              (0x80010000)   /* Config registers  (Clk, Power Down, Ver) */
#define RGU_SD_base                 (0x80030000)   /* Reset Generation Unit */
#define CIRQ_SD_base                (0x81010000)   /* IRQ Controller */
#define DMA_SD_base                 (0x81020000)   /* DMA Controller */
#define UART1_ori_SD_base     (0x81030000)   /* UART / SIR IrDA */
#define UART2_ori_SD_base     (0x81040000)   /* UART / SIR IrDA 2 */
#define UART3_ori_SD_base     (0x81050000)   /* UART3 */
#define GPIO_SD_base                (0x80020000)   /* GPIO */
// For TK6516 the UART address must set to back door address (APB bus issue workaround
#define UART1_SD_base               (0xF0023000)   /* UART / SIR IrDA */
#define UART2_SD_base               (0xF0024000)   /* UART / SIR IrDA 2 */
#define UART3_SD_base               (0xF0025000)   /* UART3 */
#define GPT_SD_base                 (0x81060000)   /* General Purpose Timer */
#define SIM_SD_base                 (0x810A0000)   /* SIM Card interface */
#define NFI_SD_base                 (0x81120000)   /* NAND Flash Interface */
#define CCIF_SD_base                (0x81160000)   /* Cross Core Interface */
#define TDMA_SD_base                (0x82000000)   /* TDMA Timer */
//#define SM_SD_base                  (0x82000200)   /* Sleep Mode */
#define BSI_SD_base                 (0x82010000)   /* Baseband Serial Interface */
#define BPI_SD_base                 (0x82020000)   /* Baseband Parallel Interface */
#define AFC_SD_base                 (0x82030000)   /* AFC */
#define APC_SD_base                 (0x82040000)   /* TX Power Control */
#define AUXADC_SD_base              (0x82050000)   /* Auxiliary ADC */
#define DIVIDER_SD_base             (0x82060000)   /* Divider */
#define FCS_SD_base                 (0x82070000)   /* FCS Unit */
#define GCU_SD_base                 (0x82080000)   /* GPRS Crypto Unit */
#define CSD_ACC_SD_base             (0x82090000)   /* CSD_ACC */
#define SHARE_SD_base               (0x820A0000)   /* DSP to CPU interrupt control (shared register) */
#define PATCH_SD_base               (0x820E0000)   /* DSP patch unit */

#define IRDBG_SD_base               (0x820B0000)   /* IRDBG */
#define SHARE2_SD_base              (0x820C0000)   /* DSP2 to CPU interrupt control (shared register) */
#define IRDBG2_SD_base              (0x820D0000)   /* IRDBG2 */
#define BFE_SD_base                 (0x82100000)   /* Base-band Front End */
#define AFE_SD_base                 (0x820F0000)   /* Audio Front End Controller       */
#define MIXED_SD_base               (0x83010000)   /* Analog Chip Interface Controller */

#define DPRAM_CPU_SD_base           (0xA0000000)   /*MCU/DSP Sherif*/
#define DPRAM2_CPU_SD_base          (0xA1000000)   /*MCU/DSP Sherif*/
#define IDMA_SD_base                (0xA2000000)
#define IDMA2_SD_base               (0xA3000000)

//#if 0
//#ifdef __MD_STANDALONE__
#define EMI_SD_base                 (0x81000000)   /* EMI registers */
#define EMI2_SD_base                (0x81190000)   /* EMI2 registers */
#define ALERTER_SD_base             (0x81070000)   /* Audio Alerter */
#define KP_SD_base                  (0x81080000)   /* Keypad Scanner */
#define PWM_SD_base                 (0x81090000)   /* Pulse Width Modulator */
#define CHE_SD_base                 (0x810D0000)   /* Cipher Hash Engine */
#define PFC_SD_base                 (0x810E0000)   /* PPP Framer */
//#endif /*__MD_STANDALONE__*/
//#endif /*#if 0, Added by request*/



#endif  /* __REG_BASE_TK6516_H__ */

