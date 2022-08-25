/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  dmuiapp.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file for DMUI application.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/

#ifdef SYNCML_DM_SUPPORT
#include "InlineCuiGprot.h"
#include "menucuigprot.h"
#include "mmi_rp_app_dmui_def.h"
#include "dmuiprot.h"
#include "Custom_syncml_dm_config.h"

/* DM PS head file */
#include "DMTypeDef.h"
#include "DMGprot.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#include "FileMgrSrvGProt.h"
#include "App_str.h"

/* URL check function head file */
#include "app_url.h"

/* Data Account type define header file */
#include "DataAccountGprot.h"
#include "DataAccountCUIGprot.h"
#include "DtcntSrvGprot.h"
#include "CbmSrvGprot.h"
#include "CommonScreens.h"
#include "cbfunc.h"
#include "BootupSrvGprot.h"
#include "AlarmFrameWorkProt.h"
#include "UcmSrvGprot.h"
#ifdef __DM_FOTA_SUPPORT__
#ifndef OMADM
#include "Mvamgrupdateagentinterface.h" /* for TDL_UPDATE_SUCCESSFUL */
#else
#include "dmpsupdateagentinterface.h" /* for TDL_UPDATE_SUCCESSFUL */
#endif
#endif /* __DM_FOTA_SUPPORT__ */

#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
#endif
#include "ProfilesSrvGprot.h"
#include "Nwinfosrvgprot.h"
#include "ModeSwitchSrvGProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "custom_mmi_default_value.h"
#include "cbm_api.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmiapi_dm_struct.h"
#include "SimCtrlSrvGprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "custom_data_account.h"
#include "cbm_consts.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "NotificationGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "CommonScreensResDef.h"
#include "stdio.h"
#include "gui_data_types.h"
#include "gui.h"
#include "browser_api.h"
#include "custom_events_notify.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_inputs.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "wgui_datetime.h"
#include "wgui_categories.h"
#include "wps_struct.h"
#include "wgui_categories_popup.h"
#include "fs_errcode.h"
#include "dmuigprot.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "PhoneSetup.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif /* __MMI_USB_SUPPORT__ */
#ifdef __DM_LAWMO_SUPPORT__
#include "rmmi_struct.h"
#endif
/***************************************************************************** 
* define
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __DM_MO_SUPPORT__
static mmi_dmui_mo_context_struct g_mmi_dmui_mo_cntx;
static mmi_dmui_mo_context_struct *g_mmi_dmui_mo_cntx_ptr = &g_mmi_dmui_mo_cntx;
#endif /* __DM_MO_SUPPORT__ */
#ifdef __DM_LAWMO_SUPPORT__
static U8 g_mmi_dmui_is_phone_lawmo_locked;
#endif /* __DM_LAWMO_SUPPORT__ */
#ifdef __DM_SCOMO_SUPPORT__
static MMI_BOOL g_dmui_scomo_waiting_ps_rsp_operate_by_user;
#endif /* __DM_SCOMO_SUPPORT__ */
dmui_context_struct dmui_context;
dmui_context_struct *ptr_dmui_context = &dmui_context;

/* CBM change */
U8 g_mmi_dmui_cbm_id;

static S32 dl_session_id;
static MMI_BOOL g_dmui_dtcnt_sel_finish;
static dmui_confirm_struct dmui_confirm;
static dmui_prompt_message_struct dmui_prompt_message;

static MMI_BOOL is_network_timeout;
static dm_network_state_enum g_mmi_dmui_network_state = DM_NETWORK_AVAILABLE;

static U32 init_get_account_count;

static dm_ui_mode_enum session_uimode;
static MMI_BOOL g_mmi_dmui_is_in_session;
static MMI_BOOL g_mmi_dmui_download_resume_is_need_confirm = MMI_TRUE;
S8 *g_mmi_dmui_waiting_screen_msg;
#ifdef __DM_FOTA_SUPPORT__
static U8 g_mmi_dmui_fota_is_update;
static MMI_BOOL g_mmi_dmui_fota_is_update_success;
static U32 g_mmi_dmui_fota_update_defer_time;
static S32 g_mmi_dmui_fota_update_defer_highlight_item;
static U8 g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_TOTAL][MMI_DMUI_STR_BUFFER_SIZE];
#endif /* __DM_FOTA_SUPPORT__ */
static MMI_BOOL g_mmi_dmui_is_reg_sim_available;
static U32 g_current_data_account_id;
static MMI_BOOL g_dmui_is_doing_restore_factory;
static dmui_fota_status_enum g_dmui_fota_status;

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Variable
*****************************************************************************/
#ifdef __MMI_SYNCML_DM_OTAP__
extern syncml_dm_ota_context_struct *g_syncml_dm_ota_context;
#endif 

extern MMI_BOOL b_profile_updated;

/***************************************************************************** 
* External Function
*****************************************************************************/
extern kal_int8 *app_ucs2_itoa (kal_int32 val, kal_int8 *buf, kal_int32 radix);
extern void mmi_dm_set_check_function(dm_setting_type_enum type, DMCheckCBFunc func);
extern void mmi_dm_print_info(dm_account_struct *ptr_dm_account);
extern void mmi_dm_unfinish_check_info(void);
extern kal_bool dm_update_account(kal_int32 old_account, kal_int32 new_account);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
/*****************************************************************************
* Local Function 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init
 * DESCRIPTION
 *  init DMUI main menu function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct cbm_app_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_FUNCTION);
    /*--------------- protocol event handler for message from DM PS -------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        {
        #ifdef __DM_LAWMO_SUPPORT__
            ReadValue(NVRAM_DM_LOCK_STATUS, &g_mmi_dmui_is_phone_lawmo_locked, DS_BYTE, &error);
            if (g_mmi_dmui_is_phone_lawmo_locked == 1)
            {
                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REBOOT_LOCK);
                g_mmi_dmui_mo_cntx_ptr->mo_cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
                g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK;
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REBOOT_UNLOCK);
                g_mmi_dmui_is_phone_lawmo_locked = 0;
                g_mmi_dmui_mo_cntx_ptr->mo_cmd = -1;
            }
        #endif /* __DM_LAWMO_SUPPORT__ */
        }
            break;

        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
        {
            if (srv_sim_ctrl_any_sim_is_available() == MMI_TRUE)
            {
                /* get add server id message response from DM PS */
                SetProtocolEventHandler(mmi_dmui_add_account_rsp_handle, MSG_ID_DM_ADD_ACCOUNT_RSP);

                /* get del server id message response from DM pS */
                SetProtocolEventHandler(mmi_dmui_del_account_rsp_handle, MSG_ID_DM_DEL_ACCOUNT_RSP);

                /* get info of server id message response from DM PS */
                SetProtocolEventHandler(mmi_dmui_get_account_rsp_handle, MSG_ID_DM_GET_ACCOUNT_RSP);

                /* get server list message from DM PS */
                SetProtocolEventHandler(mmi_dmui_list_serverid_rsp_handle, MSG_ID_DM_LIST_SERVERID_RSP);

                /* get primary server id message from DM PS */
                SetProtocolEventHandler(mmi_dmui_get_pserverid_rsp_handle, MSG_ID_DM_GET_PSERVERID_RSP);

                /* set primary server id message from DM PS */
                SetProtocolEventHandler(mmi_dmui_set_pserverid_rsp_handle, MSG_ID_DM_SET_PSERVERID_RSP);

                /* get init session message from DM PS */
                SetProtocolEventHandler(mmi_dmui_init_session_ind_handle, MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND);

                /* get user pin request from DM PS */
                SetProtocolEventHandler(mmi_dmui_userpin_ind_handle, MSG_ID_DM_GET_BOOTSTRAP_USERPIN_REQ_IND);

                /* get download request from DM PS */
                //SetProtocolEventHandler(mmi_dmui_download_ind_handle, MSG_ID_DM_DL_REQ_IND);

                /* get update request from DM PS */
#ifdef __DM_FOTA_SUPPORT__
                SetProtocolEventHandler(mmi_dmui_fota_update_req_ind_hdlr, MSG_ID_DM_UPDATE_REQ_IND);
                SetProtocolEventHandler(mmi_dmui_reset_ind_handle, MSG_ID_DM_RESET_IND);
#endif /* __DM_FOTA_SUPPORT__ */
                /* receive alert indication from DM PS */
                SetProtocolEventHandler(mmi_dmui_alert_ind_handle, MSG_ID_DM_ALERT_REQ_IND);

                SetProtocolEventHandler(mmi_dmui_download_progress_ind_handle, MSG_ID_DM_DL_PROGRESS_IND);

                SetProtocolEventHandler(mmi_dmui_exec_complete_ind_handle, MSG_ID_DM_EXEC_COMPLETE_IND);
                SetProtocolEventHandler(mmi_dmui_session_start_ind_handle, MSG_ID_DM_SESSION_START_IND);
                SetProtocolEventHandler(mmi_dmui_session_finish_ind_handle, MSG_ID_DM_SESSION_FINISH_IND);
                SetProtocolEventHandler(mmi_dmui_error_ind_handle, MSG_ID_DM_ERROR_IND);

                /* receive start oma dl indication from DM PS */
                SetProtocolEventHandler(mmi_dmui_start_dl_ind_handle, MSG_ID_DM_START_DL_REQ_IND);

                /* receive resume to download indication from DM PS */
                SetProtocolEventHandler(mmi_dmui_dl_resume_ind_handle, MSG_ID_DM_DL_RESUME_REQ_IND);

                /* receive dm session status from DM PS */
                SetProtocolEventHandler(mmi_dmui_ps_status_ind_handle, MSG_ID_DM_PS_STATUS_IND);

                /* receive da status pause from DM MMI */
                SetProtocolEventHandler(mmi_dmui_da_state_pause_ind_handle, MSG_ID_DM_DA_STATE_PAUSE);

                /* receive da status abort from DM MMI */
                SetProtocolEventHandler(mmi_dmui_da_state_abort_ind_handle, MSG_ID_DM_DA_STATE_ABORT);

                /* receive da status complete from DM MMI */
                SetProtocolEventHandler(mmi_dmui_da_state_complete_ind_handle, MSG_ID_DM_DA_STATE_COMPLETE);
#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
#endif
                SetProtocolEventHandler(mmi_dmui_init_config_info_cnf_hdlr, MSG_ID_DM_INIT_CONFIG_INFO_CNF);
#ifdef __DM_SCOMO_SUPPORT__
                SetProtocolEventHandler(mmi_dmui_scomo_install_by_srv_ind_hdlr, MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND);
                SetProtocolEventHandler(mmi_dmui_scomo_remove_by_srv_ind_hdlr, MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND);
                SetProtocolEventHandler(mmi_dmui_scomo_install_by_user_rsp_hdlr, MSG_ID_DM_SCOMO_INSTALL_BY_USER_RSP);
                SetProtocolEventHandler(mmi_dmui_scomo_remove_by_user_rsp_hdlr, MSG_ID_DM_SCOMO_REMOVE_BY_USER_RSP);
#endif /* __DM_SCOMO_SUPPORT__ */
                SetProtocolEventHandler(mmi_dmui_conn_with_dtcnt_ind_hdlr, MSG_ID_DM_CONN_WITH_DTCNT_IND);


                /* CBM change */
                cbm_app_info.app_str_id = STR_ID_DMUI_MAIN;
                cbm_app_info.app_icon_id = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
                cbm_app_info.app_type = DTCNT_APPTYPE_DM;
                cbm_register_app_id_with_app_info(&cbm_app_info, &g_mmi_dmui_cbm_id);

            #ifdef __DM_FOTA_SUPPORT__
            #ifdef __MTK_TARGET__
                /* if fota update success, remind user */
                ReadValue(NVRAM_DM_FOTA_UPDATE_FLAG, &g_mmi_dmui_fota_is_update, DS_BYTE, &error);
                if (g_mmi_dmui_fota_is_update)
                {
                    if(FOTA_InitializeUpdateRecord() >= 0)
                    {
                        if (FOTA_Inform_Update_State() == TDL_UPDATE_SUCCESSFUL)
                        {
                            /* success */ 
                            g_mmi_dmui_fota_is_update_success = MMI_TRUE;
                        }
                        else
                        {
                            /* failure */
                            g_mmi_dmui_fota_is_update_success = MMI_FALSE;
                        }
                    }
                }
            #endif /* __MTK_TARGET__ */
            #endif /* __DM_FOTA_SUPPORT__ */

#ifdef __DM_LAWMO_SUPPORT__
                srv_cbm_set_allowed_app_nwk_srv(
                    CBM_BEARER_GSM_GPRS | CBM_BEARER_EDGE | CBM_BEARER_UMTS,
                    g_mmi_dmui_cbm_id);
                if (g_mmi_dmui_is_phone_lawmo_locked == 1)
                {
                    srv_cbm_disallow_nwk_srv(
                        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_EDGE | SRV_CBM_BEARER_UMTS | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
                        g_mmi_dmui_cbm_id);
                }
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

                if (ptr_dmui_context->is_reg_sim_success == MMI_FALSE)
                {
                    dm_init_config_info_req_struct *init_config_info_req;
                    
                    init_config_info_req = OslAllocDataPtr(dm_init_config_info_req_struct);
                #if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
                 #else
                    init_config_info_req->sim_info = CBM_SIM_ID_SIM1;
                #endif
                    init_config_info_req->app_id = g_mmi_dmui_cbm_id;
                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_INIT_CONFIG_INFO_REQ, init_config_info_req);
                }

                mmi_dmui_init_serverid();

                mmi_dm_set_check_function(DM_SETTING_TYPE_DM, (DMCheckCBFunc)mmi_syncml_dm_check);
            }

        #ifdef __DM_LAWMO_SUPPORT__
            SetProtocolEventHandler(mmi_dmui_lawmo_cmd_rsp_hdlr, MSG_ID_RMMI_LOCK_AT_CMD_CNF);
            SetProtocolEventHandler(mmi_dmui_lawmo_req_ind_hdlr, MSG_ID_DM_LAWMO_REQ_IND);
        #ifdef __MTK_TARGET__
            mmi_dmui_lawmo_register_notify(
                MMI_DMUI_APP_ID_ATCI,
                MMI_DMUI_MO_TYPE_LAWMO_LOCK,
                mmi_dmui_send_lawmo_cmd_req);
        #endif /* __MTK_TARGET__ */
        #endif /* __DM_LAWMO_SUPPORT__ */

        #ifndef MMI_DM_3G
            mmi_frm_cb_reg_event(
                EVT_ID_SRV_UCM_STATUS_CHANGE,
                mmi_dmui_ucm_callback_handler,
                NULL);
        #endif /* MMI_DM_3G */
            StartTimer(
                DMUI_WAIT_FOR_APP_INIT_TIMER_ID,
                DMUI_WAIT_FOR_APP_INIT_TIME,
                mmi_dmui_all_app_init_hdlr);
        }
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_all_app_init_hdlr
 * DESCRIPTION
 *  handle something after all MMI App init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_all_app_init_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    /* if the phone is in lock status, lock the phone when boot up */
    if (g_mmi_dmui_mo_cntx_ptr->mo_cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->mo_cmd == MMI_DMUI_CMD_LAWMO_FULLYLOCK)
    {
        mmi_dmui_lawmo_req_ind_hdlr(NULL);
    }
#endif /* __DM_LAWMO_SUPPORT__ */
#ifdef __DM_SCOMO_SUPPORT__
    mmi_dmui_scomo_handle_unfinished_report();
#endif /* __DM_SCOMO_SUPPORT__ */
}


#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init_config_info_cnf_hdlr
 * DESCRIPTION
 *  the message MSG_ID_DM_INIT_CONFIG_INFO_CNF handler
 * PARAMETERS
 *  msg
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_init_config_info_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_init_config_info_cnf_struct *init_config_info_cnf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_config_info_cnf = (dm_init_config_info_cnf_struct*)msg;
    if (init_config_info_cnf->result == DM_RESULT_ERR_SUCC)
    {
        return;
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_highlight_main
 * DESCRIPTION
 *  function of highlight DM UI main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_dmui_launch, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_dmui_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_launch
 * DESCRIPTION
 *  function of entry DMUI main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* could not edit dm account if no sim as dm ps will not init in this status */
    if (srv_sim_ctrl_any_sim_is_available() == MMI_FALSE)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        return;
    }

    if (ptr_dmui_context->dmui_status != MMI_DMUI_IDLE_STATUS)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_BUSY_TRY_LATER),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        return;
    }

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_SETTING,
        mmi_dmui_setting_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    ptr_dmui_context->dmui_hilite_serverid_index = 0;
    mmi_dmui_entry_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_scr_group_proc
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_setting_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;
    cui_dtcnt_select_event_struct *dtcnt_select = (cui_dtcnt_select_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_DMUI_OP_ACTIVATE:
                {
                    mmi_dmui_entry_option_activate();
                    break;
                }

                case MENU_ID_DMUI_OP_EDIT:
                {
                    mmi_dmui_entry_option_edit_pre();
                    break;
                }

                case MENU_ID_DMUI_OP_ERASE:
                {
                    mmi_dmui_entry_option_erase_confirm();
                    break;
                }

            #ifdef MMI_DM_OP
                case MENU_ID_DMUI_OP_VIEW:
                {
                    mmi_dmui_entry_option_edit_pre();
                    break;
                }
            #endif /* MMI_DM_OP */

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
        #ifdef MMI_DM_OP
            if (ptr_dmui_context->dmui_hilite_serverid_index == 0)
            {
                ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
            }
            else
        #endif /* MMI_DM_OP */

            if (set_key_evt->item_id == MMI_DMUI_DATA_ACCOUNT_EDITOR)
            {
                ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetLeftSoftkeyFunction(mmi_dmui_entry_dtcnt_sel, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_dmui_entry_dtcnt_sel, KEY_EVENT_UP);
            }
            break;
        }

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            if (g_dmui_dtcnt_sel_finish == MMI_TRUE)
            {
                cui_inline_set_screen_attributes(ptr_dmui_context->cui_profile_setting_inline_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
                g_dmui_dtcnt_sel_finish = MMI_FALSE;
            }
            break;
        }

        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_dmui_info_checkinput_popup();
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_abort->sender_id);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
            mmi_dmui_dtcnt_sel_save(evt);
            g_dmui_dtcnt_sel_finish = MMI_TRUE;
            cui_dtcnt_select_close(dtcnt_select->sender_id);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
            cui_dtcnt_select_close(dtcnt_select->sender_id);
            break;

        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            cui_dtcnt_select_close(dtcnt_select->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_scr_group_proc
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_global_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_submit_struct *inline_submit = (cui_event_inline_submit_struct*)evt;
    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            if (inline_submit->sender_id == ptr_dmui_context->cui_session_alert_input_inline_id)
            {
                mmi_dmui_alert_input_save_value();
                mmi_dmui_alert_input_confirm();
            }
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_abort->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_main
 * DESCRIPTION
 *  function of entry DMUI main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *gui_buffer = NULL;
    PU8 sub_menu_data_ptrs[DMUI_MAX_SERVERID];
    U16 serverid_states_icon[DMUI_MAX_SERVERID];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ENTRY_MAIN_FUNCTION);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_SETTING, 
                        SCR_ID_DMUI_MAIN,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_main, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_dmui_save_highlight_serverid);

        for (i = 0; i < DMUI_MAX_SERVERID; i++)
        {
            /* if this server ID is empty */
            if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
            {
                sub_menu_data_ptrs[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);

                serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
            }
            else
            {
                sub_menu_data_ptrs[i] = (U8*) ptr_dmui_context->dmui_profile_array[i].server_id;

                if ((mmi_ucs2cmp((S8*) sub_menu_data_ptrs[i], (S8*) ptr_dmui_context->dmui_primary_serverid) == 0)
                    && (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_primary_serverid) != 0))
                {
                    serverid_states_icon[i] = IMG_ID_DMUI_SEL_IMAGE;
                }
                else
                {
                    serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
                }
            }
        }

        ShowCategory73Screen(
            STR_ID_DMUI_MAIN,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            DMUI_MAX_SERVERID,
            sub_menu_data_ptrs,
            serverid_states_icon,
            (U16*) gIndexIconsImageList,
            ptr_dmui_context->dmui_hilite_serverid_index,
            gui_buffer,
            1);

#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_dmui_fte_main_menu_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_main_menu_hide
 * DESCRIPTION
 *  function to check if dmui main menu should be hide or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dmui_main_menu_hide()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_save_highlight_serverid
 * DESCRIPTION
 *  function to save current high light server ID index
 * PARAMETERS
 *  index       [IN]        Current high light item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_save_highlight_serverid(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_hilite_serverid_index = index;

#ifdef MMI_DM_OP
    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_main_default_profile, KEY_EVENT_UP);

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_entry_option_activate, KEY_EVENT_UP);
        return;
    }
#endif /* MMI_DM_OP */

    if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[index].server_id) == 0)
    {
        /* send left soft key function for change feature */
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_edit_pre, KEY_EVENT_UP);

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_entry_option_edit_pre, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_main, KEY_EVENT_UP);

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_entry_option_activate, KEY_EVENT_UP);
    }
}

