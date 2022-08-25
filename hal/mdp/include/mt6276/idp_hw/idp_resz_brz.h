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
 * 10 14 2010 holmes.chiou
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

#ifndef __idp_resz_brz_mt6276_h__
#define __idp_resz_brz_mt6276_h__

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
 *                       BRZ definition
 * =============================================================== */
/** \defgroup brz jpeg resizer
 * \ingroup resizer
 * @{
 */

#define IDP_RESZ_BRZ_FINE_RESZ_MAX_INPUT_WIDTH  (8191)
#define IDP_RESZ_BRZ_FINE_RESZ_MAX_INPUT_HEIGHT (8191)

#define IDP_RESZ_BRZ_FINE_RESZ_MAX_OUTPUT_WIDTH  (8191)
#define IDP_RESZ_BRZ_FINE_RESZ_MAX_OUTPUT_HEIGHT (8191)
 
// register addresses
#ifndef MDP_C_MODEL
#define BRZ_BASE BRZ_base
#define BRZ_CON_REG         (BRZ_BASE+0x0000)
#define BRZ_STA_REG         (BRZ_BASE+0x0004)
#define BRZ_INT_REG         (BRZ_BASE+0x0008)
#define BRZ_SRCSZ_REG       (BRZ_BASE+0x000C)
#define BRZ_BLKCSCFG_REG    (BRZ_BASE+0x0010)
#define BRZ_YLMBASE_REG     (BRZ_BASE+0x0014)
#define BRZ_ULMBASE_REG     (BRZ_BASE+0x0018)
#define BRZ_VLMBASE_REG     (BRZ_BASE+0x001C)
#define BRZ_YLBSIZE_REG     (BRZ_BASE+0x0020)
#define BRZ_INFO0_REG       (BRZ_BASE+0x002C)
#define BRZ_INFO1_REG       (BRZ_BASE+0x0030)


// register accesses
#define REG_BRZ_CON         *((volatile unsigned int*)BRZ_CON_REG)     
#define REG_BRZ_STA         *((volatile unsigned int*)BRZ_STA_REG)     
#define REG_BRZ_INT         *((volatile unsigned int*)BRZ_INT_REG)     
#define REG_BRZ_SRCSZ       *((volatile unsigned int*)BRZ_SRCSZ_REG)   
#define REG_BRZ_BLKCSCFG    *((volatile unsigned int*)BRZ_BLKCSCFG_REG)
#define REG_BRZ_YLMBASE     *((volatile unsigned int*)BRZ_YLMBASE_REG) 
#define REG_BRZ_ULMBASE     *((volatile unsigned int*)BRZ_ULMBASE_REG) 
#define REG_BRZ_VLMBASE     *((volatile unsigned int*)BRZ_VLMBASE_REG) 
#define REG_BRZ_YLBSIZE     *((volatile unsigned int*)BRZ_YLBSIZE_REG) 
#define REG_BRZ_INFO0       *((volatile unsigned int*)BRZ_INFO0_REG)   
#define REG_BRZ_INFO1       *((volatile unsigned int*)BRZ_INFO1_REG)   
#else
#define REG_BRZ_CON         (BRZ_CON     )
#define REG_BRZ_STA         (BRZ_STA     )
#define REG_BRZ_INT         (BRZ_INT     )
#define REG_BRZ_SRCSZ       (BRZ_SRCSZ   )
#define REG_BRZ_BLKCSCFG    (BRZ_BLKCSCFG)
#define REG_BRZ_YLMBASE     (BRZ_YLMBASE )
#define REG_BRZ_ULMBASE     (BRZ_ULMBASE )
#define REG_BRZ_VLMBASE     (BRZ_VLMBASE )
#define REG_BRZ_YLBSIZE     (BRZ_YLBSIZE )
#define REG_BRZ_INFO0       (BRZ_INFO0   )
#define REG_BRZ_INFO1       (BRZ_INFO1   )

#endif // MDP_C_MODEL

/* BRZ control register */
#define BRZ_CON_BLKCSRST_BIT 0x00010000
#define BRZ_CON_BLKCSENA_BIT 0x00000001

#define IS_BRZ_START() \
    (((REG_BRZ_CON & BRZ_CON_BLKCSENA_BIT) == 0x1) ? KAL_TRUE : KAL_FALSE)

#define BRZ_RESET() \
    do { REG_BRZ_CON = BRZ_CON_BLKCSRST_BIT; \
         REG_BRZ_CON = 0; } while(0)

#define BRZ_START() \
    do { REG_BRZ_CON = BRZ_CON_BLKCSENA_BIT; } while(0)

/* BRZ status register */
/* Block-based Coarse Shrinking Busy */
#define BRZ_STA_BLKCSBUSY_BIT   0x0001
/* Block-based Coarse Shrinking Intra-Block Busy */
#define BRZ_STA_BLKINTRA_BUSY_BIT 0x0002
/* Block to Raster Scan Output Busy */
#define BRZ_STA_BLK2PEL_BUSY_BIT    0X0004

