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
 *    idp_sw_yuv420_2_uyvy422_resizer.c
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
 * 11 04 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 07 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 06 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 01 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 20 2011 hung-wen.hsieh
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
 * 07 28 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 27 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 07 01 2011 hung-wen.hsieh
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
 * 05 19 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 03 23 2011 hung-wen.hsieh
 * removed!
 * Remove MED_C related message.
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 29 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 25 2010 hung-wen.hsieh
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


/****************************************************************************
 * macro definitions
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/**
 * \def IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE
 * This macro enables idp_sw_yuv420_2_uyvy422_resizer to use dynamic switchable input/output buffers
 * when doing dithering to boost performance.
 */
#if defined(__MTK_TARGET__)
#define IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE
//#define VA2_VR_VP_6235_ENABLE_SWLA_TRACE
#endif
/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "drv_features_mdp.h"
#include "kal_public_api.h"

#include "sw_video_resizer.h"



#if defined(DRV_IDP_6235_SERIES) /* For MT6225 and MT6235 */
#if defined(MT6235) || defined(MT6235B)

#include "cache_sw.h"
#include "mmu.h"

#include "idp_sw_yuv420_2_uyvy422_resizer.h"
#include "iul_csc_y2r_565.h"
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
#include "SST_sla.h"
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    _idp_sw_resizer_cmd_t           cmd;
}_idp_sw_resizer_ilm_local_param_t;


/****************************************************************************
 * local variables
 ****************************************************************************/

/****************************************************************************
 * utilities
 ****************************************************************************/
// TODO:W1045 Code Review:a new file:sw_yuv_2_rgb_resizer.c
kal_bool
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
    void *cbparam_sw_resizer_done)
{
    _idp_sw_resizer_cmd_t cmd;
    
    ASSERT(0 != src_w);
    ASSERT(0 != src_h);
    ASSERT(0 != src_y_addr);
    ASSERT(0 != src_u_addr);
    ASSERT(0 != src_v_addr);
    ASSERT(0 != tar_rgb_addr);
    ASSERT(NULL != cbfxn_sw_resizer_done);

    {
        kal_uint32 const save_irq_mask = SaveAndSetIRQMask();
        cmd.nCmd = nCmd;
        cmd.src_width = src_w;
        cmd.src_height = src_h;
        cmd.bClip = bClip;
        cmd.clip_offset_x1 = clip_offset_x1;
        cmd.clip_offset_y1 = clip_offset_y1;
        cmd.clip_offset_x2 = clip_offset_x2;
        cmd.clip_offset_y2 = clip_offset_y2;
        cmd.tar_width = tar_w;
        cmd.tar_height = tar_h;        
        cmd.src_y_addr = src_y_addr;
        cmd.src_u_addr = src_u_addr;
        cmd.src_v_addr = src_v_addr;
        cmd.tar_rgb_addr = tar_rgb_addr;
        cmd.sw_resizer_workingbuf_addr = sw_resizer_workingbuf_addr;
        cmd.sw_resizer_workingbuf_size = sw_resizer_workingbuf_size;        
        cmd.tar_offset = tar_offset;
        cmd.cbfxn_sw_resizer_done= cbfxn_sw_resizer_done;
        cmd.cbparam_sw_resizer_done= cbparam_sw_resizer_done;
        RestoreIRQMask(save_irq_mask);
    }
    {
        _idp_sw_resizer_ilm_local_param_t *ilm_param;
        ilm_struct *p_ilm = NULL;
        module_type eActiveModuleId = stack_get_active_module_id();
        ilm_param = (_idp_sw_resizer_ilm_local_param_t*) 
                        construct_local_para(sizeof(_idp_sw_resizer_ilm_local_param_t), TD_CTRL);
        ASSERT(NULL != ilm_param);

        kal_mem_cpy((void*) &(ilm_param->cmd), (const void*) &cmd, sizeof(_idp_sw_resizer_cmd_t));

        //p_ilm = allocate_ilm(MOD_VISUAL_HISR);
        p_ilm = allocate_ilm(eActiveModuleId);
        ASSERT(NULL != p_ilm);
        
        //p_ilm->src_mod_id = MOD_VISUAL_HISR;
#if (defined(ISP_SUPPORT))
        p_ilm->src_mod_id = eActiveModuleId;
        p_ilm->dest_mod_id = MOD_CAL;
        p_ilm->sap_id = CAL_SAP;
        p_ilm->msg_id = (msg_type) MSG_ID_CAL_SW_RESIZER_START_REQ;
        p_ilm->local_para_ptr = (local_para_struct*) ilm_param;
        p_ilm->peer_buff_ptr = NULL;

        msg_send_ext_queue(p_ilm);
#endif //#if (defined(ISP_SUPPORT))
    }
    return KAL_TRUE;
}

