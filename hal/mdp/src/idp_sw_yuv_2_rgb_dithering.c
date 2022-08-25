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
 *    idp_sw_yuv_2_rgb_dithering.c
 *
 * Project:
 * --------
 *	  MAUI
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
 * 09 01 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 06 29 2011 peter.wang
 * removed!
 * .
 *
 * 06 09 2011 hung-wen.hsieh
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * macro definitions
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "drv_features_mdp.h"
#include "kal_release.h"

#if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
#include "cache_sw.h"
#include "mmu.h"

#include "idp_sw_yuv_2_rgb_dithering.h"
#include "iul_csc_y2r_565.h"

/**
 * \def IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE
 * This macro enables idp_sw_yuv_2_rgb_dithering to use dynamic switchable input/output buffers
 * when doing dithering to boost performance.
 */
#if defined(__MTK_TARGET__)
#if defined(CONTOUR_IMPROVEMENT_MT6235)
#define IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE
#endif // #if defined(CONTOUR_IMPROVEMENT_MT6235)
#endif

/****************************************************************************
 * type definitions
 ****************************************************************************/

typedef struct
{
    LOCAL_PARA_HDR
    _idp_sw_yuv_2_rgb_dithering_cmd_t           cmd;
}_idp_sw_yuv_2_rgb_dithering_ilm_local_param_t;

/****************************************************************************
 * local variables
 ****************************************************************************/


/****************************************************************************
 * utilities
 ****************************************************************************/
kal_bool
idp_sw_yuv_2_rgb_dithering_start_hisr(
    kal_uint32 src_w,
    kal_uint32 src_h,
    kal_uint32 src_y_addr, 
    kal_uint32 src_u_addr, 
    kal_uint32 src_v_addr, 
    kal_uint32 tar_rgb_addr,
    idp_sw_yuv_2_rgb_dithering_cbfxn_t cbfxn_dithering_done, 
    void *cbparam_dithering_done)
{
    _idp_sw_yuv_2_rgb_dithering_cmd_t cmd;
    
    ASSERT(0 != src_w);
    ASSERT(0 != src_h);
    ASSERT(0 != src_y_addr);
    ASSERT(0 != src_u_addr);
    ASSERT(0 != src_v_addr);
    ASSERT(0 != tar_rgb_addr);
    ASSERT(NULL != cbfxn_dithering_done);

    {
        kal_uint32 const save_irq_mask = SaveAndSetIRQMask();
        cmd.src_width = src_w;
        cmd.src_height = src_h;
        cmd.src_y_addr = src_y_addr;
        cmd.src_u_addr = src_u_addr;
        cmd.src_v_addr = src_v_addr;
        cmd.tar_rgb_addr = tar_rgb_addr;
        cmd.cbfxn_dithering_done = cbfxn_dithering_done;
        cmd.cbparam_dithering_done = cbparam_dithering_done;
        RestoreIRQMask(save_irq_mask);
    }
    // send ILM to CAL task
    {
        _idp_sw_yuv_2_rgb_dithering_ilm_local_param_t *ilm_param;
        ilm_struct *p_ilm = NULL;

        ilm_param = (_idp_sw_yuv_2_rgb_dithering_ilm_local_param_t*) 
                        construct_local_para(sizeof(_idp_sw_yuv_2_rgb_dithering_ilm_local_param_t), TD_CTRL);
        ASSERT(NULL != ilm_param);

        kal_mem_cpy((void*) &(ilm_param->cmd), (const void*) &cmd, sizeof(_idp_sw_yuv_2_rgb_dithering_cmd_t));

        p_ilm = allocate_ilm(MOD_VISUAL_HISR);
        ASSERT(NULL != p_ilm);
        p_ilm->src_mod_id = MOD_VISUAL_HISR;
        p_ilm->dest_mod_id = MOD_CAL;
        p_ilm->sap_id = CAL_SAP;
        p_ilm->msg_id = (msg_type) MSG_ID_CAL_SW_Y2R_DITHERING_REQ;
        p_ilm->local_para_ptr = (local_para_struct*) ilm_param;
        p_ilm->peer_buff_ptr = NULL;
        msg_send_ext_queue(p_ilm);
    }
    return KAL_TRUE;
}

kal_bool
idp_sw_yuv_2_rgb_dithering_close(void)
{  
    return KAL_TRUE;
}
#endif // #if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)

