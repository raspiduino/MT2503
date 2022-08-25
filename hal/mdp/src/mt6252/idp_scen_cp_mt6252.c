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
 *    idp_scen_cp_mt6252.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    ISP -> CRZ -> ROTDMA -> MEM -> LCD
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
 * 11 14 2013 chrono.wu
 * removed!
 * .
 *
 * 07 18 2013 chrono.wu
 * removed!
 * fix change buffer condition for 1 pass preview case.
 *
 * 03 25 2013 chrono.wu
 * removed!
 * MT6260 WVGA Camera features support full screen.
 *
 * 02 20 2013 peter.wang
 * removed!
 * .
 *
 * 02 19 2013 peter.wang
 * removed!
 * .
 *
 * 02 07 2013 peter.wang
 * removed!
 * .
 *
 * 01 11 2013 peter.wang
 * removed!
 * .
 *
 * 12 13 2012 peter.wang
 * removed!
 * .
 *
 * 11 06 2012 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 * 
 * 07 20 2012 peter.wang
 * removed!
 * .
 *
 * 07 05 2012 peter.wang
 * removed!
 * .
 *
 * 07 03 2012 peter.wang
 * removed!
 * .
 *
 * 07 02 2012 peter.wang
 * removed!
 * .
 *
 * 06 19 2012 peter.wang
 * removed!
 * .
 *
 * 06 19 2012 peter.wang
 * removed!
 * .
 *
 * 06 13 2012 peter.wang
 * removed!
 * .
 *
 * 06 12 2012 peter.wang
 * removed!
 * .
 *
 * 05 31 2012 peter.wang
 * removed!
 * .
 *
 * 05 30 2012 peter.wang
 * removed!
 * .
 *
 * 05 25 2012 peter.wang
 * removed!
 * .
 *
 * 05 25 2012 peter.wang
 * removed!
 * .
 *
 * 05 16 2012 peter.wang
 * removed!
 * .
 *
 * 05 08 2012 peter.wang
 * removed!
 * .
 *
 * 05 02 2012 peter.wang
 * removed!
 * .
 *
 * 04 23 2012 peter.wang
 * removed!
 * .
 *
 * 04 18 2012 peter.wang
 * removed!
 * .
 *
 * 03 20 2012 peter.wang
 * removed!
 * .
 *
 * 03 16 2012 peter.wang
 * removed!
 * .
 *
 * 03 15 2012 peter.wang
 * removed!
 * .
 *
 * 03 12 2012 peter.wang
 * removed!
 * .
 *
 * 02 24 2012 peter.wang
 * removed!
 * .
 *
 * 02 23 2012 peter.wang
 * removed!
 * .
 *
 * 02 23 2012 peter.wang
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
 * 01 10 2012 peter.wang
 * removed!
 * .
 *
 * 12 28 2011 peter.wang
 * removed!
 * .
 *
 * 12 27 2011 peter.wang
 * removed!
 * .
 *
 * 12 16 2011 peter.wang
 * removed!
 * .
 *
 * 11 25 2011 peter.wang
 * removed!
 * .
 *
 * 11 17 2011 peter.wang
 * removed!
 * .
 *
 * 09 21 2011 peter.wang
 * removed!
 * .
 *
 * 09 15 2011 peter.wang
 * removed!
 * .
 *
 * 08 29 2011 peter.wang
 * removed!
 * .
 *
 * 08 19 2011 peter.wang
 * removed!
 * .
 *
 * 08 10 2011 peter.wang
 * removed!
 * .
 *
 * 07 14 2011 peter.wang
 * removed!
 * .
 *
 * 07 12 2011 peter.wang
 * removed!
 * .
 *
 * 06 29 2011 peter.wang
 * removed!
 * .
 *
 * 05 23 2011 peter.wang
 * removed!
 * .
 *
 * 05 17 2011 peter.wang
 * removed!
 * .
 *
 * 05 16 2011 peter.wang
 * removed!
 * .
 *
 * 05 11 2011 peter.wang
 * removed!
 * .
 *
 * 04 26 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 04 18 2011 peter.wang
 * removed!
 * .
 *
 * 04 15 2011 peter.wang
 * removed!
 * .
 *
 * 02 17 2011 cm.huang
 * removed!
 * .
 *
 * 01 14 2011 cm.huang
 * removed!
 * .
 *
 * 12 06 2010 cm.huang
 * removed!
 * .
 *
 * 12 06 2010 cm.huang
 * removed!
 * .
 *
 * 12 01 2010 cm.huang
 * removed!
 * .
 *
 * 11 26 2010 cm.huang
 * removed!
 * .
 *
 * 11 24 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
 * macros and options
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/****************************************************************************
 * include directives
 ****************************************************************************/
/* system includes */
#include "app_ltlcom.h" /* Task message communiction */

#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6252_SERIES)

#include <idp_core.h>

#include <idp_camera_preview.h>
#include <mt6252/idp_engines.h>
#include <idp_cam_if.h>

#if defined(IDP_HISR_SUPPORT)
#include <mt6252/idp_hisr.h>
#endif
#include <mt6252/idp_scen_common_mt6252.h>

//include wfc check busy api
#include <wfc/inc/wfc_mm_api.h>

/* to access the define of __POSTPROC_SUPPORT__ */
#include "pp_feature_def.h"

//include G2D api
#include "g2d_enum.h"
#include "g2d_common_api.h"
#include "g2d_lt_api.h"
#include "g2d_bitblt_api.h"
#include "g2d_font_api.h"
#include "g2d_rectfill_api.h"
#include "g2d_mutex.h"

//include CAL api
#include "cal_task_msg_if.h"

IDP_COMMON_API_DECLARATION(camera_preview)

#if (defined(__POSTPROC_SUPPORT__) && defined(G2D_SUPPORT))
#define IDP_USE_G2D_AS_2NDPASS
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
#define IDP_SELF_2NDPASS
#endif

/****************************************************************************
 * local variables
 ****************************************************************************/
static struct
{
    // Note this! this does not represent HW/SW trigger...
    kal_bool                  enable_trigger_lcd; /**< KAL_TRUE to enable trigger LCD, KAL_FALSE to disable trigger LCD */

    /**  CRZ param/config_cp START  *************************************/
    kal_uint16                image_src_width;  /* image width for CRZ input */
    kal_uint16                image_src_height; /* image height for CRZ input */
    kal_uint16                preview_width;    /* image width for LCD preview */
    kal_uint16                preview_height;   /* image height for LCD preview */

    kal_bool                  enable_crz_frame_start_intr;
    /**  CRZ param/config_cp   END  *************************************/

    /**  ROT0 param/config_cp  START  ***********************************/
    kal_uint32                frame_buffer_address; /* image buffer for LCM source buffer */
    kal_uint32                frame_buffer_address1; /* second image buffer for LCM source buffer */
    kal_uint32                frame_buffer_address2; /* Third image buffer for LCM source buffer */

    img_rot_angle_enum_t      rot_angle;
#if defined(__CAMERA_GYRO_SUPPORT__)
    MM_IMAGE_COLOR_FORMAT_ENUM preview_image_color_format;
#endif
    /**  ROT0 param/config_cp    END  ***********************************/

    /** FW trigger param ***********/
    kal_uint32                 preview_buffer_idx;
    /**  FW trigger param   END  *******/

    /** crop param ***********/
    //kal_bool                  enable_crop; /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint16                crop_width;
    kal_uint16                crop_height;

    kal_bool                  dbuf_tearing_free_enable;
    /** crop param END***********/

#if defined(__ATV_SUPPORT__)
    kal_bool                  trigger_display_delay_to_frame_start_enable;
#endif

#if (defined(IDP_USE_G2D_AS_2NDPASS) || defined(IDP_SELF_2NDPASS))
    kal_bool                  postproc_image_enable;
    img_rot_angle_enum_t      postproc_image_rot_angle;
    kal_uint32                postproc_image_width;
    kal_uint32                postproc_image_height;
    kal_uint32                postproc_image_buffer_address[3]; 

    MM_IMAGE_COLOR_FORMAT_ENUM postproc_image_color_format;

