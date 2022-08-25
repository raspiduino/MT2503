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
 * BTMMISend.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_SEND_H__
#define __BT_MMI_SEND_H__

#include "MMI_features.h"
#include "BtcmSrvGprot.h"
/* auto add by kw_check begin */
#include "OppSrvGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BTSendCUIGprot.h"
#include "FileMgrSrvGProt.h"
#include "bluetooth_struct.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
/* auto add by kw_check end */
/***************************************************************************** 
* Constant
*****************************************************************************/
#define BTSEND_MAX_INSTANCE         1
#define MAX_TBUFF_SIZE              128
#define OPP_PROG_UPD_DUR            1000
#define BUF_LENGTH                  OPPC_MAX_OBEX_PACKET_LENGTH
#define BT_SEND_DUMMY_TIMEOUT       5 /* shortest timeout, just for async operation */
#define BTCOMN_CNF_BUFF_SIZE        (62*ENCODING_LENGTH)
#define MMI_BT_OBEX_DUP_FILENAME_MAX_NUM  200

#define MMIBIP_MASK_CM_NOTIFY       0x00000001
#define MMIBIP_MASK_ABORT_PRESS     0x00000002
#define MMIBIP_MASK_CONTINUE_SND    0x00000004
#define MMIBIP_MASK_FILE_TYPE       0x00000008
#define MMIBIP_MASK_USB_PLUG_IND    0x00000010
#define MMIBIP_MASK_SENDING_DELE    0x00000020
#define MMIBIP_MASK_SEND_SUCC       0x00000040
#define MMIBIP_MASK_ENCODE_JPEG     0x00000080

#define MMIOPP_MASK_CM_NOTIFY       0x00000001
#define MMIOPP_MASK_MULTI_SEND      0x00000002
#define MMIOPP_MASK_ABORT_PRESS     0x00000004
#define MMIOPP_MASK_SDP_FORMAT      0x00000008
#define MMIOPP_MASK_FILE_TYPE       0x00000010
#define MMIOPP_MASK_USB_PLUG_IND    0x00000020
#define MMIOPP_MASK_SENDING_DELE    0x00000040
#define MMIOPP_MASK_SEND_SUCC       0x00000080
#define MMIOPP_MASK_ASMSTOP         0x00000100


/* Send result code */
typedef enum
{
    BTSEND_COD_SUCCESS,
    BTSEND_COD_FAIL,
    BTSEND_COD_INVALID_PARA,
    BTSEND_COD_SERV_NOT_AVAILABLE,
    BTSEND_COD_DEVICE_BLOCKED,
    BTSEND_COD_BAD_OBJECT,
    BTSEND_COD_USER_ABORT,
    BTSEND_COD_TIMEOUT,
    BTSEND_COD_REJECT,
    BTSEND_COD_DISCONNECT,
    BTSEND_COD_FORBIDDEN,
    BTSEND_COD_UNSUPPORT_FILE_TYPE,
    BTSEND_COD_DONE,
    BTSEND_COD_ABNORMAL_DONE,
    BTSEND_COD_DRM_PROHIB,
    BTSEND_COD_USB_UNAVAILABLE,
    BTSEND_COD_BUSY,
    BTSEND_COD_POWEROFF,
    BTSEND_COD_POWERON,
    BTSEND_COD_POWERFAIL,
    BTSEND_COD_PENDING
}btsend_ret_in_enum;

typedef enum
{
    BTSEND_PROF_OPP = 0x01,
    BTSEND_PROF_FTP = 0x02,
    BTSEND_PROF_BIP = 0x04,
    BTSEND_PROF_ALL = 0xFF
} btsend_prof_enum;

typedef enum
{
    BTSEND_PWR_OFF = 0x00,
    BTSEND_PWR_ON = 0x01,
    BTSEND_TO_DEFAULT = 0x04,
    BTSEND_TO_SELECT = 0x08,
} btsend_power_timing_enum;

typedef enum
{
    BTSEND_STATE_NULL,
    BTSEND_STATE_PREPARE,
    BTSEND_STATE_READY,
    BTSEND_STATE_SENDING,
    BTSEND_STATE_END
} btsend_state_enum;

