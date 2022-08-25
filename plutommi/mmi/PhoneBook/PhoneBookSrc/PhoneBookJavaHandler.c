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
 *  PhoneBookHandlerJava.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for providing phonebook interface for java package
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef MMI_PHONEBOOKJAVAHANDLER_C
#define MMI_PHONEBOOKJAVAHANDLER_C
#include "PhbSrvGprot.h"
#include "PhoneBookProt.h"
#ifdef __J2ME__
#include "Jpim_interface.h"
#include "j2me_custom_option.h"
#endif
#include "PhoneBookJavahandler.h"

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
#include "app_datetime.h"
#endif

#if defined(JSR_75_PIM_EXTRA_IMAGE) && defined(__MMI_FILE_MANAGER__)
#include "Drm_gprot.h"
#include "App_mine.h"
#endif /* defined(JSR_75_PIM_EXTRA_IMAGE) && defined(__MMI_FILE_MANAGER__) */

#include "simctrlsrvgprot.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_java_build_contact_info(srv_phb_contact_info_struct* contact_info, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(contact_info, 0, sizeof(srv_phb_contact_info_struct));
    contact_info->field_mask = (SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_ENTRY_FIELD_GROUP | SRV_PHB_ENTRY_FIELD_DEF);

    contact_info->field_data.name = entry->name;
    contact_info->field_data.number = entry->number;

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    contact_info->field_mask |= (SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM | SRV_PHB_ENTRY_FIELD_COMPANY | SRV_PHB_ENTRY_FIELD_EMAIL1);
    contact_info->field_data.opt_num[0] = &(entry->opt_num[0]);
    contact_info->field_data.opt_num[1] = &(entry->opt_num[1]);
    contact_info->field_data.opt_num[2] = &(entry->opt_num[2]);
    contact_info->field_data.company_name = entry->companyName;
    contact_info->field_data.email_address = entry->emailAddress;
#if defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL2;
    contact_info->field_data.email_address2 = entry->emailAddress2;
#endif /* defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
#else /* clear buffer */
    entry->homeNumber[0] = 0;
    entry->companyName[0] = 0;
    entry->emailAddress[0] = 0;
#if defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    entry->emailAddress2[0] = 0;
#endif /* defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
    entry->officeNumber[0] = 0;
    entry->faxNumber[0] = 0;
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
#if defined(__MMI_PHB_DEFAULT_NUMBER__) && defined(JSR_75_PIM_EXTRA_PREFERRED_NUMBER)
    contact_info->field_data.default_number = entry->preferred_no;
#else
    contact_info->field_data.default_number = 0xff;
#endif

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_BDAY;
    contact_info->field_data.b_year = entry->bDay.nYear;
    contact_info->field_data.b_month = entry->bDay.nMonth;
    contact_info->field_data.b_day = entry->bDay.nDay;
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* JSR_75_PIM_EXTRA_BIRTHDAY */

#if defined(JSR_75_PIM_EXTRA_INFO)
#if defined(__MMI_PHB_INFO_FIELD__)
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_INFO;
    contact_info->field_data.title = entry->title;
    contact_info->field_data.url = entry->url;
    contact_info->field_data.pobox = entry->adrPOBox;
    contact_info->field_data.extension = entry->adrExtension;
    contact_info->field_data.street = entry->adrStreet;
    contact_info->field_data.city = entry->adrCity;
    contact_info->field_data.state = entry->adrState;
    contact_info->field_data.postalcode = entry->adrPostalCode;
    contact_info->field_data.country = entry->adrCountry;
    contact_info->field_data.note = entry->note;
#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* defined(JSR_75_PIM_EXTRA_INFO) */

#ifdef JSR_75_PIM_EXTRA_IMAGE
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_PIC;
    contact_info->field_data.image_path = entry->phb_image_path;
	if (entry->phb_image_path[0])
	{
        contact_info->field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_FILE;
    }