    kal_bool                  mav_capture_enable;
#endif

    kal_bool                  end_config;

    kal_bool                  crop_en;
#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    kal_uint32                cp_tmp_buffer;
    tile_calc_para            tile_para;
#endif
} config_cp;


#if defined(IDP_HISR_SUPPORT)
static idp_hisr_handle_t idp_camera_preview_frame_start_hisr_handle;
static idp_hisr_handle_t idp_camera_preview_display_frame_done_hisr_handle;
#endif

#if defined(MT6252H) || defined(MT6252)
static kal_bool _idp_scen_crz_width_over_limit = KAL_FALSE;
static kal_uint32 _idp_scen_crz_over_limit_width;
#endif

#if defined(__ATV_SUPPORT__)
kal_bool idp_camera_preview_pxd;
#endif

#if defined(IDP_USE_G2D_AS_2NDPASS)
static kal_bool idp_g2d_busy_flag;
static G2D_HANDLE_STRUCT *G2D_CAL_handle;
#endif

#if (defined(IDP_USE_G2D_AS_2NDPASS) || defined(IDP_SELF_2NDPASS))
static kal_uint32 postproc_output_buffer_idx = 0;
#endif

#if defined(IDP_SELF_2NDPASS)
enum idp_cp_2pass_state_enum
{
    IDP_CP_2PASS_STATE_NULL,
    IDP_CP_2PASS_STATE_LCD,
    IDP_CP_2PASS_STATE_PP
};
typedef enum idp_cp_2pass_state_enum idp_cp_2pass_state_t;

static idp_cp_2pass_state_t cp_2pass_state = IDP_CP_2PASS_STATE_NULL;
#endif

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
static kal_bool idp_cp_width_over_limit = KAL_FALSE;
static kal_bool idp_cp_crop_setting_in_use = KAL_FALSE;
static kal_uint32 idp_cp_pass_num = 1;
static kal_uint32 idp_cp_crop_width = 0;
static kal_uint32 idp_cp_crop_height = 0;
#endif

/****************************************************************************
 * local function bodies -- LISR
 ****************************************************************************/
static void rotdma0_config_lcd_buffer_addr(kal_uint32 buffer)
{
#if defined(MT6252H) || defined(MT6252)
    if (_idp_scen_crz_width_over_limit == KAL_TRUE)
    {
        REG_IMGDMA_ROT_DMA_Y_DST_STR_ADDR = buffer + (_idp_scen_crz_over_limit_width-320)*crz_struct.tar_height;
    }
    else
#endif
    {
        REG_IMGDMA_ROT_DMA_Y_DST_STR_ADDR = buffer;
    }
    rotdma0_struct.y_dest_start_addr = REG_IMGDMA_ROT_DMA_Y_DST_STR_ADDR;

#if defined(__CAMERA_GYRO_SUPPORT__)
    if (rotdma0_struct.yuv_color_fmt == MM_IMAGE_COLOR_FORMAT_YUV420)
    {
        kal_uint32 size = crz_struct.tar_width * crz_struct.tar_height;

        rotdma0_struct.u_dest_start_addr = rotdma0_struct.y_dest_start_addr + size;
        rotdma0_struct.v_dest_start_addr = rotdma0_struct.u_dest_start_addr + (size>>2);

        REG_IMGDMA_ROT_DMA_U_DST_STR_ADDR = rotdma0_struct.u_dest_start_addr;
        REG_IMGDMA_ROT_DMA_V_DST_STR_ADDR = rotdma0_struct.v_dest_start_addr;
    }
#endif
}

static void
_idp_scen_cp__lisr_crz__frame_start(void *user_data)
{
#if defined(__MTK_TARGET__)

    idp_add_traced_lisr(IDP_TRACED_API_camera_preview__________CRZ_START_LISR);

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    resz_esd_check_flag = KAL_TRUE;
#endif

#if defined(IDP_HISR_SUPPORT)
    idp_hisr_activate(idp_camera_preview_frame_start_hisr_handle);
#endif

#endif
}

static void 
_idp_scen_cp_lcd_change_buffer(void)
{
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        if (1 < _idp_scen_display_buffer_cnt)
        {
            // Currently 0 for display done. Switch to write buffer 1
            rotdma0_config_lcd_buffer_addr(_idp_scen_display_buffer_addr[1]);
        }
        else
        {
            // Currently 0 for display done, but we only have 1 buffer now
            // Still set write buffer to 0
            rotdma0_config_lcd_buffer_addr(_idp_scen_display_buffer_addr[0]);
        }
    }
    else
#endif
    {
        if (0 == config_cp.preview_buffer_idx)  // Currently writing buffer 0 done.
        {
            // Switch to write to buffer 1
            rotdma0_config_lcd_buffer_addr(config_cp.frame_buffer_address1);
        }
        else if (1 == config_cp.preview_buffer_idx)// Currently writing buffer 1 done.
        {
            // Switch to write to buffer 0
            rotdma0_config_lcd_buffer_addr(config_cp.frame_buffer_address);
        }
    }
}

#if defined(IDP_SELF_2NDPASS)
static void 
_idp_scen_cp_pp_change_buffer(void)
{
    kal_uint32 size = crz_struct.tar_width * crz_struct.tar_height;

    rotdma0_struct.y_dest_start_addr = config_cp.postproc_image_buffer_address[postproc_output_buffer_idx];
    rotdma0_struct.u_dest_start_addr = rotdma0_struct.y_dest_start_addr + size;
    rotdma0_struct.v_dest_start_addr = rotdma0_struct.u_dest_start_addr + (size>>2);
}

static void 
_idp_scen_cp_pp_change_state(void)
{
    // Pass2 change format and output size only
    if (cp_2pass_state == IDP_CP_2PASS_STATE_LCD)
    {
        // Change ROTDMA dest address, color format and rotate angle
        _idp_scen_cp_pp_change_buffer();
        rotdma0_struct.yuv_color_fmt = config_cp.postproc_image_color_format;
        rotdma0_struct.rot_angle = IMG_ROT_ANGLE_0;

        cp_2pass_state = IDP_CP_2PASS_STATE_PP;
    }
    else if (cp_2pass_state == IDP_CP_2PASS_STATE_PP)
    {
        // Change ROTDMA dest address, color format and rotate angle
        _idp_scen_cp_lcd_change_buffer();
        rotdma0_struct.yuv_color_fmt = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
        rotdma0_struct.rot_angle = config_cp.rot_angle;

        cp_2pass_state = IDP_CP_2PASS_STATE_LCD;
    }

    // Change rotdma src width/height
    rotdma0_struct.src_width = crz_struct.tar_width;
    rotdma0_struct.src_height = crz_struct.tar_height;

    idp_imgdma_rotdma0_config_partial(&rotdma0_struct);
}
#endif

static void
_idp_scen_cp__lisr_rotdma0__frame_done(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_camera_preview__________ROTDMA0_DONE_LISR);

#if defined(__ATV_SUPPORT__)
    idp_camera_preview_pxd = KAL_FALSE;
#endif

#if defined(IDP_SELF_2NDPASS)
    if (KAL_TRUE == config_cp.mav_capture_enable)
    {
        _idp_scen_cp_pp_change_state();
    }
#endif

    // MATV no need check busy
#if defined(__ATV_SUPPORT__)
    if (KAL_TRUE != config_cp.trigger_display_delay_to_frame_start_enable)
#endif
    {
        // No switch and trigger LCD
        if ((WFC_TRUE == wfcMMCheckBusy()) && (config_cp.dbuf_tearing_free_enable == KAL_TRUE))
        {
          #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            if (KAL_FALSE == _idp_scen_triple_display_buffer_enable)
          #endif
          #if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
            if (KAL_FALSE == idp_cp_width_over_limit)
          #endif
            {
                rotdma0_warm_reset();
                IMGDMA_ROTDMA_START();

                return;
            }
        }
    }

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    if (KAL_FALSE == idp_cp_width_over_limit)
#endif
    {
    rotdma0_warm_reset();

#if defined(IDP_SELF_2NDPASS)
    if (KAL_FALSE == config_cp.mav_capture_enable)
#endif
    {
        _idp_scen_cp_lcd_change_buffer();
    }

    IMGDMA_ROTDMA_START();
    }
