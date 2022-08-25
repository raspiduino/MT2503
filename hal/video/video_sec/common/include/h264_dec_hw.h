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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   h264_hw.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   H264 hardware register definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __H264_HW_H__
#define __H264_HW_H__

#include "reg_base.h"

#define H264_SWITCH_GMC_PORT        (GMC_base+0x20)

/* Main Configuration & Commands */
#define H264_DEC_COMD               (H264_base+0x0) /*WO*/
#define H264_DEC_DMA_COMD           (H264_base+0x4) /*WO*/
#define H264_DEC_SLICE_MAP_ADDR     (H264_base+0x8) /*RW*/
#define H264_DEC_PIC_CONF           (H264_base+0xc) /*RW*/
#define H264_DEC_SLICE_CONF         (H264_base+0x10) /*RW*/
   
/* DMA */
#define H264_DEC_DMA_LIMIT          (H264_base+0x20) /*RW*/
#define H264_DEC_DMA_ADDR           (H264_base+0x24) /*RW*/
#define H264_DEC_DMA_BITCNT         (H264_base+0x28) /*RW*/
   
/* MC */
#define H264_REF_FRAME_ADDR         (H264_base+0x30) /*RW*/
#define H264_MC_LINE_BUF_ADDR       (H264_base+0x34) /*RW*/
#define H264_MC_LINE_BUF_OFFSET     (H264_base+0x38) /*RW*/
#define H264_MC_LINE_BUF_SIZE       (H264_base+0x3c) /*RW*/
#define H264_MC_MV_BUFFER_ADDR      (H264_base+0x40) /*RW*/
   
/* Rec & Deblock */
#define H264_DEC_REC_ADDR           (H264_base+0x44) /*RW*/
#define H264_DEC_DEB_BUF_ADDR       (H264_base+0x48) /*RW*/
#define H264_DEC_REC_Y_SIZE         (H264_base+0x4c) /*RW*/
#define H264_DEC_DEB_DAT_BUF0_ADDR  (H264_base+0x50) /*RW*/
#define H264_DEC_DEB_DAT_BUF1_ADDR  (H264_base+0x54) /*RW*/
   
/* CAVLC */
#define H264_CAVLC_BASE_ADDR        (H264_base+0x60) /*RW*/
   
/* Interrupt */
#define H264_DEC_IRQ_STS            (H264_base+0x70) /*RW*/
#define H264_DEC_IRQ_MASK           (H264_base+0x74) /*RW*/
#define H264_DEC_IRQ_ACK            (H264_base+0x78) /*RW*/
#define H264_DEC_IRQ_POS            (H264_base+0x7C) /*RW*/
   
/* Debug Infomation */
#define H264_DEC_DMA_STS            (H264_base+0x100) /*RO*/
#define H264_DEC_DEBUG_INFO0        (H264_base+0x104) /*RO*/
#define H264_DEC_DEBUG_INFO1        (H264_base+0x108) /*RO*/
#define H264_DEC_DEBUG_INFO2        (H264_base+0x10c) /*RO*/
#define H264_DEC_DEBUG_INFO3        (H264_base+0x110) /*RO*/
#define H264_DEC_DEBUG_INFO4        (H264_base+0x114) /*RO*/
#define H264_DEC_DEBUG_INFO5        (H264_base+0x118) /*RO*/
#define H264_DEC_DEBUG_INFO6           (H264_base+0x11c) /*RO*/
#define H264_DEC_DEBUG_INFO7           (H264_base+0x120) /*RO*/
#define H264_DEC_DEBUG_INFO8           (H264_base+0x124) /*RO*/
#define H264_DEC_DEBUG_INFO9           (H264_base+0x128) /*RO*/
#define H264_DEC_DEBUG_INFO10         (H264_base+0x12c) /*RO*/
#define H264_DEC_DEBUG_INFO11         (H264_base+0x130) /*RO*/
   
/* DEC COMD */
#define H264_DEC_COMD_RST                               0x0001
#define H264_DEC_COMD_START                            0x0010

/* DMA COMD */
#define H264_DEC_DMA_COMD_STOP                     0x0001
#define H264_DEC_DMA_COMD_RESUME                 0x0002

/* PIC CONF */
#define H264_PIC_CONF_LAST_REF_INDEX_OFFSET 21
#define H264_PIC_CONF_REF_CURR_FRAME            0x00100000
#define H264_PIC_CONF_FRAME_TYPE                    0x00080000
#define H264_PIC_CONF_ERR_STALL_EN                 0x00040000
#define H264_PIC_CONF_INTRA_FLAG                     0x00020000
#define H264_PIC_CONF_IRQ_EN                            0x00010000
#define H264_PIC_CONF_MC_MF_CACHE_EN                 0x04000000
#define H264_PIC_CONF_PIC_HEIGHT_OFFSET        8
#define H264_PIC_CONF_PIC_WIDTH_OFFSET         0

//fix value
#define H264_MC_LINE_YBUF_OFFSET                    4
#define H264_MC_LINE_UVBUF_OFFSET                  2

/* The Dma Limit is 256KB */
#define H264_DMA_LIMIT_SIZE   (256*1024)

/* MC LINE BUF OFFSET*/
#define H264_MC_PFH_EN	                                     0x10000
#define H264_MC_UVBUF_OFFSET                          4
#define H264_MC_YBUF_OFFSET			           0

/* MC_LINE_BUF_SIZE */
#define H264_MC_LINE_UVBUF_SIZE_OFFSET         16
#define H264_MC_LINE_YBUF_SIZE_OFFSET           0

/* H264_DEC_IRQ_STS */
#define H264_DEC_IRQ_STS_DEC_DONE                  0x0001
#define H264_DEC_IRQ_STS_DMA_PAUSE                0x0002
#define H264_DEC_IRQ_STS_VLD_ERROR                 0x0004
#define H264_DEC_IRQ_STS_OVERFLOW                  0x0008
#define H264_DEC_IRQ_MB_TYPE_ERROR                 0x0010
   
/* H264_DEC_IRQ_MASK */
#define H264_DEC_IRQ_MASK_DEC_DONE                0x0001
#define H264_DEC_IRQ_MASK_DMA_PAUSE              0x0002
#define H264_DEC_IRQ_MASK_VLD_ERROR               0x0004	
#define H264_DEC_IRQ_MASK_OVERFLOE                 0x0008
#define H264_DEC_IRQ_MASK_MB_TYPE_ERROR       0x0010
   
/* H264_DEC_IRQ_ACK */
#define H264_DEC_IRQ_ACK_DEC_DONE                   0x0001
#define H264_DEC_IRQ_ACK_DMA_PAUSE                 0x0002
#define H264_DEC_IRQ_ACK_VLD_ERROR                  0x0004	
#define H264_DEC_IRQ_ACK_OVERFLOW                   0x0008
#define H264_DEC_IRQ_ACK_MB_TYPE_ERROR           0x0010

/* H264_DEC_DEBUG_INFO0 */
#define H264_DEC_DEBUG_INFO0_VLD_ERR               0x08000000
   
/* H264_DEC_DEBUG_INFO2*/
#define H264_DEC_DEBUG_INFO2_IDCT_OVERFLOW   0x02000000
   
/* H264_DEC_DEBUG_INFO11*/
#define H264_DEC_DEBUG_INFO11_SEQ_IDLE            0x1
   
#endif /*__H264_HW_H__*/

