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
 *  IdleObject.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the idle object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef IDLE_OBJECT_H
#define IDLE_OBJECT_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "IdleGprot.h"
#include "FactoryGprot.h"
#include "mmi_frm_utility_gprot.h"

/****************************************************************************
 * Include
 ****************************************************************************/

#include "NwNameSrvGprot.h"     /* SRV_NW_NAME_MAX_BUF_SIZE */


/****************************************************************************
 * Typedef
 ****************************************************************************/

struct mmi_idle_obj_st;

typedef mmi_id (*mmi_idle_on_create_cb)(
    struct mmi_idle_obj_st *obj,
    mmi_id parent_gid);

typedef void (*mmi_idle_on_run_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_close_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_enter_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_exit_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_update_service_area_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_before_display_cb)(
    struct mmi_idle_obj_st *obj);

typedef void (*mmi_idle_on_update_cb)(
    struct mmi_idle_obj_st *obj);


#define ENABLE_SOFT_KEY_AREA        0x00000001
#define ENABLE_LEFT_SOFT_KEY        0x00000002
#define ENABLE_RIGHT_SOFT_KEY       0x00000004
#define ENABLE_CENTER_SOFT_KEY      0x00000008
#define ENABLE_SEND_KEY             0x00000010
#define ENABLE_NAVIGATION_KEY       0x00000020
#define ENABLE_END_KEY              0x00000040
#define ENABLE_DIALER               0x00000080
#define ENABLE_VOLUME_CONTROL       0x00000100
#define ENABLE_VOICE_RECOGNITION    0x00000200
#define ENABLE_CAMERA               0x00000400
#define ENABLE_WAP                  0x00000800
#define ENABLE_GIS                  0x00001000
#define ENABLE_MTV                  0x00002000
#define ENABLE_OP01_FWP_KEY         0x00004000
#define ENABLE_FULL                 0xFFFFFFFF


#define MMI_IDLE_OBJ_FIELD_MEMBER_VARIABLE                              \
    MMI_FACTORY_OBJ_HEADER                                              \
    MMI_BOOL                                is_self_deleted;            \
    mmi_id                                  parent_gid;                 \
    mmi_id                                  this_gid;                   \
    U32                                     capability;                 \
    mmi_idle_service_indication_struct      service_indication[MMI_SIM_TOTAL]    

#define MMI_IDLE_OBJ_FIELD_MEMBER_FUNCTION                          \
    mmi_idle_on_create_cb               on_create;                  \
    mmi_idle_on_run_cb                  on_run;                     \
    mmi_idle_on_close_cb                on_close;                   \
    mmi_idle_on_enter_cb                on_enter;                   \
    mmi_idle_on_exit_cb                 on_exit;                    \
    mmi_idle_on_update_service_area_cb  on_update_service_area;     \
    mmi_idle_on_before_display_cb       on_before_idle_display

#define MMI_IDLE_OBJ_FIELD                                          \
    MMI_IDLE_OBJ_FIELD_MEMBER_VARIABLE;                             \
    MMI_IDLE_OBJ_FIELD_MEMBER_FUNCTION

typedef struct mmi_idle_obj_st
{
    MMI_IDLE_OBJ_FIELD;
} mmi_idle_obj_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

extern mmi_id mmi_idle_obj_on_create(
    mmi_idle_obj_struct *obj,
    mmi_id parent_gid);


extern void mmi_idle_obj_on_run(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_close(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_enter(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_exit(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_update_service_area(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_before_idle_display(mmi_idle_obj_struct *obj);


extern MMI_BOOL mmi_idle_obj_on_want_to_run(void);


extern void mmi_idle_obj_on_init(mmi_idle_obj_struct *obj);


extern void mmi_idle_obj_on_deinit(mmi_idle_obj_struct *obj);


#endif /* IDLE_OBJECT_H */