#ifdef MMI_DM_OP
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_main_default_profile
 * DESCRIPTION
 *  function of entry option screen with default profile item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_main_default_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ENTRY_DEFAULT_PROFILE);
    
    ptr_dmui_context->cui_default_profile_option_menu_id = cui_menu_create(
                                                            GRP_ID_DMAPP_SETTING,
                                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                                            CUI_MENU_TYPE_OPTION,
                                                            MENU_ID_DMUI_OPTION_DEFAULT_PROFILE,
                                                            MMI_TRUE,
                                                            NULL);
    cui_menu_set_default_title_image(
        ptr_dmui_context->cui_default_profile_option_menu_id,
        get_image(GetRootTitleIcon(MENU_ID_DMUI_MAIN)));
    cui_menu_run(ptr_dmui_context->cui_default_profile_option_menu_id);
}
#endif /* MMI_DM_OP */


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_main
 * DESCRIPTION
 *  function of entry option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ENTRY_OPTION_FUNCTION);
    ptr_dmui_context->cui_option_menu_id = cui_menu_create(
                                            GRP_ID_DMAPP_SETTING,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_OPTION,
                                            MENU_ID_DMUI_OPTION,
                                            MMI_TRUE,
                                            NULL);
    cui_menu_set_default_title_image(
        ptr_dmui_context->cui_option_menu_id,
        get_image(GetRootTitleIcon(MENU_ID_DMUI_MAIN)));
    cui_menu_run(ptr_dmui_context->cui_option_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_activate
 * DESCRIPTION
 *  function of entry option activate item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *dmui_active_serverid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_OPTION_ACTIVATE);

    dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

    mmi_ucs2cpy(
        (S8*) dmui_active_serverid->server_id,
        (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

    ptr_dmui_context->dmui_status = MMI_DMUI_SET_PSERVERID_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
    mmi_dmui_waiting_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_edit_pre
 * DESCRIPTION
 *  function of entry option edit item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_edit_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *dmui_get_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_OPTION_EDIT_PRE);

    /* if current server id is empty */
    if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id) == 0)
    {
        memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));

        ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = (U32) CBM_DEFAULT_ACCT_ID;

        ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_port =
            (U32) DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT;

        mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.server_addr, (S8*) L"http://");

        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_addr,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP);

    #ifdef MMI_DM_OP
        if (ptr_dmui_context->dmui_hilite_serverid_index == 0)
        {
            mmi_dmui_entry_option_view();
        }
        else
        {
            mmi_dmui_entry_option_edit();
        }
    #else /* MMI_DM_OP */
        mmi_dmui_entry_option_edit();
    #endif /* MMI_DM_OP */
    }
    else    /* if server id not empty */
    {
        dmui_get_account = OslAllocDataPtr(dm_server_id_struct);

        ptr_dmui_context->dmui_status = MMI_DMUI_GET_ACCOUNT_STATUS;

        mmi_ucs2cpy(
            (S8*) dmui_get_account->server_id,
            (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

        DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_ACCOUNT_REQ, (S8*) dmui_get_account);
        mmi_dmui_waiting_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_edit
 * DESCRIPTION
 *  function of entry option edit item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define ITEM_NUM (MMI_DMUI_INLINE_ITEM_TOTAL - CUI_INLINE_ITEM_ID_BASE)
    cui_inline_struct inline_struct = {0};

    cui_inline_item_caption_struct          caption_1;
    cui_inline_item_text_edit_struct        text_editor_2;
    cui_inline_item_caption_struct          caption_3;
    cui_inline_item_text_edit_struct        text_editor_4;
    cui_inline_item_caption_struct          caption_5;
    cui_inline_item_fullscreen_edit_struct  fullscreen_editor_6;
    cui_inline_item_caption_struct          caption_7;
    cui_inline_item_text_edit_struct        text_editor_8;
    cui_inline_item_caption_struct          caption_9;
    cui_inline_item_text_edit_struct        text_editor_10;
    cui_inline_item_caption_struct          caption_11;
    cui_inline_item_display_only_struct     display_only_12;
    cui_inline_item_caption_struct          caption_13;
    cui_inline_item_select_struct           select_14;

    cui_inline_set_item_struct inline_item[ITEM_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_OPTION_EDIT);
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_NONE] = STR_GLOBAL_NONE;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_BASIC] = STR_ID_DMUI_AUTHTYPE_BASIC;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_MD5] = STR_ID_DMUI_AUTHTYPE_MD5;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_HMAC] = STR_ID_DMUI_AUTHTYPE_HMAC;

    mmi_dtcnt_get_full_account_name(
        (U32)ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
        (S8*)ptr_dmui_context->dmui_cur_edit_account.acct_name,
        DM_MAX_ID_STR/2,
        MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    
    caption_1.string_id = STR_ID_DMUI_SERVERID;
    inline_item[0].item_id = MMI_DMUI_SERVERID;
    inline_item[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[0].image_id = IMG_ID_DMUI_SERVERID;
    inline_item[0].item_data = &caption_1;

    text_editor_2.string_id = 0;
    text_editor_2.default_text_id = 0;
    text_editor_2.buffer_size = DM_MAX_ID_STR / 2;
    text_editor_2.input_type = IMM_INPUT_TYPE_ASCII_CHAR;
    text_editor_2.input_extended_type = 0;
    text_editor_2.required_input_mode_set = NULL;
    inline_item[1].item_id = MMI_DMUI_SERVERID_EDITOR;
    inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[1].image_id = 0;
    inline_item[1].item_data = &text_editor_2;

    caption_3.string_id = STR_ID_DMUI_SERVER_PASSWORD;
    inline_item[2].item_id = MMI_DMUI_SERVER_PASSWORD;
    inline_item[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[2].image_id = IMG_ID_DMUI_SERVER_PASSWORD;
    inline_item[2].item_data = &caption_3;

    text_editor_4.string_id = 0;
    text_editor_4.default_text_id = 0;
    text_editor_4.buffer_size = DM_MAX_ID_STR / 2;
    text_editor_4.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    text_editor_4.input_extended_type = 0;
    text_editor_4.required_input_mode_set = NULL;
    inline_item[3].item_id = MMI_DMUI_SERVER_PASSWORD_EDITOR;
    inline_item[3].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[3].image_id = 0;
    inline_item[3].item_data = &text_editor_4;

    caption_5.string_id = STR_ID_DMUI_SERVER_ADDRESS;
    inline_item[4].item_id = MMI_DMUI_SERVER_ADDRESS;
    inline_item[4].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[4].image_id = IMG_ID_DMUI_SERVER_ADDRESS;
    inline_item[4].item_data = &caption_5;

    fullscreen_editor_6.string_id = 0;
    fullscreen_editor_6.default_text_id = 0;
    fullscreen_editor_6.title = STR_ID_DMUI_SERVER_ADDRESS;
    fullscreen_editor_6.title_icon = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
    fullscreen_editor_6.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_editor_6.input_type = IMM_INPUT_TYPE_URL;
    fullscreen_editor_6.buffer_size = DM_MAX_URI_SIZE / 2;  
    fullscreen_editor_6.required_input_mode_set = NULL;
    inline_item[5].item_id = MMI_DMUI_SERVER_ADDRESS_EDITOR;
    inline_item[5].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    inline_item[5].image_id = 0;
    inline_item[5].item_data = &fullscreen_editor_6;

    caption_7.string_id = STR_GLOBAL_USERNAME;
    inline_item[6].item_id = MMI_DMUI_USERNAME;
    inline_item[6].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[6].image_id = IMG_ID_DMUI_USERNAME;
    inline_item[6].item_data = &caption_7;

    text_editor_8.string_id = 0;
    text_editor_8.default_text_id = 0;
    text_editor_8.buffer_size = DM_MAX_ID_STR / 2;
    text_editor_8.input_type = IMM_INPUT_TYPE_ASCII_CHAR;
    text_editor_8.input_extended_type = 0;
    text_editor_8.required_input_mode_set = NULL;
    inline_item[7].item_id = MMI_DMUI_USERNAME_EDITOR;
    inline_item[7].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[7].image_id = 0;
    inline_item[7].item_data = &text_editor_8;

    caption_9.string_id = STR_ID_DMUI_USER_PASSWORD;
    inline_item[8].item_id = MMI_DMUI_USER_PASSWORD;
    inline_item[8].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[8].image_id = IMG_ID_DMUI_USER_PASSWORD;
    inline_item[8].item_data = &caption_9;

    text_editor_10.string_id = 0;
    text_editor_10.default_text_id = 0;
    text_editor_10.buffer_size = DM_MAX_ID_STR / 2;
    text_editor_10.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    text_editor_10.input_extended_type = 0;
    text_editor_10.required_input_mode_set = NULL;
    inline_item[9].item_id = MMI_DMUI_USER_PASSWORD_EDITOR;
    inline_item[9].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[9].image_id = 0;
    inline_item[9].item_data = &text_editor_10;

    caption_11.string_id = STR_GLOBAL_DATA_ACCOUNT;
    inline_item[10].item_id = MMI_DMUI_DATA_ACCOUNT;
    inline_item[10].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[10].image_id = IMG_ID_DMUI_CONNECTION_SETTING;
    inline_item[10].item_data = &caption_11;

    display_only_12.string_id = 0;
    inline_item[11].item_id = MMI_DMUI_DATA_ACCOUNT_EDITOR;
    inline_item[11].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY;
    inline_item[11].image_id = 0;
    inline_item[11].item_data = &display_only_12;

    caption_13.string_id = STR_ID_DMUI_AUTHTYPE;
    inline_item[12].item_id = MMI_DMUI_AUTHTYPE;
    inline_item[12].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[12].image_id = IMG_ID_DMUI_AUTHTYPE;
    inline_item[12].item_data = &caption_13;

    select_14.n_items = DM_AUTH_TYPE_TOTAL;
    select_14.highlighted_item = ptr_dmui_context->dmui_cur_edit_account.auth_pref;
    select_14.list_of_item_id = (U16*)ptr_dmui_context->mmi_dmui_authtype;
    inline_item[13].item_id = MMI_DMUI_AUTHTYPE_EDITOR;
    inline_item[13].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[13].image_id = 0;
    inline_item[13].item_data = &select_14;

    inline_struct.items_count = (U8)(ITEM_NUM);
    inline_struct.title = STR_GLOBAL_EDIT;   
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    ptr_dmui_context->cui_profile_setting_inline_id = cui_inline_create(GRP_ID_DMAPP_SETTING, &inline_struct);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVERID_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_id);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVER_PASSWORD_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_pw);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVER_ADDRESS_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_addr);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_USERNAME_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.user_name);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_USER_PASSWORD_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.user_pw);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_DATA_ACCOUNT_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.acct_name);
    
    cui_inline_run(ptr_dmui_context->cui_profile_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_view
 * DESCRIPTION
 *  function of entry option view item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define ITEM_NUM (MMI_DMUI_INLINE_ITEM_TOTAL - CUI_INLINE_ITEM_ID_BASE)
    #define HALF_NUM (ITEM_NUM / 2)
    cui_inline_struct inline_struct = {0};
    cui_inline_item_caption_struct          caption[HALF_NUM];
    cui_inline_item_display_only_struct     display_only[HALF_NUM];

    cui_inline_set_item_struct inline_item[ITEM_NUM];
    MMI_ID inline_id = 0;
    S32 i, count;
    U16 icon_list[ITEM_NUM] = 
    {
        IMG_ID_DMUI_SERVERID,
        0,
        IMG_ID_DMUI_SERVER_PASSWORD,
        0,
        IMG_ID_DMUI_SERVER_ADDRESS,
        0,
        IMG_ID_DMUI_USERNAME,
        0,
        IMG_ID_DMUI_USER_PASSWORD,
        0,
        IMG_ID_DMUI_CONNECTION_SETTING,
        0,
        IMG_ID_DMUI_AUTHTYPE,
        0
    };
    static U8 srv_pw_temp_buf[DM_MAX_ID_STR];
    static U8 user_pw_temp_buf[DM_MAX_ID_STR];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_OPTION_EDIT);
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_NONE] = STR_GLOBAL_NONE;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_BASIC] = STR_ID_DMUI_AUTHTYPE_BASIC;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_MD5] = STR_ID_DMUI_AUTHTYPE_MD5;
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_HMAC] = STR_ID_DMUI_AUTHTYPE_HMAC;

    mmi_dtcnt_get_full_account_name(
        (U32)ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
        (S8*)ptr_dmui_context->dmui_cur_edit_account.acct_name,
        DM_MAX_ID_STR/2,
        MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);

    for (i = 0; i < ITEM_NUM; i++)
    {
        inline_item[i].item_id = CUI_INLINE_ITEM_ID_BASE + i;
        inline_item[i].image_id = icon_list[i];

        if (i%2 == 0)
        {
            inline_item[i].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
            inline_item[i].item_data = &caption[i/2];
        }
        else
        {
            inline_item[i].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW;
            inline_item[i].item_data = &display_only[i/2];
            inline_item[i].image_id = 0;
            display_only[i/2].string_id = 0;
        }
    }

    caption[0].string_id = STR_ID_DMUI_SERVERID;
    caption[1].string_id = STR_ID_DMUI_SERVER_PASSWORD;
    caption[2].string_id = STR_ID_DMUI_SERVER_ADDRESS;
    caption[3].string_id = STR_GLOBAL_USERNAME;
    caption[4].string_id = STR_ID_DMUI_USER_PASSWORD;
    caption[6].string_id = STR_ID_DMUI_AUTHTYPE;
    display_only[6].string_id = ptr_dmui_context->mmi_dmui_authtype[ptr_dmui_context->dmui_cur_edit_account.auth_pref];

    inline_struct.items_count = (U8)(ITEM_NUM);
    inline_struct.title = STR_GLOBAL_VIEW;   
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    inline_id = cui_inline_create(GRP_ID_DMAPP_SETTING, &inline_struct);
    cui_inline_set_value(
        inline_id,
        MMI_DMUI_SERVERID_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_id);
    
    count = mmi_wcslen((WCHAR*)ptr_dmui_context->dmui_cur_edit_account.server_pw);
    memset(&srv_pw_temp_buf, 0x00, DM_MAX_ID_STR);
    for (i = 0; i < (count * 2); )
    {
        srv_pw_temp_buf[i++] = '*';
        srv_pw_temp_buf[i++] = 0;
    }
    cui_inline_set_value(
        inline_id,
        MMI_DMUI_SERVER_PASSWORD_EDITOR,
        srv_pw_temp_buf);
    cui_inline_set_value(
        inline_id,
        MMI_DMUI_SERVER_ADDRESS_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_addr);
    cui_inline_set_value(
        inline_id,
        MMI_DMUI_USERNAME_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.user_name);

    count = mmi_wcslen((WCHAR*)ptr_dmui_context->dmui_cur_edit_account.server_pw);
    memset(user_pw_temp_buf, 0x00, DM_MAX_ID_STR);
    for (i = 0; i < (count * 2); )
    {
        user_pw_temp_buf[i++] = '*';
        user_pw_temp_buf[i++] = 0;
    }
    cui_inline_set_value(
        inline_id,
        MMI_DMUI_USER_PASSWORD_EDITOR,
        user_pw_temp_buf);

    cui_inline_delete_item(inline_id, MMI_DMUI_DATA_ACCOUNT);
    cui_inline_delete_item(inline_id, MMI_DMUI_DATA_ACCOUNT_EDITOR);

    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_view
 * DESCRIPTION
 *  function of entry option view item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_dtcnt_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID dtcnt_id;
    cui_dtcnt_select_run_struct select_run_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtcnt_id = cui_dtcnt_select_create(GRP_ID_DMAPP_SETTING);
    select_run_info.account_id = ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id;
    select_run_info.AppMenuID = MENU_ID_DMUI_MAIN;
    select_run_info.str_id = STR_GLOBAL_DATA_ACCOUNT;
    select_run_info.icon_id = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
    select_run_info.app_id = g_mmi_dmui_cbm_id;
    select_run_info.bearers = DATA_ACCOUNT_BEARER_GPRS;
    select_run_info.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    select_run_info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    select_run_info.sim_selection = CUI_DTCNT_SELECT_DUAL_SIM;
    cui_dtcnt_select_set_param(dtcnt_id, &select_run_info);
    cui_dtcnt_select_run(dtcnt_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_view
 * DESCRIPTION
 *  function of entry option view item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_dtcnt_sel_save(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct *dtcnt_select = (cui_dtcnt_select_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_data_account_init = MMI_TRUE;
    ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = dtcnt_select->account_id;
    mmi_dtcnt_get_full_account_name(
        (U32)ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
        (S8*)ptr_dmui_context->dmui_cur_edit_account.acct_name,
        DM_MAX_ID_STR/2,
        MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    cui_inline_set_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_DATA_ACCOUNT_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.acct_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_save_no
 * DESCRIPTION
 *  function to cancel save DM setting operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(ptr_dmui_context->cui_profile_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_checkinput_popup
 * DESCRIPTION
 *  function to pop up "save"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_checkinput_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_DMAPP_SETTING;
    arg.callback = mmi_dmui_save_profile_cnf_cb;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_dmui_save_profile_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_dmui_info_checkinput();
            break;

        case MMI_ALERT_CNFM_NO:
            mmi_dmui_info_save_no();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_value_from_setting_inline
 * DESCRIPTION
 *  function to check user input DM information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_get_value_from_setting_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVERID_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_id);
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVER_PASSWORD_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_pw);
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_SERVER_ADDRESS_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.server_addr);
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_USERNAME_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.user_name);
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_USER_PASSWORD_EDITOR,
        ptr_dmui_context->dmui_cur_edit_account.user_pw);
    cui_inline_get_value(
        ptr_dmui_context->cui_profile_setting_inline_id,
        MMI_DMUI_AUTHTYPE_EDITOR,
        &ptr_dmui_context->dmui_cur_edit_account.auth_pref);

    /* data account info */
    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
                        &proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {
        if (proxy_info.use_proxy)
        {
            S8 temp_proxy_addr[DM_MAX_IP_SIZE];
            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_TRUE;

            sprintf(temp_proxy_addr, "%d.%d.%d.%d", proxy_info.px_addr[0], proxy_info.px_addr[1], proxy_info.px_addr[2], proxy_info.px_addr[3]);
            mmi_asc_to_ucs2(
                (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_addr,
                (S8*)temp_proxy_addr);

            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_port = (U32)proxy_info.px_port;

            mmi_asc_to_ucs2(
                (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_name,
                (S8*)proxy_info.px_authid);

            mmi_asc_to_ucs2(
                (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_pw,
                (S8*)proxy_info.px_authpw);
        }
        else
        {
            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_FALSE;
        }
    }
    else
    {
        ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_checkinput
 * DESCRIPTION
 *  function to check user input DM information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_checkinput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_server_addr[DM_MAX_URI_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dmui_get_value_from_setting_inline();
    mmi_ucs2_to_asc((S8*)temp_server_addr, (S8*)ptr_dmui_context->dmui_cur_edit_account.server_addr);

    if (applib_url_is_valid((const char*)temp_server_addr) != 0 &&
        mmi_ucs2cmp((S8*)temp_server_addr, (S8*)L"http://") != 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS),
            MMI_EVENT_FAILURE,
            GRP_ID_DMAPP_SETTING,
            NULL);
        return;
    }
    
    /* server id is empty */
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_cur_edit_account.server_id) == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DMUI_INFO_SERVERID_EMPTY),
            MMI_EVENT_FAILURE,
            GRP_ID_DMAPP_SETTING,
            NULL);
        return;
    }
    else if (mmi_dmui_serverid_valid((S8*)ptr_dmui_context->dmui_cur_edit_account.server_id) == MMI_FALSE)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DMUI_INFO_SERVERID_INVALID),
            MMI_EVENT_FAILURE,
            GRP_ID_DMAPP_SETTING,
            NULL);
        return;
    }
    else    /* server id not empty */
    {
        U8 index = 0;
        
        if (mmi_ucs2cmp(
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id,
                (S8*)ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id) == 0)
        {
            mmi_dmui_info_save_confirm_serverid_nochanged();
            return;
        }
        
        for (index = 0; index < DMUI_MAX_SERVERID; index++)
        {
            if (mmi_ucs2cmp(
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id,
                    (S8*)ptr_dmui_context->dmui_profile_array[index].server_id) == 0)
            {
                mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_ID_DMUI_INFO_SERVERID_EXIST),
                    MMI_EVENT_FAILURE,
                    GRP_ID_DMAPP_SETTING,
                    NULL);
                return;
            }
        }
        
        if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id) == 0)
        {
            mmi_dmui_info_save_confirm_serverid_nochanged();
        }
        /* entry save confirm screen when server id changed and unique */
        /* in the case need send : del & add command */
        /* if this item activated, need send set command with new server id */
        else if (mmi_ucs2cmp(
                    (S8*)ptr_dmui_context->dmui_primary_serverid,
                    (S8*)ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id) == 0)
        {
            mmi_dmui_info_save_confirm_serverid_activated_changed();
        }
        else
        {
            mmi_dmui_info_save_confirm_serverid_inactivated_changed();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_save_confirm_serverid_nochanged
 * DESCRIPTION
 *  function to save DM info with server id not changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_save_confirm_serverid_nochanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_add_account_struct *dmui_add_account = NULL;
    U8 temp_nodename[DM_MAX_ID_STR];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_add_account = OslAllocDataPtr(dm_add_account_struct);

    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

    gui_itoa((U32) ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type) temp_nodename, 10);

    mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*) temp_nodename);

    memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

    /* set DMUI status */
    ptr_dmui_context->dmui_status = MMI_DMUI_ADD_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);

    mmi_dmui_waiting_entry();
    cui_inline_close(ptr_dmui_context->cui_profile_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_save_confirm_serverid_inactivated_changed
 * DESCRIPTION
 *  function to save DM info with server id changed but not duplicate and inactivated
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_save_confirm_serverid_inactivated_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_del_serverid = OslAllocDataPtr(dm_server_id_struct);

    mmi_ucs2cpy(
        (S8*) dmui_del_serverid->server_id,
        (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

    ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);

    mmi_dmui_waiting_entry();
    cui_inline_close(ptr_dmui_context->cui_profile_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_info_save_confirm_serverid_activated_changed
 * DESCRIPTION
 *  function to save DM info with server id changed but not duplicate and activated
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_info_save_confirm_serverid_activated_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_del_serverid = OslAllocDataPtr(dm_server_id_struct);

    mmi_ucs2cpy(
        (S8*) dmui_del_serverid->server_id,
        (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

    ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);

    mmi_dmui_waiting_entry();
    cui_inline_close(ptr_dmui_context->cui_profile_setting_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_main_data_account_check
 * DESCRIPTION
 *  call back function for data account init check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_main_data_account_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set data account flag to MMI_TRUE */
    ptr_dmui_context->dmui_data_account_init = MMI_TRUE;

    #ifdef MMI_DM_OP
        if (ptr_dmui_context->dmui_hilite_serverid_index == 0)
        {
            mmi_dmui_entry_option_view();
        }
        else
        {
            mmi_dmui_entry_option_edit();
        }
    #else /* MMI_DM_OP */
        mmi_dmui_entry_option_edit();
    #endif /* MMI_DM_OP */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_erase_confirm
 * DESCRIPTION
 *  function of confirm erase item or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_erase_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if server id is empty popup empty and return */
    if (mmi_ucs2cmp(
            (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
            (S8*) L"") == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_EMPTY),
            MMI_EVENT_FAILURE,
            GRP_ID_DMAPP_SETTING,
            NULL);

        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);

        return;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_DMAPP_SETTING;
    arg.callback = mmi_dmui_del_profile_cnf_cb;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_DMUI_DELETE_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_dmui_del_profile_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_dmui_entry_option_erase_confirm_yes();
            break;

        case MMI_ALERT_CNFM_NO:
            break;

        default:
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_option_erase_confirm_yes
 * DESCRIPTION
 *  function of entry option erase item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_option_erase_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        dmui_del_serverid = OslAllocDataPtr(dm_server_id_struct);

        mmi_ucs2cpy(
            (S8*) dmui_del_serverid->server_id,
            (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

        if (mmi_ucs2cmp((S8*) dmui_del_serverid->server_id, (S8*) ptr_dmui_context->dmui_primary_serverid) == 0)
        {
            ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
        }
        else
        {
            ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
        }

        mmi_dmui_waiting_entry();
    }
}


/****************************************************************************************
*                       function to receive message from DM PS 
****************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_add_account_rsp_handle
 * DESCRIPTION
 *  function to response of add account message
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_add_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_result_struct *dm_result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_result = (dm_result_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ADD_ACCOUNT_RSP, dm_result->result_code);

    if (dm_result->result_code == 0)
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_ADD_ACCOUNT_STATUS)       /* add acct direct */
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_SAVED));

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS)   /* add active acct */
        {
            dm_server_id_struct *dmui_active_serverid = NULL;

            dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            mmi_ucs2cpy(
                (S8*) dmui_active_serverid->server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_SET_PSERVERID_STATUS;

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS) /* add inactive acct */
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_SAVED));

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
        }
    #ifdef __MMI_SYNCML_DM_OTAP__
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_ADD_ACCOUNT_STATUS)
        {
        #ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            dm_server_id_struct *dmui_active_serverid = NULL;

            dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            mmi_ucs2cpy(
                (S8*) dmui_active_serverid->server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            /* add server id to server id array */
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;

            ptr_dmui_context->dmui_status = MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
            
        #else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            if (0 == g_syncml_dm_ota_context->num_installed)
            {
                dm_server_id_struct *dmui_active_serverid = NULL;

                dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

                mmi_ucs2cpy(
                    (S8*) dmui_active_serverid->server_id,
                    (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

                /* add server id to server id array */
                mmi_ucs2cpy(
                    (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;

                if (g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].match_upadte)
                {
                    b_profile_updated = MMI_TRUE;
                }

            ptr_dmui_context->dmui_status = MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
            }
            else
            {
                /* add server id to server id array */
                mmi_ucs2cpy(
                    (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                    (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

                g_syncml_dm_ota_context->num_installed++;

                if (g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].match_upadte)
                {
                    b_profile_updated = MMI_TRUE;
                }

                ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

                mmi_syncml_dm_next_profile();
            }
        #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        }
        /* add a provisioning server id to DM to replace an activated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS)
        {
        #ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            /* do activate empty server id to DM PS */
            dm_server_id_struct *ptr_dm_ota_active_serverid = NULL;

            ptr_dm_ota_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            /* add server id to server id array */
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;

            mmi_ucs2cpy(
                (S8*) ptr_dm_ota_active_serverid->server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            
            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, ptr_dm_ota_active_serverid);
           
         #else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            if (0 == g_syncml_dm_ota_context->num_installed)
            {
            /* do activate empty server id to DM PS */
            dm_server_id_struct *ptr_dm_ota_active_serverid = NULL;

            ptr_dm_ota_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            /* add server id to server id array */
            mmi_ucs2cpy(
                    (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;

            mmi_ucs2cpy(
                (S8*) ptr_dm_ota_active_serverid->server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, ptr_dm_ota_active_serverid);
            }
            else
            {
                /* the variable stores the primary server id */
                U8 primary_server_id[DM_MAX_ID_STR];
                
                memset(primary_server_id, 0x00, DM_MAX_ID_STR);

                mmi_ucs2cpy(
                    (S8*) primary_server_id,
                    (S8*) ptr_dmui_context->dmui_primary_serverid);
                
                if (0 == mmi_ucs2cmp(
                            (S8*) primary_server_id, 
                            (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id))
                {
                    dm_server_id_struct *ptr_dm_ota_active_serverid = NULL;

                    ptr_dm_ota_active_serverid = OslAllocDataPtr(dm_server_id_struct);

                    mmi_ucs2cpy(
                        (S8*) ptr_dm_ota_active_serverid->server_id,
                        (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);
                    
                    mmi_ucs2cpy(
                        (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                        (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

                    g_syncml_dm_ota_context->num_installed++;

                    ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS;

                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, ptr_dm_ota_active_serverid);
                }
                else
                {
                    /* add server id to server id array */
                    mmi_ucs2cpy(
                        (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id,
                        (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

                    g_syncml_dm_ota_context->num_installed++;
                
                    ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

                    mmi_syncml_dm_next_profile();
                }
            }
        #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        }
    #endif /* __MMI_SYNCML_DM_OTAP__ */ 
    #ifdef MMI_DM_OP
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS)
        {
            dm_server_id_struct *ptr_dm_ota_active_serverid = NULL;

            ptr_dm_ota_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            mmi_ucs2cpy(
                (S8*) ptr_dm_ota_active_serverid->server_id,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DM_OTA_INIT_SET_PSERVERID_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, ptr_dm_ota_active_serverid);
        }
    #endif /* MMI_DM_OP */ 
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ADD_ACCOUNT_RSP_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DMUI_STATUS_INFO, ptr_dmui_context->dmui_status);

        /* If failure; then display failure pop up for user notification */
        mmi_dmui_popup_ps_rsp_result(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));

        mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_del_account_rsp_handle
 * DESCRIPTION
 *  function to response of del account message
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_del_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_result_struct *dm_result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_result = (dm_result_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DEL_ACCOUNT_RSP, dm_result->result_code);

    if (dm_result->result_code == 0)
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS)   /* for erase active server id */
        {
            /* do activate empty server id to DM PS */
            dm_server_id_struct *dmui_active_serverid = NULL;

            dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

            ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_SET_PSERVERID_STATUS;
        #ifdef MMI_DM_OP
            mmi_ucs2cpy(
                (S8*)dmui_active_serverid->server_id,
                (S8*)ptr_dmui_context->dmui_profile_array[0].server_id);
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) L"");
        #else
            mmi_ucs2cpy((S8*) dmui_active_serverid->server_id, (S8*) L"");
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) L"");
        #endif /* MMI_DM_OP */
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS)    /* for erase operation */
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_DELETED));

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            /* clear this server ID in server ID array */
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id,
                (S8*) L"");

        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS)   /* for edit operation */
        {
            U8 temp_nodename[DM_MAX_ID_STR];

            dm_add_account_struct *dmui_add_account = NULL;

            dmui_add_account = OslAllocDataPtr(dm_add_account_struct);

            memset(temp_nodename, 0x00, DM_MAX_ID_STR);

            gui_itoa((U32) ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type) temp_nodename, 10);

            mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*) temp_nodename);

            memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS) /* for edit operation */
        {
            U8 temp_nodename[DM_MAX_ID_STR];

            dm_add_account_struct *dmui_add_account = NULL;

            dmui_add_account = OslAllocDataPtr(dm_add_account_struct);

            memset(temp_nodename, 0x00, DM_MAX_ID_STR);

            gui_itoa((U32) ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type) temp_nodename, 10);

            mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*) temp_nodename);

            memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);
        }
    #ifdef __MMI_SYNCML_DM_OTAP__
        /* Replace activated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS)
        {
            U8 temp_nodename[DM_MAX_ID_STR];
            dm_add_account_struct *ptr_dm_ota_add_account = NULL;

            ptr_dm_ota_add_account = OslAllocDataPtr(dm_add_account_struct);

            memset(temp_nodename, 0x00, DM_MAX_ID_STR);

            gui_itoa((U32) g_syncml_dm_ota_context->edit_serverid_index, (UI_string_type) temp_nodename, 10);

            mmi_ucs2cpy(
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].node_name,
                (S8*) temp_nodename);

            /* set value to DM message struct */
            mmi_syncml_dm_set_value(
                &ptr_dm_ota_add_account->dm_account,
                &g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, ptr_dm_ota_add_account);

        }
    #endif /* __MMI_SYNCML_DM_OTAP__ */ 
    #ifdef MMI_DM_OP
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_INIT_DEL_ACCOUNT_STATUS)
        {
            mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id, (S8*) L"");

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_dm_ota_init_profile2();
        }
    #endif /* MMI_DM_OP */ 
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DEL_ACCOUNT_RSP_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DMUI_STATUS_INFO, ptr_dmui_context->dmui_status);

        /* If failure; then display failure pop up for user notification */
        mmi_dmui_popup_ps_rsp_result(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_account_rsp_handle
 * DESCRIPTION
 *  function to response of get account information
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_get_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_dmaccount_rsp_struct *dmui_get_account = NULL;
    dm_server_id_struct *dm_init_get_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_get_account = (dm_get_dmaccount_rsp_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_GET_ACCOUNT_RSP, dmui_get_account->result_code);

    if (dmui_get_account->result_code == 1) /* get server id list failed */
    {
        /* If failure; then display failure popup for user notification */
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_GET_ACCOUNT_RSP_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DMUI_STATUS_INFO, ptr_dmui_context->dmui_status);

        /* If failure; then display failure pop up for user notification */
        mmi_dmui_popup_ps_rsp_result(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));

        mmi_dm_unfinish_check_info();
        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
    }
    /* if server id not empty get account id in DM server id list */
    else if (ptr_dmui_context->dmui_status == MMI_DMUI_GET_ACCOUNT_STATUS)
    {
        memcpy(&ptr_dmui_context->dmui_cur_edit_account, &dmui_get_account->dm_account, sizeof(dm_account_struct));
        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);

        mmi_dm_print_info(&dmui_get_account->dm_account);
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        if (mmi_frm_group_is_present(GRP_ID_DMAPP_SETTING) == MMI_FALSE)
        {
            return;
        }

        /* data account information not init */
        if (MMI_FALSE == mmi_dtcnt_ready_check(mmi_dmui_main_data_account_check, MMI_TRUE))
        {
            ptr_dmui_context->dmui_data_account_init = MMI_FALSE;
        }
        else
        {
            /* entry option edit screen */
            #ifdef MMI_DM_OP
                if (ptr_dmui_context->dmui_hilite_serverid_index == 0)
                {
                    mmi_dmui_entry_option_view();
                }
                else
                {
                    mmi_dmui_entry_option_edit();
                }
            #else /* MMI_DM_OP */
                mmi_dmui_entry_option_edit();
            #endif /* MMI_DM_OP */     
        }
    }
    else if (ptr_dmui_context->dmui_status == MMI_DMUI_INIT_GET_ACCOUNT_STATUS)
    {
        memcpy(
            ptr_dmui_context->dmui_profile_array[init_get_account_count].provurl,
            dmui_get_account->dm_account.provurl,
            DM_MD5_HASH_LENGTH);

        memcpy(
            ptr_dmui_context->dmui_profile_array[init_get_account_count].proxy_id,
            dmui_get_account->dm_account.proxy_id,
            DM_MD5_HASH_LENGTH);

        ptr_dmui_context->dmui_profile_array[init_get_account_count].profile_type = dmui_get_account->dm_account.profile_type;
        ptr_dmui_context->dmui_profile_array[init_get_account_count].read_only = dmui_get_account->dm_account.read_only;

        init_get_account_count++;
        
        for ( ; init_get_account_count < DMUI_MAX_SERVERID; init_get_account_count++)
        {
            if (0 != mmi_ucs2strlen((S8*)(ptr_dmui_context->dmui_profile_array[init_get_account_count].server_id)))
            {
                //ptr_dmui_context->data_account_id[init_get_account_count] = dmui_get_account->dm_account.conn_setting.data_account_id;
                ptr_dmui_context->dmui_status = MMI_DMUI_INIT_GET_ACCOUNT_STATUS;
                
                dm_init_get_account = OslAllocDataPtr(dm_server_id_struct);

                mmi_ucs2cpy(
                    (S8*)dm_init_get_account->server_id, 
                    (S8*)(ptr_dmui_context->dmui_profile_array[init_get_account_count].server_id));
                
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_ACCOUNT_REQ, (S8*)dm_init_get_account);

                return;
            }
            else
            {
                continue;
            }
        }

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
        #ifdef MMI_DM_OP
        mmi_dm_ota_init_profile();
        #endif /* MMI_DM_OP */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_list_serverid_rsp_handle
 * DESCRIPTION
 *  function to receive response of list server id
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_list_serverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_list_server_id_rsp_struct *ptr_serverid_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_serverid_list = (dm_list_server_id_rsp_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LISTSERVERID_RSP, ptr_serverid_list->result_code);

    if (ptr_serverid_list->result_code == 1)    /* get server id list failed */
    {
        /* If failure; then display failure popup for user notification */
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LISTSERVERID_RSP_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DMUI_STATUS_INFO, ptr_dmui_context->dmui_status);

        /* If failure; then display failure pop up for user notification */
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));

        mmi_dm_unfinish_check_info();
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
    }
    else
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_ONLY_INIT_SERVERID_STATUS)
        {
            mmi_dmui_save_serverid_list(ptr_serverid_list->server_id_list);
            ptr_dmui_context->dmui_status = MMI_DMUI_ONLY_INIT_PSERVERID_STATUS;
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_PSERVERID_REQ, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_save_serverid_list
 * DESCRIPTION
 *  function to save server ID list from DM PS
 * PARAMETERS
 *  sour_str        [IN]        Server id list from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_save_serverid_list(U8 *sour_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;               /* partner index */
    U32 j = 0;              /* character position */
    U8 division_index = 0;  /* division index */
    dmui_serverid_map_struct dmui_serverid_map[DMUI_MAX_SERVERID];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ptr_dmui_context->dmui_profile_array, 0x00, DMUI_MAX_SERVERID * sizeof(mmi_dm_profile_struct));
    memset(dmui_serverid_map, 0x00, DMUI_MAX_SERVERID * sizeof(dmui_serverid_map_struct));

    while (1)
    {
        /* end of string */
        if ((*sour_str == 0) && (*(sour_str + 1) == 0))
        {
            break;
        }

        if (division_index % 2) /* if division_index is odd, save server ID */
        {
            /* save server id */
            dmui_serverid_map[i].dmui_serverid[j] = *sour_str;
        }
        else    /* if division_index is even, save node name */
        {
            /* save node name */
            dmui_serverid_map[i].dmui_nodename[j] = *sour_str;
        }

        j++;
        sour_str += 1;

        /* find 01 string */
        if ((*sour_str == 1) && (*(sour_str + 1) == 0))
        {
            if (division_index % 2)
            {
                dmui_serverid_map[i].dmui_serverid[j] = 0;
                dmui_serverid_map[i].dmui_serverid[j + 1] = 0;

                i++;
            }
            else
            {
                dmui_serverid_map[i].dmui_nodename[j] = 0;
                dmui_serverid_map[i].dmui_nodename[j + 1] = 0;
            }
            sour_str += 2;
            division_index++;
            j = 0;
        }
    }

    i = 0;
    j = 0;

    /* save server id and node name to server id array */
    for (i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        if (mmi_ucs2strlen((S8*) dmui_serverid_map[i].dmui_serverid) == 0)
            continue;

        {
            j = (U32) gui_atoi((UI_string_type) dmui_serverid_map[i].dmui_nodename);

            if (j < DMUI_MAX_SERVERID)
                mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_profile_array[j].server_id, (S8*) dmui_serverid_map[i].dmui_serverid);
            else
            {
                U8 temp_nodename[DM_MAX_ID_STR];
                U8 temp_serverid[DM_MAX_ID_STR];

                memset(temp_nodename, 0x00, DM_MAX_ID_STR);
                memset(temp_serverid, 0x00, DM_MAX_ID_STR);

                mmi_ucs2_to_asc((S8*) temp_nodename, (S8*) dmui_serverid_map[i].dmui_nodename);
                mmi_ucs2_to_asc((S8*) temp_serverid, (S8*) dmui_serverid_map[i].dmui_serverid);

                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SAVE_SERVERID_INVALID_NODE, temp_nodename);
                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SAVE_SERVERID_INVALID_SVID, temp_serverid);

                /* delete error server id */
                {
                    dm_server_id_struct *dmui_del_serverid = NULL;

                    dmui_del_serverid = OslAllocDataPtr(dm_server_id_struct);

                    mmi_ucs2cpy((S8*) dmui_del_serverid->server_id, (S8*) dmui_serverid_map[i].dmui_serverid);

                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_pserverid_rsp_handle
 * DESCRIPTION
 *  function to receive primary server ID from DM PS
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_get_pserverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_pserver_id_rsp_struct *ptr_pserverid = NULL;
    dm_server_id_struct *dm_init_get_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_pserverid = (dm_get_pserver_id_rsp_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_GET_PSERVERID_RSP);

    if (ptr_dmui_context->dmui_status == MMI_DMUI_ONLY_INIT_PSERVERID_STATUS)
    {
        mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_primary_serverid, (S8*) ptr_pserverid->server_id);

        for ( ; init_get_account_count < DMUI_MAX_SERVERID; init_get_account_count++)
        {
            if (0 != mmi_ucs2strlen((S8*)(ptr_dmui_context->dmui_profile_array[init_get_account_count].server_id)))
            {
                ptr_dmui_context->dmui_status = MMI_DMUI_INIT_GET_ACCOUNT_STATUS;

                dm_init_get_account = OslAllocDataPtr(dm_server_id_struct);

                mmi_ucs2cpy(
                    (S8*)dm_init_get_account->server_id, 
                    (S8*)(ptr_dmui_context->dmui_profile_array[init_get_account_count].server_id));
                
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_ACCOUNT_REQ, (S8*)dm_init_get_account);

                return;
            }
            else
            {
                continue;
            }
        }

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
    #ifdef MMI_DM_OP
        mmi_dm_ota_init_profile();
    #endif /* MMI_DM_OP */
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_set_pserverid_rsp_handle
 * DESCRIPTION
 *  function to response of set primary server id
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_set_pserverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_result_struct *add_result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_result = (dm_result_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SET_PSERVERID_RSP, add_result->result_code);

    if (add_result->result_code == 0)
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_SET_PSERVERID_STATUS)
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_ACTIVATED));
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_SET_PSERVERID_STATUS)
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_SAVED));

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) ptr_dmui_context->dmui_profile_array[ptr_dmui_context->dmui_hilite_serverid_index].server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);

        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_SET_PSERVERID_STATUS)
        {
            mmi_dmui_popup_ps_rsp_result(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_DELETED));
        #ifdef MMI_DM_OP
            mmi_ucs2cpy(
                (S8*)ptr_dmui_context->dmui_primary_serverid,
                (S8*)ptr_dmui_context->dmui_profile_array[0].server_id);
        #else
            mmi_ucs2cpy(
                (S8*)ptr_dmui_context->dmui_primary_serverid,
                (S8*)L"");
        #endif /* MMI_DM_OP */
            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
            mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
        }
    #ifdef __MMI_SYNCML_DM_OTAP__
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS)
        {
            /* reset primary server id */
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_syncml_dm_next_profile();
        }
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS)
        {
            /* reset primary server id */
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            mmi_syncml_dm_next_profile();
        }
    #endif /* __MMI_SYNCML_DM_OTAP__ */ 
    #ifdef MMI_DM_OP
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_INIT_SET_PSERVERID_STATUS)
        {
            U8 dm_init_flag = 1;
            S16 error;

            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            WriteValue(NVRAM_DM_OTA_PROFILE_INIT, &dm_init_flag, DS_BYTE, &error);

            memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
        }
    #endif /* MMI_DM_OP */ 
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SET_PSERVERID_RSP_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DMUI_STATUS_INFO, ptr_dmui_context->dmui_status);

        /* If failure; then display failure pop up for user notification */
        mmi_dmui_popup_ps_rsp_result(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED));

        mmi_dm_unfinish_check_info();
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_OPTION);
        mmi_frm_scrn_close(GRP_ID_DMAPP_SETTING, SCR_ID_DMUI_WAITING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init_session_confirm_yes
 * DESCRIPTION
 *  function to response of init session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_init_session_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ui_struct *ptr_dmui_init_session_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_init_session_res = OslAllocDataPtr(dm_ui_struct);

    ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

    /* send ok message to DM PS */
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init_session_confirm_no
 * DESCRIPTION
 *  function to response of init session and back to before screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_init_session_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ui_struct *ptr_dmui_init_session_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_init_session_res = OslAllocDataPtr(dm_ui_struct);

    ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_REJECT;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    /* send cancel message to DM PS */
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);

    mmi_frm_scrn_close_active_id();
}

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init_session_ind_handle
 * DESCRIPTION
 *  function to receive init session indication
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_init_session_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif 
    dm_ui_mode_struct *ptr_dmui_init_session = NULL;
    dm_ui_struct *ptr_dmui_init_session_res = NULL;
