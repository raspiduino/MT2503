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
 * 06 29 2011 chrono.wu
 * removed!
 * .
 *
 * 03 21 2011 chrono.wu
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

#ifndef __idp_resz_prz_mt6276_h__
#define __idp_resz_prz_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "idp_imgdma.h"

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#include "idp_resz.h"
#include "idp_hw_common.h"

#include "..\idp_mem.h"

#include "reg_base.h"
#include "idp_core.h"

/* ===============================================================
 *                       PRZ definition
 * =============================================================== */
/** \defgroup prz Post processing resizer
 * \ingroup resizer
 * @{
 */
// register addresses
#ifndef MDP_C_MODEL
#define PRZ_BASE PRZ_base
#define PRZ_CFG_REG                 (PRZ_BASE + 0x0000)
#define PRZ_CON_REG                 (PRZ_BASE + 0x0004)
#define PRZ_STA_REG                 (PRZ_BASE + 0x0008)
#define PRZ_INT_REG                 (PRZ_BASE + 0x000c)
#define PRZ_SRCSZ1_REG              (PRZ_BASE + 0x0010)
#define PRZ_TARSZ1_REG              (PRZ_BASE + 0x0014)
#define PRZ_HRATIO1_REG             (PRZ_BASE + 0x0018)
#define PRZ_VRATIO1_REG             (PRZ_BASE + 0x001c)
#define PRZ_FRCFG_REG               (PRZ_BASE + 0x0040)

// register accesses
#define REG_PRZ_CFG                 *((volatile unsigned int *)(PRZ_CFG_REG))
#define REG_PRZ_CON                 *((volatile unsigned int *)(PRZ_CON_REG))
#define REG_PRZ_STA                 *((volatile unsigned int *)(PRZ_STA_REG))
#define REG_PRZ_INT                 *((volatile unsigned int *)(PRZ_INT_REG))
#define REG_PRZ_SRCSZ1              *((volatile unsigned int *)(PRZ_SRCSZ1_REG))
#define REG_PRZ_TARSZ1              *((volatile unsigned int *)(PRZ_TARSZ1_REG))
#define REG_PRZ_HRATIO1             *((volatile unsigned int *)(PRZ_HRATIO1_REG))
#define REG_PRZ_VRATIO1             *((volatile unsigned int *)(PRZ_VRATIO1_REG))
#define REG_PRZ_FRCFG               *((volatile unsigned int *)(PRZ_FRCFG_REG))
#else // !defined(MDP_C_MODEL)
#define REG_PRZ_CFG                 (PRZ_CFG      )
#define REG_PRZ_CON                 (PRZ_CON      )
#define REG_PRZ_STA                 (PRZ_STA      )
#define REG_PRZ_INT                 (PRZ_INT      )
#define REG_PRZ_SRCSZ1              (PRZ_SRCSZ1   )
#define REG_PRZ_TARSZ1              (PRZ_TARSZ1   )
#define REG_PRZ_HRATIO1             (PRZ_HRATIO1  )
#define REG_PRZ_VRATIO1             (PRZ_VRATIO1  )
#define REG_PRZ_FRCFG               (PRZ_FRCFG    )
#endif // !defined(MDP_C_MODEL)

#define IDP_RESZ_PRZ_RESZ_MAX_INPUT_WIDTH    (8191)
#define IDP_RESZ_PRZ_RESZ_MAX_INPUT_HEIGHT   (8191)

#define IDP_RESZ_PRZ_RESZ_MAX_OUTPUT_WIDTH   (8191)
#define IDP_RESZ_PRZ_RESZ_MAX_OUTPUT_HEIGHT  (8191)

/* PRZ configuration register */
#define PRZ_CFG_PCON_BIT                0x00000100
#define PRZ_CFG_LBSEL_BIT               0x00000200
#define PRZ_CFG_INTEN0_BIT              0x00000400
#define PRZ_CFG_INTEN1_BIT              0x00000800
#define PRZ_CFG_ECV_BIT                 0x00001000
#define PRZ_CFG_EE_BIT                  0x00002000
#define PRZ_CFG_NORFDB_BIT              0x00004000
#define PRZ_CFG_BYPASS_BIT              0x00008000
#define PRZ_CFG_LBMAX_MASK              0x03ff0000
#define PRZ_CFG_INIT_BIT                0x80000000

