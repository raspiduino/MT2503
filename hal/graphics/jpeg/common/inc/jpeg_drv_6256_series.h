/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_drv_6256_series.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Driver definition of JPEG codec for MT6256 series chip.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_DRV_6256_SERIES_H__
#define __JPEG_DRV_6256_SERIES_H__

#include "drv_comm.h"
#include "drv_features_jpeg.h"

#if defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)

#include "reg_base.h"
#include "mm_power_ctrl.h"



/***** these defines have been moved to drv_features_jpeg.h ******

////#define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
////#define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__

/// For MT6256 HW JPEG decoder, file address needs 8-bytes alignment.
////#define __DRV_GRAPHICS_HW_JPEG_DECODE_ALWAYS_READ_FILE__

**********************************************************/


#if defined(__DRV_GRAPHICS_JPEG_6256_E2_SERIES__)

/* JPEG codec register offset */
#define REG_JPEG_DEC_FILE_ADDR                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x00)
#define REG_JPEG_DEC_TBLS_START_ADDR                     *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x04)
#define REG_JPEG_DEC_SAMP_FACTOR                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x08)
#define REG_JPEG_DEC_COMP_ID                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x0C)
#define REG_JPEG_DEC_TOTAL_MCU_NUM                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x10)
#define REG_JPEG_DEC_INTLV_MCU_NUM_PER_MCU_ROW           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x14)

#define REG_JPEG_DEC_COMP0_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x18)
#define REG_JPEG_DEC_COMP1_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x1C)
#define REG_JPEG_DEC_COMP2_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x20)
#define REG_JPEG_DEC_NONINTLV_DU_NUM_PER_MCU_ROW(I)      *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x18 + (I << 2))

#define REG_JPEG_DEC_COMP0_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x24)
#define REG_JPEG_DEC_COMP1_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x28)
#define REG_JPEG_DEC_COMP2_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x2C)
#define REG_JPEG_DEC_DATA_UNIT(I)                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x24 + (I << 2))

#define REG_JPEG_DEC_COMP0_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x30)
#define REG_JPEG_DEC_COMP1_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x34)
#define REG_JPEG_DEC_COMP2_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x38)
#define REG_JPEG_DEC_PROGR_COEFF_START_ADDR(I)           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x30 + (I << 2))

#define REG_JPEG_DEC_CTRL                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x3C)
#define REG_JPEG_DEC_TRIG                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x40)
#define REG_JPEG_DEC_RST                                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x44)
#define REG_JEPG_DEC_FILE_BRP                            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x48)
#define REG_JPEG_DEC_FILE_TOTAL_SIZE                     *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x4C)
#define REG_JEPG_DEC_INTLV_FIRST_MCU_INDEX               *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x50)
#define REG_JEPG_DEC_INTLV_LAST_MCU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x54)

#define REG_JEPG_DEC_COMP0_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x58)
#define REG_JEPG_DEC_COMP0_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x5C)
#define REG_JEPG_DEC_COMP1_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x60)
#define REG_JEPG_DEC_COMP1_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x64)
#define REG_JEPG_DEC_COMP2_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x68)
#define REG_JEPG_DEC_COMP2_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x6C)
#define REG_JEPG_DEC_FIRST_DU_INDEX(I)                   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x58 + (I * 8))
#define REG_JEPG_DEC_LAST_DU_INDEX(I)                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x5C + (I * 8))

#define REG_JPEG_DEC_QT_ID                               *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x70)
#define REG_JPEG_DEC_INTERRUPT_STATUS                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x74)
#define REG_JPEG_DEC_STATUS                              *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x78)

#define REG_JPEG_DEC_RANGE_DEC_EN                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x7C)
#define REG_JPEG_DEC_START_IDCT_MCU_ROW_INDEX            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x80)
#define REG_JPEG_DEC_END_IDCT_MCU_ROW_INDEX              *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x84)
#define REG_JPEG_DEC_IDCT_MCU_NUM_PER_ROW                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x88)
#define REG_JPEG_DEC_IDCT_SKIP_MCU_INDEX1                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x8C)
#define REG_JPEG_DEC_IDCT_SKIP_MCU_INDEX2                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x90)
#define REG_JPEG_DEC_MCU_CNT                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x94)
#define REG_JPEG_DEC_IDCT_CNT                            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x98)

