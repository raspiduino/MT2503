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
 *  SmsUmBtMapProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Um Application For BT Header File
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MAP_CLIENT__

#include "SmsUmBtMapGProt.h"
#include "SmsUmBtMapProt.h"
#include "UmSrvDefs.h"
#include "UmSrvGprot.h"
#include "GlobalResDef.h"
#include "SmsBtMapCSrvGProt.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#include "mmi_rp_app_sms_def.h"
#include "Gui_effect_oem.h"

srv_um_get_msg_info_result g_res;
#define SRV_SMS_UM_MAX_GET_MSG_LIST_NUMBER 100
#define SRV_SMS_UM_MSG_LIST_POOL_SIZE 2
#define SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER 8
#define INDEX_OF_LISTCID(cid) ((cid) & 0xFF)
#define CHECK_PARA_VALID(value)                                 \
{                                                               \
    if (!(value))                                               \
    {                                                           \
        ASSERT(0);                                              \
        return SRV_UM_RESULT_INVALID_PARA;                      \
    }                                                           \
}
typedef struct
{
    srv_um_msg_enum msg_type;
    srv_um_msg_btmapc_box_enum msg_box_type;
    srv_um_bt_msg_info_struct msg_info;
} srv_sms_um_cache_struct;

//typedef union
//{
//    U8 cache_memory[SRV_UM_MIN_MSG_DETAIL_NUM * sizeof(srv_sms_um_cache_struct)];
//    U8 list_sort_memory[SRV_UM_LIST_SORT_MEMORY];
//} srv_sms_um_mem_pool_union;
//
//#define SRV_UM_MSG_DETAIL_NUM (sizeof(srv_sms_um_mem_pool_union)/sizeof(srv_sms_um_cache_struct) + 1)

#define SRV_UM_MSG_DETAIL_NUM MMI_MAX_MENUITEMS_IN_CONTENT * 3
#define SRV_UM_MAX_MSG_PER_PAGE MMI_MAX_MENUITEMS_IN_CONTENT
static S32 sms_msg_detail_idx[SRV_UM_MSG_DETAIL_NUM];
static srv_sms_um_cache_struct sms_msg_detail_pool[SRV_UM_MSG_DETAIL_NUM];


extern S32 g_pid;
extern S32 g_para;

typedef enum
{
    SRV_SMS_UM_LIST_TYPE_MSG_NODE,
    SRV_SMS_UM_LIST_TYPE_ALL
} srv_sms_um_list_type_enum;

typedef struct
{
    srv_um_list_idx_enum idx_type;              /* the index data type */
    srv_um_sort_order_enum order;               /* the order of sorting */
} srv_sms_um_list_filter_struct;



typedef struct
{
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
    srv_um_sim_enum sim_id;                 /* request to the corresponding sim card */
} srv_sms_um_bt_get_msg_num_req_struct;


typedef struct
{
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
    srv_um_msg_btmapc_box_enum msg_box_type;       /* Type of message box */
    kal_uint16 start_entry;                 /* From which entry to get list info. Start from 0 */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
} srv_um_get_bt_msg_list_req_struct;

typedef struct
{
    S32 error;                                      /* error code */
    union
    {
        S32 msg_number;                                 /* message number */
    }n;
} srv_sms_um_get_list_result;

typedef struct
{
    kal_uint32 timestamp;                   /* should be given in seconds since 1.Jan. 1970 GMT. If there is no timestamp information for the message, the field should be set to zero. */
    kal_uint32 msg_id;                      /* Message id is uniquely value to represent each message in different application. */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
} srv_um_bt_msg_list_struct;


typedef struct
{
    kal_uint32 app_id;                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;           /* Type of message */
    kal_bool result_t;                    /* KAL_TRUE means OK; KAL_FALSE means failed */
    srv_sms_um_get_list_result result;
    srv_um_msg_btmapc_box_enum msg_box_type;   /* Type of message box */
    kal_uint16 start_entry;             /* The first entry number in this response primitive */
    kal_uint16 msg_number;              /* Number of messages in this response primitive */
    srv_um_bt_msg_list_struct list_info[SRV_UM_MAX_GET_MSG_LIST_NUMBER];  /* List info array */
    kal_bool more;                      /* If there are more msgs besides this loop */
} srv_um_get_bt_msg_list_rsp_struct;

typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} srv_sms_um_get_msg_info_result;

typedef struct
{
    kal_uint32 app_id;                                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                           /* Type of message */
    srv_um_msg_btmapc_box_enum msg_box_type;                   /* Type of message box */
    kal_uint16 msg_number;                              /* Number of messages in this request primitive */
    kal_uint32 msg_id[SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER];  /* the sequence of message id */
} srv_sms_um_get_msg_info_req_struct;

typedef struct
{
    kal_uint32 app_id;                                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                           /* Type of message */
    kal_bool result[SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER];    /* KAL_TRUE means OK; KAL_FALSE means failed */
    srv_um_msg_btmapc_box_enum msg_box_type;                   /* Type of message box, bit mask, may be SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT*/
    kal_uint16 msg_number;                              /* Number of messages in this response primitive */
    kal_uint32 msg_id[SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER];  /* the sequence of message id */
    srv_um_bt_msg_info_struct msg_info[SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER];    /* Message info array */
} srv_um_sms_get_msg_info_rsp_struct;

