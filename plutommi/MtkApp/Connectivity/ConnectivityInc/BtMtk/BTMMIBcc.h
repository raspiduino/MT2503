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
 * BTMMIBcc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for BTMMIBcc.c.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_BCC_H__
#define __BT_MMI_BCC_H__

#include "BtcmSrvGprot.h"
/*
#ifndef BT_MMI_CM_H
#error "BTMMICm.h should be included"
#endif
*/

/***************************************************************************** 
* Macro
*****************************************************************************/
#define MMI_BTH_BCC_LOG_STATE_TRANS(x)                                                        \
{                                                                                             \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BCC_STATE_TRANS, g_mmi_bth_bcc_cntx.state, x);\
}

#define MMI_BTH_BCC_STATE_TRANS(x)  \
{                                   \
    MMI_BTH_BCC_LOG_STATE_TRANS(x); \
    g_mmi_bth_bcc_cntx.state = x;   \
}

/***************************************************************************** 
* Definations
*****************************************************************************/
/* BCC bit-wise flag for modified bt setting */
#define MMI_BTH_BCC_HOST_NAME               0x00000001
#define MMI_BTH_BCC_DISCOVERABLE_MODE       0x00000002
/***************************************************************************** 
* Enum 
*****************************************************************************/
typedef enum
{
	MMI_BTH_BCC_STAT_IDLE,

    MMI_BTH_BCC_STAT_POWER_ON_SWITCHING,
    MMI_BTH_BCC_STAT_HOST_NAME_RESTORING,
    MMI_BTH_BCC_STAT_DISCOVERABLE_MODE_RESTORING,
    MMI_BTH_BCC_STAT_HOST_NAME_SETTING,
    MMI_BTH_BCC_STAT_DISCOVERABLE_MODE_SETTING
    
} mmi_bth_bcc_state_enum;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
	/* bcc state */
	mmi_bth_bcc_state_enum			state;

    /* native BT setting */
	U32 bt_setting_modified;
	U8 jsr_discoverable_mode;
	U8 discoverable_mode;
    U8 host_dev_name[SRV_BT_CM_BD_FNAME_LEN];

	/* preknown dev list */
	mmi_bt_bcc_dev_info_struct preknown_dev_list[SRV_BT_CM_MAX_PAIRED_DEVICE_LIST];
	
} mmi_bth_bcc_cntx_struct;

/***************************************************************************** 
* Functions
*****************************************************************************/
extern void mmi_bth_bcc_init_event_handler(void);

extern void mmi_bth_bcc_authorize_req_hdler(void *msg);
extern void mmi_bth_bcc_is_authorized_req_hdler(void *msg);
extern void mmi_bth_bcc_is_trusted_req_hdler(void *msg);
extern void mmi_bth_bcc_get_security_mode_req_hdler(void *msg);
extern void mmi_bth_bcc_get_preknown_device_count_req_hdler(void *msg);
extern void mmi_bth_bcc_get_preknown_device_req_hdler(void *msg);

extern void mmi_bth_bcc_power_on_req_hdler(void *msg);
extern void mmi_bth_bcc_restore_req_hdler(void *msg);
extern void mmi_bth_bcc_set_host_device_name_req_hdler(void *msg);
extern void mmi_bth_bcc_get_host_device_name_req_hdler(void *msg);
extern void mmi_bth_bcc_set_discoverable_mode_req_hdler(void *msg);
extern void mmi_bth_bcc_get_discoverable_mode_req_hdler(void *msg);
extern void mmi_bth_bcc_get_native_pwr_status_req_hdler(void *msg);

extern void mmi_bth_bcc_restore_cnf_hdler(mmi_bt_bcc_result_code result);
extern void mmi_bth_bcc_power_on_cnf_hdler(mmi_bt_bcc_result_code result);
extern void mmi_bth_bcc_set_host_device_name_cnf_hdler(mmi_bt_bcc_result_code result);
extern void mmi_bth_bcc_set_discoverable_mode_cnf_hdler(mmi_bt_bcc_result_code result);


#endif /* __BT_MMI_BCC_H__ */
