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
 * WAPProvisioningMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UPP Provisioning application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"

#include "custom_nvram_editor_data_item.h"

#include "Nvram_enums.h"


	
#include "DataAccountGProt.h"

#include "DtcntSrvGprot.h"

#ifdef WAP_SUPPORT

#include "WAPProfileSrvType.h"
#include "WAPProfSrvConfig.h"
#ifdef PROV_SUPPORT
#include "WAPProfResDef.h"
#include "CentralConfigAgentGprot.h"
#include "mmi_rp_app_mmi_wap_prof_def.h"
#include "mmi_rp_app_cca_def.h"
#include "WAPProfileProt.h"
#include "WAPProfileSrvProt.h"
#include "WAPProfileSrvGprot.h"

#include "WAPprovisioningSrvType.h"
#include "WAPprovisioningSrvprot.h"
#include "WAPprovisioningProt.h"
#include "DataAccountDef.h"
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* Error tones */
#include "ConnectManageGprot.h"
#include "Conversions.h"
#include <ctype.h>
#include "wgui_categories.h"
#include "Wgui_categories_util.h"

#ifdef SYNCML_DM_SUPPORT
#include "cbfunc.h"
#endif 
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"         /* LAWMO/SCOMO */
#endif

static void mmi_wap_prof_prov_app_ui_entry_info_screen_display(U32 profile_count);
static void mmi_wap_prof_prov_app_ui_pre_entry_info_screen_display(U32 profile_count, srv_wap_prov_type_enum provisioning_type);
static void mmi_wap_prof_prov_app_create_prov_screen(U32 profile_count, srv_wap_prov_type_enum provisioning_type);
static void mmi_wap_prof_prov_app_recreate_prov_screen(U32 profile_count, srv_wap_prov_type_enum provisioning_type);
static void mmi_wap_prov_app_create_display_info(U8 *out_buffer, S32 size, U32 profile_count);
static void mmi_wap_prov_app_content_display_rsk_hdlr(void);
static mmi_id mmi_wap_prof_enter_root_group(void);
static U32 profile_count =0;
static srv_wap_prov_type_enum provisioning_type;

/*****************************************************************************
 * FUNCTION
*  mmi_wap_prov_create_display_info
 * DESCRIPTION
*  
 * PARAMETERS
 *  void
 * RETURNS
*  PU8(?)
 *****************************************************************************/