typedef S32 (*srv_sms_um_get_list_cb) (S32 pid, srv_sms_um_get_list_result* rsp, S32 user_data);
typedef S32 (*srv_sms_um_get_msg_info_cb) (S32 pid, srv_sms_um_get_msg_info_result* rsp, S32 user_data);

typedef union
{
    kal_uint32 timestamp;
    kal_bool read_status;                               /* read status of message */
    kal_uint32 msg_size;                                /* message size */
    srv_um_msg_enum msg_type;                           /* message type */
    kal_wchar subject[SRV_UM_MAX_LIST_INDEX_LEN + 1];   /* message subject */
    kal_wchar address[SRV_UM_MAX_LIST_INDEX_LEN + 1];   /* message address */
} srv_um_bt_list_idx_data_union;



typedef struct
{
    U32 timestamp;
} ums_bt_get_list_sort_idx;

typedef struct
{
    srv_um_msg_enum msg_type;                   /* message type */
    U32 msg_id;                                 /* message id */
} srv_sms_um_bt_msg_node_struct;

typedef struct
{
    S32 list_cid;
    srv_um_list_cntx_struct list_cntx;
    srv_um_notify_list_handler cb_func;
    S32 user_data;
} srv_sms_um_list_pool_struct;

/********** This variable stores the message list*******/
static srv_sms_um_bt_msg_node_struct msg_node_buffer[SRV_UM_BT_MAX_MSG_NUM]={0};
static srv_sms_um_list_pool_struct sms_msg_list_pool[SRV_SMS_UM_MSG_LIST_POOL_SIZE];

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    srv_sms_um_bt_msg_node_struct *msg_list;
    U16 msg_list_size;
    U32 *timestamp_idx_data;
    S32 list_cntx_id;
    ums_bt_get_list_sort_idx *sort_idx_data;
} ums_bt_get_msg_list_cntx_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    U16 running_msg_number;
    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE];
} ums_bt_get_msg_info_cntx_struct;

S32 srv_um_bt_release_msg_list(S32 list_cid, MMI_BOOL out_of_date);
S32 srv_um_bt_listmgr_delete(S32 list_cid);
S32 srv_um_bt_listmgr_unregister(S32 list_cid);
static MMI_BOOL srv_um_bt_listmgr_is_invalid(S32 list_cid);


S32 srv_um_bt_release_msg_list(S32 list_cid, MMI_BOOL out_of_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_12, list_cid, out_of_date);

    if (out_of_date)
    {
        return srv_um_bt_listmgr_delete(list_cid);
    }
    else
    {
        return srv_um_bt_listmgr_unregister(list_cid);
    }
}

S32 srv_um_bt_listmgr_delete(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_bt_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_DELETE, list_cid);

    memset(&sms_msg_list_pool[list_index], 0, sizeof(srv_sms_um_list_pool_struct));

    return SRV_UM_RESULT_OK;
}

S32 srv_um_bt_listmgr_unregister(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_bt_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    sms_msg_list_pool[list_index].cb_func = NULL;
    sms_msg_list_pool[list_index].user_data = 0;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_UNREGISTER, list_cid);

    return SRV_UM_RESULT_OK;
}


static MMI_BOOL srv_um_bt_listmgr_is_invalid(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list_index >= SRV_SMS_UM_MSG_LIST_POOL_SIZE)
        || (sms_msg_list_pool[list_index].list_cid != list_cid)
        )
    {
        ASSERT(0);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}



U16 mmi_sms_um_bt_get_unread_msg_num(srv_um_sim_enum um_sim_id)
{
    U16 inbox_total=0,i=0,read=0,unread=0;
    inbox_total = srv_sms_btmapc_get_list_size(SRV_SMS_BOX_INBOX);
    for(i=0;i<inbox_total;i++)
    {
        U16 msg_id = srv_sms_btmapc_get_msg_id(SRV_SMS_BOX_INBOX, i);
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if(srv_sms_get_msg_sim_id(msg_id) == um_sim_id)  //sanjay //akhil
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        {
            read++;
            if(srv_sms_btmapc_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD)
                unread++;
        }
    }
    return unread;
}

MMI_BOOL mmi_sms_um_bt_get_num_req_hdlr(srv_um_msg_enum msg_type,srv_um_sim_enum sim_id,srv_sms_um_bt_get_msg_num_req_struct *req,srv_sms_um_get_msg_num_rsp_struct *rsp)
{
    //rsp->inbox_msg_number=srv_sms_btmapc_get_list_size(SRV_SMS_BOX_INBOX);
    //rsp->inbox_unread_msg_number=0;
    //rsp->sent_msg_number=srv_sms_btmapc_get_list_size(SRV_SMS_BOX_SENT);
    //rsp->unsent_msg_number=srv_sms_btmapc_get_list_size(SRV_SMS_BOX_UNSENT);
    //rsp->draft_msg_number=srv_sms_btmapc_get_list_size(SRV_SMS_BOX_DRAFTS);
    
    /*********** Below code is used for testing with original SMS service*******/

    rsp->inbox_unread_msg_number = srv_sms_btmapc_get_unread_sms_num();
    rsp->inbox_msg_number = srv_sms_btmapc_get_list_size(SRV_SMS_BOX_INBOX);
    rsp->unsent_msg_number = srv_sms_btmapc_get_list_size(SRV_SMS_BOX_UNSENT);
    rsp->sent_msg_number = srv_sms_btmapc_get_list_size(SRV_SMS_BOX_OUTBOX);
    rsp->draft_msg_number = srv_sms_btmapc_get_list_size(SRV_SMS_BOX_DRAFTS);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_UNREAD_MSG_NUM, rsp->inbox_unread_msg_number);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_INBOX_MSG_NUM, rsp->inbox_msg_number);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_UNSENT_MSG_NUM, rsp->unsent_msg_number);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_SENT_MSG_NUM, rsp->sent_msg_number);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_DRAFT_MSG_NUM, rsp->draft_msg_number);
    return MMI_TRUE;
}

