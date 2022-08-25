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
 *  IdleClassic.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines interface of the classic idle object.
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

#ifndef IDLE_CLASSIC_H
#define IDLE_CLASSIC_H

// auto add by kw_check begin
#include "IdleObject.h"
#include "wgui_categories_list.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "IdleGprot.h"
// auto add by kw_check end 

#ifdef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
/****************************************************************************
 * Define
 ****************************************************************************/

#if !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && \
    !defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__) && \
    !defined(__MMI_BT_BOX_IDLE_SHORTCUTS__)
#define MMI_IDLE_CLASSIC_CSK_SUPPORT
#endif

/****************************************************************************
 * Object Definition
 ****************************************************************************/

#if defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
/* Max number of icon shortcuts. */
#define MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT          (5)
#endif

/* 
 * Member fields related to icon shortcuts. 
 */
#if !defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
#define MMI_IDLE_CLASSIC_ICON_SHORTCUT_MEMBER_VARIABLE                  \
    U8          icon_shortcut_dummy
#else
#define MMI_IDLE_CLASSIC_ICON_SHORTCUT_MEMBER_VARIABLE                  \
    FuncPtr     icon_shct_hdlr[MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT];     \
    PU8         icon_shct_up[MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT];       \
    PU8         icon_shct_down[MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT];     \
    PU8         icon_shct_hint[MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT]
#endif /* defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__) */

/* 
 * Object definition. 
 */
#define MMI_IDLE_CLASSIC_FIELD                                          \
    MMI_IDLE_OBJ_FIELD;                                                 \
    MMI_IDLE_CLASSIC_ICON_SHORTCUT_MEMBER_VARIABLE

typedef struct
{
    MMI_IDLE_CLASSIC_FIELD;
} mmi_idle_classic_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

extern void mmi_idle_classic_on_init(mmi_idle_obj_struct *obj);

#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/

#endif /* IDLE_CLASSIC_H */

