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
 *   jpeg_drv_6255_series.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Driver definition of JPEG codec for MT6255 series chip.
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
 
#ifndef __JPEG_DRV_6255_SERIES_H__
#define __JPEG_DRV_6255_SERIES_H__

#include "drv_comm.h"
#include "drv_features_jpeg.h"

#if defined(__DRV_GRAPHICS_JPEG_6255_SERIES__)

#include "init.h"
#include "reg_base.h"
#include "mm_power_ctrl.h"

#define JPEG_CODEC_base MP4JPG_base

/* JPEG codec register offset */
#define REG_VENC_FRAME_START                       (JPEG_CODEC_base + 0x00)
#define REG_VENC_MBX_LMT                           (JPEG_CODEC_base + 0x08)
#define REG_VENC_MBY_LMT                           (JPEG_CODEC_base + 0x0C)
#define REG_VENC_SRCADR_Y                          (JPEG_CODEC_base + 0x3C)
#define REG_VENC_SRCADR_CB                         (JPEG_CODEC_base + 0x40)
#define REG_VENC_SRCADR_CR                         (JPEG_CODEC_base + 0x44)
#define REG_VENC_BITADR                            (JPEG_CODEC_base + 0x60)
#define REG_VENC_STATUS                            (JPEG_CODEC_base + 0x64)
#define REG_VENC_IRQ_EN                            (JPEG_CODEC_base + 0x68)
#define REG_VENC_BSDMA_CTRL                        (JPEG_CODEC_base + 0x70)
#define REG_VENC_IRQ_ACK                           (JPEG_CODEC_base + 0x78)
#define REG_VENC_IRQ_STATUS                        (JPEG_CODEC_base + 0x7C)
#define REG_VENC_BYTE_COUNT                        (JPEG_CODEC_base + 0x80)
#define REG_VENC_BIT_COUNT                         (JPEG_CODEC_base + 0x84)
#define REG_VENC_ZERO_COEF_COUNT                   (JPEG_CODEC_base + 0x88)
#define REG_VENC_RESET                             (JPEG_CODEC_base + 0x90)

#define REG_VENC_DEBUG1                            (JPEG_CODEC_base + 0xA4)
#define REG_VENC_DEBUG3                            (JPEG_CODEC_base + 0xAC)
#define REG_VENC_DEBUG4                            (JPEG_CODEC_base + 0xB0)
#define REG_VENC_CHECKSUM0                         (JPEG_CODEC_base + 0xB8)
#define REG_VENC_CHECKSUM1                         (JPEG_CODEC_base + 0xBC)
#define REG_VENC_CHECKSUM2                         (JPEG_CODEC_base + 0xC0)
#define REG_VENC_CHECKSUM3                         (JPEG_CODEC_base + 0xC4)
#define REG_VENC_CHECKSUM4                         (JPEG_CODEC_base + 0xC8)
#define REG_VENC_CHECKSUM5                         (JPEG_CODEC_base + 0xCC)
#define REG_VENC_CDMA_STATUS                       (JPEG_CODEC_base + 0xD0)
#define REG_VENC_BSDMA_STATUS                      (JPEG_CODEC_base + 0xD8)
#define REG_VENC_JPEG_CODEC_MODE                   (JPEG_CODEC_base + 0xF0)
#define REG_VENC_JPGENC_QUALITY                    (JPEG_CODEC_base + 0xF4)
#define REG_VENC_JPGDEC_BRZ_FACTOR                 (JPEG_CODEC_base + 0xF8)
#define REG_VENC_JPGDEC_SYS_DU_NUM                 (JPEG_CODEC_base + 0xFC)