S32 srv_sms_um_bt_get_msg_num(
        srv_um_msg_enum msg_type,
        srv_um_sim_enum sim_id,
        srv_sms_um_get_msg_num_cb cb_func,
        S32 user_data)
{
    MMI_BOOL error=MMI_FALSE;
    srv_sms_um_bt_get_msg_num_req_struct *req;
    srv_sms_um_get_msg_num_rsp_struct *rsp;
    req = (srv_sms_um_bt_get_msg_num_req_struct*) OslMalloc(sizeof(srv_sms_um_bt_get_msg_num_req_struct));//Done
    rsp = (srv_sms_um_get_msg_num_rsp_struct*)OslMalloc(sizeof(srv_sms_um_get_msg_num_rsp_struct));//Done
    memset(rsp,0,sizeof(srv_sms_um_get_msg_num_rsp_struct));
    memset(req, 0, sizeof(srv_sms_um_bt_get_msg_num_req_struct));
    req->app_id=0;
    req->msg_type=msg_type;
    req->sim_id=sim_id;
    if(msg_type!=SRV_UM_MSG_SMS && msg_type!=SRV_UM_MSG_NONE)
    {
        ASSERT(0);
    }
    //CHECK_PARA_VALID(cb_func);
    error=mmi_sms_um_bt_get_num_req_hdlr(msg_type,sim_id,req,rsp);
    cb_func(0,rsp,user_data);
    OslMfree(req);
    OslMfree(rsp);
}
static void mmi_sms_um_bt_get_msg_list_info(
                U16 msg_id,
                srv_um_bt_msg_list_struct *list_info,
                srv_um_bt_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->msg_id = msg_id;

    timestamp = srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id);
    list_info->timestamp =timestamp;
#if (MMI_MAX_SIM_NUM >= 2)
 //   list_info->sim_id = mmi_sms_sim_id_to_um_sim(srv_sms_get_msg_sim_id(msg_id));
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}

MMI_BOOL mmi_sms_um_bt_get_msg_list_info_hdlr(
    srv_um_get_bt_msg_list_rsp_struct *rsp_data,
    srv_um_get_bt_msg_list_req_struct *req_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = req_data->start_entry;
    U16 msg_box_size;
    U16 msg_count = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
    srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data->msg_box_type = req_data->msg_box_type;
    rsp_data->start_entry = list_index;
    msg_box_size=srv_sms_btmapc_get_list_size(req_data->msg_box_type); //This is for BT-Dialer

    //msg_box_size=srv_sms_get_list_size(req_data->msg_box_type);
    while (msg_count < SRV_UM_MAX_GET_MSG_LIST_NUMBER)
    {
        U16 msg_id = srv_sms_btmapc_get_msg_id(req_data->msg_box_type, list_index);
        //Use another API for BT-Dialer
        //U16 msg_id = srv_mtmap_sms_get_msg_id(sms_box_type, list_index);

        if (msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            mmi_sms_um_bt_get_msg_list_info(
                msg_id,
                &rsp_data->list_info[msg_count],
                NULL,
                SRV_UM_LIST_IDX_TIMESTAMP);

            msg_count++;
            list_index++;
        }
        else
        {
            break;
        }
    }
    rsp_data->msg_number=msg_count;
    if(list_index<msg_box_size)
    {
        rsp_data->more=MMI_FALSE;
    }
    else
    {
        rsp_data->more=MMI_TRUE;
    }
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_get_list_info_req_hdlr(srv_um_get_bt_msg_list_req_struct *req_data,srv_um_get_bt_msg_list_rsp_struct *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(req_data->msg_type == SRV_UM_MSG_SMS)
    {
        rsp_data->msg_type = SRV_UM_MSG_SMS;
        rsp_data->msg_box_type = req_data->msg_box_type;
        rsp_data->start_entry = req_data->start_entry;
        rsp_data->result_t = mmi_sms_um_bt_get_msg_list_info_hdlr(rsp_data, req_data);
    }
    else
        result=MMI_FALSE;
    return result;
}
S32 srv_sms_um_listmgr_create(srv_um_list_type_enum list_type, void **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 ticks;
    S32 new_list_index=-1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < SRV_SMS_UM_MSG_LIST_POOL_SIZE ; i++)
    {
        /* Empty*/
        if (sms_msg_list_pool[i].list_cid == 0)
        {
            new_list_index = i;
            break;
        }
        /* Not Empty but no owner */
        else if (sms_msg_list_pool[i].cb_func == NULL)
        {
            new_list_index = i;
        }
    }
    kal_get_time(&ticks);

    sms_msg_list_pool[new_list_index].list_cid = ((ticks & 0x7FFFFF00) | new_list_index);

    sms_msg_list_pool[new_list_index].list_cntx.list_type = list_type;
    if(list_type==SRV_UM_LIST_TYPE_MSG_NODE)
    {
        sms_msg_list_pool[new_list_index].list_cntx.list = (void*)msg_node_buffer;
        memset(sms_msg_list_pool[new_list_index].list_cntx.list, 0, sizeof(srv_sms_um_bt_msg_node_struct) * SRV_UM_BT_MAX_MSG_NUM);
        //memset(msg_node_buffer,0,sizeof(srv_sms_um_bt_msg_node_struct)*SRV_UM_MAX_MSG_NUM);
    }
    else
    {
        /****** Do not support other list type for BT-Dialer*******/
        ASSERT(0);
    }
    
    sms_msg_list_pool[new_list_index].cb_func = NULL;
    sms_msg_list_pool[new_list_index].user_data = 0;
    *list = sms_msg_list_pool[new_list_index].list_cntx.list;
    //*list=msg_node_buffer;
    return sms_msg_list_pool[new_list_index].list_cid;
}

