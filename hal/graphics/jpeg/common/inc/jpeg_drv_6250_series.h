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
 *   jpeg_drv_6276_series.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Driver definition of JPEG codec for MT6276 series chip.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_DRV_6250_SERIES_H__
#define __JPEG_DRV_6250_SERIES_H__

#include "drv_comm.h"
#include "drv_features_jpeg.h"

#if defined(__DRV_GRAPHICS_JPEG_6250_SERIES__)

#include "reg_base.h"
#include "mm_power_ctrl.h"


#define JPEG_CODEC_base                         JPEG_base
#define REG_HMJPEG_START                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x00)
#define REG_HMJPEG_RESET                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x04)
#define REG_HMJPEG_CRTL                         *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x08)
#define REG_HMJPEG_FORMAT                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x0C)
#define REG_HMJPEG_STATUS                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x10)
#define REG_HMJPEG_QUALITY_SETTING              *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x14)
#define REG_HMJPEG_DC_SCALE                     *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x18)

#define REG_HMJPEG_LAST_POS_3_0                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x1C)
#define REG_HMJPEG_LAST_POS_5_4                 *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x20)
#define REG_HMJPEG_DEBUG0                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x24)
#define REG_HMJPEG_DEBUG1                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x28)
#define REG_HMJPEG_DEBUG2                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x2C)
#define REG_HMJPEG_DEBUG3                       *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x30)
#define REG_HMJPEG_DUMMY                        *(volatile kal_uint32 *)(JPEG_CODEC_base + 0x34)

#define HMJPEG_SRC_BASE_REG                     (volatile kal_uint32 *)(JPEG_CODEC_base + 0x8000)
#define HMJPEG_MCIQ_BASE_REG                    (volatile kal_uint32 *)(JPEG_CODEC_base + 0x8200)
#define HMJPEG_DST_BASE_REG                     (volatile kal_uint32 *)(JPEG_CODEC_base + 0x8400)

#define REG_HMJPEG_SRC_BASE_ADDR                (JPEG_CODEC_base + 0x8000)
#define REG_HMJPEG_MCIQ_BASE_ADD                (JPEG_CODEC_base + 0x8200)
#define REG_HMJPEG_DST_BASE_ADDR                (JPEG_CODEC_base + 0x8400)

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
#define JPEG_DRV_ENC_QUALITY_POOR               4    /// quatization step << 1, Q25


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

#define HMJPEG_READ_DATA(addr,  data)  (data = *((volatile kal_uint32*)(addr)))
#define HMJPEG_WRITE_DATA(addr, data)  (*((volatile kal_uint32*)(addr)) = data)

#define HMJPEG_READ16(addr,  data)  (data = *((volatile kal_uint16*)(addr)))
#define HMJPEG_WRITE16(addr, data)  (*((volatile kal_uint16*)(addr)) = data)

#define HMJPEG_READ32(addr,  data)  (data = *((volatile kal_uint32*)(addr)))
#define HMJPEG_WRITE32(addr, data)  (*((volatile kal_uint32*)(addr)) = data)

#endif /// End of #if defined(__DRV_GRAPHICS_JPEG_6250_SERIES__)
#endif /// __JPEG_DRV_6250_SERIES_H__
