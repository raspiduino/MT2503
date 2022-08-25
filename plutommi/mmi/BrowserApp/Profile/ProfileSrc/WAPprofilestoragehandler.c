/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * WAPProfilestoragehandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for MTK to config/customize NVRAM settings.
 *
 * Author: Ramneek Kalra
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"

//#include "ServiceDefs.h"
//#include "CommonScreens.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "DataAccountGProt.h"
//#include "custom_nvram_editor_data_item.h"
//#include "SettingProfile.h"     /* For error tone */
#include "custom_mmi_default_value.h"

//#include "DtcntSrvGprot.h"

#ifdef __MMI_WAP_PROF__
//#include "WAPProfConfig.h"
#include "WAPProfileType.h"
#include "WAPProfResDef.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "WAPProfileProt.h"

//------------------------------ suggest Add ------------------------------

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "cbm_api.h"

#include "cbm_consts.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
//------------------------------ usage ------------------------------






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_set_active_profile_index
 * DESCRIPTION
 *  Sets index value to active profile index global. commits to NVRAM if commit_flag = MMI_TRUE
 * PARAMETERS
 *  sim_id          [IN]        
 *  app_id          [IN]        
 *  index_value     [IN]        
 *  commit_flag     [IN]        
 * RETURNS
 *  U8    activated profile index(?)
 *****************************************************************************/
void mmi_wap_prof_set_active_profile_index(
        mmi_wap_prof_sim_id_enum sim_id,
        mmi_wap_prof_app_id_enum app_id,
        U32 index_value,
        MMI_BOOL commit_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_SET_ACTIVE_INDEX, sim_id, app_id, index_value, commit_flag);

  
  
    if ((sim_id >= MMI_WAP_PROF_SIMID_END) ||
        (app_id >= MMI_WAP_PROF_APPID_END))
        
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }

      
	
#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)


    if (g_mmi_wap_prof_cntx.sim_id != MMI_WAP_PROF_SIMID_WLAN)
    {

  
    g_mmi_wap_prof_cntx.active_dtcnt_index[sim_id][app_id] = index_value;
     }

#else /*(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/   

    g_mmi_wap_prof_cntx.active_dtcnt_index[sim_id][app_id] = index_value;


