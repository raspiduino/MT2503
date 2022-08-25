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
 *   reg_base_mt6270A.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __REG_BASE_MT6270A_H__
#define __REG_BASE_MT6270A_H__

#define AP_CONFIG_base       (0x61000000)
#define AP_EMI_base          (0x61010000)
#define AP_CIRQ_base         (0x61020000)
#define AP_DMA_base          (0x61030000)
#define AP_GPT_base          (0x61040000)
#define AP_RGU_base          (0x61050000)
#define AP_MDIF_base         (0x61080000)
#define CONFIG_base          (0x71000000)
#define EMI_base             (0x71010000)
#define CIRQ_base            (0x71020000)
#define DMA_base             (0x71030000)
#define GPT_base             (0x71040000)
#define RGU_base             (0x71050000)
#define GPIO_base            (0x71060000)
#define CCIF_base            (0x71070000)
#define MDIF_base            (0x71080000)
#define CSDBG_base           (0x71090000)
#define UART1_base           (0x710A0000)
#define UART2_base           (0x710B0000)
#define UART3_base           (0x710C0000)
#define RTC_base             (0x710D0000)
#define NFI_base             (0x710E0000)
#define KP_base              (0x710F0000)
#define SIM_base             (0x71100000)
#define SIM2_base            (0x71110000)
//#define DIVIDER_base       (0x71120000)
#define FLEXL2_base          (0x71130000)
#define MIXED_base           (0x71140000)
#define AP_CCIF_base         (0x71150000)
#define EMUIF_base           (0x71160000)
#define LOG_base           (0x71170000)
#define LCD_base             (0x72000000) 
#define USB_base             (0x74000000) 
#define HSL_base             (0x81000000)
#define BF_CIRQ_base         (0x81020000)
#define BF_DMA_base          (0x81030000)
#define BF_GPT_base          (0x81040000)

#define BFMDIF_base          (0x42000000)
#define TX_LOCAL_base        (0xA80B0000)
#define EQRAM2_base          (0xA8100000)
#define RXBUF_base           (0xA8200000)
#define DEINTBUF_base        (0xA8400000)

#define FCS_base             (0xA8800000)
#define CSD_ACC_base         (0xA8810000)
#define GCU_base             (0xA8820000)
#define DIVIDER_base         (0xA8830000)
#define BFE_base             (0xA8840000)
#define FPGA_CONFIG_base     (0xA8850000)

//#define TDMA_base        (0xB8860000)
//#define TDMA_base        (0xB8000000)   //F3 TDMA module (temp)
#define TDMA_base          (0xA8860000)   //F2 2G TDMA
//#define BSI_base           (0xB8870000)
//#define BPI_base           (0xB8880000)
#define APC_base           (0xA8890000)
//#define AFC_base           (0xB88A0000)
#define SHARE_T1T2T3_base    (0xA88B0000)
#define GCC_base             (0xA88C0000)
#define DEINT_DMA_base       (0xA88D0000)
#define TOPSM_base           (0xA88E0000)
#define ACIF_base            (0xAFFF0000)

// redirect to dummy //////////////////
#define SHARE_base           (0xA0000000)
#define PATCH_base           (0xA0000000)
#define SHARE2_base          (0xA0000000)
#define PATCH2_base          (0xA0000000)
#define AFE_base             (0xA0000000)
#define DPRAM_CPU_base       (0xA0000000)
#define DPRAM2_CPU_base      (0xA0000000)
#define MD2GCONFG_base       (0xA8850000)
///////////////////////////////////////

#define RTR_base             (0xB0000000)
#define TXBRP_base           (0xB0010000)
#define TXCRP_base           (0xB0020000)
#define SRCHR_base           (0xB0030000)
#define RXBFE_base           (0xB0070000)
#define UTXBRP_base          (0xB0080000)
#define TXUPC_base           (0xB0090000)
#define BITCP_base           (0xB00B0000)
#define F8F9_base            (0xB0050000)
#define F8F9_1_base          (0xB0060000)
#define F8F9_2_base          (0xB00C0000)
#define LPBK_base            (0xB00F0000)
#define FPGA_DMA_base        (0xB0100000)

#define FPGA_TDMA_base       (0xB8000000)  /* F3 (Reserved) */
#define BPI_base             (0xB8010000) 
#define BSI_base             (0xB8020000) 
#define AFC_base             (0xB8030000) 
#define AUXADC_base          (0xB8040000)
#define FPGA_UART1_base      (0xB8080000)
#define FPGA_UART2_base      (0xB8090000)
#define FRC_base             (0xB80A0000)

#define RXSRP_base           (0xC0000000)
#define RAKE_base            (0xC0010000)
#define RXBRP_base           (0xC0020000)
#define HRXBRP_base          (0xC0030000)
#define F4_LPBK_base         (0xC0050000)

#define HSDPA_base           (0xD0000000)
#define HSDPA1_base          (0xD0010000)
#define HSUPA_base           (0xB80B0000)
///////////////////////////////////////

#define DPA_RLC_base         (0xD0090000)
#define DPA_MAC_base         (0xD0080000)
#define UPA_base             (0xB80B0000)


