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
 *  PhoneBookSearch.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for phb and call log dialer search
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
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#ifndef _PHONEBOOKSEARCH_C
#define _PHONEBOOKSEARCH_C

#ifdef __MMI_DIALER_SEARCH__
#include "CallManagementStruct.h"
#include "CallManagementStruct.h"
#include "UCMGprot.h"
#include "CallLogGprot.h"

#include "Mms_api.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExdcl.h"

#include "IdleHomescreenGProt.h"
#include "idleAppGprot.h"
#include "IdleAppProt.h"
#include "IdleDialerSearchGprot.h"

#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhbSrvGprot.h"
#include "SmsAppGprot.h"
#include "SmsSrvGprot.h"
#include "PhbCuiGprot.h"

#include "mainmenudef.h"
#include "CommonScreens.h"
#include "menucuigprot.h"
#include "simctrlsrvgprot.h"
#include "DialerGprot.h"
#include "IdleAppResDef.h"
#include "DialerCuiGprot.h"
#include "modeSwitchSrvGprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_idlescreen_op.h"
#include "mmi_rp_app_phonebook_def.h"
/*
 * Typedef
 */

typedef struct
{
    srv_phb_ds_list_cntx_struct list_cntx;
    U16 store_index;                /* hilite index */
} mmi_phb_ds_context_struct;

/*
 * Define
 */
void mmi_phb_ds_entry_op_dial(srv_ucm_call_type_enum sim_type);
void mmi_phb_ds_entry_op_add_contact(void);
void mmi_phb_ds_entry_op_view(void);

/*
 * Enum
 */
typedef enum
{
	mmi_phb_ds_dial,
	mmi_phb_ds_message,
	mmi_phb_ds_sms,
	mmi_phb_ds_mms,
	mmi_phb_ds_invalid_type,
}mmi_phb_ds_op_type_enum;

/*
 * Global Variable
 */
extern mmi_phb_choose_field_struct g_mmi_phb_choose_field;
mmi_phb_ds_context_struct g_mmi_phb_ds_context;

srv_ucm_call_type_enum ucm_type;

MMI_BOOL g_mmi_phb_ds_call_from_option;

U16 g_mmi_phb_ds_highlight_index;
mmi_id g_mmi_phb_ds_parent_id;


void mmi_phb_ds_call_number_directly(U32 number_type, U16 *mmi_phb_number_to_dial);	
#ifdef __MMI_UNIFIED_COMPOSER__
    void mmi_phb_ds_entry_op_send_message(void);
	void mmi_phb_ds_send_message_directly(U16 *mmi_phb_number_to_dial, grp_id_phb_enum gid);

#else
    void mmi_phb_ds_entry_op_send_sms(void);
	void mmi_phb_ds_send_sms_directly(U16 *mmi_phb_number_to_dial, grp_id_phb_enum gid);

#if defined(__MMI_MMS__)
    void mmi_phb_ds_entry_op_send_mms(void);
	void mmi_phb_ds_send_mms_directly(U16 *mmi_phb_number_to_dial, grp_id_phb_enum gid);

#endif /* defined(__MMI_MMS__) */
#endif /* __MMI_UNIFIED_COMPOSER__ */

/*
 * Local Function
 */

/*
 * Global Function
 */

#define DSEARCH_DATE_RELATE
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_num_index
 * DESCRIPTION
 *  get hilite number(if the number is optional number) store index
 * PARAMETERS
 *  itme_index       [IN]       hilite_index
 *  pstore_index     [OUT]      store index
 * RETURNS
 *  number type: 0 mobile; 1 home; 2 office; 3 fax
 *****************************************************************************/
