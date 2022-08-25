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
 *   idp_resz.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   generic part of resizers
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_mt6255_h__
#define __idp_resz_mt6255_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6255_SERIES)

#include "reg_base.h"

#define U64 kal_uint32
#define RESZ_H_RATIO_SHIFT_BITS  20
#define RESZ_V_RATIO_SHIFT_BITS  20

#define MMSYS_CONFIG_BASE                          MMCONFG_base

#ifndef MDP_C_MODEL
#define IMGDMA_MMSYS_MDP_SEL_OUT_VRZ_REG          (MMSYS_CONFIG_BASE + 0x0048)
#define IMGDMA_MMSYS_MDP_SEL_IN_VRZ_REG           (MMSYS_CONFIG_BASE + 0x0074)
#define IMGDMA_MMSYS_MDP_SEL_IN_CRZ_REG           (MMSYS_CONFIG_BASE + 0x0078)

#define REG_IMGDMA_MMSYS_MDP_SEL_OUT_VRZ          *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_OUT_VRZ_REG)      
#define REG_IMGDMA_MMSYS_MDP_SEL_IN_VRZ           *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_IN_VRZ_REG)      
#define REG_IMGDMA_MMSYS_MDP_SEL_IN_CRZ           *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_IN_CRZ_REG)      
#else  // MDP_C_MODEL

#endif // MDP_C_MODEL

//VRZ OUT
#define IMGDMA_MMSYS_MUX_VRZ_OUT_SEL_NONE() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_VRZ = 0x03;} while(0)

#define IMGDMA_MMSYS_MUX_VRZ_OUT_SEL_VDOROT() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_VRZ = 0x01;} while(0)
                        
#define IMGDMA_MMSYS_MUX_VRZ_OUT_SEL_RGBROT0() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_VRZ = 0x00;} while(0)

//VRZ IN
#define IMGDMA_MMSYS_MUX_VRZ_IN_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VRZ = 0x03;} while(0)
  
#define IMGDMA_MMSYS_MUX_VRZ_IN_SEL_MOUT() \
    do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VRZ = 0x01;} while(0)
                                                             
#define IMGDMA_MMSYS_MUX_VRZ_IN_SEL_RDMA() \
    do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VRZ = 0x00;} while(0)
  
  //CRZ IN
#define IMGDMA_MMSYS_MUX_CRZ_IN_SEL_NONE() \
      do {REG_IMGDMA_MMSYS_MDP_SEL_IN_CRZ = 0x03;} while(0)
  
#define IMGDMA_MMSYS_MUX_CRZ_IN_SEL_CAMINF() \
    do {REG_IMGDMA_MMSYS_MDP_SEL_IN_CRZ = 0x01;} while(0)
  
#define IMGDMA_MMSYS_MUX_CRZ_IN_SEL_RDMA() \
    do {REG_IMGDMA_MMSYS_MDP_SEL_IN_CRZ = 0x00;} while(0)

extern void idp_resz_init(void);

#endif // #if defined(DRV_IDP_MT6255_SERIES)
#endif // __idp_resz_mt6255_h__