#ifdef __DM_SCOMO_SUPPORT__    
    nvram_ef_dm_app_scomo_report_info_struct dm_app_scomo_report_info;
    S16 error;
#endif /* __DM_SCOMO_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_SESSION_IND);
    if (mmi_dmui_check_self_reg_sim_match() == MMI_FALSE)
    {
        return;
    }

    ptr_dmui_init_session = (dm_ui_mode_struct*) msg;
    if (ptr_dmui_init_session->ui_mode == DM_UI_MODE_NOTSPECIFIED)
    {
        session_uimode = dm_get_ui_mode_unspecifed();
    }
    else
    {
        session_uimode = ptr_dmui_init_session->ui_mode;
    }
    /* reset scomo info here */
#ifdef __DM_SCOMO_SUPPORT__
    memset(&dm_app_scomo_report_info, 0x00, sizeof(nvram_ef_dm_app_scomo_report_info_struct));
    WriteRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);
#endif /* __DM_SCOMO_SUPPORT__ */
#ifdef __DM_LAWMO_SUPPORT__
    if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
    {
        session_uimode = DM_UI_MODE_BACKGROUND;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
#ifndef MMI_DM_3G
#ifdef BROWSER_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_DM_3G */
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    switch (session_uimode)
            {
        case DM_UI_MODE_BACKGROUND: /* not response to DM PS */
            {
                ptr_dmui_init_session_res = OslAllocDataPtr(dm_ui_struct);
                ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                /* send message to DM PS */
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);
            break;
        }

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
        {
            ptr_dmui_init_session_res = OslAllocDataPtr(dm_ui_struct);

            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO,
                (WCHAR*)GetString(STR_ID_DMUI_NOTIF_INIT_SESSION_INFO));

            ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

            /* send message to DM PS */
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);
            break;
        }

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
        {
            if (MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DM, mmi_dmui_otap_confirm_entry_hdlr, (void*)&dmui_confirm))
            {
                return;
            }

        #ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

            mmi_dmui_fill_confirm_struct(
                STR_GLOBAL_CONFIRM,
                IMG_GLOBAL_OK,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_BACK,
                get_string(STR_ID_DMUI_NOTIF_INIT_SESSION_CONFIRM),
                mmi_get_event_based_image(MMI_EVENT_QUERY),
                mmi_get_event_based_sound(MMI_EVENT_QUERY),
                0,
                NULL,
                mmi_dmui_init_session_confirm_yes,
                mmi_dmui_init_session_confirm_no);

            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_DEFAULT,
                mmi_dmui_otap_confirm_entry_hdlr,
                (void*)&dmui_confirm);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_userpin_ind_handle
 * DESCRIPTION
 *  function to receive user pin indication
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_userpin_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_USER_PIN_IND);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DMUI_ENTER_PIN)   /* user pin screen actived */
    {
        return;
    }
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_ENTER_PIN);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dmui_user_pin_confirm_entry_hdlr,
        NULL);
}

MMI_BOOL mmi_dmui_user_pin_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dmui_entry_user_pin_confirm();
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_user_pin_confirm
 * DESCRIPTION
 *  function to entry user pin confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_user_pin_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_ENTER_PIN,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_user_pin_confirm, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        input_buffer = GetCurrInputBuffer(SCR_ID_DMUI_ENTER_PIN);

        if (input_buffer == NULL)
        {
            memset(ptr_dmui_context->pin_password, 0x00, (DMUI_MAX_PIN_LENGTH + 1) * ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2cpy((S8*) ptr_dmui_context->pin_password, (S8*) input_buffer);
        }

        RegisterInputBoxValidationFunction(mmi_dmui_user_pin_change_lsk);

#ifdef UI_SMALL_PIN_EDITOR_SCREEN
        enable_resized_small_screen();
#endif

        ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_ID_DMUI_NOTIF_ENTER_PIN,
            IMM_INPUT_TYPE_NUMERIC_PASSWORD,
            ptr_dmui_context->pin_password,
            (DMUI_MAX_PIN_LENGTH + 1),
            NULL,
            gui_buffer);

        SetCategory111RightSoftkeyFunction(mmi_dmui_entry_user_pin_confirm_no, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_dmui_entry_user_pin_confirm_ok, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_entry_user_pin_confirm_ok, KEY_EVENT_UP);

        if (mmi_ucs2strlen((S8*) ptr_dmui_context->pin_password) < DMUI_MIN_PIN_LENGTH)
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_user_pin_change_lsk
 * DESCRIPTION
 *  This function is to change softkey function in screen according to params
 * PARAMETERS
 *  text        [IN]        
 *  cursor      [IN]        
 *  length      [IN]        Current input length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_user_pin_change_lsk(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the validity of the input password */
    if ((length) < DMUI_MIN_PIN_LENGTH)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, 0);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(mmi_dmui_entry_user_pin_confirm_ok, KEY_POUND, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_user_pin_confirm_no
 * DESCRIPTION
 *  function to enter pin screen right soft key response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_user_pin_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_bootstrap_userpin_rsp_struct *dmui_user_pin = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_user_pin = OslAllocDataPtr(dm_get_bootstrap_userpin_rsp_struct);

    dmui_user_pin->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_BOOTSTRAP_USERPIN_RES, dmui_user_pin);

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_user_pin_confirm_ok
 * DESCRIPTION
 *  function to enter pin code screen left soft key response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_user_pin_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_bootstrap_userpin_rsp_struct *dmui_user_pin = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_user_pin = OslAllocDataPtr(dm_get_bootstrap_userpin_rsp_struct);

    mmi_ucs2cpy((S8*) dmui_user_pin->user_pin, (S8*) ptr_dmui_context->pin_password);

    dmui_user_pin->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_BOOTSTRAP_USERPIN_RES, dmui_user_pin);

    mmi_frm_scrn_close_active_id();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__  /* suggestion modify by mbj06013 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 
/* under construction !*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#ifdef __DM_FOTA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_update_req_ind_hdlr
 * DESCRIPTION
 *  function to receive update indication
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_update_req_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_ind_struct *dmui_dl_ind = NULL;
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;
    dm_ui_mode_enum dmui_update_ui_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_dl_ind = (dm_dl_ind_struct*) msg;
    ptr_dmui_context->dmui_dd_rsp_file_path = dmui_dl_ind->file_path_ptr;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UPDATE_IND, dmui_dl_ind->ui_mode, dmui_dl_ind->file_path_ptr);

    if (dmui_dl_ind->ui_mode == DM_UI_MODE_NOTSPECIFIED)
    {
        dmui_update_ui_mode = dm_get_ui_mode_unspecifed();
    }
    else
    {
        dmui_update_ui_mode = dmui_dl_ind->ui_mode;
    }

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif

    switch (dmui_update_ui_mode)
    {
        case DM_UI_MODE_BACKGROUND: /* not response to DM PS */
        {
            ptr_dmui_dl_res = OslAllocDataPtr(dm_dd_rsp_struct);

            ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
            ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
            break;
        }

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
        {
            ptr_dmui_dl_res = OslAllocDataPtr(dm_dd_rsp_struct);

            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO,
                (WCHAR*)GetString(STR_ID_DMUI_NOTIF_UPDATE_REQUEST));
            ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
            ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
            break;
        }

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
        {
            /* if can't display update screen or this screen is actived */
            if (MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE, MMI_FRM_NODE_ALL_FLAG) ||
                MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DM, mmi_dmui_fota_update_confirm_entry_hdlr, NULL) ||
                MMI_TRUE == srv_ucm_is_any_call()) // user may press confirm by mistake
            {
                return;
            }
            mmi_dmui_read_info_from_file(dmui_dl_ind->file_path_ptr);
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_DEFAULT,
                mmi_dmui_fota_update_confirm_entry_hdlr,
                NULL);
            break;
        }

        default:
            break;
    }
    /* Delete waiting screen after update confirm screen display */
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_entry_update_confirm
 * DESCRIPTION
 *  function to entry update confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_entry_update_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_UPDATE,
                        NULL,
                        (FuncPtr)mmi_dmui_fota_entry_update_confirm, 
                        MMI_FRM_FULL_SCRN))
    {
        mmi_ucs2cpy((S8*) subMenuData, GetString(STR_ID_DMUI_NOTIF_UPDATE_REBOOT));

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_UPDATE,
            mmi_dmui_fota_update_scrn_leave_proc);

        ShowCategory74Screen(
            STR_ID_DMUI_NOTIF_UPDATE_CAPTION,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_UPDATE,
            IMG_GLOBAL_YES,
            STR_ID_DMUI_NOTIF_UPDATE_DEFER,
            IMG_GLOBAL_NO,
            (PU8)subMenuData,
            mmi_ucs2strlen((S8*)subMenuData),
            NULL);
            SetLeftSoftkeyFunction(mmi_dmui_fota_send_update_accept_rsp, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_dmui_fota_entry_update_defer, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_dmui_fota_send_update_accept_rsp, KEY_EVENT_UP);
    }
}

