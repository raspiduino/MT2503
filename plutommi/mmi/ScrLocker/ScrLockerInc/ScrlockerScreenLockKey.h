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
 *  ScrlockerScreenLockKey.h
 *
 * Project:
 * --------
 *  MAUI
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

#ifndef SCR_LOCKER_SCREEN_LOCK_KEY_H
#define SCR_LOCKER_SCREEN_LOCK_KEY_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

#include "ScrLockerObject.h"
#include "DialerCuiGprot.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "ScrLockerGprot.h"


/****************************************************************************
 * Object Definition
 ****************************************************************************/

typedef enum
{
    MMI_SCRLOCK_KEY_MODE_BY_AUTO_LOCK,     /* screen lock triggered by auto lock timer */
    MMI_SCRLOCK_KEY_MODE_BY_POWER_KEY,     /* screen lock triggered by pressing power key */
    MMI_SCRLOCK_KEY_MODE_TOTAL
} vapp_screen_lock_key_mode_enum;

typedef void (*mmi_slk_on_emergency_call)(
    struct mmi_slk_obj_st *obj);

#define MMI_SLK_SCRLOCK_KEY_FIELD         \
    MMI_SLK_OBJ_FIELD

typedef struct
{
    MMI_SLK_SCRLOCK_KEY_FIELD;
    mmi_slk_on_emergency_call on_emcall;
    U32 state;
    U8  flag;
} mmi_slk_scrlock_key_struct;

/****************************************************************************
 * Function
 ****************************************************************************/

extern void mmi_slk_scrlock_key_on_init(mmi_slk_obj_struct *obj);

extern S32  vapp_screen_lock_key_init(void);
extern void vapp_screen_lock_key_deinit(void);

extern void vapp_screen_lock_key_store_state(U32 state);
extern U32  vapp_screen_lock_key_get_stored_state(void);

extern void vapp_screen_lock_key_lock_state_machine(void);
extern void vapp_screen_lock_key_unlock_state_machine(void);
extern MMI_BOOL vapp_screen_lock_key_check_state_machine(void);
extern MMI_BOOL vapp_screen_lock_key_check_emcall(void);
extern MMI_BOOL vapp_screen_lock_key_is_first_enter(void);


#endif
#endif