#define REG_VENC_JPGDEC_SYS_ADDR_Y                 (JPEG_CODEC_base + 0x100)
#define REG_VENC_JPGDEC_SYS_ADDR_U                 (JPEG_CODEC_base + 0x104)
#define REG_VENC_JPGDEC_SYS_ADDR_V                 (JPEG_CODEC_base + 0x108)
#define REG_VENC_JPGDEC_SYS_PITCH_Y                (JPEG_CODEC_base + 0x10C)
#define REG_VENC_JPGDEC_SYS_PITCH_U                (JPEG_CODEC_base + 0x110)
#define REG_VENC_JPGDEC_SYS_PITCH_V                (JPEG_CODEC_base + 0x114)
#define REG_VENC_JPGDEC_SYS_TOTAL_MCU_NUM          (JPEG_CODEC_base + 0x118)
#define REG_VENC_JPGDEC_SYS_MCU_H_LMT              (JPEG_CODEC_base + 0x11C)
#define REG_VENC_JPGENC_FIRST_BYTE_OFFSET          (JPEG_CODEC_base + 0x120)
#define REG_VENC_JPGENC_STUFFED_00_CNT             (JPEG_CODEC_base + 0x124)
#define REG_VENC_JPGDEC_SYSRAM_STATUS              (JPEG_CODEC_base + 0x128)
#define REG_VENC_JPGDEC_DEBUG0                     (JPEG_CODEC_base + 0x12C)
#define REG_VENC_JPGDEC_FILE_ADDR                  (JPEG_CODEC_base + 0x200)
#define REG_VENC_JPGDEC_COMP_ID                    (JPEG_CODEC_base + 0x20C)
#define REG_VENC_JPGDEC_TOTAL_MCU_NUM              (JPEG_CODEC_base + 0x210)
#define REG_VENC_JPGDEC_COMP0_DATA_UNIT_NUM        (JPEG_CODEC_base + 0x224)
#define REG_VENC_JPGDEC_DATA_UNIT(I)               (JPEG_CODEC_base + 0x224 + (I << 2))
#define REG_VENC_JPGDEC_CTRL                       (JPEG_CODEC_base + 0x23C)
#define REG_VENC_JPGDEC_TRIG                       (JPEG_CODEC_base + 0x240)
#define REG_VENC_JPGDEC_FILE_BRP                   (JPEG_CODEC_base + 0x248)
#define REG_VENC_JPGDEC_FILE_TOTAL_SIZE            (JPEG_CODEC_base + 0x24C)
#define REG_VENC_JPGDEC_QT_ID                      (JPEG_CODEC_base + 0x270)
#define REG_VENC_JPGDEC_INTERRUPT_STATUS           (JPEG_CODEC_base + 0x274)
#define REG_VENC_JPGDEC_STATUS                     (JPEG_CODEC_base + 0x278)
#define REG_VENC_JPGDEC_MCU_CNT                    (JPEG_CODEC_base + 0x294)
#define REG_VENC_JPGDEC_IDCT_CNT                   (JPEG_CODEC_base + 0x298)
#define REG_VENC_JPGDEC_NULL                       (JPEG_CODEC_base + 0x2A0)


#define DRV_VENC_WriteReg(addr,data)                                        \
  do {                                                                      \
    (*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data);                  \
  } while(0)
  
#define DRV_VENC_WriteReg8(addr,data)                                       \
  do {                                                                      \
    (*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data);                    \
  } while(0)

#define DRV_VENC_WriteReg16(addr,data)                                      \
  do {                                                                      \
    (*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data);                  \
  } while(0)
  
#define DRV_VENC_WriteReg32(addr,data)                                      \
  do {                                                                      \
    (*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data);                  \
  } while(0)
  


#define DRV_VENC_Reg(addr,data)                                             \
  do {                                                                      \
    if (SW_SEC_0 == INT_SW_SecVersion())                                    \
    {                                                                       \
       kal_uint32 irq_mask;                                                 \
       irq_mask = SaveAndSetIRQMask();                                      \
       data = (*(volatile kal_uint16 *)(addr));                             \
       ASSERT(0 == (*(volatile kal_uint32 *)(REG_VENC_JPGDEC_NULL)));       \
       RestoreIRQMask(irq_mask);                                            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
       data = (*(volatile kal_uint16 *)(addr));                             \
    }                                                                       \
  } while(0)
           