MMI_BOOL mmi_dmui_fota_update_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dmui_fota_entry_update_confirm();
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_update_scrn_leave_proc
 * DESCRIPTION
 *  function to cancel update screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_fota_update_scrn_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        g_mmi_dmui_fota_update_defer_time = MMI_DMUI_DEFAULT_UPDATE_DEFER_TIME;
        mmi_dmui_fota_send_update_defer_rsp();
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_send_update_defer_rsp
 * DESCRIPTION
 *  function to defer select in update confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_send_update_defer_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = OslAllocDataPtr(dm_dd_rsp_struct);

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_DEFER;
    ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;
    ptr_dmui_dl_res->defer_time = g_mmi_dmui_fota_update_defer_time;
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_send_update_accept_rsp
 * DESCRIPTION
 *  function to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_send_update_accept_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = OslAllocDataPtr(dm_dd_rsp_struct);

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
    ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
    mmi_dmui_entry_reset_progress();

    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE_DEFER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_entry_update_defer
 * DESCRIPTION
 *  function to entry update defer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_entry_update_defer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *defer_time_list_ptr[MMI_DMUI_UPDATE_DEFER_TIME_TOTAL];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_UPDATE_DEFER,
                        NULL,
                        (FuncPtr)mmi_dmui_fota_entry_update_defer, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        if (gui_buffer == NULL)
        {
            // first entry
            g_mmi_dmui_fota_update_defer_highlight_item = 0;
        }

        for (i = 0; i < MMI_DMUI_UPDATE_DEFER_TIME_TOTAL; i++)
        {
            defer_time_list_ptr[i] = g_mmi_dmui_fota_update_defer_time_list[i];
        }
        RegisterHighlightHandler(mmi_dmui_fota_update_defer_highlight_hdlr);

        mmi_wcscpy((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_1_HOUR], L"1");
        mmi_wcscat((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_1_HOUR], (U16*)get_string(STR_ID_DMUI_UPDATE_DEFER_HOUR_LATER));
        mmi_wcscpy((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_2_HOUR], L"2");
        mmi_wcscat((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_2_HOUR], (U16*)get_string(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));
        mmi_wcscpy((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_4_HOUR], L"4");
        mmi_wcscat((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_4_HOUR], (U16*)get_string(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));
        mmi_wcscpy((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_24_HOUR], L"24");
        mmi_wcscat((U16*)g_mmi_dmui_fota_update_defer_time_list[MMI_DMUI_UPDATE_DEFER_TIME_24_HOUR], (U16*)get_string(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));

        ShowCategory6Screen(
            STR_ID_DMUI_NOTIF_UPDATE_DEFER,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MMI_DMUI_UPDATE_DEFER_TIME_TOTAL,
            defer_time_list_ptr,
            NULL,
            g_mmi_dmui_fota_update_defer_highlight_item,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_dmui_fota_update_defer_lsk_ok, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_fota_update_defer_lsk_ok, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_update_defer_highlight_hdlr
 * DESCRIPTION
 *  function to handle the highlight index in update defer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_update_defer_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_dmui_fota_update_defer_highlight_item = index;

    switch (index)
    {
        case MMI_DMUI_UPDATE_DEFER_TIME_1_HOUR:
            g_mmi_dmui_fota_update_defer_time = 1 * 3600;
            break;
            
        case MMI_DMUI_UPDATE_DEFER_TIME_2_HOUR:
            g_mmi_dmui_fota_update_defer_time = 2 * 3600;
            break;
        case MMI_DMUI_UPDATE_DEFER_TIME_4_HOUR:
            g_mmi_dmui_fota_update_defer_time = 4 * 3600;
            break;
            
        case MMI_DMUI_UPDATE_DEFER_TIME_24_HOUR:
            g_mmi_dmui_fota_update_defer_time = 24 * 3600;
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fota_update_defer_lsk_ok
 * DESCRIPTION
 *  function to handle the defer time and send the msg to DM PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_update_defer_lsk_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dmui_fota_update_defer_time == 0)
    {
        mmi_dmui_fota_send_update_accept_rsp();
    }
    else
    {
        mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE);
        mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE_DEFER);
        mmi_dmui_fota_send_update_defer_rsp();
    }
}


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  mmi_dmui_fota_entry_update_info_check
 * DESCRIPTION
 *  function of fota update info check
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE:  Allow to call mmi_dmui_fota_entry_update_info_callback
 *  FALSE: Not Allow to call mmi_dmui_fota_entry_update_info_callback
 *****************************************************************************/
U8 mmi_dmui_fota_entry_update_info_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dmui_fota_is_update == 1)
    {
        g_mmi_dmui_fota_is_update = 0;
        WriteValue(NVRAM_DM_FOTA_UPDATE_FLAG, &g_mmi_dmui_fota_is_update, DS_BYTE, &error);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  mmi_dmui_fota_entry_update_info_callback
 * DESCRIPTION
 *  function of display the update info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fota_entry_update_info_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_AUTO_GEN,
                mmi_dmui_global_scr_group_proc,
                (void*)NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (g_mmi_dmui_fota_is_update_success == MMI_TRUE)
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = group_id;
        arg.callback = NULL;
        arg.f_enter_history = MMI_TRUE;
        arg.f_auto_map_empty_softkey = MMI_TRUE;
        mmi_confirm_display(
            (WCHAR*)GetString(STR_ID_DMUI_UPDATE_SUCCESS),
            MMI_EVENT_SUCCESS,
            &arg);
    }
    else
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = group_id;
        arg.callback = NULL;
        arg.f_enter_history = MMI_TRUE;
        arg.f_auto_map_empty_softkey = MMI_TRUE;
        mmi_confirm_display(
            (WCHAR*)GetString(STR_ID_DMUI_UPDATE_FAILURE),
            MMI_EVENT_FAILURE,
            &arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_reset_ind_handle
 * DESCRIPTION
 *  function to receive handset reboot indication from DM PS
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_reset_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    S16 error;
    dm_reset_ind_struct *dmui_reset_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RESET_IND);
    SetProtocolEventHandler(mmi_dmui_reset_rsp_handle, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    dmui_reset_ind = (dm_reset_ind_struct*)msg;
    if (dmui_reset_ind->result)
    {
        /* Deattach network */
        #ifdef __DM_FOTA_SUPPORT__
        g_mmi_dmui_fota_is_update = 1;
        WriteValue(NVRAM_DM_FOTA_UPDATE_FLAG, &g_mmi_dmui_fota_is_update, DS_BYTE, &error);
        /* Do not remind before reboot */
        g_mmi_dmui_fota_is_update = 0;
        #endif /* __DM_FOTA_SUPPORT__ */
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;

        Message.oslDataPtr = (oslParaType*) NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_DMUI_NOTIF_REBOOT_FAIL));
        
        mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_REBOOT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_reset_progress
 * DESCRIPTION
 *  function to display reboot screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_reset_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_REBOOT,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_reset_progress, 
                        MMI_FRM_FULL_SCRN))
    {
        ShowCategory66Screen(
            STR_ID_DMUI_NOTIF_REBOOT,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            0,
            0,
            0,
            0,
            (PU8) GetString(STR_ID_DMUI_NOTIF_REBOOT_PROGRESS),
            IMG_GLOBAL_PROGRESS,
            NULL);

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_REBOOT,
            mmi_dmui_reboot_leave_proc);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    }
}


mmi_ret mmi_dmui_reboot_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_reset_rsp_handle
 * DESCRIPTION
 *  function to receive reboot response
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_reset_rsp_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RESET_RSP);

    srv_reminder_clear(SRV_REMINDER_TYPE_TOTAL);

    AlmATPowerReset(MMI_FALSE, 3);  /* shutdown system and reboot in 3 seconds. */
}
#endif /* __DM_FOTA_SUPPORT__ */


MMI_BOOL mmi_dmui_ps_status_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dmui_prompt_message_struct *param = (dmui_prompt_message_struct*)arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DM, param->event_id, (WCHAR*)param->message);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_ps_status_ind_handle
 * DESCRIPTION
 *  function to receive dm protocol stack status indication
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_ps_status_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ps_status_ind_struct *ptr_ps_ind = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_ps_ind = (dm_ps_status_ind_struct*)msg;
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PS_STATUS_IND, ptr_ps_ind->status);

    switch (ptr_ps_ind->status)
    {
        case DM_PS_STATUS_DISCONNECTED:
        case DM_PS_STATUS_UNAUTHCATED:
        {
        #ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
        #endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
            break;
        }

        case DM_PS_STATUS_NOT_ENOUGH_MEMORY:
        {
            mmi_dmui_set_ending_msg(MMI_DMUI_ENDING_MSG_NO_MEM);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_ind_handle
 * DESCRIPTION
 *  function to receive alert message from DM PS
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif 
    U32 dmui_alert_option_mask;
    dm_alert_struct *ptr_dmui_alert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_alert = (dm_alert_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ALERT_IND, ptr_dmui_alert->alert_type);
    if (mmi_dmui_check_self_reg_sim_match() == MMI_FALSE)
    {
        if (ptr_dmui_alert->alert_string)
        {
            OslMfree(ptr_dmui_alert->alert_string);
        }
        return;
    }

    if (MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DM, mmi_dmui_otap_confirm_entry_hdlr, (void*)&dmui_confirm))
    {
        if (ptr_dmui_alert->alert_string)
        {
            OslMfree(ptr_dmui_alert->alert_string);
        }
        return;
    }
#ifdef __DM_LAWMO_SUPPORT__
    if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
    {
        if (ptr_dmui_alert->alert_type == DM_UI_INTERACTION_CONFIRM)
        {
            mmi_dmui_entry_alert_confirm_ok();
        }
        else
        {
            mmi_dmui_alert_confirm_cancel();
        }
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
#ifndef MMI_DM_3G
#ifdef BROWSER_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_DM_3G */
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

    memset(&ptr_dmui_context->dmui_alert_struct, 0x00, sizeof(dm_alert_struct));

    ptr_dmui_context->dmui_alert_struct.alert_type = ptr_dmui_alert->alert_type;        /* ALERT TYPE */
    ptr_dmui_context->dmui_alert_struct.option_mask = ptr_dmui_alert->option_mask;      /* OPTION MASK */

    ptr_dmui_context->dmui_alert_struct.alert_string = (U8*) ptr_dmui_context->dmui_alert_string;

    dmui_alert_option_mask = ptr_dmui_context->dmui_alert_struct.option_mask;

    if (ptr_dmui_alert->b_filename) /* DM PS send string with file */
    {
        FS_HANDLE fd;
        U32 size;

        fd = FS_Open((U16*) ptr_dmui_alert->alert_string, FS_READ_ONLY);

        if (fd >= 0)
        {
            FS_Read(fd, ptr_dmui_context->dmui_alert_string, sizeof(ptr_dmui_alert->buffer_len), &size);
            FS_Close(fd);
        }

    }
    else
    {
        mmi_ucs2ncpy((S8*) ptr_dmui_context->dmui_alert_string, (S8*) ptr_dmui_alert->alert_string, ptr_dmui_alert->buffer_len > DMUI_INPUT_BUFFER_SIZE ? DMUI_INPUT_BUFFER_SIZE : ptr_dmui_alert->buffer_len);       /* ALERT STRING */
    }

    OslMfree(ptr_dmui_alert->alert_string);

    if (dmui_alert_option_mask)
    {
        if (dmui_alert_option_mask >= DM_ALERT_ET_MASK) /* ET */
        {
            ptr_dmui_context->dmui_alert_struct.et = ptr_dmui_alert->et;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_ET_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_IT_MASK) /* IT */
        {
            ptr_dmui_context->dmui_alert_struct.it = ptr_dmui_alert->it;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_IT_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MAXLEN_MASK) /* MAX LEN */
        {
            ptr_dmui_context->dmui_alert_struct.max_len = ptr_dmui_alert->max_len;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXLEN_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_DR_MASK) /* DEFAULT */
        {
            mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_alert_struct.dr, (S8*) ptr_dmui_alert->dr);
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_DR_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MAXDT_MASK)  /* MAX DT */
        {
            ptr_dmui_context->dmui_alert_struct.max_dt = ptr_dmui_alert->max_dt;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXDT_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MINDT_MASK)  /* MIN DT */
        {
            ptr_dmui_context->dmui_alert_struct.min_dt = ptr_dmui_alert->min_dt;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXLEN_MASK;
        }
    }

    mmi_dmui_alert_entry_hdlr(ptr_dmui_alert->alert_type);
}

void mmi_dmui_alert_entry_hdlr(dm_alert_type_enum alert_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (alert_type)
    {
        case DM_UI_INTERACTION_DISPLAY:
        {
            ptr_dmui_context->dmui_alert_scr_id = 0;
            mmi_dmui_entry_alert_display();
        }
            break;

        case DM_UI_INTERACTION_CONFIRM:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_OTA_CONFIRM;
            mmi_dmui_entry_alert_confirm();
        }
            break;

        case DM_UI_INTERACTION_INPUT:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_INPUT;
            mmi_dmui_entry_alert_input();
        }
            break;

        case DM_UI_INTERACTION_SINGLE_CHOICE:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_SINGLE_CHOICE;
            mmi_dmui_entry_alert_single_choice();
        }
            break;

        case DM_UI_INTERACTION_MULTI_CHOICE:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_MULTI_CHOICE;
            mmi_dmui_entry_alert_multi_choice();
        }
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_display
 * DESCRIPTION
 *  function to entry alert display screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_DM_PROFILE_SETTING__ */ 
    mmi_dmui_display_popup(
        (UI_string_type)ptr_dmui_context->dmui_alert_string,
        MMI_EVENT_INFO,
        ptr_dmui_context->dmui_alert_struct.min_dt);
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_confirm
 * DESCRIPTION
 *  function to entry alert confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ENTRY_ALERT_CONFIRM);

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    mmi_dmui_fill_confirm_struct(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_NO,
        (UI_string_type)(ptr_dmui_context->dmui_alert_string),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        mmi_get_event_based_sound(MMI_EVENT_QUERY),
        0,
        NULL,
        mmi_dmui_entry_alert_confirm_ok,
        mmi_dmui_alert_confirm_no);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dmui_otap_confirm_entry_hdlr,
        (void*)&dmui_confirm);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_confirm_ok
 * DESCRIPTION
 *  function to accept alert confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);

    dmui_alert_rsp->alert_type = DM_UI_INTERACTION_CONFIRM;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, ptr_dmui_context->dmui_alert_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_input
 * DESCRIPTION
 *  function to entry alert input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct = {0};

    cui_inline_item_caption_struct          caption_1;
    cui_inline_item_fullscreen_edit_struct  fullscreen_editor_2;
    cui_inline_item_text_edit_struct        text_editor_2;
    cui_inline_item_date_time_struct        date_time_2;
    cui_inline_item_ip4_struct              ip4_2;

    cui_inline_set_item_struct inline_item[2];
    MMI_ID inline_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    caption_1.string_id = 0;
    inline_item[0].item_id = ALERT_INPUT_INLINE_ITEM_ID_1;
    inline_item[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[0].image_id = 0;
    inline_item[0].item_data = &caption_1;

    switch (ptr_dmui_context->dmui_alert_struct.it)
    {
        case DM_INPUT_EDIT_TYPE_ALPHA:
        {
            fullscreen_editor_2.string_id = 0;
            fullscreen_editor_2.default_text_id = 0;
            fullscreen_editor_2.title = STR_ID_DMUI_ALERT_DM_INFO_CAPTION;
            fullscreen_editor_2.title_icon = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
            fullscreen_editor_2.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            fullscreen_editor_2.buffer_size = ptr_dmui_context->dmui_alert_struct.max_len - 1;  
            fullscreen_editor_2.required_input_mode_set = NULL;
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &fullscreen_editor_2;

            if (ptr_dmui_context->dmui_alert_struct.et == DM_ECHO_TYPE_TEXT)
            {
                fullscreen_editor_2.input_type = IMM_INPUT_TYPE_ASCII_CHAR;
            }
            else    /* DM_ECHO_TYPE_PW */
            {
                fullscreen_editor_2.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
            }
            break;
        }

        case DM_INPUT_EDIT_TYPE_NUMBER:
        {
            text_editor_2.string_id = 0;
            text_editor_2.default_text_id = 0;
            text_editor_2.buffer_size = ptr_dmui_context->dmui_alert_struct.max_len - 1;
            text_editor_2.input_extended_type = 0;
            text_editor_2.required_input_mode_set = NULL;
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &text_editor_2;

            if (ptr_dmui_context->dmui_alert_struct.et == DM_ECHO_TYPE_TEXT)
            {
                text_editor_2.input_type = IMM_INPUT_TYPE_NUMERIC;
            }
            else    /* DM_ECHO_TYPE_PW */
            {
                text_editor_2.input_type = IMM_INPUT_TYPE_NUMERIC_PASSWORD;
            }
            break;
        }

        case DM_INPUT_EDIT_TYPE_DATE:
        {
            date_time_2.year = 0;
            date_time_2.month = 0;
            date_time_2.day = 0;
            date_time_2.hour = 0;
            date_time_2.minute = 0;
            date_time_2.second = 0;
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_DATE;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &date_time_2;
            set_inline_date_boundary(2030, 2000, 12, 1);
            break;
        }

        case DM_INPUT_EDIT_TYPE_TIME:
        {
            date_time_2.year = 0;
            date_time_2.month = 0;
            date_time_2.day = 0;
            date_time_2.hour = 0;
            date_time_2.minute = 0;
            date_time_2.second = 0;
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_TIME;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &date_time_2;
            break;
        }

        case DM_INPUT_EDIT_TYPE_PHONE:
        {
            text_editor_2.string_id = 0;
            text_editor_2.default_text_id = 0;
            text_editor_2.buffer_size = ptr_dmui_context->dmui_alert_struct.max_len - 1;
            text_editor_2.input_type = IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING;
            text_editor_2.input_extended_type = 0;
            text_editor_2.required_input_mode_set = NULL;
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &text_editor_2;
            break;
        }

        case DM_INPUT_EDIT_TYPE_IP:
        {
            ip4_2.b1 = ptr_dmui_context->dmui_alert_input_context.ip_addr[0];
            ip4_2.b2 = ptr_dmui_context->dmui_alert_input_context.ip_addr[1];
            ip4_2.b3 = ptr_dmui_context->dmui_alert_input_context.ip_addr[2];
            ip4_2.b4 = ptr_dmui_context->dmui_alert_input_context.ip_addr[3];
            inline_item[1].item_id = ALERT_INPUT_INLINE_ITEM_ID_2;
            inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_IP4;
            inline_item[1].image_id = 0;
            inline_item[1].item_data = &ip4_2;
            break;
        }

        default:
            break;
    }

    inline_struct.items_count = 2;
    inline_struct.title = STR_ID_DMUI_ALERT_DM_INFO_CAPTION;   
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_DMUI_MAIN);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(GRP_ID_DMAPP_GLOBAL, &inline_struct);
    if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_alert_struct.dr) != 0)
    {
        mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_alert_input_text, (S8*) ptr_dmui_context->dmui_alert_struct.dr);
    }
    cui_inline_set_value(
        inline_id,
        ALERT_INPUT_INLINE_ITEM_ID_1,
        ptr_dmui_context->dmui_alert_string);
    if (ptr_dmui_context->dmui_alert_struct.it == DM_INPUT_EDIT_TYPE_ALPHA ||
        ptr_dmui_context->dmui_alert_struct.it == DM_INPUT_EDIT_TYPE_NUMBER ||
        ptr_dmui_context->dmui_alert_struct.it == DM_INPUT_EDIT_TYPE_PHONE)
    {
        cui_inline_set_value(
            inline_id,
            ALERT_INPUT_INLINE_ITEM_ID_2,
            ptr_dmui_context->dmui_alert_input_text);
    }
    
    cui_inline_run(inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_input
 * DESCRIPTION
 *  function to entry alert input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_input_save_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_date_time_struct get_value_date_time;
    cui_inline_item_ip4_struct get_value_ip4;
    kal_int8 temp_buffer[32];
    U16 item_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_flag = cui_inline_get_item_attributes(
                    ptr_dmui_context->cui_session_alert_input_inline_id,
                    ALERT_INPUT_INLINE_ITEM_ID_2);
    switch (item_flag&0xff)
    {
        case CUI_INLINE_ITEM_TYPE_DATE:
        {
            cui_inline_get_value(
                ptr_dmui_context->cui_session_alert_input_inline_id,
                ALERT_INPUT_INLINE_ITEM_ID_2,
                &get_value_date_time);
            app_ucs2_itoa(
                get_value_date_time.year, 
                temp_buffer,
                10);
            mmi_ucs2cpy(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (CHAR*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L"/");
            app_ucs2_itoa(
                get_value_date_time.month, 
                temp_buffer,
                10);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (CHAR*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L"/");
            app_ucs2_itoa(
                get_value_date_time.day, 
                temp_buffer,
                10);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (CHAR*)temp_buffer);
            break;
        }

        case CUI_INLINE_ITEM_TYPE_TIME:
        {
            cui_inline_get_value(
                ptr_dmui_context->cui_session_alert_input_inline_id,
                ALERT_INPUT_INLINE_ITEM_ID_2,
                &get_value_date_time);
            app_ucs2_itoa(
                get_value_date_time.hour, 
                temp_buffer,
                10);
            mmi_ucs2cpy(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (CHAR*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L":");
            app_ucs2_itoa(
                get_value_date_time.minute, 
                temp_buffer,
                10);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (CHAR*)temp_buffer);
            break;
        }

        case CUI_INLINE_ITEM_TYPE_IP4:
        {
            cui_inline_get_value(
                ptr_dmui_context->cui_session_alert_input_inline_id,
                ALERT_INPUT_INLINE_ITEM_ID_2,
                &get_value_ip4);
            app_ucs2_itoa(
                get_value_ip4.b1, 
                temp_buffer,
                3);
            mmi_ucs2cpy(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L".");

            app_ucs2_itoa(
                get_value_ip4.b2, 
                temp_buffer,
                3);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L".");

            app_ucs2_itoa(
                get_value_ip4.b3, 
                temp_buffer,
                3);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)temp_buffer);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)L".");

            app_ucs2_itoa(
                get_value_ip4.b4, 
                temp_buffer,
                3);
            mmi_ucs2cat(
                (S8*)(ptr_dmui_context->dmui_alert_input_text),
                (S8*)temp_buffer);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_input_confirm
 * DESCRIPTION
 *  function to check alert input and pop up confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_input_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_DMAPP_GLOBAL;
    arg.callback = mmi_dmui_alert_input_cnf_cb;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_dmui_alert_input_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_dmui_alert_input_confirm_yes();
            break;

        case MMI_ALERT_CNFM_NO:
            mmi_dmui_alert_confirm_no();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_input_confirm_yes
 * DESCRIPTION
 *  function to press yes alert input and send message to DM PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_input_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    /* xjdan */
    dmui_alert_rsp->user_input_string = OslMalloc(DMUI_INPUT_BUFFER_SIZE);

    mmi_ucs2cpy((S8*) dmui_alert_rsp->user_input_string, (S8*) ptr_dmui_context->dmui_alert_input_text);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*) dmui_alert_rsp->user_input_string);

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_single_choice
 * DESCRIPTION
 *  function to entry alert single choice screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_single_choice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_ALERT_SINGLE_CHOICE,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_alert_single_choice, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_dmui_hilite_single_choice_handle);

        mmi_dmui_alert_parse_string();

        mmi_dmui_alert_parse_status();

        ShowCategory84Screen(
            STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            ptr_dmui_context->dmui_alert_choice_num,
            (U8 **) subMenuDataPtrs,
            (PU16) gIndexIconsImageList,
            1,
            (S32) 0,
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_dmui_entry_alert_single_choice_ok, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dmui_entry_alert_single_choice_ok, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_single_choice_ok
 * DESCRIPTION
 *  function to press ok in alert single choice screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_single_choice_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);

    ptr_dmui_context->dmui_alert_choice_send[0] = ptr_dmui_context->dmui_hilite_index + '1';
    ptr_dmui_context->dmui_alert_choice_send[1] = 0;
    ptr_dmui_context->dmui_alert_choice_send[2] = 0;
    ptr_dmui_context->dmui_alert_choice_send[3] = 0;

    dmui_alert_rsp->user_input_string = (U8*) OslMalloc(DMUI_INPUT_BUFFER_SIZE);

    mmi_ucs2cpy((S8*) dmui_alert_rsp->user_input_string, (S8*) ptr_dmui_context->dmui_alert_choice_send);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*) dmui_alert_rsp->user_input_string);

    dmui_alert_rsp->b_filename = KAL_FALSE;

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_hilite_single_choice_handle
 * DESCRIPTION
 *  function to save high light index in alert single choice screen
 * PARAMETERS
 *  hilited     [IN]        Current high light item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_hilite_single_choice_handle(S32 hilited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_hilite_index = hilited;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_alert_multi_choice
 * DESCRIPTION
 *  function to entry alert multi choice screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_alert_multi_choice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_ALERT_MULTI_CHOICE,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_alert_multi_choice, 
                        MMI_FRM_FULL_SCRN))
    {
        mmi_dmui_alert_parse_string();

        mmi_dmui_alert_parse_status();

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        SetCheckboxToggleRightSoftkeyFunctions(mmi_dmui_alert_multi_choice_confirm, mmi_frm_scrn_close_active_id);

        ShowCategory140Screen(
            STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            ptr_dmui_context->dmui_alert_choice_num,
            (U8 **) subMenuDataPtrs,
            (U8*) ptr_dmui_context->dmui_alert_default_value,
            0,
            gui_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_parse_string
 * DESCRIPTION
 *  function to entry alert multi choice screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_parse_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 j = 0;
    U8 cmp_strlen = 7;
    U8 *alert_str_ptr = NULL;
    U8 temp_cmp_string[14];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_alert_choice_num = 0;
    alert_str_ptr = ptr_dmui_context->dmui_alert_string;

    while (1)
    {
        /* end of parse string */
        if ((*alert_str_ptr == 0) && (*(alert_str_ptr + 1) == 0))
        {
            ptr_dmui_context->dmui_alert_choice_num++;
            return;
        }

        mmi_ucs2ncpy((S8*) temp_cmp_string, (S8*) alert_str_ptr, cmp_strlen);

        if (mmi_ucs2ncmp((S8*) DMUI_SPLIT_STRING, (S8*) temp_cmp_string, cmp_strlen) == 0)
        {
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j] = 0;
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j + 1] = 0;
            alert_str_ptr += 14;
            ptr_dmui_context->dmui_alert_choice_num++;
            j = 0;
        }
        else
        {
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j] = *alert_str_ptr;
            j++;
            alert_str_ptr++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_parse_status
 * DESCRIPTION
 *  function to get default value from dr parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_parse_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cmp_strlen = 7;
    U8 *alert_str_ptr = NULL;
    U8 temp_cmp_string[14];
    U8 alert_dr[MAX_SUB_MENU_SIZE];
    U8 digit = 0;
    S32 alert_num;
    S32 alert_num_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ptr_dmui_context->dmui_alert_default_value, 0x00, MAX_SUB_MENUS);
    alert_str_ptr = ptr_dmui_context->dmui_alert_struct.dr;

    while (1)
    {
        if ((*alert_str_ptr == 0) && (*(alert_str_ptr + 1) == 0))
        {
            if (alert_dr[0] != 0)
            {
                mmi_ucs2toi((S8*)alert_dr, &alert_num, &alert_num_length);
                ptr_dmui_context->dmui_alert_default_value[alert_num - 1] = 1;
            }
            return;
        }

        mmi_ucs2ncpy((S8*) temp_cmp_string, (S8*) alert_str_ptr, cmp_strlen);

        if (mmi_ucs2ncmp((S8*) DMUI_SPLIT_STRING, (S8*) temp_cmp_string, cmp_strlen) == 0)
        {
            if (alert_dr[0] != 0)
            {
                mmi_ucs2toi((S8*)alert_dr, &alert_num, &alert_num_length);
                ptr_dmui_context->dmui_alert_default_value[alert_num - 1] = 1;
                memset(alert_dr, 0, MAX_SUB_MENU_SIZE);
            }
            
            alert_str_ptr += 14;
            digit = 0;
        }
        else
        {
            alert_dr[digit] = *alert_str_ptr;
            digit++;
            alert_str_ptr++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_multi_choice_confirm
 * DESCRIPTION
 *  function to popup a confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_multi_choice_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_DMAPP_GLOBAL;
    arg.callback = mmi_dmui_alert_multi_choice_cnf_cb;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_DMUI_ALERT_DM_INFO_CAPTION),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_dmui_alert_multi_choice_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_dmui_alert_multi_choice_confirm_yes();
            break;

        case MMI_ALERT_CNFM_NO:
            mmi_dmui_alert_confirm_no();
            break;

        default:
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_multi_choice_confirm_yes
 * DESCRIPTION
 *  function to response left key in confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_multi_choice_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 multi_send_index = 0;
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);

    while (1)
    {
        if (ptr_dmui_context->dmui_alert_default_value[count])
        {
            app_ucs2_itoa(
                (kal_int32)(count + 1), 
                (kal_int8*)&ptr_dmui_context->dmui_alert_choice_send[multi_send_index], 
                10);
            multi_send_index += 
                2 * mmi_ucs2strlen((S8*)&ptr_dmui_context->dmui_alert_choice_send[multi_send_index]);
        }
        
        count++;
        
        if (count == ptr_dmui_context->dmui_alert_choice_num)
        {
            break;
        }
        if (ptr_dmui_context->dmui_alert_default_value[count] && multi_send_index != 0)
        {
            mmi_ucs2cat(
                (S8*)&ptr_dmui_context->dmui_alert_choice_send[multi_send_index],
                (S8*)DMUI_SPLIT_STRING);
            multi_send_index += 14;
        }
    }

    mmi_ucs2cpy((S8*) dmui_alert_rsp->user_input_string, (S8*) ptr_dmui_context->dmui_alert_choice_send);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*) dmui_alert_rsp->user_input_string);

    dmui_alert_rsp->b_filename = KAL_FALSE;

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_ALERT_MULTI_CHOICE);

    ptr_dmui_context->dmui_alert_scr_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_confirm_no
 * DESCRIPTION
 *  function to response right key in confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_REJECT;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_alert_confirm_cancel
 * DESCRIPTION
 *  function to response end key in confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_alert_confirm_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);
    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;
    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */ 

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_otap_confirm_entry_hdlr,
        (void*)&dmui_confirm);

    ptr_dmui_context->dmui_alert_scr_id = 0;
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_OTA_CONFIRM);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_ALERT_INPUT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_download_progress_ind_handle
 * DESCRIPTION
 *  function to receive download progress and display download percents.
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_download_progress_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_dl_percent = 0;
    dm_dl_progress_struct *ptr_dmui_dlprogress = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dlprogress = (dm_dl_progress_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DOWNLOAD_PROGRESS_IND, ptr_dmui_dlprogress->ui_mode);

    cur_dl_percent = ptr_dmui_dlprogress->received_bytes * 100 / ptr_dmui_dlprogress->total_bytes;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DOWNLOAD_PROGRESS_PERCENT, cur_dl_percent);

    mmi_dmui_display_download_progress((U32) cur_dl_percent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_entry_download_progress
 * DESCRIPTION
 *  function to entry download progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_entry_download_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ENTRY_DOWNLOAD_PROGRESS);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_DOWNLOAD_PROGRESS,
                        NULL,
                        (FuncPtr)mmi_dmui_entry_download_progress, 
                        MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_DOWNLOAD_PROGRESS,
            mmi_dmui_download_progress_leave_proc);

        if (ptr_dmui_context->dmui_dl_percent == 100)
        {
            string = (U8*)GetString(STR_GLOBAL_PLEASE_WAIT);
        }

        ShowCategory402Screen(
            (U8*) GetString(STR_GLOBAL_DOWNLOADING),
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            NULL,
            ptr_dmui_context->dmui_dl_percent,
            string);
        if (ptr_dmui_context->dmui_dl_percent == 100)
        {
            ChangeRightSoftkey(0, 0);
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        }
        else
        {
            SetRightSoftkeyFunction(mmi_dmui_download_progress_no, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_download_progress_leave_proc
 * DESCRIPTION
 *  function to cancel download progress
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_download_progress_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
         return -1; /* Forbid closing */
    }
    
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_download_progress_no
 * DESCRIPTION
 *  function to cancel download progress with right key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_download_progress_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DOWNLOAD_PROGRESS_NO);

