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
 *  IdleNotificationManager.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is the internal header file of the idle screen notification 
 *  manager (NMGR).
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
 *============================================================================
 ****************************************************************************/
 
#ifndef _MMI_IDLE_NOTIFICATION_MANAGER_H
#define _MMI_IDLE_NOTIFICATION_MANAGER_H

#include "MMI_features.h"

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "lcd_cqueue.h"
#include "IdleNotificationManagerGprot.h"
#include "IdleNotificationManagerConfig.h"


/**********************************************************************
 * Default constants definition
 **********************************************************************/

/* 
 * Internal option flag (LSB two bytes is used by external option flag): 
 */

/* The notification needs the idle screen as the background. */
#define MMI_NMGR_FLAG_NEED_BACKGROUND   0x00010000


/**********************************************************************
 * Default constants definition
 **********************************************************************/

#define MMI_NMGR_GUARD_TOV              1500

#define MMI_NMGR_MAX_NOTIFY_NUM         8

#define MMI_NMGR_QUEUE_CNTX_SIZE    \
    (sizeof(lcd_cqueue) + sizeof(void *) * MMI_NMGR_MAX_NOTIFY_NUM)


/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef MMI_BOOL (*mmi_nmgr_cbf_t)(void);


/**********************************************************************
 * Structure definitions
 **********************************************************************/

typedef struct
{
    U32             trigger;
    U32             type;
    U32             flag;
    mmi_nmgr_cbf_t  func;
} mmi_nmgr_req_struct;

typedef struct
{
    MMI_BOOL            is_used;
    mmi_nmgr_req_struct req;
} mmi_nmgr_queue_elem_struct;

typedef struct
{
    U32                             state;              /* All events  */
    kal_uint8                       queue_context[MMI_NMGR_QUEUE_CNTX_SIZE];
    mmi_nmgr_req_struct             proc_req;
    mmi_nmgr_req_struct             wait_req;
    mmi_nmgr_req_struct             active_req;
    mmi_nmgr_req_struct             prev_req;
    mmi_nmgr_answer_struct          info[MMI_NMGR_APP_NUM];
    lcd_cqueue                     *queue;
    mmi_nmgr_queue_elem_struct      queue_elem[MMI_NMGR_MAX_NOTIFY_NUM];
} mmi_nmgr_context_struct;


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern U8 mmi_nmgr_need_notification(void);

extern void mmi_nmgr_direct_notify(void);

extern void mmi_nmgr_reset(void);

#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#endif /* _MMI_IDLE_NOTIFICATION_MANAGER_H */

