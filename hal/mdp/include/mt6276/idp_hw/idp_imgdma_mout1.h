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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
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
 * MDP driver
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_mout1_mt6276_h__
#define __idp_imgdma_mout1_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"

/* ===================================================
 *                        MOUT1
 * =================================================== */

/** \defgroup imgdma_mout1 MOUT1
 * @{
 */
// IMGDMA MOUT1 register addresses
#ifndef MDP_C_MODEL
#define IMGDMA_MOUT1_EN_REG            (MMSYS_CONFIG_BASE + 0x0530)
#define IMGDMA_MOUT1_CLR_REG           (MMSYS_CONFIG_BASE + 0x0534)
#define IMGDMA_MOUT1_SEL_REG           (MMSYS_CONFIG_BASE + 0x0538)
#define IMGDMA_MOUT1_CON_REG           (MMSYS_CONFIG_BASE + 0x053c)

// IMGDMA MOUT1 access
#define REG_IMGDMA_MOUT1_EN            *((volatile unsigned int *) IMGDMA_MOUT1_EN_REG)
#define REG_IMGDMA_MOUT1_CLR           *((volatile unsigned int *) IMGDMA_MOUT1_CLR_REG)
#define REG_IMGDMA_MOUT1_SEL           *((volatile unsigned int *) IMGDMA_MOUT1_SEL_REG)
#define REG_IMGDMA_MOUT1_CON           *((volatile unsigned int *) IMGDMA_MOUT1_CON_REG)
#else
#define REG_IMGDMA_MOUT1_EN           (MMSYS_MDP_MOUT1_EN)
#define REG_IMGDMA_MOUT1_CLR          (MMSYS_MDP_MOUT1_CLR)
#define REG_IMGDMA_MOUT1_SEL          (MMSYS_MDP_MOUT1_SEL)
#define REG_IMGDMA_MOUT1_CON          (MMSYS_MDP_MOUT1_CON)
#endif //MDP_C_MODEL


// Multiple output selection
#define IMGDMA_MOUT1_SEL_MASK              0x0000000f
#if defined (DRV_IDP_MT6276E2_SERIES)
#define IMGDMA_MOUT1_SEL_VDOROT_BIT		0x00000001
#else
#define IMGDMA_MOUT1_SEL_ROT_DMA0_BIT      0x00000001
#endif
#define IMGDMA_MOUT1_SEL_PRZ_BIT           0x00000002
#define IMGDMA_MOUT1_SEL_VRZ_BIT           0x00000004
#define IMGDMA_MOUT1_SEL_JPG_DMA_BIT       0x00000008
#if defined (DRV_IDP_MT6276E2_SERIES)
#define IMGDMA_MOUT1_SEL_RGBROT0_BIT       0x00000010
#endif

// Enable
#define IMGDMA_MOUT1_START() \
    do { REG_IMGDMA_MOUT1_EN = 0x1; } while(0)

// Disalbe
#define IMGDMA_MOUT1_STOP() \
    do { REG_IMGDMA_MOUT1_EN = 0x0; } while(0)

// Reset
#define IMGDMA_MOUT1_RESET() \
    do { REG_IMGDMA_MOUT1_CLR = 0x1; \
         REG_IMGDMA_MOUT1_CLR = 0x0; } while(0)

// Enable frame sync
#define IMGDMA_MOUT1_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MOUT1_CON = 0x1; } while(0)

// Disable frame sync
#define IMGDMA_MOUT1_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MOUT1_CON = 0x0; } while(0)

// Output selection to JPG_DMA, ROT_DMA0, or VRZ
// Not recommended to use these macros during running...
#define IMGDMA_MOUT1_OUTPUT_SELECTION(combination) \
    do { REG_IMGDMA_MOUT1_SEL = (combination); } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_JPG_DMA() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_JPG_DMA_BIT; } while(0)

#if defined (DRV_IDP_MT6276E2_SERIES)
#define IMGDMA_MOUT1_OUTPUT_TO_VDOROT() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_VDOROT_BIT; } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_RGBROT0() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_RGBROT0_BIT; } while(0)
#else
#define IMGDMA_MOUT1_OUTPUT_TO_ROT_DMA0() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_ROT_DMA0_BIT; } while(0)
#endif

#define IMGDMA_MOUT1_OUTPUT_TO_PRZ() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_PRZ_BIT; } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_VRZ() \
    do { REG_IMGDMA_MOUT1_SEL |= IMGDMA_MOUT1_SEL_VRZ_BIT; } while(0)

#define IMGDMA_MOUT1_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_MOUT1_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)
#endif // defined(DRV_IDP_MT6276_SERIES)

#if defined(DRV_IDP_MT6256_SERIES)
#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"


/* ===================================================
 *                        MOUT1
 * =================================================== */

