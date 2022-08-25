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
 *   mt6276_imgdma.h
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
 * 11 29 2011 chrono.wu
 * removed!
 * .
 *
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 03 30 2011 chrono.wu
 * removed!
 * .
 *
 * 01 31 2011 chrono.wu
 * removed!
 * .
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * 10 18 2010 holmes.chiou
 * removed!
 * .
 *
 * 09 16 2010 holmes.chiou
 * removed!
 * .
 *
 * 09 15 2010 holmes.chiou
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * MDP driver check-in
 *
 * removed!
 * removed!
 * MDP driver
 *
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
#ifndef __idp_imgdma_mt6276_h__
#define __idp_imgdma_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif


#include <idp_define.h>

#include "reg_base.h"
#include "IntrCtrl.h"

#include "idp_core.h"
#include "img_common_enum.h"
#include "idp_hw_common.h"

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)
/*****************************************************************************
 * macros and compile options
 *****************************************************************************/


#ifndef MDP_C_MODEL
#define MMSYS_CONFIG_BASE                       (MMSYS_CONFG_base)
#define IMGDMA_MMSYS_MDP_MUX_SEL_REG            (MMSYS_CONFIG_BASE + 0x0500)
#define MMSYS_RSZ_IRQ_FLAG_REG                  (MMSYS_CONFIG_BASE + 0x0560) //prz,vrz,brz
#define MMSYS_ROT_DMA_IRQ_FLAG_REG              (MMSYS_CONFIG_BASE + 0x0564) //rot0,rot1,rot2
#define MMSYS_OVL_JPG_DMA_IRQ_FLAG_REG          (MMSYS_CONFIG_BASE + 0x0568) //ovldma,jpegdma
#define MMSYS_MDP_REQ_FLAG_REG                  (MMSYS_CONFIG_BASE + 0x0580)

#define REG_IMGDMA_MMSYS_MDP_MUX_SEL            *((volatile unsigned int *)IMGDMA_MMSYS_MDP_MUX_SEL_REG)
#define REG_MMSYS_RSZ_IRQ_FLAG                  *((volatile unsigned int *)MMSYS_RSZ_IRQ_FLAG_REG )
#define REG_MMSYS_ROT_DMA_IRQ_FLAG              *((volatile unsigned int *)MMSYS_ROT_DMA_IRQ_FLAG_REG)
#define REG_MMSYS_OVL_JPG_DMA_IRQ_FLAG          *((volatile unsigned int *)MMSYS_OVL_JPG_DMA_IRQ_FLAG_REG)
#define REG_MMSYS_MDP_REQ_FLAG                  *((volatile unsigned int *) MMSYS_MDP_REQ_FLAG_REG)
#else
#define REG_IMGDMA_MMSYS_MDP_MUX_SEL            (MMSYS_MDP_MUX_SEL)
//#define REG_MMSYS_RSZ_IRQ_FLAG                  
//#define REG_MMSYS_ROT_DMA_IRQ_FLAG              
//#define REG_MMSYS_OVL_JPG_DMA_IRQ_FLAG          
#define REG_MMSYS_MDP_REQ_FLAG                  (0xff) //dummy value

#endif
/* IMGDMA_MMSYS_MDP_MUX_SEL_REG */
#if defined(DRV_IDP_MT6276E2_SERIES)
#define IMGDMA_MMSYS_MUX_RESET() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
       ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0ff)));} while(0)
#else
#define IMGDMA_MMSYS_MUX_RESET() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x07f)));} while(0)
#endif
#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x00c))|0x0004);} while(0)
#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT1() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x00c)));} while(0)
#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x00c))|0x0008);} while(0)

#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x003))|0x0001);} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT1() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x003)));} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT2() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x003))|0x0002);} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x003))|0x0003);} while(0)

#define IMGDMA_MMSYS_MUX_CRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0030))|0x0010);} while(0)
#define IMGDMA_MMSYS_MUX_CRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0030)));} while(0)
#define IMGDMA_MMSYS_MUX_CRZ_SEL_CAM() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
        ((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0030))|0x0020);} while(0)

#if defined(DRV_IDP_MT6276E2_SERIES)
#define IMGDMA_MMSYS_MUX_VDOROT_SEL_MOUT1() \
	do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
		((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0040)));} while(0)

