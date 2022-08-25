/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   snand_hw.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   SPI-NAND Flash driver version 2
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __SNAND_HW_H__
#define __SNAND_HW_H__

#include "reg_base.h"
#include "kal_general_types.h"

#ifdef __cplusplus
     extern "C" {
#endif

typedef volatile kal_uint8 *    SNAND_P_U8;
typedef volatile kal_int8 *     SNAND_P_S8;
typedef volatile kal_uint16 *   SNAND_P_U16;
typedef volatile kal_int16 *    SNAND_P_S16;
typedef volatile kal_uint32 *   SNAND_P_U32;
typedef volatile kal_int32 *    SNAND_P_S32;

// Standard Commands
#define SNAND_CMD_BLOCK_ERASE               (0xD8)
#define SNAND_CMD_GET_FEATURES              (0x0F)
#define SNAND_CMD_FEATURES_BLOCK_LOCK       (0xA0)
#define SNAND_CMD_FEATURES_OTP              (0xB0)
#define SNAND_CMD_FEATURES_STATUS           (0xC0)
#define SNAND_CMD_PAGE_READ                 (0x13)
#define SNAND_CMD_PROGRAM_EXECUTE           (0x10)
#define SNAND_CMD_PROGRAM_LOAD              (0x02)
#define SNAND_CMD_PROGRAM_LOAD_X4           (0x32)
#define SNAND_CMD_PROGRAM_RANDOM_LOAD       (0x84)
#define SNAND_CMD_PROGRAM_RANDOM_LOAD_X4    (0xC4)
#define SNAND_CMD_READ_ID                   (0x9F)
#define SNAND_CMD_RANDOM_READ               (0x03)
#define SNAND_CMD_RANDOM_READ_SPIQ          (0x6B)
#define SNAND_CMD_SET_FEATURES              (0x1F)

#define SNAND_CMD_SW_RESET                  (0xFF)
#define SNAND_CMD_WRITE_ENABLE              (0x06)
#define SNAND_FLASH_ID_LENGTH               (2)   // The number of bytes for JEDEC ID

// Status register
#define SNAND_STATUS_OIP                    (0x01)
#define SNAND_STATUS_WEL                    (0x02)
#define SNAND_STATUS_ERASE_FAIL             (0x04)
#define SNAND_STATUS_PROGRAM_FAIL           (0x08)
#define SNAND_STATUS_TOO_MANY_ERROR_BITS    (0x20)
#define SNAND_STATUS_ERROR_BITS_CORRECTED   (0x10)
#define SNAND_STATUS_ERROR_BITS_CORRECTED_FULL   (0x30)
#define SNAND_STATUS_ECC_STATUS_MASK        (0x30)
#define SNAND_STATUS_ERROR_BITS_CORRECTED   (0x10)

// OTP register
#define SNAND_OTP_ECC_ENABLE                (0x10)
#define SNAND_OTP_QE                        (0x01)

// Block lock register
#define SNAND_BLOCK_LOCK_BITS               (0x3E)

// SNF registers
#define RW_SNAND_MAC_CTL              ((SNAND_P_U32)(SNF_base + 0x0500))
#define RW_SNAND_MAC_OUTL             ((SNAND_P_U32)(SNF_base + 0x0504))
#define RW_SNAND_MAC_INL              ((SNAND_P_U32)(SNF_base + 0x0508))

#define RW_SNAND_RD_CTL1              ((SNAND_P_U32)(SNF_base + 0x050C))
#define RW_SNAND_RD_CTL2              ((SNAND_P_U32)(SNF_base + 0x0510))
#define RW_SNAND_RD_CTL3              ((SNAND_P_U32)(SNF_base + 0x0514))

#define RW_SNAND_GF_CTL1              ((SNAND_P_U32)(SNF_base + 0x0518))
#define RW_SNAND_GF_CTL3              ((SNAND_P_U32)(SNF_base + 0x0520))

#define RW_SNAND_PG_CTL1              ((SNAND_P_U32)(SNF_base + 0x0524))
#define RW_SNAND_PG_CTL2              ((SNAND_P_U32)(SNF_base + 0x0528))
#define RW_SNAND_PG_CTL3              ((SNAND_P_U32)(SNF_base + 0x052C))

#define RW_SNAND_ER_CTL               ((SNAND_P_U32)(SNF_base + 0x0530))
#define RW_SNAND_ER_CTL2              ((SNAND_P_U32)(SNF_base + 0x0534))

#define RW_SNAND_MISC_CTL             ((SNAND_P_U32)(SNF_base + 0x0538))
#define RW_SNAND_MISC_CTL2            ((SNAND_P_U32)(SNF_base + 0x053C))

#define RW_SNAND_DLY_CTL1             ((SNAND_P_U32)(SNF_base + 0x0540))
#define RW_SNAND_DLY_CTL2             ((SNAND_P_U32)(SNF_base + 0x0544))
#define RW_SNAND_DLY_CTL3             ((SNAND_P_U32)(SNF_base + 0x0548))
#define RW_SNAND_DLY_CTL4             ((SNAND_P_U32)(SNF_base + 0x054C))

#define RW_SNAND_STA_CTL1             ((SNAND_P_U32)(SNF_base + 0x0550))

#define RW_SNAND_GPRAM_DATA           ((SNAND_P_U32)(SNF_base + 0x0800))

// RW_SNAND_DLY_CTL2
#define SNAND_SFIO0_IN_DLY_MASK       (0x0000003F)
#define SNAND_SFIO1_IN_DLY_MASK       (0x00003F00)
#define SNAND_SFIO2_IN_DLY_MASK       (0x003F0000)
#define SNAND_SFIO3_IN_DLY_MASK       (0x3F000000)

// RW_SNAND_DLY_CTL3
#define SNAND_SFCK_OUT_DLY_MASK       (0x00003F00)
#define SNAND_SFCK_OUT_DLY_OFFSET     (8)
#define SNAND_SFCK_SAM_DLY_MASK       (0x0000003F)
#define SNAND_SFCK_SAM_DLY_OFFSET     (0)
#define SNAND_SFIFO_WR_EN_DLY_SEL_MASK (0x3F000000)

// RW_SNAND_RD_CTL1
#define SNAND_PAGE_READ_CMD_OFFSET    (24)
#define SNAND_PAGE_READ_ADDRESS_MASK  (0x00FFFFFF)

// RW_SNAND_RD_CTL2
#define SNAND_DATA_READ_DUMMY_OFFSET  (8)
#define SNAND_DATA_READ_CMD_MASK      (0x000000FF)

// RW_SNAND_RD_CTL3
#define SNAND_DATA_READ_ADDRESS_MASK  (0x0000FFFF)

// RW_SNAND_MISC_CTL
#define SNAND_DATA_READ_MODE_X1       (0x0)
#define SNAND_DATA_READ_MODE_X4       (0x2)
#define SNAND_CLK_INVERSE             (0x20)
#define SNAND_SAMPLE_CLK_INVERSE      (1 << 22)
#define SNAND_4FIFO_EN                (1 << 24)
#define SNAND_DATA_READ_MODE_OFFSET   (16)
#define SNAND_DATA_READ_MODE_MASK     (0x00070000)
#define SNAND_FIFO_RD_LTC_MASK        (0x06000000)
#define SNAND_FIFO_RD_LTC_OFFSET      (25)
#define SNAND_FIFO_RD_LTC_0           (0)
#define SNAND_FIFO_RD_LTC_2           (2)
#define SNAND_PG_LOAD_X4_EN           (1 << 20)
#define SNAND_DATARD_CUSTOM_EN        (0x00000040)
#define SNAND_PG_LOAD_CUSTOM_EN       (0x00000080)
#define SNAND_SW_RST                  (0x10000000)
#define SNAND_LATCH_LAT_MASK          (0x00000300)
#define SNAND_LATCH_LAT_OFFSET        (8)

// RW_SNAND_MISC_CTL2
#define SNAND_PROGRAM_LOAD_BYTE_LEN_OFFSET    (16)
#define SNAND_READ_DATA_BYTE_LEN_OFFSET       (0)

// RW_SNAND_PG_CTL1
#define SNAND_PG_EXE_CMD_OFFSET               (16)
#define SNAND_PG_LOAD_CMD_OFFSET              (8)
#define SNAND_PG_WRITE_EN_CMD_OFFSET          (0)

// RW_SNAND_PG_CTL2
#define SNAND_PG_LOAD_CMD_DUMMY_OUT_OFFSET    (12)
#define SNAND_PG_LOAD_ADDR_MASK               (0x0000FFFF)

// RW_SNAND_GF_CTL1
#define SNAND_GF_STATUS_MASK          (0x000000FF)

// RW_SNAND_GF_CTL3
#define SNAND_GF_LOOP_LIMIT_MASK      (0x000F0000)
#define SNAND_GF_POLLING_CYCLE_MASK   (0x0000FFFF)
#define SNAND_GF_LOOP_LIMIT_OFFSET    (16)

// RW_SNAND_STA_CTL1
#define SNAND_AUTO_BLKER              (0x01000000)
#define SNAND_AUTO_READ               (0x02000000)
#define SNAND_AUTO_PROGRAM            (0x04000000)
#define SNAND_CUSTOM_READ             (0x08000000)
#define SNAND_CUSTOM_PROGRAM          (0x10000000)

// RW_SNAND_MAC_CTL
#define SNAND_WIP                     (0x00000001)  // b0
#define SNAND_WIP_READY               (0x00000002)  // b1
#define SNAND_TRIG                    (0x00000004)  // b2
#define SNAND_MAC_EN                  (0x00000008)  // b3
#define SNAND_MAC_SIO_SEL             (0x00000010)  // b4

// RW_SNAND_DIRECT_CTL
#define SNAND_QPI_EN                  (0x00000001)  // b0
#define SNAND_CMD1_EXTADDR_EN         (0x00000002)  // b1
#define SNAND_CMD2_EN                 (0x00000004)  // b2
#define SNAND_CMD2_EXTADDR_EN         (0x00000008)  // b3
#define SNAND_DR_MODE_MASK            (0x00000070)  // b4~b6
#define SNAND_NO_RELOAD               (0x00000080)  // b7
#define SNAND_DR_CMD2_DUMMY_CYC_MASK  (0x00000F00)  // b8~b11
#define SNAND_DR_CMD1_DUMMY_CYC_MASK  (0x0000F000)  // b12~b15
#define SNAND_DR_CMD2_DUMMY_CYC_OFFSET         (8)
#define SNAND_DR_CMD1_DUMMY_CYC_OFFSET        (12)
#define SNAND_DR_CMD2_MASK            (0x00FF0000)  // b16~b23
#define SNAND_DR_CMD1_MASK            (0xFF000000)  // b24~b31
#define SNAND_DR_CMD2_OFFSET                  (16)
#define SNAND_DR_CMD1_OFFSET                  (24)

// RW_SNAND_ER_CTL
#define SNAND_ER_CMD_OFFSET                    (8)
#define SNAND_ER_CMD_MASK             (0x0000FF00)
#define SNAND_AUTO_ERASE_TRIGGER      (0x00000001)

// RW_SNAND_GF_CTL3
#define SNAND_LOOP_LIMIT_OFFSET               (16)
#define SNAND_LOOP_LIMIT_MASK         (0x000F0000)
#define SNAND_LOOP_LIMIT_NO_LIMIT            (0xF)
#define SNAND_POLLING_CYCLE_MASK      (0x0000FFFF)

// SFI Non-Volitile Register
#define SNAND_WDT_DEV_BUSY              0x00000001    // (b0)
#define SNAND_WDT_DEV_SUSPEND           0x00000002    // (b1)
#define SNAND_WDT_DEV_WAIT_TIME_MASK    0x0000F000    // (b15-b12)
#define SNAND_WDT_GET_DEV_WAIT_TIME(a)  (((a)&SNAND_WDT_DEV_WAIT_TIME_MASK)>>12)

// NFI registers
#define RW_NFI_CNFG                     ((SNAND_P_U16)(NFI_base + 0x0000))
#define RW_NFI_PAGEFMT                  ((SNAND_P_U16)(NFI_base + 0x0004))
#define RW_NFI_CON                      ((SNAND_P_U16)(NFI_base + 0x0008))
#define RW_NFI_INTR_EN                  ((SNAND_P_U16)(NFI_base + 0x0010))
#define RW_NFI_INTR                     ((SNAND_P_U16)(NFI_base + 0x0014))
#define RW_NFI_CMD                      ((SNAND_P_U16)(NFI_base + 0x0020))
#define RW_NFI_STA                      ((SNAND_P_U32)(NFI_base + 0x0060))
#define RW_NFI_STRADDR                  ((SNAND_P_U32)(NFI_base + 0x0080))
#define RW_NFI_BYTELEN                  ((SNAND_P_U16)(NFI_base + 0x0084))
#define RW_NFI_MASTERSTA                ((SNAND_P_U16)(NFI_base + 0x0224))
#define RW_NFI_SPIDMA                   ((SNAND_P_U32)(NFI_base + 0x022C))

// RW_NFI_BYTELEN
#define NFI_BUS_SEC_CNTR_MASK           (0xF000)
#define NFI_BUS_SEC_CNTR_OFFSET         (12)

// RW_NFI_STA
#define NFI_STA_NAND_FSM_MASK           (0x1F000000)
#define NFI_STA_NFI_FSM_MASK            (0x000F0000)

// RW_NFI_MASTERSTA
#define NFI_MASTERSTA_MASK              (0x0FFF)

// RW_NFI_INTR
#define NFI_AHB_DONE                    (0x00000040)

// RW_NFI_INTR_EN
#define NFI_AHB_DONE_EN                 (0x00000040)
#define NFI_CUSTOM_PROG_DONE_INTR_EN    (0x00000080)
#define NFI_CUSTOM_READ_DONE_INTR_EN    (0x00000100)
#define NFI_AUTO_PROG_INTR_EN           (0x00000200)
#define NFI_AUTO_READ_INTR_EN           (0x00000400)
#define NFI_AUTO_BLKER_INTR_EN          (0x00000800)

// RW_NFI_SPIDMA
#define NFI_SPIDMA_SEC_EN               (0x00010000)
#define NFI_SPIDMA_SEC_SIZE_MASK        (0x0000FFFF)

// RW_NFI_CMD
#define NFI_CMD_DUMMY_PG                (0x80)
#define NFI_CMD_DUMMY_RD                (0x00)

// RW_NFI_CNFG
#define NFI_DMA_MODE                    (0x00000001)
#define NFI_READ_MODE_OFFSET            (1)
#define NFI_READ_MODE_RAM_TO_FLASH      (0)
#define NFI_READ_MODE_FLASH_TO_RAM      (1)
#define NFI_DMA_BURST_EN                (0x00000004)
#define NFI_OP_MODE_OFFSET              (12)
#define NFI_OP_MODE_PROGRAM_PROCESS     (0x3)
#define NFI_OP_MODE_CUSTOM_PROCESS      (0x6)

// RW_NFI_CON
#define NFI_FIFO_FLUSH                  (0x00000001)
#define NFI_RST                         (0x00000002)
#define NFI_SEC_NUM_OFFSET              (12)
#define NFI_BRD                         (0x0100)
#define NFI_BWR                         (0x0200)

// RW_NFI_PAGEFMT
#define NFI_PAGE_SIZE_2K                (0x00000001)
#define NFI_SPARE_SIZE_OFFSET           (4)
#define NFI_SPARE_SIZE_16B              (0)

// GPIO Driving Registers
#if defined(MT6260)
    #define RW_GPIO_DRV0      ((SNAND_P_U16)(GPIO_base + 0x800))
#endif

#ifdef __cplusplus
}
#endif

#endif  // __SNAND_HW_H__