/* PRZ control register */
#define PRZ_CON_ENA_BIT       0x00000001
#define PRZ_CON_RST_BIT       0x00010000

/* PRZ interrupt register */
#define PRZ_INT_FEDINT_BIT              0x00000001
#define PRZ_INT_FSTINT_BIT              0x00000002

/* PRZ coefficient table register */
#define PRZ_FRCFG_DSEL_MASK             (0x0000001f)
#define PRZ_FRCFG_USEL_MASK             (0x00001f00)
#define PRZ_FRCFG_EE_VSTR_MASK          (0x000f0000)
#define PRZ_FRCFG_EE_HSTR_MASK          (0x00f00000)

#define PRZ_FRCFG_DSEL_DEFAULT          (15)
#define PRZ_FRCFG_USEL_DEFAULT          (8)
#define PRZ_FRCFG_UDSEL_LINEAR_INTERPO  (0)
#define PRZ_FRCFG_EE_VSTR_DEFAULT       (4)
#define PRZ_FRCFG_EE_HSTR_DEFAULT       (0)

#define PRZ_SET_SINGLE_RUN() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_PCON_BIT; } while(0)

#define PRZ_SET_CONTINUOUS_RUN() \
    do { REG_PRZ_CFG |= PRZ_CFG_PCON_BIT; } while(0)

/*
 * TODO: check with Abrams if no vertical resize, do we need to enable dedicated line buffer, and if no enable it, does power consumption can improve?
 */
#define PRZ_LBSEL_CANNOT_WORK() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_LBSEL_BIT; } while(0)
    
#define PRZ_LBSEL_USE_DEDICATE_LINE_BUFFER() \
    do { REG_PRZ_CFG |= PRZ_CFG_LBSEL_BIT; } while(0)

#define PRZ_FRAME_END_INTERRUPT_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_INTEN0_BIT; } while(0)

#define PRZ_FRAME_END_INTERRUPT_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_INTEN0_BIT; } while(0)

#define PRZ_FRAME_START_INTERRUPT_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_INTEN1_BIT; } while(0)

#define PRZ_FRAME_START_INTERRUPT_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_INTEN1_BIT; } while(0)

#define PRZ_ECV_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_ECV_BIT; } while(0)

#define PRZ_ECV_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_ECV_BIT; } while(0)

#define PRZ_EDGE_ENHANCE_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_EE_BIT; } while(0)

#define PRZ_EDGE_ENHANCE_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_EE_BIT; } while(0)

#define PRZ_REGISER_DOUBLE_BUFFER_ENABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_NORFDB_BIT; } while(0)

#define PRZ_REGISER_DOUBLE_BUFFER_DISABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_NORFDB_BIT; } while(0)

#define PRZ_BYPASS_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_BYPASS_BIT; } while(0)

#define PRZ_BYPASS_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_BYPASS_BIT; } while(0)

#define PRZ_SET_LBMAX(lbmax) \
    do { REG_PRZ_CFG = \
        ((REG_PRZ_CFG & ~PRZ_CFG_LBMAX_MASK) | \
         (PRZ_CFG_LBMAX_MASK & ((lbmax) << 16))); } while(0)

#define PRZ_FRAME_SYNC_ENABLE() \
    do { REG_PRZ_CFG |= PRZ_CFG_INIT_BIT; } while(0)

#define PRZ_FRAME_SYNC_DISABLE() \
    do { REG_PRZ_CFG &= ~PRZ_CFG_INIT_BIT; } while(0)


/**
 * \brief Check if PRZ is started or not.
 */
#define IS_PRZ_START() \
    (((REG_PRZ_CON & PRZ_CON_ENA_BIT) == 0x1) ? KAL_TRUE : KAL_FALSE)

#define PRZ_RESET() \
    do { REG_PRZ_CON = PRZ_CON_RST_BIT; \
         REG_PRZ_CON = 0; } while(0)