/* The following registers are for JPEG encoder */
#define REG_JPEG_ENC_RST                                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x100)
#define REG_JPEG_ENC_CTRL                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x104)
#define REG_JPEG_ENC_QUALITY                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x108)
#define REG_JPEG_ENC_BLK_NUM                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x10C)
#define REG_JPEG_ENC_BLK_CNT                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x110)
#define REG_JPEG_ENC_INTERRUPT_STATUS                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x11C)

/* Notice: The continuous shooting mode is not implemented by driver */
#define REG_JPEG_ENC_DEST_ADDR1                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x120)
#define REG_JPEG_ENC_DMA_ADDR1                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x124)
#define REG_JPEG_ENC_STALL_ADDR1                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x128)

#define REG_JPEG_ENC_DEST_ADDR2                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x12C)
#define REG_JPEG_ENC_DMA_ADDR2                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x130)
#define REG_JPEG_ENC_STALL_ADDR2                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x134)

#define REG_JPEG_ENC_OFFSET_ADDR                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x138)
#define REG_JPEG_ENC_CURR_DMA_ADDR                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x13C)

#define REG_JPEG_ENC_RESTART_INTERVAL                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x150)
#define REG_JPEG_ENC_IMG_DIMENSION                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x154)

#define REG_JPEG_ENC_GULTRA_THRESHOLD                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x158)
#define REG_JPEG_ENC_STOP_INDEX                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x15C)
#define REG_JPEG_ENC_SLOW_DOWN                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x160)
#define REG_JPEG_ENC_DEBUG_INFO0                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x164)
#define REG_JPEG_ENC_DEBUG_INFO1                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x168)
#define REG_JPEG_ENC_DCT_CHK_SUM                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x16C)
#define REG_JPEG_ENC_DCT_STATE                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x170)


/* Definition for power down control */
/*
#define REG_PDN_CON_JPEG   *(PDN_CON3)
#define REG_PDN_CLR_JPEG   *(PDN_CLR3)
#define REG_PDN_SET_JPEG   *(PDN_SET3)

#define REG_PDN_CON_DCT    *(PDN_CON3)
#define REG_PDN_CLR_DCT    *(PDN_CLR3)
#define REG_PDN_SET_DCT    *(PDN_SET3)

#define PDN_CTRL_JPEG_BIT  0x0400
#define PDN_CTRL_DCT_BIT   0x2000
*/


#define REG_MMCG_CON       *(volatile kal_uint32 *)(MMCG_CON0)
#define REG_MMCG_CLR       *(volatile kal_uint32 *)(MMCG_CLR0)
#define REG_MMCG_SET       *(volatile kal_uint32 *)(MMCG_SET0)

#define MMCG_JPEG_ENC_BIT  (MMPWRMGR_JPEG_ENC)
#define MMCG_JPEG_DEC_BIT  (MMPWRMGR_JPEG_DEC)
#define MMCG_DCT_BIT       (MMPWRMGR_DCT)


/* Definition for control bit in REG_JPEG_ENC_CTRL */
#define JPEG_ENC_CTRL_ENABLE_BIT                0x00000001
#define JPEG_ENC_CTRL_INT_EN_BIT                0x00000004
#define JPEG_ENC_CTRL_YUV_BIT                   0x00000018
#define JPEG_ENC_CTRL_FILE_FORMAT_BIT           0x00000020
#define JPEG_ENC_CTRL_FILE_FORMAT_BIT           0x00000020
#define JPEG_ENC_CTRL_SLOW_DOWN_EN_BIT          0x00000040
#define JPEG_ENC_CTRL_GULTRA_EN_BIT             0x00000200
#define JPEG_ENC_CTRL_RST_MARKER_BIT            0x00000400
#define JPEG_ENC_CTRL_BLK_STOP_BIT              0x00000800
#define JPEG_ENC_CTRL_BURST_TYPE_BIT            0x00007000
#define JPEG_ENC_CTRL_SELF_INIT_EN_BIT          0x00010000


/* Definition for file format which will be set into JPEG_ENC_CTRL_FILE_FORMAT_BIT */
#define JPEG_DRV_ENC_FILE_FORMAT_JPEG           0x00
#define JPEG_DRV_ENC_FILE_FORMAT_JFIF_EXIF      (0x01 << 5)


