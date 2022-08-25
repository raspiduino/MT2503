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
 * BirthdayGprot.h
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
#ifndef BIRTHDAY_GPROT_H
#define BIRTHDAY_GPROT_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"

/*****************************************************************************
 * Define 
 *****************************************************************************/
typedef struct
{
    U32 store_idx;    
    U16 bday_year;
    WCHAR *name;
    U8 flag;
    U8 bday_month;
    U8 bday_day;
    U8 reminder_type;
}mmi_tdl_birthday_struct;


/*****************************************************************************
 * Typedef 
 *****************************************************************************/

/*****************************************************************************
 * Global Function 
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_birthday_add_confirm
 * DESCRIPTION
 *  Ask usr whether to set birthday alert in todolist
 * PARAMETERS
 *  U16		[IN]	store_index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tdl_birthday_add_confirm(mmi_id parent_id, U16 store_idx, MYTIME *birthday);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_add_birthday_result_callback
 * DESCRIPTION
 *  Set birthday information when week is changed.
 * PARAMETERS
 *  SelectedDate        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_tdl_birthday_add_result_callback(MMI_BOOL result, mmi_tdl_birthday_struct *birthday_info);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_br_is_delete_show_confirm
 * DESCRIPTION
 *  Ask whether to show birthday add confirm screen.
 * PARAMETERS
 *  store_index : [IN] the phonebook store index.
 * RETURNS
 *  Whether to show the birthday confirm.
 *      If the birthday info has been stored in the temp buffer, means has edit the 
 *   birthday, not show confirm. Or if the phonebook store index exists in
 *   current event birthday list, not show confirm.
 *   Otherwise, show the confirm.
 *****************************************************************************/
extern MMI_BOOL mmi_tdl_br_is_delete_show_confirm(U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_br_delete
 * DESCRIPTION
 *  Delete a birthday reminder from phonebook.
 * PARAMETERS
 *  store_index : [IN] the phonebook store index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tdl_br_delete(U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_br_delete_no
 * DESCRIPTION
 *  Do not delete the birthday reminder but delete the relation ship with phonebook.
 * PARAMETERS
 *  store_index : [IN] the phonebook store index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tdl_br_delete_no(U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_br_add_reminder_entry_edit
 * DESCRIPTION
 *  Do not delete the birthday reminder but delete the relation ship with phonebook.
 * PARAMETERS
 *  store_index : [IN] the phonebook store index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tdl_br_add_reminder_entry_edit(mmi_id parent_id, U16 store_idx, MYTIME *birthday);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_phb_deletion_proc
 * DESCRIPTION
 *  deletion notification to update birthday
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret mmi_tdl_phb_deletion_proc(mmi_event_struct* param);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_br_clear_buffer_cb
 * DESCRIPTION
 *  Clear the buffer stored birthday info.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tdl_br_clear_buffer_cb(void);


#endif /* BIRTHDAY_GPROT_H */