#define IMGDMA_MMSYS_MUX_VDOROT_SEL_MOUT2() \
	do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
		((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0040))|0x0040);} while(0)

#define IMGDMA_MMSYS_MUX_RGBROT0_SEL_MOUT1() \
	do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
		((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0080)));} while(0)
				
#define IMGDMA_MMSYS_MUX_RGBROT0_SEL_MOUT2() \
	do {REG_IMGDMA_MMSYS_MDP_MUX_SEL= \
		((REG_IMGDMA_MMSYS_MDP_MUX_SEL & (~0x0080))|0x0080);} while(0)
#endif

/* MMSYS_MDP_REQ_FLAG_REG */
#if defined(DRV_IDP_MT6276E2_SERIES)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_RGBROT1_REQ     0x10000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_RGBROT0_REQ     0x08000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_VDOROT_REQ     0x04000000
#else
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_ROT_DMA2_REQ     0x10000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_ROT_DMA1_REQ     0x08000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_LCD_ROT_DMA0_REQ     0x04000000
#endif
#define REG_MMSYS_MDP_REQ_FLAG_BIT_JPGDEC_BRZ_RDY       0x02000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_BRZ_MOUT3_REQ        0x01000000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MUX_CAM_REQ          0x00800000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_CAM_CRZ_REQ          0x00400000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_CRZ_OVL_REQ          0x00200000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_OVL_IPP_REQ          0x00100000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_IPP_MOUT1_REQ        0x00080000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_R_DMA_MOUT0_REQ      0x00040000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_JPEG_REQ             0x00020000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MUX_PRZ_REQ          0x00010000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_PRZ_MOUT2_REQ        0x00008000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MUX_VRZ_REQ          0x00004000
#if defined(DRV_IDP_MT6276E2_SERIES)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_VRZ_RGBROT1_REQ      0x00002000
#else
#define REG_MMSYS_MDP_REQ_FLAG_BIT_VRZ_ROT_DMA2_REQ     0x00002000
#endif
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_CAM_MUX_REQ    0x00001000
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_PRZ_MUX_REQ    0x00000800
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_VRZ_MUX_REQ    0x00000400
#if defined(DRV_IDP_MT6276E2_SERIES)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_VDOROT_REQ     0x00000200
#else
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_ROT_DMA0_REQ   0x00000200
#endif
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_PRZ_MUX_REQ    0x00000100
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_VRZ_MUX_REQ    0x00000080
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_JPG_DMA_REQ    0x00000040
#if defined(DRV_IDP_MT6276E2_SERIES)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT2_RGBROT0_REQ    0x00000020
#else
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT2_ROT_DMA1_REQ   0x00000020
#endif
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT2_VRZ_MUX_REQ    0x00000010
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_CAM_MUX_ERQ    0x00000008
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_PRZ_MUX_REQ    0x00000004
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_VRZ_MUX_REQ    0x00000002
#define REG_MMSYS_MDP_REQ_FLAG_BIT_GOVL_IRT_REQ         0x00000001

/* MMSYS_RSZ_IRQ_FLAG_REG */
#define MMSYS_RSZ_BRZ_IRQ_FLAG_BIT               0x0001
#define MMSYS_RSZ_VRZ_IRQ_FLAG_BIT               0x0002
#define MMSYS_RSZ_PRZ_IRQ_FLAG_BIT               0x0004

/* MMSYS_ROT_DMA_IRQ_FLAG_REG */
#if defined(DRV_IDP_MT6276E2_SERIES)
#define MMSYS_IRQ_FLAG_VDOROT_BIT                0x0001
#define MMSYS_IRQ_FLAG_RGBROT0_BIT               0x0002
#define MMSYS_IRQ_FLAG_RGBROT1_BIT               0x0004
#else
#define MMSYS_IRQ_FLAG_ROTDMA0_BIT               0x0001
#define MMSYS_IRQ_FLAG_ROTDMA1_BIT               0x0002
#define MMSYS_IRQ_FLAG_ROTDMA2_BIT               0x0004
#endif

/* MMSYS_OVL_JPG_DMA_IRQ_FLAG_REG */
#define MMSYS_IRQ_FLAG_OVLDMA                    0x0001
#define MMSYS_IRQ_FLAG_JPGDMA                    0x0002

#endif // defined(DRV_IDP_MT6276_SERIES)


