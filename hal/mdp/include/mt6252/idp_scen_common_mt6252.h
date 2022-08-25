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
 *    idp_scen_common_mt6252.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Only for MT6252 MDP driver...
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
 * 03 25 2013 chrono.wu
 * removed!
 * MT6260 WVGA Camera features support full screen.
 *
 * 02 20 2013 peter.wang
 * removed!
 * .
 *
 * 12 13 2012 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 *
 * 06 12 2012 peter.wang
 * removed!
 * .
 *
 * 04 18 2012 peter.wang
 * removed!
 * .
 *
 * 02 19 2012 peter.wang
 * removed!
 * .
 *
 * 02 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 16 2011 peter.wang
 * removed!
 * .
 *
 * 09 15 2011 peter.wang
 * removed!
 * .
 *
 * 05 17 2011 peter.wang
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(IDP_MM_COLOR_SUPPORT)
#include <color_api.h>
#include <color_enum.h>
#include <color_structure.h>
#endif
#include "drv_features.h"

#if defined(IDP_TILE_MODE_SUPPORT)
typedef struct tile_calc_para
{
    /* Tile parameters */
    kal_uint32  tile_bi_sa_src_start_pos[2];  // Input tile start position of bilinear interpolation/source accumulation
    kal_uint32  tile_bi_sa_src_end_pos[2];    // Input tile end position of bilinear interpolation/source accumulation

    kal_uint32  tile_adj_src_start_pos[2];    // Adjust tile_bi_sa_src_start_pos for alignment
    kal_uint32  tile_adj_src_end_pos[2];      // Adjust tile_bi_sa_src_end_pos for alignment
    kal_uint32  tile_src_size_x[2];           // Tile Org width

    kal_uint32  tile_sa_init_weight[2];       // Initial weight of source accumulation
    kal_uint32  tile_start_pos_x[2];          // Input tile start position
    kal_uint32  tile_start_pos_y[2];          // Input tile start position
    kal_uint16  tile_trunc_err_comp_x[2];
    kal_uint16  tile_trunc_err_comp_y[2];
    kal_uint16  tile_init_resid_x[2];         // Initial accumulated residual for truncation error compensation
    kal_uint16  tile_init_resid_y[2];
} tile_calc_para;
#endif

extern kal_bool
idp_common_open_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_stop_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_start_input_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_start_output_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_is_busy_hook(
    idp_owner_t const * const owner,
    kal_bool * const busy);

extern kal_bool
idp_common_is_in_use_hook(void);

extern kal_bool
idp_common_query_hook(
    idp_owner_t * const owner,
    va_list ap);

extern kal_bool
idp_dummy_hook(
    idp_owner_t * const owner);

extern void
idp_dummy_hook2(
    idp_owner_t * const owner);

extern kal_bool
idp_dummy_hook3(void);

extern void idp_config_crz_crop(
    kal_uint16 image_src_width,
    kal_uint16 image_src_height,
    kal_uint16 crop_width,
    kal_uint16 crop_height);

#if defined(IDP_TILE_MODE_SUPPORT)
void
idp_bi_tile_calc(
    kal_uint32 src_w, kal_uint32 src_h,
    kal_uint32 tar_w, kal_uint32 tar_h,
    tile_calc_para *tile_result);

void
idp_sa_tile_calc(
    kal_uint32 src_w, kal_uint32 src_h,
    kal_uint32 tar_w, kal_uint32 tar_h,
    tile_calc_para *tile_result);
#endif

// this flag is used to indicate whether MDP triple display buffer is enabled or not
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
extern kal_bool _idp_scen_triple_display_buffer_enable;
extern kal_uint32 _idp_scen_display_buffer_addr[3];
extern kal_uint32 _idp_scen_display_buffer_cnt;
#endif

// this buffer used for delay one frame trigger LCD display
#if defined(__ATV_SUPPORT__)
extern kal_uint32 completed_display_buffer_count;
#endif

// this handle is used for mm color control
#if defined(IDP_MM_COLOR_SUPPORT)
extern COLOR_HANDLE mm_color_handle;
#endif

#if defined(__MTK_TARGET__)
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
extern volatile kal_bool resz_esd_check_flag;
#endif
#endif