S32 srv_sms_um_merge_msg_list(
        srv_sms_um_bt_msg_node_struct *old_list,
        U32 *old_timestamp,
        srv_um_list_idx_data_union *old_idx_data,
        S32 old_list_number,
        srv_um_bt_msg_list_struct *add_list,
        srv_um_msg_enum msg_type,
        srv_um_list_idx_data_union *add_idx_data,
        S32 add_list_number,
        srv_sms_um_bt_msg_node_struct *new_list,
        U32 *new_timestamp,
        srv_um_list_idx_data_union *new_idx_data,
        srv_um_list_idx_enum sort_type,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 old_list_idx, add_list_idx, new_list_idx;
    S32 new_list_number = old_list_number + add_list_number;
    S16 comp_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    old_list_idx = add_list_idx = new_list_idx = 0;
    for (; new_list_idx < new_list_number; new_list_idx++)
    {
        comp_result = 0;

        if (add_list_idx >= add_list_number)
        {
            comp_result = -1;
        }
        else if (old_list_idx >= old_list_number)
        {
            comp_result = 1;
        }
        if (comp_result == 0)
        {
            /*if (old_timestamp[old_list_idx] >= add_list[add_list_idx].timestamp)
            {
                comp_result = -1;
            }
            else
            {*/
                comp_result = 1;
            /*}*/
        }

        if (comp_result == -1)
        {
            if (old_list_idx >= old_list_number)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            /* move old list to the correct position */
            //new_timestamp[new_list_idx] = old_timestamp[old_list_idx];
            new_list[new_list_idx].msg_id = old_list[old_list_idx].msg_id;
            new_list[new_list_idx].msg_type = old_list[old_list_idx].msg_type;
            old_list_idx++;

        }
        else
        {

            if (add_list_idx >= add_list_number)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            /* move add list to the correct position */
            //new_timestamp[new_list_idx] = add_list[add_list_idx].timestamp;
            new_list[new_list_idx].msg_id = add_list[add_list_idx].msg_id;
            new_list[new_list_idx].msg_type = msg_type;
            add_list_idx++;
        }
    }

    return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_listmgr_update_cntx(S32 list_cid, S32 msg_number, srv_sms_um_box_identity_struct msg_box, srv_sms_um_list_filter_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }*/

    sms_msg_list_pool[list_index].list_cntx.msg_number = msg_number;

    //sms_msg_list_pool[list_index].list_cntx.msg_box =(srv_sms_um_box_identity_struct)msg_box;
    sms_msg_list_pool[list_index].list_cntx.msg_box.msg_type=msg_box.msg_type;
    sms_msg_list_pool[list_index].list_cntx.msg_box.msg_box_type=msg_box.msg_box_type;
    sms_msg_list_pool[list_index].list_cntx.msg_box.sim_id=msg_box.sim_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_UPDATE_CNTX, list_cid, msg_number, msg_box.msg_type, msg_box.msg_box_type);

    if (filter)
    {
        memcpy(&sms_msg_list_pool[list_index].list_cntx.filter, filter, sizeof(srv_um_list_filter_struct));
    }
    else
    {
        memset(&sms_msg_list_pool[list_index].list_cntx.filter, 0, sizeof(srv_um_list_filter_struct));
    }

    return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_bt_get_msg_list(
        srv_sms_um_list_type_enum list_type,
        srv_sms_um_box_identity_struct msg_box,
        srv_sms_um_list_filter_struct *filter,
        srv_sms_um_get_list_cb cb_func,
        S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        srv_um_get_bt_msg_list_req_struct *req;
        srv_um_get_bt_msg_list_rsp_struct *rsp;
        ums_bt_get_msg_list_cntx_struct *cntx;
        U16 offset, max_msg_num;
        S32 temp_number=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req = (srv_um_get_bt_msg_list_req_struct*) OslMalloc(sizeof(srv_um_get_bt_msg_list_req_struct));//Done
    rsp = (srv_um_get_bt_msg_list_rsp_struct*) OslMalloc(sizeof(srv_um_get_bt_msg_list_rsp_struct));
    cntx= (ums_bt_get_msg_list_cntx_struct *)OslMalloc(sizeof(ums_bt_get_msg_list_cntx_struct));
    //cntx->timestamp_idx_data= (S32 *)OslMalloc(sizeof(S32));
    memset(cntx, 0, sizeof(ums_bt_get_msg_list_cntx_struct));
    //cntx->timestamp_idx_data=&((sms_msg_detail_pool[0]).msg_info.timestamp);
    memset(rsp,0,sizeof(srv_um_get_bt_msg_list_rsp_struct));
    memset(req,0,sizeof(srv_um_get_bt_msg_list_req_struct));
    //memset(cntx->timestamp_idx_data,0,sizeof(S32));

    req->app_id=0;
    req->msg_box_type=msg_box.msg_box_type;
    req->start_entry=0;
    req->msg_type=SRV_UM_MSG_SMS;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

    cntx->list_cntx_id=srv_sms_um_listmgr_create(SRV_UM_LIST_TYPE_MSG_NODE,(void **)&cntx->msg_list);

    cntx->msg_list_size=SRV_UM_BT_MAX_MSG_NUM;
    cntx->pending_req_type=SRV_UM_MSG_SMS;
    while(rsp->more!=MMI_TRUE)
    {
        S32 temp_number=rsp->result.n.msg_number;
        memset(rsp,0,sizeof(srv_um_get_bt_msg_list_rsp_struct));
        mmi_sms_um_bt_get_list_info_req_hdlr(req,rsp);

        req->start_entry=rsp->msg_number;

        if(rsp->result_t==MMI_FALSE)
        {
            ASSERT(0);
        }
        if (rsp->msg_number == 0)
        {
            break;
        }
        if(cntx->msg_list_size>SRV_UM_BT_MAX_MSG_NUM)
        {
            max_msg_num=SRV_UM_BT_MAX_MSG_NUM;
        }
        else
        {
            max_msg_num=cntx->msg_list_size;
        }
        /* old list is in 1~100,  list size is 300, move the old list to 201~300 */
        if(rsp->result.n.msg_number!=0)
        {
            S32 i=0;
            offset = max_msg_num-rsp->result.n.msg_number;
            for (i = rsp->result.n.msg_number - 1; i >= 0; i--)
            {
                //*(cntx->timestamp_idx_data+offset+i)=rsp->list_info[rsp->result.n.msg_number].timestamp;
                //*(cntx->sort_idx_data->timestamp+offset+i)=rsp->list_info[rsp->result.n.msg_number].timestamp;
                memcpy(cntx->msg_list + offset + i, cntx->msg_list + i, sizeof(srv_sms_um_bt_msg_node_struct));
                //*(cntx->timestamp_idx_data + offset + i) = *(cntx->timestamp_idx_data + i);
            }
        }
        else
        {
            offset=max_msg_num;
        }
        srv_sms_um_merge_msg_list(
            cntx->msg_list + offset,
            //cntx->timestamp_idx_data + offset,
            NULL,
            NULL,
            rsp->result.n.msg_number,
            rsp->list_info,
            rsp->msg_type,
            NULL,
            rsp->msg_number,
            cntx->msg_list,
            NULL,
            NULL,
            SRV_UM_LIST_IDX_TIMESTAMP,
            SRV_UM_SORT_ORDER_UNCLASSIFIED);
    }
    if(rsp->more==MMI_TRUE)
    {
        rsp->result.n.msg_number=temp_number+rsp->msg_number;
        cntx->pending_req_type&=~rsp->msg_type;
        if (rsp->result.error != SRV_UM_RESULT_OK)
        {
            memset(&sms_msg_list_pool[0], 0, sizeof(srv_sms_um_list_pool_struct));
        }
        else
        {
            /*S32 i=0;
            for (i = 0; i < rsp->result.n.msg_number - 1; i++)
            {
                memcpy(&((srv_sms_um_bt_msg_node_struct *)sms_msg_list_pool[0].list_cntx.list)[i], &cntx->msg_list[i], sizeof(srv_sms_um_bt_msg_node_struct));
            }*/
            srv_sms_um_listmgr_update_cntx(0, rsp->result.n.msg_number,msg_box,filter);
        }
    }
    OslMfree(req);
    OslMfree(cntx);
    g_pid=0;
    g_para=user_data;
    cb_func(0,&rsp->result,user_data);

    OslMfree(rsp);
}