#ifdef _DM_OMADL_VIA_DLAGENT_
    srv_da_stop_dl(dl_session_id);
    g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
    mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);
#else
    dm_cancel_downloading();
#endif /*_DM_OMADL_VIA_DLAGENT_*/
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
}

MMI_BOOL mmi_dmui_display_dl_progress_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dmui_entry_download_progress();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_display_download_progress
 * DESCRIPTION
 *  function to display download progress
 * PARAMETERS
 *  percentage      [IN]        Percent of current progress
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_display_download_progress(U32 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DMUI_DOWNLOAD_PROGRESS)   /* current screen is download progress */
    {
        if (percentage != ptr_dmui_context->dmui_dl_percent)
        {
            /* save download percent and update screen */
            ptr_dmui_context->dmui_dl_percent = percentage;
            UpdateCategory402Value((U16) percentage, NULL);
        }

        if (ptr_dmui_context->dmui_dl_percent == 100)
        {
            ChangeRightSoftkey(0, 0);
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            UpdateCategory402Value((U16) percentage, (U8*)GetString(STR_GLOBAL_PLEASE_WAIT));
        }
    }
    else if (MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))   /* download progress not a scr in history */
    {
        /* not the first time reach the 100 percentage */
        if (percentage == 100)
        {
            return;
        }
        /* save download percent and display download screen */
        ptr_dmui_context->dmui_dl_percent = percentage;
        if (MMI_FALSE == mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DM, mmi_dmui_display_dl_progress_hdlr, NULL))
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_PROGRESS,
                mmi_dmui_display_dl_progress_hdlr,
                NULL);
        }
    }
    else    /* update percentage */
    {
        ptr_dmui_context->dmui_dl_percent = percentage;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_download_progress_cancel
 * DESCRIPTION
 *  function to back to idle screen when press end key in download progress
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_download_progress_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DOWNLOAD_PROGRESS_CANCEL);

#ifdef _DM_OMADL_VIA_DLAGENT_
    srv_da_stop_dl(dl_session_id);
    g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
    mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);
#else
    dm_cancel_downloading();
#endif /*_DM_OMADL_VIA_DLAGENT_*/
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_change_account_ind_handle
 * DESCRIPTION
 *  function to receive change account message from DM PS
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_change_account_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_change_account_struct *dmui_change_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_change_account = (dm_change_account_struct*) msg;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_CHANGE_ACCOUNT_IND, dmui_change_account->action_type);

    switch (dmui_change_account->action_type)
    {
        case DM_ACTION_TYPE_ADD:
        {
            U8 i = 0;

            for (i = 0; i < DMUI_MAX_SERVERID; i++)
            {
                if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
                {
                    mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_profile_array[i].server_id, (S8*) dmui_change_account->server_id);
                    break;
                }
            }
        }
            break;

        case DM_ACTION_TYPE_UPDATE:
            break;

        case DM_ACTION_TYPE_DELETE:
        {
            U8 i = 0;

            for (i = 0; i < DMUI_MAX_SERVERID; i++)
            {
                if (mmi_ucs2cmp(
                        (S8*) ptr_dmui_context->dmui_profile_array[i].server_id,
                        (S8*) dmui_change_account->server_id) == 0)
                {
                    mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_profile_array[i].server_id, (S8*) L"");
                    break;
                }
            }
        }
            break;

        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_exec_complete_ind_handle
 * DESCRIPTION
 *  function to receive exec complete message
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_exec_complete_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_EXEC_COMPLETE_IND);
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_session_start_ind_handle
 * DESCRIPTION
 *  function to receive session start message from DM PS
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_session_start_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SESSION_START_IND);

    g_mmi_dmui_is_in_session = MMI_TRUE;
    ptr_dmui_context->ending_msg = MMI_DMUI_ENDING_MSG_DEFAULT;
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_PROMPT_MESSAGE);
#ifdef __DM_LAWMO_SUPPORT__
    g_mmi_dmui_is_reg_sim_available = MMI_TRUE;
#endif /* __DM_LAWMO_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_session_finish_ind_handle
 * DESCRIPTION
 *  function to receive session finish message from DM PS
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_session_finish_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SESSION_FINISH_IND);
    g_mmi_dmui_is_in_session = MMI_FALSE;

    if (ptr_dmui_context->ending_msg != MMI_DMUI_ENDING_MSG_TIMEOUT)
    {
        mmi_dmui_run_ending_msg();
        ptr_dmui_context->ending_msg = MMI_DMUI_ENDING_MSG_DEFAULT;
    }

    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_error_ind_handle
 * DESCRIPTION
 *  function of exit DM UI main menu
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_error_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_ERROR_IND);
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_dl_report_callback
 * DESCRIPTION
 *  function of exit DM UI main menu
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_dl_report_callback(BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (success == FALSE)
    {
        mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);
        g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
    }
    else
    {
        mmi_dmui_dl_report(DM_DOWNLOADING_UPDATE_PKG);
        /* DLA will close its waiting screen and DM should show the download screen */
        mmi_dmui_display_download_progress(0);
        g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_DL_START;
    }
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_start_dl_ind_handle
 * DESCRIPTION
 *  function of exit DM UI main menu
 * PARAMETERS
 *  msg     [IN]        Message point from DM PS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_start_dl_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
    {
    #ifdef __DM_FOTA_SUPPORT__
        mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);
    #else
        dm_cancel_downloading();
    #endif /*__DM_FOTA_SUPPORT__*/
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    if (SRV_MODE_FLIGHT_MODE == srv_mode_switch_get_current_mode() ||
        MMI_DMUI_FOTA_STATUS_RECV_NOTIFY == g_dmui_fota_status ||
        MMI_DMUI_FOTA_STATUS_NOTIFY_DLAGENT == g_dmui_fota_status)
    {
        return;
    }
    g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_RECV_NOTIFY;

    hold_local_para((local_para_struct*)msg);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dmui_dl_via_dlagent_entry_hdlr,
        (void*)msg);
}


MMI_BOOL mmi_dmui_dl_via_dlagent_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_start_dl_res_ind_struct *dmui_start_dl_ptr = (dm_start_dl_res_ind_struct*)arg;
    BOOL show_confirm = FALSE;
    wps_set_channel_req_struct *wps_setting = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_START_DL_IND_HDLR);
    StopTimer(DMUI_DOWNLOAD_RESUME_CONFIRM_TIMER_ID);
    g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_NOTIFY_DLAGENT;

    /* ???? */
    wps_setting = (wps_set_channel_req_struct*) OslConstructDataPtr(sizeof(wps_set_channel_req_struct));
    wps_setting->use_default = KAL_FALSE;
    if (dmui_start_dl_ptr->xpt_type == DM_XPT_TYPE_HTTP)
    {
        wps_setting->conn_type = WPS_CONN_TYPE_HTTP;
    }
    else
    {
        wps_setting->conn_type = WPS_CONN_TYPE_WSP_CO;
    }
    wps_setting->timeout = 30;
    wps_setting->net_id = dmui_start_dl_ptr->network_id;
    wps_setting->use_proxy = dmui_start_dl_ptr->proxy_used;
    if (wps_setting->use_proxy == KAL_TRUE)
    {
        memcpy(wps_setting->prx_ip, &(dmui_start_dl_ptr->proxy_ip), 4);
        wps_setting->prx_port = dmui_start_dl_ptr->proxy_port;
        strncpy((char*)wps_setting->username, (kal_char*) dmui_start_dl_ptr->user_name, 30);
        wps_setting->username[29] = '\0';
        strncpy((char*)wps_setting->password, (kal_char*) dmui_start_dl_ptr->password, 30);
        wps_setting->password[29] = '\0';
    }

    if (dmui_start_dl_ptr->b_resume == MMI_TRUE)
    {
        if (g_mmi_dmui_download_resume_is_need_confirm == MMI_TRUE)
        {
            show_confirm = TRUE;
        }
        else
        {
            g_mmi_dmui_waiting_screen_msg = GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_RESUME);
            mmi_dmui_none_del_waiting_entry();
            show_confirm = FALSE;
        }
    }
    else
    {
        show_confirm = TRUE;
    }

    srv_da_start_oma_download(
        (S8*) dmui_start_dl_ptr->ddfilename,
        (void*)wps_setting,
        show_confirm,
        mmi_dmui_dl_report_callback);

    if (arg)
    {
        free_local_para((local_para_struct*)arg);
    }

    OslFreeDataPtr(wps_setting);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_dl_resume_ind_handle
 * DESCRIPTION
 *  function to add waiting screen when edit or erase DM information
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_dl_resume_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_resume_dl(dl_session_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_waiting_entry
 * DESCRIPTION
 *  function to add waiting screen when edit or erase DM information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_waiting_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_SETTING, 
                        SCR_ID_DMUI_WAITING,
                        NULL,
                        mmi_dmui_waiting_entry, 
                        MMI_FRM_FG_ONLY_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        switch (ptr_dmui_context->dmui_status)
        {
            case MMI_DMUI_ADD_ACCOUNT_STATUS:
            case MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS:
            case MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS:
            {
                ShowCategory66Screen(
                    STR_ID_DMUI_MAIN,
                    GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                    0,
                    0,
                    0,
                    0,
                    (U8*) GetString(STR_GLOBAL_SAVING),
                    IMG_GLOBAL_PROGRESS,
                    gui_buffer);
            }
                break;

            case MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS:
            case MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS:
            {
                ShowCategory66Screen(
                    STR_ID_DMUI_MAIN,
                    GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                    0,
                    0,
                    0,
                    0,
                    (U8*) GetString(STR_GLOBAL_DELETING),
                    IMG_GLOBAL_PROGRESS,
                    gui_buffer);
            }
                break;

            default:
            {
                ShowCategory66Screen(
                    STR_ID_DMUI_MAIN,
                    GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                    0,
                    0,
                    0,
                    0,
                    (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
                    IMG_GLOBAL_PROGRESS,
                    gui_buffer);
            }
                break;
        }

        ClearAllKeyHandler();
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_none_del_waiting_entry
 * DESCRIPTION
 *  function to show please wait to avoid go back to idle when invoke dl
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_none_del_waiting_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_DMAPP_GLOBAL) == MMI_FALSE)
    {
        mmi_frm_group_create(
            GRP_ID_ROOT,
            GRP_ID_DMAPP_GLOBAL,
            mmi_dmui_global_scr_group_proc,
            (void*)NULL);
        mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL,
                        SCR_ID_DMUI_WAITING,
                        NULL,
                        mmi_dmui_none_del_waiting_entry,
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_WAITING,
            mmi_dmui_waiting_leave_proc);

        ShowCategory66Screen(
            STR_ID_DMUI_MAIN,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            0,
            0,
            0,
            0,
            (U8*)g_mmi_dmui_waiting_screen_msg,
            IMG_GLOBAL_PROGRESS,
            gui_buffer);

        ClearAllKeyHandler();
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_waiting_leave_proc
 * DESCRIPTION
 *  function to avoid waiting_entry screen be deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_waiting_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        return -1;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_serverid_valid
 * DESCRIPTION
 *  function to check server id valid or not
 * PARAMETERS
 *  p_serverid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p = (U8*) p_serverid;
    U8 ansii_max_value = 127;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(p_serverid);

    while ((*p != 0) || (*(p + 1) != 0))
    {
        if (*p < ansii_max_value)
        {
            p++;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;

}

#ifdef MMI_DM_OP
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_ota_init_profile
 * DESCRIPTION
 *  function to init default DM setting profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_ota_init_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dm_init_flag = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DM_OTA_PROFILE_INIT, &dm_init_flag, DS_BYTE, &error);

    /* DM default setting not init */
    if (dm_init_flag == (U8) 0xFF)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_FLAG, dm_init_flag);

        /* DM default setting is exist */
        if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id) != 0)
        {
            dm_server_id_struct *dmui_del_serverid = NULL;

            dmui_del_serverid = OslAllocDataPtr(dm_server_id_struct);

            mmi_ucs2cpy(
                (S8*) dmui_del_serverid->server_id,
                (S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id);

            ptr_dmui_context->dmui_status = MMI_DM_OTA_INIT_DEL_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
        }
        else    /* DM default setting exist */
        {
            mmi_dm_ota_init_profile2();
        }
    }
    else if (dm_init_flag == (U8) 0x01)
    {
        U8 temp_string[DM_MAX_URI_SIZE];

        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_FLAG, dm_init_flag);

        /* DM default setting is exist */
        if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id) != 0)
        {
            FS_HANDLE fh;

            memset(temp_string, 0x00, DM_MAX_URI_SIZE);
            mmi_ucs2_to_asc((S8*) temp_string, (S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id);

            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_SERVERID_EXIST);
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_DEFAULT_SERVERID_INFO, temp_string);

            memset(temp_string, 0x00, DM_MAX_URI_SIZE);
            mmi_ucs2_to_asc((S8*) temp_string, (S8*) ptr_dmui_context->dmui_primary_serverid);
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_PSERVERID_INFO, temp_string);

            /* if restore factory, the serverid.dat will be removed, remake the default profile activated */
            fh = FS_Open(L"Z:\\@dm\\serverid.dat", FS_READ_ONLY);
            if (fh < 0)
            {
                dm_server_id_struct *dmui_active_serverid = NULL;

                dmui_active_serverid = OslAllocDataPtr(dm_server_id_struct);

                mmi_ucs2cpy(
                    (S8*)dmui_active_serverid->server_id,
                    (S8*)ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id);
                mmi_ucs2cpy(
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id,
                    (S8*)ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id);

                ptr_dmui_context->dmui_status = MMI_DM_OTA_INIT_SET_PSERVERID_STATUS;
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
            }
            else
            {
                FS_Close(fh);
            }
        }
        else    /* DM default setting not exist */
        {
            memset(temp_string, 0x00, DM_MAX_URI_SIZE);
            mmi_ucs2_to_asc((S8*) temp_string, (S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id);

            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_SERVERID_NOT_EXIST);
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_DEFAULT_SERVERID_INFO, temp_string);

            memset(temp_string, 0x00, DM_MAX_URI_SIZE);
            mmi_ucs2_to_asc((S8*) temp_string, (S8*) ptr_dmui_context->dmui_primary_serverid);
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_PSERVERID_INFO, temp_string);

            mmi_dm_ota_init_profile2();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_ota_init_profile2
 * DESCRIPTION
 *  function to init default DM setting profile second process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_ota_init_profile2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_nodename[DM_MAX_ID_STR];
    dm_add_account_struct *dmui_add_account = NULL;
    srv_dtcnt_prof_proxy_info_struct proxy_info;
    U32 auto_account_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_INIT_PROFILE_2_FUNCTION);

    dmui_add_account = OslAllocDataPtr(dm_add_account_struct);

    memset(temp_nodename, 0x00, DM_MAX_ID_STR);
    memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));
    memset(&proxy_info, 0x00, sizeof(srv_dtcnt_prof_proxy_info_struct));
    gui_itoa((U32) DM_DEFAULT_PROFILE_INDEX, (UI_string_type) temp_nodename, 10);

    {
        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID);

        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.server_pw,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW);

        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.server_addr,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR);

        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.user_name,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME);

        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_cur_edit_account.user_pw,
            (S8*) DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW);

        ptr_dmui_context->dmui_cur_edit_account.auth_pref = DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE;
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*)temp_nodename);

        ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id =
            cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, 0, g_mmi_dmui_cbm_id, 0);
        srv_dtcnt_get_auto_acc_id(ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id, &auto_account_id);
        if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                            auto_account_id,
                            &proxy_info,
                            SRV_DTCNT_ACCOUNT_PRIMARY))
        {            
            if (proxy_info.use_proxy)
            {
                S8 temp_proxy_addr[DM_MAX_IP_SIZE];
                ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_TRUE;
                
                sprintf(temp_proxy_addr, "%d.%d.%d.%d", proxy_info.px_addr[0], proxy_info.px_addr[1], proxy_info.px_addr[2], proxy_info.px_addr[3]);
                mmi_asc_to_ucs2(
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_addr,
                    (S8*)temp_proxy_addr);

                ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_port = (U32)proxy_info.px_port;

                mmi_asc_to_ucs2(
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_name,
                    (S8*)proxy_info.px_authid);

                mmi_asc_to_ucs2(
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_pw,
                    (S8*)proxy_info.px_authpw);

            }
            else
            {
                ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_FALSE;
            }
        }
        else
        {
            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = MMI_FALSE;
        }
    }

    memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

    /* set DMUI status */
    ptr_dmui_context->dmui_status = MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);
}
#endif /* MMI_DM_OP */


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_read_info_from_file
 * DESCRIPTION
 *  function to read download or update information from file
 * PARAMETERS
 *  file_path       [IN]        Path of received file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_read_info_from_file(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_READ_FILE_INVALID_PATH);
        return;
    }

    fd = FS_Open(file_path, FS_READ_ONLY);

    if (fd >= 0)
    {
        FS_Read(fd, &(ptr_dmui_context->dmui_display_info), sizeof(dm_omadl_dd_struct), &size);
        FS_Close(fd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_init_serverid
 * DESCRIPTION
 *  function to init server id list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_init_serverid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_status = MMI_DMUI_ONLY_INIT_SERVERID_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LIST_SERVERID_REQ, NULL);
}

/* function to fill struct of confirm screen */


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fill_confirm_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  LSK_str                 [IN]        
 *  LSK_img                 [IN]        
 *  RSK_str                 [IN]        
 *  RSK_img                 [IN]        
 *  message                 [IN]        
 *  message_image           [IN]        
 *  toneId                  [IN]        
 *  confirmDuration         [IN]        
 *  confirmTimeOutFunc      [IN]        
 *  LSKFunc                 [IN]        
 *  RSKFunc                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fill_confirm_struct(
                U16 LSK_str,
                U16 LSK_img,
                U16 RSK_str,
                U16 RSK_img,
                UI_string_type message,
                U16 message_image,
                U16 toneId,
                U32 confirmDuration,
                TimeOutFuncPtr confirmTimeOutFunc,
                FuncPtr LSKFunc,
                FuncPtr RSKFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&dmui_confirm, 0x00, sizeof(dmui_confirm_struct));

    dmui_confirm.LSK_str = LSK_str;
    dmui_confirm.LSK_img = LSK_img;
    dmui_confirm.RSK_str = RSK_str;
    dmui_confirm.RSK_img = RSK_img;

    dmui_confirm.message = message;

    dmui_confirm.message_image = message_image;

    dmui_confirm.toneId = toneId;

    dmui_confirm.confirmDuration = confirmDuration;
    dmui_confirm.confirmTimeOutFunc = confirmTimeOutFunc;

    dmui_confirm.LSKFunc = LSKFunc;
    dmui_confirm.RSKFunc = RSKFunc;
}


/*****************************************************************************
 * FUNCTION
 *  ConfirmTimerOver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmTimerOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(DMUI_OTAP_CONFIRM_TIMER);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_OTA_CONFIRM);

    if (dmui_confirm.confirmTimeOutFunc)
    {
        (*dmui_confirm.confirmTimeOutFunc) ();
    }

    memset(&dmui_confirm, 0x00, sizeof(dmui_confirm_struct));
}


MMI_BOOL mmi_dmui_otap_confirm_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dmui_otap_confirm();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_otap_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_otap_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_OTA_CONFIRM,
                        NULL,
                        (FuncPtr)mmi_dmui_otap_confirm, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_OTA_CONFIRM,
            mmi_dmui_ota_confirm_leave_proc);

        ShowCategory165Screen(
            dmui_confirm.LSK_str,
            dmui_confirm.LSK_img,
            dmui_confirm.RSK_str,
            dmui_confirm.RSK_img,
            (UI_string_type) dmui_confirm.message,
            dmui_confirm.message_image,
            gui_buffer);

        if (dmui_confirm.LSKFunc)
        {
            SetLeftSoftkeyFunction((*dmui_confirm.LSKFunc), KEY_EVENT_UP);
            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction((*dmui_confirm.LSKFunc), KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        }

        if (dmui_confirm.RSKFunc)
        {
            SetRightSoftkeyFunction((*dmui_confirm.RSKFunc), KEY_EVENT_UP);
        }
        else
        {
            SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        }

        if (dmui_confirm.confirmDuration)
        {
            StartTimer(DMUI_OTAP_CONFIRM_TIMER, dmui_confirm.confirmDuration, ConfirmTimerOver);
        }

        if (dmui_confirm.toneId)
        {
            srv_prof_play_tone(SRV_PROF_TONE_NONE, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_otap_confirm_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_ota_confirm_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
#endif
    /* for init_session and alert_confirm use the same scr_id */
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DMAPP_GLOBAL,
        SCR_ID_DMUI_OTA_CONFIRM,
        NULL);

    return MMI_RET_ALLOW_CLOSE;
}


