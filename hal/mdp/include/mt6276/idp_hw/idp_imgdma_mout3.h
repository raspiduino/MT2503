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

#ifndef __idp_imgdma_mout3_mt6276_h__
#define __idp_imgdma_mout3_mt6276_h__

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
 *                        MOUT3
 * =================================================== */
#ifndef MDP_C_MODEL
#define IMGDMA_MOUT3_EN_REG            (MMSYS_CONFIG_BASE + 0x0550)
#define IMGDMA_MOUT3_CLR_REG           (MMSYS_CONFIG_BASE + 0x0554)
#define IMGDMA_MOUT3_SEL_REG           (MMSYS_CONFIG_BASE + 0x0558)
#define IMGDMA_MOUT3_CON_REG           (MMSYS_CONFIG_BASE + 0x055c)

// IMGDMA MOUT3 access
#define REG_IMGDMA_MOUT3_EN            *((volatile unsigned int *) IMGDMA_MOUT3_EN_REG)
#define REG_IMGDMA_MOUT3_CLR           *((volatile unsigned int *) IMGDMA_MOUT3_CLR_REG)
#define REG_IMGDMA_MOUT3_SEL           *((volatile unsigned int *) IMGDMA_MOUT3_SEL_REG)
#define REG_IMGDMA_MOUT3_CON           *((volatile unsigned int *) IMGDMA_MOUT3_CON_REG)
#else
#define REG_IMGDMA_MOUT3_EN           (MMSYS_MDP_MOUT3_EN)
#define REG_IMGDMA_MOUT3_CLR          (MMSYS_MDP_MOUT3_CLR)
#define REG_IMGDMA_MOUT3_SEL          (MMSYS_MDP_MOUT3_SEL)
#define REG_IMGDMA_MOUT3_CON          (MMSYS_MDP_MOUT3_CON)
#endif //MDP_C_MODEL

// Multiple output selection
#define IMGDMA_MOUT3_SEL_MASK         0x00000007
#define IMGDMA_MOUT3_SEL_CAM_BIT      0x00000001
#define IMGDMA_MOUT3_SEL_PRZ_BIT      0x00000002
#define IMGDMA_MOUT3_SEL_VRZ_BIT      0x00000004

// MOUT3 Enable
#define IMGDMA_MOUT3_START() \
    do { REG_IMGDMA_MOUT3_EN = 0x1; } while(0)

// MOUT3 Disalbe
#define IMGDMA_MOUT3_STOP() \
    do { REG_IMGDMA_MOUT3_EN = 0x0; } while(0)

// MOUT3 Reset
#define IMGDMA_MOUT3_RESET() \
    do { REG_IMGDMA_MOUT3_CLR = 0x1; \
         REG_IMGDMA_MOUT3_CLR = 0x0; } while(0)

// MOUT3 Enable frame sync
#define IMGDMA_MOUT3_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MOUT3_CON = 0x1; } while(0)

// MOUT3 Disable frame sync
#define IMGDMA_MOUT3_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MOUT3_CON = 0x0; } while(0)

// Output selection to ROT_DMA1 or VRZ
// Not recommended to use these macros during running...
#define IMGDMA_MOUT3_OUTPUT_SELECTION(combination) \
    do { REG_IMGDMA_MOUT3_SEL = (combination); } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_CRZ() \
    do { REG_IMGDMA_MOUT3_SEL |= IMGDMA_MOUT3_SEL_CAM_BIT; } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_PRZ() \
    do { REG_IMGDMA_MOUT3_SEL |= IMGDMA_MOUT3_SEL_PRZ_BIT; } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_VRZ() \
    do { REG_IMGDMA_MOUT3_SEL |= IMGDMA_MOUT3_SEL_VRZ_BIT; } while(0)

#define IMGDMA_MOUT3_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_MOUT3_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

#endif // defined(DRV_IDP_MT6276_SERIES)


#if defined(DRV_IDP_MT6256_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"

/* ===================================================
 *                        MOUT3
 * =================================================== */
#ifndef MDP_C_MODEL
#define MMSYS_CONFIG_BASE                       MMCONFG_base
#define IMGDMA_MMSYS_MDP_MOUT3_SEL_REG          (MMSYS_CONFIG_BASE + 0x003C)      

