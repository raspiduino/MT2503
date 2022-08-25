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

/*******************************************************************************
 * Filename:
 * ---------
 * EngineerModeTracer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the tracer for PS log
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_ENGINEER_MODE__) 

#include "MMIDataType.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "app_ltlcom.h"
#include "em_struct.h"
#include "ps_public_struct.h"


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
#if defined(__MMI_EM_NW_PREFER_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_NW_PREFER_RAT__ */

#ifdef __MMI_EM_NW_NETWORK_INFO__
extern void SendEmStartMsg(void);

extern void EngineerModeStartRes(void *inMsg);
extern void EngineerModeStartReq(U32 mod_id);
extern void EngineerModeStatusUpdate(U32 mod_id, U32 info_req);
extern void EngineerModeStatusIndHdlr(void *inMsg);
#endif /* __MMI_EM_NW_NETWORK_INFO__ */


#ifdef __MMI_EM_NW_NETWORK_INFO__

extern void mmi_em_nw_send_start_req(module_type mod_id);
extern MMI_BOOL em_nw_info_update_is_allowed_show(U8 event);
extern void mmi_em_parsing_data(void *info);
extern void mmi_em_show_screen(void);
extern void mmi_em_tracer_key_up(void);
extern void mmi_em_tracer_key_down(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_em_tracer_pen_down(mmi_pen_point_struct pos);
#endif 
extern void mmi_em_rr_process_logs(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr);
extern void mmi_em_rr_cell_select_logs_value(rr_em_cell_select_para_info_struct *rr_em_cell_select_para_info);
extern void mmi_em_rr_channel_descr_logs_value(rr_em_channel_descr_info_struct *rr_em_channel_descr_info);
extern void mmi_em_rr_ctrl_channel_descr_logs_value(rr_em_ctrl_channel_descr_info_struct *rr_em_ctrl_channel_descr_info);
extern void mmi_em_rr_rach_ctrl_para_info_logs_value(rr_em_rach_ctrl_para_info_struct *rr_em_rach_ctrl_para_info);
extern void mmi_em_rr_lai_info_logs_value(rr_em_lai_info_struct *rr_em_lai_info);
extern void mmi_em_rr_radio_link_counter_info_logs_value(rr_em_radio_link_counter_info_struct *rr_em_radio_link_counter_info);
extern void mmi_em_rr_measurement_report_info_logs_value(rr_em_measurement_report_info_struct *rr_em_measurement_report_info);
extern void mmi_em_display_screen_n(kal_uint8 screen_num);
extern void mmi_em_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b);

extern void mmi_em_display_line_n(U32 *text_pos, U8 *str);

extern U8 mmi_em_rr_measurement_report_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_measurement_report_info_logs_2(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_cell_select_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_channel_descr_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_ctrl_channel_descr_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_rach_ctrl_para_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_lai_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_radio_link_counter_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_c1_c2_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_c1_c2_logs_2(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_ca_list_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_ca_list_info_logs_2(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_plmn_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_gprs_general_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_si2q_mi_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_tbf_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern U8 mmi_em_rr_blk_info_logs(U8 screen_num, U8 **mmi_screen_text);

extern void mmi_em_rr_plmn_info_logs_value(mmrr_plmn_info_struct *rr_plmn_info);
extern void mmi_em_rr_gprs_general_info_logs_value(rr_em_gprs_general_info_struct *rr_em_gprs_general_info);
extern void mmi_em_rr_si2q_info_logs_value(rr_em_si2q_info_struct *rr_em_si2q_info);
extern void mmi_em_rr_mi_info_logs_value(rr_em_mi_info_struct *rr_em_mi_info);
extern void mmi_em_rr_tbf_info_logs_value(rr_em_tbf_status_struct *rr_em_tbf_info);
extern void mmi_em_rr_blk_info_logs_value(rr_em_blk_info_struct *rr_em_blk_info);

extern void mmi_em_rr_ca_list_info_logs_value(rr_em_ca_list_info_struct *rr_em_ca_list_info);
#endif /* __MMI_EM_NW_NETWORK_INFO__ */


#ifdef __MMI_EM_NW_CELL_LOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_CELL_LOCK__) */

#ifdef __MMI_EM_NW_BAND_SEL__
extern void EmNWBandSelGetBandReq(void);
extern void EmNWBandSelGetBandRsp(void *info);
extern void EmNWBandSelSetBandReq(void);
extern void EntryEmNWBandSelSetBandProgress(void);
extern void EmNwBandSelSetBandRsp(void *info);
#endif /* __MMI_EM_NW_BAND_SEL__ */

#ifdef __MMI_EM_NETWORK_SETTINGS__
extern void mmi_em_nw_menu_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_nw_menu_exit_event_hdlr(cui_menu_event_struct *evt);
extern void mmi_em_nw_menu_entry_event_hdlr(cui_menu_event_struct *evt);
#endif /* __MMI_EM_NETWORK_SETTINGS__ */
extern void mmi_em_misc_multi_media_menu_event_hdlr(cui_menu_event_struct *event);

#endif /* defined(__MMI_ENGINEER_MODE__) && defined(__EM_MODE__) */