/******************************************************************************
*                   external function for DM PS
******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_unfinish_check_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_unfinish_check_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 temp_prt[DM_MAX_URI_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_CHECK_FUNCTION);

#ifdef __SYNCML_DM_TEST__
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_CHECK_APP_INFO);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dmui_context->dmui_primary_serverid);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_PSERVERID_INFO, temp_prt);

    for (i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dmui_context->dmui_profile_array[0].server_id);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_SERVERID_INFO, i, temp_prt);
    }

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_HILITE_INDEX, ptr_dmui_context->dmui_hilite_index);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_HI_SERVERID_INDEX, ptr_dmui_context->dmui_hilite_serverid_index);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UNFINISH_CHECK_APP_INFO);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);

#else /* __SYNCML_DM_TEST__ */ 
    return;
#endif /* __SYNCML_DM_TEST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_print_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr_dm_account      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_print_info(dm_account_struct *ptr_dm_account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_prt[DM_MAX_URI_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ptr_dm_account);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_INFO);

#ifdef __SYNCML_DM_TEST__
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_INFO_APP_INFO);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->node_name);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_NODENAME, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->server_id);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_SERVERID, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->server_addr);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_SERVERADDR, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->server_pw);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_SERVERPW, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->user_name);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_USERNAME, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->user_pw);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_USER_PW, temp_prt);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_AUTH_PREF, ptr_dm_account->auth_pref);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_INFO_PROXY_INFO);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_DATA_ACCT_ID, ptr_dm_account->conn_setting.data_account_id);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->conn_setting.proxy_addr);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_PROXY_ADDR, temp_prt);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_PROXY_PORT, ptr_dm_account->conn_setting.proxy_port);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_PROXY_USED, ptr_dm_account->conn_setting.proxy_used);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->conn_setting.proxy_user_name);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_PROXY_USER_NAME, temp_prt);

    mmi_ucs2_to_asc((S8*) temp_prt, (S8*) ptr_dm_account->conn_setting.proxy_user_pw);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_PROXY_USER_PASSWORD, temp_prt);

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_PRINT_INFO);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_TITLE_MARK);

#else /* __SYNCML_DM_TEST__ */ 
    return;
#endif /* __SYNCML_DM_TEST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_syncml_dm_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_screen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_screen = mmi_frm_scrn_get_active_id();

    if (temp_screen >= SCR_ID_DMUI_MAIN && temp_screen <= SCR_ID_DMUI_POPUP_CONFIRM)
    {
        return MMI_FALSE;
    }

    for (temp_screen = SCR_ID_DMUI_MAIN; temp_screen <= SCR_ID_DMUI_POPUP_CONFIRM; temp_screen++)
    {
        if (MMI_TRUE == mmi_frm_scrn_is_present(GRP_ID_DMAPP_GLOBAL, temp_screen, MMI_FRM_NODE_ALL_FLAG))
            return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_network_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_network_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_NETWORK_TIMER_CALLBACK);
    
    is_network_timeout = MMI_TRUE;
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_nw_info_srv_availability_changed
 * DESCRIPTION
 *  notify dm network status
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_nw_info_srv_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *srv_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (srv_evt->new_status == SRV_NW_INFO_SA_NO_SERVICE ||
        srv_evt->new_status == SRV_NW_INFO_SA_LIMITED_SERVICE ||
        srv_evt->new_status == SRV_NW_INFO_SA_SEARCHING)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_NETWORK_STATUS, MMI_FALSE);
        g_mmi_dmui_network_state = DM_NETWORK_NOT_AVAILABLE;
        if (g_dmui_fota_status == MMI_DMUI_FOTA_STATUS_DL_START)
        {
            srv_da_remove_dl(dl_session_id);
        }
        dm_notify_network_status_internal(MMI_FALSE);
    }
    else if (srv_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_NETWORK_STATUS, MMI_TRUE);
        if (g_mmi_dmui_network_state == DM_NETWORK_NOT_AVAILABLE)
        {
            g_mmi_dmui_network_state = DM_NETWORK_AVAILABLE;
            if (mmi_dmui_is_in_call())
            {
                return MMI_RET_OK;
            }
            dm_notify_network_status_internal(MMI_TRUE);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_download_resume_confirm_timer_callback
 * DESCRIPTION
 *  change the flag if need show the download resume confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_download_resume_confirm_timer_callback(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_dmui_download_resume_is_need_confirm = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dm_da_report_hdlr
 * DESCRIPTION
 *  When the file is downloaded from WAP browser, we set it as oma download
 *  else, we save it to file system only.
 * PARAMETERS
 *  session_id      [IN]        
 *  status          [IN]        
 *  cause           [IN]        
 *  seq_num         [IN]        
 *  acc_size        [IN]        
 *  total_size      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_da_report_hdlr(S32 session_id, S32 status, S32 cause, U32 seq_num, U32 acc_size, U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_progress_struct *dl_progress_ptr = NULL;
    dmui_da_report_struct *dmui_da_report_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DA_REPORT_HDLR, status, cause);

    /* network close,  */
    if (g_mmi_dmui_network_state == DM_NETWORK_NOT_AVAILABLE ||
        cause == SRV_DA_ERROR_CONNECTION_CLOSED ||
        cause == SRV_DA_ERROR_BROWSER_CLOSED)
    {
        mmi_dmui_dl_report(DM_DOWNLOADING_NETWORK_CLOSE);
        g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
        if (status == SRV_DA_STATE_PAUSE ||
            status == SRV_DA_STATE_ABORT)
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_PAUSE_BY_NETWORK_ANOMALY));
            mmi_frm_nmgr_cancel_deferred_scenario(
                MMI_SCENARIO_ID_DM,
                mmi_dmui_display_dl_progress_hdlr,
                NULL);
            mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
            g_mmi_dmui_download_resume_is_need_confirm = MMI_FALSE;
            StartTimer(
                DMUI_DOWNLOAD_RESUME_CONFIRM_TIMER_ID,
                DMUI_DOWNLOAD_RESUME_NEED_CONFIRM_TIME,
                mmi_dmui_download_resume_confirm_timer_callback);
        }
        return;
    }

    switch (status)
    {
        case SRV_DA_STATE_INIT:
            
            return;

        case SRV_DA_STATE_PAUSE:
        {
            g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
            dmui_da_report_ptr = OslAllocDataPtr(dmui_da_report_struct);
            dmui_da_report_ptr->cause = cause;
            DMUI_SEND_MSG_TO_MMI(MSG_ID_DM_DA_STATE_PAUSE, dmui_da_report_ptr);

            return;
        }
            
        case SRV_DA_STATE_ABORT:    /* by network */
        {
            g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
            dmui_da_report_ptr = OslAllocDataPtr(dmui_da_report_struct);
            dmui_da_report_ptr->cause = cause;
            DMUI_SEND_MSG_TO_MMI(MSG_ID_DM_DA_STATE_ABORT, dmui_da_report_ptr);    

            return;
        }

        case SRV_DA_STATE_DOWNLOADING:
        {
            dl_session_id = session_id;

            dl_progress_ptr = OslAllocDataPtr(dm_dl_progress_struct);
            dl_progress_ptr->ui_mode = session_uimode;
            dl_progress_ptr->received_bytes = acc_size;
            dl_progress_ptr->total_bytes = total_size;

            DMUI_SEND_MSG_TO_MMI(MSG_ID_DM_DL_PROGRESS_IND, dl_progress_ptr);
            return;
        }

        case SRV_DA_STATE_COMPLETE:
            g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
            DMUI_SEND_MSG_TO_MMI(MSG_ID_DM_DA_STATE_COMPLETE, NULL); 

            return;

        case SRV_DA_STATE_USER_CANCEL:  /* by user */
            g_dmui_fota_status = MMI_DMUI_FOTA_STATUS_IDLE;
            mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);

           return;

        default:
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_da_fumo_setting
 * DESCRIPTION
 *  When the file is downloaded from WAP browser, we set it as oma download
 *  else, we save it to file system only.
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        
 *  mime_subtype            [IN]        
 *  action                  [IN]        
 *  filesize                [IN]        
 *  url                     [IN]        
 *  mime_type_string        [IN]        
 *  content_len             [IN]        
 *  content                 [IN]        
 *  setting                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_da_fumo_setting(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        U32 filesize,
        S8 *url,
        S8 *mime_type_string,
        U32 content_len,
        S8 *content,
        srv_da_setting_struct *setting)
{
#define DM_UPC_FILE_NAME                    L"UpdatePackage"
#define DM_FOLDER_PATH                      L"@dm\\"
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action != MMI_DA_OMA_DOWNLOAD)
    {
        srv_da_default_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
        setting->do_dispatch = MMI_FALSE;
        return;
    }
    else
    {
        srv_da_bypass_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
    }

    setting->bypass = MMI_DA_BYPASS_LEVEL_2;
    setting->default_filename = MMI_FALSE;
    mmi_ucs2cpy((S8*) setting->filename, (const S8*)DM_UPC_FILE_NAME);

    setting->can_minimize = MMI_FALSE;
    mmi_ucs2cpy((S8*) setting->folder, (const S8*)DM_FOLDER_PATH);

    setting->filepath_hdlr = NULL;
    setting->percentage_bar = MMI_FALSE;
    setting->report_hdlr = dm_da_report_hdlr;

    setting->storage = SRV_DA_STORAGE_PHONE;
    setting->drv = SRV_FMGR_SYSTEM_DRV;

    setting->keepfile = MMI_FALSE;

    setting->confirm_dispatch = MMI_FALSE;
    setting->confirm_push = MMI_TRUE;
    setting->do_dispatch = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_da_push_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action                      [IN]        
 *  filesize                    [IN]        
 *  url                         [IN]        
 *  mime_type_string            [IN]      
 *  content_len                 [IN]
 *  content                     [IN]
 *  setting                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_da_push_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    PS8 url,
    PS8 mime_type_string,
    U32 content_len,
    PS8 content,
    srv_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_push_setting(
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        setting);

#ifdef __MMI_USB_SUPPORT__
    if (MMI_TRUE == srv_usb_is_in_mass_storage_mode())
    {
        setting->storage = SRV_DA_STORAGE_PUSH_TEMP;
    }
    else
    {
        setting->storage = SRV_DA_STORAGE_GIVEN;
        setting->drv = SRV_FMGR_SYSTEM_DRV;
        mmi_wcscpy(setting->folder, L"@dm\\");
    }
#else
    setting->storage = SRV_DA_STORAGE_GIVEN;
    setting->drv = SRV_FMGR_SYSTEM_DRV;
    mmi_wcscpy(setting->folder, L"@dm\\");
#endif /* __MMI_USB_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_dl_report
 * DESCRIPTION
 *  When the file is downloaded from WAP browser, we set it as oma download
 *  else, we save it to file system only.
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_dl_report(dm_dl_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_report_struct *dl_report_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dl_report_ptr = OslAllocDataPtr(dm_dl_report_struct);

    dl_report_ptr->status = status;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_REPORT, dl_report_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  dm_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void dm_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 *data_ptr = NULL;

    kal_int32 data_len = 0;

    kal_uint32 read_len = 0;

    FS_HANDLE fSrc, fDes;

    dm_push_struct *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RECV_DA_FILE);
#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    fSrc = FS_Open(filepath, FS_READ_ONLY);

    if (fSrc < 0)
    {
        /* ASSERT(0); */

        return;
    }

    fDes = FS_Open(DM_PUSH_TEMP_FILE_NAME, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fDes < 0)
    {
        FS_Close(fSrc);

        FS_Delete(filepath);

        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fSrc, (kal_uint32*) & data_len))
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RECV_DA_FILE_DATA_LEN, data_len);

        data_ptr = (kal_uint8*)OslMalloc(TMP_BUFFER_SIZE);

        data_ptr[0] = 0x01;
        data_ptr[1] = 0x06;
        data_ptr[2] = 0x03;
        data_ptr[3] = 0xC4;
        data_ptr[4] = 0xAF;
        data_ptr[5] = 0x87;

        if (FS_NO_ERROR == FS_Write(fDes, data_ptr, 6, NULL))
        {
            while (data_len > 0)
            {
                if (FS_NO_ERROR == FS_Read(fSrc, data_ptr, TMP_BUFFER_SIZE, &read_len))
                {
                    if (FS_NO_ERROR == FS_Write(fDes, data_ptr, read_len, NULL))
                        data_len -= read_len;
                    else
                        break;
                }
                else
                    break;
            }
        }

        OslMfree(data_ptr);
    }

    FS_Close(fSrc);

    FS_Close(fDes);

    FS_Delete(filepath);

    ptr = OslAllocDataPtr(dm_push_struct);

    mmi_ucs2cpy((S8*) (ptr->file_path), (const S8*)DM_PUSH_TEMP_FILE_NAME);

    ptr->type = DM_MSG_TYPE_NOTIFICATION;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_PUSH_IND, ptr);
}


/*****************************************************************************
 * FUNCTION
 *  dm_receive_upc_file
 * DESCRIPTION
 *  receive the update package file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void dm_receive_upc_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RECV_UPC_FILE);

}


/*****************************************************************************
 * FUNCTION
 *  dm_bootstrap_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void dm_bootstrap_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
#ifdef _DM_BOOTSTRAP_SUPPORT_
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 *data_ptr = NULL;

    kal_uint8 *header_ptr = NULL;

    kal_uint8 *temp_ptr = NULL;

    kal_int32 data_len = 0;

    kal_uint32 read_len = 0;

    FS_HANDLE fSrc, fDes;

    dm_push_struct *ptr = NULL;

    kal_int32 header_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_BOOTSTRAP_RECV_DA_FILE);

    if (action != MMI_DA_PUSH)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_BOOTSTRAP_RECV_DA_FILE_SIM2);
    }

    fSrc = FS_Open(filepath, FS_READ_ONLY);

    if (fSrc < 0)
    {
        return;
    }

    fDes = FS_Open(DM_PUSH_TEMP_FILE_NAME, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fDes < 0)
    {
        FS_Close(fSrc);

        FS_Delete(filepath);

        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fSrc, (kal_uint32*) & data_len))
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_BOOTSTRAP_RECV_DA_FILE_DATA_LEN, data_len);

        temp_ptr = (kal_uint8*) mmi_da_get_header(session_id, &header_len);

        if (temp_ptr && header_len > 0)
        {
            header_ptr = (kal_uint8*)OslMalloc(header_len + 1);

            memcpy(header_ptr, temp_ptr, header_len);

            header_ptr[header_len] = '\0';

            if (header_len > 2)
            {
                if (header_ptr[header_len - 2] == 0x0D && header_ptr[header_len - 1] == 0x0A)
                {
                    header_ptr[header_len - 2] = '\0';

                    header_len -= 2;
                }
            }

            header_len++;

            if (FS_NO_ERROR == FS_Write(fDes, &header_len, sizeof(kal_int32), NULL)
                && FS_NO_ERROR == FS_Write(fDes, header_ptr, header_len, NULL))
            {
                data_ptr = (kal_uint8*) OslMalloc(TMP_BUFFER_SIZE);

                while (data_len > 0)
                {
                    if (FS_NO_ERROR == FS_Read(fSrc, data_ptr, TMP_BUFFER_SIZE, &read_len))
                    {
                        if (FS_NO_ERROR == FS_Write(fDes, data_ptr, read_len, NULL))
                            data_len -= read_len;
                        else
                            break;
                    }
                    else
                        break;
                }

                OslMfree(data_ptr);
            }

            OslMfree(header_ptr);
        }
    }

    FS_Close(fSrc);

    FS_Close(fDes);

    FS_Delete(filepath);

    ptr = OslAllocDataPtr(dm_push_struct);

    mmi_ucs2cpy((S8*) (ptr->file_path), (const S8*)DM_PUSH_TEMP_FILE_NAME);

    ptr->type = DM_MSG_TYPE_BOOTSTRAP;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_PUSH_IND, ptr);

#else /* _DM_BOOTSTRAP_SUPPORT_ */ 

    FS_Delete(filepath);

#endif /* _DM_BOOTSTRAP_SUPPORT_ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_is_call
 * DESCRIPTION
 *  To determine if cellphone is in call
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if cellphone is in call; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_dmui_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_DM_3G
    return MMI_FALSE;
#else /* MMI_DM_3G */
    return srv_ucm_is_any_call();
#endif /* MMI_DM_3G */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_da_state_pause_ind_handle
 * DESCRIPTION
 *  function to receive state pause message from DM MMI
 * PARAMETERS
 *  msg     [IN]        Message point from DM MMI
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_da_state_pause_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dmui_da_report_struct *dmui_da_report_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DA_STATE_PAUSE_IND);
    dmui_da_report_ptr = (dmui_da_report_struct*)msg;

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);

#ifdef _DM_OMADL_VIA_DLAGENT_
    srv_da_stop_dl(dl_session_id);
    
    mmi_dmui_dl_report(DM_DOWNLOADING_USER_CANCEL);
#else
    dm_cancel_downloading();
#endif /*_DM_OMADL_VIA_DLAGENT_*/
    if (dmui_da_report_ptr->cause == SRV_DA_ERROR_DISK_FULL)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_FAILURE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_da_state_abort_ind_handle
 * DESCRIPTION
 *  function to receive state abort message from DM MMI
 * PARAMETERS
 *  msg     [IN]        Message point from DM MMI
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_da_state_abort_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dmui_da_report_struct *dmui_da_report_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DA_STATE_ABORT_IND);
    dmui_da_report_ptr = (dmui_da_report_struct*)msg;

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);

    mmi_dmui_dl_report(DM_DOWNLOADING_FAILED);

    srv_da_stop_dl(dl_session_id);

    if (dmui_da_report_ptr->cause == SRV_DA_ERROR_DISK_FULL)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_FAILURE));
    }
}


#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_da_state_complete_ind_handle
 * DESCRIPTION
 *  function to receive state complete message from DM MMI
 * PARAMETERS
 *  msg     [IN]        Message point from DM MMI
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_da_state_complete_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_DA_STATE_COMPLETE_IND);
    
    mmi_dmui_dl_report(DM_DOWNLOADED_UPDATE_PKG);

    srv_da_remove_dl(dl_session_id);

    /* waiting screen shown when download finish, sometimes it will add into history */
    /* if can't display update confirm screen, delete waiting screen right now, as it is not used after download  complete*/

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dmui_display_dl_progress_hdlr,
        NULL);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_display_popup
 * DESCRIPTION
 *  This function is provide a wrapper popup function with duration config by
 *  user.
 * PARAMETERS
 *  string     [IN]         popup message
 *  duration   [IN]         popup duration
 *  event_id   [IN]         popup event_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_display_popup(UI_string_type string, mmi_event_notify_enum event_id, U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        mmi_dmui_global_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL,
                        SCR_ID_DMUI_POPUP,
                        NULL,
                        NULL, 
                        MMI_FRM_FG_ONLY_SCRN))
    {
        ShowCategory65Screen(
            (U8*)string,
            mmi_get_event_based_image(event_id), 
            NULL);

        srv_prof_play_tone(SRV_PROF_TONE_REMIND, NULL);

        StartTimer(
            DMUI_POPUP_TIMER_ID,
            duration,
            mmi_dmui_display_popup_timeout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_display_popup_timeout
 * DESCRIPTION
 *  This function is the timeout callback function for mmi_dmui_display_popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_display_popup_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    StopTimer(DMUI_POPUP_TIMER_ID);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DMUI_POPUP)
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_ucm_callback_handler
 * DESCRIPTION
 *  function to handle the ucm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_ucm_callback_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dmui_network_state == DM_NETWORK_NOT_AVAILABLE)
    {
        return MMI_RET_OK;
    }

    /* AS the ucm callback shouldn't display a screen, so need to use primitive-based mechanism */
    if (srv_ucm_is_any_call() == MMI_TRUE)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UCM_IN_CALL);
        if (g_mmi_dmui_is_in_session == MMI_TRUE)
        {
            if (!IsMyTimerExist(DMUI_UCM_TIMER_ID) && is_network_timeout == MMI_FALSE)
            {
                /* Send notification */
                dm_notify_network_status_internal(MMI_FALSE);

                /* Set timer to check timeout */
                StartTimer(DMUI_UCM_TIMER_ID, 5*60*1000, mmi_dm_network_timer_callback);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_UCM_NOT_IN_CALL);
        if (g_mmi_dmui_is_in_session == MMI_TRUE)
        {
            dm_notify_network_status_internal(MMI_TRUE);
        }
        StopTimer(DMUI_UCM_TIMER_ID);

        /* Kill timer */
        if (is_network_timeout == MMI_TRUE)
        {
            is_network_timeout = MMI_FALSE;
        #ifdef __MMI_OP01_DM_PROFILE_SETTING__     
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

            if (g_mmi_dmui_is_in_session == MMI_TRUE)
            {
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_CANCEL_REQ, NULL);
            }
            mmi_frm_nmgr_cancel_deferred_scenario(
                MMI_SCENARIO_ID_DM,
                mmi_dmui_display_dl_progress_hdlr,
                NULL);
            mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
        }
    }
    return MMI_RET_OK;
}


void mmi_dmui_ucm_defer_to_notify_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr_dmui_context->ending_msg == MMI_DMUI_ENDING_MSG_TIMEOUT)
    {
        mmi_dmui_run_ending_msg();
        ptr_dmui_context->ending_msg = MMI_DMUI_ENDING_MSG_DEFAULT;
    }
}


MMI_BOOL mmi_dmui_defer_nmgr_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_nmgr_notify_info_struct *nmgr_info = (mmi_dmui_nmgr_notify_info_struct*)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(
        scen_id,
        nmgr_info->event_id,
        (WCHAR*)GetString(nmgr_info->str_id));
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_remove_non_del_screen
 * DESCRIPTION
 *  remove a DM screen and clear the del callback function
 * PARAMETERS
 *  group_id: [IN] group ID
 *  scr_id: [IN] screen ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_remove_non_del_screen(MMI_ID group_id, MMI_ID scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_is_present(group_id, scr_id, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(
            group_id,
            scr_id,
            NULL);

        if (GetExitScrnID() == scr_id)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_frm_scrn_close(group_id, scr_id);
        }
    }
}


void mmi_dmui_get_proxy_info(kal_uint32 data_account_id, dm_proxy_info_struct *proxy_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 decode_account_id;
    U32 actual_account_id;
    srv_dtcnt_prof_proxy_info_struct temp_proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id(data_account_id, NULL, NULL, NULL, &decode_account_id);
    if (CBM_DEFAULT_ACCT_ID == decode_account_id)
    {
        srv_dtcnt_get_auto_acc_id(data_account_id, &actual_account_id);
        g_current_data_account_id = 0;
    }
    else
    {
        actual_account_id = data_account_id;
        g_current_data_account_id = actual_account_id;
    }

    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        actual_account_id,
                        &temp_proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {            
        if (temp_proxy_info.use_proxy)
        {
            proxy_info->proxy_is_used = MMI_TRUE;
            
            sprintf(proxy_info->proxy_addr, "%d.%d.%d.%d", temp_proxy_info.px_addr[0], temp_proxy_info.px_addr[1], temp_proxy_info.px_addr[2], temp_proxy_info.px_addr[3]);
            
            proxy_info->proxy_port = (U32)temp_proxy_info.px_port;
        }
        else
        {
            proxy_info->proxy_is_used = MMI_FALSE;
        }
    }
    else
    {
        proxy_info->proxy_is_used = MMI_FALSE;
    }
}


void mmi_dmui_conn_with_dtcnt_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_data_account_id != 0)
    {
        mmi_dtcnt_subscribe_account(CBM_DEFAULT_ACCT_ID, g_current_data_account_id, STR_ID_DMUI_MAIN, GetRootTitleIcon(MENU_ID_DMUI_MAIN));        
    }
}

mmi_ret mmi_dmui_sim_unavailable_notify_hdlr(mmi_event_struct* para)
{
    mmi_frm_group_close(GRP_ID_DMAPP_SETTING);
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
    mmi_frm_group_close(GRP_ID_DMAPP_OTA);
    return MMI_RET_OK;
}


#ifdef __SIM_HOT_SWAP_SUPPORT__
mmi_ret mmi_dm_sim_ctrl_det_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *event = (srv_sim_ctrl_event_detected_evt_struct *)para;
    mmi_sim_enum reg_sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    reg_sim = MMI_SIM1;
#endif

    if (event->sim == reg_sim)
    {
        switch (event->type)
        {
            case SRV_SIM_CTRL_EVENT_DET_REMOVED:
            {
                mmi_frm_group_close(GRP_ID_DMAPP_SETTING);
                mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
                mmi_frm_group_close(GRP_ID_DMAPP_OTA);
                ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
                if (g_mmi_dmui_is_in_session == MMI_TRUE)
                {
                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_CANCEL_REQ, NULL);
                }
                break;
            }

            case SRV_SIM_CTRL_EVENT_DET_INSERTED:
            {
                break;
            }

            default:
                break;
        }
    }
    return MMI_RET_OK;
}
#endif /* __SIM_HOT_SWAP_SUPPORT__ */