#endif
    contact_info->field_data.group_mask = entry->group_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_java_get_contact_info(U16 store_index, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->store_index = store_index;
    mmi_phb_java_build_contact_info(&contact_info, entry);
    srv_phb_oplib_get_contact_info((U16)store_index, &contact_info);
#if defined(__MMI_PHB_DEFAULT_NUMBER__) && defined(JSR_75_PIM_EXTRA_PREFERRED_NUMBER)
    entry->preferred_no = contact_info.field_data.default_number;
#endif
    entry->group_id = contact_info.field_data.group_mask;

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    entry->bDay.nYear = contact_info.field_data.b_year;
    entry->bDay.nMonth = contact_info.field_data.b_month;
    entry->bDay.nDay = contact_info.field_data.b_day;
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* JSR_75_PIM_EXTRA_BIRTHDAY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_write_rsp(U8 result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_rsp_struct *msg_ptr;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_set_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_entry_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->store_index = store_index;

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_JASYN;
    message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP;
    message.oslDataPtr = (oslParaType*)msg_ptr;
    message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_write_cb(S32 result, U16 store_index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 java_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        java_result = MMI_PHB_JAVA_SUCCESS;
    }
    else if (result == SRV_PHB_NUMBER_TOO_LONG)
    {
        java_result = MMI_PHB_JAVA_NUMBER_TOO_LONG;
    }
    else if (result == SRV_PHB_ADN_FORBID || result == SRV_PHB_SIM2_ADN_FORBID)
    {
        java_result = MMI_PHB_JAVA_ADN_FORBID;
    }
    else
    {
        java_result = MMI_PHB_JAVA_ERROR;
    }
    mmi_phb_java_write_rsp(java_result, store_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_java_check_entry_data(mmi_phb_handler_entry_struct* entry, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_remove_invalid_name(entry->name);
    srv_phb_remove_invalid_number(entry->number);

    srv_phb_truncate_name(entry->name, storage);
    srv_phb_truncate_number(entry->number);
    if ((!entry->name[0] && !entry->number[0]) ||
        (!srv_phb_check_valid_number(entry->number)))
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
        return MMI_FALSE;
    }
    if (storage != PHB_STORAGE_NVRAM)
    {
        return MMI_TRUE;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    srv_phb_remove_invalid_number(entry->homeNumber);
    srv_phb_remove_invalid_number(entry->officeNumber);
    srv_phb_remove_invalid_number(entry->faxNumber);

    srv_phb_truncate_number(entry->homeNumber);
    srv_phb_truncate_number(entry->officeNumber);
    srv_phb_truncate_number(entry->faxNumber);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
    if ((!srv_phb_check_valid_number(entry->homeNumber)) ||
        (!srv_phb_check_valid_number(entry->officeNumber)) ||
        (!srv_phb_check_valid_number(entry->officeNumber)))
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
        return MMI_FALSE;
    }

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
	if (entry->bDay.nYear || entry->bDay.nMonth || entry->bDay.nDay|| entry->bDay.nHour ||
        entry->bDay.nMin || entry->bDay.nSec || entry->bDay.DayIndex)
	{
        if (!applib_dt_check_valid_by_app(MMI_PHB_BDAY_MIN_YEAR_INT, MMI_PHB_BDAY_MAX_YEAR_INT, &(entry->bDay)))
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_BIRTHDAY_ERROR, 0xffff);
            return MMI_FALSE;
        }
	}

#endif /* def __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* def JSR_75_PIM_EXTRA_BIRTHDAY */

#if defined(JSR_75_PIM_EXTRA_IMAGE)
#if defined(__MMI_FILE_MANAGER__)
    if (entry->phb_image_path[0])
    {
        do
        {
            FS_HANDLE fh;
            MMI_BOOL drm_ret = MMI_TRUE;
            fh = DRM_open_file((kal_wchar*)entry->phb_image_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
            
            if (fh >= FS_NO_ERROR)
            {
            #ifdef __DRM_SUPPORT__
                drm_ret = (MMI_BOOL)DRM_validate_forward_rule(fh, DRM_PERMISSION_DISPLAY);
            #endif
                if (drm_ret == MMI_TRUE)
                {
                    break;
                }
                DRM_close_file(fh);
            }

            mmi_phb_java_write_rsp(MMI_PHB_JAVA_IMAGE_ERROR, 0xffff);
            return MMI_FALSE;
        } while (0);
    }
#endif /* __MMI_FILE_MANAGER__ */
#endif /* defined(JSR_75_PIM_EXTRA_IMAGE) */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_write_req
 * DESCRIPTION
 *  This function write a phonebook entry from JAVA request
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_write_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_set_entry_req_struct*) info;

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        mmi_phb_java_write_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
    /* get storage for [Add] operation. */
    if (local_ptr->index == 0xffff)
    {
        if (((local_ptr->storage == PHB_STORAGE_SIM) && !srv_sim_ctrl_is_available(MMI_SIM1))
    #if (MMI_MAX_SIM_NUM >= 2)
            || ((local_ptr->storage == PHB_STORAGE_SIM2) && !srv_sim_ctrl_is_available(MMI_SIM2))
    #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            || ((local_ptr->storage == PHB_STORAGE_SIM3) && !srv_sim_ctrl_is_available(MMI_SIM3))
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            || ((local_ptr->storage == PHB_STORAGE_SIM4) && !srv_sim_ctrl_is_available(MMI_SIM4))
        #endif
            )
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_NO_SIM_CARD, 0xffff);
            return;
        }
    
        if (srv_phb_get_used_contact(local_ptr->storage) == srv_phb_get_total_contact(local_ptr->storage))
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_STORAGE_FULL, 0xffff);
            return;
        }
        /* Check free space and assign storage location */
        if (local_ptr->storage == PHB_STORAGE_MAX)
        {
            local_ptr->storage = (U8)mmi_phb_get_preferred_storage();
            if (local_ptr->storage == PHB_STORAGE_MAX)
            {
                local_ptr->storage = PHB_STORAGE_NVRAM;
            }
            if (srv_phb_get_used_contact(local_ptr->storage) == srv_phb_get_total_contact(local_ptr->storage))
            {
                if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM) != srv_phb_get_total_contact(PHB_STORAGE_NVRAM))
                {
                    local_ptr->storage = PHB_STORAGE_NVRAM;
                }
                else if (srv_phb_get_used_contact(PHB_STORAGE_SIM) != srv_phb_get_total_contact(PHB_STORAGE_SIM))
                {
                    local_ptr->storage = PHB_STORAGE_SIM;
                }
        #if (MMI_MAX_SIM_NUM >= 2)
                else if (srv_phb_get_used_contact(PHB_STORAGE_SIM2) != srv_phb_get_total_contact(PHB_STORAGE_SIM2))
                {
                    local_ptr->storage = PHB_STORAGE_SIM2;
                }
        #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                else if (srv_phb_get_used_contact(PHB_STORAGE_SIM3) != srv_phb_get_total_contact(PHB_STORAGE_SIM3))
                {
                    local_ptr->storage = PHB_STORAGE_SIM3;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                else if (srv_phb_get_used_contact(PHB_STORAGE_SIM4) != srv_phb_get_total_contact(PHB_STORAGE_SIM4))
                {
                    local_ptr->storage = PHB_STORAGE_SIM4;
                }
            #endif
            }
        }
    }
    /* [Delete] operation. */
    if (local_ptr->entry_ptr == NULL)
    {
        srv_phb_oplib_delete_contact(local_ptr->index, mmi_phb_java_write_cb, NULL);
    }
    else
    {
        srv_phb_contact_info_struct contact_info;
        if (local_ptr->index != 0xffff)
        {
            if (srv_phb_check_entry_exist(local_ptr->index))
            {
                local_ptr->storage = srv_phb_get_storage(local_ptr->index);
            }
            else
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0xffff);
                return;
            }
        }
        if (!mmi_phb_java_check_entry_data(local_ptr->entry_ptr, local_ptr->storage))
        {
            return;
        }
        mmi_phb_java_build_contact_info(&contact_info, local_ptr->entry_ptr);
        /* [Add] operation. */
        if (local_ptr->index == 0xffff)
        {
            srv_phb_oplib_add_contact(local_ptr->storage, SRV_PHB_INVALID_INDEX, &contact_info, mmi_phb_java_write_cb, NULL);
        }
        /* [Update] operation. */
        else
        {
            srv_phb_oplib_update_contact(local_ptr->index, &contact_info, mmi_phb_java_write_cb, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_read_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_read_rsp(U8 result, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_entry_rsp_struct *msg_ptr;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_get_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_entry_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->count = count;

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_JASYN;
    message.oslMsgId = MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP;
    message.oslDataPtr = (oslParaType*) msg_ptr;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_read_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_read_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 count = 0;
    U16 store_index = 0;
    mmi_phb_handler_get_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_get_entry_req_struct*) info;

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        mmi_phb_java_read_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
    /*
     * Get entry data
     */
    if ((local_ptr->count > 0) && (local_ptr->entry_ptr != NULL))
    {
        /*
         *  Check valid index first.
         */
         U16 max = srv_phb_get_used_contact(local_ptr->storage);
         index = local_ptr->index;
        if (index > max)
        {
            mmi_phb_java_read_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0);
            return;
        }

        /* Sort By NAME */
        if (local_ptr->sort_type == MMI_PHB_BY_NAME)
        {
            count = 0;
            while ((index <= max) && (count < local_ptr->count))
            {
                store_index = srv_phb_sort_index_to_store_index(local_ptr->storage, index);
                local_ptr->entry_ptr[count].sort_index = index;
                mmi_phb_java_get_contact_info(store_index, &local_ptr->entry_ptr[count++]);
            }

            mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
    }
    /*
     * Get total count by storage, no need to return data.
     */
    else if (local_ptr->count == 0)
    {
        mmi_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, srv_phb_get_used_contact(local_ptr->storage));
        return;   
    }

    /* Error */
    mmi_phb_java_read_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_search_rsp(U8 result, U16 sort_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_search_entry_rsp_struct *msg_ptr;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr =
        (mmi_phb_handler_search_entry_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_phb_handler_search_entry_rsp_struct));

    /* Decide error cause */
    msg_ptr->result = result;
    msg_ptr->index = sort_index;

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_JASYN;
    message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP;
    message.oslDataPtr = (oslParaType*) msg_ptr;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_search_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    srv_phb_search_type_enum search_type;
    mmi_phb_handler_search_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_search_entry_req_struct*) info;

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }

    /* Check if search pattern empty */
    if (!local_ptr->pattern[0] && !local_ptr->pattern[1])
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        return;
    }
    if (local_ptr->sort_type != MMI_PHB_BY_NAME)
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
        return;
    }

    /* Search by name */
    if (local_ptr->search_type == MMI_PHB_BY_NAME)
    {
        search_type = SRV_PHB_SEARCH_TYPE_NAME;
    }
    /* Search by number */
    else if (local_ptr->search_type == MMI_PHB_BY_NUMBER)
    {
        search_type = SRV_PHB_SEARCH_TYPE_NUM;
    }
    else
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
        return;
    }
    result = srv_phb_oplib_search((U16*)local_ptr->pattern, SRV_PHB_SEARCH_TYPE_NUM);
    if (result >= 0)
    {
        mmi_phb_java_get_contact_info((U16)result, local_ptr->entry_ptr);
        mmi_phb_java_search_rsp(
            MMI_PHB_JAVA_SUCCESS, 
            srv_phb_store_index_to_sort_index(local_ptr->storage, (U16)result));
    }
    else
    {
        mmi_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
    }
}