#if defined(IDP_HISR_SUPPORT)
    if (KAL_TRUE == config_cp.enable_trigger_lcd)
    {
        idp_hisr_activate(idp_camera_preview_display_frame_done_hisr_handle);
    }
#endif
}

static void
_idp_scen_cp__lisr_crz__pixel_dropped(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_camera_preview________________CRZ_PIXEL_DROPPED_LISR);

#if defined(__ATV_SUPPORT__)
    idp_camera_preview_pxd = KAL_TRUE;
#endif
}

static void
_idp_scen_cp__lisr_crz__lock_drop_frame(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_camera_preview________________CRZ_LOCK_DROP_FRAME_LISR);
}

/****************************************************************************
 * local function bodies -- HISR
 ****************************************************************************/
#if defined(IDP_HISR_SUPPORT)
static void idp_camera_preview_update_lcd_buffer(void)
{
    CAL_BUFFER_CB_STRUCT rCPFrmDoneCBArg;
    CAL_CALLBACK_ID_ENUM eCBID = IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE;

#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        // get buffer for display, buffer 0 always for display
        rCPFrmDoneCBArg.ImageBuffAddr = _idp_scen_display_buffer_addr[0];

        // enable release write buffer and disable acquire next buffer process for triple display buffer
        rCPFrmDoneCBArg.EnableAcquireWriteBuffer= KAL_FALSE;
    }
    else
#endif
    {
        // Currently writing buffer 0 done, change index to 1
        if (0 == config_cp.preview_buffer_idx)
        {
            rCPFrmDoneCBArg.ImageBuffAddr = config_cp.frame_buffer_address;
            config_cp.preview_buffer_idx = 1;
        }
        else if (1 == config_cp.preview_buffer_idx)  // Currently writing buffer 0 done, change index to 0
        {
            rCPFrmDoneCBArg.ImageBuffAddr = config_cp.frame_buffer_address1;
            config_cp.preview_buffer_idx = 0;
        }

        // enable release and acquire write buffer process for double display buffer
        rCPFrmDoneCBArg.EnableAcquireWriteBuffer= KAL_TRUE;
    }

    rCPFrmDoneCBArg.EnableReleaseWriteBuffer= KAL_TRUE;

    // Trigger delay one frame and this is first frame of frame start 
#if defined(__ATV_SUPPORT__)
    if ((KAL_TRUE == config_cp.trigger_display_delay_to_frame_start_enable) && (completed_display_buffer_count < 2))
    {
        completed_display_buffer_count++;
        return; // First 2 frame no trigger display
    }
#endif

    rCPFrmDoneCBArg.ImageBuffFormat = (MM_IMAGE_FORMAT_ENUM) MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
    rCPFrmDoneCBArg.ImageRotateAngle = (MM_IMAGE_ROTATE_ENUM) config_cp.rot_angle;
    rCPFrmDoneCBArg.ImageBuffSize = crz_struct.tar_width * crz_struct.tar_height * 2;

#if defined(__CAMERA_GYRO_SUPPORT__)
    if (rotdma0_struct.yuv_color_fmt == MM_IMAGE_COLOR_FORMAT_YUV420)
    {
        rCPFrmDoneCBArg.ImageBuffFormat = (MM_IMAGE_FORMAT_ENUM) MM_IMAGE_COLOR_FORMAT_YUV420;
        rCPFrmDoneCBArg.ImageBuffSize = (crz_struct.tar_width * crz_struct.tar_height * 3) >> 1;
    }
#endif

#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        // release current display buffer if MDP holds more than 1 display buffer and 
        // release function is success
        // if we only hold 1 frame, no trigger display and no return buffer
        if (1 < _idp_scen_display_buffer_cnt)
        {
            if (pfIDP_CAL_CB(eCBID, &rCPFrmDoneCBArg, sizeof(CAL_BUFFER_CB_STRUCT)) == MM_ERROR_NONE)
            {
                // return current display buffer 0
                // and set next frame done buffer 0 is next frame current display buffer
                _idp_scen_display_buffer_addr[0] = _idp_scen_display_buffer_addr[1];
                _idp_scen_display_buffer_addr[1] = _idp_scen_display_buffer_addr[2];
                _idp_scen_display_buffer_cnt--;
            }
        }
    }
    else
#endif
    {
        // release and get new buffer
        pfIDP_CAL_CB(eCBID, &rCPFrmDoneCBArg, sizeof(CAL_BUFFER_CB_STRUCT));
    }
}

#if (defined(IDP_USE_G2D_AS_2NDPASS) || defined(IDP_SELF_2NDPASS))
static void idp_camera_preview_update_pp_buffer(void)
{
    CAL_BUFFER_CB_STRUCT rCPFrmDoneCBArg;
    CAL_CALLBACK_ID_ENUM eCBID = IDPCAL_CBID_CAM_PREVIEW_POSTPROC_FRM_DONE;

    kal_uint32 size = config_cp.postproc_image_width * config_cp.postproc_image_height;

    rCPFrmDoneCBArg.ImageBuffYAddr = config_cp.postproc_image_buffer_address[postproc_output_buffer_idx];
    rCPFrmDoneCBArg.ImageBuffUAddr = rCPFrmDoneCBArg.ImageBuffYAddr + size;
    rCPFrmDoneCBArg.ImageBuffVAddr = rCPFrmDoneCBArg.ImageBuffUAddr + (size>>2);

    postproc_output_buffer_idx = (postproc_output_buffer_idx+1) % 3;

    rCPFrmDoneCBArg.ImageBuffAddr = rCPFrmDoneCBArg.ImageBuffYAddr;

    // fill in image color format and rotate angle
    rCPFrmDoneCBArg.ImageBuffFormat = (MM_IMAGE_FORMAT_ENUM) config_cp.postproc_image_color_format;
    rCPFrmDoneCBArg.ImageRotateAngle = (MM_IMAGE_ROTATE_ENUM) IMG_ROT_ANGLE_0;

    // fill in image buffer size
    // MAV supports YUV420 postproc format
    if (MM_IMAGE_COLOR_FORMAT_YUV420 == config_cp.postproc_image_color_format)
    {
        rCPFrmDoneCBArg.ImageBuffYSize = size;
        rCPFrmDoneCBArg.ImageBuffUSize = (size>>2);
        rCPFrmDoneCBArg.ImageBuffVSize = rCPFrmDoneCBArg.ImageBuffUSize;          
        rCPFrmDoneCBArg.ImageBuffSize = rCPFrmDoneCBArg.ImageBuffYSize + rCPFrmDoneCBArg.ImageBuffUSize +
                                        rCPFrmDoneCBArg.ImageBuffVSize;
    }
    else if (MM_IMAGE_COLOR_FORMAT_RGB565 == config_cp.postproc_image_color_format)
    {       
        rCPFrmDoneCBArg.ImageBuffSize = (size<<1);
    }

    pfIDP_CAL_CB(eCBID, &rCPFrmDoneCBArg, sizeof(CAL_BUFFER_CB_STRUCT));
}
#endif

#if defined(IDP_USE_G2D_AS_2NDPASS)
static void idp_cal_g2d_cb(void *user_data)
{
    g2dReleaseHandle((G2D_HANDLE_STRUCT *)G2D_CAL_handle);

    idp_g2d_busy_flag = KAL_FALSE;
    idp_camera_preview_update_pp_buffer();
}

typedef struct
{
    float m[9];
} g2d_lt_matrix_struct;


static void idp_g2d_2pass_config()
{
    CAL_G2D_REQ_STRUCT *local_para_ptr;
    CAL_G2D_REQ_STRUCT ilm_param;
    G2D_STATUS_ENUM g2d_status = G2D_STATUS_OK;
    kal_uint8 *bufferAddr[3];
    kal_uint32 bufferSize[3];
    float s1,s2;
    g2d_lt_matrix_struct lt_matrix;

    ////////////////////////////////////////////////////////////////////////////////
    ilm_param.mem_in_color_fmt1 = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;

#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        // get buffer for display, buffer 0 always for display
        ilm_param.src_buff_y_addr = _idp_scen_display_buffer_addr[0];
    }
    else
