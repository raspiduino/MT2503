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
 *  CentralConfigAgentMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Main: primitive handlers / memory management / init / deinit
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

#ifdef __MMI_CCA_SUPPORT__


/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"
#include "kal_release.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"

#include "mmi_rp_app_cca_def.h"
#include "CentralConfigAgentGProt.h"
#include "CentralConfigAgentProt.h"

#include "CcaSrvGprot.h"
#include "CcaSrvIprot.h"

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
 *  mmi_cca_get_module_id_by_app
 * DESCRIPTION
 *  get application display name
 * PARAMETERS
 *  config_id       [IN]        
 *  with_colon      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID_TYPE mmi_cca_get_app_names(U16 config_id, MMI_BOOL with_colon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (config_id)
    {
        case SRV_CCA_CONFIG_DTACCT:
            return (with_colon == MMI_FALSE ? STR_GLOBAL_DATA_ACCOUNT : STR_ID_CCA_DATA_ACCOUNT_WITH_COLON);

#ifdef __MMI_WLAN_OTAP_OMAEXT__
        case SRV_CCA_CONFIG_WLAN:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_WLAN : STR_ID_CCA_WLAN_WITH_COLON);
#endif /* __MMI_WLAN_OTAP_OMAEXT__ */


#ifdef BROWSER_SUPPORT
        case SRV_CCA_CONFIG_BROWSER:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_BROWSER : STR_ID_CCA_BROWSER_WITH_COLON);
#endif /* BROWSER_SUPPORT */

#ifdef MMS_SUPPORT
        case SRV_CCA_CONFIG_MMS:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_MMS : STR_ID_CCA_MMS_WITH_COLON);
#endif /* MMS_SUPPORT */ 

/*
        case SRV_CCA_CONFIG_SIP:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_SIP : STR_ID_CCA_SIP_WITH_COLON);
*/


#ifdef __MMI_EMAIL_OTAP__
        case SRV_CCA_CONFIG_EMAIL:
            return (with_colon == MMI_FALSE ? STR_GLOBAL_EMAIL : STR_ID_CCA_EMAIL_WITH_COLON);
#endif /* __MMI_EMAIL_OTAP__ */ 

#ifdef __MMI_SYNCML_CCA_SUPPORT__
        case SRV_CCA_CONFIG_SYNCMLDS:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_SYNCMLDS : STR_ID_CCA_SYNCMLDS_WITH_COLON);
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

#ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_CONFIG_SYNCMLDM:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_SYNCMLDM : STR_ID_CCA_SYNCMLDM_WITH_COLON);
#endif /* SYNCML_DM_SUPPORT */ 

#ifdef __MMI_IMPS_OTA__
        case SRV_CCA_CONFIG_IMPS:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_IMPS : STR_ID_CCA_IMPS_WITH_COLON);
#endif /* __MMI_IMPS_OTA__ */ 

    #ifdef __MMI_WLAN_OTAP_DMP__    /* DMP Spec -- WLAN */
        case SRV_CCA_CONFIG_WLAN_DMP:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_WLAN : STR_ID_CCA_WLAN_WITH_COLON);
    #endif /* __MMI_WLAN_OTAP_DMP__ */ 

#ifdef __MMI_VOIP_OTAP_DMP__    /* DMP Spec -- SIP */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */ 

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
        case SRV_CCA_CONFIG_PUSH:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_PUSH : STR_ID_CCA_PUSH_WITH_COLON);
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

#ifdef __MMI_STREAMING_OTAP__
        case SRV_CCA_CONFIG_RTSP:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_RTSP : STR_ID_CCA_RTSP_WITH_COLON);
#endif /* __MMI_STREAMING_OTAP__ */ 

#ifdef __MMI_AGPS_OTAP__
        case SRV_CCA_CONFIG_SUPL:
            return (with_colon == MMI_FALSE ? STR_ID_CCA_SUPL : STR_ID_CCA_SUPL_WITH_COLON);
#endif /* __MMI_AGPS_OTAP__ */ 
            
        default:
            break;
    }
    return 0;
}


#endif /* __MMI_CCA_SUPPORT__ */ 