U32 mmi_phb_ds_get_num_index(S32 item_index, U16 *store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_off_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_off_index = item_index - g_mmi_phb_ds_context.list_cntx.name_count - g_mmi_phb_ds_context.list_cntx.callog_count;
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
    {
        S32 i, j;
        S32 number_count = 0;
        S32 index;
        U32 num_index;
        for (i = MMI_PHB_ENTRIES - 1; i >= (MMI_PHB_ENTRIES - g_mmi_phb_ds_context.list_cntx.number_count); i--)
        {
            number_count += g_mmi_phb_ds_context.list_cntx.entry[i].count;
            if (num_off_index < number_count)
            {
                *store_index = g_mmi_phb_ds_context.list_cntx.entry[i].store_index;
                break;
            }
        }
        
        index = num_off_index - (number_count - g_mmi_phb_ds_context.list_cntx.entry[i].count);
        for (j = 0; j < 4; j++)
        {
            num_index = (SRV_PHB_ENTRY_FIELD_NUMBER << j);
            if (g_mmi_phb_ds_context.list_cntx.entry[i].u.num_index & num_index)
            {
                index--;
                if (index < 0)
                {
                    break;
                }
            }
        }
        return num_index;
    }
#else
    *store_index = g_mmi_phb_ds_context.list_cntx.entry[MMI_PHB_ENTRIES - 1 - num_off_index].store_index;
    return SRV_PHB_ENTRY_FIELD_NUMBER; 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_get_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_ds_highlight_index = item_index;

#ifdef __MMI_ICON_BAR_SUPPORT__
    if (wgui_cat203_is_editor_active())
    {
        cui_dialer_toolbar_update(MMI_TRUE);
    }
    else
    {
        cui_dialer_toolbar_update(MMI_FALSE);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_phb_ds_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_ds_list_cntx_struct* list_cntx = &(g_mmi_phb_ds_context.list_cntx);
    srv_phb_ds_phb_entry_struct* entry = list_cntx->entry;
    srv_clog_log_identity_struct idt;
    srv_clog_log_struct log;
    S32 num_index;
    U16 store_index;
	MMI_ID_TYPE image_id;
	U8  storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < list_cntx->name_count)
    {
        /* name field */
        store_index = entry[item_index].store_index;
        srv_phb_get_name(store_index, str_buff, MAX_SUBMENU_CHARACTERS);
        
        if (str_buff[0] == 0)
        {
            mmi_wcsncpy((WCHAR*) str_buff, (WCHAR*)GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
        }

		storage = srv_phb_get_storage(store_index);
		switch(storage)
		{
			case PHB_STORAGE_NVRAM:
				image_id = IMG_STORAGE_HANDSET;
				break;
			case PHB_STORAGE_SIM:
        #if (MMI_MAX_SIM_NUM >= 2)
				image_id = IMG_GLOBAL_SIM1;
	    #else
				image_id = IMG_STORAGE_SIM;
        #endif
				break;
			case PHB_STORAGE_SIM2:
				image_id = IMG_GLOBAL_SIM2;
				break;
			case PHB_STORAGE_SIM3:
				image_id = IMG_GLOBAL_SIM3;
				break;
			case PHB_STORAGE_SIM4:	
				image_id = IMG_GLOBAL_SIM4;
				break;
		#ifdef 	__MMI_PHB_TCARD_STORAGE_SUPPORT__
			case PHB_STORAGE_TCARD:
				image_id = IMG_ID_PHB_TCARD_LIST;
				break;
        #endif
			default:
				image_id = IMG_STORAGE_HANDSET;
				break;		
        }
		*img_buff_p = get_image(image_id);
    }
    else if (item_index - list_cntx->name_count < g_mmi_phb_ds_context.list_cntx.callog_count)
    {
        srv_clog_get_log_by_id(
            0,
            g_mmi_phb_ds_context.list_cntx.calllog_id[item_index - g_mmi_phb_ds_context.list_cntx.name_count],
            SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_NAME | SRV_CLOG_LOG_FIELD_CID,
            &log);
        if (log.data.call_log.name[0])
        {
            mmi_wcsncpy((WCHAR*) str_buff, log.data.call_log.name, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_wcsncpy((WCHAR*) str_buff, log.data.call_log.cid, MAX_SUBMENU_CHARACTERS);
        }
        idt.cate = log.data.call_log.cate;
        idt.sim_id = log.data.call_log.sim_id;
        idt.log_type = log.data.call_log.log_type;
        idt.sub_type = log.data.call_log.sub_type;
        *img_buff_p = get_image(mmi_clog_get_log_icon(&idt));
    }
    else
    {
        /* number field */
        num_index = mmi_phb_ds_get_num_index(item_index, &store_index);
        srv_phb_get_name(store_index, str_buff, MAX_SUBMENU_CHARACTERS);
        if (num_index == SRV_PHB_ENTRY_FIELD_NUMBER)
        {
            if (str_buff[0] == 0)
            {
                srv_phb_get_number(store_index, str_buff, MAX_SUBMENU_CHARACTERS);
            }        
            #if(!defined(__MMI_FTE_SUPPORT__)||defined(__FTE_NON_SLIM_RES__))
			           *img_buff_p = get_image(IMG_MOBILE_NUMBER);
			      #else
			           *img_buff_p = 0;
			      #endif
        }
    #if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
        else
        {
            WCHAR* temp = NULL;
            mmi_phb_num_type_enum type;
            if (str_buff[0] == 0)
            {
                temp = (WCHAR*)str_buff;
            }
            srv_phb_get_optional_number(
                        store_index,
                        num_index,
                        temp,
                        &type,
                        MAX_SUBMENU_CHARACTERS);
            *img_buff_p = get_image(mmi_phb_get_img_by_number_type(type));
        }
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phb_ds_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp_name[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_ds_list_cntx_struct* list_cntx = &(g_mmi_phb_ds_context.list_cntx);
    srv_phb_ds_phb_entry_struct* entry = list_cntx->entry;
    srv_clog_log_struct log;
    S32 num_index = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < list_cntx->name_count)
    {
        /* name field */
        store_index = entry[item_index].store_index;
        srv_phb_get_number(store_index, hint_array[0], MAX_SUBMENU_CHARACTERS);
        /* There should show default number */
        if (hint_array[0][0])
        {
            return 1;
        }
    }
    else if (item_index - list_cntx->name_count < g_mmi_phb_ds_context.list_cntx.callog_count)
    {
        srv_clog_get_log_by_id(
            0,
            g_mmi_phb_ds_context.list_cntx.calllog_id[item_index - g_mmi_phb_ds_context.list_cntx.name_count],
            SRV_CLOG_LOG_FIELD_NAME | SRV_CLOG_LOG_FIELD_CID,
            &log);
        if (log.data.call_log.name[0])
        {
            mmi_wcsncpy((WCHAR*) hint_array[0], log.data.call_log.cid, MAX_SUBMENU_CHARACTERS);
            return 1;
        }
    }
    else
    {
        num_index = mmi_phb_ds_get_num_index(item_index, &store_index);
        srv_phb_get_name(store_index, temp_name, MMI_PHB_NAME_LENGTH);
        if (temp_name[0])
        {
            if (num_index == SRV_PHB_ENTRY_FIELD_NUMBER)
            {
                /* mobile number */
                srv_phb_get_number(store_index, hint_array[0], MAX_SUBMENU_CHARACTERS);
            }
        #if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
            else
            {
                srv_phb_get_optional_number(
                    store_index,
                    num_index,
                    hint_array[0],
                    NULL,
                    MAX_SUBMENU_CHARACTERS);
            }
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */
            return 1;
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_underline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_ds_get_underline(S32 item_index, S32 *underline_index, S32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S32 name_length;
    S32 i, j;
    WCHAR temp_name[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_ds_list_cntx_struct* list_cntx = &(g_mmi_phb_ds_context.list_cntx);
    srv_phb_ds_phb_entry_struct* entry = list_cntx->entry;
    U16 key_len = list_cntx->key_len;
	srv_clog_log_struct log;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < list_cntx->name_count)
    {
        /* name field */
        store_index = entry[item_index].store_index;
        *count = entry[item_index].count;
        for (j = entry[item_index].u.first, i = 0; i < *count; i++)
        {
            underline_index[2 * i] = j;
            underline_index[2 * i + 1] = j + key_len - 1;
            j += key_len;
            srv_phb_get_name(store_index, temp_name, MMI_PHB_NAME_LENGTH);
            name_length = mmi_wcslen(temp_name);
            while (j < name_length)
            {
                j++;
                if (entry[item_index].mask[j / 8] & (1 << (j % 8)))
                {
                    break;
                }
            }
        }
    }
    else if (item_index - list_cntx->name_count < g_mmi_phb_ds_context.list_cntx.callog_count)
    {
        srv_clog_get_log_by_id(
            0,
            g_mmi_phb_ds_context.list_cntx.calllog_id[item_index - g_mmi_phb_ds_context.list_cntx.name_count],
            SRV_CLOG_LOG_FIELD_NAME,
            &log);
        if (log.data.call_log.name[0])
		{
            *count = 0;
        }
		else
        {
            *count = 1;
            underline_index[0] = 0;
            underline_index[1] = key_len - 1;
        }
    }
    else
    {
        mmi_phb_ds_get_num_index(item_index, &store_index);
        srv_phb_get_name(store_index, temp_name, MMI_PHB_NAME_LENGTH);
        if (temp_name[0])
        {
            *count = 0;
        }
        else
        {
            *count = 1;
            underline_index[0] = 0;
            underline_index[1] = key_len - 1;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dialer_search_group_proc
 * DESCRIPTION
 *  screen group dialer search agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_dialer_search_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_INACTIVE:
        if (!mmi_frm_scrn_get_count(GRP_ID_PHB_DIALER_SEARCH))
        {
            mmi_frm_group_close(GRP_ID_PHB_DIALER_SEARCH);
        }
        break;
    case EVT_ID_GROUP_ACTIVE:
        if (mmi_frm_is_in_backward_scenario())
        {
        if (!mmi_frm_scrn_get_count(GRP_ID_PHB_DIALER_SEARCH))
        {
            mmi_frm_group_close(GRP_ID_PHB_DIALER_SEARCH);
        }
        }
        break;
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_DS_OPTIONS_SWITCH, MMI_FALSE);
            break;
        }
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_SWITCH)
            {
                mmi_dialer_search_entry_setting(GRP_ID_PHB_DIALER_SEARCH);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_VIEW)
            {
                mmi_phb_ds_entry_op_view();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_ADD_CONTACT)
            {
                mmi_phb_ds_entry_op_add_contact();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_DIAL)
            {
                mmi_phb_ds_entry_op_dial(SRV_UCM_CALL_TYPE_ALL);
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_SEND_MESSAGE)
            {
                mmi_phb_ds_entry_op_send_message();
            }
        #else
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_SEND_SMS)
            {
                mmi_phb_ds_entry_op_send_sms();
            }
        #if defined(__MMI_MMS__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_DS_OPTIONS_SEND_MMS)
            {
                mmi_phb_ds_entry_op_send_mms();
            }
        #endif /* defined(__MMI_MMS__) */
        #endif /* __MMI_UNIFIED_COMPOSER__ */
            else
            {
                return MMI_RET_DONT_CARE;
            }
            break;
        }
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_options
 * DESCRIPTION
 * 
 * 1. if result is null, then option just has switch menu item
 * 2. if result is not null, but no highlight, use the input box to call or message
 * 3. if result is not null, and there is highlighted item
 *    3.1) if the hightlighted item is phonebook item
 *    3.2) if the hightlighted item is calllog item
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_options_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_clog_log_struct log;
    MMI_ID menu_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                   GRP_ID_PHB_DIALER_SEARCH,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_OPTION,
                   MENU_ID_PHB_DS_OPTIONS,
                   MMI_FALSE, NULL);
    
	if(srv_sim_ctrl_any_sim_is_available())
    {
        if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_DIAL, MMI_TRUE);
        }
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_DIAL, MMI_TRUE);
    }