#define DRV_VENC_Reg8(addr,data)                                            \
  do {                                                                      \
    if (SW_SEC_0 == INT_SW_SecVersion())                                    \
    {                                                                       \
       kal_uint32 irq_mask;                                                 \
       irq_mask = SaveAndSetIRQMask();                                      \
       data = (*(volatile kal_uint8 *)(addr));                              \
       ASSERT(0 == (*(volatile kal_uint32 *)(REG_VENC_JPGDEC_NULL)));       \
       RestoreIRQMask(irq_mask);                                            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
       data = (*(volatile kal_uint8 *)(addr));                              \
    }                                                                       \
  } while(0)
           
#define DRV_VENC_Reg16(addr,data)                                           \
  do {                                                                      \
    if (SW_SEC_0 == INT_SW_SecVersion())                                    \
    {                                                                       \
       kal_uint32 irq_mask;                                                 \
       irq_mask = SaveAndSetIRQMask();                                      \
       data = (*(volatile kal_uint16 *)(addr));                             \
       ASSERT(0 == (*(volatile kal_uint32 *)(REG_VENC_JPGDEC_NULL)));       \
       RestoreIRQMask(irq_mask);                                            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
       data = (*(volatile kal_uint16 *)(addr));                             \
    }                                                                       \
  } while(0)
  
#define DRV_VENC_Reg32(addr,data)                                           \
  do {                                                                      \
    if (SW_SEC_0 == INT_SW_SecVersion())                                    \
    {                                                                       \
       kal_uint32 irq_mask;                                                 \
       irq_mask = SaveAndSetIRQMask();                                      \
       data = (*(volatile kal_uint32 *)(addr));                             \
       ASSERT(0 == (*(volatile kal_uint32 *)(REG_VENC_JPGDEC_NULL)));       \
       RestoreIRQMask(irq_mask);                                            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
       data = (*(volatile kal_uint32 *)(addr));                             \
    }                                                                       \
  } while(0)


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

#define MMCG_JPEG_BIT  (MMPWRMGR_JPEG)


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


/* Definition for JPEG sysram status */
#define JPEG_DRV_DEC_SYS_STATUS_HW_INUSE      0x0
#define JPEG_DRV_DEC_SYS_STATUS_SW_INUSE      0x1


#define JPEG_DRV_DEC_INT_STATUS_IDP_COMPLETE    0x10  /// this bit is not defined in JPEG HW spec.
                                                      /// it is used to indicate that IDP has completed.


#define JPEG_DRV_ENC_QUALITY_EXCELLENT          0    /// quatization step >> 3, Q95
#define JPEG_DRV_ENC_QUALITY_GOOD               1    /// quatization step >> 2, Q85
#define JPEG_DRV_ENC_QUALITY_FAIR               2    /// quatization step >> 1, Q75
#define JPEG_DRV_ENC_QUALITY_LOW                3    /// no shift, Q50
#define JPEG_DRV_ENC_QUALITY_POOR               3    /// no shift, Q50, align to software quality setting


#define JPEG_DRV_DEC_TABLE_ALIGNED_SIZE         0
#define JPEG_DRV_DEC_TABLE_SIZE                 0
#define JPEG_DRV_DEC_TABLE_ALIGNMENT            8
#define JPEG_DRV_DEC_TABLE_ALIGNED_ADDR         0xFFFFF800

// progressive decode buffer size
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MIN       (256 * 1024)
#define JPEG_DRV_DEC_PROG_COEF_BUFFER_MAX       (1024 * 1024)


#define JPEG_DRV_ENC_FILE_BUFFER_SIZE           (2 * 1024 * 1024)    /// Buffer for file access


#define JPEG_DRV_ENC_INT_STATUS_DONE            0x02
#define JPEG_DRV_ENC_INT_STATUS_BIT_FULL        0x10
#define JPEG_DRV_ENC_CONT_IDX_BIT               0x00010000


#define JPEG_HW_DRV_NONE                        0x00
#define JPEG_HW_DRV_ENCODER_BIT                 0x01
#define JPEG_HW_DRV_DECODER_BIT                 0x02


#define JPEG_DRV_GMC_MODE_BIT                   0x40000000


#endif /// __DRV_GRAPHICS_JPEG_6255_SERIES__
#endif /// __JPEG_DRV_6255_SERIES_H__
