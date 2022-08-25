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
 * EngineerModeGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode extern function prototype declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ENGINEER_MODE_GPROT_H
#define _ENGINEER_MODE_GPROT_H
#include "app_ltlcom.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
/* EM ASM*/
#define MMI_EM_COMM_MEM_ASM_POOL_SIZE   (11*1024)

/* EM main menu event types*/
typedef enum
{
    EVT_ID_EM_MENU_LIST_ENTRY = ENGINEER_MODE1_BASE,
    EVT_ID_EM_MENU_LIST_EXIT,
    EVT_ID_EM_MENU_LIST_HILITE,
    EVT_ID_EM_MENU_LIST_SELECT,
    EVT_ID_EM_MENU_LIST_CLOSE_REQUEST,
    EVT_ID_EM_MENU_LIST_MAX_ITEM
} evt_id_em_menu_list_enum;

/***
 * Engineer mode message define
 ***/
typedef enum
{
    MMI_EM_SCR_NODE_FLAG_NONE,
    MMI_EM_SCR_NODE_FLAG_SCR,
    MMI_EM_SCR_NODE_FLAG_MENU_CUR,
    MMI_EM_SCR_NODE_FLAG_INLINE,
    MMI_EM_SCR_NODE_FLAG_FMR_CUR,
    MMI_EM_SCR_NODE_FLAG_CNFM,
    MMI_EM_SCR_NODE_FLAG_EDIT,
    MMI_EM_SCR_NODE_FLAG_TOTAL_OF_NUM
} mmi_em_scr_node_flag_enum;

typedef struct
{
    U32 cur_flag;
    U16 cur_id;
    U32 parent_flag;
    U16 parent_id;
} mmi_em_scr_level_nofity_struct;

typedef struct
{
    LOCAL_PARA_HDR
    mmi_em_scr_level_nofity_struct cntx;
} mmi_em_scr_level_nofity_ind_struct;

typedef enum 
{
    NORMAL_MODE = 0,
    ENGINEERING_MODE,
    FACTORY_MODE
} mmi_emfm_mode_enum;

/* EM Init */
extern void InitEngineerMode(void);

/* EM main menu event handlers*/

extern S32 mmi_em_mainmenu_select_handler(mmi_event_struct *arg);

extern S32 mmi_em_mainmenu_entry_handler(mmi_event_struct *arg);

extern void mmi_emfm_set_mode(mmi_emfm_mode_enum mode);

extern mmi_emfm_mode_enum mmi_emfm_get_mode(void);

extern void mmi_emfm_clear_mode(void);
#endif /* _ENGINEER_MODE_GPROT_H */ 