#if defined(__MMI_UNIFIED_COMPOSER__)
    if (!mmi_uc_is_uc_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_SEND_MESSAGE, MMI_TRUE);
    }
#else /* defined(__MMI_UNIFIED_COMPOSER__) */
#if defined(__MMI_MMS__)
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_SEND_MMS, MMI_TRUE);
    }
#endif /* defined(__MMI_MMS__) */
#endif /* defined(__MMI_UNIFIED_COMPOSER__) */

    if (g_mmi_phb_ds_highlight_index >= g_mmi_phb_ds_context.list_cntx.name_count &&
        g_mmi_phb_ds_highlight_index - g_mmi_phb_ds_context.list_cntx.name_count < g_mmi_phb_ds_context.list_cntx.callog_count)
    {        
        srv_clog_get_log_by_id(
            0,
            g_mmi_phb_ds_context.list_cntx.calllog_id[g_mmi_phb_ds_highlight_index - g_mmi_phb_ds_context.list_cntx.name_count],
            SRV_CLOG_LOG_FIELD_PHB_ID,
            &log);
        if (srv_phb_check_number_id(log.data.call_log.phb_id))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_ADD_CONTACT, MMI_TRUE);
        }
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_VIEW, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DS_OPTIONS_ADD_CONTACT, MMI_TRUE);
    }
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_options
 * DESCRIPTION
 * 
 * 1. if result is null, then option just has switch menu item
 * 2. if result is not null, but no highlight, use the input box to call or message
 * 3. if result is not null, and there is highlighted item
 *    3.1) if the hightlighted item is phonebook item
 *    3.2) if the hightlighted item is calllog item
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_ds_parent_id = mmi_frm_group_get_active_id();

	mmi_frm_group_create_ex(g_mmi_phb_ds_parent_id, GRP_ID_PHB_DIALER_SEARCH, mmi_phb_dialer_search_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_phb_ds_entry_options_menu();
}


