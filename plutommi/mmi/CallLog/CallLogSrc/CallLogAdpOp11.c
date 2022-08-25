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
*  CallLogAdpOp11.c
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
#include "CallLogConfig.h"

#ifdef __MMI_CLOG_ADP__
#include "CallLogSrvGprot.h"
#include "CallLogAdpProt.h"
#include "CallLogProt.h"
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* Shortcut */
static void mmi_clog_op11_hs32_shct_get_data(mmi_op11_hs32_shct_data_struct *data);
static S32 mmi_clog_op11_hs32_shct_parse_data(
            void *data_list,
            U32 max_size,
            U32 index,
            mmi_clog_hs_get_data_log_info_struct *log_info);

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/


#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#define MMI_CLOG_OP11_V32_SIDEBAR


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_sb_check_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sidebar_id      [IN]        
 *  indctr_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op11_hs32_sb_check_num(S32 sidebar_id, S32 indctr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_sidebar_query_info_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_ready())
    {
        data.result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
        mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, &data);
        return;
    }
    data.result_flag = MMI_OP11_HS32_RESULT_OK;
    data.indicator_value = (S32) srv_clog_get_unread_missed_call_num();
    mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, &data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_sb_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op11_hs32_sb_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_sidebar_query_info_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.result_flag = MMI_OP11_HS32_RESULT_UPDATE;
    data.indicator_value = (S32) srv_clog_get_unread_missed_call_num();

    mmi_op11_hs32_answer_sidebar(MMI_OP11_HS32_AP_CLL, MMI_OP11_HS32_INDCTR_CLL_MISSED_VOICECALL, &data);
}

#define MMI_CLOG_OP11_V32_SHORTCUT


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_shct_query_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sidebar_id      [IN]        
 *  shct_id         [IN]        
 *  shct_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op11_hs32_shct_query_data(S32 sidebar_id, S32 shct_id, void *shct_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_shct_data_struct *shct_data_p = (mmi_op11_hs32_shct_data_struct*) shct_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_ready())
    {
        shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
        mmi_op11_hs32_answer_shct_data(sidebar_id, shct_id, shct_data_p);
        return;
    }
    shct_data_p->result_flag = MMI_OP11_HS32_RESULT_OK;
    mmi_clog_op11_hs32_shct_get_data(shct_data_p);
	shct_data_p->item_count = (S32) srv_clog_get_unread_missed_call_num();
    mmi_op11_hs32_answer_shct_data(sidebar_id, shct_id, shct_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_shct_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_op11_hs32_shct_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_shct_data_struct *shct_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    shct_data_p = mmi_op11_hs32_get_shct_data_pointer(MMI_OP11_HS32_AP_CLL, MMI_OP11_HS32_SHCT_CLL_CALL_LOG);

    if (!shct_data_p)
        return;

    shct_data_p->result_flag = MMI_OP11_HS32_RESULT_UPDATE;
    mmi_clog_op11_hs32_shct_get_data(shct_data_p);
	shct_data_p->item_count = (S32) srv_clog_get_unread_missed_call_num();
    mmi_op11_hs32_answer_shct_data(MMI_OP11_HS32_AP_CLL, MMI_OP11_HS32_SHCT_CLL_CALL_LOG, shct_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_shct_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_op11_hs32_shct_get_data(mmi_op11_hs32_shct_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_clog_hs_get_data_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_hs_init_get_data_req(&req_data);
    req_data.max_size = MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX;
    req_data.req_num = MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX;
    req_data.skip_read = MMI_TRUE;
    req_data.only_new_event = MMI_FALSE;
    req_data.need_cid = MMI_TRUE;
    req_data.data_list = (void*)data;
    req_data.parse_info_hdlr = mmi_clog_op11_hs32_shct_parse_data;

    handle = mmi_clog_hs_get_data_create(&req_data, MMI_TRUE);
    mmi_clog_hs_get_data_run(handle);
    mmi_clog_hs_get_data_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_op11_hs32_shct_parse_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_list       [IN]         
 *  max_size        [IN]        
 *  index           [IN]        
 *  log_info        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_op11_hs32_shct_parse_data(
            void *data_list,
            U32 max_size,
            U32 index,
            mmi_clog_hs_get_data_log_info_struct *log_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_shct_data_struct *data = (mmi_op11_hs32_shct_data_struct*) data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy(data->item_content[index], log_info->cid, MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX);
    mmi_wcsncpy(data->item_name[index], log_info->name, MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX);
    memcpy(&data->item_time[index], &log_info->timestamp, sizeof(applib_time_struct));
    data->item_uid[index] = (S32) log_info->log_id;
    data->item_count++;
    return MMI_TRUE;
}

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

#endif /* __MMI_CLOG_ADP__ */ 

