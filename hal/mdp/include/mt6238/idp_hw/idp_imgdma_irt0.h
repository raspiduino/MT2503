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

#ifndef __idp_imgdma_irt0_mt6238_h__
#define __idp_imgdma_irt0_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "reg_base.h"
#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "idp_hw_common.h"
#include <mt6238/idp_mem.h>

/* ===================================================
 *                        IRT0
 * =================================================== */

/** \defgroup imgdma_irt0 IRT0
 * @{
 */
#define IMGDMA_IRT0_START_REG      (IMGDMA_base + 0x0C00)
#define IMGDMA_IRT0_CTRL_REG       (IMGDMA_base + 0x0C04)
#define IMGDMA_IRT0_BASE_ADDR_REG  (IMGDMA_base + 0x0C08)
#define IMGDMA_IRT0_WIDTH_REG      (IMGDMA_base + 0x0C0C)
#define IMGDMA_IRT0_HEIGHT_REG     (IMGDMA_base + 0x0C10)
#define IMGDMA_IRT0_PXL_NUM_REG    (IMGDMA_base + 0x0C14)
#define IMGDMA_IRT0_FIFOLEN_REG    (IMGDMA_base + 0x0C18)
#define IMGDMA_IRT0_WADDR_REG      (IMGDMA_base + 0x0C1C)
#define IMGDMA_IRT0_RADDR_REG      (IMGDMA_base + 0x0C20)
#define IMGDMA_IRT0_RDHCNT_REG     (IMGDMA_base + 0x0C24)
#define IMGDMA_IRT0_RDVCNT_REG     (IMGDMA_base + 0x0C28)
#define IMGDMA_IRT0_FIFOCNT_REG    (IMGDMA_base + 0x0C2C)
#define IMGDMA_IRT0_WDYIDX_REG     (IMGDMA_base + 0x0C30)
#define IMGDMA_IRT0_RDYIDX_REG     (IMGDMA_base + 0x0C34)

#define REG_IMGDMA_IRT0_START     *((volatile unsigned int *)(IMGDMA_base + 0x0C00))
#define REG_IMGDMA_IRT0_CTRL      *((volatile unsigned int *)(IMGDMA_base + 0x0C04))
#define REG_IMGDMA_IRT0_BASE_ADDR *((volatile unsigned int *)(IMGDMA_base + 0x0C08))
#define REG_IMGDMA_IRT0_WIDTH     *((volatile unsigned int *)(IMGDMA_base + 0x0C0C))
#define REG_IMGDMA_IRT0_HEIGHT    *((volatile unsigned int *)(IMGDMA_base + 0x0C10))
#define REG_IMGDMA_IRT0_PXL_NUM   *((volatile unsigned int *)(IMGDMA_base + 0x0C14))
#define REG_IMGDMA_IRT0_FIFOLEN   *((volatile unsigned int *)(IMGDMA_base + 0x0C18))
#define REG_IMGDMA_IRT0_WADDR     *((volatile unsigned int *)(IMGDMA_base + 0x0C1C))
#define REG_IMGDMA_IRT0_RADDR     *((volatile unsigned int *)(IMGDMA_base + 0x0C20))
#define REG_IMGDMA_IRT0_RDHCNT    *((volatile unsigned int *)(IMGDMA_base + 0x0C24))
#define REG_IMGDMA_IRT0_RDVCNT    *((volatile unsigned int *)(IMGDMA_base + 0x0C28))
#define REG_IMGDMA_IRT0_FIFOCNT   *((volatile unsigned int *)(IMGDMA_base + 0x0C2C))
#define REG_IMGDMA_IRT0_WDYIDX    *((volatile unsigned int *)(IMGDMA_base + 0x0C30))
#define REG_IMGDMA_IRT0_RDYIDX    *((volatile unsigned int *)(IMGDMA_base + 0x0C34))

#define IMGDMA_IRT0_CTRL_INT_BIT           0X00000001
#define IMGDMA_IRT0_CTRL_AUTOSTR_BIT       0X00000002
#define IMGDMA_IRT0_CTRL_PSEL_BIT          0X00000004
#define IMGDMA_IRT0_CTRL_H264_BIT          0X00000008
#define IMGDMA_IRT0_CTRL_ROT_MASK          0X00000030
#define IMGDMA_IRT0_CTRL_FLIP_BIT          0X00000040
#define IMGDMA_IRT0_CTRL_BYPS_BIT          0X00000080
#define IMGDMA_IRT0_CTRL_CRZ_BIT           0X00000100
#define IMGDMA_IRT0_CTRL_PRZ_BIT           0X00000200
#define IMGDMA_IRT0_CTRL_IPP1_BIT          0X00000400
#define IMGDMA_IRT0_CTRL_MP4_DEBLK_BIT     0X00000800
#define IMGDMA_IRT0_CTRL_OUTPUT_MOD_MASK   0X00000f00

/**
 * \brief Check if IRT0 is started or not.
 */
