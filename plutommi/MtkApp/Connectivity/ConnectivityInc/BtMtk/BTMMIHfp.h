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
 * BTMMIHfp.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for HFP application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_MMI_HFP_H
#define BT_MMI_HFP_H

/* RHR ADD */
#include "MMIDataType.h"
#include "BTMMIHfpGprots.h"
#include "kal_general_types.h"
#include "BtAudioSrvGprot.h"
#include "BtcmSrvGprot.h"
/* RHR ADD end */
 
/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definations
*****************************************************************************/

#define FLAG_RELEASE            0x01

#define EVT_ID_ATTACH_RESULT    0x402
#define EVT_ID_AUDIO_RESULT     0x403
/***************************************************************************** 
* typedef 
*****************************************************************************/

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct {
    MMI_EVT_GROUP_PARAM_HEADER
    MMI_BOOL result;
} hfg_attach_event_struct;

typedef struct {
    U32 srv_hd;
    U32 flags;
    btaud_device_info dev_info;
    BtAudDevAddr pend_dev;
    MMI_ID gid;
    MMI_ID sid;
} mmi_btaud_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/
static S32 btaud_notify_hdlr(U32 event, U32 arg, void * user_data);
static void btaud_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 prof_id, U32 result);
static void btaud_auth_ind(void);
static void btaud_auth_aborted(void);
static void btaud_attach_ind(U32 chnl);
static void btaud_attach_fail(void);
static void btaud_chnl_update(U32 chnls);
static void btaud_detach_ind(U32 chnl);
static void btaud_attach_done(MMI_BOOL result);
static void btaud_detach_done(void);
static MMI_RET btaud_group_proc(mmi_event_struct *evt);



#endif /* BT_MMI_HFP_H */