/** \defgroup imgdma_mout1 MOUT1
 * @{
 */
// IMGDMA MOUT1 register addresses
#ifndef MDP_C_MODEL
#define MMSYS_CONFIG_BASE                       MMCONFG_base
#define IMGDMA_MMSYS_MDP_MOUT1_SEL_REG          (MMSYS_CONFIG_BASE + 0x0034)      

// IMGDMA MOUT1 access
#define REG_IMGDMA_MMSYS_MDP_MOUT1_SEL          *((volatile unsigned int *)IMGDMA_MMSYS_MDP_MOUT1_SEL_REG)      
#else
#define REG_IMGDMA_MMSYS_MDP_MOUT1_SEL          (MMSYS_MDP_MOUT1_SEL)      
#endif

#define IMGDMA_MOUT1_EN                      ((kal_uint32)0x01 << 0)
#define IMGDMA_MOUT1_CLR                     ((kal_uint32)0x01 << 1)
#define IMGDMA_MOUT1_SEL                     ((kal_uint32)0x01 << 2)
    #define IMGDMA_MOUT1_SEL_MASK            ((kal_uint32)0x0F << 2)
    #define IMGDMA_MOUT1_SEL_PRZ_BIT         ((kal_uint32)0x01 << 2)
    #define IMGDMA_MOUT1_SEL_VRZ_BIT         ((kal_uint32)0x02 << 2)
    #define IMGDMA_MOUT1_SEL_JPEG_DMA_BIT    ((kal_uint32)0x04 << 2)
    #define IMGDMA_MOUT1_SEL_ROT_DMA0_BIT    ((kal_uint32)0x08 << 2)
#define IMGDMA_MOUT1_CON                     ((kal_uint32)0x01 << 6)

// Enable
#define IMGDMA_MOUT1_START() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_EN)) | IMGDMA_MOUT1_EN); } while(0)

// Disalbe
#define IMGDMA_MOUT1_STOP() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_EN)); } while(0)

// Reset
#define IMGDMA_MOUT1_RESET() \
    do { \
    	 REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_CLR)) | IMGDMA_MOUT1_CLR); \
         REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = 0; \
     } while(0)

// Enable frame sync
#define IMGDMA_MOUT1_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_CON)) | IMGDMA_MOUT1_CON); } while(0)

// Disable frame sync
#define IMGDMA_MOUT1_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_CON)); } while(0)

// Output selection to JPG_DMA, ROT_DMA0, or VRZ or PRZ
// Not recommended to use these macros during running...
#define IMGDMA_MOUT1_OUTPUT_SELECTION(combination) \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & (~IMGDMA_MOUT1_SEL_MASK)) | ((combination << 2) & IMGDMA_MOUT1_SEL_MASK)); } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_JPG_DMA() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL | IMGDMA_MOUT1_SEL_JPEG_DMA_BIT); } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_ROT_DMA0() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL | IMGDMA_MOUT1_SEL_ROT_DMA0_BIT); } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_PRZ() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL  | IMGDMA_MOUT1_SEL_PRZ_BIT); } while(0)

#define IMGDMA_MOUT1_OUTPUT_TO_VRZ() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT1_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL  | IMGDMA_MOUT1_SEL_VRZ_BIT); } while(0)

#define IMGDMA_MOUT1_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_MMSYS_MDP_MOUT1_SEL & IMGDMA_MOUT1_EN)) ? KAL_TRUE : KAL_FALSE)

#endif // defined(DRV_IDP_MT6256_SERIES)

/**
 * \brief OVL structure
 *
 * Programmers can use this structure to set up IMGDMA MOUT1.
 */
#if defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)
typedef struct
{
    kal_bool    frame_sync_en;
#if defined (DRV_IDP_MT6276E2_SERIES)
    kal_bool    output_vdorot; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_rgbrot0; /**< KAL_TRUE or KAL_FALSE */
#else	
    kal_bool    output_rotdma0; /**< KAL_TRUE or KAL_FALSE */
#endif	
    kal_bool    output_prz; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_vrz; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_jpgdma; /**< KAL_TRUE or KAL_FALSE */
} idp_imgdma_mout1_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_mout1)

extern kal_bool idp_imgdma_mout1_config_real(
  idp_imgdma_mout1_struct * const mout1_struct, 
    kal_bool const config_to_hardware);

extern kal_bool
idp_imgdma_mout1_start_real(
    idp_imgdma_mout1_struct const * const p_mout1_struct);

extern kal_bool
idp_imgdma_mout1_stop_real(
    idp_imgdma_mout1_struct const * const p_mout1_struct);

extern void
idp_imgdma_mout1_open_real(void);

/** @} */
#endif //#if defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276_SERIES)
#endif // __idp_imgdma_ovl_mt6276_h__