#endif
    {
        // Currently writing buffer 0 done, change index to 1
        if (0 == config_cp.preview_buffer_idx)
        {
            ilm_param.src_buff_y_addr = config_cp.frame_buffer_address;
        }
        else if (1 == config_cp.preview_buffer_idx)  // Currently writing buffer 0 done, change index to 0
        {
            ilm_param.src_buff_y_addr = config_cp.frame_buffer_address1;
        }
    }

    if (config_cp.rot_angle == IMG_MIRROR_ROT_ANGLE_90)
    {
        ilm_param.src_width = config_cp.preview_height;
        ilm_param.src_height = config_cp.preview_width;
    }
    else
    {
        ilm_param.src_width = config_cp.preview_width;
        ilm_param.src_height = config_cp.preview_height;
    }

    ilm_param.yuv_color_fmt = MM_IMAGE_COLOR_FORMAT_RGB565;
    ilm_param.y_dest_start_addr = config_cp.postproc_image_buffer_address[postproc_output_buffer_idx];

    ilm_param.tar_width = config_cp.postproc_image_width;
    ilm_param.tar_height = config_cp.postproc_image_height;

    ilm_param.rot_angle = config_cp.rot_angle;
    ilm_param.cb_func = (idp_g2d_cb_func_t) idp_cal_g2d_cb;



    // Ori CAL do 
    local_para_ptr = &ilm_param;

    if (KAL_FALSE == g2d_mutex_check_given_status_only())
    {
        //g2d_mutex_wait_hwg2d_release();
        //HW G2D be used by another task!!!.
        return;
    }

    g2d_status = g2dGetHandle(&G2D_CAL_handle, G2D_CODEC_TYPE_HW, G2D_GET_HANDLE_MODE_DIRECT_RETURN_HANDLE);

    if(g2d_status != G2D_STATUS_OK)
    {
        ASSERT(0);
    }
    
    g2dSetDstBufferSwitchBehavior(G2D_CAL_handle, GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH);
    g2dSetColorReplacement(G2D_CAL_handle, KAL_FALSE, 0, 0, 0, 0, 0, 0, 0, 0);
    g2dSetSrcKey(G2D_CAL_handle, KAL_FALSE, 0, 0, 0, 0);
    g2dSetDithering(G2D_CAL_handle,KAL_FALSE,G2D_DITHERING_MODE_FIXED_PATTERN); 
    g2dSetDstRGBBufferInfo(
          G2D_CAL_handle, 
          (kal_uint8*)local_para_ptr->y_dest_start_addr, 
          (local_para_ptr->tar_width * local_para_ptr->tar_height * 2),
          local_para_ptr->tar_width, 
          local_para_ptr->tar_height, 
          G2D_COLOR_FORMAT_RGB565);   
    g2d_status = g2dSetDstClipWindow(
                     G2D_CAL_handle,
                     KAL_FALSE, 
                     0, 
                     0,  
                     local_para_ptr->tar_width,
                     local_para_ptr->tar_height);
    g2d_status = g2dLTSetDstWindow(G2D_CAL_handle, 0, 0, local_para_ptr->tar_width, local_para_ptr->tar_height);
    if (g2d_status == G2D_STATUS_RANGE_CHECK_FAIL)
    {
        ASSERT(0);
    }
    bufferAddr[0] = (kal_uint8*)local_para_ptr->src_buff_y_addr;
    bufferSize[0] = local_para_ptr->src_width * local_para_ptr->src_height * 2;
    g2dLTSetSrcYUVBufferInfo(
        G2D_CAL_handle,
        bufferAddr,
        bufferSize,
        local_para_ptr->src_width,
        local_para_ptr->src_height,
        G2D_COLOR_FORMAT_UYVY422);

    g2d_status = g2dLTSetSrcWindow(G2D_CAL_handle, 0, 0, local_para_ptr->src_width, local_para_ptr->src_height);
    g2dLTSetSrcAlpha(G2D_CAL_handle, KAL_FALSE, 0);
    g2dLTSetDstAlpha(G2D_CAL_handle, KAL_FALSE, 0);
    g2dLTSetSampleMode(G2D_CAL_handle, G2D_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE);

    /* get inverse matrix */
    kal_mem_set((void*) &lt_matrix.m[0], 0x0, 9*sizeof(lt_matrix.m[0]));
    if (local_para_ptr->rot_angle == IMG_MIRROR_ROT_ANGLE_90)
    {
        s1 = (float)local_para_ptr->tar_height;
        s2 = (float)local_para_ptr->src_width;
        //lt_matrix.m[1] = -(float)((float)s2/(float)s1);
        //lt_matrix.m[2] = (float)local_para_ptr->src_width-1;
        lt_matrix.m[1] = (float)((float)s2/(float)s1);
        lt_matrix.m[2] = 0;
        s1 = (float)local_para_ptr->tar_width;
        s2 = (float)local_para_ptr->src_height;
        lt_matrix.m[3] = (float)((float)s2/(float)s1);
        lt_matrix.m[5] = 0;
        //lt_matrix.m[3] = -(float)((float)s2/(float)s1);
        //lt_matrix.m[5] = (float)local_para_ptr->src_height-1;
        lt_matrix.m[8] = 1;
    }
    else if (local_para_ptr->rot_angle == IMG_ROT_ANGLE_0)
    {
        s1 = (float)local_para_ptr->tar_width;
        s2 = (float)local_para_ptr->src_width;
        lt_matrix.m[0] = (float)((float)s1/(float)s2);
        s1 = (float)local_para_ptr->tar_height;
        s2 = (float)local_para_ptr->src_height;
        lt_matrix.m[4] = (float)((float)s1/(float)s2);
        lt_matrix.m[8] = 1;
    }
    g2dLTSetMatrix(G2D_CAL_handle, lt_matrix.m);
    g2dLTSetInverseMatrix(G2D_CAL_handle, lt_matrix.m);

    g2dSetCallbackFunction(G2D_CAL_handle, (G2D_CALLBACK_FUNC_PTR)local_para_ptr->cb_func);

    g2d_status = g2dLTStart(G2D_CAL_handle);
    if (((G2D_STATUS_RANGE_CHECK_FAIL == g2d_status) || (G2D_STATUS_HW_ERROR == g2d_status)))
    {
        ASSERT(0);
    }
}
#endif

