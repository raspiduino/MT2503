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

/*******************************************************************************
 * Filename:
 * ---------
 * MMSAppUtil.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "MMSAppUtil.h"
// #include "UMGprot.h"
#include "UcAppGProt.h"
// #include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "DateTimeGprot.h"
#include "mma_api.h"
#include "MmsSrvGprot.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mma_struct.h"
#include "WAPProfileSrvType.h"
#include "custom_mmi_default_value.h"
#include "app_datetime.h"
#include "DateTimeType.h"
// #include "SimDetectionStruct.h"
#include "UcSrvGprot.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_srv_mms_def.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_util_mma_folder_to_bgsr_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_bgsr_msg_box_enum mmi_umms_app_util_mma_folder_to_bgsr_folder(mma_folder_enum folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_MMA_TO_BGSR_FOLDER, folderID);

    switch (folderID)
    {
        case MMA_FOLDER_INBOX:
            return SRV_MMS_BGSR_FOLDER_INBOX;
        case MMA_FOLDER_OUTBOX:
            return SRV_MMS_BGSR_FOLDER_OUTBOX;
        case MMA_FOLDER_ARCHIVE:
            return SRV_MMS_BGSR_FOLDER_ARCHIVE;
        default:
            return SRV_MMS_BGSR_FOLDER_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_util_convert_bgsr_folder_to_mma_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_folder_enum mmi_umms_app_util_convert_bgsr_folder_to_mma_folder(srv_mms_bgsr_msg_box_enum folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_TO_MMA_FOLDER, folderID);

    switch (folderID)
    {
        case SRV_MMS_BGSR_FOLDER_INBOX:
            return MMA_FOLDER_INBOX;
        case SRV_MMS_BGSR_FOLDER_OUTBOX:
            return MMA_FOLDER_OUTBOX;
        case SRV_MMS_BGSR_FOLDER_ARCHIVE:
            return MMA_FOLDER_ARCHIVE;
        default:
            return MMA_FOLDER_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* if ((GetActiveScreenId() == SCR_CM_ACTIVECALLSCREEN) ||
           (GetActiveScreenId() == ITEMSCR_INCOMING_CALL) ||
           (GetActiveScreenId() == SCR1004_CM_DISPENDCALLDURATION) ||
           (GetActiveScreenId() == SCR1001_CM_OUTGOINGCALLSCREEN) || (GetActiveScreenId() == SCR_CM_NOTIFYCALLABORTED)) */
        {
            return MMI_TRUE;
        }
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_util_convert_to_wap_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_util_convert_to_wap_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {

        case MMA_SIM_ID_SIM1:
            return SRV_WAP_PROF_SIMID_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
            return SRV_WAP_PROF_SIMID_SIM2;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* defined( __MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) */

    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
            return SRV_WAP_PROF_SIMID_SIM3;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 

    #if(MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
            return SRV_WAP_PROF_SIMID_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ 

        default:
            return SRV_WAP_PROF_SIMID_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  umms_get_current_utc_time
 * DESCRIPTION
 *  returns current time
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 umms_get_current_utc_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timeSecs;
    FLOAT tz;
    U32 tzdiff = 0;
    MYTIME t;
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&t);
    timeSecs = (U32)mmi_dt_mytime_2_utc_sec(&t, KAL_TRUE);
    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;
    if (tz > 0)
    {
        return (U32) (timeSecs - tzdiff);
    }
    else
    {
        return (U32) (timeSecs + tzdiff);
    }
}

#if(MMI_MAX_SIM_NUM >= 2)

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_convert_to_uc_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_convert_to_uc_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {

        case MMI_SIM1:
            return UC_SIM_ID_GSM_SIM1;
            break;
        case MMI_SIM2:
            return UC_SIM_ID_GSM_SIM2;
            break;
        case MMI_SIM3:
            return UC_SIM_ID_GSM_SIM2;
            break;
        case MMI_SIM4:
            return UC_SIM_ID_GSM_SIM2;
            break;
        default:
            return UC_SIM_ID_UNCLASSIFIED;
            break;
    }
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_util_get_string_for_msg_dr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status          [IN]        
 *  sim_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_util_get_string_for_msg_dr_status(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case MMA_DR_STATUS_RETRIEVED:
            return STR_ID_UMMS_STATUS_DELIVERED;
        case MMA_DR_STATUS_FORWARDED:
            return STR_ID_UMMS_STATUS_FORWARDED;
        case MMA_DR_STATUS_DEFERRED:
            return STR_ID_UMMS_STATUS_DEFERRED;
        case MMA_DR_STATUS_PENDING:
            return STR_ID_UMMS_STATUS_PENDING;
        case MMA_DR_STATUS_EXPIRED:
            return STR_ID_UMMS_STATUS_EXPIRED;
        case MMA_DR_STATUS_REJECTED:
            return STR_ID_UMMS_STATUS_REJECTED;
        case MMA_DR_STATUS_UNRECOGNISED:
            return STR_ID_UMMS_STATUS_UNRECOGNIZED;
        case MMA_DR_STATUS_UNREACHABLE:
            return STR_ID_UMMS_STATUS_UNREACHABLE;
        case MMA_DR_STATUS_INDETERMINATE:
            return STR_ID_UMMS_STATUS_INTERMEDIATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_util_get_string_for_msg_rr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status          [IN]        
 *  sim_id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_util_get_string_for_msg_rr_status(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case MMA_RR_STATUS_READ:
            return STR_ID_UMMS_STATUS_READ;
        case MMA_RR_STATUS_DELETED_NO_READ:
            return STR_ID_UMMS_STATUS_DELETED_WITHOUT_READ;
        case MMA_RR_STATUS_PENDING:
            return STR_ID_UMMS_STATUS_PENDING;
    }
}
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ /* __MMI_MMS_REPORT_BOX_SUPPORT__ */

#endif /* __MMI_MMS_2__ */ 