#endif


    if (commit_flag)
    {
        mmi_wap_prof_nvram_write_active_profile_index(sim_id, app_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_nvram_write_active_profile_index
 * DESCRIPTION
 *  THis API writes active index to NVRAM.
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  U8    activated profile index(?)
 *****************************************************************************/
void mmi_wap_prof_nvram_write_active_profile_index(mmi_wap_prof_sim_id_enum sim_id, mmi_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    S16 error;
    U16 lid = 0;
    U32 encoded_dtcnt_id = 0;
    U8 primary_dtcnt_id;
    U8 secondary_dtcnt_id;

    cbm_account_info_struct acct_info;
    S8 decode_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  if (app_id >= MMI_WAP_PROF_APPID_END || sim_id >= MMI_WAP_PROF_SIMID_END)
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }

    if (MMI_WAP_PROF_APPID_BRW == app_id)
    {

        if(MMI_WAP_PROF_SIMID_SIM1 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=2)
        else if(MMI_WAP_PROF_SIMID_SIM2 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX;
   }
#if (MMI_MAX_SIM_NUM>=3) 
		else if(MMI_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX;
		}
#if(MMI_MAX_SIM_NUM>=4) 
		else if(MMI_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX;
		}
#endif
#endif
#endif

        else
		{ 
			ASSERT(0);
		}


    }
    else if (MMI_WAP_PROF_APPID_MMS == app_id)
    {

        if (MMI_WAP_PROF_SIMID_SIM1 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX;
        }

#if (MMI_MAX_SIM_NUM>=2)
        else if (MMI_WAP_PROF_SIMID_SIM2 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX;
        }
#if (MMI_MAX_SIM_NUM>=3)
		else if(MMI_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=4)
		else if(MMI_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX;
		}
#endif 
#endif
#endif
    else
    {
        ASSERT(0);
        return;
    }
	}


    encoded_dtcnt_id = mmi_wap_prof_get_active_dtcnt_index(sim_id, app_id);


    decode_result = cbm_decode_data_account_id_ext(encoded_dtcnt_id, &acct_info);

    if (CBM_OK == decode_result)
{

            primary_dtcnt_id = acct_info.account[0].account_id;
            secondary_dtcnt_id = (U8) - 1;

            if (acct_info.acct_num > 1)
    {
				secondary_dtcnt_id = acct_info.account[1].account_id;
}

        }
        else
    {  //10ADA  check this case
            /* Do not change account id as result is error. */
/*            MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] CBM decode API error."); */
            MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_CBM_DECODE);
        }



    index = (U16)secondary_dtcnt_id;

    index = index << 8;
    index = index | (U16) (primary_dtcnt_id & 0x00FF);
		
		

    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_WRITE_ACTIVE_INDEX, app_id, index);

    WriteValue(lid, &index, DS_SHORT, &error);
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_WRITE_ERROR, error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_nvram_read_active_profile_index
 * DESCRIPTION
 *  It will read the active data account id from NVRAM, based on app_id.
 * PARAMETERS
 *  app_id      [IN]        Application ID BRW / MMS.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_prof_nvram_read_active_profile_index(mmi_wap_prof_sim_id_enum sim_id, mmi_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    S16 error;
    U16 lid = 0;
    MMI_BOOL upd_flag = MMI_FALSE;
	
    U32 encoded_dtcnt_id = MMI_DTCNT_INVALID_ID;
    U8 secondary_index =0;
    U8 primary_index = 0;
   
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;

#if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    U32 cbm_encoded_dtcnt_id = MMI_DTCNT_INVALID_ID;    /* MAUI_01730725 */
    cbm_account_info_struct data_account_info;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_ACTIVE_INDEX, app_id);
    if (app_id >= MMI_WAP_PROF_APPID_END || sim_id >= MMI_WAP_PROF_SIMID_END)
    {
        ASSERT(app_id < MMI_WAP_PROF_APPID_END);
        ASSERT(sim_id < MMI_WAP_PROF_SIMID_END);
        return;
    }

    if (MMI_WAP_PROF_APPID_BRW == app_id)
    {
        
        if (MMI_WAP_PROF_SIMID_SIM1 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX;
        }

#if (MMI_MAX_SIM_NUM>=2)
        else if (MMI_WAP_PROF_SIMID_SIM2 == sim_id)
        {
            lid =NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX;
}
#if (MMI_MAX_SIM_NUM>=3)
		else if(MMI_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX;
		}
#if (MMI_MAX_SIM_NUM>=4)
		else if(MMI_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX;
		}
    
      
#endif
#endif
#endif

        else
        { ASSERT(0); }

   
    }
    else if (MMI_WAP_PROF_APPID_MMS == app_id)
    {

     if(MMI_WAP_PROF_SIMID_SIM1 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX;
    }

#if (MMI_MAX_SIM_NUM>=2)
        else if(MMI_WAP_PROF_SIMID_SIM2 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=3)
		else if(MMI_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX;
		}
#if (MMI_MAX_SIM_NUM>=4) 
		else if(MMI_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX;
		}
#endif
#endif
#endif
    
    else
    {
        ASSERT(0);
        return;
    }
	}

    ReadValue(lid, &index, DS_SHORT, &error);

    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_ERROR, error);
    MMI_TRACE(MMI_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_RETURN_INDEX, index);

    /* Bits 0-7 contains primary data account id. */
    primary_index = (U8) ((index) & 0x00FF);  




    /* Bits 8-15 contains secondary data account id. */
    secondary_index = (U8) ((index) >> 8);