/*****************************************************************************
* FUNCTION
 *  mmi_phb_java_get_group_info_rsp
* DESCRIPTION
*   This function initializes phonebook handler app.
* PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
*  void
 *****************************************************************************/
void mmi_phb_java_get_group_info_rsp(U8 result, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_group_info_rsp_struct *msg_ptr;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_get_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_group_info_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->count = count;

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_JASYN;
    message.oslMsgId = MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP;
    message.oslDataPtr = (oslParaType*) msg_ptr;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_get_group_info_req
 * DESCRIPTION
 *  This function gets group information.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_get_group_info_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    mmi_phb_handler_get_group_info_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_get_group_info_req_struct*) info;

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }

#ifdef __MMI_PHB_CALLER_GROUP__
    /* Get entry data */
    if ((local_ptr->storage == PHB_STORAGE_MAX) || (local_ptr->storage == PHB_STORAGE_NVRAM))
    {
        if (local_ptr->group_ptr == NULL)
        {
            count = srv_phb_get_group_list(NULL, NULL, PHB_STORAGE_NVRAM);
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
        if ((local_ptr->max_group > 0) && (local_ptr->group_ptr != NULL))
        {
            /* Copy group information by assigned count number */
            S32 i;
            U8 group_array[MMI_PHB_GROUP_COUNT];
            U16 *group_name = OslMalloc((MMI_PHB_GROUP_NAME_LENGTH + 1) * MMI_PHB_GROUP_COUNT * sizeof(U16));
            count = srv_phb_get_group_list(group_array, group_name, PHB_STORAGE_NVRAM);
            count = count > local_ptr->max_group ? local_ptr->max_group : count;
            for (i = 0; i < count; i++)
            {
                local_ptr->group_ptr[i].group_id = group_array[i];
                mmi_wcscpy(
                    local_ptr->group_ptr[i].group_name,
                    group_name + i * (MMI_PHB_GROUP_NAME_LENGTH + 1));
            }
            OslMfree(group_name);
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }

    }
    else
    {
        if (local_ptr->group_ptr == NULL)
        {
            mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, 0);
            return;
        }
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
    mmi_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_rsp
 * DESCRIPTION
 *  This function return set group info result to JAVA
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_set_group_info_rsp(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_rsp_struct *msg_ptr;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_set_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_group_info_rsp_struct));

    msg_ptr->result = result;

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_JASYN;
    message.oslMsgId = MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP;
    message.oslDataPtr = (oslParaType*) msg_ptr;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_req
 * DESCRIPTION
 *  This function write a group name from JAVA request
 * PARAMETERS
 *  info        [IN]     