#define DSEARCH_OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_delete_option_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_delete_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_PHB_DIALER_SEARCH, SCR_ID_PHB_DS_OPTIONS, MMI_FRM_NODE_ALL_FLAG))
        mmi_frm_scrn_close(GRP_ID_PHB_DIALER_SEARCH, SCR_ID_PHB_DS_OPTIONS);
    if (mmi_frm_scrn_is_present(GRP_ID_PHB_DIALER_SEARCH, SCR_CHOOSE_NUMBER, MMI_FRM_NODE_ALL_FLAG))
        mmi_frm_scrn_close(GRP_ID_PHB_DIALER_SEARCH, SCR_CHOOSE_NUMBER);

    if (!g_mmi_phb_ds_call_from_option)
    {
        mmi_frm_group_close(GRP_ID_PHB_DIALER_SEARCH);
    }

    MMI_PHB_LOG1(TRC_MMI_PHB_DS_DELETE_OPTION_SCR, mmi_frm_group_get_active_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_cbk(mmi_ucm_after_make_call_cb_struct* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p->user_data)
    {
        srv_phb_destory_cm_user_data(p->user_data);
    }
	
    mmi_phb_ds_delete_option_scr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_do_op_by_type
 * DESCRIPTION
 *  Ds do op by giving type
 * PARAMETERS
 *  mmi_phb_ds_op_type_enum ds_type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ds_do_op_by_type(mmi_phb_ds_op_type_enum ds_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 mmi_phb_number_to_dial[MMI_PHB_NUMBER_PLUS_LENGTH + 1] = {'\0'};
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)	
	mmi_phb_num_type_enum type;
#endif
    U32 number_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    number_type = mmi_phb_ds_get_num_index(g_mmi_phb_ds_highlight_index, &(g_mmi_phb_ds_context.store_index));
	
    if (number_type ==SRV_PHB_ENTRY_FIELD_NUMBER)
    {
        srv_phb_get_number(g_mmi_phb_ds_context.store_index, mmi_phb_number_to_dial, MAX_SUBMENU_CHARACTERS);
    }
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
    else
    {
        srv_phb_get_optional_number(
            g_mmi_phb_ds_context.store_index,
            number_type,
            mmi_phb_number_to_dial,
            &type,
            MAX_SUBMENU_CHARACTERS);
    }
#endif

	switch(ds_type)
	{
		case mmi_phb_ds_dial:
			mmi_phb_ds_call_number_directly(number_type, mmi_phb_number_to_dial);
			break;
	#ifdef __MMI_UNIFIED_COMPOSER__		
		case mmi_phb_ds_message:
			mmi_phb_ds_send_message_directly(mmi_phb_number_to_dial, GRP_ID_PHB_DIALER_SEARCH);
			break;
	#else		
		case mmi_phb_ds_sms:
			mmi_phb_ds_send_sms_directly(mmi_phb_number_to_dial, GRP_ID_PHB_DIALER_SEARCH);
			break;
	#ifdef __MMI_MMS__		
		case mmi_phb_ds_mms:
			mmi_phb_ds_send_mms_directly(mmi_phb_number_to_dial, GRP_ID_PHB_DIALER_SEARCH);
			break;
	#endif
	#endif
		default:
			break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_do_calllog_op
 * DESCRIPTION
 *  Call log operation
 * PARAMETERS
 *  mmi_clog_act_enum act
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ds_do_calllog_action(mmi_clog_act_enum act)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_clog_act_prop_struct act_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_clog_act_init_prop(&act_data);
	act_data.act_type = act;
	act_data.log_id = g_mmi_phb_ds_context.list_cntx.calllog_id[g_mmi_phb_ds_highlight_index - g_mmi_phb_ds_context.list_cntx.name_count];
	mmi_clog_act_apply(g_mmi_phb_ds_parent_id, &act_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_call_choose_number_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_call_number_directly(U32 number_type, U16* num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);
    cm_user_data = srv_phb_create_cm_user_data(
        NULL, 
        number_type, 
        g_mmi_phb_ds_context.store_index);
	
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = (mmi_ucm_after_make_call_callback)mmi_phb_ds_cbk;
	make_call_para.dial_type = 	ucm_type;
    make_call_para.ucs2_num_uri = num_uri;
    
    
    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_call_choose_number_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_call_choose_number_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);
    cm_user_data = srv_phb_create_cm_user_data(
        NULL, 
        g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index], 
        g_mmi_phb_ds_context.store_index);
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = (mmi_ucm_after_make_call_callback)mmi_phb_ds_cbk;
    make_call_para.ucs2_num_uri = g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index];
	make_call_para.dial_type = 	ucm_type;
    
    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_call_choose_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_call_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_phb_ds_call_from_option)
    {
        if (!mmi_frm_group_is_present(GRP_ID_PHB_DIALER_SEARCH))
        {
            mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_PHB_DIALER_SEARCH, mmi_phb_dialer_search_group_proc, NULL);
            mmi_frm_group_enter(GRP_ID_PHB_DIALER_SEARCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
    }

    mmi_phb_entry_choose_field(
        GRP_ID_PHB_DIALER_SEARCH,
        g_mmi_phb_ds_context.store_index,
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        mmi_phb_ds_call_choose_number,
        mmi_phb_ds_call_choose_number_done,
        mmi_frm_scrn_close_active_id,
        mmi_phb_ds_call_choose_number_done,
        MMI_FALSE,
        MMI_FALSE);

    MMI_PHB_LOG1(TRC_MMI_PHB_DS_CALL_CHOOSE_NUMBER, mmi_frm_group_get_active_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_dial(srv_ucm_call_type_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_DS_ENTRY_OP_DIAL, g_mmi_phb_ds_highlight_index);

    g_mmi_phb_ds_call_from_option = MMI_FALSE;
	ucm_type = sim_type;

    if (mmi_frm_scrn_get_active_id() == SCR_ID_PHB_DS_OPTIONS)
    {
        g_mmi_phb_ds_call_from_option = MMI_TRUE;
    }

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.name_count)
    {
        g_mmi_phb_ds_context.store_index = g_mmi_phb_ds_context.list_cntx.entry[g_mmi_phb_ds_highlight_index].store_index;
        mmi_phb_ds_call_choose_number();
    }
    else if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {

		mmi_ucm_make_call_para_struct call_para;
        srv_clog_log_struct log;
        void *phb_data;
        SRV_CLOG_ID log_id = g_mmi_phb_ds_context.list_cntx.calllog_id[g_mmi_phb_ds_highlight_index - g_mmi_phb_ds_context.list_cntx.name_count];

		mmi_ucm_init_call_para(&call_para);
        srv_clog_get_log_by_id(0, log_id, SRV_CLOG_LOG_FIELD_DEFAULT, &log);
        
        if (srv_phb_check_number_id(log.data.call_log.phb_id))
            phb_data = srv_phb_create_cm_user_data_by_id(log.data.call_log.phb_id);
        else if (log.data.call_log.name[0] != '\0')
            phb_data = srv_phb_create_cm_user_data(log.data.call_log.name, 0, SRV_PHB_INVALID_INDEX);
        else
            phb_data = NULL;

	call_para.dial_type = sim_type;
        call_para.adv_para.after_callback_user_data = phb_data;
        call_para.adv_para.phb_data = phb_data;
        call_para.ucs2_num_uri = log.data.call_log.cid;
        call_para.adv_para.after_make_call_callback = mmi_phb_ds_cbk;

        mmi_ucm_call_launch(g_mmi_phb_ds_parent_id, &call_para);
		
        return;
    }
    else
    {
		mmi_phb_ds_do_op_by_type(mmi_phb_ds_dial);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_sendkey_call_pre_entry(srv_ucm_call_type_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_ds_parent_id = mmi_frm_group_get_active_id();
    mmi_phb_ds_entry_op_dial(sim_type);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_csk_call_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_ds_parent_id = mmi_frm_group_get_active_id();
    mmi_phb_ds_entry_op_dial(SRV_UCM_VOICE_CALL_TYPE_ALL);
}


#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_message_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_message_directly(U16* num_uri, grp_id_phb_enum gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_MESSAGE_DONE);

    mmi_phb_uc_send_msg((CHAR*) num_uri, gid);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_message_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_message_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_MESSAGE_DONE);

    mmi_phb_uc_send_msg((CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index], GRP_ID_PHB_DIALER_SEARCH);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        GRP_ID_PHB_DIALER_SEARCH,
        g_mmi_phb_ds_context.store_index,
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_ds_send_message,
        mmi_phb_ds_send_message_done,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_send_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_OP_SEND_MESSAGE);

    g_mmi_phb_ds_call_from_option = MMI_TRUE;

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.name_count)
    {
        g_mmi_phb_ds_context.store_index = g_mmi_phb_ds_context.list_cntx.entry[g_mmi_phb_ds_highlight_index].store_index;
    }
    else if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {
		mmi_phb_ds_do_calllog_action(MMI_CLOG_ACT_SEND_MSG);
        return;
    }
    else
    {
		mmi_phb_ds_do_op_by_type(mmi_phb_ds_message);
        return;
    }

    if (IsMessagesReEntering())
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_DIALER_SEARCH,
            0);
        mmi_frm_scrn_close(GRP_ID_PHB_DIALER_SEARCH, SCR_ID_PHB_DS_OPTIONS);
        return;
    }
    
    mmi_phb_ds_send_message();
}


