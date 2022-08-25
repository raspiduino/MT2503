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
 * 11 26 2010 hung-wen.hsieh
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

#ifndef __idp_imgdma_video_encode_mt6238_h__
#define __idp_imgdma_video_encode_mt6238_h__

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
#include <mt6238/idp_mem.h>

/* ===================================================
 *                    Video encode
 * =================================================== */

/** \defgroup imgdma_video_encode Video encode DMA
 * @{
 */
#define IMGDMA_VIDEO_ENCODE_START_REG        (IMGDMA_base + 0x0200)
#define IMGDMA_VIDEO_ENCODE_CTRL_REG         (IMGDMA_base + 0x0204)
#define IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1_REG (IMGDMA_base + 0x0210)
#define IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1_REG (IMGDMA_base + 0x0214)
#define IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1_REG (IMGDMA_base + 0x0218)
#define IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2_REG (IMGDMA_base + 0x0220)
#define IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2_REG (IMGDMA_base + 0x0224)
#define IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2_REG (IMGDMA_base + 0x0228)
#define IMGDMA_VIDEO_ENCODE_WIDTH_REG        (IMGDMA_base + 0x0230)
#define IMGDMA_VIDEO_ENCODE_HEIGHT_REG       (IMGDMA_base + 0x0234)
#define IMGDMA_VIDEO_ENCODE_PXLNUM_REG       (IMGDMA_base + 0x0238)

/* DRV_IDP_6238_SERIES_E2 */
#define IMGDMA_VIDEO_ENCODE_LB_ADDR_REG      (IMGDMA_base + 0x0260)
#define IMGDMA_VIDEO_ENCODE_LB_LEN_REG       (IMGDMA_base + 0x0264)

#define IMGDMA_VIDEO_ENCODE_LB_H_COUNT_REG   (IMGDMA_base + 0x0268)
#define IMGDMA_VIDEO_ENCODE_LB_V_COUNT_REG   (IMGDMA_base + 0x026C)

/* MT6268B */
#if defined (MT6268)
#define IMGDMA_VIDEO_ENCODE_DROP_FCNT_REG    (IMGDMA_base + 0x0270)
#define IMGDMA_VIDEO_ENCODE_HIGHP_THRESH_REG (IMGDMA_base + 0x027c)
#endif // chip option

#define REG_IMGDMA_VIDEO_ENCODE_START        *((volatile unsigned int *)(IMGDMA_base + 0x0200))
#define REG_IMGDMA_VIDEO_ENCODE_CTRL         *((volatile unsigned int *)(IMGDMA_base + 0x0204))
#define REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1 *((volatile unsigned int *)(IMGDMA_base + 0x0210))
#define REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1 *((volatile unsigned int *)(IMGDMA_base + 0x0214))
#define REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1 *((volatile unsigned int *)(IMGDMA_base + 0x0218))
#define REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2 *((volatile unsigned int *)(IMGDMA_base + 0x0220))
#define REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2 *((volatile unsigned int *)(IMGDMA_base + 0x0224))
#define REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2 *((volatile unsigned int *)(IMGDMA_base + 0x0228))
#define REG_IMGDMA_VIDEO_ENCODE_WIDTH        *((volatile unsigned int *)(IMGDMA_base + 0x0230))
#define REG_IMGDMA_VIDEO_ENCODE_HEIGHT       *((volatile unsigned int *)(IMGDMA_base + 0x0234))
#define REG_IMGDMA_VIDEO_ENCODE_PXLNUM       *((volatile unsigned int *)(IMGDMA_base + 0x0238))

/* DRV_IDP_6238_SERIES_E2 */
#define REG_IMGDMA_VIDEO_ENCODE_LB_ADDR      *((volatile unsigned int *)(IMGDMA_base + 0x0260))
#define REG_IMGDMA_VIDEO_ENCODE_LB_LEN       *((volatile unsigned int *)(IMGDMA_base + 0x0264))

