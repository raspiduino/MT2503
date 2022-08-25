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
 *   reg_base_MT6516_app_processor.h
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

#ifndef __REG_BASE_MT6516_H__
#define __REG_BASE_MT6516_H__


#define MD_ONLY_EMI_BASE (0xF1000000)
#define TDMA_base       (0xF11F0000)   /* TDMA Timer */
#define GCU_base        (0xF2080000)   /* GPRS Crypto Unit */
#define PATCH_base      (0xF20E0000)   /* DSP patch unit */
#define SHARE2_base     (0xF20C0000)
#define SHARE1_base     (0xF20A0000)   /* DSP to CPU interrupt control (shared register) */
#define SHAREG1_base    (0xF1190000)   /* share register 1 */
#define SHAREG2_base    (0xF11E0000)

#define LCD_base        (0x80120000)
#define USB_base        (0x80100000)
#define CSD_ACC_base    (0xF2090000)   /* CSD_ACC */
#define FCS_base        (0xF2070000)   /* FCS Unit */
#define MDMCUSYS_base   (0xF11C0000)

#define DIVIDER_base    (0xF2060000)
#define MD2GCONFG_base  (0xF2000000)
#define AFC_base        (0xF1200000)
#define BSI_base        (0xF2010000)   /* Baseband Serial Interface */
#define BPI_base        (0xF2020000)   /* Baseband Parallel Interface */
#define APC_base        (0xF2040000)   /* TX Power Control */
#define BFE_base        (0xF2100000)   /* Base-band Front End */
#define MIXED_base      (0xF3010000)   /* Analog Chip Interface Controller */
#define DPRAM_CPU_base  (0xF0000000)   /* MCU/DSP Sherif*/
#define DPRAM2_CPU_base (0xF1000000)   /* MCU/DSP Sherif*/
#define IDMA_base       (0xF2000000)
#define IDMA2_base      (0xF3000000)

#define CONFIG_base     (0x80001000)   /* Config registers  (Clk, Power Down, Ver) */
#define RGU_base        (0x80003000)   /* Reset Generation Unit */
#define EMI_base        (0x80020000)
#define CIRQ_base       (0x80021000)   /* IRQ Controller */
#define DMA_base        (0x80022000)   /* DMA Controller */
#define UART1_ori_base  (0x80023000)   /* UART / SIR IrDA */
#define UART2_ori_base  (0x80024000)   /* UART / SIR IrDA 2 */
#define UART3_ori_base  (0x80025000)   /* UART3 */
#define GPIO_base       (0x80002000)   /* GPIO */

#define UART1_base      (0x80023000)   /* UART / SIR IrDA */
#define UART2_base      (0x80024000)   /* UART / SIR IrDA 2 */
#define UART3_base      (0x80025000)   /* UART3 */

#define GPT_base        (0x80026000)   /* General Purpose Timer */
#define SIM_base        (0x80033000)
#define NFI_base        (0x80032000)   /* NAND Flash Interface */
#define ECC_base        (0x80038000)
#define CCIF_base       (0x80036000)   /* Cross Core Interface */
#define KP_base         (0x80028000)
#define PWM_base        (0x80029000)
#define UART4_base      (0x8002B000)
#define RTC_base        (0x8002C000)
#define SEJ_base        (0x8002D000)
#define I2C3_base       (0x8002E000)
#define IRDA_base       (0x8002F000)
#define NFIECC_base     (0x80038000)
#define APMCUSYS_CONFIG (0x80039000)
#define AP2MD_base      (0x8003A000)
#define APVFE_base      (0x8003B000)
#define APSLP_base      (0x8003C000)
#define AUXADC_base     (0x8003D000)
#define XGPT_base       (0x8003E000)
#define MSDC3_base      (0x8003F000)
#define PLL_base        (0x80060000)

#define DPI_base        (0x80130000)
#define DSI_base        (0x80140000)
#define GMC1_base       (0x80080000)
#define G2D_base        (0x80081000)
#define GCMQ_base       (0x80082000)
#define GIFDEC_base     (0x80083000)
#define IMGDMA_base     (0x80084000)
#define PNGDEC_base     (0x80085000)
#define MP4_DBLK_base   (0x80086000)
#define SPI_base        (0x80087000)
#define TVCON_base      (0x80088000)
#define TVENC_base      (0x80089000)
#define TVENC_base      (0x80089000)
#define TVCON_base      (0x80088000)
#define CAM_base_0      (0x8008A000)
#define CAB_base_1      (0x8008B000)
#define IMG_base        (0x8008C000)
#define PRZ_base        (0x8008D000)
#define CRZ_base        (0x8008E000)
#define DRZ_base        (0x8008F000)
#define ASM_base        (0x80090000)
#define WT_base         (0x80091000)
#define AFE_base        (0x80092000)
#define GMC2_base       (0x800A0000)
#define JPEG_base       (0x800A1000)
#define M3D_base        (0x800A2000)
#define MP4_base        (0x800C0000)
#define H264_base       (0x800C1000)


