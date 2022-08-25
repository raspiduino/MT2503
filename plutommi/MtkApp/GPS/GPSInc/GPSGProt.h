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
 *  GPSGProt.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *  GPS Exported APIs
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
 *============================================================================
 ****************************************************************************/
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)

#ifndef _GPSGPROT_H_
#define _GPSGPROT_H_

#include "MMIDataType.h"
#include "mmi_msg_struct.h"
#include "kal_general_types.h"
#include "GPSMgrGProt.h"
#include "mdi_gps.h"
#if defined(__AGPS_USER_PLANE__)
#include "supl2mmi_struct.h"
#endif

/* public location button, for NI/MTLR */
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    #define __ALLOW_FORBIDDEN_MY_LOCATION__
#endif

typedef enum
{
    MMI_GPS_SETTING_PREFER_SIM_NO1 = 0,
    MMI_GPS_SETTING_PREFER_SIM_NO2,
    MMI_GPS_SETTING_PREFER_SIM_NO3,
    MMI_GPS_SETTING_PREFER_SIM_NO4,
    MMI_GPS_SETTING_PREFER_SIM_NO5,
    MMI_GPS_SETTING_PERFER_SIM_END,
    MMI_GPS_SETTING_PREFER_SIM_ALWAYS_ASK
} mmi_gps_setting_prefer_sim_enum;

#if defined(__AGPS_USER_PLANE__)
#define MMI_GPS_MGR_NOTIFY_DELAY  20000
#define MMI_GPS_MGR_COMFIRM_DELAY  20000

typedef enum
{
    MMI_GPS_WORK_MODE_MA,
    MMI_GPS_WORK_MODE_MB,
    MMI_GPS_WORK_MODE_NORMAL,
    MMI_GPS_WORK_NO_WORK,
    MMI_GPS_WORK_MODE_END
} mmi_gps_work_mode_enum;
#endif

typedef enum
{
    EM_GPS_UP_PAYLOAD_BOTH = 0,
    EM_GPS_UP_PAYLOAD_RRLP,
    EM_GPS_UP_PAYLOAD_RRC,
    EM_GPS_UP_PAYLOAD_END
} mmi_em_gps_up_payload_enum;

typedef enum
{
    MMI_GPS_RECEIVER_OFF = 0,
    MMI_GPS_RECEIVER_YES = 1,
    MMI_GPS_RECEIVER_EXTERNAL,
    MMI_GPS_RECEIVER_END
} mmi_gps_receiver_enum;

typedef enum
{
    MMI_GPS_SRV_NOTIFY_TYPE_POPUP = 0,
    MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM,
    MMI_GPS_SRV_NOTIFY_TYPE_CLOSE_UI,
    MMI_GPS_SRV_NOTIFY_TYPE_END
} mmi_gps_srv_notify_type_enum;

typedef enum
{
    MMI_GPS_SRV_NOTIFY_OWNER_UP = 0,
    MMI_GPS_SRV_NOTIFY_OWNER_CP
} mmi_gps_srv_notify_owner_enum;

typedef struct
{
    mmi_gps_srv_notify_type_enum type;
    U32 id;
    mmi_gps_srv_notify_owner_enum owner;
    WCHAR *notify_p;
} mmi_gps_srv_notify_type_struct;

typedef void (*mmi_gps_setting_dataaccount_cb)(U32 dataacout,S32 err_code, void *user_data);
typedef void (*srv_gps_notify_callback)(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data);

extern mmi_ret InitGPSSetting(mmi_event_struct *evt);
extern mmi_ret mmi_gps_mgr_init(mmi_event_struct *evt);

#if defined(__AGPS_CONTROL_PLANE__)
extern S32 mmi_gps_mgr_stop_mtlr_area_event_request(void);
extern S32 mmi_gps_mgr_start_molr(
    mmi_ss_molr_begin_req_struct *molr_info,
    mdi_gps_uart_work_mode_enum gps_mode,
    U16* req_id,
    void (*callback)(S32 type, void *buffer, U32 length));
extern S32 mmi_gps_mgr_stop_molr(U16 req_id);
extern S32 mmi_gps_mgr_start_send_location(
    mmi_ss_molr_begin_req_struct * molr_info,
    U16* req_id,
    MMI_BOOL is_single,
    U32 delay,
    void (*callback)(S32 type, void *buffer, U32 length));
extern S32 mmi_gps_mgr_stop_send_location (U16 req_id);
#endif

#if defined(__AGPS_USER_PLANE__)
extern void mmi_gps_mgr_da_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, CHAR* url, CHAR* mime_type_string);

extern S32 mmi_gps_mgr_close_gps(
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length));
extern S32 mmi_gps_mgr_open_gps(
    U16 port,
    mdi_gps_uart_work_mode_enum gps_mode,
    mmi_gps_work_mode_enum work_mode,
    supl_mmi_qop_struct *qop,
    void (*gps_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length));
extern MMI_BOOL mmi_gps_mgr_is_agps_working(void);
extern void mmi_gps_mgr_register_notify_function(srv_gps_notify_callback func,void* user_data);
extern void mmi_gps_mgr_notify_result(MMI_BOOL is_enable, U32 id);

#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
extern MMI_BOOL mmi_gps_check_if_can_use_agps(void);
#endif

#if defined(__AGPS_CONTROL_PLANE__)
extern U8 mmi_gps_setting_get_mtlr(void);
extern U8 mmi_gps_get_send_location_setting(void);
MMI_BOOL mmi_gps_mgr_cp_is_ongoing(void);
extern void mmi_gps_mgr_cp_register_notify_function(srv_gps_notify_callback func, void* user_data);
extern void mmi_gps_mgr_exit_mtlr_notify_src(void);
    #ifdef __COSMOS_MMI__
        extern void vapp_gps_mgr_cp_notify_timeout(void);
        extern void mmi_gps_mgr_mtlr_notify_accept(void);
        extern void mmi_gps_mgr_mtlr_notify_decline(void);
        extern void mmi_gps_mgr_exit_mtlr_notify_src(void);
    #endif
#endif

extern U8 mmi_gps_get_receiver_setting(void);
#if defined(__MMI_SPP_SUPPORT__) && defined(__BT_GPS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern MMI_BOOL mmi_gps_setting_get_time_sync(void);
extern U32 mmi_gps_setting_get_data_account(U8 sim);


#ifdef __COSMOS_MMI__
extern void vapp_gps_mgr_notify_init(void);
extern void vapp_gps_mgr_notify_timeout(void);
extern void mmi_gps_mgr_notify_accept(void);
extern void mmi_gps_mgr_notify_decline(void);
extern void mmi_gps_mgr_exit_notify_src(void);
#endif


#endif /* _GPSGPROT_H */

#endif /* __GPS_SUPPORT__ || __BT_GPS_SUPPORT__ */