#define AP_CONFIG_SD_base       (0x61000000)
#define AP_EMI_SD_base          (0x61010000)
#define AP_CIRQ_SD_base         (0x61020000)
#define AP_DMA_SD_base          (0x61030000)
#define AP_GPT_SD_base          (0x61040000)
#define AP_RGU_SD_base          (0x61050000)
#define AP_MDIF_SD_base         (0x61080000)
#define CONFIG_SD_base          (0x71000000)
#define EMI_SD_base             (0x71010000)
#define CIRQ_SD_base            (0x71020000)
#define DMA_SD_base             (0x71030000)
#define GPT_SD_base             (0x71040000)
#define RGU_SD_base             (0x71050000)
#define GPIO_SD_base            (0x71060000)
#define CCIF_SD_base            (0x71070000)
#define MDIF_SD_base            (0x71080000)
#define CSDBG_SD_base           (0x71090000)
#define UART1_SD_base           (0x710A0000)
#define UART2_SD_base           (0x710B0000)
#define UART3_SD_base           (0x710C0000)
#define RTC_SD_base             (0x710D0000)
#define NFI_SD_base             (0x710E0000)
#define KP_SD_base              (0x710F0000)
#define SIM_SD_base             (0x71100000)
#define SIM2_SD_base            (0x71110000)
//#define DIVIDER_SD_base       (0x71120000)
#define FLEXL2_SD_base          (0x71130000)
#define MIXED_SD_base           (0x71140000)
#define AP_CCIF_SD_base         (0x71150000)
#define EMUIF_SD_base           (0x71160000)
#define LOG_SD_base             (0x71170000)
#define LCD_SD_base             (0x72000000) 
#define USB_SD_base             (0x74000000) 
#define HSL_SD_base             (0x81000000)
#define BF_CIRQ_SD_base         (0x81020000)
#define BF_DMA_SD_base          (0x81030000)
#define BF_GPT_SD_base          (0x81040000)

#define BFMDIF_SD_base          (0x42000000)
#define TX_LOCAL_SD_base        (0xA80B0000)
#define EQRAM2_SD_base          (0xA8100000)
#define RXBUF_SD_base           (0xA8200000)
#define DEINTBUF_SD_base        (0xA8400000)

#define FCS_SD_base             (0xA8800000)
#define CSD_ACC_SD_base         (0xA8810000)
#define GCU_SD_base             (0xA8820000)
#define DIVIDER_SD_base         (0xA8830000)
#define BFE_SD_base             (0xA8840000)
#define FPGA_CONFIG_SD_base     (0xA8850000)

//#define TDMA_SD_base        (0xB8860000)
//#define TDMA_SD_base        (0xB8000000)   //F3 TDMA module (temp)
#define TDMA_SD_base          (0xA8860000)   //F2 2G TDMA
//#define BSI_SD_base           (0xB8870000)
//#define BPI_SD_base           (0xB8880000)
#define APC_SD_base           (0xA8890000)
//#define AFC_SD_base           (0xB88A0000)
#define SHARE_T1T2T3_SD_base    (0xA88B0000)
#define GCC_SD_base             (0xA88C0000)
#define DEINT_DMA_SD_base       (0xA88D0000)
#define TOPSM_SD_base           (0xA88E0000)
#define ACIF_SD_base            (0xAFFF0000)

// redirect to dummy //////////////////
#define SHARE_SD_base           (0xA0000000)
#define PATCH_SD_base           (0xA0000000)
#define SHARE2_SD_base          (0xA0000000)
#define PATCH2_SD_base          (0xA0000000)
#define AFE_SD_base             (0xA0000000)
#define DPRAM_CPU_SD_base       (0xA0000000)
#define DPRAM2_CPU_SD_base      (0xA0000000)
#define MD2GCONFG_SD_base       (0xA8850000)
///////////////////////////////////////

#define RTR_SD_base             (0xB0000000)
#define TXBRP_SD_base           (0xB0010000)
#define TXCRP_SD_base           (0xB0020000)
#define SRCHR_SD_base           (0xB0030000)
#define RXBFE_SD_base           (0xB0070000)
#define UTXBRP_SD_base          (0xB0080000)
#define TXUPC_SD_base           (0xB0090000)
#define BITCP_SD_base           (0xB00B0000)
#define F8F9_SD_base            (0xB0050000)
#define F8F9_1_SD_base          (0xB0060000)
#define F8F9_2_SD_base          (0xB00C0000)
#define LPBK_SD_base            (0xB00F0000)
#define FPGA_DMA_SD_base        (0xB0100000)

#define FPGA_TDMA_SD_base       (0xB8000000)  /* F3 (Reserved) */
#define BPI_SD_base             (0xB8010000) 
#define BSI_SD_base             (0xB8020000) 
#define AFC_SD_base             (0xB8030000) 
#define AUXADC_SD_base          (0xB8040000)
#define FPGA_UART1_SD_base      (0xB8080000)
#define FPGA_UART2_SD_base      (0xB8090000)
#define FRC_SD_base             (0xB80A0000)

#define RXSRP_SD_base           (0xC0000000)
#define RAKE_SD_base            (0xC0010000)
#define RXBRP_SD_base           (0xC0020000)
#define HRXBRP_SD_base          (0xC0030000)
#define F4_LPBK_SD_base         (0xC0050000)

#define HSDPA_SD_base           (0xD0000000)
#define HSDPA1_SD_base          (0xD0010000)
#define HSUPA_SD_base           (0xB80B0000)
///////////////////////////////////////

#define DPA_RLC_SD_base         (0xD0090000)
#define DPA_MAC_SD_base         (0xD0080000)
#define UPA_SD_base             (0xB80B0000)


#endif  /* __REG_base_MT6270A_H__ */