/* Definition for YUV format which will be set into JPEG_ENC_CTRL_YUV_BIT */
#define JPEG_DRV_ENC_YUV400                     (0x02 << 3)
#define JPEG_DRV_ENC_YUV422                     (0x00 << 3)
#define JPEG_DRV_ENC_YUV420                     (0x01 << 3)
#define JPEG_DRV_ENC_YUV411                     (0x03 << 3)


/* Definition for burst type which will be set into JPEG_ENC_CTRL_BURST_TYPE_BIT */
#define JPEG_DRV_ENC_BURST_TYPE_BURST_16        (0x00 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_SINGLE_4        (0x01 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_2         (0x02 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_4         (0x03 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_8         (0x04 << 11)


/* Definition for JPEG interrupt type */
#define JPEG_DRV_ISR_TYPE_NONE                  0x00
#define JPEG_DRV_ISR_TYPE_DEC                   0x01
#define JPEG_DRV_ISR_TYPE_ENC                   0x02


/* Definition for JPEG interrupt status */
#define JPEG_DRV_DEC_INT_STATUS_EOF             0x01
#define JPEG_DRV_DEC_INT_STATUS_BREAKPOINT      0x02
#define JPEG_DRV_DEC_INT_STATUS_FILE_OVERFLOW   0x04
#define JPEG_DRV_DEC_INT_STATUS_RANGE_DECODE    0x08  /// not used

#define JPEG_DRV_DEC_INT_STATUS_IDP_COMPLETE    0x10  /// this bit is not defined in JPEG HW spec.
                                                      /// it is used to indicate that IDP has completed.


/* Definition for encode quality (16 values but only 14 valid levels) */
#define JPEG_DRV_ENC_QUALITY_00_00              0x00  /// Q60
#define JPEG_DRV_ENC_QUALITY_00_01              0x01  /// Q80
#define JPEG_DRV_ENC_QUALITY_00_10              0x02  /// Q90
#define JPEG_DRV_ENC_QUALITY_00_11              0x03  /// Q95
#define JPEG_DRV_ENC_QUALITY_01_00              0x04  /// Q39
#define JPEG_DRV_ENC_QUALITY_01_01              0x05  /// Q68
#define JPEG_DRV_ENC_QUALITY_01_10              0x06  /// Q84
#define JPEG_DRV_ENC_QUALITY_01_11              0x07  /// Q92
#define JPEG_DRV_ENC_QUALITY_10_00              0x08  /// Q48
#define JPEG_DRV_ENC_QUALITY_10_01              0x09  /// Q48
#define JPEG_DRV_ENC_QUALITY_10_10              0x0A  /// Q74
#define JPEG_DRV_ENC_QUALITY_10_11              0x0B  /// Q87
#define JPEG_DRV_ENC_QUALITY_11_00              0x0C  /// Q34
#define JPEG_DRV_ENC_QUALITY_11_01              0x0D  /// Q34
#define JPEG_DRV_ENC_QUALITY_11_10              0x0E  /// Q64
#define JPEG_DRV_ENC_QUALITY_11_11              0x0F  /// Q82


#define JPEG_DRV_ENC_QUALITY_EXCELLENT          JPEG_DRV_ENC_QUALITY_10_11    /// Q87
#define JPEG_DRV_ENC_QUALITY_GOOD               JPEG_DRV_ENC_QUALITY_10_10    /// Q74
#define JPEG_DRV_ENC_QUALITY_FAIR               JPEG_DRV_ENC_QUALITY_00_00    /// Q60
#define JPEG_DRV_ENC_QUALITY_LOW                JPEG_DRV_ENC_QUALITY_10_01    /// Q48
#define JPEG_DRV_ENC_QUALITY_POOR               JPEG_DRV_ENC_QUALITY_11_01    /// Q34


#define JPEG_DRV_DEC_TABLE_ALIGNED_SIZE         4096
#define JPEG_DRV_DEC_TABLE_SIZE                 2048
#define JPEG_DRV_DEC_TABLE_ALIGNMENT            2048
#define JPEG_DRV_DEC_TABLE_ALIGNED_ADDR         0xFFFFF800

// progressive decode buffer size
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MIN       (256 * 1024)
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MAX       (1024 * 1024)


#define JPEG_DRV_ENC_INT_STATUS_DONE   0x01
#define JPEG_DRV_ENC_INT_STATUS_STALL  0x02