static void mmi_wap_prov_app_create_display_info(U8 *out_buffer, S32 size, U32 profile_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
S8 single_space_char_ucs2[3 * ENCODING_LENGTH];
	S8 *colon_char_ucs2;    /* MAUI_01105762 */
	U8 new_line_info[SRV_WAP_PROV_NEW_LINE_SIZE];
	S8 buffer[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH];     /* MAUI_00062290 */
	S8 ascii_buffer[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH];
	S32 index;
	U32 max_subMenuData_ucs2_chars = ((MAX_SUB_MENUS * MAX_SUB_MENU_SIZE) / ENCODING_LENGTH) - 1;
	U32 used_chars_count = 0;
	//   U32 max_buffer_chars = MAX_DATA_ACCOUNT_NAME_LEN;   /* MAUI_00062290 */
	U32 max_buffer_bytes = sizeof(buffer);
#ifdef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__
	srv_wap_prov_mms_setting_data_list_struct   *mms_setting_data_p;
#endif
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset(out_buffer, 0, size);
	mmi_asc_to_ucs2((S8*) new_line_info, (S8*) "\n");    /* MAUI_00062290 */
	mmi_asc_to_ucs2((S8*) single_space_char_ucs2, (S8*) " ");    /* MAUI_00062290 */
	colon_char_ucs2 = (S8*) GetString(STR_ID_WAP_PROF_COLON_CHAR);     /* MAUI_01105762 */
#ifdef BROWSER_SUPPORT
	if (SRV_WAP_PROF_APPID_BRW == srv_wap_prov_get_app_id())
	{
		mmi_ucs2ncpy((PS8) out_buffer, (PS8) GetString(STR_ID_CCA_BROWSER), max_subMenuData_ucs2_chars);
	}
#endif
   
#ifdef MMS_SUPPORT    
	if (SRV_WAP_PROF_APPID_MMS == srv_wap_prov_get_app_id())
	{
		mmi_ucs2ncpy((PS8) out_buffer, (PS8) GetString(STR_ID_CCA_MMS), max_subMenuData_ucs2_chars);
	}
#endif
	mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
	mmi_ucs2cat(
		(PS8) out_buffer,
		(PS8) GetString(STR_ID_CCA_PROFILE));
	/* MAUI_01105762 */
	mmi_ucs2cat((PS8) out_buffer, (PS8) colon_char_ucs2);
	mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
	/* MAUI_01105762 ends */
			
	memset(buffer, 0, max_buffer_bytes);
	memset(ascii_buffer, 0, sizeof(ascii_buffer));
	sprintf(
		(S8*) ascii_buffer,
		/*            (S8*) "%c %d/%d", ':',  MAUI_01105762 */ (S8*) "%d/%d",     /* MAUI_01105762 */
		srv_wap_prov_get_current_bkm_mms_index() + 1,
		srv_wap_prov_get_current_bkm_mms_index() + srv_wap_prov_get_profile_count());

	mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);
	mmi_ucs2cat((PS8) out_buffer, (PS8) buffer); /* MAUI_00062290 */


	if (srv_wap_prov_get_bkm_cnt() > 0)
	{
		mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);    /* MAUI_00062290 */
		mmi_ucs2cat((PS8) out_buffer, 
			(PS8) GetString(STR_ID_WAP_PROF_PROV_BOOKMARKS_COLON));
		mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);

		memset(buffer, '\0', max_buffer_bytes);
		memset(ascii_buffer, 0, sizeof(ascii_buffer));
		sprintf(
			(S8*) ascii_buffer,
			(S8*) "%d",
			srv_wap_prov_get_bkm_cnt());
		mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);
		mmi_ucs2cat((PS8) out_buffer, buffer);

		for (index = 0; index < srv_wap_prov_get_bkm_cnt(); index++)
		{
			mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

			memset(buffer, '\0', max_buffer_bytes);
			mmi_ucs2ncat((PS8) out_buffer, 
				GetString(STR_ID_WAP_PROF_PROV_BOOKMARK), 
				(max_subMenuData_ucs2_chars - used_chars_count - 1 - 1));
			/*            sprintf ((S8*) ascii_buffer, (S8*) "%d%s", index+1, ": "); MAUI_01105762 */
			sprintf((S8*) ascii_buffer, (S8*) "%d", index + 1);       /* MAUI_01105762 */
			mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);  /* MAUI_00062290 */
			mmi_ucs2ncat((PS8) out_buffer, (PS8) buffer, (max_subMenuData_ucs2_chars - used_chars_count - 1));
			/* MAUI_01105762 */
			mmi_ucs2cat((PS8) out_buffer, (PS8) colon_char_ucs2);
			mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
			/* MAUI_01105762 ends */
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

		  if (mmi_ucs2strlen(srv_wap_prov_get_bm_title(index)) != 0)
			{
				if ((S32)
					(max_subMenuData_ucs2_chars - used_chars_count - 1 -
					mmi_ucs2strlen((S8*) g_srv_wap_prov_cntx.profile_list[g_srv_wap_prov_cntx.crnt_prof_index]->
					bookmark[index]->bm_title)) <= 0)
				{
					/* 
					*  break out if length of destination is not large enough.
					*/
					break;
				}
				srv_wap_prof_prov_get_displayable_data(out_buffer,srv_wap_prov_get_bm_title(index),
					SRV_WAP_PROF_DCS_UCS2);
			}

			if ((S32) (max_subMenuData_ucs2_chars - used_chars_count - 1 - strlen(srv_wap_prov_get_bm_url(index))) <= 0)
			{
				/* 
				*  break out if length of destination is not large enough.
				*/
				break;
			}
			srv_wap_prof_prov_get_displayable_data(out_buffer,srv_wap_prov_get_bm_url(index),
				SRV_WAP_PROF_DCS_ASCII);
		}
	}

	/* MAUI_00808274 starts */

#ifdef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__

	mms_setting_data_p = srv_wap_prov_get_mms_setting_data();

	if (mms_setting_data_p)
	{
		mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);        /* MAUI_00062290 */
		used_chars_count = mmi_ucs2strlen((PS8) out_buffer);
		mmi_ucs2ncat((PS8) out_buffer, 
			(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTINGS), 
			(max_subMenuData_ucs2_chars - used_chars_count - 1));

		for (; mms_setting_data_p; mms_setting_data_p = mms_setting_data_p->next)
		{
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);
			if (used_chars_count >= max_subMenuData_ucs2_chars)
			{
				/* No more space to put characters. */
				break;
			}

			mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
			switch (mms_setting_data_p->key)
			{
			case SRV_WAP_PROV_MMS_SETTING_CM:
#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
			case SRV_WAP_PROV_MMS_SETTING_RM:
#endif   
				if (SRV_WAP_PROV_MMS_SETTING_CM == mms_setting_data_p->key)
				{
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_CM_COLON), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
				}
#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
				else
				{
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_RM_COLON), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
				}