#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

MMI_BOOL mmi_dmui_check_self_reg_sim_match(void)
{
#if defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DM_SELF_REGISTER_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        return MMI_TRUE;
    }
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_fte_main_menu_tap_callback
 * DESCRIPTION
 *  main screen tap callback funtion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_fte_main_menu_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {    
        if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[index].server_id) == 0)
        {
            mmi_dmui_entry_option_edit_pre();
        }
        else
        {
            mmi_dmui_entry_option_activate();
        }
    }
}
#endif /* __MMI_FTE_SUPPORT */


mmi_ret mmi_dmui_dtcnt_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_acct_delete_ind_evt_struct *dtcnt_del_info = (srv_dtcnt_acct_delete_ind_evt_struct*)evt;
    srv_dtcnt_acct_update_ind_evt_struct *dtcnt_update_info = (srv_dtcnt_acct_update_ind_evt_struct*)evt;

    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        {
            if (dtcnt_del_info->cause == 0)
            {
                for (i = 0; i < dtcnt_del_info->del_num; i++)
                {
                    U32 temp_account_id;
                    temp_account_id = cbm_encode_data_account_id(
                                        dtcnt_del_info->acc_id[i],
                                        (cbm_sim_id_enum)(dtcnt_del_info->sim_id[i] - 1),
                                        g_mmi_dmui_cbm_id,
                                        MMI_FALSE);
                    dm_update_account(temp_account_id, CBM_DEFAULT_ACCT_ID);
                }
            }
            break;
        }

        case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        {
            if (dtcnt_update_info->cause == 1) // provisioning replace
            {
                U32 temp_account_id;
                temp_account_id = cbm_encode_data_account_id(
                                    dtcnt_update_info->acc_id,
                                    (cbm_sim_id_enum)(dtcnt_update_info->sim_id_old - 1),
                                    g_mmi_dmui_cbm_id,
                                    MMI_FALSE);
                dm_update_account(temp_account_id, CBM_DEFAULT_ACCT_ID);
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_dmui_restore_factory_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dmui_is_doing_restore_factory = MMI_TRUE;
}


void mmi_dmui_set_ending_msg(mmi_dmui_ending_msg_enum ending_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SET_ENDING_MSG, ending_msg);
    if (session_uimode != DM_UI_MODE_BACKGROUND)
    {
        if (ptr_dmui_context->ending_msg != MMI_DMUI_ENDING_MSG_DEFAULT)
        {
            return;
        }
        else
        {
            ptr_dmui_context->ending_msg = ending_msg;
        }
    }
}


void mmi_dmui_run_ending_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_RUN_ENDING_MSG, ptr_dmui_context->ending_msg);
    switch (ptr_dmui_context->ending_msg)
    {
        case MMI_DMUI_ENDING_MSG_DEFAULT:
            break;

        case MMI_DMUI_ENDING_MSG_SESSION_FAIL:
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SESSION_FAIL_ADD_IN_HISTORY);
            dmui_prompt_message.message = get_string(STR_ID_DMUI_SESSION_FAILURE);
            dmui_prompt_message.event_id = MMI_EVENT_FAILURE;
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DM, MMI_EVENT_FAILURE, mmi_dmui_ps_status_entry_hdlr, (void*)&dmui_prompt_message);
            break;
        }

        case MMI_DMUI_ENDING_MSG_NO_MEM:
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_NOT_ENOUGH_MEM_ADD_IN_HISTORY);
            dmui_prompt_message.message = get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY);
            dmui_prompt_message.event_id = MMI_EVENT_FAILURE;
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DM, MMI_EVENT_FAILURE, mmi_dmui_ps_status_entry_hdlr, (void*)&dmui_prompt_message);
            break;
        }

        case MMI_DMUI_ENDING_MSG_TIMEOUT:
        {
            mmi_dmui_nmgr_notify_info_struct nmgr_info;

            nmgr_info.event_id = MMI_EVENT_FAILURE;
            nmgr_info.str_id = STR_ID_DMUI_TIMEOUT_POPUP;
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                mmi_dmui_defer_nmgr_entry_hdlr,
                &nmgr_info);
            break;
        }

        default:
            break;
    }
}


MMI_BOOL mmi_dmui_popup_ps_rsp_result(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
    if (mmi_frm_group_is_present(GRP_ID_DMAPP_SETTING) == MMI_TRUE)
    {
        mmi_frm_nmgr_popup(scenario_id, type, string);
    }
}


#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_register_notify
 * DESCRIPTION
 *  app register the LAWMO callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_result_enum mmi_dmui_lawmo_register_notify(
                        mmi_dmui_app_id_enum app_id,
                        mmi_dmui_mo_type_enum mo_type,
                        mmi_dmui_lawmo_cb lawmo_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_dmui_mo_cntx_ptr->max_reg_app < MMI_DMUI_APP_ID_TOTAL * 2);
    if (lawmo_callback == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REG_NOTIFY_EMPTY_CB, app_id, mo_type);
        return MMI_DMUI_RESULT_FAILURE;
    }

    if (app_id == MMI_DMUI_APP_ID_IDLE && mo_type == MMI_DMUI_MO_TYPE_LAWMO_LOCK)
    {
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE].app_id = app_id;
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE].mo_type = mo_type;
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE].callback = (void*)lawmo_callback;
    }
    else if (app_id == MMI_DMUI_APP_ID_FMGR && mo_type == MMI_DMUI_MO_TYPE_LAWMO_WIPE)
    {
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR].app_id = app_id;
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR].mo_type = mo_type;
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR].callback = (void*)lawmo_callback;
    }
    else
    {
        for (i = 0; i < g_mmi_dmui_mo_cntx_ptr->max_reg_app; i++)
        {
            if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].app_id == app_id &&
                g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].mo_type == mo_type)
            {
                if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].callback == (void*)lawmo_callback)
                     
                {         
                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REG_NOTIFY_EXISY_CB, app_id, mo_type);
                    return MMI_DMUI_RESULT_SUCCESS;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REG_NOTIFY_REPLACE_CB, app_id, mo_type);
                    g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].callback = (void*)lawmo_callback;
                    return MMI_DMUI_RESULT_SUCCESS;
                }
            }
        }

        g_mmi_dmui_mo_cntx_ptr->mo_reg_info[g_mmi_dmui_mo_cntx_ptr->max_reg_app].app_id = app_id;
        g_mmi_dmui_mo_cntx_ptr->mo_reg_info[g_mmi_dmui_mo_cntx_ptr->max_reg_app].mo_type = mo_type;
        g_mmi_dmui_mo_cntx_ptr->mo_reg_info[g_mmi_dmui_mo_cntx_ptr->max_reg_app].callback = (void*)lawmo_callback;
        g_mmi_dmui_mo_cntx_ptr->mo_reg_info[g_mmi_dmui_mo_cntx_ptr->max_reg_app].status = -1;
        g_mmi_dmui_mo_cntx_ptr->max_reg_app++;
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REG_NOTIFY_SUCCESS, app_id, mo_type);
    return MMI_DMUI_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_req_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_LAWMO_REQ_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_req_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_lawmo_operation_struct *lawmo_cmd_ptr;
    static MMI_BOOL is_holding_msg = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REQ_IND_HDLR);
    if (g_dmui_is_doing_restore_factory == MMI_TRUE)
    {
        return;
    }

    if (msg)
    {
        lawmo_cmd_ptr = (dm_lawmo_operation_struct*)msg;
        /* handle flight mode issue(MAUI_01918979) */
        if (lawmo_cmd_ptr->command == DM_LAWMO_CMD_PRE_LOCK)
        {
            return;
        }

        if (MMI_TRUE == srv_mode_switch_is_switching())
        {
            if (is_holding_msg == MMI_FALSE)
            {
                hold_local_para((local_para_struct*)msg);
                is_holding_msg = MMI_TRUE;
            }
            StartTimerEx(
                DMUI_LAWMO_TRY_SWITCH_MODE_TIMER_ID,
                5000,
                mmi_dmui_lawmo_req_ind_hdlr,
                msg);
            return;
        }
        else
        {
            if (is_holding_msg == MMI_TRUE)
            {
                free_local_para((local_para_struct*)msg);
            }
            is_holding_msg = MMI_FALSE;
        }

        g_mmi_dmui_mo_cntx_ptr->mo_cmd = mmi_dmui_get_lawmo_cmd((U32)lawmo_cmd_ptr->command);
        g_mmi_dmui_mo_cntx_ptr->is_server_cmd = MMI_TRUE;

        switch(g_mmi_dmui_mo_cntx_ptr->mo_cmd)
        {
            case MMI_DMUI_CMD_LAWMO_FULLYLOCK:
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            {
                if (g_mmi_dmui_is_phone_lawmo_locked == 1)
                {
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_SUCESS);
                    return;
                }
                break;
            }
            
            case MMI_DMUI_CMD_LAWMO_UNLOCK:
            {
                if (g_mmi_dmui_is_phone_lawmo_locked == 0)
                {
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_SUCESS);
                    return;
                }
                break;
            }

            default:
                break;
        }
    }
    
    g_mmi_dmui_mo_cntx_ptr->mo_type = mmi_dmui_get_mo_type(g_mmi_dmui_mo_cntx_ptr->mo_cmd);
    g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = g_mmi_dmui_mo_cntx_ptr->mo_cmd;
    g_mmi_dmui_mo_cntx_ptr->is_cmd_success = MMI_TRUE;
    mmi_dmui_change_status_on_command();

    if (g_mmi_dmui_mo_cntx_ptr->mo_cmd == MMI_DMUI_CMD_LAWMO_WIPE)
    {
        if (g_mmi_dmui_is_phone_lawmo_locked == 0)
        {
            g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
        }
        else
        {
            mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR);
            return;
        }
    }

    if (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_FULLYLOCK)
    {
        srv_cbm_disallow_nwk_srv(
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_EDGE | SRV_CBM_BEARER_UMTS | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            g_mmi_dmui_cbm_id);
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_block();
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
    mmi_dmui_lawmo_cmd_sender();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_cmd_sender
 * DESCRIPTION
 *  function to call the app callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_cmd_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_no_callback = MMI_TRUE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_CMD_SENDER);
    g_mmi_dmui_mo_cntx_ptr->curr_mo_type = mmi_dmui_get_mo_type(g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);
    /* reset the report mark */
    for (i = 0; i < g_mmi_dmui_mo_cntx_ptr->max_reg_app; i++)
    {
        if ((g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK &&
             g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].status == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK) ||
            (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_UNLOCK &&
             g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].status != MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK))
        {
            g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_NEED_NOT_REPORT;
        }
        else if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].mo_type == g_mmi_dmui_mo_cntx_ptr->curr_mo_type)
        {
            g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_NOT_REPORT;
            is_no_callback = MMI_FALSE;
        }
        else
        {
            g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_NEED_NOT_REPORT;
        }
    }

    g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success = MMI_TRUE;

    /* if no callback, report directly */
    if (is_no_callback == MMI_TRUE)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REQ_IND_HDLR_NO_CB);
        mmi_dmui_lawmo_report(-1, g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd, MMI_DMUI_RESULT_SUCCESS);
        return;
    }

    is_no_callback = MMI_TRUE;

    /* start to send the command */
    for (i = 0; i < g_mmi_dmui_mo_cntx_ptr->max_reg_app; i++)
    {
        if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].mo_type == g_mmi_dmui_mo_cntx_ptr->curr_mo_type &&
            g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark == MMI_DMUI_REPORT_MARK_NOT_REPORT)
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_CMD_SENDER_INFO, g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].app_id, g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);
            (*(mmi_dmui_lawmo_cb)g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].callback)(
                                                            g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].app_id,
                                                            g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_special_app_cmd_sender
 * DESCRIPTION
 *  function to call the special app callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_special_app_cmd_sender(mmi_dmui_mo_special_app_enum spe_app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_CMD_SPE_APP_SENDER_INFO, g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[spe_app_index].app_id, g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);
    g_mmi_dmui_mo_cntx_ptr->curr_mo_type = mmi_dmui_get_mo_type(g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);
    for (i = 0; i < MMI_DMUI_MO_SPECIAL_APP_TOTAL; i++)
    {
        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_NEED_NOT_REPORT;

    }
    g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success = MMI_TRUE;
    g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[spe_app_index].report_mark = MMI_DMUI_REPORT_MARK_NOT_REPORT;
    (*(mmi_dmui_lawmo_cb)g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[spe_app_index].callback)(
                                                                                        g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[spe_app_index].app_id,
                                                                                        g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_report
 * DESCRIPTION
 *  function for app to report the LAWMO result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    S16 error;
    MMI_BOOL is_special_app = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REPORT_INFO, app_id, cmd, result);

    if (cmd != g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd)
    {
        return;
    }

    for (i = 0; i < MMI_DMUI_MO_SPECIAL_APP_TOTAL; i++)
    {
        if (g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[i].app_id == app_id &&
            g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[i].report_mark == MMI_DMUI_REPORT_MARK_NOT_REPORT)
        {
            is_special_app = MMI_TRUE;
            g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_REPORT;
            if (result != MMI_DMUI_RESULT_SUCCESS)
            {
                g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success = MMI_FALSE;
            }
            break;
        }
    }

    if (is_special_app == MMI_FALSE)
    {
        for (i = 0; i < g_mmi_dmui_mo_cntx_ptr->max_reg_app; i++)
        {
            if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].app_id == app_id &&
                g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark == MMI_DMUI_REPORT_MARK_NOT_REPORT)
            {
                if (result != MMI_DMUI_RESULT_SUCCESS)
                {
                    g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success = MMI_FALSE;
                }
                else if (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK)
                {
                    g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].status = MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK;
                }
                else if (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_UNLOCK)
                {
                    g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].status = MMI_DMUI_STATUS_IDLE;
                }

                g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark = MMI_DMUI_REPORT_MARK_REPORT;
                break;
            }
        }

        /* check all complete */
        for (i = 0; i < g_mmi_dmui_mo_cntx_ptr->max_reg_app; i++)
        {
            if (g_mmi_dmui_mo_cntx_ptr->mo_reg_info[i].report_mark == MMI_DMUI_REPORT_MARK_NOT_REPORT)
            {
                return;
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_REPORT_COMPLETE);
    /* all app complete */
    switch (g_mmi_dmui_mo_cntx_ptr->mo_cmd)
    {
        case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
        {
            if (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK)
            {
                if (app_id == MMI_DMUI_APP_ID_IDLE)
                {
                #ifdef __MMI_TOUCH_SCREEN__
                    mmi_pen_unblock();
                #endif /* __MMI_TOUCH_SCREEN__ */
                    mmi_dmui_change_status_after_command();
                    mmi_dmui_lawmo_cmd_finish();
                }
                else
                {
                    if (g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success)
                    {
                        nvram_ef_dm_app_lawmo_info_struct lawmo_info;
                        g_mmi_dmui_is_phone_lawmo_locked = 1;
                        lawmo_info.is_locked = MMI_TRUE;
                        WriteValue(
                            NVRAM_DM_LOCK_STATUS,
                            &g_mmi_dmui_is_phone_lawmo_locked,
                            DS_BYTE,
                            &error);
                        WriteRecord(
                            NVRAM_EF_DM_APP_LAWMO_INFO_LID,
                            1,
                            &lawmo_info,
                            sizeof(nvram_ef_dm_app_lawmo_info_struct),
                            &error);
                        mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE);
                    }
                    else
                    {
                        g_mmi_dmui_mo_cntx_ptr->is_cmd_success = MMI_FALSE;
                        g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
                        mmi_dmui_lawmo_cmd_sender();
                    }
                }
            }
            else if (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd == MMI_DMUI_CMD_LAWMO_UNLOCK)
            {
                mmi_dmui_lawmo_cmd_finish();
            }
            break;
        }
 
        case MMI_DMUI_CMD_LAWMO_UNLOCK:
        {
            if (app_id == MMI_DMUI_APP_ID_IDLE)
            {
                mmi_dmui_lawmo_cmd_finish();
            }
            else
            {
                /* must success */
                nvram_ef_dm_app_lawmo_info_struct lawmo_info;
                g_mmi_dmui_is_phone_lawmo_locked = 0;
                WriteValue(
                    NVRAM_DM_LOCK_STATUS,
                    &g_mmi_dmui_is_phone_lawmo_locked,
                    DS_BYTE,
                    &error);

                lawmo_info.is_locked = MMI_FALSE;
                WriteRecord(
                    NVRAM_EF_DM_APP_LAWMO_INFO_LID,
                    1,
                    &lawmo_info,
                    sizeof(nvram_ef_dm_app_lawmo_info_struct),
                    &error);
                /* change the status */
                mmi_dmui_change_status_after_command();
                g_mmi_dmui_mo_cntx_ptr->is_cmd_success = g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success;
                mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE);
            }
            break;
        }
        
        case MMI_DMUI_CMD_LAWMO_WIPE:
        {
            switch (g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd)
            {
                case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                {
                    if (app_id == MMI_DMUI_APP_ID_IDLE)
                    {
                    #ifdef __MMI_TOUCH_SCREEN__
                        mmi_pen_unblock();
                    #endif /* __MMI_TOUCH_SCREEN__ */
                        g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = MMI_DMUI_CMD_LAWMO_WIPE;
                        g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK;
                        mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR);
                    }
                    else
                    {
                        mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE);
                    }
                    break;
                }

                case MMI_DMUI_CMD_LAWMO_UNLOCK:
                {
                    if (app_id == MMI_DMUI_APP_ID_IDLE)
                    {
                        mmi_dmui_lawmo_cmd_finish();
                    }
                    else
                    {
                        mmi_dmui_change_status_after_command();
                        mmi_dmui_lawmo_special_app_cmd_sender(MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE);
                    }
                    break;
                }

                case MMI_DMUI_CMD_LAWMO_WIPE:
                {
                    if (app_id == MMI_DMUI_APP_ID_FMGR)
                    {
                        if (g_mmi_dmui_mo_cntx_ptr->is_curr_cmd_success)
                        {
                            mmi_dmui_lawmo_cmd_sender();
                        }
                        else
                        {
                            if (g_mmi_dmui_is_phone_lawmo_locked)
                            {
                                mmi_dmui_lawmo_cmd_finish();
                            }
                            else
                            {
                                g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
                                mmi_dmui_lawmo_cmd_sender();
                            }
                        }
                    }
                    else
                    {
                        if (g_mmi_dmui_is_phone_lawmo_locked)
                        {
                            mmi_dmui_lawmo_cmd_finish();
                        }
                        else
                        {
                            g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
                            mmi_dmui_lawmo_cmd_sender();
                        }
                    }
                    break;
                }
            }
            break;
        }

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_cmd_finish
 * DESCRIPTION
 *  function to handle the operation after all app reported
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_cmd_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_LAWMO_CMD_FINISH);

    /* All app reported */
    if (g_mmi_dmui_mo_cntx_ptr->is_server_cmd == MMI_TRUE)
    {
        if (g_mmi_dmui_mo_cntx_ptr->is_cmd_success)
        {
            switch (g_mmi_dmui_mo_cntx_ptr->mo_cmd)
            {
                case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                {
                    // only do this at the first lock time
                    mmi_dmui_switch_nw_mode();
                    break;
                }

                case MMI_DMUI_CMD_LAWMO_WIPE:
                case MMI_DMUI_CMD_LAWMO_UNLOCK:
                    srv_cbm_allow_nwk_srv(
                        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_EDGE | SRV_CBM_BEARER_UMTS | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
                        g_mmi_dmui_cbm_id);
                    break;

                default:
                    break;
            }
            mmi_dmui_send_lawmo_req_ind(DM_LAWMO_SUCESS);
        }
        else
        {
            switch (g_mmi_dmui_mo_cntx_ptr->mo_cmd)
            {
                case MMI_DMUI_CMD_LAWMO_WIPE:
                #ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
                #else
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_CLIENT_ERR);
                #endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
                    break;

                case MMI_DMUI_CMD_LAWMO_FULLYLOCK:
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_FULLLOCK_FAIL);
                    break;

                case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_PARTLOCK_FAIL);
                    break;

                case MMI_DMUI_CMD_LAWMO_UNLOCK:
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_UNLOCK_FAIL);
                    break;

                default:
                    mmi_dmui_send_lawmo_req_ind(DM_LAWMO_CLIENT_ERR);
                    break;
            }
        }
        g_mmi_dmui_mo_cntx_ptr->is_server_cmd = MMI_FALSE;
    }

    /* reset the command */
    mmi_dmui_change_status_after_command();
    g_mmi_dmui_mo_cntx_ptr->mo_cmd = -1;
    g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_send_lawmo_cmd_req
 * DESCRIPTION
 *  function to send the lawmo cmd message, also as the callback function to register the lawmo command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_send_lawmo_cmd_req(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_dmui_lawmo_cmd_ind_struct *lawmo_cmd_ind_struct_ptr;
    rmmi_lock_at_cmd_req_struct *lawmo_cmd_ind_struct_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lawmo_cmd_ind_struct_ptr = OslAllocDataPtr(rmmi_lock_at_cmd_req_struct);
    //lawmo_cmd_ind_struct_ptr->command = cmd;
    //lawmo_cmd_ind_struct_ptr->app_id = app_id;
    if (cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK)
    {
        lawmo_cmd_ind_struct_ptr->lock = KAL_TRUE;
    }
    else if (cmd == MMI_DMUI_CMD_LAWMO_UNLOCK)
    {
        lawmo_cmd_ind_struct_ptr->lock = KAL_FALSE;
    }

    
    DMUI_SEND_MSG_TO_OTHER_MOD(MOD_ATCI, MSG_ID_RMMI_LOCK_AT_CMD_REQ, lawmo_cmd_ind_struct_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_cmd_rsp_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_LAWMO_CMD_RES
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_cmd_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_dmui_lawmo_cmd_rsp_struct *lawmo_cmd_rsp_struct_ptr;
    rmmi_lock_at_cmd_cnf_struct *lawmo_cmd_rsp_struct_ptr;
    mmi_dmui_result_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lawmo_cmd_rsp_struct_ptr = (rmmi_lock_at_cmd_cnf_struct*)msg;
    
    if (lawmo_cmd_rsp_struct_ptr->result)
    {
        result = MMI_DMUI_RESULT_SUCCESS;
    }
    else
    {
        result = MMI_DMUI_RESULT_FAILURE;
    }    
    
    mmi_dmui_lawmo_report(
        MMI_DMUI_APP_ID_ATCI,
        g_mmi_dmui_mo_cntx_ptr->curr_mo_cmd,
        result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_send_lawmo_cmd_req
 * DESCRIPTION
 *  function to send the lawmo cmd message, also as the callback function to register the lawmo command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_send_lawmo_req_ind(dm_lawmo_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_lawmo_result_struct *lawmo_cmd_rsp_struct_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lawmo_cmd_rsp_struct_ptr = OslAllocDataPtr(dm_lawmo_result_struct);
    lawmo_cmd_rsp_struct_ptr->result = result;
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LAWMO_RSP, lawmo_cmd_rsp_struct_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_lawmo_cmd
 * DESCRIPTION
 *  function to change the command from DM to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_cmd_enum mmi_dmui_get_lawmo_cmd(dm_lawmo_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_cmd_enum mo_cmd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd)
    {
        case DM_LAWMO_CMD_FULL_LOCK:
            mo_cmd = MMI_DMUI_CMD_LAWMO_FULLYLOCK;
            break;

        case DM_LAWMO_CMD_PART_LOCK:
            mo_cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
            break;

        case DM_LAWMO_CMD_UNLOCK:
            mo_cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
            break;

        case DM_LAWMO_CMD_FATORY_RESET:
        #ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
        #else
            mo_cmd = MMI_DMUI_CMD_LAWMO_FACTORYRESET;
        #endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
            break;
            
        default:
            MMI_ASSERT(0);
    }
    
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_MO_GET_MO_CMD, mo_cmd);
    return mo_cmd;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_is_phone_lock
 * DESCRIPTION
 *  function to check is the phone locked
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:   phone locked
 *  FALSE:  phone unlocked
 *****************************************************************************/
kal_int8 mmi_dmui_is_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
        g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


mmi_ret mmi_dmui_lawmo_pre_key_routing_cb(mmi_event_struct *evt)
{
    if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING &&
        srv_ucm_is_any_call() == MMI_FALSE)
    {
        return MMI_RET_STOP_KEY_HANDLE;
    }
    else
    {
        return MMI_RET_OK;
    }
}


void mmi_dmui_switch_nw_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        mode =  srv_bootup_sim_is_inserted(MMI_SIM1)
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
    #endif
    #endif
    #endif
        ;
        if (MMI_TRUE == srv_mode_switch_switch_rf_mode(
                            (mode == 0) ? SRV_MODE_SWITCH_SIM1 : mode,
                            mmi_dmui_switch_nw_mode_cb,
                            NULL))
        {
            /* redraw status icon */
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif
            return;
        }
    }
}


mmi_ret mmi_dmui_switch_nw_mode_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH)
	{    
        if (((srv_mode_switch_rsp_event_struct*)evt)->result == 0) // switch failed
        {
            mmi_dmui_switch_nw_mode();
        }
    }
    return MMI_RET_OK;
}

#endif /* __DM_LAWMO_SUPPORT__ */


