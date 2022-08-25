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
 * ProvBoxAppUtil.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox app utility procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMIDataType.h"

#include "mmi_frm_utility_gprot.h"

#include "APPSDKSystemServiceGprot.h" //adm api
 
#include "UcmSrvGprot.h"

#include "UmSrvDefs.h"

#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"

/* compose data and time */
#include "APPSDKAppGProt.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"

#ifdef __MMI_WLAN_FEATURES__
#include "NetSetAppGprot.h"
#endif

#include "mmi_rp_app_provbox_def.h"
#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Local function
 *****************************************************************************/

/*===========================================================================
 * ProvBoxApp Memory handler
 *==========================================================================*/

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_provbox_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    p = OslMalloc((kal_uint32) size);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(p);

    OslMfree(p);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
KAL_ADM_ID mmi_provbox_mem_init(U32 buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KAL_ADM_ID adm_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    adm_id = kal_adm_create((void*)buffer,
                 (kal_uint32) MMI_PROVBOX_MAX_MEM_SIZE,
                 NULL, MMI_FALSE);

    MMI_ASSERT(adm_id);
    
    return adm_id;
}

/*===========================================================================
 * ProvBoxApp Memory handler end
 *==========================================================================*/

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_is_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_provbox_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0 ||
            srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
        {
            result = MMI_TRUE;
        }
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */ 
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL)  > 0)
        {
            result = MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_IS_IN_CALL, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_sims_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  > 0: there is one or more available sims
 *  = 0: all sims are unavailable
 *****************************************************************************/
U8 mmi_provbox_get_sims_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sims = MMI_SIM_ALL;
    U8 mark = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (sims)
    {
        if (srv_sim_ctrl_is_available(sims & mark))
            break;
        sims = sims & ~mark;
        mark = mark * 2;
    }

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_SIMS_STATUS, sims);

    return sims;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_is_item_shown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_provbox_is_item_shown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_provbox_is_ready())
    {
       return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_is_unread_msg
 *
 * DESCRIPTION
 *  this function is to check if provisioning message is unread
 *
 * PARAMETERS
 *  srv_provbox_msg_read_status_enum      [IN]
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_provbox_is_unread_msg(srv_provbox_msg_read_status_enum read_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_IS_UNREAD_MSG, read_status);

    return read_status == SRV_PROVBOX_MSG_READ_STATUS_UNREAD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_compose_data_time
 *
 * DESCRIPTION
 *  this function is to get the right string of data time by the sepcial format
 *
 * PARAMETERS
 *  WCHAR*      [OUT]
 *  U32         [OUT]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_compose_data_time(WCHAR* data_time, U32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 local_sec = 0;
    applib_time_struct time = {0};
    U8 dttemp[MMI_PROVBOX_DATE_TIME_BUF_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* date */
    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);

    memset(dttemp, 0x00, MMI_PROVBOX_DATE_TIME_BUF_SIZE);
    date_string((MYTIME*) & time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((CHAR*) data_time, (const CHAR*) dttemp);
    mmi_ucs2cat((CHAR*) data_time, (const CHAR*) MMI_PROVBOX_UCS2_SPACE);

    /* time */
    memset(dttemp, 0x00, MMI_PROVBOX_DATE_TIME_BUF_SIZE);
    time_string((MYTIME*) & time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((CHAR*) data_time, (const CHAR*) dttemp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_compose_properties
 *
 * DESCRIPTION
 *  this function is to get the right string of message propertiest by 
 *  the sepcial format
 *
 * PARAMETERS
 *  WCHAR*                                   [OUT]
 *  srv_provbox_msg_cmn_info_struct*         [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_compose_properties(WCHAR* properties, srv_provbox_msg_cmn_info_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR data_time[MMI_PROVBOX_DATE_TIME_BUF_SIZE * 2] = {0};
    WCHAR address[MMI_PROVBOX_ADDR_MAX_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!properties || !data)
    {
        return;
    }

    properties[0] = 0x0000;

    /* From: */
    mmi_ucs2cpy((CHAR*) properties, (const CHAR *)get_string(STR_ID_PROVBOX_FROM));
    /* New line */
    mmi_ucs2cat((CHAR*) properties, (const CHAR *)MMI_PROVBOX_UCS2_NEW_LINE);

    /* sender address */
    mmi_provbox_get_msg_address(address, (mmi_sim_enum)data->sim_id, data->msg_type, &data->sender_addr);

    mmi_ucs2cat((CHAR*) properties, (const CHAR*) address);

    /* empty line */
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);

    /* Received: */
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) get_string(STR_ID_PROVBOX_RECEIVE));
    /* New line */
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);

    /* data and time */
    data_time[0] = '\0';
    mmi_provbox_compose_data_time(data_time, data->timestamp);
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) data_time);
    
    /* empty line */
    mmi_ucs2cat((CHAR*) properties, (const CHAR *) MMI_PROVBOX_UCS2_NEW_LINE);
    mmi_ucs2cat((CHAR*) properties, (const CHAR *) MMI_PROVBOX_UCS2_NEW_LINE);

    if (data->install_time != SRV_PROVBOX_INVALID_TIME)
    {
        /* Install time: */
        mmi_ucs2cat((CHAR*) properties, (const CHAR *) get_string(STR_ID_PROVBOX_INSTALL_TIME));
        /* empty line */
        mmi_ucs2cat((CHAR*) properties, (const CHAR *) MMI_PROVBOX_UCS2_NEW_LINE);

        /* data and time */
        data_time[0] = '\0';
        mmi_provbox_compose_data_time(data_time, data->install_time);
        mmi_ucs2cat((CHAR*) properties, (const CHAR *) data_time);
    }
    else
    {
        /* Install time: */
        mmi_ucs2cat((CHAR*) properties, (const CHAR*) get_string(STR_ID_PROVBOX_INSTALL_TIME));
        /* empty line */
        mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);
        mmi_ucs2cat((CHAR*) properties, (const CHAR*) get_string(STR_ID_PROVBOX_NOT_INSTALLED));
    }

    /* empty line */
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);

    /* Message type: */
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) get_string(STR_ID_PROVBOX_MSG_TYPE));
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) MMI_PROVBOX_UCS2_NEW_LINE);
    mmi_ucs2cat((CHAR*) properties, (const CHAR*) get_string(STR_ID_PROVBOX_PROV_ITEM_NAME));    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_new_msg_idx
 *
 * DESCRIPTION
 *  this function is to get the index of new message
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_provbox_get_new_msg_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sim_to_index(mmi_provbox_get_new_msg_sim_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_new_msg_sim_id
 *
 * DESCRIPTION
 *  this function is to get the sim id of new message
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_provbox_get_new_msg_sim_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_provbox_get_msg_sim_id(srv_provbox_get_new_msg_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_msg_hilit_idx
 *
 * DESCRIPTION
 *  this function is to get the highlight index of message list menu
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_provbox_get_msg_hilit_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_MSG_HILIT_IDX, cntx->cur_hilit_idx);

    return cntx->cur_hilit_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_result_pboxsrv2mine
 *
 * DESCRIPTION
 *  this function is to transfer the result enum of provboxsrv to provboxapp
 *
 * PARAMETERS
 *  srv_provbox_result_enum [IN]
 *
 * RETURNS
 *  mmi_provbox_result_enum
 *****************************************************************************/
mmi_provbox_result_enum mmi_provbox_result_pboxsrv2mine(srv_provbox_result_enum srv_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (srv_result)
    {
        case SRV_PROVBOX_RESULT_OK:
            return MMI_PROVBOX_RESULT_OK;
            break;
        
        case SRV_PROVBOX_RESULT_FAIL:
            return MMI_PROVBOX_RESULT_FAIL;
            break;
            
        case SRV_PROVBOX_RESULT_MEM_FULL:
            return MMI_PROVBOX_RESULT_MEM_FULL;
            break;
            
        case SRV_PROVBOX_RESULT_BOX_FULL:
            return MMI_PROVBOX_RESULT_BOX_FULL;
            break;
            
        case SRV_PROVBOX_RESULT_NOT_FOUND:
            return MMI_PROVBOX_RESULT_MSG_NOT_FOUND;
            break;
            
        case SRV_PROVBOX_RESULT_PARTIAL_DELETED:
            return MMI_PROVBOX_RESULT_PARTIAL_DELETED;
            break;
            
        case SRV_PROVBOX_RESULT_READING:
            return MMI_PROVBOX_RESULT_READING_MSG;
            break;
            
        default:
            break;            
    }
    return MMI_PROVBOX_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_msg_address
 *
 * DESCRIPTION
 *  this function is to get the right message address
 *
 * PARAMETERS
 *  WCHAR *         [OUT]
 *  mmi_sim_enum    [IN]
 *  srv_provbox_msg_type_enum [IN]
 *  srv_provbox_addr_struct*  [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_get_msg_address(
         WCHAR *addr, mmi_sim_enum sim_id,
         srv_provbox_msg_type_enum msg_type, 
         srv_provbox_addr_struct* msg_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *name = NULL;
    S32 len;
    U16 str_id = mmi_provbox_get_sim_msg_title(mmi_frm_sim_to_index(sim_id));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_GET_MSG_ADDRESS, sim_id, msg_type);

    switch (msg_type)
    {
        case SRV_PROVBOX_MSG_TYPE_SIM_MMSICP:
            name = (WCHAR*) get_string(str_id);
            break;

        default:
            if (mmi_wcslen((const WCHAR*)msg_addr->addr) > 0)
            {
                name = (WCHAR*) msg_addr->addr;
            }
            else
            {
                name = (WCHAR*) get_string(STR_ID_PROVBOX_NO_NUMBER);
            }
            break;
    }
    
    len = mmi_wcslen((WCHAR*) name);

    if (len < MMI_PROVBOX_ADDR_MAX_LEN)
    {
        mmi_wcscat((WCHAR*) addr, (const WCHAR*) name);
    }
    else
    {
        mmi_wcsncat((WCHAR*) addr, (const WCHAR*) name, MMI_PROVBOX_ADDR_MAX_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_ip_addr_is_validate
 *
 * DESCRIPTION
 *  this function is to check if the format ip address is right
 *
 * PARAMETERS
 *  U16 *         [IN]
 *  S32           [IN]
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_provbox_ip_addr_is_validate(U16 *ip, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *p;
    U16 tmp = 0;
    S32 seg_len = 0;
    S32 seg_val = 0;
    U16 *seg_p;
    S32 read_len;
    S32 seg_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > MMI_PROVBOX_IP_MAX_LEN)
    {
        return MMI_FALSE;
    }

    p = ip;
    seg_p = ip;
    seg_num = 1;
    while(p)
    {
        if (*p == MMI_PROVBOX_IP_DOT ||
            *p == 0)
        {
            if (*p != 0)
            {
                tmp = *p;
                *p = 0;
            }
            mmi_ucs2toi((const CHAR*) seg_p, &seg_val, &read_len);
            if (seg_val > MMI_PROVBOX_IP_MAX_SEG_VAL)
            {
                *p = tmp;
                return MMI_FALSE;

            }

            if (tmp != 0)
            {
                *p = tmp;
                tmp = 0;
            }

            if (*p == 0)
            {
                return MMI_TRUE;
            }
            p++;
            seg_p = p;
            seg_len = 0;
            seg_num++;
            if (seg_num > MMI_PROVBOX_IP_MAX_SEG_NUM)
            {
                return MMI_FALSE;    
            }
            continue;
        }
        else
        {
            p++;
            seg_len++;
            if (seg_len > MMI_PROVBOX_IP_MAX_SEG_LEN)
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_FALSE;
}


#ifdef __MMI_PROV_IN_UM__


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_box_type_pbox2um
 *
 * DESCRIPTION
 *  this function is to transfer box type from provboxapp to UM
 *
 * PARAMETERS
 *  srv_provbox_box_type_enum         [IN]
 *
 * RETURNS
 *  srv_um_msg_box_enum
 *****************************************************************************/
srv_um_msg_box_enum mmi_provbox_box_type_pbox2um(srv_provbox_box_type_enum srv_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum um_box_type = SRV_UM_MSG_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (um_box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            um_box_type = SRV_UM_MSG_BOX_INBOX;
            break;
            
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            um_box_type = SRV_UM_MSG_BOX_ARCHIVE;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */
            
        case SRV_PROVBOX_BOX_TYPE_ALL:
            um_box_type = SRV_UM_MSG_BOX_ALL;
            break;
        
        default:
            break;
    }
    
    return srv_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_add_address
 *
 * DESCRIPTION
 *  this function is to add address for UM request
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_add_address(
         srv_um_msg_detail_struct* detail,
         WCHAR* addr,
         srv_um_addr_enum type,
         srv_um_addr_group_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (detail->address.addr == NULL)
    {
        detail->address.addr = addr;
        detail->address.next = detail->address.previous = NULL;
        detail->address.type = type;
        detail->address.group = group;
    }
    else
    {
        detail->address.addr = addr;
        detail->address.group = group;
        detail->address.next  = NULL;
        detail->address.previous = NULL;
        detail->address.type = type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_remove_address
 *
 * DESCRIPTION
 *  this function is to remove the related address
 *
 * PARAMETERS
 *  srv_um_msg_detail_struct*         [OUT]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_remove_address(srv_um_msg_detail_struct* detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_addr_struct *last_address = &detail->address;
    srv_um_addr_struct *prev_address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == detail || NULL == detail->address.addr)
    {
        return;
    }
    
    while (last_address->next != NULL)
    {
        last_address = last_address->next;
    }
    
    prev_address = last_address->previous;
    
    mmi_provbox_free(last_address);
    
    prev_address->next = NULL;    
}

#endif /* __MMI_PROV_IN_UM__ */


#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
