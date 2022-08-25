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
*  CallLogSrvCallTime.c
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_CLOG_CALL_TIME__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_include.h"

#include "nvram_common_defs.h"

#include "MMIDataType.h"
#include "mmi_frm_nvram_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
/* Total record numbers, it's SIM_MAX_NUM * CALL_TYPE_MAX_NUM, it's 12 to support Gemini+ */
#define SRV_CLOG_CTIME_RECORD_MAX_NUM           (NVRAM_EF_CLOG_CALL_TIME_TOTAL)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_CTIME_TYPE_ITEMS  (3) // voice, video, voip
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
static void srv_clog_ctime_cp_ef_data(mmi_sim_enum sim_id,
                                      srv_clog_call_type_enum call_type,
                                      srv_clog_ctime_data_struct *mem_data, 
                                      nvram_ef_clog_call_time_struct *store_data);

static void srv_clog_ctime_add_ef_data(nvram_ef_clog_call_time_struct *ef_data, srv_clog_clt_enum clt_type, U32 last_time);
static void srv_clog_ctime_reset_ef_data(nvram_ef_clog_call_time_struct *ef_data, U32 fields);

static S32 srv_clog_ctime_read_multi_records(nvram_ef_clog_call_time_struct *ef_data, U32 start_idx, U32 rec_num);
static S32 srv_clog_ctime_read_record(nvram_ef_clog_call_time_struct *data, U32 index);
static S32 srv_clog_ctime_write_record(nvram_ef_clog_call_time_struct *data, U32 index);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_CTIME_IF


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  call_type       [IN]        
 *  data            [?]         
 *  data_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_ctime_get_data(
        mmi_sim_enum sim_id,
        srv_clog_call_type_enum call_type,
        srv_clog_ctime_op_type_enum op_type,
        srv_clog_ctime_data_struct *data,
        U32 data_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    S32 ret;
    U32 index;
    mmi_sim_enum cur_sim_id;
    srv_clog_call_type_enum cur_call_type;    
    srv_clog_ctime_data_struct *cur_data;
    nvram_ef_clog_call_time_struct ef_time_data[SRV_CLOG_CTIME_RECORD_MAX_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, sim_id) || 
        !SRV_CLOG_CHECK_BIT(SRV_CLOG_CALL_TYPE_ALL, call_type) || 
        !data || !data_num || op_type >= SRV_CLOG_CTIME_OP_TYPE_MAX_ITEM)
        return SRV_CLOG_RET_INVALID_PARAM;

    if (op_type == SRV_CLOG_CTIME_OP_TYPE_MULTI && 
        data_num <= SRV_CLOG_SIM_IDX_MAX_ITEM * SRV_CLOG_CTIME_TYPE_ITEMS)
        return SRV_CLOG_RET_INVALID_PARAM;
    
    memset(data, 0x0, sizeof(srv_clog_ctime_data_struct) * data_num);
    ret = srv_clog_ctime_read_multi_records((nvram_ef_clog_call_time_struct*)ef_time_data, 0, SRV_CLOG_CTIME_RECORD_MAX_NUM);
    if (ret != SRV_CLOG_RET_OK)
    {
        return ret;
    }

    /* SRV_CLOG_SIM_IDX_MAX_ITEM can change according to different SIM number,
      while SRV_CLOG_CTIME_TYPE_ITEMS is fix on different SIM projects,
      so it will not affect the data_list and its index. */
    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        cur_sim_id = (mmi_sim_enum)SRV_CLOG_IDX2BIT(i);
        if (!SRV_CLOG_CHECK_BIT(sim_id, cur_sim_id))
            continue;

        for (j = 0; j < SRV_CLOG_CTIME_TYPE_ITEMS; j++)
        {
            cur_call_type = (srv_clog_call_type_enum)SRV_CLOG_IDX2BIT(j);
            if (SRV_CLOG_CHECK_BIT(call_type, cur_call_type))
            {
                index = i * SRV_CLOG_CTIME_TYPE_ITEMS + j;
                if (op_type == SRV_CLOG_CTIME_OP_TYPE_SINGLE)
                    cur_data = data;
                else
                    cur_data = &data[index];
              srv_clog_ctime_cp_ef_data(cur_sim_id, cur_call_type, cur_data, &ef_time_data[index]);
            }
        }
    }

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  call_type       [IN]        
 *  fields          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_ctime_reset_data(mmi_sim_enum sim_id, srv_clog_call_type_enum call_type, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    S32 ret;
    U32 index = 0;
    nvram_ef_clog_call_time_struct ef_data_list[SRV_CLOG_CTIME_RECORD_MAX_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, sim_id) ||
        !SRV_CLOG_CHECK_BIT(SRV_CLOG_CALL_TYPE_ALL, call_type) ||
        !(fields == 0 || SRV_CLOG_CHECK_BIT(SRV_CLOG_CTIME_FIELD_ALL, fields)))
        return SRV_CLOG_RET_INVALID_PARAM;

    ret = srv_clog_ctime_read_multi_records((nvram_ef_clog_call_time_struct*)ef_data_list, 0, SRV_CLOG_CTIME_RECORD_MAX_NUM);
    if (ret != SRV_CLOG_RET_OK)
    {
        return ret;
    }

    for (i = 0; i < SRV_CLOG_SIM_IDX_MAX_ITEM; i++)
    {
        if (!SRV_CLOG_CHECK_BIT(sim_id, SRV_CLOG_IDX2BIT(i)))
            continue;
        
        for (j = 0; j < SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM; j++)
        {
            if (SRV_CLOG_CHECK_BIT(call_type, SRV_CLOG_IDX2BIT(j)))
            {
                index = i * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM + j;
                srv_clog_ctime_reset_ef_data(&ef_data_list[index], fields);
                srv_clog_ctime_write_record(&ef_data_list[index], index);
            }
        }
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_update_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  call_type       [IN]        
 *  last_type       [IN]        
 *  last_time       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_ctime_update_data(mmi_sim_enum sim_id, srv_clog_call_type_enum call_type, 
                               srv_clog_clt_enum clt_type, U32 last_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 ef_idx;
    U32 sim_idx;
    U32 ct_idx;
    nvram_ef_clog_call_time_struct ef_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);
    SRV_CLOG_BIT2IDX(call_type, ct_idx);
    ef_idx = sim_idx * SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM + ct_idx;
    ret = srv_clog_ctime_read_record(&ef_data, ef_idx);
    if (ret != SRV_CLOG_RET_OK)
        return ret;
    
    srv_clog_ctime_add_ef_data(&ef_data, clt_type, last_time);
    return srv_clog_ctime_write_record(&ef_data, ef_idx);
}