#ifdef __MMI_FTE_SUPPORT__
void mmi_phb_ds_op_fte_send_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create_ex(mmi_frm_group_get_active_id(), 
							GRP_ID_PHB_DIALER_SEARCH, 
							mmi_phb_dialer_search_group_proc, 
							NULL, 
							MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_phb_ds_parent_id = GRP_ID_PHB_DIALER_SEARCH;
    mmi_phb_ds_entry_op_send_message();
}
#endif


#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_sms_directly
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_sms_directly(U16* num_uri, grp_id_phb_enum gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_SMS_DONE);

    mmi_phb_sms_send_data_for_entry((CHAR*)num_uri, gid);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_sms_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_sms_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_SMS_DONE);

    mmi_phb_sms_send_data_for_entry((CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index], GRP_ID_PHB_DIALER_SEARCH);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        GRP_ID_PHB_DIALER_SEARCH,
        g_mmi_phb_ds_context.store_index,
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        mmi_phb_ds_send_sms,
        mmi_phb_ds_send_sms_done,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_ENTRY_OP_SEND_SMS);

    g_mmi_phb_ds_call_from_option = MMI_TRUE;

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.name_count)
    {
        g_mmi_phb_ds_context.store_index = g_mmi_phb_ds_context.list_cntx.entry[g_mmi_phb_ds_highlight_index].store_index;
    }
    else if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {
		mmi_phb_ds_do_calllog_action(MMI_CLOG_ACT_SEND_SMS);
        return;
    }
    else
    {
        mmi_phb_ds_do_op_by_type(mmi_phb_ds_sms);
        return;
    }

    if (mmi_sms_is_reenter_message())
    {
        mmi_frm_scrn_close(GRP_ID_PHB_DIALER_SEARCH, SCR_ID_PHB_DS_OPTIONS);
        return;
    }
    
    mmi_phb_ds_send_sms();
}


