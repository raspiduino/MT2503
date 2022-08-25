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

#ifndef __idp_imgproc_y2r1_mt6238_h__
#define __idp_imgproc_y2r1_mt6238_h__

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

#define IMGPROC_Y2R1_CFG        (IMGPROC_base + 0x0008)
#define IMGPROC_Y2R1_SDTCON     (IMGPROC_base + 0x0010)
#define IMGPROC_Y2R1_RGB_DETECT (IMGPROC_base + 0x032C)
#define IMGPROC_Y2R1_RGB_RPLACE (IMGPROC_base + 0x0330)

#define REG_IMGPROC_Y2R1_CFG         *((volatile unsigned int *)(IMGPROC_base + 0x0008))
#define REG_IMGPROC_Y2R1_SDTCON      *((volatile unsigned int *)(IMGPROC_base + 0x0010))
#define REG_IMGPROC_Y2R1_RGB_DETECT  *((volatile unsigned int *)(IMGPROC_base + 0x032C))
#define REG_IMGPROC_Y2R1_RGB_RPLACE  *((volatile unsigned int *)(IMGPROC_base + 0x0330))

/*bit define of IMGPROC_Y2R1_CFG*/ 
#define IMGPROC_Y2R1_CFG_R2Y1_EN_BIT         0X00000001            
#define IMGPROC_Y2R1_CFG_ROUND_R2Y1_BIT      0X00000002            
#define IMGPROC_Y2R1_CFG_SDT2_EN_BIT         0X00000004            
#define IMGPROC_Y2R1_CFG_SDT3_EN_BIT         0X00000008            
#define IMGPROC_Y2R1_CFG_RGB_DETECT_EN_BIT   0X00000010            

/*Y2R1 source and outout selection*/
#define IMGPROC_Y2R1_IO_CRZ_TO_Y2R1        0X00000100
#define IMGPROC_Y2R1_IO_PRZ_TO_Y2R1        0X00000200
#define IMGPROC_Y2R1_IO_DRZ_TO_Y2R1        0X00000400
#define IMGPROC_Y2R1_IO_Y2R1_TO_IBW1       0X00000800

#define SET_IMGPROC_Y2R1_SRC(src)                                 \
  do {                                                            \
    REG_IMGPROC_R2Y_SRC &= ~IMGPROC_R2Y_SRC_Y2R1_IO_MASK ;        \
    REG_IMGPROC_R2Y_SRC |= ((src)&IMGPROC_R2Y_SRC_Y2R1_IO_MASK);  \
  } while(0)
 
#define ENABLE_Y2R1()                 REG_IMGPROC_Y2R1_CFG|= IMGPROC_Y2R1_CFG_R2Y1_EN_BIT;
#define DISABLE_Y2R1()                REG_IMGPROC_Y2R1_CFG &= ~IMGPROC_Y2R1_CFG_R2Y1_EN_BIT; 
#define ENABLE_Y2R1_ROUND()           REG_IMGPROC_Y2R1_CFG|= IMGPROC_Y2R1_CFG_ROUND_R2Y1_BIT;
#define DISABLE_Y2R1_ROUND()          REG_IMGPROC_Y2R1_CFG &= ~IMGPROC_Y2R1_CFG_ROUND_R2Y1_BIT; 
#define ENABLE_Y2R1_SDT2()            REG_IMGPROC_Y2R1_CFG|= IMGPROC_Y2R1_CFG_SDT2_EN_BIT;
#define DISABLE_Y2R1_SDT2()           REG_IMGPROC_Y2R1_CFG &= ~IMGPROC_Y2R1_CFG_SDT2_EN_BIT; 
#define ENABLE_Y2R1_SDT3()            REG_IMGPROC_Y2R1_CFG|= IMGPROC_Y2R1_CFG_SDT3_EN_BIT;
#define DISABLE_Y2R1_SDT3()           REG_IMGPROC_Y2R1_CFG &= ~IMGPROC_Y2R1_CFG_SDT3_EN_BIT; 
#define ENABLE_Y2R1_RGB_DETECT()      REG_IMGPROC_Y2R1_CFG|= IMGPROC_Y2R1_CFG_RGB_DETECT_EN_BIT;
#define DISABLE_Y2R1_RGB_DETECT()     REG_IMGPROC_Y2R1_CFG &= ~IMGPROC_Y2R1_CFG_RGB_DETECT_EN_BIT;

#define SET_IPP_Y2R1_DETECT(r,g,b)   REG_IMGPROC_Y2R1_RGB_DETECT =(r<<16)|(g<<8)|(b);
#define SET_IPP_Y2R1_REPLACE(r,g,b)  REG_IMGPROC_Y2R1_RGB_RPLACE =(r<<16)|(g<<8)|(b);

#define ENABLE_IMGPROC_HW_Y2R1()     REG_IMGPROC_EN |= IMGPROC_HW_Y2R1_ENABLE_BIT;
#define DISABLE_IMGPROC_HW_Y2R1()    REG_IMGPROC_EN &= ~IMGPROC_HW_Y2R1_ENABLE_BIT; 

struct idp_imgproc_y2r1_struct
{
  idp_module_enum_t image_src;
  idp_module_enum_t image_dest;
  
  kal_bool          enable_rgb_dithering;

#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool          hw_frame_sync; /* KAL_TRUE: enable, KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
};
typedef struct idp_imgproc_y2r1_struct idp_imgproc_y2r1_struct;

IDP_HW_COMMON_API_DECLARATION(imgproc_y2r1)

extern kal_bool idp_imgproc_y2r1_stop_real(
  idp_imgproc_y2r1_struct const * const y2r1_struct);

extern kal_bool idp_imgproc_y2r1_is_busy_real(
  kal_bool * const busy,
  idp_imgproc_y2r1_struct const * const y2r1_struct);

extern kal_bool idp_imgproc_y2r1_start_real(
  idp_imgproc_y2r1_struct const * const y2r1_struct);

extern void idp_imgproc_y2r1_close_real(void);

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgproc_y2r1_mt6238_h__