#endif /* __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__ */
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				switch (mms_setting_data_p->value_i)
				{
				case SRV_WAP_PROV_MMS_SETTING_RESTRICTED:
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_RESTRICTED), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				case SRV_WAP_PROV_MMS_SETTING_WARNING:
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_WARNING), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				case SRV_WAP_PROV_MMS_SETTING_FREE:
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_FREE), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				default:
					mmi_ucs2ncat((PS8) out_buffer, 
						/*                                         (PS8) GetString (STR_ID_VAPP_PROF_PROV_MMS_SETTING_VALUE_INVALID), */
						(PS8) GetString (STR_GLOBAL_INVALID),  /* Global string usage */
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;
}
				break;

#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__

			case SRV_WAP_PROV_MMS_SETTING_MA:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_MA_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				switch (mms_setting_data_p->value_i)
				{
				case SRV_WAP_PROV_MMS_SETTING_MA_DISABLE:
					mmi_ucs2ncat((PS8) out_buffer, 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				case SRV_WAP_PROV_MMS_SETTING_MA_ENABLE:
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_ENABLE), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				case SRV_WAP_PROV_MMS_SETTING_MA_LOCKED:
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_LOCKED), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;

				default:
					mmi_ucs2ncat((PS8) out_buffer, 
						/*                                         (PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_INVALID), */
						(PS8) GetString (STR_GLOBAL_INVALID),  /* Global string usage */
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
					break;
				}
				break;

			case SRV_WAP_PROV_MMS_SETTING_MS:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_MS_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				sprintf((S8*) ascii_buffer, 
					(S8*) "%d", 
					mms_setting_data_p->value_i);
				mmi_asc_to_ucs2(
					(S8*) buffer,
					(S8*) ascii_buffer);

				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) buffer, 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				break;

			case SRV_WAP_PROV_MMS_SETTING_PCADDR:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_WAP_PROF_PROV_MMS_SETTING_PCADDR_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);

				srv_wap_prof_prov_get_displayable_data((S8*) mms_setting_data_p->value_s,
					SRV_WAP_PROF_DCS_ASCII);
				/* MAUI_00062290 ends */

				break;
#endif /* __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__ */
			}
		}
	}
#endif /* __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__ */
	/* MAUI_00808274 ends */
}


/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_prov_app_prov_screen_hdlr
 * DESCRIPTION
 *  function to handle the service callback
 * PARAMETERS
 *    param :      [IN]  event parameter.
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
 S32 mmi_wap_prof_prov_app_prov_screen_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      srv_wap_prov_create_prov_scrn_evt_struct *event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	event = (srv_wap_prov_create_prov_scrn_evt_struct*)evt;
	switch (event->evt_id)
    {
    case EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND:
        provisioning_type = event->provisioning_type;
		profile_count = event->profile_count;
        mmi_wap_prof_prov_app_create_prov_screen(profile_count,provisioning_type);
        break;
    case EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND:
		profile_count = event->profile_count;
		provisioning_type = event->provisioning_type;
        mmi_wap_prof_prov_app_recreate_prov_screen(profile_count, provisioning_type);
        break;
    case EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND:
		provisioning_type = event->provisioning_type;
		profile_count = event->profile_count;
        mmi_wap_prof_prov_app_ui_pre_entry_info_screen_display(profile_count, provisioning_type);
		break;
	default:
        break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prov_app_dtcnt_ready_check_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 * evt
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_wap_prov_app_dtcnt_ready_check_hdlr(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      srv_wap_prov_dtcnt_ready_check_evt_struct *event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	event = (srv_wap_prov_dtcnt_ready_check_evt_struct*)evt;
	if( mmi_dtcnt_ready_check(event->callback, event->scrn_lock)) 
    {
		srv_wap_prof_prov_dtcnt_ready_callback();  //10ADA
    }
return MMI_RET_OK;	
}

void mmi_wap_prof_info_scrn_active()
{
	    U8 *guiBuffer;
	    srv_wap_prof_module_status_enum module_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_DISPLAY_INFO_SCREEN_ENTER);

	guiBuffer = mmi_frm_scrn_get_gui_buf (mmi_wap_prof_enter_root_group(), SCR_ID_WAP_PROF_PROV_DISPLAY_INFO);
    srv_wap_prov_set_srn_delete_status(SRV_WAP_PROV_UNSET_SCRN_DELETED);
    mmi_wap_prov_app_create_display_info(*subMenuData, sizeof(subMenuData), profile_count);

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_INSTALL,
        0,
        STR_ID_CCA_SKIP,
        0,
        (U8*) subMenuData,
        mmi_ucs2strlen((const S8*)subMenuData),
        guiBuffer);

    SetLeftSoftkeyFunction(srv_wap_prov_install_setting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_wap_prov_app_content_display_rsk_hdlr, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(srv_wap_prov_install_setting, KEY_EVENT_UP);
    srv_wap_prof_get_module_status(&module_status);

    if (module_status != SRV_WAP_PROF_READY)
    {
        /* Clear key handlers for OTA provisioning only. */
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}



static mmi_ret mmi_wap_prof_info_scrn_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
    {
		case EVT_ID_SCRN_INIT:
        {
            break;
        }
        
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_wap_prof_info_scrn_active();
            break;
        }
	    case EVT_ID_SCRN_DEINIT:
		case EVT_ID_SCRN_GOBACK:
		case EVT_ID_SCRN_DELETE_REQ:
		case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
		case EVT_ID_SCRN_GOBACK_IN_END_KEY:
				srv_wap_prof_prov_delete_info_scr_hdlr_callback(evt);
				break;				
	}
	 return MMI_RET_OK;
}