#define JPEG_DRV_ENC_RESTART_INTERVAL  5


#define JPEG_HW_DRV_NONE         0x00
#define JPEG_HW_DRV_ENCODER_BIT  0x01
#define JPEG_HW_DRV_DECODER_BIT  0x02

#else  // __DRV_GRAPHICS_JPEG_6256_E2_SERIES__

/* JPEG codec register offset */
#define REG_JPEG_DEC_FILE_ADDR                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x00)
#define REG_JPEG_DEC_TBLS_START_ADDR                     *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x04)
#define REG_JPEG_DEC_SAMP_FACTOR                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x08)
#define REG_JPEG_DEC_COMP_ID                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x0C)
#define REG_JPEG_DEC_TOTAL_MCU_NUM                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x10)
#define REG_JPEG_DEC_INTLV_MCU_NUM_PER_MCU_ROW           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x14)

#define REG_JPEG_DEC_COMP0_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x18)
#define REG_JPEG_DEC_COMP1_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x1C)
#define REG_JPEG_DEC_COMP2_NONINTLV_DU_NUM_PER_MCU_ROW   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x20)
#define REG_JPEG_DEC_NONINTLV_DU_NUM_PER_MCU_ROW(I)      *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x18 + (I << 2))

#define REG_JPEG_DEC_COMP0_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x24)
#define REG_JPEG_DEC_COMP1_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x28)
#define REG_JPEG_DEC_COMP2_DATA_UNIT_NUM                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x2C)
#define REG_JPEG_DEC_DATA_UNIT(I)                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x24 + (I << 2))

#define REG_JPEG_DEC_COMP0_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x30)
#define REG_JPEG_DEC_COMP1_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x34)
#define REG_JPEG_DEC_COMP2_PROGR_COEFF_START_ADDR        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x38)
#define REG_JPEG_DEC_PROGR_COEFF_START_ADDR(I)           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x30 + (I << 2))

#define REG_JPEG_DEC_CTRL                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x3C)
#define REG_JPEG_DEC_TRIG                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x40)
#define REG_JPEG_DEC_RST                                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x44)
#define REG_JEPG_DEC_FILE_BRP                            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x48)
#define REG_JPEG_DEC_FILE_TOTAL_SIZE                     *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x4C)
#define REG_JEPG_DEC_INTLV_FIRST_MCU_INDEX               *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x50)
#define REG_JEPG_DEC_INTLV_LAST_MCU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x54)

#define REG_JEPG_DEC_COMP0_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x58)
#define REG_JEPG_DEC_COMP0_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x5C)
#define REG_JEPG_DEC_COMP1_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x60)
#define REG_JEPG_DEC_COMP1_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x64)
#define REG_JEPG_DEC_COMP2_FIRST_DU_INDEX                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x68)
#define REG_JEPG_DEC_COMP2_LAST_DU_INDEX                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x6C)
#define REG_JEPG_DEC_FIRST_DU_INDEX(I)                   *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x58 + (I * 8))
#define REG_JEPG_DEC_LAST_DU_INDEX(I)                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x5C + (I * 8))

#define REG_JPEG_DEC_QT_ID                               *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x70)
#define REG_JPEG_DEC_INTERRUPT_STATUS                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x74)
#define REG_JPEG_DEC_STATUS                              *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x78)

#define REG_JPEG_DEC_RANGE_DEC_EN                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x7C)
#define REG_JPEG_DEC_START_IDCT_MCU_ROW_INDEX            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x80)
#define REG_JPEG_DEC_END_IDCT_MCU_ROW_INDEX              *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x84)
#define REG_JPEG_DEC_IDCT_MCU_NUM_PER_ROW                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x88)
#define REG_JPEG_DEC_IDCT_SKIP_MCU_INDEX1                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x8C)
#define REG_JPEG_DEC_IDCT_SKIP_MCU_INDEX2                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x90)
#define REG_JPEG_DEC_MCU_CNT                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x94)
#define REG_JPEG_DEC_IDCT_CNT                            *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x98)

/* The following registers are for JPEG encoder */
#define REG_JPEG_ENC_RST                                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x100)
#define REG_JPEG_ENC_CTRL                                *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x104)
#define REG_JPEG_ENC_QUALITY                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x108)
#define REG_JPEG_ENC_BLK_NUM                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x10C)
#define REG_JPEG_ENC_BLK_CNT                             *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x110)
#define REG_JPEG_ENC_INTERRUPT_STATUS                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x11C)

