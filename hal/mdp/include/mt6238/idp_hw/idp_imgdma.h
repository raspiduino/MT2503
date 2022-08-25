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
 *   mt6238_imgdma.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   image DMA
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 25 2010 ct.fang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/** \defgroup idp Image data path
 * \brief This module defines image data path
 * @{
 */
/** \defgroup imgdma Image DMA
 * \brief This module defines image DMA.
 * @{
 */
#ifndef __idp_imgdma_mt6238_h__
#define __idp_imgdma_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"

/* register definition of Image DMA */
#define IMGDMA_STATUS_REG           (IMGDMA_base + 0x0000)
#define IMGDMA_INT_ACK_REG          (IMGDMA_base + 0x0004)
#define IMGDMA_SW_RESET_REG         (IMGDMA_base + 0x0010)
#define IMGDMA_GMC_STATUS_REG       (IMGDMA_base + 0x0020)
#if defined(MT6268)
#define IMGDMA_ENG_SW_RSTB_REG      (IMGDMA_base + 0x0014)
#define IMGDMA_GMCIF_SW_RSTB_REG    (IMGDMA_base + 0x0018)
#define IMGDMA_GMCIF_A_ENG_STA_REG  (IMGDMA_base + 0x0030)
#define IMGDMA_GMCIF_B_ENG_STA_REG  (IMGDMA_base + 0x0034)
#define IMGDMA_GMCIF_C_ENG_STA_REG  (IMGDMA_base + 0x0038)
#define IMGDMA_GMCIF_D_ENG_STA_REG  (IMGDMA_base + 0x003C)
#define IMGDMA_GMCIF_E_ENG_STA_REG  (IMGDMA_base + 0x0040)
#define IMGDMA_GMCIF_F_ENG_STA_REG  (IMGDMA_base + 0x0044)
#define IMGDMA_INIT_EN_REG          (IMGDMA_base + 0x0050)
#endif  // chip option

#define REG_IMGDMA_STATUS           *((volatile unsigned int *) (IMGDMA_base + 0x0000))
#define REG_IMGDMA_INT_ACK          *((volatile unsigned int *) (IMGDMA_base + 0x0004))
#define REG_IMGDMA_SW_RESET         *((volatile unsigned int *) (IMGDMA_base + 0x0010))
#if defined(MT6268)
#define REG_IMGDMA_ENG_SW_RSTB      *((volatile unsigned int *) IMGDMA_ENG_SW_RSTB_REG)
#define REG_IMGDMA_GMCIF_SW_RSTB    *((volatile unsigned int *) IMGDMA_GMCIF_SW_RSTB_REG)
#define REG_IMGDMA_INIT_EN          *((volatile unsigned int *) IMGDMA_INIT_EN_REG)
#endif  // chip option

/* bit mapping of image dma interrupt ACK register */
#define IMGDMA_JPEG_INT_ACK_BIT            (1 << 0)
#define IMGDMA_VIDEO_ENCODE_W_INT_ACK_BIT  (1 << 1)
#define IMGDMA_VIDEO_ENCODE_R_INT_ACK_BIT  (1 << 2)
#define IMGDMA_VIDEO_DECODE_INT_ACK_BIT    (1 << 3)
#define IMGDMA_IBW1_INT_ACK_BIT            (1 << 4)
#define IMGDMA_IBW2_INT_ACK_BIT            (1 << 5)
#define IMGDMA_IBR1_INT_ACK_BIT            (1 << 8)
#define IMGDMA_IBR2_INT_ACK_BIT            (1 << 9)
#define IMGDMA_OVL_INT_ACK_BIT             (1 << 10)
#define IMGDMA_IRT0_INT_ACK_BIT            (1 << 12)
#define IMGDMA_IRT1_INT_ACK_BIT            (1 << 13)
#define IMGDMA_IRT2_INT_ACK_BIT            (1 << 14)
#define IMGDMA_IRT3_INT_ACK_BIT            (1 << 15)

