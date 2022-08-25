/****************************************************************************
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
 *    idp_sw_yuv420_2_uyvy422_resizer.h
 *
 * Project:
 * --------
 *	  MAUI
 *
 * Description:
 * ------------
 *    This file is the I/F definition of idp_sw_yuv420_2_uyvy422_resizer module.
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
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 13 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 06 23 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 06 22 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 20 2010 cm.huang
 * removed!
 * .
 *
 * 12 02 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__IDP_SW_YUV420_2_UYVY422_RESIZER__)
#define __IDP_SW_YUV420_2_UYVY422_RESIZER__

/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "drv_features_mdp.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"          /* Task message communiction */

#if defined(MT6235) || defined(MT6235B)
#include "drv_comm.h"

/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef void (*idp_sw_resizer_cbfxn_t)(void*);

typedef enum
{
  IDP_REQUIRE_TASK_DO_NONE = 0,
  IDP_REQUIRE_TASK_DO_SW_RESIZER,
  IDP_REQUIRE_TASK_DO_COLOR_FORMAT_TRANSMFOM,
  IDP_REQUIRE_TASK_DO_TOUCH_FROM_INSIDE_PITCH
} idp_require_task_do_enum_t;


typedef struct
{
    kal_uint32                      src_width;
    kal_uint32                      src_height;
    kal_uint32                      clip_offset_x1;
    kal_uint32                      clip_offset_y1;
    kal_uint32                      clip_offset_x2;
    kal_uint32                      clip_offset_y2;
    kal_uint32                      tar_width;
    kal_uint32                      tar_height;    
    kal_uint32                      src_y_addr;
    kal_uint32                      src_u_addr;
    kal_uint32                      src_v_addr;
    kal_uint32                      tar_rgb_addr;
    kal_uint32                      sw_resizer_workingbuf_addr;
    kal_uint32                      sw_resizer_workingbuf_size;
    kal_uint32                      tar_offset;
    idp_require_task_do_enum_t      nCmd;   //nCmd = 1 do sw resizer, nCmd = 2 do color format transform.
    kal_bool                        bClip;
    idp_sw_resizer_cbfxn_t          cbfxn_sw_resizer_done;
    void                            *cbparam_sw_resizer_done;
} _idp_sw_resizer_cmd_t;

/****************************************************************************
 * external symbol prototypes and declarations
 ****************************************************************************/
extern kal_bool
idp_sw_resizer_start_hisr(
    idp_require_task_do_enum_t nCmd,
    kal_uint32 src_w,
    kal_uint32 src_h,
    kal_bool bClip,
    kal_uint32 clip_offset_x1,
    kal_uint32 clip_offset_y1,
    kal_uint32 clip_offset_x2,
    kal_uint32 clip_offset_y2,
    kal_uint32 tar_w,
    kal_uint32 tar_h,    
    kal_uint32 src_y_addr, 
    kal_uint32 src_u_addr, 
    kal_uint32 src_v_addr, 
    kal_uint32 tar_rgb_addr,
    kal_uint32 sw_resizer_workingbuf_addr,
    kal_uint32 sw_resizer_workingbuf_size,    
    kal_uint32 tar_offset,
    idp_sw_resizer_cbfxn_t cbfxn_sw_resizer_done, 
    void *cbparam_sw_resizer_done);

extern void
idp_sw_resizer_start_req_hdlr(ilm_struct *ilm_msg);

#endif //defined(MT6235) || defined(MT6235B)
#endif // #if !defined(__IDP_SW_YUV420_2_UYVY422_RESIZER__)