if( primary_index == (U8)-1 || primary_index == CBM_DEFAULT_ACCT_ID)
    {
   primary_index = CBM_DEFAULT_ACCT_ID;
    if(secondary_index == CBM_DEFAULT_ACCT_ID)
	{
          secondary_index = (U8) - 1;
	}
   //10ADA : Check how to handle the case of updating the nvram here
    }


    encoded_dtcnt_id = mmi_wap_prof_encode_dtcnt(primary_index, secondary_index, sim_id,  app_id );

    mmi_wap_prof_set_active_profile_index(sim_id, app_id, encoded_dtcnt_id, upd_flag); //10ADA : upd_flag always FALSE

 

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_encode_dtcnt
 * DESCRIPTION
 *  It will return an encoded data account id 
 * PARAMETERS
 *  app_id      [IN]        Application ID BRW / MMS.
 * RETURNS
 *  U32
 *****************************************************************************/

U32 mmi_wap_prof_encode_dtcnt(U8 primary_index, U8 secondary_index, mmi_wap_prof_sim_id_enum sim_id, mmi_wap_prof_app_id_enum app_id )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
	mmi_wap_prof_sim_id_enum sim_info = MMI_WAP_PROF_SIMID_SIM1;


#if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    U32 cbm_encoded_dtcnt_id = MMI_DTCNT_INVALID_ID;    /* MAUI_01730725 */
    cbm_account_info_struct data_account_info;
   
#endif

    U32 encoded_dtcnt_id = MMI_DTCNT_INVALID_ID;
    U8 cbm_app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	switch(sim_id)
        {    
	case MMI_WAP_PROF_SIMID_SIM1:
		cbm_sim_id = CBM_SIM_ID_SIM1; 
	    if (app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id =g_mmi_wap_prof_cntx.cbm_brw_app_id_1;
        else
			cbm_app_id =g_mmi_wap_prof_cntx.cbm_mms_app_id_1;
			break;
#if (MMI_MAX_SIM_NUM>=2)
	case MMI_WAP_PROF_SIMID_SIM2:
		cbm_sim_id = CBM_SIM_ID_SIM2;
		if (app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_2;
        else
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_2;
		break;
#if (MMI_MAX_SIM_NUM>=3)
	case MMI_WAP_PROF_SIMID_SIM3:
		cbm_sim_id = CBM_SIM_ID_SIM3;
      		if(app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_3;
			else
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_3;
		break;
#if (MMI_MAX_SIM_NUM>=4)
	case MMI_WAP_PROF_SIMID_SIM4:
		cbm_sim_id = CBM_SIM_ID_SIM4;
		if (app_id  ==  MMI_WAP_PROF_APPID_BRW)
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_brw_app_id_4;
		else
			cbm_app_id = g_mmi_wap_prof_cntx.cbm_mms_app_id_4;
		break; 
#endif
#endif
#endif
	default:
		break;
    }





 #if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    data_account_info.account[0].account_id =  primary_index;

    data_account_info.account[0].is_always_ask = FALSE;
    data_account_info.account[0].sim_id =  cbm_sim_id ;   //10ADA check the mapping

    if ((U8) - 1 != secondary_index)
{
        data_account_info.account[1].account_id = secondary_index;

        data_account_info.account[1].is_always_ask = FALSE;
        data_account_info.account[1].sim_id = cbm_sim_id ;   //10ADA check the mapping
        data_account_info.acct_num = 2;
    }
    else
    {
        data_account_info.acct_num = 1;
    }





    data_account_info.app_id = cbm_app_id;
     


    cbm_encode_data_account_id_ext(primary_index, 
                                   &cbm_encoded_dtcnt_id,
                                   &data_account_info);

#endif /* (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__)) */ 



    if (app_id == MMI_WAP_PROF_APPID_BRW)
        {

    #if defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__)
    encoded_dtcnt_id = cbm_encoded_dtcnt_id ;
    #else
    encoded_dtcnt_id = cbm_encode_data_account_id(primary_index, cbm_sim_id, cbm_app_id, FALSE);
#endif
}


    if (app_id == MMI_WAP_PROF_APPID_MMS)
    {

    #if defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__)
    encoded_dtcnt_id = cbm_encoded_dtcnt_id ;
    #else
    encoded_dtcnt_id = cbm_encode_data_account_id(primary_index, cbm_sim_id, cbm_app_id, FALSE);
#endif
                }

    return encoded_dtcnt_id;

    }
    


#endif /* __MMI_WAP_PROF__ */ 
