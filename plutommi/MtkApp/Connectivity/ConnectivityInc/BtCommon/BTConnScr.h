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
 * BTConnCfg.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of btmmiscr.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_CONN_SCR_H__
#define __BT_CONN_SCR_H__

#include "MMI_features.h"
#include "BtcmSrvGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProcedureGprot.h"
#include "BtConnCfg.h"


#ifdef __MMI_BT_DIALER_SUPPORT__
#ifndef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
#define __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
extern void mmi_bt_dialer_show_popup(mmi_id group_id);
extern void mmi_bt_dialer_disconnect_notify(mmi_id group_id);
extern void mmi_bt_dialer_auto_connect(mmi_id group_id);
extern void mmi_bt_entry_main_menu_bt_dialer(void);
extern void mmi_bt_dialor_disconnect(srv_bt_cm_bt_addr* dev_addr);
extern void mmi_bt_dialor_connect(srv_bt_cm_bt_addr* dev_addr);
extern mmi_ret mmi_bt_entry_dialor_mydev_opt_group_proc(mmi_event_struct* evt);
extern void mmi_bt_show_dialor_help(srv_bt_cm_dev_struct *dev_p);
extern S32 mmi_bt_dialer_get_menu_num(void);
typedef  void (*BT_DAILER_CALLBACK)(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
extern MMI_BOOL mmi_bt_dialer_app_is_connected();
MMI_BOOL mmi_bt_dialer_app_is_connected_ex(srv_bt_cm_bt_addr* dev_addr);
void mmi_bt_dialer_conn_profile(srv_bt_cm_bt_addr *dev_addr, MMI_ID prarent_id, srv_bt_cm_connection_type conn_type, BT_DAILER_CALLBACK callback);
extern void mmi_bt_dialer_cent(void);
extern void MMI_BT_SET_FLAG(U32 x);
extern void MMI_BT_RESET_FLAG(U32 x);
MMI_BOOL mmi_bt_dialer_get_cent_flag(void);
void mmi_bt_dialer_set_cent_flag(MMI_BOOL flag);
void mmi_bt_dialer_conn_profile_end(srv_bt_cm_connection_type conn_type);
mmi_frm_proc_result_enum mmi_bt_dialer_shutdown(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
U32 mmi_bt_dialer_get_connecting_flag(void);
void mmi_bt_dialer_connect_time_out_hdlr(void *msg_ptr);
void mmi_bt_dialer_app_emit_event(U32 event_id, void* event_info, MMI_BOOL is_all_dis);
void mmi_bt_entry_connecting_time_out_hdlr(void);
void mmi_bt_dialer_enhanced_init();
MMI_BOOL mmi_bt_dialer_get_headset_flag();
void mmi_bt_dialer_set_headset_flag(MMI_BOOL flag);
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
#define MMI_BT_DIALER_AUTO_RECONN_DURATION  (60*1000);	/*auto reconnection duration: 60seconds*/
#define MMI_BT_DIALER_AUTO_RECONN_FREQ  (10*1000);		/*auto reconnection frequency: 10seconds*/
void mmi_bt_dialer_auto_reconn_and_to_ind(void* para);
void mmi_bt_dialer_auto_reconn_reset(void);
#endif
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
#define MMI_BT_ANTI_LOST_ALARM_DURATION (60*1000)
#ifdef __MMI_BT_BTBOX_NOLCD__
#define MMI_BT_ANTI_LOST_NOTIFY_INTERVAL (5000)
#define MMI_BT_ANTI_LOST_NOTIFY_TIMES (5)
#endif /* __MMI_BT_BTBOX_NOLCD__ */
void mmi_bt_anti_lost_clean_addr(srv_bt_cm_bt_addr* dev_addr1);
void mmi_bt_anti_lost_read_rssi_req(srv_bt_cm_bt_addr *bt_addr);
void mmi_bt_anti_lost_enable_req(srv_bt_cm_bt_addr *bt_addr, MMI_BOOL enbale);
void mmi_bt_anti_lost_add_addr(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr);
MMI_BOOL mmi_bt_anti_lost_is_in_list(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr);
void mmi_bt_anti_lost_close_scr(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr);
typedef struct 
{
	LOCAL_PARA_HDR
	S8 threshold;
    S8 rssi_value;
    U32 lap;
    U8  uap;
    U16 nap;
}mmi_bt_anti_lost_ind_data_struct;
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */

void mmi_bt_dialer_diconn_dev_func(srv_bt_cm_bt_addr* dev_addr);
void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
void mmi_bt_dialer_set_all_disconn_flag(MMI_BOOL is_all_disconn);
MMI_BOOL mmi_bt_dialer_get_all_disconn_flag(void);
void mmi_bt_dialer_conn_dev_by_addr(srv_bt_cm_dev_struct dev_info);
mmi_id cui_bt_dialer_connecting_create(mmi_id parent_gid);
mmi_ret cui_bt_dialer_connecting_run(mmi_id cui_id);
void cui_bt_dialer_connecting_close(mmi_id cui_gid);
mmi_ret cui_bt_dialer_connecting_proc(mmi_event_struct *evt);
void* mmi_bt_get_device_image(U32 cod);
MMI_BOOL mmi_bt_dialer_disconnect_by_dev_info(srv_bt_cm_dev_struct* dev_p);
void mmi_bt_dialer_conn_set_vis_state(void);
MMI_BOOL mmi_bt_dialer_is_addr_equal_0(const srv_bt_cm_bt_addr* dev_addr);

#ifdef __MMI_A2DP_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__

void mmi_bt_dialer_connect_a2dp_src(srv_bt_cm_bt_addr *dev_addr, mmi_id group_id);

#endif
#endif
#define BT_DEVICE_LINK_NUM  __BT_MAX_LINK_NUM__
typedef enum
{
    MMI_BT_CONN_NONE = 0,
    MMI_BT_CONN_ACTIVE , 
    MMI_BT_CONN_PASSIVE,
    MMI_BT_CONN_DONE,
    MMI_BT_CONN_TOTAL
    
} MMI_BT_CONN_VIS;
void mmi_bt_dialer_set_time_out_flag(MMI_BOOL time_out_flag);

#ifdef __MMI_BT_BTBOX_NOLCD__
extern U32 mmi_bt_dialer_get_reconn_item(void);
extern void mmi_bt_dialer_auto_reconn_restart(void);
#endif /* __MMI_BT_BTBOX_NOLCD__ */

#endif
#endif /* __BT_CONN_SCR_H__ */ 


/*------------------------------------------------------------*/
/*-------------------end--------------------------------------*/
/*------------------------------------------------------------*/