typedef enum
{
    MMI_BIPI_PUSH_CONVERT_FAILED,
    MMI_BIPI_PUSH_PRECONDITION_FAILED,
    MMI_BIPI_PUSH_FAILED_LAST
}mmi_bipi_push_failed_reason_enum;

/* MMI notification type */
typedef enum
{
    MMI_OPP_NOTIFY_ABORT,
    MMI_OPP_NOTIFY_ACCEPT,
    MMI_OPP_NOTIFY_DETAIL,
    MMI_OPP_NOTIFY_RECV,
    MMI_OPP_NOTIFY_PERCENT,
    MMI_OPP_NOTIFY_CNT
} mmi_opp_notify_enum;


/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    U32 app;
    U32 lap;
    U8  uap;
    U16 nap;
    U8 prof;
} btsend_device_struct;

typedef void (*btsend_in_callback) (U32, void *, void *);
typedef MMI_BOOL (*prof_is_idle_func) (void);
typedef MMI_BOOL (*prof_check_obj_func) (void *);
typedef void (*prof_send_buff_func) (void);
typedef void (*prof_send_cancel_func) (void);
typedef void (*prof_send_scr_del_func) (void);
typedef U8 (*prof_send_caculate_persent_func)(void);


typedef struct 
{
    U16 ID;
    btsend_in_callback callback;
    void *user_data;
} btsend_app_in_struct;

typedef struct
{
    U8 mime_type;
    U16 mime_subtype;
    S8 * mime_string;
} btsend_objtype_in_struct;

typedef struct
{
    cui_bt_sending_obj_enum obj_type;
    union {
        struct {
            void* addr;
            U32 length;
        } buff;
        struct {
            U16 path[SRV_FMGR_PATH_MAX_LEN + 1];
            MMI_BOOL is_sfn;
        } file;
    } u;
} btsend_objdata_in_struct;

typedef struct
{
    U16 * name;
    btsend_objtype_in_struct type;
    btsend_objdata_in_struct data;
} btsend_obj_in_struct;

typedef struct
{
    U16 total;
    U16 sent;
    U16 cur_send_cnt;
    btsend_obj_in_struct *ptr;
    btsend_obj_in_struct store;
} btsend_obj_info_in_struct;

typedef struct 
{
    btsend_obj_info_in_struct obj;
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    btsend_device_struct def_dev;
#endif
    srv_bt_cm_bt_addr addr;
    mmi_id gid;
    mmi_id hd_dev;
    mmi_id hd_pwr;
    S32 reason;
    U8 prof;
    U8 option;
    U8 state;
    U8 flag;
} btsend_inst_struct;

typedef void (*prof_send_file_func) (btsend_inst_struct *inst);
typedef void (*prof_send_obj_func)(btsend_inst_struct *inst);

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} btsend_evt_continue;

typedef struct
{
    btsend_inst_struct inst;
    U8 flag;
    U8 launch_flag;                             /* to remember if has post SUCC event to caller for launch cui*/
} btsend_context_struct;

typedef struct
{
    U32 flag;
    MMI_BOOL disconn_from_cm;
    U8 *buffer;
    S32 srv_hd;
    btsend_inst_struct *inst;
} mmi_oppc_cntx_struct;

typedef struct
{
    /* for PUSH client */
    U32 flag;
    MMI_BOOL disconn_from_cm;
    U8 *buffer;
    S32 app_hd;
    bt_bip_service_enum cur_service;
    mmi_bipi_push_failed_reason_enum push_failed_reason;
#ifndef __MMI_USB_SUPPORT__
    MMI_BOOL entering_usb;
#endif
    btsend_inst_struct *inst;
}mmi_bipi_push_cntx_struct;

/***************************************************************************** 
* Other define
*****************************************************************************/
#ifdef __MMI_BT_DEF_SEND_DEVICE__
#define SEND_TO_DEFAULT()       (g_btsend_cntx.inst.flag & BTSEND_TO_DEFAULT)
#endif



#define MMI_OPPC_LOG(x) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);

#define MMI_OPPC_LOG1(x, x1) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);

#endif
