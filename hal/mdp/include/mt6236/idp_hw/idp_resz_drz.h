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
 *    idp_resz_drz.h
 *
 * Project:
 * --------
 *    MAUI
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
 * 11 23 2010 chrono.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_drz_mt6236_h__
#define __idp_resz_drz_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "reg_base.h"
#include "idp_core.h"

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_resz.h"
#include "idp_hw_common.h"

/* ===============================================================
 *                       DRZ definition
 * =============================================================== */
/** \defgroup drz Drop resizer
 * \ingroup resizer
 * @{
 */
#define DRZ_BASE                    (DRZ_base)

#define DRZ_STR_REG                 (DRZ_BASE + 0x0000)
#define DRZ_CON_REG                 (DRZ_BASE + 0x0004)
#define DRZ_STA_REG                 (DRZ_BASE + 0x0008)
#define DRZ_ACKINT_REG              (DRZ_BASE + 0x000c)
#define DRZ_SRC_SIZE_REG            (DRZ_BASE + 0x0010)
#define DRZ_TAR_SIZE_REG            (DRZ_BASE + 0x0014)
#define DRZ_RAT_H_REG               (DRZ_BASE + 0x0020)
#define DRZ_RAT_V_REG               (DRZ_BASE + 0x0024)

#if !defined(MDP_C_MODEL)
#define REG_DRZ_STR                 *((volatile unsigned int *)(DRZ_STR_REG))
#define REG_DRZ_CON                 *((volatile unsigned int *)(DRZ_CON_REG))
#define REG_DRZ_STA                 *((volatile unsigned int *)(DRZ_STA_REG))
#define REG_DRZ_ACKINT              *((volatile unsigned int *)(DRZ_ACKINT_REG))
#define REG_DRZ_SRC_SIZE            *((volatile unsigned int *)(DRZ_SRC_SIZE_REG))
#define REG_DRZ_TAR_SIZE            *((volatile unsigned int *)(DRZ_TAR_SIZE_REG))
#define REG_DRZ_RAT_H               *((volatile unsigned int *)(DRZ_RAT_H_REG))
#define REG_DRZ_RAT_V               *((volatile unsigned int *)(DRZ_RAT_V_REG))
#else // #if !defined(MDP_C_MODEL)
#define REG_DRZ_STR                 (DRZ_STR)
#define REG_DRZ_CON                 (DRZ_CON)
#define REG_DRZ_STA                 (DRZ_STA)
#define REG_DRZ_ACKINT              (DRZ_ACKINT)
#define REG_DRZ_SRC_SIZE            (DRZ_SRC_SIZE)
#define REG_DRZ_TAR_SIZE            (DRZ_TAR_SIZE)
#define REG_DRZ_RAT_H               (DRZ_RAT_H)
#define REG_DRZ_RAT_V               (DRZ_RAT_V)
#endif // #if !defined(MDP_C_MODEL)



/**
 * \def DRZ_IS_STARTED()
 * \brief Check if DRZ is started or not.
 */
#define DRZ_IS_STARTED() \
    ((0x1 == (REG_DRZ_STR & 0x1)) ? KAL_TRUE : KAL_FALSE)

/* macros of DRZ start register */
#define DRZ_START() \
    do { REG_DRZ_STR = 1; } while(0)
    
#define DRZ_STOP() \
    do { REG_DRZ_STR = 0; } while(0)

#define DRZ_CON_IT_BIT              0x00000001
#define DRZ_CON_INIT_BIT            0x00000002
#define DRZ_CON_BYPASS_BIT          0x00000004
#define DRZ_CON_AUTORSTR_BIT        0x00000008

#define DRZ_INTERRUPT_ENABLE() \
    do { REG_DRZ_CON |= DRZ_CON_IT_BIT; } while(0)
    
#define DRZ_INTERRUPT_DISABLE() \
    do { REG_DRZ_CON &= ~DRZ_CON_IT_BIT; } while(0)

#define DRZ_FRAME_SYNC_ENABLE() \
    do { REG_DRZ_CON |= DRZ_CON_INIT_BIT; } while(0)

#define DRZ_FRAME_SYNC_DISABLE() \
    do { REG_DRZ_CON &= ~DRZ_CON_INIT_BIT; } while(0)

#define DRZ_BYPASS_ENABLE() \
    do { REG_DRZ_CON |= DRZ_CON_BYPASS_BIT; } while(0)

#define DRZ_BYPASS_DISABLE() \
    do { REG_DRZ_CON &= ~DRZ_CON_BYPASS_BIT; } while(0)

#define DRZ_AUTO_RESTART_ENABLE() \
    do { REG_DRZ_CON |= DRZ_CON_AUTORSTR_BIT; } while(0)

#define DRZ_AUTO_RESTART_DISABLE() \
    do { REG_DRZ_CON &= ~DRZ_CON_AUTORSTR_BIT; } while(0)

#define DRZ_STA_RUN_BIT 0x00010000
#define DRZ_STA_IT_BIT  0x00000001

/* macros of DRZ status register */
#define DRZ_IS_RUNNING() \
    ((DRZ_STA_RUN_BIT == (REG_DRZ_STA & DRZ_STA_RUN_BIT)) ? KAL_TRUE : KAL_FALSE)

/* macros of DRZ interrupt ACK register */
#define DRZ_ACK_INT() \
    do { REG_DRZ_ACKINT = 0x1; } while(0)

#define DRZ_SET_SRC_SIZE(height, width) \
    do { REG_DRZ_SRC_SIZE = \
        (((width)-1) & 0x0fff) | \
        ((((height)-1) & 0x0fff) << 16); } while(0)


#define DRZ_SET_TAR_SIZE(height, width) \
    do { REG_DRZ_TAR_SIZE = \
        (((width)-1) & 0x0fff) | \
        ((((height)-1) & 0x0fff) << 16); } while(0)


typedef struct
{
    kal_bool                  auto_restart;
    kal_bool                  hw_frame_sync;
    kal_bool                  bypass;

    kal_bool                  intr_en;
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;

    kal_uint16                src_height; /**< [1, 4096] */
    kal_uint16                src_width; /**< [1, 4096] */
    kal_uint16                tar_height; /**< [1, 4096] */
    kal_uint16                tar_width; /**< [1, 4096] */
} idp_resz_drz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_drz)

extern kal_bool 
idp_resz_drz_config_real(
    idp_resz_drz_struct * const p_drz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_drz_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_resz_drz_struct * const p_drz_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern void
idp_resz_drz_open_real(void);

extern kal_bool
idp_resz_drz_start_real(
    idp_resz_drz_struct const * const p_drz_struct);

extern kal_bool
idp_resz_drz_stop_real(
    idp_resz_drz_struct const * const p_drz_struct);

/** @} */
#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_resz_drz_mt6236_h__

