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
 * SMLMenuGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defines of Personalization module
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

#ifndef __SMLMENU_PROT_H__
#define __SMLMENU_PROT_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "IdleAppDef.h"				/* MAX_DIAL_PAD */
#include "stack_config.h"

#ifdef __MMI_SML_MENU__
    #define MAX_GID_LEN	        3
    #define MAX_IMSI_LEN        15
    #define MAX_NP_LEN          6
    #define MAX_NSP_LEN         8
#endif /* __MMI_SML_MENU__ */

#define MIN_SML_UNLOCK_KEY_LENGTH 8
#define MAX_SML_UNLOCK_KEY_LENGTH 16

/* SML menu implementation */
#ifdef __MMI_SML_MENU__

#define __MMI_SML_AUTO_KEY_GEN__
#define __MMI_SML_UNLOCK_RETRY_TIMER__

typedef struct
{
    U8 operation_type;          /* lock (0) or unlock (1) */
    U8 selected_category;       /* from 0 to 6 */
    U8 category_state[7];
    U8 total_records[7];
    U8 used_records[7];
    U8 key_state[7];
    U8 retry_count[7];
    U8 imsi[MAX_IMSI_LEN+1];
    U8 gid1;
    U8 gid2;
    U8 gid_valid_nibble;        /* lower nibble for gid1 and upper nibble for gid2 */
    U8 autolock_nibble;         /* lower nibble for auto lock enable and upper nibble for auto lock result */
    U8 digits_of_mcc_mnc;
    U8 action_not_from_menu;
    U8 highlight_inline_item;
    U8 input_imsi[(MAX_IMSI_LEN+1)*ENCODING_LENGTH];
    U8 input_gid1[(MAX_GID_LEN+1)*ENCODING_LENGTH];
    U8 input_gid2[(MAX_GID_LEN+1)*ENCODING_LENGTH];
} mmi_sml_menu_struct;

typedef struct
{
    U8 auto_data;
    mmi_id inline_cui_id;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif    
    FuncPtr password_len_callback;
    FuncPtr sim1_callback;
    FuncPtr sim2_callback;
    U8 dial_string[MAX_DIAL_PAD];
} mmi_sml_common_struct;

extern void mmi_sml_init(void);
extern void mmi_sml_power_on_query_req(mmi_sim_enum sim);
#ifndef __MMI_DUAL_SIM_MASTER__
extern void mmi_sml_reset_menu_content(void);
#endif

extern void mmi_sml_entry_lock_category_selection(void);
extern void mmi_sml_entry_unlock_category_selection(void);
extern void mmi_sml_entry_add_category_data(void);
extern void mmi_sml_entry_remove_category_data(void);
extern void mmi_sml_entry_permanent_unlock_selection(void);

extern U8 mmi_sml_send_lock_req_by_ssc(void);
extern U8 mmi_sml_send_unlock_req_by_ssc(void);
extern U8 mmi_sml_send_query_req_by_ssc(void);

extern void mmi_sml_display_auto_locked_notification (void);
extern void mmi_sml_popup_error_msg(U8 retry_count);

extern module_type mmi_sml_get_message_dest_module(void);
extern void mmi_sml_set_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID);
extern void mmi_sml_clear_protocol_event_handler(U16 eventID);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern void mmi_sml_entry_sim1_auto_lock(void *info);
extern void mmi_sml_entry_sim2_auto_lock(void *info);

#ifdef __SMS_DEPERSONALIZATION__
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif /* __SMS_DEPERSONALIZATION__ */

#endif /* __MMI_SML_MENU__ */

#endif /* __SMLMENU_PROT_H__ */

