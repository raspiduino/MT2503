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
 *   npplg_av_util.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Provide utility functions
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NPPLG_AV_UTIL_H
#define NPPLG_AV_UTIL_H

#include "npplg_av_main.h"
#include "gdi_datatype.h"
#include "npplg_av_include.h"
#include "stack_config.h"
#include "mdi_datatype.h"
#include "stack_msgs.h"
#include "kal_general_types.h"


/************************************************************
 * Define
 ************************************************************/
#define NPPLG_AV_UTIL_SPACE 6

/* 99:59:59 */
#define NPPLG_AV_UTIL_TIME 359999

#define NPPLG_AV_UTIL_SEC_TO_MS 1000

#define NPPLG_AV_UTIL_HOUR_TO_SEC 3600

#define NPPLG_AV_UTIL_MIN_TO_SEC 60


/************************************************************
 * Global Function
 ************************************************************/
extern kal_wchar *npplg_av_util_gen_filename(kal_uint8 app_id,
                                             kal_uint32 instance_id,
                                             kal_int32 drive_letter,
                                             kal_char *url,
                                             kal_char *mime_type);
extern kal_uint8 *npplg_av_util_get_image(kal_uint8 type, kal_uint8 display, kal_bool pressed, kal_uint8 ctrl_num);
extern void npplg_av_util_compose_play_panel(npplg_av_instance_struct *plugin_data,
                                             kal_uint8 obj_type,
                                             const kal_uint8 *ctrl_array[],
                                             kal_uint8 play_panel_num,
                                             kal_uint8 support_ctrl_num);
extern void npplg_av_util_free_control_list(npplg_av_instance_struct *plugin_data);
extern void npplg_av_util_invalidate_rect(npplg_av_instance_struct *plugin_data, npplg_av_obj_control_struct *ctrl);
extern void npplg_av_util_draw_controls(npplg_av_instance_struct *plugin_data,
                                        gdi_handle paint_layer,
                                        npplg_av_rect_struct paint_area);
extern npplg_av_obj_control_struct *npplg_av_util_get_control(npplg_av_instance_struct *plugin_data, kal_uint8 ctrl_type);
extern void npplg_av_util_show_processing_image(npplg_av_instance_struct *plugin_data, kal_bool start_timer);
extern void npplg_av_util_update_play_control(npplg_av_instance_struct *plugin_data, kal_bool playing, kal_bool draw);
extern void npplg_av_util_disable_play_control(npplg_av_instance_struct *plugin_data, kal_bool draw);
extern void npplg_av_util_update_seek_control(npplg_av_instance_struct *plugin_data);
extern void npplg_av_util_calculate_play_time_for_seek(npplg_av_instance_struct *plugin_data,
                                                       kal_bool forward,
                                                       kal_int64 *next_play_time);
extern void npplg_av_util_update_play_time_for_seek(npplg_av_instance_struct *plugin_data,
                                                    kal_bool forward,
                                                    kal_int64 next_play_time);
extern void npplg_av_util_seek(npplg_av_instance_struct *plugin_data, kal_bool forward);
extern void npplg_av_util_send_launch_media_player_ind(npplg_av_instance_struct *plugin_data,
                                                       module_type src_module,
                                                       kal_uint8 player_type,
                                                       kal_bool rtsp);
extern void npplg_av_util_send_suspend_background_play_rsp(module_type dest_module, kal_uint8 app_id, kal_int32 result);
extern void npplg_av_util_send_resume_background_play_ind(module_type src_module, kal_uint8 obj_type, kal_bool resume_bgplay);
extern void npplg_av_util_send_mmi_resume_ind(module_type dest_module,
                                              kal_uint32 instance_id,
                                              kal_uint8 app_id,
                                              kal_uint8 state);
extern void npplg_av_util_send_auto_play_audio_ind(module_type dest_module, kal_uint8 app_id, kal_bool notify_app);
extern void npplg_av_util_send_reset_ind(module_type dest_module, kal_uint32 instance_id, kal_uint8 app_id);
extern void npplg_av_util_send_notify_mmi_ind(module_type src_module, kal_uint32 instance_id, kal_uint8 app_id, kal_uint8 action);
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern void npplg_av_util_send_create_vdo_layer_req(module_type src_module,
                                                    kal_uint32 instance_id,
                                                    kal_uint8 app_id,
                                                    npplg_av_rect_struct *rect,
                                                    gdi_color transparent_color);
extern void npplg_av_util_send_create_vdo_layer_rsp(module_type dest_module,
                                                    kal_uint8 app_id,
                                                    kal_uint32 instance_id,
                                                    kal_int32 result,
                                                    gdi_handle layer_handle,
                                                    kal_uint32 blt_layer_flag,
                                                    kal_uint32 hw_layer_flag);
extern void npplg_av_util_send_free_vdo_layer_ind(module_type src_module, kal_uint8 app_id, kal_uint32 instance_id);
extern void npplg_av_util_send_update_vdo_layer_ind(module_type src_module,
                                                    kal_uint8 app_id,
                                                    kal_uint32 instance_id,
                                                    npplg_av_rect_struct *rect,
                                                    gdi_color transparent_color);
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */
extern kal_wchar *npplg_av_util_cvt_utf8_to_ucs2(const kal_char* utf8_str, kal_uint8 app_id);
extern kal_uint8 *npplg_av_util_cvt_ucs2_to_utf8(const kal_char* ucs2_str, kal_uint8 app_id);
extern void npplg_av_util_display_mdi_error_popup(MDI_RESULT result, npplg_av_instance_struct *plugin_data);
extern void npplg_av_util_init_mutex_lock(void);
extern void npplg_av_util_mutex_lock(kal_char *file, kal_uint32 line);
extern void npplg_av_util_mutex_unlock(kal_char *file, kal_uint32 line);
extern void npplg_av_util_send_ilm(module_type src_mod,
                                   module_type dest_mod,
                                   msg_type msg_id,
                                   void *local_para_ptr,
                                   void *peer_buff_ptr);


/************************************************************
 * Typedef
 ************************************************************/
#define NPPLG_AV_LOCK npplg_av_util_mutex_lock(__FILE__, __LINE__)
#define NPPLG_AV_UNLOCK npplg_av_util_mutex_unlock(__FILE__, __LINE__)

#endif /* NPPLG_AV_UTIL_H */
