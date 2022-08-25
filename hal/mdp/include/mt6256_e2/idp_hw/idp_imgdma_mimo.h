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
 *   idp_imgdma_mimo.h
 * Project:
 * --------
 *   Maui
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
 * 02 23 2012 chelun.tsai
 * removed!
 * .
 *
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 06 17 2011 chelun.tsai
 * removed!
 * MDP.
 *
 * 05 19 2011 chelun.tsai
 * removed!
 * camera capture ok.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_mimo_mt6256_e2_h__
#define __idp_imgdma_mimo_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

#include <idp_core.h>

#ifndef MDP_C_MODEL
  #define IMGDMA_MIMO_REG            (MMSYS_CONFIG_BASE + 0x080)
  #define REG_IMGDMA_MIMO            *((volatile unsigned int *) IMGDMA_MIMO_REG)
#else  //MDP_C_MODEL
  #define REG_IMGDMA_MIMO            //(MMSYS_MDP_MIMO_EN)
#endif //MDP_C_MODEL

// control bit
#define IMGDMA_MIMO_EN_BIT           0x00000001
#define IMGDMA_MIMO_CLR_BIT          0x00000002
#define IMGDMA_MIMO_CON_BIT          0x00000004

// Multiple output selection
#define IMGDMA_MIMO_OUT_MASK         0x00000E00
#define IMGDMA_MIMO_OUT_IPP_BIT      0x00000200
#define IMGDMA_MIMO_OUT_PRZ_BIT      0x00000400
#define IMGDMA_MIMO_OUT_MUX_BIT      0x00000800

// MIMO Enable
#define IMGDMA_MIMO_START() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_EN_BIT; } while(0)

// MIMO Disalbe
#define IMGDMA_MIMO_STOP() \
    do { REG_IMGDMA_MIMO &= ~IMGDMA_MIMO_EN_BIT; } while(0)

// MIMO is enabled ?
#define IMGDMA_MIMO_IS_ENABLED() \
    ((IMGDMA_MIMO_EN_BIT == (REG_IMGDMA_MIMO & IMGDMA_MIMO_EN_BIT)) ? KAL_TRUE : KAL_FALSE)

// MIMO Reset
#define IMGDMA_MIMO_RESET() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_CLR_BIT; \
         REG_IMGDMA_MIMO &= ~IMGDMA_MIMO_CLR_BIT; } while(0)

// MIMO Enable frame sync
#define IMGDMA_MIMO_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_CON_BIT; } while(0)

// MIMO Disable frame sync
#define IMGDMA_MIMO_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MIMO &= ~IMGDMA_MIMO_CON_BIT; } while(0)

// Output selection, not recommended to use these macros during running...
#define IMGDMA_MIMO_OUTPUT_CLEAR() \
    do { REG_IMGDMA_MIMO &= ~IMGDMA_MIMO_OUT_MASK; } while(0)

#define IMGDMA_MIMO_OUTPUT_TO_IPP() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_OUT_IPP_BIT; } while(0)

#define IMGDMA_MIMO_OUTPUT_TO_PRZ() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_OUT_PRZ_BIT; } while(0)

#define IMGDMA_MIMO_OUTPUT_TO_MUX() \
    do { REG_IMGDMA_MIMO |= IMGDMA_MIMO_OUT_MUX_BIT; } while(0)


typedef struct
{
    kal_bool    frame_sync_en; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_ipp;
    kal_bool    output_prz;
    kal_bool    output_mux;
} idp_imgdma_mimo_struct;

extern kal_bool idp_imgdma_mimo_start_real(
    idp_imgdma_mimo_struct const * const p_mimo_struct);
    
extern kal_bool idp_imgdma_mimo_config_real(
    idp_imgdma_mimo_struct * const p_mimo_struct, 
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_mimo_stop_real(
    idp_imgdma_mimo_struct const * const p_mimo_struct);


IDP_HW_COMMON_API_DECLARATION(imgdma_mimo)


#endif // #if defined(DRV_IDP_MT6256_E2_SERIES)
#endif // __idp_imgdma_mimo_mt6256_e2_h__