// IMGDMA MOUT0 access
#define REG_IMGDMA_MMSYS_MDP_MOUT3_SEL          *((volatile unsigned int *)IMGDMA_MMSYS_MDP_MOUT3_SEL_REG)      
#else
#define REG_IMGDMA_MMSYS_MDP_MOUT3_SEL          (MMSYS_MDP_MOUT3_SEL)      
#endif

#define IMGDMA_MOUT3_EN                  ((kal_uint32)0x01 << 0)
#define IMGDMA_MOUT3_CLR                 ((kal_uint32)0x01 << 1)
#define IMGDMA_MOUT3_SEL                 ((kal_uint32)0x01 << 2)
    #define IMGDMA_MOUT3_SEL_MASK        ((kal_uint32)0x0F << 2)
    #define IMGDMA_MOUT3_SEL_VRZ_BIT     ((kal_uint32)0x01 << 2)
    #define IMGDMA_MOUT3_SEL_PRZ_BIT     ((kal_uint32)0x02 << 2)
    #define IMGDMA_MOUT3_SEL_CRZ_BIT     ((kal_uint32)0x04 << 2)
#define IMGDMA_MOUT3_CON                 ((kal_uint32)0x01 << 6)

// MOUT3 Enable
#define IMGDMA_MOUT3_START() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_EN)) | IMGDMA_MOUT3_EN); } while(0)

// MOUT3 Disalbe
#define IMGDMA_MOUT3_STOP() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_EN)); } while(0)

// MOUT3 Reset
#define IMGDMA_MOUT3_RESET() \
    do { \
    	 REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_CLR)) | IMGDMA_MOUT3_CLR); \
         REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
         (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_CLR)); \
     } while(0)

// MOUT3 Enable frame sync
#define IMGDMA_MOUT3_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_CON)) | IMGDMA_MOUT3_CON); } while(0)

// MOUT3 Disable frame sync
#define IMGDMA_MOUT3_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_CON)); } while(0)

// Output selection to ROT_DMA1 or VRZ
// Not recommended to use these macros during running...
#define IMGDMA_MOUT3_OUTPUT_SELECTION(combination) \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL = \
    	 ((REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & (~IMGDMA_MOUT3_SEL_MASK)) | ((combination << 2) & IMGDMA_MOUT3_SEL_MASK)); } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_CRZ() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL  | IMGDMA_MOUT3_SEL_CRZ_BIT); } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_PRZ() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL  | IMGDMA_MOUT3_SEL_PRZ_BIT); } while(0)

#define IMGDMA_MOUT3_OUTPUT_TO_VRZ() \
    do { REG_IMGDMA_MMSYS_MDP_MOUT3_SEL =\
    	 (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL | IMGDMA_MOUT3_SEL_VRZ_BIT); } while(0)


#define IMGDMA_MOUT3_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_MMSYS_MDP_MOUT3_SEL & IMGDMA_MOUT3_EN)) ? KAL_TRUE : KAL_FALSE)
#endif // defined(DRV_IDP_MT6256_SERIES)


/**
 * \brief OVL structure
 *
 * Programmers can use this structure to set up IMGDMA MOUT3.
 */
#if defined(DRV_IDP_MT6256_SERIES)|| defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

typedef struct
{
    kal_bool    frame_sync_en;
    kal_bool    output_crz; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_prz; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_vrz; /**< KAL_TRUE or KAL_FALSE */
} idp_imgdma_mout3_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_mout3)

extern kal_bool idp_imgdma_mout3_config_real(
  idp_imgdma_mout3_struct * const mout3_struct, 
    kal_bool const config_to_hardware);

extern kal_bool
idp_imgdma_mout3_start_real(
    idp_imgdma_mout3_struct const * const p_mout3_struct);

extern kal_bool
idp_imgdma_mout3_stop_real(
    idp_imgdma_mout3_struct const * const p_mout3_struct);

extern void
idp_imgdma_mout3_open_real(void);

/** @} */
#endif //#if defined(DRV_IDP_MT6256_SERIES)|| defined(DRV_IDP_MT6276_SERIES)

#endif // __idp_imgdma_ovl_mt6276_h__