/* bit mapping of IMAGE DMA status register */
#define IMGDMA_STATUS_JPEG_BUSY_BIT            ((unsigned int)1 << 16)
#define IMGDMA_STATUS_VIDEO_ENCODE_W_BUSY_BIT  ((unsigned int)1 << 17)
#define IMGDMA_STATUS_VIDEO_ENCODE_R_BUSY_BIT  ((unsigned int)1 << 18)
#define IMGDMA_STATUS_VIDEO_DECODE_BUSY_BIT    ((unsigned int)1 << 19)
#define IMGDMA_STATUS_IBW1_BUSY_BIT            ((unsigned int)1 << 20)
#define IMGDMA_STATUS_IBW2_BUSY_BIT            ((unsigned int)1 << 21)
#define IMGDMA_STATUS_IBR1_BUSY_BIT            ((unsigned int)1 << 24)
#define IMGDMA_STATUS_IBR2_BUSY_BIT            ((unsigned int)1 << 25)
#define IMGDMA_STATUS_OVL_BUSY_BIT             ((unsigned int)1 << 26)
#define IMGDMA_STATUS_IRT0_BUSY_BIT            ((unsigned int)1 << 28)
#define IMGDMA_STATUS_IRT1_BUSY_BIT            ((unsigned int)1 << 29)
#define IMGDMA_STATUS_IRT2_BUSY_BIT            ((unsigned int)1 << 30)
#define IMGDMA_STATUS_IRT3_BUSY_BIT            ((unsigned int)1 << 31)

#define IMGDMA_GMC_STATUS_IF_A_IS_BUSY         ((unsigned int)1 << 0)
#define IMGDMA_GMC_STATUS_IF_B_IS_BUSY         ((unsigned int)1 << 1)
#define IMGDMA_GMC_STATUS_IF_C_IS_BUSY         ((unsigned int)1 << 2)

/* DRV_IDP_6238_SERIES_E2 */
#define IMGDMA_GMC_STATUS_IF_D_IS_BUSY         ((unsigned int)1 << 3)
#define IMGDMA_GMC_STATUS_IF_E_IS_BUSY         ((unsigned int)1 << 4)
#define IMGDMA_GMC_STATUS_IF_F_IS_BUSY         ((unsigned int)1 << 5)
/* */

#define IMGDMA_STATUS_JPEG_INT_BIT            (1 << 0)
#define IMGDMA_STATUS_VIDEO_ENCODE_W_INT_BIT  (1 << 1)
#define IMGDMA_STATUS_VIDEO_ENCODE_R_INT_BIT  (1 << 2)
#define IMGDMA_STATUS_VIDEO_DECODE_INT_BIT    (1 << 3)
#define IMGDMA_STATUS_IBW1_INT_BIT            (1 << 4)
#define IMGDMA_STATUS_IBW2_INT_BIT            (1 << 5)
#define IMGDMA_STATUS_IBR1_INT_BIT            (1 << 8)
#define IMGDMA_STATUS_IBR2_INT_BIT            (1 << 9)
#define IMGDMA_STATUS_OVL_INT_BIT             (1 << 10)
#define IMGDMA_STATUS_IRT0_INT_BIT            (1 << 12)
#define IMGDMA_STATUS_IRT1_INT_BIT            (1 << 13)
#define IMGDMA_STATUS_IRT2_INT_BIT            (1 << 14)
#define IMGDMA_STATUS_IRT3_INT_BIT            (1 << 15)

#if defined(MT6268)
/* bit mapping of image DMA HW frame sync register */
#define IMGDMA_HW_FRAME_SYNC_JPEG_BIT         0x00000001
#define IMGDMA_HW_FRAME_SYNC_VDOENC_BIT       0x00000002
#define IMGDMA_HW_FRAME_SYNC_IBW1_BIT         0x00000010
#define IMGDMA_HW_FRAME_SYNC_IBW2_BIT         0x00000020
#define IMGDMA_HW_FRAME_SYNC_OVL_BIT          0x00000400
#define IMGDMA_HW_FRAME_SYNC_IRT1_BIT         0x00002000
#endif  // chip option

#if defined(MT6268)
#define IMGDMA_SW_RSTB_JPEG           (0x00000001)
#define IMGDMA_SW_RSTB_VDOENC         (0x00000002)
#define IMGDMA_SW_RSTB_VDODEC         (0x00000008)
#define IMGDMA_SW_RSTB_IBW1           (0x00000010)
#define IMGDMA_SW_RSTB_IBW2           (0x00000020)
#define IMGDMA_SW_RSTB_IBR1           (0x00000100)
#define IMGDMA_SW_RSTB_IBR2           (0x00000200)
#define IMGDMA_SW_RSTB_OVL            (0x00000400)
#define IMGDMA_SW_RSTB_IRT0           (0x00001000)
#define IMGDMA_SW_RSTB_IRT1           (0x00002000)
#define IMGDMA_SW_RSTB_IRT2           (0x00004000)
#define IMGDMA_SW_RSTB_IRT3           (0x00008000)
#endif  // #if defined(MT6268)