/* BRZ interrupt register */
#define BRZ_INT_BLKCS_INTEN     0x0001
#define BRZ_INT_BLK2PEL_INTEN     0x0002
#define BRZ_INT_BLKCS_INT     0x0004
#define BRZ_INT_BLK2PEL_INT     0x0008

/* BRZ block coarse shrinking configuration register */
/* set sampling factor */
#define BRZ_BLKCSCFG_COARSE_MASK 0x00000003
#define BRZ_BLKCSCFG_SAMPLING_FACTOR_MASK 0x0000fff0

#define BRZ_BLKCSCFG_COARSE(coarse_ratio) \
    do { REG_BRZ_BLKCSCFG &= ~BRZ_BLKCSCFG_COARSE_MASK; \
        REG_BRZ_BLKCSCFG = REG_BRZ_BLKCSCFG | (coarse_ratio); } while(0)
        
#define BRZ_BLKCSCFG_SAMPLING_FACTOR(Vv,Hv,Vu,Hu,Vy,Hy) \
    do { REG_BRZ_BLKCSCFG &= ~BRZ_BLKCSCFG_SAMPLING_FACTOR_MASK;  \
            REG_BRZ_BLKCSCFG = REG_BRZ_BLKCSCFG | \
            ((Vv)<<14)|((Hv)<<12)|((Vu)<<10)|((Hu)<<8)|((Vy)<<6)|((Hy)<<4); } while(0)

#define BRZ_IS_BUSY() \
    (((REG_BRZ_STA & 0x7) != 0x0) ? KAL_TRUE : KAL_FALSE)

#define BRZ_BLKCS_INTERRUPT_ENABLE() \
    do { REG_BRZ_INT |= 0x01; } while(0)

#define BRZ_BLKCS_INTERRUPT_DISABLE() \
    do { REG_BRZ_INT &= ~0x01; } while(0)

#define BRZ_BLK2PEL_INTERRUPT_ENABLE() \
    do { REG_BRZ_INT |= 0x02; } while(0)

#define BRZ_BLK2PEL_INTERRUPT_DISABLE() \
    do { REG_BRZ_INT &= ~0x02; } while(0)

#define IDP_RESZ_BRZ_RESZ_MAX_INPUT_WIDTH 8191
#define IDP_RESZ_BRZ_RESZ_MAX_INPUT_HEIGHT 8191


typedef struct
{    
    kal_bool                  blkcs_intr_en; 
    idp_lisr_intr_cb_t        blkcs_intr_cb;
    idp_lisr_intr_cb_param_t  blkcs_intr_cb_param;
    
    kal_bool                  blk2pel_intr_en; 
    idp_lisr_intr_cb_t        blk2pel_intr_cb;
    idp_lisr_intr_cb_param_t  blk2pel_intr_cb_param;
    
    kal_uint16                src_height; /**< [1, 8191] */
    kal_uint16                src_width; /**< [1, 8191] */
    kal_uint16                tar_height; /**< [1, 8191] */
    kal_uint16                tar_width; /**< [1, 8191] */
    kal_uint8                   coarse_ratio; /* [0,3] 
                                                                0->no change, 
                                                                1->1/4 original size,
                                                                2->1/16 original size,
                                                                3->1/64 original size*/
                                                                
    kal_uint8                 y_h_factor; /* [0,1,2,4] 
                                                                0->no sampling
                                                                1->samping factor is 1
                                                                2->sampling factor is 2
                                                                4->sampling factor is 4*/
    kal_uint8                 y_v_factor; /* [0,1,2,4] */
    kal_uint8                 u_h_factor; /* [0,1,2,4]  */
    kal_uint8                 u_v_factor; /* [0,1,2,4]  */
    kal_uint8                 v_h_factor; /* [0,1,2,4]  */
    kal_uint8                 v_v_factor; /* [0,1,2,4]  */
    
    /** private member section */
    kal_uint16              y_line_buf_size;
    kal_uint32              y_line_buff_addr;
    kal_uint32              y_line_buff_size;
    kal_uint32              u_line_buff_addr;
    kal_uint32              u_line_buff_size;
    kal_uint32              v_line_buff_addr;
    kal_uint32              v_line_buff_size;
} idp_resz_brz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_brz)

extern void *idp_resz_brz_blkcs_intr_cb_param;
extern void (*idp_resz_brz_blkcs_intr_cb)(void *);

extern void *idp_resz_brz_blk2pel_intr_cb_param;
extern void (*idp_resz_brz_blk2pel_intr_cb)(void *);

extern kal_bool 
idp_resz_brz_config_real(
    idp_resz_brz_struct * const p_brz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_brz_get_working_mem_real(
    kal_bool use_internal_mem,
    idp_resz_brz_struct * const p_brz_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);
    
extern void
idp_resz_brz_open_real(void);

extern kal_bool
idp_resz_brz_start_real(
    idp_resz_brz_struct const * const p_brz_struct);

extern kal_bool
idp_resz_brz_stop_real(
    idp_resz_brz_struct const * const p_brz_struct);

/** @} */

#endif // defined(DRV_IDP_MT6276_SERIES)
#endif // __idp_resz_brz_mt6276_h__
