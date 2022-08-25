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
 *  PhoneBookPBAP.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
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
#if defined(__MMI_PBAP_SUPPORT__) && defined(__MMI_VCARD__)

#include "Conversions.h"
#include "FileMgrSrvGProt.h"
#include "SettingProfile.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#include "PhbSrvGprot.h"
#include "PhoneBookPBAP.h"
#include "vcard_lib.h"

#include "vcard.h"
#include "vobjects.h"
#include "CallManagementStruct.h"
#include "CallLogSrvGprot.h"
#include "App_usedetails.h"
#include "Bluetooth_struct.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "MMI_common_app_trc.h"
#include "PhoneBookGprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "string.h"
#include "ps_public_enum.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
/* auto add by kw_check end */

mmi_phb_get_info_struct g_phb_get_info;

/* for build vcard */
mmi_vcard_filter_struct build_filter;
U8 build_format;

/* for sort */
static U16 pbap_sort_index[MMI_PHB_ENTRIES + 1]; /* 1 for quick sort */

static S32 mmi_phb_write_owner_number_vcard(U16* path, MMI_BOOL is_append, U8 vcard_format);
static void mmi_phb_get_call_history_build_vcard(MMI_BOOL result, U8 count);
static void mmi_phb_sort_by_index(U16* index_array, U16 count);
static S32 mmi_phb_write_call_history_vcard(U16* path, srv_clog_log_struct* log, MMI_BOOL is_append, U8 vcard_format);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_vcard
 * DESCRIPTION
 *  build vcard to the path
 * PARAMETERS
 *  path            [IN]        vcard file path(the file must be exist before)
 *  vcard_object    [IN]        which vcard object to be built.
 *  is_append       [IN]        TRUE: write to the file tail, FALSE: write to begin
 *  build_done_cb   [IN]        call back function, return result struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_vcard(
        U16* path,
        mmi_vcard_object_struct* vcard_object,
        MMI_BOOL is_append,
        mmi_phb_build_vcard_funcptr_type build_done_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error;
    FS_HANDLE fh;
    U8 call_num_type = SRV_CLOG_CLT_DEFAULT;
    S32 write_result = -1;
    U16 index = vcard_object->index_hdlr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_BUILD_VCARD);
    MMI_ASSERT(build_done_cb != NULL);
    
    error.error_code = PHB_VCARD_NO_ERROR;
    
    fh = FS_Open((U16*) path, FS_READ_WRITE);

    if (fh < 0)
    {
        error.error_code = PHB_VCARD_FS_ERROR;
        error.fs_error = fh;
        build_done_cb(&error);
        return;
    }
    else
    {
        FS_Close(fh);
    }

    memcpy(&build_filter, &(vcard_object->vcard_filter), VCARD_FIELD_MAX / 8);    
    switch (vcard_object->vcard_storage)
    {
        case PHB_STORAGE_NVRAM_PB:
            /* check phonebook ready */
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;                
                build_done_cb(&error);
                return;
            }

            /* write owner number */
            if (vcard_object->index_hdlr == 0)
            {
                write_result = mmi_phb_write_owner_number_vcard(path, is_append, vcard_object->vcard_format);
            }
            /* write phone entry */
            else
            {
                write_result = srv_phb_build_vcard(
                                    path, 
                                    (U16)(index - 1), 
                                    is_append,
                                    vcard_object->vcard_format);
            }

            if (write_result < 0)
            {
                error.error_code = PHB_VCARD_FS_ERROR;
                error.fs_error = write_result;
            }
            
            build_done_cb(&error);
            break;
        
        case PHB_STORAGE_SIM1_PB:
            /* check phonebook ready */
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;                
                build_done_cb(&error);
                return;
            }

            /* write sim entry */
            MMI_ASSERT(vcard_object->index_hdlr > 0);

            write_result = srv_phb_build_vcard(
                                path,
                                (U16)(index + MMI_PHB_PHONE_ENTRIES - 1), 
                                is_append, 
                                vcard_object->vcard_format);

            if (write_result < 0)
            {
                error.error_code = PHB_VCARD_FS_ERROR;
                error.fs_error = write_result;
            }
            
            build_done_cb(&error);
            break;
            
        case PHB_STORAGE_SIM1_OCH:
        case PHB_STORAGE_NVRAM_OCH:
            call_num_type = SRV_CLOG_CLT_DIALED;
            break;
            
        case PHB_STORAGE_SIM1_ICH:
        case PHB_STORAGE_NVRAM_ICH:
            call_num_type = SRV_CLOG_CLT_RECVED;
            break;
            
        case PHB_STORAGE_SIM1_MCH:        
        case PHB_STORAGE_NVRAM_MCH:
            call_num_type = SRV_CLOG_CLT_MISSED;
            break;
            
        case PHB_STORAGE_SIM1_CCH:        
        case PHB_STORAGE_NVRAM_CCH:    
            call_num_type = SRV_CLOG_CLT_ALL;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }

    if (call_num_type != SRV_CLOG_CLT_DEFAULT)
    {
        srv_clog_get_list_log_ids_req_struct req_data;
        srv_clog_get_list_log_ids_cnf_struct cnf_data;
        srv_clog_log_struct log;
        /* set the init value */
        error.error_code = PHB_VCARD_NOT_FOUND;
        
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);
        
        req_data.start_by = SRV_CLOG_BY_ID;
        req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;
        req_data.log_type = call_num_type;
        
        while(1)
        {
            req_data.start_elm = cnf_data.next_start_elm;
            if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
            {
                break;
            }
            if (index > cnf_data.log_num)
            {
                index -= cnf_data.log_num;
            }
            else
            {
                srv_clog_get_log_by_id(
                    0,
                    cnf_data.log_ids[index - 1],
                    SRV_CLOG_LOG_FIELD_NAME | SRV_CLOG_LOG_FIELD_CID | SRV_CLOG_LOG_FIELD_TIMESTAMP | SRV_CLOG_LOG_FIELD_IDENTITY,
                    &log);
                write_result = mmi_phb_write_call_history_vcard(path, &log, is_append, vcard_object->vcard_format);
                if (write_result < 0)
                {
                    error.error_code = PHB_VCARD_FS_ERROR;
                    error.fs_error = write_result;
                }
                else
                {
                    error.error_code = PHB_VCARD_NO_ERROR;
                }
                break;
            }            
            if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
            {
                break;
            }
        }
        build_done_cb(&error);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_by_index
 * DESCRIPTION
 *  sort phonebook entrys by store index
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sort_by_index(U16* index_array, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0, temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for enhance the sort */
    index_array[count] = 0xffff;

    while (i < count)
    {
        for (j = 0; j < count - i; j++)
        {
            if (index_array[j] > index_array[j + 1])
            {
                temp = index_array[j];
                index_array[j] = index_array[j + 1];
                index_array[j + 1] = temp;
            }
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_array
 * DESCRIPTION
 *  get phonebook index array by storage: phone, sim , call history
 * PARAMETERS
 *  vcard_storage           [IN]        must belong to mmi_phb_storage_enum, otherwise assert happen
 *  sort_order              [IN]        index, name. default is name
 *  index_array             [IN]        index buffer provided by caller
 *  index_array_size        [IN]        index buffer size
 *  get_index_array_cb      [IN]        call back function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_index_array(
        U8 vcard_storage,
        U8 sort_order,
        U16* index_array,
        U32 index_array_size,
        mmi_phb_get_index_array_funcptr_type get_index_array_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error;
    mmi_phb_my_number_struct my_card;
    S16 p_error;
    U8 call_num_type = SRV_CLOG_CLT_DEFAULT;
    U16 index_count = 0;
    U16 i = 0, j = 0;
    srv_phb_filter_struct filter;
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_GET_INDEX_ARRAY, vcard_storage);
    
    MMI_ASSERT(get_index_array_cb != NULL);
    MMI_ASSERT((index_array != NULL) && (index_array_size > 0));

    error.error_code = PHB_VCARD_NO_ERROR;

    /* set get info callback */
    switch (vcard_storage)
    {
        case PHB_STORAGE_NVRAM_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;
                get_index_array_cb(&error, index_array, 0);
                return;
            }
            
            index_count = srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
            ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, (void*)&my_card, sizeof(mmi_phb_my_number_struct), &p_error);
            if (my_card.number[0]
                || my_card.name[0]
            #if defined(__MMI_PHB_LAST_NAME_FIELD__)
                || my_card.l_name[0]
            #endif
                )
            {
                index_count++;
                index_array[0] = 0;
                j = 1;
            }
            
            if (index_count * sizeof(U16) > index_array_size)
            {
                index_count = index_array_size / 2;
            }
            memset(&filter, 0, sizeof(srv_phb_filter_struct));
            filter.storage = PHB_STORAGE_NVRAM;
            filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;
            count = (U16)srv_phb_oplib_build_contact_list(&filter, pbap_sort_index, MMI_PHB_ENTRIES);

            if (sort_order == PHB_SORT_ORDER_INDEX)
            {        
                mmi_phb_sort_by_index(pbap_sort_index, count);
            }
            for (i = 0; i < count && j < index_count; i++)
            {
                index_array[j] = pbap_sort_index[i] + 1;
                j++;
            }
            get_index_array_cb(&error, index_array, index_count);

            break;
        
        case PHB_STORAGE_SIM1_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;
                get_index_array_cb(&error, index_array, 0);
                return;
            }
            
            index_count = srv_phb_get_used_contact(PHB_STORAGE_SIM);
            
            if (index_count * sizeof(U16) > index_array_size)
            {
                index_count = index_array_size / 2;
            }
            memset(&filter, 0, sizeof(srv_phb_filter_struct));
            filter.storage = PHB_STORAGE_SIM;
            filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;
            count = (U16)srv_phb_oplib_build_contact_list(&filter, pbap_sort_index, MMI_PHB_ENTRIES);

            if (sort_order == PHB_SORT_ORDER_INDEX)
            {        
                mmi_phb_sort_by_index(pbap_sort_index, index_count);
            }
            {
                for (i = 0; i < index_count; i++)
                {
                    index_array[i] = pbap_sort_index[i] - MMI_PHB_PHONE_ENTRIES + 1;
                }
            }
            get_index_array_cb(&error, index_array, index_count);
            break;
            
        case PHB_STORAGE_SIM1_OCH:        
        case PHB_STORAGE_NVRAM_OCH:    
            call_num_type = SRV_CLOG_CLT_DIALED;
            break;
            
        case PHB_STORAGE_SIM1_ICH:        
        case PHB_STORAGE_NVRAM_ICH:    
            call_num_type = SRV_CLOG_CLT_RECVED;
            break;
            
        case PHB_STORAGE_SIM1_MCH:        
        case PHB_STORAGE_NVRAM_MCH:        
            call_num_type = SRV_CLOG_CLT_MISSED;
            break;
            
        case PHB_STORAGE_SIM1_CCH:        
        case PHB_STORAGE_NVRAM_CCH:    
            call_num_type = SRV_CLOG_CLT_ALL;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }

    if (call_num_type != SRV_CLOG_CLT_DEFAULT)
    {
        srv_clog_log_identity_struct identity;
        srv_clog_num_info_struct num_info;
        srv_clog_init_para(SRV_CLOG_PARA_IDENTITY, &identity);
        identity.sim_id = MMI_SIM1;
        identity.log_type = call_num_type;
        identity.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;

        if (srv_clog_get_list_num_info(0, &identity, &num_info) == 0)
        {
            index_count = num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];

            if (index_count * sizeof(U16) > index_array_size)
            {
                index_count = index_array_size / 2;
            }
            
            for (i = 0; i < index_count; i++)
            {
                index_array[i] = i + 1;
            }
        }
        else
        {
            error.error_code = PHB_VCARD_IN_USE;
        }
        get_index_array_cb(&error, index_array, index_count);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_info_by_index
 * DESCRIPTION
 *  get vcard 's name and number by index
 * PARAMETERS
 *  index_hdlr          [IN]        vcard index, begin from 1, except PB folder
 *  vcard_storage       [IN]        contact storage, contain call history
 *  get_info_cb         [IN]        get info call back hdlr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_info_by_index(
        U16 index_hdlr,
        U8 vcard_storage,
        mmi_phb_get_info_by_index_funcptr_type get_info_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error;
    mmi_phb_my_number_struct my_card;
    S16 p_error;
    U8 call_num_type = SRV_CLOG_CLT_DEFAULT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_GET_INFO_BY_INDEX, index_hdlr, vcard_storage);
    
    MMI_ASSERT(get_info_cb != NULL);
    
    /* set the init value */
    error.error_code = PHB_VCARD_NO_ERROR;
    
    memset(g_phb_get_info.name, 0, 2);
    memset(g_phb_get_info.number, 0, 2);

    switch (vcard_storage)
    {
        case PHB_STORAGE_NVRAM_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;
            }
            else
            {
                if (index_hdlr == 0)
                {
                    ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, (void*)&my_card, sizeof(mmi_phb_my_number_struct), &p_error);
                    srv_phb_convert_to_name(
                        (U16*)g_phb_get_info.name, 
                        my_card.name,
                    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
                        my_card.l_name,
                    #else
                        NULL,
                    #endif
                        MMI_PHB_NAME_LENGTH
                        );
                    mmi_wcscpy((U16*)g_phb_get_info.number, my_card.number);
                }
                else
                {
                    index_hdlr--;
                    
                    if (!srv_phb_check_entry_exist(index_hdlr))
                    {
                        error.error_code = PHB_VCARD_NOT_FOUND;
                    }
                    else
                    {
                        srv_phb_get_number(index_hdlr, (U16*)g_phb_get_info.number, MMI_PHB_NUMBER_PLUS_LENGTH);
                        srv_phb_get_name(index_hdlr, (U16*)g_phb_get_info.name, MMI_PHB_NAME_LENGTH);
                    }
                }
            }
            
            get_info_cb(&error, g_phb_get_info.name, g_phb_get_info.number);
            break;
        
        case PHB_STORAGE_SIM1_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;                
            }
            else
            {
                MMI_ASSERT(index_hdlr > 0);
                index_hdlr--;
                index_hdlr += MMI_PHB_PHONE_ENTRIES;
                
                if (!srv_phb_check_entry_exist(index_hdlr))
                {
                    error.error_code = PHB_VCARD_NOT_FOUND;
                }
                else
                {
                    srv_phb_get_number(index_hdlr, (U16*)g_phb_get_info.number, MMI_PHB_NUMBER_PLUS_LENGTH);
                    srv_phb_get_name(index_hdlr, (U16*)g_phb_get_info.name, MMI_PHB_NAME_LENGTH);
                }
            }
            
            get_info_cb(&error, g_phb_get_info.name, g_phb_get_info.number);
            break;
            
        case PHB_STORAGE_SIM1_OCH:        
        case PHB_STORAGE_NVRAM_OCH:    
            call_num_type = SRV_CLOG_CLT_DIALED;
            break;
            
        case PHB_STORAGE_SIM1_ICH:        
        case PHB_STORAGE_NVRAM_ICH:    
            call_num_type = SRV_CLOG_CLT_RECVED;
            break;
            
        case PHB_STORAGE_SIM1_MCH:        
        case PHB_STORAGE_NVRAM_MCH:        
            call_num_type = SRV_CLOG_CLT_MISSED;
            break;
            
        case PHB_STORAGE_SIM1_CCH:        
        case PHB_STORAGE_NVRAM_CCH:    
            call_num_type = SRV_CLOG_CLT_ALL;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }

    if (call_num_type != SRV_CLOG_CLT_DEFAULT)
    {
        srv_clog_get_list_log_ids_req_struct req_data;
        srv_clog_get_list_log_ids_cnf_struct cnf_data;
        srv_clog_log_struct log;
        /* set the init value */        
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);
        
        req_data.start_by = SRV_CLOG_BY_ID;
        req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;
        req_data.log_type = call_num_type;
        
        while(1)
        {
            req_data.start_elm = cnf_data.next_start_elm;
            if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
            {
                break;
            }
            if (index_hdlr > cnf_data.log_num)
            {
                index_hdlr -= cnf_data.log_num;
            }
            else
            {
                srv_clog_get_log_by_id(0, cnf_data.log_ids[index_hdlr - 1], SRV_CLOG_LOG_FIELD_NAME | SRV_CLOG_LOG_FIELD_CID, &log);
                error.error_code = PHB_VCARD_NO_ERROR;
                get_info_cb(&error, (CHAR*)(log.data.call_log.name), (CHAR*)(log.data.call_log.cid));
                return;
            }            
            if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
            {
                break;
            }
        }
        error.error_code = PHB_VCARD_NOT_FOUND;
        get_info_cb(&error, NULL, NULL);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_storage_size
 * DESCRIPTION
 *  get contact counts by storage, contain call history
 * PARAMETERS
 *  vcard_storage       [IN]            storage
 *  get_storage_size_cb [IN]            call back
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_storage_size(
        U8 vcard_storage,
        mmi_phb_get_storage_size_funcptr_type get_storage_size_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error;
    U16 size = 0;
    U8 call_num_type = SRV_CLOG_CLT_DEFAULT;
    mmi_phb_my_number_struct my_card;
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_GET_STORAGE_SIZE, vcard_storage);
    
    MMI_ASSERT(get_storage_size_cb != NULL);
    /* set the error code */
    error.error_code = PHB_VCARD_NO_ERROR;

    switch (vcard_storage)
    {
        case PHB_STORAGE_NVRAM_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;
            }
            else
            {
                size = srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
                ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, (void*)&my_card, sizeof(mmi_phb_my_number_struct), &p_error);
                if (my_card.number[0]
                    || my_card.name[0]
                #if defined(__MMI_PHB_LAST_NAME_FIELD__)
                    || my_card.l_name[0]
                #endif
                    )
                {
                    size++;
                }
            }
            break;
        
        case PHB_STORAGE_SIM1_PB:
            if (!mmi_phb_check_ready(MMI_FALSE))
            {
                error.error_code = PHB_VCARD_IN_USE;
            }
            else
            {                
                size = srv_phb_get_used_contact(PHB_STORAGE_SIM);
            }
            break;
            
        case PHB_STORAGE_SIM1_OCH:        
        case PHB_STORAGE_NVRAM_OCH:    
            call_num_type = SRV_CLOG_CLT_DIALED;
            break;
            
        case PHB_STORAGE_SIM1_ICH:        
        case PHB_STORAGE_NVRAM_ICH:    
            call_num_type = SRV_CLOG_CLT_RECVED;
            break;
            
        case PHB_STORAGE_SIM1_MCH:        
        case PHB_STORAGE_NVRAM_MCH:        
            call_num_type = SRV_CLOG_CLT_MISSED;
            break;
            
        case PHB_STORAGE_SIM1_CCH:        
        case PHB_STORAGE_NVRAM_CCH:    
            call_num_type = SRV_CLOG_CLT_ALL;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }

    if (call_num_type != SRV_CLOG_CLT_DEFAULT)
    {
        srv_clog_log_identity_struct identity;
        srv_clog_num_info_struct num_info;
        srv_clog_init_para(SRV_CLOG_PARA_IDENTITY, &identity);
        identity.sim_id = MMI_SIM1;
        identity.log_type = call_num_type;
        identity.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;

        if (srv_clog_get_list_num_info(0, &identity, &num_info) == 0)
        {
            size = num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];
        }
        else
        {
            error.error_code = PHB_VCARD_IN_USE;
        }
    }

    get_storage_size_cb(&error, size);
}         


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_new_missed_calls
 * DESCRIPTION
 *  get new missed calls count
 * PARAMETERS
 *  get_size_cb         [IN]            call back function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_new_missed_calls(mmi_phb_get_storage_size_funcptr_type get_size_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error;
    U16 size = 0;
    srv_clog_log_identity_struct identity;
    srv_clog_num_info_struct num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_size_cb != NULL);
    
    /* mmi_phb_get_storage_size_callback = get_size_cb; */

    /* set the init value */
    error.error_code = PHB_VCARD_NO_ERROR;
    srv_clog_init_para(SRV_CLOG_PARA_IDENTITY, &identity);
    identity.sim_id = MMI_SIM1;
    identity.log_type = SRV_CLOG_CLT_ALL;
    identity.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;

    if (srv_clog_get_list_num_info(0, &identity, &num_info) == 0)
    {
        size = num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
    }
    else
    {
        error.error_code = PHB_VCARD_IN_USE;
    }
    get_size_cb(&error, size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_write_owner_number_vcard
 * DESCRIPTION
 *  build phb owner number to vcard
 * PARAMETERS
 *  path            [IN]        store file path
 *  is_append       [IN]        write content to the tail of file or not
 * RETURNS
 *  S32                         write vcard result
 *****************************************************************************/
static S32 mmi_phb_write_owner_number_vcard(U16* path, MMI_BOOL is_append, U8 vcard_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_my_number_struct my_card;
    vcard_object_struct vcard_data;
    VB_HANDLE vb;
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_WRITE_OWNER_NUMBER_VCARD);

    ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, (void*)&my_card, sizeof(mmi_phb_my_number_struct), &error);

    if (!(build_filter.byte[VCARD_FILTER_EMAIL / 8] & (U8) (1 << (VCARD_FILTER_EMAIL % 8))))
    {
        my_card.emailAddress[0] = 0;
    }
    if (!(build_filter.byte[VCARD_FILTER_LOGO / 8] & (U8) (1 << (VCARD_FILTER_LOGO % 8))))
    {
        my_card.companyName[0] = 0;
    }

    memset(&vcard_data, 0, sizeof(vcard_object_struct));
    vcard_data.n.given = my_card.name,
    vcard_data.tel[0].tel = my_card.number;
    vcard_data.tel[0].type = VCARD_TEL_TYPE_CELL;
    if (my_card.homeNumber[0])
    {
        vcard_data.tel[1].tel = my_card.homeNumber;
        vcard_data.tel[1].type = VCARD_TEL_TYPE_HOME;
    }
    if (my_card.officeNumber[0])
    {
        vcard_data.tel[2].tel = my_card.officeNumber;
        vcard_data.tel[2].type = VCARD_TEL_TYPE_WORK;
    }
    if (my_card.faxNumber[0])
    {
        vcard_data.tel[3].tel = my_card.faxNumber;
        vcard_data.tel[3].type = VCARD_TEL_TYPE_FAX;
    }
    vcard_data.email[0].email = my_card.emailAddress;
    vcard_data.org.name = my_card.companyName;

    vb = vcard_open_builder(path, is_append, &result);
    if (!vb)
    {
        return result;
    }

    if (vcard_format == VCARD_FORMAT_30)
    {
        vcard_set_build_version(vb, VCARD_VERSION_3_0);
    }
    vcard_set_build_mode(vb, VCARD_BUILD_MODE_TEL_ALWAYS);

    result = vcard_build(vb, &vcard_data);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_build_error(vb);
        vcard_close_builder(vb);
        return result;
    }

    vcard_close_builder(vb);
    return VCARD_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_call_history_build_vcard
 * DESCRIPTION
 *  get call history data to build vcard
 * PARAMETERS
 *  result          [IN]        if 0 = success
 *  count           [IN]        call log contact counts
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_write_call_history_vcard(U16* path, srv_clog_log_struct* log, MMI_BOOL is_append, U8 vcard_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_object_struct vcard_data;
    VB_HANDLE vb;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&vcard_data, 0, sizeof(vcard_object_struct));
    vcard_data.n.given = log->data.call_log.name;
    vcard_data.tel[0].tel = log->data.call_log.cid;
    vcard_data.tel[0].type = VCARD_TEL_TYPE_CELL;

    if (build_filter.byte[VCARD_FILTER_TIMESTAMP / 8] & (U8) (1 << (VCARD_FILTER_TIMESTAMP % 8)))
    {
        U32 local_sec;
        local_sec = applib_dt_sec_utc_to_local(log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX]);
        applib_dt_utc_sec_2_mytime(local_sec, (applib_time_struct*)&(vcard_data.x.call_time), MMI_FALSE);
        vcard_data.x.call_type = log->data.call_log.log_type;
    }

    vb = vcard_open_builder(path, is_append, &result);
    if (!vb)
    {
        return result;
    }

    if (vcard_format == VCARD_FORMAT_30)
    {
        vcard_set_build_version(vb, VCARD_VERSION_3_0);
    }
    vcard_set_build_mode(vb, VCARD_BUILD_MODE_TEL_ALWAYS);

    result = vcard_build(vb, &vcard_data);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_build_error(vb);
        vcard_close_builder(vb);
        return result;
    }

    vcard_close_builder(vb);
    return VCARD_NO_ERROR;
}
#endif /* __MMI_PBAP_SUPPORT__ */ 