/* macros of image dma status register */
#define IMGDMA_IBR2_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IBR2_BUSY_BIT)
#define IMGDMA_IBR1_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IBR1_BUSY_BIT)
#define IMGDMA_IBW2_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IBW2_BUSY_BIT)
#define IMGDMA_IBW1_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IBW1_BUSY_BIT)
#define IMGDMA_VIDEO_DECODE_IS_BUSY     (REG_IMGDMA_STATUS & IMGDMA_STATUS_VIDEO_DECODE_BUSY_BIT)
#define IMGDMA_VIDEO_ENCODE_R_IS_BUSY   (REG_IMGDMA_STATUS & IMGDMA_STATUS_VIDEO_ENCODE_R_BUSY_BIT)
#define IMGDMA_VIDEO_ENCODE_W_IS_BUSY   (REG_IMGDMA_STATUS & IMGDMA_STATUS_VIDEO_ENCODE_W_BUSY_BIT)
#define IMGDMA_JPEG_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_JPEG_BUSY_BIT)
#define IMGDMA_IRT0_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IRT0_BUSY_BIT)
#define IMGDMA_IRT1_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IRT1_BUSY_BIT)
#define IMGDMA_IRT2_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IRT2_BUSY_BIT)
#define IMGDMA_IRT3_IS_BUSY             (REG_IMGDMA_STATUS & IMGDMA_STATUS_IRT3_BUSY_BIT)
#define IMGDMA_OVL_IS_BUSY              (REG_IMGDMA_STATUS & IMGDMA_STATUS_OVL_BUSY_BIT)

/* macros of image dma interrupt ACK register */
#define ACK_IMGDMA_IBR1_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IBR1_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IBR2_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IBR2_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IBW1_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IBW1_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IBW2_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IBW2_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IRT0_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IRT0_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IRT1_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IRT1_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IRT2_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IRT2_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_IRT3_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_IRT3_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_OVL_INT()              do { REG_IMGDMA_INT_ACK = IMGDMA_OVL_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_JPEG_INT()             do { REG_IMGDMA_INT_ACK = IMGDMA_JPEG_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_VIDEO_DECODE_INT()     do { REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_DECODE_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_VIDEO_ENCODE_R_INT()   do { REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_ENCODE_R_INT_ACK_BIT; } while(0)
#define ACK_IMGDMA_VIDEO_ENCODE_W_INT()   do { REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_ENCODE_W_INT_ACK_BIT; } while(0)

#if defined(MT6268)
#define IMGDMA_ENABLE_JPEG_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_JPEG_BIT; } while (0)

#define IMGDMA_DISABLE_JPEG_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_JPEG_BIT; } while (0)

#define IMGDMA_ENABLE_VDOENC_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_VDOENC_BIT; } while (0)

#define IMGDMA_DISABLE_VDOENC_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_VDOENC_BIT; } while (0)

#define IMGDMA_ENABLE_IBW1_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_IBW1_BIT; } while (0)

#define IMGDMA_DISABLE_IBW1_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_IBW1_BIT; } while (0)

#define IMGDMA_ENABLE_IBW2_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_IBW2_BIT; } while (0)

#define IMGDMA_DISABLE_IBW2_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_IBW2_BIT; } while (0)

#define IMGDMA_ENABLE_OVL_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_OVL_BIT; } while (0)

#define IMGDMA_DISABLE_OVL_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_OVL_BIT; } while (0)

#define IMGDMA_ENABLE_IRT1_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN |= IMGDMA_HW_FRAME_SYNC_IRT1_BIT; } while (0)

#define IMGDMA_DISABLE_IRT1_HW_FRAME_SYNC() \
  do { REG_IMGDMA_INIT_EN &= ~IMGDMA_HW_FRAME_SYNC_IRT1_BIT; } while (0)
#endif  // chip option

#if defined(MT6268)
/**
 *  \def IMGDMA_RESET_ENG(eng)
 *  eng can be JPEG, VDOENC, VDODEC, IBW1, IBW2, IBR1, IBR2, OVL, IRT0, IRT1, IRT2, or IRT3
 *  \remark This is MT6268 only. MT6268A does not support this!
 */
#define IMGDMA_RESET_ENG(eng) \
  do { \
    REG_IMGDMA_ENG_SW_RSTB &= (~IMGDMA_SW_RSTB_##eng##); \
    REG_IMGDMA_ENG_SW_RSTB |= IMGDMA_SW_RSTB_##eng##; \
  } while (0)
#endif  // #if defined(MT6268)

#define IMGDMA_SW_RESET_RESET_BIT            (1)

extern void idp_imgdma_init(void);
extern void image_dma_LISR(void);
extern void idp_enforce_stop_all(void);

#endif

#endif // __idp_imgdma_mt6238_h__
/** @} */