#define MD_ONLY_EMI_SD_base (0xF1000000)
#define TDMA_SD_base       (0xF11F0000)   /* TDMA Timer */
#define GCU_SD_base        (0xF2080000)   /* GPRS Crypto Unit */
#define PATCH_SD_base      (0xF20E0000)   /* DSP patch unit */
#define SHARE2_SD_base     (0xF20C0000)
#define SHARE1_SD_base     (0xF20A0000)   /* DSP to CPU interrupt control (shared register) */
#define SHAREG1_SD_base    (0xF1190000)   /* share register 1 */
#define SHAREG2_SD_base    (0xF11E0000)

#define LCD_SD_base        (0x80120000)
#define USB_SD_base        (0x80100000)
#define CSD_ACC_SD_base    (0xF2090000)   /* CSD_ACC */
#define FCS_SD_base        (0xF2070000)   /* FCS Unit */
#define MDMCUSYS_SD_base   (0xF11C0000)

#define DIVIDER_SD_base    (0xF2060000)
#define MD2GCONFG_SD_base  (0xF2000000)
#define AFC_SD_base        (0xF1200000)
#define BSI_SD_base        (0xF2010000)   /* Baseband Serial Interface */
#define BPI_SD_base        (0xF2020000)   /* Baseband Parallel Interface */
#define APC_SD_base        (0xF2040000)   /* TX Power Control */
#define BFE_SD_base        (0xF2100000)   /* Base-band Front End */
#define MIXED_SD_base      (0xF3010000)   /* Analog Chip Interface Controller */
#define DPRAM_CPU_SD_base  (0xF0000000)   /* MCU/DSP Sherif*/
#define DPRAM2_CPU_SD_base (0xF1000000)   /* MCU/DSP Sherif*/
#define IDMA_SD_base       (0xF2000000)
#define IDMA2_SD_base      (0xF3000000)

#define CONFIG_SD_base     (0x80001000)   /* Config registers  (Clk, Power Down, Ver) */
#define RGU_SD_base        (0x80003000)   /* Reset Generation Unit */
#define EMI_SD_base        (0x80020000)
#define CIRQ_SD_base       (0x80021000)   /* IRQ Controller */
#define DMA_SD_base        (0x80022000)   /* DMA Controller */
#define UART1_ori_SD_base  (0x80023000)   /* UART / SIR IrDA */
#define UART2_ori_SD_base  (0x80024000)   /* UART / SIR IrDA 2 */
#define UART3_ori_SD_base  (0x80025000)   /* UART3 */
#define GPIO_SD_base       (0x80002000)   /* GPIO */

#define UART1_SD_base      (0x80023000)   /* UART / SIR IrDA */
#define UART2_SD_base      (0x80024000)   /* UART / SIR IrDA 2 */
#define UART3_SD_base      (0x80025000)   /* UART3 */

#define GPT_SD_base        (0x80026000)   /* General Purpose Timer */
#define SIM_SD_base        (0x80033000)
#define NFI_SD_base        (0x80032000)   /* NAND Flash Interface */
#define ECC_SD_base        (0x80038000)
#define CCIF_SD_base       (0x80036000)   /* Cross Core Interface */
#define KP_SD_base         (0x80028000)
#define PWM_SD_base        (0x80029000)
#define UART4_SD_base      (0x8002B000)
#define RTC_SD_base        (0x8002C000)
#define SEJ_SD_base        (0x8002D000)
#define I2C3_SD_base       (0x8002E000)
#define IRDA_SD_base       (0x8002F000)
#define NFIECC_SD_base     (0x80038000)
#define APMCUSYS_CONFIG (0x80039000)
#define AP2MD_SD_base      (0x8003A000)
#define APVFE_SD_base      (0x8003B000)
#define APSLP_SD_base      (0x8003C000)
#define AUXADC_SD_base     (0x8003D000)
#define XGPT_SD_base       (0x8003E000)
#define MSDC3_SD_base      (0x8003F000)
#define PLL_SD_base        (0x80060000)

#define DPI_SD_base        (0x80130000)
#define DSI_SD_base        (0x80140000)
#define GMC1_SD_base       (0x80080000)
#define G2D_SD_base        (0x80081000)
#define GCMQ_SD_base       (0x80082000)
#define GIFDEC_SD_base     (0x80083000)
#define IMGDMA_SD_base     (0x80084000)
#define PNGDEC_SD_base     (0x80085000)
#define MP4_DBLK_SD_base   (0x80086000)
#define SPI_SD_base        (0x80087000)
#define TVCON_SD_base      (0x80088000)
#define TVENC_SD_base      (0x80089000)
#define TVENC_SD_base      (0x80089000)
#define TVCON_SD_base      (0x80088000)
#define CAM_SD_base_0      (0x8008A000)
#define CAB_SD_base_1      (0x8008B000)
#define IMG_SD_base        (0x8008C000)
#define PRZ_SD_base        (0x8008D000)
#define CRZ_SD_base        (0x8008E000)
#define DRZ_SD_base        (0x8008F000)
#define ASM_SD_base        (0x80090000)
#define WT_SD_base         (0x80091000)
#define AFE_SD_base        (0x80092000)
#define GMC2_SD_base       (0x800A0000)
#define JPEG_SD_base       (0x800A1000)
#define M3D_SD_base        (0x800A2000)
#define MP4_SD_base        (0x800C0000)
#define H264_SD_base       (0x800C1000)


#endif  /* __REG_BASE_MT6516_H__ */
