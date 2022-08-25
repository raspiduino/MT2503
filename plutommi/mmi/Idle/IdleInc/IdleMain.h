/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleMain.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the idle main component.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef IDLE_MAIN_H
#define IDLE_MAIN_H

// auto add by kw_check begin
#include "MMIDataType.h"
#include "IdleObject.h"
// auto add by kw_check end 

/****************************************************************************
 * Trace
 ****************************************************************************/

#if defined(__MTK_TARGET__)
/*
 * Only target compiler supports C99 __VA_ARGS__.
 */
#define MMI_IDLE_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define MMI_IDLE_LOG(_x)     MMI_IDLE_LOG_EX _x
#else
#define MMI_IDLE_LOG(_x)
#endif /* defined(__MTK_TARGET__) */


/****************************************************************************
 * Include
 ****************************************************************************/

#include "mmi_rp_app_idle_def.h"

/****************************************************************************
 * Event Structure (internal)
 ****************************************************************************/

/* This is the structure for the EVT_ID_IDLE_MAIN_NOTIFY_REQ. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* The active group ID when the event is posted. */
    U16 active_grp_id;

    /* The active screen ID when the event is posted. */
    U16 active_scr_id;
} mmi_idle_main_notify_evt_struct;

/* This is the structure for the EVT_ID_IDLE_MAIN_UPDATE_REQ. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} mmi_idle_main_update_evt_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

extern mmi_idle_obj_struct *mmi_idle_get_obj(void);


extern void mmi_idle_emit_enter(mmi_idle_obj_struct *obj);


extern void mmi_idle_emit_exit(mmi_idle_obj_struct *obj);


extern mmi_idle_obj_struct * mmi_idle_launch_new_obj(void);


#endif /* IDLE_MAIN_H */

