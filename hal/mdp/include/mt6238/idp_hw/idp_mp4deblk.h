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
 *   mt6238_mp4deblk.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   MPEG4 deblocking filter
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

/** \ingroup idp
 * @{
 */
/** \defgroup mp4deblk MPEG4 deblocking
 * @{
 */
#ifndef __idp_mp4deblk_mt6238_h__
#define __idp_mp4deblk_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include <idp_core.h>
#include "img_common_enum.h"

/* register definition of MP4 DEBLOCK */
#define MP4DEBLK_CMMD_REG        (MP4_DEBLK_base + 0x0000)
#define MP4DEBLK_CONF_REG        (MP4_DEBLK_base + 0x0004)
#define MP4DEBLK_STS_REG         (MP4_DEBLK_base + 0x0008)
#define MP4DEBLK_IRQ_STS_REG     (MP4_DEBLK_base + 0x000C)
#define MP4DEBLK_IRQ_ACK_REG     (MP4_DEBLK_base + 0x0010)
#define MP4DEBLK_LIN_BUF_ADDR_REG (MP4_DEBLK_base + 0x0014)
#define MP4DEBLK_QUANT_ADDR_REG   (MP4_DEBLK_base + 0x0018)

#define REG_MP4DEBLK_CMMD         *((volatile unsigned int *)(MP4_DEBLK_base + 0x0000))
#define REG_MP4DEBLK_CONF         *((volatile unsigned int *)(MP4_DEBLK_base + 0x0004))
#define REG_MP4DEBLK_STS          *((volatile unsigned int *)(MP4_DEBLK_base + 0x0008))
#define REG_MP4DEBLK_IRQ_STS      *((volatile unsigned int *)(MP4_DEBLK_base + 0x000C))
#define REG_MP4DEBLK_IRQ_ACK      *((volatile unsigned int *)(MP4_DEBLK_base + 0x0010))
#define REG_MP4DEBLK_LIN_BUF_ADDR *((volatile unsigned int *)(MP4_DEBLK_base + 0x0014))
#define REG_MP4DEBLK_QUANT_ADDR   *((volatile unsigned int *)(MP4_DEBLK_base + 0x0018))

/* bit mapping of image dma interrupt ACK register */
#define MP4DEBLK_CMMD_CORE_RST_BIT     0X0001
#define MP4DEBLK_CMMD_CORE_APB_BIT     0X0002
#define MP4DEBLK_CMMD_START_BIT        0X0004

#define MP4DEBLK_CONF_IRQ_BIT          0X00000001
#define MP4DEBLK_CONF_ENABLE_BIT       0X00000002
#define MP4DEBLK_CONF_ROTATE_MASK      0X0000000C
#define MP4DEBLK_CONF_FLIP_BIT         0X00000010
#define MP4DEBLK_CONF_MB_XLIMIT_MASK   0X0000FF00
#define MP4DEBLK_CONF_MB_YLIMIT_MASK   0X00FF0000
#define MP4DEBLK_CONF_CRZ_EN_BIT       0X01000000
#define MP4DEBLK_CONF_PRZ_EN_BIT       0X02000000
#define MP4DEBLK_CONF_IPP_EN_BIT       0X04000000

/**
 * \brief Check if IBR2 is started or not.
 */
#define IS_MP4DEBLK_START()                                            \
  ((MP4DEBLK_CMMD_START_BIT == (REG_MP4DEBLK_CMMD & MP4DEBLK_CMMD_START_BIT)) \
   ? KAL_TRUE                                                           \
   : KAL_FALSE)

/* macros of mp4 deblock */
#define ENABLE_MP4DEBLK_CORE_RST() do { REG_MP4DEBLK_CMMD |= MP4DEBLK_CMMD_CORE_RST_BIT; } while(0)
#define ENABLE_MP4DEBLK_APB_RST() do { REG_MP4DEBLK_CMMD |= MP4DEBLK_CMMD_CORE_APB_BIT; } while(0)