#if defined(DRV_IDP_MT6256_SERIES)
#define MMSYS_CONFIG_BASE                       MMCONFG_base

#ifndef MDP_C_MODEL
#define MMSYS_MDP_REQ_FLAG_REG                  (MMSYS_CONFIG_BASE + 0x0020)
#define IMGDMA_MMSYS_MDP_CRZ_MUX_SEL_REG        (MMSYS_CONFIG_BASE + 0x0024)      
#define IMGDMA_MMSYS_MDP_PRZ_MUX_SEL_REG        (MMSYS_CONFIG_BASE + 0x0028)      
#define IMGDMA_MMSYS_MDP_VRZ_MUX_SEL_REG        (MMSYS_CONFIG_BASE + 0x002C)           

#define REG_MMSYS_MDP_REQ_FLAG                  *((volatile unsigned int *) MMSYS_MDP_REQ_FLAG_REG)
#define REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_CRZ_MUX_SEL_REG)      
#define REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_PRZ_MUX_SEL_REG)      
#define REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_VRZ_MUX_SEL_REG)      
#else

#endif

/* CRZ MUX SEL */
#define MMSYS_MDP_CRZ_MUX_SEL_MASK  0x03
#define CRZ_MUX_SEL_MOUT0   0x00
#define CRZ_MUX_SEL_MOUT3   0x01
#define CRZ_MUX_SEL_CAM     0x02


/* PRZ MUX SEL */
#define MMSYS_MDP_PRZ_MUX_SEL_MASK  0x03
#define PRZ_MUX_SEL_MOUT1   0x00
#define PRZ_MUX_SEL_MOUT0   0x01
#define PRZ_MUX_SEL_MOUT3   0x02

/* VRZ MUX SEL */
#define MMSYS_MDP_VRZ_MUX_SEL_MASK  0x03
#define VRZ_MUX_SEL_MOUT2   0x00
#define VRZ_MUX_SEL_MOUT0   0x01
#define VRZ_MUX_SEL_MOUT1   0x02
#define VRZ_MUX_SEL_MOUT3   0x03

/* IMGDMA_MMSYS_MDP_MUX_SEL_REG */
#define IMGDMA_MMSYS_MUX_RESET() \
    do { \
    	REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL = 0; \
    	REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL = 0; \
        REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL = 0; \
    } while(0)
#define IMGDMA_MMSYS_MUX_CRZ_SEL_CAM() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL & (~MMSYS_MDP_CRZ_MUX_SEL_MASK)) | CRZ_MUX_SEL_CAM);} while(0)
#define IMGDMA_MMSYS_MUX_CRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL & (~MMSYS_MDP_CRZ_MUX_SEL_MASK)) | CRZ_MUX_SEL_MOUT0);} while(0)
#define IMGDMA_MMSYS_MUX_CRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_CRZ_MUX_SEL & (~MMSYS_MDP_CRZ_MUX_SEL_MASK)) | CRZ_MUX_SEL_MOUT3);} while(0)

#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL & (~MMSYS_MDP_PRZ_MUX_SEL_MASK)) | PRZ_MUX_SEL_MOUT0);} while(0)
#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT1() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL & (~MMSYS_MDP_PRZ_MUX_SEL_MASK)) | PRZ_MUX_SEL_MOUT1);} while(0)
#define IMGDMA_MMSYS_MUX_PRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_PRZ_MUX_SEL & (~MMSYS_MDP_PRZ_MUX_SEL_MASK)) | PRZ_MUX_SEL_MOUT3);} while(0)

#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT0() \
    do {REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL & (~MMSYS_MDP_VRZ_MUX_SEL_MASK)) | VRZ_MUX_SEL_MOUT0);} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT1() \
    do {REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL & (~MMSYS_MDP_VRZ_MUX_SEL_MASK)) | VRZ_MUX_SEL_MOUT1);} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT2() \
    do {REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL & (~MMSYS_MDP_VRZ_MUX_SEL_MASK)) | VRZ_MUX_SEL_MOUT2);} while(0)
#define IMGDMA_MMSYS_MUX_VRZ_SEL_MOUT3() \
    do {REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL = \
        ((REG_IMGDMA_MMSYS_MDP_VRZ_MUX_SEL & (~MMSYS_MDP_VRZ_MUX_SEL_MASK)) | VRZ_MUX_SEL_MOUT3);} while(0)

