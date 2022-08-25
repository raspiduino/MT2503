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

#ifndef __idp_resz_drz_mt6238_h__
#define __idp_resz_drz_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include "idp_core.h"
#include "idp_resz.h"
#include "idp_hw_common.h"

/* ===============================================================
 *                       DRZ definition
 * =============================================================== */
/** \defgroup drz Drop resizer
 * \ingroup resizer
 * @{
 */
#define DRZ_START_REG             (DRZ_base + 0x00)
#define DRZ_CONFIG_REG            (DRZ_base + 0x04)
#define DRZ_STATUS_REG            (DRZ_base + 0x08)
#define DRZ_INT_ACK_REG           (DRZ_base + 0x0C)
#define DRZ_SOURCE_IMAGE_SIZE_REG (DRZ_base + 0x10)
#define DRZ_TARGET_IMAGE_SIZE_REG (DRZ_base + 0x14)
#define DRZ_H_RATIO_REG           (DRZ_base + 0x20)
#define DRZ_V_RATIO_REG           (DRZ_base + 0x24)
#define DRZ_DEBUG_INFO            (DRZ_base + 0x30)

#define REG_DRZ_START             *((volatile unsigned int *)(DRZ_base + 0x00))
#define REG_DRZ_CONFIG            *((volatile unsigned int *)(DRZ_base + 0x04))
#define REG_DRZ_STATUS            *((volatile unsigned int *)(DRZ_base + 0x08))
#define REG_DRZ_INT_ACK           *((volatile unsigned int *)(DRZ_base + 0x0C))
#define REG_DRZ_SOURCE_IMAGE_SIZE *((volatile unsigned int *)(DRZ_base + 0x10))
#define REG_DRZ_TARGET_IMAGE_SIZE *((volatile unsigned int *)(DRZ_base + 0x14))
#define REG_DRZ_H_RATIO           *((volatile unsigned int *)(DRZ_base + 0x20))
#define REG_DRZ_V_RATIO           *((volatile unsigned int *)(DRZ_base + 0x24))

/* bit mapping of DRZ configuration register */
#define DRZ_CONFIG_INTR_ENABLE_BIT    0x00000001
#if defined (MT6268)
#define DRZ_CONFIG_INIT_PROCESS_BIT   0x00000002
#endif // chip option
#define DRZ_CONFIG_AUTO_RESTART_BIT   0x00000008
#if defined (MT6268)
// TODO: don't know if this is a hidden register bit
#else // chip option MT6238
#define DRZ_CONFIG_PIXEL_SEL_BIT      0x00000010
#endif // chip option

/* bit mapping of DRZ status register */
#define DRZ_STATUS_INT_BIT     0x00000001
#define DRZ_STATUS_BUSY_BIT    0x00010000

/* bit mapping of DRZ interrupt acknowledge register */
#define DRZ_INT_ACK_BIT      0x00000001

/**
 * \brief Check if DRZ is started or not.
 */
#define IS_DRZ_START()                                                  \
  ((0x1 == (REG_DRZ_START & 0x1))                                       \
   ? KAL_TRUE                                                           \
   : KAL_FALSE)

/* macros of DRZ start register */
#define START_DRZ()  do { REG_DRZ_START = 1; } while(0)
#define STOP_DRZ()   do { REG_DRZ_START = 0; } while(0)

/* macros of DRZ configuration register */
#if defined (MT6268)
// TODO: check if this is still in use in MT6268B
#else // chip option MT6238 MT6268A
#define SET_DRZ_SRC_VIDEO_ENCODE_DMA() do { REG_DRZ_CONFIG &= ~DRZ_CONFIG_PIXEL_SEL_BIT; } while(0)
#define SET_DRZ_SRC_IBW3_DMA()         do { REG_DRZ_CONFIG |= DRZ_CONFIG_PIXEL_SEL_BIT; } while(0)
#endif // chip option
#define ENABLE_DRZ_AUTO_RESTART()      do { REG_DRZ_CONFIG |= DRZ_CONFIG_AUTO_RESTART_BIT; } while(0)
#define DISABLE_DRZ_AUTO_RESTART()     do { REG_DRZ_CONFIG &= ~DRZ_CONFIG_AUTO_RESTART_BIT; } while(0)
#define ENABLE_DRZ_INT()               do { REG_DRZ_CONFIG |= DRZ_CONFIG_INTR_ENABLE_BIT; } while(0)
#define DISABLE_DRZ_INT()              do { REG_DRZ_CONFIG &= ~DRZ_CONFIG_INTR_ENABLE_BIT; } while(0)
#if defined (MT6268)
#define ENABLE_DRZ_HW_FRAME_SYNC()     do { REG_DRZ_CONFIG |= DRZ_CONFIG_INIT_PROCESS_BIT; } while(0)
#define DISABLE_DRZ_HW_FRAME_SYNC()    do { REG_DRZ_CONFIG &= ~DRZ_CONFIG_INIT_PROCESS_BIT; } while(0)
#endif // chip option

/* macros of DRZ status register */
#define DRZ_IS_RUNNING (REG_DRZ_STATUS & DRZ_STATUS_BUSY_BIT)

/* macros of DRZ interrupt ACK register */
#define ACK_DRZ_INT() do { REG_DRZ_INT_ACK = DRZ_INT_ACK_BIT; } while(0)

typedef struct
{
  idp_module_enum_t         image_src;
  kal_bool                  auto_restart;

  kal_bool                  intr_en; 
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_uint16                src_height;
  kal_uint16                src_width;
  kal_uint16                tar_height;
  kal_uint16                tar_width;
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_resz_drz_struct;
/** @} */

IDP_HW_COMMON_API_DECLARATION(resz_drz)

extern kal_bool idp_resz_drz_config_real(
    idp_resz_drz_struct * const drz_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_resz_drz_stop_real(
  idp_resz_drz_struct const * const drz_struct);

extern kal_bool idp_resz_drz_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_resz_drz_struct * const drz_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_resz_drz_close_real(void);

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_resz_drz_mt6238_h__
