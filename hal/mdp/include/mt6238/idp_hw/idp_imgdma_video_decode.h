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

#ifndef __idp_imgdma_video_decode_mt6238_h__
#define __idp_imgdma_video_decode_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "reg_base.h"
#include "kal_public_api.h"
#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"

/* ===================================================
 *                   Video decode DMA
 * =================================================== */

/** \defgroup imgdma_video_decode Video decode DMA
 * @{
 */
#define IMGDMA_VIDEO_DECODE_START_REG        (IMGDMA_base + 0x0280)
#define IMGDMA_VIDEO_DECODE_CTRL_REG         (IMGDMA_base + 0x0284)
#define IMGDMA_VIDEO_DECODE_Y_BASE_ADDR_REG  (IMGDMA_base + 0x0290)
#define IMGDMA_VIDEO_DECODE_U_BASE_ADDR_REG  (IMGDMA_base + 0x0294)
#define IMGDMA_VIDEO_DECODE_V_BASE_ADDR_REG  (IMGDMA_base + 0x0298)
#define IMGDMA_VIDEO_DECODE_WIDTH_REG        (IMGDMA_base + 0x02B0)
#define IMGDMA_VIDEO_DECODE_HEIGHT_REG       (IMGDMA_base + 0x02B4)
#define IMGDMA_VIDEO_DECODE_PXLNUM_REG       (IMGDMA_base + 0x02B8)
#define IMGDMA_VIDEO_DECODE_Y_HCNT_REG       (IMGDMA_base + 0x02BC)
#define IMGDMA_VIDEO_DECODE_Y_VCNT_REG       (IMGDMA_base + 0x02C0)
#define IMGDMA_VIDEO_DECODE_V_HCNT_REG       (IMGDMA_base + 0x02C4)
#define IMGDMA_VIDEO_DECODE_V_VCNT_REG       (IMGDMA_base + 0x02C8)

#define REG_IMGDMA_VIDEO_DECODE_START        *((volatile unsigned int *)(IMGDMA_base + 0x0280))
#define REG_IMGDMA_VIDEO_DECODE_CTRL         *((volatile unsigned int *)(IMGDMA_base + 0x0284))
#define REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR  *((volatile unsigned int *)(IMGDMA_base + 0x0290))
#define REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR  *((volatile unsigned int *)(IMGDMA_base + 0x0294))
#define REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR  *((volatile unsigned int *)(IMGDMA_base + 0x0298))
#define REG_IMGDMA_VIDEO_DECODE_WIDTH        *((volatile unsigned int *)(IMGDMA_base + 0x02B0))
#define REG_IMGDMA_VIDEO_DECODE_HEIGHT       *((volatile unsigned int *)(IMGDMA_base + 0x02B4))
#define REG_IMGDMA_VIDEO_DECODE_PXLNUM       *((volatile unsigned int *)(IMGDMA_base + 0x02B8))
#define REG_IMGDMA_VIDEO_DECODE_Y_HCNT       *((volatile unsigned int *)(IMGDMA_base + 0x02BC))
#define REG_IMGDMA_VIDEO_DECODE_Y_VCNT       *((volatile unsigned int *)(IMGDMA_base + 0x02C0))
#define REG_IMGDMA_VIDEO_DECODE_V_HCNT       *((volatile unsigned int *)(IMGDMA_base + 0x02C4))
#define REG_IMGDMA_VIDEO_DECODE_V_VCNT       *((volatile unsigned int *)(IMGDMA_base + 0x02C8))

/* bit mapping of video decode image dma control register */
#define IMGDMA_VIDEO_DECODE_INT_BIT      0x00000001
#define IMGDMA_VIDEO_DECODE_H264_BIT     0x00000008
#define IMGDMA_VIDEO_DECODE_ROTATE_MASK  0x00000030
#define IMGDMA_VIDEO_DECODE_FLIP_BIT     0x00000040

/* DRV_IDP_6238_SERIES_E1 */
#define IMGDMA_VIDEO_DECODE_BYPASS_BIT   0x00000080
/* */

/* macros of Video decode image DMA start register */
#define START_IMGDMA_VIDEO_DECODE() do { REG_IMGDMA_VIDEO_DECODE_START = 1; } while(0)
#define STOP_IMGDMA_VIDEO_DECODE()  do { REG_IMGDMA_VIDEO_DECODE_START = 0; } while(0)