static MMI_BOOL srv_sms_um_listmgr_cmp_msg_box(srv_um_box_identity_struct src_msg_box, srv_um_box_identity_struct dest_msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_msg_box.msg_type == dest_msg_box.msg_type)
        && (src_msg_box.msg_box_type == dest_msg_box.msg_box_type)
        && (src_msg_box.sim_id == dest_msg_box.sim_id)
        )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
static MMI_BOOL srv_sms_um_listmgr_cmp_msg_filter(srv_um_list_filter_struct src_filter, srv_um_list_filter_struct dest_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_filter.idx_type == dest_filter.idx_type)
        && (src_filter.order == dest_filter.order))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

S32 srv_sms_um_listmgr_search(
    srv_um_list_type_enum list_type,
    srv_um_box_identity_struct msg_box,
    srv_um_list_filter_struct *filter,
    srv_um_list_cntx_struct **list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0 ; i < SRV_SMS_UM_MSG_LIST_POOL_SIZE ; i++)
    {
        if (srv_sms_um_listmgr_cmp_msg_box(sms_msg_list_pool[i].list_cntx.msg_box, msg_box) &&
            srv_sms_um_listmgr_cmp_msg_filter(sms_msg_list_pool[i].list_cntx.filter, *filter) &&
            sms_msg_list_pool[i].list_cntx.list_type == list_type)
        {
            if (list_cntx)
            {
                *list_cntx = &(sms_msg_list_pool[i].list_cntx);
            }
            return sms_msg_list_pool[i].list_cid;
        }
    }

    if (list_cntx)
    {
        *list_cntx = NULL;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_SEARCH, list_type, msg_box.msg_type, msg_box.msg_box_type);

    return SRV_UM_RESULT_DATA_NOT_FOUND;
}

