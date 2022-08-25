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
*   avk_idle_nwname.cpp
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
*
* Author:
* -------
* -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
extern "C"
{
/* NON SDK APIs */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "FileMgrGProt.h"
#include "SettingProfile.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "CustMenuRes.h"
#include "Wgui_categories_util.h"

#include "NwNameSrvGprot.h"
#include "avk_conn_btds.h"
}

AVK_ADD_ITEM(AVK_IDLE_NWNAME_AUTO, L"Auto Cases", AVK_IDLE_NWNAME);

static void VS_CASE_NWNAME_FINISHED(MMI_BOOL ret_b, vs_test_item_enum ti_e, const void * words)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 wszTxt[128] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    AVK_CASE_RESULT((0 != ret_b) ? AVK_PASS : AVK_FAIL);
    AVK_ASYN_DONE();
    /*
    vs_tfw_trace_result((U16*)words, ret_b, 0, VS_TA_BTOPP);
    if (vs_tfw_is_test_all_active(ti_e))
    {
        if (ret_b)
            vs_tfw_finish_case(ti_e);
    }
    else
    {
        kal_wstrcat(wszTxt, words);
        kal_wsprintf(&wszTxt[kal_wstrlen(wszTxt)], " ret [%d]", ret_b);
        #ifdef __MMI_SCREEN_ROTATE__
        if (ret_b)
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        else
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        #endif
    }
    */
}
AVK_CASE(AVK_IDLE_NWNAME_AUTO_01, AVK_IDLE_NWNAME_AUTO)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 ret;
	WCHAR name[260];
	MMI_BOOL bIsReady;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	bIsReady = srv_nw_name_is_ready(MMI_SIM1);

	ret = srv_nw_name_get_name(MMI_SIM1, name, 260);

    AVK_CASE_RESULT(AVK_PASS);
//    AVK_ASYN_DONE();

	//vs_service_idlescreen_log(L"vs_service_idlescreen_001_nw_get_name",VS_SERVICE_IDLESCREEN_001, MMI_TRUE, VS_TA_SERVICE_IDLESCREEN);
}

AVK_CASE(AVK_IDLE_NWNAME_AUTO_02, AVK_IDLE_NWNAME_AUTO)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 ret;
	WCHAR name[260];
	MMI_BOOL bIsRequired;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	bIsRequired = srv_nw_name_is_rplmn_required(MMI_SIM1);
	if(bIsRequired)
	{
		kal_prompt_trace(MOD_MMI,"rplmn is  required");
	}
	else
	{
		kal_prompt_trace(MOD_MMI,"rplmn is  not required");
	}
	ret = srv_nw_name_get_name_ex(MMI_SIM1, SRV_NW_NAME_TYPE_EONS,name, 260);
	//vs_service_idlescreen_log(L"vs_service_idlescreen_002_nw_get_name_ex",VS_SERVICE_IDLESCREEN_002, MMI_TRUE, VS_TA_SERVICE_IDLESCREEN);
    AVK_CASE_RESULT(AVK_PASS);
//    AVK_ASYN_DONE();
}

AVK_CASE(AVK_IDLE_NWNAME_AUTO_03, AVK_IDLE_NWNAME_AUTO)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 ret;
	WCHAR name[260];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	ret = srv_nw_name_get_name_if_any(MMI_SIM1,name, 260);

	//vs_service_idlescreen_log(L"vs_service_idlescreen_003_nw_get_name_if_any",VS_SERVICE_IDLESCREEN_003, MMI_TRUE, VS_TA_SERVICE_IDLESCREEN);
    AVK_CASE_RESULT(AVK_PASS);
//    AVK_ASYN_DONE();
}

AVK_CASE(AVK_IDLE_NWNAME_AUTO_04, AVK_IDLE_NWNAME_AUTO)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 ret;
	WCHAR spn[260];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/



	if(!srv_nw_name_is_spn_required(MMI_SIM1))
	{
		kal_prompt_trace(MOD_MMI,"spn is not required");
	}

	ret = srv_nw_name_get_spn(MMI_SIM1, spn, 260);

	//vs_service_idlescreen_log(L"vs_service_idlescreen_004_nw_get_spn",VS_SERVICE_IDLESCREEN_004, MMI_TRUE, VS_TA_SERVICE_IDLESCREEN);
    AVK_CASE_RESULT(AVK_PASS);
//    AVK_ASYN_DONE();
}


#endif


