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
*  CallLogAdpCmn.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*  
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "CallLogProt.h"
#include "CallLogConfig.h"
#ifdef __MMI_CLOG_ADP__

#include "CallLogAdpProt.h"

#include "IdleRecentEventGprot.h"
#include "MMIDataType.h"
#include "CallLogSrvGprot.h"
#include "kal_non_specific_general_types.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"
#include "app_datetime.h"
#include "mmi_rp_app_calllog_def.h"
#include "wgui_categories_util.h"
#include "custom_phb_config.h"
#include "nvram_common_defs.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "CallLogGprot.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN__)
#define MMI_CLOG_HS_RE_MAX_NUM                       (MMI_HS_MAX_RECENT_EVENT_NUM)
#else 
#define MMI_CLOG_HS_RE_MAX_NUM                       (0)
#endif 

#define MMI_CLOG_HS_OP11_MENU_DATA_MAX_NUM           (0)

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#define MMI_CLOG_HS_SHCT_MAX_NUM                     (MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX)
#else 
#define MMI_CLOG_HS_SHCT_MAX_NUM                     (0)
#endif 

#define MMI_CLOG_HS_GET_DATA_MAX_NUM                 (MMI_CLOG_MAX3(MMI_CLOG_HS_RE_MAX_NUM,MMI_CLOG_HS_OP11_MENU_DATA_MAX_NUM,MMI_CLOG_HS_SHCT_MAX_NUM))

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    U8 has_run;
    U16 max_size;
    U16 req_num;
    U8 skip_read;
    U8 only_new_event;
    U8 need_cid;
    U16 cur_index;
    SRV_CLOG_HANDLE handle;
    void *data_list;
    MMI_CLOG_HS_PARSE_INFO_HDLR parse_info_hdlr;

    srv_clog_get_list_log_ids_req_struct req_data;
    srv_clog_get_list_log_ids_cnf_struct cnf_data;
    srv_clog_num_info_struct num_info;
    WCHAR *name[MMI_CLOG_HS_GET_DATA_MAX_NUM];
    WCHAR *cid[MMI_CLOG_HS_GET_DATA_MAX_NUM];
    mmi_clog_hs_get_data_log_info_struct log_info;
    MMI_BOOL need_malloc; // need oslMalloc for name or cid
} mmi_clog_hs_get_data_para_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static S32 mmi_clog_hs_get_data_parse_list(mmi_clog_hs_get_data_para_struct *para);
static void mmi_clog_hs_get_data_parse_log(mmi_clog_hs_get_data_para_struct *para, srv_clog_log_struct *log);

#if defined(__MMI_VUI_HOMESCREEN__)

/* Recent event */
static S32 mmi_clog_hs_re_parse_data(
            void *data_list,
            U32 max_size,
            U32 cur_index,
            mmi_clog_hs_get_data_log_info_struct *log_info);
static void mmi_clog_hs_re_key_hdlr(U16 key_code, U16 key_type, void *user_data);
static void mmi_clog_hs_enter_viewer(SRV_CLOG_ID log_id);
static void mmi_clog_hs_re_enter_option(SRV_CLOG_ID log_id);