/* MMSYS_MDP_REQ_FLAG_REG */
#define REG_MMSYS_MDP_REQ_FLAG_BIT_RDMA_2_MOUT0_REQ      ((kal_uint32)0x01 << 28)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_2_CRZ_REQ         ((kal_uint32)0x01 << 27)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_2_PRZ_REQ         ((kal_uint32)0x01 << 26)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT0_2_VRZ_REQ         ((kal_uint32)0x01 << 25)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_CAM_2_CRZ_REQ             ((kal_uint32)0x01 << 24)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_BLKC_RDY_REQ                ((kal_uint32)0x01 << 23)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_BRZ_2_MOUT3_REQ         ((kal_uint32)0x01 << 22)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_2_CRZ_REQ         ((kal_uint32)0x01 << 21)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_2_PRZ_REQ         ((kal_uint32)0x01 << 20)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT3_2_VRZ_REQ         ((kal_uint32)0x01 << 19)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_CRZ_IN_REQ                    ((kal_uint32)0x01 << 18)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_CRZ_OVL_REQ                  ((kal_uint32)0x01 << 17)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_OVL_IMGPROC_REQ          ((kal_uint32)0x01 << 16)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_IMGPROC_2_MOUT1_REQ ((kal_uint32)0x01 << 15)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_2_PRZ_REQ          ((kal_uint32)0x01 << 14)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_2_VRZ_REQ          ((kal_uint32)0x01 << 13)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_2_JPEGDMA_REQ ((kal_uint32)0x01 << 12)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT1_2_ROTDMA0_REQ ((kal_uint32)0x01 << 11)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_ROTDMA0_2_LCD_REQ      ((kal_uint32)0x01 << 10)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_PRZ_IN_REQ                      ((kal_uint32)0x01 << 9)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_PRZ_2_MOUT2_REQ           ((kal_uint32)0x01 << 8)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT2_2_VRZ_REQ           ((kal_uint32)0x01 << 7)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_MOUT2_2_ROTDMA1_REQ ((kal_uint32)0x01 << 6)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_ROTDMA1_2_LCD_REQ      ((kal_uint32)0x01 << 5)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_VRZ_IN_REQ                     ((kal_uint32)0x01 << 4)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_VRZ_2_ROTDMA2_REQ      ((kal_uint32)0x01 << 3)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_ROTDMA2_2_LCD_REQ      ((kal_uint32)0x01 << 2)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_JPEGDMA_2_CODEC_REQ  ((kal_uint32)0x01 << 1)
#define REG_MMSYS_MDP_REQ_FLAG_BIT_GOVL_2_ROTDMA3_REQ    ((kal_uint32)0x01 << 0)

#endif // defined(DRV_IDP_MT6256_SERIES)


#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#define RDMA_MAX_INPUT_WIDTH         (65535)
#define RDMA_MAX_INPUT_HEIGHT        (65535)
#define WDMA_MAX_OUTPUT_WIDTH        (65535)
#define WDMA_MAX_OUTPUT_HEIGHT       (65535)

/* bit mapping of RDMA input format mask */
#define IMGDMA_RDMA_CON_INPUT_FORMAT_MASK         0x00000007
#define IMGDMA_RDMA_CON_INPUT_FORMAT_ARGB8888     0x00000000
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB888       0x00000001
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB565       0x00000002
#define IMGDMA_RDMA_CON_INPUT_FORMAT_BGR888       0x00000003
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUYV422      0x00000004
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUV          0x00000005 /**< The sub sampling rate is defined by VH, UH, YH, VV, UV, YV */
#define IMGDMA_RDMA_CON_ROUND_BIT                 0x00000008 /**< rounding when output RGB format */
#define IMGDMA_RDMA_CON_RGB_ROUND_BIT             0x00000400 /**< rounding when input RGB 565 format */

//// Macro for computing the start addresses for U, V plane
//// Directly from spec P.5/135 of V1.10
#define SAMPLE_SHIFT(sample_code) \
    (kal_uint32)((0 == (kal_uint32)(sample_code)) ? 0 : ((kal_uint32)(sample_code) - 1))

typedef struct
{
    kal_uint32                y_start_addr;
    kal_uint32                u_start_addr;
    kal_uint32                v_start_addr;
} idp_yuv_base_addr;