S32 srv_sms_um_listmgr_register(S32 list_cid, srv_um_notify_list_handler cb_func, S32 user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }*/

    /* notify old owner */
    if (sms_msg_list_pool[list_index].cb_func != NULL)
    {
        sms_msg_list_pool[list_index].cb_func(SRV_UM_NOTIFY_LIST_RELEASED_IND, list_cid, sms_msg_list_pool[list_index].user_data);
        
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_REGISTER);
    }

    sms_msg_list_pool[list_index].cb_func = cb_func;
    sms_msg_list_pool[list_index].user_data = user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_REGISTER_1, list_cid);

    return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_listmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&sms_msg_list_pool[0], 0, sizeof(srv_sms_um_list_pool_struct));
    memset(&sms_msg_list_pool[1], 0, sizeof(srv_sms_um_list_pool_struct));

    return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_check_msg_list(
        srv_um_list_type_enum list_type,
        srv_um_box_identity_struct msg_box,
        srv_um_list_filter_struct *filter,
        srv_um_notify_list_handler cb_func,
        S32 user_data,
        srv_um_list_cntx_struct **list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_cid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }
	if (SRV_UM_RESULT_OK > (result = list_cid = srv_sms_um_listmgr_search(list_type, msg_box, filter, list_cntx)))
    {
        return result;
    }
	if (SRV_UM_RESULT_OK > (result = srv_sms_um_listmgr_register(list_cid, cb_func, user_data)))
    {
        return result;
    }
	return list_cid;
}

static MMI_BOOL mmi_sms_um_bt_get_msg_info_sender_name(
                    srv_um_bt_msg_info_struct *msg_info,
                    U16 msg_id,
                    srv_um_msg_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist( msg_id))
    {
		const CHAR *temp_content;
		msg_info->msg_id=msg_id;
		msg_info->timestamp=srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id);
		msg_info->icon_id=IMG_MESSAGE_READ; //Please add the new Image ID for New Message, Send failed and Sent messages.
		#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
		#endif
		msg_info->csk_icon_id=IMG_GLOBAL_OPTION_CSK;

        //sms_mti = srv_sms_get_msg_mti(msg_id);
        msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;

        srv_sms_btmapc_get_msg_address(msg_id, (S8*)msg_info->address);

        msg_info->address_length = mmi_ucs2strlen((S8*) msg_info->address);

		temp_content = srv_sms_btmapc_get_msg_sender_name(msg_id);
		if (0 == mmi_ucs2strlen(temp_content))
        {
            srv_sms_btmapc_get_msg_address(msg_id, (S8 *)temp_content);
        }
		mmi_ucs2ncpy(
			(S8*)msg_info->sender_name,
			temp_content,
			SRV_UM_MAX_SUBJECT_LEN);
		msg_info->sender_name[SRV_BT_MAP_MAX_SENDER_NAME_LEN] ='\0';
        msg_info->subject_length = mmi_ucs2strlen((S8*)msg_info->sender_name);
    }
    else
    {
        result = MMI_FALSE;
    }
    return result;
}

MMI_BOOL mmi_sms_um_get_msg_info_req_hdlr(srv_sms_um_get_msg_info_req_struct *req,srv_um_sms_get_msg_info_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_TRUE;
	S32 i=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(rsp,0,sizeof(srv_um_sms_get_msg_info_rsp_struct));
	if(req->msg_type==SRV_UM_MSG_SMS)
	{
		rsp->app_id = req->app_id;
		rsp->msg_type = SRV_UM_MSG_SMS;
		rsp->msg_box_type = req->msg_box_type;
		rsp->msg_number = req->msg_number;
		for(i=0;i<req->msg_number;i++)
		{
			U16 msg_id=req->msg_id[i];
			srv_um_bt_msg_info_struct *msg_info=&rsp->msg_info[i];
			rsp->msg_id[i]=msg_id;
			rsp->result[i]=mmi_sms_um_bt_get_msg_info_sender_name(
                                msg_info,
                                msg_id,
								req->msg_box_type);
		}
	}
	else
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}
S32 srv_sms_um_info_add(srv_um_msg_enum msg_type, srv_um_msg_btmapc_box_enum msg_box_type, srv_um_bt_msg_info_struct msg_list[], S32 msg_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    s32 i;
    S32 *tmp_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	tmp_idx = get_ctrl_buffer(sizeof(S32) * msg_number);
	MMI_ASSERT(tmp_idx != NULL);
	kal_prompt_trace(MOD_MMI, "Akhil tmp allocated tmp");
	for (i = 0; i < msg_number; i++)
    {
        sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_type = msg_type;
        sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_box_type = msg_box_type;
        memcpy(&sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_info, &msg_list[i], sizeof(srv_um_bt_msg_info_struct));
        tmp_idx[i] = sms_msg_detail_idx[i];

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_ADD, tmp_idx[i], msg_list[i].msg_id, msg_type, msg_box_type);
    }
	for (i = 0; i < ((S32)SRV_UM_MSG_DETAIL_NUM - msg_number); i++)
    {
        sms_msg_detail_idx[i] = sms_msg_detail_idx[i + msg_number];
    }

    /* place newest message to the right side */
    for (i = 0; i < msg_number; i++)
    {
        sms_msg_detail_idx[SRV_UM_MSG_DETAIL_NUM - msg_number + i] = tmp_idx[i];
    }

    free_ctrl_buffer(tmp_idx);

    return SRV_UM_RESULT_OK;
}

