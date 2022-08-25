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
 *    idp_imgdma_mout.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The header file of MMSYS MOUT of MT6236
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
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 11 23 2010 chrono.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_mout_mt6236_h__
#define __idp_imgdma_mout_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"

/* ===================================================
 *                        OVL
 * =================================================== */

/** \defgroup imgdma_mout MOUT
 * @{
 */
// IMGDMA MOUT register addresses
#define IMGDMA_MOUT_EN_REG            (MMSYS_CONFIG_BASE + 0x0508)
#define IMGDMA_MOUT_CLR_REG           (MMSYS_CONFIG_BASE + 0x0504)
#define IMGDMA_MOUT_SEL_REG           (MMSYS_CONFIG_BASE + 0x050c)
#define IMGDMA_MOUT_CON_REG           (MMSYS_CONFIG_BASE + 0x0510)

// IMGDMA MOUT access
#define REG_IMGDMA_MOUT_EN            *((volatile unsigned int *) IMGDMA_MOUT_EN_REG)
#define REG_IMGDMA_MOUT_CLR           *((volatile unsigned int *) IMGDMA_MOUT_CLR_REG)
#define REG_IMGDMA_MOUT_SEL           *((volatile unsigned int *) IMGDMA_MOUT_SEL_REG)
#define REG_IMGDMA_MOUT_CON           *((volatile unsigned int *) IMGDMA_MOUT_CON_REG)


// Multiple output selection
#define IMGDMA_MOUT_SEL_MASK              0x0000000f
#define IMGDMA_MOUT_SEL_JPG_DMA_BIT       0x00000001
#define IMGDMA_MOUT_SEL_ROT_DMA0_BIT      0x00000002
#define IMGDMA_MOUT_SEL_R_DMA1_BIT        0x00000004
#define IMGDMA_MOUT_SEL_DRZ_BIT           0x00000008

// Enable
#define IMGDMA_MOUT_START() \
    do { REG_IMGDMA_MOUT_EN = 0x1; } while(0)

// Disalbe
#define IMGDMA_MOUT_STOP() \
    do { REG_IMGDMA_MOUT_EN = 0x0; } while(0)

// Reset
#define IMGDMA_MOUT_RESET() \
    do { REG_IMGDMA_MOUT_CLR = 0x1; \
         REG_IMGDMA_MOUT_CLR = 0x0; } while(0)

// Enable frame sync
#define IMGDMA_MOUT_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MOUT_CON = 0x1; } while(0)

// Disable frame sync
#define IMGDMA_MOUT_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MOUT_CON = 0x0; } while(0)

// Output selection to JPG_DMA, ROT_DMA0, RDMA1, or DRZ
// Not recommended to use these macros during running...
#define IMGDMA_MOUT_OUTPUT_SELECTION(combination) \
    do { REG_IMGDMA_MOUT_SEL = (combination); } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_JPG_DMA() \
    do { REG_IMGDMA_MOUT_SEL |= IMGDMA_MOUT_SEL_JPG_DMA_BIT; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_ROT_DMA0() \
    do { REG_IMGDMA_MOUT_SEL |= IMGDMA_MOUT_SEL_ROT_DMA0_BIT; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_RDMA1() \
    do { REG_IMGDMA_MOUT_SEL |= IMGDMA_MOUT_SEL_R_DMA1_BIT; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_DRZ() \
    do { REG_IMGDMA_MOUT_SEL |= IMGDMA_MOUT_SEL_DRZ_BIT; } while(0)

#define IMGDMA_MOUT_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_MOUT_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

/**
 * \brief OVL structure
 *
 * Programmers can use this structure to set up IMGDMA MOUT.
 */
typedef struct
{
    kal_bool    frame_sync_en;
    kal_bool    output_jpgdma; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_rot_dma0; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_rdma1; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_drz; /**< KAL_TRUE or KAL_FALSE */
} idp_imgdma_mout_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_mout)

extern kal_bool idp_imgdma_mout_config_real(
  idp_imgdma_mout_struct * const mout_struct, 
  kal_bool const config_to_hardware);

extern kal_bool
idp_imgdma_mout_start_real(
    idp_imgdma_mout_struct const * const p_mout_struct);

extern kal_bool
idp_imgdma_mout_stop_real(
    idp_imgdma_mout_struct const * const p_mout_struct);

extern void
idp_imgdma_mout_open_real(void);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_mout_mt6236_h__