#define REG_IMGDMA_VIDEO_ENCODE_LB_H_COUNT   *((volatile unsigned int *)(IMGDMA_base + 0x0268))
#define REG_IMGDMA_VIDEO_ENCODE_LB_V_COUNT   *((volatile unsigned int *)(IMGDMA_base + 0x026C))
/* */

/* MT6268B */
#if defined (MT6268)
#define REG_IMGDMA_VIDEO_ENCODE_DROP_FCNT    *((volatile unsigned int *) IMGDMA_VIDEO_ENCODE_DROP_FCNT_REG)
#define REG_IMGDMA_VIDEO_ENCODE_HIGHP_THRESH *((volatile unsigned int *) IMGDMA_VIDEO_ENCODE_HIGHP_THRESH_REG)
#endif // chip option

/* bit mapping of video encode image dma control register */
/* DRV_IDP_6238_SERIES_E1 */
#define IMGDMA_VIDEO_ENCODE_BYPASS_BIT       0x00000080
/* */

#define IMGDMA_VIDEO_ENCODE_FLIP_BIT         0x00000040
#define IMGDMA_VIDEO_ENCODE_ROT_MASK         0x00000030

#define IMGDMA_VIDEO_ENCODE_R_INT_BIT        0x00000008
#define IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT 0x00000004
#define IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT  0x00000002
#define IMGDMA_VIDEO_ENCODE_W_INT_BIT        0x00000001

/* macros of Video encode image DMA start register */
#define START_IMGDMA_VIDEO_ENCODE()    REG_IMGDMA_VIDEO_ENCODE_START=1;
#define STOP_IMGDMA_VIDEO_ENCODE()     REG_IMGDMA_VIDEO_ENCODE_START=0;

/**
 * \brief Check if video encode DMA is started or not.
 */
#define IS_IMGDMA_VIDEO_ENCODE_START()                      \
  ((0x1 == (REG_IMGDMA_VIDEO_ENCODE_START & 0x1))           \
   ? KAL_TRUE                                               \
   : KAL_FALSE)

/* macros of video encode image dma control register */
#define ENABLE_VIDEO_ENCODE_W_INT()         REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_W_INT_BIT;
#define DISABLE_VIDEO_ENCODE_W_INT()        REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_W_INT_BIT;
#define ENABLE_VIDEO_ENCODE_W_TRIGGER_R()   REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT;
#define DISABLE_VIDEO_ENCODE_W_TRIGGER_R()  REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT;
#define ENABLE_VIDEO_ENCODE_AUTO_RESTART()  REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT;
#define DISABLE_VIDEO_ENCODE_AUTO_RESTART() REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT;
#define ENABLE_VIDEO_ENCODE_R_INT()         REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_R_INT_BIT;
#define DISABLE_VIDEO_ENCODE_R_INT()        REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_R_INT_BIT;

#define SET_VIDEO_ENCODE_ROTATE(rot)        REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_ROT_MASK; \
  REG_IMGDMA_VIDEO_ENCODE_CTRL |= (rot<<4);

#define ENABLE_VIDEO_ENCODE_FLIP()          REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_FLIP_BIT;
#define DISABLE_VIDEO_ENCODE_FLIP()         REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_FLIP_BIT;

/* DRV_IDP_6238_SERIES_E1 */
#define ENABLE_VIDEO_ENCODE_BYPASS()        REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_BYPASS_BIT;
#define DISABLE_VIDEO_ENCODE_BYPASS()       REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_BYPASS_BIT;
/* */

/* DRV_IDP_6238_SERIES_E2 */
#define SET_VIDEO_ENCODE_LB_ADDR(addr)      REG_IMGDMA_VIDEO_ENCODE_LB_ADDR = addr;
#define SET_VIDEO_ENCODE_LB_LEN(len)        REG_IMGDMA_VIDEO_ENCODE_LB_LEN = len;
/* */