void mmi_sms_bt_handle_list_load_cb(void)
{
	mmi_sms_um_bt_ui_fsm_ef_req_msg_info_cb(g_pid,&g_res,g_para);  

}

/*void mmi_sms_bt_free_previous_mem(void)
{
	if(g_res)
	{
	OslMfree(g_res);
	g_res = NULL;
	}
}*/

S32 srv_sms_um_bt_get_msg_info(
        srv_sms_um_box_identity_struct msg_box,
        srv_sms_um_bt_msg_node_struct msg_list[],
        U16 msg_number,
        srv_sms_um_get_msg_info_cb cb_func,
        S32 user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
		srv_um_sms_get_msg_info_rsp_struct *rsp;
		ums_bt_get_msg_list_cntx_struct *cntx;
		srv_sms_um_get_msg_info_result *result;
		srv_sms_um_get_msg_info_req_struct *req;
		U16 offset, max_msg_num;
		S32 i=0,j=0;
		srv_um_msg_enum pending_req_type;
        mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(msg_number>0);
    CHECK_PARA_VALID(cb_func);

	if(msg_box.msg_type != SRV_UM_MSG_SMS)
	{
		/****** BT-Dilaer only support SMS ************/
		ASSERT(0);
	}
	//cntx=(ums_bt_get_msg_list_cntx_struct *)OslMalloc(sizeof(srv_sms_um_get_msg_info_req_struct));
	//cntx->pending_req_type=SRV_UM_MSG_SMS;
	pending_req_type=msg_box.msg_type;
	//if(cntx->pending_req_type && SRV_UM_MSG_SMS)
	result=(srv_sms_um_get_msg_info_result *)OslMalloc(sizeof(srv_sms_um_get_msg_info_result));
	memset(result,0,sizeof(srv_sms_um_get_msg_info_result));
	if(pending_req_type && SRV_UM_MSG_SMS)
	{
		rsp=(srv_um_sms_get_msg_info_rsp_struct *) OslMalloc(sizeof(srv_um_sms_get_msg_info_rsp_struct));
		req = (srv_sms_um_get_msg_info_req_struct*) OslMalloc(sizeof(srv_sms_um_get_msg_info_req_struct));
		memset(req, 0, sizeof(srv_sms_um_get_msg_info_req_struct));
		memset(rsp,0,sizeof(srv_um_sms_get_msg_info_rsp_struct));
		req->msg_type = msg_box.msg_type;
		req->app_id = 0;
		req->msg_box_type = msg_box.msg_box_type;
		req->msg_number = 0;
		for(j=0;j<msg_number;j++)
		{
			req->msg_id[req->msg_number++]=msg_list[j].msg_id;
			if (req->msg_number >= SRV_SMS_UM_MAX_GET_MSG_INFO_NUMBER)
			{
				j++;
				break;
			}
		}
		mmi_sms_um_get_msg_info_req_hdlr(req,rsp);
	}
	if(req->msg_number==0)
	{
		OslMfree(req);
		OslMfree(rsp);
		//cntx->pending_req_type &= ~SRV_UM_MSG_SMS;
		pending_req_type &= ~SRV_UM_MSG_SMS;
	}
	else
	{
		/*if(cntx->running_req_type!=rsp->msg_type)
		{
			ASSERT(0);
		}*/
		//cntx->pending_req_type &= ~SRV_UM_MSG_SMS;
		pending_req_type &= ~SRV_UM_MSG_SMS;
		for (i = 0; i < rsp->msg_number; i++)
		{
			if (!rsp->result[i])
			{
				result->no_of_fail++;
				rsp->msg_info[i].timestamp = 0;
			}
			else
			{
				result->no_of_success++;
			}
		}
		srv_sms_um_info_add(rsp->msg_type, rsp->msg_box_type, rsp->msg_info, rsp->msg_number);      
	OslMfree(req);
	OslMfree(rsp);
    }
	memcpy(&g_res, result, sizeof(srv_um_get_msg_info_result));
    g_pid = 0;
	g_para = user_data;

    MMI_FRM_INIT_EVENT(&evt, 0);
	mmi_frm_post_event(&evt,mmi_sms_bt_handle_list_load_cb,NULL);

	OslMfree(result);
	return SRV_UM_RESULT_OK;
}
srv_um_bt_msg_info_struct *srv_sms_um_bt_search(srv_sms_um_list_type_enum list_type, void *list)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i, j, end;
	srv_um_bt_msg_info_struct *result = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (list_type == SRV_UM_LIST_TYPE_MSG_NODE &&
		((srv_sms_um_bt_msg_node_struct*)list)->msg_id == 0 && ((srv_sms_um_bt_msg_node_struct*)list)->msg_type == 0)
	{
		ASSERT(0);
		return NULL;
	}
	end=0;
	for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= end; i--)
	{
		MMI_BOOL match = MMI_FALSE;
		if (list_type == SRV_UM_LIST_TYPE_MSG_NODE
			&& ((srv_um_msg_node_struct*)list)->msg_id == sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_info.msg_id
			&& ((srv_um_msg_node_struct*)list)->msg_type == sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_type)
		{
			match = MMI_TRUE;
		}
		if (match)
		{
			result = &(sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_info);

			/* this item should move the newer side if the idx is too old */
			if (i < SRV_UM_MSG_DETAIL_NUM - SRV_UM_MAX_MSG_PER_PAGE)
			{
				S32 tmp_idx = sms_msg_detail_idx[i];

				for (j = i; j < SRV_UM_MSG_DETAIL_NUM - 1; j++)
				{
					sms_msg_detail_idx[j] = sms_msg_detail_idx[j + 1];
				}
				sms_msg_detail_idx[SRV_UM_MSG_DETAIL_NUM - 1] = tmp_idx;
			}
			return result;
		}
	}
	return NULL;
}
S32 srv_sms_um_check_msg_info_by_ref(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        srv_um_bt_msg_info_struct *msg_info[])
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(list_info_size);
    CHECK_PARA_VALID(msg_number);
    CHECK_PARA_VALID(start_entry + msg_number <= list_info_size);
	if(msg_box.msg_type!=SRV_UM_MSG_SMS)
	{
		/**** BT-Dialer Does not get data other than SMS********/
		ASSERT(0);
	}
	if (msg_info != NULL)
    {
        memset(msg_info, 0, sizeof(srv_um_bt_msg_info_struct*) * msg_number);
    }
	for (i = msg_number - 1; i >= 0; i--)
    {
        srv_um_bt_msg_info_struct *tmp;

        tmp = srv_sms_um_bt_search(SRV_UM_LIST_TYPE_MSG_NODE, msg_list + start_entry + i);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_4, msg_list[start_entry + i].msg_type, msg_list[start_entry + i].msg_id, tmp);
        if (tmp)
        {
            if (msg_info != NULL)
            {
                msg_info[i] = tmp;
            }
        }
        else
        {
            return SRV_UM_RESULT_DATA_NOT_FOUND;
        }
    }
	return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_pool_clean(srv_um_msg_enum msg_type, srv_um_msg_btmapc_box_enum msg_box_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i,j;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (msg_type == SRV_UM_MSG_ALL && msg_box_type == SRV_UM_MSG_BOX_ALL)
	{
		memset(sms_msg_detail_pool, 0, sizeof(sms_msg_detail_pool));
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			sms_msg_detail_idx[i] = i;
		}

		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_CLEAN);
	}
	else
	{
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if ((sms_msg_detail_pool[i].msg_type & msg_type) &&
				(sms_msg_detail_pool[i].msg_box_type & msg_box_type))
			{
				memset(&sms_msg_detail_pool[i], 0, sizeof(srv_sms_um_cache_struct));

				//MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_CLEAN_1, i, msg_detail_pool[i].msg_info.msg_id, msg_detail_pool[i].msg_box_type);
			}
		}
		j = SRV_UM_MSG_DETAIL_NUM - 1;

		/* move all items with value to the newest side */
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if (sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_type != 0)
			{
				sms_msg_detail_idx[j] = sms_msg_detail_idx[i];
				j--;
			}
		}

		/* assign all empty items to the oldest side */
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if (sms_msg_detail_pool[i].msg_type == 0)
			{
				sms_msg_detail_idx[j] = i;
				j--;
			}
		}

		if (j != -1)
		{
			EXT_ASSERT(0, 0, 0, 0);
		}
	}

	return SRV_UM_RESULT_OK;
}