#ifdef __DM_SCOMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_install_by_srv_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_install_by_srv_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct nvram_dm_app_scomo_report_info;
    mmi_dmui_scomo_dm_cmd_info_struct        scomo_dm_cmd_info;
    dm_scomo_install_by_server_ind_struct   *install_by_srv_ind_struct_ptr;
    dm_scomo_install_by_server_cnf_struct   *install_by_srv_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dmui_is_doing_restore_factory == MMI_TRUE)
    {
        return;
    }

    g_mmi_dmui_mo_cntx_ptr->is_cmd_success = MMI_TRUE;
    ReadRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &nvram_dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);

    if (nvram_dm_app_scomo_report_info.is_info_valid)
    {
        install_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
        memcpy(install_by_srv_cnf_struct_ptr->id,        nvram_dm_app_scomo_report_info.dm_software_id,     DM_SCOMO_MAX_ID);
        memcpy(install_by_srv_cnf_struct_ptr->gen_id,    nvram_dm_app_scomo_report_info.app_software_id,    DM_SCOMO_MAX_ID);
        memcpy(install_by_srv_cnf_struct_ptr->name,      nvram_dm_app_scomo_report_info.software_name,      DM_SCOMO_MAX_NAME * 2);
        memcpy(install_by_srv_cnf_struct_ptr->version,   nvram_dm_app_scomo_report_info.software_version,   DM_SCOMO_MAX_NAME);
        install_by_srv_cnf_struct_ptr->result = nvram_dm_app_scomo_report_info.result;
        DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF, install_by_srv_cnf_struct_ptr);
    }
    else
    {
        install_by_srv_ind_struct_ptr = (dm_scomo_install_by_server_ind_struct*)msg;
        g_mmi_dmui_mo_cntx_ptr->mo_cmd = mmi_dmui_get_scomo_cmd(install_by_srv_ind_struct_ptr->command);
        g_mmi_dmui_mo_cntx_ptr->mo_type = mmi_dmui_get_mo_type(g_mmi_dmui_mo_cntx_ptr->mo_cmd);
        mmi_dmui_change_status_on_command();
        memcpy(scomo_dm_cmd_info.dm_software_id,    install_by_srv_ind_struct_ptr->id,          DM_SCOMO_MAX_ID);
        memset(scomo_dm_cmd_info.app_software_id,   0,                                          DM_SCOMO_MAX_ID);
        memcpy(scomo_dm_cmd_info.pkg_install_path,  install_by_srv_ind_struct_ptr->file_name,   DM_SCOMO_MAX_FILE_NAME * 2);
        memcpy(scomo_dm_cmd_info.pkg_network_url,   install_by_srv_ind_struct_ptr->install_url, DM_SCOMO_MAX_URL);
        if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK ||
            g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback == NULL)
        {
            /* When locked, reject SCOMO command */
            install_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
            memcpy(install_by_srv_cnf_struct_ptr->id, install_by_srv_ind_struct_ptr->id, DM_SCOMO_MAX_ID);
            if (g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback == NULL)
            {
                install_by_srv_cnf_struct_ptr->result = DM_SCOMO_CLIENT_ERROR;
            }
            else
            {
                install_by_srv_cnf_struct_ptr->result = DM_SCOMO_OPERATION_REJECT;
            }

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF, install_by_srv_cnf_struct_ptr);
            return;
        }
        else if (install_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_NOTSPECIFIED ||
                 install_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_USERINTERACTION)
        {
            scomo_dm_cmd_info.display_mode = MMI_DMUI_APP_DISPLAY_MODE_CONFIRM;
        }
        else
        {
            scomo_dm_cmd_info.display_mode = MMI_DMUI_APP_DISPLAY_MODE_BACKGROUND;
        }

        (*(mmi_dmui_scomo_cb)g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback)(
            MMI_DMUI_APP_ID_JAVA,
            g_mmi_dmui_mo_cntx_ptr->mo_cmd,
            &scomo_dm_cmd_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_remove_by_srv_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_remove_by_srv_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct    nvram_dm_app_scomo_report_info;
    mmi_dmui_scomo_dm_cmd_info_struct           scomo_dm_cmd_info;
    dm_scomo_remove_by_server_ind_struct        *remove_by_srv_ind_struct_ptr;
    dm_scomo_remove_by_server_cnf_struct        *remove_by_srv_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dmui_is_doing_restore_factory == MMI_TRUE)
    {
        return;
    }
    g_mmi_dmui_mo_cntx_ptr->is_cmd_success = MMI_TRUE;
    ReadRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &nvram_dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);

    if (nvram_dm_app_scomo_report_info.is_info_valid)
    {
        remove_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
        memcpy(remove_by_srv_cnf_struct_ptr->gen_id,    nvram_dm_app_scomo_report_info.app_software_id,    DM_SCOMO_MAX_ID);
        remove_by_srv_cnf_struct_ptr->result = nvram_dm_app_scomo_report_info.result;
        DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF, remove_by_srv_cnf_struct_ptr);
    }
    else
    {
        remove_by_srv_ind_struct_ptr = (dm_scomo_remove_by_server_ind_struct*)msg;
        g_mmi_dmui_mo_cntx_ptr->mo_cmd = mmi_dmui_get_scomo_cmd(remove_by_srv_ind_struct_ptr->command);
        g_mmi_dmui_mo_cntx_ptr->mo_type = mmi_dmui_get_mo_type(g_mmi_dmui_mo_cntx_ptr->mo_cmd);
        mmi_dmui_change_status_on_command();
        memset(scomo_dm_cmd_info.dm_software_id,    0,                                      DM_SCOMO_MAX_ID);
        memcpy(scomo_dm_cmd_info.app_software_id,   remove_by_srv_ind_struct_ptr->gen_id,   DM_SCOMO_MAX_ID);
        memset(scomo_dm_cmd_info.pkg_install_path,  0,                                      DM_SCOMO_MAX_FILE_NAME * 2);
        memset(scomo_dm_cmd_info.pkg_network_url,   0,                                      DM_SCOMO_MAX_URL);

        if (g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback == NULL)
        {
            remove_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
            remove_by_srv_cnf_struct_ptr->result = DM_SCOMO_CLIENT_ERROR;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF, remove_by_srv_cnf_struct_ptr);
            return;
        }
        else if (g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK ||
                 g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
        {
            scomo_dm_cmd_info.display_mode = MMI_DMUI_APP_DISPLAY_MODE_BACKGROUND;
        }
        else if (remove_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_NOTSPECIFIED ||
            remove_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_USERINTERACTION)
        {
            scomo_dm_cmd_info.display_mode = MMI_DMUI_APP_DISPLAY_MODE_CONFIRM;
        }
        else
        {
            scomo_dm_cmd_info.display_mode = MMI_DMUI_APP_DISPLAY_MODE_BACKGROUND;
        }

        (*(mmi_dmui_scomo_cb)g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback)(
            MMI_DMUI_APP_ID_JAVA,
            g_mmi_dmui_mo_cntx_ptr->mo_cmd,
            &scomo_dm_cmd_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_install_by_user_rsp_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_INSTALL_BY_USER_RSP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_install_by_user_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_FALSE;
    mmi_dmui_scomo_handle_unfinished_report();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_remove_by_user_rsp_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_REMOVE_BY_USER_RSP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_remove_by_user_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_FALSE;
    mmi_dmui_scomo_handle_unfinished_report();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_register_notify
 * DESCRIPTION
 *  app register the SCOMO callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_result_enum mmi_dmui_scomo_register_notify(
                        mmi_dmui_app_id_enum app_id,
                        mmi_dmui_mo_type_enum mo_type,
                        mmi_dmui_scomo_cb scomo_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(scomo_callback);
    g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].app_id = app_id;
    g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].mo_type = mo_type;
    g_mmi_dmui_mo_cntx_ptr->mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA].callback = (void*)scomo_callback;;

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SCOMO_REG_NOTIFY_SUCCESS, g_mmi_dmui_mo_cntx_ptr->mo_cmd, mo_type);
    return MMI_DMUI_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_report
 * DESCRIPTION
 *  function for app to report the SCOMO result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result,
        mmi_dmui_scomo_app_report_info_struct *scomo_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct    *dm_app_scomo_report_info;
    dm_scomo_install_by_server_cnf_struct       *install_by_server_cnf_struct_ptr;
    dm_scomo_remove_by_server_cnf_struct        *remove_by_server_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SCOMO_REPORT_INFO, app_id, cmd, result);

    if (*scomo_info->dm_software_id != 0) /* dm server command */
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SCOMO_REPORT_SERVER_CMD);

        /* send message */
        dm_app_scomo_report_info = (nvram_ef_dm_app_scomo_report_info_struct*)OslMalloc(sizeof(nvram_ef_dm_app_scomo_report_info_struct));
        dm_app_scomo_report_info->is_info_valid = 1;
        dm_app_scomo_report_info->app_id = app_id;
        dm_app_scomo_report_info->command = cmd;
        dm_app_scomo_report_info->result = result;
        memcpy(dm_app_scomo_report_info->dm_software_id,    scomo_info->dm_software_id,     DM_MAX_ID_LEN);
        memcpy(dm_app_scomo_report_info->app_software_id,   scomo_info->app_software_id,    DM_MAX_ID_LEN);
        memcpy(dm_app_scomo_report_info->software_name,     scomo_info->software_name,      DM_MAX_NAME_LEN * 2);
        memcpy(dm_app_scomo_report_info->software_version,  scomo_info->software_version,   DM_MAX_NAME_LEN);
        if (cmd == MMI_DMUI_CMD_SCOMO_INSTALL || cmd == MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE)
        {
            install_by_server_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
            memcpy(install_by_server_cnf_struct_ptr->id,        scomo_info->dm_software_id,     DM_SCOMO_MAX_ID);
            memcpy(install_by_server_cnf_struct_ptr->gen_id,    scomo_info->app_software_id,    DM_SCOMO_MAX_ID);
            memcpy(install_by_server_cnf_struct_ptr->name,      scomo_info->software_name,      DM_SCOMO_MAX_NAME * 2);
            memcpy(install_by_server_cnf_struct_ptr->version,   scomo_info->software_version,   DM_SCOMO_MAX_NAME);
            install_by_server_cnf_struct_ptr->result = (dm_scomo_error_code_enum)mmi_dmui_mo_switch_error_code(result);
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF, install_by_server_cnf_struct_ptr);
        }
        else if (cmd == MMI_DMUI_CMD_SCOMO_REMOVE)
        {
            remove_by_server_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
            memcpy(remove_by_server_cnf_struct_ptr->gen_id,    scomo_info->app_software_id,    DM_SCOMO_MAX_ID);
            remove_by_server_cnf_struct_ptr->result = (dm_scomo_error_code_enum)mmi_dmui_mo_switch_error_code(result);
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF, remove_by_server_cnf_struct_ptr);            
        }

        WriteRecord(
            NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
            1,
            dm_app_scomo_report_info,
            sizeof(nvram_ef_dm_app_scomo_report_info_struct),
            &error);
        OslMfree(dm_app_scomo_report_info);

        mmi_dmui_change_status_after_command();
        g_mmi_dmui_mo_cntx_ptr->mo_cmd = -1;
    }
    else /* user operation */
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SCOMO_REPORT_APP_CMD);
        mmi_dmui_scomo_app_operate_notify(
            app_id,
            cmd,
            scomo_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_app_operate_notify
 * DESCRIPTION
 *  function for app to notiry the operation by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_app_operate_notify(
                mmi_dmui_app_id_enum app_id,
                mmi_dmui_cmd_enum cmd,
                mmi_dmui_scomo_app_report_info_struct *scomo_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_scomo_app_report_save_file_info_struct *app_cmd_save_file_info;
    FS_HANDLE fh_scomo_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh_scomo_info = FS_Open(DM_SCOMO_APP_CMD_INFO_FILE_NAME, FS_READ_WRITE | FS_CREATE);
    if (fh_scomo_info < 0)
    {
        FS_Delete(DM_SCOMO_APP_CMD_INFO_FILE_NAME);
        return;
    }

    FS_Seek(fh_scomo_info, 0, FS_FILE_END);

    app_cmd_save_file_info = (mmi_dmui_scomo_app_report_save_file_info_struct*)OslMalloc(sizeof(mmi_dmui_scomo_app_report_save_file_info_struct));
    memcpy(
        &app_cmd_save_file_info->app_cmd_info,
        scomo_info,
        sizeof(mmi_dmui_scomo_app_report_info_struct));
    app_cmd_save_file_info->app_id = app_id;
    app_cmd_save_file_info->cmd = cmd;
    
    FS_Write(
        fh_scomo_info,
        app_cmd_save_file_info,
        sizeof(mmi_dmui_scomo_app_report_save_file_info_struct),
        NULL);
    FS_Close(fh_scomo_info);
    OslMfree(app_cmd_save_file_info);

    if (g_dmui_scomo_waiting_ps_rsp_operate_by_user == MMI_FALSE)
    {
        mmi_dmui_scomo_handle_unfinished_report();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_scomo_handle_unfinished_report
 * DESCRIPTION
 *  function to handle report to DM PS that unfinished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_scomo_handle_unfinished_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_scomo_app_report_save_file_info_struct *app_cmd_save_file_info;
    dm_scomo_install_by_user_req_struct       *install_by_user_req_struct_ptr;
    dm_scomo_remove_by_user_req_struct        *remove_by_user_req_struct_ptr;
    U32 file_len;
    static U32 fs_read_index = 0;
    U32 fs_read_len;
    FS_HANDLE fh_scomo_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_SCOMO_HANDLE_UNFINISHED_REPORT);
    fh_scomo_info = FS_Open(DM_SCOMO_APP_CMD_INFO_FILE_NAME, FS_READ_ONLY);

    if (fh_scomo_info < 0)
    {
        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fh_scomo_info, &file_len))
    {
        if (file_len > 0)
        {
            /* read the file and send msg to DM PS */
            FS_Seek(
                fh_scomo_info,
                fs_read_index * sizeof(mmi_dmui_scomo_app_report_save_file_info_struct),
                FS_FILE_BEGIN);
            fs_read_index++;

            app_cmd_save_file_info = (mmi_dmui_scomo_app_report_save_file_info_struct*)OslMalloc(sizeof(mmi_dmui_scomo_app_report_save_file_info_struct));

            if (FS_NO_ERROR != FS_Read(
                                fh_scomo_info,
                                app_cmd_save_file_info,
                                sizeof(mmi_dmui_scomo_app_report_save_file_info_struct),
                                &fs_read_len))
            {
                goto fs_error;
            }

            if (fs_read_len < sizeof(mmi_dmui_scomo_app_report_save_file_info_struct))
            {
                goto fs_error;
            }

            FS_Close(fh_scomo_info);

            g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_TRUE;

            /* send msg */
            if (app_cmd_save_file_info->cmd == MMI_DMUI_CMD_SCOMO_INSTALL ||
                app_cmd_save_file_info->cmd== MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE)
            {
                install_by_user_req_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_user_req_struct);
                memcpy(install_by_user_req_struct_ptr->gen_id,    app_cmd_save_file_info->app_cmd_info.app_software_id,    DM_SCOMO_MAX_ID);
                memcpy(install_by_user_req_struct_ptr->name,      app_cmd_save_file_info->app_cmd_info.software_name,      DM_SCOMO_MAX_NAME * 2);
                memcpy(install_by_user_req_struct_ptr->version,   app_cmd_save_file_info->app_cmd_info.software_version,   DM_SCOMO_MAX_NAME);
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_INSTALL_BY_USER_REQ, install_by_user_req_struct_ptr);
            }
            else if (app_cmd_save_file_info->cmd == MMI_DMUI_CMD_SCOMO_REMOVE ||
                     app_cmd_save_file_info->cmd == MMI_DMUI_CMD_SCOMO_REMOVE_ALL)
            {
                remove_by_user_req_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_user_req_struct);
                memcpy(remove_by_user_req_struct_ptr->gen_id,    app_cmd_save_file_info->app_cmd_info.app_software_id,    DM_SCOMO_MAX_ID);
                if (app_cmd_save_file_info->cmd == MMI_DMUI_CMD_SCOMO_REMOVE_ALL)
                {
                    remove_by_user_req_struct_ptr->delete_all = MMI_TRUE;
                }
                else
                {
                    remove_by_user_req_struct_ptr->delete_all = MMI_FALSE;
                }
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SCOMO_REMOVE_BY_USER_REQ, remove_by_user_req_struct_ptr);            
            }

            if (app_cmd_save_file_info)
            {
                OslMfree(app_cmd_save_file_info);
            }
            return;
        }
        else
        {
            goto fs_error;
        }
    }
    else
    {
        goto fs_error;
    }
    return;

fs_error:
    fs_read_index = 0;
    FS_Close(fh_scomo_info);
    FS_Delete(DM_SCOMO_APP_CMD_INFO_FILE_NAME);
    if (app_cmd_save_file_info)
    {
        OslMfree(app_cmd_save_file_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_scomo_cmd
 * DESCRIPTION
 *  function to change the command from DM to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_cmd_enum mmi_dmui_get_scomo_cmd(dm_scomo_command_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_cmd_enum mo_cmd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd)
    {
        case DM_SCOMO_INSTALL_COMMAND:
            mo_cmd = MMI_DMUI_CMD_SCOMO_INSTALL;
            break;

        case DM_SCOMO_INSTALL_INACTIVE_COMMAND:
            mo_cmd = MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE;
            break;

        case DM_SCOMO_REMOVE_COMMAND:
            mo_cmd = MMI_DMUI_CMD_SCOMO_REMOVE;
            break;

        default:
            MMI_ASSERT(0);
    }
    
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_MO_GET_MO_CMD, mo_cmd);
    return mo_cmd;
}
#endif /* __DM_SCOMO_SUPPORT__ */

#ifdef __DM_MO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_change_status_on_command
 * DESCRIPTION
 *  function to change the status before opreate command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_change_status_on_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_dmui_mo_cntx_ptr->mo_cmd)
    {
    #ifdef __DM_LAWMO_SUPPORT__
        case MMI_DMUI_CMD_LAWMO_FULLYLOCK:
        case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING;
            break;

        case MMI_DMUI_CMD_LAWMO_UNLOCK:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_IDLE;
            break;

        case MMI_DMUI_CMD_LAWMO_FACTORYRESET:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_LAWMO_WIPE_FACTORYRESET;
            break;

        case MMI_DMUI_CMD_LAWMO_WIPE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_LAWMO_WIPE_WIPE;
            if (!g_mmi_dmui_is_phone_lawmo_locked)
            {
                g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING;
            }
            break;
    #endif /* __DM_LAWMO_SUPPORT__ */

    #ifdef __DM_SCOMO_SUPPORT__
        case MMI_DMUI_CMD_SCOMO_INSTALL:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_INSTALL;
            break;
            
        case MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_INSTALL_INACTIVE;
            break;
            
        case MMI_DMUI_CMD_SCOMO_ACTIVATE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_ACTIVATE;
            break;
            
        case MMI_DMUI_CMD_SCOMO_INACTIVATE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_INACTIVATE;
            break;
            
        case MMI_DMUI_CMD_SCOMO_REMOVE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_REMOVE;
            break;

        case MMI_DMUI_CMD_SCOMO_REMOVE_ALL:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_SCOMO_REMOVE_ALL;
            break;
    #endif /* __DM_SCOMO_SUPPORT__ */

        default:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_IDLE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_change_status_after_command
 * DESCRIPTION
 *  function to change the status before opreate command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_change_status_after_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_dmui_mo_cntx_ptr->mo_cmd)
    {
    #ifdef __DM_LAWMO_SUPPORT__
        /* remain the status if command is lock */
        case MMI_DMUI_CMD_LAWMO_FULLYLOCK:
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK;
            break;

        case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK;
            break;

        case MMI_DMUI_CMD_LAWMO_UNLOCK:
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_IDLE;
            break;

        /* as the command will lock the phone, so reset it as idle */
        case MMI_DMUI_CMD_LAWMO_FACTORYRESET:
        case MMI_DMUI_CMD_LAWMO_WIPE:
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_WIPE] = MMI_DMUI_STATUS_IDLE;
            if (g_mmi_dmui_is_phone_lawmo_locked == 0)
            {
                g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_LAWMO_LOCK] = MMI_DMUI_STATUS_IDLE;
            }
            break;
    #endif /* __DM_LAWMO_SUPPORT__ */

    #ifdef __DM_SCOMO_SUPPORT__
        case MMI_DMUI_CMD_SCOMO_INSTALL:
        case MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE:
        case MMI_DMUI_CMD_SCOMO_ACTIVATE:
        case MMI_DMUI_CMD_SCOMO_INACTIVATE:
        case MMI_DMUI_CMD_SCOMO_REMOVE:
        case MMI_DMUI_CMD_SCOMO_REMOVE_ALL:
            g_mmi_dmui_mo_cntx_ptr->mo_status[MMI_DMUI_MO_TYPE_SCOMO] = MMI_DMUI_STATUS_IDLE;
            break;
    #endif /* __DM_SCOMO_SUPPORT__ */
        default:
            g_mmi_dmui_mo_cntx_ptr->mo_status[g_mmi_dmui_mo_cntx_ptr->mo_type] = MMI_DMUI_STATUS_IDLE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_status
 * DESCRIPTION
 *  function to get the status
 * PARAMETERS
 *  mmi_dmui_mo_type_enum :[IN] MO type
 * RETURNS
 *  mmi_dmui_status_enum : MO status
 *****************************************************************************/
mmi_dmui_status_enum mmi_dmui_get_status(mmi_dmui_mo_type_enum mo_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_MO_GET_STATUS, mo_type, g_mmi_dmui_mo_cntx_ptr->mo_status[mo_type]);
    return g_mmi_dmui_mo_cntx_ptr->mo_status[mo_type];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_mo_type
 * DESCRIPTION
 *  function to get the mo type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_mo_type_enum mmi_dmui_get_mo_type(mmi_dmui_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_mo_type_enum mo_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (mo_type < MMI_DMUI_MO_TYPE_TOTAL)
    {
        if (cmd < ((mo_type + 1) * MMI_DMUI_MO_TYPE_STEP))
        {
            break;
        }
        else
        {
            mo_type++;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMUI_MO_GET_MO_TYPE, mo_type);
    return mo_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_mo_switch_error_code
 * DESCRIPTION
 *  function to switch the error code from app to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_dmui_mo_switch_error_code(mmi_dmui_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_DMUI_RESULT_SUCCESS:
            if (g_mmi_dmui_mo_cntx_ptr->mo_type == MMI_DMUI_MO_TYPE_SCOMO)
            {
                return DM_SCOMO_SUCCESSFUL;
            }
            else
            {
                return MMI_DMUI_RESULT_SUCCESS;
            }

        case MMI_DMUI_RESULT_FAILURE:
            return MMI_DMUI_RESULT_FAILURE;

        case MMI_DMUI_RESULT_SCOMO_USER_CANCEL:
            return DM_SCOMO_USER_CANCEL;
        
        case MMI_DMUI_RESULT_SCOMO_DOWNLOAD_FAIL:
            return DM_SCOMO_DOWNLOAD_PACKET_FAIL;

        case MMI_DMUI_RESULT_SCOMO_AUTH_FAIL:
            return DM_SCOMO_AUTH_FAIL;

        case MMI_DMUI_RESULT_SCOMO_DOWNLOAD_OUT_MEMORY:
            return DM_SCOMO_DOWNLOAD_OUT_MEMORY;

        case MMI_DMUI_RESULT_SCOMO_INSTALL_FAIL:
            return DM_SCOMO_INSTALL_FAIL;
                
        case MMI_DMUI_RESULT_SCOMO_INSTALL_OUT_MEMORY:
            return DM_SCOMO_INSTALL_OUT_MEOMORY;
                
        case MMI_DMUI_RESULT_SCOMO_PACKAGE_INVALID:
            return DM_SCOMO_PACKAGE_INVALID;
                
        case MMI_DMUI_RESULT_SCOMO_REMOVE_FAIL:
            return DM_SCOMO_REMOVE_FAIL;
                
        case MMI_DMUI_RESULT_SCOMO_ACTIVE_FAIL:
            return DM_SCOMO_ACTIVE_FAIL;
                
        case MMI_DMUI_RESULT_SCOMO_DEACTIVE_FAIL:
            return DM_SCOMO_DEACTIVE_FAIL;
            
        case MMI_DMUI_RESULT_SCOMO_OPERATION_REJECT:
            return DM_SCOMO_OPERATION_REJECT;
            
        case MMI_DMUI_RESULT_SCOMO_DOWNLOAD_SERVER_ERROR:
            return DM_SCOMO_DOWNLOAD_SERVER_ERROR;

        default:
            MMI_ASSERT(0);
    }
}

#ifdef MMI_DM_MO_TEST
void mmi_dmui_lock_test(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    g_mmi_dmui_mo_cntx_ptr->mo_cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
    mmi_dmui_lawmo_req_ind_hdlr(NULL);
}


void mmi_dmui_unlock_test(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    g_mmi_dmui_mo_cntx_ptr->mo_cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
    mmi_dmui_lawmo_req_ind_hdlr(NULL);
}


void mmi_dmui_wipe_test(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    g_mmi_dmui_mo_cntx_ptr->mo_cmd = MMI_DMUI_CMD_LAWMO_WIPE;
    mmi_dmui_lawmo_req_ind_hdlr(NULL);
}
#endif /* MMI_DM_MO_TEST */
#endif /* __DM_MO_SUPPORT__ */

#endif /* SYNCML_DM_SUPPORT */ 

/* End of dmuiapp.c */