/* Register address of Image DMA */
/* Examples
#define IMGDMA_STATUS_REG     (IMGDMA_base + 0x0000)
#define IMGDMA_INT_ACK_REG    (IMGDMA_base + 0x0004)
#define IMGDMA_SW_RESET_REG   (IMGDMA_base + 0x0010)
 */

/* Register access of Image DMA */
/* 
#define REG_IMGDMA_STATUS    *((volatile unsigned int *)(IMGDMA_base + 0x0000))
#define REG_IMGDMA_INT_ACK   *((volatile unsigned int *)(IMGDMA_base + 0x0004))
#define REG_IMGDMA_SW_RESET  *((volatile unsigned int *)(IMGDMA_base + 0x0010))
 */

/* bit mapping of image dma interrupt ACK register */
/* Seems no such global registers in IMGDMA of 6236
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
 */

/* bit mapping of IMAGE DMA status register */
/* Seems no such global registers in IMGDMA of 6236
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
 */


/* DRV_IDP_6238_SERIES_E2 */
/* Seems no such global registers in IMGDMA of 6236
#define IMGDMA_GMC_STATUS_IF_D_IS_BUSY         ((unsigned int)1 << 3)
#define IMGDMA_GMC_STATUS_IF_E_IS_BUSY         ((unsigned int)1 << 4)
#define IMGDMA_GMC_STATUS_IF_F_IS_BUSY         ((unsigned int)1 << 5)
 */
/* */

/* macros of image dma status register */
/* Examples
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
 */

/* macros of image dma interrupt ACK register */
/* Examples
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
 */

/* No such bit in MT6276
#define IMGDMA_SW_RESET_RESET_BIT            (1)
 */

/**
 * \brief R_DMA structure
 *
 * Programmers can use this structure to set up R_DMA0 and R_DMA1.
 */
typedef struct 
{
    kal_bool                  descriptor_mode; /**< KAL_TRUE for descriptor mode, KAL_FALSE for register mode (default). */
    kal_uint8                 queue_depth; 
    kal_bool                  bypass;
    kal_bool                  stall_prev_engine;
    kal_bool                  drop_prev_engine;

    kal_bool                  auto_loop; /**< auto loop */

    kal_bool                  frame_sync_en;

    kal_bool                  rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
#if defined(DRV_IDP_MT6276E2_SERIES)
    kal_bool 		      bByteSwap;
    kal_bool 		      bRGBSwap;
#endif
    
    /* Configs for register mode. */
    kal_bool                  input_rgb; /**< KAL_TRUE, SW only examine rgb_color_fmt */
    img_color_fmt_rgb_enum_t  rgb_color_fmt; /**< 0, using YUV format. Cannot be 0 when yuv_color_fmt is 0. */
    img_color_fmt_yuv_enum_t  yuv_color_fmt; /**< 0, using RGB format. Cannot be 0 when rgb_color_fmt is 0. */
    
    kal_uint32                y_base_addr; /**< y base address */
    kal_uint32                u_base_addr; /**< u base address */
    kal_uint32                v_base_addr; /**< v base address */
    
    kal_uint32                pixel_number; /**< pixel numbers. deprecated? */
    kal_uint16                source_width; /**< 16 bit unsigned. */
    kal_uint16                source_height; /**< 16 bit unsigned. */

    kal_bool                  pitch_enable; /**< pitch */
    kal_uint16                pitch_bytes; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 
    
    kal_bool                  clip; /**< clip enable, this was called "pan" in MT6238 */
    kal_uint16                clip_left; /**< start from 0. */
    kal_uint16                clip_right; /**< max. value: (source width) - 1. */
    kal_uint16                clip_top; /**< start from 0. */
    kal_uint16                clip_bottom; /**< max. value: (source height) - 1. */

    kal_uint16                bus_control_threshold;
    /* Common config for both descriptor and register modes. */
    kal_bool                  intr_en; /**< interrupt enable. */
    idp_lisr_intr_cb_t        intr_cb; /**< interrupt callback function pointer. */
    idp_lisr_intr_cb_param_t  intr_cb_param; /**< interrupt callback function param. */

    /* private section, client must not modify below members. */
    
    kal_uint32                _y_str_addr;
    kal_uint32                _u_str_addr;
    kal_uint32                _v_str_addr;

    //// For easy debugging...
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
}idp_imgdma_rdma_struct;