/* Notice: The continuous shooting mode is not implemented by driver */
#define REG_JPEG_ENC_DEST_ADDR1                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x120)
#define REG_JPEG_ENC_DMA_ADDR1                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x124)
#define REG_JPEG_ENC_STALL_ADDR1                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x128)

#define REG_JPEG_ENC_DEST_ADDR2                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x12C)
#define REG_JPEG_ENC_DMA_ADDR2                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x130)
#define REG_JPEG_ENC_STALL_ADDR2                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x134)

#define REG_JPEG_ENC_OFFSET_ADDR                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x138)
#define REG_JPEG_ENC_CURR_DMA_ADDR                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x13C)

#define REG_JPEG_ENC_RESTART_INTERVAL                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x150)
#define REG_JPEG_ENC_IMG_DIMENSION                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x154)

#define REG_JPEG_ENC_GULTRA_THRESHOLD                    *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x158)
#define REG_JPEG_ENC_STOP_INDEX                          *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x15C)
#define REG_JPEG_ENC_SLOW_DOWN                           *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x160)


/* Definition for power down control */
/*
#define REG_PDN_CON_JPEG   *(PDN_CON3)
#define REG_PDN_CLR_JPEG   *(PDN_CLR3)
#define REG_PDN_SET_JPEG   *(PDN_SET3)

#define REG_PDN_CON_DCT    *(PDN_CON3)
#define REG_PDN_CLR_DCT    *(PDN_CLR3)
#define REG_PDN_SET_DCT    *(PDN_SET3)

#define PDN_CTRL_JPEG_BIT  0x0400
#define PDN_CTRL_DCT_BIT   0x2000
*/


#define REG_MMCG_CON       *(volatile kal_uint32 *)(MMCG_CON0)
#define REG_MMCG_CLR       *(volatile kal_uint32 *)(MMCG_CLR0)
#define REG_MMCG_SET       *(volatile kal_uint32 *)(MMCG_SET0)

#define MMCG_JPEG_ENC_BIT  (MMPWRMGR_JPEG_ENC)
#define MMCG_JPEG_DEC_BIT  (MMPWRMGR_JPEG_DEC)
////#define MMCG_DCT_BIT       MMPWRMGR_DCT


/* Definition for control bit in REG_JPEG_ENC_CTRL */
#define JPEG_ENC_CTRL_ENABLE_BIT                0x00000001
#define JPEG_ENC_CTRL_INT_EN_BIT                0x00000004
#define JPEG_ENC_CTRL_YUV_BIT                   0x00000018
#define JPEG_ENC_CTRL_FILE_FORMAT_BIT           0x00000020
#define JPEG_ENC_CTRL_FILE_FORMAT_BIT           0x00000020
#define JPEG_ENC_CTRL_SLOW_DOWN_EN_BIT          0x00000040
#define JPEG_ENC_CTRL_GULTRA_EN_BIT             0x00000200
#define JPEG_ENC_CTRL_RST_MARKER_BIT            0x00000400
#define JPEG_ENC_CTRL_BLK_STOP_BIT              0x00000800
#define JPEG_ENC_CTRL_BURST_TYPE_BIT            0x00007000
#define JPEG_ENC_CTRL_SELF_INIT_EN_BIT          0x00010000


/* Definition for file format which will be set into JPEG_ENC_CTRL_FILE_FORMAT_BIT */
#define JPEG_DRV_ENC_FILE_FORMAT_JPEG           0x00
#define JPEG_DRV_ENC_FILE_FORMAT_JFIF_EXIF      (0x01 << 5)


/* Definition for YUV format which will be set into JPEG_ENC_CTRL_YUV_BIT */
#define JPEG_DRV_ENC_YUV400                     (0x02 << 3)
#define JPEG_DRV_ENC_YUV422                     (0x00 << 3)
#define JPEG_DRV_ENC_YUV420                     (0x01 << 3)
#define JPEG_DRV_ENC_YUV411                     (0x03 << 3)


/* Definition for burst type which will be set into JPEG_ENC_CTRL_BURST_TYPE_BIT */
#define JPEG_DRV_ENC_BURST_TYPE_BURST_16        (0x00 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_SINGLE_4        (0x01 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_2         (0x02 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_4         (0x03 << 11)
#define JPEG_DRV_ENC_BURST_TYPE_BURST_8         (0x04 << 11)