#define SRV_CLOG_CTIME_GET_UTILS



/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_cp_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 *  dst     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ctime_cp_ef_data(mmi_sim_enum sim_id,
                                      srv_clog_call_type_enum call_type,
                                      srv_clog_ctime_data_struct *mem_data, 
                                      nvram_ef_clog_call_time_struct *store_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* can to acculate more than one ef data, mem_data should be memset before first to use it */
    mem_data->sim_id = sim_id;
    mem_data->call_type = call_type;
    mem_data->last_dialed += store_data->last_dialed;
    mem_data->last_recved += store_data->last_recved;
    mem_data->total_dialed += store_data->total_dialed;
    mem_data->total_recved += store_data->total_recved;
    mem_data->last_type = (srv_clog_clt_enum)store_data->last_type;
    mem_data->life += store_data->life;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_add_ef_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  last_time       [IN]        
 *  last_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ctime_add_ef_data(nvram_ef_clog_call_time_struct *ef_data, srv_clog_clt_enum clt_type, U32 last_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clt_type == SRV_CLOG_CLT_DIALED)
    {
        ef_data->last_dialed = last_time;
        ef_data->total_dialed += last_time;
    }
    else
    {
        ef_data->last_recved = last_time;
        ef_data->total_recved += last_time;
    }
    ef_data->last_type = clt_type;
    ef_data->life += last_time;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_reset_ef_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  fields      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_ctime_reset_ef_data(nvram_ef_clog_call_time_struct *ef_data, U32 fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fields == 0)
        fields = SRV_CLOG_CTIME_FIELD_ALL;
    
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CTIME_FIELD_LAST_DIALED))
    {
        ef_data->last_dialed = 0;
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CTIME_FIELD_LAST_RECVED))
    {
        ef_data->last_recved = 0;
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CTIME_FIELD_TOTAL_DIALED))
    {
        ef_data->total_dialed = 0;
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CTIME_FIELD_TOTAL_RECVED))
    {
        ef_data->total_recved = 0;
    }
    if (SRV_CLOG_CHECK_BIT(fields, SRV_CLOG_CTIME_FIELD_LIFE))
    {
        ef_data->life = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_read_multi_records
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  start_idx       [IN]        
 *  rec_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_ctime_read_multi_records(nvram_ef_clog_call_time_struct *ef_data, U32 start_idx, U32 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    S32 ret;
    U16 total_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_size = sizeof(nvram_ef_clog_call_time_struct) * rec_num;
    
    ret = ReadMultiRecord(
            NVRAM_EF_CLOG_CALL_TIME_LID,
            (U16) (start_idx + 1),
            (void*)ef_data,
            total_size,
            (U16) rec_num,
            &err);

    if (ret <= 0 && ret != total_size)
        return SRV_CLOG_RET_FAIL;
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_read_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_ctime_read_record(nvram_ef_clog_call_time_struct *data, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadRecord(
            NVRAM_EF_CLOG_CALL_TIME_LID,
            (U16) (index + 1),
            (void*)data,
            sizeof(nvram_ef_clog_call_time_struct),
            &err);
    if (ret == sizeof(nvram_ef_clog_call_time_struct))
        return SRV_CLOG_RET_OK;
    return SRV_CLOG_RET_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_write_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_ctime_write_record(nvram_ef_clog_call_time_struct *data, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = WriteRecord(
            NVRAM_EF_CLOG_CALL_TIME_LID,
            (U16) (index + 1),
            (void*)data,
            (U16) (sizeof(nvram_ef_clog_call_time_struct)),
            &err);

    if (ret == sizeof(nvram_ef_clog_call_time_struct))
        return SRV_CLOG_RET_OK;
    return SRV_CLOG_RET_FAIL;

}

#endif /* __MMI_CLOG_CALL_TIME__ */


