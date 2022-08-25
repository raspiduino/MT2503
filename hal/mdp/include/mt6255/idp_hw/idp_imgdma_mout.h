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
 *   idp_imgdma_mout.h
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
 * 05 08 2012 chrono.wu
 * removed!
 * .
 *
 * 12 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 24 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 13 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_mout_mt6255_h__
#define __idp_imgdma_mout_mt6255_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6255_SERIES)

#include "idp_imgdma.h"

#ifndef MDP_C_MODEL
  #define IMGDMA_MOUT_REG            (MMSYS_CONFIG_BASE + 0x084)
  #define REG_IMGDMA_MOUT            *((volatile unsigned int *) IMGDMA_MOUT_REG)
#else  //MDP_C_MODEL
  #define REG_IMGDMA_MOUT            //(MMSYS_MDP_MOUT0_EN)
#endif //MDP_C_MODEL

// control bit
#define IMGDMA_MOUT_EN_BIT           0x00000001
#define IMGDMA_MOUT_CLR_BIT          0x00000002
#define IMGDMA_MOUT_CON_BIT          0x00000004

// Multiple output selection
#define IMGDMA_MOUT_SEL_MASK         0x00000038
#define IMGDMA_MOUT_SEL_RGB_ROT0_BIT 0x00000008
#define IMGDMA_MOUT_SEL_VDO_ROT_BIT  0x00000010
#define IMGDMA_MOUT_SEL_VRZ_BIT      0x00000020

// MOUT Enable
#define IMGDMA_MOUT_START() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_EN_BIT; } while(0)

// MOUT Disalbe
#define IMGDMA_MOUT_STOP() \
    do { REG_IMGDMA_MOUT &= ~IMGDMA_MOUT_EN_BIT; } while(0)

// MOUT is enabled ?
#define IMGDMA_MOUT_IS_ENABLED() \
    ((IMGDMA_MOUT_EN_BIT == (REG_IMGDMA_MOUT & IMGDMA_MOUT_EN_BIT)) ? KAL_TRUE : KAL_FALSE)

// MOUT Reset
#define IMGDMA_MOUT_RESET() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_CLR_BIT; \
         REG_IMGDMA_MOUT &= ~IMGDMA_MOUT_CLR_BIT; } while(0)

// MOUT Enable frame sync
#define IMGDMA_MOUT_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_CON_BIT; } while(0)

// MOUT Disable frame sync
#define IMGDMA_MOUT_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_MOUT &= ~IMGDMA_MOUT_CON_BIT; } while(0)

// Output selection, not recommended to use these macros during running...
#define IMGDMA_MOUT_OUTPUT_CLEAR() \
    do { REG_IMGDMA_MOUT &= ~IMGDMA_MOUT_SEL_MASK; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_RGB_ROT0() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_SEL_RGB_ROT0_BIT; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_VDO_ROT() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_SEL_VDO_ROT_BIT; } while(0)

#define IMGDMA_MOUT_OUTPUT_TO_VRZ() \
    do { REG_IMGDMA_MOUT |= IMGDMA_MOUT_SEL_VRZ_BIT; } while(0)


typedef struct
{
    kal_bool    frame_sync_en; /**< KAL_TRUE or KAL_FALSE */
    kal_bool    output_vdo_rot;
    kal_bool    output_rgb_rot0;
    kal_bool    output_vrz;
} idp_imgdma_mout_struct;

extern kal_bool idp_imgdma_mout_config_real(
    idp_imgdma_mout_struct * const p_mout_struct, 
    kal_bool const config_to_hardware);


extern kal_bool
idp_imgdma_mout_start_real(
    idp_imgdma_mout_struct const * const p_mout_struct);

extern kal_bool
idp_imgdma_mout_stop_real(
    idp_imgdma_mout_struct const * const p_mout_struct);

extern void
idp_imgdma_mout0_open_real(void);


IDP_HW_COMMON_API_DECLARATION(imgdma_mout)


#endif // #if defined(DRV_IDP_MT6255_SERIES)
#endif // __idp_imgdma_mout_mt6255_h__