#define IS_IMGDMA_IRT0_START()                              \
  ((0x1 == (REG_IMGDMA_IRT0_START & 0x1))                   \
   ? KAL_TRUE                                               \
   : KAL_FALSE)

#define ENABLE_IRT0_INT()                             \
  do {                                                \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_INT_BIT; \
  } while(0)

#define DISABLE_IRT0_INT()                              \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_INT_BIT;  \
  } while(0)

#define ENABLE_IRT0_AUTOSTART()                           \
  do {                                                    \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_AUTOSTR_BIT; \
  } while(0)

#define DISABLE_IRT0_AUTOSTART()                            \
  do {                                                      \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_AUTOSTR_BIT;  \
  } while(0)

#define SET_IRT0_SRC_VIDEO_DEC_DMA()                    \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_PSEL_BIT;  \
  } while(0)

#define SET_IRT0_SRC_VIDEO_ENC_DMA()                    \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_PSEL_BIT; \
  } while(0)

#define SET_IRT0_SRC_H264_BUFFER()                      \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_H264_BIT;  \
  } while(0)

#define SET_IRT0_SRC_MPEG4_BUFFER()                     \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_H264_BIT; \
  } while(0)

#define SET_IRT0_ROTATE_DIR(rot)                        \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_ROT_MASK; \
    REG_IMGDMA_IRT0_CTRL |= (rot << 4);                 \
  } while(0)

#define ENABLE_IRT0_FLIP()                              \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_FLIP_BIT;  \
  } while(0)

#define DISABLE_IRT0_FLIP()                             \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_FLIP_BIT; \
  } while(0)

/* DRV_IDP_6238_SERIES_E1 */
#define BYPASS_IRT0_ROTATE()                            \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL |= IMGDMA_IRT0_CTRL_BYPS_BIT;  \
  } while(0)

#define NOTBYPASS_IRT0_ROTATE()                         \
  do {                                                  \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_BYPS_BIT; \
  } while(0)
/* */

#define SET_IRT0_OUTPUT_MOD(module)                             \
  do {                                                          \
    REG_IMGDMA_IRT0_CTRL &= ~IMGDMA_IRT0_CTRL_OUTPUT_MOD_MASK;  \
    REG_IMGDMA_IRT0_CTRL |= (module << 8);                      \
  } while(0)

#define START_IRT0()                            \
  do {                                          \
    REG_IMGDMA_IRT0_START=1;                    \
  } while(0)

#define STOP_IRT0()                             \
  do {                                          \
    REG_IMGDMA_IRT0_START=0;                    \
  } while(0)

#define SET_IMGDMA_IRT0_LINE_BUFFER_ADDR(addr)  \
  do {                                          \
    REG_IMGDMA_IRT0_BASE_ADDR = addr;           \
  } while(0)

#define SET_IMGDMA_IRT0_WIDTH(width)            \
  do {                                          \
    REG_IMGDMA_IRT0_WIDTH = width;              \
  } while(0)

#define SET_IMGDMA_IRT0_HEIGHT(height)          \
  do {                                          \
    REG_IMGDMA_IRT0_HEIGHT = height;            \
  } while(0)

#define SET_IMGDMA_IRT0_PIXNUM(num)             \
  do {                                          \
    REG_IMGDMA_IRT0_PXL_NUM = num;              \
  } while(0)

#define SET_IMGDMA_IRT0_FIFOLEN(len)            \
  do {                                          \
    REG_IMGDMA_IRT0_FIFOLEN = len;              \
  } while(0)

/**
 * \brief IRT0 structure
 *
 * Programmers can use this structure to set up IRT0.
 */
typedef struct
{
  kal_bool                intr_en; /**< enable int or not */
  
  idp_lisr_intr_cb_t           intr_cb;
  idp_lisr_intr_cb_param_t     intr_cb_param;
  
  kal_bool                restart; /**< restart or not */
  kal_bool                src_video_dec; /**< video dec or video enc as source */
  kal_bool                buf_h264; /**< h.264 or mp4 buffer */
  img_rot_angle_enum_t    rot_angle; /**< rotate direction */
  kal_bool                flip; /**< flip or not */
  
  /* DRV_IDP_6238_SERIES_E1 */
  kal_bool                bypass; /**< bypass rotate or not */
  /* */
  
  idp_module_enum_t       output; /**< output module */
  
  kal_uint32              work_mem_line_count;
  kal_uint32              work_mem_addr;
  
  kal_uint16              width; /**< width */
  kal_uint16              height; /**< height */
} idp_imgdma_irt0_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_irt0)

extern void *idp_imgdma_irt0_intr_cb_param;
extern void (*idp_imgdma_irt0_intr_cb)(void *);

extern kal_bool idp_imgdma_irt0_config_real(
    idp_imgdma_irt0_struct * const irt0_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_irt0_stop_real(
  idp_imgdma_irt0_struct const * const irt0_struct);

extern kal_bool idp_imgdma_irt0_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_irt0_struct * const irt0_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_irt0_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_irt0_mt6238_h__
