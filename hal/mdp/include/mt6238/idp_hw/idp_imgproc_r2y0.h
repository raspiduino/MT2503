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
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 18 2010 ct.fang
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgproc_r2y0_mt6238_h__
#define __idp_imgproc_r2y0_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include "idp_core.h"
#include "idp_imgproc.h"
#include "idp_hw_common.h"

#define IMGPROC_R2Y0_CFG      (IMGPROC_base + 0x0004)

#define REG_IMGPROC_R2Y0_CFG      *((volatile unsigned int *)(IMGPROC_base + 0x0004))

/*bit define of IMGPROC_R2Y0_CFG*/ 
#define IMGPROC_R2Y0_CFG_R2Y0_EN_BIT         0X00000001            
#define IMGPROC_R2Y0_CFG_ROUND_R2Y0_BIT      0X00000002            

/*R2Y0 source and outout selection*/
#define IMGPROC_R2Y0_IO_IRT2_TO_R2Y0       0X00010000
#define IMGPROC_R2Y0_IO_IBR1_TO_R2Y0       0X00020000
#define IMGPROC_R2Y0_IO_R2Y0_TO_CRZ        0X00080000
#define IMGPROC_R2Y0_IO_R2Y0_TO_PRZ        0X00100000

#define ENABLE_R2Y0()            REG_IMGPROC_R2Y0_CFG|= IMGPROC_R2Y0_CFG_R2Y0_EN_BIT;
#define DISABLE_R2Y0()           REG_IMGPROC_R2Y0_CFG &= ~IMGPROC_R2Y0_CFG_R2Y0_EN_BIT;
#define ENABLE_R2Y0_ROUND()      REG_IMGPROC_R2Y0_CFG|= IMGPROC_R2Y0_CFG_ROUND_R2Y0_BIT;
#define DISABLE_R2Y0_ROUND()     REG_IMGPROC_R2Y0_CFG &= ~IMGPROC_R2Y0_CFG_ROUND_R2Y0_BIT;

#define ENABLE_IMGPROC_HW_R2Y0()     REG_IMGPROC_EN |= IMGPROC_HW_R2Y0_ENABLE_BIT;
#define DISABLE_IMGPROC_HW_R2Y0()    REG_IMGPROC_EN &= ~IMGPROC_HW_R2Y0_ENABLE_BIT; 

#define SET_IMGPROC_R2Y0_SRC(src)                                 \
  do {                                                            \
    REG_IMGPROC_R2Y_SRC &= ~IMGPROC_R2Y_SRC_R2Y0_IO_MASK ;        \
    REG_IMGPROC_R2Y_SRC |= ((src)&IMGPROC_R2Y_SRC_R2Y0_IO_MASK);  \
  } while(0)

struct idp_imgproc_r2y0_struct
{
  idp_module_enum_t image_src;
  idp_module_enum_t image_dest;
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool          hw_frame_sync; /**< KAL_TRUE: enable, KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
};
typedef struct idp_imgproc_r2y0_struct idp_imgproc_r2y0_struct;

IDP_HW_COMMON_API_DECLARATION(imgproc_r2y0)

extern kal_bool idp_imgproc_r2y0_stop_real(
  idp_imgproc_r2y0_struct const * const r2y0_struct);

extern kal_bool idp_imgproc_r2y0_is_busy_real(
  kal_bool * const busy,
  idp_imgproc_r2y0_struct const * const r2y0_struct);

extern kal_bool idp_imgproc_r2y0_start_real(
  idp_imgproc_r2y0_struct const * const r2y0_struct);

extern void idp_imgproc_r2y0_close_real(void);

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgproc_r2y0_mt6238_h__