S32 srv_sms_um_release_msg_list(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_DELETE, list_cid);

    memset(&sms_msg_list_pool[list_index], 0, sizeof(srv_sms_um_list_pool_struct));

    return SRV_UM_RESULT_OK;
}

S32 srv_um_sms_clear_msg_info_cache(srv_um_msg_enum msg_type, srv_um_msg_btmapc_box_enum msg_box_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i=0,j=0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/* For special issue, when UI need to clean cache, that means all the data
	is unreliable until next get request, therefore we do not peek message
	at this time */
	if (msg_type == SRV_UM_MSG_ALL && msg_box_type == SRV_UM_MSG_BOX_ALL)
	{
		memset(sms_msg_detail_pool, 0, sizeof(sms_msg_detail_pool));
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			sms_msg_detail_idx[i] = i;
		}
	}
	else
	{
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if ((sms_msg_detail_pool[i].msg_type & msg_type) &&
				(sms_msg_detail_pool[i].msg_box_type & msg_box_type))
			{
				memset(&sms_msg_detail_pool[i], 0, sizeof(srv_sms_um_cache_struct));
			}
		}
		j = SRV_UM_MSG_DETAIL_NUM - 1;

		/* move all items with value to the newest side */
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if (sms_msg_detail_pool[sms_msg_detail_idx[i]].msg_type != 0)
			{
				sms_msg_detail_idx[j] = sms_msg_detail_idx[i];
				j--;
			}
		}

		/* assign all empty items to the oldest side */
		for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
		{
			if (sms_msg_detail_pool[i].msg_type == 0)
			{
				sms_msg_detail_idx[j] = i;
				j--;
			}
		}

		if (j != -1)
		{
			EXT_ASSERT(0, 0, 0, 0);
		}
	}
	return SRV_UM_RESULT_OK;
}

#endif
