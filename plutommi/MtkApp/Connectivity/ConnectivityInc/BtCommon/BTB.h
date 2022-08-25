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
 * BTB.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of BTB
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

#include "mmi_features.h"

#ifdef __MMI_BT_BTBOX_NOLCD__

#include "BtcmSrvGprot.h"


#define BTB_INQUIRY_COD (SRV_BT_AUDIO_MAJOR_SERVICE_MASK|SRV_BT_AUDIO_MAJOR_SERVICE_MASK|SRV_BT_TELEPHONY_MAJOR_SERVICE_MASK)

#define BTB_INQUIRY_TIMEOUT_DURATION      (80)      /* 80 sec */




typedef enum
{
    BTB_STATE_IDLE,
    BTB_STATE_ACTIVE_CONNECTING,
    BTB_STATE_PASSIVE_CONNECTING,
    BTB_STATE_ACTIVE_DISCONNECTING,
    BTB_STATE_PASSIVE_DISCONNECTING,
    BTB_STATE_RECONNECTING,
    BTB_STATE_RESETTING
} btb_state_enum;

typedef struct
{
    mmi_bt_dialer_conn_callback_item callback_item;
    srv_bt_cm_bt_addr bd_addr;
    MMI_BOOL result;
    MMI_BOOL is_connect;
} btb_opt_after_set_visibility_struct;

typedef struct
{
    MMI_BOOL reset_by_linein;
    MMI_BOOL hf_connect;
    MMI_BOOL a2dp_connect;
    MMI_BOOL avrcp_connect;
    MMI_BOOL hf_disconnect;
    MMI_BOOL a2dp_disconnect;
    MMI_BOOL avrcp_disconnect;
    btb_state_enum state;
    S32 handle;
    btb_opt_after_set_visibility_struct opt_after_set_visibility;
} btb_context_struct;


#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__

typedef struct
{
    MMI_BOOL bt_dialer_reconn_flag;
    S32 bt_dialer_reconn_accu_time;
    U32 bt_dialer_reconn_duration;
    U32 bt_dialer_reconn_freq;      /* for confirm exit func or progress rsk func */
    srv_bt_cm_bt_addr bd_addr;
    //srv_bt_cm_bt_addr bd_pconn_addr;
} mmi_bt_reconn_ctx_struct;

#endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__

typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL headset_flag;
} mmi_bt_conn_headset_struct;


extern void btb_init(void);
extern void btb_deinit(void);
extern void btb_event_notify_handle(U32 event, void* para);
extern MMI_BOOL btb_is_available(MMI_BOOL need_check_btb_state, MMI_BOOL need_check_bt_state, MMI_BOOL need_check_line_in);
extern mmi_ret btb_event_hdlr(mmi_event_struct *event);
#endif  //__MMI_BT_BTBOX_NOLCD__