/* Definition for JPEG interrupt type */
#define JPEG_DRV_ISR_TYPE_NONE                  0x00
#define JPEG_DRV_ISR_TYPE_DEC                   0x01
#define JPEG_DRV_ISR_TYPE_ENC                   0x02


/* Definition for JPEG interrupt status */
#define JPEG_DRV_DEC_INT_STATUS_EOF             0x01
#define JPEG_DRV_DEC_INT_STATUS_BREAKPOINT      0x02
#define JPEG_DRV_DEC_INT_STATUS_FILE_OVERFLOW   0x04
#define JPEG_DRV_DEC_INT_STATUS_RANGE_DECODE    0x08  /// not used

#define JPEG_DRV_DEC_INT_STATUS_IDP_COMPLETE    0x10  /// this bit is not defined in JPEG HW spec.
                                                      /// it is used to indicate that IDP has completed.


/* Definition for encode quality (16 values but only 14 valid levels) */
#define JPEG_DRV_ENC_QUALITY_00_00              0x00  /// Q60
#define JPEG_DRV_ENC_QUALITY_00_01              0x01  /// Q80
#define JPEG_DRV_ENC_QUALITY_00_10              0x02  /// Q90
#define JPEG_DRV_ENC_QUALITY_00_11              0x03  /// Q95
#define JPEG_DRV_ENC_QUALITY_01_00              0x04  /// Q39
#define JPEG_DRV_ENC_QUALITY_01_01              0x05  /// Q68
#define JPEG_DRV_ENC_QUALITY_01_10              0x06  /// Q84
#define JPEG_DRV_ENC_QUALITY_01_11              0x07  /// Q92
#define JPEG_DRV_ENC_QUALITY_10_00              0x08  /// Q48
#define JPEG_DRV_ENC_QUALITY_10_01              0x09  /// Q48
#define JPEG_DRV_ENC_QUALITY_10_10              0x0A  /// Q74
#define JPEG_DRV_ENC_QUALITY_10_11              0x0B  /// Q87
#define JPEG_DRV_ENC_QUALITY_11_00              0x0C  /// Q34
#define JPEG_DRV_ENC_QUALITY_11_01              0x0D  /// Q34
#define JPEG_DRV_ENC_QUALITY_11_10              0x0E  /// Q64
#define JPEG_DRV_ENC_QUALITY_11_11              0x0F  /// Q82


#define JPEG_DRV_ENC_QUALITY_EXCELLENT          JPEG_DRV_ENC_QUALITY_10_11    /// Q87
#define JPEG_DRV_ENC_QUALITY_GOOD               JPEG_DRV_ENC_QUALITY_10_10    /// Q74
#define JPEG_DRV_ENC_QUALITY_FAIR               JPEG_DRV_ENC_QUALITY_00_00    /// Q60
#define JPEG_DRV_ENC_QUALITY_LOW                JPEG_DRV_ENC_QUALITY_10_01    /// Q48
#define JPEG_DRV_ENC_QUALITY_POOR               JPEG_DRV_ENC_QUALITY_11_01    /// Q34


#define JPEG_DRV_DEC_TABLE_ALIGNED_SIZE         4096
#define JPEG_DRV_DEC_TABLE_SIZE                 2048
#define JPEG_DRV_DEC_TABLE_ALIGNMENT            2048
#define JPEG_DRV_DEC_TABLE_ALIGNED_ADDR         0xFFFFF800

// progressive decode buffer size
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MIN       (256 * 1024)
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MAX       (1024 * 1024)


#define JPEG_DRV_ENC_INT_STATUS_DONE   0x01
#define JPEG_DRV_ENC_INT_STATUS_STALL  0x02


#define JPEG_DRV_ENC_RESTART_INTERVAL  5


#define JPEG_HW_DRV_NONE         0x00
#define JPEG_HW_DRV_ENCODER_BIT  0x01
#define JPEG_HW_DRV_DECODER_BIT  0x02

#endif  // __DRV_GRAPHICS_JPEG_6256_E2_SERIES__

#endif /// __DRV_GRAPHICS_JPEG_6256_SERIES__
#endif /// __JPEG_DRV_6256_SERIES_H__