static kal_bool
_idp_scen_cp__hisr_crz__frame_start(void *user_data)
{
    kal_uint32 const savedMask = SaveAndSetIRQMask();
    kal_bool const enable = config_cp.enable_crz_frame_start_intr;
    RestoreIRQMask(savedMask);

    // Triger display in frame start
#if defined(__ATV_SUPPORT__)
    if (KAL_TRUE == config_cp.trigger_display_delay_to_frame_start_enable)
    {
        idp_camera_preview_update_lcd_buffer();
    }
#endif

#if defined(IDP_SELF_2NDPASS)
    // Pass2 change format and output size only
    if (cp_2pass_state == IDP_CP_2PASS_STATE_LCD)
    {
        crz_struct.tar_width = config_cp.postproc_image_width;
        crz_struct.tar_height = config_cp.postproc_image_height;
    }
    else if (cp_2pass_state == IDP_CP_2PASS_STATE_PP)
    {
        // Change CRZ tar width/height to preview
        crz_struct.tar_width = config_cp.preview_width;
        crz_struct.tar_height = config_cp.preview_height;
    }

    idp_resz_crz_config_real(&crz_struct, KAL_TRUE);
#endif

    if (KAL_TRUE == enable)
    {
        pfIDP_CAL_CB(IDPCAL_CBID_CAM_PREVIEW_CRZ_FRM_START, NULL, 0);
    }
    return KAL_TRUE;
}

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
static void idp_cp_config_and_start_next_pass()
{
    // stop current pass
    idp_imgdma_rotdma0_stop_real(&rotdma0_struct);
    idp_resz_crz_stop_real(&crz_struct);

    //config CRZ
    if (0 == idp_cp_pass_num)
    {
        crz_struct.input_src1 = IDP_MODULE_OUTER_ISP;
        crz_struct.fstart1_intr_en = KAL_TRUE;
        crz_struct.auto_restart = KAL_TRUE;
        crz_struct.clip_en = KAL_FALSE;
        // set CRZ to bypass mode because of limitation
        crz_struct.src_width = config_cp.image_src_width;
        crz_struct.src_height = config_cp.image_src_height;
        crz_struct.tar_width = config_cp.crop_width;
        crz_struct.tar_height = config_cp.crop_height;
        crz_struct.org_width = config_cp.crop_width;
        if (KAL_FALSE == idp_cp_crop_setting_in_use)
        {
            idp_cp_crop_width = config_cp.crop_width;
            idp_cp_crop_height = config_cp.crop_height;
            idp_cp_crop_setting_in_use = KAL_TRUE;
        }

        crz_struct.crop_en1 = config_cp.crop_en;
        idp_config_crz_crop(config_cp.image_src_width, config_cp.image_src_height, 
                            config_cp.crop_width, config_cp.crop_height);
        crz_struct.tile_mode = KAL_FALSE;
    }
    else
    {
        crz_struct.input_src1 = IDP_MODULE_IMGDMA_RDMA0;
        crz_struct.fstart1_intr_en = KAL_FALSE;
        crz_struct.auto_restart = KAL_FALSE;
        crz_struct.clip_en = KAL_TRUE;
        crz_struct.org_width = idp_cp_crop_width;

        if (1 == idp_cp_pass_num)
        {
            // tile pass 1 setting
            crz_struct.src_width = config_cp.tile_para.tile_src_size_x[0];
            crz_struct.src_height = idp_cp_crop_height;
            crz_struct.tar_width = config_cp.preview_width >> 1;
            crz_struct.tar_height = config_cp.preview_height;
            crz_struct.src_buff_y_addr = config_cp.cp_tmp_buffer;

            crz_struct.crop_en1 = KAL_TRUE;
            crz_struct.crop_left1 = config_cp.tile_para.tile_bi_sa_src_start_pos[0] - config_cp.tile_para.tile_adj_src_start_pos[0];
            crz_struct.crop_right1 = config_cp.tile_para.tile_bi_sa_src_end_pos[0] - config_cp.tile_para.tile_adj_src_start_pos[0];
            crz_struct.crop_top1 = 0;
            crz_struct.crop_bottom1 = idp_cp_crop_height - 1;

            // Tile Setting
            crz_struct.tile_mode = KAL_TRUE;
            crz_struct.tile_org_frame_width = idp_cp_crop_width;
            crz_struct.tile_org_tar_width = config_cp.preview_width;
            crz_struct.tile_start_pos_x = config_cp.tile_para.tile_start_pos_x[0];
            crz_struct.tile_start_pos_y = config_cp.tile_para.tile_start_pos_y[0];
            crz_struct.tile_trunc_err_comp_x = config_cp.tile_para.tile_trunc_err_comp_x[0];
            crz_struct.tile_trunc_err_comp_y = config_cp.tile_para.tile_trunc_err_comp_y[0];
            crz_struct.tile_resid_x = config_cp.tile_para.tile_init_resid_x[0];
            crz_struct.tile_resid_y = config_cp.tile_para.tile_init_resid_y[0];
        }
        else
        {
            // tile pass 2 setting
            crz_struct.src_width = config_cp.tile_para.tile_src_size_x[1];
            crz_struct.src_height = idp_cp_crop_height;
            crz_struct.tar_width = config_cp.preview_width >> 1;
            crz_struct.tar_height = config_cp.preview_height;
            crz_struct.src_buff_y_addr += ((idp_cp_crop_width - crz_struct.src_width) << 1);

            crz_struct.crop_en1 = KAL_TRUE;
            crz_struct.crop_left1 = config_cp.tile_para.tile_bi_sa_src_start_pos[1] - config_cp.tile_para.tile_adj_src_start_pos[1];
            crz_struct.crop_right1 = config_cp.tile_para.tile_bi_sa_src_end_pos[1] - config_cp.tile_para.tile_adj_src_start_pos[1];
            crz_struct.crop_top1 = 0;
            crz_struct.crop_bottom1 = idp_cp_crop_height - 1;

            // Tile Setting
            crz_struct.tile_mode = KAL_TRUE;
            crz_struct.tile_org_frame_width = idp_cp_crop_width;
            crz_struct.tile_org_tar_width = config_cp.preview_width;
            crz_struct.tile_start_pos_x = config_cp.tile_para.tile_start_pos_x[1];
            crz_struct.tile_start_pos_y = config_cp.tile_para.tile_start_pos_y[1];
            crz_struct.tile_trunc_err_comp_x = config_cp.tile_para.tile_trunc_err_comp_x[1];
            crz_struct.tile_trunc_err_comp_y = config_cp.tile_para.tile_trunc_err_comp_y[1];
            crz_struct.tile_resid_x = config_cp.tile_para.tile_init_resid_x[1];
            crz_struct.tile_resid_y = config_cp.tile_para.tile_init_resid_y[1];

            idp_cp_crop_setting_in_use = KAL_FALSE;
        }
    }
    idp_resz_crz_config_real(&crz_struct, KAL_TRUE);

    //config ROTDMA
    rotdma0_struct.src_width = crz_struct.tar_width;
    rotdma0_struct.src_height = crz_struct.tar_height;

    if (0 == idp_cp_pass_num)
    {
        rotdma0_struct.rot_angle = IMG_ROT_ANGLE_0;
        rotdma0_struct.y_dest_start_addr = config_cp.cp_tmp_buffer;
        rotdma0_struct.pitch_enable = KAL_FALSE;
    }
    else
    {
        rotdma0_struct.rot_angle = config_cp.rot_angle;
        rotdma0_struct.pitch_enable = KAL_TRUE;
        if (1 == idp_cp_pass_num)
        {
            if (0 == config_cp.preview_buffer_idx)  // Currently writing buffer 0 done.
            {
                rotdma0_struct.y_dest_start_addr = config_cp.frame_buffer_address;
            }
            else
            {
                rotdma0_struct.y_dest_start_addr = config_cp.frame_buffer_address1;
            }
        }
        else
        {
            if (IMG_ROT_ANGLE_0 == rotdma0_struct.rot_angle)
                rotdma0_struct.y_dest_start_addr += config_cp.preview_width;
            else
                rotdma0_struct.y_dest_start_addr += config_cp.preview_height * config_cp.preview_width;
        }
    }

    rotdma0_warm_reset();
    idp_imgdma_rotdma0_config_partial(&rotdma0_struct);

    //start pass
    idp_imgdma_rotdma0_start_real(&rotdma0_struct);
    idp_resz_crz_start_real(&crz_struct);
}
#endif

