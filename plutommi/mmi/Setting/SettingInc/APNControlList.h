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
 *  APNControlList.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for the header file of "ACL" feature. 
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
#ifndef APN_CONTROL_LIST_H
#define APN_CONTROL_LIST_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#ifdef __MMI_ACL_SUPPORT__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "ps_public_enum.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_utility_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Write your #define here */

#define MMI_SECSET_MAX_ACL_ENTRIES  (20)

#ifndef DYNAMIC_ALLOCATE
#define DYNAMIC_ALLOCATE
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Write your typedef here (enum, struct, ...) */

typedef struct
{
    U16 hilite_item;
    U16 acl_count;
    U8  acl_mode[MMI_SIM_TOTAL];
    U16 editor_id;
    WCHAR apn_name[MAX_APN_LEN];
    MMI_BOOL    is_new;
    mmi_sim_enum    sim_id;
    FuncPtr verify_cb;
} mmi_acl_cntx_struct;

typedef struct
{
#ifndef DYNAMIC_ALLOCATE
    WCHAR apn[MAX_APN_LEN];
#else /* DYNAMIC_ALLOCATE */
    U8  index;
    U16 apn_len;
    CHAR  *apn_data;
#endif /* DYNAMIC_ALLOCATE */
} mmi_acl_entry_struct;

typedef struct
{
    mmi_acl_entry_struct    acl_entry;
} mmi_acl_list_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */

extern mmi_acl_cntx_struct *const mmi_acl_p;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void mmi_secset_init_acl(void);

extern void mmi_secset_get_acl_mode_req(mmi_sim_enum sim_id);
extern void mmi_secset_get_acl_mode_rsp(void *info, int mod_src);

extern U8 mmi_secset_get_acl_mode(mmi_sim_enum sim_id);
extern void mmi_secset_set_acl_mode(mmi_sim_enum sim_id, U8 acl_mode);

extern mmi_ret mmi_secset_acl_main_menu_proc(mmi_event_struct *evt);

#endif /* __MMI_ACL_SUPPORT__ */

#endif /* APN_CONTROL_LIST_H */