#ifdef __MMI_FTE_SUPPORT__
void mmi_phb_ds_op_fte_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	mmi_frm_group_create_ex(mmi_frm_group_get_active_id(), 
						GRP_ID_PHB_DIALER_SEARCH, 
						mmi_phb_dialer_search_group_proc, 
						NULL, 
						MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_phb_ds_parent_id = GRP_ID_PHB_DIALER_SEARCH;

    mmi_phb_ds_entry_op_send_sms();
}
#endif


#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_mms_directly
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_mms_directly(U16* num_uri, grp_id_phb_enum gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_MMS_DONE);

    mmi_phb_mms_send_data_for_entry((CHAR*)num_uri, gid);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_mms_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_mms_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_SEND_MMS_DONE);

    mmi_phb_mms_send_data_for_entry(
        (CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index],
        GRP_ID_PHB_DIALER_SEARCH);
    mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        GRP_ID_PHB_DIALER_SEARCH,
        g_mmi_phb_ds_context.store_index,
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_ds_send_mms,
        mmi_phb_ds_send_mms_done,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_ENTRY_OP_SEND_MMS);

    g_mmi_phb_ds_call_from_option = MMI_TRUE;

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.name_count)
    {
        g_mmi_phb_ds_context.store_index = g_mmi_phb_ds_context.list_cntx.entry[g_mmi_phb_ds_highlight_index].store_index;
    }
    else if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {
		mmi_phb_ds_do_calllog_action(MMI_CLOG_ACT_SEND_MMS);
        return;
    }
    else
    {
		mmi_phb_ds_do_op_by_type(mmi_phb_ds_mms);
        return;
    }

    if (IsMessagesReEntering())
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_DIALER_SEARCH,
            0);
        mmi_frm_scrn_close(GRP_ID_PHB_DIALER_SEARCH, SCR_ID_PHB_DS_OPTIONS);
        return;
    }
    
    mmi_phb_ds_send_mms();
    
}