void
idp_sw_yuv_2_rgb_dithering_start_req_hdlr(
    ilm_struct *ilm_msg)
{
#if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
    _idp_sw_yuv_2_rgb_dithering_ilm_local_param_t *local_para_ptr = NULL;
    _idp_sw_yuv_2_rgb_dithering_cmd_t *cmd = NULL;
    
    ASSERT(NULL != ilm_msg);

    ASSERT(KAL_FALSE == kal_if_hisr());
    ASSERT(KAL_FALSE == kal_if_lisr());

    // get ilm parameters
    local_para_ptr = (_idp_sw_yuv_2_rgb_dithering_ilm_local_param_t*) ilm_msg->local_para_ptr;
    ASSERT(NULL != local_para_ptr);
    cmd = (_idp_sw_yuv_2_rgb_dithering_cmd_t*) &(local_para_ptr->cmd);
    ASSERT(NULL != cmd);

    // start yuv420 to rgb565 dithering
{
    kal_uint32 SrcPitch;
    kal_uint32 SrcYsize;
    kal_uint32 SrcUVsize;
    kal_uint32 DistPitch;

#if defined(IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE)
    kal_uint32 rgbSize;
#endif

    SrcPitch = ((cmd->src_width + 15) >> 4) << 4;  //CRZ HW width padding to 16 multiple
    DistPitch = cmd->src_width;

    SrcYsize = (((SrcPitch * (cmd->src_height)) + 31) >> 5) << 5;  //length must 32 byte alignment for switch cacheable
    SrcUVsize = (((SrcYsize >> 2) + 31) >> 5) << 5;  //length must 32 byte alignment for switch cacheable

#if defined(IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE)
    rgbSize = (((((cmd->src_width)*(cmd->src_height)) << 1) + 31) >> 5) << 5 ; //length must 32 byte alignment for switch cacheable
    
    // switch input/output buffers to cacheable
    dynamic_switch_cacheable_region(&cmd->src_y_addr, SrcYsize, PAGE_CACHEABLE);
    dynamic_switch_cacheable_region(&cmd->src_u_addr, SrcUVsize, PAGE_CACHEABLE);
    dynamic_switch_cacheable_region(&cmd->src_v_addr, SrcUVsize, PAGE_CACHEABLE);
    if ((KAL_TRUE == is_predef_dyna_c_region(cmd->tar_rgb_addr, rgbSize)) && (0 == ((cmd->tar_rgb_addr) %32))) 
    {
       dynamic_switch_cacheable_region(&cmd->tar_rgb_addr, rgbSize, PAGE_CACHEABLE);
    }
#endif //#if defined(IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE)
#if defined(__WRITE_THROUGH_CACHEABLE__)
#if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(__WRITE_THROUGH_CACHEABLE__)
    
    iul_csc_yuv420_to_rgb565_fxp_dithering((kal_uint8 *)cmd->src_y_addr, (kal_uint8 *)cmd->src_u_addr, (kal_uint8 *)cmd->src_v_addr,
                                             SrcPitch, SrcPitch/2,
                                             (kal_uint16 *)cmd->tar_rgb_addr, DistPitch*2,
                                             cmd->src_width, cmd->src_height);

#if defined(IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE)   
    // switch input/output buffers back to non-cacheable for HW
    dynamic_switch_cacheable_region(&cmd->src_y_addr, SrcYsize, PAGE_NO_CACHE);
    dynamic_switch_cacheable_region(&cmd->src_u_addr, SrcUVsize, PAGE_NO_CACHE);
    dynamic_switch_cacheable_region(&cmd->src_v_addr, SrcUVsize, PAGE_NO_CACHE);
   if ((KAL_TRUE == is_predef_dyna_c_region(cmd->tar_rgb_addr, rgbSize)) && (0 == ((cmd->tar_rgb_addr) %32))) 
   {
    dynamic_switch_cacheable_region(&cmd->tar_rgb_addr, rgbSize, PAGE_NO_CACHE);
   }
#endif //#if defined(IDP_SW_YUV_2_RGB_DITHERING__DYNAMIC_SWITCH_CACHEABLE)
}
    // callback // unecessary to be protected by semaphore...
    cmd->cbfxn_dithering_done();
#endif // #if defined(CONTOUR_IMPROVEMENT_MT6235) || defined(CONTOUR_IMPROVEMENT_MT6253)
    return;
}



