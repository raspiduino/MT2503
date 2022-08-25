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

/*******************************************************************************
 * Filename:
 * ---------
 * NoteProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines external interface of note application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __MMI_NOTE_PROT_H__
#define __MMI_NOTE_PROT_H__

#include "MMI_features.h"

#ifdef __MMI_NOTE_APP__

#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "MMIDataType.h"

#define MMI_NOTE_NODE_LEN	MAX_SUBMENU_CHARACTERS			/* max display length of note list */

/* for app create menu id */
typedef enum
{
    MENU_ID_NOTE_LIST_OPTION,
    MENU_ID_NOTE_LIST_VIEW,
    MENU_ID_NOTE_LIST_EDIT,
    MENU_ID_NOTE_LIST_NEW_NOTE,
    MENU_ID_NOTE_LIST_MARK_SEVERAL,
    MENU_ID_NOTE_LIST_DELETE,
    MENU_ID_NOTE_LIST_TOTAL
} mmi_note_list_option_enum;

typedef enum
{
    MENU_ID_NOTE_VIEW_OPTION = MENU_ID_NOTE_LIST_TOTAL + 1,
    MENU_ID_NOTE_VIEW_OPT_EDIT,
    MENU_ID_NOTE_VIEW_OPT_DEL,
    MENU_ID_NOTE_VIEW_OPT_TOTAL    
} mmi_note_view_option_enum;

typedef enum
{
	MMI_NOTE_OP_NONE,
	MMI_NOTE_OP_EDIT,
	MMI_NOTE_OP_ADD,
	MMI_NOTE_OP_DELETE,
	MMI_NOTE_OP_GET,
	MMI_NOTE_OP_NUM
} mmi_note_operation_enum;

typedef struct 
{
	U32 modify_time;
	U32 create_time;
	U16 prior_node;
	U16 next_node;			/* next node in note list and +1 is next NVRAM storage index */
	U8 note_node[(MMI_NOTE_NODE_LEN + 1) * ENCODING_LENGTH];	/* display content in note list */
} mmi_note_node_struct;

/* structure for note application status */
typedef struct
{
    U16 item_num;    /* number of note item in list */
	mmi_note_node_struct note_list[MMI_MAX_NOTE_ITEM + 1];
} mmi_note_list_struct;

typedef struct 
{
	U16 curr_item;    /* current edit or delete item */
    U8 curr_edit[(MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH];      /* current edit or add note item content */
} mmi_note_edit_struct;

typedef struct 
{
	U16	hilite_item;	/* current high light item of mark list */
	U8	mark_flag[MMI_MAX_NOTE_ITEM];
} mmi_note_mark_list_struct;

#endif /* __MMI_NOTE_APP__ */

#endif /* __MMI_NOTE_PROT_H__ */