#ifdef __MMI_FTE_SUPPORT__
void mmi_phb_ds_op_fte_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	mmi_frm_group_create_ex(mmi_frm_group_get_active_id(), 
						GRP_ID_PHB_DIALER_SEARCH, 
						mmi_phb_dialer_search_group_proc, 
						NULL, 
						MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_phb_ds_parent_id = GRP_ID_PHB_DIALER_SEARCH;

    mmi_phb_ds_entry_op_send_mms();
}
#endif
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_add_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_add_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_ENTRY_OP_ADD_CONTACT);

    g_mmi_phb_ds_call_from_option = MMI_TRUE;

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {
		mmi_phb_ds_do_calllog_action(MMI_CLOG_ACT_SAVE_TO_PHB);
    }
     mmi_phb_ds_delete_option_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_entry_op_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DS_ENTRY_OP_VIEW);

    g_mmi_phb_ds_call_from_option = MMI_TRUE;

    if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.name_count)
    {
        /* 2.1 --- highlight in name field*/
        store_index = g_mmi_phb_ds_context.list_cntx.entry[g_mmi_phb_ds_highlight_index].store_index;
        g_mmi_phb_ds_context.store_index = store_index;

        /* before enter view entry screen, need to set active index first */
        cui_phb_view_contact(GRP_ID_PHB_DIALER_SEARCH, store_index);
    }
    else if (g_mmi_phb_ds_highlight_index < g_mmi_phb_ds_context.list_cntx.callog_count + g_mmi_phb_ds_context.list_cntx.name_count)
    {
		mmi_phb_ds_do_calllog_action(MMI_CLOG_ACT_VIEW);
    }
    else
    {
        mmi_phb_ds_get_num_index(g_mmi_phb_ds_highlight_index, &store_index);
        g_mmi_phb_ds_context.store_index = store_index;
        cui_phb_view_contact(GRP_ID_PHB_DIALER_SEARCH, store_index);
    }
    mmi_phb_ds_delete_option_scr();
}