/**
 * \brief Check if video decode DMA is started or not.
 */
#define IS_IMGDMA_VIDEO_DECODE_START()                      \
  ((0x1 == (REG_IMGDMA_VIDEO_DECODE_START & 0x1))           \
   ? KAL_TRUE                                               \
   : KAL_FALSE)

/* macros of video decode image dma control register */
#define ENABLE_VIDEO_DECODE_INT()                                 \
  do {                                                            \
    REG_IMGDMA_VIDEO_DECODE_CTRL |= IMGDMA_VIDEO_DECODE_INT_BIT;  \
  } while(0)

#define DISABLE_VIDEO_DECODE_INT()                                \
  do {                                                            \
    REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_INT_BIT; \
  } while(0)

#define SET_VIDEO_DECODE_H264_BUF()                               \
  do {                                                            \
    REG_IMGDMA_VIDEO_DECODE_CTRL |= IMGDMA_VIDEO_DECODE_H264_BIT; \
  } while(0)

#define SET_VIDEO_DECODE_MPEG4_BUF()                                \
  do {                                                              \
    REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_H264_BIT;  \
  } while(0)

#define SET_VIDEO_DECODE_ROTATE(rot)                                  \
  do {                                                                \
    REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_ROTATE_MASK; \
    REG_IMGDMA_VIDEO_DECODE_CTRL |= (rot)<<4;                         \
  } while(0)

#define ENABLE_VIDEO_DECODE_FLIP()                                \
  do {                                                            \
    REG_IMGDMA_VIDEO_DECODE_CTRL |= IMGDMA_VIDEO_DECODE_FLIP_BIT; \
  } while(0)

#define DISABLE_VIDEO_DECODE_FLIP()                                 \
  do {                                                              \
    REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_FLIP_BIT;  \
  } while(0)

/* DRV_IDP_6238_SERIES_E1 */
#define BYPASS_VIDEO_DECODE_TO_IRT0()                               \
  do {                                                              \
    REG_IMGDMA_VIDEO_DECODE_CTRL |= IMGDMA_VIDEO_DECODE_BYPASS_BIT; \
  } while(0)

#define NOTBYPASS_VIDEO_DECODE_TO_IRT0()                              \
  do {                                                                \
    REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_BYPASS_BIT;  \
  } while(0)
/* */

#define SET_IMGDMA_VIDEO_DEC_PIXNUM(num)        \
  do {                                          \
    ASSERT(num <= ((1 << 20) - 1));             \
    REG_IMGDMA_VIDEO_DECODE_PXLNUM = num;       \
  } while(0)

enum idp_imgdma_video_decode_error_code_t
{
  IDP_IMGDMA_VIDEO_DECODE_NO_ERROR,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_IMGDMA_VIDEO_DECODE_ERROR_CODE_HW_LIMITATION
};
typedef enum idp_imgdma_video_decode_error_code_t idp_imgdma_video_decode_error_code_t;

enum
{
  IDP_IMGDMA_VIDEO_DECODE_QUERY_ERROR_CODE = 1
};

typedef struct {
  kal_bool                  intr_en;
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_uint32                y_base_addr; /* Base addr Y */
  kal_uint32                u_base_addr; /* Base addr U */
  kal_uint32                v_base_addr; /* Base addr V */
  kal_uint16                width; /* decode width */
  kal_uint16                height; /* decode height */
  kal_bool                  buf_h264; /* h.264 or mp4 buffer */
  kal_bool                  flip; /* flip */

  /* DRV_IDP_6238_SERIES_E1 */
  kal_bool                  bypass_irt0; /* bypass irt0 */
  /* */
  
  img_rot_angle_enum_t      rot_angle;
} idp_imgdma_video_decode_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_video_decode)

extern void *idp_imgdma_video_decode_intr_cb_param;
extern void (*idp_imgdma_video_decode_intr_cb)(void *);

extern kal_bool idp_imgdma_video_decode_config_real(
    idp_imgdma_video_decode_struct * const video_decode_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_video_decode_stop_real(
  idp_imgdma_video_decode_struct const * const video_decode_struct);

extern kal_bool idp_imgdma_video_decode_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_video_decode_struct * const video_decode_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_video_decode_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_video_decode_mt6238_h__