static kal_bool
_idp_scen_cp__hisr_rotdma0__frame_done(void *user_data)
{
#if defined(IDP_SELF_2NDPASS)
    // Check enable mav, else update lcd only
    if (KAL_TRUE == config_cp.mav_capture_enable)
    {
        // pp done update lcd and pp buffer together
        if (cp_2pass_state == IDP_CP_2PASS_STATE_LCD)
        {
            idp_camera_preview_update_pp_buffer();
            goto update_lcd;
        }
        else // do nothing.
        {
            return KAL_TRUE;
        }
    }
    else
    {
        goto update_lcd;
    }
update_lcd:
#endif

#if defined(IDP_USE_G2D_AS_2NDPASS)
    if ((KAL_TRUE == config_cp.postproc_image_enable) && (KAL_FALSE == config_cp.mav_capture_enable))
    {
        // Trigger g2d do 2nd pass
        idp_g2d_2pass_config();
    }
#endif

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    // do tile calculation when 1st pass is done
    if (KAL_TRUE == idp_cp_width_over_limit)
    {
        if (1 == idp_cp_pass_num)
        {
            if (idp_cp_crop_width * idp_cp_crop_height <= config_cp.preview_width * config_cp.preview_height)
            {
                idp_bi_tile_calc(idp_cp_crop_width, idp_cp_crop_height,
                                 config_cp.preview_width, config_cp.preview_height,
                                 &config_cp.tile_para);

                crz_struct.sa_en_x = KAL_FALSE;
                crz_struct.sa_en_y = KAL_FALSE;
            }
            else
            {
                idp_sa_tile_calc(idp_cp_crop_width, idp_cp_crop_height,
                                 config_cp.preview_width, config_cp.preview_height,
                                 &config_cp.tile_para);            

                crz_struct.sa_en_x = KAL_TRUE;
                crz_struct.sa_en_y = KAL_TRUE;
            }
        }
    
        idp_cp_config_and_start_next_pass();
    }
#endif

    // Triger display in frame done
#if defined(__ATV_SUPPORT__)
    if (KAL_TRUE != config_cp.trigger_display_delay_to_frame_start_enable)
#endif
#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    // change display buffer only at tile pass 2
    if ((KAL_FALSE == idp_cp_width_over_limit) ||
        (KAL_TRUE == idp_cp_width_over_limit && 
         0 == idp_cp_pass_num &&
         WFC_FALSE == wfcMMCheckBusy()))
#endif
    {
        idp_camera_preview_update_lcd_buffer();
    }

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    if (KAL_TRUE == idp_cp_width_over_limit)
    {
    if (2 == idp_cp_pass_num)
        idp_cp_pass_num = 0;
    else
        //update pass flags
        idp_cp_pass_num++;
    }
#endif

    return KAL_TRUE;
}
#endif  // #if defined(IDP_HISR_SUPPORT)

/****************************************************************************
 * local function bodies -- HW config functions
 ****************************************************************************/
#if defined(__MTK_TARGET__)
static kal_bool
_idp_scen_cp__config_crz(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result;

    crz_struct.input_src1 = IDP_MODULE_OUTER_ISP;

    crz_struct.fstart1_intr_en = KAL_TRUE;
    crz_struct.fstart1_intr_cb = _idp_scen_cp__lisr_crz__frame_start;

    crz_struct.pixel_dropped_intr_en = KAL_TRUE;
    crz_struct.pixel_dropped_intr_cb = _idp_scen_cp__lisr_crz__pixel_dropped;

    crz_struct.lock_drop_frame_intr_en = KAL_TRUE;
    crz_struct.lock_drop_frame_intr_cb = _idp_scen_cp__lisr_crz__lock_drop_frame;

    crz_struct.src_width = config_cp.image_src_width;
    crz_struct.src_height = config_cp.image_src_height;

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    if (KAL_TRUE == idp_cp_width_over_limit)
    {
        // set CRZ to bypass mode because of limitation
        crz_struct.tar_width = config_cp.crop_width;
        crz_struct.tar_height = config_cp.crop_height;
        crz_struct.mem_in_color_fmt1 = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
        crz_struct.src_buff_y_addr = config_cp.cp_tmp_buffer;
        crz_struct.org_width = config_cp.crop_width;
        if (KAL_FALSE == idp_cp_crop_setting_in_use)
        {
            idp_cp_crop_width = config_cp.crop_width;
            idp_cp_crop_height = config_cp.crop_height;            
            idp_cp_crop_setting_in_use = KAL_TRUE;
        }
    }
    else
#endif
    {
    crz_struct.tar_width = config_cp.preview_width;
    crz_struct.tar_height = config_cp.preview_height;
    }

    crz_struct.crop_en1 = config_cp.crop_en;
    crz_struct.auto_restart = KAL_TRUE;
    crz_struct.hw_frame_sync = KAL_TRUE;

#if defined(IDP_SELF_2NDPASS)
    if (KAL_TRUE == config_cp.mav_capture_enable)
    {
        if (cp_2pass_state == IDP_CP_2PASS_STATE_NULL) // config end set state to LCD for pass1
        {
            cp_2pass_state = IDP_CP_2PASS_STATE_LCD;
        }
        else if (cp_2pass_state == IDP_CP_2PASS_STATE_LCD) // config has end and running, next is pp path
        {
            crz_struct.tar_width = config_cp.postproc_image_width;
            crz_struct.tar_height = config_cp.postproc_image_height;
        }
    }
#endif

    //if (KAL_TRUE == crz_struct.crop_en1) // Always TRUE, code shrink
    {
        idp_config_crz_crop(config_cp.image_src_width, config_cp.image_src_height, config_cp.crop_width, config_cp.crop_height);
    }

#if defined(MT6252H) || defined(MT6252)
    if (crz_struct.tar_width >= 320)
    {
        _idp_scen_crz_over_limit_width = crz_struct.tar_width;
        crz_struct.tar_width = 320;
        _idp_scen_crz_width_over_limit = KAL_TRUE;

        // change crop for same width/hieght rate.
        crz_struct.crop_left1 = (config_cp.image_src_width - config_cp.crop_width*320/_idp_scen_crz_over_limit_width) >> 1;
        crz_struct.crop_right1 = crz_struct.crop_left1 + config_cp.crop_width*320/_idp_scen_crz_over_limit_width - 1;
    }
#endif

    result = idp_resz_crz_config(owner->crz_key, &crz_struct, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


static kal_bool
_idp_scen_cp__config_rotdma0(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result;

    if (KAL_TRUE == owner->have_config_imgdma_irt0)
    {
        return KAL_TRUE;
    }

#if defined(__CAMERA_GYRO_SUPPORT__)
    rotdma0_struct.yuv_color_fmt = config_cp.preview_image_color_format;
#else
    rotdma0_struct.yuv_color_fmt = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
#endif

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    if (KAL_TRUE == idp_cp_width_over_limit)
    {
        if (NULL == config_cp.cp_tmp_buffer)
        {
            return KAL_FALSE;
        }
        else
        {
            rotdma0_struct.y_dest_start_addr = config_cp.cp_tmp_buffer;
            if (IMG_ROT_ANGLE_0 == config_cp.rot_angle)
                rotdma0_struct.pitch_bytes = (config_cp.preview_width << 1); //Final width
            else
                rotdma0_struct.pitch_bytes = (config_cp.preview_height << 1); //Final width
        }
    }
    else
#endif
    rotdma0_struct.y_dest_start_addr = config_cp.frame_buffer_address;

#if defined(__CAMERA_GYRO_SUPPORT__)
    if (rotdma0_struct.yuv_color_fmt == MM_IMAGE_COLOR_FORMAT_YUV420)
    {
        kal_uint32 size = crz_struct.tar_width * crz_struct.tar_height;
        rotdma0_struct.u_dest_start_addr = rotdma0_struct.y_dest_start_addr + size;
        rotdma0_struct.v_dest_start_addr = rotdma0_struct.u_dest_start_addr + (size>>2);
    }
#endif

    rotdma0_struct.src_width = crz_struct.tar_width;
    rotdma0_struct.src_height = crz_struct.tar_height;

    rotdma0_struct.fend_intr_en = KAL_TRUE;
    rotdma0_struct.fend_intr_cb = _idp_scen_cp__lisr_rotdma0__frame_done;

    rotdma0_struct.hw_frame_sync = KAL_TRUE;

    rotdma0_struct.protect_en = KAL_TRUE;   //According to spec. From Camera, enable protect
    rotdma0_struct.bus_control_threshold = ROTDMA_BUS_CONTROL_THRESHOLD;

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    if (KAL_TRUE == idp_cp_width_over_limit)
        rotdma0_struct.rot_angle = IMG_ROT_ANGLE_0;
    else
#endif
    rotdma0_struct.rot_angle = config_cp.rot_angle;

#if defined(MT6252H) || defined(MT6252)
    // reset start address, clear write buffer to black
    if (_idp_scen_crz_width_over_limit == KAL_TRUE)
    {
        kal_uint32 i, size;
        kal_uint32* pu4Addr1= (kal_uint32*) config_cp.frame_buffer_address;
        kal_uint32* pu4Addr2= (kal_uint32*) config_cp.frame_buffer_address1;

        rotdma0_struct.y_dest_start_addr += (_idp_scen_crz_over_limit_width-320)*crz_struct.tar_height;

        size = (_idp_scen_crz_over_limit_width*crz_struct.tar_height) >> 1;
        for (i = 0; i <size; i++)
        {
            *(pu4Addr1 + i) = 0x00800080;
            *(pu4Addr2 + i) = 0x00800080;
        }
    }
#endif

    result = idp_imgdma_rotdma0_config(owner->irt0_key, &rotdma0_struct, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    owner->have_config_imgdma_irt0 = KAL_TRUE;

#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        //record the 3 display buffers
        _idp_scen_display_buffer_addr[0] = config_cp.frame_buffer_address;
        _idp_scen_display_buffer_addr[1] = config_cp.frame_buffer_address1;
        _idp_scen_display_buffer_addr[2] = config_cp.frame_buffer_address2;
        _idp_scen_display_buffer_cnt = 3;
    }
#endif

    return KAL_TRUE;
}

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies -- IDP scenario hook function bodies
 ****************************************************************************/
static void
idp_camera_preview_init_config_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

#if defined(IDP_HISR_SUPPORT)
    if (idp_camera_preview_frame_start_hisr_handle == NULL)
    {
        idp_camera_preview_frame_start_hisr_handle =
            idp_hisr_register(owner->key,
                              IDP_HISR_CB_TYPE_RESZ,
                              _idp_scen_cp__hisr_crz__frame_start,
                              NULL);
    }

    if (idp_camera_preview_display_frame_done_hisr_handle == NULL)
    {
        idp_camera_preview_display_frame_done_hisr_handle =
            idp_hisr_register(owner->key,
                              IDP_HISR_CB_TYPE_IMGDMA,
                              _idp_scen_cp__hisr_rotdma0__frame_done,
                              NULL);
    }
#endif

#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    _idp_scen_triple_display_buffer_enable = KAL_FALSE;
#endif

#if defined(__ATV_SUPPORT__)
    completed_display_buffer_count = 0;
#endif

    kal_mem_set(&config_cp, 0, sizeof(config_cp));

#if defined(IDP_SELF_2NDPASS)
    cp_2pass_state = IDP_CP_2PASS_STATE_NULL;
#endif
#if (defined(IDP_USE_G2D_AS_2NDPASS) || defined(IDP_SELF_2NDPASS))
    postproc_output_buffer_idx = 0;
#endif

#if defined(IDP_MM_COLOR_SUPPORT)
    colorWrapperOpen(&mm_color_handle, COLOR_SCENARIO_CAMERA_PREVIEW);
    colorWrapperEnable(mm_color_handle, 0);
#endif

#if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
    idp_cp_crop_setting_in_use = KAL_FALSE;
    idp_cp_pass_num = 1;
#endif

#endif  // #if defined(__MTK_TARGET__)
}

kal_bool
idp_camera_preview_close_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

    idp_resz_crz_close(owner->crz_key, &crz_struct);
    idp_imgdma_rotdma0_close(owner->irt0_key, &rotdma0_struct);

#if defined(IDP_HISR_SUPPORT)
    idp_hisr_clear_all(owner->key, IDP_HISR_CB_TYPE_RESZ);
    idp_hisr_clear_all(owner->key, IDP_HISR_CB_TYPE_IMGDMA);

    idp_camera_preview_frame_start_hisr_handle = NULL;
    idp_camera_preview_display_frame_done_hisr_handle = NULL;
#endif

#if defined(IDP_MM_COLOR_SUPPORT)
    colorWrapperDisable(mm_color_handle);
    colorWrapperClose(mm_color_handle);
#endif

#endif  // #if defined(__MTK_TARGET__)

    return KAL_TRUE;
}