#ifdef __MMI_FTE_SUPPORT__
void mmi_phb_ds_fte_entry_op_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create_ex(mmi_frm_group_get_active_id(),
							GRP_ID_PHB_DIALER_SEARCH,
							mmi_phb_dialer_search_group_proc,
							NULL,
							MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_phb_ds_parent_id = GRP_ID_PHB_DIALER_SEARCH;
    mmi_phb_ds_entry_op_view();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_reset_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_reset_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&g_mmi_phb_ds_context.list_cntx, 0, sizeof(srv_phb_ds_list_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_find_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_phb_ds_find_entry(UI_buffer_type keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_DIALER_SEARCH_FIND_ENTRY);

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        return 0;
    }
    return srv_phb_ds_search_entry((WCHAR*)keyword, &(g_mmi_phb_ds_context.list_cntx));
}

static void mmi_phb_ds_close_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const WCHAR* dial_string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_dialer_is_active_if_any() && (cui_dialer_get_type_if_any() == CUI_DIALER_TYPE_SEARCH))
    {
        dial_string = cui_dialer_get_dial_string_if_any();
        if(dial_string)
		{
			wgui_cat203_refresh_search_list((U8 *)dial_string);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_upd_contact_at_proc
 * DESCRIPTION
 *  screen group caller group agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_ds_upd_contact_at_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_ds_close_process();

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_at_proc
 * DESCRIPTION
 *  screen group caller group agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_ds_del_contact_at_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_ds_close_process();
	
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_startup_ready_proc
 * DESCRIPTION
 *  screen group caller group agent callback function
 * PARAMETERS
 *  param        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_ds_startup_ready_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_evt_struct *evt = (srv_phb_startup_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->phb_ready)
    {
		mmi_phb_ds_close_process();
    }

    return 0;
}


mmi_ret mmi_phb_dialer_search_sim_profile(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct * sim_evt =
        (srv_sim_ctrl_availability_changed_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
        || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
        || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        cui_dialer_close_if_present();
    }
    return MMI_RET_OK;
}
#endif /* __MMI_DIALER_SEARCH__ */
#endif /* _PHONEBOOKSEARCH_C */