/****************************************************************************
 * utilities
 ****************************************************************************/

// TODO:W1045 Code Review: Discuss new adaptor between IDP and MED_C, CT & CM & Po.

void
idp_sw_resizer_start_req_hdlr(
    ilm_struct *ilm_msg)
{
#if defined(MT6235) || defined(MT6235B)
    _idp_sw_resizer_ilm_local_param_t *local_para_ptr = NULL;
    _idp_sw_resizer_cmd_t *cmd = NULL;
    SW_VIDEO_RESIZER_CONFIG_STRUCT  sw_video_resizer_cfg;
    SW_VIDEO_RESIZER_PUT_STRUCT     video_put;
    
    kal_uint32 SrcPitch;
    kal_uint32 SrcYsize;
    kal_uint32 SrcUVsize;
    kal_uint32 rgbSize;
    kal_uint32 resizer_workingsize;
    kal_uint32 sw_resizer_working_buf_tmp;
    kal_uint32 outputY,outputU,outputV;    

    ASSERT(NULL != ilm_msg);

    ASSERT(KAL_FALSE == kal_if_hisr());
    ASSERT(KAL_FALSE == kal_if_lisr());

    // get ilm parameters
    local_para_ptr = (_idp_sw_resizer_ilm_local_param_t*) ilm_msg->local_para_ptr;
    ASSERT(NULL != local_para_ptr);
    cmd = (_idp_sw_resizer_cmd_t*) &(local_para_ptr->cmd);
    ASSERT(NULL != cmd);

     // start resizer YUV420 to RGB565
    if (IDP_REQUIRE_TASK_DO_SW_RESIZER == cmd->nCmd)
    {
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
        SLA_CustomLogging("RES", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

        rgbSize = cmd->sw_resizer_workingbuf_size;
        kal_mem_set(&sw_video_resizer_cfg,0x0,sizeof(sw_video_resizer_cfg));
        kal_mem_set(&video_put,0x0,sizeof(SW_VIDEO_RESIZER_PUT_STRUCT));
            
#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
        dynamic_switch_cacheable_region(&cmd->tar_rgb_addr, rgbSize, PAGE_CACHEABLE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
        video_put.input_buffer[0] =(kal_uint8*) cmd->src_y_addr;
        video_put.input_buffer[1] =(kal_uint8*) cmd->src_u_addr;
        video_put.input_buffer[2] =(kal_uint8*) cmd->src_v_addr;
        video_put.output_buffer[0] = (kal_uint8*) ((cmd->tar_rgb_addr)+cmd->sw_resizer_workingbuf_addr);
    
        sw_video_resizer_cfg.u4SrcClipX1 = cmd->clip_offset_x1;
        sw_video_resizer_cfg.u4SrcClipY1 = cmd->clip_offset_y1;
        sw_video_resizer_cfg.u4SrcClipX2 = cmd->clip_offset_x2;
        sw_video_resizer_cfg.u4SrcClipY2 = cmd->clip_offset_y2;

        sw_video_resizer_cfg.src_width  = cmd->src_width;
        sw_video_resizer_cfg.src_height = cmd->src_height;
        sw_video_resizer_cfg.tar_width  = cmd->tar_width;
        sw_video_resizer_cfg.tar_height = cmd->tar_height;    
        sw_video_resizer_cfg.tar_offset  = cmd->tar_offset;

        sw_video_resizer_cfg.input_buff_width[0] = cmd->src_width;
        sw_video_resizer_cfg.input_buff_width[1] = (cmd->src_width >> 1);
        sw_video_resizer_cfg.input_buff_width[2] = (cmd->src_width >> 1);
    
        if(sw_video_resizer_init(&sw_video_resizer_cfg) != SW_VIDEO_RESIZER_SUCCESS)
        {
          ASSERT(0);
        } 
    
        //Starting the resize!!!!!!!!!!!!!!!!!!!!!    
        sw_video_resizer_put_data(&video_put,&sw_video_resizer_cfg);
        //Done..................................................................//
    
    #if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)   
        dynamic_switch_cacheable_region(&cmd->tar_rgb_addr, rgbSize, PAGE_NO_CACHE);
    #endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
       sw_video_resizer_deinit();
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("RES", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

       cmd->cbfxn_sw_resizer_done(NULL);

    }
    else if (IDP_REQUIRE_TASK_DO_COLOR_FORMAT_TRANSMFOM == cmd->nCmd)
    {
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFB", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
       dynamic_switch_cacheable_region(&cmd->sw_resizer_workingbuf_addr, cmd->sw_resizer_workingbuf_size, PAGE_CACHEABLE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)

       video_put.input_buffer[0] =(kal_uint8*) cmd->src_y_addr;
       video_put.input_buffer[1] =(kal_uint8*) cmd->src_u_addr;
       video_put.input_buffer[2] =(kal_uint8*) cmd->src_v_addr;
     
       video_put.output_buffer[0] = (kal_uint8*) (cmd->sw_resizer_workingbuf_addr);
       sw_video_resizer_cfg.u4SrcClipX1 = cmd->clip_offset_x1;
       sw_video_resizer_cfg.u4SrcClipY1 = cmd->clip_offset_y1;
       sw_video_resizer_cfg.u4SrcClipX2 = cmd->clip_offset_x2;
       sw_video_resizer_cfg.u4SrcClipY2 = cmd->clip_offset_y2;
       
       sw_video_resizer_cfg.src_width  = cmd->src_width;
       sw_video_resizer_cfg.src_height = cmd->src_height;
       sw_video_resizer_cfg.tar_width  = cmd->tar_width;
       sw_video_resizer_cfg.tar_height = cmd->tar_height;    
       sw_video_resizer_cfg.tar_offset  = cmd->tar_offset;

       sw_video_resizer_cfg.input_buff_width[0] = cmd->src_width;
       sw_video_resizer_cfg.input_buff_width[1] = (cmd->src_width >> 1);
       sw_video_resizer_cfg.input_buff_width[2] = (cmd->src_width >> 1);
       if(sw_video_resizer_init(&sw_video_resizer_cfg) != SW_VIDEO_RESIZER_SUCCESS)
       {
         ASSERT(0);
       } 
#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFB", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFT", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE) 
       sw_video_yuv420_pack_uyvy422(&video_put,&sw_video_resizer_cfg);

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFT", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFA", 1);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
    
#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)   
       dynamic_switch_cacheable_region(&cmd->sw_resizer_workingbuf_addr, cmd->sw_resizer_workingbuf_size, PAGE_NO_CACHE);
#endif //#if defined(IDP_SW_YUV420_2_UYVY422_RESIZER__DYNAMIC_SWITCH_CACHEABLE)
       sw_video_resizer_deinit();

#if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)
       SLA_CustomLogging("CFA", 0);
#endif  // #if defined(VA2_VR_VP_6235_ENABLE_SWLA_TRACE)

       cmd->cbfxn_sw_resizer_done(NULL);

    }
    else if (IDP_REQUIRE_TASK_DO_TOUCH_FROM_INSIDE_PITCH == cmd->nCmd)
    {
       cmd->cbfxn_sw_resizer_done(cmd->cbparam_sw_resizer_done);
    }
    else
    {
      ASSERT(0);
    }
#endif //defined(MT6235) || defined(MT6235B)
    return;
}
#endif //defined(MT6235) || defined(MT6235B)
#endif //defined(DRV_IDP_6235_SERIES)