enum
{
  IDP_IMGDMA_VIDEO_ENCODE_MASK_WRITE_DONE_INT,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_W_INTR_CB,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_W_INTR_CB_PARAM,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_READ_DONE_INT,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_R_INTR_CB,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_R_INTR_CB_PARAM,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_W_TRIGGER_R,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_RESTART,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_ROT_ANGLE,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_FLIP,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_BYPASS,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_LINE_BUF_ADDR,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_LINE_BUF_SIZE,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_Y_BASE_ADDR1,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_Y_BASE_ADDR2,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_U_BASE_ADDR1,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_U_BASE_ADDR2,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_V_BASE_ADDR1,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_V_BASE_ADDR2,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_ENCODE_WIDTH,
  IDP_IMGDMA_VIDEO_ENCODE_MASK_ENCODE_HEIGHT,
#if defined(MT6268)
  IDP_IMGDMA_VIDEO_ENCODE_MASK_HW_FRAME_SYNC,
#endif // chip option
  
  IDP_IMGDMA_VIDEO_ENCODE_MASK_LAST
};

/**
 * \brief video encode DMA structure
 *
 * Programmers can use this structure to set up video encode
 * DMA.
 */
typedef struct
{
  kal_uint32                    mask[(IDP_IMGDMA_VIDEO_ENCODE_MASK_LAST / 32) + 1];
  
  kal_bool                      wrtie_done_int;
  idp_lisr_intr_cb_t            w_intr_cb;
  idp_lisr_intr_cb_param_t      w_intr_cb_param;

  kal_bool                      read_done_int; /**< read done interrupt */
  idp_lisr_intr_cb_t            r_intr_cb;
  idp_lisr_intr_cb_param_t      r_intr_cb_param;

  kal_bool                      w_trigger_r; /**< w trigger r */
  kal_bool                      restart;
  
  img_rot_angle_enum_t          rot_angle; /**< rotate value */
  kal_bool                      flip; /**< flip or not */
  
  /* DRV_IDP_6238_SERIES_E1 */
  kal_bool                      bypass; /**< bypass IRT0 line buffer or not */
  /* */
  
  /* DRV_IDP_6238_SERIES_E2 */
  kal_uint8                     *line_buf_addr;
  kal_uint32                    line_buf_size;
  /* */
  
  kal_uint32                     dest_base_address_0_y; /**< Base addr1 Y */
  kal_uint32                     dest_base_address_0_u; /**< Base addr2 Y */
  kal_uint32                     dest_base_address_0_v; /**< Base addr1 U */
  kal_uint32                     dest_base_address_1_y; /**< Base addr2 U */
  kal_uint32                     dest_base_address_1_u; /**< Base addr1 V */
  kal_uint32                     dest_base_address_1_v; /**< Base addr2 V */

  kal_uint8                     *y_base_addr1; /**< Base addr1 Y */
  kal_uint8                     *y_base_addr2; /**< Base addr2 Y */
  kal_uint8                     *u_base_addr1; /**< Base addr1 U */
  kal_uint8                     *u_base_addr2; /**< Base addr2 U */
  kal_uint8                     *v_base_addr1; /**< Base addr1 V */
  kal_uint8                     *v_base_addr2; /**< Base addr2 V */
  
  kal_uint16                    encode_width; /**< encode width */
  kal_uint16                    encode_height; /**< encode height */
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                      hw_frame_sync; /**< KAL_TRUE: enable HW frame sync; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_video_encode_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_video_encode)

extern void *idp_imgdma_video_encode_write_intr_cb_param;
extern void (*idp_imgdma_video_encode_write_intr_cb)(void *);

extern void *idp_imgdma_video_encode_read_intr_cb_param;
extern void (*idp_imgdma_video_encode_read_intr_cb)(void *);

extern kal_bool idp_imgdma_video_encode_config_real(
    idp_imgdma_video_encode_struct * const video_encode_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_video_encode_stop_real(
  idp_imgdma_video_encode_struct const * const video_encode_struct);

extern kal_bool idp_imgdma_video_encode_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_video_encode_struct * const video_encode_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_video_encode_close_real(void);


/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_video_encode_mt6238_h__
