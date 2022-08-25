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
 *   mt6238_imgproc.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   image processor
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
 * add to source control recursely
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * \defgroup imgproc Image processor
 * \ingroup idp
 * @{
 */
#ifndef __idp_imgproc_mt6238_h__
#define __idp_imgproc_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"

#define NO_ERROR 0

#define IMGPROC_R2Y_SRC         (IMGPROC_base + 0x0318)
#define IMGPROC_EN              (IMGPROC_base + 0x0320)

#define REG_IMGPROC_R2Y_SRC          *((volatile unsigned int *)(IMGPROC_base + 0x0318))
#define REG_IMGPROC_EN               *((volatile unsigned int *)(IMGPROC_base + 0x0320))

/*bit define of IMGPROC_R2Y_SRC*/ 
#if defined(MT6268)
#define IMGPROC_R2Y_SRC_IPP_IO_MASK         0X000000FF
#else // chip option MT6238 MT6268A
#define IMGPROC_R2Y_SRC_IPP_IO_MASK         0X0000007F
#endif // chip option
#define IMGPROC_R2Y_SRC_Y2R1_IO_MASK        0X00000F00            
#define IMGPROC_R2Y_SRC_R2Y0_IO_MASK        0X001F0000

/*bit define of IMGPROC_EN*/ 
#define IMGPROC_HW_IPP_ENABLE_BIT         0x00000001            
#define IMGPROC_HW_R2Y0_ENABLE_BIT        0x00000010            
#define IMGPROC_HW_Y2R1_ENABLE_BIT        0x00000100
#define IMGPROC_RESET_BIT                 0x00001000
#if defined(MT6268)
#define IMGPROC_INIT_ENABLE_BIT           0x00002000
#endif // chip option

#define ENABLE_IPP                                      \
  do {                                                  \
    REG_IMGPROC_EN |= IMGPROC_HW_IPP_ENABLE_BIT;        \
    REG_IMGPROC_EN |= IMGPROC_HW_R2Y0_ENABLE_BIT;       \
    REG_IMGPROC_EN |= IMGPROC_HW_Y2R1_ENABLE_BIT;       \
  } while(0)

#define DISABLE_IPP                                     \
  do {                                                  \
    REG_IMGPROC_EN &= ~IMGPROC_HW_IPP_ENABLE_BIT;       \
    REG_IMGPROC_EN &= ~IMGPROC_HW_R2Y0_ENABLE_BIT;      \
    REG_IMGPROC_EN &= ~IMGPROC_HW_Y2R1_ENABLE_BIT;      \
  } while(0)

#define RESET_IPP                                   \
  do {                                              \
    REG_IMGPROC_EN &= ~IMGPROC_RESET_BIT;           \
    REG_IMGPROC_EN |= IMGPROC_RESET_BIT;            \
  } while(0)

#if defined(MT6268)
// IPP frame sync bit
#define ENABLE_IMGPROC_HW_FRAME_SYNC()      do { REG_IMGPROC_EN |= IMGPROC_INIT_ENABLE_BIT; } while (0)
#define DISABLE_IMGPROC_HW_FRAME_SYNC()     do { REG_IMGPROC_EN &= ~IMGPROC_INIT_ENABLE_BIT; } while (0)
#endif // chip option

extern void idp_imgproc_init(void);

#endif
#endif //IMGPROC_H
/** @} */