void mmi_wap_prof_show_info_screen()
{
	   mmi_frm_scrn_create(mmi_wap_prof_enter_root_group(), 
        SCR_ID_WAP_PROF_PROV_DISPLAY_INFO,
        mmi_wap_prof_info_scrn_proc, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_prov_app_ui_pre_entry_info_screen_display
 * DESCRIPTION
 *  Pre-entry API to info screen display. It checks if active call is progressing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wap_prof_prov_app_ui_pre_entry_info_screen_display(U32 profile_count, srv_wap_prov_type_enum provisioning_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (SRV_WAP_PROV_TYPE_OTA == provisioning_type)
    {
       #ifdef __DM_LAWMO_SUPPORT__
            if( TRUE == mmi_dmui_is_phone_lock())  /*LAWMO/SCOMO*/
			{
				srv_wap_prov_reset_status();

             if(SCR_ID_WAP_PROF_PROV_DISPLAY_INFO !=	mmi_frm_scrn_get_active_id() )
				mmi_frm_scrn_close(MMI_WAP_PROV_CCA_GRP_ID, SCR_ID_WAP_PROF_PROV_DISPLAY_INFO);
			    return;
			}
			else
		#endif /* __DM_LAWMO_SUPPORT__ */
    {
				mmi_wap_prof_show_info_screen();
				//mmi_wap_prof_prov_app_ui_entry_info_screen_display(profile_count);
        }
       }
    else
    {
        /* USIM PROV */
            srv_wap_prov_install_setting();
        
    }
}


static mmi_id mmi_wap_prof_enter_root_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_wap_prov_cntx.cui_id != GRP_ID_INVALID)
    {
        return g_srv_wap_prov_cntx.cui_id;
    }

    g_srv_wap_prov_cntx.cui_id = mmi_frm_group_create_ex(mmi_cca_get_root_group(), MMI_WAP_PROV_CCA_GRP_ID, mmi_wap_prov_app_cca_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    return g_srv_wap_prov_cntx.cui_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_prov_dtcnt_ready_callback
 * DESCRIPTION
 *  Callback func after Data account is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wap_prof_prov_app_create_prov_screen(U32 profile_count, srv_wap_prov_type_enum provisioning_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

			mmi_wap_prof_enter_root_group();

			mmi_wap_prof_prov_app_ui_pre_entry_info_screen_display(profile_count, provisioning_type);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_prov_dtcnt_ready_callback
 * DESCRIPTION
 *  Callback func after Data account is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wap_prof_prov_app_recreate_prov_screen(U32 profile_count, srv_wap_prov_type_enum provisioning_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

            if (profile_count)
    {
				mmi_frm_scrn_create(mmi_wap_prof_enter_root_group(), SCR_ID_DUMMY, NULL, NULL);	
				mmi_frm_scrn_close(mmi_wap_prof_enter_root_group(), SCR_ID_DUMMY);
			}
			else
            {
		       mmi_frm_group_close(g_srv_wap_prov_cntx.cui_id);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_wap_prov_content_display_rsk_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_wap_prov_app_content_display_rsk_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_cca_ui_common_cancel_with_sg(MMI_WAP_PROV_CCA_GRP_ID, STR_ID_CCA_SKIP_PROFILE, srv_wap_prov_skip_profile);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_dtcnt_cui_proc
 * DESCRIPTION
 *  Proc function for Data account CUI.
 * PARAMETERS
 *  mmi_event_struct*                    [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_prov_app_cca_proc(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    switch(evt->evt_id)
    {

		 case EVT_ID_GROUP_DEINIT:
              mmi_frm_group_close(g_srv_wap_prov_cntx.cui_id);
			  g_srv_wap_prov_cntx.cui_id = GRP_ID_INVALID;
              break;
    }
						
    return MMI_RET_OK;
}

#endif /* WAP_SUPPORT */
#endif /* PROV_SUPPORT*/