* RETURNS
*  void
*****************************************************************************/
void mmi_phb_java_set_group_info_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_req_struct *local_ptr;
    S32 result = SRV_PHB_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_set_group_info_req_struct*) info;
    if (!mmi_phb_check_ready(MMI_FALSE))
    {
       mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_NOT_READY);
       return;
    }

#ifdef __MMI_PHB_CALLER_GROUP__
    if (local_ptr->group_ptr != NULL)
    {
        srv_phb_group_info_struct group_info;
        if (local_ptr->group_id < MMI_PHB_GROUP_COUNT)
        {
            /* Update group name operation. */
            srv_phb_datamgr_get_group_info(local_ptr->group_id, &group_info);
            mmi_wcsncpy(group_info.group_name, (U16*)local_ptr->group_ptr->group_name, MMI_PHB_GROUP_NAME_LENGTH);

            result = srv_phb_update_group_info(local_ptr->group_id, &group_info);
        }
        else
        {
            /* add group */
            memset(&group_info, 0, sizeof(srv_phb_group_info_struct));
            mmi_wcsncpy(group_info.group_name, (U16*)local_ptr->group_ptr->group_name, MMI_PHB_GROUP_NAME_LENGTH);
            result = srv_phb_add_group(&group_info);
        }
    }
    else
    {
        srv_phb_delete_group(local_ptr->group_id);
        if (local_ptr->delete_list_ptr)
        {
            srv_phb_filter_struct filter;
            srv_phb_group_filter_struct group_filter;
            filter.storage = PHB_STORAGE_NVRAM;
            filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;
            filter.name_filter = NULL;
            filter.qsearch_filter = NULL;
            filter.group_filter = &group_filter;
            group_filter.group_mask = 0xFFFF;
            group_filter.is_equal = MMI_FALSE;
            result = srv_phb_oplib_build_contact_list(&filter, local_ptr->delete_list_ptr->list, MMI_PHB_PHONE_ENTRIES);
            local_ptr->delete_list_ptr->count = result;
        }
    }
    if (result >= 0)
    {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_SUCCESS);
    }
    else
    {
        mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
    }
#else /* __MMI_PHB_CALLER_GROUP__ */
    mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
#endif /* __MMI_PHB_CALLER_GROUP__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_handler_init
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_java_handler_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_phb_java_write_req, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_read_req, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_search_req, MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ);
    SetProtocolEventHandler(mmi_phb_java_get_group_info_req, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ);
    SetProtocolEventHandler(mmi_phb_java_set_group_info_req, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);
}
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
#endif /* MMI_PHONEBOOKJAVAHANDLER_C */ 
