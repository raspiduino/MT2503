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
 * GPSMgrAGPSCP.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 * GPS manager for AGPS control plane header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __GPSMGRAGPSCP_H__
#define __GPSMGRAGPSCP_H__

#if defined(__AGPS_CONTROL_PLANE__)
#include "MMIDataType.h"
#include "mmi_msg_struct.h"
#include "GPSMgrProt.h"
#include "kal_general_types.h"
#include "mdi_gps.h"

#define MAX_MTLR_LN_REQ_NUM 5
#define MAX_MTLR_AE_REQ_NUM 5
#define MAX_MOLR_REQ_NUM    5

#define MMI_GPS_MGR_MTLR_NOTIFY_DELAY  20000
#define MMI_GPS_MGR_MTLR_CONFIRM_DELAY  20000

#define GPS_MGR_MTLR_NOTIFY_TIMER_ID GPS_MGR_NOTIFY_TIMER_ID_5

#define MAX_PLMN_STRING_LEN 6

typedef enum
{
   MMI_GPS_MGR_DEFAULT_DCS        = 0x00,  /* GSM 7-bit */
   MMI_GPS_MGR_8BIT_DCS           = 0x04,  /* 8-bit */
   MMI_GPS_MGR_UCS2_DCS           = 0x08,  /* UCS2 */
   MMI_GPS_MGR_RESERVED_DCS       = 0x0c,  /* reserved alphabet,
                                        currently, MMI shall display "not support alphabet"
                                        or "cannot display" when receive dcs indicated this value */
   MMI_GPS_MGR_EXT_DCS            = 0x10  /* Special dcs for non-standard character,
                                       used by MMI and EMS */
}mmi_gps_mgr_dcs_enum;

typedef struct
{
    U16 req_id;
    mmi_ss_mtlr_begin_ind_struct    notify_info;
    mmi_agps_state_enum state;
    module_type src_mod;
    MMI_BOOL    is_used;
}mmi_gps_manager_mtlr_notify_struct;

typedef struct
{
    U16 req_id;
    mmi_ss_aerq_begin_ind_struct    area_info;
    U32 last_event_time;
    mmi_agps_state_enum state;
    module_type src_mod;
    MMI_BOOL    need_send_req;
    MMI_BOOL    is_used;
    MMI_BOOL    is_first;
}mmi_gps_manager_mtlr_ae_req_struct;

typedef struct
{
    U16 req_id;
    mmi_ss_molr_begin_req_struct    molr_info;
    mmi_agps_state_enum state;
    mdi_gps_uart_work_mode_enum gps_mode;
    void (*callback)(S32 type, void *buffer, U32 length);
    MMI_BOOL    is_send_location;
    MMI_BOOL    is_single;
    U32 delay;
    U32 last_send_time;
    module_type src_mod;
    MMI_BOOL    is_used;
    MMI_BOOL    is_first;
}mmi_gps_manager_molr_req_struct;

typedef struct
{
    U8   plmn[MAX_PLMN_STRING_LEN + 1];
    U8   lac[2];
}mmi_gps_manager_l4c_area_info_struct;

typedef struct
{
    /* mtlr location notification */
    mmi_gps_manager_mtlr_notify_struct  notify_list[MAX_MTLR_LN_REQ_NUM];
    MMI_BOOL is_time_out;
    U8 request_id[322]; /* (160 + 1) * 2 */
    U16 client_name[161]; /* (160 + 1) * 2 */
    U8 extrenal_address[42]; /* (20 + 1) * 2 */
    /* mtlr area event */
    U8 last_mtlr_ae_ref_num;
    mmi_gps_manager_mtlr_ae_req_struct  mtlr_ae_req_list[MAX_MTLR_AE_REQ_NUM];
    MMI_BOOL cur_mtlr_ae_req_result;
    U8 cur_mtlr_ae_req_index;
    mmi_gps_manager_l4c_area_info_struct last_area_info;
    mmi_gps_manager_l4c_area_info_struct cur_area_info;
    /* molr */
    mmi_gps_manager_molr_req_struct molr_req_list[MAX_MOLR_REQ_NUM];
    S32 port;
    MMI_BOOL is_pos;
    MMI_BOOL is_ready;
    MMI_BOOL need_cipher_key;
    MMI_BOOL emerge_call;
    U8 ss_id;
    U8 waiting_index;
    /* public */
    U16 cur_id;
    U16 mtlr_count;
    MMI_ID screen_group_gid;

    srv_gps_notify_callback app_callback;
    void *app_user_data;
}mmi_gps_manager_cp_context_struct;

#endif /* __AGPS_CONTROL_PLANE__ */

#endif /* __GPSMGRAGPSCP_H__ */


