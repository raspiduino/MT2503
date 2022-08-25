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
 *    idp_sw_yuv_2_rgb_dithering.h
 *
 * Project:
 * --------
 *	  MAUI
 *
 * Description:
 * ------------
 *    This file is the I/F definition of idp_sw_yuv_2_rgb_dithering module.
 *    This module currently only supports the dithering of 4x4 block-based YUV420 planar to RGB565 
 *    frame buffer.
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
 * 06 03 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__IDP_SW_YUV_2_RGB_DITHERING__)
#define __IDP_SW_YUV_2_RGB_DITHERING__

/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "drv_features_mdp.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"          /* Task message communiction */

#include "drv_comm.h"
/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef void (*idp_sw_yuv_2_rgb_dithering_cbfxn_t)(void);

typedef struct
{
    kal_uint32                      src_width;
    kal_uint32                      src_height;
    kal_uint32                      src_y_addr;
    kal_uint32                      src_u_addr;
    kal_uint32                      src_v_addr;
    kal_uint32                      tar_rgb_addr;

    idp_sw_yuv_2_rgb_dithering_cbfxn_t  cbfxn_dithering_done;
    void                        *cbparam_dithering_done;
} _idp_sw_yuv_2_rgb_dithering_cmd_t;

/****************************************************************************
 * external symbol prototypes and declarations
 ****************************************************************************/
extern kal_bool
idp_sw_yuv_2_rgb_dithering_start_hisr(
    kal_uint32 src_w,
    kal_uint32 src_h,
    kal_uint32 src_y_addr, 
    kal_uint32 src_u_addr, 
    kal_uint32 src_v_addr, 
    kal_uint32 tar_rgb_addr,
    idp_sw_yuv_2_rgb_dithering_cbfxn_t cbfxn_dithering_done, 
    void *cbparam_dithering_done);

extern kal_bool
idp_sw_yuv_2_rgb_dithering_close(void);

#endif // #if !defined(__IDP_SW_YUV_2_RGB_DITHERING__)


