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
 * BTMMIHidd.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for HID-Device application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_MMI_HIDD_H
#define BT_MMI_HIDD_H

/* RHR ADD */
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BtcmSrvGprot.h"
/* RHR ADD end */
 
/***************************************************************************** 
* Macro
*****************************************************************************/
#define MMI_BTH_HIDD_LOG_STATE_TRANS(x) \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_HIDD_STATE_TRANS, g_hidd_cntx.state, x);

#define MMI_HID_LOG(x) \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, x);

#define MMI_HID_LOG1(x,x1) \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, x,x1);

#define MMI_HID_LOG2(x,x1,x2) \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, x,x1,x2);

#define MMI_BTH_HIDD_STATE_TRANS(x) \
            do { \
                MMI_BTH_HIDD_LOG_STATE_TRANS(x); \
                g_hidd_cntx.state = x; \
            } while (0);

#define HIDD_SAME_DEVICE(dev1,dev2)     (((dev1).lap == (dev2).lap) && \
                                         ((dev1).uap == (dev2).uap) && \
                                         ((dev1).nap == (dev2).nap))
#define HIDD_INVALID_DEVICE(dev)        (((dev).lap == 0) && \
                                         ((dev).uap == 0) && \
                                         ((dev).nap == 0))
#define MASK_UNPLUG             (0x01)
#define MASK_CONNECTED          (0x08)

#define HID_FLAG_ON(f)          (g_hidd_cntx.flags & f)
#define HID_FLAG_SET(f)         (g_hidd_cntx.flags |= f)
#define HID_FLAG_RESET(f)       (g_hidd_cntx.flags &= ~f)
                                         
#define HID_USER_CNF_TIMEOUT    (50*1000)

/***************************************************************************** 
* Definations
*****************************************************************************/
typedef U32 HIDResult;                                         
typedef enum {
    HID_RESULT_SUCCESS,
    HID_RESULT_FAIL,
    HID_RESULT_PENDING
} hid_result_enum;


#define MMI_BTH_HIDD_MAX_CONNECTION (1)
#define BT_HIDD_MAX_DEV_NAME_LEN    (80)
/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
    MMI_BTH_HIDD_STAT_IDLE,
    MMI_BTH_HIDD_STAT_ACTIVATED,
    MMI_BTH_HIDD_STAT_CONNECTED,

    MMI_BTH_HIDD_STAT_ACTIVATING,
    MMI_BTH_HIDD_STAT_DEACTIVATING,
    MMI_BTH_HIDD_STAT_CONNECTING,
    MMI_BTH_HIDD_STAT_DISCONNECTING,
    MMI_BTH_HIDD_STAT_AUTHORIZING,
    MMI_BTH_HIDD_STAT_WAITCONNECT,
    MMI_BTH_HIDD_STAT_CONNCANCEL,
    MMI_BTH_HIDD_STAT_DEACTCANCEL
} mmi_bth_hidd_state_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    /* Connection identification */
    MMI_BOOL active;
    U32 conn_id;
    U32 cmgr_id;
    srv_bt_cm_bt_addr bd_addr;
} mmi_hidd_conn_struct;

typedef struct
{
    U32 flags;
    mmi_bth_hidd_state_enum state;
    srv_bt_cm_bt_addr last_device;
    /* active connections */
    mmi_hidd_conn_struct conn;
    U8 hidd_dev_name[BT_HIDD_MAX_DEV_NAME_LEN];
} mmi_bth_hidd_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern mmi_bth_hidd_cntx_struct g_hidd_cntx;

/***************************************************************************** 
* Functions
*****************************************************************************/
static void mmi_hidd_activate_req(void);
static void mmi_hidd_deactivate_req(void);
static void mmi_hidd_disconnect_req(U32 conn_id);
static void mmi_hidd_authorize_rsp(srv_bt_cm_bt_addr *addr,U32 prof, U32 result);

extern void mmi_hidd_init_event_hdlr(void);
extern void mmi_hidd_activate_cnf_hdlr(void *msg);
extern void mmi_hidd_deactivate_cnf_hdlr(void *msg);
extern void mmi_hidd_connect_cnf_hdlr(void *msg);
extern void mmi_hidd_connect_ind_hdlr(void *msg);
extern void mmi_hidd_disconnect_cnf_hdlr(void *msg);
extern void mmi_hidd_disconnect_ind_hdlr(void *msg);
#if 1
extern void mmi_hidd_unplug_ind_hdlr(void *msg);
extern void mmi_hidd_interrupt_data_ind_hdlr(void *msg);
#endif
extern void mmi_hidd_authorize_ind_hdlr(void *msg);
extern void mmi_hidd_interrupt_data_cnf_hdlr(void *msg);
extern void mmi_bth_hidd_get_dev_name(U8 *name_buf);
extern HIDResult mmi_hidd_reject(void);
extern HIDResult mmi_hidd_disconnect(void);
extern HIDResult mmi_hidd_connect_last_dev(void);



#endif /* BT_MMI_HIDD_H */ /* end of BT_MMI_HIDD_H */

