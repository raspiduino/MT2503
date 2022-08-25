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
 *   reg_base_mt6268h.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __REG_BASE_MT6268H_H__
#define __REG_BASE_MT6268H_H__

#define DPRAM_CPU_base           (0x50000000)
#define DPRAM2_CPU_base          (0x58000000)
#define IDMA_base                (0x60000000)
#define IDMA2_base               (0x68000000)
#define USB_base		         (0x70000000)
#define CONFIG_base              (0x80000000)
#define EMI_base                 (0x80010000)
#define CIRQ_base                (0x80020000)
#define DMA_base                 (0x80030000)
#define RGU_base                 (0x80040000)
#define L2C_base                 (0x80050000)
#define GCU_base                 (0x80060000)
#define SWDBG_base               (0x80070000)
#define NFI_base                 (0x80090000)
#define SCCB_base                (0x800a0000)
#define GPT_base                 (0x80100000)
#define KP_base                  (0x80110000)
#define GPIO_base                (0x80120000)
#define UART1_base               (0x80130000)
#define SIM_base                 (0x80140000)
#define PWM_base                 (0x80150000)
#define ETM_base                 (0x80170000)
#define LCD_base                 (0x90000000)
#define UART2_base               (0x80180000)
#define PFC_base                 (0x80190000)
#define UART3_base               (0x801b0000)
#define B2PSI_base               (0X801c0000)
#define TDMA_base                (0x80200000)
#define RTC_base                 (0x80210000)
#define BPI_base                 (0xB8010000)
#define BSI_base                 (0xB8020000)
#define AFC_base                 (0xB8030000)
#define APC_base                 (0x80250000)
#define FCS_base                 (0x80260000)
#define AUXADC_base              (0xB8040000)
#define DIVIDER_base             (0x80280000)
#define CSD_ACC_base             (0x80290000)
#define MSDC_base                (0x802a0000)
#define SHARE_base               (0x80300000)
#define PATCH_base               (0x80310000)
#define SHARE2_base              (0x80320000)
#define PATCH2_base              (0x80330000)
#define AFE_base                 (0x80400000)
#define BFE_base                 (0x80410000)
#define MIXED_base               (0x80500000)
#define JPEG_CODEC_base          (0x80600000)
#define RESIZER_base             (0x80610000)
#define L1C_base                 (0x80700000)
#define FPGA_TDMA_base           (0xB8000000)
#define FPGA_DMA_base            (0xB0100000)
#define FPGA_UART1_base          (0xB8080000)
#define FPGA_UART2_base          (0xB8090000)
#define RTR_base                 (0xB0000000)
#define TXBRP_base               (0xB0010000)
#define TXCRP_base               (0xB0020000)
#define SRCHR_base               (0xB0030000)
#define RXBFE_base               (0xB0070000)
#define RXBRP_base               (0xC0020000)
#define BITCP_base               (0xB00B0000)
#define F8F9_base                (0xB00C0000)
#define RXSRP_base               (0xC0000000)
#define RAKE_base                (0xC0010000)
#define LPBK_base                (0xB00F0000)
#define F4_LPBK_base             (0xC0050000)
#define HRXBRP_base              (0xC0030000)
#define HSDPA_base               (0xD0000000)
#define HSDPA1_base              (0xD0010000)


#define DPRAM_CPU_SD_base           (0x50000000)
#define DPRAM2_CPU_SD_base          (0x58000000)
#define IDMA_SD_base                (0x60000000)
#define IDMA2_SD_base               (0x68000000)
#define USB_SD_base		            (0x70000000)
#define CONFIG_SD_base              (0x80000000)
#define EMI_SD_base                 (0x80010000)
#define CIRQ_SD_base                (0x80020000)
#define DMA_SD_base                 (0x80030000)
#define RGU_SD_base                 (0x80040000)
#define L2C_SD_base                 (0x80050000)
#define GCU_SD_base                 (0x80060000)
#define SWDBG_SD_base               (0x80070000)
#define NFI_SD_base                 (0x80090000)
#define SCCB_SD_base                (0x800a0000)
#define GPT_SD_base                 (0x80100000)
#define KP_SD_base                  (0x80110000)
#define GPIO_SD_base                (0x80120000)
#define UART1_SD_base               (0x80130000)
#define SIM_SD_base                 (0x80140000)
#define PWM_SD_base                 (0x80150000)
#define ETM_SD_base                 (0x80170000)
#define LCD_SD_base                 (0x90000000)
#define UART2_SD_base               (0x80180000)
#define PFC_SD_base                 (0x80190000)
#define UART3_SD_base               (0x801b0000)
#define B2PSI_SD_base               (0X801c0000)
#define TDMA_SD_base                (0x80200000)
#define RTC_SD_base                 (0x80210000)
#define BPI_SD_base                 (0xB8010000)
#define BSI_SD_base                 (0xB8020000)
#define AFC_SD_base                 (0xB8030000)
#define APC_SD_base                 (0x80250000)
#define FCS_SD_base                 (0x80260000)
#define AUXADC_SD_base              (0xB8040000)
#define DIVIDER_SD_base             (0x80280000)
#define CSD_ACC_SD_base             (0x80290000)
#define MSDC_SD_base                (0x802a0000)
#define SHARE_SD_base               (0x80300000)
#define PATCH_SD_base               (0x80310000)
#define SHARE2_SD_base              (0x80320000)
#define PATCH2_SD_base              (0x80330000)
#define AFE_SD_base                 (0x80400000)
#define BFE_SD_base                 (0x80410000)
#define MIXED_SD_base               (0x80500000)
#define JPEG_CODEC_SD_base          (0x80600000)
#define RESIZER_SD_base             (0x80610000)
#define L1C_SD_base                 (0x80700000)
#define FPGA_TDMA_SD_base           (0xB8000000)
#define FPGA_DMA_SD_base            (0xB0100000)
#define FPGA_UART1_SD_base          (0xB8080000)
#define FPGA_UART2_SD_base          (0xB8090000)
#define RTR_SD_base                 (0xB0000000)
#define TXBRP_SD_base               (0xB0010000)
#define TXCRP_SD_base               (0xB0020000)
#define SRCHR_SD_base               (0xB0030000)
#define RXBFE_SD_base               (0xB0070000)
#define RXBRP_SD_base               (0xC0020000)
#define BITCP_SD_base               (0xB00B0000)
#define F8F9_SD_base                (0xB00C0000)
#define RXSRP_SD_base               (0xC0000000)
#define RAKE_SD_base                (0xC0010000)
#define LPBK_SD_base                (0xB00F0000)
#define F4_LPBK_SD_base             (0xC0050000)
#define HRXBRP_SD_base              (0xC0030000)
#define HSDPA_SD_base               (0xD0000000)
#define HSDPA1_SD_base              (0xD0010000)



#endif  /* !__REG_BASE_MT6268H_H__ */

