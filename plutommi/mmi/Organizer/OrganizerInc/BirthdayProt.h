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
 * BirthdayProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Birthday application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BIRTHDAY_PROT_H
#define BIRTHDAY_PROT_H

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
 
#ifdef __MMI_BIRTHDAY_REMINDER__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BirthdayGprot.h"

/*****************************************************************************
 * Define 
 *****************************************************************************/
#define MMI_BR_REMINDER_HOUR              (9)
 

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
typedef enum
{
    MMI_BR_REMINDER_NONE,
    MMI_BR_REMINDER_SAME_DAY,
    MMI_BR_REMINDER_PREV_DAY,
    MMI_BR_REMINDER_TOTAL
} mmi_br_reminder_type_enum;

typedef enum
{
    MMI_BR_ENTER_ORG,
    MMI_BR_ENTER_PHB,
    MMI_BR_ENTER_FILE,
    MMI_BR_ENTER_TOTAL
} mmi_br_enter_flag_enum;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_inline_gid;
    mmi_tdl_birthday_struct view_birth_info;
}mmi_br_view_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_inline_gid;
    mmi_tdl_birthday_struct edit_birth_info;
}mmi_br_edit_group_data_struct;

typedef struct
{
    CHAR *inline_reminder[MMI_BR_REMINDER_TOTAL];
    U8 ui_mode;
    S32 hilite_reminder;	
    U16 curr_store_idx;
    WCHAR birth_date_buff[20];
    WCHAR birth_time_buff[20];
    MMI_BOOL is_add;
    mmi_tdl_birthday_struct temp_birth_info;
    mmi_tdl_birthday_struct curr_birth_info;
} birthday_context_struct;


/*****************************************************************************
 * Global Declaration 
 *****************************************************************************/
extern birthday_context_struct g_birth_cntx;
 

/*****************************************************************************
 * Global Function 
 *****************************************************************************/
extern void mmi_tdl_br_entry_bday_view_from_org(mmi_id parent_id);
extern void mmi_tdl_br_entry_bday_edit_from_org(mmi_id parent_id);

#endif /* __MMI_BIRTHDAY_REMINDER__ */
#endif /* BIRTHDAY_PROT_H */
