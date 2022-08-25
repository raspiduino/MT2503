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
 *  PhoneBookExtraNumber.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Implementation of feature "Owner Number", "Service Dial Number", and "SOS Number"
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHONEBOOKEXTRANUMBER_H
#define PHONEBOOKEXTRANUMBER_H

#ifdef __MMI_VCARD__
#include "vCard.h"
#endif

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

/*
 * Extra Number
 */
extern void mmi_phb_entry_extra_number(void);

/*
 * Owner Number
 */
extern void mmi_phb_get_owner_number_list_req(void);
extern void mmi_phb_get_owner_number_list_rsp(U16 result);

extern void mmi_phb_entry_owner_number(void);
extern void mmi_phb_entry_owner_number_option(void);

extern void mmi_phb_entry_owner_number_edit_prepare(void);
extern void mmi_phb_entry_owner_number_edit(void);

extern void mmi_phb_edit_owner_number_check(void);
extern void mmi_phb_edit_owner_number_req(void);
extern void mmi_phb_edit_owner_number_rsp(U16 result);

extern void mmi_phb_entry_owner_number_erase_confirm(void);
extern void mmi_phb_erase_owner_number_req(void);
extern void mmi_phb_erase_owner_number_rsp(U16 result);

/*
 * Service Dial Number
 */
extern void mmi_phb_get_sdn_list_rsp(U16 result);

extern void mmi_phb_entry_sdn_list(void);

/*
 * Emergency(SOS) Number
 */
extern void mmi_phb_get_sos_list_rsp(U16 result);

extern void mmi_phb_entry_sos_list(void);
extern void mmi_phb_sos_make_call(void);

#if defined(__MMI_PHB_SOS_NUM_EDIT__)
extern void mmi_phb_entry_sos_edit_prepare(void);
extern void mmi_phb_entry_sos_edit(void);
extern void mmi_phb_save_sos_number(void);
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */

/*
 * Fixed Dial Number
 */
extern void mmi_phb_extra_sim_set_entry(void);
extern void mmi_phb_extra_mode_entry(void);
extern void mmi_phb_extra_number_option_entry(void);

extern void mmi_phb_set_extra_mode_check(void);
extern void mmi_phb_set_extra_mode_req(void);
extern void mmi_phb_set_extra_mode_rsp(U16 result);

extern void mmi_phb_get_fdn_list_check(void);
extern void mmi_phb_get_fdn_list(void);

extern void mmi_phb_extra_number_list_entry(void);

extern void mmi_phb_extra_number_add_pre_entry(void);
extern void mmi_phb_extra_number_edit_pre_entry(void);

extern void mmi_phb_edit_extra_number_check(void);
extern void mmi_phb_extra_number_save_req(void);
extern void mmi_phb_edit_fdn_number_rsp(U16 result);

extern void mmi_phb_extra_number_delete_confirm(void);
extern void mmi_phb_extra_number_delete_req(void);
extern void mmi_phb_delete_fdn_number_rsp(U16 result);

/*
 * Barred Dial Number
 */

extern void mmi_phb_get_extra_number_list_check(void);
extern void mmi_phb_get_extra_number_list_req(void);
extern void mmi_phb_get_bdn_list_rsp(U16 result);

extern void mmi_phb_extra_number_add_pre_entry(void);

extern void mmi_phb_edit_bdn_number_rsp(U16 result);

extern void mmi_phb_delete_bdn_number_rsp(U16 result);

/*
 * ICE Contact (In Case of Emergency)
 */
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif

/*
 * My Number
 */
extern void mmi_phb_entry_my_number_list(void);
extern void mmi_phb_entry_my_number_option(void);
extern void mmi_phb_entry_my_number_edit(void);

extern void mmi_phb_entry_my_number_save_confirm(void);
extern void mmi_phb_save_my_number(void);
extern void mmi_phb_go_back_from_my_number(void);

extern void mmi_phb_entry_my_number_delete_confirm(void);
extern void mmi_phb_delete_my_number(void);

#if defined(__MMI_VCARD__)
extern void mmi_phb_send_my_number(mmi_vcard_build_vcard_enum type);
#endif /* defined(__MMI_VCARD__) */

/*
 * Speed Dial
 */
extern void mmi_phb_entry_speed_dial(void);

extern void mmi_phb_entry_speed_dial_status(void);
extern void mmi_phb_entry_speed_dial_set_number(void);
extern void mmi_phb_entry_speed_dial_option(void);

extern void mmi_phb_entry_speed_dial_select_contact(void);
extern void mmi_phb_speed_dial_make_call(void);

extern void mmi_phb_speed_dial_save(
                U16 store_index,
                U16 *phb_data,
                U32 data_type);

extern void mmi_phb_delete_speed_dial(void);

/*
 * VIP Contact
 */

/*
 * Others
 */
extern void mmi_phb_call_launch(U16 *name, U16 *number);
extern void mmi_phb_call_launch_ex(U16 *name, U16 *number, U16 call_type);
extern void mmi_phb_call_launch_with_type(U16 store_index, U16 *number, U32 number_type);

extern MMI_BOOL mmi_phb_check_wild_character(U16 *number);
extern void mmi_phb_entry_fdn_replace_confirm(void);
extern void mmi_phb_make_fdn_call(void);
extern void mmi_phb_make_fdn_call_ex(U16 call_type);

#if (MMI_MAX_SIM_NUM > 1)
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
extern void mmi_phb_make_sim1_fdn_call(void);
extern void mmi_phb_make_sim2_fdn_call(void);
extern void mmi_phb_make_sim3_fdn_call(void);
extern void mmi_phb_make_sim4_fdn_call(void);
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern void mmi_phb_delete_enter_pin2_screen(void);

#endif /* PHONEBOOKEXTRANUMBER_H */

