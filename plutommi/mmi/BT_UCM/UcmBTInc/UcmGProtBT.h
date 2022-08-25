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
 *  UcmGProtBT.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM 3.0 UCM App's external interfaces
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_GPROT_BT_H
#define UCM_GPROT_BT_H

#include "MMI_features.h"
#ifdef __MMI_BT_CALL_SUPPORT__

/* Include files---------------------------------------------------------------------------- */
#ifndef _CUSTOM_EVENTS_NOTIFY_H
#include "custom_events_notify.h"
#endif
#include "UcmSrvGProt.h"

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "UcmBTSrvGprot.h"
#include "UcmGprot.h"

/* DEFINE------------------------------------------------------------------------------------ */
#ifdef __MMI_FTE_SUPPORT__

typedef enum
{
    MMI_UCM_BT_UNLOCK_STATE,
    MMI_UCM_BT_WTL_STATE, /* wait to lock */
    MMI_UCM_BT_LOCK_STATE,
    MMI_UCM_BT_AUTO_LOCK_STATE_TOTAL
}mmi_ucm_bt_auto_lock_state_enum;

typedef enum
{
    MMI_UCM_BT_AL_OUTGOING_EVENT,
    MMI_UCM_BT_AL_INCOMING_EVENT,
    MMI_UCM_BT_AL_RELEASE_EVENT,
    MMI_UCM_BT_AL_CONNECT_EVENT,
    MMI_UCM_BT_AL_UNLOCK_EVENT,
    MMI_UCM_BT_AL_WTL_TIMEOUT_EVENT, /* Wait to lock timeout*/
    MMI_UCM_BT_AL_EVENT_TOTAL
} mmi_ucm_bt_auto_lock_trigger_event_enum;

#define MMI_UCM_BT_FTE_AUTO_LOCK_TIMEOUT  (5000)

#endif /* __MMI_FTE_SUPPORT__ */

/* Make call parameter struct */
typedef struct
{
    srv_bt_cm_bt_addr dev_addr;
    U16 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN+1]; /* the dial number, SRV_UCM_MAX_NUM_URI_LEN + 1 , UCS2 number uri with null termination, this input parameter will be copied to another buffer, it won't be modified */
    mmi_ucm_after_make_call_callback after_make_call_callback;/* callback function pointer. This cb will be called in the following cases: 1. succeed to make call 2. fail to make call 3.user selects back */
    void* after_callback_user_data; /* data pointer for make_call_callback, caller can bypass needed info by using this argv */
    U16 phb_name[SRV_UCM_BT_MAX_DIS_NAME_FROM_APP+1];
} mmi_ucm_bt_make_call_para_struct;

/* API-------------------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_error_message
 * DESCRIPTION
 *  Error message API for applications which operations are not allowed during in-call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ucm_entry_error_message(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_bt_call_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ucm_init_bt_call_para(mmi_ucm_bt_make_call_para_struct* bt_para, mmi_ucm_make_call_para_struct* para);

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
extern MMI_STR_ID mmi_ucm_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type);

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_auto_lock_state_bt
 * DESCRIPTION
 *  get auto lock state
 * PARAMETERS
 *  void
 * RETURNS
 *  Auto lock state
 *****************************************************************************/
extern mmi_ucm_bt_auto_lock_state_enum mmi_ucm_get_auto_lock_state_bt(void);
#endif // __MMI_FTE_SUPPORT__

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
extern void mmi_ucm_redial_action_bt();
extern MMI_BOOL mmi_ucm_is_ucm_sg_bt(MMI_ID check_sg_id);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

#endif /*__MMI_BT_CALL_SUPPORT__*/

#endif /* UCM_GPROT_BT_H */ 