kal_bool
idp_camera_preview_read_user_config_fast_hook(
    idp_owner_t * const owner,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
#if defined(__MTK_TARGET__)

    switch (para_type)
    {
      #if defined(IDP_HISR_SUPPORT)
        case IDP_CAMERA_PREVIEW_FRAME_START_HISR_CB_ENABLE:
            {
                // If this is enabled, CRZ LISR will activate a registered HISR to invoke camera DZ...
                kal_uint32 const savedMask = SaveAndSetIRQMask();
                config_cp.enable_crz_frame_start_intr = (kal_bool) para_value;
                RestoreIRQMask(savedMask);
            }
            break;
      #endif
        default:
            return KAL_FALSE;
            //break;
    }
#endif

    return KAL_TRUE;
}

kal_bool
idp_camera_preview_read_user_config_hook(
    idp_owner_t * const owner,
    va_list ap)
{
    kal_uint32 para_type;
    kal_bool finish = KAL_FALSE;

    while (KAL_FALSE == finish)
    {
        para_type = va_arg(ap, kal_uint32);

        switch (para_type)
        {
            case 0:
                finish = KAL_TRUE;
                break;

            case IDP_CAMERA_PREVIEW_IMAGE_SRC_WIDTH:
                config_cp.image_src_width = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_IMAGE_SRC_HEIGHT:
                config_cp.image_src_height = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_PREVIEW_WIDTH:
                config_cp.preview_width = va_arg(ap, kal_uint32);
            #if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
                if (480 < config_cp.preview_width)
                {
                    idp_cp_width_over_limit = KAL_TRUE;
                }
                else
                {
                    idp_cp_width_over_limit = KAL_FALSE;
                }
            #endif
                break;

            case IDP_CAMERA_PREVIEW_PREVIEW_HEIGHT:
                config_cp.preview_height = va_arg(ap, kal_uint32);
                break;

        #if defined(__CAMERA_GYRO_SUPPORT__)
            case IDP_CAMERA_PREVIEW_PREVIEW_IMAGE_COLOR_FORMAT:
                config_cp.preview_image_color_format = va_arg(ap, kal_uint32);
                break;
        #endif

            case IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS:
                config_cp.frame_buffer_address = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS1:
                config_cp.frame_buffer_address1 = va_arg(ap, kal_uint32);
                break;

        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            case IDP_CAMERA_PREVIEW_FRAME_BUFFER_ADDRESS2:
                config_cp.frame_buffer_address2 = va_arg(ap, kal_uint32);

                if (NULL != config_cp.frame_buffer_address2)
                {
                    _idp_scen_triple_display_buffer_enable = KAL_TRUE;
                }
                else
                {
                    _idp_scen_triple_display_buffer_enable = KAL_FALSE;
                }
                break;
        #endif

            case IDP_CAMERA_PREVIEW_DISPLAY_ROT_ANGLE:
                config_cp.rot_angle = (img_rot_angle_enum_t) va_arg(ap, kal_uint32);

                if (!((IMG_ROT_ANGLE_0 == config_cp.rot_angle) ||
                    (IMG_MIRROR_ROT_ANGLE_90 == config_cp.rot_angle)))
                {
                    return KAL_FALSE;
                }
                break;

            case IDP_CAMERA_PREVIEW_ENABLE_TRIGGER_LCD:
                config_cp.enable_trigger_lcd = (kal_bool) va_arg(ap, kal_uint32);
                break;

        #if defined(IDP_HISR_SUPPORT)
            case IDP_CAMERA_PREVIEW_FRAME_START_HISR_CB_ENABLE:
                {
                    kal_uint32 const savedMask = SaveAndSetIRQMask();
                    config_cp.enable_crz_frame_start_intr = (kal_bool) va_arg(ap, kal_uint32);
                    RestoreIRQMask(savedMask);
                }
                break;
        #endif

            case IDP_CAMERA_PREVIEW_PREVIEW_CROP_ENABLE:
                config_cp.crop_en = (kal_bool) va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_PREVIEW_CROP_WIDTH:
                config_cp.crop_width = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_PREVIEW_CROP_HEIGHT:
                config_cp.crop_height = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_ENABLE_DOUBLE_BUFFER_TEARING_FREE:
                config_cp.dbuf_tearing_free_enable = (kal_bool)va_arg(ap, kal_uint32);  
                break;

        #if defined(__ATV_SUPPORT__)
            case IDP_CAMERA_PREVIEW_ENABLE_TRIGGER_DISPLAY_DELAY_TO_FRAME_START:
                config_cp.trigger_display_delay_to_frame_start_enable = (kal_bool) va_arg(ap, kal_uint32);
              #if defined(MT6252H) || defined(MT6252)
                // MT6252 with 5193 MATV will drop frame when LCD and MDP work at the same time.
                // So, default we not delay, let frame done trigger LCD display
                config_cp.trigger_display_delay_to_frame_start_enable = KAL_FALSE;
              #endif
                break;
        #endif

        #if (defined(IDP_USE_G2D_AS_2NDPASS) || defined(IDP_SELF_2NDPASS))
            case IDP_CAMERA_PREVIEW_POSTPROC_PATH_ENABLE:
                config_cp.postproc_image_enable = (kal_bool)va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_WIDTH:
                config_cp.postproc_image_width = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_HEIGHT:
                config_cp.postproc_image_height = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_POSTPROC_ROT_ANGLE: // set 0, if preview rotate, need rotate back
                config_cp.postproc_image_rot_angle = (img_rot_angle_enum_t) va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_1:
            case IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_2:
            case IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_3:
                config_cp.postproc_image_buffer_address[para_type - IDP_CAMERA_PREVIEW_POSTPROC_BUFFER_ADDRESS_1] = va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_POSTPROC_IMAGE_COLOR_FORMAT:
                config_cp.postproc_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_ENABLE_MAV_CAPTURE:
                config_cp.mav_capture_enable = (kal_bool) va_arg(ap, kal_uint32);
                break;
        #endif

            case IDP_CAMERA_PREVIEW_ENG_CONFIG:
                config_cp.end_config = (kal_bool) va_arg(ap, kal_uint32);
                break;

        #if defined(IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT)
            case IDP_CAMERA_PREVIEW_TEMP_BUFFER:
                config_cp.cp_tmp_buffer = (kal_uint32) va_arg(ap, kal_uint32);
                break;
        #endif
        
            default:
                va_arg(ap, kal_uint32);
                break;
        }
    }

    return KAL_TRUE;
}