#define START_MP4DEBLK()  do { REG_MP4DEBLK_CMMD |= MP4DEBLK_CMMD_START_BIT; } while(0)
#define STOP_MP4DEBLK()   do { REG_MP4DEBLK_CMMD &= ~MP4DEBLK_CMMD_START_BIT; } while(0)

#define ENABLE_MP4DEBLK_IRQ() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_IRQ_BIT; } while(0)
#define DISABLE_MP4DEBLK_IRQ() do { REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_IRQ_BIT; } while(0)
   
#define ENABLE_MP4DEBLK_FILTER() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_ENABLE_BIT; } while(0)
#define DISABLE_MP4DEBLK_FILTER() do { REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_ENABLE_BIT; } while(0)

#define SET_MP4DEBLK_ROTATE(rot)                       \
  do {                                                  \
    REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_ROTATE_MASK ; \
    REG_MP4DEBLK_CONF |= (rot<<2);                     \
  } while(0)

#define ENABLE_MP4DEBLK_FLIP() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_FLIP_BIT; } while(0)
#define DISABLE_MP4DEBLK_FLIP() do { REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_FLIP_BIT; } while(0)

#define SET_MP4DEBLK_XLIMIT(limit)                         \
  do {                                                      \
    REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_MB_XLIMIT_MASK ;  \
    REG_MP4DEBLK_CONF |= (limit<<8);                       \
  } while(0)

#define SET_MP4DEBLK_YLIMIT(limit)                         \
  do {                                                      \
    REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_MB_YLIMIT_MASK ;  \
    REG_MP4DEBLK_CONF |= (limit<<16);                      \
  } while(0)

#define ENABLE_MP4DEBLK_OUTPUT_CRZ() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_CRZ_EN_BIT; } while(0)
#define DISABLE_MP4DEBLK_OUTPUT_CRZ() do { REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_CRZ_EN_BIT; } while(0)
#define ENABLE_MP4DEBLK_OUTPUT_PRZ() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_PRZ_EN_BIT; } while(0)
#define DISABLE_MP4DEBLK_OUTPUT_PRZ() do {REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_PRZ_EN_BIT; } while(0)
#define ENABLE_MP4DEBLK_OUTPUT_IPP() do { REG_MP4DEBLK_CONF |= MP4DEBLK_CONF_IPP_EN_BIT; } while(0)
#define DISABLE_MP4DEBLK_OUTPUT_IPP() do { REG_MP4DEBLK_CONF &= ~MP4DEBLK_CONF_IPP_EN_BIT; } while(0)
   
#define ACK_MP4DEBLK_INT() do { REG_MP4DEBLK_IRQ_ACK = 1; } while(0)

/**
 * \brief MPEG4 deblocking structure
 *
 * Programmers can use this structure to set up MPEG4
 * deblocking.
 */
typedef struct
{
  kal_uint16  width;              /**< decode width */
  kal_uint16  height;             /**< decode height */

  kal_bool    intr_en;         /**< done interrupt */
  idp_lisr_intr_cb_t intr_cb;
  idp_lisr_intr_cb_param_t intr_cb_param;
  
  img_rot_angle_enum_t rot_angle;         /**< rotate value */
  kal_bool    flip_enable;        /**< flip */
  kal_bool    output_crz;         /**< output to crz */
  kal_bool    output_prz;         /**< output to prz */
  kal_bool    output_ipp;         /**< output to ipp */
  kal_uint32 fifo_addr;           /**< line buffer addr */
  kal_uint32 quant_addr;          /**< quant addr */
} idp_mp4deblk_struct;

IDP_HW_COMMON_API_DECLARATION(mp4deblk)

extern kal_bool idp_mp4deblk_config_real(
    idp_mp4deblk_struct * const mp4deblk_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_mp4deblk_stop_real(
  idp_mp4deblk_struct const * const mp4deblk_struct);

extern kal_bool idp_mp4deblk_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_mp4deblk_struct * const mp4deblk_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_mp4deblk_close_real(void);

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_mp4deblk_mt6238_h__
/** @} */
/** @} */