#endif /* defined(__MMI_VUI_HOMESCREEN__) */ 

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_init_get_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_hs_init_get_data_req(mmi_clog_hs_get_data_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req)
        return;
    memset(req, 0x0, sizeof(mmi_clog_hs_get_data_req_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_clog_hs_get_data_create(mmi_clog_hs_get_data_req_struct *req, MMI_BOOL need_malloc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    mmi_clog_hs_get_data_para_struct *para;
    const mmi_clog_lt_id_attr_struct *attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ASSERT(req);
    para = OslMalloc(sizeof(mmi_clog_hs_get_data_para_struct));
    memset(para, 0x0, sizeof(mmi_clog_hs_get_data_para_struct));
    para->max_size = req->max_size;
    para->req_num = req->req_num;
    para->skip_read = req->skip_read;
    para->only_new_event = req->only_new_event;
    para->need_cid = req->need_cid;
    para->data_list = req->data_list;
    para->parse_info_hdlr = req->parse_info_hdlr;
    para->handle = req->handle;
    if (need_malloc == MMI_TRUE)
        para->need_malloc = MMI_TRUE;
    else
        para->need_malloc = MMI_FALSE;

    attr = mmi_clog_get_attr_by_lt_id(MMI_CLOG_LT_ID_MISSED_CALL);
    ret = srv_clog_get_list_num_info(para->handle, &attr->idt, &para->num_info);
    if (ret != SRV_CLOG_RET_OK)
    {
        OslMfree(para);
        return 0;
    }
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &para->req_data);
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &para->cnf_data);

    SRV_CLOG_INIT_IDT(
        (srv_clog_log_identity_struct*) & para->req_data,
        attr->idt.cate,
        attr->idt.sim_id,
        attr->idt.log_type,
        attr->idt.sub_type);
    para->req_data.start_by = SRV_CLOG_BY_ID;
    if (!para->skip_read && !para->only_new_event && para->max_size < SRV_CLOG_LOG_ID_LIST_MAX_NUM)
        para->req_data.log_num = para->max_size;
    else
        para->req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;

    MMI_TRACE(
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_HS_GET_DATA_CREATE,
        para->max_size,
        para->req_num,
        para->skip_read,
        para->need_cid);

    return (U32) para;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_clog_hs_get_data_run(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 count;
    mmi_clog_hs_get_data_para_struct *para = (mmi_clog_hs_get_data_para_struct*) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!para)
        return 0;

    count = MMI_CLOG_ROUND(para->num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS], SRV_CLOG_LOG_ID_LIST_MAX_NUM);

    for (i = 0; i < count; i++)
    {
        para->req_data.start_elm = para->cnf_data.next_start_elm;
        ret = srv_clog_get_list_log_ids(para->handle, &para->req_data, &para->cnf_data);
        if (ret != SRV_CLOG_RET_OK)
            break;
        ret = mmi_clog_hs_get_data_parse_list(para);
        if (ret == MMI_FALSE || para->cur_index >= para->max_size ||
            SRV_CLOG_IS_ELM_INVALID(para->cnf_data.next_start_elm))
            break;
    }
    para->has_run = MMI_TRUE;
    return para->cur_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_get_ttur_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_clog_hs_get_data_get_ttur_num(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_hs_get_data_para_struct *para = (mmi_clog_hs_get_data_para_struct*) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!para)
        return 0;
    MMI_CLOG_ASSERT(para->has_run);
    return para->num_info.num[SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_hs_get_data_close(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_hs_get_data_para_struct *para = (mmi_clog_hs_get_data_para_struct*) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!para)
        return;

    for (i = 0; i < MMI_CLOG_HS_GET_DATA_MAX_NUM; i++)
    {
        if (para->name[i])
            OslMfree(para->name[i]);
        if (para->cid[i])
            OslMfree(para->cid[i]);
    }
    OslMfree(para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_parse_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_hs_get_data_parse_list(mmi_clog_hs_get_data_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret = MMI_TRUE;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < para->cnf_data.log_num; i++)
    {
        ret = srv_clog_get_log_by_id(para->handle, para->cnf_data.log_ids[i], 0, &log);
        if (ret != SRV_CLOG_RET_OK)
            continue;
        if (para->skip_read && log.data.call_log.unread_num == 0)
            continue;
        if (para->only_new_event && !log.data.call_log.is_new_event)
            continue;
        if (para->need_malloc == MMI_TRUE)
            mmi_clog_hs_get_data_parse_log(para, &log);
        
        ret = (para->parse_info_hdlr) (para->data_list, para->max_size, para->cur_index, &para->log_info);
        para->cur_index++;
        if (ret == MMI_FALSE || para->cur_index >= para->max_size)
        {
            ret = MMI_FALSE;
            break;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_get_data_parse_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [IN]     
 *  log         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_hs_get_data_parse_log(mmi_clog_hs_get_data_para_struct *para, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para->log_info.unread_num = log->data.call_log.unread_num;
    para->log_info.icon = mmi_clog_get_image((const srv_clog_log_identity_struct*)&log->data.call_log);
    mmi_clog_time_utc2app(log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX], (applib_time_struct*) & para->log_info.timestamp);

    if (mmi_clog_is_name_empty(log) && mmi_clog_is_cid_empty(log))
    {
        para->log_info.name = get_string(STR_ID_CLOG_UNKNOWN_NUMBER);
        if (para->need_cid)
            para->log_info.cid = get_string(STR_ID_CLOG_UNKNOWN_NUMBER);
    }
    else
    {
        para->name[para->cur_index] = OslMalloc((SRV_CLOG_NAME_MAX_LEN + 1) * ENCODING_LENGTH);
        if (!mmi_clog_is_name_empty(log))
            mmi_wcscpy(para->name[para->cur_index], log->data.call_log.name);
        else
            mmi_wcsncpy(para->name[para->cur_index], log->data.call_log.cid, SRV_CLOG_NAME_MAX_LEN);
        para->log_info.name = para->name[para->cur_index];
        para->log_info.log_id = log->data.call_log.log_id;
        if (para->need_cid)
        {
            para->cid[para->cur_index] = OslMalloc((SRV_CLOG_CID_MAX_LEN + 1) * ENCODING_LENGTH);
            mmi_wcscpy(para->cid[para->cur_index], log->data.call_log.cid);
            para->log_info.cid = para->cid[para->cur_index];
        }
    }
}

#if defined(__MMI_VUI_HOMESCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_re_query_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_hs_re_query_data(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    U32 get_num;
    mmi_clog_hs_get_data_req_struct req_data;
    mmi_hs_recent_event_struct data[MMI_HS_MAX_RECENT_EVENT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_ready())
    {
        mmi_hs_recent_event_answer(MMI_HS_RECENT_EVENT_MISSED_CALL, MMI_HS_RESULT_OK, 0, NULL, NULL);
        return;
    }

    mmi_clog_hs_init_get_data_req(&req_data);
    req_data.max_size = MMI_HS_MAX_RECENT_EVENT_NUM;
    req_data.req_num = num;
    req_data.skip_read = MMI_FALSE;
    req_data.only_new_event = MMI_TRUE;
    req_data.need_cid = MMI_FALSE;
    req_data.data_list = (void*)data;
    req_data.parse_info_hdlr = mmi_clog_hs_re_parse_data;

    handle = mmi_clog_hs_get_data_create(&req_data, MMI_TRUE);
    get_num = mmi_clog_hs_get_data_run(handle);
    mmi_clog_hs_get_data_close(handle);

    mmi_hs_recent_event_answer(
        MMI_HS_RECENT_EVENT_MISSED_CALL,
        MMI_HS_RESULT_OK,
        get_num,
        data,
        mmi_clog_hs_re_key_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_re_parse_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_list       [IN]         
 *  max_size        [IN]        
 *  cur_index       [IN]        
 *  log_info        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_hs_re_parse_data(
            void *data_list,
            U32 max_size,
            U32 cur_index,
            mmi_clog_hs_get_data_log_info_struct *log_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_hs_recent_event_struct *re_list;
    mmi_hs_recent_event_struct *cur_re;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    re_list = (mmi_hs_recent_event_struct*) data_list;
    cur_re = &re_list[cur_index];

    cur_re->is_read = (MMI_BOOL)(log_info->unread_num == 0);
    cur_re->icon = log_info->icon;
    memcpy(&cur_re->time, &log_info->timestamp, sizeof(applib_time_struct));
    cur_re->subject = (CHAR*) log_info->name;
    cur_re->user_data = (void*)log_info->log_id;
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_re_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_type        [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_hs_re_key_hdlr(U16 key_code, U16 key_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
        case KEY_SEND:
            mmi_clog_hs_make_call_hdlr((SRV_CLOG_ID) user_data, MMI_CLOG_KEY_SEND);
            break;

        case KEY_CSK:
            mmi_clog_hs_enter_viewer((SRV_CLOG_ID) user_data);
            break;

        case KEY_LSK:
            mmi_clog_hs_re_enter_option((SRV_CLOG_ID) user_data);
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_make_call_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id          [IN]        
 *  from_key        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_hs_make_call_hdlr(SRV_CLOG_ID log_id, mmi_clog_key_enum from_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_para_struct para;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_para_struct para;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para.flags = 0;
    para.handle = SRV_CLOG_INVALID_ELM;
    para.log_id = log_id;
    para.op_mid = MMI_CLOG_OP_MID_MAKE_CALL;
    para.sel_lt_id = MMI_CLOG_LT_ID_MISSED_CALL;

    if (from_key == MMI_CLOG_KEY_SEND)
        MMI_CLOG_SET_BIT(para.flags, MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY);
#ifdef __MMI_IP_KEY__
/* under construction !*/
/* under construction !*/
#endif

    /* Temp solution base the condition that OP11V2.5 will not turn on dual-SIM and Video call feature and 
       OP11V2.5 will be phased out in recent feature */
    MMI_CLOG_SET_BIT(para.flags, MMI_CLOG_ACT_FLAG_CALL_VOICE_ONLY);

    gid = mmi_clog_get_valid_act_gid();
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_run(gid, &para);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_proc(gid, &para);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_enter_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_hs_enter_viewer(SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_para_struct para;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_para_struct para;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	para.flags = 0;
    para.handle = SRV_CLOG_INVALID_ELM;
    para.log_id = log_id;
    para.op_mid = MMI_CLOG_OP_MID_VIEW;
    para.sel_lt_id = MMI_CLOG_LT_ID_MISSED_CALL;

    MMI_CLOG_SET_BIT(para.flags, MMI_CLOG_ACT_FLAG_PURE_VIEW);

    gid = mmi_clog_get_valid_act_gid();
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_run(gid, &para);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_proc(gid, &para);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hs_re_enter_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  log_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_hs_re_enter_option(SRV_CLOG_ID log_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    mmi_clog_op_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_op_init_para(&para);
#if defined (__MMI_VUI_HOMESCREEN__)
    para.type = MMI_CLOG_OP_TYPE_VUI;
#endif 
    para.lt_id = MMI_CLOG_LT_ID_MISSED_CALL;
    para.handle = SRV_CLOG_INVALID_ELM;
    para.log_id = log_id;

    gid = mmi_clog_get_valid_act_gid();
    mmi_clog_op_enter(gid, &para);
}

#endif /* defined(__MMI_VUI_HOMESCREEN__) */ 

#endif /* __MMI_CLOG_ADP__ */ 