kal_bool
idp_camera_preview_config_hook(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result = KAL_TRUE;

#if defined(__MTK_TARGET__)
    if (config_cp.end_config == KAL_FALSE)
    {
        return KAL_TRUE;
    }

    result = _idp_scen_cp__config_crz(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    result = _idp_scen_cp__config_rotdma0(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

#endif
    return result;
}

static hook_collect_t hook_collect =
{
    idp_camera_preview_init_config_hook,
    idp_common_open_hook,//idp_camera_preview_open_hook,
    idp_camera_preview_close_hook,
    idp_common_stop_hook,//idp_camera_preview_stop_hook,
    idp_camera_preview_read_user_config_hook,
    idp_camera_preview_read_user_config_fast_hook,
    idp_dummy_hook3,//idp_camera_preview_finish_read_user_config_hook,
    idp_dummy_hook,//idp_camera_preview_hardware_setting_have_been_changed_hook,
    idp_camera_preview_config_hook,
    idp_common_query_hook,//idp_camera_preview_query_hook,
    idp_dummy_hook,//idp_camera_preview_start_intermedia_pipe_hook,
    idp_common_start_input_hook,//idp_camera_preview_start_input_hook,
    idp_common_start_output_hook,//idp_camera_preview_start_output_hook,
    idp_dummy_hook2,//idp_camera_preview_compute_mem_for_each_hw_hook,
    idp_common_is_busy_hook,//idp_camera_preview_is_busy_hook,
    idp_common_is_in_use_hook,//idp_camera_preview_is_in_use_hook,
    idp_dummy_hook2,//idp_camera_preview_clear_setting_diff_hook,
    idp_dummy_hook//idp_camera_preview_is_setting_diff_is_ok_when_busy_hook
};





static IdpCheckReentrant idp_camera_preview_check_reentrant = {KAL_NILTASK_ID, IDP_CALL_BY_HISR, IDP_CHECK_REENTRANT_PREV_OPEN, KAL_FALSE};

kal_bool
idp_camera_preview_open_real(
    kal_uint32 * const key,
    char const * const filename,
    kal_uint32 const lineno)
{
    return idp_scenario_open(key,
                             &idp_camera_preview_check_reentrant,
                             IDP_TRACED_API_camera_preview_OPEN,
                             IDP_SCENARIO_camera_preview,
                             &hook_collect);
}

kal_bool
idp_camera_preview_is_in_use(void)
{
    return idp_scenario_is_in_use(&idp_camera_preview_check_reentrant,
                                  IDP_TRACED_API_camera_preview_IS_IN_USE,
                                  &hook_collect);
}

kal_bool
idp_camera_preview_close(
    kal_uint32 const key)
{
    return idp_scenario_close(key,
                              &idp_camera_preview_check_reentrant,
                              IDP_TRACED_API_camera_preview_CLOSE,
                              &hook_collect);
}

kal_bool
idp_camera_preview_stop(
    kal_uint32 const key)
{
#if defined(IDP_USE_G2D_AS_2NDPASS)
    volatile kal_uint32 i=0;
    while (idp_g2d_busy_flag == KAL_TRUE)
    {
		i++;
		kal_sleep_task(5);
		if(i>200) break;
    }
#endif

    return idp_scenario_stop(key,
                             &idp_camera_preview_check_reentrant,
                             IDP_TRACED_API_camera_preview_STOP,
                             &hook_collect);
}

kal_bool
idp_camera_preview_start_intermedia_pipe(
    kal_uint32 const key)
{
    return idp_scenario_start_intermedia_pipe(key,
                                              &idp_camera_preview_check_reentrant,
                                              IDP_TRACED_API_camera_preview_START_INTERMEDIA_PIPE,
                                              &hook_collect);
}

kal_bool
idp_camera_preview_start_input(
    kal_uint32 const key)
{
    return idp_scenario_start_input(key,
                                    &idp_camera_preview_check_reentrant,
                                    IDP_TRACED_API_camera_preview_START_INPUT,
                                    &hook_collect);
}

kal_bool
idp_camera_preview_start_output(
    kal_uint32 const key)
{
    return idp_scenario_start_output(key,
                                     &idp_camera_preview_check_reentrant,
                                     IDP_TRACED_API_camera_preview_START_OUTPUT,
                                     &hook_collect);
}

kal_bool
idp_camera_preview_start_all(
    kal_uint32 const key)
{
    return idp_scenario_start_all(key,
                                  &idp_camera_preview_check_reentrant,
                                  IDP_TRACED_API_camera_preview_START_ALL,
                                  &hook_collect);
}

kal_bool
idp_camera_preview_is_busy(
    kal_uint32 const key,
    kal_bool * const busy)
{
    return idp_scenario_is_busy(key,
                                busy,
                                IDP_TRACED_API_camera_preview_IS_BUSY,
                                &hook_collect);
}

kal_bool
idp_camera_preview_config_fast(
    kal_uint32 const key,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
    return idp_scenario_config_fast(key,
                                    para_type,
                                    para_value,
                                    IDP_TRACED_API_camera_preview_CONFIG_FAST,
                                    &hook_collect);
}

kal_bool
idp_camera_preview_config(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_config(key,
                                 &idp_camera_preview_check_reentrant,
                                 IDP_TRACED_API_camera_preview_CONFIG,
                                 &hook_collect,
                                 ap);
    va_end(ap);
    return result;

}

kal_bool
idp_camera_preview_configurable(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_configurable(key,
                                       &idp_camera_preview_check_reentrant,
                                       IDP_TRACED_API_camera_preview_CONFIGURABLE,
                                       &hook_collect,
                                       ap);
    va_end(ap);
    return result;
}


kal_bool
idp_camera_preview_query(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_query(key,
                                &idp_camera_preview_check_reentrant,
                                IDP_TRACED_API_camera_preview_QUERY,
                                &hook_collect,
                                ap);
    va_end(ap);
    return result;
}


kal_bool idp_camera_preview_config_and_start(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_config_and_start(key,
                                           &idp_camera_preview_check_reentrant,
                                           IDP_TRACED_API_camera_preview_CONFIG_AND_START,
                                           &hook_collect,
                                           ap);
    va_end(ap);
    return result;
}


#endif  // #if defined(DRV_IDP_6252_SERIES)