typedef struct
{
    kal_bool                  intr_en; /**< interrupt */
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;

    kal_bool                  bypass;
    kal_bool                  stall_prev_engine;
    kal_bool                  drop_prev_engine;

    kal_bool                  output_to_memory;
    kal_bool                  output_to_next_engine; /**< MOUT for WDMA0, ROT_DMA0 for WDMA1, none for WDMA2 */
    
    kal_bool                  auto_loop; /**< auto loop */

    kal_bool                  frame_sync_en;

    kal_bool                  rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
    
    kal_bool                  hw_trigger_lcd; /**< Not HW trigger LCD or HW sync w/ LCD (drop mode), only for WDMA0 and WDM1 */
    idp_lcd_hw_trigger_mode_t hw_trigger_mode;
    kal_bool                  hw_trigger_rst_wait_lcd;

    kal_bool                  output_rgb; /**< KAL_TRUE, SW only examine rgb_color_fmt */
    img_color_fmt_rgb_enum_t  rgb_color_fmt; /**< output rgb format */
    img_color_fmt_yuv_enum_t  yuv_color_fmt; /**< output yuv format */
    
    kal_uint8                 alpha_value;

    kal_uint8                 reg_mode_queue_depth; /**< if reg mode, [1, 3] */
    idp_yuv_base_addr         dest[3];

    /* 0th set of destination start addresses */
    kal_uint32                dest_base_address_0_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 0 */
    kal_uint32                dest_base_address_0_u;
    kal_uint32                dest_base_address_0_v;

    /* 1st set of destination start addresses */
    kal_uint32                dest_base_address_1_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 1 */
    kal_uint32                dest_base_address_1_u;
    kal_uint32                dest_base_address_1_v;

    /* 2nd set of destination start addresses */
    kal_uint32                dest_base_address_2_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 2 */
    kal_uint32                dest_base_address_2_u;
    kal_uint32                dest_base_address_2_v;
    
    kal_uint16                src_width; /**< image width, format alignment */
    kal_uint16                src_height; /**< image height, format alignment */
    
    kal_bool                  pitch_enable; /**< pitch */
    kal_uint16                pitch_w; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 
    
    kal_bool                  clip; /**< clip enable, this was called "pan" in MT6238 */
    kal_uint16                clip_left;
    kal_uint16                clip_right;
    kal_uint16                clip_top;
    kal_uint16                clip_bottom;

    //// For easy debugging...
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
} idp_imgdma_wdma_struct;

/**
 * Init IMGDMA HW engines
 */
extern void idp_imgdma_init(void);

/**
 * The LISR for IMGDMA interruption
 */
extern void image_dma_LISR(void);

#if defined(DRV_IDP_MT6276E2_SERIES)
extern void
idp_imgdma_rotdma_get_main_buff_parameters(
    kal_bool is_rgb_format,img_color_fmt_yuv_enum_t yuv_format,  
    kal_uint16 sample_rate, kal_bool fifo_mode, kal_uint32 clip_w,
    kal_uint32 main_lb_s_in_line, kal_uint32 *p_main_blk_w, kal_uint32 *p_main_buf_line_size,
    kal_uint32 * p_main_working_buff_size);


extern void
idp_imgdma_rotdma_get_sub_buff_parameters(
    kal_bool is_rgb_format,img_color_fmt_yuv_enum_t yuv_format,  
    kal_uint16 sample_rate, kal_bool fifo_mode, kal_bool resample_mode, kal_uint32 clip_w,
    kal_uint32 main_lb_s_in_line, kal_uint32 *p_sub_blk_w, kal_uint32 *p_sub_buf_line_size,
    kal_uint32 * p_sub_working_buff_size);


extern kal_bool
idp_imgdma_rotdma_get_dst_start_address_shift_byte(
    kal_bool                  input_rgb,
    img_color_fmt_rgb_enum_t  rgb_color_fmt,
    img_color_fmt_yuv_enum_t  yuv_color_fmt,
    img_rot_angle_enum_t      rot_angle,
    kal_uint32 y_dst_w_in_byte,
    kal_uint32 y_clip_w,
    kal_uint32 y_clip_h,    
    kal_uint32 *y_shift,
    kal_uint32 *uv_shift);

#endif

#endif // #if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)

#endif // __idp_imgdma_mt6276_h__
/** @} */
