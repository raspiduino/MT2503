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
*  CallLogSrvStoreEn.c
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
#include "mmi_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "nvram_enums.h"
#include "common_nvram_editor_data_item.h"

#include "MMIDataType.h"
#include "mmi_frm_nvram_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvProt.h"

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

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/



/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_read_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_mgr      [?]         
 *  st_id       [IN]        
 *  log         [?]         
 * RETURNS
 *  
 * RETURN VALUES
 *  
 *****************************************************************************/
S32 srv_clog_st_read_log(SRV_CLOG_ID st_id, srv_clog_st_log_struct *log)
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
            NVRAM_EF_CLOG_LOG_LID,
            (U16) (st_id + 1),
            (void*)log,
            (U16) (sizeof(srv_clog_st_log_struct)),
            (S16*) & err);
    if (ret == sizeof(srv_clog_st_log_struct))
        return SRV_CLOG_RET_OK;
    return SRV_CLOG_RET_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_read_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_mgr      [?]         
 *  st_id       [IN]        
 *  num         [IN]        
 *  logs        [?]         
 * RETURNS
 *  
 * RETURN VALUES
 *  
 *****************************************************************************/
S32 srv_clog_st_read_logs(SRV_CLOG_ID st_id, U32 num, srv_clog_st_log_struct *logs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadMultiRecord(
            NVRAM_EF_CLOG_LOG_LID,
            (U16) (st_id + 1),
            (void*)logs,
            (U16) (sizeof(srv_clog_st_log_struct) * num),
            (U16) num,
            (S16*) & err);
    if (ret > 0 && ret % sizeof(srv_clog_st_log_struct) == 0)
        return ret / sizeof(srv_clog_st_log_struct);
    return SRV_CLOG_RET_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_write_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_mgr      [?]         
 *  st_id       [IN]        
 *  log         [?]         
 * RETURNS
 *  
 * RETURN VALUES
 *  
 *****************************************************************************/
static srv_clog_ret_enum srv_clog_st_write_log(SRV_CLOG_ID st_id, srv_clog_st_log_struct *log)
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
            NVRAM_EF_CLOG_LOG_LID,
            (U16) (st_id + 1),
            (void*)log,
            (U16) (NVRAM_EF_CLOG_LOG_SIZE),
            (S16*) & err);
    if (ret == NVRAM_EF_CLOG_LOG_SIZE)
        return SRV_CLOG_RET_OK;
    return SRV_CLOG_RET_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_write_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_mgr      [?]         
 *  st_id       [IN]        
 *  log         [?]         
 * RETURNS
 *  
 * RETURN VALUES
 *  
 *****************************************************************************/
srv_clog_ret_enum srv_clog_st_write_logs(U32 starts, U32 ends, srv_clog_si_struct** si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 cursor = starts/CUSTOM_CLOG_NUM_PER_RECORD;
    U32 max_times;
    U32 num_per;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_times = SRV_CLOG_NUM_ROUNDING((ends-CUSTOM_CLOG_NUM_PER_RECORD*cursor), CUSTOM_CLOG_NUM_PER_RECORD);

    for (i = 0; i < max_times; i++)
    {
        ret = srv_clog_st_write_log(cursor, si_log[CUSTOM_CLOG_NUM_PER_RECORD*cursor]);

        if(ret == SRV_CLOG_RET_OK)
            cursor ++;
        else
            ASSERT(0);
    }

    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_st_log_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  st_log      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_st_log_valid(srv_clog_st_log_struct *st_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!st_log || SRV_CLOG_IS_ELM_INVALID(st_log->log_id))
        return MMI_FALSE;
    /* check other fields */
    if (SRV_CLOG_CHECK_BIT(SRV_CLOG_SILOG_GET_TYPE_ID(st_log), SRV_CLOG_TDP_DELETED))
        return MMI_FALSE;

    return MMI_TRUE;
}