#define PRZ_START() \
    do { REG_PRZ_CON = PRZ_CON_ENA_BIT; } while(0)

#define PRZ_IS_BUSY_IN_OUT() \
    (((REG_PRZ_STA & 0x3) != 0x0) ? KAL_TRUE : KAL_FALSE)


#define PRZ_SET_DSEL(dsel) \
    do { REG_PRZ_FRCFG = \
        ((REG_PRZ_FRCFG & ~PRZ_FRCFG_DSEL_MASK) | \
         (PRZ_FRCFG_DSEL_MASK & ((dsel) << 0))); } while(0)

#define PRZ_SET_USEL(usel) \
    do { REG_PRZ_FRCFG = \
        ((REG_PRZ_FRCFG & ~PRZ_FRCFG_USEL_MASK) | \
         (PRZ_FRCFG_USEL_MASK & ((usel) << 8))); } while(0)

#define PRZ_SET_EE_VSTR(ee_vstr) \
    do { REG_PRZ_FRCFG = \
        ((REG_PRZ_FRCFG & ~PRZ_FRCFG_EE_VSTR_MASK) | \
         (PRZ_FRCFG_EE_VSTR_MASK & ((ee_vstr) << 16))); } while(0)

#define PRZ_SET_EE_HSTR(ee_hstr) \
    do { REG_PRZ_FRCFG = \
        ((REG_PRZ_FRCFG & ~PRZ_FRCFG_EE_HSTR_MASK) | \
         (PRZ_FRCFG_EE_HSTR_MASK & ((ee_hstr) << 20))); } while(0)


typedef struct
{    
    kal_bool                  no_dedicate_memory;
    kal_bool                  continous;
    idp_module_enum_t         input_src;
    kal_bool                  frame_end_intr_en; 
    idp_lisr_intr_cb_t        frame_end_intr_cb;
    idp_lisr_intr_cb_param_t  frame_end_intr_cb_param;
    
    kal_bool                  frame_start_intr_en; 
    idp_lisr_intr_cb_t        frame_start_intr_cb;
    idp_lisr_intr_cb_param_t  frame_start_intr_cb_param;
    
    kal_uint16                src_height; /**< [1, 8191] */
    kal_uint16                src_width; /**< [1, 8191] */
    kal_uint16                tar_height; /**< [1, 640] */
    kal_uint16                tar_width; /**< [1, 640] */

    kal_bool                  ecv; /**< KAL_TRUE, enable EC algorithm for vertical downscaling. */

    kal_bool                  ee; /**< KAL_TRUE, enable edge enhancement. */
    kal_uint8                 ee_horizontal_strength;
    kal_uint8                 ee_vertical_strength;

    kal_bool                  no_double_buffering_for_registers; /**< KAL_TRUE, disable double buffering for some registers. */

    kal_bool                  bypass; /**< KAL_TRUE, bypass PRZ. */

    kal_bool                  hw_frame_sync; /**< KAL_TRUE, enable HW frame sync. all previous engines must turn on frame sync to make this effective. */

    kal_bool                  udsel_not_default;
    kal_uint32                usel;
    kal_uint32                dsel;
} idp_resz_prz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_prz)

extern void *idp_resz_prz_frame_end_intr_cb_param;
extern void (*idp_resz_prz_frame_end_intr_cb)(void *);

extern void *idp_resz_prz_frame_start_intr_cb_param;
extern void (*idp_resz_prz_frame_start_intr_cb)(void *);

extern kal_bool 
idp_resz_prz_config_real(
    idp_resz_prz_struct * const p_prz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_prz_get_working_mem_real(
    kal_bool use_internal_mem,
    idp_resz_prz_struct * const p_prz_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);
    
extern void
idp_resz_prz_open_real(void);

extern kal_bool
idp_resz_prz_start_real(
    idp_resz_prz_struct const * const p_prz_struct);

extern kal_bool
idp_resz_prz_stop_real(
    idp_resz_prz_struct const * const p_prz_struct);

/** @} */

#endif // defined(DRV_IDP_MT6276_SERIES)
#endif // __idp_resz_prz_mt6276_h__
